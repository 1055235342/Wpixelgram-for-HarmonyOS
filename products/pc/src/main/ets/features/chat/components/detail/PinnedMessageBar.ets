@Component
export struct PinnedMessageBar {
  @Prop text: string = '';
  onOpen: () => void = (): void => {};

  build() {
    if (this.text.length > 0) {
      Row({ space: 8 }) {
        Column()
          .width(2)
          .height(34)
          .borderRadius(1)
          .backgroundColor('#6B7A6D')
          .margin({ left: 8 })
        Column() {
          Text('置顶消息')
            .fontSize(12)
            .fontWeight(FontWeight.Bold)
            .fontColor('#111111')
            .maxLines(1)
          Text(this.text)
            .fontSize(12)
            .fontColor('#111111')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
        }
        .layoutWeight(1)
        .alignItems(HorizontalAlign.Start)
        Text('☰')
          .fontSize(20)
          .fontColor('#162026')
          .width(28)
          .textAlign(TextAlign.Center)
      }
      .height(44)
      .width('100%')
      .padding({ left: 6, right: 10 })
      .onClick(() => {
        this.onOpen();
      })
    }
  }
}
