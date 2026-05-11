@Component
export struct CallsContent {
  build() {
    Column() {
      Text('最近通话')
        .fontSize(22)
        .fontWeight(FontWeight.Bold)
        .fontColor('#222222')
        .width('100%')
        .padding({ left: 20, right: 20, top: 18, bottom: 8 })
      Column() {
        Text('暂无最近通话')
          .fontSize(18)
          .fontWeight(FontWeight.Bold)
          .fontColor('#27364A')
        Text('后续接入 TDLib 通话记录后会显示在这里')
          .fontSize(14)
          .fontColor('#8A96A8')
          .margin({ top: 8 })
      }
      .width('100%')
      .layoutWeight(1)
      .justifyContent(FlexAlign.Center)
      .alignItems(HorizontalAlign.Center)
    }
    .width('100%')
    .height('100%')
  }
}
