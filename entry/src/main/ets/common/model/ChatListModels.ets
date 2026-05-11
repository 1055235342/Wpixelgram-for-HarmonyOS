export interface ChatItem {
  id: number;
  title: string;
  lastMessage: string;
  timeText: string;
  unreadCount: number;
  lastReadInboxMessageId: number;
  isOutgoing: boolean;
  isRead: boolean;
  isPinned: boolean;
  category: string;
  avatarText: string;
  avatarColor: string;
  avatarPath: string;
  avatarFileId: number;
}

export interface ChatSelection {
  chatId: number;
  title: string;
  avatarPath: string;
  avatarFileId: number;
  category: string;
  unreadCount: number;
  lastReadInboxMessageId: number;
}
