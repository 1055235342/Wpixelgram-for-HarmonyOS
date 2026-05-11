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


animatedEmoji::animatedEmoji()
  : sticker_()
  , sticker_width_()
  , sticker_height_()
  , fitzpatrick_type_()
  , sound_()
{}

animatedEmoji::animatedEmoji(object_ptr<sticker> &&sticker_, int32 sticker_width_, int32 sticker_height_, int32 fitzpatrick_type_, object_ptr<file> &&sound_)
  : sticker_(std::move(sticker_))
  , sticker_width_(sticker_width_)
  , sticker_height_(sticker_height_)
  , fitzpatrick_type_(fitzpatrick_type_)
  , sound_(std::move(sound_))
{}

const std::int32_t animatedEmoji::ID;

void animatedEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "animatedEmoji");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("sticker_width", sticker_width_);
    s.store_field("sticker_height", sticker_height_);
    s.store_field("fitzpatrick_type", fitzpatrick_type_);
    s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get()));
    s.store_class_end();
  }
}

archiveChatListSettings::archiveChatListSettings()
  : archive_and_mute_new_chats_from_unknown_users_()
  , keep_unmuted_chats_archived_()
  , keep_chats_from_folders_archived_()
{}

archiveChatListSettings::archiveChatListSettings(bool archive_and_mute_new_chats_from_unknown_users_, bool keep_unmuted_chats_archived_, bool keep_chats_from_folders_archived_)
  : archive_and_mute_new_chats_from_unknown_users_(archive_and_mute_new_chats_from_unknown_users_)
  , keep_unmuted_chats_archived_(keep_unmuted_chats_archived_)
  , keep_chats_from_folders_archived_(keep_chats_from_folders_archived_)
{}

const std::int32_t archiveChatListSettings::ID;

void archiveChatListSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "archiveChatListSettings");
    s.store_field("archive_and_mute_new_chats_from_unknown_users", archive_and_mute_new_chats_from_unknown_users_);
    s.store_field("keep_unmuted_chats_archived", keep_unmuted_chats_archived_);
    s.store_field("keep_chats_from_folders_archived", keep_chats_from_folders_archived_);
    s.store_class_end();
  }
}

autosaveSettingsException::autosaveSettingsException()
  : chat_id_()
  , settings_()
{}

autosaveSettingsException::autosaveSettingsException(int53 chat_id_, object_ptr<scopeAutosaveSettings> &&settings_)
  : chat_id_(chat_id_)
  , settings_(std::move(settings_))
{}

const std::int32_t autosaveSettingsException::ID;

void autosaveSettingsException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autosaveSettingsException");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

availableGifts::availableGifts()
  : gifts_()
{}

availableGifts::availableGifts(array<object_ptr<availableGift>> &&gifts_)
  : gifts_(std::move(gifts_))
{}

const std::int32_t availableGifts::ID;

void availableGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableGifts");
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

blockListMain::blockListMain() {
}

const std::int32_t blockListMain::ID;

void blockListMain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "blockListMain");
    s.store_class_end();
  }
}

blockListStories::blockListStories() {
}

const std::int32_t blockListStories::ID;

void blockListStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "blockListStories");
    s.store_class_end();
  }
}

businessAwayMessageScheduleAlways::businessAwayMessageScheduleAlways() {
}

const std::int32_t businessAwayMessageScheduleAlways::ID;

void businessAwayMessageScheduleAlways::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageScheduleAlways");
    s.store_class_end();
  }
}

businessAwayMessageScheduleOutsideOfOpeningHours::businessAwayMessageScheduleOutsideOfOpeningHours() {
}

const std::int32_t businessAwayMessageScheduleOutsideOfOpeningHours::ID;

void businessAwayMessageScheduleOutsideOfOpeningHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageScheduleOutsideOfOpeningHours");
    s.store_class_end();
  }
}

businessAwayMessageScheduleCustom::businessAwayMessageScheduleCustom()
  : start_date_()
  , end_date_()
{}

businessAwayMessageScheduleCustom::businessAwayMessageScheduleCustom(int32 start_date_, int32 end_date_)
  : start_date_(start_date_)
  , end_date_(end_date_)
{}

const std::int32_t businessAwayMessageScheduleCustom::ID;

void businessAwayMessageScheduleCustom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageScheduleCustom");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_class_end();
  }
}

buttonStyleDefault::buttonStyleDefault() {
}

const std::int32_t buttonStyleDefault::ID;

void buttonStyleDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonStyleDefault");
    s.store_class_end();
  }
}

buttonStylePrimary::buttonStylePrimary() {
}

const std::int32_t buttonStylePrimary::ID;

void buttonStylePrimary::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonStylePrimary");
    s.store_class_end();
  }
}

buttonStyleDanger::buttonStyleDanger() {
}

const std::int32_t buttonStyleDanger::ID;

void buttonStyleDanger::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonStyleDanger");
    s.store_class_end();
  }
}

buttonStyleSuccess::buttonStyleSuccess() {
}

const std::int32_t buttonStyleSuccess::ID;

void buttonStyleSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buttonStyleSuccess");
    s.store_class_end();
  }
}

canSendMessageToUserResultOk::canSendMessageToUserResultOk() {
}

const std::int32_t canSendMessageToUserResultOk::ID;

void canSendMessageToUserResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendMessageToUserResultOk");
    s.store_class_end();
  }
}

canSendMessageToUserResultUserHasPaidMessages::canSendMessageToUserResultUserHasPaidMessages()
  : outgoing_paid_message_star_count_()
{}

canSendMessageToUserResultUserHasPaidMessages::canSendMessageToUserResultUserHasPaidMessages(int53 outgoing_paid_message_star_count_)
  : outgoing_paid_message_star_count_(outgoing_paid_message_star_count_)
{}

const std::int32_t canSendMessageToUserResultUserHasPaidMessages::ID;

void canSendMessageToUserResultUserHasPaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendMessageToUserResultUserHasPaidMessages");
    s.store_field("outgoing_paid_message_star_count", outgoing_paid_message_star_count_);
    s.store_class_end();
  }
}

canSendMessageToUserResultUserIsDeleted::canSendMessageToUserResultUserIsDeleted() {
}

const std::int32_t canSendMessageToUserResultUserIsDeleted::ID;

void canSendMessageToUserResultUserIsDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendMessageToUserResultUserIsDeleted");
    s.store_class_end();
  }
}

canSendMessageToUserResultUserRestrictsNewChats::canSendMessageToUserResultUserRestrictsNewChats() {
}

const std::int32_t canSendMessageToUserResultUserRestrictsNewChats::ID;

void canSendMessageToUserResultUserRestrictsNewChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendMessageToUserResultUserRestrictsNewChats");
    s.store_class_end();
  }
}

chatAvailableReactionsAll::chatAvailableReactionsAll()
  : max_reaction_count_()
{}

chatAvailableReactionsAll::chatAvailableReactionsAll(int32 max_reaction_count_)
  : max_reaction_count_(max_reaction_count_)
{}

const std::int32_t chatAvailableReactionsAll::ID;

void chatAvailableReactionsAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAvailableReactionsAll");
    s.store_field("max_reaction_count", max_reaction_count_);
    s.store_class_end();
  }
}

chatAvailableReactionsSome::chatAvailableReactionsSome()
  : reactions_()
  , max_reaction_count_()
{}

chatAvailableReactionsSome::chatAvailableReactionsSome(array<object_ptr<ReactionType>> &&reactions_, int32 max_reaction_count_)
  : reactions_(std::move(reactions_))
  , max_reaction_count_(max_reaction_count_)
{}

const std::int32_t chatAvailableReactionsSome::ID;

void chatAvailableReactionsSome::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAvailableReactionsSome");
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("max_reaction_count", max_reaction_count_);
    s.store_class_end();
  }
}

chatMembersFilterContacts::chatMembersFilterContacts() {
}

const std::int32_t chatMembersFilterContacts::ID;

void chatMembersFilterContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterContacts");
    s.store_class_end();
  }
}

chatMembersFilterAdministrators::chatMembersFilterAdministrators() {
}

const std::int32_t chatMembersFilterAdministrators::ID;

void chatMembersFilterAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterAdministrators");
    s.store_class_end();
  }
}

chatMembersFilterMembers::chatMembersFilterMembers() {
}

const std::int32_t chatMembersFilterMembers::ID;

void chatMembersFilterMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterMembers");
    s.store_class_end();
  }
}

chatMembersFilterMention::chatMembersFilterMention()
  : topic_id_()
{}

chatMembersFilterMention::chatMembersFilterMention(object_ptr<MessageTopic> &&topic_id_)
  : topic_id_(std::move(topic_id_))
{}

const std::int32_t chatMembersFilterMention::ID;

void chatMembersFilterMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterMention");
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_class_end();
  }
}

chatMembersFilterRestricted::chatMembersFilterRestricted() {
}

const std::int32_t chatMembersFilterRestricted::ID;

void chatMembersFilterRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterRestricted");
    s.store_class_end();
  }
}

chatMembersFilterBanned::chatMembersFilterBanned() {
}

const std::int32_t chatMembersFilterBanned::ID;

void chatMembersFilterBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterBanned");
    s.store_class_end();
  }
}

chatMembersFilterBots::chatMembersFilterBots() {
}

const std::int32_t chatMembersFilterBots::ID;

void chatMembersFilterBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMembersFilterBots");
    s.store_class_end();
  }
}

chatNotificationSettings::chatNotificationSettings()
  : use_default_mute_for_()
  , mute_for_()
  , use_default_sound_()
  , sound_id_()
  , use_default_show_preview_()
  , show_preview_()
  , use_default_mute_stories_()
  , mute_stories_()
  , use_default_story_sound_()
  , story_sound_id_()
  , use_default_show_story_poster_()
  , show_story_poster_()
  , use_default_disable_pinned_message_notifications_()
  , disable_pinned_message_notifications_()
  , use_default_disable_mention_notifications_()
  , disable_mention_notifications_()
{}

chatNotificationSettings::chatNotificationSettings(bool use_default_mute_for_, int32 mute_for_, bool use_default_sound_, int64 sound_id_, bool use_default_show_preview_, bool show_preview_, bool use_default_mute_stories_, bool mute_stories_, bool use_default_story_sound_, int64 story_sound_id_, bool use_default_show_story_poster_, bool show_story_poster_, bool use_default_disable_pinned_message_notifications_, bool disable_pinned_message_notifications_, bool use_default_disable_mention_notifications_, bool disable_mention_notifications_)
  : use_default_mute_for_(use_default_mute_for_)
  , mute_for_(mute_for_)
  , use_default_sound_(use_default_sound_)
  , sound_id_(sound_id_)
  , use_default_show_preview_(use_default_show_preview_)
  , show_preview_(show_preview_)
  , use_default_mute_stories_(use_default_mute_stories_)
  , mute_stories_(mute_stories_)
  , use_default_story_sound_(use_default_story_sound_)
  , story_sound_id_(story_sound_id_)
  , use_default_show_story_poster_(use_default_show_story_poster_)
  , show_story_poster_(show_story_poster_)
  , use_default_disable_pinned_message_notifications_(use_default_disable_pinned_message_notifications_)
  , disable_pinned_message_notifications_(disable_pinned_message_notifications_)
  , use_default_disable_mention_notifications_(use_default_disable_mention_notifications_)
  , disable_mention_notifications_(disable_mention_notifications_)
{}

const std::int32_t chatNotificationSettings::ID;

void chatNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatNotificationSettings");
    s.store_field("use_default_mute_for", use_default_mute_for_);
    s.store_field("mute_for", mute_for_);
    s.store_field("use_default_sound", use_default_sound_);
    s.store_field("sound_id", sound_id_);
    s.store_field("use_default_show_preview", use_default_show_preview_);
    s.store_field("show_preview", show_preview_);
    s.store_field("use_default_mute_stories", use_default_mute_stories_);
    s.store_field("mute_stories", mute_stories_);
    s.store_field("use_default_story_sound", use_default_story_sound_);
    s.store_field("story_sound_id", story_sound_id_);
    s.store_field("use_default_show_story_poster", use_default_show_story_poster_);
    s.store_field("show_story_poster", show_story_poster_);
    s.store_field("use_default_disable_pinned_message_notifications", use_default_disable_pinned_message_notifications_);
    s.store_field("disable_pinned_message_notifications", disable_pinned_message_notifications_);
    s.store_field("use_default_disable_mention_notifications", use_default_disable_mention_notifications_);
    s.store_field("disable_mention_notifications", disable_mention_notifications_);
    s.store_class_end();
  }
}

chatPhotos::chatPhotos()
  : total_count_()
  , photos_()
{}

chatPhotos::chatPhotos(int32 total_count_, array<object_ptr<chatPhoto>> &&photos_)
  : total_count_(total_count_)
  , photos_(std::move(photos_))
{}

const std::int32_t chatPhotos::ID;

void chatPhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotos");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("photos", photos_.size()); for (const auto &_value : photos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

checkChatUsernameResultOk::checkChatUsernameResultOk() {
}

const std::int32_t checkChatUsernameResultOk::ID;

void checkChatUsernameResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultOk");
    s.store_class_end();
  }
}

checkChatUsernameResultUsernameInvalid::checkChatUsernameResultUsernameInvalid() {
}

const std::int32_t checkChatUsernameResultUsernameInvalid::ID;

void checkChatUsernameResultUsernameInvalid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultUsernameInvalid");
    s.store_class_end();
  }
}

checkChatUsernameResultUsernameOccupied::checkChatUsernameResultUsernameOccupied() {
}

const std::int32_t checkChatUsernameResultUsernameOccupied::ID;

void checkChatUsernameResultUsernameOccupied::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultUsernameOccupied");
    s.store_class_end();
  }
}

checkChatUsernameResultUsernamePurchasable::checkChatUsernameResultUsernamePurchasable() {
}

const std::int32_t checkChatUsernameResultUsernamePurchasable::ID;

void checkChatUsernameResultUsernamePurchasable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultUsernamePurchasable");
    s.store_class_end();
  }
}

checkChatUsernameResultPublicChatsTooMany::checkChatUsernameResultPublicChatsTooMany() {
}

const std::int32_t checkChatUsernameResultPublicChatsTooMany::ID;

void checkChatUsernameResultPublicChatsTooMany::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultPublicChatsTooMany");
    s.store_class_end();
  }
}

checkChatUsernameResultPublicGroupsUnavailable::checkChatUsernameResultPublicGroupsUnavailable() {
}

const std::int32_t checkChatUsernameResultPublicGroupsUnavailable::ID;

void checkChatUsernameResultPublicGroupsUnavailable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsernameResultPublicGroupsUnavailable");
    s.store_class_end();
  }
}

emojiCategorySourceSearch::emojiCategorySourceSearch()
  : emojis_()
{}

emojiCategorySourceSearch::emojiCategorySourceSearch(array<string> &&emojis_)
  : emojis_(std::move(emojis_))
{}

const std::int32_t emojiCategorySourceSearch::ID;

void emojiCategorySourceSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategorySourceSearch");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

emojiCategorySourcePremium::emojiCategorySourcePremium() {
}

const std::int32_t emojiCategorySourcePremium::ID;

void emojiCategorySourcePremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategorySourcePremium");
    s.store_class_end();
  }
}

fixedText::fixedText()
  : text_()
  , diff_text_()
{}

fixedText::fixedText(object_ptr<formattedText> &&text_, object_ptr<diffText> &&diff_text_)
  : text_(std::move(text_))
  , diff_text_(std::move(diff_text_))
{}

const std::int32_t fixedText::ID;

void fixedText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fixedText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("diff_text", static_cast<const BaseObject *>(diff_text_.get()));
    s.store_class_end();
  }
}

forwardSource::forwardSource()
  : chat_id_()
  , message_id_()
  , sender_id_()
  , sender_name_()
  , date_()
  , is_outgoing_()
{}

forwardSource::forwardSource(int53 chat_id_, int53 message_id_, object_ptr<MessageSender> &&sender_id_, string const &sender_name_, int32 date_, bool is_outgoing_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , sender_id_(std::move(sender_id_))
  , sender_name_(sender_name_)
  , date_(date_)
  , is_outgoing_(is_outgoing_)
{}

const std::int32_t forwardSource::ID;

void forwardSource::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forwardSource");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("sender_name", sender_name_);
    s.store_field("date", date_);
    s.store_field("is_outgoing", is_outgoing_);
    s.store_class_end();
  }
}

foundWebApp::foundWebApp()
  : web_app_()
  , request_write_access_()
  , skip_confirmation_()
{}

foundWebApp::foundWebApp(object_ptr<webApp> &&web_app_, bool request_write_access_, bool skip_confirmation_)
  : web_app_(std::move(web_app_))
  , request_write_access_(request_write_access_)
  , skip_confirmation_(skip_confirmation_)
{}

const std::int32_t foundWebApp::ID;

void foundWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundWebApp");
    s.store_object_field("web_app", static_cast<const BaseObject *>(web_app_.get()));
    s.store_field("request_write_access", request_write_access_);
    s.store_field("skip_confirmation", skip_confirmation_);
    s.store_class_end();
  }
}

giftAuctionState::giftAuctionState()
  : gift_()
  , state_()
{}

giftAuctionState::giftAuctionState(object_ptr<gift> &&gift_, object_ptr<AuctionState> &&state_)
  : gift_(std::move(gift_))
  , state_(std::move(state_))
{}

const std::int32_t giftAuctionState::ID;

void giftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftAuctionState");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

groupCall::groupCall()
  : id_()
  , unique_id_()
  , title_()
  , invite_link_()
  , paid_message_star_count_()
  , scheduled_start_date_()
  , enabled_start_notification_()
  , is_active_()
  , is_video_chat_()
  , is_live_story_()
  , is_rtmp_stream_()
  , is_joined_()
  , need_rejoin_()
  , is_owned_()
  , can_be_managed_()
  , participant_count_()
  , has_hidden_listeners_()
  , loaded_all_participants_()
  , message_sender_id_()
  , recent_speakers_()
  , is_my_video_enabled_()
  , is_my_video_paused_()
  , can_enable_video_()
  , mute_new_participants_()
  , can_toggle_mute_new_participants_()
  , can_send_messages_()
  , are_messages_allowed_()
  , can_toggle_are_messages_allowed_()
  , can_delete_messages_()
  , record_duration_()
  , is_video_recorded_()
  , duration_()
{}

groupCall::groupCall(int32 id_, int64 unique_id_, string const &title_, string const &invite_link_, int53 paid_message_star_count_, int32 scheduled_start_date_, bool enabled_start_notification_, bool is_active_, bool is_video_chat_, bool is_live_story_, bool is_rtmp_stream_, bool is_joined_, bool need_rejoin_, bool is_owned_, bool can_be_managed_, int32 participant_count_, bool has_hidden_listeners_, bool loaded_all_participants_, object_ptr<MessageSender> &&message_sender_id_, array<object_ptr<groupCallRecentSpeaker>> &&recent_speakers_, bool is_my_video_enabled_, bool is_my_video_paused_, bool can_enable_video_, bool mute_new_participants_, bool can_toggle_mute_new_participants_, bool can_send_messages_, bool are_messages_allowed_, bool can_toggle_are_messages_allowed_, bool can_delete_messages_, int32 record_duration_, bool is_video_recorded_, int32 duration_)
  : id_(id_)
  , unique_id_(unique_id_)
  , title_(title_)
  , invite_link_(invite_link_)
  , paid_message_star_count_(paid_message_star_count_)
  , scheduled_start_date_(scheduled_start_date_)
  , enabled_start_notification_(enabled_start_notification_)
  , is_active_(is_active_)
  , is_video_chat_(is_video_chat_)
  , is_live_story_(is_live_story_)
  , is_rtmp_stream_(is_rtmp_stream_)
  , is_joined_(is_joined_)
  , need_rejoin_(need_rejoin_)
  , is_owned_(is_owned_)
  , can_be_managed_(can_be_managed_)
  , participant_count_(participant_count_)
  , has_hidden_listeners_(has_hidden_listeners_)
  , loaded_all_participants_(loaded_all_participants_)
  , message_sender_id_(std::move(message_sender_id_))
  , recent_speakers_(std::move(recent_speakers_))
  , is_my_video_enabled_(is_my_video_enabled_)
  , is_my_video_paused_(is_my_video_paused_)
  , can_enable_video_(can_enable_video_)
  , mute_new_participants_(mute_new_participants_)
  , can_toggle_mute_new_participants_(can_toggle_mute_new_participants_)
  , can_send_messages_(can_send_messages_)
  , are_messages_allowed_(are_messages_allowed_)
  , can_toggle_are_messages_allowed_(can_toggle_are_messages_allowed_)
  , can_delete_messages_(can_delete_messages_)
  , record_duration_(record_duration_)
  , is_video_recorded_(is_video_recorded_)
  , duration_(duration_)
{}

const std::int32_t groupCall::ID;

void groupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCall");
    s.store_field("id", id_);
    s.store_field("unique_id", unique_id_);
    s.store_field("title", title_);
    s.store_field("invite_link", invite_link_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_field("scheduled_start_date", scheduled_start_date_);
    s.store_field("enabled_start_notification", enabled_start_notification_);
    s.store_field("is_active", is_active_);
    s.store_field("is_video_chat", is_video_chat_);
    s.store_field("is_live_story", is_live_story_);
    s.store_field("is_rtmp_stream", is_rtmp_stream_);
    s.store_field("is_joined", is_joined_);
    s.store_field("need_rejoin", need_rejoin_);
    s.store_field("is_owned", is_owned_);
    s.store_field("can_be_managed", can_be_managed_);
    s.store_field("participant_count", participant_count_);
    s.store_field("has_hidden_listeners", has_hidden_listeners_);
    s.store_field("loaded_all_participants", loaded_all_participants_);
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    { s.store_vector_begin("recent_speakers", recent_speakers_.size()); for (const auto &_value : recent_speakers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_my_video_enabled", is_my_video_enabled_);
    s.store_field("is_my_video_paused", is_my_video_paused_);
    s.store_field("can_enable_video", can_enable_video_);
    s.store_field("mute_new_participants", mute_new_participants_);
    s.store_field("can_toggle_mute_new_participants", can_toggle_mute_new_participants_);
    s.store_field("can_send_messages", can_send_messages_);
    s.store_field("are_messages_allowed", are_messages_allowed_);
    s.store_field("can_toggle_are_messages_allowed", can_toggle_are_messages_allowed_);
    s.store_field("can_delete_messages", can_delete_messages_);
    s.store_field("record_duration", record_duration_);
    s.store_field("is_video_recorded", is_video_recorded_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

groupCallRecentSpeaker::groupCallRecentSpeaker()
  : participant_id_()
  , is_speaking_()
{}

groupCallRecentSpeaker::groupCallRecentSpeaker(object_ptr<MessageSender> &&participant_id_, bool is_speaking_)
  : participant_id_(std::move(participant_id_))
  , is_speaking_(is_speaking_)
{}

const std::int32_t groupCallRecentSpeaker::ID;

void groupCallRecentSpeaker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallRecentSpeaker");
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("is_speaking", is_speaking_);
    s.store_class_end();
  }
}

inlineKeyboardButton::inlineKeyboardButton()
  : text_()
  , icon_custom_emoji_id_()
  , style_()
  , type_()
{}

inlineKeyboardButton::inlineKeyboardButton(string const &text_, int64 icon_custom_emoji_id_, object_ptr<ButtonStyle> &&style_, object_ptr<InlineKeyboardButtonType> &&type_)
  : text_(text_)
  , icon_custom_emoji_id_(icon_custom_emoji_id_)
  , style_(std::move(style_))
  , type_(std::move(type_))
{}

const std::int32_t inlineKeyboardButton::ID;

void inlineKeyboardButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineKeyboardButton");
    s.store_field("text", text_);
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_object_field("style", static_cast<const BaseObject *>(style_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

inputBusinessChatLink::inputBusinessChatLink()
  : text_()
  , title_()
{}

inputBusinessChatLink::inputBusinessChatLink(object_ptr<formattedText> &&text_, string const &title_)
  : text_(std::move(text_))
  , title_(title_)
{}

const std::int32_t inputBusinessChatLink::ID;

void inputBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessChatLink");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

inputBusinessStartPage::inputBusinessStartPage()
  : title_()
  , message_()
  , sticker_()
{}

inputBusinessStartPage::inputBusinessStartPage(string const &title_, string const &message_, object_ptr<InputFile> &&sticker_)
  : title_(title_)
  , message_(message_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t inputBusinessStartPage::ID;

void inputBusinessStartPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessStartPage");
    s.store_field("title", title_);
    s.store_field("message", message_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

inputIdentityDocument::inputIdentityDocument()
  : number_()
  , expiration_date_()
  , front_side_()
  , reverse_side_()
  , selfie_()
  , translation_()
{}

inputIdentityDocument::inputIdentityDocument(string const &number_, object_ptr<date> &&expiration_date_, object_ptr<InputFile> &&front_side_, object_ptr<InputFile> &&reverse_side_, object_ptr<InputFile> &&selfie_, array<object_ptr<InputFile>> &&translation_)
  : number_(number_)
  , expiration_date_(std::move(expiration_date_))
  , front_side_(std::move(front_side_))
  , reverse_side_(std::move(reverse_side_))
  , selfie_(std::move(selfie_))
  , translation_(std::move(translation_))
{}

const std::int32_t inputIdentityDocument::ID;

void inputIdentityDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputIdentityDocument");
    s.store_field("number", number_);
    s.store_object_field("expiration_date", static_cast<const BaseObject *>(expiration_date_.get()));
    s.store_object_field("front_side", static_cast<const BaseObject *>(front_side_.get()));
    s.store_object_field("reverse_side", static_cast<const BaseObject *>(reverse_side_.get()));
    s.store_object_field("selfie", static_cast<const BaseObject *>(selfie_.get()));
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputMessageReplyToMessage::inputMessageReplyToMessage()
  : message_id_()
  , quote_()
  , checklist_task_id_()
  , poll_option_id_()
{}

inputMessageReplyToMessage::inputMessageReplyToMessage(int53 message_id_, object_ptr<inputTextQuote> &&quote_, int32 checklist_task_id_, string const &poll_option_id_)
  : message_id_(message_id_)
  , quote_(std::move(quote_))
  , checklist_task_id_(checklist_task_id_)
  , poll_option_id_(poll_option_id_)
{}

const std::int32_t inputMessageReplyToMessage::ID;

void inputMessageReplyToMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageReplyToMessage");
    s.store_field("message_id", message_id_);
    s.store_object_field("quote", static_cast<const BaseObject *>(quote_.get()));
    s.store_field("checklist_task_id", checklist_task_id_);
    s.store_field("poll_option_id", poll_option_id_);
    s.store_class_end();
  }
}

inputMessageReplyToExternalMessage::inputMessageReplyToExternalMessage()
  : chat_id_()
  , message_id_()
  , quote_()
  , checklist_task_id_()
  , poll_option_id_()
{}

inputMessageReplyToExternalMessage::inputMessageReplyToExternalMessage(int53 chat_id_, int53 message_id_, object_ptr<inputTextQuote> &&quote_, int32 checklist_task_id_, string const &poll_option_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , quote_(std::move(quote_))
  , checklist_task_id_(checklist_task_id_)
  , poll_option_id_(poll_option_id_)
{}

const std::int32_t inputMessageReplyToExternalMessage::ID;

void inputMessageReplyToExternalMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageReplyToExternalMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("quote", static_cast<const BaseObject *>(quote_.get()));
    s.store_field("checklist_task_id", checklist_task_id_);
    s.store_field("poll_option_id", poll_option_id_);
    s.store_class_end();
  }
}

inputMessageReplyToStory::inputMessageReplyToStory()
  : story_poster_chat_id_()
  , story_id_()
{}

inputMessageReplyToStory::inputMessageReplyToStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t inputMessageReplyToStory::ID;

void inputMessageReplyToStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageReplyToStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

jsonObjectMember::jsonObjectMember()
  : key_()
  , value_()
{}

jsonObjectMember::jsonObjectMember(string const &key_, object_ptr<JsonValue> &&value_)
  : key_(key_)
  , value_(std::move(value_))
{}

const std::int32_t jsonObjectMember::ID;

void jsonObjectMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonObjectMember");
    s.store_field("key", key_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

linkPreviewOptions::linkPreviewOptions()
  : is_disabled_()
  , url_()
  , force_small_media_()
  , force_large_media_()
  , show_above_text_()
{}

linkPreviewOptions::linkPreviewOptions(bool is_disabled_, string const &url_, bool force_small_media_, bool force_large_media_, bool show_above_text_)
  : is_disabled_(is_disabled_)
  , url_(url_)
  , force_small_media_(force_small_media_)
  , force_large_media_(force_large_media_)
  , show_above_text_(show_above_text_)
{}

const std::int32_t linkPreviewOptions::ID;

void linkPreviewOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewOptions");
    s.store_field("is_disabled", is_disabled_);
    s.store_field("url", url_);
    s.store_field("force_small_media", force_small_media_);
    s.store_field("force_large_media", force_large_media_);
    s.store_field("show_above_text", show_above_text_);
    s.store_class_end();
  }
}

mainWebApp::mainWebApp()
  : url_()
  , mode_()
{}

mainWebApp::mainWebApp(string const &url_, object_ptr<WebAppOpenMode> &&mode_)
  : url_(url_)
  , mode_(std::move(mode_))
{}

const std::int32_t mainWebApp::ID;

void mainWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mainWebApp");
    s.store_field("url", url_);
    s.store_object_field("mode", static_cast<const BaseObject *>(mode_.get()));
    s.store_class_end();
  }
}

messageLinkInfo::messageLinkInfo()
  : is_public_()
  , chat_id_()
  , topic_id_()
  , message_()
  , media_timestamp_()
  , checklist_task_id_()
  , poll_option_id_()
  , for_album_()
{}

messageLinkInfo::messageLinkInfo(bool is_public_, int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<message> &&message_, int32 media_timestamp_, int32 checklist_task_id_, string const &poll_option_id_, bool for_album_)
  : is_public_(is_public_)
  , chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , message_(std::move(message_))
  , media_timestamp_(media_timestamp_)
  , checklist_task_id_(checklist_task_id_)
  , poll_option_id_(poll_option_id_)
  , for_album_(for_album_)
{}

const std::int32_t messageLinkInfo::ID;

void messageLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageLinkInfo");
    s.store_field("is_public", is_public_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("media_timestamp", media_timestamp_);
    s.store_field("checklist_task_id", checklist_task_id_);
    s.store_field("poll_option_id", poll_option_id_);
    s.store_field("for_album", for_album_);
    s.store_class_end();
  }
}

messageReadDateRead::messageReadDateRead()
  : read_date_()
{}

messageReadDateRead::messageReadDateRead(int32 read_date_)
  : read_date_(read_date_)
{}

const std::int32_t messageReadDateRead::ID;

void messageReadDateRead::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReadDateRead");
    s.store_field("read_date", read_date_);
    s.store_class_end();
  }
}

messageReadDateUnread::messageReadDateUnread() {
}

const std::int32_t messageReadDateUnread::ID;

void messageReadDateUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReadDateUnread");
    s.store_class_end();
  }
}

messageReadDateTooOld::messageReadDateTooOld() {
}

const std::int32_t messageReadDateTooOld::ID;

void messageReadDateTooOld::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReadDateTooOld");
    s.store_class_end();
  }
}

messageReadDateUserPrivacyRestricted::messageReadDateUserPrivacyRestricted() {
}

const std::int32_t messageReadDateUserPrivacyRestricted::ID;

void messageReadDateUserPrivacyRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReadDateUserPrivacyRestricted");
    s.store_class_end();
  }
}

messageReadDateMyPrivacyRestricted::messageReadDateMyPrivacyRestricted() {
}

const std::int32_t messageReadDateMyPrivacyRestricted::ID;

void messageReadDateMyPrivacyRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReadDateMyPrivacyRestricted");
    s.store_class_end();
  }
}

messageReplyInfo::messageReplyInfo()
  : reply_count_()
  , recent_replier_ids_()
  , last_read_inbox_message_id_()
  , last_read_outbox_message_id_()
  , last_message_id_()
{}

messageReplyInfo::messageReplyInfo(int32 reply_count_, array<object_ptr<MessageSender>> &&recent_replier_ids_, int53 last_read_inbox_message_id_, int53 last_read_outbox_message_id_, int53 last_message_id_)
  : reply_count_(reply_count_)
  , recent_replier_ids_(std::move(recent_replier_ids_))
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
  , last_message_id_(last_message_id_)
{}

const std::int32_t messageReplyInfo::ID;

void messageReplyInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplyInfo");
    s.store_field("reply_count", reply_count_);
    { s.store_vector_begin("recent_replier_ids", recent_replier_ids_.size()); for (const auto &_value : recent_replier_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_field("last_message_id", last_message_id_);
    s.store_class_end();
  }
}

messageReplyToMessage::messageReplyToMessage()
  : chat_id_()
  , message_id_()
  , quote_()
  , checklist_task_id_()
  , poll_option_id_()
  , origin_()
  , origin_send_date_()
  , content_()
{}

messageReplyToMessage::messageReplyToMessage(int53 chat_id_, int53 message_id_, object_ptr<textQuote> &&quote_, int32 checklist_task_id_, string const &poll_option_id_, object_ptr<MessageOrigin> &&origin_, int32 origin_send_date_, object_ptr<MessageContent> &&content_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , quote_(std::move(quote_))
  , checklist_task_id_(checklist_task_id_)
  , poll_option_id_(poll_option_id_)
  , origin_(std::move(origin_))
  , origin_send_date_(origin_send_date_)
  , content_(std::move(content_))
{}

const std::int32_t messageReplyToMessage::ID;

void messageReplyToMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplyToMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("quote", static_cast<const BaseObject *>(quote_.get()));
    s.store_field("checklist_task_id", checklist_task_id_);
    s.store_field("poll_option_id", poll_option_id_);
    s.store_object_field("origin", static_cast<const BaseObject *>(origin_.get()));
    s.store_field("origin_send_date", origin_send_date_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

messageReplyToStory::messageReplyToStory()
  : story_poster_chat_id_()
  , story_id_()
{}

messageReplyToStory::messageReplyToStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t messageReplyToStory::ID;

void messageReplyToStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplyToStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

messageSendOptions::messageSendOptions()
  : suggested_post_info_()
  , disable_notification_()
  , from_background_()
  , protect_content_()
  , allow_paid_broadcast_()
  , paid_message_star_count_()
  , update_order_of_installed_sticker_sets_()
  , scheduling_state_()
  , effect_id_()
  , sending_id_()
  , only_preview_()
{}

messageSendOptions::messageSendOptions(object_ptr<inputSuggestedPostInfo> &&suggested_post_info_, bool disable_notification_, bool from_background_, bool protect_content_, bool allow_paid_broadcast_, int53 paid_message_star_count_, bool update_order_of_installed_sticker_sets_, object_ptr<MessageSchedulingState> &&scheduling_state_, int64 effect_id_, int32 sending_id_, bool only_preview_)
  : suggested_post_info_(std::move(suggested_post_info_))
  , disable_notification_(disable_notification_)
  , from_background_(from_background_)
  , protect_content_(protect_content_)
  , allow_paid_broadcast_(allow_paid_broadcast_)
  , paid_message_star_count_(paid_message_star_count_)
  , update_order_of_installed_sticker_sets_(update_order_of_installed_sticker_sets_)
  , scheduling_state_(std::move(scheduling_state_))
  , effect_id_(effect_id_)
  , sending_id_(sending_id_)
  , only_preview_(only_preview_)
{}

const std::int32_t messageSendOptions::ID;

void messageSendOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSendOptions");
    s.store_object_field("suggested_post_info", static_cast<const BaseObject *>(suggested_post_info_.get()));
    s.store_field("disable_notification", disable_notification_);
    s.store_field("from_background", from_background_);
    s.store_field("protect_content", protect_content_);
    s.store_field("allow_paid_broadcast", allow_paid_broadcast_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_field("update_order_of_installed_sticker_sets", update_order_of_installed_sticker_sets_);
    s.store_object_field("scheduling_state", static_cast<const BaseObject *>(scheduling_state_.get()));
    s.store_field("effect_id", effect_id_);
    s.store_field("sending_id", sending_id_);
    s.store_field("only_preview", only_preview_);
    s.store_class_end();
  }
}

messageTopicThread::messageTopicThread()
  : message_thread_id_()
{}

messageTopicThread::messageTopicThread(int53 message_thread_id_)
  : message_thread_id_(message_thread_id_)
{}

const std::int32_t messageTopicThread::ID;

void messageTopicThread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageTopicThread");
    s.store_field("message_thread_id", message_thread_id_);
    s.store_class_end();
  }
}

messageTopicForum::messageTopicForum()
  : forum_topic_id_()
{}

messageTopicForum::messageTopicForum(int32 forum_topic_id_)
  : forum_topic_id_(forum_topic_id_)
{}

const std::int32_t messageTopicForum::ID;

void messageTopicForum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageTopicForum");
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

messageTopicDirectMessages::messageTopicDirectMessages()
  : direct_messages_chat_topic_id_()
{}

messageTopicDirectMessages::messageTopicDirectMessages(int53 direct_messages_chat_topic_id_)
  : direct_messages_chat_topic_id_(direct_messages_chat_topic_id_)
{}

const std::int32_t messageTopicDirectMessages::ID;

void messageTopicDirectMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageTopicDirectMessages");
    s.store_field("direct_messages_chat_topic_id", direct_messages_chat_topic_id_);
    s.store_class_end();
  }
}

messageTopicSavedMessages::messageTopicSavedMessages()
  : saved_messages_topic_id_()
{}

messageTopicSavedMessages::messageTopicSavedMessages(int53 saved_messages_topic_id_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
{}

const std::int32_t messageTopicSavedMessages::ID;

void messageTopicSavedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageTopicSavedMessages");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_class_end();
  }
}

notification::notification()
  : id_()
  , date_()
  , is_silent_()
  , type_()
{}

notification::notification(int32 id_, int32 date_, bool is_silent_, object_ptr<NotificationType> &&type_)
  : id_(id_)
  , date_(date_)
  , is_silent_(is_silent_)
  , type_(std::move(type_))
{}

const std::int32_t notification::ID;

void notification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notification");
    s.store_field("id", id_);
    s.store_field("date", date_);
    s.store_field("is_silent", is_silent_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

passkeys::passkeys()
  : passkeys_()
{}

passkeys::passkeys(array<object_ptr<passkey>> &&passkeys_)
  : passkeys_(std::move(passkeys_))
{}

const std::int32_t passkeys::ID;

void passkeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passkeys");
    { s.store_vector_begin("passkeys", passkeys_.size()); for (const auto &_value : passkeys_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

premiumLimitTypeSupergroupCount::premiumLimitTypeSupergroupCount() {
}

const std::int32_t premiumLimitTypeSupergroupCount::ID;

void premiumLimitTypeSupergroupCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeSupergroupCount");
    s.store_class_end();
  }
}

premiumLimitTypePinnedChatCount::premiumLimitTypePinnedChatCount() {
}

const std::int32_t premiumLimitTypePinnedChatCount::ID;

void premiumLimitTypePinnedChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypePinnedChatCount");
    s.store_class_end();
  }
}

premiumLimitTypeCreatedPublicChatCount::premiumLimitTypeCreatedPublicChatCount() {
}

const std::int32_t premiumLimitTypeCreatedPublicChatCount::ID;

void premiumLimitTypeCreatedPublicChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeCreatedPublicChatCount");
    s.store_class_end();
  }
}

premiumLimitTypeSavedAnimationCount::premiumLimitTypeSavedAnimationCount() {
}

const std::int32_t premiumLimitTypeSavedAnimationCount::ID;

void premiumLimitTypeSavedAnimationCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeSavedAnimationCount");
    s.store_class_end();
  }
}

premiumLimitTypeFavoriteStickerCount::premiumLimitTypeFavoriteStickerCount() {
}

const std::int32_t premiumLimitTypeFavoriteStickerCount::ID;

void premiumLimitTypeFavoriteStickerCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeFavoriteStickerCount");
    s.store_class_end();
  }
}

premiumLimitTypeChatFolderCount::premiumLimitTypeChatFolderCount() {
}

const std::int32_t premiumLimitTypeChatFolderCount::ID;

void premiumLimitTypeChatFolderCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeChatFolderCount");
    s.store_class_end();
  }
}

premiumLimitTypeChatFolderChosenChatCount::premiumLimitTypeChatFolderChosenChatCount() {
}

const std::int32_t premiumLimitTypeChatFolderChosenChatCount::ID;

void premiumLimitTypeChatFolderChosenChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeChatFolderChosenChatCount");
    s.store_class_end();
  }
}

premiumLimitTypePinnedArchivedChatCount::premiumLimitTypePinnedArchivedChatCount() {
}

const std::int32_t premiumLimitTypePinnedArchivedChatCount::ID;

void premiumLimitTypePinnedArchivedChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypePinnedArchivedChatCount");
    s.store_class_end();
  }
}

premiumLimitTypePinnedSavedMessagesTopicCount::premiumLimitTypePinnedSavedMessagesTopicCount() {
}

const std::int32_t premiumLimitTypePinnedSavedMessagesTopicCount::ID;

void premiumLimitTypePinnedSavedMessagesTopicCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypePinnedSavedMessagesTopicCount");
    s.store_class_end();
  }
}

premiumLimitTypeCaptionLength::premiumLimitTypeCaptionLength() {
}

const std::int32_t premiumLimitTypeCaptionLength::ID;

void premiumLimitTypeCaptionLength::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeCaptionLength");
    s.store_class_end();
  }
}

premiumLimitTypeBioLength::premiumLimitTypeBioLength() {
}

const std::int32_t premiumLimitTypeBioLength::ID;

void premiumLimitTypeBioLength::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeBioLength");
    s.store_class_end();
  }
}

premiumLimitTypeChatFolderInviteLinkCount::premiumLimitTypeChatFolderInviteLinkCount() {
}

const std::int32_t premiumLimitTypeChatFolderInviteLinkCount::ID;

void premiumLimitTypeChatFolderInviteLinkCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeChatFolderInviteLinkCount");
    s.store_class_end();
  }
}

premiumLimitTypeShareableChatFolderCount::premiumLimitTypeShareableChatFolderCount() {
}

const std::int32_t premiumLimitTypeShareableChatFolderCount::ID;

void premiumLimitTypeShareableChatFolderCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeShareableChatFolderCount");
    s.store_class_end();
  }
}

premiumLimitTypeActiveStoryCount::premiumLimitTypeActiveStoryCount() {
}

const std::int32_t premiumLimitTypeActiveStoryCount::ID;

void premiumLimitTypeActiveStoryCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeActiveStoryCount");
    s.store_class_end();
  }
}

premiumLimitTypeWeeklyPostedStoryCount::premiumLimitTypeWeeklyPostedStoryCount() {
}

const std::int32_t premiumLimitTypeWeeklyPostedStoryCount::ID;

void premiumLimitTypeWeeklyPostedStoryCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeWeeklyPostedStoryCount");
    s.store_class_end();
  }
}

premiumLimitTypeMonthlyPostedStoryCount::premiumLimitTypeMonthlyPostedStoryCount() {
}

const std::int32_t premiumLimitTypeMonthlyPostedStoryCount::ID;

void premiumLimitTypeMonthlyPostedStoryCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeMonthlyPostedStoryCount");
    s.store_class_end();
  }
}

premiumLimitTypeStoryCaptionLength::premiumLimitTypeStoryCaptionLength() {
}

const std::int32_t premiumLimitTypeStoryCaptionLength::ID;

void premiumLimitTypeStoryCaptionLength::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeStoryCaptionLength");
    s.store_class_end();
  }
}

premiumLimitTypeStorySuggestedReactionAreaCount::premiumLimitTypeStorySuggestedReactionAreaCount() {
}

const std::int32_t premiumLimitTypeStorySuggestedReactionAreaCount::ID;

void premiumLimitTypeStorySuggestedReactionAreaCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeStorySuggestedReactionAreaCount");
    s.store_class_end();
  }
}

premiumLimitTypeSimilarChatCount::premiumLimitTypeSimilarChatCount() {
}

const std::int32_t premiumLimitTypeSimilarChatCount::ID;

void premiumLimitTypeSimilarChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeSimilarChatCount");
    s.store_class_end();
  }
}

premiumLimitTypeOwnedBotCount::premiumLimitTypeOwnedBotCount() {
}

const std::int32_t premiumLimitTypeOwnedBotCount::ID;

void premiumLimitTypeOwnedBotCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimitTypeOwnedBotCount");
    s.store_class_end();
  }
}

premiumPaymentOption::premiumPaymentOption()
  : currency_()
  , amount_()
  , discount_percentage_()
  , month_count_()
  , store_product_id_()
  , payment_link_()
{}

premiumPaymentOption::premiumPaymentOption(string const &currency_, int53 amount_, int32 discount_percentage_, int32 month_count_, string const &store_product_id_, object_ptr<InternalLinkType> &&payment_link_)
  : currency_(currency_)
  , amount_(amount_)
  , discount_percentage_(discount_percentage_)
  , month_count_(month_count_)
  , store_product_id_(store_product_id_)
  , payment_link_(std::move(payment_link_))
{}

const std::int32_t premiumPaymentOption::ID;

void premiumPaymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumPaymentOption");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("discount_percentage", discount_percentage_);
    s.store_field("month_count", month_count_);
    s.store_field("store_product_id", store_product_id_);
    s.store_object_field("payment_link", static_cast<const BaseObject *>(payment_link_.get()));
    s.store_class_end();
  }
}

premiumStoryFeaturePriorityOrder::premiumStoryFeaturePriorityOrder() {
}

const std::int32_t premiumStoryFeaturePriorityOrder::ID;

void premiumStoryFeaturePriorityOrder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeaturePriorityOrder");
    s.store_class_end();
  }
}

premiumStoryFeatureStealthMode::premiumStoryFeatureStealthMode() {
}

const std::int32_t premiumStoryFeatureStealthMode::ID;

void premiumStoryFeatureStealthMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeatureStealthMode");
    s.store_class_end();
  }
}

premiumStoryFeaturePermanentViewsHistory::premiumStoryFeaturePermanentViewsHistory() {
}

const std::int32_t premiumStoryFeaturePermanentViewsHistory::ID;

void premiumStoryFeaturePermanentViewsHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeaturePermanentViewsHistory");
    s.store_class_end();
  }
}

premiumStoryFeatureCustomExpirationDuration::premiumStoryFeatureCustomExpirationDuration() {
}

const std::int32_t premiumStoryFeatureCustomExpirationDuration::ID;

void premiumStoryFeatureCustomExpirationDuration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeatureCustomExpirationDuration");
    s.store_class_end();
  }
}

premiumStoryFeatureSaveStories::premiumStoryFeatureSaveStories() {
}

const std::int32_t premiumStoryFeatureSaveStories::ID;

void premiumStoryFeatureSaveStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeatureSaveStories");
    s.store_class_end();
  }
}

premiumStoryFeatureLinksAndFormatting::premiumStoryFeatureLinksAndFormatting() {
}

const std::int32_t premiumStoryFeatureLinksAndFormatting::ID;

void premiumStoryFeatureLinksAndFormatting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeatureLinksAndFormatting");
    s.store_class_end();
  }
}

premiumStoryFeatureVideoQuality::premiumStoryFeatureVideoQuality() {
}

const std::int32_t premiumStoryFeatureVideoQuality::ID;

void premiumStoryFeatureVideoQuality::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStoryFeatureVideoQuality");
    s.store_class_end();
  }
}

publicForwardMessage::publicForwardMessage()
  : message_()
{}

publicForwardMessage::publicForwardMessage(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t publicForwardMessage::ID;

void publicForwardMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicForwardMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

publicForwardStory::publicForwardStory()
  : story_()
{}

publicForwardStory::publicForwardStory(object_ptr<story> &&story_)
  : story_(std::move(story_))
{}

const std::int32_t publicForwardStory::ID;

void publicForwardStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicForwardStory");
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

publicForwards::publicForwards()
  : total_count_()
  , forwards_()
  , next_offset_()
{}

publicForwards::publicForwards(int32 total_count_, array<object_ptr<PublicForward>> &&forwards_, string const &next_offset_)
  : total_count_(total_count_)
  , forwards_(std::move(forwards_))
  , next_offset_(next_offset_)
{}

const std::int32_t publicForwards::ID;

void publicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicForwards");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("forwards", forwards_.size()); for (const auto &_value : forwards_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

receivedGifts::receivedGifts()
  : total_count_()
  , gifts_()
  , are_notifications_enabled_()
  , next_offset_()
{}

receivedGifts::receivedGifts(int32 total_count_, array<object_ptr<receivedGift>> &&gifts_, bool are_notifications_enabled_, string const &next_offset_)
  : total_count_(total_count_)
  , gifts_(std::move(gifts_))
  , are_notifications_enabled_(are_notifications_enabled_)
  , next_offset_(next_offset_)
{}

const std::int32_t receivedGifts::ID;

void receivedGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "receivedGifts");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("are_notifications_enabled", are_notifications_enabled_);
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

savedMessagesTopic::savedMessagesTopic()
  : id_()
  , type_()
  , is_pinned_()
  , order_()
  , last_message_()
  , draft_message_()
{}

savedMessagesTopic::savedMessagesTopic(int53 id_, object_ptr<SavedMessagesTopicType> &&type_, bool is_pinned_, int64 order_, object_ptr<message> &&last_message_, object_ptr<draftMessage> &&draft_message_)
  : id_(id_)
  , type_(std::move(type_))
  , is_pinned_(is_pinned_)
  , order_(order_)
  , last_message_(std::move(last_message_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t savedMessagesTopic::ID;

void savedMessagesTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedMessagesTopic");
    s.store_field("id", id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_field("order", order_);
    s.store_object_field("last_message", static_cast<const BaseObject *>(last_message_.get()));
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

startLiveStoryResultOk::startLiveStoryResultOk()
  : story_()
{}

startLiveStoryResultOk::startLiveStoryResultOk(object_ptr<story> &&story_)
  : story_(std::move(story_))
{}

const std::int32_t startLiveStoryResultOk::ID;

void startLiveStoryResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startLiveStoryResultOk");
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

startLiveStoryResultFail::startLiveStoryResultFail()
  : error_type_()
{}

startLiveStoryResultFail::startLiveStoryResultFail(object_ptr<CanPostStoryResult> &&error_type_)
  : error_type_(std::move(error_type_))
{}

const std::int32_t startLiveStoryResultFail::ID;

void startLiveStoryResultFail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startLiveStoryResultFail");
    s.store_object_field("error_type", static_cast<const BaseObject *>(error_type_.get()));
    s.store_class_end();
  }
}

storageStatisticsByChat::storageStatisticsByChat()
  : chat_id_()
  , size_()
  , count_()
  , by_file_type_()
{}

storageStatisticsByChat::storageStatisticsByChat(int53 chat_id_, int53 size_, int32 count_, array<object_ptr<storageStatisticsByFileType>> &&by_file_type_)
  : chat_id_(chat_id_)
  , size_(size_)
  , count_(count_)
  , by_file_type_(std::move(by_file_type_))
{}

const std::int32_t storageStatisticsByChat::ID;

void storageStatisticsByChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storageStatisticsByChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("size", size_);
    s.store_field("count", count_);
    { s.store_vector_begin("by_file_type", by_file_type_.size()); for (const auto &_value : by_file_type_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyAreaPosition::storyAreaPosition()
  : x_percentage_()
  , y_percentage_()
  , width_percentage_()
  , height_percentage_()
  , rotation_angle_()
  , corner_radius_percentage_()
{}

storyAreaPosition::storyAreaPosition(double x_percentage_, double y_percentage_, double width_percentage_, double height_percentage_, double rotation_angle_, double corner_radius_percentage_)
  : x_percentage_(x_percentage_)
  , y_percentage_(y_percentage_)
  , width_percentage_(width_percentage_)
  , height_percentage_(height_percentage_)
  , rotation_angle_(rotation_angle_)
  , corner_radius_percentage_(corner_radius_percentage_)
{}

const std::int32_t storyAreaPosition::ID;

void storyAreaPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAreaPosition");
    s.store_field("x_percentage", x_percentage_);
    s.store_field("y_percentage", y_percentage_);
    s.store_field("width_percentage", width_percentage_);
    s.store_field("height_percentage", height_percentage_);
    s.store_field("rotation_angle", rotation_angle_);
    s.store_field("corner_radius_percentage", corner_radius_percentage_);
    s.store_class_end();
  }
}

storyRepostInfo::storyRepostInfo()
  : origin_()
  , is_content_modified_()
{}

storyRepostInfo::storyRepostInfo(object_ptr<StoryOrigin> &&origin_, bool is_content_modified_)
  : origin_(std::move(origin_))
  , is_content_modified_(is_content_modified_)
{}

const std::int32_t storyRepostInfo::ID;

void storyRepostInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyRepostInfo");
    s.store_object_field("origin", static_cast<const BaseObject *>(origin_.get()));
    s.store_field("is_content_modified", is_content_modified_);
    s.store_class_end();
  }
}

storyStatistics::storyStatistics()
  : story_interaction_graph_()
  , story_reaction_graph_()
{}

storyStatistics::storyStatistics(object_ptr<StatisticalGraph> &&story_interaction_graph_, object_ptr<StatisticalGraph> &&story_reaction_graph_)
  : story_interaction_graph_(std::move(story_interaction_graph_))
  , story_reaction_graph_(std::move(story_reaction_graph_))
{}

const std::int32_t storyStatistics::ID;

void storyStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyStatistics");
    s.store_object_field("story_interaction_graph", static_cast<const BaseObject *>(story_interaction_graph_.get()));
    s.store_object_field("story_reaction_graph", static_cast<const BaseObject *>(story_reaction_graph_.get()));
    s.store_class_end();
  }
}

topChatCategoryUsers::topChatCategoryUsers() {
}

const std::int32_t topChatCategoryUsers::ID;

void topChatCategoryUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryUsers");
    s.store_class_end();
  }
}

topChatCategoryBots::topChatCategoryBots() {
}

const std::int32_t topChatCategoryBots::ID;

void topChatCategoryBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryBots");
    s.store_class_end();
  }
}

topChatCategoryGroups::topChatCategoryGroups() {
}

const std::int32_t topChatCategoryGroups::ID;

void topChatCategoryGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryGroups");
    s.store_class_end();
  }
}

topChatCategoryChannels::topChatCategoryChannels() {
}

const std::int32_t topChatCategoryChannels::ID;

void topChatCategoryChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryChannels");
    s.store_class_end();
  }
}

topChatCategoryInlineBots::topChatCategoryInlineBots() {
}

const std::int32_t topChatCategoryInlineBots::ID;

void topChatCategoryInlineBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryInlineBots");
    s.store_class_end();
  }
}

topChatCategoryWebAppBots::topChatCategoryWebAppBots() {
}

const std::int32_t topChatCategoryWebAppBots::ID;

void topChatCategoryWebAppBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryWebAppBots");
    s.store_class_end();
  }
}

topChatCategoryCalls::topChatCategoryCalls() {
}

const std::int32_t topChatCategoryCalls::ID;

void topChatCategoryCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryCalls");
    s.store_class_end();
  }
}

topChatCategoryForwardChats::topChatCategoryForwardChats() {
}

const std::int32_t topChatCategoryForwardChats::ID;

void topChatCategoryForwardChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topChatCategoryForwardChats");
    s.store_class_end();
  }
}

venue::venue()
  : location_()
  , title_()
  , address_()
  , provider_()
  , id_()
  , type_()
{}

venue::venue(object_ptr<location> &&location_, string const &title_, string const &address_, string const &provider_, string const &id_, string const &type_)
  : location_(std::move(location_))
  , title_(title_)
  , address_(address_)
  , provider_(provider_)
  , id_(id_)
  , type_(type_)
{}

const std::int32_t venue::ID;

void venue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "venue");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("id", id_);
    s.store_field("type", type_);
    s.store_class_end();
  }
}

video::video()
  : duration_()
  , width_()
  , height_()
  , file_name_()
  , mime_type_()
  , has_stickers_()
  , supports_streaming_()
  , minithumbnail_()
  , thumbnail_()
  , video_()
{}

video::video(int32 duration_, int32 width_, int32 height_, string const &file_name_, string const &mime_type_, bool has_stickers_, bool supports_streaming_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&video_)
  : duration_(duration_)
  , width_(width_)
  , height_(height_)
  , file_name_(file_name_)
  , mime_type_(mime_type_)
  , has_stickers_(has_stickers_)
  , supports_streaming_(supports_streaming_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , video_(std::move(video_))
{}

const std::int32_t video::ID;

void video::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "video");
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_field("has_stickers", has_stickers_);
    s.store_field("supports_streaming", supports_streaming_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

videoNote::videoNote()
  : duration_()
  , waveform_()
  , length_()
  , minithumbnail_()
  , thumbnail_()
  , speech_recognition_result_()
  , video_()
{}

videoNote::videoNote(int32 duration_, bytes const &waveform_, int32 length_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, object_ptr<SpeechRecognitionResult> &&speech_recognition_result_, object_ptr<file> &&video_)
  : duration_(duration_)
  , waveform_(std::move(waveform_))
  , length_(length_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , speech_recognition_result_(std::move(speech_recognition_result_))
  , video_(std::move(video_))
{}

const std::int32_t videoNote::ID;

void videoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoNote");
    s.store_field("duration", duration_);
    s.store_bytes_field("waveform", waveform_);
    s.store_field("length", length_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("speech_recognition_result", static_cast<const BaseObject *>(speech_recognition_result_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

videoStoryboard::videoStoryboard()
  : storyboard_file_()
  , width_()
  , height_()
  , map_file_()
{}

videoStoryboard::videoStoryboard(object_ptr<file> &&storyboard_file_, int32 width_, int32 height_, object_ptr<file> &&map_file_)
  : storyboard_file_(std::move(storyboard_file_))
  , width_(width_)
  , height_(height_)
  , map_file_(std::move(map_file_))
{}

const std::int32_t videoStoryboard::ID;

void videoStoryboard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoStoryboard");
    s.store_object_field("storyboard_file", static_cast<const BaseObject *>(storyboard_file_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("map_file", static_cast<const BaseObject *>(map_file_.get()));
    s.store_class_end();
  }
}

addQuickReplyShortcutInlineQueryResultMessage::addQuickReplyShortcutInlineQueryResultMessage()
  : shortcut_name_()
  , reply_to_message_id_()
  , query_id_()
  , result_id_()
  , hide_via_bot_()
{}

addQuickReplyShortcutInlineQueryResultMessage::addQuickReplyShortcutInlineQueryResultMessage(string const &shortcut_name_, int53 reply_to_message_id_, int64 query_id_, string const &result_id_, bool hide_via_bot_)
  : shortcut_name_(shortcut_name_)
  , reply_to_message_id_(reply_to_message_id_)
  , query_id_(query_id_)
  , result_id_(result_id_)
  , hide_via_bot_(hide_via_bot_)
{}

const std::int32_t addQuickReplyShortcutInlineQueryResultMessage::ID;

void addQuickReplyShortcutInlineQueryResultMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addQuickReplyShortcutInlineQueryResultMessage");
    s.store_field("shortcut_name", shortcut_name_);
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_field("query_id", query_id_);
    s.store_field("result_id", result_id_);
    s.store_field("hide_via_bot", hide_via_bot_);
    s.store_class_end();
  }
}

applyPremiumGiftCode::applyPremiumGiftCode()
  : code_()
{}

applyPremiumGiftCode::applyPremiumGiftCode(string const &code_)
  : code_(code_)
{}

const std::int32_t applyPremiumGiftCode::ID;

void applyPremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "applyPremiumGiftCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

canPurchaseFromStore::canPurchaseFromStore()
  : purpose_()
{}

canPurchaseFromStore::canPurchaseFromStore(object_ptr<StorePaymentPurpose> &&purpose_)
  : purpose_(std::move(purpose_))
{}

const std::int32_t canPurchaseFromStore::ID;

void canPurchaseFromStore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPurchaseFromStore");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

canSendGift::canSendGift()
  : gift_id_()
{}

canSendGift::canSendGift(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t canSendGift::ID;

void canSendGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendGift");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

checkAuthenticationPasskey::checkAuthenticationPasskey()
  : credential_id_()
  , client_data_()
  , authenticator_data_()
  , signature_()
  , user_handle_()
{}

checkAuthenticationPasskey::checkAuthenticationPasskey(string const &credential_id_, string const &client_data_, bytes const &authenticator_data_, bytes const &signature_, bytes const &user_handle_)
  : credential_id_(credential_id_)
  , client_data_(client_data_)
  , authenticator_data_(std::move(authenticator_data_))
  , signature_(std::move(signature_))
  , user_handle_(std::move(user_handle_))
{}

const std::int32_t checkAuthenticationPasskey::ID;

void checkAuthenticationPasskey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationPasskey");
    s.store_field("credential_id", credential_id_);
    s.store_field("client_data", client_data_);
    s.store_bytes_field("authenticator_data", authenticator_data_);
    s.store_bytes_field("signature", signature_);
    s.store_bytes_field("user_handle", user_handle_);
    s.store_class_end();
  }
}

checkAuthenticationPasswordRecoveryCode::checkAuthenticationPasswordRecoveryCode()
  : recovery_code_()
{}

checkAuthenticationPasswordRecoveryCode::checkAuthenticationPasswordRecoveryCode(string const &recovery_code_)
  : recovery_code_(recovery_code_)
{}

const std::int32_t checkAuthenticationPasswordRecoveryCode::ID;

void checkAuthenticationPasswordRecoveryCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationPasswordRecoveryCode");
    s.store_field("recovery_code", recovery_code_);
    s.store_class_end();
  }
}

checkPasswordRecoveryCode::checkPasswordRecoveryCode()
  : recovery_code_()
{}

checkPasswordRecoveryCode::checkPasswordRecoveryCode(string const &recovery_code_)
  : recovery_code_(recovery_code_)
{}

const std::int32_t checkPasswordRecoveryCode::ID;

void checkPasswordRecoveryCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkPasswordRecoveryCode");
    s.store_field("recovery_code", recovery_code_);
    s.store_class_end();
  }
}

clearImportedContacts::clearImportedContacts() {
}

const std::int32_t clearImportedContacts::ID;

void clearImportedContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearImportedContacts");
    s.store_class_end();
  }
}

clickVideoMessageAdvertisement::clickVideoMessageAdvertisement()
  : advertisement_unique_id_()
{}

clickVideoMessageAdvertisement::clickVideoMessageAdvertisement(int53 advertisement_unique_id_)
  : advertisement_unique_id_(advertisement_unique_id_)
{}

const std::int32_t clickVideoMessageAdvertisement::ID;

void clickVideoMessageAdvertisement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clickVideoMessageAdvertisement");
    s.store_field("advertisement_unique_id", advertisement_unique_id_);
    s.store_class_end();
  }
}

closeSecretChat::closeSecretChat()
  : secret_chat_id_()
{}

closeSecretChat::closeSecretChat(int32 secret_chat_id_)
  : secret_chat_id_(secret_chat_id_)
{}

const std::int32_t closeSecretChat::ID;

void closeSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeSecretChat");
    s.store_field("secret_chat_id", secret_chat_id_);
    s.store_class_end();
  }
}

craftGift::craftGift()
  : received_gift_ids_()
{}

craftGift::craftGift(array<string> &&received_gift_ids_)
  : received_gift_ids_(std::move(received_gift_ids_))
{}

const std::int32_t craftGift::ID;

void craftGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "craftGift");
    { s.store_vector_begin("received_gift_ids", received_gift_ids_.size()); for (const auto &_value : received_gift_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

createBasicGroupChat::createBasicGroupChat()
  : basic_group_id_()
  , force_()
{}

createBasicGroupChat::createBasicGroupChat(int53 basic_group_id_, bool force_)
  : basic_group_id_(basic_group_id_)
  , force_(force_)
{}

const std::int32_t createBasicGroupChat::ID;

void createBasicGroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createBasicGroupChat");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

createChatFolder::createChatFolder()
  : folder_()
{}

createChatFolder::createChatFolder(object_ptr<chatFolder> &&folder_)
  : folder_(std::move(folder_))
{}

const std::int32_t createChatFolder::ID;

void createChatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createChatFolder");
    s.store_object_field("folder", static_cast<const BaseObject *>(folder_.get()));
    s.store_class_end();
  }
}

createNewBasicGroupChat::createNewBasicGroupChat()
  : user_ids_()
  , title_()
  , message_auto_delete_time_()
{}

createNewBasicGroupChat::createNewBasicGroupChat(array<int53> &&user_ids_, string const &title_, int32 message_auto_delete_time_)
  : user_ids_(std::move(user_ids_))
  , title_(title_)
  , message_auto_delete_time_(message_auto_delete_time_)
{}

const std::int32_t createNewBasicGroupChat::ID;

void createNewBasicGroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createNewBasicGroupChat");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("title", title_);
    s.store_field("message_auto_delete_time", message_auto_delete_time_);
    s.store_class_end();
  }
}

createNewSecretChat::createNewSecretChat()
  : user_id_()
{}

createNewSecretChat::createNewSecretChat(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t createNewSecretChat::ID;

void createNewSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createNewSecretChat");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

deleteAllRevokedChatInviteLinks::deleteAllRevokedChatInviteLinks()
  : chat_id_()
  , creator_user_id_()
{}

deleteAllRevokedChatInviteLinks::deleteAllRevokedChatInviteLinks(int53 chat_id_, int53 creator_user_id_)
  : chat_id_(chat_id_)
  , creator_user_id_(creator_user_id_)
{}

const std::int32_t deleteAllRevokedChatInviteLinks::ID;

void deleteAllRevokedChatInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteAllRevokedChatInviteLinks");
    s.store_field("chat_id", chat_id_);
    s.store_field("creator_user_id", creator_user_id_);
    s.store_class_end();
  }
}

deleteStoryAlbum::deleteStoryAlbum()
  : chat_id_()
  , story_album_id_()
{}

deleteStoryAlbum::deleteStoryAlbum(int53 chat_id_, int32 story_album_id_)
  : chat_id_(chat_id_)
  , story_album_id_(story_album_id_)
{}

const std::int32_t deleteStoryAlbum::ID;

void deleteStoryAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteStoryAlbum");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_album_id", story_album_id_);
    s.store_class_end();
  }
}

editBusinessMessageChecklist::editBusinessMessageChecklist()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
  , checklist_()
{}

editBusinessMessageChecklist::editBusinessMessageChecklist(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<inputChecklist> &&checklist_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , checklist_(std::move(checklist_))
{}

const std::int32_t editBusinessMessageChecklist::ID;

void editBusinessMessageChecklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessMessageChecklist");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("checklist", static_cast<const BaseObject *>(checklist_.get()));
    s.store_class_end();
  }
}

editChatInviteLink::editChatInviteLink()
  : chat_id_()
  , invite_link_()
  , name_()
  , expiration_date_()
  , member_limit_()
  , creates_join_request_()
{}

editChatInviteLink::editChatInviteLink(int53 chat_id_, string const &invite_link_, string const &name_, int32 expiration_date_, int32 member_limit_, bool creates_join_request_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , name_(name_)
  , expiration_date_(expiration_date_)
  , member_limit_(member_limit_)
  , creates_join_request_(creates_join_request_)
{}

const std::int32_t editChatInviteLink::ID;

void editChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("name", name_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("member_limit", member_limit_);
    s.store_field("creates_join_request", creates_join_request_);
    s.store_class_end();
  }
}

editChatSubscriptionInviteLink::editChatSubscriptionInviteLink()
  : chat_id_()
  , invite_link_()
  , name_()
{}

editChatSubscriptionInviteLink::editChatSubscriptionInviteLink(int53 chat_id_, string const &invite_link_, string const &name_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , name_(name_)
{}

const std::int32_t editChatSubscriptionInviteLink::ID;

void editChatSubscriptionInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editChatSubscriptionInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

editMessageMedia::editMessageMedia()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editMessageMedia::editMessageMedia(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editMessageMedia::ID;

void editMessageMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageMedia");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

getAttachmentMenuBot::getAttachmentMenuBot()
  : bot_user_id_()
{}

getAttachmentMenuBot::getAttachmentMenuBot(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t getAttachmentMenuBot::ID;

void getAttachmentMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAttachmentMenuBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

getAutoDownloadSettingsPresets::getAutoDownloadSettingsPresets() {
}

const std::int32_t getAutoDownloadSettingsPresets::ID;

void getAutoDownloadSettingsPresets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAutoDownloadSettingsPresets");
    s.store_class_end();
  }
}

getBotName::getBotName()
  : bot_user_id_()
  , language_code_()
{}

getBotName::getBotName(int53 bot_user_id_, string const &language_code_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
{}

const std::int32_t getBotName::ID;

void getBotName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotName");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getChatBoostStatus::getChatBoostStatus()
  : chat_id_()
{}

getChatBoostStatus::getChatBoostStatus(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatBoostStatus::ID;

void getChatBoostStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatBoostStatus");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatBoosts::getChatBoosts()
  : chat_id_()
  , only_gift_codes_()
  , offset_()
  , limit_()
{}

getChatBoosts::getChatBoosts(int53 chat_id_, bool only_gift_codes_, string const &offset_, int32 limit_)
  : chat_id_(chat_id_)
  , only_gift_codes_(only_gift_codes_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getChatBoosts::ID;

void getChatBoosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatBoosts");
    s.store_field("chat_id", chat_id_);
    s.store_field("only_gift_codes", only_gift_codes_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatInviteLink::getChatInviteLink()
  : chat_id_()
  , invite_link_()
{}

getChatInviteLink::getChatInviteLink(int53 chat_id_, string const &invite_link_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
{}

const std::int32_t getChatInviteLink::ID;

void getChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

getChatStoryInteractions::getChatStoryInteractions()
  : story_poster_chat_id_()
  , story_id_()
  , reaction_type_()
  , prefer_forwards_()
  , offset_()
  , limit_()
{}

getChatStoryInteractions::getChatStoryInteractions(int53 story_poster_chat_id_, int32 story_id_, object_ptr<ReactionType> &&reaction_type_, bool prefer_forwards_, string const &offset_, int32 limit_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , reaction_type_(std::move(reaction_type_))
  , prefer_forwards_(prefer_forwards_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getChatStoryInteractions::ID;

void getChatStoryInteractions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatStoryInteractions");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_field("prefer_forwards", prefer_forwards_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getConnectedAffiliatePrograms::getConnectedAffiliatePrograms()
  : affiliate_()
  , offset_()
  , limit_()
{}

getConnectedAffiliatePrograms::getConnectedAffiliatePrograms(object_ptr<AffiliateType> &&affiliate_, string const &offset_, int32 limit_)
  : affiliate_(std::move(affiliate_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getConnectedAffiliatePrograms::ID;

void getConnectedAffiliatePrograms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getConnectedAffiliatePrograms");
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getContacts::getContacts() {
}

const std::int32_t getContacts::ID;

void getContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getContacts");
    s.store_class_end();
  }
}

getCustomEmojiReactionAnimations::getCustomEmojiReactionAnimations() {
}

const std::int32_t getCustomEmojiReactionAnimations::ID;

void getCustomEmojiReactionAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCustomEmojiReactionAnimations");
    s.store_class_end();
  }
}

getGiftAuctionAcquiredGifts::getGiftAuctionAcquiredGifts()
  : gift_id_()
{}

getGiftAuctionAcquiredGifts::getGiftAuctionAcquiredGifts(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t getGiftAuctionAcquiredGifts::ID;

void getGiftAuctionAcquiredGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftAuctionAcquiredGifts");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

getGreetingStickers::getGreetingStickers() {
}

const std::int32_t getGreetingStickers::ID;

void getGreetingStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGreetingStickers");
    s.store_class_end();
  }
}

getMenuButton::getMenuButton()
  : user_id_()
{}

getMenuButton::getMenuButton(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getMenuButton::ID;

void getMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMenuButton");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getMessageFileType::getMessageFileType()
  : message_file_head_()
{}

getMessageFileType::getMessageFileType(string const &message_file_head_)
  : message_file_head_(message_file_head_)
{}

const std::int32_t getMessageFileType::ID;

void getMessageFileType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageFileType");
    s.store_field("message_file_head", message_file_head_);
    s.store_class_end();
  }
}

getNewChatPrivacySettings::getNewChatPrivacySettings() {
}

const std::int32_t getNewChatPrivacySettings::ID;

void getNewChatPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getNewChatPrivacySettings");
    s.store_class_end();
  }
}

getOwnedBots::getOwnedBots() {
}

const std::int32_t getOwnedBots::ID;

void getOwnedBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOwnedBots");
    s.store_class_end();
  }
}

getPremiumGiveawayPaymentOptions::getPremiumGiveawayPaymentOptions()
  : boosted_chat_id_()
{}

getPremiumGiveawayPaymentOptions::getPremiumGiveawayPaymentOptions(int53 boosted_chat_id_)
  : boosted_chat_id_(boosted_chat_id_)
{}

const std::int32_t getPremiumGiveawayPaymentOptions::ID;

void getPremiumGiveawayPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumGiveawayPaymentOptions");
    s.store_field("boosted_chat_id", boosted_chat_id_);
    s.store_class_end();
  }
}

getPremiumState::getPremiumState() {
}

const std::int32_t getPremiumState::ID;

void getPremiumState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumState");
    s.store_class_end();
  }
}

getRecommendedChatFolders::getRecommendedChatFolders() {
}

const std::int32_t getRecommendedChatFolders::ID;

void getRecommendedChatFolders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecommendedChatFolders");
    s.store_class_end();
  }
}

getRecommendedChats::getRecommendedChats() {
}

const std::int32_t getRecommendedChats::ID;

void getRecommendedChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecommendedChats");
    s.store_class_end();
  }
}

getRepliedMessage::getRepliedMessage()
  : chat_id_()
  , message_id_()
{}

getRepliedMessage::getRepliedMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getRepliedMessage::ID;

void getRepliedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRepliedMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getSavedMessagesTopicHistory::getSavedMessagesTopicHistory()
  : saved_messages_topic_id_()
  , from_message_id_()
  , offset_()
  , limit_()
{}

getSavedMessagesTopicHistory::getSavedMessagesTopicHistory(int53 saved_messages_topic_id_, int53 from_message_id_, int32 offset_, int32 limit_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getSavedMessagesTopicHistory::ID;

void getSavedMessagesTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedMessagesTopicHistory");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getSavedNotificationSounds::getSavedNotificationSounds() {
}

const std::int32_t getSavedNotificationSounds::ID;

void getSavedNotificationSounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedNotificationSounds");
    s.store_class_end();
  }
}

getStarPaymentOptions::getStarPaymentOptions() {
}

const std::int32_t getStarPaymentOptions::ID;

void getStarPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarPaymentOptions");
    s.store_class_end();
  }
}

getStickerSetName::getStickerSetName()
  : set_id_()
{}

getStickerSetName::getStickerSetName(int64 set_id_)
  : set_id_(set_id_)
{}

const std::int32_t getStickerSetName::ID;

void getStickerSetName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickerSetName");
    s.store_field("set_id", set_id_);
    s.store_class_end();
  }
}

getSupergroup::getSupergroup()
  : supergroup_id_()
{}

getSupergroup::getSupergroup(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t getSupergroup::ID;

void getSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupergroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

getTimeZones::getTimeZones() {
}

const std::int32_t getTimeZones::ID;

void getTimeZones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTimeZones");
    s.store_class_end();
  }
}

getUserProfilePhotos::getUserProfilePhotos()
  : user_id_()
  , offset_()
  , limit_()
{}

getUserProfilePhotos::getUserProfilePhotos(int53 user_id_, int32 offset_, int32 limit_)
  : user_id_(user_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getUserProfilePhotos::ID;

void getUserProfilePhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserProfilePhotos");
    s.store_field("user_id", user_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getUserSupportInfo::getUserSupportInfo()
  : user_id_()
{}

getUserSupportInfo::getUserSupportInfo(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getUserSupportInfo::ID;

void getUserSupportInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserSupportInfo");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getVideoChatRtmpUrl::getVideoChatRtmpUrl()
  : chat_id_()
{}

getVideoChatRtmpUrl::getVideoChatRtmpUrl(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getVideoChatRtmpUrl::ID;

void getVideoChatRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getVideoChatRtmpUrl");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getWebAppUrl::getWebAppUrl()
  : bot_user_id_()
  , url_()
  , parameters_()
{}

getWebAppUrl::getWebAppUrl(int53 bot_user_id_, string const &url_, object_ptr<webAppOpenParameters> &&parameters_)
  : bot_user_id_(bot_user_id_)
  , url_(url_)
  , parameters_(std::move(parameters_))
{}

const std::int32_t getWebAppUrl::ID;

void getWebAppUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWebAppUrl");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("url", url_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

giftPremiumWithStars::giftPremiumWithStars()
  : user_id_()
  , star_count_()
  , month_count_()
  , text_()
{}

giftPremiumWithStars::giftPremiumWithStars(int53 user_id_, int53 star_count_, int32 month_count_, object_ptr<formattedText> &&text_)
  : user_id_(user_id_)
  , star_count_(star_count_)
  , month_count_(month_count_)
  , text_(std::move(text_))
{}

const std::int32_t giftPremiumWithStars::ID;

void giftPremiumWithStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftPremiumWithStars");
    s.store_field("user_id", user_id_);
    s.store_field("star_count", star_count_);
    s.store_field("month_count", month_count_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

joinChat::joinChat()
  : chat_id_()
{}

joinChat::joinChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t joinChat::ID;

void joinChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

joinLiveStory::joinLiveStory()
  : group_call_id_()
  , join_parameters_()
{}

joinLiveStory::joinLiveStory(int32 group_call_id_, object_ptr<groupCallJoinParameters> &&join_parameters_)
  : group_call_id_(group_call_id_)
  , join_parameters_(std::move(join_parameters_))
{}

const std::int32_t joinLiveStory::ID;

void joinLiveStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinLiveStory");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("join_parameters", static_cast<const BaseObject *>(join_parameters_.get()));
    s.store_class_end();
  }
}

logOut::logOut() {
}

const std::int32_t logOut::ID;

void logOut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logOut");
    s.store_class_end();
  }
}

openMessageContent::openMessageContent()
  : chat_id_()
  , message_id_()
{}

openMessageContent::openMessageContent(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t openMessageContent::ID;

void openMessageContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openMessageContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

parseMarkdown::parseMarkdown()
  : text_()
{}

parseMarkdown::parseMarkdown(object_ptr<formattedText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t parseMarkdown::ID;

void parseMarkdown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "parseMarkdown");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

parseTextEntities::parseTextEntities()
  : text_()
  , parse_mode_()
{}

parseTextEntities::parseTextEntities(string const &text_, object_ptr<TextParseMode> &&parse_mode_)
  : text_(text_)
  , parse_mode_(std::move(parse_mode_))
{}

const std::int32_t parseTextEntities::ID;

void parseTextEntities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "parseTextEntities");
    s.store_field("text", text_);
    s.store_object_field("parse_mode", static_cast<const BaseObject *>(parse_mode_.get()));
    s.store_class_end();
  }
}

processPushNotification::processPushNotification()
  : payload_()
{}

processPushNotification::processPushNotification(string const &payload_)
  : payload_(payload_)
{}

const std::int32_t processPushNotification::ID;

void processPushNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processPushNotification");
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

readAllChatMentions::readAllChatMentions()
  : chat_id_()
{}

readAllChatMentions::readAllChatMentions(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t readAllChatMentions::ID;

void readAllChatMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllChatMentions");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

readAllDirectMessagesChatTopicReactions::readAllDirectMessagesChatTopicReactions()
  : chat_id_()
  , topic_id_()
{}

readAllDirectMessagesChatTopicReactions::readAllDirectMessagesChatTopicReactions(int53 chat_id_, int53 topic_id_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
{}

const std::int32_t readAllDirectMessagesChatTopicReactions::ID;

void readAllDirectMessagesChatTopicReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllDirectMessagesChatTopicReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_class_end();
  }
}

readBusinessMessage::readBusinessMessage()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
{}

readBusinessMessage::readBusinessMessage(string const &business_connection_id_, int53 chat_id_, int53 message_id_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t readBusinessMessage::ID;

void readBusinessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readBusinessMessage");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

removeInstalledBackground::removeInstalledBackground()
  : background_id_()
{}

removeInstalledBackground::removeInstalledBackground(int64 background_id_)
  : background_id_(background_id_)
{}

const std::int32_t removeInstalledBackground::ID;

void removeInstalledBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeInstalledBackground");
    s.store_field("background_id", background_id_);
    s.store_class_end();
  }
}

removePendingPaidMessageReactions::removePendingPaidMessageReactions()
  : chat_id_()
  , message_id_()
{}

removePendingPaidMessageReactions::removePendingPaidMessageReactions(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t removePendingPaidMessageReactions::ID;

void removePendingPaidMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removePendingPaidMessageReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

removeRecentlyFoundChat::removeRecentlyFoundChat()
  : chat_id_()
{}

removeRecentlyFoundChat::removeRecentlyFoundChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t removeRecentlyFoundChat::ID;

void removeRecentlyFoundChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeRecentlyFoundChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

removeTopChat::removeTopChat()
  : category_()
  , chat_id_()
{}

removeTopChat::removeTopChat(object_ptr<TopChatCategory> &&category_, int53 chat_id_)
  : category_(std::move(category_))
  , chat_id_(chat_id_)
{}

const std::int32_t removeTopChat::ID;

void removeTopChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeTopChat");
    s.store_object_field("category", static_cast<const BaseObject *>(category_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

reorderActiveUsernames::reorderActiveUsernames()
  : usernames_()
{}

reorderActiveUsernames::reorderActiveUsernames(array<string> &&usernames_)
  : usernames_(std::move(usernames_))
{}

const std::int32_t reorderActiveUsernames::ID;

void reorderActiveUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderActiveUsernames");
    { s.store_vector_begin("usernames", usernames_.size()); for (const auto &_value : usernames_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reorderBotMediaPreviews::reorderBotMediaPreviews()
  : bot_user_id_()
  , language_code_()
  , file_ids_()
{}

reorderBotMediaPreviews::reorderBotMediaPreviews(int53 bot_user_id_, string const &language_code_, array<int32> &&file_ids_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , file_ids_(std::move(file_ids_))
{}

const std::int32_t reorderBotMediaPreviews::ID;

void reorderBotMediaPreviews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderBotMediaPreviews");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    { s.store_vector_begin("file_ids", file_ids_.size()); for (const auto &_value : file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reorderQuickReplyShortcuts::reorderQuickReplyShortcuts()
  : shortcut_ids_()
{}

reorderQuickReplyShortcuts::reorderQuickReplyShortcuts(array<int32> &&shortcut_ids_)
  : shortcut_ids_(std::move(shortcut_ids_))
{}

const std::int32_t reorderQuickReplyShortcuts::ID;

void reorderQuickReplyShortcuts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderQuickReplyShortcuts");
    { s.store_vector_begin("shortcut_ids", shortcut_ids_.size()); for (const auto &_value : shortcut_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

resendLoginEmailAddressCode::resendLoginEmailAddressCode() {
}

const std::int32_t resendLoginEmailAddressCode::ID;

void resendLoginEmailAddressCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendLoginEmailAddressCode");
    s.store_class_end();
  }
}

resendMessages::resendMessages()
  : chat_id_()
  , message_ids_()
  , quote_()
  , paid_message_star_count_()
{}

resendMessages::resendMessages(int53 chat_id_, array<int53> &&message_ids_, object_ptr<inputTextQuote> &&quote_, int53 paid_message_star_count_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
  , quote_(std::move(quote_))
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t resendMessages::ID;

void resendMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("quote", static_cast<const BaseObject *>(quote_.get()));
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

resetInstalledBackgrounds::resetInstalledBackgrounds() {
}

const std::int32_t resetInstalledBackgrounds::ID;

void resetInstalledBackgrounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetInstalledBackgrounds");
    s.store_class_end();
  }
}

searchAffiliatePrograms::searchAffiliatePrograms()
  : affiliate_()
  , sort_order_()
  , offset_()
  , limit_()
{}

searchAffiliatePrograms::searchAffiliatePrograms(object_ptr<AffiliateType> &&affiliate_, object_ptr<AffiliateProgramSortOrder> &&sort_order_, string const &offset_, int32 limit_)
  : affiliate_(std::move(affiliate_))
  , sort_order_(std::move(sort_order_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchAffiliatePrograms::ID;

void searchAffiliatePrograms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchAffiliatePrograms");
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_object_field("sort_order", static_cast<const BaseObject *>(sort_order_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchChatRecentLocationMessages::searchChatRecentLocationMessages()
  : chat_id_()
  , limit_()
{}

searchChatRecentLocationMessages::searchChatRecentLocationMessages(int53 chat_id_, int32 limit_)
  : chat_id_(chat_id_)
  , limit_(limit_)
{}

const std::int32_t searchChatRecentLocationMessages::ID;

void searchChatRecentLocationMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatRecentLocationMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

sendBusinessMessageAlbum::sendBusinessMessageAlbum()
  : business_connection_id_()
  , chat_id_()
  , reply_to_()
  , disable_notification_()
  , protect_content_()
  , effect_id_()
  , input_message_contents_()
{}

sendBusinessMessageAlbum::sendBusinessMessageAlbum(string const &business_connection_id_, int53 chat_id_, object_ptr<InputMessageReplyTo> &&reply_to_, bool disable_notification_, bool protect_content_, int64 effect_id_, array<object_ptr<InputMessageContent>> &&input_message_contents_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , reply_to_(std::move(reply_to_))
  , disable_notification_(disable_notification_)
  , protect_content_(protect_content_)
  , effect_id_(effect_id_)
  , input_message_contents_(std::move(input_message_contents_))
{}

const std::int32_t sendBusinessMessageAlbum::ID;

void sendBusinessMessageAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendBusinessMessageAlbum");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_field("disable_notification", disable_notification_);
    s.store_field("protect_content", protect_content_);
    s.store_field("effect_id", effect_id_);
    { s.store_vector_begin("input_message_contents", input_message_contents_.size()); for (const auto &_value : input_message_contents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sendChatAction::sendChatAction()
  : chat_id_()
  , topic_id_()
  , business_connection_id_()
  , action_()
{}

sendChatAction::sendChatAction(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, string const &business_connection_id_, object_ptr<ChatAction> &&action_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , business_connection_id_(business_connection_id_)
  , action_(std::move(action_))
{}

const std::int32_t sendChatAction::ID;

void sendChatAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendChatAction");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_field("business_connection_id", business_connection_id_);
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

sendMessage::sendMessage()
  : chat_id_()
  , topic_id_()
  , reply_to_()
  , options_()
  , reply_markup_()
  , input_message_content_()
{}

sendMessage::sendMessage(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<InputMessageReplyTo> &&reply_to_, object_ptr<messageSendOptions> &&options_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , reply_to_(std::move(reply_to_))
  , options_(std::move(options_))
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t sendMessage::ID;

void sendMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

setBotInfoDescription::setBotInfoDescription()
  : bot_user_id_()
  , language_code_()
  , description_()
{}

setBotInfoDescription::setBotInfoDescription(int53 bot_user_id_, string const &language_code_, string const &description_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , description_(description_)
{}

const std::int32_t setBotInfoDescription::ID;

void setBotInfoDescription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBotInfoDescription");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

setBotName::setBotName()
  : bot_user_id_()
  , language_code_()
  , name_()
{}

setBotName::setBotName(int53 bot_user_id_, string const &language_code_, string const &name_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , name_(name_)
{}

const std::int32_t setBotName::ID;

void setBotName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBotName");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

setBusinessAccountBio::setBusinessAccountBio()
  : business_connection_id_()
  , bio_()
{}

setBusinessAccountBio::setBusinessAccountBio(string const &business_connection_id_, string const &bio_)
  : business_connection_id_(business_connection_id_)
  , bio_(bio_)
{}

const std::int32_t setBusinessAccountBio::ID;

void setBusinessAccountBio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessAccountBio");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("bio", bio_);
    s.store_class_end();
  }
}

setChatAccentColor::setChatAccentColor()
  : chat_id_()
  , accent_color_id_()
  , background_custom_emoji_id_()
{}

setChatAccentColor::setChatAccentColor(int53 chat_id_, int32 accent_color_id_, int64 background_custom_emoji_id_)
  : chat_id_(chat_id_)
  , accent_color_id_(accent_color_id_)
  , background_custom_emoji_id_(background_custom_emoji_id_)
{}

const std::int32_t setChatAccentColor::ID;

void setChatAccentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatAccentColor");
    s.store_field("chat_id", chat_id_);
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("background_custom_emoji_id", background_custom_emoji_id_);
    s.store_class_end();
  }
}

setChatEmojiStatus::setChatEmojiStatus()
  : chat_id_()
  , emoji_status_()
{}

setChatEmojiStatus::setChatEmojiStatus(int53 chat_id_, object_ptr<emojiStatus> &&emoji_status_)
  : chat_id_(chat_id_)
  , emoji_status_(std::move(emoji_status_))
{}

const std::int32_t setChatEmojiStatus::ID;

void setChatEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatEmojiStatus");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

setChatSlowModeDelay::setChatSlowModeDelay()
  : chat_id_()
  , slow_mode_delay_()
{}

setChatSlowModeDelay::setChatSlowModeDelay(int53 chat_id_, int32 slow_mode_delay_)
  : chat_id_(chat_id_)
  , slow_mode_delay_(slow_mode_delay_)
{}

const std::int32_t setChatSlowModeDelay::ID;

void setChatSlowModeDelay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatSlowModeDelay");
    s.store_field("chat_id", chat_id_);
    s.store_field("slow_mode_delay", slow_mode_delay_);
    s.store_class_end();
  }
}

setEmojiStatus::setEmojiStatus()
  : emoji_status_()
{}

setEmojiStatus::setEmojiStatus(object_ptr<emojiStatus> &&emoji_status_)
  : emoji_status_(std::move(emoji_status_))
{}

const std::int32_t setEmojiStatus::ID;

void setEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setEmojiStatus");
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

setLogVerbosityLevel::setLogVerbosityLevel()
  : new_verbosity_level_()
{}

setLogVerbosityLevel::setLogVerbosityLevel(int32 new_verbosity_level_)
  : new_verbosity_level_(new_verbosity_level_)
{}

const std::int32_t setLogVerbosityLevel::ID;

void setLogVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLogVerbosityLevel");
    s.store_field("new_verbosity_level", new_verbosity_level_);
    s.store_class_end();
  }
}

setMenuButton::setMenuButton()
  : user_id_()
  , menu_button_()
{}

setMenuButton::setMenuButton(int53 user_id_, object_ptr<botMenuButton> &&menu_button_)
  : user_id_(user_id_)
  , menu_button_(std::move(menu_button_))
{}

const std::int32_t setMenuButton::ID;

void setMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMenuButton");
    s.store_field("user_id", user_id_);
    s.store_object_field("menu_button", static_cast<const BaseObject *>(menu_button_.get()));
    s.store_class_end();
  }
}

setPinnedGifts::setPinnedGifts()
  : owner_id_()
  , received_gift_ids_()
{}

setPinnedGifts::setPinnedGifts(object_ptr<MessageSender> &&owner_id_, array<string> &&received_gift_ids_)
  : owner_id_(std::move(owner_id_))
  , received_gift_ids_(std::move(received_gift_ids_))
{}

const std::int32_t setPinnedGifts::ID;

void setPinnedGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPinnedGifts");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    { s.store_vector_begin("received_gift_ids", received_gift_ids_.size()); for (const auto &_value : received_gift_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setSupergroupCustomEmojiStickerSet::setSupergroupCustomEmojiStickerSet()
  : supergroup_id_()
  , custom_emoji_sticker_set_id_()
{}

setSupergroupCustomEmojiStickerSet::setSupergroupCustomEmojiStickerSet(int53 supergroup_id_, int64 custom_emoji_sticker_set_id_)
  : supergroup_id_(supergroup_id_)
  , custom_emoji_sticker_set_id_(custom_emoji_sticker_set_id_)
{}

const std::int32_t setSupergroupCustomEmojiStickerSet::ID;

void setSupergroupCustomEmojiStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSupergroupCustomEmojiStickerSet");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("custom_emoji_sticker_set_id", custom_emoji_sticker_set_id_);
    s.store_class_end();
  }
}

setSupergroupUnrestrictBoostCount::setSupergroupUnrestrictBoostCount()
  : supergroup_id_()
  , unrestrict_boost_count_()
{}

setSupergroupUnrestrictBoostCount::setSupergroupUnrestrictBoostCount(int53 supergroup_id_, int32 unrestrict_boost_count_)
  : supergroup_id_(supergroup_id_)
  , unrestrict_boost_count_(unrestrict_boost_count_)
{}

const std::int32_t setSupergroupUnrestrictBoostCount::ID;

void setSupergroupUnrestrictBoostCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSupergroupUnrestrictBoostCount");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("unrestrict_boost_count", unrestrict_boost_count_);
    s.store_class_end();
  }
}

setUserNote::setUserNote()
  : user_id_()
  , note_()
{}

setUserNote::setUserNote(int53 user_id_, object_ptr<formattedText> &&note_)
  : user_id_(user_id_)
  , note_(std::move(note_))
{}

const std::int32_t setUserNote::ID;

void setUserNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUserNote");
    s.store_field("user_id", user_id_);
    s.store_object_field("note", static_cast<const BaseObject *>(note_.get()));
    s.store_class_end();
  }
}

setUsername::setUsername()
  : username_()
{}

setUsername::setUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t setUsername::ID;

void setUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

testCallEmpty::testCallEmpty() {
}

const std::int32_t testCallEmpty::ID;

void testCallEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testCallEmpty");
    s.store_class_end();
  }
}

toggleChatFolderTags::toggleChatFolderTags()
  : are_tags_enabled_()
{}

toggleChatFolderTags::toggleChatFolderTags(bool are_tags_enabled_)
  : are_tags_enabled_(are_tags_enabled_)
{}

const std::int32_t toggleChatFolderTags::ID;

void toggleChatFolderTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatFolderTags");
    s.store_field("are_tags_enabled", are_tags_enabled_);
    s.store_class_end();
  }
}

toggleChatIsMarkedAsUnread::toggleChatIsMarkedAsUnread()
  : chat_id_()
  , is_marked_as_unread_()
{}

toggleChatIsMarkedAsUnread::toggleChatIsMarkedAsUnread(int53 chat_id_, bool is_marked_as_unread_)
  : chat_id_(chat_id_)
  , is_marked_as_unread_(is_marked_as_unread_)
{}

const std::int32_t toggleChatIsMarkedAsUnread::ID;

void toggleChatIsMarkedAsUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatIsMarkedAsUnread");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_class_end();
  }
}

toggleDownloadIsPaused::toggleDownloadIsPaused()
  : file_id_()
  , is_paused_()
{}

toggleDownloadIsPaused::toggleDownloadIsPaused(int32 file_id_, bool is_paused_)
  : file_id_(file_id_)
  , is_paused_(is_paused_)
{}

const std::int32_t toggleDownloadIsPaused::ID;

void toggleDownloadIsPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleDownloadIsPaused");
    s.store_field("file_id", file_id_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

toggleForumTopicIsPinned::toggleForumTopicIsPinned()
  : chat_id_()
  , forum_topic_id_()
  , is_pinned_()
{}

toggleForumTopicIsPinned::toggleForumTopicIsPinned(int53 chat_id_, int32 forum_topic_id_, bool is_pinned_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t toggleForumTopicIsPinned::ID;

void toggleForumTopicIsPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleForumTopicIsPinned");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

toggleGiftIsSaved::toggleGiftIsSaved()
  : received_gift_id_()
  , is_saved_()
{}

toggleGiftIsSaved::toggleGiftIsSaved(string const &received_gift_id_, bool is_saved_)
  : received_gift_id_(received_gift_id_)
  , is_saved_(is_saved_)
{}

const std::int32_t toggleGiftIsSaved::ID;

void toggleGiftIsSaved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGiftIsSaved");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_field("is_saved", is_saved_);
    s.store_class_end();
  }
}

toggleGroupCallParticipantIsHandRaised::toggleGroupCallParticipantIsHandRaised()
  : group_call_id_()
  , participant_id_()
  , is_hand_raised_()
{}

toggleGroupCallParticipantIsHandRaised::toggleGroupCallParticipantIsHandRaised(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, bool is_hand_raised_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , is_hand_raised_(is_hand_raised_)
{}

const std::int32_t toggleGroupCallParticipantIsHandRaised::ID;

void toggleGroupCallParticipantIsHandRaised::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallParticipantIsHandRaised");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("is_hand_raised", is_hand_raised_);
    s.store_class_end();
  }
}

toggleGroupCallScreenSharingIsPaused::toggleGroupCallScreenSharingIsPaused()
  : group_call_id_()
  , is_paused_()
{}

toggleGroupCallScreenSharingIsPaused::toggleGroupCallScreenSharingIsPaused(int32 group_call_id_, bool is_paused_)
  : group_call_id_(group_call_id_)
  , is_paused_(is_paused_)
{}

const std::int32_t toggleGroupCallScreenSharingIsPaused::ID;

void toggleGroupCallScreenSharingIsPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallScreenSharingIsPaused");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

transferBusinessAccountStars::transferBusinessAccountStars()
  : business_connection_id_()
  , star_count_()
{}

transferBusinessAccountStars::transferBusinessAccountStars(string const &business_connection_id_, int53 star_count_)
  : business_connection_id_(business_connection_id_)
  , star_count_(star_count_)
{}

const std::int32_t transferBusinessAccountStars::ID;

void transferBusinessAccountStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "transferBusinessAccountStars");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

viewTrendingStickerSets::viewTrendingStickerSets()
  : sticker_set_ids_()
{}

viewTrendingStickerSets::viewTrendingStickerSets(array<int64> &&sticker_set_ids_)
  : sticker_set_ids_(std::move(sticker_set_ids_))
{}

const std::int32_t viewTrendingStickerSets::ID;

void viewTrendingStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "viewTrendingStickerSets");
    { s.store_vector_begin("sticker_set_ids", sticker_set_ids_.size()); for (const auto &_value : sticker_set_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
