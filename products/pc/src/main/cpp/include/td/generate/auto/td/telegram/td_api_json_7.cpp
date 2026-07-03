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
Result<int32> tl_constructor_from_string(td_api::BlockList *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"blockListMain", 1352930172},
    {"blockListStories", 103323228}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ChatList *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"chatListMain", -400991316},
    {"chatListArchive", 362770115},
    {"chatListFolder", 385760856}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::EmojiCategoryType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"emojiCategoryTypeDefault", 1188782699},
    {"emojiCategoryTypeRegularStickers", -1337484846},
    {"emojiCategoryTypeEmojiStatus", 1381282631},
    {"emojiCategoryTypeChatPhoto", 1059063081}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InlineQueryResultsButtonType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inlineQueryResultsButtonTypeStartBot", -23400235},
    {"inlineQueryResultsButtonTypeWebApp", -1197382814}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputInvoice *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputInvoiceMessage", 1490872848},
    {"inputInvoiceName", -1312155917},
    {"inputInvoiceTelegram", -1762853139}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InternalLinkType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"internalLinkTypeWebApp", 2062112045}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::MessageSender *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"messageSenderUser", -336109341},
    {"messageSenderChat", -239660751}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::PhoneNumberCodeType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"phoneNumberCodeTypeChange", 87144986},
    {"phoneNumberCodeTypeVerify", -1029402661},
    {"phoneNumberCodeTypeConfirmOwnership", -485404696}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ReactionType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"reactionTypeEmoji", -1942084920},
    {"reactionTypeCustomEmoji", -989117709},
    {"reactionTypePaid", 436294381}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::StorePaymentPurpose *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"storePaymentPurposePremiumSubscription", 1263894804},
    {"storePaymentPurposePremiumGift", -39502443},
    {"storePaymentPurposePremiumGiftCodes", -1072286736},
    {"storePaymentPurposePremiumGiveaway", 1302624938},
    {"storePaymentPurposeStarGiveaway", 211212441},
    {"storePaymentPurposeStars", 410189263},
    {"storePaymentPurposeGiftedStars", 893691428}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::TelegramPaymentPurpose *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"telegramPaymentPurposePremiumGift", -1600286150},
    {"telegramPaymentPurposePremiumGiftCodes", -1863495348},
    {"telegramPaymentPurposePremiumGiveaway", -760757441},
    {"telegramPaymentPurposeStars", 1204968037},
    {"telegramPaymentPurposeGiftedStars", -1850308042},
    {"telegramPaymentPurposeStarGiveaway", 1014604689},
    {"telegramPaymentPurposeJoinChat", -1914869880}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Status from_json(td_api::acceptedGiftTypes &to, JsonObject &from) {
  TRY_STATUS(from_json(to.unlimited_gifts_, from.extract_field("unlimited_gifts")));
  TRY_STATUS(from_json(to.limited_gifts_, from.extract_field("limited_gifts")));
  TRY_STATUS(from_json(to.upgraded_gifts_, from.extract_field("upgraded_gifts")));
  TRY_STATUS(from_json(to.gifts_from_channels_, from.extract_field("gifts_from_channels")));
  TRY_STATUS(from_json(to.premium_subscription_, from.extract_field("premium_subscription")));
  return Status::OK();
}

Status from_json(td_api::affiliateTypeChannel &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::backgroundFillFreeformGradient &to, JsonObject &from) {
  TRY_STATUS(from_json(to.colors_, from.extract_field("colors")));
  return Status::OK();
}

Status from_json(td_api::botCommandScopeDefault &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessAwayMessageScheduleOutsideOfOpeningHours &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessFeatureAwayMessage &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessOpeningHours &to, JsonObject &from) {
  TRY_STATUS(from_json(to.time_zone_id_, from.extract_field("time_zone_id")));
  TRY_STATUS(from_json(to.opening_hours_, from.extract_field("opening_hours")));
  return Status::OK();
}

Status from_json(td_api::callProblemInterruptions &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::callbackQueryPayloadDataWithPassword &to, JsonObject &from) {
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  TRY_STATUS(from_json_bytes(to.data_, from.extract_field("data")));
  return Status::OK();
}

Status from_json(td_api::chatActionChoosingSticker &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatAvailableReactionsAll &to, JsonObject &from) {
  TRY_STATUS(from_json(to.max_reaction_count_, from.extract_field("max_reaction_count")));
  return Status::OK();
}

Status from_json(td_api::chatListArchive &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatMembersFilterContacts &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatPhotoSticker &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  TRY_STATUS(from_json(to.background_fill_, from.extract_field("background_fill")));
  return Status::OK();
}

Status from_json(td_api::dateTimePartPrecisionNone &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::deviceTokenWebPush &to, JsonObject &from) {
  TRY_STATUS(from_json(to.endpoint_, from.extract_field("endpoint")));
  TRY_STATUS(from_json(to.p256dh_base64url_, from.extract_field("p256dh_base64url")));
  TRY_STATUS(from_json(to.auth_base64url_, from.extract_field("auth_base64url")));
  return Status::OK();
}

Status from_json(td_api::emailAddressAuthenticationGoogleId &to, JsonObject &from) {
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  return Status::OK();
}

Status from_json(td_api::fileTypeNone &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeSecret &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeThumbnail &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::formattedText &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.entities_, from.extract_field("entities")));
  return Status::OK();
}

Status from_json(td_api::groupCallDataChannelMain &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::inlineKeyboardButtonTypeLoginUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.forward_text_, from.extract_field("forward_text")));
  return Status::OK();
}

Status from_json(td_api::inlineQueryResultsButton &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::inputCallFromMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::inputCredentialsSaved &to, JsonObject &from) {
  TRY_STATUS(from_json(to.saved_credentials_id_, from.extract_field("saved_credentials_id")));
  return Status::OK();
}

Status from_json(td_api::inputGroupCallMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::inputInlineQueryResultPhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.description_, from.extract_field("description")));
  TRY_STATUS(from_json(to.thumbnail_url_, from.extract_field("thumbnail_url")));
  TRY_STATUS(from_json(to.photo_url_, from.extract_field("photo_url")));
  TRY_STATUS(from_json(to.photo_width_, from.extract_field("photo_width")));
  TRY_STATUS(from_json(to.photo_height_, from.extract_field("photo_height")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::inputMessageAnimation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.animation_, from.extract_field("animation")));
  TRY_STATUS(from_json(to.thumbnail_, from.extract_field("thumbnail")));
  TRY_STATUS(from_json(to.added_sticker_file_ids_, from.extract_field("added_sticker_file_ids")));
  TRY_STATUS(from_json(to.duration_, from.extract_field("duration")));
  TRY_STATUS(from_json(to.width_, from.extract_field("width")));
  TRY_STATUS(from_json(to.height_, from.extract_field("height")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  TRY_STATUS(from_json(to.show_caption_above_media_, from.extract_field("show_caption_above_media")));
  TRY_STATUS(from_json(to.has_spoiler_, from.extract_field("has_spoiler")));
  return Status::OK();
}

Status from_json(td_api::inputMessageLocation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  TRY_STATUS(from_json(to.live_period_, from.extract_field("live_period")));
  TRY_STATUS(from_json(to.heading_, from.extract_field("heading")));
  TRY_STATUS(from_json(to.proximity_alert_radius_, from.extract_field("proximity_alert_radius")));
  return Status::OK();
}

Status from_json(td_api::inputMessageChecklist &to, JsonObject &from) {
  TRY_STATUS(from_json(to.checklist_, from.extract_field("checklist")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementPassport &to, JsonObject &from) {
  TRY_STATUS(from_json(to.passport_, from.extract_field("passport")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementTemporaryRegistration &to, JsonObject &from) {
  TRY_STATUS(from_json(to.temporary_registration_, from.extract_field("temporary_registration")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementErrorSourceTranslationFile &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.file_hash_, from.extract_field("file_hash")));
  return Status::OK();
}

Status from_json(td_api::inputStoryArea &to, JsonObject &from) {
  TRY_STATUS(from_json(to.position_, from.extract_field("position")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::inputStoryAreas &to, JsonObject &from) {
  TRY_STATUS(from_json(to.areas_, from.extract_field("areas")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeBotAddToChannel &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_username_, from.extract_field("bot_username")));
  TRY_STATUS(from_json(to.administrator_rights_, from.extract_field("administrator_rights")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeChatSelection &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeLanguagePack &to, JsonObject &from) {
  TRY_STATUS(from_json(to.language_pack_id_, from.extract_field("language_pack_id")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeNewStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.content_type_, from.extract_field("content_type")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeQrCodeAuthentication &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeStoryAlbum &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_album_owner_username_, from.extract_field("story_album_owner_username")));
  TRY_STATUS(from_json(to.story_album_id_, from.extract_field("story_album_id")));
  return Status::OK();
}

Status from_json(td_api::jsonObjectMember &to, JsonObject &from) {
  TRY_STATUS(from_json(to.key_, from.extract_field("key")));
  TRY_STATUS(from_json(to.value_, from.extract_field("value")));
  return Status::OK();
}

Status from_json(td_api::keyboardButtonSourceWebApp &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.prepared_button_id_, from.extract_field("prepared_button_id")));
  return Status::OK();
}

Status from_json(td_api::labeledPricePart &to, JsonObject &from) {
  TRY_STATUS(from_json(to.label_, from.extract_field("label")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  return Status::OK();
}

Status from_json(td_api::logStreamDefault &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageCopyOptions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.send_copy_, from.extract_field("send_copy")));
  TRY_STATUS(from_json(to.replace_caption_, from.extract_field("replace_caption")));
  TRY_STATUS(from_json(to.new_caption_, from.extract_field("new_caption")));
  TRY_STATUS(from_json(to.new_show_caption_above_media_, from.extract_field("new_show_caption_above_media")));
  return Status::OK();
}

Status from_json(td_api::messageSourceChatHistory &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageSourceScreenshot &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::networkTypeMobile &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::optionValueEmpty &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::passportElementTypeDriverLicense &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::passportElementTypePhoneNumber &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureImprovedDownloadSpeed &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureAnimatedProfilePhoto &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureMessagePrivacy &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypePinnedChatCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeBioLength &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeOwnedBotCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumStoryFeaturePermanentViewsHistory &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::profileTabLinks &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::publicChatTypeIsLocationBased &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::replyMarkupRemoveKeyboard &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_personal_, from.extract_field("is_personal")));
  return Status::OK();
}

Status from_json(td_api::reportReasonUnrelatedLocation &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesChatTypeFilterPrivate &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterVideo &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterUnreadReaction &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::settingsSectionDevices &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::settingsSectionPowerSaving &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::stickerFormatWebp &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::storePaymentPurposePremiumGiveaway &to, JsonObject &from) {
  TRY_STATUS(from_json(to.parameters_, from.extract_field("parameters")));
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  return Status::OK();
}

Status from_json(td_api::storyContentTypeLive &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedActionEnableArchiveAndMuteNewChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedActionGiftPremiumForChristmas &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedPostPriceTon &to, JsonObject &from) {
  TRY_STATUS(from_json(to.toncoin_cent_count_, from.extract_field("toncoin_cent_count")));
  return Status::OK();
}

Status from_json(td_api::targetChatCurrent &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::telegramPaymentPurposeStarGiveaway &to, JsonObject &from) {
  TRY_STATUS(from_json(to.parameters_, from.extract_field("parameters")));
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  TRY_STATUS(from_json(to.winner_count_, from.extract_field("winner_count")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::textEntityTypeUrl &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypeCode &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypeDateTime &to, JsonObject &from) {
  TRY_STATUS(from_json(to.unix_time_, from.extract_field("unix_time")));
  TRY_STATUS(from_json(to.formatting_type_, from.extract_field("formatting_type")));
  return Status::OK();
}

Status from_json(td_api::topChatCategoryWebAppBots &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingShowStatus &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingAllowPeerToPeerCalls &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingRuleAllowUsers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_ids_, from.extract_field("user_ids")));
  return Status::OK();
}

Status from_json(td_api::webAppOpenModeCompact &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::addChatFolderByInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  TRY_STATUS(from_json(to.chat_ids_, from.extract_field("chat_ids")));
  return Status::OK();
}

Status from_json(td_api::addGiftCollectionGifts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.collection_id_, from.extract_field("collection_id")));
  TRY_STATUS(from_json(to.received_gift_ids_, from.extract_field("received_gift_ids")));
  return Status::OK();
}

Status from_json(td_api::addPollOption &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.option_, from.extract_field("option")));
  return Status::OK();
}

Status from_json(td_api::addSavedNotificationSound &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sound_, from.extract_field("sound")));
  return Status::OK();
}

Status from_json(td_api::answerShippingQuery &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shipping_query_id_, from.extract_field("shipping_query_id")));
  TRY_STATUS(from_json(to.shipping_options_, from.extract_field("shipping_options")));
  TRY_STATUS(from_json(to.error_message_, from.extract_field("error_message")));
  return Status::OK();
}

Status from_json(td_api::buyGiftUpgrade &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.prepaid_upgrade_hash_, from.extract_field("prepaid_upgrade_hash")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::cancelPreliminaryUploadFile &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  return Status::OK();
}

Status from_json(td_api::checkAuthenticationPasswordRecoveryCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.recovery_code_, from.extract_field("recovery_code")));
  return Status::OK();
}

Status from_json(td_api::checkOauthRequestMatchCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  TRY_STATUS(from_json(to.match_code_, from.extract_field("match_code")));
  return Status::OK();
}

Status from_json(td_api::clearAllDraftMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.exclude_secret_chats_, from.extract_field("exclude_secret_chats")));
  return Status::OK();
}

Status from_json(td_api::clickChatSponsoredMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.is_media_click_, from.extract_field("is_media_click")));
  TRY_STATUS(from_json(to.from_fullscreen_, from.extract_field("from_fullscreen")));
  return Status::OK();
}

Status from_json(td_api::commitPendingLiveStoryReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::createBusinessChatLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_info_, from.extract_field("link_info")));
  return Status::OK();
}

Status from_json(td_api::createInvoiceLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.invoice_, from.extract_field("invoice")));
  return Status::OK();
}

Status from_json(td_api::createTemporaryPassword &to, JsonObject &from) {
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  TRY_STATUS(from_json(to.valid_for_, from.extract_field("valid_for")));
  return Status::OK();
}

Status from_json(td_api::deleteBotMediaPreviews &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  TRY_STATUS(from_json(to.file_ids_, from.extract_field("file_ids")));
  return Status::OK();
}

Status from_json(td_api::deleteChatHistory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.remove_from_chat_list_, from.extract_field("remove_from_chat_list")));
  TRY_STATUS(from_json(to.revoke_, from.extract_field("revoke")));
  return Status::OK();
}

Status from_json(td_api::deleteForumTopic &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  return Status::OK();
}

Status from_json(td_api::deleteQuickReplyShortcut &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shortcut_id_, from.extract_field("shortcut_id")));
  return Status::OK();
}

Status from_json(td_api::deleteStoryAlbum &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.story_album_id_, from.extract_field("story_album_id")));
  return Status::OK();
}

Status from_json(td_api::dropGiftOriginalDetails &to, JsonObject &from) {
  TRY_STATUS(from_json(to.received_gift_id_, from.extract_field("received_gift_id")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::editBusinessStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  TRY_STATUS(from_json(to.content_, from.extract_field("content")));
  TRY_STATUS(from_json(to.areas_, from.extract_field("areas")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  TRY_STATUS(from_json(to.privacy_settings_, from.extract_field("privacy_settings")));
  return Status::OK();
}

Status from_json(td_api::editInlineMessageMedia &to, JsonObject &from) {
  TRY_STATUS(from_json(to.inline_message_id_, from.extract_field("inline_message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::editMessageText &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::endGroupCall &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::getAllStickerEmojis &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_type_, from.extract_field("sticker_type")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.return_only_main_emoji_, from.extract_field("return_only_main_emoji")));
  return Status::OK();
}

Status from_json(td_api::getAuthorizationState &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getBlockedMessageSenders &to, JsonObject &from) {
  TRY_STATUS(from_json(to.block_list_, from.extract_field("block_list")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getBusinessAccountStarAmount &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  return Status::OK();
}

Status from_json(td_api::getChatActiveStories &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getChatBoostStatus &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getChatHistory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.from_message_id_, from.extract_field("from_message_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  TRY_STATUS(from_json(to.only_local_, from.extract_field("only_local")));
  return Status::OK();
}

Status from_json(td_api::getChatMessageCalendar &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.filter_, from.extract_field("filter")));
  TRY_STATUS(from_json(to.from_message_id_, from.extract_field("from_message_id")));
  return Status::OK();
}

Status from_json(td_api::getChatRevenueWithdrawalUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::getChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_list_, from.extract_field("chat_list")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getContacts &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getDatabaseStatistics &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getDirectMessagesChatTopicHistory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.from_message_id_, from.extract_field("from_message_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getFavoriteStickers &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getForumTopics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.offset_date_, from.extract_field("offset_date")));
  TRY_STATUS(from_json(to.offset_message_id_, from.extract_field("offset_message_id")));
  TRY_STATUS(from_json(to.offset_forum_topic_id_, from.extract_field("offset_forum_topic_id")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getGreetingStickers &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getInlineGameHighScores &to, JsonObject &from) {
  TRY_STATUS(from_json(to.inline_message_id_, from.extract_field("inline_message_id")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::getLanguagePackInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.language_pack_id_, from.extract_field("language_pack_id")));
  return Status::OK();
}

Status from_json(td_api::getLogStream &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getMarkdownText &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::getMessageFileType &to, JsonObject &from) {
  TRY_STATUS(from_json(to.message_file_head_, from.extract_field("message_file_head")));
  return Status::OK();
}

Status from_json(td_api::getMessageThread &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::getOwnedStickerSets &to, JsonObject &from) {
  TRY_STATUS(from_json(to.offset_sticker_set_id_, from.extract_field("offset_sticker_set_id")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getPhoneNumberInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.phone_number_prefix_, from.extract_field("phone_number_prefix")));
  return Status::OK();
}

Status from_json(td_api::getPremiumLimit &to, JsonObject &from) {
  TRY_STATUS(from_json(to.limit_type_, from.extract_field("limit_type")));
  return Status::OK();
}

Status from_json(td_api::getReadDatePrivacySettings &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getRecommendedChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getSavedNotificationSounds &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getStarGiveawayPaymentOptions &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getStickerOutlineSvgPath &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_file_id_, from.extract_field("sticker_file_id")));
  TRY_STATUS(from_json(to.for_animated_emoji_, from.extract_field("for_animated_emoji")));
  TRY_STATUS(from_json(to.for_clicked_animated_emoji_message_, from.extract_field("for_clicked_animated_emoji_message")));
  return Status::OK();
}

Status from_json(td_api::getStoryInteractions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.only_contacts_, from.extract_field("only_contacts")));
  TRY_STATUS(from_json(to.prefer_forwards_, from.extract_field("prefer_forwards")));
  TRY_STATUS(from_json(to.prefer_with_reaction_, from.extract_field("prefer_with_reaction")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getSupergroupFullInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  return Status::OK();
}

Status from_json(td_api::getTimeZones &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getUpgradedGiftVariants &to, JsonObject &from) {
  TRY_STATUS(from_json(to.regular_gift_id_, from.extract_field("regular_gift_id")));
  TRY_STATUS(from_json(to.return_upgrade_models_, from.extract_field("return_upgrade_models")));
  TRY_STATUS(from_json(to.return_craft_models_, from.extract_field("return_craft_models")));
  return Status::OK();
}

Status from_json(td_api::getUserProfilePhotos &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getWebPageInstantView &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  TRY_STATUS(from_json(to.only_local_, from.extract_field("only_local")));
  return Status::OK();
}

Status from_json(td_api::isLoginEmailAddressRequired &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::leaveGroupCall &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::logOut &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::openWebApp &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.reply_to_, from.extract_field("reply_to")));
  TRY_STATUS(from_json(to.parameters_, from.extract_field("parameters")));
  return Status::OK();
}

Status from_json(td_api::processChatFolderNewChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_id_, from.extract_field("chat_folder_id")));
  TRY_STATUS(from_json(to.added_chat_ids_, from.extract_field("added_chat_ids")));
  return Status::OK();
}

Status from_json(td_api::readAllChatReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::recognizeSpeech &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::removeContacts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_ids_, from.extract_field("user_ids")));
  return Status::OK();
}

Status from_json(td_api::removeNotificationGroup &to, JsonObject &from) {
  TRY_STATUS(from_json(to.notification_group_id_, from.extract_field("notification_group_id")));
  TRY_STATUS(from_json(to.max_notification_id_, from.extract_field("max_notification_id")));
  return Status::OK();
}

Status from_json(td_api::removeSavedNotificationSound &to, JsonObject &from) {
  TRY_STATUS(from_json(to.notification_sound_id_, from.extract_field("notification_sound_id")));
  return Status::OK();
}

Status from_json(td_api::reorderGiftCollectionGifts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.collection_id_, from.extract_field("collection_id")));
  TRY_STATUS(from_json(to.received_gift_ids_, from.extract_field("received_gift_ids")));
  return Status::OK();
}

Status from_json(td_api::replaceStickerInSet &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.old_sticker_, from.extract_field("old_sticker")));
  TRY_STATUS(from_json(to.new_sticker_, from.extract_field("new_sticker")));
  return Status::OK();
}

Status from_json(td_api::reportStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  TRY_STATUS(from_json_bytes(to.option_id_, from.extract_field("option_id")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::resendLoginEmailAddressCode &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::reuseStarSubscription &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subscription_id_, from.extract_field("subscription_id")));
  return Status::OK();
}

Status from_json(td_api::searchChatAffiliateProgram &to, JsonObject &from) {
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  TRY_STATUS(from_json(to.referrer_, from.extract_field("referrer")));
  return Status::OK();
}

Status from_json(td_api::searchGiftsForResale &to, JsonObject &from) {
  TRY_STATUS(from_json(to.gift_id_, from.extract_field("gift_id")));
  TRY_STATUS(from_json(to.order_, from.extract_field("order")));
  TRY_STATUS(from_json(to.for_crafting_, from.extract_field("for_crafting")));
  TRY_STATUS(from_json(to.for_stars_, from.extract_field("for_stars")));
  TRY_STATUS(from_json(to.attributes_, from.extract_field("attributes")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchPublicStoriesByLocation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.address_, from.extract_field("address")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchStickers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_type_, from.extract_field("sticker_type")));
  TRY_STATUS(from_json(to.emojis_, from.extract_field("emojis")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.input_language_codes_, from.extract_field("input_language_codes")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::sendBusinessMessageAlbum &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.reply_to_, from.extract_field("reply_to")));
  TRY_STATUS(from_json(to.disable_notification_, from.extract_field("disable_notification")));
  TRY_STATUS(from_json(to.protect_content_, from.extract_field("protect_content")));
  TRY_STATUS(from_json(to.effect_id_, from.extract_field("effect_id")));
  TRY_STATUS(from_json(to.input_message_contents_, from.extract_field("input_message_contents")));
  return Status::OK();
}

Status from_json(td_api::sendGiftPurchaseOffer &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.gift_name_, from.extract_field("gift_name")));
  TRY_STATUS(from_json(to.price_, from.extract_field("price")));
  TRY_STATUS(from_json(to.duration_, from.extract_field("duration")));
  TRY_STATUS(from_json(to.paid_message_star_count_, from.extract_field("paid_message_star_count")));
  return Status::OK();
}

Status from_json(td_api::sendPhoneNumberFirebaseSms &to, JsonObject &from) {
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  return Status::OK();
}

Status from_json(td_api::setApplicationVerificationToken &to, JsonObject &from) {
  TRY_STATUS(from_json(to.verification_id_, from.extract_field("verification_id")));
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  return Status::OK();
}

Status from_json(td_api::setBotInfoDescription &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  TRY_STATUS(from_json(to.description_, from.extract_field("description")));
  return Status::OK();
}

Status from_json(td_api::setBusinessAccountUsername &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  return Status::OK();
}

Status from_json(td_api::setChatActiveStoriesList &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.story_list_, from.extract_field("story_list")));
  return Status::OK();
}

Status from_json(td_api::setChatEmojiStatus &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.emoji_status_, from.extract_field("emoji_status")));
  return Status::OK();
}

Status from_json(td_api::setChatPhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.photo_, from.extract_field("photo")));
  return Status::OK();
}

Status from_json(td_api::setCustomLanguagePack &to, JsonObject &from) {
  TRY_STATUS(from_json(to.info_, from.extract_field("info")));
  TRY_STATUS(from_json(to.strings_, from.extract_field("strings")));
  return Status::OK();
}

Status from_json(td_api::setEmojiStatus &to, JsonObject &from) {
  TRY_STATUS(from_json(to.emoji_status_, from.extract_field("emoji_status")));
  return Status::OK();
}

Status from_json(td_api::setGroupCallParticipantVolumeLevel &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.participant_id_, from.extract_field("participant_id")));
  TRY_STATUS(from_json(to.volume_level_, from.extract_field("volume_level")));
  return Status::OK();
}

Status from_json(td_api::setMenuButton &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.menu_button_, from.extract_field("menu_button")));
  return Status::OK();
}

Status from_json(td_api::setPaidMessageReactionType &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::setPollAnswer &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.option_ids_, from.extract_field("option_ids")));
  return Status::OK();
}

Status from_json(td_api::setScopeNotificationSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.scope_, from.extract_field("scope")));
  TRY_STATUS(from_json(to.notification_settings_, from.extract_field("notification_settings")));
  return Status::OK();
}

Status from_json(td_api::setStoryReaction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  TRY_STATUS(from_json(to.reaction_type_, from.extract_field("reaction_type")));
  TRY_STATUS(from_json(to.update_recent_reactions_, from.extract_field("update_recent_reactions")));
  return Status::OK();
}

Status from_json(td_api::setUserNote &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.note_, from.extract_field("note")));
  return Status::OK();
}

Status from_json(td_api::shareUsersWithBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.source_, from.extract_field("source")));
  TRY_STATUS(from_json(to.button_id_, from.extract_field("button_id")));
  TRY_STATUS(from_json(to.shared_user_ids_, from.extract_field("shared_user_ids")));
  TRY_STATUS(from_json(to.only_check_, from.extract_field("only_check")));
  return Status::OK();
}

Status from_json(td_api::summarizeMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.translate_to_language_code_, from.extract_field("translate_to_language_code")));
  TRY_STATUS(from_json(to.tone_, from.extract_field("tone")));
  return Status::OK();
}

Status from_json(td_api::testCallVectorString &to, JsonObject &from) {
  TRY_STATUS(from_json(to.x_, from.extract_field("x")));
  return Status::OK();
}

Status from_json(td_api::toggleBotCanManageEmojiStatus &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.can_manage_emoji_status_, from.extract_field("can_manage_emoji_status")));
  return Status::OK();
}

Status from_json(td_api::toggleChatIsPinned &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_list_, from.extract_field("chat_list")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.is_pinned_, from.extract_field("is_pinned")));
  return Status::OK();
}

Status from_json(td_api::toggleGroupCallAreMessagesAllowed &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.are_messages_allowed_, from.extract_field("are_messages_allowed")));
  return Status::OK();
}

Status from_json(td_api::toggleSessionCanAcceptSecretChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.session_id_, from.extract_field("session_id")));
  TRY_STATUS(from_json(to.can_accept_secret_chats_, from.extract_field("can_accept_secret_chats")));
  return Status::OK();
}

Status from_json(td_api::toggleSupergroupJoinByRequest &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.join_by_request_, from.extract_field("join_by_request")));
  return Status::OK();
}

Status from_json(td_api::transferGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.received_gift_id_, from.extract_field("received_gift_id")));
  TRY_STATUS(from_json(to.new_owner_id_, from.extract_field("new_owner_id")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::uploadStickerFile &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.sticker_format_, from.extract_field("sticker_format")));
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  return Status::OK();
}

void to_json(JsonValueScope &jv, const td_api::acceptedGiftTypes &object) {
  auto jo = jv.enter_object();
  jo("@type", "acceptedGiftTypes");
  jo("unlimited_gifts", JsonBool{object.unlimited_gifts_});
  jo("limited_gifts", JsonBool{object.limited_gifts_});
  jo("upgraded_gifts", JsonBool{object.upgraded_gifts_});
  jo("gifts_from_channels", JsonBool{object.gifts_from_channels_});
  jo("premium_subscription", JsonBool{object.premium_subscription_});
}

void to_json(JsonValueScope &jv, const td_api::advertisementSponsor &object) {
  auto jo = jv.enter_object();
  jo("@type", "advertisementSponsor");
  jo("url", object.url_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("info", object.info_);
}

void to_json(JsonValueScope &jv, const td_api::animations &object) {
  auto jo = jv.enter_object();
  jo("@type", "animations");
  jo("animations", ToJson(object.animations_));
}

void to_json(JsonValueScope &jv, const td_api::audios &object) {
  auto jo = jv.enter_object();
  jo("@type", "audios");
  jo("total_count", object.total_count_);
  jo("audios", ToJson(object.audios_));
}

void to_json(JsonValueScope &jv, const td_api::availableGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "availableGift");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  jo("resale_count", object.resale_count_);
  jo("min_resale_star_count", object.min_resale_star_count_);
  jo("title", object.title_);
}

void to_json(JsonValueScope &jv, const td_api::bankCardInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "bankCardInfo");
  jo("title", object.title_);
  jo("actions", ToJson(object.actions_));
}

void to_json(JsonValueScope &jv, const td_api::botMediaPreviewInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "botMediaPreviewInfo");
  jo("previews", ToJson(object.previews_));
  jo("language_codes", ToJson(object.language_codes_));
}

void to_json(JsonValueScope &jv, const td_api::businessBotManageBar &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessBotManageBar");
  jo("bot_user_id", object.bot_user_id_);
  jo("manage_url", object.manage_url_);
  jo("is_bot_paused", JsonBool{object.is_bot_paused_});
  jo("can_bot_reply", JsonBool{object.can_bot_reply_});
}

void to_json(JsonValueScope &jv, const td_api::businessFeatures &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeatures");
  jo("features", ToJson(object.features_));
}

void to_json(JsonValueScope &jv, const td_api::businessStartPage &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessStartPage");
  jo("title", object.title_);
  jo("message", object.message_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::callbackQueryAnswer &object) {
  auto jo = jv.enter_object();
  jo("@type", "callbackQueryAnswer");
  jo("text", object.text_);
  jo("show_alert", JsonBool{object.show_alert_});
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::chatActiveStories &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActiveStories");
  jo("chat_id", object.chat_id_);
  if (object.list_) {
    jo("list", ToJson(*object.list_));
  }
  jo("order", object.order_);
  jo("can_be_archived", JsonBool{object.can_be_archived_});
  jo("max_read_story_id", object.max_read_story_id_);
  jo("stories", ToJson(object.stories_));
}

void to_json(JsonValueScope &jv, const td_api::chatBoostLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatBoostLink");
  jo("link", object.link_);
  jo("is_public", JsonBool{object.is_public_});
}

void to_json(JsonValueScope &jv, const td_api::chatFolder &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatFolder");
  if (object.name_) {
    jo("name", ToJson(*object.name_));
  }
  if (object.icon_) {
    jo("icon", ToJson(*object.icon_));
  }
  jo("color_id", object.color_id_);
  jo("is_shareable", JsonBool{object.is_shareable_});
  jo("pinned_chat_ids", ToJson(object.pinned_chat_ids_));
  jo("included_chat_ids", ToJson(object.included_chat_ids_));
  jo("excluded_chat_ids", ToJson(object.excluded_chat_ids_));
  jo("exclude_muted", JsonBool{object.exclude_muted_});
  jo("exclude_read", JsonBool{object.exclude_read_});
  jo("exclude_archived", JsonBool{object.exclude_archived_});
  jo("include_contacts", JsonBool{object.include_contacts_});
  jo("include_non_contacts", JsonBool{object.include_non_contacts_});
  jo("include_bots", JsonBool{object.include_bots_});
  jo("include_groups", JsonBool{object.include_groups_});
  jo("include_channels", JsonBool{object.include_channels_});
}

void to_json(JsonValueScope &jv, const td_api::chatInviteLinkCounts &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatInviteLinkCounts");
  jo("invite_link_counts", ToJson(object.invite_link_counts_));
}

void to_json(JsonValueScope &jv, const td_api::ChatList &object) {
  td_api::downcast_call(const_cast<td_api::ChatList &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatListMain &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatListMain");
}

void to_json(JsonValueScope &jv, const td_api::chatListArchive &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatListArchive");
}

void to_json(JsonValueScope &jv, const td_api::chatListFolder &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatListFolder");
  jo("chat_folder_id", object.chat_folder_id_);
}

void to_json(JsonValueScope &jv, const td_api::chatPermissions &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatPermissions");
  jo("can_send_basic_messages", JsonBool{object.can_send_basic_messages_});
  jo("can_send_audios", JsonBool{object.can_send_audios_});
  jo("can_send_documents", JsonBool{object.can_send_documents_});
  jo("can_send_photos", JsonBool{object.can_send_photos_});
  jo("can_send_videos", JsonBool{object.can_send_videos_});
  jo("can_send_video_notes", JsonBool{object.can_send_video_notes_});
  jo("can_send_voice_notes", JsonBool{object.can_send_voice_notes_});
  jo("can_send_polls", JsonBool{object.can_send_polls_});
  jo("can_send_other_messages", JsonBool{object.can_send_other_messages_});
  jo("can_add_link_previews", JsonBool{object.can_add_link_previews_});
  jo("can_edit_tag", JsonBool{object.can_edit_tag_});
  jo("can_change_info", JsonBool{object.can_change_info_});
  jo("can_invite_users", JsonBool{object.can_invite_users_});
  jo("can_pin_messages", JsonBool{object.can_pin_messages_});
  jo("can_create_topics", JsonBool{object.can_create_topics_});
}

void to_json(JsonValueScope &jv, const td_api::chatRevenueTransaction &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatRevenueTransaction");
  jo("cryptocurrency", object.cryptocurrency_);
  jo("cryptocurrency_amount", ToJson(JsonInt64{object.cryptocurrency_amount_}));
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::ChatStatisticsObjectType &object) {
  td_api::downcast_call(const_cast<td_api::ChatStatisticsObjectType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatStatisticsObjectTypeMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatStatisticsObjectTypeMessage");
  jo("message_id", object.message_id_);
}

void to_json(JsonValueScope &jv, const td_api::chatStatisticsObjectTypeStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatStatisticsObjectTypeStory");
  jo("story_id", object.story_id_);
}

void to_json(JsonValueScope &jv, const td_api::closedVectorPath &object) {
  auto jo = jv.enter_object();
  jo("@type", "closedVectorPath");
  jo("commands", ToJson(object.commands_));
}

void to_json(JsonValueScope &jv, const td_api::countries &object) {
  auto jo = jv.enter_object();
  jo("@type", "countries");
  jo("countries", ToJson(object.countries_));
}

void to_json(JsonValueScope &jv, const td_api::dateRange &object) {
  auto jo = jv.enter_object();
  jo("@type", "dateRange");
  jo("start_date", object.start_date_);
  jo("end_date", object.end_date_);
}

void to_json(JsonValueScope &jv, const td_api::directMessagesChatTopic &object) {
  auto jo = jv.enter_object();
  jo("@type", "directMessagesChatTopic");
  jo("chat_id", object.chat_id_);
  jo("id", object.id_);
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  jo("order", ToJson(JsonInt64{object.order_}));
  jo("can_send_unpaid_messages", JsonBool{object.can_send_unpaid_messages_});
  jo("is_marked_as_unread", JsonBool{object.is_marked_as_unread_});
  jo("unread_count", object.unread_count_);
  jo("last_read_inbox_message_id", object.last_read_inbox_message_id_);
  jo("last_read_outbox_message_id", object.last_read_outbox_message_id_);
  jo("unread_reaction_count", object.unread_reaction_count_);
  if (object.last_message_) {
    jo("last_message", ToJson(*object.last_message_));
  }
  if (object.draft_message_) {
    jo("draft_message", ToJson(*object.draft_message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::emojiChatTheme &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiChatTheme");
  jo("name", object.name_);
  if (object.light_settings_) {
    jo("light_settings", ToJson(*object.light_settings_));
  }
  if (object.dark_settings_) {
    jo("dark_settings", ToJson(*object.dark_settings_));
  }
}

void to_json(JsonValueScope &jv, const td_api::encryptedCredentials &object) {
  auto jo = jv.enter_object();
  jo("@type", "encryptedCredentials");
  jo("data", base64_encode(object.data_));
  jo("hash", base64_encode(object.hash_));
  jo("secret", base64_encode(object.secret_));
}

void to_json(JsonValueScope &jv, const td_api::FileType &object) {
  td_api::downcast_call(const_cast<td_api::FileType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::fileTypeNone &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeNone");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeAnimation &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeAnimation");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeAudio &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeAudio");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeDocument &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeDocument");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeLivePhotoVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeLivePhotoVideo");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeNotificationSound &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeNotificationSound");
}

void to_json(JsonValueScope &jv, const td_api::fileTypePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypePhoto");
}

void to_json(JsonValueScope &jv, const td_api::fileTypePhotoStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypePhotoStory");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeProfilePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeProfilePhoto");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeSecret &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeSecret");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeSecretThumbnail &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeSecretThumbnail");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeSecure &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeSecure");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeSelfDestructingLivePhotoVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeSelfDestructingLivePhotoVideo");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeSelfDestructingPhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeSelfDestructingPhoto");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeSelfDestructingVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeSelfDestructingVideo");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeSelfDestructingVideoNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeSelfDestructingVideoNote");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeSelfDestructingVoiceNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeSelfDestructingVoiceNote");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeSticker &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeSticker");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeThumbnail &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeThumbnail");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeUnknown &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeUnknown");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeVideo");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeVideoNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeVideoNote");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeVideoStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeVideoStory");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeVoiceNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeVoiceNote");
}

void to_json(JsonValueScope &jv, const td_api::fileTypeWallpaper &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileTypeWallpaper");
}

void to_json(JsonValueScope &jv, const td_api::foundAffiliateProgram &object) {
  auto jo = jv.enter_object();
  jo("@type", "foundAffiliateProgram");
  jo("bot_user_id", object.bot_user_id_);
  if (object.info_) {
    jo("info", ToJson(*object.info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::foundStories &object) {
  auto jo = jv.enter_object();
  jo("@type", "foundStories");
  jo("total_count", object.total_count_);
  jo("stories", ToJson(object.stories_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::giftAuctionAcquiredGifts &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftAuctionAcquiredGifts");
  jo("gifts", ToJson(object.gifts_));
}

void to_json(JsonValueScope &jv, const td_api::GiftPurchaseOfferState &object) {
  td_api::downcast_call(const_cast<td_api::GiftPurchaseOfferState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::giftPurchaseOfferStatePending &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftPurchaseOfferStatePending");
}

void to_json(JsonValueScope &jv, const td_api::giftPurchaseOfferStateAccepted &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftPurchaseOfferStateAccepted");
}

void to_json(JsonValueScope &jv, const td_api::giftPurchaseOfferStateRejected &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftPurchaseOfferStateRejected");
}

void to_json(JsonValueScope &jv, const td_api::giftsForResale &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftsForResale");
  jo("total_count", object.total_count_);
  jo("gifts", ToJson(object.gifts_));
  jo("models", ToJson(object.models_));
  jo("symbols", ToJson(object.symbols_));
  jo("backdrops", ToJson(object.backdrops_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::groupCallMessageLevel &object) {
  auto jo = jv.enter_object();
  jo("@type", "groupCallMessageLevel");
  jo("min_star_count", object.min_star_count_);
  jo("pin_duration", object.pin_duration_);
  jo("max_text_length", object.max_text_length_);
  jo("max_custom_emoji_count", object.max_custom_emoji_count_);
  jo("first_color", object.first_color_);
  jo("second_color", object.second_color_);
  jo("background_color", object.background_color_);
}

void to_json(JsonValueScope &jv, const td_api::httpUrl &object) {
  auto jo = jv.enter_object();
  jo("@type", "httpUrl");
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::inputChecklist &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputChecklist");
  if (object.title_) {
    jo("title", ToJson(*object.title_));
  }
  jo("tasks", ToJson(object.tasks_));
  jo("others_can_add_tasks", JsonBool{object.others_can_add_tasks_});
  jo("others_can_mark_tasks_as_done", JsonBool{object.others_can_mark_tasks_as_done_});
}

void to_json(JsonValueScope &jv, const td_api::inputSuggestedPostInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputSuggestedPostInfo");
  if (object.price_) {
    jo("price", ToJson(*object.price_));
  }
  jo("send_date", object.send_date_);
}

void to_json(JsonValueScope &jv, const td_api::keyboardButton &object) {
  auto jo = jv.enter_object();
  jo("@type", "keyboardButton");
  jo("text", object.text_);
  jo("icon_custom_emoji_id", ToJson(JsonInt64{object.icon_custom_emoji_id_}));
  if (object.style_) {
    jo("style", ToJson(*object.style_));
  }
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewOptions &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewOptions");
  jo("is_disabled", JsonBool{object.is_disabled_});
  jo("url", object.url_);
  jo("force_small_media", JsonBool{object.force_small_media_});
  jo("force_large_media", JsonBool{object.force_large_media_});
  jo("show_above_text", JsonBool{object.show_above_text_});
}

void to_json(JsonValueScope &jv, const td_api::logVerbosityLevel &object) {
  auto jo = jv.enter_object();
  jo("@type", "logVerbosityLevel");
  jo("verbosity_level", object.verbosity_level_);
}

void to_json(JsonValueScope &jv, const td_api::MessageContent &object) {
  td_api::downcast_call(const_cast<td_api::MessageContent &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::messageText &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageText");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  if (object.link_preview_) {
    jo("link_preview", ToJson(*object.link_preview_));
  }
  if (object.link_preview_options_) {
    jo("link_preview_options", ToJson(*object.link_preview_options_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageAnimation &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageAnimation");
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("show_caption_above_media", JsonBool{object.show_caption_above_media_});
  jo("has_spoiler", JsonBool{object.has_spoiler_});
  jo("is_secret", JsonBool{object.is_secret_});
}

void to_json(JsonValueScope &jv, const td_api::messageAudio &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageAudio");
  if (object.audio_) {
    jo("audio", ToJson(*object.audio_));
  }
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageDocument &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageDocument");
  if (object.document_) {
    jo("document", ToJson(*object.document_));
  }
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messagePaidMedia &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePaidMedia");
  jo("star_count", object.star_count_);
  jo("media", ToJson(object.media_));
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("show_caption_above_media", JsonBool{object.show_caption_above_media_});
}

void to_json(JsonValueScope &jv, const td_api::messagePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePhoto");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("show_caption_above_media", JsonBool{object.show_caption_above_media_});
  jo("has_spoiler", JsonBool{object.has_spoiler_});
  jo("is_secret", JsonBool{object.is_secret_});
}

void to_json(JsonValueScope &jv, const td_api::messageSticker &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSticker");
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
  jo("is_premium", JsonBool{object.is_premium_});
}

void to_json(JsonValueScope &jv, const td_api::messageVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageVideo");
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
  jo("alternative_videos", ToJson(object.alternative_videos_));
  jo("storyboards", ToJson(object.storyboards_));
  if (object.cover_) {
    jo("cover", ToJson(*object.cover_));
  }
  jo("start_timestamp", object.start_timestamp_);
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("show_caption_above_media", JsonBool{object.show_caption_above_media_});
  jo("has_spoiler", JsonBool{object.has_spoiler_});
  jo("is_secret", JsonBool{object.is_secret_});
}

void to_json(JsonValueScope &jv, const td_api::messageVideoNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageVideoNote");
  if (object.video_note_) {
    jo("video_note", ToJson(*object.video_note_));
  }
  jo("is_viewed", JsonBool{object.is_viewed_});
  jo("is_secret", JsonBool{object.is_secret_});
}

void to_json(JsonValueScope &jv, const td_api::messageVoiceNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageVoiceNote");
  if (object.voice_note_) {
    jo("voice_note", ToJson(*object.voice_note_));
  }
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("is_listened", JsonBool{object.is_listened_});
}

void to_json(JsonValueScope &jv, const td_api::messageExpiredPhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageExpiredPhoto");
}

void to_json(JsonValueScope &jv, const td_api::messageExpiredVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageExpiredVideo");
}

void to_json(JsonValueScope &jv, const td_api::messageExpiredVideoNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageExpiredVideoNote");
}

void to_json(JsonValueScope &jv, const td_api::messageExpiredVoiceNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageExpiredVoiceNote");
}

void to_json(JsonValueScope &jv, const td_api::messageLocation &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageLocation");
  if (object.location_) {
    jo("location", ToJson(*object.location_));
  }
  jo("live_period", object.live_period_);
  jo("expires_in", object.expires_in_);
  jo("heading", object.heading_);
  jo("proximity_alert_radius", object.proximity_alert_radius_);
}

void to_json(JsonValueScope &jv, const td_api::messageVenue &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageVenue");
  if (object.venue_) {
    jo("venue", ToJson(*object.venue_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageContact &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageContact");
  if (object.contact_) {
    jo("contact", ToJson(*object.contact_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageAnimatedEmoji &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageAnimatedEmoji");
  if (object.animated_emoji_) {
    jo("animated_emoji", ToJson(*object.animated_emoji_));
  }
  jo("emoji", object.emoji_);
}

void to_json(JsonValueScope &jv, const td_api::messageDice &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageDice");
  if (object.initial_state_) {
    jo("initial_state", ToJson(*object.initial_state_));
  }
  if (object.final_state_) {
    jo("final_state", ToJson(*object.final_state_));
  }
  jo("emoji", object.emoji_);
  jo("value", object.value_);
  jo("success_animation_frame_number", object.success_animation_frame_number_);
}

void to_json(JsonValueScope &jv, const td_api::messageGame &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageGame");
  if (object.game_) {
    jo("game", ToJson(*object.game_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messagePoll &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePoll");
  if (object.poll_) {
    jo("poll", ToJson(*object.poll_));
  }
  if (object.description_) {
    jo("description", ToJson(*object.description_));
  }
  if (object.media_) {
    jo("media", ToJson(*object.media_));
  }
  jo("can_add_option", JsonBool{object.can_add_option_});
}

void to_json(JsonValueScope &jv, const td_api::messageStakeDice &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageStakeDice");
  if (object.initial_state_) {
    jo("initial_state", ToJson(*object.initial_state_));
  }
  if (object.final_state_) {
    jo("final_state", ToJson(*object.final_state_));
  }
  jo("value", object.value_);
  jo("stake_toncoin_amount", object.stake_toncoin_amount_);
  jo("prize_toncoin_amount", object.prize_toncoin_amount_);
}

void to_json(JsonValueScope &jv, const td_api::messageStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageStory");
  jo("story_poster_chat_id", object.story_poster_chat_id_);
  jo("story_id", object.story_id_);
  jo("via_mention", JsonBool{object.via_mention_});
}

void to_json(JsonValueScope &jv, const td_api::messageChecklist &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChecklist");
  if (object.list_) {
    jo("list", ToJson(*object.list_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageInvoice &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageInvoice");
  if (object.product_info_) {
    jo("product_info", ToJson(*object.product_info_));
  }
  jo("currency", object.currency_);
  jo("total_amount", object.total_amount_);
  jo("start_parameter", object.start_parameter_);
  jo("is_test", JsonBool{object.is_test_});
  jo("need_shipping_address", JsonBool{object.need_shipping_address_});
  jo("receipt_message_id", object.receipt_message_id_);
  if (object.paid_media_) {
    jo("paid_media", ToJson(*object.paid_media_));
  }
  if (object.paid_media_caption_) {
    jo("paid_media_caption", ToJson(*object.paid_media_caption_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageCall");
  jo("unique_id", ToJson(JsonInt64{object.unique_id_}));
  jo("is_video", JsonBool{object.is_video_});
  if (object.discard_reason_) {
    jo("discard_reason", ToJson(*object.discard_reason_));
  }
  jo("duration", object.duration_);
}

void to_json(JsonValueScope &jv, const td_api::messageGroupCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageGroupCall");
  jo("unique_id", ToJson(JsonInt64{object.unique_id_}));
  jo("is_active", JsonBool{object.is_active_});
  jo("was_missed", JsonBool{object.was_missed_});
  jo("is_video", JsonBool{object.is_video_});
  jo("duration", object.duration_);
  jo("other_participant_ids", ToJson(object.other_participant_ids_));
}

void to_json(JsonValueScope &jv, const td_api::messageVideoChatScheduled &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageVideoChatScheduled");
  jo("group_call_id", object.group_call_id_);
  jo("start_date", object.start_date_);
}

void to_json(JsonValueScope &jv, const td_api::messageVideoChatStarted &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageVideoChatStarted");
  jo("group_call_id", object.group_call_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageVideoChatEnded &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageVideoChatEnded");
  jo("duration", object.duration_);
}

void to_json(JsonValueScope &jv, const td_api::messageInviteVideoChatParticipants &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageInviteVideoChatParticipants");
  jo("group_call_id", object.group_call_id_);
  jo("user_ids", ToJson(object.user_ids_));
}

void to_json(JsonValueScope &jv, const td_api::messagePollOptionAdded &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePollOptionAdded");
  jo("poll_message_id", object.poll_message_id_);
  jo("option_id", object.option_id_);
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messagePollOptionDeleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePollOptionDeleted");
  jo("poll_message_id", object.poll_message_id_);
  jo("option_id", object.option_id_);
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageBasicGroupChatCreate &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageBasicGroupChatCreate");
  jo("title", object.title_);
  jo("member_user_ids", ToJson(object.member_user_ids_));
}

void to_json(JsonValueScope &jv, const td_api::messageSupergroupChatCreate &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSupergroupChatCreate");
  jo("title", object.title_);
}

void to_json(JsonValueScope &jv, const td_api::messageChatChangeTitle &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatChangeTitle");
  jo("title", object.title_);
}

void to_json(JsonValueScope &jv, const td_api::messageChatChangePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatChangePhoto");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageChatDeletePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatDeletePhoto");
}

void to_json(JsonValueScope &jv, const td_api::messageChatOwnerLeft &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatOwnerLeft");
  jo("new_owner_user_id", object.new_owner_user_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageChatOwnerChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatOwnerChanged");
  jo("new_owner_user_id", object.new_owner_user_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageChatHasProtectedContentToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatHasProtectedContentToggled");
  jo("request_message_id", object.request_message_id_);
  jo("old_has_protected_content", JsonBool{object.old_has_protected_content_});
  jo("new_has_protected_content", JsonBool{object.new_has_protected_content_});
}

void to_json(JsonValueScope &jv, const td_api::messageChatHasProtectedContentDisableRequested &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatHasProtectedContentDisableRequested");
  jo("is_expired", JsonBool{object.is_expired_});
}

void to_json(JsonValueScope &jv, const td_api::messageChatAddMembers &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatAddMembers");
  jo("member_user_ids", ToJson(object.member_user_ids_));
}

void to_json(JsonValueScope &jv, const td_api::messageChatJoinByLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatJoinByLink");
}

void to_json(JsonValueScope &jv, const td_api::messageChatJoinByRequest &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatJoinByRequest");
}

void to_json(JsonValueScope &jv, const td_api::messageChatDeleteMember &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatDeleteMember");
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageChatUpgradeTo &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatUpgradeTo");
  jo("supergroup_id", object.supergroup_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageChatUpgradeFrom &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatUpgradeFrom");
  jo("title", object.title_);
  jo("basic_group_id", object.basic_group_id_);
}

void to_json(JsonValueScope &jv, const td_api::messagePinMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePinMessage");
  jo("message_id", object.message_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageScreenshotTaken &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageScreenshotTaken");
}

void to_json(JsonValueScope &jv, const td_api::messageChatSetBackground &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatSetBackground");
  jo("old_background_message_id", object.old_background_message_id_);
  if (object.background_) {
    jo("background", ToJson(*object.background_));
  }
  jo("only_for_self", JsonBool{object.only_for_self_});
}

void to_json(JsonValueScope &jv, const td_api::messageChatSetTheme &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatSetTheme");
  if (object.theme_) {
    jo("theme", ToJson(*object.theme_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageChatSetMessageAutoDeleteTime &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatSetMessageAutoDeleteTime");
  jo("message_auto_delete_time", object.message_auto_delete_time_);
  jo("from_user_id", object.from_user_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageChatBoost &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatBoost");
  jo("boost_count", object.boost_count_);
}

void to_json(JsonValueScope &jv, const td_api::messageForumTopicCreated &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageForumTopicCreated");
  jo("name", object.name_);
  jo("is_name_implicit", JsonBool{object.is_name_implicit_});
  if (object.icon_) {
    jo("icon", ToJson(*object.icon_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageForumTopicEdited &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageForumTopicEdited");
  jo("name", object.name_);
  jo("edit_icon_custom_emoji_id", JsonBool{object.edit_icon_custom_emoji_id_});
  jo("icon_custom_emoji_id", ToJson(JsonInt64{object.icon_custom_emoji_id_}));
}

void to_json(JsonValueScope &jv, const td_api::messageForumTopicIsClosedToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageForumTopicIsClosedToggled");
  jo("is_closed", JsonBool{object.is_closed_});
}

void to_json(JsonValueScope &jv, const td_api::messageForumTopicIsHiddenToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageForumTopicIsHiddenToggled");
  jo("is_hidden", JsonBool{object.is_hidden_});
}

void to_json(JsonValueScope &jv, const td_api::messageSuggestProfilePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSuggestProfilePhoto");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageSuggestBirthdate &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSuggestBirthdate");
  if (object.birthdate_) {
    jo("birthdate", ToJson(*object.birthdate_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageCustomServiceAction &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageCustomServiceAction");
  jo("text", object.text_);
}

void to_json(JsonValueScope &jv, const td_api::messageGameScore &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageGameScore");
  jo("game_message_id", object.game_message_id_);
  jo("game_id", ToJson(JsonInt64{object.game_id_}));
  jo("score", object.score_);
}

void to_json(JsonValueScope &jv, const td_api::messageManagedBotCreated &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageManagedBotCreated");
  jo("bot_user_id", object.bot_user_id_);
}

void to_json(JsonValueScope &jv, const td_api::messagePaymentSuccessful &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePaymentSuccessful");
  jo("invoice_chat_id", object.invoice_chat_id_);
  jo("invoice_message_id", object.invoice_message_id_);
  jo("currency", object.currency_);
  jo("total_amount", object.total_amount_);
  jo("subscription_until_date", object.subscription_until_date_);
  jo("is_recurring", JsonBool{object.is_recurring_});
  jo("is_first_recurring", JsonBool{object.is_first_recurring_});
  jo("invoice_name", object.invoice_name_);
}

void to_json(JsonValueScope &jv, const td_api::messagePaymentSuccessfulBot &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePaymentSuccessfulBot");
  jo("currency", object.currency_);
  jo("total_amount", object.total_amount_);
  jo("subscription_until_date", object.subscription_until_date_);
  jo("is_recurring", JsonBool{object.is_recurring_});
  jo("is_first_recurring", JsonBool{object.is_first_recurring_});
  jo("invoice_payload", base64_encode(object.invoice_payload_));
  jo("shipping_option_id", object.shipping_option_id_);
  if (object.order_info_) {
    jo("order_info", ToJson(*object.order_info_));
  }
  jo("telegram_payment_charge_id", object.telegram_payment_charge_id_);
  jo("provider_payment_charge_id", object.provider_payment_charge_id_);
}

void to_json(JsonValueScope &jv, const td_api::messagePaymentRefunded &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePaymentRefunded");
  if (object.owner_id_) {
    jo("owner_id", ToJson(*object.owner_id_));
  }
  jo("currency", object.currency_);
  jo("total_amount", object.total_amount_);
  jo("invoice_payload", base64_encode(object.invoice_payload_));
  jo("telegram_payment_charge_id", object.telegram_payment_charge_id_);
  jo("provider_payment_charge_id", object.provider_payment_charge_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageGiftedPremium &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageGiftedPremium");
  jo("gifter_user_id", object.gifter_user_id_);
  jo("receiver_user_id", object.receiver_user_id_);
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("currency", object.currency_);
  jo("amount", object.amount_);
  jo("cryptocurrency", object.cryptocurrency_);
  jo("cryptocurrency_amount", ToJson(JsonInt64{object.cryptocurrency_amount_}));
  jo("month_count", object.month_count_);
  jo("day_count", object.day_count_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messagePremiumGiftCode &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePremiumGiftCode");
  if (object.creator_id_) {
    jo("creator_id", ToJson(*object.creator_id_));
  }
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("is_from_giveaway", JsonBool{object.is_from_giveaway_});
  jo("is_unclaimed", JsonBool{object.is_unclaimed_});
  jo("currency", object.currency_);
  jo("amount", object.amount_);
  jo("cryptocurrency", object.cryptocurrency_);
  jo("cryptocurrency_amount", ToJson(JsonInt64{object.cryptocurrency_amount_}));
  jo("month_count", object.month_count_);
  jo("day_count", object.day_count_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
  jo("code", object.code_);
}

void to_json(JsonValueScope &jv, const td_api::messageGiveawayCreated &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageGiveawayCreated");
  jo("star_count", object.star_count_);
}

void to_json(JsonValueScope &jv, const td_api::messageGiveaway &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageGiveaway");
  if (object.parameters_) {
    jo("parameters", ToJson(*object.parameters_));
  }
  jo("winner_count", object.winner_count_);
  if (object.prize_) {
    jo("prize", ToJson(*object.prize_));
  }
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageGiveawayCompleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageGiveawayCompleted");
  jo("giveaway_message_id", object.giveaway_message_id_);
  jo("winner_count", object.winner_count_);
  jo("is_star_giveaway", JsonBool{object.is_star_giveaway_});
  jo("unclaimed_prize_count", object.unclaimed_prize_count_);
}

void to_json(JsonValueScope &jv, const td_api::messageGiveawayWinners &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageGiveawayWinners");
  jo("boosted_chat_id", object.boosted_chat_id_);
  jo("giveaway_message_id", object.giveaway_message_id_);
  jo("additional_chat_count", object.additional_chat_count_);
  jo("actual_winners_selection_date", object.actual_winners_selection_date_);
  jo("only_new_members", JsonBool{object.only_new_members_});
  jo("was_refunded", JsonBool{object.was_refunded_});
  if (object.prize_) {
    jo("prize", ToJson(*object.prize_));
  }
  jo("prize_description", object.prize_description_);
  jo("winner_count", object.winner_count_);
  jo("winner_user_ids", ToJson(object.winner_user_ids_));
  jo("unclaimed_prize_count", object.unclaimed_prize_count_);
}

void to_json(JsonValueScope &jv, const td_api::messageGiftedStars &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageGiftedStars");
  jo("gifter_user_id", object.gifter_user_id_);
  jo("receiver_user_id", object.receiver_user_id_);
  jo("currency", object.currency_);
  jo("amount", object.amount_);
  jo("cryptocurrency", object.cryptocurrency_);
  jo("cryptocurrency_amount", ToJson(JsonInt64{object.cryptocurrency_amount_}));
  jo("star_count", object.star_count_);
  jo("transaction_id", object.transaction_id_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageGiftedTon &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageGiftedTon");
  jo("gifter_user_id", object.gifter_user_id_);
  jo("receiver_user_id", object.receiver_user_id_);
  jo("ton_amount", object.ton_amount_);
  jo("transaction_id", object.transaction_id_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageGiveawayPrizeStars &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageGiveawayPrizeStars");
  jo("star_count", object.star_count_);
  jo("transaction_id", object.transaction_id_);
  jo("boosted_chat_id", object.boosted_chat_id_);
  jo("giveaway_message_id", object.giveaway_message_id_);
  jo("is_unclaimed", JsonBool{object.is_unclaimed_});
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageGift");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  if (object.receiver_id_) {
    jo("receiver_id", ToJson(*object.receiver_id_));
  }
  jo("received_gift_id", object.received_gift_id_);
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("unique_gift_number", object.unique_gift_number_);
  jo("sell_star_count", object.sell_star_count_);
  jo("prepaid_upgrade_star_count", object.prepaid_upgrade_star_count_);
  jo("is_upgrade_separate", JsonBool{object.is_upgrade_separate_});
  jo("is_from_auction", JsonBool{object.is_from_auction_});
  jo("is_private", JsonBool{object.is_private_});
  jo("is_saved", JsonBool{object.is_saved_});
  jo("is_prepaid_upgrade", JsonBool{object.is_prepaid_upgrade_});
  jo("can_be_upgraded", JsonBool{object.can_be_upgraded_});
  jo("was_converted", JsonBool{object.was_converted_});
  jo("was_upgraded", JsonBool{object.was_upgraded_});
  jo("was_refunded", JsonBool{object.was_refunded_});
  jo("upgraded_received_gift_id", object.upgraded_received_gift_id_);
  jo("prepaid_upgrade_hash", object.prepaid_upgrade_hash_);
}

void to_json(JsonValueScope &jv, const td_api::messageUpgradedGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageUpgradedGift");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  if (object.receiver_id_) {
    jo("receiver_id", ToJson(*object.receiver_id_));
  }
  if (object.origin_) {
    jo("origin", ToJson(*object.origin_));
  }
  jo("received_gift_id", object.received_gift_id_);
  jo("is_saved", JsonBool{object.is_saved_});
  jo("can_be_transferred", JsonBool{object.can_be_transferred_});
  jo("was_transferred", JsonBool{object.was_transferred_});
  jo("transfer_star_count", object.transfer_star_count_);
  jo("drop_original_details_star_count", object.drop_original_details_star_count_);
  jo("next_transfer_date", object.next_transfer_date_);
  jo("next_resale_date", object.next_resale_date_);
  jo("export_date", object.export_date_);
  jo("craft_date", object.craft_date_);
}

void to_json(JsonValueScope &jv, const td_api::messageRefundedUpgradedGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageRefundedUpgradedGift");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  if (object.receiver_id_) {
    jo("receiver_id", ToJson(*object.receiver_id_));
  }
  if (object.origin_) {
    jo("origin", ToJson(*object.origin_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageUpgradedGiftPurchaseOffer &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageUpgradedGiftPurchaseOffer");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  if (object.state_) {
    jo("state", ToJson(*object.state_));
  }
  if (object.price_) {
    jo("price", ToJson(*object.price_));
  }
  jo("expiration_date", object.expiration_date_);
}

void to_json(JsonValueScope &jv, const td_api::messageUpgradedGiftPurchaseOfferRejected &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageUpgradedGiftPurchaseOfferRejected");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  if (object.price_) {
    jo("price", ToJson(*object.price_));
  }
  jo("offer_message_id", object.offer_message_id_);
  jo("was_expired", JsonBool{object.was_expired_});
}

void to_json(JsonValueScope &jv, const td_api::messagePaidMessagesRefunded &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePaidMessagesRefunded");
  jo("message_count", object.message_count_);
  jo("star_count", object.star_count_);
}

void to_json(JsonValueScope &jv, const td_api::messagePaidMessagePriceChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePaidMessagePriceChanged");
  jo("paid_message_star_count", object.paid_message_star_count_);
}

void to_json(JsonValueScope &jv, const td_api::messageDirectMessagePriceChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageDirectMessagePriceChanged");
  jo("is_enabled", JsonBool{object.is_enabled_});
  jo("paid_message_star_count", object.paid_message_star_count_);
}

void to_json(JsonValueScope &jv, const td_api::messageChecklistTasksDone &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChecklistTasksDone");
  jo("checklist_message_id", object.checklist_message_id_);
  jo("marked_as_done_task_ids", ToJson(object.marked_as_done_task_ids_));
  jo("marked_as_not_done_task_ids", ToJson(object.marked_as_not_done_task_ids_));
}

void to_json(JsonValueScope &jv, const td_api::messageChecklistTasksAdded &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChecklistTasksAdded");
  jo("checklist_message_id", object.checklist_message_id_);
  jo("tasks", ToJson(object.tasks_));
}

void to_json(JsonValueScope &jv, const td_api::messageSuggestedPostApprovalFailed &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSuggestedPostApprovalFailed");
  jo("suggested_post_message_id", object.suggested_post_message_id_);
  if (object.price_) {
    jo("price", ToJson(*object.price_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageSuggestedPostApproved &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSuggestedPostApproved");
  jo("suggested_post_message_id", object.suggested_post_message_id_);
  if (object.price_) {
    jo("price", ToJson(*object.price_));
  }
  jo("send_date", object.send_date_);
}

void to_json(JsonValueScope &jv, const td_api::messageSuggestedPostDeclined &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSuggestedPostDeclined");
  jo("suggested_post_message_id", object.suggested_post_message_id_);
  jo("comment", object.comment_);
}

void to_json(JsonValueScope &jv, const td_api::messageSuggestedPostPaid &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSuggestedPostPaid");
  jo("suggested_post_message_id", object.suggested_post_message_id_);
  if (object.star_amount_) {
    jo("star_amount", ToJson(*object.star_amount_));
  }
  jo("ton_amount", object.ton_amount_);
}

void to_json(JsonValueScope &jv, const td_api::messageSuggestedPostRefunded &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSuggestedPostRefunded");
  jo("suggested_post_message_id", object.suggested_post_message_id_);
  if (object.reason_) {
    jo("reason", ToJson(*object.reason_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageContactRegistered &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageContactRegistered");
}

void to_json(JsonValueScope &jv, const td_api::messageUsersShared &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageUsersShared");
  jo("users", ToJson(object.users_));
  jo("button_id", object.button_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageChatShared &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageChatShared");
  if (object.chat_) {
    jo("chat", ToJson(*object.chat_));
  }
  jo("button_id", object.button_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageBotWriteAccessAllowed &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageBotWriteAccessAllowed");
  if (object.reason_) {
    jo("reason", ToJson(*object.reason_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageWebAppDataSent &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageWebAppDataSent");
  jo("button_text", object.button_text_);
}

void to_json(JsonValueScope &jv, const td_api::messageWebAppDataReceived &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageWebAppDataReceived");
  jo("button_text", object.button_text_);
  jo("data", object.data_);
}

void to_json(JsonValueScope &jv, const td_api::messagePassportDataSent &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePassportDataSent");
  jo("types", ToJson(object.types_));
}

void to_json(JsonValueScope &jv, const td_api::messagePassportDataReceived &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePassportDataReceived");
  jo("elements", ToJson(object.elements_));
  if (object.credentials_) {
    jo("credentials", ToJson(*object.credentials_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageProximityAlertTriggered &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageProximityAlertTriggered");
  if (object.traveler_id_) {
    jo("traveler_id", ToJson(*object.traveler_id_));
  }
  if (object.watcher_id_) {
    jo("watcher_id", ToJson(*object.watcher_id_));
  }
  jo("distance", object.distance_);
}

void to_json(JsonValueScope &jv, const td_api::messageUnsupported &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageUnsupported");
}

void to_json(JsonValueScope &jv, const td_api::messageLinkInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageLinkInfo");
  jo("is_public", JsonBool{object.is_public_});
  jo("chat_id", object.chat_id_);
  if (object.topic_id_) {
    jo("topic_id", ToJson(*object.topic_id_));
  }
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
  jo("media_timestamp", object.media_timestamp_);
  jo("checklist_task_id", object.checklist_task_id_);
  jo("poll_option_id", object.poll_option_id_);
  jo("for_album", JsonBool{object.for_album_});
}

void to_json(JsonValueScope &jv, const td_api::MessageReplyTo &object) {
  td_api::downcast_call(const_cast<td_api::MessageReplyTo &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::messageReplyToMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageReplyToMessage");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  if (object.quote_) {
    jo("quote", ToJson(*object.quote_));
  }
  jo("checklist_task_id", object.checklist_task_id_);
  jo("poll_option_id", object.poll_option_id_);
  if (object.origin_) {
    jo("origin", ToJson(*object.origin_));
  }
  jo("origin_send_date", object.origin_send_date_);
  if (object.content_) {
    jo("content", ToJson(*object.content_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageReplyToStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageReplyToStory");
  jo("story_poster_chat_id", object.story_poster_chat_id_);
  jo("story_id", object.story_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageViewer &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageViewer");
  jo("user_id", object.user_id_);
  jo("view_date", object.view_date_);
}

void to_json(JsonValueScope &jv, const td_api::notificationGroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationGroup");
  jo("id", object.id_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("chat_id", object.chat_id_);
  jo("total_count", object.total_count_);
  jo("notifications", ToJson(object.notifications_));
}

void to_json(JsonValueScope &jv, const td_api::orderInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "orderInfo");
  jo("name", object.name_);
  jo("phone_number", object.phone_number_);
  jo("email_address", object.email_address_);
  if (object.shipping_address_) {
    jo("shipping_address", ToJson(*object.shipping_address_));
  }
}

void to_json(JsonValueScope &jv, const td_api::PaidMedia &object) {
  td_api::downcast_call(const_cast<td_api::PaidMedia &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::paidMediaPreview &object) {
  auto jo = jv.enter_object();
  jo("@type", "paidMediaPreview");
  jo("width", object.width_);
  jo("height", object.height_);
  jo("duration", object.duration_);
  if (object.minithumbnail_) {
    jo("minithumbnail", ToJson(*object.minithumbnail_));
  }
}

void to_json(JsonValueScope &jv, const td_api::paidMediaPhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "paidMediaPhoto");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
}

void to_json(JsonValueScope &jv, const td_api::paidMediaVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "paidMediaVideo");
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
  if (object.cover_) {
    jo("cover", ToJson(*object.cover_));
  }
  jo("start_timestamp", object.start_timestamp_);
}

void to_json(JsonValueScope &jv, const td_api::paidMediaUnsupported &object) {
  auto jo = jv.enter_object();
  jo("@type", "paidMediaUnsupported");
}

void to_json(JsonValueScope &jv, const td_api::PassportElementType &object) {
  td_api::downcast_call(const_cast<td_api::PassportElementType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypePersonalDetails &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypePersonalDetails");
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypePassport &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypePassport");
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypeDriverLicense &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypeDriverLicense");
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypeIdentityCard &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypeIdentityCard");
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypeInternalPassport &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypeInternalPassport");
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypeAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypeAddress");
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypeUtilityBill &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypeUtilityBill");
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypeBankStatement &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypeBankStatement");
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypeRentalAgreement &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypeRentalAgreement");
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypePassportRegistration &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypePassportRegistration");
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypeTemporaryRegistration &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypeTemporaryRegistration");
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypePhoneNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypePhoneNumber");
}

void to_json(JsonValueScope &jv, const td_api::passportElementTypeEmailAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTypeEmailAddress");
}

void to_json(JsonValueScope &jv, const td_api::PaymentProvider &object) {
  td_api::downcast_call(const_cast<td_api::PaymentProvider &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::paymentProviderSmartGlocal &object) {
  auto jo = jv.enter_object();
  jo("@type", "paymentProviderSmartGlocal");
  jo("public_token", object.public_token_);
  jo("tokenize_url", object.tokenize_url_);
}

void to_json(JsonValueScope &jv, const td_api::paymentProviderStripe &object) {
  auto jo = jv.enter_object();
  jo("@type", "paymentProviderStripe");
  jo("publishable_key", object.publishable_key_);
  jo("need_country", JsonBool{object.need_country_});
  jo("need_postal_code", JsonBool{object.need_postal_code_});
  jo("need_cardholder_name", JsonBool{object.need_cardholder_name_});
}

void to_json(JsonValueScope &jv, const td_api::paymentProviderOther &object) {
  auto jo = jv.enter_object();
  jo("@type", "paymentProviderOther");
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::point &object) {
  auto jo = jv.enter_object();
  jo("@type", "point");
  jo("x", object.x_);
  jo("y", object.y_);
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatures &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatures");
  jo("features", ToJson(object.features_));
  jo("limits", ToJson(object.limits_));
  if (object.payment_link_) {
    jo("payment_link", ToJson(*object.payment_link_));
  }
}

void to_json(JsonValueScope &jv, const td_api::premiumState &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumState");
  if (object.state_) {
    jo("state", ToJson(*object.state_));
  }
  jo("payment_options", ToJson(object.payment_options_));
  jo("animations", ToJson(object.animations_));
  jo("business_animations", ToJson(object.business_animations_));
}

void to_json(JsonValueScope &jv, const td_api::ProfileTab &object) {
  td_api::downcast_call(const_cast<td_api::ProfileTab &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::profileTabPosts &object) {
  auto jo = jv.enter_object();
  jo("@type", "profileTabPosts");
}

void to_json(JsonValueScope &jv, const td_api::profileTabGifts &object) {
  auto jo = jv.enter_object();
  jo("@type", "profileTabGifts");
}

void to_json(JsonValueScope &jv, const td_api::profileTabMedia &object) {
  auto jo = jv.enter_object();
  jo("@type", "profileTabMedia");
}

void to_json(JsonValueScope &jv, const td_api::profileTabFiles &object) {
  auto jo = jv.enter_object();
  jo("@type", "profileTabFiles");
}

void to_json(JsonValueScope &jv, const td_api::profileTabLinks &object) {
  auto jo = jv.enter_object();
  jo("@type", "profileTabLinks");
}

void to_json(JsonValueScope &jv, const td_api::profileTabMusic &object) {
  auto jo = jv.enter_object();
  jo("@type", "profileTabMusic");
}

void to_json(JsonValueScope &jv, const td_api::profileTabVoice &object) {
  auto jo = jv.enter_object();
  jo("@type", "profileTabVoice");
}

void to_json(JsonValueScope &jv, const td_api::profileTabGifs &object) {
  auto jo = jv.enter_object();
  jo("@type", "profileTabGifs");
}

void to_json(JsonValueScope &jv, const td_api::quickReplyMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "quickReplyMessages");
  jo("messages", ToJson(object.messages_));
}

void to_json(JsonValueScope &jv, const td_api::recommendedChatFolder &object) {
  auto jo = jv.enter_object();
  jo("@type", "recommendedChatFolder");
  if (object.folder_) {
    jo("folder", ToJson(*object.folder_));
  }
  jo("description", object.description_);
}

void to_json(JsonValueScope &jv, const td_api::ResetPasswordResult &object) {
  td_api::downcast_call(const_cast<td_api::ResetPasswordResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::resetPasswordResultOk &object) {
  auto jo = jv.enter_object();
  jo("@type", "resetPasswordResultOk");
}

void to_json(JsonValueScope &jv, const td_api::resetPasswordResultPending &object) {
  auto jo = jv.enter_object();
  jo("@type", "resetPasswordResultPending");
  jo("pending_reset_date", object.pending_reset_date_);
}

void to_json(JsonValueScope &jv, const td_api::resetPasswordResultDeclined &object) {
  auto jo = jv.enter_object();
  jo("@type", "resetPasswordResultDeclined");
  jo("retry_date", object.retry_date_);
}

void to_json(JsonValueScope &jv, const td_api::SavedMessagesTopicType &object) {
  td_api::downcast_call(const_cast<td_api::SavedMessagesTopicType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::savedMessagesTopicTypeMyNotes &object) {
  auto jo = jv.enter_object();
  jo("@type", "savedMessagesTopicTypeMyNotes");
}

void to_json(JsonValueScope &jv, const td_api::savedMessagesTopicTypeAuthorHidden &object) {
  auto jo = jv.enter_object();
  jo("@type", "savedMessagesTopicTypeAuthorHidden");
}

void to_json(JsonValueScope &jv, const td_api::savedMessagesTopicTypeSavedFromChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "savedMessagesTopicTypeSavedFromChat");
  jo("chat_id", object.chat_id_);
}

void to_json(JsonValueScope &jv, const td_api::SessionType &object) {
  td_api::downcast_call(const_cast<td_api::SessionType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeAndroid &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeAndroid");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeApple &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeApple");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeBrave &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeBrave");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeChrome &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeChrome");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeEdge &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeEdge");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeFirefox &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeFirefox");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeIpad &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeIpad");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeIphone &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeIphone");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeLinux &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeLinux");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeMac &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeMac");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeOpera &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeOpera");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeSafari &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeSafari");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeUbuntu &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeUbuntu");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeUnknown &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeUnknown");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeVivaldi &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeVivaldi");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeWindows &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeWindows");
}

void to_json(JsonValueScope &jv, const td_api::sessionTypeXbox &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessionTypeXbox");
}

void to_json(JsonValueScope &jv, const td_api::sponsoredMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "sponsoredMessage");
  jo("message_id", object.message_id_);
  jo("is_recommended", JsonBool{object.is_recommended_});
  jo("can_be_reported", JsonBool{object.can_be_reported_});
  if (object.content_) {
    jo("content", ToJson(*object.content_));
  }
  if (object.sponsor_) {
    jo("sponsor", ToJson(*object.sponsor_));
  }
  jo("title", object.title_);
  jo("button_text", object.button_text_);
  jo("accent_color_id", object.accent_color_id_);
  jo("background_custom_emoji_id", ToJson(JsonInt64{object.background_custom_emoji_id_}));
  jo("additional_info", object.additional_info_);
}

void to_json(JsonValueScope &jv, const td_api::starPaymentOptions &object) {
  auto jo = jv.enter_object();
  jo("@type", "starPaymentOptions");
  jo("options", ToJson(object.options_));
}

void to_json(JsonValueScope &jv, const td_api::starTransactions &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransactions");
  if (object.star_amount_) {
    jo("star_amount", ToJson(*object.star_amount_));
  }
  jo("transactions", ToJson(object.transactions_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::stickerSets &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickerSets");
  jo("total_count", object.total_count_);
  jo("sets", ToJson(object.sets_));
}

void to_json(JsonValueScope &jv, const td_api::storyAlbum &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyAlbum");
  jo("id", object.id_);
  jo("name", object.name_);
  if (object.photo_icon_) {
    jo("photo_icon", ToJson(*object.photo_icon_));
  }
  if (object.video_icon_) {
    jo("video_icon", ToJson(*object.video_icon_));
  }
}

void to_json(JsonValueScope &jv, const td_api::storyInteractionInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyInteractionInfo");
  jo("view_count", object.view_count_);
  jo("forward_count", object.forward_count_);
  jo("reaction_count", object.reaction_count_);
  jo("recent_viewer_user_ids", ToJson(object.recent_viewer_user_ids_));
}

void to_json(JsonValueScope &jv, const td_api::SuggestedAction &object) {
  td_api::downcast_call(const_cast<td_api::SuggestedAction &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionEnableArchiveAndMuteNewChats &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionEnableArchiveAndMuteNewChats");
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionCheckPassword &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionCheckPassword");
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionCheckPhoneNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionCheckPhoneNumber");
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionViewChecksHint &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionViewChecksHint");
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionConvertToBroadcastGroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionConvertToBroadcastGroup");
  jo("supergroup_id", object.supergroup_id_);
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionSetPassword &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionSetPassword");
  jo("authorization_delay", object.authorization_delay_);
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionUpgradePremium &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionUpgradePremium");
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionRestorePremium &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionRestorePremium");
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionSubscribeToAnnualPremium &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionSubscribeToAnnualPremium");
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionGiftPremiumForChristmas &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionGiftPremiumForChristmas");
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionSetBirthdate &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionSetBirthdate");
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionSetProfilePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionSetProfilePhoto");
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionExtendPremium &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionExtendPremium");
  jo("manage_premium_subscription_url", object.manage_premium_subscription_url_);
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionExtendStarSubscriptions &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionExtendStarSubscriptions");
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionCustom &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionCustom");
  jo("name", object.name_);
  if (object.title_) {
    jo("title", ToJson(*object.title_));
  }
  if (object.description_) {
    jo("description", ToJson(*object.description_));
  }
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionSetLoginEmailAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionSetLoginEmailAddress");
  jo("can_be_hidden", JsonBool{object.can_be_hidden_});
}

void to_json(JsonValueScope &jv, const td_api::suggestedActionAddLoginPasskey &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedActionAddLoginPasskey");
}

void to_json(JsonValueScope &jv, const td_api::tMeUrls &object) {
  auto jo = jv.enter_object();
  jo("@type", "tMeUrls");
  jo("urls", ToJson(object.urls_));
}

void to_json(JsonValueScope &jv, const td_api::testVectorIntObject &object) {
  auto jo = jv.enter_object();
  jo("@type", "testVectorIntObject");
  jo("value", ToJson(object.value_));
}

void to_json(JsonValueScope &jv, const td_api::themeSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "themeSettings");
  if (object.base_theme_) {
    jo("base_theme", ToJson(*object.base_theme_));
  }
  jo("accent_color", object.accent_color_);
  if (object.background_) {
    jo("background", ToJson(*object.background_));
  }
  if (object.outgoing_message_fill_) {
    jo("outgoing_message_fill", ToJson(*object.outgoing_message_fill_));
  }
  jo("animate_outgoing_message_fill", JsonBool{object.animate_outgoing_message_fill_});
  jo("outgoing_message_accent_color", object.outgoing_message_accent_color_);
}

void to_json(JsonValueScope &jv, const td_api::tonTransactions &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonTransactions");
  jo("ton_amount", object.ton_amount_);
  jo("transactions", ToJson(object.transactions_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftBackdrop &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftBackdrop");
  jo("id", object.id_);
  jo("name", object.name_);
  if (object.colors_) {
    jo("colors", ToJson(*object.colors_));
  }
  if (object.rarity_) {
    jo("rarity", ToJson(*object.rarity_));
  }
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftSymbolCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftSymbolCount");
  if (object.symbol_) {
    jo("symbol", ToJson(*object.symbol_));
  }
  jo("total_count", object.total_count_);
}

void to_json(JsonValueScope &jv, const td_api::userRating &object) {
  auto jo = jv.enter_object();
  jo("@type", "userRating");
  jo("level", object.level_);
  jo("is_maximum_level_reached", JsonBool{object.is_maximum_level_reached_});
  jo("rating", object.rating_);
  jo("current_level_rating", object.current_level_rating_);
  jo("next_level_rating", object.next_level_rating_);
}

void to_json(JsonValueScope &jv, const td_api::verificationStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "verificationStatus");
  jo("is_verified", JsonBool{object.is_verified_});
  jo("is_scam", JsonBool{object.is_scam_});
  jo("is_fake", JsonBool{object.is_fake_});
  jo("bot_verification_icon_custom_emoji_id", ToJson(JsonInt64{object.bot_verification_icon_custom_emoji_id_}));
}

void to_json(JsonValueScope &jv, const td_api::webAppInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "webAppInfo");
  jo("launch_id", ToJson(JsonInt64{object.launch_id_}));
  jo("url", object.url_);
}

}  // namespace td_api
}  // namespace td
