import { MessageItem } from '../model/ChatDetailModels';

export class ChatMediaFormatters {
  public static getMediaFormat(fileName: string | undefined, mimeType: string | undefined, path: string,
    fallback: string): string {
    const fromMime = ChatMediaFormatters.getFormatFromMime(mimeType);
    if (fromMime.length > 0) {
      return fromMime;
    }
    const fromName = ChatMediaFormatters.getFormatFromPath(fileName ? fileName : '');
    if (fromName.length > 0) {
      return fromName;
    }
    const fromPath = ChatMediaFormatters.getFormatFromPath(path);
    if (fromPath.length > 0) {
      return fromPath;
    }
    return fallback;
  }

  public static getVideoProgressText(msg: MessageItem): string {
    if (msg.videoExpectedSize > 0) {
      const percent = Math.floor(msg.videoDownloadedSize * 100 / msg.videoExpectedSize);
      return `缓存 ${percent}%`;
    }
    if (msg.videoDownloadedSize > 0) {
      return `已缓存 ${Math.floor(msg.videoDownloadedSize / 1024)} KB`;
    }
    return '视频缓存中...';
  }

  public static getPhotoDownloadText(percent: number): string {
    if (percent <= 0) {
      return '下载中';
    }
    return `${percent}%`;
  }

  public static getVideoDownloadPercent(msg: MessageItem): number {
    if (msg.videoExpectedSize <= 0) {
      return msg.videoDownloadedSize > 0 ? 12 : 0;
    }
    return Math.min(100, Math.max(0, Math.floor(msg.videoDownloadedSize * 100 / msg.videoExpectedSize)));
  }

  public static getFileSizeText(size: number): string {
    if (size <= 0) {
      return '未知大小';
    }
    if (size < 1024) {
      return `${size} B`;
    }
    if (size < 1024 * 1024) {
      return `${Math.round(size / 1024)} KB`;
    }
    const mb = size / 1024 / 1024;
    return `${mb.toFixed(mb >= 10 ? 0 : 1)} MB`;
  }

  public static getAudioProgressText(msg: MessageItem): string {
    return `00:00 / ${ChatMediaFormatters.formatDuration(msg.audioDuration)}`;
  }

  public static getAudioDownloadPercent(msg: MessageItem): number {
    if (msg.audioExpectedSize <= 0) {
      return 0;
    }
    const percent = (msg.audioDownloadedSize / msg.audioExpectedSize) * 100;
    return Math.min(100, Math.max(0, percent));
  }

  public static isAudioReady(msg: MessageItem): boolean {
    if (msg.audioPath.length === 0) {
      return false;
    }
    if (msg.audioExpectedSize <= 0) {
      return true;
    }
    return msg.audioDownloadedSize >= msg.audioExpectedSize;
  }

  public static formatDuration(seconds: number): string {
    const safeSeconds = Math.max(0, seconds);
    const minutes = Math.floor(safeSeconds / 60);
    const restSeconds = safeSeconds % 60;
    return `${ChatMediaFormatters.pad2(minutes)}:${ChatMediaFormatters.pad2(restSeconds)}`;
  }

  private static getFormatFromMime(mimeType: string | undefined): string {
    if (!mimeType || mimeType.length === 0) {
      return '';
    }
    const value = mimeType.toLowerCase();
    if (value === 'image/jpeg') {
      return 'jpg';
    }
    if (value === 'image/gif') {
      return 'gif';
    }
    const slashIndex = value.indexOf('/');
    if (slashIndex >= 0 && slashIndex < value.length - 1) {
      const tail = value.substring(slashIndex + 1);
      const semiIndex = tail.indexOf(';');
      return ChatMediaFormatters.normalizeFormat(semiIndex >= 0 ? tail.substring(0, semiIndex) : tail);
    }
    return '';
  }

  private static getFormatFromPath(path: string): string {
    if (path.length === 0) {
      return '';
    }
    const cleanPath = path.split('?')[0].split('#')[0];
    const dotIndex = cleanPath.lastIndexOf('.');
    if (dotIndex < 0 || dotIndex === cleanPath.length - 1) {
      return '';
    }
    return ChatMediaFormatters.normalizeFormat(cleanPath.substring(dotIndex + 1));
  }

  private static normalizeFormat(format: string): string {
    const value = format.toLowerCase();
    if (value === 'jpeg') {
      return 'jpg';
    }
    if (value === 'quicktime') {
      return 'mov';
    }
    if (value === 'x-matroska') {
      return 'mkv';
    }
    return value;
  }

  private static pad2(value: number): string {
    return value < 10 ? `0${value}` : `${value}`;
  }
}
