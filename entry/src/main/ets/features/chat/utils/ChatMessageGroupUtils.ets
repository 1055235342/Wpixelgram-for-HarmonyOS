import { MessageGroupItem, MessageItem } from '../model/ChatDetailModels';

export class ChatMessageGroupUtils {
  public static sortMessages(items: MessageItem[]): MessageItem[] {
    return items.slice().sort((left: MessageItem, right: MessageItem): number => left.id - right.id);
  }

  public static getMessageGroupsFromItems(items: MessageItem[]): MessageGroupItem[] {
    const groups: MessageGroupItem[] = [];
    let index = 0;
    while (index < items.length) {
      const current = items[index];
      if (!ChatMessageGroupUtils.isAlbumMediaMessage(current)) {
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
      while (nextIndex < items.length) {
        const next = items[nextIndex];
        if (ChatMessageGroupUtils.isAlbumMediaMessage(next) && next.mediaAlbumId === current.mediaAlbumId &&
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

  public static getDisplayIndexForMessageId(groups: MessageGroupItem[], messageId: number): number {
    return groups.findIndex((group: MessageGroupItem): boolean => {
      return ChatMessageGroupUtils.groupContainsMessage(group, messageId);
    });
  }

  public static groupContainsMessage(group: MessageGroupItem, messageId: number): boolean {
    return group.items.some((message: MessageItem): boolean => message.id === messageId);
  }

  public static getAlbumRows(items: MessageItem[]): MessageItem[][] {
    const rows: MessageItem[][] = [];
    const visibleItems = ChatMessageGroupUtils.getAlbumVisibleItems(items);
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

  public static getAlbumVisibleItems(items: MessageItem[]): MessageItem[] {
    return items.slice(0, 9);
  }

  public static albumHasTarget(group: MessageGroupItem): boolean {
    return group.items.some((message: MessageItem): boolean => message.isTarget);
  }

  public static getDownloadPercentBucket(downloadedSize: number, expectedSize: number): number {
    if (expectedSize <= 0) {
      return 0;
    }
    const percent = Math.min(100, Math.max(0, Math.floor(downloadedSize * 100 / expectedSize)));
    if (percent >= 100) {
      return 100;
    }
    return Math.floor(percent / 5) * 5;
  }

  private static isAlbumMediaMessage(message: MessageItem): boolean {
    return message.mediaAlbumId > 0 &&
      (message.mediaType === 'messagePhoto' || message.mediaType === 'messageVideo' ||
        message.mediaType === 'messageAnimation');
  }
}
