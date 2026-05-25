// entry/src/main/ets/pages/DataStoragePage.ets
import router from '@ohos.router';
import { AppLayout } from '../common/constants/AppLayout';

interface DataStorageItem {
  icon: Resource;
  color: string;
  title: string;
  subtitle: string;
  value: string;
  disabled: boolean;
  showSwitch: boolean;
  switchOn: boolean;
}

@Entry
@Component
struct DataStoragePage {
  @State lessDataForCalls: boolean = false;
  @State saveEditedPhotos: boolean = true;
  @State pauseMusicOnRecord: boolean = true;
  @State raiseToListen: boolean = true;
  @State statusText: string = '';

  private showTodo(title: string): void {
    this.statusText = `${title}暂未接入`;
    setTimeout(() => {
      this.statusText = '';
    }, 1200);
  }

  private openCacheManagement(): void {
    router.pushUrl({ url: 'pages/CacheManagementPage' });
  }

  @Builder
  private TopBar() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column()
        .width('100%')
        .height(AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT)
        .backgroundColor('#EEF0F5')
        .linearGradientBlur(AppLayout.TOP_GRADIENT_BLUR_RADIUS, {
          fractionStops: [[0, 0], [1, 1]],
          direction: GradientDirection.Top
        })

      Button({ type: ButtonType.Circle }) {
        Image($r('app.media.back'))
          .width(21)
          .height(21)
          .objectFit(ImageFit.Contain)
          .fillColor('#111111')
      }
      .width(44)
      .height(44)
      .borderRadius(22)
      .backgroundColor('#F8FFFFFF')
      .border({ width: 1, color: '#FFFFFFFF' })
      .shadow({ radius: 12, color: '#12000000', offsetY: 4 })
      .position({ x: 24, y: AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTROL_Y_OFFSET })
      .onClick(() => {
        router.back();
      })

      Text('数据和存储')
        .fontSize(18)
        .fontWeight(FontWeight.Bold)
        .fontColor('#111111')
        .textAlign(TextAlign.Center)
        .width('100%')
        .height(44)
        .position({ x: 0, y: AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTROL_Y_OFFSET })
    }
    .width('100%')
    .height(AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT)
    .clip(true)
  }

  @Builder
  private IconBox(icon: Resource, color: string, disabled: boolean = false) {
    Stack({ alignContent: Alignment.Center }) {
      Image(icon)
        .width(18)
        .height(18)
        .objectFit(ImageFit.Contain)
        .fillColor(Color.White)
    }
    .width(30)
    .height(30)
    .borderRadius(8)
    .backgroundColor(disabled ? '#C8CBD1' : color)
    .opacity(disabled ? 0.72 : 1)
  }

  @Builder
  private DividerLine() {
    Divider()
      .strokeWidth(1)
      .color('#E0E2E7')
      .margin({ left: 58, right: 16 })
  }

  @Builder
  private SectionTitle(title: string) {
    Text(title)
      .fontSize(13)
      .fontColor('#858A93')
      .margin({ left: 24, top: 18, bottom: 8 })
      .width('100%')
  }

  @Builder
  private Arrow() {
    Text('›')
      .fontSize(26)
      .fontColor('#B4B8C0')
      .lineHeight(26)
  }

  @Builder
  private SettingRow(item: DataStorageItem, onClick: () => void = () => {}) {
    Row() {
      this.IconBox(item.icon, item.color, item.disabled)
      Column({ space: 2 }) {
        Text(item.title)
          .fontSize(16)
          .fontColor(item.disabled ? '#9A9EA6' : '#111111')
          .textAlign(TextAlign.Start)
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
        if (item.subtitle.length > 0) {
          Text(item.subtitle)
            .fontSize(13)
            .fontColor('#8E939C')
            .textAlign(TextAlign.Start)
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
        }
      }
      .alignItems(HorizontalAlign.Start)
      .layoutWeight(1)
      .margin({ left: 14 })
      if (item.value.length > 0) {
        Text(item.value)
          .fontSize(15)
          .fontColor('#8E939C')
          .maxLines(1)
          .margin({ right: 10 })
      }
      if (item.showSwitch) {
        Toggle({ type: ToggleType.Switch, isOn: item.switchOn })
          .selectedColor('#5AC867')
          .switchPointColor(Color.White)
          .width(58)
          .height(34)
          .onChange((isOn: boolean) => {
            if (item.title === '通话时使用更少流量') {
              this.lessDataForCalls = isOn;
            } else if (item.title === '保存经编辑器修改的图片') {
              this.saveEditedPhotos = isOn;
            } else if (item.title === '录音时暂停音乐') {
              this.pauseMusicOnRecord = isOn;
            } else if (item.title === '贴近耳边听取') {
              this.raiseToListen = isOn;
            }
          })
      } else {
        this.Arrow()
      }
    }
    .width('100%')
    .height(item.subtitle.length > 0 ? 58 : 50)
    .padding({ left: 18, right: 16, top: 7, bottom: 7 })
    .opacity(item.disabled ? 0.75 : 1)
    .enabled(!item.disabled)
    .onClick(onClick)
  }

  @Builder
  private Footnote(text: string) {
    Text(text)
      .fontSize(12)
      .lineHeight(18)
      .fontColor('#858A93')
      .margin({ left: 24, right: 24, top: 8 })
      .width('100%')
  }

  @Builder
  private StatusToast() {
    if (this.statusText.length > 0) {
      Text(this.statusText)
        .fontSize(12)
        .fontColor(Color.White)
        .padding({ left: 14, right: 14, top: 8, bottom: 8 })
        .borderRadius(16)
        .backgroundColor('#CC000000')
        .position({ x: '32%', y: AppLayout.STATUS_BAR_HEIGHT + 74 })
    }
  }

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll() {
        Column() {
          Column({ space: 0 }) {
            Column() {
              this.SettingRow({
                icon: $r('app.media.database'),
                color: '#F6B13D',
                title: '存储用量',
                subtitle: '',
                value: '417.7 MB',
                disabled: false,
                showSwitch: false,
                switchOn: false
              }, () => {
                this.openCacheManagement();
              })
              this.DividerLine()
              this.SettingRow({
                icon: $r('app.media.battery'),
                color: '#AF52DE',
                title: '流量使用情况',
                subtitle: '',
                value: '1 GB',
                disabled: false,
                showSwitch: false,
                switchOn: false
              }, () => {
                this.showTodo('流量使用情况');
              })
            }
            .width('100%')
            .borderRadius(24)
            .backgroundColor(Color.White)
            .clip(true)

            this.SectionTitle('自动下载媒体文件')
            Column() {
              this.SettingRow({
                icon: $r('app.media.earth'),
                color: '#5BD36E',
                title: '使用数据流量时',
                subtitle: '媒体 (10 MB)，文件 (1.0 MB)',
                value: '',
                disabled: false,
                showSwitch: false,
                switchOn: false
              }, () => {
                this.showTodo('使用数据流量时');
              })
              this.DividerLine()
              this.SettingRow({
                icon: $r('app.media.bar_search'),
                color: '#338AF6',
                title: '使用 Wi-Fi',
                subtitle: '媒体 (15 MB)，文件 (3.0 MB)',
                value: '',
                disabled: false,
                showSwitch: false,
                switchOn: false
              }, () => {
                this.showTodo('使用 Wi-Fi');
              })
              this.DividerLine()
              this.SettingRow({
                icon: $r('app.media.kuaitui15s'),
                color: '#9A9EA6',
                title: '重置自动下载设置',
                subtitle: '',
                value: '',
                disabled: true,
                showSwitch: false,
                switchOn: false
              })
            }
            .width('100%')
            .borderRadius(24)
            .backgroundColor(Color.White)
            .clip(true)

            this.SectionTitle('保存到照片')
            Column() {
              this.SettingRow({
                icon: $r('app.media.user_home'),
                color: '#338AF6',
                title: '私聊',
                subtitle: '',
                value: '关闭',
                disabled: false,
                showSwitch: false,
                switchOn: false
              }, () => {
                this.showTodo('私聊保存到照片');
              })
              this.DividerLine()
              this.SettingRow({
                icon: $r('app.media.group'),
                color: '#5BD36E',
                title: '群聊',
                subtitle: '',
                value: '关闭',
                disabled: false,
                showSwitch: false,
                switchOn: false
              }, () => {
                this.showTodo('群聊保存到照片');
              })
              this.DividerLine()
              this.SettingRow({
                icon: $r('app.media.msg_top_group'),
                color: '#F6B13D',
                title: '频道',
                subtitle: '',
                value: '关闭',
                disabled: false,
                showSwitch: false,
                switchOn: false
              }, () => {
                this.showTodo('频道保存到照片');
              })
            }
            .width('100%')
            .borderRadius(24)
            .backgroundColor(Color.White)
            .clip(true)
            this.Footnote('自动将这些聊天中的所有新图片和视频保存至照片应用中。')

            Column() {
              this.SettingRow({
                icon: $r('app.media.bar_phone'),
                color: '#32C759',
                title: '通话时使用更少流量',
                subtitle: '',
                value: '',
                disabled: false,
                showSwitch: true,
                switchOn: this.lessDataForCalls
              })
            }
            .width('100%')
            .borderRadius(24)
            .backgroundColor(Color.White)
            .clip(true)
            .margin({ top: 18 })
            this.Footnote('在较差的网络环境下，节省数据流量能在一定程度上提升通话体验，但是音质和画质将有些许降低。')

            this.SectionTitle('其它')
            Column() {
              this.SettingRow({
                icon: $r('app.media.earth'),
                color: '#43C8F5',
                title: '打开链接',
                subtitle: '',
                value: 'Telegram',
                disabled: false,
                showSwitch: false,
                switchOn: false
              }, () => {
                this.showTodo('打开链接');
              })
              this.DividerLine()
              this.SettingRow({
                icon: $r('app.media.fenxiang'),
                color: '#338AF6',
                title: '分享选单',
                subtitle: '',
                value: '',
                disabled: false,
                showSwitch: false,
                switchOn: false
              }, () => {
                this.showTodo('分享选单');
              })
              this.DividerLine()
              this.SettingRow({
                icon: $r('app.media.camera'),
                color: '#5AC867',
                title: '保存经编辑器修改的图片',
                subtitle: '',
                value: '',
                disabled: false,
                showSwitch: true,
                switchOn: this.saveEditedPhotos
              })
              this.DividerLine()
              this.SettingRow({
                icon: $r('app.media.yuyin'),
                color: '#5AC867',
                title: '录音时暂停音乐',
                subtitle: '',
                value: '',
                disabled: false,
                showSwitch: true,
                switchOn: this.pauseMusicOnRecord
              })
              this.DividerLine()
              this.SettingRow({
                icon: $r('app.media.bar_phone'),
                color: '#5AC867',
                title: '贴近耳边听取',
                subtitle: '',
                value: '',
                disabled: false,
                showSwitch: true,
                switchOn: this.raiseToListen
              })
            }
            .width('100%')
            .borderRadius(24)
            .backgroundColor(Color.White)
            .clip(true)
            this.Footnote('开启“贴近耳边听取”功能后，将手机举到耳边就能快速收听和回复您收到的语音消息。')

            this.SectionTitle('连接类型')
            Column() {
              this.SettingRow({
                icon: $r('app.media.device'),
                color: '#9B9DA3',
                title: '代理',
                subtitle: '',
                value: '无',
                disabled: false,
                showSwitch: false,
                switchOn: false
              }, () => {
                this.showTodo('代理');
              })
            }
            .width('100%')
            .borderRadius(24)
            .backgroundColor(Color.White)
            .clip(true)
          }
          .width('100%')
          .padding({
            left: 20,
            right: 20,
            top: AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT,
            bottom: AppLayout.BOTTOM_SAFE_HEIGHT + 24
          })
        }
        .width('100%')
      }
      .width('100%')
      .height('100%')
      .backgroundColor('#EEF0F5')

      this.TopBar()
      this.StatusToast()
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#EEF0F5')
  }
}
