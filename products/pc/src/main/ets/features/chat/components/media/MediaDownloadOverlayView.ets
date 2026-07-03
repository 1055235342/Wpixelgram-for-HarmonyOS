@Component
export struct MediaDownloadOverlayView {
  @Prop percent: number = 0;
  @Prop fileId: number = 0;
  @Prop text: string = '';
  onCancel: (fileId: number) => void = (fileId: number): void => {};

  build() {
    Stack({ alignContent: Alignment.Center }) {
      Circle()
        .width(52)
        .height(52)
        .fill('#44FFFFFF')
        .stroke('#55FFFFFF')
        .strokeWidth(1)
      Progress({ value: this.percent, total: 100, type: ProgressType.Ring })
        .width(52)
        .height(52)
        .color('#EFFFFFFF')
      Button({ type: ButtonType.Circle }) {
        Text('×')
          .fontSize(24)
          .fontColor(Color.White)
          .fontWeight(FontWeight.Medium)
          .textAlign(TextAlign.Center)
      }
      .width(38)
      .height(38)
      .borderRadius(19)
      .backgroundColor('#33000000')
      .onClick(() => {
        this.onCancel(this.fileId);
      })
      Text(this.text)
        .fontSize(this.percent > 0 ? 9 : 8)
        .fontColor(Color.White)
        .fontWeight(FontWeight.Medium)
        .textAlign(TextAlign.Center)
        .position({ x: 7, y: 42 })
    }
    .width(58)
    .height(58)
    .backgroundColor('#22FFFFFF')
    .borderRadius(29)
  }
}
