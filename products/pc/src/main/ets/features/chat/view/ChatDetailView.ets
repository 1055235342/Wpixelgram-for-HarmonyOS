// entry/src/main/ets/features/chat/view/ChatDetailView.ets
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
  TdMessageInteractionInfo,
  TdMessageReplyTo,
  TdMessageSender,
  TdMessageThreadInfo,
  TdPhoto,
  TdPhotoSize,
  TdReplyMarkup,
  TdSupergroup,
  TdUser,
  TdlibService,
  TdUpdate,
  TdVideo
} from '../../../common/service/TdlibService';
import { GalleryService } from '../../../common/service/GalleryService';
import { ChatMediaController } from '../viewmodel/ChatMediaController';
import { ChatDownloadCacheController } from '../viewmodel/ChatDownloadCacheController';
import { common, Want } from '@kit.AbilityKit';
import { fileIo } from '@kit.CoreFileKit';
import { KeyboardAvoidMode, window } from '@kit.ArkUI';
import { media } from '@kit.MediaKit';
import router from '@ohos.router';
import { AppLayout } from '../../../common/constants/AppLayout';
import { ChatAvatarView } from '../components/detail/ChatAvatarView';
import { ChatComposerBar } from '../components/composer/ChatComposerBar';
import { ChatHeaderBar } from '../components/header/ChatHeaderBar';
import { ChannelNotificationButtonView } from '../components/composer/ChannelNotificationButtonView';
import { AudioMessageBody } from '../components/media/AudioMessageBody';
import { DocumentMessageBody } from '../components/media/DocumentMessageBody';
import { MessageButtonPanelView } from '../components/detail/MessageButtonPanelView';
import { PhotoMessageBody } from '../components/media/PhotoMessageBody';
import { PinnedMessageBar } from '../components/detail/PinnedMessageBar';
import { ReadOnlyConversationBar } from '../components/composer/ReadOnlyConversationBar';
import { ReplyKeyboardPanelView } from '../components/composer/ReplyKeyboardPanelView';
import { UnreadDividerView } from '../components/detail/UnreadDividerView';
import { VideoMessageBody } from '../components/media/VideoMessageBody';
import {
  BotMenuCommandItem,
  ChatRouteParams,
  InlineVideoTimeItem,
  MediaPreviewItem,
  MessageButtonItem,
  MessageGroupItem,
  MessageItem,
  MessageTextRow,
  MessageTextSegment,
  OperationError,
  PhotoMediaState,
  ReplyKeyboardButtonItem,
  StartAbilityError,
  VideoRouteParams,
  createEmptyMessageItem
} from '../model/ChatDetailModels';
import {
  getChatCategory,
  getChatSubtitle,
  getCurrentChatCategory,
  isBotTitle
} from '../utils/ChatDetailMappers';
import { ChatMediaFormatters } from '../utils/ChatMediaFormatters';
import { ChatMessageGroupUtils } from '../utils/ChatMessageGroupUtils';
import { ChatMessageTextUtils } from '../utils/ChatMessageTextUtils';

@Entry
@Component
export struct ChatPage {
  @State messages: MessageItem[] = [];
  @State messageGroups: MessageGroupItem[] = [];
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
  @State canSendMessages: boolean = true;
  @State isChannelJoined: boolean = true;
  @State channelJoinPending: boolean = false;
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
  @State mediaPreviewItems: MediaPreviewItem[] = [];
  @State mediaPreviewIndex: number = 0;
  @State imagePreviewOpacity: number = 0;
  @State imagePreviewScale: number = 0.92;
  @State commentAvatarVersion: number = 0;
  @State photoRenderRevision: number = 0;
  @State thumbnailRenderRevision: number = 0;
  @State activeAudioMessageId: number = 0;
  @State activeAudioTitle: string = '';
  @State activeAudioPerformer: string = '';
  @State playingAudioMessageId: number = 0;
  @State isCommentMode: boolean = false;
  @State sourceCommentMessage: MessageItem | null = null;
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
  private mediaController: ChatMediaController = new ChatMediaController();
  private cacheController: ChatDownloadCacheController = ChatDownloadCacheController.getInstance();
  private messageIndexById: Map<number, number> = new Map();
  private mediaMessageIdsByFileId: Map<number, Set<number>> = new Map();
  private messageScroller: Scroller = new Scroller();
  private mediaPreviewSwiperController: SwiperController = new SwiperController();
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
  private audioPlayer: media.AVPlayer | null = null;
  private audioFile: fileIo.File | null = null;
  private preparingAudioMessageId: number = 0;
  private floatingPanelColor: string = '#E6FFFFFF';
  private pendingNavigationChatId: number = 0;
  private pendingNavigationMessageId: number = 0;
  private pendingCommentSourceChatId: number = 0;
  private pendingCommentSourceMessageId: number = 0;
  private pendingCommentSourceItem: MessageItem | null = null;
  private sourceCommentChatId: number = 0;
  private sourceCommentMessageId: number = 0;
  private currentSupergroupId: number = 0;
  private targetScrollToken: number = 0;
  private latestScrollToken: number = 0;
  private pendingScrollToRealLatest: boolean = false;
  private targetHistoryRetryCount: number = 0;
  private commentAvatarPaths: Map<string, string> = new Map();
  private commentAvatarFileKeys: Map<number, string> = new Map();
  private requestedCommentAvatarKeys: Set<string> = new Set();
  private keyboardWillShowCallback = (info: window.KeyboardInfo): void => {
    this.keyboardHeight = this.resolveKeyboardHeightVp(info);
    console.info(`[ChatPage] keyboard will show heightVp=${this.keyboardHeight}, rectTop=${info.endRect.top}, rectHeight=${info.endRect.height}`);
    this.scheduleScrollToLatestAt(false, 260);
  };
  private keyboardWillHideCallback = (_info: window.KeyboardInfo): void => {
    this.keyboardHeight = 0;
    console.info('[ChatPage] keyboard will hide');
  };
  private requestedMediaFileIds: Set<number> = new Set();
  private requestedVisibleMediaMessageIds: Set<number> = new Set();
  private pendingVisibleMediaMessageIds: Set<number> = new Set();
  private pendingVisibleReadMessageIds: Set<number> = new Set();
  private visibleWorkFlushScheduled: boolean = false;
  private fileRefreshAttempts: Map<number, number> = new Map();
  private mediaDebugLogging: boolean = false;
  private renderDebugLogging: boolean = true;
  private renderDebugLastAt: number = 0;
  private renderDebugSequence: number = 0;
  private updateDebugLastAt: number = 0;
  private updateDebugCounts: Map<string, number> = new Map();
  private updateDebugTotalCounts: Map<string, number> = new Map();
  private debugHeartbeatToken: number = 0;
  private lastRenderDebugReason: string = '';
  private lastRenderDebugCostMs: number = 0;
  private pendingOriginalPhotoPreviewMessageId: number = 0;
  private pendingOriginalPhotoSaveMessageId: number = 0;
  private visibleReadMessageIds: Set<number> = new Set();
  private pendingReadMessageIds: Set<number> = new Set();
  private readFlushScheduled: boolean = false;
  private readLoadedScheduled: boolean = false;

  aboutToAppear() {
    this.readRouteParams();
    console.error(`[ChatDetailDiag] ChatPage aboutToAppear chatId=${this.chatId}, initialChatId=${this.initialChatId}, embedded=${this.embedded}, target=${this.targetMessageId}`);
    console.warn(`[ChatPage][diag] appear chatId=${this.chatId}, initialChatId=${this.initialChatId}, embedded=${this.embedded}, target=${this.targetMessageId}, comment=${this.isCommentMode}`);
    this.startDebugHeartbeat();
    this.cacheController.setContext(getContext(this) as common.UIAbilityContext);
    this.cacheController.registerTdlibListeners();
    this.setupKeyboardAvoidance();
    this.registerListeners();
    if (this.chatId !== 0) {
      this.td.openChat(this.chatId);
      if (this.isCommentMode) {
        this.loadCommentHistory();
        return;
      }
      if (this.targetMessageId !== 0) {
        this.loadHistoryAroundMessage(this.targetMessageId);
      } else {
        this.refreshHistory();
      }
      this.scheduleInitialHistoryFallback();
    } else {
      this.statusText = '会话参数错误';
      console.error('[ChatPage] chatId is invalid');
    }
  }

  aboutToDisappear() {
    this.debugHeartbeatToken++;
    console.warn(`[ChatPage][diag] disappear chatId=${this.chatId}, messages=${this.messages.length}, groups=${this.messageGroups.length}`);
    this.markLoadedUnreadMessagesRead();
    this.flushVisibleReads();
    this.releaseAudioPlayer(true);
    this.mediaController.clear();
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

  private startDebugHeartbeat(): void {
    const token = ++this.debugHeartbeatToken;
    const tick = (): void => {
      if (token !== this.debugHeartbeatToken) {
        return;
      }
      const updateParts: string[] = [];
      this.updateDebugTotalCounts.forEach((count: number, key: string) => {
        updateParts.push(`${key}:${count}`);
      });
      console.warn(`[ChatPage][diag] heartbeat chatId=${this.chatId}, messages=${this.messages.length}, groups=${this.messageGroups.length}, historyLoading=${this.historyLoading}, status=${this.statusText}, lastRender=${this.lastRenderDebugReason}, lastCost=${this.lastRenderDebugCostMs}ms, updates=${updateParts.join(',')}`);
      setTimeout(tick, 3000);
    };
    setTimeout(tick, 3000);
  }

  private scheduleInitialHistoryFallback(): void {
    const chatId = this.chatId;
    const targetMessageId = this.targetMessageId;
    setTimeout(() => {
      if (this.chatId !== chatId || this.messages.length > 0 || targetMessageId !== 0) {
        return;
      }
      console.info(`[ChatPage] initial history fallback chatId=${this.chatId}, loading=${this.historyLoading}`);
      this.historyLoading = false;
      this.historyMode = 'replace';
      this.historyRequestSource = 'latest';
      this.historyFallbackTried = false;
      this.td.getChat(this.chatId);
      this.td.getChatHistory(this.chatId, this.getInitialHistoryLimit(), 0, 0);
    }, 900);
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

  private resolveKeyboardHeightVp(info: window.KeyboardInfo): number {
    let keyboardHeightPx = Math.max(0, info.endRect.height);
    let windowHeightVp = 0;

    try {
      if (this.keyboardWindow) {
        const properties = this.keyboardWindow.getWindowProperties();
        const windowBottomPx = properties.windowRect.top + properties.windowRect.height;
        windowHeightVp = this.getUIContext().px2vp(properties.windowRect.height);
        if (info.endRect.top > 0 && info.endRect.top < windowBottomPx) {
          keyboardHeightPx = windowBottomPx - info.endRect.top;
        }
      }
    } catch (err) {
      const error = err as StartAbilityError;
      console.error(`[ChatPage] resolve keyboard height failed code=${error.code}, message=${error.message}`);
    }

    const keyboardHeightVp = this.getUIContext().px2vp(keyboardHeightPx);
    const maxKeyboardHeightVp = windowHeightVp > 0 ? windowHeightVp * 0.55 : 420;
    return Math.min(Math.max(0, keyboardHeightVp), maxKeyboardHeightVp);
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
        this.canSendMessages = !this.isChannelChat;
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
      this.canSendMessages = !this.isChannelChat;
    }
    if (params && params.unreadCount !== undefined) {
      this.unreadCount = Number(params.unreadCount);
    }
    this.entryUnreadCount = this.unreadCount;
    if (params && params.lastReadInboxMessageId !== undefined) {
      this.lastReadInboxMessageId = Number(params.lastReadInboxMessageId);
    }
    if (params && params.commentMode !== undefined) {
      this.isCommentMode = params.commentMode === true || params.commentMode === 'true';
    }
    if (params && params.sourceChatId !== undefined) {
      this.sourceCommentChatId = Number(params.sourceChatId);
    }
    if (params && params.sourceMessageId !== undefined) {
      this.sourceCommentMessageId = Number(params.sourceMessageId);
    }
    if (this.isCommentMode && params && params.commentCount !== undefined) {
      this.chatTitle = this.getCommentCountText(Number(params.commentCount));
      this.chatSubtitle = '';
      this.canSendMessages = true;
      this.isChannelChat = false;
    }
    if (this.isCommentMode && params && params.sourceMessageJson !== undefined && params.sourceMessageJson.length > 0) {
      this.sourceCommentMessage = this.parseSourceCommentMessage(params.sourceMessageJson);
    }
    console.info(`[ChatPage] route params chatId=${this.chatId}, messageId=${this.targetMessageId}, title=${this.chatTitle}`);
  }

  private parseSourceCommentMessage(value: string): MessageItem | null {
    try {
      return JSON.parse(value) as MessageItem;
    } catch (err) {
      console.error(`[ChatPage] parse source comment message failed ${JSON.stringify(err)}`);
      return null;
    }
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
        if (this.isCommentMode && message.id === this.sourceCommentMessageId) {
          return;
        }
        if (this.isCommentMode || this.isCurrentChatMessage(message)) {
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
      const completedHistoryMode = this.historyMode;
      if (completedHistoryMode === 'prepend') {
        const beforeCount = this.messages.length;
        const newestLoadedMessageId = nextMessages.length > 0 ? nextMessages[nextMessages.length - 1].id : 0;
        this.mergeMessages(nextMessages);
        this.hasMoreHistory = this.messages.length > beforeCount;
        this.restoreScrollAfterPrepend(newestLoadedMessageId, this.prependAnchorMessageId);
      } else if (completedHistoryMode === 'append') {
        const beforeCount = this.messages.length;
        this.mergeMessages(nextMessages);
        this.refreshReplyKeyboardFromMessages(historyMessages);
        this.prefetchInitialMessageMedia();
        this.hasMoreNewerHistory = this.messages.length > beforeCount && nextMessages.length >= this.getInitialHistoryLimit();
      } else {
        this.setMessages(this.resolveReplyTexts(ChatMessageGroupUtils.sortMessages(nextMessages)),
          `history:${this.historyMode}:${this.historyRequestSource}`);
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
      if (this.targetMessageId !== 0 && completedHistoryMode === 'replace') {
        this.scheduleScrollToTarget(false, 'historyLoaded');
      }
      this.historyMode = 'append';
      this.continuePendingScrollToRealLatest();
    });
    this.listenUpdate('chat', (update: TdUpdate) => {
      if (update.id === undefined || update.title === undefined) {
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
        notification_settings: update.notification_settings,
        permissions: update.permissions
      };
      if (chat.id === this.pendingNavigationChatId && this.pendingNavigationMessageId !== 0) {
        const messageId = this.pendingNavigationMessageId;
        this.pendingNavigationChatId = 0;
        this.pendingNavigationMessageId = 0;
        this.openResolvedMessageTarget(chat, messageId);
        return;
      }
      this.applyCommentAvatarFromChat(chat);
      if (chat.id !== this.chatId) {
        return;
      }
      console.info(`[ChatPage] received chat title=${chat.title}, id=${chat.id}`);
      this.applyChatInfo(chat);
    });
    this.listenUpdate('user', (update: TdUpdate) => {
      const user = update as TdUser;
      this.applyCommentAvatarFromUser(user);
    });
    this.listenUpdate('supergroup', (update: TdUpdate) => {
      if (update.id === undefined || update.id !== this.currentSupergroupId) {
        return;
      }
      const supergroup: TdSupergroup = {
        id: update.id,
        is_channel: update.is_channel,
        status: update.status
      };
      this.applySupergroupAccess(supergroup);
    });
    this.listenUpdate('updateSupergroup', (update: TdUpdate) => {
      if (!update.supergroup || update.supergroup.id !== this.currentSupergroupId) {
        return;
      }
      this.applySupergroupAccess(update.supergroup);
    });
    this.listenUpdate('updateNewMessage', (update: TdUpdate) => {
      const message: TdMessage | undefined = update.message;
      if (!message || !this.isCurrentChatMessage(message)) {
        return;
      }
      this.noteUpdateDebug('updateNewMessage', `messageId=${message.id}`);
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
        this.noteUpdateDebug('updateMessageContent', `messageId=${update.message_id}`);
        console.info(`[ChatPage] received updateMessageContent messageId=${update.message_id}`);
        this.applyMessageContentUpdate(update.message_id, update.new_content);
      }
    });
    this.listenUpdate('updateMessageInteractionInfo', (update: TdUpdate) => {
      if (update.chat_id === this.chatId && update.message_id !== undefined) {
        this.noteUpdateDebug('updateMessageInteractionInfo', `messageId=${update.message_id}`);
        console.info(`[ChatPage] received updateMessageInteractionInfo messageId=${update.message_id}`);
        this.applyMessageInteractionInfoUpdate(update.message_id, update.interaction_info);
      }
    });
    this.listenUpdate('updateMessageEdited', (update: TdUpdate) => {
      if (update.chat_id === this.chatId && update.message_id !== undefined) {
        this.noteUpdateDebug('updateMessageEdited', `messageId=${update.message_id}`);
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
          this.noteUpdateDebug('updateChatReplyMarkup', `messageId=${message.id}`);
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
      this.noteUpdateDebug('message', `messageId=${message.id}`);
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
        this.openMessageTarget(targetChatId, targetMessageId);
      } else {
        this.statusText = '无法定位这条消息';
      }
    });
    this.listenUpdate('messageThreadInfo', (update: TdUpdate) => {
      this.openResolvedMessageThread(update as TdMessageThreadInfo);
    });
    this.listenUpdate('file', (update: TdUpdate) => {
      if (update.id !== undefined && update.id > 0) {
        const file: TdFile = {
          id: update.id,
          size: update.size,
          expected_size: update.expected_size,
          local: update.local,
          remote: update.remote
        };
        this.logMediaDebug(`[ChatPage][media] received file id=${file.id}, ${this.getFileDebugText(file)}`);
        this.applyFileUpdate(file);
      }
    });
    this.listenUpdate('updateFile', (update: TdUpdate) => {
      if (update.file) {
        this.noteUpdateDebug('updateFile', `fileId=${update.file.id}`);
        this.logMediaDebug(`[ChatPage][media] received updateFile id=${update.file.id}, ${this.getFileDebugText(update.file)}`);
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
    if (this.isCommentMode) {
      console.info(`[ChatPage] skip loadOlderHistory in comment mode chatId=${this.chatId}`);
      return;
    }
    if (this.historyLoading || !this.hasMoreHistory || this.chatId === 0 || this.messages.length === 0) {
      return;
    }
    this.cancelPendingLatestScroll();
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
    if (this.isCommentMode) {
      console.info(`[ChatPage] skip loadNewerHistory in comment mode chatId=${this.chatId}`);
      return;
    }
    if (this.historyLoading || !this.hasMoreNewerHistory || this.chatId === 0 || this.messages.length === 0) {
      return;
    }
    this.cancelPendingLatestScroll();
    const newestMessageId = this.messages[this.messages.length - 1].id;
    this.historyLoading = true;
    this.historyMode = 'append';
    this.historyRequestSource = 'newer';
    this.statusText = '正在加载最新消息...';
    console.info(`[ChatPage] loadNewerHistory chatId=${this.chatId}, fromMessageId=${newestMessageId}`);
    this.td.getChatHistory(this.chatId, this.getInitialHistoryLimit(), newestMessageId, -this.getInitialHistoryLimit());
  }

  private requestRealLatestHistory(): void {
    if (this.isCommentMode || this.chatId === 0) {
      this.finishScrollToLatestAndMarkRead();
      return;
    }
    if (this.historyLoading) {
      this.pendingScrollToRealLatest = true;
      return;
    }
    if (this.messages.length === 0) {
      this.pendingScrollToRealLatest = true;
      this.refreshHistory();
      return;
    }
    if (!this.hasMoreNewerHistory) {
      this.finishScrollToLatestAndMarkRead();
      return;
    }
    this.pendingScrollToRealLatest = true;
    this.loadNewerHistory();
  }

  private continuePendingScrollToRealLatest(): void {
    if (!this.pendingScrollToRealLatest) {
      return;
    }
    if (this.historyLoading) {
      return;
    }
    if (this.hasMoreNewerHistory) {
      this.loadNewerHistory();
      return;
    }
    this.pendingScrollToRealLatest = false;
    this.finishScrollToLatestAndMarkRead();
  }

  private loadHistoryAroundMessage(messageId: number): void {
    this.historyLoading = true;
    this.historyMode = 'replace';
    this.historyRequestSource = 'target';
    this.historyFallbackTried = false;
    this.targetHistoryRetryCount = 0;
    this.statusText = '正在定位消息...';
    console.info(`[ChatPage] loadHistoryAroundMessage chatId=${this.chatId}, messageId=${messageId}`);
    this.td.openMessageContent(this.chatId, messageId);
    this.td.getMessage(this.chatId, messageId);
    this.td.getChatHistory(this.chatId, 20, messageId, -10);
  }

  private loadCommentHistory(): void {
    if (this.sourceCommentChatId === 0 || this.sourceCommentMessageId === 0) {
      this.statusText = '评论参数错误';
      return;
    }
    this.historyLoading = true;
    this.historyMode = 'replace';
    this.historyRequestSource = 'comments';
    this.statusText = '正在加载评论...';
    console.info(`[ChatPage] loadCommentHistory sourceChatId=${this.sourceCommentChatId}, sourceMessageId=${this.sourceCommentMessageId}, commentChatId=${this.chatId}`);
    this.td.getMessageThreadHistory(this.sourceCommentChatId, this.sourceCommentMessageId, 0, 0, 30);
  }

  private getInitialHistoryLimit(): number {
    return 20;
  }

  private toMessageItem(message: TdMessage): MessageItem {
    if (this.messageCache.has(message.id)) {
      const cached = this.messageCache.get(message.id)!;
      this.hydrateCachedMessageMedia(cached, message.content);
      return cached;
    }
    const content: TdMessageContent | undefined = message.content;
    const item: MessageItem = {
      id: message.id,
      mediaAlbumId: message.media_album_id ? message.media_album_id : 0,
      isSelf: message.is_outgoing,
      isTarget: this.targetMessageId !== 0 && message.id === this.targetMessageId,
      senderAvatarKey: this.getMessageSenderKey(message.sender_id),
      senderAvatarLabel: message.sender_id ? this.getMessageSenderLabel(message.sender_id) : this.getAvatarText(this.chatTitle),
      mediaType: this.getNormalizedMediaType(content),
      mediaFormat: this.getContentMediaFormat(content),
      text: this.getMessageText(content),
      textRows: ChatMessageTextUtils.getRows(this.getMessageFormattedText(content)),
      replyText: this.getReplyText(message.reply_to),
      replyMessageId: this.getReplyMessageId(message.reply_to),
      buttonRows: this.getMessageButtonRows(message.reply_markup),
      photoPath: '',
      originalPhotoPath: '',
      videoPath: '',
      thumbnailPath: '',
      photoFileId: 0,
      originalPhotoFileId: 0,
      photoDownloadedSize: 0,
      photoExpectedSize: 0,
      originalPhotoDownloadedSize: 0,
      originalPhotoExpectedSize: 0,
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
      viewCount: this.getMessageViewCount(message),
      commentCount: this.getMessageCommentCount(message),
      commentAvatars: this.getMessageCommentAvatars(message),
      commentAvatarKeys: this.getMessageCommentAvatarKeys(message),
      commentThreadMessageId: this.getMessageCommentThreadMessageId(message),
      mediaVersion: 0
    };
    this.requestSenderAvatar(item);
    if (content && content.type === 'messagePhoto' && content.photo) {
      const size: TdPhotoSize | undefined = this.getPreviewPhotoSize(content.photo);
      if (size) {
        const photoFile = this.getLatestFile(size.photo);
        const state = this.getPhotoMediaState(photoFile);
        this.applyPhotoMediaStateToItem(item, state);
        item.mediaWidth = size.width;
        item.mediaHeight = size.height;
        console.info(`[ChatPage][media] toMessageItem photo messageId=${message.id}, sizeType=${size.type}, fileId=${state.fileId}, sourceFileId=${size.photo.id}, path=${state.path}, downloaded=${state.downloadedSize}, expected=${state.expectedSize}, local=${this.getFileDebugText(photoFile)}`);
      }
      const originalSize: TdPhotoSize | undefined = this.getBestPhotoSize(content.photo);
      if (originalSize) {
        const originalFile = this.getLatestFile(originalSize.photo);
        const originalState = this.getPhotoMediaState(originalFile);
        this.applyOriginalPhotoMediaStateToItem(item, originalState);
      }
    }
    if (content && content.type === 'messageVideo' && content.video) {
      const video: TdVideo = content.video;
      const videoFile = this.getLatestFile(video.video);
      item.videoFileId = videoFile.id;
      item.videoPath = this.getLocalPath(videoFile);
      item.videoDownloadedSize = this.getDownloadedSize(videoFile);
      item.videoExpectedSize = this.getExpectedSize(videoFile);
      item.videoCanPlay = this.canPlayVideo(videoFile);
      item.videoDuration = video.duration ? video.duration : 0;
      item.mediaWidth = video.width ? video.width : 0;
      item.mediaHeight = video.height ? video.height : 0;
      if (video.thumbnail && video.thumbnail.file) {
        const thumbnailFile = this.getLatestFile(video.thumbnail.file);
        item.thumbnailFileId = thumbnailFile.id;
        item.thumbnailPath = this.getCompletedLocalPath(thumbnailFile);
      }
    }
    if (content && content.type === 'messageAnimation' && content.animation) {
      const animation: TdAnimation = content.animation;
      const animationFile = this.getLatestFile(animation.animation);
      item.videoFileId = animationFile.id;
      item.videoPath = this.getLocalPath(animationFile);
      item.videoDownloadedSize = this.getDownloadedSize(animationFile);
      item.videoExpectedSize = this.getExpectedSize(animationFile);
      item.videoCanPlay = this.canPlayVideo(animationFile);
      item.videoDuration = animation.duration ? animation.duration : 0;
      item.mediaWidth = animation.width ? animation.width : 0;
      item.mediaHeight = animation.height ? animation.height : 0;
      if (animation.thumbnail && animation.thumbnail.file) {
        const thumbnailFile = this.getLatestFile(animation.thumbnail.file);
        item.thumbnailFileId = thumbnailFile.id;
        item.thumbnailPath = this.getCompletedLocalPath(thumbnailFile);
      }
    }
    if (content && content.type === 'messageDocument' && content.document) {
      const document: TdDocument = content.document;
      item.documentFileId = document.document.id;
      item.documentFileName = document.file_name && document.file_name.length > 0 ? document.file_name : '未命名文件';
      item.documentSize = this.getExpectedSize(document.document);
      item.mediaFormat = ChatMediaFormatters.getMediaFormat(document.file_name, document.mime_type, this.getLocalPath(document.document), 'file');
    }
    if (content && content.type === 'messageAudio' && content.audio) {
      this.applyAudioContentToItem(item, content.audio);
    }
    this.requestCommentAvatars(item);
    this.messageCache.set(message.id, item);
    return item;
  }

  private hydrateCachedMessageMedia(item: MessageItem, content: TdMessageContent | undefined): void {
    if (!content) {
      return;
    }
    if (content.type === 'messagePhoto' && content.photo) {
      const size: TdPhotoSize | undefined = this.getPreviewPhotoSize(content.photo);
      if (size) {
        const photoFile = this.getLatestFile(size.photo);
        const state = this.getPhotoMediaState(photoFile);
        if (this.applyPhotoMediaStateToItem(item, state)) {
          item.mediaVersion += 1;
        }
      }
      const originalSize: TdPhotoSize | undefined = this.getBestPhotoSize(content.photo);
      if (originalSize) {
        const originalFile = this.getLatestFile(originalSize.photo);
        if (this.applyOriginalPhotoMediaStateToItem(item, this.getPhotoMediaState(originalFile))) {
          item.mediaVersion += 1;
        }
      }
    }
    if (content.type === 'messageVideo' && content.video) {
      const videoFile = this.getLatestFile(content.video.video);
      const path = this.getLocalPath(videoFile);
      item.videoFileId = videoFile.id;
      item.videoDownloadedSize = this.getDownloadedSize(videoFile);
      item.videoExpectedSize = this.getExpectedSize(videoFile);
      item.videoCanPlay = this.canPlayVideo(videoFile);
      if (path.length > 0 && path !== item.videoPath) {
        item.videoPath = path;
        item.mediaVersion += 1;
      }
      if (content.video.thumbnail && content.video.thumbnail.file) {
        const thumbnailFile = this.getLatestFile(content.video.thumbnail.file);
        const thumbnailPath = this.getCompletedLocalPath(thumbnailFile);
        item.thumbnailFileId = thumbnailFile.id;
        if (thumbnailPath.length > 0 && thumbnailPath !== item.thumbnailPath) {
          item.thumbnailPath = thumbnailPath;
          item.mediaVersion += 1;
        }
      }
    }
    if (content.type === 'messageAnimation' && content.animation) {
      const animationFile = this.getLatestFile(content.animation.animation);
      const path = this.getLocalPath(animationFile);
      item.videoFileId = animationFile.id;
      item.videoDownloadedSize = this.getDownloadedSize(animationFile);
      item.videoExpectedSize = this.getExpectedSize(animationFile);
      item.videoCanPlay = this.canPlayVideo(animationFile);
      if (path.length > 0 && path !== item.videoPath) {
        item.videoPath = path;
        item.mediaVersion += 1;
      }
      if (content.animation.thumbnail && content.animation.thumbnail.file) {
        const thumbnailFile = this.getLatestFile(content.animation.thumbnail.file);
        const thumbnailPath = this.getCompletedLocalPath(thumbnailFile);
        item.thumbnailFileId = thumbnailFile.id;
        if (thumbnailPath.length > 0 && thumbnailPath !== item.thumbnailPath) {
          item.thumbnailPath = thumbnailPath;
          item.mediaVersion += 1;
        }
      }
    }
  }

  private applyAudioContentToItem(item: MessageItem, audio: TdAudio): void {
    item.audioFileId = audio.audio.id;
    item.audioPath = this.getLocalPath(audio.audio);
    item.audioTitle = this.getAudioTitle(audio);
    item.audioPerformer = audio.performer && audio.performer.length > 0 ? audio.performer : '音频';
    item.audioDuration = audio.duration ? audio.duration : 0;
    item.audioDownloadedSize = this.getDownloadedSize(audio.audio);
    item.audioExpectedSize = this.getExpectedSize(audio.audio);
    item.mediaFormat = ChatMediaFormatters.getMediaFormat(audio.file_name, audio.mime_type, this.getLocalPath(audio.audio), 'mp3');
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
      const format = ChatMediaFormatters.getMediaFormat(content.video.file_name, content.video.mime_type, this.getLocalPath(content.video.video), '');
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
      return size ? ChatMediaFormatters.getMediaFormat('', '', this.getLocalPath(size.photo), 'jpg') : 'jpg';
    }
    if (content.type === 'messageVideo' && content.video) {
      return ChatMediaFormatters.getMediaFormat(content.video.file_name, content.video.mime_type, this.getLocalPath(content.video.video), 'mp4');
    }
    if (content.type === 'messageAnimation' && content.animation) {
      return ChatMediaFormatters.getMediaFormat(content.animation.file_name, content.animation.mime_type, this.getLocalPath(content.animation.animation), 'gif');
    }
    if (content.type === 'messageDocument' && content.document) {
      return ChatMediaFormatters.getMediaFormat(content.document.file_name, content.document.mime_type, this.getLocalPath(content.document.document), 'file');
    }
    if (content.type === 'messageAudio' && content.audio) {
      return ChatMediaFormatters.getMediaFormat(content.audio.file_name, content.audio.mime_type, this.getLocalPath(content.audio.audio), 'mp3');
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

  private getMessageCommentCount(message: TdMessage): number {
    if (message.interaction_info && message.interaction_info.reply_info &&
      message.interaction_info.reply_info.reply_count !== undefined) {
      return message.interaction_info.reply_info.reply_count;
    }
    return 0;
  }

  private getMessageCommentAvatars(message: TdMessage): string[] {
    if (!message.interaction_info || !message.interaction_info.reply_info ||
      !message.interaction_info.reply_info.recent_replier_ids) {
      return [];
    }
    return this.getCommentAvatarLabels(message.interaction_info.reply_info.recent_replier_ids);
  }

  private getMessageCommentAvatarKeys(message: TdMessage): string[] {
    if (!message.interaction_info || !message.interaction_info.reply_info ||
      !message.interaction_info.reply_info.recent_replier_ids) {
      return [];
    }
    return this.getCommentAvatarKeys(message.interaction_info.reply_info.recent_replier_ids);
  }

  private getCommentAvatarLabels(senders: TdMessageSender[]): string[] {
    const labels: string[] = [];
    senders.forEach((sender: TdMessageSender) => {
      if (labels.length >= 3) {
        return;
      }
      const label = this.getMessageSenderLabel(sender);
      if (label.length > 0) {
        labels.push(label);
      }
    });
    return labels;
  }

  private getCommentAvatarKeys(senders: TdMessageSender[]): string[] {
    const keys: string[] = [];
    senders.forEach((sender: TdMessageSender) => {
      if (keys.length >= 3) {
        return;
      }
      const key = this.getMessageSenderKey(sender);
      if (key.length > 0) {
        keys.push(key);
      }
    });
    return keys;
  }

  private getMessageSenderLabel(sender: TdMessageSender | undefined): string {
    if (!sender) {
      return '?';
    }
    const id = sender.user_id !== undefined ? sender.user_id : (sender.chat_id !== undefined ? sender.chat_id : 0);
    if (id === 0) {
      return '?';
    }
    const text = `${Math.abs(id)}`;
    return text.substring(text.length - 1);
  }

  private getMessageSenderKey(sender: TdMessageSender | undefined): string {
    if (!sender) {
      return '';
    }
    if (sender.user_id !== undefined && sender.user_id !== 0) {
      return `user:${sender.user_id}`;
    }
    if (sender.chat_id !== undefined && sender.chat_id !== 0) {
      return `chat:${sender.chat_id}`;
    }
    return '';
  }

  private requestCommentAvatars(msg: MessageItem): void {
    msg.commentAvatarKeys.forEach((key: string) => {
      if (this.requestedCommentAvatarKeys.has(key) || this.commentAvatarPaths.has(key)) {
        return;
      }
      this.requestedCommentAvatarKeys.add(key);
      if (key.startsWith('user:')) {
        this.td.getUser(Number(key.substring(5)));
      } else if (key.startsWith('chat:')) {
        this.td.getChat(Number(key.substring(5)));
      }
    });
  }

  private requestSenderAvatar(msg: MessageItem): void {
    const key = msg.senderAvatarKey;
    if (key.length === 0 || this.requestedCommentAvatarKeys.has(key) || this.commentAvatarPaths.has(key)) {
      return;
    }
    this.requestedCommentAvatarKeys.add(key);
    if (key.startsWith('user:')) {
      this.td.getUser(Number(key.substring(5)));
    } else if (key.startsWith('chat:')) {
      this.td.getChat(Number(key.substring(5)));
    }
  }

  private getCommentAvatarPath(key: string): string {
    const version = this.commentAvatarVersion;
    const path = this.commentAvatarPaths.get(key);
    return version >= 0 && path ? path : '';
  }

  private applyCommentAvatarFromUser(user: TdUser): void {
    if (user.id === undefined || !user.profile_photo || !user.profile_photo.small) {
      return;
    }
    this.applyCommentAvatarFile(`user:${user.id}`, user.profile_photo.small);
  }

  private applyCommentAvatarFromChat(chat: TdChat): void {
    if (!chat.photo || !chat.photo.small) {
      return;
    }
    this.applyCommentAvatarFile(`chat:${chat.id}`, chat.photo.small);
  }

  private applyCommentAvatarFile(key: string, file: TdFile): void {
    this.commentAvatarFileKeys.set(file.id, key);
    const path = this.getLocalPath(file);
    if (path.length > 0) {
      this.commentAvatarPaths.set(key, path);
      this.commentAvatarVersion += 1;
      this.refreshAvatarBindings();
      return;
    }
    if (!file.local || !file.local.is_downloading_completed) {
      this.td.downloadFile(file.id, 8);
    }
  }

  private getMessageCommentThreadMessageId(message: TdMessage): number {
    if (message.interaction_info && message.interaction_info.reply_info &&
      message.interaction_info.reply_info.last_message_id !== undefined) {
      return message.interaction_info.reply_info.last_message_id;
    }
    return 0;
  }

  private getCommentCountText(count: number): string {
    if (count > 999) {
      return `${Math.floor(count / 1000)}k 条评论`;
    }
    return `${count} 条评论`;
  }

  private getMessageTextSegmentColor(msg: MessageItem, row: MessageTextRow, segment: MessageTextSegment): string {
    if (row.url.length > 0 || segment.type === 'hashtag') {
      return '#0A66CC';
    }
    if (this.isRobotMessage(msg) && ChatMessageTextUtils.extractBotCommandFromText(row.text).length > 0) {
      return '#0A66CC';
    }
    return '#111111';
  }

  private openMessageComments(msg: MessageItem): void {
    console.info(`[ChatPage] comments entry clicked chatId=${this.chatId}, messageId=${msg.id}, count=${msg.commentCount}`);
    this.pendingCommentSourceChatId = this.chatId;
    this.pendingCommentSourceMessageId = msg.id;
    this.pendingCommentSourceItem = msg;
    this.statusText = '正在打开评论区...';
    this.td.getMessageThread(this.chatId, msg.id);
    this.td.openMessageContent(this.chatId, msg.id);
  }

  private openResolvedMessageThread(info: TdMessageThreadInfo): void {
    const sourceChatId = this.pendingCommentSourceChatId;
    const sourceMessageId = this.pendingCommentSourceMessageId;
    const sourceItem = this.pendingCommentSourceItem;
    this.pendingCommentSourceChatId = 0;
    this.pendingCommentSourceMessageId = 0;
    this.pendingCommentSourceItem = null;
    const targetChatId = info.chat_id !== undefined && info.chat_id !== 0 ? info.chat_id : sourceChatId;
    const targetMessageId = this.getThreadTargetMessageId(info, sourceMessageId);
    console.info(`[ChatPage] resolved comment thread sourceChatId=${sourceChatId}, sourceMessageId=${sourceMessageId}, targetChatId=${targetChatId}, targetMessageId=${targetMessageId}, threadId=${info.message_thread_id}`);
    if (targetChatId !== 0 && sourceChatId !== 0 && sourceMessageId !== 0 && sourceItem !== null) {
      router.pushUrl({
        url: 'features/chat/view/ChatDetailView',
        params: {
          chatId: targetChatId,
          messageId: targetMessageId,
          title: this.getCommentCountText(sourceItem.commentCount),
          commentMode: true,
          sourceChatId: sourceChatId,
          sourceMessageId: sourceMessageId,
          sourceMessageJson: JSON.stringify(sourceItem),
          commentCount: sourceItem.commentCount
        }
      });
      return;
    }
    this.statusText = '无法打开评论区';
  }

  private getThreadTargetMessageId(info: TdMessageThreadInfo, fallbackMessageId: number): number {
    if (info.reply_info && info.reply_info.last_message_id !== undefined && info.reply_info.last_message_id !== 0) {
      return info.reply_info.last_message_id;
    }
    if (info.messages && info.messages.length > 0) {
      return info.messages[info.messages.length - 1].id;
    }
    if (info.message_thread_id !== undefined && info.message_thread_id !== 0) {
      return info.message_thread_id;
    }
    return fallbackMessageId;
  }

  private getSourceCommentDisplayMessage(): MessageItem {
    if (this.sourceCommentMessage === null) {
      return this.createCommentPlaceholderMessage();
    }
    const next = this.copyMessageItem(this.sourceCommentMessage, this.sourceCommentMessage.replyText);
    next.commentCount = 0;
    next.commentAvatars = [];
    next.commentAvatarKeys = [];
    next.commentThreadMessageId = 0;
    next.buttonRows = [];
    return next;
  }

  private createCommentPlaceholderMessage(): MessageItem {
    const item = createEmptyMessageItem();
    item.id = this.sourceCommentMessageId;
    item.isSelf = false;
    item.text = '原消息加载中...';
    item.textRows = ChatMessageTextUtils.getRows({ '@type': 'formattedText', text: item.text });
    item.commentCount = 0;
    item.buttonRows = [];
    return item;
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
    return AppLayout.STATUS_BAR_HEIGHT + 66 + this.getTopInfoPanelHeight();
  }

  private getTopFloatingHeight(): number {
    return AppLayout.STATUS_BAR_HEIGHT + 86 + this.getTopInfoPanelHeight();
  }

  private getTopInfoPanelHeight(): number {
    const hasAudio = this.activeAudioMessageId > 0;
    const hasPinned = this.pinnedMessageText.length > 0;
    if (hasAudio && hasPinned) {
      return 88;
    }
    if (hasAudio) {
      return 46;
    }
    if (hasPinned) {
      return 50;
    }
    return 0;
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
    if (this.isCommentMode) {
      this.chatAvatarText = this.getAvatarText(this.chatTitle);
      return;
    }
    this.chatTitle = chat.title.length > 0 ? chat.title : this.chatTitle;
    this.chatAvatarText = this.getAvatarText(this.chatTitle);
    const category = this.getChatCategory(chat);
    this.isChannelChat = category === '频道';
    if (chat.permissions && chat.permissions.can_send_basic_messages !== undefined) {
      this.canSendMessages = chat.permissions.can_send_basic_messages;
    } else {
      this.canSendMessages = !this.isChannelChat;
    }
    this.currentSupergroupId = chat.type && chat.type.supergroup_id ? chat.type.supergroup_id : 0;
    if (this.isChannelChat && this.currentSupergroupId !== 0) {
      this.td.getSupergroup(this.currentSupergroupId);
    }
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

  private applySupergroupAccess(supergroup: TdSupergroup): void {
    if (!this.isChannelChat || !supergroup.status) {
      return;
    }
    const status = supergroup.status;
    const statusType = status.type;
    this.isChannelJoined = statusType === 'chatMemberStatusCreator' ||
      statusType === 'chatMemberStatusAdministrator' ||
      statusType === 'chatMemberStatusMember' ||
      (statusType === 'chatMemberStatusRestricted' && status.is_member === true);

    const isCreator = statusType === 'chatMemberStatusCreator';
    const isPostingAdministrator = statusType === 'chatMemberStatusAdministrator' &&
      status.rights !== undefined && status.rights.can_post_messages === true;
    this.canSendMessages = isCreator || isPostingAdministrator;
    this.channelJoinPending = false;
    console.info(`[ChatPage] channel access chatId=${this.chatId}, status=${statusType}, joined=${this.isChannelJoined}, canSend=${this.canSendMessages}`);
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
    return getChatCategory(chat);
  }

  private isBotTitle(title: string): boolean {
    return isBotTitle(title);
  }

  private getChatSubtitle(category: string): string {
    return getChatSubtitle(category);
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
      url: 'features/chat/view/ChatProfileView',
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

  private handleMessageRowClick(msg: MessageItem, row: MessageTextRow): void {
    if (row.url.length > 0) {
      this.openUrl(row.url);
      return;
    }
    if (this.isRobotMessage(msg)) {
      const command = ChatMessageTextUtils.extractBotCommandFromText(row.text);
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
    return ChatMessageTextUtils.findUrlInText(msg.text);
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
    let best: TdPhotoSize | undefined = undefined;
    let fallback: TdPhotoSize = photo.sizes[0];
    const maxPreviewPixels = 360 * 360;
    photo.sizes.forEach((size: TdPhotoSize) => {
      const pixels = size.width * size.height;
      if (pixels > fallback.width * fallback.height) {
        fallback = size;
      }
      if (pixels > maxPreviewPixels) {
        return;
      }
      if (!best || pixels > best.width * best.height) {
        best = size;
      }
    });
    return best ? best : fallback;
  }

  private getLocalPath(file: TdFile): string {
    return this.mediaController.getLocalPath(file);
  }

  private getCompletedLocalPath(file: TdFile): string {
    return this.mediaController.getCompletedLocalPath(file);
  }

  private getLatestFile(file: TdFile): TdFile {
    return this.mediaController.getLatestFile(file);
  }

  private getPhotoMediaState(file: TdFile): PhotoMediaState {
    return this.mediaController.getPhotoMediaState(file);
  }

  private getMessagePhotoState(msg: MessageItem): PhotoMediaState {
    return this.mediaController.getMessagePhotoState(msg);
  }

  private getPhotoDisplayPath(msg: MessageItem): string {
    if (this.photoRenderRevision < 0) {
      return '';
    }
    return this.mediaController.getPhotoDisplayPath(msg);
  }

  private getMessageThumbnailPath(msg: MessageItem): string {
    return this.mediaController.getThumbnailDisplayPath(msg);
  }

  private getThumbnailDisplayPath(msg: MessageItem): string {
    if (this.thumbnailRenderRevision < 0) {
      return '';
    }
    return this.getMessageThumbnailPath(msg);
  }

  private applyPhotoMediaStateToItem(item: MessageItem, state: PhotoMediaState): boolean {
    const previousPath = item.photoPath;
    const previousDownloadedSize = item.photoDownloadedSize;
    const previousExpectedSize = item.photoExpectedSize;
    item.photoFileId = state.fileId;
    item.photoPath = state.path;
    item.photoDownloadedSize = state.downloadedSize;
    item.photoExpectedSize = state.expectedSize;
    if (state.path.length > 0) {
      item.mediaFormat = ChatMediaFormatters.getMediaFormat('', '', state.path, item.mediaFormat.length > 0 ? item.mediaFormat : 'jpg');
    }
    return previousPath !== item.photoPath || previousDownloadedSize !== item.photoDownloadedSize ||
      previousExpectedSize !== item.photoExpectedSize;
  }

  private applyOriginalPhotoMediaStateToItem(item: MessageItem, state: PhotoMediaState): boolean {
    const previousPath = item.originalPhotoPath;
    const previousDownloadedSize = item.originalPhotoDownloadedSize;
    const previousExpectedSize = item.originalPhotoExpectedSize;
    item.originalPhotoFileId = state.fileId;
    item.originalPhotoPath = state.path;
    item.originalPhotoDownloadedSize = state.downloadedSize;
    item.originalPhotoExpectedSize = state.expectedSize;
    return previousPath !== item.originalPhotoPath ||
      previousDownloadedSize !== item.originalPhotoDownloadedSize ||
      previousExpectedSize !== item.originalPhotoExpectedSize;
  }

  private getMessageOriginalPhotoState(msg: MessageItem): PhotoMediaState {
    return this.mediaController.getMessageOriginalPhotoState(msg);
  }

  private getDownloadedSize(file: TdFile): number {
    return this.mediaController.getDownloadedSize(file);
  }

  private getExpectedSize(file: TdFile): number {
    return this.mediaController.getExpectedSize(file);
  }

  private getFileDebugText(file: TdFile): string {
    const local = file.local;
    if (!local) {
      return `no-local,size=${file.size === undefined ? -1 : file.size},expected=${file.expected_size === undefined ? -1 : file.expected_size}`;
    }
    return `path=${local.path},completed=${local.is_downloading_completed === true},active=${local.is_downloading_active === true},downloaded=${local.downloaded_size === undefined ? -1 : local.downloaded_size},prefix=${local.downloaded_prefix_size === undefined ? -1 : local.downloaded_prefix_size},size=${file.size === undefined ? -1 : file.size},expected=${file.expected_size === undefined ? -1 : file.expected_size}`;
  }

  private logMediaDebug(message: string): void {
    if (this.mediaDebugLogging) {
      console.info(message);
    }
  }

  private noteUpdateDebug(type: string, detail: string = ''): void {
    if (!this.renderDebugLogging) {
      return;
    }
    const current = this.updateDebugCounts.get(type);
    this.updateDebugCounts.set(type, current !== undefined ? current + 1 : 1);
    const total = this.updateDebugTotalCounts.get(type);
    this.updateDebugTotalCounts.set(type, total !== undefined ? total + 1 : 1);
    const now = Date.now();
    if (now - this.updateDebugLastAt < 1000) {
      return;
    }
    this.updateDebugLastAt = now;
    const parts: string[] = [];
    this.updateDebugCounts.forEach((count: number, key: string) => {
      parts.push(`${key}:${count}`);
    });
    this.updateDebugCounts.clear();
    console.info(`[ChatPage][updates] chatId=${this.chatId}, counts=${parts.join(',')}, latest=${type}, ${detail}`);
  }

  private logRenderDebug(reason: string, beforeCount: number, nextCount: number, groupCount: number, costMs: number): void {
    this.lastRenderDebugReason = reason;
    this.lastRenderDebugCostMs = costMs;
    if (!this.renderDebugLogging) {
      return;
    }
    const now = Date.now();
    if (costMs < 12 && now - this.renderDebugLastAt < 800) {
      return;
    }
    this.renderDebugLastAt = now;
    console.info(`[ChatPage][render] seq=${this.renderDebugSequence}, reason=${reason}, chatId=${this.chatId}, before=${beforeCount}, next=${nextCount}, groups=${groupCount}, cost=${costMs}ms, photoRev=${this.photoRenderRevision}, thumbRev=${this.thumbnailRenderRevision}, status=${this.statusText}`);
  }

  private canPlayVideo(file: TdFile): boolean {
    return this.mediaController.canPlayVideo(file);
  }

  private shouldInlinePlayVideo(msg: MessageItem): boolean {
    return msg.mediaType === 'messageVideo' && msg.videoDuration > 0 && msg.videoDuration <= 10;
  }

  private requestDownloadFileOnce(fileId: number, priority: number): void {
    if (fileId === 0 || this.requestedMediaFileIds.has(fileId)) {
      return;
    }
    this.requestedMediaFileIds.add(fileId);
    console.info(`[ChatPage][media] lazy download request fileId=${fileId}, priority=${priority}`);
    this.td.downloadFile(fileId, priority);
    this.scheduleFileRefresh(fileId, 0);
  }

  private scheduleFileRefresh(fileId: number, attempt: number): void {
    if (fileId === 0 || attempt > 8) {
      this.fileRefreshAttempts.delete(fileId);
      return;
    }
    const currentAttempt = this.fileRefreshAttempts.get(fileId);
    if (attempt === 0 && currentAttempt !== undefined) {
      return;
    }
    this.fileRefreshAttempts.set(fileId, attempt);
    const delays: number[] = [120, 280, 520, 900, 1400, 2200, 3400, 5200, 7600];
    const delay = delays[Math.min(attempt, delays.length - 1)];
    console.info(`[ChatPage][media] schedule getFile fileId=${fileId}, attempt=${attempt}, delay=${delay}`);
    setTimeout(() => {
      if (!this.isFileStillNeeded(fileId)) {
        console.info(`[ChatPage][media] stop getFile fileId=${fileId}, attempt=${attempt}, reason=not-needed`);
        this.fileRefreshAttempts.delete(fileId);
        return;
      }
      console.info(`[ChatPage][media] getFile request fileId=${fileId}, attempt=${attempt}`);
      this.td.getFile(fileId);
      this.scheduleFileRefresh(fileId, attempt + 1);
    }, delay);
  }

  private isFileStillNeeded(fileId: number): boolean {
    return this.messages.some((message: MessageItem): boolean => {
      if (message.photoFileId === fileId) {
        return !this.getMessagePhotoState(message).isReady;
      }
      if (message.originalPhotoFileId === fileId) {
        return !this.getMessageOriginalPhotoState(message).isReady;
      }
      if (message.thumbnailFileId === fileId) {
        const cachedFile = this.mediaController.getFile(fileId);
        return this.getMessageThumbnailPath(message).length === 0 ||
          (cachedFile !== undefined && this.getCompletedLocalPath(cachedFile).length === 0);
      }
      if (message.videoFileId === fileId) {
        return message.videoPath.length === 0 && this.shouldInlinePlayVideo(message);
      }
      return false;
    });
  }

  private requestMessageItemMedia(msg: MessageItem): void {
    if (msg.mediaType === 'messagePhoto') {
      const state = this.getMessagePhotoState(msg);
      console.info(`[ChatPage][media] requestMessageItemMedia photo messageId=${msg.id}, fileId=${state.fileId}, ready=${state.isReady}, path=${state.path}, downloaded=${state.downloadedSize}, expected=${state.expectedSize}`);
      if (!state.isReady) {
        this.requestDownloadFileOnce(msg.photoFileId, 16);
      }
      return;
    }
    if (msg.mediaType === 'messageVideo') {
      if (this.getMessageThumbnailPath(msg).length === 0) {
        this.requestDownloadFileOnce(msg.thumbnailFileId, 12);
      }
      if (this.shouldInlinePlayVideo(msg) && msg.videoPath.length === 0) {
        this.requestDownloadFileOnce(msg.videoFileId, 24);
      }
      return;
    }
    if (msg.mediaType === 'messageAnimation') {
      if (this.getMessageThumbnailPath(msg).length === 0) {
        this.requestDownloadFileOnce(msg.thumbnailFileId, 12);
      }
      if (msg.videoPath.length === 0) {
        this.requestDownloadFileOnce(msg.videoFileId, 24);
      }
      return;
    }
    if (msg.mediaType === 'messageAudio') {
      if (this.getMessageThumbnailPath(msg).length === 0) {
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

  private queueVisibleMessageWork(items: MessageItem[]): void {
    items.forEach((message: MessageItem) => {
      if (!this.requestedVisibleMediaMessageIds.has(message.id)) {
        this.pendingVisibleMediaMessageIds.add(message.id);
      }
      if (!message.isSelf && message.id > this.lastReadInboxMessageId && !this.visibleReadMessageIds.has(message.id)) {
        this.pendingVisibleReadMessageIds.add(message.id);
      }
    });
    if (this.visibleWorkFlushScheduled) {
      return;
    }
    this.visibleWorkFlushScheduled = true;
    setTimeout(() => {
      this.flushVisibleMessageWork();
    }, 90);
  }

  private flushVisibleMessageWork(): void {
    this.visibleWorkFlushScheduled = false;
    if (this.pendingVisibleMediaMessageIds.size > 0) {
      const mediaIds = Array.from(this.pendingVisibleMediaMessageIds);
      this.pendingVisibleMediaMessageIds.clear();
      mediaIds.forEach((messageId: number) => {
        const index = this.messageIndexById.get(messageId);
        if (index !== undefined && index >= 0 && index < this.messages.length) {
          this.requestVisibleMessageMediaOnce(this.messages[index]);
        }
      });
    }
    if (this.pendingVisibleReadMessageIds.size > 0) {
      const readIds = Array.from(this.pendingVisibleReadMessageIds);
      this.pendingVisibleReadMessageIds.clear();
      readIds.forEach((messageId: number) => {
        const index = this.messageIndexById.get(messageId);
        if (index !== undefined && index >= 0 && index < this.messages.length) {
          this.markVisibleMessageRead(this.messages[index]);
        }
      });
    }
  }

  private prefetchInitialMessageMedia(): void {
    if (this.messages.length === 0) {
      return;
    }
    let start = Math.max(0, this.messages.length - 10);
    let end = this.messages.length;
    if (this.targetMessageId !== 0) {
      const targetIndex = this.messages.findIndex((message: MessageItem): boolean => message.id === this.targetMessageId);
      if (targetIndex >= 0) {
        start = Math.max(0, targetIndex - 6);
        end = Math.min(this.messages.length, targetIndex + 7);
      }
    }
    this.messages.slice(start, end).forEach((msg: MessageItem) => {
      this.requestVisibleMessageMediaOnce(msg);
    });
  }

  private openMediaPreview(anchor: MessageItem): void {
    const items = this.getMediaPreviewItems(anchor);
    const index = items.findIndex((item: MediaPreviewItem): boolean => item.messageId === anchor.id);
    if (items.length === 0 || index < 0) {
      this.statusText = '媒体还未准备好';
      return;
    }
    this.openMediaPlayer(items, index);
  }

  private openOriginalImagePreview(msg: MessageItem): void {
    const originalState = this.getMessageOriginalPhotoState(msg);
    if (originalState.isReady && originalState.path.length > 0) {
      this.openMediaPreview(msg);
      return;
    }
    if (originalState.fileId === 0) {
      if (this.getPhotoDisplayPath(msg).length > 0) {
        this.openMediaPreview(msg);
      } else {
        this.statusText = '图片还未下载完成';
      }
      return;
    }
    if (this.getPhotoDisplayPath(msg).length > 0) {
      this.openMediaPreview(msg);
      this.requestDownloadFileOnce(originalState.fileId, 24);
      return;
    }
    this.pendingOriginalPhotoPreviewMessageId = msg.id;
    this.statusText = '正在下载原图...';
    this.requestDownloadFileOnce(originalState.fileId, 24);
  }

  private requestOriginalImageSave(msg: MessageItem): void {
    const originalState = this.getMessageOriginalPhotoState(msg);
    if (originalState.isReady && originalState.path.length > 0) {
      this.requestImageSave(originalState.path);
      return;
    }
    if (originalState.fileId === 0) {
      this.requestImageSave(this.getPhotoDisplayPath(msg));
      return;
    }
    this.pendingOriginalPhotoSaveMessageId = msg.id;
    this.statusText = '正在下载原图...';
    this.requestDownloadFileOnce(originalState.fileId, 24);
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
      this.mediaPreviewItems = [];
      this.mediaPreviewIndex = 0;
    }, 180);
  }

  private getMediaPreviewItems(anchor: MessageItem): MediaPreviewItem[] {
    let sourceItems: MessageItem[] = [];
    if (anchor.mediaAlbumId > 0) {
      sourceItems = this.messages.filter((message: MessageItem): boolean => {
        return message.mediaAlbumId === anchor.mediaAlbumId && this.isPreviewableMedia(message);
      });
    }
    if (sourceItems.length <= 1) {
      const anchorIndex = this.messages.findIndex((message: MessageItem): boolean => message.id === anchor.id);
      const start = anchorIndex >= 0 ? Math.max(0, anchorIndex - 20) : 0;
      const end = anchorIndex >= 0 ? Math.min(this.messages.length, anchorIndex + 21) : Math.min(this.messages.length, 40);
      sourceItems = this.messages.slice(start, end).filter((message: MessageItem): boolean => this.isPreviewableMedia(message));
    }
    return sourceItems.map((message: MessageItem): MediaPreviewItem => this.toMediaPreviewItem(message));
  }

  private isPreviewableMedia(msg: MessageItem): boolean {
    return msg.mediaType === 'messagePhoto' || msg.mediaType === 'messageVideo' || msg.mediaType === 'messageAnimation';
  }

  private toMediaPreviewItem(msg: MessageItem): MediaPreviewItem {
    if (msg.mediaType === 'messagePhoto') {
      const originalState = this.getMessageOriginalPhotoState(msg);
      const previewPath = this.getPhotoDisplayPath(msg);
      return {
        id: `photo-${msg.id}`,
        type: 'photo',
        messageId: msg.id,
        fileId: msg.originalPhotoFileId !== 0 ? msg.originalPhotoFileId : msg.photoFileId,
        displayPath: originalState.path.length > 0 ? originalState.path : previewPath,
        previewPath: previewPath,
        title: this.chatTitle,
        subtitle: msg.dateText,
        description: msg.text,
        fileSize: originalState.expectedSize,
        downloadedSize: originalState.downloadedSize,
        duration: 0,
        mediaWidth: msg.mediaWidth,
        mediaHeight: msg.mediaHeight
      };
    }
    return {
      id: `${msg.mediaType === 'messageAnimation' ? 'animation' : 'video'}-${msg.id}`,
      type: msg.mediaType === 'messageAnimation' ? 'animation' : 'video',
      messageId: msg.id,
      fileId: msg.videoFileId,
      displayPath: msg.videoPath,
      previewPath: this.getThumbnailDisplayPath(msg),
      title: this.chatTitle,
      subtitle: msg.dateText.length > 0 ? msg.dateText : this.chatSubtitle,
      description: msg.text.length > 0 ? msg.text : this.chatTitle,
      fileSize: msg.videoExpectedSize,
      downloadedSize: msg.videoDownloadedSize,
      duration: msg.videoDuration,
      mediaWidth: msg.mediaWidth,
      mediaHeight: msg.mediaHeight
    };
  }

  private setMediaPreviewIndex(index: number): void {
    if (index < 0 || index >= this.mediaPreviewItems.length) {
      return;
    }
    this.mediaPreviewIndex = index;
    this.imagePreviewPath = this.mediaPreviewItems[index].displayPath;
    this.mediaPreviewSwiperController.changeIndex(index, true);
  }

  private openMediaPlayer(items: MediaPreviewItem[], index: number): void {
    const item = items[index];
    const params: VideoRouteParams = {
      chatId: this.chatId,
      messageId: item.messageId,
      fileId: item.fileId,
      mediaItemsJson: JSON.stringify(items),
      mediaIndex: index,
      videoPath: item.displayPath,
      previewUri: item.previewPath,
      title: item.title,
      subtitle: item.subtitle,
      description: item.description,
      fileSize: item.fileSize,
      downloadedSize: item.downloadedSize,
      duration: item.duration,
      videoWidth: item.mediaWidth,
      videoHeight: item.mediaHeight
    };
    router.pushUrl({
      url: 'features/chat/view/VideoPlayerView',
      params: params
    });
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

  private toLocalFilePath(source: string): string {
    if (source.startsWith('file://')) {
      return source.substring('file://'.length);
    }
    return source;
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
    this.setMessages(this.resolveReplyTexts(nextMessages), `upsert:${item.id}`);
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
    this.setMessages(this.resolveReplyTexts(ChatMessageGroupUtils.sortMessages(nextMessages)), `merge:${items.length}`);
  }

  private setMessages(items: MessageItem[], reason: string = 'unknown'): void {
    const startedAt = Date.now();
    const beforeCount = this.messages.length;
    this.messages = items;
    this.rebuildMessageIndexes(items);
    const groups = ChatMessageGroupUtils.getMessageGroupsFromItems(items);
    this.messageGroups = groups;
    this.renderDebugSequence += 1;
    this.logRenderDebug(reason, beforeCount, items.length, groups.length, Date.now() - startedAt);
  }

  private refreshAvatarBindings(): void {
    if (this.messages.length === 0) {
      return;
    }
    this.setMessages(this.messages.slice(), 'avatarBindings');
  }

  private rebuildMessageIndexes(items: MessageItem[]): void {
    this.messageIndexById.clear();
    this.mediaMessageIdsByFileId.clear();
    items.forEach((message: MessageItem, index: number) => {
      this.messageIndexById.set(message.id, index);
      this.indexMediaFileMessage(message.photoFileId, message.id);
      this.indexMediaFileMessage(message.originalPhotoFileId, message.id);
      this.indexMediaFileMessage(message.videoFileId, message.id);
      this.indexMediaFileMessage(message.thumbnailFileId, message.id);
      this.indexMediaFileMessage(message.documentFileId, message.id);
      this.indexMediaFileMessage(message.audioFileId, message.id);
    });
  }

  private indexMediaFileMessage(fileId: number, messageId: number): void {
    if (fileId === 0) {
      return;
    }
    if (!this.mediaMessageIdsByFileId.has(fileId)) {
      this.mediaMessageIdsByFileId.set(fileId, new Set<number>());
    }
    this.mediaMessageIdsByFileId.get(fileId)!.add(messageId);
  }

  private getGroupMediaVersion(items: MessageItem[]): number {
    let version = 0;
    items.forEach((item: MessageItem) => {
      version += this.getMessageRenderVersion(item);
    });
    return version;
  }

  private getMessageRenderVersion(item: MessageItem): number {
    let version = item.mediaVersion;
    if (item.mediaType === 'messagePhoto') {
      const state = this.getMessagePhotoState(item);
      version += state.isReady ? 100000 : 0;
      version += state.path.length;
    }
    if (item.thumbnailFileId !== 0) {
      const thumbnailPath = this.getMessageThumbnailPath(item);
      version += thumbnailPath.length;
      version += thumbnailPath.length > 0 ? 200000 : 0;
    }
    return version;
  }

  private getPhotoImageRenderKey(item: MessageItem): string {
    const state = this.getMessagePhotoState(item);
    return `${item.id}-${state.isReady ? 1 : 0}-${state.path.length}-${state.expectedSize}`;
  }

  private getThumbnailImageRenderKey(item: MessageItem): string {
    const thumbnailPath = this.getMessageThumbnailPath(item);
    return `${item.id}-${item.thumbnailFileId}-${thumbnailPath.length}-${item.mediaVersion}`;
  }

  private getStableExpectedSize(currentExpectedSize: number, file: TdFile): number {
    return this.mediaController.getStableExpectedSize(currentExpectedSize, file);
  }

  private getDisplayIndexForMessageId(messageId: number): number {
    return ChatMessageGroupUtils.getDisplayIndexForMessageId(this.messageGroups, messageId);
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
    console.info(`[ChatPage] request scroll to real latest chatId=${this.chatId}, unread=${this.unreadCount}, hasMoreNewer=${this.hasMoreNewerHistory}, loading=${this.historyLoading}`);
    this.requestRealLatestHistory();
  }

  private finishScrollToLatestAndMarkRead(): void {
    console.info(`[ChatPage] scroll to latest and mark read chatId=${this.chatId}, unread=${this.unreadCount}`);
    if (this.messages.length > 0) {
      this.messageScroller.scrollToIndex(this.messageGroups.length + 1, true, ScrollAlign.END);
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

  private locateMessageInCurrentChat(messageId: number, reason: string): void {
    if (this.chatId === 0 || messageId === 0) {
      return;
    }
    this.cancelPendingLatestScroll();
    this.targetMessageId = messageId;
    this.targetHistoryRetryCount = 0;
    let targetChanged = false;
    this.messages.forEach((message: MessageItem) => {
      const nextIsTarget = message.id === messageId;
      if (message.isTarget !== nextIsTarget) {
        message.isTarget = nextIsTarget;
        targetChanged = true;
      }
    });
    if (targetChanged) {
      this.setMessages(this.messages.slice(), 'callbackRefresh');
    }
    const index = this.getDisplayIndexForMessageId(messageId);
    console.info(`[ChatPage] locate message chatId=${this.chatId}, messageId=${messageId}, index=${index}, reason=${reason}`);
    if (index >= 0) {
      this.scheduleScrollToTarget(true, reason);
      return;
    }
    this.loadHistoryAroundMessage(messageId);
  }

  private openPinnedMessage(): void {
    if (this.pinnedMessageId === 0) {
      return;
    }
    this.locateMessageInCurrentChat(this.pinnedMessageId, 'pinned');
  }

  private scheduleScrollToLatest(animated: boolean): void {
    const token = ++this.latestScrollToken;
    this.scheduleScrollToLatestAt(animated, 80, token);
    this.scheduleScrollToLatestAt(false, 180, token);
    this.scheduleScrollToLatestAt(false, 340, token);
  }

  private cancelPendingLatestScroll(): void {
    this.latestScrollToken += 1;
  }

  private scheduleScrollToLatestAt(animated: boolean, delay: number, token: number = 0): void {
    setTimeout(() => {
      if (token !== 0 && token !== this.latestScrollToken) {
        return;
      }
      if (this.messages.length > 0) {
        console.info(`[ChatPage] auto scroll to latest chatId=${this.chatId}, animated=${animated}, delay=${delay}`);
        this.messageScroller.scrollToIndex(this.messageGroups.length + 1, animated, ScrollAlign.END);
      }
    }, delay);
  }

  private scheduleScrollToTarget(animated: boolean, reason: string): void {
    if (this.targetMessageId === 0) {
      return;
    }
    const token = ++this.targetScrollToken;
    const delays: number[] = [40, 140, 300, 560, 900, 1350];
    delays.forEach((delay: number, attempt: number) => {
      setTimeout(() => {
        if (token !== this.targetScrollToken || this.targetMessageId === 0) {
          return;
        }
        this.scrollToTargetMessage(animated && attempt === 0, reason, attempt, attempt === delays.length - 1);
      }, delay);
    });
  }

  private scrollToTargetMessage(animated: boolean, reason: string, attempt: number, finalAttempt: boolean): void {
    const index = this.getDisplayIndexForMessageId(this.targetMessageId);
    if (index >= 0) {
      console.info(`[ChatPage] scroll to target chatId=${this.chatId}, messageId=${this.targetMessageId}, index=${index}, attempt=${attempt}, reason=${reason}`);
      this.messageScroller.scrollToIndex(index + 1, animated, ScrollAlign.CENTER);
      this.statusText = '';
      return;
    }
    if (!finalAttempt || this.targetHistoryRetryCount >= 2 || this.chatId === 0) {
      return;
    }
    this.targetHistoryRetryCount += 1;
    this.statusText = '正在重新定位消息...';
    console.info(`[ChatPage] target missing, retry history chatId=${this.chatId}, messageId=${this.targetMessageId}, retry=${this.targetHistoryRetryCount}, reason=${reason}`);
    this.historyLoading = true;
    this.historyMode = 'replace';
    this.historyRequestSource = 'target';
    this.td.openMessageContent(this.chatId, this.targetMessageId);
    this.td.getMessage(this.chatId, this.targetMessageId);
    this.td.getChatHistory(this.chatId, 30, this.targetMessageId, -15);
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
      senderAvatarKey: message.senderAvatarKey,
      senderAvatarLabel: message.senderAvatarLabel,
      mediaType: message.mediaType,
      mediaFormat: message.mediaFormat,
      text: message.text,
      textRows: message.textRows,
      replyText: replyText,
      replyMessageId: message.replyMessageId,
      buttonRows: message.buttonRows,
      photoPath: message.photoPath,
      originalPhotoPath: message.originalPhotoPath,
      videoPath: message.videoPath,
      thumbnailPath: message.thumbnailPath,
      photoFileId: message.photoFileId,
      originalPhotoFileId: message.originalPhotoFileId,
      photoDownloadedSize: message.photoDownloadedSize,
      photoExpectedSize: message.photoExpectedSize,
      originalPhotoDownloadedSize: message.originalPhotoDownloadedSize,
      originalPhotoExpectedSize: message.originalPhotoExpectedSize,
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
      viewCount: message.viewCount,
      commentCount: message.commentCount,
      commentAvatars: message.commentAvatars,
      commentAvatarKeys: message.commentAvatarKeys,
      commentThreadMessageId: message.commentThreadMessageId,
      mediaVersion: message.mediaVersion
    };
  }

  private copyMessageItemWithPhotoState(message: MessageItem, state: PhotoMediaState): MessageItem {
    const next = this.copyMessageItem(message, message.replyText);
    if (this.applyPhotoMediaStateToItem(next, state)) {
      next.mediaVersion += 1;
    }
    return next;
  }

  private updateCachedPhotoFile(file: TdFile): void {
    const state = this.getPhotoMediaState(file);
    const updatedIds: number[] = [];
    this.messageCache.forEach((message: MessageItem, messageId: number) => {
      if (message.photoFileId !== file.id && message.originalPhotoFileId !== file.id) {
        return;
      }
      const next = message.photoFileId === file.id ? this.copyMessageItemWithPhotoState(message, state) :
        this.copyMessageItem(message, message.replyText);
      if (next.originalPhotoFileId === file.id && this.applyOriginalPhotoMediaStateToItem(next, state)) {
        next.mediaVersion += 1;
      }
      this.messageCache.set(messageId, next);
      updatedIds.push(messageId);
    });
    if (updatedIds.length > 0) {
      console.info(`[ChatPage][media] cached photo state fileId=${file.id}, ready=${state.isReady}, messageIds=${updatedIds.join(',')}, path=${state.path}`);
    }
  }

  private applyFileUpdate(file: TdFile): void {
    file = this.mediaController.cacheFile(file);
    const path = this.getLocalPath(file);
    const completedPath = this.getCompletedLocalPath(file);
    this.updateCachedPhotoFile(file);
    const matchedMessageIds = this.mediaMessageIdsByFileId.get(file.id);
    const matchedCount = matchedMessageIds ? matchedMessageIds.size : 0;
    this.logMediaDebug(`[ChatPage][media] applyFileUpdate start fileId=${file.id}, matched=${matchedCount}, path=${path}, ${this.getFileDebugText(file)}`);
    if (!this.isFileStillNeeded(file.id) && path.length > 0) {
      this.fileRefreshAttempts.delete(file.id);
    }
    if (file.id === this.chatAvatarFileId && path.length > 0) {
      console.info(`[ChatPage] apply chat avatar file update fileId=${file.id}`);
      this.chatAvatarPath = path;
    }
    if (this.commentAvatarFileKeys.has(file.id) && path.length > 0) {
      const key = this.commentAvatarFileKeys.get(file.id)!;
      this.commentAvatarPaths.set(key, path);
      this.commentAvatarVersion += 1;
      this.refreshAvatarBindings();
    }
    if (!matchedMessageIds || matchedMessageIds.size === 0) {
      this.logMediaDebug(`[ChatPage][media] applyFileUpdate no-visible-message fileId=${file.id}, path=${path}`);
      return;
    }
    let changed = false;
    const nextMessages: MessageItem[] = this.messages.slice();
    matchedMessageIds.forEach((messageId: number) => {
      const messageIndex = this.messageIndexById.get(messageId);
      if (messageIndex === undefined || messageIndex < 0 || messageIndex >= this.messages.length) {
        return;
      }
      const message = this.messages[messageIndex];
      const next: MessageItem = this.copyMessageItem(message, message.replyText);
      if (next.photoFileId === file.id) {
        const state = this.getPhotoMediaState(file);
        const previousBucket = ChatMessageGroupUtils.getDownloadPercentBucket(message.photoDownloadedSize, message.photoExpectedSize);
        const nextBucket = ChatMessageGroupUtils.getDownloadPercentBucket(state.downloadedSize, state.expectedSize);
        const photoChanged = this.applyPhotoMediaStateToItem(next, state);
        if (photoChanged) {
          const pathChanged = message.photoPath !== next.photoPath;
          const expectedChanged = state.expectedSize !== message.photoExpectedSize;
          if (pathChanged || expectedChanged || nextBucket !== previousBucket) {
            if (pathChanged) {
              next.mediaVersion += 1;
            }
            changed = true;
          }
          if (pathChanged) {
            this.photoRenderRevision += 1;
          }
        }
        this.logMediaDebug(`[ChatPage][media] photo file state messageId=${message.id}, fileId=${file.id}, ready=${state.isReady}, path=${state.path}, downloaded=${state.downloadedSize}, expected=${state.expectedSize}, previousBucket=${previousBucket}, nextBucket=${nextBucket}, changed=${photoChanged}`);
      }
      if (next.originalPhotoFileId === file.id) {
        const state = this.getPhotoMediaState(file);
        const originalChanged = this.applyOriginalPhotoMediaStateToItem(next, state);
        if (originalChanged) {
          if (message.originalPhotoPath !== next.originalPhotoPath) {
            next.mediaVersion += 1;
          }
          changed = true;
        }
        if (state.isReady && state.path.length > 0 && this.pendingOriginalPhotoPreviewMessageId === message.id) {
          this.pendingOriginalPhotoPreviewMessageId = 0;
          this.openMediaPreview(next);
        }
        if (state.isReady && state.path.length > 0 && this.pendingOriginalPhotoSaveMessageId === message.id) {
          this.pendingOriginalPhotoSaveMessageId = 0;
          this.requestImageSave(state.path);
        }
      }
      if (next.videoFileId === file.id) {
        const previousBucket = ChatMessageGroupUtils.getDownloadPercentBucket(message.videoDownloadedSize, message.videoExpectedSize);
        const downloadedSize = this.getDownloadedSize(file);
        const expectedSize = this.getStableExpectedSize(message.videoExpectedSize, file);
        const nextBucket = ChatMessageGroupUtils.getDownloadPercentBucket(downloadedSize, expectedSize);
        const pathChanged = path.length > 0 && path !== message.videoPath;
        const readyChanged = this.canPlayVideo(file) !== message.videoCanPlay;
        if (pathChanged) {
          next.videoPath = path;
        }
        next.videoDownloadedSize = downloadedSize;
        next.videoExpectedSize = expectedSize;
        next.videoCanPlay = this.canPlayVideo(file);
        if (pathChanged) {
          next.mediaFormat = ChatMediaFormatters.getMediaFormat('', '', path, next.mediaFormat.length > 0 ? next.mediaFormat : 'mp4');
        }
        if (pathChanged || readyChanged || nextBucket !== previousBucket || expectedSize !== message.videoExpectedSize) {
          if (pathChanged || readyChanged) {
            next.mediaVersion += 1;
          }
          changed = true;
        }
      }
      if (next.thumbnailFileId === file.id && completedPath.length > 0 && completedPath !== message.thumbnailPath) {
        console.info(`[ChatPage][media] thumbnail ready messageId=${message.id}, fileId=${file.id}, oldPath=${message.thumbnailPath}, newPath=${completedPath}`);
        next.thumbnailPath = completedPath;
        next.mediaVersion += 1;
        this.thumbnailRenderRevision += 1;
        changed = true;
      }
      if (next.documentFileId === file.id) {
        const expectedSize = this.getExpectedSize(file);
        if (expectedSize !== message.documentSize) {
          next.documentSize = expectedSize;
          next.mediaVersion += 1;
          changed = true;
        }
      }
      if (next.audioFileId === file.id) {
        const previousBucket = ChatMessageGroupUtils.getDownloadPercentBucket(message.audioDownloadedSize, message.audioExpectedSize);
        const previousReady = ChatMediaFormatters.isAudioReady(message);
        const downloadedSize = Math.max(message.audioDownloadedSize, this.getDownloadedSize(file));
        const expectedSize = this.getStableExpectedSize(message.audioExpectedSize, file);
        const nextBucket = ChatMessageGroupUtils.getDownloadPercentBucket(downloadedSize, expectedSize);
        const pathChanged = path.length > 0 && path !== message.audioPath;
        if (pathChanged) {
          next.audioPath = path;
        }
        next.audioDownloadedSize = downloadedSize;
        next.audioExpectedSize = expectedSize;
        if (pathChanged) {
          next.mediaFormat = ChatMediaFormatters.getMediaFormat('', '', path, next.mediaFormat.length > 0 ? next.mediaFormat : 'mp3');
        }
        if (this.activeAudioMessageId === next.id && this.audioPlayer === null &&
          path.length > 0 && (file.local && file.local.is_downloading_completed || ChatMediaFormatters.isAudioReady(next))) {
          this.createAndPlayAudio(next.id, path);
        }
        if (pathChanged || ChatMediaFormatters.isAudioReady(next) !== previousReady || nextBucket !== previousBucket ||
          expectedSize !== message.audioExpectedSize) {
          if (pathChanged || ChatMediaFormatters.isAudioReady(next) !== previousReady) {
            next.mediaVersion += 1;
          }
          changed = true;
        }
      }
      if (next !== message) {
        nextMessages[messageIndex] = next;
      }
    });
    if (changed) {
      console.info(`[ChatPage][media] applyFileUpdate changed fileId=${file.id}, path=${path}, downloaded=${this.getDownloadedSize(file)}, expected=${this.getExpectedSize(file)}`);
      this.setMessages(nextMessages, `fileUpdate:${file.id}:matched=${matchedCount}`);
      nextMessages.forEach((message: MessageItem) => {
        if (message.photoFileId === file.id || message.videoFileId === file.id || message.thumbnailFileId === file.id ||
          message.documentFileId === file.id || message.audioFileId === file.id) {
          this.messageCache.set(message.id, message);
        }
      });
    } else {
      this.logMediaDebug(`[ChatPage][media] applyFileUpdate no-change fileId=${file.id}, matched=${matchedCount}, path=${path}, downloaded=${this.getDownloadedSize(file)}, expected=${this.getExpectedSize(file)}`);
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
        senderAvatarKey: message.senderAvatarKey,
        senderAvatarLabel: message.senderAvatarLabel,
        mediaType: this.getNormalizedMediaType(content),
        mediaFormat: this.getContentMediaFormat(content),
        text: this.getMessageText(content),
        textRows: ChatMessageTextUtils.getRows(this.getMessageFormattedText(content)),
        replyText: message.replyText,
        replyMessageId: message.replyMessageId,
        buttonRows: message.buttonRows,
        photoPath: '',
        originalPhotoPath: '',
        videoPath: '',
        thumbnailPath: '',
        photoFileId: 0,
        originalPhotoFileId: 0,
        photoDownloadedSize: 0,
        photoExpectedSize: 0,
        originalPhotoDownloadedSize: 0,
        originalPhotoExpectedSize: 0,
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
        viewCount: message.viewCount,
        commentCount: message.commentCount,
        commentAvatars: message.commentAvatars,
        commentAvatarKeys: message.commentAvatarKeys,
        commentThreadMessageId: message.commentThreadMessageId,
        mediaVersion: message.mediaVersion + 1
      };
      if (content.type === 'messagePhoto' && content.photo) {
        const size: TdPhotoSize | undefined = this.getPreviewPhotoSize(content.photo);
        if (size) {
          const photoFile = this.getLatestFile(size.photo);
          this.applyPhotoMediaStateToItem(next, this.getPhotoMediaState(photoFile));
          next.mediaWidth = size.width;
          next.mediaHeight = size.height;
        }
        const originalSize: TdPhotoSize | undefined = this.getBestPhotoSize(content.photo);
        if (originalSize) {
          const originalFile = this.getLatestFile(originalSize.photo);
          this.applyOriginalPhotoMediaStateToItem(next, this.getPhotoMediaState(originalFile));
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
          next.thumbnailPath = this.getCompletedLocalPath(this.getLatestFile(content.video.thumbnail.file));
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
          next.thumbnailPath = this.getCompletedLocalPath(this.getLatestFile(content.animation.thumbnail.file));
        }
      }
      if (content.type === 'messageDocument' && content.document) {
        next.documentFileId = content.document.document.id;
        next.documentFileName = content.document.file_name && content.document.file_name.length > 0 ?
          content.document.file_name : '未命名文件';
        next.documentSize = this.getExpectedSize(content.document.document);
        next.mediaFormat = ChatMediaFormatters.getMediaFormat(content.document.file_name, content.document.mime_type,
          this.getLocalPath(content.document.document), 'file');
      }
      if (content.type === 'messageAudio' && content.audio) {
        this.applyAudioContentToItem(next, content.audio);
      }
      return next;
    });
    if (changed) {
      this.setMessages(nextMessages, `content:${messageId}`);
      const updated = nextMessages.find((message: MessageItem): boolean => message.id === messageId);
      if (updated) {
        this.messageCache.set(messageId, updated);
        this.requestedVisibleMediaMessageIds.delete(messageId);
        this.requestMessageItemMedia(updated);
      }
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
        senderAvatarKey: message.senderAvatarKey,
        senderAvatarLabel: message.senderAvatarLabel,
        mediaType: message.mediaType,
        mediaFormat: message.mediaFormat,
        text: message.text,
        textRows: message.textRows,
        replyText: message.replyText,
        replyMessageId: message.replyMessageId,
        buttonRows: this.getMessageButtonRows(replyMarkup),
        photoPath: message.photoPath,
        originalPhotoPath: message.originalPhotoPath,
        videoPath: message.videoPath,
        thumbnailPath: message.thumbnailPath,
        photoFileId: message.photoFileId,
        originalPhotoFileId: message.originalPhotoFileId,
        photoDownloadedSize: message.photoDownloadedSize,
        photoExpectedSize: message.photoExpectedSize,
        originalPhotoDownloadedSize: message.originalPhotoDownloadedSize,
        originalPhotoExpectedSize: message.originalPhotoExpectedSize,
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
        viewCount: message.viewCount,
        commentCount: message.commentCount,
        commentAvatars: message.commentAvatars,
        commentAvatarKeys: message.commentAvatarKeys,
        commentThreadMessageId: message.commentThreadMessageId,
        mediaVersion: message.mediaVersion
      };
    });
    if (changed) {
      this.setMessages(nextMessages, `replyMarkup:${messageId}`);
    }
  }

  private applyMessageInteractionInfoUpdate(messageId: number, interactionInfo: TdMessageInteractionInfo | undefined): void {
    let changed = false;
    const nextMessages: MessageItem[] = this.messages.map((message: MessageItem): MessageItem => {
      if (message.id !== messageId) {
        return message;
      }
      changed = true;
      const replyInfo = interactionInfo && interactionInfo.reply_info ? interactionInfo.reply_info : undefined;
      return {
        id: message.id,
        mediaAlbumId: message.mediaAlbumId,
        isSelf: message.isSelf,
        isTarget: message.isTarget,
        senderAvatarKey: message.senderAvatarKey,
        senderAvatarLabel: message.senderAvatarLabel,
        mediaType: message.mediaType,
        mediaFormat: message.mediaFormat,
        text: message.text,
        textRows: message.textRows,
        replyText: message.replyText,
        replyMessageId: message.replyMessageId,
        buttonRows: message.buttonRows,
        photoPath: message.photoPath,
        originalPhotoPath: message.originalPhotoPath,
        videoPath: message.videoPath,
        thumbnailPath: message.thumbnailPath,
        photoFileId: message.photoFileId,
        originalPhotoFileId: message.originalPhotoFileId,
        photoDownloadedSize: message.photoDownloadedSize,
        photoExpectedSize: message.photoExpectedSize,
        originalPhotoDownloadedSize: message.originalPhotoDownloadedSize,
        originalPhotoExpectedSize: message.originalPhotoExpectedSize,
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
        viewCount: interactionInfo && interactionInfo.view_count !== undefined ? interactionInfo.view_count : 0,
        commentCount: replyInfo && replyInfo.reply_count !== undefined ? replyInfo.reply_count : 0,
        commentAvatars: replyInfo && replyInfo.recent_replier_ids ? this.getCommentAvatarLabels(replyInfo.recent_replier_ids) : [],
        commentAvatarKeys: replyInfo && replyInfo.recent_replier_ids ? this.getCommentAvatarKeys(replyInfo.recent_replier_ids) : [],
        commentThreadMessageId: replyInfo && replyInfo.last_message_id !== undefined ? replyInfo.last_message_id : 0,
        mediaVersion: message.mediaVersion
      };
    });
    if (changed) {
      this.setMessages(nextMessages, `interaction:${messageId}`);
      const updated = nextMessages.find((message: MessageItem): boolean => message.id === messageId);
      if (updated) {
        this.messageCache.set(messageId, updated);
        this.requestCommentAvatars(updated);
      }
    }
  }

  private getPhotoDownloadPercent(msg: MessageItem): number {
    const state = this.getMessagePhotoState(msg);
    if (state.isReady) {
      return 100;
    }
    if (state.expectedSize <= 0) {
      return state.downloadedSize > 0 ? 12 : 0;
    }
    return Math.min(100, Math.max(0, Math.floor(state.downloadedSize * 100 / state.expectedSize)));
  }

  private cancelMediaDownload(fileId: number): void {
    if (fileId <= 0) {
      return;
    }
    console.info(`[ChatPage] cancel media download fileId=${fileId}`);
    this.td.cancelDownloadFile(fileId);
    this.requestedMediaFileIds.delete(fileId);
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
    this.activeAudioMessageId = msg.id;
    this.activeAudioTitle = msg.audioTitle;
    this.activeAudioPerformer = msg.audioPerformer;
    if (!ChatMediaFormatters.isAudioReady(msg)) {
      console.info(`[ChatPage] audio download clicked messageId=${msg.id}, fileId=${msg.audioFileId}`);
      this.playingAudioMessageId = 0;
      this.releaseAudioPlayer(false);
      if (msg.audioFileId > 0) {
        this.td.downloadFile(msg.audioFileId, 32);
      }
      this.statusText = '正在下载音频...';
      return;
    }
    if (this.playingAudioMessageId === msg.id) {
      this.pauseActiveAudio();
      return;
    }
    this.createAndPlayAudio(msg.id, msg.audioPath);
  }

  private playActiveAudio(): void {
    const message = this.getActiveAudioMessage();
    if (!message) {
      this.stopAudioPlayback();
      return;
    }
    this.toggleAudioPlayback(message);
  }

  private getActiveAudioMessage(): MessageItem | undefined {
    return this.messages.find((message: MessageItem): boolean => message.id === this.activeAudioMessageId);
  }

  private createAndPlayAudio(messageId: number, source: string): void {
    if (source.length === 0) {
      return;
    }
    this.releaseAudioPlayer(false);
    this.preparingAudioMessageId = messageId;
    media.createAVPlayer().then((player: media.AVPlayer) => {
      if (this.preparingAudioMessageId !== messageId) {
        player.release();
        return;
      }
      const localPath = this.toLocalFilePath(source);
      const audioFile = fileIo.openSync(localPath, fileIo.OpenMode.READ_ONLY);
      this.audioPlayer = player;
      this.audioFile = audioFile;
      this.bindAudioPlayerEvents(player, messageId);
      console.info(`[ChatPage] audio player fd source=${localPath}, messageId=${messageId}`);
      player.fdSrc = {
        fd: audioFile.fd,
        offset: 0
      };
    }).catch((err: OperationError) => {
      console.error(`[ChatPage] create audio player failed code=${err.code}, message=${err.message}`);
      this.playingAudioMessageId = 0;
      this.statusText = '音频播放失败';
    });
  }

  private bindAudioPlayerEvents(player: media.AVPlayer, messageId: number): void {
    player.on('stateChange', (state: media.AVPlayerState, reason: media.StateChangeReason) => {
      if (player !== this.audioPlayer) {
        return;
      }
      console.info(`[ChatPage] audio player state=${state}, reason=${reason}, messageId=${messageId}`);
      if (state === 'initialized') {
        player.prepare().catch((err: OperationError) => {
          console.error(`[ChatPage] audio prepare failed code=${err.code}, message=${err.message}`);
          this.playingAudioMessageId = 0;
          this.statusText = '音频播放失败';
        });
      }
      if (state === 'prepared') {
        player.play().then(() => {
          this.playingAudioMessageId = messageId;
          this.statusText = '';
        }).catch((err: OperationError) => {
          console.error(`[ChatPage] audio play failed code=${err.code}, message=${err.message}`);
          this.playingAudioMessageId = 0;
          this.statusText = '音频播放失败';
        });
      }
      if (state === 'playing') {
        this.playingAudioMessageId = messageId;
      }
      if (state === 'paused' || state === 'completed' || state === 'stopped') {
        if (this.playingAudioMessageId === messageId) {
          this.playingAudioMessageId = 0;
        }
      }
      if (state === 'error') {
        this.playingAudioMessageId = 0;
        this.statusText = '音频播放失败';
      }
    });
    player.on('error', (err: BusinessError) => {
      if (player !== this.audioPlayer) {
        return;
      }
      console.error(`[ChatPage] audio player error code=${err.code}, message=${err.message}`);
      this.playingAudioMessageId = 0;
      this.statusText = '音频播放失败';
    });
  }

  private pauseActiveAudio(): void {
    const player = this.audioPlayer;
    if (player === null) {
      this.playingAudioMessageId = 0;
      return;
    }
    player.pause().then(() => {
      this.playingAudioMessageId = 0;
    }).catch((err: OperationError) => {
      console.error(`[ChatPage] audio pause failed code=${err.code}, message=${err.message}`);
      this.playingAudioMessageId = 0;
    });
  }

  private stopAudioPlayback(): void {
    this.releaseAudioPlayer(true);
  }

  private releaseAudioPlayer(clearActive: boolean): void {
    const player = this.audioPlayer;
    const audioFile = this.audioFile;
    this.audioPlayer = null;
    this.audioFile = null;
    this.preparingAudioMessageId = 0;
    this.playingAudioMessageId = 0;
    if (clearActive) {
      this.activeAudioMessageId = 0;
      this.activeAudioTitle = '';
      this.activeAudioPerformer = '';
    }
    if (player !== null) {
      player.release().catch((err: OperationError) => {
        console.error(`[ChatPage] audio release failed code=${err.code}, message=${err.message}`);
      });
    }
    if (audioFile !== null) {
      try {
        fileIo.closeSync(audioFile);
      } catch (err) {
        const error = err as OperationError;
        console.error(`[ChatPage] audio fd close failed code=${error.code}, message=${error.message}`);
      }
    }
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
    const normalizedUrl = ChatMessageTextUtils.normalizeUrl(url);
    console.info(`[ChatPage] openUrl url=${normalizedUrl}`);
    if (normalizedUrl.length === 0) {
      return;
    }
    if (ChatMessageTextUtils.isTelegramMessageUrl(normalizedUrl)) {
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

  private openInternalMessageUrl(url: string): void {
    console.info(`[ChatPage] openInternalMessageUrl url=${url}`);
    this.statusText = '正在打开内部消息...';
    const parsed = ChatMessageTextUtils.parseTMeMessageUrl(url);
    if (parsed.chatId !== 0 && parsed.messageId !== 0) {
      this.openMessageTarget(Number(parsed.chatId), Number(parsed.messageId));
      return;
    }
    this.td.getMessageLinkInfo(url);
  }

  private openMessageTarget(chatId: number, messageId: number): void {
    if (chatId === this.chatId) {
      this.locateMessageInCurrentChat(messageId, 'sameChatLink');
      return;
    }
    this.pendingNavigationChatId = chatId;
    this.pendingNavigationMessageId = messageId;
    this.statusText = '正在获取群聊信息...';
    console.info(`[ChatPage] request target chat before navigation chatId=${chatId}, messageId=${messageId}`);
    this.td.getChat(chatId);
    setTimeout(() => {
      if (this.pendingNavigationChatId !== chatId || this.pendingNavigationMessageId !== messageId) {
        return;
      }
      this.pendingNavigationChatId = 0;
      this.pendingNavigationMessageId = 0;
      console.info(`[ChatPage] target chat resolve timeout chatId=${chatId}, messageId=${messageId}`);
      router.pushUrl({
        url: 'features/chat/view/ChatDetailView',
        params: { chatId: chatId, messageId: messageId, title: '正在加载群聊信息...' }
      });
    }, 1200);
  }

  private openResolvedMessageTarget(chat: TdChat, messageId: number): void {
    const avatarFileId = chat.photo && chat.photo.small ? chat.photo.small.id : 0;
    const avatarPath = chat.photo && chat.photo.small ? this.getLocalPath(chat.photo.small) : '';
    console.info(`[ChatPage] open resolved target chatId=${chat.id}, messageId=${messageId}, title=${chat.title}`);
    router.pushUrl({
      url: 'features/chat/view/ChatDetailView',
      params: {
        chatId: chat.id,
        messageId: messageId,
        title: chat.title,
        avatarPath: avatarPath,
        avatarFileId: avatarFileId,
        category: this.getChatCategory(chat),
        unreadCount: chat.unread_count ? chat.unread_count : 0,
        lastReadInboxMessageId: chat.last_read_inbox_message_id ? chat.last_read_inbox_message_id : 0
      }
    });
  }

  private getCurrentChatCategory(): string {
    return getCurrentChatCategory(this.isChannelChat, this.chatSubtitle);
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
    this.openMediaPreview(msg);
  }

  private openCurrentPreviewVideo(item: MediaPreviewItem): void {
    const index = this.messageIndexById.get(item.messageId);
    if (index === undefined || index < 0 || index >= this.messages.length) {
      return;
    }
    this.openVideoPlayer(this.messages[index]);
  }

  @Builder
  private AudioMiniPlayerContent() {
    if (this.activeAudioMessageId > 0) {
      Row({ space: 8 }) {
        Button({ type: ButtonType.Circle }) {
          Image(this.playingAudioMessageId === this.activeAudioMessageId ? $r('app.media.tingzhi') : $r('app.media.playfill'))
            .width(16)
            .height(16)
            .objectFit(ImageFit.Contain)
        }
        .width(32)
        .height(32)
        .backgroundColor('#26000000')
        .onClick(() => {
          if (this.playingAudioMessageId === this.activeAudioMessageId) {
            this.pauseActiveAudio();
          } else {
            this.playActiveAudio();
          }
        })

        Column() {
          Text(this.activeAudioTitle.length > 0 ? this.activeAudioTitle : '音乐')
            .fontSize(13)
            .fontWeight(FontWeight.Bold)
            .fontColor('#111111')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
            .width('100%')
            .textAlign(TextAlign.Center)
          Text(this.activeAudioPerformer.length > 0 ? this.activeAudioPerformer : '未知作者')
            .fontSize(10)
            .fontColor('#687275')
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
            .margin({ top: 1 })
            .width('100%')
            .textAlign(TextAlign.Center)
        }
        .layoutWeight(1)
        .height(34)
        .justifyContent(FlexAlign.Center)
        .alignItems(HorizontalAlign.Center)

        Button({ type: ButtonType.Circle }) {
          Text('×')
            .fontSize(20)
            .fontColor('#222222')
            .textAlign(TextAlign.Center)
        }
        .width(30)
        .height(30)
        .backgroundColor('#1A000000')
        .onClick(() => {
          this.stopAudioPlayback();
        })
      }
      .height(42)
      .width('100%')
      .padding({ left: 8, right: 8 })
    }
  }

  @Builder
  private TopInfoPanel() {
    if (this.activeAudioMessageId > 0 || this.pinnedMessageText.length > 0) {
      Column() {
        if (this.activeAudioMessageId > 0) {
          this.AudioMiniPlayerContent()
        }
        if (this.activeAudioMessageId > 0 && this.pinnedMessageText.length > 0) {
          Divider()
            .strokeWidth(0.5)
            .color('#26000000')
            .margin({ left: 14, right: 14 })
        }
        if (this.pinnedMessageText.length > 0) {
          PinnedMessageBar({
            text: this.pinnedMessageText,
            onOpen: () => {
              this.openPinnedMessage();
            }
          })
        }
      }
      .width('92%')
      .height(this.getTopInfoPanelHeight())
      .borderRadius(22)
      .backgroundColor(this.floatingPanelColor)
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

  private shouldShowGroupSenderAvatars(): boolean {
    return this.isCommentMode || this.chatSubtitle === '群组会话';
  }

  @Builder
  private MessageSenderAvatar(msg: MessageItem, size: number, leftMargin: number = 0, rightMargin: number = 0) {
    ChatAvatarView({
      path: this.getCommentAvatarPath(msg.senderAvatarKey),
      label: msg.senderAvatarLabel,
      avatarSize: size,
      fontSize: size > 28 ? 15 : 12,
      leftMargin: leftMargin,
      rightMargin: rightMargin
    })
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
    ChatHeaderBar({
      embedded: this.embedded,
      title: this.chatTitle,
      subtitle: this.chatSubtitle,
      avatarPath: this.chatAvatarPath,
      avatarText: this.chatAvatarText,
      panelColor: this.floatingPanelColor,
      onBack: (): void => {
        if (!this.embedded) {
          console.info(`[ChatPage] back clicked chatId=${this.chatId}`);
          router.back();
        }
      },
      onTitleClick: (): void => {
        console.info(`[ChatPage] title clicked chatId=${this.chatId}`);
      },
      onAvatarClick: (): void => {
        console.info(`[ChatPage] avatar clicked chatId=${this.chatId}`);
        this.openChatProfile();
      }
    })
  }

  @Builder
  private AlbumMediaTile(msg: MessageItem, tileWidth: number, tileHeight: number) {
    if (msg.mediaType === 'messagePhoto') {
      PhotoMessageBody({
        msg: msg,
        displayPath: this.getPhotoDisplayPath(msg),
        imageId: `album-photo-${this.getPhotoImageRenderKey(msg)}`,
        displayWidth: tileWidth,
        displayHeight: tileHeight,
        downloadPercent: this.getPhotoDownloadPercent(msg),
        downloadText: ChatMediaFormatters.getPhotoDownloadText(this.getPhotoDownloadPercent(msg)),
        onOpen: (message: MessageItem): void => {
          this.openOriginalImagePreview(message);
        },
        onSave: (message: MessageItem): void => {
          this.requestOriginalImageSave(message);
        },
        onCancel: (fileId: number): void => {
          this.cancelMediaDownload(fileId);
        }
      })
      .height(tileHeight)
      .clip(true)
    } else {
      VideoMessageBody({
        msg: msg,
        mode: msg.mediaType === 'messageAnimation' ? 'animation' : 'video',
        displayWidth: tileWidth,
        displayHeight: tileHeight,
        videoPath: msg.videoPath,
        previewPath: this.getThumbnailDisplayPath(msg),
        videoId: `album-video-${this.getThumbnailImageRenderKey(msg)}`,
        previewId: msg.mediaType === 'messageAnimation' ?
          `album-animation-thumb-${this.getThumbnailImageRenderKey(msg)}` :
          `album-video-thumb-${this.getThumbnailImageRenderKey(msg)}`,
        inlinePlayback: this.shouldInlinePlayVideo(msg),
        remainingText: this.getInlineRemainingText(msg),
        onOpen: (message: MessageItem): void => {
          this.openMediaPreview(message);
        },
        onInlineUpdate: (messageId: number, duration: number, time: number): void => {
          this.updateInlineVideoProgress(messageId, duration, time);
        }
      })
      .height(tileHeight)
      .clip(true)
    }
  }

  @Builder
  private MessageTextLine(msg: MessageItem, row: MessageTextRow, maxWidth: number, topMargin: number) {
    Text() {
      ForEach(row.segments, (segment: MessageTextSegment) => {
        Span(segment.text)
          .fontSize(14)
          .fontColor(this.getMessageTextSegmentColor(msg, row, segment))
      }, (segment: MessageTextSegment): string => `${row.id}-${segment.id}`)
    }
    .lineHeight(20)
    .textAlign(TextAlign.Start)
    .constraintSize({ maxWidth: maxWidth })
    .margin({ top: topMargin })
    .onClick(() => {
      this.handleMessageRowClick(msg, row);
    })
  }

  @Builder
  private CommentAvatar(label: string, key: string, index: number) {
    if (key.length > 0 && this.getCommentAvatarPath(key).length > 0) {
      Image(this.getCommentAvatarPath(key))
        .width(16)
        .height(16)
        .borderRadius(8)
        .objectFit(ImageFit.Cover)
        .backgroundColor('#D9F0FF')
        .margin({ left: index === 0 ? 4 : -5 })
    } else {
      Text(label)
        .fontSize(8)
        .fontColor(Color.White)
        .fontWeight(FontWeight.Bold)
        .textAlign(TextAlign.Center)
        .width(16)
        .height(16)
        .borderRadius(8)
        .backgroundColor(index === 0 ? '#4A90E2' : (index === 1 ? '#34A853' : '#F2994A'))
        .margin({ left: index === 0 ? 4 : -5 })
    }
  }

  @Builder
  private MessageMetaFooter(msg: MessageItem) {
    Row({ space: 4 }) {
      if (!this.isCommentMode) {
        Text('👁')
          .fontSize(10)
          .fontColor(msg.isSelf ? '#5E8F78' : '#8A96A8')
        Text(`${msg.viewCount}`)
          .fontSize(10)
          .fontColor(msg.isSelf ? '#5E8F78' : '#8A96A8')
      }
      Text(msg.dateText)
        .fontSize(11)
        .fontColor(msg.isSelf ? '#5E8F78' : '#8A96A8')
      if (msg.isSelf) {
        Text('✓✓')
          .fontSize(12)
          .fontColor('#5E8F78')
          .margin({ left: 2 })
      }
    }
    .alignItems(VerticalAlign.Center)
  }

  @Builder
  private MessageCommentEntry(msg: MessageItem) {
    if (msg.commentCount > 0) {
      Column() {
        Divider()
          .strokeWidth(1)
          .color('#1F8A96A8')
          .width('100%')
        Row() {
          Row() {
            ForEach(msg.commentAvatars, (label: string, index: number) => {
              this.CommentAvatar(label, index < msg.commentAvatarKeys.length ? msg.commentAvatarKeys[index] : '', index)
            }, (label: string, index: number): string => `${msg.id}-comment-entry-${index}-${label}`)
            Text(this.getCommentCountText(msg.commentCount))
              .fontSize(12)
              .fontColor('#0A66CC')
              .fontWeight(FontWeight.Medium)
              .margin({ left: msg.commentAvatars.length > 0 ? 7 : 0 })
          }
          .alignItems(VerticalAlign.Center)
          Blank()
          Text('›')
            .fontSize(22)
            .fontColor('#8A96A8')
            .fontWeight(FontWeight.Bold)
            .lineHeight(22)
        }
        .width('100%')
        .height(34)
        .alignItems(VerticalAlign.Center)
      }
      .width('100%')
      .margin({ top: 5 })
      .onClick(() => {
        this.openMessageComments(msg);
      })
    }
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
        PhotoMessageBody({
          msg: msg,
          displayPath: this.getPhotoDisplayPath(msg),
          imageId: `photo-${this.getPhotoImageRenderKey(msg)}`,
          displayWidth: this.getMediaDisplayWidth(msg),
          displayHeight: this.getMediaDisplayHeight(msg),
          downloadPercent: this.getPhotoDownloadPercent(msg),
          downloadText: ChatMediaFormatters.getPhotoDownloadText(this.getPhotoDownloadPercent(msg)),
          onOpen: (message: MessageItem): void => {
            this.openOriginalImagePreview(message);
          },
          onSave: (message: MessageItem): void => {
            this.requestOriginalImageSave(message);
          },
          onCancel: (fileId: number): void => {
            this.cancelMediaDownload(fileId);
          }
        })
      } else if (msg.mediaType === 'messageAudio') {
        AudioMessageBody({
          msg: msg,
          downloadPercent: ChatMediaFormatters.getAudioDownloadPercent(msg),
          progressText: ChatMediaFormatters.getAudioProgressText(msg),
          topicText: this.getAudioTopicText(msg),
          isPlaying: this.playingAudioMessageId === msg.id,
          onToggle: (message: MessageItem): void => {
            this.toggleAudioPlayback(message);
          },
          onDownload: (fileId: number): void => {
            if (fileId > 0) {
              this.cacheController.start({
                fileId: fileId,
                messageId: msg.id,
                chatId: this.chatId,
                type: 'audio',
                title: msg.audioTitle.length > 0 ? msg.audioTitle : '音频',
                fileName: msg.audioTitle.length > 0 ? msg.audioTitle : '音频',
                path: msg.audioPath,
                downloadedSize: msg.audioDownloadedSize,
                expectedSize: msg.audioExpectedSize,
                duration: msg.audioDuration
              }, getContext(this) as common.UIAbilityContext);
            }
          }
        })
      } else if (msg.mediaType === 'messageVideo') {
        VideoMessageBody({
          msg: msg,
          mode: 'video',
          displayWidth: this.getMediaDisplayWidth(msg),
          displayHeight: this.getMediaDisplayHeight(msg),
          videoPath: msg.videoPath,
          previewPath: this.getThumbnailDisplayPath(msg),
          videoId: `video-${this.getThumbnailImageRenderKey(msg)}`,
          previewId: `video-thumb-${this.getThumbnailImageRenderKey(msg)}`,
          inlinePlayback: this.shouldInlinePlayVideo(msg),
          remainingText: this.getInlineRemainingText(msg),
          onOpen: (message: MessageItem): void => {
            this.openMediaPreview(message);
          },
          onInlineUpdate: (messageId: number, duration: number, time: number): void => {
            this.updateInlineVideoProgress(messageId, duration, time);
          }
        })
      } else if (msg.mediaType === 'messageAnimation') {
        VideoMessageBody({
          msg: msg,
          mode: 'animation',
          displayWidth: this.getMediaDisplayWidth(msg),
          displayHeight: this.getMediaDisplayHeight(msg),
          videoPath: msg.videoPath,
          previewPath: this.getThumbnailDisplayPath(msg),
          previewId: `animation-thumb-${this.getThumbnailImageRenderKey(msg)}`
        })
      }
      if (msg.mediaType === 'messageDocument') {
        DocumentMessageBody({
          msg: msg,
          sizeText: ChatMediaFormatters.getFileSizeText(msg.documentSize),
          onDownload: (fileId: number): void => {
            console.info(`[ChatPage] document download clicked messageId=${msg.id}, fileId=${fileId}`);
            if (fileId > 0) {
              this.cacheController.start({
                fileId: fileId,
                messageId: msg.id,
                chatId: this.chatId,
                type: 'file',
                title: msg.documentFileName.length > 0 ? msg.documentFileName : '文件',
                fileName: msg.documentFileName.length > 0 ? msg.documentFileName : '文件',
                downloadedSize: 0,
                expectedSize: msg.documentSize
              }, getContext(this) as common.UIAbilityContext);
            }
          }
        })
      }
      if (this.hasLinkPreviewMessage(msg)) {
        this.LinkPreviewMessage(msg)
      } else if (msg.textRows.length > 0) {
        ForEach(msg.textRows, (row: MessageTextRow) => {
          this.MessageTextLine(msg, row, 280, 3)
        })
      } else if (msg.mediaType !== 'messagePhoto' && msg.mediaType !== 'messageVideo' &&
        msg.mediaType !== 'messageAnimation' && msg.mediaType !== 'messageDocument' && msg.mediaType !== 'messageAudio') {
        Text(`[${msg.mediaType}]`)
          .fontSize(13)
          .fontColor('#666666')
          .textAlign(TextAlign.Start)
          .constraintSize({ maxWidth: 280 })
      }
      Row() {
        this.MessageMetaFooter(msg)
      }
      .justifyContent(FlexAlign.End)
      .width('100%')
      .constraintSize({ maxWidth: 280 })
      .margin({ top: 4 })
      this.MessageCommentEntry(msg)
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
        Column() {
          this.MessageBody(msg)
          MessageButtonPanelView({
            messageId: msg.id,
            rows: msg.buttonRows,
            onButtonClick: (messageId: number, button: MessageButtonItem): void => {
              this.handleInlineButton(messageId, button);
            }
          })
        }
        .alignItems(HorizontalAlign.Start)
        .constraintSize({ maxWidth: '80%' })
        if (this.shouldShowGroupSenderAvatars()) {
          this.MessageSenderAvatar(msg, 30, 7)
        }
      } else {
        if (this.shouldShowGroupSenderAvatars()) {
          this.MessageSenderAvatar(msg, 30)
        } else if (!this.isRobotMessage(msg) && !this.isChannelChat) {
          ChatAvatarView({
            path: this.chatAvatarPath,
            label: this.chatAvatarText,
            avatarSize: 30,
            fontSize: 17
          })
        }
        Column() {
          this.MessageBody(msg)
          MessageButtonPanelView({
            messageId: msg.id,
            rows: msg.buttonRows,
            onButtonClick: (messageId: number, button: MessageButtonItem): void => {
              this.handleInlineButton(messageId, button);
            }
          })
        }
        .alignItems(HorizontalAlign.Start)
        .constraintSize({ maxWidth: '80%' })
        .margin({ left: (this.shouldShowGroupSenderAvatars() || (!this.isRobotMessage(msg) && !this.isChannelChat)) ? 7 : 0 })
        Blank()
      }
    }
    .alignItems(VerticalAlign.Bottom)
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
        ForEach(ChatMessageGroupUtils.getAlbumRows(group.items), (row: MessageItem[]) => {
          Row({ space: 4 }) {
            ForEach(row, (msg: MessageItem) => {
              this.AlbumMediaTile(msg, 78, 104)
            }, (msg: MessageItem): string => `${msg.id}`)
          }
          .width('100%')
        }, (row: MessageItem[]): string => row.map((message: MessageItem): string => `${message.id}`).join('-'))
      }
      .width(242)

      ForEach(ChatMessageGroupUtils.getAlbumVisibleItems(group.items), (msg: MessageItem) => {
        if (msg.textRows.length > 0) {
          Column() {
            ForEach(msg.textRows, (row: MessageTextRow) => {
              this.MessageTextLine(msg, row, 300, 4)
            }, (row: MessageTextRow): string => `${msg.id}-${row.id}`)
          }
          .width('100%')
          .alignItems(HorizontalAlign.Start)
        }
      }, (msg: MessageItem): string => `caption-${msg.id}`)

      Row() {
        this.MessageMetaFooter(group.items[group.items.length - 1])
      }
      .justifyContent(FlexAlign.End)
      .width('100%')
      .constraintSize({ maxWidth: 300 })
      .margin({ top: 4 })
      this.MessageCommentEntry(group.items[group.items.length - 1])
    }
    .alignItems(HorizontalAlign.Start)
    .padding({ left: 9, right: 9, top: 7, bottom: 5 })
    .borderRadius({
      topLeft: 12,
      topRight: 12,
      bottomLeft: group.items[0].isSelf ? 12 : 3,
      bottomRight: group.items[0].isSelf ? 3 : 12
    })
    .backgroundColor(ChatMessageGroupUtils.albumHasTarget(group) ? '#FFF2CC' : (group.items[0].isSelf ? '#46A669' : Color.White))
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
          Column() {
            this.AlbumMessageBody(group)
          }
          .alignItems(HorizontalAlign.Start)
          .constraintSize({ maxWidth: '80%' })
          if (this.shouldShowGroupSenderAvatars()) {
            this.MessageSenderAvatar(group.items[0], 30, 7)
          }
        } else {
          if (this.shouldShowGroupSenderAvatars()) {
            this.MessageSenderAvatar(group.items[0], 30)
          } else if (!this.isRobotMessage(group.items[0]) && !this.isChannelChat) {
            ChatAvatarView({
              path: this.chatAvatarPath,
              label: this.chatAvatarText,
              avatarSize: 30,
              fontSize: 17
            })
          }
          Column() {
            this.AlbumMessageBody(group)
          }
          .alignItems(HorizontalAlign.Start)
          .constraintSize({ maxWidth: '80%' })
          .margin({ left: (this.shouldShowGroupSenderAvatars() || (!this.isRobotMessage(group.items[0]) && !this.isChannelChat)) ? 7 : 0 })
          Blank()
        }
      }
      .alignItems(VerticalAlign.Bottom)
      .width('100%')
      .padding({ left: 8, right: 8, top: 4, bottom: 4 })
    }
  }

  @Builder
  private CommentStartDivider() {
    Row() {
      Divider()
        .strokeWidth(1)
        .color('#33FFFFFF')
        .layoutWeight(1)
      Text('评论已开始')
        .fontSize(12)
        .fontColor('#F2FFFFFF')
        .padding({ left: 10, right: 10, top: 4, bottom: 4 })
        .borderRadius(11)
        .backgroundColor('#66000000')
      Divider()
        .strokeWidth(1)
        .color('#33FFFFFF')
        .layoutWeight(1)
    }
    .width('100%')
    .alignItems(VerticalAlign.Center)
    .padding({ left: 28, right: 28, top: 10, bottom: 8 })
  }

  private isRobotMessage(msg: MessageItem): boolean {
    return !msg.isSelf && (this.chatSubtitle === '机器人' || msg.buttonRows.length > 0 || msg.replyText.length > 0);
  }

  private getChannelNotificationButtonText(): string {
    if (this.channelJoinPending) {
      return '正在订阅...';
    }
    if (!this.isChannelJoined) {
      return '订阅频道';
    }
    return this.channelNotificationsPaused ? '接收消息通知' : '暂停消息通知';
  }

  private handleChannelAction(): void {
    if (this.channelJoinPending) {
      return;
    }
    if (!this.isChannelJoined) {
      this.channelJoinPending = true;
      console.info(`[ChatPage] join channel chatId=${this.chatId}`);
      this.td.joinChat(this.chatId);
      setTimeout(() => {
        this.td.getChat(this.chatId);
        if (this.currentSupergroupId !== 0) {
          this.td.getSupergroup(this.currentSupergroupId);
        }
      }, 500);
      return;
    }
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
    ChannelNotificationButtonView({
      panelColor: this.floatingPanelColor,
      text: this.getChannelNotificationButtonText(),
      dimIcon: this.channelNotificationsPaused || !this.isChannelJoined,
      onGiftClick: (): void => {
        console.info(`[ChatPage] channel gift clicked chatId=${this.chatId}`);
      },
      onMainClick: (): void => {
        this.handleChannelAction();
      },
      onSearchClick: (): void => {
        console.info(`[ChatPage] channel search clicked chatId=${this.chatId}`);
      }
    })
  }

  @Builder
  private Composer() {
    ChatComposerBar({
      panelColor: this.floatingPanelColor,
      inputText: this.input,
      showBotMenuButton: this.shouldShowBotMenuButton(),
      botMenuVisible: this.botMenuVisible,
      onBotMenuToggle: (): void => {
        console.info(`[ChatPage] bot menu toggle chatId=${this.chatId}, visible=${!this.botMenuVisible}`);
        this.setBotMenuVisible(!this.botMenuVisible);
      },
      onAttachClick: (): void => {
        console.info(`[ChatPage] attach clicked chatId=${this.chatId}`);
        this.statusText = '附件功能暂未接入';
      },
      onInputChange: (value: string): void => {
        this.input = value;
      },
      onEmojiClick: (): void => {
        console.info(`[ChatPage] emoji clicked chatId=${this.chatId}`);
        this.statusText = '表情面板暂未接入';
      },
      onSendOrVoiceClick: (): void => {
        console.info(`[ChatPage] voice/send clicked chatId=${this.chatId}, textLength=${this.input.trim().length}`);
        if (!this.canSendMessages) {
          this.statusText = '当前会话不允许发送消息';
          return;
        }
        if (this.input.trim()) {
          this.td.sendMessage(this.chatId, this.input);
          this.input = '';
          this.setBotMenuVisible(false);
        } else {
          this.statusText = '语音功能暂未接入';
        }
      }
    })
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
        this.TopInfoPanel()
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
          if (this.canSendMessages) {
            this.Composer()
          } else if (this.isChannelChat) {
            this.ChannelNotificationButton()
          } else {
            ReadOnlyConversationBar({ barColor: this.floatingPanelColor })
          }
        }
        .width('100%')

        if (this.canSendMessages && !this.isChannelChat && this.replyKeyboardRows.length > 0) {
          ReplyKeyboardPanelView({
            rows: this.replyKeyboardRows,
            onButtonClick: (button: ReplyKeyboardButtonItem): void => {
              this.sendReplyKeyboardButton(button);
            }
          })
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

      Swiper(this.mediaPreviewSwiperController) {
        ForEach(this.mediaPreviewItems, (item: MediaPreviewItem) => {
          this.MediaPreviewPage(item)
        }, (item: MediaPreviewItem): string => item.id)
      }
      .width('100%')
      .height('100%')
      .index(this.mediaPreviewIndex)
      .indicator(false)
      .loop(false)
      .duration(220)
      .onChange((index: number) => {
        this.mediaPreviewIndex = index;
        if (index >= 0 && index < this.mediaPreviewItems.length) {
          this.imagePreviewPath = this.mediaPreviewItems[index].displayPath;
        }
      })
      .opacity(this.imagePreviewOpacity)
      .scale({
        x: this.imagePreviewScale,
        y: this.imagePreviewScale,
        centerX: '50%',
        centerY: '50%'
      })

      Column() {
        Blank()
        this.MediaPreviewFooter()
      }
      .width('100%')
      .height('100%')
      .opacity(this.imagePreviewOpacity)
    }
    .width('100%')
    .height('100%')
    .animation({ duration: 180, curve: Curve.EaseOut })
    .zIndex(99)
  }

  @Builder
  private MediaPreviewPage(item: MediaPreviewItem) {
    Stack({ alignContent: Alignment.Center }) {
      if (item.type === 'photo' && item.displayPath.length > 0) {
        Image(item.displayPath)
          .width('100%')
          .height('100%')
          .objectFit(ImageFit.Contain)
      } else if (item.previewPath.length > 0) {
        Image(item.previewPath)
          .width('100%')
          .height('100%')
          .objectFit(ImageFit.Contain)
      } else {
        Text(item.type === 'photo' ? '图片下载中...' : '视频预览加载中...')
          .fontSize(16)
          .fontColor(Color.White)
      }

      if (item.type === 'video') {
        Button('▶')
          .fontSize(32)
          .fontColor(Color.White)
          .width(62)
          .height(62)
          .borderRadius(31)
          .backgroundColor('#66000000')
          .onClick(() => {
            this.openCurrentPreviewVideo(item);
          })
      }
    }
    .width('100%')
    .height('100%')
    .onClick(() => {
      if (item.type === 'video') {
        this.openCurrentPreviewVideo(item);
      }
    })
  }

  @Builder
  private MediaPreviewFooter() {
    Column({ space: 8 }) {
      Row() {
        Text(`${this.mediaPreviewIndex + 1}/${this.mediaPreviewItems.length}`)
          .fontSize(13)
          .fontColor('#DDFFFFFF')
          .padding({ left: 10, right: 10, top: 4, bottom: 4 })
          .borderRadius(12)
          .backgroundColor('#55000000')
      }
      .width('100%')
      .justifyContent(FlexAlign.Center)

      Scroll() {
        Row({ space: 8 }) {
          ForEach(this.mediaPreviewItems, (item: MediaPreviewItem, index: number) => {
            this.MediaPreviewThumb(item, index)
          }, (item: MediaPreviewItem): string => `thumb-${item.id}`)
        }
        .padding({ left: 14, right: 14 })
      }
      .width('100%')
      .height(72)
      .scrollable(ScrollDirection.Horizontal)
      .scrollBar(BarState.Off)
    }
    .width('100%')
    .padding({ bottom: AppLayout.BOTTOM_SAFE_HEIGHT + 14 })
    .linearGradient({
      angle: 0,
      colors: [['#00000000', 0], ['#AA000000', 1]]
    })
  }

  @Builder
  private MediaPreviewThumb(item: MediaPreviewItem, index: number) {
    Stack({ alignContent: Alignment.Center }) {
      if (item.previewPath.length > 0) {
        Image(item.previewPath)
          .width(54)
          .height(54)
          .objectFit(ImageFit.Cover)
      } else if (item.displayPath.length > 0) {
        Image(item.displayPath)
          .width(54)
          .height(54)
          .objectFit(ImageFit.Cover)
      } else {
        Column()
          .width(54)
          .height(54)
          .backgroundColor('#44FFFFFF')
      }

      if (item.type === 'video') {
        Text('▶')
          .fontSize(18)
          .fontColor(Color.White)
      }
    }
    .width(58)
    .height(58)
    .borderRadius(4)
    .clip(true)
    .border({
      width: this.mediaPreviewIndex === index ? 2 : 0,
      color: '#FFFFFFFF'
    })
    .opacity(this.mediaPreviewIndex === index ? 1 : 0.68)
    .onClick(() => {
      this.setMediaPreviewIndex(index);
    })
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
        if (this.isCommentMode) {
          ListItem() {
            this.MessageRow(this.getSourceCommentDisplayMessage())
          }
          ListItem() {
            this.CommentStartDivider()
          }
        }
        Repeat<MessageGroupItem>(this.messageGroups)
          .each((repeatItem: RepeatItem<MessageGroupItem>) => {
            ListItem() {
              Column() {
                if (ChatMessageGroupUtils.groupContainsMessage(repeatItem.item, this.getFirstUnreadMessageId())) {
                  UnreadDividerView()
                }
                this.MessageGroupRow(repeatItem.item)
              }
              .width('100%')
            }
            .onVisibleAreaChange([0.0, 0.35], (isVisible: boolean, currentRatio: number) => {
              if (isVisible && currentRatio >= 0.35) {
                this.queueVisibleMessageWork(repeatItem.item.items);
              }
            })
          })
          .key((group: MessageGroupItem): string => group.id)
        ListItem() {
          Column()
            .height(this.getMessageListBottomInset())
            .animation({ duration: 220, curve: Curve.EaseOut })
        }
      }
      .width('100%')
      .height('100%')
      .backgroundColor(Color.Transparent)
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
    .onAppear(() => {
      console.error(`[ChatDetailDiag] ChatPage root appear chatId=${this.chatId}, initialChatId=${this.initialChatId}, embedded=${this.embedded}, messages=${this.messages.length}, groups=${this.messageGroups.length}`);
    })
  }
}
