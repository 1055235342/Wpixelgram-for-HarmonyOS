@Component
export struct ChatAvatarView {
  @Prop path: string = '';
  @Prop label: string = '?';
  @Prop avatarSize: number = 30;
  @Prop radius: number = 0;
  @Prop fontSize: number = 0;
  @Prop fillColor: ResourceColor = '#2F80ED';
  @Prop imageBackgroundColor: ResourceColor = '#D9F0FF';
  @Prop leftMargin: number = 0;
  @Prop rightMargin: number = 0;

  private getRadius(): number {
    return this.radius > 0 ? this.radius : this.avatarSize / 2;
  }

  private getFontSize(): number {
    if (this.fontSize > 0) {
      return this.fontSize;
    }
    return this.avatarSize > 42 ? 24 : 17;
  }

  build() {
    if (this.path.length > 0) {
      Image(this.path)
        .width(this.avatarSize)
        .height(this.avatarSize)
        .borderRadius(this.getRadius())
        .objectFit(ImageFit.Cover)
        .backgroundColor(this.imageBackgroundColor)
        .margin({ left: this.leftMargin, right: this.rightMargin })
    } else {
      Text(this.label.length > 0 ? this.label : '?')
        .fontSize(this.getFontSize())
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .textAlign(TextAlign.Center)
        .width(this.avatarSize)
        .height(this.avatarSize)
        .borderRadius(this.getRadius())
        .backgroundColor(this.fillColor)
        .margin({ left: this.leftMargin, right: this.rightMargin })
    }
  }
}
