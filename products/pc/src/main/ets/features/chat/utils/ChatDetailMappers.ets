import { TdChat } from '../../../common/service/TdlibService';

export function isBotTitle(title: string): boolean {
  const lower = title.toLowerCase();
  return lower.indexOf('bot') >= 0 || title.indexOf('机器人') >= 0;
}

export function getChatCategory(chat: TdChat): string {
  if (!chat.type) {
    return isBotTitle(chat.title) ? '机器人' : '个人';
  }
  if ((chat.type.type === 'chatTypePrivate' || chat.type.type === 'chatTypeSecret') && isBotTitle(chat.title)) {
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

export function getChatSubtitle(category: string): string {
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

export function getCurrentChatCategory(isChannelChat: boolean, chatSubtitle: string): string {
  if (isChannelChat) {
    return '频道';
  }
  if (chatSubtitle === '机器人') {
    return '机器人';
  }
  if (chatSubtitle === '群组会话') {
    return '群组';
  }
  return '个人';
}
