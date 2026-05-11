// entry/src/main/ets/pages/ChatListPage.ets
import { TdChat, TdFile, TdMessage, TdlibService, TdUpdate } from '../common/service/TdlibService';
import router from '@ohos.router';
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';
import { ContactsPage } from './ContactsPage';
import { ProfilePage } from './ProfilePage';
import { ChatBottomTabItem } from '../common/components/chatList/ChatBottomTabItem';
import { ChatListContent } from '../common/components/chatList/ChatListContent';
import { ChatSearchOverlay } from '../common/components/chatList/ChatSearchOverlay';
import { CallsContent } from '../common/components/chatList/CallsContent';
import { ChatItem, ChatSelection } from '../common/model/ChatListModels';
import {
  createChatItem,
  createLoadingChat,
  getAvatarText,
  getLocalPath,
  getMessagePreview,
  getMessageTime,
  isMainChatPosition,
  isPinnedByPosition,
  isPinnedByPositions
} from '../common/utils/ChatListMappers';
import {
  DividerMode,
  HdsBarStyle,
  HdsTabs,
  HdsTabsController,
  hdsMaterial
} from '@kit.UIDesignKit';

export { ChatSelection } from '../common/model/ChatListModels';

interface PreviewMessageItem {
  id: string;
  text: string;
  isSelf: boolean;
  placeholder: boolean;
}

@Entry
@Component
export struct ChatListPage {
  @State chats: ChatItem[] = [];
  @State activeCategory: string = '全部';
  @State activeBottomTab: string = 'chat';
  @State statusText: string = '';
  @State searchVisible: boolean = false;
  @State tabsSlideOut: boolean = false;
  @State contextMenuVisible: boolean = false;
  @State contextPreviewLoading: boolean = false;
  @State contextPreviewMessages: PreviewMessageItem[] = [];
  @State contextPreviewScale: number = 0.82;
  @State contextPreviewOpacity: number = 1;
  @State contextPreviewTranslateY: number = 14;
  @State contextMenuScale: number = 0.9;
  @State contextMenuOpacity: number = 0;
  @State contextMenuTranslateY: number = 10;
  @State contextPreviewLeft: number = 43;
  @State contextPreviewTop: number = 120;
  @State contextMenuLeft: number = 22;
  @State contextMenuTop: number = 382;
  @State contextLayerWidth: number = 390;
  @State contextLayerHeight: number = 780;
  @State contextChat: ChatItem = {
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
  embedded: boolean = false;
  selectedChatId: number = 0;
  onChatSelected: (selection: ChatSelection) => void = (selection: ChatSelection): void => {};
  private td = TdlibService.getInstance();
  private listenersRegistered: boolean = false;
  private chatScroller: Scroller = new Scroller();
  private tabsController: HdsTabsController = new HdsTabsController();
  private chatRequestLimit: number = 20;
  private chatLoadMoreInFlight: boolean = false;
  private chatAutoFillAttempts: number = 0;
  private contextPreviewChatId: number = 0;

  aboutToAppear() {
    this.registerListeners();
    this.requestInitialChats();
  }

  private requestInitialChats(): void {
    this.chatRequestLimit = 20;
    this.chatLoadMoreInFlight = false;
    this.chatAutoFillAttempts = 0;
    console.info(`[ChatListPage] request initial chats limit=${this.chatRequestLimit}`);
    this.td.loadChats(this.chatRequestLimit);
    this.td.getChats(this.chatRequestLimit);
  }

  private loadMoreChats(): void {
    if (this.chatLoadMoreInFlight) {
      return;
    }
    this.chatLoadMoreInFlight = true;
    this.chatRequestLimit += 20;
    console.info(`[ChatListPage] load more chats limit=${this.chatRequestLimit}`);
    this.td.loadChats(20);
    this.td.getChats(this.chatRequestLimit);
    setTimeout(() => {
      this.chatLoadMoreInFlight = false;
      this.td.getChats(this.chatRequestLimit);
    }, 650);
  }

  private registerListeners(): void {
    if (this.listenersRegistered) {
      return;
    }
    this.listenersRegistered = true;
    this.td.onUpdate('chats', (update: TdUpdate) => {
      const chatIds: number[] = update.chat_ids ? update.chat_ids : [];
      console.info(`[ChatListPage] received chats count=${chatIds.length}`);
      this.chatLoadMoreInFlight = false;
      this.applyChatIds(chatIds);
      if (this.activeBottomTab === 'chat' && chatIds.length < this.chatRequestLimit && this.chatAutoFillAttempts < 3) {
        this.chatAutoFillAttempts += 1;
        setTimeout(() => {
          this.loadMoreChats();
        }, 350);
      }
      chatIds.forEach((id: number) => {
        this.td.getChat(id);
      });
    });
    this.td.onUpdate('chat', (update: TdUpdate) => {
      if (update.id !== undefined && update.title !== undefined) {
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
          positions: update.positions
        };
        console.info(`[ChatListPage] received chat id=${chat.id}, title=${chat.title}`);
        this.upsertChat(chat);
      }
    });
    this.td.onUpdate('updateNewChat', (update: TdUpdate) => {
      if (update.chat) {
        console.info(`[ChatListPage] received updateNewChat id=${update.chat.id}, title=${update.chat.title}`);
        this.upsertChat(update.chat);
      }
    });
    this.td.onUpdate('updateChatTitle', (update: TdUpdate) => {
      if (update.chat_id !== undefined && update.title !== undefined) {
        console.info(`[ChatListPage] received updateChatTitle id=${update.chat_id}, title=${update.title}`);
        this.updateChatTitle(update.chat_id, update.title);
      }
    });
    this.td.onUpdate('updateChatLastMessage', (update: TdUpdate) => {
      if (update.chat_id !== undefined) {
        console.info(`[ChatListPage] received updateChatLastMessage id=${update.chat_id}`);
        this.ensureChatPlaceholder(update.chat_id);
        this.updateChatLastMessage(update.chat_id, update.last_message);
      }
    });
    this.td.onUpdate('updateChatReadInbox', (update: TdUpdate) => {
      if (update.chat_id !== undefined && update.unread_count !== undefined) {
        console.info(`[ChatListPage] received updateChatReadInbox id=${update.chat_id}, unread=${update.unread_count}`);
        this.updateUnreadCount(update.chat_id, update.unread_count, update.last_read_inbox_message_id);
      }
    });
    this.td.onUpdate('updateChatPosition', (update: TdUpdate) => {
      if (update.chat_id !== undefined) {
        console.info(`[ChatListPage] received updateChatPosition id=${update.chat_id}, position=${JSON.stringify(update.position)}, positions=${JSON.stringify(update.positions)}`);
        this.ensureChatPlaceholder(update.chat_id);
        if (update.position !== undefined) {
          if (isMainChatPosition(update.position)) {
            this.updatePinnedState(update.chat_id, isPinnedByPosition(update.position));
          }
        } else {
          this.updatePinnedState(update.chat_id, isPinnedByPositions(update.positions));
        }
      }
    });
    this.td.onUpdate('file', (update: TdUpdate) => {
      if (update.file) {
        console.info(`[ChatListPage] received file id=${update.file.id}`);
        this.applyAvatarFileUpdate(update.file);
      }
    });
    this.td.onUpdate('updateFile', (update: TdUpdate) => {
      if (update.file) {
        console.info(`[ChatListPage] received updateFile id=${update.file.id}`);
        this.applyAvatarFileUpdate(update.file);
      }
    });
    this.td.onUpdate('messages', (update: TdUpdate) => {
      this.applyContextPreviewMessages(update.messages ? update.messages : []);
    });
  }

  private applyChatIds(chatIds: number[]): void {
    const nextChats: ChatItem[] = [];
    const seenIds: Set<number> = new Set();
    chatIds.forEach((id: number) => {
      if (seenIds.has(id)) {
        console.warn(`[ChatListPage] skip duplicate chat id from getChats id=${id}`);
        return;
      }
      seenIds.add(id);
      const current = this.findChat(id);
      if (current) {
        nextChats.push(current);
      } else {
        nextChats.push(createLoadingChat(id));
      }
    });
    if (chatIds.length < this.chats.length) {
      this.chats.forEach((item: ChatItem) => {
        if (!seenIds.has(item.id)) {
          seenIds.add(item.id);
          nextChats.push(item);
        }
      });
    }
    this.chats = nextChats;
  }

  private dedupeChats(items: ChatItem[]): ChatItem[] {
    const seenIds: Set<number> = new Set();
    const result: ChatItem[] = [];
    items.forEach((item: ChatItem) => {
      if (seenIds.has(item.id)) {
        console.warn(`[ChatListPage] remove duplicate chat item id=${item.id}, title=${item.title}`);
        return;
      }
      seenIds.add(item.id);
      result.push(item);
    });
    return result;
  }

  private ensureChatPlaceholder(chatId: number): void {
    if (this.findChat(chatId)) {
      return;
    }
    console.info(`[ChatListPage] create placeholder for loaded chat id=${chatId}`);
    const nextChats = this.chats.slice();
    nextChats.push(createLoadingChat(chatId));
    this.chats = this.dedupeChats(nextChats);
    this.td.getChat(chatId);
  }

  private upsertChat(chat: TdChat): void {
    this.prepareChatAvatar(chat);
    const nextChats = this.chats.slice();
    const index = nextChats.findIndex((current: ChatItem): boolean => current.id === chat.id);
    const item: ChatItem = createChatItem(chat);
    const nextItem: ChatItem = index >= 0 && chat.positions === undefined ? {
      id: item.id,
      title: item.title,
      lastMessage: item.lastMessage,
      timeText: item.timeText,
      unreadCount: item.unreadCount,
      lastReadInboxMessageId: item.lastReadInboxMessageId,
      isOutgoing: item.isOutgoing,
      isRead: item.isRead,
      isPinned: nextChats[index].isPinned,
      category: item.category,
      avatarText: item.avatarText,
      avatarColor: item.avatarColor,
      avatarPath: item.avatarPath,
      avatarFileId: item.avatarFileId
    } : item;
    console.info(`[ChatListPage] upsert chat id=${chat.id}, pinned=${nextItem.isPinned}, rawPositions=${JSON.stringify(chat.positions)}`);
    if (index >= 0) {
      nextChats[index] = nextItem;
    } else {
      nextChats.push(nextItem);
    }
    this.chats = this.dedupeChats(nextChats);
  }

  private updateChatTitle(chatId: number, title: string): void {
    const nextChats = this.chats.slice();
    const index = nextChats.findIndex((current: ChatItem): boolean => current.id === chatId);
    if (index >= 0) {
      nextChats[index] = {
        id: nextChats[index].id,
        title: title,
        lastMessage: nextChats[index].lastMessage,
        timeText: nextChats[index].timeText,
        unreadCount: nextChats[index].unreadCount,
        lastReadInboxMessageId: nextChats[index].lastReadInboxMessageId,
        isOutgoing: nextChats[index].isOutgoing,
        isRead: nextChats[index].isRead,
        isPinned: nextChats[index].isPinned,
        category: nextChats[index].category,
        avatarText: getAvatarText(title),
        avatarColor: nextChats[index].avatarColor,
        avatarPath: nextChats[index].avatarPath,
        avatarFileId: nextChats[index].avatarFileId
      };
      this.chats = nextChats;
    }
  }

  private updateChatLastMessage(chatId: number, message: TdMessage | undefined): void {
    const nextChats = this.chats.slice();
    const index = nextChats.findIndex((current: ChatItem): boolean => current.id === chatId);
    if (index >= 0) {
      nextChats[index] = {
        id: nextChats[index].id,
        title: nextChats[index].title,
        lastMessage: getMessagePreview(message),
        timeText: getMessageTime(message),
        unreadCount: nextChats[index].unreadCount,
        lastReadInboxMessageId: nextChats[index].lastReadInboxMessageId,
        isOutgoing: message ? message.is_outgoing : false,
        isRead: nextChats[index].isRead,
        isPinned: nextChats[index].isPinned,
        category: nextChats[index].category,
        avatarText: nextChats[index].avatarText,
        avatarColor: nextChats[index].avatarColor,
        avatarPath: nextChats[index].avatarPath,
        avatarFileId: nextChats[index].avatarFileId
      };
      this.chats = nextChats;
    }
  }

  private updateUnreadCount(chatId: number, unreadCount: number, lastReadInboxMessageId: number | undefined = undefined): void {
    const nextChats = this.chats.slice();
    const index = nextChats.findIndex((current: ChatItem): boolean => current.id === chatId);
    if (index >= 0) {
      nextChats[index] = {
        id: nextChats[index].id,
        title: nextChats[index].title,
        lastMessage: nextChats[index].lastMessage,
        timeText: nextChats[index].timeText,
        unreadCount: unreadCount,
        lastReadInboxMessageId: lastReadInboxMessageId !== undefined ? lastReadInboxMessageId : nextChats[index].lastReadInboxMessageId,
        isOutgoing: nextChats[index].isOutgoing,
        isRead: nextChats[index].isRead,
        isPinned: nextChats[index].isPinned,
        category: nextChats[index].category,
        avatarText: nextChats[index].avatarText,
        avatarColor: nextChats[index].avatarColor,
        avatarPath: nextChats[index].avatarPath,
        avatarFileId: nextChats[index].avatarFileId
      };
      this.chats = nextChats;
    }
  }

  private markChatUnreadCleared(chatId: number): void {
    console.info(`[ChatListPage] clear unread badge locally chatId=${chatId}`);
    this.updateUnreadCount(chatId, 0);
  }

  private updatePinnedState(chatId: number, isPinned: boolean): void {
    const nextChats = this.chats.slice();
    const index = nextChats.findIndex((current: ChatItem): boolean => current.id === chatId);
    if (index >= 0) {
      nextChats[index] = {
        id: nextChats[index].id,
        title: nextChats[index].title,
        lastMessage: nextChats[index].lastMessage,
        timeText: nextChats[index].timeText,
        unreadCount: nextChats[index].unreadCount,
        lastReadInboxMessageId: nextChats[index].lastReadInboxMessageId,
        isOutgoing: nextChats[index].isOutgoing,
        isRead: nextChats[index].isRead,
        isPinned: isPinned,
        category: nextChats[index].category,
        avatarText: nextChats[index].avatarText,
        avatarColor: nextChats[index].avatarColor,
        avatarPath: nextChats[index].avatarPath,
        avatarFileId: nextChats[index].avatarFileId
      };
      this.chats = nextChats;
    }
  }

  private prepareChatAvatar(chat: TdChat): void {
    if (!chat.photo || !chat.photo.small) {
      return;
    }
    const file = chat.photo.small;
    if (!file.local || !file.local.is_downloading_completed) {
      console.info(`[ChatListPage] download avatar chatId=${chat.id}, fileId=${file.id}`);
      this.td.downloadFile(file.id, 8);
    }
  }

  private applyAvatarFileUpdate(file: TdFile): void {
    const path = getLocalPath(file);
    if (path.length === 0) {
      return;
    }
    let changed = false;
    const nextChats: ChatItem[] = this.chats.map((item: ChatItem): ChatItem => {
      if (item.avatarFileId !== file.id) {
        return item;
      }
      changed = true;
      return {
        id: item.id,
        title: item.title,
        lastMessage: item.lastMessage,
        timeText: item.timeText,
        unreadCount: item.unreadCount,
        lastReadInboxMessageId: item.lastReadInboxMessageId,
        isOutgoing: item.isOutgoing,
        isRead: item.isRead,
        isPinned: item.isPinned,
        category: item.category,
        avatarText: item.avatarText,
        avatarColor: item.avatarColor,
        avatarPath: path,
        avatarFileId: item.avatarFileId
      };
    });
    if (changed) {
      console.info(`[ChatListPage] apply avatar file update fileId=${file.id}`);
      this.chats = nextChats;
    }
  }

  private applyContextPreviewMessages(messages: TdMessage[]): void {
    if (!this.contextMenuVisible || !this.contextPreviewLoading || this.contextPreviewChatId === 0 || messages.length === 0) {
      return;
    }
    const previewItems: PreviewMessageItem[] = [];
    messages.slice().reverse().forEach((message: TdMessage) => {
      if (message.chat_id !== undefined && message.chat_id !== this.contextPreviewChatId) {
        return;
      }
      const text = getMessagePreview(message);
      previewItems.push({
        id: `${message.id}`,
        text: text.length > 0 ? text : '暂不支持的消息',
        isSelf: message.is_outgoing,
        placeholder: false
      });
    });
    if (previewItems.length === 0) {
      return;
    }
    this.contextPreviewMessages = previewItems.slice(Math.max(0, previewItems.length - 4));
    this.contextPreviewLoading = false;
    console.info(`[ChatListPage] context preview messages loaded chatId=${this.contextPreviewChatId}, count=${this.contextPreviewMessages.length}`);
  }

  private getPreviewPlaceholders(item: ChatItem): PreviewMessageItem[] {
    const items: PreviewMessageItem[] = [];
    if (item.lastMessage.length > 0 && item.lastMessage !== '加载中...') {
      items.push({
        id: 'last',
        text: item.lastMessage,
        isSelf: item.isOutgoing,
        placeholder: false
      });
    }
    while (items.length < 4) {
      items.push({
        id: `placeholder-${items.length}`,
        text: '读取消息中...',
        isSelf: items.length % 2 === 1,
        placeholder: true
      });
    }
    return items;
  }

  private findChat(chatId: number): ChatItem | undefined {
    return this.chats.find((current: ChatItem): boolean => current.id === chatId);
  }

  private getVisibleChats(): ChatItem[] {
    if (this.activeCategory === '全部') {
      return this.chats;
    }
    return this.chats.filter((item: ChatItem): boolean => item.category === this.activeCategory);
  }

  private getUnreadTotal(): number {
    let count = 0;
    this.chats.forEach((item: ChatItem) => {
      count += item.unreadCount;
    });
    return count;
  }

  private openChat(item: ChatItem): void {
    console.info(`[ChatListPage] chat item clicked chatId=${item.id}, title=${item.title}`);
    this.closeContextMenu();
    this.markChatUnreadCleared(item.id);
    if (this.embedded) {
      this.onChatSelected({
        chatId: item.id,
        title: item.title,
        avatarPath: item.avatarPath,
        avatarFileId: item.avatarFileId,
        category: item.category,
        unreadCount: item.unreadCount,
        lastReadInboxMessageId: item.lastReadInboxMessageId
      });
      return;
    }
    router.pushUrl({
      url: 'pages/ChatPage',
      params: {
        chatId: item.id,
        title: item.title,
        avatarPath: item.avatarPath,
        avatarFileId: item.avatarFileId,
        category: item.category,
        unreadCount: item.unreadCount,
        lastReadInboxMessageId: item.lastReadInboxMessageId
      }
    });
  }

  private openContacts(): void {
    console.info('[ChatListPage] contacts tab clicked');
    this.activeBottomTab = 'contacts';
    this.statusText = '';
    this.td.getContacts();
  }

  private openSettings(): void {
    console.info('[ChatListPage] settings tab clicked');
    this.activeBottomTab = 'settings';
    this.statusText = '';
    this.td.getMe();
  }

  private openCalls(): void {
    console.info('[ChatListPage] calls tab clicked');
    this.activeBottomTab = 'calls';
    this.statusText = '';
  }

  private openChatsTab(): void {
    console.info('[ChatListPage] chats tab clicked');
    this.activeBottomTab = 'chat';
    this.statusText = '';
    this.requestInitialChats();
  }

  private getActiveTabIndex(): number {
    if (this.activeBottomTab === 'contacts') {
      return 0;
    }
    if (this.activeBottomTab === 'calls') {
      return 1;
    }
    if (this.activeBottomTab === 'settings') {
      return 3;
    }
    return 2;
  }

  private applyBottomTabIndex(index: number): void {
    this.closeContextMenu();
    this.closeSearchOverlay();
    if (index === 0) {
      this.openContacts();
    } else if (index === 1) {
      this.openCalls();
    } else if (index === 3) {
      this.openSettings();
    } else {
      this.openChatsTab();
    }
  }

  private openSearchOverlay(): void {
    console.info('[ChatListPage] miniBar search clicked');
    this.closeContextMenu();
    this.tabsSlideOut = false;
    this.searchVisible = true;
    setTimeout(() => {
      this.tabsSlideOut = true;
    }, 20);
  }

  private closeSearchOverlay(): void {
    if (!this.searchVisible) {
      return;
    }
    console.info('[ChatListPage] close search overlay');
    this.searchVisible = false;
    this.tabsSlideOut = false;
  }

  private triggerHaptic(effectId: string): void {
    vibrator.startVibration({
      type: 'preset',
      effectId: effectId,
      count: 1
    }, {
      usage: 'touch'
    }).catch((error: BusinessError) => {
      console.warn(`[ChatListPage] haptic failed code=${error.code}, message=${error.message}`);
    });
  }

  private triggerLightHaptic(): void {
    this.triggerHaptic(vibrator.HapticFeedback.EFFECT_SOFT);
  }

  private triggerLongPressHaptic(): void {
    this.triggerHaptic(vibrator.HapticFeedback.EFFECT_HARD);
  }

  private clampPosition(value: number, min: number, max: number): number {
    if (max < min) {
      return min;
    }
    if (value < min) {
      return min;
    }
    if (value > max) {
      return max;
    }
    return value;
  }

  private layoutContextMenu(centerX: number, centerY: number): void {
    const previewWidth = 304;
    const previewHeight = 250;
    const menuWidth = 214;
    const menuHeight = 228;
    const gap = 10;
    const sidePadding = 12;
    const topPadding = 70;
    const bottomPadding = 98;
    const layerWidth = this.contextLayerWidth > 0 ? this.contextLayerWidth : 390;
    const layerHeight = this.contextLayerHeight > 0 ? this.contextLayerHeight : 780;
    const maxPreviewLeft = layerWidth - previewWidth - sidePadding;
    const maxPreviewTop = layerHeight - previewHeight - menuHeight - gap - bottomPadding;
    const previewLeft = this.clampPosition(centerX - previewWidth / 2, sidePadding, maxPreviewLeft);
    const previewTop = this.clampPosition(centerY - previewHeight / 2, topPadding, maxPreviewTop);

    this.contextPreviewLeft = previewLeft;
    this.contextPreviewTop = previewTop;
    this.contextMenuLeft = this.clampPosition(centerX - menuWidth / 2, sidePadding, layerWidth - menuWidth - sidePadding);
    this.contextMenuTop = previewTop + previewHeight + gap;
  }

  private openContextMenu(item: ChatItem, centerX: number, centerY: number): void {
    console.info(`[ChatListPage] long press menu open chatId=${item.id}, title=${item.title}, x=${centerX}, y=${centerY}`);
    this.triggerLongPressHaptic();
    this.contextChat = item;
    this.contextPreviewChatId = item.id;
    this.contextPreviewLoading = true;
    this.contextPreviewMessages = this.getPreviewPlaceholders(item);
    this.layoutContextMenu(centerX, centerY);
    this.contextPreviewScale = 0.82;
    this.contextPreviewOpacity = 1;
    this.contextPreviewTranslateY = 14;
    this.contextMenuScale = 0.9;
    this.contextMenuOpacity = 0;
    this.contextMenuTranslateY = 10;
    this.contextMenuVisible = true;
    setTimeout(() => {
      this.contextPreviewScale = 1.06;
      this.contextPreviewTranslateY = 0;
    }, 16);
    setTimeout(() => {
      this.contextMenuScale = 1;
      this.contextMenuOpacity = 1;
      this.contextMenuTranslateY = 0;
    }, 72);
    setTimeout(() => {
      this.contextPreviewScale = 1;
    }, 170);
    this.td.getChatHistory(item.id, 4, 0, 0);
  }

  private closeContextMenu(): void {
    if (!this.contextMenuVisible) {
      return;
    }
    console.info('[ChatListPage] long press menu close');
    this.contextMenuVisible = false;
    this.contextPreviewLoading = false;
    this.contextPreviewChatId = 0;
    this.contextPreviewScale = 0.82;
    this.contextPreviewOpacity = 1;
    this.contextPreviewTranslateY = 14;
    this.contextMenuScale = 0.9;
    this.contextMenuOpacity = 0;
    this.contextMenuTranslateY = 10;
  }

  private handleContextAction(action: string): void {
    console.info(`[ChatListPage] long press action=${action}, chatId=${this.contextChat.id}`);
    this.triggerLightHaptic();
    if (action === 'read' && this.contextChat.id !== 0) {
      this.markChatUnreadCleared(this.contextChat.id);
    } else if (action === 'unpin' && this.contextChat.id !== 0) {
      this.updatePinnedState(this.contextChat.id, false);
    } else if (action === 'pin' && this.contextChat.id !== 0) {
      this.updatePinnedState(this.contextChat.id, true);
    } else if (action === 'group') {
      this.statusText = '已准备加入分组';
    } else if (action === 'mute') {
      this.statusText = '已关闭通知';
    } else if (action === 'delete') {
      this.statusText = '删除操作已触发';
    }
    this.closeContextMenu();
  }

  @Builder
  private ContextAvatar(item: ChatItem, size: number) {
    if (item.avatarPath.length > 0) {
      Image(item.avatarPath)
        .width(size)
        .height(size)
        .borderRadius(size / 2)
        .objectFit(ImageFit.Cover)
        .backgroundColor('#E8F2FF')
    } else {
      Text(item.avatarText)
        .fontSize(size * 0.4)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .textAlign(TextAlign.Center)
        .width(size)
        .height(size)
        .borderRadius(size / 2)
        .backgroundColor(item.avatarColor)
    }
  }

  @Builder
  private PreviewMessageBubble(message: PreviewMessageItem) {
    Row() {
      if (message.isSelf) {
        Blank()
          .layoutWeight(1)
      } else {
        Circle()
          .width(24)
          .height(24)
          .fill('#4486B86E')
          .margin({ right: 6 })
      }

      if (message.placeholder) {
        Row()
          .width(message.isSelf ? 132 : 158)
          .height(30)
          .borderRadius(9)
          .backgroundColor(message.isSelf ? '#86A6CA55' : '#BFFFFFFF')
          .opacity(0.68)
      } else {
        Text(message.text)
          .fontSize(11)
          .fontColor('#182026')
          .lineHeight(16)
          .maxLines(2)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
          .padding({ left: 10, right: 10, top: 6, bottom: 6 })
          .borderRadius(10)
          .backgroundColor(message.isSelf ? '#AEEA8B' : '#F8FFFFFF')
          .constraintSize({ maxWidth: 210 })
      }

      if (!message.isSelf) {
        Blank()
          .layoutWeight(1)
      }
    }
    .width('100%')
    .height(40)
    .padding({ left: 12, right: 12 })
  }

  @Builder
  private ChatPreviewCard(item: ChatItem) {
    Stack({ alignContent: Alignment.TopStart }) {
      Image($r('app.media.phone_bg_01'))
        .width('100%')
        .height('100%')
        .objectFit(ImageFit.Cover)

      Column()
        .width('100%')
        .height('100%')
        .linearGradient({
          direction: GradientDirection.Right,
          colors: [
            ['#56C19E', 0.0],
            ['#8EBADA', 0.52],
            ['#E6E06C', 1.0]
          ]
        })

      Row() {
        Blank()
          .layoutWeight(1)
        Column() {
          Text(item.title.length > 0 ? item.title : '未命名会话')
            .fontSize(13)
            .fontWeight(FontWeight.Bold)
            .fontColor('#111111')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
          Text(this.contextPreviewLoading ? '读取最近消息...' : '最近消息')
            .fontSize(10)
            .fontColor('#7C847D')
        }
        .height(36)
        .width('58%')
        .justifyContent(FlexAlign.Center)
        .alignItems(HorizontalAlign.Center)
        .borderRadius(18)
        .backgroundColor('#EAF8D8')
        .margin({ top: 12 })
        Row() {
          this.ContextAvatar(item, 40)
        }
        .margin({ left: 8, top: 10, right: 16 })
      }
      .width('100%')
      .height(58)

      Column({ space: 6 }) {
        ForEach(this.contextPreviewMessages, (message: PreviewMessageItem) => {
          this.PreviewMessageBubble(message)
        }, (message: PreviewMessageItem): string => message.id)
      }
      .width('100%')
      .margin({ top: 66 })
    }
    .width(304)
    .height(250)
    .borderRadius(22)
    .clip(true)
    .shadow({ radius: 16, color: '#24000000', offsetY: 8 })
  }

  @Builder
  private ContextMenuItem(icon: Resource, label: string, action: string, danger: boolean) {
    Row({ space: 12 }) {
      Image(icon)
        .width(20)
        .height(20)
        .objectFit(ImageFit.Contain)
        .fillColor(danger ? '#FF3B30' : '#111111')
      Text(label)
        .fontSize(15)
        .fontColor(danger ? '#FF3B30' : '#111111')
        .layoutWeight(1)
    }
    .width('100%')
    .height(42)
    .padding({ left: 16, right: 14 })
    .onClick(() => {
      this.handleContextAction(action);
    })
  }

  @Builder
  private ContextMenuPanel() {
    Column() {
      this.ContextMenuItem($r('app.media.addfiles'), '加到分组', 'group', false)
      Divider()
        .strokeWidth(1)
        .color('#D8D8D8')
        .margin({ left: 14, right: 14 })
      this.ContextMenuItem($r('app.media.xiaoxi_yidu'), '标为已读', 'read', false)
      if (this.contextChat.isPinned) {
        this.ContextMenuItem($r('app.media.no_dingzhu'), '取消置顶', 'unpin', false)
      } else {
        this.ContextMenuItem($r('app.media.dingzhu'), '置顶', 'pin', false)
      }
      this.ContextMenuItem($r('app.media.no_tongzhi'), '关闭通知', 'mute', false)
      this.ContextMenuItem($r('app.media.delete'), '删除', 'delete', true)
    }
    .width(190)
    .padding({ top: 8, bottom: 8 })
    .borderRadius(20)
    .backgroundColor('#F7FFFFFF')
    .backgroundBlurStyle(BlurStyle.Thin, {
      colorMode: ThemeColorMode.LIGHT,
      adaptiveColor: AdaptiveColor.AVERAGE,
      scale: 1.0
    })
    .backgroundEffect({
      radius: 24,
      saturation: 1.8,
      brightness: 1.08,
      color: '#ECFFFFFF',
      adaptiveColor: AdaptiveColor.AVERAGE
    })
    .lightUpEffect(0.88)
    .border({ width: 1, color: '#FFFFFFFF' })
  }

  @Builder
  private LongPressContextOverlay() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column()
        .width('100%')
        .height('100%')
        .backgroundColor('#77000000')
        .onClick(() => {
          this.closeContextMenu();
        })

      Column() {
        this.ChatPreviewCard(this.contextChat)
      }
      .width(304)
      .height(250)
      .position({ x: this.contextPreviewLeft, y: this.contextPreviewTop })
      .opacity(this.contextPreviewOpacity)
      .scale({
        x: this.contextPreviewScale,
        y: this.contextPreviewScale,
        centerX: '50%',
        centerY: '50%'
      })
      .translate({ y: this.contextPreviewTranslateY })
      .animation({ duration: 150, curve: Curve.EaseOut })

      Column() {
        this.ContextMenuPanel()
      }
      .width(214)
      .position({ x: this.contextMenuLeft, y: this.contextMenuTop })
      .opacity(this.contextMenuOpacity)
      .scale({
        x: this.contextMenuScale,
        y: this.contextMenuScale,
        centerX: '50%',
        centerY: '0%'
      })
      .translate({ y: this.contextMenuTranslateY })
      .animation({ duration: 140, curve: Curve.EaseOut })
    }
    .width('100%')
    .height('100%')
  }

  @Builder
  private BottomTab(label: string, tabKey: string, normalIcon: Resource, selectedIcon: Resource, badge: number) {
    ChatBottomTabItem({
      label: label,
      tabKey: tabKey,
      activeTab: this.activeBottomTab,
      normalIcon: normalIcon,
      selectedIcon: selectedIcon,
      badge: badge
    })
  }

  @Builder
  private SearchMiniBar() {
    Button({ type: ButtonType.Circle }) {
      Image($r('app.media.bar_search'))
        .width(26)
        .height(26)
        .objectFit(ImageFit.Contain)
    }
    .width(54)
    .height(54)
    .borderRadius(27)
    .backgroundColor('#F7FCFF')
    .linearGradient({
      direction: GradientDirection.Bottom,
      colors: [
        ['#FFFFFFFF', 0.0],
        ['#EAF6FF', 0.46],
        ['#F8FFFFFF', 1.0]
      ]
    })
    .border({ width: 1, color: '#F8FFFFFF' })
    .backdropBlur(18)
    .shadow({ radius: 18, color: '#2A0A84FF', offsetY: 5 })
    .onClick(() => {
      this.openSearchOverlay();
    })
  }

  @Builder
  private TabExitOverlay() {
    Row() {
      this.BottomTab('联系人', 'contacts', $r('app.media.bar_user'), $r('app.media.bar_user_select'), 0)
      this.BottomTab('通话', 'calls', $r('app.media.bar_phone'), $r('app.media.bar_phone_select'), 0)
      Blank()
        .width(68)
      this.BottomTab('Telegram', 'chat', $r('app.media.bar_msg'), $r('app.media.bar_msg_select'), this.getUnreadTotal())
      this.BottomTab('设置', 'settings', $r('app.media.bar_setting'), $r('app.media.bar_setting_select'), 0)
    }
    .width('100%')
    .height(56)
    .padding({ left: 8, right: 8 })
    .borderRadius(28)
    .backgroundColor('#EFFFFFFF')
    .backdropBlur(18)
    .shadow({ radius: 18, color: '#1F000000', offsetY: 6 })
    .translate({ x: this.tabsSlideOut ? -900 : 0 })
    .animation({ duration: 260, curve: Curve.EaseOut })
  }

  @Builder
  private HdsTabsContent() {
    HdsTabs({ index: this.getActiveTabIndex(), controller: this.tabsController }) {
      TabContent() {
        ContactsPage()
      }
      .tabBar(this.BottomTab('联系人', 'contacts', $r('app.media.bar_user'), $r('app.media.bar_user_select'), 0))

      TabContent() {
        CallsContent()
      }
      .tabBar(this.BottomTab('通话', 'calls', $r('app.media.bar_phone'), $r('app.media.bar_phone_select'), 0))

      TabContent() {
        ChatListContent({
          statusText: this.statusText,
          chats: this.getVisibleChats(),
          selectedChatId: this.selectedChatId,
          searchTransition: this.searchVisible,
          chatScroller: this.chatScroller,
          onOpenChat: (chatItem: ChatItem): void => {
            this.openChat(chatItem);
          },
          onLongPressChat: (chatItem: ChatItem, centerX: number, centerY: number): void => {
            this.openContextMenu(chatItem, centerX, centerY);
          },
          onSearchClick: (): void => {
            this.openSearchOverlay();
          },
          onLoadMoreChats: (): void => {
            this.loadMoreChats();
          }
        })
      }
      .tabBar(this.BottomTab('Telegram', 'chat', $r('app.media.bar_msg'), $r('app.media.bar_msg_select'), this.getUnreadTotal()))

      TabContent() {
        ProfilePage()
      }
      .tabBar(this.BottomTab('设置', 'settings', $r('app.media.bar_setting'), $r('app.media.bar_setting_select'), 0))
    }
    .width('100%')
    .height('100%')
    .barPosition(BarPosition.End)
    .barMode(BarMode.Fixed)
    .barHeight(56)
    .barOverlap(true)
    .scrollable(false)
    .animationDuration(0)
    .divider({ mode: DividerMode.NONE })
    .barBackgroundColor(Color.Transparent)
    .barFloatingStyle({
      barSideMargin: 20,
      barBottomMargin: 28,
      // lightColor: '#B3FFFFFF',
      // thermoCtrl: true,
      // barOpacity: this.searchVisible ? 0 : 1,
      // gradientMask: {
      //   maskColor: '#F5FFFFFF',
      //   maskHeight: 74
      // },
      miniBar: {
        miniBarBuilder: () => {
          this.SearchMiniBar()
        },
        miniBarWidth: {
          smallWidth: 66,
          mediumWidth: 72,
          largeWidth: 72
        },
        miniBarStyle: HdsBarStyle.COLLAPSE,
        enableMiniBarBackground: false,
        enableMiniBarClip: false
      },
      systemMaterialEffect: {
        materialType: hdsMaterial.MaterialType.IMMERSIVE,
        materialLevel: hdsMaterial.MaterialLevel.ADAPTIVE
      }
    })
    .onChange((index: number) => {
      console.info(`[ChatListPage] hds bottom tab changed index=${index}`);
      this.applyBottomTabIndex(index);
    })
    .onTabBarClick((index: number) => {
      console.info(`[ChatListPage] hds bottom tab clicked index=${index}`);
      this.triggerLightHaptic();
    })
  }

  build() {
    Stack() {
      Column() {
        this.HdsTabsContent()
      }
      .width('100%')
      .height('100%')
      .backgroundColor(Color.White)

      if (this.searchVisible) {
        Column() {
          this.TabExitOverlay()
        }
        .width('100%')
        .height('100%')
        .justifyContent(FlexAlign.End)
        .padding({ left: 20, right: 20, bottom: 28 })

        ChatSearchOverlay({
          visible: this.searchVisible,
          chats: this.chats,
          selectedChatId: this.selectedChatId,
          onClose: (): void => {
            this.closeSearchOverlay();
          },
          onOpenChat: (item: ChatItem): void => {
            this.openChat(item);
          }
        })
      }

      if (this.contextMenuVisible) {
        this.LongPressContextOverlay()
      }
    }
    .width('100%')
    .height('100%')
    .backgroundColor(Color.White)
    .onAreaChange((oldArea: Area, newArea: Area) => {
      const width = Number(newArea.width);
      const height = Number(newArea.height);
      if (!Number.isNaN(width) && width > 0) {
        this.contextLayerWidth = width;
      }
      if (!Number.isNaN(height) && height > 0) {
        this.contextLayerHeight = height;
      }
    })
  }
}
