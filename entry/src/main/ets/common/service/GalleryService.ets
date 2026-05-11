// entry/src/main/ets/common/service/GalleryService.ets
import { common } from '@kit.AbilityKit';
import fileUri from '@ohos.file.fileuri';
import photoAccessHelper from '@ohos.file.photoAccessHelper';

export class GalleryService {
  public static async saveImage(context: common.UIAbilityContext, sourcePath: string): Promise<void> {
    const request = photoAccessHelper.MediaAssetChangeRequest.createImageAssetRequest(
      context,
      GalleryService.toFileUri(sourcePath)
    );
    const helper = photoAccessHelper.getPhotoAccessHelper(context);
    await helper.applyChanges(request);
  }

  public static async saveVideo(context: common.UIAbilityContext, sourcePath: string): Promise<void> {
    const request = photoAccessHelper.MediaAssetChangeRequest.createVideoAssetRequest(
      context,
      GalleryService.toFileUri(sourcePath)
    );
    const helper = photoAccessHelper.getPhotoAccessHelper(context);
    await helper.applyChanges(request);
  }

  private static toFileUri(sourcePath: string): string {
    const path = sourcePath.startsWith('file://') ? sourcePath.substring('file://'.length) : sourcePath;
    return fileUri.getUriFromPath(path);
  }
}
