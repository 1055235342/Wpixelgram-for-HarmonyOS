import { createEmptyMessageItem, MessageItem } from '../../model/ChatDetailModels';

@Component
export struct DocumentMessageBody {
  @Prop msg: MessageItem = createEmptyMessageItem();
  @Prop sizeText: string = '';
  onDownload: (fileId: number) => void = (fileId: number): void => {};

  build() {
    Row({ space: 10 }) {
      Button({ type: ButtonType.Circle }) {
        Image($r('app.media.download'))
          .width(20)
          .height(20)
          .objectFit(ImageFit.Contain)
          .fillColor(Color.White)
      }
      .width(42)
      .height(42)
      .borderRadius(21)
      .backgroundColor('#0A84FF')
      .onClick(() => {
        this.onDownload(this.msg.documentFileId);
      })

      Column() {
        Text(this.msg.documentFileName.length > 0 ? this.msg.documentFileName : '未命名文件')
          .fontSize(14)
          .fontWeight(FontWeight.Medium)
          .fontColor('#111111')
          .maxLines(2)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
        Text(`${this.sizeText} · ${this.msg.mediaFormat.length > 0 ? this.msg.mediaFormat : 'file'}`)
          .fontSize(11)
          .fontColor('#6D7480')
          .margin({ top: 3 })
      }
      .alignItems(HorizontalAlign.Start)
      .constraintSize({ maxWidth: 210 })
    }
    .constraintSize({ maxWidth: 270 })
    .padding({ top: 4, bottom: 4 })
  }
}
