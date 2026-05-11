// entry/src/main/ets/pages/CacheManagementPage.ets
import { TdlibService, TdStorageStatistic, TdUpdate } from '../common/service/TdlibService';

@Entry
@Component
struct CacheManagementPage {
  @State stats: string = '计算中...';
  private td = TdlibService.getInstance();

  aboutToAppear() {
    this.td.optimizeStorage(['fileTypePhoto', 'fileTypeVideo', 'fileTypeDocument'], 0, 0);
    this.td.onUpdate('updateStorageStatisticsFast', (update: TdUpdate) => {
      let total = 0;
      const statistics: TdStorageStatistic[] = update.statistics ? update.statistics : [];
      statistics.forEach((item: TdStorageStatistic) => {
        total += item.size;
      });
      this.stats = `缓存大小：${(total / 1024 / 1024).toFixed(1)} MB`;
    });
  }

  build() {
    Column() {
      Text(this.stats).fontSize(18).margin(20)
      Button('清理全部媒体缓存').onClick(() => {
        console.info('[CacheManagementPage] button 清理全部媒体缓存 clicked');
        // ttl设0代表立即清理所有
        this.td.optimizeStorage(['fileTypePhoto', 'fileTypeVideo', 'fileTypeDocument'], 0, 0);
        this.stats = '正在清理...';
      })
    }
    .width('100%').height('100%').justifyContent(FlexAlign.Center)
  }
}
