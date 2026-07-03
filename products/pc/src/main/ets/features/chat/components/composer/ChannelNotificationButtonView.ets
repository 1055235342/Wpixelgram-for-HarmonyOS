@Component
export struct ChannelNotificationButtonView {
  @Prop panelColor: ResourceColor = '#E6FFFFFF';
  @Prop text: string = '';
  @Prop dimIcon: boolean = false;
  onGiftClick: () => void = (): void => {};
  onMainClick: () => void = (): void => {};
  onSearchClick: () => void = (): void => {};

  build() {
    Row() {
      Button({ type: ButtonType.Circle }) {
        Image($r('app.media.property'))
          .width(24)
          .height(24)
          .objectFit(ImageFit.Contain)
      }
      .width(48)
      .height(48)
      .backgroundColor(this.panelColor)
      .shadow({ radius: 12, color: '#16000000', offsetY: 4 })
      .onClick(() => {
        this.onGiftClick();
      })

      Button() {
        Row({ space: 8 }) {
          Image($r('app.media.jingyin'))
            .width(17)
            .height(17)
            .objectFit(ImageFit.Contain)
            .opacity(this.dimIcon ? 0.55 : 1)
          Text(this.text)
            .fontSize(16)
            .fontColor('#111111')
            .fontWeight(FontWeight.Bold)
        }
        .justifyContent(FlexAlign.Center)
        .width('100%')
      }
      .layoutWeight(1)
      .height(48)
      .margin({ left: 12, right: 12 })
      .borderRadius(24)
      .backgroundColor(this.panelColor)
      .shadow({ radius: 12, color: '#16000000', offsetY: 4 })
      .onClick(() => {
        this.onMainClick();
      })

      Button({ type: ButtonType.Circle }) {
        Image($r('app.media.bar_search'))
          .width(24)
          .height(24)
          .objectFit(ImageFit.Contain)
      }
      .width(48)
      .height(48)
      .backgroundColor(this.panelColor)
      .shadow({ radius: 12, color: '#16000000', offsetY: 4 })
      .onClick(() => {
        this.onSearchClick();
      })
    }
    .width('100%')
    .height(52)
  }
}
