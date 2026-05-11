// entry/src/main/ets/common/service/TdlibService.ets
import { createNativeClient, sendNativeRequest, receiveNativeUpdate } from 'libtdlib_bridge.so';

interface TdBaseRequest {
  '@type': string;
}

export interface TdTypeObject {
  type?: string;
}

export interface TdlibParameters {
  use_test_dc: boolean;
  database_directory: string;
  files_directory: string;
  database_encryption_key: string;
  use_file_database: boolean;
  use_chat_info_database: boolean;
  use_message_database: boolean;
  use_secret_chats: boolean;
  api_id: number;
  api_hash: string;
  system_language_code: string;
  device_model: string;
  system_version: string;
  application_version: string;
}

interface SetTdlibParametersRequest extends TdBaseRequest, TdlibParameters {}

interface PhoneNumberRequest extends TdBaseRequest {
  phone_number: string;
}

interface AuthenticationCodeRequest extends TdBaseRequest {
  code: string;
}

interface ChatListRequest extends TdBaseRequest {}

interface GetChatsRequest extends TdBaseRequest {
  chat_list: ChatListRequest;
  limit: number;
}

interface LoadChatsRequest extends TdBaseRequest {
  chat_list: ChatListRequest;
  limit: number;
}

interface GetChatRequest extends TdBaseRequest {
  chat_id: number;
}

interface GetChatHistoryRequest extends TdBaseRequest {
  chat_id: number;
  from_message_id: number;
  offset: number;
  limit: number;
}

export interface TdTextEntityType {
  type: string;
  url?: string;
  user_id?: number;
}

export interface TdTextEntity {
  offset: number;
  length: number;
  type: TdTextEntityType;
}

export interface FormattedText extends TdBaseRequest {
  text: string;
  entities?: TdTextEntity[];
}

interface InputMessageText extends TdBaseRequest {
  text: FormattedText;
}

interface SendMessageRequest extends TdBaseRequest {
  chat_id: number;
  input_message_content: InputMessageText;
}

interface FileType extends TdBaseRequest {}

interface OptimizeStorageRequest extends TdBaseRequest {
  size: number;
  ttl: number;
  count: number;
  immunity_delay: number;
  file_types: FileType[];
  chat_ids: number[];
  exclude_chat_ids: number[];
  return_deleted_file_statistics: boolean;
  chat_limit: number;
}

interface GetInstalledStickerSetsRequest extends TdBaseRequest {
  is_masks: boolean;
}

interface SearchChatsOnServerRequest extends TdBaseRequest {
  query: string;
  limit: number;
}

interface SearchMessagesRequest extends TdBaseRequest {
  chat_list: ChatListRequest;
  query: string;
  offset: string;
  limit: number;
  filter: TdBaseRequest | null;
  chat_type_filter: TdBaseRequest | null;
  min_date: number;
  max_date: number;
}

interface DownloadFileRequest extends TdBaseRequest {
  file_id: number;
  priority: number;
  offset: number;
  limit: number;
  synchronous: boolean;
}

interface OpenMessageContentRequest extends TdBaseRequest {
  chat_id: number;
  message_id: number;
}

interface MessageSourceRequest extends TdBaseRequest {}

interface ViewMessagesRequest extends TdBaseRequest {
  chat_id: number;
  message_ids: number[];
  source: MessageSourceRequest;
  force_read: boolean;
}

interface GetMessageLinkInfoRequest extends TdBaseRequest {
  url: string;
}

export interface TdCallbackQueryPayload extends TdBaseRequest {
  data?: string;
  password?: string;
  game_short_name?: string;
}

interface GetCallbackQueryAnswerRequest extends TdBaseRequest {
  chat_id: number;
  message_id: number;
  payload: TdCallbackQueryPayload;
}

type TdRequest = TdBaseRequest | SetTdlibParametersRequest | PhoneNumberRequest |
  AuthenticationCodeRequest | GetChatsRequest | LoadChatsRequest | GetChatRequest | GetChatHistoryRequest |
  SendMessageRequest | OptimizeStorageRequest | GetInstalledStickerSetsRequest |
  SearchChatsOnServerRequest | SearchMessagesRequest | DownloadFileRequest |
  OpenMessageContentRequest | ViewMessagesRequest | GetMessageLinkInfoRequest | GetCallbackQueryAnswerRequest;

export interface TdLocalFile {
  path: string;
  can_be_downloaded?: boolean;
  is_downloading_active?: boolean;
  is_downloading_completed?: boolean;
  downloaded_prefix_size?: number;
  downloaded_size?: number;
}

export interface TdRemoteFile {
  id: string;
  unique_id?: string;
}

export interface TdFile {
  id: number;
  size?: number;
  expected_size?: number;
  local?: TdLocalFile;
  remote?: TdRemoteFile;
}

export interface TdPhotoSize {
  type: string;
  photo: TdFile;
  width: number;
  height: number;
}

export interface TdPhoto {
  sizes: TdPhotoSize[];
}

export interface TdThumbnail {
  file?: TdFile;
  width?: number;
  height?: number;
}

export interface TdVideo {
  duration?: number;
  width?: number;
  height?: number;
  file_name?: string;
  mime_type?: string;
  supports_streaming?: boolean;
  thumbnail?: TdThumbnail;
  video: TdFile;
}

export interface TdAnimation {
  duration?: number;
  width?: number;
  height?: number;
  file_name?: string;
  mime_type?: string;
  thumbnail?: TdThumbnail;
  animation: TdFile;
}

export interface TdMessageContent {
  type: string;
  text?: FormattedText;
  photo?: TdPhoto;
  video?: TdVideo;
  animation?: TdAnimation;
  caption?: FormattedText;
}

export interface TdInlineKeyboardButtonType {
  type: string;
  url?: string;
  id?: number;
  data?: string;
  query?: string;
  user_id?: number;
  text?: string;
}

export interface TdInlineKeyboardButton {
  text: string;
  type: TdInlineKeyboardButtonType;
}

export interface TdReplyMarkup {
  type: string;
  rows?: TdInlineKeyboardButton[][];
}

export interface TdTextQuote {
  text?: FormattedText;
  position?: number;
  is_manual?: boolean;
}

export interface TdMessageReplyTo {
  type: string;
  chat_id?: number;
  message_id?: number;
  quote?: TdTextQuote;
}

export interface TdMessage {
  id: number;
  chat_id?: number;
  is_outgoing: boolean;
  date?: number;
  content?: TdMessageContent;
  reply_markup?: TdReplyMarkup;
  reply_to?: TdMessageReplyTo;
}

export interface TdChatType {
  type: string;
  is_channel?: boolean;
}

export interface TdChatPosition {
  list?: TdTypeObject;
  order?: string;
  is_pinned?: boolean;
}

export interface TdChatPhotoInfo {
  small?: TdFile;
  big?: TdFile;
  minithumbnail?: TdBaseRequest;
  has_animation?: boolean;
  is_personal?: boolean;
}

export interface TdChat {
  id: number;
  title: string;
  type?: TdChatType;
  photo?: TdChatPhotoInfo;
  last_message?: TdMessage;
  unread_count?: number;
  is_marked_as_unread?: boolean;
  last_read_inbox_message_id?: number;
  last_read_outbox_message_id?: number;
  positions?: TdChatPosition[];
}

export interface TdUser {
  first_name: string;
  last_name?: string;
  phone_number: string;
}

export interface TdStorageStatistic {
  size: number;
}

export interface TdAuthorizationState {
  type: string;
}

export interface TdUpdate {
  type: string;
  authorization_state?: TdAuthorizationState;
  total_count?: number;
  chat_ids?: number[];
  chat?: TdChat;
  chat_id?: number;
  unread_count?: number;
  is_marked_as_unread?: boolean;
  last_read_inbox_message_id?: number;
  last_read_outbox_message_id?: number;
  positions?: TdChatPosition[];
  position?: TdChatPosition;
  chat_type?: TdChatType;
  photo?: TdChatPhotoInfo;
  title?: string;
  id?: number;
  last_message?: TdMessage;
  user_ids?: number[];
  messages?: TdMessage[];
  message?: TdMessage;
  next_offset?: string;
  next_from_message_id?: number;
  message_id?: number;
  media_timestamp?: number;
  new_content?: TdMessageContent;
  reply_markup?: TdReplyMarkup;
  reply_markup_message?: TdMessage;
  file?: TdFile;
  url?: string;
  text?: string;
  show_alert?: boolean;
  user?: TdUser;
  statistics?: TdStorageStatistic[];
}

type UpdateListener = (update: TdUpdate) => void;

export class TdlibService {
  private static instance: TdlibService;
  private clientId: number;
  private isPolling: boolean = false;
  private listeners: Map<string, UpdateListener[]> = new Map();

  public static getInstance(): TdlibService {
    if (!TdlibService.instance) {
      TdlibService.instance = new TdlibService();
    }
    return TdlibService.instance;
  }

  private constructor() {
    console.info('[TdlibService] create native client');
    this.clientId = createNativeClient();
    console.info(`[TdlibService] native client id=${this.clientId}`);
    if (this.clientId < 0) {
      console.error('TdlibService: 创建客户端失败');
    }
  }

  public sendRequest(request: TdRequest): void {
    const requestJson = JSON.stringify(request);
    console.info(`[TdlibService] request clientId=${this.clientId} params=${requestJson}`);
    sendNativeRequest(this.clientId, requestJson);
  }

  public startPolling(interval: number = 0.1): void {
    if (this.isPolling) return;
    this.isPolling = true;
    console.info(`[TdlibService] start polling interval=${interval}`);
    setInterval(() => {
      for (let index = 0; index < 20; index++) {
        const resp: string | null | undefined = receiveNativeUpdate(this.clientId, 0.02);
        if (resp === null || resp === undefined || resp.length === 0) {
          break;
        }
        console.info(`[TdlibService] response raw=${resp}`);
        try {
          const update = JSON.parse(this.normalizeResponse(resp)) as TdUpdate;
          this.dispatchUpdate(update.type, update);
          if (update.type === 'updateAuthorizationState' && update.authorization_state) {
            this.dispatchUpdate(update.authorization_state.type, update);
          }
        } catch (e) {
          console.error(`[TdlibService] parse response failed=${JSON.stringify(e)}`);
        }
      }
    }, interval * 1000);
  }

  private normalizeResponse(resp: string): string {
    if (resp.startsWith('{"@type":"chat"')) {
      return resp
        .replace('"@type":"chat"', '"type":"chat"')
        .replace(',"type":{', ',"chat_type":{')
        .replace(/"@type"/g, '"type"');
    }
    return resp.replace(/"@type"/g, '"type"');
  }

  private dispatchUpdate(type: string, update: TdUpdate): void {
    const callbacks = this.listeners.get(type);
    const count = callbacks ? callbacks.length : 0;
    console.info(`[TdlibService] dispatch update type=${type} listeners=${count}`);
    if (!callbacks) {
      return;
    }
    callbacks.forEach((cb: UpdateListener) => {
      try {
        cb(update);
      } catch (e) {
        console.error(`[TdlibService] listener error type=${type}, error=${JSON.stringify(e)}`);
      }
    });
  }

  public onUpdate(type: string, callback: UpdateListener): void {
    if (!this.listeners.has(type)) this.listeners.set(type, []);
    this.listeners.get(type)!.push(callback);
    console.info(`[TdlibService] register listener type=${type}`);
  }

  public offUpdate(type: string, callback: UpdateListener): void {
    const cbs = this.listeners.get(type);
    if (cbs) {
      const idx = cbs.indexOf(callback);
      if (idx > -1) cbs.splice(idx, 1);
    }
  }

  // ============ 常用 API 封装 ============
  public setTdlibParameters(params: TdlibParameters): void {
    const request: SetTdlibParametersRequest = {
      '@type': 'setTdlibParameters',
      use_test_dc: params.use_test_dc,
      database_directory: params.database_directory,
      files_directory: params.files_directory,
      database_encryption_key: params.database_encryption_key,
      use_file_database: params.use_file_database,
      use_chat_info_database: params.use_chat_info_database,
      use_message_database: params.use_message_database,
      use_secret_chats: params.use_secret_chats,
      api_id: params.api_id,
      api_hash: params.api_hash,
      system_language_code: params.system_language_code,
      device_model: params.device_model,
      system_version: params.system_version,
      application_version: params.application_version
    };
    this.sendRequest(request);
  }
  public setAuthenticationPhoneNumber(phone: string): void {
    this.sendRequest({ '@type': 'setAuthenticationPhoneNumber', phone_number: phone });
  }
  public checkAuthenticationCode(code: string): void {
    this.sendRequest({ '@type': 'checkAuthenticationCode', code: code });
  }
  public getChats(limit: number = 20): void {
    this.sendRequest({ '@type': 'getChats', chat_list: { '@type': 'chatListMain' }, limit: limit });
  }
  public loadChats(limit: number = 20): void {
    this.sendRequest({ '@type': 'loadChats', chat_list: { '@type': 'chatListMain' }, limit: limit });
  }
  public getChat(chatId: number): void {
    this.sendRequest({ '@type': 'getChat', chat_id: chatId });
  }
  public getChatHistory(chatId: number, limit: number = 20, fromMessageId: number = 0, offset: number = 0): void {
    this.sendRequest({
      '@type': 'getChatHistory',
      chat_id: chatId,
      from_message_id: fromMessageId,
      offset: offset,
      limit: limit
    });
  }
  public sendMessage(chatId: number, text: string): void {
    this.sendRequest({
      '@type': 'sendMessage',
      chat_id: chatId,
      input_message_content: {
        '@type': 'inputMessageText',
        text: { '@type': 'formattedText', text: text }
      }
    });
  }
  public getContacts(): void {
    this.sendRequest({ '@type': 'getContacts' });
  }
  public getMe(): void {
    this.sendRequest({ '@type': 'getMe' });
  }
  public optimizeStorage(fileTypes: string[], size: number = 0, ttl: number = 30*24*3600): void {
    const types: FileType[] = fileTypes.map((t: string): FileType => {
      return { '@type': t };
    });
    this.sendRequest({
      '@type': 'optimizeStorage',
      size: size,
      ttl: ttl,
      count: -1,
      immunity_delay: -1,
      file_types: types,
      chat_ids: [],
      exclude_chat_ids: [],
      return_deleted_file_statistics: true,
      chat_limit: 0
    });
  }
  public getInstalledStickerSets(): void {
    this.sendRequest({ '@type': 'getInstalledStickerSets', is_masks: false });
  }
  public searchChatsOnServer(query: string, limit: number = 20): void {
    this.sendRequest({ '@type': 'searchChatsOnServer', query: query, limit: limit });
  }
  public searchMessages(query: string, offset: string = '', limit: number = 30): void {
    this.sendRequest({
      '@type': 'searchMessages',
      chat_list: { '@type': 'chatListMain' },
      query: query,
      offset: offset,
      limit: limit,
      filter: null,
      chat_type_filter: null,
      min_date: 0,
      max_date: 0
    });
  }
  public downloadFile(fileId: number, priority: number = 16, offset: number = 0, limit: number = 0): void {
    this.sendRequest({
      '@type': 'downloadFile',
      file_id: fileId,
      priority: priority,
      offset: offset,
      limit: limit,
      synchronous: false
    });
  }
  public openMessageContent(chatId: number, messageId: number): void {
    this.sendRequest({ '@type': 'openMessageContent', chat_id: chatId, message_id: messageId });
  }
  public viewMessages(chatId: number, messageIds: number[], forceRead: boolean = true): void {
    if (messageIds.length === 0) {
      return;
    }
    this.sendRequest({
      '@type': 'viewMessages',
      chat_id: chatId,
      message_ids: messageIds,
      source: { '@type': 'messageSourceChatHistory' },
      force_read: forceRead
    });
  }
  public getMessageLinkInfo(url: string): void {
    this.sendRequest({ '@type': 'getMessageLinkInfo', url: url });
  }
  public getCallbackQueryAnswer(chatId: number, messageId: number, data: string): void {
    this.sendRequest({
      '@type': 'getCallbackQueryAnswer',
      chat_id: chatId,
      message_id: messageId,
      payload: { '@type': 'callbackQueryPayloadData', data: data }
    });
  }
  public logOut(): void {
    this.sendRequest({ '@type': 'logOut' });
  }
}
