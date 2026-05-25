// entry/src/main/cpp/types/libtdlib_bridge/index.d.ts
export const createNativeClient: () => number;
export const sendNativeRequest: (clientId: number, request: string) => void;
export const receiveNativeUpdate: (clientId: number, timeout: number) => string | null | undefined;
export const startVideoProxy: (
  clientId: number,
  fileId: number,
  localPath: string,
  totalSize: number,
  downloadedPrefixSize: number,
  downloadedSize: number,
  isCompleted: boolean
) => string;
export const stopVideoProxy: (fileId: number) => void;
