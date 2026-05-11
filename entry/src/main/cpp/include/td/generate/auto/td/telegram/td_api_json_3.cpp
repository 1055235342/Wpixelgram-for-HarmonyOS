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
Result<int32> tl_constructor_from_string(td_api::AffiliateType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"affiliateTypeCurrentUser", 1453785589},
    {"affiliateTypeBot", -1032587200},
    {"affiliateTypeChannel", -683939735}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::CallProblem *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"callProblemEcho", 801116548},
    {"callProblemNoise", 1053065359},
    {"callProblemInterruptions", 1119493218},
    {"callProblemDistortedSpeech", 379960581},
    {"callProblemSilentLocal", 253652790},
    {"callProblemSilentRemote", 573634714},
    {"callProblemDropped", -1207311487},
    {"callProblemDistortedVideo", 385245706},
    {"callProblemPixelatedVideo", 2115315411}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::DateTimeFormattingType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"dateTimeFormattingTypeRelative", -648483424},
    {"dateTimeFormattingTypeAbsolute", 47463317}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::GiftResalePrice *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"giftResalePriceStar", 1184402054},
    {"giftResalePriceTon", -415435950}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputCredentials *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputCredentialsSaved", -2034385364},
    {"inputCredentialsNew", -829689558},
    {"inputCredentialsApplePay", -1246570799},
    {"inputCredentialsGooglePay", 844384100}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputPassportElementErrorSource *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputPassportElementErrorSourceUnspecified", 267230319},
    {"inputPassportElementErrorSourceDataField", -426795002},
    {"inputPassportElementErrorSourceFrontSide", 588023741},
    {"inputPassportElementErrorSourceReverseSide", 413072891},
    {"inputPassportElementErrorSourceSelfie", -773575528},
    {"inputPassportElementErrorSourceTranslationFile", 505842299},
    {"inputPassportElementErrorSourceTranslationFiles", -527254048},
    {"inputPassportElementErrorSourceFile", -298492469},
    {"inputPassportElementErrorSourceFiles", -2008541640}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::LogStream *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"logStreamDefault", 1390581436},
    {"logStreamFile", 1532136933},
    {"logStreamEmpty", -499912244}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::NotificationSettingsScope *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"notificationSettingsScopePrivateChats", 937446759},
    {"notificationSettingsScopeGroupChats", 1212142067},
    {"notificationSettingsScopeChannelChats", 548013448}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ProfileTab *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"profileTabPosts", -1181952362},
    {"profileTabGifts", 1296815210},
    {"profileTabMedia", 1925597525},
    {"profileTabFiles", -1422681088},
    {"profileTabLinks", -748329831},
    {"profileTabMusic", -1624780178},
    {"profileTabVoice", -461960914},
    {"profileTabGifs", -1564412267}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::SearchMessagesFilter *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"searchMessagesFilterPinned", 371805512}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::SuggestedAction *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"suggestedActionAddLoginPasskey", 1186248690}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::UpgradedGiftAttributeId *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"upgradedGiftAttributeIdModel", 1053287307},
    {"upgradedGiftAttributeIdSymbol", 1188205608},
    {"upgradedGiftAttributeIdBackdrop", 1461997935}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Status from_json(td_api::affiliateProgramSortOrderCreationDate &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::autosaveSettingsScopeChannelChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::birthdate &to, JsonObject &from) {
  TRY_STATUS(from_json(to.day_, from.extract_field("day")));
  TRY_STATUS(from_json(to.month_, from.extract_field("month")));
  TRY_STATUS(from_json(to.year_, from.extract_field("year")));
  return Status::OK();
}

Status from_json(td_api::botCommandScopeChatAdministrators &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::businessFeatureLocation &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessFeatureChatFolderTags &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::buttonStyleDanger &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::callProblemDistortedVideo &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatActionRecordingVoiceNote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatActionUploadingVideoNote &to, JsonObject &from) {
  TRY_STATUS(from_json(to.progress_, from.extract_field("progress")));
  return Status::OK();
}

Status from_json(td_api::chatFolderName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.animate_custom_emoji_, from.extract_field("animate_custom_emoji")));
  return Status::OK();
}

Status from_json(td_api::chatMemberStatusMember &to, JsonObject &from) {
  TRY_STATUS(from_json(to.member_until_date_, from.extract_field("member_until_date")));
  return Status::OK();
}

Status from_json(td_api::chatMembersFilterBanned &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::contact &to, JsonObject &from) {
  TRY_STATUS(from_json(to.phone_number_, from.extract_field("phone_number")));
  TRY_STATUS(from_json(to.first_name_, from.extract_field("first_name")));
  TRY_STATUS(from_json(to.last_name_, from.extract_field("last_name")));
  TRY_STATUS(from_json(to.vcard_, from.extract_field("vcard")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::deviceTokenApplePushVoIP &to, JsonObject &from) {
  TRY_STATUS(from_json(to.device_token_, from.extract_field("device_token")));
  TRY_STATUS(from_json(to.is_app_sandbox_, from.extract_field("is_app_sandbox")));
  TRY_STATUS(from_json(to.encrypt_, from.extract_field("encrypt")));
  return Status::OK();
}

Status from_json(td_api::deviceTokenHuaweiPush &to, JsonObject &from) {
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  TRY_STATUS(from_json(to.encrypt_, from.extract_field("encrypt")));
  return Status::OK();
}

Status from_json(td_api::emojiStatus &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  TRY_STATUS(from_json(to.expiration_date_, from.extract_field("expiration_date")));
  return Status::OK();
}

Status from_json(td_api::fileTypeNotificationSound &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeSelfDestructingVideo &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeVoiceNote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::giftResalePriceStar &to, JsonObject &from) {
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::groupCallVideoQualityFull &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::inlineKeyboardButtonTypeSwitchInline &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.target_chat_, from.extract_field("target_chat")));
  return Status::OK();
}

Status from_json(td_api::inputBackgroundPrevious &to, JsonObject &from) {
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::inputChatThemeEmoji &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::inputFileRemote &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  return Status::OK();
}

Status from_json(td_api::inputInlineQueryResultContact &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.contact_, from.extract_field("contact")));
  TRY_STATUS(from_json(to.thumbnail_url_, from.extract_field("thumbnail_url")));
  TRY_STATUS(from_json(to.thumbnail_width_, from.extract_field("thumbnail_width")));
  TRY_STATUS(from_json(to.thumbnail_height_, from.extract_field("thumbnail_height")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::inputInvoiceMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::inputMessageSticker &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  TRY_STATUS(from_json(to.thumbnail_, from.extract_field("thumbnail")));
  TRY_STATUS(from_json(to.width_, from.extract_field("width")));
  TRY_STATUS(from_json(to.height_, from.extract_field("height")));
  TRY_STATUS(from_json(to.emoji_, from.extract_field("emoji")));
  return Status::OK();
}

Status from_json(td_api::inputMessageInvoice &to, JsonObject &from) {
  TRY_STATUS(from_json(to.invoice_, from.extract_field("invoice")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.description_, from.extract_field("description")));
  TRY_STATUS(from_json(to.photo_url_, from.extract_field("photo_url")));
  TRY_STATUS(from_json(to.photo_size_, from.extract_field("photo_size")));
  TRY_STATUS(from_json(to.photo_width_, from.extract_field("photo_width")));
  TRY_STATUS(from_json(to.photo_height_, from.extract_field("photo_height")));
  TRY_STATUS(from_json_bytes(to.payload_, from.extract_field("payload")));
  TRY_STATUS(from_json(to.provider_token_, from.extract_field("provider_token")));
  TRY_STATUS(from_json(to.provider_data_, from.extract_field("provider_data")));
  TRY_STATUS(from_json(to.start_parameter_, from.extract_field("start_parameter")));
  TRY_STATUS(from_json(to.paid_media_, from.extract_field("paid_media")));
  TRY_STATUS(from_json(to.paid_media_caption_, from.extract_field("paid_media_caption")));
  return Status::OK();
}

Status from_json(td_api::inputPaidMedia &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  TRY_STATUS(from_json(to.media_, from.extract_field("media")));
  TRY_STATUS(from_json(to.thumbnail_, from.extract_field("thumbnail")));
  TRY_STATUS(from_json(to.added_sticker_file_ids_, from.extract_field("added_sticker_file_ids")));
  TRY_STATUS(from_json(to.width_, from.extract_field("width")));
  TRY_STATUS(from_json(to.height_, from.extract_field("height")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementUtilityBill &to, JsonObject &from) {
  TRY_STATUS(from_json(to.utility_bill_, from.extract_field("utility_bill")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementErrorSourceDataField &to, JsonObject &from) {
  TRY_STATUS(from_json(to.field_name_, from.extract_field("field_name")));
  TRY_STATUS(from_json_bytes(to.data_hash_, from.extract_field("data_hash")));
  return Status::OK();
}

Status from_json(td_api::inputPollOption &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::inputStoryAreaTypeMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::inputThumbnail &to, JsonObject &from) {
  TRY_STATUS(from_json(to.thumbnail_, from.extract_field("thumbnail")));
  TRY_STATUS(from_json(to.width_, from.extract_field("width")));
  TRY_STATUS(from_json(to.height_, from.extract_field("height")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeChatAffiliateProgram &to, JsonObject &from) {
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  TRY_STATUS(from_json(to.referrer_, from.extract_field("referrer")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeGiftCollection &to, JsonObject &from) {
  TRY_STATUS(from_json(to.gift_owner_username_, from.extract_field("gift_owner_username")));
  TRY_STATUS(from_json(to.collection_id_, from.extract_field("collection_id")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeMyProfilePage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.section_, from.extract_field("section")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypePremiumGiftCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.code_, from.extract_field("code")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.section_, from.extract_field("section")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeUserToken &to, JsonObject &from) {
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  return Status::OK();
}

Status from_json(td_api::jsonValueArray &to, JsonObject &from) {
  TRY_STATUS(from_json(to.values_, from.extract_field("values")));
  return Status::OK();
}

Status from_json(td_api::keyboardButtonTypeRequestUsers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.restrict_user_is_bot_, from.extract_field("restrict_user_is_bot")));
  TRY_STATUS(from_json(to.user_is_bot_, from.extract_field("user_is_bot")));
  TRY_STATUS(from_json(to.restrict_user_is_premium_, from.extract_field("restrict_user_is_premium")));
  TRY_STATUS(from_json(to.user_is_premium_, from.extract_field("user_is_premium")));
  TRY_STATUS(from_json(to.max_quantity_, from.extract_field("max_quantity")));
  TRY_STATUS(from_json(to.request_name_, from.extract_field("request_name")));
  TRY_STATUS(from_json(to.request_username_, from.extract_field("request_username")));
  TRY_STATUS(from_json(to.request_photo_, from.extract_field("request_photo")));
  return Status::OK();
}

Status from_json(td_api::languagePackStringValueDeleted &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::maskPointMouth &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageSelfDestructTypeImmediately &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageSourceChatList &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageTopicSavedMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.saved_messages_topic_id_, from.extract_field("saved_messages_topic_id")));
  return Status::OK();
}

Status from_json(td_api::notificationSettingsScopePrivateChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::paidReactionTypeAnonymous &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::passportElementTypeBankStatement &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::phoneNumberCodeTypeVerify &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureCustomEmoji &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureChatBoost &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeaturePaidMessages &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeChatFolderChosenChatCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeMonthlyPostedStoryCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumSourceLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.referrer_, from.extract_field("referrer")));
  return Status::OK();
}

Status from_json(td_api::profileTabPosts &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::proxyTypeSocks5 &to, JsonObject &from) {
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::reactionTypeEmoji &to, JsonObject &from) {
  TRY_STATUS(from_json(to.emoji_, from.extract_field("emoji")));
  return Status::OK();
}

Status from_json(td_api::reportReasonViolence &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::resendCodeReasonUserRequest &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterAudio &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterVideoNote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::settingsSectionAskQuestion &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::settingsSectionLanguage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::settingsSectionSearch &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::stickerTypeCustomEmoji &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::storeTransactionGooglePlay &to, JsonObject &from) {
  TRY_STATUS(from_json(to.package_name_, from.extract_field("package_name")));
  TRY_STATUS(from_json(to.store_product_id_, from.extract_field("store_product_id")));
  TRY_STATUS(from_json(to.purchase_token_, from.extract_field("purchase_token")));
  return Status::OK();
}

Status from_json(td_api::storyPrivacySettingsEveryone &to, JsonObject &from) {
  TRY_STATUS(from_json(to.except_user_ids_, from.extract_field("except_user_ids")));
  return Status::OK();
}

Status from_json(td_api::suggestedActionSetPassword &to, JsonObject &from) {
  TRY_STATUS(from_json(to.authorization_delay_, from.extract_field("authorization_delay")));
  return Status::OK();
}

Status from_json(td_api::suggestedActionCustom &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.description_, from.extract_field("description")));
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::supergroupMembersFilterRestricted &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  return Status::OK();
}

Status from_json(td_api::telegramPaymentPurposePremiumGiftCodes &to, JsonObject &from) {
  TRY_STATUS(from_json(to.boosted_chat_id_, from.extract_field("boosted_chat_id")));
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  TRY_STATUS(from_json(to.user_ids_, from.extract_field("user_ids")));
  TRY_STATUS(from_json(to.month_count_, from.extract_field("month_count")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::textEntityTypeMention &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypeItalic &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypeTextUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::topChatCategoryBots &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::upgradedGiftAttributeIdModel &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_id_, from.extract_field("sticker_id")));
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingShowBirthdate &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingRuleAllowAll &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingRuleRestrictUsers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_ids_, from.extract_field("user_ids")));
  return Status::OK();
}

Status from_json(td_api::acceptOauthRequest &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  TRY_STATUS(from_json(to.match_code_, from.extract_field("match_code")));
  TRY_STATUS(from_json(to.allow_write_access_, from.extract_field("allow_write_access")));
  TRY_STATUS(from_json(to.allow_phone_number_access_, from.extract_field("allow_phone_number_access")));
  return Status::OK();
}

Status from_json(td_api::addContact &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.contact_, from.extract_field("contact")));
  TRY_STATUS(from_json(to.share_phone_number_, from.extract_field("share_phone_number")));
  return Status::OK();
}

Status from_json(td_api::addNetworkStatistics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.entry_, from.extract_field("entry")));
  return Status::OK();
}

Status from_json(td_api::addQuickReplyShortcutMessageAlbum &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shortcut_name_, from.extract_field("shortcut_name")));
  TRY_STATUS(from_json(to.reply_to_message_id_, from.extract_field("reply_to_message_id")));
  TRY_STATUS(from_json(to.input_message_contents_, from.extract_field("input_message_contents")));
  return Status::OK();
}

Status from_json(td_api::answerCallbackQuery &to, JsonObject &from) {
  TRY_STATUS(from_json(to.callback_query_id_, from.extract_field("callback_query_id")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.show_alert_, from.extract_field("show_alert")));
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  TRY_STATUS(from_json(to.cache_time_, from.extract_field("cache_time")));
  return Status::OK();
}

Status from_json(td_api::banChatMember &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.member_id_, from.extract_field("member_id")));
  TRY_STATUS(from_json(to.banned_until_date_, from.extract_field("banned_until_date")));
  TRY_STATUS(from_json(to.revoke_messages_, from.extract_field("revoke_messages")));
  return Status::OK();
}

Status from_json(td_api::canSendMessageToUser &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.only_local_, from.extract_field("only_local")));
  return Status::OK();
}

Status from_json(td_api::checkAuthenticationCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.code_, from.extract_field("code")));
  return Status::OK();
}

Status from_json(td_api::checkChatUsername &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  return Status::OK();
}

Status from_json(td_api::checkRecoveryEmailAddressCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.code_, from.extract_field("code")));
  return Status::OK();
}

Status from_json(td_api::clearRecentStickers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_attached_, from.extract_field("is_attached")));
  return Status::OK();
}

Status from_json(td_api::closeGiftAuction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.gift_id_, from.extract_field("gift_id")));
  return Status::OK();
}

Status from_json(td_api::connectAffiliateProgram &to, JsonObject &from) {
  TRY_STATUS(from_json(to.affiliate_, from.extract_field("affiliate")));
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  return Status::OK();
}

Status from_json(td_api::createChatSubscriptionInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.subscription_pricing_, from.extract_field("subscription_pricing")));
  return Status::OK();
}

Status from_json(td_api::createPrivateChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.force_, from.extract_field("force")));
  return Status::OK();
}

Status from_json(td_api::decryptGroupCallData &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.participant_id_, from.extract_field("participant_id")));
  TRY_STATUS(from_json(to.data_channel_, from.extract_field("data_channel")));
  TRY_STATUS(from_json_bytes(to.data_, from.extract_field("data")));
  return Status::OK();
}

Status from_json(td_api::deleteChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::deleteDefaultBackground &to, JsonObject &from) {
  TRY_STATUS(from_json(to.for_dark_theme_, from.extract_field("for_dark_theme")));
  return Status::OK();
}

Status from_json(td_api::deleteMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_ids_, from.extract_field("message_ids")));
  TRY_STATUS(from_json(to.revoke_, from.extract_field("revoke")));
  return Status::OK();
}

Status from_json(td_api::deleteSavedMessagesTopicMessagesByDate &to, JsonObject &from) {
  TRY_STATUS(from_json(to.saved_messages_topic_id_, from.extract_field("saved_messages_topic_id")));
  TRY_STATUS(from_json(to.min_date_, from.extract_field("min_date")));
  TRY_STATUS(from_json(to.max_date_, from.extract_field("max_date")));
  return Status::OK();
}

Status from_json(td_api::disconnectAffiliateProgram &to, JsonObject &from) {
  TRY_STATUS(from_json(to.affiliate_, from.extract_field("affiliate")));
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::editBusinessMessageLiveLocation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  TRY_STATUS(from_json(to.live_period_, from.extract_field("live_period")));
  TRY_STATUS(from_json(to.heading_, from.extract_field("heading")));
  TRY_STATUS(from_json(to.proximity_alert_radius_, from.extract_field("proximity_alert_radius")));
  return Status::OK();
}

Status from_json(td_api::editCustomLanguagePackInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.info_, from.extract_field("info")));
  return Status::OK();
}

Status from_json(td_api::editMessageLiveLocation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  TRY_STATUS(from_json(to.live_period_, from.extract_field("live_period")));
  TRY_STATUS(from_json(to.heading_, from.extract_field("heading")));
  TRY_STATUS(from_json(to.proximity_alert_radius_, from.extract_field("proximity_alert_radius")));
  return Status::OK();
}

Status from_json(td_api::editStoryCover &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  TRY_STATUS(from_json(to.cover_frame_timestamp_, from.extract_field("cover_frame_timestamp")));
  return Status::OK();
}

Status from_json(td_api::forwardMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.from_chat_id_, from.extract_field("from_chat_id")));
  TRY_STATUS(from_json(to.message_ids_, from.extract_field("message_ids")));
  TRY_STATUS(from_json(to.options_, from.extract_field("options")));
  TRY_STATUS(from_json(to.send_copy_, from.extract_field("send_copy")));
  TRY_STATUS(from_json(to.remove_caption_, from.extract_field("remove_caption")));
  return Status::OK();
}

Status from_json(td_api::getArchivedStickerSets &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_type_, from.extract_field("sticker_type")));
  TRY_STATUS(from_json(to.offset_sticker_set_id_, from.extract_field("offset_sticker_set_id")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getBackgroundUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::getBotName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  return Status::OK();
}

Status from_json(td_api::getBusinessFeatures &to, JsonObject &from) {
  TRY_STATUS(from_json(to.source_, from.extract_field("source")));
  return Status::OK();
}

Status from_json(td_api::getChatBoostFeatures &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_channel_, from.extract_field("is_channel")));
  return Status::OK();
}

Status from_json(td_api::getChatFolderChatsToLeave &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_id_, from.extract_field("chat_folder_id")));
  return Status::OK();
}

Status from_json(td_api::getChatJoinRequests &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.offset_request_, from.extract_field("offset_request")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getChatPinnedMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getChatSponsoredMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getCommands &to, JsonObject &from) {
  TRY_STATUS(from_json(to.scope_, from.extract_field("scope")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  return Status::OK();
}

Status from_json(td_api::getCurrentState &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getDefaultEmojiStatuses &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getEmojiReaction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.emoji_, from.extract_field("emoji")));
  return Status::OK();
}

Status from_json(td_api::getForumTopic &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  return Status::OK();
}

Status from_json(td_api::getGiftCollections &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  return Status::OK();
}

Status from_json(td_api::getGroupCallStreams &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::getInternalLinkType &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_, from.extract_field("link")));
  return Status::OK();
}

Status from_json(td_api::getLiveStoryRtmpUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getLoginUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.button_id_, from.extract_field("button_id")));
  TRY_STATUS(from_json(to.allow_write_access_, from.extract_field("allow_write_access")));
  return Status::OK();
}

Status from_json(td_api::getMessageAuthor &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::getMessageProperties &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::getNewChatPrivacySettings &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getPassportElement &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::getPremiumFeatures &to, JsonObject &from) {
  TRY_STATUS(from_json(to.source_, from.extract_field("source")));
  return Status::OK();
}

Status from_json(td_api::getPreparedKeyboardButton &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.prepared_button_id_, from.extract_field("prepared_button_id")));
  return Status::OK();
}

Status from_json(td_api::getRecentStickers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_attached_, from.extract_field("is_attached")));
  return Status::OK();
}

Status from_json(td_api::getSavedMessagesTags &to, JsonObject &from) {
  TRY_STATUS(from_json(to.saved_messages_topic_id_, from.extract_field("saved_messages_topic_id")));
  return Status::OK();
}

Status from_json(td_api::getSecretChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.secret_chat_id_, from.extract_field("secret_chat_id")));
  return Status::OK();
}

Status from_json(td_api::getStarWithdrawalUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::getStorageStatisticsFast &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getSuggestedStickerSetName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  return Status::OK();
}

Status from_json(td_api::getTextEntities &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::getTrendingStickerSets &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_type_, from.extract_field("sticker_type")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getUserFullInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::getVideoMessageAdvertisements &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::importMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_file_, from.extract_field("message_file")));
  TRY_STATUS(from_json(to.attached_files_, from.extract_field("attached_files")));
  return Status::OK();
}

Status from_json(td_api::joinLiveStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.join_parameters_, from.extract_field("join_parameters")));
  return Status::OK();
}

Status from_json(td_api::loadGroupCallParticipants &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::openGiftAuction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.gift_id_, from.extract_field("gift_id")));
  return Status::OK();
}

Status from_json(td_api::pingProxy &to, JsonObject &from) {
  TRY_STATUS(from_json(to.proxy_, from.extract_field("proxy")));
  return Status::OK();
}

Status from_json(td_api::processPushNotification &to, JsonObject &from) {
  TRY_STATUS(from_json(to.payload_, from.extract_field("payload")));
  return Status::OK();
}

Status from_json(td_api::readBusinessMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::registerUser &to, JsonObject &from) {
  TRY_STATUS(from_json(to.first_name_, from.extract_field("first_name")));
  TRY_STATUS(from_json(to.last_name_, from.extract_field("last_name")));
  TRY_STATUS(from_json(to.disable_notification_, from.extract_field("disable_notification")));
  return Status::OK();
}

Status from_json(td_api::removeLoginPasskey &to, JsonObject &from) {
  TRY_STATUS(from_json(to.passkey_id_, from.extract_field("passkey_id")));
  return Status::OK();
}

Status from_json(td_api::removeRecentHashtag &to, JsonObject &from) {
  TRY_STATUS(from_json(to.hashtag_, from.extract_field("hashtag")));
  return Status::OK();
}

Status from_json(td_api::reorderActiveUsernames &to, JsonObject &from) {
  TRY_STATUS(from_json(to.usernames_, from.extract_field("usernames")));
  return Status::OK();
}

Status from_json(td_api::reorderStoryAlbums &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.story_album_ids_, from.extract_field("story_album_ids")));
  return Status::OK();
}

Status from_json(td_api::reportChatSponsoredMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json_bytes(to.option_id_, from.extract_field("option_id")));
  return Status::OK();
}

Status from_json(td_api::requestPasswordRecovery &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::resetAuthenticationEmailAddress &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::savePreparedKeyboardButton &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.button_, from.extract_field("button")));
  return Status::OK();
}

Status from_json(td_api::searchChatsOnServer &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchPublicChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  return Status::OK();
}

Status from_json(td_api::searchSavedMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.saved_messages_topic_id_, from.extract_field("saved_messages_topic_id")));
  TRY_STATUS(from_json(to.tag_, from.extract_field("tag")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.from_message_id_, from.extract_field("from_message_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::sellGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.received_gift_id_, from.extract_field("received_gift_id")));
  return Status::OK();
}

Status from_json(td_api::sendChatAction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.action_, from.extract_field("action")));
  return Status::OK();
}

Status from_json(td_api::sendMessageViewMetrics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.time_in_view_ms_, from.extract_field("time_in_view_ms")));
  TRY_STATUS(from_json(to.active_time_in_view_ms_, from.extract_field("active_time_in_view_ms")));
  TRY_STATUS(from_json(to.height_to_viewport_ratio_per_mille_, from.extract_field("height_to_viewport_ratio_per_mille")));
  TRY_STATUS(from_json(to.seen_range_ratio_per_mille_, from.extract_field("seen_range_ratio_per_mille")));
  return Status::OK();
}

Status from_json(td_api::sendWebAppData &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.button_text_, from.extract_field("button_text")));
  TRY_STATUS(from_json(to.data_, from.extract_field("data")));
  return Status::OK();
}

Status from_json(td_api::setAutoDownloadSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.settings_, from.extract_field("settings")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::setBusinessAccountBio &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.bio_, from.extract_field("bio")));
  return Status::OK();
}

Status from_json(td_api::setBusinessMessageIsPinned &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.is_pinned_, from.extract_field("is_pinned")));
  return Status::OK();
}

Status from_json(td_api::setChatDescription &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.description_, from.extract_field("description")));
  return Status::OK();
}

Status from_json(td_api::setChatMessageSender &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_sender_id_, from.extract_field("message_sender_id")));
  return Status::OK();
}

Status from_json(td_api::setChatTitle &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  return Status::OK();
}

Status from_json(td_api::setDefaultGroupAdministratorRights &to, JsonObject &from) {
  TRY_STATUS(from_json(to.default_group_administrator_rights_, from.extract_field("default_group_administrator_rights")));
  return Status::OK();
}

Status from_json(td_api::setGiftResalePrice &to, JsonObject &from) {
  TRY_STATUS(from_json(to.received_gift_id_, from.extract_field("received_gift_id")));
  TRY_STATUS(from_json(to.price_, from.extract_field("price")));
  return Status::OK();
}

Status from_json(td_api::setLogTagVerbosityLevel &to, JsonObject &from) {
  TRY_STATUS(from_json(to.tag_, from.extract_field("tag")));
  TRY_STATUS(from_json(to.new_verbosity_level_, from.extract_field("new_verbosity_level")));
  return Status::OK();
}

Status from_json(td_api::setName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.first_name_, from.extract_field("first_name")));
  TRY_STATUS(from_json(to.last_name_, from.extract_field("last_name")));
  return Status::OK();
}

Status from_json(td_api::setPinnedChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_list_, from.extract_field("chat_list")));
  TRY_STATUS(from_json(to.chat_ids_, from.extract_field("chat_ids")));
  return Status::OK();
}

Status from_json(td_api::setReactionNotificationSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.notification_settings_, from.extract_field("notification_settings")));
  return Status::OK();
}

Status from_json(td_api::setStickerSetThumbnail &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.thumbnail_, from.extract_field("thumbnail")));
  TRY_STATUS(from_json(to.format_, from.extract_field("format")));
  return Status::OK();
}

Status from_json(td_api::setSupergroupUsername &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  return Status::OK();
}

Status from_json(td_api::setVideoChatDefaultParticipant &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.default_participant_id_, from.extract_field("default_participant_id")));
  return Status::OK();
}

Status from_json(td_api::stopBusinessPoll &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  return Status::OK();
}

Status from_json(td_api::testCallEmpty &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::testReturnError &to, JsonObject &from) {
  TRY_STATUS(from_json(to.error_, from.extract_field("error")));
  return Status::OK();
}

Status from_json(td_api::toggleChatFolderTags &to, JsonObject &from) {
  TRY_STATUS(from_json(to.are_tags_enabled_, from.extract_field("are_tags_enabled")));
  return Status::OK();
}

Status from_json(td_api::toggleForumTopicIsClosed &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  TRY_STATUS(from_json(to.is_closed_, from.extract_field("is_closed")));
  return Status::OK();
}

Status from_json(td_api::toggleGroupCallScreenSharingIsPaused &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.is_paused_, from.extract_field("is_paused")));
  return Status::OK();
}

Status from_json(td_api::toggleSupergroupHasHiddenMembers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.has_hidden_members_, from.extract_field("has_hidden_members")));
  return Status::OK();
}

Status from_json(td_api::toggleVideoChatEnabledStartNotification &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.enabled_start_notification_, from.extract_field("enabled_start_notification")));
  return Status::OK();
}

Status from_json(td_api::unpinAllForumTopicMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  return Status::OK();
}

Status from_json(td_api::viewTrendingStickerSets &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_set_ids_, from.extract_field("sticker_set_ids")));
  return Status::OK();
}

void to_json(JsonValueScope &jv, const td_api::addedProxy &object) {
  auto jo = jv.enter_object();
  jo("@type", "addedProxy");
  jo("id", object.id_);
  jo("last_used_date", object.last_used_date_);
  jo("is_enabled", JsonBool{object.is_enabled_});
  if (object.proxy_) {
    jo("proxy", ToJson(*object.proxy_));
  }
}

void to_json(JsonValueScope &jv, const td_api::alternativeVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "alternativeVideo");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("width", object.width_);
  jo("height", object.height_);
  jo("codec", object.codec_);
  if (object.hls_file_) {
    jo("hls_file", ToJson(*object.hls_file_));
  }
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
}

void to_json(JsonValueScope &jv, const td_api::auctionBid &object) {
  auto jo = jv.enter_object();
  jo("@type", "auctionBid");
  jo("star_count", object.star_count_);
  jo("bid_date", object.bid_date_);
  jo("position", object.position_);
}

void to_json(JsonValueScope &jv, const td_api::autoDownloadSettingsPresets &object) {
  auto jo = jv.enter_object();
  jo("@type", "autoDownloadSettingsPresets");
  if (object.low_) {
    jo("low", ToJson(*object.low_));
  }
  if (object.medium_) {
    jo("medium", ToJson(*object.medium_));
  }
  if (object.high_) {
    jo("high", ToJson(*object.high_));
  }
}

void to_json(JsonValueScope &jv, const td_api::BackgroundFill &object) {
  td_api::downcast_call(const_cast<td_api::BackgroundFill &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::backgroundFillSolid &object) {
  auto jo = jv.enter_object();
  jo("@type", "backgroundFillSolid");
  jo("color", object.color_);
}

void to_json(JsonValueScope &jv, const td_api::backgroundFillGradient &object) {
  auto jo = jv.enter_object();
  jo("@type", "backgroundFillGradient");
  jo("top_color", object.top_color_);
  jo("bottom_color", object.bottom_color_);
  jo("rotation_angle", object.rotation_angle_);
}

void to_json(JsonValueScope &jv, const td_api::backgroundFillFreeformGradient &object) {
  auto jo = jv.enter_object();
  jo("@type", "backgroundFillFreeformGradient");
  jo("colors", ToJson(object.colors_));
}

void to_json(JsonValueScope &jv, const td_api::botCommand &object) {
  auto jo = jv.enter_object();
  jo("@type", "botCommand");
  jo("command", object.command_);
  jo("description", object.description_);
}

void to_json(JsonValueScope &jv, const td_api::BotWriteAccessAllowReason &object) {
  td_api::downcast_call(const_cast<td_api::BotWriteAccessAllowReason &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::botWriteAccessAllowReasonConnectedWebsite &object) {
  auto jo = jv.enter_object();
  jo("@type", "botWriteAccessAllowReasonConnectedWebsite");
  jo("domain_name", object.domain_name_);
}

void to_json(JsonValueScope &jv, const td_api::botWriteAccessAllowReasonAddedToAttachmentMenu &object) {
  auto jo = jv.enter_object();
  jo("@type", "botWriteAccessAllowReasonAddedToAttachmentMenu");
}

void to_json(JsonValueScope &jv, const td_api::botWriteAccessAllowReasonLaunchedWebApp &object) {
  auto jo = jv.enter_object();
  jo("@type", "botWriteAccessAllowReasonLaunchedWebApp");
  if (object.web_app_) {
    jo("web_app", ToJson(*object.web_app_));
  }
}

void to_json(JsonValueScope &jv, const td_api::botWriteAccessAllowReasonAcceptedRequest &object) {
  auto jo = jv.enter_object();
  jo("@type", "botWriteAccessAllowReasonAcceptedRequest");
}

void to_json(JsonValueScope &jv, const td_api::businessConnectedBot &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessConnectedBot");
  jo("bot_user_id", object.bot_user_id_);
  if (object.recipients_) {
    jo("recipients", ToJson(*object.recipients_));
  }
  if (object.rights_) {
    jo("rights", ToJson(*object.rights_));
  }
}

void to_json(JsonValueScope &jv, const td_api::businessMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessMessages");
  jo("messages", ToJson(object.messages_));
}

void to_json(JsonValueScope &jv, const td_api::callProtocol &object) {
  auto jo = jv.enter_object();
  jo("@type", "callProtocol");
  jo("udp_p2p", JsonBool{object.udp_p2p_});
  jo("udp_reflector", JsonBool{object.udp_reflector_});
  jo("min_layer", object.min_layer_);
  jo("max_layer", object.max_layer_);
  jo("library_versions", ToJson(object.library_versions_));
}

void to_json(JsonValueScope &jv, const td_api::CanTransferOwnershipResult &object) {
  td_api::downcast_call(const_cast<td_api::CanTransferOwnershipResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::canTransferOwnershipResultOk &object) {
  auto jo = jv.enter_object();
  jo("@type", "canTransferOwnershipResultOk");
}

void to_json(JsonValueScope &jv, const td_api::canTransferOwnershipResultPasswordNeeded &object) {
  auto jo = jv.enter_object();
  jo("@type", "canTransferOwnershipResultPasswordNeeded");
}

void to_json(JsonValueScope &jv, const td_api::canTransferOwnershipResultPasswordTooFresh &object) {
  auto jo = jv.enter_object();
  jo("@type", "canTransferOwnershipResultPasswordTooFresh");
  jo("retry_after", object.retry_after_);
}

void to_json(JsonValueScope &jv, const td_api::canTransferOwnershipResultSessionTooFresh &object) {
  auto jo = jv.enter_object();
  jo("@type", "canTransferOwnershipResultSessionTooFresh");
  jo("retry_after", object.retry_after_);
}

void to_json(JsonValueScope &jv, const td_api::chatBackground &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatBackground");
  if (object.background_) {
    jo("background", ToJson(*object.background_));
  }
  jo("dark_theme_dimming", object.dark_theme_dimming_);
}

void to_json(JsonValueScope &jv, const td_api::chatBoostStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatBoostStatus");
  jo("boost_url", object.boost_url_);
  jo("applied_slot_ids", ToJson(object.applied_slot_ids_));
  jo("level", object.level_);
  jo("gift_code_boost_count", object.gift_code_boost_count_);
  jo("boost_count", object.boost_count_);
  jo("current_level_boost_count", object.current_level_boost_count_);
  jo("next_level_boost_count", object.next_level_boost_count_);
  jo("premium_member_count", object.premium_member_count_);
  jo("premium_member_percentage", object.premium_member_percentage_);
  jo("prepaid_giveaways", ToJson(object.prepaid_giveaways_));
}

void to_json(JsonValueScope &jv, const td_api::chatFolderInviteLinks &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatFolderInviteLinks");
  jo("invite_links", ToJson(object.invite_links_));
}

void to_json(JsonValueScope &jv, const td_api::chatInviteLinks &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatInviteLinks");
  jo("total_count", object.total_count_);
  jo("invite_links", ToJson(object.invite_links_));
}

void to_json(JsonValueScope &jv, const td_api::chatMembers &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatMembers");
  jo("total_count", object.total_count_);
  jo("members", ToJson(object.members_));
}

void to_json(JsonValueScope &jv, const td_api::chatPhotos &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatPhotos");
  jo("total_count", object.total_count_);
  jo("photos", ToJson(object.photos_));
}

void to_json(JsonValueScope &jv, const td_api::chatStatisticsAdministratorActionsInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatStatisticsAdministratorActionsInfo");
  jo("user_id", object.user_id_);
  jo("deleted_message_count", object.deleted_message_count_);
  jo("banned_user_count", object.banned_user_count_);
  jo("restricted_user_count", object.restricted_user_count_);
}

void to_json(JsonValueScope &jv, const td_api::CheckStickerSetNameResult &object) {
  td_api::downcast_call(const_cast<td_api::CheckStickerSetNameResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::checkStickerSetNameResultOk &object) {
  auto jo = jv.enter_object();
  jo("@type", "checkStickerSetNameResultOk");
}

void to_json(JsonValueScope &jv, const td_api::checkStickerSetNameResultNameInvalid &object) {
  auto jo = jv.enter_object();
  jo("@type", "checkStickerSetNameResultNameInvalid");
}

void to_json(JsonValueScope &jv, const td_api::checkStickerSetNameResultNameOccupied &object) {
  auto jo = jv.enter_object();
  jo("@type", "checkStickerSetNameResultNameOccupied");
}

void to_json(JsonValueScope &jv, const td_api::connectedWebsites &object) {
  auto jo = jv.enter_object();
  jo("@type", "connectedWebsites");
  jo("websites", ToJson(object.websites_));
}

void to_json(JsonValueScope &jv, const td_api::customRequestResult &object) {
  auto jo = jv.enter_object();
  jo("@type", "customRequestResult");
  jo("result", object.result_);
}

void to_json(JsonValueScope &jv, const td_api::DiceStickers &object) {
  td_api::downcast_call(const_cast<td_api::DiceStickers &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::diceStickersRegular &object) {
  auto jo = jv.enter_object();
  jo("@type", "diceStickersRegular");
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::diceStickersSlotMachine &object) {
  auto jo = jv.enter_object();
  jo("@type", "diceStickersSlotMachine");
  if (object.background_) {
    jo("background", ToJson(*object.background_));
  }
  if (object.lever_) {
    jo("lever", ToJson(*object.lever_));
  }
  if (object.left_reel_) {
    jo("left_reel", ToJson(*object.left_reel_));
  }
  if (object.center_reel_) {
    jo("center_reel", ToJson(*object.center_reel_));
  }
  if (object.right_reel_) {
    jo("right_reel", ToJson(*object.right_reel_));
  }
}

void to_json(JsonValueScope &jv, const td_api::EmailAddressResetState &object) {
  td_api::downcast_call(const_cast<td_api::EmailAddressResetState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::emailAddressResetStateAvailable &object) {
  auto jo = jv.enter_object();
  jo("@type", "emailAddressResetStateAvailable");
  jo("wait_period", object.wait_period_);
}

void to_json(JsonValueScope &jv, const td_api::emailAddressResetStatePending &object) {
  auto jo = jv.enter_object();
  jo("@type", "emailAddressResetStatePending");
  jo("reset_in", object.reset_in_);
}

void to_json(JsonValueScope &jv, const td_api::emojiStatusCustomEmojis &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiStatusCustomEmojis");
  jo("custom_emoji_ids", ToJson(JsonVectorInt64{object.custom_emoji_ids_}));
}

void to_json(JsonValueScope &jv, const td_api::failedToAddMembers &object) {
  auto jo = jv.enter_object();
  jo("@type", "failedToAddMembers");
  jo("failed_to_add_members", ToJson(object.failed_to_add_members_));
}

void to_json(JsonValueScope &jv, const td_api::forumTopicIcon &object) {
  auto jo = jv.enter_object();
  jo("@type", "forumTopicIcon");
  jo("color", object.color_);
  jo("custom_emoji_id", ToJson(JsonInt64{object.custom_emoji_id_}));
}

void to_json(JsonValueScope &jv, const td_api::foundMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "foundMessages");
  jo("total_count", object.total_count_);
  jo("messages", ToJson(object.messages_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::gameHighScores &object) {
  auto jo = jv.enter_object();
  jo("@type", "gameHighScores");
  jo("scores", ToJson(object.scores_));
}

void to_json(JsonValueScope &jv, const td_api::giftCollection &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftCollection");
  jo("id", object.id_);
  jo("name", object.name_);
  if (object.icon_) {
    jo("icon", ToJson(*object.icon_));
  }
  jo("gift_count", object.gift_count_);
}

void to_json(JsonValueScope &jv, const td_api::giftUpgradePreview &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftUpgradePreview");
  jo("models", ToJson(object.models_));
  jo("symbols", ToJson(object.symbols_));
  jo("backdrops", ToJson(object.backdrops_));
  jo("prices", ToJson(object.prices_));
  jo("next_prices", ToJson(object.next_prices_));
}

void to_json(JsonValueScope &jv, const td_api::groupCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "groupCall");
  jo("id", object.id_);
  jo("unique_id", ToJson(JsonInt64{object.unique_id_}));
  jo("title", object.title_);
  jo("invite_link", object.invite_link_);
  jo("paid_message_star_count", object.paid_message_star_count_);
  jo("scheduled_start_date", object.scheduled_start_date_);
  jo("enabled_start_notification", JsonBool{object.enabled_start_notification_});
  jo("is_active", JsonBool{object.is_active_});
  jo("is_video_chat", JsonBool{object.is_video_chat_});
  jo("is_live_story", JsonBool{object.is_live_story_});
  jo("is_rtmp_stream", JsonBool{object.is_rtmp_stream_});
  jo("is_joined", JsonBool{object.is_joined_});
  jo("need_rejoin", JsonBool{object.need_rejoin_});
  jo("is_owned", JsonBool{object.is_owned_});
  jo("can_be_managed", JsonBool{object.can_be_managed_});
  jo("participant_count", object.participant_count_);
  jo("has_hidden_listeners", JsonBool{object.has_hidden_listeners_});
  jo("loaded_all_participants", JsonBool{object.loaded_all_participants_});
  if (object.message_sender_id_) {
    jo("message_sender_id", ToJson(*object.message_sender_id_));
  }
  jo("recent_speakers", ToJson(object.recent_speakers_));
  jo("is_my_video_enabled", JsonBool{object.is_my_video_enabled_});
  jo("is_my_video_paused", JsonBool{object.is_my_video_paused_});
  jo("can_enable_video", JsonBool{object.can_enable_video_});
  jo("mute_new_participants", JsonBool{object.mute_new_participants_});
  jo("can_toggle_mute_new_participants", JsonBool{object.can_toggle_mute_new_participants_});
  jo("can_send_messages", JsonBool{object.can_send_messages_});
  jo("are_messages_allowed", JsonBool{object.are_messages_allowed_});
  jo("can_toggle_are_messages_allowed", JsonBool{object.can_toggle_are_messages_allowed_});
  jo("can_delete_messages", JsonBool{object.can_delete_messages_});
  jo("record_duration", object.record_duration_);
  jo("is_video_recorded", JsonBool{object.is_video_recorded_});
  jo("duration", object.duration_);
}

void to_json(JsonValueScope &jv, const td_api::groupCallStream &object) {
  auto jo = jv.enter_object();
  jo("@type", "groupCallStream");
  jo("channel_id", object.channel_id_);
  jo("scale", object.scale_);
  jo("time_offset", object.time_offset_);
}

void to_json(JsonValueScope &jv, const td_api::InlineQueryResult &object) {
  td_api::downcast_call(const_cast<td_api::InlineQueryResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultArticle &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultArticle");
  jo("id", object.id_);
  jo("url", object.url_);
  jo("title", object.title_);
  jo("description", object.description_);
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultContact &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultContact");
  jo("id", object.id_);
  if (object.contact_) {
    jo("contact", ToJson(*object.contact_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultLocation &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultLocation");
  jo("id", object.id_);
  if (object.location_) {
    jo("location", ToJson(*object.location_));
  }
  jo("title", object.title_);
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultVenue &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultVenue");
  jo("id", object.id_);
  if (object.venue_) {
    jo("venue", ToJson(*object.venue_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultGame &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultGame");
  jo("id", object.id_);
  if (object.game_) {
    jo("game", ToJson(*object.game_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultAnimation &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultAnimation");
  jo("id", object.id_);
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
  jo("title", object.title_);
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultAudio &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultAudio");
  jo("id", object.id_);
  if (object.audio_) {
    jo("audio", ToJson(*object.audio_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultDocument &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultDocument");
  jo("id", object.id_);
  if (object.document_) {
    jo("document", ToJson(*object.document_));
  }
  jo("title", object.title_);
  jo("description", object.description_);
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultPhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultPhoto");
  jo("id", object.id_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("title", object.title_);
  jo("description", object.description_);
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultSticker &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultSticker");
  jo("id", object.id_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultVideo");
  jo("id", object.id_);
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
  jo("title", object.title_);
  jo("description", object.description_);
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultVoiceNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultVoiceNote");
  jo("id", object.id_);
  if (object.voice_note_) {
    jo("voice_note", ToJson(*object.voice_note_));
  }
  jo("title", object.title_);
}

void to_json(JsonValueScope &jv, const td_api::inputPaidMedia &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputPaidMedia");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  if (object.media_) {
    jo("media", ToJson(*object.media_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  jo("added_sticker_file_ids", ToJson(object.added_sticker_file_ids_));
  jo("width", object.width_);
  jo("height", object.height_);
}

void to_json(JsonValueScope &jv, const td_api::InviteLinkChatType &object) {
  td_api::downcast_call(const_cast<td_api::InviteLinkChatType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::inviteLinkChatTypeBasicGroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "inviteLinkChatTypeBasicGroup");
}

void to_json(JsonValueScope &jv, const td_api::inviteLinkChatTypeSupergroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "inviteLinkChatTypeSupergroup");
}

void to_json(JsonValueScope &jv, const td_api::inviteLinkChatTypeChannel &object) {
  auto jo = jv.enter_object();
  jo("@type", "inviteLinkChatTypeChannel");
}

void to_json(JsonValueScope &jv, const td_api::LanguagePackStringValue &object) {
  td_api::downcast_call(const_cast<td_api::LanguagePackStringValue &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::languagePackStringValueOrdinary &object) {
  auto jo = jv.enter_object();
  jo("@type", "languagePackStringValueOrdinary");
  jo("value", object.value_);
}

void to_json(JsonValueScope &jv, const td_api::languagePackStringValuePluralized &object) {
  auto jo = jv.enter_object();
  jo("@type", "languagePackStringValuePluralized");
  jo("zero_value", object.zero_value_);
  jo("one_value", object.one_value_);
  jo("two_value", object.two_value_);
  jo("few_value", object.few_value_);
  jo("many_value", object.many_value_);
  jo("other_value", object.other_value_);
}

void to_json(JsonValueScope &jv, const td_api::languagePackStringValueDeleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "languagePackStringValueDeleted");
}

void to_json(JsonValueScope &jv, const td_api::location &object) {
  auto jo = jv.enter_object();
  jo("@type", "location");
  jo("latitude", object.latitude_);
  jo("longitude", object.longitude_);
  jo("horizontal_accuracy", object.horizontal_accuracy_);
}

void to_json(JsonValueScope &jv, const td_api::message &object) {
  auto jo = jv.enter_object();
  jo("@type", "message");
  jo("id", object.id_);
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  jo("chat_id", object.chat_id_);
  if (object.sending_state_) {
    jo("sending_state", ToJson(*object.sending_state_));
  }
  if (object.scheduling_state_) {
    jo("scheduling_state", ToJson(*object.scheduling_state_));
  }
  jo("is_outgoing", JsonBool{object.is_outgoing_});
  jo("is_pinned", JsonBool{object.is_pinned_});
  jo("is_from_offline", JsonBool{object.is_from_offline_});
  jo("can_be_saved", JsonBool{object.can_be_saved_});
  jo("has_timestamped_media", JsonBool{object.has_timestamped_media_});
  jo("is_channel_post", JsonBool{object.is_channel_post_});
  jo("is_paid_star_suggested_post", JsonBool{object.is_paid_star_suggested_post_});
  jo("is_paid_ton_suggested_post", JsonBool{object.is_paid_ton_suggested_post_});
  jo("contains_unread_mention", JsonBool{object.contains_unread_mention_});
  jo("date", object.date_);
  jo("edit_date", object.edit_date_);
  if (object.forward_info_) {
    jo("forward_info", ToJson(*object.forward_info_));
  }
  if (object.import_info_) {
    jo("import_info", ToJson(*object.import_info_));
  }
  if (object.interaction_info_) {
    jo("interaction_info", ToJson(*object.interaction_info_));
  }
  jo("unread_reactions", ToJson(object.unread_reactions_));
  if (object.fact_check_) {
    jo("fact_check", ToJson(*object.fact_check_));
  }
  if (object.suggested_post_info_) {
    jo("suggested_post_info", ToJson(*object.suggested_post_info_));
  }
  if (object.reply_to_) {
    jo("reply_to", ToJson(*object.reply_to_));
  }
  if (object.topic_id_) {
    jo("topic_id", ToJson(*object.topic_id_));
  }
  if (object.self_destruct_type_) {
    jo("self_destruct_type", ToJson(*object.self_destruct_type_));
  }
  jo("self_destruct_in", object.self_destruct_in_);
  jo("auto_delete_in", object.auto_delete_in_);
  jo("via_bot_user_id", object.via_bot_user_id_);
  jo("sender_business_bot_user_id", object.sender_business_bot_user_id_);
  jo("sender_boost_count", object.sender_boost_count_);
  jo("sender_tag", object.sender_tag_);
  jo("paid_message_star_count", object.paid_message_star_count_);
  jo("author_signature", object.author_signature_);
  jo("media_album_id", ToJson(JsonInt64{object.media_album_id_}));
  jo("effect_id", ToJson(JsonInt64{object.effect_id_}));
  if (object.restriction_info_) {
    jo("restriction_info", ToJson(*object.restriction_info_));
  }
  jo("summary_language_code", object.summary_language_code_);
  if (object.content_) {
    jo("content", ToJson(*object.content_));
  }
  if (object.reply_markup_) {
    jo("reply_markup", ToJson(*object.reply_markup_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageForwardInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageForwardInfo");
  if (object.origin_) {
    jo("origin", ToJson(*object.origin_));
  }
  jo("date", object.date_);
  if (object.source_) {
    jo("source", ToJson(*object.source_));
  }
  jo("public_service_announcement_type", object.public_service_announcement_type_);
}

void to_json(JsonValueScope &jv, const td_api::messageReaction &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageReaction");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("total_count", object.total_count_);
  jo("is_chosen", JsonBool{object.is_chosen_});
  if (object.used_sender_id_) {
    jo("used_sender_id", ToJson(*object.used_sender_id_));
  }
  jo("recent_sender_ids", ToJson(object.recent_sender_ids_));
}

void to_json(JsonValueScope &jv, const td_api::MessageSendingState &object) {
  td_api::downcast_call(const_cast<td_api::MessageSendingState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::messageSendingStatePending &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSendingStatePending");
  jo("sending_id", object.sending_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageSendingStateFailed &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSendingStateFailed");
  if (object.error_) {
    jo("error", ToJson(*object.error_));
  }
  jo("can_retry", JsonBool{object.can_retry_});
  jo("need_another_sender", JsonBool{object.need_another_sender_});
  jo("need_another_reply_quote", JsonBool{object.need_another_reply_quote_});
  jo("need_drop_reply", JsonBool{object.need_drop_reply_});
  jo("required_paid_message_star_count", object.required_paid_message_star_count_);
  jo("retry_after", object.retry_after_);
}

void to_json(JsonValueScope &jv, const td_api::NetworkStatisticsEntry &object) {
  td_api::downcast_call(const_cast<td_api::NetworkStatisticsEntry &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::networkStatisticsEntryFile &object) {
  auto jo = jv.enter_object();
  jo("@type", "networkStatisticsEntryFile");
  if (object.file_type_) {
    jo("file_type", ToJson(*object.file_type_));
  }
  if (object.network_type_) {
    jo("network_type", ToJson(*object.network_type_));
  }
  jo("sent_bytes", object.sent_bytes_);
  jo("received_bytes", object.received_bytes_);
}

void to_json(JsonValueScope &jv, const td_api::networkStatisticsEntryCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "networkStatisticsEntryCall");
  if (object.network_type_) {
    jo("network_type", ToJson(*object.network_type_));
  }
  jo("sent_bytes", object.sent_bytes_);
  jo("received_bytes", object.received_bytes_);
  jo("duration", object.duration_);
}

void to_json(JsonValueScope &jv, const td_api::NotificationType &object) {
  td_api::downcast_call(const_cast<td_api::NotificationType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::notificationTypeNewMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationTypeNewMessage");
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
  jo("show_preview", JsonBool{object.show_preview_});
}

void to_json(JsonValueScope &jv, const td_api::notificationTypeNewSecretChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationTypeNewSecretChat");
}

void to_json(JsonValueScope &jv, const td_api::notificationTypeNewCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationTypeNewCall");
  jo("call_id", object.call_id_);
}

void to_json(JsonValueScope &jv, const td_api::notificationTypeNewPushMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationTypeNewPushMessage");
  jo("message_id", object.message_id_);
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  jo("sender_name", object.sender_name_);
  jo("is_outgoing", JsonBool{object.is_outgoing_});
  if (object.content_) {
    jo("content", ToJson(*object.content_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockListItem &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockListItem");
  jo("label", object.label_);
  jo("page_blocks", ToJson(object.page_blocks_));
}

void to_json(JsonValueScope &jv, const td_api::passportAuthorizationForm &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportAuthorizationForm");
  jo("id", object.id_);
  jo("required_elements", ToJson(object.required_elements_));
  jo("privacy_policy_url", object.privacy_policy_url_);
}

void to_json(JsonValueScope &jv, const td_api::passwordState &object) {
  auto jo = jv.enter_object();
  jo("@type", "passwordState");
  jo("has_password", JsonBool{object.has_password_});
  jo("password_hint", object.password_hint_);
  jo("has_recovery_email_address", JsonBool{object.has_recovery_email_address_});
  jo("has_passport_data", JsonBool{object.has_passport_data_});
  if (object.recovery_email_address_code_info_) {
    jo("recovery_email_address_code_info", ToJson(*object.recovery_email_address_code_info_));
  }
  jo("login_email_address_pattern", object.login_email_address_pattern_);
  jo("pending_reset_date", object.pending_reset_date_);
}

void to_json(JsonValueScope &jv, const td_api::personalDocument &object) {
  auto jo = jv.enter_object();
  jo("@type", "personalDocument");
  jo("files", ToJson(object.files_));
  jo("translation", ToJson(object.translation_));
}

void to_json(JsonValueScope &jv, const td_api::pollVoter &object) {
  auto jo = jv.enter_object();
  jo("@type", "pollVoter");
  if (object.voter_id_) {
    jo("voter_id", ToJson(*object.voter_id_));
  }
  jo("date", object.date_);
}

void to_json(JsonValueScope &jv, const td_api::premiumGiveawayPaymentOptions &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumGiveawayPaymentOptions");
  jo("options", ToJson(object.options_));
}

void to_json(JsonValueScope &jv, const td_api::productInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "productInfo");
  jo("title", object.title_);
  if (object.description_) {
    jo("description", ToJson(*object.description_));
  }
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::publicPostSearchLimits &object) {
  auto jo = jv.enter_object();
  jo("@type", "publicPostSearchLimits");
  jo("daily_free_query_count", object.daily_free_query_count_);
  jo("remaining_free_query_count", object.remaining_free_query_count_);
  jo("next_free_query_in", object.next_free_query_in_);
  jo("star_count", object.star_count_);
  jo("is_current_query_free", JsonBool{object.is_current_query_free_});
}

void to_json(JsonValueScope &jv, const td_api::ReactionUnavailabilityReason &object) {
  td_api::downcast_call(const_cast<td_api::ReactionUnavailabilityReason &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::reactionUnavailabilityReasonAnonymousAdministrator &object) {
  auto jo = jv.enter_object();
  jo("@type", "reactionUnavailabilityReasonAnonymousAdministrator");
}

void to_json(JsonValueScope &jv, const td_api::reactionUnavailabilityReasonGuest &object) {
  auto jo = jv.enter_object();
  jo("@type", "reactionUnavailabilityReasonGuest");
}

void to_json(JsonValueScope &jv, const td_api::ReportChatResult &object) {
  td_api::downcast_call(const_cast<td_api::ReportChatResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::reportChatResultOk &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportChatResultOk");
}

void to_json(JsonValueScope &jv, const td_api::reportChatResultOptionRequired &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportChatResultOptionRequired");
  jo("title", object.title_);
  jo("options", ToJson(object.options_));
}

void to_json(JsonValueScope &jv, const td_api::reportChatResultTextRequired &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportChatResultTextRequired");
  jo("option_id", base64_encode(object.option_id_));
  jo("is_optional", JsonBool{object.is_optional_});
}

void to_json(JsonValueScope &jv, const td_api::reportChatResultMessagesRequired &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportChatResultMessagesRequired");
}

void to_json(JsonValueScope &jv, const td_api::savedCredentials &object) {
  auto jo = jv.enter_object();
  jo("@type", "savedCredentials");
  jo("id", object.id_);
  jo("title", object.title_);
}

void to_json(JsonValueScope &jv, const td_api::SecretChatState &object) {
  td_api::downcast_call(const_cast<td_api::SecretChatState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::secretChatStatePending &object) {
  auto jo = jv.enter_object();
  jo("@type", "secretChatStatePending");
}

void to_json(JsonValueScope &jv, const td_api::secretChatStateReady &object) {
  auto jo = jv.enter_object();
  jo("@type", "secretChatStateReady");
}

void to_json(JsonValueScope &jv, const td_api::secretChatStateClosed &object) {
  auto jo = jv.enter_object();
  jo("@type", "secretChatStateClosed");
}

void to_json(JsonValueScope &jv, const td_api::shippingOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "shippingOption");
  jo("id", object.id_);
  jo("title", object.title_);
  jo("price_parts", ToJson(object.price_parts_));
}

void to_json(JsonValueScope &jv, const td_api::starGiveawayPaymentOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "starGiveawayPaymentOption");
  jo("currency", object.currency_);
  jo("amount", object.amount_);
  jo("star_count", object.star_count_);
  jo("store_product_id", object.store_product_id_);
  jo("yearly_boost_count", object.yearly_boost_count_);
  jo("winner_options", ToJson(object.winner_options_));
  jo("is_default", JsonBool{object.is_default_});
  jo("is_additional", JsonBool{object.is_additional_});
}

void to_json(JsonValueScope &jv, const td_api::StarSubscriptionType &object) {
  td_api::downcast_call(const_cast<td_api::StarSubscriptionType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::starSubscriptionTypeChannel &object) {
  auto jo = jv.enter_object();
  jo("@type", "starSubscriptionTypeChannel");
  jo("can_reuse", JsonBool{object.can_reuse_});
  jo("invite_link", object.invite_link_);
}

void to_json(JsonValueScope &jv, const td_api::starSubscriptionTypeBot &object) {
  auto jo = jv.enter_object();
  jo("@type", "starSubscriptionTypeBot");
  jo("is_canceled_by_bot", JsonBool{object.is_canceled_by_bot_});
  jo("title", object.title_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("invoice_link", object.invoice_link_);
}

void to_json(JsonValueScope &jv, const td_api::StickerFormat &object) {
  td_api::downcast_call(const_cast<td_api::StickerFormat &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::stickerFormatWebp &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickerFormatWebp");
}

void to_json(JsonValueScope &jv, const td_api::stickerFormatTgs &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickerFormatTgs");
}

void to_json(JsonValueScope &jv, const td_api::stickerFormatWebm &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickerFormatWebm");
}

void to_json(JsonValueScope &jv, const td_api::storageStatisticsByFileType &object) {
  auto jo = jv.enter_object();
  jo("@type", "storageStatisticsByFileType");
  if (object.file_type_) {
    jo("file_type", ToJson(*object.file_type_));
  }
  jo("size", object.size_);
  jo("count", object.count_);
}

void to_json(JsonValueScope &jv, const td_api::StoryContent &object) {
  td_api::downcast_call(const_cast<td_api::StoryContent &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::storyContentPhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyContentPhoto");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::storyContentVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyContentVideo");
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
  if (object.alternative_video_) {
    jo("alternative_video", ToJson(*object.alternative_video_));
  }
}

void to_json(JsonValueScope &jv, const td_api::storyContentLive &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyContentLive");
  jo("group_call_id", object.group_call_id_);
  jo("is_rtmp_stream", JsonBool{object.is_rtmp_stream_});
}

void to_json(JsonValueScope &jv, const td_api::storyContentUnsupported &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyContentUnsupported");
}

void to_json(JsonValueScope &jv, const td_api::StoryPrivacySettings &object) {
  td_api::downcast_call(const_cast<td_api::StoryPrivacySettings &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::storyPrivacySettingsEveryone &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyPrivacySettingsEveryone");
  jo("except_user_ids", ToJson(object.except_user_ids_));
}

void to_json(JsonValueScope &jv, const td_api::storyPrivacySettingsContacts &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyPrivacySettingsContacts");
  jo("except_user_ids", ToJson(object.except_user_ids_));
}

void to_json(JsonValueScope &jv, const td_api::storyPrivacySettingsCloseFriends &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyPrivacySettingsCloseFriends");
}

void to_json(JsonValueScope &jv, const td_api::storyPrivacySettingsSelectedUsers &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyPrivacySettingsSelectedUsers");
  jo("user_ids", ToJson(object.user_ids_));
}

void to_json(JsonValueScope &jv, const td_api::supergroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "supergroup");
  jo("id", object.id_);
  if (object.usernames_) {
    jo("usernames", ToJson(*object.usernames_));
  }
  jo("date", object.date_);
  if (object.status_) {
    jo("status", ToJson(*object.status_));
  }
  jo("member_count", object.member_count_);
  jo("boost_level", object.boost_level_);
  jo("has_automatic_translation", JsonBool{object.has_automatic_translation_});
  jo("has_linked_chat", JsonBool{object.has_linked_chat_});
  jo("has_location", JsonBool{object.has_location_});
  jo("sign_messages", JsonBool{object.sign_messages_});
  jo("show_message_sender", JsonBool{object.show_message_sender_});
  jo("join_to_send_messages", JsonBool{object.join_to_send_messages_});
  jo("join_by_request", JsonBool{object.join_by_request_});
  jo("is_slow_mode_enabled", JsonBool{object.is_slow_mode_enabled_});
  jo("is_channel", JsonBool{object.is_channel_});
  jo("is_broadcast_group", JsonBool{object.is_broadcast_group_});
  jo("is_forum", JsonBool{object.is_forum_});
  jo("is_direct_messages_group", JsonBool{object.is_direct_messages_group_});
  jo("is_administered_direct_messages_group", JsonBool{object.is_administered_direct_messages_group_});
  if (object.verification_status_) {
    jo("verification_status", ToJson(*object.verification_status_));
  }
  jo("has_direct_messages_group", JsonBool{object.has_direct_messages_group_});
  jo("has_forum_tabs", JsonBool{object.has_forum_tabs_});
  if (object.restriction_info_) {
    jo("restriction_info", ToJson(*object.restriction_info_));
  }
  jo("paid_message_star_count", object.paid_message_star_count_);
  if (object.active_story_state_) {
    jo("active_story_state", ToJson(*object.active_story_state_));
  }
}

void to_json(JsonValueScope &jv, const td_api::testBytes &object) {
  auto jo = jv.enter_object();
  jo("@type", "testBytes");
  jo("value", base64_encode(object.value_));
}

void to_json(JsonValueScope &jv, const td_api::textEntities &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntities");
  jo("entities", ToJson(object.entities_));
}

void to_json(JsonValueScope &jv, const td_api::tonRevenueStatistics &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonRevenueStatistics");
  if (object.revenue_by_day_graph_) {
    jo("revenue_by_day_graph", ToJson(*object.revenue_by_day_graph_));
  }
  if (object.status_) {
    jo("status", ToJson(*object.status_));
  }
  jo("usd_rate", object.usd_rate_);
}

void to_json(JsonValueScope &jv, const td_api::updates &object) {
  auto jo = jv.enter_object();
  jo("@type", "updates");
  jo("updates", ToJson(object.updates_));
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftModelCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftModelCount");
  if (object.model_) {
    jo("model", ToJson(*object.model_));
  }
  jo("total_count", object.total_count_);
}

void to_json(JsonValueScope &jv, const td_api::userLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "userLink");
  jo("url", object.url_);
  jo("expires_in", object.expires_in_);
}

void to_json(JsonValueScope &jv, const td_api::users &object) {
  auto jo = jv.enter_object();
  jo("@type", "users");
  jo("total_count", object.total_count_);
  jo("user_ids", ToJson(object.user_ids_));
}

void to_json(JsonValueScope &jv, const td_api::videoNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "videoNote");
  jo("duration", object.duration_);
  jo("waveform", base64_encode(object.waveform_));
  jo("length", object.length_);
  if (object.minithumbnail_) {
    jo("minithumbnail", ToJson(*object.minithumbnail_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  if (object.speech_recognition_result_) {
    jo("speech_recognition_result", ToJson(*object.speech_recognition_result_));
  }
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
}

}  // namespace td_api
}  // namespace td
