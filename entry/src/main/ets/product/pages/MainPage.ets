// entry/src/main/ets/product/pages/MainPage.ets
import router from '@ohos.router';
import { TdlibService, TdUpdate } from '../../common/service/TdlibService';
import { ChatListPage, ChatSelection } from '../../features/chat/view/ChatListView';
import { ChatPage } from '../../features/chat/view/ChatDetailView';

enum Breakpoint { SM = 'sm', MD = 'md', LG = 'lg' }

@Entry
@Component
struct MainPage {
  @State bp: Breakpoint = Breakpoint.SM;
  @State selectedChatId: number = 0;
  @State selectedTitle: string = '';
  @State selectedAvatarPath: string = '';
  @State selectedAvatarFileId: number = 0;
  @State selectedCategory: string = '';
  @State selectedUnreadCount: number = 0;
  @State selectedLastReadInboxMessageId: number = 0;
  private td = TdlibService.getInstance();
  private authListenersRegistered: boolean = false;

  aboutToAppear() {
    this.registerAuthGuard();
    this.td.getAuthorizationState();
    this.td.getChats();
    this.td.getContacts();
    this.td.getMe();
  }

  private registerAuthGuard(): void {
    if (this.authListenersRegistered) {
      return;
    }
    this.authListenersRegistered = true;
    this.td.onUpdate('authorizationStateWaitPhoneNumber', (_update: TdUpdate) => {
      this.redirectToLogin('wait phone');
    });
    this.td.onUpdate('authorizationStateClosed', (_update: TdUpdate) => {
      this.redirectToLogin('closed');
    });
    this.td.onUpdate('authorizationStateClosing', (_update: TdUpdate) => {
      this.redirectToLogin('closing');
    });
  }

  private redirectToLogin(reason: string): void {
    console.info(`[MainPage] redirect to login reason=${reason}`);
    router.replaceUrl({ url: 'product/pages/LoginPage' });
  }

  private updateBreakpoint(width: number): void {
    const next = width >= 1100 ? Breakpoint.LG : (width >= 700 ? Breakpoint.MD : Breakpoint.SM);
    if (this.bp !== next) {
      console.info(`[MainPage] breakpoint changed width=${width}, bp=${next}`);
      this.bp = next;
    }
  }

  private selectChat(selection: ChatSelection): void {
    console.info(`[MainPage] selectChat chatId=${selection.chatId}, title=${selection.title}`);
    console.error(`[ChatDetailDiag] selectChat chatId=${selection.chatId}, title=${selection.title}, bp=${this.bp}`);
    this.selectedChatId = selection.chatId;
    this.selectedTitle = selection.title;
    this.selectedAvatarPath = selection.avatarPath;
    this.selectedAvatarFileId = selection.avatarFileId;
    this.selectedCategory = selection.category;
    this.selectedUnreadCount = selection.unreadCount;
    this.selectedLastReadInboxMessageId = selection.lastReadInboxMessageId;
  }

  private getSelectedChatKeys(): number[] {
    if (this.selectedChatId === 0) {
      return [];
    }
    return [this.selectedChatId];
  }

  @Builder
  private EmptyDetail() {
    Column() {
      Text('选择一个会话')
        .fontSize(24)
        .fontWeight(FontWeight.Bold)
        .fontColor('#27364A')
      Text('左侧点击消息后，这里会展示聊天内容')
        .fontSize(16)
        .fontColor('#718096')
        .margin({ top: 10 })
    }
    .width('100%')
    .height('100%')
    .justifyContent(FlexAlign.Center)
    .alignItems(HorizontalAlign.Center)
    .backgroundColor('#DDF3FF')
  }

  @Builder
  private SplitLayout() {
    Row() {
      Column() {
        ChatListPage({
          embedded: true,
          selectedChatId: this.selectedChatId,
          onChatSelected: (selection: ChatSelection): void => {
            this.selectChat(selection);
          }
        })
      }
      .width(this.bp === Breakpoint.LG ? 420 : 390)
      .height('100%')
      .backgroundColor(Color.White)
      .border({ width: { right: 1 }, color: '#D7DEE9' })
      .shadow({ radius: 12, color: '#12000000', offsetX: 2 })

      Column() {
        if (this.selectedChatId === 0) {
          this.EmptyDetail()
        } else {
          ForEach(this.getSelectedChatKeys(), (chatId: number) => {
            ChatPage({
              initialChatId: chatId,
              initialTitle: this.selectedTitle,
              initialAvatarPath: this.selectedAvatarPath,
              initialAvatarFileId: this.selectedAvatarFileId,
              initialCategory: this.selectedCategory,
              initialUnreadCount: this.selectedUnreadCount,
              initialLastReadInboxMessageId: this.selectedLastReadInboxMessageId,
              embedded: true
            })
          }, (chatId: number): string => `${chatId}`)
        }
      }
      .layoutWeight(1)
      .height('100%')
      .backgroundColor('#DDF3FF')
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#DDF3FF')
  }

  build() {
    Stack() {
      if (this.bp === Breakpoint.SM) {
        ChatListPage()
          .width('100%')
          .height('100%')
      } else {
        this.SplitLayout()
      }
    }
    .width('100%')
    .height('100%')
    .backgroundColor(this.bp === Breakpoint.SM ? '#0C7FE8' : '#DDF3FF')
    .onAppear(() => {
      console.error(`[ChatDetailDiag] MainPage appear bp=${this.bp}, selectedChatId=${this.selectedChatId}`);
    })
    .onAreaChange((oldArea: Area, newArea: Area) => {
      const width = Number(newArea.width);
      if (!Number.isNaN(width)) {
        this.updateBreakpoint(width);
      }
    })
  }
}
