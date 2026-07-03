import { AbilityConstant, ConfigurationConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';
import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';
import { ChatDownloadCacheController } from '../features/chat/viewmodel/ChatDownloadCacheController';

const DOMAIN = 0x0000;

interface BackgroundTaskError {
  code?: number;
  message?: string;
}

export default class EntryAbility extends UIAbility {
  private downloadSuspendRequestId: number = 0;

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    try {
      this.context.getApplicationContext().setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_NOT_SET);
    } catch (err) {
      hilog.error(DOMAIN, 'testTag', 'Failed to set colorMode. Cause: %{public}s', JSON.stringify(err));
    }
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onCreate');
  }

  onDestroy(): void {
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Main window is created, set main page for this ability
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onWindowStageCreate');
    windowStage.getMainWindow((windowErr, mainWindow) => {
      if (windowErr.code) {
        hilog.error(DOMAIN, 'testTag', 'Failed to get main window. Cause: %{public}s', JSON.stringify(windowErr));
        return;
      }
      try {
        mainWindow.setWindowLayoutFullScreen(true);
      } catch (err) {
        hilog.error(DOMAIN, 'testTag', 'Failed to set immersive window. Cause: %{public}s', JSON.stringify(err));
      }
    });

    this.loadStartupPage(windowStage, 'product/pages/LoginPage');
  }

  private loadStartupPage(windowStage: window.WindowStage, page: string): void {
    windowStage.loadContent(page, (err) => {
      if (err.code) {
        hilog.error(DOMAIN, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        return;
      }
      hilog.info(DOMAIN, 'testTag', 'Succeeded in loading %{public}s.', page);
    });
  }

  onWindowStageDestroy(): void {
    // Main window is destroyed, release UI related resources
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onWindowStageDestroy');
  }

  onForeground(): void {
    // Ability has brought to foreground
    this.cancelDownloadSuspendDelay();
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onBackground(): void {
    // Ability has back to background
    this.keepDownloadsRunningInBackground();
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onBackground');
  }

  private keepDownloadsRunningInBackground(): void {
    const controller = ChatDownloadCacheController.getInstance();
    controller.setContext(this.context);
    if (!controller.hasActiveDownloads()) {
      return;
    }
    controller.keepActiveDownloadsRunning();
    try {
      const info = backgroundTaskManager.requestSuspendDelay('chat download cache', () => {
        this.downloadSuspendRequestId = 0;
      });
      this.downloadSuspendRequestId = info.requestId;
      hilog.info(DOMAIN, 'testTag', 'Download suspend delay requested id=%{public}d', this.downloadSuspendRequestId);
    } catch (err) {
      const error = err as BackgroundTaskError;
      hilog.error(DOMAIN, 'testTag', 'Download suspend delay failed code=%{public}d message=%{public}s',
        error.code === undefined ? 0 : error.code, error.message === undefined ? '' : error.message);
    }
  }

  private cancelDownloadSuspendDelay(): void {
    if (this.downloadSuspendRequestId === 0) {
      return;
    }
    try {
      backgroundTaskManager.cancelSuspendDelay(this.downloadSuspendRequestId);
    } catch (err) {
      const error = err as BackgroundTaskError;
      hilog.warn(DOMAIN, 'testTag', 'Cancel download suspend delay failed code=%{public}d message=%{public}s',
        error.code === undefined ? 0 : error.code, error.message === undefined ? '' : error.message);
    }
    this.downloadSuspendRequestId = 0;
  }
}
