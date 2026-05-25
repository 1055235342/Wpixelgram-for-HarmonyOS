// entry/src/main/cpp/napi_init.cpp
#include "napi/native_api.h"
#include "td/telegram/td_json_client.h"
#include "hilog/log.h"
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <thread>
#include <mutex>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x3200
#define LOG_TAG "TDLibBridge"

static int g_client_id_counter = 0;
static std::unordered_map<int, void*> g_clients;
static std::mutex g_clients_mutex;

struct VideoCachedRange {
    int64_t start = 0;
    int64_t end = 0;
    int64_t base_downloaded_size = 0;
};

struct VideoProxySession {
    int client_id = -1;
    int file_id = 0;
    std::string local_path;
    int64_t total_size = 0;
    int64_t downloaded_prefix_size = 0;
    int64_t downloaded_size = 0;
    bool is_completed = false;
    std::vector<VideoCachedRange> cached_ranges;
};

static std::mutex g_proxy_mutex;
static std::unordered_map<int, VideoProxySession> g_video_sessions;
static std::atomic<bool> g_proxy_running(false);
static std::thread g_proxy_thread;
static int g_proxy_server_fd = -1;
static int g_proxy_port = 19090;
static const int64_t kProxyChunkSize = 2 * 1024 * 1024;
static const int64_t kProxyInitialReadSize = 2 * 1024 * 1024;
static const int64_t kProxySeekReadSize = 4 * 1024 * 1024;
static const int kProxyWaitTimeoutMs = 15000;
static const int kProxyWaitStepMs = 80;

static int64_t GetFileSize(const std::string &path) {
    struct stat st {};
    if (path.empty() || stat(path.c_str(), &st) != 0) {
        return 0;
    }
    return static_cast<int64_t>(st.st_size);
}

static int64_t GetReadablePrefixSize(const VideoProxySession &session) {
    if (session.is_completed) {
        if (session.total_size > 0) {
            return session.total_size;
        }
        return GetFileSize(session.local_path);
    }
    return std::max<int64_t>(0, session.downloaded_prefix_size);
}

static int64_t GetReadableEndForOffset(const VideoProxySession &session, int64_t offset) {
    if (session.is_completed) {
        if (session.total_size > 0) {
            return session.total_size;
        }
        return GetFileSize(session.local_path);
    }
    int64_t prefixEnd = std::max<int64_t>(0, session.downloaded_prefix_size);
    if (offset < prefixEnd) {
        return prefixEnd;
    }
    for (const auto &range : session.cached_ranges) {
        if (offset < range.start || offset >= range.end) {
            continue;
        }
        int64_t downloadedInRange = session.downloaded_size - range.base_downloaded_size;
        if (downloadedInRange <= 0) {
            continue;
        }
        return std::min<int64_t>(range.end, range.start + downloadedInRange);
    }
    if (session.total_size <= 0 || session.downloaded_size <= prefixEnd) {
        return prefixEnd;
    }
    int64_t sparseBytes = session.downloaded_size - prefixEnd;
    int64_t tailStart = std::max<int64_t>(prefixEnd, session.total_size - sparseBytes);
    if (offset >= tailStart) {
        return session.total_size;
    }
    return prefixEnd;
}

static bool GetVideoProxySession(int fileId, VideoProxySession &session) {
    std::lock_guard<std::mutex> lock(g_proxy_mutex);
    auto it = g_video_sessions.find(fileId);
    if (it == g_video_sessions.end()) {
        return false;
    }
    session = it->second;
    return true;
}

static bool SendAll(int fd, const char *data, size_t len) {
    size_t sent = 0;
    while (sent < len) {
        ssize_t n = send(fd, data + sent, len - sent, 0);
        if (n <= 0) {
            return false;
        }
        sent += static_cast<size_t>(n);
    }
    return true;
}

static bool SendString(int fd, const std::string &data) {
    return SendAll(fd, data.c_str(), data.size());
}

static void SendDownloadRequest(const VideoProxySession &session, int64_t offset, int64_t limit) {
    std::lock_guard<std::mutex> lock(g_clients_mutex);
    auto it = g_clients.find(session.client_id);
    if (it == g_clients.end()) {
        OH_LOG_ERROR(LOG_APP, "VideoProxy TDLib client not found clientId=%{public}d", session.client_id);
        return;
    }
    std::string request = "{\"@type\":\"downloadFile\",\"file_id\":" + std::to_string(session.file_id) +
        ",\"priority\":32,\"offset\":" + std::to_string(offset) +
        ",\"limit\":" + std::to_string(limit) + ",\"synchronous\":false}";
    OH_LOG_ERROR(LOG_APP, "VideoProxy download request=%{public}s", request.c_str());
    td_json_client_send(it->second, request.c_str());
}

static void SendCancelDownloadRequest(const VideoProxySession &session) {
    std::lock_guard<std::mutex> lock(g_clients_mutex);
    auto it = g_clients.find(session.client_id);
    if (it == g_clients.end()) {
        OH_LOG_ERROR(LOG_APP, "VideoProxy TDLib client not found for cancel clientId=%{public}d", session.client_id);
        return;
    }
    std::string request = "{\"@type\":\"cancelDownloadFile\",\"file_id\":" + std::to_string(session.file_id) +
        ",\"only_if_pending\":false}";
    OH_LOG_ERROR(LOG_APP, "VideoProxy cancel download request=%{public}s", request.c_str());
    td_json_client_send(it->second, request.c_str());
}

static bool IsTailRangeRequest(const VideoProxySession &session, int64_t offset) {
    if (session.total_size <= 0) {
        return false;
    }
    return offset >= std::max<int64_t>(0, session.total_size - kProxyChunkSize);
}

static bool IsSeekRangeRequest(const VideoProxySession &session, int64_t offset) {
    if (session.total_size <= 0 || IsTailRangeRequest(session, offset)) {
        return false;
    }
    int64_t prefixEnd = GetReadablePrefixSize(session);
    return offset > prefixEnd + kProxySeekReadSize;
}

static void RegisterCachedRange(const VideoProxySession &session, int64_t start, int64_t endExclusive) {
    if (endExclusive <= start) {
        return;
    }
    std::lock_guard<std::mutex> lock(g_proxy_mutex);
    auto it = g_video_sessions.find(session.file_id);
    if (it == g_video_sessions.end()) {
        return;
    }
    int64_t rangeEnd = endExclusive;
    if (it->second.total_size > 0) {
        rangeEnd = std::min<int64_t>(rangeEnd, it->second.total_size);
    }
    for (auto &range : it->second.cached_ranges) {
        if (start >= range.start && start < range.end) {
            range.end = std::max<int64_t>(range.end, rangeEnd);
            return;
        }
    }
    VideoCachedRange range;
    range.start = start;
    range.end = rangeEnd;
    range.base_downloaded_size = it->second.downloaded_size;
    it->second.cached_ranges.push_back(range);
    OH_LOG_ERROR(LOG_APP,
                 "VideoProxy register cached range fileId=%{public}d start=%{public}lld end=%{public}lld base=%{public}lld",
                 session.file_id, static_cast<long long>(range.start), static_cast<long long>(range.end),
                 static_cast<long long>(range.base_downloaded_size));
}

static void SendPlaybackDownloadRequest(const VideoProxySession &session, int64_t offset, int64_t limit) {
    if (IsTailRangeRequest(session, offset)) {
        SendDownloadRequest(session, offset, limit);
        return;
    }
    if (IsSeekRangeRequest(session, offset)) {
        int64_t requestLimit = std::max<int64_t>(limit, kProxySeekReadSize);
        RegisterCachedRange(session, offset, offset + requestLimit);
        SendCancelDownloadRequest(session);
        SendDownloadRequest(session, offset, requestLimit);
        return;
    }
    SendDownloadRequest(session, 0, 0);
}

static bool WaitUntilAvailable(int fileId, int64_t startOffset, int64_t endExclusive) {
    int waited = 0;
    while (g_proxy_running && waited < kProxyWaitTimeoutMs) {
        VideoProxySession latest;
        if (!GetVideoProxySession(fileId, latest)) {
            return false;
        }
        if (GetReadableEndForOffset(latest, startOffset) >= endExclusive) {
            return true;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(kProxyWaitStepMs));
        waited += kProxyWaitStepMs;
    }
    VideoProxySession latest;
    return GetVideoProxySession(fileId, latest) && GetReadableEndForOffset(latest, startOffset) >= endExclusive;
}

static bool ParseRequestPath(const std::string &request, int &file_id, bool &isHeadRequest) {
    const std::string getMarker = "GET /tdvideo/";
    const std::string headMarker = "HEAD /tdvideo/";
    size_t start = request.find(getMarker);
    size_t markerSize = getMarker.size();
    isHeadRequest = false;
    if (start == std::string::npos) {
        start = request.find(headMarker);
        if (start == std::string::npos) {
            return false;
        }
        markerSize = headMarker.size();
        isHeadRequest = true;
    }
    start += markerSize;
    size_t end = request.find(' ', start);
    if (end == std::string::npos || end <= start) {
        return false;
    }
    std::string id_text = request.substr(start, end - start);
    size_t query_index = id_text.find('?');
    if (query_index != std::string::npos) {
        id_text = id_text.substr(0, query_index);
    }
    file_id = std::atoi(id_text.c_str());
    return file_id > 0;
}

static bool HasRangeHeader(const std::string &request) {
    return request.find("Range:") != std::string::npos || request.find("range:") != std::string::npos;
}

static void ParseRange(const std::string &request, int64_t totalSize, int64_t &start, int64_t &endInclusive,
                       bool &openEnded) {
    start = 0;
    endInclusive = totalSize > 0 ? std::min<int64_t>(totalSize - 1, kProxyChunkSize - 1) : kProxyChunkSize - 1;
    openEnded = true;
    size_t range_pos = request.find("Range:");
    if (range_pos == std::string::npos) {
        range_pos = request.find("range:");
    }
    if (range_pos == std::string::npos) {
        return;
    }
    size_t bytes_pos = request.find("bytes=", range_pos);
    if (bytes_pos == std::string::npos) {
        return;
    }
    bytes_pos += 6;
    size_t dash_pos = request.find('-', bytes_pos);
    if (dash_pos == std::string::npos) {
        return;
    }
    start = std::atoll(request.substr(bytes_pos, dash_pos - bytes_pos).c_str());
    size_t line_end = request.find("\r\n", dash_pos);
    std::string end_text = request.substr(dash_pos + 1, line_end == std::string::npos ? std::string::npos : line_end - dash_pos - 1);
    if (!end_text.empty()) {
        endInclusive = std::atoll(end_text.c_str());
        openEnded = false;
    } else {
        endInclusive = totalSize > 0 ? totalSize - 1 : start + kProxyChunkSize * 16 - 1;
        openEnded = true;
    }
    if (totalSize > 0) {
        endInclusive = std::min<int64_t>(endInclusive, totalSize - 1);
    }
    if (endInclusive < start) {
        endInclusive = start;
    }
}

static void SendErrorResponse(int fd, int status, const std::string &message) {
    std::string body = message + "\n";
    std::string header = "HTTP/1.1 " + std::to_string(status) + " Error\r\n"
        "Content-Type: text/plain\r\n"
        "Connection: close\r\n"
        "Content-Length: " + std::to_string(body.size()) + "\r\n\r\n";
    SendString(fd, header);
    SendString(fd, body);
}

static void HandleVideoProxyClient(int client_fd) {
    char buffer[4096] = {0};
    ssize_t count = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
    if (count <= 0) {
        close(client_fd);
        return;
    }
    std::string request(buffer, static_cast<size_t>(count));
    int file_id = 0;
    bool isHeadRequest = false;
    if (!ParseRequestPath(request, file_id, isHeadRequest)) {
        SendErrorResponse(client_fd, 404, "not found");
        close(client_fd);
        return;
    }

    VideoProxySession session;
    if (!GetVideoProxySession(file_id, session)) {
        SendErrorResponse(client_fd, 404, "session not found");
        close(client_fd);
        return;
    }

    int64_t totalSize = session.total_size > 0 ? session.total_size : GetFileSize(session.local_path);
    if (totalSize <= 0) {
        SendPlaybackDownloadRequest(session, 0, 0);
        totalSize = session.total_size > 0 ? session.total_size : kProxyChunkSize * 16;
    }

    int64_t start = 0;
    int64_t endInclusive = 0;
    bool openEnded = true;
    bool hasRangeHeader = HasRangeHeader(request);
    ParseRange(request, totalSize, start, endInclusive, openEnded);
    if (!hasRangeHeader) {
        start = 0;
        endInclusive = totalSize > 0 ? totalSize - 1 : kProxyChunkSize * 16 - 1;
        openEnded = true;
    }
    int64_t endExclusive = endInclusive + 1;
    bool seekRangeRequest = IsSeekRangeRequest(session, start);
    OH_LOG_ERROR(LOG_APP,
                "VideoProxy request fileId=%{public}d method=%{public}s range=%{public}s start=%{public}lld end=%{public}lld total=%{public}lld openEnded=%{public}d",
                file_id, isHeadRequest ? "HEAD" : "GET", hasRangeHeader ? "yes" : "no",
                static_cast<long long>(start), static_cast<long long>(endInclusive),
                static_cast<long long>(totalSize), openEnded ? 1 : 0);
    if (isHeadRequest) {
        int64_t contentLength = hasRangeHeader ? (endExclusive - start) : totalSize;
        std::string header = hasRangeHeader
            ? "HTTP/1.1 206 Partial Content\r\n"
            : "HTTP/1.1 200 OK\r\n";
        header += "Content-Type: video/mp4\r\n"
            "Accept-Ranges: bytes\r\n"
            "Access-Control-Allow-Origin: *\r\n"
            "Connection: close\r\n";
        if (hasRangeHeader) {
            header += "Content-Range: bytes " + std::to_string(start) + "-" +
                std::to_string(endInclusive) + "/" + std::to_string(totalSize) + "\r\n";
        }
        header += "Content-Length: " + std::to_string(contentLength) + "\r\n\r\n";
        SendString(client_fd, header);
        close(client_fd);
        return;
    }
    int64_t limit = openEnded ? kProxyChunkSize * 2 : std::max<int64_t>(kProxyChunkSize, endExclusive - start);
    SendPlaybackDownloadRequest(session, start, openEnded ? 0 : limit);
    int64_t initialRequiredEnd = std::min<int64_t>(endExclusive, start + kProxyInitialReadSize);
    if (!WaitUntilAvailable(session.file_id, start, initialRequiredEnd)) {
        GetVideoProxySession(session.file_id, session);
        int64_t available = GetReadableEndForOffset(session, start);
        if (available <= start) {
            if (!IsTailRangeRequest(session, start) && !seekRangeRequest) {
                SendPlaybackDownloadRequest(session, 0, 0);
            }
            if (!WaitUntilAvailable(session.file_id, start, initialRequiredEnd)) {
                SendErrorResponse(client_fd, 503, "range not available");
                close(client_fd);
                return;
            }
            GetVideoProxySession(session.file_id, session);
            available = GetReadableEndForOffset(session, start);
        }
        if (!openEnded) {
            endInclusive = std::min<int64_t>(endInclusive, available - 1);
            endExclusive = endInclusive + 1;
        }
    }

    FILE *file = std::fopen(session.local_path.c_str(), "rb");
    if (file == nullptr) {
        SendErrorResponse(client_fd, 404, "file not readable");
        close(client_fd);
        return;
    }
    std::fseek(file, static_cast<long>(start), SEEK_SET);
    int64_t contentLength = endExclusive - start;
    std::string header = hasRangeHeader ? "HTTP/1.1 206 Partial Content\r\n" : "HTTP/1.1 200 OK\r\n";
    header += "Content-Type: video/mp4\r\n"
        "Accept-Ranges: bytes\r\n"
        "Access-Control-Allow-Origin: *\r\n"
        "Connection: close\r\n";
    if (hasRangeHeader) {
        header += "Content-Range: bytes " + std::to_string(start) + "-" +
            std::to_string(endInclusive) + "/" + std::to_string(totalSize) + "\r\n";
    }
    header += "Content-Length: " + std::to_string(contentLength) + "\r\n\r\n";
    if (!SendString(client_fd, header)) {
        std::fclose(file);
        close(client_fd);
        return;
    }
    std::vector<char> chunk(64 * 1024);
    int64_t remaining = contentLength;
    int64_t currentOffset = start;
    while (remaining > 0) {
        GetVideoProxySession(session.file_id, session);
        int64_t available = GetReadableEndForOffset(session, currentOffset);
        if (available <= currentOffset) {
            SendPlaybackDownloadRequest(session, currentOffset, kProxyChunkSize * 2);
            int64_t nextRequiredEnd = std::min<int64_t>(endExclusive, currentOffset + kProxyInitialReadSize);
            if (!WaitUntilAvailable(session.file_id, currentOffset, nextRequiredEnd)) {
                OH_LOG_ERROR(LOG_APP, "VideoProxy wait next range timeout fileId=%{public}d offset=%{public}lld",
                             session.file_id, static_cast<long long>(currentOffset));
                break;
            }
            GetVideoProxySession(session.file_id, session);
            available = GetReadableEndForOffset(session, currentOffset);
            clearerr(file);
        }
        if (!openEnded && available - currentOffset < kProxyInitialReadSize && currentOffset + kProxyChunkSize < endExclusive) {
            SendPlaybackDownloadRequest(session, currentOffset, kProxyChunkSize * 2);
        }
        std::fseek(file, static_cast<long>(currentOffset), SEEK_SET);
        int64_t readableNow = std::max<int64_t>(0, available - currentOffset);
        size_t readSize = static_cast<size_t>(std::min<int64_t>(std::min<int64_t>(remaining, chunk.size()), readableNow));
        if (readSize == 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(kProxyWaitStepMs));
            continue;
        }
        size_t actual = std::fread(chunk.data(), 1, readSize, file);
        if (actual == 0) {
            clearerr(file);
            std::this_thread::sleep_for(std::chrono::milliseconds(kProxyWaitStepMs));
            continue;
        }
        if (!SendAll(client_fd, chunk.data(), actual)) {
            break;
        }
        remaining -= static_cast<int64_t>(actual);
        currentOffset += static_cast<int64_t>(actual);
    }
    std::fclose(file);
    if (seekRangeRequest) {
        GetVideoProxySession(session.file_id, session);
        SendDownloadRequest(session, 0, 0);
    }
    close(client_fd);
}

static void VideoProxyLoop() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        OH_LOG_ERROR(LOG_APP, "VideoProxy socket failed");
        g_proxy_running = false;
        return;
    }
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    sockaddr_in addr {};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(static_cast<uint16_t>(g_proxy_port));
    if (bind(server_fd, reinterpret_cast<sockaddr *>(&addr), sizeof(addr)) < 0) {
        OH_LOG_ERROR(LOG_APP, "VideoProxy bind failed port=%{public}d", g_proxy_port);
        close(server_fd);
        g_proxy_running = false;
        return;
    }
    if (listen(server_fd, 8) < 0) {
        OH_LOG_ERROR(LOG_APP, "VideoProxy listen failed");
        close(server_fd);
        g_proxy_running = false;
        return;
    }
    g_proxy_server_fd = server_fd;
    OH_LOG_ERROR(LOG_APP, "VideoProxy started port=%{public}d", g_proxy_port);
    while (g_proxy_running) {
        sockaddr_in client_addr {};
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(server_fd, reinterpret_cast<sockaddr *>(&client_addr), &client_len);
        if (client_fd < 0) {
            continue;
        }
        std::thread(HandleVideoProxyClient, client_fd).detach();
    }
    close(server_fd);
    g_proxy_server_fd = -1;
}

static void EnsureVideoProxyServer() {
    if (g_proxy_running) {
        return;
    }
    g_proxy_running = true;
    g_proxy_thread = std::thread(VideoProxyLoop);
    g_proxy_thread.detach();
}

static napi_value CreateNativeClient(napi_env env, napi_callback_info info) {
    OH_LOG_INFO(LOG_APP, "CreateNativeClient called");
    void* client = td_json_client_create();
    if (client) {
        std::lock_guard<std::mutex> lock(g_clients_mutex);
        int id = g_client_id_counter++;
        g_clients[id] = client;
        OH_LOG_INFO(LOG_APP, "CreateNativeClient success, clientId=%{public}d", id);
        napi_value result;
        napi_create_int32(env, id, &result);
        return result;
    }
    OH_LOG_ERROR(LOG_APP, "CreateNativeClient failed");
    napi_value err;
    napi_create_int32(env, -1, &err);
    return err;
}

static napi_value SendNativeRequest(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    int32_t client_id;
    napi_get_value_int32(env, args[0], &client_id);
    size_t str_len;
    napi_get_value_string_utf8(env, args[1], nullptr, 0, &str_len);
    char* json_str = new char[str_len + 1];
    napi_get_value_string_utf8(env, args[1], json_str, str_len + 1, &str_len);
    OH_LOG_INFO(LOG_APP, "SendNativeRequest clientId=%{public}d request=%{public}s", client_id, json_str);
    
    {
        std::lock_guard<std::mutex> lock(g_clients_mutex);
        auto it = g_clients.find(client_id);
        if (it != g_clients.end()) {
            td_json_client_send(it->second, json_str);
            OH_LOG_INFO(LOG_APP, "SendNativeRequest sent clientId=%{public}d", client_id);
        } else {
            OH_LOG_ERROR(LOG_APP, "SendNativeRequest client not found clientId=%{public}d", client_id);
        }
    }
    delete[] json_str;
    napi_value js_null;
    napi_get_null(env, &js_null);
    return js_null;
}

static napi_value ReceiveNativeUpdate(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    int32_t client_id;
    napi_get_value_int32(env, args[0], &client_id);
    double timeout;
    napi_get_value_double(env, args[1], &timeout);
    
    {
        std::lock_guard<std::mutex> lock(g_clients_mutex);
        auto it = g_clients.find(client_id);
        if (it != g_clients.end()) {
            const char* result = td_json_client_receive(it->second, timeout);
            if (result) {
                OH_LOG_INFO(LOG_APP, "ReceiveNativeUpdate clientId=%{public}d response=%{public}s", client_id, result);
                napi_value js_result;
                napi_create_string_utf8(env, result, NAPI_AUTO_LENGTH, &js_result);
                return js_result;
            }
        } else {
            OH_LOG_ERROR(LOG_APP, "ReceiveNativeUpdate client not found clientId=%{public}d", client_id);
        }
    }
    napi_value js_null;
    napi_get_null(env, &js_null);
    return js_null;
}

static napi_value StartVideoProxy(napi_env env, napi_callback_info info) {
    size_t argc = 7;
    napi_value args[7];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    int32_t client_id = -1;
    int32_t file_id = 0;
    double total_size_value = 0;
    double prefix_size_value = 0;
    double downloaded_size_value = 0;
    bool is_completed = false;
    napi_get_value_int32(env, args[0], &client_id);
    napi_get_value_int32(env, args[1], &file_id);
    size_t path_len = 0;
    napi_get_value_string_utf8(env, args[2], nullptr, 0, &path_len);
    std::vector<char> path_buffer(path_len + 1);
    napi_get_value_string_utf8(env, args[2], path_buffer.data(), path_buffer.size(), &path_len);
    std::string local_path(path_buffer.data(), path_len);
    napi_get_value_double(env, args[3], &total_size_value);
    if (argc > 4) {
        napi_get_value_double(env, args[4], &prefix_size_value);
    }
    if (argc > 5) {
        napi_get_value_double(env, args[5], &downloaded_size_value);
    }
    if (argc > 6) {
        napi_get_value_bool(env, args[6], &is_completed);
    }

    VideoProxySession session;
    session.client_id = client_id;
    session.file_id = file_id;
    session.local_path = local_path;
    session.total_size = static_cast<int64_t>(total_size_value);
    session.downloaded_prefix_size = static_cast<int64_t>(prefix_size_value);
    session.downloaded_size = static_cast<int64_t>(downloaded_size_value);
    session.is_completed = is_completed;
    bool isNewSession = false;
    {
        std::lock_guard<std::mutex> lock(g_proxy_mutex);
        auto existing = g_video_sessions.find(file_id);
        isNewSession = existing == g_video_sessions.end();
        if (existing != g_video_sessions.end()) {
            session.cached_ranges = existing->second.cached_ranges;
        }
        g_video_sessions[file_id] = session;
    }
    EnsureVideoProxyServer();
    std::string url = "http://127.0.0.1:" + std::to_string(g_proxy_port) + "/tdvideo/" + std::to_string(file_id);
    if (isNewSession || session.is_completed || session.downloaded_prefix_size == session.downloaded_size) {
        OH_LOG_ERROR(LOG_APP,
                    "StartVideoProxy fileId=%{public}d prefix=%{public}lld downloaded=%{public}lld total=%{public}lld completed=%{public}d path=%{public}s url=%{public}s",
                    file_id, static_cast<long long>(session.downloaded_prefix_size),
                    static_cast<long long>(session.downloaded_size), static_cast<long long>(session.total_size),
                    session.is_completed ? 1 : 0,
                    local_path.c_str(), url.c_str());
    }
    napi_value result;
    napi_create_string_utf8(env, url.c_str(), NAPI_AUTO_LENGTH, &result);
    return result;
}

static napi_value StopVideoProxy(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);
    int32_t file_id = 0;
    napi_get_value_int32(env, args[0], &file_id);
    {
        std::lock_guard<std::mutex> lock(g_proxy_mutex);
        g_video_sessions.erase(file_id);
    }
    OH_LOG_ERROR(LOG_APP, "StopVideoProxy fileId=%{public}d", file_id);
    napi_value js_null;
    napi_get_null(env, &js_null);
    return js_null;
}

EXTERN_C_START
static napi_value BridgeInit(napi_env env, napi_value exports) {
    OH_LOG_INFO(LOG_APP, "BridgeInit called");
    napi_property_descriptor desc[] = {
        {"createNativeClient", nullptr, CreateNativeClient, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"sendNativeRequest", nullptr, SendNativeRequest, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"receiveNativeUpdate", nullptr, ReceiveNativeUpdate, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"startVideoProxy", nullptr, StartVideoProxy, nullptr, nullptr, nullptr, napi_default, nullptr},
        {"stopVideoProxy", nullptr, StopVideoProxy, nullptr, nullptr, nullptr, napi_default, nullptr}
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module bridge_module = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = BridgeInit,
    .nm_modname = "tdlib_bridge",
    .nm_priv = nullptr,
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterModule(void) {
    OH_LOG_INFO(LOG_APP, "RegisterModule called");
    napi_module_register(&bridge_module);
}
