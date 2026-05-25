// entry/src/main/ets/pages/ChatPage.ets
import {
  FormattedText,
  TdBotCommand,
  TdChat,
  TdAudio,
  TdAnimation,
  TdDocument,
  TdFile,
  TdInlineKeyboardButton,
  TdMessage,
  TdMessageContent,
  TdMessageReplyTo,
  TdPhoto,
  TdPhotoSize,
  TdReplyMarkup,
  TdTextEntity,
  TdlibService,
  TdUpdate,
  TdVideo
} from '../common/service/TdlibService';
import { GalleryService } from '../common/service/GalleryService';
import { common, Want } from '@kit.AbilityKit';
import { KeyboardAvoidMode, window } from '@kit.ArkUI';
import router from '@ohos.router';
import { AppLayout } from '../common/constants/AppLayout';

interface ChatRouteParams {
  chatId?: number | string;
  messageId?: number | string;
  title?: string;
  avatarPath?: string;
  avatarFileId?: number | string;
  category?: string;
  unreadCount?: number | string;
  lastReadInboxMessageId?: number | string;
}

interface VideoRouteParams {
  chatId: number;
  messageId: number;
  fileId: number;
  videoPath: string;
  previewUri: string;
  title: string;
  subtitle: string;
  description: string;
  fileSize: number;
  downloadedSize: number;
  duration: number;
  videoWidth: number;
  videoHeight: number;
}

interface MessageItem {
  id: number;
  mediaAlbumId: number;
  isSelf: boolean;
  isTarget: boolean;
  mediaType: string;
  mediaFormat: string;
  text: string;
  textRows: MessageTextRow[];
  replyText: string;
  replyMessageId: number;
  buttonRows: MessageButtonItem[][];
  photoPath: string;
  videoPath: string;
  thumbnailPath: string;
  photoFileId: number;
  videoFileId: number;
  thumbnailFileId: number;
  documentFileId: number;
  documentFileName: string;
  documentSize: number;
  audioFileId: number;
  audioPath: string;
  audioTitle: string;
  audioPerformer: string;
  audioDuration: number;
  audioDownloadedSize: number;
  audioExpectedSize: number;
  videoDownloadedSize: number;
  videoExpectedSize: number;
  videoCanPlay: boolean;
  videoDuration: number;
  mediaWidth: number;
  mediaHeight: number;
  dateText: string;
  viewCount: number;
}

interface MessageGroupItem {
  id: string;
  anchorId: number;
  isAlbum: boolean;
  items: MessageItem[];
}

interface MessageTextRow {
  id: string;
  text: string;
  url: string;
}

interface MessageButtonItem {
  id: string;
  text: string;
  type: string;
  url: string;
  data: string;
}

interface InlineVideoTimeItem {
  id: number;
  remaining: number;
}

interface BotMenuCommandItem {
  id: string;
  command: string;
  description: string;
}

interface ReplyKeyboardButtonItem {
  id: string;
  text: string;
}

interface StartAbilityError {
  code?: number;
  message?: string;
}

@Entry
@Component
export struct ChatPage {
  @State messages: MessageItem[] = [];
  @State input: string = '';
  @State chatId: number = 0;
  @State targetMessageId: number = 0;
  @State statusText: string = '加载中...';
  @State historyLoading: boolean = false;
  @State hasMoreHistory: boolean = true;
  @State showImageSaveButton: boolean = false;
  @State pendingImageSavePath: string = '';
  @State chatTitle: string = '电报';
  @State chatSubtitle: string = '';
  @State chatAvatarPath: string = '';
  @State chatAvatarText: string = '?';
  @State chatAvatarFileId: number = 0;
  @State inlineVideoTimes: InlineVideoTimeItem[] = [];
  @State unreadCount: number = 0;
  @State unreadAnchorMessageId: number = 0;
  @State lastReadInboxMessageId: number = 0;
  @State hasMoreNewerHistory: boolean = false;
  @State isChannelChat: boolean = false;
  @State channelNotificationsPaused: boolean = false;
  @State botMenuCommands: BotMenuCommandItem[] = [];
  @State botMenuVisible: boolean = false;
  @State botMenuSheetHeight: number = 250;
  @State replyKeyboardRows: ReplyKeyboardButtonItem[][] = [];
  @State replyKeyboardOneTime: boolean = false;
  @State keyboardHeight: number = 0;
  @State pinnedMessageId: number = 0;
  @State pinnedMessageText: string = '';
  @State imagePreviewVisible: boolean = false;
  @State imagePreviewPath: string = '';
  @State imagePreviewOpacity: number = 0;
  @State imagePreviewScale: number = 0.92;
  @State playingAudioMessageId: number = 0;
  @StorageLink('appDarkMode') isDarkMode: boolean = false;
  initialChatId: number = 0;
  initialMessageId: number = 0;
  initialTitle: string = '';
  initialAvatarPath: string = '';
  initialAvatarFileId: number = 0;
  initialCategory: string = '';
  initialUnreadCount: number = 0;
  initialLastReadInboxMessageId: number = 0;
  embedded: boolean = false;
  private messageCache: Map<number, MessageItem> = new Map();
  private messageScroller: Scroller = new Scroller();
  private td = TdlibService.getInstance();
  private listenersRegistered: boolean = false;
  private listenerDisposers: (() => void)[] = [];
  private historyMode: string = 'replace';
  private historyRequestSource: string = 'latest';
  private historyFallbackTried: boolean = false;
  private emptyHistoryRetryCount: number = 0;
  private entryUnreadCount: number = 0;
  private prependAnchorMessageId: number = 0;
  private botInfoRequestedUserId: number = 0;
  private botMenuDragStartHeight: number = 250;
  private botMenuMinSheetHeight: number = 250;
  private botMenuMaxSheetHeight: number = 360;
  private keyboardWindow: window.Window | null = null;
  private keyboardWillShowCallback = (info: window.KeyboardInfo): void => {
    const heightVp = this.getUIContext().px2vp(info.endRect.height);
    this.keyboardHeight = Math.max(0, heightVp);
    console.info(`[ChatPage] keyboard will show heightVp=${this.keyboardHeight}`);
    this.scheduleScrollToLatestAt(false, 260);
  };
  private keyboardWillHideCallback = (_info: window.KeyboardInfo): void => {
    this.keyboardHeight = 0;
    console.info('[ChatPage] keyboard will hide');
  };
  private requestedMediaFileIds: Set<number> = new Set();
  private requestedVisibleMediaMessageIds: Set<number> = new Set();
  private visibleReadMessageIds: Set<number> = new Set();
  private pendingReadMessageIds: Set<number> = new Set();
  private readFlushScheduled: boolean = false;
  private readLoadedScheduled: boolean = false;

  aboutToAppear() {
    this.readRouteParams();
    this.setupKeyboardAvoidance();
    this.registerListeners();
    if (this.chatId !== 0) {
      this.td.openChat(this.chatId);
      if (this.targetMessageId !== 0) {
        this.loadHistoryAroundMessage(this.targetMessageId);
      } else {
        this.refreshHistory();
      }
    } else {
      this.statusText = '会话参数错误';
      console.error('[ChatPage] chatId is invalid');
    }
  }

  aboutToDisappear() {
    this.markLoadedUnreadMessagesRead();
    this.flushVisibleReads();
    if (this.chatId !== 0) {
      this.td.closeChat(this.chatId);
      this.td.getChat(this.chatId);
    }
    this.disposeListeners();
    this.teardownKeyboardAvoidance();
  }

  private listenUpdate(type: string, callback: (update: TdUpdate) => void): void {
    this.td.onUpdate(type, callback);
    this.listenerDisposers.push(() => {
      this.td.offUpdate(type, callback);
    });
  }

  private disposeListeners(): void {
    this.listenerDisposers.forEach((dispose: () => void) => {
      dispose();
    });
    this.listenerDisposers = [];
    this.listenersRegistered = false;
  }

  private setupKeyboardAvoidance(): void {
    try {
      this.getUIContext().setKeyboardAvoidMode(KeyboardAvoidMode.NONE);
      const context = getContext(this) as common.UIAbilityContext;
      window.getLastWindow(context).then((mainWindow: window.Window) => {
        this.keyboardWindow = mainWindow;
        mainWindow.on('keyboardWillShow', this.keyboardWillShowCallback);
        mainWindow.on('keyboardWillHide', this.keyboardWillHideCallback);
        console.info('[ChatPage] keyboard avoidance mode set to NONE');
      }).catch((err: StartAbilityError) => {
        console.error(`[ChatPage] getLastWindow failed code=${err.code}, message=${err.message}`);
      });
    } catch (err) {
      const error = err as StartAbilityError;
      console.error(`[ChatPage] setup keyboard avoidance failed code=${error.code}, message=${error.message}`);
    }
  }

  private teardownKeyboardAvoidance(): void {
    this.keyboardHeight = 0;
    if (this.keyboardWindow) {
      try {
        this.keyboardWindow.off('keyboardWillShow', this.keyboardWillShowCallback);
        this.keyboardWindow.off('keyboardWillHide', this.keyboardWillHideCallback);
      } catch (err) {
        const error = err as StartAbilityError;
        console.error(`[ChatPage] remove keyboard listener failed code=${error.code}, message=${error.message}`);
      }
      this.keyboardWindow = null;
    }
    try {
      this.getUIContext().setKeyboardAvoidMode(KeyboardAvoidMode.OFFSET);
    } catch (err) {
      const error = err as StartAbilityError;
      console.error(`[ChatPage] restore keyboard avoidance failed code=${error.code}, message=${error.message}`);
    }
  }

  private readRouteParams(): void {
    if (this.initialChatId !== 0) {
      this.chatId = this.initialChatId;
      this.targetMessageId = this.initialMessageId;
      if (this.initialTitle.length > 0) {
        this.chatTitle = this.initialTitle;
        this.chatAvatarText = this.getAvatarText(this.initialTitle);
      }
      if (this.initialAvatarPath.length > 0) {
        this.chatAvatarPath = this.initialAvatarPath;
      }
      if (this.initialAvatarFileId !== 0) {
        this.chatAvatarFileId = this.initialAvatarFileId;
      }
      if (this.initialCategory.length > 0) {
        this.chatSubtitle = this.getChatSubtitle(this.initialCategory);
        this.isChannelChat = this.initialCategory === '频道';
      }
      if (this.initialUnreadCount > 0) {
        this.unreadCount = this.initialUnreadCount;
      }
      this.entryUnreadCount = this.initialUnreadCount;
      if (this.initialLastReadInboxMessageId > 0) {
        this.lastReadInboxMessageId = this.initialLastReadInboxMessageId;
      }
      console.info(`[ChatPage] initial params chatId=${this.chatId}, messageId=${this.targetMessageId}, title=${this.chatTitle}`);
      return;
    }
    const params = router.getParams() as ChatRouteParams;
    if (params && params.chatId !== undefined) {
      this.chatId = Number(params.chatId);
    }
    if (params && params.messageId !== undefined) {
      this.targetMessageId = Number(params.messageId);
    }
    if (params && params.title !== undefined) {
      this.chatTitle = params.title;
      this.chatAvatarText = this.getAvatarText(params.title);
    }
    if (params && params.avatarPath !== undefined) {
      this.chatAvatarPath = params.avatarPath;
    }
    if (params && params.avatarFileId !== undefined) {
      this.chatAvatarFileId = Number(params.avatarFileId);
    }
    if (params && params.category !== undefined) {
      this.chatSubtitle = this.getChatSubtitle(params.category);
      this.isChannelChat = params.category === '频道';
    }
    if (params && params.unreadCount !== undefined) {
      this.unreadCount = Number(params.unreadCount);
    }
    this.entryUnreadCount = this.unreadCount;
    if (params && params.lastReadInboxMessageId !== undefined) {
      this.lastReadInboxMessageId = Number(params.lastReadInboxMessageId);
    }
    console.info(`[ChatPage] route params chatId=${this.chatId}, messageId=${this.targetMessageId}, title=${this.chatTitle}`);
  }

  private registerListeners(): void {
    if (this.listenersRegistered) {
      return;
    }
    this.listenersRegistered = true;
    this.listenUpdate('messages', (update: TdUpdate) => {
      const historyMessages: TdMessage[] = update.messages ? update.messages : [];
      console.info(`[ChatPage] received messages count=${historyMessages.length}, mode=${this.historyMode}`);
      const nextMessages: MessageItem[] = [];
      historyMessages.slice().reverse().forEach((message: TdMessage) => {
        if (this.isCurrentChatMessage(message)) {
          nextMessages.push(this.toMessageItem(message));
        }
      });
      if (this.historyMode === 'replace' && nextMessages.length === 0 &&
        this.historyRequestSource === 'unread' && !this.historyFallbackTried) {
        this.historyFallbackTried = true;
        this.historyRequestSource = 'latest';
        this.statusText = '正在加载最新消息...';
        console.info(`[ChatPage] unread locate returned empty, fallback latest chatId=${this.chatId}`);
        this.td.getChatHistory(this.chatId, 20, 0, 0);
        return;
      }
      if (this.historyMode === 'replace' && nextMessages.length === 0 &&
        this.historyRequestSource === 'latest' && this.emptyHistoryRetryCount < 2) {
        this.emptyHistoryRetryCount += 1;
        this.statusText = '正在重新加载消息...';
        console.info(`[ChatPage] latest history empty, retry=${this.emptyHistoryRetryCount}, chatId=${this.chatId}`);
        setTimeout(() => {
          this.td.getChatHistory(this.chatId, this.getInitialHistoryLimit(), 0, 0);
        }, 80);
        return;
      }
      if (nextMessages.length > 0) {
        this.emptyHistoryRetryCount = 0;
      }
      if (this.historyMode === 'prepend') {
        const beforeCount = this.messages.length;
        const newestLoadedMessageId = nextMessages.length > 0 ? nextMessages[nextMessages.length - 1].id : 0;
        this.mergeMessages(nextMessages);
        this.hasMoreHistory = this.messages.length > beforeCount;
        this.restoreScrollAfterPrepend(newestLoadedMessageId, this.prependAnchorMessageId);
      } else if (this.historyMode === 'append') {
        const beforeCount = this.messages.length;
        this.mergeMessages(nextMessages);
        this.refreshReplyKeyboardFromMessages(historyMessages);
        this.prefetchInitialMessageMedia();
        this.hasMoreNewerHistory = this.messages.length > beforeCount && nextMessages.length >= this.getInitialHistoryLimit();
      } else {
        this.messages = this.resolveReplyTexts(this.sortMessages(nextMessages));
        this.refreshReplyKeyboardFromMessages(historyMessages);
        this.prefetchInitialMessageMedia();
        this.hasMoreHistory = nextMessages.length > 0;
        this.hasMoreNewerHistory = this.historyRequestSource === 'unread' && this.entryUnreadCount > 0;
        if (this.targetMessageId === 0) {
          if (this.entryUnreadCount > 0) {
            this.unreadAnchorMessageId = this.findUnreadAnchorMessageId();
            if (this.unreadAnchorMessageId !== 0) {
              this.scheduleScrollToUnread(false);
            } else {
              this.scheduleScrollToLatest(false);
            }
          } else {
            this.scheduleScrollToLatest(false);
          }
        }
        this.scheduleMarkLoadedUnreadMessagesRead();
      }
      this.historyLoading = false;
      this.statusText = this.messages.length > 0 ? '' : '暂无消息';
      this.historyMode = 'append';
    });
    this.listenUpdate('chat', (update: TdUpdate) => {
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
        reply_markup_message_id: update.reply_markup_message_id,
        notification_settings: update.notification_settings
      };
      console.info(`[ChatPage] received chat title=${chat.title}, id=${chat.id}`);
      this.applyChatInfo(chat);
    });
    this.listenUpdate('updateNewMessage', (update: TdUpdate) => {
      const message: TdMessage | undefined = update.message;
      if (!message || !this.isCurrentChatMessage(message)) {
        return;
      }
      console.info(`[ChatPage] received updateNewMessage id=${message.id}, chatId=${message.chat_id}`);
      const item = this.toMessageItem(message);
      this.upsertMessage(item);
      this.applyReplyKeyboardFromMessage(message);
      this.requestMessageItemMedia(item);
      if (!message.is_outgoing) {
        this.unreadCount += 1;
      }
    });
    this.listenUpdate('updateMessageContent', (update: TdUpdate) => {
      if (update.chat_id === this.chatId && update.message_id !== undefined && update.new_content) {
        console.info(`[ChatPage] received updateMessageContent messageId=${update.message_id}`);
        this.applyMessageContentUpdate(update.message_id, update.new_content);
      }
    });
    this.listenUpdate('updateMessageEdited', (update: TdUpdate) => {
      if (update.chat_id === this.chatId && update.message_id !== undefined) {
        console.info(`[ChatPage] received updateMessageEdited messageId=${update.message_id}`);
        this.applyReplyMarkupUpdate(update.message_id, update.reply_markup);
      }
    });
    this.listenUpdate('updateChatPinnedMessage', (update: TdUpdate) => {
      if (update.chat_id !== this.chatId || update.message_id === undefined) {
        return;
      }
      this.pinnedMessageId = update.message_id;
      if (this.pinnedMessageId > 0) {
        console.info(`[ChatPage] request updated pinned message chatId=${this.chatId}, messageId=${this.pinnedMessageId}`);
        this.td.getMessage(this.chatId, this.pinnedMessageId);
      } else {
        this.pinnedMessageText = '';
      }
    });
    this.listenUpdate('updateChatReplyMarkup', (update: TdUpdate) => {
      const message: TdMessage | undefined = update.reply_markup_message;
      if (update.chat_id === this.chatId) {
        if (message) {
          console.info(`[ChatPage] received updateChatReplyMarkup messageId=${message.id}`);
          this.upsertMessage(this.toMessageItem(message));
          this.applyReplyKeyboardFromMessage(message);
        } else {
          console.info(`[ChatPage] received updateChatReplyMarkup clear chatId=${this.chatId}`);
          this.clearReplyKeyboard();
        }
      }
    });
    this.listenUpdate('message', (update: TdUpdate) => {
      const message = update as TdMessage;
      if (!this.isCurrentChatMessage(message)) {
        return;
      }
      console.info(`[ChatPage] received direct message id=${message.id}, chatId=${message.chat_id}`);
      this.messageCache.delete(message.id);
      this.upsertMessage(this.toMessageItem(message));
      if (message.is_pinned === true || (this.pinnedMessageId !== 0 && message.id === this.pinnedMessageId)) {
        this.applyPinnedMessage(message);
      }
      this.applyReplyKeyboardFromMessage(message);
    });
    this.listenUpdate('callbackQueryAnswer', (update: TdUpdate) => {
      console.info(`[ChatPage] received callbackQueryAnswer text=${update.text}, url=${update.url}`);
      if (update.url && update.url.length > 0) {
        this.openUrl(update.url);
      } else if (update.text && update.text.length > 0) {
        this.statusText = update.text;
      }
    });
    this.listenUpdate('userFullInfo', (update: TdUpdate) => {
      const commands: TdBotCommand[] = this.extractBotCommands(update);
      console.info(`[ChatPage] received userFullInfo requestedUserId=${this.botInfoRequestedUserId}, botInfo=${update.bot_info !== undefined}, commands=${commands.length}`);
      this.applyBotCommands(commands);
    });
    this.listenUpdate('updateUserFullInfo', (update: TdUpdate) => {
      if (update.user_id !== this.botInfoRequestedUserId) {
        console.info(`[ChatPage] ignore updateUserFullInfo userId=${update.user_id}, requested=${this.botInfoRequestedUserId}`);
        return;
      }
      const commands: TdBotCommand[] = this.extractBotCommands(update);
      console.info(`[ChatPage] received updateUserFullInfo userId=${update.user_id}, nestedBotInfo=${update.user_full_info && update.user_full_info.bot_info !== undefined}, commands=${commands.length}`);
      this.applyBotCommands(commands);
    });
    this.listenUpdate('messageLinkInfo', (update: TdUpdate) => {
      const message: TdMessage | undefined = update.message;
      const targetChatId = update.chat_id !== undefined ? update.chat_id : (message && message.chat_id !== undefined ? message.chat_id : 0);
      const targetMessageId = message ? message.id : 0;
      console.info(`[ChatPage] received messageLinkInfo chatId=${targetChatId}, messageId=${targetMessageId}`);
      if (targetChatId !== 0 && targetMessageId !== 0) {
        router.pushUrl({ url: 'pages/ChatPage', params: { chatId: targetChatId, messageId: targetMessageId } });
      } else {
        this.statusText = '无法定位这条消息';
      }
    });
    this.listenUpdate('file', (update: TdUpdate) => {
      if (update.file) {
        console.info(`[ChatPage] received file id=${update.file.id}`);
        this.applyFileUpdate(update.file);
      }
    });
    this.listenUpdate('updateFile', (update: TdUpdate) => {
      if (update.file) {
        console.info(`[ChatPage] received updateFile id=${update.file.id}`);
        this.applyFileUpdate(update.file);
      }
    });
  }

  private isCurrentChatMessage(message: TdMessage): boolean {
    return message.chat_id === undefined || message.chat_id === this.chatId;
  }

  private markMessagesRead(messages: TdMessage[]): void {
    const messageIds: number[] = [];
    messages.forEach((message: TdMessage) => {
      if (this.isCurrentChatMessage(message) && !message.is_outgoing) {
        messageIds.push(message.id);
      }
    });
    if (messageIds.length === 0) {
      return;
    }
    console.info(`[ChatPage] mark messages read chatId=${this.chatId}, count=${messageIds.length}`);
    this.td.viewMessages(this.chatId, messageIds, true);
  }

  private scheduleMarkLoadedUnreadMessagesRead(): void {
    if (this.readLoadedScheduled || this.entryUnreadCount <= 0) {
      return;
    }
    this.readLoadedScheduled = true;
    setTimeout(() => {
      this.readLoadedScheduled = false;
      this.markLoadedUnreadMessagesRead();
    }, 700);
  }

  private markLoadedUnreadMessagesRead(): void {
    if (this.chatId === 0 || this.messages.length === 0) {
      return;
    }
    const ids: number[] = [];
    let maxMessageId = this.lastReadInboxMessageId;
    this.messages.forEach((message: MessageItem) => {
      if (!message.isSelf && message.id > this.lastReadInboxMessageId) {
        ids.push(message.id);
        maxMessageId = Math.max(maxMessageId, message.id);
      }
    });
    if (ids.length === 0) {
      return;
    }
    console.info(`[ChatPage] mark loaded unread messages read chatId=${this.chatId}, count=${ids.length}`);
    this.td.viewMessages(this.chatId, ids, true);
    this.lastReadInboxMessageId = maxMessageId;
    this.unreadCount = 0;
    this.unreadAnchorMessageId = 0;
    this.entryUnreadCount = 0;
    this.td.getChat(this.chatId);
  }

  private markVisibleMessageRead(message: MessageItem): void {
    if (message.isSelf || message.id <= this.lastReadInboxMessageId || this.visibleReadMessageIds.has(message.id)) {
      return;
    }
    this.visibleReadMessageIds.add(message.id);
    console.info(`[ChatPage] visible message read chatId=${this.chatId}, messageId=${message.id}`);
    this.pendingReadMessageIds.add(message.id);
    this.scheduleFlushVisibleReads();
    this.lastReadInboxMessageId = Math.max(this.lastReadInboxMessageId, message.id);
    if (this.unreadCount > 0) {
      this.unreadCount = Math.max(0, this.unreadCount - 1);
      if (this.unreadCount === 0) {
        this.unreadAnchorMessageId = 0;
      }
    }
  }

  private scheduleFlushVisibleReads(): void {
    if (this.readFlushScheduled) {
      return;
    }
    this.readFlushScheduled = true;
    setTimeout(() => {
      this.flushVisibleReads();
    }, 180);
  }

  private flushVisibleReads(): void {
    this.readFlushScheduled = false;
    if (this.pendingReadMessageIds.size === 0) {
      return;
    }
    const ids: number[] = [];
    this.pendingReadMessageIds.forEach((id: number) => {
      ids.push(id);
    });
    this.pendingReadMessageIds.clear();
    console.info(`[ChatPage] flush visible reads chatId=${this.chatId}, count=${ids.length}`);
    this.td.viewMessages(this.chatId, ids, true);
  }

  private refreshHistory(): void {
    if (this.historyLoading || this.chatId === 0) {
      return;
    }
    this.historyLoading = true;
    this.historyMode = 'replace';
    this.historyFallbackTried = false;
    this.emptyHistoryRetryCount = 0;
    this.statusText = this.unreadCount > 0 ? '正在定位未读消息...' : '正在刷新历史消息...';
    console.info(`[ChatPage] refreshHistory chatId=${this.chatId}, unread=${this.unreadCount}, lastReadInbox=${this.lastReadInboxMessageId}`);
    this.td.getChat(this.chatId);
    // 限制初始加载量，避免一次性加载过多消息
    const limit = Math.min(this.getInitialHistoryLimit(), 50); // 最大50条，避免大列表
    if (this.unreadCount > 0 && this.lastReadInboxMessageId > 0) {
      this.historyRequestSource = 'unread';
      this.td.getChatHistory(this.chatId, limit, this.lastReadInboxMessageId, -1);
      //this.td.getChatHistory(this.chatId, this.getInitialHistoryLimit(), this.lastReadInboxMessageId, -1);
      return;
    }
    this.historyRequestSource = 'latest';
    //this.td.getChatHistory(this.chatId, this.getInitialHistoryLimit(), 0, 0);
    this.td.getChatHistory(this.chatId, limit, 0, 0);
  }

  private loadOlderHistory(): void {
    if (this.historyLoading || !this.hasMoreHistory || this.chatId === 0 || this.messages.length === 0) {
      return;
    }
    const oldestMessageId = this.messages[0].id;
    this.prependAnchorMessageId = oldestMessageId;
    this.historyLoading = true;
    this.historyMode = 'prepend';
    this.historyRequestSource = 'older';
    this.statusText = '正在加载更早消息...';
    console.info(`[ChatPage] loadOlderHistory chatId=${this.chatId}, fromMessageId=${oldestMessageId}`);
    this.td.getChatHistory(this.chatId, 20, oldestMessageId, 0);
  }

  private loadNewerHistory(): void {
    if (this.historyLoading || !this.hasMoreNewerHistory || this.chatId === 0 || this.messages.length === 0) {
      return;
    }
    const newestMessageId = this.messages[this.messages.length - 1].id;
    this.historyLoading = true;
    this.historyMode = 'append';
    this.historyRequestSource = 'newer';
    this.statusText = '正在加载最新消息...';
    console.info(`[ChatPage] loadNewerHistory chatId=${this.chatId}, fromMessageId=${newestMessageId}`);
    this.td.getChatHistory(this.chatId, this.getInitialHistoryLimit(), newestMessageId, -this.getInitialHistoryLimit());
  }

  private loadHistoryAroundMessage(messageId: number): void {
    this.historyLoading = true;
    this.historyMode = 'replace';
    this.historyRequestSource = 'target';
    this.historyFallbackTried = false;
    this.statusText = '正在定位消息...';
    console.info(`[ChatPage] loadHistoryAroundMessage chatId=${this.chatId}, messageId=${messageId}`);
    this.td.openMessageContent(this.chatId, messageId);
    this.td.getChatHistory(this.chatId, 20, messageId, -10);
  }

  private getInitialHistoryLimit(): number {
    return 20;
  }

  private toMessageItem(message: TdMessage): MessageItem {
    if (this.messageCache.has(message.id)) {
      return this.messageCache.get(message.id)!;
    }
    const content: TdMessageContent | undefined = message.content;
    const item: MessageItem = {
      id: message.id,
      mediaAlbumId: message.media_album_id ? message.media_album_id : 0,
      isSelf: message.is_outgoing,
      isTarget: this.targetMessageId !== 0 && message.id === this.targetMessageId,
      mediaType: this.getNormalizedMediaType(content),
      mediaFormat: this.getContentMediaFormat(content),
      text: this.getMessageText(content),
      textRows: this.getMessageTextRows(content),
      replyText: this.getReplyText(message.reply_to),
      replyMessageId: this.getReplyMessageId(message.reply_to),
      buttonRows: this.getMessageButtonRows(message.reply_markup),
      photoPath: '',
      videoPath: '',
      thumbnailPath: '',
      photoFileId: 0,
      videoFileId: 0,
      thumbnailFileId: 0,
      documentFileId: 0,
      documentFileName: '',
      documentSize: 0,
      audioFileId: 0,
      audioPath: '',
      audioTitle: '',
      audioPerformer: '',
      audioDuration: 0,
      audioDownloadedSize: 0,
      audioExpectedSize: 0,
      videoDownloadedSize: 0,
      videoExpectedSize: 0,
      videoCanPlay: false,
      videoDuration: 0,
      mediaWidth: 0,
      mediaHeight: 0,
      dateText: this.getMessageTime(message),
      viewCount: this.getMessageViewCount(message)
    };
    if (content && content.type === 'messagePhoto' && content.photo) {
      const size: TdPhotoSize | undefined = this.getPreviewPhotoSize(content.photo);
      if (size) {
        item.photoFileId = size.photo.id;
        item.photoPath = this.getLocalPath(size.photo);
        item.mediaWidth = size.width;
        item.mediaHeight = size.height;
      }
    }
    if (content && content.type === 'messageVideo' && content.video) {
      const video: TdVideo = content.video;
      item.videoFileId = video.video.id;
      item.videoPath = this.getLocalPath(video.video);
      item.videoDownloadedSize = this.getDownloadedSize(video.video);
      item.videoExpectedSize = this.getExpectedSize(video.video);
      item.videoCanPlay = this.canPlayVideo(video.video);
      item.videoDuration = video.duration ? video.duration : 0;
      item.mediaWidth = video.width ? video.width : 0;
      item.mediaHeight = video.height ? video.height : 0;
      if (video.thumbnail && video.thumbnail.file) {
        item.thumbnailFileId = video.thumbnail.file.id;
        item.thumbnailPath = this.getLocalPath(video.thumbnail.file);
      }
    }
    if (content && content.type === 'messageAnimation' && content.animation) {
      const animation: TdAnimation = content.animation;
      item.videoFileId = animation.animation.id;
      item.videoPath = this.getLocalPath(animation.animation);
      item.videoDownloadedSize = this.getDownloadedSize(animation.animation);
      item.videoExpectedSize = this.getExpectedSize(animation.animation);
      item.videoCanPlay = this.canPlayVideo(animation.animation);
      item.videoDuration = animation.duration ? animation.duration : 0;
      item.mediaWidth = animation.width ? animation.width : 0;
      item.mediaHeight = animation.height ? animation.height : 0;
      if (animation.thumbnail && animation.thumbnail.file) {
        item.thumbnailFileId = animation.thumbnail.file.id;
        item.thumbnailPath = this.getLocalPath(animation.thumbnail.file);
      }
    }
    if (content && content.type === 'messageDocument' && content.document) {
      const document: TdDocument = content.document;
      item.documentFileId = document.document.id;
      item.documentFileName = document.file_name && document.file_name.length > 0 ? document.file_name : '未命名文件';
      item.documentSize = this.getExpectedSize(document.document);
      item.mediaFormat = this.getMediaFormat(document.file_name, document.mime_type, this.getLocalPath(document.document), 'file');
    }
    if (content && content.type === 'messageAudio' && content.audio) {
      this.applyAudioContentToItem(item, content.audio);
    }
    this.messageCache.set(message.id, item);
    return item;
  }

  private applyAudioContentToItem(item: MessageItem, audio: TdAudio): void {
    item.audioFileId = audio.audio.id;
    item.audioPath = this.getLocalPath(audio.audio);
    item.audioTitle = this.getAudioTitle(audio);
    item.audioPerformer = audio.performer && audio.performer.length > 0 ? audio.performer : '音频';
    item.audioDuration = audio.duration ? audio.duration : 0;
    item.audioDownloadedSize = this.getDownloadedSize(audio.audio);
    item.audioExpectedSize = this.getExpectedSize(audio.audio);
    item.mediaFormat = this.getMediaFormat(audio.file_name, audio.mime_type, this.getLocalPath(audio.audio), 'mp3');
    const cover = audio.album_cover_thumbnail && audio.album_cover_thumbnail.file ? audio.album_cover_thumbnail :
      (audio.thumbnail && audio.thumbnail.file ? audio.thumbnail : undefined);
    if (cover && cover.file) {
      item.thumbnailFileId = cover.file.id;
      item.thumbnailPath = this.getLocalPath(cover.file);
      item.mediaWidth = cover.width ? cover.width : 0;
      item.mediaHeight = cover.height ? cover.height : 0;
    }
  }

  private getAudioTitle(audio: TdAudio): string {
    if (audio.title && audio.title.length > 0) {
      return audio.title;
    }
    if (audio.file_name && audio.file_name.length > 0) {
      return audio.file_name;
    }
    return '未知音乐';
  }

  private getNormalizedMediaType(content: TdMessageContent | undefined): string {
    if (!content) {
      return 'unknown';
    }
    if (content.type === 'messageVideo' && content.video) {
      const format = this.getMediaFormat(content.video.file_name, content.video.mime_type, this.getLocalPath(content.video.video), '');
      if (format === 'gif') {
        return 'messageAnimation';
      }
    }
    return content.type;
  }

  private getContentMediaFormat(content: TdMessageContent | undefined): string {
    if (!content) {
      return '';
    }
    if (content.type === 'messagePhoto' && content.photo) {
      const size: TdPhotoSize | undefined = this.getPreviewPhotoSize(content.photo);
      return size ? this.getMediaFormat('', '', this.getLocalPath(size.photo), 'jpg') : 'jpg';
    }
    if (content.type === 'messageVideo' && content.video) {
      return this.getMediaFormat(content.video.file_name, content.video.mime_type, this.getLocalPath(content.video.video), 'mp4');
    }
    if (content.type === 'messageAnimation' && content.animation) {
      return this.getMediaFormat(content.animation.file_name, content.animation.mime_type, this.getLocalPath(content.animation.animation), 'gif');
    }
    if (content.type === 'messageDocument' && content.document) {
      return this.getMediaFormat(content.document.file_name, content.document.mime_type, this.getLocalPath(content.document.document), 'file');
    }
    if (content.type === 'messageAudio' && content.audio) {
      return this.getMediaFormat(content.audio.file_name, content.audio.mime_type, this.getLocalPath(content.audio.audio), 'mp3');
    }
    return '';
  }

  private getMessageFormattedText(content: TdMessageContent | undefined): FormattedText | undefined {
    if (!content) {
      return undefined;
    }
    if (content.type === 'messageText' && content.text) {
      return content.text;
    }
    if ((content.type === 'messagePhoto' || content.type === 'messageVideo' || content.type === 'messageAnimation' ||
      content.type === 'messageDocument' || content.type === 'messageAudio') &&
      content.caption) {
      return content.caption;
    }
    return undefined;
  }

  private getMessageText(content: TdMessageContent | undefined): string {
    if (content && content.type === 'messageDocument' && content.document && content.caption &&
      content.caption.text.length > 0) {
      return content.caption.text;
    }
    const formattedText = this.getMessageFormattedText(content);
    return formattedText ? formattedText.text : '';
  }

  private getMessageViewCount(message: TdMessage): number {
    if (message.interaction_info && message.interaction_info.view_count !== undefined) {
      return message.interaction_info.view_count;
    }
    return 0;
  }

  private getReplyText(replyTo: TdMessageReplyTo | undefined): string {
    if (!replyTo) {
      return '';
    }
    if (replyTo.quote && replyTo.quote.text && replyTo.quote.text.text.length > 0) {
      return replyTo.quote.text.text;
    }
    return '';
  }

  private getReplyMessageId(replyTo: TdMessageReplyTo | undefined): number {
    if (!replyTo || replyTo.message_id === undefined) {
      return 0;
    }
    return replyTo.message_id;
  }

  private getFirstUnreadMessageId(): number {
    if (this.unreadCount <= 0 || this.messages.length === 0) {
      return 0;
    }
    if (this.unreadAnchorMessageId !== 0) {
      return this.unreadAnchorMessageId;
    }
    const startIndex = Math.max(0, this.messages.length - this.unreadCount);
    return this.messages[startIndex].id;
  }

  private findUnreadAnchorMessageId(): number {
    if (this.unreadCount <= 0 || this.messages.length === 0) {
      return 0;
    }
    if (this.lastReadInboxMessageId > 0) {
      const found = this.messages.find((message: MessageItem): boolean => {
        return !message.isSelf && message.id > this.lastReadInboxMessageId;
      });
      if (found) {
        return found.id;
      }
    }
    const startIndex = Math.max(0, this.messages.length - this.unreadCount);
    return this.messages[startIndex].id;
  }

  private getUnreadDisplayText(): string {
    return this.unreadCount > 99 ? '99+' : `${this.unreadCount}`;
  }

  private getTopContentInset(): number {
    return this.pinnedMessageText.length > 0 ? AppLayout.STATUS_BAR_HEIGHT + 110 : AppLayout.STATUS_BAR_HEIGHT + 66;
  }

  private getTopFloatingHeight(): number {
    return this.pinnedMessageText.length > 0 ? AppLayout.STATUS_BAR_HEIGHT + 128 : AppLayout.STATUS_BAR_HEIGHT + 86;
  }

  private getMessageTime(message: TdMessage): string {
    if (!message.date) {
      return '';
    }
    const date = new Date(message.date * 1000);
    return `${this.pad2(date.getHours())}:${this.pad2(date.getMinutes())}`;
  }

  private pad2(value: number): string {
    return value < 10 ? `0${value}` : `${value}`;
  }

  private applyChatInfo(chat: TdChat): void {
    this.chatTitle = chat.title.length > 0 ? chat.title : this.chatTitle;
    this.chatAvatarText = this.getAvatarText(this.chatTitle);
    const category = this.getChatCategory(chat);
    this.isChannelChat = category === '频道';
    if (category !== '个人' || this.chatSubtitle !== '机器人') {
      this.chatSubtitle = this.getChatSubtitle(category);
    }
    if (chat.notification_settings && chat.notification_settings.mute_for !== undefined) {
      this.channelNotificationsPaused = chat.notification_settings.mute_for > 0;
    }
    if (chat.unread_count !== undefined) {
      this.unreadCount = chat.unread_count;
    }
    if (chat.last_read_inbox_message_id !== undefined) {
      this.lastReadInboxMessageId = chat.last_read_inbox_message_id;
    }
    if (chat.photo && chat.photo.small) {
      this.chatAvatarFileId = chat.photo.small.id;
      this.chatAvatarPath = this.getLocalPath(chat.photo.small);
      if (!chat.photo.small.local || !chat.photo.small.local.is_downloading_completed) {
        console.info(`[ChatPage] download chat avatar fileId=${chat.photo.small.id}`);
        this.td.downloadFile(chat.photo.small.id, 8);
      }
    }
    if (this.isChannelChat) {
      this.clearReplyKeyboard();
      this.botMenuVisible = false;
    } else if (chat.reply_markup_message_id && chat.reply_markup_message_id > 0) {
      console.info(`[ChatPage] request reply markup message chatId=${chat.id}, messageId=${chat.reply_markup_message_id}`);
      this.td.getMessage(chat.id, chat.reply_markup_message_id);
    } else {
      this.clearReplyKeyboard();
    }
    console.info(`[ChatPage] request chat pinned message chatId=${chat.id}`);
    this.td.getChatPinnedMessage(chat.id);
    this.requestBotInfoIfNeeded(chat);
  }

  private applyPinnedMessage(message: TdMessage): void {
    this.pinnedMessageId = message.id;
    const item = this.toMessageItem(message);
    const summary = this.getPinnedSummary(item);
    this.pinnedMessageText = summary.length > 0 ? summary : '[消息]';
    console.info(`[ChatPage] apply pinned message id=${message.id}, text=${this.pinnedMessageText}`);
  }

  private getPinnedSummary(item: MessageItem): string {
    if (item.text.length > 0) {
      return item.text;
    }
    if (item.mediaType === 'messagePhoto') {
      return '[图片]';
    }
    if (item.mediaType === 'messageVideo') {
      return '[视频]';
    }
    if (item.mediaType === 'messageAnimation') {
      return '[GIF]';
    }
    if (item.mediaType === 'messageDocument') {
      return item.documentFileName.length > 0 ? `[文件] ${item.documentFileName}` : '[文件]';
    }
    return item.mediaType.length > 0 ? `[${item.mediaType}]` : '';
  }

  private requestBotInfoIfNeeded(chat: TdChat): void {
    if (!chat.type || chat.type.type !== 'chatTypePrivate' || chat.type.user_id === undefined || chat.type.user_id <= 0) {
      this.botInfoRequestedUserId = 0;
      this.botMenuCommands = [];
      this.botMenuVisible = false;
      this.botMenuSheetHeight = this.botMenuMinSheetHeight;
      return;
    }
    if (this.botInfoRequestedUserId === chat.type.user_id) {
      return;
    }
    this.botInfoRequestedUserId = chat.type.user_id;
    console.info(`[ChatPage] request userFullInfo userId=${chat.type.user_id}, chatId=${chat.id}`);
    this.td.getUserFullInfo(chat.type.user_id);
  }

  private extractBotCommands(update: TdUpdate): TdBotCommand[] {
    if (update.bot_info && update.bot_info.commands) {
      return update.bot_info.commands;
    }
    if (update.user_full_info && update.user_full_info.bot_info && update.user_full_info.bot_info.commands) {
      return update.user_full_info.bot_info.commands;
    }
    if (update.commands) {
      return update.commands;
    }
    return [];
  }

  private applyBotCommands(commands: TdBotCommand[]): void {
    const nextCommands: BotMenuCommandItem[] = [];
    commands.forEach((item: TdBotCommand, index: number) => {
      if (item.command.length === 0) {
        return;
      }
      nextCommands.push({
        id: `${item.command}_${index}`,
        command: item.command,
        description: item.description
      });
    });
    this.botMenuCommands = nextCommands;
    this.botMenuVisible = false;
    this.botMenuSheetHeight = this.botMenuMinSheetHeight;
    if (nextCommands.length > 0) {
      this.chatSubtitle = '机器人';
    }
  }

  private sendBotCommand(command: string): void {
    if (command.length === 0) {
      return;
    }
    const text = command.startsWith('/') ? command : `/${command}`;
    console.info(`[ChatPage] bot command clicked chatId=${this.chatId}, command=${text}`);
    this.botMenuVisible = false;
    this.botMenuSheetHeight = this.botMenuMinSheetHeight;
    this.td.sendMessage(this.chatId, text);
  }

  private shouldShowBotMenuButton(): boolean {
    return !this.isChannelChat && this.botMenuCommands.length > 0;
  }

  private setBotMenuVisible(visible: boolean): void {
    this.botMenuVisible = visible;
    if (!visible) {
      this.botMenuSheetHeight = this.botMenuMinSheetHeight;
    }
  }

  private clampBotMenuSheetHeight(height: number): number {
    if (height < this.botMenuMinSheetHeight) {
      return this.botMenuMinSheetHeight;
    }
    if (height > this.botMenuMaxSheetHeight) {
      return this.botMenuMaxSheetHeight;
    }
    return height;
  }

  private getBottomFloatingHeight(): number {
    if (this.isChannelChat) {
      return 52 + AppLayout.BOTTOM_SAFE_HEIGHT + 24;
    }
    const replyKeyboardHeight = this.getReplyKeyboardHeight();
    const baseHeight = AppLayout.CHAT_COMPOSER_HEIGHT + AppLayout.BOTTOM_SAFE_HEIGHT + 24 + replyKeyboardHeight;
    if (!this.botMenuVisible) {
      return baseHeight;
    }
    return this.botMenuSheetHeight + baseHeight;
  }

  private isBotMenuAtMaxHeight(): boolean {
    return this.botMenuSheetHeight >= this.botMenuMaxSheetHeight - 1;
  }

  private getMessageListBottomInset(): number {
    if (this.isChannelChat) {
      return 52 + AppLayout.BOTTOM_SAFE_HEIGHT + 8 + this.keyboardHeight;
    }
    return AppLayout.CHAT_COMPOSER_HEIGHT + AppLayout.BOTTOM_SAFE_HEIGHT + 8 + this.keyboardHeight +
      this.getReplyKeyboardHeight();
  }

  private getReplyKeyboardHeight(): number {
    if (this.replyKeyboardRows.length === 0) {
      return 0;
    }
    const visibleRows = Math.min(this.replyKeyboardRows.length, 4);
    return visibleRows * 38 + 14;
  }

  private refreshReplyKeyboardFromMessages(messages: TdMessage[]): void {
    for (let index = messages.length - 1; index >= 0; index--) {
      if (this.applyReplyKeyboardFromMessage(messages[index])) {
        return;
      }
    }
  }

  private applyReplyKeyboardFromMessage(message: TdMessage): boolean {
    if (message.is_outgoing || !message.reply_markup) {
      return false;
    }
    if (message.reply_markup.type !== 'replyMarkupShowKeyboard') {
      if (message.reply_markup.type === 'replyMarkupRemoveKeyboard') {
        this.clearReplyKeyboard();
      }
      return false;
    }
    this.replyKeyboardRows = this.getReplyKeyboardRows(message.reply_markup);
    this.replyKeyboardOneTime = message.reply_markup.one_time === true;
    console.info(`[ChatPage] apply reply keyboard rows=${this.replyKeyboardRows.length}, oneTime=${this.replyKeyboardOneTime}`);
    return this.replyKeyboardRows.length > 0;
  }

  private clearReplyKeyboard(): void {
    this.replyKeyboardRows = [];
    this.replyKeyboardOneTime = false;
  }

  private getReplyKeyboardRows(replyMarkup: TdReplyMarkup): ReplyKeyboardButtonItem[][] {
    if (!replyMarkup.rows) {
      return [];
    }
    const rows: ReplyKeyboardButtonItem[][] = [];
    replyMarkup.rows.forEach((row: TdInlineKeyboardButton[], rowIndex: number) => {
      const buttons: ReplyKeyboardButtonItem[] = [];
      row.forEach((button: TdInlineKeyboardButton, buttonIndex: number) => {
        if (button.text.length === 0) {
          return;
        }
        buttons.push({
          id: `reply-${rowIndex}-${buttonIndex}-${button.text}`,
          text: button.text
        });
      });
      if (buttons.length > 0) {
        rows.push(buttons);
      }
    });
    return rows;
  }

  private sendReplyKeyboardButton(button: ReplyKeyboardButtonItem): void {
    console.info(`[ChatPage] reply keyboard clicked chatId=${this.chatId}, text=${button.text}`);
    this.td.sendMessage(this.chatId, button.text);
    if (this.replyKeyboardOneTime) {
      this.clearReplyKeyboard();
    }
  }

  private getChatCategory(chat: TdChat): string {
    if (!chat.type) {
      return this.isBotTitle(chat.title) ? '机器人' : '个人';
    }
    if ((chat.type.type === 'chatTypePrivate' || chat.type.type === 'chatTypeSecret') && this.isBotTitle(chat.title)) {
      return '机器人';
    }
    if (chat.type.type === 'chatTypeSupergroup' && chat.type.is_channel) {
      return '频道';
    }
    if (chat.type.type === 'chatTypeBasicGroup' || chat.type.type === 'chatTypeSupergroup') {
      return '群组';
    }
    return '个人';
  }

  private isBotTitle(title: string): boolean {
    const lower = title.toLowerCase();
    return lower.indexOf('bot') >= 0 || title.indexOf('机器人') >= 0;
  }

  private getChatSubtitle(category: string): string {
    if (category === '群组') {
      return '群组会话';
    }
    if (category === '频道') {
      return '频道';
    }
    if (category === '机器人') {
      return '机器人';
    }
    return '在线';
  }

  private getAvatarText(title: string): string {
    const trimmed = title.trim();
    if (trimmed.length === 0) {
      return '?';
    }
    return trimmed.substring(0, 1).toUpperCase();
  }

  private openChatProfile(): void {
    console.info(`[ChatPage] open chat profile chatId=${this.chatId}`);
    router.pushUrl({
      url: 'pages/ChatProfilePage',
      params: {
        chatId: this.chatId,
        title: this.chatTitle,
        avatarPath: this.chatAvatarPath,
        avatarFileId: this.chatAvatarFileId,
        avatarText: this.chatAvatarText,
        avatarColor: '#2F80ED'
      }
    });
  }

  private getMessageTextRows(content: TdMessageContent | undefined): MessageTextRow[] {
    const formattedText = this.getMessageFormattedText(content);
    if (!formattedText || formattedText.text.length === 0) {
      return [];
    }
    const rows: MessageTextRow[] = [];
    let start = 0;
    let rowIndex = 0;
    const text = formattedText.text;
    for (let index = 0; index <= text.length; index++) {
      if (index === text.length || text.charAt(index) === '\n') {
        const line = text.substring(start, index);
        if (line.trim().length > 0) {
          rows.push({
            id: `row-${rowIndex}`,
            text: line,
            url: this.findLineUrl(formattedText, start, index, line)
          });
          rowIndex++;
        }
        start = index + 1;
      }
    }
    return rows;
  }

  private findLineUrl(formattedText: FormattedText, lineStart: number, lineEnd: number, line: string): string {
    const entities: TdTextEntity[] = formattedText.entities ? formattedText.entities : [];
    for (let index = 0; index < entities.length; index++) {
      const entity = entities[index];
      const entityStart = entity.offset;
      const entityEnd = entity.offset + entity.length;
      if (entityEnd <= lineStart || entityStart >= lineEnd) {
        continue;
      }
      if (entity.type.type === 'textEntityTypeTextUrl' && entity.type.url) {
        return entity.type.url;
      }
      if (entity.type.type === 'textEntityTypeUrl') {
        return formattedText.text.substring(entityStart, entityEnd);
      }
    }
    return this.findUrlInText(line);
  }

  private findUrlInText(text: string): string {
    const parts: string[] = text.split(/\s+/);
    for (let index = 0; index < parts.length; index++) {
      const part = this.trimUrlToken(parts[index].trim());
      if (part.startsWith('http://') || part.startsWith('https://') || part.startsWith('tg://') ||
        part.startsWith('t.me/') || part.startsWith('telegram.me/')) {
        return part;
      }
    }
    return '';
  }

  private trimUrlToken(token: string): string {
    let value = token;
    while (value.length > 0 && this.isUrlLeadingTrimChar(value.charAt(0))) {
      value = value.substring(1);
    }
    while (value.length > 0 && this.isUrlTrailingTrimChar(value.charAt(value.length - 1))) {
      value = value.substring(0, value.length - 1);
    }
    return value;
  }

  private isUrlLeadingTrimChar(char: string): boolean {
    return char === '(' || char === '[' || char === '{' || char === '「' || char === '《' || char === '<';
  }

  private isUrlTrailingTrimChar(char: string): boolean {
    return char === ')' || char === ']' || char === '}' || char === '」' || char === '》' ||
      char === '>' || char === ',' || char === '.' || char === ';' || char === ':' ||
      char === '，' || char === '。' || char === '；' || char === '：';
  }

  private extractBotCommandFromText(text: string): string {
    const parts: string[] = text.split(/\s+/);
    for (let index = 0; index < parts.length; index++) {
      const part = this.trimUrlToken(parts[index].trim());
      if (part.startsWith('/') && part.length > 1) {
        return part;
      }
    }
    return '';
  }

  private handleMessageRowClick(msg: MessageItem, row: MessageTextRow): void {
    if (row.url.length > 0) {
      this.openUrl(row.url);
      return;
    }
    if (this.isRobotMessage(msg)) {
      const command = this.extractBotCommandFromText(row.text);
      if (command.length > 0) {
        this.sendBotCommand(command);
      }
    }
  }

  private hasLinkPreviewMessage(msg: MessageItem): boolean {
    if (this.isRobotMessage(msg) || msg.textRows.length > 4) {
      return false;
    }
    return msg.mediaType === 'messageText' && this.getPrimaryLinkUrl(msg).length > 0;
  }

  private getPrimaryLinkUrl(msg: MessageItem): string {
    for (let index = 0; index < msg.textRows.length; index++) {
      if (msg.textRows[index].url.length > 0) {
        return msg.textRows[index].url;
      }
    }
    return this.findUrlInText(msg.text);
  }

  private getLinkPreviewRows(msg: MessageItem): string[] {
    const rows: string[] = [];
    msg.textRows.forEach((row: MessageTextRow) => {
      const text = row.text.trim();
      if (text.length === 0 || row.url.length > 0 || text === this.getPrimaryLinkUrl(msg)) {
        return;
      }
      rows.push(text);
    });
    return rows;
  }

  private getLinkPreviewSite(url: string): string {
    const lowerUrl = url.toLowerCase();
    if (lowerUrl.startsWith('tg://') || lowerUrl.indexOf('t.me/') >= 0 ||
      lowerUrl.indexOf('telegram.me/') >= 0) {
      return 'Telegram';
    }
    const host = this.getLinkHost(url);
    return host.length > 0 ? host : '链接';
  }

  private getLinkPreviewTitle(msg: MessageItem): string {
    const rows = this.getLinkPreviewRows(msg);
    if (rows.length > 0) {
      return rows[0];
    }
    const url = this.getPrimaryLinkUrl(msg);
    const host = this.getLinkHost(url);
    if (host.length > 0) {
      return host;
    }
    return url;
  }

  private getLinkPreviewDescription(msg: MessageItem): string {
    const rows = this.getLinkPreviewRows(msg);
    if (rows.length > 1) {
      return rows.slice(1, 4).join('\n');
    }
    const url = this.getPrimaryLinkUrl(msg);
    if (this.getLinkPreviewSite(url) === 'Telegram') {
      return 'Telegram 链接，点击查看详情';
    }
    return '点击查看链接内容';
  }

  private getLinkHost(url: string): string {
    let value = url.trim();
    if (value.startsWith('tg://')) {
      return 'Telegram';
    }
    const protocolIndex = value.indexOf('://');
    if (protocolIndex >= 0) {
      value = value.substring(protocolIndex + 3);
    }
    const slashIndex = value.indexOf('/');
    if (slashIndex >= 0) {
      value = value.substring(0, slashIndex);
    }
    return value;
  }

  private getMessageButtonRows(replyMarkup: TdReplyMarkup | undefined): MessageButtonItem[][] {
    if (!replyMarkup || replyMarkup.type !== 'replyMarkupInlineKeyboard' || !replyMarkup.rows) {
      return [];
    }
    return replyMarkup.rows.map((row: TdInlineKeyboardButton[], rowIndex: number): MessageButtonItem[] => {
      return row.map((button: TdInlineKeyboardButton, buttonIndex: number): MessageButtonItem => {
        return {
          id: `button-${rowIndex}-${buttonIndex}`,
          text: button.text,
          type: button.type.type,
          url: button.type.url ? button.type.url : '',
          data: button.type.data ? button.type.data : ''
        };
      });
    });
  }

  private getBestPhotoSize(photo: TdPhoto): TdPhotoSize | undefined {
    if (photo.sizes.length === 0) {
      return undefined;
    }
    let best: TdPhotoSize = photo.sizes[0];
    photo.sizes.forEach((size: TdPhotoSize) => {
      if (size.width * size.height > best.width * best.height) {
        best = size;
      }
    });
    return best;
  }

  private getPreviewPhotoSize(photo: TdPhoto): TdPhotoSize | undefined {
    if (photo.sizes.length === 0) {
      return undefined;
    }
    let best: TdPhotoSize = photo.sizes[0];
    photo.sizes.forEach((size: TdPhotoSize) => {
      const bestPixels = best.width * best.height;
      const pixels = size.width * size.height;
      if (pixels <= 900 * 900 && pixels > bestPixels) {
        best = size;
      }
    });
    return best;
  }

  private getLocalPath(file: TdFile): string {
    if (file.local && file.local.path.length > 0) {
      return this.toFileSource(file.local.path);
    }
    return '';
  }

  private getMediaFormat(fileName: string | undefined, mimeType: string | undefined, path: string, fallback: string): string {
    const fromMime = this.getFormatFromMime(mimeType);
    if (fromMime.length > 0) {
      return fromMime;
    }
    const fromName = this.getFormatFromPath(fileName ? fileName : '');
    if (fromName.length > 0) {
      return fromName;
    }
    const fromPath = this.getFormatFromPath(path);
    if (fromPath.length > 0) {
      return fromPath;
    }
    return fallback;
  }

  private getFormatFromMime(mimeType: string | undefined): string {
    if (!mimeType || mimeType.length === 0) {
      return '';
    }
    const value = mimeType.toLowerCase();
    if (value === 'image/jpeg') {
      return 'jpg';
    }
    if (value === 'image/gif') {
      return 'gif';
    }
    const slashIndex = value.indexOf('/');
    if (slashIndex >= 0 && slashIndex < value.length - 1) {
      const tail = value.substring(slashIndex + 1);
      const semiIndex = tail.indexOf(';');
      return this.normalizeFormat(semiIndex >= 0 ? tail.substring(0, semiIndex) : tail);
    }
    return '';
  }

  private getFormatFromPath(path: string): string {
    if (path.length === 0) {
      return '';
    }
    const cleanPath = path.split('?')[0].split('#')[0];
    const dotIndex = cleanPath.lastIndexOf('.');
    if (dotIndex < 0 || dotIndex === cleanPath.length - 1) {
      return '';
    }
    return this.normalizeFormat(cleanPath.substring(dotIndex + 1));
  }

  private normalizeFormat(format: string): string {
    const value = format.toLowerCase();
    if (value === 'jpeg') {
      return 'jpg';
    }
    if (value === 'quicktime') {
      return 'mov';
    }
    if (value === 'x-matroska') {
      return 'mkv';
    }
    return value;
  }

  private getDownloadedSize(file: TdFile): number {
    if (!file.local) {
      return 0;
    }
    if (file.local.downloaded_prefix_size !== undefined && file.local.downloaded_prefix_size > 0) {
      return file.local.downloaded_prefix_size;
    }
    if (file.local.downloaded_size !== undefined) {
      return file.local.downloaded_size;
    }
    return 0;
  }

  private getExpectedSize(file: TdFile): number {
    if (file.size !== undefined && file.size > 0) {
      return file.size;
    }
    if (file.expected_size !== undefined) {
      return file.expected_size;
    }
    return 0;
  }

  private canPlayVideo(file: TdFile): boolean {
    if (!file.local || file.local.path.length === 0) {
      return false;
    }
    if (file.local.is_downloading_completed) {
      return true;
    }
    return this.getDownloadedSize(file) > 0;
  }

  private shouldInlinePlayVideo(msg: MessageItem): boolean {
    return msg.mediaType === 'messageVideo' && msg.videoDuration > 0 && msg.videoDuration <= 10;
  }

  private requestDownloadFileOnce(fileId: number, priority: number): void {
    if (fileId === 0 || this.requestedMediaFileIds.has(fileId)) {
      return;
    }
    this.requestedMediaFileIds.add(fileId);
    console.info(`[ChatPage] lazy download fileId=${fileId}, priority=${priority}`);
    this.td.downloadFile(fileId, priority);
  }

  private requestMessageItemMedia(msg: MessageItem): void {
    if (msg.mediaType === 'messagePhoto') {
      if (msg.photoPath.length === 0) {
        this.requestDownloadFileOnce(msg.photoFileId, 16);
      }
      return;
    }
    if (msg.mediaType === 'messageVideo') {
      if (msg.thumbnailPath.length === 0) {
        this.requestDownloadFileOnce(msg.thumbnailFileId, 12);
      }
      if (this.shouldInlinePlayVideo(msg) && msg.videoPath.length === 0) {
        this.requestDownloadFileOnce(msg.videoFileId, 24);
      }
      return;
    }
    if (msg.mediaType === 'messageAnimation') {
      if (msg.thumbnailPath.length === 0) {
        this.requestDownloadFileOnce(msg.thumbnailFileId, 12);
      }
      if (msg.videoPath.length === 0) {
        this.requestDownloadFileOnce(msg.videoFileId, 24);
      }
      return;
    }
    if (msg.mediaType === 'messageAudio') {
      if (msg.thumbnailPath.length === 0) {
        this.requestDownloadFileOnce(msg.thumbnailFileId, 12);
      }
    }
  }

  private requestVisibleMessageMediaOnce(msg: MessageItem): void {
    if (this.requestedVisibleMediaMessageIds.has(msg.id)) {
      return;
    }
    this.requestedVisibleMediaMessageIds.add(msg.id);
    this.requestMessageItemMedia(msg);
  }

  private prefetchInitialMessageMedia(): void {
    if (this.messages.length === 0) {
      return;
    }
    const start = Math.max(0, this.messages.length - 8);
    this.messages.slice(start).forEach((msg: MessageItem) => {
      this.requestVisibleMessageMediaOnce(msg);
    });
  }

  private openImagePreview(path: string): void {
    if (path.length === 0) {
      this.statusText = '图片还未下载完成';
      return;
    }
    this.imagePreviewPath = path;
    this.imagePreviewOpacity = 0;
    this.imagePreviewScale = 0.92;
    this.imagePreviewVisible = true;
    setTimeout(() => {
      this.imagePreviewOpacity = 1;
      this.imagePreviewScale = 1;
    }, 16);
  }

  private closeImagePreview(): void {
    this.imagePreviewOpacity = 0;
    this.imagePreviewScale = 0.92;
    setTimeout(() => {
      if (this.imagePreviewOpacity !== 0) {
        return;
      }
      this.imagePreviewVisible = false;
      this.imagePreviewPath = '';
    }, 180);
  }

  private getInlineRemainingSeconds(msg: MessageItem): number {
    const found = this.inlineVideoTimes.find((item: InlineVideoTimeItem): boolean => item.id === msg.id);
    if (found) {
      return found.remaining;
    }
    return msg.videoDuration > 0 ? msg.videoDuration : 0;
  }

  private getInlineRemainingText(msg: MessageItem): string {
    const remaining = this.getInlineRemainingSeconds(msg);
    const minute = Math.floor(remaining / 60);
    const second = remaining % 60;
    return `${minute}:${second < 10 ? '0' : ''}${second}`;
  }

  private updateInlineVideoProgress(messageId: number, duration: number, time: number): void {
    if (duration <= 0) {
      return;
    }
    const remaining = Math.max(0, Math.ceil(duration - time));
    const nextItems = this.inlineVideoTimes.filter((item: InlineVideoTimeItem): boolean => item.id !== messageId);
    nextItems.push({ id: messageId, remaining: remaining });
    this.inlineVideoTimes = nextItems;
  }

  private toFileSource(path: string): string {
    if (path.startsWith('file://')) {
      return path;
    }
    return `file://${path}`;
  }

  private prepareMessageMedia(message: TdMessage): void {
    const content: TdMessageContent | undefined = message.content;
    if (!content) {
      return;
    }
    if (content.type === 'messagePhoto' && content.photo) {
      const size: TdPhotoSize | undefined = this.getPreviewPhotoSize(content.photo);
      if (size && (!size.photo.local || !size.photo.local.is_downloading_completed)) {
        console.info(`[ChatPage] download photo fileId=${size.photo.id}, messageId=${message.id}`);
        this.td.downloadFile(size.photo.id);
      }
    }
    if (content.type === 'messageVideo' && content.video) {
      const format = this.getContentMediaFormat(content);
      if (format === 'gif' && (!content.video.video.local || !content.video.video.local.is_downloading_completed)) {
        console.info(`[ChatPage] download gif video fileId=${content.video.video.id}, messageId=${message.id}`);
        this.td.downloadFile(content.video.video.id);
      }
      const duration = content.video.duration ? content.video.duration : 0;
      if (duration > 0 && duration <= 10 && (!content.video.video.local || !content.video.video.local.is_downloading_completed)) {
        console.info(`[ChatPage] download short video fileId=${content.video.video.id}, duration=${duration}, messageId=${message.id}`);
        this.td.downloadFile(content.video.video.id);
      }
      if (content.video.thumbnail && content.video.thumbnail.file) {
        const thumbFile: TdFile = content.video.thumbnail.file;
        if (!thumbFile.local || !thumbFile.local.is_downloading_completed) {
          console.info(`[ChatPage] download video preview thumbnail fileId=${thumbFile.id}, messageId=${message.id}`);
          this.td.downloadFile(thumbFile.id);
        }
      }
    }
    if (content.type === 'messageAnimation' && content.animation) {
      const animationFile: TdFile = content.animation.animation;
      if (!animationFile.local || !animationFile.local.is_downloading_completed) {
        console.info(`[ChatPage] download animation fileId=${animationFile.id}, messageId=${message.id}`);
        this.td.downloadFile(animationFile.id);
      }
      if (content.animation.thumbnail && content.animation.thumbnail.file) {
        const thumbFile: TdFile = content.animation.thumbnail.file;
        if (!thumbFile.local || !thumbFile.local.is_downloading_completed) {
          console.info(`[ChatPage] download animation preview thumbnail fileId=${thumbFile.id}, messageId=${message.id}`);
          this.td.downloadFile(thumbFile.id);
        }
      }
    }
  }

  private upsertMessage(item: MessageItem): void {
    const nextMessages = this.messages.slice();
    const index = nextMessages.findIndex((current: MessageItem): boolean => current.id === item.id);
    if (index >= 0) {
      nextMessages[index] = item;
    } else {
      nextMessages.push(item);
    }
    nextMessages.sort((left: MessageItem, right: MessageItem): number => left.id - right.id);
    this.messages = this.resolveReplyTexts(nextMessages);
    this.statusText = '';
  }

  private mergeMessages(items: MessageItem[]): void {
    const nextMessages = this.messages.slice();
    items.forEach((item: MessageItem) => {
      const index = nextMessages.findIndex((current: MessageItem): boolean => current.id === item.id);
      if (index >= 0) {
        nextMessages[index] = item;
      } else {
        nextMessages.push(item);
      }
    });
    this.messages = this.resolveReplyTexts(this.sortMessages(nextMessages));
  }

  private sortMessages(items: MessageItem[]): MessageItem[] {
    return items.slice().sort((left: MessageItem, right: MessageItem): number => left.id - right.id);
  }

  private isAlbumMediaMessage(message: MessageItem): boolean {
    return message.mediaAlbumId > 0 &&
      (message.mediaType === 'messagePhoto' || message.mediaType === 'messageVideo' ||
        message.mediaType === 'messageAnimation');
  }

  private getMessageGroups(): MessageGroupItem[] {
    const groups: MessageGroupItem[] = [];
    let index = 0;
    while (index < this.messages.length) {
      const current = this.messages[index];
      if (!this.isAlbumMediaMessage(current)) {
        groups.push({
          id: `msg-${current.id}`,
          anchorId: current.id,
          isAlbum: false,
          items: [current]
        });
        index++;
        continue;
      }

      const albumItems: MessageItem[] = [current];
      let nextIndex = index + 1;
      while (nextIndex < this.messages.length) {
        const next = this.messages[nextIndex];
        if (this.isAlbumMediaMessage(next) && next.mediaAlbumId === current.mediaAlbumId &&
          next.isSelf === current.isSelf) {
          albumItems.push(next);
          nextIndex++;
        } else {
          break;
        }
      }

      if (albumItems.length > 1) {
        groups.push({
          id: `album-${current.mediaAlbumId}-${albumItems[0].id}`,
          anchorId: albumItems[0].id,
          isAlbum: true,
          items: albumItems
        });
      } else {
        groups.push({
          id: `msg-${current.id}`,
          anchorId: current.id,
          isAlbum: false,
          items: [current]
        });
      }
      index = nextIndex;
    }
    return groups;
  }

  private getDisplayIndexForMessageId(messageId: number): number {
    const groups = this.getMessageGroups();
    return groups.findIndex((group: MessageGroupItem): boolean => {
      return group.items.some((message: MessageItem): boolean => message.id === messageId);
    });
  }

  private groupContainsMessage(group: MessageGroupItem, messageId: number): boolean {
    return group.items.some((message: MessageItem): boolean => message.id === messageId);
  }

  private getAlbumRows(items: MessageItem[]): MessageItem[][] {
    const rows: MessageItem[][] = [];
    const visibleItems = this.getAlbumVisibleItems(items);
    let index = 0;
    while (index < visibleItems.length) {
      if (index + 2 < visibleItems.length) {
        rows.push([visibleItems[index], visibleItems[index + 1], visibleItems[index + 2]]);
      } else if (index + 1 < visibleItems.length) {
        rows.push([visibleItems[index], visibleItems[index + 1]]);
      } else {
        rows.push([visibleItems[index]]);
      }
      index += 3;
    }
    return rows;
  }

  private getAlbumVisibleItems(items: MessageItem[]): MessageItem[] {
    return items.slice(0, 9);
  }

  private albumHasTarget(group: MessageGroupItem): boolean {
    return group.items.some((message: MessageItem): boolean => message.isTarget);
  }

  private refreshMessageAfterCallback(messageId: number): void {
    if (this.chatId === 0 || messageId === 0) {
      return;
    }
    this.td.getMessage(this.chatId, messageId);
    setTimeout(() => {
      this.td.getMessage(this.chatId, messageId);
    }, 500);
    setTimeout(() => {
      this.td.getMessage(this.chatId, messageId);
    }, 1200);
  }

  private scrollToLatestAndMarkRead(): void {
    console.info(`[ChatPage] scroll to latest and mark read chatId=${this.chatId}, unread=${this.unreadCount}`);
    if (this.messages.length > 0) {
      this.messageScroller.scrollToIndex(this.getMessageGroups().length + 1, true, ScrollAlign.END);
      const unreadStart = Math.max(0, this.messages.length - this.unreadCount);
      const unreadMessages = this.messages.slice(unreadStart);
      const unreadIds: number[] = [];
      unreadMessages.forEach((message: MessageItem) => {
        if (!message.isSelf) {
          unreadIds.push(message.id);
        }
      });
      if (unreadIds.length > 0) {
        this.td.viewMessages(this.chatId, unreadIds, true);
      }
      this.lastReadInboxMessageId = this.messages[this.messages.length - 1].id;
    }
    this.unreadCount = 0;
    this.unreadAnchorMessageId = 0;
  }

  private scheduleScrollToLatest(animated: boolean): void {
    this.scheduleScrollToLatestAt(animated, 80);
    this.scheduleScrollToLatestAt(false, 180);
    this.scheduleScrollToLatestAt(false, 340);
  }

  private scheduleScrollToLatestAt(animated: boolean, delay: number): void {
    setTimeout(() => {
      if (this.messages.length > 0) {
        console.info(`[ChatPage] auto scroll to latest chatId=${this.chatId}, animated=${animated}, delay=${delay}`);
        this.messageScroller.scrollToIndex(this.getMessageGroups().length + 1, animated, ScrollAlign.END);
      }
    }, delay);
  }

  private restoreScrollAfterPrepend(newestLoadedMessageId: number, fallbackMessageId: number): void {
    const targetMessageId = newestLoadedMessageId !== 0 ? newestLoadedMessageId : fallbackMessageId;
    if (targetMessageId === 0) {
      return;
    }
    setTimeout(() => {
      const index = this.getDisplayIndexForMessageId(targetMessageId);
      if (index >= 0) {
        console.info(`[ChatPage] restore prepend scroll chatId=${this.chatId}, messageId=${targetMessageId}, index=${index}`);
        this.messageScroller.scrollToIndex(index + 1, false, ScrollAlign.START);
      }
    }, 30);
  }

  private scheduleScrollToUnread(animated: boolean): void {
    setTimeout(() => {
      const anchorId = this.getFirstUnreadMessageId();
      const index = this.getDisplayIndexForMessageId(anchorId);
      if (index >= 0) {
        console.info(`[ChatPage] auto scroll to unread chatId=${this.chatId}, messageId=${anchorId}, index=${index}`);
        this.messageScroller.scrollToIndex(index + 1, animated, ScrollAlign.START);
      }
    }, 100);
  }

  private resolveReplyTexts(items: MessageItem[]): MessageItem[] {
    return items.map((item: MessageItem): MessageItem => {
      if (item.replyText.length > 0 || item.replyMessageId === 0) {
        return item;
      }
      const replied = items.find((current: MessageItem): boolean => current.id === item.replyMessageId);
      if (!replied || replied.text.length === 0) {
        return item;
      }
      return this.copyMessageItem(item, replied.text);
    });
  }

  private copyMessageItem(message: MessageItem, replyText: string): MessageItem {
    return {
      id: message.id,
      mediaAlbumId: message.mediaAlbumId,
      isSelf: message.isSelf,
      isTarget: message.isTarget,
      mediaType: message.mediaType,
      mediaFormat: message.mediaFormat,
      text: message.text,
      textRows: message.textRows,
      replyText: replyText,
      replyMessageId: message.replyMessageId,
      buttonRows: message.buttonRows,
      photoPath: message.photoPath,
      videoPath: message.videoPath,
      thumbnailPath: message.thumbnailPath,
      photoFileId: message.photoFileId,
      videoFileId: message.videoFileId,
      thumbnailFileId: message.thumbnailFileId,
      documentFileId: message.documentFileId,
      documentFileName: message.documentFileName,
      documentSize: message.documentSize,
      audioFileId: message.audioFileId,
      audioPath: message.audioPath,
      audioTitle: message.audioTitle,
      audioPerformer: message.audioPerformer,
      audioDuration: message.audioDuration,
      audioDownloadedSize: message.audioDownloadedSize,
      audioExpectedSize: message.audioExpectedSize,
      videoDownloadedSize: message.videoDownloadedSize,
      videoExpectedSize: message.videoExpectedSize,
      videoCanPlay: message.videoCanPlay,
      videoDuration: message.videoDuration,
      mediaWidth: message.mediaWidth,
      mediaHeight: message.mediaHeight,
      dateText: message.dateText,
      viewCount: message.viewCount
    };
  }

  private applyFileUpdate(file: TdFile): void {
    const path = this.getLocalPath(file);
    if (path.length === 0) {
      return;
    }
    if (file.id === this.chatAvatarFileId) {
      console.info(`[ChatPage] apply chat avatar file update fileId=${file.id}`);
      this.chatAvatarPath = path;
    }
    let changed = false;
    const nextMessages: MessageItem[] = this.messages.map((message: MessageItem): MessageItem => {
      const next: MessageItem = {
        id: message.id,
        mediaAlbumId: message.mediaAlbumId,
        isSelf: message.isSelf,
        isTarget: message.isTarget,
        mediaType: message.mediaType,
        mediaFormat: message.mediaFormat,
        text: message.text,
        textRows: message.textRows,
        replyText: message.replyText,
        replyMessageId: message.replyMessageId,
        buttonRows: message.buttonRows,
        photoPath: message.photoPath,
        videoPath: message.videoPath,
        thumbnailPath: message.thumbnailPath,
        photoFileId: message.photoFileId,
        videoFileId: message.videoFileId,
        thumbnailFileId: message.thumbnailFileId,
        documentFileId: message.documentFileId,
        documentFileName: message.documentFileName,
        documentSize: message.documentSize,
        audioFileId: message.audioFileId,
        audioPath: message.audioPath,
        audioTitle: message.audioTitle,
        audioPerformer: message.audioPerformer,
        audioDuration: message.audioDuration,
        audioDownloadedSize: message.audioDownloadedSize,
        audioExpectedSize: message.audioExpectedSize,
        videoDownloadedSize: message.videoDownloadedSize,
        videoExpectedSize: message.videoExpectedSize,
        videoCanPlay: message.videoCanPlay,
        videoDuration: message.videoDuration,
        mediaWidth: message.mediaWidth,
        mediaHeight: message.mediaHeight,
        dateText: message.dateText,
        viewCount: message.viewCount
      };
      if (next.photoFileId === file.id) {
        next.photoPath = path;
        next.mediaFormat = this.getMediaFormat('', '', path, next.mediaFormat.length > 0 ? next.mediaFormat : 'jpg');
        changed = true;
      }
      if (next.videoFileId === file.id) {
        next.videoPath = path;
        next.videoDownloadedSize = this.getDownloadedSize(file);
        next.videoExpectedSize = this.getExpectedSize(file);
        next.videoCanPlay = this.canPlayVideo(file);
        next.mediaFormat = this.getMediaFormat('', '', path, next.mediaFormat.length > 0 ? next.mediaFormat : 'mp4');
        changed = true;
      }
      if (next.thumbnailFileId === file.id) {
        next.thumbnailPath = path;
        changed = true;
      }
      if (next.documentFileId === file.id) {
        next.documentSize = this.getExpectedSize(file);
        changed = true;
      }
      if (next.audioFileId === file.id) {
        next.audioPath = path;
        next.audioDownloadedSize = this.getDownloadedSize(file);
        next.audioExpectedSize = this.getExpectedSize(file);
        next.mediaFormat = this.getMediaFormat('', '', path, next.mediaFormat.length > 0 ? next.mediaFormat : 'mp3');
        changed = true;
      }
      return next;
    });
    if (changed) {
      console.info(`[ChatPage] applyFileUpdate fileId=${file.id}, path=${path}`);
      this.messages = nextMessages;
    }
  }

  private applyMessageContentUpdate(messageId: number, content: TdMessageContent): void {
    let changed = false;
    const nextMessages: MessageItem[] = this.messages.map((message: MessageItem): MessageItem => {
      if (message.id !== messageId) {
        return message;
      }
      changed = true;
      const next: MessageItem = {
        id: message.id,
        mediaAlbumId: message.mediaAlbumId,
        isSelf: message.isSelf,
        isTarget: message.isTarget,
        mediaType: this.getNormalizedMediaType(content),
        mediaFormat: this.getContentMediaFormat(content),
        text: this.getMessageText(content),
        textRows: this.getMessageTextRows(content),
        replyText: message.replyText,
        replyMessageId: message.replyMessageId,
        buttonRows: message.buttonRows,
        photoPath: '',
        videoPath: '',
        thumbnailPath: '',
        photoFileId: 0,
        videoFileId: 0,
        thumbnailFileId: 0,
        documentFileId: 0,
        documentFileName: '',
        documentSize: 0,
        audioFileId: 0,
        audioPath: '',
        audioTitle: '',
        audioPerformer: '',
        audioDuration: 0,
        audioDownloadedSize: 0,
        audioExpectedSize: 0,
        videoDownloadedSize: 0,
        videoExpectedSize: 0,
        videoCanPlay: false,
        videoDuration: 0,
        mediaWidth: 0,
        mediaHeight: 0,
        dateText: message.dateText,
        viewCount: message.viewCount
      };
      if (content.type === 'messagePhoto' && content.photo) {
        const size: TdPhotoSize | undefined = this.getPreviewPhotoSize(content.photo);
        if (size) {
          next.photoFileId = size.photo.id;
          next.photoPath = this.getLocalPath(size.photo);
          next.mediaWidth = size.width;
          next.mediaHeight = size.height;
        }
      }
      if (content.type === 'messageVideo' && content.video) {
        next.videoFileId = content.video.video.id;
        next.videoPath = this.getLocalPath(content.video.video);
        next.videoDownloadedSize = this.getDownloadedSize(content.video.video);
        next.videoExpectedSize = this.getExpectedSize(content.video.video);
        next.videoCanPlay = this.canPlayVideo(content.video.video);
        next.videoDuration = content.video.duration ? content.video.duration : 0;
        next.mediaWidth = content.video.width ? content.video.width : 0;
        next.mediaHeight = content.video.height ? content.video.height : 0;
        if (content.video.thumbnail && content.video.thumbnail.file) {
          next.thumbnailFileId = content.video.thumbnail.file.id;
          next.thumbnailPath = this.getLocalPath(content.video.thumbnail.file);
        }
      }
      if (content.type === 'messageAnimation' && content.animation) {
        next.videoFileId = content.animation.animation.id;
        next.videoPath = this.getLocalPath(content.animation.animation);
        next.videoDownloadedSize = this.getDownloadedSize(content.animation.animation);
        next.videoExpectedSize = this.getExpectedSize(content.animation.animation);
        next.videoCanPlay = this.canPlayVideo(content.animation.animation);
        next.videoDuration = content.animation.duration ? content.animation.duration : 0;
        next.mediaWidth = content.animation.width ? content.animation.width : 0;
        next.mediaHeight = content.animation.height ? content.animation.height : 0;
        if (content.animation.thumbnail && content.animation.thumbnail.file) {
          next.thumbnailFileId = content.animation.thumbnail.file.id;
          next.thumbnailPath = this.getLocalPath(content.animation.thumbnail.file);
        }
      }
      if (content.type === 'messageDocument' && content.document) {
        next.documentFileId = content.document.document.id;
        next.documentFileName = content.document.file_name && content.document.file_name.length > 0 ?
          content.document.file_name : '未命名文件';
        next.documentSize = this.getExpectedSize(content.document.document);
        next.mediaFormat = this.getMediaFormat(content.document.file_name, content.document.mime_type,
          this.getLocalPath(content.document.document), 'file');
      }
      if (content.type === 'messageAudio' && content.audio) {
        this.applyAudioContentToItem(next, content.audio);
      }
      return next;
    });
    if (changed) {
      this.messages = nextMessages;
    }
  }

  private applyReplyMarkupUpdate(messageId: number, replyMarkup: TdReplyMarkup | undefined): void {
    let changed = false;
    const nextMessages: MessageItem[] = this.messages.map((message: MessageItem): MessageItem => {
      if (message.id !== messageId) {
        return message;
      }
      changed = true;
      return {
        id: message.id,
        mediaAlbumId: message.mediaAlbumId,
        isSelf: message.isSelf,
        isTarget: message.isTarget,
        mediaType: message.mediaType,
        mediaFormat: message.mediaFormat,
        text: message.text,
        textRows: message.textRows,
        replyText: message.replyText,
        replyMessageId: message.replyMessageId,
        buttonRows: this.getMessageButtonRows(replyMarkup),
        photoPath: message.photoPath,
        videoPath: message.videoPath,
        thumbnailPath: message.thumbnailPath,
        photoFileId: message.photoFileId,
        videoFileId: message.videoFileId,
        thumbnailFileId: message.thumbnailFileId,
        documentFileId: message.documentFileId,
        documentFileName: message.documentFileName,
        documentSize: message.documentSize,
        audioFileId: message.audioFileId,
        audioPath: message.audioPath,
        audioTitle: message.audioTitle,
        audioPerformer: message.audioPerformer,
        audioDuration: message.audioDuration,
        audioDownloadedSize: message.audioDownloadedSize,
        audioExpectedSize: message.audioExpectedSize,
        videoDownloadedSize: message.videoDownloadedSize,
        videoExpectedSize: message.videoExpectedSize,
        videoCanPlay: message.videoCanPlay,
        videoDuration: message.videoDuration,
        mediaWidth: message.mediaWidth,
        mediaHeight: message.mediaHeight,
        dateText: message.dateText,
        viewCount: message.viewCount
      };
    });
    if (changed) {
      this.messages = nextMessages;
    }
  }

  private getVideoProgressText(msg: MessageItem): string {
    if (msg.videoExpectedSize > 0) {
      const percent = Math.floor(msg.videoDownloadedSize * 100 / msg.videoExpectedSize);
      return `缓存 ${percent}%`;
    }
    if (msg.videoDownloadedSize > 0) {
      return `已缓存 ${Math.floor(msg.videoDownloadedSize / 1024)} KB`;
    }
    return '视频缓存中...';
  }

  private getFileSizeText(size: number): string {
    if (size <= 0) {
      return '未知大小';
    }
    if (size < 1024) {
      return `${size} B`;
    }
    if (size < 1024 * 1024) {
      return `${Math.round(size / 1024)} KB`;
    }
    const mb = size / 1024 / 1024;
    return `${mb.toFixed(mb >= 10 ? 0 : 1)} MB`;
  }

  private getAudioProgressText(msg: MessageItem): string {
    return `00:00 / ${this.formatDuration(msg.audioDuration)}`;
  }

  private formatDuration(seconds: number): string {
    const safeSeconds = Math.max(0, seconds);
    const minutes = Math.floor(safeSeconds / 60);
    const restSeconds = safeSeconds % 60;
    return `${this.pad2(minutes)}:${this.pad2(restSeconds)}`;
  }

  private getAudioTopicText(msg: MessageItem): string {
    const text = msg.text.trim();
    if (text.length === 0) {
      return '#音乐';
    }
    const parts = text.split(/\s+/);
    const topic = parts.find((part: string): boolean => part.startsWith('#'));
    return topic && topic.length > 0 ? topic : `#${text.split('\n')[0]}`;
  }

  private toggleAudioPlayback(msg: MessageItem): void {
    if (msg.audioFileId > 0 && msg.audioPath.length === 0) {
      console.info(`[ChatPage] audio download clicked messageId=${msg.id}, fileId=${msg.audioFileId}`);
      this.td.downloadFile(msg.audioFileId, 24);
    }
    this.playingAudioMessageId = this.playingAudioMessageId === msg.id ? 0 : msg.id;
  }

  private getMediaRatio(msg: MessageItem): number {
    if (msg.mediaWidth <= 0 || msg.mediaHeight <= 0) {
      return 4 / 3;
    }
    const rawRatio = msg.mediaWidth / msg.mediaHeight;
    if (rawRatio < 0.56) {
      return 0.56;
    }
    if (rawRatio > 1.9) {
      return 1.9;
    }
    return rawRatio;
  }

  private getMediaDisplayWidth(msg: MessageItem): number {
    const ratio = this.getMediaRatio(msg);
    if (ratio < 0.75) {
      return 168;
    }
    if (ratio > 1.5) {
      return 250;
    }
    return 220;
  }

  private getMediaDisplayHeight(msg: MessageItem): number {
    const width = this.getMediaDisplayWidth(msg);
    return Math.round(width / this.getMediaRatio(msg));
  }

  private saveImageToGallery(path: string): void {
    if (path.length === 0) {
      this.statusText = '图片还未下载完成';
      return;
    }
    console.info(`[ChatPage] saveImageToGallery path=${path}`);
    const context = getContext(this) as common.UIAbilityContext;
    GalleryService.saveImage(context, path).then(() => {
      this.statusText = '图片已保存到图库';
    }).catch((err: StartAbilityError) => {
      console.error(`[ChatPage] saveImageToGallery failed code=${err.code}, message=${err.message}`);
      this.statusText = '保存图片失败';
    });
  }

  private requestImageSave(path: string): void {
    if (path.length === 0) {
      this.statusText = '图片还未下载完成';
      return;
    }
    this.pendingImageSavePath = path;
    this.showImageSaveButton = true;
    this.statusText = '点击保存按钮将图片保存到图库';
    console.info(`[ChatPage] requestImageSave path=${path}`);
  }

  private openUrl(url: string): void {
    const normalizedUrl = this.normalizeUrl(url);
    console.info(`[ChatPage] openUrl url=${normalizedUrl}`);
    if (normalizedUrl.length === 0) {
      return;
    }
    if (this.isTelegramMessageUrl(normalizedUrl)) {
      this.openInternalMessageUrl(normalizedUrl);
      return;
    }
    const context = getContext(this) as common.UIAbilityContext;
    const want: Want = {
      action: 'ohos.want.action.viewData',
      uri: normalizedUrl
    };
    context.startAbility(want).catch((err: StartAbilityError) => {
      console.error(`[ChatPage] openUrl failed code=${err.code}, message=${err.message}`);
      this.statusText = '无法打开链接';
    });
  }

  private normalizeUrl(url: string): string {
    const value = url.trim();
    if (value.length === 0) {
      return '';
    }
    if (value.startsWith('http://') || value.startsWith('https://') || value.startsWith('tg://')) {
      return value;
    }
    return `https://${value}`;
  }

  private isTelegramMessageUrl(url: string): boolean {
    return url.startsWith('tg://') ||
      url.startsWith('https://t.me/') ||
      url.startsWith('http://t.me/') ||
      url.startsWith('https://telegram.me/') ||
      url.startsWith('http://telegram.me/');
  }

  private openInternalMessageUrl(url: string): void {
    console.info(`[ChatPage] openInternalMessageUrl url=${url}`);
    this.statusText = '正在打开内部消息...';
    const parsed = this.parseTMeMessageUrl(url);
    if (parsed.chatId !== 0 && parsed.messageId !== 0) {
      router.pushUrl({ url: 'pages/ChatPage', params: { chatId: parsed.chatId, messageId: parsed.messageId } });
      return;
    }
    this.td.getMessageLinkInfo(url);
  }

  private parseTMeMessageUrl(url: string): ChatRouteParams {
    const result: ChatRouteParams = {
      chatId: 0,
      messageId: 0
    };
    const marker = '/c/';
    const markerIndex = url.indexOf(marker);
    if (markerIndex >= 0) {
      const tail = url.substring(markerIndex + marker.length);
      const parts = tail.split('/');
      if (parts.length >= 2) {
        const internalChatId = Number(parts[0]);
        const messageId = Number(this.trimUrlToken(parts[1].split('?')[0]));
        if (!Number.isNaN(internalChatId) && !Number.isNaN(messageId)) {
          result.chatId = Number(`-100${internalChatId}`);
          result.messageId = messageId;
        }
      }
      return result;
    }

    if (url.startsWith('tg://privatepost')) {
      const channel = this.getQueryNumber(url, 'channel');
      const post = this.getQueryNumber(url, 'post');
      if (channel !== 0 && post !== 0) {
        result.chatId = Number(`-100${channel}`);
        result.messageId = post;
      }
      return result;
    }

    return result;
  }

  private getQueryNumber(url: string, key: string): number {
    const marker = `${key}=`;
    const markerIndex = url.indexOf(marker);
    if (markerIndex < 0) {
      return 0;
    }
    const tail = url.substring(markerIndex + marker.length);
    const value = this.trimUrlToken(tail.split('&')[0]);
    const numberValue = Number(value);
    return Number.isNaN(numberValue) ? 0 : numberValue;
  }

  private handleInlineButton(messageId: number, button: MessageButtonItem): void {
    console.info(`[ChatPage] inline button clicked messageId=${messageId}, type=${button.type}, text=${button.text}`);
    if (button.type === 'inlineKeyboardButtonTypeUrl' ||
      button.type === 'inlineKeyboardButtonTypeLoginUrl' ||
      button.type === 'inlineKeyboardButtonTypeWebApp') {
      this.openUrl(button.url);
      return;
    }
    if (button.type === 'inlineKeyboardButtonTypeCallback' && button.data.length > 0) {
      this.statusText = '正在请求...';
      this.td.getCallbackQueryAnswer(this.chatId, messageId, button.data);
      this.refreshMessageAfterCallback(messageId);
      return;
    }
    if (button.type === 'inlineKeyboardButtonTypeSwitchInline') {
      this.input = button.text;
      return;
    }
    this.statusText = '暂不支持该按钮类型';
  }

  private openVideoPlayer(msg: MessageItem): void {
    if (msg.videoFileId === 0) {
      return;
    }
    console.info(`[ChatPage] openVideoPlayer chatId=${this.chatId}, messageId=${msg.id}, fileId=${msg.videoFileId}`);
    const params: VideoRouteParams = {
      chatId: this.chatId,
      messageId: msg.id,
      fileId: msg.videoFileId,
      videoPath: msg.videoPath,
      previewUri: msg.thumbnailPath,
      title: this.chatTitle,
      subtitle: msg.dateText.length > 0 ? msg.dateText : this.chatSubtitle,
      description: msg.text.length > 0 ? msg.text : this.chatTitle,
      fileSize: msg.videoExpectedSize,
      downloadedSize: msg.videoDownloadedSize,
      duration: msg.videoDuration,
      videoWidth: msg.mediaWidth,
      videoHeight: msg.mediaHeight
    };
    router.pushUrl({
      url: 'pages/VideoPlayerPage',
      params: params
    });
  }

  @Builder
  private PinnedMessageBar() {
    if (this.pinnedMessageText.length > 0) {
      Row({ space: 8 }) {
        Column()
          .width(2)
          .height(34)
          .borderRadius(1)
          .backgroundColor('#6B7A6D')
          .margin({ left: 8 })
        Column() {
          Text('置顶消息')
            .fontSize(12)
            .fontWeight(FontWeight.Bold)
            .fontColor('#111111')
            .maxLines(1)
          Text(this.pinnedMessageText)
            .fontSize(12)
            .fontColor('#111111')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
        }
        .layoutWeight(1)
        .alignItems(HorizontalAlign.Start)
        Text('☰')
          .fontSize(20)
          .fontColor('#162026')
          .width(28)
          .textAlign(TextAlign.Center)
      }
      .height(50)
      .width('92%')
      .padding({ left: 6, right: 10 })
      .borderRadius(50)
      .backgroundColor('#c8ffffff')
      .shadow({ radius: 10, color: '#12000000', offsetY: 3 })
      .position({ x: '4%', y: AppLayout.STATUS_BAR_HEIGHT + 54 })
    }
  }

  @Builder
  private MediaFormatBadge(format: string) {
    if (format.length > 0) {
      Text(format)
        .fontSize(12)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .height(24)
        .padding({ left: 9, right: 9 })
        .borderRadius(12)
        .backgroundColor('#66000000')
        .align(Alignment.TopStart)
        .margin({ left: 10, top: 10 })
    }
  }

  @Builder
  private InlineVideoTimeBadge(msg: MessageItem) {
    Text(this.getInlineRemainingText(msg))
      .fontSize(12)
      .fontWeight(FontWeight.Bold)
      .fontColor(Color.White)
      .height(24)
      .padding({ left: 9, right: 9 })
      .borderRadius(12)
      .backgroundColor('#66000000')
      .align(Alignment.TopStart)
      .margin({ left: 10, top: 10 })
  }

  @Builder
  private ChatAvatar(size: number) {
    if (this.chatAvatarPath.length > 0) {
      Image(this.chatAvatarPath)
        .width(size)
        .height(size)
        .borderRadius(size / 2)
        .objectFit(ImageFit.Cover)
        .backgroundColor('#D9F0FF')
    } else {
      Text(this.chatAvatarText)
        .fontSize(size > 42 ? 24 : 17)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .textAlign(TextAlign.Center)
        .width(size)
        .height(size)
        .borderRadius(size / 2)
        .backgroundColor('#2F80ED')
    }
  }

  @Builder
  private LinkPreviewThumb(size: number) {
    if (this.chatAvatarPath.length > 0) {
      Image(this.chatAvatarPath)
        .width(size)
        .height(size)
        .borderRadius(7)
        .objectFit(ImageFit.Cover)
        .backgroundColor('#EAF7DF')
    } else {
      Text(this.chatAvatarText)
        .fontSize(22)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .textAlign(TextAlign.Center)
        .width(size)
        .height(size)
        .borderRadius(7)
        .backgroundColor('#66B955')
    }
  }

  @Builder
  private LinkPreviewMessage(msg: MessageItem) {
    Column() {
      Text(this.getPrimaryLinkUrl(msg))
        .fontSize(14)
        .fontColor('#006DDE')
        .lineHeight(20)
        .maxLines(2)
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .width('100%')
        .onClick(() => {
          this.openUrl(this.getPrimaryLinkUrl(msg));
        })

      Row() {
        Column()
          .width(3)
          .height(86)
          .borderRadius(2)
          .backgroundColor('#12B51F')
          .margin({ right: 7 })

        Column() {
          Text(this.getLinkPreviewSite(this.getPrimaryLinkUrl(msg)))
            .fontSize(12)
            .fontWeight(FontWeight.Bold)
            .fontColor('#00A91B')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
          Text(this.getLinkPreviewTitle(msg))
            .fontSize(13)
            .fontWeight(FontWeight.Bold)
            .fontColor('#111111')
            .lineHeight(18)
            .margin({ top: 2 })
          Text(this.getLinkPreviewDescription(msg))
            .fontSize(12)
            .fontColor('#111111')
            .lineHeight(16)
            .margin({ top: 2 })
        }
        .layoutWeight(1)
        .alignItems(HorizontalAlign.Start)
        .margin({ right: 8 })

        this.LinkPreviewThumb(58)
      }
      .width('100%')
      .padding({ left: 7, right: 7, top: 7, bottom: 7 })
      .borderRadius(7)
      .backgroundColor(msg.isSelf ? '#C4F4B6' : '#F3F8EF')
      .margin({ top: 6 })
      .onClick(() => {
        this.openUrl(this.getPrimaryLinkUrl(msg));
      })
    }
    .width(318)
  }

  @Builder
  private ChatHeader() {
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
        .backgroundColor('#99ffffff')
        .onClick(() => {
          if (!this.embedded) {
            console.info(`[ChatPage] back clicked chatId=${this.chatId}`);
            router.back();
          }
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
            Text(this.chatTitle)
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

          Text(this.chatSubtitle.length > 0 ? this.chatSubtitle : '连接中...')
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
        .backgroundColor('#99ffffff')
        .shadow({ radius: 12, color: '#16000000', offsetY: 4 })
        .onClick(() => {
          console.info(`[ChatPage] title clicked chatId=${this.chatId}`);
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
            .fill('#F6FFFFFF')
          this.ChatAvatar(36)
        }
        .width(40)
        .height(40)
        .onClick(() => {
          console.info(`[ChatPage] avatar clicked chatId=${this.chatId}`);
          this.openChatProfile();
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

  @Builder
  private AlbumMediaTile(msg: MessageItem, tileWidth: number, tileHeight: number) {
    Stack({ alignContent: Alignment.Center }) {
      if (msg.mediaType === 'messagePhoto') {
        if (msg.photoPath.length > 0) {
          Image(msg.photoPath)
            .width(tileWidth)
            .height(tileHeight)
            .objectFit(ImageFit.Cover)
            .borderRadius(8)
            .onClick(() => {
              this.openImagePreview(msg.photoPath);
            })
            .gesture(
              LongPressGesture().onAction(() => {
                this.requestImageSave(msg.photoPath);
              })
            )
        } else {
          Text('图片下载中')
            .fontSize(12)
            .fontColor('#666666')
            .width(tileWidth)
            .height(tileHeight)
            .textAlign(TextAlign.Center)
            .backgroundColor('#E6F4FF')
            .borderRadius(8)
        }
        this.MediaFormatBadge(msg.mediaFormat)
      } else if (msg.mediaType === 'messageVideo') {
        if (this.shouldInlinePlayVideo(msg) && msg.videoPath.length > 0) {
          Video({
            src: msg.videoPath,
            previewUri: msg.thumbnailPath.length > 0 ? msg.thumbnailPath : undefined
          })
            .width(tileWidth)
            .height(tileHeight)
            .autoPlay(true)
            .controls(false)
            .loop(true)
            .muted(true)
            .objectFit(ImageFit.Cover)
            .borderRadius(8)
            .onUpdate((info: PlaybackInfo) => {
              this.updateInlineVideoProgress(msg.id, msg.videoDuration, info.time);
            })
            .onClick(() => {
              this.openVideoPlayer(msg);
            })
        } else if (msg.thumbnailPath.length > 0) {
          Image(msg.thumbnailPath)
            .width(tileWidth)
            .height(tileHeight)
            .objectFit(ImageFit.Cover)
            .borderRadius(8)
        } else {
          Text('视频预览')
            .fontSize(12)
            .fontColor('#666666')
            .width(tileWidth)
            .height(tileHeight)
            .textAlign(TextAlign.Center)
            .backgroundColor('#E6F4FF')
            .borderRadius(8)
        }
        if (this.shouldInlinePlayVideo(msg)) {
          this.InlineVideoTimeBadge(msg)
        } else {
          Button('▶')
            .fontSize(18)
            .fontColor(Color.White)
            .width(34)
            .height(34)
            .borderRadius(17)
            .backgroundColor('#66000000')
            .onClick(() => {
              this.openVideoPlayer(msg);
            })
          this.MediaFormatBadge(msg.mediaFormat)
        }
      } else {
        if (msg.videoPath.length > 0) {
          Image(msg.videoPath)
            .width(tileWidth)
            .height(tileHeight)
            .objectFit(ImageFit.Cover)
            .borderRadius(8)
        } else if (msg.thumbnailPath.length > 0) {
          Image(msg.thumbnailPath)
            .width(tileWidth)
            .height(tileHeight)
            .objectFit(ImageFit.Cover)
            .borderRadius(8)
        } else {
          Text('GIF预览')
            .fontSize(12)
            .fontColor('#666666')
            .width(tileWidth)
            .height(tileHeight)
            .textAlign(TextAlign.Center)
            .backgroundColor('#E6F4FF')
            .borderRadius(8)
        }
        this.MediaFormatBadge(msg.mediaFormat.length > 0 ? msg.mediaFormat : 'gif')
      }
    }
    .width(tileWidth)
    .height(tileHeight)
    .clip(true)
  }

  @Builder
  private AudioMessageBody(msg: MessageItem) {
    Column() {
      Row({ space: 9 }) {
        Stack({ alignContent: Alignment.Center }) {
          if (msg.thumbnailPath.length > 0) {
            Image(msg.thumbnailPath)
              .width(58)
              .height(58)
              .objectFit(ImageFit.Cover)
              .borderRadius(10)
          } else {
            Column()
              .width(58)
              .height(58)
              .borderRadius(10)
              .linearGradient({
                direction: GradientDirection.Bottom,
                colors: [['#69C7FF', 0], ['#7E66F2', 1]]
              })
          }

          Button({ type: ButtonType.Circle }) {
            Image(this.playingAudioMessageId === msg.id ? $r('app.media.tingzhi') : $r('app.media.playfill'))
              .width(18)
              .height(18)
              .objectFit(ImageFit.Contain)
          }
          .width(30)
          .height(30)
          .backgroundColor('#AA000000')
          .onClick(() => {
            this.toggleAudioPlayback(msg);
          })

          Button({ type: ButtonType.Circle }) {
            Text('↓')
              .fontSize(12)
              .fontColor(Color.White)
              .fontWeight(FontWeight.Bold)
          }
          .width(20)
          .height(20)
          .backgroundColor('#CC0A84FF')
          .position({ x: 36, y: 36 })
          .onClick(() => {
            if (msg.audioFileId > 0) {
              this.td.downloadFile(msg.audioFileId, 24);
            }
          })
        }
        .width(58)
        .height(58)

        Column() {
          Text(msg.audioTitle)
            .fontSize(14)
            .fontWeight(FontWeight.Bold)
            .fontColor('#111111')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
          Text(msg.audioPerformer)
            .fontSize(11)
            .fontColor('#6D7480')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
            .margin({ top: 4 })
          Text(this.getAudioProgressText(msg))
            .fontSize(11)
            .fontColor('#8A96A8')
            .margin({ top: 5 })
        }
        .layoutWeight(1)
        .alignItems(HorizontalAlign.Start)
      }
      .width('100%')

      Text(msg.audioTitle)
        .fontSize(13)
        .fontWeight(FontWeight.Medium)
        .fontColor('#111111')
        .maxLines(1)
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .margin({ top: 8 })
      Text(this.getAudioTopicText(msg))
        .fontSize(12)
        .fontColor('#0A66CC')
        .maxLines(2)
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .margin({ top: 2 })
    }
    .width(270)
    .alignItems(HorizontalAlign.Start)
  }

  @Builder
  private MessageMetaFooter(viewCount: number, dateText: string, isSelf: boolean) {
    Row({ space: 4 }) {
      Text('👁')
        .fontSize(10)
        .fontColor(isSelf ? '#5E8F78' : '#8A96A8')
      Text(`${viewCount}`)
        .fontSize(10)
        .fontColor(isSelf ? '#5E8F78' : '#8A96A8')
      Text(dateText)
        .fontSize(11)
        .fontColor(isSelf ? '#5E8F78' : '#8A96A8')
      if (isSelf) {
        Text('✓✓')
          .fontSize(12)
          .fontColor('#5E8F78')
          .margin({ left: 2 })
      }
    }
    .alignItems(VerticalAlign.Center)
  }

  @Builder
  private MessageBody(msg: MessageItem) {
    Column() {
      if (!msg.isSelf && msg.replyText.length > 0) {
        Row() {
          Column()
            .width(2)
            .height(34)
            .borderRadius(1)
            .backgroundColor('#C85AA8D6')
          Column() {
            Text('引用')
              .fontSize(9)
              .fontColor('#5AA8D6')
              .fontWeight(FontWeight.Bold)
              .maxLines(1)
            Text(msg.replyText)
              .fontSize(10)
              .fontColor('#6D7480')
              .lineHeight(14)
              .maxLines(2)
              .textOverflow({ overflow: TextOverflow.Ellipsis })
              .constraintSize({ maxWidth: 296 })
              .margin({ top: 1 })
          }
          .margin({ left: 6 })
        }
        .constraintSize({ maxWidth: 318 })
        .padding({ left: 6, right: 6, top: 5, bottom: 5 })
        .borderRadius(8)
        .backgroundColor('#F3F8FB')
        .margin({ bottom: 5 })
      }
      if (msg.mediaType === 'messagePhoto') {
        Stack({ alignContent: Alignment.Center }) {
          if (msg.photoPath.length > 0) {
            Image(msg.photoPath)
              .width(this.getMediaDisplayWidth(msg))
              .height(this.getMediaDisplayHeight(msg))
              .objectFit(ImageFit.Contain)
              .borderRadius(12)
              .onClick(() => {
                this.openImagePreview(msg.photoPath);
              })
              .gesture(
                LongPressGesture().onAction(() => {
                  this.requestImageSave(msg.photoPath);
                })
              )
          } else {
            Text('图片下载中...')
              .fontSize(14)
              .fontColor('#666666')
              .width(this.getMediaDisplayWidth(msg))
              .height(this.getMediaDisplayHeight(msg))
              .textAlign(TextAlign.Center)
              .backgroundColor('#E6F4FF')
              .borderRadius(12)
          }
          this.MediaFormatBadge(msg.mediaFormat)
        }
        .width(this.getMediaDisplayWidth(msg))
      } else if (msg.mediaType === 'messageAudio') {
        this.AudioMessageBody(msg)
      } else if (msg.mediaType === 'messageVideo') {
        Stack({ alignContent: Alignment.Center }) {
          if (this.shouldInlinePlayVideo(msg) && msg.videoPath.length > 0) {
            Video({
              src: msg.videoPath,
              previewUri: msg.thumbnailPath.length > 0 ? msg.thumbnailPath : undefined
            })
              .width(this.getMediaDisplayWidth(msg))
              .height(this.getMediaDisplayHeight(msg))
              .autoPlay(true)
              .controls(false)
              .loop(true)
              .muted(true)
              .objectFit(ImageFit.Cover)
              .borderRadius(12)
              .onUpdate((info: PlaybackInfo) => {
                this.updateInlineVideoProgress(msg.id, msg.videoDuration, info.time);
              })
              .onClick(() => {
                this.openVideoPlayer(msg);
              })
          } else if (msg.thumbnailPath.length > 0) {
            Image(msg.thumbnailPath)
              .width(this.getMediaDisplayWidth(msg))
              .height(this.getMediaDisplayHeight(msg))
              .objectFit(ImageFit.Cover)
              .borderRadius(12)
          } else {
            Text('视频预览')
              .fontSize(16)
              .fontColor('#666666')
              .width(this.getMediaDisplayWidth(msg))
              .height(this.getMediaDisplayHeight(msg))
              .textAlign(TextAlign.Center)
              .backgroundColor('#E6F4FF')
              .borderRadius(12)
          }
          if (!this.shouldInlinePlayVideo(msg)) {
            Button('▶')
              .fontSize(22)
              .fontColor(Color.White)
              .width(38)
              .height(38)
              .borderRadius(19)
              .backgroundColor('#66000000')
              .onClick(() => {
                this.openVideoPlayer(msg);
              })
          }
          if (this.shouldInlinePlayVideo(msg)) {
            this.InlineVideoTimeBadge(msg)
          } else {
            this.MediaFormatBadge(msg.mediaFormat)
          }
        }
        .width(this.getMediaDisplayWidth(msg))
        .onClick(() => {
          this.openVideoPlayer(msg);
        })
      } else if (msg.mediaType === 'messageAnimation') {
        Stack({ alignContent: Alignment.Center }) {
          if (msg.videoPath.length > 0) {
            Image(msg.videoPath)
              .width(this.getMediaDisplayWidth(msg))
              .height(this.getMediaDisplayHeight(msg))
              .objectFit(ImageFit.Cover)
              .borderRadius(12)
          } else if (msg.thumbnailPath.length > 0) {
            Image(msg.thumbnailPath)
              .width(this.getMediaDisplayWidth(msg))
              .height(this.getMediaDisplayHeight(msg))
              .objectFit(ImageFit.Cover)
              .borderRadius(12)
          } else {
            Text('GIF预览')
              .fontSize(16)
              .fontColor('#666666')
              .width(this.getMediaDisplayWidth(msg))
              .height(this.getMediaDisplayHeight(msg))
              .textAlign(TextAlign.Center)
              .backgroundColor('#E6F4FF')
              .borderRadius(12)
          }
          this.MediaFormatBadge(msg.mediaFormat.length > 0 ? msg.mediaFormat : 'gif')
        }
        .width(this.getMediaDisplayWidth(msg))
      }
      if (msg.mediaType === 'messageDocument') {
        Row({ space: 10 }) {
          Button({ type: ButtonType.Circle }) {
            Text('↓')
              .fontSize(20)
              .fontColor(Color.White)
              .textAlign(TextAlign.Center)
          }
          .width(42)
          .height(42)
          .borderRadius(21)
          .backgroundColor('#0A84FF')
          .onClick(() => {
            console.info(`[ChatPage] document download clicked messageId=${msg.id}, fileId=${msg.documentFileId}`);
            if (msg.documentFileId > 0) {
              this.td.downloadFile(msg.documentFileId, 16);
            }
          })

          Column() {
            Text(msg.documentFileName.length > 0 ? msg.documentFileName : '未命名文件')
              .fontSize(14)
              .fontWeight(FontWeight.Medium)
              .fontColor('#111111')
              .maxLines(2)
              .textOverflow({ overflow: TextOverflow.Ellipsis })
            Text(`${this.getFileSizeText(msg.documentSize)} · ${msg.mediaFormat.length > 0 ? msg.mediaFormat : 'file'}`)
              .fontSize(11)
              .fontColor('#6D7480')
              .margin({ top: 3 })
          }
          .alignItems(HorizontalAlign.Start)
          .constraintSize({ maxWidth: 210 })
        }
        .constraintSize({ maxWidth: 270 })
        .padding({ top: 4, bottom: 4 })
      }
      if (this.hasLinkPreviewMessage(msg)) {
        this.LinkPreviewMessage(msg)
      } else if (msg.textRows.length > 0) {
        ForEach(msg.textRows, (row: MessageTextRow) => {
          if (row.url.length > 0) {
            Text(row.text)
              .fontSize(14)
              .fontColor('#0A66CC')
              .lineHeight(20)
              .textAlign(TextAlign.Start)
              .constraintSize({ maxWidth: 280 })
              .margin({ top: 3 })
              .onClick(() => {
                this.handleMessageRowClick(msg, row);
              })
          } else {
            Text(row.text)
              .fontSize(14)
              .fontColor(this.isRobotMessage(msg) && this.extractBotCommandFromText(row.text).length > 0 ? '#0A66CC' : '#111111')
              .lineHeight(20)
              .textAlign(TextAlign.Start)
              .constraintSize({ maxWidth: 280 })
              .margin({ top: 3 })
              .onClick(() => {
                this.handleMessageRowClick(msg, row);
              })
          }
        })
      } else if (msg.mediaType !== 'messagePhoto' && msg.mediaType !== 'messageVideo' &&
        msg.mediaType !== 'messageAnimation' && msg.mediaType !== 'messageDocument' && msg.mediaType !== 'messageAudio') {
        Text(`[${msg.mediaType}]`)
          .fontSize(13)
          .fontColor('#666666')
          .textAlign(TextAlign.Start)
          .constraintSize({ maxWidth: 280 })
      }
      if (msg.buttonRows.length > 0) {
        Column() {
          ForEach(msg.buttonRows, (row: MessageButtonItem[]) => {
            Row() {
              ForEach(row, (button: MessageButtonItem) => {
                Button(button.text)
                  .fontSize(8)
                  .fontColor('#2C6FA3')
                  .padding({ left: 6, right: 6, top: 4, bottom: 4 })
                  .borderRadius(7)
                  .backgroundColor('#EEF7FF')
                  .layoutWeight(1)
                  .margin(2)
                  .onClick(() => {
                    this.handleInlineButton(msg.id, button);
                  })
              })
            }
            .width('100%')
          })
        }
        .constraintSize({ maxWidth: 280 })
        .margin({ top: 5 })
      }
      Row() {
        Blank()
        Column() {
          this.MessageMetaFooter(msg.viewCount, msg.dateText, msg.isSelf)
        }
        .margin({ top: 4 })
      }
      .width('100%')
    }
    .alignItems(HorizontalAlign.Start)
    .padding({ left: 9, right: 9, top: 7, bottom: 5 })
    .borderRadius({ topLeft: 12, topRight: 12, bottomLeft: msg.isSelf ? 12 : 3, bottomRight: msg.isSelf ? 3 : 12 })
    .backgroundColor(msg.isTarget ? '#FFF2CC' : (msg.isSelf ? '#46A669' : Color.White))
    .constraintSize({ maxWidth: '80%' })
    .shadow({ radius: 4, color: '#10000000', offsetY: 1 })
  }

  @Builder
  private MessageRow(msg: MessageItem) {
    Row() {
      if (msg.isSelf) {
        Blank()
        this.MessageBody(msg)
      } else {
        if (!this.isRobotMessage(msg) && !this.isChannelChat) {
          this.ChatAvatar(30)
        }
        Column() {
          this.MessageBody(msg)
        }
        .margin({ left: (this.isRobotMessage(msg) || this.isChannelChat) ? 0 : 7 })
        Blank()
      }
    }
    .width('100%')
    .padding({ left: 8, right: 8, top: 4, bottom: 4 })
  }

  @Builder
  private AlbumMessageBody(group: MessageGroupItem) {
    Column() {
      if (!group.items[0].isSelf && group.items[0].replyText.length > 0) {
        Row() {
          Column()
            .width(2)
            .height(34)
            .borderRadius(1)
            .backgroundColor('#C85AA8D6')
          Column() {
            Text('引用')
              .fontSize(9)
              .fontColor('#5AA8D6')
              .fontWeight(FontWeight.Bold)
              .maxLines(1)
            Text(group.items[0].replyText)
              .fontSize(10)
              .fontColor('#6D7480')
              .lineHeight(14)
              .maxLines(2)
              .textOverflow({ overflow: TextOverflow.Ellipsis })
              .constraintSize({ maxWidth: 296 })
              .margin({ top: 1 })
          }
          .margin({ left: 6 })
        }
        .constraintSize({ maxWidth: 318 })
        .padding({ left: 6, right: 6, top: 5, bottom: 5 })
        .borderRadius(8)
        .backgroundColor('#F3F8FB')
        .margin({ bottom: 5 })
      }

      Column({ space: 4 }) {
        ForEach(this.getAlbumRows(group.items), (row: MessageItem[]) => {
          Row({ space: 4 }) {
            ForEach(row, (msg: MessageItem) => {
              this.AlbumMediaTile(msg, 78, 104)
            }, (msg: MessageItem): string => `${msg.id}`)
          }
          .width('100%')
        }, (row: MessageItem[]): string => row.map((message: MessageItem): string => `${message.id}`).join('-'))
      }
      .width(242)

      ForEach(this.getAlbumVisibleItems(group.items), (msg: MessageItem) => {
        if (msg.textRows.length > 0) {
          Column() {
            ForEach(msg.textRows, (row: MessageTextRow) => {
              if (row.url.length > 0) {
                Text(row.text)
                  .fontSize(14)
                  .fontColor('#0A66CC')
                  .lineHeight(20)
                  .textAlign(TextAlign.Start)
                  .constraintSize({ maxWidth: 300 })
                  .margin({ top: 4 })
                  .onClick(() => {
                    this.handleMessageRowClick(msg, row);
                  })
              } else {
                Text(row.text)
                  .fontSize(14)
                  .fontColor(this.isRobotMessage(msg) && this.extractBotCommandFromText(row.text).length > 0 ? '#0A66CC' : '#111111')
                  .lineHeight(20)
                  .textAlign(TextAlign.Start)
                  .constraintSize({ maxWidth: 300 })
                  .margin({ top: 4 })
                  .onClick(() => {
                    this.handleMessageRowClick(msg, row);
                  })
              }
            }, (row: MessageTextRow): string => `${msg.id}-${row.id}`)
          }
          .width('100%')
          .alignItems(HorizontalAlign.Start)
        }
      }, (msg: MessageItem): string => `caption-${msg.id}`)

      Row() {
        Blank()
        Column() {
          this.MessageMetaFooter(group.items[group.items.length - 1].viewCount,
            group.items[group.items.length - 1].dateText, group.items[0].isSelf)
        }
        .margin({ top: 4 })
      }
      .width('100%')
    }
    .alignItems(HorizontalAlign.Start)
    .padding({ left: 9, right: 9, top: 7, bottom: 5 })
    .borderRadius({
      topLeft: 12,
      topRight: 12,
      bottomLeft: group.items[0].isSelf ? 12 : 3,
      bottomRight: group.items[0].isSelf ? 3 : 12
    })
    .backgroundColor(this.albumHasTarget(group) ? '#FFF2CC' : (group.items[0].isSelf ? '#46A669' : Color.White))
    .constraintSize({ maxWidth: '80%' })
    .shadow({ radius: 4, color: '#10000000', offsetY: 1 })
  }

  @Builder
  private MessageGroupRow(group: MessageGroupItem) {
    if (!group.isAlbum) {
      this.MessageRow(group.items[0])
    } else {
      Row() {
        if (group.items[0].isSelf) {
          Blank()
          this.AlbumMessageBody(group)
        } else {
          if (!this.isRobotMessage(group.items[0]) && !this.isChannelChat) {
            this.ChatAvatar(30)
          }
          Column() {
            this.AlbumMessageBody(group)
          }
          .margin({ left: (this.isRobotMessage(group.items[0]) || this.isChannelChat) ? 0 : 7 })
          Blank()
        }
      }
      .width('100%')
      .padding({ left: 8, right: 8, top: 4, bottom: 4 })
    }
  }

  @Builder
  private UnreadDivider() {
    Row() {
      Divider()
        .strokeWidth(1)
        .color('#660A84FF')
        .layoutWeight(1)
      Text('未读消息')
        .fontSize(11)
        .fontColor('#0A84FF')
        .padding({ left: 10, right: 10, top: 3, bottom: 3 })
        .borderRadius(10)
        .backgroundColor('#E8F4FF')
      Divider()
        .strokeWidth(1)
        .color('#660A84FF')
        .layoutWeight(1)
    }
    .width('100%')
    .padding({ left: 18, right: 18, top: 8, bottom: 8 })
  }

  private isRobotMessage(msg: MessageItem): boolean {
    return !msg.isSelf && (this.chatSubtitle === '机器人' || msg.buttonRows.length > 0 || msg.replyText.length > 0);
  }

  private getChannelNotificationButtonText(): string {
    return this.channelNotificationsPaused ? '开启通知' : '静音';
  }

  private toggleChannelNotifications(): void {
    const nextPaused = !this.channelNotificationsPaused;
    this.channelNotificationsPaused = nextPaused;
    const muteFor = nextPaused ? 2147483647 : 0;
    console.info(`[ChatPage] toggle channel notifications chatId=${this.chatId}, paused=${nextPaused}, muteFor=${muteFor}`);
    this.td.setChatNotificationMute(this.chatId, muteFor);
    setTimeout(() => {
      this.td.getChat(this.chatId);
    }, 500);
  }

  @Builder
  private ChannelNotificationButton() {
    Row() {
      Button({ type: ButtonType.Circle }) {
        Image($r('app.media.property'))
          .width(24)
          .height(24)
          .objectFit(ImageFit.Contain)
      }
      .width(48)
      .height(48)
      .backgroundColor('#DFFFFFFF')
      .shadow({ radius: 12, color: '#16000000', offsetY: 4 })
      .onClick(() => {
        console.info(`[ChatPage] channel gift clicked chatId=${this.chatId}`);
      })

      Button() {
        Row({ space: 8 }) {
          Image($r('app.media.jingyin'))
            .width(17)
            .height(17)
            .objectFit(ImageFit.Contain)
            .opacity(this.channelNotificationsPaused ? 0.55 : 1)
          Text(this.getChannelNotificationButtonText())
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
      .backgroundColor('#DFFFFFFF')
      .shadow({ radius: 12, color: '#16000000', offsetY: 4 })
      .onClick(() => {
        this.toggleChannelNotifications();
      })

      Button({ type: ButtonType.Circle }) {
        Image($r('app.media.bar_search'))
          .width(24)
          .height(24)
          .objectFit(ImageFit.Contain)
      }
      .width(48)
      .height(48)
      .backgroundColor('#DFFFFFFF')
      .shadow({ radius: 12, color: '#16000000', offsetY: 4 })
      .onClick(() => {
        console.info(`[ChatPage] channel search clicked chatId=${this.chatId}`);
      })
    }
    .width('100%')
    .height(52)
  }

  @Builder
  private Composer() {
    Row() {
      if (this.shouldShowBotMenuButton()) {
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
          console.info(`[ChatPage] bot menu toggle chatId=${this.chatId}, visible=${!this.botMenuVisible}`);
          this.setBotMenuVisible(!this.botMenuVisible);
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
      .backgroundColor('#99ffffff')
      .shadow({ radius: 10, color: '#16000000', offsetY: 3 })
      .margin({ left: this.shouldShowBotMenuButton() ? 6 : 0 })
      .onClick(() => {
        console.info(`[ChatPage] attach clicked chatId=${this.chatId}`);
        this.statusText = '附件功能暂未接入';
      })

      Row() {
        TextInput({ placeholder: '输入消息...', text: this.input })
          .fontSize(14)
          .fontColor('#222222')
          .placeholderColor('#8F9A91')
          .backgroundColor('#00ffffff')
          .layoutWeight(1)
          .onChange((value: string) => {
            this.input = value;
          })
        Text('◔')
          .fontSize(22)
          .fontColor('#7A8278')
          .width(30)
          .height(38)
          .textAlign(TextAlign.Center)
          .onClick(() => {
            console.info(`[ChatPage] emoji clicked chatId=${this.chatId}`);
            this.statusText = '表情面板暂未接入';
          })
      }
      .layoutWeight(1)
      .height(40)
      .padding({ left: 10, right: 7 })
      .margin({ left: 7, right: 7 })
      .borderRadius(20)
      .backgroundColor('#99ffffff')
      .shadow({ radius: 10, color: '#12000000', offsetY: 3 })

      Button() {
        if (this.input.trim().length > 0) {
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
      .backgroundColor('#99ffffff')
      .shadow({ radius: 10, color: '#16000000', offsetY: 3 })
      .onClick(() => {
        console.info(`[ChatPage] voice/send clicked chatId=${this.chatId}, textLength=${this.input.trim().length}`);
        if (this.input.trim()) {
          this.td.sendMessage(this.chatId, this.input);
          this.input = '';
          this.setBotMenuVisible(false);
        } else {
          this.statusText = '语音功能暂未接入';
        }
      })
    }
    .width('100%')
    .height(44)
  }

  @Builder
  private BotCommandSheet() {
    Column() {
      Scroll() {
        Column() {
          ForEach(this.botMenuCommands, (item: BotMenuCommandItem) => {
            Column() {
              Row() {
                Text(item.description.length > 0 ? item.description : item.command)
                  .fontSize(16)
                  .fontColor('#071018')
                  .maxLines(1)
                  .textOverflow({ overflow: TextOverflow.Ellipsis })
                  .layoutWeight(1)
                Text(`/${item.command}`)
                  .fontSize(14)
                  .fontColor('#899197')
                  .maxLines(1)
                  .textOverflow({ overflow: TextOverflow.Ellipsis })
                  .margin({ left: 12 })
              }
              .width('100%')
              .height(46)
              .padding({ left: 14, right: 14 })
              .onClick(() => {
                this.sendBotCommand(item.command);
              })

              Divider()
                .strokeWidth(0.6)
                .color('#4DB9C7C6')
                .margin({ left: 14, right: 14 })
            }
            .width('100%')
          }, (item: BotMenuCommandItem): string => item.id)
        }
        .width('100%')
        .padding({ left: 12, right: 12, top: 10, bottom: 0 })
      }
      .layoutWeight(1)
      .scrollBar(BarState.Off)
      .enableScrollInteraction(this.isBotMenuAtMaxHeight())
    }
    .width('100%')
    .height(this.botMenuSheetHeight)
    .borderRadius({ topLeft: 20, topRight: 20, bottomLeft: 0, bottomRight: 0 })
    .backgroundColor('#ffffffff')
    // .backdropBlur(22)
    .shadow({ radius: 12, color: '#14000000', offsetY: -3 })
    .opacity(this.botMenuVisible ? 1 : 0)
    .translate({ y: this.botMenuVisible ? 0 : this.botMenuSheetHeight })
    .animation({ duration: 220, curve: Curve.EaseOut })
    .gesture(
      PanGesture({ direction: PanDirection.Vertical })
        .onActionStart(() => {
          this.botMenuDragStartHeight = this.botMenuSheetHeight;
        })
        .onActionUpdate((event: GestureEvent) => {
          if (!this.botMenuVisible) {
            return;
          }
          this.botMenuSheetHeight = this.clampBotMenuSheetHeight(this.botMenuDragStartHeight - event.offsetY);
        })
        .onActionEnd(() => {
          if (this.botMenuSheetHeight <= this.botMenuMinSheetHeight + 30) {
            this.botMenuSheetHeight = this.botMenuMinSheetHeight;
          } else if (this.botMenuSheetHeight >= this.botMenuMaxSheetHeight - 40) {
            this.botMenuSheetHeight = this.botMenuMaxSheetHeight;
          }
        })
    )
  }

  @Builder
  private ReplyKeyboardPanel() {
    Column({ space: 6 }) {
      ForEach(this.replyKeyboardRows, (row: ReplyKeyboardButtonItem[]) => {
        Row({ space: 6 }) {
          ForEach(row, (button: ReplyKeyboardButtonItem) => {
            Button(button.text)
              .fontSize(12)
              .fontColor('#111111')
              .fontWeight(FontWeight.Medium)
              .height(32)
              .padding({ left: 8, right: 8 })
              .layoutWeight(1)
              .borderRadius(8)
              .backgroundColor('#EFFFFFFF')
              .shadow({ radius: 6, color: '#12000000', offsetY: 2 })
              .onClick(() => {
                this.sendReplyKeyboardButton(button);
              })
          }, (button: ReplyKeyboardButtonItem): string => button.id)
        }
        .width('100%')
      }, (row: ReplyKeyboardButtonItem[]): string => row.map((button: ReplyKeyboardButtonItem): string => button.id).join('|'))
    }
    .width('100%')
    .padding({ top: 8 })
  }

  @Builder
  private TopFloatingArea() {
    Stack({ alignContent: Alignment.TopStart }) {
      Stack({ alignContent: Alignment.TopStart }) {
        Column()
          .width('100%')
          .height(this.getTopFloatingHeight())
          .linearGradientBlur(AppLayout.TOP_GRADIENT_BLUR_RADIUS, {
            fractionStops: [[0, 0], [1, 1]],
            direction: GradientDirection.Top
          })
      }
      .width('100%')
      .height(this.getTopFloatingHeight())
      .clip(true)

      Column() {
        this.ChatHeader()
        this.PinnedMessageBar()
      }
      .width('100%')
      .height(this.getTopFloatingHeight())
      .position({ x: 0, y: 0 })

      if (this.showImageSaveButton) {
        Row() {
          SaveButton()
            .onClick((_event: ClickEvent, result: SaveButtonOnClickResult) => {
              console.info(`[ChatPage] SaveButton clicked result=${result}`);
              if (result === SaveButtonOnClickResult.SUCCESS) {
                this.saveImageToGallery(this.pendingImageSavePath);
                this.showImageSaveButton = false;
              } else {
                this.statusText = '保存授权失败';
              }
            })
          Button('取消')
            .margin({ left: 8 })
            .onClick(() => {
              this.showImageSaveButton = false;
              this.pendingImageSavePath = '';
              this.statusText = '';
            })
      }
        .width('100%')
        .padding(8)
        .backgroundColor('#66FFFFFF')
        .backdropBlur(12)
        .position({ x: 0, y: AppLayout.STATUS_BAR_HEIGHT + 46 })
      }
    }
    .width('100%')
    .height(this.getTopFloatingHeight())
  }

  @Builder
  private BottomFloatingArea() {
    Stack({ alignContent: Alignment.Bottom }) {
      Column()
        .width('100%')
        .height(95)
        .linearGradientBlur(50, {
          fractionStops: [[0, 0], [1, 1]],
          direction: GradientDirection.Bottom
        })

      if (this.shouldShowBotMenuButton()) {
        Row() {
          this.BotCommandSheet()
        }
        .width('100%')
        //.margin({ bottom: 28 + this.getReplyKeyboardHeight() })
      }

      Column() {
        Row() {
          if (this.isChannelChat) {
            this.ChannelNotificationButton()
          } else {
            this.Composer()
          }
        }
        .width('100%')

        if (!this.isChannelChat && this.replyKeyboardRows.length > 0) {
          this.ReplyKeyboardPanel()
        }
      }
      .width('100%')
      .padding({
        left: AppLayout.CHAT_COMPOSER_SIDE_PADDING,
        right: AppLayout.CHAT_COMPOSER_SIDE_PADDING,
        bottom: AppLayout.BOTTOM_SAFE_HEIGHT
      })
    }
    .width('100%')
    .height(this.getBottomFloatingHeight())
  }

  @Builder
  private ScrollToBottomButton() {
    Column() {
      Text(this.getUnreadDisplayText())
        .fontSize(10)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .textAlign(TextAlign.Center)
        .height(20)
        .padding({ left: 7, right: 7 })
        .borderRadius(10)
        .backgroundColor('#FF3B30')
        .margin({ bottom: 4 })
      Button({ type: ButtonType.Circle }) {
        Text('↓')
          .fontSize(24)
          .fontColor('#0A84FF')
          .textAlign(TextAlign.Center)
      }
      .width(44)
      .height(44)
      .backgroundColor('#EFFFFFFF')
      // .backdropBlur(18)
      .shadow({ radius: 12, color: '#22000000', offsetY: 4 })
      .onClick(() => {
        this.scrollToLatestAndMarkRead();
      })
    }
    .alignItems(HorizontalAlign.Center)
  }

  @Builder
  private ImagePreviewOverlay() {
    Stack({ alignContent: Alignment.Center }) {
      Column()
        .width('100%')
        .height('100%')
        .backgroundColor('#F0000000')
        .opacity(this.imagePreviewOpacity)
        .onClick(() => {
          this.closeImagePreview();
        })
      Image(this.imagePreviewPath)
        .width('100%')
        .height('100%')
        .objectFit(ImageFit.Contain)
        .opacity(this.imagePreviewOpacity)
        .scale({
          x: this.imagePreviewScale,
          y: this.imagePreviewScale,
          centerX: '50%',
          centerY: '50%'
        })
        .onClick(() => {
          this.closeImagePreview();
        })
    }
    .width('100%')
    .height('100%')
    .animation({ duration: 180, curve: Curve.EaseOut })
    .zIndex(99)
  }

  build() {
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

      List({ scroller: this.messageScroller }) {
        ListItem() {
          Column()
            .height(this.getTopContentInset())
        }
        ForEach(this.getMessageGroups(), (group: MessageGroupItem) => {
          ListItem() {
            Column() {
              if (this.groupContainsMessage(group, this.getFirstUnreadMessageId())) {
                this.UnreadDivider()
              }
              this.MessageGroupRow(group)
            }
            .width('100%')
          }
          .onVisibleAreaChange([0.0, 0.35], (isVisible: boolean, currentRatio: number) => {
            if (isVisible && currentRatio >= 0.35) {
              group.items.forEach((msg: MessageItem) => {
                this.requestVisibleMessageMediaOnce(msg);
                this.markVisibleMessageRead(msg);
              });
            }
          })
        }, (group: MessageGroupItem): string => group.id)
        ListItem() {
          Column()
            .height(this.getMessageListBottomInset())
        }
      }
      .width('100%')
      .height('100%')
      .backgroundColor(Color.Transparent)
      .contentEndOffset(this.getMessageListBottomInset())
      .scrollBar(BarState.Off)
      .onReachStart(() => {
        console.info(`[ChatPage] list reach start chatId=${this.chatId}`);
        this.loadOlderHistory();
      })
      .onReachEnd(() => {
        console.info(`[ChatPage] list reach end chatId=${this.chatId}`);
        this.loadNewerHistory();
      })

      Column() {
        this.TopFloatingArea()
      }
      .width('100%')
      .height(this.getTopFloatingHeight())
      .position({ x: 0, y: 0 })

      Stack({ alignContent: Alignment.Bottom }) {
        Column() {
          this.BottomFloatingArea()
        }
        .width('100%')
        .height(this.getBottomFloatingHeight())
      }
      .width('100%')
      .height('100%')
      .translate({ y: -this.keyboardHeight })
      .animation({ duration: 220, curve: Curve.EaseOut })
      .hitTestBehavior(HitTestMode.Transparent)

      if (this.unreadCount > 0) {
        Column() {
          Blank()
            .layoutWeight(1)
          Row() {
            Blank()
            this.ScrollToBottomButton()
          }
          .width('100%')
          .padding({ right: 18, bottom: this.getBottomFloatingHeight() + 14 })
        }
        .width('100%')
        .height('100%')
        .hitTestBehavior(HitTestMode.Transparent)
      }

      if (this.imagePreviewVisible) {
        this.ImagePreviewOverlay()
      }
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#97D394')
  }
}
