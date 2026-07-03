// entry/src/main/ets/features/chat/view/ChatListView.ets
import { TdChat, TdChatNotificationSettings, TdFile, TdMessage, TdlibService, TdUpdate } from '../../../common/service/TdlibService';
import router from '@ohos.router';
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';
import { common } from '@kit.AbilityKit';
import { ContactsPage } from './ContactsView';
import { ProfilePage } from '../../settings/view/ProfileView';
import { ChatBottomTabItem } from '../components/list/ChatBottomTabItem';
import { ChatListContent } from '../components/list/ChatListContent';
import { ChatSearchOverlay } from '../components/list/ChatSearchOverlay';
import { CallsContent } from '../components/list/CallsContent';
import { ChatItem, ChatSelection } from '../model/ChatListModels';
import { CacheResourceItem, ChatDownloadCacheController } from '../viewmodel/ChatDownloadCacheController';
import {
  createChatItem,
  createLoadingChat,
  getAvatarText,
  hasMainChatPosition,
  getLocalPath,
  getMessagePreview,
  getMessageTime,
  isMainChatPosition,
  isPinnedByPosition,
  isPinnedByPositions
} from '../utils/ChatListMappers';
import {
  DividerMode,
  HdsBarStyle,
  HdsTabs,
  HdsTabsController,
  hdsMaterial
} from '@kit.UIDesignKit';
import { curves } from '@kit.ArkUI';
import { AppLayout } from '../../../common/constants/AppLayout';

export { ChatSelection } from '../model/ChatListModels';

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
  @State cacheItems: CacheResourceItem[] = [];
  @State cacheItemsRevision: number = 0;
  @State searchBtnScale: number = 1;
  @State headerStatusText: string = '连接中...';
  @State searchVisible: boolean = false;
  @State tabsSlideOut: boolean = false;
  @State contextMenuVisible: boolean = false;
  @State contextPreviewLoading: boolean = false;
  @State contextPreviewMessages: PreviewMessageItem[] = [];
  @State contextOverlayOpacity: number = 0;
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
  @StorageLink('appDarkMode') isDarkMode: boolean = false;
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
    avatarFileId: 0,
    notificationsMuted: false,
    version: 0
  };
  embedded: boolean = false;
  selectedChatId: number = 0;
  onChatSelected: (selection: ChatSelection) => void = (selection: ChatSelection): void => {};
  private td = TdlibService.getInstance();
  private listenersRegistered: boolean = false;
  private listenerDisposers: (() => void)[] = [];
  private cacheController: ChatDownloadCacheController = ChatDownloadCacheController.getInstance();
  private cacheItemsListener: (items: CacheResourceItem[]) => void = (items: CacheResourceItem[]): void => {
    this.cacheItems = items;
    this.cacheItemsRevision += 1;
  };
  private listenerDisposeToken: number = 0;
  private requestedChatIds: Set<number> = new Set();
  private chatScroller: Scroller = new Scroller();
  private tabsController: HdsTabsController = new HdsTabsController();
  private chatRequestLimit: number = 100;
  private contextCloseToken: number = 0;
  private searchMiniBarAnimationToken: number = 0;
  private chatLoadMoreInFlight: boolean = false;
  private chatAutoFillAttempts: number = 0;
  private contextPreviewChatId: number = 0;
  private pinnedStateByChatId: Map<number, boolean> = new Map();
  private pendingChats: ChatItem[] = [];
  private pendingChatsActive: boolean = false;
  private pendingChatsFlushScheduled: boolean = false;
  private chatListDebugLogging: boolean = false;
  private headerStatusCloseToken: number = 0;
  private chatNavigationInProgress: boolean = false;
  private chatNavigationToken: number = 0;
  private bottomTabClickIndex: number = -1;

  aboutToAppear() {
    this.chatNavigationInProgress = false;
    this.listenerDisposeToken++;
    this.cacheController.setContext(getContext(this) as common.UIAbilityContext);
    this.cacheController.registerTdlibListeners();
    this.cacheController.subscribe(this.cacheItemsListener);
    this.registerListeners();
    this.requestInitialChats();
  }

  aboutToDisappear() {
    const disposeToken = ++this.listenerDisposeToken;
    setTimeout(() => {
      if (this.listenerDisposeToken !== disposeToken) {
        return;
      }
      this.listenerDisposers.forEach((dispose: () => void) => {
        dispose();
      });
      this.cacheController.unsubscribe(this.cacheItemsListener);
      this.listenerDisposers = [];
      this.listenersRegistered = false;
      this.requestedChatIds.clear();
      this.pendingChats = [];
      this.pendingChatsActive = false;
      this.pendingChatsFlushScheduled = false;
    }, 1200);
  }

  private requestInitialChats(): void {
    this.chatRequestLimit = 100;
    this.chatLoadMoreInFlight = false;
    this.chatAutoFillAttempts = 0;
    this.showHeaderUpdatingIfEmpty();
    console.info(`[ChatListPage] request initial chats limit=${this.chatRequestLimit}`);
    this.td.loadChats(this.chatRequestLimit);
    setTimeout(() => {
      this.td.getChats(this.chatRequestLimit);
    }, 500);
  }

  private scheduleHeaderStatusClose(delay: number = 900): void {
    const token = ++this.headerStatusCloseToken;
    setTimeout(() => {
      if (token === this.headerStatusCloseToken && this.activeBottomTab === 'chat') {
        this.headerStatusText = '';
      }
    }, delay);
  }

  private showHeaderUpdatingIfEmpty(): void {
    if (this.getChatsSnapshot().length > 0) {
      return;
    }
    if (this.headerStatusText !== '数据更新中...') {
      this.headerStatusText = '数据更新中...';
    }
  }

  private loadMoreChats(): void {
    if (this.chatLoadMoreInFlight) {
      return;
    }
    this.chatLoadMoreInFlight = true;
    this.chatRequestLimit += 100;
    console.info(`[ChatListPage] load more chats limit=${this.chatRequestLimit}`);
    this.td.loadChats(100);
    setTimeout(() => {
      this.td.getChats(this.chatRequestLimit);
    }, 650);
  }

  private registerListeners(): void {
    if (this.listenersRegistered) {
      return;
    }
    this.listenersRegistered = true;
    this.listenUpdate('authorizationStateReady', (_update: TdUpdate) => {
      console.info('[ChatListPage] authorization ready');
      this.showHeaderUpdatingIfEmpty();
      this.requestInitialChats();
    });
    this.listenUpdate('chats', (update: TdUpdate) => {
      const chatIds: number[] = update.chat_ids ? update.chat_ids : [];
      console.info(`[ChatListPage] received chats count=${chatIds.length}`);
      this.showHeaderUpdatingIfEmpty();
      this.chatLoadMoreInFlight = false;
      this.applyChatIds(chatIds);
      if (this.activeBottomTab === 'chat' && chatIds.length < this.chatRequestLimit && this.chatAutoFillAttempts < 3) {
        this.chatAutoFillAttempts += 1;
        setTimeout(() => {
          this.loadMoreChats();
        }, 350);
      }
      this.requestMissingChatDetails(chatIds);
      this.scheduleMissingChatRetry(chatIds);
      this.scheduleHeaderStatusClose();
    });
    this.listenUpdate('chat', (update: TdUpdate) => {
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
          positions: update.positions,
          notification_settings: update.notification_settings
        };
        this.logChatListDebug(`[ChatListPage] received chat id=${chat.id}, title=${chat.title}`);
        this.upsertChat(chat);
      }
    });
    this.listenUpdate('updateNewChat', (update: TdUpdate) => {
      if (update.chat) {
        this.logChatListDebug(`[ChatListPage] received updateNewChat id=${update.chat.id}, title=${update.chat.title}`);
        this.upsertChat(update.chat);
      }
    });
    this.listenUpdate('updateChatTitle', (update: TdUpdate) => {
      if (update.chat_id !== undefined && update.title !== undefined) {
        this.logChatListDebug(`[ChatListPage] received updateChatTitle id=${update.chat_id}, title=${update.title}`);
        this.updateChatTitle(update.chat_id, update.title);
      }
    });
    this.listenUpdate('updateChatLastMessage', (update: TdUpdate) => {
      if (update.chat_id !== undefined) {
        this.logChatListDebug(`[ChatListPage] received updateChatLastMessage id=${update.chat_id}`);
        this.ensureChatPlaceholder(update.chat_id);
        this.updateChatLastMessage(update.chat_id, update.last_message);
      }
    });
    this.listenUpdate('updateChatNotificationSettings', (update: TdUpdate) => {
      if (update.chat_id !== undefined && update.notification_settings !== undefined) {
        this.updateChatNotificationSettings(update.chat_id, update.notification_settings);
      }
    });
    this.listenUpdate('updateChatReadInbox', (update: TdUpdate) => {
      if (update.chat_id !== undefined && update.unread_count !== undefined) {
        this.logChatListDebug(`[ChatListPage] received updateChatReadInbox id=${update.chat_id}, unread=${update.unread_count}`);
        this.updateUnreadCount(update.chat_id, update.unread_count, update.last_read_inbox_message_id);
      }
    });
    this.listenUpdate('updateChatPosition', (update: TdUpdate) => {
      if (update.chat_id !== undefined) {
        this.logChatListDebug(`[ChatListPage] received updateChatPosition id=${update.chat_id}, position=${JSON.stringify(update.position)}, positions=${JSON.stringify(update.positions)}`);
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
    this.listenUpdate('file', (update: TdUpdate) => {
      if (update.file) {
        this.logChatListDebug(`[ChatListPage] received file id=${update.file.id}`);
        this.applyAvatarFileUpdate(update.file);
      }
    });
    this.listenUpdate('updateFile', (update: TdUpdate) => {
      if (update.file) {
        this.logChatListDebug(`[ChatListPage] received updateFile id=${update.file.id}`);
        this.applyAvatarFileUpdate(update.file);
      }
    });
    this.listenUpdate('messages', (update: TdUpdate) => {
      this.applyContextPreviewMessages(update.messages ? update.messages : []);
    });
  }

  private listenUpdate(type: string, callback: (update: TdUpdate) => void): void {
    this.td.onUpdate(type, callback);
    this.listenerDisposers.push(() => {
      this.td.offUpdate(type, callback);
    });
  }

  private logChatListDebug(message: string): void {
    if (this.chatListDebugLogging) {
      console.info(message);
    }
  }

  private toggleCacheDownload(fileId: number): void {
    const item = this.cacheItems.find((value: CacheResourceItem): boolean => value.fileId === fileId);
    if (!item) {
      return;
    }
    if (item.status === 'paused') {
      this.cacheController.resume(fileId);
    } else if (item.status !== 'completed') {
      this.cacheController.pause(fileId);
    }
  }

  private deleteCacheDownload(fileId: number): void {
    this.cacheController.remove(fileId);
  }

  private openCacheItem(item: CacheResourceItem): void {
    this.cacheController.open(item);
  }

  private getChatsSnapshot(): ChatItem[] {
    return this.pendingChatsActive ? this.mergeResolvedChats(this.chats, this.pendingChats) : this.chats;
  }

  private preferResolvedChatItem(left: ChatItem | undefined, right: ChatItem | undefined): ChatItem | undefined {
    if (!left) {
      return right;
    }
    if (!right) {
      return left;
    }
    const leftPlaceholder = this.isChatPlaceholder(left);
    const rightPlaceholder = this.isChatPlaceholder(right);
    if (leftPlaceholder && !rightPlaceholder) {
      return right;
    }
    if (!leftPlaceholder && rightPlaceholder) {
      return left;
    }
    return right.version !== undefined && left.version !== undefined && right.version > left.version ? right : left;
  }

  private mergeResolvedChats(baseChats: ChatItem[], nextChats: ChatItem[]): ChatItem[] {
    const baseMap: Map<number, ChatItem> =
      new Map(baseChats.map((item: ChatItem): [number, ChatItem] => [item.id, item]));
    return nextChats.map((item: ChatItem): ChatItem => {
      return this.preferResolvedChatItem(baseMap.get(item.id), item)!;
    });
  }

  private commitChats(nextChats: ChatItem[], immediate: boolean = false): void {
    const deduped = this.dedupeChats(this.mergeResolvedChats(this.chats, nextChats));
    if (deduped.length > 0 && this.headerStatusText === '数据更新中...') {
      this.headerStatusText = '';
    }
    if (immediate) {
      this.pendingChats = [];
      this.pendingChatsActive = false;
      this.pendingChatsFlushScheduled = false;
      if (this.areSameChatReferences(this.chats, deduped)) {
        return;
      }
      this.chats = deduped;
      return;
    }
    if (!this.pendingChatsActive && this.areSameChatReferences(this.chats, deduped)) {
      return;
    }
    if (this.pendingChatsActive && this.areSameChatReferences(this.pendingChats, deduped)) {
      return;
    }
    this.pendingChats = deduped;
    this.pendingChatsActive = true;
    this.schedulePendingChatsFlush(this.chatNavigationInProgress ? 260 : 80);
  }

  private areSameChatReferences(left: ChatItem[], right: ChatItem[]): boolean {
    if (left.length !== right.length) {
      return false;
    }
    for (let index = 0; index < left.length; index++) {
      if (left[index] !== right[index]) {
        return false;
      }
    }
    return true;
  }

  private areSameChatIds(left: ChatItem[], right: ChatItem[]): boolean {
    if (left.length !== right.length) {
      return false;
    }
    for (let index = 0; index < left.length; index++) {
      if (left[index].id !== right[index].id) {
        return false;
      }
    }
    return true;
  }

  private schedulePendingChatsFlush(delay: number): void {
    if (this.pendingChatsFlushScheduled) {
      return;
    }
    this.pendingChatsFlushScheduled = true;
    setTimeout(() => {
      this.flushPendingChats();
    }, delay);
  }

  private flushPendingChats(): void {
    this.pendingChatsFlushScheduled = false;
    if (!this.pendingChatsActive) {
      return;
    }
    if (this.chatNavigationInProgress) {
      this.schedulePendingChatsFlush(180);
      return;
    }
    const nextChats = this.mergeResolvedChats(this.chats, this.pendingChats);
    this.pendingChats = [];
    this.pendingChatsActive = false;
    if (this.areSameChatReferences(this.chats, nextChats)) {
      return;
    }
    this.chats = nextChats;
  }

  private applyChatIds(chatIds: number[]): void {
    const nextChats: ChatItem[] = [];
    const seenIds: Set<number> = new Set();
    const currentMap: Map<number, ChatItem> =
      new Map(this.chats.map((item: ChatItem): [number, ChatItem] => [item.id, item]));
    const pendingMap: Map<number, ChatItem> =
      new Map(this.pendingChats.map((item: ChatItem): [number, ChatItem] => [item.id, item]));
    chatIds.forEach((id: number) => {
      if (seenIds.has(id)) {
        console.warn(`[ChatListPage] skip duplicate chat id from getChats id=${id}`);
        return;
      }
      seenIds.add(id);
      const existing = this.preferResolvedChatItem(currentMap.get(id), pendingMap.get(id));
      if (existing) {
        nextChats.push(existing);
      } else {
        nextChats.push(createLoadingChat(id));
      }
    });
    if (this.areSameChatIds(this.getChatsSnapshot(), nextChats)) {
      return;
    }
    this.commitChats(nextChats, true);
  }

  private requestMissingChatDetails(chatIds: number[]): void {
    chatIds.forEach((id: number) => {
      const current = this.findChat(id);
      if (current && !this.isChatPlaceholder(current)) {
        return;
      }
      if (this.requestedChatIds.has(id)) {
        return;
      }
      this.requestedChatIds.add(id);
      this.td.getChat(id);
    });
  }

  private scheduleMissingChatRetry(chatIds: number[]): void {
    const ids = chatIds.slice();
    setTimeout(() => {
      const missingIds: number[] = [];
      ids.forEach((id: number) => {
        const current = this.findChat(id);
        if (!current || this.isChatPlaceholder(current)) {
          missingIds.push(id);
          this.requestedChatIds.delete(id);
        }
      });
      if (missingIds.length === 0) {
        return;
      }
      console.warn(`[ChatListPage] retry missing chat details count=${missingIds.length}`);
      this.requestMissingChatDetails(missingIds);
    }, 1600);
  }

  private isChatPlaceholder(item: ChatItem): boolean {
    return item.title === `Chat ${item.id}` || item.lastMessage === '加载中...' || item.avatarText === 'C';
  }

  private nextChatVersion(item: ChatItem): number {
    return (item.version !== undefined ? item.version : 0) + 1;
  }

  private isChatItemContentEqual(left: ChatItem, right: ChatItem): boolean {
    return left.id === right.id &&
      left.title === right.title &&
      left.lastMessage === right.lastMessage &&
      left.timeText === right.timeText &&
      left.unreadCount === right.unreadCount &&
      left.lastReadInboxMessageId === right.lastReadInboxMessageId &&
      left.isOutgoing === right.isOutgoing &&
      left.isRead === right.isRead &&
      left.isPinned === right.isPinned &&
      left.category === right.category &&
      left.avatarText === right.avatarText &&
      left.avatarColor === right.avatarColor &&
      left.avatarPath === right.avatarPath &&
      left.avatarFileId === right.avatarFileId &&
      left.notificationsMuted === right.notificationsMuted;
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
    this.logChatListDebug(`[ChatListPage] create placeholder for loaded chat id=${chatId}`);
    const nextChats = this.getChatsSnapshot().slice();
    nextChats.push(createLoadingChat(chatId));
    this.commitChats(nextChats);
    if (!this.requestedChatIds.has(chatId)) {
      this.requestedChatIds.add(chatId);
      this.td.getChat(chatId);
    }
  }

  private upsertChat(chat: TdChat): void {
    this.prepareChatAvatar(chat);
    const nextChats = this.getChatsSnapshot().slice();
    const index = nextChats.findIndex((current: ChatItem): boolean => current.id === chat.id);
    const item: ChatItem = createChatItem(chat);
    const pinnedFromMainPosition = hasMainChatPosition(chat.positions);
    const cachedPinned = this.pinnedStateByChatId.get(chat.id);
    const shouldPreservePinned = !pinnedFromMainPosition;
    const preservedPinned = cachedPinned !== undefined ? cachedPinned : (index >= 0 ? nextChats[index].isPinned : item.isPinned);
    const nextItem: ChatItem = shouldPreservePinned ? {
      id: item.id,
      title: item.title,
      lastMessage: item.lastMessage,
      timeText: item.timeText,
      unreadCount: item.unreadCount,
      lastReadInboxMessageId: item.lastReadInboxMessageId,
      isOutgoing: item.isOutgoing,
      isRead: item.isRead,
      isPinned: preservedPinned,
      category: item.category,
      avatarText: item.avatarText,
      avatarColor: item.avatarColor,
      avatarPath: item.avatarPath,
      avatarFileId: item.avatarFileId,
      notificationsMuted: item.notificationsMuted,
      version: index >= 0 ? this.nextChatVersion(nextChats[index]) : 1
    } : item;
    if (!shouldPreservePinned && index >= 0) {
      nextItem.version = this.nextChatVersion(nextChats[index]);
    }
    if (pinnedFromMainPosition) {
      this.pinnedStateByChatId.set(chat.id, nextItem.isPinned);
    }
    this.requestedChatIds.delete(chat.id);
    this.cacheController.setChatMuted(chat.id, nextItem.notificationsMuted);
    this.cacheController.setChatTitle(chat.id, nextItem.title);
    this.logChatListDebug(`[ChatListPage] upsert chat id=${chat.id}, pinned=${nextItem.isPinned}, rawPositions=${JSON.stringify(chat.positions)}, preservePinned=${shouldPreservePinned}`);
    if (index >= 0) {
      if (this.isChatItemContentEqual(nextChats[index], nextItem)) {
        this.scheduleHeaderStatusClose();
        return;
      }
      nextChats[index] = nextItem;
    } else {
      nextChats.push(nextItem);
    }
    this.commitChats(nextChats);
    this.scheduleHeaderStatusClose();
  }

  private updateChatTitle(chatId: number, title: string): void {
    this.cacheController.setChatTitle(chatId, title);
    const nextChats = this.getChatsSnapshot().slice();
    const index = nextChats.findIndex((current: ChatItem): boolean => current.id === chatId);
    if (index >= 0) {
      if (nextChats[index].title === title) {
        return;
      }
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
        avatarFileId: nextChats[index].avatarFileId,
        notificationsMuted: nextChats[index].notificationsMuted,
        version: this.nextChatVersion(nextChats[index])
      };
      this.commitChats(nextChats);
    }
  }

  private updateChatLastMessage(chatId: number, message: TdMessage | undefined): void {
    const nextChats = this.getChatsSnapshot().slice();
    const index = nextChats.findIndex((current: ChatItem): boolean => current.id === chatId);
    if (index >= 0) {
      const lastMessage = getMessagePreview(message);
      const timeText = getMessageTime(message);
      const isOutgoing = message ? message.is_outgoing : false;
      if (nextChats[index].lastMessage === lastMessage && nextChats[index].timeText === timeText &&
        nextChats[index].isOutgoing === isOutgoing) {
        return;
      }
      nextChats[index] = {
        id: nextChats[index].id,
        title: nextChats[index].title,
        lastMessage: lastMessage,
        timeText: timeText,
        unreadCount: nextChats[index].unreadCount,
        lastReadInboxMessageId: nextChats[index].lastReadInboxMessageId,
        isOutgoing: isOutgoing,
        isRead: nextChats[index].isRead,
        isPinned: nextChats[index].isPinned,
        category: nextChats[index].category,
        avatarText: nextChats[index].avatarText,
        avatarColor: nextChats[index].avatarColor,
        avatarPath: nextChats[index].avatarPath,
        avatarFileId: nextChats[index].avatarFileId,
        notificationsMuted: nextChats[index].notificationsMuted,
        version: this.nextChatVersion(nextChats[index])
      };
      this.commitChats(nextChats);
    }
  }

  private updateUnreadCount(chatId: number, unreadCount: number, lastReadInboxMessageId: number | undefined = undefined): void {
    const nextChats = this.getChatsSnapshot().slice();
    const index = nextChats.findIndex((current: ChatItem): boolean => current.id === chatId);
    if (index >= 0) {
      const nextLastReadInboxMessageId =
        lastReadInboxMessageId !== undefined ? lastReadInboxMessageId : nextChats[index].lastReadInboxMessageId;
      if (nextChats[index].unreadCount === unreadCount &&
        nextChats[index].lastReadInboxMessageId === nextLastReadInboxMessageId) {
        return;
      }
      nextChats[index] = {
        id: nextChats[index].id,
        title: nextChats[index].title,
        lastMessage: nextChats[index].lastMessage,
        timeText: nextChats[index].timeText,
        unreadCount: unreadCount,
        lastReadInboxMessageId: nextLastReadInboxMessageId,
        isOutgoing: nextChats[index].isOutgoing,
        isRead: nextChats[index].isRead,
        isPinned: nextChats[index].isPinned,
        category: nextChats[index].category,
        avatarText: nextChats[index].avatarText,
        avatarColor: nextChats[index].avatarColor,
        avatarPath: nextChats[index].avatarPath,
        avatarFileId: nextChats[index].avatarFileId,
        notificationsMuted: nextChats[index].notificationsMuted,
        version: this.nextChatVersion(nextChats[index])
      };
      this.commitChats(nextChats);
    }
  }

  private markChatUnreadCleared(chatId: number): void {
    console.info(`[ChatListPage] clear unread badge locally chatId=${chatId}`);
    this.updateUnreadCount(chatId, 0);
  }

  private updateChatNotificationSettings(chatId: number, settings: TdChatNotificationSettings): void {
    const muted = settings.mute_for !== undefined && settings.mute_for > 0;
    this.cacheController.setChatMuted(chatId, muted);
    const nextChats = this.getChatsSnapshot().slice();
    const index = nextChats.findIndex((current: ChatItem): boolean => current.id === chatId);
    if (index < 0 || nextChats[index].notificationsMuted === muted) {
      return;
    }
    nextChats[index] = {
      id: nextChats[index].id,
      title: nextChats[index].title,
      lastMessage: nextChats[index].lastMessage,
      timeText: nextChats[index].timeText,
      unreadCount: nextChats[index].unreadCount,
      lastReadInboxMessageId: nextChats[index].lastReadInboxMessageId,
      isOutgoing: nextChats[index].isOutgoing,
      isRead: nextChats[index].isRead,
      isPinned: nextChats[index].isPinned,
      category: nextChats[index].category,
      avatarText: nextChats[index].avatarText,
      avatarColor: nextChats[index].avatarColor,
      avatarPath: nextChats[index].avatarPath,
      avatarFileId: nextChats[index].avatarFileId,
      notificationsMuted: muted,
      version: this.nextChatVersion(nextChats[index])
    };
    this.commitChats(nextChats);
  }

  private updatePinnedState(chatId: number, isPinned: boolean): void {
    this.pinnedStateByChatId.set(chatId, isPinned);
    const nextChats = this.getChatsSnapshot().slice();
    const index = nextChats.findIndex((current: ChatItem): boolean => current.id === chatId);
    if (index >= 0) {
      if (nextChats[index].isPinned === isPinned) {
        return;
      }
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
        avatarFileId: nextChats[index].avatarFileId,
        notificationsMuted: nextChats[index].notificationsMuted,
        version: this.nextChatVersion(nextChats[index])
      };
      this.commitChats(nextChats);
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
    const currentChats = this.getChatsSnapshot();
    const changedIndexes: number[] = [];
    currentChats.forEach((item: ChatItem, index: number) => {
      if (item.avatarFileId === file.id && item.avatarPath !== path) {
        changedIndexes.push(index);
      }
    });
    if (changedIndexes.length === 0) {
      return;
    }
    const nextChats: ChatItem[] = currentChats.slice();
    changedIndexes.forEach((index: number) => {
      const item = nextChats[index];
      nextChats[index] = {
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
        avatarFileId: item.avatarFileId,
        notificationsMuted: item.notificationsMuted,
        version: this.nextChatVersion(item)
      };
    });
    this.logChatListDebug(`[ChatListPage] apply avatar file update fileId=${file.id}, changed=${changedIndexes.length}`);
    this.commitChats(nextChats);
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
    this.contextPreviewMessages = previewItems.slice(Math.max(0, previewItems.length - 5));
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
    while (items.length < 5) {
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
    return this.getChatsSnapshot().find((current: ChatItem): boolean => current.id === chatId);
  }

  private getVisibleChats(): ChatItem[] {
    const chats = this.getChatsSnapshot();
    if (this.activeCategory === '全部') {
      return chats;
    }
    return chats.filter((item: ChatItem): boolean => item.category === this.activeCategory);
  }

  private getUnreadTotal(): number {
    let count = 0;
    this.getChatsSnapshot().forEach((item: ChatItem) => {
      count += item.unreadCount;
    });
    return count;
  }

  private openChat(item: ChatItem): void {
    console.info(`[ChatListPage] chat item clicked chatId=${item.id}, title=${item.title}`);
    console.error(`[ChatDetailDiag] openChat embedded=${this.embedded}, chatId=${item.id}, title=${item.title}`);
    if (this.embedded) {
      this.closeContextMenu();
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
    this.beginChatNavigation();
    router.pushUrl({
      url: 'features/chat/view/ChatDetailView',
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

  private beginChatNavigation(): void {
    const token = ++this.chatNavigationToken;
    this.chatNavigationInProgress = true;
    if (this.contextMenuVisible) {
      this.closeContextMenu();
    }
    setTimeout(() => {
      if (token !== this.chatNavigationToken) {
        return;
      }
      this.chatNavigationInProgress = false;
      this.flushPendingChats();
    }, 700);
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
    const previewHeight = 400;
    const menuWidth = 214;
    const menuHeight = 228;
    const gap = 10;
    const sidePadding = 12;
    const topPadding = 70;
    const bottomPadding = AppLayout.BOTTOM_SAFE_HEIGHT + 70;
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
    this.contextCloseToken++;
    this.contextChat = item;
    this.contextPreviewChatId = item.id;
    this.contextPreviewLoading = true;
    this.contextPreviewMessages = this.getPreviewPlaceholders(item);
    this.layoutContextMenu(centerX, centerY);
    this.contextOverlayOpacity = 0;
    this.contextPreviewScale = 0.82;
    this.contextPreviewOpacity = 0;
    this.contextPreviewTranslateY = 14;
    this.contextMenuScale = 0.9;
    this.contextMenuOpacity = 0;
    this.contextMenuTranslateY = 10;
    this.contextMenuVisible = true;
    setTimeout(() => {
      this.contextOverlayOpacity = 1;
      this.contextPreviewOpacity = 1;
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
    const closeToken = ++this.contextCloseToken;
    this.contextOverlayOpacity = 0;
    this.contextPreviewOpacity = 0;
    this.contextPreviewScale = 0.86;
    this.contextPreviewTranslateY = 14;
    this.contextMenuScale = 0.9;
    this.contextMenuOpacity = 0;
    this.contextMenuTranslateY = 10;
    setTimeout(() => {
      if (this.contextCloseToken !== closeToken) {
        return;
      }
      this.contextMenuVisible = false;
      this.contextOverlayOpacity = 0;
      this.contextPreviewScale = 0.82;
      this.contextPreviewOpacity = 1;
      this.contextPreviewTranslateY = 14;
      this.contextMenuScale = 0.9;
      this.contextMenuOpacity = 0;
      this.contextMenuTranslateY = 10;
      this.contextPreviewLoading = false;
      this.contextPreviewChatId = 0;
    }, 170);
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
    } else if (action === 'mute' && this.contextChat.id !== 0) {
      this.td.setChatNotificationMute(this.contextChat.id, 2147483647);
      this.updateChatNotificationSettings(this.contextChat.id, { mute_for: 2147483647, use_default_mute_for: false });
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
      if (this.isDarkMode) {
        Image($r('app.media.phone_bg_04'))
          .width('100%')
          .height('100%')
          .objectFit(ImageFit.Cover)
      } else {
        Image($r('app.media.phone_bg_01'))
          .width('100%')
          .height('100%')
          .objectFit(ImageFit.Cover)
      }

      Column()
        .width('100%')
        .height('100%')
        .backgroundColor('#00FFFFFF')

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
            .width('80%')
            .textAlign(TextAlign.Center)
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
    .height(400)
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
    .backgroundColor('#FFFFFF')
    .border({ width: 1, color: '#FFFFFFFF' })
  }

  @Builder
  private LongPressContextOverlay() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column()
        .width('100%')
        .height('100%')
        .backgroundColor('#18696969')
        .backdropBlur(100)
        .opacity(this.contextOverlayOpacity)
        .animation({ duration: 150, curve: Curve.EaseOut })
        .onClick(() => {
          this.closeContextMenu();
        })

      Column() {
        this.ChatPreviewCard(this.contextChat)
      }
      .width(304)
      .height(400)
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
  private BottomTab(label: string, tabKey: string, normalIcon: Resource, selectedIcon: Resource) {
    ChatBottomTabItem({
      label: label,
      tabKey: tabKey,
      activeTab: this.activeBottomTab,
      normalIcon: normalIcon,
      selectedIcon: selectedIcon
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
    .width(56)
    .height(56)
    .borderRadius(32)
    .backgroundColor('#F7FCFF')
    .scale({
      x: this.searchBtnScale,
      y: this.searchBtnScale,
      centerX: '50%',
      centerY: '50%'
    })
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
    .animation({
      duration: 260,
      curve: curves.interpolatingSpring(8, 1, 260, 18)
    })
    .onTouch((event: TouchEvent) => {
      if (event.type === TouchType.Down) {
        this.searchBtnScale = 1.1;
      } else if (event.type === TouchType.Up || event.type === TouchType.Cancel) {
        this.searchBtnScale = 1;
      }
    })
    .onClick(() => {
      // setTimeout(() => {
        this.openSearchOverlay();
      // }, 120);
    })
  }

  @Builder
  private TabExitOverlay() {
    Row() {
      this.BottomTab('联系人', 'contacts', $r('app.media.bar_user'), $r('app.media.bar_user_select'))
      this.BottomTab('通话', 'calls', $r('app.media.bar_phone'), $r('app.media.bar_phone_select'))
      Blank()
        .width(68)
      this.BottomTab('聊天', 'chat', $r('app.media.bar_msg'), $r('app.media.bar_msg_select'))
      this.BottomTab('设置', 'settings', $r('app.media.bar_setting'), $r('app.media.bar_setting_select'))
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
      .tabBar(this.BottomTab('联系人', 'contacts', $r('app.media.bar_user'), $r('app.media.bar_user_select')))

      TabContent() {
        CallsContent()
      }
      .tabBar(this.BottomTab('通话', 'calls', $r('app.media.bar_phone'), $r('app.media.bar_phone_select')))

      TabContent() {
        ChatListContent({
          statusText: this.statusText,
          headerStatusText: this.headerStatusText,
          chats: this.getVisibleChats(),
          cacheItems: this.cacheItems,
          cacheItemsRevision: this.cacheItemsRevision,
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
          },
          onToggleCacheDownload: (fileId: number): void => {
            this.toggleCacheDownload(fileId);
          },
          onDeleteCacheDownload: (fileId: number): void => {
            this.deleteCacheDownload(fileId);
          },
          onOpenCacheItem: (item: CacheResourceItem): void => {
            this.openCacheItem(item);
          }
        })
      }
      .tabBar(this.BottomTab('聊天', 'chat', $r('app.media.bar_msg'), $r('app.media.bar_msg_select')))

      TabContent() {
        ProfilePage()
      }
      .tabBar(this.BottomTab('设置', 'settings', $r('app.media.bar_setting'), $r('app.media.bar_setting_select')))
    }
    .width('100%')
    .height('100%')
    .barPosition(BarPosition.End)
    .barMode(BarMode.Fixed)
    .vertical(false)
    .barHeight(56)
    .barOverlap(true)
    .scrollable(false)
    .animationDuration(0)
    .divider({ mode: DividerMode.NONE })
    .barBackgroundColor(Color.Transparent)
    .barFloatingStyle({
      barSideMargin: 20,
      barBottomMargin: AppLayout.FLOATING_TAB_BOTTOM,
      // 渐变蒙层
      gradientMask: { maskColor: '#66F1F3F5', maskHeight: 92 },
      systemMaterialEffect: {
        materialType: hdsMaterial.MaterialType.IMMERSIVE,
        materialLevel: hdsMaterial.MaterialLevel.ADAPTIVE
      },
      // miniBar: {
      //   miniBarBuilder: () => {
      //     this.SearchMiniBar()
      //   },
      //   miniBarWidth: {
      //     smallWidth: 66,
      //     mediumWidth: 72,
      //     largeWidth: 72
      //   },
      //   miniBarStyle: HdsBarStyle.COLLAPSE,
      //   // 迷你栏背景跟随页签栏
      //   enableMiniBarBackground: true,
      //   // 必须裁剪内容，否则折叠时内部文字仍可能露出，看起来就像没有收回。
      //   enableMiniBarClip: true
      // }
    })
    .onChange((index: number) => {
      console.info(`[ChatListPage] hds bottom tab changed index=${index}`);
      if (index === this.getActiveTabIndex()) {
        return;
      }
      if (index === this.bottomTabClickIndex) {
        this.bottomTabClickIndex = -1;
        this.applyBottomTabIndex(index);
        return;
      }
      console.warn(`[ChatListPage] ignore non-user tab change index=${index}, active=${this.activeBottomTab}`);
    })
    .onTabBarClick((index: number) => {
      console.info(`[ChatListPage] hds bottom tab clicked index=${index}`);
      this.bottomTabClickIndex = index;
      this.applyBottomTabIndex(index);
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
        .padding({ left: 20, right: 20, bottom: AppLayout.BOTTOM_SAFE_HEIGHT })

        ChatSearchOverlay({
          visible: this.searchVisible,
          chats: this.getChatsSnapshot(),
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
