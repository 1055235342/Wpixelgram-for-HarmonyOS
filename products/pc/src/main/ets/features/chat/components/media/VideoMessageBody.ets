import { createEmptyMessageItem, MessageItem } from '../../model/ChatDetailModels';
import { InlineVideoTimeBadgeView } from './InlineVideoTimeBadgeView';

@Component
export struct VideoMessageBody {
  @Prop msg: MessageItem = createEmptyMessageItem();
  @Prop mode: string = 'video';
  @Prop displayWidth: number = 0;
  @Prop displayHeight: number = 0;
  @Prop videoPath: string = '';
  @Prop previewPath: string = '';
  @Prop videoId: string = '';
  @Prop previewId: string = '';
  @Prop inlinePlayback: boolean = false;
  @Prop remainingText: string = '';
  onOpen: (msg: MessageItem) => void = (msg: MessageItem): void => {};
  onInlineUpdate: (messageId: number, duration: number, time: number) => void =
    (messageId: number, duration: number, time: number): void => {};

  private getPlaceholderText(): string {
    return this.mode === 'animation' ? 'GIF预览' : '视频预览';
  }

  build() {
    Stack({ alignContent: Alignment.Center }) {
      if (this.mode === 'video' && this.inlinePlayback && this.videoPath.length > 0) {
        Video({
          src: this.videoPath,
          previewUri: this.previewPath.length > 0 ? this.previewPath : undefined
        })
          .id(this.videoId)
          .width(this.displayWidth)
          .height(this.displayHeight)
          .autoPlay(true)
          .controls(false)
          .loop(true)
          .muted(true)
          .objectFit(ImageFit.Cover)
          .onUpdate((info: PlaybackInfo) => {
            this.onInlineUpdate(this.msg.id, this.msg.videoDuration, info.time);
          })
          .onClick(() => {
            this.onOpen(this.msg);
          })
      } else if (this.videoPath.length > 0 && this.mode === 'animation') {
        Image(this.videoPath)
          .width(this.displayWidth)
          .height(this.displayHeight)
          .objectFit(ImageFit.Cover)
      } else if (this.previewPath.length > 0) {
        Image(this.previewPath)
          .id(this.previewId)
          .width(this.displayWidth)
          .height(this.displayHeight)
          .objectFit(ImageFit.Cover)
      } else {
        Text(this.getPlaceholderText())
          .fontSize(16)
          .fontColor('#666666')
          .width(this.displayWidth)
          .height(this.displayHeight)
          .textAlign(TextAlign.Center)
          .backgroundColor('#E6F4FF')
      }
      if (this.mode === 'video' && !this.inlinePlayback) {
        Button('▶')
          .fontSize(22)
          .fontColor(Color.White)
          .width(38)
          .height(38)
          .borderRadius(19)
          .backgroundColor('#66000000')
          .onClick(() => {
            this.onOpen(this.msg);
          })
      }
      if (this.mode === 'video' && this.inlinePlayback) {
        InlineVideoTimeBadgeView({ text: this.remainingText })
      }
    }
    .width(this.displayWidth)
    .onClick(() => {
      if (this.mode === 'video') {
        this.onOpen(this.msg);
      }
    })
  }
}
