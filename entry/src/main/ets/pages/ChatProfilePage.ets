// entry/src/main/ets/pages/ChatProfilePage.ets
import router from '@ohos.router';
import { AppLayout } from '../common/constants/AppLayout';
import { TdChat, TdFile, TdlibService, TdUpdate } from '../common/service/TdlibService';
import { getLocalPath } from '../common/utils/ChatListMappers';

interface ChatProfileRouteParams {
  chatId?: number | string;
  title?: string;
  avatarPath?: string;
  avatarFileId?: number | string;
  avatarText?: string;
  avatarColor?: string;
}

@Entry
@Component
struct ChatProfilePage {
  @State chatId: number = 0;
  @State title: string = '聊天资料';
  @State subtitle: string = '';
  @State avatarPath: string = '';
  @State avatarText: string = '?';
  @State avatarColor: string = '#338AF6';
  @State avatarFileId: number = 0;
  private td = TdlibService.getInstance();

  aboutToAppear(): void {
    this.readRouteParams();
    this.td.onUpdate('chat', (update: TdUpdate) => {
      if (update.id !== this.chatId || update.title === undefined) {
        return;
      }
      const chat: TdChat = {
        id: update.id,
        title: update.title,
        type: update.chat_type,
        photo: update.photo,
        last_message: update.last_message,
        unread_count: update.unread_count,
        is_marked_as_unread: update.is_marked_as_unread,
        last_read_inbox_message_id: update.last_read_inbox_message_id,
        last_read_outbox_message_id: update.last_read_outbox_message_id,
        positions: update.positions,
        reply_markup_message_id: update.reply_markup_message_id
      };
      this.applyChat(chat);
    });
    this.td.onUpdate('file', (update: TdUpdate) => {
      if (update.file) {
        this.applyFile(update.file);
      }
    });
    this.td.onUpdate('updateFile', (update: TdUpdate) => {
      if (update.file) {
        this.applyFile(update.file);
      }
    });
    if (this.chatId !== 0) {
      this.td.getChat(this.chatId);
    }
  }

  private readRouteParams(): void {
    const params = router.getParams() as ChatProfileRouteParams;
    if (params && params.chatId !== undefined) {
      this.chatId = Number(params.chatId);
    }
    if (params && params.title !== undefined) {
      this.title = params.title;
      this.avatarText = this.getAvatarText(params.title);
    }
    if (params && params.avatarPath !== undefined) {
      this.avatarPath = params.avatarPath;
    }
    if (params && params.avatarFileId !== undefined) {
      this.avatarFileId = Number(params.avatarFileId);
    }
    if (params && params.avatarText !== undefined) {
      this.avatarText = params.avatarText;
    }
    if (params && params.avatarColor !== undefined) {
      this.avatarColor = params.avatarColor;
    }
  }

  private applyChat(chat: TdChat): void {
    this.title = chat.title;
    this.avatarText = this.getAvatarText(chat.title);
    this.subtitle = chat.type && chat.type.type ? this.getSubtitle(chat.type.type) : '';
    if (chat.photo && chat.photo.small) {
      this.avatarFileId = chat.photo.small.id;
      const localPath = getLocalPath(chat.photo.small);
      if (localPath.length > 0) {
        this.avatarPath = localPath;
      } else {
        this.td.downloadFile(chat.photo.small.id, 10);
      }
    }
  }

  private applyFile(file: TdFile): void {
    if (this.avatarFileId === 0 || file.id !== this.avatarFileId) {
      return;
    }
    const localPath = getLocalPath(file);
    if (localPath.length > 0) {
      this.avatarPath = localPath;
    }
  }

  private getAvatarText(title: string): string {
    const trimmed = title.trim();
    return trimmed.length > 0 ? trimmed.substring(0, 1) : '?';
  }

  private getSubtitle(type: string): string {
    if (type === 'chatTypePrivate') {
      return '个人资料';
    }
    if (type === 'chatTypeSupergroup' || type === 'chatTypeBasicGroup') {
      return '群组资料';
    }
    return '聊天资料';
  }

  @Builder
  private Avatar(size: number) {
    if (this.avatarPath.length > 0) {
      Image(this.avatarPath)
        .width(size)
        .height(size)
        .borderRadius(size / 2)
        .objectFit(ImageFit.Cover)
    } else {
      Text(this.avatarText)
        .fontSize(34)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .textAlign(TextAlign.Center)
        .width(size)
        .height(size)
        .borderRadius(size / 2)
        .backgroundColor(this.avatarColor)
    }
  }

  @Builder
  private TopBar() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column()
        .width('100%')
        .height(AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT)
        .backgroundColor('#EEF0F5')
        .linearGradientBlur(AppLayout.TOP_GRADIENT_BLUR_RADIUS, {
          fractionStops: [[0, 0], [1, 1]],
          direction: GradientDirection.Top
        })

      Button({ type: ButtonType.Circle }) {
        Image($r('app.media.back'))
          .width(21)
          .height(21)
          .objectFit(ImageFit.Contain)
          .fillColor('#111111')
      }
      .width(44)
      .height(44)
      .borderRadius(22)
      .backgroundColor('#F8FFFFFF')
      .border({ width: 1, color: '#FFFFFFFF' })
      .shadow({ radius: 12, color: '#12000000', offsetY: 4 })
      .position({ x: 24, y: AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTROL_Y_OFFSET })
      .onClick(() => {
        router.back();
      })

      Text(this.title)
        .fontSize(18)
        .fontWeight(FontWeight.Bold)
        .fontColor('#111111')
        .maxLines(1)
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .width('58%')
        .textAlign(TextAlign.Center)
        .position({ x: '21%', y: AppLayout.STATUS_BAR_HEIGHT + 18 })
    }
    .width('100%')
    .height(AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT)
    .clip(true)
  }

  build() {
    Stack() {
      Scroll() {
        Column() {
          this.Avatar(92)
          Text(this.title)
            .fontSize(22)
            .fontWeight(FontWeight.Bold)
            .fontColor('#111111')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
            .margin({ top: 14 })
          Text(this.subtitle)
            .fontSize(14)
            .fontColor('#858A93')
            .margin({ top: 4 })
          Column()
            .width('86%')
            .height(180)
            .borderRadius(24)
            .backgroundColor(Color.White)
            .margin({ top: 28 })
        }
        .width('100%')
        .alignItems(HorizontalAlign.Center)
        .padding({
          top: AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT + 10,
          bottom: AppLayout.BOTTOM_SAFE_HEIGHT + 24
        })
      }
      .width('100%')
      .height('100%')
      .backgroundColor('#EEF0F5')
      .scrollBar(BarState.Off)

      this.TopBar()
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#EEF0F5')
  }
}
