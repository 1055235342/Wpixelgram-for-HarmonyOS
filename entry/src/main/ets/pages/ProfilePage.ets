// entry/src/main/ets/pages/ProfilePage.ets
import router from '@ohos.router';
import { TdFile, TdlibService, TdUpdate, TdUser } from '../common/service/TdlibService';
import { getAvatarText, getLocalPath } from '../common/utils/ChatListMappers';
import { AppLayout } from '../common/constants/AppLayout';

@Entry
@Component
export struct ProfilePage {
  @State userName: string = '加载中...';
  @State phone: string = '';
  @State avatarPath: string = '';
  @State avatarFileId: number = 0;
  @State statusText: string = '';
  @StorageLink('appDarkMode') isDarkMode: boolean = false;
  private currentUserId: number = 0;
  private td = TdlibService.getInstance();

  aboutToAppear() {
    this.td.onUpdate('user', (update: TdUpdate) => {
      const user = this.getUserFromDirectUpdate(update);
      if (user) {
        this.applyCurrentUser(user, 'getMe');
      }
    });
    this.td.onUpdate('updateUser', (update: TdUpdate) => {
      const user: TdUser | undefined = update.user;
      if (user) {
        if (this.currentUserId === 0 || user.id !== this.currentUserId) {
          console.info(`[ProfilePage] ignore updateUser id=${user.id}, current=${this.currentUserId}`);
          return;
        }
        this.applyCurrentUser(user, 'updateUser');
      }
    });
    this.td.onUpdate('file', (update: TdUpdate) => {
      if (update.file) {
        this.applyAvatarFile(update.file);
      }
    });
    this.td.onUpdate('updateFile', (update: TdUpdate) => {
      if (update.file) {
        this.applyAvatarFile(update.file);
      }
    });
    this.td.getMe();
  }

  private getUserFromDirectUpdate(update: TdUpdate): TdUser | null {
    if (update.id === undefined || update.first_name === undefined) {
      return null;
    }
    return {
      id: update.id,
      first_name: update.first_name,
      last_name: update.last_name,
      phone_number: update.phone_number ? update.phone_number : '',
      profile_photo: update.profile_photo
    };
  }

  private applyCurrentUser(user: TdUser, source: string): void {
    if (user.id !== undefined) {
      this.currentUserId = user.id;
    }
    const fullName = `${user.first_name} ${user.last_name || ''}`.trim();
    this.userName = fullName.length > 0 ? fullName : 'Telegram 用户';
    this.phone = user.phone_number ? user.phone_number : '';
    this.prepareUserAvatar(user);
    console.info(`[ProfilePage] current user loaded source=${source}, id=${this.currentUserId}, name=${this.userName}`);
  }

  private prepareUserAvatar(user: TdUser): void {
    if (!user.profile_photo || !user.profile_photo.small) {
      this.avatarFileId = 0;
      this.avatarPath = '';
      return;
    }
    const file = user.profile_photo.small;
    this.avatarFileId = file.id;
    const localPath = getLocalPath(file);
    if (localPath.length > 0) {
      this.avatarPath = localPath;
      return;
    }
    console.info(`[ProfilePage] download user avatar fileId=${file.id}`);
    this.td.downloadFile(file.id, 10);
  }

  private applyAvatarFile(file: TdFile): void {
    if (this.avatarFileId === 0 || file.id !== this.avatarFileId) {
      return;
    }
    const localPath = getLocalPath(file);
    if (localPath.length === 0) {
      return;
    }
    console.info(`[ProfilePage] apply user avatar fileId=${file.id}`);
    this.avatarPath = localPath;
  }

  private formatPhone(): string {
    if (this.phone.length === 0) {
      return '';
    }
    if (this.phone.startsWith('+')) {
      return this.phone;
    }
    if (this.phone.length === 11) {
      return `+86 ${this.phone.slice(0, 3)} ${this.phone.slice(3, 7)} ${this.phone.slice(7)}`;
    }
    return `+${this.phone}`;
  }

  private showTodo(label: string): void {
    console.info(`[ProfilePage] setting item clicked label=${label}`);
    this.statusText = `${label}暂未接入`;
    setTimeout(() => {
      this.statusText = '';
    }, 1400);
  }

  private openCacheManagement(): void {
    console.info('[ProfilePage] open cache management');
    router.pushUrl({ url: 'pages/CacheManagementPage' });
  }

  private openDataStorage(): void {
    console.info('[ProfilePage] open data storage');
    router.pushUrl({ url: 'pages/DataStoragePage' });
  }

  private openGlobalSearch(): void {
    console.info('[ProfilePage] open global search');
    router.pushUrl({ url: 'pages/GlobalSearchPage' });
  }

  @Builder
  private IconBox(icon: Resource, color: string) {
    Stack({ alignContent: Alignment.Center }) {
      Image(icon)
        .width(18)
        .height(18)
        .objectFit(ImageFit.Contain)
        .fillColor(Color.White)
    }
    .width(28)
    .height(28)
    .borderRadius(8)
    .backgroundColor(color)
  }

  @Builder
  private SettingRow(icon: Resource, color: string, title: string, value: string, dangerBadge: boolean, onClick: () => void) {
    Row() {
      this.IconBox(icon, color)
      Text(title)
        .fontSize(14)
        .fontColor('#111111')
        .textAlign(TextAlign.Start)
        .margin({ left: 12 })
        .layoutWeight(1)
      if (value.length > 0) {
        Text(value)
          .fontSize(12)
          .fontColor('#8A8F98')
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
          .margin({ right: 8 })
      }
      if (dangerBadge) {
        Text('!')
          .fontSize(11)
          .fontColor(Color.White)
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Center)
          .width(18)
          .height(18)
          .borderRadius(9)
          .backgroundColor('#FF3B30')
          .margin({ right: 10 })
      }
      Text('›')
        .fontSize(22)
        .fontColor('#B7BBC2')
        .lineHeight(22)
    }
    .width('100%')
    .height(44)
    .padding({ left: 14, right: 12 })
    .onClick(onClick)
  }

  @Builder
  private DividerLine() {
    Divider()
      .strokeWidth(1)
      .color('#E3E4E8')
      .margin({ left: 54, right: 16 })
  }

  @Builder
  private UserAvatar() {
    Stack({ alignContent: Alignment.Center }) {
      if (this.avatarPath.length > 0) {
        Image(this.avatarPath)
          .width(74)
          .height(74)
          .borderRadius(37)
          .objectFit(ImageFit.Cover)
      } else {
        Text(getAvatarText(this.userName))
          .fontSize(27)
          .fontWeight(FontWeight.Medium)
          .fontColor(Color.White)
          .textAlign(TextAlign.Center)
          .width(74)
          .height(74)
          .borderRadius(37)
          .backgroundColor('#2F80ED')
      }
    }
    .width(74)
    .height(74)
    .borderRadius(37)
    .backgroundColor(Color.White)
  }

  @Builder
  private ProfileHeader() {
    Stack({ alignContent: Alignment.Top }) {
      Column() {
        Column() {
          this.UserAvatar()
        }
        .width('100%')
        .alignItems(HorizontalAlign.Center)
        .margin({ top: AppLayout.STATUS_BAR_HEIGHT + 24 })

        Text(this.userName)
          .fontSize(23)
          .fontWeight(FontWeight.Medium)
          .fontColor('#111111')
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
          .margin({ top: 10 })
        Text(this.formatPhone())
          .fontSize(14)
          .fontColor('#898E98')
          .margin({ top: 3 })
      }
      .width('100%')
      .alignItems(HorizontalAlign.Center)
    }
    .width('100%')
    .height(AppLayout.STATUS_BAR_HEIGHT + 206)
  }

  @Builder
  private FixedTopActions() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column()
        .width('100%')
        .height(AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT)
        .backgroundColor('#F0F1F6')
        .linearGradientBlur(AppLayout.TOP_GRADIENT_BLUR_RADIUS, {
          fractionStops: [[0, 0], [1, 1]],
          direction: GradientDirection.Top
        })

      Button({ type: ButtonType.Circle }) {
        Image($r('app.media.bar_add'))
          .width(18)
          .height(18)
          .objectFit(ImageFit.Contain)
          .fillColor('#111111')
      }
      .width(38)
      .height(38)
      .borderRadius(19)
      .backgroundColor('#F8FFFFFF')
      .border({ width: 1, color: '#FFFFFFFF' })
      .shadow({ radius: 12, color: '#12000000', offsetY: 4 })
      .position({ x: 20, y: AppLayout.STATUS_BAR_HEIGHT + 16 })
      .onClick(() => {
        this.showTodo('二维码');
      })

      Button('编辑')
        .fontSize(13)
        .fontColor('#111111')
        .width(62)
        .height(38)
        .borderRadius(19)
        .backgroundColor('#F8FFFFFF')
        .border({ width: 1, color: '#FFFFFFFF' })
        .shadow({ radius: 12, color: '#12000000', offsetY: 4 })
        .position({ x: 'calc(100% - 88vp)', y: AppLayout.STATUS_BAR_HEIGHT + 16 })
        .onClick(() => {
          this.showTodo('编辑资料');
        })
    }
    .width('100%')
    .height(AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT)
    .position({ x: 0, y: 0 })
    .clip(true)
    .zIndex(10)
  }

  @Builder
  private EditCard() {
    Column() {
      this.SettingRow($r('app.media.camera'), '#0A84FF', '更改头像', '', false, () => {
        this.showTodo('更改头像');
      })
      this.DividerLine()
      this.SettingRow($r('app.media.at'), '#0A84FF', '设置用户名', '', false, () => {
        this.showTodo('设置用户名');
      })
    }
    .width('100%')
    .borderRadius(22)
    .backgroundColor(Color.White)
    .clip(true)
  }

  @Builder
  private MainCards() {
    Column({ space: 16 }) {
      Column() {
        this.SettingRow($r('app.media.user_home'), '#FF514A', '主页', '', false, () => {
          this.showTodo('我的资料');
        })
      }
      .width('100%')
      .borderRadius(20)
      .backgroundColor(Color.White)
      .clip(true)

      Column() {
        this.SettingRow($r('app.media.tag'), '#1E88F5', '收藏', '', false, () => {
          this.showTodo('我的收藏');
        })
        this.DividerLine()
        this.SettingRow($r('app.media.bar_phone'), '#32C759', '通话', '', false, () => {
          this.showTodo('最近通话');
        })
        this.DividerLine()
        this.SettingRow($r('app.media.device'), '#FF9F0A', '设备', '扫描二维码', false, () => {
          this.showTodo('设备');
        })
        this.DividerLine()
        this.SettingRow($r('app.media.group'), '#35BFEA', '分组', '', false, () => {
          this.showTodo('聊天文件夹');
        })
      }
      .width('100%')
      .borderRadius(20)
      .backgroundColor(Color.White)
      .clip(true)

      Column() {
        this.SettingRow($r('app.media.notice'), '#FF514A', '通知', '', true, () => {
          this.showTodo('通知和声音');
        })
        this.DividerLine()
        this.SettingRow($r('app.media.lock'), '#9B9DA3', '隐私', '', false, () => {
          this.showTodo('隐私和安全');
        })
        this.DividerLine()
        this.SettingRow($r('app.media.database'), '#34C759', '数据和存储', '', false, () => {
          this.openDataStorage();
        })
        this.DividerLine()
        this.SettingRow($r('app.media.appearance'), '#43C8F5', '外观', this.isDarkMode ? '开' : '关', false, () => {
          this.isDarkMode = !this.isDarkMode;
          console.info(`[ProfilePage] dark theme=${this.isDarkMode}`);
        })
        this.DividerLine()
        this.SettingRow($r('app.media.battery'), '#FFB21A', '省电', '关', false, () => {
          this.showTodo('省电');
        })
        this.DividerLine()
        this.SettingRow($r('app.media.earth'), '#AF52DE', '语言', '简体中文', false, () => {
          this.showTodo('语言');
        })
      }
      .width('100%')
      .borderRadius(20)
      .backgroundColor(Color.White)
      .clip(true)

      Column() {
        this.SettingRow($r('app.media.star'), '#A66BFF', 'Telegram 高级版', '', false, () => {
          this.showTodo('Telegram 会员');
        })
        this.DividerLine()
        this.SettingRow($r('app.media.home_page'), '#EB5FD7', 'Telegram 企业版', '', false, () => {
          this.showTodo('Telegram 企业');
        })
      }
      .width('100%')
      .borderRadius(20)
      .backgroundColor(Color.White)
      .clip(true)

      Column() {
        this.SettingRow($r('app.media.message'), '#FFB21A', 'Telegram 官方客服', '', false, () => {
          this.showTodo('Telegram 官方客服');
        })
        this.DividerLine()
        this.SettingRow($r('app.media.problem'), '#42C9F4', 'Telegram 常见问题', '', false, () => {
          this.showTodo('Telegram 常见问题');
        })
        this.DividerLine()
        this.SettingRow($r('app.media.property'), '#F7D521', 'Telegram 知识产权', '', false, () => {
          this.showTodo('Telegram 知识产权');
        })
      }
      .width('100%')
      .borderRadius(20)
      .backgroundColor(Color.White)
      .clip(true)

      Button('退出登录')
        .fontSize(16)
        .fontColor('#FF3B30')
        .width('100%')
        .height(44)
        .borderRadius(20)
        .backgroundColor(Color.White)
        .onClick(() => {
          console.info('[ProfilePage] logout clicked');
          this.td.logOut();
          router.replaceUrl({ url: 'pages/LoginPage' });
        })
    }
    .width('100%')
  }

  build() {
    Stack({ alignContent: Alignment.Bottom }) {
      Scroll() {
        Column() {
          this.ProfileHeader()
          Column() {
            this.EditCard()
          }
          .width('86%')
          Column() {
            this.MainCards()
          }
          .width('86%')
          .margin({ top: 24, bottom: AppLayout.BOTTOM_SAFE_HEIGHT + 92 })
        }
        .width('100%')
        .alignItems(HorizontalAlign.Center)
      }
      .width('100%')
      .height('100%')
      .backgroundColor('#F0F1F6')
      .edgeEffect(EdgeEffect.Spring)
      .scrollBar(BarState.Off)

      this.FixedTopActions()

      if (this.statusText.length > 0) {
        Text(this.statusText)
          .fontSize(13)
          .fontColor(Color.White)
          .padding({ left: 14, right: 14, top: 8, bottom: 8 })
          .borderRadius(16)
          .backgroundColor('#B0000000')
          .margin({ bottom: AppLayout.BOTTOM_SAFE_HEIGHT + 72 })
      }
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#F0F1F6')
  }
}
