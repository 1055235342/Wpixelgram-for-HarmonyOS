// entry/src/main/ets/features/chat/view/VideoPlayerView.ets
import { GalleryService } from '../../../common/service/GalleryService';
import { TdFile, TdUpdate, TdlibService } from '../../../common/service/TdlibService';
import { common, Want, wantConstant } from '@kit.AbilityKit';
import { fileIo } from '@kit.CoreFileKit';
import { PiPWindow, promptAction, window } from '@kit.ArkUI';
import { media } from '@kit.MediaKit';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
import router from '@ohos.router';
import { AppLayout } from '../../../common/constants/AppLayout';
import { MediaPreviewItem } from '../model/ChatDetailModels';
import { ChatDownloadCacheController } from '../viewmodel/ChatDownloadCacheController';

interface VideoRouteParams {
  chatId?: number | string;
  messageId?: number | string;
  fileId?: number | string;
  mediaItemsJson?: string;
  mediaIndex?: number | string;
  videoPath?: string;
  previewUri?: string;
  title?: string;
  subtitle?: string;
  description?: string;
  fileSize?: number | string;
  downloadedSize?: number | string;
  cacheCompleted?: boolean | string;
  duration?: number | string;
  videoWidth?: number | string;
  videoHeight?: number | string;
}

interface OperationError {
  code?: number;
  message?: string;
}

@Entry
@Component
export struct VideoPlayerPage {
  @State chatId: number = 0;
  @State messageId: number = 0;
  @State fileId: number = 0;
  @State videoPath: string = '';
  @State previewUri: string = '';
  @State videoLocalPath: string = '';
  @State statusText: string = '准备播放...';
  @State downloadedSize: number = 0;
  @State downloadedPrefixSize: number = 0;
  @State expectedSize: number = 0;
  @State playbackRate: number = 1;
  @State showMenu: boolean = false;
  @State videoCompleted: boolean = false;
  @State pendingSave: boolean = false;
  @State saving: boolean = false;
  @State surfaceReady: boolean = false;
  @State playerReady: boolean = false;
  @State isPlaying: boolean = false;
  @State currentTimeMs: number = 0;
  @State durationMs: number = 0;
  @State showControls: boolean = true;
  @State title: string = '视频';
  @State subtitle: string = '';
  @State description: string = '';
  @State playbackProtocol: string = '未初始化';
  @State showPlaybackInfo: boolean = false;
  @State playerState: string = 'idle';
  @State videoWidth: number = 0;
  @State videoHeight: number = 0;
  @State viewportWidth: number = 0;
  @State viewportHeight: number = 0;
  @State isFullScreenMode: boolean = false;
  @State pipActive: boolean = false;
  @State mediaItems: MediaPreviewItem[] = [];
  @State mediaIndex: number = 0;
  @State currentMediaType: string = 'video';
  private td = TdlibService.getInstance();
  private cacheController: ChatDownloadCacheController = ChatDownloadCacheController.getInstance();
  private listenersRegistered: boolean = false;
  private xComponentController: XComponentController = new XComponentController();
  private mediaSwiperController: SwiperController = new SwiperController();
  private surfaceId: string = '';
  private player: media.AVPlayer | null = null;
  private creatingPlayer: boolean = false;
  private prepareStarted: boolean = false;
  private preparingSource: string = '';
  private streamFile: fileIo.File | null = null;
  private streamPath: string = '';
  private lastRequestedOffset: number = -1;
  private cacheCompletedRoute: boolean = false;
  private mainWindow: window.Window | null = null;
  private previousSystemBarProperties: window.SystemBarProperties | null = null;
  private previousPreferredOrientation: window.Orientation | null = null;
  private pipController: PiPWindow.PiPController | null = null;
  private cleanupStarted: boolean = false;
  private playbackStopped: boolean = false;
  private controlsHideToken: number = 0;
  private pathRetryToken: number = 0;
  private sequentialDownloadStarted: boolean = false;
  private seekDebounceToken: number = 0;
  private seekFallbackToken: number = 0;
  private seekInProgress: boolean = false;
  private queuedSeekMs: number = -1;
  private lastIssuedSeekMs: number = -1;
  private readonly seekDebounceMs: number = 180;
  private readonly streamStartBufferSize: number = 2 * 1024 * 1024;
  private readonly streamReadAheadSize: number = 4 * 1024 * 1024;

  aboutToAppear() {
    this.readRouteParams();
    this.cacheController.setContext(getContext(this) as common.UIAbilityContext);
    this.cacheController.registerTdlibListeners();
    this.applyVideoSystemBars();
    this.registerListeners();
    if (this.isCurrentVideo() && this.fileId !== 0) {
      this.statusText = this.videoCompleted ? '正在打开视频...' : '正在缓存视频...';
      if (this.chatId !== 0 && this.messageId !== 0) {
        this.td.openMessageContent(this.chatId, this.messageId);
      }
      if (!this.videoCompleted) {
        console.error(`[VideoPlayerPage] start cache fileId=${this.fileId}, messageId=${this.messageId}`);
        this.startSequentialVideoDownload();
        this.scheduleLocalPathRetry();
      }
    } else if (this.isCurrentVideo()) {
      this.statusText = '视频参数错误';
      console.error('[VideoPlayerPage] fileId is invalid');
    } else {
      this.statusText = '';
    }
    this.scheduleHideControls();
  }

  aboutToDisappear(): void {
    this.stopVideoAndPauseDownload();
    this.restoreSystemBars();
  }

  onBackPress(): boolean {
    if (this.isFullScreenMode) {
      this.exitFullScreenMode();
      return true;
    }
    this.stopVideoAndPauseDownload();
    return false;
  }

  private applyVideoSystemBars(): void {
    try {
      const context = getContext(this) as common.UIAbilityContext;
      window.getLastWindow(context).then((mainWindow: window.Window) => {
        this.mainWindow = mainWindow;
        this.previousSystemBarProperties = mainWindow.getWindowSystemBarProperties();
        this.previousPreferredOrientation = mainWindow.getPreferredOrientation();
        const rect = mainWindow.getWindowProperties().windowRect;
        this.viewportWidth = px2vp(rect.width);
        this.viewportHeight = px2vp(rect.height);
        mainWindow.setWindowSystemBarProperties({
          statusBarColor: '#00000000',
          statusBarContentColor: '#FFFFFFFF',
          isStatusBarLightIcon: true,
          navigationBarColor: '#00000000',
          navigationBarContentColor: '#FFFFFFFF',
          isNavigationBarLightIcon: true
        });
      }).catch((err: OperationError) => {
        console.error(`[VideoPlayerPage] getLastWindow failed code=${err.code}, message=${err.message}`);
      });
    } catch (err) {
      const error = err as OperationError;
      console.error(`[VideoPlayerPage] apply system bars failed code=${error.code}, message=${error.message}`);
    }
  }

  private restoreSystemBars(): void {
    const mainWindow = this.mainWindow;
    const previous = this.previousSystemBarProperties;
    if (mainWindow === null || previous === null) {
      return;
    }
    const preferredOrientation = this.previousPreferredOrientation;
    if (preferredOrientation !== null) {
      mainWindow.setPreferredOrientation(preferredOrientation).catch((err: OperationError) => {
        console.error(`[VideoPlayerPage] restore orientation failed code=${err.code}, message=${err.message}`);
      });
    }
    mainWindow.setWindowSystemBarEnable(['status', 'navigation']).catch((err: OperationError) => {
      console.error(`[VideoPlayerPage] restore system bar enable failed code=${err.code}, message=${err.message}`);
    });
    mainWindow.setWindowSystemBarProperties(previous).catch((err: OperationError) => {
      console.error(`[VideoPlayerPage] restore system bars failed code=${err.code}, message=${err.message}`);
    });
    this.mainWindow = null;
    this.previousSystemBarProperties = null;
    this.previousPreferredOrientation = null;
  }

  private scheduleHideControls(delayMs: number = 3000): void {
    const token = ++this.controlsHideToken;
    setTimeout(() => {
      if (this.controlsHideToken !== token || this.showMenu || this.showPlaybackInfo) {
        return;
      }
      this.showControls = false;
    }, delayMs);
  }

  private showControlsTemporarily(): void {
    this.showControls = true;
    this.scheduleHideControls();
  }

  private toggleControlsFromSurface(): void {
    if (this.showControls) {
      this.controlsHideToken += 1;
      this.showControls = false;
    } else {
      this.showControlsTemporarily();
    }
  }

  private exitFullScreenMode(): void {
    const mainWindow = this.mainWindow;
    if (mainWindow === null) {
      this.isFullScreenMode = false;
      return;
    }
    const nextOrientation = this.previousPreferredOrientation !== null ? this.previousPreferredOrientation : window.Orientation.PORTRAIT;
    mainWindow.setPreferredOrientation(nextOrientation).then(() => {
      return mainWindow.setWindowSystemBarEnable(['status', 'navigation']);
    }).then(() => {
      this.isFullScreenMode = false;
      this.statusText = '';
      this.showControlsTemporarily();
      console.info('[VideoPlayerPage] exit full screen by back');
    }).catch((err: OperationError) => {
      console.error(`[VideoPlayerPage] exit full screen failed code=${err.code}, message=${err.message}`);
      this.isFullScreenMode = false;
    });
  }

  private readRouteParams(): void {
    this.playbackStopped = false;
    this.cleanupStarted = false;
    const params = router.getParams() as VideoRouteParams;
    if (params && params.chatId !== undefined) {
      this.chatId = Number(params.chatId);
    }
    if (params && params.mediaItemsJson !== undefined && params.mediaItemsJson.length > 0) {
      this.mediaItems = this.parseMediaItems(params.mediaItemsJson);
    }
    if (params && params.mediaIndex !== undefined) {
      this.mediaIndex = Number(params.mediaIndex);
    }
    if (this.mediaItems.length > 0 && this.mediaIndex >= 0 && this.mediaIndex < this.mediaItems.length) {
      this.applyMediaItem(this.mediaIndex, false);
      return;
    }
    if (params && params.messageId !== undefined) {
      this.messageId = Number(params.messageId);
    }
    if (params && params.fileId !== undefined) {
      this.fileId = Number(params.fileId);
    }
    if (params && params.videoPath !== undefined) {
      this.videoPath = params.videoPath;
      this.videoLocalPath = this.toLocalFilePath(params.videoPath);
    }
    if (params && params.previewUri !== undefined) {
      this.previewUri = params.previewUri;
    }
    if (params && params.title !== undefined && params.title.length > 0) {
      this.title = params.title;
    }
    if (params && params.subtitle !== undefined) {
      this.subtitle = params.subtitle;
    }
    if (params && params.description !== undefined) {
      this.description = params.description;
    }
    if (params && params.fileSize !== undefined) {
      this.expectedSize = Number(params.fileSize);
    }
    if (params && params.downloadedSize !== undefined) {
      this.downloadedSize = Number(params.downloadedSize);
    }
    if (params && params.cacheCompleted !== undefined) {
      this.cacheCompletedRoute = params.cacheCompleted === true || params.cacheCompleted === 'true';
    }
    if (params && params.duration !== undefined) {
      this.durationMs = Number(params.duration) * 1000;
    }
    if (params && params.videoWidth !== undefined) {
      this.videoWidth = Number(params.videoWidth);
    }
    if (params && params.videoHeight !== undefined) {
      this.videoHeight = Number(params.videoHeight);
    }
    this.currentMediaType = 'video';
    this.videoCompleted = this.cacheCompletedRoute || this.isVideoCacheComplete(this.videoPath, this.downloadedSize, this.expectedSize);
    console.info(`[VideoPlayerPage] params chatId=${this.chatId}, messageId=${this.messageId}, fileId=${this.fileId}, path=${this.videoPath}`);
  }

  private parseMediaItems(value: string): MediaPreviewItem[] {
    try {
      const parsed = JSON.parse(value) as MediaPreviewItem[];
      return Array.isArray(parsed) ? parsed : [];
    } catch (err) {
      console.error(`[VideoPlayerPage] parse media items failed ${JSON.stringify(err)}`);
      return [];
    }
  }

  private isCurrentVideo(): boolean {
    return this.currentMediaType === 'video' || this.currentMediaType === 'animation';
  }

  private isVideoCacheComplete(path: string, downloadedSize: number, expectedSize: number): boolean {
    if (path.length === 0) {
      return false;
    }
    if (expectedSize <= 0) {
      return downloadedSize > 0;
    }
    return downloadedSize >= expectedSize;
  }

  private applyMediaItem(index: number, stopPrevious: boolean): void {
    if (index < 0 || index >= this.mediaItems.length) {
      return;
    }
    if (stopPrevious) {
      this.stopCurrentVideoForSwitch();
    }
    const item = this.mediaItems[index];
    this.playbackStopped = false;
    this.cleanupStarted = false;
    this.mediaIndex = index;
    this.currentMediaType = item.type;
    this.messageId = item.messageId;
    this.fileId = item.fileId;
    this.videoPath = item.displayPath;
    this.previewUri = item.previewPath;
    this.videoLocalPath = this.toLocalFilePath(item.displayPath);
    this.title = item.title.length > 0 ? item.title : (item.type === 'photo' ? '图片' : '视频');
    this.subtitle = item.subtitle;
    this.description = item.description;
    this.expectedSize = item.fileSize;
    this.downloadedSize = item.downloadedSize;
    this.downloadedPrefixSize = item.downloadedSize;
    this.durationMs = item.duration * 1000;
    this.videoWidth = item.mediaWidth;
    this.videoHeight = item.mediaHeight;
    this.videoCompleted = item.type === 'photo' ||
      this.isVideoCacheComplete(item.displayPath, item.downloadedSize, item.fileSize);
    this.statusText = item.type === 'photo' ? '' : (item.displayPath.length > 0 ? '' : '正在缓存视频...');
    this.resetPlaybackStateForMediaSwitch();
    if (this.isCurrentVideo() && this.fileId !== 0) {
      if (this.chatId !== 0 && this.messageId !== 0) {
        this.td.openMessageContent(this.chatId, this.messageId);
      }
      this.startSequentialVideoDownload();
      this.scheduleLocalPathRetry();
    }
    console.info(`[VideoPlayerPage] apply media index=${index}, type=${item.type}, messageId=${item.messageId}, fileId=${item.fileId}`);
  }

  private setMediaIndexFromThumb(index: number): void {
    if (index < 0 || index >= this.mediaItems.length || index === this.mediaIndex) {
      return;
    }
    this.mediaSwiperController.changeIndex(index, true);
    this.applyMediaItem(index, true);
    this.showControlsTemporarily();
  }

  private resetPlaybackStateForMediaSwitch(): void {
    this.surfaceReady = false;
    this.playerReady = false;
    this.isPlaying = false;
    this.currentTimeMs = 0;
    this.playerState = 'idle';
    this.playbackProtocol = '未初始化';
    this.creatingPlayer = false;
    this.prepareStarted = false;
    this.preparingSource = '';
    this.lastRequestedOffset = -1;
    this.sequentialDownloadStarted = false;
    this.seekDebounceToken += 1;
    this.seekFallbackToken += 1;
    this.seekInProgress = false;
    this.queuedSeekMs = -1;
    this.lastIssuedSeekMs = -1;
  }

  private stopCurrentVideoForSwitch(): void {
    this.playbackStopped = true;
    this.pathRetryToken += 1;
    this.releasePlayer();
    if (this.fileId !== 0) {
      this.td.stopVideoProxy(this.fileId);
    }
    if (this.isCurrentVideo() && this.fileId !== 0 && !this.videoCompleted) {
      if (!this.cacheController.isCaching(this.fileId)) {
        this.td.cancelDownloadFile(this.fileId);
      }
    }
  }

  private registerListeners(): void {
    if (this.listenersRegistered) {
      return;
    }
    this.listenersRegistered = true;
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
  }

  private applyFileUpdate(file: TdFile): void {
    if (this.shouldStopVideoWork() || file.id !== this.fileId) {
      return;
    }
    if (file.local && file.local.path.length > 0) {
      this.videoLocalPath = this.toLocalFilePath(file.local.path);
      this.videoPath = this.toFileSource(this.videoLocalPath);
    }
    this.downloadedPrefixSize = Math.max(this.downloadedPrefixSize, this.getDownloadedPrefixSize(file));
    const nextDownloadedSize = this.getDownloadedSize(file);
    this.downloadedSize = Math.max(this.downloadedSize, nextDownloadedSize);
    this.expectedSize = Math.max(this.expectedSize, this.getExpectedSize(file));
    this.videoCompleted = (file.local ? file.local.is_downloading_completed === true : false) ||
      this.isVideoCacheComplete(this.videoPath, this.downloadedSize, this.expectedSize);
    this.statusText = this.videoPath.length > 0 ? '' : '正在缓存视频...';
    console.error(`[VideoPlayerPage] file update fileId=${file.id}, path=${this.videoPath}, prefix=${this.downloadedPrefixSize}, downloaded=${this.downloadedSize}, expected=${this.expectedSize}, completed=${this.videoCompleted}`);
    this.tryStartPlayer();
    if (this.pendingSave && this.videoCompleted && this.videoPath.length > 0) {
      this.performSaveVideo();
    }
  }

  private getDownloadedSize(file: TdFile): number {
    if (!file.local) {
      return 0;
    }
    const prefixSize = file.local.downloaded_prefix_size !== undefined ? file.local.downloaded_prefix_size : 0;
    const downloadedSize = file.local.downloaded_size !== undefined ? file.local.downloaded_size : 0;
    return Math.max(prefixSize, downloadedSize);
  }

  private getDownloadedPrefixSize(file: TdFile): number {
    if (!file.local) {
      return 0;
    }
    if (file.local.is_downloading_completed === true) {
      const expected = this.getExpectedSize(file);
      return expected > 0 ? expected : this.downloadedSize;
    }
    return file.local.downloaded_prefix_size !== undefined ? file.local.downloaded_prefix_size : 0;
  }

  private getExpectedSize(file: TdFile): number {
    if (file.size !== undefined && file.size > 0) {
      return file.size;
    }
    if (file.expected_size !== undefined) {
      return file.expected_size;
    }
    return 0;
  }

  private toFileSource(path: string): string {
    if (path.startsWith('file://')) {
      return path;
    }
    return `file://${path}`;
  }

  private toLocalFilePath(source: string): string {
    if (source.startsWith('file://')) {
      return source.substring(7);
    }
    return source;
  }

  private isFilesystemPath(path: string): boolean {
    return path.length > 0 && path.indexOf('://') < 0;
  }

  private getProgressText(): string {
    if (this.saving) {
      return '正在保存到图库...';
    }
    if (this.pendingSave && !this.videoCompleted) {
      return '缓存完成后保存到图库';
    }
    if (this.expectedSize > 0) {
      return `缓存 ${Math.floor(this.downloadedSize * 100 / this.expectedSize)}%`;
    }
    if (this.downloadedSize > 0) {
      return `已缓存 ${Math.floor(this.downloadedSize / 1024)} KB`;
    }
    return this.statusText;
  }

  private getBufferedDurationMs(): number {
    if (this.durationMs <= 0 || this.expectedSize <= 0) {
      return this.videoCompleted ? this.durationMs : 0;
    }
    const bufferedSize = this.downloadedPrefixSize > 0 ? this.downloadedPrefixSize : this.downloadedSize;
    return Math.min(this.durationMs, Math.max(0, Math.floor(this.durationMs * bufferedSize / this.expectedSize)));
  }

  private getCacheProgressText(): string {
    if (this.videoCompleted) {
      return '缓存完成';
    }
    if (this.expectedSize > 0) {
      const bufferedSize = this.downloadedPrefixSize > 0 ? this.downloadedPrefixSize : this.downloadedSize;
      return `已缓存 ${Math.min(100, Math.floor(bufferedSize * 100 / this.expectedSize))}%`;
    }
    return this.statusText.length > 0 ? this.statusText : '正在缓存';
  }

  private getFileSizeText(): string {
    const size = this.expectedSize > 0 ? this.expectedSize : this.downloadedSize;
    if (size <= 0) {
      return this.statusText.length > 0 ? this.statusText : '正在加载';
    }
    if (size >= 1024 * 1024 * 1024) {
      return `${(size / 1024 / 1024 / 1024).toFixed(1)} GB`;
    }
    if (size >= 1024 * 1024) {
      return `${(size / 1024 / 1024).toFixed(1)} MB`;
    }
    if (size >= 1024) {
      return `${Math.floor(size / 1024)} KB`;
    }
    return `${size} B`;
  }

  private togglePlaybackRate(): void {
    this.playbackRate = this.playbackRate === 2 ? 1 : 2;
    this.statusText = this.playbackRate === 2 ? '2倍速播放' : '';
    console.info(`[VideoPlayerPage] toggle playbackRate=${this.playbackRate}`);
    this.applyPlaybackRate();
  }

  private onSurfaceLoaded(): void {
    this.surfaceId = this.xComponentController.getXComponentSurfaceId();
    this.surfaceReady = this.surfaceId.length > 0;
    console.info(`[VideoPlayerPage] XComponent surface loaded surfaceId=${this.surfaceId}`);
    this.tryStartPlayer();
  }

  private onSurfaceDestroyed(): void {
    console.info('[VideoPlayerPage] XComponent surface destroyed');
    this.surfaceId = '';
    this.surfaceReady = false;
    this.releasePlayer();
  }

  private tryStartPlayer(): void {
    if (this.shouldStopVideoWork() || !this.surfaceReady || this.fileId === 0 || this.videoLocalPath.length === 0) {
      return;
    }
    if (!this.isFilesystemPath(this.videoLocalPath)) {
      this.statusText = '视频本地路径不可读';
      console.error(`[VideoPlayerPage] invalid local path=${this.videoLocalPath}`);
      return;
    }
    if (this.videoCompleted) {
      this.createAndPreparePlayer(this.videoLocalPath, 'local file', this.videoLocalPath);
      return;
    }
    const proxyUrl = this.td.startVideoProxy(this.fileId, this.videoLocalPath,
      this.expectedSize > 0 ? this.expectedSize : this.downloadedSize,
      this.downloadedPrefixSize, this.downloadedSize, this.videoCompleted);
    if (this.player !== null && this.preparingSource === proxyUrl) {
      return;
    }
    this.createAndPreparePlayer(proxyUrl, 'TDLib downloadFile + local HTTP Range proxy');
  }

  private createAndPreparePlayer(sourceUrl: string, protocol: string, localPath: string = ''): void {
    if (this.shouldStopVideoWork() || this.creatingPlayer) {
      return;
    }
    this.creatingPlayer = true;
    const source = sourceUrl;
    this.statusText = '正在打开视频流...';
    this.releasePlayer(false);
    media.createAVPlayer().then((player: media.AVPlayer) => {
      if (this.shouldStopVideoWork()) {
        player.release().catch((err: OperationError) => {
          console.error(`[VideoPlayerPage] release stopped player failed code=${err.code}, message=${err.message}`);
        });
        return;
      }
      this.player = player;
      this.preparingSource = source;
      this.prepareStarted = false;
      this.bindPlayerEvents(player);
      this.playbackProtocol = protocol;
      console.error(`[VideoPlayerPage] AVPlayer use ${protocol} url=${source}, localPath=${this.videoLocalPath}, prefix=${this.downloadedPrefixSize}, downloaded=${this.downloadedSize}, expected=${this.expectedSize}`);
      if (localPath.length > 0) {
        if (!this.bindLocalFileSource(player, localPath)) {
          this.creatingPlayer = false;
          this.playerReady = false;
          this.releasePlayer(false);
          this.statusText = '播放失败';
          return;
        }
      } else {
        player.url = source;
      }
    }).catch((err: OperationError) => {
      if (this.shouldStopVideoWork()) {
        return;
      }
      this.creatingPlayer = false;
      this.playerReady = false;
      this.releasePlayer(false);
      console.error(`[VideoPlayerPage] AVPlayer create/open failed code=${err.code}, message=${err.message}`);
      this.statusText = this.videoCompleted ? '视频暂不支持播放' : '正在缓存视频...';
      if (this.fileId !== 0 && !this.videoCompleted) {
        this.requestStreamRange(0, this.getStartBufferSize());
      }
    });
  }

  private bindLocalFileSource(player: media.AVPlayer, localPath: string): boolean {
    try {
      this.closeStreamFile();
      this.streamFile = fileIo.openSync(localPath, fileIo.OpenMode.READ_ONLY);
      this.streamPath = localPath;
      const stat = fileIo.statSync(localPath);
      const length = stat.size > 0 ? stat.size : (this.expectedSize > 0 ? this.expectedSize : this.downloadedSize);
      const descriptor: media.AVFileDescriptor = {
        fd: this.streamFile.fd,
        offset: 0,
        length: length
      };
      player.fdSrc = descriptor;
      return true;
    } catch (err) {
      const error = err as OperationError;
      console.error(`[VideoPlayerPage] bind local fdSrc failed code=${error.code}, message=${error.message}, path=${localPath}`);
      this.closeStreamFile();
      return false;
    }
  }

  private prepareInitializedPlayer(player: media.AVPlayer): void {
    if (this.shouldStopVideoWork() || player !== this.player || this.prepareStarted) {
      return;
    }
    if (this.surfaceId.length === 0) {
      this.statusText = '视频窗口未准备好';
      return;
    }
    this.prepareStarted = true;
    try {
      player.surfaceId = this.surfaceId;
      console.info(`[VideoPlayerPage] AVPlayer prepare source=${this.preparingSource}, surfaceId=${this.surfaceId}`);
      player.prepare().catch((err: OperationError) => {
        if (this.shouldStopVideoWork()) {
          return;
        }
        this.creatingPlayer = false;
        this.playerReady = false;
        this.releasePlayer(false);
        console.error(`[VideoPlayerPage] AVPlayer prepare failed code=${err.code}, message=${err.message}`);
        this.statusText = this.videoCompleted ? '视频暂不支持播放' : '正在缓存视频...';
        if (this.fileId !== 0 && !this.videoCompleted) {
          this.requestStreamRange(0, this.getStartBufferSize());
        }
      });
    } catch (err) {
      const error = err as OperationError;
      this.creatingPlayer = false;
      this.playerReady = false;
      this.releasePlayer(false);
      console.error(`[VideoPlayerPage] AVPlayer set surface failed code=${error.code}, message=${error.message}`);
      this.statusText = '视频窗口初始化失败';
    }
  }

  private playPreparedPlayer(player: media.AVPlayer): void {
    if (this.shouldStopVideoWork() || player !== this.player) {
      return;
    }
    this.creatingPlayer = false;
    this.playerReady = true;
    this.statusText = '';
    this.durationMs = player.duration > 0 ? player.duration : this.durationMs;
    this.applyPreparedVideoSize(player);
    try {
      player.videoScaleType = media.VideoScaleType.VIDEO_SCALE_TYPE_SCALED_ASPECT;
    } catch (err) {
      const error = err as OperationError;
      console.error(`[VideoPlayerPage] set video scale failed code=${error.code}, message=${error.message}`);
    }
    this.applyPlaybackRate();
    player.play().then(() => {
      if (this.shouldStopVideoWork() || player !== this.player) {
        return;
      }
      this.isPlaying = true;
      this.scheduleHideControls();
    }).catch((err: OperationError) => {
      if (this.shouldStopVideoWork()) {
        return;
      }
      console.error(`[VideoPlayerPage] AVPlayer play failed code=${err.code}, message=${err.message}`);
      this.statusText = '播放失败';
    });
  }

  private tryBindDataSource(player: media.AVPlayer, source: string): boolean {
    const localPath = this.toLocalFilePath(source);
    if (!this.isFilesystemPath(localPath)) {
      return false;
    }
    try {
      this.closeStreamFile();
      this.streamFile = fileIo.openSync(localPath, fileIo.OpenMode.READ_ONLY);
      this.streamPath = localPath;
      this.lastRequestedOffset = -1;
      const totalSize = this.expectedSize > 0 ? this.expectedSize : -1;
      const descriptor: media.AVDataSrcDescriptor = {
        fileSize: totalSize,
        callback: (buffer: ArrayBuffer, length: number, pos?: number): number => {
          return this.readStreamData(buffer, length, pos);
        }
      };
      player.dataSrc = descriptor;
      return true;
    } catch (err) {
      const error = err as OperationError;
      console.error(`[VideoPlayerPage] bind dataSrc failed code=${error.code}, message=${error.message}, path=${localPath}`);
      this.closeStreamFile();
      return false;
    }
  }

  private readStreamData(buffer: ArrayBuffer, length: number, pos?: number): number {
    if (this.shouldStopVideoWork()) {
      return -2;
    }
    const file = this.streamFile;
    if (file === null || this.streamPath.length === 0 || length <= 0) {
      return -2;
    }
    const offset = pos === undefined ? 0 : Math.max(0, pos);
    const availableSize = this.getAvailableStreamSize();
    if (availableSize <= offset) {
      this.requestStreamRange(offset, length);
      return this.videoCompleted ? -1 : 0;
    }
    const readableLength = Math.min(length, availableSize - offset);
    try {
      return fileIo.readSync(file.fd, buffer, {
        offset: offset,
        length: readableLength
      });
    } catch (err) {
      const error = err as OperationError;
      console.error(`[VideoPlayerPage] read stream failed code=${error.code}, message=${error.message}, offset=${offset}, length=${readableLength}`);
      return -2;
    }
  }

  private getAvailableStreamSize(): number {
    if (!this.videoCompleted) {
      return this.downloadedSize;
    }
    if (this.streamPath.length === 0) {
      return this.downloadedSize;
    }
    try {
      const stat = fileIo.statSync(this.streamPath);
      return Math.max(this.downloadedSize, stat.size);
    } catch (_err) {
      return this.downloadedSize;
    }
  }

  private requestStreamRange(offset: number, length: number): void {
    if (this.shouldStopVideoWork() || this.fileId === 0 || this.videoCompleted) {
      return;
    }
    const requestOffset = Math.max(0, offset);
    if (this.lastRequestedOffset >= 0 && Math.abs(requestOffset - this.lastRequestedOffset) < 512 * 1024) {
      console.info(`[VideoPlayerPage] skip duplicate stream range fileId=${this.fileId}, offset=${requestOffset}, last=${this.lastRequestedOffset}`);
      return;
    }
    this.lastRequestedOffset = requestOffset;
    const requestLength = Math.max(length, this.streamReadAheadSize);
    console.info(`[VideoPlayerPage] request stream range fileId=${this.fileId}, offset=${requestOffset}, limit=${requestLength}`);
    if (requestOffset === 0 || requestOffset < this.downloadedPrefixSize + this.streamReadAheadSize) {
      this.startSequentialVideoDownload();
      return;
    }
    this.td.downloadFile(this.fileId, 32, requestOffset, requestLength);
  }

  private startSequentialVideoDownload(): void {
    if (this.shouldStopVideoWork() || this.fileId === 0 || this.videoCompleted) {
      return;
    }
    console.error(`[VideoPlayerPage] start sequential download fileId=${this.fileId}, path=${this.videoLocalPath}, prefix=${this.downloadedPrefixSize}, downloaded=${this.downloadedSize}`);
    this.sequentialDownloadStarted = true;
    this.td.downloadFile(this.fileId, 32, 0, 0);
  }

  private scheduleLocalPathRetry(): void {
    const token = ++this.pathRetryToken;
    setTimeout(() => {
      if (this.shouldStopVideoWork() || token !== this.pathRetryToken || this.videoCompleted || this.videoLocalPath.length > 0) {
        return;
      }
      console.error(`[VideoPlayerPage] local path still empty, retry download fileId=${this.fileId}, downloaded=${this.downloadedSize}, expected=${this.expectedSize}`);
      this.startSequentialVideoDownload();
      this.scheduleLocalPathRetry();
    }, 1200);
  }

  private getStartBufferSize(): number {
    if (this.expectedSize > 0) {
      return Math.min(this.expectedSize, this.streamStartBufferSize);
    }
    return this.streamStartBufferSize;
  }

  private bindPlayerEvents(player: media.AVPlayer): void {
    player.on('stateChange', (state: media.AVPlayerState, reason: media.StateChangeReason) => {
      if (this.shouldStopVideoWork() || player !== this.player) {
        return;
      }
      console.error(`[VideoPlayerPage] AVPlayer state=${state}, reason=${reason}`);
      this.playerState = state;
      this.isPlaying = state === 'playing';
      if (state === 'initialized') {
        this.prepareInitializedPlayer(player);
      }
      if (state === 'playing') {
        this.scheduleHideControls();
      }
      if (state === 'prepared') {
        this.playPreparedPlayer(player);
      }
      if (state === 'completed') {
        this.isPlaying = false;
        this.currentTimeMs = this.durationMs;
      }
      if (state === 'error') {
        this.playerReady = false;
        this.statusText = '播放失败';
      }
      this.updatePiPPlayPauseStatus();
    });
    player.on('timeUpdate', (timeMs: number) => {
      if (this.shouldStopVideoWork() || player !== this.player) {
        return;
      }
      this.currentTimeMs = timeMs;
      if (player.duration > 0) {
        this.durationMs = player.duration;
      }
    });
    player.on('durationUpdate', (durationMs: number) => {
      if (this.shouldStopVideoWork() || player !== this.player) {
        return;
      }
      this.durationMs = durationMs;
    });
    player.on('seekDone', (seekDoneTimeMs: number) => {
      if (this.shouldStopVideoWork() || player !== this.player) {
        return;
      }
      console.error(`[VideoPlayerPage] AVPlayer seekDone time=${seekDoneTimeMs}, queued=${this.queuedSeekMs}`);
      this.seekInProgress = false;
      this.currentTimeMs = seekDoneTimeMs;
      this.executeQueuedSeek();
    });
    player.on('error', (err: BusinessError) => {
      if (this.shouldStopVideoWork() || player !== this.player) {
        return;
      }
      console.error(`[VideoPlayerPage] AVPlayer error code=${err.code}, message=${err.message}`);
      this.statusText = '播放失败';
      this.isPlaying = false;
      this.playerReady = false;
      this.updatePiPPlayPauseStatus();
    });
  }

  private releasePlayer(clearStatus: boolean = true): void {
    const player = this.player;
    this.player = null;
    this.playerReady = false;
    this.isPlaying = false;
    this.seekInProgress = false;
    this.queuedSeekMs = -1;
    this.lastIssuedSeekMs = -1;
    this.seekDebounceToken++;
    this.seekFallbackToken++;
    this.pathRetryToken++;
    this.preparingSource = '';
    this.creatingPlayer = false;
    this.prepareStarted = false;
    if (clearStatus) {
      this.currentTimeMs = 0;
      this.durationMs = 0;
    }
    if (player === null) {
      this.closeStreamFile();
      return;
    }
    player.release().then(() => {
      console.info('[VideoPlayerPage] AVPlayer released');
    }).catch((err: OperationError) => {
      console.error(`[VideoPlayerPage] AVPlayer release failed code=${err.code}, message=${err.message}`);
    });
    this.closeStreamFile();
  }

  private shouldStopVideoWork(): boolean {
    return this.playbackStopped || this.cleanupStarted;
  }

  private closeStreamFile(): void {
    if (this.streamFile === null) {
      return;
    }
    try {
      fileIo.closeSync(this.streamFile);
    } catch (err) {
      const error = err as OperationError;
      console.error(`[VideoPlayerPage] close stream file failed code=${error.code}, message=${error.message}`);
    }
    this.streamFile = null;
    this.streamPath = '';
  }

  private applyPlaybackRate(): void {
    const player = this.player;
    if (player === null || !this.playerReady) {
      return;
    }
    const speed = this.playbackRate === 2 ? media.PlaybackSpeed.SPEED_FORWARD_2_00_X :
      media.PlaybackSpeed.SPEED_FORWARD_1_00_X;
    try {
      player.setSpeed(speed);
    } catch (err) {
      const error = err as OperationError;
      console.error(`[VideoPlayerPage] setSpeed failed code=${error.code}, message=${error.message}`);
    }
  }

  private togglePlayPause(): void {
    const player = this.player;
    if (player === null || !this.playerReady) {
      return;
    }
    if (this.isPlaying) {
      player.pause().then(() => {
        this.isPlaying = false;
        this.showControlsTemporarily();
        this.updatePiPPlayPauseStatus();
      }).catch((err: OperationError) => {
        console.error(`[VideoPlayerPage] pause failed code=${err.code}, message=${err.message}`);
      });
      return;
    }
    player.play().then(() => {
      this.isPlaying = true;
      this.scheduleHideControls();
      this.updatePiPPlayPauseStatus();
    }).catch((err: OperationError) => {
      console.error(`[VideoPlayerPage] play failed code=${err.code}, message=${err.message}`);
    });
  }

  private handlePrimaryPlaybackClick(): void {
    if (!this.isPlaying) {
      this.showPlaybackInfo = true;
    }
    this.togglePlayPause();
  }

  private seekTo(value: number): void {
    this.queueSeekTo(value, true);
  }

  private queueSeekTo(value: number, debounce: boolean): void {
    const player = this.player;
    if (player === null || !this.playerReady) {
      return;
    }
    const maxTime = this.durationMs > 0 ? this.durationMs : value;
    this.queuedSeekMs = Math.max(0, Math.min(Math.floor(value), maxTime));
    console.error(`[VideoPlayerPage] user seek target=${this.queuedSeekMs}, duration=${this.durationMs}, prefix=${this.downloadedPrefixSize}, downloaded=${this.downloadedSize}`);
    if (!debounce) {
      this.executeQueuedSeek();
      return;
    }
    const token = ++this.seekDebounceToken;
    setTimeout(() => {
      if (token !== this.seekDebounceToken) {
        return;
      }
      this.executeQueuedSeek();
    }, this.seekDebounceMs);
  }

  private executeQueuedSeek(): void {
    const player = this.player;
    if (player === null || !this.playerReady || this.queuedSeekMs < 0 || this.seekInProgress) {
      return;
    }
    const target = this.queuedSeekMs;
    this.queuedSeekMs = -1;
    if (Math.abs(target - this.currentTimeMs) < 250) {
      return;
    }
    this.seekInProgress = true;
    this.lastIssuedSeekMs = target;
    console.error(`[VideoPlayerPage] execute seek target=${target}`);
    try {
      player.seek(target, media.SeekMode.SEEK_CLOSEST);
      const fallbackToken = ++this.seekFallbackToken;
      setTimeout(() => {
        if (fallbackToken !== this.seekFallbackToken || !this.seekInProgress || this.lastIssuedSeekMs !== target) {
          return;
        }
        console.error(`[VideoPlayerPage] seek fallback release target=${target}, queued=${this.queuedSeekMs}`);
        this.seekInProgress = false;
        this.executeQueuedSeek();
      }, 1500);
    } catch (err) {
      const error = err as OperationError;
      console.error(`[VideoPlayerPage] seek failed code=${error.code}, message=${error.message}`);
      this.seekInProgress = false;
      this.executeQueuedSeek();
    }
  }

  private seekBy(deltaMs: number): void {
    const nextTime = Math.max(0, Math.min(this.durationMs > 0 ? this.durationMs : this.currentTimeMs + deltaMs,
      this.currentTimeMs + deltaMs));
    this.queueSeekTo(nextTime, false);
  }

  private formatTime(timeMs: number): string {
    const totalSeconds = Math.max(0, Math.floor(timeMs / 1000));
    const minutes = Math.floor(totalSeconds / 60);
    const seconds = totalSeconds % 60;
    return `${minutes}:${seconds < 10 ? '0' : ''}${seconds}`;
  }

  private getProtocolFromSource(source: string): string {
    const separatorIndex = source.indexOf('://');
    if (separatorIndex > 0) {
      return source.substring(0, separatorIndex);
    }
    return 'file';
  }

  private getPlaybackAddress(): string {
    if (this.streamPath.length > 0) {
      return this.streamPath;
    }
    return this.videoPath.length > 0 ? this.videoPath : '暂无本地地址';
  }

  private getInfoDownloadedText(): string {
    if (this.expectedSize > 0) {
      const percent = Math.floor(this.downloadedSize * 100 / this.expectedSize);
      return `${this.getReadableBytes(this.downloadedSize)} / ${this.getReadableBytes(this.expectedSize)} (${percent}%)`;
    }
    return this.getReadableBytes(this.downloadedSize);
  }

  private getReadableBytes(size: number): string {
    if (size >= 1024 * 1024 * 1024) {
      return `${(size / 1024 / 1024 / 1024).toFixed(2)} GB`;
    }
    if (size >= 1024 * 1024) {
      return `${(size / 1024 / 1024).toFixed(2)} MB`;
    }
    if (size >= 1024) {
      return `${Math.floor(size / 1024)} KB`;
    }
    return `${Math.max(0, size)} B`;
  }

  private getShareUri(): string {
    if (this.videoPath.length > 0) {
      return this.videoPath.startsWith('file://') ? this.videoPath : this.toFileSource(this.videoPath);
    }
    if (this.videoLocalPath.length > 0) {
      return this.toFileSource(this.videoLocalPath);
    }
    return '';
  }

  private shareVideo(): void {
    const uri = this.getShareUri();
    if (uri.length === 0) {
      this.statusText = '视频文件地址为空';
      return;
    }
    if (!this.videoCompleted) {
      this.statusText = '视频未缓存完成，正在继续下载';
      this.td.downloadFile(this.fileId, 32);
      return;
    }
    const context = getContext(this) as common.UIAbilityContext;
    const want: Want = {
      action: 'ohos.want.action.sendData',
      type: 'video/*',
      uri: uri,
      flags: wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION,
      parameters: {
        [wantConstant.Params.PARAMS_STREAM]: uri,
        'ability.params.title': this.title,
        'ability.params.text': this.description.length > 0 ? this.description : this.title
      }
    };
    console.info(`[VideoPlayerPage] share video uri=${uri}`);
    context.startAbility(want).then(() => {
      this.statusText = '已打开分享';
    }).catch((err: OperationError) => {
      console.error(`[VideoPlayerPage] share video failed code=${err.code}, message=${err.message}`);
      this.statusText = '分享失败';
    });
  }

  private toggleFullScreen(): void {
    const mainWindow = this.mainWindow;
    if (mainWindow === null) {
      this.statusText = '窗口未准备好';
      return;
    }
    const nextFullScreen = !this.isFullScreenMode;
    const barNames: Array<'status' | 'navigation'> = nextFullScreen ? [] : ['status', 'navigation'];
    const nextOrientation = nextFullScreen ? window.Orientation.LANDSCAPE :
      (this.previousPreferredOrientation !== null ? this.previousPreferredOrientation : window.Orientation.PORTRAIT);
    mainWindow.setWindowLayoutFullScreen(true).then(() => {
      return mainWindow.setPreferredOrientation(nextOrientation);
    }).then(() => {
      return mainWindow.setWindowSystemBarEnable(barNames);
    }).then(() => {
      this.isFullScreenMode = nextFullScreen;
      this.statusText = nextFullScreen ? '已进入全屏' : '';
      this.showControlsTemporarily();
      console.info(`[VideoPlayerPage] toggle full screen=${nextFullScreen}`);
    }).catch((err: OperationError) => {
      console.error(`[VideoPlayerPage] toggle full screen failed code=${err.code}, message=${err.message}`);
      this.statusText = '全屏切换失败';
    });
  }

  private startPictureInPicture(): void {
    if (!this.surfaceReady) {
      this.statusText = '视频窗口未准备好';
      return;
    }
    try {
      if (!PiPWindow.isPiPEnabled()) {
        this.statusText = '系统未开启小窗能力';
        return;
      }
    } catch (err) {
      const error = err as OperationError;
      console.error(`[VideoPlayerPage] check PiP enabled failed code=${error.code}, message=${error.message}`);
      this.statusText = '小窗能力不可用';
      return;
    }
    if (this.pipController !== null) {
      this.pipController.startPiP().then(() => {
        this.pipActive = true;
        this.statusText = '已进入小窗';
      }).catch((err: OperationError) => {
        console.error(`[VideoPlayerPage] restart PiP failed code=${err.code}, message=${err.message}`);
        this.statusText = '小窗启动失败';
      });
      return;
    }
    const context = getContext(this) as common.UIAbilityContext;
    PiPWindow.create({
      context: context,
      componentController: this.xComponentController,
      templateType: PiPWindow.PiPTemplateType.VIDEO_PLAY,
      contentWidth: this.videoWidth > 0 ? this.videoWidth : 16,
      contentHeight: this.videoHeight > 0 ? this.videoHeight : 9,
      controlGroups: [PiPWindow.VideoPlayControlGroup.FAST_FORWARD_BACKWARD],
      defaultWindowSizeType: 1
    }).then((controller: PiPWindow.PiPController) => {
      this.pipController = controller;
      controller.on('stateChange', (state: PiPWindow.PiPState, reason: string): void => {
        console.info(`[VideoPlayerPage] PiP state=${state}, reason=${reason}`);
        this.pipActive = state === PiPWindow.PiPState.STARTED;
      });
      controller.updatePiPControlStatus(PiPWindow.PiPControlType.VIDEO_PLAY_PAUSE,
        this.isPlaying ? PiPWindow.PiPControlStatus.PLAY : PiPWindow.PiPControlStatus.PAUSE);
      if (this.videoWidth > 0 && this.videoHeight > 0) {
        controller.updateContentSize(this.videoWidth, this.videoHeight);
      }
      return controller.startPiP();
    }).then(() => {
      this.pipActive = true;
      this.statusText = '已进入小窗';
    }).catch((err: OperationError) => {
      console.error(`[VideoPlayerPage] start PiP failed code=${err.code}, message=${err.message}`);
      this.statusText = '小窗启动失败';
    });
  }

  private updatePiPPlayPauseStatus(): void {
    if (this.pipController === null) {
      return;
    }
    try {
      this.pipController.updatePiPControlStatus(PiPWindow.PiPControlType.VIDEO_PLAY_PAUSE,
        this.isPlaying ? PiPWindow.PiPControlStatus.PLAY : PiPWindow.PiPControlStatus.PAUSE);
    } catch (err) {
      const error = err as OperationError;
      console.error(`[VideoPlayerPage] update PiP status failed code=${error.code}, message=${error.message}`);
    }
  }

  private applyPreparedVideoSize(player: media.AVPlayer): void {
    if (player.width > 0 && player.height > 0) {
      this.videoWidth = player.width;
      this.videoHeight = player.height;
      console.info(`[VideoPlayerPage] prepared video size width=${player.width}, height=${player.height}`);
    }
  }

  private getVideoAspectRatio(): number {
    if (this.videoWidth > 0 && this.videoHeight > 0) {
      return this.videoWidth / this.videoHeight;
    }
    return 16 / 9;
  }

  private getVideoSurfaceWidth(): number | string {
    if (this.viewportWidth <= 0 || this.viewportHeight <= 0) {
      return '100%';
    }
    const videoRatio = this.getVideoAspectRatio();
    const viewportRatio = this.viewportWidth / this.viewportHeight;
    if (videoRatio >= viewportRatio) {
      return this.viewportWidth;
    }
    return this.viewportHeight * videoRatio;
  }

  private getVideoSurfaceHeight(): number | string {
    if (this.viewportWidth <= 0 || this.viewportHeight <= 0) {
      return '100%';
    }
    const videoRatio = this.getVideoAspectRatio();
    const viewportRatio = this.viewportWidth / this.viewportHeight;
    if (videoRatio >= viewportRatio) {
      return this.viewportWidth / videoRatio;
    }
    return this.viewportHeight;
  }

  @Builder
  private PlaybackInfoRow(label: string, value: string) {
    Row({ space: 8 }) {
      Text(label)
        .fontSize(12)
        .fontColor('#AEB4BC')
        .width(78)
      Text(value)
        .fontSize(12)
        .fontColor(Color.White)
        .layoutWeight(1)
        .maxLines(3)
        .textOverflow({ overflow: TextOverflow.Ellipsis })
    }
    .width('100%')
  }

  @Builder
  private PlaybackInfoDialog() {
    Stack({ alignContent: Alignment.Center }) {
      Column()
        .width('100%')
        .height('100%')
        .backgroundColor('#33000000')
        .onClick(() => {
          this.showPlaybackInfo = false;
        })
      Column({ space: 10 }) {
        Row() {
          Text('播放信息')
            .fontSize(16)
            .fontWeight(FontWeight.Bold)
            .fontColor(Color.White)
          Blank()
          Button('关闭')
            .fontSize(12)
            .fontColor(Color.White)
            .height(28)
            .borderRadius(14)
            .backgroundColor('#33FFFFFF')
            .onClick(() => {
              this.showPlaybackInfo = false;
            })
        }
        .width('100%')
        this.PlaybackInfoRow('文件地址', this.getPlaybackAddress())
        this.PlaybackInfoRow('播放协议', this.playbackProtocol)
        this.PlaybackInfoRow('下载进度', this.getInfoDownloadedText())
        this.PlaybackInfoRow('播放器', `${this.playerState} / ${this.playerReady ? 'ready' : 'not ready'}`)
        this.PlaybackInfoRow('消息', `chat=${this.chatId}, message=${this.messageId}, file=${this.fileId}`)
        this.PlaybackInfoRow('Surface', this.surfaceReady ? this.surfaceId : '未创建')
        this.PlaybackInfoRow('状态', this.statusText.length > 0 ? this.statusText : '正常')
      }
      .width('84%')
      .padding({ left: 16, right: 16, top: 14, bottom: 16 })
      .borderRadius(16)
      .backgroundColor('#CC161719')
      .backdropBlur(18)
      .border({ width: 1, color: '#26FFFFFF' })
    }
    .width('100%')
    .height('100%')
  }

  @Builder
  private CircleTextButton(text: string, size: number, fontSize: number, onClick: () => void) {
    Button(text)
      .fontSize(fontSize)
      .fontColor(Color.White)
      .width(size)
      .height(size)
      .borderRadius(size / 2)
      .backgroundColor('#661D1D1F')
      .border({ width: 1, color: '#18FFFFFF' })
      .onClick(onClick)
  }

  @Builder
  private CircleIconButton(icon: Resource, size: number, iconSize: number, onClick: () => void) {
    Button({ type: ButtonType.Circle }) {
      Image(icon)
        .width(iconSize)
        .height(iconSize)
        .objectFit(ImageFit.Contain)
    }
    .width(size)
    .height(size)
    .borderRadius(size / 2)
    .backgroundColor('#661D1D1F')
    .border({ width: 1, color: '#18FFFFFF' })
    .onClick(onClick)
  }

  @Builder
  private TransparentIconButton(icon: Resource, size: number, iconSize: number, onClick: () => void) {
    Button({ type: ButtonType.Circle }) {
      Image(icon)
        .width(iconSize)
        .height(iconSize)
        .objectFit(ImageFit.Contain)
    }
    .width(size)
    .height(size)
    .borderRadius(size / 2)
    .backgroundColor(Color.Transparent)
    .onClick(onClick)
  }

  @Builder
  private DownloadSaveButton() {
    SaveButton({
      icon: SaveIconStyle.LINES,
      text: SaveDescription.DOWNLOAD,
      buttonType: ButtonType.Capsule
    })
      .width(82)
      .height(38)
      .iconSize(18)
      .fontSize(13)
      .fontColor(Color.White)
      .iconColor(Color.White)
      .textIconSpace(4)
      .padding({ left: 12, right: 12 })
      .backgroundColor('#661D1D1F')
      .borderRadius(19)
      .borderWidth(1)
      .borderColor('#18FFFFFF')
      .onClick((_event: ClickEvent, result: SaveButtonOnClickResult) => {
        console.info(`[VideoPlayerPage] download SaveButton clicked result=${result}, type=${this.currentMediaType}, fileId=${this.fileId}`);
        if (result !== SaveButtonOnClickResult.SUCCESS) {
          console.warn(`[VideoPlayerPage] SaveButton authorization failed result=${result}`);
          this.statusText = '保存授权失败';
          this.showControlsTemporarily();
          return;
        }
        this.saveCurrentMediaToGallery();
        this.showControlsTemporarily();
      })
  }


  // ==============================================
  // 4. 【核心】关闭视频 + 暂停 TDLib 下载
  // ==============================================
  private stopVideoAndPauseDownload(): void {
    if (this.cleanupStarted) {
      return;
    }
    this.cleanupStarted = true;
    this.playbackStopped = true;
    this.pathRetryToken += 1;
    this.sequentialDownloadStarted = false;
    console.info(`[VideoPlayerPage] cleanup video and cancel download fileId=${this.fileId}`);
    this.pendingSave = false;
    this.releasePlayer();
    if (this.fileId !== 0) {
      this.td.stopVideoProxy(this.fileId);
    }
    if (this.fileId !== 0 && !this.videoCompleted) {
      if (!this.cacheController.isCaching(this.fileId)) {
        this.td.cancelDownloadFile(this.fileId);
      }
    }
  }

  @Builder
  private VideoTopBar() {
    Row() {
      this.CircleIconButton($r('app.media.back'), 40, 22, () => {
        console.info('[VideoPlayerPage] back clicked');
        this.stopVideoAndPauseDownload();
        router.back();
      })
      Blank()
      Column() {
        Text(this.title)
          .fontSize(10)
          .fontWeight(FontWeight.Bold)
          .fontColor(Color.White)
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
          .textAlign(TextAlign.Center)
          .width('100%')
        Text(this.subtitle.length > 0 ? this.subtitle : this.getProgressText())
          .fontSize(12)
          .fontColor('#A8A8A8')
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
          .textAlign(TextAlign.Center)
          .width('100%')
          .margin({ top: 1 })
      }
      .width('40%')
      .height(44)
      .justifyContent(FlexAlign.Center)
      .padding({ left: 14, right: 14 })
      .borderRadius(22)
      .backgroundColor('#661D1D1F')
      .border({ width: 1, color: '#18FFFFFF' })
      Blank()
      this.CircleIconButton($r('app.media.sandian'), 40, 22, () => {
        this.showMenu = !this.showMenu;
        this.showControlsTemporarily();
      })
    }
    .width('100%')
    .padding({ left: 22, right: 22, top: AppLayout.STATUS_BAR_HEIGHT })
  }

  @Builder
  private CenterControls() {
    Row({ space: 34 }) {
      this.CircleIconButton($r('app.media.kuaitui15s'), 54, 33, () => {
        this.seekBy(-15000);
        this.showControlsTemporarily();
      })
      this.CircleIconButton(this.isPlaying ? $r('app.media.tingzhi') : $r('app.media.playfill'), 78, 44, () => {
        this.handlePrimaryPlaybackClick();
        this.showControlsTemporarily();
      })
      this.CircleIconButton($r('app.media.kuaijin15s'), 54, 33, () => {
        this.seekBy(15000);
        this.showControlsTemporarily();
      })
    }
    .justifyContent(FlexAlign.Center)
    .alignItems(VerticalAlign.Center)
    .width('100%')
    .animation({ duration: 180, curve: Curve.EaseOut })
  }

  @Builder
  private BottomControls() {
    Column({ space: 10 }) {
      Text(this.description.length > 0 ? this.description : this.title)
        .fontSize(13)
        .fontColor(Color.White)
        .maxLines(2)
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .width('100%')
      Column({ space: 5 }) {
        Row({ space: 8 }) {
          Text(this.formatTime(this.currentTimeMs))
            .fontSize(11)
            .fontColor(Color.White)
          Stack({ alignContent: Alignment.Start }) {
            Progress({
              value: this.getBufferedDurationMs(),
              total: this.durationMs > 0 ? this.durationMs : 1,
              type: ProgressType.Linear
            })
              .width('100%')
              .height(4)
              .color('#66FFFFFF')
              .backgroundColor('#33FFFFFF')
            Slider({
              value: this.currentTimeMs,
              min: 0,
              max: this.durationMs > 0 ? this.durationMs : 1
            })
              .width('100%')
              .height(24)
              .onChange((value: number) => {
                this.seekTo(value);
                this.showControlsTemporarily();
              })
          }
            .layoutWeight(1)
          Text(this.durationMs > 0 ? this.formatTime(this.durationMs) : '--:--')
            .fontSize(11)
            .fontColor(Color.White)
        }
        .width('100%')
        Text(this.getCacheProgressText())
          .fontSize(11)
          .fontColor('#C8FFFFFF')
          .textAlign(TextAlign.Center)
          .width('100%')
      }
      .padding({ left: 12, right: 12, top: 7, bottom: 9 })
      .borderRadius(17)
      .backgroundColor('#661D1D1F')
      .border({ width: 1, color: '#18FFFFFF' })
      Row() {
        this.CircleIconButton($r('app.media.fenxiang'), 38, 22, () => {
          this.shareVideo();
          this.showControlsTemporarily();
        })
        Row() {
          this.DownloadSaveButton()
        }
        .margin({ left: 12 })
        Blank()
        Row({ space: 14 }) {
          this.TransparentIconButton($r('app.media.xiaochuang'), 34, 20, () => {
            this.startPictureInPicture();
            this.showControlsTemporarily();
          })
          this.TransparentIconButton($r('app.media.shezhi'), 34, 20, () => {
            this.showMenu = !this.showMenu;
            this.showControlsTemporarily();
          })
          this.TransparentIconButton($r('app.media.quanping'), 34, 20, () => {
            this.toggleFullScreen();
          })
        }
        .height(40)
        .padding({ left: 6, right: 6 })
        .borderRadius(20)
        .backgroundColor('#661D1D1F')
        .border({ width: 1, color: '#18FFFFFF' })
      }
      .width('100%')
    }
    .width('100%')
    .padding({ left: 32, right: 32, bottom: AppLayout.BOTTOM_SAFE_HEIGHT })
  }

  @Builder
  private MediaThumbBar() {
    if (this.mediaItems.length > 1) {
      Column({ space: 6 }) {
        Text(`${this.mediaIndex + 1}/${this.mediaItems.length}`)
          .fontSize(12)
          .fontColor('#DDFFFFFF')
          .padding({ left: 10, right: 10, top: 3, bottom: 3 })
          .borderRadius(11)
          .backgroundColor('#66000000')

        Scroll() {
          Row({ space: 8 }) {
            ForEach(this.mediaItems, (item: MediaPreviewItem, index: number) => {
              this.MediaThumb(item, index)
            }, (item: MediaPreviewItem): string => `thumb-${item.id}`)
          }
          .padding({ left: 16, right: 16 })
        }
        .width('100%')
        .height(66)
        .scrollable(ScrollDirection.Horizontal)
        .scrollBar(BarState.Off)
      }
      .width('100%')
      .padding({ bottom: AppLayout.BOTTOM_SAFE_HEIGHT + 6 })
      .backgroundColor('#33000000')
    }
  }

  @Builder
  private MediaThumb(item: MediaPreviewItem, index: number) {
    Stack({ alignContent: Alignment.Center }) {
      if (item.previewPath.length > 0) {
        Image(item.previewPath)
          .width(56)
          .height(56)
          .objectFit(ImageFit.Cover)
      } else if (item.displayPath.length > 0) {
        Image(item.displayPath)
          .width(56)
          .height(56)
          .objectFit(ImageFit.Cover)
      } else {
        Column()
          .width(56)
          .height(56)
          .backgroundColor('#44FFFFFF')
      }

      if (item.type === 'video' || item.type === 'animation') {
        Image($r('app.media.playfill'))
          .width(24)
          .height(24)
          .objectFit(ImageFit.Contain)
          .fillColor(Color.White)
          .borderRadius(12)
          .backgroundColor('#66000000')
      }
    }
    .width(60)
    .height(60)
    .borderRadius(5)
    .clip(true)
    .border({
      width: this.mediaIndex === index ? 2 : 0,
      color: '#FFFFFFFF'
    })
    .opacity(this.mediaIndex === index ? 1 : 0.62)
    .onClick(() => {
      this.setMediaIndexFromThumb(index);
    })
  }

  private saveVideoToGallery(): void {
    this.showMenu = false;
    this.videoCompleted = this.isVideoCacheComplete(this.videoPath, this.downloadedSize, this.expectedSize);
    console.info(`[VideoPlayerPage] saveVideoToGallery path=${this.videoPath}, completed=${this.videoCompleted}, downloaded=${this.downloadedSize}, expected=${this.expectedSize}`);
    if (this.videoPath.length === 0 || !this.videoCompleted) {
      this.pendingSave = true;
      this.statusText = '缓存完成后保存到图库';
      console.info(`[VideoPlayerPage] save pending fileId=${this.fileId}`);
      this.cacheController.start({
        fileId: this.fileId,
        messageId: this.messageId,
        chatId: this.chatId,
        type: this.currentMediaType === 'animation' ? 'animation' : 'video',
        title: this.title,
        fileName: this.description.length > 0 ? this.description : this.title,
        path: this.videoPath,
        downloadedSize: this.downloadedSize,
        expectedSize: this.expectedSize,
        duration: Math.floor(this.durationMs / 1000),
        videoWidth: this.videoWidth,
        videoHeight: this.videoHeight
      }, getContext(this) as common.UIAbilityContext);
      return;
    }
    this.pendingSave = false;
    this.saving = false;
    this.performSaveVideo();
  }

  private saveCurrentMediaToGallery(): void {
    if (this.currentMediaType === 'photo') {
      this.saveImageToGallery();
      return;
    }
    this.saveVideoToGallery();
  }

  private saveImageToGallery(): void {
    const sourcePath = this.videoPath.length > 0 ? this.videoPath : this.previewUri;
    if (sourcePath.length === 0) {
      this.statusText = '图片还未加载完成';
      return;
    }
    this.saving = true;
    const context = getContext(this) as common.UIAbilityContext;
    GalleryService.saveImage(context, sourcePath).then(() => {
      this.saving = false;
      this.statusText = '图片已保存到图库';
      this.showToast('图片已保存到图库');
    }).catch((err: OperationError) => {
      this.saving = false;
      console.error(`[VideoPlayerPage] save image failed code=${err.code}, message=${err.message}`);
      this.statusText = '保存图片失败';
      this.showToast('保存图片失败');
    });
  }

  private performSaveVideo(): void {
    console.info(`[VideoPlayerPage] performSaveVideo enter saving=${this.saving}, path=${this.videoPath}`);
    if (this.saving || this.videoPath.length === 0) {
      console.info(`[VideoPlayerPage] skip performSaveVideo saving=${this.saving}, path=${this.videoPath}`);
      return;
    }
    this.saving = true;
    this.pendingSave = false;
    const context = getContext(this) as common.UIAbilityContext;
    console.info(`[VideoPlayerPage] call saveVideoToGalleryAsset path=${this.videoPath}`);
    this.saveVideoToGalleryAsset(context, this.videoPath).then(() => {
      this.saving = false;
      this.statusText = '视频已保存到图库';
      this.showToast('视频已保存到图库');
      console.info(`[VideoPlayerPage] save video success path=${this.videoPath}`);
    }).catch((err: OperationError) => {
      this.saving = false;
      console.error(`[VideoPlayerPage] save video failed code=${err.code}, message=${err.message}`);
      this.statusText = '保存视频失败';
      this.showToast('保存视频失败');
    });
  }

  private showToast(message: string): void {
    promptAction.showToast({
      message: message,
      duration: 2000
    });
  }

  private async saveVideoToGalleryAsset(context: common.UIAbilityContext, sourcePath: string): Promise<void> {
    console.info(`[VideoPlayerPage][save] start source=${sourcePath}`);
    const sourceLocalPath = this.toLocalFilePath(sourcePath);
    const extension = this.getPathExtension(sourceLocalPath, 'mp4');
    const title = this.getPathTitle(sourceLocalPath, `video_${Date.now()}`);
    const helper = photoAccessHelper.getPhotoAccessHelper(context);
    console.info(`[VideoPlayerPage][save] createAsset extension=${extension}, title=${title}, sourceLocalPath=${sourceLocalPath}`);
    const assetUri = await helper.createAsset(photoAccessHelper.PhotoType.VIDEO, extension, { title: title });
    console.info(`[VideoPlayerPage][save] created asset uri=${assetUri}`);
    let sourceFile: fileIo.File | null = null;
    let targetFile: fileIo.File | null = null;
    try {
      console.info('[VideoPlayerPage][save] open source');
      sourceFile = fileIo.openSync(sourceLocalPath, fileIo.OpenMode.READ_ONLY);
      console.info('[VideoPlayerPage][save] open target');
      targetFile = fileIo.openSync(assetUri, fileIo.OpenMode.WRITE_ONLY);
      console.info(`[VideoPlayerPage][save] copy sourceFd=${sourceFile.fd}, targetFd=${targetFile.fd}`);
      fileIo.copyFileSync(sourceFile.fd, targetFile.fd);
      console.info('[VideoPlayerPage][save] copy finished');
    } finally {
      if (sourceFile !== null) {
        fileIo.closeSync(sourceFile);
      }
      if (targetFile !== null) {
        fileIo.closeSync(targetFile);
      }
      console.info('[VideoPlayerPage][save] close files finished');
    }
  }

  private getPathExtension(path: string, fallback: string): string {
    const queryIndex = path.indexOf('?');
    const cleanPath = queryIndex >= 0 ? path.substring(0, queryIndex) : path;
    const dotIndex = cleanPath.lastIndexOf('.');
    if (dotIndex < 0 || dotIndex === cleanPath.length - 1) {
      return fallback;
    }
    return cleanPath.substring(dotIndex + 1).toLowerCase();
  }

  private getPathTitle(path: string, fallback: string): string {
    const queryIndex = path.indexOf('?');
    const cleanPath = queryIndex >= 0 ? path.substring(0, queryIndex) : path;
    const slashIndex = cleanPath.lastIndexOf('/');
    const fileName = slashIndex >= 0 ? cleanPath.substring(slashIndex + 1) : cleanPath;
    const dotIndex = fileName.lastIndexOf('.');
    const title = dotIndex > 0 ? fileName.substring(0, dotIndex) : fileName;
    return title.length > 0 ? title : fallback;
  }

  @Builder
  private MediaPage(item: MediaPreviewItem, index: number) {
    Stack({ alignContent: Alignment.Center }) {
      if (item.type === 'photo') {
        Image(item.displayPath.length > 0 ? item.displayPath : item.previewPath)
          .width('100%')
          .height('100%')
          .objectFit(ImageFit.Contain)
          .gesture(
            LongPressGesture().onAction(() => {
              this.saveImageToGallery();
              this.showControlsTemporarily();
            })
          )
          .onClick(() => {
            this.toggleControlsFromSurface();
          })
      } else if (index === this.mediaIndex) {
        if (this.previewUri.length > 0 && !this.playerReady) {
          Image(this.previewUri)
            .width('100%')
            .height('100%')
            .objectFit(ImageFit.Contain)
        }
        XComponent({
          id: 'tg_video_player_surface',
          type: XComponentType.SURFACE,
          controller: this.xComponentController
        })
          .width(this.getVideoSurfaceWidth())
          .height(this.getVideoSurfaceHeight())
          .onLoad(() => {
            this.onSurfaceLoaded();
          })
          .onDestroy(() => {
            this.onSurfaceDestroyed();
          })
          .gesture(
            LongPressGesture().onAction(() => {
              this.togglePlaybackRate();
            })
          )
          .onClick(() => {
            this.toggleControlsFromSurface();
          })
        if (!this.playerReady && this.previewUri.length === 0) {
          Text('正在加载视频')
            .fontSize(18)
            .fontColor(Color.White)
        }
      } else if (item.previewPath.length > 0) {
        Image(item.previewPath)
          .width('100%')
          .height('100%')
          .objectFit(ImageFit.Contain)
      } else {
        Text('视频预览加载中')
          .fontSize(18)
          .fontColor(Color.White)
      }
    }
    .width('100%')
    .height('100%')
  }

  @Builder
  private StatusToastOverlay() {
    if (this.statusText.length > 0) {
      Row() {
        Text(this.statusText)
          .fontSize(13)
          .fontColor(Color.White)
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
      }
      .constraintSize({ maxWidth: '78%' })
      .height(34)
      .padding({ left: 14, right: 14 })
      .borderRadius(17)
      .backgroundColor('#99000000')
      .backdropBlur(12)
      .position({ x: '11%', y: this.viewportHeight > 0 ? this.viewportHeight - AppLayout.BOTTOM_SAFE_HEIGHT - 128 : '78%' })
    }
  }

  build() {
    Stack() {
      if (this.mediaItems.length > 0) {
        Swiper(this.mediaSwiperController) {
          ForEach(this.mediaItems, (item: MediaPreviewItem, index: number) => {
            this.MediaPage(item, index)
          }, (item: MediaPreviewItem): string => item.id)
        }
        .width('100%')
        .height('100%')
        .index(this.mediaIndex)
        .indicator(false)
        .loop(false)
        .duration(220)
        .onChange((index: number) => {
          this.applyMediaItem(index, true);
        })
      } else {
        this.MediaPage({
          id: `video-${this.messageId}`,
          type: 'video',
          messageId: this.messageId,
          fileId: this.fileId,
          displayPath: this.videoPath,
          previewPath: this.previewUri,
          title: this.title,
          subtitle: this.subtitle,
          description: this.description,
          fileSize: this.expectedSize,
          downloadedSize: this.downloadedSize,
          duration: Math.floor(this.durationMs / 1000),
          mediaWidth: this.videoWidth,
          mediaHeight: this.videoHeight
        }, 0)
      }

      Column() {
        if (this.showControls) {
          this.VideoTopBar()
        }
        if (this.showMenu) {
          Row() {
            Blank()
            Column() {
              SaveButton()
                .onClick((_event: ClickEvent, result: SaveButtonOnClickResult) => {
                  console.info(`[VideoPlayerPage] SaveButton clicked result=${result}`);
                  if (result !== SaveButtonOnClickResult.SUCCESS) {
                    console.warn(`[VideoPlayerPage] menu SaveButton authorization failed result=${result}`);
                    this.statusText = '保存授权失败';
                    return;
                  }
                  this.saveCurrentMediaToGallery();
                })
            }
            .padding(7)
            .backgroundColor('#661D1D1F')
            .backdropBlur(12)
            .borderRadius(8)
            .margin({ right: 24 })
          }
          .width('100%')
        }
        Blank()
        if (this.showControls && this.isCurrentVideo()) {
          this.BottomControls()
        }
        this.MediaThumbBar()
      }
      .width('100%')
      .height('100%')
      .hitTestBehavior(HitTestMode.Transparent)

      if (!this.showControls && !this.showMenu && !this.showPlaybackInfo) {
        Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#01000000')
          .onClick(() => {
            this.showControlsTemporarily();
          })
      }

      if (this.showControls && this.isCurrentVideo()) {
        this.CenterControls()
      }

      if (this.showPlaybackInfo) {
        this.PlaybackInfoDialog()
      }

      this.StatusToastOverlay()
    }
    .width('100%')
    .height('100%')
    .backgroundColor(Color.Black)
  }
}
