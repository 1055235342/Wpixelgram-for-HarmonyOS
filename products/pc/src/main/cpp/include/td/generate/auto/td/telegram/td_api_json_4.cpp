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
Result<int32> tl_constructor_from_string(td_api::AutosaveSettingsScope *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"autosaveSettingsScopePrivateChats", 1395227007},
    {"autosaveSettingsScopeGroupChats", 853544526},
    {"autosaveSettingsScopeChannelChats", -499572783},
    {"autosaveSettingsScopeChat", -1632255255}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::CallbackQueryPayload *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"callbackQueryPayloadData", -1977729946},
    {"callbackQueryPayloadDataWithPassword", 1340266738},
    {"callbackQueryPayloadGame", 1303571512}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::DateTimePartPrecision *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"dateTimePartPrecisionNone", 1790302111},
    {"dateTimePartPrecisionShort", 1290158159},
    {"dateTimePartPrecisionLong", -105378824}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::GroupCallDataChannel *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"groupCallDataChannelMain", -32177779},
    {"groupCallDataChannelScreenSharing", -601649103}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputFile *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputFileId", 1788906253},
    {"inputFileRemote", -107574466},
    {"inputFileLocal", 2056030919},
    {"inputFileGenerated", -1333385216}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputPollType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputPollTypeRegular", -236313041},
    {"inputPollTypeQuiz", 877110410}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::MaskPoint *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"maskPointForehead", 1027512005},
    {"maskPointEyes", 1748310861},
    {"maskPointMouth", 411773406},
    {"maskPointChin", 534995335}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::OptionValue *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"optionValueBoolean", 63135518},
    {"optionValueEmpty", 918955155},
    {"optionValueInteger", -186858780},
    {"optionValueString", 756248212}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ProxyType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"proxyTypeSocks5", -890027341},
    {"proxyTypeHttp", -1547188361},
    {"proxyTypeMtproto", -1964826627}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::SettingsSection *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"settingsSectionSendGift", -326078}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::SuggestedPostPrice *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"suggestedPostPriceStar", 216488903},
    {"suggestedPostPriceTon", -1095222334}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::UserPrivacySetting *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"userPrivacySettingAllowUnpaidMessages", 1430051047}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Status from_json(td_api::affiliateProgramSortOrderRevenue &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::autosaveSettingsScopeChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::blockListMain &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::botCommandScopeChatMember &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::businessFeatureOpeningHours &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessFeatureUpgradedStories &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::buttonStyleSuccess &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::callProblemPixelatedVideo &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatActionUploadingVoiceNote &to, JsonObject &from) {
  TRY_STATUS(from_json(to.progress_, from.extract_field("progress")));
  return Status::OK();
}

Status from_json(td_api::chatActionWatchingAnimations &to, JsonObject &from) {
  TRY_STATUS(from_json(to.emoji_, from.extract_field("emoji")));
  return Status::OK();
}

Status from_json(td_api::chatInviteLinkMember &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.joined_chat_date_, from.extract_field("joined_chat_date")));
  TRY_STATUS(from_json(to.via_chat_folder_invite_link_, from.extract_field("via_chat_folder_invite_link")));
  TRY_STATUS(from_json(to.approver_user_id_, from.extract_field("approver_user_id")));
  return Status::OK();
}

Status from_json(td_api::chatMemberStatusRestricted &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_member_, from.extract_field("is_member")));
  TRY_STATUS(from_json(to.restricted_until_date_, from.extract_field("restricted_until_date")));
  TRY_STATUS(from_json(to.permissions_, from.extract_field("permissions")));
  return Status::OK();
}

Status from_json(td_api::chatMembersFilterBots &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::date &to, JsonObject &from) {
  TRY_STATUS(from_json(to.day_, from.extract_field("day")));
  TRY_STATUS(from_json(to.month_, from.extract_field("month")));
  TRY_STATUS(from_json(to.year_, from.extract_field("year")));
  return Status::OK();
}

Status from_json(td_api::deviceTokenWindowsPush &to, JsonObject &from) {
  TRY_STATUS(from_json(to.access_token_, from.extract_field("access_token")));
  return Status::OK();
}

Status from_json(td_api::draftMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.reply_to_, from.extract_field("reply_to")));
  TRY_STATUS(from_json(to.date_, from.extract_field("date")));
  TRY_STATUS(from_json(to.input_message_text_, from.extract_field("input_message_text")));
  TRY_STATUS(from_json(to.effect_id_, from.extract_field("effect_id")));
  TRY_STATUS(from_json(to.suggested_post_info_, from.extract_field("suggested_post_info")));
  return Status::OK();
}

Status from_json(td_api::emojiStatusTypeCustomEmoji &to, JsonObject &from) {
  TRY_STATUS(from_json(to.custom_emoji_id_, from.extract_field("custom_emoji_id")));
  return Status::OK();
}

Status from_json(td_api::fileTypePhoto &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeSelfDestructingVideoNote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeWallpaper &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::giftResalePriceTon &to, JsonObject &from) {
  TRY_STATUS(from_json(to.toncoin_cent_count_, from.extract_field("toncoin_cent_count")));
  return Status::OK();
}

Status from_json(td_api::importedContact &to, JsonObject &from) {
  TRY_STATUS(from_json(to.phone_number_, from.extract_field("phone_number")));
  TRY_STATUS(from_json(to.first_name_, from.extract_field("first_name")));
  TRY_STATUS(from_json(to.last_name_, from.extract_field("last_name")));
  TRY_STATUS(from_json(to.note_, from.extract_field("note")));
  return Status::OK();
}

Status from_json(td_api::inlineKeyboardButtonTypeBuy &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::inputBusinessChatLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  return Status::OK();
}

Status from_json(td_api::inputChatThemeGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::inputFileLocal &to, JsonObject &from) {
  TRY_STATUS(from_json(to.path_, from.extract_field("path")));
  return Status::OK();
}

Status from_json(td_api::inputInlineQueryResultDocument &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.description_, from.extract_field("description")));
  TRY_STATUS(from_json(to.document_url_, from.extract_field("document_url")));
  TRY_STATUS(from_json(to.mime_type_, from.extract_field("mime_type")));
  TRY_STATUS(from_json(to.thumbnail_url_, from.extract_field("thumbnail_url")));
  TRY_STATUS(from_json(to.thumbnail_width_, from.extract_field("thumbnail_width")));
  TRY_STATUS(from_json(to.thumbnail_height_, from.extract_field("thumbnail_height")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::inputInvoiceName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::inputMessageVideo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.video_, from.extract_field("video")));
  TRY_STATUS(from_json(to.thumbnail_, from.extract_field("thumbnail")));
  TRY_STATUS(from_json(to.cover_, from.extract_field("cover")));
  TRY_STATUS(from_json(to.start_timestamp_, from.extract_field("start_timestamp")));
  TRY_STATUS(from_json(to.added_sticker_file_ids_, from.extract_field("added_sticker_file_ids")));
  TRY_STATUS(from_json(to.duration_, from.extract_field("duration")));
  TRY_STATUS(from_json(to.width_, from.extract_field("width")));
  TRY_STATUS(from_json(to.height_, from.extract_field("height")));
  TRY_STATUS(from_json(to.supports_streaming_, from.extract_field("supports_streaming")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  TRY_STATUS(from_json(to.show_caption_above_media_, from.extract_field("show_caption_above_media")));
  TRY_STATUS(from_json(to.self_destruct_type_, from.extract_field("self_destruct_type")));
  TRY_STATUS(from_json(to.has_spoiler_, from.extract_field("has_spoiler")));
  return Status::OK();
}

Status from_json(td_api::inputMessagePoll &to, JsonObject &from) {
  TRY_STATUS(from_json(to.question_, from.extract_field("question")));
  TRY_STATUS(from_json(to.options_, from.extract_field("options")));
  TRY_STATUS(from_json(to.description_, from.extract_field("description")));
  TRY_STATUS(from_json(to.is_anonymous_, from.extract_field("is_anonymous")));
  TRY_STATUS(from_json(to.allows_multiple_answers_, from.extract_field("allows_multiple_answers")));
  TRY_STATUS(from_json(to.allows_revoting_, from.extract_field("allows_revoting")));
  TRY_STATUS(from_json(to.shuffle_options_, from.extract_field("shuffle_options")));
  TRY_STATUS(from_json(to.hide_results_until_closes_, from.extract_field("hide_results_until_closes")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  TRY_STATUS(from_json(to.open_period_, from.extract_field("open_period")));
  TRY_STATUS(from_json(to.close_date_, from.extract_field("close_date")));
  TRY_STATUS(from_json(to.is_closed_, from.extract_field("is_closed")));
  return Status::OK();
}

Status from_json(td_api::inputPaidMediaTypePhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.video_, from.extract_field("video")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementBankStatement &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bank_statement_, from.extract_field("bank_statement")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementErrorSourceFrontSide &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.file_hash_, from.extract_field("file_hash")));
  return Status::OK();
}

Status from_json(td_api::inputPollTypeRegular &to, JsonObject &from) {
  TRY_STATUS(from_json(to.allow_adding_options_, from.extract_field("allow_adding_options")));
  return Status::OK();
}

Status from_json(td_api::inputStoryAreaTypeLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeAttachmentMenuBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.target_chat_, from.extract_field("target_chat")));
  TRY_STATUS(from_json(to.bot_username_, from.extract_field("bot_username")));
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeChatBoost &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeGroupCall &to, JsonObject &from) {
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeNewChannelChat &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::internalLinkTypePremiumGiftPurchase &to, JsonObject &from) {
  TRY_STATUS(from_json(to.referrer_, from.extract_field("referrer")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeStarPurchase &to, JsonObject &from) {
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  TRY_STATUS(from_json(to.purpose_, from.extract_field("purpose")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeVideoChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_username_, from.extract_field("chat_username")));
  TRY_STATUS(from_json(to.invite_hash_, from.extract_field("invite_hash")));
  TRY_STATUS(from_json(to.is_live_stream_, from.extract_field("is_live_stream")));
  return Status::OK();
}

Status from_json(td_api::jsonValueObject &to, JsonObject &from) {
  TRY_STATUS(from_json(to.members_, from.extract_field("members")));
  return Status::OK();
}

Status from_json(td_api::keyboardButtonTypeRequestChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.chat_is_channel_, from.extract_field("chat_is_channel")));
  TRY_STATUS(from_json(to.restrict_chat_is_forum_, from.extract_field("restrict_chat_is_forum")));
  TRY_STATUS(from_json(to.chat_is_forum_, from.extract_field("chat_is_forum")));
  TRY_STATUS(from_json(to.restrict_chat_has_username_, from.extract_field("restrict_chat_has_username")));
  TRY_STATUS(from_json(to.chat_has_username_, from.extract_field("chat_has_username")));
  TRY_STATUS(from_json(to.chat_is_created_, from.extract_field("chat_is_created")));
  TRY_STATUS(from_json(to.user_administrator_rights_, from.extract_field("user_administrator_rights")));
  TRY_STATUS(from_json(to.bot_administrator_rights_, from.extract_field("bot_administrator_rights")));
  TRY_STATUS(from_json(to.bot_is_member_, from.extract_field("bot_is_member")));
  TRY_STATUS(from_json(to.request_title_, from.extract_field("request_title")));
  TRY_STATUS(from_json(to.request_username_, from.extract_field("request_username")));
  TRY_STATUS(from_json(to.request_photo_, from.extract_field("request_photo")));
  return Status::OK();
}

Status from_json(td_api::linkPreviewOptions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_disabled_, from.extract_field("is_disabled")));
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  TRY_STATUS(from_json(to.force_small_media_, from.extract_field("force_small_media")));
  TRY_STATUS(from_json(to.force_large_media_, from.extract_field("force_large_media")));
  TRY_STATUS(from_json(to.show_above_text_, from.extract_field("show_above_text")));
  return Status::OK();
}

Status from_json(td_api::maskPointChin &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageSendOptions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.suggested_post_info_, from.extract_field("suggested_post_info")));
  TRY_STATUS(from_json(to.disable_notification_, from.extract_field("disable_notification")));
  TRY_STATUS(from_json(to.from_background_, from.extract_field("from_background")));
  TRY_STATUS(from_json(to.protect_content_, from.extract_field("protect_content")));
  TRY_STATUS(from_json(to.allow_paid_broadcast_, from.extract_field("allow_paid_broadcast")));
  TRY_STATUS(from_json(to.paid_message_star_count_, from.extract_field("paid_message_star_count")));
  TRY_STATUS(from_json(to.update_order_of_installed_sticker_sets_, from.extract_field("update_order_of_installed_sticker_sets")));
  TRY_STATUS(from_json(to.scheduling_state_, from.extract_field("scheduling_state")));
  TRY_STATUS(from_json(to.effect_id_, from.extract_field("effect_id")));
  TRY_STATUS(from_json(to.sending_id_, from.extract_field("sending_id")));
  TRY_STATUS(from_json(to.only_preview_, from.extract_field("only_preview")));
  return Status::OK();
}

Status from_json(td_api::messageSourceSearch &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::networkStatisticsEntryFile &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_type_, from.extract_field("file_type")));
  TRY_STATUS(from_json(to.network_type_, from.extract_field("network_type")));
  TRY_STATUS(from_json(to.sent_bytes_, from.extract_field("sent_bytes")));
  TRY_STATUS(from_json(to.received_bytes_, from.extract_field("received_bytes")));
  return Status::OK();
}

Status from_json(td_api::notificationSettingsScopeGroupChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::paidReactionTypeChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::passportElementTypeRentalAgreement &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::phoneNumberCodeTypeConfirmOwnership &to, JsonObject &from) {
  TRY_STATUS(from_json(to.hash_, from.extract_field("hash")));
  return Status::OK();
}

Status from_json(td_api::premiumFeatureAdvancedChatManagement &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureAccentColor &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureProtectPrivateChatContent &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypePinnedArchivedChatCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeStoryCaptionLength &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumSourceSettings &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::profileTabGifts &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::proxyTypeHttp &to, JsonObject &from) {
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  TRY_STATUS(from_json(to.http_only_, from.extract_field("http_only")));
  return Status::OK();
}

Status from_json(td_api::reactionTypeCustomEmoji &to, JsonObject &from) {
  TRY_STATUS(from_json(to.custom_emoji_id_, from.extract_field("custom_emoji_id")));
  return Status::OK();
}

Status from_json(td_api::reportReasonPornography &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::resendCodeReasonVerificationFailed &to, JsonObject &from) {
  TRY_STATUS(from_json(to.error_message_, from.extract_field("error_message")));
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterDocument &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterVoiceAndVideoNote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::settingsSectionBusiness &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::settingsSectionMyStars &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::settingsSectionSendGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::storePaymentPurposePremiumSubscription &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_restore_, from.extract_field("is_restore")));
  TRY_STATUS(from_json(to.is_upgrade_, from.extract_field("is_upgrade")));
  return Status::OK();
}

Status from_json(td_api::storyAreaPosition &to, JsonObject &from) {
  TRY_STATUS(from_json(to.x_percentage_, from.extract_field("x_percentage")));
  TRY_STATUS(from_json(to.y_percentage_, from.extract_field("y_percentage")));
  TRY_STATUS(from_json(to.width_percentage_, from.extract_field("width_percentage")));
  TRY_STATUS(from_json(to.height_percentage_, from.extract_field("height_percentage")));
  TRY_STATUS(from_json(to.rotation_angle_, from.extract_field("rotation_angle")));
  TRY_STATUS(from_json(to.corner_radius_percentage_, from.extract_field("corner_radius_percentage")));
  return Status::OK();
}

Status from_json(td_api::storyPrivacySettingsContacts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.except_user_ids_, from.extract_field("except_user_ids")));
  return Status::OK();
}

Status from_json(td_api::suggestedActionUpgradePremium &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedActionSetLoginEmailAddress &to, JsonObject &from) {
  TRY_STATUS(from_json(to.can_be_hidden_, from.extract_field("can_be_hidden")));
  return Status::OK();
}

Status from_json(td_api::supergroupMembersFilterBanned &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  return Status::OK();
}

Status from_json(td_api::telegramPaymentPurposePremiumGiveaway &to, JsonObject &from) {
  TRY_STATUS(from_json(to.parameters_, from.extract_field("parameters")));
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  TRY_STATUS(from_json(to.winner_count_, from.extract_field("winner_count")));
  TRY_STATUS(from_json(to.month_count_, from.extract_field("month_count")));
  return Status::OK();
}

Status from_json(td_api::textEntityTypeHashtag &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypeUnderline &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypeMentionName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::topChatCategoryGroups &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::upgradedGiftAttributeIdSymbol &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_id_, from.extract_field("sticker_id")));
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingShowProfileAudio &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingRuleAllowContacts &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingRuleRestrictChatMembers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_ids_, from.extract_field("chat_ids")));
  return Status::OK();
}

Status from_json(td_api::acceptTermsOfService &to, JsonObject &from) {
  TRY_STATUS(from_json(to.terms_of_service_id_, from.extract_field("terms_of_service_id")));
  return Status::OK();
}

Status from_json(td_api::addCustomServerLanguagePack &to, JsonObject &from) {
  TRY_STATUS(from_json(to.language_pack_id_, from.extract_field("language_pack_id")));
  return Status::OK();
}

Status from_json(td_api::addOffer &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.options_, from.extract_field("options")));
  return Status::OK();
}

Status from_json(td_api::addRecentSticker &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_attached_, from.extract_field("is_attached")));
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  return Status::OK();
}

Status from_json(td_api::answerCustomQuery &to, JsonObject &from) {
  TRY_STATUS(from_json(to.custom_query_id_, from.extract_field("custom_query_id")));
  TRY_STATUS(from_json(to.data_, from.extract_field("data")));
  return Status::OK();
}

Status from_json(td_api::banGroupCallParticipants &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.user_ids_, from.extract_field("user_ids")));
  return Status::OK();
}

Status from_json(td_api::canTransferOwnership &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::checkAuthenticationEmailCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.code_, from.extract_field("code")));
  return Status::OK();
}

Status from_json(td_api::checkCreatedPublicChatsLimit &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::checkStickerSetName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::clearRecentlyFoundChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::closeSecretChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.secret_chat_id_, from.extract_field("secret_chat_id")));
  return Status::OK();
}

Status from_json(td_api::craftGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.received_gift_ids_, from.extract_field("received_gift_ids")));
  return Status::OK();
}

Status from_json(td_api::createForumTopic &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.is_name_implicit_, from.extract_field("is_name_implicit")));
  TRY_STATUS(from_json(to.icon_, from.extract_field("icon")));
  return Status::OK();
}

Status from_json(td_api::createSecretChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.secret_chat_id_, from.extract_field("secret_chat_id")));
  return Status::OK();
}

Status from_json(td_api::deleteAccount &to, JsonObject &from) {
  TRY_STATUS(from_json(to.reason_, from.extract_field("reason")));
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::deleteChatBackground &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.restore_previous_, from.extract_field("restore_previous")));
  return Status::OK();
}

Status from_json(td_api::deleteDirectMessagesChatTopicHistory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  return Status::OK();
}

Status from_json(td_api::deletePassportElement &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::deleteSavedOrderInfo &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::disconnectAllWebsites &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::editBusinessMessageMedia &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::editForumTopic &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.edit_icon_custom_emoji_, from.extract_field("edit_icon_custom_emoji")));
  TRY_STATUS(from_json(to.icon_custom_emoji_id_, from.extract_field("icon_custom_emoji_id")));
  return Status::OK();
}

Status from_json(td_api::editMessageMedia &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::editUserStarSubscription &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.telegram_payment_charge_id_, from.extract_field("telegram_payment_charge_id")));
  TRY_STATUS(from_json(to.is_canceled_, from.extract_field("is_canceled")));
  return Status::OK();
}

Status from_json(td_api::getAccountTtl &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getAttachedStickerSets &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  return Status::OK();
}

Status from_json(td_api::getBankCardInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bank_card_number_, from.extract_field("bank_card_number")));
  return Status::OK();
}

Status from_json(td_api::getBotSimilarBotCount &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.return_local_, from.extract_field("return_local")));
  return Status::OK();
}

Status from_json(td_api::getCallbackQueryAnswer &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.payload_, from.extract_field("payload")));
  return Status::OK();
}

Status from_json(td_api::getChatBoostLevelFeatures &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_channel_, from.extract_field("is_channel")));
  TRY_STATUS(from_json(to.level_, from.extract_field("level")));
  return Status::OK();
}

Status from_json(td_api::getChatFolderDefaultIconName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.folder_, from.extract_field("folder")));
  return Status::OK();
}

Status from_json(td_api::getChatListsToAddChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getChatPostedToChatPageStories &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.from_story_id_, from.extract_field("from_story_id")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getChatStatistics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.is_dark_, from.extract_field("is_dark")));
  return Status::OK();
}

Status from_json(td_api::getConnectedAffiliateProgram &to, JsonObject &from) {
  TRY_STATUS(from_json(to.affiliate_, from.extract_field("affiliate")));
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  return Status::OK();
}

Status from_json(td_api::getCurrentWeather &to, JsonObject &from) {
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  return Status::OK();
}

Status from_json(td_api::getDefaultMessageAutoDeleteTime &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getEmojiSuggestionsUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  return Status::OK();
}

Status from_json(td_api::getForumTopicDefaultIcons &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getGiftUpgradePreview &to, JsonObject &from) {
  TRY_STATUS(from_json(to.regular_gift_id_, from.extract_field("regular_gift_id")));
  return Status::OK();
}

Status from_json(td_api::getGroupsInCommon &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.offset_chat_id_, from.extract_field("offset_chat_id")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getJsonString &to, JsonObject &from) {
  TRY_STATUS(from_json(to.json_value_, from.extract_field("json_value")));
  return Status::OK();
}

Status from_json(td_api::getLiveStoryStreamer &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::getLoginUrlInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.button_id_, from.extract_field("button_id")));
  return Status::OK();
}

Status from_json(td_api::getMessageAvailableReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.row_size_, from.extract_field("row_size")));
  return Status::OK();
}

Status from_json(td_api::getMessagePublicForwards &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getOauthLinkInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  TRY_STATUS(from_json(to.in_app_origin_, from.extract_field("in_app_origin")));
  return Status::OK();
}

Status from_json(td_api::getPasswordState &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getPremiumGiftPaymentOptions &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getProxies &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getRecentlyOpenedChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getSavedMessagesTopicHistory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.saved_messages_topic_id_, from.extract_field("saved_messages_topic_id")));
  TRY_STATUS(from_json(to.from_message_id_, from.extract_field("from_message_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getStakeDiceState &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getStatisticalGraph &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  TRY_STATUS(from_json(to.x_, from.extract_field("x")));
  return Status::OK();
}

Status from_json(td_api::getStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  TRY_STATUS(from_json(to.only_local_, from.extract_field("only_local")));
  return Status::OK();
}

Status from_json(td_api::getSuitableDiscussionChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getThemeParametersJsonString &to, JsonObject &from) {
  TRY_STATUS(from_json(to.theme_, from.extract_field("theme")));
  return Status::OK();
}

Status from_json(td_api::getUpgradedGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::getUserLink &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getWebAppLinkUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.web_app_short_name_, from.extract_field("web_app_short_name")));
  TRY_STATUS(from_json(to.start_parameter_, from.extract_field("start_parameter")));
  TRY_STATUS(from_json(to.allow_write_access_, from.extract_field("allow_write_access")));
  TRY_STATUS(from_json(to.parameters_, from.extract_field("parameters")));
  return Status::OK();
}

Status from_json(td_api::increaseGiftAuctionBid &to, JsonObject &from) {
  TRY_STATUS(from_json(to.gift_id_, from.extract_field("gift_id")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::joinVideoChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.participant_id_, from.extract_field("participant_id")));
  TRY_STATUS(from_json(to.join_parameters_, from.extract_field("join_parameters")));
  TRY_STATUS(from_json(to.invite_hash_, from.extract_field("invite_hash")));
  return Status::OK();
}

Status from_json(td_api::loadQuickReplyShortcutMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shortcut_id_, from.extract_field("shortcut_id")));
  return Status::OK();
}

Status from_json(td_api::openMessageContent &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::placeGiftAuctionBid &to, JsonObject &from) {
  TRY_STATUS(from_json(to.gift_id_, from.extract_field("gift_id")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.is_private_, from.extract_field("is_private")));
  return Status::OK();
}

Status from_json(td_api::rateSpeechRecognition &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.is_good_, from.extract_field("is_good")));
  return Status::OK();
}

Status from_json(td_api::readChatList &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_list_, from.extract_field("chat_list")));
  return Status::OK();
}

Status from_json(td_api::removeAllFilesFromDownloads &to, JsonObject &from) {
  TRY_STATUS(from_json(to.only_active_, from.extract_field("only_active")));
  TRY_STATUS(from_json(to.only_completed_, from.extract_field("only_completed")));
  TRY_STATUS(from_json(to.delete_from_cache_, from.extract_field("delete_from_cache")));
  return Status::OK();
}

Status from_json(td_api::removeMessageReaction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reaction_type_, from.extract_field("reaction_type")));
  return Status::OK();
}

Status from_json(td_api::removeRecentSticker &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_attached_, from.extract_field("is_attached")));
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  return Status::OK();
}

Status from_json(td_api::reorderBotActiveUsernames &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.usernames_, from.extract_field("usernames")));
  return Status::OK();
}

Status from_json(td_api::reorderSupergroupActiveUsernames &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.usernames_, from.extract_field("usernames")));
  return Status::OK();
}

Status from_json(td_api::reportMessageReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.sender_id_, from.extract_field("sender_id")));
  return Status::OK();
}

Status from_json(td_api::requestQrCodeAuthentication &to, JsonObject &from) {
  TRY_STATUS(from_json(to.other_user_ids_, from.extract_field("other_user_ids")));
  return Status::OK();
}

Status from_json(td_api::resetInstalledBackgrounds &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchAffiliatePrograms &to, JsonObject &from) {
  TRY_STATUS(from_json(to.affiliate_, from.extract_field("affiliate")));
  TRY_STATUS(from_json(to.sort_order_, from.extract_field("sort_order")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchContacts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchPublicChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  return Status::OK();
}

Status from_json(td_api::searchSecretMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  TRY_STATUS(from_json(to.filter_, from.extract_field("filter")));
  return Status::OK();
}

Status from_json(td_api::sendAuthenticationFirebaseSms &to, JsonObject &from) {
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  return Status::OK();
}

Status from_json(td_api::sendCustomRequest &to, JsonObject &from) {
  TRY_STATUS(from_json(to.method_, from.extract_field("method")));
  TRY_STATUS(from_json(to.parameters_, from.extract_field("parameters")));
  return Status::OK();
}

Status from_json(td_api::sendPassportAuthorizationForm &to, JsonObject &from) {
  TRY_STATUS(from_json(to.authorization_form_id_, from.extract_field("authorization_form_id")));
  TRY_STATUS(from_json(to.types_, from.extract_field("types")));
  return Status::OK();
}

Status from_json(td_api::setAccentColor &to, JsonObject &from) {
  TRY_STATUS(from_json(to.accent_color_id_, from.extract_field("accent_color_id")));
  TRY_STATUS(from_json(to.background_custom_emoji_id_, from.extract_field("background_custom_emoji_id")));
  return Status::OK();
}

Status from_json(td_api::setAutosaveSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.scope_, from.extract_field("scope")));
  TRY_STATUS(from_json(to.settings_, from.extract_field("settings")));
  return Status::OK();
}

Status from_json(td_api::setBusinessAccountGiftSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.settings_, from.extract_field("settings")));
  return Status::OK();
}

Status from_json(td_api::setBusinessOpeningHours &to, JsonObject &from) {
  TRY_STATUS(from_json(to.opening_hours_, from.extract_field("opening_hours")));
  return Status::OK();
}

Status from_json(td_api::setChatDirectMessagesGroup &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.is_enabled_, from.extract_field("is_enabled")));
  TRY_STATUS(from_json(to.paid_message_star_count_, from.extract_field("paid_message_star_count")));
  return Status::OK();
}

Status from_json(td_api::setChatNotificationSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.notification_settings_, from.extract_field("notification_settings")));
  return Status::OK();
}

Status from_json(td_api::setCloseFriends &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_ids_, from.extract_field("user_ids")));
  return Status::OK();
}

Status from_json(td_api::setDefaultMessageAutoDeleteTime &to, JsonObject &from) {
  TRY_STATUS(from_json(to.message_auto_delete_time_, from.extract_field("message_auto_delete_time")));
  return Status::OK();
}

Status from_json(td_api::setGiftSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.settings_, from.extract_field("settings")));
  return Status::OK();
}

Status from_json(td_api::setLogVerbosityLevel &to, JsonObject &from) {
  TRY_STATUS(from_json(to.new_verbosity_level_, from.extract_field("new_verbosity_level")));
  return Status::OK();
}

Status from_json(td_api::setNetworkType &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::setPinnedForumTopics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_ids_, from.extract_field("forum_topic_ids")));
  return Status::OK();
}

Status from_json(td_api::setReadDatePrivacySettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.settings_, from.extract_field("settings")));
  return Status::OK();
}

Status from_json(td_api::setStickerSetTitle &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  return Status::OK();
}

Status from_json(td_api::setTdlibParameters &to, JsonObject &from) {
  TRY_STATUS(from_json(to.use_test_dc_, from.extract_field("use_test_dc")));
  TRY_STATUS(from_json(to.database_directory_, from.extract_field("database_directory")));
  TRY_STATUS(from_json(to.files_directory_, from.extract_field("files_directory")));
  TRY_STATUS(from_json_bytes(to.database_encryption_key_, from.extract_field("database_encryption_key")));
  TRY_STATUS(from_json(to.use_file_database_, from.extract_field("use_file_database")));
  TRY_STATUS(from_json(to.use_chat_info_database_, from.extract_field("use_chat_info_database")));
  TRY_STATUS(from_json(to.use_message_database_, from.extract_field("use_message_database")));
  TRY_STATUS(from_json(to.use_secret_chats_, from.extract_field("use_secret_chats")));
  TRY_STATUS(from_json(to.api_id_, from.extract_field("api_id")));
  TRY_STATUS(from_json(to.api_hash_, from.extract_field("api_hash")));
  TRY_STATUS(from_json(to.system_language_code_, from.extract_field("system_language_code")));
  TRY_STATUS(from_json(to.device_model_, from.extract_field("device_model")));
  TRY_STATUS(from_json(to.system_version_, from.extract_field("system_version")));
  TRY_STATUS(from_json(to.application_version_, from.extract_field("application_version")));
  return Status::OK();
}

Status from_json(td_api::setVideoChatTitle &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  return Status::OK();
}

Status from_json(td_api::stopPoll &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  return Status::OK();
}

Status from_json(td_api::testCallString &to, JsonObject &from) {
  TRY_STATUS(from_json(to.x_, from.extract_field("x")));
  return Status::OK();
}

Status from_json(td_api::testSquareInt &to, JsonObject &from) {
  TRY_STATUS(from_json(to.x_, from.extract_field("x")));
  return Status::OK();
}

Status from_json(td_api::toggleChatGiftNotifications &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.are_enabled_, from.extract_field("are_enabled")));
  return Status::OK();
}

Status from_json(td_api::toggleForumTopicIsPinned &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  TRY_STATUS(from_json(to.is_pinned_, from.extract_field("is_pinned")));
  return Status::OK();
}

Status from_json(td_api::toggleHasSponsoredMessagesEnabled &to, JsonObject &from) {
  TRY_STATUS(from_json(to.has_sponsored_messages_enabled_, from.extract_field("has_sponsored_messages_enabled")));
  return Status::OK();
}

Status from_json(td_api::toggleSupergroupIsAllHistoryAvailable &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.is_all_history_available_, from.extract_field("is_all_history_available")));
  return Status::OK();
}

Status from_json(td_api::toggleVideoChatMuteNewParticipants &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.mute_new_participants_, from.extract_field("mute_new_participants")));
  return Status::OK();
}

Status from_json(td_api::unpinChatMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::viewVideoMessageAdvertisement &to, JsonObject &from) {
  TRY_STATUS(from_json(to.advertisement_unique_id_, from.extract_field("advertisement_unique_id")));
  return Status::OK();
}

void to_json(JsonValueScope &jv, const td_api::addedReaction &object) {
  auto jo = jv.enter_object();
  jo("@type", "addedReaction");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  jo("is_outgoing", JsonBool{object.is_outgoing_});
  jo("date", object.date_);
}

void to_json(JsonValueScope &jv, const td_api::animatedChatPhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "animatedChatPhoto");
  jo("length", object.length_);
  if (object.file_) {
    jo("file", ToJson(*object.file_));
  }
  jo("main_frame_timestamp", object.main_frame_timestamp_);
}

void to_json(JsonValueScope &jv, const td_api::auctionRound &object) {
  auto jo = jv.enter_object();
  jo("@type", "auctionRound");
  jo("number", object.number_);
  jo("duration", object.duration_);
  jo("extend_time", object.extend_time_);
  jo("top_winner_count", object.top_winner_count_);
}

void to_json(JsonValueScope &jv, const td_api::autosaveSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "autosaveSettings");
  if (object.private_chat_settings_) {
    jo("private_chat_settings", ToJson(*object.private_chat_settings_));
  }
  if (object.group_settings_) {
    jo("group_settings", ToJson(*object.group_settings_));
  }
  if (object.channel_settings_) {
    jo("channel_settings", ToJson(*object.channel_settings_));
  }
  jo("exceptions", ToJson(object.exceptions_));
}

void to_json(JsonValueScope &jv, const td_api::BackgroundType &object) {
  td_api::downcast_call(const_cast<td_api::BackgroundType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::backgroundTypeWallpaper &object) {
  auto jo = jv.enter_object();
  jo("@type", "backgroundTypeWallpaper");
  jo("is_blurred", JsonBool{object.is_blurred_});
  jo("is_moving", JsonBool{object.is_moving_});
}

void to_json(JsonValueScope &jv, const td_api::backgroundTypePattern &object) {
  auto jo = jv.enter_object();
  jo("@type", "backgroundTypePattern");
  if (object.fill_) {
    jo("fill", ToJson(*object.fill_));
  }
  jo("intensity", object.intensity_);
  jo("is_inverted", JsonBool{object.is_inverted_});
  jo("is_moving", JsonBool{object.is_moving_});
}

void to_json(JsonValueScope &jv, const td_api::backgroundTypeFill &object) {
  auto jo = jv.enter_object();
  jo("@type", "backgroundTypeFill");
  if (object.fill_) {
    jo("fill", ToJson(*object.fill_));
  }
}

void to_json(JsonValueScope &jv, const td_api::backgroundTypeChatTheme &object) {
  auto jo = jv.enter_object();
  jo("@type", "backgroundTypeChatTheme");
  jo("theme_name", object.theme_name_);
}

void to_json(JsonValueScope &jv, const td_api::botCommands &object) {
  auto jo = jv.enter_object();
  jo("@type", "botCommands");
  jo("bot_user_id", object.bot_user_id_);
  jo("commands", ToJson(object.commands_));
}

void to_json(JsonValueScope &jv, const td_api::BuiltInTheme &object) {
  td_api::downcast_call(const_cast<td_api::BuiltInTheme &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::builtInThemeClassic &object) {
  auto jo = jv.enter_object();
  jo("@type", "builtInThemeClassic");
}

void to_json(JsonValueScope &jv, const td_api::builtInThemeDay &object) {
  auto jo = jv.enter_object();
  jo("@type", "builtInThemeDay");
}

void to_json(JsonValueScope &jv, const td_api::builtInThemeNight &object) {
  auto jo = jv.enter_object();
  jo("@type", "builtInThemeNight");
}

void to_json(JsonValueScope &jv, const td_api::builtInThemeTinted &object) {
  auto jo = jv.enter_object();
  jo("@type", "builtInThemeTinted");
}

void to_json(JsonValueScope &jv, const td_api::builtInThemeArctic &object) {
  auto jo = jv.enter_object();
  jo("@type", "builtInThemeArctic");
}

void to_json(JsonValueScope &jv, const td_api::businessConnection &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessConnection");
  jo("id", object.id_);
  jo("user_id", object.user_id_);
  jo("user_chat_id", object.user_chat_id_);
  jo("date", object.date_);
  if (object.rights_) {
    jo("rights", ToJson(*object.rights_));
  }
  jo("is_enabled", JsonBool{object.is_enabled_});
}

void to_json(JsonValueScope &jv, const td_api::businessOpeningHours &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessOpeningHours");
  jo("time_zone_id", object.time_zone_id_);
  jo("opening_hours", ToJson(object.opening_hours_));
}

void to_json(JsonValueScope &jv, const td_api::callServer &object) {
  auto jo = jv.enter_object();
  jo("@type", "callServer");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("ip_address", object.ip_address_);
  jo("ipv6_address", object.ipv6_address_);
  jo("port", object.port_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chat &object) {
  auto jo = jv.enter_object();
  jo("@type", "chat");
  jo("id", object.id_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("title", object.title_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("accent_color_id", object.accent_color_id_);
  jo("background_custom_emoji_id", ToJson(JsonInt64{object.background_custom_emoji_id_}));
  if (object.upgraded_gift_colors_) {
    jo("upgraded_gift_colors", ToJson(*object.upgraded_gift_colors_));
  }
  jo("profile_accent_color_id", object.profile_accent_color_id_);
  jo("profile_background_custom_emoji_id", ToJson(JsonInt64{object.profile_background_custom_emoji_id_}));
  if (object.permissions_) {
    jo("permissions", ToJson(*object.permissions_));
  }
  if (object.last_message_) {
    jo("last_message", ToJson(*object.last_message_));
  }
  jo("positions", ToJson(object.positions_));
  jo("chat_lists", ToJson(object.chat_lists_));
  if (object.message_sender_id_) {
    jo("message_sender_id", ToJson(*object.message_sender_id_));
  }
  if (object.block_list_) {
    jo("block_list", ToJson(*object.block_list_));
  }
  jo("has_protected_content", JsonBool{object.has_protected_content_});
  jo("is_translatable", JsonBool{object.is_translatable_});
  jo("is_marked_as_unread", JsonBool{object.is_marked_as_unread_});
  jo("view_as_topics", JsonBool{object.view_as_topics_});
  jo("has_scheduled_messages", JsonBool{object.has_scheduled_messages_});
  jo("can_be_deleted_only_for_self", JsonBool{object.can_be_deleted_only_for_self_});
  jo("can_be_deleted_for_all_users", JsonBool{object.can_be_deleted_for_all_users_});
  jo("can_be_reported", JsonBool{object.can_be_reported_});
  jo("default_disable_notification", JsonBool{object.default_disable_notification_});
  jo("unread_count", object.unread_count_);
  jo("last_read_inbox_message_id", object.last_read_inbox_message_id_);
  jo("last_read_outbox_message_id", object.last_read_outbox_message_id_);
  jo("unread_mention_count", object.unread_mention_count_);
  jo("unread_reaction_count", object.unread_reaction_count_);
  jo("unread_poll_vote_count", object.unread_poll_vote_count_);
  if (object.notification_settings_) {
    jo("notification_settings", ToJson(*object.notification_settings_));
  }
  if (object.available_reactions_) {
    jo("available_reactions", ToJson(*object.available_reactions_));
  }
  jo("message_auto_delete_time", object.message_auto_delete_time_);
  if (object.emoji_status_) {
    jo("emoji_status", ToJson(*object.emoji_status_));
  }
  if (object.background_) {
    jo("background", ToJson(*object.background_));
  }
  if (object.theme_) {
    jo("theme", ToJson(*object.theme_));
  }
  if (object.action_bar_) {
    jo("action_bar", ToJson(*object.action_bar_));
  }
  if (object.business_bot_manage_bar_) {
    jo("business_bot_manage_bar", ToJson(*object.business_bot_manage_bar_));
  }
  if (object.video_chat_) {
    jo("video_chat", ToJson(*object.video_chat_));
  }
  if (object.pending_join_requests_) {
    jo("pending_join_requests", ToJson(*object.pending_join_requests_));
  }
  jo("reply_markup_message_id", object.reply_markup_message_id_);
  if (object.draft_message_) {
    jo("draft_message", ToJson(*object.draft_message_));
  }
  jo("client_data", object.client_data_);
}

void to_json(JsonValueScope &jv, const td_api::chatBoost &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatBoost");
  jo("id", object.id_);
  jo("count", object.count_);
  if (object.source_) {
    jo("source", ToJson(*object.source_));
  }
  jo("start_date", object.start_date_);
  jo("expiration_date", object.expiration_date_);
}

void to_json(JsonValueScope &jv, const td_api::chatEvent &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatEvent");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("date", object.date_);
  if (object.member_id_) {
    jo("member_id", ToJson(*object.member_id_));
  }
  if (object.action_) {
    jo("action", ToJson(*object.action_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatFolderName &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatFolderName");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("animate_custom_emoji", JsonBool{object.animate_custom_emoji_});
}

void to_json(JsonValueScope &jv, const td_api::chatJoinRequest &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatJoinRequest");
  jo("user_id", object.user_id_);
  jo("date", object.date_);
  jo("bio", object.bio_);
}

void to_json(JsonValueScope &jv, const td_api::chatMessageSender &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatMessageSender");
  if (object.sender_) {
    jo("sender", ToJson(*object.sender_));
  }
  jo("needs_premium", JsonBool{object.needs_premium_});
}

void to_json(JsonValueScope &jv, const td_api::chatPosition &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatPosition");
  if (object.list_) {
    jo("list", ToJson(*object.list_));
  }
  jo("order", ToJson(JsonInt64{object.order_}));
  jo("is_pinned", JsonBool{object.is_pinned_});
  if (object.source_) {
    jo("source", ToJson(*object.source_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatStatisticsInteractionInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatStatisticsInteractionInfo");
  if (object.object_type_) {
    jo("object_type", ToJson(*object.object_type_));
  }
  jo("view_count", object.view_count_);
  jo("forward_count", object.forward_count_);
  jo("reaction_count", object.reaction_count_);
}

void to_json(JsonValueScope &jv, const td_api::checklist &object) {
  auto jo = jv.enter_object();
  jo("@type", "checklist");
  if (object.title_) {
    jo("title", ToJson(*object.title_));
  }
  jo("tasks", ToJson(object.tasks_));
  jo("others_can_add_tasks", JsonBool{object.others_can_add_tasks_});
  jo("can_add_tasks", JsonBool{object.can_add_tasks_});
  jo("others_can_mark_tasks_as_done", JsonBool{object.others_can_mark_tasks_as_done_});
  jo("can_mark_tasks_as_done", JsonBool{object.can_mark_tasks_as_done_});
}

void to_json(JsonValueScope &jv, const td_api::ConnectionState &object) {
  td_api::downcast_call(const_cast<td_api::ConnectionState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::connectionStateWaitingForNetwork &object) {
  auto jo = jv.enter_object();
  jo("@type", "connectionStateWaitingForNetwork");
}

void to_json(JsonValueScope &jv, const td_api::connectionStateConnectingToProxy &object) {
  auto jo = jv.enter_object();
  jo("@type", "connectionStateConnectingToProxy");
}

void to_json(JsonValueScope &jv, const td_api::connectionStateConnecting &object) {
  auto jo = jv.enter_object();
  jo("@type", "connectionStateConnecting");
}

void to_json(JsonValueScope &jv, const td_api::connectionStateUpdating &object) {
  auto jo = jv.enter_object();
  jo("@type", "connectionStateUpdating");
}

void to_json(JsonValueScope &jv, const td_api::connectionStateReady &object) {
  auto jo = jv.enter_object();
  jo("@type", "connectionStateReady");
}

void to_json(JsonValueScope &jv, const td_api::data &object) {
  auto jo = jv.enter_object();
  jo("@type", "data");
  jo("data", base64_encode(object.data_));
}

void to_json(JsonValueScope &jv, const td_api::diffEntity &object) {
  auto jo = jv.enter_object();
  jo("@type", "diffEntity");
  jo("offset", object.offset_);
  jo("length", object.length_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::emojiCategories &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiCategories");
  jo("categories", ToJson(object.categories_));
}

void to_json(JsonValueScope &jv, const td_api::EmojiStatusType &object) {
  td_api::downcast_call(const_cast<td_api::EmojiStatusType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::emojiStatusTypeCustomEmoji &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiStatusTypeCustomEmoji");
  jo("custom_emoji_id", ToJson(JsonInt64{object.custom_emoji_id_}));
}

void to_json(JsonValueScope &jv, const td_api::emojiStatusTypeUpgradedGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiStatusTypeUpgradedGift");
  jo("upgraded_gift_id", ToJson(JsonInt64{object.upgraded_gift_id_}));
  jo("gift_title", object.gift_title_);
  jo("gift_name", object.gift_name_);
  jo("model_custom_emoji_id", ToJson(JsonInt64{object.model_custom_emoji_id_}));
  jo("symbol_custom_emoji_id", ToJson(JsonInt64{object.symbol_custom_emoji_id_}));
  if (object.backdrop_colors_) {
    jo("backdrop_colors", ToJson(*object.backdrop_colors_));
  }
}

void to_json(JsonValueScope &jv, const td_api::file &object) {
  auto jo = jv.enter_object();
  jo("@type", "file");
  jo("id", object.id_);
  jo("size", object.size_);
  jo("expected_size", object.expected_size_);
  if (object.local_) {
    jo("local", ToJson(*object.local_));
  }
  if (object.remote_) {
    jo("remote", ToJson(*object.remote_));
  }
}

void to_json(JsonValueScope &jv, const td_api::forumTopicInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "forumTopicInfo");
  jo("chat_id", object.chat_id_);
  jo("forum_topic_id", object.forum_topic_id_);
  jo("name", object.name_);
  if (object.icon_) {
    jo("icon", ToJson(*object.icon_));
  }
  jo("creation_date", object.creation_date_);
  if (object.creator_id_) {
    jo("creator_id", ToJson(*object.creator_id_));
  }
  jo("is_general", JsonBool{object.is_general_});
  jo("is_outgoing", JsonBool{object.is_outgoing_});
  jo("is_closed", JsonBool{object.is_closed_});
  jo("is_hidden", JsonBool{object.is_hidden_});
  jo("is_name_implicit", JsonBool{object.is_name_implicit_});
}

void to_json(JsonValueScope &jv, const td_api::foundPosition &object) {
  auto jo = jv.enter_object();
  jo("@type", "foundPosition");
  jo("position", object.position_);
}

void to_json(JsonValueScope &jv, const td_api::gift &object) {
  auto jo = jv.enter_object();
  jo("@type", "gift");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("publisher_chat_id", object.publisher_chat_id_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
  jo("star_count", object.star_count_);
  jo("default_sell_star_count", object.default_sell_star_count_);
  jo("upgrade_star_count", object.upgrade_star_count_);
  jo("upgrade_variant_count", object.upgrade_variant_count_);
  jo("has_colors", JsonBool{object.has_colors_});
  jo("is_for_birthday", JsonBool{object.is_for_birthday_});
  jo("is_premium", JsonBool{object.is_premium_});
  if (object.auction_info_) {
    jo("auction_info", ToJson(*object.auction_info_));
  }
  jo("next_send_date", object.next_send_date_);
  if (object.user_limits_) {
    jo("user_limits", ToJson(*object.user_limits_));
  }
  if (object.overall_limits_) {
    jo("overall_limits", ToJson(*object.overall_limits_));
  }
  if (object.background_) {
    jo("background", ToJson(*object.background_));
  }
  jo("first_send_date", object.first_send_date_);
  jo("last_send_date", object.last_send_date_);
}

void to_json(JsonValueScope &jv, const td_api::giftCollections &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftCollections");
  jo("collections", ToJson(object.collections_));
}

void to_json(JsonValueScope &jv, const td_api::giftUpgradePrice &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftUpgradePrice");
  jo("date", object.date_);
  jo("star_count", object.star_count_);
}

void to_json(JsonValueScope &jv, const td_api::groupCallId &object) {
  auto jo = jv.enter_object();
  jo("@type", "groupCallId");
  jo("id", object.id_);
}

void to_json(JsonValueScope &jv, const td_api::groupCallStreams &object) {
  auto jo = jv.enter_object();
  jo("@type", "groupCallStreams");
  jo("streams", ToJson(object.streams_));
}

void to_json(JsonValueScope &jv, const td_api::inlineQueryResults &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineQueryResults");
  jo("inline_query_id", ToJson(JsonInt64{object.inline_query_id_}));
  if (object.button_) {
    jo("button", ToJson(*object.button_));
  }
  jo("results", ToJson(object.results_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::InputPaidMediaType &object) {
  td_api::downcast_call(const_cast<td_api::InputPaidMediaType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::inputPaidMediaTypePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputPaidMediaTypePhoto");
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inputPaidMediaTypeVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputPaidMediaTypeVideo");
  if (object.cover_) {
    jo("cover", ToJson(*object.cover_));
  }
  jo("start_timestamp", object.start_timestamp_);
  jo("duration", object.duration_);
  jo("supports_streaming", JsonBool{object.supports_streaming_});
}

void to_json(JsonValueScope &jv, const td_api::invoice &object) {
  auto jo = jv.enter_object();
  jo("@type", "invoice");
  jo("currency", object.currency_);
  jo("price_parts", ToJson(object.price_parts_));
  jo("subscription_period", object.subscription_period_);
  jo("max_tip_amount", object.max_tip_amount_);
  jo("suggested_tip_amounts", ToJson(object.suggested_tip_amounts_));
  jo("recurring_payment_terms_of_service_url", object.recurring_payment_terms_of_service_url_);
  jo("terms_of_service_url", object.terms_of_service_url_);
  jo("is_test", JsonBool{object.is_test_});
  jo("need_name", JsonBool{object.need_name_});
  jo("need_phone_number", JsonBool{object.need_phone_number_});
  jo("need_email_address", JsonBool{object.need_email_address_});
  jo("need_shipping_address", JsonBool{object.need_shipping_address_});
  jo("send_phone_number_to_provider", JsonBool{object.send_phone_number_to_provider_});
  jo("send_email_address_to_provider", JsonBool{object.send_email_address_to_provider_});
  jo("is_flexible", JsonBool{object.is_flexible_});
}

void to_json(JsonValueScope &jv, const td_api::languagePackStrings &object) {
  auto jo = jv.enter_object();
  jo("@type", "languagePackStrings");
  jo("strings", ToJson(object.strings_));
}

void to_json(JsonValueScope &jv, const td_api::locationAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "locationAddress");
  jo("country_code", object.country_code_);
  jo("state", object.state_);
  jo("city", object.city_);
  jo("street", object.street_);
}

void to_json(JsonValueScope &jv, const td_api::messageAutoDeleteTime &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageAutoDeleteTime");
  jo("time", object.time_);
}

void to_json(JsonValueScope &jv, const td_api::messageImportInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageImportInfo");
  jo("sender_name", object.sender_name_);
  jo("date", object.date_);
}

void to_json(JsonValueScope &jv, const td_api::messageReactions &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageReactions");
  jo("reactions", ToJson(object.reactions_));
  jo("are_tags", JsonBool{object.are_tags_});
  jo("paid_reactors", ToJson(object.paid_reactors_));
  jo("can_get_added_reactions", JsonBool{object.can_get_added_reactions_});
}

void to_json(JsonValueScope &jv, const td_api::messageStatistics &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageStatistics");
  if (object.message_interaction_graph_) {
    jo("message_interaction_graph", ToJson(*object.message_interaction_graph_));
  }
  if (object.message_reaction_graph_) {
    jo("message_reaction_graph", ToJson(*object.message_reaction_graph_));
  }
}

void to_json(JsonValueScope &jv, const td_api::NetworkType &object) {
  td_api::downcast_call(const_cast<td_api::NetworkType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::networkTypeNone &object) {
  auto jo = jv.enter_object();
  jo("@type", "networkTypeNone");
}

void to_json(JsonValueScope &jv, const td_api::networkTypeMobile &object) {
  auto jo = jv.enter_object();
  jo("@type", "networkTypeMobile");
}

void to_json(JsonValueScope &jv, const td_api::networkTypeMobileRoaming &object) {
  auto jo = jv.enter_object();
  jo("@type", "networkTypeMobileRoaming");
}

void to_json(JsonValueScope &jv, const td_api::networkTypeWiFi &object) {
  auto jo = jv.enter_object();
  jo("@type", "networkTypeWiFi");
}

void to_json(JsonValueScope &jv, const td_api::networkTypeOther &object) {
  auto jo = jv.enter_object();
  jo("@type", "networkTypeOther");
}

void to_json(JsonValueScope &jv, const td_api::oauthLinkInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "oauthLinkInfo");
  jo("user_id", object.user_id_);
  jo("url", object.url_);
  jo("domain", object.domain_);
  jo("from_app", JsonBool{object.from_app_});
  jo("verified_app_name", object.verified_app_name_);
  jo("bot_user_id", object.bot_user_id_);
  jo("request_write_access", JsonBool{object.request_write_access_});
  jo("request_phone_number_access", JsonBool{object.request_phone_number_access_});
  jo("browser", object.browser_);
  jo("platform", object.platform_);
  jo("ip_address", object.ip_address_);
  jo("location", object.location_);
  jo("match_code_first", JsonBool{object.match_code_first_});
  jo("match_codes", ToJson(object.match_codes_));
}

void to_json(JsonValueScope &jv, const td_api::pageBlockRelatedArticle &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockRelatedArticle");
  jo("url", object.url_);
  jo("title", object.title_);
  jo("description", object.description_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("author", object.author_);
  jo("publish_date", object.publish_date_);
}

void to_json(JsonValueScope &jv, const td_api::PassportElement &object) {
  td_api::downcast_call(const_cast<td_api::PassportElement &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::passportElementPersonalDetails &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementPersonalDetails");
  if (object.personal_details_) {
    jo("personal_details", ToJson(*object.personal_details_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passportElementPassport &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementPassport");
  if (object.passport_) {
    jo("passport", ToJson(*object.passport_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passportElementDriverLicense &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementDriverLicense");
  if (object.driver_license_) {
    jo("driver_license", ToJson(*object.driver_license_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passportElementIdentityCard &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementIdentityCard");
  if (object.identity_card_) {
    jo("identity_card", ToJson(*object.identity_card_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passportElementInternalPassport &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementInternalPassport");
  if (object.internal_passport_) {
    jo("internal_passport", ToJson(*object.internal_passport_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passportElementAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementAddress");
  if (object.address_) {
    jo("address", ToJson(*object.address_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passportElementUtilityBill &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementUtilityBill");
  if (object.utility_bill_) {
    jo("utility_bill", ToJson(*object.utility_bill_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passportElementBankStatement &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementBankStatement");
  if (object.bank_statement_) {
    jo("bank_statement", ToJson(*object.bank_statement_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passportElementRentalAgreement &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementRentalAgreement");
  if (object.rental_agreement_) {
    jo("rental_agreement", ToJson(*object.rental_agreement_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passportElementPassportRegistration &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementPassportRegistration");
  if (object.passport_registration_) {
    jo("passport_registration", ToJson(*object.passport_registration_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passportElementTemporaryRegistration &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementTemporaryRegistration");
  if (object.temporary_registration_) {
    jo("temporary_registration", ToJson(*object.temporary_registration_));
  }
}

void to_json(JsonValueScope &jv, const td_api::passportElementPhoneNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementPhoneNumber");
  jo("phone_number", object.phone_number_);
}

void to_json(JsonValueScope &jv, const td_api::passportElementEmailAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementEmailAddress");
  jo("email_address", object.email_address_);
}

void to_json(JsonValueScope &jv, const td_api::paymentForm &object) {
  auto jo = jv.enter_object();
  jo("@type", "paymentForm");
  jo("id", ToJson(JsonInt64{object.id_}));
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("seller_bot_user_id", object.seller_bot_user_id_);
  if (object.product_info_) {
    jo("product_info", ToJson(*object.product_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::phoneNumberInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "phoneNumberInfo");
  if (object.country_) {
    jo("country", ToJson(*object.country_));
  }
  jo("country_calling_code", object.country_calling_code_);
  jo("formatted_phone_number", object.formatted_phone_number_);
  jo("is_anonymous", JsonBool{object.is_anonymous_});
}

void to_json(JsonValueScope &jv, const td_api::pollVoters &object) {
  auto jo = jv.enter_object();
  jo("@type", "pollVoters");
  jo("total_count", object.total_count_);
  jo("voters", ToJson(object.voters_));
}

void to_json(JsonValueScope &jv, const td_api::premiumLimit &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumLimit");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("default_value", object.default_value_);
  jo("premium_value", object.premium_value_);
}

void to_json(JsonValueScope &jv, const td_api::profileAccentColor &object) {
  auto jo = jv.enter_object();
  jo("@type", "profileAccentColor");
  jo("id", object.id_);
  if (object.light_theme_colors_) {
    jo("light_theme_colors", ToJson(*object.light_theme_colors_));
  }
  if (object.dark_theme_colors_) {
    jo("dark_theme_colors", ToJson(*object.dark_theme_colors_));
  }
  jo("min_supergroup_chat_boost_level", object.min_supergroup_chat_boost_level_);
  jo("min_channel_chat_boost_level", object.min_channel_chat_boost_level_);
}

void to_json(JsonValueScope &jv, const td_api::PushMessageContent &object) {
  td_api::downcast_call(const_cast<td_api::PushMessageContent &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentHidden &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentHidden");
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentAnimation &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentAnimation");
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
  jo("caption", object.caption_);
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentAudio &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentAudio");
  if (object.audio_) {
    jo("audio", ToJson(*object.audio_));
  }
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentContact &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentContact");
  jo("name", object.name_);
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentContactRegistered &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentContactRegistered");
  jo("as_premium_account", JsonBool{object.as_premium_account_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentDocument &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentDocument");
  if (object.document_) {
    jo("document", ToJson(*object.document_));
  }
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentGame &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentGame");
  jo("title", object.title_);
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentGameScore &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentGameScore");
  jo("title", object.title_);
  jo("score", object.score_);
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentInvoice &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentInvoice");
  jo("price", object.price_);
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentLocation &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentLocation");
  jo("is_live", JsonBool{object.is_live_});
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentPaidMedia &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentPaidMedia");
  jo("star_count", object.star_count_);
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentPhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentPhoto");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("caption", object.caption_);
  jo("is_secret", JsonBool{object.is_secret_});
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentPoll &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentPoll");
  jo("question", object.question_);
  jo("is_regular", JsonBool{object.is_regular_});
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentPremiumGiftCode &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentPremiumGiftCode");
  jo("month_count", object.month_count_);
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentGiveaway &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentGiveaway");
  jo("winner_count", object.winner_count_);
  if (object.prize_) {
    jo("prize", ToJson(*object.prize_));
  }
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentGift");
  jo("star_count", object.star_count_);
  jo("is_prepaid_upgrade", JsonBool{object.is_prepaid_upgrade_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentUpgradedGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentUpgradedGift");
  jo("is_upgrade", JsonBool{object.is_upgrade_});
  jo("is_prepaid_upgrade", JsonBool{object.is_prepaid_upgrade_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentScreenshotTaken &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentScreenshotTaken");
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentSticker &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentSticker");
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
  jo("emoji", object.emoji_);
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentStory");
  jo("is_mention", JsonBool{object.is_mention_});
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentText &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentText");
  jo("text", object.text_);
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentChecklist &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentChecklist");
  jo("title", object.title_);
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentVideo");
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
  jo("caption", object.caption_);
  jo("is_secret", JsonBool{object.is_secret_});
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentVideoNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentVideoNote");
  if (object.video_note_) {
    jo("video_note", ToJson(*object.video_note_));
  }
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentVoiceNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentVoiceNote");
  if (object.voice_note_) {
    jo("voice_note", ToJson(*object.voice_note_));
  }
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentBasicGroupChatCreate &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentBasicGroupChatCreate");
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentVideoChatStarted &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentVideoChatStarted");
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentVideoChatEnded &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentVideoChatEnded");
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentInviteVideoChatParticipants &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentInviteVideoChatParticipants");
  jo("is_current_user", JsonBool{object.is_current_user_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentChatAddMembers &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentChatAddMembers");
  jo("member_name", object.member_name_);
  jo("is_current_user", JsonBool{object.is_current_user_});
  jo("is_returned", JsonBool{object.is_returned_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentChatChangePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentChatChangePhoto");
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentChatChangeTitle &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentChatChangeTitle");
  jo("title", object.title_);
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentChatSetBackground &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentChatSetBackground");
  jo("is_same", JsonBool{object.is_same_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentChatSetTheme &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentChatSetTheme");
  jo("name", object.name_);
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentChatDeleteMember &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentChatDeleteMember");
  jo("member_name", object.member_name_);
  jo("is_current_user", JsonBool{object.is_current_user_});
  jo("is_left", JsonBool{object.is_left_});
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentChatJoinByLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentChatJoinByLink");
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentChatJoinByRequest &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentChatJoinByRequest");
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentRecurringPayment &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentRecurringPayment");
  jo("amount", object.amount_);
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentSuggestProfilePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentSuggestProfilePhoto");
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentSuggestBirthdate &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentSuggestBirthdate");
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentProximityAlertTriggered &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentProximityAlertTriggered");
  jo("distance", object.distance_);
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentChecklistTasksAdded &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentChecklistTasksAdded");
  jo("task_count", object.task_count_);
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentChecklistTasksDone &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentChecklistTasksDone");
  jo("task_count", object.task_count_);
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentPollOptionAdded &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentPollOptionAdded");
  jo("text", object.text_);
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentMessageForwards &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentMessageForwards");
  jo("total_count", object.total_count_);
}

void to_json(JsonValueScope &jv, const td_api::pushMessageContentMediaAlbum &object) {
  auto jo = jv.enter_object();
  jo("@type", "pushMessageContentMediaAlbum");
  jo("total_count", object.total_count_);
  jo("has_photos", JsonBool{object.has_photos_});
  jo("has_videos", JsonBool{object.has_videos_});
  jo("has_audios", JsonBool{object.has_audios_});
  jo("has_documents", JsonBool{object.has_documents_});
}

void to_json(JsonValueScope &jv, const td_api::readDatePrivacySettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "readDatePrivacySettings");
  jo("show_read_date", JsonBool{object.show_read_date_});
}

void to_json(JsonValueScope &jv, const td_api::reportOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "reportOption");
  jo("id", base64_encode(object.id_));
  jo("text", object.text_);
}

void to_json(JsonValueScope &jv, const td_api::savedMessagesTag &object) {
  auto jo = jv.enter_object();
  jo("@type", "savedMessagesTag");
  if (object.tag_) {
    jo("tag", ToJson(*object.tag_));
  }
  jo("label", object.label_);
  jo("count", object.count_);
}

void to_json(JsonValueScope &jv, const td_api::SentGift &object) {
  td_api::downcast_call(const_cast<td_api::SentGift &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::sentGiftRegular &object) {
  auto jo = jv.enter_object();
  jo("@type", "sentGiftRegular");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::sentGiftUpgraded &object) {
  auto jo = jv.enter_object();
  jo("@type", "sentGiftUpgraded");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::SpeechRecognitionResult &object) {
  td_api::downcast_call(const_cast<td_api::SpeechRecognitionResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::speechRecognitionResultPending &object) {
  auto jo = jv.enter_object();
  jo("@type", "speechRecognitionResultPending");
  jo("partial_text", object.partial_text_);
}

void to_json(JsonValueScope &jv, const td_api::speechRecognitionResultText &object) {
  auto jo = jv.enter_object();
  jo("@type", "speechRecognitionResultText");
  jo("text", object.text_);
}

void to_json(JsonValueScope &jv, const td_api::speechRecognitionResultError &object) {
  auto jo = jv.enter_object();
  jo("@type", "speechRecognitionResultError");
  if (object.error_) {
    jo("error", ToJson(*object.error_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starGiveawayPaymentOptions &object) {
  auto jo = jv.enter_object();
  jo("@type", "starGiveawayPaymentOptions");
  jo("options", ToJson(object.options_));
}

void to_json(JsonValueScope &jv, const td_api::starSubscriptions &object) {
  auto jo = jv.enter_object();
  jo("@type", "starSubscriptions");
  if (object.star_amount_) {
    jo("star_amount", ToJson(*object.star_amount_));
  }
  jo("subscriptions", ToJson(object.subscriptions_));
  jo("required_star_count", object.required_star_count_);
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::StickerFullType &object) {
  td_api::downcast_call(const_cast<td_api::StickerFullType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::stickerFullTypeRegular &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickerFullTypeRegular");
  if (object.premium_animation_) {
    jo("premium_animation", ToJson(*object.premium_animation_));
  }
}

void to_json(JsonValueScope &jv, const td_api::stickerFullTypeMask &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickerFullTypeMask");
  if (object.mask_position_) {
    jo("mask_position", ToJson(*object.mask_position_));
  }
}

void to_json(JsonValueScope &jv, const td_api::stickerFullTypeCustomEmoji &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickerFullTypeCustomEmoji");
  jo("custom_emoji_id", ToJson(JsonInt64{object.custom_emoji_id_}));
  jo("needs_repainting", JsonBool{object.needs_repainting_});
}

void to_json(JsonValueScope &jv, const td_api::storageStatisticsFast &object) {
  auto jo = jv.enter_object();
  jo("@type", "storageStatisticsFast");
  jo("files_size", object.files_size_);
  jo("file_count", object.file_count_);
  jo("database_size", object.database_size_);
  jo("language_pack_database_size", object.language_pack_database_size_);
  jo("log_size", object.log_size_);
}

void to_json(JsonValueScope &jv, const td_api::StoryContentType &object) {
  td_api::downcast_call(const_cast<td_api::StoryContentType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::storyContentTypePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyContentTypePhoto");
}

void to_json(JsonValueScope &jv, const td_api::storyContentTypeVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyContentTypeVideo");
}

void to_json(JsonValueScope &jv, const td_api::storyContentTypeLive &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyContentTypeLive");
}

void to_json(JsonValueScope &jv, const td_api::storyContentTypeUnsupported &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyContentTypeUnsupported");
}

void to_json(JsonValueScope &jv, const td_api::storyRepostInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyRepostInfo");
  if (object.origin_) {
    jo("origin", ToJson(*object.origin_));
  }
  jo("is_content_modified", JsonBool{object.is_content_modified_});
}

void to_json(JsonValueScope &jv, const td_api::supergroupFullInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "supergroupFullInfo");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("description", object.description_);
  jo("member_count", object.member_count_);
  jo("administrator_count", object.administrator_count_);
  jo("restricted_count", object.restricted_count_);
  jo("banned_count", object.banned_count_);
  jo("linked_chat_id", object.linked_chat_id_);
  jo("direct_messages_chat_id", object.direct_messages_chat_id_);
  jo("slow_mode_delay", object.slow_mode_delay_);
  jo("slow_mode_delay_expires_in", object.slow_mode_delay_expires_in_);
  jo("can_enable_paid_messages", JsonBool{object.can_enable_paid_messages_});
  jo("can_enable_paid_reaction", JsonBool{object.can_enable_paid_reaction_});
  jo("can_get_members", JsonBool{object.can_get_members_});
  jo("has_hidden_members", JsonBool{object.has_hidden_members_});
  jo("can_hide_members", JsonBool{object.can_hide_members_});
  jo("can_set_sticker_set", JsonBool{object.can_set_sticker_set_});
  jo("can_set_location", JsonBool{object.can_set_location_});
  jo("can_get_statistics", JsonBool{object.can_get_statistics_});
  jo("can_get_revenue_statistics", JsonBool{object.can_get_revenue_statistics_});
  jo("can_get_star_revenue_statistics", JsonBool{object.can_get_star_revenue_statistics_});
  jo("can_send_gift", JsonBool{object.can_send_gift_});
  jo("can_toggle_aggressive_anti_spam", JsonBool{object.can_toggle_aggressive_anti_spam_});
  jo("is_all_history_available", JsonBool{object.is_all_history_available_});
  jo("can_have_sponsored_messages", JsonBool{object.can_have_sponsored_messages_});
  jo("has_aggressive_anti_spam_enabled", JsonBool{object.has_aggressive_anti_spam_enabled_});
  jo("has_paid_media_allowed", JsonBool{object.has_paid_media_allowed_});
  jo("has_pinned_stories", JsonBool{object.has_pinned_stories_});
  jo("gift_count", object.gift_count_);
  jo("my_boost_count", object.my_boost_count_);
  jo("unrestrict_boost_count", object.unrestrict_boost_count_);
  jo("outgoing_paid_message_star_count", object.outgoing_paid_message_star_count_);
  jo("sticker_set_id", ToJson(JsonInt64{object.sticker_set_id_}));
  jo("custom_emoji_sticker_set_id", ToJson(JsonInt64{object.custom_emoji_sticker_set_id_}));
  if (object.location_) {
    jo("location", ToJson(*object.location_));
  }
  if (object.invite_link_) {
    jo("invite_link", ToJson(*object.invite_link_));
  }
  jo("bot_commands", ToJson(object.bot_commands_));
  if (object.bot_verification_) {
    jo("bot_verification", ToJson(*object.bot_verification_));
  }
  if (object.main_profile_tab_) {
    jo("main_profile_tab", ToJson(*object.main_profile_tab_));
  }
  jo("upgraded_from_basic_group_id", object.upgraded_from_basic_group_id_);
  jo("upgraded_from_max_message_id", object.upgraded_from_max_message_id_);
}

void to_json(JsonValueScope &jv, const td_api::testInt &object) {
  auto jo = jv.enter_object();
  jo("@type", "testInt");
  jo("value", object.value_);
}

void to_json(JsonValueScope &jv, const td_api::textEntity &object) {
  auto jo = jv.enter_object();
  jo("@type", "textEntity");
  jo("offset", object.offset_);
  jo("length", object.length_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::tonRevenueStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "tonRevenueStatus");
  jo("total_amount", ToJson(JsonInt64{object.total_amount_}));
  jo("balance_amount", ToJson(JsonInt64{object.balance_amount_}));
  jo("available_amount", ToJson(JsonInt64{object.available_amount_}));
  jo("withdrawal_enabled", JsonBool{object.withdrawal_enabled_});
}

void to_json(JsonValueScope &jv, const td_api::upgradeGiftResult &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradeGiftResult");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  jo("received_gift_id", object.received_gift_id_);
  jo("is_saved", JsonBool{object.is_saved_});
  jo("can_be_transferred", JsonBool{object.can_be_transferred_});
  jo("transfer_star_count", object.transfer_star_count_);
  jo("drop_original_details_star_count", object.drop_original_details_star_count_);
  jo("next_transfer_date", object.next_transfer_date_);
  jo("next_resale_date", object.next_resale_date_);
  jo("export_date", object.export_date_);
}

void to_json(JsonValueScope &jv, const td_api::UpgradedGiftOrigin &object) {
  td_api::downcast_call(const_cast<td_api::UpgradedGiftOrigin &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftOriginUpgrade &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftOriginUpgrade");
  jo("gift_message_id", object.gift_message_id_);
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftOriginTransfer &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftOriginTransfer");
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftOriginResale &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftOriginResale");
  if (object.price_) {
    jo("price", ToJson(*object.price_));
  }
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftOriginBlockchain &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftOriginBlockchain");
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftOriginPrepaidUpgrade &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftOriginPrepaidUpgrade");
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftOriginOffer &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftOriginOffer");
  if (object.price_) {
    jo("price", ToJson(*object.price_));
  }
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftOriginCraft &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftOriginCraft");
}

void to_json(JsonValueScope &jv, const td_api::UserPrivacySetting &object) {
  td_api::downcast_call(const_cast<td_api::UserPrivacySetting &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingShowStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingShowStatus");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingShowProfilePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingShowProfilePhoto");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingShowLinkInForwardedMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingShowLinkInForwardedMessages");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingShowPhoneNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingShowPhoneNumber");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingShowBio &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingShowBio");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingShowBirthdate &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingShowBirthdate");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingShowProfileAudio &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingShowProfileAudio");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingAllowChatInvites &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingAllowChatInvites");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingAllowCalls &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingAllowCalls");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingAllowPeerToPeerCalls &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingAllowPeerToPeerCalls");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingAllowFindingByPhoneNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingAllowFindingByPhoneNumber");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingAutosaveGifts &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingAutosaveGifts");
}

void to_json(JsonValueScope &jv, const td_api::userPrivacySettingAllowUnpaidMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "userPrivacySettingAllowUnpaidMessages");
}

void to_json(JsonValueScope &jv, const td_api::validatedOrderInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "validatedOrderInfo");
  jo("order_info_id", object.order_info_id_);
  jo("shipping_options", ToJson(object.shipping_options_));
}

void to_json(JsonValueScope &jv, const td_api::videoStoryboard &object) {
  auto jo = jv.enter_object();
  jo("@type", "videoStoryboard");
  if (object.storyboard_file_) {
    jo("storyboard_file", ToJson(*object.storyboard_file_));
  }
  jo("width", object.width_);
  jo("height", object.height_);
  if (object.map_file_) {
    jo("map_file", ToJson(*object.map_file_));
  }
}

}  // namespace td_api
}  // namespace td
