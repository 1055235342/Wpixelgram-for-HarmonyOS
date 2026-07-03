import { common } from '@kit.AbilityKit';
import notificationManager from '@ohos.notificationManager';

interface OperationError {
  code?: number;
  message?: string;
}

export class DownloadNotificationService {
  private static instance: DownloadNotificationService = new DownloadNotificationService();
  private initialized: boolean = false;
  private textPublishTimes: number[] = [];
  private progressPublishTimes: number[] = [];
  private progressPublishAtById: Map<number, number> = new Map();

  public static getInstance(): DownloadNotificationService {
    return DownloadNotificationService.instance;
  }

  public async ensureEnabled(context: common.UIAbilityContext): Promise<boolean> {
    try {
      const enabled = await notificationManager.isNotificationEnabled();
      if (!enabled) {
        await notificationManager.requestEnableNotification(context);
      }
      if (!this.initialized) {
        await notificationManager.addSlot(notificationManager.SlotType.SOCIAL_COMMUNICATION);
        this.initialized = true;
      }
      return true;
    } catch (err) {
      const error = err as OperationError;
      console.warn(`[DownloadNotificationService] notification unavailable code=${error.code}, message=${error.message}`);
      return false;
    }
  }

  public async publishProgress(context: common.UIAbilityContext, id: number, title: string, fileName: string,
    downloadedSize: number, expectedSize: number, completed: boolean): Promise<void> {
    if (!this.takeProgressPublishSlot(id, completed)) {
      return;
    }
    const enabled = await this.ensureEnabled(context);
    if (!enabled) {
      return;
    }
    const progress = this.getProgress(downloadedSize, expectedSize, completed);
    const text = completed ? '缓存完成' : `${this.formatBytes(downloadedSize)} / ${this.formatBytes(expectedSize)}`;
    try {
      await notificationManager.publish({
        id: id,
        appMessageId: `download-${id}`,
        notificationSlotType: notificationManager.SlotType.SOCIAL_COMMUNICATION,
        isOngoing: !completed,
        tapDismissed: completed,
        content: {
          notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
          normal: {
            title: title,
            text: text,
            additionalText: `${progress}%`
          }
        },
        template: {
          name: 'downloadTemplate',
          data: {
            title: title,
            fileName: fileName,
            progressValue: progress
          }
        }
      });
    } catch (err) {
      const error = err as OperationError;
      console.warn(`[DownloadNotificationService] publish failed id=${id}, code=${error.code}, message=${error.message}`);
    }
  }

  public async publishText(context: common.UIAbilityContext, id: number, title: string, text: string): Promise<void> {
    if (!this.takeTextPublishSlot()) {
      return;
    }
    const enabled = await this.ensureEnabled(context);
    if (!enabled) {
      return;
    }
    try {
      await notificationManager.publish({
        id: id,
        appMessageId: `message-${id}`,
        notificationSlotType: notificationManager.SlotType.SOCIAL_COMMUNICATION,
        tapDismissed: true,
        content: {
          notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
          normal: {
            title: this.truncate(title, 80),
            text: this.truncate(text, 180)
          }
        }
      });
    } catch (err) {
      const error = err as OperationError;
      console.warn(`[DownloadNotificationService] publish text failed id=${id}, code=${error.code}, message=${error.message}`);
    }
  }

  public async cancel(id: number): Promise<void> {
    try {
      await notificationManager.cancel(id);
    } catch (err) {
      const error = err as OperationError;
      console.warn(`[DownloadNotificationService] cancel failed id=${id}, code=${error.code}, message=${error.message}`);
    }
  }

  private getProgress(downloadedSize: number, expectedSize: number, completed: boolean): number {
    if (completed) {
      return 100;
    }
    if (expectedSize <= 0) {
      return downloadedSize > 0 ? 1 : 0;
    }
    return Math.min(99, Math.max(0, Math.floor(downloadedSize * 100 / expectedSize)));
  }

  private takeTextPublishSlot(): boolean {
    return this.takePublishSlot(this.textPublishTimes, 10);
  }

  private takeProgressPublishSlot(id: number, completed: boolean): boolean {
    const now = Date.now();
    const lastTime = this.progressPublishAtById.get(id);
    if (!completed && lastTime !== undefined && now - lastTime < 250) {
      return false;
    }
    if (!this.takePublishSlot(this.progressPublishTimes, 20)) {
      return false;
    }
    this.progressPublishAtById.set(id, now);
    return true;
  }

  private takePublishSlot(times: number[], limit: number): boolean {
    const now = Date.now();
    const start = now - 1000;
    while (times.length > 0 && times[0] < start) {
      times.shift();
    }
    if (times.length >= limit) {
      return false;
    }
    times.push(now);
    return true;
  }

  private truncate(value: string, maxLength: number): string {
    if (value.length <= maxLength) {
      return value;
    }
    return `${value.substring(0, Math.max(0, maxLength - 3))}...`;
  }

  private formatBytes(size: number): string {
    if (size <= 0) {
      return '0 KB';
    }
    if (size >= 1024 * 1024 * 1024) {
      return `${(size / 1024 / 1024 / 1024).toFixed(2)} GB`;
    }
    if (size >= 1024 * 1024) {
      return `${(size / 1024 / 1024).toFixed(1)} MB`;
    }
    return `${Math.max(1, Math.floor(size / 1024))} KB`;
  }
}
