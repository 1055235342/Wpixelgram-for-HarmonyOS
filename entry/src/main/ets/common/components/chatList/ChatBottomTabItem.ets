@Component
export struct ChatBottomTabItem {
  @Prop label: string = '';
  @Prop tabKey: string = '';
  @Prop activeTab: string = '';
  normalIcon: Resource = $r('app.media.bar_msg');
  selectedIcon: Resource = $r('app.media.bar_msg_select');
  @Prop badge: number = 0;

  private formatBadge(count: number): string {
    return count > 99 ? '99+' : `${count}`;
  }

  build() {
    Column() {
      Stack({ alignContent: Alignment.TopEnd }) {
        Image(this.activeTab === this.tabKey ? this.selectedIcon : this.normalIcon)
          .width(42)
          .height(24)
          .objectFit(ImageFit.Contain)
        if (this.badge > 0) {
          Text(this.formatBadge(this.badge))
            .fontSize(12)
            .fontWeight(FontWeight.Bold)
            .fontColor(Color.White)
            .textAlign(TextAlign.Center)
            .width(20)
            .height(20)
            .borderRadius(10)
            .backgroundColor('#238AF2')
        }
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
