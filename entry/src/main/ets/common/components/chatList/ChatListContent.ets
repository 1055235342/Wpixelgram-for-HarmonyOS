import { ChatItem } from '../../model/ChatListModels';
import { ChatListRow } from './ChatListRow';

@Component
export struct ChatListContent {
  @Prop statusText: string = '';
  @Prop chats: ChatItem[] = [];
  @Prop selectedChatId: number = 0;
  @Prop searchTransition: boolean = false;
  @State headerCollapsed: boolean = false;
  @State selectedTopCategoryIndex: number = 0;
  @State pageDragOffsetX: number = 0;
  @State pageDragging: boolean = false;
  @State contentWidth: number = 390;
  chatScroller: Scroller = new Scroller();
  pageSwiperController: SwiperController = new SwiperController();
  onOpenChat: (item: ChatItem) => void = (item: ChatItem): void => {};
  onLongPressChat: (item: ChatItem, centerX: number, centerY: number) => void =
    (item: ChatItem, centerX: number, centerY: number): void => {};
  onSearchClick: () => void = (): void => {};
  onLoadMoreChats: () => void = (): void => {};

  private getStatusBarPadding(): number {
    return 30;
  }

  private getHeaderHeight(): number {
    return (this.headerCollapsed ? 88 : 132) + this.getStatusBarPadding();
  }

  private getVisibleChats(): ChatItem[] {
    return this.chats;
  }

  private getPinnedListBackgroundColor(): ResourceColor {
    const visibleChats = this.getVisibleChats();
    if (visibleChats.length > 0 && visibleChats[0].isPinned) {
      return '#F1F3F6';
    }
    return Color.White;
  }

  private switchTopCategory(index: number): void {
    if (this.selectedTopCategoryIndex === index) {
      return;
    }
    console.info(`[ChatListContent] switch top category index=${index}`);
    this.selectedTopCategoryIndex = index;
    this.pageDragOffsetX = 0;
    this.pageSwiperController.changeIndex(index, true);
  }

  private getPageWidth(): number {
    return this.contentWidth > 0 ? this.contentWidth : 390;
  }

  private getTrackOffsetX(): number {
    return -(this.selectedTopCategoryIndex * this.getPageWidth()) + this.pageDragOffsetX;
  }

  private clampPageDrag(offsetX: number): number {
    const pageWidth = this.getPageWidth();
    if (this.selectedTopCategoryIndex === 0) {
      if (offsetX > 0) {
        return Math.min(offsetX * 0.25, 36);
      }
      return Math.max(offsetX, -pageWidth);
    }
    if (offsetX < 0) {
      return Math.max(offsetX * 0.25, -36);
    }
    return Math.min(offsetX, pageWidth);
  }

  private handlePageDrag(offsetX: number): void {
    this.pageDragging = true;
    this.pageDragOffsetX = this.clampPageDrag(offsetX);
  }

  private finishPageDrag(offsetX: number): void {
    const threshold = Math.min(this.getPageWidth() * 0.28, 112);
    this.pageDragging = false;
    if (offsetX < -threshold) {
      this.switchTopCategory(1);
    } else if (offsetX > threshold) {
      this.switchTopCategory(0);
    } else {
      this.pageDragOffsetX = 0;
    }
  }

  private updateContentWidth(width: Length): void {
    if (typeof width === 'number' && width > 0) {
      this.contentWidth = width;
    } else if (typeof width === 'string') {
      const parsedWidth = parseFloat(width);
      if (!Number.isNaN(parsedWidth) && parsedWidth > 0) {
        this.contentWidth = parsedWidth;
      }
    }
  }

  private updateHeaderByOffset(): void {
    const offset: OffsetResult = this.chatScroller.currentOffset();
    if (offset.yOffset > 24 && !this.headerCollapsed) {
      this.headerCollapsed = true;
    } else if (offset.yOffset <= 4 && this.headerCollapsed) {
      this.headerCollapsed = false;
    }
  }

  @Builder
  private TopIconButton(icon: Resource) {
    Button({ type: ButtonType.Circle }) {
      Image(icon)
        .width(20)
        .height(20)
        .objectFit(ImageFit.Contain)
    }
    .width(30)
    .height(30)
    .backgroundColor(Color.Transparent)
  }

  @Builder
  private Toolbar() {
    Row() {
      Button('编辑')
        .fontSize(14)
        .fontWeight(FontWeight.Bold)
        .fontColor('#111111')
        .height(34)
        .padding({ left: 14, right: 14 })
        .borderRadius(17)
        .backgroundColor('#F9F9F9')
        .shadow({ radius: 10, color: '#14000000', offsetY: 2 })
        .onClick(() => {
          console.info('[ChatListContent] edit clicked');
        })

      Row({ space: 7 }) {
        LoadingProgress()
          .width(22)
          .height(22)
          .color('#0A84FF')
        Text('连接中...')
          .fontSize(16)
          .fontWeight(FontWeight.Bold)
          .fontColor('#111111')
      }
      .layoutWeight(1)
      .justifyContent(FlexAlign.Center)

      Row({ space: 2 }) {
        this.TopIconButton($r('app.media.msg_top_add'))
        this.TopIconButton($r('app.media.msg_top_group'))
      }
      .height(34)
      .padding({ left: 8, right: 8 })
      .borderRadius(17)
      .backgroundColor('#F9F9F9')
      .shadow({ radius: 10, color: '#14000000', offsetY: 2 })
    }
    .width('100%')
    .height(42)
    .padding({ left: 14, right: 14 })
    .alignItems(VerticalAlign.Center)
  }

  @Builder
  private SearchPill() {
    Row() {
      Image($r('app.media.bar_search'))
        .width(18)
        .height(18)
        .objectFit(ImageFit.Contain)
        .opacity(0.45)
        .margin({ right: 6 })
      Text('搜索')
        .fontSize(15)
        .fontColor('#9A9A9A')
    }
    .width('100%')
    .height(this.headerCollapsed ? 0 : 34)
    .justifyContent(FlexAlign.Center)
    .borderRadius(17)
    .backgroundColor('#E9E9E9')
    .opacity(this.headerCollapsed ? 0 : 1)
    .translate({ y: this.headerCollapsed ? -12 : 0 })
    .animation({ duration: 220, curve: Curve.EaseOut })
    .onClick(() => {
      console.info('[ChatListContent] search pill clicked');
      this.onSearchClick();
    })
  }

  @Builder
  private TopSegmentItem(label: string, index: number) {
    Text(label)
      .fontSize(15)
      .fontWeight(FontWeight.Bold)
      .fontColor('#111111')
      .textAlign(TextAlign.Center)
      .height(32)
      .borderRadius(16)
      .backgroundColor(this.selectedTopCategoryIndex === index ? '#E9E9E9' : Color.Transparent)
      .layoutWeight(1)
      .onClick(() => {
        console.info(`[ChatListContent] top category clicked index=${index}, label=${label}`);
        this.switchTopCategory(index);
      })
  }

  @Builder
  private SegmentBar() {
    Row() {
      this.TopSegmentItem('对话', 0)
      this.TopSegmentItem('资源堂📌', 1)
    }
    .width('100%')
    .height(38)
    .padding({ left: 3, right: 3 })
    .borderRadius(19)
    .backgroundColor('#F8F8F8')
    .border({ width: 1, color: '#FFFFFFFF' })
    .shadow({ radius: this.headerCollapsed ? 10 : 6, color: '#12000000', offsetY: this.headerCollapsed ? 3 : 1 })
  }

  @Builder
  private HeaderOverlay() {
    Stack({ alignContent: Alignment.Top }) {
      Column()
        .width('100%')
        .height(this.getHeaderHeight())
        .backgroundColor(this.headerCollapsed ? '#B8FFFFFF' : '#F8FFFFFF')
        .linearGradient({
          direction: GradientDirection.Bottom,
          colors: [
            [this.headerCollapsed ? '#E8FFFFFF' : '#FFFFFFFF', 0.0],
            [this.headerCollapsed ? '#B8FFFFFF' : '#FFFFFFFF', 0.66],
            [this.getPinnedListBackgroundColor(), 1.0]
          ]
        })
        .linearGradientBlur(this.headerCollapsed ? 24 : 0, {
          fractionStops: [
            [0.0, 0.0],
            [0.42, 0.55],
            [1.0, 1.0]
          ],
          direction: GradientDirection.Top
        })

      Column() {
        this.Toolbar()
        Row() {
          this.SearchPill()
        }
        .width('100%')
        .padding({ left: 14, right: 14 })
        .margin({ top: this.headerCollapsed ? 0 : 4 })
        Row() {
          this.SegmentBar()
        }
        .width('100%')
        .padding({ left: 14, right: 14 })
        .margin({ top: this.headerCollapsed ? 4 : 8 })
      }
      .width('100%')
      .height(this.getHeaderHeight())
      .padding({ top: this.getStatusBarPadding()})
    }
    .width('100%')
    .height(this.getHeaderHeight())
    .animation({ duration: 220, curve: Curve.EaseOut })
  }

  @Builder
  private DialogListPage() {
    List({ scroller: this.chatScroller }) {
      ListItem() {
        Column()
          .height(132 + this.getStatusBarPadding())
          .backgroundColor(this.getPinnedListBackgroundColor())
      }
      if (this.statusText.length > 0) {
        ListItem() {
          Text(this.statusText)
            .fontSize(14)
            .fontColor('#6B7280')
            .width('100%')
            .padding({ left: 18, right: 18, top: 10, bottom: 6 })
        }
      }
      if (this.getVisibleChats().length === 0) {
        ListItem() {
          Column() {
            Text('暂无会话')
              .fontSize(18)
              .fontWeight(FontWeight.Bold)
              .fontColor('#222222')
            Text('下拉刷新或稍后再试')
              .fontSize(14)
              .fontColor('#8A96A8')
              .margin({ top: 8 })
          }
          .width('100%')
          .height(320)
          .justifyContent(FlexAlign.Center)
        }
      } else {
        ForEach(this.getVisibleChats(), (item: ChatItem) => {
          ListItem() {
            ChatListRow({
              item: item,
              selectedChatId: this.selectedChatId,
              onOpenChat: (chatItem: ChatItem): void => {
                this.onOpenChat(chatItem);
              },
              onLongPressChat: (chatItem: ChatItem, centerX: number, centerY: number): void => {
                this.onLongPressChat(chatItem, centerX, centerY);
              }
            })
          }
        }, (item: ChatItem) => `${item.id}`)
      }
    }
    .width('100%')
    .height('100%')
    .edgeEffect(EdgeEffect.Spring)
    .contentEndOffset(118)
    .scrollBar(BarState.Off)
    .onReachEnd(() => {
      if (this.selectedTopCategoryIndex === 0) {
        console.info('[ChatListContent] list reach end, request more chats');
        this.onLoadMoreChats();
      }
    })
    .onDidScroll((scrollOffset: number, scrollState: ScrollState) => {
      this.updateHeaderByOffset();
    })
  }

  @Builder
  private ResourceHallPage() {
    Column() {
      Column()
        .height(132 + this.getStatusBarPadding())

      Row() {
        Text('分组有更新，您可以加入 9 个新对话')
          .fontSize(15)
          .fontColor('#0A84FF')
          .layoutWeight(1)
          .textAlign(TextAlign.Center)
        Button({ type: ButtonType.Circle }) {
          Text('×')
            .fontSize(20)
            .fontColor('#0A84FF')
        }
        .width(28)
        .height(28)
        .backgroundColor(Color.Transparent)
      }
      .width('100%')
      .height(38)
      .padding({ left: 18, right: 10 })
      .border({ width: { bottom: 1 }, color: '#D8D8D8' })

      Column() {
        Text('📂')
          .fontSize(66)
        Text('此分组是空的')
          .fontSize(19)
          .fontWeight(FontWeight.Bold)
          .fontColor('#111111')
          .margin({ top: 14 })
        Text('当前分组没有添加对话。')
          .fontSize(14)
          .fontColor('#9A9A9A')
          .margin({ top: 8 })
      }
      .width('100%')
      .layoutWeight(1)
      .justifyContent(FlexAlign.Center)
      .padding({ bottom: 58 })

      Button('编辑分组')
        .fontSize(17)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .height(48)
        .width('54%')
        .borderRadius(12)
        .backgroundColor('#0A8DFF')
        .margin({ bottom: 148 })
        .onClick(() => {
          console.info('[ChatListContent] edit resource group clicked');
        })
    }
    .width('100%')
    .height('100%')
    .backgroundColor(Color.White)
  }

  build() {
    Stack({ alignContent: Alignment.Top }) {
      Stack() {
        Swiper(this.pageSwiperController) {
          Stack() {
            this.DialogListPage()
          }
          .width('100%')
          .height('100%')

          Stack() {
            this.ResourceHallPage()
          }
          .width('100%')
          .height('100%')
        }
        .width('100%')
        .height('100%')
        .index(this.selectedTopCategoryIndex)
        .indicator(false)
        .loop(false)
        .duration(220)
        .onChange((index: number) => {
          console.info(`[ChatListContent] swiper changed index=${index}`);
          this.selectedTopCategoryIndex = index;
          this.pageDragOffsetX = 0;
        })
      }
      .width('100%')
      .height('100%')
      .clip(true)

      this.HeaderOverlay()
    }
    .width('100%')
    .height('100%')
    .opacity(this.searchTransition ? 0 : 1)
    .translate({ y: this.searchTransition ? -54 : 0 })
    .animation({ duration: 280, curve: Curve.EaseOut })
  }
}
