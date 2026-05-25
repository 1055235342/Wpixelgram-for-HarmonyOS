// entry/src/main/ets/pages/LoginPage.ets
import router from '@ohos.router';
import { common } from '@kit.AbilityKit';
import type { TdlibService, TdUpdate } from '../common/service/TdlibService';
import { TelegramBootstrap } from '../common/service/TelegramBootstrap';

@Entry
@Component
struct LoginPage {
  @State phone: string = '+86';
  @State code: string = '';
  @State showCode: boolean = false;
  @State statusText: string = '请输入手机号';
  private td: TdlibService | null = null;
  private listenersRegistered: boolean = false;
  private tdlibConfigured: boolean = false;
  private autoChecking: boolean = false;

  aboutToAppear() {
    console.info('[LoginPage] aboutToAppear');
    this.statusText = '正在检查登录状态...';
    setTimeout(() => {
      this.checkExistingSession();
    }, 300);
  }

  private async getTdlib(): Promise<TdlibService> {
    if (this.td) {
      console.info('[LoginPage] reuse TdlibService');
      return this.td;
    }
    console.info('[LoginPage] importing TdlibService');
    const tdlibModule = await import('../common/service/TdlibService');
    this.td = tdlibModule.TdlibService.getInstance();
    console.info('[LoginPage] TdlibService ready');
    return this.td;
  }

  private registerAuthListeners(td: TdlibService): void {
    if (this.listenersRegistered) {
      return;
    }
    this.listenersRegistered = true;
    td.onUpdate('authorizationStateWaitTdlibParameters', (_update: TdUpdate) => {
      console.info('[LoginPage] received authorizationStateWaitTdlibParameters');
      this.statusText = '正在初始化 TDLib...';
    });
    td.onUpdate('authorizationStateWaitPhoneNumber', (_update: TdUpdate) => {
      console.info('[LoginPage] received authorizationStateWaitPhoneNumber');
      this.showCode = false;
      this.statusText = '请输入手机号';
    });
    td.onUpdate('authorizationStateWaitCode', (_update: TdUpdate) => {
      console.info('[LoginPage] received authorizationStateWaitCode');
      this.showCode = true;
      this.statusText = '请输入验证码';
    });
    td.onUpdate('authorizationStateReady', (_update: TdUpdate) => {
      console.info('[LoginPage] received authorizationStateReady');
      router.replaceUrl({ url: 'pages/MainPage' });
    });
    td.onUpdate('authorizationStateLoggingOut', (_update: TdUpdate) => {
      console.info('[LoginPage] received authorizationStateLoggingOut');
      this.statusText = '正在退出登录...';
    });
    td.onUpdate('authorizationStateClosing', (_update: TdUpdate) => {
      console.info('[LoginPage] received authorizationStateClosing');
      this.statusText = 'TDLib 正在关闭...';
    });
    td.onUpdate('authorizationStateClosed', (_update: TdUpdate) => {
      console.info('[LoginPage] received authorizationStateClosed');
      this.statusText = '登录状态已关闭，请重新登录';
    });
  }

  private async checkExistingSession(): Promise<void> {
    if (this.autoChecking) {
      console.info('[LoginPage] checkExistingSession skipped');
      return;
    }
    this.autoChecking = true;
    try {
      console.info('[LoginPage] checkExistingSession start');
      await this.prepareTdlib();
      if (this.statusText === '正在检查登录状态...' || this.statusText === '正在初始化 TDLib...') {
        this.statusText = '请输入手机号';
      }
      console.info('[LoginPage] checkExistingSession done, waiting auth state');
    } catch (err) {
      this.statusText = '请输入手机号';
      console.error(`[LoginPage] checkExistingSession failed=${JSON.stringify(err)}`);
    } finally {
      this.autoChecking = false;
    }
  }

  private async prepareTdlib(): Promise<TdlibService> {
    try {
      console.info('[LoginPage] prepareTdlib start');
      const td = await this.getTdlib();
      this.registerAuthListeners(td);
      if (this.tdlibConfigured) {
        console.info('[LoginPage] TDLib already configured');
        return td;
      }
      const context = getContext(this) as common.UIAbilityContext;
      await TelegramBootstrap.initialize(context);
      this.tdlibConfigured = true;
      console.info('[LoginPage] prepareTdlib done');
      return td;
    } catch (err) {
      this.statusText = 'TDLib 初始化失败，请检查 telegram_config.json';
      console.error(`LoginPage: TDLib init failed: ${JSON.stringify(err)}`);
      throw new Error('TDLib initialization failed');
    }
  }

  private async sendPhoneNumber(): Promise<void> {
    try {
      console.info(`[LoginPage] sendPhoneNumber phone=${this.phone}`);
      this.statusText = '正在发送手机号...';
      const td = await this.prepareTdlib();
      td.setAuthenticationPhoneNumber(this.phone);
      this.statusText = '手机号已发送，等待 Telegram 响应...';
    } catch (err) {
      this.statusText = '发送手机号失败，请查看设备日志';
      console.error(`[LoginPage] sendPhoneNumber failed=${JSON.stringify(err)}`);
    }
  }

  private async sendAuthenticationCode(): Promise<void> {
    try {
      console.info(`[LoginPage] sendAuthenticationCode codeLength=${this.code.length}`);
      this.statusText = '正在提交验证码...';
      const td = await this.prepareTdlib();
      td.checkAuthenticationCode(this.code);
      this.statusText = '验证码已提交，等待登录结果...';
    } catch (err) {
      this.statusText = '提交验证码失败，请查看设备日志';
      console.error(`[LoginPage] sendAuthenticationCode failed=${JSON.stringify(err)}`);
    }
  }

  build() {
    Column() {
      Text('Telegram 登录').fontSize(24).fontWeight(FontWeight.Bold).margin(20)
      Text(this.statusText).fontSize(16).margin(10)

      if (!this.showCode) {
        TextInput({ placeholder: '手机号', text: this.phone }).onChange((value: string) => {
          this.phone = value;
        })
          .width('80%')
          .height(48)
          .margin(10)
          .backgroundColor('#F5F7FA')
        Button('下一步').onClick(() => {
          console.info(`[LoginPage] button 下一步 clicked phone=${this.phone}`);
          if (this.phone) {
            this.sendPhoneNumber();
          } else {
            this.statusText = '请输入手机号';
            console.warn('[LoginPage] phone is empty');
          }
        })
      } else {
        TextInput({ placeholder: '验证码', text: this.code }).onChange((value: string) => {
          this.code = value;
        })
          .width('80%')
          .height(48)
          .margin(10)
          .backgroundColor('#F5F7FA')
          .type(InputType.Number)
        Button('登录').onClick(() => {
          console.info(`[LoginPage] button 登录 clicked codeLength=${this.code.length}`);
          if (this.code) {
            this.sendAuthenticationCode();
          } else {
            this.statusText = '请输入验证码';
            console.warn('[LoginPage] code is empty');
          }
        })
      }
    }
    .width('100%').height('100%').justifyContent(FlexAlign.Center)
  }
}
