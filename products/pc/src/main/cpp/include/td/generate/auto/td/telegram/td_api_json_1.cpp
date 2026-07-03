#include "td/telegram/td_api_json.h"

#include "td/telegram/td_api.h"
#include "td/telegram/td_api.hpp"

#include "td/tl/tl_json.h"

#include "td/utils/base64.h"
#include "td/utils/common.h"
#include "td/utils/FlatHashMap.h"
#include "td/utils/Slice.h"

namespace td {
namespace td_api {
Result<int32> tl_constructor_from_string(td_api::BusinessFeature *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"businessFeatureLocation", -1064304004},
    {"businessFeatureOpeningHours", 461054701},
    {"businessFeatureQuickReplies", -1674048894},
    {"businessFeatureGreetingMessage", 1789424756},
    {"businessFeatureAwayMessage", 1090119901},
    {"businessFeatureAccountLinks", 1878693646},
    {"businessFeatureStartPage", 401471457},
    {"businessFeatureBots", 275084773},
    {"businessFeatureEmojiStatus", -846282523},
    {"businessFeatureChatFolderTags", -543880918},
    {"businessFeatureUpgradedStories", -1812245550}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ChatPhotoStickerType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"chatPhotoStickerTypeRegularOrMask", -415147620},
    {"chatPhotoStickerTypeCustomEmoji", -266224943}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::FirebaseAuthenticationSettings *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"firebaseAuthenticationSettingsAndroid", -1771112932},
    {"firebaseAuthenticationSettingsIos", 222930116}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputChatPhoto *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputChatPhotoPrevious", 23128529},
    {"inputChatPhotoStatic", 1979179699},
    {"inputChatPhotoAnimation", 90846242},
    {"inputChatPhotoSticker", 1315861341}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputPaidMediaType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputPaidMediaTypePhoto", 819520113},
    {"inputPaidMediaTypeVideo", 1793741625}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::KeyboardButtonType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"keyboardButtonTypeText", -1773037256},
    {"keyboardButtonTypeRequestPhoneNumber", -1529235527},
    {"keyboardButtonTypeRequestLocation", -125661955},
    {"keyboardButtonTypeRequestPoll", 1902435512},
    {"keyboardButtonTypeRequestUsers", -1738765315},
    {"keyboardButtonTypeRequestChat", 1511138485},
    {"keyboardButtonTypeRequestManagedBot", 311203127},
    {"keyboardButtonTypeWebApp", 1892220770}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::NetworkStatisticsEntry *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"networkStatisticsEntryFile", 188452706},
    {"networkStatisticsEntryCall", 737000365}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::PremiumSource *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"premiumSourceLimitExceeded", -2052159742},
    {"premiumSourceFeature", 445813541},
    {"premiumSourceBusinessFeature", -1492946340},
    {"premiumSourceStoryFeature", -1030737556},
    {"premiumSourceLink", 2135071132},
    {"premiumSourceSettings", -285702859}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ResendCodeReason *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"resendCodeReasonUserRequest", -441923456},
    {"resendCodeReasonVerificationFailed", 529870273}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::StoryList *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"storyListMain", -672222209},
    {"storyListArchive", -41900223}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::TopChatCategory *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"topChatCategoryUsers", 1026706816},
    {"topChatCategoryBots", -1577129195},
    {"topChatCategoryGroups", 1530056846},
    {"topChatCategoryChannels", -500825885},
    {"topChatCategoryInlineBots", 377023356},
    {"topChatCategoryWebAppBots", 100062973},
    {"topChatCategoryCalls", 356208861},
    {"topChatCategoryForwardChats", 1695922133}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::Object *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"acceptedGiftTypes", 1288451078},
    {"accountTtl", 1324495492},
    {"address", -2043654342},
    {"affiliateProgramParameters", 1642662996},
    {"affiliateProgramSortOrderProfitability", -1963282585},
    {"affiliateProgramSortOrderCreationDate", -1558628083},
    {"affiliateProgramSortOrderRevenue", 1923269304},
    {"affiliateTypeCurrentUser", 1453785589},
    {"affiliateTypeBot", -1032587200},
    {"affiliateTypeChannel", -683939735},
    {"archiveChatListSettings", 1058499236},
    {"autoDownloadSettings", 991433696},
    {"autosaveSettingsScopePrivateChats", 1395227007},
    {"autosaveSettingsScopeGroupChats", 853544526},
    {"autosaveSettingsScopeChannelChats", -499572783},
    {"autosaveSettingsScopeChat", -1632255255},
    {"backgroundFillSolid", 1010678813},
    {"backgroundFillGradient", -1839206017},
    {"backgroundFillFreeformGradient", -1145469255},
    {"backgroundTypeWallpaper", 1972128891},
    {"backgroundTypePattern", 1290213117},
    {"backgroundTypeFill", 993008684},
    {"backgroundTypeChatTheme", 1299879762},
    {"birthdate", 1644064030},
    {"blockListMain", 1352930172},
    {"blockListStories", 103323228},
    {"botCommand", -1032140601},
    {"botCommandScopeDefault", 795652779},
    {"botCommandScopeAllPrivateChats", -344889543},
    {"botCommandScopeAllGroupChats", -981088162},
    {"botCommandScopeAllChatAdministrators", 1998329169},
    {"botCommandScopeChat", -430234971},
    {"botCommandScopeChatAdministrators", 1119682126},
    {"botCommandScopeChatMember", -211380494},
    {"botMenuButton", -944407322},
    {"businessAwayMessageScheduleAlways", -910564679},
    {"businessAwayMessageScheduleOutsideOfOpeningHours", -968630506},
    {"businessAwayMessageScheduleCustom", -1967108654},
    {"businessAwayMessageSettings", 353084137},
    {"businessBotRights", 1224839038},
    {"businessConnectedBot", -1815439021},
    {"businessFeatureLocation", -1064304004},
    {"businessFeatureOpeningHours", 461054701},
    {"businessFeatureQuickReplies", -1674048894},
    {"businessFeatureGreetingMessage", 1789424756},
    {"businessFeatureAwayMessage", 1090119901},
    {"businessFeatureAccountLinks", 1878693646},
    {"businessFeatureStartPage", 401471457},
    {"businessFeatureBots", 275084773},
    {"businessFeatureEmojiStatus", -846282523},
    {"businessFeatureChatFolderTags", -543880918},
    {"businessFeatureUpgradedStories", -1812245550},
    {"businessGreetingMessageSettings", 1689140754},
    {"businessLocation", -1084969126},
    {"businessOpeningHours", 816603700},
    {"businessOpeningHoursInterval", -1108322732},
    {"businessRecipients", 868656909},
    {"buttonStyleDefault", 588834315},
    {"buttonStylePrimary", 2048071333},
    {"buttonStyleDanger", -1637377793},
    {"buttonStyleSuccess", 1042215008},
    {"callProblemEcho", 801116548},
    {"callProblemNoise", 1053065359},
    {"callProblemInterruptions", 1119493218},
    {"callProblemDistortedSpeech", 379960581},
    {"callProblemSilentLocal", 253652790},
    {"callProblemSilentRemote", 573634714},
    {"callProblemDropped", -1207311487},
    {"callProblemDistortedVideo", 385245706},
    {"callProblemPixelatedVideo", 2115315411},
    {"callProtocol", -1075562897},
    {"callbackQueryPayloadData", -1977729946},
    {"callbackQueryPayloadDataWithPassword", 1340266738},
    {"callbackQueryPayloadGame", 1303571512},
    {"chatActionTyping", 380122167},
    {"chatActionRecordingVideo", 216553362},
    {"chatActionUploadingVideo", 1234185270},
    {"chatActionRecordingVoiceNote", -808850058},
    {"chatActionUploadingVoiceNote", -613643666},
    {"chatActionUploadingPhoto", 654240583},
    {"chatActionUploadingDocument", 167884362},
    {"chatActionChoosingSticker", 372753697},
    {"chatActionChoosingLocation", -2017893596},
    {"chatActionChoosingContact", -1222507496},
    {"chatActionStartPlayingGame", -865884164},
    {"chatActionRecordingVideoNote", 16523393},
    {"chatActionUploadingVideoNote", 1172364918},
    {"chatActionWatchingAnimations", 2052990641},
    {"chatActionCancel", 1160523958},
    {"chatAdministratorRights", 1562741834},
    {"chatAvailableReactionsAll", 694160279},
    {"chatAvailableReactionsSome", 152513153},
    {"chatEventLogFilters", 1572752816},
    {"chatFolder", 1596164696},
    {"chatFolderIcon", -146104090},
    {"chatFolderName", -330482274},
    {"chatInviteLinkMember", 29156795},
    {"chatJoinRequest", 59341416},
    {"chatListMain", -400991316},
    {"chatListArchive", 362770115},
    {"chatListFolder", 385760856},
    {"chatLocation", -1566863583},
    {"chatMemberStatusCreator", 877825117},
    {"chatMemberStatusAdministrator", -861316634},
    {"chatMemberStatusMember", -32707562},
    {"chatMemberStatusRestricted", 1661432998},
    {"chatMemberStatusLeft", -5815259},
    {"chatMemberStatusBanned", -1653518666},
    {"chatMembersFilterContacts", 1774485671},
    {"chatMembersFilterAdministrators", -1266893796},
    {"chatMembersFilterMembers", 670504342},
    {"chatMembersFilterMention", 1932296772},
    {"chatMembersFilterRestricted", 1256282813},
    {"chatMembersFilterBanned", -1863102648},
    {"chatMembersFilterBots", -1422567288},
    {"chatNotificationSettings", 1459533846},
    {"chatPermissions", -1533863184},
    {"chatPhotoSticker", -1459387485},
    {"chatPhotoStickerTypeRegularOrMask", -415147620},
    {"chatPhotoStickerTypeCustomEmoji", -266224943},
    {"collectibleItemTypeUsername", 458680273},
    {"collectibleItemTypePhoneNumber", 1256251714},
    {"contact", -1993844876},
    {"date", -277956960},
    {"dateTimeFormattingTypeRelative", -648483424},
    {"dateTimeFormattingTypeAbsolute", 47463317},
    {"dateTimePartPrecisionNone", 1790302111},
    {"dateTimePartPrecisionShort", 1290158159},
    {"dateTimePartPrecisionLong", -105378824},
    {"deviceTokenFirebaseCloudMessaging", -797881849},
    {"deviceTokenApplePush", 387541955},
    {"deviceTokenApplePushVoIP", 804275689},
    {"deviceTokenWindowsPush", -1410514289},
    {"deviceTokenMicrosoftPush", 1224269900},
    {"deviceTokenMicrosoftPushVoIP", -785603759},
    {"deviceTokenWebPush", -1694507273},
    {"deviceTokenSimplePush", 49584736},
    {"deviceTokenUbuntuPush", 1782320422},
    {"deviceTokenBlackBerryPush", 1559167234},
    {"deviceTokenTizenPush", -1359947213},
    {"deviceTokenHuaweiPush", 1989103142},
    {"draftMessage", -1165040650},
    {"emailAddressAuthenticationCode", -993257022},
    {"emailAddressAuthenticationAppleId", 633948265},
    {"emailAddressAuthenticationGoogleId", -19142846},
    {"emojiCategoryTypeDefault", 1188782699},
    {"emojiCategoryTypeRegularStickers", -1337484846},
    {"emojiCategoryTypeEmojiStatus", 1381282631},
    {"emojiCategoryTypeChatPhoto", 1059063081},
    {"emojiStatus", 973424912},
    {"emojiStatusTypeCustomEmoji", -1666780939},
    {"emojiStatusTypeUpgradedGift", -837921804},
    {"error", -1679978726},
    {"fileTypeNone", 2003009189},
    {"fileTypeAnimation", -290816582},
    {"fileTypeAudio", -709112160},
    {"fileTypeDocument", -564722929},
    {"fileTypeLivePhotoVideo", 444610924},
    {"fileTypeNotificationSound", -1020289271},
    {"fileTypePhoto", -1718914651},
    {"fileTypePhotoStory", 2018995956},
    {"fileTypeProfilePhoto", 1795089315},
    {"fileTypeSecret", -1871899401},
    {"fileTypeSecretThumbnail", -1401326026},
    {"fileTypeSecure", -1419133146},
    {"fileTypeSelfDestructingLivePhotoVideo", -1331098431},
    {"fileTypeSelfDestructingPhoto", 2077176475},
    {"fileTypeSelfDestructingVideo", -1223900123},
    {"fileTypeSelfDestructingVideoNote", 1495274177},
    {"fileTypeSelfDestructingVoiceNote", 1691409181},
    {"fileTypeSticker", 475233385},
    {"fileTypeThumbnail", -12443298},
    {"fileTypeUnknown", -2011566768},
    {"fileTypeVideo", 1430816539},
    {"fileTypeVideoNote", -518412385},
    {"fileTypeVideoStory", -2146754143},
    {"fileTypeVoiceNote", -588681661},
    {"fileTypeWallpaper", 1854930076},
    {"firebaseAuthenticationSettingsAndroid", -1771112932},
    {"firebaseAuthenticationSettingsIos", 222930116},
    {"formattedText", -252624564},
    {"forumTopicIcon", -818765421},
    {"giftForResaleOrderPrice", 1371740258},
    {"giftForResaleOrderPriceChangeDate", -1694144054},
    {"giftForResaleOrderNumber", -1301157632},
    {"giftResalePriceStar", 1184402054},
    {"giftResalePriceTon", -415435950},
    {"giftSettings", 45783168},
    {"giveawayParameters", 1171549354},
    {"groupCallDataChannelMain", -32177779},
    {"groupCallDataChannelScreenSharing", -601649103},
    {"groupCallJoinParameters", 1763438054},
    {"groupCallVideoQualityThumbnail", -379186304},
    {"groupCallVideoQualityMedium", 394968234},
    {"groupCallVideoQualityFull", -2125916617},
    {"importedContact", 1818209156},
    {"inlineKeyboardButton", 1457530830},
    {"inlineKeyboardButtonTypeUrl", 1130741420},
    {"inlineKeyboardButtonTypeLoginUrl", -1203413081},
    {"inlineKeyboardButtonTypeWebApp", -1767471672},
    {"inlineKeyboardButtonTypeCallback", -1127515139},
    {"inlineKeyboardButtonTypeCallbackWithPassword", 908018248},
    {"inlineKeyboardButtonTypeCallbackGame", -383429528},
    {"inlineKeyboardButtonTypeSwitchInline", 544906485},
    {"inlineKeyboardButtonTypeBuy", 1360739440},
    {"inlineKeyboardButtonTypeUser", 1836574114},
    {"inlineKeyboardButtonTypeCopyText", 68883206},
    {"inlineQueryResultsButton", -790689618},
    {"inlineQueryResultsButtonTypeStartBot", -23400235},
    {"inlineQueryResultsButtonTypeWebApp", -1197382814},
    {"inputBackgroundLocal", -1747094364},
    {"inputBackgroundRemote", -274976231},
    {"inputBackgroundPrevious", -351905954},
    {"inputBusinessChatLink", 237858296},
    {"inputBusinessStartPage", -327383072},
    {"inputCallDiscarded", 1956569937},
    {"inputCallFromMessage", 980874855},
    {"inputChatPhotoPrevious", 23128529},
    {"inputChatPhotoStatic", 1979179699},
    {"inputChatPhotoAnimation", 90846242},
    {"inputChatPhotoSticker", 1315861341},
    {"inputChatThemeEmoji", -1461787199},
    {"inputChatThemeGift", 2026976301},
    {"inputChecklist", -145125739},
    {"inputChecklistTask", 1633462225},
    {"inputCredentialsSaved", -2034385364},
    {"inputCredentialsNew", -829689558},
    {"inputCredentialsApplePay", -1246570799},
    {"inputCredentialsGooglePay", 844384100},
    {"inputFileId", 1788906253},
    {"inputFileRemote", -107574466},
    {"inputFileLocal", 2056030919},
    {"inputFileGenerated", -1333385216},
    {"inputGroupCallLink", -812157480},
    {"inputGroupCallMessage", -341793768},
    {"inputIdentityDocument", 767353688},
    {"inputInlineQueryResultAnimation", -1489808874},
    {"inputInlineQueryResultArticle", 1983218620},
    {"inputInlineQueryResultAudio", 1260139988},
    {"inputInlineQueryResultContact", 1846064594},
    {"inputInlineQueryResultDocument", 578801869},
    {"inputInlineQueryResultGame", 966074327},
    {"inputInlineQueryResultLocation", -1887650218},
    {"inputInlineQueryResultPhoto", -1123338721},
    {"inputInlineQueryResultSticker", 274007129},
    {"inputInlineQueryResultVenue", 541704509},
    {"inputInlineQueryResultVideo", 1724073191},
    {"inputInlineQueryResultVoiceNote", -1790072503},
    {"inputInvoiceMessage", 1490872848},
    {"inputInvoiceName", -1312155917},
    {"inputInvoiceTelegram", -1762853139},
    {"inputMessageText", -212805484},
    {"inputMessageAnimation", -210404059},
    {"inputMessageAudio", -626786126},
    {"inputMessageDocument", 1633383097},
    {"inputMessagePaidMedia", -1274819374},
    {"inputMessagePhoto", 163591772},
    {"inputMessageSticker", 1072805625},
    {"inputMessageVideo", -605958271},
    {"inputMessageVideoNote", -714598691},
    {"inputMessageVoiceNote", 1461977004},
    {"inputMessageLocation", 648735088},
    {"inputMessageVenue", 1447926269},
    {"inputMessageContact", -982446849},
    {"inputMessageDice", 841574313},
    {"inputMessageGame", 1252944610},
    {"inputMessageInvoice", -1162047631},
    {"inputMessagePoll", 1305333511},
    {"inputMessageStakeDice", 1946603673},
    {"inputMessageStory", -370732053},
    {"inputMessageChecklist", -1722965261},
    {"inputMessageForwarded", -1076506316},
    {"inputMessageReplyToMessage", 1117785378},
    {"inputMessageReplyToExternalMessage", 1956732638},
    {"inputMessageReplyToStory", -1723842320},
    {"inputPaidMedia", 475844035},
    {"inputPaidMediaTypePhoto", 819520113},
    {"inputPaidMediaTypeVideo", 1793741625},
    {"inputPassportElementPersonalDetails", 164791359},
    {"inputPassportElementPassport", -497011356},
    {"inputPassportElementDriverLicense", 304813264},
    {"inputPassportElementIdentityCard", -9963390},
    {"inputPassportElementInternalPassport", 715360043},
    {"inputPassportElementAddress", 461630480},
    {"inputPassportElementUtilityBill", 1389203841},
    {"inputPassportElementBankStatement", -26585208},
    {"inputPassportElementRentalAgreement", 1736154155},
    {"inputPassportElementPassportRegistration", 1314562128},
    {"inputPassportElementTemporaryRegistration", -1913238047},
    {"inputPassportElementPhoneNumber", 1319357497},
    {"inputPassportElementEmailAddress", -248605659},
    {"inputPassportElementError", 285756898},
    {"inputPassportElementErrorSourceUnspecified", 267230319},
    {"inputPassportElementErrorSourceDataField", -426795002},
    {"inputPassportElementErrorSourceFrontSide", 588023741},
    {"inputPassportElementErrorSourceReverseSide", 413072891},
    {"inputPassportElementErrorSourceSelfie", -773575528},
    {"inputPassportElementErrorSourceTranslationFile", 505842299},
    {"inputPassportElementErrorSourceTranslationFiles", -527254048},
    {"inputPassportElementErrorSourceFile", -298492469},
    {"inputPassportElementErrorSourceFiles", -2008541640},
    {"inputPersonalDocument", 1676966826},
    {"inputPollOption", 1622584516},
    {"inputPollTypeRegular", -236313041},
    {"inputPollTypeQuiz", 877110410},
    {"inputSticker", 1589392402},
    {"inputStoryArea", 122859135},
    {"inputStoryAreaTypeLocation", -1433714887},
    {"inputStoryAreaTypeFoundVenue", -1395809130},
    {"inputStoryAreaTypePreviousVenue", 1846693388},
    {"inputStoryAreaTypeSuggestedReaction", 2101826003},
    {"inputStoryAreaTypeMessage", -266607529},
    {"inputStoryAreaTypeLink", 1408441160},
    {"inputStoryAreaTypeWeather", -1212686691},
    {"inputStoryAreaTypeUpgradedGift", 793059694},
    {"inputStoryAreas", -883247088},
    {"inputStoryContentPhoto", -309196727},
    {"inputStoryContentVideo", 3809243},
    {"inputSuggestedPostInfo", -1246794382},
    {"inputTextQuote", -1219859172},
    {"inputThumbnail", 1582387236},
    {"internalLinkTypeAttachmentMenuBot", 1682719269},
    {"internalLinkTypeAuthenticationCode", -209235982},
    {"internalLinkTypeBackground", 185411848},
    {"internalLinkTypeBotAddToChannel", 1401602752},
    {"internalLinkTypeBotStart", 1066950637},
    {"internalLinkTypeBotStartInGroup", -905081650},
    {"internalLinkTypeBusinessChat", -1606751785},
    {"internalLinkTypeCallsPage", -718405184},
    {"internalLinkTypeChatAffiliateProgram", 632049700},
    {"internalLinkTypeChatBoost", -716571328},
    {"internalLinkTypeChatFolderInvite", -1984804546},
    {"internalLinkTypeChatInvite", 428621017},
    {"internalLinkTypeChatSelection", 621470813},
    {"internalLinkTypeContactsPage", 412195917},
    {"internalLinkTypeDirectMessagesChat", 1795016752},
    {"internalLinkTypeGame", -260788787},
    {"internalLinkTypeGiftAuction", 1724902818},
    {"internalLinkTypeGiftCollection", -812480347},
    {"internalLinkTypeGroupCall", 1953084438},
    {"internalLinkTypeInstantView", 1776607039},
    {"internalLinkTypeInvoice", -213094996},
    {"internalLinkTypeLanguagePack", -1450766996},
    {"internalLinkTypeLiveStory", 665614717},
    {"internalLinkTypeMainWebApp", 1574925033},
    {"internalLinkTypeMessage", 978541650},
    {"internalLinkTypeMessageDraft", 661633749},
    {"internalLinkTypeMyProfilePage", 1204697133},
    {"internalLinkTypeNewChannelChat", -660273891},
    {"internalLinkTypeNewGroupChat", -353196057},
    {"internalLinkTypeNewPrivateChat", -1326134340},
    {"internalLinkTypeNewStory", 1637792663},
    {"internalLinkTypeOauth", 263255628},
    {"internalLinkTypePassportDataRequest", -988819839},
    {"internalLinkTypePhoneNumberConfirmation", 1757375254},
    {"internalLinkTypePremiumFeaturesPage", -626346401},
    {"internalLinkTypePremiumGiftCode", -564356974},
    {"internalLinkTypePremiumGiftPurchase", -947456567},
    {"internalLinkTypeProxy", 1592321116},
    {"internalLinkTypePublicChat", 1769614592},
    {"internalLinkTypeQrCodeAuthentication", -1089332956},
    {"internalLinkTypeRequestManagedBot", 1416354488},
    {"internalLinkTypeRestorePurchases", 606090371},
    {"internalLinkTypeSavedMessages", 248860451},
    {"internalLinkTypeSearch", -591437024},
    {"internalLinkTypeSettings", 574986998},
    {"internalLinkTypeStarPurchase", -459567298},
    {"internalLinkTypeStickerSet", -1589227614},
    {"internalLinkTypeStory", 1852042869},
    {"internalLinkTypeStoryAlbum", -332692184},
    {"internalLinkTypeTheme", -200935417},
    {"internalLinkTypeUnknownDeepLink", 625596379},
    {"internalLinkTypeUpgradedGift", -708405605},
    {"internalLinkTypeUserPhoneNumber", 273398536},
    {"internalLinkTypeUserToken", -1462248615},
    {"internalLinkTypeVideoChat", -2020149068},
    {"internalLinkTypeWebApp", 2062112045},
    {"invoice", 113204876},
    {"jsonObjectMember", -1803309418},
    {"jsonValueNull", -92872499},
    {"jsonValueBoolean", -2142186576},
    {"jsonValueNumber", -1010822033},
    {"jsonValueString", 1597947313},
    {"jsonValueArray", -183913546},
    {"jsonValueObject", 520252026},
    {"keyboardButton", -405853143},
    {"keyboardButtonSourceMessage", 326023575},
    {"keyboardButtonSourceWebApp", -450665232},
    {"keyboardButtonTypeText", -1773037256},
    {"keyboardButtonTypeRequestPhoneNumber", -1529235527},
    {"keyboardButtonTypeRequestLocation", -125661955},
    {"keyboardButtonTypeRequestPoll", 1902435512},
    {"keyboardButtonTypeRequestUsers", -1738765315},
    {"keyboardButtonTypeRequestChat", 1511138485},
    {"keyboardButtonTypeRequestManagedBot", 311203127},
    {"keyboardButtonTypeWebApp", 1892220770},
    {"labeledPricePart", 552789798},
    {"languagePackInfo", 542199642},
    {"languagePackString", 1307632736},
    {"languagePackStringValueOrdinary", -249256352},
    {"languagePackStringValuePluralized", 1906840261},
    {"languagePackStringValueDeleted", 1834792698},
    {"linkPreviewOptions", 1046590451},
    {"location", -443392141},
    {"locationAddress", -1545940190},
    {"logStreamDefault", 1390581436},
    {"logStreamFile", 1532136933},
    {"logStreamEmpty", -499912244},
    {"maskPointForehead", 1027512005},
    {"maskPointEyes", 1748310861},
    {"maskPointMouth", 411773406},
    {"maskPointChin", 534995335},
    {"maskPosition", -2097433026},
    {"messageAutoDeleteTime", 1972045589},
    {"messageCopyOptions", 1079772090},
    {"messageSchedulingStateSendAtDate", 1505903015},
    {"messageSchedulingStateSendWhenOnline", 2092947464},
    {"messageSchedulingStateSendWhenVideoProcessed", 2101578734},
    {"messageSelfDestructTypeTimer", 1351440333},
    {"messageSelfDestructTypeImmediately", -1036218363},
    {"messageSendOptions", -1725581906},
    {"messageSenderUser", -336109341},
    {"messageSenderChat", -239660751},
    {"messageSourceChatHistory", -1090386116},
    {"messageSourceMessageThreadHistory", 290427142},
    {"messageSourceForumTopicHistory", -1518064457},
    {"messageSourceDirectMessagesChatTopicHistory", 1869256503},
    {"messageSourceHistoryPreview", 1024254993},
    {"messageSourceChatList", -2047406102},
    {"messageSourceSearch", 1921333105},
    {"messageSourceChatEventLog", -1028777540},
    {"messageSourceNotification", -1046406163},
    {"messageSourceScreenshot", 469982474},
    {"messageSourceOther", 901818114},
    {"messageTopicThread", 1360920071},
    {"messageTopicForum", 2119440112},
    {"messageTopicDirectMessages", -1285378599},
    {"messageTopicSavedMessages", 588026991},
    {"networkStatisticsEntryFile", 188452706},
    {"networkStatisticsEntryCall", 737000365},
    {"networkTypeNone", -1971691759},
    {"networkTypeMobile", 819228239},
    {"networkTypeMobileRoaming", -1435199760},
    {"networkTypeWiFi", -633872070},
    {"networkTypeOther", 1942128539},
    {"newChatPrivacySettings", 123716192},
    {"notificationSettingsScopePrivateChats", 937446759},
    {"notificationSettingsScopeGroupChats", 1212142067},
    {"notificationSettingsScopeChannelChats", 548013448},
    {"optionValueBoolean", 63135518},
    {"optionValueEmpty", 918955155},
    {"optionValueInteger", -186858780},
    {"optionValueString", 756248212},
    {"orderInfo", 783997294},
    {"paidReactionTypeRegular", -1199187333},
    {"paidReactionTypeAnonymous", 47892621},
    {"paidReactionTypeChat", -675782044},
    {"passportElementTypePersonalDetails", -1032136365},
    {"passportElementTypePassport", -436360376},
    {"passportElementTypeDriverLicense", 1827298379},
    {"passportElementTypeIdentityCard", -502356132},
    {"passportElementTypeInternalPassport", -793781959},
    {"passportElementTypeAddress", 496327874},
    {"passportElementTypeUtilityBill", 627084906},
    {"passportElementTypeBankStatement", 574095667},
    {"passportElementTypeRentalAgreement", -2060583280},
    {"passportElementTypePassportRegistration", -159478209},
    {"passportElementTypeTemporaryRegistration", 1092498527},
    {"passportElementTypePhoneNumber", -995361172},
    {"passportElementTypeEmailAddress", -79321405},
    {"personalDetails", -1061656137},
    {"phoneNumberAuthenticationSettings", 1881885547},
    {"phoneNumberCodeTypeChange", 87144986},
    {"phoneNumberCodeTypeVerify", -1029402661},
    {"phoneNumberCodeTypeConfirmOwnership", -485404696},
    {"premiumFeatureIncreasedLimits", 1785455031},
    {"premiumFeatureIncreasedUploadFileSize", 1825367155},
    {"premiumFeatureImprovedDownloadSpeed", -267695554},
    {"premiumFeatureVoiceRecognition", 1288216542},
    {"premiumFeatureDisabledAds", -2008587702},
    {"premiumFeatureUniqueReactions", 766750743},
    {"premiumFeatureUniqueStickers", -2101773312},
    {"premiumFeatureCustomEmoji", 1332599628},
    {"premiumFeatureAdvancedChatManagement", 796347674},
    {"premiumFeatureProfileBadge", 233648322},
    {"premiumFeatureEmojiStatus", -36516639},
    {"premiumFeatureAnimatedProfilePhoto", -100741914},
    {"premiumFeatureForumTopicIcon", -823172286},
    {"premiumFeatureAppIcons", 1585050761},
    {"premiumFeatureRealTimeChatTranslation", -1143471488},
    {"premiumFeatureUpgradedStories", -1878522597},
    {"premiumFeatureChatBoost", 1576574747},
    {"premiumFeatureAccentColor", 907724190},
    {"premiumFeatureBackgroundForBoth", 575074042},
    {"premiumFeatureSavedMessagesTags", 1003219334},
    {"premiumFeatureMessagePrivacy", 802322678},
    {"premiumFeatureLastSeenTimes", -762230129},
    {"premiumFeatureBusiness", -1503619324},
    {"premiumFeatureMessageEffects", -723300255},
    {"premiumFeatureChecklists", -1128709251},
    {"premiumFeaturePaidMessages", -2063708431},
    {"premiumFeatureProtectPrivateChatContent", -565938675},
    {"premiumFeatureTextComposition", 210899877},
    {"premiumLimitTypeSupergroupCount", -247467131},
    {"premiumLimitTypePinnedChatCount", -998947871},
    {"premiumLimitTypeCreatedPublicChatCount", 446086841},
    {"premiumLimitTypeSavedAnimationCount", -19759735},
    {"premiumLimitTypeFavoriteStickerCount", 639754787},
    {"premiumLimitTypeChatFolderCount", 377489774},
    {"premiumLimitTypeChatFolderChosenChatCount", 1691435861},
    {"premiumLimitTypePinnedArchivedChatCount", 1485515276},
    {"premiumLimitTypePinnedSavedMessagesTopicCount", -1544854305},
    {"premiumLimitTypeCaptionLength", 293984314},
    {"premiumLimitTypeBioLength", -1146976765},
    {"premiumLimitTypeChatFolderInviteLinkCount", -128702950},
    {"premiumLimitTypeShareableChatFolderCount", 1612625095},
    {"premiumLimitTypeActiveStoryCount", -1926486372},
    {"premiumLimitTypeWeeklyPostedStoryCount", -506354313},
    {"premiumLimitTypeMonthlyPostedStoryCount", 26329490},
    {"premiumLimitTypeStoryCaptionLength", -1093324030},
    {"premiumLimitTypeStorySuggestedReactionAreaCount", -1170032633},
    {"premiumLimitTypeSimilarChatCount", -1563549935},
    {"premiumLimitTypeOwnedBotCount", -595906175},
    {"premiumSourceLimitExceeded", -2052159742},
    {"premiumSourceFeature", 445813541},
    {"premiumSourceBusinessFeature", -1492946340},
    {"premiumSourceStoryFeature", -1030737556},
    {"premiumSourceLink", 2135071132},
    {"premiumSourceSettings", -285702859},
    {"premiumStoryFeaturePriorityOrder", -1880001849},
    {"premiumStoryFeatureStealthMode", 1194605988},
    {"premiumStoryFeaturePermanentViewsHistory", -1029683296},
    {"premiumStoryFeatureCustomExpirationDuration", -593229162},
    {"premiumStoryFeatureSaveStories", -1501286467},
    {"premiumStoryFeatureLinksAndFormatting", -622623753},
    {"premiumStoryFeatureVideoQuality", -1162887511},
    {"profileTabPosts", -1181952362},
    {"profileTabGifts", 1296815210},
    {"profileTabMedia", 1925597525},
    {"profileTabFiles", -1422681088},
    {"profileTabLinks", -748329831},
    {"profileTabMusic", -1624780178},
    {"profileTabVoice", -461960914},
    {"profileTabGifs", -1564412267},
    {"proxy", -1636386947},
    {"proxyTypeSocks5", -890027341},
    {"proxyTypeHttp", -1547188361},
    {"proxyTypeMtproto", -1964826627},
    {"publicChatTypeHasUsername", 350789758},
    {"publicChatTypeIsLocationBased", 1183735952},
    {"reactionNotificationSettings", 2074932258},
    {"reactionNotificationSourceNone", 366374940},
    {"reactionNotificationSourceContacts", 555501621},
    {"reactionNotificationSourceAll", 1241689234},
    {"reactionTypeEmoji", -1942084920},
    {"reactionTypeCustomEmoji", -989117709},
    {"reactionTypePaid", 436294381},
    {"readDatePrivacySettings", 1654842920},
    {"replyMarkupRemoveKeyboard", -691252879},
    {"replyMarkupForceReply", 1101461919},
    {"replyMarkupShowKeyboard", -791495984},
    {"replyMarkupInlineKeyboard", -619317658},
    {"reportReasonSpam", -1207032897},
    {"reportReasonViolence", 2038679353},
    {"reportReasonPornography", 1306467575},
    {"reportReasonChildAbuse", 761086718},
    {"reportReasonCopyright", 1474441135},
    {"reportReasonUnrelatedLocation", 87562288},
    {"reportReasonFake", 352862176},
    {"reportReasonIllegalDrugs", -61599200},
    {"reportReasonPersonalDetails", -1588882414},
    {"reportReasonCustom", -1380459917},
    {"resendCodeReasonUserRequest", -441923456},
    {"resendCodeReasonVerificationFailed", 529870273},
    {"scopeAutosaveSettings", 1546821427},
    {"scopeNotificationSettings", 88369150},
    {"searchMessagesChatTypeFilterPrivate", 1169248975},
    {"searchMessagesChatTypeFilterGroup", -2059426022},
    {"searchMessagesChatTypeFilterChannel", -773540139},
    {"searchMessagesFilterEmpty", -869395657},
    {"searchMessagesFilterAnimation", -155713339},
    {"searchMessagesFilterAudio", 867505275},
    {"searchMessagesFilterDocument", 1526331215},
    {"searchMessagesFilterPhoto", 925932293},
    {"searchMessagesFilterPoll", -891598785},
    {"searchMessagesFilterVideo", 115538222},
    {"searchMessagesFilterVoiceNote", 1841439357},
    {"searchMessagesFilterPhotoAndVideo", 1352130963},
    {"searchMessagesFilterUrl", -1828724341},
    {"searchMessagesFilterChatPhoto", -1247751329},
    {"searchMessagesFilterVideoNote", 564323321},
    {"searchMessagesFilterVoiceAndVideoNote", 664174819},
    {"searchMessagesFilterMention", 2001258652},
    {"searchMessagesFilterUnreadMention", -95769149},
    {"searchMessagesFilterUnreadReaction", -1379651328},
    {"searchMessagesFilterUnreadPollVote", -161318950},
    {"searchMessagesFilterFailedToSend", -596322564},
    {"searchMessagesFilterPinned", 371805512},
    {"settingsSectionAppearance", 946479657},
    {"settingsSectionAskQuestion", -977295684},
    {"settingsSectionBusiness", 2035727714},
    {"settingsSectionChatFolders", -1689092795},
    {"settingsSectionDataAndStorage", -677345873},
    {"settingsSectionDevices", 1987641411},
    {"settingsSectionEditProfile", 654959232},
    {"settingsSectionFaq", 689162381},
    {"settingsSectionFeatures", 434930782},
    {"settingsSectionInAppBrowser", 1762505859},
    {"settingsSectionLanguage", 2102087062},
    {"settingsSectionMyStars", 324987676},
    {"settingsSectionMyToncoins", 1628818474},
    {"settingsSectionNotifications", 1517744502},
    {"settingsSectionPowerSaving", 1041090092},
    {"settingsSectionPremium", 1635573221},
    {"settingsSectionPrivacyAndSecurity", -1251665482},
    {"settingsSectionPrivacyPolicy", -2068087969},
    {"settingsSectionQrCode", 1816314456},
    {"settingsSectionSearch", 686700184},
    {"settingsSectionSendGift", -326078},
    {"shippingOption", 1425690001},
    {"starSubscriptionPricing", -1767733162},
    {"stickerFormatWebp", -2123043040},
    {"stickerFormatTgs", 1614588662},
    {"stickerFormatWebm", -2070162097},
    {"stickerTypeRegular", 56345973},
    {"stickerTypeMask", -1765394796},
    {"stickerTypeCustomEmoji", -120752249},
    {"storePaymentPurposePremiumSubscription", 1263894804},
    {"storePaymentPurposePremiumGift", -39502443},
    {"storePaymentPurposePremiumGiftCodes", -1072286736},
    {"storePaymentPurposePremiumGiveaway", 1302624938},
    {"storePaymentPurposeStarGiveaway", 211212441},
    {"storePaymentPurposeStars", 410189263},
    {"storePaymentPurposeGiftedStars", 893691428},
    {"storeTransactionAppStore", 1625562441},
    {"storeTransactionGooglePlay", 1094018617},
    {"storyAreaPosition", -1533023124},
    {"storyContentTypePhoto", -1568510965},
    {"storyContentTypeVideo", -573976899},
    {"storyContentTypeLive", -659651117},
    {"storyContentTypeUnsupported", 642311105},
    {"storyFullId", 765952419},
    {"storyListMain", -672222209},
    {"storyListArchive", -41900223},
    {"storyPrivacySettingsEveryone", 890847843},
    {"storyPrivacySettingsContacts", 50285309},
    {"storyPrivacySettingsCloseFriends", 2097122144},
    {"storyPrivacySettingsSelectedUsers", -1885772602},
    {"suggestedActionEnableArchiveAndMuteNewChats", 2017586255},
    {"suggestedActionCheckPassword", 1910534839},
    {"suggestedActionCheckPhoneNumber", 648771563},
    {"suggestedActionViewChecksHint", 891303239},
    {"suggestedActionConvertToBroadcastGroup", -965071304},
    {"suggestedActionSetPassword", 1863613848},
    {"suggestedActionUpgradePremium", 1890220539},
    {"suggestedActionRestorePremium", -385229468},
    {"suggestedActionSubscribeToAnnualPremium", 373913787},
    {"suggestedActionGiftPremiumForChristmas", -1816924561},
    {"suggestedActionSetBirthdate", -356672766},
    {"suggestedActionSetProfilePhoto", -1612563093},
    {"suggestedActionExtendPremium", -566207286},
    {"suggestedActionExtendStarSubscriptions", -47000234},
    {"suggestedActionCustom", 2092876611},
    {"suggestedActionSetLoginEmailAddress", 1557625160},
    {"suggestedActionAddLoginPasskey", 1186248690},
    {"suggestedPostPriceStar", 216488903},
    {"suggestedPostPriceTon", -1095222334},
    {"supergroupMembersFilterRecent", 1178199509},
    {"supergroupMembersFilterContacts", -1282910856},
    {"supergroupMembersFilterAdministrators", -2097380265},
    {"supergroupMembersFilterSearch", -1696358469},
    {"supergroupMembersFilterRestricted", -1107800034},
    {"supergroupMembersFilterBanned", -1210621683},
    {"supergroupMembersFilterMention", 1151301973},
    {"supergroupMembersFilterBots", 492138918},
    {"targetChatCurrent", -416689904},
    {"targetChatChosen", -1392978522},
    {"targetChatInternalLink", -579301408},
    {"targetChatTypes", 1513098833},
    {"telegramPaymentPurposePremiumGift", -1600286150},
    {"telegramPaymentPurposePremiumGiftCodes", -1863495348},
    {"telegramPaymentPurposePremiumGiveaway", -760757441},
    {"telegramPaymentPurposeStars", 1204968037},
    {"telegramPaymentPurposeGiftedStars", -1850308042},
    {"telegramPaymentPurposeStarGiveaway", 1014604689},
    {"telegramPaymentPurposeJoinChat", -1914869880},
    {"testInt", -574804983},
    {"testString", -27891572},
    {"textEntity", -1951688280},
    {"textEntityTypeMention", 934535013},
    {"textEntityTypeHashtag", -1023958307},
    {"textEntityTypeCashtag", 1222915915},
    {"textEntityTypeBotCommand", -1150997581},
    {"textEntityTypeUrl", -1312762756},
    {"textEntityTypeEmailAddress", 1425545249},
    {"textEntityTypePhoneNumber", -1160140246},
    {"textEntityTypeBankCardNumber", 105986320},
    {"textEntityTypeBold", -1128210000},
    {"textEntityTypeItalic", -118253987},
    {"textEntityTypeUnderline", 792317842},
    {"textEntityTypeStrikethrough", 961529082},
    {"textEntityTypeSpoiler", 544019899},
    {"textEntityTypeCode", -974534326},
    {"textEntityTypePre", 1648958606},
    {"textEntityTypePreCode", -945325397},
    {"textEntityTypeBlockQuote", -1003999032},
    {"textEntityTypeExpandableBlockQuote", 36572261},
    {"textEntityTypeTextUrl", 445719651},
    {"textEntityTypeMentionName", -1570974289},
    {"textEntityTypeCustomEmoji", 1724820677},
    {"textEntityTypeMediaTimestamp", -1841898992},
    {"textEntityTypeDateTime", -1544268588},
    {"textParseModeMarkdown", 360073407},
    {"textParseModeHTML", 1660208627},
    {"themeParameters", -276589137},
    {"topChatCategoryUsers", 1026706816},
    {"topChatCategoryBots", -1577129195},
    {"topChatCategoryGroups", 1530056846},
    {"topChatCategoryChannels", -500825885},
    {"topChatCategoryInlineBots", 377023356},
    {"topChatCategoryWebAppBots", 100062973},
    {"topChatCategoryCalls", 356208861},
    {"topChatCategoryForwardChats", 1695922133},
    {"transactionDirectionIncoming", -271074103},
    {"transactionDirectionOutgoing", 1638241254},
    {"upgradedGiftAttributeIdModel", 1053287307},
    {"upgradedGiftAttributeIdSymbol", 1188205608},
    {"upgradedGiftAttributeIdBackdrop", 1461997935},
    {"upgradedGiftBackdropColors", 4227529},
    {"userPrivacySettingShowStatus", 1862829310},
    {"userPrivacySettingShowProfilePhoto", 1408485877},
    {"userPrivacySettingShowLinkInForwardedMessages", 592688870},
    {"userPrivacySettingShowPhoneNumber", -791567831},
    {"userPrivacySettingShowBio", 959981409},
    {"userPrivacySettingShowBirthdate", 1167504607},
    {"userPrivacySettingShowProfileAudio", 610353549},
    {"userPrivacySettingAllowChatInvites", 1271668007},
    {"userPrivacySettingAllowCalls", -906967291},
    {"userPrivacySettingAllowPeerToPeerCalls", 352500032},
    {"userPrivacySettingAllowFindingByPhoneNumber", -1846645423},
    {"userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages", 338112060},
    {"userPrivacySettingAutosaveGifts", 1889167821},
    {"userPrivacySettingAllowUnpaidMessages", 1430051047},
    {"userPrivacySettingRuleAllowAll", -1967186881},
    {"userPrivacySettingRuleAllowContacts", -1892733680},
    {"userPrivacySettingRuleAllowBots", 1404208925},
    {"userPrivacySettingRuleAllowPremiumUsers", 1624147265},
    {"userPrivacySettingRuleAllowUsers", 1110988334},
    {"userPrivacySettingRuleAllowChatMembers", -2048749863},
    {"userPrivacySettingRuleRestrictAll", -1406495408},
    {"userPrivacySettingRuleRestrictContacts", 1008389378},
    {"userPrivacySettingRuleRestrictBots", -1902547363},
    {"userPrivacySettingRuleRestrictUsers", 622796522},
    {"userPrivacySettingRuleRestrictChatMembers", 392530897},
    {"userPrivacySettingRules", 322477541},
    {"venue", 1070406393},
    {"webAppOpenModeCompact", 1711603675},
    {"webAppOpenModeFullSize", 189320513},
    {"webAppOpenModeFullScreen", 1871315357},
    {"webAppOpenParameters", 1375356527}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::Function *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"acceptCall", -646618416},
    {"acceptOauthRequest", -427442108},
    {"acceptTermsOfService", 2130576356},
    {"activateStoryStealthMode", -1009023855},
    {"addBotMediaPreview", 1347126571},
    {"addChatFolderByInviteLink", -858593816},
    {"addChatMember", 1720144407},
    {"addChatMembers", -1675991329},
    {"addChatToList", -80523595},
    {"addChecklistTasks", 1554619499},
    {"addContact", -2098628252},
    {"addCustomServerLanguagePack", 4492771},
    {"addFavoriteSticker", 324504799},
    {"addFileToDownloads", 867533751},
    {"addGiftCollectionGifts", -263464606},
    {"addLocalMessage", -166217823},
    {"addLogMessage", 1597427692},
    {"addLoginPasskey", 1838899694},
    {"addMessageReaction", 1419269613},
    {"addNetworkStatistics", 1264825305},
    {"addOffer", 682451739},
    {"addPendingLiveStoryReaction", 661166197},
    {"addPendingPaidMessageReaction", -342110765},
    {"addPollOption", -382845167},
    {"addProfileAudio", 393218847},
    {"addProxy", 471098860},
    {"addQuickReplyShortcutInlineQueryResultMessage", -2017449468},
    {"addQuickReplyShortcutMessage", 1058573098},
    {"addQuickReplyShortcutMessageAlbum", 1348436244},
    {"addRecentSticker", -1478109026},
    {"addRecentlyFoundChat", -1746396787},
    {"addSavedAnimation", -1538525088},
    {"addSavedNotificationSound", 1043956975},
    {"addStickerToSet", 1457266235},
    {"addStoryAlbumStories", -537692984},
    {"allowBotToSendMessages", 1776928142},
    {"allowUnpaidMessagesFromUser", 803569495},
    {"answerCallbackQuery", -1153028490},
    {"answerCustomQuery", -1293603521},
    {"answerInlineQuery", 1343853844},
    {"answerPreCheckoutQuery", -1486789653},
    {"answerShippingQuery", -434601324},
    {"answerWebAppQuery", -1598776079},
    {"applyPremiumGiftCode", -1347138530},
    {"approveSuggestedPost", -924807202},
    {"assignStoreTransaction", -2046202900},
    {"banChatMember", -888111748},
    {"banGroupCallParticipants", 624883173},
    {"blockMessageSenderFromReplies", -1214384757},
    {"boostChat", 1945750252},
    {"buyGiftUpgrade", 154296026},
    {"canBotSendMessages", 544052364},
    {"canPostStory", 668621518},
    {"canPurchaseFromStore", 1017811816},
    {"canSendGift", 1307059830},
    {"canSendMessageToUser", 1529489462},
    {"canTransferOwnership", 634602508},
    {"cancelDownloadFile", -1954524450},
    {"cancelPasswordReset", 940733538},
    {"cancelPreliminaryUploadFile", 823412414},
    {"cancelRecoveryEmailAddressVerification", -1516728691},
    {"changeImportedContacts", 1119625871},
    {"changeStickerSet", 449357293},
    {"checkAuthenticationBotToken", 639321206},
    {"checkAuthenticationCode", -302103382},
    {"checkAuthenticationEmailCode", -582827361},
    {"checkAuthenticationPasskey", 1225325317},
    {"checkAuthenticationPassword", -2025698400},
    {"checkAuthenticationPasswordRecoveryCode", -603309083},
    {"checkAuthenticationPremiumPurchase", 1588959934},
    {"checkBotUsername", -1358454679},
    {"checkChatFolderInviteLink", 522557851},
    {"checkChatInviteLink", -496940997},
    {"checkChatUsername", -119119344},
    {"checkCreatedPublicChatsLimit", -445546591},
    {"checkEmailAddressVerificationCode", -426386685},
    {"checkLoginEmailAddressCode", -1454244766},
    {"checkOauthRequestMatchCode", -1383896724},
    {"checkPasswordRecoveryCode", -200794600},
    {"checkPhoneNumberCode", -603626079},
    {"checkPremiumGiftCode", -1786063260},
    {"checkQuickReplyShortcutName", 2101203241},
    {"checkRecoveryEmailAddressCode", -1997039589},
    {"checkStickerSetName", -1789392642},
    {"checkWebAppFileDownload", -389397278},
    {"cleanFileName", 967964667},
    {"clearAllDraftMessages", -46369573},
    {"clearAutosaveSettingsExceptions", 1475109874},
    {"clearImportedContacts", 869503298},
    {"clearRecentEmojiStatuses", -428749986},
    {"clearRecentReactions", 1298253650},
    {"clearRecentStickers", -321242684},
    {"clearRecentlyFoundChats", -285582542},
    {"clearSearchedForTags", 512017238},
    {"clickAnimatedEmojiMessage", 196179554},
    {"clickChatSponsoredMessage", 971995671},
    {"clickPremiumSubscriptionButton", -369319162},
    {"clickVideoMessageAdvertisement", 1367156622},
    {"close", -1187782273},
    {"closeChat", 39749353},
    {"closeGiftAuction", 115495644},
    {"closeSecretChat", -471006133},
    {"closeStory", 1553967851},
    {"closeWebApp", 1755391174},
    {"commitPendingLiveStoryReactions", -1786229016},
    {"commitPendingPaidMessageReactions", -171354618},
    {"composeTextWithAi", 1121392794},
    {"confirmQrCodeAuthentication", -376199379},
    {"confirmSession", -674647009},
    {"connectAffiliateProgram", 1661392684},
    {"craftGift", 2124593259},
    {"createBasicGroupChat", 1972024548},
    {"createBot", -1890858327},
    {"createBusinessChatLink", -1861018304},
    {"createCall", -1104663024},
    {"createChatFolder", 1015399680},
    {"createChatFolderInviteLink", -2037911099},
    {"createChatInviteLink", 287744833},
    {"createChatSubscriptionInviteLink", 2255717},
    {"createForumTopic", -15242103},
    {"createGiftCollection", -397088099},
    {"createGroupCall", 1930068672},
    {"createInvoiceLink", -814692249},
    {"createNewBasicGroupChat", 1806454709},
    {"createNewSecretChat", -620682651},
    {"createNewStickerSet", -481065727},
    {"createNewSupergroupChat", 804058822},
    {"createPrivateChat", -947758327},
    {"createSecretChat", 1930285615},
    {"createStoryAlbum", -804362185},
    {"createSupergroupChat", 1187475691},
    {"createTemporaryPassword", -1626509434},
    {"createVideoChat", 2124715405},
    {"declineGroupCallInvitation", 1843919377},
    {"declineOauthRequest", 420650996},
    {"declineSuggestedPost", -1758260609},
    {"decryptGroupCallData", 1781743076},
    {"deleteAccount", 1395816134},
    {"deleteAllCallMessages", -1466445325},
    {"deleteAllRevokedChatInviteLinks", 1112020698},
    {"deleteBotMediaPreviews", -1397512722},
    {"deleteBusinessChatLink", -1101895865},
    {"deleteBusinessConnectedBot", -1633976747},
    {"deleteBusinessMessages", 1425721828},
    {"deleteBusinessStory", 1024585042},
    {"deleteChat", -171253666},
    {"deleteChatBackground", 320267896},
    {"deleteChatFolder", -1956364551},
    {"deleteChatFolderInviteLink", -930057858},
    {"deleteChatHistory", -1472081761},
    {"deleteChatMessagesByDate", -1639653185},
    {"deleteChatMessagesBySender", -1164235161},
    {"deleteChatReplyMarkup", 100637531},
    {"deleteCommands", 1002732586},
    {"deleteDefaultBackground", -1297814210},
    {"deleteDirectMessagesChatTopicHistory", -1906080196},
    {"deleteDirectMessagesChatTopicMessagesByDate", 945080841},
    {"deleteFile", 1807653676},
    {"deleteForumTopic", -2121212039},
    {"deleteGiftCollection", -183749499},
    {"deleteGroupCallMessages", 339562398},
    {"deleteGroupCallMessagesBySender", 1677247618},
    {"deleteLanguagePack", -2108761026},
    {"deleteMessages", 1130090173},
    {"deletePassportElement", -1719555468},
    {"deletePollOption", -1459634839},
    {"deleteProfilePhoto", 1319794625},
    {"deleteQuickReplyShortcut", -246911978},
    {"deleteQuickReplyShortcutMessages", -40522947},
    {"deleteRevokedChatInviteLink", -1859711873},
    {"deleteSavedCredentials", 826300114},
    {"deleteSavedMessagesTopicHistory", 1776237930},
    {"deleteSavedMessagesTopicMessagesByDate", 1444389},
    {"deleteSavedOrderInfo", 1629058164},
    {"deleteStickerSet", 1577745325},
    {"deleteStory", -2020144472},
    {"deleteStoryAlbum", -658327628},
    {"destroy", 685331274},
    {"disableAllSupergroupUsernames", 843511216},
    {"disableProxy", -2100095102},
    {"discardCall", -1545983346},
    {"disconnectAffiliateProgram", -105831172},
    {"disconnectAllWebsites", -1082985981},
    {"disconnectWebsite", -778767395},
    {"downloadFile", 1059402292},
    {"dropGiftOriginalDetails", -1394445843},
    {"editBotMediaPreview", -2037031582},
    {"editBusinessChatLink", 1594947110},
    {"editBusinessMessageCaption", -1071562045},
    {"editBusinessMessageChecklist", -445013904},
    {"editBusinessMessageLiveLocation", 494972447},
    {"editBusinessMessageMedia", -60733576},
    {"editBusinessMessageReplyMarkup", 701787159},
    {"editBusinessMessageText", -1149169252},
    {"editBusinessStory", 472538940},
    {"editChatFolder", 53672754},
    {"editChatFolderInviteLink", -2141872095},
    {"editChatInviteLink", 1320303996},
    {"editChatSubscriptionInviteLink", -951826989},
    {"editCustomLanguagePackInfo", 1320751257},
    {"editForumTopic", 1112389547},
    {"editInlineMessageCaption", 1409762552},
    {"editInlineMessageLiveLocation", 2134352044},
    {"editInlineMessageMedia", 23553921},
    {"editInlineMessageReplyMarkup", -67565858},
    {"editInlineMessageText", -855457307},
    {"editMessageCaption", -2020117951},
    {"editMessageChecklist", 1497856700},
    {"editMessageLiveLocation", -1890511980},
    {"editMessageMedia", -1152678125},
    {"editMessageReplyMarkup", 332127881},
    {"editMessageSchedulingState", -1372976192},
    {"editMessageText", 196272567},
    {"editProxy", -1648824814},
    {"editQuickReplyMessage", 80517006},
    {"editStarSubscription", 2048538904},
    {"editStory", 355296788},
    {"editStoryCover", -1035823266},
    {"editUserStarSubscription", 1370582665},
    {"enableProxy", 1494450838},
    {"encryptGroupCallData", -377997690},
    {"endGroupCall", 573131959},
    {"endGroupCallRecording", -75799927},
    {"endGroupCallScreenSharing", -2047599540},
    {"finishFileGeneration", -1055060835},
    {"fixTextWithAi", -2139647563},
    {"forwardMessages", -247889118},
    {"getAccountTtl", -443905161},
    {"getActiveSessions", 1119710526},
    {"getAllPassportElements", -2038945045},
    {"getAllStickerEmojis", 296562224},
    {"getAnimatedEmoji", 1065635702},
    {"getApplicationConfig", -1823144318},
    {"getApplicationDownloadLink", 112013252},
    {"getArchiveChatListSettings", -2087874976},
    {"getArchivedStickerSets", 1001931341},
    {"getAttachedStickerSets", 1302172429},
    {"getAttachmentMenuBot", 1034248699},
    {"getAuthenticationPasskeyParameters", -686037865},
    {"getAuthorizationState", 1949154877},
    {"getAutoDownloadSettingsPresets", -1721088201},
    {"getAutosaveSettings", 2136207914},
    {"getAvailableChatBoostSlots", 1929898965},
    {"getAvailableGifts", -4559695},
    {"getBackgroundUrl", 733769682},
    {"getBankCardInfo", -1310515792},
    {"getBasicGroup", -1635174828},
    {"getBasicGroupFullInfo", -1822039253},
    {"getBlockedMessageSenders", -1931137258},
    {"getBotInfoDescription", -762841035},
    {"getBotInfoShortDescription", 1243358740},
    {"getBotMediaPreviewInfo", 1358299446},
    {"getBotMediaPreviews", 577131608},
    {"getBotName", -1707118036},
    {"getBotSimilarBotCount", -1271545369},
    {"getBotSimilarBots", -825139275},
    {"getBotToken", 1197197145},
    {"getBusinessAccountStarAmount", -1817136693},
    {"getBusinessChatLinkInfo", 797670986},
    {"getBusinessChatLinks", 710287703},
    {"getBusinessConnectedBot", 911058883},
    {"getBusinessConnection", -2114706400},
    {"getBusinessFeatures", -997171199},
    {"getCallbackQueryAnswer", 116357727},
    {"getCallbackQueryMessage", -1121939086},
    {"getChat", 1866601536},
    {"getChatActiveStories", 776993781},
    {"getChatAdministrators", 1544468155},
    {"getChatArchivedStories", -1356950392},
    {"getChatAvailableMessageSenders", 1158670635},
    {"getChatAvailablePaidMessageReactionSenders", -1244619639},
    {"getChatBoostFeatures", -389994336},
    {"getChatBoostLevelFeatures", 1172717195},
    {"getChatBoostLink", 1458662533},
    {"getChatBoostLinkInfo", 654068572},
    {"getChatBoostStatus", -810775857},
    {"getChatBoosts", -1419859400},
    {"getChatEventLog", -1281344669},
    {"getChatFolder", 92809880},
    {"getChatFolderChatCount", 2111097790},
    {"getChatFolderChatsToLeave", -1916672337},
    {"getChatFolderDefaultIconName", 754425959},
    {"getChatFolderInviteLinks", 329079776},
    {"getChatFolderNewChats", 2123181260},
    {"getChatHistory", -799960451},
    {"getChatInviteLink", -479575555},
    {"getChatInviteLinkCounts", 890299025},
    {"getChatInviteLinkMembers", 1728376124},
    {"getChatInviteLinks", 883252396},
    {"getChatJoinRequests", -388428126},
    {"getChatListsToAddChat", 654956193},
    {"getChatMember", -792636814},
    {"getChatMessageByDate", 1062564150},
    {"getChatMessageCalendar", 1644001372},
    {"getChatMessageCount", 1641001101},
    {"getChatMessagePosition", -1468174577},
    {"getChatNotificationSettingsExceptions", 201199121},
    {"getChatOwnerAfterLeaving", -1637776102},
    {"getChatPinnedMessage", 359865008},
    {"getChatPostedToChatPageStories", -46414037},
    {"getChatRevenueStatistics", 701995836},
    {"getChatRevenueTransactions", -1120110117},
    {"getChatRevenueWithdrawalUrl", 506595104},
    {"getChatScheduledMessages", -549638149},
    {"getChatSimilarChatCount", 1178506894},
    {"getChatSimilarChats", -1152348285},
    {"getChatSparseMessagePositions", 994389757},
    {"getChatSponsoredMessages", 1353203864},
    {"getChatStatistics", 327057816},
    {"getChatStoryAlbums", -1559582892},
    {"getChatStoryInteractions", 354545268},
    {"getChats", -972768574},
    {"getChatsForChatFolderInviteLink", 1873561929},
    {"getChatsToPostStories", 1893901427},
    {"getCloseFriends", -1445628722},
    {"getCollectibleItemInfo", -217797238},
    {"getCommands", 1488621559},
    {"getConnectedAffiliateProgram", -1755191440},
    {"getConnectedAffiliatePrograms", -1960029582},
    {"getConnectedWebsites", -170536110},
    {"getContacts", -1417722768},
    {"getCountries", -51902050},
    {"getCountryCode", 1540593906},
    {"getCountryFlagEmoji", 981871098},
    {"getCreatedPublicChats", 710354415},
    {"getCurrentState", -1191417719},
    {"getCurrentWeather", -1965384759},
    {"getCustomEmojiReactionAnimations", 1232375250},
    {"getCustomEmojiStickers", -2127427955},
    {"getDatabaseStatistics", -1942760263},
    {"getDeepLinkInfo", 680673150},
    {"getDefaultBackgroundCustomEmojiStickers", 485910542},
    {"getDefaultChatEmojiStatuses", 1553698018},
    {"getDefaultChatPhotoCustomEmojiStickers", -376342683},
    {"getDefaultEmojiStatuses", -539392025},
    {"getDefaultMessageAutoDeleteTime", -450857574},
    {"getDefaultProfilePhotoCustomEmojiStickers", 1280041655},
    {"getDirectMessagesChatTopic", 1990530052},
    {"getDirectMessagesChatTopicHistory", 1035221188},
    {"getDirectMessagesChatTopicMessageByDate", 1837500879},
    {"getDirectMessagesChatTopicRevenue", -792382961},
    {"getDisallowedChatEmojiStatuses", -2004787831},
    {"getEmojiCategories", 2139537774},
    {"getEmojiReaction", -449572388},
    {"getEmojiSuggestionsUrl", -1404101841},
    {"getExternalLink", 1586688235},
    {"getExternalLinkInfo", 1175288383},
    {"getFavoriteStickers", -338964672},
    {"getFile", 1553923406},
    {"getFileDownloadedPrefixSize", 855948589},
    {"getFileExtension", -106055372},
    {"getFileMimeType", -2073879671},
    {"getForumTopic", 1931459984},
    {"getForumTopicDefaultIcons", 1479898332},
    {"getForumTopicHistory", -339129791},
    {"getForumTopicLink", 330405972},
    {"getForumTopics", 1368275676},
    {"getGameHighScores", 15746459},
    {"getGiftAuctionAcquiredGifts", -937975215},
    {"getGiftAuctionState", 989210247},
    {"getGiftChatThemes", -1051327876},
    {"getGiftCollections", -1533138835},
    {"getGiftUpgradePreview", 1303475628},
    {"getGiftsForCrafting", 1571822730},
    {"getGiveawayInfo", -1215852357},
    {"getGreetingStickers", 374873372},
    {"getGrossingWebAppBots", 1696779802},
    {"getGroupCall", 1468491406},
    {"getGroupCallParticipants", 1986739394},
    {"getGroupCallStreamSegment", -502273424},
    {"getGroupCallStreams", -1619226268},
    {"getGroupsInCommon", 381539178},
    {"getImportedContactCount", -656336346},
    {"getInactiveSupergroupChats", -657720907},
    {"getInlineGameHighScores", -533107798},
    {"getInlineQueryResults", 2044524652},
    {"getInstalledBackgrounds", -1051406241},
    {"getInstalledStickerSets", 1630467830},
    {"getInternalLink", 962654640},
    {"getInternalLinkType", -1948428535},
    {"getJsonString", 663458849},
    {"getJsonValue", -1829086715},
    {"getKeywordEmojis", -1969795990},
    {"getLanguagePackInfo", 2077809320},
    {"getLanguagePackString", 150789747},
    {"getLanguagePackStrings", 1246259088},
    {"getLinkPreview", -1039572191},
    {"getLiveStoryAvailableMessageSenders", 1252390532},
    {"getLiveStoryRtmpUrl", 1267168178},
    {"getLiveStoryStreamer", -718164721},
    {"getLiveStoryTopDonors", -700264064},
    {"getLocalizationTargetInfo", 1849499526},
    {"getLogStream", 1167608667},
    {"getLogTagVerbosityLevel", 951004547},
    {"getLogTags", -254449190},
    {"getLogVerbosityLevel", 594057956},
    {"getLoginPasskeys", -165927873},
    {"getLoginUrl", 791844305},
    {"getLoginUrlInfo", -859202125},
    {"getMainWebApp", 594050214},
    {"getMapThumbnailFile", -152660070},
    {"getMarkdownText", 164524584},
    {"getMe", -191516033},
    {"getMenuButton", -437324736},
    {"getMessage", -1821196160},
    {"getMessageAddedReactions", 2110172754},
    {"getMessageAuthor", 1890166449},
    {"getMessageAvailableReactions", 1994098354},
    {"getMessageEffect", -1638843116},
    {"getMessageEmbeddingCode", 1654967561},
    {"getMessageFileType", -490270764},
    {"getMessageImportConfirmationText", 390627752},
    {"getMessageLink", -498469915},
    {"getMessageLinkInfo", -700533672},
    {"getMessageLocally", -603575444},
    {"getMessageProperties", 773382571},
    {"getMessagePublicForwards", 1369285812},
    {"getMessageReadDate", -1484455101},
    {"getMessageStatistics", 1270194648},
    {"getMessageThread", 2062695998},
    {"getMessageThreadHistory", -1808411608},
    {"getMessageViewers", -1584457010},
    {"getMessages", 425299338},
    {"getNetworkStatistics", -986228706},
    {"getNewChatPrivacySettings", -1295299657},
    {"getOauthLinkInfo", -1235634833},
    {"getOption", -1572495746},
    {"getOwnedBots", -1954035715},
    {"getOwnedStickerSets", 1493074208},
    {"getPaidMessageRevenue", 1976589102},
    {"getPasskeyParameters", -680161058},
    {"getPassportAuthorizationForm", 1636107398},
    {"getPassportAuthorizationFormAvailableElements", 1068700924},
    {"getPassportElement", -1882398342},
    {"getPasswordState", -174752904},
    {"getPaymentForm", -1924172076},
    {"getPaymentReceipt", 1013758294},
    {"getPhoneNumberInfo", -1608344583},
    {"getPhoneNumberInfoSync", 547061048},
    {"getPollOptionProperties", -1191094872},
    {"getPollVoters", -1602915575},
    {"getPreferredCountryLanguage", -933049386},
    {"getPremiumFeatures", -1260640695},
    {"getPremiumGiftPaymentOptions", -480334244},
    {"getPremiumGiveawayPaymentOptions", 1222168073},
    {"getPremiumInfoSticker", 2043562651},
    {"getPremiumLimit", 1075313898},
    {"getPremiumState", 663632610},
    {"getPremiumStickerExamples", 1399442328},
    {"getPremiumStickers", -280950192},
    {"getPreparedInlineMessage", -83179701},
    {"getPreparedKeyboardButton", 1162619742},
    {"getProxies", 1234066431},
    {"getPublicPostSearchLimits", -1724216773},
    {"getPushReceiverId", -286505294},
    {"getReadDatePrivacySettings", 451435451},
    {"getReceivedGift", -446535239},
    {"getReceivedGifts", 1411782110},
    {"getRecentEmojiStatuses", -1371914967},
    {"getRecentInlineBots", 1437823548},
    {"getRecentStickers", -579622241},
    {"getRecentlyOpenedChats", -1924156893},
    {"getRecentlyVisitedTMeUrls", 806754961},
    {"getRecommendedChatFolders", -145540217},
    {"getRecommendedChats", -649884303},
    {"getRecoveryEmailAddress", -1594770947},
    {"getRemoteFile", 2137204530},
    {"getRepliedMessage", -641918531},
    {"getSavedAnimations", 7051032},
    {"getSavedMessagesTags", -1932105815},
    {"getSavedMessagesTopicHistory", 2011552360},
    {"getSavedMessagesTopicMessageByDate", -1050786176},
    {"getSavedNotificationSound", 459569431},
    {"getSavedNotificationSounds", -1070305368},
    {"getSavedOrderInfo", -1152016675},
    {"getScopeNotificationSettings", -995613361},
    {"getSearchSponsoredChats", 1568505164},
    {"getSearchedForTags", -1692716851},
    {"getSecretChat", 40599169},
    {"getStakeDiceState", 1389168065},
    {"getStarAdAccountUrl", 1940473181},
    {"getStarGiftPaymentOptions", -500735773},
    {"getStarGiveawayPaymentOptions", -883172578},
    {"getStarPaymentOptions", 1838351940},
    {"getStarRevenueStatistics", -260356841},
    {"getStarSubscriptions", -641223956},
    {"getStarTransactions", -304141747},
    {"getStarWithdrawalUrl", -1445841134},
    {"getStatisticalGraph", 1100975515},
    {"getStickerEmojis", -1895508665},
    {"getStickerOutline", -1550504539},
    {"getStickerOutlineSvgPath", -1615497803},
    {"getStickerSet", 1052318659},
    {"getStickerSetName", 1039849089},
    {"getStickers", 1158058819},
    {"getStorageStatistics", -853193929},
    {"getStorageStatisticsFast", 61368066},
    {"getStory", -2011076366},
    {"getStoryAlbumStories", 1915090076},
    {"getStoryAvailableReactions", 595938619},
    {"getStoryInteractions", 483475469},
    {"getStoryNotificationSettingsExceptions", 627715760},
    {"getStoryPublicForwards", 1810378546},
    {"getStoryStatistics", 982926146},
    {"getSuggestedFileName", -2049399674},
    {"getSuggestedStickerSetName", -1340995520},
    {"getSuitableDiscussionChats", 49044982},
    {"getSuitablePersonalChats", -1870357515},
    {"getSupergroup", 989663458},
    {"getSupergroupFullInfo", 1099776056},
    {"getSupergroupMembers", -570940984},
    {"getSupportName", 1302205794},
    {"getSupportUser", -1733497700},
    {"getTemporaryPasswordState", -12670830},
    {"getTextEntities", -341490693},
    {"getThemeParametersJsonString", -1850145288},
    {"getThemedChatEmojiStatuses", 1924568314},
    {"getThemedEmojiStatuses", -1468220543},
    {"getTimeZones", 1340268632},
    {"getTonRevenueStatistics", -1315591160},
    {"getTonTransactions", -1935011115},
    {"getTonWithdrawalUrl", -1482519601},
    {"getTopChats", -388410847},
    {"getTrendingStickerSets", -531085986},
    {"getUpgradedGift", -1331821135},
    {"getUpgradedGiftEmojiStatuses", -1748975723},
    {"getUpgradedGiftValueInfo", 1818813417},
    {"getUpgradedGiftVariants", -1388671540},
    {"getUpgradedGiftWithdrawalUrl", -784331188},
    {"getUpgradedGiftsPromotionalAnimation", 1944094513},
    {"getUser", 1117363211},
    {"getUserChatBoosts", -1190205543},
    {"getUserFullInfo", -776823720},
    {"getUserLink", 1226839270},
    {"getUserPrivacySettingRules", -2077223311},
    {"getUserProfileAudios", -208876086},
    {"getUserProfilePhotos", -908132798},
    {"getUserSupportInfo", 1957008133},
    {"getVideoChatAvailableParticipants", -1000496379},
    {"getVideoChatInviteLink", -1394707321},
    {"getVideoChatRtmpUrl", 1210784543},
    {"getVideoMessageAdvertisements", -285681331},
    {"getWebAppLinkUrl", 1627284161},
    {"getWebAppPlaceholder", 583470479},
    {"getWebAppUrl", -1526784188},
    {"getWebPageInstantView", 1741395197},
    {"giftPremiumWithStars", -2058395432},
    {"hideContactCloseBirthdays", -1163065221},
    {"hideSuggestedAction", -1561384065},
    {"importContacts", -662555959},
    {"importMessages", -1864116784},
    {"increaseGiftAuctionBid", -493509001},
    {"inviteGroupCallParticipant", -631535414},
    {"inviteVideoChatParticipants", -473149298},
    {"isLoginEmailAddressRequired", -874594326},
    {"isProfileAudio", -245729314},
    {"joinChat", 326769313},
    {"joinChatByInviteLink", -1049973882},
    {"joinGroupCall", -2026079917},
    {"joinLiveStory", 227825676},
    {"joinVideoChat", 1322989999},
    {"launchPrepaidGiveaway", 639465530},
    {"leaveChat", -1825080735},
    {"leaveGroupCall", 980152233},
    {"listenToAudio", 589191881},
    {"loadActiveStories", 2106390328},
    {"loadChats", -1885635205},
    {"loadDirectMessagesChatTopics", 1488065975},
    {"loadGroupCallParticipants", 938720974},
    {"loadQuickReplyShortcutMessages", -46092588},
    {"loadQuickReplyShortcuts", -1016614243},
    {"loadSavedMessagesTopics", 289855160},
    {"logOut", -1581923301},
    {"markChecklistTasksAsDone", 386950739},
    {"openBotSimilarBot", -369688872},
    {"openChat", -323371509},
    {"openChatSimilarChat", -1884883949},
    {"openGiftAuction", -694137370},
    {"openMessageContent", -739088005},
    {"openSponsoredChat", 865985573},
    {"openStory", -696723005},
    {"openWebApp", -950685122},
    {"optimizeStorage", 853186759},
    {"parseMarkdown", 756366063},
    {"parseTextEntities", -1709194593},
    {"pinChatMessage", 2034719663},
    {"pingProxy", 2144501959},
    {"placeGiftAuctionBid", 1437176980},
    {"postStory", -1725643742},
    {"preliminaryUploadFile", 1894239129},
    {"processChatFolderNewChats", 1498280672},
    {"processChatHasProtectedContentDisableRequest", -2078059411},
    {"processChatJoinRequest", 1004876963},
    {"processChatJoinRequests", 1048722894},
    {"processGiftPurchaseOffer", -1177407462},
    {"processPushNotification", 786679952},
    {"rateSpeechRecognition", -287521867},
    {"readAllChatMentions", 1357558453},
    {"readAllChatPollVotes", -1882393298},
    {"readAllChatReactions", 1421973357},
    {"readAllDirectMessagesChatTopicReactions", 1154665542},
    {"readAllForumTopicMentions", -996864148},
    {"readAllForumTopicPollVotes", 320081488},
    {"readAllForumTopicReactions", -1986498949},
    {"readBusinessMessage", -1723531538},
    {"readChatList", -1117480790},
    {"readFilePart", -174576822},
    {"readdQuickReplyShortcutMessages", 387399566},
    {"recognizeSpeech", 1741947577},
    {"recoverAuthenticationPassword", -131001053},
    {"recoverPassword", -1524262541},
    {"refundStarPayment", -1804165035},
    {"registerDevice", 366088823},
    {"registerUser", -1012247828},
    {"removeAllFilesFromDownloads", -1186433402},
    {"removeBusinessConnectedBotFromChat", 2020766707},
    {"removeChatActionBar", -1650968070},
    {"removeContacts", 1943858054},
    {"removeFavoriteSticker", 1152945264},
    {"removeFileFromDownloads", 1460060142},
    {"removeGiftCollectionGifts", -692316949},
    {"removeInstalledBackground", 1346446652},
    {"removeLoginPasskey", -1728940387},
    {"removeMessageReaction", -1756934789},
    {"removeMessageSenderBotVerification", -1710174374},
    {"removeNotification", 862630734},
    {"removeNotificationGroup", 1713005454},
    {"removePendingLiveStoryReactions", 868601112},
    {"removePendingPaidMessageReactions", 1100258555},
    {"removeProfileAudio", 1292263034},
    {"removeProxy", 1369219847},
    {"removeRecentHashtag", -1013735260},
    {"removeRecentSticker", 1246577677},
    {"removeRecentlyFoundChat", 717340444},
    {"removeSavedAnimation", -495605479},
    {"removeSavedNotificationSound", -480032946},
    {"removeSearchedForTag", 891382730},
    {"removeStickerFromSet", 1642196644},
    {"removeStoryAlbumStories", 1901872465},
    {"removeTopChat", -1907876267},
    {"reorderActiveUsernames", -455399375},
    {"reorderBotActiveUsernames", -1602301664},
    {"reorderBotMediaPreviews", 630851043},
    {"reorderChatFolders", 1665299546},
    {"reorderGiftCollectionGifts", -1545340419},
    {"reorderGiftCollections", -1607216912},
    {"reorderInstalledStickerSets", 1074928158},
    {"reorderQuickReplyShortcuts", -2052799232},
    {"reorderStoryAlbumStories", 438104756},
    {"reorderStoryAlbums", 514423948},
    {"reorderSupergroupActiveUsernames", -1962466095},
    {"replaceLiveStoryRtmpUrl", 585361229},
    {"replacePrimaryChatInviteLink", 1067350941},
    {"replaceStickerInSet", -406311399},
    {"replaceVideoChatRtmpUrl", 558862304},
    {"reportAuthenticationCodeMissing", -1846555064},
    {"reportChat", 1058475058},
    {"reportChatPhoto", -646966648},
    {"reportChatSponsoredMessage", -979984820},
    {"reportMessageReactions", 919111719},
    {"reportPhoneNumberCodeMissing", -895175341},
    {"reportSponsoredChat", -902673019},
    {"reportStory", 1823256372},
    {"reportSupergroupAntiSpamFalsePositive", -516050872},
    {"reportSupergroupSpam", -94825000},
    {"reportVideoMessageAdvertisement", 617137942},
    {"requestAuthenticationPasswordRecovery", 1393896118},
    {"requestPasswordRecovery", -13777582},
    {"requestQrCodeAuthentication", 1363496527},
    {"resendAuthenticationCode", -1506755656},
    {"resendEmailAddressVerificationCode", -1872416732},
    {"resendLoginEmailAddressCode", 292966933},
    {"resendMessages", 526374678},
    {"resendPhoneNumberCode", 1808704551},
    {"resendRecoveryEmailAddressCode", 433483548},
    {"resetAllNotificationSettings", -174020359},
    {"resetAuthenticationEmailAddress", -415075796},
    {"resetInstalledBackgrounds", 1884553559},
    {"resetNetworkStatistics", 1646452102},
    {"resetPassword", -593589091},
    {"reuseStarSubscription", 778531905},
    {"revokeChatInviteLink", -776514135},
    {"revokeGroupCallInviteLink", 501589140},
    {"saveApplicationLogEvent", -811154930},
    {"savePreparedInlineMessage", -954963751},
    {"savePreparedKeyboardButton", -894817192},
    {"searchAffiliatePrograms", 681156625},
    {"searchBackground", -2130996959},
    {"searchCallMessages", -1942229221},
    {"searchChatAffiliateProgram", -1339291206},
    {"searchChatMembers", -445823291},
    {"searchChatMessages", 1072442212},
    {"searchChatRecentLocationMessages", 950238950},
    {"searchChats", -1879787060},
    {"searchChatsOnServer", -1158402188},
    {"searchContacts", -1794690715},
    {"searchEmojis", -1456187668},
    {"searchFileDownloads", 706611286},
    {"searchGiftsForResale", 1947702322},
    {"searchHashtags", 1043637617},
    {"searchInstalledStickerSets", 2120122276},
    {"searchMessages", 1225448885},
    {"searchOutgoingDocumentMessages", -1071397762},
    {"searchPublicChat", 857135533},
    {"searchPublicChats", 970385337},
    {"searchPublicMessagesByTag", 630680746},
    {"searchPublicPosts", 618133347},
    {"searchPublicStoriesByLocation", 1596709256},
    {"searchPublicStoriesByTag", 1778102602},
    {"searchPublicStoriesByVenue", -686136790},
    {"searchQuote", 1751384351},
    {"searchRecentlyFoundChats", 1647445393},
    {"searchSavedMessages", -1969512554},
    {"searchSecretMessages", -852865892},
    {"searchStickerSet", 1676592898},
    {"searchStickerSets", 262801004},
    {"searchStickers", -1856294754},
    {"searchStringsByPrefix", -2023251463},
    {"searchUserByPhoneNumber", -343757368},
    {"searchUserByToken", -666766282},
    {"searchWebApp", -1241740747},
    {"sellGift", -298298375},
    {"sendAuthenticationFirebaseSms", 364994111},
    {"sendBotStartMessage", -1435877650},
    {"sendBusinessMessage", 159888387},
    {"sendBusinessMessageAlbum", 788608366},
    {"sendCallDebugInformation", -1671879106},
    {"sendCallLog", -608809175},
    {"sendCallRating", -158354447},
    {"sendCallSignalingData", 1412280732},
    {"sendChatAction", -1586808788},
    {"sendCustomRequest", 285045153},
    {"sendEmailAddressVerificationCode", -221621379},
    {"sendGift", -1199356118},
    {"sendGiftPurchaseOffer", 917878931},
    {"sendGroupCallMessage", 2133590097},
    {"sendInlineQueryResultMessage", -1445935970},
    {"sendMessage", 964116012},
    {"sendMessageAlbum", -1488607732},
    {"sendMessageViewMetrics", 698012087},
    {"sendPassportAuthorizationForm", 652160701},
    {"sendPaymentForm", -965855094},
    {"sendPhoneNumberCode", 1084112144},
    {"sendPhoneNumberFirebaseSms", 261910660},
    {"sendQuickReplyShortcutMessages", 232068765},
    {"sendResoldGift", -1427446834},
    {"sendTextMessageDraft", 2121571326},
    {"sendWebAppCustomRequest", 922705352},
    {"sendWebAppData", -1423978996},
    {"setAccentColor", 1669974841},
    {"setAccountTtl", 701389032},
    {"setAlarm", -873497067},
    {"setApplicationVerificationToken", 927248261},
    {"setArchiveChatListSettings", -884650998},
    {"setAuthenticationEmailAddress", 1773323522},
    {"setAuthenticationPhoneNumber", 868276259},
    {"setAuthenticationPremiumPurchaseTransaction", -450986887},
    {"setAutoDownloadSettings", -353671948},
    {"setAutosaveSettings", 6846656},
    {"setBio", -1619582124},
    {"setBirthdate", 1319755160},
    {"setBotInfoDescription", 693574984},
    {"setBotInfoShortDescription", 982956771},
    {"setBotName", -761922959},
    {"setBotProfilePhoto", -1115272346},
    {"setBotUpdatesStatus", -1154926191},
    {"setBusinessAccountBio", -1698538041},
    {"setBusinessAccountGiftSettings", 1757763090},
    {"setBusinessAccountName", 999582546},
    {"setBusinessAccountProfilePhoto", 1174440149},
    {"setBusinessAccountUsername", -1520126367},
    {"setBusinessAwayMessageSettings", 1232357484},
    {"setBusinessConnectedBot", -1393459472},
    {"setBusinessGreetingMessageSettings", -873120707},
    {"setBusinessLocation", -344717547},
    {"setBusinessMessageIsPinned", -15403536},
    {"setBusinessOpeningHours", -462379918},
    {"setBusinessStartPage", -1628616290},
    {"setChatAccentColor", 882857930},
    {"setChatActiveStoriesList", -521970415},
    {"setChatAffiliateProgram", 14680631},
    {"setChatAvailableReactions", 267075078},
    {"setChatBackground", 246727678},
    {"setChatClientData", -827119811},
    {"setChatDescription", 1957213277},
    {"setChatDirectMessagesGroup", 1633150115},
    {"setChatDiscussionGroup", -918801736},
    {"setChatDraftMessage", -555614927},
    {"setChatEmojiStatus", 1434982674},
    {"setChatLocation", -767091286},
    {"setChatMemberStatus", 81794847},
    {"setChatMemberTag", 937859366},
    {"setChatMessageAutoDeleteTime", -1505643265},
    {"setChatMessageSender", -1421513858},
    {"setChatNotificationSettings", 777199614},
    {"setChatPaidMessageStarCount", -1187053289},
    {"setChatPermissions", 2138507006},
    {"setChatPhoto", -377778941},
    {"setChatPinnedStories", -669062355},
    {"setChatProfileAccentColor", 1109896826},
    {"setChatSlowModeDelay", -540350914},
    {"setChatTheme", 1474791506},
    {"setChatTitle", 164282047},
    {"setCloseFriends", -1908013258},
    {"setCommands", -907165606},
    {"setCustomEmojiStickerSetThumbnail", -1122836246},
    {"setCustomLanguagePack", -296742819},
    {"setCustomLanguagePackString", 1316365592},
    {"setDatabaseEncryptionKey", -1204599371},
    {"setDefaultBackground", -1982748511},
    {"setDefaultChannelAdministratorRights", -234004967},
    {"setDefaultGroupAdministratorRights", 1700231016},
    {"setDefaultMessageAutoDeleteTime", -1772301460},
    {"setDefaultReactionType", 1694730813},
    {"setDirectMessagesChatTopicIsMarkedAsUnread", 1569655059},
    {"setEmojiStatus", -1829224867},
    {"setFileGenerationProgress", 1836403518},
    {"setForumTopicNotificationSettings", -1989500300},
    {"setGameScore", 2127359430},
    {"setGiftCollectionName", 1108355593},
    {"setGiftResalePrice", 373916170},
    {"setGiftSettings", -519330046},
    {"setGroupCallPaidMessageStarCount", -1764341527},
    {"setGroupCallParticipantIsSpeaking", -1019676164},
    {"setGroupCallParticipantVolumeLevel", -1753769944},
    {"setInactiveSessionTtl", 1570548048},
    {"setInlineGameScore", -948871797},
    {"setLiveStoryMessageSender", -1855297410},
    {"setLogStream", -1364199535},
    {"setLogTagVerbosityLevel", -2095589738},
    {"setLogVerbosityLevel", -303429678},
    {"setLoginEmailAddress", 935019476},
    {"setMainProfileTab", 1663496423},
    {"setMenuButton", -1269841599},
    {"setMessageFactCheck", -4309752},
    {"setMessageReactions", -372524900},
    {"setMessageSenderBlockList", -1987355503},
    {"setMessageSenderBotVerification", -1262364086},
    {"setName", 1711693584},
    {"setNetworkType", -701635234},
    {"setNewChatPrivacySettings", 1774139215},
    {"setOption", 2114670322},
    {"setPaidMessageReactionType", -829934930},
    {"setPassportElement", 2068173212},
    {"setPassportElementErrors", -2056754881},
    {"setPassword", -1193589027},
    {"setPersonalChat", -1068782668},
    {"setPinnedChats", -695640000},
    {"setPinnedForumTopics", -1871668497},
    {"setPinnedGifts", 1613526306},
    {"setPinnedSavedMessagesTopics", -194818924},
    {"setPollAnswer", -1399388792},
    {"setProfileAccentColor", -1986281112},
    {"setProfileAudioPosition", 1209963614},
    {"setProfilePhoto", -2048260627},
    {"setQuickReplyShortcutName", 186709105},
    {"setReactionNotificationSettings", 1186124949},
    {"setReadDatePrivacySettings", 493913782},
    {"setRecoveryEmailAddress", -1981836385},
    {"setSavedMessagesTagLabel", -1338323696},
    {"setScopeNotificationSettings", -2049984966},
    {"setStickerEmojis", -638843855},
    {"setStickerKeywords", 137223565},
    {"setStickerMaskPosition", 1202280912},
    {"setStickerPositionInSet", 2075281185},
    {"setStickerSetThumbnail", 1677617458},
    {"setStickerSetTitle", 1693004706},
    {"setStoryAlbumName", -1143129794},
    {"setStoryPrivacySettings", -655801550},
    {"setStoryReaction", 250731529},
    {"setSupergroupCustomEmojiStickerSet", 1328894639},
    {"setSupergroupMainProfileTab", 1314899548},
    {"setSupergroupStickerSet", -2056344215},
    {"setSupergroupUnrestrictBoostCount", 969814179},
    {"setSupergroupUsername", 1346325252},
    {"setTdlibParameters", -775883218},
    {"setUpgradedGiftColors", -966832402},
    {"setUserEmojiStatus", -451519541},
    {"setUserNote", -351487655},
    {"setUserPersonalProfilePhoto", 464136438},
    {"setUserPrivacySettingRules", -473812741},
    {"setUserSupportInfo", -2088986621},
    {"setUsername", 439901214},
    {"setVideoChatDefaultParticipant", -240749901},
    {"setVideoChatTitle", 1915482994},
    {"shareChatWithBot", -917243698},
    {"sharePhoneNumber", 1097130069},
    {"shareUsersWithBot", 1154320179},
    {"startGroupCallRecording", 1757774971},
    {"startGroupCallScreenSharing", -884068051},
    {"startLiveStory", 1253467958},
    {"startScheduledVideoChat", -1300829822},
    {"stopBusinessPoll", -1142218400},
    {"stopPoll", 1659374253},
    {"suggestUserBirthdate", 39506613},
    {"suggestUserProfilePhoto", -1788742557},
    {"summarizeMessage", -1464885562},
    {"synchronizeLanguagePack", -2065307858},
    {"terminateAllOtherSessions", 1874485523},
    {"terminateSession", -407385812},
    {"testCallBytes", -736011607},
    {"testCallEmpty", -627291626},
    {"testCallString", -1732818385},
    {"testCallVectorInt", -2137277793},
    {"testCallVectorIntObject", 1825428218},
    {"testCallVectorString", -408600900},
    {"testCallVectorStringObject", 1527666429},
    {"testGetDifference", 1747084069},
    {"testNetwork", -1343998901},
    {"testProxy", 2057109116},
    {"testReturnError", 455179506},
    {"testSquareInt", -60135024},
    {"testUseUpdate", 717094686},
    {"toggleAllDownloadsArePaused", 1251512322},
    {"toggleBotCanManageEmojiStatus", 622495770},
    {"toggleBotIsAddedToAttachmentMenu", -1906712934},
    {"toggleBotUsernameIsActive", 2036569097},
    {"toggleBusinessConnectedBotChatIsPaused", 1328957509},
    {"toggleChatDefaultDisableNotification", 314794002},
    {"toggleChatFolderTags", -2092209084},
    {"toggleChatGiftNotifications", -2069429154},
    {"toggleChatHasProtectedContent", 975231309},
    {"toggleChatIsMarkedAsUnread", -986129697},
    {"toggleChatIsPinned", -1485429186},
    {"toggleChatIsTranslatable", -1812345889},
    {"toggleChatViewAsTopics", 724009948},
    {"toggleDirectMessagesChatTopicCanSendUnpaidMessages", -335898703},
    {"toggleDownloadIsPaused", -947493099},
    {"toggleForumTopicIsClosed", 982153376},
    {"toggleForumTopicIsPinned", 1474651795},
    {"toggleGeneralForumTopicIsHidden", 1595741256},
    {"toggleGiftIsSaved", 693198065},
    {"toggleGroupCallAreMessagesAllowed", -1535668758},
    {"toggleGroupCallIsMyVideoEnabled", -1624289030},
    {"toggleGroupCallIsMyVideoPaused", -478875239},
    {"toggleGroupCallParticipantIsHandRaised", -1896127519},
    {"toggleGroupCallParticipantIsMuted", -1308093433},
    {"toggleGroupCallScreenSharingIsPaused", -1602530464},
    {"toggleHasSponsoredMessagesEnabled", 1963285740},
    {"toggleSavedMessagesTopicIsPinned", -1588378164},
    {"toggleSessionCanAcceptCalls", 1819027208},
    {"toggleSessionCanAcceptSecretChats", 1000843390},
    {"toggleStoryIsPostedToChatPage", -2141806228},
    {"toggleSupergroupCanHaveSponsoredMessages", -1098204302},
    {"toggleSupergroupHasAggressiveAntiSpamEnabled", 1748956943},
    {"toggleSupergroupHasAutomaticTranslation", -184993048},
    {"toggleSupergroupHasHiddenMembers", -1537892918},
    {"toggleSupergroupIsAllHistoryAvailable", 1155110478},
    {"toggleSupergroupIsBroadcastGroup", 884089365},
    {"toggleSupergroupIsForum", 371064337},
    {"toggleSupergroupJoinByRequest", 2111807454},
    {"toggleSupergroupJoinToSendMessages", -182022642},
    {"toggleSupergroupSignMessages", 572268491},
    {"toggleSupergroupUsernameIsActive", -1500811777},
    {"toggleUsernameIsActive", 1244098019},
    {"toggleVideoChatEnabledStartNotification", 1851489086},
    {"toggleVideoChatMuteNewParticipants", 987023756},
    {"transferBusinessAccountStars", 732562464},
    {"transferChatOwnership", 2006977043},
    {"transferGift", -1167293126},
    {"translateMessageText", -1995371403},
    {"translateText", -617975379},
    {"unpinAllChatMessages", -1437805385},
    {"unpinAllDirectMessagesChatTopicMessages", 89671100},
    {"unpinAllForumTopicMessages", -1113340771},
    {"unpinChatMessage", 2065448670},
    {"upgradeBasicGroupChatToSupergroupChat", 300488122},
    {"upgradeGift", -1782136103},
    {"uploadStickerFile", 647385283},
    {"validateOrderInfo", -1248305201},
    {"viewMessages", 960236656},
    {"viewPremiumFeature", 192950706},
    {"viewSponsoredChat", 1722644778},
    {"viewTrendingStickerSets", -952416520},
    {"viewVideoMessageAdvertisement", -808563006},
    {"writeGeneratedFilePart", 214474389}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Status from_json(td_api::affiliateProgramParameters &to, JsonObject &from) {
  TRY_STATUS(from_json(to.commission_per_mille_, from.extract_field("commission_per_mille")));
  TRY_STATUS(from_json(to.month_count_, from.extract_field("month_count")));
  return Status::OK();
}

Status from_json(td_api::autosaveSettingsScopePrivateChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::backgroundTypeFill &to, JsonObject &from) {
  TRY_STATUS(from_json(to.fill_, from.extract_field("fill")));
  return Status::OK();
}

Status from_json(td_api::botCommandScopeAllChatAdministrators &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessBotRights &to, JsonObject &from) {
  TRY_STATUS(from_json(to.can_reply_, from.extract_field("can_reply")));
  TRY_STATUS(from_json(to.can_read_messages_, from.extract_field("can_read_messages")));
  TRY_STATUS(from_json(to.can_delete_sent_messages_, from.extract_field("can_delete_sent_messages")));
  TRY_STATUS(from_json(to.can_delete_all_messages_, from.extract_field("can_delete_all_messages")));
  TRY_STATUS(from_json(to.can_edit_name_, from.extract_field("can_edit_name")));
  TRY_STATUS(from_json(to.can_edit_bio_, from.extract_field("can_edit_bio")));
  TRY_STATUS(from_json(to.can_edit_profile_photo_, from.extract_field("can_edit_profile_photo")));
  TRY_STATUS(from_json(to.can_edit_username_, from.extract_field("can_edit_username")));
  TRY_STATUS(from_json(to.can_view_gifts_and_stars_, from.extract_field("can_view_gifts_and_stars")));
  TRY_STATUS(from_json(to.can_sell_gifts_, from.extract_field("can_sell_gifts")));
  TRY_STATUS(from_json(to.can_change_gift_settings_, from.extract_field("can_change_gift_settings")));
  TRY_STATUS(from_json(to.can_transfer_and_upgrade_gifts_, from.extract_field("can_transfer_and_upgrade_gifts")));
  TRY_STATUS(from_json(to.can_transfer_stars_, from.extract_field("can_transfer_stars")));
  TRY_STATUS(from_json(to.can_manage_stories_, from.extract_field("can_manage_stories")));
  return Status::OK();
}

Status from_json(td_api::businessFeatureBots &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::buttonStyleDefault &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::callProblemSilentRemote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatActionRecordingVideo &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatActionStartPlayingGame &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatFolder &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.icon_, from.extract_field("icon")));
  TRY_STATUS(from_json(to.color_id_, from.extract_field("color_id")));
  TRY_STATUS(from_json(to.is_shareable_, from.extract_field("is_shareable")));
  TRY_STATUS(from_json(to.pinned_chat_ids_, from.extract_field("pinned_chat_ids")));
  TRY_STATUS(from_json(to.included_chat_ids_, from.extract_field("included_chat_ids")));
  TRY_STATUS(from_json(to.excluded_chat_ids_, from.extract_field("excluded_chat_ids")));
  TRY_STATUS(from_json(to.exclude_muted_, from.extract_field("exclude_muted")));
  TRY_STATUS(from_json(to.exclude_read_, from.extract_field("exclude_read")));
  TRY_STATUS(from_json(to.exclude_archived_, from.extract_field("exclude_archived")));
  TRY_STATUS(from_json(to.include_contacts_, from.extract_field("include_contacts")));
  TRY_STATUS(from_json(to.include_non_contacts_, from.extract_field("include_non_contacts")));
  TRY_STATUS(from_json(to.include_bots_, from.extract_field("include_bots")));
  TRY_STATUS(from_json(to.include_groups_, from.extract_field("include_groups")));
  TRY_STATUS(from_json(to.include_channels_, from.extract_field("include_channels")));
  return Status::OK();
}

Status from_json(td_api::chatMemberStatusCreator &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_anonymous_, from.extract_field("is_anonymous")));
  TRY_STATUS(from_json(to.is_member_, from.extract_field("is_member")));
  return Status::OK();
}

Status from_json(td_api::chatMembersFilterMention &to, JsonObject &from) {
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  return Status::OK();
}

Status from_json(td_api::collectibleItemTypeUsername &to, JsonObject &from) {
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  return Status::OK();
}

Status from_json(td_api::deviceTokenFirebaseCloudMessaging &to, JsonObject &from) {
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  TRY_STATUS(from_json(to.encrypt_, from.extract_field("encrypt")));
  return Status::OK();
}

Status from_json(td_api::deviceTokenBlackBerryPush &to, JsonObject &from) {
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  return Status::OK();
}

Status from_json(td_api::emojiCategoryTypeEmojiStatus &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeDocument &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeSelfDestructingLivePhotoVideo &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeVideoNote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::giftForResaleOrderPriceChangeDate &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::groupCallVideoQualityThumbnail &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::inlineKeyboardButtonTypeCallbackWithPassword &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.data_, from.extract_field("data")));
  return Status::OK();
}

Status from_json(td_api::inputBackgroundLocal &to, JsonObject &from) {
  TRY_STATUS(from_json(to.background_, from.extract_field("background")));
  return Status::OK();
}

Status from_json(td_api::inputChatPhotoAnimation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.animation_, from.extract_field("animation")));
  TRY_STATUS(from_json(to.main_frame_timestamp_, from.extract_field("main_frame_timestamp")));
  return Status::OK();
}

Status from_json(td_api::inputCredentialsGooglePay &to, JsonObject &from) {
  TRY_STATUS(from_json(to.data_, from.extract_field("data")));
  return Status::OK();
}

Status from_json(td_api::inputInlineQueryResultArticle &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.description_, from.extract_field("description")));
  TRY_STATUS(from_json(to.thumbnail_url_, from.extract_field("thumbnail_url")));
  TRY_STATUS(from_json(to.thumbnail_width_, from.extract_field("thumbnail_width")));
  TRY_STATUS(from_json(to.thumbnail_height_, from.extract_field("thumbnail_height")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::inputInlineQueryResultVideo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.description_, from.extract_field("description")));
  TRY_STATUS(from_json(to.thumbnail_url_, from.extract_field("thumbnail_url")));
  TRY_STATUS(from_json(to.video_url_, from.extract_field("video_url")));
  TRY_STATUS(from_json(to.mime_type_, from.extract_field("mime_type")));
  TRY_STATUS(from_json(to.video_width_, from.extract_field("video_width")));
  TRY_STATUS(from_json(to.video_height_, from.extract_field("video_height")));
  TRY_STATUS(from_json(to.video_duration_, from.extract_field("video_duration")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::inputMessagePaidMedia &to, JsonObject &from) {
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  TRY_STATUS(from_json(to.paid_media_, from.extract_field("paid_media")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  TRY_STATUS(from_json(to.show_caption_above_media_, from.extract_field("show_caption_above_media")));
  TRY_STATUS(from_json(to.payload_, from.extract_field("payload")));
  return Status::OK();
}

Status from_json(td_api::inputMessageDice &to, JsonObject &from) {
  TRY_STATUS(from_json(to.emoji_, from.extract_field("emoji")));
  TRY_STATUS(from_json(to.clear_draft_, from.extract_field("clear_draft")));
  return Status::OK();
}

Status from_json(td_api::inputMessageReplyToExternalMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.quote_, from.extract_field("quote")));
  TRY_STATUS(from_json(to.checklist_task_id_, from.extract_field("checklist_task_id")));
  TRY_STATUS(from_json(to.poll_option_id_, from.extract_field("poll_option_id")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementInternalPassport &to, JsonObject &from) {
  TRY_STATUS(from_json(to.internal_passport_, from.extract_field("internal_passport")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementError &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  TRY_STATUS(from_json(to.message_, from.extract_field("message")));
  TRY_STATUS(from_json(to.source_, from.extract_field("source")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementErrorSourceFiles &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.file_hashes_, from.extract_field("file_hashes")));
  return Status::OK();
}

Status from_json(td_api::inputStoryAreaTypePreviousVenue &to, JsonObject &from) {
  TRY_STATUS(from_json(to.venue_provider_, from.extract_field("venue_provider")));
  TRY_STATUS(from_json(to.venue_id_, from.extract_field("venue_id")));
  return Status::OK();
}

Status from_json(td_api::inputSuggestedPostInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.price_, from.extract_field("price")));
  TRY_STATUS(from_json(to.send_date_, from.extract_field("send_date")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeBusinessChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_name_, from.extract_field("link_name")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeGame &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_username_, from.extract_field("bot_username")));
  TRY_STATUS(from_json(to.game_short_name_, from.extract_field("game_short_name")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypePhoneNumberConfirmation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.hash_, from.extract_field("hash")));
  TRY_STATUS(from_json(to.phone_number_, from.extract_field("phone_number")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeSavedMessages &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeUpgradedGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::jsonValueNumber &to, JsonObject &from) {
  TRY_STATUS(from_json(to.value_, from.extract_field("value")));
  return Status::OK();
}

Status from_json(td_api::keyboardButtonTypeRequestLocation &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::languagePackStringValueOrdinary &to, JsonObject &from) {
  TRY_STATUS(from_json(to.value_, from.extract_field("value")));
  return Status::OK();
}

Status from_json(td_api::maskPointForehead &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageSchedulingStateSendWhenVideoProcessed &to, JsonObject &from) {
  TRY_STATUS(from_json(to.send_date_, from.extract_field("send_date")));
  return Status::OK();
}

Status from_json(td_api::messageSourceDirectMessagesChatTopicHistory &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageTopicForum &to, JsonObject &from) {
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  return Status::OK();
}

Status from_json(td_api::networkTypeOther &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::orderInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.phone_number_, from.extract_field("phone_number")));
  TRY_STATUS(from_json(to.email_address_, from.extract_field("email_address")));
  TRY_STATUS(from_json(to.shipping_address_, from.extract_field("shipping_address")));
  return Status::OK();
}

Status from_json(td_api::passportElementTypeAddress &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::phoneNumberAuthenticationSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.allow_flash_call_, from.extract_field("allow_flash_call")));
  TRY_STATUS(from_json(to.allow_missed_call_, from.extract_field("allow_missed_call")));
  TRY_STATUS(from_json(to.is_current_phone_number_, from.extract_field("is_current_phone_number")));
  TRY_STATUS(from_json(to.has_unknown_phone_number_, from.extract_field("has_unknown_phone_number")));
  TRY_STATUS(from_json(to.allow_sms_retriever_api_, from.extract_field("allow_sms_retriever_api")));
  TRY_STATUS(from_json(to.firebase_authentication_settings_, from.extract_field("firebase_authentication_settings")));
  TRY_STATUS(from_json(to.authentication_tokens_, from.extract_field("authentication_tokens")));
  return Status::OK();
}

Status from_json(td_api::premiumFeatureUniqueReactions &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureRealTimeChatTranslation &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureMessageEffects &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeFavoriteStickerCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeActiveStoryCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumSourceBusinessFeature &to, JsonObject &from) {
  TRY_STATUS(from_json(to.feature_, from.extract_field("feature")));
  return Status::OK();
}

Status from_json(td_api::premiumStoryFeatureLinksAndFormatting &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::profileTabGifs &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::reactionNotificationSourceContacts &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::replyMarkupInlineKeyboard &to, JsonObject &from) {
  TRY_STATUS(from_json(to.rows_, from.extract_field("rows")));
  return Status::OK();
}

Status from_json(td_api::reportReasonPersonalDetails &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterEmpty &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterUrl &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterPinned &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::settingsSectionFeatures &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::settingsSectionPrivacyPolicy &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::stickerTypeRegular &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::storePaymentPurposeGiftedStars &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::storyListMain &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedActionViewChecksHint &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedActionExtendPremium &to, JsonObject &from) {
  TRY_STATUS(from_json(to.manage_premium_subscription_url_, from.extract_field("manage_premium_subscription_url")));
  return Status::OK();
}

Status from_json(td_api::supergroupMembersFilterAdministrators &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::targetChatTypes &to, JsonObject &from) {
  TRY_STATUS(from_json(to.allow_user_chats_, from.extract_field("allow_user_chats")));
  TRY_STATUS(from_json(to.allow_bot_chats_, from.extract_field("allow_bot_chats")));
  TRY_STATUS(from_json(to.allow_group_chats_, from.extract_field("allow_group_chats")));
  TRY_STATUS(from_json(to.allow_channel_chats_, from.extract_field("allow_channel_chats")));
  return Status::OK();
}

Status from_json(td_api::testString &to, JsonObject &from) {
  TRY_STATUS(from_json(to.value_, from.extract_field("value")));
  return Status::OK();
}

Status from_json(td_api::textEntityTypeBankCardNumber &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypeBlockQuote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::themeParameters &to, JsonObject &from) {
  TRY_STATUS(from_json(to.background_color_, from.extract_field("background_color")));
  TRY_STATUS(from_json(to.secondary_background_color_, from.extract_field("secondary_background_color")));
  TRY_STATUS(from_json(to.header_background_color_, from.extract_field("header_background_color")));
  TRY_STATUS(from_json(to.bottom_bar_background_color_, from.extract_field("bottom_bar_background_color")));
  TRY_STATUS(from_json(to.section_background_color_, from.extract_field("section_background_color")));
  TRY_STATUS(from_json(to.section_separator_color_, from.extract_field("section_separator_color")));
  TRY_STATUS(from_json(to.text_color_, from.extract_field("text_color")));
  TRY_STATUS(from_json(to.accent_text_color_, from.extract_field("accent_text_color")));
  TRY_STATUS(from_json(to.section_header_text_color_, from.extract_field("section_header_text_color")));
  TRY_STATUS(from_json(to.subtitle_text_color_, from.extract_field("subtitle_text_color")));
  TRY_STATUS(from_json(to.destructive_text_color_, from.extract_field("destructive_text_color")));
  TRY_STATUS(from_json(to.hint_color_, from.extract_field("hint_color")));
  TRY_STATUS(from_json(to.link_color_, from.extract_field("link_color")));
  TRY_STATUS(from_json(to.button_color_, from.extract_field("button_color")));
  TRY_STATUS(from_json(to.button_text_color_, from.extract_field("button_text_color")));
  return Status::OK();
}

Status from_json(td_api::transactionDirectionIncoming &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingShowPhoneNumber &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingAutosaveGifts &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingRuleRestrictContacts &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::webAppOpenParameters &to, JsonObject &from) {
  TRY_STATUS(from_json(to.theme_, from.extract_field("theme")));
  TRY_STATUS(from_json(to.application_name_, from.extract_field("application_name")));
  TRY_STATUS(from_json(to.mode_, from.extract_field("mode")));
  return Status::OK();
}

Status from_json(td_api::addChatToList &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.chat_list_, from.extract_field("chat_list")));
  return Status::OK();
}

Status from_json(td_api::addLoginPasskey &to, JsonObject &from) {
  TRY_STATUS(from_json(to.client_data_, from.extract_field("client_data")));
  TRY_STATUS(from_json_bytes(to.attestation_object_, from.extract_field("attestation_object")));
  return Status::OK();
}

Status from_json(td_api::addQuickReplyShortcutInlineQueryResultMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shortcut_name_, from.extract_field("shortcut_name")));
  TRY_STATUS(from_json(to.reply_to_message_id_, from.extract_field("reply_to_message_id")));
  TRY_STATUS(from_json(to.query_id_, from.extract_field("query_id")));
  TRY_STATUS(from_json(to.result_id_, from.extract_field("result_id")));
  TRY_STATUS(from_json(to.hide_via_bot_, from.extract_field("hide_via_bot")));
  return Status::OK();
}

Status from_json(td_api::allowBotToSendMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  return Status::OK();
}

Status from_json(td_api::approveSuggestedPost &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.send_date_, from.extract_field("send_date")));
  return Status::OK();
}

Status from_json(td_api::canPurchaseFromStore &to, JsonObject &from) {
  TRY_STATUS(from_json(to.purpose_, from.extract_field("purpose")));
  return Status::OK();
}

Status from_json(td_api::changeStickerSet &to, JsonObject &from) {
  TRY_STATUS(from_json(to.set_id_, from.extract_field("set_id")));
  TRY_STATUS(from_json(to.is_installed_, from.extract_field("is_installed")));
  TRY_STATUS(from_json(to.is_archived_, from.extract_field("is_archived")));
  return Status::OK();
}

Status from_json(td_api::checkChatFolderInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  return Status::OK();
}

Status from_json(td_api::checkPremiumGiftCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.code_, from.extract_field("code")));
  return Status::OK();
}

Status from_json(td_api::clearRecentEmojiStatuses &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::close &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::confirmQrCodeAuthentication &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_, from.extract_field("link")));
  return Status::OK();
}

Status from_json(td_api::createChatFolderInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_id_, from.extract_field("chat_folder_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.chat_ids_, from.extract_field("chat_ids")));
  return Status::OK();
}

Status from_json(td_api::createNewStickerSet &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.sticker_type_, from.extract_field("sticker_type")));
  TRY_STATUS(from_json(to.needs_repainting_, from.extract_field("needs_repainting")));
  TRY_STATUS(from_json(to.stickers_, from.extract_field("stickers")));
  TRY_STATUS(from_json(to.source_, from.extract_field("source")));
  return Status::OK();
}

Status from_json(td_api::declineOauthRequest &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::deleteBusinessMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.message_ids_, from.extract_field("message_ids")));
  return Status::OK();
}

Status from_json(td_api::deleteChatReplyMarkup &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::deleteGroupCallMessagesBySender &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.sender_id_, from.extract_field("sender_id")));
  TRY_STATUS(from_json(to.report_spam_, from.extract_field("report_spam")));
  return Status::OK();
}

Status from_json(td_api::deleteSavedCredentials &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::disableProxy &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::editBusinessMessageCaption &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  TRY_STATUS(from_json(to.show_caption_above_media_, from.extract_field("show_caption_above_media")));
  return Status::OK();
}

Status from_json(td_api::editChatInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.expiration_date_, from.extract_field("expiration_date")));
  TRY_STATUS(from_json(to.member_limit_, from.extract_field("member_limit")));
  TRY_STATUS(from_json(to.creates_join_request_, from.extract_field("creates_join_request")));
  return Status::OK();
}

Status from_json(td_api::editMessageCaption &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  TRY_STATUS(from_json(to.show_caption_above_media_, from.extract_field("show_caption_above_media")));
  return Status::OK();
}

Status from_json(td_api::editStarSubscription &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subscription_id_, from.extract_field("subscription_id")));
  TRY_STATUS(from_json(to.is_canceled_, from.extract_field("is_canceled")));
  return Status::OK();
}

Status from_json(td_api::finishFileGeneration &to, JsonObject &from) {
  TRY_STATUS(from_json(to.generation_id_, from.extract_field("generation_id")));
  TRY_STATUS(from_json(to.error_, from.extract_field("error")));
  return Status::OK();
}

Status from_json(td_api::getApplicationDownloadLink &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getAvailableChatBoostSlots &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getBotMediaPreviewInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  return Status::OK();
}

Status from_json(td_api::getBusinessConnectedBot &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getChatAvailableMessageSenders &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getChatFolder &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_id_, from.extract_field("chat_folder_id")));
  return Status::OK();
}

Status from_json(td_api::getChatInviteLinkMembers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  TRY_STATUS(from_json(to.only_with_expired_subscription_, from.extract_field("only_with_expired_subscription")));
  TRY_STATUS(from_json(to.offset_member_, from.extract_field("offset_member")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getChatNotificationSettingsExceptions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.scope_, from.extract_field("scope")));
  TRY_STATUS(from_json(to.compare_sound_, from.extract_field("compare_sound")));
  return Status::OK();
}

Status from_json(td_api::getChatSimilarChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getCloseFriends &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getCountryFlagEmoji &to, JsonObject &from) {
  TRY_STATUS(from_json(to.country_code_, from.extract_field("country_code")));
  return Status::OK();
}

Status from_json(td_api::getDefaultChatEmojiStatuses &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getDisallowedChatEmojiStatuses &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getFileExtension &to, JsonObject &from) {
  TRY_STATUS(from_json(to.mime_type_, from.extract_field("mime_type")));
  return Status::OK();
}

Status from_json(td_api::getGiftAuctionState &to, JsonObject &from) {
  TRY_STATUS(from_json(to.auction_id_, from.extract_field("auction_id")));
  return Status::OK();
}

Status from_json(td_api::getGroupCallParticipants &to, JsonObject &from) {
  TRY_STATUS(from_json(to.input_group_call_, from.extract_field("input_group_call")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getInstalledStickerSets &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_type_, from.extract_field("sticker_type")));
  return Status::OK();
}

Status from_json(td_api::getLinkPreview &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.link_preview_options_, from.extract_field("link_preview_options")));
  return Status::OK();
}

Status from_json(td_api::getLogVerbosityLevel &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::getMessageLinkInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::getMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_ids_, from.extract_field("message_ids")));
  return Status::OK();
}

Status from_json(td_api::getPassportAuthorizationForm &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.scope_, from.extract_field("scope")));
  TRY_STATUS(from_json(to.public_key_, from.extract_field("public_key")));
  TRY_STATUS(from_json(to.nonce_, from.extract_field("nonce")));
  return Status::OK();
}

Status from_json(td_api::getPollVoters &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.option_id_, from.extract_field("option_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getPremiumStickers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getRecentEmojiStatuses &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getRepliedMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::getSearchSponsoredChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  return Status::OK();
}

Status from_json(td_api::getStarSubscriptions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.only_expiring_, from.extract_field("only_expiring")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  return Status::OK();
}

Status from_json(td_api::getStickers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_type_, from.extract_field("sticker_type")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getStoryStatistics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  TRY_STATUS(from_json(to.is_dark_, from.extract_field("is_dark")));
  return Status::OK();
}

Status from_json(td_api::getSupportUser &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getTonWithdrawalUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::getUser &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::getVideoChatInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.can_self_unmute_, from.extract_field("can_self_unmute")));
  return Status::OK();
}

Status from_json(td_api::hideSuggestedAction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.action_, from.extract_field("action")));
  return Status::OK();
}

Status from_json(td_api::joinChatByInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  return Status::OK();
}

Status from_json(td_api::loadChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_list_, from.extract_field("chat_list")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::openChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::parseTextEntities &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.parse_mode_, from.extract_field("parse_mode")));
  return Status::OK();
}

Status from_json(td_api::processChatJoinRequests &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  TRY_STATUS(from_json(to.approve_, from.extract_field("approve")));
  return Status::OK();
}

Status from_json(td_api::readAllForumTopicPollVotes &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  return Status::OK();
}

Status from_json(td_api::refundStarPayment &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.telegram_payment_charge_id_, from.extract_field("telegram_payment_charge_id")));
  return Status::OK();
}

Status from_json(td_api::removeGiftCollectionGifts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.collection_id_, from.extract_field("collection_id")));
  TRY_STATUS(from_json(to.received_gift_ids_, from.extract_field("received_gift_ids")));
  return Status::OK();
}

Status from_json(td_api::removeProfileAudio &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  return Status::OK();
}

Status from_json(td_api::removeStoryAlbumStories &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.story_album_id_, from.extract_field("story_album_id")));
  TRY_STATUS(from_json(to.story_ids_, from.extract_field("story_ids")));
  return Status::OK();
}

Status from_json(td_api::reorderQuickReplyShortcuts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shortcut_ids_, from.extract_field("shortcut_ids")));
  return Status::OK();
}

Status from_json(td_api::reportChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json_bytes(to.option_id_, from.extract_field("option_id")));
  TRY_STATUS(from_json(to.message_ids_, from.extract_field("message_ids")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::reportVideoMessageAdvertisement &to, JsonObject &from) {
  TRY_STATUS(from_json(to.advertisement_unique_id_, from.extract_field("advertisement_unique_id")));
  TRY_STATUS(from_json_bytes(to.option_id_, from.extract_field("option_id")));
  return Status::OK();
}

Status from_json(td_api::resendRecoveryEmailAddressCode &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::saveApplicationLogEvent &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.data_, from.extract_field("data")));
  return Status::OK();
}

Status from_json(td_api::searchChatRecentLocationMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_list_, from.extract_field("chat_list")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  TRY_STATUS(from_json(to.filter_, from.extract_field("filter")));
  TRY_STATUS(from_json(to.chat_type_filter_, from.extract_field("chat_type_filter")));
  TRY_STATUS(from_json(to.min_date_, from.extract_field("min_date")));
  TRY_STATUS(from_json(to.max_date_, from.extract_field("max_date")));
  return Status::OK();
}

Status from_json(td_api::searchQuote &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.quote_, from.extract_field("quote")));
  TRY_STATUS(from_json(to.quote_position_, from.extract_field("quote_position")));
  return Status::OK();
}

Status from_json(td_api::searchUserByToken &to, JsonObject &from) {
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  return Status::OK();
}

Status from_json(td_api::sendCallRating &to, JsonObject &from) {
  TRY_STATUS(from_json(to.call_id_, from.extract_field("call_id")));
  TRY_STATUS(from_json(to.rating_, from.extract_field("rating")));
  TRY_STATUS(from_json(to.comment_, from.extract_field("comment")));
  TRY_STATUS(from_json(to.problems_, from.extract_field("problems")));
  return Status::OK();
}

Status from_json(td_api::sendMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.reply_to_, from.extract_field("reply_to")));
  TRY_STATUS(from_json(to.options_, from.extract_field("options")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::sendTextMessageDraft &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  TRY_STATUS(from_json(to.draft_id_, from.extract_field("draft_id")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::setAuthenticationPhoneNumber &to, JsonObject &from) {
  TRY_STATUS(from_json(to.phone_number_, from.extract_field("phone_number")));
  TRY_STATUS(from_json(to.settings_, from.extract_field("settings")));
  return Status::OK();
}

Status from_json(td_api::setBotProfilePhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.photo_, from.extract_field("photo")));
  return Status::OK();
}

Status from_json(td_api::setBusinessGreetingMessageSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.greeting_message_settings_, from.extract_field("greeting_message_settings")));
  return Status::OK();
}

Status from_json(td_api::setChatBackground &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.background_, from.extract_field("background")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  TRY_STATUS(from_json(to.dark_theme_dimming_, from.extract_field("dark_theme_dimming")));
  TRY_STATUS(from_json(to.only_for_self_, from.extract_field("only_for_self")));
  return Status::OK();
}

Status from_json(td_api::setChatMemberTag &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.tag_, from.extract_field("tag")));
  return Status::OK();
}

Status from_json(td_api::setChatSlowModeDelay &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.slow_mode_delay_, from.extract_field("slow_mode_delay")));
  return Status::OK();
}

Status from_json(td_api::setDefaultBackground &to, JsonObject &from) {
  TRY_STATUS(from_json(to.background_, from.extract_field("background")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  TRY_STATUS(from_json(to.for_dark_theme_, from.extract_field("for_dark_theme")));
  return Status::OK();
}

Status from_json(td_api::setGameScore &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.edit_message_, from.extract_field("edit_message")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.score_, from.extract_field("score")));
  TRY_STATUS(from_json(to.force_, from.extract_field("force")));
  return Status::OK();
}

Status from_json(td_api::setLiveStoryMessageSender &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.message_sender_id_, from.extract_field("message_sender_id")));
  return Status::OK();
}

Status from_json(td_api::setMessageSenderBlockList &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sender_id_, from.extract_field("sender_id")));
  TRY_STATUS(from_json(to.block_list_, from.extract_field("block_list")));
  return Status::OK();
}

Status from_json(td_api::setPassword &to, JsonObject &from) {
  TRY_STATUS(from_json(to.old_password_, from.extract_field("old_password")));
  TRY_STATUS(from_json(to.new_password_, from.extract_field("new_password")));
  TRY_STATUS(from_json(to.new_hint_, from.extract_field("new_hint")));
  TRY_STATUS(from_json(to.set_recovery_email_address_, from.extract_field("set_recovery_email_address")));
  TRY_STATUS(from_json(to.new_recovery_email_address_, from.extract_field("new_recovery_email_address")));
  return Status::OK();
}

Status from_json(td_api::setProfilePhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.photo_, from.extract_field("photo")));
  TRY_STATUS(from_json(to.is_public_, from.extract_field("is_public")));
  return Status::OK();
}

Status from_json(td_api::setStickerMaskPosition &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  TRY_STATUS(from_json(to.mask_position_, from.extract_field("mask_position")));
  return Status::OK();
}

Status from_json(td_api::setSupergroupStickerSet &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.sticker_set_id_, from.extract_field("sticker_set_id")));
  return Status::OK();
}

Status from_json(td_api::setUserSupportInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.message_, from.extract_field("message")));
  return Status::OK();
}

Status from_json(td_api::startLiveStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.privacy_settings_, from.extract_field("privacy_settings")));
  TRY_STATUS(from_json(to.protect_content_, from.extract_field("protect_content")));
  TRY_STATUS(from_json(to.is_rtmp_stream_, from.extract_field("is_rtmp_stream")));
  TRY_STATUS(from_json(to.enable_messages_, from.extract_field("enable_messages")));
  TRY_STATUS(from_json(to.paid_message_star_count_, from.extract_field("paid_message_star_count")));
  return Status::OK();
}

Status from_json(td_api::terminateSession &to, JsonObject &from) {
  TRY_STATUS(from_json(to.session_id_, from.extract_field("session_id")));
  return Status::OK();
}

Status from_json(td_api::testNetwork &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::toggleBusinessConnectedBotChatIsPaused &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.is_paused_, from.extract_field("is_paused")));
  return Status::OK();
}

Status from_json(td_api::toggleDirectMessagesChatTopicCanSendUnpaidMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.can_send_unpaid_messages_, from.extract_field("can_send_unpaid_messages")));
  TRY_STATUS(from_json(to.refund_payments_, from.extract_field("refund_payments")));
  return Status::OK();
}

Status from_json(td_api::toggleGroupCallParticipantIsHandRaised &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.participant_id_, from.extract_field("participant_id")));
  TRY_STATUS(from_json(to.is_hand_raised_, from.extract_field("is_hand_raised")));
  return Status::OK();
}

Status from_json(td_api::toggleSupergroupHasAggressiveAntiSpamEnabled &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.has_aggressive_anti_spam_enabled_, from.extract_field("has_aggressive_anti_spam_enabled")));
  return Status::OK();
}

Status from_json(td_api::toggleSupergroupUsernameIsActive &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  TRY_STATUS(from_json(to.is_active_, from.extract_field("is_active")));
  return Status::OK();
}

Status from_json(td_api::unpinAllChatMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::viewPremiumFeature &to, JsonObject &from) {
  TRY_STATUS(from_json(to.feature_, from.extract_field("feature")));
  return Status::OK();
}

void to_json(JsonValueScope &jv, const td_api::ActiveStoryState &object) {
  td_api::downcast_call(const_cast<td_api::ActiveStoryState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::activeStoryStateLive &object) {
  auto jo = jv.enter_object();
  jo("@type", "activeStoryStateLive");
  jo("story_id", object.story_id_);
}

void to_json(JsonValueScope &jv, const td_api::activeStoryStateUnread &object) {
  auto jo = jv.enter_object();
  jo("@type", "activeStoryStateUnread");
}

void to_json(JsonValueScope &jv, const td_api::activeStoryStateRead &object) {
  auto jo = jv.enter_object();
  jo("@type", "activeStoryStateRead");
}

void to_json(JsonValueScope &jv, const td_api::affiliateProgramParameters &object) {
  auto jo = jv.enter_object();
  jo("@type", "affiliateProgramParameters");
  jo("commission_per_mille", object.commission_per_mille_);
  jo("month_count", object.month_count_);
}

void to_json(JsonValueScope &jv, const td_api::attachmentMenuBotColor &object) {
  auto jo = jv.enter_object();
  jo("@type", "attachmentMenuBotColor");
  jo("light_color", object.light_color_);
  jo("dark_color", object.dark_color_);
}

void to_json(JsonValueScope &jv, const td_api::AuthorizationState &object) {
  td_api::downcast_call(const_cast<td_api::AuthorizationState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateWaitTdlibParameters &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateWaitTdlibParameters");
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateWaitPhoneNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateWaitPhoneNumber");
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateWaitPremiumPurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateWaitPremiumPurchase");
  jo("store_product_id", object.store_product_id_);
  jo("support_email_address", object.support_email_address_);
  jo("support_email_subject", object.support_email_subject_);
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateWaitEmailAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateWaitEmailAddress");
  jo("allow_apple_id", JsonBool{object.allow_apple_id_});
  jo("allow_google_id", JsonBool{object.allow_google_id_});
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateWaitEmailCode &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateWaitEmailCode");
  jo("allow_apple_id", JsonBool{object.allow_apple_id_});
  jo("allow_google_id", JsonBool{object.allow_google_id_});
  if (object.code_info_) {
    jo("code_info", ToJson(*object.code_info_));
  }
  if (object.email_address_reset_state_) {
    jo("email_address_reset_state", ToJson(*object.email_address_reset_state_));
  }
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateWaitCode &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateWaitCode");
  if (object.code_info_) {
    jo("code_info", ToJson(*object.code_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateWaitOtherDeviceConfirmation &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateWaitOtherDeviceConfirmation");
  jo("link", object.link_);
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateWaitRegistration &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateWaitRegistration");
  if (object.terms_of_service_) {
    jo("terms_of_service", ToJson(*object.terms_of_service_));
  }
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateWaitPassword &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateWaitPassword");
  jo("password_hint", object.password_hint_);
  jo("has_recovery_email_address", JsonBool{object.has_recovery_email_address_});
  jo("has_passport_data", JsonBool{object.has_passport_data_});
  jo("recovery_email_address_pattern", object.recovery_email_address_pattern_);
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateReady &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateReady");
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateLoggingOut &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateLoggingOut");
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateClosing &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateClosing");
}

void to_json(JsonValueScope &jv, const td_api::authorizationStateClosed &object) {
  auto jo = jv.enter_object();
  jo("@type", "authorizationStateClosed");
}

void to_json(JsonValueScope &jv, const td_api::availableReactions &object) {
  auto jo = jv.enter_object();
  jo("@type", "availableReactions");
  jo("top_reactions", ToJson(object.top_reactions_));
  jo("recent_reactions", ToJson(object.recent_reactions_));
  jo("popular_reactions", ToJson(object.popular_reactions_));
  jo("allow_custom_emoji", JsonBool{object.allow_custom_emoji_});
  jo("are_tags", JsonBool{object.are_tags_});
  if (object.unavailability_reason_) {
    jo("unavailability_reason", ToJson(*object.unavailability_reason_));
  }
}

void to_json(JsonValueScope &jv, const td_api::birthdate &object) {
  auto jo = jv.enter_object();
  jo("@type", "birthdate");
  jo("day", object.day_);
  jo("month", object.month_);
  jo("year", object.year_);
}

void to_json(JsonValueScope &jv, const td_api::botVerification &object) {
  auto jo = jv.enter_object();
  jo("@type", "botVerification");
  jo("bot_user_id", object.bot_user_id_);
  jo("icon_custom_emoji_id", ToJson(JsonInt64{object.icon_custom_emoji_id_}));
  if (object.custom_description_) {
    jo("custom_description", ToJson(*object.custom_description_));
  }
}

void to_json(JsonValueScope &jv, const td_api::businessChatLinkInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessChatLinkInfo");
  jo("chat_id", object.chat_id_);
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::businessLocation &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessLocation");
  if (object.location_) {
    jo("location", ToJson(*object.location_));
  }
  jo("address", object.address_);
}

void to_json(JsonValueScope &jv, const td_api::CallDiscardReason &object) {
  td_api::downcast_call(const_cast<td_api::CallDiscardReason &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::callDiscardReasonEmpty &object) {
  auto jo = jv.enter_object();
  jo("@type", "callDiscardReasonEmpty");
}

void to_json(JsonValueScope &jv, const td_api::callDiscardReasonMissed &object) {
  auto jo = jv.enter_object();
  jo("@type", "callDiscardReasonMissed");
}

void to_json(JsonValueScope &jv, const td_api::callDiscardReasonDeclined &object) {
  auto jo = jv.enter_object();
  jo("@type", "callDiscardReasonDeclined");
}

void to_json(JsonValueScope &jv, const td_api::callDiscardReasonDisconnected &object) {
  auto jo = jv.enter_object();
  jo("@type", "callDiscardReasonDisconnected");
}

void to_json(JsonValueScope &jv, const td_api::callDiscardReasonHungUp &object) {
  auto jo = jv.enter_object();
  jo("@type", "callDiscardReasonHungUp");
}

void to_json(JsonValueScope &jv, const td_api::callDiscardReasonUpgradeToGroupCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "callDiscardReasonUpgradeToGroupCall");
  jo("invite_link", object.invite_link_);
}

void to_json(JsonValueScope &jv, const td_api::CanSendGiftResult &object) {
  td_api::downcast_call(const_cast<td_api::CanSendGiftResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::canSendGiftResultOk &object) {
  auto jo = jv.enter_object();
  jo("@type", "canSendGiftResultOk");
}

void to_json(JsonValueScope &jv, const td_api::canSendGiftResultFail &object) {
  auto jo = jv.enter_object();
  jo("@type", "canSendGiftResultFail");
  if (object.reason_) {
    jo("reason", ToJson(*object.reason_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatAdministrators &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatAdministrators");
  jo("administrators", ToJson(object.administrators_));
}

void to_json(JsonValueScope &jv, const td_api::chatBoostSlots &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatBoostSlots");
  jo("slots", ToJson(object.slots_));
}

void to_json(JsonValueScope &jv, const td_api::chatFolderInviteLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatFolderInviteLink");
  jo("invite_link", object.invite_link_);
  jo("name", object.name_);
  jo("chat_ids", ToJson(object.chat_ids_));
}

void to_json(JsonValueScope &jv, const td_api::chatInviteLinkMembers &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatInviteLinkMembers");
  jo("total_count", object.total_count_);
  jo("members", ToJson(object.members_));
}

void to_json(JsonValueScope &jv, const td_api::chatMember &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatMember");
  if (object.member_id_) {
    jo("member_id", ToJson(*object.member_id_));
  }
  jo("tag", object.tag_);
  jo("inviter_user_id", object.inviter_user_id_);
  jo("joined_chat_date", object.joined_chat_date_);
  if (object.status_) {
    jo("status", ToJson(*object.status_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatPhotoSticker &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatPhotoSticker");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  if (object.background_fill_) {
    jo("background_fill", ToJson(*object.background_fill_));
  }
}

void to_json(JsonValueScope &jv, const td_api::ChatSource &object) {
  td_api::downcast_call(const_cast<td_api::ChatSource &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatSourceMtprotoProxy &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatSourceMtprotoProxy");
}

void to_json(JsonValueScope &jv, const td_api::chatSourcePublicServiceAnnouncement &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatSourcePublicServiceAnnouncement");
  jo("type", object.type_);
  jo("text", object.text_);
}

void to_json(JsonValueScope &jv, const td_api::chats &object) {
  auto jo = jv.enter_object();
  jo("@type", "chats");
  jo("total_count", object.total_count_);
  jo("chat_ids", ToJson(object.chat_ids_));
}

void to_json(JsonValueScope &jv, const td_api::connectedAffiliatePrograms &object) {
  auto jo = jv.enter_object();
  jo("@type", "connectedAffiliatePrograms");
  jo("total_count", object.total_count_);
  jo("programs", ToJson(object.programs_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::createdBasicGroupChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "createdBasicGroupChat");
  jo("chat_id", object.chat_id_);
  if (object.failed_to_add_members_) {
    jo("failed_to_add_members", ToJson(*object.failed_to_add_members_));
  }
}

void to_json(JsonValueScope &jv, const td_api::datedFile &object) {
  auto jo = jv.enter_object();
  jo("@type", "datedFile");
  if (object.file_) {
    jo("file", ToJson(*object.file_));
  }
  jo("date", object.date_);
}

void to_json(JsonValueScope &jv, const td_api::draftMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "draftMessage");
  if (object.reply_to_) {
    jo("reply_to", ToJson(*object.reply_to_));
  }
  jo("date", object.date_);
  if (object.input_message_text_) {
    jo("input_message_text", ToJson(*object.input_message_text_));
  }
  jo("effect_id", ToJson(JsonInt64{object.effect_id_}));
  if (object.suggested_post_info_) {
    jo("suggested_post_info", ToJson(*object.suggested_post_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::emojiReaction &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiReaction");
  jo("emoji", object.emoji_);
  jo("title", object.title_);
  jo("is_active", JsonBool{object.is_active_});
  if (object.static_icon_) {
    jo("static_icon", ToJson(*object.static_icon_));
  }
  if (object.appear_animation_) {
    jo("appear_animation", ToJson(*object.appear_animation_));
  }
  if (object.select_animation_) {
    jo("select_animation", ToJson(*object.select_animation_));
  }
  if (object.activate_animation_) {
    jo("activate_animation", ToJson(*object.activate_animation_));
  }
  if (object.effect_animation_) {
    jo("effect_animation", ToJson(*object.effect_animation_));
  }
  if (object.around_animation_) {
    jo("around_animation", ToJson(*object.around_animation_));
  }
  if (object.center_animation_) {
    jo("center_animation", ToJson(*object.center_animation_));
  }
}

void to_json(JsonValueScope &jv, const td_api::factCheck &object) {
  auto jo = jv.enter_object();
  jo("@type", "factCheck");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("country_code", object.country_code_);
}

void to_json(JsonValueScope &jv, const td_api::formattedText &object) {
  auto jo = jv.enter_object();
  jo("@type", "formattedText");
  jo("text", object.text_);
  jo("entities", ToJson(object.entities_));
}

void to_json(JsonValueScope &jv, const td_api::foundChatMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "foundChatMessages");
  jo("total_count", object.total_count_);
  jo("messages", ToJson(object.messages_));
  jo("next_from_message_id", object.next_from_message_id_);
}

void to_json(JsonValueScope &jv, const td_api::game &object) {
  auto jo = jv.enter_object();
  jo("@type", "game");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("short_name", object.short_name_);
  jo("title", object.title_);
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("description", object.description_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
}

void to_json(JsonValueScope &jv, const td_api::giftChatTheme &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftChatTheme");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  if (object.light_settings_) {
    jo("light_settings", ToJson(*object.light_settings_));
  }
  if (object.dark_settings_) {
    jo("dark_settings", ToJson(*object.dark_settings_));
  }
}

void to_json(JsonValueScope &jv, const td_api::GiftResaleResult &object) {
  td_api::downcast_call(const_cast<td_api::GiftResaleResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::giftResaleResultOk &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftResaleResultOk");
  jo("received_gift_id", object.received_gift_id_);
}

void to_json(JsonValueScope &jv, const td_api::giftResaleResultPriceIncreased &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftResaleResultPriceIncreased");
  if (object.price_) {
    jo("price", ToJson(*object.price_));
  }
}

void to_json(JsonValueScope &jv, const td_api::GiveawayParticipantStatus &object) {
  td_api::downcast_call(const_cast<td_api::GiveawayParticipantStatus &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::giveawayParticipantStatusEligible &object) {
  auto jo = jv.enter_object();
  jo("@type", "giveawayParticipantStatusEligible");
}

void to_json(JsonValueScope &jv, const td_api::giveawayParticipantStatusParticipating &object) {
  auto jo = jv.enter_object();
  jo("@type", "giveawayParticipantStatusParticipating");
}

void to_json(JsonValueScope &jv, const td_api::giveawayParticipantStatusAlreadyWasMember &object) {
  auto jo = jv.enter_object();
  jo("@type", "giveawayParticipantStatusAlreadyWasMember");
  jo("joined_chat_date", object.joined_chat_date_);
}

void to_json(JsonValueScope &jv, const td_api::giveawayParticipantStatusAdministrator &object) {
  auto jo = jv.enter_object();
  jo("@type", "giveawayParticipantStatusAdministrator");
  jo("chat_id", object.chat_id_);
}

void to_json(JsonValueScope &jv, const td_api::giveawayParticipantStatusDisallowedCountry &object) {
  auto jo = jv.enter_object();
  jo("@type", "giveawayParticipantStatusDisallowedCountry");
  jo("user_country_code", object.user_country_code_);
}

void to_json(JsonValueScope &jv, const td_api::groupCallParticipants &object) {
  auto jo = jv.enter_object();
  jo("@type", "groupCallParticipants");
  jo("total_count", object.total_count_);
  jo("participant_ids", ToJson(object.participant_ids_));
}

void to_json(JsonValueScope &jv, const td_api::inlineKeyboardButton &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineKeyboardButton");
  jo("text", object.text_);
  jo("icon_custom_emoji_id", ToJson(JsonInt64{object.icon_custom_emoji_id_}));
  if (object.style_) {
    jo("style", ToJson(*object.style_));
  }
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::InputMessageContent &object) {
  td_api::downcast_call(const_cast<td_api::InputMessageContent &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::inputMessageText &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageText");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  if (object.link_preview_options_) {
    jo("link_preview_options", ToJson(*object.link_preview_options_));
  }
  jo("clear_draft", JsonBool{object.clear_draft_});
}

void to_json(JsonValueScope &jv, const td_api::inputMessageAnimation &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageAnimation");
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  jo("added_sticker_file_ids", ToJson(object.added_sticker_file_ids_));
  jo("duration", object.duration_);
  jo("width", object.width_);
  jo("height", object.height_);
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("show_caption_above_media", JsonBool{object.show_caption_above_media_});
  jo("has_spoiler", JsonBool{object.has_spoiler_});
}

void to_json(JsonValueScope &jv, const td_api::inputMessageAudio &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageAudio");
  if (object.audio_) {
    jo("audio", ToJson(*object.audio_));
  }
  if (object.album_cover_thumbnail_) {
    jo("album_cover_thumbnail", ToJson(*object.album_cover_thumbnail_));
  }
  jo("duration", object.duration_);
  jo("title", object.title_);
  jo("performer", object.performer_);
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inputMessageDocument &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageDocument");
  if (object.document_) {
    jo("document", ToJson(*object.document_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  jo("disable_content_type_detection", JsonBool{object.disable_content_type_detection_});
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inputMessagePaidMedia &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessagePaidMedia");
  jo("star_count", object.star_count_);
  jo("paid_media", ToJson(object.paid_media_));
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("show_caption_above_media", JsonBool{object.show_caption_above_media_});
  jo("payload", object.payload_);
}

void to_json(JsonValueScope &jv, const td_api::inputMessagePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessagePhoto");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
  jo("added_sticker_file_ids", ToJson(object.added_sticker_file_ids_));
  jo("width", object.width_);
  jo("height", object.height_);
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("show_caption_above_media", JsonBool{object.show_caption_above_media_});
  if (object.self_destruct_type_) {
    jo("self_destruct_type", ToJson(*object.self_destruct_type_));
  }
  jo("has_spoiler", JsonBool{object.has_spoiler_});
}

void to_json(JsonValueScope &jv, const td_api::inputMessageSticker &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageSticker");
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  jo("width", object.width_);
  jo("height", object.height_);
  jo("emoji", object.emoji_);
}

void to_json(JsonValueScope &jv, const td_api::inputMessageVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageVideo");
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  if (object.cover_) {
    jo("cover", ToJson(*object.cover_));
  }
  jo("start_timestamp", object.start_timestamp_);
  jo("added_sticker_file_ids", ToJson(object.added_sticker_file_ids_));
  jo("duration", object.duration_);
  jo("width", object.width_);
  jo("height", object.height_);
  jo("supports_streaming", JsonBool{object.supports_streaming_});
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("show_caption_above_media", JsonBool{object.show_caption_above_media_});
  if (object.self_destruct_type_) {
    jo("self_destruct_type", ToJson(*object.self_destruct_type_));
  }
  jo("has_spoiler", JsonBool{object.has_spoiler_});
}

void to_json(JsonValueScope &jv, const td_api::inputMessageVideoNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageVideoNote");
  if (object.video_note_) {
    jo("video_note", ToJson(*object.video_note_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  jo("duration", object.duration_);
  jo("length", object.length_);
  if (object.self_destruct_type_) {
    jo("self_destruct_type", ToJson(*object.self_destruct_type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inputMessageVoiceNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageVoiceNote");
  if (object.voice_note_) {
    jo("voice_note", ToJson(*object.voice_note_));
  }
  jo("duration", object.duration_);
  jo("waveform", base64_encode(object.waveform_));
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  if (object.self_destruct_type_) {
    jo("self_destruct_type", ToJson(*object.self_destruct_type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inputMessageLocation &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageLocation");
  if (object.location_) {
    jo("location", ToJson(*object.location_));
  }
  jo("live_period", object.live_period_);
  jo("heading", object.heading_);
  jo("proximity_alert_radius", object.proximity_alert_radius_);
}

void to_json(JsonValueScope &jv, const td_api::inputMessageVenue &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageVenue");
  if (object.venue_) {
    jo("venue", ToJson(*object.venue_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inputMessageContact &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageContact");
  if (object.contact_) {
    jo("contact", ToJson(*object.contact_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inputMessageDice &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageDice");
  jo("emoji", object.emoji_);
  jo("clear_draft", JsonBool{object.clear_draft_});
}

void to_json(JsonValueScope &jv, const td_api::inputMessageGame &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageGame");
  jo("bot_user_id", object.bot_user_id_);
  jo("game_short_name", object.game_short_name_);
}

void to_json(JsonValueScope &jv, const td_api::inputMessageInvoice &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageInvoice");
  if (object.invoice_) {
    jo("invoice", ToJson(*object.invoice_));
  }
  jo("title", object.title_);
  jo("description", object.description_);
  jo("photo_url", object.photo_url_);
  jo("photo_size", object.photo_size_);
  jo("photo_width", object.photo_width_);
  jo("photo_height", object.photo_height_);
  jo("payload", base64_encode(object.payload_));
  jo("provider_token", object.provider_token_);
  jo("provider_data", object.provider_data_);
  jo("start_parameter", object.start_parameter_);
  if (object.paid_media_) {
    jo("paid_media", ToJson(*object.paid_media_));
  }
  if (object.paid_media_caption_) {
    jo("paid_media_caption", ToJson(*object.paid_media_caption_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inputMessagePoll &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessagePoll");
  if (object.question_) {
    jo("question", ToJson(*object.question_));
  }
  jo("options", ToJson(object.options_));
  if (object.description_) {
    jo("description", ToJson(*object.description_));
  }
  jo("is_anonymous", JsonBool{object.is_anonymous_});
  jo("allows_multiple_answers", JsonBool{object.allows_multiple_answers_});
  jo("allows_revoting", JsonBool{object.allows_revoting_});
  jo("shuffle_options", JsonBool{object.shuffle_options_});
  jo("hide_results_until_closes", JsonBool{object.hide_results_until_closes_});
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("open_period", object.open_period_);
  jo("close_date", object.close_date_);
  jo("is_closed", JsonBool{object.is_closed_});
}

void to_json(JsonValueScope &jv, const td_api::inputMessageStakeDice &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageStakeDice");
  jo("state_hash", object.state_hash_);
  jo("stake_toncoin_amount", object.stake_toncoin_amount_);
  jo("clear_draft", JsonBool{object.clear_draft_});
}

void to_json(JsonValueScope &jv, const td_api::inputMessageStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageStory");
  jo("story_poster_chat_id", object.story_poster_chat_id_);
  jo("story_id", object.story_id_);
}

void to_json(JsonValueScope &jv, const td_api::inputMessageChecklist &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageChecklist");
  if (object.checklist_) {
    jo("checklist", ToJson(*object.checklist_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inputMessageForwarded &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageForwarded");
  jo("from_chat_id", object.from_chat_id_);
  jo("message_id", object.message_id_);
  jo("in_game_share", JsonBool{object.in_game_share_});
  jo("replace_video_start_timestamp", JsonBool{object.replace_video_start_timestamp_});
  jo("new_video_start_timestamp", object.new_video_start_timestamp_);
  if (object.copy_options_) {
    jo("copy_options", ToJson(*object.copy_options_));
  }
}

void to_json(JsonValueScope &jv, const td_api::InternalLinkType &object) {
  td_api::downcast_call(const_cast<td_api::InternalLinkType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeAttachmentMenuBot &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeAttachmentMenuBot");
  if (object.target_chat_) {
    jo("target_chat", ToJson(*object.target_chat_));
  }
  jo("bot_username", object.bot_username_);
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeAuthenticationCode &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeAuthenticationCode");
  jo("code", object.code_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeBackground &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeBackground");
  jo("background_name", object.background_name_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeBotAddToChannel &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeBotAddToChannel");
  jo("bot_username", object.bot_username_);
  if (object.administrator_rights_) {
    jo("administrator_rights", ToJson(*object.administrator_rights_));
  }
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeBotStart &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeBotStart");
  jo("bot_username", object.bot_username_);
  jo("start_parameter", object.start_parameter_);
  jo("autostart", JsonBool{object.autostart_});
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeBotStartInGroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeBotStartInGroup");
  jo("bot_username", object.bot_username_);
  jo("start_parameter", object.start_parameter_);
  if (object.administrator_rights_) {
    jo("administrator_rights", ToJson(*object.administrator_rights_));
  }
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeBusinessChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeBusinessChat");
  jo("link_name", object.link_name_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeCallsPage &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeCallsPage");
  jo("section", object.section_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeChatAffiliateProgram &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeChatAffiliateProgram");
  jo("username", object.username_);
  jo("referrer", object.referrer_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeChatBoost &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeChatBoost");
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeChatFolderInvite &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeChatFolderInvite");
  jo("invite_link", object.invite_link_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeChatInvite &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeChatInvite");
  jo("invite_link", object.invite_link_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeChatSelection &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeChatSelection");
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeContactsPage &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeContactsPage");
  jo("section", object.section_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeDirectMessagesChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeDirectMessagesChat");
  jo("channel_username", object.channel_username_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeGame &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeGame");
  jo("bot_username", object.bot_username_);
  jo("game_short_name", object.game_short_name_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeGiftAuction &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeGiftAuction");
  jo("auction_id", object.auction_id_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeGiftCollection &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeGiftCollection");
  jo("gift_owner_username", object.gift_owner_username_);
  jo("collection_id", object.collection_id_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeGroupCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeGroupCall");
  jo("invite_link", object.invite_link_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeInstantView &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeInstantView");
  jo("url", object.url_);
  jo("fallback_url", object.fallback_url_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeInvoice &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeInvoice");
  jo("invoice_name", object.invoice_name_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeLanguagePack &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeLanguagePack");
  jo("language_pack_id", object.language_pack_id_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeLiveStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeLiveStory");
  jo("story_poster_username", object.story_poster_username_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeMainWebApp &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeMainWebApp");
  jo("bot_username", object.bot_username_);
  jo("start_parameter", object.start_parameter_);
  if (object.mode_) {
    jo("mode", ToJson(*object.mode_));
  }
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeMessage");
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeMessageDraft &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeMessageDraft");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("contains_link", JsonBool{object.contains_link_});
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeMyProfilePage &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeMyProfilePage");
  jo("section", object.section_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeNewChannelChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeNewChannelChat");
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeNewGroupChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeNewGroupChat");
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeNewPrivateChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeNewPrivateChat");
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeNewStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeNewStory");
  if (object.content_type_) {
    jo("content_type", ToJson(*object.content_type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeOauth &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeOauth");
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypePassportDataRequest &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypePassportDataRequest");
  jo("bot_user_id", object.bot_user_id_);
  jo("scope", object.scope_);
  jo("public_key", object.public_key_);
  jo("nonce", object.nonce_);
  jo("callback_url", object.callback_url_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypePhoneNumberConfirmation &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypePhoneNumberConfirmation");
  jo("hash", object.hash_);
  jo("phone_number", object.phone_number_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypePremiumFeaturesPage &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypePremiumFeaturesPage");
  jo("referrer", object.referrer_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypePremiumGiftCode &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypePremiumGiftCode");
  jo("code", object.code_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypePremiumGiftPurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypePremiumGiftPurchase");
  jo("referrer", object.referrer_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeProxy &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeProxy");
  if (object.proxy_) {
    jo("proxy", ToJson(*object.proxy_));
  }
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypePublicChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypePublicChat");
  jo("chat_username", object.chat_username_);
  jo("draft_text", object.draft_text_);
  jo("open_profile", JsonBool{object.open_profile_});
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeQrCodeAuthentication &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeQrCodeAuthentication");
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeRequestManagedBot &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeRequestManagedBot");
  jo("manager_bot_username", object.manager_bot_username_);
  jo("suggested_bot_username", object.suggested_bot_username_);
  jo("suggested_bot_name", object.suggested_bot_name_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeRestorePurchases &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeRestorePurchases");
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeSavedMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeSavedMessages");
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeSearch &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeSearch");
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeSettings");
  if (object.section_) {
    jo("section", ToJson(*object.section_));
  }
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeStarPurchase &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeStarPurchase");
  jo("star_count", object.star_count_);
  jo("purpose", object.purpose_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeStickerSet &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeStickerSet");
  jo("sticker_set_name", object.sticker_set_name_);
  jo("expect_custom_emoji", JsonBool{object.expect_custom_emoji_});
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeStory");
  jo("story_poster_username", object.story_poster_username_);
  jo("story_id", object.story_id_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeStoryAlbum &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeStoryAlbum");
  jo("story_album_owner_username", object.story_album_owner_username_);
  jo("story_album_id", object.story_album_id_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeTheme &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeTheme");
  jo("theme_name", object.theme_name_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeUnknownDeepLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeUnknownDeepLink");
  jo("link", object.link_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeUpgradedGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeUpgradedGift");
  jo("name", object.name_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeUserPhoneNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeUserPhoneNumber");
  jo("phone_number", object.phone_number_);
  jo("draft_text", object.draft_text_);
  jo("open_profile", JsonBool{object.open_profile_});
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeUserToken &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeUserToken");
  jo("token", object.token_);
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeVideoChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeVideoChat");
  jo("chat_username", object.chat_username_);
  jo("invite_hash", object.invite_hash_);
  jo("is_live_stream", JsonBool{object.is_live_stream_});
}

void to_json(JsonValueScope &jv, const td_api::internalLinkTypeWebApp &object) {
  auto jo = jv.enter_object();
  jo("@type", "internalLinkTypeWebApp");
  jo("bot_username", object.bot_username_);
  jo("web_app_short_name", object.web_app_short_name_);
  jo("start_parameter", object.start_parameter_);
  if (object.mode_) {
    jo("mode", ToJson(*object.mode_));
  }
}

void to_json(JsonValueScope &jv, const td_api::languagePackInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "languagePackInfo");
  jo("id", object.id_);
  jo("base_language_pack_id", object.base_language_pack_id_);
  jo("name", object.name_);
  jo("native_name", object.native_name_);
  jo("plural_code", object.plural_code_);
  jo("is_official", JsonBool{object.is_official_});
  jo("is_rtl", JsonBool{object.is_rtl_});
  jo("is_beta", JsonBool{object.is_beta_});
  jo("is_installed", JsonBool{object.is_installed_});
  jo("total_string_count", object.total_string_count_);
  jo("translated_string_count", object.translated_string_count_);
  jo("local_string_count", object.local_string_count_);
  jo("translation_url", object.translation_url_);
}

void to_json(JsonValueScope &jv, const td_api::localFile &object) {
  auto jo = jv.enter_object();
  jo("@type", "localFile");
  jo("path", object.path_);
  jo("can_be_downloaded", JsonBool{object.can_be_downloaded_});
  jo("can_be_deleted", JsonBool{object.can_be_deleted_});
  jo("is_downloading_active", JsonBool{object.is_downloading_active_});
  jo("is_downloading_completed", JsonBool{object.is_downloading_completed_});
  jo("download_offset", object.download_offset_);
  jo("downloaded_prefix_size", object.downloaded_prefix_size_);
  jo("downloaded_size", object.downloaded_size_);
}

void to_json(JsonValueScope &jv, const td_api::MaskPoint &object) {
  td_api::downcast_call(const_cast<td_api::MaskPoint &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::maskPointForehead &object) {
  auto jo = jv.enter_object();
  jo("@type", "maskPointForehead");
}

void to_json(JsonValueScope &jv, const td_api::maskPointEyes &object) {
  auto jo = jv.enter_object();
  jo("@type", "maskPointEyes");
}

void to_json(JsonValueScope &jv, const td_api::maskPointMouth &object) {
  auto jo = jv.enter_object();
  jo("@type", "maskPointMouth");
}

void to_json(JsonValueScope &jv, const td_api::maskPointChin &object) {
  auto jo = jv.enter_object();
  jo("@type", "maskPointChin");
}

void to_json(JsonValueScope &jv, const td_api::MessageEffectType &object) {
  td_api::downcast_call(const_cast<td_api::MessageEffectType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::messageEffectTypeEmojiReaction &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageEffectTypeEmojiReaction");
  if (object.select_animation_) {
    jo("select_animation", ToJson(*object.select_animation_));
  }
  if (object.effect_animation_) {
    jo("effect_animation", ToJson(*object.effect_animation_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageEffectTypePremiumSticker &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageEffectTypePremiumSticker");
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messagePositions &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePositions");
  jo("total_count", object.total_count_);
  jo("positions", ToJson(object.positions_));
}

void to_json(JsonValueScope &jv, const td_api::MessageSender &object) {
  td_api::downcast_call(const_cast<td_api::MessageSender &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::messageSenderUser &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSenderUser");
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageSenderChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSenderChat");
  jo("chat_id", object.chat_id_);
}

void to_json(JsonValueScope &jv, const td_api::minithumbnail &object) {
  auto jo = jv.enter_object();
  jo("@type", "minithumbnail");
  jo("width", object.width_);
  jo("height", object.height_);
  jo("data", base64_encode(object.data_));
}

void to_json(JsonValueScope &jv, const td_api::notificationSound &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationSound");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("duration", object.duration_);
  jo("date", object.date_);
  jo("title", object.title_);
  jo("data", object.data_);
  if (object.sound_) {
    jo("sound", ToJson(*object.sound_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockCaption &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockCaption");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  if (object.credit_) {
    jo("credit", ToJson(*object.credit_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passkey &object) {
  auto jo = jv.enter_object();
  jo("@type", "passkey");
  jo("id", object.id_);
  jo("name", object.name_);
  jo("addition_date", object.addition_date_);
  jo("last_usage_date", object.last_usage_date_);
  jo("software_icon_custom_emoji_id", ToJson(JsonInt64{object.software_icon_custom_emoji_id_}));
}

void to_json(JsonValueScope &jv, const td_api::passportRequiredElement &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportRequiredElement");
  jo("suitable_elements", ToJson(object.suitable_elements_));
}

void to_json(JsonValueScope &jv, const td_api::paymentResult &object) {
  auto jo = jv.enter_object();
  jo("@type", "paymentResult");
  jo("success", JsonBool{object.success_});
  jo("verification_url", object.verification_url_);
}

void to_json(JsonValueScope &jv, const td_api::pollOptionProperties &object) {
  auto jo = jv.enter_object();
  jo("@type", "pollOptionProperties");
  jo("can_be_deleted", JsonBool{object.can_be_deleted_});
  jo("can_be_replied", JsonBool{object.can_be_replied_});
  jo("can_be_replied_in_another_chat", JsonBool{object.can_be_replied_in_another_chat_});
  jo("can_get_link", JsonBool{object.can_get_link_});
}

void to_json(JsonValueScope &jv, const td_api::premiumGiftPaymentOptions &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumGiftPaymentOptions");
  jo("options", ToJson(object.options_));
}

void to_json(JsonValueScope &jv, const td_api::preparedInlineMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "preparedInlineMessage");
  jo("inline_query_id", ToJson(JsonInt64{object.inline_query_id_}));
  if (object.result_) {
    jo("result", ToJson(*object.result_));
  }
  if (object.chat_types_) {
    jo("chat_types", ToJson(*object.chat_types_));
  }
}

void to_json(JsonValueScope &jv, const td_api::PublicForward &object) {
  td_api::downcast_call(const_cast<td_api::PublicForward &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::publicForwardMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "publicForwardMessage");
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::publicForwardStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "publicForwardStory");
  if (object.story_) {
    jo("story", ToJson(*object.story_));
  }
}

void to_json(JsonValueScope &jv, const td_api::ReactionNotificationSource &object) {
  td_api::downcast_call(const_cast<td_api::ReactionNotificationSource &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::reactionNotificationSourceNone &object) {
  auto jo = jv.enter_object();
  jo("@type", "reactionNotificationSourceNone");
}

void to_json(JsonValueScope &jv, const td_api::reactionNotificationSourceContacts &object) {
  auto jo = jv.enter_object();
  jo("@type", "reactionNotificationSourceContacts");
}

void to_json(JsonValueScope &jv, const td_api::reactionNotificationSourceAll &object) {
  auto jo = jv.enter_object();
  jo("@type", "reactionNotificationSourceAll");
}

void to_json(JsonValueScope &jv, const td_api::remoteFile &object) {
  auto jo = jv.enter_object();
  jo("@type", "remoteFile");
  jo("id", object.id_);
  jo("unique_id", object.unique_id_);
  jo("is_uploading_active", JsonBool{object.is_uploading_active_});
  jo("is_uploading_completed", JsonBool{object.is_uploading_completed_});
  jo("uploaded_size", object.uploaded_size_);
}

void to_json(JsonValueScope &jv, const td_api::RichText &object) {
  td_api::downcast_call(const_cast<td_api::RichText &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::richTextPlain &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextPlain");
  jo("text", object.text_);
}

void to_json(JsonValueScope &jv, const td_api::richTextBold &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextBold");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::richTextItalic &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextItalic");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::richTextUnderline &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextUnderline");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::richTextStrikethrough &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextStrikethrough");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::richTextFixed &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextFixed");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::richTextUrl &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextUrl");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("url", object.url_);
  jo("is_cached", JsonBool{object.is_cached_});
}

void to_json(JsonValueScope &jv, const td_api::richTextEmailAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextEmailAddress");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("email_address", object.email_address_);
}

void to_json(JsonValueScope &jv, const td_api::richTextSubscript &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextSubscript");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::richTextSuperscript &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextSuperscript");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::richTextMarked &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextMarked");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::richTextPhoneNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextPhoneNumber");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("phone_number", object.phone_number_);
}

void to_json(JsonValueScope &jv, const td_api::richTextIcon &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextIcon");
  if (object.document_) {
    jo("document", ToJson(*object.document_));
  }
  jo("width", object.width_);
  jo("height", object.height_);
}

void to_json(JsonValueScope &jv, const td_api::richTextReference &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextReference");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("anchor_name", object.anchor_name_);
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::richTextAnchor &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextAnchor");
  jo("name", object.name_);
}

void to_json(JsonValueScope &jv, const td_api::richTextAnchorLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTextAnchorLink");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("anchor_name", object.anchor_name_);
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::richTexts &object) {
  auto jo = jv.enter_object();
  jo("@type", "richTexts");
  jo("texts", ToJson(object.texts_));
}

void to_json(JsonValueScope &jv, const td_api::seconds &object) {
  auto jo = jv.enter_object();
  jo("@type", "seconds");
  jo("seconds", object.seconds_);
}

void to_json(JsonValueScope &jv, const td_api::sharedChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "sharedChat");
  jo("chat_id", object.chat_id_);
  jo("title", object.title_);
  jo("username", object.username_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starAmount &object) {
  auto jo = jv.enter_object();
  jo("@type", "starAmount");
  jo("star_count", object.star_count_);
  jo("nanostar_count", object.nanostar_count_);
}

void to_json(JsonValueScope &jv, const td_api::starSubscription &object) {
  auto jo = jv.enter_object();
  jo("@type", "starSubscription");
  jo("id", object.id_);
  jo("chat_id", object.chat_id_);
  jo("expiration_date", object.expiration_date_);
  jo("is_canceled", JsonBool{object.is_canceled_});
  jo("is_expiring", JsonBool{object.is_expiring_});
  if (object.pricing_) {
    jo("pricing", ToJson(*object.pricing_));
  }
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::statisticalValue &object) {
  auto jo = jv.enter_object();
  jo("@type", "statisticalValue");
  jo("value", object.value_);
  jo("previous_value", object.previous_value_);
  jo("growth_rate_percentage", object.growth_rate_percentage_);
}

void to_json(JsonValueScope &jv, const td_api::storageStatistics &object) {
  auto jo = jv.enter_object();
  jo("@type", "storageStatistics");
  jo("size", object.size_);
  jo("count", object.count_);
  jo("by_chat", ToJson(object.by_chat_));
}

void to_json(JsonValueScope &jv, const td_api::storyAreaPosition &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyAreaPosition");
  jo("x_percentage", object.x_percentage_);
  jo("y_percentage", object.y_percentage_);
  jo("width_percentage", object.width_percentage_);
  jo("height_percentage", object.height_percentage_);
  jo("rotation_angle", object.rotation_angle_);
  jo("corner_radius_percentage", object.corner_radius_percentage_);
}

void to_json(JsonValueScope &jv, const td_api::StoryList &object) {
  td_api::downcast_call(const_cast<td_api::StoryList &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::storyListMain &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyListMain");
}

void to_json(JsonValueScope &jv, const td_api::storyListArchive &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyListArchive");
}

void to_json(JsonValueScope &jv, const td_api::SuggestedPostRefundReason &object) {
  td_api::downcast_call(const_cast<td_api::SuggestedPostRefundReason &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::suggestedPostRefundReasonPostDeleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedPostRefundReasonPostDeleted");
}

void to_json(JsonValueScope &jv, const td_api::suggestedPostRefundReasonPaymentRefunded &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedPostRefundReasonPaymentRefunded");
}

void to_json(JsonValueScope &jv, const td_api::temporaryPasswordState &object) {
  auto jo = jv.enter_object();
  jo("@type", "temporaryPasswordState");
  jo("has_password", JsonBool{object.has_password_});
  jo("valid_for", object.valid_for_);
}

void to_json(JsonValueScope &jv, const td_api::text &object) {
  auto jo = jv.enter_object();
  jo("@type", "text");
  jo("text", object.text_);
}

void to_json(JsonValueScope &jv, const td_api::timeZone &object) {
  auto jo = jv.enter_object();
  jo("@type", "timeZone");
  jo("id", object.id_);
  jo("name", object.name_);
  jo("utc_time_offset", object.utc_time_offset_);
}

void to_json(JsonValueScope &jv, const td_api::unreadReaction &object) {
  auto jo = jv.enter_object();
  jo("@type", "unreadReaction");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  jo("is_big", JsonBool{object.is_big_});
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftColors &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftColors");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("model_custom_emoji_id", ToJson(JsonInt64{object.model_custom_emoji_id_}));
  jo("symbol_custom_emoji_id", ToJson(JsonInt64{object.symbol_custom_emoji_id_}));
  jo("light_theme_accent_color", object.light_theme_accent_color_);
  jo("light_theme_colors", ToJson(object.light_theme_colors_));
  jo("dark_theme_accent_color", object.dark_theme_accent_color_);
  jo("dark_theme_colors", ToJson(object.dark_theme_colors_));
}

void to_json(JsonValueScope &jv, const td_api::userAuctionBid &object) {
  auto jo = jv.enter_object();
  jo("@type", "userAuctionBid");
  jo("star_count", object.star_count_);
  jo("bid_date", object.bid_date_);
  jo("next_bid_star_count", object.next_bid_star_count_);
  if (object.owner_id_) {
    jo("owner_id", ToJson(*object.owner_id_));
  }
  jo("was_returned", JsonBool{object.was_returned_});
}

void to_json(JsonValueScope &jv, const td_api::UserType &object) {
  td_api::downcast_call(const_cast<td_api::UserType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::userTypeRegular &object) {
  auto jo = jv.enter_object();
  jo("@type", "userTypeRegular");
}

void to_json(JsonValueScope &jv, const td_api::userTypeDeleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "userTypeDeleted");
}

void to_json(JsonValueScope &jv, const td_api::userTypeBot &object) {
  auto jo = jv.enter_object();
  jo("@type", "userTypeBot");
  jo("can_be_edited", JsonBool{object.can_be_edited_});
  jo("can_join_groups", JsonBool{object.can_join_groups_});
  jo("can_read_all_group_messages", JsonBool{object.can_read_all_group_messages_});
  jo("has_main_web_app", JsonBool{object.has_main_web_app_});
  jo("has_topics", JsonBool{object.has_topics_});
  jo("allows_users_to_create_topics", JsonBool{object.allows_users_to_create_topics_});
  jo("can_manage_bots", JsonBool{object.can_manage_bots_});
  jo("is_inline", JsonBool{object.is_inline_});
  jo("inline_query_placeholder", object.inline_query_placeholder_);
  jo("need_location", JsonBool{object.need_location_});
  jo("can_connect_to_business", JsonBool{object.can_connect_to_business_});
  jo("can_be_added_to_attachment_menu", JsonBool{object.can_be_added_to_attachment_menu_});
  jo("active_user_count", object.active_user_count_);
}

void to_json(JsonValueScope &jv, const td_api::userTypeUnknown &object) {
  auto jo = jv.enter_object();
  jo("@type", "userTypeUnknown");
}

void to_json(JsonValueScope &jv, const td_api::videoMessageAdvertisement &object) {
  auto jo = jv.enter_object();
  jo("@type", "videoMessageAdvertisement");
  jo("unique_id", object.unique_id_);
  jo("text", object.text_);
  jo("min_display_duration", object.min_display_duration_);
  jo("max_display_duration", object.max_display_duration_);
  jo("can_be_reported", JsonBool{object.can_be_reported_});
  if (object.sponsor_) {
    jo("sponsor", ToJson(*object.sponsor_));
  }
  jo("title", object.title_);
  jo("additional_info", object.additional_info_);
}

}  // namespace td_api
}  // namespace td
