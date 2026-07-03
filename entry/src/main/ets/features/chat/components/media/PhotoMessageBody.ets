import { createEmptyMessageItem, MessageItem } from '../../model/ChatDetailModels';
import { MediaDownloadOverlayView } from './MediaDownloadOverlayView';

@Component
export struct PhotoMessageBody {
  @Prop msg: MessageItem = createEmptyMessageItem();
  @Prop displayPath: string = '';
  @Prop imageId: string = '';
  @Prop displayWidth: number = 0;
  @Prop displayHeight: number = 0;
  @Prop downloadPercent: number = 0;
  @Prop downloadText: string = '';
  onOpen: (msg: MessageItem) => void = (msg: MessageItem): void => {};
  onSave: (msg: MessageItem) => void = (msg: MessageItem): void => {};
  onCancel: (fileId: number) => void = (fileId: number): void => {};

  build() {
    Stack({ alignContent: Alignment.Center }) {
      if (this.displayPath.length > 0) {
        Image(this.displayPath)
          .id(this.imageId)
          .width(this.displayWidth)
          .height(this.displayHeight)
          .objectFit(ImageFit.Cover)
          .onClick(() => {
            this.onOpen(this.msg);
          })
          .gesture(
            LongPressGesture().onAction(() => {
              this.onSave(this.msg);
            })
          )
      } else {
        Column()
          .width(this.displayWidth)
          .height(this.displayHeight)
          .backgroundColor('#DCEEFF')
        MediaDownloadOverlayView({
          percent: this.downloadPercent,
          fileId: this.msg.photoFileId,
          text: this.downloadText,
          onCancel: (fileId: number): void => {
            this.onCancel(fileId);
          }
        })
      }
    }
    .width(this.displayWidth)
  }
}
