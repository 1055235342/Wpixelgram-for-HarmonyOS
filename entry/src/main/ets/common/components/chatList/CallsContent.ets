import { AppLayout } from '../../constants/AppLayout';

@Component
export struct CallsContent {
  @Builder
  private TopBar() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column()
        .width('100%')
        .height(AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT)
        .backgroundColor('#F4F6FA')
        .linearGradientBlur(AppLayout.TOP_GRADIENT_BLUR_RADIUS, {
          fractionStops: [[0, 0], [1, 1]],
          direction: GradientDirection.Top
        })

      Text('最近通话')
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

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column() {
        Column() {
          Text('暂无最近通话')
            .fontSize(18)
            .fontWeight(FontWeight.Bold)
            .fontColor('#27364A')
          Text('后续接入 TDLib 通话记录后会显示在这里')
            .fontSize(14)
            .fontColor('#8A96A8')
            .margin({ top: 8 })
        }
        .width('100%')
        .layoutWeight(1)
        .justifyContent(FlexAlign.Center)
        .alignItems(HorizontalAlign.Center)
      }
      .width('100%')
      .height('100%')
      .padding({ top: AppLayout.STATUS_BAR_HEIGHT + AppLayout.SECONDARY_TOP_CONTENT_HEIGHT })

      this.TopBar()
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#F4F6FA')
  }
}
