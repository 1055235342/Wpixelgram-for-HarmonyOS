@Component
export struct ChatComposerBar {
  @Prop panelColor: ResourceColor = '#E6FFFFFF';
  @Prop inputText: string = '';
  @Prop showBotMenuButton: boolean = false;
  @Prop botMenuVisible: boolean = false;
  onBotMenuToggle: () => void = (): void => {};
  onAttachClick: () => void = (): void => {};
  onInputChange: (value: string) => void = (value: string): void => {};
  onEmojiClick: () => void = (): void => {};
  onSendOrVoiceClick: () => void = (): void => {};

  build() {
    Row() {
      if (this.showBotMenuButton) {
        Button() {
          Text(this.botMenuVisible ? '×' : '☰')
            .fontSize(15)
            .fontWeight(FontWeight.Bold)
            .fontColor(Color.White)
            .textAlign(TextAlign.Center)
        }
        .width(40)
        .height(40)
        .borderRadius(22)
        .backgroundColor('#0A84FF')
        .shadow({ radius: 10, color: '#16000000', offsetY: 3 })
        .onClick(() => {
          this.onBotMenuToggle();
        })
      }

      Button() {
        Image($r('app.media.file_attachment'))
          .width(21)
          .height(21)
          .objectFit(ImageFit.Contain)
      }
      .width(40)
      .height(40)
      .borderRadius(20)
      .backgroundColor(this.panelColor)
      .shadow({ radius: 10, color: '#16000000', offsetY: 3 })
      .margin({ left: this.showBotMenuButton ? 6 : 0 })
      .onClick(() => {
        this.onAttachClick();
      })

      Row() {
        TextInput({ placeholder: '输入消息...', text: this.inputText })
          .fontSize(14)
          .fontColor('#222222')
          .placeholderColor('#8F9A91')
          .backgroundColor('#00ffffff')
          .layoutWeight(1)
          .onChange((value: string) => {
            this.onInputChange(value);
          })
        Text('◔')
          .fontSize(22)
          .fontColor('#7A8278')
          .width(30)
          .height(38)
          .textAlign(TextAlign.Center)
          .onClick(() => {
            this.onEmojiClick();
          })
      }
      .layoutWeight(1)
      .height(40)
      .padding({ left: 10, right: 7 })
      .margin({ left: 7, right: 7 })
      .borderRadius(20)
      .backgroundColor(this.panelColor)
      .shadow({ radius: 10, color: '#12000000', offsetY: 3 })

      Button() {
        if (this.inputText.trim().length > 0) {
          Text('➤')
            .fontSize(17)
            .fontColor('#6F776D')
            .textAlign(TextAlign.Center)
        } else {
          Image($r('app.media.yuyin'))
            .width(21)
            .height(21)
            .objectFit(ImageFit.Contain)
        }
      }
      .width(40)
      .height(40)
      .borderRadius(20)
      .backgroundColor(this.panelColor)
      .shadow({ radius: 10, color: '#16000000', offsetY: 3 })
      .onClick(() => {
        this.onSendOrVoiceClick();
      })
    }
    .width('100%')
    .height(44)
  }
}
