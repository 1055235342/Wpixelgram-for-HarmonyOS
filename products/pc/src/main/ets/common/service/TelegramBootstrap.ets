import { common } from '@kit.AbilityKit';
import preferences from '@ohos.data.preferences';
import { TdlibParameters, TdlibService, TdUpdate } from './TdlibService';

interface TelegramAppConfig {
  api_id: number;
  api_hash: string;
}

export class TelegramBootstrap {
  private static initialized: boolean = false;
  private static parametersSent: boolean = false;
  private static parametersListenerRegistered: boolean = false;
  private static pendingParameters: TdlibParameters | null = null;
  private static readonly preferencesName: string = 'telegram_app_config';
  private static readonly apiIdKey: string = 'api_id';
  private static readonly apiHashKey: string = 'api_hash';

  private static bytesToString(bytes: Uint8Array): string {
    let result = '';
    for (let index = 0; index < bytes.length; index++) {
      result += String.fromCharCode(bytes[index]);
    }
    return result;
  }

  private static isValidConfig(config: TelegramAppConfig): boolean {
    return config.api_id > 0 && config.api_hash.length > 0 && config.api_hash !== 'replace_with_your_api_hash';
  }

  public static async loadSavedTelegramAppConfig(context: common.UIAbilityContext): Promise<TelegramAppConfig | null> {
    const store = await preferences.getPreferences(context, { name: TelegramBootstrap.preferencesName });
    const savedApiId = await store.get(TelegramBootstrap.apiIdKey, 0) as number;
    const savedApiHash = await store.get(TelegramBootstrap.apiHashKey, '') as string;
    const savedConfig: TelegramAppConfig = {
      api_id: savedApiId,
      api_hash: savedApiHash
    };
    if (TelegramBootstrap.isValidConfig(savedConfig)) {
      return savedConfig;
    }
    try {
      return await TelegramBootstrap.loadRawTelegramAppConfig(context);
    } catch (_err) {
      return null;
    }
  }

  public static async saveTelegramAppConfig(context: common.UIAbilityContext, config: TelegramAppConfig): Promise<void> {
    if (!TelegramBootstrap.isValidConfig(config)) {
      throw new Error('Telegram app config is invalid');
    }
    const store = await preferences.getPreferences(context, { name: TelegramBootstrap.preferencesName });
    await store.put(TelegramBootstrap.apiIdKey, config.api_id);
    await store.put(TelegramBootstrap.apiHashKey, config.api_hash);
    await store.flush();
  }

  private static async loadRawTelegramAppConfig(context: common.UIAbilityContext): Promise<TelegramAppConfig> {
    const configBytes = await context.resourceManager.getRawFileContent('telegram_config.json');
    const configText = TelegramBootstrap.bytesToString(configBytes);
    const config = JSON.parse(configText) as TelegramAppConfig;
    if (!TelegramBootstrap.isValidConfig(config)) {
      throw new Error('Telegram app config is invalid');
    }
    return config;
  }

  public static async initialize(context: common.UIAbilityContext): Promise<TdlibService> {
    const appConfig = await TelegramBootstrap.loadSavedTelegramAppConfig(context);
    if (appConfig === null) {
      throw new Error('Telegram app config is invalid');
    }
    return TelegramBootstrap.initializeWithConfig(context, appConfig);
  }

  public static async recreateForLogin(context: common.UIAbilityContext, appConfig: TelegramAppConfig): Promise<TdlibService> {
    const td = TdlibService.getInstance();
    console.info('[TelegramBootstrap] recreate TDLib client for login method switch');
    await TelegramBootstrap.closeClientIfNeeded(td);
    td.recreateClient();
    TelegramBootstrap.initialized = false;
    TelegramBootstrap.parametersSent = false;
    return TelegramBootstrap.initializeWithConfig(context, appConfig);
  }

  private static waitForClosed(td: TdlibService, timeoutMs: number = 15000): Promise<void> {
    if (td.getCurrentAuthorizationState() === 'authorizationStateClosed') {
      return Promise.resolve();
    }
    return new Promise((resolve: () => void) => {
      let finished = false;
      const listener = (update: TdUpdate): void => {
        const state = update.authorization_state ? update.authorization_state.type : '';
        if (state !== 'authorizationStateClosed') {
          return;
        }
        finished = true;
        td.offUpdate('updateAuthorizationState', listener);
        resolve();
      };
      td.onUpdate('updateAuthorizationState', listener);
      setTimeout(() => {
        if (finished) {
          return;
        }
        td.offUpdate('updateAuthorizationState', listener);
        console.warn(`[TelegramBootstrap] wait closed timeout state=${td.getCurrentAuthorizationState()}`);
        resolve();
      }, timeoutMs);
    });
  }

  private static async closeClientIfNeeded(td: TdlibService): Promise<void> {
    const state = td.getCurrentAuthorizationState();
    if (state.length === 0 || state === 'authorizationStateClosed') {
      return;
    }
    console.info(`[TelegramBootstrap] close old TDLib client before recreate state=${state}`);
    td.close();
    await TelegramBootstrap.waitForClosed(td);
  }

  public static async initializeWithConfig(context: common.UIAbilityContext, appConfig: TelegramAppConfig): Promise<TdlibService> {
    const td = TdlibService.getInstance();
    if (td.getCurrentAuthorizationState() === 'authorizationStateClosed') {
      console.info('[TelegramBootstrap] recreate TDLib client after closed state');
      td.recreateClient();
      TelegramBootstrap.initialized = false;
      TelegramBootstrap.parametersSent = false;
    }
    td.startPolling(0.1);
    const params: TdlibParameters = {
      use_test_dc: false,
      database_directory: context.filesDir + '/tdlib/db',
      files_directory: context.filesDir + '/tdlib/files',
      database_encryption_key: '',
      use_file_database: true,
      use_chat_info_database: true,
      use_message_database: true,
      use_secret_chats: false,
      api_id: appConfig.api_id,
      api_hash: appConfig.api_hash,
      system_language_code: 'zh-hans',
      device_model: 'HarmonyOS',
      system_version: '1.0',
      application_version: '1.0.0'
    };
    TelegramBootstrap.pendingParameters = params;
    TelegramBootstrap.registerParametersListener(td);
    if (td.getCurrentAuthorizationState() === 'authorizationStateWaitTdlibParameters') {
      TelegramBootstrap.sendPendingParameters(td);
    }
    td.getAuthorizationState();
    if (TelegramBootstrap.initialized) {
      return td;
    }
    await TelegramBootstrap.saveTelegramAppConfig(context, appConfig);
    TelegramBootstrap.initialized = true;
    return td;
  }

  private static registerParametersListener(td: TdlibService): void {
    if (TelegramBootstrap.parametersListenerRegistered) {
      return;
    }
    TelegramBootstrap.parametersListenerRegistered = true;
    td.onUpdate('authorizationStateWaitTdlibParameters', (_update: TdUpdate) => {
      TelegramBootstrap.sendPendingParameters(td);
    });
  }

  private static sendPendingParameters(td: TdlibService): void {
    if (TelegramBootstrap.parametersSent || TelegramBootstrap.pendingParameters === null) {
      return;
    }
    const params = TelegramBootstrap.pendingParameters;
    TelegramBootstrap.parametersSent = true;
    console.info(`[TelegramBootstrap] setTdlibParameters apiId=${params.api_id}, apiHashConfigured=${params.api_hash.length > 0}`);
    td.setTdlibParameters(params);
  }
}
