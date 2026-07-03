import { AppLayout } from '../../../../common/constants/AppLayout';
import { CacheResourceItem } from '../../viewmodel/ChatDownloadCacheController';

@Component
export struct CacheDownloadDrawer {
  @Prop visible: boolean = false;
  @Prop items: CacheResourceItem[] = [];
  @Prop updateRevision: number = 0;
  onClose: () => void = (): void => {};
  onToggle: (fileId: number) => void = (fileId: number): void => {};
  onDelete: (fileId: number) => void = (fileId: number): void => {};
  onOpen: (item: CacheResourceItem) => void = (item: CacheResourceItem): void => {};

  private getDownloadingItems(): CacheResourceItem[] {
    return this.items.filter((item: CacheResourceItem): boolean => item.status !== 'completed');
  }

  private getCompletedItems(): CacheResourceItem[] {
    return this.items.filter((item: CacheResourceItem): boolean => item.status === 'completed');
  }

  private getProgress(item: CacheResourceItem): number {
    if (item.status === 'completed') {
      return 100;
    }
    if (item.expectedSize <= 0) {
      return item.downloadedSize > 0 ? 1 : 0;
    }
    return Math.min(99, Math.max(0, Math.floor(item.downloadedSize * 100 / item.expectedSize)));
  }

  private getProgressText(item: CacheResourceItem): string {
    if (item.expectedSize > 0) {
      return `${this.formatBytes(item.downloadedSize)} / ${this.formatBytes(item.expectedSize)}`;
    }
    return this.formatBytes(item.downloadedSize);
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

  private getIcon(item: CacheResourceItem): Resource {
    if (item.type === 'audio') {
      return $r('app.media.yuyin');
    }
    if (item.type === 'file') {
      return $r('app.media.file_attachment');
    }
    return $r('app.media.playfill');
  }

  @Builder
  private DeleteAction(fileId: number) {
    Row() {
      Text('删除')
        .fontSize(14)
        .fontColor(Color.White)
        .fontWeight(FontWeight.Bold)
    }
    .width(72)
    .height('100%')
    .justifyContent(FlexAlign.Center)
    .backgroundColor('#FF3B30')
    .onClick(() => {
      this.onDelete(fileId);
    })
  }

  @Builder
  private SectionTitle(title: string, count: number) {
    Row() {
      Text(title)
        .fontSize(15)
        .fontWeight(FontWeight.Bold)
        .fontColor('#111111')
      Text(`${count}`)
        .fontSize(12)
        .fontColor('#6B7280')
        .margin({ left: 6 })
      Blank()
    }
    .width('100%')
    .height(34)
    .padding({ left: 18, right: 18 })
  }

  @Builder
  private EmptyState(text: string) {
    Text(text)
      .fontSize(13)
      .fontColor('#9AA3AF')
      .width('100%')
      .padding({ left: 18, right: 18, top: 12, bottom: 18 })
  }

  @Builder
  private CacheRow(item: CacheResourceItem) {
    Row({ space: 12 }) {
      Stack({ alignContent: Alignment.Center }) {
        Circle()
          .width(42)
          .height(42)
          .fill('#EEF5FF')
        Image(this.getIcon(item))
          .width(22)
          .height(22)
          .objectFit(ImageFit.Contain)
          .fillColor('#0A84FF')
      }
      .width(42)
      .height(42)

      Column({ space: 5 }) {
        Text(item.fileName.length > 0 ? item.fileName : item.title)
          .fontSize(14)
          .fontWeight(FontWeight.Medium)
          .fontColor('#111111')
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
        Text(this.getProgressText(item))
          .fontSize(12)
          .fontColor('#6B7280')
        Progress({ value: this.getProgress(item), total: 100, type: ProgressType.Linear })
          .width('100%')
          .height(4)
          .color(item.status === 'paused' ? '#C7CBD1' : '#0A84FF')
          .backgroundColor('#E5E7EB')
      }
      .layoutWeight(1)
      .alignItems(HorizontalAlign.Start)

      Button({ type: ButtonType.Circle }) {
        Image(item.status === 'paused' ? $r('app.media.download') : (item.status === 'completed' ? $r('app.media.playfill') : $r('app.media.tingzhi')))
          .width(17)
          .height(17)
          .objectFit(ImageFit.Contain)
          .fillColor(item.status === 'completed' ? '#0A84FF' : Color.White)
      }
      .width(34)
      .height(34)
      .backgroundColor(item.status === 'completed' ? '#EEF5FF' : (item.status === 'paused' ? '#0A84FF' : '#111111'))
      .onClick(() => {
        if (item.status === 'completed') {
          this.onOpen(item);
        } else {
          this.onToggle(item.fileId);
        }
      })
    }
    .width('100%')
    .padding({ left: 18, right: 14, top: 12, bottom: 12 })
    .backgroundColor(Color.White)
    .onClick(() => {
      if (item.status === 'completed') {
        this.onOpen(item);
      }
    })
  }

  @Builder
  private CacheListSection(title: string, data: CacheResourceItem[]) {
    this.SectionTitle(title, data.length)
    if (data.length === 0) {
      this.EmptyState(title === '正在下载' ? '暂无正在缓存的资源' : '暂无已完成的资源')
    } else {
      ForEach(data, (item: CacheResourceItem) => {
        ListItem() {
          this.CacheRow(item)
        }
        .swipeAction({
          end: {
            builder: (): void => {
              this.DeleteAction(item.fileId)
            },
            actionAreaDistance: 72,
            onAction: (): void => {
              this.onDelete(item.fileId);
            }
          },
          edgeEffect: SwipeEdgeEffect.Spring
        })
      }, (item: CacheResourceItem): string => {
        return `${title}-${item.fileId}-${item.status}-${item.downloadedSize}-${item.expectedSize}-${item.path.length}-${this.updateRevision}`;
      })
    }
  }

  build() {
    Stack({ alignContent: Alignment.Top }) {
      Column()
        .width('100%')
        .height('100%')
        .backgroundColor('#66000000')
        .opacity(this.visible ? 1 : 0)
        .animation({ duration: 220, curve: Curve.EaseOut })
        .onClick(() => {
          this.onClose();
        })

      Column() {
        Row() {
          Text('缓存')
            .fontSize(18)
            .fontWeight(FontWeight.Bold)
            .fontColor('#111111')
          Blank()
          Button({ type: ButtonType.Circle }) {
            Text('×')
              .fontSize(24)
              .fontColor('#111111')
          }
          .width(34)
          .height(34)
          .backgroundColor('#F1F3F6')
          .onClick(() => {
            this.onClose();
          })
        }
        .width('100%')
        .height(56)
        .padding({ left: 18, right: 14 })

        Divider().color('#ECEFF3')

        List() {
          this.CacheListSection('正在下载', this.getDownloadingItems())
          ListItem() {
            Divider().color('#ECEFF3').margin({ top: 8, bottom: 8 })
          }
          this.CacheListSection('已完成', this.getCompletedItems())
          ListItem() {
            Column().height(AppLayout.BOTTOM_SAFE_HEIGHT + 20)
          }
        }
        .width('100%')
        .layoutWeight(1)
        .edgeEffect(EdgeEffect.Spring)
        .scrollBar(BarState.Off)
      }
      .width('100%')
      .height(`calc(100% - ${AppLayout.STATUS_BAR_HEIGHT}vp)`)
      .margin({ top: AppLayout.STATUS_BAR_HEIGHT })
      .borderRadius({ topLeft: 18, topRight: 18 })
      .backgroundColor(Color.White)
      .translate({ y: this.visible ? 0 : '100%' })
      .animation({ duration: 260, curve: Curve.EaseOut })
      .gesture(
        PanGesture({ direction: PanDirection.Down })
          .onActionEnd((event: GestureEvent) => {
            if (event.offsetY > 90) {
              this.onClose();
            }
          })
      )
    }
    .width('100%')
    .height('100%')
  }
}
