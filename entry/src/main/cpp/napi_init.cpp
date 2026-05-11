// entry/src/main/cpp/napi_init.cpp
#include "napi/native_api.h"
#include "td/telegram/td_json_client.h"
#include "hilog/log.h"
#include <string>
#include <unordered_map>

#undef LOG_DOMAIN
#undef LOG_TAG
#define LOG_DOMAIN 0x3200
#define LOG_TAG "TDLibBridge"

static int g_client_id_counter = 0;
static std::unordered_map<int, void*> g_clients;

static napi_value CreateNativeClient(napi_env env, napi_callback_info info) {
    OH_LOG_INFO(LOG_APP, "CreateNativeClient called");
    void* client = td_json_client_create();
    if (client) {
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
    
    auto it = g_clients.find(client_id);
    if (it != g_clients.end()) {
        td_json_client_send(it->second, json_str);
        OH_LOG_INFO(LOG_APP, "SendNativeRequest sent clientId=%{public}d", client_id);
    } else {
        OH_LOG_ERROR(LOG_APP, "SendNativeRequest client not found clientId=%{public}d", client_id);
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
        {"receiveNativeUpdate", nullptr, ReceiveNativeUpdate, nullptr, nullptr, nullptr, napi_default, nullptr}
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
