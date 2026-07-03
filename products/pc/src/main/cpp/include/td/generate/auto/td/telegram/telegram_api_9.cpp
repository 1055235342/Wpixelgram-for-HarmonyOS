#include "telegram_api.h"

#include "td/tl/tl_object_parse.h"
#include "td/tl/tl_object_store.h"

#include "td/utils/common.h"
#include "td/utils/format.h"
#include "td/utils/logging.h"
#include "td/utils/SliceBuilder.h"
#include "td/utils/tl_parsers.h"
#include "td/utils/tl_storers.h"
#include "td/utils/TlStorerToString.h"

namespace td {
namespace telegram_api {


botVerifierSettings::botVerifierSettings()
  : flags_()
  , can_modify_custom_description_()
  , icon_()
  , company_()
  , custom_description_()
{}

const std::int32_t botVerifierSettings::ID;

object_ptr<botVerifierSettings> botVerifierSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botVerifierSettings> res = make_tl_object<botVerifierSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_modify_custom_description_ = (var0 & 2) != 0;
  res->icon_ = TlFetchLong::parse(p);
  res->company_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->custom_description_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void botVerifierSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botVerifierSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_modify_custom_description_ << 1)));
    if (var0 & 2) { s.store_field("can_modify_custom_description", true); }
    s.store_field("icon", icon_);
    s.store_field("company", company_);
    if (var0 & 1) { s.store_field("custom_description", custom_description_); }
    s.store_class_end();
  }
}

businessWorkHours::businessWorkHours()
  : flags_()
  , open_now_()
  , timezone_id_()
  , weekly_open_()
{}

businessWorkHours::businessWorkHours(int32 flags_, bool open_now_, string const &timezone_id_, array<object_ptr<businessWeeklyOpen>> &&weekly_open_)
  : flags_(flags_)
  , open_now_(open_now_)
  , timezone_id_(timezone_id_)
  , weekly_open_(std::move(weekly_open_))
{}

const std::int32_t businessWorkHours::ID;

object_ptr<businessWorkHours> businessWorkHours::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessWorkHours> res = make_tl_object<businessWorkHours>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->open_now_ = (var0 & 1) != 0;
  res->timezone_id_ = TlFetchString<string>::parse(p);
  res->weekly_open_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<businessWeeklyOpen>, 302717625>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessWorkHours::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (open_now_ << 0)), s);
  TlStoreString::store(timezone_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 302717625>>, 481674261>::store(weekly_open_, s);
}

void businessWorkHours::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (open_now_ << 0)), s);
  TlStoreString::store(timezone_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 302717625>>, 481674261>::store(weekly_open_, s);
}

void businessWorkHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessWorkHours");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (open_now_ << 0)));
    if (var0 & 1) { s.store_field("open_now", true); }
    s.store_field("timezone_id", timezone_id_);
    { s.store_vector_begin("weekly_open", weekly_open_.size()); for (const auto &_value : weekly_open_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<ChatFull> ChatFull::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatFull::ID:
      return chatFull::fetch(p);
    case channelFull::ID:
      return channelFull::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

chatFull::chatFull()
  : flags_()
  , can_set_username_()
  , has_scheduled_()
  , translations_disabled_()
  , id_()
  , about_()
  , participants_()
  , chat_photo_()
  , notify_settings_()
  , exported_invite_()
  , bot_info_()
  , pinned_msg_id_()
  , folder_id_()
  , call_()
  , ttl_period_()
  , groupcall_default_join_as_()
  , theme_emoticon_()
  , requests_pending_()
  , recent_requesters_()
  , available_reactions_()
  , reactions_limit_()
{}

const std::int32_t chatFull::ID;

object_ptr<ChatFull> chatFull::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatFull> res = make_tl_object<chatFull>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_set_username_ = (var0 & 128) != 0;
  res->has_scheduled_ = (var0 & 256) != 0;
  res->translations_disabled_ = (var0 & 524288) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->about_ = TlFetchString<string>::parse(p);
  res->participants_ = TlFetchObject<ChatParticipants>::parse(p);
  if (var0 & 4) { res->chat_photo_ = TlFetchObject<Photo>::parse(p); }
  res->notify_settings_ = TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
  if (var0 & 8192) { res->exported_invite_ = TlFetchObject<ExportedChatInvite>::parse(p); }
  if (var0 & 8) { res->bot_info_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botInfo>, 1300890265>>, 481674261>::parse(p); }
  if (var0 & 64) { res->pinned_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->folder_id_ = TlFetchInt::parse(p); }
  if (var0 & 4096) { res->call_ = TlFetchObject<InputGroupCall>::parse(p); }
  if (var0 & 16384) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (var0 & 32768) { res->groupcall_default_join_as_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 65536) { res->theme_emoticon_ = TlFetchString<string>::parse(p); }
  if (var0 & 131072) { res->requests_pending_ = TlFetchInt::parse(p); }
  if (var0 & 131072) { res->recent_requesters_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (var0 & 262144) { res->available_reactions_ = TlFetchObject<ChatReactions>::parse(p); }
  if (var0 & 1048576) { res->reactions_limit_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatFull");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_set_username_ << 7) | (has_scheduled_ << 8) | (translations_disabled_ << 19)));
    if (var0 & 128) { s.store_field("can_set_username", true); }
    if (var0 & 256) { s.store_field("has_scheduled", true); }
    if (var0 & 524288) { s.store_field("translations_disabled", true); }
    s.store_field("id", id_);
    s.store_field("about", about_);
    s.store_object_field("participants", static_cast<const BaseObject *>(participants_.get()));
    if (var0 & 4) { s.store_object_field("chat_photo", static_cast<const BaseObject *>(chat_photo_.get())); }
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    if (var0 & 8192) { s.store_object_field("exported_invite", static_cast<const BaseObject *>(exported_invite_.get())); }
    if (var0 & 8) { { s.store_vector_begin("bot_info", bot_info_.size()); for (const auto &_value : bot_info_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 64) { s.store_field("pinned_msg_id", pinned_msg_id_); }
    if (var0 & 2048) { s.store_field("folder_id", folder_id_); }
    if (var0 & 4096) { s.store_object_field("call", static_cast<const BaseObject *>(call_.get())); }
    if (var0 & 16384) { s.store_field("ttl_period", ttl_period_); }
    if (var0 & 32768) { s.store_object_field("groupcall_default_join_as", static_cast<const BaseObject *>(groupcall_default_join_as_.get())); }
    if (var0 & 65536) { s.store_field("theme_emoticon", theme_emoticon_); }
    if (var0 & 131072) { s.store_field("requests_pending", requests_pending_); }
    if (var0 & 131072) { { s.store_vector_begin("recent_requesters", recent_requesters_.size()); for (const auto &_value : recent_requesters_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 262144) { s.store_object_field("available_reactions", static_cast<const BaseObject *>(available_reactions_.get())); }
    if (var0 & 1048576) { s.store_field("reactions_limit", reactions_limit_); }
    s.store_class_end();
  }
}

channelFull::channelFull()
  : flags_()
  , can_view_participants_()
  , can_set_username_()
  , can_set_stickers_()
  , hidden_prehistory_()
  , can_set_location_()
  , has_scheduled_()
  , can_view_stats_()
  , blocked_()
  , flags2_()
  , can_delete_channel_()
  , antispam_()
  , participants_hidden_()
  , translations_disabled_()
  , stories_pinned_available_()
  , view_forum_as_messages_()
  , restricted_sponsored_()
  , can_view_revenue_()
  , paid_media_allowed_()
  , can_view_stars_revenue_()
  , paid_reactions_available_()
  , stargifts_available_()
  , paid_messages_available_()
  , id_()
  , about_()
  , participants_count_()
  , admins_count_()
  , kicked_count_()
  , banned_count_()
  , online_count_()
  , read_inbox_max_id_()
  , read_outbox_max_id_()
  , unread_count_()
  , chat_photo_()
  , notify_settings_()
  , exported_invite_()
  , bot_info_()
  , migrated_from_chat_id_()
  , migrated_from_max_id_()
  , pinned_msg_id_()
  , stickerset_()
  , available_min_id_()
  , folder_id_()
  , linked_chat_id_()
  , location_()
  , slowmode_seconds_()
  , slowmode_next_send_date_()
  , stats_dc_()
  , pts_()
  , call_()
  , ttl_period_()
  , pending_suggestions_()
  , groupcall_default_join_as_()
  , theme_emoticon_()
  , requests_pending_()
  , recent_requesters_()
  , default_send_as_()
  , available_reactions_()
  , reactions_limit_()
  , stories_()
  , wallpaper_()
  , boosts_applied_()
  , boosts_unrestrict_()
  , emojiset_()
  , bot_verification_()
  , stargifts_count_()
  , send_paid_messages_stars_()
  , main_tab_()
{}

const std::int32_t channelFull::ID;

object_ptr<ChatFull> channelFull::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelFull> res = make_tl_object<channelFull>();
  int32 var0;
  int32 var1;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_view_participants_ = (var0 & 8) != 0;
  res->can_set_username_ = (var0 & 64) != 0;
  res->can_set_stickers_ = (var0 & 128) != 0;
  res->hidden_prehistory_ = (var0 & 1024) != 0;
  res->can_set_location_ = (var0 & 65536) != 0;
  res->has_scheduled_ = (var0 & 524288) != 0;
  res->can_view_stats_ = (var0 & 1048576) != 0;
  res->blocked_ = (var0 & 4194304) != 0;
  if ((var1 = res->flags2_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_delete_channel_ = (var1 & 1) != 0;
  res->antispam_ = (var1 & 2) != 0;
  res->participants_hidden_ = (var1 & 4) != 0;
  res->translations_disabled_ = (var1 & 8) != 0;
  res->stories_pinned_available_ = (var1 & 32) != 0;
  res->view_forum_as_messages_ = (var1 & 64) != 0;
  res->restricted_sponsored_ = (var1 & 2048) != 0;
  res->can_view_revenue_ = (var1 & 4096) != 0;
  res->paid_media_allowed_ = (var1 & 16384) != 0;
  res->can_view_stars_revenue_ = (var1 & 32768) != 0;
  res->paid_reactions_available_ = (var1 & 65536) != 0;
  res->stargifts_available_ = (var1 & 524288) != 0;
  res->paid_messages_available_ = (var1 & 1048576) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->about_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->participants_count_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->admins_count_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->kicked_count_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->banned_count_ = TlFetchInt::parse(p); }
  if (var0 & 8192) { res->online_count_ = TlFetchInt::parse(p); }
  res->read_inbox_max_id_ = TlFetchInt::parse(p);
  res->read_outbox_max_id_ = TlFetchInt::parse(p);
  res->unread_count_ = TlFetchInt::parse(p);
  res->chat_photo_ = TlFetchObject<Photo>::parse(p);
  res->notify_settings_ = TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
  if (var0 & 8388608) { res->exported_invite_ = TlFetchObject<ExportedChatInvite>::parse(p); }
  res->bot_info_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botInfo>, 1300890265>>, 481674261>::parse(p);
  if (var0 & 16) { res->migrated_from_chat_id_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->migrated_from_max_id_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->pinned_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->stickerset_ = TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p); }
  if (var0 & 512) { res->available_min_id_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->folder_id_ = TlFetchInt::parse(p); }
  if (var0 & 16384) { res->linked_chat_id_ = TlFetchLong::parse(p); }
  if (var0 & 32768) { res->location_ = TlFetchObject<ChannelLocation>::parse(p); }
  if (var0 & 131072) { res->slowmode_seconds_ = TlFetchInt::parse(p); }
  if (var0 & 262144) { res->slowmode_next_send_date_ = TlFetchInt::parse(p); }
  if (var0 & 4096) { res->stats_dc_ = TlFetchInt::parse(p); }
  res->pts_ = TlFetchInt::parse(p);
  if (var0 & 2097152) { res->call_ = TlFetchObject<InputGroupCall>::parse(p); }
  if (var0 & 16777216) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (var0 & 33554432) { res->pending_suggestions_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p); }
  if (var0 & 67108864) { res->groupcall_default_join_as_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 134217728) { res->theme_emoticon_ = TlFetchString<string>::parse(p); }
  if (var0 & 268435456) { res->requests_pending_ = TlFetchInt::parse(p); }
  if (var0 & 268435456) { res->recent_requesters_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (var0 & 536870912) { res->default_send_as_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 1073741824) { res->available_reactions_ = TlFetchObject<ChatReactions>::parse(p); }
  if (var1 & 8192) { res->reactions_limit_ = TlFetchInt::parse(p); }
  if (var1 & 16) { res->stories_ = TlFetchBoxed<TlFetchObject<peerStories>, -1707742823>::parse(p); }
  if (var1 & 128) { res->wallpaper_ = TlFetchObject<WallPaper>::parse(p); }
  if (var1 & 256) { res->boosts_applied_ = TlFetchInt::parse(p); }
  if (var1 & 512) { res->boosts_unrestrict_ = TlFetchInt::parse(p); }
  if (var1 & 1024) { res->emojiset_ = TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p); }
  if (var1 & 131072) { res->bot_verification_ = TlFetchBoxed<TlFetchObject<botVerification>, -113453988>::parse(p); }
  if (var1 & 262144) { res->stargifts_count_ = TlFetchInt::parse(p); }
  if (var1 & 2097152) { res->send_paid_messages_stars_ = TlFetchLong::parse(p); }
  if (var1 & 4194304) { res->main_tab_ = TlFetchObject<ProfileTab>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelFull");
  int32 var0;
  int32 var1;
    s.store_field("flags", (var0 = flags_ | (can_view_participants_ << 3) | (can_set_username_ << 6) | (can_set_stickers_ << 7) | (hidden_prehistory_ << 10) | (can_set_location_ << 16) | (has_scheduled_ << 19) | (can_view_stats_ << 20) | (blocked_ << 22)));
    if (var0 & 8) { s.store_field("can_view_participants", true); }
    if (var0 & 64) { s.store_field("can_set_username", true); }
    if (var0 & 128) { s.store_field("can_set_stickers", true); }
    if (var0 & 1024) { s.store_field("hidden_prehistory", true); }
    if (var0 & 65536) { s.store_field("can_set_location", true); }
    if (var0 & 524288) { s.store_field("has_scheduled", true); }
    if (var0 & 1048576) { s.store_field("can_view_stats", true); }
    if (var0 & 4194304) { s.store_field("blocked", true); }
    s.store_field("flags2", (var1 = flags2_ | (can_delete_channel_ << 0) | (antispam_ << 1) | (participants_hidden_ << 2) | (translations_disabled_ << 3) | (stories_pinned_available_ << 5) | (view_forum_as_messages_ << 6) | (restricted_sponsored_ << 11) | (can_view_revenue_ << 12) | (paid_media_allowed_ << 14) | (can_view_stars_revenue_ << 15) | (paid_reactions_available_ << 16) | (stargifts_available_ << 19) | (paid_messages_available_ << 20)));
    if (var1 & 1) { s.store_field("can_delete_channel", true); }
    if (var1 & 2) { s.store_field("antispam", true); }
    if (var1 & 4) { s.store_field("participants_hidden", true); }
    if (var1 & 8) { s.store_field("translations_disabled", true); }
    if (var1 & 32) { s.store_field("stories_pinned_available", true); }
    if (var1 & 64) { s.store_field("view_forum_as_messages", true); }
    if (var1 & 2048) { s.store_field("restricted_sponsored", true); }
    if (var1 & 4096) { s.store_field("can_view_revenue", true); }
    if (var1 & 16384) { s.store_field("paid_media_allowed", true); }
    if (var1 & 32768) { s.store_field("can_view_stars_revenue", true); }
    if (var1 & 65536) { s.store_field("paid_reactions_available", true); }
    if (var1 & 524288) { s.store_field("stargifts_available", true); }
    if (var1 & 1048576) { s.store_field("paid_messages_available", true); }
    s.store_field("id", id_);
    s.store_field("about", about_);
    if (var0 & 1) { s.store_field("participants_count", participants_count_); }
    if (var0 & 2) { s.store_field("admins_count", admins_count_); }
    if (var0 & 4) { s.store_field("kicked_count", kicked_count_); }
    if (var0 & 4) { s.store_field("banned_count", banned_count_); }
    if (var0 & 8192) { s.store_field("online_count", online_count_); }
    s.store_field("read_inbox_max_id", read_inbox_max_id_);
    s.store_field("read_outbox_max_id", read_outbox_max_id_);
    s.store_field("unread_count", unread_count_);
    s.store_object_field("chat_photo", static_cast<const BaseObject *>(chat_photo_.get()));
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    if (var0 & 8388608) { s.store_object_field("exported_invite", static_cast<const BaseObject *>(exported_invite_.get())); }
    { s.store_vector_begin("bot_info", bot_info_.size()); for (const auto &_value : bot_info_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 16) { s.store_field("migrated_from_chat_id", migrated_from_chat_id_); }
    if (var0 & 16) { s.store_field("migrated_from_max_id", migrated_from_max_id_); }
    if (var0 & 32) { s.store_field("pinned_msg_id", pinned_msg_id_); }
    if (var0 & 256) { s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get())); }
    if (var0 & 512) { s.store_field("available_min_id", available_min_id_); }
    if (var0 & 2048) { s.store_field("folder_id", folder_id_); }
    if (var0 & 16384) { s.store_field("linked_chat_id", linked_chat_id_); }
    if (var0 & 32768) { s.store_object_field("location", static_cast<const BaseObject *>(location_.get())); }
    if (var0 & 131072) { s.store_field("slowmode_seconds", slowmode_seconds_); }
    if (var0 & 262144) { s.store_field("slowmode_next_send_date", slowmode_next_send_date_); }
    if (var0 & 4096) { s.store_field("stats_dc", stats_dc_); }
    s.store_field("pts", pts_);
    if (var0 & 2097152) { s.store_object_field("call", static_cast<const BaseObject *>(call_.get())); }
    if (var0 & 16777216) { s.store_field("ttl_period", ttl_period_); }
    if (var0 & 33554432) { { s.store_vector_begin("pending_suggestions", pending_suggestions_.size()); for (const auto &_value : pending_suggestions_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 67108864) { s.store_object_field("groupcall_default_join_as", static_cast<const BaseObject *>(groupcall_default_join_as_.get())); }
    if (var0 & 134217728) { s.store_field("theme_emoticon", theme_emoticon_); }
    if (var0 & 268435456) { s.store_field("requests_pending", requests_pending_); }
    if (var0 & 268435456) { { s.store_vector_begin("recent_requesters", recent_requesters_.size()); for (const auto &_value : recent_requesters_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 536870912) { s.store_object_field("default_send_as", static_cast<const BaseObject *>(default_send_as_.get())); }
    if (var0 & 1073741824) { s.store_object_field("available_reactions", static_cast<const BaseObject *>(available_reactions_.get())); }
    if (var1 & 8192) { s.store_field("reactions_limit", reactions_limit_); }
    if (var1 & 16) { s.store_object_field("stories", static_cast<const BaseObject *>(stories_.get())); }
    if (var1 & 128) { s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get())); }
    if (var1 & 256) { s.store_field("boosts_applied", boosts_applied_); }
    if (var1 & 512) { s.store_field("boosts_unrestrict", boosts_unrestrict_); }
    if (var1 & 1024) { s.store_object_field("emojiset", static_cast<const BaseObject *>(emojiset_.get())); }
    if (var1 & 131072) { s.store_object_field("bot_verification", static_cast<const BaseObject *>(bot_verification_.get())); }
    if (var1 & 262144) { s.store_field("stargifts_count", stargifts_count_); }
    if (var1 & 2097152) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    if (var1 & 4194304) { s.store_object_field("main_tab", static_cast<const BaseObject *>(main_tab_.get())); }
    s.store_class_end();
  }
}

connectedBotStarRef::connectedBotStarRef()
  : flags_()
  , revoked_()
  , url_()
  , date_()
  , bot_id_()
  , commission_permille_()
  , duration_months_()
  , participants_()
  , revenue_()
{}

const std::int32_t connectedBotStarRef::ID;

object_ptr<connectedBotStarRef> connectedBotStarRef::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<connectedBotStarRef> res = make_tl_object<connectedBotStarRef>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->revoked_ = (var0 & 2) != 0;
  res->url_ = TlFetchString<string>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->bot_id_ = TlFetchLong::parse(p);
  res->commission_permille_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->duration_months_ = TlFetchInt::parse(p); }
  res->participants_ = TlFetchLong::parse(p);
  res->revenue_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void connectedBotStarRef::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedBotStarRef");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (revoked_ << 1)));
    if (var0 & 2) { s.store_field("revoked", true); }
    s.store_field("url", url_);
    s.store_field("date", date_);
    s.store_field("bot_id", bot_id_);
    s.store_field("commission_permille", commission_permille_);
    if (var0 & 1) { s.store_field("duration_months", duration_months_); }
    s.store_field("participants", participants_);
    s.store_field("revenue", revenue_);
    s.store_class_end();
  }
}

const std::int32_t contact::ID;

object_ptr<contact> contact::fetch(TlBufferParser &p) {
  return make_tl_object<contact>(p);
}

contact::contact(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , mutual_(TlFetchBool::parse(p))
{}

void contact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contact");
    s.store_field("user_id", user_id_);
    s.store_field("mutual", mutual_);
    s.store_class_end();
  }
}

object_ptr<DialogPeer> DialogPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case dialogPeer::ID:
      return dialogPeer::fetch(p);
    case dialogPeerFolder::ID:
      return dialogPeerFolder::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t dialogPeer::ID;

object_ptr<DialogPeer> dialogPeer::fetch(TlBufferParser &p) {
  return make_tl_object<dialogPeer>(p);
}

dialogPeer::dialogPeer(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
{}

void dialogPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

const std::int32_t dialogPeerFolder::ID;

object_ptr<DialogPeer> dialogPeerFolder::fetch(TlBufferParser &p) {
  return make_tl_object<dialogPeerFolder>(p);
}

dialogPeerFolder::dialogPeerFolder(TlBufferParser &p)
  : folder_id_(TlFetchInt::parse(p))
{}

void dialogPeerFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogPeerFolder");
    s.store_field("folder_id", folder_id_);
    s.store_class_end();
  }
}

disallowedGiftsSettings::disallowedGiftsSettings()
  : flags_()
  , disallow_unlimited_stargifts_()
  , disallow_limited_stargifts_()
  , disallow_unique_stargifts_()
  , disallow_premium_gifts_()
  , disallow_stargifts_from_channels_()
{}

disallowedGiftsSettings::disallowedGiftsSettings(int32 flags_, bool disallow_unlimited_stargifts_, bool disallow_limited_stargifts_, bool disallow_unique_stargifts_, bool disallow_premium_gifts_, bool disallow_stargifts_from_channels_)
  : flags_(flags_)
  , disallow_unlimited_stargifts_(disallow_unlimited_stargifts_)
  , disallow_limited_stargifts_(disallow_limited_stargifts_)
  , disallow_unique_stargifts_(disallow_unique_stargifts_)
  , disallow_premium_gifts_(disallow_premium_gifts_)
  , disallow_stargifts_from_channels_(disallow_stargifts_from_channels_)
{}

const std::int32_t disallowedGiftsSettings::ID;

object_ptr<disallowedGiftsSettings> disallowedGiftsSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<disallowedGiftsSettings> res = make_tl_object<disallowedGiftsSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->disallow_unlimited_stargifts_ = (var0 & 1) != 0;
  res->disallow_limited_stargifts_ = (var0 & 2) != 0;
  res->disallow_unique_stargifts_ = (var0 & 4) != 0;
  res->disallow_premium_gifts_ = (var0 & 8) != 0;
  res->disallow_stargifts_from_channels_ = (var0 & 16) != 0;
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void disallowedGiftsSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (disallow_unlimited_stargifts_ << 0) | (disallow_limited_stargifts_ << 1) | (disallow_unique_stargifts_ << 2) | (disallow_premium_gifts_ << 3) | (disallow_stargifts_from_channels_ << 4)), s);
}

void disallowedGiftsSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (disallow_unlimited_stargifts_ << 0) | (disallow_limited_stargifts_ << 1) | (disallow_unique_stargifts_ << 2) | (disallow_premium_gifts_ << 3) | (disallow_stargifts_from_channels_ << 4)), s);
}

void disallowedGiftsSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "disallowedGiftsSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (disallow_unlimited_stargifts_ << 0) | (disallow_limited_stargifts_ << 1) | (disallow_unique_stargifts_ << 2) | (disallow_premium_gifts_ << 3) | (disallow_stargifts_from_channels_ << 4)));
    if (var0 & 1) { s.store_field("disallow_unlimited_stargifts", true); }
    if (var0 & 2) { s.store_field("disallow_limited_stargifts", true); }
    if (var0 & 4) { s.store_field("disallow_unique_stargifts", true); }
    if (var0 & 8) { s.store_field("disallow_premium_gifts", true); }
    if (var0 & 16) { s.store_field("disallow_stargifts_from_channels", true); }
    s.store_class_end();
  }
}

object_ptr<EmojiGroup> EmojiGroup::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case emojiGroup::ID:
      return emojiGroup::fetch(p);
    case emojiGroupGreeting::ID:
      return emojiGroupGreeting::fetch(p);
    case emojiGroupPremium::ID:
      return emojiGroupPremium::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t emojiGroup::ID;

object_ptr<EmojiGroup> emojiGroup::fetch(TlBufferParser &p) {
  return make_tl_object<emojiGroup>(p);
}

emojiGroup::emojiGroup(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , icon_emoji_id_(TlFetchLong::parse(p))
  , emoticons_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void emojiGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiGroup");
    s.store_field("title", title_);
    s.store_field("icon_emoji_id", icon_emoji_id_);
    { s.store_vector_begin("emoticons", emoticons_.size()); for (const auto &_value : emoticons_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t emojiGroupGreeting::ID;

object_ptr<EmojiGroup> emojiGroupGreeting::fetch(TlBufferParser &p) {
  return make_tl_object<emojiGroupGreeting>(p);
}

emojiGroupGreeting::emojiGroupGreeting(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , icon_emoji_id_(TlFetchLong::parse(p))
  , emoticons_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void emojiGroupGreeting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiGroupGreeting");
    s.store_field("title", title_);
    s.store_field("icon_emoji_id", icon_emoji_id_);
    { s.store_vector_begin("emoticons", emoticons_.size()); for (const auto &_value : emoticons_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t emojiGroupPremium::ID;

object_ptr<EmojiGroup> emojiGroupPremium::fetch(TlBufferParser &p) {
  return make_tl_object<emojiGroupPremium>(p);
}

emojiGroupPremium::emojiGroupPremium(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , icon_emoji_id_(TlFetchLong::parse(p))
{}

void emojiGroupPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiGroupPremium");
    s.store_field("title", title_);
    s.store_field("icon_emoji_id", icon_emoji_id_);
    s.store_class_end();
  }
}

object_ptr<EmojiKeyword> EmojiKeyword::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case emojiKeyword::ID:
      return emojiKeyword::fetch(p);
    case emojiKeywordDeleted::ID:
      return emojiKeywordDeleted::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t emojiKeyword::ID;

object_ptr<EmojiKeyword> emojiKeyword::fetch(TlBufferParser &p) {
  return make_tl_object<emojiKeyword>(p);
}

emojiKeyword::emojiKeyword(TlBufferParser &p)
  : keyword_(TlFetchString<string>::parse(p))
  , emoticons_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void emojiKeyword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiKeyword");
    s.store_field("keyword", keyword_);
    { s.store_vector_begin("emoticons", emoticons_.size()); for (const auto &_value : emoticons_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t emojiKeywordDeleted::ID;

object_ptr<EmojiKeyword> emojiKeywordDeleted::fetch(TlBufferParser &p) {
  return make_tl_object<emojiKeywordDeleted>(p);
}

emojiKeywordDeleted::emojiKeywordDeleted(TlBufferParser &p)
  : keyword_(TlFetchString<string>::parse(p))
  , emoticons_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void emojiKeywordDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiKeywordDeleted");
    s.store_field("keyword", keyword_);
    { s.store_vector_begin("emoticons", emoticons_.size()); for (const auto &_value : emoticons_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<EncryptedFile> EncryptedFile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case encryptedFileEmpty::ID:
      return encryptedFileEmpty::fetch(p);
    case encryptedFile::ID:
      return encryptedFile::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t encryptedFileEmpty::ID;

object_ptr<EncryptedFile> encryptedFileEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedFileEmpty>();
}

void encryptedFileEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedFileEmpty");
    s.store_class_end();
  }
}

const std::int32_t encryptedFile::ID;

object_ptr<EncryptedFile> encryptedFile::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedFile>(p);
}

encryptedFile::encryptedFile(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , size_(TlFetchLong::parse(p))
  , dc_id_(TlFetchInt::parse(p))
  , key_fingerprint_(TlFetchInt::parse(p))
{}

void encryptedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedFile");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("size", size_);
    s.store_field("dc_id", dc_id_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_class_end();
  }
}

object_ptr<GeoPoint> GeoPoint::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case geoPointEmpty::ID:
      return geoPointEmpty::fetch(p);
    case geoPoint::ID:
      return geoPoint::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t geoPointEmpty::ID;

object_ptr<GeoPoint> geoPointEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<geoPointEmpty>();
}

void geoPointEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void geoPointEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void geoPointEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "geoPointEmpty");
    s.store_class_end();
  }
}

geoPoint::geoPoint()
  : flags_()
  , long_()
  , lat_()
  , access_hash_()
  , accuracy_radius_()
{}

geoPoint::geoPoint(int32 flags_, double long_, double lat_, int64 access_hash_, int32 accuracy_radius_)
  : flags_(flags_)
  , long_(long_)
  , lat_(lat_)
  , access_hash_(access_hash_)
  , accuracy_radius_(accuracy_radius_)
{}

const std::int32_t geoPoint::ID;

object_ptr<GeoPoint> geoPoint::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<geoPoint> res = make_tl_object<geoPoint>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->long_ = TlFetchDouble::parse(p);
  res->lat_ = TlFetchDouble::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->accuracy_radius_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void geoPoint::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(long_, s);
  TlStoreBinary::store(lat_, s);
  TlStoreBinary::store(access_hash_, s);
  if (var0 & 1) { TlStoreBinary::store(accuracy_radius_, s); }
}

void geoPoint::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(long_, s);
  TlStoreBinary::store(lat_, s);
  TlStoreBinary::store(access_hash_, s);
  if (var0 & 1) { TlStoreBinary::store(accuracy_radius_, s); }
}

void geoPoint::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "geoPoint");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("long", long_);
    s.store_field("lat", lat_);
    s.store_field("access_hash", access_hash_);
    if (var0 & 1) { s.store_field("accuracy_radius", accuracy_radius_); }
    s.store_class_end();
  }
}

inputBusinessIntro::inputBusinessIntro(int32 flags_, string const &title_, string const &description_, object_ptr<InputDocument> &&sticker_)
  : flags_(flags_)
  , title_(title_)
  , description_(description_)
  , sticker_(std::move(sticker_))
{}

const std::int32_t inputBusinessIntro::ID;

void inputBusinessIntro::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s); }
}

void inputBusinessIntro::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s); }
}

void inputBusinessIntro::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessIntro");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 1) { s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get())); }
    s.store_class_end();
  }
}

inputPaymentCredentialsSaved::inputPaymentCredentialsSaved(string const &id_, bytes &&tmp_password_)
  : id_(id_)
  , tmp_password_(std::move(tmp_password_))
{}

const std::int32_t inputPaymentCredentialsSaved::ID;

void inputPaymentCredentialsSaved::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(tmp_password_, s);
}

void inputPaymentCredentialsSaved::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(tmp_password_, s);
}

void inputPaymentCredentialsSaved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaymentCredentialsSaved");
    s.store_field("id", id_);
    s.store_bytes_field("tmp_password", tmp_password_);
    s.store_class_end();
  }
}

inputPaymentCredentials::inputPaymentCredentials(int32 flags_, bool save_, object_ptr<dataJSON> &&data_)
  : flags_(flags_)
  , save_(save_)
  , data_(std::move(data_))
{}

const std::int32_t inputPaymentCredentials::ID;

void inputPaymentCredentials::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (save_ << 0)), s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(data_, s);
}

void inputPaymentCredentials::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (save_ << 0)), s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(data_, s);
}

void inputPaymentCredentials::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaymentCredentials");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (save_ << 0)));
    if (var0 & 1) { s.store_field("save", true); }
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_class_end();
  }
}

inputPaymentCredentialsApplePay::inputPaymentCredentialsApplePay(object_ptr<dataJSON> &&payment_data_)
  : payment_data_(std::move(payment_data_))
{}

const std::int32_t inputPaymentCredentialsApplePay::ID;

void inputPaymentCredentialsApplePay::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(payment_data_, s);
}

void inputPaymentCredentialsApplePay::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(payment_data_, s);
}

void inputPaymentCredentialsApplePay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaymentCredentialsApplePay");
    s.store_object_field("payment_data", static_cast<const BaseObject *>(payment_data_.get()));
    s.store_class_end();
  }
}

inputPaymentCredentialsGooglePay::inputPaymentCredentialsGooglePay(object_ptr<dataJSON> &&payment_token_)
  : payment_token_(std::move(payment_token_))
{}

const std::int32_t inputPaymentCredentialsGooglePay::ID;

void inputPaymentCredentialsGooglePay::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(payment_token_, s);
}

void inputPaymentCredentialsGooglePay::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(payment_token_, s);
}

void inputPaymentCredentialsGooglePay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPaymentCredentialsGooglePay");
    s.store_object_field("payment_token", static_cast<const BaseObject *>(payment_token_.get()));
    s.store_class_end();
  }
}

inputQuickReplyShortcut::inputQuickReplyShortcut(string const &shortcut_)
  : shortcut_(shortcut_)
{}

const std::int32_t inputQuickReplyShortcut::ID;

void inputQuickReplyShortcut::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(shortcut_, s);
}

void inputQuickReplyShortcut::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(shortcut_, s);
}

void inputQuickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputQuickReplyShortcut");
    s.store_field("shortcut", shortcut_);
    s.store_class_end();
  }
}

inputQuickReplyShortcutId::inputQuickReplyShortcutId(int32 shortcut_id_)
  : shortcut_id_(shortcut_id_)
{}

const std::int32_t inputQuickReplyShortcutId::ID;

void inputQuickReplyShortcutId::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(shortcut_id_, s);
}

void inputQuickReplyShortcutId::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(shortcut_id_, s);
}

void inputQuickReplyShortcutId::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputQuickReplyShortcutId");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_class_end();
  }
}

object_ptr<InputReplyTo> InputReplyTo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputReplyToMessage::ID:
      return inputReplyToMessage::fetch(p);
    case inputReplyToStory::ID:
      return inputReplyToStory::fetch(p);
    case inputReplyToMonoForum::ID:
      return inputReplyToMonoForum::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputReplyToMessage::inputReplyToMessage()
  : flags_()
  , reply_to_msg_id_()
  , top_msg_id_()
  , reply_to_peer_id_()
  , quote_text_()
  , quote_entities_()
  , quote_offset_()
  , monoforum_peer_id_()
  , todo_item_id_()
  , poll_option_()
{}

inputReplyToMessage::inputReplyToMessage(int32 flags_, int32 reply_to_msg_id_, int32 top_msg_id_, object_ptr<InputPeer> &&reply_to_peer_id_, string const &quote_text_, array<object_ptr<MessageEntity>> &&quote_entities_, int32 quote_offset_, object_ptr<InputPeer> &&monoforum_peer_id_, int32 todo_item_id_, bytes &&poll_option_)
  : flags_(flags_)
  , reply_to_msg_id_(reply_to_msg_id_)
  , top_msg_id_(top_msg_id_)
  , reply_to_peer_id_(std::move(reply_to_peer_id_))
  , quote_text_(quote_text_)
  , quote_entities_(std::move(quote_entities_))
  , quote_offset_(quote_offset_)
  , monoforum_peer_id_(std::move(monoforum_peer_id_))
  , todo_item_id_(todo_item_id_)
  , poll_option_(std::move(poll_option_))
{}

const std::int32_t inputReplyToMessage::ID;

object_ptr<InputReplyTo> inputReplyToMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputReplyToMessage> res = make_tl_object<inputReplyToMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->reply_to_msg_id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->top_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->reply_to_peer_id_ = TlFetchObject<InputPeer>::parse(p); }
  if (var0 & 4) { res->quote_text_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->quote_entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 16) { res->quote_offset_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->monoforum_peer_id_ = TlFetchObject<InputPeer>::parse(p); }
  if (var0 & 64) { res->todo_item_id_ = TlFetchInt::parse(p); }
  if (var0 & 128) { res->poll_option_ = TlFetchBytes<bytes>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputReplyToMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(reply_to_msg_id_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_peer_id_, s); }
  if (var0 & 4) { TlStoreString::store(quote_text_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(quote_entities_, s); }
  if (var0 & 16) { TlStoreBinary::store(quote_offset_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(monoforum_peer_id_, s); }
  if (var0 & 64) { TlStoreBinary::store(todo_item_id_, s); }
  if (var0 & 128) { TlStoreString::store(poll_option_, s); }
}

void inputReplyToMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(reply_to_msg_id_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_peer_id_, s); }
  if (var0 & 4) { TlStoreString::store(quote_text_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(quote_entities_, s); }
  if (var0 & 16) { TlStoreBinary::store(quote_offset_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(monoforum_peer_id_, s); }
  if (var0 & 64) { TlStoreBinary::store(todo_item_id_, s); }
  if (var0 & 128) { TlStoreString::store(poll_option_, s); }
}

void inputReplyToMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReplyToMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("reply_to_msg_id", reply_to_msg_id_);
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("reply_to_peer_id", static_cast<const BaseObject *>(reply_to_peer_id_.get())); }
    if (var0 & 4) { s.store_field("quote_text", quote_text_); }
    if (var0 & 8) { { s.store_vector_begin("quote_entities", quote_entities_.size()); for (const auto &_value : quote_entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("quote_offset", quote_offset_); }
    if (var0 & 32) { s.store_object_field("monoforum_peer_id", static_cast<const BaseObject *>(monoforum_peer_id_.get())); }
    if (var0 & 64) { s.store_field("todo_item_id", todo_item_id_); }
    if (var0 & 128) { s.store_bytes_field("poll_option", poll_option_); }
    s.store_class_end();
  }
}

inputReplyToStory::inputReplyToStory(object_ptr<InputPeer> &&peer_, int32 story_id_)
  : peer_(std::move(peer_))
  , story_id_(story_id_)
{}

const std::int32_t inputReplyToStory::ID;

object_ptr<InputReplyTo> inputReplyToStory::fetch(TlBufferParser &p) {
  return make_tl_object<inputReplyToStory>(p);
}

inputReplyToStory::inputReplyToStory(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , story_id_(TlFetchInt::parse(p))
{}

void inputReplyToStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(story_id_, s);
}

void inputReplyToStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(story_id_, s);
}

void inputReplyToStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReplyToStory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

inputReplyToMonoForum::inputReplyToMonoForum(object_ptr<InputPeer> &&monoforum_peer_id_)
  : monoforum_peer_id_(std::move(monoforum_peer_id_))
{}

const std::int32_t inputReplyToMonoForum::ID;

object_ptr<InputReplyTo> inputReplyToMonoForum::fetch(TlBufferParser &p) {
  return make_tl_object<inputReplyToMonoForum>(p);
}

inputReplyToMonoForum::inputReplyToMonoForum(TlBufferParser &p)
  : monoforum_peer_id_(TlFetchObject<InputPeer>::parse(p))
{}

void inputReplyToMonoForum::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(monoforum_peer_id_, s);
}

void inputReplyToMonoForum::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(monoforum_peer_id_, s);
}

void inputReplyToMonoForum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReplyToMonoForum");
    s.store_object_field("monoforum_peer_id", static_cast<const BaseObject *>(monoforum_peer_id_.get()));
    s.store_class_end();
  }
}

inputSecureFileUploaded::inputSecureFileUploaded(int64 id_, int32 parts_, string const &md5_checksum_, bytes &&file_hash_, bytes &&secret_)
  : id_(id_)
  , parts_(parts_)
  , md5_checksum_(md5_checksum_)
  , file_hash_(std::move(file_hash_))
  , secret_(std::move(secret_))
{}

const std::int32_t inputSecureFileUploaded::ID;

void inputSecureFileUploaded::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(md5_checksum_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(secret_, s);
}

void inputSecureFileUploaded::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(md5_checksum_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(secret_, s);
}

void inputSecureFileUploaded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSecureFileUploaded");
    s.store_field("id", id_);
    s.store_field("parts", parts_);
    s.store_field("md5_checksum", md5_checksum_);
    s.store_bytes_field("file_hash", file_hash_);
    s.store_bytes_field("secret", secret_);
    s.store_class_end();
  }
}

inputSecureFile::inputSecureFile(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputSecureFile::ID;

void inputSecureFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputSecureFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputSecureFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSecureFile");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputSingleMedia::inputSingleMedia(int32 flags_, object_ptr<InputMedia> &&media_, int64 random_id_, string const &message_, array<object_ptr<MessageEntity>> &&entities_)
  : flags_(flags_)
  , media_(std::move(media_))
  , random_id_(random_id_)
  , message_(message_)
  , entities_(std::move(entities_))
{}

const std::int32_t inputSingleMedia::ID;

void inputSingleMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(message_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void inputSingleMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(message_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void inputSingleMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSingleMedia");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_field("random_id", random_id_);
    s.store_field("message", message_);
    if (var0 & 1) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

object_ptr<InputStickerSet> InputStickerSet::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputStickerSetEmpty::ID:
      return inputStickerSetEmpty::fetch(p);
    case inputStickerSetID::ID:
      return inputStickerSetID::fetch(p);
    case inputStickerSetShortName::ID:
      return inputStickerSetShortName::fetch(p);
    case inputStickerSetAnimatedEmoji::ID:
      return inputStickerSetAnimatedEmoji::fetch(p);
    case inputStickerSetDice::ID:
      return inputStickerSetDice::fetch(p);
    case inputStickerSetAnimatedEmojiAnimations::ID:
      return inputStickerSetAnimatedEmojiAnimations::fetch(p);
    case inputStickerSetPremiumGifts::ID:
      return inputStickerSetPremiumGifts::fetch(p);
    case inputStickerSetEmojiGenericAnimations::ID:
      return inputStickerSetEmojiGenericAnimations::fetch(p);
    case inputStickerSetEmojiDefaultStatuses::ID:
      return inputStickerSetEmojiDefaultStatuses::fetch(p);
    case inputStickerSetEmojiDefaultTopicIcons::ID:
      return inputStickerSetEmojiDefaultTopicIcons::fetch(p);
    case inputStickerSetEmojiChannelDefaultStatuses::ID:
      return inputStickerSetEmojiChannelDefaultStatuses::fetch(p);
    case inputStickerSetTonGifts::ID:
      return inputStickerSetTonGifts::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputStickerSetEmpty::ID;

object_ptr<InputStickerSet> inputStickerSetEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetEmpty>();
}

void inputStickerSetEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetEmpty");
    s.store_class_end();
  }
}

inputStickerSetID::inputStickerSetID(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputStickerSetID::ID;

object_ptr<InputStickerSet> inputStickerSetID::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetID>(p);
}

inputStickerSetID::inputStickerSetID(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputStickerSetID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputStickerSetID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputStickerSetID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetID");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputStickerSetShortName::inputStickerSetShortName(string const &short_name_)
  : short_name_(short_name_)
{}

const std::int32_t inputStickerSetShortName::ID;

object_ptr<InputStickerSet> inputStickerSetShortName::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetShortName>(p);
}

inputStickerSetShortName::inputStickerSetShortName(TlBufferParser &p)
  : short_name_(TlFetchString<string>::parse(p))
{}

void inputStickerSetShortName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(short_name_, s);
}

void inputStickerSetShortName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(short_name_, s);
}

void inputStickerSetShortName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetShortName");
    s.store_field("short_name", short_name_);
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetAnimatedEmoji::ID;

object_ptr<InputStickerSet> inputStickerSetAnimatedEmoji::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetAnimatedEmoji>();
}

void inputStickerSetAnimatedEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetAnimatedEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetAnimatedEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetAnimatedEmoji");
    s.store_class_end();
  }
}

inputStickerSetDice::inputStickerSetDice(string const &emoticon_)
  : emoticon_(emoticon_)
{}

const std::int32_t inputStickerSetDice::ID;

object_ptr<InputStickerSet> inputStickerSetDice::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetDice>(p);
}

inputStickerSetDice::inputStickerSetDice(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
{}

void inputStickerSetDice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void inputStickerSetDice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void inputStickerSetDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetDice");
    s.store_field("emoticon", emoticon_);
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetAnimatedEmojiAnimations::ID;

object_ptr<InputStickerSet> inputStickerSetAnimatedEmojiAnimations::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetAnimatedEmojiAnimations>();
}

void inputStickerSetAnimatedEmojiAnimations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetAnimatedEmojiAnimations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetAnimatedEmojiAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetAnimatedEmojiAnimations");
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetPremiumGifts::ID;

object_ptr<InputStickerSet> inputStickerSetPremiumGifts::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetPremiumGifts>();
}

void inputStickerSetPremiumGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetPremiumGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetPremiumGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetPremiumGifts");
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetEmojiGenericAnimations::ID;

object_ptr<InputStickerSet> inputStickerSetEmojiGenericAnimations::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetEmojiGenericAnimations>();
}

void inputStickerSetEmojiGenericAnimations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiGenericAnimations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiGenericAnimations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetEmojiGenericAnimations");
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetEmojiDefaultStatuses::ID;

object_ptr<InputStickerSet> inputStickerSetEmojiDefaultStatuses::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetEmojiDefaultStatuses>();
}

void inputStickerSetEmojiDefaultStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiDefaultStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiDefaultStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetEmojiDefaultStatuses");
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetEmojiDefaultTopicIcons::ID;

object_ptr<InputStickerSet> inputStickerSetEmojiDefaultTopicIcons::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetEmojiDefaultTopicIcons>();
}

void inputStickerSetEmojiDefaultTopicIcons::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiDefaultTopicIcons::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiDefaultTopicIcons::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetEmojiDefaultTopicIcons");
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetEmojiChannelDefaultStatuses::ID;

object_ptr<InputStickerSet> inputStickerSetEmojiChannelDefaultStatuses::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetEmojiChannelDefaultStatuses>();
}

void inputStickerSetEmojiChannelDefaultStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiChannelDefaultStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetEmojiChannelDefaultStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetEmojiChannelDefaultStatuses");
    s.store_class_end();
  }
}

const std::int32_t inputStickerSetTonGifts::ID;

object_ptr<InputStickerSet> inputStickerSetTonGifts::fetch(TlBufferParser &p) {
  return make_tl_object<inputStickerSetTonGifts>();
}

void inputStickerSetTonGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputStickerSetTonGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputStickerSetTonGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetTonGifts");
    s.store_class_end();
  }
}

inputStorePaymentPremiumSubscription::inputStorePaymentPremiumSubscription(int32 flags_, bool restore_, bool upgrade_)
  : flags_(flags_)
  , restore_(restore_)
  , upgrade_(upgrade_)
{}

const std::int32_t inputStorePaymentPremiumSubscription::ID;

void inputStorePaymentPremiumSubscription::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (restore_ << 0) | (upgrade_ << 1)), s);
}

void inputStorePaymentPremiumSubscription::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (restore_ << 0) | (upgrade_ << 1)), s);
}

void inputStorePaymentPremiumSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentPremiumSubscription");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (restore_ << 0) | (upgrade_ << 1)));
    if (var0 & 1) { s.store_field("restore", true); }
    if (var0 & 2) { s.store_field("upgrade", true); }
    s.store_class_end();
  }
}

inputStorePaymentGiftPremium::inputStorePaymentGiftPremium(object_ptr<InputUser> &&user_id_, string const &currency_, int64 amount_)
  : user_id_(std::move(user_id_))
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t inputStorePaymentGiftPremium::ID;

void inputStorePaymentGiftPremium::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentGiftPremium::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentGiftPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentGiftPremium");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

inputStorePaymentPremiumGiftCode::inputStorePaymentPremiumGiftCode(int32 flags_, array<object_ptr<InputUser>> &&users_, object_ptr<InputPeer> &&boost_peer_, string const &currency_, int64 amount_, object_ptr<textWithEntities> &&message_)
  : flags_(flags_)
  , users_(std::move(users_))
  , boost_peer_(std::move(boost_peer_))
  , currency_(currency_)
  , amount_(amount_)
  , message_(std::move(message_))
{}

const std::int32_t inputStorePaymentPremiumGiftCode::ID;

void inputStorePaymentPremiumGiftCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s); }
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputStorePaymentPremiumGiftCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s); }
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputStorePaymentPremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentPremiumGiftCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_object_field("boost_peer", static_cast<const BaseObject *>(boost_peer_.get())); }
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

inputStorePaymentPremiumGiveaway::inputStorePaymentPremiumGiveaway(int32 flags_, bool only_new_subscribers_, bool winners_are_visible_, object_ptr<InputPeer> &&boost_peer_, array<object_ptr<InputPeer>> &&additional_peers_, array<string> &&countries_iso2_, string const &prize_description_, int64 random_id_, int32 until_date_, string const &currency_, int64 amount_)
  : flags_(flags_)
  , only_new_subscribers_(only_new_subscribers_)
  , winners_are_visible_(winners_are_visible_)
  , boost_peer_(std::move(boost_peer_))
  , additional_peers_(std::move(additional_peers_))
  , countries_iso2_(std::move(countries_iso2_))
  , prize_description_(prize_description_)
  , random_id_(random_id_)
  , until_date_(until_date_)
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t inputStorePaymentPremiumGiveaway::ID;

void inputStorePaymentPremiumGiveaway::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(additional_peers_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  if (var0 & 16) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(random_id_, s);
  TlStoreBinary::store(until_date_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentPremiumGiveaway::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(additional_peers_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  if (var0 & 16) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(random_id_, s);
  TlStoreBinary::store(until_date_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentPremiumGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentPremiumGiveaway");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 3)));
    if (var0 & 1) { s.store_field("only_new_subscribers", true); }
    if (var0 & 8) { s.store_field("winners_are_visible", true); }
    s.store_object_field("boost_peer", static_cast<const BaseObject *>(boost_peer_.get()));
    if (var0 & 2) { { s.store_vector_begin("additional_peers", additional_peers_.size()); for (const auto &_value : additional_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("countries_iso2", countries_iso2_.size()); for (const auto &_value : countries_iso2_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("prize_description", prize_description_); }
    s.store_field("random_id", random_id_);
    s.store_field("until_date", until_date_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

inputStorePaymentStarsTopup::inputStorePaymentStarsTopup(int32 flags_, int64 stars_, string const &currency_, int64 amount_, object_ptr<InputPeer> &&spend_purpose_peer_)
  : flags_(flags_)
  , stars_(stars_)
  , currency_(currency_)
  , amount_(amount_)
  , spend_purpose_peer_(std::move(spend_purpose_peer_))
{}

const std::int32_t inputStorePaymentStarsTopup::ID;

void inputStorePaymentStarsTopup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(stars_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(spend_purpose_peer_, s); }
}

void inputStorePaymentStarsTopup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(stars_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(spend_purpose_peer_, s); }
}

void inputStorePaymentStarsTopup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentStarsTopup");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("stars", stars_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    if (var0 & 1) { s.store_object_field("spend_purpose_peer", static_cast<const BaseObject *>(spend_purpose_peer_.get())); }
    s.store_class_end();
  }
}

inputStorePaymentStarsGift::inputStorePaymentStarsGift(object_ptr<InputUser> &&user_id_, int64 stars_, string const &currency_, int64 amount_)
  : user_id_(std::move(user_id_))
  , stars_(stars_)
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t inputStorePaymentStarsGift::ID;

void inputStorePaymentStarsGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(stars_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentStarsGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(stars_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentStarsGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentStarsGift");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("stars", stars_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

inputStorePaymentStarsGiveaway::inputStorePaymentStarsGiveaway(int32 flags_, bool only_new_subscribers_, bool winners_are_visible_, int64 stars_, object_ptr<InputPeer> &&boost_peer_, array<object_ptr<InputPeer>> &&additional_peers_, array<string> &&countries_iso2_, string const &prize_description_, int64 random_id_, int32 until_date_, string const &currency_, int64 amount_, int32 users_)
  : flags_(flags_)
  , only_new_subscribers_(only_new_subscribers_)
  , winners_are_visible_(winners_are_visible_)
  , stars_(stars_)
  , boost_peer_(std::move(boost_peer_))
  , additional_peers_(std::move(additional_peers_))
  , countries_iso2_(std::move(countries_iso2_))
  , prize_description_(prize_description_)
  , random_id_(random_id_)
  , until_date_(until_date_)
  , currency_(currency_)
  , amount_(amount_)
  , users_(users_)
{}

const std::int32_t inputStorePaymentStarsGiveaway::ID;

void inputStorePaymentStarsGiveaway::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 3)), s);
  TlStoreBinary::store(stars_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(additional_peers_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  if (var0 & 16) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(random_id_, s);
  TlStoreBinary::store(until_date_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
  TlStoreBinary::store(users_, s);
}

void inputStorePaymentStarsGiveaway::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 3)), s);
  TlStoreBinary::store(stars_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(additional_peers_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  if (var0 & 16) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(random_id_, s);
  TlStoreBinary::store(until_date_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
  TlStoreBinary::store(users_, s);
}

void inputStorePaymentStarsGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentStarsGiveaway");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 3)));
    if (var0 & 1) { s.store_field("only_new_subscribers", true); }
    if (var0 & 8) { s.store_field("winners_are_visible", true); }
    s.store_field("stars", stars_);
    s.store_object_field("boost_peer", static_cast<const BaseObject *>(boost_peer_.get()));
    if (var0 & 2) { { s.store_vector_begin("additional_peers", additional_peers_.size()); for (const auto &_value : additional_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("countries_iso2", countries_iso2_.size()); for (const auto &_value : countries_iso2_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("prize_description", prize_description_); }
    s.store_field("random_id", random_id_);
    s.store_field("until_date", until_date_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("users", users_);
    s.store_class_end();
  }
}

inputStorePaymentAuthCode::inputStorePaymentAuthCode(int32 flags_, bool restore_, string const &phone_number_, string const &phone_code_hash_, string const &currency_, int64 amount_)
  : flags_(flags_)
  , restore_(restore_)
  , phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t inputStorePaymentAuthCode::ID;

void inputStorePaymentAuthCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (restore_ << 0)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentAuthCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (restore_ << 0)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void inputStorePaymentAuthCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStorePaymentAuthCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (restore_ << 0)));
    if (var0 & 1) { s.store_field("restore", true); }
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

jsonObjectValue::jsonObjectValue(string const &key_, object_ptr<JSONValue> &&value_)
  : key_(key_)
  , value_(std::move(value_))
{}

const std::int32_t jsonObjectValue::ID;

object_ptr<jsonObjectValue> jsonObjectValue::fetch(TlBufferParser &p) {
  return make_tl_object<jsonObjectValue>(p);
}

jsonObjectValue::jsonObjectValue(TlBufferParser &p)
  : key_(TlFetchString<string>::parse(p))
  , value_(TlFetchObject<JSONValue>::parse(p))
{}

void jsonObjectValue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(key_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(value_, s);
}

void jsonObjectValue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(key_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(value_, s);
}

void jsonObjectValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonObjectValue");
    s.store_field("key", key_);
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_class_end();
  }
}

object_ptr<JSONValue> JSONValue::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case jsonNull::ID:
      return jsonNull::fetch(p);
    case jsonBool::ID:
      return jsonBool::fetch(p);
    case jsonNumber::ID:
      return jsonNumber::fetch(p);
    case jsonString::ID:
      return jsonString::fetch(p);
    case jsonArray::ID:
      return jsonArray::fetch(p);
    case jsonObject::ID:
      return jsonObject::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t jsonNull::ID;

object_ptr<JSONValue> jsonNull::fetch(TlBufferParser &p) {
  return make_tl_object<jsonNull>();
}

void jsonNull::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void jsonNull::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void jsonNull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonNull");
    s.store_class_end();
  }
}

jsonBool::jsonBool(bool value_)
  : value_(value_)
{}

const std::int32_t jsonBool::ID;

object_ptr<JSONValue> jsonBool::fetch(TlBufferParser &p) {
  return make_tl_object<jsonBool>(p);
}

jsonBool::jsonBool(TlBufferParser &p)
  : value_(TlFetchBool::parse(p))
{}

void jsonBool::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBool::store(value_, s);
}

void jsonBool::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBool::store(value_, s);
}

void jsonBool::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonBool");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonNumber::jsonNumber(double value_)
  : value_(value_)
{}

const std::int32_t jsonNumber::ID;

object_ptr<JSONValue> jsonNumber::fetch(TlBufferParser &p) {
  return make_tl_object<jsonNumber>(p);
}

jsonNumber::jsonNumber(TlBufferParser &p)
  : value_(TlFetchDouble::parse(p))
{}

void jsonNumber::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(value_, s);
}

void jsonNumber::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(value_, s);
}

void jsonNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonNumber");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonString::jsonString(string const &value_)
  : value_(value_)
{}

const std::int32_t jsonString::ID;

object_ptr<JSONValue> jsonString::fetch(TlBufferParser &p) {
  return make_tl_object<jsonString>(p);
}

jsonString::jsonString(TlBufferParser &p)
  : value_(TlFetchString<string>::parse(p))
{}

void jsonString::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(value_, s);
}

void jsonString::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(value_, s);
}

void jsonString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonString");
    s.store_field("value", value_);
    s.store_class_end();
  }
}

jsonArray::jsonArray(array<object_ptr<JSONValue>> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t jsonArray::ID;

object_ptr<JSONValue> jsonArray::fetch(TlBufferParser &p) {
  return make_tl_object<jsonArray>(p);
}

jsonArray::jsonArray(TlBufferParser &p)
  : value_(TlFetchBoxed<TlFetchVector<TlFetchObject<JSONValue>>, 481674261>::parse(p))
{}

void jsonArray::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(value_, s);
}

void jsonArray::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(value_, s);
}

void jsonArray::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonArray");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

jsonObject::jsonObject(array<object_ptr<jsonObjectValue>> &&value_)
  : value_(std::move(value_))
{}

const std::int32_t jsonObject::ID;

object_ptr<JSONValue> jsonObject::fetch(TlBufferParser &p) {
  return make_tl_object<jsonObject>(p);
}

jsonObject::jsonObject(TlBufferParser &p)
  : value_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<jsonObjectValue>, -1059185703>>, 481674261>::parse(p))
{}

void jsonObject::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1059185703>>, 481674261>::store(value_, s);
}

void jsonObject::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1059185703>>, 481674261>::store(value_, s);
}

void jsonObject::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "jsonObject");
    { s.store_vector_begin("value", value_.size()); for (const auto &_value : value_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<MessageExtendedMedia> MessageExtendedMedia::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messageExtendedMediaPreview::ID:
      return messageExtendedMediaPreview::fetch(p);
    case messageExtendedMedia::ID:
      return messageExtendedMedia::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messageExtendedMediaPreview::messageExtendedMediaPreview()
  : flags_()
  , w_()
  , h_()
  , thumb_()
  , video_duration_()
{}

messageExtendedMediaPreview::messageExtendedMediaPreview(int32 flags_, int32 w_, int32 h_, object_ptr<PhotoSize> &&thumb_, int32 video_duration_)
  : flags_(flags_)
  , w_(w_)
  , h_(h_)
  , thumb_(std::move(thumb_))
  , video_duration_(video_duration_)
{}

const std::int32_t messageExtendedMediaPreview::ID;

object_ptr<MessageExtendedMedia> messageExtendedMediaPreview::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageExtendedMediaPreview> res = make_tl_object<messageExtendedMediaPreview>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->w_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->h_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->thumb_ = TlFetchObject<PhotoSize>::parse(p); }
  if (var0 & 4) { res->video_duration_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageExtendedMediaPreview::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(w_, s); }
  if (var0 & 1) { TlStoreBinary::store(h_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_duration_, s); }
}

void messageExtendedMediaPreview::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(w_, s); }
  if (var0 & 1) { TlStoreBinary::store(h_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_duration_, s); }
}

void messageExtendedMediaPreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExtendedMediaPreview");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("w", w_); }
    if (var0 & 1) { s.store_field("h", h_); }
    if (var0 & 2) { s.store_object_field("thumb", static_cast<const BaseObject *>(thumb_.get())); }
    if (var0 & 4) { s.store_field("video_duration", video_duration_); }
    s.store_class_end();
  }
}

messageExtendedMedia::messageExtendedMedia(object_ptr<MessageMedia> &&media_)
  : media_(std::move(media_))
{}

const std::int32_t messageExtendedMedia::ID;

object_ptr<MessageExtendedMedia> messageExtendedMedia::fetch(TlBufferParser &p) {
  return make_tl_object<messageExtendedMedia>(p);
}

messageExtendedMedia::messageExtendedMedia(TlBufferParser &p)
  : media_(TlFetchObject<MessageMedia>::parse(p))
{}

void messageExtendedMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messageExtendedMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messageExtendedMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageExtendedMedia");
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

object_ptr<MessageReplyHeader> MessageReplyHeader::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messageReplyHeader::ID:
      return messageReplyHeader::fetch(p);
    case messageReplyStoryHeader::ID:
      return messageReplyStoryHeader::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messageReplyHeader::messageReplyHeader()
  : flags_()
  , reply_to_scheduled_()
  , forum_topic_()
  , quote_()
  , reply_to_msg_id_()
  , reply_to_peer_id_()
  , reply_from_()
  , reply_media_()
  , reply_to_top_id_()
  , quote_text_()
  , quote_entities_()
  , quote_offset_()
  , todo_item_id_()
  , poll_option_()
{}

const std::int32_t messageReplyHeader::ID;

object_ptr<MessageReplyHeader> messageReplyHeader::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageReplyHeader> res = make_tl_object<messageReplyHeader>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->reply_to_scheduled_ = (var0 & 4) != 0;
  res->forum_topic_ = (var0 & 8) != 0;
  res->quote_ = (var0 & 512) != 0;
  if (var0 & 16) { res->reply_to_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->reply_to_peer_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 32) { res->reply_from_ = TlFetchBoxed<TlFetchObject<messageFwdHeader>, 1313731771>::parse(p); }
  if (var0 & 256) { res->reply_media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (var0 & 2) { res->reply_to_top_id_ = TlFetchInt::parse(p); }
  if (var0 & 64) { res->quote_text_ = TlFetchString<string>::parse(p); }
  if (var0 & 128) { res->quote_entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 1024) { res->quote_offset_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->todo_item_id_ = TlFetchInt::parse(p); }
  if (var0 & 4096) { res->poll_option_ = TlFetchBytes<bytes>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageReplyHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplyHeader");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (reply_to_scheduled_ << 2) | (forum_topic_ << 3) | (quote_ << 9)));
    if (var0 & 4) { s.store_field("reply_to_scheduled", true); }
    if (var0 & 8) { s.store_field("forum_topic", true); }
    if (var0 & 512) { s.store_field("quote", true); }
    if (var0 & 16) { s.store_field("reply_to_msg_id", reply_to_msg_id_); }
    if (var0 & 1) { s.store_object_field("reply_to_peer_id", static_cast<const BaseObject *>(reply_to_peer_id_.get())); }
    if (var0 & 32) { s.store_object_field("reply_from", static_cast<const BaseObject *>(reply_from_.get())); }
    if (var0 & 256) { s.store_object_field("reply_media", static_cast<const BaseObject *>(reply_media_.get())); }
    if (var0 & 2) { s.store_field("reply_to_top_id", reply_to_top_id_); }
    if (var0 & 64) { s.store_field("quote_text", quote_text_); }
    if (var0 & 128) { { s.store_vector_begin("quote_entities", quote_entities_.size()); for (const auto &_value : quote_entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1024) { s.store_field("quote_offset", quote_offset_); }
    if (var0 & 2048) { s.store_field("todo_item_id", todo_item_id_); }
    if (var0 & 4096) { s.store_bytes_field("poll_option", poll_option_); }
    s.store_class_end();
  }
}

const std::int32_t messageReplyStoryHeader::ID;

object_ptr<MessageReplyHeader> messageReplyStoryHeader::fetch(TlBufferParser &p) {
  return make_tl_object<messageReplyStoryHeader>(p);
}

messageReplyStoryHeader::messageReplyStoryHeader(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , story_id_(TlFetchInt::parse(p))
{}

void messageReplyStoryHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplyStoryHeader");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("story_id", story_id_);
    s.store_class_end();
  }
}

missingInvitee::missingInvitee()
  : flags_()
  , premium_would_allow_invite_()
  , premium_required_for_pm_()
  , user_id_()
{}

const std::int32_t missingInvitee::ID;

object_ptr<missingInvitee> missingInvitee::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<missingInvitee> res = make_tl_object<missingInvitee>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->premium_would_allow_invite_ = (var0 & 1) != 0;
  res->premium_required_for_pm_ = (var0 & 2) != 0;
  res->user_id_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void missingInvitee::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "missingInvitee");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (premium_would_allow_invite_ << 0) | (premium_required_for_pm_ << 1)));
    if (var0 & 1) { s.store_field("premium_would_allow_invite", true); }
    if (var0 & 2) { s.store_field("premium_required_for_pm", true); }
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

page::page()
  : flags_()
  , part_()
  , rtl_()
  , v2_()
  , url_()
  , blocks_()
  , photos_()
  , documents_()
  , views_()
{}

page::page(int32 flags_, bool part_, bool rtl_, bool v2_, string const &url_, array<object_ptr<PageBlock>> &&blocks_, array<object_ptr<Photo>> &&photos_, array<object_ptr<Document>> &&documents_, int32 views_)
  : flags_(flags_)
  , part_(part_)
  , rtl_(rtl_)
  , v2_(v2_)
  , url_(url_)
  , blocks_(std::move(blocks_))
  , photos_(std::move(photos_))
  , documents_(std::move(documents_))
  , views_(views_)
{}

const std::int32_t page::ID;

object_ptr<page> page::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<page> res = make_tl_object<page>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->part_ = (var0 & 1) != 0;
  res->rtl_ = (var0 & 2) != 0;
  res->v2_ = (var0 & 4) != 0;
  res->url_ = TlFetchString<string>::parse(p);
  res->blocks_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p);
  res->photos_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Photo>>, 481674261>::parse(p);
  res->documents_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p);
  if (var0 & 8) { res->views_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void page::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (part_ << 0) | (rtl_ << 1) | (v2_ << 2)), s);
  TlStoreString::store(url_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(photos_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s);
  if (var0 & 8) { TlStoreBinary::store(views_, s); }
}

void page::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (part_ << 0) | (rtl_ << 1) | (v2_ << 2)), s);
  TlStoreString::store(url_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(photos_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s);
  if (var0 & 8) { TlStoreBinary::store(views_, s); }
}

void page::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "page");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (part_ << 0) | (rtl_ << 1) | (v2_ << 2)));
    if (var0 & 1) { s.store_field("part", true); }
    if (var0 & 2) { s.store_field("rtl", true); }
    if (var0 & 4) { s.store_field("v2", true); }
    s.store_field("url", url_);
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("photos", photos_.size()); for (const auto &_value : photos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 8) { s.store_field("views", views_); }
    s.store_class_end();
  }
}

pageCaption::pageCaption(object_ptr<RichText> &&text_, object_ptr<RichText> &&credit_)
  : text_(std::move(text_))
  , credit_(std::move(credit_))
{}

const std::int32_t pageCaption::ID;

object_ptr<pageCaption> pageCaption::fetch(TlBufferParser &p) {
  return make_tl_object<pageCaption>(p);
}

pageCaption::pageCaption(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , credit_(TlFetchObject<RichText>::parse(p))
{}

void pageCaption::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(credit_, s);
}

void pageCaption::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(credit_, s);
}

void pageCaption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageCaption");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("credit", static_cast<const BaseObject *>(credit_.get()));
    s.store_class_end();
  }
}

pageTableCell::pageTableCell()
  : flags_()
  , header_()
  , align_center_()
  , align_right_()
  , valign_middle_()
  , valign_bottom_()
  , text_()
  , colspan_()
  , rowspan_()
{}

pageTableCell::pageTableCell(int32 flags_, bool header_, bool align_center_, bool align_right_, bool valign_middle_, bool valign_bottom_, object_ptr<RichText> &&text_, int32 colspan_, int32 rowspan_)
  : flags_(flags_)
  , header_(header_)
  , align_center_(align_center_)
  , align_right_(align_right_)
  , valign_middle_(valign_middle_)
  , valign_bottom_(valign_bottom_)
  , text_(std::move(text_))
  , colspan_(colspan_)
  , rowspan_(rowspan_)
{}

const std::int32_t pageTableCell::ID;

object_ptr<pageTableCell> pageTableCell::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageTableCell> res = make_tl_object<pageTableCell>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->header_ = (var0 & 1) != 0;
  res->align_center_ = (var0 & 8) != 0;
  res->align_right_ = (var0 & 16) != 0;
  res->valign_middle_ = (var0 & 32) != 0;
  res->valign_bottom_ = (var0 & 64) != 0;
  if (var0 & 128) { res->text_ = TlFetchObject<RichText>::parse(p); }
  if (var0 & 2) { res->colspan_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->rowspan_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void pageTableCell::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (header_ << 0) | (align_center_ << 3) | (align_right_ << 4) | (valign_middle_ << 5) | (valign_bottom_ << 6)), s);
  if (var0 & 128) { TlStoreBoxedUnknown<TlStoreObject>::store(text_, s); }
  if (var0 & 2) { TlStoreBinary::store(colspan_, s); }
  if (var0 & 4) { TlStoreBinary::store(rowspan_, s); }
}

void pageTableCell::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (header_ << 0) | (align_center_ << 3) | (align_right_ << 4) | (valign_middle_ << 5) | (valign_bottom_ << 6)), s);
  if (var0 & 128) { TlStoreBoxedUnknown<TlStoreObject>::store(text_, s); }
  if (var0 & 2) { TlStoreBinary::store(colspan_, s); }
  if (var0 & 4) { TlStoreBinary::store(rowspan_, s); }
}

void pageTableCell::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageTableCell");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (header_ << 0) | (align_center_ << 3) | (align_right_ << 4) | (valign_middle_ << 5) | (valign_bottom_ << 6)));
    if (var0 & 1) { s.store_field("header", true); }
    if (var0 & 8) { s.store_field("align_center", true); }
    if (var0 & 16) { s.store_field("align_right", true); }
    if (var0 & 32) { s.store_field("valign_middle", true); }
    if (var0 & 64) { s.store_field("valign_bottom", true); }
    if (var0 & 128) { s.store_object_field("text", static_cast<const BaseObject *>(text_.get())); }
    if (var0 & 2) { s.store_field("colspan", colspan_); }
    if (var0 & 4) { s.store_field("rowspan", rowspan_); }
    s.store_class_end();
  }
}

object_ptr<PasswordKdfAlgo> PasswordKdfAlgo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case passwordKdfAlgoUnknown::ID:
      return passwordKdfAlgoUnknown::fetch(p);
    case passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::ID:
      return passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t passwordKdfAlgoUnknown::ID;

object_ptr<PasswordKdfAlgo> passwordKdfAlgoUnknown::fetch(TlBufferParser &p) {
  return make_tl_object<passwordKdfAlgoUnknown>();
}

void passwordKdfAlgoUnknown::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void passwordKdfAlgoUnknown::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void passwordKdfAlgoUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passwordKdfAlgoUnknown");
    s.store_class_end();
  }
}

passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow(bytes &&salt1_, bytes &&salt2_, int32 g_, bytes &&p_)
  : salt1_(std::move(salt1_))
  , salt2_(std::move(salt2_))
  , g_(g_)
  , p_(std::move(p_))
{}

const std::int32_t passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::ID;

object_ptr<PasswordKdfAlgo> passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::fetch(TlBufferParser &p) {
  return make_tl_object<passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow>(p);
}

passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow(TlBufferParser &p)
  : salt1_(TlFetchBytes<bytes>::parse(p))
  , salt2_(TlFetchBytes<bytes>::parse(p))
  , g_(TlFetchInt::parse(p))
  , p_(TlFetchBytes<bytes>::parse(p))
{}

void passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(salt1_, s);
  TlStoreString::store(salt2_, s);
  TlStoreBinary::store(g_, s);
  TlStoreString::store(p_, s);
}

void passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(salt1_, s);
  TlStoreString::store(salt2_, s);
  TlStoreBinary::store(g_, s);
  TlStoreString::store(p_, s);
}

void passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow");
    s.store_bytes_field("salt1", salt1_);
    s.store_bytes_field("salt2", salt2_);
    s.store_field("g", g_);
    s.store_bytes_field("p", p_);
    s.store_class_end();
  }
}

const std::int32_t receivedNotifyMessage::ID;

object_ptr<receivedNotifyMessage> receivedNotifyMessage::fetch(TlBufferParser &p) {
  return make_tl_object<receivedNotifyMessage>(p);
}

receivedNotifyMessage::receivedNotifyMessage(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , flags_(TlFetchInt::parse(p))
{}

void receivedNotifyMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "receivedNotifyMessage");
    s.store_field("id", id_);
    s.store_field("flags", flags_);
    s.store_class_end();
  }
}

restrictionReason::restrictionReason(string const &platform_, string const &reason_, string const &text_)
  : platform_(platform_)
  , reason_(reason_)
  , text_(text_)
{}

const std::int32_t restrictionReason::ID;

object_ptr<restrictionReason> restrictionReason::fetch(TlBufferParser &p) {
  return make_tl_object<restrictionReason>(p);
}

restrictionReason::restrictionReason(TlBufferParser &p)
  : platform_(TlFetchString<string>::parse(p))
  , reason_(TlFetchString<string>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void restrictionReason::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(platform_, s);
  TlStoreString::store(reason_, s);
  TlStoreString::store(text_, s);
}

void restrictionReason::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(platform_, s);
  TlStoreString::store(reason_, s);
  TlStoreString::store(text_, s);
}

void restrictionReason::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "restrictionReason");
    s.store_field("platform", platform_);
    s.store_field("reason", reason_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

object_ptr<SavedDialog> SavedDialog::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case savedDialog::ID:
      return savedDialog::fetch(p);
    case monoForumDialog::ID:
      return monoForumDialog::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

savedDialog::savedDialog()
  : flags_()
  , pinned_()
  , peer_()
  , top_message_()
{}

const std::int32_t savedDialog::ID;

object_ptr<SavedDialog> savedDialog::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<savedDialog> res = make_tl_object<savedDialog>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 4) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->top_message_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void savedDialog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedDialog");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 2)));
    if (var0 & 4) { s.store_field("pinned", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_message", top_message_);
    s.store_class_end();
  }
}

monoForumDialog::monoForumDialog()
  : flags_()
  , unread_mark_()
  , nopaid_messages_exception_()
  , peer_()
  , top_message_()
  , read_inbox_max_id_()
  , read_outbox_max_id_()
  , unread_count_()
  , unread_reactions_count_()
  , draft_()
{}

const std::int32_t monoForumDialog::ID;

object_ptr<SavedDialog> monoForumDialog::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<monoForumDialog> res = make_tl_object<monoForumDialog>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->unread_mark_ = (var0 & 8) != 0;
  res->nopaid_messages_exception_ = (var0 & 16) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->top_message_ = TlFetchInt::parse(p);
  res->read_inbox_max_id_ = TlFetchInt::parse(p);
  res->read_outbox_max_id_ = TlFetchInt::parse(p);
  res->unread_count_ = TlFetchInt::parse(p);
  res->unread_reactions_count_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->draft_ = TlFetchObject<DraftMessage>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void monoForumDialog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "monoForumDialog");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (unread_mark_ << 3) | (nopaid_messages_exception_ << 4)));
    if (var0 & 8) { s.store_field("unread_mark", true); }
    if (var0 & 16) { s.store_field("nopaid_messages_exception", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_message", top_message_);
    s.store_field("read_inbox_max_id", read_inbox_max_id_);
    s.store_field("read_outbox_max_id", read_outbox_max_id_);
    s.store_field("unread_count", unread_count_);
    s.store_field("unread_reactions_count", unread_reactions_count_);
    if (var0 & 2) { s.store_object_field("draft", static_cast<const BaseObject *>(draft_.get())); }
    s.store_class_end();
  }
}

const std::int32_t searchResultsCalendarPeriod::ID;

object_ptr<searchResultsCalendarPeriod> searchResultsCalendarPeriod::fetch(TlBufferParser &p) {
  return make_tl_object<searchResultsCalendarPeriod>(p);
}

searchResultsCalendarPeriod::searchResultsCalendarPeriod(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
  , min_msg_id_(TlFetchInt::parse(p))
  , max_msg_id_(TlFetchInt::parse(p))
  , count_(TlFetchInt::parse(p))
{}

void searchResultsCalendarPeriod::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchResultsCalendarPeriod");
    s.store_field("date", date_);
    s.store_field("min_msg_id", min_msg_id_);
    s.store_field("max_msg_id", max_msg_id_);
    s.store_field("count", count_);
    s.store_class_end();
  }
}

object_ptr<SecurePlainData> SecurePlainData::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case securePlainPhone::ID:
      return securePlainPhone::fetch(p);
    case securePlainEmail::ID:
      return securePlainEmail::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

securePlainPhone::securePlainPhone(string const &phone_)
  : phone_(phone_)
{}

const std::int32_t securePlainPhone::ID;

object_ptr<SecurePlainData> securePlainPhone::fetch(TlBufferParser &p) {
  return make_tl_object<securePlainPhone>(p);
}

securePlainPhone::securePlainPhone(TlBufferParser &p)
  : phone_(TlFetchString<string>::parse(p))
{}

void securePlainPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_, s);
}

void securePlainPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_, s);
}

void securePlainPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "securePlainPhone");
    s.store_field("phone", phone_);
    s.store_class_end();
  }
}

securePlainEmail::securePlainEmail(string const &email_)
  : email_(email_)
{}

const std::int32_t securePlainEmail::ID;

object_ptr<SecurePlainData> securePlainEmail::fetch(TlBufferParser &p) {
  return make_tl_object<securePlainEmail>(p);
}

securePlainEmail::securePlainEmail(TlBufferParser &p)
  : email_(TlFetchString<string>::parse(p))
{}

void securePlainEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(email_, s);
}

void securePlainEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(email_, s);
}

void securePlainEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "securePlainEmail");
    s.store_field("email", email_);
    s.store_class_end();
  }
}

object_ptr<StarGiftAttribute> StarGiftAttribute::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starGiftAttributeModel::ID:
      return starGiftAttributeModel::fetch(p);
    case starGiftAttributePattern::ID:
      return starGiftAttributePattern::fetch(p);
    case starGiftAttributeBackdrop::ID:
      return starGiftAttributeBackdrop::fetch(p);
    case starGiftAttributeOriginalDetails::ID:
      return starGiftAttributeOriginalDetails::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

starGiftAttributeModel::starGiftAttributeModel()
  : flags_()
  , crafted_()
  , name_()
  , document_()
  , rarity_()
{}

starGiftAttributeModel::starGiftAttributeModel(int32 flags_, bool crafted_, string const &name_, object_ptr<Document> &&document_, object_ptr<StarGiftAttributeRarity> &&rarity_)
  : flags_(flags_)
  , crafted_(crafted_)
  , name_(name_)
  , document_(std::move(document_))
  , rarity_(std::move(rarity_))
{}

const std::int32_t starGiftAttributeModel::ID;

object_ptr<StarGiftAttribute> starGiftAttributeModel::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftAttributeModel> res = make_tl_object<starGiftAttributeModel>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->crafted_ = (var0 & 1) != 0;
  res->name_ = TlFetchString<string>::parse(p);
  res->document_ = TlFetchObject<Document>::parse(p);
  res->rarity_ = TlFetchObject<StarGiftAttributeRarity>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void starGiftAttributeModel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (crafted_ << 0)), s);
  TlStoreString::store(name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rarity_, s);
}

void starGiftAttributeModel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (crafted_ << 0)), s);
  TlStoreString::store(name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rarity_, s);
}

void starGiftAttributeModel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeModel");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (crafted_ << 0)));
    if (var0 & 1) { s.store_field("crafted", true); }
    s.store_field("name", name_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("rarity", static_cast<const BaseObject *>(rarity_.get()));
    s.store_class_end();
  }
}

starGiftAttributePattern::starGiftAttributePattern(string const &name_, object_ptr<Document> &&document_, object_ptr<StarGiftAttributeRarity> &&rarity_)
  : name_(name_)
  , document_(std::move(document_))
  , rarity_(std::move(rarity_))
{}

const std::int32_t starGiftAttributePattern::ID;

object_ptr<StarGiftAttribute> starGiftAttributePattern::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributePattern>(p);
}

starGiftAttributePattern::starGiftAttributePattern(TlBufferParser &p)
  : name_(TlFetchString<string>::parse(p))
  , document_(TlFetchObject<Document>::parse(p))
  , rarity_(TlFetchObject<StarGiftAttributeRarity>::parse(p))
{}

void starGiftAttributePattern::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rarity_, s);
}

void starGiftAttributePattern::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rarity_, s);
}

void starGiftAttributePattern::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributePattern");
    s.store_field("name", name_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("rarity", static_cast<const BaseObject *>(rarity_.get()));
    s.store_class_end();
  }
}

starGiftAttributeBackdrop::starGiftAttributeBackdrop(string const &name_, int32 backdrop_id_, int32 center_color_, int32 edge_color_, int32 pattern_color_, int32 text_color_, object_ptr<StarGiftAttributeRarity> &&rarity_)
  : name_(name_)
  , backdrop_id_(backdrop_id_)
  , center_color_(center_color_)
  , edge_color_(edge_color_)
  , pattern_color_(pattern_color_)
  , text_color_(text_color_)
  , rarity_(std::move(rarity_))
{}

const std::int32_t starGiftAttributeBackdrop::ID;

object_ptr<StarGiftAttribute> starGiftAttributeBackdrop::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeBackdrop>(p);
}

starGiftAttributeBackdrop::starGiftAttributeBackdrop(TlBufferParser &p)
  : name_(TlFetchString<string>::parse(p))
  , backdrop_id_(TlFetchInt::parse(p))
  , center_color_(TlFetchInt::parse(p))
  , edge_color_(TlFetchInt::parse(p))
  , pattern_color_(TlFetchInt::parse(p))
  , text_color_(TlFetchInt::parse(p))
  , rarity_(TlFetchObject<StarGiftAttributeRarity>::parse(p))
{}

void starGiftAttributeBackdrop::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(name_, s);
  TlStoreBinary::store(backdrop_id_, s);
  TlStoreBinary::store(center_color_, s);
  TlStoreBinary::store(edge_color_, s);
  TlStoreBinary::store(pattern_color_, s);
  TlStoreBinary::store(text_color_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rarity_, s);
}

void starGiftAttributeBackdrop::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(name_, s);
  TlStoreBinary::store(backdrop_id_, s);
  TlStoreBinary::store(center_color_, s);
  TlStoreBinary::store(edge_color_, s);
  TlStoreBinary::store(pattern_color_, s);
  TlStoreBinary::store(text_color_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(rarity_, s);
}

void starGiftAttributeBackdrop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeBackdrop");
    s.store_field("name", name_);
    s.store_field("backdrop_id", backdrop_id_);
    s.store_field("center_color", center_color_);
    s.store_field("edge_color", edge_color_);
    s.store_field("pattern_color", pattern_color_);
    s.store_field("text_color", text_color_);
    s.store_object_field("rarity", static_cast<const BaseObject *>(rarity_.get()));
    s.store_class_end();
  }
}

starGiftAttributeOriginalDetails::starGiftAttributeOriginalDetails()
  : flags_()
  , sender_id_()
  , recipient_id_()
  , date_()
  , message_()
{}

starGiftAttributeOriginalDetails::starGiftAttributeOriginalDetails(int32 flags_, object_ptr<Peer> &&sender_id_, object_ptr<Peer> &&recipient_id_, int32 date_, object_ptr<textWithEntities> &&message_)
  : flags_(flags_)
  , sender_id_(std::move(sender_id_))
  , recipient_id_(std::move(recipient_id_))
  , date_(date_)
  , message_(std::move(message_))
{}

const std::int32_t starGiftAttributeOriginalDetails::ID;

object_ptr<StarGiftAttribute> starGiftAttributeOriginalDetails::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftAttributeOriginalDetails> res = make_tl_object<starGiftAttributeOriginalDetails>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->sender_id_ = TlFetchObject<Peer>::parse(p); }
  res->recipient_id_ = TlFetchObject<Peer>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void starGiftAttributeOriginalDetails::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(sender_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(recipient_id_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void starGiftAttributeOriginalDetails::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(sender_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(recipient_id_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void starGiftAttributeOriginalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeOriginalDetails");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("sender_id", static_cast<const BaseObject *>(sender_id_.get())); }
    s.store_object_field("recipient_id", static_cast<const BaseObject *>(recipient_id_.get()));
    s.store_field("date", date_);
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

object_ptr<StarGiftAuctionRound> StarGiftAuctionRound::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starGiftAuctionRound::ID:
      return starGiftAuctionRound::fetch(p);
    case starGiftAuctionRoundExtendable::ID:
      return starGiftAuctionRoundExtendable::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t starGiftAuctionRound::ID;

object_ptr<StarGiftAuctionRound> starGiftAuctionRound::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAuctionRound>(p);
}

starGiftAuctionRound::starGiftAuctionRound(TlBufferParser &p)
  : num_(TlFetchInt::parse(p))
  , duration_(TlFetchInt::parse(p))
{}

void starGiftAuctionRound::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionRound");
    s.store_field("num", num_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

const std::int32_t starGiftAuctionRoundExtendable::ID;

object_ptr<StarGiftAuctionRound> starGiftAuctionRoundExtendable::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAuctionRoundExtendable>(p);
}

starGiftAuctionRoundExtendable::starGiftAuctionRoundExtendable(TlBufferParser &p)
  : num_(TlFetchInt::parse(p))
  , duration_(TlFetchInt::parse(p))
  , extend_top_(TlFetchInt::parse(p))
  , extend_window_(TlFetchInt::parse(p))
{}

void starGiftAuctionRoundExtendable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionRoundExtendable");
    s.store_field("num", num_);
    s.store_field("duration", duration_);
    s.store_field("extend_top", extend_top_);
    s.store_field("extend_window", extend_window_);
    s.store_class_end();
  }
}

const std::int32_t stickerKeyword::ID;

object_ptr<stickerKeyword> stickerKeyword::fetch(TlBufferParser &p) {
  return make_tl_object<stickerKeyword>(p);
}

stickerKeyword::stickerKeyword(TlBufferParser &p)
  : document_id_(TlFetchLong::parse(p))
  , keyword_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void stickerKeyword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerKeyword");
    s.store_field("document_id", document_id_);
    { s.store_vector_begin("keyword", keyword_.size()); for (const auto &_value : keyword_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

storyFwdHeader::storyFwdHeader()
  : flags_()
  , modified_()
  , from_()
  , from_name_()
  , story_id_()
{}

storyFwdHeader::storyFwdHeader(int32 flags_, bool modified_, object_ptr<Peer> &&from_, string const &from_name_, int32 story_id_)
  : flags_(flags_)
  , modified_(modified_)
  , from_(std::move(from_))
  , from_name_(from_name_)
  , story_id_(story_id_)
{}

const std::int32_t storyFwdHeader::ID;

object_ptr<storyFwdHeader> storyFwdHeader::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyFwdHeader> res = make_tl_object<storyFwdHeader>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->modified_ = (var0 & 8) != 0;
  if (var0 & 1) { res->from_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 2) { res->from_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->story_id_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void storyFwdHeader::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (modified_ << 3)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(from_, s); }
  if (var0 & 2) { TlStoreString::store(from_name_, s); }
  if (var0 & 4) { TlStoreBinary::store(story_id_, s); }
}

void storyFwdHeader::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (modified_ << 3)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(from_, s); }
  if (var0 & 2) { TlStoreString::store(from_name_, s); }
  if (var0 & 4) { TlStoreBinary::store(story_id_, s); }
}

void storyFwdHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyFwdHeader");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (modified_ << 3)));
    if (var0 & 8) { s.store_field("modified", true); }
    if (var0 & 1) { s.store_object_field("from", static_cast<const BaseObject *>(from_.get())); }
    if (var0 & 2) { s.store_field("from_name", from_name_); }
    if (var0 & 4) { s.store_field("story_id", story_id_); }
    s.store_class_end();
  }
}

object_ptr<Updates> Updates::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case updatesTooLong::ID:
      return updatesTooLong::fetch(p);
    case updateShortMessage::ID:
      return updateShortMessage::fetch(p);
    case updateShortChatMessage::ID:
      return updateShortChatMessage::fetch(p);
    case updateShort::ID:
      return updateShort::fetch(p);
    case updatesCombined::ID:
      return updatesCombined::fetch(p);
    case updates::ID:
      return updates::fetch(p);
    case updateShortSentMessage::ID:
      return updateShortSentMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t updatesTooLong::ID;

object_ptr<Updates> updatesTooLong::fetch(TlBufferParser &p) {
  return make_tl_object<updatesTooLong>();
}

void updatesTooLong::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatesTooLong");
    s.store_class_end();
  }
}

updateShortMessage::updateShortMessage()
  : flags_()
  , out_()
  , mentioned_()
  , media_unread_()
  , silent_()
  , id_()
  , user_id_()
  , message_()
  , pts_()
  , pts_count_()
  , date_()
  , fwd_from_()
  , via_bot_id_()
  , reply_to_()
  , entities_()
  , ttl_period_()
{}

const std::int32_t updateShortMessage::ID;

object_ptr<Updates> updateShortMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateShortMessage> res = make_tl_object<updateShortMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->out_ = (var0 & 2) != 0;
  res->mentioned_ = (var0 & 16) != 0;
  res->media_unread_ = (var0 & 32) != 0;
  res->silent_ = (var0 & 8192) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->fwd_from_ = TlFetchBoxed<TlFetchObject<messageFwdHeader>, 1313731771>::parse(p); }
  if (var0 & 2048) { res->via_bot_id_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->reply_to_ = TlFetchObject<MessageReplyHeader>::parse(p); }
  if (var0 & 128) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 33554432) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateShortMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateShortMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (out_ << 1) | (mentioned_ << 4) | (media_unread_ << 5) | (silent_ << 13)));
    if (var0 & 2) { s.store_field("out", true); }
    if (var0 & 16) { s.store_field("mentioned", true); }
    if (var0 & 32) { s.store_field("media_unread", true); }
    if (var0 & 8192) { s.store_field("silent", true); }
    s.store_field("id", id_);
    s.store_field("user_id", user_id_);
    s.store_field("message", message_);
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_field("date", date_);
    if (var0 & 4) { s.store_object_field("fwd_from", static_cast<const BaseObject *>(fwd_from_.get())); }
    if (var0 & 2048) { s.store_field("via_bot_id", via_bot_id_); }
    if (var0 & 8) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    if (var0 & 128) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 33554432) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

updateShortChatMessage::updateShortChatMessage()
  : flags_()
  , out_()
  , mentioned_()
  , media_unread_()
  , silent_()
  , id_()
  , from_id_()
  , chat_id_()
  , message_()
  , pts_()
  , pts_count_()
  , date_()
  , fwd_from_()
  , via_bot_id_()
  , reply_to_()
  , entities_()
  , ttl_period_()
{}

const std::int32_t updateShortChatMessage::ID;

object_ptr<Updates> updateShortChatMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateShortChatMessage> res = make_tl_object<updateShortChatMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->out_ = (var0 & 2) != 0;
  res->mentioned_ = (var0 & 16) != 0;
  res->media_unread_ = (var0 & 32) != 0;
  res->silent_ = (var0 & 8192) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->from_id_ = TlFetchLong::parse(p);
  res->chat_id_ = TlFetchLong::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->fwd_from_ = TlFetchBoxed<TlFetchObject<messageFwdHeader>, 1313731771>::parse(p); }
  if (var0 & 2048) { res->via_bot_id_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->reply_to_ = TlFetchObject<MessageReplyHeader>::parse(p); }
  if (var0 & 128) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 33554432) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateShortChatMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateShortChatMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (out_ << 1) | (mentioned_ << 4) | (media_unread_ << 5) | (silent_ << 13)));
    if (var0 & 2) { s.store_field("out", true); }
    if (var0 & 16) { s.store_field("mentioned", true); }
    if (var0 & 32) { s.store_field("media_unread", true); }
    if (var0 & 8192) { s.store_field("silent", true); }
    s.store_field("id", id_);
    s.store_field("from_id", from_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("message", message_);
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_field("date", date_);
    if (var0 & 4) { s.store_object_field("fwd_from", static_cast<const BaseObject *>(fwd_from_.get())); }
    if (var0 & 2048) { s.store_field("via_bot_id", via_bot_id_); }
    if (var0 & 8) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    if (var0 & 128) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 33554432) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

const std::int32_t updateShort::ID;

object_ptr<Updates> updateShort::fetch(TlBufferParser &p) {
  return make_tl_object<updateShort>(p);
}

updateShort::updateShort(TlBufferParser &p)
  : update_(TlFetchObject<Update>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void updateShort::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateShort");
    s.store_object_field("update", static_cast<const BaseObject *>(update_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t updatesCombined::ID;

object_ptr<Updates> updatesCombined::fetch(TlBufferParser &p) {
  return make_tl_object<updatesCombined>(p);
}

updatesCombined::updatesCombined(TlBufferParser &p)
  : updates_(TlFetchBoxed<TlFetchVector<TlFetchObject<Update>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , date_(TlFetchInt::parse(p))
  , seq_start_(TlFetchInt::parse(p))
  , seq_(TlFetchInt::parse(p))
{}

void updatesCombined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatesCombined");
    { s.store_vector_begin("updates", updates_.size()); for (const auto &_value : updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("date", date_);
    s.store_field("seq_start", seq_start_);
    s.store_field("seq", seq_);
    s.store_class_end();
  }
}

updates::updates()
  : updates_()
  , users_()
  , chats_()
  , date_()
  , seq_()
{}

const std::int32_t updates::ID;

object_ptr<Updates> updates::fetch(TlBufferParser &p) {
  return make_tl_object<updates>(p);
}

updates::updates(TlBufferParser &p)
  : updates_(TlFetchBoxed<TlFetchVector<TlFetchObject<Update>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , date_(TlFetchInt::parse(p))
  , seq_(TlFetchInt::parse(p))
{}

void updates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates");
    { s.store_vector_begin("updates", updates_.size()); for (const auto &_value : updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("date", date_);
    s.store_field("seq", seq_);
    s.store_class_end();
  }
}

updateShortSentMessage::updateShortSentMessage()
  : flags_()
  , out_()
  , id_()
  , pts_()
  , pts_count_()
  , date_()
  , media_()
  , entities_()
  , ttl_period_()
{}

const std::int32_t updateShortSentMessage::ID;

object_ptr<Updates> updateShortSentMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateShortSentMessage> res = make_tl_object<updateShortSentMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->out_ = (var0 & 2) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 512) { res->media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (var0 & 128) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 33554432) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateShortSentMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateShortSentMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (out_ << 1)));
    if (var0 & 2) { s.store_field("out", true); }
    s.store_field("id", id_);
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_field("date", date_);
    if (var0 & 512) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 128) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 33554432) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

userFull::userFull()
  : flags_()
  , blocked_()
  , phone_calls_available_()
  , phone_calls_private_()
  , can_pin_message_()
  , has_scheduled_()
  , video_calls_available_()
  , voice_messages_forbidden_()
  , translations_disabled_()
  , stories_pinned_available_()
  , blocked_my_stories_from_()
  , wallpaper_overridden_()
  , contact_require_premium_()
  , read_dates_private_()
  , flags2_()
  , sponsored_enabled_()
  , can_view_revenue_()
  , bot_can_manage_emoji_status_()
  , display_gifts_button_()
  , noforwards_my_enabled_()
  , noforwards_peer_enabled_()
  , unofficial_security_risk_()
  , id_()
  , about_()
  , settings_()
  , personal_photo_()
  , profile_photo_()
  , fallback_photo_()
  , notify_settings_()
  , bot_info_()
  , pinned_msg_id_()
  , common_chats_count_()
  , folder_id_()
  , ttl_period_()
  , theme_()
  , private_forward_name_()
  , bot_group_admin_rights_()
  , bot_broadcast_admin_rights_()
  , wallpaper_()
  , stories_()
  , business_work_hours_()
  , business_location_()
  , business_greeting_message_()
  , business_away_message_()
  , business_intro_()
  , birthday_()
  , personal_channel_id_()
  , personal_channel_message_()
  , stargifts_count_()
  , starref_program_()
  , bot_verification_()
  , send_paid_messages_stars_()
  , disallowed_gifts_()
  , stars_rating_()
  , stars_my_pending_rating_()
  , stars_my_pending_rating_date_()
  , main_tab_()
  , saved_music_()
  , note_()
  , bot_manager_id_()
{}

const std::int32_t userFull::ID;

object_ptr<userFull> userFull::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<userFull> res = make_tl_object<userFull>();
  int32 var0;
  int32 var1;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->blocked_ = (var0 & 1) != 0;
  res->phone_calls_available_ = (var0 & 16) != 0;
  res->phone_calls_private_ = (var0 & 32) != 0;
  res->can_pin_message_ = (var0 & 128) != 0;
  res->has_scheduled_ = (var0 & 4096) != 0;
  res->video_calls_available_ = (var0 & 8192) != 0;
  res->voice_messages_forbidden_ = (var0 & 1048576) != 0;
  res->translations_disabled_ = (var0 & 8388608) != 0;
  res->stories_pinned_available_ = (var0 & 67108864) != 0;
  res->blocked_my_stories_from_ = (var0 & 134217728) != 0;
  res->wallpaper_overridden_ = (var0 & 268435456) != 0;
  res->contact_require_premium_ = (var0 & 536870912) != 0;
  res->read_dates_private_ = (var0 & 1073741824) != 0;
  if ((var1 = res->flags2_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->sponsored_enabled_ = (var1 & 128) != 0;
  res->can_view_revenue_ = (var1 & 512) != 0;
  res->bot_can_manage_emoji_status_ = (var1 & 1024) != 0;
  res->display_gifts_button_ = (var1 & 65536) != 0;
  res->noforwards_my_enabled_ = (var1 & 8388608) != 0;
  res->noforwards_peer_enabled_ = (var1 & 16777216) != 0;
  res->unofficial_security_risk_ = (var1 & 67108864) != 0;
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->about_ = TlFetchString<string>::parse(p); }
  res->settings_ = TlFetchBoxed<TlFetchObject<peerSettings>, -193510921>::parse(p);
  if (var0 & 2097152) { res->personal_photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 4) { res->profile_photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 4194304) { res->fallback_photo_ = TlFetchObject<Photo>::parse(p); }
  res->notify_settings_ = TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
  if (var0 & 8) { res->bot_info_ = TlFetchBoxed<TlFetchObject<botInfo>, 1300890265>::parse(p); }
  if (var0 & 64) { res->pinned_msg_id_ = TlFetchInt::parse(p); }
  res->common_chats_count_ = TlFetchInt::parse(p);
  if (var0 & 2048) { res->folder_id_ = TlFetchInt::parse(p); }
  if (var0 & 16384) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (var0 & 32768) { res->theme_ = TlFetchObject<ChatTheme>::parse(p); }
  if (var0 & 65536) { res->private_forward_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 131072) { res->bot_group_admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 262144) { res->bot_broadcast_admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 16777216) { res->wallpaper_ = TlFetchObject<WallPaper>::parse(p); }
  if (var0 & 33554432) { res->stories_ = TlFetchBoxed<TlFetchObject<peerStories>, -1707742823>::parse(p); }
  if (var1 & 1) { res->business_work_hours_ = TlFetchBoxed<TlFetchObject<businessWorkHours>, -1936543592>::parse(p); }
  if (var1 & 2) { res->business_location_ = TlFetchBoxed<TlFetchObject<businessLocation>, -1403249929>::parse(p); }
  if (var1 & 4) { res->business_greeting_message_ = TlFetchBoxed<TlFetchObject<businessGreetingMessage>, -451302485>::parse(p); }
  if (var1 & 8) { res->business_away_message_ = TlFetchBoxed<TlFetchObject<businessAwayMessage>, -283809188>::parse(p); }
  if (var1 & 16) { res->business_intro_ = TlFetchBoxed<TlFetchObject<businessIntro>, 1510606445>::parse(p); }
  if (var1 & 32) { res->birthday_ = TlFetchBoxed<TlFetchObject<birthday>, 1821253126>::parse(p); }
  if (var1 & 64) { res->personal_channel_id_ = TlFetchLong::parse(p); }
  if (var1 & 64) { res->personal_channel_message_ = TlFetchInt::parse(p); }
  if (var1 & 256) { res->stargifts_count_ = TlFetchInt::parse(p); }
  if (var1 & 2048) { res->starref_program_ = TlFetchBoxed<TlFetchObject<starRefProgram>, -586389774>::parse(p); }
  if (var1 & 4096) { res->bot_verification_ = TlFetchBoxed<TlFetchObject<botVerification>, -113453988>::parse(p); }
  if (var1 & 16384) { res->send_paid_messages_stars_ = TlFetchLong::parse(p); }
  if (var1 & 32768) { res->disallowed_gifts_ = TlFetchBoxed<TlFetchObject<disallowedGiftsSettings>, 1911715524>::parse(p); }
  if (var1 & 131072) { res->stars_rating_ = TlFetchBoxed<TlFetchObject<starsRating>, 453922567>::parse(p); }
  if (var1 & 262144) { res->stars_my_pending_rating_ = TlFetchBoxed<TlFetchObject<starsRating>, 453922567>::parse(p); }
  if (var1 & 262144) { res->stars_my_pending_rating_date_ = TlFetchInt::parse(p); }
  if (var1 & 1048576) { res->main_tab_ = TlFetchObject<ProfileTab>::parse(p); }
  if (var1 & 2097152) { res->saved_music_ = TlFetchObject<Document>::parse(p); }
  if (var1 & 4194304) { res->note_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (var1 & 33554432) { res->bot_manager_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void userFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userFull");
  int32 var0;
  int32 var1;
    s.store_field("flags", (var0 = flags_ | (blocked_ << 0) | (phone_calls_available_ << 4) | (phone_calls_private_ << 5) | (can_pin_message_ << 7) | (has_scheduled_ << 12) | (video_calls_available_ << 13) | (voice_messages_forbidden_ << 20) | (translations_disabled_ << 23) | (stories_pinned_available_ << 26) | (blocked_my_stories_from_ << 27) | (wallpaper_overridden_ << 28) | (contact_require_premium_ << 29) | (read_dates_private_ << 30)));
    if (var0 & 1) { s.store_field("blocked", true); }
    if (var0 & 16) { s.store_field("phone_calls_available", true); }
    if (var0 & 32) { s.store_field("phone_calls_private", true); }
    if (var0 & 128) { s.store_field("can_pin_message", true); }
    if (var0 & 4096) { s.store_field("has_scheduled", true); }
    if (var0 & 8192) { s.store_field("video_calls_available", true); }
    if (var0 & 1048576) { s.store_field("voice_messages_forbidden", true); }
    if (var0 & 8388608) { s.store_field("translations_disabled", true); }
    if (var0 & 67108864) { s.store_field("stories_pinned_available", true); }
    if (var0 & 134217728) { s.store_field("blocked_my_stories_from", true); }
    if (var0 & 268435456) { s.store_field("wallpaper_overridden", true); }
    if (var0 & 536870912) { s.store_field("contact_require_premium", true); }
    if (var0 & 1073741824) { s.store_field("read_dates_private", true); }
    s.store_field("flags2", (var1 = flags2_ | (sponsored_enabled_ << 7) | (can_view_revenue_ << 9) | (bot_can_manage_emoji_status_ << 10) | (display_gifts_button_ << 16) | (noforwards_my_enabled_ << 23) | (noforwards_peer_enabled_ << 24) | (unofficial_security_risk_ << 26)));
    if (var1 & 128) { s.store_field("sponsored_enabled", true); }
    if (var1 & 512) { s.store_field("can_view_revenue", true); }
    if (var1 & 1024) { s.store_field("bot_can_manage_emoji_status", true); }
    if (var1 & 65536) { s.store_field("display_gifts_button", true); }
    if (var1 & 8388608) { s.store_field("noforwards_my_enabled", true); }
    if (var1 & 16777216) { s.store_field("noforwards_peer_enabled", true); }
    if (var1 & 67108864) { s.store_field("unofficial_security_risk", true); }
    s.store_field("id", id_);
    if (var0 & 2) { s.store_field("about", about_); }
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    if (var0 & 2097152) { s.store_object_field("personal_photo", static_cast<const BaseObject *>(personal_photo_.get())); }
    if (var0 & 4) { s.store_object_field("profile_photo", static_cast<const BaseObject *>(profile_photo_.get())); }
    if (var0 & 4194304) { s.store_object_field("fallback_photo", static_cast<const BaseObject *>(fallback_photo_.get())); }
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    if (var0 & 8) { s.store_object_field("bot_info", static_cast<const BaseObject *>(bot_info_.get())); }
    if (var0 & 64) { s.store_field("pinned_msg_id", pinned_msg_id_); }
    s.store_field("common_chats_count", common_chats_count_);
    if (var0 & 2048) { s.store_field("folder_id", folder_id_); }
    if (var0 & 16384) { s.store_field("ttl_period", ttl_period_); }
    if (var0 & 32768) { s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get())); }
    if (var0 & 65536) { s.store_field("private_forward_name", private_forward_name_); }
    if (var0 & 131072) { s.store_object_field("bot_group_admin_rights", static_cast<const BaseObject *>(bot_group_admin_rights_.get())); }
    if (var0 & 262144) { s.store_object_field("bot_broadcast_admin_rights", static_cast<const BaseObject *>(bot_broadcast_admin_rights_.get())); }
    if (var0 & 16777216) { s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get())); }
    if (var0 & 33554432) { s.store_object_field("stories", static_cast<const BaseObject *>(stories_.get())); }
    if (var1 & 1) { s.store_object_field("business_work_hours", static_cast<const BaseObject *>(business_work_hours_.get())); }
    if (var1 & 2) { s.store_object_field("business_location", static_cast<const BaseObject *>(business_location_.get())); }
    if (var1 & 4) { s.store_object_field("business_greeting_message", static_cast<const BaseObject *>(business_greeting_message_.get())); }
    if (var1 & 8) { s.store_object_field("business_away_message", static_cast<const BaseObject *>(business_away_message_.get())); }
    if (var1 & 16) { s.store_object_field("business_intro", static_cast<const BaseObject *>(business_intro_.get())); }
    if (var1 & 32) { s.store_object_field("birthday", static_cast<const BaseObject *>(birthday_.get())); }
    if (var1 & 64) { s.store_field("personal_channel_id", personal_channel_id_); }
    if (var1 & 64) { s.store_field("personal_channel_message", personal_channel_message_); }
    if (var1 & 256) { s.store_field("stargifts_count", stargifts_count_); }
    if (var1 & 2048) { s.store_object_field("starref_program", static_cast<const BaseObject *>(starref_program_.get())); }
    if (var1 & 4096) { s.store_object_field("bot_verification", static_cast<const BaseObject *>(bot_verification_.get())); }
    if (var1 & 16384) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    if (var1 & 32768) { s.store_object_field("disallowed_gifts", static_cast<const BaseObject *>(disallowed_gifts_.get())); }
    if (var1 & 131072) { s.store_object_field("stars_rating", static_cast<const BaseObject *>(stars_rating_.get())); }
    if (var1 & 262144) { s.store_object_field("stars_my_pending_rating", static_cast<const BaseObject *>(stars_my_pending_rating_.get())); }
    if (var1 & 262144) { s.store_field("stars_my_pending_rating_date", stars_my_pending_rating_date_); }
    if (var1 & 1048576) { s.store_object_field("main_tab", static_cast<const BaseObject *>(main_tab_.get())); }
    if (var1 & 2097152) { s.store_object_field("saved_music", static_cast<const BaseObject *>(saved_music_.get())); }
    if (var1 & 4194304) { s.store_object_field("note", static_cast<const BaseObject *>(note_.get())); }
    if (var1 & 33554432) { s.store_field("bot_manager_id", bot_manager_id_); }
    s.store_class_end();
  }
}

username::username()
  : flags_()
  , editable_()
  , active_()
  , username_()
{}

username::username(int32 flags_, bool editable_, bool active_, string const &username_)
  : flags_(flags_)
  , editable_(editable_)
  , active_(active_)
  , username_(username_)
{}

const std::int32_t username::ID;

object_ptr<username> username::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<username> res = make_tl_object<username>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->editable_ = (var0 & 1) != 0;
  res->active_ = (var0 & 2) != 0;
  res->username_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void username::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (editable_ << 0) | (active_ << 1)), s);
  TlStoreString::store(username_, s);
}

void username::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (editable_ << 0) | (active_ << 1)), s);
  TlStoreString::store(username_, s);
}

void username::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "username");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (editable_ << 0) | (active_ << 1)));
    if (var0 & 1) { s.store_field("editable", true); }
    if (var0 & 2) { s.store_field("active", true); }
    s.store_field("username", username_);
    s.store_class_end();
  }
}

object_ptr<WebPage> WebPage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case webPageEmpty::ID:
      return webPageEmpty::fetch(p);
    case webPagePending::ID:
      return webPagePending::fetch(p);
    case webPage::ID:
      return webPage::fetch(p);
    case webPageNotModified::ID:
      return webPageNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

webPageEmpty::webPageEmpty()
  : flags_()
  , id_()
  , url_()
{}

webPageEmpty::webPageEmpty(int32 flags_, int64 id_, string const &url_)
  : flags_(flags_)
  , id_(id_)
  , url_(url_)
{}

const std::int32_t webPageEmpty::ID;

object_ptr<WebPage> webPageEmpty::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPageEmpty> res = make_tl_object<webPageEmpty>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->url_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPageEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(url_, s); }
}

void webPageEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(url_, s); }
}

void webPageEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageEmpty");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_field("url", url_); }
    s.store_class_end();
  }
}

webPagePending::webPagePending()
  : flags_()
  , id_()
  , url_()
  , date_()
{}

webPagePending::webPagePending(int32 flags_, int64 id_, string const &url_, int32 date_)
  : flags_(flags_)
  , id_(id_)
  , url_(url_)
  , date_(date_)
{}

const std::int32_t webPagePending::ID;

object_ptr<WebPage> webPagePending::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPagePending> res = make_tl_object<webPagePending>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->url_ = TlFetchString<string>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPagePending::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(url_, s); }
  TlStoreBinary::store(date_, s);
}

void webPagePending::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(url_, s); }
  TlStoreBinary::store(date_, s);
}

void webPagePending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPagePending");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_field("url", url_); }
    s.store_field("date", date_);
    s.store_class_end();
  }
}

webPage::webPage()
  : flags_()
  , has_large_media_()
  , video_cover_photo_()
  , id_()
  , url_()
  , display_url_()
  , hash_()
  , type_()
  , site_name_()
  , title_()
  , description_()
  , photo_()
  , embed_url_()
  , embed_type_()
  , embed_width_()
  , embed_height_()
  , duration_()
  , author_()
  , document_()
  , cached_page_()
  , attributes_()
{}

webPage::webPage(int32 flags_, bool has_large_media_, bool video_cover_photo_, int64 id_, string const &url_, string const &display_url_, int32 hash_, string const &type_, string const &site_name_, string const &title_, string const &description_, object_ptr<Photo> &&photo_, string const &embed_url_, string const &embed_type_, int32 embed_width_, int32 embed_height_, int32 duration_, string const &author_, object_ptr<Document> &&document_, object_ptr<page> &&cached_page_, array<object_ptr<WebPageAttribute>> &&attributes_)
  : flags_(flags_)
  , has_large_media_(has_large_media_)
  , video_cover_photo_(video_cover_photo_)
  , id_(id_)
  , url_(url_)
  , display_url_(display_url_)
  , hash_(hash_)
  , type_(type_)
  , site_name_(site_name_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , embed_url_(embed_url_)
  , embed_type_(embed_type_)
  , embed_width_(embed_width_)
  , embed_height_(embed_height_)
  , duration_(duration_)
  , author_(author_)
  , document_(std::move(document_))
  , cached_page_(std::move(cached_page_))
  , attributes_(std::move(attributes_))
{}

const std::int32_t webPage::ID;

object_ptr<WebPage> webPage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPage> res = make_tl_object<webPage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_large_media_ = (var0 & 8192) != 0;
  res->video_cover_photo_ = (var0 & 16384) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  res->display_url_ = TlFetchString<string>::parse(p);
  res->hash_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->type_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->site_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->description_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 32) { res->embed_url_ = TlFetchString<string>::parse(p); }
  if (var0 & 32) { res->embed_type_ = TlFetchString<string>::parse(p); }
  if (var0 & 64) { res->embed_width_ = TlFetchInt::parse(p); }
  if (var0 & 64) { res->embed_height_ = TlFetchInt::parse(p); }
  if (var0 & 128) { res->duration_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->author_ = TlFetchString<string>::parse(p); }
  if (var0 & 512) { res->document_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 1024) { res->cached_page_ = TlFetchBoxed<TlFetchObject<page>, -1738178803>::parse(p); }
  if (var0 & 4096) { res->attributes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<WebPageAttribute>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_large_media_ << 13) | (video_cover_photo_ << 14)), s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(url_, s);
  TlStoreString::store(display_url_, s);
  TlStoreBinary::store(hash_, s);
  if (var0 & 1) { TlStoreString::store(type_, s); }
  if (var0 & 2) { TlStoreString::store(site_name_, s); }
  if (var0 & 4) { TlStoreString::store(title_, s); }
  if (var0 & 8) { TlStoreString::store(description_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s); }
  if (var0 & 32) { TlStoreString::store(embed_url_, s); }
  if (var0 & 32) { TlStoreString::store(embed_type_, s); }
  if (var0 & 64) { TlStoreBinary::store(embed_width_, s); }
  if (var0 & 64) { TlStoreBinary::store(embed_height_, s); }
  if (var0 & 128) { TlStoreBinary::store(duration_, s); }
  if (var0 & 256) { TlStoreString::store(author_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, -1738178803>::store(cached_page_, s); }
  if (var0 & 4096) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s); }
}

void webPage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_large_media_ << 13) | (video_cover_photo_ << 14)), s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(url_, s);
  TlStoreString::store(display_url_, s);
  TlStoreBinary::store(hash_, s);
  if (var0 & 1) { TlStoreString::store(type_, s); }
  if (var0 & 2) { TlStoreString::store(site_name_, s); }
  if (var0 & 4) { TlStoreString::store(title_, s); }
  if (var0 & 8) { TlStoreString::store(description_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s); }
  if (var0 & 32) { TlStoreString::store(embed_url_, s); }
  if (var0 & 32) { TlStoreString::store(embed_type_, s); }
  if (var0 & 64) { TlStoreBinary::store(embed_width_, s); }
  if (var0 & 64) { TlStoreBinary::store(embed_height_, s); }
  if (var0 & 128) { TlStoreBinary::store(duration_, s); }
  if (var0 & 256) { TlStoreString::store(author_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, -1738178803>::store(cached_page_, s); }
  if (var0 & 4096) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s); }
}

void webPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_large_media_ << 13) | (video_cover_photo_ << 14)));
    if (var0 & 8192) { s.store_field("has_large_media", true); }
    if (var0 & 16384) { s.store_field("video_cover_photo", true); }
    s.store_field("id", id_);
    s.store_field("url", url_);
    s.store_field("display_url", display_url_);
    s.store_field("hash", hash_);
    if (var0 & 1) { s.store_field("type", type_); }
    if (var0 & 2) { s.store_field("site_name", site_name_); }
    if (var0 & 4) { s.store_field("title", title_); }
    if (var0 & 8) { s.store_field("description", description_); }
    if (var0 & 16) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 32) { s.store_field("embed_url", embed_url_); }
    if (var0 & 32) { s.store_field("embed_type", embed_type_); }
    if (var0 & 64) { s.store_field("embed_width", embed_width_); }
    if (var0 & 64) { s.store_field("embed_height", embed_height_); }
    if (var0 & 128) { s.store_field("duration", duration_); }
    if (var0 & 256) { s.store_field("author", author_); }
    if (var0 & 512) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 1024) { s.store_object_field("cached_page", static_cast<const BaseObject *>(cached_page_.get())); }
    if (var0 & 4096) { { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

webPageNotModified::webPageNotModified()
  : flags_()
  , cached_page_views_()
{}

webPageNotModified::webPageNotModified(int32 flags_, int32 cached_page_views_)
  : flags_(flags_)
  , cached_page_views_(cached_page_views_)
{}

const std::int32_t webPageNotModified::ID;

object_ptr<WebPage> webPageNotModified::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPageNotModified> res = make_tl_object<webPageNotModified>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->cached_page_views_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPageNotModified::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(cached_page_views_, s); }
}

void webPageNotModified::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(cached_page_views_, s); }
}

void webPageNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageNotModified");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("cached_page_views", cached_page_views_); }
    s.store_class_end();
  }
}

object_ptr<account_EmojiStatuses> account_EmojiStatuses::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_emojiStatusesNotModified::ID:
      return account_emojiStatusesNotModified::fetch(p);
    case account_emojiStatuses::ID:
      return account_emojiStatuses::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_emojiStatusesNotModified::ID;

object_ptr<account_EmojiStatuses> account_emojiStatusesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_emojiStatusesNotModified>();
}

void account_emojiStatusesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.emojiStatusesNotModified");
    s.store_class_end();
  }
}

const std::int32_t account_emojiStatuses::ID;

object_ptr<account_EmojiStatuses> account_emojiStatuses::fetch(TlBufferParser &p) {
  return make_tl_object<account_emojiStatuses>(p);
}

account_emojiStatuses::account_emojiStatuses(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , statuses_(TlFetchBoxed<TlFetchVector<TlFetchObject<EmojiStatus>>, 481674261>::parse(p))
{}

void account_emojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.emojiStatuses");
    s.store_field("hash", hash_);
    { s.store_vector_begin("statuses", statuses_.size()); for (const auto &_value : statuses_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

auth_loggedOut::auth_loggedOut()
  : flags_()
  , future_auth_token_()
{}

const std::int32_t auth_loggedOut::ID;

object_ptr<auth_loggedOut> auth_loggedOut::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_loggedOut> res = make_tl_object<auth_loggedOut>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->future_auth_token_ = TlFetchBytes<bytes>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void auth_loggedOut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.loggedOut");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_bytes_field("future_auth_token", future_auth_token_); }
    s.store_class_end();
  }
}

object_ptr<auth_SentCodeType> auth_SentCodeType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case auth_sentCodeTypeApp::ID:
      return auth_sentCodeTypeApp::fetch(p);
    case auth_sentCodeTypeSms::ID:
      return auth_sentCodeTypeSms::fetch(p);
    case auth_sentCodeTypeCall::ID:
      return auth_sentCodeTypeCall::fetch(p);
    case auth_sentCodeTypeFlashCall::ID:
      return auth_sentCodeTypeFlashCall::fetch(p);
    case auth_sentCodeTypeMissedCall::ID:
      return auth_sentCodeTypeMissedCall::fetch(p);
    case auth_sentCodeTypeEmailCode::ID:
      return auth_sentCodeTypeEmailCode::fetch(p);
    case auth_sentCodeTypeSetUpEmailRequired::ID:
      return auth_sentCodeTypeSetUpEmailRequired::fetch(p);
    case auth_sentCodeTypeFragmentSms::ID:
      return auth_sentCodeTypeFragmentSms::fetch(p);
    case auth_sentCodeTypeFirebaseSms::ID:
      return auth_sentCodeTypeFirebaseSms::fetch(p);
    case auth_sentCodeTypeSmsWord::ID:
      return auth_sentCodeTypeSmsWord::fetch(p);
    case auth_sentCodeTypeSmsPhrase::ID:
      return auth_sentCodeTypeSmsPhrase::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t auth_sentCodeTypeApp::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeApp::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeTypeApp>(p);
}

auth_sentCodeTypeApp::auth_sentCodeTypeApp(TlBufferParser &p)
  : length_(TlFetchInt::parse(p))
{}

void auth_sentCodeTypeApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeApp");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodeTypeSms::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeSms::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeTypeSms>(p);
}

auth_sentCodeTypeSms::auth_sentCodeTypeSms(TlBufferParser &p)
  : length_(TlFetchInt::parse(p))
{}

void auth_sentCodeTypeSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeSms");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodeTypeCall::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeCall::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeTypeCall>(p);
}

auth_sentCodeTypeCall::auth_sentCodeTypeCall(TlBufferParser &p)
  : length_(TlFetchInt::parse(p))
{}

void auth_sentCodeTypeCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeCall");
    s.store_field("length", length_);
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodeTypeFlashCall::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeFlashCall::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeTypeFlashCall>(p);
}

auth_sentCodeTypeFlashCall::auth_sentCodeTypeFlashCall(TlBufferParser &p)
  : pattern_(TlFetchString<string>::parse(p))
{}

void auth_sentCodeTypeFlashCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeFlashCall");
    s.store_field("pattern", pattern_);
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodeTypeMissedCall::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeMissedCall::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeTypeMissedCall>(p);
}

auth_sentCodeTypeMissedCall::auth_sentCodeTypeMissedCall(TlBufferParser &p)
  : prefix_(TlFetchString<string>::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void auth_sentCodeTypeMissedCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeMissedCall");
    s.store_field("prefix", prefix_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

auth_sentCodeTypeEmailCode::auth_sentCodeTypeEmailCode()
  : flags_()
  , apple_signin_allowed_()
  , google_signin_allowed_()
  , email_pattern_()
  , length_()
  , reset_available_period_()
  , reset_pending_date_()
{}

const std::int32_t auth_sentCodeTypeEmailCode::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeEmailCode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_sentCodeTypeEmailCode> res = make_tl_object<auth_sentCodeTypeEmailCode>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->apple_signin_allowed_ = (var0 & 1) != 0;
  res->google_signin_allowed_ = (var0 & 2) != 0;
  res->email_pattern_ = TlFetchString<string>::parse(p);
  res->length_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->reset_available_period_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->reset_pending_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_sentCodeTypeEmailCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeEmailCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (apple_signin_allowed_ << 0) | (google_signin_allowed_ << 1)));
    if (var0 & 1) { s.store_field("apple_signin_allowed", true); }
    if (var0 & 2) { s.store_field("google_signin_allowed", true); }
    s.store_field("email_pattern", email_pattern_);
    s.store_field("length", length_);
    if (var0 & 8) { s.store_field("reset_available_period", reset_available_period_); }
    if (var0 & 16) { s.store_field("reset_pending_date", reset_pending_date_); }
    s.store_class_end();
  }
}

auth_sentCodeTypeSetUpEmailRequired::auth_sentCodeTypeSetUpEmailRequired()
  : flags_()
  , apple_signin_allowed_()
  , google_signin_allowed_()
{}

const std::int32_t auth_sentCodeTypeSetUpEmailRequired::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeSetUpEmailRequired::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_sentCodeTypeSetUpEmailRequired> res = make_tl_object<auth_sentCodeTypeSetUpEmailRequired>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->apple_signin_allowed_ = (var0 & 1) != 0;
  res->google_signin_allowed_ = (var0 & 2) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_sentCodeTypeSetUpEmailRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeSetUpEmailRequired");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (apple_signin_allowed_ << 0) | (google_signin_allowed_ << 1)));
    if (var0 & 1) { s.store_field("apple_signin_allowed", true); }
    if (var0 & 2) { s.store_field("google_signin_allowed", true); }
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodeTypeFragmentSms::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeFragmentSms::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeTypeFragmentSms>(p);
}

auth_sentCodeTypeFragmentSms::auth_sentCodeTypeFragmentSms(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void auth_sentCodeTypeFragmentSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeFragmentSms");
    s.store_field("url", url_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

auth_sentCodeTypeFirebaseSms::auth_sentCodeTypeFirebaseSms()
  : flags_()
  , nonce_()
  , play_integrity_project_id_()
  , play_integrity_nonce_()
  , receipt_()
  , push_timeout_()
  , length_()
{}

const std::int32_t auth_sentCodeTypeFirebaseSms::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeFirebaseSms::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_sentCodeTypeFirebaseSms> res = make_tl_object<auth_sentCodeTypeFirebaseSms>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->nonce_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 4) { res->play_integrity_project_id_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->play_integrity_nonce_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 2) { res->receipt_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->push_timeout_ = TlFetchInt::parse(p); }
  res->length_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_sentCodeTypeFirebaseSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeFirebaseSms");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_bytes_field("nonce", nonce_); }
    if (var0 & 4) { s.store_field("play_integrity_project_id", play_integrity_project_id_); }
    if (var0 & 4) { s.store_bytes_field("play_integrity_nonce", play_integrity_nonce_); }
    if (var0 & 2) { s.store_field("receipt", receipt_); }
    if (var0 & 2) { s.store_field("push_timeout", push_timeout_); }
    s.store_field("length", length_);
    s.store_class_end();
  }
}

auth_sentCodeTypeSmsWord::auth_sentCodeTypeSmsWord()
  : flags_()
  , beginning_()
{}

const std::int32_t auth_sentCodeTypeSmsWord::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeSmsWord::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_sentCodeTypeSmsWord> res = make_tl_object<auth_sentCodeTypeSmsWord>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->beginning_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_sentCodeTypeSmsWord::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeSmsWord");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("beginning", beginning_); }
    s.store_class_end();
  }
}

auth_sentCodeTypeSmsPhrase::auth_sentCodeTypeSmsPhrase()
  : flags_()
  , beginning_()
{}

const std::int32_t auth_sentCodeTypeSmsPhrase::ID;

object_ptr<auth_SentCodeType> auth_sentCodeTypeSmsPhrase::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_sentCodeTypeSmsPhrase> res = make_tl_object<auth_sentCodeTypeSmsPhrase>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->beginning_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_sentCodeTypeSmsPhrase::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeTypeSmsPhrase");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("beginning", beginning_); }
    s.store_class_end();
  }
}

const std::int32_t bots_botInfo::ID;

object_ptr<bots_botInfo> bots_botInfo::fetch(TlBufferParser &p) {
  return make_tl_object<bots_botInfo>(p);
}

bots_botInfo::bots_botInfo(TlBufferParser &p)
  : name_(TlFetchString<string>::parse(p))
  , about_(TlFetchString<string>::parse(p))
  , description_(TlFetchString<string>::parse(p))
{}

void bots_botInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.botInfo");
    s.store_field("name", name_);
    s.store_field("about", about_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

const std::int32_t contacts_resolvedPeer::ID;

object_ptr<contacts_resolvedPeer> contacts_resolvedPeer::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_resolvedPeer>(p);
}

contacts_resolvedPeer::contacts_resolvedPeer(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_resolvedPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.resolvedPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t fragment_collectibleInfo::ID;

object_ptr<fragment_collectibleInfo> fragment_collectibleInfo::fetch(TlBufferParser &p) {
  return make_tl_object<fragment_collectibleInfo>(p);
}

fragment_collectibleInfo::fragment_collectibleInfo(TlBufferParser &p)
  : purchase_date_(TlFetchInt::parse(p))
  , currency_(TlFetchString<string>::parse(p))
  , amount_(TlFetchLong::parse(p))
  , crypto_currency_(TlFetchString<string>::parse(p))
  , crypto_amount_(TlFetchLong::parse(p))
  , url_(TlFetchString<string>::parse(p))
{}

void fragment_collectibleInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fragment.collectibleInfo");
    s.store_field("purchase_date", purchase_date_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("crypto_currency", crypto_currency_);
    s.store_field("crypto_amount", crypto_amount_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

object_ptr<help_DeepLinkInfo> help_DeepLinkInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_deepLinkInfoEmpty::ID:
      return help_deepLinkInfoEmpty::fetch(p);
    case help_deepLinkInfo::ID:
      return help_deepLinkInfo::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_deepLinkInfoEmpty::ID;

object_ptr<help_DeepLinkInfo> help_deepLinkInfoEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<help_deepLinkInfoEmpty>();
}

void help_deepLinkInfoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.deepLinkInfoEmpty");
    s.store_class_end();
  }
}

help_deepLinkInfo::help_deepLinkInfo()
  : flags_()
  , update_app_()
  , message_()
  , entities_()
{}

const std::int32_t help_deepLinkInfo::ID;

object_ptr<help_DeepLinkInfo> help_deepLinkInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_deepLinkInfo> res = make_tl_object<help_deepLinkInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->update_app_ = (var0 & 1) != 0;
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void help_deepLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.deepLinkInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (update_app_ << 0)));
    if (var0 & 1) { s.store_field("update_app", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

object_ptr<help_PeerColorSet> help_PeerColorSet::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_peerColorSet::ID:
      return help_peerColorSet::fetch(p);
    case help_peerColorProfileSet::ID:
      return help_peerColorProfileSet::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_peerColorSet::ID;

object_ptr<help_PeerColorSet> help_peerColorSet::fetch(TlBufferParser &p) {
  return make_tl_object<help_peerColorSet>(p);
}

help_peerColorSet::help_peerColorSet(TlBufferParser &p)
  : colors_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void help_peerColorSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.peerColorSet");
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t help_peerColorProfileSet::ID;

object_ptr<help_PeerColorSet> help_peerColorProfileSet::fetch(TlBufferParser &p) {
  return make_tl_object<help_peerColorProfileSet>(p);
}

help_peerColorProfileSet::help_peerColorProfileSet(TlBufferParser &p)
  : palette_colors_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , bg_colors_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , story_colors_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void help_peerColorProfileSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.peerColorProfileSet");
    { s.store_vector_begin("palette_colors", palette_colors_.size()); for (const auto &_value : palette_colors_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("bg_colors", bg_colors_.size()); for (const auto &_value : bg_colors_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("story_colors", story_colors_.size()); for (const auto &_value : story_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t help_recentMeUrls::ID;

object_ptr<help_recentMeUrls> help_recentMeUrls::fetch(TlBufferParser &p) {
  return make_tl_object<help_recentMeUrls>(p);
}

help_recentMeUrls::help_recentMeUrls(TlBufferParser &p)
  : urls_(TlFetchBoxed<TlFetchVector<TlFetchObject<RecentMeUrl>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void help_recentMeUrls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.recentMeUrls");
    { s.store_vector_begin("urls", urls_.size()); for (const auto &_value : urls_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t help_support::ID;

object_ptr<help_support> help_support::fetch(TlBufferParser &p) {
  return make_tl_object<help_support>(p);
}

help_support::help_support(TlBufferParser &p)
  : phone_number_(TlFetchString<string>::parse(p))
  , user_(TlFetchObject<User>::parse(p))
{}

void help_support::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.support");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("user", static_cast<const BaseObject *>(user_.get()));
    s.store_class_end();
  }
}

object_ptr<messages_FoundStickerSets> messages_FoundStickerSets::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_foundStickerSetsNotModified::ID:
      return messages_foundStickerSetsNotModified::fetch(p);
    case messages_foundStickerSets::ID:
      return messages_foundStickerSets::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_foundStickerSetsNotModified::ID;

object_ptr<messages_FoundStickerSets> messages_foundStickerSetsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_foundStickerSetsNotModified>();
}

void messages_foundStickerSetsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.foundStickerSetsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_foundStickerSets::ID;

object_ptr<messages_FoundStickerSets> messages_foundStickerSets::fetch(TlBufferParser &p) {
  return make_tl_object<messages_foundStickerSets>(p);
}

messages_foundStickerSets::messages_foundStickerSets(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , sets_(TlFetchBoxed<TlFetchVector<TlFetchObject<StickerSetCovered>>, 481674261>::parse(p))
{}

void messages_foundStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.foundStickerSets");
    s.store_field("hash", hash_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_messageEditData::messages_messageEditData()
  : flags_()
  , caption_()
{}

const std::int32_t messages_messageEditData::ID;

object_ptr<messages_messageEditData> messages_messageEditData::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_messageEditData> res = make_tl_object<messages_messageEditData>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->caption_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_messageEditData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.messageEditData");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (caption_ << 0)));
    if (var0 & 1) { s.store_field("caption", true); }
    s.store_class_end();
  }
}

object_ptr<messages_SavedGifs> messages_SavedGifs::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_savedGifsNotModified::ID:
      return messages_savedGifsNotModified::fetch(p);
    case messages_savedGifs::ID:
      return messages_savedGifs::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_savedGifsNotModified::ID;

object_ptr<messages_SavedGifs> messages_savedGifsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedGifsNotModified>();
}

void messages_savedGifsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedGifsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_savedGifs::ID;

object_ptr<messages_SavedGifs> messages_savedGifs::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedGifs>(p);
}

messages_savedGifs::messages_savedGifs(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , gifs_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void messages_savedGifs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedGifs");
    s.store_field("hash", hash_);
    { s.store_vector_begin("gifs", gifs_.size()); for (const auto &_value : gifs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_SponsoredMessages> messages_SponsoredMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_sponsoredMessages::ID:
      return messages_sponsoredMessages::fetch(p);
    case messages_sponsoredMessagesEmpty::ID:
      return messages_sponsoredMessagesEmpty::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messages_sponsoredMessages::messages_sponsoredMessages()
  : flags_()
  , posts_between_()
  , start_delay_()
  , between_delay_()
  , messages_()
  , chats_()
  , users_()
{}

const std::int32_t messages_sponsoredMessages::ID;

object_ptr<messages_SponsoredMessages> messages_sponsoredMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_sponsoredMessages> res = make_tl_object<messages_sponsoredMessages>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->posts_between_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->start_delay_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->between_delay_ = TlFetchInt::parse(p); }
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<sponsoredMessage>, 2109703795>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_sponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sponsoredMessages");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("posts_between", posts_between_); }
    if (var0 & 2) { s.store_field("start_delay", start_delay_); }
    if (var0 & 4) { s.store_field("between_delay", between_delay_); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_sponsoredMessagesEmpty::ID;

object_ptr<messages_SponsoredMessages> messages_sponsoredMessagesEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<messages_sponsoredMessagesEmpty>();
}

void messages_sponsoredMessagesEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sponsoredMessagesEmpty");
    s.store_class_end();
  }
}

const std::int32_t messages_translateResult::ID;

object_ptr<messages_translateResult> messages_translateResult::fetch(TlBufferParser &p) {
  return make_tl_object<messages_translateResult>(p);
}

messages_translateResult::messages_translateResult(TlBufferParser &p)
  : result_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>>, 481674261>::parse(p))
{}

void messages_translateResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.translateResult");
    { s.store_vector_begin("result", result_.size()); for (const auto &_value : result_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_votesList::messages_votesList()
  : flags_()
  , count_()
  , votes_()
  , chats_()
  , users_()
  , next_offset_()
{}

const std::int32_t messages_votesList::ID;

object_ptr<messages_votesList> messages_votesList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_votesList> res = make_tl_object<messages_votesList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->votes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessagePeerVote>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_votesList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.votesList");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("count", count_);
    { s.store_vector_begin("votes", votes_.size()); for (const auto &_value : votes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

object_ptr<payments_PaymentForm> payments_PaymentForm::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_paymentForm::ID:
      return payments_paymentForm::fetch(p);
    case payments_paymentFormStars::ID:
      return payments_paymentFormStars::fetch(p);
    case payments_paymentFormStarGift::ID:
      return payments_paymentFormStarGift::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

payments_paymentForm::payments_paymentForm()
  : flags_()
  , can_save_credentials_()
  , password_missing_()
  , form_id_()
  , bot_id_()
  , title_()
  , description_()
  , photo_()
  , invoice_()
  , provider_id_()
  , url_()
  , native_provider_()
  , native_params_()
  , additional_methods_()
  , saved_info_()
  , saved_credentials_()
  , users_()
{}

const std::int32_t payments_paymentForm::ID;

object_ptr<payments_PaymentForm> payments_paymentForm::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_paymentForm> res = make_tl_object<payments_paymentForm>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_save_credentials_ = (var0 & 4) != 0;
  res->password_missing_ = (var0 & 8) != 0;
  res->form_id_ = TlFetchLong::parse(p);
  res->bot_id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 32) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  res->invoice_ = TlFetchBoxed<TlFetchObject<invoice>, 77522308>::parse(p);
  res->provider_id_ = TlFetchLong::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  if (var0 & 16) { res->native_provider_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->native_params_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p); }
  if (var0 & 64) { res->additional_methods_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<paymentFormMethod>, -1996951013>>, 481674261>::parse(p); }
  if (var0 & 1) { res->saved_info_ = TlFetchBoxed<TlFetchObject<paymentRequestedInfo>, -1868808300>::parse(p); }
  if (var0 & 2) { res->saved_credentials_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<paymentSavedCredentialsCard>, -842892769>>, 481674261>::parse(p); }
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_paymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentForm");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_save_credentials_ << 2) | (password_missing_ << 3)));
    if (var0 & 4) { s.store_field("can_save_credentials", true); }
    if (var0 & 8) { s.store_field("password_missing", true); }
    s.store_field("form_id", form_id_);
    s.store_field("bot_id", bot_id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 32) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_field("provider_id", provider_id_);
    s.store_field("url", url_);
    if (var0 & 16) { s.store_field("native_provider", native_provider_); }
    if (var0 & 16) { s.store_object_field("native_params", static_cast<const BaseObject *>(native_params_.get())); }
    if (var0 & 64) { { s.store_vector_begin("additional_methods", additional_methods_.size()); for (const auto &_value : additional_methods_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1) { s.store_object_field("saved_info", static_cast<const BaseObject *>(saved_info_.get())); }
    if (var0 & 2) { { s.store_vector_begin("saved_credentials", saved_credentials_.size()); for (const auto &_value : saved_credentials_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_paymentFormStars::payments_paymentFormStars()
  : flags_()
  , form_id_()
  , bot_id_()
  , title_()
  , description_()
  , photo_()
  , invoice_()
  , users_()
{}

const std::int32_t payments_paymentFormStars::ID;

object_ptr<payments_PaymentForm> payments_paymentFormStars::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_paymentFormStars> res = make_tl_object<payments_paymentFormStars>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->form_id_ = TlFetchLong::parse(p);
  res->bot_id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 32) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  res->invoice_ = TlFetchBoxed<TlFetchObject<invoice>, 77522308>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_paymentFormStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentFormStars");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("form_id", form_id_);
    s.store_field("bot_id", bot_id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 32) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_paymentFormStarGift::ID;

object_ptr<payments_PaymentForm> payments_paymentFormStarGift::fetch(TlBufferParser &p) {
  return make_tl_object<payments_paymentFormStarGift>(p);
}

payments_paymentFormStarGift::payments_paymentFormStarGift(TlBufferParser &p)
  : form_id_(TlFetchLong::parse(p))
  , invoice_(TlFetchBoxed<TlFetchObject<invoice>, 77522308>::parse(p))
{}

void payments_paymentFormStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentFormStarGift");
    s.store_field("form_id", form_id_);
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftAuctionState::ID;

object_ptr<payments_starGiftAuctionState> payments_starGiftAuctionState::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftAuctionState>(p);
}

payments_starGiftAuctionState::payments_starGiftAuctionState(TlBufferParser &p)
  : gift_(TlFetchObject<StarGift>::parse(p))
  , state_(TlFetchObject<StarGiftAuctionState>::parse(p))
  , user_state_(TlFetchBoxed<TlFetchObject<starGiftAuctionUserState>, 787403204>::parse(p))
  , timeout_(TlFetchInt::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
{}

void payments_starGiftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftAuctionState");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_object_field("user_state", static_cast<const BaseObject *>(user_state_.get()));
    s.store_field("timeout", timeout_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftUpgradeAttributes::ID;

object_ptr<payments_starGiftUpgradeAttributes> payments_starGiftUpgradeAttributes::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftUpgradeAttributes>(p);
}

payments_starGiftUpgradeAttributes::payments_starGiftUpgradeAttributes(TlBufferParser &p)
  : attributes_(TlFetchBoxed<TlFetchVector<TlFetchObject<StarGiftAttribute>>, 481674261>::parse(p))
{}

void payments_starGiftUpgradeAttributes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftUpgradeAttributes");
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftWithdrawalUrl::ID;

object_ptr<payments_starGiftWithdrawalUrl> payments_starGiftWithdrawalUrl::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftWithdrawalUrl>(p);
}

payments_starGiftWithdrawalUrl::payments_starGiftWithdrawalUrl(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void payments_starGiftWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftWithdrawalUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

const std::int32_t photos_photo::ID;

object_ptr<photos_photo> photos_photo::fetch(TlBufferParser &p) {
  return make_tl_object<photos_photo>(p);
}

photos_photo::photos_photo(TlBufferParser &p)
  : photo_(TlFetchObject<Photo>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void photos_photo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.photo");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t smsjobs_eligibleToJoin::ID;

object_ptr<smsjobs_eligibleToJoin> smsjobs_eligibleToJoin::fetch(TlBufferParser &p) {
  return make_tl_object<smsjobs_eligibleToJoin>(p);
}

smsjobs_eligibleToJoin::smsjobs_eligibleToJoin(TlBufferParser &p)
  : terms_url_(TlFetchString<string>::parse(p))
  , monthly_sent_sms_(TlFetchInt::parse(p))
{}

void smsjobs_eligibleToJoin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.eligibleToJoin");
    s.store_field("terms_url", terms_url_);
    s.store_field("monthly_sent_sms", monthly_sent_sms_);
    s.store_class_end();
  }
}

const std::int32_t stats_storyStats::ID;

object_ptr<stats_storyStats> stats_storyStats::fetch(TlBufferParser &p) {
  return make_tl_object<stats_storyStats>(p);
}

stats_storyStats::stats_storyStats(TlBufferParser &p)
  : views_graph_(TlFetchObject<StatsGraph>::parse(p))
  , reactions_by_emotion_graph_(TlFetchObject<StatsGraph>::parse(p))
{}

void stats_storyStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.storyStats");
    s.store_object_field("views_graph", static_cast<const BaseObject *>(views_graph_.get()));
    s.store_object_field("reactions_by_emotion_graph", static_cast<const BaseObject *>(reactions_by_emotion_graph_.get()));
    s.store_class_end();
  }
}

const std::int32_t updates_state::ID;

object_ptr<updates_state> updates_state::fetch(TlBufferParser &p) {
  return make_tl_object<updates_state>(p);
}

updates_state::updates_state(TlBufferParser &p)
  : pts_(TlFetchInt::parse(p))
  , qts_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , seq_(TlFetchInt::parse(p))
  , unread_count_(TlFetchInt::parse(p))
{}

void updates_state::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.state");
    s.store_field("pts", pts_);
    s.store_field("qts", qts_);
    s.store_field("date", date_);
    s.store_field("seq", seq_);
    s.store_field("unread_count", unread_count_);
    s.store_class_end();
  }
}

object_ptr<upload_File> upload_File::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case upload_file::ID:
      return upload_file::fetch(p);
    case upload_fileCdnRedirect::ID:
      return upload_fileCdnRedirect::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t upload_file::ID;

object_ptr<upload_File> upload_file::fetch(TlBufferParser &p) {
  return make_tl_object<upload_file>(p);
}

upload_file::upload_file(TlBufferParser &p)
  : type_(TlFetchObject<storage_FileType>::parse(p))
  , mtime_(TlFetchInt::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void upload_file::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.file");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("mtime", mtime_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

const std::int32_t upload_fileCdnRedirect::ID;

object_ptr<upload_File> upload_fileCdnRedirect::fetch(TlBufferParser &p) {
  return make_tl_object<upload_fileCdnRedirect>(p);
}

upload_fileCdnRedirect::upload_fileCdnRedirect(TlBufferParser &p)
  : dc_id_(TlFetchInt::parse(p))
  , file_token_(TlFetchBytes<bytes>::parse(p))
  , encryption_key_(TlFetchBytes<bytes>::parse(p))
  , encryption_iv_(TlFetchBytes<bytes>::parse(p))
  , file_hashes_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<fileHash>, -207944868>>, 481674261>::parse(p))
{}

void upload_fileCdnRedirect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.fileCdnRedirect");
    s.store_field("dc_id", dc_id_);
    s.store_bytes_field("file_token", file_token_);
    s.store_bytes_field("encryption_key", encryption_key_);
    s.store_bytes_field("encryption_iv", encryption_iv_);
    { s.store_vector_begin("file_hashes", file_hashes_.size()); for (const auto &_value : file_hashes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_acceptAuthorization::account_acceptAuthorization(int64 bot_id_, string const &scope_, string const &public_key_, array<object_ptr<secureValueHash>> &&value_hashes_, object_ptr<secureCredentialsEncrypted> &&credentials_)
  : bot_id_(bot_id_)
  , scope_(scope_)
  , public_key_(public_key_)
  , value_hashes_(std::move(value_hashes_))
  , credentials_(std::move(credentials_))
{}

const std::int32_t account_acceptAuthorization::ID;

void account_acceptAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-202552205);
  TlStoreBinary::store(bot_id_, s);
  TlStoreString::store(scope_, s);
  TlStoreString::store(public_key_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -316748368>>, 481674261>::store(value_hashes_, s);
  TlStoreBoxed<TlStoreObject, 871426631>::store(credentials_, s);
}

void account_acceptAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-202552205);
  TlStoreBinary::store(bot_id_, s);
  TlStoreString::store(scope_, s);
  TlStoreString::store(public_key_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -316748368>>, 481674261>::store(value_hashes_, s);
  TlStoreBoxed<TlStoreObject, 871426631>::store(credentials_, s);
}

void account_acceptAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.acceptAuthorization");
    s.store_field("bot_id", bot_id_);
    s.store_field("scope", scope_);
    s.store_field("public_key", public_key_);
    { s.store_vector_begin("value_hashes", value_hashes_.size()); for (const auto &_value : value_hashes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("credentials", static_cast<const BaseObject *>(credentials_.get()));
    s.store_class_end();
  }
}

account_acceptAuthorization::ReturnType account_acceptAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_changePhone::account_changePhone(string const &phone_number_, string const &phone_code_hash_, string const &phone_code_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , phone_code_(phone_code_)
{}

const std::int32_t account_changePhone::ID;

void account_changePhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1891839707);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(phone_code_, s);
}

void account_changePhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1891839707);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(phone_code_, s);
}

void account_changePhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.changePhone");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("phone_code", phone_code_);
    s.store_class_end();
  }
}

account_changePhone::ReturnType account_changePhone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

const std::int32_t account_clearRecentEmojiStatuses::ID;

void account_clearRecentEmojiStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(404757166);
}

void account_clearRecentEmojiStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(404757166);
}

void account_clearRecentEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.clearRecentEmojiStatuses");
    s.store_class_end();
  }
}

account_clearRecentEmojiStatuses::ReturnType account_clearRecentEmojiStatuses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_confirmPasswordEmail::account_confirmPasswordEmail(string const &code_)
  : code_(code_)
{}

const std::int32_t account_confirmPasswordEmail::ID;

void account_confirmPasswordEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1881204448);
  TlStoreString::store(code_, s);
}

void account_confirmPasswordEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1881204448);
  TlStoreString::store(code_, s);
}

void account_confirmPasswordEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.confirmPasswordEmail");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

account_confirmPasswordEmail::ReturnType account_confirmPasswordEmail::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_createTheme::account_createTheme(int32 flags_, string const &slug_, string const &title_, object_ptr<InputDocument> &&document_, array<object_ptr<inputThemeSettings>> &&settings_)
  : flags_(flags_)
  , slug_(slug_)
  , title_(title_)
  , document_(std::move(document_))
  , settings_(std::move(settings_))
{}

const std::int32_t account_createTheme::ID;

void account_createTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1697530880);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(slug_, s);
  TlStoreString::store(title_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1881255857>>, 481674261>::store(settings_, s); }
}

void account_createTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1697530880);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(slug_, s);
  TlStoreString::store(title_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1881255857>>, 481674261>::store(settings_, s); }
}

void account_createTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.createTheme");
    s.store_field("flags", (var0 = flags_));
    s.store_field("slug", slug_);
    s.store_field("title", title_);
    if (var0 & 4) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 8) { { s.store_vector_begin("settings", settings_.size()); for (const auto &_value : settings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

account_createTheme::ReturnType account_createTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<theme>, -1609668650>::parse(p);
#undef FAIL
}

account_disablePeerConnectedBot::account_disablePeerConnectedBot(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t account_disablePeerConnectedBot::ID;

void account_disablePeerConnectedBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1581481689);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void account_disablePeerConnectedBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1581481689);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void account_disablePeerConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.disablePeerConnectedBot");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

account_disablePeerConnectedBot::ReturnType account_disablePeerConnectedBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_getAuthorizations::ID;

void account_getAuthorizations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-484392616);
}

void account_getAuthorizations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-484392616);
}

void account_getAuthorizations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getAuthorizations");
    s.store_class_end();
  }
}

account_getAuthorizations::ReturnType account_getAuthorizations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_authorizations>, 1275039392>::parse(p);
#undef FAIL
}

account_getNotifySettings::account_getNotifySettings(object_ptr<InputNotifyPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t account_getNotifySettings::ID;

void account_getNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(313765169);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void account_getNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(313765169);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void account_getNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getNotifySettings");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

account_getNotifySettings::ReturnType account_getNotifySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
#undef FAIL
}

const std::int32_t account_getPassword::ID;

void account_getPassword::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1418342645);
}

void account_getPassword::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1418342645);
}

void account_getPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getPassword");
    s.store_class_end();
  }
}

account_getPassword::ReturnType account_getPassword::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_password>, -1787080453>::parse(p);
#undef FAIL
}

account_getWallPaper::account_getWallPaper(object_ptr<InputWallPaper> &&wallpaper_)
  : wallpaper_(std::move(wallpaper_))
{}

const std::int32_t account_getWallPaper::ID;

void account_getWallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-57811990);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s);
}

void account_getWallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-57811990);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s);
}

void account_getWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getWallPaper");
    s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get()));
    s.store_class_end();
  }
}

account_getWallPaper::ReturnType account_getWallPaper::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<WallPaper>::parse(p);
#undef FAIL
}

account_initTakeoutSession::account_initTakeoutSession(int32 flags_, bool contacts_, bool message_users_, bool message_chats_, bool message_megagroups_, bool message_channels_, bool files_, int64 file_max_size_)
  : flags_(flags_)
  , contacts_(contacts_)
  , message_users_(message_users_)
  , message_chats_(message_chats_)
  , message_megagroups_(message_megagroups_)
  , message_channels_(message_channels_)
  , files_(files_)
  , file_max_size_(file_max_size_)
{}

const std::int32_t account_initTakeoutSession::ID;

void account_initTakeoutSession::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1896617296);
  TlStoreBinary::store((var0 = flags_ | (contacts_ << 0) | (message_users_ << 1) | (message_chats_ << 2) | (message_megagroups_ << 3) | (message_channels_ << 4) | (files_ << 5)), s);
  if (var0 & 32) { TlStoreBinary::store(file_max_size_, s); }
}

void account_initTakeoutSession::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1896617296);
  TlStoreBinary::store((var0 = flags_ | (contacts_ << 0) | (message_users_ << 1) | (message_chats_ << 2) | (message_megagroups_ << 3) | (message_channels_ << 4) | (files_ << 5)), s);
  if (var0 & 32) { TlStoreBinary::store(file_max_size_, s); }
}

void account_initTakeoutSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.initTakeoutSession");
    s.store_field("flags", (var0 = flags_ | (contacts_ << 0) | (message_users_ << 1) | (message_chats_ << 2) | (message_megagroups_ << 3) | (message_channels_ << 4) | (files_ << 5)));
    if (var0 & 1) { s.store_field("contacts", true); }
    if (var0 & 2) { s.store_field("message_users", true); }
    if (var0 & 4) { s.store_field("message_chats", true); }
    if (var0 & 8) { s.store_field("message_megagroups", true); }
    if (var0 & 16) { s.store_field("message_channels", true); }
    if (var0 & 32) { s.store_field("files", true); }
    if (var0 & 32) { s.store_field("file_max_size", file_max_size_); }
    s.store_class_end();
  }
}

account_initTakeoutSession::ReturnType account_initTakeoutSession::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_takeout>, 1304052993>::parse(p);
#undef FAIL
}

account_sendChangePhoneCode::account_sendChangePhoneCode(string const &phone_number_, object_ptr<codeSettings> &&settings_)
  : phone_number_(phone_number_)
  , settings_(std::move(settings_))
{}

const std::int32_t account_sendChangePhoneCode::ID;

void account_sendChangePhoneCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2108208411);
  TlStoreString::store(phone_number_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void account_sendChangePhoneCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2108208411);
  TlStoreString::store(phone_number_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void account_sendChangePhoneCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.sendChangePhoneCode");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_sendChangePhoneCode::ReturnType account_sendChangePhoneCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

account_toggleUsername::account_toggleUsername(string const &username_, bool active_)
  : username_(username_)
  , active_(active_)
{}

const std::int32_t account_toggleUsername::ID;

void account_toggleUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1490465654);
  TlStoreString::store(username_, s);
  TlStoreBool::store(active_, s);
}

void account_toggleUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1490465654);
  TlStoreString::store(username_, s);
  TlStoreBool::store(active_, s);
}

void account_toggleUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.toggleUsername");
    s.store_field("username", username_);
    s.store_field("active", active_);
    s.store_class_end();
  }
}

account_toggleUsername::ReturnType account_toggleUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateColor::account_updateColor(int32 flags_, bool for_profile_, object_ptr<PeerColor> &&color_)
  : flags_(flags_)
  , for_profile_(for_profile_)
  , color_(std::move(color_))
{}

const std::int32_t account_updateColor::ID;

void account_updateColor::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1749885262);
  TlStoreBinary::store((var0 = flags_ | (for_profile_ << 1)), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(color_, s); }
}

void account_updateColor::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1749885262);
  TlStoreBinary::store((var0 = flags_ | (for_profile_ << 1)), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(color_, s); }
}

void account_updateColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateColor");
    s.store_field("flags", (var0 = flags_ | (for_profile_ << 1)));
    if (var0 & 2) { s.store_field("for_profile", true); }
    if (var0 & 4) { s.store_object_field("color", static_cast<const BaseObject *>(color_.get())); }
    s.store_class_end();
  }
}

account_updateColor::ReturnType account_updateColor::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateProfile::account_updateProfile(int32 flags_, string const &first_name_, string const &last_name_, string const &about_)
  : flags_(flags_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , about_(about_)
{}

const std::int32_t account_updateProfile::ID;

void account_updateProfile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2018596725);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(first_name_, s); }
  if (var0 & 2) { TlStoreString::store(last_name_, s); }
  if (var0 & 4) { TlStoreString::store(about_, s); }
}

void account_updateProfile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2018596725);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(first_name_, s); }
  if (var0 & 2) { TlStoreString::store(last_name_, s); }
  if (var0 & 4) { TlStoreString::store(about_, s); }
}

void account_updateProfile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateProfile");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("first_name", first_name_); }
    if (var0 & 2) { s.store_field("last_name", last_name_); }
    if (var0 & 4) { s.store_field("about", about_); }
    s.store_class_end();
  }
}

account_updateProfile::ReturnType account_updateProfile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

auth_checkPassword::auth_checkPassword(object_ptr<InputCheckPasswordSRP> &&password_)
  : password_(std::move(password_))
{}

const std::int32_t auth_checkPassword::ID;

void auth_checkPassword::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-779399914);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void auth_checkPassword::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-779399914);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void auth_checkPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.checkPassword");
    s.store_object_field("password", static_cast<const BaseObject *>(password_.get()));
    s.store_class_end();
  }
}

auth_checkPassword::ReturnType auth_checkPassword::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

auth_importBotAuthorization::auth_importBotAuthorization(int32 flags_, int32 api_id_, string const &api_hash_, string const &bot_auth_token_)
  : flags_(flags_)
  , api_id_(api_id_)
  , api_hash_(api_hash_)
  , bot_auth_token_(bot_auth_token_)
{}

const std::int32_t auth_importBotAuthorization::ID;

void auth_importBotAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1738800940);
  TlStoreBinary::store(flags_, s);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreString::store(bot_auth_token_, s);
}

void auth_importBotAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1738800940);
  TlStoreBinary::store(flags_, s);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreString::store(bot_auth_token_, s);
}

void auth_importBotAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.importBotAuthorization");
    s.store_field("flags", flags_);
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", api_hash_);
    s.store_field("bot_auth_token", bot_auth_token_);
    s.store_class_end();
  }
}

auth_importBotAuthorization::ReturnType auth_importBotAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

auth_importWebTokenAuthorization::auth_importWebTokenAuthorization(int32 api_id_, string const &api_hash_, string const &web_auth_token_)
  : api_id_(api_id_)
  , api_hash_(api_hash_)
  , web_auth_token_(web_auth_token_)
{}

const std::int32_t auth_importWebTokenAuthorization::ID;

void auth_importWebTokenAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(767062953);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreString::store(web_auth_token_, s);
}

void auth_importWebTokenAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(767062953);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreString::store(web_auth_token_, s);
}

void auth_importWebTokenAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.importWebTokenAuthorization");
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", api_hash_);
    s.store_field("web_auth_token", web_auth_token_);
    s.store_class_end();
  }
}

auth_importWebTokenAuthorization::ReturnType auth_importWebTokenAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

auth_requestFirebaseSms::auth_requestFirebaseSms(int32 flags_, string const &phone_number_, string const &phone_code_hash_, string const &safety_net_token_, string const &play_integrity_token_, string const &ios_push_secret_)
  : flags_(flags_)
  , phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , safety_net_token_(safety_net_token_)
  , play_integrity_token_(play_integrity_token_)
  , ios_push_secret_(ios_push_secret_)
{}

const std::int32_t auth_requestFirebaseSms::ID;

void auth_requestFirebaseSms::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1908857314);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  if (var0 & 1) { TlStoreString::store(safety_net_token_, s); }
  if (var0 & 4) { TlStoreString::store(play_integrity_token_, s); }
  if (var0 & 2) { TlStoreString::store(ios_push_secret_, s); }
}

void auth_requestFirebaseSms::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1908857314);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  if (var0 & 1) { TlStoreString::store(safety_net_token_, s); }
  if (var0 & 4) { TlStoreString::store(play_integrity_token_, s); }
  if (var0 & 2) { TlStoreString::store(ios_push_secret_, s); }
}

void auth_requestFirebaseSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.requestFirebaseSms");
    s.store_field("flags", (var0 = flags_));
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    if (var0 & 1) { s.store_field("safety_net_token", safety_net_token_); }
    if (var0 & 4) { s.store_field("play_integrity_token", play_integrity_token_); }
    if (var0 & 2) { s.store_field("ios_push_secret", ios_push_secret_); }
    s.store_class_end();
  }
}

auth_requestFirebaseSms::ReturnType auth_requestFirebaseSms::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_signUp::auth_signUp(int32 flags_, bool no_joined_notifications_, string const &phone_number_, string const &phone_code_hash_, string const &first_name_, string const &last_name_)
  : flags_(flags_)
  , no_joined_notifications_(no_joined_notifications_)
  , phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , first_name_(first_name_)
  , last_name_(last_name_)
{}

const std::int32_t auth_signUp::ID;

void auth_signUp::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1429752041);
  TlStoreBinary::store((var0 = flags_ | (no_joined_notifications_ << 0)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
}

void auth_signUp::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1429752041);
  TlStoreBinary::store((var0 = flags_ | (no_joined_notifications_ << 0)), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
}

void auth_signUp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.signUp");
    s.store_field("flags", (var0 = flags_ | (no_joined_notifications_ << 0)));
    if (var0 & 1) { s.store_field("no_joined_notifications", true); }
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_class_end();
  }
}

auth_signUp::ReturnType auth_signUp::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

bots_allowSendMessage::bots_allowSendMessage(object_ptr<InputUser> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t bots_allowSendMessage::ID;

void bots_allowSendMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-248323089);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_allowSendMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-248323089);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_allowSendMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.allowSendMessage");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

bots_allowSendMessage::ReturnType bots_allowSendMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

bots_answerWebhookJSONQuery::bots_answerWebhookJSONQuery(int64 query_id_, object_ptr<dataJSON> &&data_)
  : query_id_(query_id_)
  , data_(std::move(data_))
{}

const std::int32_t bots_answerWebhookJSONQuery::ID;

void bots_answerWebhookJSONQuery::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-434028723);
  TlStoreBinary::store(query_id_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(data_, s);
}

void bots_answerWebhookJSONQuery::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-434028723);
  TlStoreBinary::store(query_id_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(data_, s);
}

void bots_answerWebhookJSONQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.answerWebhookJSONQuery");
    s.store_field("query_id", query_id_);
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_class_end();
  }
}

bots_answerWebhookJSONQuery::ReturnType bots_answerWebhookJSONQuery::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_createBot::bots_createBot(int32 flags_, bool via_deeplink_, string const &name_, string const &username_, object_ptr<InputUser> &&manager_id_)
  : flags_(flags_)
  , via_deeplink_(via_deeplink_)
  , name_(name_)
  , username_(username_)
  , manager_id_(std::move(manager_id_))
{}

const std::int32_t bots_createBot::ID;

void bots_createBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-441352405);
  TlStoreBinary::store((var0 = flags_ | (via_deeplink_ << 0)), s);
  TlStoreString::store(name_, s);
  TlStoreString::store(username_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(manager_id_, s);
}

void bots_createBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-441352405);
  TlStoreBinary::store((var0 = flags_ | (via_deeplink_ << 0)), s);
  TlStoreString::store(name_, s);
  TlStoreString::store(username_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(manager_id_, s);
}

void bots_createBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.createBot");
    s.store_field("flags", (var0 = flags_ | (via_deeplink_ << 0)));
    if (var0 & 1) { s.store_field("via_deeplink", true); }
    s.store_field("name", name_);
    s.store_field("username", username_);
    s.store_object_field("manager_id", static_cast<const BaseObject *>(manager_id_.get()));
    s.store_class_end();
  }
}

bots_createBot::ReturnType bots_createBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

bots_reorderUsernames::bots_reorderUsernames(object_ptr<InputUser> &&bot_, array<string> &&order_)
  : bot_(std::move(bot_))
  , order_(std::move(order_))
{}

const std::int32_t bots_reorderUsernames::ID;

void bots_reorderUsernames::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1760972350);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(order_, s);
}

void bots_reorderUsernames::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1760972350);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(order_, s);
}

void bots_reorderUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.reorderUsernames");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

bots_reorderUsernames::ReturnType bots_reorderUsernames::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_exportMessageLink::channels_exportMessageLink(int32 flags_, bool grouped_, bool thread_, object_ptr<InputChannel> &&channel_, int32 id_)
  : flags_(flags_)
  , grouped_(grouped_)
  , thread_(thread_)
  , channel_(std::move(channel_))
  , id_(id_)
{}

const std::int32_t channels_exportMessageLink::ID;

void channels_exportMessageLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-432034325);
  TlStoreBinary::store((var0 = flags_ | (grouped_ << 0) | (thread_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(id_, s);
}

void channels_exportMessageLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-432034325);
  TlStoreBinary::store((var0 = flags_ | (grouped_ << 0) | (thread_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(id_, s);
}

void channels_exportMessageLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.exportMessageLink");
    s.store_field("flags", (var0 = flags_ | (grouped_ << 0) | (thread_ << 1)));
    if (var0 & 1) { s.store_field("grouped", true); }
    if (var0 & 2) { s.store_field("thread", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

channels_exportMessageLink::ReturnType channels_exportMessageLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<exportedMessageLink>, 1571494644>::parse(p);
#undef FAIL
}

channels_getChannelRecommendations::channels_getChannelRecommendations(int32 flags_, object_ptr<InputChannel> &&channel_)
  : flags_(flags_)
  , channel_(std::move(channel_))
{}

const std::int32_t channels_getChannelRecommendations::ID;

void channels_getChannelRecommendations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(631707458);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s); }
}

void channels_getChannelRecommendations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(631707458);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s); }
}

void channels_getChannelRecommendations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getChannelRecommendations");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get())); }
    s.store_class_end();
  }
}

channels_getChannelRecommendations::ReturnType channels_getChannelRecommendations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

channels_inviteToChannel::channels_inviteToChannel(object_ptr<InputChannel> &&channel_, array<object_ptr<InputUser>> &&users_)
  : channel_(std::move(channel_))
  , users_(std::move(users_))
{}

const std::int32_t channels_inviteToChannel::ID;

void channels_inviteToChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-907854508);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void channels_inviteToChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-907854508);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void channels_inviteToChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.inviteToChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_inviteToChannel::ReturnType channels_inviteToChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_invitedUsers>, 2136862630>::parse(p);
#undef FAIL
}

channels_readMessageContents::channels_readMessageContents(object_ptr<InputChannel> &&channel_, array<int32> &&id_)
  : channel_(std::move(channel_))
  , id_(std::move(id_))
{}

const std::int32_t channels_readMessageContents::ID;

void channels_readMessageContents::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-357180360);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void channels_readMessageContents::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-357180360);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void channels_readMessageContents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.readMessageContents");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_readMessageContents::ReturnType channels_readMessageContents::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_setMainProfileTab::channels_setMainProfileTab(object_ptr<InputChannel> &&channel_, object_ptr<ProfileTab> &&tab_)
  : channel_(std::move(channel_))
  , tab_(std::move(tab_))
{}

const std::int32_t channels_setMainProfileTab::ID;

void channels_setMainProfileTab::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(897842353);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(tab_, s);
}

void channels_setMainProfileTab::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(897842353);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(tab_, s);
}

void channels_setMainProfileTab::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.setMainProfileTab");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("tab", static_cast<const BaseObject *>(tab_.get()));
    s.store_class_end();
  }
}

channels_setMainProfileTab::ReturnType channels_setMainProfileTab::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_updatePaidMessagesPrice::channels_updatePaidMessagesPrice(int32 flags_, bool broadcast_messages_allowed_, object_ptr<InputChannel> &&channel_, int64 send_paid_messages_stars_)
  : flags_(flags_)
  , broadcast_messages_allowed_(broadcast_messages_allowed_)
  , channel_(std::move(channel_))
  , send_paid_messages_stars_(send_paid_messages_stars_)
{}

const std::int32_t channels_updatePaidMessagesPrice::ID;

void channels_updatePaidMessagesPrice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1259483771);
  TlStoreBinary::store((var0 = flags_ | (broadcast_messages_allowed_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(send_paid_messages_stars_, s);
}

void channels_updatePaidMessagesPrice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1259483771);
  TlStoreBinary::store((var0 = flags_ | (broadcast_messages_allowed_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(send_paid_messages_stars_, s);
}

void channels_updatePaidMessagesPrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.updatePaidMessagesPrice");
    s.store_field("flags", (var0 = flags_ | (broadcast_messages_allowed_ << 0)));
    if (var0 & 1) { s.store_field("broadcast_messages_allowed", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("send_paid_messages_stars", send_paid_messages_stars_);
    s.store_class_end();
  }
}

channels_updatePaidMessagesPrice::ReturnType channels_updatePaidMessagesPrice::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

chatlists_editExportedInvite::chatlists_editExportedInvite(int32 flags_, object_ptr<inputChatlistDialogFilter> &&chatlist_, string const &slug_, string const &title_, array<object_ptr<InputPeer>> &&peers_)
  : flags_(flags_)
  , chatlist_(std::move(chatlist_))
  , slug_(slug_)
  , title_(title_)
  , peers_(std::move(peers_))
{}

const std::int32_t chatlists_editExportedInvite::ID;

void chatlists_editExportedInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1698543165);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreString::store(slug_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s); }
}

void chatlists_editExportedInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1698543165);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreString::store(slug_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s); }
}

void chatlists_editExportedInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.editExportedInvite");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_field("slug", slug_);
    if (var0 & 2) { s.store_field("title", title_); }
    if (var0 & 4) { { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

chatlists_editExportedInvite::ReturnType chatlists_editExportedInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<exportedChatlistInvite>, 206668204>::parse(p);
#undef FAIL
}

contacts_deleteContacts::contacts_deleteContacts(array<object_ptr<InputUser>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t contacts_deleteContacts::ID;

void contacts_deleteContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(157945344);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void contacts_deleteContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(157945344);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void contacts_deleteContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.deleteContacts");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

contacts_deleteContacts::ReturnType contacts_deleteContacts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

contacts_importContactToken::contacts_importContactToken(string const &token_)
  : token_(token_)
{}

const std::int32_t contacts_importContactToken::ID;

void contacts_importContactToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(318789512);
  TlStoreString::store(token_, s);
}

void contacts_importContactToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(318789512);
  TlStoreString::store(token_, s);
}

void contacts_importContactToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.importContactToken");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

contacts_importContactToken::ReturnType contacts_importContactToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

contacts_resolvePhone::contacts_resolvePhone(string const &phone_)
  : phone_(phone_)
{}

const std::int32_t contacts_resolvePhone::ID;

void contacts_resolvePhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1963375804);
  TlStoreString::store(phone_, s);
}

void contacts_resolvePhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1963375804);
  TlStoreString::store(phone_, s);
}

void contacts_resolvePhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.resolvePhone");
    s.store_field("phone", phone_);
    s.store_class_end();
  }
}

contacts_resolvePhone::ReturnType contacts_resolvePhone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<contacts_resolvedPeer>, 2131196633>::parse(p);
#undef FAIL
}

contacts_resolveUsername::contacts_resolveUsername(int32 flags_, string const &username_, string const &referer_)
  : flags_(flags_)
  , username_(username_)
  , referer_(referer_)
{}

const std::int32_t contacts_resolveUsername::ID;

void contacts_resolveUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1918565308);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(username_, s);
  if (var0 & 1) { TlStoreString::store(referer_, s); }
}

void contacts_resolveUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1918565308);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(username_, s);
  if (var0 & 1) { TlStoreString::store(referer_, s); }
}

void contacts_resolveUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.resolveUsername");
    s.store_field("flags", (var0 = flags_));
    s.store_field("username", username_);
    if (var0 & 1) { s.store_field("referer", referer_); }
    s.store_class_end();
  }
}

contacts_resolveUsername::ReturnType contacts_resolveUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<contacts_resolvedPeer>, 2131196633>::parse(p);
#undef FAIL
}

const std::int32_t help_getPromoData::ID;

void help_getPromoData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1063816159);
}

void help_getPromoData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1063816159);
}

void help_getPromoData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getPromoData");
    s.store_class_end();
  }
}

help_getPromoData::ReturnType help_getPromoData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_PromoData>::parse(p);
#undef FAIL
}

invokeWithGooglePlayIntegrityPrefix::invokeWithGooglePlayIntegrityPrefix(string const &nonce_, string const &token_)
  : nonce_(nonce_)
  , token_(token_)
{}

const std::int32_t invokeWithGooglePlayIntegrityPrefix::ID;

void invokeWithGooglePlayIntegrityPrefix::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(502868356);
  TlStoreString::store(nonce_, s);
  TlStoreString::store(token_, s);
}

void invokeWithGooglePlayIntegrityPrefix::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(502868356);
  TlStoreString::store(nonce_, s);
  TlStoreString::store(token_, s);
}

void invokeWithGooglePlayIntegrityPrefix::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invokeWithGooglePlayIntegrityPrefix");
    s.store_field("nonce", nonce_);
    s.store_field("token", token_);
    s.store_class_end();
  }
}

invokeWithGooglePlayIntegrityPrefix::ReturnType invokeWithGooglePlayIntegrityPrefix::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<error>, -994444869>::parse(p);
#undef FAIL
}

messages_addPollAnswer::messages_addPollAnswer(object_ptr<InputPeer> &&peer_, int32 msg_id_, object_ptr<PollAnswer> &&answer_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , answer_(std::move(answer_))
{}

const std::int32_t messages_addPollAnswer::ID;

void messages_addPollAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(431770477);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(answer_, s);
}

void messages_addPollAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(431770477);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(answer_, s);
}

void messages_addPollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.addPollAnswer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_object_field("answer", static_cast<const BaseObject *>(answer_.get()));
    s.store_class_end();
  }
}

messages_addPollAnswer::ReturnType messages_addPollAnswer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_deleteMessages::messages_deleteMessages(int32 flags_, bool revoke_, array<int32> &&id_)
  : flags_(flags_)
  , revoke_(revoke_)
  , id_(std::move(id_))
{}

const std::int32_t messages_deleteMessages::ID;

void messages_deleteMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-443640366);
  TlStoreBinary::store((var0 = flags_ | (revoke_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_deleteMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-443640366);
  TlStoreBinary::store((var0 = flags_ | (revoke_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_deleteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteMessages");
    s.store_field("flags", (var0 = flags_ | (revoke_ << 0)));
    if (var0 & 1) { s.store_field("revoke", true); }
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_deleteMessages::ReturnType messages_deleteMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedMessages>, -2066640507>::parse(p);
#undef FAIL
}

messages_deletePollAnswer::messages_deletePollAnswer(object_ptr<InputPeer> &&peer_, int32 msg_id_, bytes &&option_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , option_(std::move(option_))
{}

const std::int32_t messages_deletePollAnswer::ID;

void messages_deletePollAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1400568411);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreString::store(option_, s);
}

void messages_deletePollAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1400568411);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreString::store(option_, s);
}

void messages_deletePollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deletePollAnswer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_bytes_field("option", option_);
    s.store_class_end();
  }
}

messages_deletePollAnswer::ReturnType messages_deletePollAnswer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editQuickReplyShortcut::messages_editQuickReplyShortcut(int32 shortcut_id_, string const &shortcut_)
  : shortcut_id_(shortcut_id_)
  , shortcut_(shortcut_)
{}

const std::int32_t messages_editQuickReplyShortcut::ID;

void messages_editQuickReplyShortcut::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1543519471);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreString::store(shortcut_, s);
}

void messages_editQuickReplyShortcut::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1543519471);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreString::store(shortcut_, s);
}

void messages_editQuickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editQuickReplyShortcut");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_field("shortcut", shortcut_);
    s.store_class_end();
  }
}

messages_editQuickReplyShortcut::ReturnType messages_editQuickReplyShortcut::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_getAttachMenuBot::messages_getAttachMenuBot(object_ptr<InputUser> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t messages_getAttachMenuBot::ID;

void messages_getAttachMenuBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1998676370);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void messages_getAttachMenuBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1998676370);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void messages_getAttachMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAttachMenuBot");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

messages_getAttachMenuBot::ReturnType messages_getAttachMenuBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<attachMenuBotsBot>, -1816172929>::parse(p);
#undef FAIL
}

messages_getExportedChatInvites::messages_getExportedChatInvites(int32 flags_, bool revoked_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&admin_id_, int32 offset_date_, string const &offset_link_, int32 limit_)
  : flags_(flags_)
  , revoked_(revoked_)
  , peer_(std::move(peer_))
  , admin_id_(std::move(admin_id_))
  , offset_date_(offset_date_)
  , offset_link_(offset_link_)
  , limit_(limit_)
{}

const std::int32_t messages_getExportedChatInvites::ID;

void messages_getExportedChatInvites::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1565154314);
  TlStoreBinary::store((var0 = flags_ | (revoked_ << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(admin_id_, s);
  if (var0 & 4) { TlStoreBinary::store(offset_date_, s); }
  if (var0 & 4) { TlStoreString::store(offset_link_, s); }
  TlStoreBinary::store(limit_, s);
}

void messages_getExportedChatInvites::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1565154314);
  TlStoreBinary::store((var0 = flags_ | (revoked_ << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(admin_id_, s);
  if (var0 & 4) { TlStoreBinary::store(offset_date_, s); }
  if (var0 & 4) { TlStoreString::store(offset_link_, s); }
  TlStoreBinary::store(limit_, s);
}

void messages_getExportedChatInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getExportedChatInvites");
    s.store_field("flags", (var0 = flags_ | (revoked_ << 3)));
    if (var0 & 8) { s.store_field("revoked", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("admin_id", static_cast<const BaseObject *>(admin_id_.get()));
    if (var0 & 4) { s.store_field("offset_date", offset_date_); }
    if (var0 & 4) { s.store_field("offset_link", offset_link_); }
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getExportedChatInvites::ReturnType messages_getExportedChatInvites::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_exportedChatInvites>, -1111085620>::parse(p);
#undef FAIL
}

messages_getFeaturedStickers::messages_getFeaturedStickers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getFeaturedStickers::ID;

void messages_getFeaturedStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1685588756);
  TlStoreBinary::store(hash_, s);
}

void messages_getFeaturedStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1685588756);
  TlStoreBinary::store(hash_, s);
}

void messages_getFeaturedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getFeaturedStickers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getFeaturedStickers::ReturnType messages_getFeaturedStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FeaturedStickers>::parse(p);
#undef FAIL
}

messages_getPeerSettings::messages_getPeerSettings(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_getPeerSettings::ID;

void messages_getPeerSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-270948702);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getPeerSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-270948702);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getPeerSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPeerSettings");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_getPeerSettings::ReturnType messages_getPeerSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_peerSettings>, 1753266509>::parse(p);
#undef FAIL
}

const std::int32_t messages_getPinnedSavedDialogs::ID;

void messages_getPinnedSavedDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-700607264);
}

void messages_getPinnedSavedDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-700607264);
}

void messages_getPinnedSavedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPinnedSavedDialogs");
    s.store_class_end();
  }
}

messages_getPinnedSavedDialogs::ReturnType messages_getPinnedSavedDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SavedDialogs>::parse(p);
#undef FAIL
}

messages_getSearchCounters::messages_getSearchCounters(int32 flags_, object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&saved_peer_id_, int32 top_msg_id_, array<object_ptr<MessagesFilter>> &&filters_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , saved_peer_id_(std::move(saved_peer_id_))
  , top_msg_id_(top_msg_id_)
  , filters_(std::move(filters_))
{}

const std::int32_t messages_getSearchCounters::ID;

void messages_getSearchCounters::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(465367808);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(filters_, s);
}

void messages_getSearchCounters::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(465367808);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(filters_, s);
}

void messages_getSearchCounters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSearchCounters");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 4) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    { s.store_vector_begin("filters", filters_.size()); for (const auto &_value : filters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getSearchCounters::ReturnType messages_getSearchCounters::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messages_searchCounter>, -398136321>>, 481674261>::parse(p);
#undef FAIL
}

messages_getStickerSet::messages_getStickerSet(object_ptr<InputStickerSet> &&stickerset_, int32 hash_)
  : stickerset_(std::move(stickerset_))
  , hash_(hash_)
{}

const std::int32_t messages_getStickerSet::ID;

void messages_getStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-928977804);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-928977804);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getStickerSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getStickerSet::ReturnType messages_getStickerSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

messages_hidePeerSettingsBar::messages_hidePeerSettingsBar(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_hidePeerSettingsBar::ID;

void messages_hidePeerSettingsBar::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1336717624);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_hidePeerSettingsBar::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1336717624);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_hidePeerSettingsBar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.hidePeerSettingsBar");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_hidePeerSettingsBar::ReturnType messages_hidePeerSettingsBar::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_requestSimpleWebView::messages_requestSimpleWebView(int32 flags_, bool from_switch_webview_, bool from_side_menu_, bool compact_, bool fullscreen_, object_ptr<InputUser> &&bot_, string const &url_, string const &start_param_, object_ptr<dataJSON> &&theme_params_, string const &platform_)
  : flags_(flags_)
  , from_switch_webview_(from_switch_webview_)
  , from_side_menu_(from_side_menu_)
  , compact_(compact_)
  , fullscreen_(fullscreen_)
  , bot_(std::move(bot_))
  , url_(url_)
  , start_param_(start_param_)
  , theme_params_(std::move(theme_params_))
  , platform_(platform_)
{}

const std::int32_t messages_requestSimpleWebView::ID;

void messages_requestSimpleWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1094336115);
  TlStoreBinary::store((var0 = flags_ | (from_switch_webview_ << 1) | (from_side_menu_ << 2) | (compact_ << 7) | (fullscreen_ << 8)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 8) { TlStoreString::store(url_, s); }
  if (var0 & 16) { TlStoreString::store(start_param_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestSimpleWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1094336115);
  TlStoreBinary::store((var0 = flags_ | (from_switch_webview_ << 1) | (from_side_menu_ << 2) | (compact_ << 7) | (fullscreen_ << 8)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 8) { TlStoreString::store(url_, s); }
  if (var0 & 16) { TlStoreString::store(start_param_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestSimpleWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestSimpleWebView");
    s.store_field("flags", (var0 = flags_ | (from_switch_webview_ << 1) | (from_side_menu_ << 2) | (compact_ << 7) | (fullscreen_ << 8)));
    if (var0 & 2) { s.store_field("from_switch_webview", true); }
    if (var0 & 4) { s.store_field("from_side_menu", true); }
    if (var0 & 128) { s.store_field("compact", true); }
    if (var0 & 256) { s.store_field("fullscreen", true); }
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    if (var0 & 8) { s.store_field("url", url_); }
    if (var0 & 16) { s.store_field("start_param", start_param_); }
    if (var0 & 1) { s.store_object_field("theme_params", static_cast<const BaseObject *>(theme_params_.get())); }
    s.store_field("platform", platform_);
    s.store_class_end();
  }
}

messages_requestSimpleWebView::ReturnType messages_requestSimpleWebView::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<webViewResultUrl>, 1294139288>::parse(p);
#undef FAIL
}

messages_sendMedia::messages_sendMedia(int32 flags_, bool silent_, bool background_, bool clear_draft_, bool noforwards_, bool update_stickersets_order_, bool invert_media_, bool allow_paid_floodskip_, object_ptr<InputPeer> &&peer_, object_ptr<InputReplyTo> &&reply_to_, object_ptr<InputMedia> &&media_, string const &message_, int64 random_id_, object_ptr<ReplyMarkup> &&reply_markup_, array<object_ptr<MessageEntity>> &&entities_, int32 schedule_date_, int32 schedule_repeat_period_, object_ptr<InputPeer> &&send_as_, object_ptr<InputQuickReplyShortcut> &&quick_reply_shortcut_, int64 effect_, int64 allow_paid_stars_, object_ptr<suggestedPost> &&suggested_post_)
  : flags_(flags_)
  , silent_(silent_)
  , background_(background_)
  , clear_draft_(clear_draft_)
  , noforwards_(noforwards_)
  , update_stickersets_order_(update_stickersets_order_)
  , invert_media_(invert_media_)
  , allow_paid_floodskip_(allow_paid_floodskip_)
  , peer_(std::move(peer_))
  , reply_to_(std::move(reply_to_))
  , media_(std::move(media_))
  , message_(message_)
  , random_id_(random_id_)
  , reply_markup_(std::move(reply_markup_))
  , entities_(std::move(entities_))
  , schedule_date_(schedule_date_)
  , schedule_repeat_period_(schedule_repeat_period_)
  , send_as_(std::move(send_as_))
  , quick_reply_shortcut_(std::move(quick_reply_shortcut_))
  , effect_(effect_)
  , allow_paid_stars_(allow_paid_stars_)
  , suggested_post_(std::move(suggested_post_))
{}

const std::int32_t messages_sendMedia::ID;

void messages_sendMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(53536639);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  TlStoreString::store(message_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 16777216) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 4194304) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
}

void messages_sendMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(53536639);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  TlStoreString::store(message_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 16777216) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 4194304) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
}

void messages_sendMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendMedia");
    s.store_field("flags", (var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19)));
    if (var0 & 32) { s.store_field("silent", true); }
    if (var0 & 64) { s.store_field("background", true); }
    if (var0 & 128) { s.store_field("clear_draft", true); }
    if (var0 & 16384) { s.store_field("noforwards", true); }
    if (var0 & 32768) { s.store_field("update_stickersets_order", true); }
    if (var0 & 65536) { s.store_field("invert_media", true); }
    if (var0 & 524288) { s.store_field("allow_paid_floodskip", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_field("message", message_);
    s.store_field("random_id", random_id_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1024) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 16777216) { s.store_field("schedule_repeat_period", schedule_repeat_period_); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    if (var0 & 131072) { s.store_object_field("quick_reply_shortcut", static_cast<const BaseObject *>(quick_reply_shortcut_.get())); }
    if (var0 & 262144) { s.store_field("effect", effect_); }
    if (var0 & 2097152) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    if (var0 & 4194304) { s.store_object_field("suggested_post", static_cast<const BaseObject *>(suggested_post_.get())); }
    s.store_class_end();
  }
}

messages_sendMedia::ReturnType messages_sendMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_sendMessage::messages_sendMessage(int32 flags_, bool no_webpage_, bool silent_, bool background_, bool clear_draft_, bool noforwards_, bool update_stickersets_order_, bool invert_media_, bool allow_paid_floodskip_, object_ptr<InputPeer> &&peer_, object_ptr<InputReplyTo> &&reply_to_, string const &message_, int64 random_id_, object_ptr<ReplyMarkup> &&reply_markup_, array<object_ptr<MessageEntity>> &&entities_, int32 schedule_date_, int32 schedule_repeat_period_, object_ptr<InputPeer> &&send_as_, object_ptr<InputQuickReplyShortcut> &&quick_reply_shortcut_, int64 effect_, int64 allow_paid_stars_, object_ptr<suggestedPost> &&suggested_post_)
  : flags_(flags_)
  , no_webpage_(no_webpage_)
  , silent_(silent_)
  , background_(background_)
  , clear_draft_(clear_draft_)
  , noforwards_(noforwards_)
  , update_stickersets_order_(update_stickersets_order_)
  , invert_media_(invert_media_)
  , allow_paid_floodskip_(allow_paid_floodskip_)
  , peer_(std::move(peer_))
  , reply_to_(std::move(reply_to_))
  , message_(message_)
  , random_id_(random_id_)
  , reply_markup_(std::move(reply_markup_))
  , entities_(std::move(entities_))
  , schedule_date_(schedule_date_)
  , schedule_repeat_period_(schedule_repeat_period_)
  , send_as_(std::move(send_as_))
  , quick_reply_shortcut_(std::move(quick_reply_shortcut_))
  , effect_(effect_)
  , allow_paid_stars_(allow_paid_stars_)
  , suggested_post_(std::move(suggested_post_))
{}

const std::int32_t messages_sendMessage::ID;

void messages_sendMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1415369050);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreString::store(message_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 16777216) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 4194304) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
}

void messages_sendMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1415369050);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreString::store(message_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 16777216) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 4194304) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
}

void messages_sendMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendMessage");
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 1) | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19)));
    if (var0 & 2) { s.store_field("no_webpage", true); }
    if (var0 & 32) { s.store_field("silent", true); }
    if (var0 & 64) { s.store_field("background", true); }
    if (var0 & 128) { s.store_field("clear_draft", true); }
    if (var0 & 16384) { s.store_field("noforwards", true); }
    if (var0 & 32768) { s.store_field("update_stickersets_order", true); }
    if (var0 & 65536) { s.store_field("invert_media", true); }
    if (var0 & 524288) { s.store_field("allow_paid_floodskip", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_field("message", message_);
    s.store_field("random_id", random_id_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1024) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 16777216) { s.store_field("schedule_repeat_period", schedule_repeat_period_); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    if (var0 & 131072) { s.store_object_field("quick_reply_shortcut", static_cast<const BaseObject *>(quick_reply_shortcut_.get())); }
    if (var0 & 262144) { s.store_field("effect", effect_); }
    if (var0 & 2097152) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    if (var0 & 4194304) { s.store_object_field("suggested_post", static_cast<const BaseObject *>(suggested_post_.get())); }
    s.store_class_end();
  }
}

messages_sendMessage::ReturnType messages_sendMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setChatWallPaper::messages_setChatWallPaper(int32 flags_, bool for_both_, bool revert_, object_ptr<InputPeer> &&peer_, object_ptr<InputWallPaper> &&wallpaper_, object_ptr<wallPaperSettings> &&settings_, int32 id_)
  : flags_(flags_)
  , for_both_(for_both_)
  , revert_(revert_)
  , peer_(std::move(peer_))
  , wallpaper_(std::move(wallpaper_))
  , settings_(std::move(settings_))
  , id_(id_)
{}

const std::int32_t messages_setChatWallPaper::ID;

void messages_setChatWallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1879389471);
  TlStoreBinary::store((var0 = flags_ | (for_both_ << 3) | (revert_ << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s); }
  if (var0 & 2) { TlStoreBinary::store(id_, s); }
}

void messages_setChatWallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1879389471);
  TlStoreBinary::store((var0 = flags_ | (for_both_ << 3) | (revert_ << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s); }
  if (var0 & 2) { TlStoreBinary::store(id_, s); }
}

void messages_setChatWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setChatWallPaper");
    s.store_field("flags", (var0 = flags_ | (for_both_ << 3) | (revert_ << 4)));
    if (var0 & 8) { s.store_field("for_both", true); }
    if (var0 & 16) { s.store_field("revert", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get())); }
    if (var0 & 4) { s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get())); }
    if (var0 & 2) { s.store_field("id", id_); }
    s.store_class_end();
  }
}

messages_setChatWallPaper::ReturnType messages_setChatWallPaper::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setInlineBotResults::messages_setInlineBotResults(int32 flags_, bool gallery_, bool private_, int64 query_id_, array<object_ptr<InputBotInlineResult>> &&results_, int32 cache_time_, string const &next_offset_, object_ptr<inlineBotSwitchPM> &&switch_pm_, object_ptr<inlineBotWebView> &&switch_webview_)
  : flags_(flags_)
  , gallery_(gallery_)
  , private_(private_)
  , query_id_(query_id_)
  , results_(std::move(results_))
  , cache_time_(cache_time_)
  , next_offset_(next_offset_)
  , switch_pm_(std::move(switch_pm_))
  , switch_webview_(std::move(switch_webview_))
{}

const std::int32_t messages_setInlineBotResults::ID;

void messages_setInlineBotResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1156406247);
  TlStoreBinary::store((var0 = flags_ | (gallery_ << 0) | (private_ << 1)), s);
  TlStoreBinary::store(query_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(results_, s);
  TlStoreBinary::store(cache_time_, s);
  if (var0 & 4) { TlStoreString::store(next_offset_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, 1008755359>::store(switch_pm_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreObject, -1250781739>::store(switch_webview_, s); }
}

void messages_setInlineBotResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1156406247);
  TlStoreBinary::store((var0 = flags_ | (gallery_ << 0) | (private_ << 1)), s);
  TlStoreBinary::store(query_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(results_, s);
  TlStoreBinary::store(cache_time_, s);
  if (var0 & 4) { TlStoreString::store(next_offset_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, 1008755359>::store(switch_pm_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreObject, -1250781739>::store(switch_webview_, s); }
}

void messages_setInlineBotResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setInlineBotResults");
    s.store_field("flags", (var0 = flags_ | (gallery_ << 0) | (private_ << 1)));
    if (var0 & 1) { s.store_field("gallery", true); }
    if (var0 & 2) { s.store_field("private", true); }
    s.store_field("query_id", query_id_);
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("cache_time", cache_time_);
    if (var0 & 4) { s.store_field("next_offset", next_offset_); }
    if (var0 & 8) { s.store_object_field("switch_pm", static_cast<const BaseObject *>(switch_pm_.get())); }
    if (var0 & 16) { s.store_object_field("switch_webview", static_cast<const BaseObject *>(switch_webview_.get())); }
    s.store_class_end();
  }
}

messages_setInlineBotResults::ReturnType messages_setInlineBotResults::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_toggleNoForwards::messages_toggleNoForwards(int32 flags_, object_ptr<InputPeer> &&peer_, bool enabled_, int32 request_msg_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , enabled_(enabled_)
  , request_msg_id_(request_msg_id_)
{}

const std::int32_t messages_toggleNoForwards::ID;

void messages_toggleNoForwards::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1308091851);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(enabled_, s);
  if (var0 & 1) { TlStoreBinary::store(request_msg_id_, s); }
}

void messages_toggleNoForwards::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1308091851);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(enabled_, s);
  if (var0 & 1) { TlStoreBinary::store(request_msg_id_, s); }
}

void messages_toggleNoForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleNoForwards");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("enabled", enabled_);
    if (var0 & 1) { s.store_field("request_msg_id", request_msg_id_); }
    s.store_class_end();
  }
}

messages_toggleNoForwards::ReturnType messages_toggleNoForwards::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_updateSavedReactionTag::messages_updateSavedReactionTag(int32 flags_, object_ptr<Reaction> &&reaction_, string const &title_)
  : flags_(flags_)
  , reaction_(std::move(reaction_))
  , title_(title_)
{}

const std::int32_t messages_updateSavedReactionTag::ID;

void messages_updateSavedReactionTag::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1613331948);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
}

void messages_updateSavedReactionTag::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1613331948);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
}

void messages_updateSavedReactionTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.updateSavedReactionTag");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    if (var0 & 1) { s.store_field("title", title_); }
    s.store_class_end();
  }
}

messages_updateSavedReactionTag::ReturnType messages_updateSavedReactionTag::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_uploadImportedMedia::messages_uploadImportedMedia(object_ptr<InputPeer> &&peer_, int64 import_id_, string const &file_name_, object_ptr<InputMedia> &&media_)
  : peer_(std::move(peer_))
  , import_id_(import_id_)
  , file_name_(file_name_)
  , media_(std::move(media_))
{}

const std::int32_t messages_uploadImportedMedia::ID;

void messages_uploadImportedMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(713433234);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(import_id_, s);
  TlStoreString::store(file_name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messages_uploadImportedMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(713433234);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(import_id_, s);
  TlStoreString::store(file_name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messages_uploadImportedMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.uploadImportedMedia");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("import_id", import_id_);
    s.store_field("file_name", file_name_);
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

messages_uploadImportedMedia::ReturnType messages_uploadImportedMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<MessageMedia>::parse(p);
#undef FAIL
}

payments_assignPlayMarketTransaction::payments_assignPlayMarketTransaction(object_ptr<dataJSON> &&receipt_, object_ptr<InputStorePaymentPurpose> &&purpose_)
  : receipt_(std::move(receipt_))
  , purpose_(std::move(purpose_))
{}

const std::int32_t payments_assignPlayMarketTransaction::ID;

void payments_assignPlayMarketTransaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-537046829);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(receipt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_assignPlayMarketTransaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-537046829);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(receipt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_assignPlayMarketTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.assignPlayMarketTransaction");
    s.store_object_field("receipt", static_cast<const BaseObject *>(receipt_.get()));
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

payments_assignPlayMarketTransaction::ReturnType payments_assignPlayMarketTransaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_checkCanSendGift::payments_checkCanSendGift(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t payments_checkCanSendGift::ID;

void payments_checkCanSendGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1060835895);
  TlStoreBinary::store(gift_id_, s);
}

void payments_checkCanSendGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1060835895);
  TlStoreBinary::store(gift_id_, s);
}

void payments_checkCanSendGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.checkCanSendGift");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

payments_checkCanSendGift::ReturnType payments_checkCanSendGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_CheckCanSendGiftResult>::parse(p);
#undef FAIL
}

payments_craftStarGift::payments_craftStarGift(array<object_ptr<InputSavedStarGift>> &&stargift_)
  : stargift_(std::move(stargift_))
{}

const std::int32_t payments_craftStarGift::ID;

void payments_craftStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1325832113);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_craftStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1325832113);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_craftStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.craftStarGift");
    { s.store_vector_begin("stargift", stargift_.size()); for (const auto &_value : stargift_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_craftStarGift::ReturnType payments_craftStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_createStarGiftCollection::payments_createStarGiftCollection(object_ptr<InputPeer> &&peer_, string const &title_, array<object_ptr<InputSavedStarGift>> &&stargift_)
  : peer_(std::move(peer_))
  , title_(title_)
  , stargift_(std::move(stargift_))
{}

const std::int32_t payments_createStarGiftCollection::ID;

void payments_createStarGiftCollection::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(524947079);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_createStarGiftCollection::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(524947079);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_createStarGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.createStarGiftCollection");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("title", title_);
    { s.store_vector_begin("stargift", stargift_.size()); for (const auto &_value : stargift_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_createStarGiftCollection::ReturnType payments_createStarGiftCollection::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<starGiftCollection>, -1653926992>::parse(p);
#undef FAIL
}

payments_getConnectedStarRefBot::payments_getConnectedStarRefBot(object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&bot_)
  : peer_(std::move(peer_))
  , bot_(std::move(bot_))
{}

const std::int32_t payments_getConnectedStarRefBot::ID;

void payments_getConnectedStarRefBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1210476304);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void payments_getConnectedStarRefBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1210476304);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void payments_getConnectedStarRefBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getConnectedStarRefBot");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

payments_getConnectedStarRefBot::ReturnType payments_getConnectedStarRefBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_connectedStarRefBots>, -1730811363>::parse(p);
#undef FAIL
}

payments_getConnectedStarRefBots::payments_getConnectedStarRefBots(int32 flags_, object_ptr<InputPeer> &&peer_, int32 offset_date_, string const &offset_link_, int32 limit_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , offset_date_(offset_date_)
  , offset_link_(offset_link_)
  , limit_(limit_)
{}

const std::int32_t payments_getConnectedStarRefBots::ID;

void payments_getConnectedStarRefBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1483318611);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBinary::store(offset_date_, s); }
  if (var0 & 4) { TlStoreString::store(offset_link_, s); }
  TlStoreBinary::store(limit_, s);
}

void payments_getConnectedStarRefBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1483318611);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBinary::store(offset_date_, s); }
  if (var0 & 4) { TlStoreString::store(offset_link_, s); }
  TlStoreBinary::store(limit_, s);
}

void payments_getConnectedStarRefBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getConnectedStarRefBots");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 4) { s.store_field("offset_date", offset_date_); }
    if (var0 & 4) { s.store_field("offset_link", offset_link_); }
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

payments_getConnectedStarRefBots::ReturnType payments_getConnectedStarRefBots::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_connectedStarRefBots>, -1730811363>::parse(p);
#undef FAIL
}

payments_getCraftStarGifts::payments_getCraftStarGifts(int64 gift_id_, string const &offset_, int32 limit_)
  : gift_id_(gift_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t payments_getCraftStarGifts::ID;

void payments_getCraftStarGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-49947392);
  TlStoreBinary::store(gift_id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getCraftStarGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-49947392);
  TlStoreBinary::store(gift_id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getCraftStarGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getCraftStarGifts");
    s.store_field("gift_id", gift_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

payments_getCraftStarGifts::ReturnType payments_getCraftStarGifts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_savedStarGifts>, -1779201615>::parse(p);
#undef FAIL
}

payments_getPaymentReceipt::payments_getPaymentReceipt(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t payments_getPaymentReceipt::ID;

void payments_getPaymentReceipt::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(611897804);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void payments_getPaymentReceipt::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(611897804);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void payments_getPaymentReceipt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getPaymentReceipt");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

payments_getPaymentReceipt::ReturnType payments_getPaymentReceipt::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_PaymentReceipt>::parse(p);
#undef FAIL
}

payments_getUniqueStarGift::payments_getUniqueStarGift(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t payments_getUniqueStarGift::ID;

void payments_getUniqueStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1583919758);
  TlStoreString::store(slug_, s);
}

void payments_getUniqueStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1583919758);
  TlStoreString::store(slug_, s);
}

void payments_getUniqueStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getUniqueStarGift");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

payments_getUniqueStarGift::ReturnType payments_getUniqueStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_uniqueStarGift>, 1097619176>::parse(p);
#undef FAIL
}

payments_transferStarGift::payments_transferStarGift(object_ptr<InputSavedStarGift> &&stargift_, object_ptr<InputPeer> &&to_id_)
  : stargift_(std::move(stargift_))
  , to_id_(std::move(to_id_))
{}

const std::int32_t payments_transferStarGift::ID;

void payments_transferStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2132285290);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_id_, s);
}

void payments_transferStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2132285290);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_id_, s);
}

void payments_transferStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.transferStarGift");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_object_field("to_id", static_cast<const BaseObject *>(to_id_.get()));
    s.store_class_end();
  }
}

payments_transferStarGift::ReturnType payments_transferStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_checkGroupCall::phone_checkGroupCall(object_ptr<InputGroupCall> &&call_, array<int32> &&sources_)
  : call_(std::move(call_))
  , sources_(std::move(sources_))
{}

const std::int32_t phone_checkGroupCall::ID;

void phone_checkGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1248003721);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(sources_, s);
}

void phone_checkGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1248003721);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(sources_, s);
}

void phone_checkGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.checkGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("sources", sources_.size()); for (const auto &_value : sources_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

phone_checkGroupCall::ReturnType phone_checkGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
#undef FAIL
}

phone_deleteGroupCallMessages::phone_deleteGroupCallMessages(int32 flags_, bool report_spam_, object_ptr<InputGroupCall> &&call_, array<int32> &&messages_)
  : flags_(flags_)
  , report_spam_(report_spam_)
  , call_(std::move(call_))
  , messages_(std::move(messages_))
{}

const std::int32_t phone_deleteGroupCallMessages::ID;

void phone_deleteGroupCallMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-162573065);
  TlStoreBinary::store((var0 = flags_ | (report_spam_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(messages_, s);
}

void phone_deleteGroupCallMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-162573065);
  TlStoreBinary::store((var0 = flags_ | (report_spam_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(messages_, s);
}

void phone_deleteGroupCallMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.deleteGroupCallMessages");
    s.store_field("flags", (var0 = flags_ | (report_spam_ << 0)));
    if (var0 & 1) { s.store_field("report_spam", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

phone_deleteGroupCallMessages::ReturnType phone_deleteGroupCallMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_editGroupCallParticipant::phone_editGroupCallParticipant(int32 flags_, object_ptr<InputGroupCall> &&call_, object_ptr<InputPeer> &&participant_, bool muted_, int32 volume_, bool raise_hand_, bool video_stopped_, bool video_paused_, bool presentation_paused_)
  : flags_(flags_)
  , call_(std::move(call_))
  , participant_(std::move(participant_))
  , muted_(muted_)
  , volume_(volume_)
  , raise_hand_(raise_hand_)
  , video_stopped_(video_stopped_)
  , video_paused_(video_paused_)
  , presentation_paused_(presentation_paused_)
{}

const std::int32_t phone_editGroupCallParticipant::ID;

void phone_editGroupCallParticipant::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1524155713);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  if (var0 & 1) { TlStoreBool::store(muted_, s); }
  if (var0 & 2) { TlStoreBinary::store(volume_, s); }
  if (var0 & 4) { TlStoreBool::store(raise_hand_, s); }
  if (var0 & 8) { TlStoreBool::store(video_stopped_, s); }
  if (var0 & 16) { TlStoreBool::store(video_paused_, s); }
  if (var0 & 32) { TlStoreBool::store(presentation_paused_, s); }
}

void phone_editGroupCallParticipant::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1524155713);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  if (var0 & 1) { TlStoreBool::store(muted_, s); }
  if (var0 & 2) { TlStoreBinary::store(volume_, s); }
  if (var0 & 4) { TlStoreBool::store(raise_hand_, s); }
  if (var0 & 8) { TlStoreBool::store(video_stopped_, s); }
  if (var0 & 16) { TlStoreBool::store(video_paused_, s); }
  if (var0 & 32) { TlStoreBool::store(presentation_paused_, s); }
}

void phone_editGroupCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.editGroupCallParticipant");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    if (var0 & 1) { s.store_field("muted", muted_); }
    if (var0 & 2) { s.store_field("volume", volume_); }
    if (var0 & 4) { s.store_field("raise_hand", raise_hand_); }
    if (var0 & 8) { s.store_field("video_stopped", video_stopped_); }
    if (var0 & 16) { s.store_field("video_paused", video_paused_); }
    if (var0 & 32) { s.store_field("presentation_paused", presentation_paused_); }
    s.store_class_end();
  }
}

phone_editGroupCallParticipant::ReturnType phone_editGroupCallParticipant::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_joinGroupCallPresentation::phone_joinGroupCallPresentation(object_ptr<InputGroupCall> &&call_, object_ptr<dataJSON> &&params_)
  : call_(std::move(call_))
  , params_(std::move(params_))
{}

const std::int32_t phone_joinGroupCallPresentation::ID;

void phone_joinGroupCallPresentation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-873829436);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void phone_joinGroupCallPresentation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-873829436);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void phone_joinGroupCallPresentation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.joinGroupCallPresentation");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("params", static_cast<const BaseObject *>(params_.get()));
    s.store_class_end();
  }
}

phone_joinGroupCallPresentation::ReturnType phone_joinGroupCallPresentation::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_saveDefaultGroupCallJoinAs::phone_saveDefaultGroupCallJoinAs(object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&join_as_)
  : peer_(std::move(peer_))
  , join_as_(std::move(join_as_))
{}

const std::int32_t phone_saveDefaultGroupCallJoinAs::ID;

void phone_saveDefaultGroupCallJoinAs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1465786252);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(join_as_, s);
}

void phone_saveDefaultGroupCallJoinAs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1465786252);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(join_as_, s);
}

void phone_saveDefaultGroupCallJoinAs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.saveDefaultGroupCallJoinAs");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("join_as", static_cast<const BaseObject *>(join_as_.get()));
    s.store_class_end();
  }
}

phone_saveDefaultGroupCallJoinAs::ReturnType phone_saveDefaultGroupCallJoinAs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_sendConferenceCallBroadcast::phone_sendConferenceCallBroadcast(object_ptr<InputGroupCall> &&call_, bytes &&block_)
  : call_(std::move(call_))
  , block_(std::move(block_))
{}

const std::int32_t phone_sendConferenceCallBroadcast::ID;

void phone_sendConferenceCallBroadcast::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-965732096);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreString::store(block_, s);
}

void phone_sendConferenceCallBroadcast::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-965732096);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreString::store(block_, s);
}

void phone_sendConferenceCallBroadcast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.sendConferenceCallBroadcast");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_bytes_field("block", block_);
    s.store_class_end();
  }
}

phone_sendConferenceCallBroadcast::ReturnType phone_sendConferenceCallBroadcast::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_setCallRating::phone_setCallRating(int32 flags_, bool user_initiative_, object_ptr<inputPhoneCall> &&peer_, int32 rating_, string const &comment_)
  : flags_(flags_)
  , user_initiative_(user_initiative_)
  , peer_(std::move(peer_))
  , rating_(rating_)
  , comment_(comment_)
{}

const std::int32_t phone_setCallRating::ID;

void phone_setCallRating::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1508562471);
  TlStoreBinary::store((var0 = flags_ | (user_initiative_ << 0)), s);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBinary::store(rating_, s);
  TlStoreString::store(comment_, s);
}

void phone_setCallRating::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1508562471);
  TlStoreBinary::store((var0 = flags_ | (user_initiative_ << 0)), s);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBinary::store(rating_, s);
  TlStoreString::store(comment_, s);
}

void phone_setCallRating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.setCallRating");
    s.store_field("flags", (var0 = flags_ | (user_initiative_ << 0)));
    if (var0 & 1) { s.store_field("user_initiative", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("rating", rating_);
    s.store_field("comment", comment_);
    s.store_class_end();
  }
}

phone_setCallRating::ReturnType phone_setCallRating::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

stories_getAlbumStories::stories_getAlbumStories(object_ptr<InputPeer> &&peer_, int32 album_id_, int32 offset_, int32 limit_)
  : peer_(std::move(peer_))
  , album_id_(album_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t stories_getAlbumStories::ID;

void stories_getAlbumStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1400869535);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(album_id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getAlbumStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1400869535);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(album_id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getAlbumStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getAlbumStories");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("album_id", album_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stories_getAlbumStories::ReturnType stories_getAlbumStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_stories>, 1673780490>::parse(p);
#undef FAIL
}

stories_getStoriesArchive::stories_getStoriesArchive(object_ptr<InputPeer> &&peer_, int32 offset_id_, int32 limit_)
  : peer_(std::move(peer_))
  , offset_id_(offset_id_)
  , limit_(limit_)
{}

const std::int32_t stories_getStoriesArchive::ID;

void stories_getStoriesArchive::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1271586794);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getStoriesArchive::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1271586794);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getStoriesArchive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getStoriesArchive");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stories_getStoriesArchive::ReturnType stories_getStoriesArchive::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_stories>, 1673780490>::parse(p);
#undef FAIL
}

upload_getFile::upload_getFile(int32 flags_, bool precise_, bool cdn_supported_, object_ptr<InputFileLocation> &&location_, int64 offset_, int32 limit_)
  : flags_(flags_)
  , precise_(precise_)
  , cdn_supported_(cdn_supported_)
  , location_(std::move(location_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t upload_getFile::ID;

void upload_getFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1101843010);
  TlStoreBinary::store((var0 = flags_ | (precise_ << 0) | (cdn_supported_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(location_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void upload_getFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1101843010);
  TlStoreBinary::store((var0 = flags_ | (precise_ << 0) | (cdn_supported_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(location_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void upload_getFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.getFile");
    s.store_field("flags", (var0 = flags_ | (precise_ << 0) | (cdn_supported_ << 1)));
    if (var0 & 1) { s.store_field("precise", true); }
    if (var0 & 2) { s.store_field("cdn_supported", true); }
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

upload_getFile::ReturnType upload_getFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<upload_File>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
