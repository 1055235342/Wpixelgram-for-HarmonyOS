import { TdFile } from '../../../common/service/TdlibService';
import { MessageItem, PhotoMediaState } from '../model/ChatDetailModels';

export class ChatMediaController {
  private fileCache: Map<number, TdFile> = new Map();

  public clear(): void {
    this.fileCache.clear();
  }

  public hasFile(fileId: number): boolean {
    return this.fileCache.has(fileId);
  }

  public getFile(fileId: number): TdFile | undefined {
    return this.fileCache.get(fileId);
  }

  public cacheFile(file: TdFile): TdFile {
    const merged = this.mergeFileUpdate(file);
    this.fileCache.set(merged.id, merged);
    return merged;
  }

  public getLocalPath(file: TdFile): string {
    if (file.local && file.local.path.length > 0) {
      return this.toFileSource(file.local.path);
    }
    return '';
  }

  public getCompletedLocalPath(file: TdFile): string {
    if (file.local && file.local.is_downloading_completed === true && file.local.path.length > 0) {
      return this.toFileSource(file.local.path);
    }
    return '';
  }

  public getLatestFile(file: TdFile): TdFile {
    const cached = this.fileCache.get(file.id);
    return cached ? cached : file;
  }

  public getPhotoMediaState(file: TdFile): PhotoMediaState {
    const latestFile = this.getLatestFile(file);
    const path = this.getCompletedLocalPath(latestFile);
    return {
      fileId: latestFile.id,
      path: path,
      downloadedSize: this.getDownloadedSize(latestFile),
      expectedSize: this.getExpectedSize(latestFile),
      isReady: path.length > 0
    };
  }

  public getMessagePhotoState(msg: MessageItem): PhotoMediaState {
    const cached = msg.photoFileId !== 0 ? this.fileCache.get(msg.photoFileId) : undefined;
    if (cached) {
      return this.getPhotoMediaState(cached);
    }
    return {
      fileId: msg.photoFileId,
      path: msg.photoPath,
      downloadedSize: msg.photoDownloadedSize,
      expectedSize: msg.photoExpectedSize,
      isReady: msg.photoPath.length > 0
    };
  }

  public getMessageOriginalPhotoState(msg: MessageItem): PhotoMediaState {
    const cached = msg.originalPhotoFileId !== 0 ? this.fileCache.get(msg.originalPhotoFileId) : undefined;
    if (cached) {
      return this.getPhotoMediaState(cached);
    }
    return {
      fileId: msg.originalPhotoFileId,
      path: msg.originalPhotoPath,
      downloadedSize: msg.originalPhotoDownloadedSize,
      expectedSize: msg.originalPhotoExpectedSize,
      isReady: msg.originalPhotoPath.length > 0
    };
  }

  public getPhotoDisplayPath(msg: MessageItem): string {
    return this.getMessagePhotoState(msg).path;
  }

  public getThumbnailDisplayPath(msg: MessageItem): string {
    const cached = msg.thumbnailFileId !== 0 ? this.fileCache.get(msg.thumbnailFileId) : undefined;
    if (cached) {
      return this.getCompletedLocalPath(cached);
    }
    return msg.thumbnailPath;
  }

  public getDownloadedSize(file: TdFile): number {
    if (file.local && file.local.downloaded_size !== undefined) {
      return file.local.downloaded_size;
    }
    if (file.local && file.local.downloaded_prefix_size !== undefined) {
      return file.local.downloaded_prefix_size;
    }
    return 0;
  }

  public getExpectedSize(file: TdFile): number {
    if (file.expected_size !== undefined && file.expected_size > 0) {
      return file.expected_size;
    }
    if (file.size !== undefined && file.size > 0) {
      return file.size;
    }
    return 0;
  }

  public getStableExpectedSize(previousExpectedSize: number, file: TdFile): number {
    const expectedSize = this.getExpectedSize(file);
    return expectedSize > 0 ? expectedSize : previousExpectedSize;
  }

  public getDownloadPercent(downloadedSize: number, expectedSize: number): number {
    if (expectedSize <= 0) {
      return downloadedSize > 0 ? 12 : 0;
    }
    return Math.min(100, Math.max(0, Math.floor(downloadedSize * 100 / expectedSize)));
  }

  public canPlayVideo(file: TdFile): boolean {
    if (!file.local) {
      return false;
    }
    return file.local.is_downloading_completed === true || this.getDownloadedSize(file) > 0;
  }

  private mergeFileUpdate(file: TdFile): TdFile {
    const cached = this.fileCache.get(file.id);
    if (!cached || !cached.local || cached.local.is_downloading_completed !== true) {
      return file;
    }
    if (!file.local || file.local.is_downloading_completed !== true) {
      return cached;
    }
    return file;
  }

  private toFileSource(path: string): string {
    if (path.length === 0) {
      return '';
    }
    if (path.startsWith('file://')) {
      return path;
    }
    return `file://${path}`;
  }
}
