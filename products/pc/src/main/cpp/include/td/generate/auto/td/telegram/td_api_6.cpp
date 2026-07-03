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


audios::audios()
  : total_count_()
  , audios_()
{}

audios::audios(int32 total_count_, array<object_ptr<audio>> &&audios_)
  : total_count_(total_count_)
  , audios_(std::move(audios_))
{}

const std::int32_t audios::ID;

void audios::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "audios");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("audios", audios_.size()); for (const auto &_value : audios_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

autoDownloadSettingsPresets::autoDownloadSettingsPresets()
  : low_()
  , medium_()
  , high_()
{}

autoDownloadSettingsPresets::autoDownloadSettingsPresets(object_ptr<autoDownloadSettings> &&low_, object_ptr<autoDownloadSettings> &&medium_, object_ptr<autoDownloadSettings> &&high_)
  : low_(std::move(low_))
  , medium_(std::move(medium_))
  , high_(std::move(high_))
{}

const std::int32_t autoDownloadSettingsPresets::ID;

void autoDownloadSettingsPresets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autoDownloadSettingsPresets");
    s.store_object_field("low", static_cast<const BaseObject *>(low_.get()));
    s.store_object_field("medium", static_cast<const BaseObject *>(medium_.get()));
    s.store_object_field("high", static_cast<const BaseObject *>(high_.get()));
    s.store_class_end();
  }
}

bankCardInfo::bankCardInfo()
  : title_()
  , actions_()
{}

bankCardInfo::bankCardInfo(string const &title_, array<object_ptr<bankCardActionOpenUrl>> &&actions_)
  : title_(title_)
  , actions_(std::move(actions_))
{}

const std::int32_t bankCardInfo::ID;

void bankCardInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bankCardInfo");
    s.store_field("title", title_);
    { s.store_vector_begin("actions", actions_.size()); for (const auto &_value : actions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

botCommand::botCommand()
  : command_()
  , description_()
{}

botCommand::botCommand(string const &command_, string const &description_)
  : command_(command_)
  , description_(description_)
{}

const std::int32_t botCommand::ID;

void botCommand::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommand");
    s.store_field("command", command_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

builtInThemeClassic::builtInThemeClassic() {
}

const std::int32_t builtInThemeClassic::ID;

void builtInThemeClassic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "builtInThemeClassic");
    s.store_class_end();
  }
}

builtInThemeDay::builtInThemeDay() {
}

const std::int32_t builtInThemeDay::ID;

void builtInThemeDay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "builtInThemeDay");
    s.store_class_end();
  }
}

builtInThemeNight::builtInThemeNight() {
}

const std::int32_t builtInThemeNight::ID;

void builtInThemeNight::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "builtInThemeNight");
    s.store_class_end();
  }
}

builtInThemeTinted::builtInThemeTinted() {
}

const std::int32_t builtInThemeTinted::ID;

void builtInThemeTinted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "builtInThemeTinted");
    s.store_class_end();
  }
}

builtInThemeArctic::builtInThemeArctic() {
}

const std::int32_t builtInThemeArctic::ID;

void builtInThemeArctic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "builtInThemeArctic");
    s.store_class_end();
  }
}

callDiscardReasonEmpty::callDiscardReasonEmpty() {
}

const std::int32_t callDiscardReasonEmpty::ID;

void callDiscardReasonEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonEmpty");
    s.store_class_end();
  }
}

callDiscardReasonMissed::callDiscardReasonMissed() {
}

const std::int32_t callDiscardReasonMissed::ID;

void callDiscardReasonMissed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonMissed");
    s.store_class_end();
  }
}

callDiscardReasonDeclined::callDiscardReasonDeclined() {
}

const std::int32_t callDiscardReasonDeclined::ID;

void callDiscardReasonDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonDeclined");
    s.store_class_end();
  }
}

callDiscardReasonDisconnected::callDiscardReasonDisconnected() {
}

const std::int32_t callDiscardReasonDisconnected::ID;

void callDiscardReasonDisconnected::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonDisconnected");
    s.store_class_end();
  }
}

callDiscardReasonHungUp::callDiscardReasonHungUp() {
}

const std::int32_t callDiscardReasonHungUp::ID;

void callDiscardReasonHungUp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonHungUp");
    s.store_class_end();
  }
}

callDiscardReasonUpgradeToGroupCall::callDiscardReasonUpgradeToGroupCall()
  : invite_link_()
{}

callDiscardReasonUpgradeToGroupCall::callDiscardReasonUpgradeToGroupCall(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t callDiscardReasonUpgradeToGroupCall::ID;

void callDiscardReasonUpgradeToGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callDiscardReasonUpgradeToGroupCall");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

callServerTypeTelegramReflector::callServerTypeTelegramReflector()
  : peer_tag_()
  , is_tcp_()
{}

callServerTypeTelegramReflector::callServerTypeTelegramReflector(bytes const &peer_tag_, bool is_tcp_)
  : peer_tag_(std::move(peer_tag_))
  , is_tcp_(is_tcp_)
{}

const std::int32_t callServerTypeTelegramReflector::ID;

void callServerTypeTelegramReflector::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callServerTypeTelegramReflector");
    s.store_bytes_field("peer_tag", peer_tag_);
    s.store_field("is_tcp", is_tcp_);
    s.store_class_end();
  }
}

callServerTypeWebrtc::callServerTypeWebrtc()
  : username_()
  , password_()
  , supports_turn_()
  , supports_stun_()
{}

callServerTypeWebrtc::callServerTypeWebrtc(string const &username_, string const &password_, bool supports_turn_, bool supports_stun_)
  : username_(username_)
  , password_(password_)
  , supports_turn_(supports_turn_)
  , supports_stun_(supports_stun_)
{}

const std::int32_t callServerTypeWebrtc::ID;

void callServerTypeWebrtc::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "callServerTypeWebrtc");
    s.store_field("username", username_);
    s.store_field("password", password_);
    s.store_field("supports_turn", supports_turn_);
    s.store_field("supports_stun", supports_stun_);
    s.store_class_end();
  }
}

chatBoostLevelFeatures::chatBoostLevelFeatures()
  : level_()
  , story_per_day_count_()
  , custom_emoji_reaction_count_()
  , title_color_count_()
  , profile_accent_color_count_()
  , can_set_profile_background_custom_emoji_()
  , accent_color_count_()
  , can_set_background_custom_emoji_()
  , can_set_emoji_status_()
  , chat_theme_background_count_()
  , can_set_custom_background_()
  , can_set_custom_emoji_sticker_set_()
  , can_enable_automatic_translation_()
  , can_recognize_speech_()
  , can_disable_sponsored_messages_()
{}

chatBoostLevelFeatures::chatBoostLevelFeatures(int32 level_, int32 story_per_day_count_, int32 custom_emoji_reaction_count_, int32 title_color_count_, int32 profile_accent_color_count_, bool can_set_profile_background_custom_emoji_, int32 accent_color_count_, bool can_set_background_custom_emoji_, bool can_set_emoji_status_, int32 chat_theme_background_count_, bool can_set_custom_background_, bool can_set_custom_emoji_sticker_set_, bool can_enable_automatic_translation_, bool can_recognize_speech_, bool can_disable_sponsored_messages_)
  : level_(level_)
  , story_per_day_count_(story_per_day_count_)
  , custom_emoji_reaction_count_(custom_emoji_reaction_count_)
  , title_color_count_(title_color_count_)
  , profile_accent_color_count_(profile_accent_color_count_)
  , can_set_profile_background_custom_emoji_(can_set_profile_background_custom_emoji_)
  , accent_color_count_(accent_color_count_)
  , can_set_background_custom_emoji_(can_set_background_custom_emoji_)
  , can_set_emoji_status_(can_set_emoji_status_)
  , chat_theme_background_count_(chat_theme_background_count_)
  , can_set_custom_background_(can_set_custom_background_)
  , can_set_custom_emoji_sticker_set_(can_set_custom_emoji_sticker_set_)
  , can_enable_automatic_translation_(can_enable_automatic_translation_)
  , can_recognize_speech_(can_recognize_speech_)
  , can_disable_sponsored_messages_(can_disable_sponsored_messages_)
{}

const std::int32_t chatBoostLevelFeatures::ID;

void chatBoostLevelFeatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostLevelFeatures");
    s.store_field("level", level_);
    s.store_field("story_per_day_count", story_per_day_count_);
    s.store_field("custom_emoji_reaction_count", custom_emoji_reaction_count_);
    s.store_field("title_color_count", title_color_count_);
    s.store_field("profile_accent_color_count", profile_accent_color_count_);
    s.store_field("can_set_profile_background_custom_emoji", can_set_profile_background_custom_emoji_);
    s.store_field("accent_color_count", accent_color_count_);
    s.store_field("can_set_background_custom_emoji", can_set_background_custom_emoji_);
    s.store_field("can_set_emoji_status", can_set_emoji_status_);
    s.store_field("chat_theme_background_count", chat_theme_background_count_);
    s.store_field("can_set_custom_background", can_set_custom_background_);
    s.store_field("can_set_custom_emoji_sticker_set", can_set_custom_emoji_sticker_set_);
    s.store_field("can_enable_automatic_translation", can_enable_automatic_translation_);
    s.store_field("can_recognize_speech", can_recognize_speech_);
    s.store_field("can_disable_sponsored_messages", can_disable_sponsored_messages_);
    s.store_class_end();
  }
}

chatBoostSlot::chatBoostSlot()
  : slot_id_()
  , currently_boosted_chat_id_()
  , start_date_()
  , expiration_date_()
  , cooldown_until_date_()
{}

chatBoostSlot::chatBoostSlot(int32 slot_id_, int53 currently_boosted_chat_id_, int32 start_date_, int32 expiration_date_, int32 cooldown_until_date_)
  : slot_id_(slot_id_)
  , currently_boosted_chat_id_(currently_boosted_chat_id_)
  , start_date_(start_date_)
  , expiration_date_(expiration_date_)
  , cooldown_until_date_(cooldown_until_date_)
{}

const std::int32_t chatBoostSlot::ID;

void chatBoostSlot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBoostSlot");
    s.store_field("slot_id", slot_id_);
    s.store_field("currently_boosted_chat_id", currently_boosted_chat_id_);
    s.store_field("start_date", start_date_);
    s.store_field("expiration_date", expiration_date_);
    s.store_field("cooldown_until_date", cooldown_until_date_);
    s.store_class_end();
  }
}

chatEventLogFilters::chatEventLogFilters()
  : message_edits_()
  , message_deletions_()
  , message_pins_()
  , member_joins_()
  , member_leaves_()
  , member_invites_()
  , member_promotions_()
  , member_restrictions_()
  , member_tag_changes_()
  , info_changes_()
  , setting_changes_()
  , invite_link_changes_()
  , video_chat_changes_()
  , forum_changes_()
  , subscription_extensions_()
{}

chatEventLogFilters::chatEventLogFilters(bool message_edits_, bool message_deletions_, bool message_pins_, bool member_joins_, bool member_leaves_, bool member_invites_, bool member_promotions_, bool member_restrictions_, bool member_tag_changes_, bool info_changes_, bool setting_changes_, bool invite_link_changes_, bool video_chat_changes_, bool forum_changes_, bool subscription_extensions_)
  : message_edits_(message_edits_)
  , message_deletions_(message_deletions_)
  , message_pins_(message_pins_)
  , member_joins_(member_joins_)
  , member_leaves_(member_leaves_)
  , member_invites_(member_invites_)
  , member_promotions_(member_promotions_)
  , member_restrictions_(member_restrictions_)
  , member_tag_changes_(member_tag_changes_)
  , info_changes_(info_changes_)
  , setting_changes_(setting_changes_)
  , invite_link_changes_(invite_link_changes_)
  , video_chat_changes_(video_chat_changes_)
  , forum_changes_(forum_changes_)
  , subscription_extensions_(subscription_extensions_)
{}

const std::int32_t chatEventLogFilters::ID;

void chatEventLogFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEventLogFilters");
    s.store_field("message_edits", message_edits_);
    s.store_field("message_deletions", message_deletions_);
    s.store_field("message_pins", message_pins_);
    s.store_field("member_joins", member_joins_);
    s.store_field("member_leaves", member_leaves_);
    s.store_field("member_invites", member_invites_);
    s.store_field("member_promotions", member_promotions_);
    s.store_field("member_restrictions", member_restrictions_);
    s.store_field("member_tag_changes", member_tag_changes_);
    s.store_field("info_changes", info_changes_);
    s.store_field("setting_changes", setting_changes_);
    s.store_field("invite_link_changes", invite_link_changes_);
    s.store_field("video_chat_changes", video_chat_changes_);
    s.store_field("forum_changes", forum_changes_);
    s.store_field("subscription_extensions", subscription_extensions_);
    s.store_class_end();
  }
}

chatEvents::chatEvents()
  : events_()
{}

chatEvents::chatEvents(array<object_ptr<chatEvent>> &&events_)
  : events_(std::move(events_))
{}

const std::int32_t chatEvents::ID;

void chatEvents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEvents");
    { s.store_vector_begin("events", events_.size()); for (const auto &_value : events_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatFolderInviteLinks::chatFolderInviteLinks()
  : invite_links_()
{}

chatFolderInviteLinks::chatFolderInviteLinks(array<object_ptr<chatFolderInviteLink>> &&invite_links_)
  : invite_links_(std::move(invite_links_))
{}

const std::int32_t chatFolderInviteLinks::ID;

void chatFolderInviteLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFolderInviteLinks");
    { s.store_vector_begin("invite_links", invite_links_.size()); for (const auto &_value : invite_links_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatInviteLinkInfo::chatInviteLinkInfo()
  : chat_id_()
  , accessible_for_()
  , type_()
  , title_()
  , photo_()
  , accent_color_id_()
  , description_()
  , member_count_()
  , member_user_ids_()
  , subscription_info_()
  , creates_join_request_()
  , is_public_()
  , verification_status_()
{}

chatInviteLinkInfo::chatInviteLinkInfo(int53 chat_id_, int32 accessible_for_, object_ptr<InviteLinkChatType> &&type_, string const &title_, object_ptr<chatPhotoInfo> &&photo_, int32 accent_color_id_, string const &description_, int32 member_count_, array<int53> &&member_user_ids_, object_ptr<chatInviteLinkSubscriptionInfo> &&subscription_info_, bool creates_join_request_, bool is_public_, object_ptr<verificationStatus> &&verification_status_)
  : chat_id_(chat_id_)
  , accessible_for_(accessible_for_)
  , type_(std::move(type_))
  , title_(title_)
  , photo_(std::move(photo_))
  , accent_color_id_(accent_color_id_)
  , description_(description_)
  , member_count_(member_count_)
  , member_user_ids_(std::move(member_user_ids_))
  , subscription_info_(std::move(subscription_info_))
  , creates_join_request_(creates_join_request_)
  , is_public_(is_public_)
  , verification_status_(std::move(verification_status_))
{}

const std::int32_t chatInviteLinkInfo::ID;

void chatInviteLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("accessible_for", accessible_for_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("description", description_);
    s.store_field("member_count", member_count_);
    { s.store_vector_begin("member_user_ids", member_user_ids_.size()); for (const auto &_value : member_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("subscription_info", static_cast<const BaseObject *>(subscription_info_.get()));
    s.store_field("creates_join_request", creates_join_request_);
    s.store_field("is_public", is_public_);
    s.store_object_field("verification_status", static_cast<const BaseObject *>(verification_status_.get()));
    s.store_class_end();
  }
}

chatInviteLinkSubscriptionInfo::chatInviteLinkSubscriptionInfo()
  : pricing_()
  , can_reuse_()
  , form_id_()
{}

chatInviteLinkSubscriptionInfo::chatInviteLinkSubscriptionInfo(object_ptr<starSubscriptionPricing> &&pricing_, bool can_reuse_, int64 form_id_)
  : pricing_(std::move(pricing_))
  , can_reuse_(can_reuse_)
  , form_id_(form_id_)
{}

const std::int32_t chatInviteLinkSubscriptionInfo::ID;

void chatInviteLinkSubscriptionInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteLinkSubscriptionInfo");
    s.store_object_field("pricing", static_cast<const BaseObject *>(pricing_.get()));
    s.store_field("can_reuse", can_reuse_);
    s.store_field("form_id", form_id_);
    s.store_class_end();
  }
}

chatJoinRequestsInfo::chatJoinRequestsInfo()
  : total_count_()
  , user_ids_()
{}

chatJoinRequestsInfo::chatJoinRequestsInfo(int32 total_count_, array<int53> &&user_ids_)
  : total_count_(total_count_)
  , user_ids_(std::move(user_ids_))
{}

const std::int32_t chatJoinRequestsInfo::ID;

void chatJoinRequestsInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatJoinRequestsInfo");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatLists::chatLists()
  : chat_lists_()
{}

chatLists::chatLists(array<object_ptr<ChatList>> &&chat_lists_)
  : chat_lists_(std::move(chat_lists_))
{}

const std::int32_t chatLists::ID;

void chatLists::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatLists");
    { s.store_vector_begin("chat_lists", chat_lists_.size()); for (const auto &_value : chat_lists_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatLocation::chatLocation()
  : location_()
  , address_()
{}

chatLocation::chatLocation(object_ptr<location> &&location_, string const &address_)
  : location_(std::move(location_))
  , address_(address_)
{}

const std::int32_t chatLocation::ID;

void chatLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatLocation");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("address", address_);
    s.store_class_end();
  }
}

chatPhotoStickerTypeRegularOrMask::chatPhotoStickerTypeRegularOrMask()
  : sticker_set_id_()
  , sticker_id_()
{}

chatPhotoStickerTypeRegularOrMask::chatPhotoStickerTypeRegularOrMask(int64 sticker_set_id_, int64 sticker_id_)
  : sticker_set_id_(sticker_set_id_)
  , sticker_id_(sticker_id_)
{}

const std::int32_t chatPhotoStickerTypeRegularOrMask::ID;

void chatPhotoStickerTypeRegularOrMask::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotoStickerTypeRegularOrMask");
    s.store_field("sticker_set_id", sticker_set_id_);
    s.store_field("sticker_id", sticker_id_);
    s.store_class_end();
  }
}

chatPhotoStickerTypeCustomEmoji::chatPhotoStickerTypeCustomEmoji()
  : custom_emoji_id_()
{}

chatPhotoStickerTypeCustomEmoji::chatPhotoStickerTypeCustomEmoji(int64 custom_emoji_id_)
  : custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t chatPhotoStickerTypeCustomEmoji::ID;

void chatPhotoStickerTypeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotoStickerTypeCustomEmoji");
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

countries::countries()
  : countries_()
{}

countries::countries(array<object_ptr<countryInfo>> &&countries_)
  : countries_(std::move(countries_))
{}

const std::int32_t countries::ID;

void countries::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "countries");
    { s.store_vector_begin("countries", countries_.size()); for (const auto &_value : countries_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

countryInfo::countryInfo()
  : country_code_()
  , name_()
  , english_name_()
  , is_hidden_()
  , calling_codes_()
{}

countryInfo::countryInfo(string const &country_code_, string const &name_, string const &english_name_, bool is_hidden_, array<string> &&calling_codes_)
  : country_code_(country_code_)
  , name_(name_)
  , english_name_(english_name_)
  , is_hidden_(is_hidden_)
  , calling_codes_(std::move(calling_codes_))
{}

const std::int32_t countryInfo::ID;

void countryInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "countryInfo");
    s.store_field("country_code", country_code_);
    s.store_field("name", name_);
    s.store_field("english_name", english_name_);
    s.store_field("is_hidden", is_hidden_);
    { s.store_vector_begin("calling_codes", calling_codes_.size()); for (const auto &_value : calling_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

deviceTokenFirebaseCloudMessaging::deviceTokenFirebaseCloudMessaging()
  : token_()
  , encrypt_()
{}

deviceTokenFirebaseCloudMessaging::deviceTokenFirebaseCloudMessaging(string const &token_, bool encrypt_)
  : token_(token_)
  , encrypt_(encrypt_)
{}

const std::int32_t deviceTokenFirebaseCloudMessaging::ID;

void deviceTokenFirebaseCloudMessaging::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenFirebaseCloudMessaging");
    s.store_field("token", token_);
    s.store_field("encrypt", encrypt_);
    s.store_class_end();
  }
}

deviceTokenApplePush::deviceTokenApplePush()
  : device_token_()
  , is_app_sandbox_()
{}

deviceTokenApplePush::deviceTokenApplePush(string const &device_token_, bool is_app_sandbox_)
  : device_token_(device_token_)
  , is_app_sandbox_(is_app_sandbox_)
{}

const std::int32_t deviceTokenApplePush::ID;

void deviceTokenApplePush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenApplePush");
    s.store_field("device_token", device_token_);
    s.store_field("is_app_sandbox", is_app_sandbox_);
    s.store_class_end();
  }
}

deviceTokenApplePushVoIP::deviceTokenApplePushVoIP()
  : device_token_()
  , is_app_sandbox_()
  , encrypt_()
{}

deviceTokenApplePushVoIP::deviceTokenApplePushVoIP(string const &device_token_, bool is_app_sandbox_, bool encrypt_)
  : device_token_(device_token_)
  , is_app_sandbox_(is_app_sandbox_)
  , encrypt_(encrypt_)
{}

const std::int32_t deviceTokenApplePushVoIP::ID;

void deviceTokenApplePushVoIP::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenApplePushVoIP");
    s.store_field("device_token", device_token_);
    s.store_field("is_app_sandbox", is_app_sandbox_);
    s.store_field("encrypt", encrypt_);
    s.store_class_end();
  }
}

deviceTokenWindowsPush::deviceTokenWindowsPush()
  : access_token_()
{}

deviceTokenWindowsPush::deviceTokenWindowsPush(string const &access_token_)
  : access_token_(access_token_)
{}

const std::int32_t deviceTokenWindowsPush::ID;

void deviceTokenWindowsPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenWindowsPush");
    s.store_field("access_token", access_token_);
    s.store_class_end();
  }
}

deviceTokenMicrosoftPush::deviceTokenMicrosoftPush()
  : channel_uri_()
{}

deviceTokenMicrosoftPush::deviceTokenMicrosoftPush(string const &channel_uri_)
  : channel_uri_(channel_uri_)
{}

const std::int32_t deviceTokenMicrosoftPush::ID;

void deviceTokenMicrosoftPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenMicrosoftPush");
    s.store_field("channel_uri", channel_uri_);
    s.store_class_end();
  }
}

deviceTokenMicrosoftPushVoIP::deviceTokenMicrosoftPushVoIP()
  : channel_uri_()
{}

deviceTokenMicrosoftPushVoIP::deviceTokenMicrosoftPushVoIP(string const &channel_uri_)
  : channel_uri_(channel_uri_)
{}

const std::int32_t deviceTokenMicrosoftPushVoIP::ID;

void deviceTokenMicrosoftPushVoIP::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenMicrosoftPushVoIP");
    s.store_field("channel_uri", channel_uri_);
    s.store_class_end();
  }
}

deviceTokenWebPush::deviceTokenWebPush()
  : endpoint_()
  , p256dh_base64url_()
  , auth_base64url_()
{}

deviceTokenWebPush::deviceTokenWebPush(string const &endpoint_, string const &p256dh_base64url_, string const &auth_base64url_)
  : endpoint_(endpoint_)
  , p256dh_base64url_(p256dh_base64url_)
  , auth_base64url_(auth_base64url_)
{}

const std::int32_t deviceTokenWebPush::ID;

void deviceTokenWebPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenWebPush");
    s.store_field("endpoint", endpoint_);
    s.store_field("p256dh_base64url", p256dh_base64url_);
    s.store_field("auth_base64url", auth_base64url_);
    s.store_class_end();
  }
}

deviceTokenSimplePush::deviceTokenSimplePush()
  : endpoint_()
{}

deviceTokenSimplePush::deviceTokenSimplePush(string const &endpoint_)
  : endpoint_(endpoint_)
{}

const std::int32_t deviceTokenSimplePush::ID;

void deviceTokenSimplePush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenSimplePush");
    s.store_field("endpoint", endpoint_);
    s.store_class_end();
  }
}

deviceTokenUbuntuPush::deviceTokenUbuntuPush()
  : token_()
{}

deviceTokenUbuntuPush::deviceTokenUbuntuPush(string const &token_)
  : token_(token_)
{}

const std::int32_t deviceTokenUbuntuPush::ID;

void deviceTokenUbuntuPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenUbuntuPush");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

deviceTokenBlackBerryPush::deviceTokenBlackBerryPush()
  : token_()
{}

deviceTokenBlackBerryPush::deviceTokenBlackBerryPush(string const &token_)
  : token_(token_)
{}

const std::int32_t deviceTokenBlackBerryPush::ID;

void deviceTokenBlackBerryPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenBlackBerryPush");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

deviceTokenTizenPush::deviceTokenTizenPush()
  : reg_id_()
{}

deviceTokenTizenPush::deviceTokenTizenPush(string const &reg_id_)
  : reg_id_(reg_id_)
{}

const std::int32_t deviceTokenTizenPush::ID;

void deviceTokenTizenPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenTizenPush");
    s.store_field("reg_id", reg_id_);
    s.store_class_end();
  }
}

deviceTokenHuaweiPush::deviceTokenHuaweiPush()
  : token_()
  , encrypt_()
{}

deviceTokenHuaweiPush::deviceTokenHuaweiPush(string const &token_, bool encrypt_)
  : token_(token_)
  , encrypt_(encrypt_)
{}

const std::int32_t deviceTokenHuaweiPush::ID;

void deviceTokenHuaweiPush::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deviceTokenHuaweiPush");
    s.store_field("token", token_);
    s.store_field("encrypt", encrypt_);
    s.store_class_end();
  }
}

directMessagesChatTopic::directMessagesChatTopic()
  : chat_id_()
  , id_()
  , sender_id_()
  , order_()
  , can_send_unpaid_messages_()
  , is_marked_as_unread_()
  , unread_count_()
  , last_read_inbox_message_id_()
  , last_read_outbox_message_id_()
  , unread_reaction_count_()
  , last_message_()
  , draft_message_()
{}

directMessagesChatTopic::directMessagesChatTopic(int53 chat_id_, int53 id_, object_ptr<MessageSender> &&sender_id_, int64 order_, bool can_send_unpaid_messages_, bool is_marked_as_unread_, int53 unread_count_, int53 last_read_inbox_message_id_, int53 last_read_outbox_message_id_, int53 unread_reaction_count_, object_ptr<message> &&last_message_, object_ptr<draftMessage> &&draft_message_)
  : chat_id_(chat_id_)
  , id_(id_)
  , sender_id_(std::move(sender_id_))
  , order_(order_)
  , can_send_unpaid_messages_(can_send_unpaid_messages_)
  , is_marked_as_unread_(is_marked_as_unread_)
  , unread_count_(unread_count_)
  , last_read_inbox_message_id_(last_read_inbox_message_id_)
  , last_read_outbox_message_id_(last_read_outbox_message_id_)
  , unread_reaction_count_(unread_reaction_count_)
  , last_message_(std::move(last_message_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t directMessagesChatTopic::ID;

void directMessagesChatTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "directMessagesChatTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("id", id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("order", order_);
    s.store_field("can_send_unpaid_messages", can_send_unpaid_messages_);
    s.store_field("is_marked_as_unread", is_marked_as_unread_);
    s.store_field("unread_count", unread_count_);
    s.store_field("last_read_inbox_message_id", last_read_inbox_message_id_);
    s.store_field("last_read_outbox_message_id", last_read_outbox_message_id_);
    s.store_field("unread_reaction_count", unread_reaction_count_);
    s.store_object_field("last_message", static_cast<const BaseObject *>(last_message_.get()));
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

draftMessage::draftMessage()
  : reply_to_()
  , date_()
  , input_message_text_()
  , effect_id_()
  , suggested_post_info_()
{}

draftMessage::draftMessage(object_ptr<InputMessageReplyTo> &&reply_to_, int32 date_, object_ptr<InputMessageContent> &&input_message_text_, int64 effect_id_, object_ptr<inputSuggestedPostInfo> &&suggested_post_info_)
  : reply_to_(std::move(reply_to_))
  , date_(date_)
  , input_message_text_(std::move(input_message_text_))
  , effect_id_(effect_id_)
  , suggested_post_info_(std::move(suggested_post_info_))
{}

const std::int32_t draftMessage::ID;

void draftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "draftMessage");
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_field("date", date_);
    s.store_object_field("input_message_text", static_cast<const BaseObject *>(input_message_text_.get()));
    s.store_field("effect_id", effect_id_);
    s.store_object_field("suggested_post_info", static_cast<const BaseObject *>(suggested_post_info_.get()));
    s.store_class_end();
  }
}

emailAddressAuthenticationCodeInfo::emailAddressAuthenticationCodeInfo()
  : email_address_pattern_()
  , length_()
{}

emailAddressAuthenticationCodeInfo::emailAddressAuthenticationCodeInfo(string const &email_address_pattern_, int32 length_)
  : email_address_pattern_(email_address_pattern_)
  , length_(length_)
{}

const std::int32_t emailAddressAuthenticationCodeInfo::ID;

void emailAddressAuthenticationCodeInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressAuthenticationCodeInfo");
    s.store_field("email_address_pattern", email_address_pattern_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

emailAddressResetStateAvailable::emailAddressResetStateAvailable()
  : wait_period_()
{}

emailAddressResetStateAvailable::emailAddressResetStateAvailable(int32 wait_period_)
  : wait_period_(wait_period_)
{}

const std::int32_t emailAddressResetStateAvailable::ID;

void emailAddressResetStateAvailable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressResetStateAvailable");
    s.store_field("wait_period", wait_period_);
    s.store_class_end();
  }
}

emailAddressResetStatePending::emailAddressResetStatePending()
  : reset_in_()
{}

emailAddressResetStatePending::emailAddressResetStatePending(int32 reset_in_)
  : reset_in_(reset_in_)
{}

const std::int32_t emailAddressResetStatePending::ID;

void emailAddressResetStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailAddressResetStatePending");
    s.store_field("reset_in", reset_in_);
    s.store_class_end();
  }
}

emojiCategories::emojiCategories()
  : categories_()
{}

emojiCategories::emojiCategories(array<object_ptr<emojiCategory>> &&categories_)
  : categories_(std::move(categories_))
{}

const std::int32_t emojiCategories::ID;

void emojiCategories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiCategories");
    { s.store_vector_begin("categories", categories_.size()); for (const auto &_value : categories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

encryptedPassportElement::encryptedPassportElement()
  : type_()
  , data_()
  , front_side_()
  , reverse_side_()
  , selfie_()
  , translation_()
  , files_()
  , value_()
  , hash_()
{}

encryptedPassportElement::encryptedPassportElement(object_ptr<PassportElementType> &&type_, bytes const &data_, object_ptr<datedFile> &&front_side_, object_ptr<datedFile> &&reverse_side_, object_ptr<datedFile> &&selfie_, array<object_ptr<datedFile>> &&translation_, array<object_ptr<datedFile>> &&files_, string const &value_, string const &hash_)
  : type_(std::move(type_))
  , data_(std::move(data_))
  , front_side_(std::move(front_side_))
  , reverse_side_(std::move(reverse_side_))
  , selfie_(std::move(selfie_))
  , translation_(std::move(translation_))
  , files_(std::move(files_))
  , value_(value_)
  , hash_(hash_)
{}

const std::int32_t encryptedPassportElement::ID;

void encryptedPassportElement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedPassportElement");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("data", data_);
    s.store_object_field("front_side", static_cast<const BaseObject *>(front_side_.get()));
    s.store_object_field("reverse_side", static_cast<const BaseObject *>(reverse_side_.get()));
    s.store_object_field("selfie", static_cast<const BaseObject *>(selfie_.get()));
    { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("value", value_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

forumTopicIcon::forumTopicIcon()
  : color_()
  , custom_emoji_id_()
{}

forumTopicIcon::forumTopicIcon(int32 color_, int64 custom_emoji_id_)
  : color_(color_)
  , custom_emoji_id_(custom_emoji_id_)
{}

const std::int32_t forumTopicIcon::ID;

void forumTopicIcon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forumTopicIcon");
    s.store_field("color", color_);
    s.store_field("custom_emoji_id", custom_emoji_id_);
    s.store_class_end();
  }
}

foundFileDownloads::foundFileDownloads()
  : total_counts_()
  , files_()
  , next_offset_()
{}

foundFileDownloads::foundFileDownloads(object_ptr<downloadedFileCounts> &&total_counts_, array<object_ptr<fileDownload>> &&files_, string const &next_offset_)
  : total_counts_(std::move(total_counts_))
  , files_(std::move(files_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundFileDownloads::ID;

void foundFileDownloads::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundFileDownloads");
    s.store_object_field("total_counts", static_cast<const BaseObject *>(total_counts_.get()));
    { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

foundUsers::foundUsers()
  : user_ids_()
  , next_offset_()
{}

foundUsers::foundUsers(array<int53> &&user_ids_, string const &next_offset_)
  : user_ids_(std::move(user_ids_))
  , next_offset_(next_offset_)
{}

const std::int32_t foundUsers::ID;

void foundUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundUsers");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

giftCollection::giftCollection()
  : id_()
  , name_()
  , icon_()
  , gift_count_()
{}

giftCollection::giftCollection(int32 id_, string const &name_, object_ptr<sticker> &&icon_, int32 gift_count_)
  : id_(id_)
  , name_(name_)
  , icon_(std::move(icon_))
  , gift_count_(gift_count_)
{}

const std::int32_t giftCollection::ID;

void giftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "giftCollection");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_field("gift_count", gift_count_);
    s.store_class_end();
  }
}

groupCallMessageLevel::groupCallMessageLevel()
  : min_star_count_()
  , pin_duration_()
  , max_text_length_()
  , max_custom_emoji_count_()
  , first_color_()
  , second_color_()
  , background_color_()
{}

groupCallMessageLevel::groupCallMessageLevel(int53 min_star_count_, int32 pin_duration_, int32 max_text_length_, int32 max_custom_emoji_count_, int32 first_color_, int32 second_color_, int32 background_color_)
  : min_star_count_(min_star_count_)
  , pin_duration_(pin_duration_)
  , max_text_length_(max_text_length_)
  , max_custom_emoji_count_(max_custom_emoji_count_)
  , first_color_(first_color_)
  , second_color_(second_color_)
  , background_color_(background_color_)
{}

const std::int32_t groupCallMessageLevel::ID;

void groupCallMessageLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallMessageLevel");
    s.store_field("min_star_count", min_star_count_);
    s.store_field("pin_duration", pin_duration_);
    s.store_field("max_text_length", max_text_length_);
    s.store_field("max_custom_emoji_count", max_custom_emoji_count_);
    s.store_field("first_color", first_color_);
    s.store_field("second_color", second_color_);
    s.store_field("background_color", background_color_);
    s.store_class_end();
  }
}

groupCallStream::groupCallStream()
  : channel_id_()
  , scale_()
  , time_offset_()
{}

groupCallStream::groupCallStream(int32 channel_id_, int32 scale_, int53 time_offset_)
  : channel_id_(channel_id_)
  , scale_(scale_)
  , time_offset_(time_offset_)
{}

const std::int32_t groupCallStream::ID;

void groupCallStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallStream");
    s.store_field("channel_id", channel_id_);
    s.store_field("scale", scale_);
    s.store_field("time_offset", time_offset_);
    s.store_class_end();
  }
}

inlineQueryResults::inlineQueryResults()
  : inline_query_id_()
  , button_()
  , results_()
  , next_offset_()
{}

inlineQueryResults::inlineQueryResults(int64 inline_query_id_, object_ptr<inlineQueryResultsButton> &&button_, array<object_ptr<InlineQueryResult>> &&results_, string const &next_offset_)
  : inline_query_id_(inline_query_id_)
  , button_(std::move(button_))
  , results_(std::move(results_))
  , next_offset_(next_offset_)
{}

const std::int32_t inlineQueryResults::ID;

void inlineQueryResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryResults");
    s.store_field("inline_query_id", inline_query_id_);
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

inputChatThemeEmoji::inputChatThemeEmoji()
  : name_()
{}

inputChatThemeEmoji::inputChatThemeEmoji(string const &name_)
  : name_(name_)
{}

const std::int32_t inputChatThemeEmoji::ID;

void inputChatThemeEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatThemeEmoji");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

inputChatThemeGift::inputChatThemeGift()
  : name_()
{}

inputChatThemeGift::inputChatThemeGift(string const &name_)
  : name_(name_)
{}

const std::int32_t inputChatThemeGift::ID;

void inputChatThemeGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatThemeGift");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

inputChecklist::inputChecklist()
  : title_()
  , tasks_()
  , others_can_add_tasks_()
  , others_can_mark_tasks_as_done_()
{}

inputChecklist::inputChecklist(object_ptr<formattedText> &&title_, array<object_ptr<inputChecklistTask>> &&tasks_, bool others_can_add_tasks_, bool others_can_mark_tasks_as_done_)
  : title_(std::move(title_))
  , tasks_(std::move(tasks_))
  , others_can_add_tasks_(others_can_add_tasks_)
  , others_can_mark_tasks_as_done_(others_can_mark_tasks_as_done_)
{}

const std::int32_t inputChecklist::ID;

void inputChecklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChecklist");
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    { s.store_vector_begin("tasks", tasks_.size()); for (const auto &_value : tasks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("others_can_add_tasks", others_can_add_tasks_);
    s.store_field("others_can_mark_tasks_as_done", others_can_mark_tasks_as_done_);
    s.store_class_end();
  }
}

inputInlineQueryResultAnimation::inputInlineQueryResultAnimation()
  : id_()
  , title_()
  , thumbnail_url_()
  , thumbnail_mime_type_()
  , video_url_()
  , video_mime_type_()
  , video_duration_()
  , video_width_()
  , video_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultAnimation::inputInlineQueryResultAnimation(string const &id_, string const &title_, string const &thumbnail_url_, string const &thumbnail_mime_type_, string const &video_url_, string const &video_mime_type_, int32 video_duration_, int32 video_width_, int32 video_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_mime_type_(thumbnail_mime_type_)
  , video_url_(video_url_)
  , video_mime_type_(video_mime_type_)
  , video_duration_(video_duration_)
  , video_width_(video_width_)
  , video_height_(video_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultAnimation::ID;

void inputInlineQueryResultAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultAnimation");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_mime_type", thumbnail_mime_type_);
    s.store_field("video_url", video_url_);
    s.store_field("video_mime_type", video_mime_type_);
    s.store_field("video_duration", video_duration_);
    s.store_field("video_width", video_width_);
    s.store_field("video_height", video_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultArticle::inputInlineQueryResultArticle()
  : id_()
  , url_()
  , title_()
  , description_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultArticle::inputInlineQueryResultArticle(string const &id_, string const &url_, string const &title_, string const &description_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , url_(url_)
  , title_(title_)
  , description_(description_)
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultArticle::ID;

void inputInlineQueryResultArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultArticle");
    s.store_field("id", id_);
    s.store_field("url", url_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultAudio::inputInlineQueryResultAudio()
  : id_()
  , title_()
  , performer_()
  , audio_url_()
  , audio_duration_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultAudio::inputInlineQueryResultAudio(string const &id_, string const &title_, string const &performer_, string const &audio_url_, int32 audio_duration_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , performer_(performer_)
  , audio_url_(audio_url_)
  , audio_duration_(audio_duration_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultAudio::ID;

void inputInlineQueryResultAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultAudio");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("performer", performer_);
    s.store_field("audio_url", audio_url_);
    s.store_field("audio_duration", audio_duration_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultContact::inputInlineQueryResultContact()
  : id_()
  , contact_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultContact::inputInlineQueryResultContact(string const &id_, object_ptr<contact> &&contact_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , contact_(std::move(contact_))
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultContact::ID;

void inputInlineQueryResultContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultContact");
    s.store_field("id", id_);
    s.store_object_field("contact", static_cast<const BaseObject *>(contact_.get()));
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultDocument::inputInlineQueryResultDocument()
  : id_()
  , title_()
  , description_()
  , document_url_()
  , mime_type_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultDocument::inputInlineQueryResultDocument(string const &id_, string const &title_, string const &description_, string const &document_url_, string const &mime_type_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , description_(description_)
  , document_url_(document_url_)
  , mime_type_(mime_type_)
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultDocument::ID;

void inputInlineQueryResultDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultDocument");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("document_url", document_url_);
    s.store_field("mime_type", mime_type_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultGame::inputInlineQueryResultGame()
  : id_()
  , game_short_name_()
  , reply_markup_()
{}

inputInlineQueryResultGame::inputInlineQueryResultGame(string const &id_, string const &game_short_name_, object_ptr<ReplyMarkup> &&reply_markup_)
  : id_(id_)
  , game_short_name_(game_short_name_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputInlineQueryResultGame::ID;

void inputInlineQueryResultGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultGame");
    s.store_field("id", id_);
    s.store_field("game_short_name", game_short_name_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultLocation::inputInlineQueryResultLocation()
  : id_()
  , location_()
  , live_period_()
  , title_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultLocation::inputInlineQueryResultLocation(string const &id_, object_ptr<location> &&location_, int32 live_period_, string const &title_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , location_(std::move(location_))
  , live_period_(live_period_)
  , title_(title_)
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultLocation::ID;

void inputInlineQueryResultLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultLocation");
    s.store_field("id", id_);
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("live_period", live_period_);
    s.store_field("title", title_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultPhoto::inputInlineQueryResultPhoto()
  : id_()
  , title_()
  , description_()
  , thumbnail_url_()
  , photo_url_()
  , photo_width_()
  , photo_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultPhoto::inputInlineQueryResultPhoto(string const &id_, string const &title_, string const &description_, string const &thumbnail_url_, string const &photo_url_, int32 photo_width_, int32 photo_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , description_(description_)
  , thumbnail_url_(thumbnail_url_)
  , photo_url_(photo_url_)
  , photo_width_(photo_width_)
  , photo_height_(photo_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultPhoto::ID;

void inputInlineQueryResultPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultPhoto");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("photo_url", photo_url_);
    s.store_field("photo_width", photo_width_);
    s.store_field("photo_height", photo_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultSticker::inputInlineQueryResultSticker()
  : id_()
  , thumbnail_url_()
  , sticker_url_()
  , sticker_width_()
  , sticker_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultSticker::inputInlineQueryResultSticker(string const &id_, string const &thumbnail_url_, string const &sticker_url_, int32 sticker_width_, int32 sticker_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , thumbnail_url_(thumbnail_url_)
  , sticker_url_(sticker_url_)
  , sticker_width_(sticker_width_)
  , sticker_height_(sticker_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultSticker::ID;

void inputInlineQueryResultSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultSticker");
    s.store_field("id", id_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("sticker_url", sticker_url_);
    s.store_field("sticker_width", sticker_width_);
    s.store_field("sticker_height", sticker_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultVenue::inputInlineQueryResultVenue()
  : id_()
  , venue_()
  , thumbnail_url_()
  , thumbnail_width_()
  , thumbnail_height_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultVenue::inputInlineQueryResultVenue(string const &id_, object_ptr<venue> &&venue_, string const &thumbnail_url_, int32 thumbnail_width_, int32 thumbnail_height_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , venue_(std::move(venue_))
  , thumbnail_url_(thumbnail_url_)
  , thumbnail_width_(thumbnail_width_)
  , thumbnail_height_(thumbnail_height_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultVenue::ID;

void inputInlineQueryResultVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultVenue");
    s.store_field("id", id_);
    s.store_object_field("venue", static_cast<const BaseObject *>(venue_.get()));
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("thumbnail_width", thumbnail_width_);
    s.store_field("thumbnail_height", thumbnail_height_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultVideo::inputInlineQueryResultVideo()
  : id_()
  , title_()
  , description_()
  , thumbnail_url_()
  , video_url_()
  , mime_type_()
  , video_width_()
  , video_height_()
  , video_duration_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultVideo::inputInlineQueryResultVideo(string const &id_, string const &title_, string const &description_, string const &thumbnail_url_, string const &video_url_, string const &mime_type_, int32 video_width_, int32 video_height_, int32 video_duration_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , description_(description_)
  , thumbnail_url_(thumbnail_url_)
  , video_url_(video_url_)
  , mime_type_(mime_type_)
  , video_width_(video_width_)
  , video_height_(video_height_)
  , video_duration_(video_duration_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultVideo::ID;

void inputInlineQueryResultVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultVideo");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_field("thumbnail_url", thumbnail_url_);
    s.store_field("video_url", video_url_);
    s.store_field("mime_type", mime_type_);
    s.store_field("video_width", video_width_);
    s.store_field("video_height", video_height_);
    s.store_field("video_duration", video_duration_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

inputInlineQueryResultVoiceNote::inputInlineQueryResultVoiceNote()
  : id_()
  , title_()
  , voice_note_url_()
  , voice_note_duration_()
  , reply_markup_()
  , input_message_content_()
{}

inputInlineQueryResultVoiceNote::inputInlineQueryResultVoiceNote(string const &id_, string const &title_, string const &voice_note_url_, int32 voice_note_duration_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : id_(id_)
  , title_(title_)
  , voice_note_url_(voice_note_url_)
  , voice_note_duration_(voice_note_duration_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t inputInlineQueryResultVoiceNote::ID;

void inputInlineQueryResultVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInlineQueryResultVoiceNote");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_field("voice_note_url", voice_note_url_);
    s.store_field("voice_note_duration", voice_note_duration_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

languagePackString::languagePackString()
  : key_()
  , value_()
{}

languagePackString::languagePackString(string const &key_, object_ptr<LanguagePackStringValue> &&value_)
  : key_(key_)
  , value_(std::move(value_))
{}

const std::int32_t languagePackString::ID;

void languagePackString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "languagePackString");
    s.store_field("key", key_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

localizationTargetInfo::localizationTargetInfo()
  : language_packs_()
{}

localizationTargetInfo::localizationTargetInfo(array<object_ptr<languagePackInfo>> &&language_packs_)
  : language_packs_(std::move(language_packs_))
{}

const std::int32_t localizationTargetInfo::ID;

void localizationTargetInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "localizationTargetInfo");
    { s.store_vector_begin("language_packs", language_packs_.size()); for (const auto &_value : language_packs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageFileTypePrivate::messageFileTypePrivate()
  : name_()
{}

messageFileTypePrivate::messageFileTypePrivate(string const &name_)
  : name_(name_)
{}

const std::int32_t messageFileTypePrivate::ID;

void messageFileTypePrivate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageFileTypePrivate");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

messageFileTypeGroup::messageFileTypeGroup()
  : title_()
{}

messageFileTypeGroup::messageFileTypeGroup(string const &title_)
  : title_(title_)
{}

const std::int32_t messageFileTypeGroup::ID;

void messageFileTypeGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageFileTypeGroup");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

messageFileTypeUnknown::messageFileTypeUnknown() {
}

const std::int32_t messageFileTypeUnknown::ID;

void messageFileTypeUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageFileTypeUnknown");
    s.store_class_end();
  }
}

messagePositions::messagePositions()
  : total_count_()
  , positions_()
{}

messagePositions::messagePositions(int32 total_count_, array<object_ptr<messagePosition>> &&positions_)
  : total_count_(total_count_)
  , positions_(std::move(positions_))
{}

const std::int32_t messagePositions::ID;

void messagePositions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePositions");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageSendingStatePending::messageSendingStatePending()
  : sending_id_()
{}

messageSendingStatePending::messageSendingStatePending(int32 sending_id_)
  : sending_id_(sending_id_)
{}

const std::int32_t messageSendingStatePending::ID;

void messageSendingStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSendingStatePending");
    s.store_field("sending_id", sending_id_);
    s.store_class_end();
  }
}

messageSendingStateFailed::messageSendingStateFailed()
  : error_()
  , can_retry_()
  , need_another_sender_()
  , need_another_reply_quote_()
  , need_drop_reply_()
  , required_paid_message_star_count_()
  , retry_after_()
{}

messageSendingStateFailed::messageSendingStateFailed(object_ptr<error> &&error_, bool can_retry_, bool need_another_sender_, bool need_another_reply_quote_, bool need_drop_reply_, int53 required_paid_message_star_count_, double retry_after_)
  : error_(std::move(error_))
  , can_retry_(can_retry_)
  , need_another_sender_(need_another_sender_)
  , need_another_reply_quote_(need_another_reply_quote_)
  , need_drop_reply_(need_drop_reply_)
  , required_paid_message_star_count_(required_paid_message_star_count_)
  , retry_after_(retry_after_)
{}

const std::int32_t messageSendingStateFailed::ID;

void messageSendingStateFailed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageSendingStateFailed");
    s.store_object_field("error", static_cast<const BaseObject *>(error_.get()));
    s.store_field("can_retry", can_retry_);
    s.store_field("need_another_sender", need_another_sender_);
    s.store_field("need_another_reply_quote", need_another_reply_quote_);
    s.store_field("need_drop_reply", need_drop_reply_);
    s.store_field("required_paid_message_star_count", required_paid_message_star_count_);
    s.store_field("retry_after", retry_after_);
    s.store_class_end();
  }
}

messageThreadInfo::messageThreadInfo()
  : chat_id_()
  , message_thread_id_()
  , reply_info_()
  , unread_message_count_()
  , messages_()
  , draft_message_()
{}

messageThreadInfo::messageThreadInfo(int53 chat_id_, int53 message_thread_id_, object_ptr<messageReplyInfo> &&reply_info_, int32 unread_message_count_, array<object_ptr<message>> &&messages_, object_ptr<draftMessage> &&draft_message_)
  : chat_id_(chat_id_)
  , message_thread_id_(message_thread_id_)
  , reply_info_(std::move(reply_info_))
  , unread_message_count_(unread_message_count_)
  , messages_(std::move(messages_))
  , draft_message_(std::move(draft_message_))
{}

const std::int32_t messageThreadInfo::ID;

void messageThreadInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageThreadInfo");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_thread_id", message_thread_id_);
    s.store_object_field("reply_info", static_cast<const BaseObject *>(reply_info_.get()));
    s.store_field("unread_message_count", unread_message_count_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("draft_message", static_cast<const BaseObject *>(draft_message_.get()));
    s.store_class_end();
  }
}

networkStatisticsEntryFile::networkStatisticsEntryFile()
  : file_type_()
  , network_type_()
  , sent_bytes_()
  , received_bytes_()
{}

networkStatisticsEntryFile::networkStatisticsEntryFile(object_ptr<FileType> &&file_type_, object_ptr<NetworkType> &&network_type_, int53 sent_bytes_, int53 received_bytes_)
  : file_type_(std::move(file_type_))
  , network_type_(std::move(network_type_))
  , sent_bytes_(sent_bytes_)
  , received_bytes_(received_bytes_)
{}

const std::int32_t networkStatisticsEntryFile::ID;

void networkStatisticsEntryFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkStatisticsEntryFile");
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_object_field("network_type", static_cast<const BaseObject *>(network_type_.get()));
    s.store_field("sent_bytes", sent_bytes_);
    s.store_field("received_bytes", received_bytes_);
    s.store_class_end();
  }
}

networkStatisticsEntryCall::networkStatisticsEntryCall()
  : network_type_()
  , sent_bytes_()
  , received_bytes_()
  , duration_()
{}

networkStatisticsEntryCall::networkStatisticsEntryCall(object_ptr<NetworkType> &&network_type_, int53 sent_bytes_, int53 received_bytes_, double duration_)
  : network_type_(std::move(network_type_))
  , sent_bytes_(sent_bytes_)
  , received_bytes_(received_bytes_)
  , duration_(duration_)
{}

const std::int32_t networkStatisticsEntryCall::ID;

void networkStatisticsEntryCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "networkStatisticsEntryCall");
    s.store_object_field("network_type", static_cast<const BaseObject *>(network_type_.get()));
    s.store_field("sent_bytes", sent_bytes_);
    s.store_field("received_bytes", received_bytes_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

notificationSound::notificationSound()
  : id_()
  , duration_()
  , date_()
  , title_()
  , data_()
  , sound_()
{}

notificationSound::notificationSound(int64 id_, int32 duration_, int32 date_, string const &title_, string const &data_, object_ptr<file> &&sound_)
  : id_(id_)
  , duration_(duration_)
  , date_(date_)
  , title_(title_)
  , data_(data_)
  , sound_(std::move(sound_))
{}

const std::int32_t notificationSound::ID;

void notificationSound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSound");
    s.store_field("id", id_);
    s.store_field("duration", duration_);
    s.store_field("date", date_);
    s.store_field("title", title_);
    s.store_field("data", data_);
    s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get()));
    s.store_class_end();
  }
}

optionValueBoolean::optionValueBoolean()
  : value_()
{}

optionValueBoolean::optionValueBoolean(bool value_)
  : value_(value_)
{}

const std::int32_t optionValueBoolean::ID;

void optionValueBoolean::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optionValueBoolean");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

optionValueEmpty::optionValueEmpty() {
}

const std::int32_t optionValueEmpty::ID;

void optionValueEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optionValueEmpty");
    s.store_class_end();
  }
}

optionValueInteger::optionValueInteger()
  : value_()
{}

optionValueInteger::optionValueInteger(int64 value_)
  : value_(value_)
{}

const std::int32_t optionValueInteger::ID;

void optionValueInteger::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optionValueInteger");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

optionValueString::optionValueString()
  : value_()
{}

optionValueString::optionValueString(string const &value_)
  : value_(value_)
{}

const std::int32_t optionValueString::ID;

void optionValueString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "optionValueString");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

paidMediaPreview::paidMediaPreview()
  : width_()
  , height_()
  , duration_()
  , minithumbnail_()
{}

paidMediaPreview::paidMediaPreview(int32 width_, int32 height_, int32 duration_, object_ptr<minithumbnail> &&minithumbnail_)
  : width_(width_)
  , height_(height_)
  , duration_(duration_)
  , minithumbnail_(std::move(minithumbnail_))
{}

const std::int32_t paidMediaPreview::ID;

void paidMediaPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidMediaPreview");
    s.store_field("width", width_);
    s.store_field("height", height_);
    s.store_field("duration", duration_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    s.store_class_end();
  }
}

paidMediaPhoto::paidMediaPhoto()
  : photo_()
  , video_()
{}

paidMediaPhoto::paidMediaPhoto(object_ptr<photo> &&photo_, object_ptr<video> &&video_)
  : photo_(std::move(photo_))
  , video_(std::move(video_))
{}

const std::int32_t paidMediaPhoto::ID;

void paidMediaPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidMediaPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_class_end();
  }
}

paidMediaVideo::paidMediaVideo()
  : video_()
  , cover_()
  , start_timestamp_()
{}

paidMediaVideo::paidMediaVideo(object_ptr<video> &&video_, object_ptr<photo> &&cover_, int32 start_timestamp_)
  : video_(std::move(video_))
  , cover_(std::move(cover_))
  , start_timestamp_(start_timestamp_)
{}

const std::int32_t paidMediaVideo::ID;

void paidMediaVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidMediaVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_field("start_timestamp", start_timestamp_);
    s.store_class_end();
  }
}

paidMediaUnsupported::paidMediaUnsupported() {
}

const std::int32_t paidMediaUnsupported::ID;

void paidMediaUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidMediaUnsupported");
    s.store_class_end();
  }
}

passportElementTypePersonalDetails::passportElementTypePersonalDetails() {
}

const std::int32_t passportElementTypePersonalDetails::ID;

void passportElementTypePersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypePersonalDetails");
    s.store_class_end();
  }
}

passportElementTypePassport::passportElementTypePassport() {
}

const std::int32_t passportElementTypePassport::ID;

void passportElementTypePassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypePassport");
    s.store_class_end();
  }
}

passportElementTypeDriverLicense::passportElementTypeDriverLicense() {
}

const std::int32_t passportElementTypeDriverLicense::ID;

void passportElementTypeDriverLicense::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeDriverLicense");
    s.store_class_end();
  }
}

passportElementTypeIdentityCard::passportElementTypeIdentityCard() {
}

const std::int32_t passportElementTypeIdentityCard::ID;

void passportElementTypeIdentityCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeIdentityCard");
    s.store_class_end();
  }
}

passportElementTypeInternalPassport::passportElementTypeInternalPassport() {
}

const std::int32_t passportElementTypeInternalPassport::ID;

void passportElementTypeInternalPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeInternalPassport");
    s.store_class_end();
  }
}

passportElementTypeAddress::passportElementTypeAddress() {
}

const std::int32_t passportElementTypeAddress::ID;

void passportElementTypeAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeAddress");
    s.store_class_end();
  }
}

passportElementTypeUtilityBill::passportElementTypeUtilityBill() {
}

const std::int32_t passportElementTypeUtilityBill::ID;

void passportElementTypeUtilityBill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeUtilityBill");
    s.store_class_end();
  }
}

passportElementTypeBankStatement::passportElementTypeBankStatement() {
}

const std::int32_t passportElementTypeBankStatement::ID;

void passportElementTypeBankStatement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeBankStatement");
    s.store_class_end();
  }
}

passportElementTypeRentalAgreement::passportElementTypeRentalAgreement() {
}

const std::int32_t passportElementTypeRentalAgreement::ID;

void passportElementTypeRentalAgreement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeRentalAgreement");
    s.store_class_end();
  }
}

passportElementTypePassportRegistration::passportElementTypePassportRegistration() {
}

const std::int32_t passportElementTypePassportRegistration::ID;

void passportElementTypePassportRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypePassportRegistration");
    s.store_class_end();
  }
}

passportElementTypeTemporaryRegistration::passportElementTypeTemporaryRegistration() {
}

const std::int32_t passportElementTypeTemporaryRegistration::ID;

void passportElementTypeTemporaryRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeTemporaryRegistration");
    s.store_class_end();
  }
}

passportElementTypePhoneNumber::passportElementTypePhoneNumber() {
}

const std::int32_t passportElementTypePhoneNumber::ID;

void passportElementTypePhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypePhoneNumber");
    s.store_class_end();
  }
}

passportElementTypeEmailAddress::passportElementTypeEmailAddress() {
}

const std::int32_t passportElementTypeEmailAddress::ID;

void passportElementTypeEmailAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passportElementTypeEmailAddress");
    s.store_class_end();
  }
}

photo::photo()
  : has_stickers_()
  , minithumbnail_()
  , sizes_()
{}

photo::photo(bool has_stickers_, object_ptr<minithumbnail> &&minithumbnail_, array<object_ptr<photoSize>> &&sizes_)
  : has_stickers_(has_stickers_)
  , minithumbnail_(std::move(minithumbnail_))
  , sizes_(std::move(sizes_))
{}

const std::int32_t photo::ID;

void photo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photo");
    s.store_field("has_stickers", has_stickers_);
    s.store_object_field("minithumbnail", static_cast<const BaseObject *>(minithumbnail_.get()));
    { s.store_vector_begin("sizes", sizes_.size()); for (const auto &_value : sizes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

photoSize::photoSize()
  : type_()
  , photo_()
  , width_()
  , height_()
  , progressive_sizes_()
{}

photoSize::photoSize(string const &type_, object_ptr<file> &&photo_, int32 width_, int32 height_, array<int32> &&progressive_sizes_)
  : type_(type_)
  , photo_(std::move(photo_))
  , width_(width_)
  , height_(height_)
  , progressive_sizes_(std::move(progressive_sizes_))
{}

const std::int32_t photoSize::ID;

void photoSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoSize");
    s.store_field("type", type_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("width", width_);
    s.store_field("height", height_);
    { s.store_vector_begin("progressive_sizes", progressive_sizes_.size()); for (const auto &_value : progressive_sizes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

poll::poll()
  : id_()
  , question_()
  , options_()
  , total_voter_count_()
  , recent_voter_ids_()
  , can_get_voters_()
  , is_anonymous_()
  , allows_multiple_answers_()
  , allows_revoting_()
  , option_order_()
  , type_()
  , open_period_()
  , close_date_()
  , is_closed_()
{}

poll::poll(int64 id_, object_ptr<formattedText> &&question_, array<object_ptr<pollOption>> &&options_, int32 total_voter_count_, array<object_ptr<MessageSender>> &&recent_voter_ids_, bool can_get_voters_, bool is_anonymous_, bool allows_multiple_answers_, bool allows_revoting_, array<int32> &&option_order_, object_ptr<PollType> &&type_, int32 open_period_, int32 close_date_, bool is_closed_)
  : id_(id_)
  , question_(std::move(question_))
  , options_(std::move(options_))
  , total_voter_count_(total_voter_count_)
  , recent_voter_ids_(std::move(recent_voter_ids_))
  , can_get_voters_(can_get_voters_)
  , is_anonymous_(is_anonymous_)
  , allows_multiple_answers_(allows_multiple_answers_)
  , allows_revoting_(allows_revoting_)
  , option_order_(std::move(option_order_))
  , type_(std::move(type_))
  , open_period_(open_period_)
  , close_date_(close_date_)
  , is_closed_(is_closed_)
{}

const std::int32_t poll::ID;

void poll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "poll");
    s.store_field("id", id_);
    s.store_object_field("question", static_cast<const BaseObject *>(question_.get()));
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("total_voter_count", total_voter_count_);
    { s.store_vector_begin("recent_voter_ids", recent_voter_ids_.size()); for (const auto &_value : recent_voter_ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("can_get_voters", can_get_voters_);
    s.store_field("is_anonymous", is_anonymous_);
    s.store_field("allows_multiple_answers", allows_multiple_answers_);
    s.store_field("allows_revoting", allows_revoting_);
    { s.store_vector_begin("option_order", option_order_.size()); for (const auto &_value : option_order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("open_period", open_period_);
    s.store_field("close_date", close_date_);
    s.store_field("is_closed", is_closed_);
    s.store_class_end();
  }
}

premiumFeatureIncreasedLimits::premiumFeatureIncreasedLimits() {
}

const std::int32_t premiumFeatureIncreasedLimits::ID;

void premiumFeatureIncreasedLimits::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureIncreasedLimits");
    s.store_class_end();
  }
}

premiumFeatureIncreasedUploadFileSize::premiumFeatureIncreasedUploadFileSize() {
}

const std::int32_t premiumFeatureIncreasedUploadFileSize::ID;

void premiumFeatureIncreasedUploadFileSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureIncreasedUploadFileSize");
    s.store_class_end();
  }
}

premiumFeatureImprovedDownloadSpeed::premiumFeatureImprovedDownloadSpeed() {
}

const std::int32_t premiumFeatureImprovedDownloadSpeed::ID;

void premiumFeatureImprovedDownloadSpeed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureImprovedDownloadSpeed");
    s.store_class_end();
  }
}

premiumFeatureVoiceRecognition::premiumFeatureVoiceRecognition() {
}

const std::int32_t premiumFeatureVoiceRecognition::ID;

void premiumFeatureVoiceRecognition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureVoiceRecognition");
    s.store_class_end();
  }
}

premiumFeatureDisabledAds::premiumFeatureDisabledAds() {
}

const std::int32_t premiumFeatureDisabledAds::ID;

void premiumFeatureDisabledAds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureDisabledAds");
    s.store_class_end();
  }
}

premiumFeatureUniqueReactions::premiumFeatureUniqueReactions() {
}

const std::int32_t premiumFeatureUniqueReactions::ID;

void premiumFeatureUniqueReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureUniqueReactions");
    s.store_class_end();
  }
}

premiumFeatureUniqueStickers::premiumFeatureUniqueStickers() {
}

const std::int32_t premiumFeatureUniqueStickers::ID;

void premiumFeatureUniqueStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureUniqueStickers");
    s.store_class_end();
  }
}

premiumFeatureCustomEmoji::premiumFeatureCustomEmoji() {
}

const std::int32_t premiumFeatureCustomEmoji::ID;

void premiumFeatureCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureCustomEmoji");
    s.store_class_end();
  }
}

premiumFeatureAdvancedChatManagement::premiumFeatureAdvancedChatManagement() {
}

const std::int32_t premiumFeatureAdvancedChatManagement::ID;

void premiumFeatureAdvancedChatManagement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureAdvancedChatManagement");
    s.store_class_end();
  }
}

premiumFeatureProfileBadge::premiumFeatureProfileBadge() {
}

const std::int32_t premiumFeatureProfileBadge::ID;

void premiumFeatureProfileBadge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureProfileBadge");
    s.store_class_end();
  }
}

premiumFeatureEmojiStatus::premiumFeatureEmojiStatus() {
}

const std::int32_t premiumFeatureEmojiStatus::ID;

void premiumFeatureEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureEmojiStatus");
    s.store_class_end();
  }
}

premiumFeatureAnimatedProfilePhoto::premiumFeatureAnimatedProfilePhoto() {
}

const std::int32_t premiumFeatureAnimatedProfilePhoto::ID;

void premiumFeatureAnimatedProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureAnimatedProfilePhoto");
    s.store_class_end();
  }
}

premiumFeatureForumTopicIcon::premiumFeatureForumTopicIcon() {
}

const std::int32_t premiumFeatureForumTopicIcon::ID;

void premiumFeatureForumTopicIcon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureForumTopicIcon");
    s.store_class_end();
  }
}

premiumFeatureAppIcons::premiumFeatureAppIcons() {
}

const std::int32_t premiumFeatureAppIcons::ID;

void premiumFeatureAppIcons::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureAppIcons");
    s.store_class_end();
  }
}

premiumFeatureRealTimeChatTranslation::premiumFeatureRealTimeChatTranslation() {
}

const std::int32_t premiumFeatureRealTimeChatTranslation::ID;

void premiumFeatureRealTimeChatTranslation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureRealTimeChatTranslation");
    s.store_class_end();
  }
}

premiumFeatureUpgradedStories::premiumFeatureUpgradedStories() {
}

const std::int32_t premiumFeatureUpgradedStories::ID;

void premiumFeatureUpgradedStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureUpgradedStories");
    s.store_class_end();
  }
}

premiumFeatureChatBoost::premiumFeatureChatBoost() {
}

const std::int32_t premiumFeatureChatBoost::ID;

void premiumFeatureChatBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureChatBoost");
    s.store_class_end();
  }
}

premiumFeatureAccentColor::premiumFeatureAccentColor() {
}

const std::int32_t premiumFeatureAccentColor::ID;

void premiumFeatureAccentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureAccentColor");
    s.store_class_end();
  }
}

premiumFeatureBackgroundForBoth::premiumFeatureBackgroundForBoth() {
}

const std::int32_t premiumFeatureBackgroundForBoth::ID;

void premiumFeatureBackgroundForBoth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureBackgroundForBoth");
    s.store_class_end();
  }
}

premiumFeatureSavedMessagesTags::premiumFeatureSavedMessagesTags() {
}

const std::int32_t premiumFeatureSavedMessagesTags::ID;

void premiumFeatureSavedMessagesTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureSavedMessagesTags");
    s.store_class_end();
  }
}

premiumFeatureMessagePrivacy::premiumFeatureMessagePrivacy() {
}

const std::int32_t premiumFeatureMessagePrivacy::ID;

void premiumFeatureMessagePrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureMessagePrivacy");
    s.store_class_end();
  }
}

premiumFeatureLastSeenTimes::premiumFeatureLastSeenTimes() {
}

const std::int32_t premiumFeatureLastSeenTimes::ID;

void premiumFeatureLastSeenTimes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureLastSeenTimes");
    s.store_class_end();
  }
}

premiumFeatureBusiness::premiumFeatureBusiness() {
}

const std::int32_t premiumFeatureBusiness::ID;

void premiumFeatureBusiness::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureBusiness");
    s.store_class_end();
  }
}

premiumFeatureMessageEffects::premiumFeatureMessageEffects() {
}

const std::int32_t premiumFeatureMessageEffects::ID;

void premiumFeatureMessageEffects::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureMessageEffects");
    s.store_class_end();
  }
}

premiumFeatureChecklists::premiumFeatureChecklists() {
}

const std::int32_t premiumFeatureChecklists::ID;

void premiumFeatureChecklists::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureChecklists");
    s.store_class_end();
  }
}

premiumFeaturePaidMessages::premiumFeaturePaidMessages() {
}

const std::int32_t premiumFeaturePaidMessages::ID;

void premiumFeaturePaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeaturePaidMessages");
    s.store_class_end();
  }
}

premiumFeatureProtectPrivateChatContent::premiumFeatureProtectPrivateChatContent() {
}

const std::int32_t premiumFeatureProtectPrivateChatContent::ID;

void premiumFeatureProtectPrivateChatContent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureProtectPrivateChatContent");
    s.store_class_end();
  }
}

premiumFeatureTextComposition::premiumFeatureTextComposition() {
}

const std::int32_t premiumFeatureTextComposition::ID;

void premiumFeatureTextComposition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumFeatureTextComposition");
    s.store_class_end();
  }
}

prepaidGiveaway::prepaidGiveaway()
  : id_()
  , winner_count_()
  , prize_()
  , boost_count_()
  , payment_date_()
{}

prepaidGiveaway::prepaidGiveaway(int64 id_, int32 winner_count_, object_ptr<GiveawayPrize> &&prize_, int32 boost_count_, int32 payment_date_)
  : id_(id_)
  , winner_count_(winner_count_)
  , prize_(std::move(prize_))
  , boost_count_(boost_count_)
  , payment_date_(payment_date_)
{}

const std::int32_t prepaidGiveaway::ID;

void prepaidGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "prepaidGiveaway");
    s.store_field("id", id_);
    s.store_field("winner_count", winner_count_);
    s.store_object_field("prize", static_cast<const BaseObject *>(prize_.get()));
    s.store_field("boost_count", boost_count_);
    s.store_field("payment_date", payment_date_);
    s.store_class_end();
  }
}

profileAccentColor::profileAccentColor()
  : id_()
  , light_theme_colors_()
  , dark_theme_colors_()
  , min_supergroup_chat_boost_level_()
  , min_channel_chat_boost_level_()
{}

profileAccentColor::profileAccentColor(int32 id_, object_ptr<profileAccentColors> &&light_theme_colors_, object_ptr<profileAccentColors> &&dark_theme_colors_, int32 min_supergroup_chat_boost_level_, int32 min_channel_chat_boost_level_)
  : id_(id_)
  , light_theme_colors_(std::move(light_theme_colors_))
  , dark_theme_colors_(std::move(dark_theme_colors_))
  , min_supergroup_chat_boost_level_(min_supergroup_chat_boost_level_)
  , min_channel_chat_boost_level_(min_channel_chat_boost_level_)
{}

const std::int32_t profileAccentColor::ID;

void profileAccentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileAccentColor");
    s.store_field("id", id_);
    s.store_object_field("light_theme_colors", static_cast<const BaseObject *>(light_theme_colors_.get()));
    s.store_object_field("dark_theme_colors", static_cast<const BaseObject *>(dark_theme_colors_.get()));
    s.store_field("min_supergroup_chat_boost_level", min_supergroup_chat_boost_level_);
    s.store_field("min_channel_chat_boost_level", min_channel_chat_boost_level_);
    s.store_class_end();
  }
}

pushMessageContentHidden::pushMessageContentHidden()
  : is_pinned_()
{}

pushMessageContentHidden::pushMessageContentHidden(bool is_pinned_)
  : is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentHidden::ID;

void pushMessageContentHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentHidden");
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentAnimation::pushMessageContentAnimation()
  : animation_()
  , caption_()
  , is_pinned_()
{}

pushMessageContentAnimation::pushMessageContentAnimation(object_ptr<animation> &&animation_, string const &caption_, bool is_pinned_)
  : animation_(std::move(animation_))
  , caption_(caption_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentAnimation::ID;

void pushMessageContentAnimation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentAnimation");
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_field("caption", caption_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentAudio::pushMessageContentAudio()
  : audio_()
  , is_pinned_()
{}

pushMessageContentAudio::pushMessageContentAudio(object_ptr<audio> &&audio_, bool is_pinned_)
  : audio_(std::move(audio_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentAudio::ID;

void pushMessageContentAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentAudio");
    s.store_object_field("audio", static_cast<const BaseObject *>(audio_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentContact::pushMessageContentContact()
  : name_()
  , is_pinned_()
{}

pushMessageContentContact::pushMessageContentContact(string const &name_, bool is_pinned_)
  : name_(name_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentContact::ID;

void pushMessageContentContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentContact");
    s.store_field("name", name_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentContactRegistered::pushMessageContentContactRegistered()
  : as_premium_account_()
{}

pushMessageContentContactRegistered::pushMessageContentContactRegistered(bool as_premium_account_)
  : as_premium_account_(as_premium_account_)
{}

const std::int32_t pushMessageContentContactRegistered::ID;

void pushMessageContentContactRegistered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentContactRegistered");
    s.store_field("as_premium_account", as_premium_account_);
    s.store_class_end();
  }
}

pushMessageContentDocument::pushMessageContentDocument()
  : document_()
  , is_pinned_()
{}

pushMessageContentDocument::pushMessageContentDocument(object_ptr<document> &&document_, bool is_pinned_)
  : document_(std::move(document_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentDocument::ID;

void pushMessageContentDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentDocument");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentGame::pushMessageContentGame()
  : title_()
  , is_pinned_()
{}

pushMessageContentGame::pushMessageContentGame(string const &title_, bool is_pinned_)
  : title_(title_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentGame::ID;

void pushMessageContentGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentGame");
    s.store_field("title", title_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentGameScore::pushMessageContentGameScore()
  : title_()
  , score_()
  , is_pinned_()
{}

pushMessageContentGameScore::pushMessageContentGameScore(string const &title_, int32 score_, bool is_pinned_)
  : title_(title_)
  , score_(score_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentGameScore::ID;

void pushMessageContentGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentGameScore");
    s.store_field("title", title_);
    s.store_field("score", score_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentInvoice::pushMessageContentInvoice()
  : price_()
  , is_pinned_()
{}

pushMessageContentInvoice::pushMessageContentInvoice(string const &price_, bool is_pinned_)
  : price_(price_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentInvoice::ID;

void pushMessageContentInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentInvoice");
    s.store_field("price", price_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentLocation::pushMessageContentLocation()
  : is_live_()
  , is_pinned_()
{}

pushMessageContentLocation::pushMessageContentLocation(bool is_live_, bool is_pinned_)
  : is_live_(is_live_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentLocation::ID;

void pushMessageContentLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentLocation");
    s.store_field("is_live", is_live_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentPaidMedia::pushMessageContentPaidMedia()
  : star_count_()
  , is_pinned_()
{}

pushMessageContentPaidMedia::pushMessageContentPaidMedia(int53 star_count_, bool is_pinned_)
  : star_count_(star_count_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentPaidMedia::ID;

void pushMessageContentPaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentPaidMedia");
    s.store_field("star_count", star_count_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentPhoto::pushMessageContentPhoto()
  : photo_()
  , caption_()
  , is_secret_()
  , is_pinned_()
{}

pushMessageContentPhoto::pushMessageContentPhoto(object_ptr<photo> &&photo_, string const &caption_, bool is_secret_, bool is_pinned_)
  : photo_(std::move(photo_))
  , caption_(caption_)
  , is_secret_(is_secret_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentPhoto::ID;

void pushMessageContentPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("caption", caption_);
    s.store_field("is_secret", is_secret_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentPoll::pushMessageContentPoll()
  : question_()
  , is_regular_()
  , is_pinned_()
{}

pushMessageContentPoll::pushMessageContentPoll(string const &question_, bool is_regular_, bool is_pinned_)
  : question_(question_)
  , is_regular_(is_regular_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentPoll::ID;

void pushMessageContentPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentPoll");
    s.store_field("question", question_);
    s.store_field("is_regular", is_regular_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentPremiumGiftCode::pushMessageContentPremiumGiftCode()
  : month_count_()
{}

pushMessageContentPremiumGiftCode::pushMessageContentPremiumGiftCode(int32 month_count_)
  : month_count_(month_count_)
{}

const std::int32_t pushMessageContentPremiumGiftCode::ID;

void pushMessageContentPremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentPremiumGiftCode");
    s.store_field("month_count", month_count_);
    s.store_class_end();
  }
}

pushMessageContentGiveaway::pushMessageContentGiveaway()
  : winner_count_()
  , prize_()
  , is_pinned_()
{}

pushMessageContentGiveaway::pushMessageContentGiveaway(int32 winner_count_, object_ptr<GiveawayPrize> &&prize_, bool is_pinned_)
  : winner_count_(winner_count_)
  , prize_(std::move(prize_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentGiveaway::ID;

void pushMessageContentGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentGiveaway");
    s.store_field("winner_count", winner_count_);
    s.store_object_field("prize", static_cast<const BaseObject *>(prize_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentGift::pushMessageContentGift()
  : star_count_()
  , is_prepaid_upgrade_()
{}

pushMessageContentGift::pushMessageContentGift(int53 star_count_, bool is_prepaid_upgrade_)
  : star_count_(star_count_)
  , is_prepaid_upgrade_(is_prepaid_upgrade_)
{}

const std::int32_t pushMessageContentGift::ID;

void pushMessageContentGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentGift");
    s.store_field("star_count", star_count_);
    s.store_field("is_prepaid_upgrade", is_prepaid_upgrade_);
    s.store_class_end();
  }
}

pushMessageContentUpgradedGift::pushMessageContentUpgradedGift()
  : is_upgrade_()
  , is_prepaid_upgrade_()
{}

pushMessageContentUpgradedGift::pushMessageContentUpgradedGift(bool is_upgrade_, bool is_prepaid_upgrade_)
  : is_upgrade_(is_upgrade_)
  , is_prepaid_upgrade_(is_prepaid_upgrade_)
{}

const std::int32_t pushMessageContentUpgradedGift::ID;

void pushMessageContentUpgradedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentUpgradedGift");
    s.store_field("is_upgrade", is_upgrade_);
    s.store_field("is_prepaid_upgrade", is_prepaid_upgrade_);
    s.store_class_end();
  }
}

pushMessageContentScreenshotTaken::pushMessageContentScreenshotTaken() {
}

const std::int32_t pushMessageContentScreenshotTaken::ID;

void pushMessageContentScreenshotTaken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentScreenshotTaken");
    s.store_class_end();
  }
}

pushMessageContentSticker::pushMessageContentSticker()
  : sticker_()
  , emoji_()
  , is_pinned_()
{}

pushMessageContentSticker::pushMessageContentSticker(object_ptr<sticker> &&sticker_, string const &emoji_, bool is_pinned_)
  : sticker_(std::move(sticker_))
  , emoji_(emoji_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentSticker::ID;

void pushMessageContentSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("emoji", emoji_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentStory::pushMessageContentStory()
  : is_mention_()
  , is_pinned_()
{}

pushMessageContentStory::pushMessageContentStory(bool is_mention_, bool is_pinned_)
  : is_mention_(is_mention_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentStory::ID;

void pushMessageContentStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentStory");
    s.store_field("is_mention", is_mention_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentText::pushMessageContentText()
  : text_()
  , is_pinned_()
{}

pushMessageContentText::pushMessageContentText(string const &text_, bool is_pinned_)
  : text_(text_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentText::ID;

void pushMessageContentText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentText");
    s.store_field("text", text_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentChecklist::pushMessageContentChecklist()
  : title_()
  , is_pinned_()
{}

pushMessageContentChecklist::pushMessageContentChecklist(string const &title_, bool is_pinned_)
  : title_(title_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentChecklist::ID;

void pushMessageContentChecklist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChecklist");
    s.store_field("title", title_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentVideo::pushMessageContentVideo()
  : video_()
  , caption_()
  , is_secret_()
  , is_pinned_()
{}

pushMessageContentVideo::pushMessageContentVideo(object_ptr<video> &&video_, string const &caption_, bool is_secret_, bool is_pinned_)
  : video_(std::move(video_))
  , caption_(caption_)
  , is_secret_(is_secret_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentVideo::ID;

void pushMessageContentVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVideo");
    s.store_object_field("video", static_cast<const BaseObject *>(video_.get()));
    s.store_field("caption", caption_);
    s.store_field("is_secret", is_secret_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentVideoNote::pushMessageContentVideoNote()
  : video_note_()
  , is_pinned_()
{}

pushMessageContentVideoNote::pushMessageContentVideoNote(object_ptr<videoNote> &&video_note_, bool is_pinned_)
  : video_note_(std::move(video_note_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentVideoNote::ID;

void pushMessageContentVideoNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVideoNote");
    s.store_object_field("video_note", static_cast<const BaseObject *>(video_note_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentVoiceNote::pushMessageContentVoiceNote()
  : voice_note_()
  , is_pinned_()
{}

pushMessageContentVoiceNote::pushMessageContentVoiceNote(object_ptr<voiceNote> &&voice_note_, bool is_pinned_)
  : voice_note_(std::move(voice_note_))
  , is_pinned_(is_pinned_)
{}

const std::int32_t pushMessageContentVoiceNote::ID;

void pushMessageContentVoiceNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVoiceNote");
    s.store_object_field("voice_note", static_cast<const BaseObject *>(voice_note_.get()));
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

pushMessageContentBasicGroupChatCreate::pushMessageContentBasicGroupChatCreate() {
}

const std::int32_t pushMessageContentBasicGroupChatCreate::ID;

void pushMessageContentBasicGroupChatCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentBasicGroupChatCreate");
    s.store_class_end();
  }
}

pushMessageContentVideoChatStarted::pushMessageContentVideoChatStarted() {
}

const std::int32_t pushMessageContentVideoChatStarted::ID;

void pushMessageContentVideoChatStarted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVideoChatStarted");
    s.store_class_end();
  }
}

pushMessageContentVideoChatEnded::pushMessageContentVideoChatEnded() {
}

const std::int32_t pushMessageContentVideoChatEnded::ID;

void pushMessageContentVideoChatEnded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentVideoChatEnded");
    s.store_class_end();
  }
}

pushMessageContentInviteVideoChatParticipants::pushMessageContentInviteVideoChatParticipants()
  : is_current_user_()
{}

pushMessageContentInviteVideoChatParticipants::pushMessageContentInviteVideoChatParticipants(bool is_current_user_)
  : is_current_user_(is_current_user_)
{}

const std::int32_t pushMessageContentInviteVideoChatParticipants::ID;

void pushMessageContentInviteVideoChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentInviteVideoChatParticipants");
    s.store_field("is_current_user", is_current_user_);
    s.store_class_end();
  }
}

pushMessageContentChatAddMembers::pushMessageContentChatAddMembers()
  : member_name_()
  , is_current_user_()
  , is_returned_()
{}

pushMessageContentChatAddMembers::pushMessageContentChatAddMembers(string const &member_name_, bool is_current_user_, bool is_returned_)
  : member_name_(member_name_)
  , is_current_user_(is_current_user_)
  , is_returned_(is_returned_)
{}

const std::int32_t pushMessageContentChatAddMembers::ID;

void pushMessageContentChatAddMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatAddMembers");
    s.store_field("member_name", member_name_);
    s.store_field("is_current_user", is_current_user_);
    s.store_field("is_returned", is_returned_);
    s.store_class_end();
  }
}

pushMessageContentChatChangePhoto::pushMessageContentChatChangePhoto() {
}

const std::int32_t pushMessageContentChatChangePhoto::ID;

void pushMessageContentChatChangePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatChangePhoto");
    s.store_class_end();
  }
}

pushMessageContentChatChangeTitle::pushMessageContentChatChangeTitle()
  : title_()
{}

pushMessageContentChatChangeTitle::pushMessageContentChatChangeTitle(string const &title_)
  : title_(title_)
{}

const std::int32_t pushMessageContentChatChangeTitle::ID;

void pushMessageContentChatChangeTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatChangeTitle");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

pushMessageContentChatSetBackground::pushMessageContentChatSetBackground()
  : is_same_()
{}

pushMessageContentChatSetBackground::pushMessageContentChatSetBackground(bool is_same_)
  : is_same_(is_same_)
{}

const std::int32_t pushMessageContentChatSetBackground::ID;

void pushMessageContentChatSetBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatSetBackground");
    s.store_field("is_same", is_same_);
    s.store_class_end();
  }
}

pushMessageContentChatSetTheme::pushMessageContentChatSetTheme()
  : name_()
{}

pushMessageContentChatSetTheme::pushMessageContentChatSetTheme(string const &name_)
  : name_(name_)
{}

const std::int32_t pushMessageContentChatSetTheme::ID;

void pushMessageContentChatSetTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatSetTheme");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

pushMessageContentChatDeleteMember::pushMessageContentChatDeleteMember()
  : member_name_()
  , is_current_user_()
  , is_left_()
{}

pushMessageContentChatDeleteMember::pushMessageContentChatDeleteMember(string const &member_name_, bool is_current_user_, bool is_left_)
  : member_name_(member_name_)
  , is_current_user_(is_current_user_)
  , is_left_(is_left_)
{}

const std::int32_t pushMessageContentChatDeleteMember::ID;

void pushMessageContentChatDeleteMember::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatDeleteMember");
    s.store_field("member_name", member_name_);
    s.store_field("is_current_user", is_current_user_);
    s.store_field("is_left", is_left_);
    s.store_class_end();
  }
}

pushMessageContentChatJoinByLink::pushMessageContentChatJoinByLink() {
}

const std::int32_t pushMessageContentChatJoinByLink::ID;

void pushMessageContentChatJoinByLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatJoinByLink");
    s.store_class_end();
  }
}

pushMessageContentChatJoinByRequest::pushMessageContentChatJoinByRequest() {
}

const std::int32_t pushMessageContentChatJoinByRequest::ID;

void pushMessageContentChatJoinByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChatJoinByRequest");
    s.store_class_end();
  }
}

pushMessageContentRecurringPayment::pushMessageContentRecurringPayment()
  : amount_()
{}

pushMessageContentRecurringPayment::pushMessageContentRecurringPayment(string const &amount_)
  : amount_(amount_)
{}

const std::int32_t pushMessageContentRecurringPayment::ID;

void pushMessageContentRecurringPayment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentRecurringPayment");
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

pushMessageContentSuggestProfilePhoto::pushMessageContentSuggestProfilePhoto() {
}

const std::int32_t pushMessageContentSuggestProfilePhoto::ID;

void pushMessageContentSuggestProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentSuggestProfilePhoto");
    s.store_class_end();
  }
}

pushMessageContentSuggestBirthdate::pushMessageContentSuggestBirthdate() {
}

const std::int32_t pushMessageContentSuggestBirthdate::ID;

void pushMessageContentSuggestBirthdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentSuggestBirthdate");
    s.store_class_end();
  }
}

pushMessageContentProximityAlertTriggered::pushMessageContentProximityAlertTriggered()
  : distance_()
{}

pushMessageContentProximityAlertTriggered::pushMessageContentProximityAlertTriggered(int32 distance_)
  : distance_(distance_)
{}

const std::int32_t pushMessageContentProximityAlertTriggered::ID;

void pushMessageContentProximityAlertTriggered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentProximityAlertTriggered");
    s.store_field("distance", distance_);
    s.store_class_end();
  }
}

pushMessageContentChecklistTasksAdded::pushMessageContentChecklistTasksAdded()
  : task_count_()
{}

pushMessageContentChecklistTasksAdded::pushMessageContentChecklistTasksAdded(int32 task_count_)
  : task_count_(task_count_)
{}

const std::int32_t pushMessageContentChecklistTasksAdded::ID;

void pushMessageContentChecklistTasksAdded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChecklistTasksAdded");
    s.store_field("task_count", task_count_);
    s.store_class_end();
  }
}

pushMessageContentChecklistTasksDone::pushMessageContentChecklistTasksDone()
  : task_count_()
{}

pushMessageContentChecklistTasksDone::pushMessageContentChecklistTasksDone(int32 task_count_)
  : task_count_(task_count_)
{}

const std::int32_t pushMessageContentChecklistTasksDone::ID;

void pushMessageContentChecklistTasksDone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentChecklistTasksDone");
    s.store_field("task_count", task_count_);
    s.store_class_end();
  }
}

pushMessageContentPollOptionAdded::pushMessageContentPollOptionAdded()
  : text_()
{}

pushMessageContentPollOptionAdded::pushMessageContentPollOptionAdded(string const &text_)
  : text_(text_)
{}

const std::int32_t pushMessageContentPollOptionAdded::ID;

void pushMessageContentPollOptionAdded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentPollOptionAdded");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

pushMessageContentMessageForwards::pushMessageContentMessageForwards()
  : total_count_()
{}

pushMessageContentMessageForwards::pushMessageContentMessageForwards(int32 total_count_)
  : total_count_(total_count_)
{}

const std::int32_t pushMessageContentMessageForwards::ID;

void pushMessageContentMessageForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentMessageForwards");
    s.store_field("total_count", total_count_);
    s.store_class_end();
  }
}

pushMessageContentMediaAlbum::pushMessageContentMediaAlbum()
  : total_count_()
  , has_photos_()
  , has_videos_()
  , has_audios_()
  , has_documents_()
{}

pushMessageContentMediaAlbum::pushMessageContentMediaAlbum(int32 total_count_, bool has_photos_, bool has_videos_, bool has_audios_, bool has_documents_)
  : total_count_(total_count_)
  , has_photos_(has_photos_)
  , has_videos_(has_videos_)
  , has_audios_(has_audios_)
  , has_documents_(has_documents_)
{}

const std::int32_t pushMessageContentMediaAlbum::ID;

void pushMessageContentMediaAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pushMessageContentMediaAlbum");
    s.store_field("total_count", total_count_);
    s.store_field("has_photos", has_photos_);
    s.store_field("has_videos", has_videos_);
    s.store_field("has_audios", has_audios_);
    s.store_field("has_documents", has_documents_);
    s.store_class_end();
  }
}

receivedGift::receivedGift()
  : received_gift_id_()
  , sender_id_()
  , text_()
  , unique_gift_number_()
  , is_private_()
  , is_saved_()
  , is_pinned_()
  , can_be_upgraded_()
  , can_be_transferred_()
  , was_refunded_()
  , date_()
  , gift_()
  , collection_ids_()
  , sell_star_count_()
  , prepaid_upgrade_star_count_()
  , is_upgrade_separate_()
  , transfer_star_count_()
  , drop_original_details_star_count_()
  , next_transfer_date_()
  , next_resale_date_()
  , export_date_()
  , prepaid_upgrade_hash_()
  , craft_date_()
{}

receivedGift::receivedGift(string const &received_gift_id_, object_ptr<MessageSender> &&sender_id_, object_ptr<formattedText> &&text_, int32 unique_gift_number_, bool is_private_, bool is_saved_, bool is_pinned_, bool can_be_upgraded_, bool can_be_transferred_, bool was_refunded_, int32 date_, object_ptr<SentGift> &&gift_, array<int32> &&collection_ids_, int53 sell_star_count_, int53 prepaid_upgrade_star_count_, bool is_upgrade_separate_, int53 transfer_star_count_, int53 drop_original_details_star_count_, int32 next_transfer_date_, int32 next_resale_date_, int32 export_date_, string const &prepaid_upgrade_hash_, int32 craft_date_)
  : received_gift_id_(received_gift_id_)
  , sender_id_(std::move(sender_id_))
  , text_(std::move(text_))
  , unique_gift_number_(unique_gift_number_)
  , is_private_(is_private_)
  , is_saved_(is_saved_)
  , is_pinned_(is_pinned_)
  , can_be_upgraded_(can_be_upgraded_)
  , can_be_transferred_(can_be_transferred_)
  , was_refunded_(was_refunded_)
  , date_(date_)
  , gift_(std::move(gift_))
  , collection_ids_(std::move(collection_ids_))
  , sell_star_count_(sell_star_count_)
  , prepaid_upgrade_star_count_(prepaid_upgrade_star_count_)
  , is_upgrade_separate_(is_upgrade_separate_)
  , transfer_star_count_(transfer_star_count_)
  , drop_original_details_star_count_(drop_original_details_star_count_)
  , next_transfer_date_(next_transfer_date_)
  , next_resale_date_(next_resale_date_)
  , export_date_(export_date_)
  , prepaid_upgrade_hash_(prepaid_upgrade_hash_)
  , craft_date_(craft_date_)
{}

const std::int32_t receivedGift::ID;

void receivedGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "receivedGift");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("unique_gift_number", unique_gift_number_);
    s.store_field("is_private", is_private_);
    s.store_field("is_saved", is_saved_);
    s.store_field("is_pinned", is_pinned_);
    s.store_field("can_be_upgraded", can_be_upgraded_);
    s.store_field("can_be_transferred", can_be_transferred_);
    s.store_field("was_refunded", was_refunded_);
    s.store_field("date", date_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    { s.store_vector_begin("collection_ids", collection_ids_.size()); for (const auto &_value : collection_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("sell_star_count", sell_star_count_);
    s.store_field("prepaid_upgrade_star_count", prepaid_upgrade_star_count_);
    s.store_field("is_upgrade_separate", is_upgrade_separate_);
    s.store_field("transfer_star_count", transfer_star_count_);
    s.store_field("drop_original_details_star_count", drop_original_details_star_count_);
    s.store_field("next_transfer_date", next_transfer_date_);
    s.store_field("next_resale_date", next_resale_date_);
    s.store_field("export_date", export_date_);
    s.store_field("prepaid_upgrade_hash", prepaid_upgrade_hash_);
    s.store_field("craft_date", craft_date_);
    s.store_class_end();
  }
}

reportReasonSpam::reportReasonSpam() {
}

const std::int32_t reportReasonSpam::ID;

void reportReasonSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonSpam");
    s.store_class_end();
  }
}

reportReasonViolence::reportReasonViolence() {
}

const std::int32_t reportReasonViolence::ID;

void reportReasonViolence::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonViolence");
    s.store_class_end();
  }
}

reportReasonPornography::reportReasonPornography() {
}

const std::int32_t reportReasonPornography::ID;

void reportReasonPornography::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonPornography");
    s.store_class_end();
  }
}

reportReasonChildAbuse::reportReasonChildAbuse() {
}

const std::int32_t reportReasonChildAbuse::ID;

void reportReasonChildAbuse::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonChildAbuse");
    s.store_class_end();
  }
}

reportReasonCopyright::reportReasonCopyright() {
}

const std::int32_t reportReasonCopyright::ID;

void reportReasonCopyright::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonCopyright");
    s.store_class_end();
  }
}

reportReasonUnrelatedLocation::reportReasonUnrelatedLocation() {
}

const std::int32_t reportReasonUnrelatedLocation::ID;

void reportReasonUnrelatedLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonUnrelatedLocation");
    s.store_class_end();
  }
}

reportReasonFake::reportReasonFake() {
}

const std::int32_t reportReasonFake::ID;

void reportReasonFake::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonFake");
    s.store_class_end();
  }
}

reportReasonIllegalDrugs::reportReasonIllegalDrugs() {
}

const std::int32_t reportReasonIllegalDrugs::ID;

void reportReasonIllegalDrugs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonIllegalDrugs");
    s.store_class_end();
  }
}

reportReasonPersonalDetails::reportReasonPersonalDetails() {
}

const std::int32_t reportReasonPersonalDetails::ID;

void reportReasonPersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonPersonalDetails");
    s.store_class_end();
  }
}

reportReasonCustom::reportReasonCustom() {
}

const std::int32_t reportReasonCustom::ID;

void reportReasonCustom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportReasonCustom");
    s.store_class_end();
  }
}

savedMessagesTags::savedMessagesTags()
  : tags_()
{}

savedMessagesTags::savedMessagesTags(array<object_ptr<savedMessagesTag>> &&tags_)
  : tags_(std::move(tags_))
{}

const std::int32_t savedMessagesTags::ID;

void savedMessagesTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedMessagesTags");
    { s.store_vector_begin("tags", tags_.size()); for (const auto &_value : tags_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

sessionTypeAndroid::sessionTypeAndroid() {
}

const std::int32_t sessionTypeAndroid::ID;

void sessionTypeAndroid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeAndroid");
    s.store_class_end();
  }
}

sessionTypeApple::sessionTypeApple() {
}

const std::int32_t sessionTypeApple::ID;

void sessionTypeApple::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeApple");
    s.store_class_end();
  }
}

sessionTypeBrave::sessionTypeBrave() {
}

const std::int32_t sessionTypeBrave::ID;

void sessionTypeBrave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeBrave");
    s.store_class_end();
  }
}

sessionTypeChrome::sessionTypeChrome() {
}

const std::int32_t sessionTypeChrome::ID;

void sessionTypeChrome::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeChrome");
    s.store_class_end();
  }
}

sessionTypeEdge::sessionTypeEdge() {
}

const std::int32_t sessionTypeEdge::ID;

void sessionTypeEdge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeEdge");
    s.store_class_end();
  }
}

sessionTypeFirefox::sessionTypeFirefox() {
}

const std::int32_t sessionTypeFirefox::ID;

void sessionTypeFirefox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeFirefox");
    s.store_class_end();
  }
}

sessionTypeIpad::sessionTypeIpad() {
}

const std::int32_t sessionTypeIpad::ID;

void sessionTypeIpad::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeIpad");
    s.store_class_end();
  }
}

sessionTypeIphone::sessionTypeIphone() {
}

const std::int32_t sessionTypeIphone::ID;

void sessionTypeIphone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeIphone");
    s.store_class_end();
  }
}

sessionTypeLinux::sessionTypeLinux() {
}

const std::int32_t sessionTypeLinux::ID;

void sessionTypeLinux::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeLinux");
    s.store_class_end();
  }
}

sessionTypeMac::sessionTypeMac() {
}

const std::int32_t sessionTypeMac::ID;

void sessionTypeMac::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeMac");
    s.store_class_end();
  }
}

sessionTypeOpera::sessionTypeOpera() {
}

const std::int32_t sessionTypeOpera::ID;

void sessionTypeOpera::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeOpera");
    s.store_class_end();
  }
}

sessionTypeSafari::sessionTypeSafari() {
}

const std::int32_t sessionTypeSafari::ID;

void sessionTypeSafari::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeSafari");
    s.store_class_end();
  }
}

sessionTypeUbuntu::sessionTypeUbuntu() {
}

const std::int32_t sessionTypeUbuntu::ID;

void sessionTypeUbuntu::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeUbuntu");
    s.store_class_end();
  }
}

sessionTypeUnknown::sessionTypeUnknown() {
}

const std::int32_t sessionTypeUnknown::ID;

void sessionTypeUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeUnknown");
    s.store_class_end();
  }
}

sessionTypeVivaldi::sessionTypeVivaldi() {
}

const std::int32_t sessionTypeVivaldi::ID;

void sessionTypeVivaldi::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeVivaldi");
    s.store_class_end();
  }
}

sessionTypeWindows::sessionTypeWindows() {
}

const std::int32_t sessionTypeWindows::ID;

void sessionTypeWindows::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeWindows");
    s.store_class_end();
  }
}

sessionTypeXbox::sessionTypeXbox() {
}

const std::int32_t sessionTypeXbox::ID;

void sessionTypeXbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sessionTypeXbox");
    s.store_class_end();
  }
}

shippingOption::shippingOption()
  : id_()
  , title_()
  , price_parts_()
{}

shippingOption::shippingOption(string const &id_, string const &title_, array<object_ptr<labeledPricePart>> &&price_parts_)
  : id_(id_)
  , title_(title_)
  , price_parts_(std::move(price_parts_))
{}

const std::int32_t shippingOption::ID;

void shippingOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shippingOption");
    s.store_field("id", id_);
    s.store_field("title", title_);
    { s.store_vector_begin("price_parts", price_parts_.size()); for (const auto &_value : price_parts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starPaymentOptions::starPaymentOptions()
  : options_()
{}

starPaymentOptions::starPaymentOptions(array<object_ptr<starPaymentOption>> &&options_)
  : options_(std::move(options_))
{}

const std::int32_t starPaymentOptions::ID;

void starPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starPaymentOptions");
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starTransaction::starTransaction()
  : id_()
  , star_amount_()
  , is_refund_()
  , date_()
  , type_()
{}

starTransaction::starTransaction(string const &id_, object_ptr<starAmount> &&star_amount_, bool is_refund_, int32 date_, object_ptr<StarTransactionType> &&type_)
  : id_(id_)
  , star_amount_(std::move(star_amount_))
  , is_refund_(is_refund_)
  , date_(date_)
  , type_(std::move(type_))
{}

const std::int32_t starTransaction::ID;

void starTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransaction");
    s.store_field("id", id_);
    s.store_object_field("star_amount", static_cast<const BaseObject *>(star_amount_.get()));
    s.store_field("is_refund", is_refund_);
    s.store_field("date", date_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

starTransactionTypePremiumBotDeposit::starTransactionTypePremiumBotDeposit() {
}

const std::int32_t starTransactionTypePremiumBotDeposit::ID;

void starTransactionTypePremiumBotDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePremiumBotDeposit");
    s.store_class_end();
  }
}

starTransactionTypeAppStoreDeposit::starTransactionTypeAppStoreDeposit() {
}

const std::int32_t starTransactionTypeAppStoreDeposit::ID;

void starTransactionTypeAppStoreDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeAppStoreDeposit");
    s.store_class_end();
  }
}

starTransactionTypeGooglePlayDeposit::starTransactionTypeGooglePlayDeposit() {
}

const std::int32_t starTransactionTypeGooglePlayDeposit::ID;

void starTransactionTypeGooglePlayDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGooglePlayDeposit");
    s.store_class_end();
  }
}

starTransactionTypeFragmentDeposit::starTransactionTypeFragmentDeposit() {
}

const std::int32_t starTransactionTypeFragmentDeposit::ID;

void starTransactionTypeFragmentDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeFragmentDeposit");
    s.store_class_end();
  }
}

starTransactionTypeUserDeposit::starTransactionTypeUserDeposit()
  : user_id_()
  , sticker_()
{}

starTransactionTypeUserDeposit::starTransactionTypeUserDeposit(int53 user_id_, object_ptr<sticker> &&sticker_)
  : user_id_(user_id_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t starTransactionTypeUserDeposit::ID;

void starTransactionTypeUserDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeUserDeposit");
    s.store_field("user_id", user_id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiveawayDeposit::starTransactionTypeGiveawayDeposit()
  : chat_id_()
  , giveaway_message_id_()
{}

starTransactionTypeGiveawayDeposit::starTransactionTypeGiveawayDeposit(int53 chat_id_, int53 giveaway_message_id_)
  : chat_id_(chat_id_)
  , giveaway_message_id_(giveaway_message_id_)
{}

const std::int32_t starTransactionTypeGiveawayDeposit::ID;

void starTransactionTypeGiveawayDeposit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiveawayDeposit");
    s.store_field("chat_id", chat_id_);
    s.store_field("giveaway_message_id", giveaway_message_id_);
    s.store_class_end();
  }
}

starTransactionTypeFragmentWithdrawal::starTransactionTypeFragmentWithdrawal()
  : withdrawal_state_()
{}

starTransactionTypeFragmentWithdrawal::starTransactionTypeFragmentWithdrawal(object_ptr<RevenueWithdrawalState> &&withdrawal_state_)
  : withdrawal_state_(std::move(withdrawal_state_))
{}

const std::int32_t starTransactionTypeFragmentWithdrawal::ID;

void starTransactionTypeFragmentWithdrawal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeFragmentWithdrawal");
    s.store_object_field("withdrawal_state", static_cast<const BaseObject *>(withdrawal_state_.get()));
    s.store_class_end();
  }
}

starTransactionTypeTelegramAdsWithdrawal::starTransactionTypeTelegramAdsWithdrawal() {
}

const std::int32_t starTransactionTypeTelegramAdsWithdrawal::ID;

void starTransactionTypeTelegramAdsWithdrawal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeTelegramAdsWithdrawal");
    s.store_class_end();
  }
}

starTransactionTypeTelegramApiUsage::starTransactionTypeTelegramApiUsage()
  : request_count_()
{}

starTransactionTypeTelegramApiUsage::starTransactionTypeTelegramApiUsage(int32 request_count_)
  : request_count_(request_count_)
{}

const std::int32_t starTransactionTypeTelegramApiUsage::ID;

void starTransactionTypeTelegramApiUsage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeTelegramApiUsage");
    s.store_field("request_count", request_count_);
    s.store_class_end();
  }
}

starTransactionTypeBotPaidMediaPurchase::starTransactionTypeBotPaidMediaPurchase()
  : user_id_()
  , media_()
{}

starTransactionTypeBotPaidMediaPurchase::starTransactionTypeBotPaidMediaPurchase(int53 user_id_, array<object_ptr<PaidMedia>> &&media_)
  : user_id_(user_id_)
  , media_(std::move(media_))
{}

const std::int32_t starTransactionTypeBotPaidMediaPurchase::ID;

void starTransactionTypeBotPaidMediaPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBotPaidMediaPurchase");
    s.store_field("user_id", user_id_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starTransactionTypeBotPaidMediaSale::starTransactionTypeBotPaidMediaSale()
  : user_id_()
  , media_()
  , payload_()
  , affiliate_()
{}

starTransactionTypeBotPaidMediaSale::starTransactionTypeBotPaidMediaSale(int53 user_id_, array<object_ptr<PaidMedia>> &&media_, string const &payload_, object_ptr<affiliateInfo> &&affiliate_)
  : user_id_(user_id_)
  , media_(std::move(media_))
  , payload_(payload_)
  , affiliate_(std::move(affiliate_))
{}

const std::int32_t starTransactionTypeBotPaidMediaSale::ID;

void starTransactionTypeBotPaidMediaSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBotPaidMediaSale");
    s.store_field("user_id", user_id_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("payload", payload_);
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_class_end();
  }
}

starTransactionTypeChannelPaidMediaPurchase::starTransactionTypeChannelPaidMediaPurchase()
  : chat_id_()
  , message_id_()
  , media_()
{}

starTransactionTypeChannelPaidMediaPurchase::starTransactionTypeChannelPaidMediaPurchase(int53 chat_id_, int53 message_id_, array<object_ptr<PaidMedia>> &&media_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , media_(std::move(media_))
{}

const std::int32_t starTransactionTypeChannelPaidMediaPurchase::ID;

void starTransactionTypeChannelPaidMediaPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeChannelPaidMediaPurchase");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starTransactionTypeChannelPaidMediaSale::starTransactionTypeChannelPaidMediaSale()
  : user_id_()
  , message_id_()
  , media_()
{}

starTransactionTypeChannelPaidMediaSale::starTransactionTypeChannelPaidMediaSale(int53 user_id_, int53 message_id_, array<object_ptr<PaidMedia>> &&media_)
  : user_id_(user_id_)
  , message_id_(message_id_)
  , media_(std::move(media_))
{}

const std::int32_t starTransactionTypeChannelPaidMediaSale::ID;

void starTransactionTypeChannelPaidMediaSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeChannelPaidMediaSale");
    s.store_field("user_id", user_id_);
    s.store_field("message_id", message_id_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starTransactionTypeBotInvoicePurchase::starTransactionTypeBotInvoicePurchase()
  : user_id_()
  , product_info_()
{}

starTransactionTypeBotInvoicePurchase::starTransactionTypeBotInvoicePurchase(int53 user_id_, object_ptr<productInfo> &&product_info_)
  : user_id_(user_id_)
  , product_info_(std::move(product_info_))
{}

const std::int32_t starTransactionTypeBotInvoicePurchase::ID;

void starTransactionTypeBotInvoicePurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBotInvoicePurchase");
    s.store_field("user_id", user_id_);
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_class_end();
  }
}

starTransactionTypeBotInvoiceSale::starTransactionTypeBotInvoiceSale()
  : user_id_()
  , product_info_()
  , invoice_payload_()
  , affiliate_()
{}

starTransactionTypeBotInvoiceSale::starTransactionTypeBotInvoiceSale(int53 user_id_, object_ptr<productInfo> &&product_info_, bytes const &invoice_payload_, object_ptr<affiliateInfo> &&affiliate_)
  : user_id_(user_id_)
  , product_info_(std::move(product_info_))
  , invoice_payload_(std::move(invoice_payload_))
  , affiliate_(std::move(affiliate_))
{}

const std::int32_t starTransactionTypeBotInvoiceSale::ID;

void starTransactionTypeBotInvoiceSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBotInvoiceSale");
    s.store_field("user_id", user_id_);
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_bytes_field("invoice_payload", invoice_payload_);
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_class_end();
  }
}

starTransactionTypeBotSubscriptionPurchase::starTransactionTypeBotSubscriptionPurchase()
  : user_id_()
  , subscription_period_()
  , product_info_()
{}

starTransactionTypeBotSubscriptionPurchase::starTransactionTypeBotSubscriptionPurchase(int53 user_id_, int32 subscription_period_, object_ptr<productInfo> &&product_info_)
  : user_id_(user_id_)
  , subscription_period_(subscription_period_)
  , product_info_(std::move(product_info_))
{}

const std::int32_t starTransactionTypeBotSubscriptionPurchase::ID;

void starTransactionTypeBotSubscriptionPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBotSubscriptionPurchase");
    s.store_field("user_id", user_id_);
    s.store_field("subscription_period", subscription_period_);
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_class_end();
  }
}

starTransactionTypeBotSubscriptionSale::starTransactionTypeBotSubscriptionSale()
  : user_id_()
  , subscription_period_()
  , product_info_()
  , invoice_payload_()
  , affiliate_()
{}

starTransactionTypeBotSubscriptionSale::starTransactionTypeBotSubscriptionSale(int53 user_id_, int32 subscription_period_, object_ptr<productInfo> &&product_info_, bytes const &invoice_payload_, object_ptr<affiliateInfo> &&affiliate_)
  : user_id_(user_id_)
  , subscription_period_(subscription_period_)
  , product_info_(std::move(product_info_))
  , invoice_payload_(std::move(invoice_payload_))
  , affiliate_(std::move(affiliate_))
{}

const std::int32_t starTransactionTypeBotSubscriptionSale::ID;

void starTransactionTypeBotSubscriptionSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBotSubscriptionSale");
    s.store_field("user_id", user_id_);
    s.store_field("subscription_period", subscription_period_);
    s.store_object_field("product_info", static_cast<const BaseObject *>(product_info_.get()));
    s.store_bytes_field("invoice_payload", invoice_payload_);
    s.store_object_field("affiliate", static_cast<const BaseObject *>(affiliate_.get()));
    s.store_class_end();
  }
}

starTransactionTypeChannelSubscriptionPurchase::starTransactionTypeChannelSubscriptionPurchase()
  : chat_id_()
  , subscription_period_()
{}

starTransactionTypeChannelSubscriptionPurchase::starTransactionTypeChannelSubscriptionPurchase(int53 chat_id_, int32 subscription_period_)
  : chat_id_(chat_id_)
  , subscription_period_(subscription_period_)
{}

const std::int32_t starTransactionTypeChannelSubscriptionPurchase::ID;

void starTransactionTypeChannelSubscriptionPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeChannelSubscriptionPurchase");
    s.store_field("chat_id", chat_id_);
    s.store_field("subscription_period", subscription_period_);
    s.store_class_end();
  }
}

starTransactionTypeChannelSubscriptionSale::starTransactionTypeChannelSubscriptionSale()
  : user_id_()
  , subscription_period_()
{}

starTransactionTypeChannelSubscriptionSale::starTransactionTypeChannelSubscriptionSale(int53 user_id_, int32 subscription_period_)
  : user_id_(user_id_)
  , subscription_period_(subscription_period_)
{}

const std::int32_t starTransactionTypeChannelSubscriptionSale::ID;

void starTransactionTypeChannelSubscriptionSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeChannelSubscriptionSale");
    s.store_field("user_id", user_id_);
    s.store_field("subscription_period", subscription_period_);
    s.store_class_end();
  }
}

starTransactionTypeGiftAuctionBid::starTransactionTypeGiftAuctionBid()
  : owner_id_()
  , gift_()
{}

starTransactionTypeGiftAuctionBid::starTransactionTypeGiftAuctionBid(object_ptr<MessageSender> &&owner_id_, object_ptr<gift> &&gift_)
  : owner_id_(std::move(owner_id_))
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftAuctionBid::ID;

void starTransactionTypeGiftAuctionBid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftAuctionBid");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftPurchase::starTransactionTypeGiftPurchase()
  : owner_id_()
  , gift_()
{}

starTransactionTypeGiftPurchase::starTransactionTypeGiftPurchase(object_ptr<MessageSender> &&owner_id_, object_ptr<gift> &&gift_)
  : owner_id_(std::move(owner_id_))
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftPurchase::ID;

void starTransactionTypeGiftPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftPurchase");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftPurchaseOffer::starTransactionTypeGiftPurchaseOffer()
  : gift_()
{}

starTransactionTypeGiftPurchaseOffer::starTransactionTypeGiftPurchaseOffer(object_ptr<upgradedGift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftPurchaseOffer::ID;

void starTransactionTypeGiftPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftPurchaseOffer");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftTransfer::starTransactionTypeGiftTransfer()
  : owner_id_()
  , gift_()
{}

starTransactionTypeGiftTransfer::starTransactionTypeGiftTransfer(object_ptr<MessageSender> &&owner_id_, object_ptr<upgradedGift> &&gift_)
  : owner_id_(std::move(owner_id_))
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftTransfer::ID;

void starTransactionTypeGiftTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftTransfer");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftOriginalDetailsDrop::starTransactionTypeGiftOriginalDetailsDrop()
  : owner_id_()
  , gift_()
{}

starTransactionTypeGiftOriginalDetailsDrop::starTransactionTypeGiftOriginalDetailsDrop(object_ptr<MessageSender> &&owner_id_, object_ptr<upgradedGift> &&gift_)
  : owner_id_(std::move(owner_id_))
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftOriginalDetailsDrop::ID;

void starTransactionTypeGiftOriginalDetailsDrop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftOriginalDetailsDrop");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftSale::starTransactionTypeGiftSale()
  : user_id_()
  , gift_()
{}

starTransactionTypeGiftSale::starTransactionTypeGiftSale(int53 user_id_, object_ptr<gift> &&gift_)
  : user_id_(user_id_)
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftSale::ID;

void starTransactionTypeGiftSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftSale");
    s.store_field("user_id", user_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftUpgrade::starTransactionTypeGiftUpgrade()
  : user_id_()
  , gift_()
{}

starTransactionTypeGiftUpgrade::starTransactionTypeGiftUpgrade(int53 user_id_, object_ptr<upgradedGift> &&gift_)
  : user_id_(user_id_)
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftUpgrade::ID;

void starTransactionTypeGiftUpgrade::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftUpgrade");
    s.store_field("user_id", user_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeGiftUpgradePurchase::starTransactionTypeGiftUpgradePurchase()
  : owner_id_()
  , gift_()
{}

starTransactionTypeGiftUpgradePurchase::starTransactionTypeGiftUpgradePurchase(object_ptr<MessageSender> &&owner_id_, object_ptr<gift> &&gift_)
  : owner_id_(std::move(owner_id_))
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeGiftUpgradePurchase::ID;

void starTransactionTypeGiftUpgradePurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeGiftUpgradePurchase");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeUpgradedGiftPurchase::starTransactionTypeUpgradedGiftPurchase()
  : user_id_()
  , gift_()
{}

starTransactionTypeUpgradedGiftPurchase::starTransactionTypeUpgradedGiftPurchase(int53 user_id_, object_ptr<upgradedGift> &&gift_)
  : user_id_(user_id_)
  , gift_(std::move(gift_))
{}

const std::int32_t starTransactionTypeUpgradedGiftPurchase::ID;

void starTransactionTypeUpgradedGiftPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeUpgradedGiftPurchase");
    s.store_field("user_id", user_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

starTransactionTypeUpgradedGiftSale::starTransactionTypeUpgradedGiftSale()
  : user_id_()
  , gift_()
  , commission_per_mille_()
  , commission_star_amount_()
  , via_offer_()
{}

starTransactionTypeUpgradedGiftSale::starTransactionTypeUpgradedGiftSale(int53 user_id_, object_ptr<upgradedGift> &&gift_, int32 commission_per_mille_, object_ptr<starAmount> &&commission_star_amount_, bool via_offer_)
  : user_id_(user_id_)
  , gift_(std::move(gift_))
  , commission_per_mille_(commission_per_mille_)
  , commission_star_amount_(std::move(commission_star_amount_))
  , via_offer_(via_offer_)
{}

const std::int32_t starTransactionTypeUpgradedGiftSale::ID;

void starTransactionTypeUpgradedGiftSale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeUpgradedGiftSale");
    s.store_field("user_id", user_id_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_object_field("commission_star_amount", static_cast<const BaseObject *>(commission_star_amount_.get()));
    s.store_field("via_offer", via_offer_);
    s.store_class_end();
  }
}

starTransactionTypeChannelPaidReactionSend::starTransactionTypeChannelPaidReactionSend()
  : chat_id_()
  , message_id_()
{}

starTransactionTypeChannelPaidReactionSend::starTransactionTypeChannelPaidReactionSend(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t starTransactionTypeChannelPaidReactionSend::ID;

void starTransactionTypeChannelPaidReactionSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeChannelPaidReactionSend");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

starTransactionTypeChannelPaidReactionReceive::starTransactionTypeChannelPaidReactionReceive()
  : user_id_()
  , message_id_()
{}

starTransactionTypeChannelPaidReactionReceive::starTransactionTypeChannelPaidReactionReceive(int53 user_id_, int53 message_id_)
  : user_id_(user_id_)
  , message_id_(message_id_)
{}

const std::int32_t starTransactionTypeChannelPaidReactionReceive::ID;

void starTransactionTypeChannelPaidReactionReceive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeChannelPaidReactionReceive");
    s.store_field("user_id", user_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

starTransactionTypeAffiliateProgramCommission::starTransactionTypeAffiliateProgramCommission()
  : chat_id_()
  , commission_per_mille_()
{}

starTransactionTypeAffiliateProgramCommission::starTransactionTypeAffiliateProgramCommission(int53 chat_id_, int32 commission_per_mille_)
  : chat_id_(chat_id_)
  , commission_per_mille_(commission_per_mille_)
{}

const std::int32_t starTransactionTypeAffiliateProgramCommission::ID;

void starTransactionTypeAffiliateProgramCommission::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeAffiliateProgramCommission");
    s.store_field("chat_id", chat_id_);
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_class_end();
  }
}

starTransactionTypePaidMessageSend::starTransactionTypePaidMessageSend()
  : chat_id_()
  , message_count_()
{}

starTransactionTypePaidMessageSend::starTransactionTypePaidMessageSend(int53 chat_id_, int32 message_count_)
  : chat_id_(chat_id_)
  , message_count_(message_count_)
{}

const std::int32_t starTransactionTypePaidMessageSend::ID;

void starTransactionTypePaidMessageSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePaidMessageSend");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_count", message_count_);
    s.store_class_end();
  }
}

starTransactionTypePaidMessageReceive::starTransactionTypePaidMessageReceive()
  : sender_id_()
  , message_count_()
  , commission_per_mille_()
  , commission_star_amount_()
{}

starTransactionTypePaidMessageReceive::starTransactionTypePaidMessageReceive(object_ptr<MessageSender> &&sender_id_, int32 message_count_, int32 commission_per_mille_, object_ptr<starAmount> &&commission_star_amount_)
  : sender_id_(std::move(sender_id_))
  , message_count_(message_count_)
  , commission_per_mille_(commission_per_mille_)
  , commission_star_amount_(std::move(commission_star_amount_))
{}

const std::int32_t starTransactionTypePaidMessageReceive::ID;

void starTransactionTypePaidMessageReceive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePaidMessageReceive");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("message_count", message_count_);
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_object_field("commission_star_amount", static_cast<const BaseObject *>(commission_star_amount_.get()));
    s.store_class_end();
  }
}

starTransactionTypePaidGroupCallMessageSend::starTransactionTypePaidGroupCallMessageSend()
  : chat_id_()
{}

starTransactionTypePaidGroupCallMessageSend::starTransactionTypePaidGroupCallMessageSend(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t starTransactionTypePaidGroupCallMessageSend::ID;

void starTransactionTypePaidGroupCallMessageSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePaidGroupCallMessageSend");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

starTransactionTypePaidGroupCallMessageReceive::starTransactionTypePaidGroupCallMessageReceive()
  : sender_id_()
  , commission_per_mille_()
  , commission_star_amount_()
{}

starTransactionTypePaidGroupCallMessageReceive::starTransactionTypePaidGroupCallMessageReceive(object_ptr<MessageSender> &&sender_id_, int32 commission_per_mille_, object_ptr<starAmount> &&commission_star_amount_)
  : sender_id_(std::move(sender_id_))
  , commission_per_mille_(commission_per_mille_)
  , commission_star_amount_(std::move(commission_star_amount_))
{}

const std::int32_t starTransactionTypePaidGroupCallMessageReceive::ID;

void starTransactionTypePaidGroupCallMessageReceive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePaidGroupCallMessageReceive");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_object_field("commission_star_amount", static_cast<const BaseObject *>(commission_star_amount_.get()));
    s.store_class_end();
  }
}

starTransactionTypePaidGroupCallReactionSend::starTransactionTypePaidGroupCallReactionSend()
  : chat_id_()
{}

starTransactionTypePaidGroupCallReactionSend::starTransactionTypePaidGroupCallReactionSend(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t starTransactionTypePaidGroupCallReactionSend::ID;

void starTransactionTypePaidGroupCallReactionSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePaidGroupCallReactionSend");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

starTransactionTypePaidGroupCallReactionReceive::starTransactionTypePaidGroupCallReactionReceive()
  : sender_id_()
  , commission_per_mille_()
  , commission_star_amount_()
{}

starTransactionTypePaidGroupCallReactionReceive::starTransactionTypePaidGroupCallReactionReceive(object_ptr<MessageSender> &&sender_id_, int32 commission_per_mille_, object_ptr<starAmount> &&commission_star_amount_)
  : sender_id_(std::move(sender_id_))
  , commission_per_mille_(commission_per_mille_)
  , commission_star_amount_(std::move(commission_star_amount_))
{}

const std::int32_t starTransactionTypePaidGroupCallReactionReceive::ID;

void starTransactionTypePaidGroupCallReactionReceive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePaidGroupCallReactionReceive");
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("commission_per_mille", commission_per_mille_);
    s.store_object_field("commission_star_amount", static_cast<const BaseObject *>(commission_star_amount_.get()));
    s.store_class_end();
  }
}

starTransactionTypeSuggestedPostPaymentSend::starTransactionTypeSuggestedPostPaymentSend()
  : chat_id_()
{}

starTransactionTypeSuggestedPostPaymentSend::starTransactionTypeSuggestedPostPaymentSend(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t starTransactionTypeSuggestedPostPaymentSend::ID;

void starTransactionTypeSuggestedPostPaymentSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeSuggestedPostPaymentSend");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

starTransactionTypeSuggestedPostPaymentReceive::starTransactionTypeSuggestedPostPaymentReceive()
  : user_id_()
{}

starTransactionTypeSuggestedPostPaymentReceive::starTransactionTypeSuggestedPostPaymentReceive(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t starTransactionTypeSuggestedPostPaymentReceive::ID;

void starTransactionTypeSuggestedPostPaymentReceive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeSuggestedPostPaymentReceive");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

starTransactionTypePremiumPurchase::starTransactionTypePremiumPurchase()
  : user_id_()
  , month_count_()
  , sticker_()
{}

starTransactionTypePremiumPurchase::starTransactionTypePremiumPurchase(int53 user_id_, int32 month_count_, object_ptr<sticker> &&sticker_)
  : user_id_(user_id_)
  , month_count_(month_count_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t starTransactionTypePremiumPurchase::ID;

void starTransactionTypePremiumPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePremiumPurchase");
    s.store_field("user_id", user_id_);
    s.store_field("month_count", month_count_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

starTransactionTypeBusinessBotTransferSend::starTransactionTypeBusinessBotTransferSend()
  : user_id_()
{}

starTransactionTypeBusinessBotTransferSend::starTransactionTypeBusinessBotTransferSend(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t starTransactionTypeBusinessBotTransferSend::ID;

void starTransactionTypeBusinessBotTransferSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBusinessBotTransferSend");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

starTransactionTypeBusinessBotTransferReceive::starTransactionTypeBusinessBotTransferReceive()
  : user_id_()
{}

starTransactionTypeBusinessBotTransferReceive::starTransactionTypeBusinessBotTransferReceive(int53 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t starTransactionTypeBusinessBotTransferReceive::ID;

void starTransactionTypeBusinessBotTransferReceive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeBusinessBotTransferReceive");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

starTransactionTypePublicPostSearch::starTransactionTypePublicPostSearch() {
}

const std::int32_t starTransactionTypePublicPostSearch::ID;

void starTransactionTypePublicPostSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypePublicPostSearch");
    s.store_class_end();
  }
}

starTransactionTypeUnsupported::starTransactionTypeUnsupported() {
}

const std::int32_t starTransactionTypeUnsupported::ID;

void starTransactionTypeUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starTransactionTypeUnsupported");
    s.store_class_end();
  }
}

stickerSets::stickerSets()
  : total_count_()
  , sets_()
{}

stickerSets::stickerSets(int32 total_count_, array<object_ptr<stickerSetInfo>> &&sets_)
  : total_count_(total_count_)
  , sets_(std::move(sets_))
{}

const std::int32_t stickerSets::ID;

void stickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSets");
    s.store_field("total_count", total_count_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyContentTypePhoto::storyContentTypePhoto() {
}

const std::int32_t storyContentTypePhoto::ID;

void storyContentTypePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentTypePhoto");
    s.store_class_end();
  }
}

storyContentTypeVideo::storyContentTypeVideo() {
}

const std::int32_t storyContentTypeVideo::ID;

void storyContentTypeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentTypeVideo");
    s.store_class_end();
  }
}

storyContentTypeLive::storyContentTypeLive() {
}

const std::int32_t storyContentTypeLive::ID;

void storyContentTypeLive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentTypeLive");
    s.store_class_end();
  }
}

storyContentTypeUnsupported::storyContentTypeUnsupported() {
}

const std::int32_t storyContentTypeUnsupported::ID;

void storyContentTypeUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyContentTypeUnsupported");
    s.store_class_end();
  }
}

storyInteraction::storyInteraction()
  : actor_id_()
  , interaction_date_()
  , block_list_()
  , type_()
{}

storyInteraction::storyInteraction(object_ptr<MessageSender> &&actor_id_, int32 interaction_date_, object_ptr<BlockList> &&block_list_, object_ptr<StoryInteractionType> &&type_)
  : actor_id_(std::move(actor_id_))
  , interaction_date_(interaction_date_)
  , block_list_(std::move(block_list_))
  , type_(std::move(type_))
{}

const std::int32_t storyInteraction::ID;

void storyInteraction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyInteraction");
    s.store_object_field("actor_id", static_cast<const BaseObject *>(actor_id_.get()));
    s.store_field("interaction_date", interaction_date_);
    s.store_object_field("block_list", static_cast<const BaseObject *>(block_list_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

storyPrivacySettingsEveryone::storyPrivacySettingsEveryone()
  : except_user_ids_()
{}

storyPrivacySettingsEveryone::storyPrivacySettingsEveryone(array<int53> &&except_user_ids_)
  : except_user_ids_(std::move(except_user_ids_))
{}

const std::int32_t storyPrivacySettingsEveryone::ID;

void storyPrivacySettingsEveryone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyPrivacySettingsEveryone");
    { s.store_vector_begin("except_user_ids", except_user_ids_.size()); for (const auto &_value : except_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyPrivacySettingsContacts::storyPrivacySettingsContacts()
  : except_user_ids_()
{}

storyPrivacySettingsContacts::storyPrivacySettingsContacts(array<int53> &&except_user_ids_)
  : except_user_ids_(std::move(except_user_ids_))
{}

const std::int32_t storyPrivacySettingsContacts::ID;

void storyPrivacySettingsContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyPrivacySettingsContacts");
    { s.store_vector_begin("except_user_ids", except_user_ids_.size()); for (const auto &_value : except_user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyPrivacySettingsCloseFriends::storyPrivacySettingsCloseFriends() {
}

const std::int32_t storyPrivacySettingsCloseFriends::ID;

void storyPrivacySettingsCloseFriends::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyPrivacySettingsCloseFriends");
    s.store_class_end();
  }
}

storyPrivacySettingsSelectedUsers::storyPrivacySettingsSelectedUsers()
  : user_ids_()
{}

storyPrivacySettingsSelectedUsers::storyPrivacySettingsSelectedUsers(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t storyPrivacySettingsSelectedUsers::ID;

void storyPrivacySettingsSelectedUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyPrivacySettingsSelectedUsers");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

suggestedPostStatePending::suggestedPostStatePending() {
}

const std::int32_t suggestedPostStatePending::ID;

void suggestedPostStatePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostStatePending");
    s.store_class_end();
  }
}

suggestedPostStateApproved::suggestedPostStateApproved() {
}

const std::int32_t suggestedPostStateApproved::ID;

void suggestedPostStateApproved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostStateApproved");
    s.store_class_end();
  }
}

suggestedPostStateDeclined::suggestedPostStateDeclined() {
}

const std::int32_t suggestedPostStateDeclined::ID;

void suggestedPostStateDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPostStateDeclined");
    s.store_class_end();
  }
}

telegramPaymentPurposePremiumGift::telegramPaymentPurposePremiumGift()
  : currency_()
  , amount_()
  , user_id_()
  , month_count_()
  , text_()
{}

telegramPaymentPurposePremiumGift::telegramPaymentPurposePremiumGift(string const &currency_, int53 amount_, int53 user_id_, int32 month_count_, object_ptr<formattedText> &&text_)
  : currency_(currency_)
  , amount_(amount_)
  , user_id_(user_id_)
  , month_count_(month_count_)
  , text_(std::move(text_))
{}

const std::int32_t telegramPaymentPurposePremiumGift::ID;

void telegramPaymentPurposePremiumGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposePremiumGift");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("user_id", user_id_);
    s.store_field("month_count", month_count_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

telegramPaymentPurposePremiumGiftCodes::telegramPaymentPurposePremiumGiftCodes()
  : boosted_chat_id_()
  , currency_()
  , amount_()
  , user_ids_()
  , month_count_()
  , text_()
{}

telegramPaymentPurposePremiumGiftCodes::telegramPaymentPurposePremiumGiftCodes(int53 boosted_chat_id_, string const &currency_, int53 amount_, array<int53> &&user_ids_, int32 month_count_, object_ptr<formattedText> &&text_)
  : boosted_chat_id_(boosted_chat_id_)
  , currency_(currency_)
  , amount_(amount_)
  , user_ids_(std::move(user_ids_))
  , month_count_(month_count_)
  , text_(std::move(text_))
{}

const std::int32_t telegramPaymentPurposePremiumGiftCodes::ID;

void telegramPaymentPurposePremiumGiftCodes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposePremiumGiftCodes");
    s.store_field("boosted_chat_id", boosted_chat_id_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("month_count", month_count_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

telegramPaymentPurposePremiumGiveaway::telegramPaymentPurposePremiumGiveaway()
  : parameters_()
  , currency_()
  , amount_()
  , winner_count_()
  , month_count_()
{}

telegramPaymentPurposePremiumGiveaway::telegramPaymentPurposePremiumGiveaway(object_ptr<giveawayParameters> &&parameters_, string const &currency_, int53 amount_, int32 winner_count_, int32 month_count_)
  : parameters_(std::move(parameters_))
  , currency_(currency_)
  , amount_(amount_)
  , winner_count_(winner_count_)
  , month_count_(month_count_)
{}

const std::int32_t telegramPaymentPurposePremiumGiveaway::ID;

void telegramPaymentPurposePremiumGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposePremiumGiveaway");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("winner_count", winner_count_);
    s.store_field("month_count", month_count_);
    s.store_class_end();
  }
}

telegramPaymentPurposeStars::telegramPaymentPurposeStars()
  : currency_()
  , amount_()
  , star_count_()
  , chat_id_()
{}

telegramPaymentPurposeStars::telegramPaymentPurposeStars(string const &currency_, int53 amount_, int53 star_count_, int53 chat_id_)
  : currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
  , chat_id_(chat_id_)
{}

const std::int32_t telegramPaymentPurposeStars::ID;

void telegramPaymentPurposeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposeStars");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

telegramPaymentPurposeGiftedStars::telegramPaymentPurposeGiftedStars()
  : user_id_()
  , currency_()
  , amount_()
  , star_count_()
{}

telegramPaymentPurposeGiftedStars::telegramPaymentPurposeGiftedStars(int53 user_id_, string const &currency_, int53 amount_, int53 star_count_)
  : user_id_(user_id_)
  , currency_(currency_)
  , amount_(amount_)
  , star_count_(star_count_)
{}

const std::int32_t telegramPaymentPurposeGiftedStars::ID;

void telegramPaymentPurposeGiftedStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposeGiftedStars");
    s.store_field("user_id", user_id_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

telegramPaymentPurposeStarGiveaway::telegramPaymentPurposeStarGiveaway()
  : parameters_()
  , currency_()
  , amount_()
  , winner_count_()
  , star_count_()
{}

telegramPaymentPurposeStarGiveaway::telegramPaymentPurposeStarGiveaway(object_ptr<giveawayParameters> &&parameters_, string const &currency_, int53 amount_, int32 winner_count_, int53 star_count_)
  : parameters_(std::move(parameters_))
  , currency_(currency_)
  , amount_(amount_)
  , winner_count_(winner_count_)
  , star_count_(star_count_)
{}

const std::int32_t telegramPaymentPurposeStarGiveaway::ID;

void telegramPaymentPurposeStarGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposeStarGiveaway");
    s.store_object_field("parameters", static_cast<const BaseObject *>(parameters_.get()));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("winner_count", winner_count_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

telegramPaymentPurposeJoinChat::telegramPaymentPurposeJoinChat()
  : invite_link_()
{}

telegramPaymentPurposeJoinChat::telegramPaymentPurposeJoinChat(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t telegramPaymentPurposeJoinChat::ID;

void telegramPaymentPurposeJoinChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "telegramPaymentPurposeJoinChat");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

testVectorInt::testVectorInt()
  : value_()
{}

testVectorInt::testVectorInt(array<int32> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t testVectorInt::ID;

void testVectorInt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testVectorInt");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

testVectorString::testVectorString()
  : value_()
{}

testVectorString::testVectorString(array<string> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t testVectorString::ID;

void testVectorString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "testVectorString");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

themeParameters::themeParameters()
  : background_color_()
  , secondary_background_color_()
  , header_background_color_()
  , bottom_bar_background_color_()
  , section_background_color_()
  , section_separator_color_()
  , text_color_()
  , accent_text_color_()
  , section_header_text_color_()
  , subtitle_text_color_()
  , destructive_text_color_()
  , hint_color_()
  , link_color_()
  , button_color_()
  , button_text_color_()
{}

themeParameters::themeParameters(int32 background_color_, int32 secondary_background_color_, int32 header_background_color_, int32 bottom_bar_background_color_, int32 section_background_color_, int32 section_separator_color_, int32 text_color_, int32 accent_text_color_, int32 section_header_text_color_, int32 subtitle_text_color_, int32 destructive_text_color_, int32 hint_color_, int32 link_color_, int32 button_color_, int32 button_text_color_)
  : background_color_(background_color_)
  , secondary_background_color_(secondary_background_color_)
  , header_background_color_(header_background_color_)
  , bottom_bar_background_color_(bottom_bar_background_color_)
  , section_background_color_(section_background_color_)
  , section_separator_color_(section_separator_color_)
  , text_color_(text_color_)
  , accent_text_color_(accent_text_color_)
  , section_header_text_color_(section_header_text_color_)
  , subtitle_text_color_(subtitle_text_color_)
  , destructive_text_color_(destructive_text_color_)
  , hint_color_(hint_color_)
  , link_color_(link_color_)
  , button_color_(button_color_)
  , button_text_color_(button_text_color_)
{}

const std::int32_t themeParameters::ID;

void themeParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "themeParameters");
    s.store_field("background_color", background_color_);
    s.store_field("secondary_background_color", secondary_background_color_);
    s.store_field("header_background_color", header_background_color_);
    s.store_field("bottom_bar_background_color", bottom_bar_background_color_);
    s.store_field("section_background_color", section_background_color_);
    s.store_field("section_separator_color", section_separator_color_);
    s.store_field("text_color", text_color_);
    s.store_field("accent_text_color", accent_text_color_);
    s.store_field("section_header_text_color", section_header_text_color_);
    s.store_field("subtitle_text_color", subtitle_text_color_);
    s.store_field("destructive_text_color", destructive_text_color_);
    s.store_field("hint_color", hint_color_);
    s.store_field("link_color", link_color_);
    s.store_field("button_color", button_color_);
    s.store_field("button_text_color", button_text_color_);
    s.store_class_end();
  }
}

unconfirmedSession::unconfirmedSession()
  : id_()
  , log_in_date_()
  , device_model_()
  , location_()
{}

unconfirmedSession::unconfirmedSession(int64 id_, int32 log_in_date_, string const &device_model_, string const &location_)
  : id_(id_)
  , log_in_date_(log_in_date_)
  , device_model_(device_model_)
  , location_(location_)
{}

const std::int32_t unconfirmedSession::ID;

void unconfirmedSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "unconfirmedSession");
    s.store_field("id", id_);
    s.store_field("log_in_date", log_in_date_);
    s.store_field("device_model", device_model_);
    s.store_field("location", location_);
    s.store_class_end();
  }
}

upgradeGiftResult::upgradeGiftResult()
  : gift_()
  , received_gift_id_()
  , is_saved_()
  , can_be_transferred_()
  , transfer_star_count_()
  , drop_original_details_star_count_()
  , next_transfer_date_()
  , next_resale_date_()
  , export_date_()
{}

upgradeGiftResult::upgradeGiftResult(object_ptr<upgradedGift> &&gift_, string const &received_gift_id_, bool is_saved_, bool can_be_transferred_, int53 transfer_star_count_, int53 drop_original_details_star_count_, int32 next_transfer_date_, int32 next_resale_date_, int32 export_date_)
  : gift_(std::move(gift_))
  , received_gift_id_(received_gift_id_)
  , is_saved_(is_saved_)
  , can_be_transferred_(can_be_transferred_)
  , transfer_star_count_(transfer_star_count_)
  , drop_original_details_star_count_(drop_original_details_star_count_)
  , next_transfer_date_(next_transfer_date_)
  , next_resale_date_(next_resale_date_)
  , export_date_(export_date_)
{}

const std::int32_t upgradeGiftResult::ID;

void upgradeGiftResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradeGiftResult");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("received_gift_id", received_gift_id_);
    s.store_field("is_saved", is_saved_);
    s.store_field("can_be_transferred", can_be_transferred_);
    s.store_field("transfer_star_count", transfer_star_count_);
    s.store_field("drop_original_details_star_count", drop_original_details_star_count_);
    s.store_field("next_transfer_date", next_transfer_date_);
    s.store_field("next_resale_date", next_resale_date_);
    s.store_field("export_date", export_date_);
    s.store_class_end();
  }
}

upgradedGiftSymbolCount::upgradedGiftSymbolCount()
  : symbol_()
  , total_count_()
{}

upgradedGiftSymbolCount::upgradedGiftSymbolCount(object_ptr<upgradedGiftSymbol> &&symbol_, int32 total_count_)
  : symbol_(std::move(symbol_))
  , total_count_(total_count_)
{}

const std::int32_t upgradedGiftSymbolCount::ID;

void upgradedGiftSymbolCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upgradedGiftSymbolCount");
    s.store_object_field("symbol", static_cast<const BaseObject *>(symbol_.get()));
    s.store_field("total_count", total_count_);
    s.store_class_end();
  }
}

userLink::userLink()
  : url_()
  , expires_in_()
{}

userLink::userLink(string const &url_, int32 expires_in_)
  : url_(url_)
  , expires_in_(expires_in_)
{}

const std::int32_t userLink::ID;

void userLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userLink");
    s.store_field("url", url_);
    s.store_field("expires_in", expires_in_);
    s.store_class_end();
  }
}

userSupportInfo::userSupportInfo()
  : message_()
  , author_()
  , date_()
{}

userSupportInfo::userSupportInfo(object_ptr<formattedText> &&message_, string const &author_, int32 date_)
  : message_(std::move(message_))
  , author_(author_)
  , date_(date_)
{}

const std::int32_t userSupportInfo::ID;

void userSupportInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userSupportInfo");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("author", author_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

webApp::webApp()
  : short_name_()
  , title_()
  , description_()
  , photo_()
  , animation_()
{}

webApp::webApp(string const &short_name_, string const &title_, string const &description_, object_ptr<photo> &&photo_, object_ptr<animation> &&animation_)
  : short_name_(short_name_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , animation_(std::move(animation_))
{}

const std::int32_t webApp::ID;

void webApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webApp");
    s.store_field("short_name", short_name_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("animation", static_cast<const BaseObject *>(animation_.get()));
    s.store_class_end();
  }
}

webAppOpenModeCompact::webAppOpenModeCompact() {
}

const std::int32_t webAppOpenModeCompact::ID;

void webAppOpenModeCompact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAppOpenModeCompact");
    s.store_class_end();
  }
}

webAppOpenModeFullSize::webAppOpenModeFullSize() {
}

const std::int32_t webAppOpenModeFullSize::ID;

void webAppOpenModeFullSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAppOpenModeFullSize");
    s.store_class_end();
  }
}

webAppOpenModeFullScreen::webAppOpenModeFullScreen() {
}

const std::int32_t webAppOpenModeFullScreen::ID;

void webAppOpenModeFullScreen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAppOpenModeFullScreen");
    s.store_class_end();
  }
}

addPendingLiveStoryReaction::addPendingLiveStoryReaction()
  : group_call_id_()
  , star_count_()
{}

addPendingLiveStoryReaction::addPendingLiveStoryReaction(int32 group_call_id_, int53 star_count_)
  : group_call_id_(group_call_id_)
  , star_count_(star_count_)
{}

const std::int32_t addPendingLiveStoryReaction::ID;

void addPendingLiveStoryReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addPendingLiveStoryReaction");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

addPollOption::addPollOption()
  : chat_id_()
  , message_id_()
  , option_()
{}

addPollOption::addPollOption(int53 chat_id_, int53 message_id_, object_ptr<inputPollOption> &&option_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , option_(std::move(option_))
{}

const std::int32_t addPollOption::ID;

void addPollOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "addPollOption");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("option", static_cast<const BaseObject *>(option_.get()));
    s.store_class_end();
  }
}

buyGiftUpgrade::buyGiftUpgrade()
  : owner_id_()
  , prepaid_upgrade_hash_()
  , star_count_()
{}

buyGiftUpgrade::buyGiftUpgrade(object_ptr<MessageSender> &&owner_id_, string const &prepaid_upgrade_hash_, int53 star_count_)
  : owner_id_(std::move(owner_id_))
  , prepaid_upgrade_hash_(prepaid_upgrade_hash_)
  , star_count_(star_count_)
{}

const std::int32_t buyGiftUpgrade::ID;

void buyGiftUpgrade::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "buyGiftUpgrade");
    s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get()));
    s.store_field("prepaid_upgrade_hash", prepaid_upgrade_hash_);
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

checkAuthenticationPremiumPurchase::checkAuthenticationPremiumPurchase()
  : currency_()
  , amount_()
{}

checkAuthenticationPremiumPurchase::checkAuthenticationPremiumPurchase(string const &currency_, int53 amount_)
  : currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t checkAuthenticationPremiumPurchase::ID;

void checkAuthenticationPremiumPurchase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "checkAuthenticationPremiumPurchase");
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

clearRecentEmojiStatuses::clearRecentEmojiStatuses() {
}

const std::int32_t clearRecentEmojiStatuses::ID;

void clearRecentEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearRecentEmojiStatuses");
    s.store_class_end();
  }
}

clearSearchedForTags::clearSearchedForTags()
  : clear_cashtags_()
{}

clearSearchedForTags::clearSearchedForTags(bool clear_cashtags_)
  : clear_cashtags_(clear_cashtags_)
{}

const std::int32_t clearSearchedForTags::ID;

void clearSearchedForTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clearSearchedForTags");
    s.store_field("clear_cashtags", clear_cashtags_);
    s.store_class_end();
  }
}

clickAnimatedEmojiMessage::clickAnimatedEmojiMessage()
  : chat_id_()
  , message_id_()
{}

clickAnimatedEmojiMessage::clickAnimatedEmojiMessage(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t clickAnimatedEmojiMessage::ID;

void clickAnimatedEmojiMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "clickAnimatedEmojiMessage");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

close::close() {
}

const std::int32_t close::ID;

void close::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "close");
    s.store_class_end();
  }
}

closeStory::closeStory()
  : story_poster_chat_id_()
  , story_id_()
{}

closeStory::closeStory(int53 story_poster_chat_id_, int32 story_id_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
{}

const std::int32_t closeStory::ID;

void closeStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "closeStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

confirmQrCodeAuthentication::confirmQrCodeAuthentication()
  : link_()
{}

confirmQrCodeAuthentication::confirmQrCodeAuthentication(string const &link_)
  : link_(link_)
{}

const std::int32_t confirmQrCodeAuthentication::ID;

void confirmQrCodeAuthentication::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "confirmQrCodeAuthentication");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

createChatFolderInviteLink::createChatFolderInviteLink()
  : chat_folder_id_()
  , name_()
  , chat_ids_()
{}

createChatFolderInviteLink::createChatFolderInviteLink(int32 chat_folder_id_, string const &name_, array<int53> &&chat_ids_)
  : chat_folder_id_(chat_folder_id_)
  , name_(name_)
  , chat_ids_(std::move(chat_ids_))
{}

const std::int32_t createChatFolderInviteLink::ID;

void createChatFolderInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createChatFolderInviteLink");
    s.store_field("chat_folder_id", chat_folder_id_);
    s.store_field("name", name_);
    { s.store_vector_begin("chat_ids", chat_ids_.size()); for (const auto &_value : chat_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

createForumTopic::createForumTopic()
  : chat_id_()
  , name_()
  , is_name_implicit_()
  , icon_()
{}

createForumTopic::createForumTopic(int53 chat_id_, string const &name_, bool is_name_implicit_, object_ptr<forumTopicIcon> &&icon_)
  : chat_id_(chat_id_)
  , name_(name_)
  , is_name_implicit_(is_name_implicit_)
  , icon_(std::move(icon_))
{}

const std::int32_t createForumTopic::ID;

void createForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createForumTopic");
    s.store_field("chat_id", chat_id_);
    s.store_field("name", name_);
    s.store_field("is_name_implicit", is_name_implicit_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    s.store_class_end();
  }
}

createStoryAlbum::createStoryAlbum()
  : story_poster_chat_id_()
  , name_()
  , story_ids_()
{}

createStoryAlbum::createStoryAlbum(int53 story_poster_chat_id_, string const &name_, array<int32> &&story_ids_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , name_(name_)
  , story_ids_(std::move(story_ids_))
{}

const std::int32_t createStoryAlbum::ID;

void createStoryAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "createStoryAlbum");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("name", name_);
    { s.store_vector_begin("story_ids", story_ids_.size()); for (const auto &_value : story_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

declineGroupCallInvitation::declineGroupCallInvitation()
  : chat_id_()
  , message_id_()
{}

declineGroupCallInvitation::declineGroupCallInvitation(int53 chat_id_, int53 message_id_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
{}

const std::int32_t declineGroupCallInvitation::ID;

void declineGroupCallInvitation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "declineGroupCallInvitation");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_class_end();
  }
}

deleteChatMessagesByDate::deleteChatMessagesByDate()
  : chat_id_()
  , min_date_()
  , max_date_()
  , revoke_()
{}

deleteChatMessagesByDate::deleteChatMessagesByDate(int53 chat_id_, int32 min_date_, int32 max_date_, bool revoke_)
  : chat_id_(chat_id_)
  , min_date_(min_date_)
  , max_date_(max_date_)
  , revoke_(revoke_)
{}

const std::int32_t deleteChatMessagesByDate::ID;

void deleteChatMessagesByDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteChatMessagesByDate");
    s.store_field("chat_id", chat_id_);
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

deleteGroupCallMessagesBySender::deleteGroupCallMessagesBySender()
  : group_call_id_()
  , sender_id_()
  , report_spam_()
{}

deleteGroupCallMessagesBySender::deleteGroupCallMessagesBySender(int32 group_call_id_, object_ptr<MessageSender> &&sender_id_, bool report_spam_)
  : group_call_id_(group_call_id_)
  , sender_id_(std::move(sender_id_))
  , report_spam_(report_spam_)
{}

const std::int32_t deleteGroupCallMessagesBySender::ID;

void deleteGroupCallMessagesBySender::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteGroupCallMessagesBySender");
    s.store_field("group_call_id", group_call_id_);
    s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get()));
    s.store_field("report_spam", report_spam_);
    s.store_class_end();
  }
}

deleteRevokedChatInviteLink::deleteRevokedChatInviteLink()
  : chat_id_()
  , invite_link_()
{}

deleteRevokedChatInviteLink::deleteRevokedChatInviteLink(int53 chat_id_, string const &invite_link_)
  : chat_id_(chat_id_)
  , invite_link_(invite_link_)
{}

const std::int32_t deleteRevokedChatInviteLink::ID;

void deleteRevokedChatInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "deleteRevokedChatInviteLink");
    s.store_field("chat_id", chat_id_);
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

editBotMediaPreview::editBotMediaPreview()
  : bot_user_id_()
  , language_code_()
  , file_id_()
  , content_()
{}

editBotMediaPreview::editBotMediaPreview(int53 bot_user_id_, string const &language_code_, int32 file_id_, object_ptr<InputStoryContent> &&content_)
  : bot_user_id_(bot_user_id_)
  , language_code_(language_code_)
  , file_id_(file_id_)
  , content_(std::move(content_))
{}

const std::int32_t editBotMediaPreview::ID;

void editBotMediaPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBotMediaPreview");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_field("language_code", language_code_);
    s.store_field("file_id", file_id_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_class_end();
  }
}

editBusinessStory::editBusinessStory()
  : story_poster_chat_id_()
  , story_id_()
  , content_()
  , areas_()
  , caption_()
  , privacy_settings_()
{}

editBusinessStory::editBusinessStory(int53 story_poster_chat_id_, int32 story_id_, object_ptr<InputStoryContent> &&content_, object_ptr<inputStoryAreas> &&areas_, object_ptr<formattedText> &&caption_, object_ptr<StoryPrivacySettings> &&privacy_settings_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , content_(std::move(content_))
  , areas_(std::move(areas_))
  , caption_(std::move(caption_))
  , privacy_settings_(std::move(privacy_settings_))
{}

const std::int32_t editBusinessStory::ID;

void editBusinessStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editBusinessStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_object_field("content", static_cast<const BaseObject *>(content_.get()));
    s.store_object_field("areas", static_cast<const BaseObject *>(areas_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_object_field("privacy_settings", static_cast<const BaseObject *>(privacy_settings_.get()));
    s.store_class_end();
  }
}

editInlineMessageMedia::editInlineMessageMedia()
  : inline_message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editInlineMessageMedia::editInlineMessageMedia(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editInlineMessageMedia::ID;

void editInlineMessageMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageMedia");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editInlineMessageReplyMarkup::editInlineMessageReplyMarkup()
  : inline_message_id_()
  , reply_markup_()
{}

editInlineMessageReplyMarkup::editInlineMessageReplyMarkup(string const &inline_message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : inline_message_id_(inline_message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t editInlineMessageReplyMarkup::ID;

void editInlineMessageReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editInlineMessageReplyMarkup");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

editMessageReplyMarkup::editMessageReplyMarkup()
  : chat_id_()
  , message_id_()
  , reply_markup_()
{}

editMessageReplyMarkup::editMessageReplyMarkup(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t editMessageReplyMarkup::ID;

void editMessageReplyMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageReplyMarkup");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_class_end();
  }
}

editMessageText::editMessageText()
  : chat_id_()
  , message_id_()
  , reply_markup_()
  , input_message_content_()
{}

editMessageText::editMessageText(int53 chat_id_, int53 message_id_, object_ptr<ReplyMarkup> &&reply_markup_, object_ptr<InputMessageContent> &&input_message_content_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reply_markup_(std::move(reply_markup_))
  , input_message_content_(std::move(input_message_content_))
{}

const std::int32_t editMessageText::ID;

void editMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editMessageText");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get()));
    s.store_object_field("input_message_content", static_cast<const BaseObject *>(input_message_content_.get()));
    s.store_class_end();
  }
}

editStarSubscription::editStarSubscription()
  : subscription_id_()
  , is_canceled_()
{}

editStarSubscription::editStarSubscription(string const &subscription_id_, bool is_canceled_)
  : subscription_id_(subscription_id_)
  , is_canceled_(is_canceled_)
{}

const std::int32_t editStarSubscription::ID;

void editStarSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "editStarSubscription");
    s.store_field("subscription_id", subscription_id_);
    s.store_field("is_canceled", is_canceled_);
    s.store_class_end();
  }
}

endGroupCallRecording::endGroupCallRecording()
  : group_call_id_()
{}

endGroupCallRecording::endGroupCallRecording(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t endGroupCallRecording::ID;

void endGroupCallRecording::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "endGroupCallRecording");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

getApplicationConfig::getApplicationConfig() {
}

const std::int32_t getApplicationConfig::ID;

void getApplicationConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getApplicationConfig");
    s.store_class_end();
  }
}

getChatActiveStories::getChatActiveStories()
  : chat_id_()
{}

getChatActiveStories::getChatActiveStories(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatActiveStories::ID;

void getChatActiveStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatActiveStories");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatAdministrators::getChatAdministrators()
  : chat_id_()
{}

getChatAdministrators::getChatAdministrators(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatAdministrators::ID;

void getChatAdministrators::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatAdministrators");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatBoostLinkInfo::getChatBoostLinkInfo()
  : url_()
{}

getChatBoostLinkInfo::getChatBoostLinkInfo(string const &url_)
  : url_(url_)
{}

const std::int32_t getChatBoostLinkInfo::ID;

void getChatBoostLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatBoostLinkInfo");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

getChatInviteLinkCounts::getChatInviteLinkCounts()
  : chat_id_()
{}

getChatInviteLinkCounts::getChatInviteLinkCounts(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t getChatInviteLinkCounts::ID;

void getChatInviteLinkCounts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatInviteLinkCounts");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

getChatRevenueWithdrawalUrl::getChatRevenueWithdrawalUrl()
  : chat_id_()
  , password_()
{}

getChatRevenueWithdrawalUrl::getChatRevenueWithdrawalUrl(int53 chat_id_, string const &password_)
  : chat_id_(chat_id_)
  , password_(password_)
{}

const std::int32_t getChatRevenueWithdrawalUrl::ID;

void getChatRevenueWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatRevenueWithdrawalUrl");
    s.store_field("chat_id", chat_id_);
    s.store_field("password", password_);
    s.store_class_end();
  }
}

getChats::getChats()
  : chat_list_()
  , limit_()
{}

getChats::getChats(object_ptr<ChatList> &&chat_list_, int32 limit_)
  : chat_list_(std::move(chat_list_))
  , limit_(limit_)
{}

const std::int32_t getChats::ID;

void getChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChats");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getChatsToPostStories::getChatsToPostStories() {
}

const std::int32_t getChatsToPostStories::ID;

void getChatsToPostStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getChatsToPostStories");
    s.store_class_end();
  }
}

getCurrentState::getCurrentState() {
}

const std::int32_t getCurrentState::ID;

void getCurrentState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCurrentState");
    s.store_class_end();
  }
}

getCustomEmojiStickers::getCustomEmojiStickers()
  : custom_emoji_ids_()
{}

getCustomEmojiStickers::getCustomEmojiStickers(array<int64> &&custom_emoji_ids_)
  : custom_emoji_ids_(std::move(custom_emoji_ids_))
{}

const std::int32_t getCustomEmojiStickers::ID;

void getCustomEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getCustomEmojiStickers");
    { s.store_vector_begin("custom_emoji_ids", custom_emoji_ids_.size()); for (const auto &_value : custom_emoji_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getInactiveSupergroupChats::getInactiveSupergroupChats() {
}

const std::int32_t getInactiveSupergroupChats::ID;

void getInactiveSupergroupChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInactiveSupergroupChats");
    s.store_class_end();
  }
}

getInlineGameHighScores::getInlineGameHighScores()
  : inline_message_id_()
  , user_id_()
{}

getInlineGameHighScores::getInlineGameHighScores(string const &inline_message_id_, int53 user_id_)
  : inline_message_id_(inline_message_id_)
  , user_id_(user_id_)
{}

const std::int32_t getInlineGameHighScores::ID;

void getInlineGameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInlineGameHighScores");
    s.store_field("inline_message_id", inline_message_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

getInstalledBackgrounds::getInstalledBackgrounds()
  : for_dark_theme_()
{}

getInstalledBackgrounds::getInstalledBackgrounds(bool for_dark_theme_)
  : for_dark_theme_(for_dark_theme_)
{}

const std::int32_t getInstalledBackgrounds::ID;

void getInstalledBackgrounds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getInstalledBackgrounds");
    s.store_field("for_dark_theme", for_dark_theme_);
    s.store_class_end();
  }
}

getKeywordEmojis::getKeywordEmojis()
  : text_()
  , input_language_codes_()
{}

getKeywordEmojis::getKeywordEmojis(string const &text_, array<string> &&input_language_codes_)
  : text_(text_)
  , input_language_codes_(std::move(input_language_codes_))
{}

const std::int32_t getKeywordEmojis::ID;

void getKeywordEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getKeywordEmojis");
    s.store_field("text", text_);
    { s.store_vector_begin("input_language_codes", input_language_codes_.size()); for (const auto &_value : input_language_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

getLoginUrl::getLoginUrl()
  : chat_id_()
  , message_id_()
  , button_id_()
  , allow_write_access_()
{}

getLoginUrl::getLoginUrl(int53 chat_id_, int53 message_id_, int53 button_id_, bool allow_write_access_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , button_id_(button_id_)
  , allow_write_access_(allow_write_access_)
{}

const std::int32_t getLoginUrl::ID;

void getLoginUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getLoginUrl");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("button_id", button_id_);
    s.store_field("allow_write_access", allow_write_access_);
    s.store_class_end();
  }
}

getMarkdownText::getMarkdownText()
  : text_()
{}

getMarkdownText::getMarkdownText(object_ptr<formattedText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t getMarkdownText::ID;

void getMarkdownText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMarkdownText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

getMessageAddedReactions::getMessageAddedReactions()
  : chat_id_()
  , message_id_()
  , reaction_type_()
  , offset_()
  , limit_()
{}

getMessageAddedReactions::getMessageAddedReactions(int53 chat_id_, int53 message_id_, object_ptr<ReactionType> &&reaction_type_, string const &offset_, int32 limit_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , reaction_type_(std::move(reaction_type_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t getMessageAddedReactions::ID;

void getMessageAddedReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageAddedReactions");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getMessageStatistics::getMessageStatistics()
  : chat_id_()
  , message_id_()
  , is_dark_()
{}

getMessageStatistics::getMessageStatistics(int53 chat_id_, int53 message_id_, bool is_dark_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , is_dark_(is_dark_)
{}

const std::int32_t getMessageStatistics::ID;

void getMessageStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getMessageStatistics");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getPushReceiverId::getPushReceiverId()
  : payload_()
{}

getPushReceiverId::getPushReceiverId(string const &payload_)
  : payload_(payload_)
{}

const std::int32_t getPushReceiverId::ID;

void getPushReceiverId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getPushReceiverId");
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

getRemoteFile::getRemoteFile()
  : remote_file_id_()
  , file_type_()
{}

getRemoteFile::getRemoteFile(string const &remote_file_id_, object_ptr<FileType> &&file_type_)
  : remote_file_id_(remote_file_id_)
  , file_type_(std::move(file_type_))
{}

const std::int32_t getRemoteFile::ID;

void getRemoteFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getRemoteFile");
    s.store_field("remote_file_id", remote_file_id_);
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_class_end();
  }
}

getSavedAnimations::getSavedAnimations() {
}

const std::int32_t getSavedAnimations::ID;

void getSavedAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSavedAnimations");
    s.store_class_end();
  }
}

getSearchedForTags::getSearchedForTags()
  : tag_prefix_()
  , limit_()
{}

getSearchedForTags::getSearchedForTags(string const &tag_prefix_, int32 limit_)
  : tag_prefix_(tag_prefix_)
  , limit_(limit_)
{}

const std::int32_t getSearchedForTags::ID;

void getSearchedForTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSearchedForTags");
    s.store_field("tag_prefix", tag_prefix_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

getStarGiveawayPaymentOptions::getStarGiveawayPaymentOptions() {
}

const std::int32_t getStarGiveawayPaymentOptions::ID;

void getStarGiveawayPaymentOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarGiveawayPaymentOptions");
    s.store_class_end();
  }
}

getStarSubscriptions::getStarSubscriptions()
  : only_expiring_()
  , offset_()
{}

getStarSubscriptions::getStarSubscriptions(bool only_expiring_, string const &offset_)
  : only_expiring_(only_expiring_)
  , offset_(offset_)
{}

const std::int32_t getStarSubscriptions::ID;

void getStarSubscriptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStarSubscriptions");
    s.store_field("only_expiring", only_expiring_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

getStoryAvailableReactions::getStoryAvailableReactions()
  : row_size_()
{}

getStoryAvailableReactions::getStoryAvailableReactions(int32 row_size_)
  : row_size_(row_size_)
{}

const std::int32_t getStoryAvailableReactions::ID;

void getStoryAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStoryAvailableReactions");
    s.store_field("row_size", row_size_);
    s.store_class_end();
  }
}

getStoryStatistics::getStoryStatistics()
  : chat_id_()
  , story_id_()
  , is_dark_()
{}

getStoryStatistics::getStoryStatistics(int53 chat_id_, int32 story_id_, bool is_dark_)
  : chat_id_(chat_id_)
  , story_id_(story_id_)
  , is_dark_(is_dark_)
{}

const std::int32_t getStoryStatistics::ID;

void getStoryStatistics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getStoryStatistics");
    s.store_field("chat_id", chat_id_);
    s.store_field("story_id", story_id_);
    s.store_field("is_dark", is_dark_);
    s.store_class_end();
  }
}

getSuggestedStickerSetName::getSuggestedStickerSetName()
  : title_()
{}

getSuggestedStickerSetName::getSuggestedStickerSetName(string const &title_)
  : title_(title_)
{}

const std::int32_t getSuggestedStickerSetName::ID;

void getSuggestedStickerSetName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSuggestedStickerSetName");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

getSupportName::getSupportName() {
}

const std::int32_t getSupportName::ID;

void getSupportName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getSupportName");
    s.store_class_end();
  }
}

getThemedChatEmojiStatuses::getThemedChatEmojiStatuses() {
}

const std::int32_t getThemedChatEmojiStatuses::ID;

void getThemedChatEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getThemedChatEmojiStatuses");
    s.store_class_end();
  }
}

getUpgradedGiftWithdrawalUrl::getUpgradedGiftWithdrawalUrl()
  : received_gift_id_()
  , password_()
{}

getUpgradedGiftWithdrawalUrl::getUpgradedGiftWithdrawalUrl(string const &received_gift_id_, string const &password_)
  : received_gift_id_(received_gift_id_)
  , password_(password_)
{}

const std::int32_t getUpgradedGiftWithdrawalUrl::ID;

void getUpgradedGiftWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "getUpgradedGiftWithdrawalUrl");
    s.store_field("received_gift_id", received_gift_id_);
    s.store_field("password", password_);
    s.store_class_end();
  }
}

importContacts::importContacts()
  : contacts_()
{}

importContacts::importContacts(array<object_ptr<importedContact>> &&contacts_)
  : contacts_(std::move(contacts_))
{}

const std::int32_t importContacts::ID;

void importContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importContacts");
    { s.store_vector_begin("contacts", contacts_.size()); for (const auto &_value : contacts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

joinChatByInviteLink::joinChatByInviteLink()
  : invite_link_()
{}

joinChatByInviteLink::joinChatByInviteLink(string const &invite_link_)
  : invite_link_(invite_link_)
{}

const std::int32_t joinChatByInviteLink::ID;

void joinChatByInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "joinChatByInviteLink");
    s.store_field("invite_link", invite_link_);
    s.store_class_end();
  }
}

loadChats::loadChats()
  : chat_list_()
  , limit_()
{}

loadChats::loadChats(object_ptr<ChatList> &&chat_list_, int32 limit_)
  : chat_list_(std::move(chat_list_))
  , limit_(limit_)
{}

const std::int32_t loadChats::ID;

void loadChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "loadChats");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

openSponsoredChat::openSponsoredChat()
  : sponsored_chat_unique_id_()
{}

openSponsoredChat::openSponsoredChat(int53 sponsored_chat_unique_id_)
  : sponsored_chat_unique_id_(sponsored_chat_unique_id_)
{}

const std::int32_t openSponsoredChat::ID;

void openSponsoredChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "openSponsoredChat");
    s.store_field("sponsored_chat_unique_id", sponsored_chat_unique_id_);
    s.store_class_end();
  }
}

placeGiftAuctionBid::placeGiftAuctionBid()
  : gift_id_()
  , star_count_()
  , user_id_()
  , text_()
  , is_private_()
{}

placeGiftAuctionBid::placeGiftAuctionBid(int64 gift_id_, int53 star_count_, int53 user_id_, object_ptr<formattedText> &&text_, bool is_private_)
  : gift_id_(gift_id_)
  , star_count_(star_count_)
  , user_id_(user_id_)
  , text_(std::move(text_))
  , is_private_(is_private_)
{}

const std::int32_t placeGiftAuctionBid::ID;

void placeGiftAuctionBid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "placeGiftAuctionBid");
    s.store_field("gift_id", gift_id_);
    s.store_field("star_count", star_count_);
    s.store_field("user_id", user_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("is_private", is_private_);
    s.store_class_end();
  }
}

readAllChatPollVotes::readAllChatPollVotes()
  : chat_id_()
{}

readAllChatPollVotes::readAllChatPollVotes(int53 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t readAllChatPollVotes::ID;

void readAllChatPollVotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readAllChatPollVotes");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

removeSearchedForTag::removeSearchedForTag()
  : tag_()
{}

removeSearchedForTag::removeSearchedForTag(string const &tag_)
  : tag_(tag_)
{}

const std::int32_t removeSearchedForTag::ID;

void removeSearchedForTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "removeSearchedForTag");
    s.store_field("tag", tag_);
    s.store_class_end();
  }
}

reorderInstalledStickerSets::reorderInstalledStickerSets()
  : sticker_type_()
  , sticker_set_ids_()
{}

reorderInstalledStickerSets::reorderInstalledStickerSets(object_ptr<StickerType> &&sticker_type_, array<int64> &&sticker_set_ids_)
  : sticker_type_(std::move(sticker_type_))
  , sticker_set_ids_(std::move(sticker_set_ids_))
{}

const std::int32_t reorderInstalledStickerSets::ID;

void reorderInstalledStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reorderInstalledStickerSets");
    s.store_object_field("sticker_type", static_cast<const BaseObject *>(sticker_type_.get()));
    { s.store_vector_begin("sticker_set_ids", sticker_set_ids_.size()); for (const auto &_value : sticker_set_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportStory::reportStory()
  : story_poster_chat_id_()
  , story_id_()
  , option_id_()
  , text_()
{}

reportStory::reportStory(int53 story_poster_chat_id_, int32 story_id_, bytes const &option_id_, string const &text_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , option_id_(std::move(option_id_))
  , text_(text_)
{}

const std::int32_t reportStory::ID;

void reportStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportStory");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_bytes_field("option_id", option_id_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

revokeGroupCallInviteLink::revokeGroupCallInviteLink()
  : group_call_id_()
{}

revokeGroupCallInviteLink::revokeGroupCallInviteLink(int32 group_call_id_)
  : group_call_id_(group_call_id_)
{}

const std::int32_t revokeGroupCallInviteLink::ID;

void revokeGroupCallInviteLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "revokeGroupCallInviteLink");
    s.store_field("group_call_id", group_call_id_);
    s.store_class_end();
  }
}

savePreparedInlineMessage::savePreparedInlineMessage()
  : user_id_()
  , result_()
  , chat_types_()
{}

savePreparedInlineMessage::savePreparedInlineMessage(int53 user_id_, object_ptr<InputInlineQueryResult> &&result_, object_ptr<targetChatTypes> &&chat_types_)
  : user_id_(user_id_)
  , result_(std::move(result_))
  , chat_types_(std::move(chat_types_))
{}

const std::int32_t savePreparedInlineMessage::ID;

void savePreparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savePreparedInlineMessage");
    s.store_field("user_id", user_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_object_field("chat_types", static_cast<const BaseObject *>(chat_types_.get()));
    s.store_class_end();
  }
}

searchChatMembers::searchChatMembers()
  : chat_id_()
  , query_()
  , limit_()
  , filter_()
{}

searchChatMembers::searchChatMembers(int53 chat_id_, string const &query_, int32 limit_, object_ptr<ChatMembersFilter> &&filter_)
  : chat_id_(chat_id_)
  , query_(query_)
  , limit_(limit_)
  , filter_(std::move(filter_))
{}

const std::int32_t searchChatMembers::ID;

void searchChatMembers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchChatMembers");
    s.store_field("chat_id", chat_id_);
    s.store_field("query", query_);
    s.store_field("limit", limit_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_class_end();
  }
}

sendCallSignalingData::sendCallSignalingData()
  : call_id_()
  , data_()
{}

sendCallSignalingData::sendCallSignalingData(int32 call_id_, bytes const &data_)
  : call_id_(call_id_)
  , data_(std::move(data_))
{}

const std::int32_t sendCallSignalingData::ID;

void sendCallSignalingData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendCallSignalingData");
    s.store_field("call_id", call_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

setAccentColor::setAccentColor()
  : accent_color_id_()
  , background_custom_emoji_id_()
{}

setAccentColor::setAccentColor(int32 accent_color_id_, int64 background_custom_emoji_id_)
  : accent_color_id_(accent_color_id_)
  , background_custom_emoji_id_(background_custom_emoji_id_)
{}

const std::int32_t setAccentColor::ID;

void setAccentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAccentColor");
    s.store_field("accent_color_id", accent_color_id_);
    s.store_field("background_custom_emoji_id", background_custom_emoji_id_);
    s.store_class_end();
  }
}

setAuthenticationPhoneNumber::setAuthenticationPhoneNumber()
  : phone_number_()
  , settings_()
{}

setAuthenticationPhoneNumber::setAuthenticationPhoneNumber(string const &phone_number_, object_ptr<phoneNumberAuthenticationSettings> &&settings_)
  : phone_number_(phone_number_)
  , settings_(std::move(settings_))
{}

const std::int32_t setAuthenticationPhoneNumber::ID;

void setAuthenticationPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAuthenticationPhoneNumber");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setAutoDownloadSettings::setAutoDownloadSettings()
  : settings_()
  , type_()
{}

setAutoDownloadSettings::setAutoDownloadSettings(object_ptr<autoDownloadSettings> &&settings_, object_ptr<NetworkType> &&type_)
  : settings_(std::move(settings_))
  , type_(std::move(type_))
{}

const std::int32_t setAutoDownloadSettings::ID;

void setAutoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAutoDownloadSettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

setAutosaveSettings::setAutosaveSettings()
  : scope_()
  , settings_()
{}

setAutosaveSettings::setAutosaveSettings(object_ptr<AutosaveSettingsScope> &&scope_, object_ptr<scopeAutosaveSettings> &&settings_)
  : scope_(std::move(scope_))
  , settings_(std::move(settings_))
{}

const std::int32_t setAutosaveSettings::ID;

void setAutosaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setAutosaveSettings");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setBusinessAccountProfilePhoto::setBusinessAccountProfilePhoto()
  : business_connection_id_()
  , photo_()
  , is_public_()
{}

setBusinessAccountProfilePhoto::setBusinessAccountProfilePhoto(string const &business_connection_id_, object_ptr<InputChatPhoto> &&photo_, bool is_public_)
  : business_connection_id_(business_connection_id_)
  , photo_(std::move(photo_))
  , is_public_(is_public_)
{}

const std::int32_t setBusinessAccountProfilePhoto::ID;

void setBusinessAccountProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessAccountProfilePhoto");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("is_public", is_public_);
    s.store_class_end();
  }
}

setBusinessGreetingMessageSettings::setBusinessGreetingMessageSettings()
  : greeting_message_settings_()
{}

setBusinessGreetingMessageSettings::setBusinessGreetingMessageSettings(object_ptr<businessGreetingMessageSettings> &&greeting_message_settings_)
  : greeting_message_settings_(std::move(greeting_message_settings_))
{}

const std::int32_t setBusinessGreetingMessageSettings::ID;

void setBusinessGreetingMessageSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setBusinessGreetingMessageSettings");
    s.store_object_field("greeting_message_settings", static_cast<const BaseObject *>(greeting_message_settings_.get()));
    s.store_class_end();
  }
}

setChatClientData::setChatClientData()
  : chat_id_()
  , client_data_()
{}

setChatClientData::setChatClientData(int53 chat_id_, string const &client_data_)
  : chat_id_(chat_id_)
  , client_data_(client_data_)
{}

const std::int32_t setChatClientData::ID;

void setChatClientData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatClientData");
    s.store_field("chat_id", chat_id_);
    s.store_field("client_data", client_data_);
    s.store_class_end();
  }
}

setChatMemberStatus::setChatMemberStatus()
  : chat_id_()
  , member_id_()
  , status_()
{}

setChatMemberStatus::setChatMemberStatus(int53 chat_id_, object_ptr<MessageSender> &&member_id_, object_ptr<ChatMemberStatus> &&status_)
  : chat_id_(chat_id_)
  , member_id_(std::move(member_id_))
  , status_(std::move(status_))
{}

const std::int32_t setChatMemberStatus::ID;

void setChatMemberStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatMemberStatus");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("member_id", static_cast<const BaseObject *>(member_id_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

setChatPinnedStories::setChatPinnedStories()
  : chat_id_()
  , story_ids_()
{}

setChatPinnedStories::setChatPinnedStories(int53 chat_id_, array<int32> &&story_ids_)
  : chat_id_(chat_id_)
  , story_ids_(std::move(story_ids_))
{}

const std::int32_t setChatPinnedStories::ID;

void setChatPinnedStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setChatPinnedStories");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("story_ids", story_ids_.size()); for (const auto &_value : story_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setCloseFriends::setCloseFriends()
  : user_ids_()
{}

setCloseFriends::setCloseFriends(array<int53> &&user_ids_)
  : user_ids_(std::move(user_ids_))
{}

const std::int32_t setCloseFriends::ID;

void setCloseFriends::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setCloseFriends");
    { s.store_vector_begin("user_ids", user_ids_.size()); for (const auto &_value : user_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

setFileGenerationProgress::setFileGenerationProgress()
  : generation_id_()
  , expected_size_()
  , local_prefix_size_()
{}

setFileGenerationProgress::setFileGenerationProgress(int64 generation_id_, int53 expected_size_, int53 local_prefix_size_)
  : generation_id_(generation_id_)
  , expected_size_(expected_size_)
  , local_prefix_size_(local_prefix_size_)
{}

const std::int32_t setFileGenerationProgress::ID;

void setFileGenerationProgress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setFileGenerationProgress");
    s.store_field("generation_id", generation_id_);
    s.store_field("expected_size", expected_size_);
    s.store_field("local_prefix_size", local_prefix_size_);
    s.store_class_end();
  }
}

setGiftSettings::setGiftSettings()
  : settings_()
{}

setGiftSettings::setGiftSettings(object_ptr<giftSettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t setGiftSettings::ID;

void setGiftSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setGiftSettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

setMessageFactCheck::setMessageFactCheck()
  : chat_id_()
  , message_id_()
  , text_()
{}

setMessageFactCheck::setMessageFactCheck(int53 chat_id_, int53 message_id_, object_ptr<formattedText> &&text_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , text_(std::move(text_))
{}

const std::int32_t setMessageFactCheck::ID;

void setMessageFactCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMessageFactCheck");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

setMessageSenderBotVerification::setMessageSenderBotVerification()
  : bot_user_id_()
  , verified_id_()
  , custom_description_()
{}

setMessageSenderBotVerification::setMessageSenderBotVerification(int53 bot_user_id_, object_ptr<MessageSender> &&verified_id_, string const &custom_description_)
  : bot_user_id_(bot_user_id_)
  , verified_id_(std::move(verified_id_))
  , custom_description_(custom_description_)
{}

const std::int32_t setMessageSenderBotVerification::ID;

void setMessageSenderBotVerification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setMessageSenderBotVerification");
    s.store_field("bot_user_id", bot_user_id_);
    s.store_object_field("verified_id", static_cast<const BaseObject *>(verified_id_.get()));
    s.store_field("custom_description", custom_description_);
    s.store_class_end();
  }
}

setPaidMessageReactionType::setPaidMessageReactionType()
  : chat_id_()
  , message_id_()
  , type_()
{}

setPaidMessageReactionType::setPaidMessageReactionType(int53 chat_id_, int53 message_id_, object_ptr<PaidReactionType> &&type_)
  : chat_id_(chat_id_)
  , message_id_(message_id_)
  , type_(std::move(type_))
{}

const std::int32_t setPaidMessageReactionType::ID;

void setPaidMessageReactionType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setPaidMessageReactionType");
    s.store_field("chat_id", chat_id_);
    s.store_field("message_id", message_id_);
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

setProfileAccentColor::setProfileAccentColor()
  : profile_accent_color_id_()
  , profile_background_custom_emoji_id_()
{}

setProfileAccentColor::setProfileAccentColor(int32 profile_accent_color_id_, int64 profile_background_custom_emoji_id_)
  : profile_accent_color_id_(profile_accent_color_id_)
  , profile_background_custom_emoji_id_(profile_background_custom_emoji_id_)
{}

const std::int32_t setProfileAccentColor::ID;

void setProfileAccentColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setProfileAccentColor");
    s.store_field("profile_accent_color_id", profile_accent_color_id_);
    s.store_field("profile_background_custom_emoji_id", profile_background_custom_emoji_id_);
    s.store_class_end();
  }
}

setStickerSetTitle::setStickerSetTitle()
  : name_()
  , title_()
{}

setStickerSetTitle::setStickerSetTitle(string const &name_, string const &title_)
  : name_(name_)
  , title_(title_)
{}

const std::int32_t setStickerSetTitle::ID;

void setStickerSetTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStickerSetTitle");
    s.store_field("name", name_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

setStoryReaction::setStoryReaction()
  : story_poster_chat_id_()
  , story_id_()
  , reaction_type_()
  , update_recent_reactions_()
{}

setStoryReaction::setStoryReaction(int53 story_poster_chat_id_, int32 story_id_, object_ptr<ReactionType> &&reaction_type_, bool update_recent_reactions_)
  : story_poster_chat_id_(story_poster_chat_id_)
  , story_id_(story_id_)
  , reaction_type_(std::move(reaction_type_))
  , update_recent_reactions_(update_recent_reactions_)
{}

const std::int32_t setStoryReaction::ID;

void setStoryReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setStoryReaction");
    s.store_field("story_poster_chat_id", story_poster_chat_id_);
    s.store_field("story_id", story_id_);
    s.store_object_field("reaction_type", static_cast<const BaseObject *>(reaction_type_.get()));
    s.store_field("update_recent_reactions", update_recent_reactions_);
    s.store_class_end();
  }
}

setTdlibParameters::setTdlibParameters()
  : use_test_dc_()
  , database_directory_()
  , files_directory_()
  , database_encryption_key_()
  , use_file_database_()
  , use_chat_info_database_()
  , use_message_database_()
  , use_secret_chats_()
  , api_id_()
  , api_hash_()
  , system_language_code_()
  , device_model_()
  , system_version_()
  , application_version_()
{}

setTdlibParameters::setTdlibParameters(bool use_test_dc_, string const &database_directory_, string const &files_directory_, bytes const &database_encryption_key_, bool use_file_database_, bool use_chat_info_database_, bool use_message_database_, bool use_secret_chats_, int32 api_id_, string const &api_hash_, string const &system_language_code_, string const &device_model_, string const &system_version_, string const &application_version_)
  : use_test_dc_(use_test_dc_)
  , database_directory_(database_directory_)
  , files_directory_(files_directory_)
  , database_encryption_key_(std::move(database_encryption_key_))
  , use_file_database_(use_file_database_)
  , use_chat_info_database_(use_chat_info_database_)
  , use_message_database_(use_message_database_)
  , use_secret_chats_(use_secret_chats_)
  , api_id_(api_id_)
  , api_hash_(api_hash_)
  , system_language_code_(system_language_code_)
  , device_model_(device_model_)
  , system_version_(system_version_)
  , application_version_(application_version_)
{}

const std::int32_t setTdlibParameters::ID;

void setTdlibParameters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setTdlibParameters");
    s.store_field("use_test_dc", use_test_dc_);
    s.store_field("database_directory", database_directory_);
    s.store_field("files_directory", files_directory_);
    s.store_bytes_field("database_encryption_key", database_encryption_key_);
    s.store_field("use_file_database", use_file_database_);
    s.store_field("use_chat_info_database", use_chat_info_database_);
    s.store_field("use_message_database", use_message_database_);
    s.store_field("use_secret_chats", use_secret_chats_);
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", api_hash_);
    s.store_field("system_language_code", system_language_code_);
    s.store_field("device_model", device_model_);
    s.store_field("system_version", system_version_);
    s.store_field("application_version", application_version_);
    s.store_class_end();
  }
}

setUpgradedGiftColors::setUpgradedGiftColors()
  : upgraded_gift_colors_id_()
{}

setUpgradedGiftColors::setUpgradedGiftColors(int64 upgraded_gift_colors_id_)
  : upgraded_gift_colors_id_(upgraded_gift_colors_id_)
{}

const std::int32_t setUpgradedGiftColors::ID;

void setUpgradedGiftColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "setUpgradedGiftColors");
    s.store_field("upgraded_gift_colors_id", upgraded_gift_colors_id_);
    s.store_class_end();
  }
}

shareChatWithBot::shareChatWithBot()
  : source_()
  , button_id_()
  , shared_chat_id_()
  , only_check_()
{}

shareChatWithBot::shareChatWithBot(object_ptr<KeyboardButtonSource> &&source_, int32 button_id_, int53 shared_chat_id_, bool only_check_)
  : source_(std::move(source_))
  , button_id_(button_id_)
  , shared_chat_id_(shared_chat_id_)
  , only_check_(only_check_)
{}

const std::int32_t shareChatWithBot::ID;

void shareChatWithBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shareChatWithBot");
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("button_id", button_id_);
    s.store_field("shared_chat_id", shared_chat_id_);
    s.store_field("only_check", only_check_);
    s.store_class_end();
  }
}

startGroupCallRecording::startGroupCallRecording()
  : group_call_id_()
  , title_()
  , record_video_()
  , use_portrait_orientation_()
{}

startGroupCallRecording::startGroupCallRecording(int32 group_call_id_, string const &title_, bool record_video_, bool use_portrait_orientation_)
  : group_call_id_(group_call_id_)
  , title_(title_)
  , record_video_(record_video_)
  , use_portrait_orientation_(use_portrait_orientation_)
{}

const std::int32_t startGroupCallRecording::ID;

void startGroupCallRecording::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startGroupCallRecording");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("title", title_);
    s.store_field("record_video", record_video_);
    s.store_field("use_portrait_orientation", use_portrait_orientation_);
    s.store_class_end();
  }
}

startGroupCallScreenSharing::startGroupCallScreenSharing()
  : group_call_id_()
  , audio_source_id_()
  , payload_()
{}

startGroupCallScreenSharing::startGroupCallScreenSharing(int32 group_call_id_, int32 audio_source_id_, string const &payload_)
  : group_call_id_(group_call_id_)
  , audio_source_id_(audio_source_id_)
  , payload_(payload_)
{}

const std::int32_t startGroupCallScreenSharing::ID;

void startGroupCallScreenSharing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "startGroupCallScreenSharing");
    s.store_field("group_call_id", group_call_id_);
    s.store_field("audio_source_id", audio_source_id_);
    s.store_field("payload", payload_);
    s.store_class_end();
  }
}

toggleChatIsPinned::toggleChatIsPinned()
  : chat_list_()
  , chat_id_()
  , is_pinned_()
{}

toggleChatIsPinned::toggleChatIsPinned(object_ptr<ChatList> &&chat_list_, int53 chat_id_, bool is_pinned_)
  : chat_list_(std::move(chat_list_))
  , chat_id_(chat_id_)
  , is_pinned_(is_pinned_)
{}

const std::int32_t toggleChatIsPinned::ID;

void toggleChatIsPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleChatIsPinned");
    s.store_object_field("chat_list", static_cast<const BaseObject *>(chat_list_.get()));
    s.store_field("chat_id", chat_id_);
    s.store_field("is_pinned", is_pinned_);
    s.store_class_end();
  }
}

toggleHasSponsoredMessagesEnabled::toggleHasSponsoredMessagesEnabled()
  : has_sponsored_messages_enabled_()
{}

toggleHasSponsoredMessagesEnabled::toggleHasSponsoredMessagesEnabled(bool has_sponsored_messages_enabled_)
  : has_sponsored_messages_enabled_(has_sponsored_messages_enabled_)
{}

const std::int32_t toggleHasSponsoredMessagesEnabled::ID;

void toggleHasSponsoredMessagesEnabled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleHasSponsoredMessagesEnabled");
    s.store_field("has_sponsored_messages_enabled", has_sponsored_messages_enabled_);
    s.store_class_end();
  }
}

toggleSessionCanAcceptSecretChats::toggleSessionCanAcceptSecretChats()
  : session_id_()
  , can_accept_secret_chats_()
{}

toggleSessionCanAcceptSecretChats::toggleSessionCanAcceptSecretChats(int64 session_id_, bool can_accept_secret_chats_)
  : session_id_(session_id_)
  , can_accept_secret_chats_(can_accept_secret_chats_)
{}

const std::int32_t toggleSessionCanAcceptSecretChats::ID;

void toggleSessionCanAcceptSecretChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSessionCanAcceptSecretChats");
    s.store_field("session_id", session_id_);
    s.store_field("can_accept_secret_chats", can_accept_secret_chats_);
    s.store_class_end();
  }
}

toggleSupergroupIsForum::toggleSupergroupIsForum()
  : supergroup_id_()
  , is_forum_()
  , has_forum_tabs_()
{}

toggleSupergroupIsForum::toggleSupergroupIsForum(int53 supergroup_id_, bool is_forum_, bool has_forum_tabs_)
  : supergroup_id_(supergroup_id_)
  , is_forum_(is_forum_)
  , has_forum_tabs_(has_forum_tabs_)
{}

const std::int32_t toggleSupergroupIsForum::ID;

void toggleSupergroupIsForum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupIsForum");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("is_forum", is_forum_);
    s.store_field("has_forum_tabs", has_forum_tabs_);
    s.store_class_end();
  }
}

toggleSupergroupSignMessages::toggleSupergroupSignMessages()
  : supergroup_id_()
  , sign_messages_()
  , show_message_sender_()
{}

toggleSupergroupSignMessages::toggleSupergroupSignMessages(int53 supergroup_id_, bool sign_messages_, bool show_message_sender_)
  : supergroup_id_(supergroup_id_)
  , sign_messages_(sign_messages_)
  , show_message_sender_(show_message_sender_)
{}

const std::int32_t toggleSupergroupSignMessages::ID;

void toggleSupergroupSignMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupSignMessages");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("sign_messages", sign_messages_);
    s.store_field("show_message_sender", show_message_sender_);
    s.store_class_end();
  }
}

toggleSupergroupUsernameIsActive::toggleSupergroupUsernameIsActive()
  : supergroup_id_()
  , username_()
  , is_active_()
{}

toggleSupergroupUsernameIsActive::toggleSupergroupUsernameIsActive(int53 supergroup_id_, string const &username_, bool is_active_)
  : supergroup_id_(supergroup_id_)
  , username_(username_)
  , is_active_(is_active_)
{}

const std::int32_t toggleSupergroupUsernameIsActive::ID;

void toggleSupergroupUsernameIsActive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleSupergroupUsernameIsActive");
    s.store_field("supergroup_id", supergroup_id_);
    s.store_field("username", username_);
    s.store_field("is_active", is_active_);
    s.store_class_end();
  }
}

toggleUsernameIsActive::toggleUsernameIsActive()
  : username_()
  , is_active_()
{}

toggleUsernameIsActive::toggleUsernameIsActive(string const &username_, bool is_active_)
  : username_(username_)
  , is_active_(is_active_)
{}

const std::int32_t toggleUsernameIsActive::ID;

void toggleUsernameIsActive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "toggleUsernameIsActive");
    s.store_field("username", username_);
    s.store_field("is_active", is_active_);
    s.store_class_end();
  }
}

transferGift::transferGift()
  : business_connection_id_()
  , received_gift_id_()
  , new_owner_id_()
  , star_count_()
{}

transferGift::transferGift(string const &business_connection_id_, string const &received_gift_id_, object_ptr<MessageSender> &&new_owner_id_, int53 star_count_)
  : business_connection_id_(business_connection_id_)
  , received_gift_id_(received_gift_id_)
  , new_owner_id_(std::move(new_owner_id_))
  , star_count_(star_count_)
{}

const std::int32_t transferGift::ID;

void transferGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "transferGift");
    s.store_field("business_connection_id", business_connection_id_);
    s.store_field("received_gift_id", received_gift_id_);
    s.store_object_field("new_owner_id", static_cast<const BaseObject *>(new_owner_id_.get()));
    s.store_field("star_count", star_count_);
    s.store_class_end();
  }
}

viewMessages::viewMessages()
  : chat_id_()
  , message_ids_()
  , source_()
  , force_read_()
{}

viewMessages::viewMessages(int53 chat_id_, array<int53> &&message_ids_, object_ptr<MessageSource> &&source_, bool force_read_)
  : chat_id_(chat_id_)
  , message_ids_(std::move(message_ids_))
  , source_(std::move(source_))
  , force_read_(force_read_)
{}

const std::int32_t viewMessages::ID;

void viewMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "viewMessages");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("message_ids", message_ids_.size()); for (const auto &_value : message_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("source", static_cast<const BaseObject *>(source_.get()));
    s.store_field("force_read", force_read_);
    s.store_class_end();
  }
}
}  // namespace td_api
}  // namespace td
