// entry/src/main/ets/common/service/GalleryService.ets
import { common } from '@kit.AbilityKit';
import { fileIo } from '@kit.CoreFileKit';
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
    console.info(`[GalleryService] saveVideo start source=${sourcePath}`);
    const helper = photoAccessHelper.getPhotoAccessHelper(context);
    const sourceLocalPath = GalleryService.toLocalPath(sourcePath);
    const extension = GalleryService.getExtension(sourceLocalPath, 'mp4');
    console.info(`[GalleryService] create video asset extension=${extension}, sourceLocalPath=${sourceLocalPath}`);
    const assetUri = await helper.createAsset(photoAccessHelper.PhotoType.VIDEO, extension);
    console.info(`[GalleryService] created video asset uri=${assetUri}`);
    let sourceFile: fileIo.File | null = null;
    let targetFile: fileIo.File | null = null;
    try {
      console.info('[GalleryService] open source video file');
      sourceFile = fileIo.openSync(sourceLocalPath, fileIo.OpenMode.READ_ONLY);
      console.info(`[GalleryService] open target gallery asset fd uri=${assetUri}`);
      targetFile = fileIo.openSync(assetUri, fileIo.OpenMode.WRITE_ONLY);
      console.info(`[GalleryService] copy video sourceFd=${sourceFile.fd}, targetFd=${targetFile.fd}`);
      fileIo.copyFileSync(sourceFile.fd, targetFile.fd);
      console.info('[GalleryService] copy video finished');
    } finally {
      if (sourceFile !== null) {
        fileIo.closeSync(sourceFile);
      }
      if (targetFile !== null) {
        fileIo.closeSync(targetFile);
      }
      console.info('[GalleryService] saveVideo close files finished');
    }
  }

  private static toFileUri(sourcePath: string): string {
    return fileUri.getUriFromPath(GalleryService.toLocalPath(sourcePath));
  }

  private static toLocalPath(sourcePath: string): string {
    return sourcePath.startsWith('file://') ? sourcePath.substring('file://'.length) : sourcePath;
  }

  private static getExtension(path: string, fallback: string): string {
    const queryIndex = path.indexOf('?');
    const cleanPath = queryIndex >= 0 ? path.substring(0, queryIndex) : path;
    const dotIndex = cleanPath.lastIndexOf('.');
    if (dotIndex < 0 || dotIndex === cleanPath.length - 1) {
      return fallback;
    }
    return cleanPath.substring(dotIndex + 1).toLowerCase();
  }
}
