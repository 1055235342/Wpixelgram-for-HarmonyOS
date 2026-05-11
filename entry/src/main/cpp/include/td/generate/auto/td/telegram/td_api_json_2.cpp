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
Result<int32> tl_constructor_from_string(td_api::AffiliateProgramSortOrder *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"affiliateProgramSortOrderProfitability", -1963282585},
    {"affiliateProgramSortOrderCreationDate", -1558628083},
    {"affiliateProgramSortOrderRevenue", 1923269304}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::ButtonStyle *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"buttonStyleDefault", 588834315},
    {"buttonStylePrimary", 2048071333},
    {"buttonStyleDanger", -1637377793},
    {"buttonStyleSuccess", 1042215008}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::CollectibleItemType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"collectibleItemTypeUsername", 458680273},
    {"collectibleItemTypePhoneNumber", 1256251714}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::GiftForResaleOrder *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"giftForResaleOrderPrice", 1371740258},
    {"giftForResaleOrderPriceChangeDate", -1694144054},
    {"giftForResaleOrderNumber", -1301157632}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputChatTheme *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"inputChatThemeEmoji", -1461787199},
    {"inputChatThemeGift", 2026976301}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::InputPassportElement *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
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
    {"inputPassportElementEmailAddress", -248605659}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::LanguagePackStringValue *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"languagePackStringValueOrdinary", -249256352},
    {"languagePackStringValuePluralized", 1906840261},
    {"languagePackStringValueDeleted", 1834792698}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::NetworkType *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"networkTypeNone", -1971691759},
    {"networkTypeMobile", 819228239},
    {"networkTypeMobileRoaming", -1435199760},
    {"networkTypeWiFi", -633872070},
    {"networkTypeOther", 1942128539}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::PremiumStoryFeature *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"premiumStoryFeaturePriorityOrder", -1880001849},
    {"premiumStoryFeatureStealthMode", 1194605988},
    {"premiumStoryFeaturePermanentViewsHistory", -1029683296},
    {"premiumStoryFeatureCustomExpirationDuration", -593229162},
    {"premiumStoryFeatureSaveStories", -1501286467},
    {"premiumStoryFeatureLinksAndFormatting", -622623753},
    {"premiumStoryFeatureVideoQuality", -1162887511}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::SearchMessagesChatTypeFilter *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"searchMessagesChatTypeFilterPrivate", 1169248975},
    {"searchMessagesChatTypeFilterGroup", -2059426022},
    {"searchMessagesChatTypeFilterChannel", -773540139}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::StoryPrivacySettings *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"storyPrivacySettingsEveryone", 890847843},
    {"storyPrivacySettingsContacts", 50285309},
    {"storyPrivacySettingsCloseFriends", 2097122144},
    {"storyPrivacySettingsSelectedUsers", -1885772602}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Result<int32> tl_constructor_from_string(td_api::TransactionDirection *object, const std::string &str) {
  static const FlatHashMap<Slice, int32, SliceHash> m = {
    {"transactionDirectionIncoming", -271074103},
    {"transactionDirectionOutgoing", 1638241254}
  };
  auto it = m.find(str);
  if (it == m.end()) {
    return Status::Error(PSLICE() << "Unknown class \"" << str << "\"");
  }
  return it->second;
}

Status from_json(td_api::affiliateProgramSortOrderProfitability &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::autosaveSettingsScopeGroupChats &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::backgroundTypeChatTheme &to, JsonObject &from) {
  TRY_STATUS(from_json(to.theme_name_, from.extract_field("theme_name")));
  return Status::OK();
}

Status from_json(td_api::botCommandScopeChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::businessConnectedBot &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.recipients_, from.extract_field("recipients")));
  TRY_STATUS(from_json(to.rights_, from.extract_field("rights")));
  return Status::OK();
}

Status from_json(td_api::businessFeatureEmojiStatus &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::buttonStylePrimary &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::callProblemDropped &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatActionUploadingVideo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.progress_, from.extract_field("progress")));
  return Status::OK();
}

Status from_json(td_api::chatActionRecordingVideoNote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::chatFolderIcon &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::chatMemberStatusAdministrator &to, JsonObject &from) {
  TRY_STATUS(from_json(to.can_be_edited_, from.extract_field("can_be_edited")));
  TRY_STATUS(from_json(to.rights_, from.extract_field("rights")));
  return Status::OK();
}

Status from_json(td_api::chatMembersFilterRestricted &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::collectibleItemTypePhoneNumber &to, JsonObject &from) {
  TRY_STATUS(from_json(to.phone_number_, from.extract_field("phone_number")));
  return Status::OK();
}

Status from_json(td_api::deviceTokenApplePush &to, JsonObject &from) {
  TRY_STATUS(from_json(to.device_token_, from.extract_field("device_token")));
  TRY_STATUS(from_json(to.is_app_sandbox_, from.extract_field("is_app_sandbox")));
  return Status::OK();
}

Status from_json(td_api::deviceTokenTizenPush &to, JsonObject &from) {
  TRY_STATUS(from_json(to.reg_id_, from.extract_field("reg_id")));
  return Status::OK();
}

Status from_json(td_api::emojiCategoryTypeChatPhoto &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeLivePhotoVideo &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeSelfDestructingPhoto &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::fileTypeVideoStory &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::giftForResaleOrderNumber &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::groupCallVideoQualityMedium &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::inlineKeyboardButtonTypeCallbackGame &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::inputBackgroundRemote &to, JsonObject &from) {
  TRY_STATUS(from_json(to.background_id_, from.extract_field("background_id")));
  return Status::OK();
}

Status from_json(td_api::inputChatPhotoSticker &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  return Status::OK();
}

Status from_json(td_api::inputFileId &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  return Status::OK();
}

Status from_json(td_api::inputInlineQueryResultAudio &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.performer_, from.extract_field("performer")));
  TRY_STATUS(from_json(to.audio_url_, from.extract_field("audio_url")));
  TRY_STATUS(from_json(to.audio_duration_, from.extract_field("audio_duration")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::inputInlineQueryResultVoiceNote &to, JsonObject &from) {
  TRY_STATUS(from_json(to.id_, from.extract_field("id")));
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.voice_note_url_, from.extract_field("voice_note_url")));
  TRY_STATUS(from_json(to.voice_note_duration_, from.extract_field("voice_note_duration")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::inputMessagePhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.photo_, from.extract_field("photo")));
  TRY_STATUS(from_json(to.thumbnail_, from.extract_field("thumbnail")));
  TRY_STATUS(from_json(to.video_, from.extract_field("video")));
  TRY_STATUS(from_json(to.added_sticker_file_ids_, from.extract_field("added_sticker_file_ids")));
  TRY_STATUS(from_json(to.width_, from.extract_field("width")));
  TRY_STATUS(from_json(to.height_, from.extract_field("height")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  TRY_STATUS(from_json(to.show_caption_above_media_, from.extract_field("show_caption_above_media")));
  TRY_STATUS(from_json(to.self_destruct_type_, from.extract_field("self_destruct_type")));
  TRY_STATUS(from_json(to.has_spoiler_, from.extract_field("has_spoiler")));
  return Status::OK();
}

Status from_json(td_api::inputMessageGame &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.game_short_name_, from.extract_field("game_short_name")));
  return Status::OK();
}

Status from_json(td_api::inputMessageReplyToStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementAddress &to, JsonObject &from) {
  TRY_STATUS(from_json(to.address_, from.extract_field("address")));
  return Status::OK();
}

Status from_json(td_api::inputPassportElementErrorSourceUnspecified &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.element_hash_, from.extract_field("element_hash")));
  return Status::OK();
}

Status from_json(td_api::inputPersonalDocument &to, JsonObject &from) {
  TRY_STATUS(from_json(to.files_, from.extract_field("files")));
  TRY_STATUS(from_json(to.translation_, from.extract_field("translation")));
  return Status::OK();
}

Status from_json(td_api::inputStoryAreaTypeSuggestedReaction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.reaction_type_, from.extract_field("reaction_type")));
  TRY_STATUS(from_json(to.is_dark_, from.extract_field("is_dark")));
  TRY_STATUS(from_json(to.is_flipped_, from.extract_field("is_flipped")));
  return Status::OK();
}

Status from_json(td_api::inputTextQuote &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.position_, from.extract_field("position")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeCallsPage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.section_, from.extract_field("section")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeGiftAuction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.auction_id_, from.extract_field("auction_id")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeMessageDraft &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  TRY_STATUS(from_json(to.contains_link_, from.extract_field("contains_link")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypePremiumFeaturesPage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.referrer_, from.extract_field("referrer")));
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeSearch &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::internalLinkTypeUserPhoneNumber &to, JsonObject &from) {
  TRY_STATUS(from_json(to.phone_number_, from.extract_field("phone_number")));
  TRY_STATUS(from_json(to.draft_text_, from.extract_field("draft_text")));
  TRY_STATUS(from_json(to.open_profile_, from.extract_field("open_profile")));
  return Status::OK();
}

Status from_json(td_api::jsonValueString &to, JsonObject &from) {
  TRY_STATUS(from_json(to.value_, from.extract_field("value")));
  return Status::OK();
}

Status from_json(td_api::keyboardButtonTypeRequestPoll &to, JsonObject &from) {
  TRY_STATUS(from_json(to.force_regular_, from.extract_field("force_regular")));
  TRY_STATUS(from_json(to.force_quiz_, from.extract_field("force_quiz")));
  return Status::OK();
}

Status from_json(td_api::languagePackStringValuePluralized &to, JsonObject &from) {
  TRY_STATUS(from_json(to.zero_value_, from.extract_field("zero_value")));
  TRY_STATUS(from_json(to.one_value_, from.extract_field("one_value")));
  TRY_STATUS(from_json(to.two_value_, from.extract_field("two_value")));
  TRY_STATUS(from_json(to.few_value_, from.extract_field("few_value")));
  TRY_STATUS(from_json(to.many_value_, from.extract_field("many_value")));
  TRY_STATUS(from_json(to.other_value_, from.extract_field("other_value")));
  return Status::OK();
}

Status from_json(td_api::maskPointEyes &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageSelfDestructTypeTimer &to, JsonObject &from) {
  TRY_STATUS(from_json(to.self_destruct_time_, from.extract_field("self_destruct_time")));
  return Status::OK();
}

Status from_json(td_api::messageSourceHistoryPreview &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::messageTopicDirectMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.direct_messages_chat_topic_id_, from.extract_field("direct_messages_chat_topic_id")));
  return Status::OK();
}

Status from_json(td_api::newChatPrivacySettings &to, JsonObject &from) {
  TRY_STATUS(from_json(to.allow_new_chats_from_unknown_users_, from.extract_field("allow_new_chats_from_unknown_users")));
  TRY_STATUS(from_json(to.incoming_paid_message_star_count_, from.extract_field("incoming_paid_message_star_count")));
  return Status::OK();
}

Status from_json(td_api::paidReactionTypeRegular &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::passportElementTypeUtilityBill &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::phoneNumberCodeTypeChange &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureUniqueStickers &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureUpgradedStories &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumFeatureChecklists &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeChatFolderCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumLimitTypeWeeklyPostedStoryCount &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::premiumSourceStoryFeature &to, JsonObject &from) {
  TRY_STATUS(from_json(to.feature_, from.extract_field("feature")));
  return Status::OK();
}

Status from_json(td_api::premiumStoryFeatureVideoQuality &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::proxy &to, JsonObject &from) {
  TRY_STATUS(from_json(to.server_, from.extract_field("server")));
  TRY_STATUS(from_json(to.port_, from.extract_field("port")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::reactionNotificationSourceAll &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::reportReasonSpam &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::reportReasonCustom &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterAnimation &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::searchMessagesFilterChatPhoto &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::settingsSectionAppearance &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::settingsSectionInAppBrowser &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::settingsSectionQrCode &to, JsonObject &from) {
  TRY_STATUS(from_json(to.subsection_, from.extract_field("subsection")));
  return Status::OK();
}

Status from_json(td_api::stickerTypeMask &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::storeTransactionAppStore &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.receipt_, from.extract_field("receipt")));
  return Status::OK();
}

Status from_json(td_api::storyListArchive &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::suggestedActionConvertToBroadcastGroup &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  return Status::OK();
}

Status from_json(td_api::suggestedActionExtendStarSubscriptions &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::supergroupMembersFilterSearch &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  return Status::OK();
}

Status from_json(td_api::telegramPaymentPurposePremiumGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.month_count_, from.extract_field("month_count")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::textEntity &to, JsonObject &from) {
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.length_, from.extract_field("length")));
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::textEntityTypeBold &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::textEntityTypeExpandableBlockQuote &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::topChatCategoryUsers &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::transactionDirectionOutgoing &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingShowBio &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingAllowUnpaidMessages &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::userPrivacySettingRuleRestrictBots &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::acceptCall &to, JsonObject &from) {
  TRY_STATUS(from_json(to.call_id_, from.extract_field("call_id")));
  TRY_STATUS(from_json(to.protocol_, from.extract_field("protocol")));
  return Status::OK();
}

Status from_json(td_api::addChecklistTasks &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.tasks_, from.extract_field("tasks")));
  return Status::OK();
}

Status from_json(td_api::addMessageReaction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reaction_type_, from.extract_field("reaction_type")));
  TRY_STATUS(from_json(to.is_big_, from.extract_field("is_big")));
  TRY_STATUS(from_json(to.update_recent_reactions_, from.extract_field("update_recent_reactions")));
  return Status::OK();
}

Status from_json(td_api::addQuickReplyShortcutMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shortcut_name_, from.extract_field("shortcut_name")));
  TRY_STATUS(from_json(to.reply_to_message_id_, from.extract_field("reply_to_message_id")));
  TRY_STATUS(from_json(to.input_message_content_, from.extract_field("input_message_content")));
  return Status::OK();
}

Status from_json(td_api::allowUnpaidMessagesFromUser &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.refund_payments_, from.extract_field("refund_payments")));
  return Status::OK();
}

Status from_json(td_api::assignStoreTransaction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.transaction_, from.extract_field("transaction")));
  TRY_STATUS(from_json(to.purpose_, from.extract_field("purpose")));
  return Status::OK();
}

Status from_json(td_api::canSendGift &to, JsonObject &from) {
  TRY_STATUS(from_json(to.gift_id_, from.extract_field("gift_id")));
  return Status::OK();
}

Status from_json(td_api::checkAuthenticationBotToken &to, JsonObject &from) {
  TRY_STATUS(from_json(to.token_, from.extract_field("token")));
  return Status::OK();
}

Status from_json(td_api::checkChatInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  return Status::OK();
}

Status from_json(td_api::checkQuickReplyShortcutName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::clearRecentReactions &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::closeChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::confirmSession &to, JsonObject &from) {
  TRY_STATUS(from_json(to.session_id_, from.extract_field("session_id")));
  return Status::OK();
}

Status from_json(td_api::createChatInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  TRY_STATUS(from_json(to.expiration_date_, from.extract_field("expiration_date")));
  TRY_STATUS(from_json(to.member_limit_, from.extract_field("member_limit")));
  TRY_STATUS(from_json(to.creates_join_request_, from.extract_field("creates_join_request")));
  return Status::OK();
}

Status from_json(td_api::createNewSupergroupChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.title_, from.extract_field("title")));
  TRY_STATUS(from_json(to.is_forum_, from.extract_field("is_forum")));
  TRY_STATUS(from_json(to.is_channel_, from.extract_field("is_channel")));
  TRY_STATUS(from_json(to.description_, from.extract_field("description")));
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  TRY_STATUS(from_json(to.message_auto_delete_time_, from.extract_field("message_auto_delete_time")));
  TRY_STATUS(from_json(to.for_import_, from.extract_field("for_import")));
  return Status::OK();
}

Status from_json(td_api::declineSuggestedPost &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.comment_, from.extract_field("comment")));
  return Status::OK();
}

Status from_json(td_api::deleteBusinessStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  return Status::OK();
}

Status from_json(td_api::deleteCommands &to, JsonObject &from) {
  TRY_STATUS(from_json(to.scope_, from.extract_field("scope")));
  TRY_STATUS(from_json(to.language_code_, from.extract_field("language_code")));
  return Status::OK();
}

Status from_json(td_api::deleteLanguagePack &to, JsonObject &from) {
  TRY_STATUS(from_json(to.language_pack_id_, from.extract_field("language_pack_id")));
  return Status::OK();
}

Status from_json(td_api::deleteSavedMessagesTopicHistory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.saved_messages_topic_id_, from.extract_field("saved_messages_topic_id")));
  return Status::OK();
}

Status from_json(td_api::discardCall &to, JsonObject &from) {
  TRY_STATUS(from_json(to.call_id_, from.extract_field("call_id")));
  TRY_STATUS(from_json(to.is_disconnected_, from.extract_field("is_disconnected")));
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  TRY_STATUS(from_json(to.duration_, from.extract_field("duration")));
  TRY_STATUS(from_json(to.is_video_, from.extract_field("is_video")));
  TRY_STATUS(from_json(to.connection_id_, from.extract_field("connection_id")));
  return Status::OK();
}

Status from_json(td_api::editBusinessMessageChecklist &to, JsonObject &from) {
  TRY_STATUS(from_json(to.business_connection_id_, from.extract_field("business_connection_id")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.checklist_, from.extract_field("checklist")));
  return Status::OK();
}

Status from_json(td_api::editChatSubscriptionInviteLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.invite_link_, from.extract_field("invite_link")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::editMessageChecklist &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reply_markup_, from.extract_field("reply_markup")));
  TRY_STATUS(from_json(to.checklist_, from.extract_field("checklist")));
  return Status::OK();
}

Status from_json(td_api::editStory &to, JsonObject &from) {
  TRY_STATUS(from_json(to.story_poster_chat_id_, from.extract_field("story_poster_chat_id")));
  TRY_STATUS(from_json(to.story_id_, from.extract_field("story_id")));
  TRY_STATUS(from_json(to.content_, from.extract_field("content")));
  TRY_STATUS(from_json(to.areas_, from.extract_field("areas")));
  TRY_STATUS(from_json(to.caption_, from.extract_field("caption")));
  return Status::OK();
}

Status from_json(td_api::fixTextWithAi &to, JsonObject &from) {
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::getArchiveChatListSettings &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getAvailableGifts &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getBotMediaPreviews &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  return Status::OK();
}

Status from_json(td_api::getBusinessConnection &to, JsonObject &from) {
  TRY_STATUS(from_json(to.connection_id_, from.extract_field("connection_id")));
  return Status::OK();
}

Status from_json(td_api::getChatAvailablePaidMessageReactionSenders &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getChatFolderChatCount &to, JsonObject &from) {
  TRY_STATUS(from_json(to.folder_, from.extract_field("folder")));
  return Status::OK();
}

Status from_json(td_api::getChatInviteLinks &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.creator_user_id_, from.extract_field("creator_user_id")));
  TRY_STATUS(from_json(to.is_revoked_, from.extract_field("is_revoked")));
  TRY_STATUS(from_json(to.offset_date_, from.extract_field("offset_date")));
  TRY_STATUS(from_json(to.offset_invite_link_, from.extract_field("offset_invite_link")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getChatOwnerAfterLeaving &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::getChatSparseMessagePositions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.filter_, from.extract_field("filter")));
  TRY_STATUS(from_json(to.from_message_id_, from.extract_field("from_message_id")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  TRY_STATUS(from_json(to.saved_messages_topic_id_, from.extract_field("saved_messages_topic_id")));
  return Status::OK();
}

Status from_json(td_api::getCollectibleItemInfo &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::getCreatedPublicChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::getDefaultChatPhotoCustomEmojiStickers &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getEmojiCategories &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  return Status::OK();
}

Status from_json(td_api::getFileMimeType &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_name_, from.extract_field("file_name")));
  return Status::OK();
}

Status from_json(td_api::getGiftChatThemes &to, JsonObject &from) {
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getGroupCallStreamSegment &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.time_offset_, from.extract_field("time_offset")));
  TRY_STATUS(from_json(to.scale_, from.extract_field("scale")));
  TRY_STATUS(from_json(to.channel_id_, from.extract_field("channel_id")));
  TRY_STATUS(from_json(to.video_quality_, from.extract_field("video_quality")));
  return Status::OK();
}

Status from_json(td_api::getInternalLink &to, JsonObject &from) {
  TRY_STATUS(from_json(to.type_, from.extract_field("type")));
  TRY_STATUS(from_json(to.is_http_, from.extract_field("is_http")));
  return Status::OK();
}

Status from_json(td_api::getLiveStoryAvailableMessageSenders &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::getLoginPasskeys &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getMessageAddedReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.reaction_type_, from.extract_field("reaction_type")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getMessageLocally &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  return Status::OK();
}

Status from_json(td_api::getNetworkStatistics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.only_current_, from.extract_field("only_current")));
  return Status::OK();
}

Status from_json(td_api::getPassportAuthorizationFormAvailableElements &to, JsonObject &from) {
  TRY_STATUS(from_json(to.authorization_form_id_, from.extract_field("authorization_form_id")));
  TRY_STATUS(from_json(to.password_, from.extract_field("password")));
  return Status::OK();
}

Status from_json(td_api::getPreferredCountryLanguage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.country_code_, from.extract_field("country_code")));
  return Status::OK();
}

Status from_json(td_api::getPreparedInlineMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.prepared_message_id_, from.extract_field("prepared_message_id")));
  return Status::OK();
}

Status from_json(td_api::getRecentInlineBots &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getSavedAnimations &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getSearchedForTags &to, JsonObject &from) {
  TRY_STATUS(from_json(to.tag_prefix_, from.extract_field("tag_prefix")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getStarTransactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.subscription_id_, from.extract_field("subscription_id")));
  TRY_STATUS(from_json(to.direction_, from.extract_field("direction")));
  TRY_STATUS(from_json(to.offset_, from.extract_field("offset")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getStorageStatistics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_limit_, from.extract_field("chat_limit")));
  return Status::OK();
}

Status from_json(td_api::getSuggestedFileName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  TRY_STATUS(from_json(to.directory_, from.extract_field("directory")));
  return Status::OK();
}

Status from_json(td_api::getTemporaryPasswordState &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::getTopChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.category_, from.extract_field("category")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::getUserChatBoosts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  return Status::OK();
}

Status from_json(td_api::getVideoChatRtmpUrl &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::importContacts &to, JsonObject &from) {
  TRY_STATUS(from_json(to.contacts_, from.extract_field("contacts")));
  return Status::OK();
}

Status from_json(td_api::joinGroupCall &to, JsonObject &from) {
  TRY_STATUS(from_json(to.input_group_call_, from.extract_field("input_group_call")));
  TRY_STATUS(from_json(to.join_parameters_, from.extract_field("join_parameters")));
  return Status::OK();
}

Status from_json(td_api::loadDirectMessagesChatTopics &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::openChatSimilarChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.opened_chat_id_, from.extract_field("opened_chat_id")));
  return Status::OK();
}

Status from_json(td_api::pinChatMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.disable_notification_, from.extract_field("disable_notification")));
  TRY_STATUS(from_json(to.only_for_self_, from.extract_field("only_for_self")));
  return Status::OK();
}

Status from_json(td_api::processGiftPurchaseOffer &to, JsonObject &from) {
  TRY_STATUS(from_json(to.message_id_, from.extract_field("message_id")));
  TRY_STATUS(from_json(to.accept_, from.extract_field("accept")));
  return Status::OK();
}

Status from_json(td_api::readAllForumTopicReactions &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.forum_topic_id_, from.extract_field("forum_topic_id")));
  return Status::OK();
}

Status from_json(td_api::registerDevice &to, JsonObject &from) {
  TRY_STATUS(from_json(to.device_token_, from.extract_field("device_token")));
  TRY_STATUS(from_json(to.other_user_ids_, from.extract_field("other_user_ids")));
  return Status::OK();
}

Status from_json(td_api::removeInstalledBackground &to, JsonObject &from) {
  TRY_STATUS(from_json(to.background_id_, from.extract_field("background_id")));
  return Status::OK();
}

Status from_json(td_api::removeProxy &to, JsonObject &from) {
  TRY_STATUS(from_json(to.proxy_id_, from.extract_field("proxy_id")));
  return Status::OK();
}

Status from_json(td_api::removeTopChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.category_, from.extract_field("category")));
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::reorderStoryAlbumStories &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.story_album_id_, from.extract_field("story_album_id")));
  TRY_STATUS(from_json(to.story_ids_, from.extract_field("story_ids")));
  return Status::OK();
}

Status from_json(td_api::reportChatPhoto &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  TRY_STATUS(from_json(to.reason_, from.extract_field("reason")));
  TRY_STATUS(from_json(to.text_, from.extract_field("text")));
  return Status::OK();
}

Status from_json(td_api::requestAuthenticationPasswordRecovery &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::resetAllNotificationSettings &to, JsonObject &from) {
  return Status::OK();
}

Status from_json(td_api::savePreparedInlineMessage &to, JsonObject &from) {
  TRY_STATUS(from_json(to.user_id_, from.extract_field("user_id")));
  TRY_STATUS(from_json(to.result_, from.extract_field("result")));
  TRY_STATUS(from_json(to.chat_types_, from.extract_field("chat_types")));
  return Status::OK();
}

Status from_json(td_api::searchChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchOutgoingDocumentMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchRecentlyFoundChats &to, JsonObject &from) {
  TRY_STATUS(from_json(to.query_, from.extract_field("query")));
  TRY_STATUS(from_json(to.limit_, from.extract_field("limit")));
  return Status::OK();
}

Status from_json(td_api::searchWebApp &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.web_app_short_name_, from.extract_field("web_app_short_name")));
  return Status::OK();
}

Status from_json(td_api::sendCallSignalingData &to, JsonObject &from) {
  TRY_STATUS(from_json(to.call_id_, from.extract_field("call_id")));
  TRY_STATUS(from_json_bytes(to.data_, from.extract_field("data")));
  return Status::OK();
}

Status from_json(td_api::sendMessageAlbum &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  TRY_STATUS(from_json(to.reply_to_, from.extract_field("reply_to")));
  TRY_STATUS(from_json(to.options_, from.extract_field("options")));
  TRY_STATUS(from_json(to.input_message_contents_, from.extract_field("input_message_contents")));
  return Status::OK();
}

Status from_json(td_api::sendWebAppCustomRequest &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.method_, from.extract_field("method")));
  TRY_STATUS(from_json(to.parameters_, from.extract_field("parameters")));
  return Status::OK();
}

Status from_json(td_api::setAuthenticationPremiumPurchaseTransaction &to, JsonObject &from) {
  TRY_STATUS(from_json(to.transaction_, from.extract_field("transaction")));
  TRY_STATUS(from_json(to.is_restore_, from.extract_field("is_restore")));
  TRY_STATUS(from_json(to.currency_, from.extract_field("currency")));
  TRY_STATUS(from_json(to.amount_, from.extract_field("amount")));
  return Status::OK();
}

Status from_json(td_api::setBotUpdatesStatus &to, JsonObject &from) {
  TRY_STATUS(from_json(to.pending_update_count_, from.extract_field("pending_update_count")));
  TRY_STATUS(from_json(to.error_message_, from.extract_field("error_message")));
  return Status::OK();
}

Status from_json(td_api::setBusinessLocation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.location_, from.extract_field("location")));
  return Status::OK();
}

Status from_json(td_api::setChatClientData &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.client_data_, from.extract_field("client_data")));
  return Status::OK();
}

Status from_json(td_api::setChatMessageAutoDeleteTime &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.message_auto_delete_time_, from.extract_field("message_auto_delete_time")));
  return Status::OK();
}

Status from_json(td_api::setChatTheme &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.theme_, from.extract_field("theme")));
  return Status::OK();
}

Status from_json(td_api::setDefaultChannelAdministratorRights &to, JsonObject &from) {
  TRY_STATUS(from_json(to.default_channel_administrator_rights_, from.extract_field("default_channel_administrator_rights")));
  return Status::OK();
}

Status from_json(td_api::setGiftCollectionName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.owner_id_, from.extract_field("owner_id")));
  TRY_STATUS(from_json(to.collection_id_, from.extract_field("collection_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::setLogStream &to, JsonObject &from) {
  TRY_STATUS(from_json(to.log_stream_, from.extract_field("log_stream")));
  return Status::OK();
}

Status from_json(td_api::setMessageSenderBotVerification &to, JsonObject &from) {
  TRY_STATUS(from_json(to.bot_user_id_, from.extract_field("bot_user_id")));
  TRY_STATUS(from_json(to.verified_id_, from.extract_field("verified_id")));
  TRY_STATUS(from_json(to.custom_description_, from.extract_field("custom_description")));
  return Status::OK();
}

Status from_json(td_api::setPersonalChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  return Status::OK();
}

Status from_json(td_api::setQuickReplyShortcutName &to, JsonObject &from) {
  TRY_STATUS(from_json(to.shortcut_id_, from.extract_field("shortcut_id")));
  TRY_STATUS(from_json(to.name_, from.extract_field("name")));
  return Status::OK();
}

Status from_json(td_api::setStickerPositionInSet &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sticker_, from.extract_field("sticker")));
  TRY_STATUS(from_json(to.position_, from.extract_field("position")));
  return Status::OK();
}

Status from_json(td_api::setSupergroupUnrestrictBoostCount &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.unrestrict_boost_count_, from.extract_field("unrestrict_boost_count")));
  return Status::OK();
}

Status from_json(td_api::setUsername &to, JsonObject &from) {
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  return Status::OK();
}

Status from_json(td_api::startScheduledVideoChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  return Status::OK();
}

Status from_json(td_api::testCallBytes &to, JsonObject &from) {
  TRY_STATUS(from_json_bytes(to.x_, from.extract_field("x")));
  return Status::OK();
}

Status from_json(td_api::testProxy &to, JsonObject &from) {
  TRY_STATUS(from_json(to.proxy_, from.extract_field("proxy")));
  TRY_STATUS(from_json(to.dc_id_, from.extract_field("dc_id")));
  TRY_STATUS(from_json(to.timeout_, from.extract_field("timeout")));
  return Status::OK();
}

Status from_json(td_api::toggleChatDefaultDisableNotification &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.default_disable_notification_, from.extract_field("default_disable_notification")));
  return Status::OK();
}

Status from_json(td_api::toggleDownloadIsPaused &to, JsonObject &from) {
  TRY_STATUS(from_json(to.file_id_, from.extract_field("file_id")));
  TRY_STATUS(from_json(to.is_paused_, from.extract_field("is_paused")));
  return Status::OK();
}

Status from_json(td_api::toggleGroupCallParticipantIsMuted &to, JsonObject &from) {
  TRY_STATUS(from_json(to.group_call_id_, from.extract_field("group_call_id")));
  TRY_STATUS(from_json(to.participant_id_, from.extract_field("participant_id")));
  TRY_STATUS(from_json(to.is_muted_, from.extract_field("is_muted")));
  return Status::OK();
}

Status from_json(td_api::toggleSupergroupHasAutomaticTranslation &to, JsonObject &from) {
  TRY_STATUS(from_json(to.supergroup_id_, from.extract_field("supergroup_id")));
  TRY_STATUS(from_json(to.has_automatic_translation_, from.extract_field("has_automatic_translation")));
  return Status::OK();
}

Status from_json(td_api::toggleUsernameIsActive &to, JsonObject &from) {
  TRY_STATUS(from_json(to.username_, from.extract_field("username")));
  TRY_STATUS(from_json(to.is_active_, from.extract_field("is_active")));
  return Status::OK();
}

Status from_json(td_api::unpinAllDirectMessagesChatTopicMessages &to, JsonObject &from) {
  TRY_STATUS(from_json(to.chat_id_, from.extract_field("chat_id")));
  TRY_STATUS(from_json(to.topic_id_, from.extract_field("topic_id")));
  return Status::OK();
}

Status from_json(td_api::viewSponsoredChat &to, JsonObject &from) {
  TRY_STATUS(from_json(to.sponsored_chat_unique_id_, from.extract_field("sponsored_chat_unique_id")));
  return Status::OK();
}

void to_json(JsonValueScope &jv, const td_api::addedProxies &object) {
  auto jo = jv.enter_object();
  jo("@type", "addedProxies");
  jo("proxies", ToJson(object.proxies_));
}

void to_json(JsonValueScope &jv, const td_api::ageVerificationParameters &object) {
  auto jo = jv.enter_object();
  jo("@type", "ageVerificationParameters");
  jo("min_age", object.min_age_);
  jo("verification_bot_username", object.verification_bot_username_);
  jo("country", object.country_);
}

void to_json(JsonValueScope &jv, const td_api::attributeCraftPersistenceProbability &object) {
  auto jo = jv.enter_object();
  jo("@type", "attributeCraftPersistenceProbability");
  jo("persistence_chance_per_mille", ToJson(object.persistence_chance_per_mille_));
}

void to_json(JsonValueScope &jv, const td_api::autoDownloadSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "autoDownloadSettings");
  jo("is_auto_download_enabled", JsonBool{object.is_auto_download_enabled_});
  jo("max_photo_file_size", object.max_photo_file_size_);
  jo("max_video_file_size", object.max_video_file_size_);
  jo("max_other_file_size", object.max_other_file_size_);
  jo("video_upload_bitrate", object.video_upload_bitrate_);
  jo("preload_large_videos", JsonBool{object.preload_large_videos_});
  jo("preload_next_audio", JsonBool{object.preload_next_audio_});
  jo("preload_stories", JsonBool{object.preload_stories_});
  jo("use_less_data_for_calls", JsonBool{object.use_less_data_for_calls_});
}

void to_json(JsonValueScope &jv, const td_api::background &object) {
  auto jo = jv.enter_object();
  jo("@type", "background");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("is_default", JsonBool{object.is_default_});
  jo("is_dark", JsonBool{object.is_dark_});
  jo("name", object.name_);
  if (object.document_) {
    jo("document", ToJson(*object.document_));
  }
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::BlockList &object) {
  td_api::downcast_call(const_cast<td_api::BlockList &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::blockListMain &object) {
  auto jo = jv.enter_object();
  jo("@type", "blockListMain");
}

void to_json(JsonValueScope &jv, const td_api::blockListStories &object) {
  auto jo = jv.enter_object();
  jo("@type", "blockListStories");
}

void to_json(JsonValueScope &jv, const td_api::botVerificationParameters &object) {
  auto jo = jv.enter_object();
  jo("@type", "botVerificationParameters");
  jo("icon_custom_emoji_id", ToJson(JsonInt64{object.icon_custom_emoji_id_}));
  jo("organization_name", object.organization_name_);
  if (object.default_custom_description_) {
    jo("default_custom_description", ToJson(*object.default_custom_description_));
  }
  jo("can_set_custom_description", JsonBool{object.can_set_custom_description_});
}

void to_json(JsonValueScope &jv, const td_api::businessChatLinks &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessChatLinks");
  jo("links", ToJson(object.links_));
}

void to_json(JsonValueScope &jv, const td_api::businessMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "businessMessage");
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
  if (object.reply_to_message_) {
    jo("reply_to_message", ToJson(*object.reply_to_message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::callId &object) {
  auto jo = jv.enter_object();
  jo("@type", "callId");
  jo("id", object.id_);
}

void to_json(JsonValueScope &jv, const td_api::CanSendMessageToUserResult &object) {
  td_api::downcast_call(const_cast<td_api::CanSendMessageToUserResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::canSendMessageToUserResultOk &object) {
  auto jo = jv.enter_object();
  jo("@type", "canSendMessageToUserResultOk");
}

void to_json(JsonValueScope &jv, const td_api::canSendMessageToUserResultUserHasPaidMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "canSendMessageToUserResultUserHasPaidMessages");
  jo("outgoing_paid_message_star_count", object.outgoing_paid_message_star_count_);
}

void to_json(JsonValueScope &jv, const td_api::canSendMessageToUserResultUserIsDeleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "canSendMessageToUserResultUserIsDeleted");
}

void to_json(JsonValueScope &jv, const td_api::canSendMessageToUserResultUserRestrictsNewChats &object) {
  auto jo = jv.enter_object();
  jo("@type", "canSendMessageToUserResultUserRestrictsNewChats");
}

void to_json(JsonValueScope &jv, const td_api::ChatAvailableReactions &object) {
  td_api::downcast_call(const_cast<td_api::ChatAvailableReactions &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatAvailableReactionsAll &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatAvailableReactionsAll");
  jo("max_reaction_count", object.max_reaction_count_);
}

void to_json(JsonValueScope &jv, const td_api::chatAvailableReactionsSome &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatAvailableReactionsSome");
  jo("reactions", ToJson(object.reactions_));
  jo("max_reaction_count", object.max_reaction_count_);
}

void to_json(JsonValueScope &jv, const td_api::ChatBoostSource &object) {
  td_api::downcast_call(const_cast<td_api::ChatBoostSource &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatBoostSourceGiftCode &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatBoostSourceGiftCode");
  jo("user_id", object.user_id_);
  jo("gift_code", object.gift_code_);
}

void to_json(JsonValueScope &jv, const td_api::chatBoostSourceGiveaway &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatBoostSourceGiveaway");
  jo("user_id", object.user_id_);
  jo("gift_code", object.gift_code_);
  jo("star_count", object.star_count_);
  jo("giveaway_message_id", object.giveaway_message_id_);
  jo("is_unclaimed", JsonBool{object.is_unclaimed_});
}

void to_json(JsonValueScope &jv, const td_api::chatBoostSourcePremium &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatBoostSourcePremium");
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::chatFolderInviteLinkInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatFolderInviteLinkInfo");
  if (object.chat_folder_info_) {
    jo("chat_folder_info", ToJson(*object.chat_folder_info_));
  }
  jo("missing_chat_ids", ToJson(object.missing_chat_ids_));
  jo("added_chat_ids", ToJson(object.added_chat_ids_));
}

void to_json(JsonValueScope &jv, const td_api::chatInviteLinkSubscriptionInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatInviteLinkSubscriptionInfo");
  if (object.pricing_) {
    jo("pricing", ToJson(*object.pricing_));
  }
  jo("can_reuse", JsonBool{object.can_reuse_});
  jo("form_id", ToJson(JsonInt64{object.form_id_}));
}

void to_json(JsonValueScope &jv, const td_api::ChatMemberStatus &object) {
  td_api::downcast_call(const_cast<td_api::ChatMemberStatus &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatMemberStatusCreator &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatMemberStatusCreator");
  jo("is_anonymous", JsonBool{object.is_anonymous_});
  jo("is_member", JsonBool{object.is_member_});
}

void to_json(JsonValueScope &jv, const td_api::chatMemberStatusAdministrator &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatMemberStatusAdministrator");
  jo("can_be_edited", JsonBool{object.can_be_edited_});
  if (object.rights_) {
    jo("rights", ToJson(*object.rights_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatMemberStatusMember &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatMemberStatusMember");
  jo("member_until_date", object.member_until_date_);
}

void to_json(JsonValueScope &jv, const td_api::chatMemberStatusRestricted &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatMemberStatusRestricted");
  jo("is_member", JsonBool{object.is_member_});
  jo("restricted_until_date", object.restricted_until_date_);
  if (object.permissions_) {
    jo("permissions", ToJson(*object.permissions_));
  }
}

void to_json(JsonValueScope &jv, const td_api::chatMemberStatusLeft &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatMemberStatusLeft");
}

void to_json(JsonValueScope &jv, const td_api::chatMemberStatusBanned &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatMemberStatusBanned");
  jo("banned_until_date", object.banned_until_date_);
}

void to_json(JsonValueScope &jv, const td_api::ChatPhotoStickerType &object) {
  td_api::downcast_call(const_cast<td_api::ChatPhotoStickerType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatPhotoStickerTypeRegularOrMask &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatPhotoStickerTypeRegularOrMask");
  jo("sticker_set_id", ToJson(JsonInt64{object.sticker_set_id_}));
  jo("sticker_id", ToJson(JsonInt64{object.sticker_id_}));
}

void to_json(JsonValueScope &jv, const td_api::chatPhotoStickerTypeCustomEmoji &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatPhotoStickerTypeCustomEmoji");
  jo("custom_emoji_id", ToJson(JsonInt64{object.custom_emoji_id_}));
}

void to_json(JsonValueScope &jv, const td_api::ChatStatistics &object) {
  td_api::downcast_call(const_cast<td_api::ChatStatistics &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::chatStatisticsSupergroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatStatisticsSupergroup");
  if (object.period_) {
    jo("period", ToJson(*object.period_));
  }
  if (object.member_count_) {
    jo("member_count", ToJson(*object.member_count_));
  }
  if (object.message_count_) {
    jo("message_count", ToJson(*object.message_count_));
  }
  if (object.viewer_count_) {
    jo("viewer_count", ToJson(*object.viewer_count_));
  }
  if (object.sender_count_) {
    jo("sender_count", ToJson(*object.sender_count_));
  }
  if (object.member_count_graph_) {
    jo("member_count_graph", ToJson(*object.member_count_graph_));
  }
  if (object.join_graph_) {
    jo("join_graph", ToJson(*object.join_graph_));
  }
  if (object.join_by_source_graph_) {
    jo("join_by_source_graph", ToJson(*object.join_by_source_graph_));
  }
  if (object.language_graph_) {
    jo("language_graph", ToJson(*object.language_graph_));
  }
  if (object.message_content_graph_) {
    jo("message_content_graph", ToJson(*object.message_content_graph_));
  }
  if (object.action_graph_) {
    jo("action_graph", ToJson(*object.action_graph_));
  }
  if (object.day_graph_) {
    jo("day_graph", ToJson(*object.day_graph_));
  }
  if (object.week_graph_) {
    jo("week_graph", ToJson(*object.week_graph_));
  }
  jo("top_senders", ToJson(object.top_senders_));
  jo("top_administrators", ToJson(object.top_administrators_));
  jo("top_inviters", ToJson(object.top_inviters_));
}

void to_json(JsonValueScope &jv, const td_api::chatStatisticsChannel &object) {
  auto jo = jv.enter_object();
  jo("@type", "chatStatisticsChannel");
  if (object.period_) {
    jo("period", ToJson(*object.period_));
  }
  if (object.member_count_) {
    jo("member_count", ToJson(*object.member_count_));
  }
  if (object.mean_message_view_count_) {
    jo("mean_message_view_count", ToJson(*object.mean_message_view_count_));
  }
  if (object.mean_message_share_count_) {
    jo("mean_message_share_count", ToJson(*object.mean_message_share_count_));
  }
  if (object.mean_message_reaction_count_) {
    jo("mean_message_reaction_count", ToJson(*object.mean_message_reaction_count_));
  }
  if (object.mean_story_view_count_) {
    jo("mean_story_view_count", ToJson(*object.mean_story_view_count_));
  }
  if (object.mean_story_share_count_) {
    jo("mean_story_share_count", ToJson(*object.mean_story_share_count_));
  }
  if (object.mean_story_reaction_count_) {
    jo("mean_story_reaction_count", ToJson(*object.mean_story_reaction_count_));
  }
  jo("enabled_notifications_percentage", object.enabled_notifications_percentage_);
  if (object.member_count_graph_) {
    jo("member_count_graph", ToJson(*object.member_count_graph_));
  }
  if (object.join_graph_) {
    jo("join_graph", ToJson(*object.join_graph_));
  }
  if (object.mute_graph_) {
    jo("mute_graph", ToJson(*object.mute_graph_));
  }
  if (object.view_count_by_hour_graph_) {
    jo("view_count_by_hour_graph", ToJson(*object.view_count_by_hour_graph_));
  }
  if (object.view_count_by_source_graph_) {
    jo("view_count_by_source_graph", ToJson(*object.view_count_by_source_graph_));
  }
  if (object.join_by_source_graph_) {
    jo("join_by_source_graph", ToJson(*object.join_by_source_graph_));
  }
  if (object.language_graph_) {
    jo("language_graph", ToJson(*object.language_graph_));
  }
  if (object.message_interaction_graph_) {
    jo("message_interaction_graph", ToJson(*object.message_interaction_graph_));
  }
  if (object.message_reaction_graph_) {
    jo("message_reaction_graph", ToJson(*object.message_reaction_graph_));
  }
  if (object.story_interaction_graph_) {
    jo("story_interaction_graph", ToJson(*object.story_interaction_graph_));
  }
  if (object.story_reaction_graph_) {
    jo("story_reaction_graph", ToJson(*object.story_reaction_graph_));
  }
  if (object.instant_view_interaction_graph_) {
    jo("instant_view_interaction_graph", ToJson(*object.instant_view_interaction_graph_));
  }
  jo("recent_interactions", ToJson(object.recent_interactions_));
}

void to_json(JsonValueScope &jv, const td_api::CheckChatUsernameResult &object) {
  td_api::downcast_call(const_cast<td_api::CheckChatUsernameResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::checkChatUsernameResultOk &object) {
  auto jo = jv.enter_object();
  jo("@type", "checkChatUsernameResultOk");
}

void to_json(JsonValueScope &jv, const td_api::checkChatUsernameResultUsernameInvalid &object) {
  auto jo = jv.enter_object();
  jo("@type", "checkChatUsernameResultUsernameInvalid");
}

void to_json(JsonValueScope &jv, const td_api::checkChatUsernameResultUsernameOccupied &object) {
  auto jo = jv.enter_object();
  jo("@type", "checkChatUsernameResultUsernameOccupied");
}

void to_json(JsonValueScope &jv, const td_api::checkChatUsernameResultUsernamePurchasable &object) {
  auto jo = jv.enter_object();
  jo("@type", "checkChatUsernameResultUsernamePurchasable");
}

void to_json(JsonValueScope &jv, const td_api::checkChatUsernameResultPublicChatsTooMany &object) {
  auto jo = jv.enter_object();
  jo("@type", "checkChatUsernameResultPublicChatsTooMany");
}

void to_json(JsonValueScope &jv, const td_api::checkChatUsernameResultPublicGroupsUnavailable &object) {
  auto jo = jv.enter_object();
  jo("@type", "checkChatUsernameResultPublicGroupsUnavailable");
}

void to_json(JsonValueScope &jv, const td_api::connectedWebsite &object) {
  auto jo = jv.enter_object();
  jo("@type", "connectedWebsite");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("domain_name", object.domain_name_);
  jo("bot_user_id", object.bot_user_id_);
  jo("browser", object.browser_);
  jo("platform", object.platform_);
  jo("log_in_date", object.log_in_date_);
  jo("last_active_date", object.last_active_date_);
  jo("ip_address", object.ip_address_);
  jo("location", object.location_);
}

void to_json(JsonValueScope &jv, const td_api::currentWeather &object) {
  auto jo = jv.enter_object();
  jo("@type", "currentWeather");
  jo("temperature", object.temperature_);
  jo("emoji", object.emoji_);
}

void to_json(JsonValueScope &jv, const td_api::deepLinkInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "deepLinkInfo");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("need_update_application", JsonBool{object.need_update_application_});
}

void to_json(JsonValueScope &jv, const td_api::emailAddressAuthenticationCodeInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "emailAddressAuthenticationCodeInfo");
  jo("email_address_pattern", object.email_address_pattern_);
  jo("length", object.length_);
}

void to_json(JsonValueScope &jv, const td_api::emojiStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "emojiStatus");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("expiration_date", object.expiration_date_);
}

void to_json(JsonValueScope &jv, const td_api::failedToAddMember &object) {
  auto jo = jv.enter_object();
  jo("@type", "failedToAddMember");
  jo("user_id", object.user_id_);
  jo("premium_would_allow_invite", JsonBool{object.premium_would_allow_invite_});
  jo("premium_required_to_send_messages", JsonBool{object.premium_required_to_send_messages_});
}

void to_json(JsonValueScope &jv, const td_api::forumTopic &object) {
  auto jo = jv.enter_object();
  jo("@type", "forumTopic");
  if (object.info_) {
    jo("info", ToJson(*object.info_));
  }
  if (object.last_message_) {
    jo("last_message", ToJson(*object.last_message_));
  }
  jo("order", ToJson(JsonInt64{object.order_}));
  jo("is_pinned", JsonBool{object.is_pinned_});
  jo("unread_count", object.unread_count_);
  jo("last_read_inbox_message_id", object.last_read_inbox_message_id_);
  jo("last_read_outbox_message_id", object.last_read_outbox_message_id_);
  jo("unread_mention_count", object.unread_mention_count_);
  jo("unread_reaction_count", object.unread_reaction_count_);
  jo("unread_poll_vote_count", object.unread_poll_vote_count_);
  if (object.notification_settings_) {
    jo("notification_settings", ToJson(*object.notification_settings_));
  }
  if (object.draft_message_) {
    jo("draft_message", ToJson(*object.draft_message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::foundFileDownloads &object) {
  auto jo = jv.enter_object();
  jo("@type", "foundFileDownloads");
  if (object.total_counts_) {
    jo("total_counts", ToJson(*object.total_counts_));
  }
  jo("files", ToJson(object.files_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::gameHighScore &object) {
  auto jo = jv.enter_object();
  jo("@type", "gameHighScore");
  jo("position", object.position_);
  jo("user_id", object.user_id_);
  jo("score", object.score_);
}

void to_json(JsonValueScope &jv, const td_api::giftChatThemes &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftChatThemes");
  jo("themes", ToJson(object.themes_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::giftSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "giftSettings");
  jo("show_gift_button", JsonBool{object.show_gift_button_});
  if (object.accepted_gift_types_) {
    jo("accepted_gift_types", ToJson(*object.accepted_gift_types_));
  }
}

void to_json(JsonValueScope &jv, const td_api::GiveawayPrize &object) {
  td_api::downcast_call(const_cast<td_api::GiveawayPrize &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::giveawayPrizePremium &object) {
  auto jo = jv.enter_object();
  jo("@type", "giveawayPrizePremium");
  jo("month_count", object.month_count_);
}

void to_json(JsonValueScope &jv, const td_api::giveawayPrizeStars &object) {
  auto jo = jv.enter_object();
  jo("@type", "giveawayPrizeStars");
  jo("star_count", object.star_count_);
}

void to_json(JsonValueScope &jv, const td_api::groupCallRecentSpeaker &object) {
  auto jo = jv.enter_object();
  jo("@type", "groupCallRecentSpeaker");
  if (object.participant_id_) {
    jo("participant_id", ToJson(*object.participant_id_));
  }
  jo("is_speaking", JsonBool{object.is_speaking_});
}

void to_json(JsonValueScope &jv, const td_api::InlineKeyboardButtonType &object) {
  td_api::downcast_call(const_cast<td_api::InlineKeyboardButtonType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::inlineKeyboardButtonTypeUrl &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineKeyboardButtonTypeUrl");
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::inlineKeyboardButtonTypeLoginUrl &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineKeyboardButtonTypeLoginUrl");
  jo("url", object.url_);
  jo("id", object.id_);
  jo("forward_text", object.forward_text_);
}

void to_json(JsonValueScope &jv, const td_api::inlineKeyboardButtonTypeWebApp &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineKeyboardButtonTypeWebApp");
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::inlineKeyboardButtonTypeCallback &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineKeyboardButtonTypeCallback");
  jo("data", base64_encode(object.data_));
}

void to_json(JsonValueScope &jv, const td_api::inlineKeyboardButtonTypeCallbackWithPassword &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineKeyboardButtonTypeCallbackWithPassword");
  jo("data", base64_encode(object.data_));
}

void to_json(JsonValueScope &jv, const td_api::inlineKeyboardButtonTypeCallbackGame &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineKeyboardButtonTypeCallbackGame");
}

void to_json(JsonValueScope &jv, const td_api::inlineKeyboardButtonTypeSwitchInline &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineKeyboardButtonTypeSwitchInline");
  jo("query", object.query_);
  if (object.target_chat_) {
    jo("target_chat", ToJson(*object.target_chat_));
  }
}

void to_json(JsonValueScope &jv, const td_api::inlineKeyboardButtonTypeBuy &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineKeyboardButtonTypeBuy");
}

void to_json(JsonValueScope &jv, const td_api::inlineKeyboardButtonTypeUser &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineKeyboardButtonTypeUser");
  jo("user_id", object.user_id_);
}

void to_json(JsonValueScope &jv, const td_api::inlineKeyboardButtonTypeCopyText &object) {
  auto jo = jv.enter_object();
  jo("@type", "inlineKeyboardButtonTypeCopyText");
  jo("text", object.text_);
}

void to_json(JsonValueScope &jv, const td_api::InputMessageReplyTo &object) {
  td_api::downcast_call(const_cast<td_api::InputMessageReplyTo &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::inputMessageReplyToMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageReplyToMessage");
  jo("message_id", object.message_id_);
  if (object.quote_) {
    jo("quote", ToJson(*object.quote_));
  }
  jo("checklist_task_id", object.checklist_task_id_);
  jo("poll_option_id", object.poll_option_id_);
}

void to_json(JsonValueScope &jv, const td_api::inputMessageReplyToExternalMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageReplyToExternalMessage");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  if (object.quote_) {
    jo("quote", ToJson(*object.quote_));
  }
  jo("checklist_task_id", object.checklist_task_id_);
  jo("poll_option_id", object.poll_option_id_);
}

void to_json(JsonValueScope &jv, const td_api::inputMessageReplyToStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "inputMessageReplyToStory");
  jo("story_poster_chat_id", object.story_poster_chat_id_);
  jo("story_id", object.story_id_);
}

void to_json(JsonValueScope &jv, const td_api::InviteGroupCallParticipantResult &object) {
  td_api::downcast_call(const_cast<td_api::InviteGroupCallParticipantResult &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::inviteGroupCallParticipantResultUserPrivacyRestricted &object) {
  auto jo = jv.enter_object();
  jo("@type", "inviteGroupCallParticipantResultUserPrivacyRestricted");
}

void to_json(JsonValueScope &jv, const td_api::inviteGroupCallParticipantResultUserAlreadyParticipant &object) {
  auto jo = jv.enter_object();
  jo("@type", "inviteGroupCallParticipantResultUserAlreadyParticipant");
}

void to_json(JsonValueScope &jv, const td_api::inviteGroupCallParticipantResultUserWasBanned &object) {
  auto jo = jv.enter_object();
  jo("@type", "inviteGroupCallParticipantResultUserWasBanned");
}

void to_json(JsonValueScope &jv, const td_api::inviteGroupCallParticipantResultSuccess &object) {
  auto jo = jv.enter_object();
  jo("@type", "inviteGroupCallParticipantResultSuccess");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
}

void to_json(JsonValueScope &jv, const td_api::languagePackString &object) {
  auto jo = jv.enter_object();
  jo("@type", "languagePackString");
  jo("key", object.key_);
  if (object.value_) {
    jo("value", ToJson(*object.value_));
  }
}

void to_json(JsonValueScope &jv, const td_api::localizationTargetInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "localizationTargetInfo");
  jo("language_packs", ToJson(object.language_packs_));
}

void to_json(JsonValueScope &jv, const td_api::maskPosition &object) {
  auto jo = jv.enter_object();
  jo("@type", "maskPosition");
  if (object.point_) {
    jo("point", ToJson(*object.point_));
  }
  jo("x_shift", object.x_shift_);
  jo("y_shift", object.y_shift_);
  jo("scale", object.scale_);
}

void to_json(JsonValueScope &jv, const td_api::MessageFileType &object) {
  td_api::downcast_call(const_cast<td_api::MessageFileType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::messageFileTypePrivate &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageFileTypePrivate");
  jo("name", object.name_);
}

void to_json(JsonValueScope &jv, const td_api::messageFileTypeGroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageFileTypeGroup");
  jo("title", object.title_);
}

void to_json(JsonValueScope &jv, const td_api::messageFileTypeUnknown &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageFileTypeUnknown");
}

void to_json(JsonValueScope &jv, const td_api::messageProperties &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageProperties");
  jo("can_add_offer", JsonBool{object.can_add_offer_});
  jo("can_add_tasks", JsonBool{object.can_add_tasks_});
  jo("can_be_approved", JsonBool{object.can_be_approved_});
  jo("can_be_copied", JsonBool{object.can_be_copied_});
  jo("can_be_copied_to_secret_chat", JsonBool{object.can_be_copied_to_secret_chat_});
  jo("can_be_declined", JsonBool{object.can_be_declined_});
  jo("can_be_deleted_only_for_self", JsonBool{object.can_be_deleted_only_for_self_});
  jo("can_be_deleted_for_all_users", JsonBool{object.can_be_deleted_for_all_users_});
  jo("can_be_edited", JsonBool{object.can_be_edited_});
  jo("can_be_forwarded", JsonBool{object.can_be_forwarded_});
  jo("can_be_paid", JsonBool{object.can_be_paid_});
  jo("can_be_pinned", JsonBool{object.can_be_pinned_});
  jo("can_be_replied", JsonBool{object.can_be_replied_});
  jo("can_be_replied_in_another_chat", JsonBool{object.can_be_replied_in_another_chat_});
  jo("can_be_saved", JsonBool{object.can_be_saved_});
  jo("can_be_shared_in_story", JsonBool{object.can_be_shared_in_story_});
  jo("can_edit_media", JsonBool{object.can_edit_media_});
  jo("can_edit_scheduling_state", JsonBool{object.can_edit_scheduling_state_});
  jo("can_edit_suggested_post_info", JsonBool{object.can_edit_suggested_post_info_});
  jo("can_get_author", JsonBool{object.can_get_author_});
  jo("can_get_embedding_code", JsonBool{object.can_get_embedding_code_});
  jo("can_get_link", JsonBool{object.can_get_link_});
  jo("can_get_media_timestamp_links", JsonBool{object.can_get_media_timestamp_links_});
  jo("can_get_message_thread", JsonBool{object.can_get_message_thread_});
  jo("can_get_read_date", JsonBool{object.can_get_read_date_});
  jo("can_get_statistics", JsonBool{object.can_get_statistics_});
  jo("can_get_video_advertisements", JsonBool{object.can_get_video_advertisements_});
  jo("can_get_viewers", JsonBool{object.can_get_viewers_});
  jo("can_mark_tasks_as_done", JsonBool{object.can_mark_tasks_as_done_});
  jo("can_recognize_speech", JsonBool{object.can_recognize_speech_});
  jo("can_report_chat", JsonBool{object.can_report_chat_});
  jo("can_report_reactions", JsonBool{object.can_report_reactions_});
  jo("can_report_supergroup_spam", JsonBool{object.can_report_supergroup_spam_});
  jo("can_set_fact_check", JsonBool{object.can_set_fact_check_});
  jo("has_protected_content_by_current_user", JsonBool{object.has_protected_content_by_current_user_});
  jo("has_protected_content_by_other_user", JsonBool{object.has_protected_content_by_other_user_});
  jo("need_show_statistics", JsonBool{object.need_show_statistics_});
}

void to_json(JsonValueScope &jv, const td_api::messageSenders &object) {
  auto jo = jv.enter_object();
  jo("@type", "messageSenders");
  jo("total_count", object.total_count_);
  jo("senders", ToJson(object.senders_));
}

void to_json(JsonValueScope &jv, const td_api::networkStatistics &object) {
  auto jo = jv.enter_object();
  jo("@type", "networkStatistics");
  jo("since_date", object.since_date_);
  jo("entries", ToJson(object.entries_));
}

void to_json(JsonValueScope &jv, const td_api::notificationSounds &object) {
  auto jo = jv.enter_object();
  jo("@type", "notificationSounds");
  jo("notification_sounds", ToJson(object.notification_sounds_));
}

void to_json(JsonValueScope &jv, const td_api::PageBlockHorizontalAlignment &object) {
  td_api::downcast_call(const_cast<td_api::PageBlockHorizontalAlignment &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::pageBlockHorizontalAlignmentLeft &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockHorizontalAlignmentLeft");
}

void to_json(JsonValueScope &jv, const td_api::pageBlockHorizontalAlignmentCenter &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockHorizontalAlignmentCenter");
}

void to_json(JsonValueScope &jv, const td_api::pageBlockHorizontalAlignmentRight &object) {
  auto jo = jv.enter_object();
  jo("@type", "pageBlockHorizontalAlignmentRight");
}

void to_json(JsonValueScope &jv, const td_api::passkeys &object) {
  auto jo = jv.enter_object();
  jo("@type", "passkeys");
  jo("passkeys", ToJson(object.passkeys_));
}

void to_json(JsonValueScope &jv, const td_api::passportSuitableElement &object) {
  auto jo = jv.enter_object();
  jo("@type", "passportSuitableElement");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("is_selfie_required", JsonBool{object.is_selfie_required_});
  jo("is_translation_required", JsonBool{object.is_translation_required_});
  jo("is_native_name_required", JsonBool{object.is_native_name_required_});
}

void to_json(JsonValueScope &jv, const td_api::personalDetails &object) {
  auto jo = jv.enter_object();
  jo("@type", "personalDetails");
  jo("first_name", object.first_name_);
  jo("middle_name", object.middle_name_);
  jo("last_name", object.last_name_);
  jo("native_first_name", object.native_first_name_);
  jo("native_middle_name", object.native_middle_name_);
  jo("native_last_name", object.native_last_name_);
  if (object.birthdate_) {
    jo("birthdate", ToJson(*object.birthdate_));
  }
  jo("gender", object.gender_);
  jo("country_code", object.country_code_);
  jo("residence_country_code", object.residence_country_code_);
}

void to_json(JsonValueScope &jv, const td_api::PollType &object) {
  td_api::downcast_call(const_cast<td_api::PollType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::pollTypeRegular &object) {
  auto jo = jv.enter_object();
  jo("@type", "pollTypeRegular");
}

void to_json(JsonValueScope &jv, const td_api::pollTypeQuiz &object) {
  auto jo = jv.enter_object();
  jo("@type", "pollTypeQuiz");
  jo("correct_option_ids", ToJson(object.correct_option_ids_));
  if (object.explanation_) {
    jo("explanation", ToJson(*object.explanation_));
  }
  if (object.explanation_media_) {
    jo("explanation_media", ToJson(*object.explanation_media_));
  }
}

void to_json(JsonValueScope &jv, const td_api::premiumGiveawayPaymentOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "premiumGiveawayPaymentOption");
  jo("currency", object.currency_);
  jo("amount", object.amount_);
  jo("winner_count", object.winner_count_);
  jo("month_count", object.month_count_);
  jo("store_product_id", object.store_product_id_);
  jo("store_product_quantity", object.store_product_quantity_);
}

void to_json(JsonValueScope &jv, const td_api::preparedInlineMessageId &object) {
  auto jo = jv.enter_object();
  jo("@type", "preparedInlineMessageId");
  jo("id", object.id_);
  jo("expiration_date", object.expiration_date_);
}

void to_json(JsonValueScope &jv, const td_api::publicForwards &object) {
  auto jo = jv.enter_object();
  jo("@type", "publicForwards");
  jo("total_count", object.total_count_);
  jo("forwards", ToJson(object.forwards_));
  jo("next_offset", object.next_offset_);
}

void to_json(JsonValueScope &jv, const td_api::ReactionType &object) {
  td_api::downcast_call(const_cast<td_api::ReactionType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::reactionTypeEmoji &object) {
  auto jo = jv.enter_object();
  jo("@type", "reactionTypeEmoji");
  jo("emoji", object.emoji_);
}

void to_json(JsonValueScope &jv, const td_api::reactionTypeCustomEmoji &object) {
  auto jo = jv.enter_object();
  jo("@type", "reactionTypeCustomEmoji");
  jo("custom_emoji_id", ToJson(JsonInt64{object.custom_emoji_id_}));
}

void to_json(JsonValueScope &jv, const td_api::reactionTypePaid &object) {
  auto jo = jv.enter_object();
  jo("@type", "reactionTypePaid");
}

void to_json(JsonValueScope &jv, const td_api::ReplyMarkup &object) {
  td_api::downcast_call(const_cast<td_api::ReplyMarkup &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::replyMarkupRemoveKeyboard &object) {
  auto jo = jv.enter_object();
  jo("@type", "replyMarkupRemoveKeyboard");
  jo("is_personal", JsonBool{object.is_personal_});
}

void to_json(JsonValueScope &jv, const td_api::replyMarkupForceReply &object) {
  auto jo = jv.enter_object();
  jo("@type", "replyMarkupForceReply");
  jo("is_personal", JsonBool{object.is_personal_});
  jo("input_field_placeholder", object.input_field_placeholder_);
}

void to_json(JsonValueScope &jv, const td_api::replyMarkupShowKeyboard &object) {
  auto jo = jv.enter_object();
  jo("@type", "replyMarkupShowKeyboard");
  jo("rows", ToJson(object.rows_));
  jo("is_persistent", JsonBool{object.is_persistent_});
  jo("resize_keyboard", JsonBool{object.resize_keyboard_});
  jo("one_time", JsonBool{object.one_time_});
  jo("is_personal", JsonBool{object.is_personal_});
  jo("input_field_placeholder", object.input_field_placeholder_);
}

void to_json(JsonValueScope &jv, const td_api::replyMarkupInlineKeyboard &object) {
  auto jo = jv.enter_object();
  jo("@type", "replyMarkupInlineKeyboard");
  jo("rows", ToJson(object.rows_));
}

void to_json(JsonValueScope &jv, const td_api::rtmpUrl &object) {
  auto jo = jv.enter_object();
  jo("@type", "rtmpUrl");
  jo("url", object.url_);
  jo("stream_key", object.stream_key_);
}

void to_json(JsonValueScope &jv, const td_api::secretChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "secretChat");
  jo("id", object.id_);
  jo("user_id", object.user_id_);
  if (object.state_) {
    jo("state", ToJson(*object.state_));
  }
  jo("is_outbound", JsonBool{object.is_outbound_});
  jo("key_hash", base64_encode(object.key_hash_));
  jo("layer", object.layer_);
}

void to_json(JsonValueScope &jv, const td_api::sharedUser &object) {
  auto jo = jv.enter_object();
  jo("@type", "sharedUser");
  jo("user_id", object.user_id_);
  jo("first_name", object.first_name_);
  jo("last_name", object.last_name_);
  jo("username", object.username_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::starCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "starCount");
  jo("star_count", object.star_count_);
}

void to_json(JsonValueScope &jv, const td_api::starSubscriptionPricing &object) {
  auto jo = jv.enter_object();
  jo("@type", "starSubscriptionPricing");
  jo("period", object.period_);
  jo("star_count", object.star_count_);
}

void to_json(JsonValueScope &jv, const td_api::sticker &object) {
  auto jo = jv.enter_object();
  jo("@type", "sticker");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("set_id", ToJson(JsonInt64{object.set_id_}));
  jo("width", object.width_);
  jo("height", object.height_);
  jo("emoji", object.emoji_);
  if (object.format_) {
    jo("format", ToJson(*object.format_));
  }
  if (object.full_type_) {
    jo("full_type", ToJson(*object.full_type_));
  }
  if (object.thumbnail_) {
    jo("thumbnail", ToJson(*object.thumbnail_));
  }
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::storageStatisticsByChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "storageStatisticsByChat");
  jo("chat_id", object.chat_id_);
  jo("size", object.size_);
  jo("count", object.count_);
  jo("by_file_type", ToJson(object.by_file_type_));
}

void to_json(JsonValueScope &jv, const td_api::StoryAreaType &object) {
  td_api::downcast_call(const_cast<td_api::StoryAreaType &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::storyAreaTypeLocation &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyAreaTypeLocation");
  if (object.location_) {
    jo("location", ToJson(*object.location_));
  }
  if (object.address_) {
    jo("address", ToJson(*object.address_));
  }
}

void to_json(JsonValueScope &jv, const td_api::storyAreaTypeVenue &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyAreaTypeVenue");
  if (object.venue_) {
    jo("venue", ToJson(*object.venue_));
  }
}

void to_json(JsonValueScope &jv, const td_api::storyAreaTypeSuggestedReaction &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyAreaTypeSuggestedReaction");
  if (object.reaction_type_) {
    jo("reaction_type", ToJson(*object.reaction_type_));
  }
  jo("total_count", object.total_count_);
  jo("is_dark", JsonBool{object.is_dark_});
  jo("is_flipped", JsonBool{object.is_flipped_});
}

void to_json(JsonValueScope &jv, const td_api::storyAreaTypeMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyAreaTypeMessage");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
}

void to_json(JsonValueScope &jv, const td_api::storyAreaTypeLink &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyAreaTypeLink");
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::storyAreaTypeWeather &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyAreaTypeWeather");
  jo("temperature", object.temperature_);
  jo("emoji", object.emoji_);
  jo("background_color", object.background_color_);
}

void to_json(JsonValueScope &jv, const td_api::storyAreaTypeUpgradedGift &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyAreaTypeUpgradedGift");
  jo("gift_name", object.gift_name_);
}

void to_json(JsonValueScope &jv, const td_api::StoryOrigin &object) {
  td_api::downcast_call(const_cast<td_api::StoryOrigin &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::storyOriginPublicStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyOriginPublicStory");
  jo("chat_id", object.chat_id_);
  jo("story_id", object.story_id_);
}

void to_json(JsonValueScope &jv, const td_api::storyOriginHiddenUser &object) {
  auto jo = jv.enter_object();
  jo("@type", "storyOriginHiddenUser");
  jo("poster_name", object.poster_name_);
}

void to_json(JsonValueScope &jv, const td_api::SuggestedPostState &object) {
  td_api::downcast_call(const_cast<td_api::SuggestedPostState &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::suggestedPostStatePending &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedPostStatePending");
}

void to_json(JsonValueScope &jv, const td_api::suggestedPostStateApproved &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedPostStateApproved");
}

void to_json(JsonValueScope &jv, const td_api::suggestedPostStateDeclined &object) {
  auto jo = jv.enter_object();
  jo("@type", "suggestedPostStateDeclined");
}

void to_json(JsonValueScope &jv, const td_api::termsOfService &object) {
  auto jo = jv.enter_object();
  jo("@type", "termsOfService");
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
  jo("min_user_age", object.min_user_age_);
  jo("show_popup", JsonBool{object.show_popup_});
}

void to_json(JsonValueScope &jv, const td_api::textCompositionStyle &object) {
  auto jo = jv.enter_object();
  jo("@type", "textCompositionStyle");
  jo("name", object.name_);
  jo("custom_emoji_id", ToJson(JsonInt64{object.custom_emoji_id_}));
  jo("title", object.title_);
}

void to_json(JsonValueScope &jv, const td_api::timeZones &object) {
  auto jo = jv.enter_object();
  jo("@type", "timeZones");
  jo("time_zones", ToJson(object.time_zones_));
}

void to_json(JsonValueScope &jv, const td_api::Update &object) {
  td_api::downcast_call(const_cast<td_api::Update &>(object), [&jv](const auto &object) { to_json(jv, object); });
}

void to_json(JsonValueScope &jv, const td_api::updateAuthorizationState &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateAuthorizationState");
  if (object.authorization_state_) {
    jo("authorization_state", ToJson(*object.authorization_state_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNewMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewMessage");
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateMessageSendAcknowledged &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageSendAcknowledged");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
}

void to_json(JsonValueScope &jv, const td_api::updateMessageSendSucceeded &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageSendSucceeded");
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
  jo("old_message_id", object.old_message_id_);
}

void to_json(JsonValueScope &jv, const td_api::updateMessageSendFailed &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageSendFailed");
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
  jo("old_message_id", object.old_message_id_);
  if (object.error_) {
    jo("error", ToJson(*object.error_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateMessageContent &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageContent");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  if (object.new_content_) {
    jo("new_content", ToJson(*object.new_content_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateMessageEdited &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageEdited");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  jo("edit_date", object.edit_date_);
  if (object.reply_markup_) {
    jo("reply_markup", ToJson(*object.reply_markup_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateMessageIsPinned &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageIsPinned");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  jo("is_pinned", JsonBool{object.is_pinned_});
}

void to_json(JsonValueScope &jv, const td_api::updateMessageInteractionInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageInteractionInfo");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  if (object.interaction_info_) {
    jo("interaction_info", ToJson(*object.interaction_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateMessageContentOpened &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageContentOpened");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
}

void to_json(JsonValueScope &jv, const td_api::updateMessageMentionRead &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageMentionRead");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  jo("unread_mention_count", object.unread_mention_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateMessageUnreadReactions &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageUnreadReactions");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  jo("unread_reactions", ToJson(object.unread_reactions_));
  jo("unread_reaction_count", object.unread_reaction_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateMessageFactCheck &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageFactCheck");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  if (object.fact_check_) {
    jo("fact_check", ToJson(*object.fact_check_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateMessageSuggestedPostInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageSuggestedPostInfo");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  if (object.suggested_post_info_) {
    jo("suggested_post_info", ToJson(*object.suggested_post_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateMessageLiveLocationViewed &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageLiveLocationViewed");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
}

void to_json(JsonValueScope &jv, const td_api::updateVideoPublished &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateVideoPublished");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
}

void to_json(JsonValueScope &jv, const td_api::updateNewChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewChat");
  if (object.chat_) {
    jo("chat", ToJson(*object.chat_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatTitle &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatTitle");
  jo("chat_id", object.chat_id_);
  jo("title", object.title_);
}

void to_json(JsonValueScope &jv, const td_api::updateChatPhoto &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatPhoto");
  jo("chat_id", object.chat_id_);
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatAccentColors &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatAccentColors");
  jo("chat_id", object.chat_id_);
  jo("accent_color_id", object.accent_color_id_);
  jo("background_custom_emoji_id", ToJson(JsonInt64{object.background_custom_emoji_id_}));
  if (object.upgraded_gift_colors_) {
    jo("upgraded_gift_colors", ToJson(*object.upgraded_gift_colors_));
  }
  jo("profile_accent_color_id", object.profile_accent_color_id_);
  jo("profile_background_custom_emoji_id", ToJson(JsonInt64{object.profile_background_custom_emoji_id_}));
}

void to_json(JsonValueScope &jv, const td_api::updateChatPermissions &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatPermissions");
  jo("chat_id", object.chat_id_);
  if (object.permissions_) {
    jo("permissions", ToJson(*object.permissions_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatLastMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatLastMessage");
  jo("chat_id", object.chat_id_);
  if (object.last_message_) {
    jo("last_message", ToJson(*object.last_message_));
  }
  jo("positions", ToJson(object.positions_));
}

void to_json(JsonValueScope &jv, const td_api::updateChatPosition &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatPosition");
  jo("chat_id", object.chat_id_);
  if (object.position_) {
    jo("position", ToJson(*object.position_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatAddedToList &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatAddedToList");
  jo("chat_id", object.chat_id_);
  if (object.chat_list_) {
    jo("chat_list", ToJson(*object.chat_list_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatRemovedFromList &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatRemovedFromList");
  jo("chat_id", object.chat_id_);
  if (object.chat_list_) {
    jo("chat_list", ToJson(*object.chat_list_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatReadInbox &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatReadInbox");
  jo("chat_id", object.chat_id_);
  jo("last_read_inbox_message_id", object.last_read_inbox_message_id_);
  jo("unread_count", object.unread_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateChatReadOutbox &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatReadOutbox");
  jo("chat_id", object.chat_id_);
  jo("last_read_outbox_message_id", object.last_read_outbox_message_id_);
}

void to_json(JsonValueScope &jv, const td_api::updateChatActionBar &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatActionBar");
  jo("chat_id", object.chat_id_);
  if (object.action_bar_) {
    jo("action_bar", ToJson(*object.action_bar_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatBusinessBotManageBar &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatBusinessBotManageBar");
  jo("chat_id", object.chat_id_);
  if (object.business_bot_manage_bar_) {
    jo("business_bot_manage_bar", ToJson(*object.business_bot_manage_bar_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatAvailableReactions &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatAvailableReactions");
  jo("chat_id", object.chat_id_);
  if (object.available_reactions_) {
    jo("available_reactions", ToJson(*object.available_reactions_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatDraftMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatDraftMessage");
  jo("chat_id", object.chat_id_);
  if (object.draft_message_) {
    jo("draft_message", ToJson(*object.draft_message_));
  }
  jo("positions", ToJson(object.positions_));
}

void to_json(JsonValueScope &jv, const td_api::updateChatEmojiStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatEmojiStatus");
  jo("chat_id", object.chat_id_);
  if (object.emoji_status_) {
    jo("emoji_status", ToJson(*object.emoji_status_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatMessageSender &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatMessageSender");
  jo("chat_id", object.chat_id_);
  if (object.message_sender_id_) {
    jo("message_sender_id", ToJson(*object.message_sender_id_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatMessageAutoDeleteTime &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatMessageAutoDeleteTime");
  jo("chat_id", object.chat_id_);
  jo("message_auto_delete_time", object.message_auto_delete_time_);
}

void to_json(JsonValueScope &jv, const td_api::updateChatNotificationSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatNotificationSettings");
  jo("chat_id", object.chat_id_);
  if (object.notification_settings_) {
    jo("notification_settings", ToJson(*object.notification_settings_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatPendingJoinRequests &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatPendingJoinRequests");
  jo("chat_id", object.chat_id_);
  if (object.pending_join_requests_) {
    jo("pending_join_requests", ToJson(*object.pending_join_requests_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatReplyMarkup &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatReplyMarkup");
  jo("chat_id", object.chat_id_);
  if (object.reply_markup_message_) {
    jo("reply_markup_message", ToJson(*object.reply_markup_message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatBackground &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatBackground");
  jo("chat_id", object.chat_id_);
  if (object.background_) {
    jo("background", ToJson(*object.background_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatTheme &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatTheme");
  jo("chat_id", object.chat_id_);
  if (object.theme_) {
    jo("theme", ToJson(*object.theme_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatUnreadMentionCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatUnreadMentionCount");
  jo("chat_id", object.chat_id_);
  jo("unread_mention_count", object.unread_mention_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateChatUnreadReactionCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatUnreadReactionCount");
  jo("chat_id", object.chat_id_);
  jo("unread_reaction_count", object.unread_reaction_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateChatUnreadPollVoteCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatUnreadPollVoteCount");
  jo("chat_id", object.chat_id_);
  jo("unread_poll_vote_count", object.unread_poll_vote_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateChatVideoChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatVideoChat");
  jo("chat_id", object.chat_id_);
  if (object.video_chat_) {
    jo("video_chat", ToJson(*object.video_chat_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatDefaultDisableNotification &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatDefaultDisableNotification");
  jo("chat_id", object.chat_id_);
  jo("default_disable_notification", JsonBool{object.default_disable_notification_});
}

void to_json(JsonValueScope &jv, const td_api::updateChatHasProtectedContent &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatHasProtectedContent");
  jo("chat_id", object.chat_id_);
  jo("has_protected_content", JsonBool{object.has_protected_content_});
}

void to_json(JsonValueScope &jv, const td_api::updateChatIsTranslatable &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatIsTranslatable");
  jo("chat_id", object.chat_id_);
  jo("is_translatable", JsonBool{object.is_translatable_});
}

void to_json(JsonValueScope &jv, const td_api::updateChatIsMarkedAsUnread &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatIsMarkedAsUnread");
  jo("chat_id", object.chat_id_);
  jo("is_marked_as_unread", JsonBool{object.is_marked_as_unread_});
}

void to_json(JsonValueScope &jv, const td_api::updateChatViewAsTopics &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatViewAsTopics");
  jo("chat_id", object.chat_id_);
  jo("view_as_topics", JsonBool{object.view_as_topics_});
}

void to_json(JsonValueScope &jv, const td_api::updateChatBlockList &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatBlockList");
  jo("chat_id", object.chat_id_);
  if (object.block_list_) {
    jo("block_list", ToJson(*object.block_list_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatHasScheduledMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatHasScheduledMessages");
  jo("chat_id", object.chat_id_);
  jo("has_scheduled_messages", JsonBool{object.has_scheduled_messages_});
}

void to_json(JsonValueScope &jv, const td_api::updateChatFolders &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatFolders");
  jo("chat_folders", ToJson(object.chat_folders_));
  jo("main_chat_list_position", object.main_chat_list_position_);
  jo("are_tags_enabled", JsonBool{object.are_tags_enabled_});
}

void to_json(JsonValueScope &jv, const td_api::updateChatOnlineMemberCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatOnlineMemberCount");
  jo("chat_id", object.chat_id_);
  jo("online_member_count", object.online_member_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateSavedMessagesTopic &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateSavedMessagesTopic");
  if (object.topic_) {
    jo("topic", ToJson(*object.topic_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateSavedMessagesTopicCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateSavedMessagesTopicCount");
  jo("topic_count", object.topic_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateDirectMessagesChatTopic &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateDirectMessagesChatTopic");
  if (object.topic_) {
    jo("topic", ToJson(*object.topic_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateTopicMessageCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateTopicMessageCount");
  jo("chat_id", object.chat_id_);
  if (object.topic_id_) {
    jo("topic_id", ToJson(*object.topic_id_));
  }
  jo("message_count", object.message_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateQuickReplyShortcut &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateQuickReplyShortcut");
  if (object.shortcut_) {
    jo("shortcut", ToJson(*object.shortcut_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateQuickReplyShortcutDeleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateQuickReplyShortcutDeleted");
  jo("shortcut_id", object.shortcut_id_);
}

void to_json(JsonValueScope &jv, const td_api::updateQuickReplyShortcuts &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateQuickReplyShortcuts");
  jo("shortcut_ids", ToJson(object.shortcut_ids_));
}

void to_json(JsonValueScope &jv, const td_api::updateQuickReplyShortcutMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateQuickReplyShortcutMessages");
  jo("shortcut_id", object.shortcut_id_);
  jo("messages", ToJson(object.messages_));
}

void to_json(JsonValueScope &jv, const td_api::updateForumTopicInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateForumTopicInfo");
  if (object.info_) {
    jo("info", ToJson(*object.info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateForumTopic &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateForumTopic");
  jo("chat_id", object.chat_id_);
  jo("forum_topic_id", object.forum_topic_id_);
  jo("is_pinned", JsonBool{object.is_pinned_});
  jo("last_read_inbox_message_id", object.last_read_inbox_message_id_);
  jo("last_read_outbox_message_id", object.last_read_outbox_message_id_);
  jo("unread_mention_count", object.unread_mention_count_);
  jo("unread_reaction_count", object.unread_reaction_count_);
  jo("unread_poll_vote_count", object.unread_poll_vote_count_);
  if (object.notification_settings_) {
    jo("notification_settings", ToJson(*object.notification_settings_));
  }
  if (object.draft_message_) {
    jo("draft_message", ToJson(*object.draft_message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateScopeNotificationSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateScopeNotificationSettings");
  if (object.scope_) {
    jo("scope", ToJson(*object.scope_));
  }
  if (object.notification_settings_) {
    jo("notification_settings", ToJson(*object.notification_settings_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateReactionNotificationSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateReactionNotificationSettings");
  if (object.notification_settings_) {
    jo("notification_settings", ToJson(*object.notification_settings_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNotification &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNotification");
  jo("notification_group_id", object.notification_group_id_);
  if (object.notification_) {
    jo("notification", ToJson(*object.notification_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNotificationGroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNotificationGroup");
  jo("notification_group_id", object.notification_group_id_);
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
  jo("chat_id", object.chat_id_);
  jo("notification_settings_chat_id", object.notification_settings_chat_id_);
  jo("notification_sound_id", ToJson(JsonInt64{object.notification_sound_id_}));
  jo("total_count", object.total_count_);
  jo("added_notifications", ToJson(object.added_notifications_));
  jo("removed_notification_ids", ToJson(object.removed_notification_ids_));
}

void to_json(JsonValueScope &jv, const td_api::updateActiveNotifications &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateActiveNotifications");
  jo("groups", ToJson(object.groups_));
}

void to_json(JsonValueScope &jv, const td_api::updateHavePendingNotifications &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateHavePendingNotifications");
  jo("have_delayed_notifications", JsonBool{object.have_delayed_notifications_});
  jo("have_unreceived_notifications", JsonBool{object.have_unreceived_notifications_});
}

void to_json(JsonValueScope &jv, const td_api::updateDeleteMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateDeleteMessages");
  jo("chat_id", object.chat_id_);
  jo("message_ids", ToJson(object.message_ids_));
  jo("is_permanent", JsonBool{object.is_permanent_});
  jo("from_cache", JsonBool{object.from_cache_});
}

void to_json(JsonValueScope &jv, const td_api::updateChatAction &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatAction");
  jo("chat_id", object.chat_id_);
  if (object.topic_id_) {
    jo("topic_id", ToJson(*object.topic_id_));
  }
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  if (object.action_) {
    jo("action", ToJson(*object.action_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updatePendingTextMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "updatePendingTextMessage");
  jo("chat_id", object.chat_id_);
  jo("forum_topic_id", object.forum_topic_id_);
  jo("draft_id", ToJson(JsonInt64{object.draft_id_}));
  if (object.text_) {
    jo("text", ToJson(*object.text_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateUserStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateUserStatus");
  jo("user_id", object.user_id_);
  if (object.status_) {
    jo("status", ToJson(*object.status_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateUser &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateUser");
  if (object.user_) {
    jo("user", ToJson(*object.user_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateBasicGroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateBasicGroup");
  if (object.basic_group_) {
    jo("basic_group", ToJson(*object.basic_group_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateSupergroup &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateSupergroup");
  if (object.supergroup_) {
    jo("supergroup", ToJson(*object.supergroup_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateSecretChat &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateSecretChat");
  if (object.secret_chat_) {
    jo("secret_chat", ToJson(*object.secret_chat_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateUserFullInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateUserFullInfo");
  jo("user_id", object.user_id_);
  if (object.user_full_info_) {
    jo("user_full_info", ToJson(*object.user_full_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateBasicGroupFullInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateBasicGroupFullInfo");
  jo("basic_group_id", object.basic_group_id_);
  if (object.basic_group_full_info_) {
    jo("basic_group_full_info", ToJson(*object.basic_group_full_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateSupergroupFullInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateSupergroupFullInfo");
  jo("supergroup_id", object.supergroup_id_);
  if (object.supergroup_full_info_) {
    jo("supergroup_full_info", ToJson(*object.supergroup_full_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateServiceNotification &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateServiceNotification");
  jo("type", object.type_);
  if (object.content_) {
    jo("content", ToJson(*object.content_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNewOauthRequest &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewOauthRequest");
  jo("domain", object.domain_);
  jo("location", object.location_);
  jo("url", object.url_);
}

void to_json(JsonValueScope &jv, const td_api::updateFile &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateFile");
  if (object.file_) {
    jo("file", ToJson(*object.file_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateFileGenerationStart &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateFileGenerationStart");
  jo("generation_id", ToJson(JsonInt64{object.generation_id_}));
  jo("original_path", object.original_path_);
  jo("destination_path", object.destination_path_);
  jo("conversion", object.conversion_);
}

void to_json(JsonValueScope &jv, const td_api::updateFileGenerationStop &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateFileGenerationStop");
  jo("generation_id", ToJson(JsonInt64{object.generation_id_}));
}

void to_json(JsonValueScope &jv, const td_api::updateFileDownloads &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateFileDownloads");
  jo("total_size", object.total_size_);
  jo("total_count", object.total_count_);
  jo("downloaded_size", object.downloaded_size_);
}

void to_json(JsonValueScope &jv, const td_api::updateFileAddedToDownloads &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateFileAddedToDownloads");
  if (object.file_download_) {
    jo("file_download", ToJson(*object.file_download_));
  }
  if (object.counts_) {
    jo("counts", ToJson(*object.counts_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateFileDownload &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateFileDownload");
  jo("file_id", object.file_id_);
  jo("complete_date", object.complete_date_);
  jo("is_paused", JsonBool{object.is_paused_});
  if (object.counts_) {
    jo("counts", ToJson(*object.counts_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateFileRemovedFromDownloads &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateFileRemovedFromDownloads");
  jo("file_id", object.file_id_);
  if (object.counts_) {
    jo("counts", ToJson(*object.counts_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateApplicationVerificationRequired &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateApplicationVerificationRequired");
  jo("verification_id", object.verification_id_);
  jo("nonce", object.nonce_);
  jo("cloud_project_number", ToJson(JsonInt64{object.cloud_project_number_}));
}

void to_json(JsonValueScope &jv, const td_api::updateApplicationRecaptchaVerificationRequired &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateApplicationRecaptchaVerificationRequired");
  jo("verification_id", object.verification_id_);
  jo("action", object.action_);
  jo("recaptcha_key_id", object.recaptcha_key_id_);
}

void to_json(JsonValueScope &jv, const td_api::updateCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateCall");
  if (object.call_) {
    jo("call", ToJson(*object.call_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateGroupCall &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateGroupCall");
  if (object.group_call_) {
    jo("group_call", ToJson(*object.group_call_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateGroupCallParticipant &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateGroupCallParticipant");
  jo("group_call_id", object.group_call_id_);
  if (object.participant_) {
    jo("participant", ToJson(*object.participant_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateGroupCallParticipants &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateGroupCallParticipants");
  jo("group_call_id", object.group_call_id_);
  jo("participant_user_ids", ToJson(JsonVectorInt64{object.participant_user_ids_}));
}

void to_json(JsonValueScope &jv, const td_api::updateGroupCallVerificationState &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateGroupCallVerificationState");
  jo("group_call_id", object.group_call_id_);
  jo("generation", object.generation_);
  jo("emojis", ToJson(object.emojis_));
}

void to_json(JsonValueScope &jv, const td_api::updateNewGroupCallMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewGroupCallMessage");
  jo("group_call_id", object.group_call_id_);
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNewGroupCallPaidReaction &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewGroupCallPaidReaction");
  jo("group_call_id", object.group_call_id_);
  if (object.sender_id_) {
    jo("sender_id", ToJson(*object.sender_id_));
  }
  jo("star_count", object.star_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateGroupCallMessageSendFailed &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateGroupCallMessageSendFailed");
  jo("group_call_id", object.group_call_id_);
  jo("message_id", object.message_id_);
  if (object.error_) {
    jo("error", ToJson(*object.error_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateGroupCallMessagesDeleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateGroupCallMessagesDeleted");
  jo("group_call_id", object.group_call_id_);
  jo("message_ids", ToJson(object.message_ids_));
}

void to_json(JsonValueScope &jv, const td_api::updateLiveStoryTopDonors &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateLiveStoryTopDonors");
  jo("group_call_id", object.group_call_id_);
  if (object.donors_) {
    jo("donors", ToJson(*object.donors_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNewCallSignalingData &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewCallSignalingData");
  jo("call_id", object.call_id_);
  jo("data", base64_encode(object.data_));
}

void to_json(JsonValueScope &jv, const td_api::updateGiftAuctionState &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateGiftAuctionState");
  if (object.state_) {
    jo("state", ToJson(*object.state_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateActiveGiftAuctions &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateActiveGiftAuctions");
  jo("states", ToJson(object.states_));
}

void to_json(JsonValueScope &jv, const td_api::updateUserPrivacySettingRules &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateUserPrivacySettingRules");
  if (object.setting_) {
    jo("setting", ToJson(*object.setting_));
  }
  if (object.rules_) {
    jo("rules", ToJson(*object.rules_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateUnreadMessageCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateUnreadMessageCount");
  if (object.chat_list_) {
    jo("chat_list", ToJson(*object.chat_list_));
  }
  jo("unread_count", object.unread_count_);
  jo("unread_unmuted_count", object.unread_unmuted_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateUnreadChatCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateUnreadChatCount");
  if (object.chat_list_) {
    jo("chat_list", ToJson(*object.chat_list_));
  }
  jo("total_count", object.total_count_);
  jo("unread_count", object.unread_count_);
  jo("unread_unmuted_count", object.unread_unmuted_count_);
  jo("marked_as_unread_count", object.marked_as_unread_count_);
  jo("marked_as_unread_unmuted_count", object.marked_as_unread_unmuted_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateStory &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateStory");
  if (object.story_) {
    jo("story", ToJson(*object.story_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateStoryDeleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateStoryDeleted");
  jo("story_poster_chat_id", object.story_poster_chat_id_);
  jo("story_id", object.story_id_);
}

void to_json(JsonValueScope &jv, const td_api::updateStoryPostSucceeded &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateStoryPostSucceeded");
  if (object.story_) {
    jo("story", ToJson(*object.story_));
  }
  jo("old_story_id", object.old_story_id_);
}

void to_json(JsonValueScope &jv, const td_api::updateStoryPostFailed &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateStoryPostFailed");
  if (object.story_) {
    jo("story", ToJson(*object.story_));
  }
  if (object.error_) {
    jo("error", ToJson(*object.error_));
  }
  if (object.error_type_) {
    jo("error_type", ToJson(*object.error_type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatActiveStories &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatActiveStories");
  if (object.active_stories_) {
    jo("active_stories", ToJson(*object.active_stories_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateStoryListChatCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateStoryListChatCount");
  if (object.story_list_) {
    jo("story_list", ToJson(*object.story_list_));
  }
  jo("chat_count", object.chat_count_);
}

void to_json(JsonValueScope &jv, const td_api::updateStoryStealthMode &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateStoryStealthMode");
  jo("active_until_date", object.active_until_date_);
  jo("cooldown_until_date", object.cooldown_until_date_);
}

void to_json(JsonValueScope &jv, const td_api::updateTrustedMiniAppBots &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateTrustedMiniAppBots");
  jo("bot_user_ids", ToJson(object.bot_user_ids_));
}

void to_json(JsonValueScope &jv, const td_api::updateOption &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateOption");
  jo("name", object.name_);
  if (object.value_) {
    jo("value", ToJson(*object.value_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateStickerSet &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateStickerSet");
  if (object.sticker_set_) {
    jo("sticker_set", ToJson(*object.sticker_set_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateInstalledStickerSets &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateInstalledStickerSets");
  if (object.sticker_type_) {
    jo("sticker_type", ToJson(*object.sticker_type_));
  }
  jo("sticker_set_ids", ToJson(JsonVectorInt64{object.sticker_set_ids_}));
}

void to_json(JsonValueScope &jv, const td_api::updateTrendingStickerSets &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateTrendingStickerSets");
  if (object.sticker_type_) {
    jo("sticker_type", ToJson(*object.sticker_type_));
  }
  if (object.sticker_sets_) {
    jo("sticker_sets", ToJson(*object.sticker_sets_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateRecentStickers &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateRecentStickers");
  jo("is_attached", JsonBool{object.is_attached_});
  jo("sticker_ids", ToJson(object.sticker_ids_));
}

void to_json(JsonValueScope &jv, const td_api::updateFavoriteStickers &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateFavoriteStickers");
  jo("sticker_ids", ToJson(object.sticker_ids_));
}

void to_json(JsonValueScope &jv, const td_api::updateSavedAnimations &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateSavedAnimations");
  jo("animation_ids", ToJson(object.animation_ids_));
}

void to_json(JsonValueScope &jv, const td_api::updateSavedNotificationSounds &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateSavedNotificationSounds");
  jo("notification_sound_ids", ToJson(JsonVectorInt64{object.notification_sound_ids_}));
}

void to_json(JsonValueScope &jv, const td_api::updateDefaultBackground &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateDefaultBackground");
  jo("for_dark_theme", JsonBool{object.for_dark_theme_});
  if (object.background_) {
    jo("background", ToJson(*object.background_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateEmojiChatThemes &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateEmojiChatThemes");
  jo("chat_themes", ToJson(object.chat_themes_));
}

void to_json(JsonValueScope &jv, const td_api::updateAccentColors &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateAccentColors");
  jo("colors", ToJson(object.colors_));
  jo("available_accent_color_ids", ToJson(object.available_accent_color_ids_));
}

void to_json(JsonValueScope &jv, const td_api::updateProfileAccentColors &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateProfileAccentColors");
  jo("colors", ToJson(object.colors_));
  jo("available_accent_color_ids", ToJson(object.available_accent_color_ids_));
}

void to_json(JsonValueScope &jv, const td_api::updateLanguagePackStrings &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateLanguagePackStrings");
  jo("localization_target", object.localization_target_);
  jo("language_pack_id", object.language_pack_id_);
  jo("strings", ToJson(object.strings_));
}

void to_json(JsonValueScope &jv, const td_api::updateConnectionState &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateConnectionState");
  if (object.state_) {
    jo("state", ToJson(*object.state_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateFreezeState &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateFreezeState");
  jo("is_frozen", JsonBool{object.is_frozen_});
  jo("freezing_date", object.freezing_date_);
  jo("deletion_date", object.deletion_date_);
  jo("appeal_link", object.appeal_link_);
}

void to_json(JsonValueScope &jv, const td_api::updateAgeVerificationParameters &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateAgeVerificationParameters");
  if (object.parameters_) {
    jo("parameters", ToJson(*object.parameters_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateTermsOfService &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateTermsOfService");
  jo("terms_of_service_id", object.terms_of_service_id_);
  if (object.terms_of_service_) {
    jo("terms_of_service", ToJson(*object.terms_of_service_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateUnconfirmedSession &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateUnconfirmedSession");
  if (object.session_) {
    jo("session", ToJson(*object.session_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateAttachmentMenuBots &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateAttachmentMenuBots");
  jo("bots", ToJson(object.bots_));
}

void to_json(JsonValueScope &jv, const td_api::updateWebAppMessageSent &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateWebAppMessageSent");
  jo("web_app_launch_id", ToJson(JsonInt64{object.web_app_launch_id_}));
}

void to_json(JsonValueScope &jv, const td_api::updateActiveEmojiReactions &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateActiveEmojiReactions");
  jo("emojis", ToJson(object.emojis_));
}

void to_json(JsonValueScope &jv, const td_api::updateAvailableMessageEffects &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateAvailableMessageEffects");
  jo("reaction_effect_ids", ToJson(JsonVectorInt64{object.reaction_effect_ids_}));
  jo("sticker_effect_ids", ToJson(JsonVectorInt64{object.sticker_effect_ids_}));
}

void to_json(JsonValueScope &jv, const td_api::updateDefaultReactionType &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateDefaultReactionType");
  if (object.reaction_type_) {
    jo("reaction_type", ToJson(*object.reaction_type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateDefaultPaidReactionType &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateDefaultPaidReactionType");
  if (object.type_) {
    jo("type", ToJson(*object.type_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateSavedMessagesTags &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateSavedMessagesTags");
  jo("saved_messages_topic_id", object.saved_messages_topic_id_);
  if (object.tags_) {
    jo("tags", ToJson(*object.tags_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateActiveLiveLocationMessages &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateActiveLiveLocationMessages");
  jo("messages", ToJson(object.messages_));
}

void to_json(JsonValueScope &jv, const td_api::updateOwnedStarCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateOwnedStarCount");
  if (object.star_amount_) {
    jo("star_amount", ToJson(*object.star_amount_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateOwnedTonCount &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateOwnedTonCount");
  jo("ton_amount", object.ton_amount_);
}

void to_json(JsonValueScope &jv, const td_api::updateChatRevenueAmount &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatRevenueAmount");
  jo("chat_id", object.chat_id_);
  if (object.revenue_amount_) {
    jo("revenue_amount", ToJson(*object.revenue_amount_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateStarRevenueStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateStarRevenueStatus");
  if (object.owner_id_) {
    jo("owner_id", ToJson(*object.owner_id_));
  }
  if (object.status_) {
    jo("status", ToJson(*object.status_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateTonRevenueStatus &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateTonRevenueStatus");
  if (object.status_) {
    jo("status", ToJson(*object.status_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateSpeechRecognitionTrial &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateSpeechRecognitionTrial");
  jo("max_media_duration", object.max_media_duration_);
  jo("weekly_count", object.weekly_count_);
  jo("left_count", object.left_count_);
  jo("next_reset_date", object.next_reset_date_);
}

void to_json(JsonValueScope &jv, const td_api::updateGroupCallMessageLevels &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateGroupCallMessageLevels");
  jo("levels", ToJson(object.levels_));
}

void to_json(JsonValueScope &jv, const td_api::updateDiceEmojis &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateDiceEmojis");
  jo("emojis", ToJson(object.emojis_));
}

void to_json(JsonValueScope &jv, const td_api::updateStakeDiceState &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateStakeDiceState");
  if (object.state_) {
    jo("state", ToJson(*object.state_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateAnimatedEmojiMessageClicked &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateAnimatedEmojiMessageClicked");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateAnimationSearchParameters &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateAnimationSearchParameters");
  jo("provider", object.provider_);
  jo("emojis", ToJson(object.emojis_));
}

void to_json(JsonValueScope &jv, const td_api::updateTextCompositionStyles &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateTextCompositionStyles");
  jo("styles", ToJson(object.styles_));
}

void to_json(JsonValueScope &jv, const td_api::updateSuggestedActions &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateSuggestedActions");
  jo("added_actions", ToJson(object.added_actions_));
  jo("removed_actions", ToJson(object.removed_actions_));
}

void to_json(JsonValueScope &jv, const td_api::updateSpeedLimitNotification &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateSpeedLimitNotification");
  jo("is_upload", JsonBool{object.is_upload_});
}

void to_json(JsonValueScope &jv, const td_api::updateContactCloseBirthdays &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateContactCloseBirthdays");
  jo("close_birthday_users", ToJson(object.close_birthday_users_));
}

void to_json(JsonValueScope &jv, const td_api::updateAutosaveSettings &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateAutosaveSettings");
  if (object.scope_) {
    jo("scope", ToJson(*object.scope_));
  }
  if (object.settings_) {
    jo("settings", ToJson(*object.settings_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateBusinessConnection &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateBusinessConnection");
  if (object.connection_) {
    jo("connection", ToJson(*object.connection_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNewBusinessMessage &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewBusinessMessage");
  jo("connection_id", object.connection_id_);
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateBusinessMessageEdited &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateBusinessMessageEdited");
  jo("connection_id", object.connection_id_);
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateBusinessMessagesDeleted &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateBusinessMessagesDeleted");
  jo("connection_id", object.connection_id_);
  jo("chat_id", object.chat_id_);
  jo("message_ids", ToJson(object.message_ids_));
}

void to_json(JsonValueScope &jv, const td_api::updateNewInlineQuery &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewInlineQuery");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("sender_user_id", object.sender_user_id_);
  if (object.user_location_) {
    jo("user_location", ToJson(*object.user_location_));
  }
  if (object.chat_type_) {
    jo("chat_type", ToJson(*object.chat_type_));
  }
  jo("query", object.query_);
  jo("offset", object.offset_);
}

void to_json(JsonValueScope &jv, const td_api::updateNewChosenInlineResult &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewChosenInlineResult");
  jo("sender_user_id", object.sender_user_id_);
  if (object.user_location_) {
    jo("user_location", ToJson(*object.user_location_));
  }
  jo("query", object.query_);
  jo("result_id", object.result_id_);
  jo("inline_message_id", object.inline_message_id_);
}

void to_json(JsonValueScope &jv, const td_api::updateNewCallbackQuery &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewCallbackQuery");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("sender_user_id", object.sender_user_id_);
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  jo("chat_instance", ToJson(JsonInt64{object.chat_instance_}));
  if (object.payload_) {
    jo("payload", ToJson(*object.payload_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNewInlineCallbackQuery &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewInlineCallbackQuery");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("sender_user_id", object.sender_user_id_);
  jo("inline_message_id", object.inline_message_id_);
  jo("chat_instance", ToJson(JsonInt64{object.chat_instance_}));
  if (object.payload_) {
    jo("payload", ToJson(*object.payload_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNewBusinessCallbackQuery &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewBusinessCallbackQuery");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("sender_user_id", object.sender_user_id_);
  jo("connection_id", object.connection_id_);
  if (object.message_) {
    jo("message", ToJson(*object.message_));
  }
  jo("chat_instance", ToJson(JsonInt64{object.chat_instance_}));
  if (object.payload_) {
    jo("payload", ToJson(*object.payload_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNewShippingQuery &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewShippingQuery");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("sender_user_id", object.sender_user_id_);
  jo("invoice_payload", object.invoice_payload_);
  if (object.shipping_address_) {
    jo("shipping_address", ToJson(*object.shipping_address_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNewPreCheckoutQuery &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewPreCheckoutQuery");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("sender_user_id", object.sender_user_id_);
  jo("currency", object.currency_);
  jo("total_amount", object.total_amount_);
  jo("invoice_payload", base64_encode(object.invoice_payload_));
  jo("shipping_option_id", object.shipping_option_id_);
  if (object.order_info_) {
    jo("order_info", ToJson(*object.order_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNewCustomEvent &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewCustomEvent");
  jo("event", object.event_);
}

void to_json(JsonValueScope &jv, const td_api::updateNewCustomQuery &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewCustomQuery");
  jo("id", ToJson(JsonInt64{object.id_}));
  jo("data", object.data_);
  jo("timeout", object.timeout_);
}

void to_json(JsonValueScope &jv, const td_api::updatePoll &object) {
  auto jo = jv.enter_object();
  jo("@type", "updatePoll");
  if (object.poll_) {
    jo("poll", ToJson(*object.poll_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updatePollAnswer &object) {
  auto jo = jv.enter_object();
  jo("@type", "updatePollAnswer");
  jo("poll_id", ToJson(JsonInt64{object.poll_id_}));
  if (object.voter_id_) {
    jo("voter_id", ToJson(*object.voter_id_));
  }
  jo("option_ids", ToJson(object.option_ids_));
  jo("option_positions", ToJson(object.option_positions_));
}

void to_json(JsonValueScope &jv, const td_api::updateManagedBot &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateManagedBot");
  jo("user_id", object.user_id_);
  jo("bot_user_id", object.bot_user_id_);
}

void to_json(JsonValueScope &jv, const td_api::updateChatMember &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatMember");
  jo("chat_id", object.chat_id_);
  jo("actor_user_id", object.actor_user_id_);
  jo("date", object.date_);
  if (object.invite_link_) {
    jo("invite_link", ToJson(*object.invite_link_));
  }
  jo("via_join_request", JsonBool{object.via_join_request_});
  jo("via_chat_folder_invite_link", JsonBool{object.via_chat_folder_invite_link_});
  if (object.old_chat_member_) {
    jo("old_chat_member", ToJson(*object.old_chat_member_));
  }
  if (object.new_chat_member_) {
    jo("new_chat_member", ToJson(*object.new_chat_member_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateNewChatJoinRequest &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateNewChatJoinRequest");
  jo("chat_id", object.chat_id_);
  if (object.request_) {
    jo("request", ToJson(*object.request_));
  }
  jo("user_chat_id", object.user_chat_id_);
  if (object.invite_link_) {
    jo("invite_link", ToJson(*object.invite_link_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateChatBoost &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateChatBoost");
  jo("chat_id", object.chat_id_);
  if (object.boost_) {
    jo("boost", ToJson(*object.boost_));
  }
}

void to_json(JsonValueScope &jv, const td_api::updateMessageReaction &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageReaction");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  if (object.actor_id_) {
    jo("actor_id", ToJson(*object.actor_id_));
  }
  jo("date", object.date_);
  jo("old_reaction_types", ToJson(object.old_reaction_types_));
  jo("new_reaction_types", ToJson(object.new_reaction_types_));
}

void to_json(JsonValueScope &jv, const td_api::updateMessageReactions &object) {
  auto jo = jv.enter_object();
  jo("@type", "updateMessageReactions");
  jo("chat_id", object.chat_id_);
  jo("message_id", object.message_id_);
  jo("date", object.date_);
  jo("reactions", ToJson(object.reactions_));
}

void to_json(JsonValueScope &jv, const td_api::updatePaidMediaPurchased &object) {
  auto jo = jv.enter_object();
  jo("@type", "updatePaidMediaPurchased");
  jo("user_id", object.user_id_);
  jo("payload", object.payload_);
}

void to_json(JsonValueScope &jv, const td_api::upgradedGiftModel &object) {
  auto jo = jv.enter_object();
  jo("@type", "upgradedGiftModel");
  jo("name", object.name_);
  if (object.sticker_) {
    jo("sticker", ToJson(*object.sticker_));
  }
  if (object.rarity_) {
    jo("rarity", ToJson(*object.rarity_));
  }
  jo("is_crafted", JsonBool{object.is_crafted_});
}

void to_json(JsonValueScope &jv, const td_api::userFullInfo &object) {
  auto jo = jv.enter_object();
  jo("@type", "userFullInfo");
  if (object.personal_photo_) {
    jo("personal_photo", ToJson(*object.personal_photo_));
  }
  if (object.photo_) {
    jo("photo", ToJson(*object.photo_));
  }
  if (object.public_photo_) {
    jo("public_photo", ToJson(*object.public_photo_));
  }
  if (object.block_list_) {
    jo("block_list", ToJson(*object.block_list_));
  }
  jo("can_be_called", JsonBool{object.can_be_called_});
  jo("supports_video_calls", JsonBool{object.supports_video_calls_});
  jo("has_private_calls", JsonBool{object.has_private_calls_});
  jo("has_private_forwards", JsonBool{object.has_private_forwards_});
  jo("has_restricted_voice_and_video_note_messages", JsonBool{object.has_restricted_voice_and_video_note_messages_});
  jo("has_posted_to_profile_stories", JsonBool{object.has_posted_to_profile_stories_});
  jo("has_sponsored_messages_enabled", JsonBool{object.has_sponsored_messages_enabled_});
  jo("need_phone_number_privacy_exception", JsonBool{object.need_phone_number_privacy_exception_});
  jo("set_chat_background", JsonBool{object.set_chat_background_});
  jo("uses_unofficial_app", JsonBool{object.uses_unofficial_app_});
  if (object.bio_) {
    jo("bio", ToJson(*object.bio_));
  }
  if (object.birthdate_) {
    jo("birthdate", ToJson(*object.birthdate_));
  }
  jo("personal_chat_id", object.personal_chat_id_);
  jo("gift_count", object.gift_count_);
  jo("group_in_common_count", object.group_in_common_count_);
  jo("incoming_paid_message_star_count", object.incoming_paid_message_star_count_);
  jo("outgoing_paid_message_star_count", object.outgoing_paid_message_star_count_);
  if (object.gift_settings_) {
    jo("gift_settings", ToJson(*object.gift_settings_));
  }
  if (object.bot_verification_) {
    jo("bot_verification", ToJson(*object.bot_verification_));
  }
  if (object.main_profile_tab_) {
    jo("main_profile_tab", ToJson(*object.main_profile_tab_));
  }
  if (object.first_profile_audio_) {
    jo("first_profile_audio", ToJson(*object.first_profile_audio_));
  }
  if (object.rating_) {
    jo("rating", ToJson(*object.rating_));
  }
  if (object.pending_rating_) {
    jo("pending_rating", ToJson(*object.pending_rating_));
  }
  jo("pending_rating_date", object.pending_rating_date_);
  if (object.note_) {
    jo("note", ToJson(*object.note_));
  }
  if (object.business_info_) {
    jo("business_info", ToJson(*object.business_info_));
  }
  if (object.bot_info_) {
    jo("bot_info", ToJson(*object.bot_info_));
  }
}

void to_json(JsonValueScope &jv, const td_api::usernames &object) {
  auto jo = jv.enter_object();
  jo("@type", "usernames");
  jo("active_usernames", ToJson(object.active_usernames_));
  jo("disabled_usernames", ToJson(object.disabled_usernames_));
  jo("editable_username", object.editable_username_);
  jo("collectible_usernames", ToJson(object.collectible_usernames_));
}

void to_json(JsonValueScope &jv, const td_api::videoMessageAdvertisements &object) {
  auto jo = jv.enter_object();
  jo("@type", "videoMessageAdvertisements");
  jo("advertisements", ToJson(object.advertisements_));
  jo("start_delay", object.start_delay_);
  jo("between_delay", object.between_delay_);
}

}  // namespace td_api
}  // namespace td
