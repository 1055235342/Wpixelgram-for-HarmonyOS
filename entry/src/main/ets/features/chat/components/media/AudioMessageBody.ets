import { createEmptyMessageItem, MessageItem } from '../../model/ChatDetailModels';

@Component
export struct AudioMessageBody {
  @Prop msg: MessageItem = createEmptyMessageItem();
  @Prop downloadPercent: number = 0;
  @Prop progressText: string = '';
  @Prop topicText: string = '';
  @Prop isPlaying: boolean = false;
  onToggle: (msg: MessageItem) => void = (msg: MessageItem): void => {};
  onDownload: (fileId: number) => void = (fileId: number): void => {};

  build() {
    Column() {
      Row({ space: 9 }) {
        Stack({ alignContent: Alignment.Center }) {
          Circle()
            .width(64)
            .height(64)
            .fill(Color.Transparent)
            .stroke('#DDE8EE')
            .strokeWidth(3)
          Progress({ value: this.downloadPercent, total: 100, type: ProgressType.Ring })
            .width(64)
            .height(64)
            .color('#0A84FF')

          if (this.msg.thumbnailPath.length > 0) {
            Image(this.msg.thumbnailPath)
              .width(54)
              .height(54)
              .objectFit(ImageFit.Cover)
              .borderRadius(27)
          } else {
            Column()
              .width(54)
              .height(54)
              .borderRadius(27)
              .linearGradient({
                direction: GradientDirection.Bottom,
                colors: [['#69C7FF', 0], ['#7E66F2', 1]]
              })
          }

          Button({ type: ButtonType.Circle }) {
            Image(this.isPlaying ? $r('app.media.tingzhi') : $r('app.media.playfill'))
              .width(18)
              .height(18)
              .objectFit(ImageFit.Contain)
          }
          .width(30)
          .height(30)
          .backgroundColor('#AA000000')
          .onClick(() => {
            this.onToggle(this.msg);
          })

          Button({ type: ButtonType.Circle }) {
            Image($r('app.media.download'))
              .width(12)
              .height(12)
              .objectFit(ImageFit.Contain)
              .fillColor(Color.White)
          }
          .width(20)
          .height(20)
          .backgroundColor('#CC0A84FF')
          .position({ x: 42, y: 42 })
          .onClick(() => {
            this.onDownload(this.msg.audioFileId);
          })
        }
        .width(64)
        .height(64)

        Column() {
          Text(this.msg.audioTitle)
            .fontSize(14)
            .fontWeight(FontWeight.Bold)
            .fontColor('#111111')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
          Text(this.msg.audioPerformer)
            .fontSize(11)
            .fontColor('#6D7480')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
            .margin({ top: 4 })
          Text(this.progressText)
            .fontSize(11)
            .fontColor('#8A96A8')
            .margin({ top: 5 })
        }
        .layoutWeight(1)
        .alignItems(HorizontalAlign.Start)
      }
      .width('100%')

      Text(this.msg.audioTitle)
        .fontSize(13)
        .fontWeight(FontWeight.Medium)
        .fontColor('#111111')
        .maxLines(1)
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .margin({ top: 8 })
      Text(this.topicText)
        .fontSize(12)
        .fontColor('#0A66CC')
        .maxLines(2)
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .margin({ top: 2 })
    }
    .width(270)
    .alignItems(HorizontalAlign.Start)
  }
}
