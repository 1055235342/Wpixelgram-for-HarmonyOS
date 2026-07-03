import { AppLayout } from '../../../../common/constants/AppLayout';
import { ChatAvatarView } from '../detail/ChatAvatarView';

@Component
export struct ChatHeaderBar {
  @Prop embedded: boolean = false;
  @Prop title: string = '';
  @Prop subtitle: string = '';
  @Prop avatarPath: string = '';
  @Prop avatarText: string = '?';
  @Prop panelColor: ResourceColor = '#E6FFFFFF';
  onBack: () => void = (): void => {};
  onTitleClick: () => void = (): void => {};
  onAvatarClick: () => void = (): void => {};

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Row() {
        Button({ type: ButtonType.Circle }) {
          if (!this.embedded) {
            Image($r('app.media.back'))
              .width(22)
              .height(22)
              .objectFit(ImageFit.Contain)
              .fillColor(Color.Black)
          } else {
            Blank()
              .width(22)
              .height(22)
          }
        }
        .width(40)
        .height(40)
        .borderRadius(20)
        .backgroundColor(this.panelColor)
        .onClick(() => {
          this.onBack();
        })
      }
      .height(40)
      .padding({ left: 0, right: 0 })
      .borderRadius(20)
      .backgroundColor('#00ffffff')
      .shadow({ radius: 12, color: '#1A000000', offsetY: 4 })
      .position({ x: 14, y: AppLayout.STATUS_BAR_HEIGHT + 8 })
      .zIndex(10)

      Row() {
        Blank()
        Column() {
          Row() {
            Text(this.title)
              .fontSize(10)
              .fontWeight(FontWeight.Bold)
              .fontColor('#0B0F14')
              .maxLines(1)
              .textOverflow({ overflow: TextOverflow.Ellipsis })
              .width('80%')
              .textAlign(TextAlign.Center)
          }
          .justifyContent(FlexAlign.Center)
          .width('100%')

          Text(this.subtitle.length > 0 ? this.subtitle : '连接中...')
            .fontSize(11)
            .fontColor('#737B7A')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
            .margin({ top: 1 })
        }
        .height(40)
        .width('44%')
        .justifyContent(FlexAlign.Center)
        .padding({ left: 12, right: 12 })
        .borderRadius(20)
        .backgroundColor(this.panelColor)
        .shadow({ radius: 12, color: '#16000000', offsetY: 4 })
        .onClick(() => {
          this.onTitleClick();
        })
        Blank()
      }
      .width('100%')
      .height(40)
      .position({ x: 0, y: AppLayout.STATUS_BAR_HEIGHT + 8 })

      Row() {
        Blank()
        Stack({ alignContent: Alignment.Center }) {
          Circle()
            .width(40)
            .height(40)
            .fill(this.panelColor)
          ChatAvatarView({
            path: this.avatarPath,
            label: this.avatarText,
            avatarSize: 36,
            fontSize: 17
          })
        }
        .width(40)
        .height(40)
        .onClick(() => {
          this.onAvatarClick();
        })
      }
      .width('100%')
      .height(40)
      .padding({ right: 12 })
      .position({ x: 0, y: AppLayout.STATUS_BAR_HEIGHT + 8 })
    }
    .width('100%')
    .height(AppLayout.STATUS_BAR_HEIGHT + 58)
  }
}
