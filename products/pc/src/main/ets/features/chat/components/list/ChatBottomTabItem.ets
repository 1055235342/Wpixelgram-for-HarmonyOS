@Component
export struct ChatBottomTabItem {
  @Prop label: string = '';
  @Prop tabKey: string = '';
  @Prop activeTab: string = '';
  normalIcon: Resource = $r('app.media.bar_msg');
  selectedIcon: Resource = $r('app.media.bar_msg_select');

  build() {
    Column() {
      Stack({ alignContent: Alignment.TopEnd }) {
        Image(this.activeTab === this.tabKey ? this.selectedIcon : this.normalIcon)
          .width(42)
          .height(24)
          .objectFit(ImageFit.Contain)
      }
      .width(42)
      .height(24)

      Text(this.label)
        .fontSize(10)
        .fontWeight(this.activeTab === this.tabKey ? FontWeight.Bold : FontWeight.Medium)
        .fontColor(this.activeTab === this.tabKey ? '#1E88F5' : '#718096')
        .width('100%')
        .textAlign(TextAlign.Center)
        .margin({ top: 4 })
    }
    .layoutWeight(1)
    .height(60)
    .justifyContent(FlexAlign.Center)
    .alignItems(HorizontalAlign.Center)
  }
}
