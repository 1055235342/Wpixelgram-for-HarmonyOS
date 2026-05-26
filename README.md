# Wpixelgram for HarmonyOS

HarmonyOS 即时通信客户端，基于 ArkTS、TDLib Native Bridge 和 AVPlayer/XComponent 开发。

## 功能

- 会话列表、消息详情、联系人、通话、设置页面。
- 支持文本、图片、视频、音频、文件、机器人按钮等消息内容。
- 支持手机、平板和大屏左右分栏。

## 实机截图

<table>
  <tr>
    <td><img src="img/1.jpg" width="180" /></td>
    <td><img src="img/2.jpg" width="180" /></td>
    <td><img src="img/3.jpg" width="180" /></td>
    <td><img src="img/4.jpg" width="180" /></td>
  </tr>
</table>

## 环境

- HarmonyOS SDK: `6.1.0(23)`
- DevEco Studio
- ArkTS / Native C++ / NAPI

## 配置

本地 API 配置放在：

```text
entry/src/main/resources/rawfile/
```

根据目录里的 `*.example.json` 创建本地配置文件，并填写自己的 `api_id` 和 `api_hash`。


## 构建

推荐使用 DevEco Studio 打开项目后直接构建运行。

## 说明

当前项目还在迭代中，重点关注消息同步、媒体播放、未读状态、存储统计和页面性能。



# 免责声明
本项目为 **非官方、第三方开源适配项目**，
与 Telegram Messenger Inc.、华为鸿蒙官方无任何关联、授权与合作关系。
Telegram 为 Telegram Messenger Inc. 注册商标，
HarmonyOS 为华为技术有限公司注册商标。
本项目仅用于个人技术学习与开源交流，不用于商业用途。



