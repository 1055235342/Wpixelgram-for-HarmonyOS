// entry/src/main/ets/pages/GlobalSearchPage.ets
import router from '@ohos.router';
import { TdMessage, TdMessageContent, TdUpdate, TdlibService } from '../common/service/TdlibService';
import { AppLayout } from '../common/constants/AppLayout';

interface SearchResultItem {
  id: string;
  kind: string;
  chatId: number;
  messageId: number;
  title: string;
  preview: string;
}

@Entry
@Component
export struct GlobalSearchPage {
  @State query: string = '';
  @State results: SearchResultItem[] = [];
  @State statusText: string = '输入关键词搜索消息或联系人';
  private td = TdlibService.getInstance();
  private listenersRegistered: boolean = false;
  private activeQuery: string = '';
  private chatTitles: Map<number, string> = new Map();

  aboutToAppear() {
    this.registerListeners();
  }

  private registerListeners(): void {
    if (this.listenersRegistered) {
      return;
    }
    this.listenersRegistered = true;
    this.td.onUpdate('foundMessages', (update: TdUpdate) => {
      const messages: TdMessage[] = update.messages ? update.messages : [];
      console.info(`[GlobalSearchPage] received foundMessages count=${messages.length}, nextOffset=${update.next_offset}`);
      const items: SearchResultItem[] = messages.map((message: TdMessage): SearchResultItem => {
        const chatId = message.chat_id !== undefined ? message.chat_id : 0;
        if (chatId !== 0) {
          this.td.getChat(chatId);
        }
        return {
          id: `message-${chatId}-${message.id}`,
          kind: 'message',
          chatId: chatId,
          messageId: message.id,
          title: this.getChatTitle(chatId),
          preview: this.getMessagePreview(message.content)
        };
      });
      this.results = items;
      this.statusText = items.length > 0 ? '' : '没有搜索到消息';
    });
    this.td.onUpdate('chats', (update: TdUpdate) => {
      if (this.activeQuery.length === 0) {
        return;
      }
      const chatIds: number[] = update.chat_ids ? update.chat_ids : [];
      console.info(`[GlobalSearchPage] received chats count=${chatIds.length}`);
      chatIds.forEach((chatId: number) => {
        this.td.getChat(chatId);
        this.upsertResult({
          id: `chat-${chatId}`,
          kind: 'chat',
          chatId: chatId,
          messageId: 0,
          title: this.getChatTitle(chatId),
          preview: '点击进入会话'
        });
      });
      if (this.results.length === 0 && chatIds.length === 0) {
        this.statusText = '没有搜索到结果';
      }
    });
    this.td.onUpdate('chat', (update: TdUpdate) => {
      if (update.id === undefined || update.title === undefined) {
        return;
      }
      console.info(`[GlobalSearchPage] received chat id=${update.id}, title=${update.title}`);
      this.chatTitles.set(update.id, update.title);
      this.refreshChatTitle(update.id, update.title);
    });
  }

  private submitSearch(value: string): void {
    this.query = value.trim();
    this.activeQuery = this.query;
    console.info(`[GlobalSearchPage] search submit query=${this.query}`);
    if (this.query.length === 0) {
      this.results = [];
      this.statusText = '输入关键词搜索消息或联系人';
      return;
    }
    this.results = [];
    this.statusText = '搜索中...';
    this.td.searchMessages(this.query, '', 30);
    this.td.searchChatsOnServer(this.query, 20);
  }

  private getChatTitle(chatId: number): string {
    const title = this.chatTitles.get(chatId);
    if (title !== undefined && title.length > 0) {
      return title;
    }
    return chatId !== 0 ? `Chat ${chatId}` : '未知会话';
  }

  private getMessagePreview(content: TdMessageContent | undefined): string {
    if (!content) {
      return '[未知消息]';
    }
    if (content.type === 'messageText' && content.text) {
      return content.text.text;
    }
    if ((content.type === 'messagePhoto' || content.type === 'messageVideo') && content.caption) {
      return content.caption.text.length > 0 ? content.caption.text : `[${content.type}]`;
    }
    if (content.type === 'messagePhoto') {
      return '[图片]';
    }
    if (content.type === 'messageVideo') {
      return '[视频]';
    }
    return `[${content.type}]`;
  }

  private upsertResult(item: SearchResultItem): void {
    const nextResults = this.results.slice();
    const index = nextResults.findIndex((current: SearchResultItem): boolean => current.id === item.id);
    if (index >= 0) {
      nextResults[index] = item;
    } else {
      nextResults.push(item);
    }
    this.results = nextResults;
    this.statusText = '';
  }

  private refreshChatTitle(chatId: number, title: string): void {
    let changed = false;
    const nextResults = this.results.map((item: SearchResultItem): SearchResultItem => {
      if (item.chatId !== chatId) {
        return item;
      }
      changed = true;
      return {
        id: item.id,
        kind: item.kind,
        chatId: item.chatId,
        messageId: item.messageId,
        title: title,
        preview: item.preview
      };
    });
    if (changed) {
      this.results = nextResults;
    }
  }

  private openResult(item: SearchResultItem): void {
    console.info(`[GlobalSearchPage] result clicked kind=${item.kind}, chatId=${item.chatId}, messageId=${item.messageId}`);
    if (item.chatId === 0) {
      this.statusText = '无法打开该结果';
      return;
    }
    if (item.messageId !== 0) {
      this.td.openMessageContent(item.chatId, item.messageId);
      router.pushUrl({ url: 'pages/ChatPage', params: { chatId: item.chatId, messageId: item.messageId } });
    } else {
      router.pushUrl({ url: 'pages/ChatPage', params: { chatId: item.chatId } });
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
      .position({ x: 18, y: AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTROL_Y_OFFSET })
      .onClick(() => {
        router.back();
      })

      Search({ placeholder: '搜索消息或联系人', value: this.query })
        .onChange((value: string) => {
          this.query = value;
        })
        .onSubmit((value: string) => {
          this.submitSearch(value);
        })
        .height(44)
        .width('calc(100% - 82vp)')
        .position({ x: 70, y: AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTROL_Y_OFFSET })
    }
    .width('100%')
    .height(AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT)
    .clip(true)
  }

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column() {
        if (this.statusText.length > 0) {
          Text(this.statusText)
            .fontSize(15)
            .fontColor('#666666')
            .padding(12)
        }

        List() {
          ForEach(this.results, (item: SearchResultItem) => {
            ListItem() {
              Column() {
                Text(item.title)
                  .fontSize(17)
                  .fontWeight(FontWeight.Medium)
                  .width('100%')
                Text(item.preview)
                  .fontSize(14)
                  .fontColor('#666666')
                  .maxLines(2)
                  .textOverflow({ overflow: TextOverflow.Ellipsis })
                  .margin({ top: 6 })
                  .width('100%')
              }
              .width('100%')
              .padding(14)
              .onClick(() => {
                this.openResult(item);
              })
            }
          })
        }
        .width('100%')
        .layoutWeight(1)
      }
      .width('100%')
      .height('100%')
      .padding({
        top: AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT,
        bottom: AppLayout.BOTTOM_SAFE_HEIGHT
      })

      this.TopBar()
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#EEF0F5')
  }
}
