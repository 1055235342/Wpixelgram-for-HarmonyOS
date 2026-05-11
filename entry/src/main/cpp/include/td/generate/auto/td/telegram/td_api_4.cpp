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


addedProxies::addedProxies()
  : proxies_()
{}

addedProxies::addedProxies(array<object_ptr<addedProxy>> &&proxies_)
  : proxies_(std::move(proxies_))
{}

const std::int32_t addedProxies::ID;

void addedProxies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addedProxies");
    { s.store_vector_begin("proxies", proxies_.size()); for (const auto &_value : proxies_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

auctionRound::auctionRound()
  : number_()
  , duration_()
  , extend_time_()
  , top_winner_count_()
{}

auctionRound::auctionRound(int32 number_, int32 duration_, int32 extend_time_, int32 top_winner_count_)
  : number_(number_)
  , duration_(duration_)
  , extend_time_(extend_time_)
  , top_winner_count_(top_winner_count_)
{}

const std::int32_t auctionRound::ID;

void auctionRound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auctionRound");
    s.store_field("number", number_);
    s.store_field("duration", duration_);
    s.store_field("extend_time", extend_time_);
    s.store_field("top_winner_count", top_winner_count_);
    s.store_class_end();
  }
}

autoDownloadSettings::autoDownloadSettings()
  : is_auto_download_enabled_()
  , max_photo_file_size_()
  , max_video_file_size_()
  , max_other_file_size_()
  , video_upload_bitrate_()
  , preload_large_videos_()
  , preload_next_audio_()
  , preload_stories_()
  , use_less_data_for_calls_()
{}

autoDownloadSettings::autoDownloadSettings(bool is_auto_download_enabled_, int32 max_photo_file_size_, int53 max_video_file_size_, int53 max_other_file_size_, int32 video_upload_bitrate_, bool preload_large_videos_, bool preload_next_audio_, bool preload_stories_, bool use_less_data_for_calls_)
  : is_auto_download_enabled_(is_auto_download_enabled_)
  , max_photo_file_size_(max_photo_file_size_)
  , max_video_file_size_(max_video_file_size_)
  , max_other_file_size_(max_other_file_size_)
  , video_upload_bitrate_(video_upload_bitrate_)
  , preload_large_videos_(preload_large_videos_)
  , preload_next_audio_(preload_next_audio_)
  , preload_stories_(preload_stories_)
  , use_less_data_for_calls_(use_less_data_for_calls_)
{}

const std::int32_t autoDownloadSettings::ID;

void autoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autoDownloadSettings");
    s.store_field("is_auto_download_enabled", is_auto_download_enabled_);
    s.store_field("max_photo_file_size", max_photo_file_size_);
    s.store_field("max_video_file_size", max_video_file_size_);
    s.store_field("max_other_file_size", max_other_file_size_);
    s.store_field("video_upload_bitrate", video_upload_bitrate_);
    s.store_field("preload_large_videos", preload_large_videos_);
    s.store_field("preload_next_audio", preload_next_audio_);
    s.store_field("preload_stories", preload_stories_);
    s.store_field("use_less_data_for_calls", use_less_data_for_calls_);
    s.store_class_end();
  }
}

basicGroupFullInfo::basicGroupFullInfo()
  : photo_()
  , description_()
  , creator_user_id_()
  , members_()
  , can_hide_members_()
  , can_toggle_aggressive_anti_spam_()
  , invite_link_()
  , bot_commands_()
{}

basicGroupFullInfo::basicGroupFullInfo(object_ptr<chatPhoto> &&photo_, string const &description_, int53 creator_user_id_, array<object_ptr<chatMember>> &&members_, bool can_hide_members_, bool can_toggle_aggressive_anti_spam_, object_ptr<chatInviteLink> &&invite_link_, array<object_ptr<botCommands>> &&bot_commands_)
  : photo_(std::move(photo_))
  , description_(description_)
  , creator_user_id_(creator_user_id_)
  , members_(std::move(members_))
  , can_hide_members_(can_hide_members_)
  , can_toggle_aggressive_anti_spam_(can_toggle_aggressive_anti_spam_)
  , invite_link_(std::move(invite_link_))
  , bot_commands_(std::move(bot_commands_))
{}

const std::int32_t basicGroupFullInfo::ID;

void basicGroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "basicGroupFullInfo");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("description", description_);
    s.store_field("creator_user_id", creator_user_id_);
    { s.store_vector_begin("members", members_.size()); for (const auto &_value : members_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("can_hide_members", can_hide_members_);
    s.store_field("can_toggle_aggressive_anti_spam", can_toggle_aggressive_anti_spam_);
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    { s.store_vector_begin("bot_commands", bot_commands_.size()); for (const auto &_value : bot_commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

birthdate::birthdate()
  : day_()
  , month_()
  , year_()
{}

birthdate::birthdate(int32 day_, int32 month_, int32 year_)
  : day_(day_)
  , month_(month_)
  , year_(year_)
{}

const std::int32_t birthdate::ID;

void birthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "birthdate");
    s.store_field("day", day_);
    s.store_field("month", month_);
    s.store_field("year", year_);
    s.store_class_end();
  }
}

botInfo::botInfo()
  : short_description_()
  , description_()
  , photo_()
  , animation_()
  , manager_bot_user_id_()
  , menu_button_()
  , commands_()
  , privacy_policy_url_()
  , default_group_administrator_rights_()
  , default_channel_administrator_rights_()
  , affiliate_program_()
  , web_app_background_light_color_()
  , web_app_background_dark_color_()
  , web_app_header_light_color_()
  , web_app_header_dark_color_()
  , verification_parameters_()
  , can_get_revenue_statistics_()
  , can_manage_emoji_status_()
  , has_media_previews_()
  , edit_commands_link_()
  , edit_description_link_()
  , edit_description_media_link_()
  , edit_settings_link_()
{}

botInfo::botInfo(string const &short_description_, string const &description_, object_ptr<photo> &&photo_, object_ptr<animation> &&animation_, int53 manager_bot_user_id_, object_ptr<botMenuButton> &&menu_button_, array<object_ptr<botCommand>> &&commands_, string const &privacy_policy_url_, object_ptr<chatAdministratorRights> &&default_group_administrator_rights_, object_ptr<chatAdministratorRights> &&default_channel_administrator_rights_, object_ptr<affiliateProgramInfo> &&affiliate_program_, int32 web_app_background_light_color_, int32 web_app_background_dark_color_, int32 web_app_header_light_color_, int32 web_app_header_dark_color_, object_ptr<botVerificationParameters> &&verification_parameters_, bool can_get_revenue_statistics_, bool can_manage_emoji_status_, bool has_media_previews_, object_ptr<InternalLinkType> &&edit_commands_link_, object_ptr<InternalLinkType> &&edit_description_link_, object_ptr<InternalLinkType> &&edit_description_media_link_, object_ptr<InternalLinkType> &&edit_settings_link_)
  : short_description_(short_description_)
  , description_(description_)
  , photo_(std::move(photo_))
  , animation_(std::move(animation_))
  , manager_bot_user_id_(manager_bot_user_id_)
  , menu_button_(std::move(menu_button_))
  , commands_(std::move(commands_))
  , privacy_policy_url_(privacy_policy_url_)
  , default_group_administrator_rights_(std::move(default_group_administrator_rights_))
  , default_channel_administrator_rights_(std::move(default_channel_administrator_rights_))
  , affiliate_program_(std::move(affiliate_program_))
  , web_app_background_light_color_(web_app_background_light_color_)
  , web_app_background_dark_color_(web_app_background_dark_color_)
  , web_app_header_light_color_(web_app_header_light_color_)
  , web_app_header_dark_color_(web_app_header_dark_color_)
  , verification_parameters_(std::move(verification_parameters_))
  , can_get_revenue_statistics_(can_get_revenue_statistics_)
  , can_manage_emoji_status_(can_manage_emoji_status_)
  , has_media_previews_(has_media_previews_)
  , edit_commands_link_(std::move(edit_commands_link_))
  , edit_description_link_(std::move(edit_description_link_))
  , edit_description_media_link_(std::move(edit_description_media_link_))
  , edit_settings_link_(std::move(edit_settings_link_))
{}

const std::int32_t botInfo::ID;

void botInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInfo");
    s.store_field("short_description", short_description_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_field("manager_bot_user_id", manager_bot_user_id_);
    s.store_object_field("menu_button", static_cast<const BaseObject *>(menu_button_.get()));
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("privacy_policy_url", privacy_policy_url_);
    s.store_object_field("default_group_administrator_rights", static_cast<const BaseObject *>(default_group_administrator_rights_.get()));
    s.store_object_field("default_channel_administrator_rights", static_cast<const BaseObject *>(default_channel_administrator_rights_.get()));
    s.store_object_field("affiliate_program", static_cast<const BaseObject *>(affiliate_program_.get()));
    s.store_field("web_app_background_light_color", web_app_background_light_color_);
    s.store_field("web_app_background_dark_color", web_app_background_dark_color_);
    s.store_field("web_app_header_light_color", web_app_header_light_color_);
    s.store_field("web_app_header_dark_color", web_app_header_dark_color_);
    s.store_object_field("verification_parameters", static_cast<const BaseObject *>(verification_parameters_.get()));
    s.store_field("can_get_revenue_statistics", can_get_revenue_statistics_);
    s.store_field("can_manage_emoji_status", can_manage_emoji_status_);
    s.store_field("has_media_previews", has_media_previews_);
    s.store_object_field("edit_commands_link", static_cast<const BaseObject *>(edit_commands_link_.get()));
    s.store_object_field("edit_description_link", static_cast<const BaseObject *>(edit_description_link_.get()));
    s.store_object_field("edit_description_media_link", static_cast<const BaseObject *>(edit_description_media_link_.get()));
    s.store_object_field("edit_settings_link", static_cast<const BaseObject *>(edit_settings_link_.get()));
    s.store_class_end();
  }
}

businessChatLink::businessChatLink()
  : link_()
  , text_()
  , title_()
  , view_count_()
{}

businessChatLink::businessChatLink(string const &link_, object_ptr<formattedText> &&text_, string const &title_, int32 view_count_)
  : link_(link_)
  , text_(std::move(text_))
  , title_(title_)
  , view_count_(view_count_)
{}

const std::int32_t businessChatLink::ID;

void businessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessChatLink");
    s.store_field("link", link_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("title", title_);
    s.store_field("view_count", view_count_);
    s.store_class_end();
  }
}

businessFeatureLocation::businessFeatureLocation() {
}

const std::int32_t businessFeatureLocation::ID;

void businessFeatureLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureLocation");
    s.store_class_end();
  }
}

businessFeatureOpeningHours::businessFeatureOpeningHours() {
}

const std::int32_t businessFeatureOpeningHours::ID;

void businessFeatureOpeningHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureOpeningHours");
    s.store_class_end();
  }
}

businessFeatureQuickReplies::businessFeatureQuickReplies() {
}

const std::int32_t businessFeatureQuickReplies::ID;

void businessFeatureQuickReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureQuickReplies");
    s.store_class_end();
  }
}

businessFeatureGreetingMessage::businessFeatureGreetingMessage() {
}

const std::int32_t businessFeatureGreetingMessage::ID;

void businessFeatureGreetingMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureGreetingMessage");
    s.store_class_end();
  }
}

businessFeatureAwayMessage::businessFeatureAwayMessage() {
}

const std::int32_t businessFeatureAwayMessage::ID;

void businessFeatureAwayMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureAwayMessage");
    s.store_class_end();
  }
}

businessFeatureAccountLinks::businessFeatureAccountLinks() {
}

const std::int32_t businessFeatureAccountLinks::ID;

void businessFeatureAccountLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureAccountLinks");
    s.store_class_end();
  }
}

businessFeatureStartPage::businessFeatureStartPage() {
}

const std::int32_t businessFeatureStartPage::ID;

void businessFeatureStartPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureStartPage");
    s.store_class_end();
  }
}

businessFeatureBots::businessFeatureBots() {
}

const std::int32_t businessFeatureBots::ID;

void businessFeatureBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureBots");
    s.store_class_end();
  }
}

businessFeatureEmojiStatus::businessFeatureEmojiStatus() {
}

const std::int32_t businessFeatureEmojiStatus::ID;

void businessFeatureEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureEmojiStatus");
    s.store_class_end();
  }
}

businessFeatureChatFolderTags::businessFeatureChatFolderTags() {
}

const std::int32_t businessFeatureChatFolderTags::ID;

void businessFeatureChatFolderTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureChatFolderTags");
    s.store_class_end();
  }
}

businessFeatureUpgradedStories::businessFeatureUpgradedStories() {
}

const std::int32_t businessFeatureUpgradedStories::ID;

void businessFeatureUpgradedStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeatureUpgradedStories");
    s.store_class_end();
  }
}

businessFeaturePromotionAnimation::businessFeaturePromotionAnimation()
  : feature_()
  , animation_()
{}

businessFeaturePromotionAnimation::businessFeaturePromotionAnimation(object_ptr<BusinessFeature> &&feature_, object_ptr<animation> &&animation_)
  : feature_(std::move(feature_))
  , animation_(std::move(animation_))
{}

const std::int32_t businessFeaturePromotionAnimation::ID;

void businessFeaturePromotionAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessFeaturePromotionAnimation");
    s.store_object_field("feature", static_cast<const BaseObject *>(feature_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

businessGreetingMessageSettings::businessGreetingMessageSettings()
  : shortcut_id_()
  , recipients_()
  , inactivity_days_()
{}

businessGreetingMessageSettings::businessGreetingMessageSettings(int32 shortcut_id_, object_ptr<businessRecipients> &&recipients_, int32 inactivity_days_)
  : shortcut_id_(shortcut_id_)
  , recipients_(std::move(recipients_))
  , inactivity_days_(inactivity_days_)
{}

const std::int32_t businessGreetingMessageSettings::ID;

void businessGreetingMessageSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessGreetingMessageSettings");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_field("inactivity_days", inactivity_days_);
    s.store_class_end();
  }
}

call::call()
  : id_()
  , unique_id_()
  , user_id_()
  , is_outgoing_()
  , is_video_()
  , state_()
{}

call::call(int32 id_, int64 unique_id_, int53 user_id_, bool is_outgoing_, bool is_video_, object_ptr<CallState> &&state_)
  : id_(id_)
  , unique_id_(unique_id_)
  , user_id_(user_id_)
  , is_outgoing_(is_outgoing_)
  , is_video_(is_video_)
  , state_(std::move(state_))
{}

const std::int32_t call::ID;

void call::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "call");
    s.store_field("id", id_);
    s.store_field("unique_id", unique_id_);
    s.store_field("user_id", user_id_);
    s.store_field("is_outgoing", is_outgoing_);
    s.store_field("is_video", is_video_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

chatInviteLink::chatInviteLink()
  : invite_link_()
  , name_()
  , creator_user_id_()
  , date_()
  , edit_date_()
  , expiration_date_()
  , subscription_pricing_()
  , member_limit_()
  , member_count_()
  , expired_member_count_()
  , pending_join_request_count_()
  , creates_join_request_()
  , is_primary_()
  , is_revoked_()
{}

chatInviteLink::chatInviteLink(string const &invite_link_, string const &name_, int53 creator_user_id_, int32 date_, int32 edit_date_, int32 expiration_date_, object_ptr<starSubscriptionPricing> &&subscription_pricing_, int32 member_limit_, int32 member_count_, int32 expired_member_count_, int32 pending_join_request_count_, bool creates_join_request_, bool is_primary_, bool is_revoked_)
  : invite_link_(invite_link_)
  , name_(name_)
  , creator_user_id_(creator_user_id_)
  , date_(date_)
  , edit_date_(edit_date_)
  , expiration_date_(expiration_date_)
  , subscription_pricing_(std::move(subscription_pricing_))
  , member_limit_(member_limit_)
  , member_count_(member_count_)
  , expired_member_count_(expired_member_count_)
  , pending_join_request_count_(pending_join_request_count_)
  , creates_join_request_(creates_join_request_)
  , is_primary_(is_primary_)
  , is_revoked_(is_revoked_)
{}

const std::int32_t chatInviteLink::ID;

void chatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_field("name", name_);
    s.store_field("creator_user_id", creator_user_id_);
    s.store_field("date", date_);
    s.store_field("edit_date", edit_date_);
    s.store_field("expiration_date", expiration_date_);
    s.store_object_field("subscription_pricing", static_cast<const BaseObject *>(subscription_pricing_.get()));
    s.store_field("member_limit", member_limit_);
    s.store_field("member_count", member_count_);
    s.store_field("expired_member_count", expired_member_count_);
    s.store_field("pending_join_request_count", pending_join_request_count_);
    s.store_field("creates_join_request", creates_join_request_);
    s.store_field("is_primary", is_primary_);
    s.store_field("is_revoked", is_revoked_);
    s.store_class_end();
  }
}

chatListMain::chatListMain() {
}

const std::int32_t chatListMain::ID;

void chatListMain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatListMain");
    s.store_class_end();
  }
}

chatListArchive::chatListArchive() {
}

const std::int32_t chatListArchive::ID;

void chatListArchive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatListArchive");
    s.store_class_end();
  }
}

chatListFolder::chatListFolder()
  : chat_folder_id_()
{}

chatListFolder::chatListFolder(int32 chat_folder_id_)
  : chat_folder_id_(chat_folder_id_)
{}

const std::int32_t chatListFolder::ID;

void chatListFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatListFolder");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_class_end();
  }
}

chatMessageSender::chatMessageSender()
  : sender_()
  , needs_premium_()
{}

chatMessageSender::chatMessageSender(object_ptr<MessageSender> &&sender_, bool needs_premium_)
  : sender_(std::move(sender_))
  , needs_premium_(needs_premium_)
{}

const std::int32_t chatMessageSender::ID;

void chatMessageSender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMessageSender");
    s.store_object_field("sender", static_cast<const BaseObject *>(sender_.get()));
    s.store_field("needs_premium", needs_premium_);
    s.store_class_end();
  }
}

chatRevenueTransaction::chatRevenueTransaction()
  : cryptocurrency_()
  , cryptocurrency_amount_()
  , type_()
{}

chatRevenueTransaction::chatRevenueTransaction(string const &cryptocurrency_, int64 cryptocurrency_amount_, object_ptr<ChatRevenueTransactionType> &&type_)
  : cryptocurrency_(cryptocurrency_)
  , cryptocurrency_amount_(cryptocurrency_amount_)
  , type_(std::move(type_))
{}

const std::int32_t chatRevenueTransaction::ID;

void chatRevenueTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueTransaction");
    s.store_field("cryptocurrency", cryptocurrency_);
    s.store_field("cryptocurrency_amount", cryptocurrency_amount_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

chatStatisticsSupergroup::chatStatisticsSupergroup()
  : period_()
  , member_count_()
  , message_count_()
  , viewer_count_()
  , sender_count_()
  , member_count_graph_()
  , join_graph_()
  , join_by_source_graph_()
  , language_graph_()
  , message_content_graph_()
  , action_graph_()
  , day_graph_()
  , week_graph_()
  , top_senders_()
  , top_administrators_()
  , top_inviters_()
{}

chatStatisticsSupergroup::chatStatisticsSupergroup(object_ptr<dateRange> &&period_, object_ptr<statisticalValue> &&member_count_, object_ptr<statisticalValue> &&message_count_, object_ptr<statisticalValue> &&viewer_count_, object_ptr<statisticalValue> &&sender_count_, object_ptr<StatisticalGraph> &&member_count_graph_, object_ptr<StatisticalGraph> &&join_graph_, object_ptr<StatisticalGraph> &&join_by_source_graph_, object_ptr<StatisticalGraph> &&language_graph_, object_ptr<StatisticalGraph> &&message_content_graph_, object_ptr<StatisticalGraph> &&action_graph_, object_ptr<StatisticalGraph> &&day_graph_, object_ptr<StatisticalGraph> &&week_graph_, array<object_ptr<chatStatisticsMessageSenderInfo>> &&top_senders_, array<object_ptr<chatStatisticsAdministratorActionsInfo>> &&top_administrators_, array<object_ptr<chatStatisticsInviterInfo>> &&top_inviters_)
  : period_(std::move(period_))
  , member_count_(std::move(member_count_))
  , message_count_(std::move(message_count_))
  , viewer_count_(std::move(viewer_count_))
  , sender_count_(std::move(sender_count_))
  , member_count_graph_(std::move(member_count_graph_))
  , join_graph_(std::move(join_graph_))
  , join_by_source_graph_(std::move(join_by_source_graph_))
  , language_graph_(std::move(language_graph_))
  , message_content_graph_(std::move(message_content_graph_))
  , action_graph_(std::move(action_graph_))
  , day_graph_(std::move(day_graph_))
  , week_graph_(std::move(week_graph_))
  , top_senders_(std::move(top_senders_))
  , top_administrators_(std::move(top_administrators_))
  , top_inviters_(std::move(top_inviters_))
{}

const std::int32_t chatStatisticsSupergroup::ID;

void chatStatisticsSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsSupergroup");
    s.store_object_field("period", static_cast<const BaseObject *>(period_.get()));
    s.store_object_field("member_count", static_cast<const BaseObject *>(member_count_.get()));
    s.store_object_field("message_count", static_cast<const BaseObject *>(message_count_.get()));
    s.store_object_field("viewer_count", static_cast<const BaseObject *>(viewer_count_.get()));
    s.store_object_field("sender_count", static_cast<const BaseObject *>(sender_count_.get()));
    s.store_object_field("member_count_graph", static_cast<const BaseObject *>(member_count_graph_.get()));
    s.store_object_field("join_graph", static_cast<const BaseObject *>(join_graph_.get()));
    s.store_object_field("join_by_source_graph", static_cast<const BaseObject *>(join_by_source_graph_.get()));
    s.store_object_field("language_graph", static_cast<const BaseObject *>(language_graph_.get()));
    s.store_object_field("message_content_graph", static_cast<const BaseObject *>(message_content_graph_.get()));
    s.store_object_field("action_graph", static_cast<const BaseObject *>(action_graph_.get()));
    s.store_object_field("day_graph", static_cast<const BaseObject *>(day_graph_.get()));
    s.store_object_field("week_graph", static_cast<const BaseObject *>(week_graph_.get()));
    { s.store_vector_begin("top_senders", top_senders_.size()); for (const auto &_value : top_senders_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_administrators", top_administrators_.size()); for (const auto &_value : top_administrators_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_inviters", top_inviters_.size()); for (const auto &_value : top_inviters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatStatisticsChannel::chatStatisticsChannel()
  : period_()
  , member_count_()
  , mean_message_view_count_()
  , mean_message_share_count_()
  , mean_message_reaction_count_()
  , mean_story_view_count_()
  , mean_story_share_count_()
  , mean_story_reaction_count_()
  , enabled_notifications_percentage_()
  , member_count_graph_()
  , join_graph_()
  , mute_graph_()
  , view_count_by_hour_graph_()
  , view_count_by_source_graph_()
  , join_by_source_graph_()
  , language_graph_()
  , message_interaction_graph_()
  , message_reaction_graph_()
  , story_interaction_graph_()
  , story_reaction_graph_()
  , instant_view_interaction_graph_()
  , recent_interactions_()
{}

chatStatisticsChannel::chatStatisticsChannel(object_ptr<dateRange> &&period_, object_ptr<statisticalValue> &&member_count_, object_ptr<statisticalValue> &&mean_message_view_count_, object_ptr<statisticalValue> &&mean_message_share_count_, object_ptr<statisticalValue> &&mean_message_reaction_count_, object_ptr<statisticalValue> &&mean_story_view_count_, object_ptr<statisticalValue> &&mean_story_share_count_, object_ptr<statisticalValue> &&mean_story_reaction_count_, double enabled_notifications_percentage_, object_ptr<StatisticalGraph> &&member_count_graph_, object_ptr<StatisticalGraph> &&join_graph_, object_ptr<StatisticalGraph> &&mute_graph_, object_ptr<StatisticalGraph> &&view_count_by_hour_graph_, object_ptr<StatisticalGraph> &&view_count_by_source_graph_, object_ptr<StatisticalGraph> &&join_by_source_graph_, object_ptr<StatisticalGraph> &&language_graph_, object_ptr<StatisticalGraph> &&message_interaction_graph_, object_ptr<StatisticalGraph> &&message_reaction_graph_, object_ptr<StatisticalGraph> &&story_interaction_graph_, object_ptr<StatisticalGraph> &&story_reaction_graph_, object_ptr<StatisticalGraph> &&instant_view_interaction_graph_, array<object_ptr<chatStatisticsInteractionInfo>> &&recent_interactions_)
  : period_(std::move(period_))
  , member_count_(std::move(member_count_))
  , mean_message_view_count_(std::move(mean_message_view_count_))
  , mean_message_share_count_(std::move(mean_message_share_count_))
  , mean_message_reaction_count_(std::move(mean_message_reaction_count_))
  , mean_story_view_count_(std::move(mean_story_view_count_))
  , mean_story_share_count_(std::move(mean_story_share_count_))
  , mean_story_reaction_count_(std::move(mean_story_reaction_count_))
  , enabled_notifications_percentage_(enabled_notifications_percentage_)
  , member_count_graph_(std::move(member_count_graph_))
  , join_graph_(std::move(join_graph_))
  , mute_graph_(std::move(mute_graph_))
  , view_count_by_hour_graph_(std::move(view_count_by_hour_graph_))
  , view_count_by_source_graph_(std::move(view_count_by_source_graph_))
  , join_by_source_graph_(std::move(join_by_source_graph_))
  , language_graph_(std::move(language_graph_))
  , message_interaction_graph_(std::move(message_interaction_graph_))
  , message_reaction_graph_(std::move(message_reaction_graph_))
  , story_interaction_graph_(std::move(story_interaction_graph_))
  , story_reaction_graph_(std::move(story_reaction_graph_))
  , instant_view_interaction_graph_(std::move(instant_view_interaction_graph_))
  , recent_interactions_(std::move(recent_interactions_))
{}

const std::int32_t chatStatisticsChannel::ID;

void chatStatisticsChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsChannel");
    s.store_object_field("period", static_cast<const BaseObject *>(period_.get()));
    s.store_object_field("member_count", static_cast<const BaseObject *>(member_count_.get()));
    s.store_object_field("mean_message_view_count", static_cast<const BaseObject *>(mean_message_view_count_.get()));
    s.store_object_field("mean_message_share_count", static_cast<const BaseObject *>(mean_message_share_count_.get()));
    s.store_object_field("mean_message_reaction_count", static_cast<const BaseObject *>(mean_message_reaction_count_.get()));
    s.store_object_field("mean_story_view_count", static_cast<const BaseObject *>(mean_story_view_count_.get()));
    s.store_object_field("mean_story_share_count", static_cast<const BaseObject *>(mean_story_share_count_.get()));
    s.store_object_field("mean_story_reaction_count", static_cast<const BaseObject *>(mean_story_reaction_count_.get()));
    s.store_field("enabled_notifications_percentage", enabled_notifications_percentage_);
    s.store_object_field("member_count_graph", static_cast<const BaseObject *>(member_count_graph_.get()));
    s.store_object_field("join_graph", static_cast<const BaseObject *>(join_graph_.get()));
    s.store_object_field("mute_graph", static_cast<const BaseObject *>(mute_graph_.get()));
    s.store_object_field("view_count_by_hour_graph", static_cast<const BaseObject *>(view_count_by_hour_graph_.get()));
    s.store_object_field("view_count_by_source_graph", static_cast<const BaseObject *>(view_count_by_source_graph_.get()));
    s.store_object_field("join_by_source_graph", static_cast<const BaseObject *>(join_by_source_graph_.get()));
    s.store_object_field("language_graph", static_cast<const BaseObject *>(language_graph_.get()));
    s.store_object_field("message_interaction_graph", static_cast<const BaseObject *>(message_interaction_graph_.get()));
    s.store_object_field("message_reaction_graph", static_cast<const BaseObject *>(message_reaction_graph_.get()));
    s.store_object_field("story_interaction_graph", static_cast<const BaseObject *>(story_interaction_graph_.get()));
    s.store_object_field("story_reaction_graph", static_cast<const BaseObject *>(story_reaction_graph_.get()));
    s.store_object_field("instant_view_interaction_graph", static_cast<const BaseObject *>(instant_view_interaction_graph_.get()));
    { s.store_vector_begin("recent_interactions", recent_interactions_.size()); for (const auto &_value : recent_interactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatStatisticsObjectTypeMessage::chatStatisticsObjectTypeMessage()
  : message_id_()
{}

chatStatisticsObjectTypeMessage::chatStatisticsObjectTypeMessage(int53 message_id_)
  : message_id_(message_id_)
{}

const std::int32_t chatStatisticsObjectTypeMessage::ID;

void chatStatisticsObjectTypeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsObjectTypeMessage");
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

chatStatisticsObjectTypeStory::chatStatisticsObjectTypeStory()
  : story_id_()
{}

chatStatisticsObjectTypeStory::chatStatisticsObjectTypeStory(int32 story_id_)
  : story_id_(story_id_)
{}

const std::int32_t chatStatisticsObjectTypeStory::ID;

void chatStatisticsObjectTypeStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsObjectTypeStory");
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

checklist::checklist()
  : title_()
  , tasks_()
  , others_can_add_tasks_()
  , can_add_tasks_()
  , others_can_mark_tasks_as_done_()
  , can_mark_tasks_as_done_()
{}

checklist::checklist(object_ptr<formattedText> &&title_, array<object_ptr<checklistTask>> &&tasks_, bool others_can_add_tasks_, bool can_add_tasks_, bool others_can_mark_tasks_as_done_, bool can_mark_tasks_as_done_)
  : title_(std::move(title_))
  , tasks_(std::move(tasks_))
  , others_can_add_tasks_(others_can_add_tasks_)
  , can_add_tasks_(can_add_tasks_)
  , others_can_mark_tasks_as_done_(others_can_mark_tasks_as_done_)
  , can_mark_tasks_as_done_(can_mark_tasks_as_done_)
{}

const std::int32_t checklist::ID;

void checklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checklist");
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    { s.store_vector_begin("tasks", tasks_.size()); for (const auto &_value : tasks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("others_can_add_tasks", others_can_add_tasks_);
    s.store_field("can_add_tasks", can_add_tasks_);
    s.store_field("others_can_mark_tasks_as_done", others_can_mark_tasks_as_done_);
    s.store_field("can_mark_tasks_as_done", can_mark_tasks_as_done_);
    s.store_class_end();
  }
}

collectibleItemTypeUsername::collectibleItemTypeUsername()
  : username_()
{}

collectibleItemTypeUsername::collectibleItemTypeUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t collectibleItemTypeUsername::ID;

void collectibleItemTypeUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "collectibleItemTypeUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

collectibleItemTypePhoneNumber::collectibleItemTypePhoneNumber()
  : phone_number_()
{}

collectibleItemTypePhoneNumber::collectibleItemTypePhoneNumber(string const &phone_number_)
  : phone_number_(phone_number_)
{}

const std::int32_t collectibleItemTypePhoneNumber::ID;

void collectibleItemTypePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "collectibleItemTypePhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

connectedWebsite::connectedWebsite()
  : id_()
  , domain_name_()
  , bot_user_id_()
  , browser_()
  , platform_()
  , log_in_date_()
  , last_active_date_()
  , ip_address_()
  , location_()
{}

connectedWebsite::connectedWebsite(int64 id_, string const &domain_name_, int53 bot_user_id_, string const &browser_, string const &platform_, int32 log_in_date_, int32 last_active_date_, string const &ip_address_, string const &location_)
  : id_(id_)
  , domain_name_(domain_name_)
  , bot_user_id_(bot_user_id_)
  , browser_(browser_)
  , platform_(platform_)
  , log_in_date_(log_in_date_)
  , last_active_date_(last_active_date_)
  , ip_address_(ip_address_)
  , location_(location_)
{}

const std::int32_t connectedWebsite::ID;

void connectedWebsite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedWebsite");
    s.store_field("id", id_);
    s.store_field("domain_name", domain_name_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("browser", browser_);
    s.store_field("platform", platform_);
    s.store_field("log_in_date", log_in_date_);
    s.store_field("last_active_date", last_active_date_);
    s.store_field("ip_address", ip_address_);
    s.store_field("location", location_);
    s.store_class_end();
  }
}

connectedWebsites::connectedWebsites()
  : websites_()
{}

connectedWebsites::connectedWebsites(array<object_ptr<connectedWebsite>> &&websites_)
  : websites_(std::move(websites_))
{}

const std::int32_t connectedWebsites::ID;

void connectedWebsites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedWebsites");
    { s.store_vector_begin("websites", websites_.size()); for (const auto &_value : websites_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

currentWeather::currentWeather()
  : temperature_()
  , emoji_()
{}

currentWeather::currentWeather(double temperature_, string const &emoji_)
  : temperature_(temperature_)
  , emoji_(emoji_)
{}

const std::int32_t currentWeather::ID;

void currentWeather::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "currentWeather");
    s.store_field("temperature", temperature_);
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

diffEntity::diffEntity()
  : offset_()
  , length_()
  , type_()
{}

diffEntity::diffEntity(int32 offset_, int32 length_, object_ptr<DiffEntityType> &&type_)
  : offset_(offset_)
  , length_(length_)
  , type_(std::move(type_))
{}

const std::int32_t diffEntity::ID;

void diffEntity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diffEntity");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

diffText::diffText()
  : text_()
  , entities_()
{}

diffText::diffText(string const &text_, array<object_ptr<diffEntity>> &&entities_)
  : text_(text_)
  , entities_(std::move(entities_))
{}

const std::int32_t diffText::ID;

void diffText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diffText");
    s.store_field("text", text_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

document::document()
  : file_name_()
  , mime_type_()
  , minithumbnail_()
  , thumbnail_()
  , document_()
{}

document::document(string const &file_name_, string const &mime_type_, object_ptr<minithumbnail> &&minithumbnail_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&document_)
  : file_name_(file_name_)
  , mime_type_(mime_type_)
  , minithumbnail_(std::move(minithumbnail_))
  , thumbnail_(std::move(thumbnail_))
  , document_(std::move(document_))
{}

const std::int32_t document::ID;

void document::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "document");
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_class_end();
  }
}

emojiCategory::emojiCategory()
  : name_()
  , icon_()
  , source_()
  , is_greeting_()
{}

emojiCategory::emojiCategory(string const &name_, object_ptr<sticker> &&icon_, object_ptr<EmojiCategorySource> &&source_, bool is_greeting_)
  : name_(name_)
  , icon_(std::move(icon_))
  , source_(std::move(source_))
  , is_greeting_(is_greeting_)
{}

const std::int32_t emojiCategory::ID;

void emojiCategory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategory");
    s.store_field("name", name_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("is_greeting", is_greeting_);
    s.store_class_end();
  }
}

emojiKeyword::emojiKeyword()
  : emoji_()
  , keyword_()
{}

emojiKeyword::emojiKeyword(string const &emoji_, string const &keyword_)
  : emoji_(emoji_)
  , keyword_(keyword_)
{}

const std::int32_t emojiKeyword::ID;

void emojiKeyword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiKeyword");
    s.store_field("emoji", emoji_);
    s.store_field("keyword", keyword_);
    s.store_class_end();
  }
}

emojiStatus::emojiStatus()
  : type_()
  , expiration_date_()
{}

emojiStatus::emojiStatus(object_ptr<EmojiStatusType> &&type_, int32 expiration_date_)
  : type_(std::move(type_))
  , expiration_date_(expiration_date_)
{}

const std::int32_t emojiStatus::ID;

void emojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatus");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("expiration_date", expiration_date_);
    s.store_class_end();
  }
}

emojiStatusCustomEmojis::emojiStatusCustomEmojis()
  : custom_emoji_ids_()
{}

emojiStatusCustomEmojis::emojiStatusCustomEmojis(array<int64> &&custom_emoji_ids_)
  : custom_emoji_ids_(std::move(custom_emoji_ids_))
{}

const std::int32_t emojiStatusCustomEmojis::ID;

void emojiStatusCustomEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatusCustomEmojis");
    { s.store_vector_begin("custom_emoji_ids", custom_emoji_ids_.size()); for (const auto &_value : custom_emoji_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

factCheck::factCheck()
  : text_()
  , country_code_()
{}

factCheck::factCheck(object_ptr<formattedText> &&text_, string const &country_code_)
  : text_(std::move(text_))
  , country_code_(country_code_)
{}

const std::int32_t factCheck::ID;

void factCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "factCheck");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("country_code", country_code_);
    s.store_class_end();
  }
}

file::file()
  : id_()
  , size_()
  , expected_size_()
  , local_()
  , remote_()
{}

file::file(int32 id_, int53 size_, int53 expected_size_, object_ptr<localFile> &&local_, object_ptr<remoteFile> &&remote_)
  : id_(id_)
  , size_(size_)
  , expected_size_(expected_size_)
  , local_(std::move(local_))
  , remote_(std::move(remote_))
{}

const std::int32_t file::ID;

void file::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "file");
    s.store_field("id", id_);
    s.store_field("size", size_);
    s.store_field("expected_size", expected_size_);
    s.store_object_field("local", static_cast<const BaseObject *>(local_.get()));
    s.store_object_field("remote", static_cast<const BaseObject *>(remote_.get()));
    s.store_class_end();
  }
}

formattedText::formattedText()
  : text_()
  , entities_()
{}

formattedText::formattedText(string const &text_, array<object_ptr<textEntity>> &&entities_)
  : text_(text_)
  , entities_(std::move(entities_))
{}

const std::int32_t formattedText::ID;

void formattedText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "formattedText");
    s.store_field("text", text_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

giftAuctionAcquiredGifts::giftAuctionAcquiredGifts()
  : gifts_()
{}

giftAuctionAcquiredGifts::giftAuctionAcquiredGifts(array<object_ptr<giftAuctionAcquiredGift>> &&gifts_)
  : gifts_(std::move(gifts_))
{}

const std::int32_t giftAuctionAcquiredGifts::ID;

void giftAuctionAcquiredGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftAuctionAcquiredGifts");
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

giftChatTheme::giftChatTheme()
  : gift_()
  , light_settings_()
  , dark_settings_()
{}

giftChatTheme::giftChatTheme(object_ptr<upgradedGift> &&gift_, object_ptr<themeSettings> &&light_settings_, object_ptr<themeSettings> &&dark_settings_)
  : gift_(std::move(gift_))
  , light_settings_(std::move(light_settings_))
  , dark_settings_(std::move(dark_settings_))
{}

const std::int32_t giftChatTheme::ID;

void giftChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftChatTheme");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("light_settings", static_cast<const BaseObject *>(light_settings_.get()));
    s.store_object_field("dark_settings", static_cast<const BaseObject *>(dark_settings_.get()));
    s.store_class_end();
  }
}

giftForResale::giftForResale()
  : gift_()
  , received_gift_id_()
{}

giftForResale::giftForResale(object_ptr<upgradedGift> &&gift_, string const &received_gift_id_)
  : gift_(std::move(gift_))
  , received_gift_id_(received_gift_id_)
{}

const std::int32_t giftForResale::ID;

void giftForResale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftForResale");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("received_gift_id", received_gift_id_);
    s.store_class_end();
  }
}

giftForResaleOrderPrice::giftForResaleOrderPrice() {
}

const std::int32_t giftForResaleOrderPrice::ID;

void giftForResaleOrderPrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftForResaleOrderPrice");
    s.store_class_end();
  }
}

giftForResaleOrderPriceChangeDate::giftForResaleOrderPriceChangeDate() {
}

const std::int32_t giftForResaleOrderPriceChangeDate::ID;

void giftForResaleOrderPriceChangeDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftForResaleOrderPriceChangeDate");
    s.store_class_end();
  }
}

giftForResaleOrderNumber::giftForResaleOrderNumber() {
}

const std::int32_t giftForResaleOrderNumber::ID;

void giftForResaleOrderNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftForResaleOrderNumber");
    s.store_class_end();
  }
}

giftPurchaseLimits::giftPurchaseLimits()
  : total_count_()
  , remaining_count_()
{}

giftPurchaseLimits::giftPurchaseLimits(int32 total_count_, int32 remaining_count_)
  : total_count_(total_count_)
  , remaining_count_(remaining_count_)
{}

const std::int32_t giftPurchaseLimits::ID;

void giftPurchaseLimits::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftPurchaseLimits");
    s.store_field("total_count", total_count_);
    s.store_field("remaining_count", remaining_count_);
    s.store_class_end();
  }
}

giftResaleParameters::giftResaleParameters()
  : star_count_()
  , toncoin_cent_count_()
  , toncoin_only_()
{}

giftResaleParameters::giftResaleParameters(int53 star_count_, int53 toncoin_cent_count_, bool toncoin_only_)
  : star_count_(star_count_)
  , toncoin_cent_count_(toncoin_cent_count_)
  , toncoin_only_(toncoin_only_)
{}

const std::int32_t giftResaleParameters::ID;

void giftResaleParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftResaleParameters");
    s.store_field("star_count", star_count_);
    s.store_field("toncoin_cent_count", toncoin_cent_count_);
    s.store_field("toncoin_only", toncoin_only_);
    s.store_class_end();
  }
}

inputChecklistTask::inputChecklistTask()
  : id_()
  , text_()
{}

inputChecklistTask::inputChecklistTask(int32 id_, object_ptr<formattedText> &&text_)
  : id_(id_)
  , text_(std::move(text_))
{}

const std::int32_t inputChecklistTask::ID;

void inputChecklistTask::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChecklistTask");
    s.store_field("id", id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

inputInvoiceMessage::inputInvoiceMessage()
  : chat_id_()
  , message_id_()
{}

inputInvoiceMessage::inputInvoiceMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t inputInvoiceMessage::ID;

void inputInvoiceMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

inputInvoiceName::inputInvoiceName()
  : name_()
{}

inputInvoiceName::inputInvoiceName(string const &name_)
  : name_(name_)
{}

const std::int32_t inputInvoiceName::ID;

void inputInvoiceName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceName");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

inputInvoiceTelegram::inputInvoiceTelegram()
  : purpose_()
{}

inputInvoiceTelegram::inputInvoiceTelegram(object_ptr<TelegramPaymentPurpose> &&purpose_)
  : purpose_(std::move(purpose_))
{}

const std::int32_t inputInvoiceTelegram::ID;

void inputInvoiceTelegram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceTelegram");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

inputPassportElementErrorSourceUnspecified::inputPassportElementErrorSourceUnspecified()
  : element_hash_()
{}

inputPassportElementErrorSourceUnspecified::inputPassportElementErrorSourceUnspecified(bytes const &element_hash_)
  : element_hash_(std::move(element_hash_))
{}

const std::int32_t inputPassportElementErrorSourceUnspecified::ID;

void inputPassportElementErrorSourceUnspecified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceUnspecified");
    s.store_bytes_field("element_hash", element_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceDataField::inputPassportElementErrorSourceDataField()
  : field_name_()
  , data_hash_()
{}

inputPassportElementErrorSourceDataField::inputPassportElementErrorSourceDataField(string const &field_name_, bytes const &data_hash_)
  : field_name_(field_name_)
  , data_hash_(std::move(data_hash_))
{}

const std::int32_t inputPassportElementErrorSourceDataField::ID;

void inputPassportElementErrorSourceDataField::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceDataField");
    s.store_field("field_name", field_name_);
    s.store_bytes_field("data_hash", data_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceFrontSide::inputPassportElementErrorSourceFrontSide()
  : file_hash_()
{}

inputPassportElementErrorSourceFrontSide::inputPassportElementErrorSourceFrontSide(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceFrontSide::ID;

void inputPassportElementErrorSourceFrontSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceFrontSide");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceReverseSide::inputPassportElementErrorSourceReverseSide()
  : file_hash_()
{}

inputPassportElementErrorSourceReverseSide::inputPassportElementErrorSourceReverseSide(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceReverseSide::ID;

void inputPassportElementErrorSourceReverseSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceReverseSide");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceSelfie::inputPassportElementErrorSourceSelfie()
  : file_hash_()
{}

inputPassportElementErrorSourceSelfie::inputPassportElementErrorSourceSelfie(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceSelfie::ID;

void inputPassportElementErrorSourceSelfie::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceSelfie");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceTranslationFile::inputPassportElementErrorSourceTranslationFile()
  : file_hash_()
{}

inputPassportElementErrorSourceTranslationFile::inputPassportElementErrorSourceTranslationFile(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceTranslationFile::ID;

void inputPassportElementErrorSourceTranslationFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceTranslationFile");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceTranslationFiles::inputPassportElementErrorSourceTranslationFiles()
  : file_hashes_()
{}

inputPassportElementErrorSourceTranslationFiles::inputPassportElementErrorSourceTranslationFiles(array<bytes> &&file_hashes_)
  : file_hashes_(std::move(file_hashes_))
{}

const std::int32_t inputPassportElementErrorSourceTranslationFiles::ID;

void inputPassportElementErrorSourceTranslationFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceTranslationFiles");
    { s.store_vector_begin("file_hashes", file_hashes_.size()); for (const auto &_value : file_hashes_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPassportElementErrorSourceFile::inputPassportElementErrorSourceFile()
  : file_hash_()
{}

inputPassportElementErrorSourceFile::inputPassportElementErrorSourceFile(bytes const &file_hash_)
  : file_hash_(std::move(file_hash_))
{}

const std::int32_t inputPassportElementErrorSourceFile::ID;

void inputPassportElementErrorSourceFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceFile");
    s.store_bytes_field("file_hash", file_hash_);
    s.store_class_end();
  }
}

inputPassportElementErrorSourceFiles::inputPassportElementErrorSourceFiles()
  : file_hashes_()
{}

inputPassportElementErrorSourceFiles::inputPassportElementErrorSourceFiles(array<bytes> &&file_hashes_)
  : file_hashes_(std::move(file_hashes_))
{}

const std::int32_t inputPassportElementErrorSourceFiles::ID;

void inputPassportElementErrorSourceFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementErrorSourceFiles");
    { s.store_vector_begin("file_hashes", file_hashes_.size()); for (const auto &_value : file_hashes_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPollOption::inputPollOption()
  : text_()
{}

inputPollOption::inputPollOption(object_ptr<formattedText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t inputPollOption::ID;

void inputPollOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollOption");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

inputPollTypeRegular::inputPollTypeRegular()
  : allow_adding_options_()
{}

inputPollTypeRegular::inputPollTypeRegular(bool allow_adding_options_)
  : allow_adding_options_(allow_adding_options_)
{}

const std::int32_t inputPollTypeRegular::ID;

void inputPollTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollTypeRegular");
    s.store_field("allow_adding_options", allow_adding_options_);
    s.store_class_end();
  }
}

inputPollTypeQuiz::inputPollTypeQuiz()
  : correct_option_ids_()
  , explanation_()
{}

inputPollTypeQuiz::inputPollTypeQuiz(array<int32> &&correct_option_ids_, object_ptr<formattedText> &&explanation_)
  : correct_option_ids_(std::move(correct_option_ids_))
  , explanation_(std::move(explanation_))
{}

const std::int32_t inputPollTypeQuiz::ID;

void inputPollTypeQuiz::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollTypeQuiz");
    { s.store_vector_begin("correct_option_ids", correct_option_ids_.size()); for (const auto &_value : correct_option_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("explanation", static_cast<const BaseObject *>(explanation_.get()));
    s.store_class_end();
  }
}

inputStoryAreas::inputStoryAreas()
  : areas_()
{}

inputStoryAreas::inputStoryAreas(array<object_ptr<inputStoryArea>> &&areas_)
  : areas_(std::move(areas_))
{}

const std::int32_t inputStoryAreas::ID;

void inputStoryAreas::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreas");
    { s.store_vector_begin("areas", areas_.size()); for (const auto &_value : areas_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

languagePackStrings::languagePackStrings()
  : strings_()
{}

languagePackStrings::languagePackStrings(array<object_ptr<languagePackString>> &&strings_)
  : strings_(std::move(strings_))
{}

const std::int32_t languagePackStrings::ID;

void languagePackStrings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackStrings");
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

linkPreviewTypeAlbum::linkPreviewTypeAlbum()
  : media_()
  , caption_()
{}

linkPreviewTypeAlbum::linkPreviewTypeAlbum(array<object_ptr<LinkPreviewAlbumMedia>> &&media_, string const &caption_)
  : media_(std::move(media_))
  , caption_(caption_)
{}

const std::int32_t linkPreviewTypeAlbum::ID;

void linkPreviewTypeAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeAlbum");
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("caption", caption_);
    s.store_class_end();
  }
}

linkPreviewTypeAnimation::linkPreviewTypeAnimation()
  : animation_()
{}

linkPreviewTypeAnimation::linkPreviewTypeAnimation(object_ptr<animation> &&animation_)
  : animation_(std::move(animation_))
{}

const std::int32_t linkPreviewTypeAnimation::ID;

void linkPreviewTypeAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeApp::linkPreviewTypeApp()
  : photo_()
{}

linkPreviewTypeApp::linkPreviewTypeApp(object_ptr<photo> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypeApp::ID;

void linkPreviewTypeApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeApp");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeArticle::linkPreviewTypeArticle()
  : photo_()
{}

linkPreviewTypeArticle::linkPreviewTypeArticle(object_ptr<photo> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypeArticle::ID;

void linkPreviewTypeArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeArticle");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeAudio::linkPreviewTypeAudio()
  : audio_()
{}

linkPreviewTypeAudio::linkPreviewTypeAudio(object_ptr<audio> &&audio_)
  : audio_(std::move(audio_))
{}

const std::int32_t linkPreviewTypeAudio::ID;

void linkPreviewTypeAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeBackground::linkPreviewTypeBackground()
  : document_()
  , background_type_()
{}

linkPreviewTypeBackground::linkPreviewTypeBackground(object_ptr<document> &&document_, object_ptr<BackgroundType> &&background_type_)
  : document_(std::move(document_))
  , background_type_(std::move(background_type_))
{}

const std::int32_t linkPreviewTypeBackground::ID;

void linkPreviewTypeBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeBackground");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("background_type", static_cast<const BaseObject *>(background_type_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeChannelBoost::linkPreviewTypeChannelBoost()
  : photo_()
{}

linkPreviewTypeChannelBoost::linkPreviewTypeChannelBoost(object_ptr<chatPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypeChannelBoost::ID;

void linkPreviewTypeChannelBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeChannelBoost");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeChat::linkPreviewTypeChat()
  : type_()
  , photo_()
  , creates_join_request_()
{}

linkPreviewTypeChat::linkPreviewTypeChat(object_ptr<InviteLinkChatType> &&type_, object_ptr<chatPhoto> &&photo_, bool creates_join_request_)
  : type_(std::move(type_))
  , photo_(std::move(photo_))
  , creates_join_request_(creates_join_request_)
{}

const std::int32_t linkPreviewTypeChat::ID;

void linkPreviewTypeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeChat");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("creates_join_request", creates_join_request_);
    s.store_class_end();
  }
}

linkPreviewTypeDirectMessagesChat::linkPreviewTypeDirectMessagesChat()
  : photo_()
{}

linkPreviewTypeDirectMessagesChat::linkPreviewTypeDirectMessagesChat(object_ptr<chatPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypeDirectMessagesChat::ID;

void linkPreviewTypeDirectMessagesChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeDirectMessagesChat");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeDocument::linkPreviewTypeDocument()
  : document_()
{}

linkPreviewTypeDocument::linkPreviewTypeDocument(object_ptr<document> &&document_)
  : document_(std::move(document_))
{}

const std::int32_t linkPreviewTypeDocument::ID;

void linkPreviewTypeDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeEmbeddedAnimationPlayer::linkPreviewTypeEmbeddedAnimationPlayer()
  : url_()
  , animation_()
  , thumbnail_()
  , duration_()
  , width_()
  , height_()
{}

linkPreviewTypeEmbeddedAnimationPlayer::linkPreviewTypeEmbeddedAnimationPlayer(string const &url_, object_ptr<animation> &&animation_, object_ptr<photo> &&thumbnail_, int32 duration_, int32 width_, int32 height_)
  : url_(url_)
  , animation_(std::move(animation_))
  , thumbnail_(std::move(thumbnail_))
  , duration_(duration_)
  , width_(width_)
  , height_(height_)
{}

const std::int32_t linkPreviewTypeEmbeddedAnimationPlayer::ID;

void linkPreviewTypeEmbeddedAnimationPlayer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeEmbeddedAnimationPlayer");
    s.store_field("url", url_);
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

linkPreviewTypeEmbeddedAudioPlayer::linkPreviewTypeEmbeddedAudioPlayer()
  : url_()
  , audio_()
  , thumbnail_()
  , duration_()
  , width_()
  , height_()
{}

linkPreviewTypeEmbeddedAudioPlayer::linkPreviewTypeEmbeddedAudioPlayer(string const &url_, object_ptr<audio> &&audio_, object_ptr<photo> &&thumbnail_, int32 duration_, int32 width_, int32 height_)
  : url_(url_)
  , audio_(std::move(audio_))
  , thumbnail_(std::move(thumbnail_))
  , duration_(duration_)
  , width_(width_)
  , height_(height_)
{}

const std::int32_t linkPreviewTypeEmbeddedAudioPlayer::ID;

void linkPreviewTypeEmbeddedAudioPlayer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeEmbeddedAudioPlayer");
    s.store_field("url", url_);
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

linkPreviewTypeEmbeddedVideoPlayer::linkPreviewTypeEmbeddedVideoPlayer()
  : url_()
  , video_()
  , thumbnail_()
  , duration_()
  , width_()
  , height_()
{}

linkPreviewTypeEmbeddedVideoPlayer::linkPreviewTypeEmbeddedVideoPlayer(string const &url_, object_ptr<video> &&video_, object_ptr<photo> &&thumbnail_, int32 duration_, int32 width_, int32 height_)
  : url_(url_)
  , video_(std::move(video_))
  , thumbnail_(std::move(thumbnail_))
  , duration_(duration_)
  , width_(width_)
  , height_(height_)
{}

const std::int32_t linkPreviewTypeEmbeddedVideoPlayer::ID;

void linkPreviewTypeEmbeddedVideoPlayer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeEmbeddedVideoPlayer");
    s.store_field("url", url_);
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

linkPreviewTypeExternalAudio::linkPreviewTypeExternalAudio()
  : url_()
  , mime_type_()
  , duration_()
{}

linkPreviewTypeExternalAudio::linkPreviewTypeExternalAudio(string const &url_, string const &mime_type_, int32 duration_)
  : url_(url_)
  , mime_type_(mime_type_)
  , duration_(duration_)
{}

const std::int32_t linkPreviewTypeExternalAudio::ID;

void linkPreviewTypeExternalAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeExternalAudio");
    s.store_field("url", url_);
    s.store_field("mime_type", mime_type_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

linkPreviewTypeExternalVideo::linkPreviewTypeExternalVideo()
  : url_()
  , mime_type_()
  , width_()
  , height_()
  , duration_()
{}

linkPreviewTypeExternalVideo::linkPreviewTypeExternalVideo(string const &url_, string const &mime_type_, int32 width_, int32 height_, int32 duration_)
  : url_(url_)
  , mime_type_(mime_type_)
  , width_(width_)
  , height_(height_)
  , duration_(duration_)
{}

const std::int32_t linkPreviewTypeExternalVideo::ID;

void linkPreviewTypeExternalVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeExternalVideo");
    s.store_field("url", url_);
    s.store_field("mime_type", mime_type_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

linkPreviewTypeGiftAuction::linkPreviewTypeGiftAuction()
  : gift_()
  , auction_end_date_()
{}

linkPreviewTypeGiftAuction::linkPreviewTypeGiftAuction(object_ptr<gift> &&gift_, int32 auction_end_date_)
  : gift_(std::move(gift_))
  , auction_end_date_(auction_end_date_)
{}

const std::int32_t linkPreviewTypeGiftAuction::ID;

void linkPreviewTypeGiftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeGiftAuction");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("auction_end_date", auction_end_date_);
    s.store_class_end();
  }
}

linkPreviewTypeGiftCollection::linkPreviewTypeGiftCollection()
  : icons_()
{}

linkPreviewTypeGiftCollection::linkPreviewTypeGiftCollection(array<object_ptr<sticker>> &&icons_)
  : icons_(std::move(icons_))
{}

const std::int32_t linkPreviewTypeGiftCollection::ID;

void linkPreviewTypeGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeGiftCollection");
    { s.store_vector_begin("icons", icons_.size()); for (const auto &_value : icons_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

linkPreviewTypeGroupCall::linkPreviewTypeGroupCall() {
}

const std::int32_t linkPreviewTypeGroupCall::ID;

void linkPreviewTypeGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeGroupCall");
    s.store_class_end();
  }
}

linkPreviewTypeInvoice::linkPreviewTypeInvoice() {
}

const std::int32_t linkPreviewTypeInvoice::ID;

void linkPreviewTypeInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeInvoice");
    s.store_class_end();
  }
}

linkPreviewTypeLiveStory::linkPreviewTypeLiveStory()
  : story_poster_chat_id_()
  , story_id_()
{}

linkPreviewTypeLiveStory::linkPreviewTypeLiveStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t linkPreviewTypeLiveStory::ID;

void linkPreviewTypeLiveStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeLiveStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

linkPreviewTypeMessage::linkPreviewTypeMessage() {
}

const std::int32_t linkPreviewTypeMessage::ID;

void linkPreviewTypeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeMessage");
    s.store_class_end();
  }
}

linkPreviewTypePhoto::linkPreviewTypePhoto()
  : photo_()
{}

linkPreviewTypePhoto::linkPreviewTypePhoto(object_ptr<photo> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypePhoto::ID;

void linkPreviewTypePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewTypePremiumGiftCode::linkPreviewTypePremiumGiftCode() {
}

const std::int32_t linkPreviewTypePremiumGiftCode::ID;

void linkPreviewTypePremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypePremiumGiftCode");
    s.store_class_end();
  }
}

linkPreviewTypeRequestManagedBot::linkPreviewTypeRequestManagedBot() {
}

const std::int32_t linkPreviewTypeRequestManagedBot::ID;

void linkPreviewTypeRequestManagedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeRequestManagedBot");
    s.store_class_end();
  }
}

linkPreviewTypeShareableChatFolder::linkPreviewTypeShareableChatFolder() {
}

const std::int32_t linkPreviewTypeShareableChatFolder::ID;

void linkPreviewTypeShareableChatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeShareableChatFolder");
    s.store_class_end();
  }
}

linkPreviewTypeSticker::linkPreviewTypeSticker()
  : sticker_()
{}

linkPreviewTypeSticker::linkPreviewTypeSticker(object_ptr<sticker> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t linkPreviewTypeSticker::ID;

void linkPreviewTypeSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeStickerSet::linkPreviewTypeStickerSet()
  : stickers_()
{}

linkPreviewTypeStickerSet::linkPreviewTypeStickerSet(array<object_ptr<sticker>> &&stickers_)
  : stickers_(std::move(stickers_))
{}

const std::int32_t linkPreviewTypeStickerSet::ID;

void linkPreviewTypeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeStickerSet");
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

linkPreviewTypeStory::linkPreviewTypeStory()
  : story_poster_chat_id_()
  , story_id_()
{}

linkPreviewTypeStory::linkPreviewTypeStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t linkPreviewTypeStory::ID;

void linkPreviewTypeStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

linkPreviewTypeStoryAlbum::linkPreviewTypeStoryAlbum()
  : photo_icon_()
  , video_icon_()
{}

linkPreviewTypeStoryAlbum::linkPreviewTypeStoryAlbum(object_ptr<photo> &&photo_icon_, object_ptr<video> &&video_icon_)
  : photo_icon_(std::move(photo_icon_))
  , video_icon_(std::move(video_icon_))
{}

const std::int32_t linkPreviewTypeStoryAlbum::ID;

void linkPreviewTypeStoryAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeStoryAlbum");
    s.store_object_field("photo_icon", static_cast<const BaseObject *>(photo_icon_.get()));
    s.store_object_field("video_icon", static_cast<const BaseObject *>(video_icon_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeSupergroupBoost::linkPreviewTypeSupergroupBoost()
  : photo_()
{}

linkPreviewTypeSupergroupBoost::linkPreviewTypeSupergroupBoost(object_ptr<chatPhoto> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypeSupergroupBoost::ID;

void linkPreviewTypeSupergroupBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeSupergroupBoost");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeTheme::linkPreviewTypeTheme()
  : documents_()
  , settings_()
{}

linkPreviewTypeTheme::linkPreviewTypeTheme(array<object_ptr<document>> &&documents_, object_ptr<themeSettings> &&settings_)
  : documents_(std::move(documents_))
  , settings_(std::move(settings_))
{}

const std::int32_t linkPreviewTypeTheme::ID;

void linkPreviewTypeTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeTheme");
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeUnsupported::linkPreviewTypeUnsupported() {
}

const std::int32_t linkPreviewTypeUnsupported::ID;

void linkPreviewTypeUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeUnsupported");
    s.store_class_end();
  }
}

linkPreviewTypeUpgradedGift::linkPreviewTypeUpgradedGift()
  : gift_()
{}

linkPreviewTypeUpgradedGift::linkPreviewTypeUpgradedGift(object_ptr<upgradedGift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t linkPreviewTypeUpgradedGift::ID;

void linkPreviewTypeUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeUpgradedGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeUser::linkPreviewTypeUser()
  : photo_()
  , is_bot_()
{}

linkPreviewTypeUser::linkPreviewTypeUser(object_ptr<chatPhoto> &&photo_, bool is_bot_)
  : photo_(std::move(photo_))
  , is_bot_(is_bot_)
{}

const std::int32_t linkPreviewTypeUser::ID;

void linkPreviewTypeUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeUser");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("is_bot", is_bot_);
    s.store_class_end();
  }
}

linkPreviewTypeVideo::linkPreviewTypeVideo()
  : video_()
  , cover_()
  , start_timestamp_()
{}

linkPreviewTypeVideo::linkPreviewTypeVideo(object_ptr<video> &&video_, object_ptr<photo> &&cover_, int32 start_timestamp_)
  : video_(std::move(video_))
  , cover_(std::move(cover_))
  , start_timestamp_(start_timestamp_)
{}

const std::int32_t linkPreviewTypeVideo::ID;

void linkPreviewTypeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_field("start_timestamp", start_timestamp_);
    s.store_class_end();
  }
}

linkPreviewTypeVideoChat::linkPreviewTypeVideoChat()
  : photo_()
  , is_live_stream_()
  , joins_as_speaker_()
{}

linkPreviewTypeVideoChat::linkPreviewTypeVideoChat(object_ptr<chatPhoto> &&photo_, bool is_live_stream_, bool joins_as_speaker_)
  : photo_(std::move(photo_))
  , is_live_stream_(is_live_stream_)
  , joins_as_speaker_(joins_as_speaker_)
{}

const std::int32_t linkPreviewTypeVideoChat::ID;

void linkPreviewTypeVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeVideoChat");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("is_live_stream", is_live_stream_);
    s.store_field("joins_as_speaker", joins_as_speaker_);
    s.store_class_end();
  }
}

linkPreviewTypeVideoNote::linkPreviewTypeVideoNote()
  : video_note_()
{}

linkPreviewTypeVideoNote::linkPreviewTypeVideoNote(object_ptr<videoNote> &&video_note_)
  : video_note_(std::move(video_note_))
{}

const std::int32_t linkPreviewTypeVideoNote::ID;

void linkPreviewTypeVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeVideoNote");
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeVoiceNote::linkPreviewTypeVoiceNote()
  : voice_note_()
{}

linkPreviewTypeVoiceNote::linkPreviewTypeVoiceNote(object_ptr<voiceNote> &&voice_note_)
  : voice_note_(std::move(voice_note_))
{}

const std::int32_t linkPreviewTypeVoiceNote::ID;

void linkPreviewTypeVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_class_end();
  }
}

linkPreviewTypeWebApp::linkPreviewTypeWebApp()
  : photo_()
{}

linkPreviewTypeWebApp::linkPreviewTypeWebApp(object_ptr<photo> &&photo_)
  : photo_(std::move(photo_))
{}

const std::int32_t linkPreviewTypeWebApp::ID;

void linkPreviewTypeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreviewTypeWebApp");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

maskPosition::maskPosition()
  : point_()
  , x_shift_()
  , y_shift_()
  , scale_()
{}

maskPosition::maskPosition(object_ptr<MaskPoint> &&point_, double x_shift_, double y_shift_, double scale_)
  : point_(std::move(point_))
  , x_shift_(x_shift_)
  , y_shift_(y_shift_)
  , scale_(scale_)
{}

const std::int32_t maskPosition::ID;

void maskPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskPosition");
    s.store_object_field("point", static_cast<const BaseObject *>(point_.get()));
    s.store_field("x_shift", x_shift_);
    s.store_field("y_shift", y_shift_);
    s.store_field("scale", scale_);
    s.store_class_end();
  }
}

messageReactions::messageReactions()
  : reactions_()
  , are_tags_()
  , paid_reactors_()
  , can_get_added_reactions_()
{}

messageReactions::messageReactions(array<object_ptr<messageReaction>> &&reactions_, bool are_tags_, array<object_ptr<paidReactor>> &&paid_reactors_, bool can_get_added_reactions_)
  : reactions_(std::move(reactions_))
  , are_tags_(are_tags_)
  , paid_reactors_(std::move(paid_reactors_))
  , can_get_added_reactions_(can_get_added_reactions_)
{}

const std::int32_t messageReactions::ID;

void messageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReactions");
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("are_tags", are_tags_);
    { s.store_vector_begin("paid_reactors", paid_reactors_.size()); for (const auto &_value : paid_reactors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("can_get_added_reactions", can_get_added_reactions_);
    s.store_class_end();
  }
}

messageViewers::messageViewers()
  : viewers_()
{}

messageViewers::messageViewers(array<object_ptr<messageViewer>> &&viewers_)
  : viewers_(std::move(viewers_))
{}

const std::int32_t messageViewers::ID;

void messageViewers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageViewers");
    { s.store_vector_begin("viewers", viewers_.size()); for (const auto &_value : viewers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

ok::ok() {
}

const std::int32_t ok::ID;

void ok::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ok");
    s.store_class_end();
  }
}

pageBlockListItem::pageBlockListItem()
  : label_()
  , page_blocks_()
{}

pageBlockListItem::pageBlockListItem(string const &label_, array<object_ptr<PageBlock>> &&page_blocks_)
  : label_(label_)
  , page_blocks_(std::move(page_blocks_))
{}

const std::int32_t pageBlockListItem::ID;

void pageBlockListItem::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockListItem");
    s.store_field("label", label_);
    { s.store_vector_begin("page_blocks", page_blocks_.size()); for (const auto &_value : page_blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

passportAuthorizationForm::passportAuthorizationForm()
  : id_()
  , required_elements_()
  , privacy_policy_url_()
{}

passportAuthorizationForm::passportAuthorizationForm(int32 id_, array<object_ptr<passportRequiredElement>> &&required_elements_, string const &privacy_policy_url_)
  : id_(id_)
  , required_elements_(std::move(required_elements_))
  , privacy_policy_url_(privacy_policy_url_)
{}

const std::int32_t passportAuthorizationForm::ID;

void passportAuthorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportAuthorizationForm");
    s.store_field("id", id_);
    { s.store_vector_begin("required_elements", required_elements_.size()); for (const auto &_value : required_elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("privacy_policy_url", privacy_policy_url_);
    s.store_class_end();
  }
}

passportElements::passportElements()
  : elements_()
{}

passportElements::passportElements(array<object_ptr<PassportElement>> &&elements_)
  : elements_(std::move(elements_))
{}

const std::int32_t passportElements::ID;

void passportElements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElements");
    { s.store_vector_begin("elements", elements_.size()); for (const auto &_value : elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

passportRequiredElement::passportRequiredElement()
  : suitable_elements_()
{}

passportRequiredElement::passportRequiredElement(array<object_ptr<passportSuitableElement>> &&suitable_elements_)
  : suitable_elements_(std::move(suitable_elements_))
{}

const std::int32_t passportRequiredElement::ID;

void passportRequiredElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportRequiredElement");
    { s.store_vector_begin("suitable_elements", suitable_elements_.size()); for (const auto &_value : suitable_elements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

paymentForm::paymentForm()
  : id_()
  , type_()
  , seller_bot_user_id_()
  , product_info_()
{}

paymentForm::paymentForm(int64 id_, object_ptr<PaymentFormType> &&type_, int53 seller_bot_user_id_, object_ptr<productInfo> &&product_info_)
  : id_(id_)
  , type_(std::move(type_))
  , seller_bot_user_id_(seller_bot_user_id_)
  , product_info_(std::move(product_info_))
{}

const std::int32_t paymentForm::ID;

void paymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentForm");
    s.store_field("id", id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("seller_bot_user_id", seller_bot_user_id_);
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_class_end();
  }
}

pollVoters::pollVoters()
  : total_count_()
  , voters_()
{}

pollVoters::pollVoters(int32 total_count_, array<object_ptr<pollVoter>> &&voters_)
  : total_count_(total_count_)
  , voters_(std::move(voters_))
{}

const std::int32_t pollVoters::ID;

void pollVoters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollVoters");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("voters", voters_.size()); for (const auto &_value : voters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

premiumGiftCodeInfo::premiumGiftCodeInfo()
  : creator_id_()
  , creation_date_()
  , is_from_giveaway_()
  , giveaway_message_id_()
  , month_count_()
  , day_count_()
  , user_id_()
  , use_date_()
{}

premiumGiftCodeInfo::premiumGiftCodeInfo(object_ptr<MessageSender> &&creator_id_, int32 creation_date_, bool is_from_giveaway_, int53 giveaway_message_id_, int32 month_count_, int32 day_count_, int53 user_id_, int32 use_date_)
  : creator_id_(std::move(creator_id_))
  , creation_date_(creation_date_)
  , is_from_giveaway_(is_from_giveaway_)
  , giveaway_message_id_(giveaway_message_id_)
  , month_count_(month_count_)
  , day_count_(day_count_)
  , user_id_(user_id_)
  , use_date_(use_date_)
{}

const std::int32_t premiumGiftCodeInfo::ID;

void premiumGiftCodeInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumGiftCodeInfo");
    s.store_object_field("creator_id", static_cast<const BaseObject *>(creator_id_.get()));
    s.store_field("creation_date", creation_date_);
    s.store_field("is_from_giveaway", is_from_giveaway_);
    s.store_field("giveaway_message_id", giveaway_message_id_);
    s.store_field("month_count", month_count_);
    s.store_field("day_count", day_count_);
    s.store_field("user_id", user_id_);
    s.store_field("use_date", use_date_);
    s.store_class_end();
  }
}

premiumGiveawayPaymentOption::premiumGiveawayPaymentOption()
  : currency_()
  , amount_()
  , winner_count_()
  , month_count_()
  , store_product_id_()
  , store_product_quantity_()
{}

premiumGiveawayPaymentOption::premiumGiveawayPaymentOption(string const &currency_, int53 amount_, int32 winner_count_, int32 month_count_, string const &store_product_id_, int32 store_product_quantity_)
  : currency_(currency_)
  , amount_(amount_)
  , winner_count_(winner_count_)
  , month_count_(month_count_)
  , store_product_id_(store_product_id_)
  , store_product_quantity_(store_product_quantity_)
{}

const std::int32_t premiumGiveawayPaymentOption::ID;

void premiumGiveawayPaymentOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumGiveawayPaymentOption");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("winner_count", winner_count_);
    s.store_field("month_count", month_count_);
    s.store_field("store_product_id", store_product_id_);
    s.store_field("store_product_quantity", store_product_quantity_);
    s.store_class_end();
  }
}

productInfo::productInfo()
  : title_()
  , description_()
  , photo_()
{}

productInfo::productInfo(string const &title_, object_ptr<formattedText> &&description_, object_ptr<photo> &&photo_)
  : title_(title_)
  , description_(std::move(description_))
  , photo_(std::move(photo_))
{}

const std::int32_t productInfo::ID;

void productInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "productInfo");
    s.store_field("title", title_);
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

quickReplyShortcut::quickReplyShortcut()
  : id_()
  , name_()
  , first_message_()
  , message_count_()
{}

quickReplyShortcut::quickReplyShortcut(int32 id_, string const &name_, object_ptr<quickReplyMessage> &&first_message_, int32 message_count_)
  : id_(id_)
  , name_(name_)
  , first_message_(std::move(first_message_))
  , message_count_(message_count_)
{}

const std::int32_t quickReplyShortcut::ID;

void quickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "quickReplyShortcut");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_object_field("first_message", static_cast<const BaseObject *>(first_message_.get()));
    s.store_field("message_count", message_count_);
    s.store_class_end();
  }
}

reportChatResultOk::reportChatResultOk() {
}

const std::int32_t reportChatResultOk::ID;

void reportChatResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatResultOk");
    s.store_class_end();
  }
}

reportChatResultOptionRequired::reportChatResultOptionRequired()
  : title_()
  , options_()
{}

reportChatResultOptionRequired::reportChatResultOptionRequired(string const &title_, array<object_ptr<reportOption>> &&options_)
  : title_(title_)
  , options_(std::move(options_))
{}

const std::int32_t reportChatResultOptionRequired::ID;

void reportChatResultOptionRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatResultOptionRequired");
    s.store_field("title", title_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportChatResultTextRequired::reportChatResultTextRequired()
  : option_id_()
  , is_optional_()
{}

reportChatResultTextRequired::reportChatResultTextRequired(bytes const &option_id_, bool is_optional_)
  : option_id_(std::move(option_id_))
  , is_optional_(is_optional_)
{}

const std::int32_t reportChatResultTextRequired::ID;

void reportChatResultTextRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatResultTextRequired");
    s.store_bytes_field("option_id", option_id_);
    s.store_field("is_optional", is_optional_);
    s.store_class_end();
  }
}

reportChatResultMessagesRequired::reportChatResultMessagesRequired() {
}

const std::int32_t reportChatResultMessagesRequired::ID;

void reportChatResultMessagesRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportChatResultMessagesRequired");
    s.store_class_end();
  }
}

rtmpUrl::rtmpUrl()
  : url_()
  , stream_key_()
{}

rtmpUrl::rtmpUrl(string const &url_, string const &stream_key_)
  : url_(url_)
  , stream_key_(stream_key_)
{}

const std::int32_t rtmpUrl::ID;

void rtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "rtmpUrl");
    s.store_field("url", url_);
    s.store_field("stream_key", stream_key_);
    s.store_class_end();
  }
}

starAmount::starAmount()
  : star_count_()
  , nanostar_count_()
{}

starAmount::starAmount(int53 star_count_, int32 nanostar_count_)
  : star_count_(star_count_)
  , nanostar_count_(nanostar_count_)
{}

const std::int32_t starAmount::ID;

void starAmount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starAmount");
    s.store_field("star_count", star_count_);
    s.store_field("nanostar_count", nanostar_count_);
    s.store_class_end();
  }
}

starSubscriptionPricing::starSubscriptionPricing()
  : period_()
  , star_count_()
{}

starSubscriptionPricing::starSubscriptionPricing(int32 period_, int53 star_count_)
  : period_(period_)
  , star_count_(star_count_)
{}

const std::int32_t starSubscriptionPricing::ID;

void starSubscriptionPricing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starSubscriptionPricing");
    s.store_field("period", period_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

statisticalValue::statisticalValue()
  : value_()
  , previous_value_()
  , growth_rate_percentage_()
{}

statisticalValue::statisticalValue(double value_, double previous_value_, double growth_rate_percentage_)
  : value_(value_)
  , previous_value_(previous_value_)
  , growth_rate_percentage_(growth_rate_percentage_)
{}

const std::int32_t statisticalValue::ID;

void statisticalValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statisticalValue");
    s.store_field("value", value_);
    s.store_field("previous_value", previous_value_);
    s.store_field("growth_rate_percentage", growth_rate_percentage_);
    s.store_class_end();
  }
}

story::story()
  : id_()
  , poster_chat_id_()
  , poster_id_()
  , date_()
  , is_being_posted_()
  , is_being_edited_()
  , is_edited_()
  , is_posted_to_chat_page_()
  , is_visible_only_for_self_()
  , can_be_added_to_album_()
  , can_be_deleted_()
  , can_be_edited_()
  , can_be_forwarded_()
  , can_be_replied_()
  , can_set_privacy_settings_()
  , can_toggle_is_posted_to_chat_page_()
  , can_get_statistics_()
  , can_get_interactions_()
  , has_expired_viewers_()
  , repost_info_()
  , interaction_info_()
  , chosen_reaction_type_()
  , privacy_settings_()
  , content_()
  , areas_()
  , caption_()
  , album_ids_()
{}

story::story(int32 id_, int53 poster_chat_id_, object_ptr<MessageSender> &&poster_id_, int32 date_, bool is_being_posted_, bool is_being_edited_, bool is_edited_, bool is_posted_to_chat_page_, bool is_visible_only_for_self_, bool can_be_added_to_album_, bool can_be_deleted_, bool can_be_edited_, bool can_be_forwarded_, bool can_be_replied_, bool can_set_privacy_settings_, bool can_toggle_is_posted_to_chat_page_, bool can_get_statistics_, bool can_get_interactions_, bool has_expired_viewers_, object_ptr<storyRepostInfo> &&repost_info_, object_ptr<storyInteractionInfo> &&interaction_info_, object_ptr<ReactionType> &&chosen_reaction_type_, object_ptr<StoryPrivacySettings> &&privacy_settings_, object_ptr<StoryContent> &&content_, array<object_ptr<storyArea>> &&areas_, object_ptr<formattedText> &&caption_, array<int32> &&album_ids_)
  : id_(id_)
  , poster_chat_id_(poster_chat_id_)
  , poster_id_(std::move(poster_id_))
  , date_(date_)
  , is_being_posted_(is_being_posted_)
  , is_being_edited_(is_being_edited_)
  , is_edited_(is_edited_)
  , is_posted_to_chat_page_(is_posted_to_chat_page_)
  , is_visible_only_for_self_(is_visible_only_for_self_)
  , can_be_added_to_album_(can_be_added_to_album_)
  , can_be_deleted_(can_be_deleted_)
  , can_be_edited_(can_be_edited_)
  , can_be_forwarded_(can_be_forwarded_)
  , can_be_replied_(can_be_replied_)
  , can_set_privacy_settings_(can_set_privacy_settings_)
  , can_toggle_is_posted_to_chat_page_(can_toggle_is_posted_to_chat_page_)
  , can_get_statistics_(can_get_statistics_)
  , can_get_interactions_(can_get_interactions_)
  , has_expired_viewers_(has_expired_viewers_)
  , repost_info_(std::move(repost_info_))
  , interaction_info_(std::move(interaction_info_))
  , chosen_reaction_type_(std::move(chosen_reaction_type_))
  , privacy_settings_(std::move(privacy_settings_))
  , content_(std::move(content_))
  , areas_(std::move(areas_))
  , caption_(std::move(caption_))
  , album_ids_(std::move(album_ids_))
{}

const std::int32_t story::ID;

void story::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "story");
    s.store_field("id", id_);
    s.store_field("poster_chat_id", poster_chat_id_);
    s.store_object_field("poster_id", static_cast<const BaseObject *>(poster_id_.get()));
    s.store_field("date", date_);
    s.store_field("is_being_posted", is_being_posted_);
    s.store_field("is_being_edited", is_being_edited_);
    s.store_field("is_edited", is_edited_);
    s.store_field("is_posted_to_chat_page", is_posted_to_chat_page_);
    s.store_field("is_visible_only_for_self", is_visible_only_for_self_);
    s.store_field("can_be_added_to_album", can_be_added_to_album_);
    s.store_field("can_be_deleted", can_be_deleted_);
    s.store_field("can_be_edited", can_be_edited_);
    s.store_field("can_be_forwarded", can_be_forwarded_);
    s.store_field("can_be_replied", can_be_replied_);
    s.store_field("can_set_privacy_settings", can_set_privacy_settings_);
    s.store_field("can_toggle_is_posted_to_chat_page", can_toggle_is_posted_to_chat_page_);
    s.store_field("can_get_statistics", can_get_statistics_);
    s.store_field("can_get_interactions", can_get_interactions_);
    s.store_field("has_expired_viewers", has_expired_viewers_);
    s.store_object_field("repost_info", static_cast<const BaseObject *>(repost_info_.get()));
    s.store_object_field("interaction_info", static_cast<const BaseObject *>(interaction_info_.get()));
    s.store_object_field("chosen_reaction_type", static_cast<const BaseObject *>(chosen_reaction_type_.get()));
    s.store_object_field("privacy_settings", static_cast<const BaseObject *>(privacy_settings_.get()));
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    { s.store_vector_begin("areas", areas_.size()); for (const auto &_value : areas_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    { s.store_vector_begin("album_ids", album_ids_.size()); for (const auto &_value : album_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyAlbum::storyAlbum()
  : id_()
  , name_()
  , photo_icon_()
  , video_icon_()
{}

storyAlbum::storyAlbum(int32 id_, string const &name_, object_ptr<photo> &&photo_icon_, object_ptr<video> &&video_icon_)
  : id_(id_)
  , name_(name_)
  , photo_icon_(std::move(photo_icon_))
  , video_icon_(std::move(video_icon_))
{}

const std::int32_t storyAlbum::ID;

void storyAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAlbum");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_object_field("photo_icon", static_cast<const BaseObject *>(photo_icon_.get()));
    s.store_object_field("video_icon", static_cast<const BaseObject *>(video_icon_.get()));
    s.store_class_end();
  }
}

storyAlbums::storyAlbums()
  : albums_()
{}

storyAlbums::storyAlbums(array<object_ptr<storyAlbum>> &&albums_)
  : albums_(std::move(albums_))
{}

const std::int32_t storyAlbums::ID;

void storyAlbums::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAlbums");
    { s.store_vector_begin("albums", albums_.size()); for (const auto &_value : albums_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

suggestedPostRefundReasonPostDeleted::suggestedPostRefundReasonPostDeleted() {
}

const std::int32_t suggestedPostRefundReasonPostDeleted::ID;

void suggestedPostRefundReasonPostDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostRefundReasonPostDeleted");
    s.store_class_end();
  }
}

suggestedPostRefundReasonPaymentRefunded::suggestedPostRefundReasonPaymentRefunded() {
}

const std::int32_t suggestedPostRefundReasonPaymentRefunded::ID;

void suggestedPostRefundReasonPaymentRefunded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostRefundReasonPaymentRefunded");
    s.store_class_end();
  }
}

termsOfService::termsOfService()
  : text_()
  , min_user_age_()
  , show_popup_()
{}

termsOfService::termsOfService(object_ptr<formattedText> &&text_, int32 min_user_age_, bool show_popup_)
  : text_(std::move(text_))
  , min_user_age_(min_user_age_)
  , show_popup_(show_popup_)
{}

const std::int32_t termsOfService::ID;

void termsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "termsOfService");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("min_user_age", min_user_age_);
    s.store_field("show_popup", show_popup_);
    s.store_class_end();
  }
}

testBytes::testBytes()
  : value_()
{}

testBytes::testBytes(bytes const &value_)
  : value_(std::move(value_))
{}

const std::int32_t testBytes::ID;

void testBytes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testBytes");
    s.store_bytes_field("value", value_);
    s.store_class_end();
  }
}

upgradedGiftAttributeIdModel::upgradedGiftAttributeIdModel()
  : sticker_id_()
{}

upgradedGiftAttributeIdModel::upgradedGiftAttributeIdModel(int64 sticker_id_)
  : sticker_id_(sticker_id_)
{}

const std::int32_t upgradedGiftAttributeIdModel::ID;

void upgradedGiftAttributeIdModel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeIdModel");
    s.store_field("sticker_id", sticker_id_);
    s.store_class_end();
  }
}

upgradedGiftAttributeIdSymbol::upgradedGiftAttributeIdSymbol()
  : sticker_id_()
{}

upgradedGiftAttributeIdSymbol::upgradedGiftAttributeIdSymbol(int64 sticker_id_)
  : sticker_id_(sticker_id_)
{}

const std::int32_t upgradedGiftAttributeIdSymbol::ID;

void upgradedGiftAttributeIdSymbol::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeIdSymbol");
    s.store_field("sticker_id", sticker_id_);
    s.store_class_end();
  }
}

upgradedGiftAttributeIdBackdrop::upgradedGiftAttributeIdBackdrop()
  : backdrop_id_()
{}

upgradedGiftAttributeIdBackdrop::upgradedGiftAttributeIdBackdrop(int32 backdrop_id_)
  : backdrop_id_(backdrop_id_)
{}

const std::int32_t upgradedGiftAttributeIdBackdrop::ID;

void upgradedGiftAttributeIdBackdrop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeIdBackdrop");
    s.store_field("backdrop_id", backdrop_id_);
    s.store_class_end();
  }
}

upgradedGiftBackdrop::upgradedGiftBackdrop()
  : id_()
  , name_()
  , colors_()
  , rarity_()
{}

upgradedGiftBackdrop::upgradedGiftBackdrop(int32 id_, string const &name_, object_ptr<upgradedGiftBackdropColors> &&colors_, object_ptr<UpgradedGiftAttributeRarity> &&rarity_)
  : id_(id_)
  , name_(name_)
  , colors_(std::move(colors_))
  , rarity_(std::move(rarity_))
{}

const std::int32_t upgradedGiftBackdrop::ID;

void upgradedGiftBackdrop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftBackdrop");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_object_field("colors", static_cast<const BaseObject *>(colors_.get()));
    s.store_object_field("rarity", static_cast<const BaseObject *>(rarity_.get()));
    s.store_class_end();
  }
}

upgradedGiftOriginUpgrade::upgradedGiftOriginUpgrade()
  : gift_message_id_()
{}

upgradedGiftOriginUpgrade::upgradedGiftOriginUpgrade(int53 gift_message_id_)
  : gift_message_id_(gift_message_id_)
{}

const std::int32_t upgradedGiftOriginUpgrade::ID;

void upgradedGiftOriginUpgrade::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginUpgrade");
    s.store_field("gift_message_id", gift_message_id_);
    s.store_class_end();
  }
}

upgradedGiftOriginTransfer::upgradedGiftOriginTransfer() {
}

const std::int32_t upgradedGiftOriginTransfer::ID;

void upgradedGiftOriginTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginTransfer");
    s.store_class_end();
  }
}

upgradedGiftOriginResale::upgradedGiftOriginResale()
  : price_()
{}

upgradedGiftOriginResale::upgradedGiftOriginResale(object_ptr<GiftResalePrice> &&price_)
  : price_(std::move(price_))
{}

const std::int32_t upgradedGiftOriginResale::ID;

void upgradedGiftOriginResale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginResale");
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

upgradedGiftOriginBlockchain::upgradedGiftOriginBlockchain() {
}

const std::int32_t upgradedGiftOriginBlockchain::ID;

void upgradedGiftOriginBlockchain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginBlockchain");
    s.store_class_end();
  }
}

upgradedGiftOriginPrepaidUpgrade::upgradedGiftOriginPrepaidUpgrade() {
}

const std::int32_t upgradedGiftOriginPrepaidUpgrade::ID;

void upgradedGiftOriginPrepaidUpgrade::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginPrepaidUpgrade");
    s.store_class_end();
  }
}

upgradedGiftOriginOffer::upgradedGiftOriginOffer()
  : price_()
{}

upgradedGiftOriginOffer::upgradedGiftOriginOffer(object_ptr<GiftResalePrice> &&price_)
  : price_(std::move(price_))
{}

const std::int32_t upgradedGiftOriginOffer::ID;

void upgradedGiftOriginOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginOffer");
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

upgradedGiftOriginCraft::upgradedGiftOriginCraft() {
}

const std::int32_t upgradedGiftOriginCraft::ID;

void upgradedGiftOriginCraft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftOriginCraft");
    s.store_class_end();
  }
}

userPrivacySettingRules::userPrivacySettingRules()
  : rules_()
{}

userPrivacySettingRules::userPrivacySettingRules(array<object_ptr<UserPrivacySettingRule>> &&rules_)
  : rules_(std::move(rules_))
{}

const std::int32_t userPrivacySettingRules::ID;

void userPrivacySettingRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userPrivacySettingRules");
    { s.store_vector_begin("rules", rules_.size()); for (const auto &_value : rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

userRating::userRating()
  : level_()
  , is_maximum_level_reached_()
  , rating_()
  , current_level_rating_()
  , next_level_rating_()
{}

userRating::userRating(int32 level_, bool is_maximum_level_reached_, int53 rating_, int53 current_level_rating_, int53 next_level_rating_)
  : level_(level_)
  , is_maximum_level_reached_(is_maximum_level_reached_)
  , rating_(rating_)
  , current_level_rating_(current_level_rating_)
  , next_level_rating_(next_level_rating_)
{}

const std::int32_t userRating::ID;

void userRating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userRating");
    s.store_field("level", level_);
    s.store_field("is_maximum_level_reached", is_maximum_level_reached_);
    s.store_field("rating", rating_);
    s.store_field("current_level_rating", current_level_rating_);
    s.store_field("next_level_rating", next_level_rating_);
    s.store_class_end();
  }
}

verificationStatus::verificationStatus()
  : is_verified_()
  , is_scam_()
  , is_fake_()
  , bot_verification_icon_custom_emoji_id_()
{}

verificationStatus::verificationStatus(bool is_verified_, bool is_scam_, bool is_fake_, int64 bot_verification_icon_custom_emoji_id_)
  : is_verified_(is_verified_)
  , is_scam_(is_scam_)
  , is_fake_(is_fake_)
  , bot_verification_icon_custom_emoji_id_(bot_verification_icon_custom_emoji_id_)
{}

const std::int32_t verificationStatus::ID;

void verificationStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "verificationStatus");
    s.store_field("is_verified", is_verified_);
    s.store_field("is_scam", is_scam_);
    s.store_field("is_fake", is_fake_);
    s.store_field("bot_verification_icon_custom_emoji_id", bot_verification_icon_custom_emoji_id_);
    s.store_class_end();
  }
}

videoMessageAdvertisements::videoMessageAdvertisements()
  : advertisements_()
  , start_delay_()
  , between_delay_()
{}

videoMessageAdvertisements::videoMessageAdvertisements(array<object_ptr<videoMessageAdvertisement>> &&advertisements_, int32 start_delay_, int32 between_delay_)
  : advertisements_(std::move(advertisements_))
  , start_delay_(start_delay_)
  , between_delay_(between_delay_)
{}

const std::int32_t videoMessageAdvertisements::ID;

void videoMessageAdvertisements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoMessageAdvertisements");
    { s.store_vector_begin("advertisements", advertisements_.size()); for (const auto &_value : advertisements_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("start_delay", start_delay_);
    s.store_field("between_delay", between_delay_);
    s.store_class_end();
  }
}

addChatMembers::addChatMembers()
  : chat_id_()
  , user_ids_()
{}

addChatMembers::addChatMembers(int53 chat_id_, array<int53> &&user_ids_)
  : chat_id_(chat_id_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t addChatMembers::ID;

void addChatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChatMembers");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

addChecklistTasks::addChecklistTasks()
  : chat_id_()
  , message_id_()
  , tasks_()
{}

addChecklistTasks::addChecklistTasks(int53 chat_id_, int53 message_id_, array<object_ptr<inputChecklistTask>> &&tasks_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , tasks_(std::move(tasks_))
{}

const std::int32_t addChecklistTasks::ID;

void addChecklistTasks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChecklistTasks");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("tasks", tasks_.size()); for (const auto &_value : tasks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

addQuickReplyShortcutMessageAlbum::addQuickReplyShortcutMessageAlbum()
  : shortcut_name_()
  , reply_to_message_id_()
  , input_message_contents_()
{}

addQuickReplyShortcutMessageAlbum::addQuickReplyShortcutMessageAlbum(string const &shortcut_name_, int53 reply_to_message_id_, array<object_ptr<InputMessageContent>> &&input_message_contents_)
  : shortcut_name_(shortcut_name_)
  , reply_to_message_id_(reply_to_message_id_)
  , input_message_contents_(std::move(input_message_contents_))
{}

const std::int32_t addQuickReplyShortcutMessageAlbum::ID;

void addQuickReplyShortcutMessageAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addQuickReplyShortcutMessageAlbum");
    s.store_field("shortcut_name", shortcut_name_);
    s.store_field("reply_to_message_id", reply_to_message_id_);
    { s.store_vector_begin("input_message_contents", input_message_contents_.size()); for (const auto &_value : input_message_contents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

addRecentSticker::addRecentSticker()
  : is_attached_()
  , sticker_()
{}

addRecentSticker::addRecentSticker(bool is_attached_, object_ptr<InputFile> &&sticker_)
  : is_attached_(is_attached_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t addRecentSticker::ID;

void addRecentSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addRecentSticker");
    s.store_field("is_attached", is_attached_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

addSavedAnimation::addSavedAnimation()
  : animation_()
{}

addSavedAnimation::addSavedAnimation(object_ptr<InputFile> &&animation_)
  : animation_(std::move(animation_))
{}

const std::int32_t addSavedAnimation::ID;

void addSavedAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addSavedAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

answerCallbackQuery::answerCallbackQuery()
  : callback_query_id_()
  , text_()
  , show_alert_()
  , url_()
  , cache_time_()
{}

answerCallbackQuery::answerCallbackQuery(int64 callback_query_id_, string const &text_, bool show_alert_, string const &url_, int32 cache_time_)
  : callback_query_id_(callback_query_id_)
  , text_(text_)
  , show_alert_(show_alert_)
  , url_(url_)
  , cache_time_(cache_time_)
{}

const std::int32_t answerCallbackQuery::ID;

void answerCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerCallbackQuery");
    s.store_field("callback_query_id", callback_query_id_);
    s.store_field("text", text_);
    s.store_field("show_alert", show_alert_);
    s.store_field("url", url_);
    s.store_field("cache_time", cache_time_);
    s.store_class_end();
  }
}

answerCustomQuery::answerCustomQuery()
  : custom_query_id_()
  , data_()
{}

answerCustomQuery::answerCustomQuery(int64 custom_query_id_, string const &data_)
  : custom_query_id_(custom_query_id_)
  , data_(data_)
{}

const std::int32_t answerCustomQuery::ID;

void answerCustomQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerCustomQuery");
    s.store_field("custom_query_id", custom_query_id_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

answerInlineQuery::answerInlineQuery()
  : inline_query_id_()
  , is_personal_()
  , button_()
  , results_()
  , cache_time_()
  , next_offset_()
{}

answerInlineQuery::answerInlineQuery(int64 inline_query_id_, bool is_personal_, object_ptr<inlineQueryResultsButton> &&button_, array<object_ptr<InputInlineQueryResult>> &&results_, int32 cache_time_, string const &next_offset_)
  : inline_query_id_(inline_query_id_)
  , is_personal_(is_personal_)
  , button_(std::move(button_))
  , results_(std::move(results_))
  , cache_time_(cache_time_)
  , next_offset_(next_offset_)
{}

const std::int32_t answerInlineQuery::ID;

void answerInlineQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerInlineQuery");
    s.store_field("inline_query_id", inline_query_id_);
    s.store_field("is_personal", is_personal_);
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("cache_time", cache_time_);
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

banGroupCallParticipants::banGroupCallParticipants()
  : group_call_id_()
  , user_ids_()
{}

banGroupCallParticipants::banGroupCallParticipants(int32 group_call_id_, array<int64> &&user_ids_)
  : group_call_id_(group_call_id_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t banGroupCallParticipants::ID;

void banGroupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "banGroupCallParticipants");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

canSendMessageToUser::canSendMessageToUser()
  : user_id_()
  , only_local_()
{}

canSendMessageToUser::canSendMessageToUser(int53 user_id_, bool only_local_)
  : user_id_(user_id_)
  , only_local_(only_local_)
{}

const std::int32_t canSendMessageToUser::ID;

void canSendMessageToUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendMessageToUser");
    s.store_field("user_id", user_id_);
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

changeImportedContacts::changeImportedContacts()
  : contacts_()
{}

changeImportedContacts::changeImportedContacts(array<object_ptr<importedContact>> &&contacts_)
  : contacts_(std::move(contacts_))
{}

const std::int32_t changeImportedContacts::ID;

void changeImportedContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "changeImportedContacts");
    { s.store_vector_begin("contacts", contacts_.size()); for (const auto &_value : contacts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

checkAuthenticationCode::checkAuthenticationCode()
  : code_()
{}

checkAuthenticationCode::checkAuthenticationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkAuthenticationCode::ID;

void checkAuthenticationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

checkCreatedPublicChatsLimit::checkCreatedPublicChatsLimit()
  : type_()
{}

checkCreatedPublicChatsLimit::checkCreatedPublicChatsLimit(object_ptr<PublicChatType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t checkCreatedPublicChatsLimit::ID;

void checkCreatedPublicChatsLimit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkCreatedPublicChatsLimit");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

checkOauthRequestMatchCode::checkOauthRequestMatchCode()
  : url_()
  , match_code_()
{}

checkOauthRequestMatchCode::checkOauthRequestMatchCode(string const &url_, string const &match_code_)
  : url_(url_)
  , match_code_(match_code_)
{}

const std::int32_t checkOauthRequestMatchCode::ID;

void checkOauthRequestMatchCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkOauthRequestMatchCode");
    s.store_field("url", url_);
    s.store_field("match_code", match_code_);
    s.store_class_end();
  }
}

clearAllDraftMessages::clearAllDraftMessages()
  : exclude_secret_chats_()
{}

clearAllDraftMessages::clearAllDraftMessages(bool exclude_secret_chats_)
  : exclude_secret_chats_(exclude_secret_chats_)
{}

const std::int32_t clearAllDraftMessages::ID;

void clearAllDraftMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearAllDraftMessages");
    s.store_field("exclude_secret_chats", exclude_secret_chats_);
    s.store_class_end();
  }
}

clearRecentReactions::clearRecentReactions() {
}

const std::int32_t clearRecentReactions::ID;

void clearRecentReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearRecentReactions");
    s.store_class_end();
  }
}

declineSuggestedPost::declineSuggestedPost()
  : chat_id_()
  , message_id_()
  , comment_()
{}

declineSuggestedPost::declineSuggestedPost(int53 chat_id_, int53 message_id_, string const &comment_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , comment_(comment_)
{}

const std::int32_t declineSuggestedPost::ID;

void declineSuggestedPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "declineSuggestedPost");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("comment", comment_);
    s.store_class_end();
  }
}

deleteAllCallMessages::deleteAllCallMessages()
  : revoke_()
{}

deleteAllCallMessages::deleteAllCallMessages(bool revoke_)
  : revoke_(revoke_)
{}

const std::int32_t deleteAllCallMessages::ID;

void deleteAllCallMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteAllCallMessages");
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

deleteDirectMessagesChatTopicHistory::deleteDirectMessagesChatTopicHistory()
  : chat_id_()
  , topic_id_()
{}

deleteDirectMessagesChatTopicHistory::deleteDirectMessagesChatTopicHistory(int53 chat_id_, int53 topic_id_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
{}

const std::int32_t deleteDirectMessagesChatTopicHistory::ID;

void deleteDirectMessagesChatTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteDirectMessagesChatTopicHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_class_end();
  }
}

deleteSavedMessagesTopicHistory::deleteSavedMessagesTopicHistory()
  : saved_messages_topic_id_()
{}

deleteSavedMessagesTopicHistory::deleteSavedMessagesTopicHistory(int53 saved_messages_topic_id_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
{}

const std::int32_t deleteSavedMessagesTopicHistory::ID;

void deleteSavedMessagesTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteSavedMessagesTopicHistory");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_class_end();
  }
}

editBusinessMessageCaption::editBusinessMessageCaption()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
  , caption_()
  , show_caption_above_media_()
{}

editBusinessMessageCaption::editBusinessMessageCaption(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
{}

const std::int32_t editBusinessMessageCaption::ID;

void editBusinessMessageCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessMessageCaption");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_class_end();
  }
}

editBusinessMessageText::editBusinessMessageText()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editBusinessMessageText::editBusinessMessageText(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editBusinessMessageText::ID;

void editBusinessMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessMessageText");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

enableProxy::enableProxy()
  : proxy_id_()
{}

enableProxy::enableProxy(int32 proxy_id_)
  : proxy_id_(proxy_id_)
{}

const std::int32_t enableProxy::ID;

void enableProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "enableProxy");
    s.store_field("proxy_id", proxy_id_);
    s.store_class_end();
  }
}

getAccountTtl::getAccountTtl() {
}

const std::int32_t getAccountTtl::ID;

void getAccountTtl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAccountTtl");
    s.store_class_end();
  }
}

getActiveSessions::getActiveSessions() {
}

const std::int32_t getActiveSessions::ID;

void getActiveSessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getActiveSessions");
    s.store_class_end();
  }
}

getAnimatedEmoji::getAnimatedEmoji()
  : emoji_()
{}

getAnimatedEmoji::getAnimatedEmoji(string const &emoji_)
  : emoji_(emoji_)
{}

const std::int32_t getAnimatedEmoji::ID;

void getAnimatedEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAnimatedEmoji");
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

getAvailableChatBoostSlots::getAvailableChatBoostSlots() {
}

const std::int32_t getAvailableChatBoostSlots::ID;

void getAvailableChatBoostSlots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAvailableChatBoostSlots");
    s.store_class_end();
  }
}

getBankCardInfo::getBankCardInfo()
  : bank_card_number_()
{}

getBankCardInfo::getBankCardInfo(string const &bank_card_number_)
  : bank_card_number_(bank_card_number_)
{}

const std::int32_t getBankCardInfo::ID;

void getBankCardInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBankCardInfo");
    s.store_field("bank_card_number", bank_card_number_);
    s.store_class_end();
  }
}

getBotMediaPreviews::getBotMediaPreviews()
  : bot_user_id_()
{}

getBotMediaPreviews::getBotMediaPreviews(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t getBotMediaPreviews::ID;

void getBotMediaPreviews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotMediaPreviews");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

getChatFolderNewChats::getChatFolderNewChats()
  : chat_folder_id_()
{}

getChatFolderNewChats::getChatFolderNewChats(int32 chat_folder_id_)
  : chat_folder_id_(chat_folder_id_)
{}

const std::int32_t getChatFolderNewChats::ID;

void getChatFolderNewChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFolderNewChats");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_class_end();
  }
}

getChatMessageCount::getChatMessageCount()
  : chat_id_()
  , topic_id_()
  , filter_()
  , return_local_()
{}

getChatMessageCount::getChatMessageCount(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<SearchMessagesFilter> &&filter_, bool return_local_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , filter_(std::move(filter_))
  , return_local_(return_local_)
{}

const std::int32_t getChatMessageCount::ID;

void getChatMessageCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMessageCount");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("return_local", return_local_);
    s.store_class_end();
  }
}

getChatsForChatFolderInviteLink::getChatsForChatFolderInviteLink()
  : chat_folder_id_()
{}

getChatsForChatFolderInviteLink::getChatsForChatFolderInviteLink(int32 chat_folder_id_)
  : chat_folder_id_(chat_folder_id_)
{}

const std::int32_t getChatsForChatFolderInviteLink::ID;

void getChatsForChatFolderInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatsForChatFolderInviteLink");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_class_end();
  }
}

getDefaultChatPhotoCustomEmojiStickers::getDefaultChatPhotoCustomEmojiStickers() {
}

const std::int32_t getDefaultChatPhotoCustomEmojiStickers::ID;

void getDefaultChatPhotoCustomEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDefaultChatPhotoCustomEmojiStickers");
    s.store_class_end();
  }
}

getFile::getFile()
  : file_id_()
{}

getFile::getFile(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t getFile::ID;

void getFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFile");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

getForumTopics::getForumTopics()
  : chat_id_()
  , query_()
  , offset_date_()
  , offset_message_id_()
  , offset_forum_topic_id_()
  , limit_()
{}

getForumTopics::getForumTopics(int53 chat_id_, string const &query_, int32 offset_date_, int53 offset_message_id_, int32 offset_forum_topic_id_, int32 limit_)
  : chat_id_(chat_id_)
  , query_(query_)
  , offset_date_(offset_date_)
  , offset_message_id_(offset_message_id_)
  , offset_forum_topic_id_(offset_forum_topic_id_)
  , limit_(limit_)
{}

const std::int32_t getForumTopics::ID;

void getForumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getForumTopics");
    s.store_field("chat_id", chat_id_);
    s.store_field("query", query_);
    s.store_field("offset_date", offset_date_);
    s.store_field("offset_message_id", offset_message_id_);
    s.store_field("offset_forum_topic_id", offset_forum_topic_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getGiftChatThemes::getGiftChatThemes()
  : offset_()
  , limit_()
{}

getGiftChatThemes::getGiftChatThemes(string const &offset_, int32 limit_)
  : offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getGiftChatThemes::ID;

void getGiftChatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGiftChatThemes");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getInlineQueryResults::getInlineQueryResults()
  : bot_user_id_()
  , chat_id_()
  , user_location_()
  , query_()
  , offset_()
{}

getInlineQueryResults::getInlineQueryResults(int53 bot_user_id_, int53 chat_id_, object_ptr<location> &&user_location_, string const &query_, string const &offset_)
  : bot_user_id_(bot_user_id_)
  , chat_id_(chat_id_)
  , user_location_(std::move(user_location_))
  , query_(query_)
  , offset_(offset_)
{}

const std::int32_t getInlineQueryResults::ID;

void getInlineQueryResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInlineQueryResults");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("user_location", static_cast<const BaseObject *>(user_location_.get()));
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

getInternalLink::getInternalLink()
  : type_()
  , is_http_()
{}

getInternalLink::getInternalLink(object_ptr<InternalLinkType> &&type_, bool is_http_)
  : type_(std::move(type_))
  , is_http_(is_http_)
{}

const std::int32_t getInternalLink::ID;

void getInternalLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInternalLink");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("is_http", is_http_);
    s.store_class_end();
  }
}

getInternalLinkType::getInternalLinkType()
  : link_()
{}

getInternalLinkType::getInternalLinkType(string const &link_)
  : link_(link_)
{}

const std::int32_t getInternalLinkType::ID;

void getInternalLinkType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInternalLinkType");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

getMe::getMe() {
}

const std::int32_t getMe::ID;

void getMe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMe");
    s.store_class_end();
  }
}

getMessageEffect::getMessageEffect()
  : effect_id_()
{}

getMessageEffect::getMessageEffect(int64 effect_id_)
  : effect_id_(effect_id_)
{}

const std::int32_t getMessageEffect::ID;

void getMessageEffect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageEffect");
    s.store_field("effect_id", effect_id_);
    s.store_class_end();
  }
}

getNetworkStatistics::getNetworkStatistics()
  : only_current_()
{}

getNetworkStatistics::getNetworkStatistics(bool only_current_)
  : only_current_(only_current_)
{}

const std::int32_t getNetworkStatistics::ID;

void getNetworkStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getNetworkStatistics");
    s.store_field("only_current", only_current_);
    s.store_class_end();
  }
}

getPasskeyParameters::getPasskeyParameters() {
}

const std::int32_t getPasskeyParameters::ID;

void getPasskeyParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPasskeyParameters");
    s.store_class_end();
  }
}

getPassportAuthorizationForm::getPassportAuthorizationForm()
  : bot_user_id_()
  , scope_()
  , public_key_()
  , nonce_()
{}

getPassportAuthorizationForm::getPassportAuthorizationForm(int53 bot_user_id_, string const &scope_, string const &public_key_, string const &nonce_)
  : bot_user_id_(bot_user_id_)
  , scope_(scope_)
  , public_key_(public_key_)
  , nonce_(nonce_)
{}

const std::int32_t getPassportAuthorizationForm::ID;

void getPassportAuthorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPassportAuthorizationForm");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("scope", scope_);
    s.store_field("public_key", public_key_);
    s.store_field("nonce", nonce_);
    s.store_class_end();
  }
}

getPremiumStickers::getPremiumStickers()
  : limit_()
{}

getPremiumStickers::getPremiumStickers(int32 limit_)
  : limit_(limit_)
{}

const std::int32_t getPremiumStickers::ID;

void getPremiumStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPremiumStickers");
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getPreparedInlineMessage::getPreparedInlineMessage()
  : bot_user_id_()
  , prepared_message_id_()
{}

getPreparedInlineMessage::getPreparedInlineMessage(int53 bot_user_id_, string const &prepared_message_id_)
  : bot_user_id_(bot_user_id_)
  , prepared_message_id_(prepared_message_id_)
{}

const std::int32_t getPreparedInlineMessage::ID;

void getPreparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPreparedInlineMessage");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("prepared_message_id", prepared_message_id_);
    s.store_class_end();
  }
}

getRecentStickers::getRecentStickers()
  : is_attached_()
{}

getRecentStickers::getRecentStickers(bool is_attached_)
  : is_attached_(is_attached_)
{}

const std::int32_t getRecentStickers::ID;

void getRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentStickers");
    s.store_field("is_attached", is_attached_);
    s.store_class_end();
  }
}

getStarGiftPaymentOptions::getStarGiftPaymentOptions()
  : user_id_()
{}

getStarGiftPaymentOptions::getStarGiftPaymentOptions(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t getStarGiftPaymentOptions::ID;

void getStarGiftPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarGiftPaymentOptions");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getSuitablePersonalChats::getSuitablePersonalChats() {
}

const std::int32_t getSuitablePersonalChats::ID;

void getSuitablePersonalChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSuitablePersonalChats");
    s.store_class_end();
  }
}

getSupportUser::getSupportUser() {
}

const std::int32_t getSupportUser::ID;

void getSupportUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupportUser");
    s.store_class_end();
  }
}

getThemedEmojiStatuses::getThemedEmojiStatuses() {
}

const std::int32_t getThemedEmojiStatuses::ID;

void getThemedEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getThemedEmojiStatuses");
    s.store_class_end();
  }
}

getTonRevenueStatistics::getTonRevenueStatistics()
  : is_dark_()
{}

getTonRevenueStatistics::getTonRevenueStatistics(bool is_dark_)
  : is_dark_(is_dark_)
{}

const std::int32_t getTonRevenueStatistics::ID;

void getTonRevenueStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonRevenueStatistics");
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

hideContactCloseBirthdays::hideContactCloseBirthdays() {
}

const std::int32_t hideContactCloseBirthdays::ID;

void hideContactCloseBirthdays::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "hideContactCloseBirthdays");
    s.store_class_end();
  }
}

joinGroupCall::joinGroupCall()
  : input_group_call_()
  , join_parameters_()
{}

joinGroupCall::joinGroupCall(object_ptr<InputGroupCall> &&input_group_call_, object_ptr<groupCallJoinParameters> &&join_parameters_)
  : input_group_call_(std::move(input_group_call_))
  , join_parameters_(std::move(join_parameters_))
{}

const std::int32_t joinGroupCall::ID;

void joinGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinGroupCall");
    s.store_object_field("input_group_call", static_cast<const BaseObject *>(input_group_call_.get()));
    s.store_object_field("join_parameters", static_cast<const BaseObject *>(join_parameters_.get()));
    s.store_class_end();
  }
}

leaveChat::leaveChat()
  : chat_id_()
{}

leaveChat::leaveChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t leaveChat::ID;

void leaveChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "leaveChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

markChecklistTasksAsDone::markChecklistTasksAsDone()
  : chat_id_()
  , message_id_()
  , marked_as_done_task_ids_()
  , marked_as_not_done_task_ids_()
{}

markChecklistTasksAsDone::markChecklistTasksAsDone(int53 chat_id_, int53 message_id_, array<int32> &&marked_as_done_task_ids_, array<int32> &&marked_as_not_done_task_ids_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , marked_as_done_task_ids_(std::move(marked_as_done_task_ids_))
  , marked_as_not_done_task_ids_(std::move(marked_as_not_done_task_ids_))
{}

const std::int32_t markChecklistTasksAsDone::ID;

void markChecklistTasksAsDone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "markChecklistTasksAsDone");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("marked_as_done_task_ids", marked_as_done_task_ids_.size()); for (const auto &_value : marked_as_done_task_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("marked_as_not_done_task_ids", marked_as_not_done_task_ids_.size()); for (const auto &_value : marked_as_not_done_task_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

openBotSimilarBot::openBotSimilarBot()
  : bot_user_id_()
  , opened_bot_user_id_()
{}

openBotSimilarBot::openBotSimilarBot(int53 bot_user_id_, int53 opened_bot_user_id_)
  : bot_user_id_(bot_user_id_)
  , opened_bot_user_id_(opened_bot_user_id_)
{}

const std::int32_t openBotSimilarBot::ID;

void openBotSimilarBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openBotSimilarBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("opened_bot_user_id", opened_bot_user_id_);
    s.store_class_end();
  }
}

openChatSimilarChat::openChatSimilarChat()
  : chat_id_()
  , opened_chat_id_()
{}

openChatSimilarChat::openChatSimilarChat(int53 chat_id_, int53 opened_chat_id_)
  : chat_id_(chat_id_)
  , opened_chat_id_(opened_chat_id_)
{}

const std::int32_t openChatSimilarChat::ID;

void openChatSimilarChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openChatSimilarChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("opened_chat_id", opened_chat_id_);
    s.store_class_end();
  }
}

openWebApp::openWebApp()
  : chat_id_()
  , bot_user_id_()
  , url_()
  , topic_id_()
  , reply_to_()
  , parameters_()
{}

openWebApp::openWebApp(int53 chat_id_, int53 bot_user_id_, string const &url_, object_ptr<MessageTopic> &&topic_id_, object_ptr<InputMessageReplyTo> &&reply_to_, object_ptr<webAppOpenParameters> &&parameters_)
  : chat_id_(chat_id_)
  , bot_user_id_(bot_user_id_)
  , url_(url_)
  , topic_id_(std::move(topic_id_))
  , reply_to_(std::move(reply_to_))
  , parameters_(std::move(parameters_))
{}

const std::int32_t openWebApp::ID;

void openWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openWebApp");
    s.store_field("chat_id", chat_id_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("url", url_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

processChatFolderNewChats::processChatFolderNewChats()
  : chat_folder_id_()
  , added_chat_ids_()
{}

processChatFolderNewChats::processChatFolderNewChats(int32 chat_folder_id_, array<int53> &&added_chat_ids_)
  : chat_folder_id_(chat_folder_id_)
  , added_chat_ids_(std::move(added_chat_ids_))
{}

const std::int32_t processChatFolderNewChats::ID;

void processChatFolderNewChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processChatFolderNewChats");
    s.store_field("chat_folder_id", chat_folder_id_);
    { s.store_vector_begin("added_chat_ids", added_chat_ids_.size()); for (const auto &_value : added_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

processChatHasProtectedContentDisableRequest::processChatHasProtectedContentDisableRequest()
  : chat_id_()
  , request_message_id_()
  , approve_()
{}

processChatHasProtectedContentDisableRequest::processChatHasProtectedContentDisableRequest(int53 chat_id_, int53 request_message_id_, bool approve_)
  : chat_id_(chat_id_)
  , request_message_id_(request_message_id_)
  , approve_(approve_)
{}

const std::int32_t processChatHasProtectedContentDisableRequest::ID;

void processChatHasProtectedContentDisableRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "processChatHasProtectedContentDisableRequest");
    s.store_field("chat_id", chat_id_);
    s.store_field("request_message_id", request_message_id_);
    s.store_field("approve", approve_);
    s.store_class_end();
  }
}

readAllForumTopicPollVotes::readAllForumTopicPollVotes()
  : chat_id_()
  , forum_topic_id_()
{}

readAllForumTopicPollVotes::readAllForumTopicPollVotes(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t readAllForumTopicPollVotes::ID;

void readAllForumTopicPollVotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllForumTopicPollVotes");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

readdQuickReplyShortcutMessages::readdQuickReplyShortcutMessages()
  : shortcut_name_()
  , message_ids_()
{}

readdQuickReplyShortcutMessages::readdQuickReplyShortcutMessages(string const &shortcut_name_, array<int53> &&message_ids_)
  : shortcut_name_(shortcut_name_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t readdQuickReplyShortcutMessages::ID;

void readdQuickReplyShortcutMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readdQuickReplyShortcutMessages");
    s.store_field("shortcut_name", shortcut_name_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

registerDevice::registerDevice()
  : device_token_()
  , other_user_ids_()
{}

registerDevice::registerDevice(object_ptr<DeviceToken> &&device_token_, array<int53> &&other_user_ids_)
  : device_token_(std::move(device_token_))
  , other_user_ids_(std::move(other_user_ids_))
{}

const std::int32_t registerDevice::ID;

void registerDevice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "registerDevice");
    s.store_object_field("device_token", static_cast<const BaseObject *>(device_token_.get()));
    { s.store_vector_begin("other_user_ids", other_user_ids_.size()); for (const auto &_value : other_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

removePendingLiveStoryReactions::removePendingLiveStoryReactions()
  : group_call_id_()
{}

removePendingLiveStoryReactions::removePendingLiveStoryReactions(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t removePendingLiveStoryReactions::ID;

void removePendingLiveStoryReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removePendingLiveStoryReactions");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

reorderBotActiveUsernames::reorderBotActiveUsernames()
  : bot_user_id_()
  , usernames_()
{}

reorderBotActiveUsernames::reorderBotActiveUsernames(int53 bot_user_id_, array<string> &&usernames_)
  : bot_user_id_(bot_user_id_)
  , usernames_(std::move(usernames_))
{}

const std::int32_t reorderBotActiveUsernames::ID;

void reorderBotActiveUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderBotActiveUsernames");
    s.store_field("bot_user_id", bot_user_id_);
    { s.store_vector_begin("usernames", usernames_.size()); for (const auto &_value : usernames_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

requestQrCodeAuthentication::requestQrCodeAuthentication()
  : other_user_ids_()
{}

requestQrCodeAuthentication::requestQrCodeAuthentication(array<int53> &&other_user_ids_)
  : other_user_ids_(std::move(other_user_ids_))
{}

const std::int32_t requestQrCodeAuthentication::ID;

void requestQrCodeAuthentication::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestQrCodeAuthentication");
    { s.store_vector_begin("other_user_ids", other_user_ids_.size()); for (const auto &_value : other_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

resendAuthenticationCode::resendAuthenticationCode()
  : reason_()
{}

resendAuthenticationCode::resendAuthenticationCode(object_ptr<ResendCodeReason> &&reason_)
  : reason_(std::move(reason_))
{}

const std::int32_t resendAuthenticationCode::ID;

void resendAuthenticationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendAuthenticationCode");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_class_end();
  }
}

resetAuthenticationEmailAddress::resetAuthenticationEmailAddress() {
}

const std::int32_t resetAuthenticationEmailAddress::ID;

void resetAuthenticationEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetAuthenticationEmailAddress");
    s.store_class_end();
  }
}

resetNetworkStatistics::resetNetworkStatistics() {
}

const std::int32_t resetNetworkStatistics::ID;

void resetNetworkStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetNetworkStatistics");
    s.store_class_end();
  }
}

searchBackground::searchBackground()
  : name_()
{}

searchBackground::searchBackground(string const &name_)
  : name_(name_)
{}

const std::int32_t searchBackground::ID;

void searchBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchBackground");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

searchChatAffiliateProgram::searchChatAffiliateProgram()
  : username_()
  , referrer_()
{}

searchChatAffiliateProgram::searchChatAffiliateProgram(string const &username_, string const &referrer_)
  : username_(username_)
  , referrer_(referrer_)
{}

const std::int32_t searchChatAffiliateProgram::ID;

void searchChatAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatAffiliateProgram");
    s.store_field("username", username_);
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

searchPublicPosts::searchPublicPosts()
  : query_()
  , offset_()
  , limit_()
  , star_count_()
{}

searchPublicPosts::searchPublicPosts(string const &query_, string const &offset_, int32 limit_, int53 star_count_)
  : query_(query_)
  , offset_(offset_)
  , limit_(limit_)
  , star_count_(star_count_)
{}

const std::int32_t searchPublicPosts::ID;

void searchPublicPosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicPosts");
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

sendBusinessMessage::sendBusinessMessage()
  : business_connection_id_()
  , chat_id_()
  , reply_to_()
  , disable_notification_()
  , protect_content_()
  , effect_id_()
  , reply_markup_()
  , input_message_content_()
{}

sendBusinessMessage::sendBusinessMessage(string const &business_connection_id_, int53 chat_id_, object_ptr<InputMessageReplyTo> &&reply_to_, bool disable_notification_, bool protect_content_, int64 effect_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , reply_to_(std::move(reply_to_))
  , disable_notification_(disable_notification_)
  , protect_content_(protect_content_)
  , effect_id_(effect_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t sendBusinessMessage::ID;

void sendBusinessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendBusinessMessage");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_field("disable_notification", disable_notification_);
    s.store_field("protect_content", protect_content_);
    s.store_field("effect_id", effect_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

sendQuickReplyShortcutMessages::sendQuickReplyShortcutMessages()
  : chat_id_()
  , shortcut_id_()
  , sending_id_()
{}

sendQuickReplyShortcutMessages::sendQuickReplyShortcutMessages(int53 chat_id_, int32 shortcut_id_, int32 sending_id_)
  : chat_id_(chat_id_)
  , shortcut_id_(shortcut_id_)
  , sending_id_(sending_id_)
{}

const std::int32_t sendQuickReplyShortcutMessages::ID;

void sendQuickReplyShortcutMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendQuickReplyShortcutMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("shortcut_id", shortcut_id_);
    s.store_field("sending_id", sending_id_);
    s.store_class_end();
  }
}

setArchiveChatListSettings::setArchiveChatListSettings()
  : settings_()
{}

setArchiveChatListSettings::setArchiveChatListSettings(object_ptr<archiveChatListSettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t setArchiveChatListSettings::ID;

void setArchiveChatListSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setArchiveChatListSettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setBio::setBio()
  : bio_()
{}

setBio::setBio(string const &bio_)
  : bio_(bio_)
{}

const std::int32_t setBio::ID;

void setBio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBio");
    s.store_field("bio", bio_);
    s.store_class_end();
  }
}

setBotUpdatesStatus::setBotUpdatesStatus()
  : pending_update_count_()
  , error_message_()
{}

setBotUpdatesStatus::setBotUpdatesStatus(int32 pending_update_count_, string const &error_message_)
  : pending_update_count_(pending_update_count_)
  , error_message_(error_message_)
{}

const std::int32_t setBotUpdatesStatus::ID;

void setBotUpdatesStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBotUpdatesStatus");
    s.store_field("pending_update_count", pending_update_count_);
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

setBusinessAccountGiftSettings::setBusinessAccountGiftSettings()
  : business_connection_id_()
  , settings_()
{}

setBusinessAccountGiftSettings::setBusinessAccountGiftSettings(string const &business_connection_id_, object_ptr<giftSettings> &&settings_)
  : business_connection_id_(business_connection_id_)
  , settings_(std::move(settings_))
{}

const std::int32_t setBusinessAccountGiftSettings::ID;

void setBusinessAccountGiftSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessAccountGiftSettings");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setBusinessAccountUsername::setBusinessAccountUsername()
  : business_connection_id_()
  , username_()
{}

setBusinessAccountUsername::setBusinessAccountUsername(string const &business_connection_id_, string const &username_)
  : business_connection_id_(business_connection_id_)
  , username_(username_)
{}

const std::int32_t setBusinessAccountUsername::ID;

void setBusinessAccountUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessAccountUsername");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("username", username_);
    s.store_class_end();
  }
}

setChatLocation::setChatLocation()
  : chat_id_()
  , location_()
{}

setChatLocation::setChatLocation(int53 chat_id_, object_ptr<chatLocation> &&location_)
  : chat_id_(chat_id_)
  , location_(std::move(location_))
{}

const std::int32_t setChatLocation::ID;

void setChatLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatLocation");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

setChatNotificationSettings::setChatNotificationSettings()
  : chat_id_()
  , notification_settings_()
{}

setChatNotificationSettings::setChatNotificationSettings(int53 chat_id_, object_ptr<chatNotificationSettings> &&notification_settings_)
  : chat_id_(chat_id_)
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t setChatNotificationSettings::ID;

void setChatNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatNotificationSettings");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

setChatTheme::setChatTheme()
  : chat_id_()
  , theme_()
{}

setChatTheme::setChatTheme(int53 chat_id_, object_ptr<InputChatTheme> &&theme_)
  : chat_id_(chat_id_)
  , theme_(std::move(theme_))
{}

const std::int32_t setChatTheme::ID;

void setChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatTheme");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

setCustomEmojiStickerSetThumbnail::setCustomEmojiStickerSetThumbnail()
  : name_()
  , custom_emoji_id_()
{}

setCustomEmojiStickerSetThumbnail::setCustomEmojiStickerSetThumbnail(string const &name_, int64 custom_emoji_id_)
  : name_(name_)
  , custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t setCustomEmojiStickerSetThumbnail::ID;

void setCustomEmojiStickerSetThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCustomEmojiStickerSetThumbnail");
    s.store_field("name", name_);
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

setPassportElementErrors::setPassportElementErrors()
  : user_id_()
  , errors_()
{}

setPassportElementErrors::setPassportElementErrors(int53 user_id_, array<object_ptr<inputPassportElementError>> &&errors_)
  : user_id_(user_id_)
  , errors_(std::move(errors_))
{}

const std::int32_t setPassportElementErrors::ID;

void setPassportElementErrors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPassportElementErrors");
    s.store_field("user_id", user_id_);
    { s.store_vector_begin("errors", errors_.size()); for (const auto &_value : errors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

setPersonalChat::setPersonalChat()
  : chat_id_()
{}

setPersonalChat::setPersonalChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t setPersonalChat::ID;

void setPersonalChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPersonalChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

setProfileAudioPosition::setProfileAudioPosition()
  : file_id_()
  , after_file_id_()
{}

setProfileAudioPosition::setProfileAudioPosition(int32 file_id_, int32 after_file_id_)
  : file_id_(file_id_)
  , after_file_id_(after_file_id_)
{}

const std::int32_t setProfileAudioPosition::ID;

void setProfileAudioPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setProfileAudioPosition");
    s.store_field("file_id", file_id_);
    s.store_field("after_file_id", after_file_id_);
    s.store_class_end();
  }
}

setStickerEmojis::setStickerEmojis()
  : sticker_()
  , emojis_()
{}

setStickerEmojis::setStickerEmojis(object_ptr<InputFile> &&sticker_, string const &emojis_)
  : sticker_(std::move(sticker_))
  , emojis_(emojis_)
{}

const std::int32_t setStickerEmojis::ID;

void setStickerEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerEmojis");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("emojis", emojis_);
    s.store_class_end();
  }
}

setSupergroupUsername::setSupergroupUsername()
  : supergroup_id_()
  , username_()
{}

setSupergroupUsername::setSupergroupUsername(int53 supergroup_id_, string const &username_)
  : supergroup_id_(supergroup_id_)
  , username_(username_)
{}

const std::int32_t setSupergroupUsername::ID;

void setSupergroupUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSupergroupUsername");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("username", username_);
    s.store_class_end();
  }
}

summarizeMessage::summarizeMessage()
  : chat_id_()
  , message_id_()
  , translate_to_language_code_()
  , tone_()
{}

summarizeMessage::summarizeMessage(int53 chat_id_, int53 message_id_, string const &translate_to_language_code_, string const &tone_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , translate_to_language_code_(translate_to_language_code_)
  , tone_(tone_)
{}

const std::int32_t summarizeMessage::ID;

void summarizeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "summarizeMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("translate_to_language_code", translate_to_language_code_);
    s.store_field("tone", tone_);
    s.store_class_end();
  }
}

toggleBusinessConnectedBotChatIsPaused::toggleBusinessConnectedBotChatIsPaused()
  : chat_id_()
  , is_paused_()
{}

toggleBusinessConnectedBotChatIsPaused::toggleBusinessConnectedBotChatIsPaused(int53 chat_id_, bool is_paused_)
  : chat_id_(chat_id_)
  , is_paused_(is_paused_)
{}

const std::int32_t toggleBusinessConnectedBotChatIsPaused::ID;

void toggleBusinessConnectedBotChatIsPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleBusinessConnectedBotChatIsPaused");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_paused", is_paused_);
    s.store_class_end();
  }
}

toggleGroupCallIsMyVideoEnabled::toggleGroupCallIsMyVideoEnabled()
  : group_call_id_()
  , is_my_video_enabled_()
{}

toggleGroupCallIsMyVideoEnabled::toggleGroupCallIsMyVideoEnabled(int32 group_call_id_, bool is_my_video_enabled_)
  : group_call_id_(group_call_id_)
  , is_my_video_enabled_(is_my_video_enabled_)
{}

const std::int32_t toggleGroupCallIsMyVideoEnabled::ID;

void toggleGroupCallIsMyVideoEnabled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallIsMyVideoEnabled");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("is_my_video_enabled", is_my_video_enabled_);
    s.store_class_end();
  }
}

toggleSupergroupHasAggressiveAntiSpamEnabled::toggleSupergroupHasAggressiveAntiSpamEnabled()
  : supergroup_id_()
  , has_aggressive_anti_spam_enabled_()
{}

toggleSupergroupHasAggressiveAntiSpamEnabled::toggleSupergroupHasAggressiveAntiSpamEnabled(int53 supergroup_id_, bool has_aggressive_anti_spam_enabled_)
  : supergroup_id_(supergroup_id_)
  , has_aggressive_anti_spam_enabled_(has_aggressive_anti_spam_enabled_)
{}

const std::int32_t toggleSupergroupHasAggressiveAntiSpamEnabled::ID;

void toggleSupergroupHasAggressiveAntiSpamEnabled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupHasAggressiveAntiSpamEnabled");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("has_aggressive_anti_spam_enabled", has_aggressive_anti_spam_enabled_);
    s.store_class_end();
  }
}

toggleSupergroupIsAllHistoryAvailable::toggleSupergroupIsAllHistoryAvailable()
  : supergroup_id_()
  , is_all_history_available_()
{}

toggleSupergroupIsAllHistoryAvailable::toggleSupergroupIsAllHistoryAvailable(int53 supergroup_id_, bool is_all_history_available_)
  : supergroup_id_(supergroup_id_)
  , is_all_history_available_(is_all_history_available_)
{}

const std::int32_t toggleSupergroupIsAllHistoryAvailable::ID;

void toggleSupergroupIsAllHistoryAvailable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupIsAllHistoryAvailable");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("is_all_history_available", is_all_history_available_);
    s.store_class_end();
  }
}

validateOrderInfo::validateOrderInfo()
  : input_invoice_()
  , order_info_()
  , allow_save_()
{}

validateOrderInfo::validateOrderInfo(object_ptr<InputInvoice> &&input_invoice_, object_ptr<orderInfo> &&order_info_, bool allow_save_)
  : input_invoice_(std::move(input_invoice_))
  , order_info_(std::move(order_info_))
  , allow_save_(allow_save_)
{}

const std::int32_t validateOrderInfo::ID;

void validateOrderInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "validateOrderInfo");
    s.store_object_field("input_invoice", static_cast<const BaseObject *>(input_invoice_.get()));
    s.store_object_field("order_info", static_cast<const BaseObject *>(order_info_.get()));
    s.store_field("allow_save", allow_save_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
