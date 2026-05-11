// entry/src/main/ets/pages/ProfilePage.ets
import router from '@ohos.router';
import { TdlibService, TdUpdate, TdUser } from '../common/service/TdlibService';

@Entry
@Component
export struct ProfilePage {
  @State userName: string = '加载中...';
  @State phone: string = '';
  private td = TdlibService.getInstance();

  aboutToAppear() {
    this.td.onUpdate('updateUser', (update: TdUpdate) => {
      const user: TdUser | undefined = update.user;
      if (user) {
        this.userName = user.first_name + ' ' + (user.last_name || '');
        this.phone = user.phone_number;
      }
    });
    this.td.getMe();
  }

  build() {
    Column() {
      Row() {
        Text('User').fontSize(24)
        Text(this.userName).fontSize(20).margin({ left: 12 })
      }
      .width('100%').padding(20)

      Button('缓存管理')
        .onClick(() => {
          console.info('[ProfilePage] button 缓存管理 clicked');
          router.pushUrl({ url: 'pages/CacheManagementPage' });
        })
      Button('搜索消息')
        .onClick(() => {
          console.info('[ProfilePage] button 搜索消息 clicked');
          router.pushUrl({ url: 'pages/GlobalSearchPage' });
        })
      Button('退出登录')
        .onClick(() => {
          console.info('[ProfilePage] button 退出登录 clicked');
          this.td.logOut();
          router.replaceUrl({ url: 'pages/LoginPage' });
        })
    }
    .width('100%').height('100%')
  }
}
