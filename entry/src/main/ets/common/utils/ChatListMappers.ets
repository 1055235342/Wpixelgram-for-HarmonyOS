import { TdChat, TdChatPosition, TdChatType, TdFile, TdMessage, TdMessageContent } from '../service/TdlibService';
import { ChatItem } from '../model/ChatListModels';

const AVATAR_COLORS: string[] = ['#2F80ED', '#27AE60', '#F2994A', '#9B51E0', '#00A3A3', '#EB5757', '#1D9BF0'];

export function createLoadingChat(id: number): ChatItem {
  const title = `Chat ${id}`;
  return {
    id: id,
    title: title,
    lastMessage: '加载中...',
    timeText: '',
    unreadCount: 0,
    lastReadInboxMessageId: 0,
    isOutgoing: false,
    isRead: false,
    isPinned: false,
    category: '全部',
    avatarText: getAvatarText(title),
    avatarColor: getAvatarColor(id),
    avatarPath: '',
    avatarFileId: 0
  };
}

export function createChatItem(chat: TdChat): ChatItem {
  const title = chat.title.length > 0 ? chat.title : `Chat ${chat.id}`;
  return {
    id: chat.id,
    title: title,
    lastMessage: getMessagePreview(chat.last_message),
    timeText: getMessageTime(chat.last_message),
    unreadCount: chat.unread_count ? chat.unread_count : 0,
    lastReadInboxMessageId: chat.last_read_inbox_message_id ? chat.last_read_inbox_message_id : 0,
    isOutgoing: chat.last_message ? chat.last_message.is_outgoing : false,
    isRead: isOutgoingRead(chat),
    isPinned: isPinnedByPositions(chat.positions),
    category: getChatCategory(chat.type, title),
    avatarText: getAvatarText(title),
    avatarColor: getAvatarColor(chat.id),
    avatarPath: getChatAvatarPath(chat),
    avatarFileId: getChatAvatarFileId(chat)
  };
}

export function getChatAvatarFileId(chat: TdChat): number {
  if (chat.photo && chat.photo.small) {
    return chat.photo.small.id;
  }
  return 0;
}

export function getChatAvatarPath(chat: TdChat): string {
  if (chat.photo && chat.photo.small && chat.photo.small.local && chat.photo.small.local.path.length > 0) {
    return toFileSource(chat.photo.small.local.path);
  }
  return '';
}

export function getLocalPath(file: TdFile): string {
  if (file.local && file.local.path.length > 0) {
    return toFileSource(file.local.path);
  }
  return '';
}

export function getMessagePreview(message: TdMessage | undefined): string {
  if (!message || !message.content) {
    return '';
  }
  const content: TdMessageContent = message.content;
  const caption = content.caption && content.caption.text.length > 0 ? content.caption.text : '';
  if (content.type === 'messageText' && content.text) {
    return content.text.text;
  }
  if (content.type === 'messagePhoto') {
    return caption.length > 0 ? caption : '[图片]';
  }
  if (content.type === 'messageVideo') {
    return caption.length > 0 ? caption : '[视频]';
  }
  if (content.type === 'messageAnimation') {
    return caption.length > 0 ? caption : 'GIF';
  }
  if (content.type === 'messageSticker') {
    return '[贴纸]';
  }
  if (content.type === 'messageDocument') {
    return caption.length > 0 ? caption : '[文件]';
  }
  if (content.type === 'messageVoiceNote') {
    return '[语音]';
  }
  return `[${content.type}]`;
}

export function getMessageTime(message: TdMessage | undefined): string {
  if (!message || !message.date) {
    return '';
  }
  const date = new Date(message.date * 1000);
  const hour = pad2(date.getHours());
  const minute = pad2(date.getMinutes());
  return `${hour}:${minute}`;
}

export function getChatCategory(type: TdChatType | undefined, title: string): string {
  if (!type) {
    return isBotTitle(title) ? '机器人' : '个人';
  }
  if (type.type === 'chatTypePrivate' || type.type === 'chatTypeSecret') {
    return isBotTitle(title) ? '机器人' : '个人';
  }
  if (type.type === 'chatTypeSupergroup' && type.is_channel) {
    return '频道';
  }
  if (type.type === 'chatTypeBasicGroup' || type.type === 'chatTypeSupergroup') {
    return '群组';
  }
  return '全部';
}

export function isOutgoingRead(chat: TdChat): boolean {
  if (!chat.last_message || !chat.last_message.is_outgoing || chat.last_read_outbox_message_id === undefined) {
    return false;
  }
  return chat.last_read_outbox_message_id >= chat.last_message.id;
}

export function isPinnedByPositions(positions: TdChatPosition[] | undefined): boolean {
  if (!positions) {
    return false;
  }
  return positions.some((position: TdChatPosition): boolean => {
    return isMainListPosition(position) && position.is_pinned === true;
  });
}

export function isPinnedByPosition(position: TdChatPosition | undefined): boolean {
  if (!position) {
    return false;
  }
  return isMainListPosition(position) && position.is_pinned === true;
}

export function isMainChatPosition(position: TdChatPosition | undefined): boolean {
  if (!position) {
    return false;
  }
  return isMainListPosition(position);
}

export function getAvatarText(title: string): string {
  const trimmed = title.trim();
  if (trimmed.length === 0) {
    return '?';
  }
  return trimmed.substring(0, 1).toUpperCase();
}

export function getAvatarColor(id: number): string {
  const index = Math.abs(id) % AVATAR_COLORS.length;
  return AVATAR_COLORS[index];
}

function toFileSource(path: string): string {
  if (path.startsWith('file://')) {
    return path;
  }
  return `file://${path}`;
}

function pad2(value: number): string {
  return value < 10 ? `0${value}` : `${value}`;
}

function isMainListPosition(position: TdChatPosition): boolean {
  if (!position.list) {
    return true;
  }
  const listType = position.list.type;
  return listType === undefined || listType === 'chatListMain';
}

function isBotTitle(title: string): boolean {
  return title.toLowerCase().indexOf('bot') >= 0 || title.indexOf('机器人') >= 0;
}
