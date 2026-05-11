import { ChatItem } from '../../model/ChatListModels';

@Component
export struct ChatListRow {
  @Prop item: ChatItem = {
    id: 0,
    title: '',
    lastMessage: '',
    timeText: '',
    unreadCount: 0,
    lastReadInboxMessageId: 0,
    isOutgoing: false,
    isRead: false,
    isPinned: false,
    category: '',
    avatarText: '',
    avatarColor: '#2F80ED',
    avatarPath: '',
    avatarFileId: 0
  };
  @Prop selectedChatId: number = 0;
  onOpenChat: (item: ChatItem) => void = (item: ChatItem): void => {};
  onLongPressChat: (item: ChatItem, centerX: number, centerY: number) => void =
    (item: ChatItem, centerX: number, centerY: number): void => {};

  private formatBadge(count: number): string {
    return count > 99 ? '99+' : `${count}`;
  }

  private getRowBackgroundColor(): ResourceColor {
    if (this.selectedChatId === this.item.id) {
      return '#EAF4FF';
    }
    if (this.item.isPinned) {
      return '#F1F3F6';
    }
    return Color.Transparent;
  }

  private getDividerColor(): ResourceColor {
    return this.item.isPinned ? '#DDE2EA' : '#EEF1F5';
  }

  @Builder
  private Avatar() {
    if (this.item.avatarPath.length > 0) {
      Image(this.item.avatarPath)
        .width(44)
        .height(44)
        .borderRadius(22)
        .objectFit(ImageFit.Cover)
        .backgroundColor('#E8F2FF')
    } else {
      Text(this.item.avatarText)
        .fontSize(18)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .textAlign(TextAlign.Center)
        .width(44)
        .height(44)
        .borderRadius(22)
        .backgroundColor(this.item.avatarColor)
    }
  }

  build() {
    Column() {
      Row() {
        this.Avatar()
        Column() {
          Row() {
            Text(this.item.title)
              .fontSize(14)
              .fontWeight(FontWeight.Bold)
              .fontColor('#222222')
              .textAlign(TextAlign.Start)
              .maxLines(1)
              .textOverflow({ overflow: TextOverflow.Ellipsis })
              .layoutWeight(1)
            if (this.item.category === '机器人') {
              Text('✓')
                .fontSize(11)
                .fontColor(Color.White)
                .textAlign(TextAlign.Center)
                .width(18)
                .height(18)
                .borderRadius(9)
                .backgroundColor('#238AF2')
                .margin({ left: 6 })
            }
          }
          .width('100%')

          Text(this.item.lastMessage.length > 0 ? this.item.lastMessage : '暂无消息')
            .fontSize(11)
            .fontColor('#778498')
            .textAlign(TextAlign.Start)
            .width('100%')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
            .margin({ top: 3 })
        }
        .layoutWeight(1)
        .alignItems(HorizontalAlign.Start)
        .margin({ left: 12, right: 8 })

        Column() {
          Text(this.item.timeText)
            .fontSize(10)
            .fontColor('#8A96A8')
            .height(16)

          if (this.item.unreadCount > 0) {
            Text(this.formatBadge(this.item.unreadCount))
              .fontSize(10)
              .fontWeight(FontWeight.Bold)
              .fontColor(Color.White)
              .textAlign(TextAlign.Center)
              .width(this.item.unreadCount > 99 ? 34 : 24)
              .height(22)
              .borderRadius(11)
              .backgroundColor('#238AF2')
              .margin({ top: 4 })
          } else if (this.item.isPinned) {
            Image($r('app.media.dingzhu'))
              .width(17)
              .height(17)
              .objectFit(ImageFit.Contain)
              .margin({ top: 4 })
          } else if (this.item.isOutgoing) {
            Text(this.item.isRead ? '✓✓' : '✓')
              .fontSize(14)
              .fontColor(this.item.isRead ? '#34B768' : '#A2ABBA')
              .margin({ top: 4 })
          } else {
            Blank()
              .height(22)
          }
        }
        .width(42)
        .alignItems(HorizontalAlign.End)
      }
      .width('100%')
      .height(60)
      .padding({ left: 14, right: 14 })
      .onClick(() => {
        this.onOpenChat(this.item);
      })
      .gesture(
        LongPressGesture().onAction((event: LongPressGestureEvent) => {
          let centerX = 195;
          let centerY = 240;
          if (event.fingerList.length > 0) {
            centerX = event.fingerList[0].globalX;
            centerY = event.fingerList[0].globalY;
          }
          console.info(`[ChatListRow] long press chatId=${this.item.id}, x=${centerX}, y=${centerY}`);
          this.onLongPressChat(this.item, centerX, centerY);
        })
      )
      .backgroundColor(this.getRowBackgroundColor())

      Divider()
        .strokeWidth(1)
        .color(this.getDividerColor())
        .margin({ left: 70 })
    }
    .width('100%')
    .backgroundColor(this.getRowBackgroundColor())
  }
}
