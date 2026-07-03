import { ReplyKeyboardButtonItem } from '../../model/ChatDetailModels';

@Component
export struct ReplyKeyboardPanelView {
  @Prop rows: ReplyKeyboardButtonItem[][] = [];
  onButtonClick: (button: ReplyKeyboardButtonItem) => void =
    (button: ReplyKeyboardButtonItem): void => {};

  build() {
    Column({ space: 6 }) {
      ForEach(this.rows, (row: ReplyKeyboardButtonItem[]) => {
        Row({ space: 6 }) {
          ForEach(row, (button: ReplyKeyboardButtonItem) => {
            Button(button.text)
              .fontSize(12)
              .fontColor('#111111')
              .fontWeight(FontWeight.Medium)
              .height(32)
              .padding({ left: 8, right: 8 })
              .layoutWeight(1)
              .borderRadius(8)
              .backgroundColor('#EFFFFFFF')
              .shadow({ radius: 6, color: '#12000000', offsetY: 2 })
              .onClick(() => {
                this.onButtonClick(button);
              })
          }, (button: ReplyKeyboardButtonItem): string => button.id)
        }
        .width('100%')
      }, (row: ReplyKeyboardButtonItem[]): string => row.map((button: ReplyKeyboardButtonItem): string => button.id).join('|'))
    }
    .width('100%')
    .padding({ top: 8 })
  }
}
