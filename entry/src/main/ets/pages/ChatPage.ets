// entry/src/main/ets/pages/ChatPage.ets
import {
  FormattedText,
  TdChat,
  TdAnimation,
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
import router from '@ohos.router';

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

interface MessageItem {
  id: number;
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
  videoDownloadedSize: number;
  videoExpectedSize: number;
  videoCanPlay: boolean;
  videoDuration: number;
  dateText: string;
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
  initialChatId: number = 0;
  initialMessageId: number = 0;
  initialTitle: string = '';
  initialAvatarPath: string = '';
  initialAvatarFileId: number = 0;
  initialCategory: string = '';
  initialUnreadCount: number = 0;
  initialLastReadInboxMessageId: number = 0;
  embedded: boolean = false;
  private messageScroller: Scroller = new Scroller();
  private td = TdlibService.getInstance();
  private listenersRegistered: boolean = false;
  private historyMode: string = 'replace';
  private historyRequestSource: string = 'latest';
  private historyFallbackTried: boolean = false;
  private entryUnreadCount: number = 0;
  private requestedMediaFileIds: Set<number> = new Set();

  aboutToAppear() {
    this.readRouteParams();
    this.registerListeners();
    if (this.chatId !== 0) {
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
    this.td.onUpdate('messages', (update: TdUpdate) => {
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
      if (this.historyMode === 'prepend') {
        const beforeCount = this.messages.length;
        this.mergeMessages(nextMessages);
        this.hasMoreHistory = this.messages.length > beforeCount;
      } else {
        this.messages = this.resolveReplyTexts(this.sortMessages(nextMessages));
        this.hasMoreHistory = nextMessages.length > 0;
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
      }
      this.historyLoading = false;
      this.statusText = this.messages.length > 0 ? '' : '暂无消息';
      this.historyMode = 'append';
    });
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
        positions: update.positions
      };
      console.info(`[ChatPage] received chat title=${chat.title}, id=${chat.id}`);
      this.applyChatInfo(chat);
    });
    this.td.onUpdate('updateNewMessage', (update: TdUpdate) => {
      const message: TdMessage | undefined = update.message;
      if (!message || !this.isCurrentChatMessage(message)) {
        return;
      }
      console.info(`[ChatPage] received updateNewMessage id=${message.id}, chatId=${message.chat_id}`);
      const item = this.toMessageItem(message);
      this.upsertMessage(item);
      this.requestMessageItemMedia(item);
      if (!message.is_outgoing) {
        this.unreadCount += 1;
      }
    });
    this.td.onUpdate('updateMessageContent', (update: TdUpdate) => {
      if (update.chat_id === this.chatId && update.message_id !== undefined && update.new_content) {
        console.info(`[ChatPage] received updateMessageContent messageId=${update.message_id}`);
        this.applyMessageContentUpdate(update.message_id, update.new_content);
      }
    });
    this.td.onUpdate('updateMessageEdited', (update: TdUpdate) => {
      if (update.chat_id === this.chatId && update.message_id !== undefined) {
        console.info(`[ChatPage] received updateMessageEdited messageId=${update.message_id}`);
        this.applyReplyMarkupUpdate(update.message_id, update.reply_markup);
      }
    });
    this.td.onUpdate('updateChatReplyMarkup', (update: TdUpdate) => {
      const message: TdMessage | undefined = update.reply_markup_message;
      if (update.chat_id === this.chatId && message) {
        console.info(`[ChatPage] received updateChatReplyMarkup messageId=${message.id}`);
        this.upsertMessage(this.toMessageItem(message));
      }
    });
    this.td.onUpdate('callbackQueryAnswer', (update: TdUpdate) => {
      console.info(`[ChatPage] received callbackQueryAnswer text=${update.text}, url=${update.url}`);
      if (update.url && update.url.length > 0) {
        this.openUrl(update.url);
      } else if (update.text && update.text.length > 0) {
        this.statusText = update.text;
      }
    });
    this.td.onUpdate('messageLinkInfo', (update: TdUpdate) => {
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
    this.td.onUpdate('file', (update: TdUpdate) => {
      if (update.file) {
        console.info(`[ChatPage] received file id=${update.file.id}`);
        this.applyFileUpdate(update.file);
      }
    });
    this.td.onUpdate('updateFile', (update: TdUpdate) => {
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

  private refreshHistory(): void {
    if (this.historyLoading || this.chatId === 0) {
      return;
    }
    this.historyLoading = true;
    this.historyMode = 'replace';
    this.historyFallbackTried = false;
    this.statusText = this.unreadCount > 0 ? '正在定位未读消息...' : '正在刷新历史消息...';
    console.info(`[ChatPage] refreshHistory chatId=${this.chatId}, unread=${this.unreadCount}, lastReadInbox=${this.lastReadInboxMessageId}`);
    this.td.getChat(this.chatId);
    if (this.unreadCount > 0 && this.lastReadInboxMessageId > 0) {
      this.historyRequestSource = 'unread';
      this.td.getChatHistory(this.chatId, this.getInitialHistoryLimit(), this.lastReadInboxMessageId, -1);
      return;
    }
    this.historyRequestSource = 'latest';
    this.td.getChatHistory(this.chatId, this.getInitialHistoryLimit(), 0, 0);
  }

  private loadOlderHistory(): void {
    if (this.historyLoading || !this.hasMoreHistory || this.chatId === 0 || this.messages.length === 0) {
      return;
    }
    const oldestMessageId = this.messages[0].id;
    this.historyLoading = true;
    this.historyMode = 'prepend';
    this.historyRequestSource = 'older';
    this.statusText = '正在加载更早消息...';
    console.info(`[ChatPage] loadOlderHistory chatId=${this.chatId}, fromMessageId=${oldestMessageId}`);
    this.td.getChatHistory(this.chatId, 20, oldestMessageId, 0);
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
    const content: TdMessageContent | undefined = message.content;
    const item: MessageItem = {
      id: message.id,
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
      videoDownloadedSize: 0,
      videoExpectedSize: 0,
      videoCanPlay: false,
      videoDuration: 0,
      dateText: this.getMessageTime(message)
    };
    if (content && content.type === 'messagePhoto' && content.photo) {
      const size: TdPhotoSize | undefined = this.getBestPhotoSize(content.photo);
      if (size) {
        item.photoFileId = size.photo.id;
        item.photoPath = this.getLocalPath(size.photo);
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
      if (animation.thumbnail && animation.thumbnail.file) {
        item.thumbnailFileId = animation.thumbnail.file.id;
        item.thumbnailPath = this.getLocalPath(animation.thumbnail.file);
      }
    }
    console.info(`[ChatPage] message item id=${item.id}, type=${item.mediaType}, format=${item.mediaFormat}, textLength=${item.text.length}, photoFileId=${item.photoFileId}, videoFileId=${item.videoFileId}`);
    return item;
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
      const size: TdPhotoSize | undefined = this.getBestPhotoSize(content.photo);
      return size ? this.getMediaFormat('', '', this.getLocalPath(size.photo), 'jpg') : 'jpg';
    }
    if (content.type === 'messageVideo' && content.video) {
      return this.getMediaFormat(content.video.file_name, content.video.mime_type, this.getLocalPath(content.video.video), 'mp4');
    }
    if (content.type === 'messageAnimation' && content.animation) {
      return this.getMediaFormat(content.animation.file_name, content.animation.mime_type, this.getLocalPath(content.animation.animation), 'gif');
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
    if ((content.type === 'messagePhoto' || content.type === 'messageVideo' || content.type === 'messageAnimation') &&
      content.caption) {
      return content.caption;
    }
    return undefined;
  }

  private getMessageText(content: TdMessageContent | undefined): string {
    const formattedText = this.getMessageFormattedText(content);
    return formattedText ? formattedText.text : '';
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
    this.chatSubtitle = this.getChatSubtitle(this.getChatCategory(chat));
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
  }

  private getChatCategory(chat: TdChat): string {
    if (!chat.type) {
      return '个人';
    }
    if (chat.type.type === 'chatTypeSupergroup' && chat.type.is_channel) {
      return '频道';
    }
    if (chat.type.type === 'chatTypeBasicGroup' || chat.type.type === 'chatTypeSupergroup') {
      return '群组';
    }
    return '个人';
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
    const parts: string[] = text.split(' ');
    for (let index = 0; index < parts.length; index++) {
      const part = parts[index].trim();
      if (part.startsWith('http://') || part.startsWith('https://') || part.startsWith('tg://')) {
        return part;
      }
    }
    return '';
  }

  private hasLinkPreviewMessage(msg: MessageItem): boolean {
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
    }
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
      const size: TdPhotoSize | undefined = this.getBestPhotoSize(content.photo);
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

  private scrollToLatestAndMarkRead(): void {
    console.info(`[ChatPage] scroll to latest and mark read chatId=${this.chatId}, unread=${this.unreadCount}`);
    if (this.messages.length > 0) {
      this.messageScroller.scrollToIndex(this.messages.length + 1, true, ScrollAlign.END);
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
        this.messageScroller.scrollToIndex(this.messages.length + 1, animated, ScrollAlign.END);
      }
    }, delay);
  }

  private scheduleScrollToUnread(animated: boolean): void {
    setTimeout(() => {
      const anchorId = this.getFirstUnreadMessageId();
      const index = this.messages.findIndex((message: MessageItem): boolean => message.id === anchorId);
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
      videoDownloadedSize: message.videoDownloadedSize,
      videoExpectedSize: message.videoExpectedSize,
      videoCanPlay: message.videoCanPlay,
      videoDuration: message.videoDuration,
      dateText: message.dateText
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
        videoDownloadedSize: message.videoDownloadedSize,
        videoExpectedSize: message.videoExpectedSize,
        videoCanPlay: message.videoCanPlay,
        videoDuration: message.videoDuration,
        dateText: message.dateText
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
        videoDownloadedSize: 0,
        videoExpectedSize: 0,
        videoCanPlay: false,
        videoDuration: 0,
        dateText: message.dateText
      };
      if (content.type === 'messagePhoto' && content.photo) {
        const size: TdPhotoSize | undefined = this.getBestPhotoSize(content.photo);
        if (size) {
          next.photoFileId = size.photo.id;
          next.photoPath = this.getLocalPath(size.photo);
        }
      }
      if (content.type === 'messageVideo' && content.video) {
        next.videoFileId = content.video.video.id;
        next.videoPath = this.getLocalPath(content.video.video);
        next.videoDownloadedSize = this.getDownloadedSize(content.video.video);
        next.videoExpectedSize = this.getExpectedSize(content.video.video);
        next.videoCanPlay = this.canPlayVideo(content.video.video);
        next.videoDuration = content.video.duration ? content.video.duration : 0;
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
        if (content.animation.thumbnail && content.animation.thumbnail.file) {
          next.thumbnailFileId = content.animation.thumbnail.file.id;
          next.thumbnailPath = this.getLocalPath(content.animation.thumbnail.file);
        }
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
        videoDownloadedSize: message.videoDownloadedSize,
        videoExpectedSize: message.videoExpectedSize,
        videoCanPlay: message.videoCanPlay,
        videoDuration: message.videoDuration,
        dateText: message.dateText
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
    if (markerIndex < 0) {
      return result;
    }
    const tail = url.substring(markerIndex + marker.length);
    const parts = tail.split('/');
    if (parts.length < 2) {
      return result;
    }
    const internalChatId = Number(parts[0]);
    const messageId = Number(parts[1].split('?')[0]);
    if (!Number.isNaN(internalChatId) && !Number.isNaN(messageId)) {
      result.chatId = Number(`-100${internalChatId}`);
      result.messageId = messageId;
    }
    return result;
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
    router.pushUrl({
      url: 'pages/VideoPlayerPage',
      params: {
        chatId: this.chatId,
        messageId: msg.id,
        fileId: msg.videoFileId,
        videoPath: msg.videoPath,
        previewUri: msg.thumbnailPath
      }
    });
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
          .height('100%')
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
            .maxLines(2)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
            .margin({ top: 2 })
          Text(this.getLinkPreviewDescription(msg))
            .fontSize(12)
            .fontColor('#111111')
            .lineHeight(16)
            .maxLines(3)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
            .margin({ top: 2 })
        }
        .layoutWeight(1)
        .alignItems(HorizontalAlign.Start)
        .margin({ right: 8 })

        this.LinkPreviewThumb(58)
      }
      .width('100%')
      .height(92)
      .padding({ left: 7, right: 7, top: 7, bottom: 7 })
      .borderRadius(7)
      .backgroundColor(msg.isSelf ? '#C4F4B6' : '#F3F8EF')
      .margin({ top: 6 })
      .onClick(() => {
        this.openUrl(this.getPrimaryLinkUrl(msg));
      })
    }
    .width(286)
  }

  @Builder
  private ChatHeader() {
    Stack({ alignContent: Alignment.TopStart }) {
      Row() {
        if (!this.embedded) {
          Image($r('app.media.back'))
            .width(22)
            .height(22)
            .objectFit(ImageFit.Contain)
        } else {
          Blank()
            .width(22)
            .height(22)
        }
      }
      .height(40)
      .padding({ left: 9, right: 9 })
      .borderRadius(20)
      .backgroundColor('#EFFFFFFF')
      .backdropBlur(18)
      .shadow({ radius: 12, color: '#1A000000', offsetY: 4 })
      .onClick(() => {
        if (!this.embedded) {
          console.info(`[ChatPage] back clicked chatId=${this.chatId}`);
          router.back();
        }
      })
      .position({ x: 14, y: 40 })

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
            Image($r('app.media.jingyin'))
              .width(11)
              .height(11)
              .objectFit(ImageFit.Contain)
              .opacity(0.62)
              .margin({ left: 4 })
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
        .backgroundColor('#EFFFFFFF')
        .backdropBlur(18)
        .shadow({ radius: 12, color: '#16000000', offsetY: 4 })
        .onClick(() => {
          console.info(`[ChatPage] title clicked chatId=${this.chatId}`);
        })
        Blank()
      }
      .width('100%')
      .height(40)
      .position({ x: 0, y: 40 })

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
          this.refreshHistory();
        })
      }
      .width('100%')
      .height(40)
      .padding({ right: 12 })
      .position({ x: 0, y: 40 })
    }
    .width('100%')
    .height(90)
  }

  @Builder
  private MessageBody(msg: MessageItem) {
    Column() {
      if (!msg.isSelf && msg.replyText.length > 0) {
        Row() {
          Column()
            .width(2)
            .height(28)
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
              .constraintSize({ maxWidth: 244 })
              .margin({ top: 1 })
          }
          .margin({ left: 6 })
        }
        .constraintSize({ maxWidth: 266 })
        .padding({ left: 6, right: 6, top: 5, bottom: 5 })
        .borderRadius(8)
        .backgroundColor('#F3F8FB')
        .margin({ bottom: 5 })
      }
      if (msg.mediaType === 'messagePhoto') {
        Stack({ alignContent: Alignment.Center }) {
          if (msg.photoPath.length > 0) {
            Image(msg.photoPath)
              .width(158)
              .height(140)
              .objectFit(ImageFit.Contain)
              .borderRadius(12)
              .gesture(
                LongPressGesture().onAction(() => {
                  this.requestImageSave(msg.photoPath);
                })
              )
          } else {
            Text('图片下载中...')
              .fontSize(14)
              .fontColor('#666666')
              .width(158)
              .height(140)
              .textAlign(TextAlign.Center)
              .backgroundColor('#E6F4FF')
              .borderRadius(12)
          }
          this.MediaFormatBadge(msg.mediaFormat)
        }
        .width(158)
        .height(140)
      } else if (msg.mediaType === 'messageVideo') {
        Stack({ alignContent: Alignment.Center }) {
          if (this.shouldInlinePlayVideo(msg) && msg.videoPath.length > 0) {
            Video({
              src: msg.videoPath,
              previewUri: msg.thumbnailPath.length > 0 ? msg.thumbnailPath : undefined
            })
              .width(168)
              .height(120)
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
              .width(168)
              .height(120)
              .objectFit(ImageFit.Cover)
              .borderRadius(12)
          } else {
            Text('视频预览')
              .fontSize(16)
              .fontColor('#666666')
              .width(168)
              .height(120)
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
        .width(168)
        .height(120)
        .onClick(() => {
          this.openVideoPlayer(msg);
        })
      } else if (msg.mediaType === 'messageAnimation') {
        Stack({ alignContent: Alignment.Center }) {
          if (msg.videoPath.length > 0) {
            Image(msg.videoPath)
              .width(168)
              .height(120)
              .objectFit(ImageFit.Cover)
              .borderRadius(12)
          } else if (msg.thumbnailPath.length > 0) {
            Image(msg.thumbnailPath)
              .width(168)
              .height(120)
              .objectFit(ImageFit.Cover)
              .borderRadius(12)
          } else {
            Text('GIF预览')
              .fontSize(16)
              .fontColor('#666666')
              .width(168)
              .height(120)
              .textAlign(TextAlign.Center)
              .backgroundColor('#E6F4FF')
              .borderRadius(12)
          }
          this.MediaFormatBadge(msg.mediaFormat.length > 0 ? msg.mediaFormat : 'gif')
        }
        .width(168)
        .height(120)
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
              .constraintSize({ maxWidth: 270 })
              .margin({ top: 3 })
              .onClick(() => {
                this.openUrl(row.url);
              })
          } else {
            Text(row.text)
              .fontSize(14)
              .fontColor('#111111')
              .lineHeight(20)
              .textAlign(TextAlign.Start)
              .constraintSize({ maxWidth: 270 })
              .margin({ top: 3 })
          }
        })
      } else if (msg.mediaType !== 'messagePhoto' && msg.mediaType !== 'messageVideo' &&
        msg.mediaType !== 'messageAnimation') {
        Text(`[${msg.mediaType}]`)
          .fontSize(13)
          .fontColor('#666666')
          .textAlign(TextAlign.Start)
          .constraintSize({ maxWidth: 270 })
      }
      if (msg.buttonRows.length > 0) {
        Column() {
          ForEach(msg.buttonRows, (row: MessageButtonItem[]) => {
            Row() {
              ForEach(row, (button: MessageButtonItem) => {
                Button(button.text)
                  .fontSize(8)
                  .fontColor('#2C6FA3')
                  .height(22)
                  .padding({ left: 6, right: 6 })
                  .borderRadius(7)
                  .backgroundColor('#EEF7FF')
                  .layoutWeight(1)
                  .margin(2)
                  .onClick(() => {
                    this.handleInlineButton(msg.id, button);
                  })
              })
            }
            .width(270)
          })
        }
        .width(270)
        .constraintSize({ maxWidth: 270 })
        .margin({ top: 5 })
      }
      Row() {
        Blank()
        Text(msg.dateText)
          .fontSize(11)
          .fontColor(msg.isSelf ? '#5E8F78' : '#8A96A8')
          .margin({ top: 4 })
        if (msg.isSelf) {
          Text('✓✓')
            .fontSize(12)
            .fontColor('#5E8F78')
            .margin({ left: 4, top: 4 })
        }
      }
      .width('100%')
    }
    .alignItems(HorizontalAlign.Start)
    .padding({ left: 9, right: 9, top: 7, bottom: 5 })
    .borderRadius({ topLeft: 12, topRight: 12, bottomLeft: msg.isSelf ? 12 : 3, bottomRight: msg.isSelf ? 3 : 12 })
    .backgroundColor(msg.isTarget ? '#FFF2CC' : (msg.isSelf ? '#46A669' : Color.White))
    .constraintSize({ maxWidth: 292 })
    .clip(true)
    .shadow({ radius: 4, color: '#10000000', offsetY: 1 })
  }

  @Builder
  private MessageRow(msg: MessageItem) {
    Row() {
      if (msg.isSelf) {
        Blank()
        this.MessageBody(msg)
      } else {
        if (!this.isRobotMessage(msg)) {
          this.ChatAvatar(30)
        }
        Column() {
          this.MessageBody(msg)
        }
        .margin({ left: this.isRobotMessage(msg) ? 0 : 7 })
        Blank()
      }
    }
    .width('100%')
    .padding({ left: 8, right: 8, top: 4, bottom: 4 })
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

  @Builder
  private Composer() {
    Row() {
      Button() {
        Image($r('app.media.file_attachment'))
          .width(21)
          .height(21)
          .objectFit(ImageFit.Contain)
      }
      .width(40)
      .height(40)
      .borderRadius(20)
      .backgroundColor('#EFFFFFFF')
      .backdropBlur(18)
      .shadow({ radius: 10, color: '#16000000', offsetY: 3 })
      .onClick(() => {
        console.info(`[ChatPage] attach clicked chatId=${this.chatId}`);
        this.statusText = '附件功能暂未接入';
      })

      Row() {
        TextInput({ placeholder: '输入消息...', text: this.input })
          .fontSize(14)
          .fontColor('#222222')
          .placeholderColor('#8F9A91')
          .backgroundColor(Color.Transparent)
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
      .backgroundColor('#EFFFFFFF')
      .backdropBlur(18)
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
      .backgroundColor('#EFFFFFFF')
      .backdropBlur(18)
      .shadow({ radius: 10, color: '#16000000', offsetY: 3 })
      .onClick(() => {
        console.info(`[ChatPage] voice/send clicked chatId=${this.chatId}, textLength=${this.input.trim().length}`);
        if (this.input.trim()) {
          this.td.sendMessage(this.chatId, this.input);
          this.input = '';
        } else {
          this.statusText = '语音功能暂未接入';
        }
      })
    }
    .width('100%')
    .height(44)
  }

  @Builder
  private TopFloatingArea() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column()
        .width('100%')
        .height(90)
        .linearGradient({
          direction: GradientDirection.Bottom,
          colors: [
            ['#ffffffff', 0.0],
            ['#a3ffffff', 0.6],
            ['#00ffffff', 1.0]
          ]
        })
        .linearGradientBlur(18, {
          fractionStops: [
            [0.0, 0.0],
            [0.48, 0.58],
            [1.0, 1.0]
          ],
          direction: GradientDirection.Top
        })

      Column() {
        this.ChatHeader()
      }
      .width('100%')
      .height(90)
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
        .position({ x: 0, y: 78 })
      }
    }
    .width('100%')
    .height(118)
  }

  @Builder
  private BottomFloatingArea() {
    Stack({ alignContent: Alignment.Bottom }) {
      Column()
        .width('100%')
        .height(92)
        .linearGradient({
          direction: GradientDirection.Bottom,
          colors: [
            ['#00FFFFFF', 0.0],
            ['#92FFFFFF', 0.54],
            ['#DFFFFFFF', 1.0]
          ]
        })
        .linearGradientBlur(18, {
          fractionStops: [
            [0.0, 0.0],
            [0.48, 0.54],
            [1.0, 1.0]
          ],
          direction: GradientDirection.Bottom
        })

      Row() {
        this.Composer()
      }
      .width('100%')
      .padding({ left: 25, right: 25, bottom: 28 })
    }
    .width('100%')
    .height(96)
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
      .backdropBlur(18)
      .shadow({ radius: 12, color: '#22000000', offsetY: 4 })
      .onClick(() => {
        this.scrollToLatestAndMarkRead();
      })
    }
    .alignItems(HorizontalAlign.Center)
  }

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Image($r('app.media.phone_bg_01'))
        .width('100%')
        .height('100%')
        .objectFit(ImageFit.Cover)

      List({ scroller: this.messageScroller }) {
        ListItem() {
          Column()
            .height(86)
        }
        ForEach(this.messages, (msg: MessageItem) => {
          ListItem() {
            Column() {
              if (msg.id === this.getFirstUnreadMessageId()) {
                this.UnreadDivider()
              }
              this.MessageRow(msg)
            }
            .width('100%')
          }
          .onVisibleAreaChange([0.0, 0.35], (isVisible: boolean, currentRatio: number) => {
            if (isVisible && currentRatio >= 0.35) {
              this.requestMessageItemMedia(msg);
            }
          })
        }, (msg: MessageItem): string => `${msg.id}`)
        ListItem() {
          Column()
            .height(76)
        }
      }
      .width('100%')
      .height('100%')
      .backgroundColor(Color.Transparent)
      .contentEndOffset(76)
      .scrollBar(BarState.Off)
      .onReachStart(() => {
        console.info(`[ChatPage] list reach start chatId=${this.chatId}`);
        this.loadOlderHistory();
      })

      Column() {
        this.TopFloatingArea()
      }
      .width('100%')
      .height(120)
      .position({ x: 0, y: 0 })

      Stack({ alignContent: Alignment.Bottom }) {
        Column() {
          this.BottomFloatingArea()
        }
        .width('100%')
        .height(96)
      }
      .width('100%')
      .height('100%')
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
          .padding({ right: 18, bottom: 110 })
        }
        .width('100%')
        .height('100%')
        .hitTestBehavior(HitTestMode.Transparent)
      }
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#97D394')
  }
}
