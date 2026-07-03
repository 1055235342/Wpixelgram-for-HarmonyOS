import { common } from '@kit.AbilityKit';
import router from '@ohos.router';
import preferences from '@ohos.data.preferences';
import { DownloadNotificationService } from '../../../common/service/DownloadNotificationService';
import { TdFile, TdMessage, TdUpdate, TdlibService } from '../../../common/service/TdlibService';
import { getMessagePreview } from '../utils/ChatListMappers';

export type CacheResourceType = 'video' | 'file' | 'audio' | 'animation';
export type CacheResourceStatus = 'downloading' | 'paused' | 'completed';

export interface CacheResourceItem {
  fileId: number;
  messageId: number;
  chatId: number;
  type: CacheResourceType;
  title: string;
  fileName: string;
  path: string;
  downloadedSize: number;
  expectedSize: number;
  status: CacheResourceStatus;
  notificationId: number;
  duration: number;
  videoWidth: number;
  videoHeight: number;
}

export interface CacheResourceRequest {
  fileId: number;
  messageId?: number;
  chatId?: number;
  type: CacheResourceType;
  title?: string;
  fileName?: string;
  path?: string;
  downloadedSize?: number;
  expectedSize?: number;
  duration?: number;
  videoWidth?: number;
  videoHeight?: number;
}

type CacheListener = (items: CacheResourceItem[]) => void;

export class ChatDownloadCacheController {
  private static instance: ChatDownloadCacheController = new ChatDownloadCacheController();
  private static readonly preferencesName: string = 'chat_download_cache';
  private static readonly cacheItemsKey: string = 'cache_items';
  private td: TdlibService = TdlibService.getInstance();
  private notifier: DownloadNotificationService = DownloadNotificationService.getInstance();
  private items: CacheResourceItem[] = [];
  private listeners: CacheListener[] = [];
  private registered: boolean = false;
  private context: common.UIAbilityContext | null = null;
  private mutedChatIds: Set<number> = new Set();
  private chatTitles: Map<number, string> = new Map();
  private storageLoaded: boolean = false;
  private storageLoading: boolean = false;
  private persistToken: number = 0;

  public static getInstance(): ChatDownloadCacheController {
    return ChatDownloadCacheController.instance;
  }

  public setContext(context: common.UIAbilityContext): void {
    this.context = context;
    this.restorePersistedItems();
  }

  public setChatMuted(chatId: number, muted: boolean): void {
    if (chatId === 0) {
      return;
    }
    if (muted) {
      this.mutedChatIds.add(chatId);
    } else {
      this.mutedChatIds.delete(chatId);
    }
  }

  public setChatTitle(chatId: number, title: string): void {
    if (chatId === 0 || title.length === 0) {
      return;
    }
    this.chatTitles.set(chatId, title);
  }

  public registerTdlibListeners(): void {
    if (this.registered) {
      return;
    }
    this.registered = true;
    this.td.onUpdate('file', (update: TdUpdate) => {
      if (update.file) {
        this.applyFileUpdate(update.file);
      }
    });
    this.td.onUpdate('updateFile', (update: TdUpdate) => {
      if (update.file) {
        this.applyFileUpdate(update.file);
      }
    });
    this.td.onUpdate('updateNewMessage', (update: TdUpdate) => {
      if (update.message) {
        this.applyNewMessage(update.message);
      }
    });
    this.td.onUpdate('message', (update: TdUpdate) => {
      if (update.message) {
        this.repairCacheItemFromMessage(update.message);
      }
    });
  }

  public subscribe(listener: CacheListener): void {
    this.listeners.push(listener);
    listener(this.getItems());
  }

  public unsubscribe(listener: CacheListener): void {
    const index = this.listeners.indexOf(listener);
    if (index >= 0) {
      this.listeners.splice(index, 1);
    }
  }

  public getItems(): CacheResourceItem[] {
    return this.items.map((item: CacheResourceItem): CacheResourceItem => {
      return {
        fileId: item.fileId,
        messageId: item.messageId,
        chatId: item.chatId,
        type: item.type,
        title: item.title,
        fileName: item.fileName,
        path: item.path,
        downloadedSize: item.downloadedSize,
        expectedSize: item.expectedSize,
        status: item.status,
        notificationId: item.notificationId,
        duration: item.duration,
        videoWidth: item.videoWidth,
        videoHeight: item.videoHeight
      };
    });
  }

  public isCaching(fileId: number): boolean {
    return this.items.some((item: CacheResourceItem): boolean => {
      return item.fileId === fileId && item.status !== 'paused';
    });
  }

  public hasActiveDownloads(): boolean {
    return this.items.some((item: CacheResourceItem): boolean => item.status === 'downloading');
  }

  public keepActiveDownloadsRunning(): void {
    this.registerTdlibListeners();
    this.items.forEach((item: CacheResourceItem) => {
      if (item.status === 'downloading') {
        this.td.downloadFile(item.fileId, this.getPriority(item.type));
        this.publishNotification(item);
      }
    });
  }

  public start(request: CacheResourceRequest, context?: common.UIAbilityContext): void {
    if (request.fileId <= 0) {
      return;
    }
    if (context) {
      this.setContext(context);
    }
    this.registerTdlibListeners();
    const index = this.items.findIndex((item: CacheResourceItem): boolean => item.fileId === request.fileId);
    const nextItem = this.mergeRequest(index >= 0 ? this.items[index] : undefined, request);
    nextItem.status = nextItem.status === 'completed' ? 'completed' : 'downloading';
    if (index >= 0) {
      this.items[index] = nextItem;
    } else {
      this.items = [nextItem].concat(this.items);
    }
    console.info(`[ChatDownloadCacheController] start fileId=${request.fileId}, type=${request.type}, title=${nextItem.title}`);
    if (nextItem.status !== 'completed') {
      this.td.downloadFile(request.fileId, this.getPriority(request.type));
    }
    this.publishNotification(nextItem);
    this.emit();
  }

  public pause(fileId: number): void {
    const item = this.findMutable(fileId);
    if (!item || item.status === 'completed') {
      return;
    }
    item.status = 'paused';
    this.td.cancelDownloadFile(fileId);
    this.notifier.cancel(item.notificationId);
    console.info(`[ChatDownloadCacheController] pause fileId=${fileId}`);
    this.emit();
  }

  public resume(fileId: number): void {
    const item = this.findMutable(fileId);
    if (!item || item.status === 'completed') {
      return;
    }
    item.status = 'downloading';
    this.td.downloadFile(fileId, this.getPriority(item.type));
    this.publishNotification(item);
    console.info(`[ChatDownloadCacheController] resume fileId=${fileId}`);
    this.emit();
  }

  public remove(fileId: number): void {
    const item = this.items.find((value: CacheResourceItem): boolean => value.fileId === fileId);
    this.items = this.items.filter((value: CacheResourceItem): boolean => value.fileId !== fileId);
    this.td.cancelDownloadFile(fileId);
    if (item) {
      this.notifier.cancel(item.notificationId);
    }
    console.info(`[ChatDownloadCacheController] remove fileId=${fileId}`);
    this.emit();
  }

  public open(item: CacheResourceItem): void {
    if (item.status !== 'completed' || item.path.length === 0) {
      return;
    }
    if (this.isInvalidMediaPath(item.type, item.path)) {
      const mutable = this.findMutable(item.fileId);
      if (mutable) {
        mutable.path = '';
        mutable.status = 'downloading';
        this.requestMessageRepair(mutable);
        this.td.getFile(mutable.fileId);
        this.emit();
      }
      return;
    }
    if (item.type === 'video' || item.type === 'animation') {
      router.pushUrl({
        url: 'features/chat/view/VideoPlayerView',
        params: {
          chatId: item.chatId,
          messageId: item.messageId,
          fileId: item.fileId,
          videoPath: item.path,
          previewUri: '',
          title: item.title,
          subtitle: '',
          description: item.fileName,
          fileSize: item.expectedSize,
          downloadedSize: item.expectedSize > 0 ? item.expectedSize : item.downloadedSize,
          cacheCompleted: true,
          duration: item.duration,
          videoWidth: item.videoWidth,
          videoHeight: item.videoHeight
        }
      });
    }
  }

  private applyFileUpdate(file: TdFile): void {
    const item = this.findMutable(file.id);
    if (!item) {
      return;
    }
    const previousStatus = item.status;
    if (file.local && file.local.path.length > 0) {
      const path = this.toFileSource(file.local.path);
      if (!this.isInvalidMediaPath(item.type, path)) {
        item.path = path;
      } else {
        console.warn(`[ChatDownloadCacheController] ignore invalid media path fileId=${item.fileId}, type=${item.type}, path=${path}`);
        this.requestMessageRepair(item);
      }
    }
    item.downloadedSize = Math.max(item.downloadedSize, this.getDownloadedSize(file));
    item.expectedSize = Math.max(item.expectedSize, this.getExpectedSize(file));
    const completed = item.path.length > 0 && !this.isInvalidMediaPath(item.type, item.path) &&
      ((file.local && file.local.is_downloading_completed === true) ||
        (item.expectedSize > 0 && item.downloadedSize >= item.expectedSize));
    if (completed) {
      item.status = 'completed';
      item.downloadedSize = item.expectedSize > 0 ? item.expectedSize : item.downloadedSize;
    } else if (item.status !== 'paused') {
      item.status = 'downloading';
    }
    console.info(`[ChatDownloadCacheController] file update fileId=${item.fileId}, status=${item.status}, downloaded=${item.downloadedSize}, expected=${item.expectedSize}, path=${item.path}`);
    this.publishNotification(item, previousStatus !== 'completed' && item.status === 'completed');
    this.emit();
  }

  private mergeRequest(current: CacheResourceItem | undefined, request: CacheResourceRequest): CacheResourceItem {
    const title = request.title && request.title.length > 0 ? request.title : this.getDefaultTitle(request.type);
    const fileName = request.fileName && request.fileName.length > 0 ? request.fileName : title;
    return {
      fileId: request.fileId,
      messageId: request.messageId !== undefined ? request.messageId : (current ? current.messageId : 0),
      chatId: request.chatId !== undefined ? request.chatId : (current ? current.chatId : 0),
      type: request.type,
      title: title,
      fileName: fileName,
      path: this.getValidRequestPath(request.type, request.path !== undefined ? request.path : (current ? current.path : '')),
      downloadedSize: Math.max(current ? current.downloadedSize : 0, request.downloadedSize !== undefined ? request.downloadedSize : 0),
      expectedSize: Math.max(current ? current.expectedSize : 0, request.expectedSize !== undefined ? request.expectedSize : 0),
      status: current ? current.status : 'downloading',
      notificationId: 200000 + request.fileId,
      duration: request.duration !== undefined ? request.duration : (current ? current.duration : 0),
      videoWidth: request.videoWidth !== undefined ? request.videoWidth : (current ? current.videoWidth : 0),
      videoHeight: request.videoHeight !== undefined ? request.videoHeight : (current ? current.videoHeight : 0)
    };
  }

  private publishNotification(item: CacheResourceItem, forceCompleted: boolean = false): void {
    if (this.context === null || item.status === 'paused' || this.mutedChatIds.has(item.chatId)) {
      return;
    }
    if (item.status === 'completed' && !forceCompleted) {
      return;
    }
    this.notifier.publishProgress(this.context, item.notificationId, item.status === 'completed' ? '缓存完成' : '正在缓存',
      item.fileName, item.downloadedSize, item.expectedSize, item.status === 'completed');
  }

  private applyNewMessage(message: TdMessage): void {
    if (this.context === null || !message || message.chat_id === undefined || message.is_outgoing ||
      this.mutedChatIds.has(message.chat_id)) {
      return;
    }
    const text = getMessagePreview(message);
    if (text.length === 0) {
      return;
    }
    const title = this.chatTitles.get(message.chat_id);
    this.notifier.publishText(this.context, this.getMessageNotificationId(message.id),
      title !== undefined ? title : `Chat ${message.chat_id}`, text);
  }

  private getMessageNotificationId(messageId: number): number {
    return 300000 + Math.abs(Math.floor(messageId % 100000));
  }

  private emit(): void {
    this.schedulePersist();
    const snapshot = this.getItems();
    this.listeners.forEach((listener: CacheListener) => {
      listener(snapshot);
    });
  }

  private restorePersistedItems(): void {
    if (this.context === null || this.storageLoaded || this.storageLoading) {
      return;
    }
    this.storageLoading = true;
    const context = this.context;
    preferences.getPreferences(context, { name: ChatDownloadCacheController.preferencesName })
      .then((store: preferences.Preferences) => {
        return store.get(ChatDownloadCacheController.cacheItemsKey, '');
      })
      .then((value: preferences.ValueType) => {
        this.storageLoaded = true;
        this.storageLoading = false;
        if (typeof value !== 'string' || value.length === 0) {
          return;
        }
        const restoredItems = this.parsePersistedItems(value);
        if (restoredItems.length === 0) {
          return;
        }
        this.mergePersistedItems(restoredItems);
        this.resumeUnfinishedItems();
        this.emit();
        console.info(`[ChatDownloadCacheController] restore persisted cache count=${restoredItems.length}`);
      })
      .catch((err: Error) => {
        this.storageLoaded = true;
        this.storageLoading = false;
        console.warn(`[ChatDownloadCacheController] restore persisted cache failed=${err.message}`);
      });
  }

  private parsePersistedItems(value: string): CacheResourceItem[] {
    try {
      const parsedItems = JSON.parse(value) as CacheResourceItem[];
      if (!Array.isArray(parsedItems)) {
        return [];
      }
      return parsedItems
        .map((item: CacheResourceItem): CacheResourceItem => this.normalizePersistedItem(item))
        .filter((item: CacheResourceItem): boolean => item.fileId > 0);
    } catch (err) {
      console.warn(`[ChatDownloadCacheController] parse persisted cache failed=${JSON.stringify(err)}`);
      return [];
    }
  }

  private normalizePersistedItem(item: CacheResourceItem): CacheResourceItem {
    const type = item.type === 'file' || item.type === 'audio' || item.type === 'animation' ? item.type : 'video';
    const status: CacheResourceStatus = item.status === 'completed' ? 'completed' : 'downloading';
    return {
      fileId: Number(item.fileId) || 0,
      messageId: Number(item.messageId) || 0,
      chatId: Number(item.chatId) || 0,
      type: type,
      title: item.title !== undefined ? `${item.title}` : this.getDefaultTitle(type),
      fileName: item.fileName !== undefined ? `${item.fileName}` : this.getDefaultTitle(type),
      path: this.getValidRequestPath(type, item.path !== undefined ? `${item.path}` : ''),
      downloadedSize: Number(item.downloadedSize) || 0,
      expectedSize: Number(item.expectedSize) || 0,
      status: status === 'completed' && this.isInvalidMediaPath(type, item.path !== undefined ? `${item.path}` : '') ?
        'downloading' : status,
      notificationId: Number(item.notificationId) || 200000 + (Number(item.fileId) || 0),
      duration: Number(item.duration) || 0,
      videoWidth: Number(item.videoWidth) || 0,
      videoHeight: Number(item.videoHeight) || 0
    };
  }

  private mergePersistedItems(restoredItems: CacheResourceItem[]): void {
    const nextItems = this.items.slice();
    restoredItems.forEach((restored: CacheResourceItem) => {
      const index = nextItems.findIndex((item: CacheResourceItem): boolean => item.fileId === restored.fileId);
      if (index >= 0) {
        nextItems[index] = this.mergeRestoredItem(nextItems[index], restored);
      } else {
        nextItems.push(restored);
      }
    });
    this.items = nextItems;
  }

  private mergeRestoredItem(current: CacheResourceItem, restored: CacheResourceItem): CacheResourceItem {
    return {
      fileId: current.fileId,
      messageId: current.messageId !== 0 ? current.messageId : restored.messageId,
      chatId: current.chatId !== 0 ? current.chatId : restored.chatId,
      type: current.type,
      title: current.title.length > 0 ? current.title : restored.title,
      fileName: current.fileName.length > 0 ? current.fileName : restored.fileName,
      path: current.path.length > 0 ? current.path : restored.path,
      downloadedSize: Math.max(current.downloadedSize, restored.downloadedSize),
      expectedSize: Math.max(current.expectedSize, restored.expectedSize),
      status: current.status === 'completed' || restored.status === 'completed' ? 'completed' : 'downloading',
      notificationId: current.notificationId,
      duration: current.duration > 0 ? current.duration : restored.duration,
      videoWidth: current.videoWidth > 0 ? current.videoWidth : restored.videoWidth,
      videoHeight: current.videoHeight > 0 ? current.videoHeight : restored.videoHeight
    };
  }

  private resumeUnfinishedItems(): void {
    this.registerTdlibListeners();
    this.items.forEach((item: CacheResourceItem) => {
      if (item.status !== 'completed') {
        item.status = 'downloading';
        this.requestMessageRepair(item);
        this.td.getFile(item.fileId);
        this.td.downloadFile(item.fileId, this.getPriority(item.type));
        this.publishNotification(item);
      }
    });
  }

  private schedulePersist(): void {
    if (this.context === null || !this.storageLoaded) {
      return;
    }
    const token = ++this.persistToken;
    setTimeout(() => {
      if (token === this.persistToken) {
        this.persistItems();
      }
    }, 350);
  }

  private persistItems(): void {
    if (this.context === null) {
      return;
    }
    const context = this.context;
    const text = JSON.stringify(this.getItems());
    preferences.getPreferences(context, { name: ChatDownloadCacheController.preferencesName })
      .then((store: preferences.Preferences) => {
        return store.put(ChatDownloadCacheController.cacheItemsKey, text)
          .then(() => store.flush());
      })
      .catch((err: Error) => {
        console.warn(`[ChatDownloadCacheController] persist cache failed=${err.message}`);
      });
  }

  private findMutable(fileId: number): CacheResourceItem | undefined {
    return this.items.find((item: CacheResourceItem): boolean => item.fileId === fileId);
  }

  private getDownloadedSize(file: TdFile): number {
    if (!file.local) {
      return 0;
    }
    const prefixSize = file.local.downloaded_prefix_size !== undefined ? file.local.downloaded_prefix_size : 0;
    const downloadedSize = file.local.downloaded_size !== undefined ? file.local.downloaded_size : 0;
    return Math.max(prefixSize, downloadedSize);
  }

  private getExpectedSize(file: TdFile): number {
    if (file.size !== undefined && file.size > 0) {
      return file.size;
    }
    if (file.expected_size !== undefined && file.expected_size > 0) {
      return file.expected_size;
    }
    return 0;
  }

  private getPriority(type: CacheResourceType): number {
    if (type === 'file') {
      return 16;
    }
    return 32;
  }

  private getDefaultTitle(type: CacheResourceType): string {
    if (type === 'audio') {
      return '音频';
    }
    if (type === 'file') {
      return '文件';
    }
    return '视频';
  }

  private toFileSource(path: string): string {
    if (path.length === 0 || path.indexOf('file://') === 0) {
      return path;
    }
    return `file://${path}`;
  }

  private getValidRequestPath(type: CacheResourceType, path: string): string {
    if (path.length === 0 || this.isInvalidMediaPath(type, path)) {
      return '';
    }
    return path;
  }

  private isInvalidMediaPath(type: CacheResourceType, path: string): boolean {
    if ((type !== 'video' && type !== 'animation') || path.length === 0) {
      return false;
    }
    const lowerPath = path.toLowerCase();
    return lowerPath.endsWith('.jpg') || lowerPath.endsWith('.jpeg') || lowerPath.endsWith('.png') ||
      lowerPath.endsWith('.webp') || lowerPath.endsWith('.gif');
  }

  private requestMessageRepair(item: CacheResourceItem): void {
    if (item.chatId !== 0 && item.messageId !== 0) {
      this.td.getMessage(item.chatId, item.messageId);
    }
  }

  private repairCacheItemFromMessage(message: TdMessage): void {
    const item = this.items.find((value: CacheResourceItem): boolean => {
      return value.messageId === message.id && (value.chatId === 0 || value.chatId === message.chat_id);
    });
    if (!item || !message.content) {
      return;
    }
    const file = item.type === 'animation' && message.content.animation ? message.content.animation.animation :
      (item.type === 'video' && message.content.video ? message.content.video.video : undefined);
    if (!file || file.id <= 0) {
      return;
    }
    const oldFileId = item.fileId;
    item.fileId = file.id;
    item.notificationId = 200000 + file.id;
    item.expectedSize = Math.max(item.expectedSize, this.getExpectedSize(file));
    item.downloadedSize = Math.max(item.downloadedSize, this.getDownloadedSize(file));
    if (file.local && file.local.path.length > 0) {
      const path = this.toFileSource(file.local.path);
      if (!this.isInvalidMediaPath(item.type, path)) {
        item.path = path;
      }
    }
    if (item.path.length > 0 && !this.isInvalidMediaPath(item.type, item.path) &&
      ((file.local && file.local.is_downloading_completed === true) ||
        (item.expectedSize > 0 && item.downloadedSize >= item.expectedSize))) {
      item.status = 'completed';
    } else if (item.status !== 'paused') {
      item.status = 'downloading';
      this.td.downloadFile(item.fileId, this.getPriority(item.type));
    }
    console.info(`[ChatDownloadCacheController] repair media item messageId=${message.id}, oldFileId=${oldFileId}, fileId=${item.fileId}, path=${item.path}`);
    this.emit();
  }
}
