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
Result<int32> tl_constructor_from_string(td_api::BusinessAwayMessageSchedule *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"businessAwayMessageScheduleAlways", -910564679},
    {"businessAwayMessageScheduleOutsideOfOpeningHours", -968630506},
    {"businessAwayMessageScheduleCustom", -1967108654}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ChatMembersFilter *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"chatMembersFilterContacts", 1774485671},
    {"chatMembersFilterAdministrators", -1266893796},
    {"chatMembersFilterMembers", 670504342},
    {"chatMembersFilterMention", 1932296772},
    {"chatMembersFilterRestricted", 1256282813},
    {"chatMembersFilterBanned", -1863102648},
    {"chatMembersFilterBots", -1422567288}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::FileType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"fileTypeWallpaper", 1854930076}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputCall *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputCallDiscarded", 1956569937},
    {"inputCallFromMessage", 980874855}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputMessageReplyTo *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputMessageReplyToMessage", 1117785378},
    {"inputMessageReplyToExternalMessage", 1956732638},
    {"inputMessageReplyToStory", -1723842320}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::KeyboardButtonSource *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"keyboardButtonSourceMessage", 326023575},
    {"keyboardButtonSourceWebApp", -450665232}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::MessageTopic *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"messageTopicThread", 1360920071},
    {"messageTopicForum", 2119440112},
    {"messageTopicDirectMessages", -1285378599},
    {"messageTopicSavedMessages", 588026991}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::PremiumLimitType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"premiumLimitTypeOwnedBotCount", -595906175}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ReportReason *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"reportReasonSpam", -1207032897},
    {"reportReasonViolence", 2038679353},
    {"reportReasonPornography", 1306467575},
    {"reportReasonChildAbuse", 761086718},
    {"reportReasonCopyright", 1474441135},
    {"reportReasonUnrelatedLocation", 87562288},
    {"reportReasonFake", 352862176},
    {"reportReasonIllegalDrugs", -61599200},
    {"reportReasonPersonalDetails", -1588882414},
    {"reportReasonCustom", -1380459917}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::StoryContentType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"storyContentTypePhoto", -1568510965},
    {"storyContentTypeVideo", -573976899},
    {"storyContentTypeLive", -659651117},
    {"storyContentTypeUnsupported", 642311105}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::TextParseMode *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"textParseModeMarkdown", 360073407},
    {"textParseModeHTML", 1660208627}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Status from_json(td_api::address &to, JsonObject &from) {
  TRY_STATUS(from_json(to.country_code_, from.extract_field("country_code")));
  TRY_STATUS(from_json(to.state_, from.extract_field("state")));
  TRY_STATUS(from_json(to.city_, from.extract_field("city")));
  TRY_STATUS(from_json(to.street_line1_, from.extract_field("street_line1")));
  TRY_STATUS(from_json(to.street_line2_, from.extract_field("street_line2")));
  TRY_STATUS(from_json(to.postal_code_, from.extract_field("postal_code")));
  return Status::OK();
}

Status from_json(td_api::autoDownloadSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_auto_download_enabled_, from.extract_field("is_auto_download_enabled")));
  TRY_STATUS(from_json(to.max_photo_file_size_, from.extract_field("max_photo_file_size")));
  TRY_STATUS(from_json(to.max_video_file_size_, from.extract_field("max_video_file_size")));
  TRY_STATUS(from_json(to.max_other_file_size_, from.extract_field("max_other_file_size")));
  TRY_STATUS(from_json(to.video_upload_bitrate_, from.extract_field("video_upload_bitrate")));
  TRY_STATUS(from_json(to.preload_large_videos_, from.extract_field("preload_large_videos")));
  TRY_STATUS(from_json(to.preload_next_audio_, from.extract_field("preload_next_audio")));
  TRY_STATUS(from_json(to.preload_stories_, from.extract_field("preload_stories")));
  TRY_STATUS(from_json(to.use_less_data_for_calls_, from.extract_field("use_less_data_for_calls")));
  return Status::OK();
}

Status from_json(td_api::backgroundTypePattern &to, JsonObject &from) {
  TRY_STATUS(from_json(to.fill_, from.extract_field("fill")));
  TRY_STATUS(from_json(to.intensity_, from.extract_field("intensity")));
  TRY_STATUS(from_json(to.is_inverted_, from.extract_field("is_inverted")));
  TRY_STATUS(from_json(to.is_moving_, from.extract_field("is_moving")));
  return Status::OK();
}

Status from_json(td_api::botCommandScopeAllGroupChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessAwayMessageSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shortcut_id_, from.extract_field("shortcut_id")));
  TRY_STATUS(from_json(to.recipients_, from.extract_field("recipients")));
  TRY_STATUS(from_json(to.schedule_, from.extract_field("schedule")));
  TRY_STATUS(from_json(to.offline_only_, from.extract_field("offline_only")));
  return Status::OK();
}

Status from_json(td_api::businessFeatureStartPage &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessRecipients &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_ids_, from.extract_field("chat_ids")));
  TRY_STATUS(from_json(to.excluded_chat_ids_, from.extract_field("excluded_chat_ids")));
  TRY_STATUS(from_json(to.select_existing_chats_, from.extract_field("select_existing_chats")));
  TRY_STATUS(from_json(to.select_new_chats_, from.extract_field("select_new_chats")));
  TRY_STATUS(from_json(to.select_contacts_, from.extract_field("select_contacts")));
  TRY_STATUS(from_json(to.select_non_contacts_, from.extract_field("select_non_contacts")));
  TRY_STATUS(from_json(to.exclude_selected_, from.extract_field("exclude_selected")));
  return Status::OK();
}

Status from_json(td_api::callProblemSilentLocal &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatActionTyping &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatActionChoosingContact &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatEventLogFilters &to, JsonObject &from) {
  TRY_STATUS(from_json(to.message_edits_, from.extract_field("message_edits")));
  TRY_STATUS(from_json(to.message_deletions_, from.extract_field("message_deletions")));
  TRY_STATUS(from_json(to.message_pins_, from.extract_field("message_pins")));
  TRY_STATUS(from_json(to.member_joins_, from.extract_field("member_joins")));
  TRY_STATUS(from_json(to.member_leaves_, from.extract_field("member_leaves")));
  TRY_STATUS(from_json(to.member_invites_, from.extract_field("member_invites")));
  TRY_STATUS(from_json(to.member_promotions_, from.extract_field("member_promotions")));
  TRY_STATUS(from_json(to.member_restrictions_, from.extract_field("member_restrictions")));
  TRY_STATUS(from_json(to.member_tag_changes_, from.extract_field("member_tag_changes")));
  TRY_STATUS(from_json(to.info_changes_, from.extract_field("info_changes")));
  TRY_STATUS(from_json(to.setting_changes_, from.extract_field("setting_changes")));
  TRY_STATUS(from_json(to.invite_link_changes_, from.extract_field("invite_link_changes")));
  TRY_STATUS(from_json(to.video_chat_changes_, from.extract_field("video_chat_changes")));
  TRY_STATUS(from_json(to.forum_changes_, from.extract_field("forum_changes")));
  TRY_STATUS(from_json(to.subscription_extensions_, from.extract_field("subscription_extensions")));
  return Status::OK();
}

Status from_json(td_api::chatLocation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  TRY_STATUS(from_json(to.address_, from.extract_field("address")));
  return Status::OK();
}

Status from_json(td_api::chatMembersFilterMembers &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatPhotoStickerTypeCustomEmoji &to, JsonObject &from) {
  TRY_STATUS(from_json(to.custom_emoji_id_, from.extract_field("custom_emoji_id")));
  return Status::OK();
}

Status from_json(td_api::dateTimePartPrecisionLong &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::deviceTokenUbuntuPush &to, JsonObject &from) {
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  return Status::OK();
}

Status from_json(td_api::emojiCategoryTypeRegularStickers &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeAudio &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeSecure &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeVideo &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::giftForResaleOrderPrice &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::groupCallJoinParameters &to, JsonObject &from) {
  TRY_STATUS(from_json(to.audio_source_id_, from.extract_field("audio_source_id")));
  TRY_STATUS(from_json(to.payload_, from.extract_field("payload")));
  TRY_STATUS(from_json(to.is_muted_, from.extract_field("is_muted")));
  TRY_STATUS(from_json(to.is_my_video_enabled_, from.extract_field("is_my_video_enabled")));
  return Status::OK();
}

Status from_json(td_api::inlineKeyboardButtonTypeCallback &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.data_, from.extract_field("data")));
  return Status::OK();
}

Status from_json(td_api::inlineQueryResultsButtonTypeWebApp &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::inputChatPhotoStatic &to, JsonObject &from) {
  TRY_STATUS(from_json(to.photo_, from.extract_field("photo")));
  return Status::OK();
}

Status from_json(td_api::inputCredentialsApplePay &to, JsonObject &from) {
  TRY_STATUS(from_json(to.data_, from.extract_field("data")));
  return Status::OK();
}

Status from_json(td_api::inputInlineQueryResultAnimation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.thumbnail_url_, from.extract_field("thumbnail_url")));
  TRY_STATUS(from_json(to.thumbnail_mime_type_, from.extract_field("thumbnail_mime_type")));
  TRY_STATUS(from_json(to.video_url_, from.extract_field("video_url")));
  TRY_STATUS(from_json(to.video_mime_type_, from.extract_field("video_mime_type")));
  TRY_STATUS(from_json(to.video_duration_, from.extract_field("video_duration")));
  TRY_STATUS(from_json(to.video_width_, from.extract_field("video_width")));
  TRY_STATUS(from_json(to.video_height_, from.extract_field("video_height")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::inputInlineQueryResultVenue &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.venue_, from.extract_field("venue")));
  TRY_STATUS(from_json(to.thumbnail_url_, from.extract_field("thumbnail_url")));
  TRY_STATUS(from_json(to.thumbnail_width_, from.extract_field("thumbnail_width")));
  TRY_STATUS(from_json(to.thumbnail_height_, from.extract_field("thumbnail_height")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::inputMessageDocument &to, JsonObject &from) {
  TRY_STATUS(from_json(to.document_, from.extract_field("document")));
  TRY_STATUS(from_json(to.thumbnail_, from.extract_field("thumbnail")));
  TRY_STATUS(from_json(to.disable_content_type_detection_, from.extract_field("disable_content_type_detection")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  return Status::OK();
}

Status from_json(td_api::inputMessageContact &to, JsonObject &from) {
  TRY_STATUS(from_json(to.contact_, from.extract_field("contact")));
  return Status::OK();
}

Status from_json(td_api::inputMessageReplyToMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.quote_, from.extract_field("quote")));
  TRY_STATUS(from_json(to.checklist_task_id_, from.extract_field("checklist_task_id")));
  TRY_STATUS(from_json(to.poll_option_id_, from.extract_field("poll_option_id")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementIdentityCard &to, JsonObject &from) {
  TRY_STATUS(from_json(to.identity_card_, from.extract_field("identity_card")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementEmailAddress &to, JsonObject &from) {
  TRY_STATUS(from_json(to.email_address_, from.extract_field("email_address")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementErrorSourceFile &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.file_hash_, from.extract_field("file_hash")));
  return Status::OK();
}

Status from_json(td_api::inputStoryAreaTypeFoundVenue &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_id_, from.extract_field("query_id")));
  TRY_STATUS(from_json(to.result_id_, from.extract_field("result_id")));
  return Status::OK();
}

Status from_json(td_api::inputStoryContentVideo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.video_, from.extract_field("video")));
  TRY_STATUS(from_json(to.added_sticker_file_ids_, from.extract_field("added_sticker_file_ids")));
  TRY_STATUS(from_json(to.duration_, from.extract_field("duration")));
  TRY_STATUS(from_json(to.cover_frame_timestamp_, from.extract_field("cover_frame_timestamp")));
  TRY_STATUS(from_json(to.is_animation_, from.extract_field("is_animation")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeBotStartInGroup &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_username_, from.extract_field("bot_username")));
  TRY_STATUS(from_json(to.start_parameter_, from.extract_field("start_parameter")));
  TRY_STATUS(from_json(to.administrator_rights_, from.extract_field("administrator_rights")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeDirectMessagesChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.channel_username_, from.extract_field("channel_username")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeMainWebApp &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_username_, from.extract_field("bot_username")));
  TRY_STATUS(from_json(to.start_parameter_, from.extract_field("start_parameter")));
  TRY_STATUS(from_json(to.mode_, from.extract_field("mode")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypePassportDataRequest &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.scope_, from.extract_field("scope")));
  TRY_STATUS(from_json(to.public_key_, from.extract_field("public_key")));
  TRY_STATUS(from_json(to.nonce_, from.extract_field("nonce")));
  TRY_STATUS(from_json(to.callback_url_, from.extract_field("callback_url")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeRestorePurchases &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeUnknownDeepLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_, from.extract_field("link")));
  return Status::OK();
}

Status from_json(td_api::jsonValueBoolean &to, JsonObject &from) {
  TRY_STATUS(from_json(to.value_, from.extract_field("value")));
  return Status::OK();
}

Status from_json(td_api::keyboardButtonTypeRequestPhoneNumber &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::languagePackString &to, JsonObject &from) {
  TRY_STATUS(from_json(to.key_, from.extract_field("key")));
  TRY_STATUS(from_json(to.value_, from.extract_field("value")));
  return Status::OK();
}

Status from_json(td_api::logStreamEmpty &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageSchedulingStateSendWhenOnline &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageSourceForumTopicHistory &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageTopicThread &to, JsonObject &from) {
  TRY_STATUS(from_json(to.message_thread_id_, from.extract_field("message_thread_id")));
  return Status::OK();
}

Status from_json(td_api::networkTypeWiFi &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::optionValueString &to, JsonObject &from) {
  TRY_STATUS(from_json(to.value_, from.extract_field("value")));
  return Status::OK();
}

Status from_json(td_api::passportElementTypeInternalPassport &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::personalDetails &to, JsonObject &from) {
  TRY_STATUS(from_json(to.first_name_, from.extract_field("first_name")));
  TRY_STATUS(from_json(to.middle_name_, from.extract_field("middle_name")));
  TRY_STATUS(from_json(to.last_name_, from.extract_field("last_name")));
  TRY_STATUS(from_json(to.native_first_name_, from.extract_field("native_first_name")));
  TRY_STATUS(from_json(to.native_middle_name_, from.extract_field("native_middle_name")));
  TRY_STATUS(from_json(to.native_last_name_, from.extract_field("native_last_name")));
  TRY_STATUS(from_json(to.birthdate_, from.extract_field("birthdate")));
  TRY_STATUS(from_json(to.gender_, from.extract_field("gender")));
  TRY_STATUS(from_json(to.country_code_, from.extract_field("country_code")));
  TRY_STATUS(from_json(to.residence_country_code_, from.extract_field("residence_country_code")));
  return Status::OK();
}

Status from_json(td_api::premiumFeatureDisabledAds &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureAppIcons &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureBusiness &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeSavedAnimationCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeShareableChatFolderCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumSourceFeature &to, JsonObject &from) {
  TRY_STATUS(from_json(to.feature_, from.extract_field("feature")));
  return Status::OK();
}

Status from_json(td_api::premiumStoryFeatureSaveStories &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::profileTabVoice &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::reactionNotificationSourceNone &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::replyMarkupShowKeyboard &to, JsonObject &from) {
  TRY_STATUS(from_json(to.rows_, from.extract_field("rows")));
  TRY_STATUS(from_json(to.is_persistent_, from.extract_field("is_persistent")));
  TRY_STATUS(from_json(to.resize_keyboard_, from.extract_field("resize_keyboard")));
  TRY_STATUS(from_json(to.one_time_, from.extract_field("one_time")));
  TRY_STATUS(from_json(to.is_personal_, from.extract_field("is_personal")));
  TRY_STATUS(from_json(to.input_field_placeholder_, from.extract_field("input_field_placeholder")));
  return Status::OK();
}

Status from_json(td_api::reportReasonIllegalDrugs &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesChatTypeFilterChannel &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterPhotoAndVideo &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterFailedToSend &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::settingsSectionFaq &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::settingsSectionPrivacyAndSecurity &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::stickerFormatWebm &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::storePaymentPurposeStars &to, JsonObject &from) {
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::storyFullId &to, JsonObject &from) {
  TRY_STATUS(from_json(to.poster_chat_id_, from.extract_field("poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  return Status::OK();
}

Status from_json(td_api::suggestedActionCheckPhoneNumber &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedActionSetProfilePhoto &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::supergroupMembersFilterContacts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  return Status::OK();
}

Status from_json(td_api::targetChatInternalLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_, from.extract_field("link")));
  return Status::OK();
}

Status from_json(td_api::testInt &to, JsonObject &from) {
  TRY_STATUS(from_json(to.value_, from.extract_field("value")));
  return Status::OK();
}

Status from_json(td_api::textEntityTypePhoneNumber &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypePreCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.language_, from.extract_field("language")));
  return Status::OK();
}

Status from_json(td_api::textParseModeHTML &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::topChatCategoryForwardChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingShowLinkInForwardedMessages &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingAllowPrivateVoiceAndVideoNoteMessages &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingRuleRestrictAll &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::webAppOpenModeFullScreen &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::addChatMembers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.user_ids_, from.extract_field("user_ids")));
  return Status::OK();
}

Status from_json(td_api::addLogMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.verbosity_level_, from.extract_field("verbosity_level")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::addProxy &to, JsonObject &from) {
  TRY_STATUS(from_json(to.proxy_, from.extract_field("proxy")));
  TRY_STATUS(from_json(to.enable_, from.extract_field("enable")));
  return Status::OK();
}

Status from_json(td_api::addStoryAlbumStories &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.story_album_id_, from.extract_field("story_album_id")));
  TRY_STATUS(from_json(to.story_ids_, from.extract_field("story_ids")));
  return Status::OK();
}

Status from_json(td_api::applyPremiumGiftCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.code_, from.extract_field("code")));
  return Status::OK();
}

Status from_json(td_api::canPostStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::changeImportedContacts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.contacts_, from.extract_field("contacts")));
  return Status::OK();
}

Status from_json(td_api::checkBotUsername &to, JsonObject &from) {
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  return Status::OK();
}

Status from_json(td_api::checkPhoneNumberCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.code_, from.extract_field("code")));
  return Status::OK();
}

Status from_json(td_api::clearImportedContacts &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::clickVideoMessageAdvertisement &to, JsonObject &from) {
  TRY_STATUS(from_json(to.advertisement_unique_id_, from.extract_field("advertisement_unique_id")));
  return Status::OK();
}

Status from_json(td_api::composeTextWithAi &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.translate_to_language_code_, from.extract_field("translate_to_language_code")));
  TRY_STATUS(from_json(to.style_name_, from.extract_field("style_name")));
  TRY_STATUS(from_json(to.add_emojis_, from.extract_field("add_emojis")));
  return Status::OK();
}

Status from_json(td_api::createChatFolder &to, JsonObject &from) {
  TRY_STATUS(from_json(to.folder_, from.extract_field("folder")));
  return Status::OK();
}

Status from_json(td_api::createNewSecretChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::declineGroupCallInvitation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::deleteBusinessConnectedBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  return Status::OK();
}

Status from_json(td_api::deleteChatMessagesBySender &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.sender_id_, from.extract_field("sender_id")));
  return Status::OK();
}

Status from_json(td_api::deleteGroupCallMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.message_ids_, from.extract_field("message_ids")));
  TRY_STATUS(from_json(to.report_spam_, from.extract_field("report_spam")));
  return Status::OK();
}

Status from_json(td_api::deleteRevokedChatInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  return Status::OK();
}

Status from_json(td_api::disableAllSupergroupUsernames &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  return Status::OK();
}

Status from_json(td_api::editBusinessChatLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_, from.extract_field("link")));
  TRY_STATUS(from_json(to.link_info_, from.extract_field("link_info")));
  return Status::OK();
}

Status from_json(td_api::editChatFolderInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_id_, from.extract_field("chat_folder_id")));
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.chat_ids_, from.extract_field("chat_ids")));
  return Status::OK();
}

Status from_json(td_api::editInlineMessageText &to, JsonObject &from) {
  TRY_STATUS(from_json(to.inline_message_id_, from.extract_field("inline_message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::editQuickReplyMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shortcut_id_, from.extract_field("shortcut_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::endGroupCallScreenSharing &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::getApplicationConfig &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getAutosaveSettings &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getBotInfoShortDescription &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  return Status::OK();
}

Status from_json(td_api::getBusinessChatLinks &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getChatArchivedStories &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.from_story_id_, from.extract_field("from_story_id")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getChatEventLog &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.from_event_id_, from.extract_field("from_event_id")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  TRY_STATUS(from_json(to.filters_, from.extract_field("filters")));
  TRY_STATUS(from_json(to.user_ids_, from.extract_field("user_ids")));
  return Status::OK();
}

Status from_json(td_api::getChatInviteLinkCounts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getChatMessagePosition &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.filter_, from.extract_field("filter")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::getChatSimilarChatCount &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.return_local_, from.extract_field("return_local")));
  return Status::OK();
}

Status from_json(td_api::getChatsToPostStories &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getCountryCode &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getDefaultBackgroundCustomEmojiStickers &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getDirectMessagesChatTopicRevenue &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  return Status::OK();
}

Status from_json(td_api::getFileDownloadedPrefixSize &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  return Status::OK();
}

Status from_json(td_api::getGiftAuctionAcquiredGifts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.gift_id_, from.extract_field("gift_id")));
  return Status::OK();
}

Status from_json(td_api::getGroupCall &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::getInstalledBackgrounds &to, JsonObject &from) {
  TRY_STATUS(from_json(to.for_dark_theme_, from.extract_field("for_dark_theme")));
  return Status::OK();
}

Status from_json(td_api::getLanguagePackStrings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.language_pack_id_, from.extract_field("language_pack_id")));
  TRY_STATUS(from_json(to.keys_, from.extract_field("keys")));
  return Status::OK();
}

Status from_json(td_api::getLogTags &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getMenuButton &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::getMessageLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.media_timestamp_, from.extract_field("media_timestamp")));
  TRY_STATUS(from_json(to.checklist_task_id_, from.extract_field("checklist_task_id")));
  TRY_STATUS(from_json(to.poll_option_id_, from.extract_field("poll_option_id")));
  TRY_STATUS(from_json(to.for_album_, from.extract_field("for_album")));
  TRY_STATUS(from_json(to.in_message_thread_, from.extract_field("in_message_thread")));
  return Status::OK();
}

Status from_json(td_api::getMessageViewers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::getPasskeyParameters &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getPollOptionProperties &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.poll_option_id_, from.extract_field("poll_option_id")));
  return Status::OK();
}

Status from_json(td_api::getPremiumStickerExamples &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getReceivedGifts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.collection_id_, from.extract_field("collection_id")));
  TRY_STATUS(from_json(to.exclude_unsaved_, from.extract_field("exclude_unsaved")));
  TRY_STATUS(from_json(to.exclude_saved_, from.extract_field("exclude_saved")));
  TRY_STATUS(from_json(to.exclude_unlimited_, from.extract_field("exclude_unlimited")));
  TRY_STATUS(from_json(to.exclude_upgradable_, from.extract_field("exclude_upgradable")));
  TRY_STATUS(from_json(to.exclude_non_upgradable_, from.extract_field("exclude_non_upgradable")));
  TRY_STATUS(from_json(to.exclude_upgraded_, from.extract_field("exclude_upgraded")));
  TRY_STATUS(from_json(to.exclude_without_colors_, from.extract_field("exclude_without_colors")));
  TRY_STATUS(from_json(to.exclude_hosted_, from.extract_field("exclude_hosted")));
  TRY_STATUS(from_json(to.sort_by_price_, from.extract_field("sort_by_price")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getRemoteFile &to, JsonObject &from) {
  TRY_STATUS(from_json(to.remote_file_id_, from.extract_field("remote_file_id")));
  TRY_STATUS(from_json(to.file_type_, from.extract_field("file_type")));
  return Status::OK();
}

Status from_json(td_api::getScopeNotificationSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.scope_, from.extract_field("scope")));
  return Status::OK();
}

Status from_json(td_api::getStarRevenueStatistics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.is_dark_, from.extract_field("is_dark")));
  return Status::OK();
}

Status from_json(td_api::getStickerSetName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.set_id_, from.extract_field("set_id")));
  return Status::OK();
}

Status from_json(td_api::getStoryPublicForwards &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getSupportName &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getTonTransactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.direction_, from.extract_field("direction")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getUpgradedGiftsPromotionalAnimation &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getVideoChatAvailableParticipants &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::hideContactCloseBirthdays &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::joinChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::loadActiveStories &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_list_, from.extract_field("story_list")));
  return Status::OK();
}

Status from_json(td_api::openBotSimilarBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.opened_bot_user_id_, from.extract_field("opened_bot_user_id")));
  return Status::OK();
}

Status from_json(td_api::parseMarkdown &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::processChatJoinRequest &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.approve_, from.extract_field("approve")));
  return Status::OK();
}

Status from_json(td_api::readAllForumTopicMentions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  return Status::OK();
}

Status from_json(td_api::recoverPassword &to, JsonObject &from) {
  TRY_STATUS(from_json(to.recovery_code_, from.extract_field("recovery_code")));
  TRY_STATUS(from_json(to.new_password_, from.extract_field("new_password")));
  TRY_STATUS(from_json(to.new_hint_, from.extract_field("new_hint")));
  return Status::OK();
}

Status from_json(td_api::removeFileFromDownloads &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  TRY_STATUS(from_json(to.delete_from_cache_, from.extract_field("delete_from_cache")));
  return Status::OK();
}

Status from_json(td_api::removePendingPaidMessageReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::removeStickerFromSet &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  return Status::OK();
}

Status from_json(td_api::reorderInstalledStickerSets &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_type_, from.extract_field("sticker_type")));
  TRY_STATUS(from_json(to.sticker_set_ids_, from.extract_field("sticker_set_ids")));
  return Status::OK();
}

Status from_json(td_api::reportAuthenticationCodeMissing &to, JsonObject &from) {
  TRY_STATUS(from_json(to.mobile_network_code_, from.extract_field("mobile_network_code")));
  return Status::OK();
}

Status from_json(td_api::reportSupergroupSpam &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.message_ids_, from.extract_field("message_ids")));
  return Status::OK();
}

Status from_json(td_api::resendPhoneNumberCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.reason_, from.extract_field("reason")));
  return Status::OK();
}

Status from_json(td_api::revokeGroupCallInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::searchChatMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.sender_id_, from.extract_field("sender_id")));
  TRY_STATUS(from_json(to.from_message_id_, from.extract_field("from_message_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  TRY_STATUS(from_json(to.filter_, from.extract_field("filter")));
  return Status::OK();
}

Status from_json(td_api::searchInstalledStickerSets &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_type_, from.extract_field("sticker_type")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchPublicStoriesByVenue &to, JsonObject &from) {
  TRY_STATUS(from_json(to.venue_provider_, from.extract_field("venue_provider")));
  TRY_STATUS(from_json(to.venue_id_, from.extract_field("venue_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchUserByPhoneNumber &to, JsonObject &from) {
  TRY_STATUS(from_json(to.phone_number_, from.extract_field("phone_number")));
  TRY_STATUS(from_json(to.only_local_, from.extract_field("only_local")));
  return Status::OK();
}

Status from_json(td_api::sendCallLog &to, JsonObject &from) {
  TRY_STATUS(from_json(to.call_id_, from.extract_field("call_id")));
  TRY_STATUS(from_json(to.log_file_, from.extract_field("log_file")));
  return Status::OK();
}

Status from_json(td_api::sendInlineQueryResultMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.reply_to_, from.extract_field("reply_to")));
  TRY_STATUS(from_json(to.options_, from.extract_field("options")));
  TRY_STATUS(from_json(to.query_id_, from.extract_field("query_id")));
  TRY_STATUS(from_json(to.result_id_, from.extract_field("result_id")));
  TRY_STATUS(from_json(to.hide_via_bot_, from.extract_field("hide_via_bot")));
  return Status::OK();
}

Status from_json(td_api::sendResoldGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.gift_name_, from.extract_field("gift_name")));
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.price_, from.extract_field("price")));
  return Status::OK();
}

Status from_json(td_api::setAuthenticationEmailAddress &to, JsonObject &from) {
  TRY_STATUS(from_json(to.email_address_, from.extract_field("email_address")));
  return Status::OK();
}

Status from_json(td_api::setBotName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::setBusinessConnectedBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_, from.extract_field("bot")));
  return Status::OK();
}

Status from_json(td_api::setChatAvailableReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.available_reactions_, from.extract_field("available_reactions")));
  return Status::OK();
}

Status from_json(td_api::setChatMemberStatus &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.member_id_, from.extract_field("member_id")));
  TRY_STATUS(from_json(to.status_, from.extract_field("status")));
  return Status::OK();
}

Status from_json(td_api::setChatProfileAccentColor &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.profile_accent_color_id_, from.extract_field("profile_accent_color_id")));
  TRY_STATUS(from_json(to.profile_background_custom_emoji_id_, from.extract_field("profile_background_custom_emoji_id")));
  return Status::OK();
}

Status from_json(td_api::setDatabaseEncryptionKey &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.new_encryption_key_, from.extract_field("new_encryption_key")));
  return Status::OK();
}

Status from_json(td_api::setForumTopicNotificationSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  TRY_STATUS(from_json(to.notification_settings_, from.extract_field("notification_settings")));
  return Status::OK();
}

Status from_json(td_api::setInlineGameScore &to, JsonObject &from) {
  TRY_STATUS(from_json(to.inline_message_id_, from.extract_field("inline_message_id")));
  TRY_STATUS(from_json(to.edit_message_, from.extract_field("edit_message")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.score_, from.extract_field("score")));
  TRY_STATUS(from_json(to.force_, from.extract_field("force")));
  return Status::OK();
}

Status from_json(td_api::setMessageReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reaction_types_, from.extract_field("reaction_types")));
  TRY_STATUS(from_json(to.is_big_, from.extract_field("is_big")));
  return Status::OK();
}

Status from_json(td_api::setPassportElementErrors &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.errors_, from.extract_field("errors")));
  return Status::OK();
}

Status from_json(td_api::setProfileAudioPosition &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  TRY_STATUS(from_json(to.after_file_id_, from.extract_field("after_file_id")));
  return Status::OK();
}

Status from_json(td_api::setStickerKeywords &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  TRY_STATUS(from_json(to.keywords_, from.extract_field("keywords")));
  return Status::OK();
}

Status from_json(td_api::setSupergroupMainProfileTab &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.main_profile_tab_, from.extract_field("main_profile_tab")));
  return Status::OK();
}

Status from_json(td_api::setUserPrivacySettingRules &to, JsonObject &from) {
  TRY_STATUS(from_json(to.setting_, from.extract_field("setting")));
  TRY_STATUS(from_json(to.rules_, from.extract_field("rules")));
  return Status::OK();
}

Status from_json(td_api::startGroupCallScreenSharing &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.audio_source_id_, from.extract_field("audio_source_id")));
  TRY_STATUS(from_json(to.payload_, from.extract_field("payload")));
  return Status::OK();
}

Status from_json(td_api::terminateAllOtherSessions &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::testGetDifference &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::toggleBotUsernameIsActive &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  TRY_STATUS(from_json(to.is_active_, from.extract_field("is_active")));
  return Status::OK();
}

Status from_json(td_api::toggleChatViewAsTopics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.view_as_topics_, from.extract_field("view_as_topics")));
  return Status::OK();
}

Status from_json(td_api::toggleGroupCallIsMyVideoPaused &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.is_my_video_paused_, from.extract_field("is_my_video_paused")));
  return Status::OK();
}

Status from_json(td_api::toggleSupergroupCanHaveSponsoredMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.can_have_sponsored_messages_, from.extract_field("can_have_sponsored_messages")));
  return Status::OK();
}

Status from_json(td_api::toggleSupergroupSignMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.sign_messages_, from.extract_field("sign_messages")));
  TRY_STATUS(from_json(to.show_message_sender_, from.extract_field("show_message_sender")));
  return Status::OK();
}

Status from_json(td_api::translateText &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.to_language_code_, from.extract_field("to_language_code")));
  TRY_STATUS(from_json(to.tone_, from.extract_field("tone")));
  return Status::OK();
}

Status from_json(td_api::viewMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_ids_, from.extract_field("message_ids")));
  TRY_STATUS(from_json(to.source_, from.extract_field("source")));
  TRY_STATUS(from_json(to.force_read_, from.extract_field("force_read")));
  return Status::OK();
}

void to_json(JsonValueScope &jv, const td_api::accountTtl &object) {
  auto jo = jv.enter_object();
  jo("@type", "accountTtl");
  jo("days", object.days_);
}

void to_json(JsonValueScope &jv, const td_api::affiliateProgramInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "affiliateProgramInfo");
  if (object.parameters_) {
    jo("parameters", ToJson(*object.parameters_));
  }
  jo("end_date", object.end_date_);
  if (object.daily_revenue_per_user_amount_) {
    jo("daily_revenue_per_user_amount", ToJson(*object.daily_revenue_per_user_amount_));
  }
}

void to_json(JsonValueScope &jv, const td_api::attachmentMenuBot &object) {
  auto jo = jv.enter_object();
  jo("@type", "attachmentMenuBot");
  jo("bot_user_id", object.bot_user_id_);
  jo("supports_self_chat", JsonBool{object.supports_self_chat_});
  jo("supports_user_chats", JsonBool{object.supports_user_chats_});
  jo("supports_bot_chats", JsonBool{object.supports_bot_chats_});
  jo("supports_group_chats", JsonBool{object.supports_group_chats_});
  jo("supports_channel_chats", JsonBool{object.supports_channel_chats_});
  jo("request_write_access", JsonBool{object.request_write_access_});
  jo("is_added", JsonBool{object.is_added_});
  jo("show_in_attachment_menu", JsonBool{object.show_in_attachment_menu_});
  jo("show_in_side_menu", JsonBool{object.show_in_side_menu_});
  jo("show_disclaimer_in_side_menu", JsonBool{object.show_disclaimer_in_side_menu_});
  jo("name", object.name_);
  if (object.name_color_) {
    jo("name_color", ToJson(*object.name_color_));
  }
  if (object.default_icon_) {
    jo("default_icon", ToJson(*object.default_icon_));
  }
  if (object.ios_static_icon_) {
    jo("ios_static_icon", ToJson(*object.ios_static_icon_));
  }
  if (object.ios_animated_icon_) {
    jo("ios_animated_icon", ToJson(*object.ios_animated_icon_));
  }
  if (object.ios_side_menu_icon_) {
    jo("ios_side_menu_icon", ToJson(*object.ios_side_menu_icon_));
  }
  if (object.android_icon_) {
    jo("android_icon", ToJson(*object.android_icon_));
  }
  if (object.android_side_menu_icon_) {
    jo("android_side_menu_icon", ToJson(*object.android_side_menu_icon_));
  }
  if (object.macos_icon_) {
    jo("macos_icon", ToJson(*object.macos_icon_));
  }
  if (object.macos_side_menu_icon_) {
    jo("macos_side_menu_icon", ToJson(*object.macos_side_menu_icon_));
  }
  if (object.icon_color_) {
    jo("icon_color", ToJson(*object.icon_color_));
  }
  if (object.web_app_placeholder_) {
    jo("web_app_placeholder", ToJson(*object.web_app_placeholder_));
  }
}

void to_json(JsonValueScope &jv, const td_api::AuthenticationCodeType &object) {
  td_api::downcast_call(const_cast<td_api::AuthenticationCodeType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::authenticationCodeTypeTelegramMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "authenticationCodeTypeTelegramMessage");
  jo("length", object.length_);
}

void to_json(JsonValueScope &jv, const td_api::authenticationCodeTypeSms &object) {
  auto jo = jv.enter_object();
  jo("@type", "authenticationCodeTypeSms");
  jo("length", object.length_);
}

void to_json(JsonValueScope &jv, const td_api::authenticationCodeTypeSmsWord &object) {
  auto jo = jv.enter_object();
  jo("@type", "authenticationCodeTypeSmsWord");
  jo("first_letter", object.first_letter_);
}

void to_json(JsonValueScope &jv, const td_api::authenticationCodeTypeSmsPhrase &object) {
  auto jo = jv.enter_object();
  jo("@type", "authenticationCodeTypeSmsPhrase");
  jo("first_word", object.first_word_);
}

void to_json(JsonValueScope &jv, const td_api::authenticationCodeTypeCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "authenticationCodeTypeCall");
  jo("length", object.length_);
}

void to_json(JsonValueScope &jv, const td_api::authenticationCodeTypeFlashCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "authenticationCodeTypeFlashCall");
  jo("pattern", object.pattern_);
}

void to_json(JsonValueScope &jv, const td_api::authenticationCodeTypeMissedCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "authenticationCodeTypeMissedCall");
  jo("phone_number_prefix", object.phone_number_prefix_);
  jo("length", object.length_);
}

void to_json(JsonValueScope &jv, const td_api::authenticationCodeTypeFragment &object) {
  auto jo = jv.enter_object();
  jo("@type", "authenticationCodeTypeFragment");
  jo("url", object.url_);
  jo("length", object.length_);
}

void to_json(JsonValueScope &jv, const td_api::authenticationCodeTypeFirebaseAndroid &object) {
  auto jo = jv.enter_object();
  jo("@type", "authenticationCodeTypeFirebaseAndroid");
  if (object.device_verification_parameters_) {
    jo("device_verification_parameters", ToJson(*object.device_verification_parameters_));
  }
  jo("length", object.length_);
}

void to_json(JsonValueScope &jv, const td_api::authenticationCodeTypeFirebaseIos &object) {
  auto jo = jv.enter_object();
  jo("@type", "authenticationCodeTypeFirebaseIos");
  jo("receipt", object.receipt_);
  jo("push_timeout", object.push_timeout_);
  jo("length", object.length_);
}

void to_json(JsonValueScope &jv, const td_api::availableReaction &object) {
  auto jo = jv.enter_object();
  jo("@type", "availableReaction");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("needs_premium", JsonBool{object.needs_premium_});
}

void to_json(JsonValueScope &jv, const td_api::basicGroupFullInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "basicGroupFullInfo");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("description", object.description_);
  jo("creator_user_id", object.creator_user_id_);
  jo("members", ToJson(object.members_));
  jo("can_hide_members", JsonBool{object.can_hide_members_});
  jo("can_toggle_aggressive_anti_spam", JsonBool{object.can_toggle_aggressive_anti_spam_});
  if (object.invite_link_) {
    jo("invite_link", ToJson(*object.invite_link_));
  }
  jo("bot_commands", ToJson(object.bot_commands_));
}

void to_json(JsonValueScope &jv, const td_api::botMenuButton &object) {
  auto jo = jv.enter_object();
  jo("@type", "botMenuButton");
  jo("text", object.text_);
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::businessChatLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessChatLink");
  jo("link", object.link_);
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("title", object.title_);
  jo("view_count", object.view_count_);
}

void to_json(JsonValueScope &jv, const td_api::businessInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessInfo");
  if (object.location_) {
    jo("location", ToJson(*object.location_));
  }
  if (object.opening_hours_) {
    jo("opening_hours", ToJson(*object.opening_hours_));
  }
  if (object.local_opening_hours_) {
    jo("local_opening_hours", ToJson(*object.local_opening_hours_));
  }
  jo("next_open_in", object.next_open_in_);
  jo("next_close_in", object.next_close_in_);
  if (object.greeting_message_settings_) {
    jo("greeting_message_settings", ToJson(*object.greeting_message_settings_));
  }
  if (object.away_message_settings_) {
    jo("away_message_settings", ToJson(*object.away_message_settings_));
  }
  if (object.start_page_) {
    jo("start_page", ToJson(*object.start_page_));
  }
}

void to_json(JsonValueScope &jv, const td_api::call &object) {
  auto jo = jv.enter_object();
  jo("@type", "call");
  jo("id", object.id_);
  jo("unique_id", ToJson(JsonInt64{object.unique_id_}));
  jo("user_id", object.user_id_);
  jo("is_outgoing", JsonBool{object.is_outgoing_});
  jo("is_video", JsonBool{object.is_video_});
  if (object.state_) {
    jo("state", ToJson(*object.state_));
  }
}

void to_json(JsonValueScope &jv, const td_api::CanPostStoryResult &object) {
  td_api::downcast_call(const_cast<td_api::CanPostStoryResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::canPostStoryResultOk &object) {
  auto jo = jv.enter_object();
  jo("@type", "canPostStoryResultOk");
  jo("story_count", object.story_count_);
}

void to_json(JsonValueScope &jv, const td_api::canPostStoryResultPremiumNeeded &object) {
  auto jo = jv.enter_object();
  jo("@type", "canPostStoryResultPremiumNeeded");
}

void to_json(JsonValueScope &jv, const td_api::canPostStoryResultBoostNeeded &object) {
  auto jo = jv.enter_object();
  jo("@type", "canPostStoryResultBoostNeeded");
}

void to_json(JsonValueScope &jv, const td_api::canPostStoryResultActiveStoryLimitExceeded &object) {
  auto jo = jv.enter_object();
  jo("@type", "canPostStoryResultActiveStoryLimitExceeded");
}

void to_json(JsonValueScope &jv, const td_api::canPostStoryResultWeeklyLimitExceeded &object) {
  auto jo = jv.enter_object();
  jo("@type", "canPostStoryResultWeeklyLimitExceeded");
  jo("retry_after", object.retry_after_);
}

void to_json(JsonValueScope &jv, const td_api::canPostStoryResultMonthlyLimitExceeded &object) {
  auto jo = jv.enter_object();
  jo("@type", "canPostStoryResultMonthlyLimitExceeded");
  jo("retry_after", object.retry_after_);
}

void to_json(JsonValueScope &jv, const td_api::canPostStoryResultLiveStoryIsActive &object) {
  auto jo = jv.enter_object();
  jo("@type", "canPostStoryResultLiveStoryIsActive");
  jo("story_id", object.story_id_);
}

void to_json(JsonValueScope &jv, const td_api::chatAdministratorRights &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatAdministratorRights");
  jo("can_manage_chat", JsonBool{object.can_manage_chat_});
  jo("can_change_info", JsonBool{object.can_change_info_});
  jo("can_post_messages", JsonBool{object.can_post_messages_});
  jo("can_edit_messages", JsonBool{object.can_edit_messages_});
  jo("can_delete_messages", JsonBool{object.can_delete_messages_});
  jo("can_invite_users", JsonBool{object.can_invite_users_});
  jo("can_restrict_members", JsonBool{object.can_restrict_members_});
  jo("can_pin_messages", JsonBool{object.can_pin_messages_});
  jo("can_manage_topics", JsonBool{object.can_manage_topics_});
  jo("can_promote_members", JsonBool{object.can_promote_members_});
  jo("can_manage_video_chats", JsonBool{object.can_manage_video_chats_});
  jo("can_post_stories", JsonBool{object.can_post_stories_});
  jo("can_edit_stories", JsonBool{object.can_edit_stories_});
  jo("can_delete_stories", JsonBool{object.can_delete_stories_});
  jo("can_manage_direct_messages", JsonBool{object.can_manage_direct_messages_});
  jo("can_manage_tags", JsonBool{object.can_manage_tags_});
  jo("is_anonymous", JsonBool{object.is_anonymous_});
}

void to_json(JsonValueScope &jv, const td_api::chatBoostSlot &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatBoostSlot");
  jo("slot_id", object.slot_id_);
  jo("currently_boosted_chat_id", object.currently_boosted_chat_id_);
  jo("start_date", object.start_date_);
  jo("expiration_date", object.expiration_date_);
  jo("cooldown_until_date", object.cooldown_until_date_);
}

void to_json(JsonValueScope &jv, const td_api::chatFolderInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatFolderInfo");
  jo("id", object.id_);
  if (object.name_) {
    jo("name", ToJson(*object.name_));
  }
  if (object.icon_) {
    jo("icon", ToJson(*object.icon_));
  }
  jo("color_id", object.color_id_);
  jo("is_shareable", JsonBool{object.is_shareable_});
  jo("has_my_invite_links", JsonBool{object.has_my_invite_links_});
}

void to_json(JsonValueScope &jv, const td_api::chatInviteLinkMember &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatInviteLinkMember");
  jo("user_id", object.user_id_);
  jo("joined_chat_date", object.joined_chat_date_);
  jo("via_chat_folder_invite_link", JsonBool{object.via_chat_folder_invite_link_});
  jo("approver_user_id", object.approver_user_id_);
}

void to_json(JsonValueScope &jv, const td_api::chatLocation &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatLocation");
  if (object.location_) {
    jo("location", ToJson(*object.location_));
  }
  jo("address", object.address_);
}

void to_json(JsonValueScope &jv, const td_api::chatPhotoInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatPhotoInfo");
  if (object.small_) {
    jo("small", ToJson(*object.small_));
  }
  if (object.big_) {
    jo("big", ToJson(*object.big_));
  }
  if (object.minithumbnail_) {
    jo("minithumbnail", ToJson(*object.minithumbnail_));
  }
  jo("has_animation", JsonBool{object.has_animation_});
  jo("is_personal", JsonBool{object.is_personal_});
}

void to_json(JsonValueScope &jv, const td_api::chatRevenueTransactions &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatRevenueTransactions");
  jo("ton_amount", object.ton_amount_);
  jo("transactions", ToJson(object.transactions_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::ChatType &object) {
  td_api::downcast_call(const_cast<td_api::ChatType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatTypePrivate &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatTypePrivate");
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::chatTypeBasicGroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatTypeBasicGroup");
  jo("basic_group_id", object.basic_group_id_);
}

void to_json(JsonValueScope &jv, const td_api::chatTypeSupergroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatTypeSupergroup");
  jo("supergroup_id", object.supergroup_id_);
  jo("is_channel", JsonBool{object.is_channel_});
}

void to_json(JsonValueScope &jv, const td_api::chatTypeSecret &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatTypeSecret");
  jo("secret_chat_id", object.secret_chat_id_);
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::connectedAffiliateProgram &object) {
  auto jo = jv.enter_object();
  jo("@type", "connectedAffiliateProgram");
  jo("url", object.url_);
  jo("bot_user_id", object.bot_user_id_);
  if (object.parameters_) {
    jo("parameters", ToJson(*object.parameters_));
  }
  jo("connection_date", object.connection_date_);
  jo("is_disconnected", JsonBool{object.is_disconnected_});
  jo("user_count", ToJson(JsonInt64{object.user_count_}));
  jo("revenue_star_count", object.revenue_star_count_);
}

void to_json(JsonValueScope &jv, const td_api::CraftGiftResult &object) {
  td_api::downcast_call(const_cast<td_api::CraftGiftResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::craftGiftResultSuccess &object) {
  auto jo = jv.enter_object();
  jo("@type", "craftGiftResultSuccess");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  jo("received_gift_id", object.received_gift_id_);
}

void to_json(JsonValueScope &jv, const td_api::craftGiftResultTooEarly &object) {
  auto jo = jv.enter_object();
  jo("@type", "craftGiftResultTooEarly");
  jo("retry_after", object.retry_after_);
}

void to_json(JsonValueScope &jv, const td_api::craftGiftResultInvalidGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "craftGiftResultInvalidGift");
}

void to_json(JsonValueScope &jv, const td_api::craftGiftResultFail &object) {
  auto jo = jv.enter_object();
  jo("@type", "craftGiftResultFail");
}

void to_json(JsonValueScope &jv, const td_api::DateTimePartPrecision &object) {
  td_api::downcast_call(const_cast<td_api::DateTimePartPrecision &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::dateTimePartPrecisionNone &object) {
  auto jo = jv.enter_object();
  jo("@type", "dateTimePartPrecisionNone");
}

void to_json(JsonValueScope &jv, const td_api::dateTimePartPrecisionShort &object) {
  auto jo = jv.enter_object();
  jo("@type", "dateTimePartPrecisionShort");
}

void to_json(JsonValueScope &jv, const td_api::dateTimePartPrecisionLong &object) {
  auto jo = jv.enter_object();
  jo("@type", "dateTimePartPrecisionLong");
}

void to_json(JsonValueScope &jv, const td_api::downloadedFileCounts &object) {
  auto jo = jv.enter_object();
  jo("@type", "downloadedFileCounts");
  jo("active_count", object.active_count_);
  jo("paused_count", object.paused_count_);
  jo("completed_count", object.completed_count_);
}

void to_json(JsonValueScope &jv, const td_api::emojiKeywords &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiKeywords");
  jo("emoji_keywords", ToJson(object.emoji_keywords_));
}

void to_json(JsonValueScope &jv, const td_api::error &object) {
  auto jo = jv.enter_object();
  jo("@type", "error");
  jo("code", object.code_);
  jo("message", object.message_);
}

void to_json(JsonValueScope &jv, const td_api::fixedText &object) {
  auto jo = jv.enter_object();
  jo("@type", "fixedText");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  if (object.diff_text_) {
    jo("diff_text", ToJson(*object.diff_text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::foundChatBoosts &object) {
  auto jo = jv.enter_object();
  jo("@type", "foundChatBoosts");
  jo("total_count", object.total_count_);
  jo("boosts", ToJson(object.boosts_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::foundWebApp &object) {
  auto jo = jv.enter_object();
  jo("@type", "foundWebApp");
  if (object.web_app_) {
    jo("web_app", ToJson(*object.web_app_));
  }
  jo("request_write_access", JsonBool{object.request_write_access_});
  jo("skip_confirmation", JsonBool{object.skip_confirmation_});
}

void to_json(JsonValueScope &jv, const td_api::giftBackground &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftBackground");
  jo("center_color", object.center_color_);
  jo("edge_color", object.edge_color_);
  jo("text_color", object.text_color_);
}

void to_json(JsonValueScope &jv, const td_api::GiftResalePrice &object) {
  td_api::downcast_call(const_cast<td_api::GiftResalePrice &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::giftResalePriceStar &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftResalePriceStar");
  jo("star_count", object.star_count_);
}

void to_json(JsonValueScope &jv, const td_api::giftResalePriceTon &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftResalePriceTon");
  jo("toncoin_cent_count", object.toncoin_cent_count_);
}

void to_json(JsonValueScope &jv, const td_api::giveawayParameters &object) {
  auto jo = jv.enter_object();
  jo("@type", "giveawayParameters");
  jo("boosted_chat_id", object.boosted_chat_id_);
  jo("additional_chat_ids", ToJson(object.additional_chat_ids_));
  jo("winners_selection_date", object.winners_selection_date_);
  jo("only_new_members", JsonBool{object.only_new_members_});
  jo("has_public_winners", JsonBool{object.has_public_winners_});
  jo("country_codes", ToJson(object.country_codes_));
  jo("prize_description", object.prize_description_);
}

void to_json(JsonValueScope &jv, const td_api::groupCallParticipantVideoInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "groupCallParticipantVideoInfo");
  jo("source_groups", ToJson(object.source_groups_));
  jo("endpoint_id", object.endpoint_id_);
  jo("is_paused", JsonBool{object.is_paused_});
}

void to_json(JsonValueScope &jv, const td_api::importedContacts &object) {
  auto jo = jv.enter_object();
  jo("@type", "importedContacts");
  jo("user_ids", ToJson(object.user_ids_));
  jo("importer_count", ToJson(object.importer_count_));
}

void to_json(JsonValueScope &jv, const td_api::InputFile &object) {
  td_api::downcast_call(const_cast<td_api::InputFile &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::inputFileId &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputFileId");
  jo("id", object.id_);
}

void to_json(JsonValueScope &jv, const td_api::inputFileRemote &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputFileRemote");
  jo("id", object.id_);
}

void to_json(JsonValueScope &jv, const td_api::inputFileLocal &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputFileLocal");
  jo("path", object.path_);
}

void to_json(JsonValueScope &jv, const td_api::inputFileGenerated &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputFileGenerated");
  jo("original_path", object.original_path_);
  jo("conversion", object.conversion_);
  jo("expected_size", object.expected_size_);
}

void to_json(JsonValueScope &jv, const td_api::inputThumbnail &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputThumbnail");
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  jo("width", object.width_);
  jo("height", object.height_);
}

void to_json(JsonValueScope &jv, const td_api::labeledPricePart &object) {
  auto jo = jv.enter_object();
  jo("@type", "labeledPricePart");
  jo("label", object.label_);
  jo("amount", object.amount_);
}

void to_json(JsonValueScope &jv, const td_api::liveStoryDonors &object) {
  auto jo = jv.enter_object();
  jo("@type", "liveStoryDonors");
  jo("total_star_count", object.total_star_count_);
  jo("top_donors", ToJson(object.top_donors_));
}

void to_json(JsonValueScope &jv, const td_api::mainWebApp &object) {
  auto jo = jv.enter_object();
  jo("@type", "mainWebApp");
  jo("url", object.url_);
  if (object.mode_) {
    jo("mode", ToJson(*object.mode_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messageEffect &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageEffect");
  jo("id", ToJson(JsonInt64{object.id_}));
  if (object.static_icon_) {
    jo("static_icon", ToJson(*object.static_icon_));
  }
  jo("emoji", object.emoji_);
  jo("is_premium", JsonBool{object.is_premium_});
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::messagePosition &object) {
  auto jo = jv.enter_object();
  jo("@type", "messagePosition");
  jo("position", object.position_);
  jo("message_id", object.message_id_);
  jo("date", object.date_);
}

void to_json(JsonValueScope &jv, const td_api::MessageSelfDestructType &object) {
  td_api::downcast_call(const_cast<td_api::MessageSelfDestructType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::messageSelfDestructTypeTimer &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSelfDestructTypeTimer");
  jo("self_destruct_time", object.self_destruct_time_);
}

void to_json(JsonValueScope &jv, const td_api::messageSelfDestructTypeImmediately &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSelfDestructTypeImmediately");
}

void to_json(JsonValueScope &jv, const td_api::messages &object) {
  auto jo = jv.enter_object();
  jo("@type", "messages");
  jo("total_count", object.total_count_);
  jo("messages", ToJson(object.messages_));
}

void to_json(JsonValueScope &jv, const td_api::NotificationSettingsScope &object) {
  td_api::downcast_call(const_cast<td_api::NotificationSettingsScope &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::notificationSettingsScopePrivateChats &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationSettingsScopePrivateChats");
}

void to_json(JsonValueScope &jv, const td_api::notificationSettingsScopeGroupChats &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationSettingsScopeGroupChats");
}

void to_json(JsonValueScope &jv, const td_api::notificationSettingsScopeChannelChats &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationSettingsScopeChannelChats");
}

void to_json(JsonValueScope &jv, const td_api::PageBlock &object) {
  td_api::downcast_call(const_cast<td_api::PageBlock &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::pageBlockTitle &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockTitle");
  if (object.title_) {
    jo("title", ToJson(*object.title_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockSubtitle &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockSubtitle");
  if (object.subtitle_) {
    jo("subtitle", ToJson(*object.subtitle_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockAuthorDate &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockAuthorDate");
  if (object.author_) {
    jo("author", ToJson(*object.author_));
  }
  jo("publish_date", object.publish_date_);
}

void to_json(JsonValueScope &jv, const td_api::pageBlockHeader &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockHeader");
  if (object.header_) {
    jo("header", ToJson(*object.header_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockSubheader &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockSubheader");
  if (object.subheader_) {
    jo("subheader", ToJson(*object.subheader_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockKicker &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockKicker");
  if (object.kicker_) {
    jo("kicker", ToJson(*object.kicker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockParagraph &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockParagraph");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockPreformatted &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockPreformatted");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("language", object.language_);
}

void to_json(JsonValueScope &jv, const td_api::pageBlockFooter &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockFooter");
  if (object.footer_) {
    jo("footer", ToJson(*object.footer_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockDivider &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockDivider");
}

void to_json(JsonValueScope &jv, const td_api::pageBlockAnchor &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockAnchor");
  jo("name", object.name_);
}

void to_json(JsonValueScope &jv, const td_api::pageBlockList &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockList");
  jo("items", ToJson(object.items_));
}

void to_json(JsonValueScope &jv, const td_api::pageBlockBlockQuote &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockBlockQuote");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  if (object.credit_) {
    jo("credit", ToJson(*object.credit_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockPullQuote &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockPullQuote");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  if (object.credit_) {
    jo("credit", ToJson(*object.credit_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockAnimation &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockAnimation");
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("need_autoplay", JsonBool{object.need_autoplay_});
}

void to_json(JsonValueScope &jv, const td_api::pageBlockAudio &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockAudio");
  if (object.audio_) {
    jo("audio", ToJson(*object.audio_));
  }
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockPhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockPhoto");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::pageBlockVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockVideo");
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("need_autoplay", JsonBool{object.need_autoplay_});
  jo("is_looped", JsonBool{object.is_looped_});
}

void to_json(JsonValueScope &jv, const td_api::pageBlockVoiceNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockVoiceNote");
  if (object.voice_note_) {
    jo("voice_note", ToJson(*object.voice_note_));
  }
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockCover &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockCover");
  if (object.cover_) {
    jo("cover", ToJson(*object.cover_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockEmbedded &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockEmbedded");
  jo("url", object.url_);
  jo("html", object.html_);
  if (object.poster_photo_) {
    jo("poster_photo", ToJson(*object.poster_photo_));
  }
  jo("width", object.width_);
  jo("height", object.height_);
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("is_full_width", JsonBool{object.is_full_width_});
  jo("allow_scrolling", JsonBool{object.allow_scrolling_});
}

void to_json(JsonValueScope &jv, const td_api::pageBlockEmbeddedPost &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockEmbeddedPost");
  jo("url", object.url_);
  jo("author", object.author_);
  if (object.author_photo_) {
    jo("author_photo", ToJson(*object.author_photo_));
  }
  jo("date", object.date_);
  jo("page_blocks", ToJson(object.page_blocks_));
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockCollage &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockCollage");
  jo("page_blocks", ToJson(object.page_blocks_));
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockSlideshow &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockSlideshow");
  jo("page_blocks", ToJson(object.page_blocks_));
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
}

void to_json(JsonValueScope &jv, const td_api::pageBlockChatLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockChatLink");
  jo("title", object.title_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("accent_color_id", object.accent_color_id_);
  jo("username", object.username_);
}

void to_json(JsonValueScope &jv, const td_api::pageBlockTable &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockTable");
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
  jo("cells", ToJson(object.cells_));
  jo("is_bordered", JsonBool{object.is_bordered_});
  jo("is_striped", JsonBool{object.is_striped_});
}

void to_json(JsonValueScope &jv, const td_api::pageBlockDetails &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockDetails");
  if (object.header_) {
    jo("header", ToJson(*object.header_));
  }
  jo("page_blocks", ToJson(object.page_blocks_));
  jo("is_open", JsonBool{object.is_open_});
}

void to_json(JsonValueScope &jv, const td_api::pageBlockRelatedArticles &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockRelatedArticles");
  if (object.header_) {
    jo("header", ToJson(*object.header_));
  }
  jo("articles", ToJson(object.articles_));
}

void to_json(JsonValueScope &jv, const td_api::pageBlockMap &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockMap");
  if (object.location_) {
    jo("location", ToJson(*object.location_));
  }
  jo("zoom", object.zoom_);
  jo("width", object.width_);
  jo("height", object.height_);
  if (object.caption_) {
    jo("caption", ToJson(*object.caption_));
  }
}

void to_json(JsonValueScope &jv, const td_api::paidReactor &object) {
  auto jo = jv.enter_object();
  jo("@type", "paidReactor");
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  jo("star_count", object.star_count_);
  jo("is_top", JsonBool{object.is_top_});
  jo("is_me", JsonBool{object.is_me_});
  jo("is_anonymous", JsonBool{object.is_anonymous_});
}

void to_json(JsonValueScope &jv, const td_api::passportElementsWithErrors &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElementsWithErrors");
  jo("elements", ToJson(object.elements_));
  jo("errors", ToJson(object.errors_));
}

void to_json(JsonValueScope &jv, const td_api::PaymentReceiptType &object) {
  td_api::downcast_call(const_cast<td_api::PaymentReceiptType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::paymentReceiptTypeRegular &object) {
  auto jo = jv.enter_object();
  jo("@type", "paymentReceiptTypeRegular");
  jo("payment_provider_user_id", object.payment_provider_user_id_);
  if (object.invoice_) {
    jo("invoice", ToJson(*object.invoice_));
  }
  if (object.order_info_) {
    jo("order_info", ToJson(*object.order_info_));
  }
  if (object.shipping_option_) {
    jo("shipping_option", ToJson(*object.shipping_option_));
  }
  jo("credentials_title", object.credentials_title_);
  jo("tip_amount", object.tip_amount_);
}

void to_json(JsonValueScope &jv, const td_api::paymentReceiptTypeStars &object) {
  auto jo = jv.enter_object();
  jo("@type", "paymentReceiptTypeStars");
  jo("star_count", object.star_count_);
  jo("transaction_id", object.transaction_id_);
}

void to_json(JsonValueScope &jv, const td_api::pollOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "pollOption");
  jo("id", object.id_);
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  if (object.media_) {
    jo("media", ToJson(*object.media_));
  }
  jo("voter_count", object.voter_count_);
  jo("vote_percentage", object.vote_percentage_);
  jo("recent_voter_ids", ToJson(object.recent_voter_ids_));
  jo("is_chosen", JsonBool{object.is_chosen_});
  jo("is_being_chosen", JsonBool{object.is_being_chosen_});
  if (object.author_) {
    jo("author", ToJson(*object.author_));
  }
  jo("addition_date", object.addition_date_);
}

void to_json(JsonValueScope &jv, const td_api::premiumGiftPaymentOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumGiftPaymentOption");
  jo("currency", object.currency_);
  jo("amount", object.amount_);
  jo("star_count", object.star_count_);
  jo("discount_percentage", object.discount_percentage_);
  jo("month_count", object.month_count_);
  jo("store_product_id", object.store_product_id_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::prepaidGiveaway &object) {
  auto jo = jv.enter_object();
  jo("@type", "prepaidGiveaway");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("winner_count", object.winner_count_);
  if (object.prize_) {
    jo("prize", ToJson(*object.prize_));
  }
  jo("boost_count", object.boost_count_);
  jo("payment_date", object.payment_date_);
}

void to_json(JsonValueScope &jv, const td_api::ProxyType &object) {
  td_api::downcast_call(const_cast<td_api::ProxyType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::proxyTypeSocks5 &object) {
  auto jo = jv.enter_object();
  jo("@type", "proxyTypeSocks5");
  jo("username", object.username_);
  jo("password", object.password_);
}

void to_json(JsonValueScope &jv, const td_api::proxyTypeHttp &object) {
  auto jo = jv.enter_object();
  jo("@type", "proxyTypeHttp");
  jo("username", object.username_);
  jo("password", object.password_);
  jo("http_only", JsonBool{object.http_only_});
}

void to_json(JsonValueScope &jv, const td_api::proxyTypeMtproto &object) {
  auto jo = jv.enter_object();
  jo("@type", "proxyTypeMtproto");
  jo("secret", object.secret_);
}

void to_json(JsonValueScope &jv, const td_api::reactionNotificationSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "reactionNotificationSettings");
  if (object.message_reaction_source_) {
    jo("message_reaction_source", ToJson(*object.message_reaction_source_));
  }
  if (object.story_reaction_source_) {
    jo("story_reaction_source", ToJson(*object.story_reaction_source_));
  }
  if (object.poll_vote_source_) {
    jo("poll_vote_source", ToJson(*object.poll_vote_source_));
  }
  jo("sound_id", ToJson(JsonInt64{object.sound_id_}));
  jo("show_preview", JsonBool{object.show_preview_});
}

void to_json(JsonValueScope &jv, const td_api::recoveryEmailAddress &object) {
  auto jo = jv.enter_object();
  jo("@type", "recoveryEmailAddress");
  jo("recovery_email_address", object.recovery_email_address_);
}

void to_json(JsonValueScope &jv, const td_api::RevenueWithdrawalState &object) {
  td_api::downcast_call(const_cast<td_api::RevenueWithdrawalState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::revenueWithdrawalStatePending &object) {
  auto jo = jv.enter_object();
  jo("@type", "revenueWithdrawalStatePending");
}

void to_json(JsonValueScope &jv, const td_api::revenueWithdrawalStateSucceeded &object) {
  auto jo = jv.enter_object();
  jo("@type", "revenueWithdrawalStateSucceeded");
  jo("date", object.date_);
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::revenueWithdrawalStateFailed &object) {
  auto jo = jv.enter_object();
  jo("@type", "revenueWithdrawalStateFailed");
}

void to_json(JsonValueScope &jv, const td_api::scopeNotificationSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "scopeNotificationSettings");
  jo("mute_for", object.mute_for_);
  jo("sound_id", ToJson(JsonInt64{object.sound_id_}));
  jo("show_preview", JsonBool{object.show_preview_});
  jo("use_default_mute_stories", JsonBool{object.use_default_mute_stories_});
  jo("mute_stories", JsonBool{object.mute_stories_});
  jo("story_sound_id", ToJson(JsonInt64{object.story_sound_id_}));
  jo("show_story_poster", JsonBool{object.show_story_poster_});
  jo("disable_pinned_message_notifications", JsonBool{object.disable_pinned_message_notifications_});
  jo("disable_mention_notifications", JsonBool{object.disable_mention_notifications_});
}

void to_json(JsonValueScope &jv, const td_api::SettingsSection &object) {
  td_api::downcast_call(const_cast<td_api::SettingsSection &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionAppearance &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionAppearance");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionAskQuestion &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionAskQuestion");
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionBusiness &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionBusiness");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionChatFolders &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionChatFolders");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionDataAndStorage &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionDataAndStorage");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionDevices &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionDevices");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionEditProfile &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionEditProfile");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionFaq &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionFaq");
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionFeatures &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionFeatures");
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionInAppBrowser &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionInAppBrowser");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionLanguage &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionLanguage");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionMyStars &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionMyStars");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionMyToncoins &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionMyToncoins");
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionNotifications &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionNotifications");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionPowerSaving &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionPowerSaving");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionPremium &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionPremium");
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionPrivacyAndSecurity &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionPrivacyAndSecurity");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionPrivacyPolicy &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionPrivacyPolicy");
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionQrCode &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionQrCode");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionSearch &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionSearch");
}

void to_json(JsonValueScope &jv, const td_api::settingsSectionSendGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "settingsSectionSendGift");
  jo("subsection", object.subsection_);
}

void to_json(JsonValueScope &jv, const td_api::stakeDiceState &object) {
  auto jo = jv.enter_object();
  jo("@type", "stakeDiceState");
  jo("state_hash", object.state_hash_);
  jo("stake_toncoin_amount", object.stake_toncoin_amount_);
  jo("suggested_stake_toncoin_amounts", ToJson(object.suggested_stake_toncoin_amounts_));
  jo("current_streak", object.current_streak_);
  jo("prize_per_mille", ToJson(object.prize_per_mille_));
  jo("streak_prize_per_mille", object.streak_prize_per_mille_);
}

void to_json(JsonValueScope &jv, const td_api::starRevenueStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "starRevenueStatus");
  if (object.total_amount_) {
    jo("total_amount", ToJson(*object.total_amount_));
  }
  if (object.current_amount_) {
    jo("current_amount", ToJson(*object.current_amount_));
  }
  if (object.available_amount_) {
    jo("available_amount", ToJson(*object.available_amount_));
  }
  jo("withdrawal_enabled", JsonBool{object.withdrawal_enabled_});
  jo("next_withdrawal_in", object.next_withdrawal_in_);
}

void to_json(JsonValueScope &jv, const td_api::StatisticalGraph &object) {
  td_api::downcast_call(const_cast<td_api::StatisticalGraph &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::statisticalGraphData &object) {
  auto jo = jv.enter_object();
  jo("@type", "statisticalGraphData");
  jo("json_data", object.json_data_);
  jo("zoom_token", object.zoom_token_);
}

void to_json(JsonValueScope &jv, const td_api::statisticalGraphAsync &object) {
  auto jo = jv.enter_object();
  jo("@type", "statisticalGraphAsync");
  jo("token", object.token_);
}

void to_json(JsonValueScope &jv, const td_api::statisticalGraphError &object) {
  auto jo = jv.enter_object();
  jo("@type", "statisticalGraphError");
  jo("error_message", object.error_message_);
}

void to_json(JsonValueScope &jv, const td_api::stickers &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickers");
  jo("stickers", ToJson(object.stickers_));
}

void to_json(JsonValueScope &jv, const td_api::storyArea &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyArea");
  if (object.position_) {
    jo("position", ToJson(*object.position_));
  }
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::storyInteractions &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyInteractions");
  jo("total_count", object.total_count_);
  jo("total_forward_count", object.total_forward_count_);
  jo("total_reaction_count", object.total_reaction_count_);
  jo("interactions", ToJson(object.interactions_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::SuggestedPostPrice &object) {
  td_api::downcast_call(const_cast<td_api::SuggestedPostPrice &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::suggestedPostPriceStar &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedPostPriceStar");
  jo("star_count", object.star_count_);
}

void to_json(JsonValueScope &jv, const td_api::suggestedPostPriceTon &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedPostPriceTon");
  jo("toncoin_cent_count", object.toncoin_cent_count_);
}

void to_json(JsonValueScope &jv, const td_api::targetChatTypes &object) {
  auto jo = jv.enter_object();
  jo("@type", "targetChatTypes");
  jo("allow_user_chats", JsonBool{object.allow_user_chats_});
  jo("allow_bot_chats", JsonBool{object.allow_bot_chats_});
  jo("allow_group_chats", JsonBool{object.allow_group_chats_});
  jo("allow_channel_chats", JsonBool{object.allow_channel_chats_});
}

void to_json(JsonValueScope &jv, const td_api::testVectorStringObject &object) {
  auto jo = jv.enter_object();
  jo("@type", "testVectorStringObject");
  jo("value", ToJson(object.value_));
}

void to_json(JsonValueScope &jv, const td_api::ThumbnailFormat &object) {
  td_api::downcast_call(const_cast<td_api::ThumbnailFormat &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::thumbnailFormatJpeg &object) {
  auto jo = jv.enter_object();
  jo("@type", "thumbnailFormatJpeg");
}

void to_json(JsonValueScope &jv, const td_api::thumbnailFormatGif &object) {
  auto jo = jv.enter_object();
  jo("@type", "thumbnailFormatGif");
}

void to_json(JsonValueScope &jv, const td_api::thumbnailFormatMpeg4 &object) {
  auto jo = jv.enter_object();
  jo("@type", "thumbnailFormatMpeg4");
}

void to_json(JsonValueScope &jv, const td_api::thumbnailFormatPng &object) {
  auto jo = jv.enter_object();
  jo("@type", "thumbnailFormatPng");
}

void to_json(JsonValueScope &jv, const td_api::thumbnailFormatTgs &object) {
  auto jo = jv.enter_object();
  jo("@type", "thumbnailFormatTgs");
}

void to_json(JsonValueScope &jv, const td_api::thumbnailFormatWebm &object) {
  auto jo = jv.enter_object();
  jo("@type", "thumbnailFormatWebm");
}

void to_json(JsonValueScope &jv, const td_api::thumbnailFormatWebp &object) {
  auto jo = jv.enter_object();
  jo("@type", "thumbnailFormatWebp");
}

void to_json(JsonValueScope &jv, const td_api::unconfirmedSession &object) {
  auto jo = jv.enter_object();
  jo("@type", "unconfirmedSession");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("log_in_date", object.log_in_date_);
  jo("device_model", object.device_model_);
  jo("location", object.location_);
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftBackdropCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftBackdropCount");
  if (object.backdrop_) {
    jo("backdrop", ToJson(*object.backdrop_));
  }
  jo("total_count", object.total_count_);
}

void to_json(JsonValueScope &jv, const td_api::user &object) {
  auto jo = jv.enter_object();
  jo("@type", "user");
  jo("id", object.id_);
  jo("first_name", object.first_name_);
  jo("last_name", object.last_name_);
  if (object.usernames_) {
    jo("usernames", ToJson(*object.usernames_));
  }
  jo("phone_number", object.phone_number_);
  if (object.status_) {
    jo("status", ToJson(*object.status_));
  }
  if (object.profile_photo_) {
    jo("profile_photo", ToJson(*object.profile_photo_));
  }
  jo("accent_color_id", object.accent_color_id_);
  jo("background_custom_emoji_id", ToJson(JsonInt64{object.background_custom_emoji_id_}));
  if (object.upgraded_gift_colors_) {
    jo("upgraded_gift_colors", ToJson(*object.upgraded_gift_colors_));
  }
  jo("profile_accent_color_id", object.profile_accent_color_id_);
  jo("profile_background_custom_emoji_id", ToJson(JsonInt64{object.profile_background_custom_emoji_id_}));
  if (object.emoji_status_) {
    jo("emoji_status", ToJson(*object.emoji_status_));
  }
  jo("is_contact", JsonBool{object.is_contact_});
  jo("is_mutual_contact", JsonBool{object.is_mutual_contact_});
  jo("is_close_friend", JsonBool{object.is_close_friend_});
  if (object.verification_status_) {
    jo("verification_status", ToJson(*object.verification_status_));
  }
  jo("is_premium", JsonBool{object.is_premium_});
  jo("is_support", JsonBool{object.is_support_});
  if (object.restriction_info_) {
    jo("restriction_info", ToJson(*object.restriction_info_));
  }
  if (object.active_story_state_) {
    jo("active_story_state", ToJson(*object.active_story_state_));
  }
  jo("restricts_new_chats", JsonBool{object.restricts_new_chats_});
  jo("paid_message_star_count", object.paid_message_star_count_);
  jo("have_access", JsonBool{object.have_access_});
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("language_code", object.language_code_);
  jo("added_to_attachment_menu", JsonBool{object.added_to_attachment_menu_});
}

void to_json(JsonValueScope &jv, const td_api::userSupportInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "userSupportInfo");
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
  jo("author", object.author_);
  jo("date", object.date_);
}

void to_json(JsonValueScope &jv, const td_api::videoChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "videoChat");
  jo("group_call_id", object.group_call_id_);
  jo("has_participants", JsonBool{object.has_participants_});
  if (object.default_participant_id_) {
    jo("default_participant_id", ToJson(*object.default_participant_id_));
  }
}

void to_json(JsonValueScope &jv, const td_api::webPageInstantView &object) {
  auto jo = jv.enter_object();
  jo("@type", "webPageInstantView");
  jo("page_blocks", ToJson(object.page_blocks_));
  jo("view_count", object.view_count_);
  jo("version", object.version_);
  jo("is_rtl", JsonBool{object.is_rtl_});
  jo("is_full", JsonBool{object.is_full_});
  if (object.feedback_link_) {
    jo("feedback_link", ToJson(*object.feedback_link_));
  }
}

}  // namespace td_api
}  // namespace td
