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


addedProxy::addedProxy()
  : id_()
  , last_used_date_()
  , is_enabled_()
  , proxy_()
{}

addedProxy::addedProxy(int32 id_, int32 last_used_date_, bool is_enabled_, object_ptr<proxy> &&proxy_)
  : id_(id_)
  , last_used_date_(last_used_date_)
  , is_enabled_(is_enabled_)
  , proxy_(std::move(proxy_))
{}

const std::int32_t addedProxy::ID;

void addedProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addedProxy");
    s.store_field("id", id_);
    s.store_field("last_used_date", last_used_date_);
    s.store_field("is_enabled", is_enabled_);
    s.store_object_field("proxy", static_cast<const BaseObject *>(proxy_.get()));
    s.store_class_end();
  }
}

animations::animations()
  : animations_()
{}

animations::animations(array<object_ptr<animation>> &&animations_)
  : animations_(std::move(animations_))
{}

const std::int32_t animations::ID;

void animations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "animations");
    { s.store_vector_begin("animations", animations_.size()); for (const auto &_value : animations_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

auctionBid::auctionBid()
  : star_count_()
  , bid_date_()
  , position_()
{}

auctionBid::auctionBid(int53 star_count_, int32 bid_date_, int32 position_)
  : star_count_(star_count_)
  , bid_date_(bid_date_)
  , position_(position_)
{}

const std::int32_t auctionBid::ID;

void auctionBid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auctionBid");
    s.store_field("star_count", star_count_);
    s.store_field("bid_date", bid_date_);
    s.store_field("position", position_);
    s.store_class_end();
  }
}

authenticationCodeTypeTelegramMessage::authenticationCodeTypeTelegramMessage()
  : length_()
{}

authenticationCodeTypeTelegramMessage::authenticationCodeTypeTelegramMessage(int32 length_)
  : length_(length_)
{}

const std::int32_t authenticationCodeTypeTelegramMessage::ID;

void authenticationCodeTypeTelegramMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeTelegramMessage");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeSms::authenticationCodeTypeSms()
  : length_()
{}

authenticationCodeTypeSms::authenticationCodeTypeSms(int32 length_)
  : length_(length_)
{}

const std::int32_t authenticationCodeTypeSms::ID;

void authenticationCodeTypeSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeSms");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeSmsWord::authenticationCodeTypeSmsWord()
  : first_letter_()
{}

authenticationCodeTypeSmsWord::authenticationCodeTypeSmsWord(string const &first_letter_)
  : first_letter_(first_letter_)
{}

const std::int32_t authenticationCodeTypeSmsWord::ID;

void authenticationCodeTypeSmsWord::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeSmsWord");
    s.store_field("first_letter", first_letter_);
    s.store_class_end();
  }
}

authenticationCodeTypeSmsPhrase::authenticationCodeTypeSmsPhrase()
  : first_word_()
{}

authenticationCodeTypeSmsPhrase::authenticationCodeTypeSmsPhrase(string const &first_word_)
  : first_word_(first_word_)
{}

const std::int32_t authenticationCodeTypeSmsPhrase::ID;

void authenticationCodeTypeSmsPhrase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeSmsPhrase");
    s.store_field("first_word", first_word_);
    s.store_class_end();
  }
}

authenticationCodeTypeCall::authenticationCodeTypeCall()
  : length_()
{}

authenticationCodeTypeCall::authenticationCodeTypeCall(int32 length_)
  : length_(length_)
{}

const std::int32_t authenticationCodeTypeCall::ID;

void authenticationCodeTypeCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeCall");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeFlashCall::authenticationCodeTypeFlashCall()
  : pattern_()
{}

authenticationCodeTypeFlashCall::authenticationCodeTypeFlashCall(string const &pattern_)
  : pattern_(pattern_)
{}

const std::int32_t authenticationCodeTypeFlashCall::ID;

void authenticationCodeTypeFlashCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeFlashCall");
    s.store_field("pattern", pattern_);
    s.store_class_end();
  }
}

authenticationCodeTypeMissedCall::authenticationCodeTypeMissedCall()
  : phone_number_prefix_()
  , length_()
{}

authenticationCodeTypeMissedCall::authenticationCodeTypeMissedCall(string const &phone_number_prefix_, int32 length_)
  : phone_number_prefix_(phone_number_prefix_)
  , length_(length_)
{}

const std::int32_t authenticationCodeTypeMissedCall::ID;

void authenticationCodeTypeMissedCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeMissedCall");
    s.store_field("phone_number_prefix", phone_number_prefix_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeFragment::authenticationCodeTypeFragment()
  : url_()
  , length_()
{}

authenticationCodeTypeFragment::authenticationCodeTypeFragment(string const &url_, int32 length_)
  : url_(url_)
  , length_(length_)
{}

const std::int32_t authenticationCodeTypeFragment::ID;

void authenticationCodeTypeFragment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeFragment");
    s.store_field("url", url_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeFirebaseAndroid::authenticationCodeTypeFirebaseAndroid()
  : device_verification_parameters_()
  , length_()
{}

authenticationCodeTypeFirebaseAndroid::authenticationCodeTypeFirebaseAndroid(object_ptr<FirebaseDeviceVerificationParameters> &&device_verification_parameters_, int32 length_)
  : device_verification_parameters_(std::move(device_verification_parameters_))
  , length_(length_)
{}

const std::int32_t authenticationCodeTypeFirebaseAndroid::ID;

void authenticationCodeTypeFirebaseAndroid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeFirebaseAndroid");
    s.store_object_field("device_verification_parameters", static_cast<const BaseObject *>(device_verification_parameters_.get()));
    s.store_field("length", length_);
    s.store_class_end();
  }
}

authenticationCodeTypeFirebaseIos::authenticationCodeTypeFirebaseIos()
  : receipt_()
  , push_timeout_()
  , length_()
{}

authenticationCodeTypeFirebaseIos::authenticationCodeTypeFirebaseIos(string const &receipt_, int32 push_timeout_, int32 length_)
  : receipt_(receipt_)
  , push_timeout_(push_timeout_)
  , length_(length_)
{}

const std::int32_t authenticationCodeTypeFirebaseIos::ID;

void authenticationCodeTypeFirebaseIos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authenticationCodeTypeFirebaseIos");
    s.store_field("receipt", receipt_);
    s.store_field("push_timeout", push_timeout_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

autosaveSettingsScopePrivateChats::autosaveSettingsScopePrivateChats() {
}

const std::int32_t autosaveSettingsScopePrivateChats::ID;

void autosaveSettingsScopePrivateChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autosaveSettingsScopePrivateChats");
    s.store_class_end();
  }
}

autosaveSettingsScopeGroupChats::autosaveSettingsScopeGroupChats() {
}

const std::int32_t autosaveSettingsScopeGroupChats::ID;

void autosaveSettingsScopeGroupChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autosaveSettingsScopeGroupChats");
    s.store_class_end();
  }
}

autosaveSettingsScopeChannelChats::autosaveSettingsScopeChannelChats() {
}

const std::int32_t autosaveSettingsScopeChannelChats::ID;

void autosaveSettingsScopeChannelChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autosaveSettingsScopeChannelChats");
    s.store_class_end();
  }
}

autosaveSettingsScopeChat::autosaveSettingsScopeChat()
  : chat_id_()
{}

autosaveSettingsScopeChat::autosaveSettingsScopeChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t autosaveSettingsScopeChat::ID;

void autosaveSettingsScopeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autosaveSettingsScopeChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

availableReactions::availableReactions()
  : top_reactions_()
  , recent_reactions_()
  , popular_reactions_()
  , allow_custom_emoji_()
  , are_tags_()
  , unavailability_reason_()
{}

availableReactions::availableReactions(array<object_ptr<availableReaction>> &&top_reactions_, array<object_ptr<availableReaction>> &&recent_reactions_, array<object_ptr<availableReaction>> &&popular_reactions_, bool allow_custom_emoji_, bool are_tags_, object_ptr<ReactionUnavailabilityReason> &&unavailability_reason_)
  : top_reactions_(std::move(top_reactions_))
  , recent_reactions_(std::move(recent_reactions_))
  , popular_reactions_(std::move(popular_reactions_))
  , allow_custom_emoji_(allow_custom_emoji_)
  , are_tags_(are_tags_)
  , unavailability_reason_(std::move(unavailability_reason_))
{}

const std::int32_t availableReactions::ID;

void availableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableReactions");
    { s.store_vector_begin("top_reactions", top_reactions_.size()); for (const auto &_value : top_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("recent_reactions", recent_reactions_.size()); for (const auto &_value : recent_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("popular_reactions", popular_reactions_.size()); for (const auto &_value : popular_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("allow_custom_emoji", allow_custom_emoji_);
    s.store_field("are_tags", are_tags_);
    s.store_object_field("unavailability_reason", static_cast<const BaseObject *>(unavailability_reason_.get()));
    s.store_class_end();
  }
}

basicGroup::basicGroup()
  : id_()
  , member_count_()
  , status_()
  , is_active_()
  , upgraded_to_supergroup_id_()
{}

basicGroup::basicGroup(int53 id_, int32 member_count_, object_ptr<ChatMemberStatus> &&status_, bool is_active_, int53 upgraded_to_supergroup_id_)
  : id_(id_)
  , member_count_(member_count_)
  , status_(std::move(status_))
  , is_active_(is_active_)
  , upgraded_to_supergroup_id_(upgraded_to_supergroup_id_)
{}

const std::int32_t basicGroup::ID;

void basicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "basicGroup");
    s.store_field("id", id_);
    s.store_field("member_count", member_count_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("is_active", is_active_);
    s.store_field("upgraded_to_supergroup_id", upgraded_to_supergroup_id_);
    s.store_class_end();
  }
}

botCommands::botCommands()
  : bot_user_id_()
  , commands_()
{}

botCommands::botCommands(int53 bot_user_id_, array<object_ptr<botCommand>> &&commands_)
  : bot_user_id_(bot_user_id_)
  , commands_(std::move(commands_))
{}

const std::int32_t botCommands::ID;

void botCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommands");
    s.store_field("bot_user_id", bot_user_id_);
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

botMediaPreview::botMediaPreview()
  : date_()
  , content_()
{}

botMediaPreview::botMediaPreview(int32 date_, object_ptr<StoryContent> &&content_)
  : date_(date_)
  , content_(std::move(content_))
{}

const std::int32_t botMediaPreview::ID;

void botMediaPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMediaPreview");
    s.store_field("date", date_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

botMenuButton::botMenuButton()
  : text_()
  , url_()
{}

botMenuButton::botMenuButton(string const &text_, string const &url_)
  : text_(text_)
  , url_(url_)
{}

const std::int32_t botMenuButton::ID;

void botMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMenuButton");
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

businessConnection::businessConnection()
  : id_()
  , user_id_()
  , user_chat_id_()
  , date_()
  , rights_()
  , is_enabled_()
{}

businessConnection::businessConnection(string const &id_, int53 user_id_, int53 user_chat_id_, int32 date_, object_ptr<businessBotRights> &&rights_, bool is_enabled_)
  : id_(id_)
  , user_id_(user_id_)
  , user_chat_id_(user_chat_id_)
  , date_(date_)
  , rights_(std::move(rights_))
  , is_enabled_(is_enabled_)
{}

const std::int32_t businessConnection::ID;

void businessConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessConnection");
    s.store_field("id", id_);
    s.store_field("user_id", user_id_);
    s.store_field("user_chat_id", user_chat_id_);
    s.store_field("date", date_);
    s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get()));
    s.store_field("is_enabled", is_enabled_);
    s.store_class_end();
  }
}

businessFeatures::businessFeatures()
  : features_()
{}

businessFeatures::businessFeatures(array<object_ptr<BusinessFeature>> &&features_)
  : features_(std::move(features_))
{}

const std::int32_t businessFeatures::ID;

void businessFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatures");
    { s.store_vector_begin("features", features_.size()); for (const auto &_value : features_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

callId::callId()
  : id_()
{}

callId::callId(int32 id_)
  : id_(id_)
{}

const std::int32_t callId::ID;

void callId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

callbackQueryPayloadData::callbackQueryPayloadData()
  : data_()
{}

callbackQueryPayloadData::callbackQueryPayloadData(bytes const &data_)
  : data_(std::move(data_))
{}

const std::int32_t callbackQueryPayloadData::ID;

void callbackQueryPayloadData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callbackQueryPayloadData");
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

callbackQueryPayloadDataWithPassword::callbackQueryPayloadDataWithPassword()
  : password_()
  , data_()
{}

callbackQueryPayloadDataWithPassword::callbackQueryPayloadDataWithPassword(string const &password_, bytes const &data_)
  : password_(password_)
  , data_(std::move(data_))
{}

const std::int32_t callbackQueryPayloadDataWithPassword::ID;

void callbackQueryPayloadDataWithPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callbackQueryPayloadDataWithPassword");
    s.store_field("password", password_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

callbackQueryPayloadGame::callbackQueryPayloadGame()
  : game_short_name_()
{}

callbackQueryPayloadGame::callbackQueryPayloadGame(string const &game_short_name_)
  : game_short_name_(game_short_name_)
{}

const std::int32_t callbackQueryPayloadGame::ID;

void callbackQueryPayloadGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callbackQueryPayloadGame");
    s.store_field("game_short_name", game_short_name_);
    s.store_class_end();
  }
}

chat::chat()
  : id_()
  , type_()
  , title_()
  , photo_()
  , accent_color_id_()
  , background_custom_emoji_id_()
  , upgraded_gift_colors_()
  , profile_accent_color_id_()
  , profile_background_custom_emoji_id_()
  , permissions_()
  , last_message_()
  , positions_()
  , chat_lists_()
  , message_sender_id_()
  , block_list_()
  , has_protected_content_()
  , is_translatable_()
  , is_marked_as_unread_()
  , view_as_topics_()
  , has_scheduled_messages_()
  , can_be_deleted_only_for_self_()
  , can_be_deleted_for_all_users_()
  , can_be_reported_()
  , default_disable_notification_()
  , unread_count_()
  , last_read_inbox_message_id_()
  , last_read_outbox_message_id_()
  , unread_mention_count_()
  , unread_reaction_count_()
  , unread_poll_vote_count_()
  , notification_settings_()
  , available_reactions_()
  , message_auto_delete_time_()
  , emoji_status_()
  , background_()
  , theme_()
  , action_bar_()
  , business_bot_manage_bar_()
  , video_chat_()
  , pending_join_requests_()
  , reply_markup_message_id_()
  , draft_message_()
  , client_data_()
{}

chat::chat(int53 id_, object_ptr<ChatType> &&type_, string const &title_, object_ptr<chatPhotoInfo> &&photo_, int32 accent_color_id_, int64 background_custom_emoji_id_, object_ptr<upgradedGiftColors> &&upgraded_gift_colors_, int32 profile_accent_color_id_, int64 profile_background_custom_emoji_id_, object_ptr<chatPermissions> &&permissions_, object_ptr<message> &&last_message_, array<object_ptr<chatPosition>> &&positions_, array<object_ptr<ChatList>> &&chat_lists_, object_ptr<MessageSender> &&message_sender_id_, object_ptr<BlockList> &&block_list_, bool has_protected_content_, bool is_translatable_, bool is_marked_as_unread_, bool view_as_topics_, bool has_scheduled_messages_, bool can_be_deleted_only_for_self_, bool can_be_deleted_for_all_users_, bool can_be_reported_, bool default_disable_notification_, int32 unread_count_, int53 last_read_inbox_message_id_, int53 last_read_outbox_message_id_, int32 unread_mention_count_, int32 unread_reaction_count_, int32 unread_poll_vote_count_, object_ptr<chatNotificationSettings> &&notification_settings_, object_ptr<ChatAvailableReactions> &&available_reactions_, int32 message_auto_delete_time_, object_ptr<emojiStatus> &&emoji_status_, object_ptr<chatBackground> &&background_, object_ptr<ChatTheme> &&theme_, object_ptr<ChatActionBar> &&action_bar_, object_ptr<businessBotManageBar> &&business_bot_manage_bar_, object_ptr<videoChat> &&video_chat_, object_ptr<chatJoinRequestsInfo> &&pending_join_requests_, int53 reply_markup_message_id_, object_ptr<draftMessage> &&draft_message_, string const &client_data_)
  : id_(id_)
  , type_(std::move(type_))
  , title_(title_)
  , photo_(std::move(photo_))
  , accent_color_id_(accent_color_id_)
  , background_custom_emoji_id_(background_custom_emoji_id_)
  , upgraded_gift_colors_(std::move(upgraded_gift_colors_))
  , profile_accent_color_id_(profile_accent_color_id_)
  , profile_background_custom_emoji_id_(profile_background_custom_emoji_id_)
  , permissions_(std::move(permissions_))
  , last_message_(std::move(last_message_))
  , positions_(std::move(positions_))
  , chat_lists_(std::move(chat_lists_))
  , message_sender_id_(std::move(message_sender_id_))
  , block_list_(std::move(block_list_))
  , has_protected_content_(has_protected_content_)
  , is_translatable_(is_translatable_)
  , is_marked_as_unread_(is_marked_as_unread_)
  , view_as_topics_(view_as_topics_)
  , has_scheduled_messages_(has_scheduled_messages_)
  , can_be_deleted_only_for_self_(can_be_deleted_only_for_self_)
  , can_be_deleted_for_all_users_(can_be_deleted_for_all_users_)
  , can_be_reported_(can_be_reported_)
  , default_disable_notification_(default_disable_notification_)
  , unread_count_(unread_count_)
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
  , unread_mention_count_(unread_mention_count_)
  , unread_reaction_count_(unread_reaction_count_)
  , unread_poll_vote_count_(unread_poll_vote_count_)
  , notification_settings_(std::move(notification_settings_))
  , available_reactions_(std::move(available_reactions_))
  , message_auto_delete_time_(message_auto_delete_time_)
  , emoji_status_(std::move(emoji_status_))
  , background_(std::move(background_))
  , theme_(std::move(theme_))
  , action_bar_(std::move(action_bar_))
  , business_bot_manage_bar_(std::move(business_bot_manage_bar_))
  , video_chat_(std::move(video_chat_))
  , pending_join_requests_(std::move(pending_join_requests_))
  , reply_markup_message_id_(reply_markup_message_id_)
  , draft_message_(std::move(draft_message_))
  , client_data_(client_data_)
{}

const std::int32_t chat::ID;

void chat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chat");
    s.store_field("id", id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("background_custom_emoji_id", background_custom_emoji_id_);
    s.store_object_field("upgraded_gift_colors", static_cast<const BaseObject *>(upgraded_gift_colors_.get()));
    s.store_field("profile_accent_color_id", profile_accent_color_id_);
    s.store_field("profile_background_custom_emoji_id", profile_background_custom_emoji_id_);
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_object_field("last_message", static_cast<const BaseObject *>(last_message_.get()));
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chat_lists", chat_lists_.size()); for (const auto &_value : chat_lists_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    s.store_object_field("block_list", static_cast<const BaseObject *>(block_list_.get()));
    s.store_field("has_protected_content", has_protected_content_);
    s.store_field("is_translatable", is_translatable_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_field("view_as_topics", view_as_topics_);
    s.store_field("has_scheduled_messages", has_scheduled_messages_);
    s.store_field("can_be_deleted_only_for_self", can_be_deleted_only_for_self_);
    s.store_field("can_be_deleted_for_all_users", can_be_deleted_for_all_users_);
    s.store_field("can_be_reported", can_be_reported_);
    s.store_field("default_disable_notification", default_disable_notification_);
    s.store_field("unread_count", unread_count_);
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_field("unread_mention_count", unread_mention_count_);
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_field("unread_poll_vote_count", unread_poll_vote_count_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_object_field("available_reactions", static_cast<const BaseObject *>(available_reactions_.get()));
    s.store_field("message_auto_delete_time", message_auto_delete_time_);
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_object_field("action_bar", static_cast<const BaseObject *>(action_bar_.get()));
    s.store_object_field("business_bot_manage_bar", static_cast<const BaseObject *>(business_bot_manage_bar_.get()));
    s.store_object_field("video_chat", static_cast<const BaseObject *>(video_chat_.get()));
    s.store_object_field("pending_join_requests", static_cast<const BaseObject *>(pending_join_requests_.get()));
    s.store_field("reply_markup_message_id", reply_markup_message_id_);
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_field("client_data", client_data_);
    s.store_class_end();
  }
}

chatAdministratorRights::chatAdministratorRights()
  : can_manage_chat_()
  , can_change_info_()
  , can_post_messages_()
  , can_edit_messages_()
  , can_delete_messages_()
  , can_invite_users_()
  , can_restrict_members_()
  , can_pin_messages_()
  , can_manage_topics_()
  , can_promote_members_()
  , can_manage_video_chats_()
  , can_post_stories_()
  , can_edit_stories_()
  , can_delete_stories_()
  , can_manage_direct_messages_()
  , can_manage_tags_()
  , is_anonymous_()
{}

chatAdministratorRights::chatAdministratorRights(bool can_manage_chat_, bool can_change_info_, bool can_post_messages_, bool can_edit_messages_, bool can_delete_messages_, bool can_invite_users_, bool can_restrict_members_, bool can_pin_messages_, bool can_manage_topics_, bool can_promote_members_, bool can_manage_video_chats_, bool can_post_stories_, bool can_edit_stories_, bool can_delete_stories_, bool can_manage_direct_messages_, bool can_manage_tags_, bool is_anonymous_)
  : can_manage_chat_(can_manage_chat_)
  , can_change_info_(can_change_info_)
  , can_post_messages_(can_post_messages_)
  , can_edit_messages_(can_edit_messages_)
  , can_delete_messages_(can_delete_messages_)
  , can_invite_users_(can_invite_users_)
  , can_restrict_members_(can_restrict_members_)
  , can_pin_messages_(can_pin_messages_)
  , can_manage_topics_(can_manage_topics_)
  , can_promote_members_(can_promote_members_)
  , can_manage_video_chats_(can_manage_video_chats_)
  , can_post_stories_(can_post_stories_)
  , can_edit_stories_(can_edit_stories_)
  , can_delete_stories_(can_delete_stories_)
  , can_manage_direct_messages_(can_manage_direct_messages_)
  , can_manage_tags_(can_manage_tags_)
  , is_anonymous_(is_anonymous_)
{}

const std::int32_t chatAdministratorRights::ID;

void chatAdministratorRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdministratorRights");
    s.store_field("can_manage_chat", can_manage_chat_);
    s.store_field("can_change_info", can_change_info_);
    s.store_field("can_post_messages", can_post_messages_);
    s.store_field("can_edit_messages", can_edit_messages_);
    s.store_field("can_delete_messages", can_delete_messages_);
    s.store_field("can_invite_users", can_invite_users_);
    s.store_field("can_restrict_members", can_restrict_members_);
    s.store_field("can_pin_messages", can_pin_messages_);
    s.store_field("can_manage_topics", can_manage_topics_);
    s.store_field("can_promote_members", can_promote_members_);
    s.store_field("can_manage_video_chats", can_manage_video_chats_);
    s.store_field("can_post_stories", can_post_stories_);
    s.store_field("can_edit_stories", can_edit_stories_);
    s.store_field("can_delete_stories", can_delete_stories_);
    s.store_field("can_manage_direct_messages", can_manage_direct_messages_);
    s.store_field("can_manage_tags", can_manage_tags_);
    s.store_field("is_anonymous", is_anonymous_);
    s.store_class_end();
  }
}

chatBackground::chatBackground()
  : background_()
  , dark_theme_dimming_()
{}

chatBackground::chatBackground(object_ptr<background> &&background_, int32 dark_theme_dimming_)
  : background_(std::move(background_))
  , dark_theme_dimming_(dark_theme_dimming_)
{}

const std::int32_t chatBackground::ID;

void chatBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBackground");
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_field("dark_theme_dimming", dark_theme_dimming_);
    s.store_class_end();
  }
}

chatEventMessageEdited::chatEventMessageEdited()
  : old_message_()
  , new_message_()
{}

chatEventMessageEdited::chatEventMessageEdited(object_ptr<message> &&old_message_, object_ptr<message> &&new_message_)
  : old_message_(std::move(old_message_))
  , new_message_(std::move(new_message_))
{}

const std::int32_t chatEventMessageEdited::ID;

void chatEventMessageEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessageEdited");
    s.store_object_field("old_message", static_cast<const BaseObject *>(old_message_.get()));
    s.store_object_field("new_message", static_cast<const BaseObject *>(new_message_.get()));
    s.store_class_end();
  }
}

chatEventMessageDeleted::chatEventMessageDeleted()
  : message_()
  , can_report_anti_spam_false_positive_()
{}

chatEventMessageDeleted::chatEventMessageDeleted(object_ptr<message> &&message_, bool can_report_anti_spam_false_positive_)
  : message_(std::move(message_))
  , can_report_anti_spam_false_positive_(can_report_anti_spam_false_positive_)
{}

const std::int32_t chatEventMessageDeleted::ID;

void chatEventMessageDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessageDeleted");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("can_report_anti_spam_false_positive", can_report_anti_spam_false_positive_);
    s.store_class_end();
  }
}

chatEventMessagePinned::chatEventMessagePinned()
  : message_()
{}

chatEventMessagePinned::chatEventMessagePinned(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t chatEventMessagePinned::ID;

void chatEventMessagePinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessagePinned");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

chatEventMessageUnpinned::chatEventMessageUnpinned()
  : message_()
{}

chatEventMessageUnpinned::chatEventMessageUnpinned(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t chatEventMessageUnpinned::ID;

void chatEventMessageUnpinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessageUnpinned");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

chatEventPollStopped::chatEventPollStopped()
  : message_()
{}

chatEventPollStopped::chatEventPollStopped(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t chatEventPollStopped::ID;

void chatEventPollStopped::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventPollStopped");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

chatEventMemberJoined::chatEventMemberJoined() {
}

const std::int32_t chatEventMemberJoined::ID;

void chatEventMemberJoined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberJoined");
    s.store_class_end();
  }
}

chatEventMemberJoinedByInviteLink::chatEventMemberJoinedByInviteLink()
  : invite_link_()
  , via_chat_folder_invite_link_()
{}

chatEventMemberJoinedByInviteLink::chatEventMemberJoinedByInviteLink(object_ptr<chatInviteLink> &&invite_link_, bool via_chat_folder_invite_link_)
  : invite_link_(std::move(invite_link_))
  , via_chat_folder_invite_link_(via_chat_folder_invite_link_)
{}

const std::int32_t chatEventMemberJoinedByInviteLink::ID;

void chatEventMemberJoinedByInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberJoinedByInviteLink");
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_field("via_chat_folder_invite_link", via_chat_folder_invite_link_);
    s.store_class_end();
  }
}

chatEventMemberJoinedByRequest::chatEventMemberJoinedByRequest()
  : approver_user_id_()
  , invite_link_()
{}

chatEventMemberJoinedByRequest::chatEventMemberJoinedByRequest(int53 approver_user_id_, object_ptr<chatInviteLink> &&invite_link_)
  : approver_user_id_(approver_user_id_)
  , invite_link_(std::move(invite_link_))
{}

const std::int32_t chatEventMemberJoinedByRequest::ID;

void chatEventMemberJoinedByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberJoinedByRequest");
    s.store_field("approver_user_id", approver_user_id_);
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_class_end();
  }
}

chatEventMemberInvited::chatEventMemberInvited()
  : user_id_()
  , status_()
{}

chatEventMemberInvited::chatEventMemberInvited(int53 user_id_, object_ptr<ChatMemberStatus> &&status_)
  : user_id_(user_id_)
  , status_(std::move(status_))
{}

const std::int32_t chatEventMemberInvited::ID;

void chatEventMemberInvited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberInvited");
    s.store_field("user_id", user_id_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

chatEventMemberLeft::chatEventMemberLeft() {
}

const std::int32_t chatEventMemberLeft::ID;

void chatEventMemberLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberLeft");
    s.store_class_end();
  }
}

chatEventMemberPromoted::chatEventMemberPromoted()
  : user_id_()
  , old_status_()
  , new_status_()
{}

chatEventMemberPromoted::chatEventMemberPromoted(int53 user_id_, object_ptr<ChatMemberStatus> &&old_status_, object_ptr<ChatMemberStatus> &&new_status_)
  : user_id_(user_id_)
  , old_status_(std::move(old_status_))
  , new_status_(std::move(new_status_))
{}

const std::int32_t chatEventMemberPromoted::ID;

void chatEventMemberPromoted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberPromoted");
    s.store_field("user_id", user_id_);
    s.store_object_field("old_status", static_cast<const BaseObject *>(old_status_.get()));
    s.store_object_field("new_status", static_cast<const BaseObject *>(new_status_.get()));
    s.store_class_end();
  }
}

chatEventMemberRestricted::chatEventMemberRestricted()
  : member_id_()
  , old_status_()
  , new_status_()
{}

chatEventMemberRestricted::chatEventMemberRestricted(object_ptr<MessageSender> &&member_id_, object_ptr<ChatMemberStatus> &&old_status_, object_ptr<ChatMemberStatus> &&new_status_)
  : member_id_(std::move(member_id_))
  , old_status_(std::move(old_status_))
  , new_status_(std::move(new_status_))
{}

const std::int32_t chatEventMemberRestricted::ID;

void chatEventMemberRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberRestricted");
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_object_field("old_status", static_cast<const BaseObject *>(old_status_.get()));
    s.store_object_field("new_status", static_cast<const BaseObject *>(new_status_.get()));
    s.store_class_end();
  }
}

chatEventMemberTagChanged::chatEventMemberTagChanged()
  : user_id_()
  , old_tag_()
  , new_tag_()
{}

chatEventMemberTagChanged::chatEventMemberTagChanged(int53 user_id_, string const &old_tag_, string const &new_tag_)
  : user_id_(user_id_)
  , old_tag_(old_tag_)
  , new_tag_(new_tag_)
{}

const std::int32_t chatEventMemberTagChanged::ID;

void chatEventMemberTagChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberTagChanged");
    s.store_field("user_id", user_id_);
    s.store_field("old_tag", old_tag_);
    s.store_field("new_tag", new_tag_);
    s.store_class_end();
  }
}

chatEventMemberSubscriptionExtended::chatEventMemberSubscriptionExtended()
  : user_id_()
  , old_status_()
  , new_status_()
{}

chatEventMemberSubscriptionExtended::chatEventMemberSubscriptionExtended(int53 user_id_, object_ptr<ChatMemberStatus> &&old_status_, object_ptr<ChatMemberStatus> &&new_status_)
  : user_id_(user_id_)
  , old_status_(std::move(old_status_))
  , new_status_(std::move(new_status_))
{}

const std::int32_t chatEventMemberSubscriptionExtended::ID;

void chatEventMemberSubscriptionExtended::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMemberSubscriptionExtended");
    s.store_field("user_id", user_id_);
    s.store_object_field("old_status", static_cast<const BaseObject *>(old_status_.get()));
    s.store_object_field("new_status", static_cast<const BaseObject *>(new_status_.get()));
    s.store_class_end();
  }
}

chatEventAvailableReactionsChanged::chatEventAvailableReactionsChanged()
  : old_available_reactions_()
  , new_available_reactions_()
{}

chatEventAvailableReactionsChanged::chatEventAvailableReactionsChanged(object_ptr<ChatAvailableReactions> &&old_available_reactions_, object_ptr<ChatAvailableReactions> &&new_available_reactions_)
  : old_available_reactions_(std::move(old_available_reactions_))
  , new_available_reactions_(std::move(new_available_reactions_))
{}

const std::int32_t chatEventAvailableReactionsChanged::ID;

void chatEventAvailableReactionsChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventAvailableReactionsChanged");
    s.store_object_field("old_available_reactions", static_cast<const BaseObject *>(old_available_reactions_.get()));
    s.store_object_field("new_available_reactions", static_cast<const BaseObject *>(new_available_reactions_.get()));
    s.store_class_end();
  }
}

chatEventBackgroundChanged::chatEventBackgroundChanged()
  : old_background_()
  , new_background_()
{}

chatEventBackgroundChanged::chatEventBackgroundChanged(object_ptr<chatBackground> &&old_background_, object_ptr<chatBackground> &&new_background_)
  : old_background_(std::move(old_background_))
  , new_background_(std::move(new_background_))
{}

const std::int32_t chatEventBackgroundChanged::ID;

void chatEventBackgroundChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventBackgroundChanged");
    s.store_object_field("old_background", static_cast<const BaseObject *>(old_background_.get()));
    s.store_object_field("new_background", static_cast<const BaseObject *>(new_background_.get()));
    s.store_class_end();
  }
}

chatEventDescriptionChanged::chatEventDescriptionChanged()
  : old_description_()
  , new_description_()
{}

chatEventDescriptionChanged::chatEventDescriptionChanged(string const &old_description_, string const &new_description_)
  : old_description_(old_description_)
  , new_description_(new_description_)
{}

const std::int32_t chatEventDescriptionChanged::ID;

void chatEventDescriptionChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventDescriptionChanged");
    s.store_field("old_description", old_description_);
    s.store_field("new_description", new_description_);
    s.store_class_end();
  }
}

chatEventEmojiStatusChanged::chatEventEmojiStatusChanged()
  : old_emoji_status_()
  , new_emoji_status_()
{}

chatEventEmojiStatusChanged::chatEventEmojiStatusChanged(object_ptr<emojiStatus> &&old_emoji_status_, object_ptr<emojiStatus> &&new_emoji_status_)
  : old_emoji_status_(std::move(old_emoji_status_))
  , new_emoji_status_(std::move(new_emoji_status_))
{}

const std::int32_t chatEventEmojiStatusChanged::ID;

void chatEventEmojiStatusChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventEmojiStatusChanged");
    s.store_object_field("old_emoji_status", static_cast<const BaseObject *>(old_emoji_status_.get()));
    s.store_object_field("new_emoji_status", static_cast<const BaseObject *>(new_emoji_status_.get()));
    s.store_class_end();
  }
}

chatEventLinkedChatChanged::chatEventLinkedChatChanged()
  : old_linked_chat_id_()
  , new_linked_chat_id_()
{}

chatEventLinkedChatChanged::chatEventLinkedChatChanged(int53 old_linked_chat_id_, int53 new_linked_chat_id_)
  : old_linked_chat_id_(old_linked_chat_id_)
  , new_linked_chat_id_(new_linked_chat_id_)
{}

const std::int32_t chatEventLinkedChatChanged::ID;

void chatEventLinkedChatChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventLinkedChatChanged");
    s.store_field("old_linked_chat_id", old_linked_chat_id_);
    s.store_field("new_linked_chat_id", new_linked_chat_id_);
    s.store_class_end();
  }
}

chatEventLocationChanged::chatEventLocationChanged()
  : old_location_()
  , new_location_()
{}

chatEventLocationChanged::chatEventLocationChanged(object_ptr<chatLocation> &&old_location_, object_ptr<chatLocation> &&new_location_)
  : old_location_(std::move(old_location_))
  , new_location_(std::move(new_location_))
{}

const std::int32_t chatEventLocationChanged::ID;

void chatEventLocationChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventLocationChanged");
    s.store_object_field("old_location", static_cast<const BaseObject *>(old_location_.get()));
    s.store_object_field("new_location", static_cast<const BaseObject *>(new_location_.get()));
    s.store_class_end();
  }
}

chatEventMessageAutoDeleteTimeChanged::chatEventMessageAutoDeleteTimeChanged()
  : old_message_auto_delete_time_()
  , new_message_auto_delete_time_()
{}

chatEventMessageAutoDeleteTimeChanged::chatEventMessageAutoDeleteTimeChanged(int32 old_message_auto_delete_time_, int32 new_message_auto_delete_time_)
  : old_message_auto_delete_time_(old_message_auto_delete_time_)
  , new_message_auto_delete_time_(new_message_auto_delete_time_)
{}

const std::int32_t chatEventMessageAutoDeleteTimeChanged::ID;

void chatEventMessageAutoDeleteTimeChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventMessageAutoDeleteTimeChanged");
    s.store_field("old_message_auto_delete_time", old_message_auto_delete_time_);
    s.store_field("new_message_auto_delete_time", new_message_auto_delete_time_);
    s.store_class_end();
  }
}

chatEventPermissionsChanged::chatEventPermissionsChanged()
  : old_permissions_()
  , new_permissions_()
{}

chatEventPermissionsChanged::chatEventPermissionsChanged(object_ptr<chatPermissions> &&old_permissions_, object_ptr<chatPermissions> &&new_permissions_)
  : old_permissions_(std::move(old_permissions_))
  , new_permissions_(std::move(new_permissions_))
{}

const std::int32_t chatEventPermissionsChanged::ID;

void chatEventPermissionsChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventPermissionsChanged");
    s.store_object_field("old_permissions", static_cast<const BaseObject *>(old_permissions_.get()));
    s.store_object_field("new_permissions", static_cast<const BaseObject *>(new_permissions_.get()));
    s.store_class_end();
  }
}

chatEventPhotoChanged::chatEventPhotoChanged()
  : old_photo_()
  , new_photo_()
{}

chatEventPhotoChanged::chatEventPhotoChanged(object_ptr<chatPhoto> &&old_photo_, object_ptr<chatPhoto> &&new_photo_)
  : old_photo_(std::move(old_photo_))
  , new_photo_(std::move(new_photo_))
{}

const std::int32_t chatEventPhotoChanged::ID;

void chatEventPhotoChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventPhotoChanged");
    s.store_object_field("old_photo", static_cast<const BaseObject *>(old_photo_.get()));
    s.store_object_field("new_photo", static_cast<const BaseObject *>(new_photo_.get()));
    s.store_class_end();
  }
}

chatEventSlowModeDelayChanged::chatEventSlowModeDelayChanged()
  : old_slow_mode_delay_()
  , new_slow_mode_delay_()
{}

chatEventSlowModeDelayChanged::chatEventSlowModeDelayChanged(int32 old_slow_mode_delay_, int32 new_slow_mode_delay_)
  : old_slow_mode_delay_(old_slow_mode_delay_)
  , new_slow_mode_delay_(new_slow_mode_delay_)
{}

const std::int32_t chatEventSlowModeDelayChanged::ID;

void chatEventSlowModeDelayChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventSlowModeDelayChanged");
    s.store_field("old_slow_mode_delay", old_slow_mode_delay_);
    s.store_field("new_slow_mode_delay", new_slow_mode_delay_);
    s.store_class_end();
  }
}

chatEventStickerSetChanged::chatEventStickerSetChanged()
  : old_sticker_set_id_()
  , new_sticker_set_id_()
{}

chatEventStickerSetChanged::chatEventStickerSetChanged(int64 old_sticker_set_id_, int64 new_sticker_set_id_)
  : old_sticker_set_id_(old_sticker_set_id_)
  , new_sticker_set_id_(new_sticker_set_id_)
{}

const std::int32_t chatEventStickerSetChanged::ID;

void chatEventStickerSetChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventStickerSetChanged");
    s.store_field("old_sticker_set_id", old_sticker_set_id_);
    s.store_field("new_sticker_set_id", new_sticker_set_id_);
    s.store_class_end();
  }
}

chatEventCustomEmojiStickerSetChanged::chatEventCustomEmojiStickerSetChanged()
  : old_sticker_set_id_()
  , new_sticker_set_id_()
{}

chatEventCustomEmojiStickerSetChanged::chatEventCustomEmojiStickerSetChanged(int64 old_sticker_set_id_, int64 new_sticker_set_id_)
  : old_sticker_set_id_(old_sticker_set_id_)
  , new_sticker_set_id_(new_sticker_set_id_)
{}

const std::int32_t chatEventCustomEmojiStickerSetChanged::ID;

void chatEventCustomEmojiStickerSetChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventCustomEmojiStickerSetChanged");
    s.store_field("old_sticker_set_id", old_sticker_set_id_);
    s.store_field("new_sticker_set_id", new_sticker_set_id_);
    s.store_class_end();
  }
}

chatEventTitleChanged::chatEventTitleChanged()
  : old_title_()
  , new_title_()
{}

chatEventTitleChanged::chatEventTitleChanged(string const &old_title_, string const &new_title_)
  : old_title_(old_title_)
  , new_title_(new_title_)
{}

const std::int32_t chatEventTitleChanged::ID;

void chatEventTitleChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventTitleChanged");
    s.store_field("old_title", old_title_);
    s.store_field("new_title", new_title_);
    s.store_class_end();
  }
}

chatEventUsernameChanged::chatEventUsernameChanged()
  : old_username_()
  , new_username_()
{}

chatEventUsernameChanged::chatEventUsernameChanged(string const &old_username_, string const &new_username_)
  : old_username_(old_username_)
  , new_username_(new_username_)
{}

const std::int32_t chatEventUsernameChanged::ID;

void chatEventUsernameChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventUsernameChanged");
    s.store_field("old_username", old_username_);
    s.store_field("new_username", new_username_);
    s.store_class_end();
  }
}

chatEventActiveUsernamesChanged::chatEventActiveUsernamesChanged()
  : old_usernames_()
  , new_usernames_()
{}

chatEventActiveUsernamesChanged::chatEventActiveUsernamesChanged(array<string> &&old_usernames_, array<string> &&new_usernames_)
  : old_usernames_(std::move(old_usernames_))
  , new_usernames_(std::move(new_usernames_))
{}

const std::int32_t chatEventActiveUsernamesChanged::ID;

void chatEventActiveUsernamesChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventActiveUsernamesChanged");
    { s.store_vector_begin("old_usernames", old_usernames_.size()); for (const auto &_value : old_usernames_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("new_usernames", new_usernames_.size()); for (const auto &_value : new_usernames_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatEventAccentColorChanged::chatEventAccentColorChanged()
  : old_accent_color_id_()
  , old_background_custom_emoji_id_()
  , new_accent_color_id_()
  , new_background_custom_emoji_id_()
{}

chatEventAccentColorChanged::chatEventAccentColorChanged(int32 old_accent_color_id_, int64 old_background_custom_emoji_id_, int32 new_accent_color_id_, int64 new_background_custom_emoji_id_)
  : old_accent_color_id_(old_accent_color_id_)
  , old_background_custom_emoji_id_(old_background_custom_emoji_id_)
  , new_accent_color_id_(new_accent_color_id_)
  , new_background_custom_emoji_id_(new_background_custom_emoji_id_)
{}

const std::int32_t chatEventAccentColorChanged::ID;

void chatEventAccentColorChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventAccentColorChanged");
    s.store_field("old_accent_color_id", old_accent_color_id_);
    s.store_field("old_background_custom_emoji_id", old_background_custom_emoji_id_);
    s.store_field("new_accent_color_id", new_accent_color_id_);
    s.store_field("new_background_custom_emoji_id", new_background_custom_emoji_id_);
    s.store_class_end();
  }
}

chatEventProfileAccentColorChanged::chatEventProfileAccentColorChanged()
  : old_profile_accent_color_id_()
  , old_profile_background_custom_emoji_id_()
  , new_profile_accent_color_id_()
  , new_profile_background_custom_emoji_id_()
{}

chatEventProfileAccentColorChanged::chatEventProfileAccentColorChanged(int32 old_profile_accent_color_id_, int64 old_profile_background_custom_emoji_id_, int32 new_profile_accent_color_id_, int64 new_profile_background_custom_emoji_id_)
  : old_profile_accent_color_id_(old_profile_accent_color_id_)
  , old_profile_background_custom_emoji_id_(old_profile_background_custom_emoji_id_)
  , new_profile_accent_color_id_(new_profile_accent_color_id_)
  , new_profile_background_custom_emoji_id_(new_profile_background_custom_emoji_id_)
{}

const std::int32_t chatEventProfileAccentColorChanged::ID;

void chatEventProfileAccentColorChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventProfileAccentColorChanged");
    s.store_field("old_profile_accent_color_id", old_profile_accent_color_id_);
    s.store_field("old_profile_background_custom_emoji_id", old_profile_background_custom_emoji_id_);
    s.store_field("new_profile_accent_color_id", new_profile_accent_color_id_);
    s.store_field("new_profile_background_custom_emoji_id", new_profile_background_custom_emoji_id_);
    s.store_class_end();
  }
}

chatEventHasProtectedContentToggled::chatEventHasProtectedContentToggled()
  : has_protected_content_()
{}

chatEventHasProtectedContentToggled::chatEventHasProtectedContentToggled(bool has_protected_content_)
  : has_protected_content_(has_protected_content_)
{}

const std::int32_t chatEventHasProtectedContentToggled::ID;

void chatEventHasProtectedContentToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventHasProtectedContentToggled");
    s.store_field("has_protected_content", has_protected_content_);
    s.store_class_end();
  }
}

chatEventInvitesToggled::chatEventInvitesToggled()
  : can_invite_users_()
{}

chatEventInvitesToggled::chatEventInvitesToggled(bool can_invite_users_)
  : can_invite_users_(can_invite_users_)
{}

const std::int32_t chatEventInvitesToggled::ID;

void chatEventInvitesToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventInvitesToggled");
    s.store_field("can_invite_users", can_invite_users_);
    s.store_class_end();
  }
}

chatEventIsAllHistoryAvailableToggled::chatEventIsAllHistoryAvailableToggled()
  : is_all_history_available_()
{}

chatEventIsAllHistoryAvailableToggled::chatEventIsAllHistoryAvailableToggled(bool is_all_history_available_)
  : is_all_history_available_(is_all_history_available_)
{}

const std::int32_t chatEventIsAllHistoryAvailableToggled::ID;

void chatEventIsAllHistoryAvailableToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventIsAllHistoryAvailableToggled");
    s.store_field("is_all_history_available", is_all_history_available_);
    s.store_class_end();
  }
}

chatEventHasAggressiveAntiSpamEnabledToggled::chatEventHasAggressiveAntiSpamEnabledToggled()
  : has_aggressive_anti_spam_enabled_()
{}

chatEventHasAggressiveAntiSpamEnabledToggled::chatEventHasAggressiveAntiSpamEnabledToggled(bool has_aggressive_anti_spam_enabled_)
  : has_aggressive_anti_spam_enabled_(has_aggressive_anti_spam_enabled_)
{}

const std::int32_t chatEventHasAggressiveAntiSpamEnabledToggled::ID;

void chatEventHasAggressiveAntiSpamEnabledToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventHasAggressiveAntiSpamEnabledToggled");
    s.store_field("has_aggressive_anti_spam_enabled", has_aggressive_anti_spam_enabled_);
    s.store_class_end();
  }
}

chatEventSignMessagesToggled::chatEventSignMessagesToggled()
  : sign_messages_()
{}

chatEventSignMessagesToggled::chatEventSignMessagesToggled(bool sign_messages_)
  : sign_messages_(sign_messages_)
{}

const std::int32_t chatEventSignMessagesToggled::ID;

void chatEventSignMessagesToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventSignMessagesToggled");
    s.store_field("sign_messages", sign_messages_);
    s.store_class_end();
  }
}

chatEventShowMessageSenderToggled::chatEventShowMessageSenderToggled()
  : show_message_sender_()
{}

chatEventShowMessageSenderToggled::chatEventShowMessageSenderToggled(bool show_message_sender_)
  : show_message_sender_(show_message_sender_)
{}

const std::int32_t chatEventShowMessageSenderToggled::ID;

void chatEventShowMessageSenderToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventShowMessageSenderToggled");
    s.store_field("show_message_sender", show_message_sender_);
    s.store_class_end();
  }
}

chatEventAutomaticTranslationToggled::chatEventAutomaticTranslationToggled()
  : has_automatic_translation_()
{}

chatEventAutomaticTranslationToggled::chatEventAutomaticTranslationToggled(bool has_automatic_translation_)
  : has_automatic_translation_(has_automatic_translation_)
{}

const std::int32_t chatEventAutomaticTranslationToggled::ID;

void chatEventAutomaticTranslationToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventAutomaticTranslationToggled");
    s.store_field("has_automatic_translation", has_automatic_translation_);
    s.store_class_end();
  }
}

chatEventInviteLinkEdited::chatEventInviteLinkEdited()
  : old_invite_link_()
  , new_invite_link_()
{}

chatEventInviteLinkEdited::chatEventInviteLinkEdited(object_ptr<chatInviteLink> &&old_invite_link_, object_ptr<chatInviteLink> &&new_invite_link_)
  : old_invite_link_(std::move(old_invite_link_))
  , new_invite_link_(std::move(new_invite_link_))
{}

const std::int32_t chatEventInviteLinkEdited::ID;

void chatEventInviteLinkEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventInviteLinkEdited");
    s.store_object_field("old_invite_link", static_cast<const BaseObject *>(old_invite_link_.get()));
    s.store_object_field("new_invite_link", static_cast<const BaseObject *>(new_invite_link_.get()));
    s.store_class_end();
  }
}

chatEventInviteLinkRevoked::chatEventInviteLinkRevoked()
  : invite_link_()
{}

chatEventInviteLinkRevoked::chatEventInviteLinkRevoked(object_ptr<chatInviteLink> &&invite_link_)
  : invite_link_(std::move(invite_link_))
{}

const std::int32_t chatEventInviteLinkRevoked::ID;

void chatEventInviteLinkRevoked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventInviteLinkRevoked");
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_class_end();
  }
}

chatEventInviteLinkDeleted::chatEventInviteLinkDeleted()
  : invite_link_()
{}

chatEventInviteLinkDeleted::chatEventInviteLinkDeleted(object_ptr<chatInviteLink> &&invite_link_)
  : invite_link_(std::move(invite_link_))
{}

const std::int32_t chatEventInviteLinkDeleted::ID;

void chatEventInviteLinkDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventInviteLinkDeleted");
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_class_end();
  }
}

chatEventVideoChatCreated::chatEventVideoChatCreated()
  : group_call_id_()
{}

chatEventVideoChatCreated::chatEventVideoChatCreated(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t chatEventVideoChatCreated::ID;

void chatEventVideoChatCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatCreated");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

chatEventVideoChatEnded::chatEventVideoChatEnded()
  : group_call_id_()
{}

chatEventVideoChatEnded::chatEventVideoChatEnded(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t chatEventVideoChatEnded::ID;

void chatEventVideoChatEnded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatEnded");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

chatEventVideoChatMuteNewParticipantsToggled::chatEventVideoChatMuteNewParticipantsToggled()
  : mute_new_participants_()
{}

chatEventVideoChatMuteNewParticipantsToggled::chatEventVideoChatMuteNewParticipantsToggled(bool mute_new_participants_)
  : mute_new_participants_(mute_new_participants_)
{}

const std::int32_t chatEventVideoChatMuteNewParticipantsToggled::ID;

void chatEventVideoChatMuteNewParticipantsToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatMuteNewParticipantsToggled");
    s.store_field("mute_new_participants", mute_new_participants_);
    s.store_class_end();
  }
}

chatEventVideoChatParticipantIsMutedToggled::chatEventVideoChatParticipantIsMutedToggled()
  : participant_id_()
  , is_muted_()
{}

chatEventVideoChatParticipantIsMutedToggled::chatEventVideoChatParticipantIsMutedToggled(object_ptr<MessageSender> &&participant_id_, bool is_muted_)
  : participant_id_(std::move(participant_id_))
  , is_muted_(is_muted_)
{}

const std::int32_t chatEventVideoChatParticipantIsMutedToggled::ID;

void chatEventVideoChatParticipantIsMutedToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatParticipantIsMutedToggled");
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("is_muted", is_muted_);
    s.store_class_end();
  }
}

chatEventVideoChatParticipantVolumeLevelChanged::chatEventVideoChatParticipantVolumeLevelChanged()
  : participant_id_()
  , volume_level_()
{}

chatEventVideoChatParticipantVolumeLevelChanged::chatEventVideoChatParticipantVolumeLevelChanged(object_ptr<MessageSender> &&participant_id_, int32 volume_level_)
  : participant_id_(std::move(participant_id_))
  , volume_level_(volume_level_)
{}

const std::int32_t chatEventVideoChatParticipantVolumeLevelChanged::ID;

void chatEventVideoChatParticipantVolumeLevelChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventVideoChatParticipantVolumeLevelChanged");
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("volume_level", volume_level_);
    s.store_class_end();
  }
}

chatEventIsForumToggled::chatEventIsForumToggled()
  : is_forum_()
{}

chatEventIsForumToggled::chatEventIsForumToggled(bool is_forum_)
  : is_forum_(is_forum_)
{}

const std::int32_t chatEventIsForumToggled::ID;

void chatEventIsForumToggled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventIsForumToggled");
    s.store_field("is_forum", is_forum_);
    s.store_class_end();
  }
}

chatEventForumTopicCreated::chatEventForumTopicCreated()
  : topic_info_()
{}

chatEventForumTopicCreated::chatEventForumTopicCreated(object_ptr<forumTopicInfo> &&topic_info_)
  : topic_info_(std::move(topic_info_))
{}

const std::int32_t chatEventForumTopicCreated::ID;

void chatEventForumTopicCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventForumTopicCreated");
    s.store_object_field("topic_info", static_cast<const BaseObject *>(topic_info_.get()));
    s.store_class_end();
  }
}

chatEventForumTopicEdited::chatEventForumTopicEdited()
  : old_topic_info_()
  , new_topic_info_()
{}

chatEventForumTopicEdited::chatEventForumTopicEdited(object_ptr<forumTopicInfo> &&old_topic_info_, object_ptr<forumTopicInfo> &&new_topic_info_)
  : old_topic_info_(std::move(old_topic_info_))
  , new_topic_info_(std::move(new_topic_info_))
{}

const std::int32_t chatEventForumTopicEdited::ID;

void chatEventForumTopicEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventForumTopicEdited");
    s.store_object_field("old_topic_info", static_cast<const BaseObject *>(old_topic_info_.get()));
    s.store_object_field("new_topic_info", static_cast<const BaseObject *>(new_topic_info_.get()));
    s.store_class_end();
  }
}

chatEventForumTopicToggleIsClosed::chatEventForumTopicToggleIsClosed()
  : topic_info_()
{}

chatEventForumTopicToggleIsClosed::chatEventForumTopicToggleIsClosed(object_ptr<forumTopicInfo> &&topic_info_)
  : topic_info_(std::move(topic_info_))
{}

const std::int32_t chatEventForumTopicToggleIsClosed::ID;

void chatEventForumTopicToggleIsClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventForumTopicToggleIsClosed");
    s.store_object_field("topic_info", static_cast<const BaseObject *>(topic_info_.get()));
    s.store_class_end();
  }
}

chatEventForumTopicToggleIsHidden::chatEventForumTopicToggleIsHidden()
  : topic_info_()
{}

chatEventForumTopicToggleIsHidden::chatEventForumTopicToggleIsHidden(object_ptr<forumTopicInfo> &&topic_info_)
  : topic_info_(std::move(topic_info_))
{}

const std::int32_t chatEventForumTopicToggleIsHidden::ID;

void chatEventForumTopicToggleIsHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventForumTopicToggleIsHidden");
    s.store_object_field("topic_info", static_cast<const BaseObject *>(topic_info_.get()));
    s.store_class_end();
  }
}

chatEventForumTopicDeleted::chatEventForumTopicDeleted()
  : topic_info_()
{}

chatEventForumTopicDeleted::chatEventForumTopicDeleted(object_ptr<forumTopicInfo> &&topic_info_)
  : topic_info_(std::move(topic_info_))
{}

const std::int32_t chatEventForumTopicDeleted::ID;

void chatEventForumTopicDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventForumTopicDeleted");
    s.store_object_field("topic_info", static_cast<const BaseObject *>(topic_info_.get()));
    s.store_class_end();
  }
}

chatEventForumTopicPinned::chatEventForumTopicPinned()
  : old_topic_info_()
  , new_topic_info_()
{}

chatEventForumTopicPinned::chatEventForumTopicPinned(object_ptr<forumTopicInfo> &&old_topic_info_, object_ptr<forumTopicInfo> &&new_topic_info_)
  : old_topic_info_(std::move(old_topic_info_))
  , new_topic_info_(std::move(new_topic_info_))
{}

const std::int32_t chatEventForumTopicPinned::ID;

void chatEventForumTopicPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventForumTopicPinned");
    s.store_object_field("old_topic_info", static_cast<const BaseObject *>(old_topic_info_.get()));
    s.store_object_field("new_topic_info", static_cast<const BaseObject *>(new_topic_info_.get()));
    s.store_class_end();
  }
}

chatInviteLinkMember::chatInviteLinkMember()
  : user_id_()
  , joined_chat_date_()
  , via_chat_folder_invite_link_()
  , approver_user_id_()
{}

chatInviteLinkMember::chatInviteLinkMember(int53 user_id_, int32 joined_chat_date_, bool via_chat_folder_invite_link_, int53 approver_user_id_)
  : user_id_(user_id_)
  , joined_chat_date_(joined_chat_date_)
  , via_chat_folder_invite_link_(via_chat_folder_invite_link_)
  , approver_user_id_(approver_user_id_)
{}

const std::int32_t chatInviteLinkMember::ID;

void chatInviteLinkMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkMember");
    s.store_field("user_id", user_id_);
    s.store_field("joined_chat_date", joined_chat_date_);
    s.store_field("via_chat_folder_invite_link", via_chat_folder_invite_link_);
    s.store_field("approver_user_id", approver_user_id_);
    s.store_class_end();
  }
}

chatMessageSenders::chatMessageSenders()
  : senders_()
{}

chatMessageSenders::chatMessageSenders(array<object_ptr<chatMessageSender>> &&senders_)
  : senders_(std::move(senders_))
{}

const std::int32_t chatMessageSenders::ID;

void chatMessageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMessageSenders");
    { s.store_vector_begin("senders", senders_.size()); for (const auto &_value : senders_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatRevenueTransactionTypeUnsupported::chatRevenueTransactionTypeUnsupported() {
}

const std::int32_t chatRevenueTransactionTypeUnsupported::ID;

void chatRevenueTransactionTypeUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransactionTypeUnsupported");
    s.store_class_end();
  }
}

chatRevenueTransactionTypeSponsoredMessageEarnings::chatRevenueTransactionTypeSponsoredMessageEarnings()
  : start_date_()
  , end_date_()
{}

chatRevenueTransactionTypeSponsoredMessageEarnings::chatRevenueTransactionTypeSponsoredMessageEarnings(int32 start_date_, int32 end_date_)
  : start_date_(start_date_)
  , end_date_(end_date_)
{}

const std::int32_t chatRevenueTransactionTypeSponsoredMessageEarnings::ID;

void chatRevenueTransactionTypeSponsoredMessageEarnings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransactionTypeSponsoredMessageEarnings");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_class_end();
  }
}

chatRevenueTransactionTypeSuggestedPostEarnings::chatRevenueTransactionTypeSuggestedPostEarnings()
  : user_id_()
{}

chatRevenueTransactionTypeSuggestedPostEarnings::chatRevenueTransactionTypeSuggestedPostEarnings(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t chatRevenueTransactionTypeSuggestedPostEarnings::ID;

void chatRevenueTransactionTypeSuggestedPostEarnings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransactionTypeSuggestedPostEarnings");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

chatRevenueTransactionTypeFragmentWithdrawal::chatRevenueTransactionTypeFragmentWithdrawal()
  : withdrawal_date_()
  , state_()
{}

chatRevenueTransactionTypeFragmentWithdrawal::chatRevenueTransactionTypeFragmentWithdrawal(int32 withdrawal_date_, object_ptr<RevenueWithdrawalState> &&state_)
  : withdrawal_date_(withdrawal_date_)
  , state_(std::move(state_))
{}

const std::int32_t chatRevenueTransactionTypeFragmentWithdrawal::ID;

void chatRevenueTransactionTypeFragmentWithdrawal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransactionTypeFragmentWithdrawal");
    s.store_field("withdrawal_date", withdrawal_date_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

chatRevenueTransactionTypeFragmentRefund::chatRevenueTransactionTypeFragmentRefund()
  : refund_date_()
{}

chatRevenueTransactionTypeFragmentRefund::chatRevenueTransactionTypeFragmentRefund(int32 refund_date_)
  : refund_date_(refund_date_)
{}

const std::int32_t chatRevenueTransactionTypeFragmentRefund::ID;

void chatRevenueTransactionTypeFragmentRefund::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransactionTypeFragmentRefund");
    s.store_field("refund_date", refund_date_);
    s.store_class_end();
  }
}

chatStatisticsInviterInfo::chatStatisticsInviterInfo()
  : user_id_()
  , added_member_count_()
{}

chatStatisticsInviterInfo::chatStatisticsInviterInfo(int53 user_id_, int32 added_member_count_)
  : user_id_(user_id_)
  , added_member_count_(added_member_count_)
{}

const std::int32_t chatStatisticsInviterInfo::ID;

void chatStatisticsInviterInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsInviterInfo");
    s.store_field("user_id", user_id_);
    s.store_field("added_member_count", added_member_count_);
    s.store_class_end();
  }
}

collectibleItemInfo::collectibleItemInfo()
  : purchase_date_()
  , currency_()
  , amount_()
  , cryptocurrency_()
  , cryptocurrency_amount_()
  , url_()
{}

collectibleItemInfo::collectibleItemInfo(int32 purchase_date_, string const &currency_, int53 amount_, string const &cryptocurrency_, int64 cryptocurrency_amount_, string const &url_)
  : purchase_date_(purchase_date_)
  , currency_(currency_)
  , amount_(amount_)
  , cryptocurrency_(cryptocurrency_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , url_(url_)
{}

const std::int32_t collectibleItemInfo::ID;

void collectibleItemInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "collectibleItemInfo");
    s.store_field("purchase_date", purchase_date_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

connectedAffiliateProgram::connectedAffiliateProgram()
  : url_()
  , bot_user_id_()
  , parameters_()
  , connection_date_()
  , is_disconnected_()
  , user_count_()
  , revenue_star_count_()
{}

connectedAffiliateProgram::connectedAffiliateProgram(string const &url_, int53 bot_user_id_, object_ptr<affiliateProgramParameters> &&parameters_, int32 connection_date_, bool is_disconnected_, int64 user_count_, int53 revenue_star_count_)
  : url_(url_)
  , bot_user_id_(bot_user_id_)
  , parameters_(std::move(parameters_))
  , connection_date_(connection_date_)
  , is_disconnected_(is_disconnected_)
  , user_count_(user_count_)
  , revenue_star_count_(revenue_star_count_)
{}

const std::int32_t connectedAffiliateProgram::ID;

void connectedAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedAffiliateProgram");
    s.store_field("url", url_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("connection_date", connection_date_);
    s.store_field("is_disconnected", is_disconnected_);
    s.store_field("user_count", user_count_);
    s.store_field("revenue_star_count", revenue_star_count_);
    s.store_class_end();
  }
}

count::count()
  : count_()
{}

count::count(int32 count_)
  : count_(count_)
{}

const std::int32_t count::ID;

void count::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "count");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

databaseStatistics::databaseStatistics()
  : statistics_()
{}

databaseStatistics::databaseStatistics(string const &statistics_)
  : statistics_(statistics_)
{}

const std::int32_t databaseStatistics::ID;

void databaseStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "databaseStatistics");
    s.store_field("statistics", statistics_);
    s.store_class_end();
  }
}

dateTimePartPrecisionNone::dateTimePartPrecisionNone() {
}

const std::int32_t dateTimePartPrecisionNone::ID;

void dateTimePartPrecisionNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateTimePartPrecisionNone");
    s.store_class_end();
  }
}

dateTimePartPrecisionShort::dateTimePartPrecisionShort() {
}

const std::int32_t dateTimePartPrecisionShort::ID;

void dateTimePartPrecisionShort::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateTimePartPrecisionShort");
    s.store_class_end();
  }
}

dateTimePartPrecisionLong::dateTimePartPrecisionLong() {
}

const std::int32_t dateTimePartPrecisionLong::ID;

void dateTimePartPrecisionLong::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateTimePartPrecisionLong");
    s.store_class_end();
  }
}

downloadedFileCounts::downloadedFileCounts()
  : active_count_()
  , paused_count_()
  , completed_count_()
{}

downloadedFileCounts::downloadedFileCounts(int32 active_count_, int32 paused_count_, int32 completed_count_)
  : active_count_(active_count_)
  , paused_count_(paused_count_)
  , completed_count_(completed_count_)
{}

const std::int32_t downloadedFileCounts::ID;

void downloadedFileCounts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "downloadedFileCounts");
    s.store_field("active_count", active_count_);
    s.store_field("paused_count", paused_count_);
    s.store_field("completed_count", completed_count_);
    s.store_class_end();
  }
}

forumTopicInfo::forumTopicInfo()
  : chat_id_()
  , forum_topic_id_()
  , name_()
  , icon_()
  , creation_date_()
  , creator_id_()
  , is_general_()
  , is_outgoing_()
  , is_closed_()
  , is_hidden_()
  , is_name_implicit_()
{}

forumTopicInfo::forumTopicInfo(int53 chat_id_, int32 forum_topic_id_, string const &name_, object_ptr<forumTopicIcon> &&icon_, int32 creation_date_, object_ptr<MessageSender> &&creator_id_, bool is_general_, bool is_outgoing_, bool is_closed_, bool is_hidden_, bool is_name_implicit_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , name_(name_)
  , icon_(std::move(icon_))
  , creation_date_(creation_date_)
  , creator_id_(std::move(creator_id_))
  , is_general_(is_general_)
  , is_outgoing_(is_outgoing_)
  , is_closed_(is_closed_)
  , is_hidden_(is_hidden_)
  , is_name_implicit_(is_name_implicit_)
{}

const std::int32_t forumTopicInfo::ID;

void forumTopicInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forumTopicInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("name", name_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_field("creation_date", creation_date_);
    s.store_object_field("creator_id", static_cast<const BaseObject *>(creator_id_.get()));
    s.store_field("is_general", is_general_);
    s.store_field("is_outgoing", is_outgoing_);
    s.store_field("is_closed", is_closed_);
    s.store_field("is_hidden", is_hidden_);
    s.store_field("is_name_implicit", is_name_implicit_);
    s.store_class_end();
  }
}

foundPublicPosts::foundPublicPosts()
  : messages_()
  , next_offset_()
  , search_limits_()
  , are_limits_exceeded_()
{}

foundPublicPosts::foundPublicPosts(array<object_ptr<message>> &&messages_, string const &next_offset_, object_ptr<publicPostSearchLimits> &&search_limits_, bool are_limits_exceeded_)
  : messages_(std::move(messages_))
  , next_offset_(next_offset_)
  , search_limits_(std::move(search_limits_))
  , are_limits_exceeded_(are_limits_exceeded_)
{}

const std::int32_t foundPublicPosts::ID;

void foundPublicPosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundPublicPosts");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_object_field("search_limits", static_cast<const BaseObject *>(search_limits_.get()));
    s.store_field("are_limits_exceeded", are_limits_exceeded_);
    s.store_class_end();
  }
}

giftCollections::giftCollections()
  : collections_()
{}

giftCollections::giftCollections(array<object_ptr<giftCollection>> &&collections_)
  : collections_(std::move(collections_))
{}

const std::int32_t giftCollections::ID;

void giftCollections::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftCollections");
    { s.store_vector_begin("collections", collections_.size()); for (const auto &_value : collections_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

giftUpgradeVariants::giftUpgradeVariants()
  : models_()
  , symbols_()
  , backdrops_()
{}

giftUpgradeVariants::giftUpgradeVariants(array<object_ptr<upgradedGiftModel>> &&models_, array<object_ptr<upgradedGiftSymbol>> &&symbols_, array<object_ptr<upgradedGiftBackdrop>> &&backdrops_)
  : models_(std::move(models_))
  , symbols_(std::move(symbols_))
  , backdrops_(std::move(backdrops_))
{}

const std::int32_t giftUpgradeVariants::ID;

void giftUpgradeVariants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftUpgradeVariants");
    { s.store_vector_begin("models", models_.size()); for (const auto &_value : models_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("symbols", symbols_.size()); for (const auto &_value : symbols_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("backdrops", backdrops_.size()); for (const auto &_value : backdrops_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

groupCallId::groupCallId()
  : id_()
{}

groupCallId::groupCallId(int32 id_)
  : id_(id_)
{}

const std::int32_t groupCallId::ID;

void groupCallId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

hashtags::hashtags()
  : hashtags_()
{}

hashtags::hashtags(array<string> &&hashtags_)
  : hashtags_(std::move(hashtags_))
{}

const std::int32_t hashtags::ID;

void hashtags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "hashtags");
    { s.store_vector_begin("hashtags", hashtags_.size()); for (const auto &_value : hashtags_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPassportElementError::inputPassportElementError()
  : type_()
  , message_()
  , source_()
{}

inputPassportElementError::inputPassportElementError(object_ptr<PassportElementType> &&type_, string const &message_, object_ptr<InputPassportElementErrorSource> &&source_)
  : type_(std::move(type_))
  , message_(message_)
  , source_(std::move(source_))
{}

const std::int32_t inputPassportElementError::ID;

void inputPassportElementError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementError");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("message", message_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

invoice::invoice()
  : currency_()
  , price_parts_()
  , subscription_period_()
  , max_tip_amount_()
  , suggested_tip_amounts_()
  , recurring_payment_terms_of_service_url_()
  , terms_of_service_url_()
  , is_test_()
  , need_name_()
  , need_phone_number_()
  , need_email_address_()
  , need_shipping_address_()
  , send_phone_number_to_provider_()
  , send_email_address_to_provider_()
  , is_flexible_()
{}

invoice::invoice(string const &currency_, array<object_ptr<labeledPricePart>> &&price_parts_, int32 subscription_period_, int53 max_tip_amount_, array<int53> &&suggested_tip_amounts_, string const &recurring_payment_terms_of_service_url_, string const &terms_of_service_url_, bool is_test_, bool need_name_, bool need_phone_number_, bool need_email_address_, bool need_shipping_address_, bool send_phone_number_to_provider_, bool send_email_address_to_provider_, bool is_flexible_)
  : currency_(currency_)
  , price_parts_(std::move(price_parts_))
  , subscription_period_(subscription_period_)
  , max_tip_amount_(max_tip_amount_)
  , suggested_tip_amounts_(std::move(suggested_tip_amounts_))
  , recurring_payment_terms_of_service_url_(recurring_payment_terms_of_service_url_)
  , terms_of_service_url_(terms_of_service_url_)
  , is_test_(is_test_)
  , need_name_(need_name_)
  , need_phone_number_(need_phone_number_)
  , need_email_address_(need_email_address_)
  , need_shipping_address_(need_shipping_address_)
  , send_phone_number_to_provider_(send_phone_number_to_provider_)
  , send_email_address_to_provider_(send_email_address_to_provider_)
  , is_flexible_(is_flexible_)
{}

const std::int32_t invoice::ID;

void invoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invoice");
    s.store_field("currency", currency_);
    { s.store_vector_begin("price_parts", price_parts_.size()); for (const auto &_value : price_parts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("subscription_period", subscription_period_);
    s.store_field("max_tip_amount", max_tip_amount_);
    { s.store_vector_begin("suggested_tip_amounts", suggested_tip_amounts_.size()); for (const auto &_value : suggested_tip_amounts_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("recurring_payment_terms_of_service_url", recurring_payment_terms_of_service_url_);
    s.store_field("terms_of_service_url", terms_of_service_url_);
    s.store_field("is_test", is_test_);
    s.store_field("need_name", need_name_);
    s.store_field("need_phone_number", need_phone_number_);
    s.store_field("need_email_address", need_email_address_);
    s.store_field("need_shipping_address", need_shipping_address_);
    s.store_field("send_phone_number_to_provider", send_phone_number_to_provider_);
    s.store_field("send_email_address_to_provider", send_email_address_to_provider_);
    s.store_field("is_flexible", is_flexible_);
    s.store_class_end();
  }
}

jsonValueNull::jsonValueNull() {
}

const std::int32_t jsonValueNull::ID;

void jsonValueNull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueNull");
    s.store_class_end();
  }
}

jsonValueBoolean::jsonValueBoolean()
  : value_()
{}

jsonValueBoolean::jsonValueBoolean(bool value_)
  : value_(value_)
{}

const std::int32_t jsonValueBoolean::ID;

void jsonValueBoolean::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueBoolean");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonValueNumber::jsonValueNumber()
  : value_()
{}

jsonValueNumber::jsonValueNumber(double value_)
  : value_(value_)
{}

const std::int32_t jsonValueNumber::ID;

void jsonValueNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueNumber");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonValueString::jsonValueString()
  : value_()
{}

jsonValueString::jsonValueString(string const &value_)
  : value_(value_)
{}

const std::int32_t jsonValueString::ID;

void jsonValueString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueString");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonValueArray::jsonValueArray()
  : values_()
{}

jsonValueArray::jsonValueArray(array<object_ptr<JsonValue>> &&values_)
  : values_(std::move(values_))
{}

const std::int32_t jsonValueArray::ID;

void jsonValueArray::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueArray");
    { s.store_vector_begin("values", values_.size()); for (const auto &_value : values_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

jsonValueObject::jsonValueObject()
  : members_()
{}

jsonValueObject::jsonValueObject(array<object_ptr<jsonObjectMember>> &&members_)
  : members_(std::move(members_))
{}

const std::int32_t jsonValueObject::ID;

void jsonValueObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonValueObject");
    { s.store_vector_begin("members", members_.size()); for (const auto &_value : members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

keyboardButtonTypeText::keyboardButtonTypeText() {
}

const std::int32_t keyboardButtonTypeText::ID;

void keyboardButtonTypeText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeText");
    s.store_class_end();
  }
}

keyboardButtonTypeRequestPhoneNumber::keyboardButtonTypeRequestPhoneNumber() {
}

const std::int32_t keyboardButtonTypeRequestPhoneNumber::ID;

void keyboardButtonTypeRequestPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestPhoneNumber");
    s.store_class_end();
  }
}

keyboardButtonTypeRequestLocation::keyboardButtonTypeRequestLocation() {
}

const std::int32_t keyboardButtonTypeRequestLocation::ID;

void keyboardButtonTypeRequestLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestLocation");
    s.store_class_end();
  }
}

keyboardButtonTypeRequestPoll::keyboardButtonTypeRequestPoll()
  : force_regular_()
  , force_quiz_()
{}

keyboardButtonTypeRequestPoll::keyboardButtonTypeRequestPoll(bool force_regular_, bool force_quiz_)
  : force_regular_(force_regular_)
  , force_quiz_(force_quiz_)
{}

const std::int32_t keyboardButtonTypeRequestPoll::ID;

void keyboardButtonTypeRequestPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestPoll");
    s.store_field("force_regular", force_regular_);
    s.store_field("force_quiz", force_quiz_);
    s.store_class_end();
  }
}

keyboardButtonTypeRequestUsers::keyboardButtonTypeRequestUsers()
  : id_()
  , restrict_user_is_bot_()
  , user_is_bot_()
  , restrict_user_is_premium_()
  , user_is_premium_()
  , max_quantity_()
  , request_name_()
  , request_username_()
  , request_photo_()
{}

keyboardButtonTypeRequestUsers::keyboardButtonTypeRequestUsers(int32 id_, bool restrict_user_is_bot_, bool user_is_bot_, bool restrict_user_is_premium_, bool user_is_premium_, int32 max_quantity_, bool request_name_, bool request_username_, bool request_photo_)
  : id_(id_)
  , restrict_user_is_bot_(restrict_user_is_bot_)
  , user_is_bot_(user_is_bot_)
  , restrict_user_is_premium_(restrict_user_is_premium_)
  , user_is_premium_(user_is_premium_)
  , max_quantity_(max_quantity_)
  , request_name_(request_name_)
  , request_username_(request_username_)
  , request_photo_(request_photo_)
{}

const std::int32_t keyboardButtonTypeRequestUsers::ID;

void keyboardButtonTypeRequestUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestUsers");
    s.store_field("id", id_);
    s.store_field("restrict_user_is_bot", restrict_user_is_bot_);
    s.store_field("user_is_bot", user_is_bot_);
    s.store_field("restrict_user_is_premium", restrict_user_is_premium_);
    s.store_field("user_is_premium", user_is_premium_);
    s.store_field("max_quantity", max_quantity_);
    s.store_field("request_name", request_name_);
    s.store_field("request_username", request_username_);
    s.store_field("request_photo", request_photo_);
    s.store_class_end();
  }
}

keyboardButtonTypeRequestChat::keyboardButtonTypeRequestChat()
  : id_()
  , chat_is_channel_()
  , restrict_chat_is_forum_()
  , chat_is_forum_()
  , restrict_chat_has_username_()
  , chat_has_username_()
  , chat_is_created_()
  , user_administrator_rights_()
  , bot_administrator_rights_()
  , bot_is_member_()
  , request_title_()
  , request_username_()
  , request_photo_()
{}

keyboardButtonTypeRequestChat::keyboardButtonTypeRequestChat(int32 id_, bool chat_is_channel_, bool restrict_chat_is_forum_, bool chat_is_forum_, bool restrict_chat_has_username_, bool chat_has_username_, bool chat_is_created_, object_ptr<chatAdministratorRights> &&user_administrator_rights_, object_ptr<chatAdministratorRights> &&bot_administrator_rights_, bool bot_is_member_, bool request_title_, bool request_username_, bool request_photo_)
  : id_(id_)
  , chat_is_channel_(chat_is_channel_)
  , restrict_chat_is_forum_(restrict_chat_is_forum_)
  , chat_is_forum_(chat_is_forum_)
  , restrict_chat_has_username_(restrict_chat_has_username_)
  , chat_has_username_(chat_has_username_)
  , chat_is_created_(chat_is_created_)
  , user_administrator_rights_(std::move(user_administrator_rights_))
  , bot_administrator_rights_(std::move(bot_administrator_rights_))
  , bot_is_member_(bot_is_member_)
  , request_title_(request_title_)
  , request_username_(request_username_)
  , request_photo_(request_photo_)
{}

const std::int32_t keyboardButtonTypeRequestChat::ID;

void keyboardButtonTypeRequestChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestChat");
    s.store_field("id", id_);
    s.store_field("chat_is_channel", chat_is_channel_);
    s.store_field("restrict_chat_is_forum", restrict_chat_is_forum_);
    s.store_field("chat_is_forum", chat_is_forum_);
    s.store_field("restrict_chat_has_username", restrict_chat_has_username_);
    s.store_field("chat_has_username", chat_has_username_);
    s.store_field("chat_is_created", chat_is_created_);
    s.store_object_field("user_administrator_rights", static_cast<const BaseObject *>(user_administrator_rights_.get()));
    s.store_object_field("bot_administrator_rights", static_cast<const BaseObject *>(bot_administrator_rights_.get()));
    s.store_field("bot_is_member", bot_is_member_);
    s.store_field("request_title", request_title_);
    s.store_field("request_username", request_username_);
    s.store_field("request_photo", request_photo_);
    s.store_class_end();
  }
}

keyboardButtonTypeRequestManagedBot::keyboardButtonTypeRequestManagedBot()
  : id_()
  , suggested_name_()
  , suggested_username_()
{}

keyboardButtonTypeRequestManagedBot::keyboardButtonTypeRequestManagedBot(int32 id_, string const &suggested_name_, string const &suggested_username_)
  : id_(id_)
  , suggested_name_(suggested_name_)
  , suggested_username_(suggested_username_)
{}

const std::int32_t keyboardButtonTypeRequestManagedBot::ID;

void keyboardButtonTypeRequestManagedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeRequestManagedBot");
    s.store_field("id", id_);
    s.store_field("suggested_name", suggested_name_);
    s.store_field("suggested_username", suggested_username_);
    s.store_class_end();
  }
}

keyboardButtonTypeWebApp::keyboardButtonTypeWebApp()
  : url_()
{}

keyboardButtonTypeWebApp::keyboardButtonTypeWebApp(string const &url_)
  : url_(url_)
{}

const std::int32_t keyboardButtonTypeWebApp::ID;

void keyboardButtonTypeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonTypeWebApp");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

logTags::logTags()
  : tags_()
{}

logTags::logTags(array<string> &&tags_)
  : tags_(std::move(tags_))
{}

const std::int32_t logTags::ID;

void logTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "logTags");
    { s.store_vector_begin("tags", tags_.size()); for (const auto &_value : tags_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageEffect::messageEffect()
  : id_()
  , static_icon_()
  , emoji_()
  , is_premium_()
  , type_()
{}

messageEffect::messageEffect(int64 id_, object_ptr<sticker> &&static_icon_, string const &emoji_, bool is_premium_, object_ptr<MessageEffectType> &&type_)
  : id_(id_)
  , static_icon_(std::move(static_icon_))
  , emoji_(emoji_)
  , is_premium_(is_premium_)
  , type_(std::move(type_))
{}

const std::int32_t messageEffect::ID;

void messageEffect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEffect");
    s.store_field("id", id_);
    s.store_object_field("static_icon", static_cast<const BaseObject *>(static_icon_.get()));
    s.store_field("emoji", emoji_);
    s.store_field("is_premium", is_premium_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

messageOriginUser::messageOriginUser()
  : sender_user_id_()
{}

messageOriginUser::messageOriginUser(int53 sender_user_id_)
  : sender_user_id_(sender_user_id_)
{}

const std::int32_t messageOriginUser::ID;

void messageOriginUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageOriginUser");
    s.store_field("sender_user_id", sender_user_id_);
    s.store_class_end();
  }
}

messageOriginHiddenUser::messageOriginHiddenUser()
  : sender_name_()
{}

messageOriginHiddenUser::messageOriginHiddenUser(string const &sender_name_)
  : sender_name_(sender_name_)
{}

const std::int32_t messageOriginHiddenUser::ID;

void messageOriginHiddenUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageOriginHiddenUser");
    s.store_field("sender_name", sender_name_);
    s.store_class_end();
  }
}

messageOriginChat::messageOriginChat()
  : sender_chat_id_()
  , author_signature_()
{}

messageOriginChat::messageOriginChat(int53 sender_chat_id_, string const &author_signature_)
  : sender_chat_id_(sender_chat_id_)
  , author_signature_(author_signature_)
{}

const std::int32_t messageOriginChat::ID;

void messageOriginChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageOriginChat");
    s.store_field("sender_chat_id", sender_chat_id_);
    s.store_field("author_signature", author_signature_);
    s.store_class_end();
  }
}

messageOriginChannel::messageOriginChannel()
  : chat_id_()
  , message_id_()
  , author_signature_()
{}

messageOriginChannel::messageOriginChannel(int53 chat_id_, int53 message_id_, string const &author_signature_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , author_signature_(author_signature_)
{}

const std::int32_t messageOriginChannel::ID;

void messageOriginChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageOriginChannel");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("author_signature", author_signature_);
    s.store_class_end();
  }
}

messagePosition::messagePosition()
  : position_()
  , message_id_()
  , date_()
{}

messagePosition::messagePosition(int32 position_, int53 message_id_, int32 date_)
  : position_(position_)
  , message_id_(message_id_)
  , date_(date_)
{}

const std::int32_t messagePosition::ID;

void messagePosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePosition");
    s.store_field("position", position_);
    s.store_field("message_id", message_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

messageSenders::messageSenders()
  : total_count_()
  , senders_()
{}

messageSenders::messageSenders(int32 total_count_, array<object_ptr<MessageSender>> &&senders_)
  : total_count_(total_count_)
  , senders_(std::move(senders_))
{}

const std::int32_t messageSenders::ID;

void messageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSenders");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("senders", senders_.size()); for (const auto &_value : senders_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageViewer::messageViewer()
  : user_id_()
  , view_date_()
{}

messageViewer::messageViewer(int53 user_id_, int32 view_date_)
  : user_id_(user_id_)
  , view_date_(view_date_)
{}

const std::int32_t messageViewer::ID;

void messageViewer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageViewer");
    s.store_field("user_id", user_id_);
    s.store_field("view_date", view_date_);
    s.store_class_end();
  }
}

pageBlockRelatedArticle::pageBlockRelatedArticle()
  : url_()
  , title_()
  , description_()
  , photo_()
  , author_()
  , publish_date_()
{}

pageBlockRelatedArticle::pageBlockRelatedArticle(string const &url_, string const &title_, string const &description_, object_ptr<photo> &&photo_, string const &author_, int32 publish_date_)
  : url_(url_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , author_(author_)
  , publish_date_(publish_date_)
{}

const std::int32_t pageBlockRelatedArticle::ID;

void pageBlockRelatedArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockRelatedArticle");
    s.store_field("url", url_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("author", author_);
    s.store_field("publish_date", publish_date_);
    s.store_class_end();
  }
}

passkey::passkey()
  : id_()
  , name_()
  , addition_date_()
  , last_usage_date_()
  , software_icon_custom_emoji_id_()
{}

passkey::passkey(string const &id_, string const &name_, int32 addition_date_, int32 last_usage_date_, int64 software_icon_custom_emoji_id_)
  : id_(id_)
  , name_(name_)
  , addition_date_(addition_date_)
  , last_usage_date_(last_usage_date_)
  , software_icon_custom_emoji_id_(software_icon_custom_emoji_id_)
{}

const std::int32_t passkey::ID;

void passkey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passkey");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_field("addition_date", addition_date_);
    s.store_field("last_usage_date", last_usage_date_);
    s.store_field("software_icon_custom_emoji_id", software_icon_custom_emoji_id_);
    s.store_class_end();
  }
}

paymentOption::paymentOption()
  : title_()
  , url_()
{}

paymentOption::paymentOption(string const &title_, string const &url_)
  : title_(title_)
  , url_(url_)
{}

const std::int32_t paymentOption::ID;

void paymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentOption");
    s.store_field("title", title_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

paymentProviderSmartGlocal::paymentProviderSmartGlocal()
  : public_token_()
  , tokenize_url_()
{}

paymentProviderSmartGlocal::paymentProviderSmartGlocal(string const &public_token_, string const &tokenize_url_)
  : public_token_(public_token_)
  , tokenize_url_(tokenize_url_)
{}

const std::int32_t paymentProviderSmartGlocal::ID;

void paymentProviderSmartGlocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentProviderSmartGlocal");
    s.store_field("public_token", public_token_);
    s.store_field("tokenize_url", tokenize_url_);
    s.store_class_end();
  }
}

paymentProviderStripe::paymentProviderStripe()
  : publishable_key_()
  , need_country_()
  , need_postal_code_()
  , need_cardholder_name_()
{}

paymentProviderStripe::paymentProviderStripe(string const &publishable_key_, bool need_country_, bool need_postal_code_, bool need_cardholder_name_)
  : publishable_key_(publishable_key_)
  , need_country_(need_country_)
  , need_postal_code_(need_postal_code_)
  , need_cardholder_name_(need_cardholder_name_)
{}

const std::int32_t paymentProviderStripe::ID;

void paymentProviderStripe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentProviderStripe");
    s.store_field("publishable_key", publishable_key_);
    s.store_field("need_country", need_country_);
    s.store_field("need_postal_code", need_postal_code_);
    s.store_field("need_cardholder_name", need_cardholder_name_);
    s.store_class_end();
  }
}

paymentProviderOther::paymentProviderOther()
  : url_()
{}

paymentProviderOther::paymentProviderOther(string const &url_)
  : url_(url_)
{}

const std::int32_t paymentProviderOther::ID;

void paymentProviderOther::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentProviderOther");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

pollTypeRegular::pollTypeRegular() {
}

const std::int32_t pollTypeRegular::ID;

void pollTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollTypeRegular");
    s.store_class_end();
  }
}

pollTypeQuiz::pollTypeQuiz()
  : correct_option_ids_()
  , explanation_()
  , explanation_media_()
{}

pollTypeQuiz::pollTypeQuiz(array<int32> &&correct_option_ids_, object_ptr<formattedText> &&explanation_, object_ptr<MessageContent> &&explanation_media_)
  : correct_option_ids_(std::move(correct_option_ids_))
  , explanation_(std::move(explanation_))
  , explanation_media_(std::move(explanation_media_))
{}

const std::int32_t pollTypeQuiz::ID;

void pollTypeQuiz::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollTypeQuiz");
    { s.store_vector_begin("correct_option_ids", correct_option_ids_.size()); for (const auto &_value : correct_option_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("explanation", static_cast<const BaseObject *>(explanation_.get()));
    s.store_object_field("explanation_media", static_cast<const BaseObject *>(explanation_media_.get()));
    s.store_class_end();
  }
}

premiumGiveawayPaymentOptions::premiumGiveawayPaymentOptions()
  : options_()
{}

premiumGiveawayPaymentOptions::premiumGiveawayPaymentOptions(array<object_ptr<premiumGiveawayPaymentOption>> &&options_)
  : options_(std::move(options_))
{}

const std::int32_t premiumGiveawayPaymentOptions::ID;

void premiumGiveawayPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumGiveawayPaymentOptions");
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

premiumSourceLimitExceeded::premiumSourceLimitExceeded()
  : limit_type_()
{}

premiumSourceLimitExceeded::premiumSourceLimitExceeded(object_ptr<PremiumLimitType> &&limit_type_)
  : limit_type_(std::move(limit_type_))
{}

const std::int32_t premiumSourceLimitExceeded::ID;

void premiumSourceLimitExceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSourceLimitExceeded");
    s.store_object_field("limit_type", static_cast<const BaseObject *>(limit_type_.get()));
    s.store_class_end();
  }
}

premiumSourceFeature::premiumSourceFeature()
  : feature_()
{}

premiumSourceFeature::premiumSourceFeature(object_ptr<PremiumFeature> &&feature_)
  : feature_(std::move(feature_))
{}

const std::int32_t premiumSourceFeature::ID;

void premiumSourceFeature::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSourceFeature");
    s.store_object_field("feature", static_cast<const BaseObject *>(feature_.get()));
    s.store_class_end();
  }
}

premiumSourceBusinessFeature::premiumSourceBusinessFeature()
  : feature_()
{}

premiumSourceBusinessFeature::premiumSourceBusinessFeature(object_ptr<BusinessFeature> &&feature_)
  : feature_(std::move(feature_))
{}

const std::int32_t premiumSourceBusinessFeature::ID;

void premiumSourceBusinessFeature::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSourceBusinessFeature");
    s.store_object_field("feature", static_cast<const BaseObject *>(feature_.get()));
    s.store_class_end();
  }
}

premiumSourceStoryFeature::premiumSourceStoryFeature()
  : feature_()
{}

premiumSourceStoryFeature::premiumSourceStoryFeature(object_ptr<PremiumStoryFeature> &&feature_)
  : feature_(std::move(feature_))
{}

const std::int32_t premiumSourceStoryFeature::ID;

void premiumSourceStoryFeature::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSourceStoryFeature");
    s.store_object_field("feature", static_cast<const BaseObject *>(feature_.get()));
    s.store_class_end();
  }
}

premiumSourceLink::premiumSourceLink()
  : referrer_()
{}

premiumSourceLink::premiumSourceLink(string const &referrer_)
  : referrer_(referrer_)
{}

const std::int32_t premiumSourceLink::ID;

void premiumSourceLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSourceLink");
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

premiumSourceSettings::premiumSourceSettings() {
}

const std::int32_t premiumSourceSettings::ID;

void premiumSourceSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSourceSettings");
    s.store_class_end();
  }
}

premiumStatePaymentOption::premiumStatePaymentOption()
  : payment_option_()
  , is_current_()
  , is_upgrade_()
  , last_transaction_id_()
{}

premiumStatePaymentOption::premiumStatePaymentOption(object_ptr<premiumPaymentOption> &&payment_option_, bool is_current_, bool is_upgrade_, string const &last_transaction_id_)
  : payment_option_(std::move(payment_option_))
  , is_current_(is_current_)
  , is_upgrade_(is_upgrade_)
  , last_transaction_id_(last_transaction_id_)
{}

const std::int32_t premiumStatePaymentOption::ID;

void premiumStatePaymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumStatePaymentOption");
    s.store_object_field("payment_option", static_cast<const BaseObject *>(payment_option_.get()));
    s.store_field("is_current", is_current_);
    s.store_field("is_upgrade", is_upgrade_);
    s.store_field("last_transaction_id", last_transaction_id_);
    s.store_class_end();
  }
}

profileTabPosts::profileTabPosts() {
}

const std::int32_t profileTabPosts::ID;

void profileTabPosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabPosts");
    s.store_class_end();
  }
}

profileTabGifts::profileTabGifts() {
}

const std::int32_t profileTabGifts::ID;

void profileTabGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabGifts");
    s.store_class_end();
  }
}

profileTabMedia::profileTabMedia() {
}

const std::int32_t profileTabMedia::ID;

void profileTabMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabMedia");
    s.store_class_end();
  }
}

profileTabFiles::profileTabFiles() {
}

const std::int32_t profileTabFiles::ID;

void profileTabFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabFiles");
    s.store_class_end();
  }
}

profileTabLinks::profileTabLinks() {
}

const std::int32_t profileTabLinks::ID;

void profileTabLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabLinks");
    s.store_class_end();
  }
}

profileTabMusic::profileTabMusic() {
}

const std::int32_t profileTabMusic::ID;

void profileTabMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabMusic");
    s.store_class_end();
  }
}

profileTabVoice::profileTabVoice() {
}

const std::int32_t profileTabVoice::ID;

void profileTabVoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabVoice");
    s.store_class_end();
  }
}

profileTabGifs::profileTabGifs() {
}

const std::int32_t profileTabGifs::ID;

void profileTabGifs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabGifs");
    s.store_class_end();
  }
}

proxy::proxy()
  : server_()
  , port_()
  , type_()
{}

proxy::proxy(string const &server_, int32 port_, object_ptr<ProxyType> &&type_)
  : server_(server_)
  , port_(port_)
  , type_(std::move(type_))
{}

const std::int32_t proxy::ID;

void proxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxy");
    s.store_field("server", server_);
    s.store_field("port", port_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

pushReceiverId::pushReceiverId()
  : id_()
{}

pushReceiverId::pushReceiverId(int64 id_)
  : id_(id_)
{}

const std::int32_t pushReceiverId::ID;

void pushReceiverId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushReceiverId");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

quickReplyMessage::quickReplyMessage()
  : id_()
  , sending_state_()
  , can_be_edited_()
  , reply_to_message_id_()
  , via_bot_user_id_()
  , media_album_id_()
  , content_()
  , reply_markup_()
{}

quickReplyMessage::quickReplyMessage(int53 id_, object_ptr<MessageSendingState> &&sending_state_, bool can_be_edited_, int53 reply_to_message_id_, int53 via_bot_user_id_, int64 media_album_id_, object_ptr<MessageContent> &&content_, object_ptr<ReplyMarkup> &&reply_markup_)
  : id_(id_)
  , sending_state_(std::move(sending_state_))
  , can_be_edited_(can_be_edited_)
  , reply_to_message_id_(reply_to_message_id_)
  , via_bot_user_id_(via_bot_user_id_)
  , media_album_id_(media_album_id_)
  , content_(std::move(content_))
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t quickReplyMessage::ID;

void quickReplyMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "quickReplyMessage");
    s.store_field("id", id_);
    s.store_object_field("sending_state", static_cast<const BaseObject *>(sending_state_.get()));
    s.store_field("can_be_edited", can_be_edited_);
    s.store_field("reply_to_message_id", reply_to_message_id_);
    s.store_field("via_bot_user_id", via_bot_user_id_);
    s.store_field("media_album_id", media_album_id_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

quickReplyMessages::quickReplyMessages()
  : messages_()
{}

quickReplyMessages::quickReplyMessages(array<object_ptr<quickReplyMessage>> &&messages_)
  : messages_(std::move(messages_))
{}

const std::int32_t quickReplyMessages::ID;

void quickReplyMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "quickReplyMessages");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

recommendedChatFolders::recommendedChatFolders()
  : chat_folders_()
{}

recommendedChatFolders::recommendedChatFolders(array<object_ptr<recommendedChatFolder>> &&chat_folders_)
  : chat_folders_(std::move(chat_folders_))
{}

const std::int32_t recommendedChatFolders::ID;

void recommendedChatFolders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recommendedChatFolders");
    { s.store_vector_begin("chat_folders", chat_folders_.size()); for (const auto &_value : chat_folders_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

revenueWithdrawalStatePending::revenueWithdrawalStatePending() {
}

const std::int32_t revenueWithdrawalStatePending::ID;

void revenueWithdrawalStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "revenueWithdrawalStatePending");
    s.store_class_end();
  }
}

revenueWithdrawalStateSucceeded::revenueWithdrawalStateSucceeded()
  : date_()
  , url_()
{}

revenueWithdrawalStateSucceeded::revenueWithdrawalStateSucceeded(int32 date_, string const &url_)
  : date_(date_)
  , url_(url_)
{}

const std::int32_t revenueWithdrawalStateSucceeded::ID;

void revenueWithdrawalStateSucceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "revenueWithdrawalStateSucceeded");
    s.store_field("date", date_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

revenueWithdrawalStateFailed::revenueWithdrawalStateFailed() {
}

const std::int32_t revenueWithdrawalStateFailed::ID;

void revenueWithdrawalStateFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "revenueWithdrawalStateFailed");
    s.store_class_end();
  }
}

richTextPlain::richTextPlain()
  : text_()
{}

richTextPlain::richTextPlain(string const &text_)
  : text_(text_)
{}

const std::int32_t richTextPlain::ID;

void richTextPlain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextPlain");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

richTextBold::richTextBold()
  : text_()
{}

richTextBold::richTextBold(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextBold::ID;

void richTextBold::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextBold");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextItalic::richTextItalic()
  : text_()
{}

richTextItalic::richTextItalic(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextItalic::ID;

void richTextItalic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextItalic");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextUnderline::richTextUnderline()
  : text_()
{}

richTextUnderline::richTextUnderline(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextUnderline::ID;

void richTextUnderline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextUnderline");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextStrikethrough::richTextStrikethrough()
  : text_()
{}

richTextStrikethrough::richTextStrikethrough(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextStrikethrough::ID;

void richTextStrikethrough::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextStrikethrough");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextFixed::richTextFixed()
  : text_()
{}

richTextFixed::richTextFixed(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextFixed::ID;

void richTextFixed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextFixed");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextUrl::richTextUrl()
  : text_()
  , url_()
  , is_cached_()
{}

richTextUrl::richTextUrl(object_ptr<RichText> &&text_, string const &url_, bool is_cached_)
  : text_(std::move(text_))
  , url_(url_)
  , is_cached_(is_cached_)
{}

const std::int32_t richTextUrl::ID;

void richTextUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextUrl");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("url", url_);
    s.store_field("is_cached", is_cached_);
    s.store_class_end();
  }
}

richTextEmailAddress::richTextEmailAddress()
  : text_()
  , email_address_()
{}

richTextEmailAddress::richTextEmailAddress(object_ptr<RichText> &&text_, string const &email_address_)
  : text_(std::move(text_))
  , email_address_(email_address_)
{}

const std::int32_t richTextEmailAddress::ID;

void richTextEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextEmailAddress");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

richTextSubscript::richTextSubscript()
  : text_()
{}

richTextSubscript::richTextSubscript(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextSubscript::ID;

void richTextSubscript::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextSubscript");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextSuperscript::richTextSuperscript()
  : text_()
{}

richTextSuperscript::richTextSuperscript(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextSuperscript::ID;

void richTextSuperscript::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextSuperscript");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextMarked::richTextMarked()
  : text_()
{}

richTextMarked::richTextMarked(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t richTextMarked::ID;

void richTextMarked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextMarked");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

richTextPhoneNumber::richTextPhoneNumber()
  : text_()
  , phone_number_()
{}

richTextPhoneNumber::richTextPhoneNumber(object_ptr<RichText> &&text_, string const &phone_number_)
  : text_(std::move(text_))
  , phone_number_(phone_number_)
{}

const std::int32_t richTextPhoneNumber::ID;

void richTextPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextPhoneNumber");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

richTextIcon::richTextIcon()
  : document_()
  , width_()
  , height_()
{}

richTextIcon::richTextIcon(object_ptr<document> &&document_, int32 width_, int32 height_)
  : document_(std::move(document_))
  , width_(width_)
  , height_(height_)
{}

const std::int32_t richTextIcon::ID;

void richTextIcon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextIcon");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

richTextReference::richTextReference()
  : text_()
  , anchor_name_()
  , url_()
{}

richTextReference::richTextReference(object_ptr<RichText> &&text_, string const &anchor_name_, string const &url_)
  : text_(std::move(text_))
  , anchor_name_(anchor_name_)
  , url_(url_)
{}

const std::int32_t richTextReference::ID;

void richTextReference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextReference");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("anchor_name", anchor_name_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

richTextAnchor::richTextAnchor()
  : name_()
{}

richTextAnchor::richTextAnchor(string const &name_)
  : name_(name_)
{}

const std::int32_t richTextAnchor::ID;

void richTextAnchor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextAnchor");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

richTextAnchorLink::richTextAnchorLink()
  : text_()
  , anchor_name_()
  , url_()
{}

richTextAnchorLink::richTextAnchorLink(object_ptr<RichText> &&text_, string const &anchor_name_, string const &url_)
  : text_(std::move(text_))
  , anchor_name_(anchor_name_)
  , url_(url_)
{}

const std::int32_t richTextAnchorLink::ID;

void richTextAnchorLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTextAnchorLink");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("anchor_name", anchor_name_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

richTexts::richTexts()
  : texts_()
{}

richTexts::richTexts(array<object_ptr<RichText>> &&texts_)
  : texts_(std::move(texts_))
{}

const std::int32_t richTexts::ID;

void richTexts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "richTexts");
    { s.store_vector_begin("texts", texts_.size()); for (const auto &_value : texts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

savedMessagesTag::savedMessagesTag()
  : tag_()
  , label_()
  , count_()
{}

savedMessagesTag::savedMessagesTag(object_ptr<ReactionType> &&tag_, string const &label_, int32 count_)
  : tag_(std::move(tag_))
  , label_(label_)
  , count_(count_)
{}

const std::int32_t savedMessagesTag::ID;

void savedMessagesTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedMessagesTag");
    s.store_object_field("tag", static_cast<const BaseObject *>(tag_.get()));
    s.store_field("label", label_);
    s.store_field("count", count_);
    s.store_class_end();
  }
}

sessions::sessions()
  : sessions_()
  , inactive_session_ttl_days_()
{}

sessions::sessions(array<object_ptr<session>> &&sessions_, int32 inactive_session_ttl_days_)
  : sessions_(std::move(sessions_))
  , inactive_session_ttl_days_(inactive_session_ttl_days_)
{}

const std::int32_t sessions::ID;

void sessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessions");
    { s.store_vector_begin("sessions", sessions_.size()); for (const auto &_value : sessions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("inactive_session_ttl_days", inactive_session_ttl_days_);
    s.store_class_end();
  }
}

sponsoredChats::sponsoredChats()
  : chats_()
{}

sponsoredChats::sponsoredChats(array<object_ptr<sponsoredChat>> &&chats_)
  : chats_(std::move(chats_))
{}

const std::int32_t sponsoredChats::ID;

void sponsoredChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredChats");
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sponsoredMessage::sponsoredMessage()
  : message_id_()
  , is_recommended_()
  , can_be_reported_()
  , content_()
  , sponsor_()
  , title_()
  , button_text_()
  , accent_color_id_()
  , background_custom_emoji_id_()
  , additional_info_()
{}

sponsoredMessage::sponsoredMessage(int53 message_id_, bool is_recommended_, bool can_be_reported_, object_ptr<MessageContent> &&content_, object_ptr<advertisementSponsor> &&sponsor_, string const &title_, string const &button_text_, int32 accent_color_id_, int64 background_custom_emoji_id_, string const &additional_info_)
  : message_id_(message_id_)
  , is_recommended_(is_recommended_)
  , can_be_reported_(can_be_reported_)
  , content_(std::move(content_))
  , sponsor_(std::move(sponsor_))
  , title_(title_)
  , button_text_(button_text_)
  , accent_color_id_(accent_color_id_)
  , background_custom_emoji_id_(background_custom_emoji_id_)
  , additional_info_(additional_info_)
{}

const std::int32_t sponsoredMessage::ID;

void sponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredMessage");
    s.store_field("message_id", message_id_);
    s.store_field("is_recommended", is_recommended_);
    s.store_field("can_be_reported", can_be_reported_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("sponsor", static_cast<const BaseObject *>(sponsor_.get()));
    s.store_field("title", title_);
    s.store_field("button_text", button_text_);
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("background_custom_emoji_id", background_custom_emoji_id_);
    s.store_field("additional_info", additional_info_);
    s.store_class_end();
  }
}

sponsoredMessages::sponsoredMessages()
  : messages_()
  , messages_between_()
{}

sponsoredMessages::sponsoredMessages(array<object_ptr<sponsoredMessage>> &&messages_, int32 messages_between_)
  : messages_(std::move(messages_))
  , messages_between_(messages_between_)
{}

const std::int32_t sponsoredMessages::ID;

void sponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredMessages");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("messages_between", messages_between_);
    s.store_class_end();
  }
}

starGiveawayPaymentOption::starGiveawayPaymentOption()
  : currency_()
  , amount_()
  , star_count_()
  , store_product_id_()
  , yearly_boost_count_()
  , winner_options_()
  , is_default_()
  , is_additional_()
{}

starGiveawayPaymentOption::starGiveawayPaymentOption(string const &currency_, int53 amount_, int53 star_count_, string const &store_product_id_, int32 yearly_boost_count_, array<object_ptr<starGiveawayWinnerOption>> &&winner_options_, bool is_default_, bool is_additional_)
  : currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
  , store_product_id_(store_product_id_)
  , yearly_boost_count_(yearly_boost_count_)
  , winner_options_(std::move(winner_options_))
  , is_default_(is_default_)
  , is_additional_(is_additional_)
{}

const std::int32_t starGiveawayPaymentOption::ID;

void starGiveawayPaymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiveawayPaymentOption");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_field("store_product_id", store_product_id_);
    s.store_field("yearly_boost_count", yearly_boost_count_);
    { s.store_vector_begin("winner_options", winner_options_.size()); for (const auto &_value : winner_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_default", is_default_);
    s.store_field("is_additional", is_additional_);
    s.store_class_end();
  }
}

storyContentPhoto::storyContentPhoto()
  : photo_()
{}

storyContentPhoto::storyContentPhoto(object_ptr<photo> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t storyContentPhoto::ID;

void storyContentPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

storyContentVideo::storyContentVideo()
  : video_()
  , alternative_video_()
{}

storyContentVideo::storyContentVideo(object_ptr<storyVideo> &&video_, object_ptr<storyVideo> &&alternative_video_)
  : video_(std::move(video_))
  , alternative_video_(std::move(alternative_video_))
{}

const std::int32_t storyContentVideo::ID;

void storyContentVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("alternative_video", static_cast<const BaseObject *>(alternative_video_.get()));
    s.store_class_end();
  }
}

storyContentLive::storyContentLive()
  : group_call_id_()
  , is_rtmp_stream_()
{}

storyContentLive::storyContentLive(int32 group_call_id_, bool is_rtmp_stream_)
  : group_call_id_(group_call_id_)
  , is_rtmp_stream_(is_rtmp_stream_)
{}

const std::int32_t storyContentLive::ID;

void storyContentLive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentLive");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("is_rtmp_stream", is_rtmp_stream_);
    s.store_class_end();
  }
}

storyContentUnsupported::storyContentUnsupported() {
}

const std::int32_t storyContentUnsupported::ID;

void storyContentUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentUnsupported");
    s.store_class_end();
  }
}

supergroupFullInfo::supergroupFullInfo()
  : photo_()
  , description_()
  , member_count_()
  , administrator_count_()
  , restricted_count_()
  , banned_count_()
  , linked_chat_id_()
  , direct_messages_chat_id_()
  , slow_mode_delay_()
  , slow_mode_delay_expires_in_()
  , can_enable_paid_messages_()
  , can_enable_paid_reaction_()
  , can_get_members_()
  , has_hidden_members_()
  , can_hide_members_()
  , can_set_sticker_set_()
  , can_set_location_()
  , can_get_statistics_()
  , can_get_revenue_statistics_()
  , can_get_star_revenue_statistics_()
  , can_send_gift_()
  , can_toggle_aggressive_anti_spam_()
  , is_all_history_available_()
  , can_have_sponsored_messages_()
  , has_aggressive_anti_spam_enabled_()
  , has_paid_media_allowed_()
  , has_pinned_stories_()
  , gift_count_()
  , my_boost_count_()
  , unrestrict_boost_count_()
  , outgoing_paid_message_star_count_()
  , sticker_set_id_()
  , custom_emoji_sticker_set_id_()
  , location_()
  , invite_link_()
  , bot_commands_()
  , bot_verification_()
  , main_profile_tab_()
  , upgraded_from_basic_group_id_()
  , upgraded_from_max_message_id_()
{}

supergroupFullInfo::supergroupFullInfo(object_ptr<chatPhoto> &&photo_, string const &description_, int32 member_count_, int32 administrator_count_, int32 restricted_count_, int32 banned_count_, int53 linked_chat_id_, int53 direct_messages_chat_id_, int32 slow_mode_delay_, double slow_mode_delay_expires_in_, bool can_enable_paid_messages_, bool can_enable_paid_reaction_, bool can_get_members_, bool has_hidden_members_, bool can_hide_members_, bool can_set_sticker_set_, bool can_set_location_, bool can_get_statistics_, bool can_get_revenue_statistics_, bool can_get_star_revenue_statistics_, bool can_send_gift_, bool can_toggle_aggressive_anti_spam_, bool is_all_history_available_, bool can_have_sponsored_messages_, bool has_aggressive_anti_spam_enabled_, bool has_paid_media_allowed_, bool has_pinned_stories_, int32 gift_count_, int32 my_boost_count_, int32 unrestrict_boost_count_, int53 outgoing_paid_message_star_count_, int64 sticker_set_id_, int64 custom_emoji_sticker_set_id_, object_ptr<chatLocation> &&location_, object_ptr<chatInviteLink> &&invite_link_, array<object_ptr<botCommands>> &&bot_commands_, object_ptr<botVerification> &&bot_verification_, object_ptr<ProfileTab> &&main_profile_tab_, int53 upgraded_from_basic_group_id_, int53 upgraded_from_max_message_id_)
  : photo_(std::move(photo_))
  , description_(description_)
  , member_count_(member_count_)
  , administrator_count_(administrator_count_)
  , restricted_count_(restricted_count_)
  , banned_count_(banned_count_)
  , linked_chat_id_(linked_chat_id_)
  , direct_messages_chat_id_(direct_messages_chat_id_)
  , slow_mode_delay_(slow_mode_delay_)
  , slow_mode_delay_expires_in_(slow_mode_delay_expires_in_)
  , can_enable_paid_messages_(can_enable_paid_messages_)
  , can_enable_paid_reaction_(can_enable_paid_reaction_)
  , can_get_members_(can_get_members_)
  , has_hidden_members_(has_hidden_members_)
  , can_hide_members_(can_hide_members_)
  , can_set_sticker_set_(can_set_sticker_set_)
  , can_set_location_(can_set_location_)
  , can_get_statistics_(can_get_statistics_)
  , can_get_revenue_statistics_(can_get_revenue_statistics_)
  , can_get_star_revenue_statistics_(can_get_star_revenue_statistics_)
  , can_send_gift_(can_send_gift_)
  , can_toggle_aggressive_anti_spam_(can_toggle_aggressive_anti_spam_)
  , is_all_history_available_(is_all_history_available_)
  , can_have_sponsored_messages_(can_have_sponsored_messages_)
  , has_aggressive_anti_spam_enabled_(has_aggressive_anti_spam_enabled_)
  , has_paid_media_allowed_(has_paid_media_allowed_)
  , has_pinned_stories_(has_pinned_stories_)
  , gift_count_(gift_count_)
  , my_boost_count_(my_boost_count_)
  , unrestrict_boost_count_(unrestrict_boost_count_)
  , outgoing_paid_message_star_count_(outgoing_paid_message_star_count_)
  , sticker_set_id_(sticker_set_id_)
  , custom_emoji_sticker_set_id_(custom_emoji_sticker_set_id_)
  , location_(std::move(location_))
  , invite_link_(std::move(invite_link_))
  , bot_commands_(std::move(bot_commands_))
  , bot_verification_(std::move(bot_verification_))
  , main_profile_tab_(std::move(main_profile_tab_))
  , upgraded_from_basic_group_id_(upgraded_from_basic_group_id_)
  , upgraded_from_max_message_id_(upgraded_from_max_message_id_)
{}

const std::int32_t supergroupFullInfo::ID;

void supergroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupFullInfo");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("description", description_);
    s.store_field("member_count", member_count_);
    s.store_field("administrator_count", administrator_count_);
    s.store_field("restricted_count", restricted_count_);
    s.store_field("banned_count", banned_count_);
    s.store_field("linked_chat_id", linked_chat_id_);
    s.store_field("direct_messages_chat_id", direct_messages_chat_id_);
    s.store_field("slow_mode_delay", slow_mode_delay_);
    s.store_field("slow_mode_delay_expires_in", slow_mode_delay_expires_in_);
    s.store_field("can_enable_paid_messages", can_enable_paid_messages_);
    s.store_field("can_enable_paid_reaction", can_enable_paid_reaction_);
    s.store_field("can_get_members", can_get_members_);
    s.store_field("has_hidden_members", has_hidden_members_);
    s.store_field("can_hide_members", can_hide_members_);
    s.store_field("can_set_sticker_set", can_set_sticker_set_);
    s.store_field("can_set_location", can_set_location_);
    s.store_field("can_get_statistics", can_get_statistics_);
    s.store_field("can_get_revenue_statistics", can_get_revenue_statistics_);
    s.store_field("can_get_star_revenue_statistics", can_get_star_revenue_statistics_);
    s.store_field("can_send_gift", can_send_gift_);
    s.store_field("can_toggle_aggressive_anti_spam", can_toggle_aggressive_anti_spam_);
    s.store_field("is_all_history_available", is_all_history_available_);
    s.store_field("can_have_sponsored_messages", can_have_sponsored_messages_);
    s.store_field("has_aggressive_anti_spam_enabled", has_aggressive_anti_spam_enabled_);
    s.store_field("has_paid_media_allowed", has_paid_media_allowed_);
    s.store_field("has_pinned_stories", has_pinned_stories_);
    s.store_field("gift_count", gift_count_);
    s.store_field("my_boost_count", my_boost_count_);
    s.store_field("unrestrict_boost_count", unrestrict_boost_count_);
    s.store_field("outgoing_paid_message_star_count", outgoing_paid_message_star_count_);
    s.store_field("sticker_set_id", sticker_set_id_);
    s.store_field("custom_emoji_sticker_set_id", custom_emoji_sticker_set_id_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    { s.store_vector_begin("bot_commands", bot_commands_.size()); for (const auto &_value : bot_commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("bot_verification", static_cast<const BaseObject *>(bot_verification_.get()));
    s.store_object_field("main_profile_tab", static_cast<const BaseObject *>(main_profile_tab_.get()));
    s.store_field("upgraded_from_basic_group_id", upgraded_from_basic_group_id_);
    s.store_field("upgraded_from_max_message_id", upgraded_from_max_message_id_);
    s.store_class_end();
  }
}

tMeUrl::tMeUrl()
  : url_()
  , type_()
{}

tMeUrl::tMeUrl(string const &url_, object_ptr<TMeUrlType> &&type_)
  : url_(url_)
  , type_(std::move(type_))
{}

const std::int32_t tMeUrl::ID;

void tMeUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrl");
    s.store_field("url", url_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

tMeUrlTypeUser::tMeUrlTypeUser()
  : user_id_()
{}

tMeUrlTypeUser::tMeUrlTypeUser(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t tMeUrlTypeUser::ID;

void tMeUrlTypeUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrlTypeUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

tMeUrlTypeSupergroup::tMeUrlTypeSupergroup()
  : supergroup_id_()
{}

tMeUrlTypeSupergroup::tMeUrlTypeSupergroup(int53 supergroup_id_)
  : supergroup_id_(supergroup_id_)
{}

const std::int32_t tMeUrlTypeSupergroup::ID;

void tMeUrlTypeSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrlTypeSupergroup");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_class_end();
  }
}

tMeUrlTypeChatInvite::tMeUrlTypeChatInvite()
  : info_()
{}

tMeUrlTypeChatInvite::tMeUrlTypeChatInvite(object_ptr<chatInviteLinkInfo> &&info_)
  : info_(std::move(info_))
{}

const std::int32_t tMeUrlTypeChatInvite::ID;

void tMeUrlTypeChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrlTypeChatInvite");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

tMeUrlTypeStickerSet::tMeUrlTypeStickerSet()
  : sticker_set_id_()
{}

tMeUrlTypeStickerSet::tMeUrlTypeStickerSet(int64 sticker_set_id_)
  : sticker_set_id_(sticker_set_id_)
{}

const std::int32_t tMeUrlTypeStickerSet::ID;

void tMeUrlTypeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tMeUrlTypeStickerSet");
    s.store_field("sticker_set_id", sticker_set_id_);
    s.store_class_end();
  }
}

testString::testString()
  : value_()
{}

testString::testString(string const &value_)
  : value_(value_)
{}

const std::int32_t testString::ID;

void testString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testString");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

text::text()
  : text_()
{}

text::text(string const &text_)
  : text_(text_)
{}

const std::int32_t text::ID;

void text::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "text");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

themeSettings::themeSettings()
  : base_theme_()
  , accent_color_()
  , background_()
  , outgoing_message_fill_()
  , animate_outgoing_message_fill_()
  , outgoing_message_accent_color_()
{}

themeSettings::themeSettings(object_ptr<BuiltInTheme> &&base_theme_, int32 accent_color_, object_ptr<background> &&background_, object_ptr<BackgroundFill> &&outgoing_message_fill_, bool animate_outgoing_message_fill_, int32 outgoing_message_accent_color_)
  : base_theme_(std::move(base_theme_))
  , accent_color_(accent_color_)
  , background_(std::move(background_))
  , outgoing_message_fill_(std::move(outgoing_message_fill_))
  , animate_outgoing_message_fill_(animate_outgoing_message_fill_)
  , outgoing_message_accent_color_(outgoing_message_accent_color_)
{}

const std::int32_t themeSettings::ID;

void themeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "themeSettings");
    s.store_object_field("base_theme", static_cast<const BaseObject *>(base_theme_.get()));
    s.store_field("accent_color", accent_color_);
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("outgoing_message_fill", static_cast<const BaseObject *>(outgoing_message_fill_.get()));
    s.store_field("animate_outgoing_message_fill", animate_outgoing_message_fill_);
    s.store_field("outgoing_message_accent_color", outgoing_message_accent_color_);
    s.store_class_end();
  }
}

thumbnail::thumbnail()
  : format_()
  , width_()
  , height_()
  , file_()
{}

thumbnail::thumbnail(object_ptr<ThumbnailFormat> &&format_, int32 width_, int32 height_, object_ptr<file> &&file_)
  : format_(std::move(format_))
  , width_(width_)
  , height_(height_)
  , file_(std::move(file_))
{}

const std::int32_t thumbnail::ID;

void thumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnail");
    s.store_object_field("format", static_cast<const BaseObject *>(format_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

thumbnailFormatJpeg::thumbnailFormatJpeg() {
}

const std::int32_t thumbnailFormatJpeg::ID;

void thumbnailFormatJpeg::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatJpeg");
    s.store_class_end();
  }
}

thumbnailFormatGif::thumbnailFormatGif() {
}

const std::int32_t thumbnailFormatGif::ID;

void thumbnailFormatGif::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatGif");
    s.store_class_end();
  }
}

thumbnailFormatMpeg4::thumbnailFormatMpeg4() {
}

const std::int32_t thumbnailFormatMpeg4::ID;

void thumbnailFormatMpeg4::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatMpeg4");
    s.store_class_end();
  }
}

thumbnailFormatPng::thumbnailFormatPng() {
}

const std::int32_t thumbnailFormatPng::ID;

void thumbnailFormatPng::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatPng");
    s.store_class_end();
  }
}

thumbnailFormatTgs::thumbnailFormatTgs() {
}

const std::int32_t thumbnailFormatTgs::ID;

void thumbnailFormatTgs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatTgs");
    s.store_class_end();
  }
}

thumbnailFormatWebm::thumbnailFormatWebm() {
}

const std::int32_t thumbnailFormatWebm::ID;

void thumbnailFormatWebm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatWebm");
    s.store_class_end();
  }
}

thumbnailFormatWebp::thumbnailFormatWebp() {
}

const std::int32_t thumbnailFormatWebp::ID;

void thumbnailFormatWebp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "thumbnailFormatWebp");
    s.store_class_end();
  }
}

tonRevenueStatus::tonRevenueStatus()
  : total_amount_()
  , balance_amount_()
  , available_amount_()
  , withdrawal_enabled_()
{}

tonRevenueStatus::tonRevenueStatus(int64 total_amount_, int64 balance_amount_, int64 available_amount_, bool withdrawal_enabled_)
  : total_amount_(total_amount_)
  , balance_amount_(balance_amount_)
  , available_amount_(available_amount_)
  , withdrawal_enabled_(withdrawal_enabled_)
{}

const std::int32_t tonRevenueStatus::ID;

void tonRevenueStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonRevenueStatus");
    s.store_field("total_amount", total_amount_);
    s.store_field("balance_amount", balance_amount_);
    s.store_field("available_amount", available_amount_);
    s.store_field("withdrawal_enabled", withdrawal_enabled_);
    s.store_class_end();
  }
}

tonTransaction::tonTransaction()
  : id_()
  , ton_amount_()
  , is_refund_()
  , date_()
  , type_()
{}

tonTransaction::tonTransaction(string const &id_, int53 ton_amount_, bool is_refund_, int32 date_, object_ptr<TonTransactionType> &&type_)
  : id_(id_)
  , ton_amount_(ton_amount_)
  , is_refund_(is_refund_)
  , date_(date_)
  , type_(std::move(type_))
{}

const std::int32_t tonTransaction::ID;

void tonTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "tonTransaction");
    s.store_field("id", id_);
    s.store_field("ton_amount", ton_amount_);
    s.store_field("is_refund", is_refund_);
    s.store_field("date", date_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

userFullInfo::userFullInfo()
  : personal_photo_()
  , photo_()
  , public_photo_()
  , block_list_()
  , can_be_called_()
  , supports_video_calls_()
  , has_private_calls_()
  , has_private_forwards_()
  , has_restricted_voice_and_video_note_messages_()
  , has_posted_to_profile_stories_()
  , has_sponsored_messages_enabled_()
  , need_phone_number_privacy_exception_()
  , set_chat_background_()
  , uses_unofficial_app_()
  , bio_()
  , birthdate_()
  , personal_chat_id_()
  , gift_count_()
  , group_in_common_count_()
  , incoming_paid_message_star_count_()
  , outgoing_paid_message_star_count_()
  , gift_settings_()
  , bot_verification_()
  , main_profile_tab_()
  , first_profile_audio_()
  , rating_()
  , pending_rating_()
  , pending_rating_date_()
  , note_()
  , business_info_()
  , bot_info_()
{}

userFullInfo::userFullInfo(object_ptr<chatPhoto> &&personal_photo_, object_ptr<chatPhoto> &&photo_, object_ptr<chatPhoto> &&public_photo_, object_ptr<BlockList> &&block_list_, bool can_be_called_, bool supports_video_calls_, bool has_private_calls_, bool has_private_forwards_, bool has_restricted_voice_and_video_note_messages_, bool has_posted_to_profile_stories_, bool has_sponsored_messages_enabled_, bool need_phone_number_privacy_exception_, bool set_chat_background_, bool uses_unofficial_app_, object_ptr<formattedText> &&bio_, object_ptr<birthdate> &&birthdate_, int53 personal_chat_id_, int32 gift_count_, int32 group_in_common_count_, int53 incoming_paid_message_star_count_, int53 outgoing_paid_message_star_count_, object_ptr<giftSettings> &&gift_settings_, object_ptr<botVerification> &&bot_verification_, object_ptr<ProfileTab> &&main_profile_tab_, object_ptr<audio> &&first_profile_audio_, object_ptr<userRating> &&rating_, object_ptr<userRating> &&pending_rating_, int32 pending_rating_date_, object_ptr<formattedText> &&note_, object_ptr<businessInfo> &&business_info_, object_ptr<botInfo> &&bot_info_)
  : personal_photo_(std::move(personal_photo_))
  , photo_(std::move(photo_))
  , public_photo_(std::move(public_photo_))
  , block_list_(std::move(block_list_))
  , can_be_called_(can_be_called_)
  , supports_video_calls_(supports_video_calls_)
  , has_private_calls_(has_private_calls_)
  , has_private_forwards_(has_private_forwards_)
  , has_restricted_voice_and_video_note_messages_(has_restricted_voice_and_video_note_messages_)
  , has_posted_to_profile_stories_(has_posted_to_profile_stories_)
  , has_sponsored_messages_enabled_(has_sponsored_messages_enabled_)
  , need_phone_number_privacy_exception_(need_phone_number_privacy_exception_)
  , set_chat_background_(set_chat_background_)
  , uses_unofficial_app_(uses_unofficial_app_)
  , bio_(std::move(bio_))
  , birthdate_(std::move(birthdate_))
  , personal_chat_id_(personal_chat_id_)
  , gift_count_(gift_count_)
  , group_in_common_count_(group_in_common_count_)
  , incoming_paid_message_star_count_(incoming_paid_message_star_count_)
  , outgoing_paid_message_star_count_(outgoing_paid_message_star_count_)
  , gift_settings_(std::move(gift_settings_))
  , bot_verification_(std::move(bot_verification_))
  , main_profile_tab_(std::move(main_profile_tab_))
  , first_profile_audio_(std::move(first_profile_audio_))
  , rating_(std::move(rating_))
  , pending_rating_(std::move(pending_rating_))
  , pending_rating_date_(pending_rating_date_)
  , note_(std::move(note_))
  , business_info_(std::move(business_info_))
  , bot_info_(std::move(bot_info_))
{}

const std::int32_t userFullInfo::ID;

void userFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userFullInfo");
    s.store_object_field("personal_photo", static_cast<const BaseObject *>(personal_photo_.get()));
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("public_photo", static_cast<const BaseObject *>(public_photo_.get()));
    s.store_object_field("block_list", static_cast<const BaseObject *>(block_list_.get()));
    s.store_field("can_be_called", can_be_called_);
    s.store_field("supports_video_calls", supports_video_calls_);
    s.store_field("has_private_calls", has_private_calls_);
    s.store_field("has_private_forwards", has_private_forwards_);
    s.store_field("has_restricted_voice_and_video_note_messages", has_restricted_voice_and_video_note_messages_);
    s.store_field("has_posted_to_profile_stories", has_posted_to_profile_stories_);
    s.store_field("has_sponsored_messages_enabled", has_sponsored_messages_enabled_);
    s.store_field("need_phone_number_privacy_exception", need_phone_number_privacy_exception_);
    s.store_field("set_chat_background", set_chat_background_);
    s.store_field("uses_unofficial_app", uses_unofficial_app_);
    s.store_object_field("bio", static_cast<const BaseObject *>(bio_.get()));
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_field("personal_chat_id", personal_chat_id_);
    s.store_field("gift_count", gift_count_);
    s.store_field("group_in_common_count", group_in_common_count_);
    s.store_field("incoming_paid_message_star_count", incoming_paid_message_star_count_);
    s.store_field("outgoing_paid_message_star_count", outgoing_paid_message_star_count_);
    s.store_object_field("gift_settings", static_cast<const BaseObject *>(gift_settings_.get()));
    s.store_object_field("bot_verification", static_cast<const BaseObject *>(bot_verification_.get()));
    s.store_object_field("main_profile_tab", static_cast<const BaseObject *>(main_profile_tab_.get()));
    s.store_object_field("first_profile_audio", static_cast<const BaseObject *>(first_profile_audio_.get()));
    s.store_object_field("rating", static_cast<const BaseObject *>(rating_.get()));
    s.store_object_field("pending_rating", static_cast<const BaseObject *>(pending_rating_.get()));
    s.store_field("pending_rating_date", pending_rating_date_);
    s.store_object_field("note", static_cast<const BaseObject *>(note_.get()));
    s.store_object_field("business_info", static_cast<const BaseObject *>(business_info_.get()));
    s.store_object_field("bot_info", static_cast<const BaseObject *>(bot_info_.get()));
    s.store_class_end();
  }
}

validatedOrderInfo::validatedOrderInfo()
  : order_info_id_()
  , shipping_options_()
{}

validatedOrderInfo::validatedOrderInfo(string const &order_info_id_, array<object_ptr<shippingOption>> &&shipping_options_)
  : order_info_id_(order_info_id_)
  , shipping_options_(std::move(shipping_options_))
{}

const std::int32_t validatedOrderInfo::ID;

void validatedOrderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "validatedOrderInfo");
    s.store_field("order_info_id", order_info_id_);
    { s.store_vector_begin("shipping_options", shipping_options_.size()); for (const auto &_value : shipping_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

addCustomServerLanguagePack::addCustomServerLanguagePack()
  : language_pack_id_()
{}

addCustomServerLanguagePack::addCustomServerLanguagePack(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t addCustomServerLanguagePack::ID;

void addCustomServerLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addCustomServerLanguagePack");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

addMessageReaction::addMessageReaction()
  : chat_id_()
  , message_id_()
  , reaction_type_()
  , is_big_()
  , update_recent_reactions_()
{}

addMessageReaction::addMessageReaction(int53 chat_id_, int53 message_id_, object_ptr<ReactionType> &&reaction_type_, bool is_big_, bool update_recent_reactions_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reaction_type_(std::move(reaction_type_))
  , is_big_(is_big_)
  , update_recent_reactions_(update_recent_reactions_)
{}

const std::int32_t addMessageReaction::ID;

void addMessageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addMessageReaction");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_field("is_big", is_big_);
    s.store_field("update_recent_reactions", update_recent_reactions_);
    s.store_class_end();
  }
}

addProfileAudio::addProfileAudio()
  : file_id_()
{}

addProfileAudio::addProfileAudio(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t addProfileAudio::ID;

void addProfileAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addProfileAudio");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

allowBotToSendMessages::allowBotToSendMessages()
  : bot_user_id_()
{}

allowBotToSendMessages::allowBotToSendMessages(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t allowBotToSendMessages::ID;

void allowBotToSendMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "allowBotToSendMessages");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

blockMessageSenderFromReplies::blockMessageSenderFromReplies()
  : message_id_()
  , delete_message_()
  , delete_all_messages_()
  , report_spam_()
{}

blockMessageSenderFromReplies::blockMessageSenderFromReplies(int53 message_id_, bool delete_message_, bool delete_all_messages_, bool report_spam_)
  : message_id_(message_id_)
  , delete_message_(delete_message_)
  , delete_all_messages_(delete_all_messages_)
  , report_spam_(report_spam_)
{}

const std::int32_t blockMessageSenderFromReplies::ID;

void blockMessageSenderFromReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "blockMessageSenderFromReplies");
    s.store_field("message_id", message_id_);
    s.store_field("delete_message", delete_message_);
    s.store_field("delete_all_messages", delete_all_messages_);
    s.store_field("report_spam", report_spam_);
    s.store_class_end();
  }
}

checkAuthenticationBotToken::checkAuthenticationBotToken()
  : token_()
{}

checkAuthenticationBotToken::checkAuthenticationBotToken(string const &token_)
  : token_(token_)
{}

const std::int32_t checkAuthenticationBotToken::ID;

void checkAuthenticationBotToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationBotToken");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

checkAuthenticationEmailCode::checkAuthenticationEmailCode()
  : code_()
{}

checkAuthenticationEmailCode::checkAuthenticationEmailCode(object_ptr<EmailAddressAuthentication> &&code_)
  : code_(std::move(code_))
{}

const std::int32_t checkAuthenticationEmailCode::ID;

void checkAuthenticationEmailCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationEmailCode");
    s.store_object_field("code", static_cast<const BaseObject *>(code_.get()));
    s.store_class_end();
  }
}

checkBotUsername::checkBotUsername()
  : username_()
{}

checkBotUsername::checkBotUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t checkBotUsername::ID;

void checkBotUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkBotUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

checkRecoveryEmailAddressCode::checkRecoveryEmailAddressCode()
  : code_()
{}

checkRecoveryEmailAddressCode::checkRecoveryEmailAddressCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkRecoveryEmailAddressCode::ID;

void checkRecoveryEmailAddressCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkRecoveryEmailAddressCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

clearAutosaveSettingsExceptions::clearAutosaveSettingsExceptions() {
}

const std::int32_t clearAutosaveSettingsExceptions::ID;

void clearAutosaveSettingsExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearAutosaveSettingsExceptions");
    s.store_class_end();
  }
}

closeChat::closeChat()
  : chat_id_()
{}

closeChat::closeChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t closeChat::ID;

void closeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

confirmSession::confirmSession()
  : session_id_()
{}

confirmSession::confirmSession(int64 session_id_)
  : session_id_(session_id_)
{}

const std::int32_t confirmSession::ID;

void confirmSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "confirmSession");
    s.store_field("session_id", session_id_);
    s.store_class_end();
  }
}

connectAffiliateProgram::connectAffiliateProgram()
  : affiliate_()
  , bot_user_id_()
{}

connectAffiliateProgram::connectAffiliateProgram(object_ptr<AffiliateType> &&affiliate_, int53 bot_user_id_)
  : affiliate_(std::move(affiliate_))
  , bot_user_id_(bot_user_id_)
{}

const std::int32_t connectAffiliateProgram::ID;

void connectAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectAffiliateProgram");
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

createBot::createBot()
  : manager_bot_user_id_()
  , name_()
  , username_()
  , via_link_()
{}

createBot::createBot(int53 manager_bot_user_id_, string const &name_, string const &username_, bool via_link_)
  : manager_bot_user_id_(manager_bot_user_id_)
  , name_(name_)
  , username_(username_)
  , via_link_(via_link_)
{}

const std::int32_t createBot::ID;

void createBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createBot");
    s.store_field("manager_bot_user_id", manager_bot_user_id_);
    s.store_field("name", name_);
    s.store_field("username", username_);
    s.store_field("via_link", via_link_);
    s.store_class_end();
  }
}

createChatSubscriptionInviteLink::createChatSubscriptionInviteLink()
  : chat_id_()
  , name_()
  , subscription_pricing_()
{}

createChatSubscriptionInviteLink::createChatSubscriptionInviteLink(int53 chat_id_, string const &name_, object_ptr<starSubscriptionPricing> &&subscription_pricing_)
  : chat_id_(chat_id_)
  , name_(name_)
  , subscription_pricing_(std::move(subscription_pricing_))
{}

const std::int32_t createChatSubscriptionInviteLink::ID;

void createChatSubscriptionInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createChatSubscriptionInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("name", name_);
    s.store_object_field("subscription_pricing", static_cast<const BaseObject *>(subscription_pricing_.get()));
    s.store_class_end();
  }
}

createSupergroupChat::createSupergroupChat()
  : supergroup_id_()
  , force_()
{}

createSupergroupChat::createSupergroupChat(int53 supergroup_id_, bool force_)
  : supergroup_id_(supergroup_id_)
  , force_(force_)
{}

const std::int32_t createSupergroupChat::ID;

void createSupergroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createSupergroupChat");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("force", force_);
    s.store_class_end();
  }
}

deleteChatHistory::deleteChatHistory()
  : chat_id_()
  , remove_from_chat_list_()
  , revoke_()
{}

deleteChatHistory::deleteChatHistory(int53 chat_id_, bool remove_from_chat_list_, bool revoke_)
  : chat_id_(chat_id_)
  , remove_from_chat_list_(remove_from_chat_list_)
  , revoke_(revoke_)
{}

const std::int32_t deleteChatHistory::ID;

void deleteChatHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("remove_from_chat_list", remove_from_chat_list_);
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

deleteGiftCollection::deleteGiftCollection()
  : owner_id_()
  , collection_id_()
{}

deleteGiftCollection::deleteGiftCollection(object_ptr<MessageSender> &&owner_id_, int32 collection_id_)
  : owner_id_(std::move(owner_id_))
  , collection_id_(collection_id_)
{}

const std::int32_t deleteGiftCollection::ID;

void deleteGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteGiftCollection");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("collection_id", collection_id_);
    s.store_class_end();
  }
}

deleteQuickReplyShortcut::deleteQuickReplyShortcut()
  : shortcut_id_()
{}

deleteQuickReplyShortcut::deleteQuickReplyShortcut(int32 shortcut_id_)
  : shortcut_id_(shortcut_id_)
{}

const std::int32_t deleteQuickReplyShortcut::ID;

void deleteQuickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteQuickReplyShortcut");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_class_end();
  }
}

disconnectAffiliateProgram::disconnectAffiliateProgram()
  : affiliate_()
  , url_()
{}

disconnectAffiliateProgram::disconnectAffiliateProgram(object_ptr<AffiliateType> &&affiliate_, string const &url_)
  : affiliate_(std::move(affiliate_))
  , url_(url_)
{}

const std::int32_t disconnectAffiliateProgram::ID;

void disconnectAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disconnectAffiliateProgram");
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_field("url", url_);
    s.store_class_end();
  }
}

downloadFile::downloadFile()
  : file_id_()
  , priority_()
  , offset_()
  , limit_()
  , synchronous_()
{}

downloadFile::downloadFile(int32 file_id_, int32 priority_, int53 offset_, int53 limit_, bool synchronous_)
  : file_id_(file_id_)
  , priority_(priority_)
  , offset_(offset_)
  , limit_(limit_)
  , synchronous_(synchronous_)
{}

const std::int32_t downloadFile::ID;

void downloadFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "downloadFile");
    s.store_field("file_id", file_id_);
    s.store_field("priority", priority_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("synchronous", synchronous_);
    s.store_class_end();
  }
}

editChatFolder::editChatFolder()
  : chat_folder_id_()
  , folder_()
{}

editChatFolder::editChatFolder(int32 chat_folder_id_, object_ptr<chatFolder> &&folder_)
  : chat_folder_id_(chat_folder_id_)
  , folder_(std::move(folder_))
{}

const std::int32_t editChatFolder::ID;

void editChatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editChatFolder");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_object_field("folder", static_cast<const BaseObject *>(folder_.get()));
    s.store_class_end();
  }
}

editMessageLiveLocation::editMessageLiveLocation()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , location_()
  , live_period_()
  , heading_()
  , proximity_alert_radius_()
{}

editMessageLiveLocation::editMessageLiveLocation(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<location> &&location_, int32 live_period_, int32 heading_, int32 proximity_alert_radius_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , location_(std::move(location_))
  , live_period_(live_period_)
  , heading_(heading_)
  , proximity_alert_radius_(proximity_alert_radius_)
{}

const std::int32_t editMessageLiveLocation::ID;

void editMessageLiveLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageLiveLocation");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("live_period", live_period_);
    s.store_field("heading", heading_);
    s.store_field("proximity_alert_radius", proximity_alert_radius_);
    s.store_class_end();
  }
}

editProxy::editProxy()
  : proxy_id_()
  , proxy_()
  , enable_()
{}

editProxy::editProxy(int32 proxy_id_, object_ptr<proxy> &&proxy_, bool enable_)
  : proxy_id_(proxy_id_)
  , proxy_(std::move(proxy_))
  , enable_(enable_)
{}

const std::int32_t editProxy::ID;

void editProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editProxy");
    s.store_field("proxy_id", proxy_id_);
    s.store_object_field("proxy", static_cast<const BaseObject *>(proxy_.get()));
    s.store_field("enable", enable_);
    s.store_class_end();
  }
}

editQuickReplyMessage::editQuickReplyMessage()
  : shortcut_id_()
  , message_id_()
  , input_message_content_()
{}

editQuickReplyMessage::editQuickReplyMessage(int32 shortcut_id_, int53 message_id_, object_ptr<InputMessageContent> &&input_message_content_)
  : shortcut_id_(shortcut_id_)
  , message_id_(message_id_)
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editQuickReplyMessage::ID;

void editQuickReplyMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editQuickReplyMessage");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editStoryCover::editStoryCover()
  : story_poster_chat_id_()
  , story_id_()
  , cover_frame_timestamp_()
{}

editStoryCover::editStoryCover(int53 story_poster_chat_id_, int32 story_id_, double cover_frame_timestamp_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , cover_frame_timestamp_(cover_frame_timestamp_)
{}

const std::int32_t editStoryCover::ID;

void editStoryCover::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editStoryCover");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_field("cover_frame_timestamp", cover_frame_timestamp_);
    s.store_class_end();
  }
}

getAuthorizationState::getAuthorizationState() {
}

const std::int32_t getAuthorizationState::ID;

void getAuthorizationState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAuthorizationState");
    s.store_class_end();
  }
}

getBusinessAccountStarAmount::getBusinessAccountStarAmount()
  : business_connection_id_()
{}

getBusinessAccountStarAmount::getBusinessAccountStarAmount(string const &business_connection_id_)
  : business_connection_id_(business_connection_id_)
{}

const std::int32_t getBusinessAccountStarAmount::ID;

void getBusinessAccountStarAmount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBusinessAccountStarAmount");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_class_end();
  }
}

getBusinessChatLinks::getBusinessChatLinks() {
}

const std::int32_t getBusinessChatLinks::ID;

void getBusinessChatLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBusinessChatLinks");
    s.store_class_end();
  }
}

getCallbackQueryAnswer::getCallbackQueryAnswer()
  : chat_id_()
  , message_id_()
  , payload_()
{}

getCallbackQueryAnswer::getCallbackQueryAnswer(int53 chat_id_, int53 message_id_, object_ptr<CallbackQueryPayload> &&payload_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , payload_(std::move(payload_))
{}

const std::int32_t getCallbackQueryAnswer::ID;

void getCallbackQueryAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCallbackQueryAnswer");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("payload", static_cast<const BaseObject *>(payload_.get()));
    s.store_class_end();
  }
}

getChatFolder::getChatFolder()
  : chat_folder_id_()
{}

getChatFolder::getChatFolder(int32 chat_folder_id_)
  : chat_folder_id_(chat_folder_id_)
{}

const std::int32_t getChatFolder::ID;

void getChatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFolder");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_class_end();
  }
}

getChatFolderChatCount::getChatFolderChatCount()
  : folder_()
{}

getChatFolderChatCount::getChatFolderChatCount(object_ptr<chatFolder> &&folder_)
  : folder_(std::move(folder_))
{}

const std::int32_t getChatFolderChatCount::ID;

void getChatFolderChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFolderChatCount");
    s.store_object_field("folder", static_cast<const BaseObject *>(folder_.get()));
    s.store_class_end();
  }
}

getCountryCode::getCountryCode() {
}

const std::int32_t getCountryCode::ID;

void getCountryCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCountryCode");
    s.store_class_end();
  }
}

getCountryFlagEmoji::getCountryFlagEmoji()
  : country_code_()
{}

getCountryFlagEmoji::getCountryFlagEmoji(string const &country_code_)
  : country_code_(country_code_)
{}

const std::int32_t getCountryFlagEmoji::ID;

void getCountryFlagEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCountryFlagEmoji");
    s.store_field("country_code", country_code_);
    s.store_class_end();
  }
}

getDefaultMessageAutoDeleteTime::getDefaultMessageAutoDeleteTime() {
}

const std::int32_t getDefaultMessageAutoDeleteTime::ID;

void getDefaultMessageAutoDeleteTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDefaultMessageAutoDeleteTime");
    s.store_class_end();
  }
}

getGiftAuctionState::getGiftAuctionState()
  : auction_id_()
{}

getGiftAuctionState::getGiftAuctionState(string const &auction_id_)
  : auction_id_(auction_id_)
{}

const std::int32_t getGiftAuctionState::ID;

void getGiftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftAuctionState");
    s.store_field("auction_id", auction_id_);
    s.store_class_end();
  }
}

getGroupCallParticipants::getGroupCallParticipants()
  : input_group_call_()
  , limit_()
{}

getGroupCallParticipants::getGroupCallParticipants(object_ptr<InputGroupCall> &&input_group_call_, int32 limit_)
  : input_group_call_(std::move(input_group_call_))
  , limit_(limit_)
{}

const std::int32_t getGroupCallParticipants::ID;

void getGroupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupCallParticipants");
    s.store_object_field("input_group_call", static_cast<const BaseObject *>(input_group_call_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getJsonValue::getJsonValue()
  : json_()
{}

getJsonValue::getJsonValue(string const &json_)
  : json_(json_)
{}

const std::int32_t getJsonValue::ID;

void getJsonValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getJsonValue");
    s.store_field("json", json_);
    s.store_class_end();
  }
}

getLanguagePackString::getLanguagePackString()
  : language_pack_database_path_()
  , localization_target_()
  , language_pack_id_()
  , key_()
{}

getLanguagePackString::getLanguagePackString(string const &language_pack_database_path_, string const &localization_target_, string const &language_pack_id_, string const &key_)
  : language_pack_database_path_(language_pack_database_path_)
  , localization_target_(localization_target_)
  , language_pack_id_(language_pack_id_)
  , key_(key_)
{}

const std::int32_t getLanguagePackString::ID;

void getLanguagePackString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLanguagePackString");
    s.store_field("language_pack_database_path", language_pack_database_path_);
    s.store_field("localization_target", localization_target_);
    s.store_field("language_pack_id", language_pack_id_);
    s.store_field("key", key_);
    s.store_class_end();
  }
}

getLanguagePackStrings::getLanguagePackStrings()
  : language_pack_id_()
  , keys_()
{}

getLanguagePackStrings::getLanguagePackStrings(string const &language_pack_id_, array<string> &&keys_)
  : language_pack_id_(language_pack_id_)
  , keys_(std::move(keys_))
{}

const std::int32_t getLanguagePackStrings::ID;

void getLanguagePackStrings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLanguagePackStrings");
    s.store_field("language_pack_id", language_pack_id_);
    { s.store_vector_begin("keys", keys_.size()); for (const auto &_value : keys_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getLiveStoryAvailableMessageSenders::getLiveStoryAvailableMessageSenders()
  : group_call_id_()
{}

getLiveStoryAvailableMessageSenders::getLiveStoryAvailableMessageSenders(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t getLiveStoryAvailableMessageSenders::ID;

void getLiveStoryAvailableMessageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLiveStoryAvailableMessageSenders");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getLiveStoryRtmpUrl::getLiveStoryRtmpUrl()
  : chat_id_()
{}

getLiveStoryRtmpUrl::getLiveStoryRtmpUrl(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getLiveStoryRtmpUrl::ID;

void getLiveStoryRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLiveStoryRtmpUrl");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getMessageLink::getMessageLink()
  : chat_id_()
  , message_id_()
  , media_timestamp_()
  , checklist_task_id_()
  , poll_option_id_()
  , for_album_()
  , in_message_thread_()
{}

getMessageLink::getMessageLink(int53 chat_id_, int53 message_id_, int32 media_timestamp_, int32 checklist_task_id_, string const &poll_option_id_, bool for_album_, bool in_message_thread_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , media_timestamp_(media_timestamp_)
  , checklist_task_id_(checklist_task_id_)
  , poll_option_id_(poll_option_id_)
  , for_album_(for_album_)
  , in_message_thread_(in_message_thread_)
{}

const std::int32_t getMessageLink::ID;

void getMessageLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("media_timestamp", media_timestamp_);
    s.store_field("checklist_task_id", checklist_task_id_);
    s.store_field("poll_option_id", poll_option_id_);
    s.store_field("for_album", for_album_);
    s.store_field("in_message_thread", in_message_thread_);
    s.store_class_end();
  }
}

getMessageReadDate::getMessageReadDate()
  : chat_id_()
  , message_id_()
{}

getMessageReadDate::getMessageReadDate(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageReadDate::ID;

void getMessageReadDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageReadDate");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getMessageThread::getMessageThread()
  : chat_id_()
  , message_id_()
{}

getMessageThread::getMessageThread(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageThread::ID;

void getMessageThread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageThread");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getOwnedStickerSets::getOwnedStickerSets()
  : offset_sticker_set_id_()
  , limit_()
{}

getOwnedStickerSets::getOwnedStickerSets(int64 offset_sticker_set_id_, int32 limit_)
  : offset_sticker_set_id_(offset_sticker_set_id_)
  , limit_(limit_)
{}

const std::int32_t getOwnedStickerSets::ID;

void getOwnedStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getOwnedStickerSets");
    s.store_field("offset_sticker_set_id", offset_sticker_set_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getPremiumGiftPaymentOptions::getPremiumGiftPaymentOptions() {
}

const std::int32_t getPremiumGiftPaymentOptions::ID;

void getPremiumGiftPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumGiftPaymentOptions");
    s.store_class_end();
  }
}

getRecentInlineBots::getRecentInlineBots() {
}

const std::int32_t getRecentInlineBots::ID;

void getRecentInlineBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentInlineBots");
    s.store_class_end();
  }
}

getRecentlyVisitedTMeUrls::getRecentlyVisitedTMeUrls()
  : referrer_()
{}

getRecentlyVisitedTMeUrls::getRecentlyVisitedTMeUrls(string const &referrer_)
  : referrer_(referrer_)
{}

const std::int32_t getRecentlyVisitedTMeUrls::ID;

void getRecentlyVisitedTMeUrls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentlyVisitedTMeUrls");
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

getScopeNotificationSettings::getScopeNotificationSettings()
  : scope_()
{}

getScopeNotificationSettings::getScopeNotificationSettings(object_ptr<NotificationSettingsScope> &&scope_)
  : scope_(std::move(scope_))
{}

const std::int32_t getScopeNotificationSettings::ID;

void getScopeNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getScopeNotificationSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_class_end();
  }
}

getStoryAlbumStories::getStoryAlbumStories()
  : chat_id_()
  , story_album_id_()
  , offset_()
  , limit_()
{}

getStoryAlbumStories::getStoryAlbumStories(int53 chat_id_, int32 story_album_id_, int32 offset_, int32 limit_)
  : chat_id_(chat_id_)
  , story_album_id_(story_album_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getStoryAlbumStories::ID;

void getStoryAlbumStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStoryAlbumStories");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_album_id", story_album_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getStoryPublicForwards::getStoryPublicForwards()
  : story_poster_chat_id_()
  , story_id_()
  , offset_()
  , limit_()
{}

getStoryPublicForwards::getStoryPublicForwards(int53 story_poster_chat_id_, int32 story_id_, string const &offset_, int32 limit_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getStoryPublicForwards::ID;

void getStoryPublicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStoryPublicForwards");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getSuggestedFileName::getSuggestedFileName()
  : file_id_()
  , directory_()
{}

getSuggestedFileName::getSuggestedFileName(int32 file_id_, string const &directory_)
  : file_id_(file_id_)
  , directory_(directory_)
{}

const std::int32_t getSuggestedFileName::ID;

void getSuggestedFileName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSuggestedFileName");
    s.store_field("file_id", file_id_);
    s.store_field("directory", directory_);
    s.store_class_end();
  }
}

getTextEntities::getTextEntities()
  : text_()
{}

getTextEntities::getTextEntities(string const &text_)
  : text_(text_)
{}

const std::int32_t getTextEntities::ID;

void getTextEntities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTextEntities");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

getUserChatBoosts::getUserChatBoosts()
  : chat_id_()
  , user_id_()
{}

getUserChatBoosts::getUserChatBoosts(int53 chat_id_, int53 user_id_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
{}

const std::int32_t getUserChatBoosts::ID;

void getUserChatBoosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserChatBoosts");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getUserFullInfo::getUserFullInfo()
  : user_id_()
{}

getUserFullInfo::getUserFullInfo(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getUserFullInfo::ID;

void getUserFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserFullInfo");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

increaseGiftAuctionBid::increaseGiftAuctionBid()
  : gift_id_()
  , star_count_()
{}

increaseGiftAuctionBid::increaseGiftAuctionBid(int64 gift_id_, int53 star_count_)
  : gift_id_(gift_id_)
  , star_count_(star_count_)
{}

const std::int32_t increaseGiftAuctionBid::ID;

void increaseGiftAuctionBid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "increaseGiftAuctionBid");
    s.store_field("gift_id", gift_id_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

loadQuickReplyShortcutMessages::loadQuickReplyShortcutMessages()
  : shortcut_id_()
{}

loadQuickReplyShortcutMessages::loadQuickReplyShortcutMessages(int32 shortcut_id_)
  : shortcut_id_(shortcut_id_)
{}

const std::int32_t loadQuickReplyShortcutMessages::ID;

void loadQuickReplyShortcutMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadQuickReplyShortcutMessages");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_class_end();
  }
}

processGiftPurchaseOffer::processGiftPurchaseOffer()
  : message_id_()
  , accept_()
{}

processGiftPurchaseOffer::processGiftPurchaseOffer(int53 message_id_, bool accept_)
  : message_id_(message_id_)
  , accept_(accept_)
{}

const std::int32_t processGiftPurchaseOffer::ID;

void processGiftPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processGiftPurchaseOffer");
    s.store_field("message_id", message_id_);
    s.store_field("accept", accept_);
    s.store_class_end();
  }
}

removeChatActionBar::removeChatActionBar()
  : chat_id_()
{}

removeChatActionBar::removeChatActionBar(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t removeChatActionBar::ID;

void removeChatActionBar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeChatActionBar");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

removeNotificationGroup::removeNotificationGroup()
  : notification_group_id_()
  , max_notification_id_()
{}

removeNotificationGroup::removeNotificationGroup(int32 notification_group_id_, int32 max_notification_id_)
  : notification_group_id_(notification_group_id_)
  , max_notification_id_(max_notification_id_)
{}

const std::int32_t removeNotificationGroup::ID;

void removeNotificationGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeNotificationGroup");
    s.store_field("notification_group_id", notification_group_id_);
    s.store_field("max_notification_id", max_notification_id_);
    s.store_class_end();
  }
}

replaceStickerInSet::replaceStickerInSet()
  : user_id_()
  , name_()
  , old_sticker_()
  , new_sticker_()
{}

replaceStickerInSet::replaceStickerInSet(int53 user_id_, string const &name_, object_ptr<InputFile> &&old_sticker_, object_ptr<inputSticker> &&new_sticker_)
  : user_id_(user_id_)
  , name_(name_)
  , old_sticker_(std::move(old_sticker_))
  , new_sticker_(std::move(new_sticker_))
{}

const std::int32_t replaceStickerInSet::ID;

void replaceStickerInSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replaceStickerInSet");
    s.store_field("user_id", user_id_);
    s.store_field("name", name_);
    s.store_object_field("old_sticker", static_cast<const BaseObject *>(old_sticker_.get()));
    s.store_object_field("new_sticker", static_cast<const BaseObject *>(new_sticker_.get()));
    s.store_class_end();
  }
}

requestAuthenticationPasswordRecovery::requestAuthenticationPasswordRecovery() {
}

const std::int32_t requestAuthenticationPasswordRecovery::ID;

void requestAuthenticationPasswordRecovery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestAuthenticationPasswordRecovery");
    s.store_class_end();
  }
}

resetAllNotificationSettings::resetAllNotificationSettings() {
}

const std::int32_t resetAllNotificationSettings::ID;

void resetAllNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetAllNotificationSettings");
    s.store_class_end();
  }
}

searchChats::searchChats()
  : query_()
  , limit_()
{}

searchChats::searchChats(string const &query_, int32 limit_)
  : query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchChats::ID;

void searchChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChats");
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchGiftsForResale::searchGiftsForResale()
  : gift_id_()
  , order_()
  , for_crafting_()
  , for_stars_()
  , attributes_()
  , offset_()
  , limit_()
{}

searchGiftsForResale::searchGiftsForResale(int64 gift_id_, object_ptr<GiftForResaleOrder> &&order_, bool for_crafting_, bool for_stars_, array<object_ptr<UpgradedGiftAttributeId>> &&attributes_, string const &offset_, int32 limit_)
  : gift_id_(gift_id_)
  , order_(std::move(order_))
  , for_crafting_(for_crafting_)
  , for_stars_(for_stars_)
  , attributes_(std::move(attributes_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchGiftsForResale::ID;

void searchGiftsForResale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchGiftsForResale");
    s.store_field("gift_id", gift_id_);
    s.store_object_field("order", static_cast<const BaseObject *>(order_.get()));
    s.store_field("for_crafting", for_crafting_);
    s.store_field("for_stars", for_stars_);
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

sendMessageViewMetrics::sendMessageViewMetrics()
  : chat_id_()
  , message_id_()
  , time_in_view_ms_()
  , active_time_in_view_ms_()
  , height_to_viewport_ratio_per_mille_()
  , seen_range_ratio_per_mille_()
{}

sendMessageViewMetrics::sendMessageViewMetrics(int53 chat_id_, int53 message_id_, int32 time_in_view_ms_, int32 active_time_in_view_ms_, int32 height_to_viewport_ratio_per_mille_, int32 seen_range_ratio_per_mille_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , time_in_view_ms_(time_in_view_ms_)
  , active_time_in_view_ms_(active_time_in_view_ms_)
  , height_to_viewport_ratio_per_mille_(height_to_viewport_ratio_per_mille_)
  , seen_range_ratio_per_mille_(seen_range_ratio_per_mille_)
{}

const std::int32_t sendMessageViewMetrics::ID;

void sendMessageViewMetrics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageViewMetrics");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("time_in_view_ms", time_in_view_ms_);
    s.store_field("active_time_in_view_ms", active_time_in_view_ms_);
    s.store_field("height_to_viewport_ratio_per_mille", height_to_viewport_ratio_per_mille_);
    s.store_field("seen_range_ratio_per_mille", seen_range_ratio_per_mille_);
    s.store_class_end();
  }
}

sendResoldGift::sendResoldGift()
  : gift_name_()
  , owner_id_()
  , price_()
{}

sendResoldGift::sendResoldGift(string const &gift_name_, object_ptr<MessageSender> &&owner_id_, object_ptr<GiftResalePrice> &&price_)
  : gift_name_(gift_name_)
  , owner_id_(std::move(owner_id_))
  , price_(std::move(price_))
{}

const std::int32_t sendResoldGift::ID;

void sendResoldGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendResoldGift");
    s.store_field("gift_name", gift_name_);
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

setApplicationVerificationToken::setApplicationVerificationToken()
  : verification_id_()
  , token_()
{}

setApplicationVerificationToken::setApplicationVerificationToken(int53 verification_id_, string const &token_)
  : verification_id_(verification_id_)
  , token_(token_)
{}

const std::int32_t setApplicationVerificationToken::ID;

void setApplicationVerificationToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setApplicationVerificationToken");
    s.store_field("verification_id", verification_id_);
    s.store_field("token", token_);
    s.store_class_end();
  }
}

setBusinessMessageIsPinned::setBusinessMessageIsPinned()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , is_pinned_()
{}

setBusinessMessageIsPinned::setBusinessMessageIsPinned(string const &business_connection_id_, int53 chat_id_, int53 message_id_, bool is_pinned_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t setBusinessMessageIsPinned::ID;

void setBusinessMessageIsPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessMessageIsPinned");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

setBusinessOpeningHours::setBusinessOpeningHours()
  : opening_hours_()
{}

setBusinessOpeningHours::setBusinessOpeningHours(object_ptr<businessOpeningHours> &&opening_hours_)
  : opening_hours_(std::move(opening_hours_))
{}

const std::int32_t setBusinessOpeningHours::ID;

void setBusinessOpeningHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessOpeningHours");
    s.store_object_field("opening_hours", static_cast<const BaseObject *>(opening_hours_.get()));
    s.store_class_end();
  }
}

setChatDirectMessagesGroup::setChatDirectMessagesGroup()
  : chat_id_()
  , is_enabled_()
  , paid_message_star_count_()
{}

setChatDirectMessagesGroup::setChatDirectMessagesGroup(int53 chat_id_, bool is_enabled_, int53 paid_message_star_count_)
  : chat_id_(chat_id_)
  , is_enabled_(is_enabled_)
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t setChatDirectMessagesGroup::ID;

void setChatDirectMessagesGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatDirectMessagesGroup");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_enabled", is_enabled_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

setChatMemberTag::setChatMemberTag()
  : chat_id_()
  , user_id_()
  , tag_()
{}

setChatMemberTag::setChatMemberTag(int53 chat_id_, int53 user_id_, string const &tag_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
  , tag_(tag_)
{}

const std::int32_t setChatMemberTag::ID;

void setChatMemberTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatMemberTag");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("tag", tag_);
    s.store_class_end();
  }
}

setChatMessageAutoDeleteTime::setChatMessageAutoDeleteTime()
  : chat_id_()
  , message_auto_delete_time_()
{}

setChatMessageAutoDeleteTime::setChatMessageAutoDeleteTime(int53 chat_id_, int32 message_auto_delete_time_)
  : chat_id_(chat_id_)
  , message_auto_delete_time_(message_auto_delete_time_)
{}

const std::int32_t setChatMessageAutoDeleteTime::ID;

void setChatMessageAutoDeleteTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatMessageAutoDeleteTime");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_auto_delete_time", message_auto_delete_time_);
    s.store_class_end();
  }
}

setChatPaidMessageStarCount::setChatPaidMessageStarCount()
  : chat_id_()
  , paid_message_star_count_()
{}

setChatPaidMessageStarCount::setChatPaidMessageStarCount(int53 chat_id_, int53 paid_message_star_count_)
  : chat_id_(chat_id_)
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t setChatPaidMessageStarCount::ID;

void setChatPaidMessageStarCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatPaidMessageStarCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

setCommands::setCommands()
  : scope_()
  , language_code_()
  , commands_()
{}

setCommands::setCommands(object_ptr<BotCommandScope> &&scope_, string const &language_code_, array<object_ptr<botCommand>> &&commands_)
  : scope_(std::move(scope_))
  , language_code_(language_code_)
  , commands_(std::move(commands_))
{}

const std::int32_t setCommands::ID;

void setCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("language_code", language_code_);
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

setGiftResalePrice::setGiftResalePrice()
  : received_gift_id_()
  , price_()
{}

setGiftResalePrice::setGiftResalePrice(string const &received_gift_id_, object_ptr<GiftResalePrice> &&price_)
  : received_gift_id_(received_gift_id_)
  , price_(std::move(price_))
{}

const std::int32_t setGiftResalePrice::ID;

void setGiftResalePrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGiftResalePrice");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

setLiveStoryMessageSender::setLiveStoryMessageSender()
  : group_call_id_()
  , message_sender_id_()
{}

setLiveStoryMessageSender::setLiveStoryMessageSender(int32 group_call_id_, object_ptr<MessageSender> &&message_sender_id_)
  : group_call_id_(group_call_id_)
  , message_sender_id_(std::move(message_sender_id_))
{}

const std::int32_t setLiveStoryMessageSender::ID;

void setLiveStoryMessageSender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLiveStoryMessageSender");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    s.store_class_end();
  }
}

setNetworkType::setNetworkType()
  : type_()
{}

setNetworkType::setNetworkType(object_ptr<NetworkType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t setNetworkType::ID;

void setNetworkType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setNetworkType");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

setNewChatPrivacySettings::setNewChatPrivacySettings()
  : settings_()
{}

setNewChatPrivacySettings::setNewChatPrivacySettings(object_ptr<newChatPrivacySettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t setNewChatPrivacySettings::ID;

void setNewChatPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setNewChatPrivacySettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setRecoveryEmailAddress::setRecoveryEmailAddress()
  : password_()
  , new_recovery_email_address_()
{}

setRecoveryEmailAddress::setRecoveryEmailAddress(string const &password_, string const &new_recovery_email_address_)
  : password_(password_)
  , new_recovery_email_address_(new_recovery_email_address_)
{}

const std::int32_t setRecoveryEmailAddress::ID;

void setRecoveryEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setRecoveryEmailAddress");
    s.store_field("password", password_);
    s.store_field("new_recovery_email_address", new_recovery_email_address_);
    s.store_class_end();
  }
}

setStoryAlbumName::setStoryAlbumName()
  : chat_id_()
  , story_album_id_()
  , name_()
{}

setStoryAlbumName::setStoryAlbumName(int53 chat_id_, int32 story_album_id_, string const &name_)
  : chat_id_(chat_id_)
  , story_album_id_(story_album_id_)
  , name_(name_)
{}

const std::int32_t setStoryAlbumName::ID;

void setStoryAlbumName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStoryAlbumName");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_album_id", story_album_id_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

setSupergroupStickerSet::setSupergroupStickerSet()
  : supergroup_id_()
  , sticker_set_id_()
{}

setSupergroupStickerSet::setSupergroupStickerSet(int53 supergroup_id_, int64 sticker_set_id_)
  : supergroup_id_(supergroup_id_)
  , sticker_set_id_(sticker_set_id_)
{}

const std::int32_t setSupergroupStickerSet::ID;

void setSupergroupStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSupergroupStickerSet");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("sticker_set_id", sticker_set_id_);
    s.store_class_end();
  }
}

toggleChatViewAsTopics::toggleChatViewAsTopics()
  : chat_id_()
  , view_as_topics_()
{}

toggleChatViewAsTopics::toggleChatViewAsTopics(int53 chat_id_, bool view_as_topics_)
  : chat_id_(chat_id_)
  , view_as_topics_(view_as_topics_)
{}

const std::int32_t toggleChatViewAsTopics::ID;

void toggleChatViewAsTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatViewAsTopics");
    s.store_field("chat_id", chat_id_);
    s.store_field("view_as_topics", view_as_topics_);
    s.store_class_end();
  }
}

translateMessageText::translateMessageText()
  : chat_id_()
  , message_id_()
  , to_language_code_()
  , tone_()
{}

translateMessageText::translateMessageText(int53 chat_id_, int53 message_id_, string const &to_language_code_, string const &tone_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , to_language_code_(to_language_code_)
  , tone_(tone_)
{}

const std::int32_t translateMessageText::ID;

void translateMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "translateMessageText");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("to_language_code", to_language_code_);
    s.store_field("tone", tone_);
    s.store_class_end();
  }
}

unpinAllDirectMessagesChatTopicMessages::unpinAllDirectMessagesChatTopicMessages()
  : chat_id_()
  , topic_id_()
{}

unpinAllDirectMessagesChatTopicMessages::unpinAllDirectMessagesChatTopicMessages(int53 chat_id_, int53 topic_id_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
{}

const std::int32_t unpinAllDirectMessagesChatTopicMessages::ID;

void unpinAllDirectMessagesChatTopicMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unpinAllDirectMessagesChatTopicMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_class_end();
  }
}

unpinAllForumTopicMessages::unpinAllForumTopicMessages()
  : chat_id_()
  , forum_topic_id_()
{}

unpinAllForumTopicMessages::unpinAllForumTopicMessages(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t unpinAllForumTopicMessages::ID;

void unpinAllForumTopicMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unpinAllForumTopicMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

upgradeBasicGroupChatToSupergroupChat::upgradeBasicGroupChatToSupergroupChat()
  : chat_id_()
{}

upgradeBasicGroupChatToSupergroupChat::upgradeBasicGroupChatToSupergroupChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t upgradeBasicGroupChatToSupergroupChat::ID;

void upgradeBasicGroupChatToSupergroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradeBasicGroupChatToSupergroupChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

upgradeGift::upgradeGift()
  : business_connection_id_()
  , received_gift_id_()
  , keep_original_details_()
  , star_count_()
{}

upgradeGift::upgradeGift(string const &business_connection_id_, string const &received_gift_id_, bool keep_original_details_, int53 star_count_)
  : business_connection_id_(business_connection_id_)
  , received_gift_id_(received_gift_id_)
  , keep_original_details_(keep_original_details_)
  , star_count_(star_count_)
{}

const std::int32_t upgradeGift::ID;

void upgradeGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradeGift");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("received_gift_id", received_gift_id_);
    s.store_field("keep_original_details", keep_original_details_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
