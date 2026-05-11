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


affiliateProgramParameters::affiliateProgramParameters()
  : commission_per_mille_()
  , month_count_()
{}

affiliateProgramParameters::affiliateProgramParameters(int32 commission_per_mille_, int32 month_count_)
  : commission_per_mille_(commission_per_mille_)
  , month_count_(month_count_)
{}

const std::int32_t affiliateProgramParameters::ID;

void affiliateProgramParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "affiliateProgramParameters");
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_field("month_count", month_count_);
    s.store_class_end();
  }
}

attachmentMenuBot::attachmentMenuBot()
  : bot_user_id_()
  , supports_self_chat_()
  , supports_user_chats_()
  , supports_bot_chats_()
  , supports_group_chats_()
  , supports_channel_chats_()
  , request_write_access_()
  , is_added_()
  , show_in_attachment_menu_()
  , show_in_side_menu_()
  , show_disclaimer_in_side_menu_()
  , name_()
  , name_color_()
  , default_icon_()
  , ios_static_icon_()
  , ios_animated_icon_()
  , ios_side_menu_icon_()
  , android_icon_()
  , android_side_menu_icon_()
  , macos_icon_()
  , macos_side_menu_icon_()
  , icon_color_()
  , web_app_placeholder_()
{}

attachmentMenuBot::attachmentMenuBot(int53 bot_user_id_, bool supports_self_chat_, bool supports_user_chats_, bool supports_bot_chats_, bool supports_group_chats_, bool supports_channel_chats_, bool request_write_access_, bool is_added_, bool show_in_attachment_menu_, bool show_in_side_menu_, bool show_disclaimer_in_side_menu_, string const &name_, object_ptr<attachmentMenuBotColor> &&name_color_, object_ptr<file> &&default_icon_, object_ptr<file> &&ios_static_icon_, object_ptr<file> &&ios_animated_icon_, object_ptr<file> &&ios_side_menu_icon_, object_ptr<file> &&android_icon_, object_ptr<file> &&android_side_menu_icon_, object_ptr<file> &&macos_icon_, object_ptr<file> &&macos_side_menu_icon_, object_ptr<attachmentMenuBotColor> &&icon_color_, object_ptr<file> &&web_app_placeholder_)
  : bot_user_id_(bot_user_id_)
  , supports_self_chat_(supports_self_chat_)
  , supports_user_chats_(supports_user_chats_)
  , supports_bot_chats_(supports_bot_chats_)
  , supports_group_chats_(supports_group_chats_)
  , supports_channel_chats_(supports_channel_chats_)
  , request_write_access_(request_write_access_)
  , is_added_(is_added_)
  , show_in_attachment_menu_(show_in_attachment_menu_)
  , show_in_side_menu_(show_in_side_menu_)
  , show_disclaimer_in_side_menu_(show_disclaimer_in_side_menu_)
  , name_(name_)
  , name_color_(std::move(name_color_))
  , default_icon_(std::move(default_icon_))
  , ios_static_icon_(std::move(ios_static_icon_))
  , ios_animated_icon_(std::move(ios_animated_icon_))
  , ios_side_menu_icon_(std::move(ios_side_menu_icon_))
  , android_icon_(std::move(android_icon_))
  , android_side_menu_icon_(std::move(android_side_menu_icon_))
  , macos_icon_(std::move(macos_icon_))
  , macos_side_menu_icon_(std::move(macos_side_menu_icon_))
  , icon_color_(std::move(icon_color_))
  , web_app_placeholder_(std::move(web_app_placeholder_))
{}

const std::int32_t attachmentMenuBot::ID;

void attachmentMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachmentMenuBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("supports_self_chat", supports_self_chat_);
    s.store_field("supports_user_chats", supports_user_chats_);
    s.store_field("supports_bot_chats", supports_bot_chats_);
    s.store_field("supports_group_chats", supports_group_chats_);
    s.store_field("supports_channel_chats", supports_channel_chats_);
    s.store_field("request_write_access", request_write_access_);
    s.store_field("is_added", is_added_);
    s.store_field("show_in_attachment_menu", show_in_attachment_menu_);
    s.store_field("show_in_side_menu", show_in_side_menu_);
    s.store_field("show_disclaimer_in_side_menu", show_disclaimer_in_side_menu_);
    s.store_field("name", name_);
    s.store_object_field("name_color", static_cast<const BaseObject *>(name_color_.get()));
    s.store_object_field("default_icon", static_cast<const BaseObject *>(default_icon_.get()));
    s.store_object_field("ios_static_icon", static_cast<const BaseObject *>(ios_static_icon_.get()));
    s.store_object_field("ios_animated_icon", static_cast<const BaseObject *>(ios_animated_icon_.get()));
    s.store_object_field("ios_side_menu_icon", static_cast<const BaseObject *>(ios_side_menu_icon_.get()));
    s.store_object_field("android_icon", static_cast<const BaseObject *>(android_icon_.get()));
    s.store_object_field("android_side_menu_icon", static_cast<const BaseObject *>(android_side_menu_icon_.get()));
    s.store_object_field("macos_icon", static_cast<const BaseObject *>(macos_icon_.get()));
    s.store_object_field("macos_side_menu_icon", static_cast<const BaseObject *>(macos_side_menu_icon_.get()));
    s.store_object_field("icon_color", static_cast<const BaseObject *>(icon_color_.get()));
    s.store_object_field("web_app_placeholder", static_cast<const BaseObject *>(web_app_placeholder_.get()));
    s.store_class_end();
  }
}

audio::audio()
  : duration_()
  , title_()
  , performer_()
  , file_name_()
  , mime_type_()
  , album_cover_minithumbnail_()
  , album_cover_thumbnail_()
  , external_album_covers_()
  , audio_()
{}

audio::audio(int32 duration_, string const &title_, string const &performer_, string const &file_name_, string const &mime_type_, object_ptr<minithumbnail> &&album_cover_minithumbnail_, object_ptr<thumbnail> &&album_cover_thumbnail_, array<object_ptr<thumbnail>> &&external_album_covers_, object_ptr<file> &&audio_)
  : duration_(duration_)
  , title_(title_)
  , performer_(performer_)
  , file_name_(file_name_)
  , mime_type_(mime_type_)
  , album_cover_minithumbnail_(std::move(album_cover_minithumbnail_))
  , album_cover_thumbnail_(std::move(album_cover_thumbnail_))
  , external_album_covers_(std::move(external_album_covers_))
  , audio_(std::move(audio_))
{}

const std::int32_t audio::ID;

void audio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "audio");
    s.store_field("duration", duration_);
    s.store_field("title", title_);
    s.store_field("performer", performer_);
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_object_field("album_cover_minithumbnail", static_cast<const BaseObject *>(album_cover_minithumbnail_.get()));
    s.store_object_field("album_cover_thumbnail", static_cast<const BaseObject *>(album_cover_thumbnail_.get()));
    { s.store_vector_begin("external_album_covers", external_album_covers_.size()); for (const auto &_value : external_album_covers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_class_end();
  }
}

botVerificationParameters::botVerificationParameters()
  : icon_custom_emoji_id_()
  , organization_name_()
  , default_custom_description_()
  , can_set_custom_description_()
{}

botVerificationParameters::botVerificationParameters(int64 icon_custom_emoji_id_, string const &organization_name_, object_ptr<formattedText> &&default_custom_description_, bool can_set_custom_description_)
  : icon_custom_emoji_id_(icon_custom_emoji_id_)
  , organization_name_(organization_name_)
  , default_custom_description_(std::move(default_custom_description_))
  , can_set_custom_description_(can_set_custom_description_)
{}

const std::int32_t botVerificationParameters::ID;

void botVerificationParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botVerificationParameters");
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_field("organization_name", organization_name_);
    s.store_object_field("default_custom_description", static_cast<const BaseObject *>(default_custom_description_.get()));
    s.store_field("can_set_custom_description", can_set_custom_description_);
    s.store_class_end();
  }
}

botWriteAccessAllowReasonConnectedWebsite::botWriteAccessAllowReasonConnectedWebsite()
  : domain_name_()
{}

botWriteAccessAllowReasonConnectedWebsite::botWriteAccessAllowReasonConnectedWebsite(string const &domain_name_)
  : domain_name_(domain_name_)
{}

const std::int32_t botWriteAccessAllowReasonConnectedWebsite::ID;

void botWriteAccessAllowReasonConnectedWebsite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botWriteAccessAllowReasonConnectedWebsite");
    s.store_field("domain_name", domain_name_);
    s.store_class_end();
  }
}

botWriteAccessAllowReasonAddedToAttachmentMenu::botWriteAccessAllowReasonAddedToAttachmentMenu() {
}

const std::int32_t botWriteAccessAllowReasonAddedToAttachmentMenu::ID;

void botWriteAccessAllowReasonAddedToAttachmentMenu::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botWriteAccessAllowReasonAddedToAttachmentMenu");
    s.store_class_end();
  }
}

botWriteAccessAllowReasonLaunchedWebApp::botWriteAccessAllowReasonLaunchedWebApp()
  : web_app_()
{}

botWriteAccessAllowReasonLaunchedWebApp::botWriteAccessAllowReasonLaunchedWebApp(object_ptr<webApp> &&web_app_)
  : web_app_(std::move(web_app_))
{}

const std::int32_t botWriteAccessAllowReasonLaunchedWebApp::ID;

void botWriteAccessAllowReasonLaunchedWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botWriteAccessAllowReasonLaunchedWebApp");
    s.store_object_field("web_app", static_cast<const BaseObject *>(web_app_.get()));
    s.store_class_end();
  }
}

botWriteAccessAllowReasonAcceptedRequest::botWriteAccessAllowReasonAcceptedRequest() {
}

const std::int32_t botWriteAccessAllowReasonAcceptedRequest::ID;

void botWriteAccessAllowReasonAcceptedRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botWriteAccessAllowReasonAcceptedRequest");
    s.store_class_end();
  }
}

businessBotRights::businessBotRights()
  : can_reply_()
  , can_read_messages_()
  , can_delete_sent_messages_()
  , can_delete_all_messages_()
  , can_edit_name_()
  , can_edit_bio_()
  , can_edit_profile_photo_()
  , can_edit_username_()
  , can_view_gifts_and_stars_()
  , can_sell_gifts_()
  , can_change_gift_settings_()
  , can_transfer_and_upgrade_gifts_()
  , can_transfer_stars_()
  , can_manage_stories_()
{}

businessBotRights::businessBotRights(bool can_reply_, bool can_read_messages_, bool can_delete_sent_messages_, bool can_delete_all_messages_, bool can_edit_name_, bool can_edit_bio_, bool can_edit_profile_photo_, bool can_edit_username_, bool can_view_gifts_and_stars_, bool can_sell_gifts_, bool can_change_gift_settings_, bool can_transfer_and_upgrade_gifts_, bool can_transfer_stars_, bool can_manage_stories_)
  : can_reply_(can_reply_)
  , can_read_messages_(can_read_messages_)
  , can_delete_sent_messages_(can_delete_sent_messages_)
  , can_delete_all_messages_(can_delete_all_messages_)
  , can_edit_name_(can_edit_name_)
  , can_edit_bio_(can_edit_bio_)
  , can_edit_profile_photo_(can_edit_profile_photo_)
  , can_edit_username_(can_edit_username_)
  , can_view_gifts_and_stars_(can_view_gifts_and_stars_)
  , can_sell_gifts_(can_sell_gifts_)
  , can_change_gift_settings_(can_change_gift_settings_)
  , can_transfer_and_upgrade_gifts_(can_transfer_and_upgrade_gifts_)
  , can_transfer_stars_(can_transfer_stars_)
  , can_manage_stories_(can_manage_stories_)
{}

const std::int32_t businessBotRights::ID;

void businessBotRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessBotRights");
    s.store_field("can_reply", can_reply_);
    s.store_field("can_read_messages", can_read_messages_);
    s.store_field("can_delete_sent_messages", can_delete_sent_messages_);
    s.store_field("can_delete_all_messages", can_delete_all_messages_);
    s.store_field("can_edit_name", can_edit_name_);
    s.store_field("can_edit_bio", can_edit_bio_);
    s.store_field("can_edit_profile_photo", can_edit_profile_photo_);
    s.store_field("can_edit_username", can_edit_username_);
    s.store_field("can_view_gifts_and_stars", can_view_gifts_and_stars_);
    s.store_field("can_sell_gifts", can_sell_gifts_);
    s.store_field("can_change_gift_settings", can_change_gift_settings_);
    s.store_field("can_transfer_and_upgrade_gifts", can_transfer_and_upgrade_gifts_);
    s.store_field("can_transfer_stars", can_transfer_stars_);
    s.store_field("can_manage_stories", can_manage_stories_);
    s.store_class_end();
  }
}

businessInfo::businessInfo()
  : location_()
  , opening_hours_()
  , local_opening_hours_()
  , next_open_in_()
  , next_close_in_()
  , greeting_message_settings_()
  , away_message_settings_()
  , start_page_()
{}

businessInfo::businessInfo(object_ptr<businessLocation> &&location_, object_ptr<businessOpeningHours> &&opening_hours_, object_ptr<businessOpeningHours> &&local_opening_hours_, int32 next_open_in_, int32 next_close_in_, object_ptr<businessGreetingMessageSettings> &&greeting_message_settings_, object_ptr<businessAwayMessageSettings> &&away_message_settings_, object_ptr<businessStartPage> &&start_page_)
  : location_(std::move(location_))
  , opening_hours_(std::move(opening_hours_))
  , local_opening_hours_(std::move(local_opening_hours_))
  , next_open_in_(next_open_in_)
  , next_close_in_(next_close_in_)
  , greeting_message_settings_(std::move(greeting_message_settings_))
  , away_message_settings_(std::move(away_message_settings_))
  , start_page_(std::move(start_page_))
{}

const std::int32_t businessInfo::ID;

void businessInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessInfo");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_object_field("opening_hours", static_cast<const BaseObject *>(opening_hours_.get()));
    s.store_object_field("local_opening_hours", static_cast<const BaseObject *>(local_opening_hours_.get()));
    s.store_field("next_open_in", next_open_in_);
    s.store_field("next_close_in", next_close_in_);
    s.store_object_field("greeting_message_settings", static_cast<const BaseObject *>(greeting_message_settings_.get()));
    s.store_object_field("away_message_settings", static_cast<const BaseObject *>(away_message_settings_.get()));
    s.store_object_field("start_page", static_cast<const BaseObject *>(start_page_.get()));
    s.store_class_end();
  }
}

businessStartPage::businessStartPage()
  : title_()
  , message_()
  , sticker_()
{}

businessStartPage::businessStartPage(string const &title_, string const &message_, object_ptr<sticker> &&sticker_)
  : title_(title_)
  , message_(message_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t businessStartPage::ID;

void businessStartPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessStartPage");
    s.store_field("title", title_);
    s.store_field("message", message_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

chatBoostLinkInfo::chatBoostLinkInfo()
  : is_public_()
  , chat_id_()
{}

chatBoostLinkInfo::chatBoostLinkInfo(bool is_public_, int53 chat_id_)
  : is_public_(is_public_)
  , chat_id_(chat_id_)
{}

const std::int32_t chatBoostLinkInfo::ID;

void chatBoostLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostLinkInfo");
    s.store_field("is_public", is_public_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

chatFolderInviteLink::chatFolderInviteLink()
  : invite_link_()
  , name_()
  , chat_ids_()
{}

chatFolderInviteLink::chatFolderInviteLink(string const &invite_link_, string const &name_, array<int53> &&chat_ids_)
  : invite_link_(invite_link_)
  , name_(name_)
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t chatFolderInviteLink::ID;

void chatFolderInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolderInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_field("name", name_);
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatFolderName::chatFolderName()
  : text_()
  , animate_custom_emoji_()
{}

chatFolderName::chatFolderName(object_ptr<formattedText> &&text_, bool animate_custom_emoji_)
  : text_(std::move(text_))
  , animate_custom_emoji_(animate_custom_emoji_)
{}

const std::int32_t chatFolderName::ID;

void chatFolderName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolderName");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("animate_custom_emoji", animate_custom_emoji_);
    s.store_class_end();
  }
}

chatPhotoInfo::chatPhotoInfo()
  : small_()
  , big_()
  , minithumbnail_()
  , has_animation_()
  , is_personal_()
{}

chatPhotoInfo::chatPhotoInfo(object_ptr<file> &&small_, object_ptr<file> &&big_, object_ptr<minithumbnail> &&minithumbnail_, bool has_animation_, bool is_personal_)
  : small_(std::move(small_))
  , big_(std::move(big_))
  , minithumbnail_(std::move(minithumbnail_))
  , has_animation_(has_animation_)
  , is_personal_(is_personal_)
{}

const std::int32_t chatPhotoInfo::ID;

void chatPhotoInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotoInfo");
    s.store_object_field("small", static_cast<const BaseObject *>(small_.get()));
    s.store_object_field("big", static_cast<const BaseObject *>(big_.get()));
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_field("has_animation", has_animation_);
    s.store_field("is_personal", is_personal_);
    s.store_class_end();
  }
}

dateTimeFormattingTypeRelative::dateTimeFormattingTypeRelative() {
}

const std::int32_t dateTimeFormattingTypeRelative::ID;

void dateTimeFormattingTypeRelative::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateTimeFormattingTypeRelative");
    s.store_class_end();
  }
}

dateTimeFormattingTypeAbsolute::dateTimeFormattingTypeAbsolute()
  : time_precision_()
  , date_precision_()
  , show_day_of_week_()
{}

dateTimeFormattingTypeAbsolute::dateTimeFormattingTypeAbsolute(object_ptr<DateTimePartPrecision> &&time_precision_, object_ptr<DateTimePartPrecision> &&date_precision_, bool show_day_of_week_)
  : time_precision_(std::move(time_precision_))
  , date_precision_(std::move(date_precision_))
  , show_day_of_week_(show_day_of_week_)
{}

const std::int32_t dateTimeFormattingTypeAbsolute::ID;

void dateTimeFormattingTypeAbsolute::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dateTimeFormattingTypeAbsolute");
    s.store_object_field("time_precision", static_cast<const BaseObject *>(time_precision_.get()));
    s.store_object_field("date_precision", static_cast<const BaseObject *>(date_precision_.get()));
    s.store_field("show_day_of_week", show_day_of_week_);
    s.store_class_end();
  }
}

diceStickersRegular::diceStickersRegular()
  : sticker_()
{}

diceStickersRegular::diceStickersRegular(object_ptr<sticker> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t diceStickersRegular::ID;

void diceStickersRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diceStickersRegular");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

diceStickersSlotMachine::diceStickersSlotMachine()
  : background_()
  , lever_()
  , left_reel_()
  , center_reel_()
  , right_reel_()
{}

diceStickersSlotMachine::diceStickersSlotMachine(object_ptr<sticker> &&background_, object_ptr<sticker> &&lever_, object_ptr<sticker> &&left_reel_, object_ptr<sticker> &&center_reel_, object_ptr<sticker> &&right_reel_)
  : background_(std::move(background_))
  , lever_(std::move(lever_))
  , left_reel_(std::move(left_reel_))
  , center_reel_(std::move(center_reel_))
  , right_reel_(std::move(right_reel_))
{}

const std::int32_t diceStickersSlotMachine::ID;

void diceStickersSlotMachine::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "diceStickersSlotMachine");
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("lever", static_cast<const BaseObject *>(lever_.get()));
    s.store_object_field("left_reel", static_cast<const BaseObject *>(left_reel_.get()));
    s.store_object_field("center_reel", static_cast<const BaseObject *>(center_reel_.get()));
    s.store_object_field("right_reel", static_cast<const BaseObject *>(right_reel_.get()));
    s.store_class_end();
  }
}

foundPositions::foundPositions()
  : total_count_()
  , positions_()
{}

foundPositions::foundPositions(int32 total_count_, array<int32> &&positions_)
  : total_count_(total_count_)
  , positions_(std::move(positions_))
{}

const std::int32_t foundPositions::ID;

void foundPositions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundPositions");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

foundStories::foundStories()
  : total_count_()
  , stories_()
  , next_offset_()
{}

foundStories::foundStories(int32 total_count_, array<object_ptr<story>> &&stories_, string const &next_offset_)
  : total_count_(total_count_)
  , stories_(std::move(stories_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundStories::ID;

void foundStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundStories");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

gameHighScores::gameHighScores()
  : scores_()
{}

gameHighScores::gameHighScores(array<object_ptr<gameHighScore>> &&scores_)
  : scores_(std::move(scores_))
{}

const std::int32_t gameHighScores::ID;

void gameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "gameHighScores");
    { s.store_vector_begin("scores", scores_.size()); for (const auto &_value : scores_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

groupCallInfo::groupCallInfo()
  : group_call_id_()
  , join_payload_()
{}

groupCallInfo::groupCallInfo(int32 group_call_id_, string const &join_payload_)
  : group_call_id_(group_call_id_)
  , join_payload_(join_payload_)
{}

const std::int32_t groupCallInfo::ID;

void groupCallInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallInfo");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("join_payload", join_payload_);
    s.store_class_end();
  }
}

groupCallVideoQualityThumbnail::groupCallVideoQualityThumbnail() {
}

const std::int32_t groupCallVideoQualityThumbnail::ID;

void groupCallVideoQualityThumbnail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallVideoQualityThumbnail");
    s.store_class_end();
  }
}

groupCallVideoQualityMedium::groupCallVideoQualityMedium() {
}

const std::int32_t groupCallVideoQualityMedium::ID;

void groupCallVideoQualityMedium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallVideoQualityMedium");
    s.store_class_end();
  }
}

groupCallVideoQualityFull::groupCallVideoQualityFull() {
}

const std::int32_t groupCallVideoQualityFull::ID;

void groupCallVideoQualityFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallVideoQualityFull");
    s.store_class_end();
  }
}

inputCallDiscarded::inputCallDiscarded()
  : call_id_()
{}

inputCallDiscarded::inputCallDiscarded(int32 call_id_)
  : call_id_(call_id_)
{}

const std::int32_t inputCallDiscarded::ID;

void inputCallDiscarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCallDiscarded");
    s.store_field("call_id", call_id_);
    s.store_class_end();
  }
}

inputCallFromMessage::inputCallFromMessage()
  : chat_id_()
  , message_id_()
{}

inputCallFromMessage::inputCallFromMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t inputCallFromMessage::ID;

void inputCallFromMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCallFromMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

inputCredentialsSaved::inputCredentialsSaved()
  : saved_credentials_id_()
{}

inputCredentialsSaved::inputCredentialsSaved(string const &saved_credentials_id_)
  : saved_credentials_id_(saved_credentials_id_)
{}

const std::int32_t inputCredentialsSaved::ID;

void inputCredentialsSaved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCredentialsSaved");
    s.store_field("saved_credentials_id", saved_credentials_id_);
    s.store_class_end();
  }
}

inputCredentialsNew::inputCredentialsNew()
  : data_()
  , allow_save_()
{}

inputCredentialsNew::inputCredentialsNew(string const &data_, bool allow_save_)
  : data_(data_)
  , allow_save_(allow_save_)
{}

const std::int32_t inputCredentialsNew::ID;

void inputCredentialsNew::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCredentialsNew");
    s.store_field("data", data_);
    s.store_field("allow_save", allow_save_);
    s.store_class_end();
  }
}

inputCredentialsApplePay::inputCredentialsApplePay()
  : data_()
{}

inputCredentialsApplePay::inputCredentialsApplePay(string const &data_)
  : data_(data_)
{}

const std::int32_t inputCredentialsApplePay::ID;

void inputCredentialsApplePay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCredentialsApplePay");
    s.store_field("data", data_);
    s.store_class_end();
  }
}

inputCredentialsGooglePay::inputCredentialsGooglePay()
  : data_()
{}

inputCredentialsGooglePay::inputCredentialsGooglePay(string const &data_)
  : data_(data_)
{}

const std::int32_t inputCredentialsGooglePay::ID;

void inputCredentialsGooglePay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCredentialsGooglePay");
    s.store_field("data", data_);
    s.store_class_end();
  }
}

inputGroupCallLink::inputGroupCallLink()
  : link_()
{}

inputGroupCallLink::inputGroupCallLink(string const &link_)
  : link_(link_)
{}

const std::int32_t inputGroupCallLink::ID;

void inputGroupCallLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGroupCallLink");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

inputGroupCallMessage::inputGroupCallMessage()
  : chat_id_()
  , message_id_()
{}

inputGroupCallMessage::inputGroupCallMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t inputGroupCallMessage::ID;

void inputGroupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGroupCallMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

inputPaidMedia::inputPaidMedia()
  : type_()
  , media_()
  , thumbnail_()
  , added_sticker_file_ids_()
  , width_()
  , height_()
{}

inputPaidMedia::inputPaidMedia(object_ptr<InputPaidMediaType> &&type_, object_ptr<InputFile> &&media_, object_ptr<inputThumbnail> &&thumbnail_, array<int32> &&added_sticker_file_ids_, int32 width_, int32 height_)
  : type_(std::move(type_))
  , media_(std::move(media_))
  , thumbnail_(std::move(thumbnail_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , width_(width_)
  , height_(height_)
{}

const std::int32_t inputPaidMedia::ID;

void inputPaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaidMedia");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_class_end();
  }
}

internalLinkTypeAttachmentMenuBot::internalLinkTypeAttachmentMenuBot()
  : target_chat_()
  , bot_username_()
  , url_()
{}

internalLinkTypeAttachmentMenuBot::internalLinkTypeAttachmentMenuBot(object_ptr<TargetChat> &&target_chat_, string const &bot_username_, string const &url_)
  : target_chat_(std::move(target_chat_))
  , bot_username_(bot_username_)
  , url_(url_)
{}

const std::int32_t internalLinkTypeAttachmentMenuBot::ID;

void internalLinkTypeAttachmentMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeAttachmentMenuBot");
    s.store_object_field("target_chat", static_cast<const BaseObject *>(target_chat_.get()));
    s.store_field("bot_username", bot_username_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

internalLinkTypeAuthenticationCode::internalLinkTypeAuthenticationCode()
  : code_()
{}

internalLinkTypeAuthenticationCode::internalLinkTypeAuthenticationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t internalLinkTypeAuthenticationCode::ID;

void internalLinkTypeAuthenticationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeAuthenticationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

internalLinkTypeBackground::internalLinkTypeBackground()
  : background_name_()
{}

internalLinkTypeBackground::internalLinkTypeBackground(string const &background_name_)
  : background_name_(background_name_)
{}

const std::int32_t internalLinkTypeBackground::ID;

void internalLinkTypeBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBackground");
    s.store_field("background_name", background_name_);
    s.store_class_end();
  }
}

internalLinkTypeBotAddToChannel::internalLinkTypeBotAddToChannel()
  : bot_username_()
  , administrator_rights_()
{}

internalLinkTypeBotAddToChannel::internalLinkTypeBotAddToChannel(string const &bot_username_, object_ptr<chatAdministratorRights> &&administrator_rights_)
  : bot_username_(bot_username_)
  , administrator_rights_(std::move(administrator_rights_))
{}

const std::int32_t internalLinkTypeBotAddToChannel::ID;

void internalLinkTypeBotAddToChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBotAddToChannel");
    s.store_field("bot_username", bot_username_);
    s.store_object_field("administrator_rights", static_cast<const BaseObject *>(administrator_rights_.get()));
    s.store_class_end();
  }
}

internalLinkTypeBotStart::internalLinkTypeBotStart()
  : bot_username_()
  , start_parameter_()
  , autostart_()
{}

internalLinkTypeBotStart::internalLinkTypeBotStart(string const &bot_username_, string const &start_parameter_, bool autostart_)
  : bot_username_(bot_username_)
  , start_parameter_(start_parameter_)
  , autostart_(autostart_)
{}

const std::int32_t internalLinkTypeBotStart::ID;

void internalLinkTypeBotStart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBotStart");
    s.store_field("bot_username", bot_username_);
    s.store_field("start_parameter", start_parameter_);
    s.store_field("autostart", autostart_);
    s.store_class_end();
  }
}

internalLinkTypeBotStartInGroup::internalLinkTypeBotStartInGroup()
  : bot_username_()
  , start_parameter_()
  , administrator_rights_()
{}

internalLinkTypeBotStartInGroup::internalLinkTypeBotStartInGroup(string const &bot_username_, string const &start_parameter_, object_ptr<chatAdministratorRights> &&administrator_rights_)
  : bot_username_(bot_username_)
  , start_parameter_(start_parameter_)
  , administrator_rights_(std::move(administrator_rights_))
{}

const std::int32_t internalLinkTypeBotStartInGroup::ID;

void internalLinkTypeBotStartInGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBotStartInGroup");
    s.store_field("bot_username", bot_username_);
    s.store_field("start_parameter", start_parameter_);
    s.store_object_field("administrator_rights", static_cast<const BaseObject *>(administrator_rights_.get()));
    s.store_class_end();
  }
}

internalLinkTypeBusinessChat::internalLinkTypeBusinessChat()
  : link_name_()
{}

internalLinkTypeBusinessChat::internalLinkTypeBusinessChat(string const &link_name_)
  : link_name_(link_name_)
{}

const std::int32_t internalLinkTypeBusinessChat::ID;

void internalLinkTypeBusinessChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeBusinessChat");
    s.store_field("link_name", link_name_);
    s.store_class_end();
  }
}

internalLinkTypeCallsPage::internalLinkTypeCallsPage()
  : section_()
{}

internalLinkTypeCallsPage::internalLinkTypeCallsPage(string const &section_)
  : section_(section_)
{}

const std::int32_t internalLinkTypeCallsPage::ID;

void internalLinkTypeCallsPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeCallsPage");
    s.store_field("section", section_);
    s.store_class_end();
  }
}

internalLinkTypeChatAffiliateProgram::internalLinkTypeChatAffiliateProgram()
  : username_()
  , referrer_()
{}

internalLinkTypeChatAffiliateProgram::internalLinkTypeChatAffiliateProgram(string const &username_, string const &referrer_)
  : username_(username_)
  , referrer_(referrer_)
{}

const std::int32_t internalLinkTypeChatAffiliateProgram::ID;

void internalLinkTypeChatAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeChatAffiliateProgram");
    s.store_field("username", username_);
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

internalLinkTypeChatBoost::internalLinkTypeChatBoost()
  : url_()
{}

internalLinkTypeChatBoost::internalLinkTypeChatBoost(string const &url_)
  : url_(url_)
{}

const std::int32_t internalLinkTypeChatBoost::ID;

void internalLinkTypeChatBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeChatBoost");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

internalLinkTypeChatFolderInvite::internalLinkTypeChatFolderInvite()
  : invite_link_()
{}

internalLinkTypeChatFolderInvite::internalLinkTypeChatFolderInvite(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t internalLinkTypeChatFolderInvite::ID;

void internalLinkTypeChatFolderInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeChatFolderInvite");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

internalLinkTypeChatInvite::internalLinkTypeChatInvite()
  : invite_link_()
{}

internalLinkTypeChatInvite::internalLinkTypeChatInvite(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t internalLinkTypeChatInvite::ID;

void internalLinkTypeChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeChatInvite");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

internalLinkTypeChatSelection::internalLinkTypeChatSelection() {
}

const std::int32_t internalLinkTypeChatSelection::ID;

void internalLinkTypeChatSelection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeChatSelection");
    s.store_class_end();
  }
}

internalLinkTypeContactsPage::internalLinkTypeContactsPage()
  : section_()
{}

internalLinkTypeContactsPage::internalLinkTypeContactsPage(string const &section_)
  : section_(section_)
{}

const std::int32_t internalLinkTypeContactsPage::ID;

void internalLinkTypeContactsPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeContactsPage");
    s.store_field("section", section_);
    s.store_class_end();
  }
}

internalLinkTypeDirectMessagesChat::internalLinkTypeDirectMessagesChat()
  : channel_username_()
{}

internalLinkTypeDirectMessagesChat::internalLinkTypeDirectMessagesChat(string const &channel_username_)
  : channel_username_(channel_username_)
{}

const std::int32_t internalLinkTypeDirectMessagesChat::ID;

void internalLinkTypeDirectMessagesChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeDirectMessagesChat");
    s.store_field("channel_username", channel_username_);
    s.store_class_end();
  }
}

internalLinkTypeGame::internalLinkTypeGame()
  : bot_username_()
  , game_short_name_()
{}

internalLinkTypeGame::internalLinkTypeGame(string const &bot_username_, string const &game_short_name_)
  : bot_username_(bot_username_)
  , game_short_name_(game_short_name_)
{}

const std::int32_t internalLinkTypeGame::ID;

void internalLinkTypeGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeGame");
    s.store_field("bot_username", bot_username_);
    s.store_field("game_short_name", game_short_name_);
    s.store_class_end();
  }
}

internalLinkTypeGiftAuction::internalLinkTypeGiftAuction()
  : auction_id_()
{}

internalLinkTypeGiftAuction::internalLinkTypeGiftAuction(string const &auction_id_)
  : auction_id_(auction_id_)
{}

const std::int32_t internalLinkTypeGiftAuction::ID;

void internalLinkTypeGiftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeGiftAuction");
    s.store_field("auction_id", auction_id_);
    s.store_class_end();
  }
}

internalLinkTypeGiftCollection::internalLinkTypeGiftCollection()
  : gift_owner_username_()
  , collection_id_()
{}

internalLinkTypeGiftCollection::internalLinkTypeGiftCollection(string const &gift_owner_username_, int32 collection_id_)
  : gift_owner_username_(gift_owner_username_)
  , collection_id_(collection_id_)
{}

const std::int32_t internalLinkTypeGiftCollection::ID;

void internalLinkTypeGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeGiftCollection");
    s.store_field("gift_owner_username", gift_owner_username_);
    s.store_field("collection_id", collection_id_);
    s.store_class_end();
  }
}

internalLinkTypeGroupCall::internalLinkTypeGroupCall()
  : invite_link_()
{}

internalLinkTypeGroupCall::internalLinkTypeGroupCall(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t internalLinkTypeGroupCall::ID;

void internalLinkTypeGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeGroupCall");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

internalLinkTypeInstantView::internalLinkTypeInstantView()
  : url_()
  , fallback_url_()
{}

internalLinkTypeInstantView::internalLinkTypeInstantView(string const &url_, string const &fallback_url_)
  : url_(url_)
  , fallback_url_(fallback_url_)
{}

const std::int32_t internalLinkTypeInstantView::ID;

void internalLinkTypeInstantView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeInstantView");
    s.store_field("url", url_);
    s.store_field("fallback_url", fallback_url_);
    s.store_class_end();
  }
}

internalLinkTypeInvoice::internalLinkTypeInvoice()
  : invoice_name_()
{}

internalLinkTypeInvoice::internalLinkTypeInvoice(string const &invoice_name_)
  : invoice_name_(invoice_name_)
{}

const std::int32_t internalLinkTypeInvoice::ID;

void internalLinkTypeInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeInvoice");
    s.store_field("invoice_name", invoice_name_);
    s.store_class_end();
  }
}

internalLinkTypeLanguagePack::internalLinkTypeLanguagePack()
  : language_pack_id_()
{}

internalLinkTypeLanguagePack::internalLinkTypeLanguagePack(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t internalLinkTypeLanguagePack::ID;

void internalLinkTypeLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeLanguagePack");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

internalLinkTypeLiveStory::internalLinkTypeLiveStory()
  : story_poster_username_()
{}

internalLinkTypeLiveStory::internalLinkTypeLiveStory(string const &story_poster_username_)
  : story_poster_username_(story_poster_username_)
{}

const std::int32_t internalLinkTypeLiveStory::ID;

void internalLinkTypeLiveStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeLiveStory");
    s.store_field("story_poster_username", story_poster_username_);
    s.store_class_end();
  }
}

internalLinkTypeMainWebApp::internalLinkTypeMainWebApp()
  : bot_username_()
  , start_parameter_()
  , mode_()
{}

internalLinkTypeMainWebApp::internalLinkTypeMainWebApp(string const &bot_username_, string const &start_parameter_, object_ptr<WebAppOpenMode> &&mode_)
  : bot_username_(bot_username_)
  , start_parameter_(start_parameter_)
  , mode_(std::move(mode_))
{}

const std::int32_t internalLinkTypeMainWebApp::ID;

void internalLinkTypeMainWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeMainWebApp");
    s.store_field("bot_username", bot_username_);
    s.store_field("start_parameter", start_parameter_);
    s.store_object_field("mode", static_cast<const BaseObject *>(mode_.get()));
    s.store_class_end();
  }
}

internalLinkTypeMessage::internalLinkTypeMessage()
  : url_()
{}

internalLinkTypeMessage::internalLinkTypeMessage(string const &url_)
  : url_(url_)
{}

const std::int32_t internalLinkTypeMessage::ID;

void internalLinkTypeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeMessage");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

internalLinkTypeMessageDraft::internalLinkTypeMessageDraft()
  : text_()
  , contains_link_()
{}

internalLinkTypeMessageDraft::internalLinkTypeMessageDraft(object_ptr<formattedText> &&text_, bool contains_link_)
  : text_(std::move(text_))
  , contains_link_(contains_link_)
{}

const std::int32_t internalLinkTypeMessageDraft::ID;

void internalLinkTypeMessageDraft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeMessageDraft");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("contains_link", contains_link_);
    s.store_class_end();
  }
}

internalLinkTypeMyProfilePage::internalLinkTypeMyProfilePage()
  : section_()
{}

internalLinkTypeMyProfilePage::internalLinkTypeMyProfilePage(string const &section_)
  : section_(section_)
{}

const std::int32_t internalLinkTypeMyProfilePage::ID;

void internalLinkTypeMyProfilePage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeMyProfilePage");
    s.store_field("section", section_);
    s.store_class_end();
  }
}

internalLinkTypeNewChannelChat::internalLinkTypeNewChannelChat() {
}

const std::int32_t internalLinkTypeNewChannelChat::ID;

void internalLinkTypeNewChannelChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeNewChannelChat");
    s.store_class_end();
  }
}

internalLinkTypeNewGroupChat::internalLinkTypeNewGroupChat() {
}

const std::int32_t internalLinkTypeNewGroupChat::ID;

void internalLinkTypeNewGroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeNewGroupChat");
    s.store_class_end();
  }
}

internalLinkTypeNewPrivateChat::internalLinkTypeNewPrivateChat() {
}

const std::int32_t internalLinkTypeNewPrivateChat::ID;

void internalLinkTypeNewPrivateChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeNewPrivateChat");
    s.store_class_end();
  }
}

internalLinkTypeNewStory::internalLinkTypeNewStory()
  : content_type_()
{}

internalLinkTypeNewStory::internalLinkTypeNewStory(object_ptr<StoryContentType> &&content_type_)
  : content_type_(std::move(content_type_))
{}

const std::int32_t internalLinkTypeNewStory::ID;

void internalLinkTypeNewStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeNewStory");
    s.store_object_field("content_type", static_cast<const BaseObject *>(content_type_.get()));
    s.store_class_end();
  }
}

internalLinkTypeOauth::internalLinkTypeOauth()
  : url_()
{}

internalLinkTypeOauth::internalLinkTypeOauth(string const &url_)
  : url_(url_)
{}

const std::int32_t internalLinkTypeOauth::ID;

void internalLinkTypeOauth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeOauth");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

internalLinkTypePassportDataRequest::internalLinkTypePassportDataRequest()
  : bot_user_id_()
  , scope_()
  , public_key_()
  , nonce_()
  , callback_url_()
{}

internalLinkTypePassportDataRequest::internalLinkTypePassportDataRequest(int53 bot_user_id_, string const &scope_, string const &public_key_, string const &nonce_, string const &callback_url_)
  : bot_user_id_(bot_user_id_)
  , scope_(scope_)
  , public_key_(public_key_)
  , nonce_(nonce_)
  , callback_url_(callback_url_)
{}

const std::int32_t internalLinkTypePassportDataRequest::ID;

void internalLinkTypePassportDataRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePassportDataRequest");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("scope", scope_);
    s.store_field("public_key", public_key_);
    s.store_field("nonce", nonce_);
    s.store_field("callback_url", callback_url_);
    s.store_class_end();
  }
}

internalLinkTypePhoneNumberConfirmation::internalLinkTypePhoneNumberConfirmation()
  : hash_()
  , phone_number_()
{}

internalLinkTypePhoneNumberConfirmation::internalLinkTypePhoneNumberConfirmation(string const &hash_, string const &phone_number_)
  : hash_(hash_)
  , phone_number_(phone_number_)
{}

const std::int32_t internalLinkTypePhoneNumberConfirmation::ID;

void internalLinkTypePhoneNumberConfirmation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePhoneNumberConfirmation");
    s.store_field("hash", hash_);
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

internalLinkTypePremiumFeaturesPage::internalLinkTypePremiumFeaturesPage()
  : referrer_()
{}

internalLinkTypePremiumFeaturesPage::internalLinkTypePremiumFeaturesPage(string const &referrer_)
  : referrer_(referrer_)
{}

const std::int32_t internalLinkTypePremiumFeaturesPage::ID;

void internalLinkTypePremiumFeaturesPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePremiumFeaturesPage");
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

internalLinkTypePremiumGiftCode::internalLinkTypePremiumGiftCode()
  : code_()
{}

internalLinkTypePremiumGiftCode::internalLinkTypePremiumGiftCode(string const &code_)
  : code_(code_)
{}

const std::int32_t internalLinkTypePremiumGiftCode::ID;

void internalLinkTypePremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePremiumGiftCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

internalLinkTypePremiumGiftPurchase::internalLinkTypePremiumGiftPurchase()
  : referrer_()
{}

internalLinkTypePremiumGiftPurchase::internalLinkTypePremiumGiftPurchase(string const &referrer_)
  : referrer_(referrer_)
{}

const std::int32_t internalLinkTypePremiumGiftPurchase::ID;

void internalLinkTypePremiumGiftPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePremiumGiftPurchase");
    s.store_field("referrer", referrer_);
    s.store_class_end();
  }
}

internalLinkTypeProxy::internalLinkTypeProxy()
  : proxy_()
{}

internalLinkTypeProxy::internalLinkTypeProxy(object_ptr<proxy> &&proxy_)
  : proxy_(std::move(proxy_))
{}

const std::int32_t internalLinkTypeProxy::ID;

void internalLinkTypeProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeProxy");
    s.store_object_field("proxy", static_cast<const BaseObject *>(proxy_.get()));
    s.store_class_end();
  }
}

internalLinkTypePublicChat::internalLinkTypePublicChat()
  : chat_username_()
  , draft_text_()
  , open_profile_()
{}

internalLinkTypePublicChat::internalLinkTypePublicChat(string const &chat_username_, string const &draft_text_, bool open_profile_)
  : chat_username_(chat_username_)
  , draft_text_(draft_text_)
  , open_profile_(open_profile_)
{}

const std::int32_t internalLinkTypePublicChat::ID;

void internalLinkTypePublicChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypePublicChat");
    s.store_field("chat_username", chat_username_);
    s.store_field("draft_text", draft_text_);
    s.store_field("open_profile", open_profile_);
    s.store_class_end();
  }
}

internalLinkTypeQrCodeAuthentication::internalLinkTypeQrCodeAuthentication() {
}

const std::int32_t internalLinkTypeQrCodeAuthentication::ID;

void internalLinkTypeQrCodeAuthentication::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeQrCodeAuthentication");
    s.store_class_end();
  }
}

internalLinkTypeRequestManagedBot::internalLinkTypeRequestManagedBot()
  : manager_bot_username_()
  , suggested_bot_username_()
  , suggested_bot_name_()
{}

internalLinkTypeRequestManagedBot::internalLinkTypeRequestManagedBot(string const &manager_bot_username_, string const &suggested_bot_username_, string const &suggested_bot_name_)
  : manager_bot_username_(manager_bot_username_)
  , suggested_bot_username_(suggested_bot_username_)
  , suggested_bot_name_(suggested_bot_name_)
{}

const std::int32_t internalLinkTypeRequestManagedBot::ID;

void internalLinkTypeRequestManagedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeRequestManagedBot");
    s.store_field("manager_bot_username", manager_bot_username_);
    s.store_field("suggested_bot_username", suggested_bot_username_);
    s.store_field("suggested_bot_name", suggested_bot_name_);
    s.store_class_end();
  }
}

internalLinkTypeRestorePurchases::internalLinkTypeRestorePurchases() {
}

const std::int32_t internalLinkTypeRestorePurchases::ID;

void internalLinkTypeRestorePurchases::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeRestorePurchases");
    s.store_class_end();
  }
}

internalLinkTypeSavedMessages::internalLinkTypeSavedMessages() {
}

const std::int32_t internalLinkTypeSavedMessages::ID;

void internalLinkTypeSavedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeSavedMessages");
    s.store_class_end();
  }
}

internalLinkTypeSearch::internalLinkTypeSearch() {
}

const std::int32_t internalLinkTypeSearch::ID;

void internalLinkTypeSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeSearch");
    s.store_class_end();
  }
}

internalLinkTypeSettings::internalLinkTypeSettings()
  : section_()
{}

internalLinkTypeSettings::internalLinkTypeSettings(object_ptr<SettingsSection> &&section_)
  : section_(std::move(section_))
{}

const std::int32_t internalLinkTypeSettings::ID;

void internalLinkTypeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeSettings");
    s.store_object_field("section", static_cast<const BaseObject *>(section_.get()));
    s.store_class_end();
  }
}

internalLinkTypeStarPurchase::internalLinkTypeStarPurchase()
  : star_count_()
  , purpose_()
{}

internalLinkTypeStarPurchase::internalLinkTypeStarPurchase(int53 star_count_, string const &purpose_)
  : star_count_(star_count_)
  , purpose_(purpose_)
{}

const std::int32_t internalLinkTypeStarPurchase::ID;

void internalLinkTypeStarPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeStarPurchase");
    s.store_field("star_count", star_count_);
    s.store_field("purpose", purpose_);
    s.store_class_end();
  }
}

internalLinkTypeStickerSet::internalLinkTypeStickerSet()
  : sticker_set_name_()
  , expect_custom_emoji_()
{}

internalLinkTypeStickerSet::internalLinkTypeStickerSet(string const &sticker_set_name_, bool expect_custom_emoji_)
  : sticker_set_name_(sticker_set_name_)
  , expect_custom_emoji_(expect_custom_emoji_)
{}

const std::int32_t internalLinkTypeStickerSet::ID;

void internalLinkTypeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeStickerSet");
    s.store_field("sticker_set_name", sticker_set_name_);
    s.store_field("expect_custom_emoji", expect_custom_emoji_);
    s.store_class_end();
  }
}

internalLinkTypeStory::internalLinkTypeStory()
  : story_poster_username_()
  , story_id_()
{}

internalLinkTypeStory::internalLinkTypeStory(string const &story_poster_username_, int32 story_id_)
  : story_poster_username_(story_poster_username_)
  , story_id_(story_id_)
{}

const std::int32_t internalLinkTypeStory::ID;

void internalLinkTypeStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeStory");
    s.store_field("story_poster_username", story_poster_username_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

internalLinkTypeStoryAlbum::internalLinkTypeStoryAlbum()
  : story_album_owner_username_()
  , story_album_id_()
{}

internalLinkTypeStoryAlbum::internalLinkTypeStoryAlbum(string const &story_album_owner_username_, int32 story_album_id_)
  : story_album_owner_username_(story_album_owner_username_)
  , story_album_id_(story_album_id_)
{}

const std::int32_t internalLinkTypeStoryAlbum::ID;

void internalLinkTypeStoryAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeStoryAlbum");
    s.store_field("story_album_owner_username", story_album_owner_username_);
    s.store_field("story_album_id", story_album_id_);
    s.store_class_end();
  }
}

internalLinkTypeTheme::internalLinkTypeTheme()
  : theme_name_()
{}

internalLinkTypeTheme::internalLinkTypeTheme(string const &theme_name_)
  : theme_name_(theme_name_)
{}

const std::int32_t internalLinkTypeTheme::ID;

void internalLinkTypeTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeTheme");
    s.store_field("theme_name", theme_name_);
    s.store_class_end();
  }
}

internalLinkTypeUnknownDeepLink::internalLinkTypeUnknownDeepLink()
  : link_()
{}

internalLinkTypeUnknownDeepLink::internalLinkTypeUnknownDeepLink(string const &link_)
  : link_(link_)
{}

const std::int32_t internalLinkTypeUnknownDeepLink::ID;

void internalLinkTypeUnknownDeepLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeUnknownDeepLink");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

internalLinkTypeUpgradedGift::internalLinkTypeUpgradedGift()
  : name_()
{}

internalLinkTypeUpgradedGift::internalLinkTypeUpgradedGift(string const &name_)
  : name_(name_)
{}

const std::int32_t internalLinkTypeUpgradedGift::ID;

void internalLinkTypeUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeUpgradedGift");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

internalLinkTypeUserPhoneNumber::internalLinkTypeUserPhoneNumber()
  : phone_number_()
  , draft_text_()
  , open_profile_()
{}

internalLinkTypeUserPhoneNumber::internalLinkTypeUserPhoneNumber(string const &phone_number_, string const &draft_text_, bool open_profile_)
  : phone_number_(phone_number_)
  , draft_text_(draft_text_)
  , open_profile_(open_profile_)
{}

const std::int32_t internalLinkTypeUserPhoneNumber::ID;

void internalLinkTypeUserPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeUserPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_field("draft_text", draft_text_);
    s.store_field("open_profile", open_profile_);
    s.store_class_end();
  }
}

internalLinkTypeUserToken::internalLinkTypeUserToken()
  : token_()
{}

internalLinkTypeUserToken::internalLinkTypeUserToken(string const &token_)
  : token_(token_)
{}

const std::int32_t internalLinkTypeUserToken::ID;

void internalLinkTypeUserToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeUserToken");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

internalLinkTypeVideoChat::internalLinkTypeVideoChat()
  : chat_username_()
  , invite_hash_()
  , is_live_stream_()
{}

internalLinkTypeVideoChat::internalLinkTypeVideoChat(string const &chat_username_, string const &invite_hash_, bool is_live_stream_)
  : chat_username_(chat_username_)
  , invite_hash_(invite_hash_)
  , is_live_stream_(is_live_stream_)
{}

const std::int32_t internalLinkTypeVideoChat::ID;

void internalLinkTypeVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeVideoChat");
    s.store_field("chat_username", chat_username_);
    s.store_field("invite_hash", invite_hash_);
    s.store_field("is_live_stream", is_live_stream_);
    s.store_class_end();
  }
}

internalLinkTypeWebApp::internalLinkTypeWebApp()
  : bot_username_()
  , web_app_short_name_()
  , start_parameter_()
  , mode_()
{}

internalLinkTypeWebApp::internalLinkTypeWebApp(string const &bot_username_, string const &web_app_short_name_, string const &start_parameter_, object_ptr<WebAppOpenMode> &&mode_)
  : bot_username_(bot_username_)
  , web_app_short_name_(web_app_short_name_)
  , start_parameter_(start_parameter_)
  , mode_(std::move(mode_))
{}

const std::int32_t internalLinkTypeWebApp::ID;

void internalLinkTypeWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "internalLinkTypeWebApp");
    s.store_field("bot_username", bot_username_);
    s.store_field("web_app_short_name", web_app_short_name_);
    s.store_field("start_parameter", start_parameter_);
    s.store_object_field("mode", static_cast<const BaseObject *>(mode_.get()));
    s.store_class_end();
  }
}

languagePackInfo::languagePackInfo()
  : id_()
  , base_language_pack_id_()
  , name_()
  , native_name_()
  , plural_code_()
  , is_official_()
  , is_rtl_()
  , is_beta_()
  , is_installed_()
  , total_string_count_()
  , translated_string_count_()
  , local_string_count_()
  , translation_url_()
{}

languagePackInfo::languagePackInfo(string const &id_, string const &base_language_pack_id_, string const &name_, string const &native_name_, string const &plural_code_, bool is_official_, bool is_rtl_, bool is_beta_, bool is_installed_, int32 total_string_count_, int32 translated_string_count_, int32 local_string_count_, string const &translation_url_)
  : id_(id_)
  , base_language_pack_id_(base_language_pack_id_)
  , name_(name_)
  , native_name_(native_name_)
  , plural_code_(plural_code_)
  , is_official_(is_official_)
  , is_rtl_(is_rtl_)
  , is_beta_(is_beta_)
  , is_installed_(is_installed_)
  , total_string_count_(total_string_count_)
  , translated_string_count_(translated_string_count_)
  , local_string_count_(local_string_count_)
  , translation_url_(translation_url_)
{}

const std::int32_t languagePackInfo::ID;

void languagePackInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackInfo");
    s.store_field("id", id_);
    s.store_field("base_language_pack_id", base_language_pack_id_);
    s.store_field("name", name_);
    s.store_field("native_name", native_name_);
    s.store_field("plural_code", plural_code_);
    s.store_field("is_official", is_official_);
    s.store_field("is_rtl", is_rtl_);
    s.store_field("is_beta", is_beta_);
    s.store_field("is_installed", is_installed_);
    s.store_field("total_string_count", total_string_count_);
    s.store_field("translated_string_count", translated_string_count_);
    s.store_field("local_string_count", local_string_count_);
    s.store_field("translation_url", translation_url_);
    s.store_class_end();
  }
}

locationAddress::locationAddress()
  : country_code_()
  , state_()
  , city_()
  , street_()
{}

locationAddress::locationAddress(string const &country_code_, string const &state_, string const &city_, string const &street_)
  : country_code_(country_code_)
  , state_(state_)
  , city_(city_)
  , street_(street_)
{}

const std::int32_t locationAddress::ID;

void locationAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "locationAddress");
    s.store_field("country_code", country_code_);
    s.store_field("state", state_);
    s.store_field("city", city_);
    s.store_field("street", street_);
    s.store_class_end();
  }
}

messageAutoDeleteTime::messageAutoDeleteTime()
  : time_()
{}

messageAutoDeleteTime::messageAutoDeleteTime(int32 time_)
  : time_(time_)
{}

const std::int32_t messageAutoDeleteTime::ID;

void messageAutoDeleteTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageAutoDeleteTime");
    s.store_field("time", time_);
    s.store_class_end();
  }
}

messageSenderUser::messageSenderUser()
  : user_id_()
{}

messageSenderUser::messageSenderUser(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t messageSenderUser::ID;

void messageSenderUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSenderUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

messageSenderChat::messageSenderChat()
  : chat_id_()
{}

messageSenderChat::messageSenderChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t messageSenderChat::ID;

void messageSenderChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSenderChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

networkTypeNone::networkTypeNone() {
}

const std::int32_t networkTypeNone::ID;

void networkTypeNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeNone");
    s.store_class_end();
  }
}

networkTypeMobile::networkTypeMobile() {
}

const std::int32_t networkTypeMobile::ID;

void networkTypeMobile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeMobile");
    s.store_class_end();
  }
}

networkTypeMobileRoaming::networkTypeMobileRoaming() {
}

const std::int32_t networkTypeMobileRoaming::ID;

void networkTypeMobileRoaming::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeMobileRoaming");
    s.store_class_end();
  }
}

networkTypeWiFi::networkTypeWiFi() {
}

const std::int32_t networkTypeWiFi::ID;

void networkTypeWiFi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeWiFi");
    s.store_class_end();
  }
}

networkTypeOther::networkTypeOther() {
}

const std::int32_t networkTypeOther::ID;

void networkTypeOther::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkTypeOther");
    s.store_class_end();
  }
}

notificationSettingsScopePrivateChats::notificationSettingsScopePrivateChats() {
}

const std::int32_t notificationSettingsScopePrivateChats::ID;

void notificationSettingsScopePrivateChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSettingsScopePrivateChats");
    s.store_class_end();
  }
}

notificationSettingsScopeGroupChats::notificationSettingsScopeGroupChats() {
}

const std::int32_t notificationSettingsScopeGroupChats::ID;

void notificationSettingsScopeGroupChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSettingsScopeGroupChats");
    s.store_class_end();
  }
}

notificationSettingsScopeChannelChats::notificationSettingsScopeChannelChats() {
}

const std::int32_t notificationSettingsScopeChannelChats::ID;

void notificationSettingsScopeChannelChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSettingsScopeChannelChats");
    s.store_class_end();
  }
}

paymentReceipt::paymentReceipt()
  : product_info_()
  , date_()
  , seller_bot_user_id_()
  , type_()
{}

paymentReceipt::paymentReceipt(object_ptr<productInfo> &&product_info_, int32 date_, int53 seller_bot_user_id_, object_ptr<PaymentReceiptType> &&type_)
  : product_info_(std::move(product_info_))
  , date_(date_)
  , seller_bot_user_id_(seller_bot_user_id_)
  , type_(std::move(type_))
{}

const std::int32_t paymentReceipt::ID;

void paymentReceipt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentReceipt");
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_field("date", date_);
    s.store_field("seller_bot_user_id", seller_bot_user_id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

preparedInlineMessage::preparedInlineMessage()
  : inline_query_id_()
  , result_()
  , chat_types_()
{}

preparedInlineMessage::preparedInlineMessage(int64 inline_query_id_, object_ptr<InlineQueryResult> &&result_, object_ptr<targetChatTypes> &&chat_types_)
  : inline_query_id_(inline_query_id_)
  , result_(std::move(result_))
  , chat_types_(std::move(chat_types_))
{}

const std::int32_t preparedInlineMessage::ID;

void preparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "preparedInlineMessage");
    s.store_field("inline_query_id", inline_query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_object_field("chat_types", static_cast<const BaseObject *>(chat_types_.get()));
    s.store_class_end();
  }
}

profilePhoto::profilePhoto()
  : id_()
  , small_()
  , big_()
  , minithumbnail_()
  , has_animation_()
  , is_personal_()
{}

profilePhoto::profilePhoto(int64 id_, object_ptr<file> &&small_, object_ptr<file> &&big_, object_ptr<minithumbnail> &&minithumbnail_, bool has_animation_, bool is_personal_)
  : id_(id_)
  , small_(std::move(small_))
  , big_(std::move(big_))
  , minithumbnail_(std::move(minithumbnail_))
  , has_animation_(has_animation_)
  , is_personal_(is_personal_)
{}

const std::int32_t profilePhoto::ID;

void profilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profilePhoto");
    s.store_field("id", id_);
    s.store_object_field("small", static_cast<const BaseObject *>(small_.get()));
    s.store_object_field("big", static_cast<const BaseObject *>(big_.get()));
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_field("has_animation", has_animation_);
    s.store_field("is_personal", is_personal_);
    s.store_class_end();
  }
}

proxyTypeSocks5::proxyTypeSocks5()
  : username_()
  , password_()
{}

proxyTypeSocks5::proxyTypeSocks5(string const &username_, string const &password_)
  : username_(username_)
  , password_(password_)
{}

const std::int32_t proxyTypeSocks5::ID;

void proxyTypeSocks5::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxyTypeSocks5");
    s.store_field("username", username_);
    s.store_field("password", password_);
    s.store_class_end();
  }
}

proxyTypeHttp::proxyTypeHttp()
  : username_()
  , password_()
  , http_only_()
{}

proxyTypeHttp::proxyTypeHttp(string const &username_, string const &password_, bool http_only_)
  : username_(username_)
  , password_(password_)
  , http_only_(http_only_)
{}

const std::int32_t proxyTypeHttp::ID;

void proxyTypeHttp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxyTypeHttp");
    s.store_field("username", username_);
    s.store_field("password", password_);
    s.store_field("http_only", http_only_);
    s.store_class_end();
  }
}

proxyTypeMtproto::proxyTypeMtproto()
  : secret_()
{}

proxyTypeMtproto::proxyTypeMtproto(string const &secret_)
  : secret_(secret_)
{}

const std::int32_t proxyTypeMtproto::ID;

void proxyTypeMtproto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "proxyTypeMtproto");
    s.store_field("secret", secret_);
    s.store_class_end();
  }
}

reactionTypeEmoji::reactionTypeEmoji()
  : emoji_()
{}

reactionTypeEmoji::reactionTypeEmoji(string const &emoji_)
  : emoji_(emoji_)
{}

const std::int32_t reactionTypeEmoji::ID;

void reactionTypeEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionTypeEmoji");
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

reactionTypeCustomEmoji::reactionTypeCustomEmoji()
  : custom_emoji_id_()
{}

reactionTypeCustomEmoji::reactionTypeCustomEmoji(int64 custom_emoji_id_)
  : custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t reactionTypeCustomEmoji::ID;

void reactionTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionTypeCustomEmoji");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

reactionTypePaid::reactionTypePaid() {
}

const std::int32_t reactionTypePaid::ID;

void reactionTypePaid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionTypePaid");
    s.store_class_end();
  }
}

reactionUnavailabilityReasonAnonymousAdministrator::reactionUnavailabilityReasonAnonymousAdministrator() {
}

const std::int32_t reactionUnavailabilityReasonAnonymousAdministrator::ID;

void reactionUnavailabilityReasonAnonymousAdministrator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionUnavailabilityReasonAnonymousAdministrator");
    s.store_class_end();
  }
}

reactionUnavailabilityReasonGuest::reactionUnavailabilityReasonGuest() {
}

const std::int32_t reactionUnavailabilityReasonGuest::ID;

void reactionUnavailabilityReasonGuest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionUnavailabilityReasonGuest");
    s.store_class_end();
  }
}

readDatePrivacySettings::readDatePrivacySettings()
  : show_read_date_()
{}

readDatePrivacySettings::readDatePrivacySettings(bool show_read_date_)
  : show_read_date_(show_read_date_)
{}

const std::int32_t readDatePrivacySettings::ID;

void readDatePrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readDatePrivacySettings");
    s.store_field("show_read_date", show_read_date_);
    s.store_class_end();
  }
}

reportSponsoredResultOk::reportSponsoredResultOk() {
}

const std::int32_t reportSponsoredResultOk::ID;

void reportSponsoredResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSponsoredResultOk");
    s.store_class_end();
  }
}

reportSponsoredResultFailed::reportSponsoredResultFailed() {
}

const std::int32_t reportSponsoredResultFailed::ID;

void reportSponsoredResultFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSponsoredResultFailed");
    s.store_class_end();
  }
}

reportSponsoredResultOptionRequired::reportSponsoredResultOptionRequired()
  : title_()
  , options_()
{}

reportSponsoredResultOptionRequired::reportSponsoredResultOptionRequired(string const &title_, array<object_ptr<reportOption>> &&options_)
  : title_(title_)
  , options_(std::move(options_))
{}

const std::int32_t reportSponsoredResultOptionRequired::ID;

void reportSponsoredResultOptionRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSponsoredResultOptionRequired");
    s.store_field("title", title_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportSponsoredResultAdsHidden::reportSponsoredResultAdsHidden() {
}

const std::int32_t reportSponsoredResultAdsHidden::ID;

void reportSponsoredResultAdsHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSponsoredResultAdsHidden");
    s.store_class_end();
  }
}

reportSponsoredResultPremiumRequired::reportSponsoredResultPremiumRequired() {
}

const std::int32_t reportSponsoredResultPremiumRequired::ID;

void reportSponsoredResultPremiumRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSponsoredResultPremiumRequired");
    s.store_class_end();
  }
}

secretChat::secretChat()
  : id_()
  , user_id_()
  , state_()
  , is_outbound_()
  , key_hash_()
  , layer_()
{}

secretChat::secretChat(int32 id_, int53 user_id_, object_ptr<SecretChatState> &&state_, bool is_outbound_, bytes const &key_hash_, int32 layer_)
  : id_(id_)
  , user_id_(user_id_)
  , state_(std::move(state_))
  , is_outbound_(is_outbound_)
  , key_hash_(std::move(key_hash_))
  , layer_(layer_)
{}

const std::int32_t secretChat::ID;

void secretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secretChat");
    s.store_field("id", id_);
    s.store_field("user_id", user_id_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_field("is_outbound", is_outbound_);
    s.store_bytes_field("key_hash", key_hash_);
    s.store_field("layer", layer_);
    s.store_class_end();
  }
}

secretChatStatePending::secretChatStatePending() {
}

const std::int32_t secretChatStatePending::ID;

void secretChatStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secretChatStatePending");
    s.store_class_end();
  }
}

secretChatStateReady::secretChatStateReady() {
}

const std::int32_t secretChatStateReady::ID;

void secretChatStateReady::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secretChatStateReady");
    s.store_class_end();
  }
}

secretChatStateClosed::secretChatStateClosed() {
}

const std::int32_t secretChatStateClosed::ID;

void secretChatStateClosed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secretChatStateClosed");
    s.store_class_end();
  }
}

starRevenueStatus::starRevenueStatus()
  : total_amount_()
  , current_amount_()
  , available_amount_()
  , withdrawal_enabled_()
  , next_withdrawal_in_()
{}

starRevenueStatus::starRevenueStatus(object_ptr<starAmount> &&total_amount_, object_ptr<starAmount> &&current_amount_, object_ptr<starAmount> &&available_amount_, bool withdrawal_enabled_, int32 next_withdrawal_in_)
  : total_amount_(std::move(total_amount_))
  , current_amount_(std::move(current_amount_))
  , available_amount_(std::move(available_amount_))
  , withdrawal_enabled_(withdrawal_enabled_)
  , next_withdrawal_in_(next_withdrawal_in_)
{}

const std::int32_t starRevenueStatus::ID;

void starRevenueStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starRevenueStatus");
    s.store_object_field("total_amount", static_cast<const BaseObject *>(total_amount_.get()));
    s.store_object_field("current_amount", static_cast<const BaseObject *>(current_amount_.get()));
    s.store_object_field("available_amount", static_cast<const BaseObject *>(available_amount_.get()));
    s.store_field("withdrawal_enabled", withdrawal_enabled_);
    s.store_field("next_withdrawal_in", next_withdrawal_in_);
    s.store_class_end();
  }
}

starSubscriptionTypeChannel::starSubscriptionTypeChannel()
  : can_reuse_()
  , invite_link_()
{}

starSubscriptionTypeChannel::starSubscriptionTypeChannel(bool can_reuse_, string const &invite_link_)
  : can_reuse_(can_reuse_)
  , invite_link_(invite_link_)
{}

const std::int32_t starSubscriptionTypeChannel::ID;

void starSubscriptionTypeChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starSubscriptionTypeChannel");
    s.store_field("can_reuse", can_reuse_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

starSubscriptionTypeBot::starSubscriptionTypeBot()
  : is_canceled_by_bot_()
  , title_()
  , photo_()
  , invoice_link_()
{}

starSubscriptionTypeBot::starSubscriptionTypeBot(bool is_canceled_by_bot_, string const &title_, object_ptr<photo> &&photo_, string const &invoice_link_)
  : is_canceled_by_bot_(is_canceled_by_bot_)
  , title_(title_)
  , photo_(std::move(photo_))
  , invoice_link_(invoice_link_)
{}

const std::int32_t starSubscriptionTypeBot::ID;

void starSubscriptionTypeBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starSubscriptionTypeBot");
    s.store_field("is_canceled_by_bot", is_canceled_by_bot_);
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("invoice_link", invoice_link_);
    s.store_class_end();
  }
}

statisticalGraphData::statisticalGraphData()
  : json_data_()
  , zoom_token_()
{}

statisticalGraphData::statisticalGraphData(string const &json_data_, string const &zoom_token_)
  : json_data_(json_data_)
  , zoom_token_(zoom_token_)
{}

const std::int32_t statisticalGraphData::ID;

void statisticalGraphData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statisticalGraphData");
    s.store_field("json_data", json_data_);
    s.store_field("zoom_token", zoom_token_);
    s.store_class_end();
  }
}

statisticalGraphAsync::statisticalGraphAsync()
  : token_()
{}

statisticalGraphAsync::statisticalGraphAsync(string const &token_)
  : token_(token_)
{}

const std::int32_t statisticalGraphAsync::ID;

void statisticalGraphAsync::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statisticalGraphAsync");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

statisticalGraphError::statisticalGraphError()
  : error_message_()
{}

statisticalGraphError::statisticalGraphError(string const &error_message_)
  : error_message_(error_message_)
{}

const std::int32_t statisticalGraphError::ID;

void statisticalGraphError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statisticalGraphError");
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

stickerFullTypeRegular::stickerFullTypeRegular()
  : premium_animation_()
{}

stickerFullTypeRegular::stickerFullTypeRegular(object_ptr<file> &&premium_animation_)
  : premium_animation_(std::move(premium_animation_))
{}

const std::int32_t stickerFullTypeRegular::ID;

void stickerFullTypeRegular::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerFullTypeRegular");
    s.store_object_field("premium_animation", static_cast<const BaseObject *>(premium_animation_.get()));
    s.store_class_end();
  }
}

stickerFullTypeMask::stickerFullTypeMask()
  : mask_position_()
{}

stickerFullTypeMask::stickerFullTypeMask(object_ptr<maskPosition> &&mask_position_)
  : mask_position_(std::move(mask_position_))
{}

const std::int32_t stickerFullTypeMask::ID;

void stickerFullTypeMask::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerFullTypeMask");
    s.store_object_field("mask_position", static_cast<const BaseObject *>(mask_position_.get()));
    s.store_class_end();
  }
}

stickerFullTypeCustomEmoji::stickerFullTypeCustomEmoji()
  : custom_emoji_id_()
  , needs_repainting_()
{}

stickerFullTypeCustomEmoji::stickerFullTypeCustomEmoji(int64 custom_emoji_id_, bool needs_repainting_)
  : custom_emoji_id_(custom_emoji_id_)
  , needs_repainting_(needs_repainting_)
{}

const std::int32_t stickerFullTypeCustomEmoji::ID;

void stickerFullTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerFullTypeCustomEmoji");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_field("needs_repainting", needs_repainting_);
    s.store_class_end();
  }
}

stickerSet::stickerSet()
  : id_()
  , title_()
  , name_()
  , thumbnail_()
  , thumbnail_outline_()
  , is_owned_()
  , is_installed_()
  , is_archived_()
  , is_official_()
  , sticker_type_()
  , needs_repainting_()
  , is_allowed_as_chat_emoji_status_()
  , is_viewed_()
  , stickers_()
  , emojis_()
{}

stickerSet::stickerSet(int64 id_, string const &title_, string const &name_, object_ptr<thumbnail> &&thumbnail_, object_ptr<outline> &&thumbnail_outline_, bool is_owned_, bool is_installed_, bool is_archived_, bool is_official_, object_ptr<StickerType> &&sticker_type_, bool needs_repainting_, bool is_allowed_as_chat_emoji_status_, bool is_viewed_, array<object_ptr<sticker>> &&stickers_, array<object_ptr<emojis>> &&emojis_)
  : id_(id_)
  , title_(title_)
  , name_(name_)
  , thumbnail_(std::move(thumbnail_))
  , thumbnail_outline_(std::move(thumbnail_outline_))
  , is_owned_(is_owned_)
  , is_installed_(is_installed_)
  , is_archived_(is_archived_)
  , is_official_(is_official_)
  , sticker_type_(std::move(sticker_type_))
  , needs_repainting_(needs_repainting_)
  , is_allowed_as_chat_emoji_status_(is_allowed_as_chat_emoji_status_)
  , is_viewed_(is_viewed_)
  , stickers_(std::move(stickers_))
  , emojis_(std::move(emojis_))
{}

const std::int32_t stickerSet::ID;

void stickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSet");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("name", name_);
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("thumbnail_outline", static_cast<const BaseObject *>(thumbnail_outline_.get()));
    s.store_field("is_owned", is_owned_);
    s.store_field("is_installed", is_installed_);
    s.store_field("is_archived", is_archived_);
    s.store_field("is_official", is_official_);
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("needs_repainting", needs_repainting_);
    s.store_field("is_allowed_as_chat_emoji_status", is_allowed_as_chat_emoji_status_);
    s.store_field("is_viewed", is_viewed_);
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

storageStatisticsByFileType::storageStatisticsByFileType()
  : file_type_()
  , size_()
  , count_()
{}

storageStatisticsByFileType::storageStatisticsByFileType(object_ptr<FileType> &&file_type_, int53 size_, int32 count_)
  : file_type_(std::move(file_type_))
  , size_(size_)
  , count_(count_)
{}

const std::int32_t storageStatisticsByFileType::ID;

void storageStatisticsByFileType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storageStatisticsByFileType");
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_field("size", size_);
    s.store_field("count", count_);
    s.store_class_end();
  }
}

storyInfo::storyInfo()
  : story_id_()
  , date_()
  , is_for_close_friends_()
  , is_live_()
{}

storyInfo::storyInfo(int32 story_id_, int32 date_, bool is_for_close_friends_, bool is_live_)
  : story_id_(story_id_)
  , date_(date_)
  , is_for_close_friends_(is_for_close_friends_)
  , is_live_(is_live_)
{}

const std::int32_t storyInfo::ID;

void storyInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInfo");
    s.store_field("story_id", story_id_);
    s.store_field("date", date_);
    s.store_field("is_for_close_friends", is_for_close_friends_);
    s.store_field("is_live", is_live_);
    s.store_class_end();
  }
}

storyInteractionTypeView::storyInteractionTypeView()
  : chosen_reaction_type_()
{}

storyInteractionTypeView::storyInteractionTypeView(object_ptr<ReactionType> &&chosen_reaction_type_)
  : chosen_reaction_type_(std::move(chosen_reaction_type_))
{}

const std::int32_t storyInteractionTypeView::ID;

void storyInteractionTypeView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInteractionTypeView");
    s.store_object_field("chosen_reaction_type", static_cast<const BaseObject *>(chosen_reaction_type_.get()));
    s.store_class_end();
  }
}

storyInteractionTypeForward::storyInteractionTypeForward()
  : message_()
{}

storyInteractionTypeForward::storyInteractionTypeForward(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t storyInteractionTypeForward::ID;

void storyInteractionTypeForward::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInteractionTypeForward");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

storyInteractionTypeRepost::storyInteractionTypeRepost()
  : story_()
{}

storyInteractionTypeRepost::storyInteractionTypeRepost(object_ptr<story> &&story_)
  : story_(std::move(story_))
{}

const std::int32_t storyInteractionTypeRepost::ID;

void storyInteractionTypeRepost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInteractionTypeRepost");
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

storyInteractions::storyInteractions()
  : total_count_()
  , total_forward_count_()
  , total_reaction_count_()
  , interactions_()
  , next_offset_()
{}

storyInteractions::storyInteractions(int32 total_count_, int32 total_forward_count_, int32 total_reaction_count_, array<object_ptr<storyInteraction>> &&interactions_, string const &next_offset_)
  : total_count_(total_count_)
  , total_forward_count_(total_forward_count_)
  , total_reaction_count_(total_reaction_count_)
  , interactions_(std::move(interactions_))
  , next_offset_(next_offset_)
{}

const std::int32_t storyInteractions::ID;

void storyInteractions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInteractions");
    s.store_field("total_count", total_count_);
    s.store_field("total_forward_count", total_forward_count_);
    s.store_field("total_reaction_count", total_reaction_count_);
    { s.store_vector_begin("interactions", interactions_.size()); for (const auto &_value : interactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

supergroupMembersFilterRecent::supergroupMembersFilterRecent() {
}

const std::int32_t supergroupMembersFilterRecent::ID;

void supergroupMembersFilterRecent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterRecent");
    s.store_class_end();
  }
}

supergroupMembersFilterContacts::supergroupMembersFilterContacts()
  : query_()
{}

supergroupMembersFilterContacts::supergroupMembersFilterContacts(string const &query_)
  : query_(query_)
{}

const std::int32_t supergroupMembersFilterContacts::ID;

void supergroupMembersFilterContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterContacts");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

supergroupMembersFilterAdministrators::supergroupMembersFilterAdministrators() {
}

const std::int32_t supergroupMembersFilterAdministrators::ID;

void supergroupMembersFilterAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterAdministrators");
    s.store_class_end();
  }
}

supergroupMembersFilterSearch::supergroupMembersFilterSearch()
  : query_()
{}

supergroupMembersFilterSearch::supergroupMembersFilterSearch(string const &query_)
  : query_(query_)
{}

const std::int32_t supergroupMembersFilterSearch::ID;

void supergroupMembersFilterSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterSearch");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

supergroupMembersFilterRestricted::supergroupMembersFilterRestricted()
  : query_()
{}

supergroupMembersFilterRestricted::supergroupMembersFilterRestricted(string const &query_)
  : query_(query_)
{}

const std::int32_t supergroupMembersFilterRestricted::ID;

void supergroupMembersFilterRestricted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterRestricted");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

supergroupMembersFilterBanned::supergroupMembersFilterBanned()
  : query_()
{}

supergroupMembersFilterBanned::supergroupMembersFilterBanned(string const &query_)
  : query_(query_)
{}

const std::int32_t supergroupMembersFilterBanned::ID;

void supergroupMembersFilterBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterBanned");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

supergroupMembersFilterMention::supergroupMembersFilterMention()
  : query_()
  , topic_id_()
{}

supergroupMembersFilterMention::supergroupMembersFilterMention(string const &query_, object_ptr<MessageTopic> &&topic_id_)
  : query_(query_)
  , topic_id_(std::move(topic_id_))
{}

const std::int32_t supergroupMembersFilterMention::ID;

void supergroupMembersFilterMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterMention");
    s.store_field("query", query_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_class_end();
  }
}

supergroupMembersFilterBots::supergroupMembersFilterBots() {
}

const std::int32_t supergroupMembersFilterBots::ID;

void supergroupMembersFilterBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "supergroupMembersFilterBots");
    s.store_class_end();
  }
}

testVectorIntObject::testVectorIntObject()
  : value_()
{}

testVectorIntObject::testVectorIntObject(array<object_ptr<testInt>> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t testVectorIntObject::ID;

void testVectorIntObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testVectorIntObject");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

textEntities::textEntities()
  : entities_()
{}

textEntities::textEntities(array<object_ptr<textEntity>> &&entities_)
  : entities_(std::move(entities_))
{}

const std::int32_t textEntities::ID;

void textEntities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEntities");
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

upgradedGift::upgradedGift()
  : id_()
  , regular_gift_id_()
  , publisher_chat_id_()
  , title_()
  , name_()
  , number_()
  , total_upgraded_count_()
  , max_upgraded_count_()
  , is_burned_()
  , is_crafted_()
  , is_premium_()
  , is_theme_available_()
  , used_theme_chat_id_()
  , host_id_()
  , owner_id_()
  , owner_address_()
  , owner_name_()
  , gift_address_()
  , model_()
  , symbol_()
  , backdrop_()
  , original_details_()
  , colors_()
  , resale_parameters_()
  , can_send_purchase_offer_()
  , craft_probability_per_mille_()
  , value_currency_()
  , value_amount_()
  , value_usd_amount_()
{}

upgradedGift::upgradedGift(int64 id_, int64 regular_gift_id_, int53 publisher_chat_id_, string const &title_, string const &name_, int32 number_, int32 total_upgraded_count_, int32 max_upgraded_count_, bool is_burned_, bool is_crafted_, bool is_premium_, bool is_theme_available_, int53 used_theme_chat_id_, object_ptr<MessageSender> &&host_id_, object_ptr<MessageSender> &&owner_id_, string const &owner_address_, string const &owner_name_, string const &gift_address_, object_ptr<upgradedGiftModel> &&model_, object_ptr<upgradedGiftSymbol> &&symbol_, object_ptr<upgradedGiftBackdrop> &&backdrop_, object_ptr<upgradedGiftOriginalDetails> &&original_details_, object_ptr<upgradedGiftColors> &&colors_, object_ptr<giftResaleParameters> &&resale_parameters_, bool can_send_purchase_offer_, int32 craft_probability_per_mille_, string const &value_currency_, int53 value_amount_, int53 value_usd_amount_)
  : id_(id_)
  , regular_gift_id_(regular_gift_id_)
  , publisher_chat_id_(publisher_chat_id_)
  , title_(title_)
  , name_(name_)
  , number_(number_)
  , total_upgraded_count_(total_upgraded_count_)
  , max_upgraded_count_(max_upgraded_count_)
  , is_burned_(is_burned_)
  , is_crafted_(is_crafted_)
  , is_premium_(is_premium_)
  , is_theme_available_(is_theme_available_)
  , used_theme_chat_id_(used_theme_chat_id_)
  , host_id_(std::move(host_id_))
  , owner_id_(std::move(owner_id_))
  , owner_address_(owner_address_)
  , owner_name_(owner_name_)
  , gift_address_(gift_address_)
  , model_(std::move(model_))
  , symbol_(std::move(symbol_))
  , backdrop_(std::move(backdrop_))
  , original_details_(std::move(original_details_))
  , colors_(std::move(colors_))
  , resale_parameters_(std::move(resale_parameters_))
  , can_send_purchase_offer_(can_send_purchase_offer_)
  , craft_probability_per_mille_(craft_probability_per_mille_)
  , value_currency_(value_currency_)
  , value_amount_(value_amount_)
  , value_usd_amount_(value_usd_amount_)
{}

const std::int32_t upgradedGift::ID;

void upgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGift");
    s.store_field("id", id_);
    s.store_field("regular_gift_id", regular_gift_id_);
    s.store_field("publisher_chat_id", publisher_chat_id_);
    s.store_field("title", title_);
    s.store_field("name", name_);
    s.store_field("number", number_);
    s.store_field("total_upgraded_count", total_upgraded_count_);
    s.store_field("max_upgraded_count", max_upgraded_count_);
    s.store_field("is_burned", is_burned_);
    s.store_field("is_crafted", is_crafted_);
    s.store_field("is_premium", is_premium_);
    s.store_field("is_theme_available", is_theme_available_);
    s.store_field("used_theme_chat_id", used_theme_chat_id_);
    s.store_object_field("host_id", static_cast<const BaseObject *>(host_id_.get()));
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("owner_address", owner_address_);
    s.store_field("owner_name", owner_name_);
    s.store_field("gift_address", gift_address_);
    s.store_object_field("model", static_cast<const BaseObject *>(model_.get()));
    s.store_object_field("symbol", static_cast<const BaseObject *>(symbol_.get()));
    s.store_object_field("backdrop", static_cast<const BaseObject *>(backdrop_.get()));
    s.store_object_field("original_details", static_cast<const BaseObject *>(original_details_.get()));
    s.store_object_field("colors", static_cast<const BaseObject *>(colors_.get()));
    s.store_object_field("resale_parameters", static_cast<const BaseObject *>(resale_parameters_.get()));
    s.store_field("can_send_purchase_offer", can_send_purchase_offer_);
    s.store_field("craft_probability_per_mille", craft_probability_per_mille_);
    s.store_field("value_currency", value_currency_);
    s.store_field("value_amount", value_amount_);
    s.store_field("value_usd_amount", value_usd_amount_);
    s.store_class_end();
  }
}

upgradedGiftAttributeRarityPerMille::upgradedGiftAttributeRarityPerMille()
  : per_mille_()
{}

upgradedGiftAttributeRarityPerMille::upgradedGiftAttributeRarityPerMille(int32 per_mille_)
  : per_mille_(per_mille_)
{}

const std::int32_t upgradedGiftAttributeRarityPerMille::ID;

void upgradedGiftAttributeRarityPerMille::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeRarityPerMille");
    s.store_field("per_mille", per_mille_);
    s.store_class_end();
  }
}

upgradedGiftAttributeRarityUncommon::upgradedGiftAttributeRarityUncommon() {
}

const std::int32_t upgradedGiftAttributeRarityUncommon::ID;

void upgradedGiftAttributeRarityUncommon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeRarityUncommon");
    s.store_class_end();
  }
}

upgradedGiftAttributeRarityRare::upgradedGiftAttributeRarityRare() {
}

const std::int32_t upgradedGiftAttributeRarityRare::ID;

void upgradedGiftAttributeRarityRare::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeRarityRare");
    s.store_class_end();
  }
}

upgradedGiftAttributeRarityEpic::upgradedGiftAttributeRarityEpic() {
}

const std::int32_t upgradedGiftAttributeRarityEpic::ID;

void upgradedGiftAttributeRarityEpic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeRarityEpic");
    s.store_class_end();
  }
}

upgradedGiftAttributeRarityLegendary::upgradedGiftAttributeRarityLegendary() {
}

const std::int32_t upgradedGiftAttributeRarityLegendary::ID;

void upgradedGiftAttributeRarityLegendary::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftAttributeRarityLegendary");
    s.store_class_end();
  }
}

upgradedGiftBackdropCount::upgradedGiftBackdropCount()
  : backdrop_()
  , total_count_()
{}

upgradedGiftBackdropCount::upgradedGiftBackdropCount(object_ptr<upgradedGiftBackdrop> &&backdrop_, int32 total_count_)
  : backdrop_(std::move(backdrop_))
  , total_count_(total_count_)
{}

const std::int32_t upgradedGiftBackdropCount::ID;

void upgradedGiftBackdropCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftBackdropCount");
    s.store_object_field("backdrop", static_cast<const BaseObject *>(backdrop_.get()));
    s.store_field("total_count", total_count_);
    s.store_class_end();
  }
}

acceptCall::acceptCall()
  : call_id_()
  , protocol_()
{}

acceptCall::acceptCall(int32 call_id_, object_ptr<callProtocol> &&protocol_)
  : call_id_(call_id_)
  , protocol_(std::move(protocol_))
{}

const std::int32_t acceptCall::ID;

void acceptCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "acceptCall");
    s.store_field("call_id", call_id_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

acceptTermsOfService::acceptTermsOfService()
  : terms_of_service_id_()
{}

acceptTermsOfService::acceptTermsOfService(string const &terms_of_service_id_)
  : terms_of_service_id_(terms_of_service_id_)
{}

const std::int32_t acceptTermsOfService::ID;

void acceptTermsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "acceptTermsOfService");
    s.store_field("terms_of_service_id", terms_of_service_id_);
    s.store_class_end();
  }
}

addChatMember::addChatMember()
  : chat_id_()
  , user_id_()
  , forward_limit_()
{}

addChatMember::addChatMember(int53 chat_id_, int53 user_id_, int32 forward_limit_)
  : chat_id_(chat_id_)
  , user_id_(user_id_)
  , forward_limit_(forward_limit_)
{}

const std::int32_t addChatMember::ID;

void addChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("forward_limit", forward_limit_);
    s.store_class_end();
  }
}

addLocalMessage::addLocalMessage()
  : chat_id_()
  , sender_id_()
  , reply_to_()
  , disable_notification_()
  , input_message_content_()
{}

addLocalMessage::addLocalMessage(int53 chat_id_, object_ptr<MessageSender> &&sender_id_, object_ptr<InputMessageReplyTo> &&reply_to_, bool disable_notification_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , sender_id_(std::move(sender_id_))
  , reply_to_(std::move(reply_to_))
  , disable_notification_(disable_notification_)
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t addLocalMessage::ID;

void addLocalMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addLocalMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_field("disable_notification", disable_notification_);
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

addProxy::addProxy()
  : proxy_()
  , enable_()
{}

addProxy::addProxy(object_ptr<proxy> &&proxy_, bool enable_)
  : proxy_(std::move(proxy_))
  , enable_(enable_)
{}

const std::int32_t addProxy::ID;

void addProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addProxy");
    s.store_object_field("proxy", static_cast<const BaseObject *>(proxy_.get()));
    s.store_field("enable", enable_);
    s.store_class_end();
  }
}

answerPreCheckoutQuery::answerPreCheckoutQuery()
  : pre_checkout_query_id_()
  , error_message_()
{}

answerPreCheckoutQuery::answerPreCheckoutQuery(int64 pre_checkout_query_id_, string const &error_message_)
  : pre_checkout_query_id_(pre_checkout_query_id_)
  , error_message_(error_message_)
{}

const std::int32_t answerPreCheckoutQuery::ID;

void answerPreCheckoutQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "answerPreCheckoutQuery");
    s.store_field("pre_checkout_query_id", pre_checkout_query_id_);
    s.store_field("error_message", error_message_);
    s.store_class_end();
  }
}

assignStoreTransaction::assignStoreTransaction()
  : transaction_()
  , purpose_()
{}

assignStoreTransaction::assignStoreTransaction(object_ptr<StoreTransaction> &&transaction_, object_ptr<StorePaymentPurpose> &&purpose_)
  : transaction_(std::move(transaction_))
  , purpose_(std::move(purpose_))
{}

const std::int32_t assignStoreTransaction::ID;

void assignStoreTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "assignStoreTransaction");
    s.store_object_field("transaction", static_cast<const BaseObject *>(transaction_.get()));
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

cancelPreliminaryUploadFile::cancelPreliminaryUploadFile()
  : file_id_()
{}

cancelPreliminaryUploadFile::cancelPreliminaryUploadFile(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t cancelPreliminaryUploadFile::ID;

void cancelPreliminaryUploadFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cancelPreliminaryUploadFile");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

checkLoginEmailAddressCode::checkLoginEmailAddressCode()
  : code_()
{}

checkLoginEmailAddressCode::checkLoginEmailAddressCode(object_ptr<EmailAddressAuthentication> &&code_)
  : code_(std::move(code_))
{}

const std::int32_t checkLoginEmailAddressCode::ID;

void checkLoginEmailAddressCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkLoginEmailAddressCode");
    s.store_object_field("code", static_cast<const BaseObject *>(code_.get()));
    s.store_class_end();
  }
}

checkPhoneNumberCode::checkPhoneNumberCode()
  : code_()
{}

checkPhoneNumberCode::checkPhoneNumberCode(string const &code_)
  : code_(code_)
{}

const std::int32_t checkPhoneNumberCode::ID;

void checkPhoneNumberCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkPhoneNumberCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

checkWebAppFileDownload::checkWebAppFileDownload()
  : bot_user_id_()
  , file_name_()
  , url_()
{}

checkWebAppFileDownload::checkWebAppFileDownload(int53 bot_user_id_, string const &file_name_, string const &url_)
  : bot_user_id_(bot_user_id_)
  , file_name_(file_name_)
  , url_(url_)
{}

const std::int32_t checkWebAppFileDownload::ID;

void checkWebAppFileDownload::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkWebAppFileDownload");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("file_name", file_name_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

clearRecentlyFoundChats::clearRecentlyFoundChats() {
}

const std::int32_t clearRecentlyFoundChats::ID;

void clearRecentlyFoundChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearRecentlyFoundChats");
    s.store_class_end();
  }
}

commitPendingLiveStoryReactions::commitPendingLiveStoryReactions()
  : group_call_id_()
{}

commitPendingLiveStoryReactions::commitPendingLiveStoryReactions(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t commitPendingLiveStoryReactions::ID;

void commitPendingLiveStoryReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "commitPendingLiveStoryReactions");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

composeTextWithAi::composeTextWithAi()
  : text_()
  , translate_to_language_code_()
  , style_name_()
  , add_emojis_()
{}

composeTextWithAi::composeTextWithAi(object_ptr<formattedText> &&text_, string const &translate_to_language_code_, string const &style_name_, bool add_emojis_)
  : text_(std::move(text_))
  , translate_to_language_code_(translate_to_language_code_)
  , style_name_(style_name_)
  , add_emojis_(add_emojis_)
{}

const std::int32_t composeTextWithAi::ID;

void composeTextWithAi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "composeTextWithAi");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("translate_to_language_code", translate_to_language_code_);
    s.store_field("style_name", style_name_);
    s.store_field("add_emojis", add_emojis_);
    s.store_class_end();
  }
}

createCall::createCall()
  : user_id_()
  , protocol_()
  , is_video_()
{}

createCall::createCall(int53 user_id_, object_ptr<callProtocol> &&protocol_, bool is_video_)
  : user_id_(user_id_)
  , protocol_(std::move(protocol_))
  , is_video_(is_video_)
{}

const std::int32_t createCall::ID;

void createCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createCall");
    s.store_field("user_id", user_id_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_field("is_video", is_video_);
    s.store_class_end();
  }
}

createNewStickerSet::createNewStickerSet()
  : user_id_()
  , title_()
  , name_()
  , sticker_type_()
  , needs_repainting_()
  , stickers_()
  , source_()
{}

createNewStickerSet::createNewStickerSet(int53 user_id_, string const &title_, string const &name_, object_ptr<StickerType> &&sticker_type_, bool needs_repainting_, array<object_ptr<inputSticker>> &&stickers_, string const &source_)
  : user_id_(user_id_)
  , title_(title_)
  , name_(name_)
  , sticker_type_(std::move(sticker_type_))
  , needs_repainting_(needs_repainting_)
  , stickers_(std::move(stickers_))
  , source_(source_)
{}

const std::int32_t createNewStickerSet::ID;

void createNewStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createNewStickerSet");
    s.store_field("user_id", user_id_);
    s.store_field("title", title_);
    s.store_field("name", name_);
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("needs_repainting", needs_repainting_);
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("source", source_);
    s.store_class_end();
  }
}

createVideoChat::createVideoChat()
  : chat_id_()
  , title_()
  , start_date_()
  , is_rtmp_stream_()
{}

createVideoChat::createVideoChat(int53 chat_id_, string const &title_, int32 start_date_, bool is_rtmp_stream_)
  : chat_id_(chat_id_)
  , title_(title_)
  , start_date_(start_date_)
  , is_rtmp_stream_(is_rtmp_stream_)
{}

const std::int32_t createVideoChat::ID;

void createVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createVideoChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_field("start_date", start_date_);
    s.store_field("is_rtmp_stream", is_rtmp_stream_);
    s.store_class_end();
  }
}

deleteBusinessConnectedBot::deleteBusinessConnectedBot()
  : bot_user_id_()
{}

deleteBusinessConnectedBot::deleteBusinessConnectedBot(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t deleteBusinessConnectedBot::ID;

void deleteBusinessConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteBusinessConnectedBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

deleteBusinessMessages::deleteBusinessMessages()
  : business_connection_id_()
  , message_ids_()
{}

deleteBusinessMessages::deleteBusinessMessages(string const &business_connection_id_, array<int53> &&message_ids_)
  : business_connection_id_(business_connection_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t deleteBusinessMessages::ID;

void deleteBusinessMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteBusinessMessages");
    s.store_field("business_connection_id", business_connection_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

deleteBusinessStory::deleteBusinessStory()
  : business_connection_id_()
  , story_id_()
{}

deleteBusinessStory::deleteBusinessStory(string const &business_connection_id_, int32 story_id_)
  : business_connection_id_(business_connection_id_)
  , story_id_(story_id_)
{}

const std::int32_t deleteBusinessStory::ID;

void deleteBusinessStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteBusinessStory");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

deleteProfilePhoto::deleteProfilePhoto()
  : profile_photo_id_()
{}

deleteProfilePhoto::deleteProfilePhoto(int64 profile_photo_id_)
  : profile_photo_id_(profile_photo_id_)
{}

const std::int32_t deleteProfilePhoto::ID;

void deleteProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteProfilePhoto");
    s.store_field("profile_photo_id", profile_photo_id_);
    s.store_class_end();
  }
}

deleteSavedMessagesTopicMessagesByDate::deleteSavedMessagesTopicMessagesByDate()
  : saved_messages_topic_id_()
  , min_date_()
  , max_date_()
{}

deleteSavedMessagesTopicMessagesByDate::deleteSavedMessagesTopicMessagesByDate(int53 saved_messages_topic_id_, int32 min_date_, int32 max_date_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
  , min_date_(min_date_)
  , max_date_(max_date_)
{}

const std::int32_t deleteSavedMessagesTopicMessagesByDate::ID;

void deleteSavedMessagesTopicMessagesByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteSavedMessagesTopicMessagesByDate");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_class_end();
  }
}

disconnectAllWebsites::disconnectAllWebsites() {
}

const std::int32_t disconnectAllWebsites::ID;

void disconnectAllWebsites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disconnectAllWebsites");
    s.store_class_end();
  }
}

editBusinessMessageMedia::editBusinessMessageMedia()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editBusinessMessageMedia::editBusinessMessageMedia(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editBusinessMessageMedia::ID;

void editBusinessMessageMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessMessageMedia");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editMessageChecklist::editMessageChecklist()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , checklist_()
{}

editMessageChecklist::editMessageChecklist(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<inputChecklist> &&checklist_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , checklist_(std::move(checklist_))
{}

const std::int32_t editMessageChecklist::ID;

void editMessageChecklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageChecklist");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("checklist", static_cast<const BaseObject *>(checklist_.get()));
    s.store_class_end();
  }
}

encryptGroupCallData::encryptGroupCallData()
  : group_call_id_()
  , data_channel_()
  , data_()
  , unencrypted_prefix_size_()
{}

encryptGroupCallData::encryptGroupCallData(int32 group_call_id_, object_ptr<GroupCallDataChannel> &&data_channel_, bytes const &data_, int32 unencrypted_prefix_size_)
  : group_call_id_(group_call_id_)
  , data_channel_(std::move(data_channel_))
  , data_(std::move(data_))
  , unencrypted_prefix_size_(unencrypted_prefix_size_)
{}

const std::int32_t encryptGroupCallData::ID;

void encryptGroupCallData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptGroupCallData");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("data_channel", static_cast<const BaseObject *>(data_channel_.get()));
    s.store_bytes_field("data", data_);
    s.store_field("unencrypted_prefix_size", unencrypted_prefix_size_);
    s.store_class_end();
  }
}

getArchivedStickerSets::getArchivedStickerSets()
  : sticker_type_()
  , offset_sticker_set_id_()
  , limit_()
{}

getArchivedStickerSets::getArchivedStickerSets(object_ptr<StickerType> &&sticker_type_, int64 offset_sticker_set_id_, int32 limit_)
  : sticker_type_(std::move(sticker_type_))
  , offset_sticker_set_id_(offset_sticker_set_id_)
  , limit_(limit_)
{}

const std::int32_t getArchivedStickerSets::ID;

void getArchivedStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getArchivedStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("offset_sticker_set_id", offset_sticker_set_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getAuthenticationPasskeyParameters::getAuthenticationPasskeyParameters() {
}

const std::int32_t getAuthenticationPasskeyParameters::ID;

void getAuthenticationPasskeyParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAuthenticationPasskeyParameters");
    s.store_class_end();
  }
}

getBlockedMessageSenders::getBlockedMessageSenders()
  : block_list_()
  , offset_()
  , limit_()
{}

getBlockedMessageSenders::getBlockedMessageSenders(object_ptr<BlockList> &&block_list_, int32 offset_, int32 limit_)
  : block_list_(std::move(block_list_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getBlockedMessageSenders::ID;

void getBlockedMessageSenders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBlockedMessageSenders");
    s.store_object_field("block_list", static_cast<const BaseObject *>(block_list_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatFolderChatsToLeave::getChatFolderChatsToLeave()
  : chat_folder_id_()
{}

getChatFolderChatsToLeave::getChatFolderChatsToLeave(int32 chat_folder_id_)
  : chat_folder_id_(chat_folder_id_)
{}

const std::int32_t getChatFolderChatsToLeave::ID;

void getChatFolderChatsToLeave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFolderChatsToLeave");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_class_end();
  }
}

getChatInviteLinkMembers::getChatInviteLinkMembers()
  : chat_id_()
  , invite_link_()
  , only_with_expired_subscription_()
  , offset_member_()
  , limit_()
{}

getChatInviteLinkMembers::getChatInviteLinkMembers(int53 chat_id_, string const &invite_link_, bool only_with_expired_subscription_, object_ptr<chatInviteLinkMember> &&offset_member_, int32 limit_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
  , only_with_expired_subscription_(only_with_expired_subscription_)
  , offset_member_(std::move(offset_member_))
  , limit_(limit_)
{}

const std::int32_t getChatInviteLinkMembers::ID;

void getChatInviteLinkMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatInviteLinkMembers");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_field("only_with_expired_subscription", only_with_expired_subscription_);
    s.store_object_field("offset_member", static_cast<const BaseObject *>(offset_member_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatListsToAddChat::getChatListsToAddChat()
  : chat_id_()
{}

getChatListsToAddChat::getChatListsToAddChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatListsToAddChat::ID;

void getChatListsToAddChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatListsToAddChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatMessageCalendar::getChatMessageCalendar()
  : chat_id_()
  , topic_id_()
  , filter_()
  , from_message_id_()
{}

getChatMessageCalendar::getChatMessageCalendar(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<SearchMessagesFilter> &&filter_, int53 from_message_id_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , filter_(std::move(filter_))
  , from_message_id_(from_message_id_)
{}

const std::int32_t getChatMessageCalendar::ID;

void getChatMessageCalendar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatMessageCalendar");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("from_message_id", from_message_id_);
    s.store_class_end();
  }
}

getChatSimilarChats::getChatSimilarChats()
  : chat_id_()
{}

getChatSimilarChats::getChatSimilarChats(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatSimilarChats::ID;

void getChatSimilarChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatSimilarChats");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatSponsoredMessages::getChatSponsoredMessages()
  : chat_id_()
{}

getChatSponsoredMessages::getChatSponsoredMessages(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatSponsoredMessages::ID;

void getChatSponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatSponsoredMessages");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getDefaultBackgroundCustomEmojiStickers::getDefaultBackgroundCustomEmojiStickers() {
}

const std::int32_t getDefaultBackgroundCustomEmojiStickers::ID;

void getDefaultBackgroundCustomEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDefaultBackgroundCustomEmojiStickers");
    s.store_class_end();
  }
}

getDirectMessagesChatTopicHistory::getDirectMessagesChatTopicHistory()
  : chat_id_()
  , topic_id_()
  , from_message_id_()
  , offset_()
  , limit_()
{}

getDirectMessagesChatTopicHistory::getDirectMessagesChatTopicHistory(int53 chat_id_, int53 topic_id_, int53 from_message_id_, int32 offset_, int32 limit_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getDirectMessagesChatTopicHistory::ID;

void getDirectMessagesChatTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDirectMessagesChatTopicHistory");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getDirectMessagesChatTopicMessageByDate::getDirectMessagesChatTopicMessageByDate()
  : chat_id_()
  , topic_id_()
  , date_()
{}

getDirectMessagesChatTopicMessageByDate::getDirectMessagesChatTopicMessageByDate(int53 chat_id_, int53 topic_id_, int32 date_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
  , date_(date_)
{}

const std::int32_t getDirectMessagesChatTopicMessageByDate::ID;

void getDirectMessagesChatTopicMessageByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDirectMessagesChatTopicMessageByDate");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

getEmojiSuggestionsUrl::getEmojiSuggestionsUrl()
  : language_code_()
{}

getEmojiSuggestionsUrl::getEmojiSuggestionsUrl(string const &language_code_)
  : language_code_(language_code_)
{}

const std::int32_t getEmojiSuggestionsUrl::ID;

void getEmojiSuggestionsUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getEmojiSuggestionsUrl");
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getForumTopicDefaultIcons::getForumTopicDefaultIcons() {
}

const std::int32_t getForumTopicDefaultIcons::ID;

void getForumTopicDefaultIcons::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getForumTopicDefaultIcons");
    s.store_class_end();
  }
}

getGroupCall::getGroupCall()
  : group_call_id_()
{}

getGroupCall::getGroupCall(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t getGroupCall::ID;

void getGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupCall");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getGroupsInCommon::getGroupsInCommon()
  : user_id_()
  , offset_chat_id_()
  , limit_()
{}

getGroupsInCommon::getGroupsInCommon(int53 user_id_, int53 offset_chat_id_, int32 limit_)
  : user_id_(user_id_)
  , offset_chat_id_(offset_chat_id_)
  , limit_(limit_)
{}

const std::int32_t getGroupsInCommon::ID;

void getGroupsInCommon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupsInCommon");
    s.store_field("user_id", user_id_);
    s.store_field("offset_chat_id", offset_chat_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getInstalledStickerSets::getInstalledStickerSets()
  : sticker_type_()
{}

getInstalledStickerSets::getInstalledStickerSets(object_ptr<StickerType> &&sticker_type_)
  : sticker_type_(std::move(sticker_type_))
{}

const std::int32_t getInstalledStickerSets::ID;

void getInstalledStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInstalledStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_class_end();
  }
}

getLocalizationTargetInfo::getLocalizationTargetInfo()
  : only_local_()
{}

getLocalizationTargetInfo::getLocalizationTargetInfo(bool only_local_)
  : only_local_(only_local_)
{}

const std::int32_t getLocalizationTargetInfo::ID;

void getLocalizationTargetInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLocalizationTargetInfo");
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

getMainWebApp::getMainWebApp()
  : chat_id_()
  , bot_user_id_()
  , start_parameter_()
  , parameters_()
{}

getMainWebApp::getMainWebApp(int53 chat_id_, int53 bot_user_id_, string const &start_parameter_, object_ptr<webAppOpenParameters> &&parameters_)
  : chat_id_(chat_id_)
  , bot_user_id_(bot_user_id_)
  , start_parameter_(start_parameter_)
  , parameters_(std::move(parameters_))
{}

const std::int32_t getMainWebApp::ID;

void getMainWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMainWebApp");
    s.store_field("chat_id", chat_id_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("start_parameter", start_parameter_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

getMessageProperties::getMessageProperties()
  : chat_id_()
  , message_id_()
{}

getMessageProperties::getMessageProperties(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getMessageProperties::ID;

void getMessageProperties::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageProperties");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getMessages::getMessages()
  : chat_id_()
  , message_ids_()
{}

getMessages::getMessages(int53 chat_id_, array<int53> &&message_ids_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t getMessages::ID;

void getMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getPublicPostSearchLimits::getPublicPostSearchLimits()
  : query_()
{}

getPublicPostSearchLimits::getPublicPostSearchLimits(string const &query_)
  : query_(query_)
{}

const std::int32_t getPublicPostSearchLimits::ID;

void getPublicPostSearchLimits::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPublicPostSearchLimits");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

getRecentEmojiStatuses::getRecentEmojiStatuses() {
}

const std::int32_t getRecentEmojiStatuses::ID;

void getRecentEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRecentEmojiStatuses");
    s.store_class_end();
  }
}

getSupergroupMembers::getSupergroupMembers()
  : supergroup_id_()
  , filter_()
  , offset_()
  , limit_()
{}

getSupergroupMembers::getSupergroupMembers(int53 supergroup_id_, object_ptr<SupergroupMembersFilter> &&filter_, int32 offset_, int32 limit_)
  : supergroup_id_(supergroup_id_)
  , filter_(std::move(filter_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getSupergroupMembers::ID;

void getSupergroupMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupergroupMembers");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getTonTransactions::getTonTransactions()
  : direction_()
  , offset_()
  , limit_()
{}

getTonTransactions::getTonTransactions(object_ptr<TransactionDirection> &&direction_, string const &offset_, int32 limit_)
  : direction_(std::move(direction_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getTonTransactions::ID;

void getTonTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonTransactions");
    s.store_object_field("direction", static_cast<const BaseObject *>(direction_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getUpgradedGiftEmojiStatuses::getUpgradedGiftEmojiStatuses() {
}

const std::int32_t getUpgradedGiftEmojiStatuses::ID;

void getUpgradedGiftEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUpgradedGiftEmojiStatuses");
    s.store_class_end();
  }
}

getUpgradedGiftsPromotionalAnimation::getUpgradedGiftsPromotionalAnimation() {
}

const std::int32_t getUpgradedGiftsPromotionalAnimation::ID;

void getUpgradedGiftsPromotionalAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUpgradedGiftsPromotionalAnimation");
    s.store_class_end();
  }
}

getWebPageInstantView::getWebPageInstantView()
  : url_()
  , only_local_()
{}

getWebPageInstantView::getWebPageInstantView(string const &url_, bool only_local_)
  : url_(url_)
  , only_local_(only_local_)
{}

const std::int32_t getWebPageInstantView::ID;

void getWebPageInstantView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWebPageInstantView");
    s.store_field("url", url_);
    s.store_field("only_local", only_local_);
    s.store_class_end();
  }
}

loadActiveStories::loadActiveStories()
  : story_list_()
{}

loadActiveStories::loadActiveStories(object_ptr<StoryList> &&story_list_)
  : story_list_(std::move(story_list_))
{}

const std::int32_t loadActiveStories::ID;

void loadActiveStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadActiveStories");
    s.store_object_field("story_list", static_cast<const BaseObject *>(story_list_.get()));
    s.store_class_end();
  }
}

loadSavedMessagesTopics::loadSavedMessagesTopics()
  : limit_()
{}

loadSavedMessagesTopics::loadSavedMessagesTopics(int32 limit_)
  : limit_(limit_)
{}

const std::int32_t loadSavedMessagesTopics::ID;

void loadSavedMessagesTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadSavedMessagesTopics");
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

openGiftAuction::openGiftAuction()
  : gift_id_()
{}

openGiftAuction::openGiftAuction(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t openGiftAuction::ID;

void openGiftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openGiftAuction");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

openStory::openStory()
  : story_poster_chat_id_()
  , story_id_()
{}

openStory::openStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t openStory::ID;

void openStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

pinChatMessage::pinChatMessage()
  : chat_id_()
  , message_id_()
  , disable_notification_()
  , only_for_self_()
{}

pinChatMessage::pinChatMessage(int53 chat_id_, int53 message_id_, bool disable_notification_, bool only_for_self_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , disable_notification_(disable_notification_)
  , only_for_self_(only_for_self_)
{}

const std::int32_t pinChatMessage::ID;

void pinChatMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pinChatMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("disable_notification", disable_notification_);
    s.store_field("only_for_self", only_for_self_);
    s.store_class_end();
  }
}

readAllForumTopicMentions::readAllForumTopicMentions()
  : chat_id_()
  , forum_topic_id_()
{}

readAllForumTopicMentions::readAllForumTopicMentions(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t readAllForumTopicMentions::ID;

void readAllForumTopicMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllForumTopicMentions");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

removeGiftCollectionGifts::removeGiftCollectionGifts()
  : owner_id_()
  , collection_id_()
  , received_gift_ids_()
{}

removeGiftCollectionGifts::removeGiftCollectionGifts(object_ptr<MessageSender> &&owner_id_, int32 collection_id_, array<string> &&received_gift_ids_)
  : owner_id_(std::move(owner_id_))
  , collection_id_(collection_id_)
  , received_gift_ids_(std::move(received_gift_ids_))
{}

const std::int32_t removeGiftCollectionGifts::ID;

void removeGiftCollectionGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeGiftCollectionGifts");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("collection_id", collection_id_);
    { s.store_vector_begin("received_gift_ids", received_gift_ids_.size()); for (const auto &_value : received_gift_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reorderGiftCollections::reorderGiftCollections()
  : owner_id_()
  , collection_ids_()
{}

reorderGiftCollections::reorderGiftCollections(object_ptr<MessageSender> &&owner_id_, array<int32> &&collection_ids_)
  : owner_id_(std::move(owner_id_))
  , collection_ids_(std::move(collection_ids_))
{}

const std::int32_t reorderGiftCollections::ID;

void reorderGiftCollections::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderGiftCollections");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    { s.store_vector_begin("collection_ids", collection_ids_.size()); for (const auto &_value : collection_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportAuthenticationCodeMissing::reportAuthenticationCodeMissing()
  : mobile_network_code_()
{}

reportAuthenticationCodeMissing::reportAuthenticationCodeMissing(string const &mobile_network_code_)
  : mobile_network_code_(mobile_network_code_)
{}

const std::int32_t reportAuthenticationCodeMissing::ID;

void reportAuthenticationCodeMissing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportAuthenticationCodeMissing");
    s.store_field("mobile_network_code", mobile_network_code_);
    s.store_class_end();
  }
}

resetPassword::resetPassword() {
}

const std::int32_t resetPassword::ID;

void resetPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetPassword");
    s.store_class_end();
  }
}

searchChatsOnServer::searchChatsOnServer()
  : query_()
  , limit_()
{}

searchChatsOnServer::searchChatsOnServer(string const &query_, int32 limit_)
  : query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchChatsOnServer::ID;

void searchChatsOnServer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatsOnServer");
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchWebApp::searchWebApp()
  : bot_user_id_()
  , web_app_short_name_()
{}

searchWebApp::searchWebApp(int53 bot_user_id_, string const &web_app_short_name_)
  : bot_user_id_(bot_user_id_)
  , web_app_short_name_(web_app_short_name_)
{}

const std::int32_t searchWebApp::ID;

void searchWebApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchWebApp");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("web_app_short_name", web_app_short_name_);
    s.store_class_end();
  }
}

sendCallDebugInformation::sendCallDebugInformation()
  : call_id_()
  , debug_information_()
{}

sendCallDebugInformation::sendCallDebugInformation(object_ptr<InputCall> &&call_id_, string const &debug_information_)
  : call_id_(std::move(call_id_))
  , debug_information_(debug_information_)
{}

const std::int32_t sendCallDebugInformation::ID;

void sendCallDebugInformation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCallDebugInformation");
    s.store_object_field("call_id", static_cast<const BaseObject *>(call_id_.get()));
    s.store_field("debug_information", debug_information_);
    s.store_class_end();
  }
}

sendCallLog::sendCallLog()
  : call_id_()
  , log_file_()
{}

sendCallLog::sendCallLog(object_ptr<InputCall> &&call_id_, object_ptr<InputFile> &&log_file_)
  : call_id_(std::move(call_id_))
  , log_file_(std::move(log_file_))
{}

const std::int32_t sendCallLog::ID;

void sendCallLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCallLog");
    s.store_object_field("call_id", static_cast<const BaseObject *>(call_id_.get()));
    s.store_object_field("log_file", static_cast<const BaseObject *>(log_file_.get()));
    s.store_class_end();
  }
}

setBusinessAwayMessageSettings::setBusinessAwayMessageSettings()
  : away_message_settings_()
{}

setBusinessAwayMessageSettings::setBusinessAwayMessageSettings(object_ptr<businessAwayMessageSettings> &&away_message_settings_)
  : away_message_settings_(std::move(away_message_settings_))
{}

const std::int32_t setBusinessAwayMessageSettings::ID;

void setBusinessAwayMessageSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessAwayMessageSettings");
    s.store_object_field("away_message_settings", static_cast<const BaseObject *>(away_message_settings_.get()));
    s.store_class_end();
  }
}

setChatActiveStoriesList::setChatActiveStoriesList()
  : chat_id_()
  , story_list_()
{}

setChatActiveStoriesList::setChatActiveStoriesList(int53 chat_id_, object_ptr<StoryList> &&story_list_)
  : chat_id_(chat_id_)
  , story_list_(std::move(story_list_))
{}

const std::int32_t setChatActiveStoriesList::ID;

void setChatActiveStoriesList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatActiveStoriesList");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("story_list", static_cast<const BaseObject *>(story_list_.get()));
    s.store_class_end();
  }
}

setChatAffiliateProgram::setChatAffiliateProgram()
  : chat_id_()
  , parameters_()
{}

setChatAffiliateProgram::setChatAffiliateProgram(int53 chat_id_, object_ptr<affiliateProgramParameters> &&parameters_)
  : chat_id_(chat_id_)
  , parameters_(std::move(parameters_))
{}

const std::int32_t setChatAffiliateProgram::ID;

void setChatAffiliateProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatAffiliateProgram");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

setChatAvailableReactions::setChatAvailableReactions()
  : chat_id_()
  , available_reactions_()
{}

setChatAvailableReactions::setChatAvailableReactions(int53 chat_id_, object_ptr<ChatAvailableReactions> &&available_reactions_)
  : chat_id_(chat_id_)
  , available_reactions_(std::move(available_reactions_))
{}

const std::int32_t setChatAvailableReactions::ID;

void setChatAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatAvailableReactions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("available_reactions", static_cast<const BaseObject *>(available_reactions_.get()));
    s.store_class_end();
  }
}

setDefaultBackground::setDefaultBackground()
  : background_()
  , type_()
  , for_dark_theme_()
{}

setDefaultBackground::setDefaultBackground(object_ptr<InputBackground> &&background_, object_ptr<BackgroundType> &&type_, bool for_dark_theme_)
  : background_(std::move(background_))
  , type_(std::move(type_))
  , for_dark_theme_(for_dark_theme_)
{}

const std::int32_t setDefaultBackground::ID;

void setDefaultBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDefaultBackground");
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("for_dark_theme", for_dark_theme_);
    s.store_class_end();
  }
}

setDefaultReactionType::setDefaultReactionType()
  : reaction_type_()
{}

setDefaultReactionType::setDefaultReactionType(object_ptr<ReactionType> &&reaction_type_)
  : reaction_type_(std::move(reaction_type_))
{}

const std::int32_t setDefaultReactionType::ID;

void setDefaultReactionType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setDefaultReactionType");
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_class_end();
  }
}

setMessageReactions::setMessageReactions()
  : chat_id_()
  , message_id_()
  , reaction_types_()
  , is_big_()
{}

setMessageReactions::setMessageReactions(int53 chat_id_, int53 message_id_, array<object_ptr<ReactionType>> &&reaction_types_, bool is_big_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reaction_types_(std::move(reaction_types_))
  , is_big_(is_big_)
{}

const std::int32_t setMessageReactions::ID;

void setMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMessageReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("reaction_types", reaction_types_.size()); for (const auto &_value : reaction_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_big", is_big_);
    s.store_class_end();
  }
}

setOption::setOption()
  : name_()
  , value_()
{}

setOption::setOption(string const &name_, object_ptr<OptionValue> &&value_)
  : name_(name_)
  , value_(std::move(value_))
{}

const std::int32_t setOption::ID;

void setOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setOption");
    s.store_field("name", name_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

setPassportElement::setPassportElement()
  : element_()
  , password_()
{}

setPassportElement::setPassportElement(object_ptr<InputPassportElement> &&element_, string const &password_)
  : element_(std::move(element_))
  , password_(password_)
{}

const std::int32_t setPassportElement::ID;

void setPassportElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPassportElement");
    s.store_object_field("element", static_cast<const BaseObject *>(element_.get()));
    s.store_field("password", password_);
    s.store_class_end();
  }
}

setPinnedForumTopics::setPinnedForumTopics()
  : chat_id_()
  , forum_topic_ids_()
{}

setPinnedForumTopics::setPinnedForumTopics(int53 chat_id_, array<int32> &&forum_topic_ids_)
  : chat_id_(chat_id_)
  , forum_topic_ids_(std::move(forum_topic_ids_))
{}

const std::int32_t setPinnedForumTopics::ID;

void setPinnedForumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPinnedForumTopics");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("forum_topic_ids", forum_topic_ids_.size()); for (const auto &_value : forum_topic_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setReactionNotificationSettings::setReactionNotificationSettings()
  : notification_settings_()
{}

setReactionNotificationSettings::setReactionNotificationSettings(object_ptr<reactionNotificationSettings> &&notification_settings_)
  : notification_settings_(std::move(notification_settings_))
{}

const std::int32_t setReactionNotificationSettings::ID;

void setReactionNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setReactionNotificationSettings");
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

setScopeNotificationSettings::setScopeNotificationSettings()
  : scope_()
  , notification_settings_()
{}

setScopeNotificationSettings::setScopeNotificationSettings(object_ptr<NotificationSettingsScope> &&scope_, object_ptr<scopeNotificationSettings> &&notification_settings_)
  : scope_(std::move(scope_))
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t setScopeNotificationSettings::ID;

void setScopeNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setScopeNotificationSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

setStickerPositionInSet::setStickerPositionInSet()
  : sticker_()
  , position_()
{}

setStickerPositionInSet::setStickerPositionInSet(object_ptr<InputFile> &&sticker_, int32 position_)
  : sticker_(std::move(sticker_))
  , position_(position_)
{}

const std::int32_t setStickerPositionInSet::ID;

void setStickerPositionInSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerPositionInSet");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("position", position_);
    s.store_class_end();
  }
}

setSupergroupMainProfileTab::setSupergroupMainProfileTab()
  : supergroup_id_()
  , main_profile_tab_()
{}

setSupergroupMainProfileTab::setSupergroupMainProfileTab(int53 supergroup_id_, object_ptr<ProfileTab> &&main_profile_tab_)
  : supergroup_id_(supergroup_id_)
  , main_profile_tab_(std::move(main_profile_tab_))
{}

const std::int32_t setSupergroupMainProfileTab::ID;

void setSupergroupMainProfileTab::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSupergroupMainProfileTab");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_object_field("main_profile_tab", static_cast<const BaseObject *>(main_profile_tab_.get()));
    s.store_class_end();
  }
}

setUserSupportInfo::setUserSupportInfo()
  : user_id_()
  , message_()
{}

setUserSupportInfo::setUserSupportInfo(int53 user_id_, object_ptr<formattedText> &&message_)
  : user_id_(user_id_)
  , message_(std::move(message_))
{}

const std::int32_t setUserSupportInfo::ID;

void setUserSupportInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUserSupportInfo");
    s.store_field("user_id", user_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

startLiveStory::startLiveStory()
  : chat_id_()
  , privacy_settings_()
  , protect_content_()
  , is_rtmp_stream_()
  , enable_messages_()
  , paid_message_star_count_()
{}

startLiveStory::startLiveStory(int53 chat_id_, object_ptr<StoryPrivacySettings> &&privacy_settings_, bool protect_content_, bool is_rtmp_stream_, bool enable_messages_, int53 paid_message_star_count_)
  : chat_id_(chat_id_)
  , privacy_settings_(std::move(privacy_settings_))
  , protect_content_(protect_content_)
  , is_rtmp_stream_(is_rtmp_stream_)
  , enable_messages_(enable_messages_)
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t startLiveStory::ID;

void startLiveStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startLiveStory");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("privacy_settings", static_cast<const BaseObject *>(privacy_settings_.get()));
    s.store_field("protect_content", protect_content_);
    s.store_field("is_rtmp_stream", is_rtmp_stream_);
    s.store_field("enable_messages", enable_messages_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

stopBusinessPoll::stopBusinessPoll()
  : business_connection_id_()
  , chat_id_()
  , message_id_()
  , reply_markup_()
{}

stopBusinessPoll::stopBusinessPoll(string const &business_connection_id_, int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : business_connection_id_(business_connection_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t stopBusinessPoll::ID;

void stopBusinessPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stopBusinessPoll");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

synchronizeLanguagePack::synchronizeLanguagePack()
  : language_pack_id_()
{}

synchronizeLanguagePack::synchronizeLanguagePack(string const &language_pack_id_)
  : language_pack_id_(language_pack_id_)
{}

const std::int32_t synchronizeLanguagePack::ID;

void synchronizeLanguagePack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "synchronizeLanguagePack");
    s.store_field("language_pack_id", language_pack_id_);
    s.store_class_end();
  }
}

testGetDifference::testGetDifference() {
}

const std::int32_t testGetDifference::ID;

void testGetDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testGetDifference");
    s.store_class_end();
  }
}

toggleSupergroupHasAutomaticTranslation::toggleSupergroupHasAutomaticTranslation()
  : supergroup_id_()
  , has_automatic_translation_()
{}

toggleSupergroupHasAutomaticTranslation::toggleSupergroupHasAutomaticTranslation(int53 supergroup_id_, bool has_automatic_translation_)
  : supergroup_id_(supergroup_id_)
  , has_automatic_translation_(has_automatic_translation_)
{}

const std::int32_t toggleSupergroupHasAutomaticTranslation::ID;

void toggleSupergroupHasAutomaticTranslation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupHasAutomaticTranslation");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("has_automatic_translation", has_automatic_translation_);
    s.store_class_end();
  }
}

toggleSupergroupJoinToSendMessages::toggleSupergroupJoinToSendMessages()
  : supergroup_id_()
  , join_to_send_messages_()
{}

toggleSupergroupJoinToSendMessages::toggleSupergroupJoinToSendMessages(int53 supergroup_id_, bool join_to_send_messages_)
  : supergroup_id_(supergroup_id_)
  , join_to_send_messages_(join_to_send_messages_)
{}

const std::int32_t toggleSupergroupJoinToSendMessages::ID;

void toggleSupergroupJoinToSendMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupJoinToSendMessages");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("join_to_send_messages", join_to_send_messages_);
    s.store_class_end();
  }
}

toggleVideoChatMuteNewParticipants::toggleVideoChatMuteNewParticipants()
  : group_call_id_()
  , mute_new_participants_()
{}

toggleVideoChatMuteNewParticipants::toggleVideoChatMuteNewParticipants(int32 group_call_id_, bool mute_new_participants_)
  : group_call_id_(group_call_id_)
  , mute_new_participants_(mute_new_participants_)
{}

const std::int32_t toggleVideoChatMuteNewParticipants::ID;

void toggleVideoChatMuteNewParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleVideoChatMuteNewParticipants");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("mute_new_participants", mute_new_participants_);
    s.store_class_end();
  }
}

writeGeneratedFilePart::writeGeneratedFilePart()
  : generation_id_()
  , offset_()
  , data_()
{}

writeGeneratedFilePart::writeGeneratedFilePart(int64 generation_id_, int53 offset_, bytes const &data_)
  : generation_id_(generation_id_)
  , offset_(offset_)
  , data_(std::move(data_))
{}

const std::int32_t writeGeneratedFilePart::ID;

void writeGeneratedFilePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "writeGeneratedFilePart");
    s.store_field("generation_id", generation_id_);
    s.store_field("offset", offset_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
