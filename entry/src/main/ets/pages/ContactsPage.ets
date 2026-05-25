// entry/src/main/ets/pages/ContactsPage.ets
import { TdlibService, TdUpdate } from '../common/service/TdlibService';
import { AppLayout } from '../common/constants/AppLayout';

interface ContactItem {
  id: number;
  name: string;
}

@Entry
@Component
export struct ContactsPage {
  @State contacts: ContactItem[] = [];
  private td = TdlibService.getInstance();

  aboutToAppear() {
    this.td.getContacts();
    this.td.onUpdate('updateContacts', (update: TdUpdate) => {
      const userIds: number[] = update.user_ids ? update.user_ids : [];
      this.contacts = userIds.map((id: number): ContactItem => ({
        id: id,
        name: `User ${id}`
      }));
    });
  }

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

      Text('联系人')
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
      List() {
        ForEach(this.contacts, (item: ContactItem) => {
          ListItem() {
            Row() {
              Text(item.name).fontSize(18)
            }
            .width('100%').height(60).padding(16)
          }
        })
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
