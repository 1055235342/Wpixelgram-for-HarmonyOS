@Component
export struct UnreadDividerView {
  build() {
    Row() {
      Divider()
        .strokeWidth(1)
        .color('#660A84FF')
        .layoutWeight(1)
      Text('未读消息')
        .fontSize(11)
        .fontColor('#0A84FF')
        .padding({ left: 10, right: 10, top: 3, bottom: 3 })
        .borderRadius(10)
        .backgroundColor('#E8F4FF')
      Divider()
        .strokeWidth(1)
        .color('#660A84FF')
        .layoutWeight(1)
    }
    .width('100%')
    .padding({ left: 18, right: 18, top: 8, bottom: 8 })
  }
}
