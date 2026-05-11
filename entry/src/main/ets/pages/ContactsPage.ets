// entry/src/main/ets/pages/ContactsPage.ets
import { TdlibService, TdUpdate } from '../common/service/TdlibService';

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

  build() {
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
    .width('100%').height('100%')
  }
}
