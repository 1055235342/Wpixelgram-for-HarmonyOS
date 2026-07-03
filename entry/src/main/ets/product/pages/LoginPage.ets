// entry/src/main/ets/product/pages/LoginPage.ets
import router from '@ohos.router';
import { common } from '@kit.AbilityKit';
import { promptAction } from '@kit.ArkUI';
import type { TdlibService, TdUpdate } from '../../common/service/TdlibService';
import { TelegramBootstrap } from '../../common/service/TelegramBootstrap';

interface CountryCodeItem {
  label: string;
  code: string;
}

interface CountrySelectOption {
  value: string;
}

type LoginMethod = 'phone' | 'qr';
type ResendCodeMethod = 'sms' | 'voice';

let cachedLoginStep: number = 0;
let cachedLoginMethod: LoginMethod = 'phone';
let cachedPhone: string = '';
let cachedCountryIndex: number = 0;

@Entry
@Component
struct LoginPage {
  @State step: number = 1;
  @State apiIdText: string = '';
  @State apiHash: string = '';
  @State loginMethod: LoginMethod = 'phone';
  @State countryIndex: number = 0;
  @State phone: string = '';
  @State code: string = '';
  @State password: string = '';
  @State qrLink: string = '';
  @State waitingCode: boolean = false;
  @State waitingPassword: boolean = false;
  @State resendMenuVisible: boolean = false;
  @State resendCountdown: number = 0;
  @State resendingCode: boolean = false;
  @State configLoaded: boolean = false;
  @State configLoading: boolean = false;
  @State pageLoading: boolean = false;
  @State loadingText: string = '';
  @State codeHintText: string = '';
  @State canResendCode: boolean = false;
  @State statusText: string = '配置 Telegram API';
  private td: TdlibService | null = null;
  private listenersRegistered: boolean = false;
  private listenerDisposers: (() => void)[] = [];
  private pageActive: boolean = false;
  private tdlibConfigured: boolean = false;
  private activeLoginToken: number = 0;
  private runningLoginMethod: LoginMethod | '' = '';
  private authorizationQueryPending: boolean = false;
  private resendCountdownTimer: number = -1;
  private startupChecking: boolean = false;
  private routingToMain: boolean = false;
  private readonly countries: CountryCodeItem[] = [
    { label: '中国', code: '+86' },
    { label: '中国香港', code: '+852' },
    { label: '中国台湾', code: '+886' },
    { label: '美国', code: '+1' },
    { label: '日本', code: '+81' },
    { label: '韩国', code: '+82' },
    { label: '英国', code: '+44' }
  ];

  aboutToAppear() {
    this.pageActive = true;
    this.routingToMain = false;

    if (!this.configLoaded && !this.configLoading) {
      this.loadInitialConfig();
    }
  }

  aboutToDisappear() {
    this.pageActive = false;
    this.stopResendCountdown();
    this.disposeAuthListeners();
  }

  private openMainOnce(): void {
    if (!this.pageActive || this.routingToMain) {
      return;
    }

    this.routingToMain = true;
    router.replaceUrl({ url: 'product/pages/MainPage' });
  }

  private async loadInitialConfig(): Promise<void> {
    this.configLoading = true;
    this.startupChecking = true;
    this.statusText = '正在检查登录状态...';

    try {
      const context = getContext(this) as common.UIAbilityContext;
      const config = await TelegramBootstrap.loadSavedTelegramAppConfig(context);

      if (!this.pageActive) {
        return;
      }

      // 没有配置，才展示 API 配置页
      if (config === null) {
        this.step = 1;
        this.statusText = '请输入 api_id 和 api_hash';
        return;
      }

      // 有配置后，永远不要再自动跳回 step = 1
      this.apiIdText = `${config.api_id}`;
      this.apiHash = config.api_hash;

      const td = await this.getTdlib();
      this.registerAuthListeners(td);

      let authState = td.getCurrentAuthorizationState();

      // 刚退出时 TDLib 仍在关闭中，不要重新初始化，不要回 API 页
      if (
        authState === 'authorizationStateLoggingOut' ||
          authState === 'authorizationStateClosing' ||
          authState === 'authorizationStateClosed'
      ) {
        this.tdlibConfigured = false;
        this.step = 2;
        this.loginMethod = 'phone';
        this.statusText = '选择登录方式';
        return;
      }

      // 第一次启动 TDLib 才初始化
      if (
        authState.length === 0 ||
          authState === 'authorizationStateWaitTdlibParameters'
      ) {
        await TelegramBootstrap.initializeWithConfig(context, {
          api_id: config.api_id,
          api_hash: config.api_hash
        });

        this.tdlibConfigured = true;

        authState = await this.waitForAuthState(
          td,
          [
            'authorizationStateReady',
            'authorizationStateWaitPhoneNumber',
            'authorizationStateWaitCode',
            'authorizationStateWaitPassword',
            'authorizationStateWaitOtherDeviceConfirmation',
            'authorizationStateClosed'
          ],
          12000
        );
      } else {
        // TDLib 已经是可用状态，不要重复 initialize
        this.tdlibConfigured = true;
      }

      if (!this.pageActive) {
        return;
      }

      // 已登录，直接进主页
      if (authState === 'authorizationStateReady') {
        this.openMainOnce();
        return;
      }

      // App 在验证码阶段被关闭，恢复验证码页
      if (authState === 'authorizationStateWaitCode') {
        this.step = 3;
        this.loginMethod = 'phone';
        this.waitingCode = true;
        this.waitingPassword = false;
        this.statusText = '请输入验证码';
        return;
      }

      // App 在二步验证阶段被关闭，恢复密码页
      if (authState === 'authorizationStateWaitPassword') {
        this.step = 3;
        this.loginMethod = 'phone';
        this.waitingCode = false;
        this.waitingPassword = true;
        this.statusText = '请输入二步验证密码';
        return;
      }

      // 其余未登录状态，都进入选择登录方式
      this.step = 2;
      this.loginMethod = 'phone';
      this.waitingCode = false;
      this.waitingPassword = false;
      this.statusText = '选择登录方式';
    } catch (err) {
      console.error(`[LoginPage] loadInitialConfig failed=${JSON.stringify(err)}`);

      // 已经有配置时，初始化失败也只回登录方式，不回 API 配置页
      if (this.apiIdText.length > 0 && this.apiHash.length > 0) {
        this.step = 2;
        this.statusText = '登录状态检查失败，请重新选择登录方式';
      } else {
        this.step = 1;
        this.statusText = '请输入 api_id 和 api_hash';
      }
    } finally {
      this.startupChecking = false;
      this.configLoaded = true;
      this.configLoading = false;
    }
  }

  private async getTdlib(): Promise<TdlibService> {
    if (this.td) {
      return this.td;
    }
    const tdlibModule = await import('../../common/service/TdlibService');
    this.td = tdlibModule.TdlibService.getInstance();
    return this.td;
  }

  private registerAuthListeners(td: TdlibService): void {
    if (this.listenersRegistered) {
      return;
    }
    this.listenersRegistered = true;
    this.listenAuthUpdate(td, 'authorizationStateWaitTdlibParameters', (_update: TdUpdate) => {
      this.statusText = '正在初始化 TDLib...';
    });
    this.listenAuthUpdate(td, 'authorizationStateWaitPhoneNumber', (_update: TdUpdate) => {
      if (this.runningLoginMethod === 'qr') {
        console.info('[LoginPage] keep qr flow on authorizationStateWaitPhoneNumber');
        return;
      }
      this.pageLoading = false;
      this.loadingText = '';
      this.waitingCode = false;
      this.waitingPassword = false;
      this.resendMenuVisible = false;
      this.canResendCode = false;
      this.statusText = '请输入手机号';
    });
    this.listenAuthUpdate(td, 'authorizationStateWaitCode', (update: TdUpdate) => {
      if (this.runningLoginMethod === 'qr') {
        console.info('[LoginPage] ignore authorizationStateWaitCode during qr flow');
        return;
      }
      this.authorizationQueryPending = false;
      this.runningLoginMethod = '';
      this.pageLoading = false;
      this.loadingText = '';
      this.waitingCode = true;
      this.waitingPassword = false;
      this.loginMethod = 'phone';
      this.step = 3;
      this.codeHintText = this.buildCodeHintText(update);
      this.canResendCode = this.hasNextCodeType(update);
      const timeout = this.getCodeTimeout(update);
      this.statusText = this.codeHintText.length > 0 ? this.codeHintText : '请输入验证码';
      this.startResendCountdown(timeout);
      this.cacheLoginState();
      console.info(`[LoginPage] wait code info=${JSON.stringify(update.authorization_state ? update.authorization_state.code_info : undefined)}`);
    });
    this.listenAuthUpdate(td, 'authorizationStateWaitPassword', (update: TdUpdate) => {
      if (this.runningLoginMethod === 'qr') {
        console.info('[LoginPage] ignore authorizationStateWaitPassword during qr flow');
        return;
      }
      this.authorizationQueryPending = false;
      this.runningLoginMethod = '';
      this.pageLoading = false;
      this.loadingText = '';
      this.waitingPassword = true;
      this.loginMethod = 'phone';
      this.step = 3;
      const hint = update.authorization_state && update.authorization_state.password_hint ?
      `，提示：${update.authorization_state.password_hint}` : '';
      this.statusText = `请输入二步验证密码${hint}`;
    });
    this.listenAuthUpdate(td, 'authorizationStateWaitOtherDeviceConfirmation', (update: TdUpdate) => {
      this.authorizationQueryPending = false;
      this.runningLoginMethod = '';
      this.pageLoading = false;
      this.loadingText = '';
      this.step = 3;
      this.loginMethod = 'qr';
      this.qrLink = update.authorization_state && update.authorization_state.link ? update.authorization_state.link : '';
      this.statusText = this.qrLink.length > 0 ? '请使用 Telegram 扫码登录' : '正在获取二维码...';
    });
    this.listenAuthUpdate(td, 'authorizationStateReady', (_update: TdUpdate) => {
      this.authorizationQueryPending = false;
      this.runningLoginMethod = '';
      this.pageLoading = false;
      this.loadingText = '';

      this.openMainOnce();
    });
    this.listenAuthUpdate(td, 'authorizationStateLoggingOut', (_update: TdUpdate) => {
      this.statusText = '正在退出登录...';
    });
    this.listenAuthUpdate(td, 'authorizationStateClosing', (_update: TdUpdate) => {
      this.statusText = 'TDLib 正在关闭...';
    });
    this.listenAuthUpdate(td, 'authorizationStateClosed', (_update: TdUpdate) => {
      this.tdlibConfigured = false;
      this.authorizationQueryPending = false;
      this.runningLoginMethod = '';
      this.pageLoading = false;
      this.loadingText = '';
      this.waitingCode = false;
      this.waitingPassword = false;

      // 已退出时只回“选择登录方式”，绝不回 API 配置页
      if (
        this.pageActive &&
          this.configLoaded &&
          !this.startupChecking &&
          !this.routingToMain
      ) {
        this.step = 2;
        this.loginMethod = 'phone';
        this.statusText = '选择登录方式';
      }
    });
    this.listenAuthUpdate(td, 'error', (update: TdUpdate) => {
      if (this.shouldIgnoreLoginError(update)) {
        return;
      }
      if (this.handleLoginError(update)) {
        return;
      }
      this.authorizationQueryPending = false;
      this.runningLoginMethod = '';
      this.pageLoading = false;
      this.loadingText = '';
      this.resendingCode = false;
      const message = update.error_message !== undefined ? update.error_message : 'TDLib 请求失败';
      this.statusText = `TDLib 错误 ${update.code !== undefined ? update.code : ''} ${message}`;
      console.error(`[LoginPage] tdlib error code=${update.code}, message=${message}`);
    });
  }

  private handleLoginError(update: TdUpdate): boolean {
    const message = update.error_message !== undefined ? update.error_message : '';
    const lowerMessage = message.toLowerCase();
    if (update.code === 400 && lowerMessage.indexOf('code') >= 0 && lowerMessage.indexOf('resend') >= 0) {
      this.authorizationQueryPending = false;
      this.runningLoginMethod = '';
      this.pageLoading = false;
      this.loadingText = '';
      this.resendingCode = false;
      this.resendMenuVisible = false;
      this.canResendCode = false;
      this.statusText = '当前不能重新发送验证码，请检查 Telegram 应用内消息或稍后再试';
      this.showToast('当前不能重新发送验证码');
      console.warn(`[LoginPage] resend code rejected message=${message}`);
      return true;
    }
    return false;
  }

  private shouldIgnoreLoginError(update: TdUpdate): boolean {
    const message = update.error_message !== undefined ? update.error_message : '';
    if (update.code !== 401 || message !== 'Unauthorized') {
      return false;
    }
    const authState = this.td ? this.td.getCurrentAuthorizationState() : '';
    const inLoginAuthorization = authState !== 'authorizationStateReady' && authState !== 'authorizationStateClosed';
    if (inLoginAuthorization) {
      console.warn(`[LoginPage] ignore unauthorized error during login authState=${authState}`);
      return true;
    }
    return false;
  }

  private listenAuthUpdate(
    td: TdlibService,
    type: string,
    callback: (update: TdUpdate) => void
  ): void {
    const wrapped = (update: TdUpdate): void => {
      // 页面已销毁，或这不是当前正在使用的 TDLib 实例，直接忽略
      if (!this.pageActive || this.td !== td) {
        return;
      }

      callback(update);
    };

    td.onUpdate(type, wrapped);

    this.listenerDisposers.push(() => {
      td.offUpdate(type, wrapped);
    });
  }

  private disposeAuthListeners(): void {
    this.listenerDisposers.forEach((dispose: () => void) => {
      dispose();
    });
    this.listenerDisposers = [];
    this.listenersRegistered = false;
  }

  private getApiId(): number {
    return Number(this.apiIdText);
  }

  private isConfigValid(): boolean {
    return this.getApiId() > 0 && this.apiHash.trim().length > 0;
  }

  private async saveConfigAndNext(): Promise<void> {
    if (this.pageLoading) {
      return;
    }
    if (!this.isConfigValid()) {
      this.statusText = '请输入有效的 api_id 和 api_hash';
      return;
    }
    this.pageLoading = true;
    this.loadingText = '正在保存配置...';
    try {
      const context = getContext(this) as common.UIAbilityContext;
      await TelegramBootstrap.saveTelegramAppConfig(context, {
        api_id: this.getApiId(),
        api_hash: this.apiHash.trim()
      });
      this.step = 2;
      this.waitingCode = false;
      this.waitingPassword = false;
      this.qrLink = '';
      this.loginMethod = 'phone';
      this.statusText = '选择登录方式';
      this.cacheLoginState();
    } catch (err) {
      this.statusText = 'API 配置保存失败';
      console.error(`[LoginPage] save config failed=${JSON.stringify(err)}`);
    } finally {
      this.pageLoading = false;
      this.loadingText = '';
    }
  }

  private async prepareTdlib(): Promise<TdlibService> {
    let td = await this.getTdlib();
    this.registerAuthListeners(td);

    let authState = td.getCurrentAuthorizationState();

    // 旧 TDLib 已退出或正在退出：重新创建登录实例
    if (
      authState === 'authorizationStateClosed' ||
        authState === 'authorizationStateClosing' ||
        authState === 'authorizationStateLoggingOut'
    ) {
      if (authState !== 'authorizationStateClosed') {
        try {
          await this.waitForAuthState(
            td,
            ['authorizationStateClosed'],
            15000
          );
        } catch (_) {
          console.warn('[LoginPage] wait TDLib close timeout, recreate anyway');
        }
      }

      td = await this.recreateTdlibForLogin();
      return td;
    }

    // 新 TDLib 才初始化参数
    if (
      authState.length === 0 ||
        authState === 'authorizationStateWaitTdlibParameters'
    ) {
      const context = getContext(this) as common.UIAbilityContext;

      await TelegramBootstrap.initializeWithConfig(context, {
        api_id: this.getApiId(),
        api_hash: this.apiHash.trim()
      });
    }

    this.tdlibConfigured = true;
    td.getAuthorizationState();

    return td;
  }

  private async recreateTdlibForLogin(): Promise<TdlibService> {
    const context = getContext(this) as common.UIAbilityContext;
    this.disposeAuthListeners();
    const td = await TelegramBootstrap.recreateForLogin(context, {
      api_id: this.getApiId(),
      api_hash: this.apiHash.trim()
    });
    this.td = td;
    this.tdlibConfigured = true;
    this.registerAuthListeners(td);
    return td;
  }

  private getFullPhone(): string {
    const digits = this.phone.trim().replace(/\s/g, '');
    return `${this.countries[this.countryIndex].code}${digits}`;
  }

  private getCountryOptions(): CountrySelectOption[] {
    return this.countries.map((item: CountryCodeItem): CountrySelectOption => {
      return { value: `${item.label} ${item.code}` };
    });
  }

  private getErrorMessage(err: Object): string {
    if (err instanceof Error) {
      return err.message;
    }
    return JSON.stringify(err);
  }

  private showToast(message: string): void {
    promptAction.showToast({ message: message, duration: 2200 });
  }

  private getCodeTimeout(update: TdUpdate): number {
    const timeout = update.authorization_state && update.authorization_state.code_info &&
      update.authorization_state.code_info.timeout !== undefined ? update.authorization_state.code_info.timeout : 60;
    return timeout > 0 ? timeout : 0;
  }

  private hasNextCodeType(update: TdUpdate): boolean {
    const info = update.authorization_state ? update.authorization_state.code_info : undefined;
    return !!(info && info.next_type);
  }

  private getCodeTypeText(type: string): string {
    switch (type) {
      case 'authenticationCodeTypeTelegramMessage':
        return 'Telegram 应用内消息';
      case 'authenticationCodeTypeSms':
        return '短信';
      case 'authenticationCodeTypeCall':
        return '语音电话';
      case 'authenticationCodeTypeFlashCall':
        return '闪电来电';
      case 'authenticationCodeTypeMissedCall':
        return '未接来电';
      case 'authenticationCodeTypeFragment':
        return 'Fragment';
      default:
        return '验证码';
    }
  }

  private buildCodeHintText(update: TdUpdate): string {
    const info = update.authorization_state ? update.authorization_state.code_info : undefined;
    if (!info || !info.type) {
      return '';
    }
    const current = this.getCodeTypeText(info.type.type);
    const next = info.next_type ? this.getCodeTypeText(info.next_type.type) : '';
    if (next.length > 0) {
      return `验证码已通过${current}发送，可稍后切换为${next}`;
    }
    return `验证码已通过${current}发送`;
  }

  private beginLoginFlow(method: LoginMethod): number {
    this.activeLoginToken++;
    this.runningLoginMethod = method;
    this.authorizationQueryPending = false;
    this.pageLoading = true;
    return this.activeLoginToken;
  }

  private isLoginFlowCurrent(token: number, method: LoginMethod): boolean {
    return this.activeLoginToken === token && this.runningLoginMethod === method;
  }

  private waitForAuthState(td: TdlibService, expectedStates: string[], timeoutMs: number = 10000): Promise<string> {
    const currentState = td.getCurrentAuthorizationState();
    if (expectedStates.indexOf(currentState) >= 0) {
      return Promise.resolve(currentState);
    }
    return new Promise((resolve: (value: string) => void, reject: (reason: Error) => void) => {
      let finished = false;
      const listener = (update: TdUpdate): void => {
        const state = update.authorization_state ? update.authorization_state.type : '';
        if (expectedStates.indexOf(state) < 0) {
          return;
        }
        finished = true;
        td.offUpdate('updateAuthorizationState', listener);
        resolve(state);
      };
      td.onUpdate('updateAuthorizationState', listener);
      td.getAuthorizationState();
      setTimeout(() => {
        if (finished) {
          return;
        }
        td.offUpdate('updateAuthorizationState', listener);
        reject(new Error(`wait authorization state timeout current=${td.getCurrentAuthorizationState()}`));
      }, timeoutMs);
    });
  }

  private async startPhoneLogin(): Promise<void> {
    if (this.phone.trim().length === 0) {
      this.statusText = '请输入手机号';
      return;
    }
    if (this.runningLoginMethod === 'phone') {
      this.statusText = '正在发送手机号...';
      return;
    }
    const flowToken = this.beginLoginFlow('phone');
    this.cacheLoginState();
    this.loadingText = '正在发送验证码...';
    try {
      this.statusText = '正在发送手机号...';
      let td = await this.prepareTdlib();
      if (!this.isLoginFlowCurrent(flowToken, 'phone')) {
        return;
      }
      if (td.getCurrentAuthorizationState() === 'authorizationStateWaitOtherDeviceConfirmation') {
        this.qrLink = '';
        this.statusText = '正在切换到手机号登录...';
        td = await this.recreateTdlibForLogin();
      }
      if (!this.isLoginFlowCurrent(flowToken, 'phone')) {
        return;
      }
      this.statusText = '等待 TDLib 初始化完成...';
      await this.waitForAuthState(td, ['authorizationStateWaitPhoneNumber']);
      if (!this.isLoginFlowCurrent(flowToken, 'phone')) {
        return;
      }
      this.statusText = '正在发送手机号...';
      this.authorizationQueryPending = true;
      console.info(`[LoginPage] setAuthenticationPhoneNumber phone=${this.getFullPhone()}`);
      td.setAuthenticationPhoneNumber(this.getFullPhone());
      this.loadingText = '等待验证码返回...';
      this.statusText = '手机号已发送，等待验证码...';
    } catch (err) {
      if (!this.isLoginFlowCurrent(flowToken, 'phone')) {
        return;
      }
      this.authorizationQueryPending = false;
      this.runningLoginMethod = '';
      this.pageLoading = false;
      this.loadingText = '';
      const message = this.getErrorMessage(err);
      this.statusText = `发送手机号失败：${message}`;
      console.error(`[LoginPage] start phone failed=${message}`);
    }
  }

  private async startQrLogin(): Promise<void> {
    if (this.runningLoginMethod === 'qr') {
      this.statusText = '正在获取二维码...';
      return;
    }
    const flowToken = this.beginLoginFlow('qr');
    this.loadingText = '正在获取二维码...';
    try {
      this.qrLink = '';
      this.statusText = '正在获取二维码...';
      let td = await this.prepareTdlib();
      if (!this.isLoginFlowCurrent(flowToken, 'qr')) {
        return;
      }
      if (td.getCurrentAuthorizationState() === 'authorizationStateWaitOtherDeviceConfirmation') {
        this.runningLoginMethod = '';
        this.pageLoading = false;
        this.loadingText = '';
        this.statusText = this.qrLink.length > 0 ? '请使用 Telegram 扫码登录' : '正在等待二维码...';
        return;
      }
      if (td.getCurrentAuthorizationState() !== 'authorizationStateWaitPhoneNumber') {
        console.info(`[LoginPage] recreate TDLib for qr from state=${td.getCurrentAuthorizationState()}`);
        td = await this.recreateTdlibForLogin();
      }
      await this.waitForAuthState(td, ['authorizationStateWaitPhoneNumber']);
      if (!this.isLoginFlowCurrent(flowToken, 'qr')) {
        return;
      }
      this.authorizationQueryPending = true;
      td.requestQrCodeAuthentication();
      this.loadingText = '等待二维码返回...';
      this.statusText = '等待二维码返回...';
      await this.waitForAuthState(td, ['authorizationStateWaitOtherDeviceConfirmation']);
    } catch (err) {
      if (!this.isLoginFlowCurrent(flowToken, 'qr')) {
        return;
      }
      this.authorizationQueryPending = false;
      this.runningLoginMethod = '';
      this.pageLoading = false;
      this.loadingText = '';
      const message = this.getErrorMessage(err);
      this.statusText = `获取二维码失败：${message}`;
      console.error(`[LoginPage] start qr failed=${message}`);
    }
  }

  private async submitCode(): Promise<void> {
    if (this.pageLoading) {
      return;
    }
    const code = this.code.trim();
    if (code.length !== 6) {
      this.statusText = '请输入验证码';
      return;
    }
    this.pageLoading = true;
    this.loadingText = '正在提交验证码...';
    try {
      const td = await this.prepareTdlib();
      await this.waitForAuthState(td, ['authorizationStateWaitCode']);
      td.checkAuthenticationCode(code);
      this.statusText = '验证码已提交...';
      this.loadingText = '等待登录结果...';
    } catch (err) {
      this.pageLoading = false;
      this.loadingText = '';
      this.statusText = `验证码提交失败：${this.getErrorMessage(err)}`;
    }
  }

  private async submitPassword(): Promise<void> {
    if (this.pageLoading) {
      return;
    }
    if (this.password.length === 0) {
      this.statusText = '请输入密码';
      return;
    }
    this.pageLoading = true;
    this.loadingText = '正在提交密码...';
    try {
      const td = await this.prepareTdlib();
      await this.waitForAuthState(td, ['authorizationStateWaitPassword']);
      td.checkAuthenticationPassword(this.password);
      this.statusText = '密码已提交...';
      this.loadingText = '等待登录结果...';
    } catch (err) {
      this.pageLoading = false;
      this.loadingText = '';
      this.statusText = `密码提交失败：${this.getErrorMessage(err)}`;
    }
  }

  private startResendCountdown(seconds: number = 60): void {
    this.stopResendCountdown();
    if (seconds <= 0) {
      this.resendCountdown = 0;
      return;
    }
    this.resendCountdown = seconds;
    this.resendCountdownTimer = setInterval(() => {
      if (this.resendCountdown <= 1) {
        this.stopResendCountdown();
        return;
      }
      this.resendCountdown -= 1;
    }, 1000);
  }

  private stopResendCountdown(): void {
    if (this.resendCountdownTimer >= 0) {
      clearInterval(this.resendCountdownTimer);
      this.resendCountdownTimer = -1;
    }
    this.resendCountdown = 0;
  }

  private async resendCode(method: ResendCodeMethod): Promise<void> {
    if (this.resendingCode) {
      return;
    }
    if (this.resendCountdown > 0) {
      this.showToast(`${this.resendCountdown}秒后可重新发送`);
      return;
    }
    if (!this.canResendCode) {
      this.resendMenuVisible = false;
      this.statusText = '当前不能重新发送验证码，请检查 Telegram 应用内消息或稍后再试';
      this.showToast('当前不能重新发送验证码');
      return;
    }
    this.resendingCode = true;
    this.resendMenuVisible = false;
    this.loadingText = method === 'voice' ? '正在请求语音验证码...' : '正在重新发送验证码...';
    try {
      const td = await this.prepareTdlib();
      await this.waitForAuthState(td, ['authorizationStateWaitCode']);
      console.info(`[LoginPage] resendAuthenticationCode method=${method}`);
      td.resendAuthenticationCode();
      this.startResendCountdown();
      if (method === 'voice') {
        this.statusText = '正在拨打电话，请注意接听';
        this.showToast('正在拨打电话，请注意接听');
      } else {
        this.statusText = '验证码已通过短信发送至您的手机';
        this.showToast('验证码已通过短信发送至您的手机');
      }
      setTimeout(() => {
        this.resendingCode = false;
        this.loadingText = '';
      }, 1800);
    } catch (err) {
      this.resendingCode = false;
      this.loadingText = '';
      const message = this.getErrorMessage(err);
      this.statusText = `重新发送失败：${message}`;
      this.showToast(`重新发送失败：${message}`);
    }
  }

  private isBusy(): boolean {
    return this.configLoading || this.pageLoading || this.authorizationQueryPending || this.resendingCode;
  }

  private selectLoginMethod(method: LoginMethod): void {
    if (this.isBusy()) {
      return;
    }
    this.loginMethod = method;
    this.step = 3;
    this.waitingCode = false;
    this.waitingPassword = false;
    this.codeHintText = '';
    this.canResendCode = false;
    this.resendMenuVisible = false;
    this.statusText = method === 'phone' ? '请输入手机号' : '二维码登录';
    this.cacheLoginState();
    if (method === 'qr') {
      this.startQrLogin();
    }
  }

  private goBackStep(): void {
    if (this.isBusy()) {
      return;
    }
    if (this.step === 3) {
      this.activeLoginToken++;
      this.runningLoginMethod = '';
      this.authorizationQueryPending = false;
      this.qrLink = '';
      this.waitingCode = false;
      this.waitingPassword = false;
      this.canResendCode = false;
      this.resendMenuVisible = false;
      this.step = 2;
      this.statusText = '选择登录方式';
      this.cacheLoginState();
      return;
    }
    this.step = Math.max(1, this.step - 1);
    this.cacheLoginState();
  }

  private cacheLoginState(): void {
    cachedLoginStep = this.step;
    cachedLoginMethod = this.loginMethod;
    cachedPhone = this.phone;
    cachedCountryIndex = this.countryIndex;
  }

  private restoreCachedLoginState(): void {
    this.step = cachedLoginStep;
    this.loginMethod = cachedLoginMethod;
    this.phone = cachedPhone;
    this.countryIndex = cachedCountryIndex;
    this.statusText = this.step === 2 ? '选择登录方式' : (this.loginMethod === 'qr' ? '二维码登录' : '请输入手机号');
  }

  @Builder
  private NavButtons() {
    Row() {
      if (this.step > 1) {
        Button('上一步')
          .height(42)
          .borderRadius(21)
          .backgroundColor('#EEF2F7')
          .fontColor('#111111')
          .enabled(!this.isBusy())
          .onClick(() => {
            this.goBackStep();
          })
      } else {
        Blank().width(1)
      }
      Blank()
      Button(this.step === 1 ? '下一步' : (this.step === 2 ? '下一步' : '完成'))
        .visibility(this.step === 1 ? Visibility.Visible : Visibility.Hidden)
        .height(42)
        .borderRadius(21)
        .backgroundColor('#0A84FF')
        .fontColor(Color.White)
        .enabled(!this.isBusy())
        .onClick(() => {
          if (this.step === 1) {
            this.saveConfigAndNext();
          }
        })
    }
    .width('100%')
    .padding({ left: 22, right: 22, bottom: 24 })
  }

  @Builder
  private ConfigStep() {
    Column({ space: 14 }) {
      Text('配置 Telegram API')
        .fontSize(24)
        .fontWeight(FontWeight.Bold)
      TextInput({ placeholder: 'api_id', text: this.apiIdText })
        .type(InputType.Number)
        .height(48)
        .backgroundColor('#F5F7FA')
        .borderRadius(12)
        .onChange((value: string) => {
          this.apiIdText = value;
        })
      TextInput({ placeholder: 'api_hash', text: this.apiHash })
        .height(48)
        .backgroundColor('#F5F7FA')
        .borderRadius(12)
        .onChange((value: string) => {
          this.apiHash = value;
        })
    }
    .width('86%')
  }

  @Builder
  private MethodStep() {
    Column({ space: 12 }) {
      Text('选择登录方式')
        .fontSize(24)
        .fontWeight(FontWeight.Bold)
      this.MethodButton('使用手机号登录', 'phone')
      this.MethodButton('使用二维码登录', 'qr')
    }
    .width('86%')
  }

  @Builder
  private MethodButton(text: string, method: LoginMethod) {
    Button(text)
      .width('100%')
      .height(48)
      .borderRadius(12)
      .fontColor(this.loginMethod === method ? Color.White : '#111111')
      .backgroundColor(this.loginMethod === method ? '#0A84FF' : '#F5F7FA')
      .enabled(!this.isBusy())
      .onClick(() => {
        this.selectLoginMethod(method);
      })
  }

  @Builder
  private PhoneForm() {
    Column({ space: 12 }) {
      Text('手机号登录')
        .fontSize(24)
        .fontWeight(FontWeight.Bold)
      if (!this.waitingCode && !this.waitingPassword) {
        Row({ space: 8 }) {
          Select(this.getCountryOptions())
            .selected(this.countryIndex)
            .height(48)
            .layoutWeight(1)
            .onSelect((index: number) => {
            this.countryIndex = index;
            this.cacheLoginState();
          })
          TextInput({ placeholder: '手机号', text: this.phone })
            .type(InputType.PhoneNumber)
            .height(48)
            .layoutWeight(2)
            .backgroundColor('#F5F7FA')
            .borderRadius(12)
            .onChange((value: string) => {
              this.phone = value;
              this.cacheLoginState();
            })
        }
      }
      if (!this.waitingCode && !this.waitingPassword) {
        Button('继续')
          .width('100%')
          .height(46)
          .borderRadius(12)
          .backgroundColor('#0A84FF')
          .fontColor(Color.White)
          .enabled(!this.isBusy())
          .onClick(() => {
            this.startPhoneLogin();
          })
      }
      if (this.waitingCode) {
        Text(`验证码已发送至 ${this.getFullPhone()}`)
          .fontSize(13)
          .fontColor('#6B7280')
          .width('100%')
          .textAlign(TextAlign.Start)
        if (this.codeHintText.length > 0) {
          Text(this.codeHintText)
            .fontSize(12)
            .fontColor('#6B7280')
            .width('100%')
            .textAlign(TextAlign.Start)
        }
        TextInput({ placeholder: '6位验证码', text: this.code })
          .type(InputType.Number)
          .maxLength(6)
          .height(48)
          .backgroundColor('#F5F7FA')
          .borderRadius(12)
          .onChange((value: string) => {
            this.code = value.replace(/\D/g, '').slice(0, 6);
          })
        Text(this.resendCountdown > 0 ? `${this.resendCountdown}秒后可重新发送` : '可重新发送验证码')
          .fontSize(12)
          .fontColor('#6B7280')
          .width('100%')
          .textAlign(TextAlign.Start)
        Text('收不到验证码？')
          .fontSize(13)
          .fontColor(this.canResendCode && !this.isBusy() ? '#0A84FF' : '#9CA3AF')
          .width('100%')
          .textAlign(TextAlign.Start)
          .enabled(this.canResendCode && !this.isBusy())
          .onClick(() => {
            this.resendMenuVisible = !this.resendMenuVisible;
          })
        if (this.resendMenuVisible) {
          Row({ space: 8 }) {
            this.ResendMenuButton('短信接收', 'sms')
            this.ResendMenuButton('语音接收', 'voice')
          }
          .width('100%')
        }
        Button('提交验证码')
          .width('100%')
          .height(46)
          .borderRadius(12)
          .backgroundColor('#111111')
          .fontColor(Color.White)
          .enabled(!this.isBusy())
          .onClick(() => {
            this.submitCode();
          })
      }
      if (this.waitingPassword) {
        TextInput({ placeholder: '二步验证密码', text: this.password })
          .type(InputType.Password)
          .height(48)
          .backgroundColor('#F5F7FA')
          .borderRadius(12)
          .onChange((value: string) => {
            this.password = value;
          })
        Button('提交密码')
          .width('100%')
          .height(46)
          .borderRadius(12)
          .backgroundColor('#111111')
          .fontColor(Color.White)
          .enabled(!this.isBusy())
          .onClick(() => {
            this.submitPassword();
          })
      }
    }
    .width('86%')
  }

  @Builder
  private ResendMenuButton(text: string, method: ResendCodeMethod) {
    Button(text)
      .height(38)
      .layoutWeight(1)
      .borderRadius(10)
      .fontSize(13)
      .fontColor('#111111')
      .backgroundColor('#EEF2F7')
      .enabled(!this.resendingCode)
      .onClick(() => {
        this.resendCode(method);
      })
  }

  @Builder
  private QrForm() {
    Column({ space: 14 }) {
      Text('二维码扫码登录')
        .fontSize(24)
        .fontWeight(FontWeight.Bold)
      if (this.qrLink.length > 0) {
        QRCode(this.qrLink)
          .width(220)
          .height(220)
          .color('#111111')
          .backgroundColor(Color.White)
        Text('用已登录的 Telegram 扫描二维码')
          .fontSize(13)
          .fontColor('#6B7280')
        Row({ space: 8 }) {
          LoadingProgress().width(18).height(18).color('#0A84FF')
          Text('等待扫码确认...')
            .fontSize(12)
            .fontColor('#6B7280')
        }
      } else {
        LoadingProgress().width(42).height(42).color('#0A84FF')
      }
      Button('刷新二维码')
        .height(42)
        .borderRadius(21)
        .backgroundColor('#EEF2F7')
        .fontColor('#111111')
        .enabled(!this.isBusy())
        .onClick(() => {
          this.startQrLogin();
        })
    }
    .width('86%')
    .alignItems(HorizontalAlign.Center)
  }

  @Builder
  private LoginStep() {
    if (this.loginMethod === 'qr') {
      this.QrForm()
    } else {
      this.PhoneForm()
    }
  }

  @Builder
  private LoadingState() {
    if (this.isBusy()) {
      Row({ space: 8 }) {
        LoadingProgress().width(18).height(18).color('#0A84FF')
        Text(this.loadingText.length > 0 ? this.loadingText : this.statusText)
          .fontSize(12)
          .fontColor('#0A84FF')
      }
    }
  }

  build() {
    Column() {
      Column({ space: 12 }) {
        Text(this.statusText)
          .fontSize(14)
          .fontColor('#6B7280')
          .maxLines(2)
          .textAlign(TextAlign.Center)
        this.LoadingState()
        if (!this.configLoaded) {
          LoadingProgress().width(42).height(42).color('#0A84FF')
        } else if (this.step === 1) {
          this.ConfigStep()
        } else if (this.step === 2) {
          this.MethodStep()
        } else {
          this.LoginStep()
        }
      }
      .layoutWeight(1)
      .justifyContent(FlexAlign.Center)
      .alignItems(HorizontalAlign.Center)
      .width('100%')
      if (this.configLoaded) {
        this.NavButtons()
      }
    }
    .width('100%')
    .height('100%')
    .backgroundColor(Color.White)
  }
}
