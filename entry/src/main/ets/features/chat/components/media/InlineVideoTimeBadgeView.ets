@Component
export struct InlineVideoTimeBadgeView {
  @Prop text: string = '';

  build() {
    Text(this.text)
      .fontSize(12)
      .fontWeight(FontWeight.Bold)
      .fontColor(Color.White)
      .height(24)
      .padding({ left: 9, right: 9 })
      .borderRadius(12)
      .backgroundColor('#66000000')
      .align(Alignment.TopStart)
      .margin({ left: 10, top: 10 })
  }
}
