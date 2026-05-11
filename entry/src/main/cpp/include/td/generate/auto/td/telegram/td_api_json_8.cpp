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
Result<int32> tl_constructor_from_string(td_api::BotCommandScope *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"botCommandScopeDefault", 795652779},
    {"botCommandScopeAllPrivateChats", -344889543},
    {"botCommandScopeAllGroupChats", -981088162},
    {"botCommandScopeAllChatAdministrators", 1998329169},
    {"botCommandScopeChat", -430234971},
    {"botCommandScopeChatAdministrators", 1119682126},
    {"botCommandScopeChatMember", -211380494}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ChatMemberStatus *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"chatMemberStatusCreator", 877825117},
    {"chatMemberStatusAdministrator", -861316634},
    {"chatMemberStatusMember", -32707562},
    {"chatMemberStatusRestricted", 1661432998},
    {"chatMemberStatusLeft", -5815259},
    {"chatMemberStatusBanned", -1653518666}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::EmojiStatusType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"emojiStatusTypeCustomEmoji", -1666780939},
    {"emojiStatusTypeUpgradedGift", -837921804}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputBackground *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputBackgroundLocal", -1747094364},
    {"inputBackgroundRemote", -274976231},
    {"inputBackgroundPrevious", -351905954}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputMessageContent *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"inputMessageForwarded", -1076506316}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::JsonValue *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"jsonValueNull", -92872499},
    {"jsonValueBoolean", -2142186576},
    {"jsonValueNumber", -1010822033},
    {"jsonValueString", 1597947313},
    {"jsonValueArray", -183913546},
    {"jsonValueObject", 520252026}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::MessageSource *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"messageSourceOther", 901818114}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::PremiumFeature *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"premiumFeatureTextComposition", 210899877}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ReplyMarkup *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"replyMarkupRemoveKeyboard", -691252879},
    {"replyMarkupForceReply", 1101461919},
    {"replyMarkupShowKeyboard", -791495984},
    {"replyMarkupInlineKeyboard", -619317658}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::StoreTransaction *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"storeTransactionAppStore", 1625562441},
    {"storeTransactionGooglePlay", 1094018617}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::TextEntityType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"textEntityTypeDateTime", -1544268588}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Status from_json(td_api::accountTtl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.days_, from.extract_field("days")));
  return Status::OK();
}

Status from_json(td_api::archiveChatListSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.archive_and_mute_new_chats_from_unknown_users_, from.extract_field("archive_and_mute_new_chats_from_unknown_users")));
  TRY_STATUS(from_json(to.keep_unmuted_chats_archived_, from.extract_field("keep_unmuted_chats_archived")));
  TRY_STATUS(from_json(to.keep_chats_from_folders_archived_, from.extract_field("keep_chats_from_folders_archived")));
  return Status::OK();
}

Status from_json(td_api::backgroundTypeWallpaper &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_blurred_, from.extract_field("is_blurred")));
  TRY_STATUS(from_json(to.is_moving_, from.extract_field("is_moving")));
  return Status::OK();
}

Status from_json(td_api::botCommandScopeAllPrivateChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessAwayMessageScheduleCustom &to, JsonObject &from) {
  TRY_STATUS(from_json(to.start_date_, from.extract_field("start_date")));
  TRY_STATUS(from_json(to.end_date_, from.extract_field("end_date")));
  return Status::OK();
}

Status from_json(td_api::businessFeatureAccountLinks &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::businessOpeningHoursInterval &to, JsonObject &from) {
  TRY_STATUS(from_json(to.start_minute_, from.extract_field("start_minute")));
  TRY_STATUS(from_json(to.end_minute_, from.extract_field("end_minute")));
  return Status::OK();
}

Status from_json(td_api::callProblemDistortedSpeech &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::callbackQueryPayloadGame &to, JsonObject &from) {
  TRY_STATUS(from_json(to.game_short_name_, from.extract_field("game_short_name")));
  return Status::OK();
}

Status from_json(td_api::chatActionChoosingLocation &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatAvailableReactionsSome &to, JsonObject &from) {
  TRY_STATUS(from_json(to.reactions_, from.extract_field("reactions")));
  TRY_STATUS(from_json(to.max_reaction_count_, from.extract_field("max_reaction_count")));
  return Status::OK();
}

Status from_json(td_api::chatListFolder &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_id_, from.extract_field("chat_folder_id")));
  return Status::OK();
}

Status from_json(td_api::chatMembersFilterAdministrators &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatPhotoStickerTypeRegularOrMask &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_set_id_, from.extract_field("sticker_set_id")));
  TRY_STATUS(from_json(to.sticker_id_, from.extract_field("sticker_id")));
  return Status::OK();
}

Status from_json(td_api::dateTimePartPrecisionShort &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::deviceTokenSimplePush &to, JsonObject &from) {
  TRY_STATUS(from_json(to.endpoint_, from.extract_field("endpoint")));
  return Status::OK();
}

Status from_json(td_api::emojiCategoryTypeDefault &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeAnimation &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeSecretThumbnail &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeUnknown &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::forumTopicIcon &to, JsonObject &from) {
  TRY_STATUS(from_json(to.color_, from.extract_field("color")));
  TRY_STATUS(from_json(to.custom_emoji_id_, from.extract_field("custom_emoji_id")));
  return Status::OK();
}

Status from_json(td_api::groupCallDataChannelScreenSharing &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::inlineKeyboardButtonTypeWebApp &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::inlineQueryResultsButtonTypeStartBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.parameter_, from.extract_field("parameter")));
  return Status::OK();
}

Status from_json(td_api::inputChatPhotoPrevious &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_photo_id_, from.extract_field("chat_photo_id")));
  return Status::OK();
}

Status from_json(td_api::inputCredentialsNew &to, JsonObject &from) {
  TRY_STATUS(from_json(to.data_, from.extract_field("data")));
  TRY_STATUS(from_json(to.allow_save_, from.extract_field("allow_save")));
  return Status::OK();
}

Status from_json(td_api::inputIdentityDocument &to, JsonObject &from) {
  TRY_STATUS(from_json(to.number_, from.extract_field("number")));
  TRY_STATUS(from_json(to.expiration_date_, from.extract_field("expiration_date")));
  TRY_STATUS(from_json(to.front_side_, from.extract_field("front_side")));
  TRY_STATUS(from_json(to.reverse_side_, from.extract_field("reverse_side")));
  TRY_STATUS(from_json(to.selfie_, from.extract_field("selfie")));
  TRY_STATUS(from_json(to.translation_, from.extract_field("translation")));
  return Status::OK();
}

Status from_json(td_api::inputInlineQueryResultSticker &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.thumbnail_url_, from.extract_field("thumbnail_url")));
  TRY_STATUS(from_json(to.sticker_url_, from.extract_field("sticker_url")));
  TRY_STATUS(from_json(to.sticker_width_, from.extract_field("sticker_width")));
  TRY_STATUS(from_json(to.sticker_height_, from.extract_field("sticker_height")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::inputMessageAudio &to, JsonObject &from) {
  TRY_STATUS(from_json(to.audio_, from.extract_field("audio")));
  TRY_STATUS(from_json(to.album_cover_thumbnail_, from.extract_field("album_cover_thumbnail")));
  TRY_STATUS(from_json(to.duration_, from.extract_field("duration")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.performer_, from.extract_field("performer")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  return Status::OK();
}

Status from_json(td_api::inputMessageVenue &to, JsonObject &from) {
  TRY_STATUS(from_json(to.venue_, from.extract_field("venue")));
  return Status::OK();
}

Status from_json(td_api::inputMessageForwarded &to, JsonObject &from) {
  TRY_STATUS(from_json(to.from_chat_id_, from.extract_field("from_chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.in_game_share_, from.extract_field("in_game_share")));
  TRY_STATUS(from_json(to.replace_video_start_timestamp_, from.extract_field("replace_video_start_timestamp")));
  TRY_STATUS(from_json(to.new_video_start_timestamp_, from.extract_field("new_video_start_timestamp")));
  TRY_STATUS(from_json(to.copy_options_, from.extract_field("copy_options")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementDriverLicense &to, JsonObject &from) {
  TRY_STATUS(from_json(to.driver_license_, from.extract_field("driver_license")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementPhoneNumber &to, JsonObject &from) {
  TRY_STATUS(from_json(to.phone_number_, from.extract_field("phone_number")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementErrorSourceTranslationFiles &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.file_hashes_, from.extract_field("file_hashes")));
  return Status::OK();
}

Status from_json(td_api::inputStoryAreaTypeLocation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  TRY_STATUS(from_json(to.address_, from.extract_field("address")));
  return Status::OK();
}

Status from_json(td_api::inputStoryContentPhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.photo_, from.extract_field("photo")));
  TRY_STATUS(from_json(to.added_sticker_file_ids_, from.extract_field("added_sticker_file_ids")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeBotStart &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_username_, from.extract_field("bot_username")));
  TRY_STATUS(from_json(to.start_parameter_, from.extract_field("start_parameter")));
  TRY_STATUS(from_json(to.autostart_, from.extract_field("autostart")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeContactsPage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.section_, from.extract_field("section")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeLiveStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_username_, from.extract_field("story_poster_username")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeOauth &to, JsonObject &from) {
  TRY_STATUS(from_json(to.url_, from.extract_field("url")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeRequestManagedBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.manager_bot_username_, from.extract_field("manager_bot_username")));
  TRY_STATUS(from_json(to.suggested_bot_username_, from.extract_field("suggested_bot_username")));
  TRY_STATUS(from_json(to.suggested_bot_name_, from.extract_field("suggested_bot_name")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeTheme &to, JsonObject &from) {
  TRY_STATUS(from_json(to.theme_name_, from.extract_field("theme_name")));
  return Status::OK();
}

Status from_json(td_api::jsonValueNull &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::keyboardButtonTypeText &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::languagePackInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.base_language_pack_id_, from.extract_field("base_language_pack_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.native_name_, from.extract_field("native_name")));
  TRY_STATUS(from_json(to.plural_code_, from.extract_field("plural_code")));
  TRY_STATUS(from_json(to.is_official_, from.extract_field("is_official")));
  TRY_STATUS(from_json(to.is_rtl_, from.extract_field("is_rtl")));
  TRY_STATUS(from_json(to.is_beta_, from.extract_field("is_beta")));
  TRY_STATUS(from_json(to.is_installed_, from.extract_field("is_installed")));
  TRY_STATUS(from_json(to.total_string_count_, from.extract_field("total_string_count")));
  TRY_STATUS(from_json(to.translated_string_count_, from.extract_field("translated_string_count")));
  TRY_STATUS(from_json(to.local_string_count_, from.extract_field("local_string_count")));
  TRY_STATUS(from_json(to.translation_url_, from.extract_field("translation_url")));
  return Status::OK();
}

Status from_json(td_api::logStreamFile &to, JsonObject &from) {
  TRY_STATUS(from_json(to.path_, from.extract_field("path")));
  TRY_STATUS(from_json(to.max_file_size_, from.extract_field("max_file_size")));
  TRY_STATUS(from_json(to.redirect_stderr_, from.extract_field("redirect_stderr")));
  return Status::OK();
}

Status from_json(td_api::messageSchedulingStateSendAtDate &to, JsonObject &from) {
  TRY_STATUS(from_json(to.send_date_, from.extract_field("send_date")));
  TRY_STATUS(from_json(to.repeat_period_, from.extract_field("repeat_period")));
  return Status::OK();
}

Status from_json(td_api::messageSourceMessageThreadHistory &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageSourceOther &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::networkTypeMobileRoaming &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::optionValueInteger &to, JsonObject &from) {
  TRY_STATUS(from_json(to.value_, from.extract_field("value")));
  return Status::OK();
}

Status from_json(td_api::passportElementTypeIdentityCard &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::passportElementTypeEmailAddress &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureVoiceRecognition &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureForumTopicIcon &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureLastSeenTimes &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeCreatedPublicChatCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeChatFolderInviteLinkCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumSourceLimitExceeded &to, JsonObject &from) {
  TRY_STATUS(from_json(to.limit_type_, from.extract_field("limit_type")));
  return Status::OK();
}

Status from_json(td_api::premiumStoryFeatureCustomExpirationDuration &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::profileTabMusic &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::reactionNotificationSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.message_reaction_source_, from.extract_field("message_reaction_source")));
  TRY_STATUS(from_json(to.story_reaction_source_, from.extract_field("story_reaction_source")));
  TRY_STATUS(from_json(to.poll_vote_source_, from.extract_field("poll_vote_source")));
  TRY_STATUS(from_json(to.sound_id_, from.extract_field("sound_id")));
  TRY_STATUS(from_json(to.show_preview_, from.extract_field("show_preview")));
  return Status::OK();
}

Status from_json(td_api::replyMarkupForceReply &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_personal_, from.extract_field("is_personal")));
  TRY_STATUS(from_json(to.input_field_placeholder_, from.extract_field("input_field_placeholder")));
  return Status::OK();
}

Status from_json(td_api::reportReasonFake &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesChatTypeFilterGroup &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterVoiceNote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterUnreadPollVote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::settingsSectionEditProfile &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::settingsSectionPremium &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::stickerFormatTgs &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::storePaymentPurposeStarGiveaway &to, JsonObject &from) {
  TRY_STATUS(from_json(to.parameters_, from.extract_field("parameters")));
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  TRY_STATUS(from_json(to.winner_count_, from.extract_field("winner_count")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  return Status::OK();
}

Status from_json(td_api::storyContentTypeUnsupported &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedActionCheckPassword &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedActionSetBirthdate &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::supergroupMembersFilterRecent &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::targetChatChosen &to, JsonObject &from) {
  TRY_STATUS(from_json(to.types_, from.extract_field("types")));
  return Status::OK();
}

Status from_json(td_api::telegramPaymentPurposeJoinChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  return Status::OK();
}

Status from_json(td_api::textEntityTypeEmailAddress &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypePre &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textParseModeMarkdown &to, JsonObject &from) {
  TRY_STATUS(from_json(to.version_, from.extract_field("version")));
  return Status::OK();
}

Status from_json(td_api::topChatCategoryCalls &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingShowProfilePhoto &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingAllowFindingByPhoneNumber &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingRuleAllowChatMembers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_ids_, from.extract_field("chat_ids")));
  return Status::OK();
}

Status from_json(td_api::webAppOpenModeFullSize &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::addChatMember &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.forward_limit_, from.extract_field("forward_limit")));
  return Status::OK();
}

Status from_json(td_api::addLocalMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.sender_id_, from.extract_field("sender_id")));
  TRY_STATUS(from_json(to.reply_to_, from.extract_field("reply_to")));
  TRY_STATUS(from_json(to.disable_notification_, from.extract_field("disable_notification")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::addProfileAudio &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  return Status::OK();
}

Status from_json(td_api::addStickerToSet &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  return Status::OK();
}

Status from_json(td_api::answerWebAppQuery &to, JsonObject &from) {
  TRY_STATUS(from_json(to.web_app_query_id_, from.extract_field("web_app_query_id")));
  TRY_STATUS(from_json(to.result_, from.extract_field("result")));
  return Status::OK();
}

Status from_json(td_api::canBotSendMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  return Status::OK();
}

Status from_json(td_api::cancelRecoveryEmailAddressVerification &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::checkAuthenticationPremiumPurchase &to, JsonObject &from) {
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  return Status::OK();
}

Status from_json(td_api::checkPasswordRecoveryCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.recovery_code_, from.extract_field("recovery_code")));
  return Status::OK();
}

Status from_json(td_api::clearAutosaveSettingsExceptions &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::clickPremiumSubscriptionButton &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::commitPendingPaidMessageReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::createCall &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.protocol_, from.extract_field("protocol")));
  TRY_STATUS(from_json(to.is_video_, from.extract_field("is_video")));
  return Status::OK();
}

Status from_json(td_api::createNewBasicGroupChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_ids_, from.extract_field("user_ids")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.message_auto_delete_time_, from.extract_field("message_auto_delete_time")));
  return Status::OK();
}

Status from_json(td_api::createVideoChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.start_date_, from.extract_field("start_date")));
  TRY_STATUS(from_json(to.is_rtmp_stream_, from.extract_field("is_rtmp_stream")));
  return Status::OK();
}

Status from_json(td_api::deleteBusinessChatLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_, from.extract_field("link")));
  return Status::OK();
}

Status from_json(td_api::deleteChatMessagesByDate &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.min_date_, from.extract_field("min_date")));
  TRY_STATUS(from_json(to.max_date_, from.extract_field("max_date")));
  TRY_STATUS(from_json(to.revoke_, from.extract_field("revoke")));
  return Status::OK();
}

Status from_json(td_api::deleteGiftCollection &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.collection_id_, from.extract_field("collection_id")));
  return Status::OK();
}

Status from_json(td_api::deleteQuickReplyShortcutMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shortcut_id_, from.extract_field("shortcut_id")));
  TRY_STATUS(from_json(to.message_ids_, from.extract_field("message_ids")));
  return Status::OK();
}

Status from_json(td_api::destroy &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::editBotMediaPreview &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  TRY_STATUS(from_json(to.content_, from.extract_field("content")));
  return Status::OK();
}

Status from_json(td_api::editChatFolder &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_id_, from.extract_field("chat_folder_id")));
  TRY_STATUS(from_json(to.folder_, from.extract_field("folder")));
  return Status::OK();
}

Status from_json(td_api::editInlineMessageReplyMarkup &to, JsonObject &from) {
  TRY_STATUS(from_json(to.inline_message_id_, from.extract_field("inline_message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  return Status::OK();
}

Status from_json(td_api::editProxy &to, JsonObject &from) {
  TRY_STATUS(from_json(to.proxy_id_, from.extract_field("proxy_id")));
  TRY_STATUS(from_json(to.proxy_, from.extract_field("proxy")));
  TRY_STATUS(from_json(to.enable_, from.extract_field("enable")));
  return Status::OK();
}

Status from_json(td_api::endGroupCallRecording &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::getAnimatedEmoji &to, JsonObject &from) {
  TRY_STATUS(from_json(to.emoji_, from.extract_field("emoji")));
  return Status::OK();
}

Status from_json(td_api::getAutoDownloadSettingsPresets &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getBotInfoDescription &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  return Status::OK();
}

Status from_json(td_api::getBusinessChatLinkInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_name_, from.extract_field("link_name")));
  return Status::OK();
}

Status from_json(td_api::getChatAdministrators &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getChatBoosts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.only_gift_codes_, from.extract_field("only_gift_codes")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getChatInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  return Status::OK();
}

Status from_json(td_api::getChatMessageCount &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.filter_, from.extract_field("filter")));
  TRY_STATUS(from_json(to.return_local_, from.extract_field("return_local")));
  return Status::OK();
}

Status from_json(td_api::getChatScheduledMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getChatsForChatFolderInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_folder_id_, from.extract_field("chat_folder_id")));
  return Status::OK();
}

Status from_json(td_api::getCountries &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getDeepLinkInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.link_, from.extract_field("link")));
  return Status::OK();
}

Status from_json(td_api::getDirectMessagesChatTopicMessageByDate &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.date_, from.extract_field("date")));
  return Status::OK();
}

Status from_json(td_api::getFile &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  return Status::OK();
}

Status from_json(td_api::getGameHighScores &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::getGrossingWebAppBots &to, JsonObject &from) {
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getInlineQueryResults &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.user_location_, from.extract_field("user_location")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  return Status::OK();
}

Status from_json(td_api::getLanguagePackString &to, JsonObject &from) {
  TRY_STATUS(from_json(to.language_pack_database_path_, from.extract_field("language_pack_database_path")));
  TRY_STATUS(from_json(to.localization_target_, from.extract_field("localization_target")));
  TRY_STATUS(from_json(to.language_pack_id_, from.extract_field("language_pack_id")));
  TRY_STATUS(from_json(to.key_, from.extract_field("key")));
  return Status::OK();
}

Status from_json(td_api::getLogTagVerbosityLevel &to, JsonObject &from) {
  TRY_STATUS(from_json(to.tag_, from.extract_field("tag")));
  return Status::OK();
}

Status from_json(td_api::getMe &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getMessageImportConfirmationText &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getMessageThreadHistory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.from_message_id_, from.extract_field("from_message_id")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getPaidMessageRevenue &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::getPhoneNumberInfoSync &to, JsonObject &from) {
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  TRY_STATUS(from_json(to.phone_number_prefix_, from.extract_field("phone_number_prefix")));
  return Status::OK();
}

Status from_json(td_api::getPremiumState &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getReceivedGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.received_gift_id_, from.extract_field("received_gift_id")));
  return Status::OK();
}

Status from_json(td_api::getRecoveryEmailAddress &to, JsonObject &from) {
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::getSavedOrderInfo &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getStarPaymentOptions &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getStickerSet &to, JsonObject &from) {
  TRY_STATUS(from_json(to.set_id_, from.extract_field("set_id")));
  return Status::OK();
}

Status from_json(td_api::getStoryNotificationSettingsExceptions &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getSupergroupMembers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.filter_, from.extract_field("filter")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getTonRevenueStatistics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.is_dark_, from.extract_field("is_dark")));
  return Status::OK();
}

Status from_json(td_api::getUpgradedGiftWithdrawalUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.received_gift_id_, from.extract_field("received_gift_id")));
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::getUserSupportInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::giftPremiumWithStars &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.star_count_, from.extract_field("star_count")));
  TRY_STATUS(from_json(to.month_count_, from.extract_field("month_count")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::isProfileAudio &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  return Status::OK();
}

Status from_json(td_api::listenToAudio &to, JsonObject &from) {
  TRY_STATUS(from_json(to.audio_file_id_, from.extract_field("audio_file_id")));
  TRY_STATUS(from_json(to.duration_, from.extract_field("duration")));
  return Status::OK();
}

Status from_json(td_api::markChecklistTasksAsDone &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.marked_as_done_task_ids_, from.extract_field("marked_as_done_task_ids")));
  TRY_STATUS(from_json(to.marked_as_not_done_task_ids_, from.extract_field("marked_as_not_done_task_ids")));
  return Status::OK();
}

Status from_json(td_api::optimizeStorage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.size_, from.extract_field("size")));
  TRY_STATUS(from_json(to.ttl_, from.extract_field("ttl")));
  TRY_STATUS(from_json(to.count_, from.extract_field("count")));
  TRY_STATUS(from_json(to.immunity_delay_, from.extract_field("immunity_delay")));
  TRY_STATUS(from_json(to.file_types_, from.extract_field("file_types")));
  TRY_STATUS(from_json(to.chat_ids_, from.extract_field("chat_ids")));
  TRY_STATUS(from_json(to.exclude_chat_ids_, from.extract_field("exclude_chat_ids")));
  TRY_STATUS(from_json(to.return_deleted_file_statistics_, from.extract_field("return_deleted_file_statistics")));
  TRY_STATUS(from_json(to.chat_limit_, from.extract_field("chat_limit")));
  return Status::OK();
}

Status from_json(td_api::processChatHasProtectedContentDisableRequest &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.request_message_id_, from.extract_field("request_message_id")));
  TRY_STATUS(from_json(to.approve_, from.extract_field("approve")));
  return Status::OK();
}

Status from_json(td_api::readAllDirectMessagesChatTopicReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  return Status::OK();
}

Status from_json(td_api::recoverAuthenticationPassword &to, JsonObject &from) {
  TRY_STATUS(from_json(to.recovery_code_, from.extract_field("recovery_code")));
  TRY_STATUS(from_json(to.new_password_, from.extract_field("new_password")));
  TRY_STATUS(from_json(to.new_hint_, from.extract_field("new_hint")));
  return Status::OK();
}

Status from_json(td_api::removeFavoriteSticker &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  return Status::OK();
}

Status from_json(td_api::removePendingLiveStoryReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::removeSearchedForTag &to, JsonObject &from) {
  TRY_STATUS(from_json(to.tag_, from.extract_field("tag")));
  return Status::OK();
}

Status from_json(td_api::reorderGiftCollections &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.collection_ids_, from.extract_field("collection_ids")));
  return Status::OK();
}

Status from_json(td_api::replaceVideoChatRtmpUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::reportSupergroupAntiSpamFalsePositive &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::resendMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_ids_, from.extract_field("message_ids")));
  TRY_STATUS(from_json(to.quote_, from.extract_field("quote")));
  TRY_STATUS(from_json(to.paid_message_star_count_, from.extract_field("paid_message_star_count")));
  return Status::OK();
}

Status from_json(td_api::revokeChatInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  return Status::OK();
}

Status from_json(td_api::searchChatMembers &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  TRY_STATUS(from_json(to.filter_, from.extract_field("filter")));
  return Status::OK();
}

Status from_json(td_api::searchHashtags &to, JsonObject &from) {
  TRY_STATUS(from_json(to.prefix_, from.extract_field("prefix")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchPublicStoriesByTag &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.tag_, from.extract_field("tag")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchStringsByPrefix &to, JsonObject &from) {
  TRY_STATUS(from_json(to.strings_, from.extract_field("strings")));
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  TRY_STATUS(from_json(to.return_none_for_empty_query_, from.extract_field("return_none_for_empty_query")));
  return Status::OK();
}

Status from_json(td_api::sendCallDebugInformation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.call_id_, from.extract_field("call_id")));
  TRY_STATUS(from_json(to.debug_information_, from.extract_field("debug_information")));
  return Status::OK();
}

Status from_json(td_api::sendGroupCallMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.paid_message_star_count_, from.extract_field("paid_message_star_count")));
  return Status::OK();
}

Status from_json(td_api::sendQuickReplyShortcutMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.shortcut_id_, from.extract_field("shortcut_id")));
  TRY_STATUS(from_json(to.sending_id_, from.extract_field("sending_id")));
  return Status::OK();
}

Status from_json(td_api::setArchiveChatListSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.settings_, from.extract_field("settings")));
  return Status::OK();
}

Status from_json(td_api::setBotInfoShortDescription &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  TRY_STATUS(from_json(to.short_description_, from.extract_field("short_description")));
  return Status::OK();
}

Status from_json(td_api::setBusinessAwayMessageSettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.away_message_settings_, from.extract_field("away_message_settings")));
  return Status::OK();
}

Status from_json(td_api::setChatAffiliateProgram &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.parameters_, from.extract_field("parameters")));
  return Status::OK();
}

Status from_json(td_api::setChatLocation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  return Status::OK();
}

Status from_json(td_api::setChatPinnedStories &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.story_ids_, from.extract_field("story_ids")));
  return Status::OK();
}

Status from_json(td_api::setCustomLanguagePackString &to, JsonObject &from) {
  TRY_STATUS(from_json(to.language_pack_id_, from.extract_field("language_pack_id")));
  TRY_STATUS(from_json(to.new_string_, from.extract_field("new_string")));
  return Status::OK();
}

Status from_json(td_api::setFileGenerationProgress &to, JsonObject &from) {
  TRY_STATUS(from_json(to.generation_id_, from.extract_field("generation_id")));
  TRY_STATUS(from_json(to.expected_size_, from.extract_field("expected_size")));
  TRY_STATUS(from_json(to.local_prefix_size_, from.extract_field("local_prefix_size")));
  return Status::OK();
}

Status from_json(td_api::setInactiveSessionTtl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.inactive_session_ttl_days_, from.extract_field("inactive_session_ttl_days")));
  return Status::OK();
}

Status from_json(td_api::setMessageFactCheck &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::setPassportElement &to, JsonObject &from) {
  TRY_STATUS(from_json(to.element_, from.extract_field("element")));
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::setProfileAccentColor &to, JsonObject &from) {
  TRY_STATUS(from_json(to.profile_accent_color_id_, from.extract_field("profile_accent_color_id")));
  TRY_STATUS(from_json(to.profile_background_custom_emoji_id_, from.extract_field("profile_background_custom_emoji_id")));
  return Status::OK();
}

Status from_json(td_api::setStickerEmojis &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  TRY_STATUS(from_json(to.emojis_, from.extract_field("emojis")));
  return Status::OK();
}

Status from_json(td_api::setSupergroupCustomEmojiStickerSet &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.custom_emoji_sticker_set_id_, from.extract_field("custom_emoji_sticker_set_id")));
  return Status::OK();
}

Status from_json(td_api::setUserPersonalProfilePhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.photo_, from.extract_field("photo")));
  return Status::OK();
}

Status from_json(td_api::startGroupCallRecording &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.record_video_, from.extract_field("record_video")));
  TRY_STATUS(from_json(to.use_portrait_orientation_, from.extract_field("use_portrait_orientation")));
  return Status::OK();
}

Status from_json(td_api::synchronizeLanguagePack &to, JsonObject &from) {
  TRY_STATUS(from_json(to.language_pack_id_, from.extract_field("language_pack_id")));
  return Status::OK();
}

Status from_json(td_api::testCallVectorStringObject &to, JsonObject &from) {
  TRY_STATUS(from_json(to.x_, from.extract_field("x")));
  return Status::OK();
}

Status from_json(td_api::toggleBotIsAddedToAttachmentMenu &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.is_added_, from.extract_field("is_added")));
  TRY_STATUS(from_json(to.allow_write_access_, from.extract_field("allow_write_access")));
  return Status::OK();
}

Status from_json(td_api::toggleChatIsTranslatable &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.is_translatable_, from.extract_field("is_translatable")));
  return Status::OK();
}

Status from_json(td_api::toggleGroupCallIsMyVideoEnabled &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.is_my_video_enabled_, from.extract_field("is_my_video_enabled")));
  return Status::OK();
}

Status from_json(td_api::toggleStoryIsPostedToChatPage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  TRY_STATUS(from_json(to.is_posted_to_chat_page_, from.extract_field("is_posted_to_chat_page")));
  return Status::OK();
}

Status from_json(td_api::toggleSupergroupJoinToSendMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.join_to_send_messages_, from.extract_field("join_to_send_messages")));
  return Status::OK();
}

Status from_json(td_api::translateMessageText &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.to_language_code_, from.extract_field("to_language_code")));
  TRY_STATUS(from_json(to.tone_, from.extract_field("tone")));
  return Status::OK();
}

Status from_json(td_api::validateOrderInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.input_invoice_, from.extract_field("input_invoice")));
  TRY_STATUS(from_json(to.order_info_, from.extract_field("order_info")));
  TRY_STATUS(from_json(to.allow_save_, from.extract_field("allow_save")));
  return Status::OK();
}

void to_json(JsonValueScope &jv, const td_api::accountInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "accountInfo");
  jo("registration_month", object.registration_month_);
  jo("registration_year", object.registration_year_);
  jo("phone_number_country_code", object.phone_number_country_code_);
  jo("last_name_change_date", object.last_name_change_date_);
  jo("last_photo_change_date", object.last_photo_change_date_);
}

void to_json(JsonValueScope &jv, const td_api::affiliateInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "affiliateInfo");
  jo("commission_per_mille", object.commission_per_mille_);
  jo("affiliate_chat_id", object.affiliate_chat_id_);
  if (object.star_amount_) {
    jo("star_amount", ToJson(*object.star_amount_));
  }
}

void to_json(JsonValueScope &jv, const td_api::archiveChatListSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "archiveChatListSettings");
  jo("archive_and_mute_new_chats_from_unknown_users", JsonBool{object.archive_and_mute_new_chats_from_unknown_users_});
  jo("keep_unmuted_chats_archived", JsonBool{object.keep_unmuted_chats_archived_});
  jo("keep_chats_from_folders_archived", JsonBool{object.keep_chats_from_folders_archived_});
}

void to_json(JsonValueScope &jv, const td_api::authenticationCodeInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "authenticationCodeInfo");
  jo("phone_number", object.phone_number_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  if (object.next_type_) {
    jo("next_type", ToJson(*object.next_type_));
  }
  jo("timeout", object.timeout_);
}

void to_json(JsonValueScope &jv, const td_api::availableGifts &object) {
  auto jo = jv.enter_object();
  jo("@type", "availableGifts");
  jo("gifts", ToJson(object.gifts_));
}

void to_json(JsonValueScope &jv, const td_api::basicGroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "basicGroup");
  jo("id", object.id_);
  jo("member_count", object.member_count_);
  if (object.status_) {
    jo("status", ToJson(*object.status_));
  }
  jo("is_active", JsonBool{object.is_active_});
  jo("upgraded_to_supergroup_id", object.upgraded_to_supergroup_id_);
}

void to_json(JsonValueScope &jv, const td_api::botMediaPreviews &object) {
  auto jo = jv.enter_object();
  jo("@type", "botMediaPreviews");
  jo("previews", ToJson(object.previews_));
}

void to_json(JsonValueScope &jv, const td_api::businessBotRights &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessBotRights");
  jo("can_reply", JsonBool{object.can_reply_});
  jo("can_read_messages", JsonBool{object.can_read_messages_});
  jo("can_delete_sent_messages", JsonBool{object.can_delete_sent_messages_});
  jo("can_delete_all_messages", JsonBool{object.can_delete_all_messages_});
  jo("can_edit_name", JsonBool{object.can_edit_name_});
  jo("can_edit_bio", JsonBool{object.can_edit_bio_});
  jo("can_edit_profile_photo", JsonBool{object.can_edit_profile_photo_});
  jo("can_edit_username", JsonBool{object.can_edit_username_});
  jo("can_view_gifts_and_stars", JsonBool{object.can_view_gifts_and_stars_});
  jo("can_sell_gifts", JsonBool{object.can_sell_gifts_});
  jo("can_change_gift_settings", JsonBool{object.can_change_gift_settings_});
  jo("can_transfer_and_upgrade_gifts", JsonBool{object.can_transfer_and_upgrade_gifts_});
  jo("can_transfer_stars", JsonBool{object.can_transfer_stars_});
  jo("can_manage_stories", JsonBool{object.can_manage_stories_});
}

void to_json(JsonValueScope &jv, const td_api::businessGreetingMessageSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessGreetingMessageSettings");
  jo("shortcut_id", object.shortcut_id_);
  if (object.recipients_) {
    jo("recipients", ToJson(*object.recipients_));
  }
  jo("inactivity_days", object.inactivity_days_);
}

void to_json(JsonValueScope &jv, const td_api::ButtonStyle &object) {
  td_api::downcast_call(const_cast<td_api::ButtonStyle &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::buttonStyleDefault &object) {
  auto jo = jv.enter_object();
  jo("@type", "buttonStyleDefault");
}

void to_json(JsonValueScope &jv, const td_api::buttonStylePrimary &object) {
  auto jo = jv.enter_object();
  jo("@type", "buttonStylePrimary");
}

void to_json(JsonValueScope &jv, const td_api::buttonStyleDanger &object) {
  auto jo = jv.enter_object();
  jo("@type", "buttonStyleDanger");
}

void to_json(JsonValueScope &jv, const td_api::buttonStyleSuccess &object) {
  auto jo = jv.enter_object();
  jo("@type", "buttonStyleSuccess");
}

void to_json(JsonValueScope &jv, const td_api::CallbackQueryPayload &object) {
  td_api::downcast_call(const_cast<td_api::CallbackQueryPayload &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::callbackQueryPayloadData &object) {
  auto jo = jv.enter_object();
  jo("@type", "callbackQueryPayloadData");
  jo("data", base64_encode(object.data_));
}

void to_json(JsonValueScope &jv, const td_api::callbackQueryPayloadDataWithPassword &object) {
  auto jo = jv.enter_object();
  jo("@type", "callbackQueryPayloadDataWithPassword");
  jo("password", object.password_);
  jo("data", base64_encode(object.data_));
}

void to_json(JsonValueScope &jv, const td_api::callbackQueryPayloadGame &object) {
  auto jo = jv.enter_object();
  jo("@type", "callbackQueryPayloadGame");
  jo("game_short_name", object.game_short_name_);
}

void to_json(JsonValueScope &jv, const td_api::chatAdministrator &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatAdministrator");
  jo("user_id", object.user_id_);
  jo("custom_title", object.custom_title_);
  jo("is_owner", JsonBool{object.is_owner_});
  jo("can_be_edited", JsonBool{object.can_be_edited_});
}

void to_json(JsonValueScope &jv, const td_api::chatBoostLinkInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatBoostLinkInfo");
  jo("is_public", JsonBool{object.is_public_});
  jo("chat_id", object.chat_id_);
}

void to_json(JsonValueScope &jv, const td_api::chatFolderIcon &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatFolderIcon");
  jo("name", object.name_);
}

void to_json(JsonValueScope &jv, const td_api::chatInviteLinkInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatInviteLinkInfo");
  jo("chat_id", object.chat_id_);
  jo("accessible_for", object.accessible_for_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("title", object.title_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("accent_color_id", object.accent_color_id_);
  jo("description", object.description_);
  jo("member_count", object.member_count_);
  jo("member_user_ids", ToJson(object.member_user_ids_));
  if (object.subscription_info_) {
    jo("subscription_info", ToJson(*object.subscription_info_));
  }
  jo("creates_join_request", JsonBool{object.creates_join_request_});
  jo("is_public", JsonBool{object.is_public_});
  if (object.verification_status_) {
    jo("verification_status", ToJson(*object.verification_status_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatLists &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatLists");
  jo("chat_lists", ToJson(object.chat_lists_));
}

void to_json(JsonValueScope &jv, const td_api::chatPhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatPhoto");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("added_date", object.added_date_);
  if (object.minithumbnail_) {
    jo("minithumbnail", ToJson(*object.minithumbnail_));
  }
  jo("sizes", ToJson(object.sizes_));
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
  if (object.small_animation_) {
    jo("small_animation", ToJson(*object.small_animation_));
  }
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::ChatRevenueTransactionType &object) {
  td_api::downcast_call(const_cast<td_api::ChatRevenueTransactionType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatRevenueTransactionTypeUnsupported &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatRevenueTransactionTypeUnsupported");
}

void to_json(JsonValueScope &jv, const td_api::chatRevenueTransactionTypeSponsoredMessageEarnings &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatRevenueTransactionTypeSponsoredMessageEarnings");
  jo("start_date", object.start_date_);
  jo("end_date", object.end_date_);
}

void to_json(JsonValueScope &jv, const td_api::chatRevenueTransactionTypeSuggestedPostEarnings &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatRevenueTransactionTypeSuggestedPostEarnings");
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::chatRevenueTransactionTypeFragmentWithdrawal &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatRevenueTransactionTypeFragmentWithdrawal");
  jo("withdrawal_date", object.withdrawal_date_);
  if (object.state_) {
    jo("state", ToJson(*object.state_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatRevenueTransactionTypeFragmentRefund &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatRevenueTransactionTypeFragmentRefund");
  jo("refund_date", object.refund_date_);
}

void to_json(JsonValueScope &jv, const td_api::ChatTheme &object) {
  td_api::downcast_call(const_cast<td_api::ChatTheme &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatThemeEmoji &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatThemeEmoji");
  jo("name", object.name_);
}

void to_json(JsonValueScope &jv, const td_api::chatThemeGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatThemeGift");
  if (object.gift_theme_) {
    jo("gift_theme", ToJson(*object.gift_theme_));
  }
}

void to_json(JsonValueScope &jv, const td_api::collectibleItemInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "collectibleItemInfo");
  jo("purchase_date", object.purchase_date_);
  jo("currency", object.currency_);
  jo("amount", object.amount_);
  jo("cryptocurrency", object.cryptocurrency_);
  jo("cryptocurrency_amount", ToJson(JsonInt64{object.cryptocurrency_amount_}));
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::countryInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "countryInfo");
  jo("country_code", object.country_code_);
  jo("name", object.name_);
  jo("english_name", object.english_name_);
  jo("is_hidden", JsonBool{object.is_hidden_});
  jo("calling_codes", ToJson(object.calling_codes_));
}

void to_json(JsonValueScope &jv, const td_api::DateTimeFormattingType &object) {
  td_api::downcast_call(const_cast<td_api::DateTimeFormattingType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::dateTimeFormattingTypeRelative &object) {
  auto jo = jv.enter_object();
  jo("@type", "dateTimeFormattingTypeRelative");
}

void to_json(JsonValueScope &jv, const td_api::dateTimeFormattingTypeAbsolute &object) {
  auto jo = jv.enter_object();
  jo("@type", "dateTimeFormattingTypeAbsolute");
  if (object.time_precision_) {
    jo("time_precision", ToJson(*object.time_precision_));
  }
  if (object.date_precision_) {
    jo("date_precision", ToJson(*object.date_precision_));
  }
  jo("show_day_of_week", JsonBool{object.show_day_of_week_});
}

void to_json(JsonValueScope &jv, const td_api::document &object) {
  auto jo = jv.enter_object();
  jo("@type", "document");
  jo("file_name", object.file_name_);
  jo("mime_type", object.mime_type_);
  if (object.minithumbnail_) {
    jo("minithumbnail", ToJson(*object.minithumbnail_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  if (object.document_) {
    jo("document", ToJson(*object.document_));
  }
}

void to_json(JsonValueScope &jv, const td_api::emojiKeyword &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiKeyword");
  jo("emoji", object.emoji_);
  jo("keyword", object.keyword_);
}

void to_json(JsonValueScope &jv, const td_api::encryptedPassportElement &object) {
  auto jo = jv.enter_object();
  jo("@type", "encryptedPassportElement");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("data", base64_encode(object.data_));
  if (object.front_side_) {
    jo("front_side", ToJson(*object.front_side_));
  }
  if (object.reverse_side_) {
    jo("reverse_side", ToJson(*object.reverse_side_));
  }
  if (object.selfie_) {
    jo("selfie", ToJson(*object.selfie_));
  }
  jo("translation", ToJson(object.translation_));
  jo("files", ToJson(object.files_));
  jo("value", object.value_);
  jo("hash", object.hash_);
}

void to_json(JsonValueScope &jv, const td_api::FirebaseDeviceVerificationParameters &object) {
  td_api::downcast_call(const_cast<td_api::FirebaseDeviceVerificationParameters &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::firebaseDeviceVerificationParametersSafetyNet &object) {
  auto jo = jv.enter_object();
  jo("@type", "firebaseDeviceVerificationParametersSafetyNet");
  jo("nonce", base64_encode(object.nonce_));
}

void to_json(JsonValueScope &jv, const td_api::firebaseDeviceVerificationParametersPlayIntegrity &object) {
  auto jo = jv.enter_object();
  jo("@type", "firebaseDeviceVerificationParametersPlayIntegrity");
  jo("nonce", object.nonce_);
  jo("cloud_project_number", ToJson(JsonInt64{object.cloud_project_number_}));
}

void to_json(JsonValueScope &jv, const td_api::foundAffiliatePrograms &object) {
  auto jo = jv.enter_object();
  jo("@type", "foundAffiliatePrograms");
  jo("total_count", object.total_count_);
  jo("programs", ToJson(object.programs_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::foundUsers &object) {
  auto jo = jv.enter_object();
  jo("@type", "foundUsers");
  jo("user_ids", ToJson(object.user_ids_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::giftAuctionState &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftAuctionState");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  if (object.state_) {
    jo("state", ToJson(*object.state_));
  }
}

void to_json(JsonValueScope &jv, const td_api::giftResaleParameters &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftResaleParameters");
  jo("star_count", object.star_count_);
  jo("toncoin_cent_count", object.toncoin_cent_count_);
  jo("toncoin_only", JsonBool{object.toncoin_only_});
}

void to_json(JsonValueScope &jv, const td_api::GiveawayInfo &object) {
  td_api::downcast_call(const_cast<td_api::GiveawayInfo &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::giveawayInfoOngoing &object) {
  auto jo = jv.enter_object();
  jo("@type", "giveawayInfoOngoing");
  jo("creation_date", object.creation_date_);
  if (object.status_) {
    jo("status", ToJson(*object.status_));
  }
  jo("is_ended", JsonBool{object.is_ended_});
}

void to_json(JsonValueScope &jv, const td_api::giveawayInfoCompleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "giveawayInfoCompleted");
  jo("creation_date", object.creation_date_);
  jo("actual_winners_selection_date", object.actual_winners_selection_date_);
  jo("was_refunded", JsonBool{object.was_refunded_});
  jo("is_winner", JsonBool{object.is_winner_});
  jo("winner_count", object.winner_count_);
  jo("activation_count", object.activation_count_);
  jo("gift_code", object.gift_code_);
  jo("won_star_count", object.won_star_count_);
}

void to_json(JsonValueScope &jv, const td_api::groupCallParticipant &object) {
  auto jo = jv.enter_object();
  jo("@type", "groupCallParticipant");
  if (object.participant_id_) {
    jo("participant_id", ToJson(*object.participant_id_));
  }
  jo("audio_source_id", object.audio_source_id_);
  jo("screen_sharing_audio_source_id", object.screen_sharing_audio_source_id_);
  if (object.video_info_) {
    jo("video_info", ToJson(*object.video_info_));
  }
  if (object.screen_sharing_video_info_) {
    jo("screen_sharing_video_info", ToJson(*object.screen_sharing_video_info_));
  }
  jo("bio", object.bio_);
  jo("is_current_user", JsonBool{object.is_current_user_});
  jo("is_speaking", JsonBool{object.is_speaking_});
  jo("is_hand_raised", JsonBool{object.is_hand_raised_});
  jo("can_be_muted_for_all_users", JsonBool{object.can_be_muted_for_all_users_});
  jo("can_be_unmuted_for_all_users", JsonBool{object.can_be_unmuted_for_all_users_});
  jo("can_be_muted_for_current_user", JsonBool{object.can_be_muted_for_current_user_});
  jo("can_be_unmuted_for_current_user", JsonBool{object.can_be_unmuted_for_current_user_});
  jo("is_muted_for_all_users", JsonBool{object.is_muted_for_all_users_});
  jo("is_muted_for_current_user", JsonBool{object.is_muted_for_current_user_});
  jo("can_unmute_self", JsonBool{object.can_unmute_self_});
  jo("volume_level", object.volume_level_);
  jo("order", object.order_);
}

void to_json(JsonValueScope &jv, const td_api::identityDocument &object) {
  auto jo = jv.enter_object();
  jo("@type", "identityDocument");
  jo("number", object.number_);
  if (object.expiration_date_) {
    jo("expiration_date", ToJson(*object.expiration_date_));
  }
  if (object.front_side_) {
    jo("front_side", ToJson(*object.front_side_));
  }
  if (object.reverse_side_) {
    jo("reverse_side", ToJson(*object.reverse_side_));
  }
  if (object.selfie_) {
    jo("selfie", ToJson(*object.selfie_));
  }
  jo("translation", ToJson(object.translation_));
}

void to_json(JsonValueScope &jv, const td_api::inputChecklistTask &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputChecklistTask");
  jo("id", object.id_);
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inputTextQuote &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputTextQuote");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("position", object.position_);
}

void to_json(JsonValueScope &jv, const td_api::KeyboardButtonType &object) {
  td_api::downcast_call(const_cast<td_api::KeyboardButtonType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::keyboardButtonTypeText &object) {
  auto jo = jv.enter_object();
  jo("@type", "keyboardButtonTypeText");
}

void to_json(JsonValueScope &jv, const td_api::keyboardButtonTypeRequestPhoneNumber &object) {
  auto jo = jv.enter_object();
  jo("@type", "keyboardButtonTypeRequestPhoneNumber");
}

void to_json(JsonValueScope &jv, const td_api::keyboardButtonTypeRequestLocation &object) {
  auto jo = jv.enter_object();
  jo("@type", "keyboardButtonTypeRequestLocation");
}

void to_json(JsonValueScope &jv, const td_api::keyboardButtonTypeRequestPoll &object) {
  auto jo = jv.enter_object();
  jo("@type", "keyboardButtonTypeRequestPoll");
  jo("force_regular", JsonBool{object.force_regular_});
  jo("force_quiz", JsonBool{object.force_quiz_});
}

void to_json(JsonValueScope &jv, const td_api::keyboardButtonTypeRequestUsers &object) {
  auto jo = jv.enter_object();
  jo("@type", "keyboardButtonTypeRequestUsers");
  jo("id", object.id_);
  jo("restrict_user_is_bot", JsonBool{object.restrict_user_is_bot_});
  jo("user_is_bot", JsonBool{object.user_is_bot_});
  jo("restrict_user_is_premium", JsonBool{object.restrict_user_is_premium_});
  jo("user_is_premium", JsonBool{object.user_is_premium_});
  jo("max_quantity", object.max_quantity_);
  jo("request_name", JsonBool{object.request_name_});
  jo("request_username", JsonBool{object.request_username_});
  jo("request_photo", JsonBool{object.request_photo_});
}

void to_json(JsonValueScope &jv, const td_api::keyboardButtonTypeRequestChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "keyboardButtonTypeRequestChat");
  jo("id", object.id_);
  jo("chat_is_channel", JsonBool{object.chat_is_channel_});
  jo("restrict_chat_is_forum", JsonBool{object.restrict_chat_is_forum_});
  jo("chat_is_forum", JsonBool{object.chat_is_forum_});
  jo("restrict_chat_has_username", JsonBool{object.restrict_chat_has_username_});
  jo("chat_has_username", JsonBool{object.chat_has_username_});
  jo("chat_is_created", JsonBool{object.chat_is_created_});
  if (object.user_administrator_rights_) {
    jo("user_administrator_rights", ToJson(*object.user_administrator_rights_));
  }
  if (object.bot_administrator_rights_) {
    jo("bot_administrator_rights", ToJson(*object.bot_administrator_rights_));
  }
  jo("bot_is_member", JsonBool{object.bot_is_member_});
  jo("request_title", JsonBool{object.request_title_});
  jo("request_username", JsonBool{object.request_username_});
  jo("request_photo", JsonBool{object.request_photo_});
}

void to_json(JsonValueScope &jv, const td_api::keyboardButtonTypeRequestManagedBot &object) {
  auto jo = jv.enter_object();
  jo("@type", "keyboardButtonTypeRequestManagedBot");
  jo("id", object.id_);
  jo("suggested_name", object.suggested_name_);
  jo("suggested_username", object.suggested_username_);
}

void to_json(JsonValueScope &jv, const td_api::keyboardButtonTypeWebApp &object) {
  auto jo = jv.enter_object();
  jo("@type", "keyboardButtonTypeWebApp");
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::LinkPreviewType &object) {
  td_api::downcast_call(const_cast<td_api::LinkPreviewType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeAlbum &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeAlbum");
  jo("media", ToJson(object.media_));
  jo("caption", object.caption_);
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeAnimation &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeAnimation");
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeApp &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeApp");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeArticle &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeArticle");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeAudio &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeAudio");
  if (object.audio_) {
    jo("audio", ToJson(*object.audio_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeBackground &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeBackground");
  if (object.document_) {
    jo("document", ToJson(*object.document_));
  }
  if (object.background_type_) {
    jo("background_type", ToJson(*object.background_type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeChannelBoost &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeChannelBoost");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeChat");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("creates_join_request", JsonBool{object.creates_join_request_});
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeDirectMessagesChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeDirectMessagesChat");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeDocument &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeDocument");
  if (object.document_) {
    jo("document", ToJson(*object.document_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeEmbeddedAnimationPlayer &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeEmbeddedAnimationPlayer");
  jo("url", object.url_);
  if (object.animation_) {
    jo("animation", ToJson(*object.animation_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  jo("duration", object.duration_);
  jo("width", object.width_);
  jo("height", object.height_);
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeEmbeddedAudioPlayer &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeEmbeddedAudioPlayer");
  jo("url", object.url_);
  if (object.audio_) {
    jo("audio", ToJson(*object.audio_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  jo("duration", object.duration_);
  jo("width", object.width_);
  jo("height", object.height_);
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeEmbeddedVideoPlayer &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeEmbeddedVideoPlayer");
  jo("url", object.url_);
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  jo("duration", object.duration_);
  jo("width", object.width_);
  jo("height", object.height_);
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeExternalAudio &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeExternalAudio");
  jo("url", object.url_);
  jo("mime_type", object.mime_type_);
  jo("duration", object.duration_);
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeExternalVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeExternalVideo");
  jo("url", object.url_);
  jo("mime_type", object.mime_type_);
  jo("width", object.width_);
  jo("height", object.height_);
  jo("duration", object.duration_);
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeGiftAuction &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeGiftAuction");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
  jo("auction_end_date", object.auction_end_date_);
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeGiftCollection &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeGiftCollection");
  jo("icons", ToJson(object.icons_));
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeGroupCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeGroupCall");
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeInvoice &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeInvoice");
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeLiveStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeLiveStory");
  jo("story_poster_chat_id", object.story_poster_chat_id_);
  jo("story_id", object.story_id_);
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeMessage");
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypePhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypePhoto");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypePremiumGiftCode &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypePremiumGiftCode");
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeRequestManagedBot &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeRequestManagedBot");
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeShareableChatFolder &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeShareableChatFolder");
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeSticker &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeSticker");
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeStickerSet &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeStickerSet");
  jo("stickers", ToJson(object.stickers_));
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeStory");
  jo("story_poster_chat_id", object.story_poster_chat_id_);
  jo("story_id", object.story_id_);
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeStoryAlbum &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeStoryAlbum");
  if (object.photo_icon_) {
    jo("photo_icon", ToJson(*object.photo_icon_));
  }
  if (object.video_icon_) {
    jo("video_icon", ToJson(*object.video_icon_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeSupergroupBoost &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeSupergroupBoost");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeTheme &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeTheme");
  jo("documents", ToJson(object.documents_));
  if (object.settings_) {
    jo("settings", ToJson(*object.settings_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeUnsupported &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeUnsupported");
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeUpgradedGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeUpgradedGift");
  if (object.gift_) {
    jo("gift", ToJson(*object.gift_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeUser &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeUser");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("is_bot", JsonBool{object.is_bot_});
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeVideo &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeVideo");
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
  if (object.cover_) {
    jo("cover", ToJson(*object.cover_));
  }
  jo("start_timestamp", object.start_timestamp_);
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeVideoChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeVideoChat");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  jo("is_live_stream", JsonBool{object.is_live_stream_});
  jo("joins_as_speaker", JsonBool{object.joins_as_speaker_});
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeVideoNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeVideoNote");
  if (object.video_note_) {
    jo("video_note", ToJson(*object.video_note_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeVoiceNote &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeVoiceNote");
  if (object.voice_note_) {
    jo("voice_note", ToJson(*object.voice_note_));
  }
}

void to_json(JsonValueScope &jv, const td_api::linkPreviewTypeWebApp &object) {
  auto jo = jv.enter_object();
  jo("@type", "linkPreviewTypeWebApp");
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::LoginUrlInfo &object) {
  td_api::downcast_call(const_cast<td_api::LoginUrlInfo &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::loginUrlInfoOpen &object) {
  auto jo = jv.enter_object();
  jo("@type", "loginUrlInfoOpen");
  jo("url", object.url_);
  jo("skip_confirmation", JsonBool{object.skip_confirmation_});
}

void to_json(JsonValueScope &jv, const td_api::loginUrlInfoRequestConfirmation &object) {
  auto jo = jv.enter_object();
  jo("@type", "loginUrlInfoRequestConfirmation");
  jo("url", object.url_);
  jo("domain", object.domain_);
  jo("bot_user_id", object.bot_user_id_);
  jo("request_write_access", JsonBool{object.request_write_access_});
}

void to_json(JsonValueScope &jv, const td_api::messageCopyOptions &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageCopyOptions");
  jo("send_copy", JsonBool{object.send_copy_});
  jo("replace_caption", JsonBool{object.replace_caption_});
  if (object.new_caption_) {
    jo("new_caption", ToJson(*object.new_caption_));
  }
  jo("new_show_caption_above_media", JsonBool{object.new_show_caption_above_media_});
}

void to_json(JsonValueScope &jv, const td_api::MessageOrigin &object) {
  td_api::downcast_call(const_cast<td_api::MessageOrigin &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::messageOriginUser &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageOriginUser");
  jo("sender_user_id", object.sender_user_id_);
}

void to_json(JsonValueScope &jv, const td_api::messageOriginHiddenUser &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageOriginHiddenUser");
  jo("sender_name", object.sender_name_);
}

void to_json(JsonValueScope &jv, const td_api::messageOriginChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageOriginChat");
  jo("sender_chat_id", object.sender_chat_id_);
  jo("author_signature", object.author_signature_);
}

void to_json(JsonValueScope &jv, const td_api::messageOriginChannel &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageOriginChannel");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  jo("author_signature", object.author_signature_);
}

void to_json(JsonValueScope &jv, const td_api::MessageSchedulingState &object) {
  td_api::downcast_call(const_cast<td_api::MessageSchedulingState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::messageSchedulingStateSendAtDate &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSchedulingStateSendAtDate");
  jo("send_date", object.send_date_);
  jo("repeat_period", object.repeat_period_);
}

void to_json(JsonValueScope &jv, const td_api::messageSchedulingStateSendWhenOnline &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSchedulingStateSendWhenOnline");
}

void to_json(JsonValueScope &jv, const td_api::messageSchedulingStateSendWhenVideoProcessed &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSchedulingStateSendWhenVideoProcessed");
  jo("send_date", object.send_date_);
}

void to_json(JsonValueScope &jv, const td_api::messageViewers &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageViewers");
  jo("viewers", ToJson(object.viewers_));
}

void to_json(JsonValueScope &jv, const td_api::NotificationGroupType &object) {
  td_api::downcast_call(const_cast<td_api::NotificationGroupType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::notificationGroupTypeMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationGroupTypeMessages");
}

void to_json(JsonValueScope &jv, const td_api::notificationGroupTypeMentions &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationGroupTypeMentions");
}

void to_json(JsonValueScope &jv, const td_api::notificationGroupTypeSecretChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationGroupTypeSecretChat");
}

void to_json(JsonValueScope &jv, const td_api::notificationGroupTypeCalls &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationGroupTypeCalls");
}

void to_json(JsonValueScope &jv, const td_api::outline &object) {
  auto jo = jv.enter_object();
  jo("@type", "outline");
  jo("paths", ToJson(object.paths_));
}

void to_json(JsonValueScope &jv, const td_api::PaidReactionType &object) {
  td_api::downcast_call(const_cast<td_api::PaidReactionType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::paidReactionTypeRegular &object) {
  auto jo = jv.enter_object();
  jo("@type", "paidReactionTypeRegular");
}

void to_json(JsonValueScope &jv, const td_api::paidReactionTypeAnonymous &object) {
  auto jo = jv.enter_object();
  jo("@type", "paidReactionTypeAnonymous");
}

void to_json(JsonValueScope &jv, const td_api::paidReactionTypeChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "paidReactionTypeChat");
  jo("chat_id", object.chat_id_);
}

void to_json(JsonValueScope &jv, const td_api::passportElements &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportElements");
  jo("elements", ToJson(object.elements_));
}

void to_json(JsonValueScope &jv, const td_api::paymentReceipt &object) {
  auto jo = jv.enter_object();
  jo("@type", "paymentReceipt");
  if (object.product_info_) {
    jo("product_info", ToJson(*object.product_info_));
  }
  jo("date", object.date_);
  jo("seller_bot_user_id", object.seller_bot_user_id_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::poll &object) {
  auto jo = jv.enter_object();
  jo("@type", "poll");
  jo("id", ToJson(JsonInt64{object.id_}));
  if (object.question_) {
    jo("question", ToJson(*object.question_));
  }
  jo("options", ToJson(object.options_));
  jo("total_voter_count", object.total_voter_count_);
  jo("recent_voter_ids", ToJson(object.recent_voter_ids_));
  jo("can_get_voters", JsonBool{object.can_get_voters_});
  jo("is_anonymous", JsonBool{object.is_anonymous_});
  jo("allows_multiple_answers", JsonBool{object.allows_multiple_answers_});
  jo("allows_revoting", JsonBool{object.allows_revoting_});
  jo("option_order", ToJson(object.option_order_));
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("open_period", object.open_period_);
  jo("close_date", object.close_date_);
  jo("is_closed", JsonBool{object.is_closed_});
}

void to_json(JsonValueScope &jv, const td_api::premiumGiftCodeInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumGiftCodeInfo");
  if (object.creator_id_) {
    jo("creator_id", ToJson(*object.creator_id_));
  }
  jo("creation_date", object.creation_date_);
  jo("is_from_giveaway", JsonBool{object.is_from_giveaway_});
  jo("giveaway_message_id", object.giveaway_message_id_);
  jo("month_count", object.month_count_);
  jo("day_count", object.day_count_);
  jo("user_id", object.user_id_);
  jo("use_date", object.use_date_);
}

void to_json(JsonValueScope &jv, const td_api::premiumStatePaymentOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumStatePaymentOption");
  if (object.payment_option_) {
    jo("payment_option", ToJson(*object.payment_option_));
  }
  jo("is_current", JsonBool{object.is_current_});
  jo("is_upgrade", JsonBool{object.is_upgrade_});
  jo("last_transaction_id", object.last_transaction_id_);
}

void to_json(JsonValueScope &jv, const td_api::proxy &object) {
  auto jo = jv.enter_object();
  jo("@type", "proxy");
  jo("server", object.server_);
  jo("port", object.port_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::quickReplyShortcut &object) {
  auto jo = jv.enter_object();
  jo("@type", "quickReplyShortcut");
  jo("id", object.id_);
  jo("name", object.name_);
  if (object.first_message_) {
    jo("first_message", ToJson(*object.first_message_));
  }
  jo("message_count", object.message_count_);
}

void to_json(JsonValueScope &jv, const td_api::recommendedChatFolders &object) {
  auto jo = jv.enter_object();
  jo("@type", "recommendedChatFolders");
  jo("chat_folders", ToJson(object.chat_folders_));
}

void to_json(JsonValueScope &jv, const td_api::restrictionInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "restrictionInfo");
  jo("restriction_reason", object.restriction_reason_);
  jo("has_sensitive_content", JsonBool{object.has_sensitive_content_});
}

void to_json(JsonValueScope &jv, const td_api::scopeAutosaveSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "scopeAutosaveSettings");
  jo("autosave_photos", JsonBool{object.autosave_photos_});
  jo("autosave_videos", JsonBool{object.autosave_videos_});
  jo("max_video_file_size", object.max_video_file_size_);
}

void to_json(JsonValueScope &jv, const td_api::sessions &object) {
  auto jo = jv.enter_object();
  jo("@type", "sessions");
  jo("sessions", ToJson(object.sessions_));
  jo("inactive_session_ttl_days", object.inactive_session_ttl_days_);
}

void to_json(JsonValueScope &jv, const td_api::sponsoredMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "sponsoredMessages");
  jo("messages", ToJson(object.messages_));
  jo("messages_between", object.messages_between_);
}

void to_json(JsonValueScope &jv, const td_api::starRevenueStatistics &object) {
  auto jo = jv.enter_object();
  jo("@type", "starRevenueStatistics");
  if (object.revenue_by_day_graph_) {
    jo("revenue_by_day_graph", ToJson(*object.revenue_by_day_graph_));
  }
  if (object.status_) {
    jo("status", ToJson(*object.status_));
  }
  jo("usd_rate", object.usd_rate_);
}

void to_json(JsonValueScope &jv, const td_api::StartLiveStoryResult &object) {
  td_api::downcast_call(const_cast<td_api::StartLiveStoryResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::startLiveStoryResultOk &object) {
  auto jo = jv.enter_object();
  jo("@type", "startLiveStoryResultOk");
  if (object.story_) {
    jo("story", ToJson(*object.story_));
  }
}

void to_json(JsonValueScope &jv, const td_api::startLiveStoryResultFail &object) {
  auto jo = jv.enter_object();
  jo("@type", "startLiveStoryResultFail");
  if (object.error_type_) {
    jo("error_type", ToJson(*object.error_type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::StickerType &object) {
  td_api::downcast_call(const_cast<td_api::StickerType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::stickerTypeRegular &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickerTypeRegular");
}

void to_json(JsonValueScope &jv, const td_api::stickerTypeMask &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickerTypeMask");
}

void to_json(JsonValueScope &jv, const td_api::stickerTypeCustomEmoji &object) {
  auto jo = jv.enter_object();
  jo("@type", "stickerTypeCustomEmoji");
}

void to_json(JsonValueScope &jv, const td_api::storyAlbums &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyAlbums");
  jo("albums", ToJson(object.albums_));
}

void to_json(JsonValueScope &jv, const td_api::StoryInteractionType &object) {
  td_api::downcast_call(const_cast<td_api::StoryInteractionType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::storyInteractionTypeView &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyInteractionTypeView");
  if (object.chosen_reaction_type_) {
    jo("chosen_reaction_type", ToJson(*object.chosen_reaction_type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::storyInteractionTypeForward &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyInteractionTypeForward");
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::storyInteractionTypeRepost &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyInteractionTypeRepost");
  if (object.story_) {
    jo("story", ToJson(*object.story_));
  }
}

void to_json(JsonValueScope &jv, const td_api::suggestedPostInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedPostInfo");
  if (object.price_) {
    jo("price", ToJson(*object.price_));
  }
  jo("send_date", object.send_date_);
  if (object.state_) {
    jo("state", ToJson(*object.state_));
  }
  jo("can_be_approved", JsonBool{object.can_be_approved_});
  jo("can_be_declined", JsonBool{object.can_be_declined_});
}

void to_json(JsonValueScope &jv, const td_api::TargetChat &object) {
  td_api::downcast_call(const_cast<td_api::TargetChat &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::targetChatCurrent &object) {
  auto jo = jv.enter_object();
  jo("@type", "targetChatCurrent");
}

void to_json(JsonValueScope &jv, const td_api::targetChatChosen &object) {
  auto jo = jv.enter_object();
  jo("@type", "targetChatChosen");
  if (object.types_) {
    jo("types", ToJson(*object.types_));
  }
}

void to_json(JsonValueScope &jv, const td_api::targetChatInternalLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "targetChatInternalLink");
  if (object.link_) {
    jo("link", ToJson(*object.link_));
  }
}

void to_json(JsonValueScope &jv, const td_api::testVectorString &object) {
  auto jo = jv.enter_object();
  jo("@type", "testVectorString");
  jo("value", ToJson(object.value_));
}

void to_json(JsonValueScope &jv, const td_api::thumbnail &object) {
  auto jo = jv.enter_object();
  jo("@type", "thumbnail");
  if (object.format_) {
    jo("format", ToJson(*object.format_));
  }
  jo("width", object.width_);
  jo("height", object.height_);
  if (object.file_) {
    jo("file", ToJson(*object.file_));
  }
}

void to_json(JsonValueScope &jv, const td_api::trendingStickerSets &object) {
  auto jo = jv.enter_object();
  jo("@type", "trendingStickerSets");
  jo("total_count", object.total_count_);
  jo("sets", ToJson(object.sets_));
  jo("is_premium", JsonBool{object.is_premium_});
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftBackdropColors &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftBackdropColors");
  jo("center_color", object.center_color_);
  jo("edge_color", object.edge_color_);
  jo("symbol_color", object.symbol_color_);
  jo("text_color", object.text_color_);
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftValueInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftValueInfo");
  jo("currency", object.currency_);
  jo("value", object.value_);
  jo("is_value_average", JsonBool{object.is_value_average_});
  jo("initial_sale_date", object.initial_sale_date_);
  jo("initial_sale_star_count", object.initial_sale_star_count_);
  jo("initial_sale_price", object.initial_sale_price_);
  jo("last_sale_date", object.last_sale_date_);
  jo("last_sale_price", object.last_sale_price_);
  jo("is_last_sale_on_fragment", JsonBool{object.is_last_sale_on_fragment_});
  jo("minimum_price", object.minimum_price_);
  jo("average_sale_price", object.average_sale_price_);
  jo("telegram_listed_gift_count", object.telegram_listed_gift_count_);
  jo("fragment_listed_gift_count", object.fragment_listed_gift_count_);
  jo("fragment_url", object.fragment_url_);
}

void to_json(JsonValueScope &jv, const td_api::UserStatus &object) {
  td_api::downcast_call(const_cast<td_api::UserStatus &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::userStatusEmpty &object) {
  auto jo = jv.enter_object();
  jo("@type", "userStatusEmpty");
}

void to_json(JsonValueScope &jv, const td_api::userStatusOnline &object) {
  auto jo = jv.enter_object();
  jo("@type", "userStatusOnline");
  jo("expires", object.expires_);
}

void to_json(JsonValueScope &jv, const td_api::userStatusOffline &object) {
  auto jo = jv.enter_object();
  jo("@type", "userStatusOffline");
  jo("was_online", object.was_online_);
}

void to_json(JsonValueScope &jv, const td_api::userStatusRecently &object) {
  auto jo = jv.enter_object();
  jo("@type", "userStatusRecently");
  jo("by_my_privacy_settings", JsonBool{object.by_my_privacy_settings_});
}

void to_json(JsonValueScope &jv, const td_api::userStatusLastWeek &object) {
  auto jo = jv.enter_object();
  jo("@type", "userStatusLastWeek");
  jo("by_my_privacy_settings", JsonBool{object.by_my_privacy_settings_});
}

void to_json(JsonValueScope &jv, const td_api::userStatusLastMonth &object) {
  auto jo = jv.enter_object();
  jo("@type", "userStatusLastMonth");
  jo("by_my_privacy_settings", JsonBool{object.by_my_privacy_settings_});
}

void to_json(JsonValueScope &jv, const td_api::video &object) {
  auto jo = jv.enter_object();
  jo("@type", "video");
  jo("duration", object.duration_);
  jo("width", object.width_);
  jo("height", object.height_);
  jo("file_name", object.file_name_);
  jo("mime_type", object.mime_type_);
  jo("has_stickers", JsonBool{object.has_stickers_});
  jo("supports_streaming", JsonBool{object.supports_streaming_});
  if (object.minithumbnail_) {
    jo("minithumbnail", ToJson(*object.minithumbnail_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  if (object.video_) {
    jo("video", ToJson(*object.video_));
  }
}

void to_json(JsonValueScope &jv, const td_api::WebAppOpenMode &object) {
  td_api::downcast_call(const_cast<td_api::WebAppOpenMode &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::webAppOpenModeCompact &object) {
  auto jo = jv.enter_object();
  jo("@type", "webAppOpenModeCompact");
}

void to_json(JsonValueScope &jv, const td_api::webAppOpenModeFullSize &object) {
  auto jo = jv.enter_object();
  jo("@type", "webAppOpenModeFullSize");
}

void to_json(JsonValueScope &jv, const td_api::webAppOpenModeFullScreen &object) {
  auto jo = jv.enter_object();
  jo("@type", "webAppOpenModeFullScreen");
}

}  // namespace td_api
}  // namespace td
