import { MessageButtonItem } from '../../model/ChatDetailModels';

@Component
export struct MessageButtonPanelView {
  @Prop messageId: number = 0;
  @Prop rows: MessageButtonItem[][] = [];
  onButtonClick: (messageId: number, button: MessageButtonItem) => void =
    (messageId: number, button: MessageButtonItem): void => {};

  build() {
    if (this.rows.length > 0) {
      Column() {
        ForEach(this.rows, (row: MessageButtonItem[]) => {
          Row() {
            ForEach(row, (button: MessageButtonItem) => {
              Button({ type: ButtonType.Normal }) {
                Text(button.text)
                  .fontSize(10)
                  .fontColor('#2C6FA3')
                  .textAlign(TextAlign.Center)
                  .maxLines(2)
                  .textOverflow({ overflow: TextOverflow.Ellipsis })
                  .width('100%')
              }
                .height(38)
                .padding({ left: 8, right: 8, top: 6, bottom: 6 })
                .borderRadius(7)
                .backgroundColor('#EEF7FF')
                .layoutWeight(1)
                .margin(2)
                .onClick(() => {
                  this.onButtonClick(this.messageId, button);
                })
            }, (button: MessageButtonItem): string => button.id)
          }
          .width(280)
        }, (row: MessageButtonItem[]): string => row.map((button: MessageButtonItem): string => button.id).join('|'))
      }
      .width(280)
      .alignItems(HorizontalAlign.Start)
      .margin({ top: 3 })
    }
  }
}
