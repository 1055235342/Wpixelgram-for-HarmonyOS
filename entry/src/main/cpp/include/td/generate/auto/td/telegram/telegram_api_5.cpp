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


object_ptr<BaseTheme> BaseTheme::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case baseThemeClassic::ID:
      return baseThemeClassic::fetch(p);
    case baseThemeDay::ID:
      return baseThemeDay::fetch(p);
    case baseThemeNight::ID:
      return baseThemeNight::fetch(p);
    case baseThemeTinted::ID:
      return baseThemeTinted::fetch(p);
    case baseThemeArctic::ID:
      return baseThemeArctic::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t baseThemeClassic::ID;

object_ptr<BaseTheme> baseThemeClassic::fetch(TlBufferParser &p) {
  return make_tl_object<baseThemeClassic>();
}

void baseThemeClassic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void baseThemeClassic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void baseThemeClassic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "baseThemeClassic");
    s.store_class_end();
  }
}

const std::int32_t baseThemeDay::ID;

object_ptr<BaseTheme> baseThemeDay::fetch(TlBufferParser &p) {
  return make_tl_object<baseThemeDay>();
}

void baseThemeDay::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void baseThemeDay::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void baseThemeDay::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "baseThemeDay");
    s.store_class_end();
  }
}

const std::int32_t baseThemeNight::ID;

object_ptr<BaseTheme> baseThemeNight::fetch(TlBufferParser &p) {
  return make_tl_object<baseThemeNight>();
}

void baseThemeNight::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void baseThemeNight::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void baseThemeNight::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "baseThemeNight");
    s.store_class_end();
  }
}

const std::int32_t baseThemeTinted::ID;

object_ptr<BaseTheme> baseThemeTinted::fetch(TlBufferParser &p) {
  return make_tl_object<baseThemeTinted>();
}

void baseThemeTinted::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void baseThemeTinted::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void baseThemeTinted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "baseThemeTinted");
    s.store_class_end();
  }
}

const std::int32_t baseThemeArctic::ID;

object_ptr<BaseTheme> baseThemeArctic::fetch(TlBufferParser &p) {
  return make_tl_object<baseThemeArctic>();
}

void baseThemeArctic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void baseThemeArctic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void baseThemeArctic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "baseThemeArctic");
    s.store_class_end();
  }
}

object_ptr<BotMenuButton> BotMenuButton::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case botMenuButtonDefault::ID:
      return botMenuButtonDefault::fetch(p);
    case botMenuButtonCommands::ID:
      return botMenuButtonCommands::fetch(p);
    case botMenuButton::ID:
      return botMenuButton::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t botMenuButtonDefault::ID;

object_ptr<BotMenuButton> botMenuButtonDefault::fetch(TlBufferParser &p) {
  return make_tl_object<botMenuButtonDefault>();
}

void botMenuButtonDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void botMenuButtonDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void botMenuButtonDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMenuButtonDefault");
    s.store_class_end();
  }
}

const std::int32_t botMenuButtonCommands::ID;

object_ptr<BotMenuButton> botMenuButtonCommands::fetch(TlBufferParser &p) {
  return make_tl_object<botMenuButtonCommands>();
}

void botMenuButtonCommands::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void botMenuButtonCommands::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void botMenuButtonCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMenuButtonCommands");
    s.store_class_end();
  }
}

botMenuButton::botMenuButton(string const &text_, string const &url_)
  : text_(text_)
  , url_(url_)
{}

const std::int32_t botMenuButton::ID;

object_ptr<BotMenuButton> botMenuButton::fetch(TlBufferParser &p) {
  return make_tl_object<botMenuButton>(p);
}

botMenuButton::botMenuButton(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , url_(TlFetchString<string>::parse(p))
{}

void botMenuButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void botMenuButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void botMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botMenuButton");
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

businessBotRecipients::businessBotRecipients()
  : flags_()
  , existing_chats_()
  , new_chats_()
  , contacts_()
  , non_contacts_()
  , exclude_selected_()
  , users_()
  , exclude_users_()
{}

const std::int32_t businessBotRecipients::ID;

object_ptr<businessBotRecipients> businessBotRecipients::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessBotRecipients> res = make_tl_object<businessBotRecipients>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->existing_chats_ = (var0 & 1) != 0;
  res->new_chats_ = (var0 & 2) != 0;
  res->contacts_ = (var0 & 4) != 0;
  res->non_contacts_ = (var0 & 8) != 0;
  res->exclude_selected_ = (var0 & 32) != 0;
  if (var0 & 16) { res->users_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (var0 & 64) { res->exclude_users_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessBotRecipients::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessBotRecipients");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5)));
    if (var0 & 1) { s.store_field("existing_chats", true); }
    if (var0 & 2) { s.store_field("new_chats", true); }
    if (var0 & 4) { s.store_field("contacts", true); }
    if (var0 & 8) { s.store_field("non_contacts", true); }
    if (var0 & 32) { s.store_field("exclude_selected", true); }
    if (var0 & 16) { { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 64) { { s.store_vector_begin("exclude_users", exclude_users_.size()); for (const auto &_value : exclude_users_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

chatBannedRights::chatBannedRights()
  : flags_()
  , view_messages_()
  , send_messages_()
  , send_media_()
  , send_stickers_()
  , send_gifs_()
  , send_games_()
  , send_inline_()
  , embed_links_()
  , send_polls_()
  , change_info_()
  , invite_users_()
  , pin_messages_()
  , manage_topics_()
  , send_photos_()
  , send_videos_()
  , send_roundvideos_()
  , send_audios_()
  , send_voices_()
  , send_docs_()
  , send_plain_()
  , edit_rank_()
  , until_date_()
{}

chatBannedRights::chatBannedRights(int32 flags_, bool view_messages_, bool send_messages_, bool send_media_, bool send_stickers_, bool send_gifs_, bool send_games_, bool send_inline_, bool embed_links_, bool send_polls_, bool change_info_, bool invite_users_, bool pin_messages_, bool manage_topics_, bool send_photos_, bool send_videos_, bool send_roundvideos_, bool send_audios_, bool send_voices_, bool send_docs_, bool send_plain_, bool edit_rank_, int32 until_date_)
  : flags_(flags_)
  , view_messages_(view_messages_)
  , send_messages_(send_messages_)
  , send_media_(send_media_)
  , send_stickers_(send_stickers_)
  , send_gifs_(send_gifs_)
  , send_games_(send_games_)
  , send_inline_(send_inline_)
  , embed_links_(embed_links_)
  , send_polls_(send_polls_)
  , change_info_(change_info_)
  , invite_users_(invite_users_)
  , pin_messages_(pin_messages_)
  , manage_topics_(manage_topics_)
  , send_photos_(send_photos_)
  , send_videos_(send_videos_)
  , send_roundvideos_(send_roundvideos_)
  , send_audios_(send_audios_)
  , send_voices_(send_voices_)
  , send_docs_(send_docs_)
  , send_plain_(send_plain_)
  , edit_rank_(edit_rank_)
  , until_date_(until_date_)
{}

const std::int32_t chatBannedRights::ID;

object_ptr<chatBannedRights> chatBannedRights::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatBannedRights> res = make_tl_object<chatBannedRights>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->view_messages_ = (var0 & 1) != 0;
  res->send_messages_ = (var0 & 2) != 0;
  res->send_media_ = (var0 & 4) != 0;
  res->send_stickers_ = (var0 & 8) != 0;
  res->send_gifs_ = (var0 & 16) != 0;
  res->send_games_ = (var0 & 32) != 0;
  res->send_inline_ = (var0 & 64) != 0;
  res->embed_links_ = (var0 & 128) != 0;
  res->send_polls_ = (var0 & 256) != 0;
  res->change_info_ = (var0 & 1024) != 0;
  res->invite_users_ = (var0 & 32768) != 0;
  res->pin_messages_ = (var0 & 131072) != 0;
  res->manage_topics_ = (var0 & 262144) != 0;
  res->send_photos_ = (var0 & 524288) != 0;
  res->send_videos_ = (var0 & 1048576) != 0;
  res->send_roundvideos_ = (var0 & 2097152) != 0;
  res->send_audios_ = (var0 & 4194304) != 0;
  res->send_voices_ = (var0 & 8388608) != 0;
  res->send_docs_ = (var0 & 16777216) != 0;
  res->send_plain_ = (var0 & 33554432) != 0;
  res->edit_rank_ = (var0 & 67108864) != 0;
  res->until_date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void chatBannedRights::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (view_messages_ << 0) | (send_messages_ << 1) | (send_media_ << 2) | (send_stickers_ << 3) | (send_gifs_ << 4) | (send_games_ << 5) | (send_inline_ << 6) | (embed_links_ << 7) | (send_polls_ << 8) | (change_info_ << 10) | (invite_users_ << 15) | (pin_messages_ << 17) | (manage_topics_ << 18) | (send_photos_ << 19) | (send_videos_ << 20) | (send_roundvideos_ << 21) | (send_audios_ << 22) | (send_voices_ << 23) | (send_docs_ << 24) | (send_plain_ << 25) | (edit_rank_ << 26)), s);
  TlStoreBinary::store(until_date_, s);
}

void chatBannedRights::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (view_messages_ << 0) | (send_messages_ << 1) | (send_media_ << 2) | (send_stickers_ << 3) | (send_gifs_ << 4) | (send_games_ << 5) | (send_inline_ << 6) | (embed_links_ << 7) | (send_polls_ << 8) | (change_info_ << 10) | (invite_users_ << 15) | (pin_messages_ << 17) | (manage_topics_ << 18) | (send_photos_ << 19) | (send_videos_ << 20) | (send_roundvideos_ << 21) | (send_audios_ << 22) | (send_voices_ << 23) | (send_docs_ << 24) | (send_plain_ << 25) | (edit_rank_ << 26)), s);
  TlStoreBinary::store(until_date_, s);
}

void chatBannedRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatBannedRights");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (view_messages_ << 0) | (send_messages_ << 1) | (send_media_ << 2) | (send_stickers_ << 3) | (send_gifs_ << 4) | (send_games_ << 5) | (send_inline_ << 6) | (embed_links_ << 7) | (send_polls_ << 8) | (change_info_ << 10) | (invite_users_ << 15) | (pin_messages_ << 17) | (manage_topics_ << 18) | (send_photos_ << 19) | (send_videos_ << 20) | (send_roundvideos_ << 21) | (send_audios_ << 22) | (send_voices_ << 23) | (send_docs_ << 24) | (send_plain_ << 25) | (edit_rank_ << 26)));
    if (var0 & 1) { s.store_field("view_messages", true); }
    if (var0 & 2) { s.store_field("send_messages", true); }
    if (var0 & 4) { s.store_field("send_media", true); }
    if (var0 & 8) { s.store_field("send_stickers", true); }
    if (var0 & 16) { s.store_field("send_gifs", true); }
    if (var0 & 32) { s.store_field("send_games", true); }
    if (var0 & 64) { s.store_field("send_inline", true); }
    if (var0 & 128) { s.store_field("embed_links", true); }
    if (var0 & 256) { s.store_field("send_polls", true); }
    if (var0 & 1024) { s.store_field("change_info", true); }
    if (var0 & 32768) { s.store_field("invite_users", true); }
    if (var0 & 131072) { s.store_field("pin_messages", true); }
    if (var0 & 262144) { s.store_field("manage_topics", true); }
    if (var0 & 524288) { s.store_field("send_photos", true); }
    if (var0 & 1048576) { s.store_field("send_videos", true); }
    if (var0 & 2097152) { s.store_field("send_roundvideos", true); }
    if (var0 & 4194304) { s.store_field("send_audios", true); }
    if (var0 & 8388608) { s.store_field("send_voices", true); }
    if (var0 & 16777216) { s.store_field("send_docs", true); }
    if (var0 & 33554432) { s.store_field("send_plain", true); }
    if (var0 & 67108864) { s.store_field("edit_rank", true); }
    s.store_field("until_date", until_date_);
    s.store_class_end();
  }
}

const std::int32_t contactStatus::ID;

object_ptr<contactStatus> contactStatus::fetch(TlBufferParser &p) {
  return make_tl_object<contactStatus>(p);
}

contactStatus::contactStatus(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , status_(TlFetchObject<UserStatus>::parse(p))
{}

void contactStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contactStatus");
    s.store_field("user_id", user_id_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

object_ptr<Dialog> Dialog::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case dialog::ID:
      return dialog::fetch(p);
    case dialogFolder::ID:
      return dialogFolder::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

dialog::dialog()
  : flags_()
  , pinned_()
  , unread_mark_()
  , view_forum_as_messages_()
  , peer_()
  , top_message_()
  , read_inbox_max_id_()
  , read_outbox_max_id_()
  , unread_count_()
  , unread_mentions_count_()
  , unread_reactions_count_()
  , unread_poll_votes_count_()
  , notify_settings_()
  , pts_()
  , draft_()
  , folder_id_()
  , ttl_period_()
{}

const std::int32_t dialog::ID;

object_ptr<Dialog> dialog::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<dialog> res = make_tl_object<dialog>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 4) != 0;
  res->unread_mark_ = (var0 & 8) != 0;
  res->view_forum_as_messages_ = (var0 & 64) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->top_message_ = TlFetchInt::parse(p);
  res->read_inbox_max_id_ = TlFetchInt::parse(p);
  res->read_outbox_max_id_ = TlFetchInt::parse(p);
  res->unread_count_ = TlFetchInt::parse(p);
  res->unread_mentions_count_ = TlFetchInt::parse(p);
  res->unread_reactions_count_ = TlFetchInt::parse(p);
  res->unread_poll_votes_count_ = TlFetchInt::parse(p);
  res->notify_settings_ = TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
  if (var0 & 1) { res->pts_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->draft_ = TlFetchObject<DraftMessage>::parse(p); }
  if (var0 & 16) { res->folder_id_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void dialog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialog");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 2) | (unread_mark_ << 3) | (view_forum_as_messages_ << 6)));
    if (var0 & 4) { s.store_field("pinned", true); }
    if (var0 & 8) { s.store_field("unread_mark", true); }
    if (var0 & 64) { s.store_field("view_forum_as_messages", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_message", top_message_);
    s.store_field("read_inbox_max_id", read_inbox_max_id_);
    s.store_field("read_outbox_max_id", read_outbox_max_id_);
    s.store_field("unread_count", unread_count_);
    s.store_field("unread_mentions_count", unread_mentions_count_);
    s.store_field("unread_reactions_count", unread_reactions_count_);
    s.store_field("unread_poll_votes_count", unread_poll_votes_count_);
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    if (var0 & 1) { s.store_field("pts", pts_); }
    if (var0 & 2) { s.store_object_field("draft", static_cast<const BaseObject *>(draft_.get())); }
    if (var0 & 16) { s.store_field("folder_id", folder_id_); }
    if (var0 & 32) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

dialogFolder::dialogFolder()
  : flags_()
  , pinned_()
  , folder_()
  , peer_()
  , top_message_()
  , unread_muted_peers_count_()
  , unread_unmuted_peers_count_()
  , unread_muted_messages_count_()
  , unread_unmuted_messages_count_()
{}

const std::int32_t dialogFolder::ID;

object_ptr<Dialog> dialogFolder::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<dialogFolder> res = make_tl_object<dialogFolder>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 4) != 0;
  res->folder_ = TlFetchBoxed<TlFetchObject<folder>, -11252123>::parse(p);
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->top_message_ = TlFetchInt::parse(p);
  res->unread_muted_peers_count_ = TlFetchInt::parse(p);
  res->unread_unmuted_peers_count_ = TlFetchInt::parse(p);
  res->unread_muted_messages_count_ = TlFetchInt::parse(p);
  res->unread_unmuted_messages_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void dialogFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogFolder");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 2)));
    if (var0 & 4) { s.store_field("pinned", true); }
    s.store_object_field("folder", static_cast<const BaseObject *>(folder_.get()));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_message", top_message_);
    s.store_field("unread_muted_peers_count", unread_muted_peers_count_);
    s.store_field("unread_unmuted_peers_count", unread_unmuted_peers_count_);
    s.store_field("unread_muted_messages_count", unread_muted_messages_count_);
    s.store_field("unread_unmuted_messages_count", unread_unmuted_messages_count_);
    s.store_class_end();
  }
}

inlineBotSwitchPM::inlineBotSwitchPM(string const &text_, string const &start_param_)
  : text_(text_)
  , start_param_(start_param_)
{}

const std::int32_t inlineBotSwitchPM::ID;

object_ptr<inlineBotSwitchPM> inlineBotSwitchPM::fetch(TlBufferParser &p) {
  return make_tl_object<inlineBotSwitchPM>(p);
}

inlineBotSwitchPM::inlineBotSwitchPM(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , start_param_(TlFetchString<string>::parse(p))
{}

void inlineBotSwitchPM::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreString::store(start_param_, s);
}

void inlineBotSwitchPM::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreString::store(start_param_, s);
}

void inlineBotSwitchPM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineBotSwitchPM");
    s.store_field("text", text_);
    s.store_field("start_param", start_param_);
    s.store_class_end();
  }
}

object_ptr<InputGame> InputGame::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputGameID::ID:
      return inputGameID::fetch(p);
    case inputGameShortName::ID:
      return inputGameShortName::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputGameID::inputGameID(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputGameID::ID;

object_ptr<InputGame> inputGameID::fetch(TlBufferParser &p) {
  return make_tl_object<inputGameID>(p);
}

inputGameID::inputGameID(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputGameID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputGameID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputGameID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGameID");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputGameShortName::inputGameShortName(object_ptr<InputUser> &&bot_id_, string const &short_name_)
  : bot_id_(std::move(bot_id_))
  , short_name_(short_name_)
{}

const std::int32_t inputGameShortName::ID;

object_ptr<InputGame> inputGameShortName::fetch(TlBufferParser &p) {
  return make_tl_object<inputGameShortName>(p);
}

inputGameShortName::inputGameShortName(TlBufferParser &p)
  : bot_id_(TlFetchObject<InputUser>::parse(p))
  , short_name_(TlFetchString<string>::parse(p))
{}

void inputGameShortName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_id_, s);
  TlStoreString::store(short_name_, s);
}

void inputGameShortName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_id_, s);
  TlStoreString::store(short_name_, s);
}

void inputGameShortName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGameShortName");
    s.store_object_field("bot_id", static_cast<const BaseObject *>(bot_id_.get()));
    s.store_field("short_name", short_name_);
    s.store_class_end();
  }
}

inputPasskeyCredentialPublicKey::inputPasskeyCredentialPublicKey(string const &id_, string const &raw_id_, object_ptr<InputPasskeyResponse> &&response_)
  : id_(id_)
  , raw_id_(raw_id_)
  , response_(std::move(response_))
{}

const std::int32_t inputPasskeyCredentialPublicKey::ID;

void inputPasskeyCredentialPublicKey::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(raw_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(response_, s);
}

void inputPasskeyCredentialPublicKey::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(raw_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(response_, s);
}

void inputPasskeyCredentialPublicKey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPasskeyCredentialPublicKey");
    s.store_field("id", id_);
    s.store_field("raw_id", raw_id_);
    s.store_object_field("response", static_cast<const BaseObject *>(response_.get()));
    s.store_class_end();
  }
}

inputPasskeyCredentialFirebasePNV::inputPasskeyCredentialFirebasePNV(string const &pnv_token_)
  : pnv_token_(pnv_token_)
{}

const std::int32_t inputPasskeyCredentialFirebasePNV::ID;

void inputPasskeyCredentialFirebasePNV::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(pnv_token_, s);
}

void inputPasskeyCredentialFirebasePNV::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(pnv_token_, s);
}

void inputPasskeyCredentialFirebasePNV::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPasskeyCredentialFirebasePNV");
    s.store_field("pnv_token", pnv_token_);
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueAllowContacts::ID;

void inputPrivacyValueAllowContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowContacts");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueAllowAll::ID;

void inputPrivacyValueAllowAll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowAll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowAll");
    s.store_class_end();
  }
}

inputPrivacyValueAllowUsers::inputPrivacyValueAllowUsers(array<object_ptr<InputUser>> &&users_)
  : users_(std::move(users_))
{}

const std::int32_t inputPrivacyValueAllowUsers::ID;

void inputPrivacyValueAllowUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void inputPrivacyValueAllowUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void inputPrivacyValueAllowUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowUsers");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueDisallowContacts::ID;

void inputPrivacyValueDisallowContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueDisallowContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueDisallowContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueDisallowContacts");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueDisallowAll::ID;

void inputPrivacyValueDisallowAll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueDisallowAll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueDisallowAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueDisallowAll");
    s.store_class_end();
  }
}

inputPrivacyValueDisallowUsers::inputPrivacyValueDisallowUsers(array<object_ptr<InputUser>> &&users_)
  : users_(std::move(users_))
{}

const std::int32_t inputPrivacyValueDisallowUsers::ID;

void inputPrivacyValueDisallowUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void inputPrivacyValueDisallowUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void inputPrivacyValueDisallowUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueDisallowUsers");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPrivacyValueAllowChatParticipants::inputPrivacyValueAllowChatParticipants(array<int64> &&chats_)
  : chats_(std::move(chats_))
{}

const std::int32_t inputPrivacyValueAllowChatParticipants::ID;

void inputPrivacyValueAllowChatParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void inputPrivacyValueAllowChatParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void inputPrivacyValueAllowChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowChatParticipants");
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputPrivacyValueDisallowChatParticipants::inputPrivacyValueDisallowChatParticipants(array<int64> &&chats_)
  : chats_(std::move(chats_))
{}

const std::int32_t inputPrivacyValueDisallowChatParticipants::ID;

void inputPrivacyValueDisallowChatParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void inputPrivacyValueDisallowChatParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void inputPrivacyValueDisallowChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueDisallowChatParticipants");
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueAllowCloseFriends::ID;

void inputPrivacyValueAllowCloseFriends::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowCloseFriends::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowCloseFriends::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowCloseFriends");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueAllowPremium::ID;

void inputPrivacyValueAllowPremium::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowPremium::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowPremium");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueAllowBots::ID;

void inputPrivacyValueAllowBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueAllowBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueAllowBots");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyValueDisallowBots::ID;

void inputPrivacyValueDisallowBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueDisallowBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyValueDisallowBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyValueDisallowBots");
    s.store_class_end();
  }
}

inputStickerSetItem::inputStickerSetItem(int32 flags_, object_ptr<InputDocument> &&document_, string const &emoji_, object_ptr<maskCoords> &&mask_coords_, string const &keywords_)
  : flags_(flags_)
  , document_(std::move(document_))
  , emoji_(emoji_)
  , mask_coords_(std::move(mask_coords_))
  , keywords_(keywords_)
{}

const std::int32_t inputStickerSetItem::ID;

void inputStickerSetItem::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreString::store(emoji_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1361650766>::store(mask_coords_, s); }
  if (var0 & 2) { TlStoreString::store(keywords_, s); }
}

void inputStickerSetItem::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreString::store(emoji_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1361650766>::store(mask_coords_, s); }
  if (var0 & 2) { TlStoreString::store(keywords_, s); }
}

void inputStickerSetItem::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetItem");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_field("emoji", emoji_);
    if (var0 & 1) { s.store_object_field("mask_coords", static_cast<const BaseObject *>(mask_coords_.get())); }
    if (var0 & 2) { s.store_field("keywords", keywords_); }
    s.store_class_end();
  }
}

inputStickeredMediaPhoto::inputStickeredMediaPhoto(object_ptr<InputPhoto> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t inputStickeredMediaPhoto::ID;

void inputStickeredMediaPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputStickeredMediaPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputStickeredMediaPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickeredMediaPhoto");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

inputStickeredMediaDocument::inputStickeredMediaDocument(object_ptr<InputDocument> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t inputStickeredMediaDocument::ID;

void inputStickeredMediaDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputStickeredMediaDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputStickeredMediaDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickeredMediaDocument");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

object_ptr<IpPort> IpPort::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case ipPort::ID:
      return ipPort::fetch(p);
    case ipPortSecret::ID:
      return ipPortSecret::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t ipPort::ID;

object_ptr<IpPort> ipPort::fetch(TlBufferParser &p) {
  return make_tl_object<ipPort>(p);
}

ipPort::ipPort(TlBufferParser &p)
  : ipv4_(TlFetchInt::parse(p))
  , port_(TlFetchInt::parse(p))
{}

void ipPort::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ipPort");
    s.store_field("ipv4", ipv4_);
    s.store_field("port", port_);
    s.store_class_end();
  }
}

const std::int32_t ipPortSecret::ID;

object_ptr<IpPort> ipPortSecret::fetch(TlBufferParser &p) {
  return make_tl_object<ipPortSecret>(p);
}

ipPortSecret::ipPortSecret(TlBufferParser &p)
  : ipv4_(TlFetchInt::parse(p))
  , port_(TlFetchInt::parse(p))
  , secret_(TlFetchBytes<bytes>::parse(p))
{}

void ipPortSecret::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "ipPortSecret");
    s.store_field("ipv4", ipv4_);
    s.store_field("port", port_);
    s.store_bytes_field("secret", secret_);
    s.store_class_end();
  }
}

maskCoords::maskCoords(int32 n_, double x_, double y_, double zoom_)
  : n_(n_)
  , x_(x_)
  , y_(y_)
  , zoom_(zoom_)
{}

const std::int32_t maskCoords::ID;

object_ptr<maskCoords> maskCoords::fetch(TlBufferParser &p) {
  return make_tl_object<maskCoords>(p);
}

maskCoords::maskCoords(TlBufferParser &p)
  : n_(TlFetchInt::parse(p))
  , x_(TlFetchDouble::parse(p))
  , y_(TlFetchDouble::parse(p))
  , zoom_(TlFetchDouble::parse(p))
{}

void maskCoords::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(n_, s);
  TlStoreBinary::store(x_, s);
  TlStoreBinary::store(y_, s);
  TlStoreBinary::store(zoom_, s);
}

void maskCoords::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(n_, s);
  TlStoreBinary::store(x_, s);
  TlStoreBinary::store(y_, s);
  TlStoreBinary::store(zoom_, s);
}

void maskCoords::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "maskCoords");
    s.store_field("n", n_);
    s.store_field("x", x_);
    s.store_field("y", y_);
    s.store_field("zoom", zoom_);
    s.store_class_end();
  }
}

object_ptr<MessageAction> MessageAction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messageActionEmpty::ID:
      return messageActionEmpty::fetch(p);
    case messageActionChatCreate::ID:
      return messageActionChatCreate::fetch(p);
    case messageActionChatEditTitle::ID:
      return messageActionChatEditTitle::fetch(p);
    case messageActionChatEditPhoto::ID:
      return messageActionChatEditPhoto::fetch(p);
    case messageActionChatDeletePhoto::ID:
      return messageActionChatDeletePhoto::fetch(p);
    case messageActionChatAddUser::ID:
      return messageActionChatAddUser::fetch(p);
    case messageActionChatDeleteUser::ID:
      return messageActionChatDeleteUser::fetch(p);
    case messageActionChatJoinedByLink::ID:
      return messageActionChatJoinedByLink::fetch(p);
    case messageActionChannelCreate::ID:
      return messageActionChannelCreate::fetch(p);
    case messageActionChatMigrateTo::ID:
      return messageActionChatMigrateTo::fetch(p);
    case messageActionChannelMigrateFrom::ID:
      return messageActionChannelMigrateFrom::fetch(p);
    case messageActionPinMessage::ID:
      return messageActionPinMessage::fetch(p);
    case messageActionHistoryClear::ID:
      return messageActionHistoryClear::fetch(p);
    case messageActionGameScore::ID:
      return messageActionGameScore::fetch(p);
    case messageActionPaymentSentMe::ID:
      return messageActionPaymentSentMe::fetch(p);
    case messageActionPaymentSent::ID:
      return messageActionPaymentSent::fetch(p);
    case messageActionPhoneCall::ID:
      return messageActionPhoneCall::fetch(p);
    case messageActionScreenshotTaken::ID:
      return messageActionScreenshotTaken::fetch(p);
    case messageActionCustomAction::ID:
      return messageActionCustomAction::fetch(p);
    case messageActionBotAllowed::ID:
      return messageActionBotAllowed::fetch(p);
    case messageActionSecureValuesSentMe::ID:
      return messageActionSecureValuesSentMe::fetch(p);
    case messageActionSecureValuesSent::ID:
      return messageActionSecureValuesSent::fetch(p);
    case messageActionContactSignUp::ID:
      return messageActionContactSignUp::fetch(p);
    case messageActionGeoProximityReached::ID:
      return messageActionGeoProximityReached::fetch(p);
    case messageActionGroupCall::ID:
      return messageActionGroupCall::fetch(p);
    case messageActionInviteToGroupCall::ID:
      return messageActionInviteToGroupCall::fetch(p);
    case messageActionSetMessagesTTL::ID:
      return messageActionSetMessagesTTL::fetch(p);
    case messageActionGroupCallScheduled::ID:
      return messageActionGroupCallScheduled::fetch(p);
    case messageActionSetChatTheme::ID:
      return messageActionSetChatTheme::fetch(p);
    case messageActionChatJoinedByRequest::ID:
      return messageActionChatJoinedByRequest::fetch(p);
    case messageActionWebViewDataSentMe::ID:
      return messageActionWebViewDataSentMe::fetch(p);
    case messageActionWebViewDataSent::ID:
      return messageActionWebViewDataSent::fetch(p);
    case messageActionGiftPremium::ID:
      return messageActionGiftPremium::fetch(p);
    case messageActionTopicCreate::ID:
      return messageActionTopicCreate::fetch(p);
    case messageActionTopicEdit::ID:
      return messageActionTopicEdit::fetch(p);
    case messageActionSuggestProfilePhoto::ID:
      return messageActionSuggestProfilePhoto::fetch(p);
    case messageActionRequestedPeer::ID:
      return messageActionRequestedPeer::fetch(p);
    case messageActionSetChatWallPaper::ID:
      return messageActionSetChatWallPaper::fetch(p);
    case messageActionGiftCode::ID:
      return messageActionGiftCode::fetch(p);
    case messageActionGiveawayLaunch::ID:
      return messageActionGiveawayLaunch::fetch(p);
    case messageActionGiveawayResults::ID:
      return messageActionGiveawayResults::fetch(p);
    case messageActionBoostApply::ID:
      return messageActionBoostApply::fetch(p);
    case messageActionRequestedPeerSentMe::ID:
      return messageActionRequestedPeerSentMe::fetch(p);
    case messageActionPaymentRefunded::ID:
      return messageActionPaymentRefunded::fetch(p);
    case messageActionGiftStars::ID:
      return messageActionGiftStars::fetch(p);
    case messageActionPrizeStars::ID:
      return messageActionPrizeStars::fetch(p);
    case messageActionStarGift::ID:
      return messageActionStarGift::fetch(p);
    case messageActionStarGiftUnique::ID:
      return messageActionStarGiftUnique::fetch(p);
    case messageActionPaidMessagesRefunded::ID:
      return messageActionPaidMessagesRefunded::fetch(p);
    case messageActionPaidMessagesPrice::ID:
      return messageActionPaidMessagesPrice::fetch(p);
    case messageActionConferenceCall::ID:
      return messageActionConferenceCall::fetch(p);
    case messageActionTodoCompletions::ID:
      return messageActionTodoCompletions::fetch(p);
    case messageActionTodoAppendTasks::ID:
      return messageActionTodoAppendTasks::fetch(p);
    case messageActionSuggestedPostApproval::ID:
      return messageActionSuggestedPostApproval::fetch(p);
    case messageActionSuggestedPostSuccess::ID:
      return messageActionSuggestedPostSuccess::fetch(p);
    case messageActionSuggestedPostRefund::ID:
      return messageActionSuggestedPostRefund::fetch(p);
    case messageActionGiftTon::ID:
      return messageActionGiftTon::fetch(p);
    case messageActionSuggestBirthday::ID:
      return messageActionSuggestBirthday::fetch(p);
    case messageActionStarGiftPurchaseOffer::ID:
      return messageActionStarGiftPurchaseOffer::fetch(p);
    case messageActionStarGiftPurchaseOfferDeclined::ID:
      return messageActionStarGiftPurchaseOfferDeclined::fetch(p);
    case messageActionNewCreatorPending::ID:
      return messageActionNewCreatorPending::fetch(p);
    case messageActionChangeCreator::ID:
      return messageActionChangeCreator::fetch(p);
    case messageActionNoForwardsToggle::ID:
      return messageActionNoForwardsToggle::fetch(p);
    case messageActionNoForwardsRequest::ID:
      return messageActionNoForwardsRequest::fetch(p);
    case messageActionPollAppendAnswer::ID:
      return messageActionPollAppendAnswer::fetch(p);
    case messageActionPollDeleteAnswer::ID:
      return messageActionPollDeleteAnswer::fetch(p);
    case messageActionManagedBotCreated::ID:
      return messageActionManagedBotCreated::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messageActionEmpty::ID;

object_ptr<MessageAction> messageActionEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionEmpty>();
}

void messageActionEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionEmpty");
    s.store_class_end();
  }
}

const std::int32_t messageActionChatCreate::ID;

object_ptr<MessageAction> messageActionChatCreate::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatCreate>(p);
}

messageActionChatCreate::messageActionChatCreate(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void messageActionChatCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatCreate");
    s.store_field("title", title_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messageActionChatEditTitle::ID;

object_ptr<MessageAction> messageActionChatEditTitle::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatEditTitle>(p);
}

messageActionChatEditTitle::messageActionChatEditTitle(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
{}

void messageActionChatEditTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatEditTitle");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

const std::int32_t messageActionChatEditPhoto::ID;

object_ptr<MessageAction> messageActionChatEditPhoto::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatEditPhoto>(p);
}

messageActionChatEditPhoto::messageActionChatEditPhoto(TlBufferParser &p)
  : photo_(TlFetchObject<Photo>::parse(p))
{}

void messageActionChatEditPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatEditPhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionChatDeletePhoto::ID;

object_ptr<MessageAction> messageActionChatDeletePhoto::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatDeletePhoto>();
}

void messageActionChatDeletePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatDeletePhoto");
    s.store_class_end();
  }
}

const std::int32_t messageActionChatAddUser::ID;

object_ptr<MessageAction> messageActionChatAddUser::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatAddUser>(p);
}

messageActionChatAddUser::messageActionChatAddUser(TlBufferParser &p)
  : users_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void messageActionChatAddUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatAddUser");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messageActionChatDeleteUser::ID;

object_ptr<MessageAction> messageActionChatDeleteUser::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatDeleteUser>(p);
}

messageActionChatDeleteUser::messageActionChatDeleteUser(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
{}

void messageActionChatDeleteUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatDeleteUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

const std::int32_t messageActionChatJoinedByLink::ID;

object_ptr<MessageAction> messageActionChatJoinedByLink::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatJoinedByLink>(p);
}

messageActionChatJoinedByLink::messageActionChatJoinedByLink(TlBufferParser &p)
  : inviter_id_(TlFetchLong::parse(p))
{}

void messageActionChatJoinedByLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatJoinedByLink");
    s.store_field("inviter_id", inviter_id_);
    s.store_class_end();
  }
}

const std::int32_t messageActionChannelCreate::ID;

object_ptr<MessageAction> messageActionChannelCreate::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChannelCreate>(p);
}

messageActionChannelCreate::messageActionChannelCreate(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
{}

void messageActionChannelCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChannelCreate");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

const std::int32_t messageActionChatMigrateTo::ID;

object_ptr<MessageAction> messageActionChatMigrateTo::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatMigrateTo>(p);
}

messageActionChatMigrateTo::messageActionChatMigrateTo(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
{}

void messageActionChatMigrateTo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatMigrateTo");
    s.store_field("channel_id", channel_id_);
    s.store_class_end();
  }
}

const std::int32_t messageActionChannelMigrateFrom::ID;

object_ptr<MessageAction> messageActionChannelMigrateFrom::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChannelMigrateFrom>(p);
}

messageActionChannelMigrateFrom::messageActionChannelMigrateFrom(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , chat_id_(TlFetchLong::parse(p))
{}

void messageActionChannelMigrateFrom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChannelMigrateFrom");
    s.store_field("title", title_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

const std::int32_t messageActionPinMessage::ID;

object_ptr<MessageAction> messageActionPinMessage::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionPinMessage>();
}

void messageActionPinMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPinMessage");
    s.store_class_end();
  }
}

const std::int32_t messageActionHistoryClear::ID;

object_ptr<MessageAction> messageActionHistoryClear::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionHistoryClear>();
}

void messageActionHistoryClear::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionHistoryClear");
    s.store_class_end();
  }
}

const std::int32_t messageActionGameScore::ID;

object_ptr<MessageAction> messageActionGameScore::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionGameScore>(p);
}

messageActionGameScore::messageActionGameScore(TlBufferParser &p)
  : game_id_(TlFetchLong::parse(p))
  , score_(TlFetchInt::parse(p))
{}

void messageActionGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGameScore");
    s.store_field("game_id", game_id_);
    s.store_field("score", score_);
    s.store_class_end();
  }
}

messageActionPaymentSentMe::messageActionPaymentSentMe()
  : flags_()
  , recurring_init_()
  , recurring_used_()
  , currency_()
  , total_amount_()
  , payload_()
  , info_()
  , shipping_option_id_()
  , charge_()
  , subscription_until_date_()
{}

const std::int32_t messageActionPaymentSentMe::ID;

object_ptr<MessageAction> messageActionPaymentSentMe::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionPaymentSentMe> res = make_tl_object<messageActionPaymentSentMe>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->recurring_init_ = (var0 & 4) != 0;
  res->recurring_used_ = (var0 & 8) != 0;
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  res->payload_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 1) { res->info_ = TlFetchBoxed<TlFetchObject<paymentRequestedInfo>, -1868808300>::parse(p); }
  if (var0 & 2) { res->shipping_option_id_ = TlFetchString<string>::parse(p); }
  res->charge_ = TlFetchBoxed<TlFetchObject<paymentCharge>, -368917890>::parse(p);
  if (var0 & 16) { res->subscription_until_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionPaymentSentMe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPaymentSentMe");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (recurring_init_ << 2) | (recurring_used_ << 3)));
    if (var0 & 4) { s.store_field("recurring_init", true); }
    if (var0 & 8) { s.store_field("recurring_used", true); }
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_bytes_field("payload", payload_);
    if (var0 & 1) { s.store_object_field("info", static_cast<const BaseObject *>(info_.get())); }
    if (var0 & 2) { s.store_field("shipping_option_id", shipping_option_id_); }
    s.store_object_field("charge", static_cast<const BaseObject *>(charge_.get()));
    if (var0 & 16) { s.store_field("subscription_until_date", subscription_until_date_); }
    s.store_class_end();
  }
}

messageActionPaymentSent::messageActionPaymentSent()
  : flags_()
  , recurring_init_()
  , recurring_used_()
  , currency_()
  , total_amount_()
  , invoice_slug_()
  , subscription_until_date_()
{}

const std::int32_t messageActionPaymentSent::ID;

object_ptr<MessageAction> messageActionPaymentSent::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionPaymentSent> res = make_tl_object<messageActionPaymentSent>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->recurring_init_ = (var0 & 4) != 0;
  res->recurring_used_ = (var0 & 8) != 0;
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->invoice_slug_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->subscription_until_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionPaymentSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPaymentSent");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (recurring_init_ << 2) | (recurring_used_ << 3)));
    if (var0 & 4) { s.store_field("recurring_init", true); }
    if (var0 & 8) { s.store_field("recurring_used", true); }
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    if (var0 & 1) { s.store_field("invoice_slug", invoice_slug_); }
    if (var0 & 16) { s.store_field("subscription_until_date", subscription_until_date_); }
    s.store_class_end();
  }
}

messageActionPhoneCall::messageActionPhoneCall()
  : flags_()
  , video_()
  , call_id_()
  , reason_()
  , duration_()
{}

const std::int32_t messageActionPhoneCall::ID;

object_ptr<MessageAction> messageActionPhoneCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionPhoneCall> res = make_tl_object<messageActionPhoneCall>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->video_ = (var0 & 4) != 0;
  res->call_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->reason_ = TlFetchObject<PhoneCallDiscardReason>::parse(p); }
  if (var0 & 2) { res->duration_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionPhoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPhoneCall");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (video_ << 2)));
    if (var0 & 4) { s.store_field("video", true); }
    s.store_field("call_id", call_id_);
    if (var0 & 1) { s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get())); }
    if (var0 & 2) { s.store_field("duration", duration_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionScreenshotTaken::ID;

object_ptr<MessageAction> messageActionScreenshotTaken::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionScreenshotTaken>();
}

void messageActionScreenshotTaken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionScreenshotTaken");
    s.store_class_end();
  }
}

const std::int32_t messageActionCustomAction::ID;

object_ptr<MessageAction> messageActionCustomAction::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionCustomAction>(p);
}

messageActionCustomAction::messageActionCustomAction(TlBufferParser &p)
  : message_(TlFetchString<string>::parse(p))
{}

void messageActionCustomAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionCustomAction");
    s.store_field("message", message_);
    s.store_class_end();
  }
}

messageActionBotAllowed::messageActionBotAllowed()
  : flags_()
  , attach_menu_()
  , from_request_()
  , domain_()
  , app_()
{}

const std::int32_t messageActionBotAllowed::ID;

object_ptr<MessageAction> messageActionBotAllowed::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionBotAllowed> res = make_tl_object<messageActionBotAllowed>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->attach_menu_ = (var0 & 2) != 0;
  res->from_request_ = (var0 & 8) != 0;
  if (var0 & 1) { res->domain_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->app_ = TlFetchObject<BotApp>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionBotAllowed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionBotAllowed");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (attach_menu_ << 1) | (from_request_ << 3)));
    if (var0 & 2) { s.store_field("attach_menu", true); }
    if (var0 & 8) { s.store_field("from_request", true); }
    if (var0 & 1) { s.store_field("domain", domain_); }
    if (var0 & 4) { s.store_object_field("app", static_cast<const BaseObject *>(app_.get())); }
    s.store_class_end();
  }
}

const std::int32_t messageActionSecureValuesSentMe::ID;

object_ptr<MessageAction> messageActionSecureValuesSentMe::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionSecureValuesSentMe>(p);
}

messageActionSecureValuesSentMe::messageActionSecureValuesSentMe(TlBufferParser &p)
  : values_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<secureValue>, 411017418>>, 481674261>::parse(p))
  , credentials_(TlFetchBoxed<TlFetchObject<secureCredentialsEncrypted>, 871426631>::parse(p))
{}

void messageActionSecureValuesSentMe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSecureValuesSentMe");
    { s.store_vector_begin("values", values_.size()); for (const auto &_value : values_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("credentials", static_cast<const BaseObject *>(credentials_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionSecureValuesSent::ID;

object_ptr<MessageAction> messageActionSecureValuesSent::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionSecureValuesSent>(p);
}

messageActionSecureValuesSent::messageActionSecureValuesSent(TlBufferParser &p)
  : types_(TlFetchBoxed<TlFetchVector<TlFetchObject<SecureValueType>>, 481674261>::parse(p))
{}

void messageActionSecureValuesSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSecureValuesSent");
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messageActionContactSignUp::ID;

object_ptr<MessageAction> messageActionContactSignUp::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionContactSignUp>();
}

void messageActionContactSignUp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionContactSignUp");
    s.store_class_end();
  }
}

const std::int32_t messageActionGeoProximityReached::ID;

object_ptr<MessageAction> messageActionGeoProximityReached::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionGeoProximityReached>(p);
}

messageActionGeoProximityReached::messageActionGeoProximityReached(TlBufferParser &p)
  : from_id_(TlFetchObject<Peer>::parse(p))
  , to_id_(TlFetchObject<Peer>::parse(p))
  , distance_(TlFetchInt::parse(p))
{}

void messageActionGeoProximityReached::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGeoProximityReached");
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    s.store_object_field("to_id", static_cast<const BaseObject *>(to_id_.get()));
    s.store_field("distance", distance_);
    s.store_class_end();
  }
}

messageActionGroupCall::messageActionGroupCall()
  : flags_()
  , call_()
  , duration_()
{}

const std::int32_t messageActionGroupCall::ID;

object_ptr<MessageAction> messageActionGroupCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGroupCall> res = make_tl_object<messageActionGroupCall>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->call_ = TlFetchObject<InputGroupCall>::parse(p);
  if (var0 & 1) { res->duration_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGroupCall");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    if (var0 & 1) { s.store_field("duration", duration_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionInviteToGroupCall::ID;

object_ptr<MessageAction> messageActionInviteToGroupCall::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionInviteToGroupCall>(p);
}

messageActionInviteToGroupCall::messageActionInviteToGroupCall(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void messageActionInviteToGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionInviteToGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageActionSetMessagesTTL::messageActionSetMessagesTTL()
  : flags_()
  , period_()
  , auto_setting_from_()
{}

const std::int32_t messageActionSetMessagesTTL::ID;

object_ptr<MessageAction> messageActionSetMessagesTTL::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionSetMessagesTTL> res = make_tl_object<messageActionSetMessagesTTL>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->period_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->auto_setting_from_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionSetMessagesTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSetMessagesTTL");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("period", period_);
    if (var0 & 1) { s.store_field("auto_setting_from", auto_setting_from_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionGroupCallScheduled::ID;

object_ptr<MessageAction> messageActionGroupCallScheduled::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionGroupCallScheduled>(p);
}

messageActionGroupCallScheduled::messageActionGroupCallScheduled(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , schedule_date_(TlFetchInt::parse(p))
{}

void messageActionGroupCallScheduled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGroupCallScheduled");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("schedule_date", schedule_date_);
    s.store_class_end();
  }
}

const std::int32_t messageActionSetChatTheme::ID;

object_ptr<MessageAction> messageActionSetChatTheme::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionSetChatTheme>(p);
}

messageActionSetChatTheme::messageActionSetChatTheme(TlBufferParser &p)
  : theme_(TlFetchObject<ChatTheme>::parse(p))
{}

void messageActionSetChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSetChatTheme");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionChatJoinedByRequest::ID;

object_ptr<MessageAction> messageActionChatJoinedByRequest::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChatJoinedByRequest>();
}

void messageActionChatJoinedByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChatJoinedByRequest");
    s.store_class_end();
  }
}

const std::int32_t messageActionWebViewDataSentMe::ID;

object_ptr<MessageAction> messageActionWebViewDataSentMe::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionWebViewDataSentMe>(p);
}

messageActionWebViewDataSentMe::messageActionWebViewDataSentMe(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , data_(TlFetchString<string>::parse(p))
{}

void messageActionWebViewDataSentMe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionWebViewDataSentMe");
    s.store_field("text", text_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

const std::int32_t messageActionWebViewDataSent::ID;

object_ptr<MessageAction> messageActionWebViewDataSent::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionWebViewDataSent>(p);
}

messageActionWebViewDataSent::messageActionWebViewDataSent(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
{}

void messageActionWebViewDataSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionWebViewDataSent");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

messageActionGiftPremium::messageActionGiftPremium()
  : flags_()
  , currency_()
  , amount_()
  , days_()
  , crypto_currency_()
  , crypto_amount_()
  , message_()
{}

const std::int32_t messageActionGiftPremium::ID;

object_ptr<MessageAction> messageActionGiftPremium::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGiftPremium> res = make_tl_object<messageActionGiftPremium>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->days_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->crypto_currency_ = TlFetchString<string>::parse(p); }
  if (var0 & 1) { res->crypto_amount_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGiftPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGiftPremium");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("days", days_);
    if (var0 & 1) { s.store_field("crypto_currency", crypto_currency_); }
    if (var0 & 1) { s.store_field("crypto_amount", crypto_amount_); }
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

messageActionTopicCreate::messageActionTopicCreate()
  : flags_()
  , title_missing_()
  , title_()
  , icon_color_()
  , icon_emoji_id_()
{}

const std::int32_t messageActionTopicCreate::ID;

object_ptr<MessageAction> messageActionTopicCreate::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionTopicCreate> res = make_tl_object<messageActionTopicCreate>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->title_missing_ = (var0 & 2) != 0;
  res->title_ = TlFetchString<string>::parse(p);
  res->icon_color_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->icon_emoji_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionTopicCreate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionTopicCreate");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (title_missing_ << 1)));
    if (var0 & 2) { s.store_field("title_missing", true); }
    s.store_field("title", title_);
    s.store_field("icon_color", icon_color_);
    if (var0 & 1) { s.store_field("icon_emoji_id", icon_emoji_id_); }
    s.store_class_end();
  }
}

messageActionTopicEdit::messageActionTopicEdit()
  : flags_()
  , title_()
  , icon_emoji_id_()
  , closed_()
  , hidden_()
{}

const std::int32_t messageActionTopicEdit::ID;

object_ptr<MessageAction> messageActionTopicEdit::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionTopicEdit> res = make_tl_object<messageActionTopicEdit>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->icon_emoji_id_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->closed_ = TlFetchBool::parse(p); }
  if (var0 & 8) { res->hidden_ = TlFetchBool::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionTopicEdit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionTopicEdit");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("icon_emoji_id", icon_emoji_id_); }
    if (var0 & 4) { s.store_field("closed", closed_); }
    if (var0 & 8) { s.store_field("hidden", hidden_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionSuggestProfilePhoto::ID;

object_ptr<MessageAction> messageActionSuggestProfilePhoto::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionSuggestProfilePhoto>(p);
}

messageActionSuggestProfilePhoto::messageActionSuggestProfilePhoto(TlBufferParser &p)
  : photo_(TlFetchObject<Photo>::parse(p))
{}

void messageActionSuggestProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSuggestProfilePhoto");
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionRequestedPeer::ID;

object_ptr<MessageAction> messageActionRequestedPeer::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionRequestedPeer>(p);
}

messageActionRequestedPeer::messageActionRequestedPeer(TlBufferParser &p)
  : button_id_(TlFetchInt::parse(p))
  , peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
{}

void messageActionRequestedPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionRequestedPeer");
    s.store_field("button_id", button_id_);
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageActionSetChatWallPaper::messageActionSetChatWallPaper()
  : flags_()
  , same_()
  , for_both_()
  , wallpaper_()
{}

const std::int32_t messageActionSetChatWallPaper::ID;

object_ptr<MessageAction> messageActionSetChatWallPaper::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionSetChatWallPaper> res = make_tl_object<messageActionSetChatWallPaper>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->same_ = (var0 & 1) != 0;
  res->for_both_ = (var0 & 2) != 0;
  res->wallpaper_ = TlFetchObject<WallPaper>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionSetChatWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSetChatWallPaper");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (same_ << 0) | (for_both_ << 1)));
    if (var0 & 1) { s.store_field("same", true); }
    if (var0 & 2) { s.store_field("for_both", true); }
    s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get()));
    s.store_class_end();
  }
}

messageActionGiftCode::messageActionGiftCode()
  : flags_()
  , via_giveaway_()
  , unclaimed_()
  , boost_peer_()
  , days_()
  , slug_()
  , currency_()
  , amount_()
  , crypto_currency_()
  , crypto_amount_()
  , message_()
{}

const std::int32_t messageActionGiftCode::ID;

object_ptr<MessageAction> messageActionGiftCode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGiftCode> res = make_tl_object<messageActionGiftCode>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->via_giveaway_ = (var0 & 1) != 0;
  res->unclaimed_ = (var0 & 32) != 0;
  if (var0 & 2) { res->boost_peer_ = TlFetchObject<Peer>::parse(p); }
  res->days_ = TlFetchInt::parse(p);
  res->slug_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->currency_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->amount_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->crypto_currency_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->crypto_amount_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGiftCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (via_giveaway_ << 0) | (unclaimed_ << 5)));
    if (var0 & 1) { s.store_field("via_giveaway", true); }
    if (var0 & 32) { s.store_field("unclaimed", true); }
    if (var0 & 2) { s.store_object_field("boost_peer", static_cast<const BaseObject *>(boost_peer_.get())); }
    s.store_field("days", days_);
    s.store_field("slug", slug_);
    if (var0 & 4) { s.store_field("currency", currency_); }
    if (var0 & 4) { s.store_field("amount", amount_); }
    if (var0 & 8) { s.store_field("crypto_currency", crypto_currency_); }
    if (var0 & 8) { s.store_field("crypto_amount", crypto_amount_); }
    if (var0 & 16) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

messageActionGiveawayLaunch::messageActionGiveawayLaunch()
  : flags_()
  , stars_()
{}

const std::int32_t messageActionGiveawayLaunch::ID;

object_ptr<MessageAction> messageActionGiveawayLaunch::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGiveawayLaunch> res = make_tl_object<messageActionGiveawayLaunch>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->stars_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGiveawayLaunch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGiveawayLaunch");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("stars", stars_); }
    s.store_class_end();
  }
}

messageActionGiveawayResults::messageActionGiveawayResults()
  : flags_()
  , stars_()
  , winners_count_()
  , unclaimed_count_()
{}

const std::int32_t messageActionGiveawayResults::ID;

object_ptr<MessageAction> messageActionGiveawayResults::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGiveawayResults> res = make_tl_object<messageActionGiveawayResults>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->stars_ = (var0 & 1) != 0;
  res->winners_count_ = TlFetchInt::parse(p);
  res->unclaimed_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGiveawayResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGiveawayResults");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (stars_ << 0)));
    if (var0 & 1) { s.store_field("stars", true); }
    s.store_field("winners_count", winners_count_);
    s.store_field("unclaimed_count", unclaimed_count_);
    s.store_class_end();
  }
}

const std::int32_t messageActionBoostApply::ID;

object_ptr<MessageAction> messageActionBoostApply::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionBoostApply>(p);
}

messageActionBoostApply::messageActionBoostApply(TlBufferParser &p)
  : boosts_(TlFetchInt::parse(p))
{}

void messageActionBoostApply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionBoostApply");
    s.store_field("boosts", boosts_);
    s.store_class_end();
  }
}

const std::int32_t messageActionRequestedPeerSentMe::ID;

object_ptr<MessageAction> messageActionRequestedPeerSentMe::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionRequestedPeerSentMe>(p);
}

messageActionRequestedPeerSentMe::messageActionRequestedPeerSentMe(TlBufferParser &p)
  : button_id_(TlFetchInt::parse(p))
  , peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<RequestedPeer>>, 481674261>::parse(p))
{}

void messageActionRequestedPeerSentMe::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionRequestedPeerSentMe");
    s.store_field("button_id", button_id_);
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageActionPaymentRefunded::messageActionPaymentRefunded()
  : flags_()
  , peer_()
  , currency_()
  , total_amount_()
  , payload_()
  , charge_()
{}

const std::int32_t messageActionPaymentRefunded::ID;

object_ptr<MessageAction> messageActionPaymentRefunded::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionPaymentRefunded> res = make_tl_object<messageActionPaymentRefunded>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->payload_ = TlFetchBytes<bytes>::parse(p); }
  res->charge_ = TlFetchBoxed<TlFetchObject<paymentCharge>, -368917890>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionPaymentRefunded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPaymentRefunded");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    if (var0 & 1) { s.store_bytes_field("payload", payload_); }
    s.store_object_field("charge", static_cast<const BaseObject *>(charge_.get()));
    s.store_class_end();
  }
}

messageActionGiftStars::messageActionGiftStars()
  : flags_()
  , currency_()
  , amount_()
  , stars_()
  , crypto_currency_()
  , crypto_amount_()
  , transaction_id_()
{}

const std::int32_t messageActionGiftStars::ID;

object_ptr<MessageAction> messageActionGiftStars::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGiftStars> res = make_tl_object<messageActionGiftStars>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->stars_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->crypto_currency_ = TlFetchString<string>::parse(p); }
  if (var0 & 1) { res->crypto_amount_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->transaction_id_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGiftStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGiftStars");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("stars", stars_);
    if (var0 & 1) { s.store_field("crypto_currency", crypto_currency_); }
    if (var0 & 1) { s.store_field("crypto_amount", crypto_amount_); }
    if (var0 & 2) { s.store_field("transaction_id", transaction_id_); }
    s.store_class_end();
  }
}

messageActionPrizeStars::messageActionPrizeStars()
  : flags_()
  , unclaimed_()
  , stars_()
  , transaction_id_()
  , boost_peer_()
  , giveaway_msg_id_()
{}

const std::int32_t messageActionPrizeStars::ID;

object_ptr<MessageAction> messageActionPrizeStars::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionPrizeStars> res = make_tl_object<messageActionPrizeStars>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->unclaimed_ = (var0 & 1) != 0;
  res->stars_ = TlFetchLong::parse(p);
  res->transaction_id_ = TlFetchString<string>::parse(p);
  res->boost_peer_ = TlFetchObject<Peer>::parse(p);
  res->giveaway_msg_id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionPrizeStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPrizeStars");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (unclaimed_ << 0)));
    if (var0 & 1) { s.store_field("unclaimed", true); }
    s.store_field("stars", stars_);
    s.store_field("transaction_id", transaction_id_);
    s.store_object_field("boost_peer", static_cast<const BaseObject *>(boost_peer_.get()));
    s.store_field("giveaway_msg_id", giveaway_msg_id_);
    s.store_class_end();
  }
}

messageActionStarGift::messageActionStarGift()
  : flags_()
  , name_hidden_()
  , saved_()
  , converted_()
  , upgraded_()
  , refunded_()
  , can_upgrade_()
  , prepaid_upgrade_()
  , upgrade_separate_()
  , auction_acquired_()
  , gift_()
  , message_()
  , convert_stars_()
  , upgrade_msg_id_()
  , upgrade_stars_()
  , from_id_()
  , peer_()
  , saved_id_()
  , prepaid_upgrade_hash_()
  , gift_msg_id_()
  , to_id_()
  , gift_num_()
{}

const std::int32_t messageActionStarGift::ID;

object_ptr<MessageAction> messageActionStarGift::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionStarGift> res = make_tl_object<messageActionStarGift>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->name_hidden_ = (var0 & 1) != 0;
  res->saved_ = (var0 & 4) != 0;
  res->converted_ = (var0 & 8) != 0;
  res->upgraded_ = (var0 & 32) != 0;
  res->refunded_ = (var0 & 512) != 0;
  res->can_upgrade_ = (var0 & 1024) != 0;
  res->prepaid_upgrade_ = (var0 & 8192) != 0;
  res->upgrade_separate_ = (var0 & 65536) != 0;
  res->auction_acquired_ = (var0 & 131072) != 0;
  res->gift_ = TlFetchObject<StarGift>::parse(p);
  if (var0 & 2) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (var0 & 16) { res->convert_stars_ = TlFetchLong::parse(p); }
  if (var0 & 32) { res->upgrade_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->upgrade_stars_ = TlFetchLong::parse(p); }
  if (var0 & 2048) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 4096) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 4096) { res->saved_id_ = TlFetchLong::parse(p); }
  if (var0 & 16384) { res->prepaid_upgrade_hash_ = TlFetchString<string>::parse(p); }
  if (var0 & 32768) { res->gift_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 262144) { res->to_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 524288) { res->gift_num_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionStarGift");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (name_hidden_ << 0) | (saved_ << 2) | (converted_ << 3) | (upgraded_ << 5) | (refunded_ << 9) | (can_upgrade_ << 10) | (prepaid_upgrade_ << 13) | (upgrade_separate_ << 16) | (auction_acquired_ << 17)));
    if (var0 & 1) { s.store_field("name_hidden", true); }
    if (var0 & 4) { s.store_field("saved", true); }
    if (var0 & 8) { s.store_field("converted", true); }
    if (var0 & 32) { s.store_field("upgraded", true); }
    if (var0 & 512) { s.store_field("refunded", true); }
    if (var0 & 1024) { s.store_field("can_upgrade", true); }
    if (var0 & 8192) { s.store_field("prepaid_upgrade", true); }
    if (var0 & 65536) { s.store_field("upgrade_separate", true); }
    if (var0 & 131072) { s.store_field("auction_acquired", true); }
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    if (var0 & 16) { s.store_field("convert_stars", convert_stars_); }
    if (var0 & 32) { s.store_field("upgrade_msg_id", upgrade_msg_id_); }
    if (var0 & 256) { s.store_field("upgrade_stars", upgrade_stars_); }
    if (var0 & 2048) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 4096) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 4096) { s.store_field("saved_id", saved_id_); }
    if (var0 & 16384) { s.store_field("prepaid_upgrade_hash", prepaid_upgrade_hash_); }
    if (var0 & 32768) { s.store_field("gift_msg_id", gift_msg_id_); }
    if (var0 & 262144) { s.store_object_field("to_id", static_cast<const BaseObject *>(to_id_.get())); }
    if (var0 & 524288) { s.store_field("gift_num", gift_num_); }
    s.store_class_end();
  }
}

messageActionStarGiftUnique::messageActionStarGiftUnique()
  : flags_()
  , upgrade_()
  , transferred_()
  , saved_()
  , refunded_()
  , prepaid_upgrade_()
  , assigned_()
  , from_offer_()
  , craft_()
  , gift_()
  , can_export_at_()
  , transfer_stars_()
  , from_id_()
  , peer_()
  , saved_id_()
  , resale_amount_()
  , can_transfer_at_()
  , can_resell_at_()
  , drop_original_details_stars_()
  , can_craft_at_()
{}

const std::int32_t messageActionStarGiftUnique::ID;

object_ptr<MessageAction> messageActionStarGiftUnique::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionStarGiftUnique> res = make_tl_object<messageActionStarGiftUnique>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->upgrade_ = (var0 & 1) != 0;
  res->transferred_ = (var0 & 2) != 0;
  res->saved_ = (var0 & 4) != 0;
  res->refunded_ = (var0 & 32) != 0;
  res->prepaid_upgrade_ = (var0 & 2048) != 0;
  res->assigned_ = (var0 & 8192) != 0;
  res->from_offer_ = (var0 & 16384) != 0;
  res->craft_ = (var0 & 65536) != 0;
  res->gift_ = TlFetchObject<StarGift>::parse(p);
  if (var0 & 8) { res->can_export_at_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->transfer_stars_ = TlFetchLong::parse(p); }
  if (var0 & 64) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 128) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 128) { res->saved_id_ = TlFetchLong::parse(p); }
  if (var0 & 256) { res->resale_amount_ = TlFetchObject<StarsAmount>::parse(p); }
  if (var0 & 512) { res->can_transfer_at_ = TlFetchInt::parse(p); }
  if (var0 & 1024) { res->can_resell_at_ = TlFetchInt::parse(p); }
  if (var0 & 4096) { res->drop_original_details_stars_ = TlFetchLong::parse(p); }
  if (var0 & 32768) { res->can_craft_at_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionStarGiftUnique::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionStarGiftUnique");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (upgrade_ << 0) | (transferred_ << 1) | (saved_ << 2) | (refunded_ << 5) | (prepaid_upgrade_ << 11) | (assigned_ << 13) | (from_offer_ << 14) | (craft_ << 16)));
    if (var0 & 1) { s.store_field("upgrade", true); }
    if (var0 & 2) { s.store_field("transferred", true); }
    if (var0 & 4) { s.store_field("saved", true); }
    if (var0 & 32) { s.store_field("refunded", true); }
    if (var0 & 2048) { s.store_field("prepaid_upgrade", true); }
    if (var0 & 8192) { s.store_field("assigned", true); }
    if (var0 & 16384) { s.store_field("from_offer", true); }
    if (var0 & 65536) { s.store_field("craft", true); }
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    if (var0 & 8) { s.store_field("can_export_at", can_export_at_); }
    if (var0 & 16) { s.store_field("transfer_stars", transfer_stars_); }
    if (var0 & 64) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 128) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 128) { s.store_field("saved_id", saved_id_); }
    if (var0 & 256) { s.store_object_field("resale_amount", static_cast<const BaseObject *>(resale_amount_.get())); }
    if (var0 & 512) { s.store_field("can_transfer_at", can_transfer_at_); }
    if (var0 & 1024) { s.store_field("can_resell_at", can_resell_at_); }
    if (var0 & 4096) { s.store_field("drop_original_details_stars", drop_original_details_stars_); }
    if (var0 & 32768) { s.store_field("can_craft_at", can_craft_at_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionPaidMessagesRefunded::ID;

object_ptr<MessageAction> messageActionPaidMessagesRefunded::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionPaidMessagesRefunded>(p);
}

messageActionPaidMessagesRefunded::messageActionPaidMessagesRefunded(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , stars_(TlFetchLong::parse(p))
{}

void messageActionPaidMessagesRefunded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPaidMessagesRefunded");
    s.store_field("count", count_);
    s.store_field("stars", stars_);
    s.store_class_end();
  }
}

messageActionPaidMessagesPrice::messageActionPaidMessagesPrice()
  : flags_()
  , broadcast_messages_allowed_()
  , stars_()
{}

const std::int32_t messageActionPaidMessagesPrice::ID;

object_ptr<MessageAction> messageActionPaidMessagesPrice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionPaidMessagesPrice> res = make_tl_object<messageActionPaidMessagesPrice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->broadcast_messages_allowed_ = (var0 & 1) != 0;
  res->stars_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionPaidMessagesPrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPaidMessagesPrice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (broadcast_messages_allowed_ << 0)));
    if (var0 & 1) { s.store_field("broadcast_messages_allowed", true); }
    s.store_field("stars", stars_);
    s.store_class_end();
  }
}

messageActionConferenceCall::messageActionConferenceCall()
  : flags_()
  , missed_()
  , active_()
  , video_()
  , call_id_()
  , duration_()
  , other_participants_()
{}

const std::int32_t messageActionConferenceCall::ID;

object_ptr<MessageAction> messageActionConferenceCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionConferenceCall> res = make_tl_object<messageActionConferenceCall>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->missed_ = (var0 & 1) != 0;
  res->active_ = (var0 & 2) != 0;
  res->video_ = (var0 & 16) != 0;
  res->call_id_ = TlFetchLong::parse(p);
  if (var0 & 4) { res->duration_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->other_participants_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionConferenceCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionConferenceCall");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (missed_ << 0) | (active_ << 1) | (video_ << 4)));
    if (var0 & 1) { s.store_field("missed", true); }
    if (var0 & 2) { s.store_field("active", true); }
    if (var0 & 16) { s.store_field("video", true); }
    s.store_field("call_id", call_id_);
    if (var0 & 4) { s.store_field("duration", duration_); }
    if (var0 & 8) { { s.store_vector_begin("other_participants", other_participants_.size()); for (const auto &_value : other_participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t messageActionTodoCompletions::ID;

object_ptr<MessageAction> messageActionTodoCompletions::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionTodoCompletions>(p);
}

messageActionTodoCompletions::messageActionTodoCompletions(TlBufferParser &p)
  : completed_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , incompleted_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void messageActionTodoCompletions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionTodoCompletions");
    { s.store_vector_begin("completed", completed_.size()); for (const auto &_value : completed_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("incompleted", incompleted_.size()); for (const auto &_value : incompleted_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messageActionTodoAppendTasks::ID;

object_ptr<MessageAction> messageActionTodoAppendTasks::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionTodoAppendTasks>(p);
}

messageActionTodoAppendTasks::messageActionTodoAppendTasks(TlBufferParser &p)
  : list_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<todoItem>, -878074577>>, 481674261>::parse(p))
{}

void messageActionTodoAppendTasks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionTodoAppendTasks");
    { s.store_vector_begin("list", list_.size()); for (const auto &_value : list_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageActionSuggestedPostApproval::messageActionSuggestedPostApproval()
  : flags_()
  , rejected_()
  , balance_too_low_()
  , reject_comment_()
  , schedule_date_()
  , price_()
{}

const std::int32_t messageActionSuggestedPostApproval::ID;

object_ptr<MessageAction> messageActionSuggestedPostApproval::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionSuggestedPostApproval> res = make_tl_object<messageActionSuggestedPostApproval>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->rejected_ = (var0 & 1) != 0;
  res->balance_too_low_ = (var0 & 2) != 0;
  if (var0 & 4) { res->reject_comment_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->schedule_date_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->price_ = TlFetchObject<StarsAmount>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionSuggestedPostApproval::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSuggestedPostApproval");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (rejected_ << 0) | (balance_too_low_ << 1)));
    if (var0 & 1) { s.store_field("rejected", true); }
    if (var0 & 2) { s.store_field("balance_too_low", true); }
    if (var0 & 4) { s.store_field("reject_comment", reject_comment_); }
    if (var0 & 8) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 16) { s.store_object_field("price", static_cast<const BaseObject *>(price_.get())); }
    s.store_class_end();
  }
}

const std::int32_t messageActionSuggestedPostSuccess::ID;

object_ptr<MessageAction> messageActionSuggestedPostSuccess::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionSuggestedPostSuccess>(p);
}

messageActionSuggestedPostSuccess::messageActionSuggestedPostSuccess(TlBufferParser &p)
  : price_(TlFetchObject<StarsAmount>::parse(p))
{}

void messageActionSuggestedPostSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSuggestedPostSuccess");
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

messageActionSuggestedPostRefund::messageActionSuggestedPostRefund()
  : flags_()
  , payer_initiated_()
{}

const std::int32_t messageActionSuggestedPostRefund::ID;

object_ptr<MessageAction> messageActionSuggestedPostRefund::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionSuggestedPostRefund> res = make_tl_object<messageActionSuggestedPostRefund>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->payer_initiated_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionSuggestedPostRefund::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSuggestedPostRefund");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (payer_initiated_ << 0)));
    if (var0 & 1) { s.store_field("payer_initiated", true); }
    s.store_class_end();
  }
}

messageActionGiftTon::messageActionGiftTon()
  : flags_()
  , currency_()
  , amount_()
  , crypto_currency_()
  , crypto_amount_()
  , transaction_id_()
{}

const std::int32_t messageActionGiftTon::ID;

object_ptr<MessageAction> messageActionGiftTon::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionGiftTon> res = make_tl_object<messageActionGiftTon>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->crypto_currency_ = TlFetchString<string>::parse(p);
  res->crypto_amount_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->transaction_id_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionGiftTon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionGiftTon");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("crypto_currency", crypto_currency_);
    s.store_field("crypto_amount", crypto_amount_);
    if (var0 & 1) { s.store_field("transaction_id", transaction_id_); }
    s.store_class_end();
  }
}

const std::int32_t messageActionSuggestBirthday::ID;

object_ptr<MessageAction> messageActionSuggestBirthday::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionSuggestBirthday>(p);
}

messageActionSuggestBirthday::messageActionSuggestBirthday(TlBufferParser &p)
  : birthday_(TlFetchBoxed<TlFetchObject<birthday>, 1821253126>::parse(p))
{}

void messageActionSuggestBirthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionSuggestBirthday");
    s.store_object_field("birthday", static_cast<const BaseObject *>(birthday_.get()));
    s.store_class_end();
  }
}

messageActionStarGiftPurchaseOffer::messageActionStarGiftPurchaseOffer()
  : flags_()
  , accepted_()
  , declined_()
  , gift_()
  , price_()
  , expires_at_()
{}

const std::int32_t messageActionStarGiftPurchaseOffer::ID;

object_ptr<MessageAction> messageActionStarGiftPurchaseOffer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionStarGiftPurchaseOffer> res = make_tl_object<messageActionStarGiftPurchaseOffer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->accepted_ = (var0 & 1) != 0;
  res->declined_ = (var0 & 2) != 0;
  res->gift_ = TlFetchObject<StarGift>::parse(p);
  res->price_ = TlFetchObject<StarsAmount>::parse(p);
  res->expires_at_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionStarGiftPurchaseOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionStarGiftPurchaseOffer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (accepted_ << 0) | (declined_ << 1)));
    if (var0 & 1) { s.store_field("accepted", true); }
    if (var0 & 2) { s.store_field("declined", true); }
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("expires_at", expires_at_);
    s.store_class_end();
  }
}

messageActionStarGiftPurchaseOfferDeclined::messageActionStarGiftPurchaseOfferDeclined()
  : flags_()
  , expired_()
  , gift_()
  , price_()
{}

const std::int32_t messageActionStarGiftPurchaseOfferDeclined::ID;

object_ptr<MessageAction> messageActionStarGiftPurchaseOfferDeclined::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionStarGiftPurchaseOfferDeclined> res = make_tl_object<messageActionStarGiftPurchaseOfferDeclined>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->expired_ = (var0 & 1) != 0;
  res->gift_ = TlFetchObject<StarGift>::parse(p);
  res->price_ = TlFetchObject<StarsAmount>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionStarGiftPurchaseOfferDeclined::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionStarGiftPurchaseOfferDeclined");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (expired_ << 0)));
    if (var0 & 1) { s.store_field("expired", true); }
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionNewCreatorPending::ID;

object_ptr<MessageAction> messageActionNewCreatorPending::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionNewCreatorPending>(p);
}

messageActionNewCreatorPending::messageActionNewCreatorPending(TlBufferParser &p)
  : new_creator_id_(TlFetchLong::parse(p))
{}

void messageActionNewCreatorPending::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionNewCreatorPending");
    s.store_field("new_creator_id", new_creator_id_);
    s.store_class_end();
  }
}

const std::int32_t messageActionChangeCreator::ID;

object_ptr<MessageAction> messageActionChangeCreator::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionChangeCreator>(p);
}

messageActionChangeCreator::messageActionChangeCreator(TlBufferParser &p)
  : new_creator_id_(TlFetchLong::parse(p))
{}

void messageActionChangeCreator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionChangeCreator");
    s.store_field("new_creator_id", new_creator_id_);
    s.store_class_end();
  }
}

const std::int32_t messageActionNoForwardsToggle::ID;

object_ptr<MessageAction> messageActionNoForwardsToggle::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionNoForwardsToggle>(p);
}

messageActionNoForwardsToggle::messageActionNoForwardsToggle(TlBufferParser &p)
  : prev_value_(TlFetchBool::parse(p))
  , new_value_(TlFetchBool::parse(p))
{}

void messageActionNoForwardsToggle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionNoForwardsToggle");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

messageActionNoForwardsRequest::messageActionNoForwardsRequest()
  : flags_()
  , expired_()
  , prev_value_()
  , new_value_()
{}

const std::int32_t messageActionNoForwardsRequest::ID;

object_ptr<MessageAction> messageActionNoForwardsRequest::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageActionNoForwardsRequest> res = make_tl_object<messageActionNoForwardsRequest>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->expired_ = (var0 & 1) != 0;
  res->prev_value_ = TlFetchBool::parse(p);
  res->new_value_ = TlFetchBool::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageActionNoForwardsRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionNoForwardsRequest");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (expired_ << 0)));
    if (var0 & 1) { s.store_field("expired", true); }
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t messageActionPollAppendAnswer::ID;

object_ptr<MessageAction> messageActionPollAppendAnswer::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionPollAppendAnswer>(p);
}

messageActionPollAppendAnswer::messageActionPollAppendAnswer(TlBufferParser &p)
  : answer_(TlFetchObject<PollAnswer>::parse(p))
{}

void messageActionPollAppendAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPollAppendAnswer");
    s.store_object_field("answer", static_cast<const BaseObject *>(answer_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionPollDeleteAnswer::ID;

object_ptr<MessageAction> messageActionPollDeleteAnswer::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionPollDeleteAnswer>(p);
}

messageActionPollDeleteAnswer::messageActionPollDeleteAnswer(TlBufferParser &p)
  : answer_(TlFetchObject<PollAnswer>::parse(p))
{}

void messageActionPollDeleteAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionPollDeleteAnswer");
    s.store_object_field("answer", static_cast<const BaseObject *>(answer_.get()));
    s.store_class_end();
  }
}

const std::int32_t messageActionManagedBotCreated::ID;

object_ptr<MessageAction> messageActionManagedBotCreated::fetch(TlBufferParser &p) {
  return make_tl_object<messageActionManagedBotCreated>(p);
}

messageActionManagedBotCreated::messageActionManagedBotCreated(TlBufferParser &p)
  : bot_id_(TlFetchLong::parse(p))
{}

void messageActionManagedBotCreated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageActionManagedBotCreated");
    s.store_field("bot_id", bot_id_);
    s.store_class_end();
  }
}

object_ptr<MessagesFilter> MessagesFilter::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputMessagesFilterEmpty::ID:
      return inputMessagesFilterEmpty::fetch(p);
    case inputMessagesFilterPhotos::ID:
      return inputMessagesFilterPhotos::fetch(p);
    case inputMessagesFilterVideo::ID:
      return inputMessagesFilterVideo::fetch(p);
    case inputMessagesFilterPhotoVideo::ID:
      return inputMessagesFilterPhotoVideo::fetch(p);
    case inputMessagesFilterDocument::ID:
      return inputMessagesFilterDocument::fetch(p);
    case inputMessagesFilterUrl::ID:
      return inputMessagesFilterUrl::fetch(p);
    case inputMessagesFilterGif::ID:
      return inputMessagesFilterGif::fetch(p);
    case inputMessagesFilterVoice::ID:
      return inputMessagesFilterVoice::fetch(p);
    case inputMessagesFilterMusic::ID:
      return inputMessagesFilterMusic::fetch(p);
    case inputMessagesFilterChatPhotos::ID:
      return inputMessagesFilterChatPhotos::fetch(p);
    case inputMessagesFilterPhoneCalls::ID:
      return inputMessagesFilterPhoneCalls::fetch(p);
    case inputMessagesFilterRoundVoice::ID:
      return inputMessagesFilterRoundVoice::fetch(p);
    case inputMessagesFilterRoundVideo::ID:
      return inputMessagesFilterRoundVideo::fetch(p);
    case inputMessagesFilterMyMentions::ID:
      return inputMessagesFilterMyMentions::fetch(p);
    case inputMessagesFilterGeo::ID:
      return inputMessagesFilterGeo::fetch(p);
    case inputMessagesFilterContacts::ID:
      return inputMessagesFilterContacts::fetch(p);
    case inputMessagesFilterPinned::ID:
      return inputMessagesFilterPinned::fetch(p);
    case inputMessagesFilterPoll::ID:
      return inputMessagesFilterPoll::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputMessagesFilterEmpty::ID;

object_ptr<MessagesFilter> inputMessagesFilterEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterEmpty>();
}

void inputMessagesFilterEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterEmpty");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterPhotos::ID;

object_ptr<MessagesFilter> inputMessagesFilterPhotos::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterPhotos>();
}

void inputMessagesFilterPhotos::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPhotos::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterPhotos");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterVideo::ID;

object_ptr<MessagesFilter> inputMessagesFilterVideo::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterVideo>();
}

void inputMessagesFilterVideo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterVideo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterVideo");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterPhotoVideo::ID;

object_ptr<MessagesFilter> inputMessagesFilterPhotoVideo::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterPhotoVideo>();
}

void inputMessagesFilterPhotoVideo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPhotoVideo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPhotoVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterPhotoVideo");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterDocument::ID;

object_ptr<MessagesFilter> inputMessagesFilterDocument::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterDocument>();
}

void inputMessagesFilterDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterDocument");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterUrl::ID;

object_ptr<MessagesFilter> inputMessagesFilterUrl::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterUrl>();
}

void inputMessagesFilterUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterUrl");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterGif::ID;

object_ptr<MessagesFilter> inputMessagesFilterGif::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterGif>();
}

void inputMessagesFilterGif::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterGif::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterGif::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterGif");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterVoice::ID;

object_ptr<MessagesFilter> inputMessagesFilterVoice::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterVoice>();
}

void inputMessagesFilterVoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterVoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterVoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterVoice");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterMusic::ID;

object_ptr<MessagesFilter> inputMessagesFilterMusic::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterMusic>();
}

void inputMessagesFilterMusic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterMusic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterMusic");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterChatPhotos::ID;

object_ptr<MessagesFilter> inputMessagesFilterChatPhotos::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterChatPhotos>();
}

void inputMessagesFilterChatPhotos::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterChatPhotos::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterChatPhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterChatPhotos");
    s.store_class_end();
  }
}

inputMessagesFilterPhoneCalls::inputMessagesFilterPhoneCalls()
  : flags_()
  , missed_()
{}

inputMessagesFilterPhoneCalls::inputMessagesFilterPhoneCalls(int32 flags_, bool missed_)
  : flags_(flags_)
  , missed_(missed_)
{}

const std::int32_t inputMessagesFilterPhoneCalls::ID;

object_ptr<MessagesFilter> inputMessagesFilterPhoneCalls::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMessagesFilterPhoneCalls> res = make_tl_object<inputMessagesFilterPhoneCalls>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->missed_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMessagesFilterPhoneCalls::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (missed_ << 0)), s);
}

void inputMessagesFilterPhoneCalls::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (missed_ << 0)), s);
}

void inputMessagesFilterPhoneCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterPhoneCalls");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (missed_ << 0)));
    if (var0 & 1) { s.store_field("missed", true); }
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterRoundVoice::ID;

object_ptr<MessagesFilter> inputMessagesFilterRoundVoice::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterRoundVoice>();
}

void inputMessagesFilterRoundVoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterRoundVoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterRoundVoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterRoundVoice");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterRoundVideo::ID;

object_ptr<MessagesFilter> inputMessagesFilterRoundVideo::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterRoundVideo>();
}

void inputMessagesFilterRoundVideo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterRoundVideo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterRoundVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterRoundVideo");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterMyMentions::ID;

object_ptr<MessagesFilter> inputMessagesFilterMyMentions::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterMyMentions>();
}

void inputMessagesFilterMyMentions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterMyMentions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterMyMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterMyMentions");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterGeo::ID;

object_ptr<MessagesFilter> inputMessagesFilterGeo::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterGeo>();
}

void inputMessagesFilterGeo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterGeo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterGeo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterGeo");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterContacts::ID;

object_ptr<MessagesFilter> inputMessagesFilterContacts::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterContacts>();
}

void inputMessagesFilterContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterContacts");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterPinned::ID;

object_ptr<MessagesFilter> inputMessagesFilterPinned::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterPinned>();
}

void inputMessagesFilterPinned::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPinned::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterPinned");
    s.store_class_end();
  }
}

const std::int32_t inputMessagesFilterPoll::ID;

object_ptr<MessagesFilter> inputMessagesFilterPoll::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessagesFilterPoll>();
}

void inputMessagesFilterPoll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPoll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagesFilterPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagesFilterPoll");
    s.store_class_end();
  }
}

const std::int32_t paymentCharge::ID;

object_ptr<paymentCharge> paymentCharge::fetch(TlBufferParser &p) {
  return make_tl_object<paymentCharge>(p);
}

paymentCharge::paymentCharge(TlBufferParser &p)
  : id_(TlFetchString<string>::parse(p))
  , provider_charge_id_(TlFetchString<string>::parse(p))
{}

void paymentCharge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentCharge");
    s.store_field("id", id_);
    s.store_field("provider_charge_id", provider_charge_id_);
    s.store_class_end();
  }
}

const std::int32_t paymentFormMethod::ID;

object_ptr<paymentFormMethod> paymentFormMethod::fetch(TlBufferParser &p) {
  return make_tl_object<paymentFormMethod>(p);
}

paymentFormMethod::paymentFormMethod(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , title_(TlFetchString<string>::parse(p))
{}

void paymentFormMethod::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentFormMethod");
    s.store_field("url", url_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

object_ptr<Photo> Photo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case photoEmpty::ID:
      return photoEmpty::fetch(p);
    case photo::ID:
      return photo::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

photoEmpty::photoEmpty(int64 id_)
  : id_(id_)
{}

const std::int32_t photoEmpty::ID;

object_ptr<Photo> photoEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<photoEmpty>(p);
}

photoEmpty::photoEmpty(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void photoEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void photoEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void photoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoEmpty");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

photo::photo()
  : flags_()
  , has_stickers_()
  , id_()
  , access_hash_()
  , file_reference_()
  , date_()
  , sizes_()
  , video_sizes_()
  , dc_id_()
{}

photo::photo(int32 flags_, bool has_stickers_, int64 id_, int64 access_hash_, bytes &&file_reference_, int32 date_, array<object_ptr<PhotoSize>> &&sizes_, array<object_ptr<VideoSize>> &&video_sizes_, int32 dc_id_)
  : flags_(flags_)
  , has_stickers_(has_stickers_)
  , id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
  , date_(date_)
  , sizes_(std::move(sizes_))
  , video_sizes_(std::move(video_sizes_))
  , dc_id_(dc_id_)
{}

const std::int32_t photo::ID;

object_ptr<Photo> photo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<photo> res = make_tl_object<photo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_stickers_ = (var0 & 1) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->file_reference_ = TlFetchBytes<bytes>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->sizes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PhotoSize>>, 481674261>::parse(p);
  if (var0 & 2) { res->video_sizes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<VideoSize>>, 481674261>::parse(p); }
  res->dc_id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void photo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_stickers_ << 0)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(sizes_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(video_sizes_, s); }
  TlStoreBinary::store(dc_id_, s);
}

void photo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_stickers_ << 0)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(sizes_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(video_sizes_, s); }
  TlStoreBinary::store(dc_id_, s);
}

void photo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_stickers_ << 0)));
    if (var0 & 1) { s.store_field("has_stickers", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_field("date", date_);
    { s.store_vector_begin("sizes", sizes_.size()); for (const auto &_value : sizes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 2) { { s.store_vector_begin("video_sizes", video_sizes_.size()); for (const auto &_value : video_sizes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("dc_id", dc_id_);
    s.store_class_end();
  }
}

object_ptr<PrivacyKey> PrivacyKey::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case privacyKeyStatusTimestamp::ID:
      return privacyKeyStatusTimestamp::fetch(p);
    case privacyKeyChatInvite::ID:
      return privacyKeyChatInvite::fetch(p);
    case privacyKeyPhoneCall::ID:
      return privacyKeyPhoneCall::fetch(p);
    case privacyKeyPhoneP2P::ID:
      return privacyKeyPhoneP2P::fetch(p);
    case privacyKeyForwards::ID:
      return privacyKeyForwards::fetch(p);
    case privacyKeyProfilePhoto::ID:
      return privacyKeyProfilePhoto::fetch(p);
    case privacyKeyPhoneNumber::ID:
      return privacyKeyPhoneNumber::fetch(p);
    case privacyKeyAddedByPhone::ID:
      return privacyKeyAddedByPhone::fetch(p);
    case privacyKeyVoiceMessages::ID:
      return privacyKeyVoiceMessages::fetch(p);
    case privacyKeyAbout::ID:
      return privacyKeyAbout::fetch(p);
    case privacyKeyBirthday::ID:
      return privacyKeyBirthday::fetch(p);
    case privacyKeyStarGiftsAutoSave::ID:
      return privacyKeyStarGiftsAutoSave::fetch(p);
    case privacyKeyNoPaidMessages::ID:
      return privacyKeyNoPaidMessages::fetch(p);
    case privacyKeySavedMusic::ID:
      return privacyKeySavedMusic::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t privacyKeyStatusTimestamp::ID;

object_ptr<PrivacyKey> privacyKeyStatusTimestamp::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyStatusTimestamp>();
}

void privacyKeyStatusTimestamp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyStatusTimestamp");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyChatInvite::ID;

object_ptr<PrivacyKey> privacyKeyChatInvite::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyChatInvite>();
}

void privacyKeyChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyChatInvite");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyPhoneCall::ID;

object_ptr<PrivacyKey> privacyKeyPhoneCall::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyPhoneCall>();
}

void privacyKeyPhoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyPhoneCall");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyPhoneP2P::ID;

object_ptr<PrivacyKey> privacyKeyPhoneP2P::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyPhoneP2P>();
}

void privacyKeyPhoneP2P::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyPhoneP2P");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyForwards::ID;

object_ptr<PrivacyKey> privacyKeyForwards::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyForwards>();
}

void privacyKeyForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyForwards");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyProfilePhoto::ID;

object_ptr<PrivacyKey> privacyKeyProfilePhoto::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyProfilePhoto>();
}

void privacyKeyProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyProfilePhoto");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyPhoneNumber::ID;

object_ptr<PrivacyKey> privacyKeyPhoneNumber::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyPhoneNumber>();
}

void privacyKeyPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyPhoneNumber");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyAddedByPhone::ID;

object_ptr<PrivacyKey> privacyKeyAddedByPhone::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyAddedByPhone>();
}

void privacyKeyAddedByPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyAddedByPhone");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyVoiceMessages::ID;

object_ptr<PrivacyKey> privacyKeyVoiceMessages::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyVoiceMessages>();
}

void privacyKeyVoiceMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyVoiceMessages");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyAbout::ID;

object_ptr<PrivacyKey> privacyKeyAbout::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyAbout>();
}

void privacyKeyAbout::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyAbout");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyBirthday::ID;

object_ptr<PrivacyKey> privacyKeyBirthday::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyBirthday>();
}

void privacyKeyBirthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyBirthday");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyStarGiftsAutoSave::ID;

object_ptr<PrivacyKey> privacyKeyStarGiftsAutoSave::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyStarGiftsAutoSave>();
}

void privacyKeyStarGiftsAutoSave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyStarGiftsAutoSave");
    s.store_class_end();
  }
}

const std::int32_t privacyKeyNoPaidMessages::ID;

object_ptr<PrivacyKey> privacyKeyNoPaidMessages::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeyNoPaidMessages>();
}

void privacyKeyNoPaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeyNoPaidMessages");
    s.store_class_end();
  }
}

const std::int32_t privacyKeySavedMusic::ID;

object_ptr<PrivacyKey> privacyKeySavedMusic::fetch(TlBufferParser &p) {
  return make_tl_object<privacyKeySavedMusic>();
}

void privacyKeySavedMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyKeySavedMusic");
    s.store_class_end();
  }
}

object_ptr<RecentMeUrl> RecentMeUrl::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case recentMeUrlUnknown::ID:
      return recentMeUrlUnknown::fetch(p);
    case recentMeUrlUser::ID:
      return recentMeUrlUser::fetch(p);
    case recentMeUrlChat::ID:
      return recentMeUrlChat::fetch(p);
    case recentMeUrlChatInvite::ID:
      return recentMeUrlChatInvite::fetch(p);
    case recentMeUrlStickerSet::ID:
      return recentMeUrlStickerSet::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t recentMeUrlUnknown::ID;

object_ptr<RecentMeUrl> recentMeUrlUnknown::fetch(TlBufferParser &p) {
  return make_tl_object<recentMeUrlUnknown>(p);
}

recentMeUrlUnknown::recentMeUrlUnknown(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void recentMeUrlUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recentMeUrlUnknown");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

const std::int32_t recentMeUrlUser::ID;

object_ptr<RecentMeUrl> recentMeUrlUser::fetch(TlBufferParser &p) {
  return make_tl_object<recentMeUrlUser>(p);
}

recentMeUrlUser::recentMeUrlUser(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , user_id_(TlFetchLong::parse(p))
{}

void recentMeUrlUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recentMeUrlUser");
    s.store_field("url", url_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

const std::int32_t recentMeUrlChat::ID;

object_ptr<RecentMeUrl> recentMeUrlChat::fetch(TlBufferParser &p) {
  return make_tl_object<recentMeUrlChat>(p);
}

recentMeUrlChat::recentMeUrlChat(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , chat_id_(TlFetchLong::parse(p))
{}

void recentMeUrlChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recentMeUrlChat");
    s.store_field("url", url_);
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

const std::int32_t recentMeUrlChatInvite::ID;

object_ptr<RecentMeUrl> recentMeUrlChatInvite::fetch(TlBufferParser &p) {
  return make_tl_object<recentMeUrlChatInvite>(p);
}

recentMeUrlChatInvite::recentMeUrlChatInvite(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , chat_invite_(TlFetchObject<ChatInvite>::parse(p))
{}

void recentMeUrlChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recentMeUrlChatInvite");
    s.store_field("url", url_);
    s.store_object_field("chat_invite", static_cast<const BaseObject *>(chat_invite_.get()));
    s.store_class_end();
  }
}

const std::int32_t recentMeUrlStickerSet::ID;

object_ptr<RecentMeUrl> recentMeUrlStickerSet::fetch(TlBufferParser &p) {
  return make_tl_object<recentMeUrlStickerSet>(p);
}

recentMeUrlStickerSet::recentMeUrlStickerSet(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , set_(TlFetchObject<StickerSetCovered>::parse(p))
{}

void recentMeUrlStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recentMeUrlStickerSet");
    s.store_field("url", url_);
    s.store_object_field("set", static_cast<const BaseObject *>(set_.get()));
    s.store_class_end();
  }
}

object_ptr<ReplyMarkup> ReplyMarkup::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case replyKeyboardHide::ID:
      return replyKeyboardHide::fetch(p);
    case replyKeyboardForceReply::ID:
      return replyKeyboardForceReply::fetch(p);
    case replyKeyboardMarkup::ID:
      return replyKeyboardMarkup::fetch(p);
    case replyInlineMarkup::ID:
      return replyInlineMarkup::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

replyKeyboardHide::replyKeyboardHide()
  : flags_()
  , selective_()
{}

replyKeyboardHide::replyKeyboardHide(int32 flags_, bool selective_)
  : flags_(flags_)
  , selective_(selective_)
{}

const std::int32_t replyKeyboardHide::ID;

object_ptr<ReplyMarkup> replyKeyboardHide::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<replyKeyboardHide> res = make_tl_object<replyKeyboardHide>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->selective_ = (var0 & 4) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void replyKeyboardHide::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (selective_ << 2)), s);
}

void replyKeyboardHide::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (selective_ << 2)), s);
}

void replyKeyboardHide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyKeyboardHide");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (selective_ << 2)));
    if (var0 & 4) { s.store_field("selective", true); }
    s.store_class_end();
  }
}

replyKeyboardForceReply::replyKeyboardForceReply()
  : flags_()
  , single_use_()
  , selective_()
  , placeholder_()
{}

replyKeyboardForceReply::replyKeyboardForceReply(int32 flags_, bool single_use_, bool selective_, string const &placeholder_)
  : flags_(flags_)
  , single_use_(single_use_)
  , selective_(selective_)
  , placeholder_(placeholder_)
{}

const std::int32_t replyKeyboardForceReply::ID;

object_ptr<ReplyMarkup> replyKeyboardForceReply::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<replyKeyboardForceReply> res = make_tl_object<replyKeyboardForceReply>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->single_use_ = (var0 & 2) != 0;
  res->selective_ = (var0 & 4) != 0;
  if (var0 & 8) { res->placeholder_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void replyKeyboardForceReply::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (single_use_ << 1) | (selective_ << 2)), s);
  if (var0 & 8) { TlStoreString::store(placeholder_, s); }
}

void replyKeyboardForceReply::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (single_use_ << 1) | (selective_ << 2)), s);
  if (var0 & 8) { TlStoreString::store(placeholder_, s); }
}

void replyKeyboardForceReply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyKeyboardForceReply");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (single_use_ << 1) | (selective_ << 2)));
    if (var0 & 2) { s.store_field("single_use", true); }
    if (var0 & 4) { s.store_field("selective", true); }
    if (var0 & 8) { s.store_field("placeholder", placeholder_); }
    s.store_class_end();
  }
}

replyKeyboardMarkup::replyKeyboardMarkup()
  : flags_()
  , resize_()
  , single_use_()
  , selective_()
  , persistent_()
  , rows_()
  , placeholder_()
{}

replyKeyboardMarkup::replyKeyboardMarkup(int32 flags_, bool resize_, bool single_use_, bool selective_, bool persistent_, array<object_ptr<keyboardButtonRow>> &&rows_, string const &placeholder_)
  : flags_(flags_)
  , resize_(resize_)
  , single_use_(single_use_)
  , selective_(selective_)
  , persistent_(persistent_)
  , rows_(std::move(rows_))
  , placeholder_(placeholder_)
{}

const std::int32_t replyKeyboardMarkup::ID;

object_ptr<ReplyMarkup> replyKeyboardMarkup::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<replyKeyboardMarkup> res = make_tl_object<replyKeyboardMarkup>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->resize_ = (var0 & 1) != 0;
  res->single_use_ = (var0 & 2) != 0;
  res->selective_ = (var0 & 4) != 0;
  res->persistent_ = (var0 & 16) != 0;
  res->rows_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<keyboardButtonRow>, 2002815875>>, 481674261>::parse(p);
  if (var0 & 8) { res->placeholder_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void replyKeyboardMarkup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (resize_ << 0) | (single_use_ << 1) | (selective_ << 2) | (persistent_ << 4)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 2002815875>>, 481674261>::store(rows_, s);
  if (var0 & 8) { TlStoreString::store(placeholder_, s); }
}

void replyKeyboardMarkup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (resize_ << 0) | (single_use_ << 1) | (selective_ << 2) | (persistent_ << 4)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 2002815875>>, 481674261>::store(rows_, s);
  if (var0 & 8) { TlStoreString::store(placeholder_, s); }
}

void replyKeyboardMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyKeyboardMarkup");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (resize_ << 0) | (single_use_ << 1) | (selective_ << 2) | (persistent_ << 4)));
    if (var0 & 1) { s.store_field("resize", true); }
    if (var0 & 2) { s.store_field("single_use", true); }
    if (var0 & 4) { s.store_field("selective", true); }
    if (var0 & 16) { s.store_field("persistent", true); }
    { s.store_vector_begin("rows", rows_.size()); for (const auto &_value : rows_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 8) { s.store_field("placeholder", placeholder_); }
    s.store_class_end();
  }
}

replyInlineMarkup::replyInlineMarkup(array<object_ptr<keyboardButtonRow>> &&rows_)
  : rows_(std::move(rows_))
{}

const std::int32_t replyInlineMarkup::ID;

object_ptr<ReplyMarkup> replyInlineMarkup::fetch(TlBufferParser &p) {
  return make_tl_object<replyInlineMarkup>(p);
}

replyInlineMarkup::replyInlineMarkup(TlBufferParser &p)
  : rows_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<keyboardButtonRow>, 2002815875>>, 481674261>::parse(p))
{}

void replyInlineMarkup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 2002815875>>, 481674261>::store(rows_, s);
}

void replyInlineMarkup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 2002815875>>, 481674261>::store(rows_, s);
}

void replyInlineMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "replyInlineMarkup");
    { s.store_vector_begin("rows", rows_.size()); for (const auto &_value : rows_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t savedPhoneContact::ID;

object_ptr<savedPhoneContact> savedPhoneContact::fetch(TlBufferParser &p) {
  return make_tl_object<savedPhoneContact>(p);
}

savedPhoneContact::savedPhoneContact(TlBufferParser &p)
  : phone_(TlFetchString<string>::parse(p))
  , first_name_(TlFetchString<string>::parse(p))
  , last_name_(TlFetchString<string>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void savedPhoneContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedPhoneContact");
    s.store_field("phone", phone_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

object_ptr<SecureFile> SecureFile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case secureFileEmpty::ID:
      return secureFileEmpty::fetch(p);
    case secureFile::ID:
      return secureFile::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t secureFileEmpty::ID;

object_ptr<SecureFile> secureFileEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<secureFileEmpty>();
}

void secureFileEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureFileEmpty");
    s.store_class_end();
  }
}

const std::int32_t secureFile::ID;

object_ptr<SecureFile> secureFile::fetch(TlBufferParser &p) {
  return make_tl_object<secureFile>(p);
}

secureFile::secureFile(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , size_(TlFetchLong::parse(p))
  , dc_id_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , file_hash_(TlFetchBytes<bytes>::parse(p))
  , secret_(TlFetchBytes<bytes>::parse(p))
{}

void secureFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureFile");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("size", size_);
    s.store_field("dc_id", dc_id_);
    s.store_field("date", date_);
    s.store_bytes_field("file_hash", file_hash_);
    s.store_bytes_field("secret", secret_);
    s.store_class_end();
  }
}

object_ptr<SecureValueType> SecureValueType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case secureValueTypePersonalDetails::ID:
      return secureValueTypePersonalDetails::fetch(p);
    case secureValueTypePassport::ID:
      return secureValueTypePassport::fetch(p);
    case secureValueTypeDriverLicense::ID:
      return secureValueTypeDriverLicense::fetch(p);
    case secureValueTypeIdentityCard::ID:
      return secureValueTypeIdentityCard::fetch(p);
    case secureValueTypeInternalPassport::ID:
      return secureValueTypeInternalPassport::fetch(p);
    case secureValueTypeAddress::ID:
      return secureValueTypeAddress::fetch(p);
    case secureValueTypeUtilityBill::ID:
      return secureValueTypeUtilityBill::fetch(p);
    case secureValueTypeBankStatement::ID:
      return secureValueTypeBankStatement::fetch(p);
    case secureValueTypeRentalAgreement::ID:
      return secureValueTypeRentalAgreement::fetch(p);
    case secureValueTypePassportRegistration::ID:
      return secureValueTypePassportRegistration::fetch(p);
    case secureValueTypeTemporaryRegistration::ID:
      return secureValueTypeTemporaryRegistration::fetch(p);
    case secureValueTypePhone::ID:
      return secureValueTypePhone::fetch(p);
    case secureValueTypeEmail::ID:
      return secureValueTypeEmail::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t secureValueTypePersonalDetails::ID;

object_ptr<SecureValueType> secureValueTypePersonalDetails::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypePersonalDetails>();
}

void secureValueTypePersonalDetails::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypePersonalDetails::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypePersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypePersonalDetails");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypePassport::ID;

object_ptr<SecureValueType> secureValueTypePassport::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypePassport>();
}

void secureValueTypePassport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypePassport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypePassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypePassport");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeDriverLicense::ID;

object_ptr<SecureValueType> secureValueTypeDriverLicense::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeDriverLicense>();
}

void secureValueTypeDriverLicense::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeDriverLicense::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeDriverLicense::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeDriverLicense");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeIdentityCard::ID;

object_ptr<SecureValueType> secureValueTypeIdentityCard::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeIdentityCard>();
}

void secureValueTypeIdentityCard::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeIdentityCard::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeIdentityCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeIdentityCard");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeInternalPassport::ID;

object_ptr<SecureValueType> secureValueTypeInternalPassport::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeInternalPassport>();
}

void secureValueTypeInternalPassport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeInternalPassport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeInternalPassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeInternalPassport");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeAddress::ID;

object_ptr<SecureValueType> secureValueTypeAddress::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeAddress>();
}

void secureValueTypeAddress::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeAddress::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeAddress");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeUtilityBill::ID;

object_ptr<SecureValueType> secureValueTypeUtilityBill::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeUtilityBill>();
}

void secureValueTypeUtilityBill::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeUtilityBill::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeUtilityBill::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeUtilityBill");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeBankStatement::ID;

object_ptr<SecureValueType> secureValueTypeBankStatement::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeBankStatement>();
}

void secureValueTypeBankStatement::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeBankStatement::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeBankStatement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeBankStatement");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeRentalAgreement::ID;

object_ptr<SecureValueType> secureValueTypeRentalAgreement::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeRentalAgreement>();
}

void secureValueTypeRentalAgreement::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeRentalAgreement::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeRentalAgreement::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeRentalAgreement");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypePassportRegistration::ID;

object_ptr<SecureValueType> secureValueTypePassportRegistration::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypePassportRegistration>();
}

void secureValueTypePassportRegistration::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypePassportRegistration::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypePassportRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypePassportRegistration");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeTemporaryRegistration::ID;

object_ptr<SecureValueType> secureValueTypeTemporaryRegistration::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeTemporaryRegistration>();
}

void secureValueTypeTemporaryRegistration::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeTemporaryRegistration::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeTemporaryRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeTemporaryRegistration");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypePhone::ID;

object_ptr<SecureValueType> secureValueTypePhone::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypePhone>();
}

void secureValueTypePhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypePhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypePhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypePhone");
    s.store_class_end();
  }
}

const std::int32_t secureValueTypeEmail::ID;

object_ptr<SecureValueType> secureValueTypeEmail::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueTypeEmail>();
}

void secureValueTypeEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void secureValueTypeEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void secureValueTypeEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueTypeEmail");
    s.store_class_end();
  }
}

const std::int32_t starGiftAttributeCounter::ID;

object_ptr<starGiftAttributeCounter> starGiftAttributeCounter::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeCounter>(p);
}

starGiftAttributeCounter::starGiftAttributeCounter(TlBufferParser &p)
  : attribute_(TlFetchObject<StarGiftAttributeId>::parse(p))
  , count_(TlFetchInt::parse(p))
{}

void starGiftAttributeCounter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeCounter");
    s.store_object_field("attribute", static_cast<const BaseObject *>(attribute_.get()));
    s.store_field("count", count_);
    s.store_class_end();
  }
}

starsRating::starsRating()
  : flags_()
  , level_()
  , current_level_stars_()
  , stars_()
  , next_level_stars_()
{}

const std::int32_t starsRating::ID;

object_ptr<starsRating> starsRating::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsRating> res = make_tl_object<starsRating>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->level_ = TlFetchInt::parse(p);
  res->current_level_stars_ = TlFetchLong::parse(p);
  res->stars_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->next_level_stars_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsRating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsRating");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("level", level_);
    s.store_field("current_level_stars", current_level_stars_);
    s.store_field("stars", stars_);
    if (var0 & 1) { s.store_field("next_level_stars", next_level_stars_); }
    s.store_class_end();
  }
}

starsSubscription::starsSubscription()
  : flags_()
  , canceled_()
  , can_refulfill_()
  , missing_balance_()
  , bot_canceled_()
  , id_()
  , peer_()
  , until_date_()
  , pricing_()
  , chat_invite_hash_()
  , title_()
  , photo_()
  , invoice_slug_()
{}

const std::int32_t starsSubscription::ID;

object_ptr<starsSubscription> starsSubscription::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsSubscription> res = make_tl_object<starsSubscription>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->canceled_ = (var0 & 1) != 0;
  res->can_refulfill_ = (var0 & 2) != 0;
  res->missing_balance_ = (var0 & 4) != 0;
  res->bot_canceled_ = (var0 & 128) != 0;
  res->id_ = TlFetchString<string>::parse(p);
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->until_date_ = TlFetchInt::parse(p);
  res->pricing_ = TlFetchBoxed<TlFetchObject<starsSubscriptionPricing>, 88173912>::parse(p);
  if (var0 & 8) { res->chat_invite_hash_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 32) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  if (var0 & 64) { res->invoice_slug_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsSubscription");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (canceled_ << 0) | (can_refulfill_ << 1) | (missing_balance_ << 2) | (bot_canceled_ << 7)));
    if (var0 & 1) { s.store_field("canceled", true); }
    if (var0 & 2) { s.store_field("can_refulfill", true); }
    if (var0 & 4) { s.store_field("missing_balance", true); }
    if (var0 & 128) { s.store_field("bot_canceled", true); }
    s.store_field("id", id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("until_date", until_date_);
    s.store_object_field("pricing", static_cast<const BaseObject *>(pricing_.get()));
    if (var0 & 8) { s.store_field("chat_invite_hash", chat_invite_hash_); }
    if (var0 & 16) { s.store_field("title", title_); }
    if (var0 & 32) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 64) { s.store_field("invoice_slug", invoice_slug_); }
    s.store_class_end();
  }
}

storiesStealthMode::storiesStealthMode()
  : flags_()
  , active_until_date_()
  , cooldown_until_date_()
{}

const std::int32_t storiesStealthMode::ID;

object_ptr<storiesStealthMode> storiesStealthMode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storiesStealthMode> res = make_tl_object<storiesStealthMode>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->active_until_date_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->cooldown_until_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void storiesStealthMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storiesStealthMode");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("active_until_date", active_until_date_); }
    if (var0 & 2) { s.store_field("cooldown_until_date", cooldown_until_date_); }
    s.store_class_end();
  }
}

object_ptr<User> User::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case userEmpty::ID:
      return userEmpty::fetch(p);
    case user::ID:
      return user::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t userEmpty::ID;

object_ptr<User> userEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<userEmpty>(p);
}

userEmpty::userEmpty(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void userEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userEmpty");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

user::user()
  : flags_()
  , self_()
  , contact_()
  , mutual_contact_()
  , deleted_()
  , bot_()
  , bot_chat_history_()
  , bot_nochats_()
  , verified_()
  , restricted_()
  , min_()
  , bot_inline_geo_()
  , support_()
  , scam_()
  , apply_min_photo_()
  , fake_()
  , bot_attach_menu_()
  , premium_()
  , attach_menu_enabled_()
  , flags2_()
  , bot_can_edit_()
  , close_friend_()
  , stories_hidden_()
  , stories_unavailable_()
  , contact_require_premium_()
  , bot_business_()
  , bot_has_main_app_()
  , bot_forum_view_()
  , bot_forum_can_manage_topics_()
  , bot_can_manage_bots_()
  , id_()
  , access_hash_()
  , first_name_()
  , last_name_()
  , username_()
  , phone_()
  , photo_()
  , status_()
  , bot_info_version_()
  , restriction_reason_()
  , bot_inline_placeholder_()
  , lang_code_()
  , emoji_status_()
  , usernames_()
  , stories_max_id_()
  , color_()
  , profile_color_()
  , bot_active_users_()
  , bot_verification_icon_()
  , send_paid_messages_stars_()
{}

user::user(int32 flags_, bool self_, bool contact_, bool mutual_contact_, bool deleted_, bool bot_, bool bot_chat_history_, bool bot_nochats_, bool verified_, bool restricted_, bool min_, bool bot_inline_geo_, bool support_, bool scam_, bool apply_min_photo_, bool fake_, bool bot_attach_menu_, bool premium_, bool attach_menu_enabled_, int32 flags2_, bool bot_can_edit_, bool close_friend_, bool stories_hidden_, bool stories_unavailable_, bool contact_require_premium_, bool bot_business_, bool bot_has_main_app_, bool bot_forum_view_, bool bot_forum_can_manage_topics_, bool bot_can_manage_bots_, int64 id_, int64 access_hash_, string const &first_name_, string const &last_name_, string const &username_, string const &phone_, object_ptr<UserProfilePhoto> &&photo_, object_ptr<UserStatus> &&status_, int32 bot_info_version_, array<object_ptr<restrictionReason>> &&restriction_reason_, string const &bot_inline_placeholder_, string const &lang_code_, object_ptr<EmojiStatus> &&emoji_status_, array<object_ptr<username>> &&usernames_, object_ptr<recentStory> &&stories_max_id_, object_ptr<PeerColor> &&color_, object_ptr<PeerColor> &&profile_color_, int32 bot_active_users_, int64 bot_verification_icon_, int64 send_paid_messages_stars_)
  : flags_(flags_)
  , self_(self_)
  , contact_(contact_)
  , mutual_contact_(mutual_contact_)
  , deleted_(deleted_)
  , bot_(bot_)
  , bot_chat_history_(bot_chat_history_)
  , bot_nochats_(bot_nochats_)
  , verified_(verified_)
  , restricted_(restricted_)
  , min_(min_)
  , bot_inline_geo_(bot_inline_geo_)
  , support_(support_)
  , scam_(scam_)
  , apply_min_photo_(apply_min_photo_)
  , fake_(fake_)
  , bot_attach_menu_(bot_attach_menu_)
  , premium_(premium_)
  , attach_menu_enabled_(attach_menu_enabled_)
  , flags2_(flags2_)
  , bot_can_edit_(bot_can_edit_)
  , close_friend_(close_friend_)
  , stories_hidden_(stories_hidden_)
  , stories_unavailable_(stories_unavailable_)
  , contact_require_premium_(contact_require_premium_)
  , bot_business_(bot_business_)
  , bot_has_main_app_(bot_has_main_app_)
  , bot_forum_view_(bot_forum_view_)
  , bot_forum_can_manage_topics_(bot_forum_can_manage_topics_)
  , bot_can_manage_bots_(bot_can_manage_bots_)
  , id_(id_)
  , access_hash_(access_hash_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , username_(username_)
  , phone_(phone_)
  , photo_(std::move(photo_))
  , status_(std::move(status_))
  , bot_info_version_(bot_info_version_)
  , restriction_reason_(std::move(restriction_reason_))
  , bot_inline_placeholder_(bot_inline_placeholder_)
  , lang_code_(lang_code_)
  , emoji_status_(std::move(emoji_status_))
  , usernames_(std::move(usernames_))
  , stories_max_id_(std::move(stories_max_id_))
  , color_(std::move(color_))
  , profile_color_(std::move(profile_color_))
  , bot_active_users_(bot_active_users_)
  , bot_verification_icon_(bot_verification_icon_)
  , send_paid_messages_stars_(send_paid_messages_stars_)
{}

const std::int32_t user::ID;

object_ptr<User> user::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<user> res = make_tl_object<user>();
  int32 var0;
  int32 var1;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->self_ = (var0 & 1024) != 0;
  res->contact_ = (var0 & 2048) != 0;
  res->mutual_contact_ = (var0 & 4096) != 0;
  res->deleted_ = (var0 & 8192) != 0;
  res->bot_ = (var0 & 16384) != 0;
  res->bot_chat_history_ = (var0 & 32768) != 0;
  res->bot_nochats_ = (var0 & 65536) != 0;
  res->verified_ = (var0 & 131072) != 0;
  res->restricted_ = (var0 & 262144) != 0;
  res->min_ = (var0 & 1048576) != 0;
  res->bot_inline_geo_ = (var0 & 2097152) != 0;
  res->support_ = (var0 & 8388608) != 0;
  res->scam_ = (var0 & 16777216) != 0;
  res->apply_min_photo_ = (var0 & 33554432) != 0;
  res->fake_ = (var0 & 67108864) != 0;
  res->bot_attach_menu_ = (var0 & 134217728) != 0;
  res->premium_ = (var0 & 268435456) != 0;
  res->attach_menu_enabled_ = (var0 & 536870912) != 0;
  if ((var1 = res->flags2_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bot_can_edit_ = (var1 & 2) != 0;
  res->close_friend_ = (var1 & 4) != 0;
  res->stories_hidden_ = (var1 & 8) != 0;
  res->stories_unavailable_ = (var1 & 16) != 0;
  res->contact_require_premium_ = (var1 & 1024) != 0;
  res->bot_business_ = (var1 & 2048) != 0;
  res->bot_has_main_app_ = (var1 & 8192) != 0;
  res->bot_forum_view_ = (var1 & 65536) != 0;
  res->bot_forum_can_manage_topics_ = (var1 & 131072) != 0;
  res->bot_can_manage_bots_ = (var1 & 262144) != 0;
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->access_hash_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->first_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->last_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->username_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->phone_ = TlFetchString<string>::parse(p); }
  if (var0 & 32) { res->photo_ = TlFetchObject<UserProfilePhoto>::parse(p); }
  if (var0 & 64) { res->status_ = TlFetchObject<UserStatus>::parse(p); }
  if (var0 & 16384) { res->bot_info_version_ = TlFetchInt::parse(p); }
  if (var0 & 262144) { res->restriction_reason_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<restrictionReason>, -797791052>>, 481674261>::parse(p); }
  if (var0 & 524288) { res->bot_inline_placeholder_ = TlFetchString<string>::parse(p); }
  if (var0 & 4194304) { res->lang_code_ = TlFetchString<string>::parse(p); }
  if (var0 & 1073741824) { res->emoji_status_ = TlFetchObject<EmojiStatus>::parse(p); }
  if (var1 & 1) { res->usernames_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<username>, -1274595769>>, 481674261>::parse(p); }
  if (var1 & 32) { res->stories_max_id_ = TlFetchBoxed<TlFetchObject<recentStory>, 1897752877>::parse(p); }
  if (var1 & 256) { res->color_ = TlFetchObject<PeerColor>::parse(p); }
  if (var1 & 512) { res->profile_color_ = TlFetchObject<PeerColor>::parse(p); }
  if (var1 & 4096) { res->bot_active_users_ = TlFetchInt::parse(p); }
  if (var1 & 16384) { res->bot_verification_icon_ = TlFetchLong::parse(p); }
  if (var1 & 32768) { res->send_paid_messages_stars_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void user::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "user");
  int32 var0;
  int32 var1;
    s.store_field("flags", (var0 = flags_ | (self_ << 10) | (contact_ << 11) | (mutual_contact_ << 12) | (deleted_ << 13) | (bot_ << 14) | (bot_chat_history_ << 15) | (bot_nochats_ << 16) | (verified_ << 17) | (restricted_ << 18) | (min_ << 20) | (bot_inline_geo_ << 21) | (support_ << 23) | (scam_ << 24) | (apply_min_photo_ << 25) | (fake_ << 26) | (bot_attach_menu_ << 27) | (premium_ << 28) | (attach_menu_enabled_ << 29)));
    if (var0 & 1024) { s.store_field("self", true); }
    if (var0 & 2048) { s.store_field("contact", true); }
    if (var0 & 4096) { s.store_field("mutual_contact", true); }
    if (var0 & 8192) { s.store_field("deleted", true); }
    if (var0 & 16384) { s.store_field("bot", true); }
    if (var0 & 32768) { s.store_field("bot_chat_history", true); }
    if (var0 & 65536) { s.store_field("bot_nochats", true); }
    if (var0 & 131072) { s.store_field("verified", true); }
    if (var0 & 262144) { s.store_field("restricted", true); }
    if (var0 & 1048576) { s.store_field("min", true); }
    if (var0 & 2097152) { s.store_field("bot_inline_geo", true); }
    if (var0 & 8388608) { s.store_field("support", true); }
    if (var0 & 16777216) { s.store_field("scam", true); }
    if (var0 & 33554432) { s.store_field("apply_min_photo", true); }
    if (var0 & 67108864) { s.store_field("fake", true); }
    if (var0 & 134217728) { s.store_field("bot_attach_menu", true); }
    if (var0 & 268435456) { s.store_field("premium", true); }
    if (var0 & 536870912) { s.store_field("attach_menu_enabled", true); }
    s.store_field("flags2", (var1 = flags2_ | (bot_can_edit_ << 1) | (close_friend_ << 2) | (stories_hidden_ << 3) | (stories_unavailable_ << 4) | (contact_require_premium_ << 10) | (bot_business_ << 11) | (bot_has_main_app_ << 13) | (bot_forum_view_ << 16) | (bot_forum_can_manage_topics_ << 17) | (bot_can_manage_bots_ << 18)));
    if (var1 & 2) { s.store_field("bot_can_edit", true); }
    if (var1 & 4) { s.store_field("close_friend", true); }
    if (var1 & 8) { s.store_field("stories_hidden", true); }
    if (var1 & 16) { s.store_field("stories_unavailable", true); }
    if (var1 & 1024) { s.store_field("contact_require_premium", true); }
    if (var1 & 2048) { s.store_field("bot_business", true); }
    if (var1 & 8192) { s.store_field("bot_has_main_app", true); }
    if (var1 & 65536) { s.store_field("bot_forum_view", true); }
    if (var1 & 131072) { s.store_field("bot_forum_can_manage_topics", true); }
    if (var1 & 262144) { s.store_field("bot_can_manage_bots", true); }
    s.store_field("id", id_);
    if (var0 & 1) { s.store_field("access_hash", access_hash_); }
    if (var0 & 2) { s.store_field("first_name", first_name_); }
    if (var0 & 4) { s.store_field("last_name", last_name_); }
    if (var0 & 8) { s.store_field("username", username_); }
    if (var0 & 16) { s.store_field("phone", phone_); }
    if (var0 & 32) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 64) { s.store_object_field("status", static_cast<const BaseObject *>(status_.get())); }
    if (var0 & 16384) { s.store_field("bot_info_version", bot_info_version_); }
    if (var0 & 262144) { { s.store_vector_begin("restriction_reason", restriction_reason_.size()); for (const auto &_value : restriction_reason_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 524288) { s.store_field("bot_inline_placeholder", bot_inline_placeholder_); }
    if (var0 & 4194304) { s.store_field("lang_code", lang_code_); }
    if (var0 & 1073741824) { s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get())); }
    if (var1 & 1) { { s.store_vector_begin("usernames", usernames_.size()); for (const auto &_value : usernames_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var1 & 32) { s.store_object_field("stories_max_id", static_cast<const BaseObject *>(stories_max_id_.get())); }
    if (var1 & 256) { s.store_object_field("color", static_cast<const BaseObject *>(color_.get())); }
    if (var1 & 512) { s.store_object_field("profile_color", static_cast<const BaseObject *>(profile_color_.get())); }
    if (var1 & 4096) { s.store_field("bot_active_users", bot_active_users_); }
    if (var1 & 16384) { s.store_field("bot_verification_icon", bot_verification_icon_); }
    if (var1 & 32768) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    s.store_class_end();
  }
}

object_ptr<UserStatus> UserStatus::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case userStatusEmpty::ID:
      return userStatusEmpty::fetch(p);
    case userStatusOnline::ID:
      return userStatusOnline::fetch(p);
    case userStatusOffline::ID:
      return userStatusOffline::fetch(p);
    case userStatusRecently::ID:
      return userStatusRecently::fetch(p);
    case userStatusLastWeek::ID:
      return userStatusLastWeek::fetch(p);
    case userStatusLastMonth::ID:
      return userStatusLastMonth::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t userStatusEmpty::ID;

object_ptr<UserStatus> userStatusEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<userStatusEmpty>();
}

void userStatusEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusEmpty");
    s.store_class_end();
  }
}

const std::int32_t userStatusOnline::ID;

object_ptr<UserStatus> userStatusOnline::fetch(TlBufferParser &p) {
  return make_tl_object<userStatusOnline>(p);
}

userStatusOnline::userStatusOnline(TlBufferParser &p)
  : expires_(TlFetchInt::parse(p))
{}

void userStatusOnline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusOnline");
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

const std::int32_t userStatusOffline::ID;

object_ptr<UserStatus> userStatusOffline::fetch(TlBufferParser &p) {
  return make_tl_object<userStatusOffline>(p);
}

userStatusOffline::userStatusOffline(TlBufferParser &p)
  : was_online_(TlFetchInt::parse(p))
{}

void userStatusOffline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusOffline");
    s.store_field("was_online", was_online_);
    s.store_class_end();
  }
}

userStatusRecently::userStatusRecently()
  : flags_()
  , by_me_()
{}

const std::int32_t userStatusRecently::ID;

object_ptr<UserStatus> userStatusRecently::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<userStatusRecently> res = make_tl_object<userStatusRecently>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->by_me_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void userStatusRecently::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusRecently");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (by_me_ << 0)));
    if (var0 & 1) { s.store_field("by_me", true); }
    s.store_class_end();
  }
}

userStatusLastWeek::userStatusLastWeek()
  : flags_()
  , by_me_()
{}

const std::int32_t userStatusLastWeek::ID;

object_ptr<UserStatus> userStatusLastWeek::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<userStatusLastWeek> res = make_tl_object<userStatusLastWeek>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->by_me_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void userStatusLastWeek::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusLastWeek");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (by_me_ << 0)));
    if (var0 & 1) { s.store_field("by_me", true); }
    s.store_class_end();
  }
}

userStatusLastMonth::userStatusLastMonth()
  : flags_()
  , by_me_()
{}

const std::int32_t userStatusLastMonth::ID;

object_ptr<UserStatus> userStatusLastMonth::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<userStatusLastMonth> res = make_tl_object<userStatusLastMonth>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->by_me_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void userStatusLastMonth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userStatusLastMonth");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (by_me_ << 0)));
    if (var0 & 1) { s.store_field("by_me", true); }
    s.store_class_end();
  }
}

const std::int32_t account_connectedBots::ID;

object_ptr<account_connectedBots> account_connectedBots::fetch(TlBufferParser &p) {
  return make_tl_object<account_connectedBots>(p);
}

account_connectedBots::account_connectedBots(TlBufferParser &p)
  : connected_bots_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<connectedBot>, -849058964>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void account_connectedBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.connectedBots");
    { s.store_vector_begin("connected_bots", connected_bots_.size()); for (const auto &_value : connected_bots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<channels_ChannelParticipants> channels_ChannelParticipants::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case channels_channelParticipants::ID:
      return channels_channelParticipants::fetch(p);
    case channels_channelParticipantsNotModified::ID:
      return channels_channelParticipantsNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t channels_channelParticipants::ID;

object_ptr<channels_ChannelParticipants> channels_channelParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<channels_channelParticipants>(p);
}

channels_channelParticipants::channels_channelParticipants(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , participants_(TlFetchBoxed<TlFetchVector<TlFetchObject<ChannelParticipant>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void channels_channelParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.channelParticipants");
    s.store_field("count", count_);
    { s.store_vector_begin("participants", participants_.size()); for (const auto &_value : participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t channels_channelParticipantsNotModified::ID;

object_ptr<channels_ChannelParticipants> channels_channelParticipantsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<channels_channelParticipantsNotModified>();
}

void channels_channelParticipantsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.channelParticipantsNotModified");
    s.store_class_end();
  }
}

object_ptr<channels_SponsoredMessageReportResult> channels_SponsoredMessageReportResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case channels_sponsoredMessageReportResultChooseOption::ID:
      return channels_sponsoredMessageReportResultChooseOption::fetch(p);
    case channels_sponsoredMessageReportResultAdsHidden::ID:
      return channels_sponsoredMessageReportResultAdsHidden::fetch(p);
    case channels_sponsoredMessageReportResultReported::ID:
      return channels_sponsoredMessageReportResultReported::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t channels_sponsoredMessageReportResultChooseOption::ID;

object_ptr<channels_SponsoredMessageReportResult> channels_sponsoredMessageReportResultChooseOption::fetch(TlBufferParser &p) {
  return make_tl_object<channels_sponsoredMessageReportResultChooseOption>(p);
}

channels_sponsoredMessageReportResultChooseOption::channels_sponsoredMessageReportResultChooseOption(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , options_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<sponsoredMessageReportOption>, 1124938064>>, 481674261>::parse(p))
{}

void channels_sponsoredMessageReportResultChooseOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.sponsoredMessageReportResultChooseOption");
    s.store_field("title", title_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t channels_sponsoredMessageReportResultAdsHidden::ID;

object_ptr<channels_SponsoredMessageReportResult> channels_sponsoredMessageReportResultAdsHidden::fetch(TlBufferParser &p) {
  return make_tl_object<channels_sponsoredMessageReportResultAdsHidden>();
}

void channels_sponsoredMessageReportResultAdsHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.sponsoredMessageReportResultAdsHidden");
    s.store_class_end();
  }
}

const std::int32_t channels_sponsoredMessageReportResultReported::ID;

object_ptr<channels_SponsoredMessageReportResult> channels_sponsoredMessageReportResultReported::fetch(TlBufferParser &p) {
  return make_tl_object<channels_sponsoredMessageReportResultReported>();
}

void channels_sponsoredMessageReportResultReported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.sponsoredMessageReportResultReported");
    s.store_class_end();
  }
}

object_ptr<contacts_TopPeers> contacts_TopPeers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case contacts_topPeersNotModified::ID:
      return contacts_topPeersNotModified::fetch(p);
    case contacts_topPeers::ID:
      return contacts_topPeers::fetch(p);
    case contacts_topPeersDisabled::ID:
      return contacts_topPeersDisabled::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t contacts_topPeersNotModified::ID;

object_ptr<contacts_TopPeers> contacts_topPeersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_topPeersNotModified>();
}

void contacts_topPeersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.topPeersNotModified");
    s.store_class_end();
  }
}

const std::int32_t contacts_topPeers::ID;

object_ptr<contacts_TopPeers> contacts_topPeers::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_topPeers>(p);
}

contacts_topPeers::contacts_topPeers(TlBufferParser &p)
  : categories_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<topPeerCategoryPeers>, -75283823>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_topPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.topPeers");
    { s.store_vector_begin("categories", categories_.size()); for (const auto &_value : categories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t contacts_topPeersDisabled::ID;

object_ptr<contacts_TopPeers> contacts_topPeersDisabled::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_topPeersDisabled>();
}

void contacts_topPeersDisabled::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.topPeersDisabled");
    s.store_class_end();
  }
}

help_countryCode::help_countryCode()
  : flags_()
  , country_code_()
  , prefixes_()
  , patterns_()
{}

const std::int32_t help_countryCode::ID;

object_ptr<help_countryCode> help_countryCode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_countryCode> res = make_tl_object<help_countryCode>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->country_code_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->prefixes_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p); }
  if (var0 & 2) { res->patterns_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void help_countryCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.countryCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("country_code", country_code_);
    if (var0 & 1) { { s.store_vector_begin("prefixes", prefixes_.size()); for (const auto &_value : prefixes_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 2) { { s.store_vector_begin("patterns", patterns_.size()); for (const auto &_value : patterns_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

object_ptr<messages_AllStickers> messages_AllStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_allStickersNotModified::ID:
      return messages_allStickersNotModified::fetch(p);
    case messages_allStickers::ID:
      return messages_allStickers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_allStickersNotModified::ID;

object_ptr<messages_AllStickers> messages_allStickersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_allStickersNotModified>();
}

void messages_allStickersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.allStickersNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_allStickers::ID;

object_ptr<messages_AllStickers> messages_allStickers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_allStickers>(p);
}

messages_allStickers::messages_allStickers(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , sets_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>>, 481674261>::parse(p))
{}

void messages_allStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.allStickers");
    s.store_field("hash", hash_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_AvailableEffects> messages_AvailableEffects::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_availableEffectsNotModified::ID:
      return messages_availableEffectsNotModified::fetch(p);
    case messages_availableEffects::ID:
      return messages_availableEffects::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_availableEffectsNotModified::ID;

object_ptr<messages_AvailableEffects> messages_availableEffectsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_availableEffectsNotModified>();
}

void messages_availableEffectsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.availableEffectsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_availableEffects::ID;

object_ptr<messages_AvailableEffects> messages_availableEffects::fetch(TlBufferParser &p) {
  return make_tl_object<messages_availableEffects>(p);
}

messages_availableEffects::messages_availableEffects(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , effects_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<availableEffect>, -1815879042>>, 481674261>::parse(p))
  , documents_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void messages_availableEffects::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.availableEffects");
    s.store_field("hash", hash_);
    { s.store_vector_begin("effects", effects_.size()); for (const auto &_value : effects_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_AvailableReactions> messages_AvailableReactions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_availableReactionsNotModified::ID:
      return messages_availableReactionsNotModified::fetch(p);
    case messages_availableReactions::ID:
      return messages_availableReactions::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_availableReactionsNotModified::ID;

object_ptr<messages_AvailableReactions> messages_availableReactionsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_availableReactionsNotModified>();
}

void messages_availableReactionsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.availableReactionsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_availableReactions::ID;

object_ptr<messages_AvailableReactions> messages_availableReactions::fetch(TlBufferParser &p) {
  return make_tl_object<messages_availableReactions>(p);
}

messages_availableReactions::messages_availableReactions(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , reactions_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<availableReaction>, -1065882623>>, 481674261>::parse(p))
{}

void messages_availableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.availableReactions");
    s.store_field("hash", hash_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_DhConfig> messages_DhConfig::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_dhConfigNotModified::ID:
      return messages_dhConfigNotModified::fetch(p);
    case messages_dhConfig::ID:
      return messages_dhConfig::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_dhConfigNotModified::ID;

object_ptr<messages_DhConfig> messages_dhConfigNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_dhConfigNotModified>(p);
}

messages_dhConfigNotModified::messages_dhConfigNotModified(TlBufferParser &p)
  : random_(TlFetchBytes<bytes>::parse(p))
{}

void messages_dhConfigNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.dhConfigNotModified");
    s.store_bytes_field("random", random_);
    s.store_class_end();
  }
}

const std::int32_t messages_dhConfig::ID;

object_ptr<messages_DhConfig> messages_dhConfig::fetch(TlBufferParser &p) {
  return make_tl_object<messages_dhConfig>(p);
}

messages_dhConfig::messages_dhConfig(TlBufferParser &p)
  : g_(TlFetchInt::parse(p))
  , p_(TlFetchBytes<bytes>::parse(p))
  , version_(TlFetchInt::parse(p))
  , random_(TlFetchBytes<bytes>::parse(p))
{}

void messages_dhConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.dhConfig");
    s.store_field("g", g_);
    s.store_bytes_field("p", p_);
    s.store_field("version", version_);
    s.store_bytes_field("random", random_);
    s.store_class_end();
  }
}

messages_forumTopics::messages_forumTopics()
  : flags_()
  , order_by_create_date_()
  , count_()
  , topics_()
  , messages_()
  , chats_()
  , users_()
  , pts_()
{}

const std::int32_t messages_forumTopics::ID;

object_ptr<messages_forumTopics> messages_forumTopics::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_forumTopics> res = make_tl_object<messages_forumTopics>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->order_by_create_date_ = (var0 & 1) != 0;
  res->count_ = TlFetchInt::parse(p);
  res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_forumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.forumTopics");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (order_by_create_date_ << 0)));
    if (var0 & 1) { s.store_field("order_by_create_date", true); }
    s.store_field("count", count_);
    { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_class_end();
  }
}

const std::int32_t messages_invitedUsers::ID;

object_ptr<messages_invitedUsers> messages_invitedUsers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_invitedUsers>(p);
}

messages_invitedUsers::messages_invitedUsers(TlBufferParser &p)
  : updates_(TlFetchObject<Updates>::parse(p))
  , missing_invitees_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<missingInvitee>, 1653379620>>, 481674261>::parse(p))
{}

void messages_invitedUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.invitedUsers");
    s.store_object_field("updates", static_cast<const BaseObject *>(updates_.get()));
    { s.store_vector_begin("missing_invitees", missing_invitees_.size()); for (const auto &_value : missing_invitees_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_Messages> messages_Messages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_messages::ID:
      return messages_messages::fetch(p);
    case messages_messagesSlice::ID:
      return messages_messagesSlice::fetch(p);
    case messages_channelMessages::ID:
      return messages_channelMessages::fetch(p);
    case messages_messagesNotModified::ID:
      return messages_messagesNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_messages::ID;

object_ptr<messages_Messages> messages_messages::fetch(TlBufferParser &p) {
  return make_tl_object<messages_messages>(p);
}

messages_messages::messages_messages(TlBufferParser &p)
  : messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , topics_(TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_messages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.messages");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_messagesSlice::messages_messagesSlice()
  : flags_()
  , inexact_()
  , count_()
  , next_rate_()
  , offset_id_offset_()
  , search_flood_()
  , messages_()
  , topics_()
  , chats_()
  , users_()
{}

const std::int32_t messages_messagesSlice::ID;

object_ptr<messages_Messages> messages_messagesSlice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_messagesSlice> res = make_tl_object<messages_messagesSlice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inexact_ = (var0 & 2) != 0;
  res->count_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->next_rate_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->offset_id_offset_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->search_flood_ = TlFetchBoxed<TlFetchObject<searchPostsFlood>, 1040931690>::parse(p); }
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_messagesSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.messagesSlice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inexact_ << 1)));
    if (var0 & 2) { s.store_field("inexact", true); }
    s.store_field("count", count_);
    if (var0 & 1) { s.store_field("next_rate", next_rate_); }
    if (var0 & 4) { s.store_field("offset_id_offset", offset_id_offset_); }
    if (var0 & 8) { s.store_object_field("search_flood", static_cast<const BaseObject *>(search_flood_.get())); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_channelMessages::messages_channelMessages()
  : flags_()
  , inexact_()
  , pts_()
  , count_()
  , offset_id_offset_()
  , messages_()
  , topics_()
  , chats_()
  , users_()
{}

const std::int32_t messages_channelMessages::ID;

object_ptr<messages_Messages> messages_channelMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_channelMessages> res = make_tl_object<messages_channelMessages>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inexact_ = (var0 & 2) != 0;
  res->pts_ = TlFetchInt::parse(p);
  res->count_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->offset_id_offset_ = TlFetchInt::parse(p); }
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->topics_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ForumTopic>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_channelMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.channelMessages");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inexact_ << 1)));
    if (var0 & 2) { s.store_field("inexact", true); }
    s.store_field("pts", pts_);
    s.store_field("count", count_);
    if (var0 & 4) { s.store_field("offset_id_offset", offset_id_offset_); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_messagesNotModified::ID;

object_ptr<messages_Messages> messages_messagesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_messagesNotModified>(p);
}

messages_messagesNotModified::messages_messagesNotModified(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
{}

void messages_messagesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.messagesNotModified");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

object_ptr<payments_CheckCanSendGiftResult> payments_CheckCanSendGiftResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_checkCanSendGiftResultOk::ID:
      return payments_checkCanSendGiftResultOk::fetch(p);
    case payments_checkCanSendGiftResultFail::ID:
      return payments_checkCanSendGiftResultFail::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t payments_checkCanSendGiftResultOk::ID;

object_ptr<payments_CheckCanSendGiftResult> payments_checkCanSendGiftResultOk::fetch(TlBufferParser &p) {
  return make_tl_object<payments_checkCanSendGiftResultOk>();
}

void payments_checkCanSendGiftResultOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.checkCanSendGiftResultOk");
    s.store_class_end();
  }
}

const std::int32_t payments_checkCanSendGiftResultFail::ID;

object_ptr<payments_CheckCanSendGiftResult> payments_checkCanSendGiftResultFail::fetch(TlBufferParser &p) {
  return make_tl_object<payments_checkCanSendGiftResultFail>(p);
}

payments_checkCanSendGiftResultFail::payments_checkCanSendGiftResultFail(TlBufferParser &p)
  : reason_(TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p))
{}

void payments_checkCanSendGiftResultFail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.checkCanSendGiftResultFail");
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_class_end();
  }
}

const std::int32_t phone_groupCall::ID;

object_ptr<phone_groupCall> phone_groupCall::fetch(TlBufferParser &p) {
  return make_tl_object<phone_groupCall>(p);
}

phone_groupCall::phone_groupCall(TlBufferParser &p)
  : call_(TlFetchObject<GroupCall>::parse(p))
  , participants_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<groupCallParticipant>, 708691884>>, 481674261>::parse(p))
  , participants_next_offset_(TlFetchString<string>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void phone_groupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.groupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("participants", participants_.size()); for (const auto &_value : participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("participants_next_offset", participants_next_offset_);
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t phone_joinAsPeers::ID;

object_ptr<phone_joinAsPeers> phone_joinAsPeers::fetch(TlBufferParser &p) {
  return make_tl_object<phone_joinAsPeers>(p);
}

phone_joinAsPeers::phone_joinAsPeers(TlBufferParser &p)
  : peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void phone_joinAsPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.joinAsPeers");
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stats_messageStats::ID;

object_ptr<stats_messageStats> stats_messageStats::fetch(TlBufferParser &p) {
  return make_tl_object<stats_messageStats>(p);
}

stats_messageStats::stats_messageStats(TlBufferParser &p)
  : views_graph_(TlFetchObject<StatsGraph>::parse(p))
  , reactions_by_emotion_graph_(TlFetchObject<StatsGraph>::parse(p))
{}

void stats_messageStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.messageStats");
    s.store_object_field("views_graph", static_cast<const BaseObject *>(views_graph_.get()));
    s.store_object_field("reactions_by_emotion_graph", static_cast<const BaseObject *>(reactions_by_emotion_graph_.get()));
    s.store_class_end();
  }
}

object_ptr<stories_AllStories> stories_AllStories::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case stories_allStoriesNotModified::ID:
      return stories_allStoriesNotModified::fetch(p);
    case stories_allStories::ID:
      return stories_allStories::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

stories_allStoriesNotModified::stories_allStoriesNotModified()
  : flags_()
  , state_()
  , stealth_mode_()
{}

const std::int32_t stories_allStoriesNotModified::ID;

object_ptr<stories_AllStories> stories_allStoriesNotModified::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stories_allStoriesNotModified> res = make_tl_object<stories_allStoriesNotModified>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->state_ = TlFetchString<string>::parse(p);
  res->stealth_mode_ = TlFetchBoxed<TlFetchObject<storiesStealthMode>, 1898850301>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void stories_allStoriesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.allStoriesNotModified");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("state", state_);
    s.store_object_field("stealth_mode", static_cast<const BaseObject *>(stealth_mode_.get()));
    s.store_class_end();
  }
}

stories_allStories::stories_allStories()
  : flags_()
  , has_more_()
  , count_()
  , state_()
  , peer_stories_()
  , chats_()
  , users_()
  , stealth_mode_()
{}

const std::int32_t stories_allStories::ID;

object_ptr<stories_AllStories> stories_allStories::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stories_allStories> res = make_tl_object<stories_allStories>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_more_ = (var0 & 1) != 0;
  res->count_ = TlFetchInt::parse(p);
  res->state_ = TlFetchString<string>::parse(p);
  res->peer_stories_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<peerStories>, -1707742823>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  res->stealth_mode_ = TlFetchBoxed<TlFetchObject<storiesStealthMode>, 1898850301>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void stories_allStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.allStories");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_more_ << 0)));
    if (var0 & 1) { s.store_field("has_more", true); }
    s.store_field("count", count_);
    s.store_field("state", state_);
    { s.store_vector_begin("peer_stories", peer_stories_.size()); for (const auto &_value : peer_stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("stealth_mode", static_cast<const BaseObject *>(stealth_mode_.get()));
    s.store_class_end();
  }
}

object_ptr<upload_CdnFile> upload_CdnFile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case upload_cdnFileReuploadNeeded::ID:
      return upload_cdnFileReuploadNeeded::fetch(p);
    case upload_cdnFile::ID:
      return upload_cdnFile::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t upload_cdnFileReuploadNeeded::ID;

object_ptr<upload_CdnFile> upload_cdnFileReuploadNeeded::fetch(TlBufferParser &p) {
  return make_tl_object<upload_cdnFileReuploadNeeded>(p);
}

upload_cdnFileReuploadNeeded::upload_cdnFileReuploadNeeded(TlBufferParser &p)
  : request_token_(TlFetchBytes<bytes>::parse(p))
{}

void upload_cdnFileReuploadNeeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.cdnFileReuploadNeeded");
    s.store_bytes_field("request_token", request_token_);
    s.store_class_end();
  }
}

const std::int32_t upload_cdnFile::ID;

object_ptr<upload_CdnFile> upload_cdnFile::fetch(TlBufferParser &p) {
  return make_tl_object<upload_cdnFile>(p);
}

upload_cdnFile::upload_cdnFile(TlBufferParser &p)
  : bytes_(TlFetchBytes<bytes>::parse(p))
{}

void upload_cdnFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.cdnFile");
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

const std::int32_t users_userFull::ID;

object_ptr<users_userFull> users_userFull::fetch(TlBufferParser &p) {
  return make_tl_object<users_userFull>(p);
}

users_userFull::users_userFull(TlBufferParser &p)
  : full_user_(TlFetchBoxed<TlFetchObject<userFull>, 114026053>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void users_userFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.userFull");
    s.store_object_field("full_user", static_cast<const BaseObject *>(full_user_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_deleteSecureValue::account_deleteSecureValue(array<object_ptr<SecureValueType>> &&types_)
  : types_(std::move(types_))
{}

const std::int32_t account_deleteSecureValue::ID;

void account_deleteSecureValue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1199522741);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(types_, s);
}

void account_deleteSecureValue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1199522741);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(types_, s);
}

void account_deleteSecureValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.deleteSecureValue");
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_deleteSecureValue::ReturnType account_deleteSecureValue::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_getRecentEmojiStatuses::account_getRecentEmojiStatuses(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getRecentEmojiStatuses::ID;

void account_getRecentEmojiStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(257392901);
  TlStoreBinary::store(hash_, s);
}

void account_getRecentEmojiStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(257392901);
  TlStoreBinary::store(hash_, s);
}

void account_getRecentEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getRecentEmojiStatuses");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getRecentEmojiStatuses::ReturnType account_getRecentEmojiStatuses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_EmojiStatuses>::parse(p);
#undef FAIL
}

account_getSavedMusicIds::account_getSavedMusicIds(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getSavedMusicIds::ID;

void account_getSavedMusicIds::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-526557265);
  TlStoreBinary::store(hash_, s);
}

void account_getSavedMusicIds::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-526557265);
  TlStoreBinary::store(hash_, s);
}

void account_getSavedMusicIds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getSavedMusicIds");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getSavedMusicIds::ReturnType account_getSavedMusicIds::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_SavedMusicIds>::parse(p);
#undef FAIL
}

account_getSavedRingtones::account_getSavedRingtones(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getSavedRingtones::ID;

void account_getSavedRingtones::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-510647672);
  TlStoreBinary::store(hash_, s);
}

void account_getSavedRingtones::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-510647672);
  TlStoreBinary::store(hash_, s);
}

void account_getSavedRingtones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getSavedRingtones");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getSavedRingtones::ReturnType account_getSavedRingtones::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_SavedRingtones>::parse(p);
#undef FAIL
}

account_getUniqueGiftChatThemes::account_getUniqueGiftChatThemes(string const &offset_, int32 limit_, int64 hash_)
  : offset_(offset_)
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t account_getUniqueGiftChatThemes::ID;

void account_getUniqueGiftChatThemes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-466818615);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void account_getUniqueGiftChatThemes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-466818615);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void account_getUniqueGiftChatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getUniqueGiftChatThemes");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getUniqueGiftChatThemes::ReturnType account_getUniqueGiftChatThemes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_ChatThemes>::parse(p);
#undef FAIL
}

account_installWallPaper::account_installWallPaper(object_ptr<InputWallPaper> &&wallpaper_, object_ptr<wallPaperSettings> &&settings_)
  : wallpaper_(std::move(wallpaper_))
  , settings_(std::move(settings_))
{}

const std::int32_t account_installWallPaper::ID;

void account_installWallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-18000023);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s);
  TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s);
}

void account_installWallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-18000023);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s);
  TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s);
}

void account_installWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.installWallPaper");
    s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get()));
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_installWallPaper::ReturnType account_installWallPaper::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_reportPeer::account_reportPeer(object_ptr<InputPeer> &&peer_, object_ptr<ReportReason> &&reason_, string const &message_)
  : peer_(std::move(peer_))
  , reason_(std::move(reason_))
  , message_(message_)
{}

const std::int32_t account_reportPeer::ID;

void account_reportPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-977650298);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reason_, s);
  TlStoreString::store(message_, s);
}

void account_reportPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-977650298);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reason_, s);
  TlStoreString::store(message_, s);
}

void account_reportPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.reportPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("message", message_);
    s.store_class_end();
  }
}

account_reportPeer::ReturnType account_reportPeer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_resetWallPapers::ID;

void account_resetWallPapers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1153722364);
}

void account_resetWallPapers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1153722364);
}

void account_resetWallPapers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetWallPapers");
    s.store_class_end();
  }
}

account_resetWallPapers::ReturnType account_resetWallPapers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_uploadTheme::account_uploadTheme(int32 flags_, object_ptr<InputFile> &&file_, object_ptr<InputFile> &&thumb_, string const &file_name_, string const &mime_type_)
  : flags_(flags_)
  , file_(std::move(file_))
  , thumb_(std::move(thumb_))
  , file_name_(file_name_)
  , mime_type_(mime_type_)
{}

const std::int32_t account_uploadTheme::ID;

void account_uploadTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(473805619);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  TlStoreString::store(file_name_, s);
  TlStoreString::store(mime_type_, s);
}

void account_uploadTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(473805619);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  TlStoreString::store(file_name_, s);
  TlStoreString::store(mime_type_, s);
}

void account_uploadTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.uploadTheme");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    if (var0 & 1) { s.store_object_field("thumb", static_cast<const BaseObject *>(thumb_.get())); }
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_class_end();
  }
}

account_uploadTheme::ReturnType account_uploadTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Document>::parse(p);
#undef FAIL
}

auth_dropTempAuthKeys::auth_dropTempAuthKeys(array<int64> &&except_auth_keys_)
  : except_auth_keys_(std::move(except_auth_keys_))
{}

const std::int32_t auth_dropTempAuthKeys::ID;

void auth_dropTempAuthKeys::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1907842680);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(except_auth_keys_, s);
}

void auth_dropTempAuthKeys::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1907842680);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(except_auth_keys_, s);
}

void auth_dropTempAuthKeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.dropTempAuthKeys");
    { s.store_vector_begin("except_auth_keys", except_auth_keys_.size()); for (const auto &_value : except_auth_keys_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

auth_dropTempAuthKeys::ReturnType auth_dropTempAuthKeys::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t auth_logOut::ID;

void auth_logOut::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1047706137);
}

void auth_logOut::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1047706137);
}

void auth_logOut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.logOut");
    s.store_class_end();
  }
}

auth_logOut::ReturnType auth_logOut::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<auth_loggedOut>, -1012759713>::parse(p);
#undef FAIL
}

auth_resetLoginEmail::auth_resetLoginEmail(string const &phone_number_, string const &phone_code_hash_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
{}

const std::int32_t auth_resetLoginEmail::ID;

void auth_resetLoginEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2123760019);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
}

void auth_resetLoginEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2123760019);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
}

void auth_resetLoginEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.resetLoginEmail");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_class_end();
  }
}

auth_resetLoginEmail::ReturnType auth_resetLoginEmail::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

bots_getPreviewMedias::bots_getPreviewMedias(object_ptr<InputUser> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t bots_getPreviewMedias::ID;

void bots_getPreviewMedias::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1566222003);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_getPreviewMedias::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1566222003);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_getPreviewMedias::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getPreviewMedias");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

bots_getPreviewMedias::ReturnType bots_getPreviewMedias::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botPreviewMedia>, 602479523>>, 481674261>::parse(p);
#undef FAIL
}

channels_getAdminLog::channels_getAdminLog(int32 flags_, object_ptr<InputChannel> &&channel_, string const &q_, object_ptr<channelAdminLogEventsFilter> &&events_filter_, array<object_ptr<InputUser>> &&admins_, int64 max_id_, int64 min_id_, int32 limit_)
  : flags_(flags_)
  , channel_(std::move(channel_))
  , q_(q_)
  , events_filter_(std::move(events_filter_))
  , admins_(std::move(admins_))
  , max_id_(max_id_)
  , min_id_(min_id_)
  , limit_(limit_)
{}

const std::int32_t channels_getAdminLog::ID;

void channels_getAdminLog::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(870184064);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(q_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -368018716>::store(events_filter_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(admins_, s); }
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(limit_, s);
}

void channels_getAdminLog::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(870184064);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(q_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -368018716>::store(events_filter_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(admins_, s); }
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(limit_, s);
}

void channels_getAdminLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getAdminLog");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("q", q_);
    if (var0 & 1) { s.store_object_field("events_filter", static_cast<const BaseObject *>(events_filter_.get())); }
    if (var0 & 2) { { s.store_vector_begin("admins", admins_.size()); for (const auto &_value : admins_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

channels_getAdminLog::ReturnType channels_getAdminLog::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<channels_adminLogResults>, -309659827>::parse(p);
#undef FAIL
}

channels_getFullChannel::channels_getFullChannel(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t channels_getFullChannel::ID;

void channels_getFullChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(141781513);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_getFullChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(141781513);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_getFullChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getFullChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_getFullChannel::ReturnType channels_getFullChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_chatFull>, -438840932>::parse(p);
#undef FAIL
}

channels_setEmojiStickers::channels_setEmojiStickers(object_ptr<InputChannel> &&channel_, object_ptr<InputStickerSet> &&stickerset_)
  : channel_(std::move(channel_))
  , stickerset_(std::move(stickerset_))
{}

const std::int32_t channels_setEmojiStickers::ID;

void channels_setEmojiStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1020866743);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void channels_setEmojiStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1020866743);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void channels_setEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.setEmojiStickers");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_class_end();
  }
}

channels_setEmojiStickers::ReturnType channels_setEmojiStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_toggleSlowMode::channels_toggleSlowMode(object_ptr<InputChannel> &&channel_, int32 seconds_)
  : channel_(std::move(channel_))
  , seconds_(seconds_)
{}

const std::int32_t channels_toggleSlowMode::ID;

void channels_toggleSlowMode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-304832784);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(seconds_, s);
}

void channels_toggleSlowMode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-304832784);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(seconds_, s);
}

void channels_toggleSlowMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleSlowMode");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("seconds", seconds_);
    s.store_class_end();
  }
}

channels_toggleSlowMode::ReturnType channels_toggleSlowMode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

chatlists_joinChatlistInvite::chatlists_joinChatlistInvite(string const &slug_, array<object_ptr<InputPeer>> &&peers_)
  : slug_(slug_)
  , peers_(std::move(peers_))
{}

const std::int32_t chatlists_joinChatlistInvite::ID;

void chatlists_joinChatlistInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1498291302);
  TlStoreString::store(slug_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_joinChatlistInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1498291302);
  TlStoreString::store(slug_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_joinChatlistInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.joinChatlistInvite");
    s.store_field("slug", slug_);
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatlists_joinChatlistInvite::ReturnType chatlists_joinChatlistInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

contacts_editCloseFriends::contacts_editCloseFriends(array<int64> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t contacts_editCloseFriends::ID;

void contacts_editCloseFriends::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1167653392);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void contacts_editCloseFriends::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1167653392);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void contacts_editCloseFriends::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.editCloseFriends");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

contacts_editCloseFriends::ReturnType contacts_editCloseFriends::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t contacts_exportContactToken::ID;

void contacts_exportContactToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-127582169);
}

void contacts_exportContactToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-127582169);
}

void contacts_exportContactToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.exportContactToken");
    s.store_class_end();
  }
}

contacts_exportContactToken::ReturnType contacts_exportContactToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<exportedContactToken>, 1103040667>::parse(p);
#undef FAIL
}

contacts_getContacts::contacts_getContacts(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t contacts_getContacts::ID;

void contacts_getContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1574346258);
  TlStoreBinary::store(hash_, s);
}

void contacts_getContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1574346258);
  TlStoreBinary::store(hash_, s);
}

void contacts_getContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getContacts");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

contacts_getContacts::ReturnType contacts_getContacts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<contacts_Contacts>::parse(p);
#undef FAIL
}

contacts_getTopPeers::contacts_getTopPeers(int32 flags_, bool correspondents_, bool bots_pm_, bool bots_inline_, bool phone_calls_, bool forward_users_, bool forward_chats_, bool groups_, bool channels_, bool bots_app_, int32 offset_, int32 limit_, int64 hash_)
  : flags_(flags_)
  , correspondents_(correspondents_)
  , bots_pm_(bots_pm_)
  , bots_inline_(bots_inline_)
  , phone_calls_(phone_calls_)
  , forward_users_(forward_users_)
  , forward_chats_(forward_chats_)
  , groups_(groups_)
  , channels_(channels_)
  , bots_app_(bots_app_)
  , offset_(offset_)
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t contacts_getTopPeers::ID;

void contacts_getTopPeers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1758168906);
  TlStoreBinary::store((var0 = flags_ | (correspondents_ << 0) | (bots_pm_ << 1) | (bots_inline_ << 2) | (phone_calls_ << 3) | (forward_users_ << 4) | (forward_chats_ << 5) | (groups_ << 10) | (channels_ << 15) | (bots_app_ << 16)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void contacts_getTopPeers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1758168906);
  TlStoreBinary::store((var0 = flags_ | (correspondents_ << 0) | (bots_pm_ << 1) | (bots_inline_ << 2) | (phone_calls_ << 3) | (forward_users_ << 4) | (forward_chats_ << 5) | (groups_ << 10) | (channels_ << 15) | (bots_app_ << 16)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void contacts_getTopPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getTopPeers");
    s.store_field("flags", (var0 = flags_ | (correspondents_ << 0) | (bots_pm_ << 1) | (bots_inline_ << 2) | (phone_calls_ << 3) | (forward_users_ << 4) | (forward_chats_ << 5) | (groups_ << 10) | (channels_ << 15) | (bots_app_ << 16)));
    if (var0 & 1) { s.store_field("correspondents", true); }
    if (var0 & 2) { s.store_field("bots_pm", true); }
    if (var0 & 4) { s.store_field("bots_inline", true); }
    if (var0 & 8) { s.store_field("phone_calls", true); }
    if (var0 & 16) { s.store_field("forward_users", true); }
    if (var0 & 32) { s.store_field("forward_chats", true); }
    if (var0 & 1024) { s.store_field("groups", true); }
    if (var0 & 32768) { s.store_field("channels", true); }
    if (var0 & 65536) { s.store_field("bots_app", true); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

contacts_getTopPeers::ReturnType contacts_getTopPeers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<contacts_TopPeers>::parse(p);
#undef FAIL
}

const std::int32_t contacts_resetSaved::ID;

void contacts_resetSaved::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2020263951);
}

void contacts_resetSaved::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2020263951);
}

void contacts_resetSaved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.resetSaved");
    s.store_class_end();
  }
}

contacts_resetSaved::ReturnType contacts_resetSaved::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

help_dismissSuggestion::help_dismissSuggestion(object_ptr<InputPeer> &&peer_, string const &suggestion_)
  : peer_(std::move(peer_))
  , suggestion_(suggestion_)
{}

const std::int32_t help_dismissSuggestion::ID;

void help_dismissSuggestion::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-183649631);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(suggestion_, s);
}

void help_dismissSuggestion::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-183649631);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(suggestion_, s);
}

void help_dismissSuggestion::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.dismissSuggestion");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("suggestion", suggestion_);
    s.store_class_end();
  }
}

help_dismissSuggestion::ReturnType help_dismissSuggestion::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

help_getPeerColors::help_getPeerColors(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t help_getPeerColors::ID;

void help_getPeerColors::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-629083089);
  TlStoreBinary::store(hash_, s);
}

void help_getPeerColors::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-629083089);
  TlStoreBinary::store(hash_, s);
}

void help_getPeerColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getPeerColors");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_getPeerColors::ReturnType help_getPeerColors::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_PeerColors>::parse(p);
#undef FAIL
}

const std::int32_t help_getSupport::ID;

void help_getSupport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1663104819);
}

void help_getSupport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1663104819);
}

void help_getSupport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getSupport");
    s.store_class_end();
  }
}

help_getSupport::ReturnType help_getSupport::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<help_support>, 398898678>::parse(p);
#undef FAIL
}

langpack_getLangPack::langpack_getLangPack(string const &lang_pack_, string const &lang_code_)
  : lang_pack_(lang_pack_)
  , lang_code_(lang_code_)
{}

const std::int32_t langpack_getLangPack::ID;

void langpack_getLangPack::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-219008246);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
}

void langpack_getLangPack::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-219008246);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
}

void langpack_getLangPack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langpack.getLangPack");
    s.store_field("lang_pack", lang_pack_);
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

langpack_getLangPack::ReturnType langpack_getLangPack::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<langPackDifference>, -209337866>::parse(p);
#undef FAIL
}

messages_checkUrlAuthMatchCode::messages_checkUrlAuthMatchCode(string const &url_, string const &match_code_)
  : url_(url_)
  , match_code_(match_code_)
{}

const std::int32_t messages_checkUrlAuthMatchCode::ID;

void messages_checkUrlAuthMatchCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-911967477);
  TlStoreString::store(url_, s);
  TlStoreString::store(match_code_, s);
}

void messages_checkUrlAuthMatchCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-911967477);
  TlStoreString::store(url_, s);
  TlStoreString::store(match_code_, s);
}

void messages_checkUrlAuthMatchCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.checkUrlAuthMatchCode");
    s.store_field("url", url_);
    s.store_field("match_code", match_code_);
    s.store_class_end();
  }
}

messages_checkUrlAuthMatchCode::ReturnType messages_checkUrlAuthMatchCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t messages_clearAllDrafts::ID;

void messages_clearAllDrafts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2119757468);
}

void messages_clearAllDrafts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2119757468);
}

void messages_clearAllDrafts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.clearAllDrafts");
    s.store_class_end();
  }
}

messages_clearAllDrafts::ReturnType messages_clearAllDrafts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_clickSponsoredMessage::messages_clickSponsoredMessage(int32 flags_, bool media_, bool fullscreen_, bytes &&random_id_)
  : flags_(flags_)
  , media_(media_)
  , fullscreen_(fullscreen_)
  , random_id_(std::move(random_id_))
{}

const std::int32_t messages_clickSponsoredMessage::ID;

void messages_clickSponsoredMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2110454402);
  TlStoreBinary::store((var0 = flags_ | (media_ << 0) | (fullscreen_ << 1)), s);
  TlStoreString::store(random_id_, s);
}

void messages_clickSponsoredMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2110454402);
  TlStoreBinary::store((var0 = flags_ | (media_ << 0) | (fullscreen_ << 1)), s);
  TlStoreString::store(random_id_, s);
}

void messages_clickSponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.clickSponsoredMessage");
    s.store_field("flags", (var0 = flags_ | (media_ << 0) | (fullscreen_ << 1)));
    if (var0 & 1) { s.store_field("media", true); }
    if (var0 & 2) { s.store_field("fullscreen", true); }
    s.store_bytes_field("random_id", random_id_);
    s.store_class_end();
  }
}

messages_clickSponsoredMessage::ReturnType messages_clickSponsoredMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_deleteExportedChatInvite::messages_deleteExportedChatInvite(object_ptr<InputPeer> &&peer_, string const &link_)
  : peer_(std::move(peer_))
  , link_(link_)
{}

const std::int32_t messages_deleteExportedChatInvite::ID;

void messages_deleteExportedChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-731601877);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
}

void messages_deleteExportedChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-731601877);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
}

void messages_deleteExportedChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteExportedChatInvite");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("link", link_);
    s.store_class_end();
  }
}

messages_deleteExportedChatInvite::ReturnType messages_deleteExportedChatInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_editChatAdmin::messages_editChatAdmin(int64 chat_id_, object_ptr<InputUser> &&user_id_, bool is_admin_)
  : chat_id_(chat_id_)
  , user_id_(std::move(user_id_))
  , is_admin_(is_admin_)
{}

const std::int32_t messages_editChatAdmin::ID;

void messages_editChatAdmin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1470377534);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBool::store(is_admin_, s);
}

void messages_editChatAdmin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1470377534);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBool::store(is_admin_, s);
}

void messages_editChatAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatAdmin");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("is_admin", is_admin_);
    s.store_class_end();
  }
}

messages_editChatAdmin::ReturnType messages_editChatAdmin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_editChatCreator::messages_editChatCreator(object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&user_id_, object_ptr<InputCheckPasswordSRP> &&password_)
  : peer_(std::move(peer_))
  , user_id_(std::move(user_id_))
  , password_(std::move(password_))
{}

const std::int32_t messages_editChatCreator::ID;

void messages_editChatCreator::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-146556841);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void messages_editChatCreator::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-146556841);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void messages_editChatCreator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatCreator");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_object_field("password", static_cast<const BaseObject *>(password_.get()));
    s.store_class_end();
  }
}

messages_editChatCreator::ReturnType messages_editChatCreator::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editFactCheck::messages_editFactCheck(object_ptr<InputPeer> &&peer_, int32 msg_id_, object_ptr<textWithEntities> &&text_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , text_(std::move(text_))
{}

const std::int32_t messages_editFactCheck::ID;

void messages_editFactCheck::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(92925557);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
}

void messages_editFactCheck::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(92925557);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
}

void messages_editFactCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editFactCheck");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

messages_editFactCheck::ReturnType messages_editFactCheck::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getBotApp::messages_getBotApp(object_ptr<InputBotApp> &&app_, int64 hash_)
  : app_(std::move(app_))
  , hash_(hash_)
{}

const std::int32_t messages_getBotApp::ID;

void messages_getBotApp::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(889046467);
  TlStoreBoxedUnknown<TlStoreObject>::store(app_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getBotApp::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(889046467);
  TlStoreBoxedUnknown<TlStoreObject>::store(app_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getBotApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getBotApp");
    s.store_object_field("app", static_cast<const BaseObject *>(app_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getBotApp::ReturnType messages_getBotApp::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_botApp>, -347034123>::parse(p);
#undef FAIL
}

messages_getChats::messages_getChats(array<int64> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t messages_getChats::ID;

void messages_getChats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1240027791);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getChats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1240027791);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getChats");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getChats::ReturnType messages_getChats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

messages_getDefaultTagReactions::messages_getDefaultTagReactions(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getDefaultTagReactions::ID;

void messages_getDefaultTagReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1107741656);
  TlStoreBinary::store(hash_, s);
}

void messages_getDefaultTagReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1107741656);
  TlStoreBinary::store(hash_, s);
}

void messages_getDefaultTagReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDefaultTagReactions");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getDefaultTagReactions::ReturnType messages_getDefaultTagReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Reactions>::parse(p);
#undef FAIL
}

messages_getEmojiURL::messages_getEmojiURL(string const &lang_code_)
  : lang_code_(lang_code_)
{}

const std::int32_t messages_getEmojiURL::ID;

void messages_getEmojiURL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-709817306);
  TlStoreString::store(lang_code_, s);
}

void messages_getEmojiURL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-709817306);
  TlStoreString::store(lang_code_, s);
}

void messages_getEmojiURL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiURL");
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

messages_getEmojiURL::ReturnType messages_getEmojiURL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<emojiURL>, -1519029347>::parse(p);
#undef FAIL
}

messages_getFactCheck::messages_getFactCheck(object_ptr<InputPeer> &&peer_, array<int32> &&msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(std::move(msg_id_))
{}

const std::int32_t messages_getFactCheck::ID;

void messages_getFactCheck::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1177696786);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(msg_id_, s);
}

void messages_getFactCheck::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1177696786);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(msg_id_, s);
}

void messages_getFactCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getFactCheck");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("msg_id", msg_id_.size()); for (const auto &_value : msg_id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getFactCheck::ReturnType messages_getFactCheck::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<factCheck>, -1197736753>>, 481674261>::parse(p);
#undef FAIL
}

messages_getFeaturedEmojiStickers::messages_getFeaturedEmojiStickers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getFeaturedEmojiStickers::ID;

void messages_getFeaturedEmojiStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(248473398);
  TlStoreBinary::store(hash_, s);
}

void messages_getFeaturedEmojiStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(248473398);
  TlStoreBinary::store(hash_, s);
}

void messages_getFeaturedEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getFeaturedEmojiStickers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getFeaturedEmojiStickers::ReturnType messages_getFeaturedEmojiStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FeaturedStickers>::parse(p);
#undef FAIL
}

messages_getFutureChatCreatorAfterLeave::messages_getFutureChatCreatorAfterLeave(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_getFutureChatCreatorAfterLeave::ID;

void messages_getFutureChatCreatorAfterLeave::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(998051494);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getFutureChatCreatorAfterLeave::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(998051494);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getFutureChatCreatorAfterLeave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getFutureChatCreatorAfterLeave");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_getFutureChatCreatorAfterLeave::ReturnType messages_getFutureChatCreatorAfterLeave::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

messages_getGameHighScores::messages_getGameHighScores(object_ptr<InputPeer> &&peer_, int32 id_, object_ptr<InputUser> &&user_id_)
  : peer_(std::move(peer_))
  , id_(id_)
  , user_id_(std::move(user_id_))
{}

const std::int32_t messages_getGameHighScores::ID;

void messages_getGameHighScores::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-400399203);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_getGameHighScores::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-400399203);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_getGameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getGameHighScores");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

messages_getGameHighScores::ReturnType messages_getGameHighScores::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_highScores>, -1707344487>::parse(p);
#undef FAIL
}

messages_getMessageEditData::messages_getMessageEditData(object_ptr<InputPeer> &&peer_, int32 id_)
  : peer_(std::move(peer_))
  , id_(id_)
{}

const std::int32_t messages_getMessageEditData::ID;

void messages_getMessageEditData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-39416522);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void messages_getMessageEditData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-39416522);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void messages_getMessageEditData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMessageEditData");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

messages_getMessageEditData::ReturnType messages_getMessageEditData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_messageEditData>, 649453030>::parse(p);
#undef FAIL
}

messages_getMessageReadParticipants::messages_getMessageReadParticipants(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t messages_getMessageReadParticipants::ID;

void messages_getMessageReadParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(834782287);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_getMessageReadParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(834782287);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_getMessageReadParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMessageReadParticipants");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

messages_getMessageReadParticipants::ReturnType messages_getMessageReadParticipants::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<readParticipantDate>, 1246753138>>, 481674261>::parse(p);
#undef FAIL
}

messages_getMyStickers::messages_getMyStickers(int64 offset_id_, int32 limit_)
  : offset_id_(offset_id_)
  , limit_(limit_)
{}

const std::int32_t messages_getMyStickers::ID;

void messages_getMyStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-793386500);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getMyStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-793386500);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getMyStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMyStickers");
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getMyStickers::ReturnType messages_getMyStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_myStickers>, -83926371>::parse(p);
#undef FAIL
}

messages_getOnlines::messages_getOnlines(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_getOnlines::ID;

void messages_getOnlines::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1848369232);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getOnlines::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1848369232);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getOnlines::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getOnlines");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_getOnlines::ReturnType messages_getOnlines::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<chatOnlines>, -264117680>::parse(p);
#undef FAIL
}

messages_getQuickReplies::messages_getQuickReplies(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getQuickReplies::ID;

void messages_getQuickReplies::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-729550168);
  TlStoreBinary::store(hash_, s);
}

void messages_getQuickReplies::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-729550168);
  TlStoreBinary::store(hash_, s);
}

void messages_getQuickReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getQuickReplies");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getQuickReplies::ReturnType messages_getQuickReplies::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_QuickReplies>::parse(p);
#undef FAIL
}

messages_receivedMessages::messages_receivedMessages(int32 max_id_)
  : max_id_(max_id_)
{}

const std::int32_t messages_receivedMessages::ID;

void messages_receivedMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(94983360);
  TlStoreBinary::store(max_id_, s);
}

void messages_receivedMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(94983360);
  TlStoreBinary::store(max_id_, s);
}

void messages_receivedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.receivedMessages");
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

messages_receivedMessages::ReturnType messages_receivedMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<receivedNotifyMessage>, -1551583367>>, 481674261>::parse(p);
#undef FAIL
}

messages_reorderPinnedDialogs::messages_reorderPinnedDialogs(int32 flags_, bool force_, int32 folder_id_, array<object_ptr<InputDialogPeer>> &&order_)
  : flags_(flags_)
  , force_(force_)
  , folder_id_(folder_id_)
  , order_(std::move(order_))
{}

const std::int32_t messages_reorderPinnedDialogs::ID;

void messages_reorderPinnedDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(991616823);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBinary::store(folder_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s);
}

void messages_reorderPinnedDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(991616823);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBinary::store(folder_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s);
}

void messages_reorderPinnedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reorderPinnedDialogs");
    s.store_field("flags", (var0 = flags_ | (force_ << 0)));
    if (var0 & 1) { s.store_field("force", true); }
    s.store_field("folder_id", folder_id_);
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reorderPinnedDialogs::ReturnType messages_reorderPinnedDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_report::messages_report(object_ptr<InputPeer> &&peer_, array<int32> &&id_, bytes &&option_, string const &message_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
  , option_(std::move(option_))
  , message_(message_)
{}

const std::int32_t messages_report::ID;

void messages_report::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-59199589);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreString::store(option_, s);
  TlStoreString::store(message_, s);
}

void messages_report::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-59199589);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreString::store(option_, s);
  TlStoreString::store(message_, s);
}

void messages_report::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.report");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_bytes_field("option", option_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

messages_report::ReturnType messages_report::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<ReportResult>::parse(p);
#undef FAIL
}

messages_reportMusicListen::messages_reportMusicListen(object_ptr<InputDocument> &&id_, int32 listened_duration_)
  : id_(std::move(id_))
  , listened_duration_(listened_duration_)
{}

const std::int32_t messages_reportMusicListen::ID;

void messages_reportMusicListen::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-574826471);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBinary::store(listened_duration_, s);
}

void messages_reportMusicListen::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-574826471);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBinary::store(listened_duration_, s);
}

void messages_reportMusicListen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportMusicListen");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("listened_duration", listened_duration_);
    s.store_class_end();
  }
}

messages_reportMusicListen::ReturnType messages_reportMusicListen::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_saveDefaultSendAs::messages_saveDefaultSendAs(object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&send_as_)
  : peer_(std::move(peer_))
  , send_as_(std::move(send_as_))
{}

const std::int32_t messages_saveDefaultSendAs::ID;

void messages_saveDefaultSendAs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-855777386);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s);
}

void messages_saveDefaultSendAs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-855777386);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s);
}

void messages_saveDefaultSendAs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.saveDefaultSendAs");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get()));
    s.store_class_end();
  }
}

messages_saveDefaultSendAs::ReturnType messages_saveDefaultSendAs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_saveGif::messages_saveGif(object_ptr<InputDocument> &&id_, bool unsave_)
  : id_(std::move(id_))
  , unsave_(unsave_)
{}

const std::int32_t messages_saveGif::ID;

void messages_saveGif::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(846868683);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unsave_, s);
}

void messages_saveGif::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(846868683);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unsave_, s);
}

void messages_saveGif::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.saveGif");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("unsave", unsave_);
    s.store_class_end();
  }
}

messages_saveGif::ReturnType messages_saveGif::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_sendScreenshotNotification::messages_sendScreenshotNotification(object_ptr<InputPeer> &&peer_, object_ptr<InputReplyTo> &&reply_to_, int64 random_id_)
  : peer_(std::move(peer_))
  , reply_to_(std::move(reply_to_))
  , random_id_(random_id_)
{}

const std::int32_t messages_sendScreenshotNotification::ID;

void messages_sendScreenshotNotification::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1589618665);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s);
  TlStoreBinary::store(random_id_, s);
}

void messages_sendScreenshotNotification::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1589618665);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s);
  TlStoreBinary::store(random_id_, s);
}

void messages_sendScreenshotNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendScreenshotNotification");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get()));
    s.store_field("random_id", random_id_);
    s.store_class_end();
  }
}

messages_sendScreenshotNotification::ReturnType messages_sendScreenshotNotification::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setDefaultReaction::messages_setDefaultReaction(object_ptr<Reaction> &&reaction_)
  : reaction_(std::move(reaction_))
{}

const std::int32_t messages_setDefaultReaction::ID;

void messages_setDefaultReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1330094102);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
}

void messages_setDefaultReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1330094102);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
}

void messages_setDefaultReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setDefaultReaction");
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

messages_setDefaultReaction::ReturnType messages_setDefaultReaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_setHistoryTTL::messages_setHistoryTTL(object_ptr<InputPeer> &&peer_, int32 period_)
  : peer_(std::move(peer_))
  , period_(period_)
{}

const std::int32_t messages_setHistoryTTL::ID;

void messages_setHistoryTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1207017500);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(period_, s);
}

void messages_setHistoryTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1207017500);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(period_, s);
}

void messages_setHistoryTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setHistoryTTL");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("period", period_);
    s.store_class_end();
  }
}

messages_setHistoryTTL::ReturnType messages_setHistoryTTL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_toggleDialogPin::messages_toggleDialogPin(int32 flags_, bool pinned_, object_ptr<InputDialogPeer> &&peer_)
  : flags_(flags_)
  , pinned_(pinned_)
  , peer_(std::move(peer_))
{}

const std::int32_t messages_toggleDialogPin::ID;

void messages_toggleDialogPin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1489903017);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_toggleDialogPin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1489903017);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_toggleDialogPin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleDialogPin");
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_toggleDialogPin::ReturnType messages_toggleDialogPin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_updateDialogFiltersOrder::messages_updateDialogFiltersOrder(array<int32> &&order_)
  : order_(std::move(order_))
{}

const std::int32_t messages_updateDialogFiltersOrder::ID;

void messages_updateDialogFiltersOrder::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-983318044);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_updateDialogFiltersOrder::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-983318044);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_updateDialogFiltersOrder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.updateDialogFiltersOrder");
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_updateDialogFiltersOrder::ReturnType messages_updateDialogFiltersOrder::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_checkGiftCode::payments_checkGiftCode(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t payments_checkGiftCode::ID;

void payments_checkGiftCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1907247935);
  TlStoreString::store(slug_, s);
}

void payments_checkGiftCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1907247935);
  TlStoreString::store(slug_, s);
}

void payments_checkGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.checkGiftCode");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

payments_checkGiftCode::ReturnType payments_checkGiftCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_checkedGiftCode>, -342343793>::parse(p);
#undef FAIL
}

payments_convertStarGift::payments_convertStarGift(object_ptr<InputSavedStarGift> &&stargift_)
  : stargift_(std::move(stargift_))
{}

const std::int32_t payments_convertStarGift::ID;

void payments_convertStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1958676331);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_convertStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1958676331);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_convertStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.convertStarGift");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

payments_convertStarGift::ReturnType payments_convertStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_fulfillStarsSubscription::payments_fulfillStarsSubscription(object_ptr<InputPeer> &&peer_, string const &subscription_id_)
  : peer_(std::move(peer_))
  , subscription_id_(subscription_id_)
{}

const std::int32_t payments_fulfillStarsSubscription::ID;

void payments_fulfillStarsSubscription::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-866391117);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(subscription_id_, s);
}

void payments_fulfillStarsSubscription::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-866391117);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(subscription_id_, s);
}

void payments_fulfillStarsSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.fulfillStarsSubscription");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("subscription_id", subscription_id_);
    s.store_class_end();
  }
}

payments_fulfillStarsSubscription::ReturnType payments_fulfillStarsSubscription::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_getGiveawayInfo::payments_getGiveawayInfo(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t payments_getGiveawayInfo::ID;

void payments_getGiveawayInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-198994907);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void payments_getGiveawayInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-198994907);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void payments_getGiveawayInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getGiveawayInfo");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

payments_getGiveawayInfo::ReturnType payments_getGiveawayInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_GiveawayInfo>::parse(p);
#undef FAIL
}

payments_getStarGiftWithdrawalUrl::payments_getStarGiftWithdrawalUrl(object_ptr<InputSavedStarGift> &&stargift_, object_ptr<InputCheckPasswordSRP> &&password_)
  : stargift_(std::move(stargift_))
  , password_(std::move(password_))
{}

const std::int32_t payments_getStarGiftWithdrawalUrl::ID;

void payments_getStarGiftWithdrawalUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-798059608);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void payments_getStarGiftWithdrawalUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-798059608);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void payments_getStarGiftWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftWithdrawalUrl");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_object_field("password", static_cast<const BaseObject *>(password_.get()));
    s.store_class_end();
  }
}

payments_getStarGiftWithdrawalUrl::ReturnType payments_getStarGiftWithdrawalUrl::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftWithdrawalUrl>, -2069218660>::parse(p);
#undef FAIL
}

phone_declineConferenceCallInvite::phone_declineConferenceCallInvite(int32 msg_id_)
  : msg_id_(msg_id_)
{}

const std::int32_t phone_declineConferenceCallInvite::ID;

void phone_declineConferenceCallInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1011325297);
  TlStoreBinary::store(msg_id_, s);
}

void phone_declineConferenceCallInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1011325297);
  TlStoreBinary::store(msg_id_, s);
}

void phone_declineConferenceCallInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.declineConferenceCallInvite");
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

phone_declineConferenceCallInvite::ReturnType phone_declineConferenceCallInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_editGroupCallTitle::phone_editGroupCallTitle(object_ptr<InputGroupCall> &&call_, string const &title_)
  : call_(std::move(call_))
  , title_(title_)
{}

const std::int32_t phone_editGroupCallTitle::ID;

void phone_editGroupCallTitle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(480685066);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreString::store(title_, s);
}

void phone_editGroupCallTitle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(480685066);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreString::store(title_, s);
}

void phone_editGroupCallTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.editGroupCallTitle");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

phone_editGroupCallTitle::ReturnType phone_editGroupCallTitle::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

photos_uploadContactProfilePhoto::photos_uploadContactProfilePhoto(int32 flags_, bool suggest_, bool save_, object_ptr<InputUser> &&user_id_, object_ptr<InputFile> &&file_, object_ptr<InputFile> &&video_, double video_start_ts_, object_ptr<VideoSize> &&video_emoji_markup_)
  : flags_(flags_)
  , suggest_(suggest_)
  , save_(save_)
  , user_id_(std::move(user_id_))
  , file_(std::move(file_))
  , video_(std::move(video_))
  , video_start_ts_(video_start_ts_)
  , video_emoji_markup_(std::move(video_emoji_markup_))
{}

const std::int32_t photos_uploadContactProfilePhoto::ID;

void photos_uploadContactProfilePhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-515093903);
  TlStoreBinary::store((var0 = flags_ | (suggest_ << 3) | (save_ << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(file_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(video_emoji_markup_, s); }
}

void photos_uploadContactProfilePhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-515093903);
  TlStoreBinary::store((var0 = flags_ | (suggest_ << 3) | (save_ << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(file_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(video_emoji_markup_, s); }
}

void photos_uploadContactProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.uploadContactProfilePhoto");
    s.store_field("flags", (var0 = flags_ | (suggest_ << 3) | (save_ << 4)));
    if (var0 & 8) { s.store_field("suggest", true); }
    if (var0 & 16) { s.store_field("save", true); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    if (var0 & 1) { s.store_object_field("file", static_cast<const BaseObject *>(file_.get())); }
    if (var0 & 2) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    if (var0 & 4) { s.store_field("video_start_ts", video_start_ts_); }
    if (var0 & 32) { s.store_object_field("video_emoji_markup", static_cast<const BaseObject *>(video_emoji_markup_.get())); }
    s.store_class_end();
  }
}

photos_uploadContactProfilePhoto::ReturnType photos_uploadContactProfilePhoto::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<photos_photo>, 539045032>::parse(p);
#undef FAIL
}

smsjobs_getSmsJob::smsjobs_getSmsJob(string const &job_id_)
  : job_id_(job_id_)
{}

const std::int32_t smsjobs_getSmsJob::ID;

void smsjobs_getSmsJob::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2005766191);
  TlStoreString::store(job_id_, s);
}

void smsjobs_getSmsJob::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2005766191);
  TlStoreString::store(job_id_, s);
}

void smsjobs_getSmsJob::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.getSmsJob");
    s.store_field("job_id", job_id_);
    s.store_class_end();
  }
}

smsjobs_getSmsJob::ReturnType smsjobs_getSmsJob::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<smsJob>, -425595208>::parse(p);
#undef FAIL
}

smsjobs_updateSettings::smsjobs_updateSettings(int32 flags_, bool allow_international_)
  : flags_(flags_)
  , allow_international_(allow_international_)
{}

const std::int32_t smsjobs_updateSettings::ID;

void smsjobs_updateSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(155164863);
  TlStoreBinary::store((var0 = flags_ | (allow_international_ << 0)), s);
}

void smsjobs_updateSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(155164863);
  TlStoreBinary::store((var0 = flags_ | (allow_international_ << 0)), s);
}

void smsjobs_updateSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.updateSettings");
    s.store_field("flags", (var0 = flags_ | (allow_international_ << 0)));
    if (var0 & 1) { s.store_field("allow_international", true); }
    s.store_class_end();
  }
}

smsjobs_updateSettings::ReturnType smsjobs_updateSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stats_getMessageStats::stats_getMessageStats(int32 flags_, bool dark_, object_ptr<InputChannel> &&channel_, int32 msg_id_)
  : flags_(flags_)
  , dark_(dark_)
  , channel_(std::move(channel_))
  , msg_id_(msg_id_)
{}

const std::int32_t stats_getMessageStats::ID;

void stats_getMessageStats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1226791947);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
}

void stats_getMessageStats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1226791947);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
}

void stats_getMessageStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getMessageStats");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0)));
    if (var0 & 1) { s.store_field("dark", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

stats_getMessageStats::ReturnType stats_getMessageStats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_messageStats>, 2145983508>::parse(p);
#undef FAIL
}

stickers_checkShortName::stickers_checkShortName(string const &short_name_)
  : short_name_(short_name_)
{}

const std::int32_t stickers_checkShortName::ID;

void stickers_checkShortName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(676017721);
  TlStoreString::store(short_name_, s);
}

void stickers_checkShortName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(676017721);
  TlStoreString::store(short_name_, s);
}

void stickers_checkShortName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.checkShortName");
    s.store_field("short_name", short_name_);
    s.store_class_end();
  }
}

stickers_checkShortName::ReturnType stickers_checkShortName::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stickers_suggestShortName::stickers_suggestShortName(string const &title_)
  : title_(title_)
{}

const std::int32_t stickers_suggestShortName::ID;

void stickers_suggestShortName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1303364867);
  TlStoreString::store(title_, s);
}

void stickers_suggestShortName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1303364867);
  TlStoreString::store(title_, s);
}

void stickers_suggestShortName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.suggestShortName");
    s.store_field("title", title_);
    s.store_class_end();
  }
}

stickers_suggestShortName::ReturnType stickers_suggestShortName::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stickers_suggestedShortName>, -2046910401>::parse(p);
#undef FAIL
}

stories_createAlbum::stories_createAlbum(object_ptr<InputPeer> &&peer_, string const &title_, array<int32> &&stories_)
  : peer_(std::move(peer_))
  , title_(title_)
  , stories_(std::move(stories_))
{}

const std::int32_t stories_createAlbum::ID;

void stories_createAlbum::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1553754395);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(stories_, s);
}

void stories_createAlbum::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1553754395);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(stories_, s);
}

void stories_createAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.createAlbum");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("title", title_);
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_createAlbum::ReturnType stories_createAlbum::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<storyAlbum>, -1826262950>::parse(p);
#undef FAIL
}

stories_deleteAlbum::stories_deleteAlbum(object_ptr<InputPeer> &&peer_, int32 album_id_)
  : peer_(std::move(peer_))
  , album_id_(album_id_)
{}

const std::int32_t stories_deleteAlbum::ID;

void stories_deleteAlbum::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1925949744);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(album_id_, s);
}

void stories_deleteAlbum::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1925949744);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(album_id_, s);
}

void stories_deleteAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.deleteAlbum");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("album_id", album_id_);
    s.store_class_end();
  }
}

stories_deleteAlbum::ReturnType stories_deleteAlbum::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stories_exportStoryLink::stories_exportStoryLink(object_ptr<InputPeer> &&peer_, int32 id_)
  : peer_(std::move(peer_))
  , id_(id_)
{}

const std::int32_t stories_exportStoryLink::ID;

void stories_exportStoryLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2072899360);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void stories_exportStoryLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2072899360);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void stories_exportStoryLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.exportStoryLink");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

stories_exportStoryLink::ReturnType stories_exportStoryLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<exportedStoryLink>, 1070138683>::parse(p);
#undef FAIL
}

stories_getAllStories::stories_getAllStories(int32 flags_, bool next_, bool hidden_, string const &state_)
  : flags_(flags_)
  , next_(next_)
  , hidden_(hidden_)
  , state_(state_)
{}

const std::int32_t stories_getAllStories::ID;

void stories_getAllStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-290400731);
  TlStoreBinary::store((var0 = flags_ | (next_ << 1) | (hidden_ << 2)), s);
  if (var0 & 1) { TlStoreString::store(state_, s); }
}

void stories_getAllStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-290400731);
  TlStoreBinary::store((var0 = flags_ | (next_ << 1) | (hidden_ << 2)), s);
  if (var0 & 1) { TlStoreString::store(state_, s); }
}

void stories_getAllStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getAllStories");
    s.store_field("flags", (var0 = flags_ | (next_ << 1) | (hidden_ << 2)));
    if (var0 & 2) { s.store_field("next", true); }
    if (var0 & 4) { s.store_field("hidden", true); }
    if (var0 & 1) { s.store_field("state", state_); }
    s.store_class_end();
  }
}

stories_getAllStories::ReturnType stories_getAllStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<stories_AllStories>::parse(p);
#undef FAIL
}

stories_togglePinnedToTop::stories_togglePinnedToTop(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t stories_togglePinnedToTop::ID;

void stories_togglePinnedToTop::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(187268763);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_togglePinnedToTop::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(187268763);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_togglePinnedToTop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.togglePinnedToTop");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_togglePinnedToTop::ReturnType stories_togglePinnedToTop::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t test_parseInputAppEvent::ID;

void test_parseInputAppEvent::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1156741135);
}

void test_parseInputAppEvent::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1156741135);
}

void test_parseInputAppEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "test.parseInputAppEvent");
    s.store_class_end();
  }
}

test_parseInputAppEvent::ReturnType test_parseInputAppEvent::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<inputAppEvent>, 488313413>::parse(p);
#undef FAIL
}

users_getSavedMusic::users_getSavedMusic(object_ptr<InputUser> &&id_, int32 offset_, int32 limit_, int64 hash_)
  : id_(std::move(id_))
  , offset_(offset_)
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t users_getSavedMusic::ID;

void users_getSavedMusic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2022539235);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void users_getSavedMusic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2022539235);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void users_getSavedMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.getSavedMusic");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

users_getSavedMusic::ReturnType users_getSavedMusic::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<users_SavedMusic>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
