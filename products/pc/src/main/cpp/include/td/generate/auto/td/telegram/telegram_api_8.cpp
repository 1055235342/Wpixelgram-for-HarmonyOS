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


botAppSettings::botAppSettings()
  : flags_()
  , placeholder_path_()
  , background_color_()
  , background_dark_color_()
  , header_color_()
  , header_dark_color_()
{}

const std::int32_t botAppSettings::ID;

object_ptr<botAppSettings> botAppSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botAppSettings> res = make_tl_object<botAppSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->placeholder_path_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 2) { res->background_color_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->background_dark_color_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->header_color_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->header_dark_color_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void botAppSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botAppSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_bytes_field("placeholder_path", placeholder_path_); }
    if (var0 & 2) { s.store_field("background_color", background_color_); }
    if (var0 & 4) { s.store_field("background_dark_color", background_dark_color_); }
    if (var0 & 8) { s.store_field("header_color", header_color_); }
    if (var0 & 16) { s.store_field("header_dark_color", header_dark_color_); }
    s.store_class_end();
  }
}

const std::int32_t botPreviewMedia::ID;

object_ptr<botPreviewMedia> botPreviewMedia::fetch(TlBufferParser &p) {
  return make_tl_object<botPreviewMedia>(p);
}

botPreviewMedia::botPreviewMedia(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
  , media_(TlFetchObject<MessageMedia>::parse(p))
{}

void botPreviewMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botPreviewMedia");
    s.store_field("date", date_);
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

businessBotRights::businessBotRights()
  : flags_()
  , reply_()
  , read_messages_()
  , delete_sent_messages_()
  , delete_received_messages_()
  , edit_name_()
  , edit_bio_()
  , edit_profile_photo_()
  , edit_username_()
  , view_gifts_()
  , sell_gifts_()
  , change_gift_settings_()
  , transfer_and_upgrade_gifts_()
  , transfer_stars_()
  , manage_stories_()
{}

businessBotRights::businessBotRights(int32 flags_, bool reply_, bool read_messages_, bool delete_sent_messages_, bool delete_received_messages_, bool edit_name_, bool edit_bio_, bool edit_profile_photo_, bool edit_username_, bool view_gifts_, bool sell_gifts_, bool change_gift_settings_, bool transfer_and_upgrade_gifts_, bool transfer_stars_, bool manage_stories_)
  : flags_(flags_)
  , reply_(reply_)
  , read_messages_(read_messages_)
  , delete_sent_messages_(delete_sent_messages_)
  , delete_received_messages_(delete_received_messages_)
  , edit_name_(edit_name_)
  , edit_bio_(edit_bio_)
  , edit_profile_photo_(edit_profile_photo_)
  , edit_username_(edit_username_)
  , view_gifts_(view_gifts_)
  , sell_gifts_(sell_gifts_)
  , change_gift_settings_(change_gift_settings_)
  , transfer_and_upgrade_gifts_(transfer_and_upgrade_gifts_)
  , transfer_stars_(transfer_stars_)
  , manage_stories_(manage_stories_)
{}

const std::int32_t businessBotRights::ID;

object_ptr<businessBotRights> businessBotRights::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessBotRights> res = make_tl_object<businessBotRights>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->reply_ = (var0 & 1) != 0;
  res->read_messages_ = (var0 & 2) != 0;
  res->delete_sent_messages_ = (var0 & 4) != 0;
  res->delete_received_messages_ = (var0 & 8) != 0;
  res->edit_name_ = (var0 & 16) != 0;
  res->edit_bio_ = (var0 & 32) != 0;
  res->edit_profile_photo_ = (var0 & 64) != 0;
  res->edit_username_ = (var0 & 128) != 0;
  res->view_gifts_ = (var0 & 256) != 0;
  res->sell_gifts_ = (var0 & 512) != 0;
  res->change_gift_settings_ = (var0 & 1024) != 0;
  res->transfer_and_upgrade_gifts_ = (var0 & 2048) != 0;
  res->transfer_stars_ = (var0 & 4096) != 0;
  res->manage_stories_ = (var0 & 8192) != 0;
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessBotRights::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (reply_ << 0) | (read_messages_ << 1) | (delete_sent_messages_ << 2) | (delete_received_messages_ << 3) | (edit_name_ << 4) | (edit_bio_ << 5) | (edit_profile_photo_ << 6) | (edit_username_ << 7) | (view_gifts_ << 8) | (sell_gifts_ << 9) | (change_gift_settings_ << 10) | (transfer_and_upgrade_gifts_ << 11) | (transfer_stars_ << 12) | (manage_stories_ << 13)), s);
}

void businessBotRights::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (reply_ << 0) | (read_messages_ << 1) | (delete_sent_messages_ << 2) | (delete_received_messages_ << 3) | (edit_name_ << 4) | (edit_bio_ << 5) | (edit_profile_photo_ << 6) | (edit_username_ << 7) | (view_gifts_ << 8) | (sell_gifts_ << 9) | (change_gift_settings_ << 10) | (transfer_and_upgrade_gifts_ << 11) | (transfer_stars_ << 12) | (manage_stories_ << 13)), s);
}

void businessBotRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessBotRights");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (reply_ << 0) | (read_messages_ << 1) | (delete_sent_messages_ << 2) | (delete_received_messages_ << 3) | (edit_name_ << 4) | (edit_bio_ << 5) | (edit_profile_photo_ << 6) | (edit_username_ << 7) | (view_gifts_ << 8) | (sell_gifts_ << 9) | (change_gift_settings_ << 10) | (transfer_and_upgrade_gifts_ << 11) | (transfer_stars_ << 12) | (manage_stories_ << 13)));
    if (var0 & 1) { s.store_field("reply", true); }
    if (var0 & 2) { s.store_field("read_messages", true); }
    if (var0 & 4) { s.store_field("delete_sent_messages", true); }
    if (var0 & 8) { s.store_field("delete_received_messages", true); }
    if (var0 & 16) { s.store_field("edit_name", true); }
    if (var0 & 32) { s.store_field("edit_bio", true); }
    if (var0 & 64) { s.store_field("edit_profile_photo", true); }
    if (var0 & 128) { s.store_field("edit_username", true); }
    if (var0 & 256) { s.store_field("view_gifts", true); }
    if (var0 & 512) { s.store_field("sell_gifts", true); }
    if (var0 & 1024) { s.store_field("change_gift_settings", true); }
    if (var0 & 2048) { s.store_field("transfer_and_upgrade_gifts", true); }
    if (var0 & 4096) { s.store_field("transfer_stars", true); }
    if (var0 & 8192) { s.store_field("manage_stories", true); }
    s.store_class_end();
  }
}

const std::int32_t dialogFilterSuggested::ID;

object_ptr<dialogFilterSuggested> dialogFilterSuggested::fetch(TlBufferParser &p) {
  return make_tl_object<dialogFilterSuggested>(p);
}

dialogFilterSuggested::dialogFilterSuggested(TlBufferParser &p)
  : filter_(TlFetchObject<DialogFilter>::parse(p))
  , description_(TlFetchString<string>::parse(p))
{}

void dialogFilterSuggested::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogFilterSuggested");
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("description", description_);
    s.store_class_end();
  }
}

object_ptr<EmojiList> EmojiList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case emojiListNotModified::ID:
      return emojiListNotModified::fetch(p);
    case emojiList::ID:
      return emojiList::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t emojiListNotModified::ID;

object_ptr<EmojiList> emojiListNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<emojiListNotModified>();
}

void emojiListNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiListNotModified");
    s.store_class_end();
  }
}

const std::int32_t emojiList::ID;

object_ptr<EmojiList> emojiList::fetch(TlBufferParser &p) {
  return make_tl_object<emojiList>(p);
}

emojiList::emojiList(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , document_id_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void emojiList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiList");
    s.store_field("hash", hash_);
    { s.store_vector_begin("document_id", document_id_.size()); for (const auto &_value : document_id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t folderPeer::ID;

object_ptr<folderPeer> folderPeer::fetch(TlBufferParser &p) {
  return make_tl_object<folderPeer>(p);
}

folderPeer::folderPeer(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , folder_id_(TlFetchInt::parse(p))
{}

void folderPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "folderPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("folder_id", folder_id_);
    s.store_class_end();
  }
}

object_ptr<ForumTopic> ForumTopic::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case forumTopicDeleted::ID:
      return forumTopicDeleted::fetch(p);
    case forumTopic::ID:
      return forumTopic::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t forumTopicDeleted::ID;

object_ptr<ForumTopic> forumTopicDeleted::fetch(TlBufferParser &p) {
  return make_tl_object<forumTopicDeleted>(p);
}

forumTopicDeleted::forumTopicDeleted(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
{}

void forumTopicDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forumTopicDeleted");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

forumTopic::forumTopic()
  : flags_()
  , my_()
  , closed_()
  , pinned_()
  , short_()
  , hidden_()
  , title_missing_()
  , id_()
  , date_()
  , peer_()
  , title_()
  , icon_color_()
  , icon_emoji_id_()
  , top_message_()
  , read_inbox_max_id_()
  , read_outbox_max_id_()
  , unread_count_()
  , unread_mentions_count_()
  , unread_reactions_count_()
  , unread_poll_votes_count_()
  , from_id_()
  , notify_settings_()
  , draft_()
{}

const std::int32_t forumTopic::ID;

object_ptr<ForumTopic> forumTopic::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<forumTopic> res = make_tl_object<forumTopic>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->my_ = (var0 & 2) != 0;
  res->closed_ = (var0 & 4) != 0;
  res->pinned_ = (var0 & 8) != 0;
  res->short_ = (var0 & 32) != 0;
  res->hidden_ = (var0 & 64) != 0;
  res->title_missing_ = (var0 & 128) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->icon_color_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->icon_emoji_id_ = TlFetchLong::parse(p); }
  res->top_message_ = TlFetchInt::parse(p);
  res->read_inbox_max_id_ = TlFetchInt::parse(p);
  res->read_outbox_max_id_ = TlFetchInt::parse(p);
  res->unread_count_ = TlFetchInt::parse(p);
  res->unread_mentions_count_ = TlFetchInt::parse(p);
  res->unread_reactions_count_ = TlFetchInt::parse(p);
  res->unread_poll_votes_count_ = TlFetchInt::parse(p);
  res->from_id_ = TlFetchObject<Peer>::parse(p);
  res->notify_settings_ = TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p);
  if (var0 & 16) { res->draft_ = TlFetchObject<DraftMessage>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void forumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "forumTopic");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (my_ << 1) | (closed_ << 2) | (pinned_ << 3) | (short_ << 5) | (hidden_ << 6) | (title_missing_ << 7)));
    if (var0 & 2) { s.store_field("my", true); }
    if (var0 & 4) { s.store_field("closed", true); }
    if (var0 & 8) { s.store_field("pinned", true); }
    if (var0 & 32) { s.store_field("short", true); }
    if (var0 & 64) { s.store_field("hidden", true); }
    if (var0 & 128) { s.store_field("title_missing", true); }
    s.store_field("id", id_);
    s.store_field("date", date_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("title", title_);
    s.store_field("icon_color", icon_color_);
    if (var0 & 1) { s.store_field("icon_emoji_id", icon_emoji_id_); }
    s.store_field("top_message", top_message_);
    s.store_field("read_inbox_max_id", read_inbox_max_id_);
    s.store_field("read_outbox_max_id", read_outbox_max_id_);
    s.store_field("unread_count", unread_count_);
    s.store_field("unread_mentions_count", unread_mentions_count_);
    s.store_field("unread_reactions_count", unread_reactions_count_);
    s.store_field("unread_poll_votes_count", unread_poll_votes_count_);
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    if (var0 & 16) { s.store_object_field("draft", static_cast<const BaseObject *>(draft_.get())); }
    s.store_class_end();
  }
}

inlineBotWebView::inlineBotWebView(string const &text_, string const &url_)
  : text_(text_)
  , url_(url_)
{}

const std::int32_t inlineBotWebView::ID;

object_ptr<inlineBotWebView> inlineBotWebView::fetch(TlBufferParser &p) {
  return make_tl_object<inlineBotWebView>(p);
}

inlineBotWebView::inlineBotWebView(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , url_(TlFetchString<string>::parse(p))
{}

void inlineBotWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void inlineBotWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void inlineBotWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineBotWebView");
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inputBotAppID::inputBotAppID(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputBotAppID::ID;

void inputBotAppID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputBotAppID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputBotAppID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotAppID");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputBotAppShortName::inputBotAppShortName(object_ptr<InputUser> &&bot_id_, string const &short_name_)
  : bot_id_(std::move(bot_id_))
  , short_name_(short_name_)
{}

const std::int32_t inputBotAppShortName::ID;

void inputBotAppShortName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_id_, s);
  TlStoreString::store(short_name_, s);
}

void inputBotAppShortName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_id_, s);
  TlStoreString::store(short_name_, s);
}

void inputBotAppShortName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotAppShortName");
    s.store_object_field("bot_id", static_cast<const BaseObject *>(bot_id_.get()));
    s.store_field("short_name", short_name_);
    s.store_class_end();
  }
}

object_ptr<InputGroupCall> InputGroupCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputGroupCall::ID:
      return inputGroupCall::fetch(p);
    case inputGroupCallSlug::ID:
      return inputGroupCallSlug::fetch(p);
    case inputGroupCallInviteMessage::ID:
      return inputGroupCallInviteMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputGroupCall::inputGroupCall(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputGroupCall::ID;

object_ptr<InputGroupCall> inputGroupCall::fetch(TlBufferParser &p) {
  return make_tl_object<inputGroupCall>(p);
}

inputGroupCall::inputGroupCall(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGroupCall");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputGroupCallSlug::inputGroupCallSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputGroupCallSlug::ID;

object_ptr<InputGroupCall> inputGroupCallSlug::fetch(TlBufferParser &p) {
  return make_tl_object<inputGroupCallSlug>(p);
}

inputGroupCallSlug::inputGroupCallSlug(TlBufferParser &p)
  : slug_(TlFetchString<string>::parse(p))
{}

void inputGroupCallSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputGroupCallSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputGroupCallSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGroupCallSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

inputGroupCallInviteMessage::inputGroupCallInviteMessage(int32 msg_id_)
  : msg_id_(msg_id_)
{}

const std::int32_t inputGroupCallInviteMessage::ID;

object_ptr<InputGroupCall> inputGroupCallInviteMessage::fetch(TlBufferParser &p) {
  return make_tl_object<inputGroupCallInviteMessage>(p);
}

inputGroupCallInviteMessage::inputGroupCallInviteMessage(TlBufferParser &p)
  : msg_id_(TlFetchInt::parse(p))
{}

void inputGroupCallInviteMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(msg_id_, s);
}

void inputGroupCallInviteMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(msg_id_, s);
}

void inputGroupCallInviteMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGroupCallInviteMessage");
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

inputPhoneCall::inputPhoneCall(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputPhoneCall::ID;

void inputPhoneCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputPhoneCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputPhoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhoneCall");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputSavedStarGiftUser::inputSavedStarGiftUser(int32 msg_id_)
  : msg_id_(msg_id_)
{}

const std::int32_t inputSavedStarGiftUser::ID;

void inputSavedStarGiftUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(msg_id_, s);
}

void inputSavedStarGiftUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(msg_id_, s);
}

void inputSavedStarGiftUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSavedStarGiftUser");
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

inputSavedStarGiftChat::inputSavedStarGiftChat(object_ptr<InputPeer> &&peer_, int64 saved_id_)
  : peer_(std::move(peer_))
  , saved_id_(saved_id_)
{}

const std::int32_t inputSavedStarGiftChat::ID;

void inputSavedStarGiftChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(saved_id_, s);
}

void inputSavedStarGiftChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(saved_id_, s);
}

void inputSavedStarGiftChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSavedStarGiftChat");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("saved_id", saved_id_);
    s.store_class_end();
  }
}

inputSavedStarGiftSlug::inputSavedStarGiftSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputSavedStarGiftSlug::ID;

void inputSavedStarGiftSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputSavedStarGiftSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputSavedStarGiftSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSavedStarGiftSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

messageRange::messageRange(int32 min_id_, int32 max_id_)
  : min_id_(min_id_)
  , max_id_(max_id_)
{}

const std::int32_t messageRange::ID;

object_ptr<messageRange> messageRange::fetch(TlBufferParser &p) {
  return make_tl_object<messageRange>(p);
}

messageRange::messageRange(TlBufferParser &p)
  : min_id_(TlFetchInt::parse(p))
  , max_id_(TlFetchInt::parse(p))
{}

void messageRange::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(max_id_, s);
}

void messageRange::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(max_id_, s);
}

void messageRange::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageRange");
    s.store_field("min_id", min_id_);
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

messageViews::messageViews()
  : flags_()
  , views_()
  , forwards_()
  , replies_()
{}

const std::int32_t messageViews::ID;

object_ptr<messageViews> messageViews::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageViews> res = make_tl_object<messageViews>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->views_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->forwards_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->replies_ = TlFetchBoxed<TlFetchObject<messageReplies>, -2083123262>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messageViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageViews");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("views", views_); }
    if (var0 & 2) { s.store_field("forwards", forwards_); }
    if (var0 & 4) { s.store_object_field("replies", static_cast<const BaseObject *>(replies_.get())); }
    s.store_class_end();
  }
}

const std::int32_t peerBlocked::ID;

object_ptr<peerBlocked> peerBlocked::fetch(TlBufferParser &p) {
  return make_tl_object<peerBlocked>(p);
}

peerBlocked::peerBlocked(TlBufferParser &p)
  : peer_id_(TlFetchObject<Peer>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void peerBlocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerBlocked");
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

object_ptr<PeerColor> PeerColor::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case peerColor::ID:
      return peerColor::fetch(p);
    case peerColorCollectible::ID:
      return peerColorCollectible::fetch(p);
    case inputPeerColorCollectible::ID:
      return inputPeerColorCollectible::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

peerColor::peerColor()
  : flags_()
  , color_()
  , background_emoji_id_()
{}

peerColor::peerColor(int32 flags_, int32 color_, int64 background_emoji_id_)
  : flags_(flags_)
  , color_(color_)
  , background_emoji_id_(background_emoji_id_)
{}

const std::int32_t peerColor::ID;

object_ptr<PeerColor> peerColor::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<peerColor> res = make_tl_object<peerColor>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->color_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->background_emoji_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void peerColor::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(color_, s); }
  if (var0 & 2) { TlStoreBinary::store(background_emoji_id_, s); }
}

void peerColor::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(color_, s); }
  if (var0 & 2) { TlStoreBinary::store(background_emoji_id_, s); }
}

void peerColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerColor");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("color", color_); }
    if (var0 & 2) { s.store_field("background_emoji_id", background_emoji_id_); }
    s.store_class_end();
  }
}

peerColorCollectible::peerColorCollectible()
  : flags_()
  , collectible_id_()
  , gift_emoji_id_()
  , background_emoji_id_()
  , accent_color_()
  , colors_()
  , dark_accent_color_()
  , dark_colors_()
{}

peerColorCollectible::peerColorCollectible(int32 flags_, int64 collectible_id_, int64 gift_emoji_id_, int64 background_emoji_id_, int32 accent_color_, array<int32> &&colors_, int32 dark_accent_color_, array<int32> &&dark_colors_)
  : flags_(flags_)
  , collectible_id_(collectible_id_)
  , gift_emoji_id_(gift_emoji_id_)
  , background_emoji_id_(background_emoji_id_)
  , accent_color_(accent_color_)
  , colors_(std::move(colors_))
  , dark_accent_color_(dark_accent_color_)
  , dark_colors_(std::move(dark_colors_))
{}

const std::int32_t peerColorCollectible::ID;

object_ptr<PeerColor> peerColorCollectible::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<peerColorCollectible> res = make_tl_object<peerColorCollectible>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collectible_id_ = TlFetchLong::parse(p);
  res->gift_emoji_id_ = TlFetchLong::parse(p);
  res->background_emoji_id_ = TlFetchLong::parse(p);
  res->accent_color_ = TlFetchInt::parse(p);
  res->colors_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  if (var0 & 1) { res->dark_accent_color_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->dark_colors_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void peerColorCollectible::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(collectible_id_, s);
  TlStoreBinary::store(gift_emoji_id_, s);
  TlStoreBinary::store(background_emoji_id_, s);
  TlStoreBinary::store(accent_color_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(colors_, s);
  if (var0 & 1) { TlStoreBinary::store(dark_accent_color_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(dark_colors_, s); }
}

void peerColorCollectible::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(collectible_id_, s);
  TlStoreBinary::store(gift_emoji_id_, s);
  TlStoreBinary::store(background_emoji_id_, s);
  TlStoreBinary::store(accent_color_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(colors_, s);
  if (var0 & 1) { TlStoreBinary::store(dark_accent_color_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(dark_colors_, s); }
}

void peerColorCollectible::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerColorCollectible");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("collectible_id", collectible_id_);
    s.store_field("gift_emoji_id", gift_emoji_id_);
    s.store_field("background_emoji_id", background_emoji_id_);
    s.store_field("accent_color", accent_color_);
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_field("", _value); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("dark_accent_color", dark_accent_color_); }
    if (var0 & 2) { { s.store_vector_begin("dark_colors", dark_colors_.size()); for (const auto &_value : dark_colors_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

inputPeerColorCollectible::inputPeerColorCollectible(int64 collectible_id_)
  : collectible_id_(collectible_id_)
{}

const std::int32_t inputPeerColorCollectible::ID;

object_ptr<PeerColor> inputPeerColorCollectible::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerColorCollectible>(p);
}

inputPeerColorCollectible::inputPeerColorCollectible(TlBufferParser &p)
  : collectible_id_(TlFetchLong::parse(p))
{}

void inputPeerColorCollectible::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(collectible_id_, s);
}

void inputPeerColorCollectible::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(collectible_id_, s);
}

void inputPeerColorCollectible::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerColorCollectible");
    s.store_field("collectible_id", collectible_id_);
    s.store_class_end();
  }
}

object_ptr<PeerLocated> PeerLocated::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case peerLocated::ID:
      return peerLocated::fetch(p);
    case peerSelfLocated::ID:
      return peerSelfLocated::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t peerLocated::ID;

object_ptr<PeerLocated> peerLocated::fetch(TlBufferParser &p) {
  return make_tl_object<peerLocated>(p);
}

peerLocated::peerLocated(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , expires_(TlFetchInt::parse(p))
  , distance_(TlFetchInt::parse(p))
{}

void peerLocated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerLocated");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("expires", expires_);
    s.store_field("distance", distance_);
    s.store_class_end();
  }
}

const std::int32_t peerSelfLocated::ID;

object_ptr<PeerLocated> peerSelfLocated::fetch(TlBufferParser &p) {
  return make_tl_object<peerSelfLocated>(p);
}

peerSelfLocated::peerSelfLocated(TlBufferParser &p)
  : expires_(TlFetchInt::parse(p))
{}

void peerSelfLocated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerSelfLocated");
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

peerStories::peerStories()
  : flags_()
  , peer_()
  , max_read_id_()
  , stories_()
{}

const std::int32_t peerStories::ID;

object_ptr<peerStories> peerStories::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<peerStories> res = make_tl_object<peerStories>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 1) { res->max_read_id_ = TlFetchInt::parse(p); }
  res->stories_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StoryItem>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void peerStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerStories");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("max_read_id", max_read_id_); }
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<ReactionNotificationsFrom> ReactionNotificationsFrom::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case reactionNotificationsFromContacts::ID:
      return reactionNotificationsFromContacts::fetch(p);
    case reactionNotificationsFromAll::ID:
      return reactionNotificationsFromAll::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t reactionNotificationsFromContacts::ID;

object_ptr<ReactionNotificationsFrom> reactionNotificationsFromContacts::fetch(TlBufferParser &p) {
  return make_tl_object<reactionNotificationsFromContacts>();
}

void reactionNotificationsFromContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void reactionNotificationsFromContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void reactionNotificationsFromContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionNotificationsFromContacts");
    s.store_class_end();
  }
}

const std::int32_t reactionNotificationsFromAll::ID;

object_ptr<ReactionNotificationsFrom> reactionNotificationsFromAll::fetch(TlBufferParser &p) {
  return make_tl_object<reactionNotificationsFromAll>();
}

void reactionNotificationsFromAll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void reactionNotificationsFromAll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void reactionNotificationsFromAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionNotificationsFromAll");
    s.store_class_end();
  }
}

starGiftBackground::starGiftBackground(int32 center_color_, int32 edge_color_, int32 text_color_)
  : center_color_(center_color_)
  , edge_color_(edge_color_)
  , text_color_(text_color_)
{}

const std::int32_t starGiftBackground::ID;

object_ptr<starGiftBackground> starGiftBackground::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftBackground>(p);
}

starGiftBackground::starGiftBackground(TlBufferParser &p)
  : center_color_(TlFetchInt::parse(p))
  , edge_color_(TlFetchInt::parse(p))
  , text_color_(TlFetchInt::parse(p))
{}

void starGiftBackground::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(center_color_, s);
  TlStoreBinary::store(edge_color_, s);
  TlStoreBinary::store(text_color_, s);
}

void starGiftBackground::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(center_color_, s);
  TlStoreBinary::store(edge_color_, s);
  TlStoreBinary::store(text_color_, s);
}

void starGiftBackground::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftBackground");
    s.store_field("center_color", center_color_);
    s.store_field("edge_color", edge_color_);
    s.store_field("text_color", text_color_);
    s.store_class_end();
  }
}

starRefProgram::starRefProgram()
  : flags_()
  , bot_id_()
  , commission_permille_()
  , duration_months_()
  , end_date_()
  , daily_revenue_per_user_()
{}

const std::int32_t starRefProgram::ID;

object_ptr<starRefProgram> starRefProgram::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starRefProgram> res = make_tl_object<starRefProgram>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bot_id_ = TlFetchLong::parse(p);
  res->commission_permille_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->duration_months_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->end_date_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->daily_revenue_per_user_ = TlFetchObject<StarsAmount>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starRefProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starRefProgram");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("bot_id", bot_id_);
    s.store_field("commission_permille", commission_permille_);
    if (var0 & 1) { s.store_field("duration_months", duration_months_); }
    if (var0 & 2) { s.store_field("end_date", end_date_); }
    if (var0 & 4) { s.store_object_field("daily_revenue_per_user", static_cast<const BaseObject *>(daily_revenue_per_user_.get())); }
    s.store_class_end();
  }
}

starsGiveawayOption::starsGiveawayOption()
  : flags_()
  , extended_()
  , default_()
  , stars_()
  , yearly_boosts_()
  , store_product_()
  , currency_()
  , amount_()
  , winners_()
{}

const std::int32_t starsGiveawayOption::ID;

object_ptr<starsGiveawayOption> starsGiveawayOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsGiveawayOption> res = make_tl_object<starsGiveawayOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->extended_ = (var0 & 1) != 0;
  res->default_ = (var0 & 2) != 0;
  res->stars_ = TlFetchLong::parse(p);
  res->yearly_boosts_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->store_product_ = TlFetchString<string>::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->winners_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starsGiveawayWinnersOption>, 1411605001>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsGiveawayOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsGiveawayOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (extended_ << 0) | (default_ << 1)));
    if (var0 & 1) { s.store_field("extended", true); }
    if (var0 & 2) { s.store_field("default", true); }
    s.store_field("stars", stars_);
    s.store_field("yearly_boosts", yearly_boosts_);
    if (var0 & 4) { s.store_field("store_product", store_product_); }
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    { s.store_vector_begin("winners", winners_.size()); for (const auto &_value : winners_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starsGiveawayWinnersOption::starsGiveawayWinnersOption()
  : flags_()
  , default_()
  , users_()
  , per_user_stars_()
{}

const std::int32_t starsGiveawayWinnersOption::ID;

object_ptr<starsGiveawayWinnersOption> starsGiveawayWinnersOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsGiveawayWinnersOption> res = make_tl_object<starsGiveawayWinnersOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->default_ = (var0 & 1) != 0;
  res->users_ = TlFetchInt::parse(p);
  res->per_user_stars_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsGiveawayWinnersOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsGiveawayWinnersOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (default_ << 0)));
    if (var0 & 1) { s.store_field("default", true); }
    s.store_field("users", users_);
    s.store_field("per_user_stars", per_user_stars_);
    s.store_class_end();
  }
}

const std::int32_t statsAbsValueAndPrev::ID;

object_ptr<statsAbsValueAndPrev> statsAbsValueAndPrev::fetch(TlBufferParser &p) {
  return make_tl_object<statsAbsValueAndPrev>(p);
}

statsAbsValueAndPrev::statsAbsValueAndPrev(TlBufferParser &p)
  : current_(TlFetchDouble::parse(p))
  , previous_(TlFetchDouble::parse(p))
{}

void statsAbsValueAndPrev::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsAbsValueAndPrev");
    s.store_field("current", current_);
    s.store_field("previous", previous_);
    s.store_class_end();
  }
}

stickerSet::stickerSet()
  : flags_()
  , archived_()
  , official_()
  , masks_()
  , emojis_()
  , text_color_()
  , channel_emoji_status_()
  , creator_()
  , installed_date_()
  , id_()
  , access_hash_()
  , title_()
  , short_name_()
  , thumbs_()
  , thumb_dc_id_()
  , thumb_version_()
  , thumb_document_id_()
  , count_()
  , hash_()
{}

const std::int32_t stickerSet::ID;

object_ptr<stickerSet> stickerSet::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stickerSet> res = make_tl_object<stickerSet>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->archived_ = (var0 & 2) != 0;
  res->official_ = (var0 & 4) != 0;
  res->masks_ = (var0 & 8) != 0;
  res->emojis_ = (var0 & 128) != 0;
  res->text_color_ = (var0 & 512) != 0;
  res->channel_emoji_status_ = (var0 & 1024) != 0;
  res->creator_ = (var0 & 2048) != 0;
  if (var0 & 1) { res->installed_date_ = TlFetchInt::parse(p); }
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->short_name_ = TlFetchString<string>::parse(p);
  if (var0 & 16) { res->thumbs_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PhotoSize>>, 481674261>::parse(p); }
  if (var0 & 16) { res->thumb_dc_id_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->thumb_version_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->thumb_document_id_ = TlFetchLong::parse(p); }
  res->count_ = TlFetchInt::parse(p);
  res->hash_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void stickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSet");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (archived_ << 1) | (official_ << 2) | (masks_ << 3) | (emojis_ << 7) | (text_color_ << 9) | (channel_emoji_status_ << 10) | (creator_ << 11)));
    if (var0 & 2) { s.store_field("archived", true); }
    if (var0 & 4) { s.store_field("official", true); }
    if (var0 & 8) { s.store_field("masks", true); }
    if (var0 & 128) { s.store_field("emojis", true); }
    if (var0 & 512) { s.store_field("text_color", true); }
    if (var0 & 1024) { s.store_field("channel_emoji_status", true); }
    if (var0 & 2048) { s.store_field("creator", true); }
    if (var0 & 1) { s.store_field("installed_date", installed_date_); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("title", title_);
    s.store_field("short_name", short_name_);
    if (var0 & 16) { { s.store_vector_begin("thumbs", thumbs_.size()); for (const auto &_value : thumbs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("thumb_dc_id", thumb_dc_id_); }
    if (var0 & 16) { s.store_field("thumb_version", thumb_version_); }
    if (var0 & 256) { s.store_field("thumb_document_id", thumb_document_id_); }
    s.store_field("count", count_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

const std::int32_t timezone::ID;

object_ptr<timezone> timezone::fetch(TlBufferParser &p) {
  return make_tl_object<timezone>(p);
}

timezone::timezone(TlBufferParser &p)
  : id_(TlFetchString<string>::parse(p))
  , name_(TlFetchString<string>::parse(p))
  , utc_offset_(TlFetchInt::parse(p))
{}

void timezone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "timezone");
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_field("utc_offset", utc_offset_);
    s.store_class_end();
  }
}

webViewMessageSent::webViewMessageSent()
  : flags_()
  , msg_id_()
{}

const std::int32_t webViewMessageSent::ID;

object_ptr<webViewMessageSent> webViewMessageSent::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webViewMessageSent> res = make_tl_object<webViewMessageSent>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->msg_id_ = TlFetchObject<InputBotInlineMessageID>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void webViewMessageSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webViewMessageSent");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("msg_id", static_cast<const BaseObject *>(msg_id_.get())); }
    s.store_class_end();
  }
}

const std::int32_t account_autoSaveSettings::ID;

object_ptr<account_autoSaveSettings> account_autoSaveSettings::fetch(TlBufferParser &p) {
  return make_tl_object<account_autoSaveSettings>(p);
}

account_autoSaveSettings::account_autoSaveSettings(TlBufferParser &p)
  : users_settings_(TlFetchBoxed<TlFetchObject<autoSaveSettings>, -934791986>::parse(p))
  , chats_settings_(TlFetchBoxed<TlFetchObject<autoSaveSettings>, -934791986>::parse(p))
  , broadcasts_settings_(TlFetchBoxed<TlFetchObject<autoSaveSettings>, -934791986>::parse(p))
  , exceptions_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<autoSaveException>, -2124403385>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void account_autoSaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.autoSaveSettings");
    s.store_object_field("users_settings", static_cast<const BaseObject *>(users_settings_.get()));
    s.store_object_field("chats_settings", static_cast<const BaseObject *>(chats_settings_.get()));
    s.store_object_field("broadcasts_settings", static_cast<const BaseObject *>(broadcasts_settings_.get()));
    { s.store_vector_begin("exceptions", exceptions_.size()); for (const auto &_value : exceptions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t account_privacyRules::ID;

object_ptr<account_privacyRules> account_privacyRules::fetch(TlBufferParser &p) {
  return make_tl_object<account_privacyRules>(p);
}

account_privacyRules::account_privacyRules(TlBufferParser &p)
  : rules_(TlFetchBoxed<TlFetchVector<TlFetchObject<PrivacyRule>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void account_privacyRules::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.privacyRules");
    { s.store_vector_begin("rules", rules_.size()); for (const auto &_value : rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t account_sentEmailCode::ID;

object_ptr<account_sentEmailCode> account_sentEmailCode::fetch(TlBufferParser &p) {
  return make_tl_object<account_sentEmailCode>(p);
}

account_sentEmailCode::account_sentEmailCode(TlBufferParser &p)
  : email_pattern_(TlFetchString<string>::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void account_sentEmailCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.sentEmailCode");
    s.store_field("email_pattern", email_pattern_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

object_ptr<account_Themes> account_Themes::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_themesNotModified::ID:
      return account_themesNotModified::fetch(p);
    case account_themes::ID:
      return account_themes::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_themesNotModified::ID;

object_ptr<account_Themes> account_themesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_themesNotModified>();
}

void account_themesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.themesNotModified");
    s.store_class_end();
  }
}

const std::int32_t account_themes::ID;

object_ptr<account_Themes> account_themes::fetch(TlBufferParser &p) {
  return make_tl_object<account_themes>(p);
}

account_themes::account_themes(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , themes_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<theme>, -1609668650>>, 481674261>::parse(p))
{}

void account_themes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.themes");
    s.store_field("hash", hash_);
    { s.store_vector_begin("themes", themes_.size()); for (const auto &_value : themes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<auth_CodeType> auth_CodeType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case auth_codeTypeSms::ID:
      return auth_codeTypeSms::fetch(p);
    case auth_codeTypeCall::ID:
      return auth_codeTypeCall::fetch(p);
    case auth_codeTypeFlashCall::ID:
      return auth_codeTypeFlashCall::fetch(p);
    case auth_codeTypeMissedCall::ID:
      return auth_codeTypeMissedCall::fetch(p);
    case auth_codeTypeFragmentSms::ID:
      return auth_codeTypeFragmentSms::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t auth_codeTypeSms::ID;

object_ptr<auth_CodeType> auth_codeTypeSms::fetch(TlBufferParser &p) {
  return make_tl_object<auth_codeTypeSms>();
}

void auth_codeTypeSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.codeTypeSms");
    s.store_class_end();
  }
}

const std::int32_t auth_codeTypeCall::ID;

object_ptr<auth_CodeType> auth_codeTypeCall::fetch(TlBufferParser &p) {
  return make_tl_object<auth_codeTypeCall>();
}

void auth_codeTypeCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.codeTypeCall");
    s.store_class_end();
  }
}

const std::int32_t auth_codeTypeFlashCall::ID;

object_ptr<auth_CodeType> auth_codeTypeFlashCall::fetch(TlBufferParser &p) {
  return make_tl_object<auth_codeTypeFlashCall>();
}

void auth_codeTypeFlashCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.codeTypeFlashCall");
    s.store_class_end();
  }
}

const std::int32_t auth_codeTypeMissedCall::ID;

object_ptr<auth_CodeType> auth_codeTypeMissedCall::fetch(TlBufferParser &p) {
  return make_tl_object<auth_codeTypeMissedCall>();
}

void auth_codeTypeMissedCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.codeTypeMissedCall");
    s.store_class_end();
  }
}

const std::int32_t auth_codeTypeFragmentSms::ID;

object_ptr<auth_CodeType> auth_codeTypeFragmentSms::fetch(TlBufferParser &p) {
  return make_tl_object<auth_codeTypeFragmentSms>();
}

void auth_codeTypeFragmentSms::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.codeTypeFragmentSms");
    s.store_class_end();
  }
}

bots_popularAppBots::bots_popularAppBots()
  : flags_()
  , next_offset_()
  , users_()
{}

const std::int32_t bots_popularAppBots::ID;

object_ptr<bots_popularAppBots> bots_popularAppBots::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<bots_popularAppBots> res = make_tl_object<bots_popularAppBots>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void bots_popularAppBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.popularAppBots");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

contacts_contactBirthdays::contacts_contactBirthdays(array<object_ptr<contactBirthday>> &&contacts_, array<object_ptr<User>> &&users_)
  : contacts_(std::move(contacts_))
  , users_(std::move(users_))
{}

const std::int32_t contacts_contactBirthdays::ID;

object_ptr<contacts_contactBirthdays> contacts_contactBirthdays::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_contactBirthdays>(p);
}

contacts_contactBirthdays::contacts_contactBirthdays(TlBufferParser &p)
  : contacts_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<contactBirthday>, 496600883>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_contactBirthdays::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.contactBirthdays");
    { s.store_vector_begin("contacts", contacts_.size()); for (const auto &_value : contacts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<help_CountriesList> help_CountriesList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_countriesListNotModified::ID:
      return help_countriesListNotModified::fetch(p);
    case help_countriesList::ID:
      return help_countriesList::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_countriesListNotModified::ID;

object_ptr<help_CountriesList> help_countriesListNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<help_countriesListNotModified>();
}

void help_countriesListNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.countriesListNotModified");
    s.store_class_end();
  }
}

const std::int32_t help_countriesList::ID;

object_ptr<help_CountriesList> help_countriesList::fetch(TlBufferParser &p) {
  return make_tl_object<help_countriesList>(p);
}

help_countriesList::help_countriesList(TlBufferParser &p)
  : countries_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<help_country>, -1014526429>>, 481674261>::parse(p))
  , hash_(TlFetchInt::parse(p))
{}

void help_countriesList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.countriesList");
    { s.store_vector_begin("countries", countries_.size()); for (const auto &_value : countries_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

const std::int32_t help_inviteText::ID;

object_ptr<help_inviteText> help_inviteText::fetch(TlBufferParser &p) {
  return make_tl_object<help_inviteText>(p);
}

help_inviteText::help_inviteText(TlBufferParser &p)
  : message_(TlFetchString<string>::parse(p))
{}

void help_inviteText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.inviteText");
    s.store_field("message", message_);
    s.store_class_end();
  }
}

object_ptr<help_UserInfo> help_UserInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_userInfoEmpty::ID:
      return help_userInfoEmpty::fetch(p);
    case help_userInfo::ID:
      return help_userInfo::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_userInfoEmpty::ID;

object_ptr<help_UserInfo> help_userInfoEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<help_userInfoEmpty>();
}

void help_userInfoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.userInfoEmpty");
    s.store_class_end();
  }
}

const std::int32_t help_userInfo::ID;

object_ptr<help_UserInfo> help_userInfo::fetch(TlBufferParser &p) {
  return make_tl_object<help_userInfo>(p);
}

help_userInfo::help_userInfo(TlBufferParser &p)
  : message_(TlFetchString<string>::parse(p))
  , entities_(TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p))
  , author_(TlFetchString<string>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void help_userInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.userInfo");
    s.store_field("message", message_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("author", author_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t messages_affectedFoundMessages::ID;

object_ptr<messages_affectedFoundMessages> messages_affectedFoundMessages::fetch(TlBufferParser &p) {
  return make_tl_object<messages_affectedFoundMessages>(p);
}

messages_affectedFoundMessages::messages_affectedFoundMessages(TlBufferParser &p)
  : pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
  , offset_(TlFetchInt::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void messages_affectedFoundMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.affectedFoundMessages");
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_field("offset", offset_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_archivedStickers::ID;

object_ptr<messages_archivedStickers> messages_archivedStickers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_archivedStickers>(p);
}

messages_archivedStickers::messages_archivedStickers(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , sets_(TlFetchBoxed<TlFetchVector<TlFetchObject<StickerSetCovered>>, 481674261>::parse(p))
{}

void messages_archivedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.archivedStickers");
    s.store_field("count", count_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_EmojiGameInfo> messages_EmojiGameInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_emojiGameUnavailable::ID:
      return messages_emojiGameUnavailable::fetch(p);
    case messages_emojiGameDiceInfo::ID:
      return messages_emojiGameDiceInfo::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_emojiGameUnavailable::ID;

object_ptr<messages_EmojiGameInfo> messages_emojiGameUnavailable::fetch(TlBufferParser &p) {
  return make_tl_object<messages_emojiGameUnavailable>();
}

void messages_emojiGameUnavailable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.emojiGameUnavailable");
    s.store_class_end();
  }
}

messages_emojiGameDiceInfo::messages_emojiGameDiceInfo()
  : flags_()
  , game_hash_()
  , prev_stake_()
  , current_streak_()
  , params_()
  , plays_left_()
{}

const std::int32_t messages_emojiGameDiceInfo::ID;

object_ptr<messages_EmojiGameInfo> messages_emojiGameDiceInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_emojiGameDiceInfo> res = make_tl_object<messages_emojiGameDiceInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->game_hash_ = TlFetchString<string>::parse(p);
  res->prev_stake_ = TlFetchLong::parse(p);
  res->current_streak_ = TlFetchInt::parse(p);
  res->params_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  if (var0 & 1) { res->plays_left_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_emojiGameDiceInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.emojiGameDiceInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("game_hash", game_hash_);
    s.store_field("prev_stake", prev_stake_);
    s.store_field("current_streak", current_streak_);
    { s.store_vector_begin("params", params_.size()); for (const auto &_value : params_) { s.store_field("", _value); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("plays_left", plays_left_); }
    s.store_class_end();
  }
}

object_ptr<messages_FavedStickers> messages_FavedStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_favedStickersNotModified::ID:
      return messages_favedStickersNotModified::fetch(p);
    case messages_favedStickers::ID:
      return messages_favedStickers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_favedStickersNotModified::ID;

object_ptr<messages_FavedStickers> messages_favedStickersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_favedStickersNotModified>();
}

void messages_favedStickersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.favedStickersNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_favedStickers::ID;

object_ptr<messages_FavedStickers> messages_favedStickers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_favedStickers>(p);
}

messages_favedStickers::messages_favedStickers(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , packs_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerPack>, 313694676>>, 481674261>::parse(p))
  , stickers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void messages_favedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.favedStickers");
    s.store_field("hash", hash_);
    { s.store_vector_begin("packs", packs_.size()); for (const auto &_value : packs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_StickerSetInstallResult> messages_StickerSetInstallResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_stickerSetInstallResultSuccess::ID:
      return messages_stickerSetInstallResultSuccess::fetch(p);
    case messages_stickerSetInstallResultArchive::ID:
      return messages_stickerSetInstallResultArchive::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_stickerSetInstallResultSuccess::ID;

object_ptr<messages_StickerSetInstallResult> messages_stickerSetInstallResultSuccess::fetch(TlBufferParser &p) {
  return make_tl_object<messages_stickerSetInstallResultSuccess>();
}

void messages_stickerSetInstallResultSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.stickerSetInstallResultSuccess");
    s.store_class_end();
  }
}

const std::int32_t messages_stickerSetInstallResultArchive::ID;

object_ptr<messages_StickerSetInstallResult> messages_stickerSetInstallResultArchive::fetch(TlBufferParser &p) {
  return make_tl_object<messages_stickerSetInstallResultArchive>(p);
}

messages_stickerSetInstallResultArchive::messages_stickerSetInstallResultArchive(TlBufferParser &p)
  : sets_(TlFetchBoxed<TlFetchVector<TlFetchObject<StickerSetCovered>>, 481674261>::parse(p))
{}

void messages_stickerSetInstallResultArchive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.stickerSetInstallResultArchive");
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_webPagePreview::ID;

object_ptr<messages_webPagePreview> messages_webPagePreview::fetch(TlBufferParser &p) {
  return make_tl_object<messages_webPagePreview>(p);
}

messages_webPagePreview::messages_webPagePreview(TlBufferParser &p)
  : media_(TlFetchObject<MessageMedia>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_webPagePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.webPagePreview");
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_connectedStarRefBots::ID;

object_ptr<payments_connectedStarRefBots> payments_connectedStarRefBots::fetch(TlBufferParser &p) {
  return make_tl_object<payments_connectedStarRefBots>(p);
}

payments_connectedStarRefBots::payments_connectedStarRefBots(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , connected_bots_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<connectedBotStarRef>, 429997937>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void payments_connectedStarRefBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.connectedStarRefBots");
    s.store_field("count", count_);
    { s.store_vector_begin("connected_bots", connected_bots_.size()); for (const auto &_value : connected_bots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_exportedInvoice::ID;

object_ptr<payments_exportedInvoice> payments_exportedInvoice::fetch(TlBufferParser &p) {
  return make_tl_object<payments_exportedInvoice>(p);
}

payments_exportedInvoice::payments_exportedInvoice(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void payments_exportedInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.exportedInvoice");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

payments_savedInfo::payments_savedInfo()
  : flags_()
  , has_saved_credentials_()
  , saved_info_()
{}

const std::int32_t payments_savedInfo::ID;

object_ptr<payments_savedInfo> payments_savedInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_savedInfo> res = make_tl_object<payments_savedInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_saved_credentials_ = (var0 & 2) != 0;
  if (var0 & 1) { res->saved_info_ = TlFetchBoxed<TlFetchObject<paymentRequestedInfo>, -1868808300>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_savedInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.savedInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_saved_credentials_ << 1)));
    if (var0 & 2) { s.store_field("has_saved_credentials", true); }
    if (var0 & 1) { s.store_object_field("saved_info", static_cast<const BaseObject *>(saved_info_.get())); }
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftUpgradePreview::ID;

object_ptr<payments_starGiftUpgradePreview> payments_starGiftUpgradePreview::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftUpgradePreview>(p);
}

payments_starGiftUpgradePreview::payments_starGiftUpgradePreview(TlBufferParser &p)
  : sample_attributes_(TlFetchBoxed<TlFetchVector<TlFetchObject<StarGiftAttribute>>, 481674261>::parse(p))
  , prices_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starGiftUpgradePrice>, -1712704739>>, 481674261>::parse(p))
  , next_prices_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starGiftUpgradePrice>, -1712704739>>, 481674261>::parse(p))
{}

void payments_starGiftUpgradePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftUpgradePreview");
    { s.store_vector_begin("sample_attributes", sample_attributes_.size()); for (const auto &_value : sample_attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("prices", prices_.size()); for (const auto &_value : prices_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("next_prices", next_prices_.size()); for (const auto &_value : next_prices_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t phone_groupCallStreamRtmpUrl::ID;

object_ptr<phone_groupCallStreamRtmpUrl> phone_groupCallStreamRtmpUrl::fetch(TlBufferParser &p) {
  return make_tl_object<phone_groupCallStreamRtmpUrl>(p);
}

phone_groupCallStreamRtmpUrl::phone_groupCallStreamRtmpUrl(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , key_(TlFetchString<string>::parse(p))
{}

void phone_groupCallStreamRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.groupCallStreamRtmpUrl");
    s.store_field("url", url_);
    s.store_field("key", key_);
    s.store_class_end();
  }
}

phone_groupParticipants::phone_groupParticipants(int32 count_, array<object_ptr<groupCallParticipant>> &&participants_, string const &next_offset_, array<object_ptr<Chat>> &&chats_, array<object_ptr<User>> &&users_, int32 version_)
  : count_(count_)
  , participants_(std::move(participants_))
  , next_offset_(next_offset_)
  , chats_(std::move(chats_))
  , users_(std::move(users_))
  , version_(version_)
{}

const std::int32_t phone_groupParticipants::ID;

object_ptr<phone_groupParticipants> phone_groupParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<phone_groupParticipants>(p);
}

phone_groupParticipants::phone_groupParticipants(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , participants_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<groupCallParticipant>, 708691884>>, 481674261>::parse(p))
  , next_offset_(TlFetchString<string>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void phone_groupParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.groupParticipants");
    s.store_field("count", count_);
    { s.store_vector_begin("participants", participants_.size()); for (const auto &_value : participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("version", version_);
    s.store_class_end();
  }
}

object_ptr<stories_Albums> stories_Albums::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case stories_albumsNotModified::ID:
      return stories_albumsNotModified::fetch(p);
    case stories_albums::ID:
      return stories_albums::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t stories_albumsNotModified::ID;

object_ptr<stories_Albums> stories_albumsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<stories_albumsNotModified>();
}

void stories_albumsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.albumsNotModified");
    s.store_class_end();
  }
}

const std::int32_t stories_albums::ID;

object_ptr<stories_Albums> stories_albums::fetch(TlBufferParser &p) {
  return make_tl_object<stories_albums>(p);
}

stories_albums::stories_albums(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , albums_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<storyAlbum>, -1826262950>>, 481674261>::parse(p))
{}

void stories_albums::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.albums");
    s.store_field("hash", hash_);
    { s.store_vector_begin("albums", albums_.size()); for (const auto &_value : albums_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_storyReactionsList::stories_storyReactionsList()
  : flags_()
  , count_()
  , reactions_()
  , chats_()
  , users_()
  , next_offset_()
{}

const std::int32_t stories_storyReactionsList::ID;

object_ptr<stories_storyReactionsList> stories_storyReactionsList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stories_storyReactionsList> res = make_tl_object<stories_storyReactionsList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->reactions_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StoryReaction>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void stories_storyReactionsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.storyReactionsList");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("count", count_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

object_ptr<updates_ChannelDifference> updates_ChannelDifference::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case updates_channelDifferenceEmpty::ID:
      return updates_channelDifferenceEmpty::fetch(p);
    case updates_channelDifferenceTooLong::ID:
      return updates_channelDifferenceTooLong::fetch(p);
    case updates_channelDifference::ID:
      return updates_channelDifference::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

updates_channelDifferenceEmpty::updates_channelDifferenceEmpty()
  : flags_()
  , final_()
  , pts_()
  , timeout_()
{}

const std::int32_t updates_channelDifferenceEmpty::ID;

object_ptr<updates_ChannelDifference> updates_channelDifferenceEmpty::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updates_channelDifferenceEmpty> res = make_tl_object<updates_channelDifferenceEmpty>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->final_ = (var0 & 1) != 0;
  res->pts_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->timeout_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updates_channelDifferenceEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.channelDifferenceEmpty");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (final_ << 0)));
    if (var0 & 1) { s.store_field("final", true); }
    s.store_field("pts", pts_);
    if (var0 & 2) { s.store_field("timeout", timeout_); }
    s.store_class_end();
  }
}

updates_channelDifferenceTooLong::updates_channelDifferenceTooLong()
  : flags_()
  , final_()
  , timeout_()
  , dialog_()
  , messages_()
  , chats_()
  , users_()
{}

const std::int32_t updates_channelDifferenceTooLong::ID;

object_ptr<updates_ChannelDifference> updates_channelDifferenceTooLong::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updates_channelDifferenceTooLong> res = make_tl_object<updates_channelDifferenceTooLong>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->final_ = (var0 & 1) != 0;
  if (var0 & 2) { res->timeout_ = TlFetchInt::parse(p); }
  res->dialog_ = TlFetchObject<Dialog>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updates_channelDifferenceTooLong::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.channelDifferenceTooLong");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (final_ << 0)));
    if (var0 & 1) { s.store_field("final", true); }
    if (var0 & 2) { s.store_field("timeout", timeout_); }
    s.store_object_field("dialog", static_cast<const BaseObject *>(dialog_.get()));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updates_channelDifference::updates_channelDifference()
  : flags_()
  , final_()
  , pts_()
  , timeout_()
  , new_messages_()
  , other_updates_()
  , chats_()
  , users_()
{}

const std::int32_t updates_channelDifference::ID;

object_ptr<updates_ChannelDifference> updates_channelDifference::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updates_channelDifference> res = make_tl_object<updates_channelDifference>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->final_ = (var0 & 1) != 0;
  res->pts_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->timeout_ = TlFetchInt::parse(p); }
  res->new_messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->other_updates_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Update>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updates_channelDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.channelDifference");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (final_ << 0)));
    if (var0 & 1) { s.store_field("final", true); }
    s.store_field("pts", pts_);
    if (var0 & 2) { s.store_field("timeout", timeout_); }
    { s.store_vector_begin("new_messages", new_messages_.size()); for (const auto &_value : new_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("other_updates", other_updates_.size()); for (const auto &_value : other_updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t account_cancelPasswordEmail::ID;

void account_cancelPasswordEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1043606090);
}

void account_cancelPasswordEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1043606090);
}

void account_cancelPasswordEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.cancelPasswordEmail");
    s.store_class_end();
  }
}

account_cancelPasswordEmail::ReturnType account_cancelPasswordEmail::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_checkUsername::account_checkUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t account_checkUsername::ID;

void account_checkUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(655677548);
  TlStoreString::store(username_, s);
}

void account_checkUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(655677548);
  TlStoreString::store(username_, s);
}

void account_checkUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.checkUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

account_checkUsername::ReturnType account_checkUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_getAutoSaveSettings::ID;

void account_getAutoSaveSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1379156774);
}

void account_getAutoSaveSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1379156774);
}

void account_getAutoSaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getAutoSaveSettings");
    s.store_class_end();
  }
}

account_getAutoSaveSettings::ReturnType account_getAutoSaveSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_autoSaveSettings>, 1279133341>::parse(p);
#undef FAIL
}

account_getChannelDefaultEmojiStatuses::account_getChannelDefaultEmojiStatuses(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getChannelDefaultEmojiStatuses::ID;

void account_getChannelDefaultEmojiStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1999087573);
  TlStoreBinary::store(hash_, s);
}

void account_getChannelDefaultEmojiStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1999087573);
  TlStoreBinary::store(hash_, s);
}

void account_getChannelDefaultEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getChannelDefaultEmojiStatuses");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getChannelDefaultEmojiStatuses::ReturnType account_getChannelDefaultEmojiStatuses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_EmojiStatuses>::parse(p);
#undef FAIL
}

account_getChatThemes::account_getChatThemes(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getChatThemes::ID;

void account_getChatThemes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-700916087);
  TlStoreBinary::store(hash_, s);
}

void account_getChatThemes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-700916087);
  TlStoreBinary::store(hash_, s);
}

void account_getChatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getChatThemes");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getChatThemes::ReturnType account_getChatThemes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_Themes>::parse(p);
#undef FAIL
}

account_getDefaultProfilePhotoEmojis::account_getDefaultProfilePhotoEmojis(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getDefaultProfilePhotoEmojis::ID;

void account_getDefaultProfilePhotoEmojis::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-495647960);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultProfilePhotoEmojis::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-495647960);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultProfilePhotoEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getDefaultProfilePhotoEmojis");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getDefaultProfilePhotoEmojis::ReturnType account_getDefaultProfilePhotoEmojis::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EmojiList>::parse(p);
#undef FAIL
}

account_getPaidMessagesRevenue::account_getPaidMessagesRevenue(int32 flags_, object_ptr<InputPeer> &&parent_peer_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , parent_peer_(std::move(parent_peer_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t account_getPaidMessagesRevenue::ID;

void account_getPaidMessagesRevenue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(431639143);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void account_getPaidMessagesRevenue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(431639143);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void account_getPaidMessagesRevenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getPaidMessagesRevenue");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

account_getPaidMessagesRevenue::ReturnType account_getPaidMessagesRevenue::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_paidMessagesRevenue>, 504403720>::parse(p);
#undef FAIL
}

account_getPrivacy::account_getPrivacy(object_ptr<InputPrivacyKey> &&key_)
  : key_(std::move(key_))
{}

const std::int32_t account_getPrivacy::ID;

void account_getPrivacy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-623130288);
  TlStoreBoxedUnknown<TlStoreObject>::store(key_, s);
}

void account_getPrivacy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-623130288);
  TlStoreBoxedUnknown<TlStoreObject>::store(key_, s);
}

void account_getPrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getPrivacy");
    s.store_object_field("key", static_cast<const BaseObject *>(key_.get()));
    s.store_class_end();
  }
}

account_getPrivacy::ReturnType account_getPrivacy::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_privacyRules>, 1352683077>::parse(p);
#undef FAIL
}

account_getThemes::account_getThemes(string const &format_, int64 hash_)
  : format_(format_)
  , hash_(hash_)
{}

const std::int32_t account_getThemes::ID;

void account_getThemes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1913054296);
  TlStoreString::store(format_, s);
  TlStoreBinary::store(hash_, s);
}

void account_getThemes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1913054296);
  TlStoreString::store(format_, s);
  TlStoreBinary::store(hash_, s);
}

void account_getThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getThemes");
    s.store_field("format", format_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getThemes::ReturnType account_getThemes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_Themes>::parse(p);
#undef FAIL
}

account_registerDevice::account_registerDevice(int32 flags_, bool no_muted_, int32 token_type_, string const &token_, bool app_sandbox_, bytes &&secret_, array<int64> &&other_uids_)
  : flags_(flags_)
  , no_muted_(no_muted_)
  , token_type_(token_type_)
  , token_(token_)
  , app_sandbox_(app_sandbox_)
  , secret_(std::move(secret_))
  , other_uids_(std::move(other_uids_))
{}

const std::int32_t account_registerDevice::ID;

void account_registerDevice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-326762118);
  TlStoreBinary::store((var0 = flags_ | (no_muted_ << 0)), s);
  TlStoreBinary::store(token_type_, s);
  TlStoreString::store(token_, s);
  TlStoreBool::store(app_sandbox_, s);
  TlStoreString::store(secret_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(other_uids_, s);
}

void account_registerDevice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-326762118);
  TlStoreBinary::store((var0 = flags_ | (no_muted_ << 0)), s);
  TlStoreBinary::store(token_type_, s);
  TlStoreString::store(token_, s);
  TlStoreBool::store(app_sandbox_, s);
  TlStoreString::store(secret_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(other_uids_, s);
}

void account_registerDevice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.registerDevice");
    s.store_field("flags", (var0 = flags_ | (no_muted_ << 0)));
    if (var0 & 1) { s.store_field("no_muted", true); }
    s.store_field("token_type", token_type_);
    s.store_field("token", token_);
    s.store_field("app_sandbox", app_sandbox_);
    s.store_bytes_field("secret", secret_);
    { s.store_vector_begin("other_uids", other_uids_.size()); for (const auto &_value : other_uids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_registerDevice::ReturnType account_registerDevice::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_saveMusic::account_saveMusic(int32 flags_, bool unsave_, object_ptr<InputDocument> &&id_, object_ptr<InputDocument> &&after_id_)
  : flags_(flags_)
  , unsave_(unsave_)
  , id_(std::move(id_))
  , after_id_(std::move(after_id_))
{}

const std::int32_t account_saveMusic::ID;

void account_saveMusic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1301859671);
  TlStoreBinary::store((var0 = flags_ | (unsave_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(after_id_, s); }
}

void account_saveMusic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1301859671);
  TlStoreBinary::store((var0 = flags_ | (unsave_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(after_id_, s); }
}

void account_saveMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveMusic");
    s.store_field("flags", (var0 = flags_ | (unsave_ << 0)));
    if (var0 & 1) { s.store_field("unsave", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    if (var0 & 2) { s.store_object_field("after_id", static_cast<const BaseObject *>(after_id_.get())); }
    s.store_class_end();
  }
}

account_saveMusic::ReturnType account_saveMusic::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_setContentSettings::account_setContentSettings(int32 flags_, bool sensitive_enabled_)
  : flags_(flags_)
  , sensitive_enabled_(sensitive_enabled_)
{}

const std::int32_t account_setContentSettings::ID;

void account_setContentSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1250643605);
  TlStoreBinary::store((var0 = flags_ | (sensitive_enabled_ << 0)), s);
}

void account_setContentSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1250643605);
  TlStoreBinary::store((var0 = flags_ | (sensitive_enabled_ << 0)), s);
}

void account_setContentSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setContentSettings");
    s.store_field("flags", (var0 = flags_ | (sensitive_enabled_ << 0)));
    if (var0 & 1) { s.store_field("sensitive_enabled", true); }
    s.store_class_end();
  }
}

account_setContentSettings::ReturnType account_setContentSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateBusinessAwayMessage::account_updateBusinessAwayMessage(int32 flags_, object_ptr<inputBusinessAwayMessage> &&message_)
  : flags_(flags_)
  , message_(std::move(message_))
{}

const std::int32_t account_updateBusinessAwayMessage::ID;

void account_updateBusinessAwayMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1570078811);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -2094959136>::store(message_, s); }
}

void account_updateBusinessAwayMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1570078811);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -2094959136>::store(message_, s); }
}

void account_updateBusinessAwayMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateBusinessAwayMessage");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

account_updateBusinessAwayMessage::ReturnType account_updateBusinessAwayMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateConnectedBot::account_updateConnectedBot(int32 flags_, bool deleted_, object_ptr<businessBotRights> &&rights_, object_ptr<InputUser> &&bot_, object_ptr<inputBusinessBotRecipients> &&recipients_)
  : flags_(flags_)
  , deleted_(deleted_)
  , rights_(std::move(rights_))
  , bot_(std::move(bot_))
  , recipients_(std::move(recipients_))
{}

const std::int32_t account_updateConnectedBot::ID;

void account_updateConnectedBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1721797758);
  TlStoreBinary::store((var0 = flags_ | (deleted_ << 1)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1604170505>::store(rights_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxed<TlStoreObject, -991587810>::store(recipients_, s);
}

void account_updateConnectedBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1721797758);
  TlStoreBinary::store((var0 = flags_ | (deleted_ << 1)), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1604170505>::store(rights_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxed<TlStoreObject, -991587810>::store(recipients_, s);
}

void account_updateConnectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateConnectedBot");
    s.store_field("flags", (var0 = flags_ | (deleted_ << 1)));
    if (var0 & 2) { s.store_field("deleted", true); }
    if (var0 & 1) { s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get())); }
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_class_end();
  }
}

account_updateConnectedBot::ReturnType account_updateConnectedBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

account_updateTheme::account_updateTheme(int32 flags_, string const &format_, object_ptr<InputTheme> &&theme_, string const &slug_, string const &title_, object_ptr<InputDocument> &&document_, array<object_ptr<inputThemeSettings>> &&settings_)
  : flags_(flags_)
  , format_(format_)
  , theme_(std::move(theme_))
  , slug_(slug_)
  , title_(title_)
  , document_(std::move(document_))
  , settings_(std::move(settings_))
{}

const std::int32_t account_updateTheme::ID;

void account_updateTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(737414348);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(format_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
  if (var0 & 1) { TlStoreString::store(slug_, s); }
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1881255857>>, 481674261>::store(settings_, s); }
}

void account_updateTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(737414348);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(format_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
  if (var0 & 1) { TlStoreString::store(slug_, s); }
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1881255857>>, 481674261>::store(settings_, s); }
}

void account_updateTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateTheme");
    s.store_field("flags", (var0 = flags_));
    s.store_field("format", format_);
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    if (var0 & 1) { s.store_field("slug", slug_); }
    if (var0 & 2) { s.store_field("title", title_); }
    if (var0 & 4) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 8) { { s.store_vector_begin("settings", settings_.size()); for (const auto &_value : settings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

account_updateTheme::ReturnType account_updateTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<theme>, -1609668650>::parse(p);
#undef FAIL
}

account_verifyEmail::account_verifyEmail(object_ptr<EmailVerifyPurpose> &&purpose_, object_ptr<EmailVerification> &&verification_)
  : purpose_(std::move(purpose_))
  , verification_(std::move(verification_))
{}

const std::int32_t account_verifyEmail::ID;

void account_verifyEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(53322959);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(verification_, s);
}

void account_verifyEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(53322959);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(verification_, s);
}

void account_verifyEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.verifyEmail");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_object_field("verification", static_cast<const BaseObject *>(verification_.get()));
    s.store_class_end();
  }
}

account_verifyEmail::ReturnType account_verifyEmail::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_EmailVerified>::parse(p);
#undef FAIL
}

auth_importAuthorization::auth_importAuthorization(int64 id_, bytes &&bytes_)
  : id_(id_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t auth_importAuthorization::ID;

void auth_importAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1518699091);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(bytes_, s);
}

void auth_importAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1518699091);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(bytes_, s);
}

void auth_importAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.importAuthorization");
    s.store_field("id", id_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

auth_importAuthorization::ReturnType auth_importAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

auth_resendCode::auth_resendCode(int32 flags_, string const &phone_number_, string const &phone_code_hash_, string const &reason_)
  : flags_(flags_)
  , phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , reason_(reason_)
{}

const std::int32_t auth_resendCode::ID;

void auth_resendCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-890997469);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  if (var0 & 1) { TlStoreString::store(reason_, s); }
}

void auth_resendCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-890997469);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  if (var0 & 1) { TlStoreString::store(reason_, s); }
}

void auth_resendCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.resendCode");
    s.store_field("flags", (var0 = flags_));
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    if (var0 & 1) { s.store_field("reason", reason_); }
    s.store_class_end();
  }
}

auth_resendCode::ReturnType auth_resendCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

bots_resetBotCommands::bots_resetBotCommands(object_ptr<BotCommandScope> &&scope_, string const &lang_code_)
  : scope_(std::move(scope_))
  , lang_code_(lang_code_)
{}

const std::int32_t bots_resetBotCommands::ID;

void bots_resetBotCommands::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1032708345);
  TlStoreBoxedUnknown<TlStoreObject>::store(scope_, s);
  TlStoreString::store(lang_code_, s);
}

void bots_resetBotCommands::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1032708345);
  TlStoreBoxedUnknown<TlStoreObject>::store(scope_, s);
  TlStoreString::store(lang_code_, s);
}

void bots_resetBotCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.resetBotCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

bots_resetBotCommands::ReturnType bots_resetBotCommands::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_setBotCommands::bots_setBotCommands(object_ptr<BotCommandScope> &&scope_, string const &lang_code_, array<object_ptr<botCommand>> &&commands_)
  : scope_(std::move(scope_))
  , lang_code_(lang_code_)
  , commands_(std::move(commands_))
{}

const std::int32_t bots_setBotCommands::ID;

void bots_setBotCommands::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(85399130);
  TlStoreBoxedUnknown<TlStoreObject>::store(scope_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1032140601>>, 481674261>::store(commands_, s);
}

void bots_setBotCommands::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(85399130);
  TlStoreBoxedUnknown<TlStoreObject>::store(scope_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1032140601>>, 481674261>::store(commands_, s);
}

void bots_setBotCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setBotCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("lang_code", lang_code_);
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

bots_setBotCommands::ReturnType bots_setBotCommands::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_setBotGroupDefaultAdminRights::bots_setBotGroupDefaultAdminRights(object_ptr<chatAdminRights> &&admin_rights_)
  : admin_rights_(std::move(admin_rights_))
{}

const std::int32_t bots_setBotGroupDefaultAdminRights::ID;

void bots_setBotGroupDefaultAdminRights::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1839281686);
  TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s);
}

void bots_setBotGroupDefaultAdminRights::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1839281686);
  TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s);
}

void bots_setBotGroupDefaultAdminRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setBotGroupDefaultAdminRights");
    s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get()));
    s.store_class_end();
  }
}

bots_setBotGroupDefaultAdminRights::ReturnType bots_setBotGroupDefaultAdminRights::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_setBotMenuButton::bots_setBotMenuButton(object_ptr<InputUser> &&user_id_, object_ptr<BotMenuButton> &&button_)
  : user_id_(std::move(user_id_))
  , button_(std::move(button_))
{}

const std::int32_t bots_setBotMenuButton::ID;

void bots_setBotMenuButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1157944655);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(button_, s);
}

void bots_setBotMenuButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1157944655);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(button_, s);
}

void bots_setBotMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setBotMenuButton");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    s.store_class_end();
  }
}

bots_setBotMenuButton::ReturnType bots_setBotMenuButton::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_setCustomVerification::bots_setCustomVerification(int32 flags_, bool enabled_, object_ptr<InputUser> &&bot_, object_ptr<InputPeer> &&peer_, string const &custom_description_)
  : flags_(flags_)
  , enabled_(enabled_)
  , bot_(std::move(bot_))
  , peer_(std::move(peer_))
  , custom_description_(custom_description_)
{}

const std::int32_t bots_setCustomVerification::ID;

void bots_setCustomVerification::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1953898563);
  TlStoreBinary::store((var0 = flags_ | (enabled_ << 1)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreString::store(custom_description_, s); }
}

void bots_setCustomVerification::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1953898563);
  TlStoreBinary::store((var0 = flags_ | (enabled_ << 1)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreString::store(custom_description_, s); }
}

void bots_setCustomVerification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setCustomVerification");
    s.store_field("flags", (var0 = flags_ | (enabled_ << 1)));
    if (var0 & 2) { s.store_field("enabled", true); }
    if (var0 & 1) { s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get())); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 4) { s.store_field("custom_description", custom_description_); }
    s.store_class_end();
  }
}

bots_setCustomVerification::ReturnType bots_setCustomVerification::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_checkUsername::channels_checkUsername(object_ptr<InputChannel> &&channel_, string const &username_)
  : channel_(std::move(channel_))
  , username_(username_)
{}

const std::int32_t channels_checkUsername::ID;

void channels_checkUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(283557164);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(username_, s);
}

void channels_checkUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(283557164);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(username_, s);
}

void channels_checkUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.checkUsername");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("username", username_);
    s.store_class_end();
  }
}

channels_checkUsername::ReturnType channels_checkUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_editAdmin::channels_editAdmin(int32 flags_, object_ptr<InputChannel> &&channel_, object_ptr<InputUser> &&user_id_, object_ptr<chatAdminRights> &&admin_rights_, string const &rank_)
  : flags_(flags_)
  , channel_(std::move(channel_))
  , user_id_(std::move(user_id_))
  , admin_rights_(std::move(admin_rights_))
  , rank_(rank_)
{}

const std::int32_t channels_editAdmin::ID;

void channels_editAdmin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1701270168);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s);
  if (var0 & 1) { TlStoreString::store(rank_, s); }
}

void channels_editAdmin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1701270168);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s);
  if (var0 & 1) { TlStoreString::store(rank_, s); }
}

void channels_editAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.editAdmin");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get()));
    if (var0 & 1) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

channels_editAdmin::ReturnType channels_editAdmin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_searchPosts::channels_searchPosts(int32 flags_, string const &hashtag_, string const &query_, int32 offset_rate_, object_ptr<InputPeer> &&offset_peer_, int32 offset_id_, int32 limit_, int64 allow_paid_stars_)
  : flags_(flags_)
  , hashtag_(hashtag_)
  , query_(query_)
  , offset_rate_(offset_rate_)
  , offset_peer_(std::move(offset_peer_))
  , offset_id_(offset_id_)
  , limit_(limit_)
  , allow_paid_stars_(allow_paid_stars_)
{}

const std::int32_t channels_searchPosts::ID;

void channels_searchPosts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-221973939);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(hashtag_, s); }
  if (var0 & 2) { TlStoreString::store(query_, s); }
  TlStoreBinary::store(offset_rate_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
  if (var0 & 4) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void channels_searchPosts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-221973939);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(hashtag_, s); }
  if (var0 & 2) { TlStoreString::store(query_, s); }
  TlStoreBinary::store(offset_rate_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
  if (var0 & 4) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void channels_searchPosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.searchPosts");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("hashtag", hashtag_); }
    if (var0 & 2) { s.store_field("query", query_); }
    s.store_field("offset_rate", offset_rate_);
    s.store_object_field("offset_peer", static_cast<const BaseObject *>(offset_peer_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    if (var0 & 4) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    s.store_class_end();
  }
}

channels_searchPosts::ReturnType channels_searchPosts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

channels_setStickers::channels_setStickers(object_ptr<InputChannel> &&channel_, object_ptr<InputStickerSet> &&stickerset_)
  : channel_(std::move(channel_))
  , stickerset_(std::move(stickerset_))
{}

const std::int32_t channels_setStickers::ID;

void channels_setStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-359881479);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void channels_setStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-359881479);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void channels_setStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.setStickers");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_class_end();
  }
}

channels_setStickers::ReturnType channels_setStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_toggleUsername::channels_toggleUsername(object_ptr<InputChannel> &&channel_, string const &username_, bool active_)
  : channel_(std::move(channel_))
  , username_(username_)
  , active_(active_)
{}

const std::int32_t channels_toggleUsername::ID;

void channels_toggleUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1358053637);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(username_, s);
  TlStoreBool::store(active_, s);
}

void channels_toggleUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1358053637);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(username_, s);
  TlStoreBool::store(active_, s);
}

void channels_toggleUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleUsername");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("username", username_);
    s.store_field("active", active_);
    s.store_class_end();
  }
}

channels_toggleUsername::ReturnType channels_toggleUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

chatlists_leaveChatlist::chatlists_leaveChatlist(object_ptr<inputChatlistDialogFilter> &&chatlist_, array<object_ptr<InputPeer>> &&peers_)
  : chatlist_(std::move(chatlist_))
  , peers_(std::move(peers_))
{}

const std::int32_t chatlists_leaveChatlist::ID;

void chatlists_leaveChatlist::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1962598714);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_leaveChatlist::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1962598714);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_leaveChatlist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.leaveChatlist");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatlists_leaveChatlist::ReturnType chatlists_leaveChatlist::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

contacts_getBlocked::contacts_getBlocked(int32 flags_, bool my_stories_from_, int32 offset_, int32 limit_)
  : flags_(flags_)
  , my_stories_from_(my_stories_from_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t contacts_getBlocked::ID;

void contacts_getBlocked::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1702457472);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void contacts_getBlocked::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1702457472);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void contacts_getBlocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getBlocked");
    s.store_field("flags", (var0 = flags_ | (my_stories_from_ << 0)));
    if (var0 & 1) { s.store_field("my_stories_from", true); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

contacts_getBlocked::ReturnType contacts_getBlocked::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<contacts_Blocked>::parse(p);
#undef FAIL
}

contacts_getContactIDs::contacts_getContactIDs(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t contacts_getContactIDs::ID;

void contacts_getContactIDs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2061264541);
  TlStoreBinary::store(hash_, s);
}

void contacts_getContactIDs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2061264541);
  TlStoreBinary::store(hash_, s);
}

void contacts_getContactIDs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getContactIDs");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

contacts_getContactIDs::ReturnType contacts_getContactIDs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
#undef FAIL
}

contacts_search::contacts_search(string const &q_, int32 limit_)
  : q_(q_)
  , limit_(limit_)
{}

const std::int32_t contacts_search::ID;

void contacts_search::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(301470424);
  TlStoreString::store(q_, s);
  TlStoreBinary::store(limit_, s);
}

void contacts_search::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(301470424);
  TlStoreString::store(q_, s);
  TlStoreBinary::store(limit_, s);
}

void contacts_search::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.search");
    s.store_field("q", q_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

contacts_search::ReturnType contacts_search::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<contacts_found>, -1290580579>::parse(p);
#undef FAIL
}

invokeWithReCaptchaPrefix::invokeWithReCaptchaPrefix(string const &token_)
  : token_(token_)
{}

const std::int32_t invokeWithReCaptchaPrefix::ID;

void invokeWithReCaptchaPrefix::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1380249708);
  TlStoreString::store(token_, s);
}

void invokeWithReCaptchaPrefix::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1380249708);
  TlStoreString::store(token_, s);
}

void invokeWithReCaptchaPrefix::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invokeWithReCaptchaPrefix");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

invokeWithReCaptchaPrefix::ReturnType invokeWithReCaptchaPrefix::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<error>, -994444869>::parse(p);
#undef FAIL
}

langpack_getLanguage::langpack_getLanguage(string const &lang_pack_, string const &lang_code_)
  : lang_pack_(lang_pack_)
  , lang_code_(lang_code_)
{}

const std::int32_t langpack_getLanguage::ID;

void langpack_getLanguage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1784243458);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
}

void langpack_getLanguage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1784243458);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
}

void langpack_getLanguage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langpack.getLanguage");
    s.store_field("lang_pack", lang_pack_);
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

langpack_getLanguage::ReturnType langpack_getLanguage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<langPackLanguage>, -288727837>::parse(p);
#undef FAIL
}

langpack_getLanguages::langpack_getLanguages(string const &lang_pack_)
  : lang_pack_(lang_pack_)
{}

const std::int32_t langpack_getLanguages::ID;

void langpack_getLanguages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1120311183);
  TlStoreString::store(lang_pack_, s);
}

void langpack_getLanguages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1120311183);
  TlStoreString::store(lang_pack_, s);
}

void langpack_getLanguages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langpack.getLanguages");
    s.store_field("lang_pack", lang_pack_);
    s.store_class_end();
  }
}

langpack_getLanguages::ReturnType langpack_getLanguages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<langPackLanguage>, -288727837>>, 481674261>::parse(p);
#undef FAIL
}

messages_acceptEncryption::messages_acceptEncryption(object_ptr<inputEncryptedChat> &&peer_, bytes &&g_b_, int64 key_fingerprint_)
  : peer_(std::move(peer_))
  , g_b_(std::move(g_b_))
  , key_fingerprint_(key_fingerprint_)
{}

const std::int32_t messages_acceptEncryption::ID;

void messages_acceptEncryption::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1035731989);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreString::store(g_b_, s);
  TlStoreBinary::store(key_fingerprint_, s);
}

void messages_acceptEncryption::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1035731989);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreString::store(g_b_, s);
  TlStoreBinary::store(key_fingerprint_, s);
}

void messages_acceptEncryption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.acceptEncryption");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_bytes_field("g_b", g_b_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_class_end();
  }
}

messages_acceptEncryption::ReturnType messages_acceptEncryption::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EncryptedChat>::parse(p);
#undef FAIL
}

messages_addChatUser::messages_addChatUser(int64 chat_id_, object_ptr<InputUser> &&user_id_, int32 fwd_limit_)
  : chat_id_(chat_id_)
  , user_id_(std::move(user_id_))
  , fwd_limit_(fwd_limit_)
{}

const std::int32_t messages_addChatUser::ID;

void messages_addChatUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-876162809);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(fwd_limit_, s);
}

void messages_addChatUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-876162809);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(fwd_limit_, s);
}

void messages_addChatUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.addChatUser");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("fwd_limit", fwd_limit_);
    s.store_class_end();
  }
}

messages_addChatUser::ReturnType messages_addChatUser::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_invitedUsers>, 2136862630>::parse(p);
#undef FAIL
}

messages_checkChatInvite::messages_checkChatInvite(string const &hash_)
  : hash_(hash_)
{}

const std::int32_t messages_checkChatInvite::ID;

void messages_checkChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1051570619);
  TlStoreString::store(hash_, s);
}

void messages_checkChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1051570619);
  TlStoreString::store(hash_, s);
}

void messages_checkChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.checkChatInvite");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_checkChatInvite::ReturnType messages_checkChatInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<ChatInvite>::parse(p);
#undef FAIL
}

messages_checkHistoryImport::messages_checkHistoryImport(string const &import_head_)
  : import_head_(import_head_)
{}

const std::int32_t messages_checkHistoryImport::ID;

void messages_checkHistoryImport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1140726259);
  TlStoreString::store(import_head_, s);
}

void messages_checkHistoryImport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1140726259);
  TlStoreString::store(import_head_, s);
}

void messages_checkHistoryImport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.checkHistoryImport");
    s.store_field("import_head", import_head_);
    s.store_class_end();
  }
}

messages_checkHistoryImport::ReturnType messages_checkHistoryImport::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_historyImportParsed>, 1578088377>::parse(p);
#undef FAIL
}

messages_createForumTopic::messages_createForumTopic(int32 flags_, bool title_missing_, object_ptr<InputPeer> &&peer_, string const &title_, int32 icon_color_, int64 icon_emoji_id_, int64 random_id_, object_ptr<InputPeer> &&send_as_)
  : flags_(flags_)
  , title_missing_(title_missing_)
  , peer_(std::move(peer_))
  , title_(title_)
  , icon_color_(icon_color_)
  , icon_emoji_id_(icon_emoji_id_)
  , random_id_(random_id_)
  , send_as_(std::move(send_as_))
{}

const std::int32_t messages_createForumTopic::ID;

void messages_createForumTopic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(798540757);
  TlStoreBinary::store((var0 = flags_ | (title_missing_ << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(title_, s);
  if (var0 & 1) { TlStoreBinary::store(icon_color_, s); }
  if (var0 & 8) { TlStoreBinary::store(icon_emoji_id_, s); }
  TlStoreBinary::store(random_id_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void messages_createForumTopic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(798540757);
  TlStoreBinary::store((var0 = flags_ | (title_missing_ << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(title_, s);
  if (var0 & 1) { TlStoreBinary::store(icon_color_, s); }
  if (var0 & 8) { TlStoreBinary::store(icon_emoji_id_, s); }
  TlStoreBinary::store(random_id_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void messages_createForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.createForumTopic");
    s.store_field("flags", (var0 = flags_ | (title_missing_ << 4)));
    if (var0 & 16) { s.store_field("title_missing", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("title", title_);
    if (var0 & 1) { s.store_field("icon_color", icon_color_); }
    if (var0 & 8) { s.store_field("icon_emoji_id", icon_emoji_id_); }
    s.store_field("random_id", random_id_);
    if (var0 & 4) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    s.store_class_end();
  }
}

messages_createForumTopic::ReturnType messages_createForumTopic::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_deleteSavedHistory::messages_deleteSavedHistory(int32 flags_, object_ptr<InputPeer> &&parent_peer_, object_ptr<InputPeer> &&peer_, int32 max_id_, int32 min_date_, int32 max_date_)
  : flags_(flags_)
  , parent_peer_(std::move(parent_peer_))
  , peer_(std::move(peer_))
  , max_id_(max_id_)
  , min_date_(min_date_)
  , max_date_(max_date_)
{}

const std::int32_t messages_deleteSavedHistory::ID;

void messages_deleteSavedHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1304758367);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
  if (var0 & 4) { TlStoreBinary::store(min_date_, s); }
  if (var0 & 8) { TlStoreBinary::store(max_date_, s); }
}

void messages_deleteSavedHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1304758367);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
  if (var0 & 4) { TlStoreBinary::store(min_date_, s); }
  if (var0 & 8) { TlStoreBinary::store(max_date_, s); }
}

void messages_deleteSavedHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteSavedHistory");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    if (var0 & 4) { s.store_field("min_date", min_date_); }
    if (var0 & 8) { s.store_field("max_date", max_date_); }
    s.store_class_end();
  }
}

messages_deleteSavedHistory::ReturnType messages_deleteSavedHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_deleteScheduledMessages::messages_deleteScheduledMessages(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t messages_deleteScheduledMessages::ID;

void messages_deleteScheduledMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1504586518);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_deleteScheduledMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1504586518);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_deleteScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteScheduledMessages");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_deleteScheduledMessages::ReturnType messages_deleteScheduledMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getArchivedStickers::messages_getArchivedStickers(int32 flags_, bool masks_, bool emojis_, int64 offset_id_, int32 limit_)
  : flags_(flags_)
  , masks_(masks_)
  , emojis_(emojis_)
  , offset_id_(offset_id_)
  , limit_(limit_)
{}

const std::int32_t messages_getArchivedStickers::ID;

void messages_getArchivedStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1475442322);
  TlStoreBinary::store((var0 = flags_ | (masks_ << 0) | (emojis_ << 1)), s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getArchivedStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1475442322);
  TlStoreBinary::store((var0 = flags_ | (masks_ << 0) | (emojis_ << 1)), s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getArchivedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getArchivedStickers");
    s.store_field("flags", (var0 = flags_ | (masks_ << 0) | (emojis_ << 1)));
    if (var0 & 1) { s.store_field("masks", true); }
    if (var0 & 2) { s.store_field("emojis", true); }
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getArchivedStickers::ReturnType messages_getArchivedStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_archivedStickers>, 1338747336>::parse(p);
#undef FAIL
}

messages_getAvailableEffects::messages_getAvailableEffects(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getAvailableEffects::ID;

void messages_getAvailableEffects::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-559805895);
  TlStoreBinary::store(hash_, s);
}

void messages_getAvailableEffects::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-559805895);
  TlStoreBinary::store(hash_, s);
}

void messages_getAvailableEffects::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAvailableEffects");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getAvailableEffects::ReturnType messages_getAvailableEffects::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_AvailableEffects>::parse(p);
#undef FAIL
}

messages_getAvailableReactions::messages_getAvailableReactions(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getAvailableReactions::ID;

void messages_getAvailableReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(417243308);
  TlStoreBinary::store(hash_, s);
}

void messages_getAvailableReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(417243308);
  TlStoreBinary::store(hash_, s);
}

void messages_getAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAvailableReactions");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getAvailableReactions::ReturnType messages_getAvailableReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_AvailableReactions>::parse(p);
#undef FAIL
}

const std::int32_t messages_getDialogFilters::ID;

void messages_getDialogFilters::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-271283063);
}

void messages_getDialogFilters::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-271283063);
}

void messages_getDialogFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDialogFilters");
    s.store_class_end();
  }
}

messages_getDialogFilters::ReturnType messages_getDialogFilters::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_dialogFilters>, 718878489>::parse(p);
#undef FAIL
}

messages_getEmojiStatusGroups::messages_getEmojiStatusGroups(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getEmojiStatusGroups::ID;

void messages_getEmojiStatusGroups::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(785209037);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiStatusGroups::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(785209037);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiStatusGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiStatusGroups");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getEmojiStatusGroups::ReturnType messages_getEmojiStatusGroups::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_EmojiGroups>::parse(p);
#undef FAIL
}

messages_getMessages::messages_getMessages(array<object_ptr<InputMessage>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t messages_getMessages::ID;

void messages_getMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1673946374);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void messages_getMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1673946374);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void messages_getMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMessages");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getMessages::ReturnType messages_getMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getMessagesReactions::messages_getMessagesReactions(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t messages_getMessagesReactions::ID;

void messages_getMessagesReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1950707482);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getMessagesReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1950707482);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getMessagesReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMessagesReactions");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getMessagesReactions::ReturnType messages_getMessagesReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getPeerDialogs::messages_getPeerDialogs(array<object_ptr<InputDialogPeer>> &&peers_)
  : peers_(std::move(peers_))
{}

const std::int32_t messages_getPeerDialogs::ID;

void messages_getPeerDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-462373635);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void messages_getPeerDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-462373635);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void messages_getPeerDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPeerDialogs");
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getPeerDialogs::ReturnType messages_getPeerDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_peerDialogs>, 863093588>::parse(p);
#undef FAIL
}

messages_getRecentStickers::messages_getRecentStickers(int32 flags_, bool attached_, int64 hash_)
  : flags_(flags_)
  , attached_(attached_)
  , hash_(hash_)
{}

const std::int32_t messages_getRecentStickers::ID;

void messages_getRecentStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1649852357);
  TlStoreBinary::store((var0 = flags_ | (attached_ << 0)), s);
  TlStoreBinary::store(hash_, s);
}

void messages_getRecentStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1649852357);
  TlStoreBinary::store((var0 = flags_ | (attached_ << 0)), s);
  TlStoreBinary::store(hash_, s);
}

void messages_getRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getRecentStickers");
    s.store_field("flags", (var0 = flags_ | (attached_ << 0)));
    if (var0 & 1) { s.store_field("attached", true); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getRecentStickers::ReturnType messages_getRecentStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_RecentStickers>::parse(p);
#undef FAIL
}

messages_getSavedHistory::messages_getSavedHistory(int32 flags_, object_ptr<InputPeer> &&parent_peer_, object_ptr<InputPeer> &&peer_, int32 offset_id_, int32 offset_date_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_, int64 hash_)
  : flags_(flags_)
  , parent_peer_(std::move(parent_peer_))
  , peer_(std::move(peer_))
  , offset_id_(offset_id_)
  , offset_date_(offset_date_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
  , hash_(hash_)
{}

const std::int32_t messages_getSavedHistory::ID;

void messages_getSavedHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1718964215);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1718964215);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSavedHistory");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("offset_date", offset_date_);
    s.store_field("add_offset", add_offset_);
    s.store_field("limit", limit_);
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getSavedHistory::ReturnType messages_getSavedHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getScheduledHistory::messages_getScheduledHistory(object_ptr<InputPeer> &&peer_, int64 hash_)
  : peer_(std::move(peer_))
  , hash_(hash_)
{}

const std::int32_t messages_getScheduledHistory::ID;

void messages_getScheduledHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-183077365);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getScheduledHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-183077365);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getScheduledHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getScheduledHistory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getScheduledHistory::ReturnType messages_getScheduledHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getSearchResultsCalendar::messages_getSearchResultsCalendar(int32 flags_, object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&saved_peer_id_, object_ptr<MessagesFilter> &&filter_, int32 offset_id_, int32 offset_date_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , saved_peer_id_(std::move(saved_peer_id_))
  , filter_(std::move(filter_))
  , offset_id_(offset_id_)
  , offset_date_(offset_date_)
{}

const std::int32_t messages_getSearchResultsCalendar::ID;

void messages_getSearchResultsCalendar::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1789130429);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
}

void messages_getSearchResultsCalendar::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1789130429);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
}

void messages_getSearchResultsCalendar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSearchResultsCalendar");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 4) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("offset_date", offset_date_);
    s.store_class_end();
  }
}

messages_getSearchResultsCalendar::ReturnType messages_getSearchResultsCalendar::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_searchResultsCalendar>, 343859772>::parse(p);
#undef FAIL
}

const std::int32_t messages_getSplitRanges::ID;

void messages_getSplitRanges::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(486505992);
}

void messages_getSplitRanges::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(486505992);
}

void messages_getSplitRanges::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSplitRanges");
    s.store_class_end();
  }
}

messages_getSplitRanges::ReturnType messages_getSplitRanges::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messageRange>, 182649427>>, 481674261>::parse(p);
#undef FAIL
}

messages_hideChatJoinRequest::messages_hideChatJoinRequest(int32 flags_, bool approved_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , approved_(approved_)
  , peer_(std::move(peer_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t messages_hideChatJoinRequest::ID;

void messages_hideChatJoinRequest::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2145904661);
  TlStoreBinary::store((var0 = flags_ | (approved_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_hideChatJoinRequest::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2145904661);
  TlStoreBinary::store((var0 = flags_ | (approved_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_hideChatJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.hideChatJoinRequest");
    s.store_field("flags", (var0 = flags_ | (approved_ << 0)));
    if (var0 & 1) { s.store_field("approved", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

messages_hideChatJoinRequest::ReturnType messages_hideChatJoinRequest::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_readSavedHistory::messages_readSavedHistory(object_ptr<InputPeer> &&parent_peer_, object_ptr<InputPeer> &&peer_, int32 max_id_)
  : parent_peer_(std::move(parent_peer_))
  , peer_(std::move(peer_))
  , max_id_(max_id_)
{}

const std::int32_t messages_readSavedHistory::ID;

void messages_readSavedHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1169540261);
  TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
}

void messages_readSavedHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1169540261);
  TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
}

void messages_readSavedHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readSavedHistory");
    s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get()));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

messages_readSavedHistory::ReturnType messages_readSavedHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_searchSentMedia::messages_searchSentMedia(string const &q_, object_ptr<MessagesFilter> &&filter_, int32 limit_)
  : q_(q_)
  , filter_(std::move(filter_))
  , limit_(limit_)
{}

const std::int32_t messages_searchSentMedia::ID;

void messages_searchSentMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(276705696);
  TlStoreString::store(q_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_searchSentMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(276705696);
  TlStoreString::store(q_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_searchSentMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchSentMedia");
    s.store_field("q", q_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_searchSentMedia::ReturnType messages_searchSentMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_searchStickerSets::messages_searchStickerSets(int32 flags_, bool exclude_featured_, string const &q_, int64 hash_)
  : flags_(flags_)
  , exclude_featured_(exclude_featured_)
  , q_(q_)
  , hash_(hash_)
{}

const std::int32_t messages_searchStickerSets::ID;

void messages_searchStickerSets::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(896555914);
  TlStoreBinary::store((var0 = flags_ | (exclude_featured_ << 0)), s);
  TlStoreString::store(q_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchStickerSets::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(896555914);
  TlStoreBinary::store((var0 = flags_ | (exclude_featured_ << 0)), s);
  TlStoreString::store(q_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchStickerSets");
    s.store_field("flags", (var0 = flags_ | (exclude_featured_ << 0)));
    if (var0 & 1) { s.store_field("exclude_featured", true); }
    s.store_field("q", q_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_searchStickerSets::ReturnType messages_searchStickerSets::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FoundStickerSets>::parse(p);
#undef FAIL
}

messages_sendQuickReplyMessages::messages_sendQuickReplyMessages(object_ptr<InputPeer> &&peer_, int32 shortcut_id_, array<int32> &&id_, array<int64> &&random_id_)
  : peer_(std::move(peer_))
  , shortcut_id_(shortcut_id_)
  , id_(std::move(id_))
  , random_id_(std::move(random_id_))
{}

const std::int32_t messages_sendQuickReplyMessages::ID;

void messages_sendQuickReplyMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1819610593);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(random_id_, s);
}

void messages_sendQuickReplyMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1819610593);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(random_id_, s);
}

void messages_sendQuickReplyMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendQuickReplyMessages");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("shortcut_id", shortcut_id_);
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("random_id", random_id_.size()); for (const auto &_value : random_id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_sendQuickReplyMessages::ReturnType messages_sendQuickReplyMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_sendVote::messages_sendVote(object_ptr<InputPeer> &&peer_, int32 msg_id_, array<bytes> &&options_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , options_(std::move(options_))
{}

const std::int32_t messages_sendVote::ID;

void messages_sendVote::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(283795844);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(options_, s);
}

void messages_sendVote::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(283795844);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(options_, s);
}

void messages_sendVote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendVote");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_sendVote::ReturnType messages_sendVote::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setChatAvailableReactions::messages_setChatAvailableReactions(int32 flags_, object_ptr<InputPeer> &&peer_, object_ptr<ChatReactions> &&available_reactions_, int32 reactions_limit_, bool paid_enabled_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , available_reactions_(std::move(available_reactions_))
  , reactions_limit_(reactions_limit_)
  , paid_enabled_(paid_enabled_)
{}

const std::int32_t messages_setChatAvailableReactions::ID;

void messages_setChatAvailableReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2041895551);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(available_reactions_, s);
  if (var0 & 1) { TlStoreBinary::store(reactions_limit_, s); }
  if (var0 & 2) { TlStoreBool::store(paid_enabled_, s); }
}

void messages_setChatAvailableReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2041895551);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(available_reactions_, s);
  if (var0 & 1) { TlStoreBinary::store(reactions_limit_, s); }
  if (var0 & 2) { TlStoreBool::store(paid_enabled_, s); }
}

void messages_setChatAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setChatAvailableReactions");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("available_reactions", static_cast<const BaseObject *>(available_reactions_.get()));
    if (var0 & 1) { s.store_field("reactions_limit", reactions_limit_); }
    if (var0 & 2) { s.store_field("paid_enabled", paid_enabled_); }
    s.store_class_end();
  }
}

messages_setChatAvailableReactions::ReturnType messages_setChatAvailableReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_updatePinnedMessage::messages_updatePinnedMessage(int32 flags_, bool silent_, bool unpin_, bool pm_oneside_, object_ptr<InputPeer> &&peer_, int32 id_)
  : flags_(flags_)
  , silent_(silent_)
  , unpin_(unpin_)
  , pm_oneside_(pm_oneside_)
  , peer_(std::move(peer_))
  , id_(id_)
{}

const std::int32_t messages_updatePinnedMessage::ID;

void messages_updatePinnedMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-760547348);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 0) | (unpin_ << 1) | (pm_oneside_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void messages_updatePinnedMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-760547348);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 0) | (unpin_ << 1) | (pm_oneside_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void messages_updatePinnedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.updatePinnedMessage");
    s.store_field("flags", (var0 = flags_ | (silent_ << 0) | (unpin_ << 1) | (pm_oneside_ << 2)));
    if (var0 & 1) { s.store_field("silent", true); }
    if (var0 & 2) { s.store_field("unpin", true); }
    if (var0 & 4) { s.store_field("pm_oneside", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

messages_updatePinnedMessage::ReturnType messages_updatePinnedMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_botCancelStarsSubscription::payments_botCancelStarsSubscription(int32 flags_, bool restore_, object_ptr<InputUser> &&user_id_, string const &charge_id_)
  : flags_(flags_)
  , restore_(restore_)
  , user_id_(std::move(user_id_))
  , charge_id_(charge_id_)
{}

const std::int32_t payments_botCancelStarsSubscription::ID;

void payments_botCancelStarsSubscription::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1845102114);
  TlStoreBinary::store((var0 = flags_ | (restore_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(charge_id_, s);
}

void payments_botCancelStarsSubscription::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1845102114);
  TlStoreBinary::store((var0 = flags_ | (restore_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(charge_id_, s);
}

void payments_botCancelStarsSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.botCancelStarsSubscription");
    s.store_field("flags", (var0 = flags_ | (restore_ << 0)));
    if (var0 & 1) { s.store_field("restore", true); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("charge_id", charge_id_);
    s.store_class_end();
  }
}

payments_botCancelStarsSubscription::ReturnType payments_botCancelStarsSubscription::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_connectStarRefBot::payments_connectStarRefBot(object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&bot_)
  : peer_(std::move(peer_))
  , bot_(std::move(bot_))
{}

const std::int32_t payments_connectStarRefBot::ID;

void payments_connectStarRefBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2127901834);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void payments_connectStarRefBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2127901834);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void payments_connectStarRefBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.connectStarRefBot");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

payments_connectStarRefBot::ReturnType payments_connectStarRefBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_connectedStarRefBots>, -1730811363>::parse(p);
#undef FAIL
}

payments_getBankCardData::payments_getBankCardData(string const &number_)
  : number_(number_)
{}

const std::int32_t payments_getBankCardData::ID;

void payments_getBankCardData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(779736953);
  TlStoreString::store(number_, s);
}

void payments_getBankCardData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(779736953);
  TlStoreString::store(number_, s);
}

void payments_getBankCardData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getBankCardData");
    s.store_field("number", number_);
    s.store_class_end();
  }
}

payments_getBankCardData::ReturnType payments_getBankCardData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_bankCardData>, 1042605427>::parse(p);
#undef FAIL
}

const std::int32_t payments_getSavedInfo::ID;

void payments_getSavedInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(578650699);
}

void payments_getSavedInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(578650699);
}

void payments_getSavedInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getSavedInfo");
    s.store_class_end();
  }
}

payments_getSavedInfo::ReturnType payments_getSavedInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_savedInfo>, -74456004>::parse(p);
#undef FAIL
}

payments_getSavedStarGifts::payments_getSavedStarGifts(int32 flags_, bool exclude_unsaved_, bool exclude_saved_, bool exclude_unlimited_, bool exclude_unique_, bool sort_by_value_, bool exclude_upgradable_, bool exclude_unupgradable_, bool peer_color_available_, bool exclude_hosted_, object_ptr<InputPeer> &&peer_, int32 collection_id_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , exclude_unsaved_(exclude_unsaved_)
  , exclude_saved_(exclude_saved_)
  , exclude_unlimited_(exclude_unlimited_)
  , exclude_unique_(exclude_unique_)
  , sort_by_value_(sort_by_value_)
  , exclude_upgradable_(exclude_upgradable_)
  , exclude_unupgradable_(exclude_unupgradable_)
  , peer_color_available_(peer_color_available_)
  , exclude_hosted_(exclude_hosted_)
  , peer_(std::move(peer_))
  , collection_id_(collection_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t payments_getSavedStarGifts::ID;

void payments_getSavedStarGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1558583959);
  TlStoreBinary::store((var0 = flags_ | (exclude_unsaved_ << 0) | (exclude_saved_ << 1) | (exclude_unlimited_ << 2) | (exclude_unique_ << 4) | (sort_by_value_ << 5) | (exclude_upgradable_ << 7) | (exclude_unupgradable_ << 8) | (peer_color_available_ << 9) | (exclude_hosted_ << 10)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 64) { TlStoreBinary::store(collection_id_, s); }
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getSavedStarGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1558583959);
  TlStoreBinary::store((var0 = flags_ | (exclude_unsaved_ << 0) | (exclude_saved_ << 1) | (exclude_unlimited_ << 2) | (exclude_unique_ << 4) | (sort_by_value_ << 5) | (exclude_upgradable_ << 7) | (exclude_unupgradable_ << 8) | (peer_color_available_ << 9) | (exclude_hosted_ << 10)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 64) { TlStoreBinary::store(collection_id_, s); }
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getSavedStarGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getSavedStarGifts");
    s.store_field("flags", (var0 = flags_ | (exclude_unsaved_ << 0) | (exclude_saved_ << 1) | (exclude_unlimited_ << 2) | (exclude_unique_ << 4) | (sort_by_value_ << 5) | (exclude_upgradable_ << 7) | (exclude_unupgradable_ << 8) | (peer_color_available_ << 9) | (exclude_hosted_ << 10)));
    if (var0 & 1) { s.store_field("exclude_unsaved", true); }
    if (var0 & 2) { s.store_field("exclude_saved", true); }
    if (var0 & 4) { s.store_field("exclude_unlimited", true); }
    if (var0 & 16) { s.store_field("exclude_unique", true); }
    if (var0 & 32) { s.store_field("sort_by_value", true); }
    if (var0 & 128) { s.store_field("exclude_upgradable", true); }
    if (var0 & 256) { s.store_field("exclude_unupgradable", true); }
    if (var0 & 512) { s.store_field("peer_color_available", true); }
    if (var0 & 1024) { s.store_field("exclude_hosted", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 64) { s.store_field("collection_id", collection_id_); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

payments_getSavedStarGifts::ReturnType payments_getSavedStarGifts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_savedStarGifts>, -1779201615>::parse(p);
#undef FAIL
}

payments_getStarsTransactions::payments_getStarsTransactions(int32 flags_, bool inbound_, bool outbound_, bool ascending_, bool ton_, string const &subscription_id_, object_ptr<InputPeer> &&peer_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , inbound_(inbound_)
  , outbound_(outbound_)
  , ascending_(ascending_)
  , ton_(ton_)
  , subscription_id_(subscription_id_)
  , peer_(std::move(peer_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t payments_getStarsTransactions::ID;

void payments_getStarsTransactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1775912279);
  TlStoreBinary::store((var0 = flags_ | (inbound_ << 0) | (outbound_ << 1) | (ascending_ << 2) | (ton_ << 4)), s);
  if (var0 & 8) { TlStoreString::store(subscription_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getStarsTransactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1775912279);
  TlStoreBinary::store((var0 = flags_ | (inbound_ << 0) | (outbound_ << 1) | (ascending_ << 2) | (ton_ << 4)), s);
  if (var0 & 8) { TlStoreString::store(subscription_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getStarsTransactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsTransactions");
    s.store_field("flags", (var0 = flags_ | (inbound_ << 0) | (outbound_ << 1) | (ascending_ << 2) | (ton_ << 4)));
    if (var0 & 1) { s.store_field("inbound", true); }
    if (var0 & 2) { s.store_field("outbound", true); }
    if (var0 & 4) { s.store_field("ascending", true); }
    if (var0 & 16) { s.store_field("ton", true); }
    if (var0 & 8) { s.store_field("subscription_id", subscription_id_); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

payments_getStarsTransactions::ReturnType payments_getStarsTransactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsStatus>, 1822222573>::parse(p);
#undef FAIL
}

payments_upgradeStarGift::payments_upgradeStarGift(int32 flags_, bool keep_original_details_, object_ptr<InputSavedStarGift> &&stargift_)
  : flags_(flags_)
  , keep_original_details_(keep_original_details_)
  , stargift_(std::move(stargift_))
{}

const std::int32_t payments_upgradeStarGift::ID;

void payments_upgradeStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1361648395);
  TlStoreBinary::store((var0 = flags_ | (keep_original_details_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_upgradeStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1361648395);
  TlStoreBinary::store((var0 = flags_ | (keep_original_details_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_upgradeStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.upgradeStarGift");
    s.store_field("flags", (var0 = flags_ | (keep_original_details_ << 0)));
    if (var0 & 1) { s.store_field("keep_original_details", true); }
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

payments_upgradeStarGift::ReturnType payments_upgradeStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_validateRequestedInfo::payments_validateRequestedInfo(int32 flags_, bool save_, object_ptr<InputInvoice> &&invoice_, object_ptr<paymentRequestedInfo> &&info_)
  : flags_(flags_)
  , save_(save_)
  , invoice_(std::move(invoice_))
  , info_(std::move(info_))
{}

const std::int32_t payments_validateRequestedInfo::ID;

void payments_validateRequestedInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1228345045);
  TlStoreBinary::store((var0 = flags_ | (save_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
  TlStoreBoxed<TlStoreObject, -1868808300>::store(info_, s);
}

void payments_validateRequestedInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1228345045);
  TlStoreBinary::store((var0 = flags_ | (save_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
  TlStoreBoxed<TlStoreObject, -1868808300>::store(info_, s);
}

void payments_validateRequestedInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.validateRequestedInfo");
    s.store_field("flags", (var0 = flags_ | (save_ << 0)));
    if (var0 & 1) { s.store_field("save", true); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

payments_validateRequestedInfo::ReturnType payments_validateRequestedInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_validatedRequestedInfo>, -784000893>::parse(p);
#undef FAIL
}

phone_confirmCall::phone_confirmCall(object_ptr<inputPhoneCall> &&peer_, bytes &&g_a_, int64 key_fingerprint_, object_ptr<phoneCallProtocol> &&protocol_)
  : peer_(std::move(peer_))
  , g_a_(std::move(g_a_))
  , key_fingerprint_(key_fingerprint_)
  , protocol_(std::move(protocol_))
{}

const std::int32_t phone_confirmCall::ID;

void phone_confirmCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(788404002);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreString::store(g_a_, s);
  TlStoreBinary::store(key_fingerprint_, s);
  TlStoreBoxed<TlStoreObject, -58224696>::store(protocol_, s);
}

void phone_confirmCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(788404002);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreString::store(g_a_, s);
  TlStoreBinary::store(key_fingerprint_, s);
  TlStoreBoxed<TlStoreObject, -58224696>::store(protocol_, s);
}

void phone_confirmCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.confirmCall");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_bytes_field("g_a", g_a_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

phone_confirmCall::ReturnType phone_confirmCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_phoneCall>, -326966976>::parse(p);
#undef FAIL
}

phone_getGroupCall::phone_getGroupCall(object_ptr<InputGroupCall> &&call_, int32 limit_)
  : call_(std::move(call_))
  , limit_(limit_)
{}

const std::int32_t phone_getGroupCall::ID;

void phone_getGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(68699611);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(limit_, s);
}

void phone_getGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(68699611);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(limit_, s);
}

void phone_getGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

phone_getGroupCall::ReturnType phone_getGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_groupCall>, -1636664659>::parse(p);
#undef FAIL
}

phone_getGroupCallStars::phone_getGroupCallStars(object_ptr<InputGroupCall> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t phone_getGroupCallStars::ID;

void phone_getGroupCallStars::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1868784386);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_getGroupCallStars::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1868784386);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_getGroupCallStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupCallStars");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

phone_getGroupCallStars::ReturnType phone_getGroupCallStars::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_groupCallStars>, -1658995418>::parse(p);
#undef FAIL
}

phone_getGroupCallStreamRtmpUrl::phone_getGroupCallStreamRtmpUrl(int32 flags_, bool live_story_, object_ptr<InputPeer> &&peer_, bool revoke_)
  : flags_(flags_)
  , live_story_(live_story_)
  , peer_(std::move(peer_))
  , revoke_(revoke_)
{}

const std::int32_t phone_getGroupCallStreamRtmpUrl::ID;

void phone_getGroupCallStreamRtmpUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1525991226);
  TlStoreBinary::store((var0 = flags_ | (live_story_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(revoke_, s);
}

void phone_getGroupCallStreamRtmpUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1525991226);
  TlStoreBinary::store((var0 = flags_ | (live_story_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(revoke_, s);
}

void phone_getGroupCallStreamRtmpUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupCallStreamRtmpUrl");
    s.store_field("flags", (var0 = flags_ | (live_story_ << 0)));
    if (var0 & 1) { s.store_field("live_story", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

phone_getGroupCallStreamRtmpUrl::ReturnType phone_getGroupCallStreamRtmpUrl::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_groupCallStreamRtmpUrl>, 767505458>::parse(p);
#undef FAIL
}

photos_deletePhotos::photos_deletePhotos(array<object_ptr<InputPhoto>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t photos_deletePhotos::ID;

void photos_deletePhotos::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2016444625);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void photos_deletePhotos::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2016444625);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void photos_deletePhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.deletePhotos");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

photos_deletePhotos::ReturnType photos_deletePhotos::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p);
#undef FAIL
}

smsjobs_finishJob::smsjobs_finishJob(int32 flags_, string const &job_id_, string const &error_)
  : flags_(flags_)
  , job_id_(job_id_)
  , error_(error_)
{}

const std::int32_t smsjobs_finishJob::ID;

void smsjobs_finishJob::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1327415076);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(job_id_, s);
  if (var0 & 1) { TlStoreString::store(error_, s); }
}

void smsjobs_finishJob::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1327415076);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(job_id_, s);
  if (var0 & 1) { TlStoreString::store(error_, s); }
}

void smsjobs_finishJob::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.finishJob");
    s.store_field("flags", (var0 = flags_));
    s.store_field("job_id", job_id_);
    if (var0 & 1) { s.store_field("error", error_); }
    s.store_class_end();
  }
}

smsjobs_finishJob::ReturnType smsjobs_finishJob::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t smsjobs_isEligibleToJoin::ID;

void smsjobs_isEligibleToJoin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(249313744);
}

void smsjobs_isEligibleToJoin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(249313744);
}

void smsjobs_isEligibleToJoin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.isEligibleToJoin");
    s.store_class_end();
  }
}

smsjobs_isEligibleToJoin::ReturnType smsjobs_isEligibleToJoin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<smsjobs_eligibleToJoin>, -594852657>::parse(p);
#undef FAIL
}

stickers_createStickerSet::stickers_createStickerSet(int32 flags_, bool masks_, bool emojis_, bool text_color_, object_ptr<InputUser> &&user_id_, string const &title_, string const &short_name_, object_ptr<InputDocument> &&thumb_, array<object_ptr<inputStickerSetItem>> &&stickers_, string const &software_)
  : flags_(flags_)
  , masks_(masks_)
  , emojis_(emojis_)
  , text_color_(text_color_)
  , user_id_(std::move(user_id_))
  , title_(title_)
  , short_name_(short_name_)
  , thumb_(std::move(thumb_))
  , stickers_(std::move(stickers_))
  , software_(software_)
{}

const std::int32_t stickers_createStickerSet::ID;

void stickers_createStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1876841625);
  TlStoreBinary::store((var0 = flags_ | (masks_ << 0) | (emojis_ << 5) | (text_color_ << 6)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(short_name_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 853188252>>, 481674261>::store(stickers_, s);
  if (var0 & 8) { TlStoreString::store(software_, s); }
}

void stickers_createStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1876841625);
  TlStoreBinary::store((var0 = flags_ | (masks_ << 0) | (emojis_ << 5) | (text_color_ << 6)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(short_name_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 853188252>>, 481674261>::store(stickers_, s);
  if (var0 & 8) { TlStoreString::store(software_, s); }
}

void stickers_createStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.createStickerSet");
    s.store_field("flags", (var0 = flags_ | (masks_ << 0) | (emojis_ << 5) | (text_color_ << 6)));
    if (var0 & 1) { s.store_field("masks", true); }
    if (var0 & 32) { s.store_field("emojis", true); }
    if (var0 & 64) { s.store_field("text_color", true); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("title", title_);
    s.store_field("short_name", short_name_);
    if (var0 & 4) { s.store_object_field("thumb", static_cast<const BaseObject *>(thumb_.get())); }
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 8) { s.store_field("software", software_); }
    s.store_class_end();
  }
}

stickers_createStickerSet::ReturnType stickers_createStickerSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stories_activateStealthMode::stories_activateStealthMode(int32 flags_, bool past_, bool future_)
  : flags_(flags_)
  , past_(past_)
  , future_(future_)
{}

const std::int32_t stories_activateStealthMode::ID;

void stories_activateStealthMode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1471926630);
  TlStoreBinary::store((var0 = flags_ | (past_ << 0) | (future_ << 1)), s);
}

void stories_activateStealthMode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1471926630);
  TlStoreBinary::store((var0 = flags_ | (past_ << 0) | (future_ << 1)), s);
}

void stories_activateStealthMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.activateStealthMode");
    s.store_field("flags", (var0 = flags_ | (past_ << 0) | (future_ << 1)));
    if (var0 & 1) { s.store_field("past", true); }
    if (var0 & 2) { s.store_field("future", true); }
    s.store_class_end();
  }
}

stories_activateStealthMode::ReturnType stories_activateStealthMode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

stories_getStoriesViews::stories_getStoriesViews(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t stories_getStoriesViews::ID;

void stories_getStoriesViews::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(685862088);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_getStoriesViews::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(685862088);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_getStoriesViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getStoriesViews");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_getStoriesViews::ReturnType stories_getStoriesViews::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_storyViews>, -560009955>::parse(p);
#undef FAIL
}

stories_reorderAlbums::stories_reorderAlbums(object_ptr<InputPeer> &&peer_, array<int32> &&order_)
  : peer_(std::move(peer_))
  , order_(std::move(order_))
{}

const std::int32_t stories_reorderAlbums::ID;

void stories_reorderAlbums::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2060059687);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void stories_reorderAlbums::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2060059687);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void stories_reorderAlbums::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.reorderAlbums");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_reorderAlbums::ReturnType stories_reorderAlbums::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t updates_getState::ID;

void updates_getState::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-304838614);
}

void updates_getState::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-304838614);
}

void updates_getState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.getState");
    s.store_class_end();
  }
}

updates_getState::ReturnType updates_getState::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<updates_state>, -1519637954>::parse(p);
#undef FAIL
}

upload_saveFilePart::upload_saveFilePart(int64 file_id_, int32 file_part_, bytes &&bytes_)
  : file_id_(file_id_)
  , file_part_(file_part_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t upload_saveFilePart::ID;

void upload_saveFilePart::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1291540959);
  TlStoreBinary::store(file_id_, s);
  TlStoreBinary::store(file_part_, s);
  TlStoreString::store(bytes_, s);
}

void upload_saveFilePart::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1291540959);
  TlStoreBinary::store(file_id_, s);
  TlStoreBinary::store(file_part_, s);
  TlStoreString::store(bytes_, s);
}

void upload_saveFilePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.saveFilePart");
    s.store_field("file_id", file_id_);
    s.store_field("file_part", file_part_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

upload_saveFilePart::ReturnType upload_saveFilePart::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
