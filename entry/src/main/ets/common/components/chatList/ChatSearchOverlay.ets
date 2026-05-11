import { ChatItem } from '../../model/ChatListModels';
import { ChatListContent } from './ChatListContent';

@Component
export struct ChatSearchOverlay {
  @Prop visible: boolean = false;
  @Prop chats: ChatItem[] = [];
  @Prop selectedChatId: number = 0;
  onClose: () => void = (): void => {};
  onOpenChat: (item: ChatItem) => void = (item: ChatItem): void => {};
  @State selectedCategory: string = '对话';
  @State showResults: boolean = false;
  @State inputExpanded: boolean = false;
  private resultScroller: Scroller = new Scroller();
  private categories: string[] = ['对话', '频道', '应用', '帖子', '媒体', '链接', '文件', '音乐', '语言'];

  aboutToAppear() {
    this.inputExpanded = false;
  }

  private selectCategory(category: string): void {
    console.info(`[ChatSearchOverlay] category clicked category=${category}`);
    this.selectedCategory = category;
    this.showResults = true;
  }

  private getFilteredChats(): ChatItem[] {
    if (this.selectedCategory === '对话') {
      return this.chats;
    }
    if (this.selectedCategory === '频道') {
      return this.chats.filter((item: ChatItem): boolean => item.category === '频道');
    }
    if (this.selectedCategory === '应用') {
      return this.chats.filter((item: ChatItem): boolean => item.category === '机器人');
    }
    if (this.selectedCategory === '帖子') {
      return this.chats.filter((item: ChatItem): boolean => item.category === '群组' || item.category === '频道');
    }
    if (this.selectedCategory === '媒体') {
      return this.chats.filter((item: ChatItem): boolean => this.isMediaPreview(item.lastMessage));
    }
    if (this.selectedCategory === '链接') {
      return this.chats.filter((item: ChatItem): boolean => this.hasLinkPreview(item.lastMessage));
    }
    if (this.selectedCategory === '文件') {
      return this.chats.filter((item: ChatItem): boolean => item.lastMessage.indexOf('[文件]') >= 0);
    }
    if (this.selectedCategory === '音乐') {
      return this.chats.filter((item: ChatItem): boolean => this.hasMusicPreview(item.lastMessage));
    }
    if (this.selectedCategory === '语言') {
      return this.chats.filter((item: ChatItem): boolean => item.lastMessage.indexOf('[语音]') >= 0 ||
        item.lastMessage.indexOf('语音') >= 0);
    }
    return this.chats;
  }

  private isMediaPreview(text: string): boolean {
    return text.indexOf('[图片]') >= 0 ||
      text.indexOf('[视频]') >= 0 ||
      text.indexOf('GIF') >= 0 ||
      text.indexOf('[贴纸]') >= 0;
  }

  private hasLinkPreview(text: string): boolean {
    const lowerText = text.toLowerCase();
    return lowerText.indexOf('http://') >= 0 ||
      lowerText.indexOf('https://') >= 0 ||
      lowerText.indexOf('t.me/') >= 0 ||
      lowerText.indexOf('www.') >= 0;
  }

  private hasMusicPreview(text: string): boolean {
    return text.indexOf('音乐') >= 0 ||
      text.indexOf('歌曲') >= 0 ||
      text.indexOf('音频') >= 0 ||
      text.toLowerCase().indexOf('music') >= 0;
  }

  @Builder
  private CategoryChip(category: string) {
    Text(category)
      .fontSize(15)
      .fontWeight(this.selectedCategory === category ? FontWeight.Bold : FontWeight.Medium)
      .fontColor('#111111')
      .height(34)
      .padding({ left: 14, right: 14 })
      .borderRadius(17)
      .backgroundColor(this.selectedCategory === category ? '#DCDCDC' : Color.Transparent)
      .onClick(() => {
        this.selectCategory(category);
      })
  }

  @Builder
  private SearchInputBar() {
    Row({ space: 8 }) {
      Row() {
        Image($r('app.media.bar_search'))
          .width(20)
          .height(20)
          .objectFit(ImageFit.Contain)
          .opacity(0.58)
          .margin({ left: 14, right: 8 })
        TextInput({ placeholder: '搜索' })
          .fontSize(16)
          .fontColor('#1F2937')
          .placeholderColor('#9B9B9B')
          .backgroundColor(Color.Transparent)
          .layoutWeight(1)
      }
      .height(46)
      .width(this.inputExpanded ? '82%' : 54)
      .borderRadius(23)
      .backgroundColor('#FAFAFA')
      .border({ width: 1, color: '#F2F2F2' })
      .shadow({ radius: 12, color: '#12000000', offsetY: 3 })
      .clip(true)
      .animation({ duration: 260, curve: Curve.EaseOut })

      Button({ type: ButtonType.Circle }) {
        Image($r('app.media.close'))
          .width(24)
          .height(24)
          .objectFit(ImageFit.Contain)
      }
      .width(54)
      .height(54)
      .borderRadius(27)
      .backgroundColor('#FAFAFA')
      .border({ width: 1, color: '#F2F2F2' })
      .shadow({ radius: 10, color: '#12000000', offsetY: 3 })
      .opacity(this.inputExpanded ? 1 : 0)
      .animation({ duration: 180, curve: Curve.EaseOut })
      .onClick(() => {
        console.info('[ChatSearchOverlay] close clicked');
        this.onClose();
      })
    }
    .width('100%')
    .padding({ left: 16, right: 10 })
    .justifyContent(FlexAlign.End)
  }

  @Builder
  private BottomBlurScrim() {
    Column()
      .width('100%')
      .height(160)
      .linearGradient({
        direction: GradientDirection.Bottom,
        colors: [
          ['#00FFFFFF', 0.0],
          ['#B8FFFFFF', 0.66],
          ['#FFFFFFFF', 1.0]
        ]
      })
      .linearGradientBlur(18, {
        fractionStops: [
          [0.0, 0.0],
          [0.45, 0.52],
          [1.0, 1.0]
        ],
        direction: GradientDirection.Bottom
      })
  }

  build() {
    Stack({ alignContent: Alignment.Bottom }) {
      Column() {
        if (this.showResults) {
          ChatListContent({
            statusText: '',
            chats: this.getFilteredChats(),
            selectedChatId: this.selectedChatId,
            chatScroller: this.resultScroller,
            onOpenChat: (item: ChatItem): void => {
              this.onOpenChat(item);
            }
          })
        } else {
          Blank()
        }
      }
      .width('100%')
      .height('100%')
      .opacity(this.showResults ? 1 : 0.12)
      .animation({ duration: 220, curve: Curve.EaseOut })

      this.BottomBlurScrim()

      Column() {
        Scroll() {
          Row() {
            Row() {
              ForEach(this.categories, (category: string) => {
                this.CategoryChip(category)
              }, (category: string) => category)
            }
            .height(42)
            .padding({ left: 4, right: 4 })
            .borderRadius(21)
            .backgroundColor('#FAFAFA')
            .border({ width: 1, color: '#F2F2F2' })
            .shadow({ radius: 12, color: '#12000000', offsetY: 3 })
          }
          .padding({ left: 16, right: 16 })
        }
        .width('100%')
        .height(50)
        .scrollable(ScrollDirection.Horizontal)
        .scrollBar(BarState.Off)
        .margin({ bottom: 8 })
        .opacity(this.inputExpanded ? 1 : 0)
        .translate({ y: this.inputExpanded ? 0 : 12 })
        .animation({ duration: 220, curve: Curve.EaseOut })

        this.SearchInputBar()
      }
      .width('100%')
      .padding({ bottom: 28 })
    }
    .width('100%')
    .height('100%')
    .backgroundColor(Color.Transparent)
    .opacity(this.visible ? 1 : 0)
    .translate({ y: this.visible ? 0 : 72 })
    .animation({ duration: 260, curve: Curve.EaseOut })
    .onAppear(() => {
      this.inputExpanded = true;
    })
  }
}
