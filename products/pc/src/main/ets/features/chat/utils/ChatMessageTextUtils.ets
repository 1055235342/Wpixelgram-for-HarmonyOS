import { FormattedText, TdTextEntity } from '../../../common/service/TdlibService';
import { ChatRouteParams, MessageTextRow, MessageTextSegment } from '../model/ChatDetailModels';

export class ChatMessageTextUtils {
  public static getRows(formattedText: FormattedText | undefined): MessageTextRow[] {
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
            url: ChatMessageTextUtils.findLineUrl(formattedText, start, index, line),
            segments: ChatMessageTextUtils.getSegments(line)
          });
          rowIndex++;
        }
        start = index + 1;
      }
    }
    return rows;
  }

  public static getSegments(text: string): MessageTextSegment[] {
    const segments: MessageTextSegment[] = [];
    let start = 0;
    let segmentIndex = 0;
    for (let index = 0; index < text.length; index++) {
      if (text.charAt(index) !== '#' || !ChatMessageTextUtils.isHashtagStart(text, index)) {
        continue;
      }
      const end = ChatMessageTextUtils.findHashtagEnd(text, index + 1);
      if (end <= index + 1) {
        continue;
      }
      if (index > start) {
        segments.push({
          id: `seg-${segmentIndex++}`,
          text: text.substring(start, index),
          type: 'text'
        });
      }
      segments.push({
        id: `seg-${segmentIndex++}`,
        text: text.substring(index, end),
        type: 'hashtag'
      });
      start = end;
      index = end - 1;
    }
    if (start < text.length) {
      segments.push({
        id: `seg-${segmentIndex++}`,
        text: text.substring(start),
        type: 'text'
      });
    }
    if (segments.length === 0 && text.length > 0) {
      segments.push({
        id: 'seg-0',
        text: text,
        type: 'text'
      });
    }
    return segments;
  }

  public static findUrlInText(text: string): string {
    const parts: string[] = text.split(/\s+/);
    for (let index = 0; index < parts.length; index++) {
      const part = ChatMessageTextUtils.trimUrlToken(parts[index].trim());
      if (part.startsWith('http://') || part.startsWith('https://') || part.startsWith('tg://') ||
        part.startsWith('t.me/') || part.startsWith('telegram.me/')) {
        return part;
      }
    }
    return '';
  }

  public static trimUrlToken(token: string): string {
    let value = token;
    while (value.length > 0 && ChatMessageTextUtils.isUrlLeadingTrimChar(value.charAt(0))) {
      value = value.substring(1);
    }
    while (value.length > 0 && ChatMessageTextUtils.isUrlTrailingTrimChar(value.charAt(value.length - 1))) {
      value = value.substring(0, value.length - 1);
    }
    return value;
  }

  public static extractBotCommandFromText(text: string): string {
    const parts: string[] = text.split(/\s+/);
    for (let index = 0; index < parts.length; index++) {
      const part = ChatMessageTextUtils.trimUrlToken(parts[index].trim());
      if (part.startsWith('/') && part.length > 1) {
        return part;
      }
    }
    return '';
  }

  public static normalizeUrl(url: string): string {
    const value = url.trim();
    if (value.length === 0) {
      return '';
    }
    if (value.startsWith('http://') || value.startsWith('https://') || value.startsWith('tg://')) {
      return value;
    }
    return `https://${value}`;
  }

  public static isTelegramMessageUrl(url: string): boolean {
    return url.startsWith('tg://') ||
      url.startsWith('https://t.me/') ||
      url.startsWith('http://t.me/') ||
      url.startsWith('https://telegram.me/') ||
      url.startsWith('http://telegram.me/');
  }

  public static parseTMeMessageUrl(url: string): ChatRouteParams {
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
        const messageId = Number(ChatMessageTextUtils.trimUrlToken(parts[1].split('?')[0]));
        if (!Number.isNaN(internalChatId) && !Number.isNaN(messageId)) {
          result.chatId = Number(`-100${internalChatId}`);
          result.messageId = messageId;
        }
      }
      return result;
    }

    if (url.startsWith('tg://privatepost')) {
      const channel = ChatMessageTextUtils.getQueryNumber(url, 'channel');
      const post = ChatMessageTextUtils.getQueryNumber(url, 'post');
      if (channel !== 0 && post !== 0) {
        result.chatId = Number(`-100${channel}`);
        result.messageId = post;
      }
      return result;
    }

    return result;
  }

  private static findLineUrl(formattedText: FormattedText, lineStart: number, lineEnd: number, line: string): string {
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
    return ChatMessageTextUtils.findUrlInText(line);
  }

  private static isHashtagStart(text: string, index: number): boolean {
    if (index > 0 && ChatMessageTextUtils.isHashtagChar(text.charAt(index - 1))) {
      return false;
    }
    return index + 1 < text.length && ChatMessageTextUtils.isHashtagChar(text.charAt(index + 1));
  }

  private static findHashtagEnd(text: string, start: number): number {
    let index = start;
    while (index < text.length && ChatMessageTextUtils.isHashtagChar(text.charAt(index))) {
      index++;
    }
    return index;
  }

  private static isHashtagChar(char: string): boolean {
    return /[A-Za-z0-9_\-\u4E00-\u9FFF]/.test(char);
  }

  private static isUrlLeadingTrimChar(char: string): boolean {
    return char === '(' || char === '[' || char === '{' || char === '「' || char === '《' || char === '<';
  }

  private static isUrlTrailingTrimChar(char: string): boolean {
    return char === ')' || char === ']' || char === '}' || char === '」' || char === '》' ||
      char === '>' || char === ',' || char === '.' || char === ';' || char === ':' ||
      char === '，' || char === '。' || char === '；' || char === '：';
  }

  private static getQueryNumber(url: string, key: string): number {
    const marker = `${key}=`;
    const markerIndex = url.indexOf(marker);
    if (markerIndex < 0) {
      return 0;
    }
    const tail = url.substring(markerIndex + marker.length);
    const value = ChatMessageTextUtils.trimUrlToken(tail.split('&')[0]);
    const numberValue = Number(value);
    return Number.isNaN(numberValue) ? 0 : numberValue;
  }
}
