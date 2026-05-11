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
Result<int32> tl_constructor_from_string(td_api::BackgroundFill *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"backgroundFillSolid", 1010678813},
    {"backgroundFillGradient", -1839206017},
    {"backgroundFillFreeformGradient", -1145469255}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ChatAction *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"chatActionCancel", 1160523958}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::DeviceToken *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"deviceTokenHuaweiPush", 1989103142}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::GroupCallVideoQuality *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"groupCallVideoQualityThumbnail", -379186304},
    {"groupCallVideoQualityMedium", 394968234},
    {"groupCallVideoQualityFull", -2125916617}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputGroupCall *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputGroupCallLink", -812157480},
    {"inputGroupCallMessage", -341793768}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputStoryAreaType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputStoryAreaTypeLocation", -1433714887},
    {"inputStoryAreaTypeFoundVenue", -1395809130},
    {"inputStoryAreaTypePreviousVenue", 1846693388},
    {"inputStoryAreaTypeSuggestedReaction", 2101826003},
    {"inputStoryAreaTypeMessage", -266607529},
    {"inputStoryAreaTypeLink", 1408441160},
    {"inputStoryAreaTypeWeather", -1212686691},
    {"inputStoryAreaTypeUpgradedGift", 793059694}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::MessageSchedulingState *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"messageSchedulingStateSendAtDate", 1505903015},
    {"messageSchedulingStateSendWhenOnline", 2092947464},
    {"messageSchedulingStateSendWhenVideoProcessed", 2101578734}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::PaidReactionType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"paidReactionTypeRegular", -1199187333},
    {"paidReactionTypeAnonymous", 47892621},
    {"paidReactionTypeChat", -675782044}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::PublicChatType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"publicChatTypeHasUsername", 350789758},
    {"publicChatTypeIsLocationBased", 1183735952}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::StickerFormat *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"stickerFormatWebp", -2123043040},
    {"stickerFormatTgs", 1614588662},
    {"stickerFormatWebm", -2070162097}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::SupergroupMembersFilter *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"supergroupMembersFilterRecent", 1178199509},
    {"supergroupMembersFilterContacts", -1282910856},
    {"supergroupMembersFilterAdministrators", -2097380265},
    {"supergroupMembersFilterSearch", -1696358469},
    {"supergroupMembersFilterRestricted", -1107800034},
    {"supergroupMembersFilterBanned", -1210621683},
    {"supergroupMembersFilterMention", 1151301973},
    {"supergroupMembersFilterBots", 492138918}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::UserPrivacySettingRule *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"userPrivacySettingRuleRestrictChatMembers", 392530897}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Status from_json(td_api::affiliateTypeCurrentUser &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::backgroundFillSolid &to, JsonObject &from) {
  TRY_STATUS(from_json(to.color_, from.extract_field("color")));
  return Status::OK();
}

Status from_json(td_api::blockListStories &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::botMenuButton &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::businessFeatureQuickReplies &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessGreetingMessageSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shortcut_id_, from.extract_field("shortcut_id")));
  TRY_STATUS(from_json(to.recipients_, from.extract_field("recipients")));
  TRY_STATUS(from_json(to.inactivity_days_, from.extract_field("inactivity_days")));
  return Status::OK();
}

Status from_json(td_api::callProblemEcho &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::callProtocol &to, JsonObject &from) {
  TRY_STATUS(from_json(to.udp_p2p_, from.extract_field("udp_p2p")));
  TRY_STATUS(from_json(to.udp_reflector_, from.extract_field("udp_reflector")));
  TRY_STATUS(from_json(to.min_layer_, from.extract_field("min_layer")));
  TRY_STATUS(from_json(to.max_layer_, from.extract_field("max_layer")));
  TRY_STATUS(from_json(to.library_versions_, from.extract_field("library_versions")));
  return Status::OK();
}

Status from_json(td_api::chatActionUploadingPhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.progress_, from.extract_field("progress")));
  return Status::OK();
}

Status from_json(td_api::chatActionCancel &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatJoinRequest &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.date_, from.extract_field("date")));
  TRY_STATUS(from_json(to.bio_, from.extract_field("bio")));
  return Status::OK();
}

Status from_json(td_api::chatMemberStatusLeft &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatNotificationSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.use_default_mute_for_, from.extract_field("use_default_mute_for")));
  TRY_STATUS(from_json(to.mute_for_, from.extract_field("mute_for")));
  TRY_STATUS(from_json(to.use_default_sound_, from.extract_field("use_default_sound")));
  TRY_STATUS(from_json(to.sound_id_, from.extract_field("sound_id")));
  TRY_STATUS(from_json(to.use_default_show_preview_, from.extract_field("use_default_show_preview")));
  TRY_STATUS(from_json(to.show_preview_, from.extract_field("show_preview")));
  TRY_STATUS(from_json(to.use_default_mute_stories_, from.extract_field("use_default_mute_stories")));
  TRY_STATUS(from_json(to.mute_stories_, from.extract_field("mute_stories")));
  TRY_STATUS(from_json(to.use_default_story_sound_, from.extract_field("use_default_story_sound")));
  TRY_STATUS(from_json(to.story_sound_id_, from.extract_field("story_sound_id")));
  TRY_STATUS(from_json(to.use_default_show_story_poster_, from.extract_field("use_default_show_story_poster")));
  TRY_STATUS(from_json(to.show_story_poster_, from.extract_field("show_story_poster")));
  TRY_STATUS(from_json(to.use_default_disable_pinned_message_notifications_, from.extract_field("use_default_disable_pinned_message_notifications")));
  TRY_STATUS(from_json(to.disable_pinned_message_notifications_, from.extract_field("disable_pinned_message_notifications")));
  TRY_STATUS(from_json(to.use_default_disable_mention_notifications_, from.extract_field("use_default_disable_mention_notifications")));
  TRY_STATUS(from_json(to.disable_mention_notifications_, from.extract_field("disable_mention_notifications")));
  return Status::OK();
}

Status from_json(td_api::dateTimeFormattingTypeRelative &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::deviceTokenMicrosoftPush &to, JsonObject &from) {
  TRY_STATUS(from_json(to.channel_uri_, from.extract_field("channel_uri")));
  return Status::OK();
}

Status from_json(td_api::emailAddressAuthenticationCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.code_, from.extract_field("code")));
  return Status::OK();
}

Status from_json(td_api::emojiStatusTypeUpgradedGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.upgraded_gift_id_, from.extract_field("upgraded_gift_id")));
  TRY_STATUS(from_json(to.gift_title_, from.extract_field("gift_title")));
  TRY_STATUS(from_json(to.gift_name_, from.extract_field("gift_name")));
  TRY_STATUS(from_json(to.model_custom_emoji_id_, from.extract_field("model_custom_emoji_id")));
  TRY_STATUS(from_json(to.symbol_custom_emoji_id_, from.extract_field("symbol_custom_emoji_id")));
  TRY_STATUS(from_json(to.backdrop_colors_, from.extract_field("backdrop_colors")));
  return Status::OK();
}

Status from_json(td_api::fileTypePhotoStory &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeSelfDestructingVoiceNote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::firebaseAuthenticationSettingsAndroid &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::giftSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.show_gift_button_, from.extract_field("show_gift_button")));
  TRY_STATUS(from_json(to.accepted_gift_types_, from.extract_field("accepted_gift_types")));
  return Status::OK();
}

Status from_json(td_api::inlineKeyboardButton &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.icon_custom_emoji_id_, from.extract_field("icon_custom_emoji_id")));
  TRY_STATUS(from_json(to.style_, from.extract_field("style")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::inlineKeyboardButtonTypeUser &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::inputBusinessStartPage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.message_, from.extract_field("message")));
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  return Status::OK();
}

Status from_json(td_api::inputChecklist &to, JsonObject &from) {
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.tasks_, from.extract_field("tasks")));
  TRY_STATUS(from_json(to.others_can_add_tasks_, from.extract_field("others_can_add_tasks")));
  TRY_STATUS(from_json(to.others_can_mark_tasks_as_done_, from.extract_field("others_can_mark_tasks_as_done")));
  return Status::OK();
}

Status from_json(td_api::inputFileGenerated &to, JsonObject &from) {
  TRY_STATUS(from_json(to.original_path_, from.extract_field("original_path")));
  TRY_STATUS(from_json(to.conversion_, from.extract_field("conversion")));
  TRY_STATUS(from_json(to.expected_size_, from.extract_field("expected_size")));
  return Status::OK();
}

Status from_json(td_api::inputInlineQueryResultGame &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.game_short_name_, from.extract_field("game_short_name")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  return Status::OK();
}

Status from_json(td_api::inputInvoiceTelegram &to, JsonObject &from) {
  TRY_STATUS(from_json(to.purpose_, from.extract_field("purpose")));
  return Status::OK();
}

Status from_json(td_api::inputMessageVideoNote &to, JsonObject &from) {
  TRY_STATUS(from_json(to.video_note_, from.extract_field("video_note")));
  TRY_STATUS(from_json(to.thumbnail_, from.extract_field("thumbnail")));
  TRY_STATUS(from_json(to.duration_, from.extract_field("duration")));
  TRY_STATUS(from_json(to.length_, from.extract_field("length")));
  TRY_STATUS(from_json(to.self_destruct_type_, from.extract_field("self_destruct_type")));
  return Status::OK();
}

Status from_json(td_api::inputMessageStakeDice &to, JsonObject &from) {
  TRY_STATUS(from_json(to.state_hash_, from.extract_field("state_hash")));
  TRY_STATUS(from_json(to.stake_toncoin_amount_, from.extract_field("stake_toncoin_amount")));
  TRY_STATUS(from_json(to.clear_draft_, from.extract_field("clear_draft")));
  return Status::OK();
}

Status from_json(td_api::inputPaidMediaTypeVideo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.cover_, from.extract_field("cover")));
  TRY_STATUS(from_json(to.start_timestamp_, from.extract_field("start_timestamp")));
  TRY_STATUS(from_json(to.duration_, from.extract_field("duration")));
  TRY_STATUS(from_json(to.supports_streaming_, from.extract_field("supports_streaming")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementRentalAgreement &to, JsonObject &from) {
  TRY_STATUS(from_json(to.rental_agreement_, from.extract_field("rental_agreement")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementErrorSourceReverseSide &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.file_hash_, from.extract_field("file_hash")));
  return Status::OK();
}

Status from_json(td_api::inputPollTypeQuiz &to, JsonObject &from) {
  TRY_STATUS(from_json(to.correct_option_ids_, from.extract_field("correct_option_ids")));
  TRY_STATUS(from_json(to.explanation_, from.extract_field("explanation")));
  return Status::OK();
}

Status from_json(td_api::inputStoryAreaTypeWeather &to, JsonObject &from) {
  TRY_STATUS(from_json(to.temperature_, from.extract_field("temperature")));
  TRY_STATUS(from_json(to.emoji_, from.extract_field("emoji")));
  TRY_STATUS(from_json(to.background_color_, from.extract_field("background_color")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeAuthenticationCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.code_, from.extract_field("code")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeChatFolderInvite &to, JsonObject &from) {
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeInstantView &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  TRY_STATUS(from_json(to.fallback_url_, from.extract_field("fallback_url")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeNewGroupChat &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeProxy &to, JsonObject &from) {
  TRY_STATUS(from_json(to.proxy_, from.extract_field("proxy")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeStickerSet &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_set_name_, from.extract_field("sticker_set_name")));
  TRY_STATUS(from_json(to.expect_custom_emoji_, from.extract_field("expect_custom_emoji")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeWebApp &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_username_, from.extract_field("bot_username")));
  TRY_STATUS(from_json(to.web_app_short_name_, from.extract_field("web_app_short_name")));
  TRY_STATUS(from_json(to.start_parameter_, from.extract_field("start_parameter")));
  TRY_STATUS(from_json(to.mode_, from.extract_field("mode")));
  return Status::OK();
}

Status from_json(td_api::keyboardButton &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.icon_custom_emoji_id_, from.extract_field("icon_custom_emoji_id")));
  TRY_STATUS(from_json(to.style_, from.extract_field("style")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::keyboardButtonTypeRequestManagedBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.suggested_name_, from.extract_field("suggested_name")));
  TRY_STATUS(from_json(to.suggested_username_, from.extract_field("suggested_username")));
  return Status::OK();
}

Status from_json(td_api::location &to, JsonObject &from) {
  TRY_STATUS(from_json(to.latitude_, from.extract_field("latitude")));
  TRY_STATUS(from_json(to.longitude_, from.extract_field("longitude")));
  TRY_STATUS(from_json(to.horizontal_accuracy_, from.extract_field("horizontal_accuracy")));
  return Status::OK();
}

Status from_json(td_api::maskPosition &to, JsonObject &from) {
  TRY_STATUS(from_json(to.point_, from.extract_field("point")));
  TRY_STATUS(from_json(to.x_shift_, from.extract_field("x_shift")));
  TRY_STATUS(from_json(to.y_shift_, from.extract_field("y_shift")));
  TRY_STATUS(from_json(to.scale_, from.extract_field("scale")));
  return Status::OK();
}

Status from_json(td_api::messageSenderUser &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::messageSourceChatEventLog &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::networkStatisticsEntryCall &to, JsonObject &from) {
  TRY_STATUS(from_json(to.network_type_, from.extract_field("network_type")));
  TRY_STATUS(from_json(to.sent_bytes_, from.extract_field("sent_bytes")));
  TRY_STATUS(from_json(to.received_bytes_, from.extract_field("received_bytes")));
  TRY_STATUS(from_json(to.duration_, from.extract_field("duration")));
  return Status::OK();
}

Status from_json(td_api::notificationSettingsScopeChannelChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::passportElementTypePersonalDetails &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::passportElementTypePassportRegistration &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureIncreasedLimits &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureProfileBadge &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureBackgroundForBoth &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureTextComposition &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypePinnedSavedMessagesTopicCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeStorySuggestedReactionAreaCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumStoryFeaturePriorityOrder &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::profileTabMedia &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::proxyTypeMtproto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.secret_, from.extract_field("secret")));
  return Status::OK();
}

Status from_json(td_api::reactionTypePaid &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::reportReasonChildAbuse &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::scopeAutosaveSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.autosave_photos_, from.extract_field("autosave_photos")));
  TRY_STATUS(from_json(to.autosave_videos_, from.extract_field("autosave_videos")));
  TRY_STATUS(from_json(to.max_video_file_size_, from.extract_field("max_video_file_size")));
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterPhoto &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterMention &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::settingsSectionChatFolders &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::settingsSectionMyToncoins &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::shippingOption &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.price_parts_, from.extract_field("price_parts")));
  return Status::OK();
}

Status from_json(td_api::storePaymentPurposePremiumGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::storyContentTypePhoto &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::storyPrivacySettingsCloseFriends &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedActionRestorePremium &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedActionAddLoginPasskey &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::supergroupMembersFilterMention &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  return Status::OK();
}

Status from_json(td_api::telegramPaymentPurposeStars &to, JsonObject &from) {
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::textEntityTypeCashtag &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypeStrikethrough &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypeCustomEmoji &to, JsonObject &from) {
  TRY_STATUS(from_json(to.custom_emoji_id_, from.extract_field("custom_emoji_id")));
  return Status::OK();
}

Status from_json(td_api::topChatCategoryChannels &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::upgradedGiftAttributeIdBackdrop &to, JsonObject &from) {
  TRY_STATUS(from_json(to.backdrop_id_, from.extract_field("backdrop_id")));
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingAllowChatInvites &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingRuleAllowBots &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingRules &to, JsonObject &from) {
  TRY_STATUS(from_json(to.rules_, from.extract_field("rules")));
  return Status::OK();
}

Status from_json(td_api::activateStoryStealthMode &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::addFavoriteSticker &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  return Status::OK();
}

Status from_json(td_api::addPendingLiveStoryReaction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::addRecentlyFoundChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::answerInlineQuery &to, JsonObject &from) {
  TRY_STATUS(from_json(to.inline_query_id_, from.extract_field("inline_query_id")));
  TRY_STATUS(from_json(to.is_personal_, from.extract_field("is_personal")));
  TRY_STATUS(from_json(to.button_, from.extract_field("button")));
  TRY_STATUS(from_json(to.results_, from.extract_field("results")));
  TRY_STATUS(from_json(to.cache_time_, from.extract_field("cache_time")));
  TRY_STATUS(from_json(to.next_offset_, from.extract_field("next_offset")));
  return Status::OK();
}

Status from_json(td_api::blockMessageSenderFromReplies &to, JsonObject &from) {
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.delete_message_, from.extract_field("delete_message")));
  TRY_STATUS(from_json(to.delete_all_messages_, from.extract_field("delete_all_messages")));
  TRY_STATUS(from_json(to.report_spam_, from.extract_field("report_spam")));
  return Status::OK();
}

Status from_json(td_api::cancelDownloadFile &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  TRY_STATUS(from_json(to.only_if_pending_, from.extract_field("only_if_pending")));
  return Status::OK();
}

Status from_json(td_api::checkAuthenticationPasskey &to, JsonObject &from) {
  TRY_STATUS(from_json(to.credential_id_, from.extract_field("credential_id")));
  TRY_STATUS(from_json(to.client_data_, from.extract_field("client_data")));
  TRY_STATUS(from_json_bytes(to.authenticator_data_, from.extract_field("authenticator_data")));
  TRY_STATUS(from_json_bytes(to.signature_, from.extract_field("signature")));
  TRY_STATUS(from_json_bytes(to.user_handle_, from.extract_field("user_handle")));
  return Status::OK();
}

Status from_json(td_api::checkEmailAddressVerificationCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.code_, from.extract_field("code")));
  return Status::OK();
}

Status from_json(td_api::checkWebAppFileDownload &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.file_name_, from.extract_field("file_name")));
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::clearSearchedForTags &to, JsonObject &from) {
  TRY_STATUS(from_json(to.clear_cashtags_, from.extract_field("clear_cashtags")));
  return Status::OK();
}

Status from_json(td_api::closeStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  return Status::OK();
}

Status from_json(td_api::createBasicGroupChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.basic_group_id_, from.extract_field("basic_group_id")));
  TRY_STATUS(from_json(to.force_, from.extract_field("force")));
  return Status::OK();
}

Status from_json(td_api::createGiftCollection &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.received_gift_ids_, from.extract_field("received_gift_ids")));
  return Status::OK();
}

Status from_json(td_api::createStoryAlbum &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.story_ids_, from.extract_field("story_ids")));
  return Status::OK();
}

Status from_json(td_api::deleteAllCallMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.revoke_, from.extract_field("revoke")));
  return Status::OK();
}

Status from_json(td_api::deleteChatFolder &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_id_, from.extract_field("chat_folder_id")));
  TRY_STATUS(from_json(to.leave_chat_ids_, from.extract_field("leave_chat_ids")));
  return Status::OK();
}

Status from_json(td_api::deleteDirectMessagesChatTopicMessagesByDate &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.min_date_, from.extract_field("min_date")));
  TRY_STATUS(from_json(to.max_date_, from.extract_field("max_date")));
  return Status::OK();
}

Status from_json(td_api::deletePollOption &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.option_id_, from.extract_field("option_id")));
  return Status::OK();
}

Status from_json(td_api::deleteStickerSet &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::disconnectWebsite &to, JsonObject &from) {
  TRY_STATUS(from_json(to.website_id_, from.extract_field("website_id")));
  return Status::OK();
}

Status from_json(td_api::editBusinessMessageReplyMarkup &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  return Status::OK();
}

Status from_json(td_api::editInlineMessageCaption &to, JsonObject &from) {
  TRY_STATUS(from_json(to.inline_message_id_, from.extract_field("inline_message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  TRY_STATUS(from_json(to.show_caption_above_media_, from.extract_field("show_caption_above_media")));
  return Status::OK();
}

Status from_json(td_api::editMessageReplyMarkup &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  return Status::OK();
}

Status from_json(td_api::enableProxy &to, JsonObject &from) {
  TRY_STATUS(from_json(to.proxy_id_, from.extract_field("proxy_id")));
  return Status::OK();
}

Status from_json(td_api::getActiveSessions &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getAttachmentMenuBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  return Status::OK();
}

Status from_json(td_api::getBasicGroup &to, JsonObject &from) {
  TRY_STATUS(from_json(to.basic_group_id_, from.extract_field("basic_group_id")));
  return Status::OK();
}

Status from_json(td_api::getBotSimilarBots &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  return Status::OK();
}

Status from_json(td_api::getCallbackQueryMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.callback_query_id_, from.extract_field("callback_query_id")));
  return Status::OK();
}

Status from_json(td_api::getChatBoostLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getChatFolderInviteLinks &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_id_, from.extract_field("chat_folder_id")));
  return Status::OK();
}

Status from_json(td_api::getChatMember &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.member_id_, from.extract_field("member_id")));
  return Status::OK();
}

Status from_json(td_api::getChatRevenueStatistics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.is_dark_, from.extract_field("is_dark")));
  return Status::OK();
}

Status from_json(td_api::getChatStoryAlbums &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getConnectedAffiliatePrograms &to, JsonObject &from) {
  TRY_STATUS(from_json(to.affiliate_, from.extract_field("affiliate")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getCustomEmojiReactionAnimations &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getDefaultProfilePhotoCustomEmojiStickers &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getExternalLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_, from.extract_field("link")));
  TRY_STATUS(from_json(to.allow_write_access_, from.extract_field("allow_write_access")));
  return Status::OK();
}

Status from_json(td_api::getForumTopicHistory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  TRY_STATUS(from_json(to.from_message_id_, from.extract_field("from_message_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getGiftsForCrafting &to, JsonObject &from) {
  TRY_STATUS(from_json(to.regular_gift_id_, from.extract_field("regular_gift_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getImportedContactCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getJsonValue &to, JsonObject &from) {
  TRY_STATUS(from_json(to.json_, from.extract_field("json")));
  return Status::OK();
}

Status from_json(td_api::getLiveStoryTopDonors &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::getMainWebApp &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.start_parameter_, from.extract_field("start_parameter")));
  TRY_STATUS(from_json(to.parameters_, from.extract_field("parameters")));
  return Status::OK();
}

Status from_json(td_api::getMessageEffect &to, JsonObject &from) {
  TRY_STATUS(from_json(to.effect_id_, from.extract_field("effect_id")));
  return Status::OK();
}

Status from_json(td_api::getMessageReadDate &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::getOption &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::getPaymentForm &to, JsonObject &from) {
  TRY_STATUS(from_json(to.input_invoice_, from.extract_field("input_invoice")));
  TRY_STATUS(from_json(to.theme_, from.extract_field("theme")));
  return Status::OK();
}

Status from_json(td_api::getPremiumGiveawayPaymentOptions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.boosted_chat_id_, from.extract_field("boosted_chat_id")));
  return Status::OK();
}

Status from_json(td_api::getPublicPostSearchLimits &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  return Status::OK();
}

Status from_json(td_api::getRecentlyVisitedTMeUrls &to, JsonObject &from) {
  TRY_STATUS(from_json(to.referrer_, from.extract_field("referrer")));
  return Status::OK();
}

Status from_json(td_api::getSavedMessagesTopicMessageByDate &to, JsonObject &from) {
  TRY_STATUS(from_json(to.saved_messages_topic_id_, from.extract_field("saved_messages_topic_id")));
  TRY_STATUS(from_json(to.date_, from.extract_field("date")));
  return Status::OK();
}

Status from_json(td_api::getStarAdAccountUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  return Status::OK();
}

Status from_json(td_api::getStickerEmojis &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  return Status::OK();
}

Status from_json(td_api::getStoryAlbumStories &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.story_album_id_, from.extract_field("story_album_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getSuitablePersonalChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getThemedChatEmojiStatuses &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getUpgradedGiftEmojiStatuses &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getUserPrivacySettingRules &to, JsonObject &from) {
  TRY_STATUS(from_json(to.setting_, from.extract_field("setting")));
  return Status::OK();
}

Status from_json(td_api::getWebAppPlaceholder &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  return Status::OK();
}

Status from_json(td_api::inviteGroupCallParticipant &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.is_video_, from.extract_field("is_video")));
  return Status::OK();
}

Status from_json(td_api::launchPrepaidGiveaway &to, JsonObject &from) {
  TRY_STATUS(from_json(to.giveaway_id_, from.extract_field("giveaway_id")));
  TRY_STATUS(from_json(to.parameters_, from.extract_field("parameters")));
  TRY_STATUS(from_json(to.winner_count_, from.extract_field("winner_count")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::loadQuickReplyShortcuts &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::openSponsoredChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sponsored_chat_unique_id_, from.extract_field("sponsored_chat_unique_id")));
  return Status::OK();
}

Status from_json(td_api::postStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.content_, from.extract_field("content")));
  TRY_STATUS(from_json(to.areas_, from.extract_field("areas")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  TRY_STATUS(from_json(to.privacy_settings_, from.extract_field("privacy_settings")));
  TRY_STATUS(from_json(to.album_ids_, from.extract_field("album_ids")));
  TRY_STATUS(from_json(to.active_period_, from.extract_field("active_period")));
  TRY_STATUS(from_json(to.from_story_full_id_, from.extract_field("from_story_full_id")));
  TRY_STATUS(from_json(to.is_posted_to_chat_page_, from.extract_field("is_posted_to_chat_page")));
  TRY_STATUS(from_json(to.protect_content_, from.extract_field("protect_content")));
  return Status::OK();
}

Status from_json(td_api::readAllChatMentions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::readFilePart &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.count_, from.extract_field("count")));
  return Status::OK();
}

Status from_json(td_api::removeBusinessConnectedBotFromChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::removeMessageSenderBotVerification &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.verified_id_, from.extract_field("verified_id")));
  return Status::OK();
}

Status from_json(td_api::removeRecentlyFoundChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::reorderBotMediaPreviews &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  TRY_STATUS(from_json(to.file_ids_, from.extract_field("file_ids")));
  return Status::OK();
}

Status from_json(td_api::replaceLiveStoryRtmpUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::reportPhoneNumberCodeMissing &to, JsonObject &from) {
  TRY_STATUS(from_json(to.mobile_network_code_, from.extract_field("mobile_network_code")));
  return Status::OK();
}

Status from_json(td_api::resendAuthenticationCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.reason_, from.extract_field("reason")));
  return Status::OK();
}

Status from_json(td_api::resetNetworkStatistics &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchBackground &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::searchEmojis &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.input_language_codes_, from.extract_field("input_language_codes")));
  return Status::OK();
}

Status from_json(td_api::searchPublicMessagesByTag &to, JsonObject &from) {
  TRY_STATUS(from_json(to.tag_, from.extract_field("tag")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchStickerSet &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.ignore_cache_, from.extract_field("ignore_cache")));
  return Status::OK();
}

Status from_json(td_api::sendBotStartMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.parameter_, from.extract_field("parameter")));
  return Status::OK();
}

Status from_json(td_api::sendEmailAddressVerificationCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.email_address_, from.extract_field("email_address")));
  return Status::OK();
}

Status from_json(td_api::sendPaymentForm &to, JsonObject &from) {
  TRY_STATUS(from_json(to.input_invoice_, from.extract_field("input_invoice")));
  TRY_STATUS(from_json(to.payment_form_id_, from.extract_field("payment_form_id")));
  TRY_STATUS(from_json(to.order_info_id_, from.extract_field("order_info_id")));
  TRY_STATUS(from_json(to.shipping_option_id_, from.extract_field("shipping_option_id")));
  TRY_STATUS(from_json(to.credentials_, from.extract_field("credentials")));
  TRY_STATUS(from_json(to.tip_amount_, from.extract_field("tip_amount")));
  return Status::OK();
}

Status from_json(td_api::setAccountTtl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.ttl_, from.extract_field("ttl")));
  return Status::OK();
}

Status from_json(td_api::setBio &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bio_, from.extract_field("bio")));
  return Status::OK();
}

Status from_json(td_api::setBusinessAccountName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.first_name_, from.extract_field("first_name")));
  TRY_STATUS(from_json(to.last_name_, from.extract_field("last_name")));
  return Status::OK();
}

Status from_json(td_api::setBusinessStartPage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.start_page_, from.extract_field("start_page")));
  return Status::OK();
}

Status from_json(td_api::setChatDiscussionGroup &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.discussion_chat_id_, from.extract_field("discussion_chat_id")));
  return Status::OK();
}

Status from_json(td_api::setChatPaidMessageStarCount &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.paid_message_star_count_, from.extract_field("paid_message_star_count")));
  return Status::OK();
}

Status from_json(td_api::setCommands &to, JsonObject &from) {
  TRY_STATUS(from_json(to.scope_, from.extract_field("scope")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  TRY_STATUS(from_json(to.commands_, from.extract_field("commands")));
  return Status::OK();
}

Status from_json(td_api::setDefaultReactionType &to, JsonObject &from) {
  TRY_STATUS(from_json(to.reaction_type_, from.extract_field("reaction_type")));
  return Status::OK();
}

Status from_json(td_api::setGroupCallPaidMessageStarCount &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.paid_message_star_count_, from.extract_field("paid_message_star_count")));
  return Status::OK();
}

Status from_json(td_api::setLoginEmailAddress &to, JsonObject &from) {
  TRY_STATUS(from_json(to.new_login_email_address_, from.extract_field("new_login_email_address")));
  return Status::OK();
}

Status from_json(td_api::setNewChatPrivacySettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.settings_, from.extract_field("settings")));
  return Status::OK();
}

Status from_json(td_api::setPinnedGifts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.received_gift_ids_, from.extract_field("received_gift_ids")));
  return Status::OK();
}

Status from_json(td_api::setRecoveryEmailAddress &to, JsonObject &from) {
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  TRY_STATUS(from_json(to.new_recovery_email_address_, from.extract_field("new_recovery_email_address")));
  return Status::OK();
}

Status from_json(td_api::setStoryAlbumName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.story_album_id_, from.extract_field("story_album_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::setUpgradedGiftColors &to, JsonObject &from) {
  TRY_STATUS(from_json(to.upgraded_gift_colors_id_, from.extract_field("upgraded_gift_colors_id")));
  return Status::OK();
}

Status from_json(td_api::shareChatWithBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.source_, from.extract_field("source")));
  TRY_STATUS(from_json(to.button_id_, from.extract_field("button_id")));
  TRY_STATUS(from_json(to.shared_chat_id_, from.extract_field("shared_chat_id")));
  TRY_STATUS(from_json(to.only_check_, from.extract_field("only_check")));
  return Status::OK();
}

Status from_json(td_api::suggestUserBirthdate &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.birthdate_, from.extract_field("birthdate")));
  return Status::OK();
}

Status from_json(td_api::testCallVectorInt &to, JsonObject &from) {
  TRY_STATUS(from_json(to.x_, from.extract_field("x")));
  return Status::OK();
}

Status from_json(td_api::testUseUpdate &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::toggleChatHasProtectedContent &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.has_protected_content_, from.extract_field("has_protected_content")));
  return Status::OK();
}

Status from_json(td_api::toggleGeneralForumTopicIsHidden &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.is_hidden_, from.extract_field("is_hidden")));
  return Status::OK();
}

Status from_json(td_api::toggleSavedMessagesTopicIsPinned &to, JsonObject &from) {
  TRY_STATUS(from_json(to.saved_messages_topic_id_, from.extract_field("saved_messages_topic_id")));
  TRY_STATUS(from_json(to.is_pinned_, from.extract_field("is_pinned")));
  return Status::OK();
}

Status from_json(td_api::toggleSupergroupIsBroadcastGroup &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  return Status::OK();
}

Status from_json(td_api::transferBusinessAccountStars &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::upgradeBasicGroupChatToSupergroupChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::writeGeneratedFilePart &to, JsonObject &from) {
  TRY_STATUS(from_json(to.generation_id_, from.extract_field("generation_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json_bytes(to.data_, from.extract_field("data")));
  return Status::OK();
}

void to_json(JsonValueScope &jv, const td_api::addedReactions &object) {
  auto jo = jv.enter_object();
  jo("@type", "addedReactions");
  jo("total_count", object.total_count_);
  jo("reactions", ToJson(object.reactions_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::animatedEmoji &object) {
  auto jo = jv.enter_object();
  jo("@type", "animatedEmoji");
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
  jo("sticker_width", object.sticker_width_);
  jo("sticker_height", object.sticker_height_);
  jo("fitzpatrick_type", object.fitzpatrick_type_);
  if (object.sound_) {
    jo("sound", ToJson(*object.sound_));
  }
}

void to_json(JsonValueScope &jv, const td_api::AuctionState &object) {
  td_api::downcast_call(const_cast<td_api::AuctionState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::auctionStateActive &object) {
  auto jo = jv.enter_object();
  jo("@type", "auctionStateActive");
  jo("start_date", object.start_date_);
  jo("end_date", object.end_date_);
  jo("min_bid", object.min_bid_);
  jo("bid_levels", ToJson(object.bid_levels_));
  jo("top_bidder_user_ids", ToJson(object.top_bidder_user_ids_));
  jo("rounds", ToJson(object.rounds_));
  jo("current_round_end_date", object.current_round_end_date_);
  jo("current_round_number", object.current_round_number_);
  jo("total_round_count", object.total_round_count_);
  jo("distributed_item_count", object.distributed_item_count_);
  jo("left_item_count", object.left_item_count_);
  jo("acquired_item_count", object.acquired_item_count_);
  if (object.user_bid_) {
    jo("user_bid", ToJson(*object.user_bid_));
  }
}

void to_json(JsonValueScope &jv, const td_api::auctionStateFinished &object) {
  auto jo = jv.enter_object();
  jo("@type", "auctionStateFinished");
  jo("start_date", object.start_date_);
  jo("end_date", object.end_date_);
  jo("average_price", object.average_price_);
  jo("acquired_item_count", object.acquired_item_count_);
  jo("telegram_listed_item_count", object.telegram_listed_item_count_);
  jo("fragment_listed_item_count", object.fragment_listed_item_count_);
  jo("fragment_url", object.fragment_url_);
}

void to_json(JsonValueScope &jv, const td_api::autosaveSettingsException &object) {
  auto jo = jv.enter_object();
  jo("@type", "autosaveSettingsException");
  jo("chat_id", object.chat_id_);
  if (object.settings_) {
    jo("settings", ToJson(*object.settings_));
  }
}

void to_json(JsonValueScope &jv, const td_api::backgrounds &object) {
  auto jo = jv.enter_object();
  jo("@type", "backgrounds");
  jo("backgrounds", ToJson(object.backgrounds_));
}

void to_json(JsonValueScope &jv, const td_api::botInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "botInfo");
  jo("short_description", object.short_description_);
  jo("description", object.description_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
  jo("manager_bot_user_id", object.manager_bot_user_id_);
  if (object.menu_button_) {
    jo("menu_button", ToJson(*object.menu_button_));
  }
  jo("commands", ToJson(object.commands_));
  jo("privacy_policy_url", object.privacy_policy_url_);
  if (object.default_group_administrator_rights_) {
    jo("default_group_administrator_rights", ToJson(*object.default_group_administrator_rights_));
  }
  if (object.default_channel_administrator_rights_) {
    jo("default_channel_administrator_rights", ToJson(*object.default_channel_administrator_rights_));
  }
  if (object.affiliate_program_) {
    jo("affiliate_program", ToJson(*object.affiliate_program_));
  }
  jo("web_app_background_light_color", object.web_app_background_light_color_);
  jo("web_app_background_dark_color", object.web_app_background_dark_color_);
  jo("web_app_header_light_color", object.web_app_header_light_color_);
  jo("web_app_header_dark_color", object.web_app_header_dark_color_);
  if (object.verification_parameters_) {
    jo("verification_parameters", ToJson(*object.verification_parameters_));
  }
  jo("can_get_revenue_statistics", JsonBool{object.can_get_revenue_statistics_});
  jo("can_manage_emoji_status", JsonBool{object.can_manage_emoji_status_});
  jo("has_media_previews", JsonBool{object.has_media_previews_});
  if (object.edit_commands_link_) {
    jo("edit_commands_link", ToJson(*object.edit_commands_link_));
  }
  if (object.edit_description_link_) {
    jo("edit_description_link", ToJson(*object.edit_description_link_));
  }
  if (object.edit_description_media_link_) {
    jo("edit_description_media_link", ToJson(*object.edit_description_media_link_));
  }
  if (object.edit_settings_link_) {
    jo("edit_settings_link", ToJson(*object.edit_settings_link_));
  }
}

void to_json(JsonValueScope &jv, const td_api::BusinessAwayMessageSchedule &object) {
  td_api::downcast_call(const_cast<td_api::BusinessAwayMessageSchedule &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::businessAwayMessageScheduleAlways &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessAwayMessageScheduleAlways");
}

void to_json(JsonValueScope &jv, const td_api::businessAwayMessageScheduleOutsideOfOpeningHours &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessAwayMessageScheduleOutsideOfOpeningHours");
}

void to_json(JsonValueScope &jv, const td_api::businessAwayMessageScheduleCustom &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessAwayMessageScheduleCustom");
  jo("start_date", object.start_date_);
  jo("end_date", object.end_date_);
}

void to_json(JsonValueScope &jv, const td_api::BusinessFeature &object) {
  td_api::downcast_call(const_cast<td_api::BusinessFeature &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::businessFeatureLocation &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeatureLocation");
}

void to_json(JsonValueScope &jv, const td_api::businessFeatureOpeningHours &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeatureOpeningHours");
}

void to_json(JsonValueScope &jv, const td_api::businessFeatureQuickReplies &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeatureQuickReplies");
}

void to_json(JsonValueScope &jv, const td_api::businessFeatureGreetingMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeatureGreetingMessage");
}

void to_json(JsonValueScope &jv, const td_api::businessFeatureAwayMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeatureAwayMessage");
}

void to_json(JsonValueScope &jv, const td_api::businessFeatureAccountLinks &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeatureAccountLinks");
}

void to_json(JsonValueScope &jv, const td_api::businessFeatureStartPage &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeatureStartPage");
}

void to_json(JsonValueScope &jv, const td_api::businessFeatureBots &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeatureBots");
}

void to_json(JsonValueScope &jv, const td_api::businessFeatureEmojiStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeatureEmojiStatus");
}

void to_json(JsonValueScope &jv, const td_api::businessFeatureChatFolderTags &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeatureChatFolderTags");
}

void to_json(JsonValueScope &jv, const td_api::businessFeatureUpgradedStories &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessFeatureUpgradedStories");
}

void to_json(JsonValueScope &jv, const td_api::businessOpeningHoursInterval &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessOpeningHoursInterval");
  jo("start_minute", object.start_minute_);
  jo("end_minute", object.end_minute_);
}

void to_json(JsonValueScope &jv, const td_api::CallServerType &object) {
  td_api::downcast_call(const_cast<td_api::CallServerType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::callServerTypeTelegramReflector &object) {
  auto jo = jv.enter_object();
  jo("@type", "callServerTypeTelegramReflector");
  jo("peer_tag", base64_encode(object.peer_tag_));
  jo("is_tcp", JsonBool{object.is_tcp_});
}

void to_json(JsonValueScope &jv, const td_api::callServerTypeWebrtc &object) {
  auto jo = jv.enter_object();
  jo("@type", "callServerTypeWebrtc");
  jo("username", object.username_);
  jo("password", object.password_);
  jo("supports_turn", JsonBool{object.supports_turn_});
  jo("supports_stun", JsonBool{object.supports_stun_});
}

void to_json(JsonValueScope &jv, const td_api::ChatAction &object) {
  td_api::downcast_call(const_cast<td_api::ChatAction &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatActionTyping &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionTyping");
}

void to_json(JsonValueScope &jv, const td_api::chatActionRecordingVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionRecordingVideo");
}

void to_json(JsonValueScope &jv, const td_api::chatActionUploadingVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionUploadingVideo");
  jo("progress", object.progress_);
}

void to_json(JsonValueScope &jv, const td_api::chatActionRecordingVoiceNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionRecordingVoiceNote");
}

void to_json(JsonValueScope &jv, const td_api::chatActionUploadingVoiceNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionUploadingVoiceNote");
  jo("progress", object.progress_);
}

void to_json(JsonValueScope &jv, const td_api::chatActionUploadingPhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionUploadingPhoto");
  jo("progress", object.progress_);
}

void to_json(JsonValueScope &jv, const td_api::chatActionUploadingDocument &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionUploadingDocument");
  jo("progress", object.progress_);
}

void to_json(JsonValueScope &jv, const td_api::chatActionChoosingSticker &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionChoosingSticker");
}

void to_json(JsonValueScope &jv, const td_api::chatActionChoosingLocation &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionChoosingLocation");
}

void to_json(JsonValueScope &jv, const td_api::chatActionChoosingContact &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionChoosingContact");
}

void to_json(JsonValueScope &jv, const td_api::chatActionStartPlayingGame &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionStartPlayingGame");
}

void to_json(JsonValueScope &jv, const td_api::chatActionRecordingVideoNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionRecordingVideoNote");
}

void to_json(JsonValueScope &jv, const td_api::chatActionUploadingVideoNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionUploadingVideoNote");
  jo("progress", object.progress_);
}

void to_json(JsonValueScope &jv, const td_api::chatActionWatchingAnimations &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionWatchingAnimations");
  jo("emoji", object.emoji_);
}

void to_json(JsonValueScope &jv, const td_api::chatActionCancel &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatActionCancel");
}

void to_json(JsonValueScope &jv, const td_api::chatBoostFeatures &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatBoostFeatures");
  jo("features", ToJson(object.features_));
  jo("min_profile_background_custom_emoji_boost_level", object.min_profile_background_custom_emoji_boost_level_);
  jo("min_background_custom_emoji_boost_level", object.min_background_custom_emoji_boost_level_);
  jo("min_emoji_status_boost_level", object.min_emoji_status_boost_level_);
  jo("min_chat_theme_background_boost_level", object.min_chat_theme_background_boost_level_);
  jo("min_custom_background_boost_level", object.min_custom_background_boost_level_);
  jo("min_custom_emoji_sticker_set_boost_level", object.min_custom_emoji_sticker_set_boost_level_);
  jo("min_automatic_translation_boost_level", object.min_automatic_translation_boost_level_);
  jo("min_speech_recognition_boost_level", object.min_speech_recognition_boost_level_);
  jo("min_sponsored_message_disable_boost_level", object.min_sponsored_message_disable_boost_level_);
}

void to_json(JsonValueScope &jv, const td_api::ChatEventAction &object) {
  td_api::downcast_call(const_cast<td_api::ChatEventAction &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatEventMessageEdited &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMessageEdited");
  if (object.old_message_) {
    jo("old_message", ToJson(*object.old_message_));
  }
  if (object.new_message_) {
    jo("new_message", ToJson(*object.new_message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventMessageDeleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMessageDeleted");
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
  jo("can_report_anti_spam_false_positive", JsonBool{object.can_report_anti_spam_false_positive_});
}

void to_json(JsonValueScope &jv, const td_api::chatEventMessagePinned &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMessagePinned");
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventMessageUnpinned &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMessageUnpinned");
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventPollStopped &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventPollStopped");
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventMemberJoined &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMemberJoined");
}

void to_json(JsonValueScope &jv, const td_api::chatEventMemberJoinedByInviteLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMemberJoinedByInviteLink");
  if (object.invite_link_) {
    jo("invite_link", ToJson(*object.invite_link_));
  }
  jo("via_chat_folder_invite_link", JsonBool{object.via_chat_folder_invite_link_});
}

void to_json(JsonValueScope &jv, const td_api::chatEventMemberJoinedByRequest &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMemberJoinedByRequest");
  jo("approver_user_id", object.approver_user_id_);
  if (object.invite_link_) {
    jo("invite_link", ToJson(*object.invite_link_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventMemberInvited &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMemberInvited");
  jo("user_id", object.user_id_);
  if (object.status_) {
    jo("status", ToJson(*object.status_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventMemberLeft &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMemberLeft");
}

void to_json(JsonValueScope &jv, const td_api::chatEventMemberPromoted &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMemberPromoted");
  jo("user_id", object.user_id_);
  if (object.old_status_) {
    jo("old_status", ToJson(*object.old_status_));
  }
  if (object.new_status_) {
    jo("new_status", ToJson(*object.new_status_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventMemberRestricted &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMemberRestricted");
  if (object.member_id_) {
    jo("member_id", ToJson(*object.member_id_));
  }
  if (object.old_status_) {
    jo("old_status", ToJson(*object.old_status_));
  }
  if (object.new_status_) {
    jo("new_status", ToJson(*object.new_status_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventMemberTagChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMemberTagChanged");
  jo("user_id", object.user_id_);
  jo("old_tag", object.old_tag_);
  jo("new_tag", object.new_tag_);
}

void to_json(JsonValueScope &jv, const td_api::chatEventMemberSubscriptionExtended &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMemberSubscriptionExtended");
  jo("user_id", object.user_id_);
  if (object.old_status_) {
    jo("old_status", ToJson(*object.old_status_));
  }
  if (object.new_status_) {
    jo("new_status", ToJson(*object.new_status_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventAvailableReactionsChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventAvailableReactionsChanged");
  if (object.old_available_reactions_) {
    jo("old_available_reactions", ToJson(*object.old_available_reactions_));
  }
  if (object.new_available_reactions_) {
    jo("new_available_reactions", ToJson(*object.new_available_reactions_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventBackgroundChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventBackgroundChanged");
  if (object.old_background_) {
    jo("old_background", ToJson(*object.old_background_));
  }
  if (object.new_background_) {
    jo("new_background", ToJson(*object.new_background_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventDescriptionChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventDescriptionChanged");
  jo("old_description", object.old_description_);
  jo("new_description", object.new_description_);
}

void to_json(JsonValueScope &jv, const td_api::chatEventEmojiStatusChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventEmojiStatusChanged");
  if (object.old_emoji_status_) {
    jo("old_emoji_status", ToJson(*object.old_emoji_status_));
  }
  if (object.new_emoji_status_) {
    jo("new_emoji_status", ToJson(*object.new_emoji_status_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventLinkedChatChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventLinkedChatChanged");
  jo("old_linked_chat_id", object.old_linked_chat_id_);
  jo("new_linked_chat_id", object.new_linked_chat_id_);
}

void to_json(JsonValueScope &jv, const td_api::chatEventLocationChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventLocationChanged");
  if (object.old_location_) {
    jo("old_location", ToJson(*object.old_location_));
  }
  if (object.new_location_) {
    jo("new_location", ToJson(*object.new_location_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventMessageAutoDeleteTimeChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventMessageAutoDeleteTimeChanged");
  jo("old_message_auto_delete_time", object.old_message_auto_delete_time_);
  jo("new_message_auto_delete_time", object.new_message_auto_delete_time_);
}

void to_json(JsonValueScope &jv, const td_api::chatEventPermissionsChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventPermissionsChanged");
  if (object.old_permissions_) {
    jo("old_permissions", ToJson(*object.old_permissions_));
  }
  if (object.new_permissions_) {
    jo("new_permissions", ToJson(*object.new_permissions_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventPhotoChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventPhotoChanged");
  if (object.old_photo_) {
    jo("old_photo", ToJson(*object.old_photo_));
  }
  if (object.new_photo_) {
    jo("new_photo", ToJson(*object.new_photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventSlowModeDelayChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventSlowModeDelayChanged");
  jo("old_slow_mode_delay", object.old_slow_mode_delay_);
  jo("new_slow_mode_delay", object.new_slow_mode_delay_);
}

void to_json(JsonValueScope &jv, const td_api::chatEventStickerSetChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventStickerSetChanged");
  jo("old_sticker_set_id", ToJson(JsonInt64{object.old_sticker_set_id_}));
  jo("new_sticker_set_id", ToJson(JsonInt64{object.new_sticker_set_id_}));
}

void to_json(JsonValueScope &jv, const td_api::chatEventCustomEmojiStickerSetChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventCustomEmojiStickerSetChanged");
  jo("old_sticker_set_id", ToJson(JsonInt64{object.old_sticker_set_id_}));
  jo("new_sticker_set_id", ToJson(JsonInt64{object.new_sticker_set_id_}));
}

void to_json(JsonValueScope &jv, const td_api::chatEventTitleChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventTitleChanged");
  jo("old_title", object.old_title_);
  jo("new_title", object.new_title_);
}

void to_json(JsonValueScope &jv, const td_api::chatEventUsernameChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventUsernameChanged");
  jo("old_username", object.old_username_);
  jo("new_username", object.new_username_);
}

void to_json(JsonValueScope &jv, const td_api::chatEventActiveUsernamesChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventActiveUsernamesChanged");
  jo("old_usernames", ToJson(object.old_usernames_));
  jo("new_usernames", ToJson(object.new_usernames_));
}

void to_json(JsonValueScope &jv, const td_api::chatEventAccentColorChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventAccentColorChanged");
  jo("old_accent_color_id", object.old_accent_color_id_);
  jo("old_background_custom_emoji_id", ToJson(JsonInt64{object.old_background_custom_emoji_id_}));
  jo("new_accent_color_id", object.new_accent_color_id_);
  jo("new_background_custom_emoji_id", ToJson(JsonInt64{object.new_background_custom_emoji_id_}));
}

void to_json(JsonValueScope &jv, const td_api::chatEventProfileAccentColorChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventProfileAccentColorChanged");
  jo("old_profile_accent_color_id", object.old_profile_accent_color_id_);
  jo("old_profile_background_custom_emoji_id", ToJson(JsonInt64{object.old_profile_background_custom_emoji_id_}));
  jo("new_profile_accent_color_id", object.new_profile_accent_color_id_);
  jo("new_profile_background_custom_emoji_id", ToJson(JsonInt64{object.new_profile_background_custom_emoji_id_}));
}

void to_json(JsonValueScope &jv, const td_api::chatEventHasProtectedContentToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventHasProtectedContentToggled");
  jo("has_protected_content", JsonBool{object.has_protected_content_});
}

void to_json(JsonValueScope &jv, const td_api::chatEventInvitesToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventInvitesToggled");
  jo("can_invite_users", JsonBool{object.can_invite_users_});
}

void to_json(JsonValueScope &jv, const td_api::chatEventIsAllHistoryAvailableToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventIsAllHistoryAvailableToggled");
  jo("is_all_history_available", JsonBool{object.is_all_history_available_});
}

void to_json(JsonValueScope &jv, const td_api::chatEventHasAggressiveAntiSpamEnabledToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventHasAggressiveAntiSpamEnabledToggled");
  jo("has_aggressive_anti_spam_enabled", JsonBool{object.has_aggressive_anti_spam_enabled_});
}

void to_json(JsonValueScope &jv, const td_api::chatEventSignMessagesToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventSignMessagesToggled");
  jo("sign_messages", JsonBool{object.sign_messages_});
}

void to_json(JsonValueScope &jv, const td_api::chatEventShowMessageSenderToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventShowMessageSenderToggled");
  jo("show_message_sender", JsonBool{object.show_message_sender_});
}

void to_json(JsonValueScope &jv, const td_api::chatEventAutomaticTranslationToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventAutomaticTranslationToggled");
  jo("has_automatic_translation", JsonBool{object.has_automatic_translation_});
}

void to_json(JsonValueScope &jv, const td_api::chatEventInviteLinkEdited &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventInviteLinkEdited");
  if (object.old_invite_link_) {
    jo("old_invite_link", ToJson(*object.old_invite_link_));
  }
  if (object.new_invite_link_) {
    jo("new_invite_link", ToJson(*object.new_invite_link_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventInviteLinkRevoked &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventInviteLinkRevoked");
  if (object.invite_link_) {
    jo("invite_link", ToJson(*object.invite_link_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventInviteLinkDeleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventInviteLinkDeleted");
  if (object.invite_link_) {
    jo("invite_link", ToJson(*object.invite_link_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventVideoChatCreated &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventVideoChatCreated");
  jo("group_call_id", object.group_call_id_);
}

void to_json(JsonValueScope &jv, const td_api::chatEventVideoChatEnded &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventVideoChatEnded");
  jo("group_call_id", object.group_call_id_);
}

void to_json(JsonValueScope &jv, const td_api::chatEventVideoChatMuteNewParticipantsToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventVideoChatMuteNewParticipantsToggled");
  jo("mute_new_participants", JsonBool{object.mute_new_participants_});
}

void to_json(JsonValueScope &jv, const td_api::chatEventVideoChatParticipantIsMutedToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventVideoChatParticipantIsMutedToggled");
  if (object.participant_id_) {
    jo("participant_id", ToJson(*object.participant_id_));
  }
  jo("is_muted", JsonBool{object.is_muted_});
}

void to_json(JsonValueScope &jv, const td_api::chatEventVideoChatParticipantVolumeLevelChanged &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventVideoChatParticipantVolumeLevelChanged");
  if (object.participant_id_) {
    jo("participant_id", ToJson(*object.participant_id_));
  }
  jo("volume_level", object.volume_level_);
}

void to_json(JsonValueScope &jv, const td_api::chatEventIsForumToggled &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventIsForumToggled");
  jo("is_forum", JsonBool{object.is_forum_});
}

void to_json(JsonValueScope &jv, const td_api::chatEventForumTopicCreated &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventForumTopicCreated");
  if (object.topic_info_) {
    jo("topic_info", ToJson(*object.topic_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventForumTopicEdited &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventForumTopicEdited");
  if (object.old_topic_info_) {
    jo("old_topic_info", ToJson(*object.old_topic_info_));
  }
  if (object.new_topic_info_) {
    jo("new_topic_info", ToJson(*object.new_topic_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventForumTopicToggleIsClosed &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventForumTopicToggleIsClosed");
  if (object.topic_info_) {
    jo("topic_info", ToJson(*object.topic_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventForumTopicToggleIsHidden &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventForumTopicToggleIsHidden");
  if (object.topic_info_) {
    jo("topic_info", ToJson(*object.topic_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventForumTopicDeleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventForumTopicDeleted");
  if (object.topic_info_) {
    jo("topic_info", ToJson(*object.topic_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatEventForumTopicPinned &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEventForumTopicPinned");
  if (object.old_topic_info_) {
    jo("old_topic_info", ToJson(*object.old_topic_info_));
  }
  if (object.new_topic_info_) {
    jo("new_topic_info", ToJson(*object.new_topic_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatInviteLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatInviteLink");
  jo("invite_link", object.invite_link_);
  jo("name", object.name_);
  jo("creator_user_id", object.creator_user_id_);
  jo("date", object.date_);
  jo("edit_date", object.edit_date_);
  jo("expiration_date", object.expiration_date_);
  if (object.subscription_pricing_) {
    jo("subscription_pricing", ToJson(*object.subscription_pricing_));
  }
  jo("member_limit", object.member_limit_);
  jo("member_count", object.member_count_);
  jo("expired_member_count", object.expired_member_count_);
  jo("pending_join_request_count", object.pending_join_request_count_);
  jo("creates_join_request", JsonBool{object.creates_join_request_});
  jo("is_primary", JsonBool{object.is_primary_});
  jo("is_revoked", JsonBool{object.is_revoked_});
}

void to_json(JsonValueScope &jv, const td_api::chatJoinRequests &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatJoinRequests");
  jo("total_count", object.total_count_);
  jo("requests", ToJson(object.requests_));
}

void to_json(JsonValueScope &jv, const td_api::chatMessageSenders &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatMessageSenders");
  jo("senders", ToJson(object.senders_));
}

void to_json(JsonValueScope &jv, const td_api::chatRevenueAmount &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatRevenueAmount");
  jo("cryptocurrency", object.cryptocurrency_);
  jo("total_amount", ToJson(JsonInt64{object.total_amount_}));
  jo("balance_amount", ToJson(JsonInt64{object.balance_amount_}));
  jo("available_amount", ToJson(JsonInt64{object.available_amount_}));
  jo("withdrawal_enabled", JsonBool{object.withdrawal_enabled_});
}

void to_json(JsonValueScope &jv, const td_api::chatStatisticsInviterInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatStatisticsInviterInfo");
  jo("user_id", object.user_id_);
  jo("added_member_count", object.added_member_count_);
}

void to_json(JsonValueScope &jv, const td_api::checklistTask &object) {
  auto jo = jv.enter_object();
  jo("@type", "checklistTask");
  jo("id", object.id_);
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  if (object.completed_by_) {
    jo("completed_by", ToJson(*object.completed_by_));
  }
  jo("completion_date", object.completion_date_);
}

void to_json(JsonValueScope &jv, const td_api::contact &object) {
  auto jo = jv.enter_object();
  jo("@type", "contact");
  jo("phone_number", object.phone_number_);
  jo("first_name", object.first_name_);
  jo("last_name", object.last_name_);
  jo("vcard", object.vcard_);
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::databaseStatistics &object) {
  auto jo = jv.enter_object();
  jo("@type", "databaseStatistics");
  jo("statistics", object.statistics_);
}

void to_json(JsonValueScope &jv, const td_api::DiffEntityType &object) {
  td_api::downcast_call(const_cast<td_api::DiffEntityType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::diffEntityTypeInsert &object) {
  auto jo = jv.enter_object();
  jo("@type", "diffEntityTypeInsert");
}

void to_json(JsonValueScope &jv, const td_api::diffEntityTypeReplace &object) {
  auto jo = jv.enter_object();
  jo("@type", "diffEntityTypeReplace");
  jo("old_text", object.old_text_);
}

void to_json(JsonValueScope &jv, const td_api::diffEntityTypeDelete &object) {
  auto jo = jv.enter_object();
  jo("@type", "diffEntityTypeDelete");
}

void to_json(JsonValueScope &jv, const td_api::emojiCategory &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiCategory");
  jo("name", object.name_);
  if (object.icon_) {
    jo("icon", ToJson(*object.icon_));
  }
  if (object.source_) {
    jo("source", ToJson(*object.source_));
  }
  jo("is_greeting", JsonBool{object.is_greeting_});
}

void to_json(JsonValueScope &jv, const td_api::emojiStatuses &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiStatuses");
  jo("emoji_statuses", ToJson(object.emoji_statuses_));
}

void to_json(JsonValueScope &jv, const td_api::fileDownload &object) {
  auto jo = jv.enter_object();
  jo("@type", "fileDownload");
  jo("file_id", object.file_id_);
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
  jo("add_date", object.add_date_);
  jo("complete_date", object.complete_date_);
  jo("is_paused", JsonBool{object.is_paused_});
}

void to_json(JsonValueScope &jv, const td_api::forumTopics &object) {
  auto jo = jv.enter_object();
  jo("@type", "forumTopics");
  jo("total_count", object.total_count_);
  jo("topics", ToJson(object.topics_));
  jo("next_offset_date", object.next_offset_date_);
  jo("next_offset_message_id", object.next_offset_message_id_);
  jo("next_offset_forum_topic_id", object.next_offset_forum_topic_id_);
}

void to_json(JsonValueScope &jv, const td_api::foundPositions &object) {
  auto jo = jv.enter_object();
  jo("@type", "foundPositions");
  jo("total_count", object.total_count_);
  jo("positions", ToJson(object.positions_));
}

void to_json(JsonValueScope &jv, const td_api::giftAuction &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftAuction");
  jo("id", object.id_);
  jo("gifts_per_round", object.gifts_per_round_);
  jo("start_date", object.start_date_);
}

void to_json(JsonValueScope &jv, const td_api::giftForResale &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftForResale");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  jo("received_gift_id", object.received_gift_id_);
}

void to_json(JsonValueScope &jv, const td_api::giftUpgradeVariants &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftUpgradeVariants");
  jo("models", ToJson(object.models_));
  jo("symbols", ToJson(object.symbols_));
  jo("backdrops", ToJson(object.backdrops_));
}

void to_json(JsonValueScope &jv, const td_api::groupCallInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "groupCallInfo");
  jo("group_call_id", object.group_call_id_);
  jo("join_payload", object.join_payload_);
}

void to_json(JsonValueScope &jv, const td_api::groupCallVideoSourceGroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "groupCallVideoSourceGroup");
  jo("semantics", object.semantics_);
  jo("source_ids", ToJson(object.source_ids_));
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResultsButton &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResultsButton");
  jo("text", object.text_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inputPollOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputPollOption");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::jsonObjectMember &object) {
  auto jo = jv.enter_object();
  jo("@type", "jsonObjectMember");
  jo("key", object.key_);
  if (object.value_) {
    jo("value", ToJson(*object.value_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreview &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreview");
  jo("url", object.url_);
  jo("display_url", object.display_url_);
  jo("site_name", object.site_name_);
  jo("title", object.title_);
  if (object.description_) {
    jo("description", ToJson(*object.description_));
  }
  jo("author", object.author_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("has_large_media", JsonBool{object.has_large_media_});
  jo("show_large_media", JsonBool{object.show_large_media_});
  jo("show_media_above_description", JsonBool{object.show_media_above_description_});
  jo("skip_confirmation", JsonBool{object.skip_confirmation_});
  jo("show_above_text", JsonBool{object.show_above_text_});
  jo("instant_view_version", object.instant_view_version_);
}

void to_json(JsonValueScope &jv, const td_api::LogStream &object) {
  td_api::downcast_call(const_cast<td_api::LogStream &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::logStreamDefault &object) {
  auto jo = jv.enter_object();
  jo("@type", "logStreamDefault");
}

void to_json(JsonValueScope &jv, const td_api::logStreamFile &object) {
  auto jo = jv.enter_object();
  jo("@type", "logStreamFile");
  jo("path", object.path_);
  jo("max_file_size", object.max_file_size_);
  jo("redirect_stderr", JsonBool{object.redirect_stderr_});
}

void to_json(JsonValueScope &jv, const td_api::logStreamEmpty &object) {
  auto jo = jv.enter_object();
  jo("@type", "logStreamEmpty");
}

void to_json(JsonValueScope &jv, const td_api::messageCalendar &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageCalendar");
  jo("total_count", object.total_count_);
  jo("days", ToJson(object.days_));
}

void to_json(JsonValueScope &jv, const td_api::messageInteractionInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageInteractionInfo");
  jo("view_count", object.view_count_);
  jo("forward_count", object.forward_count_);
  if (object.reply_info_) {
    jo("reply_info", ToJson(*object.reply_info_));
  }
  if (object.reactions_) {
    jo("reactions", ToJson(*object.reactions_));
  }
}

void to_json(JsonValueScope &jv, const td_api::MessageReadDate &object) {
  td_api::downcast_call(const_cast<td_api::MessageReadDate &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::messageReadDateRead &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageReadDateRead");
  jo("read_date", object.read_date_);
}

void to_json(JsonValueScope &jv, const td_api::messageReadDateUnread &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageReadDateUnread");
}

void to_json(JsonValueScope &jv, const td_api::messageReadDateTooOld &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageReadDateTooOld");
}

void to_json(JsonValueScope &jv, const td_api::messageReadDateUserPrivacyRestricted &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageReadDateUserPrivacyRestricted");
}

void to_json(JsonValueScope &jv, const td_api::messageReadDateMyPrivacyRestricted &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageReadDateMyPrivacyRestricted");
}

void to_json(JsonValueScope &jv, const td_api::messageThreadInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageThreadInfo");
  jo("chat_id", object.chat_id_);
  jo("message_thread_id", object.message_thread_id_);
  if (object.reply_info_) {
    jo("reply_info", ToJson(*object.reply_info_));
  }
  jo("unread_message_count", object.unread_message_count_);
  jo("messages", ToJson(object.messages_));
  if (object.draft_message_) {
    jo("draft_message", ToJson(*object.draft_message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::newChatPrivacySettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "newChatPrivacySettings");
  jo("allow_new_chats_from_unknown_users", JsonBool{object.allow_new_chats_from_unknown_users_});
  jo("incoming_paid_message_star_count", object.incoming_paid_message_star_count_);
}

void to_json(JsonValueScope &jv, const td_api::ok &object) {
  auto jo = jv.enter_object();
  jo("@type", "ok");
}

void to_json(JsonValueScope &jv, const td_api::pageBlockTableCell &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockTableCell");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("is_header", JsonBool{object.is_header_});
  jo("colspan", object.colspan_);
  jo("rowspan", object.rowspan_);
  if (object.align_) {
    jo("align", ToJson(*object.align_));
  }
  if (object.valign_) {
    jo("valign", ToJson(*object.valign_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passportElementError &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementError");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("message", object.message_);
  if (object.source_) {
    jo("source", ToJson(*object.source_));
  }
}

void to_json(JsonValueScope &jv, const td_api::PaymentFormType &object) {
  td_api::downcast_call(const_cast<td_api::PaymentFormType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::paymentFormTypeRegular &object) {
  auto jo = jv.enter_object();
  jo("@type", "paymentFormTypeRegular");
  if (object.invoice_) {
    jo("invoice", ToJson(*object.invoice_));
  }
  jo("payment_provider_user_id", object.payment_provider_user_id_);
  if (object.payment_provider_) {
    jo("payment_provider", ToJson(*object.payment_provider_));
  }
  jo("additional_payment_options", ToJson(object.additional_payment_options_));
  if (object.saved_order_info_) {
    jo("saved_order_info", ToJson(*object.saved_order_info_));
  }
  jo("saved_credentials", ToJson(object.saved_credentials_));
  jo("can_save_credentials", JsonBool{object.can_save_credentials_});
  jo("need_password", JsonBool{object.need_password_});
}

void to_json(JsonValueScope &jv, const td_api::paymentFormTypeStars &object) {
  auto jo = jv.enter_object();
  jo("@type", "paymentFormTypeStars");
  jo("star_count", object.star_count_);
}

void to_json(JsonValueScope &jv, const td_api::paymentFormTypeStarSubscription &object) {
  auto jo = jv.enter_object();
  jo("@type", "paymentFormTypeStarSubscription");
  if (object.pricing_) {
    jo("pricing", ToJson(*object.pricing_));
  }
}

void to_json(JsonValueScope &jv, const td_api::photo &object) {
  auto jo = jv.enter_object();
  jo("@type", "photo");
  jo("has_stickers", JsonBool{object.has_stickers_});
  if (object.minithumbnail_) {
    jo("minithumbnail", ToJson(*object.minithumbnail_));
  }
  jo("sizes", ToJson(object.sizes_));
}

void to_json(JsonValueScope &jv, const td_api::PremiumFeature &object) {
  td_api::downcast_call(const_cast<td_api::PremiumFeature &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureIncreasedLimits &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureIncreasedLimits");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureIncreasedUploadFileSize &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureIncreasedUploadFileSize");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureImprovedDownloadSpeed &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureImprovedDownloadSpeed");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureVoiceRecognition &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureVoiceRecognition");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureDisabledAds &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureDisabledAds");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureUniqueReactions &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureUniqueReactions");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureUniqueStickers &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureUniqueStickers");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureCustomEmoji &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureCustomEmoji");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureAdvancedChatManagement &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureAdvancedChatManagement");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureProfileBadge &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureProfileBadge");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureEmojiStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureEmojiStatus");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureAnimatedProfilePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureAnimatedProfilePhoto");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureForumTopicIcon &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureForumTopicIcon");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureAppIcons &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureAppIcons");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureRealTimeChatTranslation &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureRealTimeChatTranslation");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureUpgradedStories &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureUpgradedStories");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureChatBoost &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureChatBoost");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureAccentColor &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureAccentColor");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureBackgroundForBoth &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureBackgroundForBoth");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureSavedMessagesTags &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureSavedMessagesTags");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureMessagePrivacy &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureMessagePrivacy");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureLastSeenTimes &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureLastSeenTimes");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureBusiness &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureBusiness");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureMessageEffects &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureMessageEffects");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureChecklists &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureChecklists");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeaturePaidMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeaturePaidMessages");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureProtectPrivateChatContent &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureProtectPrivateChatContent");
}

void to_json(JsonValueScope &jv, const td_api::premiumFeatureTextComposition &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumFeatureTextComposition");
}

void to_json(JsonValueScope &jv, const td_api::PremiumLimitType &object) {
  td_api::downcast_call(const_cast<td_api::PremiumLimitType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeSupergroupCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeSupergroupCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypePinnedChatCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypePinnedChatCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeCreatedPublicChatCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeCreatedPublicChatCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeSavedAnimationCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeSavedAnimationCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeFavoriteStickerCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeFavoriteStickerCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeChatFolderCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeChatFolderCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeChatFolderChosenChatCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeChatFolderChosenChatCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypePinnedArchivedChatCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypePinnedArchivedChatCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypePinnedSavedMessagesTopicCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypePinnedSavedMessagesTopicCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeCaptionLength &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeCaptionLength");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeBioLength &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeBioLength");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeChatFolderInviteLinkCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeChatFolderInviteLinkCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeShareableChatFolderCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeShareableChatFolderCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeActiveStoryCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeActiveStoryCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeWeeklyPostedStoryCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeWeeklyPostedStoryCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeMonthlyPostedStoryCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeMonthlyPostedStoryCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeStoryCaptionLength &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeStoryCaptionLength");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeStorySuggestedReactionAreaCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeStorySuggestedReactionAreaCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeSimilarChatCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeSimilarChatCount");
}

void to_json(JsonValueScope &jv, const td_api::premiumLimitTypeOwnedBotCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimitTypeOwnedBotCount");
}

void to_json(JsonValueScope &jv, const td_api::profileAccentColors &object) {
  auto jo = jv.enter_object();
  jo("@type", "profileAccentColors");
  jo("palette_colors", ToJson(object.palette_colors_));
  jo("background_colors", ToJson(object.background_colors_));
  jo("story_colors", ToJson(object.story_colors_));
}

void to_json(JsonValueScope &jv, const td_api::pushReceiverId &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushReceiverId");
  jo("id", ToJson(JsonInt64{object.id_}));
}

void to_json(JsonValueScope &jv, const td_api::receivedGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "receivedGift");
  jo("received_gift_id", object.received_gift_id_);
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("unique_gift_number", object.unique_gift_number_);
  jo("is_private", JsonBool{object.is_private_});
  jo("is_saved", JsonBool{object.is_saved_});
  jo("is_pinned", JsonBool{object.is_pinned_});
  jo("can_be_upgraded", JsonBool{object.can_be_upgraded_});
  jo("can_be_transferred", JsonBool{object.can_be_transferred_});
  jo("was_refunded", JsonBool{object.was_refunded_});
  jo("date", object.date_);
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  jo("collection_ids", ToJson(object.collection_ids_));
  jo("sell_star_count", object.sell_star_count_);
  jo("prepaid_upgrade_star_count", object.prepaid_upgrade_star_count_);
  jo("is_upgrade_separate", JsonBool{object.is_upgrade_separate_});
  jo("transfer_star_count", object.transfer_star_count_);
  jo("drop_original_details_star_count", object.drop_original_details_star_count_);
  jo("next_transfer_date", object.next_transfer_date_);
  jo("next_resale_date", object.next_resale_date_);
  jo("export_date", object.export_date_);
  jo("prepaid_upgrade_hash", object.prepaid_upgrade_hash_);
  jo("craft_date", object.craft_date_);
}

void to_json(JsonValueScope &jv, const td_api::ReportSponsoredResult &object) {
  td_api::downcast_call(const_cast<td_api::ReportSponsoredResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::reportSponsoredResultOk &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportSponsoredResultOk");
}

void to_json(JsonValueScope &jv, const td_api::reportSponsoredResultFailed &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportSponsoredResultFailed");
}

void to_json(JsonValueScope &jv, const td_api::reportSponsoredResultOptionRequired &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportSponsoredResultOptionRequired");
  jo("title", object.title_);
  jo("options", ToJson(object.options_));
}

void to_json(JsonValueScope &jv, const td_api::reportSponsoredResultAdsHidden &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportSponsoredResultAdsHidden");
}

void to_json(JsonValueScope &jv, const td_api::reportSponsoredResultPremiumRequired &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportSponsoredResultPremiumRequired");
}

void to_json(JsonValueScope &jv, const td_api::savedMessagesTags &object) {
  auto jo = jv.enter_object();
  jo("@type", "savedMessagesTags");
  jo("tags", ToJson(object.tags_));
}

void to_json(JsonValueScope &jv, const td_api::sentWebAppMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "sentWebAppMessage");
  jo("inline_message_id", object.inline_message_id_);
}

void to_json(JsonValueScope &jv, const td_api::sponsoredChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "sponsoredChat");
  jo("unique_id", object.unique_id_);
  jo("chat_id", object.chat_id_);
  jo("sponsor_info", object.sponsor_info_);
  jo("additional_info", object.additional_info_);
}

void to_json(JsonValueScope &jv, const td_api::starGiveawayWinnerOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "starGiveawayWinnerOption");
  jo("winner_count", object.winner_count_);
  jo("won_star_count", object.won_star_count_);
  jo("is_default", JsonBool{object.is_default_});
}

void to_json(JsonValueScope &jv, const td_api::starTransaction &object) {
  auto jo = jv.enter_object();
  jo("@type", "starTransaction");
  jo("id", object.id_);
  if (object.star_amount_) {
    jo("star_amount", ToJson(*object.star_amount_));
  }
  jo("is_refund", JsonBool{object.is_refund_});
  jo("date", object.date_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::stickerSet &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickerSet");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("title", object.title_);
  jo("name", object.name_);
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  if (object.thumbnail_outline_) {
    jo("thumbnail_outline", ToJson(*object.thumbnail_outline_));
  }
  jo("is_owned", JsonBool{object.is_owned_});
  jo("is_installed", JsonBool{object.is_installed_});
  jo("is_archived", JsonBool{object.is_archived_});
  jo("is_official", JsonBool{object.is_official_});
  if (object.sticker_type_) {
    jo("sticker_type", ToJson(*object.sticker_type_));
  }
  jo("needs_repainting", JsonBool{object.needs_repainting_});
  jo("is_allowed_as_chat_emoji_status", JsonBool{object.is_allowed_as_chat_emoji_status_});
  jo("is_viewed", JsonBool{object.is_viewed_});
  jo("stickers", ToJson(object.stickers_));
  jo("emojis", ToJson(object.emojis_));
}

void to_json(JsonValueScope &jv, const td_api::stories &object) {
  auto jo = jv.enter_object();
  jo("@type", "stories");
  jo("total_count", object.total_count_);
  jo("stories", ToJson(object.stories_));
  jo("pinned_story_ids", ToJson(object.pinned_story_ids_));
}

void to_json(JsonValueScope &jv, const td_api::storyInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyInfo");
  jo("story_id", object.story_id_);
  jo("date", object.date_);
  jo("is_for_close_friends", JsonBool{object.is_for_close_friends_});
  jo("is_live", JsonBool{object.is_live_});
}

void to_json(JsonValueScope &jv, const td_api::storyStatistics &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyStatistics");
  if (object.story_interaction_graph_) {
    jo("story_interaction_graph", ToJson(*object.story_interaction_graph_));
  }
  if (object.story_reaction_graph_) {
    jo("story_reaction_graph", ToJson(*object.story_reaction_graph_));
  }
}

void to_json(JsonValueScope &jv, const td_api::tMeUrl &object) {
  auto jo = jv.enter_object();
  jo("@type", "tMeUrl");
  jo("url", object.url_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::testString &object) {
  auto jo = jv.enter_object();
  jo("@type", "testString");
  jo("value", object.value_);
}

void to_json(JsonValueScope &jv, const td_api::TextEntityType &object) {
  td_api::downcast_call(const_cast<td_api::TextEntityType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeMention &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeMention");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeHashtag &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeHashtag");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeCashtag &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeCashtag");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeBotCommand &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeBotCommand");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeUrl &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeUrl");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeEmailAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeEmailAddress");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypePhoneNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypePhoneNumber");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeBankCardNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeBankCardNumber");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeBold &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeBold");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeItalic &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeItalic");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeUnderline &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeUnderline");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeStrikethrough &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeStrikethrough");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeSpoiler &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeSpoiler");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeCode &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeCode");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypePre &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypePre");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypePreCode &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypePreCode");
  jo("language", object.language_);
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeBlockQuote &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeBlockQuote");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeExpandableBlockQuote &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeExpandableBlockQuote");
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeTextUrl &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeTextUrl");
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeMentionName &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeMentionName");
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeCustomEmoji &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeCustomEmoji");
  jo("custom_emoji_id", ToJson(JsonInt64{object.custom_emoji_id_}));
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeMediaTimestamp &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeMediaTimestamp");
  jo("media_timestamp", object.media_timestamp_);
}

void to_json(JsonValueScope &jv, const td_api::textEntityTypeDateTime &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntityTypeDateTime");
  jo("unix_time", object.unix_time_);
  if (object.formatting_type_) {
    jo("formatting_type", ToJson(*object.formatting_type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::tonTransaction &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonTransaction");
  jo("id", object.id_);
  jo("ton_amount", object.ton_amount_);
  jo("is_refund", JsonBool{object.is_refund_});
  jo("date", object.date_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::upgradedGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGift");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("regular_gift_id", ToJson(JsonInt64{object.regular_gift_id_}));
  jo("publisher_chat_id", object.publisher_chat_id_);
  jo("title", object.title_);
  jo("name", object.name_);
  jo("number", object.number_);
  jo("total_upgraded_count", object.total_upgraded_count_);
  jo("max_upgraded_count", object.max_upgraded_count_);
  jo("is_burned", JsonBool{object.is_burned_});
  jo("is_crafted", JsonBool{object.is_crafted_});
  jo("is_premium", JsonBool{object.is_premium_});
  jo("is_theme_available", JsonBool{object.is_theme_available_});
  jo("used_theme_chat_id", object.used_theme_chat_id_);
  if (object.host_id_) {
    jo("host_id", ToJson(*object.host_id_));
  }
  if (object.owner_id_) {
    jo("owner_id", ToJson(*object.owner_id_));
  }
  jo("owner_address", object.owner_address_);
  jo("owner_name", object.owner_name_);
  jo("gift_address", object.gift_address_);
  if (object.model_) {
    jo("model", ToJson(*object.model_));
  }
  if (object.symbol_) {
    jo("symbol", ToJson(*object.symbol_));
  }
  if (object.backdrop_) {
    jo("backdrop", ToJson(*object.backdrop_));
  }
  if (object.original_details_) {
    jo("original_details", ToJson(*object.original_details_));
  }
  if (object.colors_) {
    jo("colors", ToJson(*object.colors_));
  }
  if (object.resale_parameters_) {
    jo("resale_parameters", ToJson(*object.resale_parameters_));
  }
  jo("can_send_purchase_offer", JsonBool{object.can_send_purchase_offer_});
  jo("craft_probability_per_mille", object.craft_probability_per_mille_);
  jo("value_currency", object.value_currency_);
  jo("value_amount", object.value_amount_);
  jo("value_usd_amount", object.value_usd_amount_);
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftOriginalDetails &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftOriginalDetails");
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  if (object.receiver_id_) {
    jo("receiver_id", ToJson(*object.receiver_id_));
  }
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("date", object.date_);
}

void to_json(JsonValueScope &jv, const td_api::UserPrivacySettingRule &object) {
  td_api::downcast_call(const_cast<td_api::UserPrivacySettingRule &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingRuleAllowAll &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingRuleAllowAll");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingRuleAllowContacts &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingRuleAllowContacts");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingRuleAllowBots &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingRuleAllowBots");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingRuleAllowPremiumUsers &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingRuleAllowPremiumUsers");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingRuleAllowUsers &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingRuleAllowUsers");
  jo("user_ids", ToJson(object.user_ids_));
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingRuleAllowChatMembers &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingRuleAllowChatMembers");
  jo("chat_ids", ToJson(object.chat_ids_));
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingRuleRestrictAll &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingRuleRestrictAll");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingRuleRestrictContacts &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingRuleRestrictContacts");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingRuleRestrictBots &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingRuleRestrictBots");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingRuleRestrictUsers &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingRuleRestrictUsers");
  jo("user_ids", ToJson(object.user_ids_));
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingRuleRestrictChatMembers &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingRuleRestrictChatMembers");
  jo("chat_ids", ToJson(object.chat_ids_));
}

void to_json(JsonValueScope &jv, const td_api::VectorPathCommand &object) {
  td_api::downcast_call(const_cast<td_api::VectorPathCommand &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::vectorPathCommandLine &object) {
  auto jo = jv.enter_object();
  jo("@type", "vectorPathCommandLine");
  if (object.end_point_) {
    jo("end_point", ToJson(*object.end_point_));
  }
}

void to_json(JsonValueScope &jv, const td_api::vectorPathCommandCubicBezierCurve &object) {
  auto jo = jv.enter_object();
  jo("@type", "vectorPathCommandCubicBezierCurve");
  if (object.start_control_point_) {
    jo("start_control_point", ToJson(*object.start_control_point_));
  }
  if (object.end_control_point_) {
    jo("end_control_point", ToJson(*object.end_control_point_));
  }
  if (object.end_point_) {
    jo("end_point", ToJson(*object.end_point_));
  }
}

void to_json(JsonValueScope &jv, const td_api::voiceNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "voiceNote");
  jo("duration", object.duration_);
  jo("waveform", base64_encode(object.waveform_));
  jo("mime_type", object.mime_type_);
  if (object.speech_recognition_result_) {
    jo("speech_recognition_result", ToJson(*object.speech_recognition_result_));
  }
  if (object.voice_) {
    jo("voice", ToJson(*object.voice_));
  }
}

}  // namespace td_api
}  // namespace td
