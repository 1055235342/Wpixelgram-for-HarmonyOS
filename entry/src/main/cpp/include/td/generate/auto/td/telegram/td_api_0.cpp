#include "td_api.h"

#include "td/utils/common.h"
#include "td/utils/format.h"
#include "td/utils/logging.h"
#include "td/utils/SliceBuilder.h"
#include "td/utils/tl_parsers.h"
#include "td/utils/tl_storers.h"
#include "td/utils/TlStorerToString.h"

namespace td {
namespace td_api {

std::string to_string(const BaseObject &value) {
  TlStorerToString storer;
  value.store(storer, "");
  return storer.move_as_string();
}

accountTtl::accountTtl()
  : days_()
{}

accountTtl::accountTtl(int32 days_)
  : days_(days_)
{}

const std::int32_t accountTtl::ID;

void accountTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "accountTtl");
    s.store_field("days", days_);
    s.store_class_end();
  }
}

attachmentMenuBotColor::attachmentMenuBotColor()
  : light_color_()
  , dark_color_()
{}

attachmentMenuBotColor::attachmentMenuBotColor(int32 light_color_, int32 dark_color_)
  : light_color_(light_color_)
  , dark_color_(dark_color_)
{}

const std::int32_t attachmentMenuBotColor::ID;

void attachmentMenuBotColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachmentMenuBotColor");
    s.store_field("light_color", light_color_);
    s.store_field("dark_color", dark_color_);
    s.store_class_end();
  }
}

authenticationCodeInfo::authenticationCodeInfo()
  : phone_number_()
  , type_()
  , next_type_()
  , timeout_()
{}

authenticationCodeInfo::authenticationCodeInfo(string const &phone_number_, object_ptr<AuthenticationCodeType> &&type_, object_ptr<AuthenticationCodeType> &&next_type_, int32 timeout_)
  : phone_number_(phone_number_)
  , type_(std::move(type_))
  , next_type_(std::move(next_type_))
  , timeout_(timeout_)
{}

const std::int32_t authenticationCodeInfo::ID;

void authenticationCodeInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeInfo");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("next_type", static_cast<const BaseObject *>(next_type_.get()));
    s.store_field("timeout", timeout_);
    s.store_class_end();
  }
}

availableGift::availableGift()
  : gift_()
  , resale_count_()
  , min_resale_star_count_()
  , title_()
{}

availableGift::availableGift(object_ptr<gift> &&gift_, int32 resale_count_, int53 min_resale_star_count_, string const &title_)
  : gift_(std::move(gift_))
  , resale_count_(resale_count_)
  , min_resale_star_count_(min_resale_star_count_)
  , title_(title_)
{}

const std::int32_t availableGift::ID;

void availableGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("resale_count", resale_count_);
    s.store_field("min_resale_star_count", min_resale_star_count_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

botVerification::botVerification()
  : bot_user_id_()
  , icon_custom_emoji_id_()
  , custom_description_()
{}

botVerification::botVerification(int53 bot_user_id_, int64 icon_custom_emoji_id_, object_ptr<formattedText> &&custom_description_)
  : bot_user_id_(bot_user_id_)
  , icon_custom_emoji_id_(icon_custom_emoji_id_)
  , custom_description_(std::move(custom_description_))
{}

const std::int32_t botVerification::ID;

void botVerification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botVerification");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_object_field("custom_description", static_cast<const BaseObject *>(custom_description_.get()));
    s.store_class_end();
  }
}

businessChatLinkInfo::businessChatLinkInfo()
  : chat_id_()
  , text_()
{}

businessChatLinkInfo::businessChatLinkInfo(int53 chat_id_, object_ptr<formattedText> &&text_)
  : chat_id_(chat_id_)
  , text_(std::move(text_))
{}

const std::int32_t businessChatLinkInfo::ID;

void businessChatLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessChatLinkInfo");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

businessOpeningHoursInterval::businessOpeningHoursInterval()
  : start_minute_()
  , end_minute_()
{}

businessOpeningHoursInterval::businessOpeningHoursInterval(int32 start_minute_, int32 end_minute_)
  : start_minute_(start_minute_)
  , end_minute_(end_minute_)
{}

const std::int32_t businessOpeningHoursInterval::ID;

void businessOpeningHoursInterval::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessOpeningHoursInterval");
    s.store_field("start_minute", start_minute_);
    s.store_field("end_minute", end_minute_);
    s.store_class_end();
  }
}

callbackQueryAnswer::callbackQueryAnswer()
  : text_()
  , show_alert_()
  , url_()
{}

callbackQueryAnswer::callbackQueryAnswer(string const &text_, bool show_alert_, string const &url_)
  : text_(text_)
  , show_alert_(show_alert_)
  , url_(url_)
{}

const std::int32_t callbackQueryAnswer::ID;

void callbackQueryAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callbackQueryAnswer");
    s.store_field("text", text_);
    s.store_field("show_alert", show_alert_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

canPostStoryResultOk::canPostStoryResultOk()
  : story_count_()
{}

canPostStoryResultOk::canPostStoryResultOk(int32 story_count_)
  : story_count_(story_count_)
{}

const std::int32_t canPostStoryResultOk::ID;

void canPostStoryResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultOk");
    s.store_field("story_count", story_count_);
    s.store_class_end();
  }
}

canPostStoryResultPremiumNeeded::canPostStoryResultPremiumNeeded() {
}

const std::int32_t canPostStoryResultPremiumNeeded::ID;

void canPostStoryResultPremiumNeeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultPremiumNeeded");
    s.store_class_end();
  }
}

canPostStoryResultBoostNeeded::canPostStoryResultBoostNeeded() {
}

const std::int32_t canPostStoryResultBoostNeeded::ID;

void canPostStoryResultBoostNeeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultBoostNeeded");
    s.store_class_end();
  }
}

canPostStoryResultActiveStoryLimitExceeded::canPostStoryResultActiveStoryLimitExceeded() {
}

const std::int32_t canPostStoryResultActiveStoryLimitExceeded::ID;

void canPostStoryResultActiveStoryLimitExceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultActiveStoryLimitExceeded");
    s.store_class_end();
  }
}

canPostStoryResultWeeklyLimitExceeded::canPostStoryResultWeeklyLimitExceeded()
  : retry_after_()
{}

canPostStoryResultWeeklyLimitExceeded::canPostStoryResultWeeklyLimitExceeded(int32 retry_after_)
  : retry_after_(retry_after_)
{}

const std::int32_t canPostStoryResultWeeklyLimitExceeded::ID;

void canPostStoryResultWeeklyLimitExceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultWeeklyLimitExceeded");
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

canPostStoryResultMonthlyLimitExceeded::canPostStoryResultMonthlyLimitExceeded()
  : retry_after_()
{}

canPostStoryResultMonthlyLimitExceeded::canPostStoryResultMonthlyLimitExceeded(int32 retry_after_)
  : retry_after_(retry_after_)
{}

const std::int32_t canPostStoryResultMonthlyLimitExceeded::ID;

void canPostStoryResultMonthlyLimitExceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultMonthlyLimitExceeded");
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

canPostStoryResultLiveStoryIsActive::canPostStoryResultLiveStoryIsActive()
  : story_id_()
{}

canPostStoryResultLiveStoryIsActive::canPostStoryResultLiveStoryIsActive(int32 story_id_)
  : story_id_(story_id_)
{}

const std::int32_t canPostStoryResultLiveStoryIsActive::ID;

void canPostStoryResultLiveStoryIsActive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStoryResultLiveStoryIsActive");
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

chatActionTyping::chatActionTyping() {
}

const std::int32_t chatActionTyping::ID;

void chatActionTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionTyping");
    s.store_class_end();
  }
}

chatActionRecordingVideo::chatActionRecordingVideo() {
}

const std::int32_t chatActionRecordingVideo::ID;

void chatActionRecordingVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionRecordingVideo");
    s.store_class_end();
  }
}

chatActionUploadingVideo::chatActionUploadingVideo()
  : progress_()
{}

chatActionUploadingVideo::chatActionUploadingVideo(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingVideo::ID;

void chatActionUploadingVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingVideo");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionRecordingVoiceNote::chatActionRecordingVoiceNote() {
}

const std::int32_t chatActionRecordingVoiceNote::ID;

void chatActionRecordingVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionRecordingVoiceNote");
    s.store_class_end();
  }
}

chatActionUploadingVoiceNote::chatActionUploadingVoiceNote()
  : progress_()
{}

chatActionUploadingVoiceNote::chatActionUploadingVoiceNote(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingVoiceNote::ID;

void chatActionUploadingVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingVoiceNote");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionUploadingPhoto::chatActionUploadingPhoto()
  : progress_()
{}

chatActionUploadingPhoto::chatActionUploadingPhoto(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingPhoto::ID;

void chatActionUploadingPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingPhoto");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionUploadingDocument::chatActionUploadingDocument()
  : progress_()
{}

chatActionUploadingDocument::chatActionUploadingDocument(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingDocument::ID;

void chatActionUploadingDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingDocument");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionChoosingSticker::chatActionChoosingSticker() {
}

const std::int32_t chatActionChoosingSticker::ID;

void chatActionChoosingSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionChoosingSticker");
    s.store_class_end();
  }
}

chatActionChoosingLocation::chatActionChoosingLocation() {
}

const std::int32_t chatActionChoosingLocation::ID;

void chatActionChoosingLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionChoosingLocation");
    s.store_class_end();
  }
}

chatActionChoosingContact::chatActionChoosingContact() {
}

const std::int32_t chatActionChoosingContact::ID;

void chatActionChoosingContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionChoosingContact");
    s.store_class_end();
  }
}

chatActionStartPlayingGame::chatActionStartPlayingGame() {
}

const std::int32_t chatActionStartPlayingGame::ID;

void chatActionStartPlayingGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionStartPlayingGame");
    s.store_class_end();
  }
}

chatActionRecordingVideoNote::chatActionRecordingVideoNote() {
}

const std::int32_t chatActionRecordingVideoNote::ID;

void chatActionRecordingVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionRecordingVideoNote");
    s.store_class_end();
  }
}

chatActionUploadingVideoNote::chatActionUploadingVideoNote()
  : progress_()
{}

chatActionUploadingVideoNote::chatActionUploadingVideoNote(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t chatActionUploadingVideoNote::ID;

void chatActionUploadingVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionUploadingVideoNote");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

chatActionWatchingAnimations::chatActionWatchingAnimations()
  : emoji_()
{}

chatActionWatchingAnimations::chatActionWatchingAnimations(string const &emoji_)
  : emoji_(emoji_)
{}

const std::int32_t chatActionWatchingAnimations::ID;

void chatActionWatchingAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionWatchingAnimations");
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

chatActionCancel::chatActionCancel() {
}

const std::int32_t chatActionCancel::ID;

void chatActionCancel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatActionCancel");
    s.store_class_end();
  }
}

chatBoostFeatures::chatBoostFeatures()
  : features_()
  , min_profile_background_custom_emoji_boost_level_()
  , min_background_custom_emoji_boost_level_()
  , min_emoji_status_boost_level_()
  , min_chat_theme_background_boost_level_()
  , min_custom_background_boost_level_()
  , min_custom_emoji_sticker_set_boost_level_()
  , min_automatic_translation_boost_level_()
  , min_speech_recognition_boost_level_()
  , min_sponsored_message_disable_boost_level_()
{}

chatBoostFeatures::chatBoostFeatures(array<object_ptr<chatBoostLevelFeatures>> &&features_, int32 min_profile_background_custom_emoji_boost_level_, int32 min_background_custom_emoji_boost_level_, int32 min_emoji_status_boost_level_, int32 min_chat_theme_background_boost_level_, int32 min_custom_background_boost_level_, int32 min_custom_emoji_sticker_set_boost_level_, int32 min_automatic_translation_boost_level_, int32 min_speech_recognition_boost_level_, int32 min_sponsored_message_disable_boost_level_)
  : features_(std::move(features_))
  , min_profile_background_custom_emoji_boost_level_(min_profile_background_custom_emoji_boost_level_)
  , min_background_custom_emoji_boost_level_(min_background_custom_emoji_boost_level_)
  , min_emoji_status_boost_level_(min_emoji_status_boost_level_)
  , min_chat_theme_background_boost_level_(min_chat_theme_background_boost_level_)
  , min_custom_background_boost_level_(min_custom_background_boost_level_)
  , min_custom_emoji_sticker_set_boost_level_(min_custom_emoji_sticker_set_boost_level_)
  , min_automatic_translation_boost_level_(min_automatic_translation_boost_level_)
  , min_speech_recognition_boost_level_(min_speech_recognition_boost_level_)
  , min_sponsored_message_disable_boost_level_(min_sponsored_message_disable_boost_level_)
{}

const std::int32_t chatBoostFeatures::ID;

void chatBoostFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostFeatures");
    { s.store_vector_begin("features", features_.size()); for (const auto &_value : features_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("min_profile_background_custom_emoji_boost_level", min_profile_background_custom_emoji_boost_level_);
    s.store_field("min_background_custom_emoji_boost_level", min_background_custom_emoji_boost_level_);
    s.store_field("min_emoji_status_boost_level", min_emoji_status_boost_level_);
    s.store_field("min_chat_theme_background_boost_level", min_chat_theme_background_boost_level_);
    s.store_field("min_custom_background_boost_level", min_custom_background_boost_level_);
    s.store_field("min_custom_emoji_sticker_set_boost_level", min_custom_emoji_sticker_set_boost_level_);
    s.store_field("min_automatic_translation_boost_level", min_automatic_translation_boost_level_);
    s.store_field("min_speech_recognition_boost_level", min_speech_recognition_boost_level_);
    s.store_field("min_sponsored_message_disable_boost_level", min_sponsored_message_disable_boost_level_);
    s.store_class_end();
  }
}

chatBoostStatus::chatBoostStatus()
  : boost_url_()
  , applied_slot_ids_()
  , level_()
  , gift_code_boost_count_()
  , boost_count_()
  , current_level_boost_count_()
  , next_level_boost_count_()
  , premium_member_count_()
  , premium_member_percentage_()
  , prepaid_giveaways_()
{}

chatBoostStatus::chatBoostStatus(string const &boost_url_, array<int32> &&applied_slot_ids_, int32 level_, int32 gift_code_boost_count_, int32 boost_count_, int32 current_level_boost_count_, int32 next_level_boost_count_, int32 premium_member_count_, double premium_member_percentage_, array<object_ptr<prepaidGiveaway>> &&prepaid_giveaways_)
  : boost_url_(boost_url_)
  , applied_slot_ids_(std::move(applied_slot_ids_))
  , level_(level_)
  , gift_code_boost_count_(gift_code_boost_count_)
  , boost_count_(boost_count_)
  , current_level_boost_count_(current_level_boost_count_)
  , next_level_boost_count_(next_level_boost_count_)
  , premium_member_count_(premium_member_count_)
  , premium_member_percentage_(premium_member_percentage_)
  , prepaid_giveaways_(std::move(prepaid_giveaways_))
{}

const std::int32_t chatBoostStatus::ID;

void chatBoostStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostStatus");
    s.store_field("boost_url", boost_url_);
    { s.store_vector_begin("applied_slot_ids", applied_slot_ids_.size()); for (const auto &_value : applied_slot_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("level", level_);
    s.store_field("gift_code_boost_count", gift_code_boost_count_);
    s.store_field("boost_count", boost_count_);
    s.store_field("current_level_boost_count", current_level_boost_count_);
    s.store_field("next_level_boost_count", next_level_boost_count_);
    s.store_field("premium_member_count", premium_member_count_);
    s.store_field("premium_member_percentage", premium_member_percentage_);
    { s.store_vector_begin("prepaid_giveaways", prepaid_giveaways_.size()); for (const auto &_value : prepaid_giveaways_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatFolder::chatFolder()
  : name_()
  , icon_()
  , color_id_()
  , is_shareable_()
  , pinned_chat_ids_()
  , included_chat_ids_()
  , excluded_chat_ids_()
  , exclude_muted_()
  , exclude_read_()
  , exclude_archived_()
  , include_contacts_()
  , include_non_contacts_()
  , include_bots_()
  , include_groups_()
  , include_channels_()
{}

chatFolder::chatFolder(object_ptr<chatFolderName> &&name_, object_ptr<chatFolderIcon> &&icon_, int32 color_id_, bool is_shareable_, array<int53> &&pinned_chat_ids_, array<int53> &&included_chat_ids_, array<int53> &&excluded_chat_ids_, bool exclude_muted_, bool exclude_read_, bool exclude_archived_, bool include_contacts_, bool include_non_contacts_, bool include_bots_, bool include_groups_, bool include_channels_)
  : name_(std::move(name_))
  , icon_(std::move(icon_))
  , color_id_(color_id_)
  , is_shareable_(is_shareable_)
  , pinned_chat_ids_(std::move(pinned_chat_ids_))
  , included_chat_ids_(std::move(included_chat_ids_))
  , excluded_chat_ids_(std::move(excluded_chat_ids_))
  , exclude_muted_(exclude_muted_)
  , exclude_read_(exclude_read_)
  , exclude_archived_(exclude_archived_)
  , include_contacts_(include_contacts_)
  , include_non_contacts_(include_non_contacts_)
  , include_bots_(include_bots_)
  , include_groups_(include_groups_)
  , include_channels_(include_channels_)
{}

const std::int32_t chatFolder::ID;

void chatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolder");
    s.store_object_field("name", static_cast<const BaseObject *>(name_.get()));
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_field("color_id", color_id_);
    s.store_field("is_shareable", is_shareable_);
    { s.store_vector_begin("pinned_chat_ids", pinned_chat_ids_.size()); for (const auto &_value : pinned_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("included_chat_ids", included_chat_ids_.size()); for (const auto &_value : included_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("excluded_chat_ids", excluded_chat_ids_.size()); for (const auto &_value : excluded_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("exclude_muted", exclude_muted_);
    s.store_field("exclude_read", exclude_read_);
    s.store_field("exclude_archived", exclude_archived_);
    s.store_field("include_contacts", include_contacts_);
    s.store_field("include_non_contacts", include_non_contacts_);
    s.store_field("include_bots", include_bots_);
    s.store_field("include_groups", include_groups_);
    s.store_field("include_channels", include_channels_);
    s.store_class_end();
  }
}

chatInviteLinkCounts::chatInviteLinkCounts()
  : invite_link_counts_()
{}

chatInviteLinkCounts::chatInviteLinkCounts(array<object_ptr<chatInviteLinkCount>> &&invite_link_counts_)
  : invite_link_counts_(std::move(invite_link_counts_))
{}

const std::int32_t chatInviteLinkCounts::ID;

void chatInviteLinkCounts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkCounts");
    { s.store_vector_begin("invite_link_counts", invite_link_counts_.size()); for (const auto &_value : invite_link_counts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatPermissions::chatPermissions()
  : can_send_basic_messages_()
  , can_send_audios_()
  , can_send_documents_()
  , can_send_photos_()
  , can_send_videos_()
  , can_send_video_notes_()
  , can_send_voice_notes_()
  , can_send_polls_()
  , can_send_other_messages_()
  , can_add_link_previews_()
  , can_edit_tag_()
  , can_change_info_()
  , can_invite_users_()
  , can_pin_messages_()
  , can_create_topics_()
{}

chatPermissions::chatPermissions(bool can_send_basic_messages_, bool can_send_audios_, bool can_send_documents_, bool can_send_photos_, bool can_send_videos_, bool can_send_video_notes_, bool can_send_voice_notes_, bool can_send_polls_, bool can_send_other_messages_, bool can_add_link_previews_, bool can_edit_tag_, bool can_change_info_, bool can_invite_users_, bool can_pin_messages_, bool can_create_topics_)
  : can_send_basic_messages_(can_send_basic_messages_)
  , can_send_audios_(can_send_audios_)
  , can_send_documents_(can_send_documents_)
  , can_send_photos_(can_send_photos_)
  , can_send_videos_(can_send_videos_)
  , can_send_video_notes_(can_send_video_notes_)
  , can_send_voice_notes_(can_send_voice_notes_)
  , can_send_polls_(can_send_polls_)
  , can_send_other_messages_(can_send_other_messages_)
  , can_add_link_previews_(can_add_link_previews_)
  , can_edit_tag_(can_edit_tag_)
  , can_change_info_(can_change_info_)
  , can_invite_users_(can_invite_users_)
  , can_pin_messages_(can_pin_messages_)
  , can_create_topics_(can_create_topics_)
{}

const std::int32_t chatPermissions::ID;

void chatPermissions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPermissions");
    s.store_field("can_send_basic_messages", can_send_basic_messages_);
    s.store_field("can_send_audios", can_send_audios_);
    s.store_field("can_send_documents", can_send_documents_);
    s.store_field("can_send_photos", can_send_photos_);
    s.store_field("can_send_videos", can_send_videos_);
    s.store_field("can_send_video_notes", can_send_video_notes_);
    s.store_field("can_send_voice_notes", can_send_voice_notes_);
    s.store_field("can_send_polls", can_send_polls_);
    s.store_field("can_send_other_messages", can_send_other_messages_);
    s.store_field("can_add_link_previews", can_add_link_previews_);
    s.store_field("can_edit_tag", can_edit_tag_);
    s.store_field("can_change_info", can_change_info_);
    s.store_field("can_invite_users", can_invite_users_);
    s.store_field("can_pin_messages", can_pin_messages_);
    s.store_field("can_create_topics", can_create_topics_);
    s.store_class_end();
  }
}

chatPhoto::chatPhoto()
  : id_()
  , added_date_()
  , minithumbnail_()
  , sizes_()
  , animation_()
  , small_animation_()
  , sticker_()
{}

chatPhoto::chatPhoto(int64 id_, int32 added_date_, object_ptr<minithumbnail> &&minithumbnail_, array<object_ptr<photoSize>> &&sizes_, object_ptr<animatedChatPhoto> &&animation_, object_ptr<animatedChatPhoto> &&small_animation_, object_ptr<chatPhotoSticker> &&sticker_)
  : id_(id_)
  , added_date_(added_date_)
  , minithumbnail_(std::move(minithumbnail_))
  , sizes_(std::move(sizes_))
  , animation_(std::move(animation_))
  , small_animation_(std::move(small_animation_))
  , sticker_(std::move(sticker_))
{}

const std::int32_t chatPhoto::ID;

void chatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhoto");
    s.store_field("id", id_);
    s.store_field("added_date", added_date_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    { s.store_vector_begin("sizes", sizes_.size()); for (const auto &_value : sizes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("small_animation", static_cast<const BaseObject *>(small_animation_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

chatRevenueAmount::chatRevenueAmount()
  : cryptocurrency_()
  , total_amount_()
  , balance_amount_()
  , available_amount_()
  , withdrawal_enabled_()
{}

chatRevenueAmount::chatRevenueAmount(string const &cryptocurrency_, int64 total_amount_, int64 balance_amount_, int64 available_amount_, bool withdrawal_enabled_)
  : cryptocurrency_(cryptocurrency_)
  , total_amount_(total_amount_)
  , balance_amount_(balance_amount_)
  , available_amount_(available_amount_)
  , withdrawal_enabled_(withdrawal_enabled_)
{}

const std::int32_t chatRevenueAmount::ID;

void chatRevenueAmount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueAmount");
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("balance_amount", balance_amount_);
    s.store_field("available_amount", available_amount_);
    s.store_field("withdrawal_enabled", withdrawal_enabled_);
    s.store_class_end();
  }
}

chatStatisticsMessageSenderInfo::chatStatisticsMessageSenderInfo()
  : user_id_()
  , sent_message_count_()
  , average_character_count_()
{}

chatStatisticsMessageSenderInfo::chatStatisticsMessageSenderInfo(int53 user_id_, int32 sent_message_count_, int32 average_character_count_)
  : user_id_(user_id_)
  , sent_message_count_(sent_message_count_)
  , average_character_count_(average_character_count_)
{}

const std::int32_t chatStatisticsMessageSenderInfo::ID;

void chatStatisticsMessageSenderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsMessageSenderInfo");
    s.store_field("user_id", user_id_);
    s.store_field("sent_message_count", sent_message_count_);
    s.store_field("average_character_count", average_character_count_);
    s.store_class_end();
  }
}

chatThemeEmoji::chatThemeEmoji()
  : name_()
{}

chatThemeEmoji::chatThemeEmoji(string const &name_)
  : name_(name_)
{}

const std::int32_t chatThemeEmoji::ID;

void chatThemeEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatThemeEmoji");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

chatThemeGift::chatThemeGift()
  : gift_theme_()
{}

chatThemeGift::chatThemeGift(object_ptr<giftChatTheme> &&gift_theme_)
  : gift_theme_(std::move(gift_theme_))
{}

const std::int32_t chatThemeGift::ID;

void chatThemeGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatThemeGift");
    s.store_object_field("gift_theme", static_cast<const BaseObject *>(gift_theme_.get()));
    s.store_class_end();
  }
}

emojiKeywords::emojiKeywords()
  : emoji_keywords_()
{}

emojiKeywords::emojiKeywords(array<object_ptr<emojiKeyword>> &&emoji_keywords_)
  : emoji_keywords_(std::move(emoji_keywords_))
{}

const std::int32_t emojiKeywords::ID;

void emojiKeywords::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiKeywords");
    { s.store_vector_begin("emoji_keywords", emoji_keywords_.size()); for (const auto &_value : emoji_keywords_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

emojis::emojis()
  : emojis_()
{}

emojis::emojis(array<string> &&emojis_)
  : emojis_(std::move(emojis_))
{}

const std::int32_t emojis::ID;

void emojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojis");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

error::error()
  : code_()
  , message_()
{}

error::error(int32 code_, string const &message_)
  : code_(code_)
  , message_(message_)
{}

const std::int32_t error::ID;

void error::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "error");
    s.store_field("code", code_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

fileDownload::fileDownload()
  : file_id_()
  , message_()
  , add_date_()
  , complete_date_()
  , is_paused_()
{}

fileDownload::fileDownload(int32 file_id_, object_ptr<message> &&message_, int32 add_date_, int32 complete_date_, bool is_paused_)
  : file_id_(file_id_)
  , message_(std::move(message_))
  , add_date_(add_date_)
  , complete_date_(complete_date_)
  , is_paused_(is_paused_)
{}

const std::int32_t fileDownload::ID;

void fileDownload::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileDownload");
    s.store_field("file_id", file_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("add_date", add_date_);
    s.store_field("complete_date", complete_date_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

fileDownloadedPrefixSize::fileDownloadedPrefixSize()
  : size_()
{}

fileDownloadedPrefixSize::fileDownloadedPrefixSize(int53 size_)
  : size_(size_)
{}

const std::int32_t fileDownloadedPrefixSize::ID;

void fileDownloadedPrefixSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileDownloadedPrefixSize");
    s.store_field("size", size_);
    s.store_class_end();
  }
}

giftAuction::giftAuction()
  : id_()
  , gifts_per_round_()
  , start_date_()
{}

giftAuction::giftAuction(string const &id_, int32 gifts_per_round_, int32 start_date_)
  : id_(id_)
  , gifts_per_round_(gifts_per_round_)
  , start_date_(start_date_)
{}

const std::int32_t giftAuction::ID;

void giftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftAuction");
    s.store_field("id", id_);
    s.store_field("gifts_per_round", gifts_per_round_);
    s.store_field("start_date", start_date_);
    s.store_class_end();
  }
}

giftBackground::giftBackground()
  : center_color_()
  , edge_color_()
  , text_color_()
{}

giftBackground::giftBackground(int32 center_color_, int32 edge_color_, int32 text_color_)
  : center_color_(center_color_)
  , edge_color_(edge_color_)
  , text_color_(text_color_)
{}

const std::int32_t giftBackground::ID;

void giftBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftBackground");
    s.store_field("center_color", center_color_);
    s.store_field("edge_color", edge_color_);
    s.store_field("text_color", text_color_);
    s.store_class_end();
  }
}

giftResaleResultOk::giftResaleResultOk()
  : received_gift_id_()
{}

giftResaleResultOk::giftResaleResultOk(string const &received_gift_id_)
  : received_gift_id_(received_gift_id_)
{}

const std::int32_t giftResaleResultOk::ID;

void giftResaleResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftResaleResultOk");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

giftResaleResultPriceIncreased::giftResaleResultPriceIncreased()
  : price_()
{}

giftResaleResultPriceIncreased::giftResaleResultPriceIncreased(object_ptr<GiftResalePrice> &&price_)
  : price_(std::move(price_))
{}

const std::int32_t giftResaleResultPriceIncreased::ID;

void giftResaleResultPriceIncreased::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftResaleResultPriceIncreased");
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

giftSettings::giftSettings()
  : show_gift_button_()
  , accepted_gift_types_()
{}

giftSettings::giftSettings(bool show_gift_button_, object_ptr<acceptedGiftTypes> &&accepted_gift_types_)
  : show_gift_button_(show_gift_button_)
  , accepted_gift_types_(std::move(accepted_gift_types_))
{}

const std::int32_t giftSettings::ID;

void giftSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftSettings");
    s.store_field("show_gift_button", show_gift_button_);
    s.store_object_field("accepted_gift_types", static_cast<const BaseObject *>(accepted_gift_types_.get()));
    s.store_class_end();
  }
}

giftUpgradePrice::giftUpgradePrice()
  : date_()
  , star_count_()
{}

giftUpgradePrice::giftUpgradePrice(int32 date_, int53 star_count_)
  : date_(date_)
  , star_count_(star_count_)
{}

const std::int32_t giftUpgradePrice::ID;

void giftUpgradePrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftUpgradePrice");
    s.store_field("date", date_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

giveawayParameters::giveawayParameters()
  : boosted_chat_id_()
  , additional_chat_ids_()
  , winners_selection_date_()
  , only_new_members_()
  , has_public_winners_()
  , country_codes_()
  , prize_description_()
{}

giveawayParameters::giveawayParameters(int53 boosted_chat_id_, array<int53> &&additional_chat_ids_, int32 winners_selection_date_, bool only_new_members_, bool has_public_winners_, array<string> &&country_codes_, string const &prize_description_)
  : boosted_chat_id_(boosted_chat_id_)
  , additional_chat_ids_(std::move(additional_chat_ids_))
  , winners_selection_date_(winners_selection_date_)
  , only_new_members_(only_new_members_)
  , has_public_winners_(has_public_winners_)
  , country_codes_(std::move(country_codes_))
  , prize_description_(prize_description_)
{}

const std::int32_t giveawayParameters::ID;

void giveawayParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayParameters");
    s.store_field("boosted_chat_id", boosted_chat_id_);
    { s.store_vector_begin("additional_chat_ids", additional_chat_ids_.size()); for (const auto &_value : additional_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("winners_selection_date", winners_selection_date_);
    s.store_field("only_new_members", only_new_members_);
    s.store_field("has_public_winners", has_public_winners_);
    { s.store_vector_begin("country_codes", country_codes_.size()); for (const auto &_value : country_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("prize_description", prize_description_);
    s.store_class_end();
  }
}

giveawayParticipantStatusEligible::giveawayParticipantStatusEligible() {
}

const std::int32_t giveawayParticipantStatusEligible::ID;

void giveawayParticipantStatusEligible::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayParticipantStatusEligible");
    s.store_class_end();
  }
}

giveawayParticipantStatusParticipating::giveawayParticipantStatusParticipating() {
}

const std::int32_t giveawayParticipantStatusParticipating::ID;

void giveawayParticipantStatusParticipating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayParticipantStatusParticipating");
    s.store_class_end();
  }
}

giveawayParticipantStatusAlreadyWasMember::giveawayParticipantStatusAlreadyWasMember()
  : joined_chat_date_()
{}

giveawayParticipantStatusAlreadyWasMember::giveawayParticipantStatusAlreadyWasMember(int32 joined_chat_date_)
  : joined_chat_date_(joined_chat_date_)
{}

const std::int32_t giveawayParticipantStatusAlreadyWasMember::ID;

void giveawayParticipantStatusAlreadyWasMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayParticipantStatusAlreadyWasMember");
    s.store_field("joined_chat_date", joined_chat_date_);
    s.store_class_end();
  }
}

giveawayParticipantStatusAdministrator::giveawayParticipantStatusAdministrator()
  : chat_id_()
{}

giveawayParticipantStatusAdministrator::giveawayParticipantStatusAdministrator(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t giveawayParticipantStatusAdministrator::ID;

void giveawayParticipantStatusAdministrator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayParticipantStatusAdministrator");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

giveawayParticipantStatusDisallowedCountry::giveawayParticipantStatusDisallowedCountry()
  : user_country_code_()
{}

giveawayParticipantStatusDisallowedCountry::giveawayParticipantStatusDisallowedCountry(string const &user_country_code_)
  : user_country_code_(user_country_code_)
{}

const std::int32_t giveawayParticipantStatusDisallowedCountry::ID;

void giveawayParticipantStatusDisallowedCountry::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giveawayParticipantStatusDisallowedCountry");
    s.store_field("user_country_code", user_country_code_);
    s.store_class_end();
  }
}

groupCallParticipant::groupCallParticipant()
  : participant_id_()
  , audio_source_id_()
  , screen_sharing_audio_source_id_()
  , video_info_()
  , screen_sharing_video_info_()
  , bio_()
  , is_current_user_()
  , is_speaking_()
  , is_hand_raised_()
  , can_be_muted_for_all_users_()
  , can_be_unmuted_for_all_users_()
  , can_be_muted_for_current_user_()
  , can_be_unmuted_for_current_user_()
  , is_muted_for_all_users_()
  , is_muted_for_current_user_()
  , can_unmute_self_()
  , volume_level_()
  , order_()
{}

groupCallParticipant::groupCallParticipant(object_ptr<MessageSender> &&participant_id_, int32 audio_source_id_, int32 screen_sharing_audio_source_id_, object_ptr<groupCallParticipantVideoInfo> &&video_info_, object_ptr<groupCallParticipantVideoInfo> &&screen_sharing_video_info_, string const &bio_, bool is_current_user_, bool is_speaking_, bool is_hand_raised_, bool can_be_muted_for_all_users_, bool can_be_unmuted_for_all_users_, bool can_be_muted_for_current_user_, bool can_be_unmuted_for_current_user_, bool is_muted_for_all_users_, bool is_muted_for_current_user_, bool can_unmute_self_, int32 volume_level_, string const &order_)
  : participant_id_(std::move(participant_id_))
  , audio_source_id_(audio_source_id_)
  , screen_sharing_audio_source_id_(screen_sharing_audio_source_id_)
  , video_info_(std::move(video_info_))
  , screen_sharing_video_info_(std::move(screen_sharing_video_info_))
  , bio_(bio_)
  , is_current_user_(is_current_user_)
  , is_speaking_(is_speaking_)
  , is_hand_raised_(is_hand_raised_)
  , can_be_muted_for_all_users_(can_be_muted_for_all_users_)
  , can_be_unmuted_for_all_users_(can_be_unmuted_for_all_users_)
  , can_be_muted_for_current_user_(can_be_muted_for_current_user_)
  , can_be_unmuted_for_current_user_(can_be_unmuted_for_current_user_)
  , is_muted_for_all_users_(is_muted_for_all_users_)
  , is_muted_for_current_user_(is_muted_for_current_user_)
  , can_unmute_self_(can_unmute_self_)
  , volume_level_(volume_level_)
  , order_(order_)
{}

const std::int32_t groupCallParticipant::ID;

void groupCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipant");
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("audio_source_id", audio_source_id_);
    s.store_field("screen_sharing_audio_source_id", screen_sharing_audio_source_id_);
    s.store_object_field("video_info", static_cast<const BaseObject *>(video_info_.get()));
    s.store_object_field("screen_sharing_video_info", static_cast<const BaseObject *>(screen_sharing_video_info_.get()));
    s.store_field("bio", bio_);
    s.store_field("is_current_user", is_current_user_);
    s.store_field("is_speaking", is_speaking_);
    s.store_field("is_hand_raised", is_hand_raised_);
    s.store_field("can_be_muted_for_all_users", can_be_muted_for_all_users_);
    s.store_field("can_be_unmuted_for_all_users", can_be_unmuted_for_all_users_);
    s.store_field("can_be_muted_for_current_user", can_be_muted_for_current_user_);
    s.store_field("can_be_unmuted_for_current_user", can_be_unmuted_for_current_user_);
    s.store_field("is_muted_for_all_users", is_muted_for_all_users_);
    s.store_field("is_muted_for_current_user", is_muted_for_current_user_);
    s.store_field("can_unmute_self", can_unmute_self_);
    s.store_field("volume_level", volume_level_);
    s.store_field("order", order_);
    s.store_class_end();
  }
}

groupCallParticipantVideoInfo::groupCallParticipantVideoInfo()
  : source_groups_()
  , endpoint_id_()
  , is_paused_()
{}

groupCallParticipantVideoInfo::groupCallParticipantVideoInfo(array<object_ptr<groupCallVideoSourceGroup>> &&source_groups_, string const &endpoint_id_, bool is_paused_)
  : source_groups_(std::move(source_groups_))
  , endpoint_id_(endpoint_id_)
  , is_paused_(is_paused_)
{}

const std::int32_t groupCallParticipantVideoInfo::ID;

void groupCallParticipantVideoInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipantVideoInfo");
    { s.store_vector_begin("source_groups", source_groups_.size()); for (const auto &_value : source_groups_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("endpoint_id", endpoint_id_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

httpUrl::httpUrl()
  : url_()
{}

httpUrl::httpUrl(string const &url_)
  : url_(url_)
{}

const std::int32_t httpUrl::ID;

void httpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "httpUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

importedContact::importedContact()
  : phone_number_()
  , first_name_()
  , last_name_()
  , note_()
{}

importedContact::importedContact(string const &phone_number_, string const &first_name_, string const &last_name_, object_ptr<formattedText> &&note_)
  : phone_number_(phone_number_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , note_(std::move(note_))
{}

const std::int32_t importedContact::ID;

void importedContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importedContact");
    s.store_field("phone_number", phone_number_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_object_field("note", static_cast<const BaseObject *>(note_.get()));
    s.store_class_end();
  }
}

inputBackgroundLocal::inputBackgroundLocal()
  : background_()
{}

inputBackgroundLocal::inputBackgroundLocal(object_ptr<InputFile> &&background_)
  : background_(std::move(background_))
{}

const std::int32_t inputBackgroundLocal::ID;

void inputBackgroundLocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBackgroundLocal");
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_class_end();
  }
}

inputBackgroundRemote::inputBackgroundRemote()
  : background_id_()
{}

inputBackgroundRemote::inputBackgroundRemote(int64 background_id_)
  : background_id_(background_id_)
{}

const std::int32_t inputBackgroundRemote::ID;

void inputBackgroundRemote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBackgroundRemote");
    s.store_field("background_id", background_id_);
    s.store_class_end();
  }
}

inputBackgroundPrevious::inputBackgroundPrevious()
  : message_id_()
{}

inputBackgroundPrevious::inputBackgroundPrevious(int53 message_id_)
  : message_id_(message_id_)
{}

const std::int32_t inputBackgroundPrevious::ID;

void inputBackgroundPrevious::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBackgroundPrevious");
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

inputFileId::inputFileId()
  : id_()
{}

inputFileId::inputFileId(int32 id_)
  : id_(id_)
{}

const std::int32_t inputFileId::ID;

void inputFileId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

inputFileRemote::inputFileRemote()
  : id_()
{}

inputFileRemote::inputFileRemote(string const &id_)
  : id_(id_)
{}

const std::int32_t inputFileRemote::ID;

void inputFileRemote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileRemote");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

inputFileLocal::inputFileLocal()
  : path_()
{}

inputFileLocal::inputFileLocal(string const &path_)
  : path_(path_)
{}

const std::int32_t inputFileLocal::ID;

void inputFileLocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileLocal");
    s.store_field("path", path_);
    s.store_class_end();
  }
}

inputFileGenerated::inputFileGenerated()
  : original_path_()
  , conversion_()
  , expected_size_()
{}

inputFileGenerated::inputFileGenerated(string const &original_path_, string const &conversion_, int53 expected_size_)
  : original_path_(original_path_)
  , conversion_(conversion_)
  , expected_size_(expected_size_)
{}

const std::int32_t inputFileGenerated::ID;

void inputFileGenerated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileGenerated");
    s.store_field("original_path", original_path_);
    s.store_field("conversion", conversion_);
    s.store_field("expected_size", expected_size_);
    s.store_class_end();
  }
}

inputPaidMediaTypePhoto::inputPaidMediaTypePhoto()
  : video_()
{}

inputPaidMediaTypePhoto::inputPaidMediaTypePhoto(object_ptr<InputFile> &&video_)
  : video_(std::move(video_))
{}

const std::int32_t inputPaidMediaTypePhoto::ID;

void inputPaidMediaTypePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaidMediaTypePhoto");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

inputPaidMediaTypeVideo::inputPaidMediaTypeVideo()
  : cover_()
  , start_timestamp_()
  , duration_()
  , supports_streaming_()
{}

inputPaidMediaTypeVideo::inputPaidMediaTypeVideo(object_ptr<InputFile> &&cover_, int32 start_timestamp_, int32 duration_, bool supports_streaming_)
  : cover_(std::move(cover_))
  , start_timestamp_(start_timestamp_)
  , duration_(duration_)
  , supports_streaming_(supports_streaming_)
{}

const std::int32_t inputPaidMediaTypeVideo::ID;

void inputPaidMediaTypeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaidMediaTypeVideo");
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_field("start_timestamp", start_timestamp_);
    s.store_field("duration", duration_);
    s.store_field("supports_streaming", supports_streaming_);
    s.store_class_end();
  }
}

inputTextQuote::inputTextQuote()
  : text_()
  , position_()
{}

inputTextQuote::inputTextQuote(object_ptr<formattedText> &&text_, int32 position_)
  : text_(std::move(text_))
  , position_(position_)
{}

const std::int32_t inputTextQuote::ID;

void inputTextQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputTextQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("position", position_);
    s.store_class_end();
  }
}

keyboardButton::keyboardButton()
  : text_()
  , icon_custom_emoji_id_()
  , style_()
  , type_()
{}

keyboardButton::keyboardButton(string const &text_, int64 icon_custom_emoji_id_, object_ptr<ButtonStyle> &&style_, object_ptr<KeyboardButtonType> &&type_)
  : text_(text_)
  , icon_custom_emoji_id_(icon_custom_emoji_id_)
  , style_(std::move(style_))
  , type_(std::move(type_))
{}

const std::int32_t keyboardButton::ID;

void keyboardButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButton");
    s.store_field("text", text_);
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_object_field("style", static_cast<const BaseObject *>(style_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

linkPreviewAlbumMediaPhoto::linkPreviewAlbumMediaPhoto()
  : photo_()
{}

linkPreviewAlbumMediaPhoto::linkPreviewAlbumMediaPhoto(object_ptr<photo> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewAlbumMediaPhoto::ID;

void linkPreviewAlbumMediaPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewAlbumMediaPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewAlbumMediaVideo::linkPreviewAlbumMediaVideo()
  : video_()
{}

linkPreviewAlbumMediaVideo::linkPreviewAlbumMediaVideo(object_ptr<video> &&video_)
  : video_(std::move(video_))
{}

const std::int32_t linkPreviewAlbumMediaVideo::ID;

void linkPreviewAlbumMediaVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewAlbumMediaVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

localFile::localFile()
  : path_()
  , can_be_downloaded_()
  , can_be_deleted_()
  , is_downloading_active_()
  , is_downloading_completed_()
  , download_offset_()
  , downloaded_prefix_size_()
  , downloaded_size_()
{}

localFile::localFile(string const &path_, bool can_be_downloaded_, bool can_be_deleted_, bool is_downloading_active_, bool is_downloading_completed_, int53 download_offset_, int53 downloaded_prefix_size_, int53 downloaded_size_)
  : path_(path_)
  , can_be_downloaded_(can_be_downloaded_)
  , can_be_deleted_(can_be_deleted_)
  , is_downloading_active_(is_downloading_active_)
  , is_downloading_completed_(is_downloading_completed_)
  , download_offset_(download_offset_)
  , downloaded_prefix_size_(downloaded_prefix_size_)
  , downloaded_size_(downloaded_size_)
{}

const std::int32_t localFile::ID;

void localFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "localFile");
    s.store_field("path", path_);
    s.store_field("can_be_downloaded", can_be_downloaded_);
    s.store_field("can_be_deleted", can_be_deleted_);
    s.store_field("is_downloading_active", is_downloading_active_);
    s.store_field("is_downloading_completed", is_downloading_completed_);
    s.store_field("download_offset", download_offset_);
    s.store_field("downloaded_prefix_size", downloaded_prefix_size_);
    s.store_field("downloaded_size", downloaded_size_);
    s.store_class_end();
  }
}

logVerbosityLevel::logVerbosityLevel()
  : verbosity_level_()
{}

logVerbosityLevel::logVerbosityLevel(int32 verbosity_level_)
  : verbosity_level_(verbosity_level_)
{}

const std::int32_t logVerbosityLevel::ID;

void logVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logVerbosityLevel");
    s.store_field("verbosity_level", verbosity_level_);
    s.store_class_end();
  }
}

loginUrlInfoOpen::loginUrlInfoOpen()
  : url_()
  , skip_confirmation_()
{}

loginUrlInfoOpen::loginUrlInfoOpen(string const &url_, bool skip_confirmation_)
  : url_(url_)
  , skip_confirmation_(skip_confirmation_)
{}

const std::int32_t loginUrlInfoOpen::ID;

void loginUrlInfoOpen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loginUrlInfoOpen");
    s.store_field("url", url_);
    s.store_field("skip_confirmation", skip_confirmation_);
    s.store_class_end();
  }
}

loginUrlInfoRequestConfirmation::loginUrlInfoRequestConfirmation()
  : url_()
  , domain_()
  , bot_user_id_()
  , request_write_access_()
{}

loginUrlInfoRequestConfirmation::loginUrlInfoRequestConfirmation(string const &url_, string const &domain_, int53 bot_user_id_, bool request_write_access_)
  : url_(url_)
  , domain_(domain_)
  , bot_user_id_(bot_user_id_)
  , request_write_access_(request_write_access_)
{}

const std::int32_t loginUrlInfoRequestConfirmation::ID;

void loginUrlInfoRequestConfirmation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loginUrlInfoRequestConfirmation");
    s.store_field("url", url_);
    s.store_field("domain", domain_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("request_write_access", request_write_access_);
    s.store_class_end();
  }
}

messageCopyOptions::messageCopyOptions()
  : send_copy_()
  , replace_caption_()
  , new_caption_()
  , new_show_caption_above_media_()
{}

messageCopyOptions::messageCopyOptions(bool send_copy_, bool replace_caption_, object_ptr<formattedText> &&new_caption_, bool new_show_caption_above_media_)
  : send_copy_(send_copy_)
  , replace_caption_(replace_caption_)
  , new_caption_(std::move(new_caption_))
  , new_show_caption_above_media_(new_show_caption_above_media_)
{}

const std::int32_t messageCopyOptions::ID;

void messageCopyOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageCopyOptions");
    s.store_field("send_copy", send_copy_);
    s.store_field("replace_caption", replace_caption_);
    s.store_object_field("new_caption", static_cast<const BaseObject *>(new_caption_.get()));
    s.store_field("new_show_caption_above_media", new_show_caption_above_media_);
    s.store_class_end();
  }
}

messageEffectTypeEmojiReaction::messageEffectTypeEmojiReaction()
  : select_animation_()
  , effect_animation_()
{}

messageEffectTypeEmojiReaction::messageEffectTypeEmojiReaction(object_ptr<sticker> &&select_animation_, object_ptr<sticker> &&effect_animation_)
  : select_animation_(std::move(select_animation_))
  , effect_animation_(std::move(effect_animation_))
{}

const std::int32_t messageEffectTypeEmojiReaction::ID;

void messageEffectTypeEmojiReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEffectTypeEmojiReaction");
    s.store_object_field("select_animation", static_cast<const BaseObject *>(select_animation_.get()));
    s.store_object_field("effect_animation", static_cast<const BaseObject *>(effect_animation_.get()));
    s.store_class_end();
  }
}

messageEffectTypePremiumSticker::messageEffectTypePremiumSticker()
  : sticker_()
{}

messageEffectTypePremiumSticker::messageEffectTypePremiumSticker(object_ptr<sticker> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t messageEffectTypePremiumSticker::ID;

void messageEffectTypePremiumSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEffectTypePremiumSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

messageSelfDestructTypeTimer::messageSelfDestructTypeTimer()
  : self_destruct_time_()
{}

messageSelfDestructTypeTimer::messageSelfDestructTypeTimer(int32 self_destruct_time_)
  : self_destruct_time_(self_destruct_time_)
{}

const std::int32_t messageSelfDestructTypeTimer::ID;

void messageSelfDestructTypeTimer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSelfDestructTypeTimer");
    s.store_field("self_destruct_time", self_destruct_time_);
    s.store_class_end();
  }
}

messageSelfDestructTypeImmediately::messageSelfDestructTypeImmediately() {
}

const std::int32_t messageSelfDestructTypeImmediately::ID;

void messageSelfDestructTypeImmediately::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSelfDestructTypeImmediately");
    s.store_class_end();
  }
}

messageSourceChatHistory::messageSourceChatHistory() {
}

const std::int32_t messageSourceChatHistory::ID;

void messageSourceChatHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceChatHistory");
    s.store_class_end();
  }
}

messageSourceMessageThreadHistory::messageSourceMessageThreadHistory() {
}

const std::int32_t messageSourceMessageThreadHistory::ID;

void messageSourceMessageThreadHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceMessageThreadHistory");
    s.store_class_end();
  }
}

messageSourceForumTopicHistory::messageSourceForumTopicHistory() {
}

const std::int32_t messageSourceForumTopicHistory::ID;

void messageSourceForumTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceForumTopicHistory");
    s.store_class_end();
  }
}

messageSourceDirectMessagesChatTopicHistory::messageSourceDirectMessagesChatTopicHistory() {
}

const std::int32_t messageSourceDirectMessagesChatTopicHistory::ID;

void messageSourceDirectMessagesChatTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceDirectMessagesChatTopicHistory");
    s.store_class_end();
  }
}

messageSourceHistoryPreview::messageSourceHistoryPreview() {
}

const std::int32_t messageSourceHistoryPreview::ID;

void messageSourceHistoryPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceHistoryPreview");
    s.store_class_end();
  }
}

messageSourceChatList::messageSourceChatList() {
}

const std::int32_t messageSourceChatList::ID;

void messageSourceChatList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceChatList");
    s.store_class_end();
  }
}

messageSourceSearch::messageSourceSearch() {
}

const std::int32_t messageSourceSearch::ID;

void messageSourceSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceSearch");
    s.store_class_end();
  }
}

messageSourceChatEventLog::messageSourceChatEventLog() {
}

const std::int32_t messageSourceChatEventLog::ID;

void messageSourceChatEventLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceChatEventLog");
    s.store_class_end();
  }
}

messageSourceNotification::messageSourceNotification() {
}

const std::int32_t messageSourceNotification::ID;

void messageSourceNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceNotification");
    s.store_class_end();
  }
}

messageSourceScreenshot::messageSourceScreenshot() {
}

const std::int32_t messageSourceScreenshot::ID;

void messageSourceScreenshot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceScreenshot");
    s.store_class_end();
  }
}

messageSourceOther::messageSourceOther() {
}

const std::int32_t messageSourceOther::ID;

void messageSourceOther::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSourceOther");
    s.store_class_end();
  }
}

messages::messages()
  : total_count_()
  , messages_()
{}

messages::messages(int32 total_count_, array<object_ptr<message>> &&messages_)
  : total_count_(total_count_)
  , messages_(std::move(messages_))
{}

const std::int32_t messages::ID;

void messages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

passportElementPersonalDetails::passportElementPersonalDetails()
  : personal_details_()
{}

passportElementPersonalDetails::passportElementPersonalDetails(object_ptr<personalDetails> &&personal_details_)
  : personal_details_(std::move(personal_details_))
{}

const std::int32_t passportElementPersonalDetails::ID;

void passportElementPersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementPersonalDetails");
    s.store_object_field("personal_details", static_cast<const BaseObject *>(personal_details_.get()));
    s.store_class_end();
  }
}

passportElementPassport::passportElementPassport()
  : passport_()
{}

passportElementPassport::passportElementPassport(object_ptr<identityDocument> &&passport_)
  : passport_(std::move(passport_))
{}

const std::int32_t passportElementPassport::ID;

void passportElementPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementPassport");
    s.store_object_field("passport", static_cast<const BaseObject *>(passport_.get()));
    s.store_class_end();
  }
}

passportElementDriverLicense::passportElementDriverLicense()
  : driver_license_()
{}

passportElementDriverLicense::passportElementDriverLicense(object_ptr<identityDocument> &&driver_license_)
  : driver_license_(std::move(driver_license_))
{}

const std::int32_t passportElementDriverLicense::ID;

void passportElementDriverLicense::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementDriverLicense");
    s.store_object_field("driver_license", static_cast<const BaseObject *>(driver_license_.get()));
    s.store_class_end();
  }
}

passportElementIdentityCard::passportElementIdentityCard()
  : identity_card_()
{}

passportElementIdentityCard::passportElementIdentityCard(object_ptr<identityDocument> &&identity_card_)
  : identity_card_(std::move(identity_card_))
{}

const std::int32_t passportElementIdentityCard::ID;

void passportElementIdentityCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementIdentityCard");
    s.store_object_field("identity_card", static_cast<const BaseObject *>(identity_card_.get()));
    s.store_class_end();
  }
}

passportElementInternalPassport::passportElementInternalPassport()
  : internal_passport_()
{}

passportElementInternalPassport::passportElementInternalPassport(object_ptr<identityDocument> &&internal_passport_)
  : internal_passport_(std::move(internal_passport_))
{}

const std::int32_t passportElementInternalPassport::ID;

void passportElementInternalPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementInternalPassport");
    s.store_object_field("internal_passport", static_cast<const BaseObject *>(internal_passport_.get()));
    s.store_class_end();
  }
}

passportElementAddress::passportElementAddress()
  : address_()
{}

passportElementAddress::passportElementAddress(object_ptr<address> &&address_)
  : address_(std::move(address_))
{}

const std::int32_t passportElementAddress::ID;

void passportElementAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementAddress");
    s.store_object_field("address", static_cast<const BaseObject *>(address_.get()));
    s.store_class_end();
  }
}

passportElementUtilityBill::passportElementUtilityBill()
  : utility_bill_()
{}

passportElementUtilityBill::passportElementUtilityBill(object_ptr<personalDocument> &&utility_bill_)
  : utility_bill_(std::move(utility_bill_))
{}

const std::int32_t passportElementUtilityBill::ID;

void passportElementUtilityBill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementUtilityBill");
    s.store_object_field("utility_bill", static_cast<const BaseObject *>(utility_bill_.get()));
    s.store_class_end();
  }
}

passportElementBankStatement::passportElementBankStatement()
  : bank_statement_()
{}

passportElementBankStatement::passportElementBankStatement(object_ptr<personalDocument> &&bank_statement_)
  : bank_statement_(std::move(bank_statement_))
{}

const std::int32_t passportElementBankStatement::ID;

void passportElementBankStatement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementBankStatement");
    s.store_object_field("bank_statement", static_cast<const BaseObject *>(bank_statement_.get()));
    s.store_class_end();
  }
}

passportElementRentalAgreement::passportElementRentalAgreement()
  : rental_agreement_()
{}

passportElementRentalAgreement::passportElementRentalAgreement(object_ptr<personalDocument> &&rental_agreement_)
  : rental_agreement_(std::move(rental_agreement_))
{}

const std::int32_t passportElementRentalAgreement::ID;

void passportElementRentalAgreement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementRentalAgreement");
    s.store_object_field("rental_agreement", static_cast<const BaseObject *>(rental_agreement_.get()));
    s.store_class_end();
  }
}

passportElementPassportRegistration::passportElementPassportRegistration()
  : passport_registration_()
{}

passportElementPassportRegistration::passportElementPassportRegistration(object_ptr<personalDocument> &&passport_registration_)
  : passport_registration_(std::move(passport_registration_))
{}

const std::int32_t passportElementPassportRegistration::ID;

void passportElementPassportRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementPassportRegistration");
    s.store_object_field("passport_registration", static_cast<const BaseObject *>(passport_registration_.get()));
    s.store_class_end();
  }
}

passportElementTemporaryRegistration::passportElementTemporaryRegistration()
  : temporary_registration_()
{}

passportElementTemporaryRegistration::passportElementTemporaryRegistration(object_ptr<personalDocument> &&temporary_registration_)
  : temporary_registration_(std::move(temporary_registration_))
{}

const std::int32_t passportElementTemporaryRegistration::ID;

void passportElementTemporaryRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTemporaryRegistration");
    s.store_object_field("temporary_registration", static_cast<const BaseObject *>(temporary_registration_.get()));
    s.store_class_end();
  }
}

passportElementPhoneNumber::passportElementPhoneNumber()
  : phone_number_()
{}

passportElementPhoneNumber::passportElementPhoneNumber(string const &phone_number_)
  : phone_number_(phone_number_)
{}

const std::int32_t passportElementPhoneNumber::ID;

void passportElementPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

passportElementEmailAddress::passportElementEmailAddress()
  : email_address_()
{}

passportElementEmailAddress::passportElementEmailAddress(string const &email_address_)
  : email_address_(email_address_)
{}

const std::int32_t passportElementEmailAddress::ID;

void passportElementEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementEmailAddress");
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

paymentFormTypeRegular::paymentFormTypeRegular()
  : invoice_()
  , payment_provider_user_id_()
  , payment_provider_()
  , additional_payment_options_()
  , saved_order_info_()
  , saved_credentials_()
  , can_save_credentials_()
  , need_password_()
{}

paymentFormTypeRegular::paymentFormTypeRegular(object_ptr<invoice> &&invoice_, int53 payment_provider_user_id_, object_ptr<PaymentProvider> &&payment_provider_, array<object_ptr<paymentOption>> &&additional_payment_options_, object_ptr<orderInfo> &&saved_order_info_, array<object_ptr<savedCredentials>> &&saved_credentials_, bool can_save_credentials_, bool need_password_)
  : invoice_(std::move(invoice_))
  , payment_provider_user_id_(payment_provider_user_id_)
  , payment_provider_(std::move(payment_provider_))
  , additional_payment_options_(std::move(additional_payment_options_))
  , saved_order_info_(std::move(saved_order_info_))
  , saved_credentials_(std::move(saved_credentials_))
  , can_save_credentials_(can_save_credentials_)
  , need_password_(need_password_)
{}

const std::int32_t paymentFormTypeRegular::ID;

void paymentFormTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentFormTypeRegular");
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_field("payment_provider_user_id", payment_provider_user_id_);
    s.store_object_field("payment_provider", static_cast<const BaseObject *>(payment_provider_.get()));
    { s.store_vector_begin("additional_payment_options", additional_payment_options_.size()); for (const auto &_value : additional_payment_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("saved_order_info", static_cast<const BaseObject *>(saved_order_info_.get()));
    { s.store_vector_begin("saved_credentials", saved_credentials_.size()); for (const auto &_value : saved_credentials_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("can_save_credentials", can_save_credentials_);
    s.store_field("need_password", need_password_);
    s.store_class_end();
  }
}

paymentFormTypeStars::paymentFormTypeStars()
  : star_count_()
{}

paymentFormTypeStars::paymentFormTypeStars(int53 star_count_)
  : star_count_(star_count_)
{}

const std::int32_t paymentFormTypeStars::ID;

void paymentFormTypeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentFormTypeStars");
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

paymentFormTypeStarSubscription::paymentFormTypeStarSubscription()
  : pricing_()
{}

paymentFormTypeStarSubscription::paymentFormTypeStarSubscription(object_ptr<starSubscriptionPricing> &&pricing_)
  : pricing_(std::move(pricing_))
{}

const std::int32_t paymentFormTypeStarSubscription::ID;

void paymentFormTypeStarSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentFormTypeStarSubscription");
    s.store_object_field("pricing", static_cast<const BaseObject *>(pricing_.get()));
    s.store_class_end();
  }
}

paymentReceiptTypeRegular::paymentReceiptTypeRegular()
  : payment_provider_user_id_()
  , invoice_()
  , order_info_()
  , shipping_option_()
  , credentials_title_()
  , tip_amount_()
{}

paymentReceiptTypeRegular::paymentReceiptTypeRegular(int53 payment_provider_user_id_, object_ptr<invoice> &&invoice_, object_ptr<orderInfo> &&order_info_, object_ptr<shippingOption> &&shipping_option_, string const &credentials_title_, int53 tip_amount_)
  : payment_provider_user_id_(payment_provider_user_id_)
  , invoice_(std::move(invoice_))
  , order_info_(std::move(order_info_))
  , shipping_option_(std::move(shipping_option_))
  , credentials_title_(credentials_title_)
  , tip_amount_(tip_amount_)
{}

const std::int32_t paymentReceiptTypeRegular::ID;

void paymentReceiptTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentReceiptTypeRegular");
    s.store_field("payment_provider_user_id", payment_provider_user_id_);
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_object_field("order_info", static_cast<const BaseObject *>(order_info_.get()));
    s.store_object_field("shipping_option", static_cast<const BaseObject *>(shipping_option_.get()));
    s.store_field("credentials_title", credentials_title_);
    s.store_field("tip_amount", tip_amount_);
    s.store_class_end();
  }
}

paymentReceiptTypeStars::paymentReceiptTypeStars()
  : star_count_()
  , transaction_id_()
{}

paymentReceiptTypeStars::paymentReceiptTypeStars(int53 star_count_, string const &transaction_id_)
  : star_count_(star_count_)
  , transaction_id_(transaction_id_)
{}

const std::int32_t paymentReceiptTypeStars::ID;

void paymentReceiptTypeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentReceiptTypeStars");
    s.store_field("star_count", star_count_);
    s.store_field("transaction_id", transaction_id_);
    s.store_class_end();
  }
}

personalDocument::personalDocument()
  : files_()
  , translation_()
{}

personalDocument::personalDocument(array<object_ptr<datedFile>> &&files_, array<object_ptr<datedFile>> &&translation_)
  : files_(std::move(files_))
  , translation_(std::move(translation_))
{}

const std::int32_t personalDocument::ID;

void personalDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "personalDocument");
    { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

phoneNumberAuthenticationSettings::phoneNumberAuthenticationSettings()
  : allow_flash_call_()
  , allow_missed_call_()
  , is_current_phone_number_()
  , has_unknown_phone_number_()
  , allow_sms_retriever_api_()
  , firebase_authentication_settings_()
  , authentication_tokens_()
{}

phoneNumberAuthenticationSettings::phoneNumberAuthenticationSettings(bool allow_flash_call_, bool allow_missed_call_, bool is_current_phone_number_, bool has_unknown_phone_number_, bool allow_sms_retriever_api_, object_ptr<FirebaseAuthenticationSettings> &&firebase_authentication_settings_, array<string> &&authentication_tokens_)
  : allow_flash_call_(allow_flash_call_)
  , allow_missed_call_(allow_missed_call_)
  , is_current_phone_number_(is_current_phone_number_)
  , has_unknown_phone_number_(has_unknown_phone_number_)
  , allow_sms_retriever_api_(allow_sms_retriever_api_)
  , firebase_authentication_settings_(std::move(firebase_authentication_settings_))
  , authentication_tokens_(std::move(authentication_tokens_))
{}

const std::int32_t phoneNumberAuthenticationSettings::ID;

void phoneNumberAuthenticationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneNumberAuthenticationSettings");
    s.store_field("allow_flash_call", allow_flash_call_);
    s.store_field("allow_missed_call", allow_missed_call_);
    s.store_field("is_current_phone_number", is_current_phone_number_);
    s.store_field("has_unknown_phone_number", has_unknown_phone_number_);
    s.store_field("allow_sms_retriever_api", allow_sms_retriever_api_);
    s.store_object_field("firebase_authentication_settings", static_cast<const BaseObject *>(firebase_authentication_settings_.get()));
    { s.store_vector_begin("authentication_tokens", authentication_tokens_.size()); for (const auto &_value : authentication_tokens_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

premiumFeatures::premiumFeatures()
  : features_()
  , limits_()
  , payment_link_()
{}

premiumFeatures::premiumFeatures(array<object_ptr<PremiumFeature>> &&features_, array<object_ptr<premiumLimit>> &&limits_, object_ptr<InternalLinkType> &&payment_link_)
  : features_(std::move(features_))
  , limits_(std::move(limits_))
  , payment_link_(std::move(payment_link_))
{}

const std::int32_t premiumFeatures::ID;

void premiumFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatures");
    { s.store_vector_begin("features", features_.size()); for (const auto &_value : features_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("limits", limits_.size()); for (const auto &_value : limits_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("payment_link", static_cast<const BaseObject *>(payment_link_.get()));
    s.store_class_end();
  }
}

publicPostSearchLimits::publicPostSearchLimits()
  : daily_free_query_count_()
  , remaining_free_query_count_()
  , next_free_query_in_()
  , star_count_()
  , is_current_query_free_()
{}

publicPostSearchLimits::publicPostSearchLimits(int32 daily_free_query_count_, int32 remaining_free_query_count_, int32 next_free_query_in_, int53 star_count_, bool is_current_query_free_)
  : daily_free_query_count_(daily_free_query_count_)
  , remaining_free_query_count_(remaining_free_query_count_)
  , next_free_query_in_(next_free_query_in_)
  , star_count_(star_count_)
  , is_current_query_free_(is_current_query_free_)
{}

const std::int32_t publicPostSearchLimits::ID;

void publicPostSearchLimits::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicPostSearchLimits");
    s.store_field("daily_free_query_count", daily_free_query_count_);
    s.store_field("remaining_free_query_count", remaining_free_query_count_);
    s.store_field("next_free_query_in", next_free_query_in_);
    s.store_field("star_count", star_count_);
    s.store_field("is_current_query_free", is_current_query_free_);
    s.store_class_end();
  }
}

reactionNotificationSettings::reactionNotificationSettings()
  : message_reaction_source_()
  , story_reaction_source_()
  , poll_vote_source_()
  , sound_id_()
  , show_preview_()
{}

reactionNotificationSettings::reactionNotificationSettings(object_ptr<ReactionNotificationSource> &&message_reaction_source_, object_ptr<ReactionNotificationSource> &&story_reaction_source_, object_ptr<ReactionNotificationSource> &&poll_vote_source_, int64 sound_id_, bool show_preview_)
  : message_reaction_source_(std::move(message_reaction_source_))
  , story_reaction_source_(std::move(story_reaction_source_))
  , poll_vote_source_(std::move(poll_vote_source_))
  , sound_id_(sound_id_)
  , show_preview_(show_preview_)
{}

const std::int32_t reactionNotificationSettings::ID;

void reactionNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionNotificationSettings");
    s.store_object_field("message_reaction_source", static_cast<const BaseObject *>(message_reaction_source_.get()));
    s.store_object_field("story_reaction_source", static_cast<const BaseObject *>(story_reaction_source_.get()));
    s.store_object_field("poll_vote_source", static_cast<const BaseObject *>(poll_vote_source_.get()));
    s.store_field("sound_id", sound_id_);
    s.store_field("show_preview", show_preview_);
    s.store_class_end();
  }
}

remoteFile::remoteFile()
  : id_()
  , unique_id_()
  , is_uploading_active_()
  , is_uploading_completed_()
  , uploaded_size_()
{}

remoteFile::remoteFile(string const &id_, string const &unique_id_, bool is_uploading_active_, bool is_uploading_completed_, int53 uploaded_size_)
  : id_(id_)
  , unique_id_(unique_id_)
  , is_uploading_active_(is_uploading_active_)
  , is_uploading_completed_(is_uploading_completed_)
  , uploaded_size_(uploaded_size_)
{}

const std::int32_t remoteFile::ID;

void remoteFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "remoteFile");
    s.store_field("id", id_);
    s.store_field("unique_id", unique_id_);
    s.store_field("is_uploading_active", is_uploading_active_);
    s.store_field("is_uploading_completed", is_uploading_completed_);
    s.store_field("uploaded_size", uploaded_size_);
    s.store_class_end();
  }
}

reportOption::reportOption()
  : id_()
  , text_()
{}

reportOption::reportOption(bytes const &id_, string const &text_)
  : id_(std::move(id_))
  , text_(text_)
{}

const std::int32_t reportOption::ID;

void reportOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportOption");
    s.store_bytes_field("id", id_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

resendCodeReasonUserRequest::resendCodeReasonUserRequest() {
}

const std::int32_t resendCodeReasonUserRequest::ID;

void resendCodeReasonUserRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendCodeReasonUserRequest");
    s.store_class_end();
  }
}

resendCodeReasonVerificationFailed::resendCodeReasonVerificationFailed()
  : error_message_()
{}

resendCodeReasonVerificationFailed::resendCodeReasonVerificationFailed(string const &error_message_)
  : error_message_(error_message_)
{}

const std::int32_t resendCodeReasonVerificationFailed::ID;

void resendCodeReasonVerificationFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendCodeReasonVerificationFailed");
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

savedMessagesTopicTypeMyNotes::savedMessagesTopicTypeMyNotes() {
}

const std::int32_t savedMessagesTopicTypeMyNotes::ID;

void savedMessagesTopicTypeMyNotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedMessagesTopicTypeMyNotes");
    s.store_class_end();
  }
}

savedMessagesTopicTypeAuthorHidden::savedMessagesTopicTypeAuthorHidden() {
}

const std::int32_t savedMessagesTopicTypeAuthorHidden::ID;

void savedMessagesTopicTypeAuthorHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedMessagesTopicTypeAuthorHidden");
    s.store_class_end();
  }
}

savedMessagesTopicTypeSavedFromChat::savedMessagesTopicTypeSavedFromChat()
  : chat_id_()
{}

savedMessagesTopicTypeSavedFromChat::savedMessagesTopicTypeSavedFromChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t savedMessagesTopicTypeSavedFromChat::ID;

void savedMessagesTopicTypeSavedFromChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedMessagesTopicTypeSavedFromChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

sentGiftRegular::sentGiftRegular()
  : gift_()
{}

sentGiftRegular::sentGiftRegular(object_ptr<gift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t sentGiftRegular::ID;

void sentGiftRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sentGiftRegular");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

sentGiftUpgraded::sentGiftUpgraded()
  : gift_()
{}

sentGiftUpgraded::sentGiftUpgraded(object_ptr<upgradedGift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t sentGiftUpgraded::ID;

void sentGiftUpgraded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sentGiftUpgraded");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

sentWebAppMessage::sentWebAppMessage()
  : inline_message_id_()
{}

sentWebAppMessage::sentWebAppMessage(string const &inline_message_id_)
  : inline_message_id_(inline_message_id_)
{}

const std::int32_t sentWebAppMessage::ID;

void sentWebAppMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sentWebAppMessage");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_class_end();
  }
}

starTransactions::starTransactions()
  : star_amount_()
  , transactions_()
  , next_offset_()
{}

starTransactions::starTransactions(object_ptr<starAmount> &&star_amount_, array<object_ptr<starTransaction>> &&transactions_, string const &next_offset_)
  : star_amount_(std::move(star_amount_))
  , transactions_(std::move(transactions_))
  , next_offset_(next_offset_)
{}

const std::int32_t starTransactions::ID;

void starTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactions");
    s.store_object_field("star_amount", static_cast<const BaseObject *>(star_amount_.get()));
    { s.store_vector_begin("transactions", transactions_.size()); for (const auto &_value : transactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

stickerFormatWebp::stickerFormatWebp() {
}

const std::int32_t stickerFormatWebp::ID;

void stickerFormatWebp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerFormatWebp");
    s.store_class_end();
  }
}

stickerFormatTgs::stickerFormatTgs() {
}

const std::int32_t stickerFormatTgs::ID;

void stickerFormatTgs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerFormatTgs");
    s.store_class_end();
  }
}

stickerFormatWebm::stickerFormatWebm() {
}

const std::int32_t stickerFormatWebm::ID;

void stickerFormatWebm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerFormatWebm");
    s.store_class_end();
  }
}

storageStatisticsFast::storageStatisticsFast()
  : files_size_()
  , file_count_()
  , database_size_()
  , language_pack_database_size_()
  , log_size_()
{}

storageStatisticsFast::storageStatisticsFast(int53 files_size_, int32 file_count_, int53 database_size_, int53 language_pack_database_size_, int53 log_size_)
  : files_size_(files_size_)
  , file_count_(file_count_)
  , database_size_(database_size_)
  , language_pack_database_size_(language_pack_database_size_)
  , log_size_(log_size_)
{}

const std::int32_t storageStatisticsFast::ID;

void storageStatisticsFast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storageStatisticsFast");
    s.store_field("files_size", files_size_);
    s.store_field("file_count", file_count_);
    s.store_field("database_size", database_size_);
    s.store_field("language_pack_database_size", language_pack_database_size_);
    s.store_field("log_size", log_size_);
    s.store_class_end();
  }
}

storeTransactionAppStore::storeTransactionAppStore()
  : receipt_()
{}

storeTransactionAppStore::storeTransactionAppStore(bytes const &receipt_)
  : receipt_(std::move(receipt_))
{}

const std::int32_t storeTransactionAppStore::ID;

void storeTransactionAppStore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storeTransactionAppStore");
    s.store_bytes_field("receipt", receipt_);
    s.store_class_end();
  }
}

storeTransactionGooglePlay::storeTransactionGooglePlay()
  : package_name_()
  , store_product_id_()
  , purchase_token_()
{}

storeTransactionGooglePlay::storeTransactionGooglePlay(string const &package_name_, string const &store_product_id_, string const &purchase_token_)
  : package_name_(package_name_)
  , store_product_id_(store_product_id_)
  , purchase_token_(purchase_token_)
{}

const std::int32_t storeTransactionGooglePlay::ID;

void storeTransactionGooglePlay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storeTransactionGooglePlay");
    s.store_field("package_name", package_name_);
    s.store_field("store_product_id", store_product_id_);
    s.store_field("purchase_token", purchase_token_);
    s.store_class_end();
  }
}

textEntityTypeMention::textEntityTypeMention() {
}

const std::int32_t textEntityTypeMention::ID;

void textEntityTypeMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeMention");
    s.store_class_end();
  }
}

textEntityTypeHashtag::textEntityTypeHashtag() {
}

const std::int32_t textEntityTypeHashtag::ID;

void textEntityTypeHashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeHashtag");
    s.store_class_end();
  }
}

textEntityTypeCashtag::textEntityTypeCashtag() {
}

const std::int32_t textEntityTypeCashtag::ID;

void textEntityTypeCashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeCashtag");
    s.store_class_end();
  }
}

textEntityTypeBotCommand::textEntityTypeBotCommand() {
}

const std::int32_t textEntityTypeBotCommand::ID;

void textEntityTypeBotCommand::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeBotCommand");
    s.store_class_end();
  }
}

textEntityTypeUrl::textEntityTypeUrl() {
}

const std::int32_t textEntityTypeUrl::ID;

void textEntityTypeUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeUrl");
    s.store_class_end();
  }
}

textEntityTypeEmailAddress::textEntityTypeEmailAddress() {
}

const std::int32_t textEntityTypeEmailAddress::ID;

void textEntityTypeEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeEmailAddress");
    s.store_class_end();
  }
}

textEntityTypePhoneNumber::textEntityTypePhoneNumber() {
}

const std::int32_t textEntityTypePhoneNumber::ID;

void textEntityTypePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypePhoneNumber");
    s.store_class_end();
  }
}

textEntityTypeBankCardNumber::textEntityTypeBankCardNumber() {
}

const std::int32_t textEntityTypeBankCardNumber::ID;

void textEntityTypeBankCardNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeBankCardNumber");
    s.store_class_end();
  }
}

textEntityTypeBold::textEntityTypeBold() {
}

const std::int32_t textEntityTypeBold::ID;

void textEntityTypeBold::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeBold");
    s.store_class_end();
  }
}

textEntityTypeItalic::textEntityTypeItalic() {
}

const std::int32_t textEntityTypeItalic::ID;

void textEntityTypeItalic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeItalic");
    s.store_class_end();
  }
}

textEntityTypeUnderline::textEntityTypeUnderline() {
}

const std::int32_t textEntityTypeUnderline::ID;

void textEntityTypeUnderline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeUnderline");
    s.store_class_end();
  }
}

textEntityTypeStrikethrough::textEntityTypeStrikethrough() {
}

const std::int32_t textEntityTypeStrikethrough::ID;

void textEntityTypeStrikethrough::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeStrikethrough");
    s.store_class_end();
  }
}

textEntityTypeSpoiler::textEntityTypeSpoiler() {
}

const std::int32_t textEntityTypeSpoiler::ID;

void textEntityTypeSpoiler::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeSpoiler");
    s.store_class_end();
  }
}

textEntityTypeCode::textEntityTypeCode() {
}

const std::int32_t textEntityTypeCode::ID;

void textEntityTypeCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeCode");
    s.store_class_end();
  }
}

textEntityTypePre::textEntityTypePre() {
}

const std::int32_t textEntityTypePre::ID;

void textEntityTypePre::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypePre");
    s.store_class_end();
  }
}

textEntityTypePreCode::textEntityTypePreCode()
  : language_()
{}

textEntityTypePreCode::textEntityTypePreCode(string const &language_)
  : language_(language_)
{}

const std::int32_t textEntityTypePreCode::ID;

void textEntityTypePreCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypePreCode");
    s.store_field("language", language_);
    s.store_class_end();
  }
}

textEntityTypeBlockQuote::textEntityTypeBlockQuote() {
}

const std::int32_t textEntityTypeBlockQuote::ID;

void textEntityTypeBlockQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeBlockQuote");
    s.store_class_end();
  }
}

textEntityTypeExpandableBlockQuote::textEntityTypeExpandableBlockQuote() {
}

const std::int32_t textEntityTypeExpandableBlockQuote::ID;

void textEntityTypeExpandableBlockQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeExpandableBlockQuote");
    s.store_class_end();
  }
}

textEntityTypeTextUrl::textEntityTypeTextUrl()
  : url_()
{}

textEntityTypeTextUrl::textEntityTypeTextUrl(string const &url_)
  : url_(url_)
{}

const std::int32_t textEntityTypeTextUrl::ID;

void textEntityTypeTextUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeTextUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

textEntityTypeMentionName::textEntityTypeMentionName()
  : user_id_()
{}

textEntityTypeMentionName::textEntityTypeMentionName(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t textEntityTypeMentionName::ID;

void textEntityTypeMentionName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeMentionName");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

textEntityTypeCustomEmoji::textEntityTypeCustomEmoji()
  : custom_emoji_id_()
{}

textEntityTypeCustomEmoji::textEntityTypeCustomEmoji(int64 custom_emoji_id_)
  : custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t textEntityTypeCustomEmoji::ID;

void textEntityTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeCustomEmoji");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

textEntityTypeMediaTimestamp::textEntityTypeMediaTimestamp()
  : media_timestamp_()
{}

textEntityTypeMediaTimestamp::textEntityTypeMediaTimestamp(int32 media_timestamp_)
  : media_timestamp_(media_timestamp_)
{}

const std::int32_t textEntityTypeMediaTimestamp::ID;

void textEntityTypeMediaTimestamp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeMediaTimestamp");
    s.store_field("media_timestamp", media_timestamp_);
    s.store_class_end();
  }
}

textEntityTypeDateTime::textEntityTypeDateTime()
  : unix_time_()
  , formatting_type_()
{}

textEntityTypeDateTime::textEntityTypeDateTime(int32 unix_time_, object_ptr<DateTimeFormattingType> &&formatting_type_)
  : unix_time_(unix_time_)
  , formatting_type_(std::move(formatting_type_))
{}

const std::int32_t textEntityTypeDateTime::ID;

void textEntityTypeDateTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntityTypeDateTime");
    s.store_field("unix_time", unix_time_);
    s.store_object_field("formatting_type", static_cast<const BaseObject *>(formatting_type_.get()));
    s.store_class_end();
  }
}

textParseModeMarkdown::textParseModeMarkdown()
  : version_()
{}

textParseModeMarkdown::textParseModeMarkdown(int32 version_)
  : version_(version_)
{}

const std::int32_t textParseModeMarkdown::ID;

void textParseModeMarkdown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textParseModeMarkdown");
    s.store_field("version", version_);
    s.store_class_end();
  }
}

textParseModeHTML::textParseModeHTML() {
}

const std::int32_t textParseModeHTML::ID;

void textParseModeHTML::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textParseModeHTML");
    s.store_class_end();
  }
}

textQuote::textQuote()
  : text_()
  , position_()
  , is_manual_()
{}

textQuote::textQuote(object_ptr<formattedText> &&text_, int32 position_, bool is_manual_)
  : text_(std::move(text_))
  , position_(position_)
  , is_manual_(is_manual_)
{}

const std::int32_t textQuote::ID;

void textQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("position", position_);
    s.store_field("is_manual", is_manual_);
    s.store_class_end();
  }
}

timeZone::timeZone()
  : id_()
  , name_()
  , utc_time_offset_()
{}

timeZone::timeZone(string const &id_, string const &name_, int32 utc_time_offset_)
  : id_(id_)
  , name_(name_)
  , utc_time_offset_(utc_time_offset_)
{}

const std::int32_t timeZone::ID;

void timeZone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "timeZone");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_field("utc_time_offset", utc_time_offset_);
    s.store_class_end();
  }
}

tonTransactions::tonTransactions()
  : ton_amount_()
  , transactions_()
  , next_offset_()
{}

tonTransactions::tonTransactions(int53 ton_amount_, array<object_ptr<tonTransaction>> &&transactions_, string const &next_offset_)
  : ton_amount_(ton_amount_)
  , transactions_(std::move(transactions_))
  , next_offset_(next_offset_)
{}

const std::int32_t tonTransactions::ID;

void tonTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransactions");
    s.store_field("ton_amount", ton_amount_);
    { s.store_vector_begin("transactions", transactions_.size()); for (const auto &_value : transactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

transactionDirectionIncoming::transactionDirectionIncoming() {
}

const std::int32_t transactionDirectionIncoming::ID;

void transactionDirectionIncoming::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "transactionDirectionIncoming");
    s.store_class_end();
  }
}

transactionDirectionOutgoing::transactionDirectionOutgoing() {
}

const std::int32_t transactionDirectionOutgoing::ID;

void transactionDirectionOutgoing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "transactionDirectionOutgoing");
    s.store_class_end();
  }
}

unreadReaction::unreadReaction()
  : type_()
  , sender_id_()
  , is_big_()
{}

unreadReaction::unreadReaction(object_ptr<ReactionType> &&type_, object_ptr<MessageSender> &&sender_id_, bool is_big_)
  : type_(std::move(type_))
  , sender_id_(std::move(sender_id_))
  , is_big_(is_big_)
{}

const std::int32_t unreadReaction::ID;

void unreadReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unreadReaction");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("is_big", is_big_);
    s.store_class_end();
  }
}

upgradedGiftColors::upgradedGiftColors()
  : id_()
  , model_custom_emoji_id_()
  , symbol_custom_emoji_id_()
  , light_theme_accent_color_()
  , light_theme_colors_()
  , dark_theme_accent_color_()
  , dark_theme_colors_()
{}

upgradedGiftColors::upgradedGiftColors(int64 id_, int64 model_custom_emoji_id_, int64 symbol_custom_emoji_id_, int32 light_theme_accent_color_, array<int32> &&light_theme_colors_, int32 dark_theme_accent_color_, array<int32> &&dark_theme_colors_)
  : id_(id_)
  , model_custom_emoji_id_(model_custom_emoji_id_)
  , symbol_custom_emoji_id_(symbol_custom_emoji_id_)
  , light_theme_accent_color_(light_theme_accent_color_)
  , light_theme_colors_(std::move(light_theme_colors_))
  , dark_theme_accent_color_(dark_theme_accent_color_)
  , dark_theme_colors_(std::move(dark_theme_colors_))
{}

const std::int32_t upgradedGiftColors::ID;

void upgradedGiftColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftColors");
    s.store_field("id", id_);
    s.store_field("model_custom_emoji_id", model_custom_emoji_id_);
    s.store_field("symbol_custom_emoji_id", symbol_custom_emoji_id_);
    s.store_field("light_theme_accent_color", light_theme_accent_color_);
    { s.store_vector_begin("light_theme_colors", light_theme_colors_.size()); for (const auto &_value : light_theme_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("dark_theme_accent_color", dark_theme_accent_color_);
    { s.store_vector_begin("dark_theme_colors", dark_theme_colors_.size()); for (const auto &_value : dark_theme_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

videoChat::videoChat()
  : group_call_id_()
  , has_participants_()
  , default_participant_id_()
{}

videoChat::videoChat(int32 group_call_id_, bool has_participants_, object_ptr<MessageSender> &&default_participant_id_)
  : group_call_id_(group_call_id_)
  , has_participants_(has_participants_)
  , default_participant_id_(std::move(default_participant_id_))
{}

const std::int32_t videoChat::ID;

void videoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoChat");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("has_participants", has_participants_);
    s.store_object_field("default_participant_id", static_cast<const BaseObject *>(default_participant_id_.get()));
    s.store_class_end();
  }
}

voiceNote::voiceNote()
  : duration_()
  , waveform_()
  , mime_type_()
  , speech_recognition_result_()
  , voice_()
{}

voiceNote::voiceNote(int32 duration_, bytes const &waveform_, string const &mime_type_, object_ptr<SpeechRecognitionResult> &&speech_recognition_result_, object_ptr<file> &&voice_)
  : duration_(duration_)
  , waveform_(std::move(waveform_))
  , mime_type_(mime_type_)
  , speech_recognition_result_(std::move(speech_recognition_result_))
  , voice_(std::move(voice_))
{}

const std::int32_t voiceNote::ID;

void voiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "voiceNote");
    s.store_field("duration", duration_);
    s.store_bytes_field("waveform", waveform_);
    s.store_field("mime_type", mime_type_);
    s.store_object_field("speech_recognition_result", static_cast<const BaseObject *>(speech_recognition_result_.get()));
    s.store_object_field("voice", static_cast<const BaseObject *>(voice_.get()));
    s.store_class_end();
  }
}

acceptOauthRequest::acceptOauthRequest()
  : url_()
  , match_code_()
  , allow_write_access_()
  , allow_phone_number_access_()
{}

acceptOauthRequest::acceptOauthRequest(string const &url_, string const &match_code_, bool allow_write_access_, bool allow_phone_number_access_)
  : url_(url_)
  , match_code_(match_code_)
  , allow_write_access_(allow_write_access_)
  , allow_phone_number_access_(allow_phone_number_access_)
{}

const std::int32_t acceptOauthRequest::ID;

void acceptOauthRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "acceptOauthRequest");
    s.store_field("url", url_);
    s.store_field("match_code", match_code_);
    s.store_field("allow_write_access", allow_write_access_);
    s.store_field("allow_phone_number_access", allow_phone_number_access_);
    s.store_class_end();
  }
}

addContact::addContact()
  : user_id_()
  , contact_()
  , share_phone_number_()
{}

addContact::addContact(int53 user_id_, object_ptr<importedContact> &&contact_, bool share_phone_number_)
  : user_id_(user_id_)
  , contact_(std::move(contact_))
  , share_phone_number_(share_phone_number_)
{}

const std::int32_t addContact::ID;

void addContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addContact");
    s.store_field("user_id", user_id_);
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_field("share_phone_number", share_phone_number_);
    s.store_class_end();
  }
}

addLoginPasskey::addLoginPasskey()
  : client_data_()
  , attestation_object_()
{}

addLoginPasskey::addLoginPasskey(string const &client_data_, bytes const &attestation_object_)
  : client_data_(client_data_)
  , attestation_object_(std::move(attestation_object_))
{}

const std::int32_t addLoginPasskey::ID;

void addLoginPasskey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addLoginPasskey");
    s.store_field("client_data", client_data_);
    s.store_bytes_field("attestation_object", attestation_object_);
    s.store_class_end();
  }
}

approveSuggestedPost::approveSuggestedPost()
  : chat_id_()
  , message_id_()
  , send_date_()
{}

approveSuggestedPost::approveSuggestedPost(int53 chat_id_, int53 message_id_, int32 send_date_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , send_date_(send_date_)
{}

const std::int32_t approveSuggestedPost::ID;

void approveSuggestedPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "approveSuggestedPost");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("send_date", send_date_);
    s.store_class_end();
  }
}

clickChatSponsoredMessage::clickChatSponsoredMessage()
  : chat_id_()
  , message_id_()
  , is_media_click_()
  , from_fullscreen_()
{}

clickChatSponsoredMessage::clickChatSponsoredMessage(int53 chat_id_, int53 message_id_, bool is_media_click_, bool from_fullscreen_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_media_click_(is_media_click_)
  , from_fullscreen_(from_fullscreen_)
{}

const std::int32_t clickChatSponsoredMessage::ID;

void clickChatSponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clickChatSponsoredMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_media_click", is_media_click_);
    s.store_field("from_fullscreen", from_fullscreen_);
    s.store_class_end();
  }
}

createInvoiceLink::createInvoiceLink()
  : business_connection_id_()
  , invoice_()
{}

createInvoiceLink::createInvoiceLink(string const &business_connection_id_, object_ptr<InputMessageContent> &&invoice_)
  : business_connection_id_(business_connection_id_)
  , invoice_(std::move(invoice_))
{}

const std::int32_t createInvoiceLink::ID;

void createInvoiceLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createInvoiceLink");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_class_end();
  }
}

createSecretChat::createSecretChat()
  : secret_chat_id_()
{}

createSecretChat::createSecretChat(int32 secret_chat_id_)
  : secret_chat_id_(secret_chat_id_)
{}

const std::int32_t createSecretChat::ID;

void createSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createSecretChat");
    s.store_field("secret_chat_id", secret_chat_id_);
    s.store_class_end();
  }
}

deleteAccount::deleteAccount()
  : reason_()
  , password_()
{}

deleteAccount::deleteAccount(string const &reason_, string const &password_)
  : reason_(reason_)
  , password_(password_)
{}

const std::int32_t deleteAccount::ID;

void deleteAccount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteAccount");
    s.store_field("reason", reason_);
    s.store_field("password", password_);
    s.store_class_end();
  }
}

deleteBotMediaPreviews::deleteBotMediaPreviews()
  : bot_user_id_()
  , language_code_()
  , file_ids_()
{}

deleteBotMediaPreviews::deleteBotMediaPreviews(int53 bot_user_id_, string const &language_code_, array<int32> &&file_ids_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , file_ids_(std::move(file_ids_))
{}

const std::int32_t deleteBotMediaPreviews::ID;

void deleteBotMediaPreviews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteBotMediaPreviews");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    { s.store_vector_begin("file_ids", file_ids_.size()); for (const auto &_value : file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

deleteChatReplyMarkup::deleteChatReplyMarkup()
  : chat_id_()
  , message_id_()
{}

deleteChatReplyMarkup::deleteChatReplyMarkup(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t deleteChatReplyMarkup::ID;

void deleteChatReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatReplyMarkup");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

deleteStickerSet::deleteStickerSet()
  : name_()
{}

deleteStickerSet::deleteStickerSet(string const &name_)
  : name_(name_)
{}

const std::int32_t deleteStickerSet::ID;

void deleteStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteStickerSet");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

destroy::destroy() {
}

const std::int32_t destroy::ID;

void destroy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "destroy");
    s.store_class_end();
  }
}

disableAllSupergroupUsernames::disableAllSupergroupUsernames()
  : supergroup_id_()
{}

disableAllSupergroupUsernames::disableAllSupergroupUsernames(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t disableAllSupergroupUsernames::ID;

void disableAllSupergroupUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disableAllSupergroupUsernames");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

editChatFolderInviteLink::editChatFolderInviteLink()
  : chat_folder_id_()
  , invite_link_()
  , name_()
  , chat_ids_()
{}

editChatFolderInviteLink::editChatFolderInviteLink(int32 chat_folder_id_, string const &invite_link_, string const &name_, array<int53> &&chat_ids_)
  : chat_folder_id_(chat_folder_id_)
  , invite_link_(invite_link_)
  , name_(name_)
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t editChatFolderInviteLink::ID;

void editChatFolderInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editChatFolderInviteLink");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("name", name_);
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

editMessageSchedulingState::editMessageSchedulingState()
  : chat_id_()
  , message_id_()
  , scheduling_state_()
{}

editMessageSchedulingState::editMessageSchedulingState(int53 chat_id_, int53 message_id_, object_ptr<MessageSchedulingState> &&scheduling_state_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , scheduling_state_(std::move(scheduling_state_))
{}

const std::int32_t editMessageSchedulingState::ID;

void editMessageSchedulingState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageSchedulingState");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("scheduling_state", static_cast<const BaseObject *>(scheduling_state_.get()));
    s.store_class_end();
  }
}

endGroupCall::endGroupCall()
  : group_call_id_()
{}

endGroupCall::endGroupCall(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t endGroupCall::ID;

void endGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "endGroupCall");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

fixTextWithAi::fixTextWithAi()
  : text_()
{}

fixTextWithAi::fixTextWithAi(object_ptr<formattedText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t fixTextWithAi::ID;

void fixTextWithAi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fixTextWithAi");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

getAutosaveSettings::getAutosaveSettings() {
}

const std::int32_t getAutosaveSettings::ID;

void getAutosaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAutosaveSettings");
    s.store_class_end();
  }
}

getBotSimilarBots::getBotSimilarBots()
  : bot_user_id_()
{}

getBotSimilarBots::getBotSimilarBots(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t getBotSimilarBots::ID;

void getBotSimilarBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotSimilarBots");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

getBusinessConnectedBot::getBusinessConnectedBot() {
}

const std::int32_t getBusinessConnectedBot::ID;

void getBusinessConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBusinessConnectedBot");
    s.store_class_end();
  }
}

getBusinessConnection::getBusinessConnection()
  : connection_id_()
{}

getBusinessConnection::getBusinessConnection(string const &connection_id_)
  : connection_id_(connection_id_)
{}

const std::int32_t getBusinessConnection::ID;

void getBusinessConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBusinessConnection");
    s.store_field("connection_id", connection_id_);
    s.store_class_end();
  }
}

getChatArchivedStories::getChatArchivedStories()
  : chat_id_()
  , from_story_id_()
  , limit_()
{}

getChatArchivedStories::getChatArchivedStories(int53 chat_id_, int32 from_story_id_, int32 limit_)
  : chat_id_(chat_id_)
  , from_story_id_(from_story_id_)
  , limit_(limit_)
{}

const std::int32_t getChatArchivedStories::ID;

void getChatArchivedStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatArchivedStories");
    s.store_field("chat_id", chat_id_);
    s.store_field("from_story_id", from_story_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatEventLog::getChatEventLog()
  : chat_id_()
  , query_()
  , from_event_id_()
  , limit_()
  , filters_()
  , user_ids_()
{}

getChatEventLog::getChatEventLog(int53 chat_id_, string const &query_, int64 from_event_id_, int32 limit_, object_ptr<chatEventLogFilters> &&filters_, array<int53> &&user_ids_)
  : chat_id_(chat_id_)
  , query_(query_)
  , from_event_id_(from_event_id_)
  , limit_(limit_)
  , filters_(std::move(filters_))
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t getChatEventLog::ID;

void getChatEventLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatEventLog");
    s.store_field("chat_id", chat_id_);
    s.store_field("query", query_);
    s.store_field("from_event_id", from_event_id_);
    s.store_field("limit", limit_);
    s.store_object_field("filters", static_cast<const BaseObject *>(filters_.get()));
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getChatFolderDefaultIconName::getChatFolderDefaultIconName()
  : folder_()
{}

getChatFolderDefaultIconName::getChatFolderDefaultIconName(object_ptr<chatFolder> &&folder_)
  : folder_(std::move(folder_))
{}

const std::int32_t getChatFolderDefaultIconName::ID;

void getChatFolderDefaultIconName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFolderDefaultIconName");
    s.store_object_field("folder", static_cast<const BaseObject *>(folder_.get()));
    s.store_class_end();
  }
}

getChatMessageByDate::getChatMessageByDate()
  : chat_id_()
  , date_()
{}

getChatMessageByDate::getChatMessageByDate(int53 chat_id_, int32 date_)
  : chat_id_(chat_id_)
  , date_(date_)
{}

const std::int32_t getChatMessageByDate::ID;

void getChatMessageByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMessageByDate");
    s.store_field("chat_id", chat_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

getChatOwnerAfterLeaving::getChatOwnerAfterLeaving()
  : chat_id_()
{}

getChatOwnerAfterLeaving::getChatOwnerAfterLeaving(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatOwnerAfterLeaving::ID;

void getChatOwnerAfterLeaving::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatOwnerAfterLeaving");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getConnectedAffiliateProgram::getConnectedAffiliateProgram()
  : affiliate_()
  , bot_user_id_()
{}

getConnectedAffiliateProgram::getConnectedAffiliateProgram(object_ptr<AffiliateType> &&affiliate_, int53 bot_user_id_)
  : affiliate_(std::move(affiliate_))
  , bot_user_id_(bot_user_id_)
{}

const std::int32_t getConnectedAffiliateProgram::ID;

void getConnectedAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getConnectedAffiliateProgram");
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

getDirectMessagesChatTopicRevenue::getDirectMessagesChatTopicRevenue()
  : chat_id_()
  , topic_id_()
{}

getDirectMessagesChatTopicRevenue::getDirectMessagesChatTopicRevenue(int53 chat_id_, int53 topic_id_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
{}

const std::int32_t getDirectMessagesChatTopicRevenue::ID;

void getDirectMessagesChatTopicRevenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDirectMessagesChatTopicRevenue");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_class_end();
  }
}

getDisallowedChatEmojiStatuses::getDisallowedChatEmojiStatuses() {
}

const std::int32_t getDisallowedChatEmojiStatuses::ID;

void getDisallowedChatEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDisallowedChatEmojiStatuses");
    s.store_class_end();
  }
}

getFileMimeType::getFileMimeType()
  : file_name_()
{}

getFileMimeType::getFileMimeType(string const &file_name_)
  : file_name_(file_name_)
{}

const std::int32_t getFileMimeType::ID;

void getFileMimeType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFileMimeType");
    s.store_field("file_name", file_name_);
    s.store_class_end();
  }
}

getGiftsForCrafting::getGiftsForCrafting()
  : regular_gift_id_()
  , offset_()
  , limit_()
{}

getGiftsForCrafting::getGiftsForCrafting(int64 regular_gift_id_, string const &offset_, int32 limit_)
  : regular_gift_id_(regular_gift_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getGiftsForCrafting::ID;

void getGiftsForCrafting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftsForCrafting");
    s.store_field("regular_gift_id", regular_gift_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getImportedContactCount::getImportedContactCount() {
}

const std::int32_t getImportedContactCount::ID;

void getImportedContactCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getImportedContactCount");
    s.store_class_end();
  }
}

getLogTagVerbosityLevel::getLogTagVerbosityLevel()
  : tag_()
{}

getLogTagVerbosityLevel::getLogTagVerbosityLevel(string const &tag_)
  : tag_(tag_)
{}

const std::int32_t getLogTagVerbosityLevel::ID;

void getLogTagVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLogTagVerbosityLevel");
    s.store_field("tag", tag_);
    s.store_class_end();
  }
}

getMapThumbnailFile::getMapThumbnailFile()
  : location_()
  , zoom_()
  , width_()
  , height_()
  , scale_()
  , chat_id_()
{}

getMapThumbnailFile::getMapThumbnailFile(object_ptr<location> &&location_, int32 zoom_, int32 width_, int32 height_, int32 scale_, int53 chat_id_)
  : location_(std::move(location_))
  , zoom_(zoom_)
  , width_(width_)
  , height_(height_)
  , scale_(scale_)
  , chat_id_(chat_id_)
{}

const std::int32_t getMapThumbnailFile::ID;

void getMapThumbnailFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMapThumbnailFile");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("zoom", zoom_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("scale", scale_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getMessage::getMessage()
  : chat_id_()
  , message_id_()
{}

getMessage::getMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessage::ID;

void getMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getMessageAuthor::getMessageAuthor()
  : chat_id_()
  , message_id_()
{}

getMessageAuthor::getMessageAuthor(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageAuthor::ID;

void getMessageAuthor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageAuthor");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getMessageAvailableReactions::getMessageAvailableReactions()
  : chat_id_()
  , message_id_()
  , row_size_()
{}

getMessageAvailableReactions::getMessageAvailableReactions(int53 chat_id_, int53 message_id_, int32 row_size_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , row_size_(row_size_)
{}

const std::int32_t getMessageAvailableReactions::ID;

void getMessageAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageAvailableReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("row_size", row_size_);
    s.store_class_end();
  }
}

getMessageLocally::getMessageLocally()
  : chat_id_()
  , message_id_()
{}

getMessageLocally::getMessageLocally(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageLocally::ID;

void getMessageLocally::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageLocally");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getPhoneNumberInfoSync::getPhoneNumberInfoSync()
  : language_code_()
  , phone_number_prefix_()
{}

getPhoneNumberInfoSync::getPhoneNumberInfoSync(string const &language_code_, string const &phone_number_prefix_)
  : language_code_(language_code_)
  , phone_number_prefix_(phone_number_prefix_)
{}

const std::int32_t getPhoneNumberInfoSync::ID;

void getPhoneNumberInfoSync::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPhoneNumberInfoSync");
    s.store_field("language_code", language_code_);
    s.store_field("phone_number_prefix", phone_number_prefix_);
    s.store_class_end();
  }
}

getPremiumStickerExamples::getPremiumStickerExamples() {
}

const std::int32_t getPremiumStickerExamples::ID;

void getPremiumStickerExamples::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumStickerExamples");
    s.store_class_end();
  }
}

getProxies::getProxies() {
}

const std::int32_t getProxies::ID;

void getProxies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getProxies");
    s.store_class_end();
  }
}

getSavedOrderInfo::getSavedOrderInfo() {
}

const std::int32_t getSavedOrderInfo::ID;

void getSavedOrderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedOrderInfo");
    s.store_class_end();
  }
}

getSecretChat::getSecretChat()
  : secret_chat_id_()
{}

getSecretChat::getSecretChat(int32 secret_chat_id_)
  : secret_chat_id_(secret_chat_id_)
{}

const std::int32_t getSecretChat::ID;

void getSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSecretChat");
    s.store_field("secret_chat_id", secret_chat_id_);
    s.store_class_end();
  }
}

getStickerOutline::getStickerOutline()
  : sticker_file_id_()
  , for_animated_emoji_()
  , for_clicked_animated_emoji_message_()
{}

getStickerOutline::getStickerOutline(int32 sticker_file_id_, bool for_animated_emoji_, bool for_clicked_animated_emoji_message_)
  : sticker_file_id_(sticker_file_id_)
  , for_animated_emoji_(for_animated_emoji_)
  , for_clicked_animated_emoji_message_(for_clicked_animated_emoji_message_)
{}

const std::int32_t getStickerOutline::ID;

void getStickerOutline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickerOutline");
    s.store_field("sticker_file_id", sticker_file_id_);
    s.store_field("for_animated_emoji", for_animated_emoji_);
    s.store_field("for_clicked_animated_emoji_message", for_clicked_animated_emoji_message_);
    s.store_class_end();
  }
}

getStorageStatisticsFast::getStorageStatisticsFast() {
}

const std::int32_t getStorageStatisticsFast::ID;

void getStorageStatisticsFast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStorageStatisticsFast");
    s.store_class_end();
  }
}

getThemeParametersJsonString::getThemeParametersJsonString()
  : theme_()
{}

getThemeParametersJsonString::getThemeParametersJsonString(object_ptr<themeParameters> &&theme_)
  : theme_(std::move(theme_))
{}

const std::int32_t getThemeParametersJsonString::ID;

void getThemeParametersJsonString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getThemeParametersJsonString");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

getUpgradedGiftValueInfo::getUpgradedGiftValueInfo()
  : name_()
{}

getUpgradedGiftValueInfo::getUpgradedGiftValueInfo(string const &name_)
  : name_(name_)
{}

const std::int32_t getUpgradedGiftValueInfo::ID;

void getUpgradedGiftValueInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUpgradedGiftValueInfo");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

getVideoChatAvailableParticipants::getVideoChatAvailableParticipants()
  : chat_id_()
{}

getVideoChatAvailableParticipants::getVideoChatAvailableParticipants(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getVideoChatAvailableParticipants::ID;

void getVideoChatAvailableParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getVideoChatAvailableParticipants");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getWebAppLinkUrl::getWebAppLinkUrl()
  : chat_id_()
  , bot_user_id_()
  , web_app_short_name_()
  , start_parameter_()
  , allow_write_access_()
  , parameters_()
{}

getWebAppLinkUrl::getWebAppLinkUrl(int53 chat_id_, int53 bot_user_id_, string const &web_app_short_name_, string const &start_parameter_, bool allow_write_access_, object_ptr<webAppOpenParameters> &&parameters_)
  : chat_id_(chat_id_)
  , bot_user_id_(bot_user_id_)
  , web_app_short_name_(web_app_short_name_)
  , start_parameter_(start_parameter_)
  , allow_write_access_(allow_write_access_)
  , parameters_(std::move(parameters_))
{}

const std::int32_t getWebAppLinkUrl::ID;

void getWebAppLinkUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWebAppLinkUrl");
    s.store_field("chat_id", chat_id_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("web_app_short_name", web_app_short_name_);
    s.store_field("start_parameter", start_parameter_);
    s.store_field("allow_write_access", allow_write_access_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

loadDirectMessagesChatTopics::loadDirectMessagesChatTopics()
  : chat_id_()
  , limit_()
{}

loadDirectMessagesChatTopics::loadDirectMessagesChatTopics(int53 chat_id_, int32 limit_)
  : chat_id_(chat_id_)
  , limit_(limit_)
{}

const std::int32_t loadDirectMessagesChatTopics::ID;

void loadDirectMessagesChatTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadDirectMessagesChatTopics");
    s.store_field("chat_id", chat_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

openChat::openChat()
  : chat_id_()
{}

openChat::openChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t openChat::ID;

void openChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

processChatJoinRequests::processChatJoinRequests()
  : chat_id_()
  , invite_link_()
  , approve_()
{}

processChatJoinRequests::processChatJoinRequests(int53 chat_id_, string const &invite_link_, bool approve_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , approve_(approve_)
{}

const std::int32_t processChatJoinRequests::ID;

void processChatJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processChatJoinRequests");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("approve", approve_);
    s.store_class_end();
  }
}

recoverPassword::recoverPassword()
  : recovery_code_()
  , new_password_()
  , new_hint_()
{}

recoverPassword::recoverPassword(string const &recovery_code_, string const &new_password_, string const &new_hint_)
  : recovery_code_(recovery_code_)
  , new_password_(new_password_)
  , new_hint_(new_hint_)
{}

const std::int32_t recoverPassword::ID;

void recoverPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recoverPassword");
    s.store_field("recovery_code", recovery_code_);
    s.store_field("new_password", new_password_);
    s.store_field("new_hint", new_hint_);
    s.store_class_end();
  }
}

refundStarPayment::refundStarPayment()
  : user_id_()
  , telegram_payment_charge_id_()
{}

refundStarPayment::refundStarPayment(int53 user_id_, string const &telegram_payment_charge_id_)
  : user_id_(user_id_)
  , telegram_payment_charge_id_(telegram_payment_charge_id_)
{}

const std::int32_t refundStarPayment::ID;

void refundStarPayment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "refundStarPayment");
    s.store_field("user_id", user_id_);
    s.store_field("telegram_payment_charge_id", telegram_payment_charge_id_);
    s.store_class_end();
  }
}

removeLoginPasskey::removeLoginPasskey()
  : passkey_id_()
{}

removeLoginPasskey::removeLoginPasskey(string const &passkey_id_)
  : passkey_id_(passkey_id_)
{}

const std::int32_t removeLoginPasskey::ID;

void removeLoginPasskey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeLoginPasskey");
    s.store_field("passkey_id", passkey_id_);
    s.store_class_end();
  }
}

reportChatPhoto::reportChatPhoto()
  : chat_id_()
  , file_id_()
  , reason_()
  , text_()
{}

reportChatPhoto::reportChatPhoto(int53 chat_id_, int32 file_id_, object_ptr<ReportReason> &&reason_, string const &text_)
  : chat_id_(chat_id_)
  , file_id_(file_id_)
  , reason_(std::move(reason_))
  , text_(text_)
{}

const std::int32_t reportChatPhoto::ID;

void reportChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatPhoto");
    s.store_field("chat_id", chat_id_);
    s.store_field("file_id", file_id_);
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("text", text_);
    s.store_class_end();
  }
}

reportChatSponsoredMessage::reportChatSponsoredMessage()
  : chat_id_()
  , message_id_()
  , option_id_()
{}

reportChatSponsoredMessage::reportChatSponsoredMessage(int53 chat_id_, int53 message_id_, bytes const &option_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , option_id_(std::move(option_id_))
{}

const std::int32_t reportChatSponsoredMessage::ID;

void reportChatSponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatSponsoredMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_bytes_field("option_id", option_id_);
    s.store_class_end();
  }
}

reportMessageReactions::reportMessageReactions()
  : chat_id_()
  , message_id_()
  , sender_id_()
{}

reportMessageReactions::reportMessageReactions(int53 chat_id_, int53 message_id_, object_ptr<MessageSender> &&sender_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , sender_id_(std::move(sender_id_))
{}

const std::int32_t reportMessageReactions::ID;

void reportMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportMessageReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_class_end();
  }
}

searchFileDownloads::searchFileDownloads()
  : query_()
  , only_active_()
  , only_completed_()
  , offset_()
  , limit_()
{}

searchFileDownloads::searchFileDownloads(string const &query_, bool only_active_, bool only_completed_, string const &offset_, int32 limit_)
  : query_(query_)
  , only_active_(only_active_)
  , only_completed_(only_completed_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchFileDownloads::ID;

void searchFileDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchFileDownloads");
    s.store_field("query", query_);
    s.store_field("only_active", only_active_);
    s.store_field("only_completed", only_completed_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchRecentlyFoundChats::searchRecentlyFoundChats()
  : query_()
  , limit_()
{}

searchRecentlyFoundChats::searchRecentlyFoundChats(string const &query_, int32 limit_)
  : query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchRecentlyFoundChats::ID;

void searchRecentlyFoundChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchRecentlyFoundChats");
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchStickerSet::searchStickerSet()
  : name_()
  , ignore_cache_()
{}

searchStickerSet::searchStickerSet(string const &name_, bool ignore_cache_)
  : name_(name_)
  , ignore_cache_(ignore_cache_)
{}

const std::int32_t searchStickerSet::ID;

void searchStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchStickerSet");
    s.store_field("name", name_);
    s.store_field("ignore_cache", ignore_cache_);
    s.store_class_end();
  }
}

searchStickers::searchStickers()
  : sticker_type_()
  , emojis_()
  , query_()
  , input_language_codes_()
  , offset_()
  , limit_()
{}

searchStickers::searchStickers(object_ptr<StickerType> &&sticker_type_, string const &emojis_, string const &query_, array<string> &&input_language_codes_, int32 offset_, int32 limit_)
  : sticker_type_(std::move(sticker_type_))
  , emojis_(emojis_)
  , query_(query_)
  , input_language_codes_(std::move(input_language_codes_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchStickers::ID;

void searchStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchStickers");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("emojis", emojis_);
    s.store_field("query", query_);
    { s.store_vector_begin("input_language_codes", input_language_codes_.size()); for (const auto &_value : input_language_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchStringsByPrefix::searchStringsByPrefix()
  : strings_()
  , query_()
  , limit_()
  , return_none_for_empty_query_()
{}

searchStringsByPrefix::searchStringsByPrefix(array<string> &&strings_, string const &query_, int32 limit_, bool return_none_for_empty_query_)
  : strings_(std::move(strings_))
  , query_(query_)
  , limit_(limit_)
  , return_none_for_empty_query_(return_none_for_empty_query_)
{}

const std::int32_t searchStringsByPrefix::ID;

void searchStringsByPrefix::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchStringsByPrefix");
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_field("return_none_for_empty_query", return_none_for_empty_query_);
    s.store_class_end();
  }
}

searchUserByToken::searchUserByToken()
  : token_()
{}

searchUserByToken::searchUserByToken(string const &token_)
  : token_(token_)
{}

const std::int32_t searchUserByToken::ID;

void searchUserByToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchUserByToken");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

sendWebAppCustomRequest::sendWebAppCustomRequest()
  : bot_user_id_()
  , method_()
  , parameters_()
{}

sendWebAppCustomRequest::sendWebAppCustomRequest(int53 bot_user_id_, string const &method_, string const &parameters_)
  : bot_user_id_(bot_user_id_)
  , method_(method_)
  , parameters_(parameters_)
{}

const std::int32_t sendWebAppCustomRequest::ID;

void sendWebAppCustomRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendWebAppCustomRequest");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("method", method_);
    s.store_field("parameters", parameters_);
    s.store_class_end();
  }
}

setChatDescription::setChatDescription()
  : chat_id_()
  , description_()
{}

setChatDescription::setChatDescription(int53 chat_id_, string const &description_)
  : chat_id_(chat_id_)
  , description_(description_)
{}

const std::int32_t setChatDescription::ID;

void setChatDescription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatDescription");
    s.store_field("chat_id", chat_id_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

setDatabaseEncryptionKey::setDatabaseEncryptionKey()
  : new_encryption_key_()
{}

setDatabaseEncryptionKey::setDatabaseEncryptionKey(bytes const &new_encryption_key_)
  : new_encryption_key_(std::move(new_encryption_key_))
{}

const std::int32_t setDatabaseEncryptionKey::ID;

void setDatabaseEncryptionKey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDatabaseEncryptionKey");
    s.store_bytes_field("new_encryption_key", new_encryption_key_);
    s.store_class_end();
  }
}

setDefaultChannelAdministratorRights::setDefaultChannelAdministratorRights()
  : default_channel_administrator_rights_()
{}

setDefaultChannelAdministratorRights::setDefaultChannelAdministratorRights(object_ptr<chatAdministratorRights> &&default_channel_administrator_rights_)
  : default_channel_administrator_rights_(std::move(default_channel_administrator_rights_))
{}

const std::int32_t setDefaultChannelAdministratorRights::ID;

void setDefaultChannelAdministratorRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDefaultChannelAdministratorRights");
    s.store_object_field("default_channel_administrator_rights", static_cast<const BaseObject *>(default_channel_administrator_rights_.get()));
    s.store_class_end();
  }
}

setDefaultMessageAutoDeleteTime::setDefaultMessageAutoDeleteTime()
  : message_auto_delete_time_()
{}

setDefaultMessageAutoDeleteTime::setDefaultMessageAutoDeleteTime(object_ptr<messageAutoDeleteTime> &&message_auto_delete_time_)
  : message_auto_delete_time_(std::move(message_auto_delete_time_))
{}

const std::int32_t setDefaultMessageAutoDeleteTime::ID;

void setDefaultMessageAutoDeleteTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDefaultMessageAutoDeleteTime");
    s.store_object_field("message_auto_delete_time", static_cast<const BaseObject *>(message_auto_delete_time_.get()));
    s.store_class_end();
  }
}

setGroupCallParticipantIsSpeaking::setGroupCallParticipantIsSpeaking()
  : group_call_id_()
  , audio_source_()
  , is_speaking_()
{}

setGroupCallParticipantIsSpeaking::setGroupCallParticipantIsSpeaking(int32 group_call_id_, int32 audio_source_, bool is_speaking_)
  : group_call_id_(group_call_id_)
  , audio_source_(audio_source_)
  , is_speaking_(is_speaking_)
{}

const std::int32_t setGroupCallParticipantIsSpeaking::ID;

void setGroupCallParticipantIsSpeaking::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGroupCallParticipantIsSpeaking");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("audio_source", audio_source_);
    s.store_field("is_speaking", is_speaking_);
    s.store_class_end();
  }
}

setPassword::setPassword()
  : old_password_()
  , new_password_()
  , new_hint_()
  , set_recovery_email_address_()
  , new_recovery_email_address_()
{}

setPassword::setPassword(string const &old_password_, string const &new_password_, string const &new_hint_, bool set_recovery_email_address_, string const &new_recovery_email_address_)
  : old_password_(old_password_)
  , new_password_(new_password_)
  , new_hint_(new_hint_)
  , set_recovery_email_address_(set_recovery_email_address_)
  , new_recovery_email_address_(new_recovery_email_address_)
{}

const std::int32_t setPassword::ID;

void setPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPassword");
    s.store_field("old_password", old_password_);
    s.store_field("new_password", new_password_);
    s.store_field("new_hint", new_hint_);
    s.store_field("set_recovery_email_address", set_recovery_email_address_);
    s.store_field("new_recovery_email_address", new_recovery_email_address_);
    s.store_class_end();
  }
}

setPollAnswer::setPollAnswer()
  : chat_id_()
  , message_id_()
  , option_ids_()
{}

setPollAnswer::setPollAnswer(int53 chat_id_, int53 message_id_, array<int32> &&option_ids_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , option_ids_(std::move(option_ids_))
{}

const std::int32_t setPollAnswer::ID;

void setPollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPollAnswer");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("option_ids", option_ids_.size()); for (const auto &_value : option_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setReadDatePrivacySettings::setReadDatePrivacySettings()
  : settings_()
{}

setReadDatePrivacySettings::setReadDatePrivacySettings(object_ptr<readDatePrivacySettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t setReadDatePrivacySettings::ID;

void setReadDatePrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setReadDatePrivacySettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setStoryPrivacySettings::setStoryPrivacySettings()
  : story_id_()
  , privacy_settings_()
{}

setStoryPrivacySettings::setStoryPrivacySettings(int32 story_id_, object_ptr<StoryPrivacySettings> &&privacy_settings_)
  : story_id_(story_id_)
  , privacy_settings_(std::move(privacy_settings_))
{}

const std::int32_t setStoryPrivacySettings::ID;

void setStoryPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStoryPrivacySettings");
    s.store_field("story_id", story_id_);
    s.store_object_field("privacy_settings", static_cast<const BaseObject *>(privacy_settings_.get()));
    s.store_class_end();
  }
}

setUserPrivacySettingRules::setUserPrivacySettingRules()
  : setting_()
  , rules_()
{}

setUserPrivacySettingRules::setUserPrivacySettingRules(object_ptr<UserPrivacySetting> &&setting_, object_ptr<userPrivacySettingRules> &&rules_)
  : setting_(std::move(setting_))
  , rules_(std::move(rules_))
{}

const std::int32_t setUserPrivacySettingRules::ID;

void setUserPrivacySettingRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUserPrivacySettingRules");
    s.store_object_field("setting", static_cast<const BaseObject *>(setting_.get()));
    s.store_object_field("rules", static_cast<const BaseObject *>(rules_.get()));
    s.store_class_end();
  }
}

startScheduledVideoChat::startScheduledVideoChat()
  : group_call_id_()
{}

startScheduledVideoChat::startScheduledVideoChat(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t startScheduledVideoChat::ID;

void startScheduledVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startScheduledVideoChat");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

stopPoll::stopPoll()
  : chat_id_()
  , message_id_()
  , reply_markup_()
{}

stopPoll::stopPoll(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t stopPoll::ID;

void stopPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stopPoll");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

suggestUserBirthdate::suggestUserBirthdate()
  : user_id_()
  , birthdate_()
{}

suggestUserBirthdate::suggestUserBirthdate(int53 user_id_, object_ptr<birthdate> &&birthdate_)
  : user_id_(user_id_)
  , birthdate_(std::move(birthdate_))
{}

const std::int32_t suggestUserBirthdate::ID;

void suggestUserBirthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestUserBirthdate");
    s.store_field("user_id", user_id_);
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_class_end();
  }
}

terminateSession::terminateSession()
  : session_id_()
{}

terminateSession::terminateSession(int64 session_id_)
  : session_id_(session_id_)
{}

const std::int32_t terminateSession::ID;

void terminateSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "terminateSession");
    s.store_field("session_id", session_id_);
    s.store_class_end();
  }
}

testCallVectorIntObject::testCallVectorIntObject()
  : x_()
{}

testCallVectorIntObject::testCallVectorIntObject(array<object_ptr<testInt>> &&x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallVectorIntObject::ID;

void testCallVectorIntObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallVectorIntObject");
    { s.store_vector_begin("x", x_.size()); for (const auto &_value : x_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

testCallVectorString::testCallVectorString()
  : x_()
{}

testCallVectorString::testCallVectorString(array<string> &&x_)
  : x_(std::move(x_))
{}

const std::int32_t testCallVectorString::ID;

void testCallVectorString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallVectorString");
    { s.store_vector_begin("x", x_.size()); for (const auto &_value : x_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

testProxy::testProxy()
  : proxy_()
  , dc_id_()
  , timeout_()
{}

testProxy::testProxy(object_ptr<proxy> &&proxy_, int32 dc_id_, double timeout_)
  : proxy_(std::move(proxy_))
  , dc_id_(dc_id_)
  , timeout_(timeout_)
{}

const std::int32_t testProxy::ID;

void testProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testProxy");
    s.store_object_field("proxy", static_cast<const BaseObject *>(proxy_.get()));
    s.store_field("dc_id", dc_id_);
    s.store_field("timeout", timeout_);
    s.store_class_end();
  }
}

testReturnError::testReturnError()
  : error_()
{}

testReturnError::testReturnError(object_ptr<error> &&error_)
  : error_(std::move(error_))
{}

const std::int32_t testReturnError::ID;

void testReturnError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testReturnError");
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

testUseUpdate::testUseUpdate() {
}

const std::int32_t testUseUpdate::ID;

void testUseUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testUseUpdate");
    s.store_class_end();
  }
}

toggleChatHasProtectedContent::toggleChatHasProtectedContent()
  : chat_id_()
  , has_protected_content_()
{}

toggleChatHasProtectedContent::toggleChatHasProtectedContent(int53 chat_id_, bool has_protected_content_)
  : chat_id_(chat_id_)
  , has_protected_content_(has_protected_content_)
{}

const std::int32_t toggleChatHasProtectedContent::ID;

void toggleChatHasProtectedContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatHasProtectedContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("has_protected_content", has_protected_content_);
    s.store_class_end();
  }
}

toggleDirectMessagesChatTopicCanSendUnpaidMessages::toggleDirectMessagesChatTopicCanSendUnpaidMessages()
  : chat_id_()
  , topic_id_()
  , can_send_unpaid_messages_()
  , refund_payments_()
{}

toggleDirectMessagesChatTopicCanSendUnpaidMessages::toggleDirectMessagesChatTopicCanSendUnpaidMessages(int53 chat_id_, int53 topic_id_, bool can_send_unpaid_messages_, bool refund_payments_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
  , can_send_unpaid_messages_(can_send_unpaid_messages_)
  , refund_payments_(refund_payments_)
{}

const std::int32_t toggleDirectMessagesChatTopicCanSendUnpaidMessages::ID;

void toggleDirectMessagesChatTopicCanSendUnpaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleDirectMessagesChatTopicCanSendUnpaidMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_field("can_send_unpaid_messages", can_send_unpaid_messages_);
    s.store_field("refund_payments", refund_payments_);
    s.store_class_end();
  }
}

toggleGroupCallIsMyVideoPaused::toggleGroupCallIsMyVideoPaused()
  : group_call_id_()
  , is_my_video_paused_()
{}

toggleGroupCallIsMyVideoPaused::toggleGroupCallIsMyVideoPaused(int32 group_call_id_, bool is_my_video_paused_)
  : group_call_id_(group_call_id_)
  , is_my_video_paused_(is_my_video_paused_)
{}

const std::int32_t toggleGroupCallIsMyVideoPaused::ID;

void toggleGroupCallIsMyVideoPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallIsMyVideoPaused");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("is_my_video_paused", is_my_video_paused_);
    s.store_class_end();
  }
}

toggleSessionCanAcceptCalls::toggleSessionCanAcceptCalls()
  : session_id_()
  , can_accept_calls_()
{}

toggleSessionCanAcceptCalls::toggleSessionCanAcceptCalls(int64 session_id_, bool can_accept_calls_)
  : session_id_(session_id_)
  , can_accept_calls_(can_accept_calls_)
{}

const std::int32_t toggleSessionCanAcceptCalls::ID;

void toggleSessionCanAcceptCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSessionCanAcceptCalls");
    s.store_field("session_id", session_id_);
    s.store_field("can_accept_calls", can_accept_calls_);
    s.store_class_end();
  }
}

toggleSupergroupHasHiddenMembers::toggleSupergroupHasHiddenMembers()
  : supergroup_id_()
  , has_hidden_members_()
{}

toggleSupergroupHasHiddenMembers::toggleSupergroupHasHiddenMembers(int53 supergroup_id_, bool has_hidden_members_)
  : supergroup_id_(supergroup_id_)
  , has_hidden_members_(has_hidden_members_)
{}

const std::int32_t toggleSupergroupHasHiddenMembers::ID;

void toggleSupergroupHasHiddenMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupHasHiddenMembers");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("has_hidden_members", has_hidden_members_);
    s.store_class_end();
  }
}

unpinChatMessage::unpinChatMessage()
  : chat_id_()
  , message_id_()
{}

unpinChatMessage::unpinChatMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t unpinChatMessage::ID;

void unpinChatMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unpinChatMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

viewPremiumFeature::viewPremiumFeature()
  : feature_()
{}

viewPremiumFeature::viewPremiumFeature(object_ptr<PremiumFeature> &&feature_)
  : feature_(std::move(feature_))
{}

const std::int32_t viewPremiumFeature::ID;

void viewPremiumFeature::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "viewPremiumFeature");
    s.store_object_field("feature", static_cast<const BaseObject *>(feature_.get()));
    s.store_class_end();
  }
}

viewVideoMessageAdvertisement::viewVideoMessageAdvertisement()
  : advertisement_unique_id_()
{}

viewVideoMessageAdvertisement::viewVideoMessageAdvertisement(int53 advertisement_unique_id_)
  : advertisement_unique_id_(advertisement_unique_id_)
{}

const std::int32_t viewVideoMessageAdvertisement::ID;

void viewVideoMessageAdvertisement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "viewVideoMessageAdvertisement");
    s.store_field("advertisement_unique_id", advertisement_unique_id_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
