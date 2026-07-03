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


accentColor::accentColor()
  : id_()
  , built_in_accent_color_id_()
  , light_theme_colors_()
  , dark_theme_colors_()
  , min_channel_chat_boost_level_()
{}

accentColor::accentColor(int32 id_, int32 built_in_accent_color_id_, array<int32> &&light_theme_colors_, array<int32> &&dark_theme_colors_, int32 min_channel_chat_boost_level_)
  : id_(id_)
  , built_in_accent_color_id_(built_in_accent_color_id_)
  , light_theme_colors_(std::move(light_theme_colors_))
  , dark_theme_colors_(std::move(dark_theme_colors_))
  , min_channel_chat_boost_level_(min_channel_chat_boost_level_)
{}

const std::int32_t accentColor::ID;

void accentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "accentColor");
    s.store_field("id", id_);
    s.store_field("built_in_accent_color_id", built_in_accent_color_id_);
    { s.store_vector_begin("light_theme_colors", light_theme_colors_.size()); for (const auto &_value : light_theme_colors_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("dark_theme_colors", dark_theme_colors_.size()); for (const auto &_value : dark_theme_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("min_channel_chat_boost_level", min_channel_chat_boost_level_);
    s.store_class_end();
  }
}

addedReaction::addedReaction()
  : type_()
  , sender_id_()
  , is_outgoing_()
  , date_()
{}

addedReaction::addedReaction(object_ptr<ReactionType> &&type_, object_ptr<MessageSender> &&sender_id_, bool is_outgoing_, int32 date_)
  : type_(std::move(type_))
  , sender_id_(std::move(sender_id_))
  , is_outgoing_(is_outgoing_)
  , date_(date_)
{}

const std::int32_t addedReaction::ID;

void addedReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addedReaction");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("is_outgoing", is_outgoing_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

alternativeVideo::alternativeVideo()
  : id_()
  , width_()
  , height_()
  , codec_()
  , hls_file_()
  , video_()
{}

alternativeVideo::alternativeVideo(int64 id_, int32 width_, int32 height_, string const &codec_, object_ptr<file> &&hls_file_, object_ptr<file> &&video_)
  : id_(id_)
  , width_(width_)
  , height_(height_)
  , codec_(codec_)
  , hls_file_(std::move(hls_file_))
  , video_(std::move(video_))
{}

const std::int32_t alternativeVideo::ID;

void alternativeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "alternativeVideo");
    s.store_field("id", id_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("codec", codec_);
    s.store_object_field("hls_file", static_cast<const BaseObject *>(hls_file_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

animatedChatPhoto::animatedChatPhoto()
  : length_()
  , file_()
  , main_frame_timestamp_()
{}

animatedChatPhoto::animatedChatPhoto(int32 length_, object_ptr<file> &&file_, double main_frame_timestamp_)
  : length_(length_)
  , file_(std::move(file_))
  , main_frame_timestamp_(main_frame_timestamp_)
{}

const std::int32_t animatedChatPhoto::ID;

void animatedChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "animatedChatPhoto");
    s.store_field("length", length_);
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_field("main_frame_timestamp", main_frame_timestamp_);
    s.store_class_end();
  }
}

background::background()
  : id_()
  , is_default_()
  , is_dark_()
  , name_()
  , document_()
  , type_()
{}

background::background(int64 id_, bool is_default_, bool is_dark_, string const &name_, object_ptr<document> &&document_, object_ptr<BackgroundType> &&type_)
  : id_(id_)
  , is_default_(is_default_)
  , is_dark_(is_dark_)
  , name_(name_)
  , document_(std::move(document_))
  , type_(std::move(type_))
{}

const std::int32_t background::ID;

void background::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "background");
    s.store_field("id", id_);
    s.store_field("is_default", is_default_);
    s.store_field("is_dark", is_dark_);
    s.store_field("name", name_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

backgroundFillSolid::backgroundFillSolid()
  : color_()
{}

backgroundFillSolid::backgroundFillSolid(int32 color_)
  : color_(color_)
{}

const std::int32_t backgroundFillSolid::ID;

void backgroundFillSolid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundFillSolid");
    s.store_field("color", color_);
    s.store_class_end();
  }
}

backgroundFillGradient::backgroundFillGradient()
  : top_color_()
  , bottom_color_()
  , rotation_angle_()
{}

backgroundFillGradient::backgroundFillGradient(int32 top_color_, int32 bottom_color_, int32 rotation_angle_)
  : top_color_(top_color_)
  , bottom_color_(bottom_color_)
  , rotation_angle_(rotation_angle_)
{}

const std::int32_t backgroundFillGradient::ID;

void backgroundFillGradient::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundFillGradient");
    s.store_field("top_color", top_color_);
    s.store_field("bottom_color", bottom_color_);
    s.store_field("rotation_angle", rotation_angle_);
    s.store_class_end();
  }
}

backgroundFillFreeformGradient::backgroundFillFreeformGradient()
  : colors_()
{}

backgroundFillFreeformGradient::backgroundFillFreeformGradient(array<int32> &&colors_)
  : colors_(std::move(colors_))
{}

const std::int32_t backgroundFillFreeformGradient::ID;

void backgroundFillFreeformGradient::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "backgroundFillFreeformGradient");
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

bankCardActionOpenUrl::bankCardActionOpenUrl()
  : text_()
  , url_()
{}

bankCardActionOpenUrl::bankCardActionOpenUrl(string const &text_, string const &url_)
  : text_(text_)
  , url_(url_)
{}

const std::int32_t bankCardActionOpenUrl::ID;

void bankCardActionOpenUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bankCardActionOpenUrl");
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

botMediaPreviewInfo::botMediaPreviewInfo()
  : previews_()
  , language_codes_()
{}

botMediaPreviewInfo::botMediaPreviewInfo(array<object_ptr<botMediaPreview>> &&previews_, array<string> &&language_codes_)
  : previews_(std::move(previews_))
  , language_codes_(std::move(language_codes_))
{}

const std::int32_t botMediaPreviewInfo::ID;

void botMediaPreviewInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMediaPreviewInfo");
    { s.store_vector_begin("previews", previews_.size()); for (const auto &_value : previews_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("language_codes", language_codes_.size()); for (const auto &_value : language_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

businessConnectedBot::businessConnectedBot()
  : bot_user_id_()
  , recipients_()
  , rights_()
{}

businessConnectedBot::businessConnectedBot(int53 bot_user_id_, object_ptr<businessRecipients> &&recipients_, object_ptr<businessBotRights> &&rights_)
  : bot_user_id_(bot_user_id_)
  , recipients_(std::move(recipients_))
  , rights_(std::move(rights_))
{}

const std::int32_t businessConnectedBot::ID;

void businessConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessConnectedBot");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get()));
    s.store_class_end();
  }
}

businessLocation::businessLocation()
  : location_()
  , address_()
{}

businessLocation::businessLocation(object_ptr<location> &&location_, string const &address_)
  : location_(std::move(location_))
  , address_(address_)
{}

const std::int32_t businessLocation::ID;

void businessLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("address", address_);
    s.store_class_end();
  }
}

businessRecipients::businessRecipients()
  : chat_ids_()
  , excluded_chat_ids_()
  , select_existing_chats_()
  , select_new_chats_()
  , select_contacts_()
  , select_non_contacts_()
  , exclude_selected_()
{}

businessRecipients::businessRecipients(array<int53> &&chat_ids_, array<int53> &&excluded_chat_ids_, bool select_existing_chats_, bool select_new_chats_, bool select_contacts_, bool select_non_contacts_, bool exclude_selected_)
  : chat_ids_(std::move(chat_ids_))
  , excluded_chat_ids_(std::move(excluded_chat_ids_))
  , select_existing_chats_(select_existing_chats_)
  , select_new_chats_(select_new_chats_)
  , select_contacts_(select_contacts_)
  , select_non_contacts_(select_non_contacts_)
  , exclude_selected_(exclude_selected_)
{}

const std::int32_t businessRecipients::ID;

void businessRecipients::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessRecipients");
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("excluded_chat_ids", excluded_chat_ids_.size()); for (const auto &_value : excluded_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("select_existing_chats", select_existing_chats_);
    s.store_field("select_new_chats", select_new_chats_);
    s.store_field("select_contacts", select_contacts_);
    s.store_field("select_non_contacts", select_non_contacts_);
    s.store_field("exclude_selected", exclude_selected_);
    s.store_class_end();
  }
}

callProtocol::callProtocol()
  : udp_p2p_()
  , udp_reflector_()
  , min_layer_()
  , max_layer_()
  , library_versions_()
{}

callProtocol::callProtocol(bool udp_p2p_, bool udp_reflector_, int32 min_layer_, int32 max_layer_, array<string> &&library_versions_)
  : udp_p2p_(udp_p2p_)
  , udp_reflector_(udp_reflector_)
  , min_layer_(min_layer_)
  , max_layer_(max_layer_)
  , library_versions_(std::move(library_versions_))
{}

const std::int32_t callProtocol::ID;

void callProtocol::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callProtocol");
    s.store_field("udp_p2p", udp_p2p_);
    s.store_field("udp_reflector", udp_reflector_);
    s.store_field("min_layer", min_layer_);
    s.store_field("max_layer", max_layer_);
    { s.store_vector_begin("library_versions", library_versions_.size()); for (const auto &_value : library_versions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

callServer::callServer()
  : id_()
  , ip_address_()
  , ipv6_address_()
  , port_()
  , type_()
{}

callServer::callServer(int64 id_, string const &ip_address_, string const &ipv6_address_, int32 port_, object_ptr<CallServerType> &&type_)
  : id_(id_)
  , ip_address_(ip_address_)
  , ipv6_address_(ipv6_address_)
  , port_(port_)
  , type_(std::move(type_))
{}

const std::int32_t callServer::ID;

void callServer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callServer");
    s.store_field("id", id_);
    s.store_field("ip_address", ip_address_);
    s.store_field("ipv6_address", ipv6_address_);
    s.store_field("port", port_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

canSendGiftResultOk::canSendGiftResultOk() {
}

const std::int32_t canSendGiftResultOk::ID;

void canSendGiftResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendGiftResultOk");
    s.store_class_end();
  }
}

canSendGiftResultFail::canSendGiftResultFail()
  : reason_()
{}

canSendGiftResultFail::canSendGiftResultFail(object_ptr<formattedText> &&reason_)
  : reason_(std::move(reason_))
{}

const std::int32_t canSendGiftResultFail::ID;

void canSendGiftResultFail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canSendGiftResultFail");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_class_end();
  }
}

chatAdministrators::chatAdministrators()
  : administrators_()
{}

chatAdministrators::chatAdministrators(array<object_ptr<chatAdministrator>> &&administrators_)
  : administrators_(std::move(administrators_))
{}

const std::int32_t chatAdministrators::ID;

void chatAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdministrators");
    { s.store_vector_begin("administrators", administrators_.size()); for (const auto &_value : administrators_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatBoost::chatBoost()
  : id_()
  , count_()
  , source_()
  , start_date_()
  , expiration_date_()
{}

chatBoost::chatBoost(string const &id_, int32 count_, object_ptr<ChatBoostSource> &&source_, int32 start_date_, int32 expiration_date_)
  : id_(id_)
  , count_(count_)
  , source_(std::move(source_))
  , start_date_(start_date_)
  , expiration_date_(expiration_date_)
{}

const std::int32_t chatBoost::ID;

void chatBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoost");
    s.store_field("id", id_);
    s.store_field("count", count_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("start_date", start_date_);
    s.store_field("expiration_date", expiration_date_);
    s.store_class_end();
  }
}

chatBoostSourceGiftCode::chatBoostSourceGiftCode()
  : user_id_()
  , gift_code_()
{}

chatBoostSourceGiftCode::chatBoostSourceGiftCode(int53 user_id_, string const &gift_code_)
  : user_id_(user_id_)
  , gift_code_(gift_code_)
{}

const std::int32_t chatBoostSourceGiftCode::ID;

void chatBoostSourceGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostSourceGiftCode");
    s.store_field("user_id", user_id_);
    s.store_field("gift_code", gift_code_);
    s.store_class_end();
  }
}

chatBoostSourceGiveaway::chatBoostSourceGiveaway()
  : user_id_()
  , gift_code_()
  , star_count_()
  , giveaway_message_id_()
  , is_unclaimed_()
{}

chatBoostSourceGiveaway::chatBoostSourceGiveaway(int53 user_id_, string const &gift_code_, int53 star_count_, int53 giveaway_message_id_, bool is_unclaimed_)
  : user_id_(user_id_)
  , gift_code_(gift_code_)
  , star_count_(star_count_)
  , giveaway_message_id_(giveaway_message_id_)
  , is_unclaimed_(is_unclaimed_)
{}

const std::int32_t chatBoostSourceGiveaway::ID;

void chatBoostSourceGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostSourceGiveaway");
    s.store_field("user_id", user_id_);
    s.store_field("gift_code", gift_code_);
    s.store_field("star_count", star_count_);
    s.store_field("giveaway_message_id", giveaway_message_id_);
    s.store_field("is_unclaimed", is_unclaimed_);
    s.store_class_end();
  }
}

chatBoostSourcePremium::chatBoostSourcePremium()
  : user_id_()
{}

chatBoostSourcePremium::chatBoostSourcePremium(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t chatBoostSourcePremium::ID;

void chatBoostSourcePremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostSourcePremium");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

chatFolderInviteLinkInfo::chatFolderInviteLinkInfo()
  : chat_folder_info_()
  , missing_chat_ids_()
  , added_chat_ids_()
{}

chatFolderInviteLinkInfo::chatFolderInviteLinkInfo(object_ptr<chatFolderInfo> &&chat_folder_info_, array<int53> &&missing_chat_ids_, array<int53> &&added_chat_ids_)
  : chat_folder_info_(std::move(chat_folder_info_))
  , missing_chat_ids_(std::move(missing_chat_ids_))
  , added_chat_ids_(std::move(added_chat_ids_))
{}

const std::int32_t chatFolderInviteLinkInfo::ID;

void chatFolderInviteLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolderInviteLinkInfo");
    s.store_object_field("chat_folder_info", static_cast<const BaseObject *>(chat_folder_info_.get()));
    { s.store_vector_begin("missing_chat_ids", missing_chat_ids_.size()); for (const auto &_value : missing_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("added_chat_ids", added_chat_ids_.size()); for (const auto &_value : added_chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatMember::chatMember()
  : member_id_()
  , tag_()
  , inviter_user_id_()
  , joined_chat_date_()
  , status_()
{}

chatMember::chatMember(object_ptr<MessageSender> &&member_id_, string const &tag_, int53 inviter_user_id_, int32 joined_chat_date_, object_ptr<ChatMemberStatus> &&status_)
  : member_id_(std::move(member_id_))
  , tag_(tag_)
  , inviter_user_id_(inviter_user_id_)
  , joined_chat_date_(joined_chat_date_)
  , status_(std::move(status_))
{}

const std::int32_t chatMember::ID;

void chatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatMember");
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_field("tag", tag_);
    s.store_field("inviter_user_id", inviter_user_id_);
    s.store_field("joined_chat_date", joined_chat_date_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

chatPhotoSticker::chatPhotoSticker()
  : type_()
  , background_fill_()
{}

chatPhotoSticker::chatPhotoSticker(object_ptr<ChatPhotoStickerType> &&type_, object_ptr<BackgroundFill> &&background_fill_)
  : type_(std::move(type_))
  , background_fill_(std::move(background_fill_))
{}

const std::int32_t chatPhotoSticker::ID;

void chatPhotoSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotoSticker");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_object_field("background_fill", static_cast<const BaseObject *>(background_fill_.get()));
    s.store_class_end();
  }
}

chatPosition::chatPosition()
  : list_()
  , order_()
  , is_pinned_()
  , source_()
{}

chatPosition::chatPosition(object_ptr<ChatList> &&list_, int64 order_, bool is_pinned_, object_ptr<ChatSource> &&source_)
  : list_(std::move(list_))
  , order_(order_)
  , is_pinned_(is_pinned_)
  , source_(std::move(source_))
{}

const std::int32_t chatPosition::ID;

void chatPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPosition");
    s.store_object_field("list", static_cast<const BaseObject *>(list_.get()));
    s.store_field("order", order_);
    s.store_field("is_pinned", is_pinned_);
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_class_end();
  }
}

chatRevenueStatistics::chatRevenueStatistics()
  : revenue_by_hour_graph_()
  , revenue_graph_()
  , revenue_amount_()
  , usd_rate_()
{}

chatRevenueStatistics::chatRevenueStatistics(object_ptr<StatisticalGraph> &&revenue_by_hour_graph_, object_ptr<StatisticalGraph> &&revenue_graph_, object_ptr<chatRevenueAmount> &&revenue_amount_, double usd_rate_)
  : revenue_by_hour_graph_(std::move(revenue_by_hour_graph_))
  , revenue_graph_(std::move(revenue_graph_))
  , revenue_amount_(std::move(revenue_amount_))
  , usd_rate_(usd_rate_)
{}

const std::int32_t chatRevenueStatistics::ID;

void chatRevenueStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatRevenueStatistics");
    s.store_object_field("revenue_by_hour_graph", static_cast<const BaseObject *>(revenue_by_hour_graph_.get()));
    s.store_object_field("revenue_graph", static_cast<const BaseObject *>(revenue_graph_.get()));
    s.store_object_field("revenue_amount", static_cast<const BaseObject *>(revenue_amount_.get()));
    s.store_field("usd_rate", usd_rate_);
    s.store_class_end();
  }
}

chatSourceMtprotoProxy::chatSourceMtprotoProxy() {
}

const std::int32_t chatSourceMtprotoProxy::ID;

void chatSourceMtprotoProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatSourceMtprotoProxy");
    s.store_class_end();
  }
}

chatSourcePublicServiceAnnouncement::chatSourcePublicServiceAnnouncement()
  : type_()
  , text_()
{}

chatSourcePublicServiceAnnouncement::chatSourcePublicServiceAnnouncement(string const &type_, string const &text_)
  : type_(type_)
  , text_(text_)
{}

const std::int32_t chatSourcePublicServiceAnnouncement::ID;

void chatSourcePublicServiceAnnouncement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatSourcePublicServiceAnnouncement");
    s.store_field("type", type_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

chatStatisticsAdministratorActionsInfo::chatStatisticsAdministratorActionsInfo()
  : user_id_()
  , deleted_message_count_()
  , banned_user_count_()
  , restricted_user_count_()
{}

chatStatisticsAdministratorActionsInfo::chatStatisticsAdministratorActionsInfo(int53 user_id_, int32 deleted_message_count_, int32 banned_user_count_, int32 restricted_user_count_)
  : user_id_(user_id_)
  , deleted_message_count_(deleted_message_count_)
  , banned_user_count_(banned_user_count_)
  , restricted_user_count_(restricted_user_count_)
{}

const std::int32_t chatStatisticsAdministratorActionsInfo::ID;

void chatStatisticsAdministratorActionsInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatStatisticsAdministratorActionsInfo");
    s.store_field("user_id", user_id_);
    s.store_field("deleted_message_count", deleted_message_count_);
    s.store_field("banned_user_count", banned_user_count_);
    s.store_field("restricted_user_count", restricted_user_count_);
    s.store_class_end();
  }
}

chats::chats()
  : total_count_()
  , chat_ids_()
{}

chats::chats(int32 total_count_, array<int53> &&chat_ids_)
  : total_count_(total_count_)
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t chats::ID;

void chats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chats");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

closeBirthdayUser::closeBirthdayUser()
  : user_id_()
  , birthdate_()
{}

closeBirthdayUser::closeBirthdayUser(int53 user_id_, object_ptr<birthdate> &&birthdate_)
  : user_id_(user_id_)
  , birthdate_(std::move(birthdate_))
{}

const std::int32_t closeBirthdayUser::ID;

void closeBirthdayUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeBirthdayUser");
    s.store_field("user_id", user_id_);
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_class_end();
  }
}

createdBasicGroupChat::createdBasicGroupChat()
  : chat_id_()
  , failed_to_add_members_()
{}

createdBasicGroupChat::createdBasicGroupChat(int53 chat_id_, object_ptr<failedToAddMembers> &&failed_to_add_members_)
  : chat_id_(chat_id_)
  , failed_to_add_members_(std::move(failed_to_add_members_))
{}

const std::int32_t createdBasicGroupChat::ID;

void createdBasicGroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createdBasicGroupChat");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("failed_to_add_members", static_cast<const BaseObject *>(failed_to_add_members_.get()));
    s.store_class_end();
  }
}

datedFile::datedFile()
  : file_()
  , date_()
{}

datedFile::datedFile(object_ptr<file> &&file_, int32 date_)
  : file_(std::move(file_))
  , date_(date_)
{}

const std::int32_t datedFile::ID;

void datedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "datedFile");
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

deepLinkInfo::deepLinkInfo()
  : text_()
  , need_update_application_()
{}

deepLinkInfo::deepLinkInfo(object_ptr<formattedText> &&text_, bool need_update_application_)
  : text_(std::move(text_))
  , need_update_application_(need_update_application_)
{}

const std::int32_t deepLinkInfo::ID;

void deepLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deepLinkInfo");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("need_update_application", need_update_application_);
    s.store_class_end();
  }
}

emojiReaction::emojiReaction()
  : emoji_()
  , title_()
  , is_active_()
  , static_icon_()
  , appear_animation_()
  , select_animation_()
  , activate_animation_()
  , effect_animation_()
  , around_animation_()
  , center_animation_()
{}

emojiReaction::emojiReaction(string const &emoji_, string const &title_, bool is_active_, object_ptr<sticker> &&static_icon_, object_ptr<sticker> &&appear_animation_, object_ptr<sticker> &&select_animation_, object_ptr<sticker> &&activate_animation_, object_ptr<sticker> &&effect_animation_, object_ptr<sticker> &&around_animation_, object_ptr<sticker> &&center_animation_)
  : emoji_(emoji_)
  , title_(title_)
  , is_active_(is_active_)
  , static_icon_(std::move(static_icon_))
  , appear_animation_(std::move(appear_animation_))
  , select_animation_(std::move(select_animation_))
  , activate_animation_(std::move(activate_animation_))
  , effect_animation_(std::move(effect_animation_))
  , around_animation_(std::move(around_animation_))
  , center_animation_(std::move(center_animation_))
{}

const std::int32_t emojiReaction::ID;

void emojiReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiReaction");
    s.store_field("emoji", emoji_);
    s.store_field("title", title_);
    s.store_field("is_active", is_active_);
    s.store_object_field("static_icon", static_cast<const BaseObject *>(static_icon_.get()));
    s.store_object_field("appear_animation", static_cast<const BaseObject *>(appear_animation_.get()));
    s.store_object_field("select_animation", static_cast<const BaseObject *>(select_animation_.get()));
    s.store_object_field("activate_animation", static_cast<const BaseObject *>(activate_animation_.get()));
    s.store_object_field("effect_animation", static_cast<const BaseObject *>(effect_animation_.get()));
    s.store_object_field("around_animation", static_cast<const BaseObject *>(around_animation_.get()));
    s.store_object_field("center_animation", static_cast<const BaseObject *>(center_animation_.get()));
    s.store_class_end();
  }
}

failedToAddMember::failedToAddMember()
  : user_id_()
  , premium_would_allow_invite_()
  , premium_required_to_send_messages_()
{}

failedToAddMember::failedToAddMember(int53 user_id_, bool premium_would_allow_invite_, bool premium_required_to_send_messages_)
  : user_id_(user_id_)
  , premium_would_allow_invite_(premium_would_allow_invite_)
  , premium_required_to_send_messages_(premium_required_to_send_messages_)
{}

const std::int32_t failedToAddMember::ID;

void failedToAddMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "failedToAddMember");
    s.store_field("user_id", user_id_);
    s.store_field("premium_would_allow_invite", premium_would_allow_invite_);
    s.store_field("premium_required_to_send_messages", premium_required_to_send_messages_);
    s.store_class_end();
  }
}

firebaseAuthenticationSettingsAndroid::firebaseAuthenticationSettingsAndroid() {
}

const std::int32_t firebaseAuthenticationSettingsAndroid::ID;

void firebaseAuthenticationSettingsAndroid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "firebaseAuthenticationSettingsAndroid");
    s.store_class_end();
  }
}

firebaseAuthenticationSettingsIos::firebaseAuthenticationSettingsIos()
  : device_token_()
  , is_app_sandbox_()
{}

firebaseAuthenticationSettingsIos::firebaseAuthenticationSettingsIos(string const &device_token_, bool is_app_sandbox_)
  : device_token_(device_token_)
  , is_app_sandbox_(is_app_sandbox_)
{}

const std::int32_t firebaseAuthenticationSettingsIos::ID;

void firebaseAuthenticationSettingsIos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "firebaseAuthenticationSettingsIos");
    s.store_field("device_token", device_token_);
    s.store_field("is_app_sandbox", is_app_sandbox_);
    s.store_class_end();
  }
}

foundMessages::foundMessages()
  : total_count_()
  , messages_()
  , next_offset_()
{}

foundMessages::foundMessages(int32 total_count_, array<object_ptr<message>> &&messages_, string const &next_offset_)
  : total_count_(total_count_)
  , messages_(std::move(messages_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundMessages::ID;

void foundMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundMessages");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

foundPosition::foundPosition()
  : position_()
{}

foundPosition::foundPosition(int32 position_)
  : position_(position_)
{}

const std::int32_t foundPosition::ID;

void foundPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundPosition");
    s.store_field("position", position_);
    s.store_class_end();
  }
}

giftAuctionAcquiredGift::giftAuctionAcquiredGift()
  : receiver_id_()
  , date_()
  , star_count_()
  , auction_round_number_()
  , auction_round_position_()
  , unique_gift_number_()
  , text_()
  , is_private_()
{}

giftAuctionAcquiredGift::giftAuctionAcquiredGift(object_ptr<MessageSender> &&receiver_id_, int32 date_, int53 star_count_, int32 auction_round_number_, int32 auction_round_position_, int32 unique_gift_number_, object_ptr<formattedText> &&text_, bool is_private_)
  : receiver_id_(std::move(receiver_id_))
  , date_(date_)
  , star_count_(star_count_)
  , auction_round_number_(auction_round_number_)
  , auction_round_position_(auction_round_position_)
  , unique_gift_number_(unique_gift_number_)
  , text_(std::move(text_))
  , is_private_(is_private_)
{}

const std::int32_t giftAuctionAcquiredGift::ID;

void giftAuctionAcquiredGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftAuctionAcquiredGift");
    s.store_object_field("receiver_id", static_cast<const BaseObject *>(receiver_id_.get()));
    s.store_field("date", date_);
    s.store_field("star_count", star_count_);
    s.store_field("auction_round_number", auction_round_number_);
    s.store_field("auction_round_position", auction_round_position_);
    s.store_field("unique_gift_number", unique_gift_number_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_private", is_private_);
    s.store_class_end();
  }
}

giftResalePriceStar::giftResalePriceStar()
  : star_count_()
{}

giftResalePriceStar::giftResalePriceStar(int53 star_count_)
  : star_count_(star_count_)
{}

const std::int32_t giftResalePriceStar::ID;

void giftResalePriceStar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftResalePriceStar");
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

giftResalePriceTon::giftResalePriceTon()
  : toncoin_cent_count_()
{}

giftResalePriceTon::giftResalePriceTon(int53 toncoin_cent_count_)
  : toncoin_cent_count_(toncoin_cent_count_)
{}

const std::int32_t giftResalePriceTon::ID;

void giftResalePriceTon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftResalePriceTon");
    s.store_field("toncoin_cent_count", toncoin_cent_count_);
    s.store_class_end();
  }
}

giftUpgradePreview::giftUpgradePreview()
  : models_()
  , symbols_()
  , backdrops_()
  , prices_()
  , next_prices_()
{}

giftUpgradePreview::giftUpgradePreview(array<object_ptr<upgradedGiftModel>> &&models_, array<object_ptr<upgradedGiftSymbol>> &&symbols_, array<object_ptr<upgradedGiftBackdrop>> &&backdrops_, array<object_ptr<giftUpgradePrice>> &&prices_, array<object_ptr<giftUpgradePrice>> &&next_prices_)
  : models_(std::move(models_))
  , symbols_(std::move(symbols_))
  , backdrops_(std::move(backdrops_))
  , prices_(std::move(prices_))
  , next_prices_(std::move(next_prices_))
{}

const std::int32_t giftUpgradePreview::ID;

void giftUpgradePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftUpgradePreview");
    { s.store_vector_begin("models", models_.size()); for (const auto &_value : models_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("symbols", symbols_.size()); for (const auto &_value : symbols_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("backdrops", backdrops_.size()); for (const auto &_value : backdrops_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("prices", prices_.size()); for (const auto &_value : prices_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("next_prices", next_prices_.size()); for (const auto &_value : next_prices_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

giftsForResale::giftsForResale()
  : total_count_()
  , gifts_()
  , models_()
  , symbols_()
  , backdrops_()
  , next_offset_()
{}

giftsForResale::giftsForResale(int32 total_count_, array<object_ptr<giftForResale>> &&gifts_, array<object_ptr<upgradedGiftModelCount>> &&models_, array<object_ptr<upgradedGiftSymbolCount>> &&symbols_, array<object_ptr<upgradedGiftBackdropCount>> &&backdrops_, string const &next_offset_)
  : total_count_(total_count_)
  , gifts_(std::move(gifts_))
  , models_(std::move(models_))
  , symbols_(std::move(symbols_))
  , backdrops_(std::move(backdrops_))
  , next_offset_(next_offset_)
{}

const std::int32_t giftsForResale::ID;

void giftsForResale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftsForResale");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("models", models_.size()); for (const auto &_value : models_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("symbols", symbols_.size()); for (const auto &_value : symbols_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("backdrops", backdrops_.size()); for (const auto &_value : backdrops_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

groupCallMessage::groupCallMessage()
  : message_id_()
  , sender_id_()
  , date_()
  , text_()
  , paid_message_star_count_()
  , is_from_owner_()
  , can_be_deleted_()
{}

groupCallMessage::groupCallMessage(int32 message_id_, object_ptr<MessageSender> &&sender_id_, int32 date_, object_ptr<formattedText> &&text_, int53 paid_message_star_count_, bool is_from_owner_, bool can_be_deleted_)
  : message_id_(message_id_)
  , sender_id_(std::move(sender_id_))
  , date_(date_)
  , text_(std::move(text_))
  , paid_message_star_count_(paid_message_star_count_)
  , is_from_owner_(is_from_owner_)
  , can_be_deleted_(can_be_deleted_)
{}

const std::int32_t groupCallMessage::ID;

void groupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallMessage");
    s.store_field("message_id", message_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("date", date_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_field("is_from_owner", is_from_owner_);
    s.store_field("can_be_deleted", can_be_deleted_);
    s.store_class_end();
  }
}

identityDocument::identityDocument()
  : number_()
  , expiration_date_()
  , front_side_()
  , reverse_side_()
  , selfie_()
  , translation_()
{}

identityDocument::identityDocument(string const &number_, object_ptr<date> &&expiration_date_, object_ptr<datedFile> &&front_side_, object_ptr<datedFile> &&reverse_side_, object_ptr<datedFile> &&selfie_, array<object_ptr<datedFile>> &&translation_)
  : number_(number_)
  , expiration_date_(std::move(expiration_date_))
  , front_side_(std::move(front_side_))
  , reverse_side_(std::move(reverse_side_))
  , selfie_(std::move(selfie_))
  , translation_(std::move(translation_))
{}

const std::int32_t identityDocument::ID;

void identityDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "identityDocument");
    s.store_field("number", number_);
    s.store_object_field("expiration_date", static_cast<const BaseObject *>(expiration_date_.get()));
    s.store_object_field("front_side", static_cast<const BaseObject *>(front_side_.get()));
    s.store_object_field("reverse_side", static_cast<const BaseObject *>(reverse_side_.get()));
    s.store_object_field("selfie", static_cast<const BaseObject *>(selfie_.get()));
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inlineQueryResultsButton::inlineQueryResultsButton()
  : text_()
  , type_()
{}

inlineQueryResultsButton::inlineQueryResultsButton(string const &text_, object_ptr<InlineQueryResultsButtonType> &&type_)
  : text_(text_)
  , type_(std::move(type_))
{}

const std::int32_t inlineQueryResultsButton::ID;

void inlineQueryResultsButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResultsButton");
    s.store_field("text", text_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

inputMessageText::inputMessageText()
  : text_()
  , link_preview_options_()
  , clear_draft_()
{}

inputMessageText::inputMessageText(object_ptr<formattedText> &&text_, object_ptr<linkPreviewOptions> &&link_preview_options_, bool clear_draft_)
  : text_(std::move(text_))
  , link_preview_options_(std::move(link_preview_options_))
  , clear_draft_(clear_draft_)
{}

const std::int32_t inputMessageText::ID;

void inputMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("link_preview_options", static_cast<const BaseObject *>(link_preview_options_.get()));
    s.store_field("clear_draft", clear_draft_);
    s.store_class_end();
  }
}

inputMessageAnimation::inputMessageAnimation()
  : animation_()
  , thumbnail_()
  , added_sticker_file_ids_()
  , duration_()
  , width_()
  , height_()
  , caption_()
  , show_caption_above_media_()
  , has_spoiler_()
{}

inputMessageAnimation::inputMessageAnimation(object_ptr<InputFile> &&animation_, object_ptr<inputThumbnail> &&thumbnail_, array<int32> &&added_sticker_file_ids_, int32 duration_, int32 width_, int32 height_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, bool has_spoiler_)
  : animation_(std::move(animation_))
  , thumbnail_(std::move(thumbnail_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , duration_(duration_)
  , width_(width_)
  , height_(height_)
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , has_spoiler_(has_spoiler_)
{}

const std::int32_t inputMessageAnimation::ID;

void inputMessageAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_field("has_spoiler", has_spoiler_);
    s.store_class_end();
  }
}

inputMessageAudio::inputMessageAudio()
  : audio_()
  , album_cover_thumbnail_()
  , duration_()
  , title_()
  , performer_()
  , caption_()
{}

inputMessageAudio::inputMessageAudio(object_ptr<InputFile> &&audio_, object_ptr<inputThumbnail> &&album_cover_thumbnail_, int32 duration_, string const &title_, string const &performer_, object_ptr<formattedText> &&caption_)
  : audio_(std::move(audio_))
  , album_cover_thumbnail_(std::move(album_cover_thumbnail_))
  , duration_(duration_)
  , title_(title_)
  , performer_(performer_)
  , caption_(std::move(caption_))
{}

const std::int32_t inputMessageAudio::ID;

void inputMessageAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("album_cover_thumbnail", static_cast<const BaseObject *>(album_cover_thumbnail_.get()));
    s.store_field("duration", duration_);
    s.store_field("title", title_);
    s.store_field("performer", performer_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputMessageDocument::inputMessageDocument()
  : document_()
  , thumbnail_()
  , disable_content_type_detection_()
  , caption_()
{}

inputMessageDocument::inputMessageDocument(object_ptr<InputFile> &&document_, object_ptr<inputThumbnail> &&thumbnail_, bool disable_content_type_detection_, object_ptr<formattedText> &&caption_)
  : document_(std::move(document_))
  , thumbnail_(std::move(thumbnail_))
  , disable_content_type_detection_(disable_content_type_detection_)
  , caption_(std::move(caption_))
{}

const std::int32_t inputMessageDocument::ID;

void inputMessageDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("disable_content_type_detection", disable_content_type_detection_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

inputMessagePaidMedia::inputMessagePaidMedia()
  : star_count_()
  , paid_media_()
  , caption_()
  , show_caption_above_media_()
  , payload_()
{}

inputMessagePaidMedia::inputMessagePaidMedia(int53 star_count_, array<object_ptr<inputPaidMedia>> &&paid_media_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, string const &payload_)
  : star_count_(star_count_)
  , paid_media_(std::move(paid_media_))
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , payload_(payload_)
{}

const std::int32_t inputMessagePaidMedia::ID;

void inputMessagePaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagePaidMedia");
    s.store_field("star_count", star_count_);
    { s.store_vector_begin("paid_media", paid_media_.size()); for (const auto &_value : paid_media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

inputMessagePhoto::inputMessagePhoto()
  : photo_()
  , thumbnail_()
  , video_()
  , added_sticker_file_ids_()
  , width_()
  , height_()
  , caption_()
  , show_caption_above_media_()
  , self_destruct_type_()
  , has_spoiler_()
{}

inputMessagePhoto::inputMessagePhoto(object_ptr<InputFile> &&photo_, object_ptr<inputThumbnail> &&thumbnail_, object_ptr<InputFile> &&video_, array<int32> &&added_sticker_file_ids_, int32 width_, int32 height_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, object_ptr<MessageSelfDestructType> &&self_destruct_type_, bool has_spoiler_)
  : photo_(std::move(photo_))
  , thumbnail_(std::move(thumbnail_))
  , video_(std::move(video_))
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , width_(width_)
  , height_(height_)
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , self_destruct_type_(std::move(self_destruct_type_))
  , has_spoiler_(has_spoiler_)
{}

const std::int32_t inputMessagePhoto::ID;

void inputMessagePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_object_field("self_destruct_type", static_cast<const BaseObject *>(self_destruct_type_.get()));
    s.store_field("has_spoiler", has_spoiler_);
    s.store_class_end();
  }
}

inputMessageSticker::inputMessageSticker()
  : sticker_()
  , thumbnail_()
  , width_()
  , height_()
  , emoji_()
{}

inputMessageSticker::inputMessageSticker(object_ptr<InputFile> &&sticker_, object_ptr<inputThumbnail> &&thumbnail_, int32 width_, int32 height_, string const &emoji_)
  : sticker_(std::move(sticker_))
  , thumbnail_(std::move(thumbnail_))
  , width_(width_)
  , height_(height_)
  , emoji_(emoji_)
{}

const std::int32_t inputMessageSticker::ID;

void inputMessageSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("emoji", emoji_);
    s.store_class_end();
  }
}

inputMessageVideo::inputMessageVideo()
  : video_()
  , thumbnail_()
  , cover_()
  , start_timestamp_()
  , added_sticker_file_ids_()
  , duration_()
  , width_()
  , height_()
  , supports_streaming_()
  , caption_()
  , show_caption_above_media_()
  , self_destruct_type_()
  , has_spoiler_()
{}

inputMessageVideo::inputMessageVideo(object_ptr<InputFile> &&video_, object_ptr<inputThumbnail> &&thumbnail_, object_ptr<InputFile> &&cover_, int32 start_timestamp_, array<int32> &&added_sticker_file_ids_, int32 duration_, int32 width_, int32 height_, bool supports_streaming_, object_ptr<formattedText> &&caption_, bool show_caption_above_media_, object_ptr<MessageSelfDestructType> &&self_destruct_type_, bool has_spoiler_)
  : video_(std::move(video_))
  , thumbnail_(std::move(thumbnail_))
  , cover_(std::move(cover_))
  , start_timestamp_(start_timestamp_)
  , added_sticker_file_ids_(std::move(added_sticker_file_ids_))
  , duration_(duration_)
  , width_(width_)
  , height_(height_)
  , supports_streaming_(supports_streaming_)
  , caption_(std::move(caption_))
  , show_caption_above_media_(show_caption_above_media_)
  , self_destruct_type_(std::move(self_destruct_type_))
  , has_spoiler_(has_spoiler_)
{}

const std::int32_t inputMessageVideo::ID;

void inputMessageVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_field("start_timestamp", start_timestamp_);
    { s.store_vector_begin("added_sticker_file_ids", added_sticker_file_ids_.size()); for (const auto &_value : added_sticker_file_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("duration", duration_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("supports_streaming", supports_streaming_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("show_caption_above_media", show_caption_above_media_);
    s.store_object_field("self_destruct_type", static_cast<const BaseObject *>(self_destruct_type_.get()));
    s.store_field("has_spoiler", has_spoiler_);
    s.store_class_end();
  }
}

inputMessageVideoNote::inputMessageVideoNote()
  : video_note_()
  , thumbnail_()
  , duration_()
  , length_()
  , self_destruct_type_()
{}

inputMessageVideoNote::inputMessageVideoNote(object_ptr<InputFile> &&video_note_, object_ptr<inputThumbnail> &&thumbnail_, int32 duration_, int32 length_, object_ptr<MessageSelfDestructType> &&self_destruct_type_)
  : video_note_(std::move(video_note_))
  , thumbnail_(std::move(thumbnail_))
  , duration_(duration_)
  , length_(length_)
  , self_destruct_type_(std::move(self_destruct_type_))
{}

const std::int32_t inputMessageVideoNote::ID;

void inputMessageVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageVideoNote");
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_field("duration", duration_);
    s.store_field("length", length_);
    s.store_object_field("self_destruct_type", static_cast<const BaseObject *>(self_destruct_type_.get()));
    s.store_class_end();
  }
}

inputMessageVoiceNote::inputMessageVoiceNote()
  : voice_note_()
  , duration_()
  , waveform_()
  , caption_()
  , self_destruct_type_()
{}

inputMessageVoiceNote::inputMessageVoiceNote(object_ptr<InputFile> &&voice_note_, int32 duration_, bytes const &waveform_, object_ptr<formattedText> &&caption_, object_ptr<MessageSelfDestructType> &&self_destruct_type_)
  : voice_note_(std::move(voice_note_))
  , duration_(duration_)
  , waveform_(std::move(waveform_))
  , caption_(std::move(caption_))
  , self_destruct_type_(std::move(self_destruct_type_))
{}

const std::int32_t inputMessageVoiceNote::ID;

void inputMessageVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_field("duration", duration_);
    s.store_bytes_field("waveform", waveform_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_object_field("self_destruct_type", static_cast<const BaseObject *>(self_destruct_type_.get()));
    s.store_class_end();
  }
}

inputMessageLocation::inputMessageLocation()
  : location_()
  , live_period_()
  , heading_()
  , proximity_alert_radius_()
{}

inputMessageLocation::inputMessageLocation(object_ptr<location> &&location_, int32 live_period_, int32 heading_, int32 proximity_alert_radius_)
  : location_(std::move(location_))
  , live_period_(live_period_)
  , heading_(heading_)
  , proximity_alert_radius_(proximity_alert_radius_)
{}

const std::int32_t inputMessageLocation::ID;

void inputMessageLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("live_period", live_period_);
    s.store_field("heading", heading_);
    s.store_field("proximity_alert_radius", proximity_alert_radius_);
    s.store_class_end();
  }
}

inputMessageVenue::inputMessageVenue()
  : venue_()
{}

inputMessageVenue::inputMessageVenue(object_ptr<venue> &&venue_)
  : venue_(std::move(venue_))
{}

const std::int32_t inputMessageVenue::ID;

void inputMessageVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageVenue");
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_class_end();
  }
}

inputMessageContact::inputMessageContact()
  : contact_()
{}

inputMessageContact::inputMessageContact(object_ptr<contact> &&contact_)
  : contact_(std::move(contact_))
{}

const std::int32_t inputMessageContact::ID;

void inputMessageContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageContact");
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_class_end();
  }
}

inputMessageDice::inputMessageDice()
  : emoji_()
  , clear_draft_()
{}

inputMessageDice::inputMessageDice(string const &emoji_, bool clear_draft_)
  : emoji_(emoji_)
  , clear_draft_(clear_draft_)
{}

const std::int32_t inputMessageDice::ID;

void inputMessageDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageDice");
    s.store_field("emoji", emoji_);
    s.store_field("clear_draft", clear_draft_);
    s.store_class_end();
  }
}

inputMessageGame::inputMessageGame()
  : bot_user_id_()
  , game_short_name_()
{}

inputMessageGame::inputMessageGame(int53 bot_user_id_, string const &game_short_name_)
  : bot_user_id_(bot_user_id_)
  , game_short_name_(game_short_name_)
{}

const std::int32_t inputMessageGame::ID;

void inputMessageGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageGame");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("game_short_name", game_short_name_);
    s.store_class_end();
  }
}

inputMessageInvoice::inputMessageInvoice()
  : invoice_()
  , title_()
  , description_()
  , photo_url_()
  , photo_size_()
  , photo_width_()
  , photo_height_()
  , payload_()
  , provider_token_()
  , provider_data_()
  , start_parameter_()
  , paid_media_()
  , paid_media_caption_()
{}

inputMessageInvoice::inputMessageInvoice(object_ptr<invoice> &&invoice_, string const &title_, string const &description_, string const &photo_url_, int32 photo_size_, int32 photo_width_, int32 photo_height_, bytes const &payload_, string const &provider_token_, string const &provider_data_, string const &start_parameter_, object_ptr<inputPaidMedia> &&paid_media_, object_ptr<formattedText> &&paid_media_caption_)
  : invoice_(std::move(invoice_))
  , title_(title_)
  , description_(description_)
  , photo_url_(photo_url_)
  , photo_size_(photo_size_)
  , photo_width_(photo_width_)
  , photo_height_(photo_height_)
  , payload_(std::move(payload_))
  , provider_token_(provider_token_)
  , provider_data_(provider_data_)
  , start_parameter_(start_parameter_)
  , paid_media_(std::move(paid_media_))
  , paid_media_caption_(std::move(paid_media_caption_))
{}

const std::int32_t inputMessageInvoice::ID;

void inputMessageInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageInvoice");
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("photo_url", photo_url_);
    s.store_field("photo_size", photo_size_);
    s.store_field("photo_width", photo_width_);
    s.store_field("photo_height", photo_height_);
    s.store_bytes_field("payload", payload_);
    s.store_field("provider_token", provider_token_);
    s.store_field("provider_data", provider_data_);
    s.store_field("start_parameter", start_parameter_);
    s.store_object_field("paid_media", static_cast<const BaseObject *>(paid_media_.get()));
    s.store_object_field("paid_media_caption", static_cast<const BaseObject *>(paid_media_caption_.get()));
    s.store_class_end();
  }
}

inputMessagePoll::inputMessagePoll()
  : question_()
  , options_()
  , description_()
  , is_anonymous_()
  , allows_multiple_answers_()
  , allows_revoting_()
  , shuffle_options_()
  , hide_results_until_closes_()
  , type_()
  , open_period_()
  , close_date_()
  , is_closed_()
{}

inputMessagePoll::inputMessagePoll(object_ptr<formattedText> &&question_, array<object_ptr<inputPollOption>> &&options_, object_ptr<formattedText> &&description_, bool is_anonymous_, bool allows_multiple_answers_, bool allows_revoting_, bool shuffle_options_, bool hide_results_until_closes_, object_ptr<InputPollType> &&type_, int32 open_period_, int32 close_date_, bool is_closed_)
  : question_(std::move(question_))
  , options_(std::move(options_))
  , description_(std::move(description_))
  , is_anonymous_(is_anonymous_)
  , allows_multiple_answers_(allows_multiple_answers_)
  , allows_revoting_(allows_revoting_)
  , shuffle_options_(shuffle_options_)
  , hide_results_until_closes_(hide_results_until_closes_)
  , type_(std::move(type_))
  , open_period_(open_period_)
  , close_date_(close_date_)
  , is_closed_(is_closed_)
{}

const std::int32_t inputMessagePoll::ID;

void inputMessagePoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagePoll");
    s.store_object_field("question", static_cast<const BaseObject *>(question_.get()));
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_field("is_anonymous", is_anonymous_);
    s.store_field("allows_multiple_answers", allows_multiple_answers_);
    s.store_field("allows_revoting", allows_revoting_);
    s.store_field("shuffle_options", shuffle_options_);
    s.store_field("hide_results_until_closes", hide_results_until_closes_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("open_period", open_period_);
    s.store_field("close_date", close_date_);
    s.store_field("is_closed", is_closed_);
    s.store_class_end();
  }
}

inputMessageStakeDice::inputMessageStakeDice()
  : state_hash_()
  , stake_toncoin_amount_()
  , clear_draft_()
{}

inputMessageStakeDice::inputMessageStakeDice(string const &state_hash_, int53 stake_toncoin_amount_, bool clear_draft_)
  : state_hash_(state_hash_)
  , stake_toncoin_amount_(stake_toncoin_amount_)
  , clear_draft_(clear_draft_)
{}

const std::int32_t inputMessageStakeDice::ID;

void inputMessageStakeDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageStakeDice");
    s.store_field("state_hash", state_hash_);
    s.store_field("stake_toncoin_amount", stake_toncoin_amount_);
    s.store_field("clear_draft", clear_draft_);
    s.store_class_end();
  }
}

inputMessageStory::inputMessageStory()
  : story_poster_chat_id_()
  , story_id_()
{}

inputMessageStory::inputMessageStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t inputMessageStory::ID;

void inputMessageStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

inputMessageChecklist::inputMessageChecklist()
  : checklist_()
{}

inputMessageChecklist::inputMessageChecklist(object_ptr<inputChecklist> &&checklist_)
  : checklist_(std::move(checklist_))
{}

const std::int32_t inputMessageChecklist::ID;

void inputMessageChecklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageChecklist");
    s.store_object_field("checklist", static_cast<const BaseObject *>(checklist_.get()));
    s.store_class_end();
  }
}

inputMessageForwarded::inputMessageForwarded()
  : from_chat_id_()
  , message_id_()
  , in_game_share_()
  , replace_video_start_timestamp_()
  , new_video_start_timestamp_()
  , copy_options_()
{}

inputMessageForwarded::inputMessageForwarded(int53 from_chat_id_, int53 message_id_, bool in_game_share_, bool replace_video_start_timestamp_, int32 new_video_start_timestamp_, object_ptr<messageCopyOptions> &&copy_options_)
  : from_chat_id_(from_chat_id_)
  , message_id_(message_id_)
  , in_game_share_(in_game_share_)
  , replace_video_start_timestamp_(replace_video_start_timestamp_)
  , new_video_start_timestamp_(new_video_start_timestamp_)
  , copy_options_(std::move(copy_options_))
{}

const std::int32_t inputMessageForwarded::ID;

void inputMessageForwarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageForwarded");
    s.store_field("from_chat_id", from_chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("in_game_share", in_game_share_);
    s.store_field("replace_video_start_timestamp", replace_video_start_timestamp_);
    s.store_field("new_video_start_timestamp", new_video_start_timestamp_);
    s.store_object_field("copy_options", static_cast<const BaseObject *>(copy_options_.get()));
    s.store_class_end();
  }
}

inputPassportElementPersonalDetails::inputPassportElementPersonalDetails()
  : personal_details_()
{}

inputPassportElementPersonalDetails::inputPassportElementPersonalDetails(object_ptr<personalDetails> &&personal_details_)
  : personal_details_(std::move(personal_details_))
{}

const std::int32_t inputPassportElementPersonalDetails::ID;

void inputPassportElementPersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementPersonalDetails");
    s.store_object_field("personal_details", static_cast<const BaseObject *>(personal_details_.get()));
    s.store_class_end();
  }
}

inputPassportElementPassport::inputPassportElementPassport()
  : passport_()
{}

inputPassportElementPassport::inputPassportElementPassport(object_ptr<inputIdentityDocument> &&passport_)
  : passport_(std::move(passport_))
{}

const std::int32_t inputPassportElementPassport::ID;

void inputPassportElementPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementPassport");
    s.store_object_field("passport", static_cast<const BaseObject *>(passport_.get()));
    s.store_class_end();
  }
}

inputPassportElementDriverLicense::inputPassportElementDriverLicense()
  : driver_license_()
{}

inputPassportElementDriverLicense::inputPassportElementDriverLicense(object_ptr<inputIdentityDocument> &&driver_license_)
  : driver_license_(std::move(driver_license_))
{}

const std::int32_t inputPassportElementDriverLicense::ID;

void inputPassportElementDriverLicense::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementDriverLicense");
    s.store_object_field("driver_license", static_cast<const BaseObject *>(driver_license_.get()));
    s.store_class_end();
  }
}

inputPassportElementIdentityCard::inputPassportElementIdentityCard()
  : identity_card_()
{}

inputPassportElementIdentityCard::inputPassportElementIdentityCard(object_ptr<inputIdentityDocument> &&identity_card_)
  : identity_card_(std::move(identity_card_))
{}

const std::int32_t inputPassportElementIdentityCard::ID;

void inputPassportElementIdentityCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementIdentityCard");
    s.store_object_field("identity_card", static_cast<const BaseObject *>(identity_card_.get()));
    s.store_class_end();
  }
}

inputPassportElementInternalPassport::inputPassportElementInternalPassport()
  : internal_passport_()
{}

inputPassportElementInternalPassport::inputPassportElementInternalPassport(object_ptr<inputIdentityDocument> &&internal_passport_)
  : internal_passport_(std::move(internal_passport_))
{}

const std::int32_t inputPassportElementInternalPassport::ID;

void inputPassportElementInternalPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementInternalPassport");
    s.store_object_field("internal_passport", static_cast<const BaseObject *>(internal_passport_.get()));
    s.store_class_end();
  }
}

inputPassportElementAddress::inputPassportElementAddress()
  : address_()
{}

inputPassportElementAddress::inputPassportElementAddress(object_ptr<address> &&address_)
  : address_(std::move(address_))
{}

const std::int32_t inputPassportElementAddress::ID;

void inputPassportElementAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementAddress");
    s.store_object_field("address", static_cast<const BaseObject *>(address_.get()));
    s.store_class_end();
  }
}

inputPassportElementUtilityBill::inputPassportElementUtilityBill()
  : utility_bill_()
{}

inputPassportElementUtilityBill::inputPassportElementUtilityBill(object_ptr<inputPersonalDocument> &&utility_bill_)
  : utility_bill_(std::move(utility_bill_))
{}

const std::int32_t inputPassportElementUtilityBill::ID;

void inputPassportElementUtilityBill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementUtilityBill");
    s.store_object_field("utility_bill", static_cast<const BaseObject *>(utility_bill_.get()));
    s.store_class_end();
  }
}

inputPassportElementBankStatement::inputPassportElementBankStatement()
  : bank_statement_()
{}

inputPassportElementBankStatement::inputPassportElementBankStatement(object_ptr<inputPersonalDocument> &&bank_statement_)
  : bank_statement_(std::move(bank_statement_))
{}

const std::int32_t inputPassportElementBankStatement::ID;

void inputPassportElementBankStatement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementBankStatement");
    s.store_object_field("bank_statement", static_cast<const BaseObject *>(bank_statement_.get()));
    s.store_class_end();
  }
}

inputPassportElementRentalAgreement::inputPassportElementRentalAgreement()
  : rental_agreement_()
{}

inputPassportElementRentalAgreement::inputPassportElementRentalAgreement(object_ptr<inputPersonalDocument> &&rental_agreement_)
  : rental_agreement_(std::move(rental_agreement_))
{}

const std::int32_t inputPassportElementRentalAgreement::ID;

void inputPassportElementRentalAgreement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementRentalAgreement");
    s.store_object_field("rental_agreement", static_cast<const BaseObject *>(rental_agreement_.get()));
    s.store_class_end();
  }
}

inputPassportElementPassportRegistration::inputPassportElementPassportRegistration()
  : passport_registration_()
{}

inputPassportElementPassportRegistration::inputPassportElementPassportRegistration(object_ptr<inputPersonalDocument> &&passport_registration_)
  : passport_registration_(std::move(passport_registration_))
{}

const std::int32_t inputPassportElementPassportRegistration::ID;

void inputPassportElementPassportRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementPassportRegistration");
    s.store_object_field("passport_registration", static_cast<const BaseObject *>(passport_registration_.get()));
    s.store_class_end();
  }
}

inputPassportElementTemporaryRegistration::inputPassportElementTemporaryRegistration()
  : temporary_registration_()
{}

inputPassportElementTemporaryRegistration::inputPassportElementTemporaryRegistration(object_ptr<inputPersonalDocument> &&temporary_registration_)
  : temporary_registration_(std::move(temporary_registration_))
{}

const std::int32_t inputPassportElementTemporaryRegistration::ID;

void inputPassportElementTemporaryRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementTemporaryRegistration");
    s.store_object_field("temporary_registration", static_cast<const BaseObject *>(temporary_registration_.get()));
    s.store_class_end();
  }
}

inputPassportElementPhoneNumber::inputPassportElementPhoneNumber()
  : phone_number_()
{}

inputPassportElementPhoneNumber::inputPassportElementPhoneNumber(string const &phone_number_)
  : phone_number_(phone_number_)
{}

const std::int32_t inputPassportElementPhoneNumber::ID;

void inputPassportElementPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_class_end();
  }
}

inputPassportElementEmailAddress::inputPassportElementEmailAddress()
  : email_address_()
{}

inputPassportElementEmailAddress::inputPassportElementEmailAddress(string const &email_address_)
  : email_address_(email_address_)
{}

const std::int32_t inputPassportElementEmailAddress::ID;

void inputPassportElementEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPassportElementEmailAddress");
    s.store_field("email_address", email_address_);
    s.store_class_end();
  }
}

inputSticker::inputSticker()
  : sticker_()
  , format_()
  , emojis_()
  , mask_position_()
  , keywords_()
{}

inputSticker::inputSticker(object_ptr<InputFile> &&sticker_, object_ptr<StickerFormat> &&format_, string const &emojis_, object_ptr<maskPosition> &&mask_position_, array<string> &&keywords_)
  : sticker_(std::move(sticker_))
  , format_(std::move(format_))
  , emojis_(emojis_)
  , mask_position_(std::move(mask_position_))
  , keywords_(std::move(keywords_))
{}

const std::int32_t inputSticker::ID;

void inputSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("format", static_cast<const BaseObject *>(format_.get()));
    s.store_field("emojis", emojis_);
    s.store_object_field("mask_position", static_cast<const BaseObject *>(mask_position_.get()));
    { s.store_vector_begin("keywords", keywords_.size()); for (const auto &_value : keywords_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputStoryAreaTypeLocation::inputStoryAreaTypeLocation()
  : location_()
  , address_()
{}

inputStoryAreaTypeLocation::inputStoryAreaTypeLocation(object_ptr<location> &&location_, object_ptr<locationAddress> &&address_)
  : location_(std::move(location_))
  , address_(std::move(address_))
{}

const std::int32_t inputStoryAreaTypeLocation::ID;

void inputStoryAreaTypeLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_object_field("address", static_cast<const BaseObject *>(address_.get()));
    s.store_class_end();
  }
}

inputStoryAreaTypeFoundVenue::inputStoryAreaTypeFoundVenue()
  : query_id_()
  , result_id_()
{}

inputStoryAreaTypeFoundVenue::inputStoryAreaTypeFoundVenue(int64 query_id_, string const &result_id_)
  : query_id_(query_id_)
  , result_id_(result_id_)
{}

const std::int32_t inputStoryAreaTypeFoundVenue::ID;

void inputStoryAreaTypeFoundVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeFoundVenue");
    s.store_field("query_id", query_id_);
    s.store_field("result_id", result_id_);
    s.store_class_end();
  }
}

inputStoryAreaTypePreviousVenue::inputStoryAreaTypePreviousVenue()
  : venue_provider_()
  , venue_id_()
{}

inputStoryAreaTypePreviousVenue::inputStoryAreaTypePreviousVenue(string const &venue_provider_, string const &venue_id_)
  : venue_provider_(venue_provider_)
  , venue_id_(venue_id_)
{}

const std::int32_t inputStoryAreaTypePreviousVenue::ID;

void inputStoryAreaTypePreviousVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypePreviousVenue");
    s.store_field("venue_provider", venue_provider_);
    s.store_field("venue_id", venue_id_);
    s.store_class_end();
  }
}

inputStoryAreaTypeSuggestedReaction::inputStoryAreaTypeSuggestedReaction()
  : reaction_type_()
  , is_dark_()
  , is_flipped_()
{}

inputStoryAreaTypeSuggestedReaction::inputStoryAreaTypeSuggestedReaction(object_ptr<ReactionType> &&reaction_type_, bool is_dark_, bool is_flipped_)
  : reaction_type_(std::move(reaction_type_))
  , is_dark_(is_dark_)
  , is_flipped_(is_flipped_)
{}

const std::int32_t inputStoryAreaTypeSuggestedReaction::ID;

void inputStoryAreaTypeSuggestedReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeSuggestedReaction");
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_field("is_dark", is_dark_);
    s.store_field("is_flipped", is_flipped_);
    s.store_class_end();
  }
}

inputStoryAreaTypeMessage::inputStoryAreaTypeMessage()
  : chat_id_()
  , message_id_()
{}

inputStoryAreaTypeMessage::inputStoryAreaTypeMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t inputStoryAreaTypeMessage::ID;

void inputStoryAreaTypeMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

inputStoryAreaTypeLink::inputStoryAreaTypeLink()
  : url_()
{}

inputStoryAreaTypeLink::inputStoryAreaTypeLink(string const &url_)
  : url_(url_)
{}

const std::int32_t inputStoryAreaTypeLink::ID;

void inputStoryAreaTypeLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeLink");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inputStoryAreaTypeWeather::inputStoryAreaTypeWeather()
  : temperature_()
  , emoji_()
  , background_color_()
{}

inputStoryAreaTypeWeather::inputStoryAreaTypeWeather(double temperature_, string const &emoji_, int32 background_color_)
  : temperature_(temperature_)
  , emoji_(emoji_)
  , background_color_(background_color_)
{}

const std::int32_t inputStoryAreaTypeWeather::ID;

void inputStoryAreaTypeWeather::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeWeather");
    s.store_field("temperature", temperature_);
    s.store_field("emoji", emoji_);
    s.store_field("background_color", background_color_);
    s.store_class_end();
  }
}

inputStoryAreaTypeUpgradedGift::inputStoryAreaTypeUpgradedGift()
  : gift_name_()
{}

inputStoryAreaTypeUpgradedGift::inputStoryAreaTypeUpgradedGift(string const &gift_name_)
  : gift_name_(gift_name_)
{}

const std::int32_t inputStoryAreaTypeUpgradedGift::ID;

void inputStoryAreaTypeUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStoryAreaTypeUpgradedGift");
    s.store_field("gift_name", gift_name_);
    s.store_class_end();
  }
}

linkPreview::linkPreview()
  : url_()
  , display_url_()
  , site_name_()
  , title_()
  , description_()
  , author_()
  , type_()
  , has_large_media_()
  , show_large_media_()
  , show_media_above_description_()
  , skip_confirmation_()
  , show_above_text_()
  , instant_view_version_()
{}

linkPreview::linkPreview(string const &url_, string const &display_url_, string const &site_name_, string const &title_, object_ptr<formattedText> &&description_, string const &author_, object_ptr<LinkPreviewType> &&type_, bool has_large_media_, bool show_large_media_, bool show_media_above_description_, bool skip_confirmation_, bool show_above_text_, int32 instant_view_version_)
  : url_(url_)
  , display_url_(display_url_)
  , site_name_(site_name_)
  , title_(title_)
  , description_(std::move(description_))
  , author_(author_)
  , type_(std::move(type_))
  , has_large_media_(has_large_media_)
  , show_large_media_(show_large_media_)
  , show_media_above_description_(show_media_above_description_)
  , skip_confirmation_(skip_confirmation_)
  , show_above_text_(show_above_text_)
  , instant_view_version_(instant_view_version_)
{}

const std::int32_t linkPreview::ID;

void linkPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "linkPreview");
    s.store_field("url", url_);
    s.store_field("display_url", display_url_);
    s.store_field("site_name", site_name_);
    s.store_field("title", title_);
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_field("author", author_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("has_large_media", has_large_media_);
    s.store_field("show_large_media", show_large_media_);
    s.store_field("show_media_above_description", show_media_above_description_);
    s.store_field("skip_confirmation", skip_confirmation_);
    s.store_field("show_above_text", show_above_text_);
    s.store_field("instant_view_version", instant_view_version_);
    s.store_class_end();
  }
}

pageBlockTitle::pageBlockTitle()
  : title_()
{}

pageBlockTitle::pageBlockTitle(object_ptr<RichText> &&title_)
  : title_(std::move(title_))
{}

const std::int32_t pageBlockTitle::ID;

void pageBlockTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTitle");
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    s.store_class_end();
  }
}

pageBlockSubtitle::pageBlockSubtitle()
  : subtitle_()
{}

pageBlockSubtitle::pageBlockSubtitle(object_ptr<RichText> &&subtitle_)
  : subtitle_(std::move(subtitle_))
{}

const std::int32_t pageBlockSubtitle::ID;

void pageBlockSubtitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSubtitle");
    s.store_object_field("subtitle", static_cast<const BaseObject *>(subtitle_.get()));
    s.store_class_end();
  }
}

pageBlockAuthorDate::pageBlockAuthorDate()
  : author_()
  , publish_date_()
{}

pageBlockAuthorDate::pageBlockAuthorDate(object_ptr<RichText> &&author_, int32 publish_date_)
  : author_(std::move(author_))
  , publish_date_(publish_date_)
{}

const std::int32_t pageBlockAuthorDate::ID;

void pageBlockAuthorDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAuthorDate");
    s.store_object_field("author", static_cast<const BaseObject *>(author_.get()));
    s.store_field("publish_date", publish_date_);
    s.store_class_end();
  }
}

pageBlockHeader::pageBlockHeader()
  : header_()
{}

pageBlockHeader::pageBlockHeader(object_ptr<RichText> &&header_)
  : header_(std::move(header_))
{}

const std::int32_t pageBlockHeader::ID;

void pageBlockHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHeader");
    s.store_object_field("header", static_cast<const BaseObject *>(header_.get()));
    s.store_class_end();
  }
}

pageBlockSubheader::pageBlockSubheader()
  : subheader_()
{}

pageBlockSubheader::pageBlockSubheader(object_ptr<RichText> &&subheader_)
  : subheader_(std::move(subheader_))
{}

const std::int32_t pageBlockSubheader::ID;

void pageBlockSubheader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSubheader");
    s.store_object_field("subheader", static_cast<const BaseObject *>(subheader_.get()));
    s.store_class_end();
  }
}

pageBlockKicker::pageBlockKicker()
  : kicker_()
{}

pageBlockKicker::pageBlockKicker(object_ptr<RichText> &&kicker_)
  : kicker_(std::move(kicker_))
{}

const std::int32_t pageBlockKicker::ID;

void pageBlockKicker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockKicker");
    s.store_object_field("kicker", static_cast<const BaseObject *>(kicker_.get()));
    s.store_class_end();
  }
}

pageBlockParagraph::pageBlockParagraph()
  : text_()
{}

pageBlockParagraph::pageBlockParagraph(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockParagraph::ID;

void pageBlockParagraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockParagraph");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockPreformatted::pageBlockPreformatted()
  : text_()
  , language_()
{}

pageBlockPreformatted::pageBlockPreformatted(object_ptr<RichText> &&text_, string const &language_)
  : text_(std::move(text_))
  , language_(language_)
{}

const std::int32_t pageBlockPreformatted::ID;

void pageBlockPreformatted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPreformatted");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("language", language_);
    s.store_class_end();
  }
}

pageBlockFooter::pageBlockFooter()
  : footer_()
{}

pageBlockFooter::pageBlockFooter(object_ptr<RichText> &&footer_)
  : footer_(std::move(footer_))
{}

const std::int32_t pageBlockFooter::ID;

void pageBlockFooter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockFooter");
    s.store_object_field("footer", static_cast<const BaseObject *>(footer_.get()));
    s.store_class_end();
  }
}

pageBlockDivider::pageBlockDivider() {
}

const std::int32_t pageBlockDivider::ID;

void pageBlockDivider::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockDivider");
    s.store_class_end();
  }
}

pageBlockAnchor::pageBlockAnchor()
  : name_()
{}

pageBlockAnchor::pageBlockAnchor(string const &name_)
  : name_(name_)
{}

const std::int32_t pageBlockAnchor::ID;

void pageBlockAnchor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAnchor");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

pageBlockList::pageBlockList()
  : items_()
{}

pageBlockList::pageBlockList(array<object_ptr<pageBlockListItem>> &&items_)
  : items_(std::move(items_))
{}

const std::int32_t pageBlockList::ID;

void pageBlockList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockList");
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockBlockQuote::pageBlockBlockQuote()
  : text_()
  , credit_()
{}

pageBlockBlockQuote::pageBlockBlockQuote(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t pageBlockBlockQuote::ID;

void pageBlockBlockQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockBlockQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

pageBlockPullQuote::pageBlockPullQuote()
  : text_()
  , credit_()
{}

pageBlockPullQuote::pageBlockPullQuote(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t pageBlockPullQuote::ID;

void pageBlockPullQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPullQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

pageBlockAnimation::pageBlockAnimation()
  : animation_()
  , caption_()
  , need_autoplay_()
{}

pageBlockAnimation::pageBlockAnimation(object_ptr<animation> &&animation_, object_ptr<pageBlockCaption> &&caption_, bool need_autoplay_)
  : animation_(std::move(animation_))
  , caption_(std::move(caption_))
  , need_autoplay_(need_autoplay_)
{}

const std::int32_t pageBlockAnimation::ID;

void pageBlockAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("need_autoplay", need_autoplay_);
    s.store_class_end();
  }
}

pageBlockAudio::pageBlockAudio()
  : audio_()
  , caption_()
{}

pageBlockAudio::pageBlockAudio(object_ptr<audio> &&audio_, object_ptr<pageBlockCaption> &&caption_)
  : audio_(std::move(audio_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockAudio::ID;

void pageBlockAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockPhoto::pageBlockPhoto()
  : photo_()
  , caption_()
  , url_()
{}

pageBlockPhoto::pageBlockPhoto(object_ptr<photo> &&photo_, object_ptr<pageBlockCaption> &&caption_, string const &url_)
  : photo_(std::move(photo_))
  , caption_(std::move(caption_))
  , url_(url_)
{}

const std::int32_t pageBlockPhoto::ID;

void pageBlockPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("url", url_);
    s.store_class_end();
  }
}

pageBlockVideo::pageBlockVideo()
  : video_()
  , caption_()
  , need_autoplay_()
  , is_looped_()
{}

pageBlockVideo::pageBlockVideo(object_ptr<video> &&video_, object_ptr<pageBlockCaption> &&caption_, bool need_autoplay_, bool is_looped_)
  : video_(std::move(video_))
  , caption_(std::move(caption_))
  , need_autoplay_(need_autoplay_)
  , is_looped_(is_looped_)
{}

const std::int32_t pageBlockVideo::ID;

void pageBlockVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("need_autoplay", need_autoplay_);
    s.store_field("is_looped", is_looped_);
    s.store_class_end();
  }
}

pageBlockVoiceNote::pageBlockVoiceNote()
  : voice_note_()
  , caption_()
{}

pageBlockVoiceNote::pageBlockVoiceNote(object_ptr<voiceNote> &&voice_note_, object_ptr<pageBlockCaption> &&caption_)
  : voice_note_(std::move(voice_note_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockVoiceNote::ID;

void pageBlockVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockCover::pageBlockCover()
  : cover_()
{}

pageBlockCover::pageBlockCover(object_ptr<PageBlock> &&cover_)
  : cover_(std::move(cover_))
{}

const std::int32_t pageBlockCover::ID;

void pageBlockCover::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCover");
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_class_end();
  }
}

pageBlockEmbedded::pageBlockEmbedded()
  : url_()
  , html_()
  , poster_photo_()
  , width_()
  , height_()
  , caption_()
  , is_full_width_()
  , allow_scrolling_()
{}

pageBlockEmbedded::pageBlockEmbedded(string const &url_, string const &html_, object_ptr<photo> &&poster_photo_, int32 width_, int32 height_, object_ptr<pageBlockCaption> &&caption_, bool is_full_width_, bool allow_scrolling_)
  : url_(url_)
  , html_(html_)
  , poster_photo_(std::move(poster_photo_))
  , width_(width_)
  , height_(height_)
  , caption_(std::move(caption_))
  , is_full_width_(is_full_width_)
  , allow_scrolling_(allow_scrolling_)
{}

const std::int32_t pageBlockEmbedded::ID;

void pageBlockEmbedded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockEmbedded");
    s.store_field("url", url_);
    s.store_field("html", html_);
    s.store_object_field("poster_photo", static_cast<const BaseObject *>(poster_photo_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_field("is_full_width", is_full_width_);
    s.store_field("allow_scrolling", allow_scrolling_);
    s.store_class_end();
  }
}

pageBlockEmbeddedPost::pageBlockEmbeddedPost()
  : url_()
  , author_()
  , author_photo_()
  , date_()
  , page_blocks_()
  , caption_()
{}

pageBlockEmbeddedPost::pageBlockEmbeddedPost(string const &url_, string const &author_, object_ptr<photo> &&author_photo_, int32 date_, array<object_ptr<PageBlock>> &&page_blocks_, object_ptr<pageBlockCaption> &&caption_)
  : url_(url_)
  , author_(author_)
  , author_photo_(std::move(author_photo_))
  , date_(date_)
  , page_blocks_(std::move(page_blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockEmbeddedPost::ID;

void pageBlockEmbeddedPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockEmbeddedPost");
    s.store_field("url", url_);
    s.store_field("author", author_);
    s.store_object_field("author_photo", static_cast<const BaseObject *>(author_photo_.get()));
    s.store_field("date", date_);
    { s.store_vector_begin("page_blocks", page_blocks_.size()); for (const auto &_value : page_blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockCollage::pageBlockCollage()
  : page_blocks_()
  , caption_()
{}

pageBlockCollage::pageBlockCollage(array<object_ptr<PageBlock>> &&page_blocks_, object_ptr<pageBlockCaption> &&caption_)
  : page_blocks_(std::move(page_blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockCollage::ID;

void pageBlockCollage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCollage");
    { s.store_vector_begin("page_blocks", page_blocks_.size()); for (const auto &_value : page_blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockSlideshow::pageBlockSlideshow()
  : page_blocks_()
  , caption_()
{}

pageBlockSlideshow::pageBlockSlideshow(array<object_ptr<PageBlock>> &&page_blocks_, object_ptr<pageBlockCaption> &&caption_)
  : page_blocks_(std::move(page_blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockSlideshow::ID;

void pageBlockSlideshow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSlideshow");
    { s.store_vector_begin("page_blocks", page_blocks_.size()); for (const auto &_value : page_blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockChatLink::pageBlockChatLink()
  : title_()
  , photo_()
  , accent_color_id_()
  , username_()
{}

pageBlockChatLink::pageBlockChatLink(string const &title_, object_ptr<chatPhotoInfo> &&photo_, int32 accent_color_id_, string const &username_)
  : title_(title_)
  , photo_(std::move(photo_))
  , accent_color_id_(accent_color_id_)
  , username_(username_)
{}

const std::int32_t pageBlockChatLink::ID;

void pageBlockChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockChatLink");
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("username", username_);
    s.store_class_end();
  }
}

pageBlockTable::pageBlockTable()
  : caption_()
  , cells_()
  , is_bordered_()
  , is_striped_()
{}

pageBlockTable::pageBlockTable(object_ptr<RichText> &&caption_, array<array<object_ptr<pageBlockTableCell>>> &&cells_, bool is_bordered_, bool is_striped_)
  : caption_(std::move(caption_))
  , cells_(std::move(cells_))
  , is_bordered_(is_bordered_)
  , is_striped_(is_striped_)
{}

const std::int32_t pageBlockTable::ID;

void pageBlockTable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTable");
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    { s.store_vector_begin("cells", cells_.size()); for (const auto &_value : cells_) { { s.store_vector_begin("", _value.size()); for (const auto &_value2 : _value) { s.store_object_field("", static_cast<const BaseObject *>(_value2.get())); } s.store_class_end(); } } s.store_class_end(); }
    s.store_field("is_bordered", is_bordered_);
    s.store_field("is_striped", is_striped_);
    s.store_class_end();
  }
}

pageBlockDetails::pageBlockDetails()
  : header_()
  , page_blocks_()
  , is_open_()
{}

pageBlockDetails::pageBlockDetails(object_ptr<RichText> &&header_, array<object_ptr<PageBlock>> &&page_blocks_, bool is_open_)
  : header_(std::move(header_))
  , page_blocks_(std::move(page_blocks_))
  , is_open_(is_open_)
{}

const std::int32_t pageBlockDetails::ID;

void pageBlockDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockDetails");
    s.store_object_field("header", static_cast<const BaseObject *>(header_.get()));
    { s.store_vector_begin("page_blocks", page_blocks_.size()); for (const auto &_value : page_blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_open", is_open_);
    s.store_class_end();
  }
}

pageBlockRelatedArticles::pageBlockRelatedArticles()
  : header_()
  , articles_()
{}

pageBlockRelatedArticles::pageBlockRelatedArticles(object_ptr<RichText> &&header_, array<object_ptr<pageBlockRelatedArticle>> &&articles_)
  : header_(std::move(header_))
  , articles_(std::move(articles_))
{}

const std::int32_t pageBlockRelatedArticles::ID;

void pageBlockRelatedArticles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockRelatedArticles");
    s.store_object_field("header", static_cast<const BaseObject *>(header_.get()));
    { s.store_vector_begin("articles", articles_.size()); for (const auto &_value : articles_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockMap::pageBlockMap()
  : location_()
  , zoom_()
  , width_()
  , height_()
  , caption_()
{}

pageBlockMap::pageBlockMap(object_ptr<location> &&location_, int32 zoom_, int32 width_, int32 height_, object_ptr<pageBlockCaption> &&caption_)
  : location_(std::move(location_))
  , zoom_(zoom_)
  , width_(width_)
  , height_(height_)
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockMap::ID;

void pageBlockMap::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockMap");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("zoom", zoom_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

paidReactor::paidReactor()
  : sender_id_()
  , star_count_()
  , is_top_()
  , is_me_()
  , is_anonymous_()
{}

paidReactor::paidReactor(object_ptr<MessageSender> &&sender_id_, int53 star_count_, bool is_top_, bool is_me_, bool is_anonymous_)
  : sender_id_(std::move(sender_id_))
  , star_count_(star_count_)
  , is_top_(is_top_)
  , is_me_(is_me_)
  , is_anonymous_(is_anonymous_)
{}

const std::int32_t paidReactor::ID;

void paidReactor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactor");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("star_count", star_count_);
    s.store_field("is_top", is_top_);
    s.store_field("is_me", is_me_);
    s.store_field("is_anonymous", is_anonymous_);
    s.store_class_end();
  }
}

personalDetails::personalDetails()
  : first_name_()
  , middle_name_()
  , last_name_()
  , native_first_name_()
  , native_middle_name_()
  , native_last_name_()
  , birthdate_()
  , gender_()
  , country_code_()
  , residence_country_code_()
{}

personalDetails::personalDetails(string const &first_name_, string const &middle_name_, string const &last_name_, string const &native_first_name_, string const &native_middle_name_, string const &native_last_name_, object_ptr<date> &&birthdate_, string const &gender_, string const &country_code_, string const &residence_country_code_)
  : first_name_(first_name_)
  , middle_name_(middle_name_)
  , last_name_(last_name_)
  , native_first_name_(native_first_name_)
  , native_middle_name_(native_middle_name_)
  , native_last_name_(native_last_name_)
  , birthdate_(std::move(birthdate_))
  , gender_(gender_)
  , country_code_(country_code_)
  , residence_country_code_(residence_country_code_)
{}

const std::int32_t personalDetails::ID;

void personalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "personalDetails");
    s.store_field("first_name", first_name_);
    s.store_field("middle_name", middle_name_);
    s.store_field("last_name", last_name_);
    s.store_field("native_first_name", native_first_name_);
    s.store_field("native_middle_name", native_middle_name_);
    s.store_field("native_last_name", native_last_name_);
    s.store_object_field("birthdate", static_cast<const BaseObject *>(birthdate_.get()));
    s.store_field("gender", gender_);
    s.store_field("country_code", country_code_);
    s.store_field("residence_country_code", residence_country_code_);
    s.store_class_end();
  }
}

phoneNumberInfo::phoneNumberInfo()
  : country_()
  , country_calling_code_()
  , formatted_phone_number_()
  , is_anonymous_()
{}

phoneNumberInfo::phoneNumberInfo(object_ptr<countryInfo> &&country_, string const &country_calling_code_, string const &formatted_phone_number_, bool is_anonymous_)
  : country_(std::move(country_))
  , country_calling_code_(country_calling_code_)
  , formatted_phone_number_(formatted_phone_number_)
  , is_anonymous_(is_anonymous_)
{}

const std::int32_t phoneNumberInfo::ID;

void phoneNumberInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneNumberInfo");
    s.store_object_field("country", static_cast<const BaseObject *>(country_.get()));
    s.store_field("country_calling_code", country_calling_code_);
    s.store_field("formatted_phone_number", formatted_phone_number_);
    s.store_field("is_anonymous", is_anonymous_);
    s.store_class_end();
  }
}

premiumLimit::premiumLimit()
  : type_()
  , default_value_()
  , premium_value_()
{}

premiumLimit::premiumLimit(object_ptr<PremiumLimitType> &&type_, int32 default_value_, int32 premium_value_)
  : type_(std::move(type_))
  , default_value_(default_value_)
  , premium_value_(premium_value_)
{}

const std::int32_t premiumLimit::ID;

void premiumLimit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumLimit");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("default_value", default_value_);
    s.store_field("premium_value", premium_value_);
    s.store_class_end();
  }
}

profileAccentColors::profileAccentColors()
  : palette_colors_()
  , background_colors_()
  , story_colors_()
{}

profileAccentColors::profileAccentColors(array<int32> &&palette_colors_, array<int32> &&background_colors_, array<int32> &&story_colors_)
  : palette_colors_(std::move(palette_colors_))
  , background_colors_(std::move(background_colors_))
  , story_colors_(std::move(story_colors_))
{}

const std::int32_t profileAccentColors::ID;

void profileAccentColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileAccentColors");
    { s.store_vector_begin("palette_colors", palette_colors_.size()); for (const auto &_value : palette_colors_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("background_colors", background_colors_.size()); for (const auto &_value : background_colors_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("story_colors", story_colors_.size()); for (const auto &_value : story_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reactionNotificationSourceNone::reactionNotificationSourceNone() {
}

const std::int32_t reactionNotificationSourceNone::ID;

void reactionNotificationSourceNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionNotificationSourceNone");
    s.store_class_end();
  }
}

reactionNotificationSourceContacts::reactionNotificationSourceContacts() {
}

const std::int32_t reactionNotificationSourceContacts::ID;

void reactionNotificationSourceContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionNotificationSourceContacts");
    s.store_class_end();
  }
}

reactionNotificationSourceAll::reactionNotificationSourceAll() {
}

const std::int32_t reactionNotificationSourceAll::ID;

void reactionNotificationSourceAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionNotificationSourceAll");
    s.store_class_end();
  }
}

recommendedChatFolder::recommendedChatFolder()
  : folder_()
  , description_()
{}

recommendedChatFolder::recommendedChatFolder(object_ptr<chatFolder> &&folder_, string const &description_)
  : folder_(std::move(folder_))
  , description_(description_)
{}

const std::int32_t recommendedChatFolder::ID;

void recommendedChatFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recommendedChatFolder");
    s.store_object_field("folder", static_cast<const BaseObject *>(folder_.get()));
    s.store_field("description", description_);
    s.store_class_end();
  }
}

recoveryEmailAddress::recoveryEmailAddress()
  : recovery_email_address_()
{}

recoveryEmailAddress::recoveryEmailAddress(string const &recovery_email_address_)
  : recovery_email_address_(recovery_email_address_)
{}

const std::int32_t recoveryEmailAddress::ID;

void recoveryEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recoveryEmailAddress");
    s.store_field("recovery_email_address", recovery_email_address_);
    s.store_class_end();
  }
}

resetPasswordResultOk::resetPasswordResultOk() {
}

const std::int32_t resetPasswordResultOk::ID;

void resetPasswordResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetPasswordResultOk");
    s.store_class_end();
  }
}

resetPasswordResultPending::resetPasswordResultPending()
  : pending_reset_date_()
{}

resetPasswordResultPending::resetPasswordResultPending(int32 pending_reset_date_)
  : pending_reset_date_(pending_reset_date_)
{}

const std::int32_t resetPasswordResultPending::ID;

void resetPasswordResultPending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetPasswordResultPending");
    s.store_field("pending_reset_date", pending_reset_date_);
    s.store_class_end();
  }
}

resetPasswordResultDeclined::resetPasswordResultDeclined()
  : retry_date_()
{}

resetPasswordResultDeclined::resetPasswordResultDeclined(int32 retry_date_)
  : retry_date_(retry_date_)
{}

const std::int32_t resetPasswordResultDeclined::ID;

void resetPasswordResultDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resetPasswordResultDeclined");
    s.store_field("retry_date", retry_date_);
    s.store_class_end();
  }
}

restrictionInfo::restrictionInfo()
  : restriction_reason_()
  , has_sensitive_content_()
{}

restrictionInfo::restrictionInfo(string const &restriction_reason_, bool has_sensitive_content_)
  : restriction_reason_(restriction_reason_)
  , has_sensitive_content_(has_sensitive_content_)
{}

const std::int32_t restrictionInfo::ID;

void restrictionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "restrictionInfo");
    s.store_field("restriction_reason", restriction_reason_);
    s.store_field("has_sensitive_content", has_sensitive_content_);
    s.store_class_end();
  }
}

session::session()
  : id_()
  , is_current_()
  , is_password_pending_()
  , is_unconfirmed_()
  , can_accept_secret_chats_()
  , can_accept_calls_()
  , type_()
  , api_id_()
  , application_name_()
  , application_version_()
  , is_official_application_()
  , device_model_()
  , platform_()
  , system_version_()
  , log_in_date_()
  , last_active_date_()
  , ip_address_()
  , location_()
{}

session::session(int64 id_, bool is_current_, bool is_password_pending_, bool is_unconfirmed_, bool can_accept_secret_chats_, bool can_accept_calls_, object_ptr<SessionType> &&type_, int32 api_id_, string const &application_name_, string const &application_version_, bool is_official_application_, string const &device_model_, string const &platform_, string const &system_version_, int32 log_in_date_, int32 last_active_date_, string const &ip_address_, string const &location_)
  : id_(id_)
  , is_current_(is_current_)
  , is_password_pending_(is_password_pending_)
  , is_unconfirmed_(is_unconfirmed_)
  , can_accept_secret_chats_(can_accept_secret_chats_)
  , can_accept_calls_(can_accept_calls_)
  , type_(std::move(type_))
  , api_id_(api_id_)
  , application_name_(application_name_)
  , application_version_(application_version_)
  , is_official_application_(is_official_application_)
  , device_model_(device_model_)
  , platform_(platform_)
  , system_version_(system_version_)
  , log_in_date_(log_in_date_)
  , last_active_date_(last_active_date_)
  , ip_address_(ip_address_)
  , location_(location_)
{}

const std::int32_t session::ID;

void session::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "session");
    s.store_field("id", id_);
    s.store_field("is_current", is_current_);
    s.store_field("is_password_pending", is_password_pending_);
    s.store_field("is_unconfirmed", is_unconfirmed_);
    s.store_field("can_accept_secret_chats", can_accept_secret_chats_);
    s.store_field("can_accept_calls", can_accept_calls_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("api_id", api_id_);
    s.store_field("application_name", application_name_);
    s.store_field("application_version", application_version_);
    s.store_field("is_official_application", is_official_application_);
    s.store_field("device_model", device_model_);
    s.store_field("platform", platform_);
    s.store_field("system_version", system_version_);
    s.store_field("log_in_date", log_in_date_);
    s.store_field("last_active_date", last_active_date_);
    s.store_field("ip_address", ip_address_);
    s.store_field("location", location_);
    s.store_class_end();
  }
}

speechRecognitionResultPending::speechRecognitionResultPending()
  : partial_text_()
{}

speechRecognitionResultPending::speechRecognitionResultPending(string const &partial_text_)
  : partial_text_(partial_text_)
{}

const std::int32_t speechRecognitionResultPending::ID;

void speechRecognitionResultPending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "speechRecognitionResultPending");
    s.store_field("partial_text", partial_text_);
    s.store_class_end();
  }
}

speechRecognitionResultText::speechRecognitionResultText()
  : text_()
{}

speechRecognitionResultText::speechRecognitionResultText(string const &text_)
  : text_(text_)
{}

const std::int32_t speechRecognitionResultText::ID;

void speechRecognitionResultText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "speechRecognitionResultText");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

speechRecognitionResultError::speechRecognitionResultError()
  : error_()
{}

speechRecognitionResultError::speechRecognitionResultError(object_ptr<error> &&error_)
  : error_(std::move(error_))
{}

const std::int32_t speechRecognitionResultError::ID;

void speechRecognitionResultError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "speechRecognitionResultError");
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

starCount::starCount()
  : star_count_()
{}

starCount::starCount(int53 star_count_)
  : star_count_(star_count_)
{}

const std::int32_t starCount::ID;

void starCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starCount");
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

starRevenueStatistics::starRevenueStatistics()
  : revenue_by_day_graph_()
  , status_()
  , usd_rate_()
{}

starRevenueStatistics::starRevenueStatistics(object_ptr<StatisticalGraph> &&revenue_by_day_graph_, object_ptr<starRevenueStatus> &&status_, double usd_rate_)
  : revenue_by_day_graph_(std::move(revenue_by_day_graph_))
  , status_(std::move(status_))
  , usd_rate_(usd_rate_)
{}

const std::int32_t starRevenueStatistics::ID;

void starRevenueStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starRevenueStatistics");
    s.store_object_field("revenue_by_day_graph", static_cast<const BaseObject *>(revenue_by_day_graph_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("usd_rate", usd_rate_);
    s.store_class_end();
  }
}

sticker::sticker()
  : id_()
  , set_id_()
  , width_()
  , height_()
  , emoji_()
  , format_()
  , full_type_()
  , thumbnail_()
  , sticker_()
{}

sticker::sticker(int64 id_, int64 set_id_, int32 width_, int32 height_, string const &emoji_, object_ptr<StickerFormat> &&format_, object_ptr<StickerFullType> &&full_type_, object_ptr<thumbnail> &&thumbnail_, object_ptr<file> &&sticker_)
  : id_(id_)
  , set_id_(set_id_)
  , width_(width_)
  , height_(height_)
  , emoji_(emoji_)
  , format_(std::move(format_))
  , full_type_(std::move(full_type_))
  , thumbnail_(std::move(thumbnail_))
  , sticker_(std::move(sticker_))
{}

const std::int32_t sticker::ID;

void sticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sticker");
    s.store_field("id", id_);
    s.store_field("set_id", set_id_);
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("emoji", emoji_);
    s.store_object_field("format", static_cast<const BaseObject *>(format_.get()));
    s.store_object_field("full_type", static_cast<const BaseObject *>(full_type_.get()));
    s.store_object_field("thumbnail", static_cast<const BaseObject *>(thumbnail_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

stories::stories()
  : total_count_()
  , stories_()
  , pinned_story_ids_()
{}

stories::stories(int32 total_count_, array<object_ptr<story>> &&stories_, array<int32> &&pinned_story_ids_)
  : total_count_(total_count_)
  , stories_(std::move(stories_))
  , pinned_story_ids_(std::move(pinned_story_ids_))
{}

const std::int32_t stories::ID;

void stories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("pinned_story_ids", pinned_story_ids_.size()); for (const auto &_value : pinned_story_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyListMain::storyListMain() {
}

const std::int32_t storyListMain::ID;

void storyListMain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyListMain");
    s.store_class_end();
  }
}

storyListArchive::storyListArchive() {
}

const std::int32_t storyListArchive::ID;

void storyListArchive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyListArchive");
    s.store_class_end();
  }
}

targetChatTypes::targetChatTypes()
  : allow_user_chats_()
  , allow_bot_chats_()
  , allow_group_chats_()
  , allow_channel_chats_()
{}

targetChatTypes::targetChatTypes(bool allow_user_chats_, bool allow_bot_chats_, bool allow_group_chats_, bool allow_channel_chats_)
  : allow_user_chats_(allow_user_chats_)
  , allow_bot_chats_(allow_bot_chats_)
  , allow_group_chats_(allow_group_chats_)
  , allow_channel_chats_(allow_channel_chats_)
{}

const std::int32_t targetChatTypes::ID;

void targetChatTypes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "targetChatTypes");
    s.store_field("allow_user_chats", allow_user_chats_);
    s.store_field("allow_bot_chats", allow_bot_chats_);
    s.store_field("allow_group_chats", allow_group_chats_);
    s.store_field("allow_channel_chats", allow_channel_chats_);
    s.store_class_end();
  }
}

temporaryPasswordState::temporaryPasswordState()
  : has_password_()
  , valid_for_()
{}

temporaryPasswordState::temporaryPasswordState(bool has_password_, int32 valid_for_)
  : has_password_(has_password_)
  , valid_for_(valid_for_)
{}

const std::int32_t temporaryPasswordState::ID;

void temporaryPasswordState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "temporaryPasswordState");
    s.store_field("has_password", has_password_);
    s.store_field("valid_for", valid_for_);
    s.store_class_end();
  }
}

testVectorStringObject::testVectorStringObject()
  : value_()
{}

testVectorStringObject::testVectorStringObject(array<object_ptr<testString>> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t testVectorStringObject::ID;

void testVectorStringObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testVectorStringObject");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

timeZones::timeZones()
  : time_zones_()
{}

timeZones::timeZones(array<object_ptr<timeZone>> &&time_zones_)
  : time_zones_(std::move(time_zones_))
{}

const std::int32_t timeZones::ID;

void timeZones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "timeZones");
    { s.store_vector_begin("time_zones", time_zones_.size()); for (const auto &_value : time_zones_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

trendingStickerSets::trendingStickerSets()
  : total_count_()
  , sets_()
  , is_premium_()
{}

trendingStickerSets::trendingStickerSets(int32 total_count_, array<object_ptr<stickerSetInfo>> &&sets_, bool is_premium_)
  : total_count_(total_count_)
  , sets_(std::move(sets_))
  , is_premium_(is_premium_)
{}

const std::int32_t trendingStickerSets::ID;

void trendingStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "trendingStickerSets");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("is_premium", is_premium_);
    s.store_class_end();
  }
}

updateAuthorizationState::updateAuthorizationState()
  : authorization_state_()
{}

updateAuthorizationState::updateAuthorizationState(object_ptr<AuthorizationState> &&authorization_state_)
  : authorization_state_(std::move(authorization_state_))
{}

const std::int32_t updateAuthorizationState::ID;

void updateAuthorizationState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAuthorizationState");
    s.store_object_field("authorization_state", static_cast<const BaseObject *>(authorization_state_.get()));
    s.store_class_end();
  }
}

updateNewMessage::updateNewMessage()
  : message_()
{}

updateNewMessage::updateNewMessage(object_ptr<message> &&message_)
  : message_(std::move(message_))
{}

const std::int32_t updateNewMessage::ID;

void updateNewMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateMessageSendAcknowledged::updateMessageSendAcknowledged()
  : chat_id_()
  , message_id_()
{}

updateMessageSendAcknowledged::updateMessageSendAcknowledged(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t updateMessageSendAcknowledged::ID;

void updateMessageSendAcknowledged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageSendAcknowledged");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

updateMessageSendSucceeded::updateMessageSendSucceeded()
  : message_()
  , old_message_id_()
{}

updateMessageSendSucceeded::updateMessageSendSucceeded(object_ptr<message> &&message_, int53 old_message_id_)
  : message_(std::move(message_))
  , old_message_id_(old_message_id_)
{}

const std::int32_t updateMessageSendSucceeded::ID;

void updateMessageSendSucceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageSendSucceeded");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("old_message_id", old_message_id_);
    s.store_class_end();
  }
}

updateMessageSendFailed::updateMessageSendFailed()
  : message_()
  , old_message_id_()
  , error_()
{}

updateMessageSendFailed::updateMessageSendFailed(object_ptr<message> &&message_, int53 old_message_id_, object_ptr<error> &&error_)
  : message_(std::move(message_))
  , old_message_id_(old_message_id_)
  , error_(std::move(error_))
{}

const std::int32_t updateMessageSendFailed::ID;

void updateMessageSendFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageSendFailed");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("old_message_id", old_message_id_);
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

updateMessageContent::updateMessageContent()
  : chat_id_()
  , message_id_()
  , new_content_()
{}

updateMessageContent::updateMessageContent(int53 chat_id_, int53 message_id_, object_ptr<MessageContent> &&new_content_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , new_content_(std::move(new_content_))
{}

const std::int32_t updateMessageContent::ID;

void updateMessageContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("new_content", static_cast<const BaseObject *>(new_content_.get()));
    s.store_class_end();
  }
}

updateMessageEdited::updateMessageEdited()
  : chat_id_()
  , message_id_()
  , edit_date_()
  , reply_markup_()
{}

updateMessageEdited::updateMessageEdited(int53 chat_id_, int53 message_id_, int32 edit_date_, object_ptr<ReplyMarkup> &&reply_markup_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , edit_date_(edit_date_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t updateMessageEdited::ID;

void updateMessageEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageEdited");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("edit_date", edit_date_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

updateMessageIsPinned::updateMessageIsPinned()
  : chat_id_()
  , message_id_()
  , is_pinned_()
{}

updateMessageIsPinned::updateMessageIsPinned(int53 chat_id_, int53 message_id_, bool is_pinned_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t updateMessageIsPinned::ID;

void updateMessageIsPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageIsPinned");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

updateMessageInteractionInfo::updateMessageInteractionInfo()
  : chat_id_()
  , message_id_()
  , interaction_info_()
{}

updateMessageInteractionInfo::updateMessageInteractionInfo(int53 chat_id_, int53 message_id_, object_ptr<messageInteractionInfo> &&interaction_info_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , interaction_info_(std::move(interaction_info_))
{}

const std::int32_t updateMessageInteractionInfo::ID;

void updateMessageInteractionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageInteractionInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("interaction_info", static_cast<const BaseObject *>(interaction_info_.get()));
    s.store_class_end();
  }
}

updateMessageContentOpened::updateMessageContentOpened()
  : chat_id_()
  , message_id_()
{}

updateMessageContentOpened::updateMessageContentOpened(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t updateMessageContentOpened::ID;

void updateMessageContentOpened::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageContentOpened");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

updateMessageMentionRead::updateMessageMentionRead()
  : chat_id_()
  , message_id_()
  , unread_mention_count_()
{}

updateMessageMentionRead::updateMessageMentionRead(int53 chat_id_, int53 message_id_, int32 unread_mention_count_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , unread_mention_count_(unread_mention_count_)
{}

const std::int32_t updateMessageMentionRead::ID;

void updateMessageMentionRead::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageMentionRead");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("unread_mention_count", unread_mention_count_);
    s.store_class_end();
  }
}

updateMessageUnreadReactions::updateMessageUnreadReactions()
  : chat_id_()
  , message_id_()
  , unread_reactions_()
  , unread_reaction_count_()
{}

updateMessageUnreadReactions::updateMessageUnreadReactions(int53 chat_id_, int53 message_id_, array<object_ptr<unreadReaction>> &&unread_reactions_, int32 unread_reaction_count_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , unread_reactions_(std::move(unread_reactions_))
  , unread_reaction_count_(unread_reaction_count_)
{}

const std::int32_t updateMessageUnreadReactions::ID;

void updateMessageUnreadReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageUnreadReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("unread_reactions", unread_reactions_.size()); for (const auto &_value : unread_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_class_end();
  }
}

updateMessageFactCheck::updateMessageFactCheck()
  : chat_id_()
  , message_id_()
  , fact_check_()
{}

updateMessageFactCheck::updateMessageFactCheck(int53 chat_id_, int53 message_id_, object_ptr<factCheck> &&fact_check_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , fact_check_(std::move(fact_check_))
{}

const std::int32_t updateMessageFactCheck::ID;

void updateMessageFactCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageFactCheck");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("fact_check", static_cast<const BaseObject *>(fact_check_.get()));
    s.store_class_end();
  }
}

updateMessageSuggestedPostInfo::updateMessageSuggestedPostInfo()
  : chat_id_()
  , message_id_()
  , suggested_post_info_()
{}

updateMessageSuggestedPostInfo::updateMessageSuggestedPostInfo(int53 chat_id_, int53 message_id_, object_ptr<suggestedPostInfo> &&suggested_post_info_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , suggested_post_info_(std::move(suggested_post_info_))
{}

const std::int32_t updateMessageSuggestedPostInfo::ID;

void updateMessageSuggestedPostInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageSuggestedPostInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("suggested_post_info", static_cast<const BaseObject *>(suggested_post_info_.get()));
    s.store_class_end();
  }
}

updateMessageLiveLocationViewed::updateMessageLiveLocationViewed()
  : chat_id_()
  , message_id_()
{}

updateMessageLiveLocationViewed::updateMessageLiveLocationViewed(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t updateMessageLiveLocationViewed::ID;

void updateMessageLiveLocationViewed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageLiveLocationViewed");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

updateVideoPublished::updateVideoPublished()
  : chat_id_()
  , message_id_()
{}

updateVideoPublished::updateVideoPublished(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t updateVideoPublished::ID;

void updateVideoPublished::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateVideoPublished");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

updateNewChat::updateNewChat()
  : chat_()
{}

updateNewChat::updateNewChat(object_ptr<chat> &&chat_)
  : chat_(std::move(chat_))
{}

const std::int32_t updateNewChat::ID;

void updateNewChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewChat");
    s.store_object_field("chat", static_cast<const BaseObject *>(chat_.get()));
    s.store_class_end();
  }
}

updateChatTitle::updateChatTitle()
  : chat_id_()
  , title_()
{}

updateChatTitle::updateChatTitle(int53 chat_id_, string const &title_)
  : chat_id_(chat_id_)
  , title_(title_)
{}

const std::int32_t updateChatTitle::ID;

void updateChatTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatTitle");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

updateChatPhoto::updateChatPhoto()
  : chat_id_()
  , photo_()
{}

updateChatPhoto::updateChatPhoto(int53 chat_id_, object_ptr<chatPhotoInfo> &&photo_)
  : chat_id_(chat_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t updateChatPhoto::ID;

void updateChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatPhoto");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

updateChatAccentColors::updateChatAccentColors()
  : chat_id_()
  , accent_color_id_()
  , background_custom_emoji_id_()
  , upgraded_gift_colors_()
  , profile_accent_color_id_()
  , profile_background_custom_emoji_id_()
{}

updateChatAccentColors::updateChatAccentColors(int53 chat_id_, int32 accent_color_id_, int64 background_custom_emoji_id_, object_ptr<upgradedGiftColors> &&upgraded_gift_colors_, int32 profile_accent_color_id_, int64 profile_background_custom_emoji_id_)
  : chat_id_(chat_id_)
  , accent_color_id_(accent_color_id_)
  , background_custom_emoji_id_(background_custom_emoji_id_)
  , upgraded_gift_colors_(std::move(upgraded_gift_colors_))
  , profile_accent_color_id_(profile_accent_color_id_)
  , profile_background_custom_emoji_id_(profile_background_custom_emoji_id_)
{}

const std::int32_t updateChatAccentColors::ID;

void updateChatAccentColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatAccentColors");
    s.store_field("chat_id", chat_id_);
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("background_custom_emoji_id", background_custom_emoji_id_);
    s.store_object_field("upgraded_gift_colors", static_cast<const BaseObject *>(upgraded_gift_colors_.get()));
    s.store_field("profile_accent_color_id", profile_accent_color_id_);
    s.store_field("profile_background_custom_emoji_id", profile_background_custom_emoji_id_);
    s.store_class_end();
  }
}

updateChatPermissions::updateChatPermissions()
  : chat_id_()
  , permissions_()
{}

updateChatPermissions::updateChatPermissions(int53 chat_id_, object_ptr<chatPermissions> &&permissions_)
  : chat_id_(chat_id_)
  , permissions_(std::move(permissions_))
{}

const std::int32_t updateChatPermissions::ID;

void updateChatPermissions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatPermissions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("permissions", static_cast<const BaseObject *>(permissions_.get()));
    s.store_class_end();
  }
}

updateChatLastMessage::updateChatLastMessage()
  : chat_id_()
  , last_message_()
  , positions_()
{}

updateChatLastMessage::updateChatLastMessage(int53 chat_id_, object_ptr<message> &&last_message_, array<object_ptr<chatPosition>> &&positions_)
  : chat_id_(chat_id_)
  , last_message_(std::move(last_message_))
  , positions_(std::move(positions_))
{}

const std::int32_t updateChatLastMessage::ID;

void updateChatLastMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatLastMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("last_message", static_cast<const BaseObject *>(last_message_.get()));
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateChatPosition::updateChatPosition()
  : chat_id_()
  , position_()
{}

updateChatPosition::updateChatPosition(int53 chat_id_, object_ptr<chatPosition> &&position_)
  : chat_id_(chat_id_)
  , position_(std::move(position_))
{}

const std::int32_t updateChatPosition::ID;

void updateChatPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatPosition");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("position", static_cast<const BaseObject *>(position_.get()));
    s.store_class_end();
  }
}

updateChatAddedToList::updateChatAddedToList()
  : chat_id_()
  , chat_list_()
{}

updateChatAddedToList::updateChatAddedToList(int53 chat_id_, object_ptr<ChatList> &&chat_list_)
  : chat_id_(chat_id_)
  , chat_list_(std::move(chat_list_))
{}

const std::int32_t updateChatAddedToList::ID;

void updateChatAddedToList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatAddedToList");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_class_end();
  }
}

updateChatRemovedFromList::updateChatRemovedFromList()
  : chat_id_()
  , chat_list_()
{}

updateChatRemovedFromList::updateChatRemovedFromList(int53 chat_id_, object_ptr<ChatList> &&chat_list_)
  : chat_id_(chat_id_)
  , chat_list_(std::move(chat_list_))
{}

const std::int32_t updateChatRemovedFromList::ID;

void updateChatRemovedFromList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatRemovedFromList");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_class_end();
  }
}

updateChatReadInbox::updateChatReadInbox()
  : chat_id_()
  , last_read_inbox_message_id_()
  , unread_count_()
{}

updateChatReadInbox::updateChatReadInbox(int53 chat_id_, int53 last_read_inbox_message_id_, int32 unread_count_)
  : chat_id_(chat_id_)
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , unread_count_(unread_count_)
{}

const std::int32_t updateChatReadInbox::ID;

void updateChatReadInbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatReadInbox");
    s.store_field("chat_id", chat_id_);
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("unread_count", unread_count_);
    s.store_class_end();
  }
}

updateChatReadOutbox::updateChatReadOutbox()
  : chat_id_()
  , last_read_outbox_message_id_()
{}

updateChatReadOutbox::updateChatReadOutbox(int53 chat_id_, int53 last_read_outbox_message_id_)
  : chat_id_(chat_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
{}

const std::int32_t updateChatReadOutbox::ID;

void updateChatReadOutbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatReadOutbox");
    s.store_field("chat_id", chat_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_class_end();
  }
}

updateChatActionBar::updateChatActionBar()
  : chat_id_()
  , action_bar_()
{}

updateChatActionBar::updateChatActionBar(int53 chat_id_, object_ptr<ChatActionBar> &&action_bar_)
  : chat_id_(chat_id_)
  , action_bar_(std::move(action_bar_))
{}

const std::int32_t updateChatActionBar::ID;

void updateChatActionBar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatActionBar");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("action_bar", static_cast<const BaseObject *>(action_bar_.get()));
    s.store_class_end();
  }
}

updateChatBusinessBotManageBar::updateChatBusinessBotManageBar()
  : chat_id_()
  , business_bot_manage_bar_()
{}

updateChatBusinessBotManageBar::updateChatBusinessBotManageBar(int53 chat_id_, object_ptr<businessBotManageBar> &&business_bot_manage_bar_)
  : chat_id_(chat_id_)
  , business_bot_manage_bar_(std::move(business_bot_manage_bar_))
{}

const std::int32_t updateChatBusinessBotManageBar::ID;

void updateChatBusinessBotManageBar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatBusinessBotManageBar");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("business_bot_manage_bar", static_cast<const BaseObject *>(business_bot_manage_bar_.get()));
    s.store_class_end();
  }
}

updateChatAvailableReactions::updateChatAvailableReactions()
  : chat_id_()
  , available_reactions_()
{}

updateChatAvailableReactions::updateChatAvailableReactions(int53 chat_id_, object_ptr<ChatAvailableReactions> &&available_reactions_)
  : chat_id_(chat_id_)
  , available_reactions_(std::move(available_reactions_))
{}

const std::int32_t updateChatAvailableReactions::ID;

void updateChatAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatAvailableReactions");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("available_reactions", static_cast<const BaseObject *>(available_reactions_.get()));
    s.store_class_end();
  }
}

updateChatDraftMessage::updateChatDraftMessage()
  : chat_id_()
  , draft_message_()
  , positions_()
{}

updateChatDraftMessage::updateChatDraftMessage(int53 chat_id_, object_ptr<draftMessage> &&draft_message_, array<object_ptr<chatPosition>> &&positions_)
  : chat_id_(chat_id_)
  , draft_message_(std::move(draft_message_))
  , positions_(std::move(positions_))
{}

const std::int32_t updateChatDraftMessage::ID;

void updateChatDraftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatDraftMessage");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateChatEmojiStatus::updateChatEmojiStatus()
  : chat_id_()
  , emoji_status_()
{}

updateChatEmojiStatus::updateChatEmojiStatus(int53 chat_id_, object_ptr<emojiStatus> &&emoji_status_)
  : chat_id_(chat_id_)
  , emoji_status_(std::move(emoji_status_))
{}

const std::int32_t updateChatEmojiStatus::ID;

void updateChatEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatEmojiStatus");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

updateChatMessageSender::updateChatMessageSender()
  : chat_id_()
  , message_sender_id_()
{}

updateChatMessageSender::updateChatMessageSender(int53 chat_id_, object_ptr<MessageSender> &&message_sender_id_)
  : chat_id_(chat_id_)
  , message_sender_id_(std::move(message_sender_id_))
{}

const std::int32_t updateChatMessageSender::ID;

void updateChatMessageSender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatMessageSender");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("message_sender_id", static_cast<const BaseObject *>(message_sender_id_.get()));
    s.store_class_end();
  }
}

updateChatMessageAutoDeleteTime::updateChatMessageAutoDeleteTime()
  : chat_id_()
  , message_auto_delete_time_()
{}

updateChatMessageAutoDeleteTime::updateChatMessageAutoDeleteTime(int53 chat_id_, int32 message_auto_delete_time_)
  : chat_id_(chat_id_)
  , message_auto_delete_time_(message_auto_delete_time_)
{}

const std::int32_t updateChatMessageAutoDeleteTime::ID;

void updateChatMessageAutoDeleteTime::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatMessageAutoDeleteTime");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_auto_delete_time", message_auto_delete_time_);
    s.store_class_end();
  }
}

updateChatNotificationSettings::updateChatNotificationSettings()
  : chat_id_()
  , notification_settings_()
{}

updateChatNotificationSettings::updateChatNotificationSettings(int53 chat_id_, object_ptr<chatNotificationSettings> &&notification_settings_)
  : chat_id_(chat_id_)
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t updateChatNotificationSettings::ID;

void updateChatNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatNotificationSettings");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

updateChatPendingJoinRequests::updateChatPendingJoinRequests()
  : chat_id_()
  , pending_join_requests_()
{}

updateChatPendingJoinRequests::updateChatPendingJoinRequests(int53 chat_id_, object_ptr<chatJoinRequestsInfo> &&pending_join_requests_)
  : chat_id_(chat_id_)
  , pending_join_requests_(std::move(pending_join_requests_))
{}

const std::int32_t updateChatPendingJoinRequests::ID;

void updateChatPendingJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatPendingJoinRequests");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("pending_join_requests", static_cast<const BaseObject *>(pending_join_requests_.get()));
    s.store_class_end();
  }
}

updateChatReplyMarkup::updateChatReplyMarkup()
  : chat_id_()
  , reply_markup_message_()
{}

updateChatReplyMarkup::updateChatReplyMarkup(int53 chat_id_, object_ptr<message> &&reply_markup_message_)
  : chat_id_(chat_id_)
  , reply_markup_message_(std::move(reply_markup_message_))
{}

const std::int32_t updateChatReplyMarkup::ID;

void updateChatReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatReplyMarkup");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("reply_markup_message", static_cast<const BaseObject *>(reply_markup_message_.get()));
    s.store_class_end();
  }
}

updateChatBackground::updateChatBackground()
  : chat_id_()
  , background_()
{}

updateChatBackground::updateChatBackground(int53 chat_id_, object_ptr<chatBackground> &&background_)
  : chat_id_(chat_id_)
  , background_(std::move(background_))
{}

const std::int32_t updateChatBackground::ID;

void updateChatBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatBackground");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_class_end();
  }
}

updateChatTheme::updateChatTheme()
  : chat_id_()
  , theme_()
{}

updateChatTheme::updateChatTheme(int53 chat_id_, object_ptr<ChatTheme> &&theme_)
  : chat_id_(chat_id_)
  , theme_(std::move(theme_))
{}

const std::int32_t updateChatTheme::ID;

void updateChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatTheme");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

updateChatUnreadMentionCount::updateChatUnreadMentionCount()
  : chat_id_()
  , unread_mention_count_()
{}

updateChatUnreadMentionCount::updateChatUnreadMentionCount(int53 chat_id_, int32 unread_mention_count_)
  : chat_id_(chat_id_)
  , unread_mention_count_(unread_mention_count_)
{}

const std::int32_t updateChatUnreadMentionCount::ID;

void updateChatUnreadMentionCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatUnreadMentionCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("unread_mention_count", unread_mention_count_);
    s.store_class_end();
  }
}

updateChatUnreadReactionCount::updateChatUnreadReactionCount()
  : chat_id_()
  , unread_reaction_count_()
{}

updateChatUnreadReactionCount::updateChatUnreadReactionCount(int53 chat_id_, int32 unread_reaction_count_)
  : chat_id_(chat_id_)
  , unread_reaction_count_(unread_reaction_count_)
{}

const std::int32_t updateChatUnreadReactionCount::ID;

void updateChatUnreadReactionCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatUnreadReactionCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_class_end();
  }
}

updateChatUnreadPollVoteCount::updateChatUnreadPollVoteCount()
  : chat_id_()
  , unread_poll_vote_count_()
{}

updateChatUnreadPollVoteCount::updateChatUnreadPollVoteCount(int53 chat_id_, int32 unread_poll_vote_count_)
  : chat_id_(chat_id_)
  , unread_poll_vote_count_(unread_poll_vote_count_)
{}

const std::int32_t updateChatUnreadPollVoteCount::ID;

void updateChatUnreadPollVoteCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatUnreadPollVoteCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("unread_poll_vote_count", unread_poll_vote_count_);
    s.store_class_end();
  }
}

updateChatVideoChat::updateChatVideoChat()
  : chat_id_()
  , video_chat_()
{}

updateChatVideoChat::updateChatVideoChat(int53 chat_id_, object_ptr<videoChat> &&video_chat_)
  : chat_id_(chat_id_)
  , video_chat_(std::move(video_chat_))
{}

const std::int32_t updateChatVideoChat::ID;

void updateChatVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatVideoChat");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("video_chat", static_cast<const BaseObject *>(video_chat_.get()));
    s.store_class_end();
  }
}

updateChatDefaultDisableNotification::updateChatDefaultDisableNotification()
  : chat_id_()
  , default_disable_notification_()
{}

updateChatDefaultDisableNotification::updateChatDefaultDisableNotification(int53 chat_id_, bool default_disable_notification_)
  : chat_id_(chat_id_)
  , default_disable_notification_(default_disable_notification_)
{}

const std::int32_t updateChatDefaultDisableNotification::ID;

void updateChatDefaultDisableNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatDefaultDisableNotification");
    s.store_field("chat_id", chat_id_);
    s.store_field("default_disable_notification", default_disable_notification_);
    s.store_class_end();
  }
}

updateChatHasProtectedContent::updateChatHasProtectedContent()
  : chat_id_()
  , has_protected_content_()
{}

updateChatHasProtectedContent::updateChatHasProtectedContent(int53 chat_id_, bool has_protected_content_)
  : chat_id_(chat_id_)
  , has_protected_content_(has_protected_content_)
{}

const std::int32_t updateChatHasProtectedContent::ID;

void updateChatHasProtectedContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatHasProtectedContent");
    s.store_field("chat_id", chat_id_);
    s.store_field("has_protected_content", has_protected_content_);
    s.store_class_end();
  }
}

updateChatIsTranslatable::updateChatIsTranslatable()
  : chat_id_()
  , is_translatable_()
{}

updateChatIsTranslatable::updateChatIsTranslatable(int53 chat_id_, bool is_translatable_)
  : chat_id_(chat_id_)
  , is_translatable_(is_translatable_)
{}

const std::int32_t updateChatIsTranslatable::ID;

void updateChatIsTranslatable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatIsTranslatable");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_translatable", is_translatable_);
    s.store_class_end();
  }
}

updateChatIsMarkedAsUnread::updateChatIsMarkedAsUnread()
  : chat_id_()
  , is_marked_as_unread_()
{}

updateChatIsMarkedAsUnread::updateChatIsMarkedAsUnread(int53 chat_id_, bool is_marked_as_unread_)
  : chat_id_(chat_id_)
  , is_marked_as_unread_(is_marked_as_unread_)
{}

const std::int32_t updateChatIsMarkedAsUnread::ID;

void updateChatIsMarkedAsUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatIsMarkedAsUnread");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_class_end();
  }
}

updateChatViewAsTopics::updateChatViewAsTopics()
  : chat_id_()
  , view_as_topics_()
{}

updateChatViewAsTopics::updateChatViewAsTopics(int53 chat_id_, bool view_as_topics_)
  : chat_id_(chat_id_)
  , view_as_topics_(view_as_topics_)
{}

const std::int32_t updateChatViewAsTopics::ID;

void updateChatViewAsTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatViewAsTopics");
    s.store_field("chat_id", chat_id_);
    s.store_field("view_as_topics", view_as_topics_);
    s.store_class_end();
  }
}

updateChatBlockList::updateChatBlockList()
  : chat_id_()
  , block_list_()
{}

updateChatBlockList::updateChatBlockList(int53 chat_id_, object_ptr<BlockList> &&block_list_)
  : chat_id_(chat_id_)
  , block_list_(std::move(block_list_))
{}

const std::int32_t updateChatBlockList::ID;

void updateChatBlockList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatBlockList");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("block_list", static_cast<const BaseObject *>(block_list_.get()));
    s.store_class_end();
  }
}

updateChatHasScheduledMessages::updateChatHasScheduledMessages()
  : chat_id_()
  , has_scheduled_messages_()
{}

updateChatHasScheduledMessages::updateChatHasScheduledMessages(int53 chat_id_, bool has_scheduled_messages_)
  : chat_id_(chat_id_)
  , has_scheduled_messages_(has_scheduled_messages_)
{}

const std::int32_t updateChatHasScheduledMessages::ID;

void updateChatHasScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatHasScheduledMessages");
    s.store_field("chat_id", chat_id_);
    s.store_field("has_scheduled_messages", has_scheduled_messages_);
    s.store_class_end();
  }
}

updateChatFolders::updateChatFolders()
  : chat_folders_()
  , main_chat_list_position_()
  , are_tags_enabled_()
{}

updateChatFolders::updateChatFolders(array<object_ptr<chatFolderInfo>> &&chat_folders_, int32 main_chat_list_position_, bool are_tags_enabled_)
  : chat_folders_(std::move(chat_folders_))
  , main_chat_list_position_(main_chat_list_position_)
  , are_tags_enabled_(are_tags_enabled_)
{}

const std::int32_t updateChatFolders::ID;

void updateChatFolders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatFolders");
    { s.store_vector_begin("chat_folders", chat_folders_.size()); for (const auto &_value : chat_folders_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("main_chat_list_position", main_chat_list_position_);
    s.store_field("are_tags_enabled", are_tags_enabled_);
    s.store_class_end();
  }
}

updateChatOnlineMemberCount::updateChatOnlineMemberCount()
  : chat_id_()
  , online_member_count_()
{}

updateChatOnlineMemberCount::updateChatOnlineMemberCount(int53 chat_id_, int32 online_member_count_)
  : chat_id_(chat_id_)
  , online_member_count_(online_member_count_)
{}

const std::int32_t updateChatOnlineMemberCount::ID;

void updateChatOnlineMemberCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatOnlineMemberCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("online_member_count", online_member_count_);
    s.store_class_end();
  }
}

updateSavedMessagesTopic::updateSavedMessagesTopic()
  : topic_()
{}

updateSavedMessagesTopic::updateSavedMessagesTopic(object_ptr<savedMessagesTopic> &&topic_)
  : topic_(std::move(topic_))
{}

const std::int32_t updateSavedMessagesTopic::ID;

void updateSavedMessagesTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedMessagesTopic");
    s.store_object_field("topic", static_cast<const BaseObject *>(topic_.get()));
    s.store_class_end();
  }
}

updateSavedMessagesTopicCount::updateSavedMessagesTopicCount()
  : topic_count_()
{}

updateSavedMessagesTopicCount::updateSavedMessagesTopicCount(int32 topic_count_)
  : topic_count_(topic_count_)
{}

const std::int32_t updateSavedMessagesTopicCount::ID;

void updateSavedMessagesTopicCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedMessagesTopicCount");
    s.store_field("topic_count", topic_count_);
    s.store_class_end();
  }
}

updateDirectMessagesChatTopic::updateDirectMessagesChatTopic()
  : topic_()
{}

updateDirectMessagesChatTopic::updateDirectMessagesChatTopic(object_ptr<directMessagesChatTopic> &&topic_)
  : topic_(std::move(topic_))
{}

const std::int32_t updateDirectMessagesChatTopic::ID;

void updateDirectMessagesChatTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDirectMessagesChatTopic");
    s.store_object_field("topic", static_cast<const BaseObject *>(topic_.get()));
    s.store_class_end();
  }
}

updateTopicMessageCount::updateTopicMessageCount()
  : chat_id_()
  , topic_id_()
  , message_count_()
{}

updateTopicMessageCount::updateTopicMessageCount(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, int32 message_count_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , message_count_(message_count_)
{}

const std::int32_t updateTopicMessageCount::ID;

void updateTopicMessageCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTopicMessageCount");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_field("message_count", message_count_);
    s.store_class_end();
  }
}

updateQuickReplyShortcut::updateQuickReplyShortcut()
  : shortcut_()
{}

updateQuickReplyShortcut::updateQuickReplyShortcut(object_ptr<quickReplyShortcut> &&shortcut_)
  : shortcut_(std::move(shortcut_))
{}

const std::int32_t updateQuickReplyShortcut::ID;

void updateQuickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateQuickReplyShortcut");
    s.store_object_field("shortcut", static_cast<const BaseObject *>(shortcut_.get()));
    s.store_class_end();
  }
}

updateQuickReplyShortcutDeleted::updateQuickReplyShortcutDeleted()
  : shortcut_id_()
{}

updateQuickReplyShortcutDeleted::updateQuickReplyShortcutDeleted(int32 shortcut_id_)
  : shortcut_id_(shortcut_id_)
{}

const std::int32_t updateQuickReplyShortcutDeleted::ID;

void updateQuickReplyShortcutDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateQuickReplyShortcutDeleted");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_class_end();
  }
}

updateQuickReplyShortcuts::updateQuickReplyShortcuts()
  : shortcut_ids_()
{}

updateQuickReplyShortcuts::updateQuickReplyShortcuts(array<int32> &&shortcut_ids_)
  : shortcut_ids_(std::move(shortcut_ids_))
{}

const std::int32_t updateQuickReplyShortcuts::ID;

void updateQuickReplyShortcuts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateQuickReplyShortcuts");
    { s.store_vector_begin("shortcut_ids", shortcut_ids_.size()); for (const auto &_value : shortcut_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateQuickReplyShortcutMessages::updateQuickReplyShortcutMessages()
  : shortcut_id_()
  , messages_()
{}

updateQuickReplyShortcutMessages::updateQuickReplyShortcutMessages(int32 shortcut_id_, array<object_ptr<quickReplyMessage>> &&messages_)
  : shortcut_id_(shortcut_id_)
  , messages_(std::move(messages_))
{}

const std::int32_t updateQuickReplyShortcutMessages::ID;

void updateQuickReplyShortcutMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateQuickReplyShortcutMessages");
    s.store_field("shortcut_id", shortcut_id_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateForumTopicInfo::updateForumTopicInfo()
  : info_()
{}

updateForumTopicInfo::updateForumTopicInfo(object_ptr<forumTopicInfo> &&info_)
  : info_(std::move(info_))
{}

const std::int32_t updateForumTopicInfo::ID;

void updateForumTopicInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateForumTopicInfo");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

updateForumTopic::updateForumTopic()
  : chat_id_()
  , forum_topic_id_()
  , is_pinned_()
  , last_read_inbox_message_id_()
  , last_read_outbox_message_id_()
  , unread_mention_count_()
  , unread_reaction_count_()
  , unread_poll_vote_count_()
  , notification_settings_()
  , draft_message_()
{}

updateForumTopic::updateForumTopic(int53 chat_id_, int32 forum_topic_id_, bool is_pinned_, int53 last_read_inbox_message_id_, int53 last_read_outbox_message_id_, int32 unread_mention_count_, int32 unread_reaction_count_, int32 unread_poll_vote_count_, object_ptr<chatNotificationSettings> &&notification_settings_, object_ptr<draftMessage> &&draft_message_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , is_pinned_(is_pinned_)
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
  , unread_mention_count_(unread_mention_count_)
  , unread_reaction_count_(unread_reaction_count_)
  , unread_poll_vote_count_(unread_poll_vote_count_)
  , notification_settings_(std::move(notification_settings_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t updateForumTopic::ID;

void updateForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateForumTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_field("unread_mention_count", unread_mention_count_);
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_field("unread_poll_vote_count", unread_poll_vote_count_);
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

updateScopeNotificationSettings::updateScopeNotificationSettings()
  : scope_()
  , notification_settings_()
{}

updateScopeNotificationSettings::updateScopeNotificationSettings(object_ptr<NotificationSettingsScope> &&scope_, object_ptr<scopeNotificationSettings> &&notification_settings_)
  : scope_(std::move(scope_))
  , notification_settings_(std::move(notification_settings_))
{}

const std::int32_t updateScopeNotificationSettings::ID;

void updateScopeNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateScopeNotificationSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

updateReactionNotificationSettings::updateReactionNotificationSettings()
  : notification_settings_()
{}

updateReactionNotificationSettings::updateReactionNotificationSettings(object_ptr<reactionNotificationSettings> &&notification_settings_)
  : notification_settings_(std::move(notification_settings_))
{}

const std::int32_t updateReactionNotificationSettings::ID;

void updateReactionNotificationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReactionNotificationSettings");
    s.store_object_field("notification_settings", static_cast<const BaseObject *>(notification_settings_.get()));
    s.store_class_end();
  }
}

updateNotification::updateNotification()
  : notification_group_id_()
  , notification_()
{}

updateNotification::updateNotification(int32 notification_group_id_, object_ptr<notification> &&notification_)
  : notification_group_id_(notification_group_id_)
  , notification_(std::move(notification_))
{}

const std::int32_t updateNotification::ID;

void updateNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNotification");
    s.store_field("notification_group_id", notification_group_id_);
    s.store_object_field("notification", static_cast<const BaseObject *>(notification_.get()));
    s.store_class_end();
  }
}

updateNotificationGroup::updateNotificationGroup()
  : notification_group_id_()
  , type_()
  , chat_id_()
  , notification_settings_chat_id_()
  , notification_sound_id_()
  , total_count_()
  , added_notifications_()
  , removed_notification_ids_()
{}

updateNotificationGroup::updateNotificationGroup(int32 notification_group_id_, object_ptr<NotificationGroupType> &&type_, int53 chat_id_, int53 notification_settings_chat_id_, int64 notification_sound_id_, int32 total_count_, array<object_ptr<notification>> &&added_notifications_, array<int32> &&removed_notification_ids_)
  : notification_group_id_(notification_group_id_)
  , type_(std::move(type_))
  , chat_id_(chat_id_)
  , notification_settings_chat_id_(notification_settings_chat_id_)
  , notification_sound_id_(notification_sound_id_)
  , total_count_(total_count_)
  , added_notifications_(std::move(added_notifications_))
  , removed_notification_ids_(std::move(removed_notification_ids_))
{}

const std::int32_t updateNotificationGroup::ID;

void updateNotificationGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNotificationGroup");
    s.store_field("notification_group_id", notification_group_id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_field("notification_settings_chat_id", notification_settings_chat_id_);
    s.store_field("notification_sound_id", notification_sound_id_);
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("added_notifications", added_notifications_.size()); for (const auto &_value : added_notifications_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("removed_notification_ids", removed_notification_ids_.size()); for (const auto &_value : removed_notification_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateActiveNotifications::updateActiveNotifications()
  : groups_()
{}

updateActiveNotifications::updateActiveNotifications(array<object_ptr<notificationGroup>> &&groups_)
  : groups_(std::move(groups_))
{}

const std::int32_t updateActiveNotifications::ID;

void updateActiveNotifications::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateActiveNotifications");
    { s.store_vector_begin("groups", groups_.size()); for (const auto &_value : groups_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateHavePendingNotifications::updateHavePendingNotifications()
  : have_delayed_notifications_()
  , have_unreceived_notifications_()
{}

updateHavePendingNotifications::updateHavePendingNotifications(bool have_delayed_notifications_, bool have_unreceived_notifications_)
  : have_delayed_notifications_(have_delayed_notifications_)
  , have_unreceived_notifications_(have_unreceived_notifications_)
{}

const std::int32_t updateHavePendingNotifications::ID;

void updateHavePendingNotifications::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateHavePendingNotifications");
    s.store_field("have_delayed_notifications", have_delayed_notifications_);
    s.store_field("have_unreceived_notifications", have_unreceived_notifications_);
    s.store_class_end();
  }
}

updateDeleteMessages::updateDeleteMessages()
  : chat_id_()
  , message_ids_()
  , is_permanent_()
  , from_cache_()
{}

updateDeleteMessages::updateDeleteMessages(int53 chat_id_, array<int53> &&message_ids_, bool is_permanent_, bool from_cache_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
  , is_permanent_(is_permanent_)
  , from_cache_(from_cache_)
{}

const std::int32_t updateDeleteMessages::ID;

void updateDeleteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("is_permanent", is_permanent_);
    s.store_field("from_cache", from_cache_);
    s.store_class_end();
  }
}

updateChatAction::updateChatAction()
  : chat_id_()
  , topic_id_()
  , sender_id_()
  , action_()
{}

updateChatAction::updateChatAction(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, object_ptr<MessageSender> &&sender_id_, object_ptr<ChatAction> &&action_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , sender_id_(std::move(sender_id_))
  , action_(std::move(action_))
{}

const std::int32_t updateChatAction::ID;

void updateChatAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatAction");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

updatePendingTextMessage::updatePendingTextMessage()
  : chat_id_()
  , forum_topic_id_()
  , draft_id_()
  , text_()
{}

updatePendingTextMessage::updatePendingTextMessage(int53 chat_id_, int32 forum_topic_id_, int64 draft_id_, object_ptr<formattedText> &&text_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , draft_id_(draft_id_)
  , text_(std::move(text_))
{}

const std::int32_t updatePendingTextMessage::ID;

void updatePendingTextMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePendingTextMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("draft_id", draft_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

updateUserStatus::updateUserStatus()
  : user_id_()
  , status_()
{}

updateUserStatus::updateUserStatus(int53 user_id_, object_ptr<UserStatus> &&status_)
  : user_id_(user_id_)
  , status_(std::move(status_))
{}

const std::int32_t updateUserStatus::ID;

void updateUserStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserStatus");
    s.store_field("user_id", user_id_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

updateUser::updateUser()
  : user_()
{}

updateUser::updateUser(object_ptr<user> &&user_)
  : user_(std::move(user_))
{}

const std::int32_t updateUser::ID;

void updateUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUser");
    s.store_object_field("user", static_cast<const BaseObject *>(user_.get()));
    s.store_class_end();
  }
}

updateBasicGroup::updateBasicGroup()
  : basic_group_()
{}

updateBasicGroup::updateBasicGroup(object_ptr<basicGroup> &&basic_group_)
  : basic_group_(std::move(basic_group_))
{}

const std::int32_t updateBasicGroup::ID;

void updateBasicGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBasicGroup");
    s.store_object_field("basic_group", static_cast<const BaseObject *>(basic_group_.get()));
    s.store_class_end();
  }
}

updateSupergroup::updateSupergroup()
  : supergroup_()
{}

updateSupergroup::updateSupergroup(object_ptr<supergroup> &&supergroup_)
  : supergroup_(std::move(supergroup_))
{}

const std::int32_t updateSupergroup::ID;

void updateSupergroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSupergroup");
    s.store_object_field("supergroup", static_cast<const BaseObject *>(supergroup_.get()));
    s.store_class_end();
  }
}

updateSecretChat::updateSecretChat()
  : secret_chat_()
{}

updateSecretChat::updateSecretChat(object_ptr<secretChat> &&secret_chat_)
  : secret_chat_(std::move(secret_chat_))
{}

const std::int32_t updateSecretChat::ID;

void updateSecretChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSecretChat");
    s.store_object_field("secret_chat", static_cast<const BaseObject *>(secret_chat_.get()));
    s.store_class_end();
  }
}

updateUserFullInfo::updateUserFullInfo()
  : user_id_()
  , user_full_info_()
{}

updateUserFullInfo::updateUserFullInfo(int53 user_id_, object_ptr<userFullInfo> &&user_full_info_)
  : user_id_(user_id_)
  , user_full_info_(std::move(user_full_info_))
{}

const std::int32_t updateUserFullInfo::ID;

void updateUserFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserFullInfo");
    s.store_field("user_id", user_id_);
    s.store_object_field("user_full_info", static_cast<const BaseObject *>(user_full_info_.get()));
    s.store_class_end();
  }
}

updateBasicGroupFullInfo::updateBasicGroupFullInfo()
  : basic_group_id_()
  , basic_group_full_info_()
{}

updateBasicGroupFullInfo::updateBasicGroupFullInfo(int53 basic_group_id_, object_ptr<basicGroupFullInfo> &&basic_group_full_info_)
  : basic_group_id_(basic_group_id_)
  , basic_group_full_info_(std::move(basic_group_full_info_))
{}

const std::int32_t updateBasicGroupFullInfo::ID;

void updateBasicGroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBasicGroupFullInfo");
    s.store_field("basic_group_id", basic_group_id_);
    s.store_object_field("basic_group_full_info", static_cast<const BaseObject *>(basic_group_full_info_.get()));
    s.store_class_end();
  }
}

updateSupergroupFullInfo::updateSupergroupFullInfo()
  : supergroup_id_()
  , supergroup_full_info_()
{}

updateSupergroupFullInfo::updateSupergroupFullInfo(int53 supergroup_id_, object_ptr<supergroupFullInfo> &&supergroup_full_info_)
  : supergroup_id_(supergroup_id_)
  , supergroup_full_info_(std::move(supergroup_full_info_))
{}

const std::int32_t updateSupergroupFullInfo::ID;

void updateSupergroupFullInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSupergroupFullInfo");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_object_field("supergroup_full_info", static_cast<const BaseObject *>(supergroup_full_info_.get()));
    s.store_class_end();
  }
}

updateServiceNotification::updateServiceNotification()
  : type_()
  , content_()
{}

updateServiceNotification::updateServiceNotification(string const &type_, object_ptr<MessageContent> &&content_)
  : type_(type_)
  , content_(std::move(content_))
{}

const std::int32_t updateServiceNotification::ID;

void updateServiceNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateServiceNotification");
    s.store_field("type", type_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

updateNewOauthRequest::updateNewOauthRequest()
  : domain_()
  , location_()
  , url_()
{}

updateNewOauthRequest::updateNewOauthRequest(string const &domain_, string const &location_, string const &url_)
  : domain_(domain_)
  , location_(location_)
  , url_(url_)
{}

const std::int32_t updateNewOauthRequest::ID;

void updateNewOauthRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewOauthRequest");
    s.store_field("domain", domain_);
    s.store_field("location", location_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

updateFile::updateFile()
  : file_()
{}

updateFile::updateFile(object_ptr<file> &&file_)
  : file_(std::move(file_))
{}

const std::int32_t updateFile::ID;

void updateFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFile");
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

updateFileGenerationStart::updateFileGenerationStart()
  : generation_id_()
  , original_path_()
  , destination_path_()
  , conversion_()
{}

updateFileGenerationStart::updateFileGenerationStart(int64 generation_id_, string const &original_path_, string const &destination_path_, string const &conversion_)
  : generation_id_(generation_id_)
  , original_path_(original_path_)
  , destination_path_(destination_path_)
  , conversion_(conversion_)
{}

const std::int32_t updateFileGenerationStart::ID;

void updateFileGenerationStart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileGenerationStart");
    s.store_field("generation_id", generation_id_);
    s.store_field("original_path", original_path_);
    s.store_field("destination_path", destination_path_);
    s.store_field("conversion", conversion_);
    s.store_class_end();
  }
}

updateFileGenerationStop::updateFileGenerationStop()
  : generation_id_()
{}

updateFileGenerationStop::updateFileGenerationStop(int64 generation_id_)
  : generation_id_(generation_id_)
{}

const std::int32_t updateFileGenerationStop::ID;

void updateFileGenerationStop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileGenerationStop");
    s.store_field("generation_id", generation_id_);
    s.store_class_end();
  }
}

updateFileDownloads::updateFileDownloads()
  : total_size_()
  , total_count_()
  , downloaded_size_()
{}

updateFileDownloads::updateFileDownloads(int53 total_size_, int32 total_count_, int53 downloaded_size_)
  : total_size_(total_size_)
  , total_count_(total_count_)
  , downloaded_size_(downloaded_size_)
{}

const std::int32_t updateFileDownloads::ID;

void updateFileDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileDownloads");
    s.store_field("total_size", total_size_);
    s.store_field("total_count", total_count_);
    s.store_field("downloaded_size", downloaded_size_);
    s.store_class_end();
  }
}

updateFileAddedToDownloads::updateFileAddedToDownloads()
  : file_download_()
  , counts_()
{}

updateFileAddedToDownloads::updateFileAddedToDownloads(object_ptr<fileDownload> &&file_download_, object_ptr<downloadedFileCounts> &&counts_)
  : file_download_(std::move(file_download_))
  , counts_(std::move(counts_))
{}

const std::int32_t updateFileAddedToDownloads::ID;

void updateFileAddedToDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileAddedToDownloads");
    s.store_object_field("file_download", static_cast<const BaseObject *>(file_download_.get()));
    s.store_object_field("counts", static_cast<const BaseObject *>(counts_.get()));
    s.store_class_end();
  }
}

updateFileDownload::updateFileDownload()
  : file_id_()
  , complete_date_()
  , is_paused_()
  , counts_()
{}

updateFileDownload::updateFileDownload(int32 file_id_, int32 complete_date_, bool is_paused_, object_ptr<downloadedFileCounts> &&counts_)
  : file_id_(file_id_)
  , complete_date_(complete_date_)
  , is_paused_(is_paused_)
  , counts_(std::move(counts_))
{}

const std::int32_t updateFileDownload::ID;

void updateFileDownload::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileDownload");
    s.store_field("file_id", file_id_);
    s.store_field("complete_date", complete_date_);
    s.store_field("is_paused", is_paused_);
    s.store_object_field("counts", static_cast<const BaseObject *>(counts_.get()));
    s.store_class_end();
  }
}

updateFileRemovedFromDownloads::updateFileRemovedFromDownloads()
  : file_id_()
  , counts_()
{}

updateFileRemovedFromDownloads::updateFileRemovedFromDownloads(int32 file_id_, object_ptr<downloadedFileCounts> &&counts_)
  : file_id_(file_id_)
  , counts_(std::move(counts_))
{}

const std::int32_t updateFileRemovedFromDownloads::ID;

void updateFileRemovedFromDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFileRemovedFromDownloads");
    s.store_field("file_id", file_id_);
    s.store_object_field("counts", static_cast<const BaseObject *>(counts_.get()));
    s.store_class_end();
  }
}

updateApplicationVerificationRequired::updateApplicationVerificationRequired()
  : verification_id_()
  , nonce_()
  , cloud_project_number_()
{}

updateApplicationVerificationRequired::updateApplicationVerificationRequired(int53 verification_id_, string const &nonce_, int64 cloud_project_number_)
  : verification_id_(verification_id_)
  , nonce_(nonce_)
  , cloud_project_number_(cloud_project_number_)
{}

const std::int32_t updateApplicationVerificationRequired::ID;

void updateApplicationVerificationRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateApplicationVerificationRequired");
    s.store_field("verification_id", verification_id_);
    s.store_field("nonce", nonce_);
    s.store_field("cloud_project_number", cloud_project_number_);
    s.store_class_end();
  }
}

updateApplicationRecaptchaVerificationRequired::updateApplicationRecaptchaVerificationRequired()
  : verification_id_()
  , action_()
  , recaptcha_key_id_()
{}

updateApplicationRecaptchaVerificationRequired::updateApplicationRecaptchaVerificationRequired(int53 verification_id_, string const &action_, string const &recaptcha_key_id_)
  : verification_id_(verification_id_)
  , action_(action_)
  , recaptcha_key_id_(recaptcha_key_id_)
{}

const std::int32_t updateApplicationRecaptchaVerificationRequired::ID;

void updateApplicationRecaptchaVerificationRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateApplicationRecaptchaVerificationRequired");
    s.store_field("verification_id", verification_id_);
    s.store_field("action", action_);
    s.store_field("recaptcha_key_id", recaptcha_key_id_);
    s.store_class_end();
  }
}

updateCall::updateCall()
  : call_()
{}

updateCall::updateCall(object_ptr<call> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t updateCall::ID;

void updateCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

updateGroupCall::updateGroupCall()
  : group_call_()
{}

updateGroupCall::updateGroupCall(object_ptr<groupCall> &&group_call_)
  : group_call_(std::move(group_call_))
{}

const std::int32_t updateGroupCall::ID;

void updateGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCall");
    s.store_object_field("group_call", static_cast<const BaseObject *>(group_call_.get()));
    s.store_class_end();
  }
}

updateGroupCallParticipant::updateGroupCallParticipant()
  : group_call_id_()
  , participant_()
{}

updateGroupCallParticipant::updateGroupCallParticipant(int32 group_call_id_, object_ptr<groupCallParticipant> &&participant_)
  : group_call_id_(group_call_id_)
  , participant_(std::move(participant_))
{}

const std::int32_t updateGroupCallParticipant::ID;

void updateGroupCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallParticipant");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

updateGroupCallParticipants::updateGroupCallParticipants()
  : group_call_id_()
  , participant_user_ids_()
{}

updateGroupCallParticipants::updateGroupCallParticipants(int32 group_call_id_, array<int64> &&participant_user_ids_)
  : group_call_id_(group_call_id_)
  , participant_user_ids_(std::move(participant_user_ids_))
{}

const std::int32_t updateGroupCallParticipants::ID;

void updateGroupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallParticipants");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("participant_user_ids", participant_user_ids_.size()); for (const auto &_value : participant_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateGroupCallVerificationState::updateGroupCallVerificationState()
  : group_call_id_()
  , generation_()
  , emojis_()
{}

updateGroupCallVerificationState::updateGroupCallVerificationState(int32 group_call_id_, int32 generation_, array<string> &&emojis_)
  : group_call_id_(group_call_id_)
  , generation_(generation_)
  , emojis_(std::move(emojis_))
{}

const std::int32_t updateGroupCallVerificationState::ID;

void updateGroupCallVerificationState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallVerificationState");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("generation", generation_);
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateNewGroupCallMessage::updateNewGroupCallMessage()
  : group_call_id_()
  , message_()
{}

updateNewGroupCallMessage::updateNewGroupCallMessage(int32 group_call_id_, object_ptr<groupCallMessage> &&message_)
  : group_call_id_(group_call_id_)
  , message_(std::move(message_))
{}

const std::int32_t updateNewGroupCallMessage::ID;

void updateNewGroupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewGroupCallMessage");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateNewGroupCallPaidReaction::updateNewGroupCallPaidReaction()
  : group_call_id_()
  , sender_id_()
  , star_count_()
{}

updateNewGroupCallPaidReaction::updateNewGroupCallPaidReaction(int32 group_call_id_, object_ptr<MessageSender> &&sender_id_, int53 star_count_)
  : group_call_id_(group_call_id_)
  , sender_id_(std::move(sender_id_))
  , star_count_(star_count_)
{}

const std::int32_t updateNewGroupCallPaidReaction::ID;

void updateNewGroupCallPaidReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewGroupCallPaidReaction");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

updateGroupCallMessageSendFailed::updateGroupCallMessageSendFailed()
  : group_call_id_()
  , message_id_()
  , error_()
{}

updateGroupCallMessageSendFailed::updateGroupCallMessageSendFailed(int32 group_call_id_, int32 message_id_, object_ptr<error> &&error_)
  : group_call_id_(group_call_id_)
  , message_id_(message_id_)
  , error_(std::move(error_))
{}

const std::int32_t updateGroupCallMessageSendFailed::ID;

void updateGroupCallMessageSendFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallMessageSendFailed");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_class_end();
  }
}

updateGroupCallMessagesDeleted::updateGroupCallMessagesDeleted()
  : group_call_id_()
  , message_ids_()
{}

updateGroupCallMessagesDeleted::updateGroupCallMessagesDeleted(int32 group_call_id_, array<int32> &&message_ids_)
  : group_call_id_(group_call_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t updateGroupCallMessagesDeleted::ID;

void updateGroupCallMessagesDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallMessagesDeleted");
    s.store_field("group_call_id", group_call_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateLiveStoryTopDonors::updateLiveStoryTopDonors()
  : group_call_id_()
  , donors_()
{}

updateLiveStoryTopDonors::updateLiveStoryTopDonors(int32 group_call_id_, object_ptr<liveStoryDonors> &&donors_)
  : group_call_id_(group_call_id_)
  , donors_(std::move(donors_))
{}

const std::int32_t updateLiveStoryTopDonors::ID;

void updateLiveStoryTopDonors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateLiveStoryTopDonors");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("donors", static_cast<const BaseObject *>(donors_.get()));
    s.store_class_end();
  }
}

updateNewCallSignalingData::updateNewCallSignalingData()
  : call_id_()
  , data_()
{}

updateNewCallSignalingData::updateNewCallSignalingData(int32 call_id_, bytes const &data_)
  : call_id_(call_id_)
  , data_(std::move(data_))
{}

const std::int32_t updateNewCallSignalingData::ID;

void updateNewCallSignalingData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewCallSignalingData");
    s.store_field("call_id", call_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

updateGiftAuctionState::updateGiftAuctionState()
  : state_()
{}

updateGiftAuctionState::updateGiftAuctionState(object_ptr<giftAuctionState> &&state_)
  : state_(std::move(state_))
{}

const std::int32_t updateGiftAuctionState::ID;

void updateGiftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGiftAuctionState");
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

updateActiveGiftAuctions::updateActiveGiftAuctions()
  : states_()
{}

updateActiveGiftAuctions::updateActiveGiftAuctions(array<object_ptr<giftAuctionState>> &&states_)
  : states_(std::move(states_))
{}

const std::int32_t updateActiveGiftAuctions::ID;

void updateActiveGiftAuctions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateActiveGiftAuctions");
    { s.store_vector_begin("states", states_.size()); for (const auto &_value : states_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateUserPrivacySettingRules::updateUserPrivacySettingRules()
  : setting_()
  , rules_()
{}

updateUserPrivacySettingRules::updateUserPrivacySettingRules(object_ptr<UserPrivacySetting> &&setting_, object_ptr<userPrivacySettingRules> &&rules_)
  : setting_(std::move(setting_))
  , rules_(std::move(rules_))
{}

const std::int32_t updateUserPrivacySettingRules::ID;

void updateUserPrivacySettingRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserPrivacySettingRules");
    s.store_object_field("setting", static_cast<const BaseObject *>(setting_.get()));
    s.store_object_field("rules", static_cast<const BaseObject *>(rules_.get()));
    s.store_class_end();
  }
}

updateUnreadMessageCount::updateUnreadMessageCount()
  : chat_list_()
  , unread_count_()
  , unread_unmuted_count_()
{}

updateUnreadMessageCount::updateUnreadMessageCount(object_ptr<ChatList> &&chat_list_, int32 unread_count_, int32 unread_unmuted_count_)
  : chat_list_(std::move(chat_list_))
  , unread_count_(unread_count_)
  , unread_unmuted_count_(unread_unmuted_count_)
{}

const std::int32_t updateUnreadMessageCount::ID;

void updateUnreadMessageCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUnreadMessageCount");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("unread_count", unread_count_);
    s.store_field("unread_unmuted_count", unread_unmuted_count_);
    s.store_class_end();
  }
}

updateUnreadChatCount::updateUnreadChatCount()
  : chat_list_()
  , total_count_()
  , unread_count_()
  , unread_unmuted_count_()
  , marked_as_unread_count_()
  , marked_as_unread_unmuted_count_()
{}

updateUnreadChatCount::updateUnreadChatCount(object_ptr<ChatList> &&chat_list_, int32 total_count_, int32 unread_count_, int32 unread_unmuted_count_, int32 marked_as_unread_count_, int32 marked_as_unread_unmuted_count_)
  : chat_list_(std::move(chat_list_))
  , total_count_(total_count_)
  , unread_count_(unread_count_)
  , unread_unmuted_count_(unread_unmuted_count_)
  , marked_as_unread_count_(marked_as_unread_count_)
  , marked_as_unread_unmuted_count_(marked_as_unread_unmuted_count_)
{}

const std::int32_t updateUnreadChatCount::ID;

void updateUnreadChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUnreadChatCount");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("total_count", total_count_);
    s.store_field("unread_count", unread_count_);
    s.store_field("unread_unmuted_count", unread_unmuted_count_);
    s.store_field("marked_as_unread_count", marked_as_unread_count_);
    s.store_field("marked_as_unread_unmuted_count", marked_as_unread_unmuted_count_);
    s.store_class_end();
  }
}

updateStory::updateStory()
  : story_()
{}

updateStory::updateStory(object_ptr<story> &&story_)
  : story_(std::move(story_))
{}

const std::int32_t updateStory::ID;

void updateStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStory");
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

updateStoryDeleted::updateStoryDeleted()
  : story_poster_chat_id_()
  , story_id_()
{}

updateStoryDeleted::updateStoryDeleted(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t updateStoryDeleted::ID;

void updateStoryDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoryDeleted");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

updateStoryPostSucceeded::updateStoryPostSucceeded()
  : story_()
  , old_story_id_()
{}

updateStoryPostSucceeded::updateStoryPostSucceeded(object_ptr<story> &&story_, int32 old_story_id_)
  : story_(std::move(story_))
  , old_story_id_(old_story_id_)
{}

const std::int32_t updateStoryPostSucceeded::ID;

void updateStoryPostSucceeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoryPostSucceeded");
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_field("old_story_id", old_story_id_);
    s.store_class_end();
  }
}

updateStoryPostFailed::updateStoryPostFailed()
  : story_()
  , error_()
  , error_type_()
{}

updateStoryPostFailed::updateStoryPostFailed(object_ptr<story> &&story_, object_ptr<error> &&error_, object_ptr<CanPostStoryResult> &&error_type_)
  : story_(std::move(story_))
  , error_(std::move(error_))
  , error_type_(std::move(error_type_))
{}

const std::int32_t updateStoryPostFailed::ID;

void updateStoryPostFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoryPostFailed");
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_object_field("error_type", static_cast<const BaseObject *>(error_type_.get()));
    s.store_class_end();
  }
}

updateChatActiveStories::updateChatActiveStories()
  : active_stories_()
{}

updateChatActiveStories::updateChatActiveStories(object_ptr<chatActiveStories> &&active_stories_)
  : active_stories_(std::move(active_stories_))
{}

const std::int32_t updateChatActiveStories::ID;

void updateChatActiveStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatActiveStories");
    s.store_object_field("active_stories", static_cast<const BaseObject *>(active_stories_.get()));
    s.store_class_end();
  }
}

updateStoryListChatCount::updateStoryListChatCount()
  : story_list_()
  , chat_count_()
{}

updateStoryListChatCount::updateStoryListChatCount(object_ptr<StoryList> &&story_list_, int32 chat_count_)
  : story_list_(std::move(story_list_))
  , chat_count_(chat_count_)
{}

const std::int32_t updateStoryListChatCount::ID;

void updateStoryListChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoryListChatCount");
    s.store_object_field("story_list", static_cast<const BaseObject *>(story_list_.get()));
    s.store_field("chat_count", chat_count_);
    s.store_class_end();
  }
}

updateStoryStealthMode::updateStoryStealthMode()
  : active_until_date_()
  , cooldown_until_date_()
{}

updateStoryStealthMode::updateStoryStealthMode(int32 active_until_date_, int32 cooldown_until_date_)
  : active_until_date_(active_until_date_)
  , cooldown_until_date_(cooldown_until_date_)
{}

const std::int32_t updateStoryStealthMode::ID;

void updateStoryStealthMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoryStealthMode");
    s.store_field("active_until_date", active_until_date_);
    s.store_field("cooldown_until_date", cooldown_until_date_);
    s.store_class_end();
  }
}

updateTrustedMiniAppBots::updateTrustedMiniAppBots()
  : bot_user_ids_()
{}

updateTrustedMiniAppBots::updateTrustedMiniAppBots(array<int53> &&bot_user_ids_)
  : bot_user_ids_(std::move(bot_user_ids_))
{}

const std::int32_t updateTrustedMiniAppBots::ID;

void updateTrustedMiniAppBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTrustedMiniAppBots");
    { s.store_vector_begin("bot_user_ids", bot_user_ids_.size()); for (const auto &_value : bot_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateOption::updateOption()
  : name_()
  , value_()
{}

updateOption::updateOption(string const &name_, object_ptr<OptionValue> &&value_)
  : name_(name_)
  , value_(std::move(value_))
{}

const std::int32_t updateOption::ID;

void updateOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateOption");
    s.store_field("name", name_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

updateStickerSet::updateStickerSet()
  : sticker_set_()
{}

updateStickerSet::updateStickerSet(object_ptr<stickerSet> &&sticker_set_)
  : sticker_set_(std::move(sticker_set_))
{}

const std::int32_t updateStickerSet::ID;

void updateStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStickerSet");
    s.store_object_field("sticker_set", static_cast<const BaseObject *>(sticker_set_.get()));
    s.store_class_end();
  }
}

updateInstalledStickerSets::updateInstalledStickerSets()
  : sticker_type_()
  , sticker_set_ids_()
{}

updateInstalledStickerSets::updateInstalledStickerSets(object_ptr<StickerType> &&sticker_type_, array<int64> &&sticker_set_ids_)
  : sticker_type_(std::move(sticker_type_))
  , sticker_set_ids_(std::move(sticker_set_ids_))
{}

const std::int32_t updateInstalledStickerSets::ID;

void updateInstalledStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateInstalledStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    { s.store_vector_begin("sticker_set_ids", sticker_set_ids_.size()); for (const auto &_value : sticker_set_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateTrendingStickerSets::updateTrendingStickerSets()
  : sticker_type_()
  , sticker_sets_()
{}

updateTrendingStickerSets::updateTrendingStickerSets(object_ptr<StickerType> &&sticker_type_, object_ptr<trendingStickerSets> &&sticker_sets_)
  : sticker_type_(std::move(sticker_type_))
  , sticker_sets_(std::move(sticker_sets_))
{}

const std::int32_t updateTrendingStickerSets::ID;

void updateTrendingStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTrendingStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_object_field("sticker_sets", static_cast<const BaseObject *>(sticker_sets_.get()));
    s.store_class_end();
  }
}

updateRecentStickers::updateRecentStickers()
  : is_attached_()
  , sticker_ids_()
{}

updateRecentStickers::updateRecentStickers(bool is_attached_, array<int32> &&sticker_ids_)
  : is_attached_(is_attached_)
  , sticker_ids_(std::move(sticker_ids_))
{}

const std::int32_t updateRecentStickers::ID;

void updateRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateRecentStickers");
    s.store_field("is_attached", is_attached_);
    { s.store_vector_begin("sticker_ids", sticker_ids_.size()); for (const auto &_value : sticker_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateFavoriteStickers::updateFavoriteStickers()
  : sticker_ids_()
{}

updateFavoriteStickers::updateFavoriteStickers(array<int32> &&sticker_ids_)
  : sticker_ids_(std::move(sticker_ids_))
{}

const std::int32_t updateFavoriteStickers::ID;

void updateFavoriteStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFavoriteStickers");
    { s.store_vector_begin("sticker_ids", sticker_ids_.size()); for (const auto &_value : sticker_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateSavedAnimations::updateSavedAnimations()
  : animation_ids_()
{}

updateSavedAnimations::updateSavedAnimations(array<int32> &&animation_ids_)
  : animation_ids_(std::move(animation_ids_))
{}

const std::int32_t updateSavedAnimations::ID;

void updateSavedAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedAnimations");
    { s.store_vector_begin("animation_ids", animation_ids_.size()); for (const auto &_value : animation_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateSavedNotificationSounds::updateSavedNotificationSounds()
  : notification_sound_ids_()
{}

updateSavedNotificationSounds::updateSavedNotificationSounds(array<int64> &&notification_sound_ids_)
  : notification_sound_ids_(std::move(notification_sound_ids_))
{}

const std::int32_t updateSavedNotificationSounds::ID;

void updateSavedNotificationSounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedNotificationSounds");
    { s.store_vector_begin("notification_sound_ids", notification_sound_ids_.size()); for (const auto &_value : notification_sound_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateDefaultBackground::updateDefaultBackground()
  : for_dark_theme_()
  , background_()
{}

updateDefaultBackground::updateDefaultBackground(bool for_dark_theme_, object_ptr<background> &&background_)
  : for_dark_theme_(for_dark_theme_)
  , background_(std::move(background_))
{}

const std::int32_t updateDefaultBackground::ID;

void updateDefaultBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDefaultBackground");
    s.store_field("for_dark_theme", for_dark_theme_);
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_class_end();
  }
}

updateEmojiChatThemes::updateEmojiChatThemes()
  : chat_themes_()
{}

updateEmojiChatThemes::updateEmojiChatThemes(array<object_ptr<emojiChatTheme>> &&chat_themes_)
  : chat_themes_(std::move(chat_themes_))
{}

const std::int32_t updateEmojiChatThemes::ID;

void updateEmojiChatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEmojiChatThemes");
    { s.store_vector_begin("chat_themes", chat_themes_.size()); for (const auto &_value : chat_themes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateAccentColors::updateAccentColors()
  : colors_()
  , available_accent_color_ids_()
{}

updateAccentColors::updateAccentColors(array<object_ptr<accentColor>> &&colors_, array<int32> &&available_accent_color_ids_)
  : colors_(std::move(colors_))
  , available_accent_color_ids_(std::move(available_accent_color_ids_))
{}

const std::int32_t updateAccentColors::ID;

void updateAccentColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAccentColors");
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("available_accent_color_ids", available_accent_color_ids_.size()); for (const auto &_value : available_accent_color_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateProfileAccentColors::updateProfileAccentColors()
  : colors_()
  , available_accent_color_ids_()
{}

updateProfileAccentColors::updateProfileAccentColors(array<object_ptr<profileAccentColor>> &&colors_, array<int32> &&available_accent_color_ids_)
  : colors_(std::move(colors_))
  , available_accent_color_ids_(std::move(available_accent_color_ids_))
{}

const std::int32_t updateProfileAccentColors::ID;

void updateProfileAccentColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateProfileAccentColors");
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("available_accent_color_ids", available_accent_color_ids_.size()); for (const auto &_value : available_accent_color_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateLanguagePackStrings::updateLanguagePackStrings()
  : localization_target_()
  , language_pack_id_()
  , strings_()
{}

updateLanguagePackStrings::updateLanguagePackStrings(string const &localization_target_, string const &language_pack_id_, array<object_ptr<languagePackString>> &&strings_)
  : localization_target_(localization_target_)
  , language_pack_id_(language_pack_id_)
  , strings_(std::move(strings_))
{}

const std::int32_t updateLanguagePackStrings::ID;

void updateLanguagePackStrings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateLanguagePackStrings");
    s.store_field("localization_target", localization_target_);
    s.store_field("language_pack_id", language_pack_id_);
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateConnectionState::updateConnectionState()
  : state_()
{}

updateConnectionState::updateConnectionState(object_ptr<ConnectionState> &&state_)
  : state_(std::move(state_))
{}

const std::int32_t updateConnectionState::ID;

void updateConnectionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateConnectionState");
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

updateFreezeState::updateFreezeState()
  : is_frozen_()
  , freezing_date_()
  , deletion_date_()
  , appeal_link_()
{}

updateFreezeState::updateFreezeState(bool is_frozen_, int32 freezing_date_, int32 deletion_date_, string const &appeal_link_)
  : is_frozen_(is_frozen_)
  , freezing_date_(freezing_date_)
  , deletion_date_(deletion_date_)
  , appeal_link_(appeal_link_)
{}

const std::int32_t updateFreezeState::ID;

void updateFreezeState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFreezeState");
    s.store_field("is_frozen", is_frozen_);
    s.store_field("freezing_date", freezing_date_);
    s.store_field("deletion_date", deletion_date_);
    s.store_field("appeal_link", appeal_link_);
    s.store_class_end();
  }
}

updateAgeVerificationParameters::updateAgeVerificationParameters()
  : parameters_()
{}

updateAgeVerificationParameters::updateAgeVerificationParameters(object_ptr<ageVerificationParameters> &&parameters_)
  : parameters_(std::move(parameters_))
{}

const std::int32_t updateAgeVerificationParameters::ID;

void updateAgeVerificationParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAgeVerificationParameters");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_class_end();
  }
}

updateTermsOfService::updateTermsOfService()
  : terms_of_service_id_()
  , terms_of_service_()
{}

updateTermsOfService::updateTermsOfService(string const &terms_of_service_id_, object_ptr<termsOfService> &&terms_of_service_)
  : terms_of_service_id_(terms_of_service_id_)
  , terms_of_service_(std::move(terms_of_service_))
{}

const std::int32_t updateTermsOfService::ID;

void updateTermsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTermsOfService");
    s.store_field("terms_of_service_id", terms_of_service_id_);
    s.store_object_field("terms_of_service", static_cast<const BaseObject *>(terms_of_service_.get()));
    s.store_class_end();
  }
}

updateUnconfirmedSession::updateUnconfirmedSession()
  : session_()
{}

updateUnconfirmedSession::updateUnconfirmedSession(object_ptr<unconfirmedSession> &&session_)
  : session_(std::move(session_))
{}

const std::int32_t updateUnconfirmedSession::ID;

void updateUnconfirmedSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUnconfirmedSession");
    s.store_object_field("session", static_cast<const BaseObject *>(session_.get()));
    s.store_class_end();
  }
}

updateAttachmentMenuBots::updateAttachmentMenuBots()
  : bots_()
{}

updateAttachmentMenuBots::updateAttachmentMenuBots(array<object_ptr<attachmentMenuBot>> &&bots_)
  : bots_(std::move(bots_))
{}

const std::int32_t updateAttachmentMenuBots::ID;

void updateAttachmentMenuBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAttachmentMenuBots");
    { s.store_vector_begin("bots", bots_.size()); for (const auto &_value : bots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateWebAppMessageSent::updateWebAppMessageSent()
  : web_app_launch_id_()
{}

updateWebAppMessageSent::updateWebAppMessageSent(int64 web_app_launch_id_)
  : web_app_launch_id_(web_app_launch_id_)
{}

const std::int32_t updateWebAppMessageSent::ID;

void updateWebAppMessageSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebAppMessageSent");
    s.store_field("web_app_launch_id", web_app_launch_id_);
    s.store_class_end();
  }
}

updateActiveEmojiReactions::updateActiveEmojiReactions()
  : emojis_()
{}

updateActiveEmojiReactions::updateActiveEmojiReactions(array<string> &&emojis_)
  : emojis_(std::move(emojis_))
{}

const std::int32_t updateActiveEmojiReactions::ID;

void updateActiveEmojiReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateActiveEmojiReactions");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateAvailableMessageEffects::updateAvailableMessageEffects()
  : reaction_effect_ids_()
  , sticker_effect_ids_()
{}

updateAvailableMessageEffects::updateAvailableMessageEffects(array<int64> &&reaction_effect_ids_, array<int64> &&sticker_effect_ids_)
  : reaction_effect_ids_(std::move(reaction_effect_ids_))
  , sticker_effect_ids_(std::move(sticker_effect_ids_))
{}

const std::int32_t updateAvailableMessageEffects::ID;

void updateAvailableMessageEffects::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAvailableMessageEffects");
    { s.store_vector_begin("reaction_effect_ids", reaction_effect_ids_.size()); for (const auto &_value : reaction_effect_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("sticker_effect_ids", sticker_effect_ids_.size()); for (const auto &_value : sticker_effect_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateDefaultReactionType::updateDefaultReactionType()
  : reaction_type_()
{}

updateDefaultReactionType::updateDefaultReactionType(object_ptr<ReactionType> &&reaction_type_)
  : reaction_type_(std::move(reaction_type_))
{}

const std::int32_t updateDefaultReactionType::ID;

void updateDefaultReactionType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDefaultReactionType");
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_class_end();
  }
}

updateDefaultPaidReactionType::updateDefaultPaidReactionType()
  : type_()
{}

updateDefaultPaidReactionType::updateDefaultPaidReactionType(object_ptr<PaidReactionType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t updateDefaultPaidReactionType::ID;

void updateDefaultPaidReactionType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDefaultPaidReactionType");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

updateSavedMessagesTags::updateSavedMessagesTags()
  : saved_messages_topic_id_()
  , tags_()
{}

updateSavedMessagesTags::updateSavedMessagesTags(int53 saved_messages_topic_id_, object_ptr<savedMessagesTags> &&tags_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
  , tags_(std::move(tags_))
{}

const std::int32_t updateSavedMessagesTags::ID;

void updateSavedMessagesTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedMessagesTags");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_object_field("tags", static_cast<const BaseObject *>(tags_.get()));
    s.store_class_end();
  }
}

updateActiveLiveLocationMessages::updateActiveLiveLocationMessages()
  : messages_()
{}

updateActiveLiveLocationMessages::updateActiveLiveLocationMessages(array<object_ptr<message>> &&messages_)
  : messages_(std::move(messages_))
{}

const std::int32_t updateActiveLiveLocationMessages::ID;

void updateActiveLiveLocationMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateActiveLiveLocationMessages");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateOwnedStarCount::updateOwnedStarCount()
  : star_amount_()
{}

updateOwnedStarCount::updateOwnedStarCount(object_ptr<starAmount> &&star_amount_)
  : star_amount_(std::move(star_amount_))
{}

const std::int32_t updateOwnedStarCount::ID;

void updateOwnedStarCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateOwnedStarCount");
    s.store_object_field("star_amount", static_cast<const BaseObject *>(star_amount_.get()));
    s.store_class_end();
  }
}

updateOwnedTonCount::updateOwnedTonCount()
  : ton_amount_()
{}

updateOwnedTonCount::updateOwnedTonCount(int53 ton_amount_)
  : ton_amount_(ton_amount_)
{}

const std::int32_t updateOwnedTonCount::ID;

void updateOwnedTonCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateOwnedTonCount");
    s.store_field("ton_amount", ton_amount_);
    s.store_class_end();
  }
}

updateChatRevenueAmount::updateChatRevenueAmount()
  : chat_id_()
  , revenue_amount_()
{}

updateChatRevenueAmount::updateChatRevenueAmount(int53 chat_id_, object_ptr<chatRevenueAmount> &&revenue_amount_)
  : chat_id_(chat_id_)
  , revenue_amount_(std::move(revenue_amount_))
{}

const std::int32_t updateChatRevenueAmount::ID;

void updateChatRevenueAmount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatRevenueAmount");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("revenue_amount", static_cast<const BaseObject *>(revenue_amount_.get()));
    s.store_class_end();
  }
}

updateStarRevenueStatus::updateStarRevenueStatus()
  : owner_id_()
  , status_()
{}

updateStarRevenueStatus::updateStarRevenueStatus(object_ptr<MessageSender> &&owner_id_, object_ptr<starRevenueStatus> &&status_)
  : owner_id_(std::move(owner_id_))
  , status_(std::move(status_))
{}

const std::int32_t updateStarRevenueStatus::ID;

void updateStarRevenueStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStarRevenueStatus");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

updateTonRevenueStatus::updateTonRevenueStatus()
  : status_()
{}

updateTonRevenueStatus::updateTonRevenueStatus(object_ptr<tonRevenueStatus> &&status_)
  : status_(std::move(status_))
{}

const std::int32_t updateTonRevenueStatus::ID;

void updateTonRevenueStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTonRevenueStatus");
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

updateSpeechRecognitionTrial::updateSpeechRecognitionTrial()
  : max_media_duration_()
  , weekly_count_()
  , left_count_()
  , next_reset_date_()
{}

updateSpeechRecognitionTrial::updateSpeechRecognitionTrial(int32 max_media_duration_, int32 weekly_count_, int32 left_count_, int32 next_reset_date_)
  : max_media_duration_(max_media_duration_)
  , weekly_count_(weekly_count_)
  , left_count_(left_count_)
  , next_reset_date_(next_reset_date_)
{}

const std::int32_t updateSpeechRecognitionTrial::ID;

void updateSpeechRecognitionTrial::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSpeechRecognitionTrial");
    s.store_field("max_media_duration", max_media_duration_);
    s.store_field("weekly_count", weekly_count_);
    s.store_field("left_count", left_count_);
    s.store_field("next_reset_date", next_reset_date_);
    s.store_class_end();
  }
}

updateGroupCallMessageLevels::updateGroupCallMessageLevels()
  : levels_()
{}

updateGroupCallMessageLevels::updateGroupCallMessageLevels(array<object_ptr<groupCallMessageLevel>> &&levels_)
  : levels_(std::move(levels_))
{}

const std::int32_t updateGroupCallMessageLevels::ID;

void updateGroupCallMessageLevels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallMessageLevels");
    { s.store_vector_begin("levels", levels_.size()); for (const auto &_value : levels_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateDiceEmojis::updateDiceEmojis()
  : emojis_()
{}

updateDiceEmojis::updateDiceEmojis(array<string> &&emojis_)
  : emojis_(std::move(emojis_))
{}

const std::int32_t updateDiceEmojis::ID;

void updateDiceEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDiceEmojis");
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateStakeDiceState::updateStakeDiceState()
  : state_()
{}

updateStakeDiceState::updateStakeDiceState(object_ptr<stakeDiceState> &&state_)
  : state_(std::move(state_))
{}

const std::int32_t updateStakeDiceState::ID;

void updateStakeDiceState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStakeDiceState");
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

updateAnimatedEmojiMessageClicked::updateAnimatedEmojiMessageClicked()
  : chat_id_()
  , message_id_()
  , sticker_()
{}

updateAnimatedEmojiMessageClicked::updateAnimatedEmojiMessageClicked(int53 chat_id_, int53 message_id_, object_ptr<sticker> &&sticker_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t updateAnimatedEmojiMessageClicked::ID;

void updateAnimatedEmojiMessageClicked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAnimatedEmojiMessageClicked");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

updateAnimationSearchParameters::updateAnimationSearchParameters()
  : provider_()
  , emojis_()
{}

updateAnimationSearchParameters::updateAnimationSearchParameters(string const &provider_, array<string> &&emojis_)
  : provider_(provider_)
  , emojis_(std::move(emojis_))
{}

const std::int32_t updateAnimationSearchParameters::ID;

void updateAnimationSearchParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAnimationSearchParameters");
    s.store_field("provider", provider_);
    { s.store_vector_begin("emojis", emojis_.size()); for (const auto &_value : emojis_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateTextCompositionStyles::updateTextCompositionStyles()
  : styles_()
{}

updateTextCompositionStyles::updateTextCompositionStyles(array<object_ptr<textCompositionStyle>> &&styles_)
  : styles_(std::move(styles_))
{}

const std::int32_t updateTextCompositionStyles::ID;

void updateTextCompositionStyles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTextCompositionStyles");
    { s.store_vector_begin("styles", styles_.size()); for (const auto &_value : styles_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateSuggestedActions::updateSuggestedActions()
  : added_actions_()
  , removed_actions_()
{}

updateSuggestedActions::updateSuggestedActions(array<object_ptr<SuggestedAction>> &&added_actions_, array<object_ptr<SuggestedAction>> &&removed_actions_)
  : added_actions_(std::move(added_actions_))
  , removed_actions_(std::move(removed_actions_))
{}

const std::int32_t updateSuggestedActions::ID;

void updateSuggestedActions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSuggestedActions");
    { s.store_vector_begin("added_actions", added_actions_.size()); for (const auto &_value : added_actions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("removed_actions", removed_actions_.size()); for (const auto &_value : removed_actions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateSpeedLimitNotification::updateSpeedLimitNotification()
  : is_upload_()
{}

updateSpeedLimitNotification::updateSpeedLimitNotification(bool is_upload_)
  : is_upload_(is_upload_)
{}

const std::int32_t updateSpeedLimitNotification::ID;

void updateSpeedLimitNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSpeedLimitNotification");
    s.store_field("is_upload", is_upload_);
    s.store_class_end();
  }
}

updateContactCloseBirthdays::updateContactCloseBirthdays()
  : close_birthday_users_()
{}

updateContactCloseBirthdays::updateContactCloseBirthdays(array<object_ptr<closeBirthdayUser>> &&close_birthday_users_)
  : close_birthday_users_(std::move(close_birthday_users_))
{}

const std::int32_t updateContactCloseBirthdays::ID;

void updateContactCloseBirthdays::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateContactCloseBirthdays");
    { s.store_vector_begin("close_birthday_users", close_birthday_users_.size()); for (const auto &_value : close_birthday_users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateAutosaveSettings::updateAutosaveSettings()
  : scope_()
  , settings_()
{}

updateAutosaveSettings::updateAutosaveSettings(object_ptr<AutosaveSettingsScope> &&scope_, object_ptr<scopeAutosaveSettings> &&settings_)
  : scope_(std::move(scope_))
  , settings_(std::move(settings_))
{}

const std::int32_t updateAutosaveSettings::ID;

void updateAutosaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAutosaveSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

updateBusinessConnection::updateBusinessConnection()
  : connection_()
{}

updateBusinessConnection::updateBusinessConnection(object_ptr<businessConnection> &&connection_)
  : connection_(std::move(connection_))
{}

const std::int32_t updateBusinessConnection::ID;

void updateBusinessConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBusinessConnection");
    s.store_object_field("connection", static_cast<const BaseObject *>(connection_.get()));
    s.store_class_end();
  }
}

updateNewBusinessMessage::updateNewBusinessMessage()
  : connection_id_()
  , message_()
{}

updateNewBusinessMessage::updateNewBusinessMessage(string const &connection_id_, object_ptr<businessMessage> &&message_)
  : connection_id_(connection_id_)
  , message_(std::move(message_))
{}

const std::int32_t updateNewBusinessMessage::ID;

void updateNewBusinessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewBusinessMessage");
    s.store_field("connection_id", connection_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateBusinessMessageEdited::updateBusinessMessageEdited()
  : connection_id_()
  , message_()
{}

updateBusinessMessageEdited::updateBusinessMessageEdited(string const &connection_id_, object_ptr<businessMessage> &&message_)
  : connection_id_(connection_id_)
  , message_(std::move(message_))
{}

const std::int32_t updateBusinessMessageEdited::ID;

void updateBusinessMessageEdited::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBusinessMessageEdited");
    s.store_field("connection_id", connection_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateBusinessMessagesDeleted::updateBusinessMessagesDeleted()
  : connection_id_()
  , chat_id_()
  , message_ids_()
{}

updateBusinessMessagesDeleted::updateBusinessMessagesDeleted(string const &connection_id_, int53 chat_id_, array<int53> &&message_ids_)
  : connection_id_(connection_id_)
  , chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
{}

const std::int32_t updateBusinessMessagesDeleted::ID;

void updateBusinessMessagesDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBusinessMessagesDeleted");
    s.store_field("connection_id", connection_id_);
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateNewInlineQuery::updateNewInlineQuery()
  : id_()
  , sender_user_id_()
  , user_location_()
  , chat_type_()
  , query_()
  , offset_()
{}

updateNewInlineQuery::updateNewInlineQuery(int64 id_, int53 sender_user_id_, object_ptr<location> &&user_location_, object_ptr<ChatType> &&chat_type_, string const &query_, string const &offset_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , user_location_(std::move(user_location_))
  , chat_type_(std::move(chat_type_))
  , query_(query_)
  , offset_(offset_)
{}

const std::int32_t updateNewInlineQuery::ID;

void updateNewInlineQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewInlineQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_object_field("user_location", static_cast<const BaseObject *>(user_location_.get()));
    s.store_object_field("chat_type", static_cast<const BaseObject *>(chat_type_.get()));
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

updateNewChosenInlineResult::updateNewChosenInlineResult()
  : sender_user_id_()
  , user_location_()
  , query_()
  , result_id_()
  , inline_message_id_()
{}

updateNewChosenInlineResult::updateNewChosenInlineResult(int53 sender_user_id_, object_ptr<location> &&user_location_, string const &query_, string const &result_id_, string const &inline_message_id_)
  : sender_user_id_(sender_user_id_)
  , user_location_(std::move(user_location_))
  , query_(query_)
  , result_id_(result_id_)
  , inline_message_id_(inline_message_id_)
{}

const std::int32_t updateNewChosenInlineResult::ID;

void updateNewChosenInlineResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewChosenInlineResult");
    s.store_field("sender_user_id", sender_user_id_);
    s.store_object_field("user_location", static_cast<const BaseObject *>(user_location_.get()));
    s.store_field("query", query_);
    s.store_field("result_id", result_id_);
    s.store_field("inline_message_id", inline_message_id_);
    s.store_class_end();
  }
}

updateNewCallbackQuery::updateNewCallbackQuery()
  : id_()
  , sender_user_id_()
  , chat_id_()
  , message_id_()
  , chat_instance_()
  , payload_()
{}

updateNewCallbackQuery::updateNewCallbackQuery(int64 id_, int53 sender_user_id_, int53 chat_id_, int53 message_id_, int64 chat_instance_, object_ptr<CallbackQueryPayload> &&payload_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , chat_instance_(chat_instance_)
  , payload_(std::move(payload_))
{}

const std::int32_t updateNewCallbackQuery::ID;

void updateNewCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewCallbackQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("chat_instance", chat_instance_);
    s.store_object_field("payload", static_cast<const BaseObject *>(payload_.get()));
    s.store_class_end();
  }
}

updateNewInlineCallbackQuery::updateNewInlineCallbackQuery()
  : id_()
  , sender_user_id_()
  , inline_message_id_()
  , chat_instance_()
  , payload_()
{}

updateNewInlineCallbackQuery::updateNewInlineCallbackQuery(int64 id_, int53 sender_user_id_, string const &inline_message_id_, int64 chat_instance_, object_ptr<CallbackQueryPayload> &&payload_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , inline_message_id_(inline_message_id_)
  , chat_instance_(chat_instance_)
  , payload_(std::move(payload_))
{}

const std::int32_t updateNewInlineCallbackQuery::ID;

void updateNewInlineCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewInlineCallbackQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("inline_message_id", inline_message_id_);
    s.store_field("chat_instance", chat_instance_);
    s.store_object_field("payload", static_cast<const BaseObject *>(payload_.get()));
    s.store_class_end();
  }
}

updateNewBusinessCallbackQuery::updateNewBusinessCallbackQuery()
  : id_()
  , sender_user_id_()
  , connection_id_()
  , message_()
  , chat_instance_()
  , payload_()
{}

updateNewBusinessCallbackQuery::updateNewBusinessCallbackQuery(int64 id_, int53 sender_user_id_, string const &connection_id_, object_ptr<businessMessage> &&message_, int64 chat_instance_, object_ptr<CallbackQueryPayload> &&payload_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , connection_id_(connection_id_)
  , message_(std::move(message_))
  , chat_instance_(chat_instance_)
  , payload_(std::move(payload_))
{}

const std::int32_t updateNewBusinessCallbackQuery::ID;

void updateNewBusinessCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewBusinessCallbackQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("connection_id", connection_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("chat_instance", chat_instance_);
    s.store_object_field("payload", static_cast<const BaseObject *>(payload_.get()));
    s.store_class_end();
  }
}

updateNewShippingQuery::updateNewShippingQuery()
  : id_()
  , sender_user_id_()
  , invoice_payload_()
  , shipping_address_()
{}

updateNewShippingQuery::updateNewShippingQuery(int64 id_, int53 sender_user_id_, string const &invoice_payload_, object_ptr<address> &&shipping_address_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , invoice_payload_(invoice_payload_)
  , shipping_address_(std::move(shipping_address_))
{}

const std::int32_t updateNewShippingQuery::ID;

void updateNewShippingQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewShippingQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("invoice_payload", invoice_payload_);
    s.store_object_field("shipping_address", static_cast<const BaseObject *>(shipping_address_.get()));
    s.store_class_end();
  }
}

updateNewPreCheckoutQuery::updateNewPreCheckoutQuery()
  : id_()
  , sender_user_id_()
  , currency_()
  , total_amount_()
  , invoice_payload_()
  , shipping_option_id_()
  , order_info_()
{}

updateNewPreCheckoutQuery::updateNewPreCheckoutQuery(int64 id_, int53 sender_user_id_, string const &currency_, int53 total_amount_, bytes const &invoice_payload_, string const &shipping_option_id_, object_ptr<orderInfo> &&order_info_)
  : id_(id_)
  , sender_user_id_(sender_user_id_)
  , currency_(currency_)
  , total_amount_(total_amount_)
  , invoice_payload_(std::move(invoice_payload_))
  , shipping_option_id_(shipping_option_id_)
  , order_info_(std::move(order_info_))
{}

const std::int32_t updateNewPreCheckoutQuery::ID;

void updateNewPreCheckoutQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewPreCheckoutQuery");
    s.store_field("id", id_);
    s.store_field("sender_user_id", sender_user_id_);
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_bytes_field("invoice_payload", invoice_payload_);
    s.store_field("shipping_option_id", shipping_option_id_);
    s.store_object_field("order_info", static_cast<const BaseObject *>(order_info_.get()));
    s.store_class_end();
  }
}

updateNewCustomEvent::updateNewCustomEvent()
  : event_()
{}

updateNewCustomEvent::updateNewCustomEvent(string const &event_)
  : event_(event_)
{}

const std::int32_t updateNewCustomEvent::ID;

void updateNewCustomEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewCustomEvent");
    s.store_field("event", event_);
    s.store_class_end();
  }
}

updateNewCustomQuery::updateNewCustomQuery()
  : id_()
  , data_()
  , timeout_()
{}

updateNewCustomQuery::updateNewCustomQuery(int64 id_, string const &data_, int32 timeout_)
  : id_(id_)
  , data_(data_)
  , timeout_(timeout_)
{}

const std::int32_t updateNewCustomQuery::ID;

void updateNewCustomQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewCustomQuery");
    s.store_field("id", id_);
    s.store_field("data", data_);
    s.store_field("timeout", timeout_);
    s.store_class_end();
  }
}

updatePoll::updatePoll()
  : poll_()
{}

updatePoll::updatePoll(object_ptr<poll> &&poll_)
  : poll_(std::move(poll_))
{}

const std::int32_t updatePoll::ID;

void updatePoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePoll");
    s.store_object_field("poll", static_cast<const BaseObject *>(poll_.get()));
    s.store_class_end();
  }
}

updatePollAnswer::updatePollAnswer()
  : poll_id_()
  , voter_id_()
  , option_ids_()
  , option_positions_()
{}

updatePollAnswer::updatePollAnswer(int64 poll_id_, object_ptr<MessageSender> &&voter_id_, array<string> &&option_ids_, array<int32> &&option_positions_)
  : poll_id_(poll_id_)
  , voter_id_(std::move(voter_id_))
  , option_ids_(std::move(option_ids_))
  , option_positions_(std::move(option_positions_))
{}

const std::int32_t updatePollAnswer::ID;

void updatePollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePollAnswer");
    s.store_field("poll_id", poll_id_);
    s.store_object_field("voter_id", static_cast<const BaseObject *>(voter_id_.get()));
    { s.store_vector_begin("option_ids", option_ids_.size()); for (const auto &_value : option_ids_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("option_positions", option_positions_.size()); for (const auto &_value : option_positions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateManagedBot::updateManagedBot()
  : user_id_()
  , bot_user_id_()
{}

updateManagedBot::updateManagedBot(int53 user_id_, int53 bot_user_id_)
  : user_id_(user_id_)
  , bot_user_id_(bot_user_id_)
{}

const std::int32_t updateManagedBot::ID;

void updateManagedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateManagedBot");
    s.store_field("user_id", user_id_);
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

updateChatMember::updateChatMember()
  : chat_id_()
  , actor_user_id_()
  , date_()
  , invite_link_()
  , via_join_request_()
  , via_chat_folder_invite_link_()
  , old_chat_member_()
  , new_chat_member_()
{}

updateChatMember::updateChatMember(int53 chat_id_, int53 actor_user_id_, int32 date_, object_ptr<chatInviteLink> &&invite_link_, bool via_join_request_, bool via_chat_folder_invite_link_, object_ptr<chatMember> &&old_chat_member_, object_ptr<chatMember> &&new_chat_member_)
  : chat_id_(chat_id_)
  , actor_user_id_(actor_user_id_)
  , date_(date_)
  , invite_link_(std::move(invite_link_))
  , via_join_request_(via_join_request_)
  , via_chat_folder_invite_link_(via_chat_folder_invite_link_)
  , old_chat_member_(std::move(old_chat_member_))
  , new_chat_member_(std::move(new_chat_member_))
{}

const std::int32_t updateChatMember::ID;

void updateChatMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatMember");
    s.store_field("chat_id", chat_id_);
    s.store_field("actor_user_id", actor_user_id_);
    s.store_field("date", date_);
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_field("via_join_request", via_join_request_);
    s.store_field("via_chat_folder_invite_link", via_chat_folder_invite_link_);
    s.store_object_field("old_chat_member", static_cast<const BaseObject *>(old_chat_member_.get()));
    s.store_object_field("new_chat_member", static_cast<const BaseObject *>(new_chat_member_.get()));
    s.store_class_end();
  }
}

updateNewChatJoinRequest::updateNewChatJoinRequest()
  : chat_id_()
  , request_()
  , user_chat_id_()
  , invite_link_()
{}

updateNewChatJoinRequest::updateNewChatJoinRequest(int53 chat_id_, object_ptr<chatJoinRequest> &&request_, int53 user_chat_id_, object_ptr<chatInviteLink> &&invite_link_)
  : chat_id_(chat_id_)
  , request_(std::move(request_))
  , user_chat_id_(user_chat_id_)
  , invite_link_(std::move(invite_link_))
{}

const std::int32_t updateNewChatJoinRequest::ID;

void updateNewChatJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewChatJoinRequest");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("request", static_cast<const BaseObject *>(request_.get()));
    s.store_field("user_chat_id", user_chat_id_);
    s.store_object_field("invite_link", static_cast<const BaseObject *>(invite_link_.get()));
    s.store_class_end();
  }
}

updateChatBoost::updateChatBoost()
  : chat_id_()
  , boost_()
{}

updateChatBoost::updateChatBoost(int53 chat_id_, object_ptr<chatBoost> &&boost_)
  : chat_id_(chat_id_)
  , boost_(std::move(boost_))
{}

const std::int32_t updateChatBoost::ID;

void updateChatBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatBoost");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("boost", static_cast<const BaseObject *>(boost_.get()));
    s.store_class_end();
  }
}

updateMessageReaction::updateMessageReaction()
  : chat_id_()
  , message_id_()
  , actor_id_()
  , date_()
  , old_reaction_types_()
  , new_reaction_types_()
{}

updateMessageReaction::updateMessageReaction(int53 chat_id_, int53 message_id_, object_ptr<MessageSender> &&actor_id_, int32 date_, array<object_ptr<ReactionType>> &&old_reaction_types_, array<object_ptr<ReactionType>> &&new_reaction_types_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , actor_id_(std::move(actor_id_))
  , date_(date_)
  , old_reaction_types_(std::move(old_reaction_types_))
  , new_reaction_types_(std::move(new_reaction_types_))
{}

const std::int32_t updateMessageReaction::ID;

void updateMessageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageReaction");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("actor_id", static_cast<const BaseObject *>(actor_id_.get()));
    s.store_field("date", date_);
    { s.store_vector_begin("old_reaction_types", old_reaction_types_.size()); for (const auto &_value : old_reaction_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("new_reaction_types", new_reaction_types_.size()); for (const auto &_value : new_reaction_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateMessageReactions::updateMessageReactions()
  : chat_id_()
  , message_id_()
  , date_()
  , reactions_()
{}

updateMessageReactions::updateMessageReactions(int53 chat_id_, int53 message_id_, int32 date_, array<object_ptr<messageReaction>> &&reactions_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , date_(date_)
  , reactions_(std::move(reactions_))
{}

const std::int32_t updateMessageReactions::ID;

void updateMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("date", date_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updatePaidMediaPurchased::updatePaidMediaPurchased()
  : user_id_()
  , payload_()
{}

updatePaidMediaPurchased::updatePaidMediaPurchased(int53 user_id_, string const &payload_)
  : user_id_(user_id_)
  , payload_(payload_)
{}

const std::int32_t updatePaidMediaPurchased::ID;

void updatePaidMediaPurchased::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePaidMediaPurchased");
    s.store_field("user_id", user_id_);
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

webAppOpenParameters::webAppOpenParameters()
  : theme_()
  , application_name_()
  , mode_()
{}

webAppOpenParameters::webAppOpenParameters(object_ptr<themeParameters> &&theme_, string const &application_name_, object_ptr<WebAppOpenMode> &&mode_)
  : theme_(std::move(theme_))
  , application_name_(application_name_)
  , mode_(std::move(mode_))
{}

const std::int32_t webAppOpenParameters::ID;

void webAppOpenParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAppOpenParameters");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_field("application_name", application_name_);
    s.store_object_field("mode", static_cast<const BaseObject *>(mode_.get()));
    s.store_class_end();
  }
}

addChatFolderByInviteLink::addChatFolderByInviteLink()
  : invite_link_()
  , chat_ids_()
{}

addChatFolderByInviteLink::addChatFolderByInviteLink(string const &invite_link_, array<int53> &&chat_ids_)
  : invite_link_(invite_link_)
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t addChatFolderByInviteLink::ID;

void addChatFolderByInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChatFolderByInviteLink");
    s.store_field("invite_link", invite_link_);
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

addChatToList::addChatToList()
  : chat_id_()
  , chat_list_()
{}

addChatToList::addChatToList(int53 chat_id_, object_ptr<ChatList> &&chat_list_)
  : chat_id_(chat_id_)
  , chat_list_(std::move(chat_list_))
{}

const std::int32_t addChatToList::ID;

void addChatToList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addChatToList");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_class_end();
  }
}

addFileToDownloads::addFileToDownloads()
  : file_id_()
  , chat_id_()
  , message_id_()
  , priority_()
{}

addFileToDownloads::addFileToDownloads(int32 file_id_, int53 chat_id_, int53 message_id_, int32 priority_)
  : file_id_(file_id_)
  , chat_id_(chat_id_)
  , message_id_(message_id_)
  , priority_(priority_)
{}

const std::int32_t addFileToDownloads::ID;

void addFileToDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addFileToDownloads");
    s.store_field("file_id", file_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("priority", priority_);
    s.store_class_end();
  }
}

addGiftCollectionGifts::addGiftCollectionGifts()
  : owner_id_()
  , collection_id_()
  , received_gift_ids_()
{}

addGiftCollectionGifts::addGiftCollectionGifts(object_ptr<MessageSender> &&owner_id_, int32 collection_id_, array<string> &&received_gift_ids_)
  : owner_id_(std::move(owner_id_))
  , collection_id_(collection_id_)
  , received_gift_ids_(std::move(received_gift_ids_))
{}

const std::int32_t addGiftCollectionGifts::ID;

void addGiftCollectionGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addGiftCollectionGifts");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("collection_id", collection_id_);
    { s.store_vector_begin("received_gift_ids", received_gift_ids_.size()); for (const auto &_value : received_gift_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

addNetworkStatistics::addNetworkStatistics()
  : entry_()
{}

addNetworkStatistics::addNetworkStatistics(object_ptr<NetworkStatisticsEntry> &&entry_)
  : entry_(std::move(entry_))
{}

const std::int32_t addNetworkStatistics::ID;

void addNetworkStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addNetworkStatistics");
    s.store_object_field("entry", static_cast<const BaseObject *>(entry_.get()));
    s.store_class_end();
  }
}

canPostStory::canPostStory()
  : chat_id_()
{}

canPostStory::canPostStory(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t canPostStory::ID;

void canPostStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canPostStory");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

canTransferOwnership::canTransferOwnership() {
}

const std::int32_t canTransferOwnership::ID;

void canTransferOwnership::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "canTransferOwnership");
    s.store_class_end();
  }
}

cancelPasswordReset::cancelPasswordReset() {
}

const std::int32_t cancelPasswordReset::ID;

void cancelPasswordReset::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cancelPasswordReset");
    s.store_class_end();
  }
}

checkAuthenticationPassword::checkAuthenticationPassword()
  : password_()
{}

checkAuthenticationPassword::checkAuthenticationPassword(string const &password_)
  : password_(password_)
{}

const std::int32_t checkAuthenticationPassword::ID;

void checkAuthenticationPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationPassword");
    s.store_field("password", password_);
    s.store_class_end();
  }
}

checkChatInviteLink::checkChatInviteLink()
  : invite_link_()
{}

checkChatInviteLink::checkChatInviteLink(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t checkChatInviteLink::ID;

void checkChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

checkChatUsername::checkChatUsername()
  : chat_id_()
  , username_()
{}

checkChatUsername::checkChatUsername(int53 chat_id_, string const &username_)
  : chat_id_(chat_id_)
  , username_(username_)
{}

const std::int32_t checkChatUsername::ID;

void checkChatUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkChatUsername");
    s.store_field("chat_id", chat_id_);
    s.store_field("username", username_);
    s.store_class_end();
  }
}

cleanFileName::cleanFileName()
  : file_name_()
{}

cleanFileName::cleanFileName(string const &file_name_)
  : file_name_(file_name_)
{}

const std::int32_t cleanFileName::ID;

void cleanFileName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cleanFileName");
    s.store_field("file_name", file_name_);
    s.store_class_end();
  }
}

clearRecentStickers::clearRecentStickers()
  : is_attached_()
{}

clearRecentStickers::clearRecentStickers(bool is_attached_)
  : is_attached_(is_attached_)
{}

const std::int32_t clearRecentStickers::ID;

void clearRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearRecentStickers");
    s.store_field("is_attached", is_attached_);
    s.store_class_end();
  }
}

clickPremiumSubscriptionButton::clickPremiumSubscriptionButton() {
}

const std::int32_t clickPremiumSubscriptionButton::ID;

void clickPremiumSubscriptionButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clickPremiumSubscriptionButton");
    s.store_class_end();
  }
}

closeGiftAuction::closeGiftAuction()
  : gift_id_()
{}

closeGiftAuction::closeGiftAuction(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t closeGiftAuction::ID;

void closeGiftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeGiftAuction");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

createGroupCall::createGroupCall()
  : join_parameters_()
{}

createGroupCall::createGroupCall(object_ptr<groupCallJoinParameters> &&join_parameters_)
  : join_parameters_(std::move(join_parameters_))
{}

const std::int32_t createGroupCall::ID;

void createGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createGroupCall");
    s.store_object_field("join_parameters", static_cast<const BaseObject *>(join_parameters_.get()));
    s.store_class_end();
  }
}

createNewSupergroupChat::createNewSupergroupChat()
  : title_()
  , is_forum_()
  , is_channel_()
  , description_()
  , location_()
  , message_auto_delete_time_()
  , for_import_()
{}

createNewSupergroupChat::createNewSupergroupChat(string const &title_, bool is_forum_, bool is_channel_, string const &description_, object_ptr<chatLocation> &&location_, int32 message_auto_delete_time_, bool for_import_)
  : title_(title_)
  , is_forum_(is_forum_)
  , is_channel_(is_channel_)
  , description_(description_)
  , location_(std::move(location_))
  , message_auto_delete_time_(message_auto_delete_time_)
  , for_import_(for_import_)
{}

const std::int32_t createNewSupergroupChat::ID;

void createNewSupergroupChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createNewSupergroupChat");
    s.store_field("title", title_);
    s.store_field("is_forum", is_forum_);
    s.store_field("is_channel", is_channel_);
    s.store_field("description", description_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("message_auto_delete_time", message_auto_delete_time_);
    s.store_field("for_import", for_import_);
    s.store_class_end();
  }
}

deleteChatBackground::deleteChatBackground()
  : chat_id_()
  , restore_previous_()
{}

deleteChatBackground::deleteChatBackground(int53 chat_id_, bool restore_previous_)
  : chat_id_(chat_id_)
  , restore_previous_(restore_previous_)
{}

const std::int32_t deleteChatBackground::ID;

void deleteChatBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatBackground");
    s.store_field("chat_id", chat_id_);
    s.store_field("restore_previous", restore_previous_);
    s.store_class_end();
  }
}

deleteChatMessagesBySender::deleteChatMessagesBySender()
  : chat_id_()
  , sender_id_()
{}

deleteChatMessagesBySender::deleteChatMessagesBySender(int53 chat_id_, object_ptr<MessageSender> &&sender_id_)
  : chat_id_(chat_id_)
  , sender_id_(std::move(sender_id_))
{}

const std::int32_t deleteChatMessagesBySender::ID;

void deleteChatMessagesBySender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatMessagesBySender");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_class_end();
  }
}

deleteCommands::deleteCommands()
  : scope_()
  , language_code_()
{}

deleteCommands::deleteCommands(object_ptr<BotCommandScope> &&scope_, string const &language_code_)
  : scope_(std::move(scope_))
  , language_code_(language_code_)
{}

const std::int32_t deleteCommands::ID;

void deleteCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

deleteDirectMessagesChatTopicMessagesByDate::deleteDirectMessagesChatTopicMessagesByDate()
  : chat_id_()
  , topic_id_()
  , min_date_()
  , max_date_()
{}

deleteDirectMessagesChatTopicMessagesByDate::deleteDirectMessagesChatTopicMessagesByDate(int53 chat_id_, int53 topic_id_, int32 min_date_, int32 max_date_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
  , min_date_(min_date_)
  , max_date_(max_date_)
{}

const std::int32_t deleteDirectMessagesChatTopicMessagesByDate::ID;

void deleteDirectMessagesChatTopicMessagesByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteDirectMessagesChatTopicMessagesByDate");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_class_end();
  }
}

deleteSavedCredentials::deleteSavedCredentials() {
}

const std::int32_t deleteSavedCredentials::ID;

void deleteSavedCredentials::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteSavedCredentials");
    s.store_class_end();
  }
}

deleteStory::deleteStory()
  : story_poster_chat_id_()
  , story_id_()
{}

deleteStory::deleteStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t deleteStory::ID;

void deleteStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

disableProxy::disableProxy() {
}

const std::int32_t disableProxy::ID;

void disableProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disableProxy");
    s.store_class_end();
  }
}

discardCall::discardCall()
  : call_id_()
  , is_disconnected_()
  , invite_link_()
  , duration_()
  , is_video_()
  , connection_id_()
{}

discardCall::discardCall(int32 call_id_, bool is_disconnected_, string const &invite_link_, int32 duration_, bool is_video_, int64 connection_id_)
  : call_id_(call_id_)
  , is_disconnected_(is_disconnected_)
  , invite_link_(invite_link_)
  , duration_(duration_)
  , is_video_(is_video_)
  , connection_id_(connection_id_)
{}

const std::int32_t discardCall::ID;

void discardCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "discardCall");
    s.store_field("call_id", call_id_);
    s.store_field("is_disconnected", is_disconnected_);
    s.store_field("invite_link", invite_link_);
    s.store_field("duration", duration_);
    s.store_field("is_video", is_video_);
    s.store_field("connection_id", connection_id_);
    s.store_class_end();
  }
}

editBusinessChatLink::editBusinessChatLink()
  : link_()
  , link_info_()
{}

editBusinessChatLink::editBusinessChatLink(string const &link_, object_ptr<inputBusinessChatLink> &&link_info_)
  : link_(link_)
  , link_info_(std::move(link_info_))
{}

const std::int32_t editBusinessChatLink::ID;

void editBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessChatLink");
    s.store_field("link", link_);
    s.store_object_field("link_info", static_cast<const BaseObject *>(link_info_.get()));
    s.store_class_end();
  }
}

editForumTopic::editForumTopic()
  : chat_id_()
  , forum_topic_id_()
  , name_()
  , edit_icon_custom_emoji_()
  , icon_custom_emoji_id_()
{}

editForumTopic::editForumTopic(int53 chat_id_, int32 forum_topic_id_, string const &name_, bool edit_icon_custom_emoji_, int64 icon_custom_emoji_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
  , name_(name_)
  , edit_icon_custom_emoji_(edit_icon_custom_emoji_)
  , icon_custom_emoji_id_(icon_custom_emoji_id_)
{}

const std::int32_t editForumTopic::ID;

void editForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editForumTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_field("name", name_);
    s.store_field("edit_icon_custom_emoji", edit_icon_custom_emoji_);
    s.store_field("icon_custom_emoji_id", icon_custom_emoji_id_);
    s.store_class_end();
  }
}

editUserStarSubscription::editUserStarSubscription()
  : user_id_()
  , telegram_payment_charge_id_()
  , is_canceled_()
{}

editUserStarSubscription::editUserStarSubscription(int53 user_id_, string const &telegram_payment_charge_id_, bool is_canceled_)
  : user_id_(user_id_)
  , telegram_payment_charge_id_(telegram_payment_charge_id_)
  , is_canceled_(is_canceled_)
{}

const std::int32_t editUserStarSubscription::ID;

void editUserStarSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editUserStarSubscription");
    s.store_field("user_id", user_id_);
    s.store_field("telegram_payment_charge_id", telegram_payment_charge_id_);
    s.store_field("is_canceled", is_canceled_);
    s.store_class_end();
  }
}

getAllPassportElements::getAllPassportElements()
  : password_()
{}

getAllPassportElements::getAllPassportElements(string const &password_)
  : password_(password_)
{}

const std::int32_t getAllPassportElements::ID;

void getAllPassportElements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAllPassportElements");
    s.store_field("password", password_);
    s.store_class_end();
  }
}

getAllStickerEmojis::getAllStickerEmojis()
  : sticker_type_()
  , query_()
  , chat_id_()
  , return_only_main_emoji_()
{}

getAllStickerEmojis::getAllStickerEmojis(object_ptr<StickerType> &&sticker_type_, string const &query_, int53 chat_id_, bool return_only_main_emoji_)
  : sticker_type_(std::move(sticker_type_))
  , query_(query_)
  , chat_id_(chat_id_)
  , return_only_main_emoji_(return_only_main_emoji_)
{}

const std::int32_t getAllStickerEmojis::ID;

void getAllStickerEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getAllStickerEmojis");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("query", query_);
    s.store_field("chat_id", chat_id_);
    s.store_field("return_only_main_emoji", return_only_main_emoji_);
    s.store_class_end();
  }
}

getApplicationDownloadLink::getApplicationDownloadLink() {
}

const std::int32_t getApplicationDownloadLink::ID;

void getApplicationDownloadLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getApplicationDownloadLink");
    s.store_class_end();
  }
}

getArchiveChatListSettings::getArchiveChatListSettings() {
}

const std::int32_t getArchiveChatListSettings::ID;

void getArchiveChatListSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getArchiveChatListSettings");
    s.store_class_end();
  }
}

getBotInfoShortDescription::getBotInfoShortDescription()
  : bot_user_id_()
  , language_code_()
{}

getBotInfoShortDescription::getBotInfoShortDescription(int53 bot_user_id_, string const &language_code_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
{}

const std::int32_t getBotInfoShortDescription::ID;

void getBotInfoShortDescription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotInfoShortDescription");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getBotMediaPreviewInfo::getBotMediaPreviewInfo()
  : bot_user_id_()
  , language_code_()
{}

getBotMediaPreviewInfo::getBotMediaPreviewInfo(int53 bot_user_id_, string const &language_code_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
{}

const std::int32_t getBotMediaPreviewInfo::ID;

void getBotMediaPreviewInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getBotMediaPreviewInfo");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_class_end();
  }
}

getCallbackQueryMessage::getCallbackQueryMessage()
  : chat_id_()
  , message_id_()
  , callback_query_id_()
{}

getCallbackQueryMessage::getCallbackQueryMessage(int53 chat_id_, int53 message_id_, int64 callback_query_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , callback_query_id_(callback_query_id_)
{}

const std::int32_t getCallbackQueryMessage::ID;

void getCallbackQueryMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCallbackQueryMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("callback_query_id", callback_query_id_);
    s.store_class_end();
  }
}

getChat::getChat()
  : chat_id_()
{}

getChat::getChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChat::ID;

void getChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatFolderInviteLinks::getChatFolderInviteLinks()
  : chat_folder_id_()
{}

getChatFolderInviteLinks::getChatFolderInviteLinks(int32 chat_folder_id_)
  : chat_folder_id_(chat_folder_id_)
{}

const std::int32_t getChatFolderInviteLinks::ID;

void getChatFolderInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatFolderInviteLinks");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_class_end();
  }
}

getChatInviteLinks::getChatInviteLinks()
  : chat_id_()
  , creator_user_id_()
  , is_revoked_()
  , offset_date_()
  , offset_invite_link_()
  , limit_()
{}

getChatInviteLinks::getChatInviteLinks(int53 chat_id_, int53 creator_user_id_, bool is_revoked_, int32 offset_date_, string const &offset_invite_link_, int32 limit_)
  : chat_id_(chat_id_)
  , creator_user_id_(creator_user_id_)
  , is_revoked_(is_revoked_)
  , offset_date_(offset_date_)
  , offset_invite_link_(offset_invite_link_)
  , limit_(limit_)
{}

const std::int32_t getChatInviteLinks::ID;

void getChatInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatInviteLinks");
    s.store_field("chat_id", chat_id_);
    s.store_field("creator_user_id", creator_user_id_);
    s.store_field("is_revoked", is_revoked_);
    s.store_field("offset_date", offset_date_);
    s.store_field("offset_invite_link", offset_invite_link_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatPostedToChatPageStories::getChatPostedToChatPageStories()
  : chat_id_()
  , from_story_id_()
  , limit_()
{}

getChatPostedToChatPageStories::getChatPostedToChatPageStories(int53 chat_id_, int32 from_story_id_, int32 limit_)
  : chat_id_(chat_id_)
  , from_story_id_(from_story_id_)
  , limit_(limit_)
{}

const std::int32_t getChatPostedToChatPageStories::ID;

void getChatPostedToChatPageStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatPostedToChatPageStories");
    s.store_field("chat_id", chat_id_);
    s.store_field("from_story_id", from_story_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatSimilarChatCount::getChatSimilarChatCount()
  : chat_id_()
  , return_local_()
{}

getChatSimilarChatCount::getChatSimilarChatCount(int53 chat_id_, bool return_local_)
  : chat_id_(chat_id_)
  , return_local_(return_local_)
{}

const std::int32_t getChatSimilarChatCount::ID;

void getChatSimilarChatCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatSimilarChatCount");
    s.store_field("chat_id", chat_id_);
    s.store_field("return_local", return_local_);
    s.store_class_end();
  }
}

getChatStatistics::getChatStatistics()
  : chat_id_()
  , is_dark_()
{}

getChatStatistics::getChatStatistics(int53 chat_id_, bool is_dark_)
  : chat_id_(chat_id_)
  , is_dark_(is_dark_)
{}

const std::int32_t getChatStatistics::ID;

void getChatStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatStatistics");
    s.store_field("chat_id", chat_id_);
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getCloseFriends::getCloseFriends() {
}

const std::int32_t getCloseFriends::ID;

void getCloseFriends::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCloseFriends");
    s.store_class_end();
  }
}

getCollectibleItemInfo::getCollectibleItemInfo()
  : type_()
{}

getCollectibleItemInfo::getCollectibleItemInfo(object_ptr<CollectibleItemType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t getCollectibleItemInfo::ID;

void getCollectibleItemInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCollectibleItemInfo");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

getCountries::getCountries() {
}

const std::int32_t getCountries::ID;

void getCountries::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCountries");
    s.store_class_end();
  }
}

getCreatedPublicChats::getCreatedPublicChats()
  : type_()
{}

getCreatedPublicChats::getCreatedPublicChats(object_ptr<PublicChatType> &&type_)
  : type_(std::move(type_))
{}

const std::int32_t getCreatedPublicChats::ID;

void getCreatedPublicChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCreatedPublicChats");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

getDatabaseStatistics::getDatabaseStatistics() {
}

const std::int32_t getDatabaseStatistics::ID;

void getDatabaseStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDatabaseStatistics");
    s.store_class_end();
  }
}

getDefaultEmojiStatuses::getDefaultEmojiStatuses() {
}

const std::int32_t getDefaultEmojiStatuses::ID;

void getDefaultEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDefaultEmojiStatuses");
    s.store_class_end();
  }
}

getDefaultProfilePhotoCustomEmojiStickers::getDefaultProfilePhotoCustomEmojiStickers() {
}

const std::int32_t getDefaultProfilePhotoCustomEmojiStickers::ID;

void getDefaultProfilePhotoCustomEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDefaultProfilePhotoCustomEmojiStickers");
    s.store_class_end();
  }
}

getDirectMessagesChatTopic::getDirectMessagesChatTopic()
  : chat_id_()
  , topic_id_()
{}

getDirectMessagesChatTopic::getDirectMessagesChatTopic(int53 chat_id_, int53 topic_id_)
  : chat_id_(chat_id_)
  , topic_id_(topic_id_)
{}

const std::int32_t getDirectMessagesChatTopic::ID;

void getDirectMessagesChatTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getDirectMessagesChatTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("topic_id", topic_id_);
    s.store_class_end();
  }
}

getFileDownloadedPrefixSize::getFileDownloadedPrefixSize()
  : file_id_()
  , offset_()
{}

getFileDownloadedPrefixSize::getFileDownloadedPrefixSize(int32 file_id_, int53 offset_)
  : file_id_(file_id_)
  , offset_(offset_)
{}

const std::int32_t getFileDownloadedPrefixSize::ID;

void getFileDownloadedPrefixSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFileDownloadedPrefixSize");
    s.store_field("file_id", file_id_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

getFileExtension::getFileExtension()
  : mime_type_()
{}

getFileExtension::getFileExtension(string const &mime_type_)
  : mime_type_(mime_type_)
{}

const std::int32_t getFileExtension::ID;

void getFileExtension::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getFileExtension");
    s.store_field("mime_type", mime_type_);
    s.store_class_end();
  }
}

getForumTopic::getForumTopic()
  : chat_id_()
  , forum_topic_id_()
{}

getForumTopic::getForumTopic(int53 chat_id_, int32 forum_topic_id_)
  : chat_id_(chat_id_)
  , forum_topic_id_(forum_topic_id_)
{}

const std::int32_t getForumTopic::ID;

void getForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getForumTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("forum_topic_id", forum_topic_id_);
    s.store_class_end();
  }
}

getGrossingWebAppBots::getGrossingWebAppBots()
  : offset_()
  , limit_()
{}

getGrossingWebAppBots::getGrossingWebAppBots(string const &offset_, int32 limit_)
  : offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getGrossingWebAppBots::ID;

void getGrossingWebAppBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGrossingWebAppBots");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getGroupCallStreams::getGroupCallStreams()
  : group_call_id_()
{}

getGroupCallStreams::getGroupCallStreams(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t getGroupCallStreams::ID;

void getGroupCallStreams::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getGroupCallStreams");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getLinkPreview::getLinkPreview()
  : text_()
  , link_preview_options_()
{}

getLinkPreview::getLinkPreview(object_ptr<formattedText> &&text_, object_ptr<linkPreviewOptions> &&link_preview_options_)
  : text_(std::move(text_))
  , link_preview_options_(std::move(link_preview_options_))
{}

const std::int32_t getLinkPreview::ID;

void getLinkPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLinkPreview");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("link_preview_options", static_cast<const BaseObject *>(link_preview_options_.get()));
    s.store_class_end();
  }
}

getLogVerbosityLevel::getLogVerbosityLevel() {
}

const std::int32_t getLogVerbosityLevel::ID;

void getLogVerbosityLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLogVerbosityLevel");
    s.store_class_end();
  }
}

getMessageImportConfirmationText::getMessageImportConfirmationText()
  : chat_id_()
{}

getMessageImportConfirmationText::getMessageImportConfirmationText(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getMessageImportConfirmationText::ID;

void getMessageImportConfirmationText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageImportConfirmationText");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getMessageLinkInfo::getMessageLinkInfo()
  : url_()
{}

getMessageLinkInfo::getMessageLinkInfo(string const &url_)
  : url_(url_)
{}

const std::int32_t getMessageLinkInfo::ID;

void getMessageLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageLinkInfo");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

getPassportAuthorizationFormAvailableElements::getPassportAuthorizationFormAvailableElements()
  : authorization_form_id_()
  , password_()
{}

getPassportAuthorizationFormAvailableElements::getPassportAuthorizationFormAvailableElements(int32 authorization_form_id_, string const &password_)
  : authorization_form_id_(authorization_form_id_)
  , password_(password_)
{}

const std::int32_t getPassportAuthorizationFormAvailableElements::ID;

void getPassportAuthorizationFormAvailableElements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPassportAuthorizationFormAvailableElements");
    s.store_field("authorization_form_id", authorization_form_id_);
    s.store_field("password", password_);
    s.store_class_end();
  }
}

getPasswordState::getPasswordState() {
}

const std::int32_t getPasswordState::ID;

void getPasswordState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPasswordState");
    s.store_class_end();
  }
}

getPhoneNumberInfo::getPhoneNumberInfo()
  : phone_number_prefix_()
{}

getPhoneNumberInfo::getPhoneNumberInfo(string const &phone_number_prefix_)
  : phone_number_prefix_(phone_number_prefix_)
{}

const std::int32_t getPhoneNumberInfo::ID;

void getPhoneNumberInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPhoneNumberInfo");
    s.store_field("phone_number_prefix", phone_number_prefix_);
    s.store_class_end();
  }
}

getPollOptionProperties::getPollOptionProperties()
  : chat_id_()
  , message_id_()
  , poll_option_id_()
{}

getPollOptionProperties::getPollOptionProperties(int53 chat_id_, int53 message_id_, string const &poll_option_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , poll_option_id_(poll_option_id_)
{}

const std::int32_t getPollOptionProperties::ID;

void getPollOptionProperties::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPollOptionProperties");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("poll_option_id", poll_option_id_);
    s.store_class_end();
  }
}

getPreparedKeyboardButton::getPreparedKeyboardButton()
  : bot_user_id_()
  , prepared_button_id_()
{}

getPreparedKeyboardButton::getPreparedKeyboardButton(int53 bot_user_id_, string const &prepared_button_id_)
  : bot_user_id_(bot_user_id_)
  , prepared_button_id_(prepared_button_id_)
{}

const std::int32_t getPreparedKeyboardButton::ID;

void getPreparedKeyboardButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPreparedKeyboardButton");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("prepared_button_id", prepared_button_id_);
    s.store_class_end();
  }
}

getSearchSponsoredChats::getSearchSponsoredChats()
  : query_()
{}

getSearchSponsoredChats::getSearchSponsoredChats(string const &query_)
  : query_(query_)
{}

const std::int32_t getSearchSponsoredChats::ID;

void getSearchSponsoredChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSearchSponsoredChats");
    s.store_field("query", query_);
    s.store_class_end();
  }
}

getStatisticalGraph::getStatisticalGraph()
  : chat_id_()
  , token_()
  , x_()
{}

getStatisticalGraph::getStatisticalGraph(int53 chat_id_, string const &token_, int53 x_)
  : chat_id_(chat_id_)
  , token_(token_)
  , x_(x_)
{}

const std::int32_t getStatisticalGraph::ID;

void getStatisticalGraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStatisticalGraph");
    s.store_field("chat_id", chat_id_);
    s.store_field("token", token_);
    s.store_field("x", x_);
    s.store_class_end();
  }
}

getStickers::getStickers()
  : sticker_type_()
  , query_()
  , limit_()
  , chat_id_()
{}

getStickers::getStickers(object_ptr<StickerType> &&sticker_type_, string const &query_, int32 limit_, int53 chat_id_)
  : sticker_type_(std::move(sticker_type_))
  , query_(query_)
  , limit_(limit_)
  , chat_id_(chat_id_)
{}

const std::int32_t getStickers::ID;

void getStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStickers");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getTonWithdrawalUrl::getTonWithdrawalUrl()
  : password_()
{}

getTonWithdrawalUrl::getTonWithdrawalUrl(string const &password_)
  : password_(password_)
{}

const std::int32_t getTonWithdrawalUrl::ID;

void getTonWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTonWithdrawalUrl");
    s.store_field("password", password_);
    s.store_class_end();
  }
}

getTopChats::getTopChats()
  : category_()
  , limit_()
{}

getTopChats::getTopChats(object_ptr<TopChatCategory> &&category_, int32 limit_)
  : category_(std::move(category_))
  , limit_(limit_)
{}

const std::int32_t getTopChats::ID;

void getTopChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getTopChats");
    s.store_object_field("category", static_cast<const BaseObject *>(category_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getUserProfileAudios::getUserProfileAudios()
  : user_id_()
  , offset_()
  , limit_()
{}

getUserProfileAudios::getUserProfileAudios(int53 user_id_, int32 offset_, int32 limit_)
  : user_id_(user_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getUserProfileAudios::ID;

void getUserProfileAudios::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUserProfileAudios");
    s.store_field("user_id", user_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getVideoChatInviteLink::getVideoChatInviteLink()
  : group_call_id_()
  , can_self_unmute_()
{}

getVideoChatInviteLink::getVideoChatInviteLink(int32 group_call_id_, bool can_self_unmute_)
  : group_call_id_(group_call_id_)
  , can_self_unmute_(can_self_unmute_)
{}

const std::int32_t getVideoChatInviteLink::ID;

void getVideoChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getVideoChatInviteLink");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("can_self_unmute", can_self_unmute_);
    s.store_class_end();
  }
}

getVideoMessageAdvertisements::getVideoMessageAdvertisements()
  : chat_id_()
  , message_id_()
{}

getVideoMessageAdvertisements::getVideoMessageAdvertisements(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t getVideoMessageAdvertisements::ID;

void getVideoMessageAdvertisements::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getVideoMessageAdvertisements");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

getWebAppPlaceholder::getWebAppPlaceholder()
  : bot_user_id_()
{}

getWebAppPlaceholder::getWebAppPlaceholder(int53 bot_user_id_)
  : bot_user_id_(bot_user_id_)
{}

const std::int32_t getWebAppPlaceholder::ID;

void getWebAppPlaceholder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getWebAppPlaceholder");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_class_end();
  }
}

hideSuggestedAction::hideSuggestedAction()
  : action_()
{}

hideSuggestedAction::hideSuggestedAction(object_ptr<SuggestedAction> &&action_)
  : action_(std::move(action_))
{}

const std::int32_t hideSuggestedAction::ID;

void hideSuggestedAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "hideSuggestedAction");
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

isLoginEmailAddressRequired::isLoginEmailAddressRequired() {
}

const std::int32_t isLoginEmailAddressRequired::ID;

void isLoginEmailAddressRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "isLoginEmailAddressRequired");
    s.store_class_end();
  }
}

isProfileAudio::isProfileAudio()
  : file_id_()
{}

isProfileAudio::isProfileAudio(int32 file_id_)
  : file_id_(file_id_)
{}

const std::int32_t isProfileAudio::ID;

void isProfileAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "isProfileAudio");
    s.store_field("file_id", file_id_);
    s.store_class_end();
  }
}

joinVideoChat::joinVideoChat()
  : group_call_id_()
  , participant_id_()
  , join_parameters_()
  , invite_hash_()
{}

joinVideoChat::joinVideoChat(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, object_ptr<groupCallJoinParameters> &&join_parameters_, string const &invite_hash_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , join_parameters_(std::move(join_parameters_))
  , invite_hash_(invite_hash_)
{}

const std::int32_t joinVideoChat::ID;

void joinVideoChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinVideoChat");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_object_field("join_parameters", static_cast<const BaseObject *>(join_parameters_.get()));
    s.store_field("invite_hash", invite_hash_);
    s.store_class_end();
  }
}

launchPrepaidGiveaway::launchPrepaidGiveaway()
  : giveaway_id_()
  , parameters_()
  , winner_count_()
  , star_count_()
{}

launchPrepaidGiveaway::launchPrepaidGiveaway(int64 giveaway_id_, object_ptr<giveawayParameters> &&parameters_, int32 winner_count_, int53 star_count_)
  : giveaway_id_(giveaway_id_)
  , parameters_(std::move(parameters_))
  , winner_count_(winner_count_)
  , star_count_(star_count_)
{}

const std::int32_t launchPrepaidGiveaway::ID;

void launchPrepaidGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "launchPrepaidGiveaway");
    s.store_field("giveaway_id", giveaway_id_);
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("winner_count", winner_count_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

loadGroupCallParticipants::loadGroupCallParticipants()
  : group_call_id_()
  , limit_()
{}

loadGroupCallParticipants::loadGroupCallParticipants(int32 group_call_id_, int32 limit_)
  : group_call_id_(group_call_id_)
  , limit_(limit_)
{}

const std::int32_t loadGroupCallParticipants::ID;

void loadGroupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadGroupCallParticipants");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

readAllChatReactions::readAllChatReactions()
  : chat_id_()
{}

readAllChatReactions::readAllChatReactions(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t readAllChatReactions::ID;

void readAllChatReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllChatReactions");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

removeBusinessConnectedBotFromChat::removeBusinessConnectedBotFromChat()
  : chat_id_()
{}

removeBusinessConnectedBotFromChat::removeBusinessConnectedBotFromChat(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t removeBusinessConnectedBotFromChat::ID;

void removeBusinessConnectedBotFromChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeBusinessConnectedBotFromChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

removeFavoriteSticker::removeFavoriteSticker()
  : sticker_()
{}

removeFavoriteSticker::removeFavoriteSticker(object_ptr<InputFile> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t removeFavoriteSticker::ID;

void removeFavoriteSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeFavoriteSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

removeMessageSenderBotVerification::removeMessageSenderBotVerification()
  : bot_user_id_()
  , verified_id_()
{}

removeMessageSenderBotVerification::removeMessageSenderBotVerification(int53 bot_user_id_, object_ptr<MessageSender> &&verified_id_)
  : bot_user_id_(bot_user_id_)
  , verified_id_(std::move(verified_id_))
{}

const std::int32_t removeMessageSenderBotVerification::ID;

void removeMessageSenderBotVerification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeMessageSenderBotVerification");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("verified_id", static_cast<const BaseObject *>(verified_id_.get()));
    s.store_class_end();
  }
}

removeNotification::removeNotification()
  : notification_group_id_()
  , notification_id_()
{}

removeNotification::removeNotification(int32 notification_group_id_, int32 notification_id_)
  : notification_group_id_(notification_group_id_)
  , notification_id_(notification_id_)
{}

const std::int32_t removeNotification::ID;

void removeNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeNotification");
    s.store_field("notification_group_id", notification_group_id_);
    s.store_field("notification_id", notification_id_);
    s.store_class_end();
  }
}

removeRecentSticker::removeRecentSticker()
  : is_attached_()
  , sticker_()
{}

removeRecentSticker::removeRecentSticker(bool is_attached_, object_ptr<InputFile> &&sticker_)
  : is_attached_(is_attached_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t removeRecentSticker::ID;

void removeRecentSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeRecentSticker");
    s.store_field("is_attached", is_attached_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

removeSavedAnimation::removeSavedAnimation()
  : animation_()
{}

removeSavedAnimation::removeSavedAnimation(object_ptr<InputFile> &&animation_)
  : animation_(std::move(animation_))
{}

const std::int32_t removeSavedAnimation::ID;

void removeSavedAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeSavedAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

removeStickerFromSet::removeStickerFromSet()
  : sticker_()
{}

removeStickerFromSet::removeStickerFromSet(object_ptr<InputFile> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t removeStickerFromSet::ID;

void removeStickerFromSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeStickerFromSet");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

reorderStoryAlbumStories::reorderStoryAlbumStories()
  : chat_id_()
  , story_album_id_()
  , story_ids_()
{}

reorderStoryAlbumStories::reorderStoryAlbumStories(int53 chat_id_, int32 story_album_id_, array<int32> &&story_ids_)
  : chat_id_(chat_id_)
  , story_album_id_(story_album_id_)
  , story_ids_(std::move(story_ids_))
{}

const std::int32_t reorderStoryAlbumStories::ID;

void reorderStoryAlbumStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderStoryAlbumStories");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_album_id", story_album_id_);
    { s.store_vector_begin("story_ids", story_ids_.size()); for (const auto &_value : story_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportPhoneNumberCodeMissing::reportPhoneNumberCodeMissing()
  : mobile_network_code_()
{}

reportPhoneNumberCodeMissing::reportPhoneNumberCodeMissing(string const &mobile_network_code_)
  : mobile_network_code_(mobile_network_code_)
{}

const std::int32_t reportPhoneNumberCodeMissing::ID;

void reportPhoneNumberCodeMissing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportPhoneNumberCodeMissing");
    s.store_field("mobile_network_code", mobile_network_code_);
    s.store_class_end();
  }
}

reportSponsoredChat::reportSponsoredChat()
  : sponsored_chat_unique_id_()
  , option_id_()
{}

reportSponsoredChat::reportSponsoredChat(int53 sponsored_chat_unique_id_, bytes const &option_id_)
  : sponsored_chat_unique_id_(sponsored_chat_unique_id_)
  , option_id_(std::move(option_id_))
{}

const std::int32_t reportSponsoredChat::ID;

void reportSponsoredChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportSponsoredChat");
    s.store_field("sponsored_chat_unique_id", sponsored_chat_unique_id_);
    s.store_bytes_field("option_id", option_id_);
    s.store_class_end();
  }
}

requestPasswordRecovery::requestPasswordRecovery() {
}

const std::int32_t requestPasswordRecovery::ID;

void requestPasswordRecovery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestPasswordRecovery");
    s.store_class_end();
  }
}

resendEmailAddressVerificationCode::resendEmailAddressVerificationCode() {
}

const std::int32_t resendEmailAddressVerificationCode::ID;

void resendEmailAddressVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendEmailAddressVerificationCode");
    s.store_class_end();
  }
}

resendRecoveryEmailAddressCode::resendRecoveryEmailAddressCode() {
}

const std::int32_t resendRecoveryEmailAddressCode::ID;

void resendRecoveryEmailAddressCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "resendRecoveryEmailAddressCode");
    s.store_class_end();
  }
}

reuseStarSubscription::reuseStarSubscription()
  : subscription_id_()
{}

reuseStarSubscription::reuseStarSubscription(string const &subscription_id_)
  : subscription_id_(subscription_id_)
{}

const std::int32_t reuseStarSubscription::ID;

void reuseStarSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reuseStarSubscription");
    s.store_field("subscription_id", subscription_id_);
    s.store_class_end();
  }
}

savePreparedKeyboardButton::savePreparedKeyboardButton()
  : user_id_()
  , button_()
{}

savePreparedKeyboardButton::savePreparedKeyboardButton(int53 user_id_, object_ptr<keyboardButton> &&button_)
  : user_id_(user_id_)
  , button_(std::move(button_))
{}

const std::int32_t savePreparedKeyboardButton::ID;

void savePreparedKeyboardButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savePreparedKeyboardButton");
    s.store_field("user_id", user_id_);
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    s.store_class_end();
  }
}

searchChatMessages::searchChatMessages()
  : chat_id_()
  , topic_id_()
  , query_()
  , sender_id_()
  , from_message_id_()
  , offset_()
  , limit_()
  , filter_()
{}

searchChatMessages::searchChatMessages(int53 chat_id_, object_ptr<MessageTopic> &&topic_id_, string const &query_, object_ptr<MessageSender> &&sender_id_, int53 from_message_id_, int32 offset_, int32 limit_, object_ptr<SearchMessagesFilter> &&filter_)
  : chat_id_(chat_id_)
  , topic_id_(std::move(topic_id_))
  , query_(query_)
  , sender_id_(std::move(sender_id_))
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
  , filter_(std::move(filter_))
{}

const std::int32_t searchChatMessages::ID;

void searchChatMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatMessages");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("topic_id", static_cast<const BaseObject *>(topic_id_.get()));
    s.store_field("query", query_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_class_end();
  }
}

searchContacts::searchContacts()
  : query_()
  , limit_()
{}

searchContacts::searchContacts(string const &query_, int32 limit_)
  : query_(query_)
  , limit_(limit_)
{}

const std::int32_t searchContacts::ID;

void searchContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchContacts");
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchPublicStoriesByLocation::searchPublicStoriesByLocation()
  : address_()
  , offset_()
  , limit_()
{}

searchPublicStoriesByLocation::searchPublicStoriesByLocation(object_ptr<locationAddress> &&address_, string const &offset_, int32 limit_)
  : address_(std::move(address_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchPublicStoriesByLocation::ID;

void searchPublicStoriesByLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicStoriesByLocation");
    s.store_object_field("address", static_cast<const BaseObject *>(address_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchPublicStoriesByTag::searchPublicStoriesByTag()
  : story_poster_chat_id_()
  , tag_()
  , offset_()
  , limit_()
{}

searchPublicStoriesByTag::searchPublicStoriesByTag(int53 story_poster_chat_id_, string const &tag_, string const &offset_, int32 limit_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , tag_(tag_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchPublicStoriesByTag::ID;

void searchPublicStoriesByTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPublicStoriesByTag");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("tag", tag_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchQuote::searchQuote()
  : text_()
  , quote_()
  , quote_position_()
{}

searchQuote::searchQuote(object_ptr<formattedText> &&text_, object_ptr<formattedText> &&quote_, int32 quote_position_)
  : text_(std::move(text_))
  , quote_(std::move(quote_))
  , quote_position_(quote_position_)
{}

const std::int32_t searchQuote::ID;

void searchQuote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchQuote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("quote", static_cast<const BaseObject *>(quote_.get()));
    s.store_field("quote_position", quote_position_);
    s.store_class_end();
  }
}

searchSavedMessages::searchSavedMessages()
  : saved_messages_topic_id_()
  , tag_()
  , query_()
  , from_message_id_()
  , offset_()
  , limit_()
{}

searchSavedMessages::searchSavedMessages(int53 saved_messages_topic_id_, object_ptr<ReactionType> &&tag_, string const &query_, int53 from_message_id_, int32 offset_, int32 limit_)
  : saved_messages_topic_id_(saved_messages_topic_id_)
  , tag_(std::move(tag_))
  , query_(query_)
  , from_message_id_(from_message_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t searchSavedMessages::ID;

void searchSavedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchSavedMessages");
    s.store_field("saved_messages_topic_id", saved_messages_topic_id_);
    s.store_object_field("tag", static_cast<const BaseObject *>(tag_.get()));
    s.store_field("query", query_);
    s.store_field("from_message_id", from_message_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

searchStickerSets::searchStickerSets()
  : sticker_type_()
  , query_()
{}

searchStickerSets::searchStickerSets(object_ptr<StickerType> &&sticker_type_, string const &query_)
  : sticker_type_(std::move(sticker_type_))
  , query_(query_)
{}

const std::int32_t searchStickerSets::ID;

void searchStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    s.store_field("query", query_);
    s.store_class_end();
  }
}

sendPaymentForm::sendPaymentForm()
  : input_invoice_()
  , payment_form_id_()
  , order_info_id_()
  , shipping_option_id_()
  , credentials_()
  , tip_amount_()
{}

sendPaymentForm::sendPaymentForm(object_ptr<InputInvoice> &&input_invoice_, int64 payment_form_id_, string const &order_info_id_, string const &shipping_option_id_, object_ptr<InputCredentials> &&credentials_, int53 tip_amount_)
  : input_invoice_(std::move(input_invoice_))
  , payment_form_id_(payment_form_id_)
  , order_info_id_(order_info_id_)
  , shipping_option_id_(shipping_option_id_)
  , credentials_(std::move(credentials_))
  , tip_amount_(tip_amount_)
{}

const std::int32_t sendPaymentForm::ID;

void sendPaymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendPaymentForm");
    s.store_object_field("input_invoice", static_cast<const BaseObject *>(input_invoice_.get()));
    s.store_field("payment_form_id", payment_form_id_);
    s.store_field("order_info_id", order_info_id_);
    s.store_field("shipping_option_id", shipping_option_id_);
    s.store_object_field("credentials", static_cast<const BaseObject *>(credentials_.get()));
    s.store_field("tip_amount", tip_amount_);
    s.store_class_end();
  }
}

sendPhoneNumberFirebaseSms::sendPhoneNumberFirebaseSms()
  : token_()
{}

sendPhoneNumberFirebaseSms::sendPhoneNumberFirebaseSms(string const &token_)
  : token_(token_)
{}

const std::int32_t sendPhoneNumberFirebaseSms::ID;

void sendPhoneNumberFirebaseSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendPhoneNumberFirebaseSms");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

setAlarm::setAlarm()
  : seconds_()
{}

setAlarm::setAlarm(double seconds_)
  : seconds_(seconds_)
{}

const std::int32_t setAlarm::ID;

void setAlarm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAlarm");
    s.store_field("seconds", seconds_);
    s.store_class_end();
  }
}

setAuthenticationPremiumPurchaseTransaction::setAuthenticationPremiumPurchaseTransaction()
  : transaction_()
  , is_restore_()
  , currency_()
  , amount_()
{}

setAuthenticationPremiumPurchaseTransaction::setAuthenticationPremiumPurchaseTransaction(object_ptr<StoreTransaction> &&transaction_, bool is_restore_, string const &currency_, int53 amount_)
  : transaction_(std::move(transaction_))
  , is_restore_(is_restore_)
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t setAuthenticationPremiumPurchaseTransaction::ID;

void setAuthenticationPremiumPurchaseTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAuthenticationPremiumPurchaseTransaction");
    s.store_object_field("transaction", static_cast<const BaseObject *>(transaction_.get()));
    s.store_field("is_restore", is_restore_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

setBusinessAccountName::setBusinessAccountName()
  : business_connection_id_()
  , first_name_()
  , last_name_()
{}

setBusinessAccountName::setBusinessAccountName(string const &business_connection_id_, string const &first_name_, string const &last_name_)
  : business_connection_id_(business_connection_id_)
  , first_name_(first_name_)
  , last_name_(last_name_)
{}

const std::int32_t setBusinessAccountName::ID;

void setBusinessAccountName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessAccountName");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_class_end();
  }
}

setBusinessLocation::setBusinessLocation()
  : location_()
{}

setBusinessLocation::setBusinessLocation(object_ptr<businessLocation> &&location_)
  : location_(std::move(location_))
{}

const std::int32_t setBusinessLocation::ID;

void setBusinessLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_class_end();
  }
}

setChatBackground::setChatBackground()
  : chat_id_()
  , background_()
  , type_()
  , dark_theme_dimming_()
  , only_for_self_()
{}

setChatBackground::setChatBackground(int53 chat_id_, object_ptr<InputBackground> &&background_, object_ptr<BackgroundType> &&type_, int32 dark_theme_dimming_, bool only_for_self_)
  : chat_id_(chat_id_)
  , background_(std::move(background_))
  , type_(std::move(type_))
  , dark_theme_dimming_(dark_theme_dimming_)
  , only_for_self_(only_for_self_)
{}

const std::int32_t setChatBackground::ID;

void setChatBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatBackground");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("background", static_cast<const BaseObject *>(background_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("dark_theme_dimming", dark_theme_dimming_);
    s.store_field("only_for_self", only_for_self_);
    s.store_class_end();
  }
}

setGroupCallPaidMessageStarCount::setGroupCallPaidMessageStarCount()
  : group_call_id_()
  , paid_message_star_count_()
{}

setGroupCallPaidMessageStarCount::setGroupCallPaidMessageStarCount(int32 group_call_id_, int53 paid_message_star_count_)
  : group_call_id_(group_call_id_)
  , paid_message_star_count_(paid_message_star_count_)
{}

const std::int32_t setGroupCallPaidMessageStarCount::ID;

void setGroupCallPaidMessageStarCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGroupCallPaidMessageStarCount");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("paid_message_star_count", paid_message_star_count_);
    s.store_class_end();
  }
}

setLogStream::setLogStream()
  : log_stream_()
{}

setLogStream::setLogStream(object_ptr<LogStream> &&log_stream_)
  : log_stream_(std::move(log_stream_))
{}

const std::int32_t setLogStream::ID;

void setLogStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLogStream");
    s.store_object_field("log_stream", static_cast<const BaseObject *>(log_stream_.get()));
    s.store_class_end();
  }
}

setLoginEmailAddress::setLoginEmailAddress()
  : new_login_email_address_()
{}

setLoginEmailAddress::setLoginEmailAddress(string const &new_login_email_address_)
  : new_login_email_address_(new_login_email_address_)
{}

const std::int32_t setLoginEmailAddress::ID;

void setLoginEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setLoginEmailAddress");
    s.store_field("new_login_email_address", new_login_email_address_);
    s.store_class_end();
  }
}

setPinnedChats::setPinnedChats()
  : chat_list_()
  , chat_ids_()
{}

setPinnedChats::setPinnedChats(object_ptr<ChatList> &&chat_list_, array<int53> &&chat_ids_)
  : chat_list_(std::move(chat_list_))
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t setPinnedChats::ID;

void setPinnedChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPinnedChats");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setPinnedSavedMessagesTopics::setPinnedSavedMessagesTopics()
  : saved_messages_topic_ids_()
{}

setPinnedSavedMessagesTopics::setPinnedSavedMessagesTopics(array<int53> &&saved_messages_topic_ids_)
  : saved_messages_topic_ids_(std::move(saved_messages_topic_ids_))
{}

const std::int32_t setPinnedSavedMessagesTopics::ID;

void setPinnedSavedMessagesTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPinnedSavedMessagesTopics");
    { s.store_vector_begin("saved_messages_topic_ids", saved_messages_topic_ids_.size()); for (const auto &_value : saved_messages_topic_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setQuickReplyShortcutName::setQuickReplyShortcutName()
  : shortcut_id_()
  , name_()
{}

setQuickReplyShortcutName::setQuickReplyShortcutName(int32 shortcut_id_, string const &name_)
  : shortcut_id_(shortcut_id_)
  , name_(name_)
{}

const std::int32_t setQuickReplyShortcutName::ID;

void setQuickReplyShortcutName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setQuickReplyShortcutName");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

setSavedMessagesTagLabel::setSavedMessagesTagLabel()
  : tag_()
  , label_()
{}

setSavedMessagesTagLabel::setSavedMessagesTagLabel(object_ptr<ReactionType> &&tag_, string const &label_)
  : tag_(std::move(tag_))
  , label_(label_)
{}

const std::int32_t setSavedMessagesTagLabel::ID;

void setSavedMessagesTagLabel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setSavedMessagesTagLabel");
    s.store_object_field("tag", static_cast<const BaseObject *>(tag_.get()));
    s.store_field("label", label_);
    s.store_class_end();
  }
}

setUserEmojiStatus::setUserEmojiStatus()
  : user_id_()
  , emoji_status_()
{}

setUserEmojiStatus::setUserEmojiStatus(int53 user_id_, object_ptr<emojiStatus> &&emoji_status_)
  : user_id_(user_id_)
  , emoji_status_(std::move(emoji_status_))
{}

const std::int32_t setUserEmojiStatus::ID;

void setUserEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUserEmojiStatus");
    s.store_field("user_id", user_id_);
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

sharePhoneNumber::sharePhoneNumber()
  : user_id_()
{}

sharePhoneNumber::sharePhoneNumber(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t sharePhoneNumber::ID;

void sharePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sharePhoneNumber");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

terminateAllOtherSessions::terminateAllOtherSessions() {
}

const std::int32_t terminateAllOtherSessions::ID;

void terminateAllOtherSessions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "terminateAllOtherSessions");
    s.store_class_end();
  }
}

toggleChatDefaultDisableNotification::toggleChatDefaultDisableNotification()
  : chat_id_()
  , default_disable_notification_()
{}

toggleChatDefaultDisableNotification::toggleChatDefaultDisableNotification(int53 chat_id_, bool default_disable_notification_)
  : chat_id_(chat_id_)
  , default_disable_notification_(default_disable_notification_)
{}

const std::int32_t toggleChatDefaultDisableNotification::ID;

void toggleChatDefaultDisableNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatDefaultDisableNotification");
    s.store_field("chat_id", chat_id_);
    s.store_field("default_disable_notification", default_disable_notification_);
    s.store_class_end();
  }
}

toggleChatGiftNotifications::toggleChatGiftNotifications()
  : chat_id_()
  , are_enabled_()
{}

toggleChatGiftNotifications::toggleChatGiftNotifications(int53 chat_id_, bool are_enabled_)
  : chat_id_(chat_id_)
  , are_enabled_(are_enabled_)
{}

const std::int32_t toggleChatGiftNotifications::ID;

void toggleChatGiftNotifications::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatGiftNotifications");
    s.store_field("chat_id", chat_id_);
    s.store_field("are_enabled", are_enabled_);
    s.store_class_end();
  }
}

toggleGroupCallParticipantIsMuted::toggleGroupCallParticipantIsMuted()
  : group_call_id_()
  , participant_id_()
  , is_muted_()
{}

toggleGroupCallParticipantIsMuted::toggleGroupCallParticipantIsMuted(int32 group_call_id_, object_ptr<MessageSender> &&participant_id_, bool is_muted_)
  : group_call_id_(group_call_id_)
  , participant_id_(std::move(participant_id_))
  , is_muted_(is_muted_)
{}

const std::int32_t toggleGroupCallParticipantIsMuted::ID;

void toggleGroupCallParticipantIsMuted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleGroupCallParticipantIsMuted");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("participant_id", static_cast<const BaseObject *>(participant_id_.get()));
    s.store_field("is_muted", is_muted_);
    s.store_class_end();
  }
}

toggleStoryIsPostedToChatPage::toggleStoryIsPostedToChatPage()
  : story_poster_chat_id_()
  , story_id_()
  , is_posted_to_chat_page_()
{}

toggleStoryIsPostedToChatPage::toggleStoryIsPostedToChatPage(int53 story_poster_chat_id_, int32 story_id_, bool is_posted_to_chat_page_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , is_posted_to_chat_page_(is_posted_to_chat_page_)
{}

const std::int32_t toggleStoryIsPostedToChatPage::ID;

void toggleStoryIsPostedToChatPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleStoryIsPostedToChatPage");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_field("is_posted_to_chat_page", is_posted_to_chat_page_);
    s.store_class_end();
  }
}

uploadStickerFile::uploadStickerFile()
  : user_id_()
  , sticker_format_()
  , sticker_()
{}

uploadStickerFile::uploadStickerFile(int53 user_id_, object_ptr<StickerFormat> &&sticker_format_, object_ptr<InputFile> &&sticker_)
  : user_id_(user_id_)
  , sticker_format_(std::move(sticker_format_))
  , sticker_(std::move(sticker_))
{}

const std::int32_t uploadStickerFile::ID;

void uploadStickerFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "uploadStickerFile");
    s.store_field("user_id", user_id_);
    s.store_object_field("sticker_format", static_cast<const BaseObject *>(sticker_format_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
