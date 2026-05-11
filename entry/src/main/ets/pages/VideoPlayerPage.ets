// entry/src/main/ets/pages/VideoPlayerPage.ets
import { GalleryService } from '../common/service/GalleryService';
import { TdFile, TdUpdate, TdlibService } from '../common/service/TdlibService';
import { common } from '@kit.AbilityKit';
import router from '@ohos.router';

interface VideoRouteParams {
  chatId?: number | string;
  messageId?: number | string;
  fileId?: number | string;
  videoPath?: string;
  previewUri?: string;
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
  @State statusText: string = '准备播放...';
  @State downloadedSize: number = 0;
  @State expectedSize: number = 0;
  @State playbackRate: number = 1;
  @State showMenu: boolean = false;
  @State videoCompleted: boolean = false;
  @State pendingSave: boolean = false;
  @State saving: boolean = false;
  private td = TdlibService.getInstance();
  private listenersRegistered: boolean = false;

  aboutToAppear() {
    this.readRouteParams();
    this.registerListeners();
    if (this.fileId !== 0) {
      console.info(`[VideoPlayerPage] start cache fileId=${this.fileId}, messageId=${this.messageId}`);
      this.statusText = '正在缓存视频...';
      if (this.chatId !== 0 && this.messageId !== 0) {
        this.td.openMessageContent(this.chatId, this.messageId);
      }
      this.td.downloadFile(this.fileId, 32);
    } else {
      this.statusText = '视频参数错误';
      console.error('[VideoPlayerPage] fileId is invalid');
    }
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
    }
    if (params && params.previewUri !== undefined) {
      this.previewUri = params.previewUri;
    }
    console.info(`[VideoPlayerPage] params chatId=${this.chatId}, messageId=${this.messageId}, fileId=${this.fileId}`);
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
      this.videoPath = this.toFileSource(file.local.path);
    }
    this.videoCompleted = file.local ? file.local.is_downloading_completed === true : false;
    this.downloadedSize = this.getDownloadedSize(file);
    this.expectedSize = this.getExpectedSize(file);
    this.statusText = this.videoPath.length > 0 && this.downloadedSize > 0 ? '' : '正在缓存视频...';
    console.info(`[VideoPlayerPage] file update fileId=${file.id}, path=${this.videoPath}, downloaded=${this.downloadedSize}, expected=${this.expectedSize}`);
    if (this.pendingSave && this.videoCompleted && this.videoPath.length > 0) {
      this.performSaveVideo();
    }
  }

  private getDownloadedSize(file: TdFile): number {
    if (!file.local) {
      return 0;
    }
    if (file.local.downloaded_prefix_size !== undefined && file.local.downloaded_prefix_size > 0) {
      return file.local.downloaded_prefix_size;
    }
    if (file.local.downloaded_size !== undefined) {
      return file.local.downloaded_size;
    }
    return 0;
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

  private togglePlaybackRate(): void {
    this.playbackRate = this.playbackRate === 2 ? 1 : 2;
    this.statusText = this.playbackRate === 2 ? '2倍速播放' : '';
    console.info(`[VideoPlayerPage] toggle playbackRate=${this.playbackRate}`);
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
      Column() {
        if (this.videoPath.length > 0 && this.downloadedSize > 0) {
          Video({
            src: this.videoPath,
            previewUri: this.previewUri.length > 0 ? this.previewUri : undefined,
            currentProgressRate: this.playbackRate
          })
            .width('100%')
            .height('100%')
            .autoPlay(true)
            .controls(true)
            .objectFit(ImageFit.Contain)
            .gesture(
              LongPressGesture().onAction(() => {
                this.togglePlaybackRate();
              })
            )
        } else if (this.previewUri.length > 0) {
          Image(this.previewUri)
            .width('100%')
            .height('100%')
            .objectFit(ImageFit.Contain)
        } else {
          Text('正在加载视频')
            .fontSize(18)
            .fontColor(Color.White)
        }
      }
      .width('100%')
      .height('100%')
      .justifyContent(FlexAlign.Center)

      Column() {
        Row() {
          Button('返回')
            .onClick(() => {
              console.info('[VideoPlayerPage] button 返回 clicked');
              router.back();
            })
          Blank()
          Button('...')
            .onClick(() => {
              this.showMenu = !this.showMenu;
            })
        }
        .width('100%')
        .padding(12)
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
            .padding(8)
            .backgroundColor('#222222')
            .borderRadius(8)
            .margin({ right: 12 })
          }
          .width('100%')
        }
        Blank()
        if (this.getProgressText().length > 0) {
          Text(this.getProgressText())
            .fontSize(14)
            .fontColor(Color.White)
            .padding(12)
        }
      }
      .width('100%')
      .height('100%')
    }
    .width('100%')
    .height('100%')
    .backgroundColor(Color.Black)
  }
}
