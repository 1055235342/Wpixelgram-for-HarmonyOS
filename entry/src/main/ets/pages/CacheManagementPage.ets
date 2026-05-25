// entry/src/main/ets/pages/CacheManagementPage.ets
import router from '@ohos.router';
import { AppLayout } from '../common/constants/AppLayout';
import {
  TdChat,
  TdlibService,
  TdStorageStatisticsByChat,
  TdStorageStatisticsByFileType,
  TdUpdate
} from '../common/service/TdlibService';

interface CacheCategoryItem {
  icon: Resource;
  color: string;
  title: string;
  percent: string;
  size: string;
  sizeBytes: number;
  expandable: boolean;
  fileType: string;
}

interface AutoDeleteItem {
  icon: Resource;
  color: string;
  title: string;
  value: string;
}

interface ChatStorageItem {
  chatId: number;
  avatarText: string;
  avatarColor: string;
  title: string;
  size: string;
  selected: boolean;
}

interface ChatProfileRouteParams {
  chatId?: number | string;
  title?: string;
  avatarText?: string;
  avatarColor?: string;
}

interface FileStorageItem {
  fileType: string;
  title: string;
  date: string;
  size: string;
  selected: boolean;
}

interface MediaStorageItem {
  fileType: string;
  color: string;
  size: string;
  selected: boolean;
}

@Entry
@Component
struct CacheManagementPage {
  @State totalText: string = '417.7 MB';
  @State statusText: string = '';
  @State selectedDetailTab: number = 0;
  @State categoryItems: CacheCategoryItem[] = [];
  @State chatStorageItems: ChatStorageItem[] = [];
  @State fileStorageItems: FileStorageItem[] = [];
  @State mediaStorageItems: MediaStorageItem[] = [];
  @State selectedClearText: string = '清除所选';
  @State activeChatMenuId: number = 0;
  @State detailDrawerVisible: boolean = false;
  @State detailDrawerTitle: string = '';
  private totalBytes: number = 0;
  private chatTitles: Map<number, string> = new Map();
  private td = TdlibService.getInstance();
  private chartSettings: RenderingContextSettings = new RenderingContextSettings(true);
  private chartContext: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.chartSettings);

  aboutToAppear() {
    this.td.onUpdate('storageStatistics', (update: TdUpdate) => {
      this.applyStorageStatistics(update);
    });
    this.td.onUpdate('updateStorageStatisticsFast', (update: TdUpdate) => {
      this.applyStorageStatistics(update);
    });
    this.td.onUpdate('chat', (update: TdUpdate) => {
      this.applyChatTitleUpdate(update);
    });
    this.seedStoragePlaceholders();
    this.td.getStorageStatistics(100);
  }

  private seedStoragePlaceholders(): void {
    if (this.categoryItems.length === 0) {
      this.categoryItems = this.buildCategoryItems([
        { file_type: { type: 'fileTypeVideo' }, size: 321.3 * 1024 * 1024 },
        { file_type: { type: 'fileTypeOther' }, size: 66.7 * 1024 * 1024 },
        { file_type: { type: 'fileTypePhoto' }, size: 12.1 * 1024 * 1024 },
        { file_type: { type: 'fileTypeSticker' }, size: 7.6 * 1024 * 1024 },
        { file_type: { type: 'fileTypeDocument' }, size: 9.8 * 1024 * 1024 }
      ]);
    }
    if (this.chatStorageItems.length === 0) {
      this.chatStorageItems = [
        { chatId: 0, avatarText: '三', avatarColor: '#C66AE8', title: '三级 AV（经典）', size: '116.9 MB', selected: false },
        { chatId: 0, avatarText: '●', avatarColor: '#637BFF', title: '🔴 动漫资源', size: '64 MB', selected: false },
        { chatId: 0, avatarText: '糖', avatarColor: '#88D479', title: '糖心丨 AV 小站', size: '40.3 MB', selected: false }
      ];
    }
  }

  private applyStorageStatistics(update: TdUpdate): void {
    let total = update.size !== undefined ? update.size : 0;
    if (total <= 0 && update.files_size !== undefined) {
      total = update.files_size + (update.database_size ? update.database_size : 0) + (update.log_size ? update.log_size : 0);
    }
    if (total <= 0 && update.by_chat) {
      update.by_chat.forEach((item: TdStorageStatisticsByChat) => {
        total += item.size;
      });
    }
    if (total > 0) {
      this.totalBytes = total;
      this.totalText = this.formatBytes(total);
    }
    if (update.by_file_type && update.by_file_type.length > 0) {
      this.categoryItems = this.buildCategoryItems(update.by_file_type);
      this.fileStorageItems = this.buildFileItems(update.by_file_type);
      this.mediaStorageItems = this.buildMediaItems(update.by_file_type);
    }
    if (update.by_chat && update.by_chat.length > 0) {
      this.chatStorageItems = this.buildChatItems(update.by_chat);
    }
    this.updateSelectedClearText();
    this.drawChart();
  }

  private applyChatTitleUpdate(update: TdUpdate): void {
    if (update.id === undefined || update.title === undefined) {
      return;
    }
    this.chatTitles.set(update.id, update.title);
    const index = this.chatStorageItems.findIndex((item: ChatStorageItem): boolean => item.chatId === update.id);
    if (index < 0) {
      return;
    }
    const nextItems = this.chatStorageItems.slice();
    nextItems[index] = {
      chatId: nextItems[index].chatId,
      avatarText: this.getAvatarText(update.title),
      avatarColor: nextItems[index].avatarColor,
      title: update.title,
      size: nextItems[index].size,
      selected: nextItems[index].selected
    };
    this.chatStorageItems = nextItems;
  }

  private formatBytes(size: number): string {
    const mb = size / 1024 / 1024;
    if (mb >= 1024) {
      return `${(mb / 1024).toFixed(1)} GB`;
    }
    return `${mb.toFixed(1)} MB`;
  }

  private formatPercent(size: number): string {
    if (this.totalBytes <= 0) {
      return '';
    }
    const percent = size * 100 / this.totalBytes;
    return `${percent >= 10 ? percent.toFixed(1) : percent.toFixed(1)}%`;
  }

  private getFileTypeName(fileType: string): string {
    if (fileType === 'fileTypeVideo' || fileType === 'fileTypeVideoNote') {
      return '视频';
    }
    if (fileType === 'fileTypePhoto' || fileType === 'fileTypeProfilePhoto') {
      return '图片';
    }
    if (fileType === 'fileTypeAnimation') {
      return '动图';
    }
    if (fileType === 'fileTypeDocument') {
      return '文件';
    }
    if (fileType === 'fileTypeSticker') {
      return '贴纸';
    }
    if (fileType === 'fileTypeAudio' || fileType === 'fileTypeVoiceNote') {
      return '音乐';
    }
    return '其他';
  }

  private getFileType(type: TdStorageStatisticsByFileType): string {
    return type.file_type && type.file_type.type ? type.file_type.type : 'fileTypeOther';
  }

  private isMediaType(fileType: string): boolean {
    return fileType === 'fileTypeVideo' || fileType === 'fileTypeVideoNote' ||
      fileType === 'fileTypePhoto' || fileType === 'fileTypeAnimation';
  }

  private isFileType(fileType: string): boolean {
    return fileType === 'fileTypeDocument' || fileType === 'fileTypeAudio' || fileType === 'fileTypeVoiceNote';
  }

  private getAvatarText(title: string): string {
    const trimmed = title.trim();
    return trimmed.length > 0 ? trimmed.substring(0, 1) : 'T';
  }

  private getAvatarColor(index: number): string {
    const colors: string[] = ['#C66AE8', '#637BFF', '#88D479', '#6C78FF', '#F5BE66', '#63D4D2', '#81B6FF', '#F56A68'];
    return colors[index % colors.length];
  }

  private buildCategoryItems(items: TdStorageStatisticsByFileType[]): CacheCategoryItem[] {
    const result: CacheCategoryItem[] = [];
    items.slice().sort((left: TdStorageStatisticsByFileType, right: TdStorageStatisticsByFileType): number => right.size - left.size)
      .forEach((item: TdStorageStatisticsByFileType, index: number) => {
        if (item.size <= 0) {
          return;
        }
        const fileType = this.getFileType(item);
        result.push({
          icon: this.getCategoryIcon(fileType),
          color: this.getCategoryColor(fileType, index),
          title: this.getFileTypeName(fileType),
          percent: this.formatPercent(item.size),
          size: this.formatBytes(item.size),
          sizeBytes: item.size,
          expandable: false,
          fileType: fileType
        });
      });
    return result.slice(0, 6);
  }

  private buildChatItems(items: TdStorageStatisticsByChat[]): ChatStorageItem[] {
    const selectedMap: Map<number, boolean> = new Map();
    this.chatStorageItems.forEach((item: ChatStorageItem) => {
      selectedMap.set(item.chatId, item.selected);
    });
    return items.slice().sort((left: TdStorageStatisticsByChat, right: TdStorageStatisticsByChat): number => right.size - left.size)
      .slice(0, 80)
      .map((item: TdStorageStatisticsByChat, index: number): ChatStorageItem => {
        const title = this.chatTitles.get(item.chat_id) || `Chat ${item.chat_id}`;
        if (!this.chatTitles.has(item.chat_id)) {
          this.td.getChat(item.chat_id);
        }
        return {
          chatId: item.chat_id,
          avatarText: this.getAvatarText(title),
          avatarColor: this.getAvatarColor(index),
          title: title,
          size: this.formatBytes(item.size),
          selected: selectedMap.get(item.chat_id) === true
        };
      });
  }

  private buildFileItems(items: TdStorageStatisticsByFileType[]): FileStorageItem[] {
    return items.filter((item: TdStorageStatisticsByFileType): boolean => this.isFileType(this.getFileType(item)) && item.size > 0)
      .sort((left: TdStorageStatisticsByFileType, right: TdStorageStatisticsByFileType): number => right.size - left.size)
      .map((item: TdStorageStatisticsByFileType): FileStorageItem => {
        const fileType = this.getFileType(item);
        return {
          fileType: fileType,
          title: `${this.getFileTypeName(fileType)}缓存`,
          date: `${item.count ? item.count : 0} 个缓存文件`,
          size: this.formatBytes(item.size),
          selected: false
        };
      });
  }

  private buildMediaItems(items: TdStorageStatisticsByFileType[]): MediaStorageItem[] {
    const colors: string[] = ['#121212', '#B89A8E', '#171717', '#315490', '#B9917C', '#D3C7C4'];
    return items.filter((item: TdStorageStatisticsByFileType): boolean => this.isMediaType(this.getFileType(item)) && item.size > 0)
      .sort((left: TdStorageStatisticsByFileType, right: TdStorageStatisticsByFileType): number => right.size - left.size)
      .map((item: TdStorageStatisticsByFileType, index: number): MediaStorageItem => {
        return {
          fileType: this.getFileType(item),
          color: colors[index % colors.length],
          size: this.formatBytes(item.size),
          selected: false
        };
      });
  }

  private getCategoryIcon(fileType: string): Resource {
    if (fileType === 'fileTypeVideo' || fileType === 'fileTypeAnimation') {
      return $r('app.media.playfill');
    }
    if (fileType === 'fileTypePhoto') {
      return $r('app.media.camera');
    }
    if (fileType === 'fileTypeSticker') {
      return $r('app.media.tag');
    }
    if (fileType === 'fileTypeDocument') {
      return $r('app.media.database');
    }
    return $r('app.media.device');
  }

  private getCategoryColor(fileType: string, index: number): string {
    if (fileType === 'fileTypeVideo' || fileType === 'fileTypeVideoNote') {
      return '#4379EE';
    }
    if (fileType === 'fileTypePhoto') {
      return '#73C9F4';
    }
    if (fileType === 'fileTypeSticker') {
      return '#5655D7';
    }
    if (fileType === 'fileTypeDocument') {
      return '#F7A12D';
    }
    const colors: string[] = ['#F79E28', '#5BD36E', '#AF52DE'];
    return colors[index % colors.length];
  }

  private toggleChatSelection(chatId: number): void {
    this.chatStorageItems = this.chatStorageItems.map((item: ChatStorageItem): ChatStorageItem => {
      if (item.chatId !== chatId) {
        return item;
      }
      return {
        chatId: item.chatId,
        avatarText: item.avatarText,
        avatarColor: item.avatarColor,
        title: item.title,
        size: item.size,
        selected: !item.selected
      };
    });
    this.updateSelectedClearText();
  }

  private openChatMenu(chatId: number): void {
    this.activeChatMenuId = this.activeChatMenuId === chatId ? 0 : chatId;
  }

  private closeChatMenu(): void {
    this.activeChatMenuId = 0;
  }

  private hasSelectedChatRows(): boolean {
    return this.chatStorageItems.some((item: ChatStorageItem): boolean => item.selected);
  }

  private getActiveChatMenuItem(): ChatStorageItem {
    const item = this.chatStorageItems.find((chat: ChatStorageItem): boolean => chat.chatId === this.activeChatMenuId);
    if (item) {
      return item;
    }
    return {
      chatId: 0,
      avatarText: '?',
      avatarColor: '#338AF6',
      title: '',
      size: '',
      selected: false
    };
  }

  private showChatDetailDrawer(item: ChatStorageItem): void {
    this.detailDrawerTitle = item.title;
    this.detailDrawerVisible = true;
    this.closeChatMenu();
  }

  private openChatProfile(item: ChatStorageItem): void {
    const params: ChatProfileRouteParams = {
      chatId: item.chatId,
      title: item.title,
      avatarText: item.avatarText,
      avatarColor: item.avatarColor
    };
    console.info(`[CacheManagementPage] open chat profile chatId=${item.chatId}, title=${item.title}`);
    router.pushUrl({ url: 'pages/ChatProfilePage', params: params });
    this.closeChatMenu();
  }

  private toggleFileSelection(fileType: string): void {
    this.fileStorageItems = this.fileStorageItems.map((item: FileStorageItem): FileStorageItem => {
      if (item.fileType !== fileType) {
        return item;
      }
      return {
        fileType: item.fileType,
        title: item.title,
        date: item.date,
        size: item.size,
        selected: !item.selected
      };
    });
    this.updateSelectedClearText();
  }

  private toggleMediaSelection(fileType: string): void {
    this.mediaStorageItems = this.mediaStorageItems.map((item: MediaStorageItem): MediaStorageItem => {
      if (item.fileType !== fileType) {
        return item;
      }
      return {
        fileType: item.fileType,
        color: item.color,
        size: item.size,
        selected: !item.selected
      };
    });
    this.updateSelectedClearText();
  }

  private getMediaGridHeight(): number {
    const rows = Math.max(1, Math.ceil(this.mediaStorageItems.length / 3));
    return rows * 150 + Math.max(0, rows - 1);
  }

  private getChartPercent(index: number): string {
    if (this.categoryItems.length <= index) {
      return '';
    }
    return this.categoryItems[index].percent;
  }

  private showStatus(text: string): void {
    this.statusText = text;
    setTimeout(() => {
      this.statusText = '';
    }, 1300);
  }

  private clearCache(): void {
    console.info('[CacheManagementPage] clear cache clicked');
    this.showStatus('正在清理缓存...');
    const selectedChatIds: number[] = [];
    const selectedFileTypes: string[] = [];
    this.chatStorageItems.forEach((item: ChatStorageItem) => {
      if (item.selected && item.chatId !== 0) {
        selectedChatIds.push(item.chatId);
      }
    });
    this.fileStorageItems.forEach((item: FileStorageItem) => {
      if (item.selected) {
        selectedFileTypes.push(item.fileType);
      }
    });
    this.mediaStorageItems.forEach((item: MediaStorageItem) => {
      if (item.selected) {
        selectedFileTypes.push(item.fileType);
      }
    });
    const uniqueFileTypes = Array.from(new Set<string>(selectedFileTypes));
    if (selectedChatIds.length > 0 || uniqueFileTypes.length > 0) {
      this.td.optimizeStorageAdvanced(uniqueFileTypes, selectedChatIds, 0, 0);
    } else {
      this.td.optimizeStorage(['fileTypePhoto', 'fileTypeVideo', 'fileTypeDocument', 'fileTypeSticker'], 0, 0);
    }
    setTimeout(() => {
      this.td.getStorageStatistics(100);
    }, 650);
  }

  private updateSelectedClearText(): void {
    let count = 0;
    this.chatStorageItems.forEach((item: ChatStorageItem) => {
      if (item.selected) {
        count += 1;
      }
    });
    this.fileStorageItems.forEach((item: FileStorageItem) => {
      if (item.selected) {
        count += 1;
      }
    });
    this.mediaStorageItems.forEach((item: MediaStorageItem) => {
      if (item.selected) {
        count += 1;
      }
    });
    this.selectedClearText = count > 0 ? `清除所选 ${count} 项` : '清除所选';
  }

  private drawChart(): void {
    const ctx = this.chartContext;
    const center = 118;
    const radius = 74;
    const width = 44;
    const gap = 0.035;
    let start = -Math.PI / 2;
    ctx.clearRect(0, 0, 236, 236);
    if (this.categoryItems.length === 0 || this.totalBytes <= 0) {
      this.drawArc(ctx, center, radius, width, start, Math.PI * 1.5, '#4379EE');
      return;
    }
    this.categoryItems.forEach((item: CacheCategoryItem) => {
      const sweep = Math.max(0.04, Math.PI * 2 * item.sizeBytes / this.totalBytes);
      this.drawArc(ctx, center, radius, width, start, start + sweep - gap, item.color);
      start += sweep;
    });
  }

  private drawArc(ctx: CanvasRenderingContext2D, center: number, radius: number, width: number,
    start: number, end: number, color: string): void {
    ctx.beginPath();
    ctx.lineWidth = width;
    ctx.strokeStyle = color;
    ctx.arc(center, center, radius, start, end);
    ctx.stroke();
  }

  @Builder
  private TopBar() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column()
        .width('100%')
        .height(AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT)
        .backgroundColor('#E8EEF0F5')
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

      Text('存储使用')
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
  private DonutChart() {
    Stack({ alignContent: Alignment.Center }) {
      Canvas(this.chartContext)
        .width(236)
        .height(236)
        .onReady(() => {
          this.drawChart();
        })
      Text(this.totalText)
        .fontSize(22)
        .fontWeight(FontWeight.Bold)
        .fontColor('#000000')
      Text(this.getChartPercent(0))
        .fontSize(16)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .position({ x: 16, y: 142 })
      Text(this.getChartPercent(1))
        .fontSize(16)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .position({ x: 154, y: 58 })
    }
    .width(236)
    .height(236)
    .margin({ top: 6 })
  }

  @Builder
  private SectionTitle(title: string) {
    Text(title)
      .fontSize(12)
      .fontColor('#858A93')
      .textAlign(TextAlign.Start)
      .width('100%')
      .margin({ left: 24, top: 22, bottom: 8 })
  }

  @Builder
  private DividerLine(left: number = 60) {
    Divider()
      .strokeWidth(1)
      .color('#E0E2E7')
      .margin({ left: left, right: 16 })
  }

  @Builder
  private CheckIcon(color: string) {
    Stack({ alignContent: Alignment.Center }) {
      Text('✓')
        .fontSize(16)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .textAlign(TextAlign.Center)
    }
    .width(32)
    .height(32)
    .borderRadius(16)
    .backgroundColor(color)
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
    .width(34)
    .height(34)
    .borderRadius(9)
    .backgroundColor(color)
  }

  @Builder
  private CategoryRow(item: CacheCategoryItem) {
    Row() {
      this.CheckIcon(item.color)
      Text(item.title)
        .fontSize(15)
        .fontWeight(FontWeight.Medium)
        .fontColor('#111111')
        .textAlign(TextAlign.Start)
        .margin({ left: 18 })
      Text(item.percent)
        .fontSize(14)
        .fontColor('#8A8F98')
        .margin({ left: 6 })
        .layoutWeight(1)
      Text(item.size)
        .fontSize(14)
        .fontColor('#8A8F98')
      if (item.expandable) {
        Text('⌄')
          .fontSize(20)
          .fontColor('#B4B8C0')
          .margin({ left: 8 })
      }
    }
    .width('100%')
    .height(56)
    .padding({ left: 28, right: 24 })
  }

  @Builder
  private AutoDeleteRow(item: AutoDeleteItem) {
    Row() {
      this.IconBox(item.icon, item.color)
      Text(item.title)
        .fontSize(15)
        .fontWeight(FontWeight.Medium)
        .fontColor('#111111')
        .textAlign(TextAlign.Start)
        .layoutWeight(1)
        .margin({ left: 18 })
      Text(item.value)
        .fontSize(15)
        .fontColor('#8A8F98')
      Text('⌄')
        .fontSize(20)
        .fontColor('#B4B8C0')
        .margin({ left: 6 })
    }
    .width('100%')
    .height(58)
    .padding({ left: 24, right: 22 })
    .onClick(() => {
      this.showStatus(`${item.title}自动删除设置暂未接入`);
    })
  }

  @Builder
  private Footnote(text: string) {
    Text(text)
      .fontSize(12)
      .lineHeight(18)
      .fontColor('#858A93')
      .textAlign(TextAlign.Start)
      .width('100%')
      .margin({ left: 24, right: 24, top: 10 })
  }

  @Builder
  private UsageCard() {
    Column() {
      ForEach(this.categoryItems, (item: CacheCategoryItem, index: number) => {
        this.CategoryRow(item)
        if (index < this.categoryItems.length - 1) {
          this.DividerLine()
        }
      })

      Button(`清除缓存  ${this.totalText}`)
        .fontSize(15)
        .fontWeight(FontWeight.Medium)
        .fontColor('#E8F2FF')
        .width('88%')
        .height(54)
        .borderRadius(27)
        .backgroundColor('#3289F6')
        .margin({ top: 18, bottom: 18 })
        .onClick(() => {
          this.clearCache();
        })
    }
    .width('100%')
    .borderRadius(28)
    .backgroundColor(Color.White)
    .clip(true)
  }

  @Builder
  private AutoDeleteCard() {
    Column() {
      this.AutoDeleteRow({
        icon: $r('app.media.user_home'),
        color: '#338AF6',
        title: '私聊',
        value: '从不'
      })
      this.DividerLine()
      this.AutoDeleteRow({
        icon: $r('app.media.group'),
        color: '#5BD36E',
        title: '群聊',
        value: '1 个月'
      })
      this.DividerLine()
      this.AutoDeleteRow({
        icon: $r('app.media.msg_top_group'),
        color: '#F6B13D',
        title: '频道',
        value: '1 周'
      })
      this.DividerLine()
      this.AutoDeleteRow({
        icon: $r('app.media.appearance'),
        color: '#6A5EF6',
        title: '动态',
        value: '2 天'
      })
    }
    .width('100%')
    .borderRadius(24)
    .backgroundColor(Color.White)
    .clip(true)
  }

  @Builder
  private LimitCard() {
    Column() {
      Row() {
        Text('5 GB')
          .fontSize(13)
          .fontColor('#8A8F98')
        Text('20 GB')
          .fontSize(13)
          .fontColor('#8A8F98')
        Text('50 GB')
          .fontSize(13)
          .fontColor('#8A8F98')
        Text('无限')
          .fontSize(13)
          .fontColor('#8A8F98')
      }
      .width('100%')
      .justifyContent(FlexAlign.SpaceBetween)
      .padding({ left: 28, right: 28, top: 20 })

      Stack() {
        Row()
          .width('88%')
          .height(4)
          .borderRadius(2)
          .backgroundColor('#338AF6')
          .margin({ left: 28 })
        Row() {
          Circle()
            .width(4)
            .height(4)
            .fill('#C8CBD1')
          Circle()
            .width(4)
            .height(4)
            .fill('#C8CBD1')
          Circle()
            .width(4)
            .height(4)
            .fill('#C8CBD1')
        }
        .width('70%')
        .justifyContent(FlexAlign.SpaceBetween)
        .margin({ left: 48 })
        Circle()
          .width(46)
          .height(34)
          .fill(Color.White)
          .shadow({ radius: 10, color: '#22000000', offsetY: 3 })
          .position({ x: 'calc(100% - 72vp)', y: 6 })
      }
      .width('100%')
      .height(48)
      .margin({ top: 6, bottom: 8 })
    }
    .width('100%')
    .borderRadius(24)
    .backgroundColor(Color.White)
    .clip(true)
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
        .position({ x: '31%', y: AppLayout.STATUS_BAR_HEIGHT + 72 })
    }
  }

  @Builder
  private DetailSegment() {
    Row() {
      this.SegmentItem('聊天', 0)
      this.SegmentItem('媒体', 1)
      this.SegmentItem('文件', 2)
    }
    .width(184)
    .height(40)
    .padding(3)
    .borderRadius(20)
    .backgroundColor('#F8FFFFFF')
    .border({ width: 1, color: '#FFFFFFFF' })
    .shadow({ radius: 10, color: '#10000000', offsetY: 3 })
    .margin({ top: 28, bottom: 14 })
  }

  @Builder
  private SegmentItem(label: string, index: number) {
    Text(label)
      .fontSize(15)
      .fontWeight(FontWeight.Medium)
      .fontColor('#111111')
      .textAlign(TextAlign.Center)
      .layoutWeight(1)
      .height(34)
      .borderRadius(17)
      .backgroundColor(this.selectedDetailTab === index ? '#E3E3E3' : '#00FFFFFF')
      .onClick(() => {
        this.selectedDetailTab = index;
      })
  }

  @Builder
  private ChatAvatar(item: ChatStorageItem) {
    Stack({ alignContent: Alignment.Center }) {
      Text(item.avatarText)
        .fontSize(item.avatarText.length > 1 ? 14 : 17)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .textAlign(TextAlign.Center)
    }
    .width(38)
    .height(38)
    .borderRadius(19)
    .backgroundColor(item.avatarColor)
  }

  @Builder
  private ChatStorageRow(item: ChatStorageItem) {
    Column() {
      Row() {
        this.ChatAvatar(item)
        Text(item.title)
          .fontSize(15)
          .fontWeight(FontWeight.Medium)
          .fontColor('#111111')
          .textAlign(TextAlign.Start)
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
          .layoutWeight(1)
          .margin({ left: 14 })
        Text(item.size)
          .fontSize(14)
          .fontColor('#8A8F98')
          .margin({ left: 10 })
        if (this.hasSelectedChatRows()) {
          Button({ type: ButtonType.Circle }) {
            if (item.selected) {
              Text('✓')
                .fontSize(15)
                .fontWeight(FontWeight.Bold)
                .fontColor(Color.White)
            }
          }
          .width(24)
          .height(24)
          .borderRadius(12)
          .backgroundColor(item.selected ? '#338AF6' : '#00FFFFFF')
          .border({ width: 2, color: item.selected ? '#338AF6' : '#C7CBD1' })
          .margin({ left: 10 })
          .onClick(() => {
            this.toggleChatSelection(item.chatId);
            this.closeChatMenu();
          })
        }
      }
      .width('100%')
      .height(54)
      .padding({ left: 16, right: 16 })
      .gesture(
        LongPressGesture().onAction(() => {
          console.info(`[CacheManagementPage] long press storage chat chatId=${item.chatId}`);
          this.openChatMenu(item.chatId);
        })
      )

    }
    .width('100%')
  }

  @Builder
  private ChatRowMenu(item: ChatStorageItem) {
    Column() {
      this.ChatRowMenuItem($r('app.media.problem'), '显示详情', () => {
        this.showChatDetailDrawer(item);
      })
      this.ChatRowMenuItem($r('app.media.user_home'), '打开个人资料', () => {
        this.openChatProfile(item);
      })
      this.ChatRowMenuItem($r('app.media.xiaoxi_yidu'), '选择', () => {
        this.toggleChatSelection(item.chatId);
        this.closeChatMenu();
      })
    }
    .width(236)
    .padding({ top: 8, bottom: 8 })
    .borderRadius(26)
    .backgroundColor('#EAF4FF')
    .backdropBlur(18)
    .border({ width: 1, color: '#F8FFFFFF' })
    .margin({ top: 14 })
    .alignItems(HorizontalAlign.Start)
  }

  @Builder
  private ChatRowMenuItem(icon: Resource, title: string, action: () => void) {
    Row() {
      Image(icon)
        .width(19)
        .height(19)
        .objectFit(ImageFit.Contain)
        .fillColor('#111111')
      Text(title)
        .fontSize(14)
        .fontColor('#111111')
        .margin({ left: 14 })
    }
    .width('100%')
    .height(54)
    .padding({ left: 18, right: 18 })
    .onClick(action)
  }

  @Builder
  private ChatMenuPreviewRow(item: ChatStorageItem) {
    Row() {
      this.ChatAvatar(item)
      Text(item.title)
        .fontSize(15)
        .fontWeight(FontWeight.Bold)
        .fontColor('#111111')
        .textAlign(TextAlign.Start)
        .maxLines(1)
        .textOverflow({ overflow: TextOverflow.Ellipsis })
        .layoutWeight(1)
        .margin({ left: 14 })
      Text(item.size)
        .fontSize(16)
        .fontColor('#8A8F98')
        .margin({ left: 12 })
    }
    .width('100%')
    .height(54)
    .padding({ left: 16, right: 18 })
    .borderRadius(10)
    .backgroundColor(Color.White)
  }

  @Builder
  private ChatMenuOverlay() {
    if (this.activeChatMenuId !== 0) {
      Stack({ alignContent: Alignment.BottomStart }) {
        Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#50D5D9E2')
          .backdropBlur(38)
          .onClick(() => {
            this.closeChatMenu();
          })

        Column() {
          this.ChatMenuPreviewRow(this.getActiveChatMenuItem())
          this.ChatRowMenu(this.getActiveChatMenuItem())
        }
        .width('100%')
        .alignItems(HorizontalAlign.Start)
        .padding({ left: 32, right: 32, bottom: AppLayout.BOTTOM_SAFE_HEIGHT + 112 })
      }
      .width('100%')
      .height('100%')
      .zIndex(18)
    }
  }

  @Builder
  private ChatStorageList() {
    Column() {
      ForEach(this.chatStorageItems, (item: ChatStorageItem, index: number) => {
        this.ChatStorageRow(item)
        if (index < this.chatStorageItems.length - 1) {
          this.DividerLine(70)
        }
      })
    }
    .width('92%')
    .borderRadius(24)
    .backgroundColor(Color.White)
    .clip(true)
  }

  @Builder
  private FileIcon() {
    Stack({ alignContent: Alignment.Center }) {
      Text('epub')
        .fontSize(13)
        .fontWeight(FontWeight.Bold)
        .fontColor(Color.White)
        .margin({ top: 12 })
    }
    .width(36)
    .height(44)
    .borderRadius(5)
    .backgroundColor('#67BDF0')
  }

  @Builder
  private FileStorageRow(item: FileStorageItem) {
    Row() {
      Circle()
        .width(24)
        .height(24)
        .fill(item.selected ? '#338AF6' : '#00FFFFFF')
        .stroke(item.selected ? '#338AF6' : '#C7CBD1')
        .strokeWidth(2)
      Row() {
        this.FileIcon()
      }
      .margin({ left: 14 })
      Column({ space: 3 }) {
        Text(item.title)
          .fontSize(14)
          .fontWeight(FontWeight.Medium)
          .fontColor('#111111')
          .textAlign(TextAlign.Start)
          .maxLines(1)
          .textOverflow({ overflow: TextOverflow.Ellipsis })
        Text(item.date)
          .fontSize(12)
          .fontColor('#8A8F98')
          .textAlign(TextAlign.Start)
          .maxLines(1)
      }
      .alignItems(HorizontalAlign.Start)
      .layoutWeight(1)
      .margin({ left: 12 })
      Text(item.size)
        .fontSize(14)
        .fontColor('#8A8F98')
        .margin({ left: 10 })
    }
    .width('100%')
    .height(58)
    .padding({ left: 18, right: 18 })
    .onClick(() => {
      this.toggleFileSelection(item.fileType);
    })
  }

  @Builder
  private FileStorageList() {
    Column() {
      ForEach(this.fileStorageItems, (item: FileStorageItem, index: number) => {
        this.FileStorageRow(item)
        if (index < this.fileStorageItems.length - 1) {
          this.DividerLine(88)
        }
      })
    }
    .width('92%')
    .borderRadius(24)
    .backgroundColor(Color.White)
    .clip(true)
  }

  @Builder
  private MediaCell(item: MediaStorageItem) {
    Stack() {
      Row()
        .width('100%')
        .height('100%')
        .backgroundColor(item.color)
      Circle()
        .width(28)
        .height(28)
        .fill(item.selected ? '#338AF6' : '#22FFFFFF')
        .stroke(Color.White)
        .strokeWidth(2)
        .position({ x: 'calc(100% - 34vp)', y: 8 })
      if (item.selected) {
        Text('✓')
          .fontSize(18)
          .fontWeight(FontWeight.Bold)
          .fontColor(Color.White)
          .position({ x: 'calc(100% - 27vp)', y: 8 })
      }
      Row() {
        Text('▶')
          .fontSize(10)
          .fontColor(Color.White)
        Text(item.size)
          .fontSize(12)
          .fontColor(Color.White)
          .margin({ left: 4 })
      }
      .padding({ left: 7, right: 7, top: 3, bottom: 3 })
      .borderRadius(10)
      .backgroundColor('#7A000000')
      .position({ x: 'calc(100% - 78vp)', y: 116 })
    }
    .width('100%')
    .height(150)
    .clip(true)
    .onClick(() => {
      this.toggleMediaSelection(item.fileType);
    })
  }

  @Builder
  private MediaStorageGrid() {
    Column() {
      Grid() {
        ForEach(this.mediaStorageItems, (item: MediaStorageItem) => {
          GridItem() {
            this.MediaCell(item)
          }
        })
      }
      .columnsTemplate('1fr 1fr 1fr')
      .columnsGap(1)
      .rowsGap(1)
      .width('100%')
      .height(this.getMediaGridHeight())

      Button(this.selectedClearText)
        .fontSize(15)
        .fontColor(Color.White)
        .width('92%')
        .height(54)
        .borderRadius(12)
        .backgroundColor('#338AF6')
        .margin({ top: 14, bottom: 18 })
        .onClick(() => {
          this.clearCache();
        })
    }
    .width('100%')
  }

  @Builder
  private DetailContent() {
    Column() {
      this.DetailSegment()
      if (this.selectedDetailTab === 0) {
        this.ChatStorageList()
      } else if (this.selectedDetailTab === 1) {
        this.MediaStorageGrid()
      } else {
        this.FileStorageList()
      }
    }
    .width('100%')
    .alignItems(HorizontalAlign.Center)
  }

  @Builder
  private DetailDrawer() {
    if (this.detailDrawerVisible) {
      Stack({ alignContent: Alignment.Bottom }) {
        Column()
          .width('100%')
          .height('100%')
          .backgroundColor('#22000000')
          .onClick(() => {
            this.detailDrawerVisible = false;
          })

        Column() {
          Row() {
            Button({ type: ButtonType.Circle }) {
              Image($r('app.media.close'))
                .width(18)
                .height(18)
                .objectFit(ImageFit.Contain)
                .fillColor('#111111')
            }
            .width(38)
            .height(38)
            .borderRadius(19)
            .backgroundColor('#F2F3F5')
            .onClick(() => {
              this.detailDrawerVisible = false;
            })
            Text(this.detailDrawerTitle)
              .fontSize(16)
              .fontWeight(FontWeight.Bold)
              .fontColor('#111111')
              .maxLines(1)
              .textOverflow({ overflow: TextOverflow.Ellipsis })
              .layoutWeight(1)
              .margin({ left: 12 })
          }
          .width('100%')
          .height(48)
          .padding({ left: 18, right: 18 })

          Blank()
            .layoutWeight(1)
        }
        .width('100%')
        .height('46%')
        .padding({ top: 12, bottom: AppLayout.BOTTOM_SAFE_HEIGHT + 12 })
        .borderRadius({ topLeft: 28, topRight: 28 })
        .backgroundColor(Color.White)
        .transition(TransitionEffect.move(TransitionEdge.BOTTOM).animation({ duration: 220, curve: Curve.EaseOut }))
      }
      .width('100%')
      .height('100%')
      .zIndex(20)
    }
  }

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll() {
        Column() {
          this.DonutChart()
          Text('存储使用')
            .fontSize(20)
            .fontWeight(FontWeight.Bold)
            .fontColor('#111111')
            .margin({ top: 10 })
          Text('Telegram 占用了你 0.3% 的可用设备储存空间。')
            .fontSize(12)
            .fontColor('#858A93')
            .textAlign(TextAlign.Center)
            .margin({ top: 8 })

          Row()
            .width(200)
            .height(4)
            .borderRadius(2)
            .backgroundColor('#C9DDF8')
            .margin({ top: 16, bottom: 28 })
          Circle()
            .width(6)
            .height(6)
            .fill('#338AF6')
            .position({ x: 'calc(50% - 104vp)', y: AppLayout.STATUS_BAR_HEIGHT + 370 })

          Column() {
            this.UsageCard()
          }
          .width('92%')

          this.Footnote('所有媒体文件将保留在 Telegram 云端，需要时可以重新下载。')

          Column() {
            this.SectionTitle('自动删除已缓存媒体')
            this.AutoDeleteCard()
          }
          .width('92%')

          this.Footnote('在此期间你未曾访问过的云端聊天中的照片、视频和其他文件将从此设备中删除，以节省磁盘空间。')

          Column() {
            this.SectionTitle('缓存大小限制')
            this.LimitCard()
          }
          .width('92%')

          this.Footnote('如果缓存大小超过此限制，将从此设备中删除最早的未曾访问的媒体文件。')

          this.DetailContent()
        }
        .width('100%')
        .alignItems(HorizontalAlign.Center)
        .padding({
          top: AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT,
          bottom: AppLayout.BOTTOM_SAFE_HEIGHT + 28
        })
      }
      .width('100%')
      .height('100%')
      .backgroundColor('#EEF0F5')
      .scrollBar(BarState.Off)

      this.TopBar()
      this.ChatMenuOverlay()
      this.DetailDrawer()
      this.StatusToast()
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#EEF0F5')
  }
}
