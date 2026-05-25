// entry/src/main/ets/pages/VideoPlayerPage.ets
import { GalleryService } from '../common/service/GalleryService';
import { TdFile, TdUpdate, TdlibService } from '../common/service/TdlibService';
import { common, Want, wantConstant } from '@kit.AbilityKit';
import { fileIo } from '@kit.CoreFileKit';
import { PiPWindow, window } from '@kit.ArkUI';
import { media } from '@kit.MediaKit';
import router from '@ohos.router';
import { AppLayout } from '../common/constants/AppLayout';

interface VideoRouteParams {
  chatId?: number | string;
  messageId?: number | string;
  fileId?: number | string;
  videoPath?: string;
  previewUri?: string;
  title?: string;
  subtitle?: string;
  description?: string;
  fileSize?: number | string;
  downloadedSize?: number | string;
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
  private td = TdlibService.getInstance();
  private listenersRegistered: boolean = false;
  private xComponentController: XComponentController = new XComponentController();
  private surfaceId: string = '';
  private player: media.AVPlayer | null = null;
  private creatingPlayer: boolean = false;
  private prepareStarted: boolean = false;
  private preparingSource: string = '';
  private streamFile: fileIo.File | null = null;
  private streamPath: string = '';
  private lastRequestedOffset: number = -1;
  private mainWindow: window.Window | null = null;
  private previousSystemBarProperties: window.SystemBarProperties | null = null;
  private previousPreferredOrientation: window.Orientation | null = null;
  private pipController: PiPWindow.PiPController | null = null;
  private cleanupStarted: boolean = false;
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
    this.applyVideoSystemBars();
    this.registerListeners();
    if (this.fileId !== 0) {
      console.error(`[VideoPlayerPage] start cache fileId=${this.fileId}, messageId=${this.messageId}`);
      this.statusText = '正在缓存视频...';
      if (this.chatId !== 0 && this.messageId !== 0) {
        this.td.openMessageContent(this.chatId, this.messageId);
      }
      this.startSequentialVideoDownload();
      this.scheduleLocalPathRetry();
    } else {
      this.statusText = '视频参数错误';
      console.error('[VideoPlayerPage] fileId is invalid');
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
    const params = router.getParams() as VideoRouteParams;
    if (params && params.chatId !== undefined) {
      this.chatId = Number(params.chatId);
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
    if (params && params.duration !== undefined) {
      this.durationMs = Number(params.duration) * 1000;
    }
    if (params && params.videoWidth !== undefined) {
      this.videoWidth = Number(params.videoWidth);
    }
    if (params && params.videoHeight !== undefined) {
      this.videoHeight = Number(params.videoHeight);
    }
    console.info(`[VideoPlayerPage] params chatId=${this.chatId}, messageId=${this.messageId}, fileId=${this.fileId}, path=${this.videoPath}`);
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
    if (file.id !== this.fileId) {
      return;
    }
    if (file.local && file.local.path.length > 0) {
      this.videoLocalPath = this.toLocalFilePath(file.local.path);
      this.videoPath = this.toFileSource(this.videoLocalPath);
    }
    this.videoCompleted = file.local ? file.local.is_downloading_completed === true : false;
    this.downloadedPrefixSize = Math.max(this.downloadedPrefixSize, this.getDownloadedPrefixSize(file));
    const nextDownloadedSize = this.getDownloadedSize(file);
    this.downloadedSize = Math.max(this.downloadedSize, nextDownloadedSize);
    this.expectedSize = Math.max(this.expectedSize, this.getExpectedSize(file));
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
    if (!this.surfaceReady || this.fileId === 0 || this.videoLocalPath.length === 0) {
      return;
    }
    if (!this.isFilesystemPath(this.videoLocalPath)) {
      this.statusText = '视频本地路径不可读';
      console.error(`[VideoPlayerPage] invalid local path=${this.videoLocalPath}`);
      return;
    }
    const proxyUrl = this.td.startVideoProxy(this.fileId, this.videoLocalPath,
      this.expectedSize > 0 ? this.expectedSize : this.downloadedSize,
      this.downloadedPrefixSize, this.downloadedSize, this.videoCompleted);
    if (this.player !== null && this.preparingSource === proxyUrl) {
      return;
    }
    this.createAndPreparePlayer(proxyUrl);
  }

  private createAndPreparePlayer(proxyUrl: string): void {
    if (this.creatingPlayer) {
      return;
    }
    this.creatingPlayer = true;
    const source = proxyUrl;
    this.statusText = '正在打开视频流...';
    this.releasePlayer(false);
    media.createAVPlayer().then((player: media.AVPlayer) => {
      this.player = player;
      this.preparingSource = source;
      this.prepareStarted = false;
      this.bindPlayerEvents(player);
      this.playbackProtocol = 'TDLib downloadFile + local HTTP Range proxy';
      console.error(`[VideoPlayerPage] AVPlayer use proxy url=${source}, localPath=${this.videoLocalPath}, prefix=${this.downloadedPrefixSize}, downloaded=${this.downloadedSize}, expected=${this.expectedSize}`);
      player.url = source;
    }).catch((err: OperationError) => {
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

  private prepareInitializedPlayer(player: media.AVPlayer): void {
    if (player !== this.player || this.prepareStarted) {
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
    if (player !== this.player) {
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
      this.isPlaying = true;
      this.scheduleHideControls();
    }).catch((err: OperationError) => {
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
    if (this.fileId === 0 || this.videoCompleted) {
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
    if (this.fileId === 0 || this.videoCompleted) {
      return;
    }
    console.error(`[VideoPlayerPage] start sequential download fileId=${this.fileId}, path=${this.videoLocalPath}, prefix=${this.downloadedPrefixSize}, downloaded=${this.downloadedSize}`);
    this.sequentialDownloadStarted = true;
    this.td.downloadFile(this.fileId, 32, 0, 0);
  }

  private scheduleLocalPathRetry(): void {
    const token = ++this.pathRetryToken;
    setTimeout(() => {
      if (token !== this.pathRetryToken || this.videoCompleted || this.videoLocalPath.length > 0) {
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
      if (player !== this.player) {
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
      if (player !== this.player) {
        return;
      }
      this.currentTimeMs = timeMs;
      if (player.duration > 0) {
        this.durationMs = player.duration;
      }
    });
    player.on('durationUpdate', (durationMs: number) => {
      if (player !== this.player) {
        return;
      }
      this.durationMs = durationMs;
    });
    player.on('seekDone', (seekDoneTimeMs: number) => {
      if (player !== this.player) {
        return;
      }
      console.error(`[VideoPlayerPage] AVPlayer seekDone time=${seekDoneTimeMs}, queued=${this.queuedSeekMs}`);
      this.seekInProgress = false;
      this.currentTimeMs = seekDoneTimeMs;
      this.executeQueuedSeek();
    });
    player.on('error', (err: BusinessError) => {
      if (player !== this.player) {
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


  // ==============================================
  // 4. 【核心】关闭视频 + 暂停 TDLib 下载
  // ==============================================
  private stopVideoAndPauseDownload(): void {
    if (this.cleanupStarted) {
      return;
    }
    this.cleanupStarted = true;
    console.info(`[VideoPlayerPage] cleanup video and cancel download fileId=${this.fileId}`);
    this.releasePlayer();
    if (this.fileId !== 0) {
      this.td.stopVideoProxy(this.fileId);
    }
    if (this.fileId !== 0 && !this.videoCompleted && !this.pendingSave) {
      this.td.cancelDownloadFile(this.fileId);
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
        Text(this.getFileSizeText())
          .fontSize(12)
          .fontWeight(FontWeight.Bold)
          .fontColor(Color.White)
          .textAlign(TextAlign.Center)
          .width('100%')
        Row({ space: 8 }) {
          Text(this.formatTime(this.currentTimeMs))
            .fontSize(11)
            .fontColor(Color.White)
          Slider({
            value: this.currentTimeMs,
            min: 0,
            max: this.durationMs > 0 ? this.durationMs : 1
          })
            .layoutWeight(1)
            .onChange((value: number) => {
              this.seekTo(value);
              this.showControlsTemporarily();
            })
          Text(this.durationMs > 0 ? this.formatTime(this.durationMs) : '--:--')
            .fontSize(11)
            .fontColor(Color.White)
        }
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

  private saveVideoToGallery(): void {
    this.showMenu = false;
    if (this.videoPath.length === 0 || !this.videoCompleted) {
      this.pendingSave = true;
      this.statusText = '缓存完成后保存到图库';
      console.info(`[VideoPlayerPage] save pending fileId=${this.fileId}`);
      this.td.downloadFile(this.fileId, 32);
      return;
    }
    this.pendingSave = true;
    this.performSaveVideo();
  }

  private performSaveVideo(): void {
    if (this.saving || this.videoPath.length === 0) {
      return;
    }
    this.saving = true;
    this.pendingSave = false;
    const context = getContext(this) as common.UIAbilityContext;
    GalleryService.saveVideo(context, this.videoPath).then(() => {
      this.saving = false;
      this.statusText = '视频已保存到图库';
    }).catch((err: OperationError) => {
      this.saving = false;
      console.error(`[VideoPlayerPage] save video failed code=${err.code}, message=${err.message}`);
      this.statusText = '保存视频失败';
    });
  }

  build() {
    Stack() {
      Stack({ alignContent: Alignment.Center }) {
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
      }
      .width('100%')
      .height('100%')

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
                  if (result === SaveButtonOnClickResult.SUCCESS) {
                    this.saveVideoToGallery();
                  } else {
                    this.statusText = '保存授权失败';
                  }
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
        if (this.showControls) {
          this.BottomControls()
        }
      }
      .width('100%')
      .height('100%')
      .hitTestBehavior(this.showControls || this.showMenu ? HitTestMode.Default : HitTestMode.Transparent)

      if (!this.showControls && !this.showMenu && !this.showPlaybackInfo) {
        Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#01000000')
          .onClick(() => {
            this.showControlsTemporarily();
          })
      }

      if (this.showControls) {
        this.CenterControls()
      }

      if (this.showPlaybackInfo) {
        this.PlaybackInfoDialog()
      }
    }
    .width('100%')
    .height('100%')
    .backgroundColor(Color.Black)
  }
}
