export interface ChatRouteParams {
  chatId?: number | string;
  messageId?: number | string;
  title?: string;
  avatarPath?: string;
  avatarFileId?: number | string;
  category?: string;
  unreadCount?: number | string;
  lastReadInboxMessageId?: number | string;
  commentMode?: boolean | string;
  sourceChatId?: number | string;
  sourceMessageId?: number | string;
  sourceMessageJson?: string;
  commentCount?: number | string;
}

export interface VideoRouteParams {
  chatId: number;
  messageId: number;
  fileId: number;
  mediaItemsJson?: string;
  mediaIndex?: number;
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

export interface MediaPreviewItem {
  id: string;
  type: string;
  messageId: number;
  fileId: number;
  displayPath: string;
  previewPath: string;
  title: string;
  subtitle: string;
  description: string;
  fileSize: number;
  downloadedSize: number;
  duration: number;
  mediaWidth: number;
  mediaHeight: number;
}

export interface MessageItem {
  id: number;
  mediaAlbumId: number;
  isSelf: boolean;
  isTarget: boolean;
  senderAvatarKey: string;
  senderAvatarLabel: string;
  mediaType: string;
  mediaFormat: string;
  text: string;
  textRows: MessageTextRow[];
  replyText: string;
  replyMessageId: number;
  buttonRows: MessageButtonItem[][];
  photoPath: string;
  originalPhotoPath: string;
  videoPath: string;
  thumbnailPath: string;
  photoFileId: number;
  originalPhotoFileId: number;
  photoDownloadedSize: number;
  photoExpectedSize: number;
  originalPhotoDownloadedSize: number;
  originalPhotoExpectedSize: number;
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
  commentCount: number;
  commentAvatars: string[];
  commentAvatarKeys: string[];
  commentThreadMessageId: number;
  mediaVersion: number;
}

export interface PhotoMediaState {
  fileId: number;
  path: string;
  downloadedSize: number;
  expectedSize: number;
  isReady: boolean;
}

export interface MessageGroupItem {
  id: string;
  anchorId: number;
  isAlbum: boolean;
  items: MessageItem[];
}

export interface MessageTextRow {
  id: string;
  text: string;
  url: string;
  segments: MessageTextSegment[];
}

export interface MessageTextSegment {
  id: string;
  text: string;
  type: string;
}

export interface MessageButtonItem {
  id: string;
  text: string;
  type: string;
  url: string;
  data: string;
}

export interface InlineVideoTimeItem {
  id: number;
  remaining: number;
}

export interface BotMenuCommandItem {
  id: string;
  command: string;
  description: string;
}

export interface ReplyKeyboardButtonItem {
  id: string;
  text: string;
}

export interface StartAbilityError {
  code?: number;
  message?: string;
}

export interface OperationError {
  code?: number;
  message?: string;
}

export function createEmptyMessageItem(): MessageItem {
  return {
    id: 0,
    mediaAlbumId: 0,
    isSelf: false,
    isTarget: false,
    senderAvatarKey: '',
    senderAvatarLabel: '',
    mediaType: '',
    mediaFormat: '',
    text: '',
    textRows: [],
    replyText: '',
    replyMessageId: 0,
    buttonRows: [],
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
    dateText: '',
    viewCount: 0,
    commentCount: 0,
    commentAvatars: [],
    commentAvatarKeys: [],
    commentThreadMessageId: 0,
    mediaVersion: 0
  };
}
