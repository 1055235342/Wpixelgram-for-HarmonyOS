@Component
export struct ReadOnlyConversationBar {
  @Prop barColor: ResourceColor = '#E6FFFFFF';

  build() {
    Row() {
      Text('当前会话不允许发送消息')
        .fontSize(14)
        .fontColor('#687275')
        .fontWeight(FontWeight.Medium)
        .textAlign(TextAlign.Center)
    }
    .width('100%')
    .height(48)
    .justifyContent(FlexAlign.Center)
    .borderRadius(24)
    .backgroundColor(this.barColor)
    .shadow({ radius: 10, color: '#16000000', offsetY: 3 })
  }
}
