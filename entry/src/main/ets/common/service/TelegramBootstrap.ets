import { common } from '@kit.AbilityKit';
import { TdlibParameters, TdlibService } from './TdlibService';

interface TelegramAppConfig {
  api_id: number;
  api_hash: string;
}

export class TelegramBootstrap {
  private static initialized: boolean = false;

  private static bytesToString(bytes: Uint8Array): string {
    let result = '';
    for (let index = 0; index < bytes.length; index++) {
      result += String.fromCharCode(bytes[index]);
    }
    return result;
  }

  private static async loadTelegramAppConfig(context: common.UIAbilityContext): Promise<TelegramAppConfig> {
    const configBytes = await context.resourceManager.getRawFileContent('telegram_config.json');
    const configText = TelegramBootstrap.bytesToString(configBytes);
    const config = JSON.parse(configText) as TelegramAppConfig;
    if (config.api_id <= 0 || config.api_hash.length === 0 || config.api_hash === 'replace_with_your_api_hash') {
      throw new Error('Telegram app config is invalid');
    }
    return config;
  }

  public static async initialize(context: common.UIAbilityContext): Promise<TdlibService> {
    const td = TdlibService.getInstance();
    td.startPolling(0.1);
    if (TelegramBootstrap.initialized) {
      td.getAuthorizationState();
      return td;
    }
    const appConfig = await TelegramBootstrap.loadTelegramAppConfig(context);
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
    console.info(`[TelegramBootstrap] setTdlibParameters apiId=${params.api_id}, apiHashConfigured=${params.api_hash.length > 0}`);
    td.setTdlibParameters(params);
    td.getAuthorizationState();
    TelegramBootstrap.initialized = true;
    return td;
  }
}
