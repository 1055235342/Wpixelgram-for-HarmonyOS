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


attachMenuBot::attachMenuBot()
  : flags_()
  , inactive_()
  , has_settings_()
  , request_write_access_()
  , show_in_attach_menu_()
  , show_in_side_menu_()
  , side_menu_disclaimer_needed_()
  , bot_id_()
  , short_name_()
  , peer_types_()
  , icons_()
{}

const std::int32_t attachMenuBot::ID;

object_ptr<attachMenuBot> attachMenuBot::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<attachMenuBot> res = make_tl_object<attachMenuBot>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inactive_ = (var0 & 1) != 0;
  res->has_settings_ = (var0 & 2) != 0;
  res->request_write_access_ = (var0 & 4) != 0;
  res->show_in_attach_menu_ = (var0 & 8) != 0;
  res->show_in_side_menu_ = (var0 & 16) != 0;
  res->side_menu_disclaimer_needed_ = (var0 & 32) != 0;
  res->bot_id_ = TlFetchLong::parse(p);
  res->short_name_ = TlFetchString<string>::parse(p);
  if (var0 & 8) { res->peer_types_ = TlFetchBoxed<TlFetchVector<TlFetchObject<AttachMenuPeerType>>, 481674261>::parse(p); }
  res->icons_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<attachMenuBotIcon>, -1297663893>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void attachMenuBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuBot");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inactive_ << 0) | (has_settings_ << 1) | (request_write_access_ << 2) | (show_in_attach_menu_ << 3) | (show_in_side_menu_ << 4) | (side_menu_disclaimer_needed_ << 5)));
    if (var0 & 1) { s.store_field("inactive", true); }
    if (var0 & 2) { s.store_field("has_settings", true); }
    if (var0 & 4) { s.store_field("request_write_access", true); }
    if (var0 & 8) { s.store_field("show_in_attach_menu", true); }
    if (var0 & 16) { s.store_field("show_in_side_menu", true); }
    if (var0 & 32) { s.store_field("side_menu_disclaimer_needed", true); }
    s.store_field("bot_id", bot_id_);
    s.store_field("short_name", short_name_);
    if (var0 & 8) { { s.store_vector_begin("peer_types", peer_types_.size()); for (const auto &_value : peer_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("icons", icons_.size()); for (const auto &_value : icons_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t autoSaveException::ID;

object_ptr<autoSaveException> autoSaveException::fetch(TlBufferParser &p) {
  return make_tl_object<autoSaveException>(p);
}

autoSaveException::autoSaveException(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , settings_(TlFetchBoxed<TlFetchObject<autoSaveSettings>, -934791986>::parse(p))
{}

void autoSaveException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autoSaveException");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

birthday::birthday()
  : flags_()
  , day_()
  , month_()
  , year_()
{}

birthday::birthday(int32 flags_, int32 day_, int32 month_, int32 year_)
  : flags_(flags_)
  , day_(day_)
  , month_(month_)
  , year_(year_)
{}

const std::int32_t birthday::ID;

object_ptr<birthday> birthday::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<birthday> res = make_tl_object<birthday>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->day_ = TlFetchInt::parse(p);
  res->month_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->year_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void birthday::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(day_, s);
  TlStoreBinary::store(month_, s);
  if (var0 & 1) { TlStoreBinary::store(year_, s); }
}

void birthday::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(day_, s);
  TlStoreBinary::store(month_, s);
  if (var0 & 1) { TlStoreBinary::store(year_, s); }
}

void birthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "birthday");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("day", day_);
    s.store_field("month", month_);
    if (var0 & 1) { s.store_field("year", year_); }
    s.store_class_end();
  }
}

businessLocation::businessLocation()
  : flags_()
  , geo_point_()
  , address_()
{}

const std::int32_t businessLocation::ID;

object_ptr<businessLocation> businessLocation::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessLocation> res = make_tl_object<businessLocation>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->geo_point_ = TlFetchObject<GeoPoint>::parse(p); }
  res->address_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessLocation");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get())); }
    s.store_field("address", address_);
    s.store_class_end();
  }
}

businessRecipients::businessRecipients()
  : flags_()
  , existing_chats_()
  , new_chats_()
  , contacts_()
  , non_contacts_()
  , exclude_selected_()
  , users_()
{}

const std::int32_t businessRecipients::ID;

object_ptr<businessRecipients> businessRecipients::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessRecipients> res = make_tl_object<businessRecipients>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->existing_chats_ = (var0 & 1) != 0;
  res->new_chats_ = (var0 & 2) != 0;
  res->contacts_ = (var0 & 4) != 0;
  res->non_contacts_ = (var0 & 8) != 0;
  res->exclude_selected_ = (var0 & 32) != 0;
  if (var0 & 16) { res->users_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessRecipients::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessRecipients");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5)));
    if (var0 & 1) { s.store_field("existing_chats", true); }
    if (var0 & 2) { s.store_field("new_chats", true); }
    if (var0 & 4) { s.store_field("contacts", true); }
    if (var0 & 8) { s.store_field("non_contacts", true); }
    if (var0 & 32) { s.store_field("exclude_selected", true); }
    if (var0 & 16) { { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t chatAdminWithInvites::ID;

object_ptr<chatAdminWithInvites> chatAdminWithInvites::fetch(TlBufferParser &p) {
  return make_tl_object<chatAdminWithInvites>(p);
}

chatAdminWithInvites::chatAdminWithInvites(TlBufferParser &p)
  : admin_id_(TlFetchLong::parse(p))
  , invites_count_(TlFetchInt::parse(p))
  , revoked_invites_count_(TlFetchInt::parse(p))
{}

void chatAdminWithInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdminWithInvites");
    s.store_field("admin_id", admin_id_);
    s.store_field("invites_count", invites_count_);
    s.store_field("revoked_invites_count", revoked_invites_count_);
    s.store_class_end();
  }
}

object_ptr<ChatInvite> ChatInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatInviteAlready::ID:
      return chatInviteAlready::fetch(p);
    case chatInvite::ID:
      return chatInvite::fetch(p);
    case chatInvitePeek::ID:
      return chatInvitePeek::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t chatInviteAlready::ID;

object_ptr<ChatInvite> chatInviteAlready::fetch(TlBufferParser &p) {
  return make_tl_object<chatInviteAlready>(p);
}

chatInviteAlready::chatInviteAlready(TlBufferParser &p)
  : chat_(TlFetchObject<Chat>::parse(p))
{}

void chatInviteAlready::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteAlready");
    s.store_object_field("chat", static_cast<const BaseObject *>(chat_.get()));
    s.store_class_end();
  }
}

chatInvite::chatInvite()
  : flags_()
  , channel_()
  , broadcast_()
  , public_()
  , megagroup_()
  , request_needed_()
  , verified_()
  , scam_()
  , fake_()
  , can_refulfill_subscription_()
  , title_()
  , about_()
  , photo_()
  , participants_count_()
  , participants_()
  , color_()
  , subscription_pricing_()
  , subscription_form_id_()
  , bot_verification_()
{}

const std::int32_t chatInvite::ID;

object_ptr<ChatInvite> chatInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatInvite> res = make_tl_object<chatInvite>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_ = (var0 & 1) != 0;
  res->broadcast_ = (var0 & 2) != 0;
  res->public_ = (var0 & 4) != 0;
  res->megagroup_ = (var0 & 8) != 0;
  res->request_needed_ = (var0 & 64) != 0;
  res->verified_ = (var0 & 128) != 0;
  res->scam_ = (var0 & 256) != 0;
  res->fake_ = (var0 & 512) != 0;
  res->can_refulfill_subscription_ = (var0 & 2048) != 0;
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 32) { res->about_ = TlFetchString<string>::parse(p); }
  res->photo_ = TlFetchObject<Photo>::parse(p);
  res->participants_count_ = TlFetchInt::parse(p);
  if (var0 & 16) { res->participants_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p); }
  res->color_ = TlFetchInt::parse(p);
  if (var0 & 1024) { res->subscription_pricing_ = TlFetchBoxed<TlFetchObject<starsSubscriptionPricing>, 88173912>::parse(p); }
  if (var0 & 4096) { res->subscription_form_id_ = TlFetchLong::parse(p); }
  if (var0 & 8192) { res->bot_verification_ = TlFetchBoxed<TlFetchObject<botVerification>, -113453988>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInvite");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (channel_ << 0) | (broadcast_ << 1) | (public_ << 2) | (megagroup_ << 3) | (request_needed_ << 6) | (verified_ << 7) | (scam_ << 8) | (fake_ << 9) | (can_refulfill_subscription_ << 11)));
    if (var0 & 1) { s.store_field("channel", true); }
    if (var0 & 2) { s.store_field("broadcast", true); }
    if (var0 & 4) { s.store_field("public", true); }
    if (var0 & 8) { s.store_field("megagroup", true); }
    if (var0 & 64) { s.store_field("request_needed", true); }
    if (var0 & 128) { s.store_field("verified", true); }
    if (var0 & 256) { s.store_field("scam", true); }
    if (var0 & 512) { s.store_field("fake", true); }
    if (var0 & 2048) { s.store_field("can_refulfill_subscription", true); }
    s.store_field("title", title_);
    if (var0 & 32) { s.store_field("about", about_); }
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("participants_count", participants_count_);
    if (var0 & 16) { { s.store_vector_begin("participants", participants_.size()); for (const auto &_value : participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("color", color_);
    if (var0 & 1024) { s.store_object_field("subscription_pricing", static_cast<const BaseObject *>(subscription_pricing_.get())); }
    if (var0 & 4096) { s.store_field("subscription_form_id", subscription_form_id_); }
    if (var0 & 8192) { s.store_object_field("bot_verification", static_cast<const BaseObject *>(bot_verification_.get())); }
    s.store_class_end();
  }
}

const std::int32_t chatInvitePeek::ID;

object_ptr<ChatInvite> chatInvitePeek::fetch(TlBufferParser &p) {
  return make_tl_object<chatInvitePeek>(p);
}

chatInvitePeek::chatInvitePeek(TlBufferParser &p)
  : chat_(TlFetchObject<Chat>::parse(p))
  , expires_(TlFetchInt::parse(p))
{}

void chatInvitePeek::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInvitePeek");
    s.store_object_field("chat", static_cast<const BaseObject *>(chat_.get()));
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

object_ptr<ChatParticipants> ChatParticipants::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatParticipantsForbidden::ID:
      return chatParticipantsForbidden::fetch(p);
    case chatParticipants::ID:
      return chatParticipants::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

chatParticipantsForbidden::chatParticipantsForbidden()
  : flags_()
  , chat_id_()
  , self_participant_()
{}

const std::int32_t chatParticipantsForbidden::ID;

object_ptr<ChatParticipants> chatParticipantsForbidden::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatParticipantsForbidden> res = make_tl_object<chatParticipantsForbidden>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->chat_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->self_participant_ = TlFetchObject<ChatParticipant>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatParticipantsForbidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatParticipantsForbidden");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("chat_id", chat_id_);
    if (var0 & 1) { s.store_object_field("self_participant", static_cast<const BaseObject *>(self_participant_.get())); }
    s.store_class_end();
  }
}

const std::int32_t chatParticipants::ID;

object_ptr<ChatParticipants> chatParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<chatParticipants>(p);
}

chatParticipants::chatParticipants(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
  , participants_(TlFetchBoxed<TlFetchVector<TlFetchObject<ChatParticipant>>, 481674261>::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void chatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatParticipants");
    s.store_field("chat_id", chat_id_);
    { s.store_vector_begin("participants", participants_.size()); for (const auto &_value : participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("version", version_);
    s.store_class_end();
  }
}

object_ptr<ChatReactions> ChatReactions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatReactionsNone::ID:
      return chatReactionsNone::fetch(p);
    case chatReactionsAll::ID:
      return chatReactionsAll::fetch(p);
    case chatReactionsSome::ID:
      return chatReactionsSome::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t chatReactionsNone::ID;

object_ptr<ChatReactions> chatReactionsNone::fetch(TlBufferParser &p) {
  return make_tl_object<chatReactionsNone>();
}

void chatReactionsNone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void chatReactionsNone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void chatReactionsNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReactionsNone");
    s.store_class_end();
  }
}

chatReactionsAll::chatReactionsAll()
  : flags_()
  , allow_custom_()
{}

chatReactionsAll::chatReactionsAll(int32 flags_, bool allow_custom_)
  : flags_(flags_)
  , allow_custom_(allow_custom_)
{}

const std::int32_t chatReactionsAll::ID;

object_ptr<ChatReactions> chatReactionsAll::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatReactionsAll> res = make_tl_object<chatReactionsAll>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->allow_custom_ = (var0 & 1) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatReactionsAll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (allow_custom_ << 0)), s);
}

void chatReactionsAll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (allow_custom_ << 0)), s);
}

void chatReactionsAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReactionsAll");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (allow_custom_ << 0)));
    if (var0 & 1) { s.store_field("allow_custom", true); }
    s.store_class_end();
  }
}

chatReactionsSome::chatReactionsSome(array<object_ptr<Reaction>> &&reactions_)
  : reactions_(std::move(reactions_))
{}

const std::int32_t chatReactionsSome::ID;

object_ptr<ChatReactions> chatReactionsSome::fetch(TlBufferParser &p) {
  return make_tl_object<chatReactionsSome>(p);
}

chatReactionsSome::chatReactionsSome(TlBufferParser &p)
  : reactions_(TlFetchBoxed<TlFetchVector<TlFetchObject<Reaction>>, 481674261>::parse(p))
{}

void chatReactionsSome::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(reactions_, s);
}

void chatReactionsSome::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(reactions_, s);
}

void chatReactionsSome::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatReactionsSome");
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

connectedBot::connectedBot()
  : flags_()
  , bot_id_()
  , recipients_()
  , rights_()
{}

const std::int32_t connectedBot::ID;

object_ptr<connectedBot> connectedBot::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<connectedBot> res = make_tl_object<connectedBot>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bot_id_ = TlFetchLong::parse(p);
  res->recipients_ = TlFetchBoxed<TlFetchObject<businessBotRecipients>, -1198722189>::parse(p);
  res->rights_ = TlFetchBoxed<TlFetchObject<businessBotRights>, -1604170505>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void connectedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "connectedBot");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("bot_id", bot_id_);
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get()));
    s.store_class_end();
  }
}

dataJSON::dataJSON(string const &data_)
  : data_(data_)
{}

const std::int32_t dataJSON::ID;

object_ptr<dataJSON> dataJSON::fetch(TlBufferParser &p) {
  return make_tl_object<dataJSON>(p);
}

dataJSON::dataJSON(TlBufferParser &p)
  : data_(TlFetchString<string>::parse(p))
{}

void dataJSON::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(data_, s);
}

void dataJSON::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(data_, s);
}

void dataJSON::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dataJSON");
    s.store_field("data", data_);
    s.store_class_end();
  }
}

object_ptr<DialogFilter> DialogFilter::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case dialogFilter::ID:
      return dialogFilter::fetch(p);
    case dialogFilterDefault::ID:
      return dialogFilterDefault::fetch(p);
    case dialogFilterChatlist::ID:
      return dialogFilterChatlist::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

dialogFilter::dialogFilter()
  : flags_()
  , contacts_()
  , non_contacts_()
  , groups_()
  , broadcasts_()
  , bots_()
  , exclude_muted_()
  , exclude_read_()
  , exclude_archived_()
  , title_noanimate_()
  , id_()
  , title_()
  , emoticon_()
  , color_()
  , pinned_peers_()
  , include_peers_()
  , exclude_peers_()
{}

dialogFilter::dialogFilter(int32 flags_, bool contacts_, bool non_contacts_, bool groups_, bool broadcasts_, bool bots_, bool exclude_muted_, bool exclude_read_, bool exclude_archived_, bool title_noanimate_, int32 id_, object_ptr<textWithEntities> &&title_, string const &emoticon_, int32 color_, array<object_ptr<InputPeer>> &&pinned_peers_, array<object_ptr<InputPeer>> &&include_peers_, array<object_ptr<InputPeer>> &&exclude_peers_)
  : flags_(flags_)
  , contacts_(contacts_)
  , non_contacts_(non_contacts_)
  , groups_(groups_)
  , broadcasts_(broadcasts_)
  , bots_(bots_)
  , exclude_muted_(exclude_muted_)
  , exclude_read_(exclude_read_)
  , exclude_archived_(exclude_archived_)
  , title_noanimate_(title_noanimate_)
  , id_(id_)
  , title_(std::move(title_))
  , emoticon_(emoticon_)
  , color_(color_)
  , pinned_peers_(std::move(pinned_peers_))
  , include_peers_(std::move(include_peers_))
  , exclude_peers_(std::move(exclude_peers_))
{}

const std::int32_t dialogFilter::ID;

object_ptr<DialogFilter> dialogFilter::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<dialogFilter> res = make_tl_object<dialogFilter>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->contacts_ = (var0 & 1) != 0;
  res->non_contacts_ = (var0 & 2) != 0;
  res->groups_ = (var0 & 4) != 0;
  res->broadcasts_ = (var0 & 8) != 0;
  res->bots_ = (var0 & 16) != 0;
  res->exclude_muted_ = (var0 & 2048) != 0;
  res->exclude_read_ = (var0 & 4096) != 0;
  res->exclude_archived_ = (var0 & 8192) != 0;
  res->title_noanimate_ = (var0 & 268435456) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->title_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (var0 & 33554432) { res->emoticon_ = TlFetchString<string>::parse(p); }
  if (var0 & 134217728) { res->color_ = TlFetchInt::parse(p); }
  res->pinned_peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputPeer>>, 481674261>::parse(p);
  res->include_peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputPeer>>, 481674261>::parse(p);
  res->exclude_peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputPeer>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void dialogFilter::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (contacts_ << 0) | (non_contacts_ << 1) | (groups_ << 2) | (broadcasts_ << 3) | (bots_ << 4) | (exclude_muted_ << 11) | (exclude_read_ << 12) | (exclude_archived_ << 13) | (title_noanimate_ << 28)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
  if (var0 & 33554432) { TlStoreString::store(emoticon_, s); }
  if (var0 & 134217728) { TlStoreBinary::store(color_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(pinned_peers_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(include_peers_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(exclude_peers_, s);
}

void dialogFilter::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (contacts_ << 0) | (non_contacts_ << 1) | (groups_ << 2) | (broadcasts_ << 3) | (bots_ << 4) | (exclude_muted_ << 11) | (exclude_read_ << 12) | (exclude_archived_ << 13) | (title_noanimate_ << 28)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
  if (var0 & 33554432) { TlStoreString::store(emoticon_, s); }
  if (var0 & 134217728) { TlStoreBinary::store(color_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(pinned_peers_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(include_peers_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(exclude_peers_, s);
}

void dialogFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogFilter");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (contacts_ << 0) | (non_contacts_ << 1) | (groups_ << 2) | (broadcasts_ << 3) | (bots_ << 4) | (exclude_muted_ << 11) | (exclude_read_ << 12) | (exclude_archived_ << 13) | (title_noanimate_ << 28)));
    if (var0 & 1) { s.store_field("contacts", true); }
    if (var0 & 2) { s.store_field("non_contacts", true); }
    if (var0 & 4) { s.store_field("groups", true); }
    if (var0 & 8) { s.store_field("broadcasts", true); }
    if (var0 & 16) { s.store_field("bots", true); }
    if (var0 & 2048) { s.store_field("exclude_muted", true); }
    if (var0 & 4096) { s.store_field("exclude_read", true); }
    if (var0 & 8192) { s.store_field("exclude_archived", true); }
    if (var0 & 268435456) { s.store_field("title_noanimate", true); }
    s.store_field("id", id_);
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    if (var0 & 33554432) { s.store_field("emoticon", emoticon_); }
    if (var0 & 134217728) { s.store_field("color", color_); }
    { s.store_vector_begin("pinned_peers", pinned_peers_.size()); for (const auto &_value : pinned_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("include_peers", include_peers_.size()); for (const auto &_value : include_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("exclude_peers", exclude_peers_.size()); for (const auto &_value : exclude_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t dialogFilterDefault::ID;

object_ptr<DialogFilter> dialogFilterDefault::fetch(TlBufferParser &p) {
  return make_tl_object<dialogFilterDefault>();
}

void dialogFilterDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void dialogFilterDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void dialogFilterDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogFilterDefault");
    s.store_class_end();
  }
}

dialogFilterChatlist::dialogFilterChatlist()
  : flags_()
  , has_my_invites_()
  , title_noanimate_()
  , id_()
  , title_()
  , emoticon_()
  , color_()
  , pinned_peers_()
  , include_peers_()
{}

dialogFilterChatlist::dialogFilterChatlist(int32 flags_, bool has_my_invites_, bool title_noanimate_, int32 id_, object_ptr<textWithEntities> &&title_, string const &emoticon_, int32 color_, array<object_ptr<InputPeer>> &&pinned_peers_, array<object_ptr<InputPeer>> &&include_peers_)
  : flags_(flags_)
  , has_my_invites_(has_my_invites_)
  , title_noanimate_(title_noanimate_)
  , id_(id_)
  , title_(std::move(title_))
  , emoticon_(emoticon_)
  , color_(color_)
  , pinned_peers_(std::move(pinned_peers_))
  , include_peers_(std::move(include_peers_))
{}

const std::int32_t dialogFilterChatlist::ID;

object_ptr<DialogFilter> dialogFilterChatlist::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<dialogFilterChatlist> res = make_tl_object<dialogFilterChatlist>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_my_invites_ = (var0 & 67108864) != 0;
  res->title_noanimate_ = (var0 & 268435456) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->title_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (var0 & 33554432) { res->emoticon_ = TlFetchString<string>::parse(p); }
  if (var0 & 134217728) { res->color_ = TlFetchInt::parse(p); }
  res->pinned_peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputPeer>>, 481674261>::parse(p);
  res->include_peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputPeer>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void dialogFilterChatlist::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_my_invites_ << 26) | (title_noanimate_ << 28)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
  if (var0 & 33554432) { TlStoreString::store(emoticon_, s); }
  if (var0 & 134217728) { TlStoreBinary::store(color_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(pinned_peers_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(include_peers_, s);
}

void dialogFilterChatlist::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_my_invites_ << 26) | (title_noanimate_ << 28)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
  if (var0 & 33554432) { TlStoreString::store(emoticon_, s); }
  if (var0 & 134217728) { TlStoreBinary::store(color_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(pinned_peers_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(include_peers_, s);
}

void dialogFilterChatlist::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dialogFilterChatlist");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_my_invites_ << 26) | (title_noanimate_ << 28)));
    if (var0 & 67108864) { s.store_field("has_my_invites", true); }
    if (var0 & 268435456) { s.store_field("title_noanimate", true); }
    s.store_field("id", id_);
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    if (var0 & 33554432) { s.store_field("emoticon", emoticon_); }
    if (var0 & 134217728) { s.store_field("color", color_); }
    { s.store_vector_begin("pinned_peers", pinned_peers_.size()); for (const auto &_value : pinned_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("include_peers", include_peers_.size()); for (const auto &_value : include_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<DraftMessage> DraftMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case draftMessageEmpty::ID:
      return draftMessageEmpty::fetch(p);
    case draftMessage::ID:
      return draftMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

draftMessageEmpty::draftMessageEmpty()
  : flags_()
  , date_()
{}

const std::int32_t draftMessageEmpty::ID;

object_ptr<DraftMessage> draftMessageEmpty::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<draftMessageEmpty> res = make_tl_object<draftMessageEmpty>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void draftMessageEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "draftMessageEmpty");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("date", date_); }
    s.store_class_end();
  }
}

draftMessage::draftMessage()
  : flags_()
  , no_webpage_()
  , invert_media_()
  , reply_to_()
  , message_()
  , entities_()
  , media_()
  , date_()
  , effect_()
  , suggested_post_()
{}

const std::int32_t draftMessage::ID;

object_ptr<DraftMessage> draftMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<draftMessage> res = make_tl_object<draftMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->no_webpage_ = (var0 & 2) != 0;
  res->invert_media_ = (var0 & 64) != 0;
  if (var0 & 16) { res->reply_to_ = TlFetchObject<InputReplyTo>::parse(p); }
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 8) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 32) { res->media_ = TlFetchObject<InputMedia>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 128) { res->effect_ = TlFetchLong::parse(p); }
  if (var0 & 256) { res->suggested_post_ = TlFetchBoxed<TlFetchObject<suggestedPost>, 244201445>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void draftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "draftMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 6)));
    if (var0 & 2) { s.store_field("no_webpage", true); }
    if (var0 & 64) { s.store_field("invert_media", true); }
    if (var0 & 16) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_field("message", message_);
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 32) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    s.store_field("date", date_);
    if (var0 & 128) { s.store_field("effect", effect_); }
    if (var0 & 256) { s.store_object_field("suggested_post", static_cast<const BaseObject *>(suggested_post_.get())); }
    s.store_class_end();
  }
}

emailVerificationCode::emailVerificationCode(string const &code_)
  : code_(code_)
{}

const std::int32_t emailVerificationCode::ID;

void emailVerificationCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(code_, s);
}

void emailVerificationCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(code_, s);
}

void emailVerificationCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailVerificationCode");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

emailVerificationGoogle::emailVerificationGoogle(string const &token_)
  : token_(token_)
{}

const std::int32_t emailVerificationGoogle::ID;

void emailVerificationGoogle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(token_, s);
}

void emailVerificationGoogle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(token_, s);
}

void emailVerificationGoogle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailVerificationGoogle");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

emailVerificationApple::emailVerificationApple(string const &token_)
  : token_(token_)
{}

const std::int32_t emailVerificationApple::ID;

void emailVerificationApple::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(token_, s);
}

void emailVerificationApple::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(token_, s);
}

void emailVerificationApple::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailVerificationApple");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

exportedChatlistInvite::exportedChatlistInvite()
  : flags_()
  , title_()
  , url_()
  , peers_()
{}

const std::int32_t exportedChatlistInvite::ID;

object_ptr<exportedChatlistInvite> exportedChatlistInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<exportedChatlistInvite> res = make_tl_object<exportedChatlistInvite>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->title_ = TlFetchString<string>::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  res->peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void exportedChatlistInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "exportedChatlistInvite");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("title", title_);
    s.store_field("url", url_);
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t exportedStoryLink::ID;

object_ptr<exportedStoryLink> exportedStoryLink::fetch(TlBufferParser &p) {
  return make_tl_object<exportedStoryLink>(p);
}

exportedStoryLink::exportedStoryLink(TlBufferParser &p)
  : link_(TlFetchString<string>::parse(p))
{}

void exportedStoryLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "exportedStoryLink");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

folder::folder()
  : flags_()
  , autofill_new_broadcasts_()
  , autofill_public_groups_()
  , autofill_new_correspondents_()
  , id_()
  , title_()
  , photo_()
{}

const std::int32_t folder::ID;

object_ptr<folder> folder::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<folder> res = make_tl_object<folder>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->autofill_new_broadcasts_ = (var0 & 1) != 0;
  res->autofill_public_groups_ = (var0 & 2) != 0;
  res->autofill_new_correspondents_ = (var0 & 4) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 8) { res->photo_ = TlFetchObject<ChatPhoto>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void folder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "folder");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (autofill_new_broadcasts_ << 0) | (autofill_public_groups_ << 1) | (autofill_new_correspondents_ << 2)));
    if (var0 & 1) { s.store_field("autofill_new_broadcasts", true); }
    if (var0 & 2) { s.store_field("autofill_public_groups", true); }
    if (var0 & 4) { s.store_field("autofill_new_correspondents", true); }
    s.store_field("id", id_);
    s.store_field("title", title_);
    if (var0 & 8) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_class_end();
  }
}

groupCallMessage::groupCallMessage()
  : flags_()
  , from_admin_()
  , id_()
  , from_id_()
  , date_()
  , message_()
  , paid_message_stars_()
{}

const std::int32_t groupCallMessage::ID;

object_ptr<groupCallMessage> groupCallMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<groupCallMessage> res = make_tl_object<groupCallMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->from_admin_ = (var0 & 2) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->from_id_ = TlFetchObject<Peer>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (var0 & 1) { res->paid_message_stars_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void groupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (from_admin_ << 1)));
    if (var0 & 2) { s.store_field("from_admin", true); }
    s.store_field("id", id_);
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    s.store_field("date", date_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    if (var0 & 1) { s.store_field("paid_message_stars", paid_message_stars_); }
    s.store_class_end();
  }
}

inputBusinessRecipients::inputBusinessRecipients(int32 flags_, bool existing_chats_, bool new_chats_, bool contacts_, bool non_contacts_, bool exclude_selected_, array<object_ptr<InputUser>> &&users_)
  : flags_(flags_)
  , existing_chats_(existing_chats_)
  , new_chats_(new_chats_)
  , contacts_(contacts_)
  , non_contacts_(non_contacts_)
  , exclude_selected_(exclude_selected_)
  , users_(std::move(users_))
{}

const std::int32_t inputBusinessRecipients::ID;

void inputBusinessRecipients::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5)), s);
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s); }
}

void inputBusinessRecipients::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5)), s);
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s); }
}

void inputBusinessRecipients::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessRecipients");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5)));
    if (var0 & 1) { s.store_field("existing_chats", true); }
    if (var0 & 2) { s.store_field("new_chats", true); }
    if (var0 & 4) { s.store_field("contacts", true); }
    if (var0 & 8) { s.store_field("non_contacts", true); }
    if (var0 & 32) { s.store_field("exclude_selected", true); }
    if (var0 & 16) { { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

inputNotifyPeer::inputNotifyPeer(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t inputNotifyPeer::ID;

void inputNotifyPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void inputNotifyPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void inputNotifyPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputNotifyPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

const std::int32_t inputNotifyUsers::ID;

void inputNotifyUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputNotifyUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputNotifyUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputNotifyUsers");
    s.store_class_end();
  }
}

const std::int32_t inputNotifyChats::ID;

void inputNotifyChats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputNotifyChats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputNotifyChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputNotifyChats");
    s.store_class_end();
  }
}

const std::int32_t inputNotifyBroadcasts::ID;

void inputNotifyBroadcasts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputNotifyBroadcasts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputNotifyBroadcasts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputNotifyBroadcasts");
    s.store_class_end();
  }
}

inputNotifyForumTopic::inputNotifyForumTopic(object_ptr<InputPeer> &&peer_, int32 top_msg_id_)
  : peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
{}

const std::int32_t inputNotifyForumTopic::ID;

void inputNotifyForumTopic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(top_msg_id_, s);
}

void inputNotifyForumTopic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(top_msg_id_, s);
}

void inputNotifyForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputNotifyForumTopic");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_msg_id", top_msg_id_);
    s.store_class_end();
  }
}

object_ptr<InputPeer> InputPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputPeerEmpty::ID:
      return inputPeerEmpty::fetch(p);
    case inputPeerSelf::ID:
      return inputPeerSelf::fetch(p);
    case inputPeerChat::ID:
      return inputPeerChat::fetch(p);
    case inputPeerUser::ID:
      return inputPeerUser::fetch(p);
    case inputPeerChannel::ID:
      return inputPeerChannel::fetch(p);
    case inputPeerUserFromMessage::ID:
      return inputPeerUserFromMessage::fetch(p);
    case inputPeerChannelFromMessage::ID:
      return inputPeerChannelFromMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputPeerEmpty::ID;

object_ptr<InputPeer> inputPeerEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerEmpty>();
}

void inputPeerEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPeerEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPeerEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerEmpty");
    s.store_class_end();
  }
}

const std::int32_t inputPeerSelf::ID;

object_ptr<InputPeer> inputPeerSelf::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerSelf>();
}

void inputPeerSelf::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPeerSelf::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPeerSelf::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerSelf");
    s.store_class_end();
  }
}

inputPeerChat::inputPeerChat(int64 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t inputPeerChat::ID;

object_ptr<InputPeer> inputPeerChat::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerChat>(p);
}

inputPeerChat::inputPeerChat(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
{}

void inputPeerChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(chat_id_, s);
}

void inputPeerChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(chat_id_, s);
}

void inputPeerChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

inputPeerUser::inputPeerUser(int64 user_id_, int64 access_hash_)
  : user_id_(user_id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputPeerUser::ID;

object_ptr<InputPeer> inputPeerUser::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerUser>(p);
}

inputPeerUser::inputPeerUser(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputPeerUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputPeerUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputPeerUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerUser");
    s.store_field("user_id", user_id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputPeerChannel::inputPeerChannel(int64 channel_id_, int64 access_hash_)
  : channel_id_(channel_id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputPeerChannel::ID;

object_ptr<InputPeer> inputPeerChannel::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerChannel>(p);
}

inputPeerChannel::inputPeerChannel(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputPeerChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(channel_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputPeerChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(channel_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputPeerChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerChannel");
    s.store_field("channel_id", channel_id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputPeerUserFromMessage::inputPeerUserFromMessage(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 user_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , user_id_(user_id_)
{}

const std::int32_t inputPeerUserFromMessage::ID;

object_ptr<InputPeer> inputPeerUserFromMessage::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerUserFromMessage>(p);
}

inputPeerUserFromMessage::inputPeerUserFromMessage(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , user_id_(TlFetchLong::parse(p))
{}

void inputPeerUserFromMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(user_id_, s);
}

void inputPeerUserFromMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(user_id_, s);
}

void inputPeerUserFromMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerUserFromMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

inputPeerChannelFromMessage::inputPeerChannelFromMessage(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 channel_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , channel_id_(channel_id_)
{}

const std::int32_t inputPeerChannelFromMessage::ID;

object_ptr<InputPeer> inputPeerChannelFromMessage::fetch(TlBufferParser &p) {
  return make_tl_object<inputPeerChannelFromMessage>(p);
}

inputPeerChannelFromMessage::inputPeerChannelFromMessage(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , channel_id_(TlFetchLong::parse(p))
{}

void inputPeerChannelFromMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(channel_id_, s);
}

void inputPeerChannelFromMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(channel_id_, s);
}

void inputPeerChannelFromMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerChannelFromMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("channel_id", channel_id_);
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyStatusTimestamp::ID;

void inputPrivacyKeyStatusTimestamp::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyStatusTimestamp::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyStatusTimestamp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyStatusTimestamp");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyChatInvite::ID;

void inputPrivacyKeyChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyChatInvite");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyPhoneCall::ID;

void inputPrivacyKeyPhoneCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyPhoneCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyPhoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyPhoneCall");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyPhoneP2P::ID;

void inputPrivacyKeyPhoneP2P::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyPhoneP2P::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyPhoneP2P::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyPhoneP2P");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyForwards::ID;

void inputPrivacyKeyForwards::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyForwards::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyForwards");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyProfilePhoto::ID;

void inputPrivacyKeyProfilePhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyProfilePhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyProfilePhoto");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyPhoneNumber::ID;

void inputPrivacyKeyPhoneNumber::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyPhoneNumber::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyPhoneNumber::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyPhoneNumber");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyAddedByPhone::ID;

void inputPrivacyKeyAddedByPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyAddedByPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyAddedByPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyAddedByPhone");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyVoiceMessages::ID;

void inputPrivacyKeyVoiceMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyVoiceMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyVoiceMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyVoiceMessages");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyAbout::ID;

void inputPrivacyKeyAbout::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyAbout::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyAbout::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyAbout");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyBirthday::ID;

void inputPrivacyKeyBirthday::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyBirthday::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyBirthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyBirthday");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyStarGiftsAutoSave::ID;

void inputPrivacyKeyStarGiftsAutoSave::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyStarGiftsAutoSave::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyStarGiftsAutoSave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyStarGiftsAutoSave");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeyNoPaidMessages::ID;

void inputPrivacyKeyNoPaidMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyNoPaidMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeyNoPaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeyNoPaidMessages");
    s.store_class_end();
  }
}

const std::int32_t inputPrivacyKeySavedMusic::ID;

void inputPrivacyKeySavedMusic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeySavedMusic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPrivacyKeySavedMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPrivacyKeySavedMusic");
    s.store_class_end();
  }
}

keyboardButtonRow::keyboardButtonRow(array<object_ptr<KeyboardButton>> &&buttons_)
  : buttons_(std::move(buttons_))
{}

const std::int32_t keyboardButtonRow::ID;

object_ptr<keyboardButtonRow> keyboardButtonRow::fetch(TlBufferParser &p) {
  return make_tl_object<keyboardButtonRow>(p);
}

keyboardButtonRow::keyboardButtonRow(TlBufferParser &p)
  : buttons_(TlFetchBoxed<TlFetchVector<TlFetchObject<KeyboardButton>>, 481674261>::parse(p))
{}

void keyboardButtonRow::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(buttons_, s);
}

void keyboardButtonRow::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(buttons_, s);
}

void keyboardButtonRow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonRow");
    { s.store_vector_begin("buttons", buttons_.size()); for (const auto &_value : buttons_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<Message> Message::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messageEmpty::ID:
      return messageEmpty::fetch(p);
    case message::ID:
      return message::fetch(p);
    case messageService::ID:
      return messageService::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messageEmpty::messageEmpty()
  : flags_()
  , id_()
  , peer_id_()
{}

const std::int32_t messageEmpty::ID;

object_ptr<Message> messageEmpty::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageEmpty> res = make_tl_object<messageEmpty>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->peer_id_ = TlFetchObject<Peer>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEmpty");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get())); }
    s.store_class_end();
  }
}

message::message()
  : flags_()
  , out_()
  , mentioned_()
  , media_unread_()
  , silent_()
  , post_()
  , from_scheduled_()
  , legacy_()
  , edit_hide_()
  , pinned_()
  , noforwards_()
  , invert_media_()
  , flags2_()
  , offline_()
  , video_processing_pending_()
  , paid_suggested_post_stars_()
  , paid_suggested_post_ton_()
  , id_()
  , from_id_()
  , from_boosts_applied_()
  , from_rank_()
  , peer_id_()
  , saved_peer_id_()
  , fwd_from_()
  , via_bot_id_()
  , via_business_bot_id_()
  , reply_to_()
  , date_()
  , message_()
  , media_()
  , reply_markup_()
  , entities_()
  , views_()
  , forwards_()
  , replies_()
  , edit_date_()
  , post_author_()
  , grouped_id_()
  , reactions_()
  , restriction_reason_()
  , ttl_period_()
  , quick_reply_shortcut_id_()
  , effect_()
  , factcheck_()
  , report_delivery_until_date_()
  , paid_message_stars_()
  , suggested_post_()
  , schedule_repeat_period_()
  , summary_from_language_()
{}

message::message(int32 flags_, bool out_, bool mentioned_, bool media_unread_, bool silent_, bool post_, bool from_scheduled_, bool legacy_, bool edit_hide_, bool pinned_, bool noforwards_, bool invert_media_, int32 flags2_, bool offline_, bool video_processing_pending_, bool paid_suggested_post_stars_, bool paid_suggested_post_ton_, int32 id_, object_ptr<Peer> &&from_id_, int32 from_boosts_applied_, string const &from_rank_, object_ptr<Peer> &&peer_id_, object_ptr<Peer> &&saved_peer_id_, object_ptr<messageFwdHeader> &&fwd_from_, int64 via_bot_id_, int64 via_business_bot_id_, object_ptr<MessageReplyHeader> &&reply_to_, int32 date_, string const &message_, object_ptr<MessageMedia> &&media_, object_ptr<ReplyMarkup> &&reply_markup_, array<object_ptr<MessageEntity>> &&entities_, int32 views_, int32 forwards_, object_ptr<messageReplies> &&replies_, int32 edit_date_, string const &post_author_, int64 grouped_id_, object_ptr<messageReactions> &&reactions_, array<object_ptr<restrictionReason>> &&restriction_reason_, int32 ttl_period_, int32 quick_reply_shortcut_id_, int64 effect_, object_ptr<factCheck> &&factcheck_, int32 report_delivery_until_date_, int64 paid_message_stars_, object_ptr<suggestedPost> &&suggested_post_, int32 schedule_repeat_period_, string const &summary_from_language_)
  : flags_(flags_)
  , out_(out_)
  , mentioned_(mentioned_)
  , media_unread_(media_unread_)
  , silent_(silent_)
  , post_(post_)
  , from_scheduled_(from_scheduled_)
  , legacy_(legacy_)
  , edit_hide_(edit_hide_)
  , pinned_(pinned_)
  , noforwards_(noforwards_)
  , invert_media_(invert_media_)
  , flags2_(flags2_)
  , offline_(offline_)
  , video_processing_pending_(video_processing_pending_)
  , paid_suggested_post_stars_(paid_suggested_post_stars_)
  , paid_suggested_post_ton_(paid_suggested_post_ton_)
  , id_(id_)
  , from_id_(std::move(from_id_))
  , from_boosts_applied_(from_boosts_applied_)
  , from_rank_(from_rank_)
  , peer_id_(std::move(peer_id_))
  , saved_peer_id_(std::move(saved_peer_id_))
  , fwd_from_(std::move(fwd_from_))
  , via_bot_id_(via_bot_id_)
  , via_business_bot_id_(via_business_bot_id_)
  , reply_to_(std::move(reply_to_))
  , date_(date_)
  , message_(message_)
  , media_(std::move(media_))
  , reply_markup_(std::move(reply_markup_))
  , entities_(std::move(entities_))
  , views_(views_)
  , forwards_(forwards_)
  , replies_(std::move(replies_))
  , edit_date_(edit_date_)
  , post_author_(post_author_)
  , grouped_id_(grouped_id_)
  , reactions_(std::move(reactions_))
  , restriction_reason_(std::move(restriction_reason_))
  , ttl_period_(ttl_period_)
  , quick_reply_shortcut_id_(quick_reply_shortcut_id_)
  , effect_(effect_)
  , factcheck_(std::move(factcheck_))
  , report_delivery_until_date_(report_delivery_until_date_)
  , paid_message_stars_(paid_message_stars_)
  , suggested_post_(std::move(suggested_post_))
  , schedule_repeat_period_(schedule_repeat_period_)
  , summary_from_language_(summary_from_language_)
{}

const std::int32_t message::ID;

object_ptr<Message> message::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<message> res = make_tl_object<message>();
  int32 var0;
  int32 var1;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->out_ = (var0 & 2) != 0;
  res->mentioned_ = (var0 & 16) != 0;
  res->media_unread_ = (var0 & 32) != 0;
  res->silent_ = (var0 & 8192) != 0;
  res->post_ = (var0 & 16384) != 0;
  res->from_scheduled_ = (var0 & 262144) != 0;
  res->legacy_ = (var0 & 524288) != 0;
  res->edit_hide_ = (var0 & 2097152) != 0;
  res->pinned_ = (var0 & 16777216) != 0;
  res->noforwards_ = (var0 & 67108864) != 0;
  res->invert_media_ = (var0 & 134217728) != 0;
  if ((var1 = res->flags2_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->offline_ = (var1 & 2) != 0;
  res->video_processing_pending_ = (var1 & 16) != 0;
  res->paid_suggested_post_stars_ = (var1 & 256) != 0;
  res->paid_suggested_post_ton_ = (var1 & 512) != 0;
  res->id_ = TlFetchInt::parse(p);
  if (var0 & 256) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 536870912) { res->from_boosts_applied_ = TlFetchInt::parse(p); }
  if (var1 & 4096) { res->from_rank_ = TlFetchString<string>::parse(p); }
  res->peer_id_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 268435456) { res->saved_peer_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 4) { res->fwd_from_ = TlFetchBoxed<TlFetchObject<messageFwdHeader>, 1313731771>::parse(p); }
  if (var0 & 2048) { res->via_bot_id_ = TlFetchLong::parse(p); }
  if (var1 & 1) { res->via_business_bot_id_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->reply_to_ = TlFetchObject<MessageReplyHeader>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 512) { res->media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (var0 & 64) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (var0 & 128) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 1024) { res->views_ = TlFetchInt::parse(p); }
  if (var0 & 1024) { res->forwards_ = TlFetchInt::parse(p); }
  if (var0 & 8388608) { res->replies_ = TlFetchBoxed<TlFetchObject<messageReplies>, -2083123262>::parse(p); }
  if (var0 & 32768) { res->edit_date_ = TlFetchInt::parse(p); }
  if (var0 & 65536) { res->post_author_ = TlFetchString<string>::parse(p); }
  if (var0 & 131072) { res->grouped_id_ = TlFetchLong::parse(p); }
  if (var0 & 1048576) { res->reactions_ = TlFetchBoxed<TlFetchObject<messageReactions>, 171155211>::parse(p); }
  if (var0 & 4194304) { res->restriction_reason_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<restrictionReason>, -797791052>>, 481674261>::parse(p); }
  if (var0 & 33554432) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (var0 & 1073741824) { res->quick_reply_shortcut_id_ = TlFetchInt::parse(p); }
  if (var1 & 4) { res->effect_ = TlFetchLong::parse(p); }
  if (var1 & 8) { res->factcheck_ = TlFetchBoxed<TlFetchObject<factCheck>, -1197736753>::parse(p); }
  if (var1 & 32) { res->report_delivery_until_date_ = TlFetchInt::parse(p); }
  if (var1 & 64) { res->paid_message_stars_ = TlFetchLong::parse(p); }
  if (var1 & 128) { res->suggested_post_ = TlFetchBoxed<TlFetchObject<suggestedPost>, 244201445>::parse(p); }
  if (var1 & 1024) { res->schedule_repeat_period_ = TlFetchInt::parse(p); }
  if (var1 & 2048) { res->summary_from_language_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void message::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "message");
  int32 var0;
  int32 var1;
    s.store_field("flags", (var0 = flags_ | (out_ << 1) | (mentioned_ << 4) | (media_unread_ << 5) | (silent_ << 13) | (post_ << 14) | (from_scheduled_ << 18) | (legacy_ << 19) | (edit_hide_ << 21) | (pinned_ << 24) | (noforwards_ << 26) | (invert_media_ << 27)));
    if (var0 & 2) { s.store_field("out", true); }
    if (var0 & 16) { s.store_field("mentioned", true); }
    if (var0 & 32) { s.store_field("media_unread", true); }
    if (var0 & 8192) { s.store_field("silent", true); }
    if (var0 & 16384) { s.store_field("post", true); }
    if (var0 & 262144) { s.store_field("from_scheduled", true); }
    if (var0 & 524288) { s.store_field("legacy", true); }
    if (var0 & 2097152) { s.store_field("edit_hide", true); }
    if (var0 & 16777216) { s.store_field("pinned", true); }
    if (var0 & 67108864) { s.store_field("noforwards", true); }
    if (var0 & 134217728) { s.store_field("invert_media", true); }
    s.store_field("flags2", (var1 = flags2_ | (offline_ << 1) | (video_processing_pending_ << 4) | (paid_suggested_post_stars_ << 8) | (paid_suggested_post_ton_ << 9)));
    if (var1 & 2) { s.store_field("offline", true); }
    if (var1 & 16) { s.store_field("video_processing_pending", true); }
    if (var1 & 256) { s.store_field("paid_suggested_post_stars", true); }
    if (var1 & 512) { s.store_field("paid_suggested_post_ton", true); }
    s.store_field("id", id_);
    if (var0 & 256) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 536870912) { s.store_field("from_boosts_applied", from_boosts_applied_); }
    if (var1 & 4096) { s.store_field("from_rank", from_rank_); }
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    if (var0 & 268435456) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    if (var0 & 4) { s.store_object_field("fwd_from", static_cast<const BaseObject *>(fwd_from_.get())); }
    if (var0 & 2048) { s.store_field("via_bot_id", via_bot_id_); }
    if (var1 & 1) { s.store_field("via_business_bot_id", via_business_bot_id_); }
    if (var0 & 8) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_field("date", date_);
    s.store_field("message", message_);
    if (var0 & 512) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 64) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 128) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1024) { s.store_field("views", views_); }
    if (var0 & 1024) { s.store_field("forwards", forwards_); }
    if (var0 & 8388608) { s.store_object_field("replies", static_cast<const BaseObject *>(replies_.get())); }
    if (var0 & 32768) { s.store_field("edit_date", edit_date_); }
    if (var0 & 65536) { s.store_field("post_author", post_author_); }
    if (var0 & 131072) { s.store_field("grouped_id", grouped_id_); }
    if (var0 & 1048576) { s.store_object_field("reactions", static_cast<const BaseObject *>(reactions_.get())); }
    if (var0 & 4194304) { { s.store_vector_begin("restriction_reason", restriction_reason_.size()); for (const auto &_value : restriction_reason_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 33554432) { s.store_field("ttl_period", ttl_period_); }
    if (var0 & 1073741824) { s.store_field("quick_reply_shortcut_id", quick_reply_shortcut_id_); }
    if (var1 & 4) { s.store_field("effect", effect_); }
    if (var1 & 8) { s.store_object_field("factcheck", static_cast<const BaseObject *>(factcheck_.get())); }
    if (var1 & 32) { s.store_field("report_delivery_until_date", report_delivery_until_date_); }
    if (var1 & 64) { s.store_field("paid_message_stars", paid_message_stars_); }
    if (var1 & 128) { s.store_object_field("suggested_post", static_cast<const BaseObject *>(suggested_post_.get())); }
    if (var1 & 1024) { s.store_field("schedule_repeat_period", schedule_repeat_period_); }
    if (var1 & 2048) { s.store_field("summary_from_language", summary_from_language_); }
    s.store_class_end();
  }
}

messageService::messageService()
  : flags_()
  , out_()
  , mentioned_()
  , media_unread_()
  , reactions_are_possible_()
  , silent_()
  , post_()
  , legacy_()
  , id_()
  , from_id_()
  , peer_id_()
  , saved_peer_id_()
  , reply_to_()
  , date_()
  , action_()
  , reactions_()
  , ttl_period_()
{}

const std::int32_t messageService::ID;

object_ptr<Message> messageService::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageService> res = make_tl_object<messageService>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->out_ = (var0 & 2) != 0;
  res->mentioned_ = (var0 & 16) != 0;
  res->media_unread_ = (var0 & 32) != 0;
  res->reactions_are_possible_ = (var0 & 512) != 0;
  res->silent_ = (var0 & 8192) != 0;
  res->post_ = (var0 & 16384) != 0;
  res->legacy_ = (var0 & 524288) != 0;
  res->id_ = TlFetchInt::parse(p);
  if (var0 & 256) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  res->peer_id_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 268435456) { res->saved_peer_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 8) { res->reply_to_ = TlFetchObject<MessageReplyHeader>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->action_ = TlFetchObject<MessageAction>::parse(p);
  if (var0 & 1048576) { res->reactions_ = TlFetchBoxed<TlFetchObject<messageReactions>, 171155211>::parse(p); }
  if (var0 & 33554432) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageService");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (out_ << 1) | (mentioned_ << 4) | (media_unread_ << 5) | (reactions_are_possible_ << 9) | (silent_ << 13) | (post_ << 14) | (legacy_ << 19)));
    if (var0 & 2) { s.store_field("out", true); }
    if (var0 & 16) { s.store_field("mentioned", true); }
    if (var0 & 32) { s.store_field("media_unread", true); }
    if (var0 & 512) { s.store_field("reactions_are_possible", true); }
    if (var0 & 8192) { s.store_field("silent", true); }
    if (var0 & 16384) { s.store_field("post", true); }
    if (var0 & 524288) { s.store_field("legacy", true); }
    s.store_field("id", id_);
    if (var0 & 256) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    if (var0 & 268435456) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    if (var0 & 8) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_field("date", date_);
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    if (var0 & 1048576) { s.store_object_field("reactions", static_cast<const BaseObject *>(reactions_.get())); }
    if (var0 & 33554432) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

messageReactor::messageReactor()
  : flags_()
  , top_()
  , my_()
  , anonymous_()
  , peer_id_()
  , count_()
{}

const std::int32_t messageReactor::ID;

object_ptr<messageReactor> messageReactor::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageReactor> res = make_tl_object<messageReactor>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->top_ = (var0 & 1) != 0;
  res->my_ = (var0 & 2) != 0;
  res->anonymous_ = (var0 & 4) != 0;
  if (var0 & 8) { res->peer_id_ = TlFetchObject<Peer>::parse(p); }
  res->count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messageReactor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReactor");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (top_ << 0) | (my_ << 1) | (anonymous_ << 2)));
    if (var0 & 1) { s.store_field("top", true); }
    if (var0 & 2) { s.store_field("my", true); }
    if (var0 & 4) { s.store_field("anonymous", true); }
    if (var0 & 8) { s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get())); }
    s.store_field("count", count_);
    s.store_class_end();
  }
}

object_ptr<PageBlock> PageBlock::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case pageBlockUnsupported::ID:
      return pageBlockUnsupported::fetch(p);
    case pageBlockTitle::ID:
      return pageBlockTitle::fetch(p);
    case pageBlockSubtitle::ID:
      return pageBlockSubtitle::fetch(p);
    case pageBlockAuthorDate::ID:
      return pageBlockAuthorDate::fetch(p);
    case pageBlockHeader::ID:
      return pageBlockHeader::fetch(p);
    case pageBlockSubheader::ID:
      return pageBlockSubheader::fetch(p);
    case pageBlockParagraph::ID:
      return pageBlockParagraph::fetch(p);
    case pageBlockPreformatted::ID:
      return pageBlockPreformatted::fetch(p);
    case pageBlockFooter::ID:
      return pageBlockFooter::fetch(p);
    case pageBlockDivider::ID:
      return pageBlockDivider::fetch(p);
    case pageBlockAnchor::ID:
      return pageBlockAnchor::fetch(p);
    case pageBlockList::ID:
      return pageBlockList::fetch(p);
    case pageBlockBlockquote::ID:
      return pageBlockBlockquote::fetch(p);
    case pageBlockPullquote::ID:
      return pageBlockPullquote::fetch(p);
    case pageBlockPhoto::ID:
      return pageBlockPhoto::fetch(p);
    case pageBlockVideo::ID:
      return pageBlockVideo::fetch(p);
    case pageBlockCover::ID:
      return pageBlockCover::fetch(p);
    case pageBlockEmbed::ID:
      return pageBlockEmbed::fetch(p);
    case pageBlockEmbedPost::ID:
      return pageBlockEmbedPost::fetch(p);
    case pageBlockCollage::ID:
      return pageBlockCollage::fetch(p);
    case pageBlockSlideshow::ID:
      return pageBlockSlideshow::fetch(p);
    case pageBlockChannel::ID:
      return pageBlockChannel::fetch(p);
    case pageBlockAudio::ID:
      return pageBlockAudio::fetch(p);
    case pageBlockKicker::ID:
      return pageBlockKicker::fetch(p);
    case pageBlockTable::ID:
      return pageBlockTable::fetch(p);
    case pageBlockOrderedList::ID:
      return pageBlockOrderedList::fetch(p);
    case pageBlockDetails::ID:
      return pageBlockDetails::fetch(p);
    case pageBlockRelatedArticles::ID:
      return pageBlockRelatedArticles::fetch(p);
    case pageBlockMap::ID:
      return pageBlockMap::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t pageBlockUnsupported::ID;

object_ptr<PageBlock> pageBlockUnsupported::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockUnsupported>();
}

void pageBlockUnsupported::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void pageBlockUnsupported::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void pageBlockUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockUnsupported");
    s.store_class_end();
  }
}

pageBlockTitle::pageBlockTitle(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockTitle::ID;

object_ptr<PageBlock> pageBlockTitle::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockTitle>(p);
}

pageBlockTitle::pageBlockTitle(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockTitle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockTitle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTitle");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockSubtitle::pageBlockSubtitle(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockSubtitle::ID;

object_ptr<PageBlock> pageBlockSubtitle::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockSubtitle>(p);
}

pageBlockSubtitle::pageBlockSubtitle(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockSubtitle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockSubtitle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockSubtitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSubtitle");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockAuthorDate::pageBlockAuthorDate(object_ptr<RichText> &&author_, int32 published_date_)
  : author_(std::move(author_))
  , published_date_(published_date_)
{}

const std::int32_t pageBlockAuthorDate::ID;

object_ptr<PageBlock> pageBlockAuthorDate::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockAuthorDate>(p);
}

pageBlockAuthorDate::pageBlockAuthorDate(TlBufferParser &p)
  : author_(TlFetchObject<RichText>::parse(p))
  , published_date_(TlFetchInt::parse(p))
{}

void pageBlockAuthorDate::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(author_, s);
  TlStoreBinary::store(published_date_, s);
}

void pageBlockAuthorDate::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(author_, s);
  TlStoreBinary::store(published_date_, s);
}

void pageBlockAuthorDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAuthorDate");
    s.store_object_field("author", static_cast<const BaseObject *>(author_.get()));
    s.store_field("published_date", published_date_);
    s.store_class_end();
  }
}

pageBlockHeader::pageBlockHeader(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockHeader::ID;

object_ptr<PageBlock> pageBlockHeader::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockHeader>(p);
}

pageBlockHeader::pageBlockHeader(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockHeader::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeader::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockHeader");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockSubheader::pageBlockSubheader(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockSubheader::ID;

object_ptr<PageBlock> pageBlockSubheader::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockSubheader>(p);
}

pageBlockSubheader::pageBlockSubheader(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockSubheader::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockSubheader::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockSubheader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSubheader");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockParagraph::pageBlockParagraph(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockParagraph::ID;

object_ptr<PageBlock> pageBlockParagraph::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockParagraph>(p);
}

pageBlockParagraph::pageBlockParagraph(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockParagraph::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockParagraph::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockParagraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockParagraph");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockPreformatted::pageBlockPreformatted(object_ptr<RichText> &&text_, string const &language_)
  : text_(std::move(text_))
  , language_(language_)
{}

const std::int32_t pageBlockPreformatted::ID;

object_ptr<PageBlock> pageBlockPreformatted::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockPreformatted>(p);
}

pageBlockPreformatted::pageBlockPreformatted(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , language_(TlFetchString<string>::parse(p))
{}

void pageBlockPreformatted::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(language_, s);
}

void pageBlockPreformatted::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(language_, s);
}

void pageBlockPreformatted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPreformatted");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("language", language_);
    s.store_class_end();
  }
}

pageBlockFooter::pageBlockFooter(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockFooter::ID;

object_ptr<PageBlock> pageBlockFooter::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockFooter>(p);
}

pageBlockFooter::pageBlockFooter(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockFooter::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockFooter::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockFooter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockFooter");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

const std::int32_t pageBlockDivider::ID;

object_ptr<PageBlock> pageBlockDivider::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockDivider>();
}

void pageBlockDivider::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void pageBlockDivider::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void pageBlockDivider::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockDivider");
    s.store_class_end();
  }
}

pageBlockAnchor::pageBlockAnchor(string const &name_)
  : name_(name_)
{}

const std::int32_t pageBlockAnchor::ID;

object_ptr<PageBlock> pageBlockAnchor::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockAnchor>(p);
}

pageBlockAnchor::pageBlockAnchor(TlBufferParser &p)
  : name_(TlFetchString<string>::parse(p))
{}

void pageBlockAnchor::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(name_, s);
}

void pageBlockAnchor::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(name_, s);
}

void pageBlockAnchor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAnchor");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

pageBlockList::pageBlockList(array<object_ptr<PageListItem>> &&items_)
  : items_(std::move(items_))
{}

const std::int32_t pageBlockList::ID;

object_ptr<PageBlock> pageBlockList::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockList>(p);
}

pageBlockList::pageBlockList(TlBufferParser &p)
  : items_(TlFetchBoxed<TlFetchVector<TlFetchObject<PageListItem>>, 481674261>::parse(p))
{}

void pageBlockList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
}

void pageBlockList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
}

void pageBlockList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockList");
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockBlockquote::pageBlockBlockquote(object_ptr<RichText> &&text_, object_ptr<RichText> &&caption_)
  : text_(std::move(text_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockBlockquote::ID;

object_ptr<PageBlock> pageBlockBlockquote::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockBlockquote>(p);
}

pageBlockBlockquote::pageBlockBlockquote(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , caption_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockBlockquote::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(caption_, s);
}

void pageBlockBlockquote::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(caption_, s);
}

void pageBlockBlockquote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockBlockquote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockPullquote::pageBlockPullquote(object_ptr<RichText> &&text_, object_ptr<RichText> &&caption_)
  : text_(std::move(text_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockPullquote::ID;

object_ptr<PageBlock> pageBlockPullquote::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockPullquote>(p);
}

pageBlockPullquote::pageBlockPullquote(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , caption_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockPullquote::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(caption_, s);
}

void pageBlockPullquote::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(caption_, s);
}

void pageBlockPullquote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPullquote");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockPhoto::pageBlockPhoto()
  : flags_()
  , photo_id_()
  , caption_()
  , url_()
  , webpage_id_()
{}

pageBlockPhoto::pageBlockPhoto(int32 flags_, int64 photo_id_, object_ptr<pageCaption> &&caption_, string const &url_, int64 webpage_id_)
  : flags_(flags_)
  , photo_id_(photo_id_)
  , caption_(std::move(caption_))
  , url_(url_)
  , webpage_id_(webpage_id_)
{}

const std::int32_t pageBlockPhoto::ID;

object_ptr<PageBlock> pageBlockPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockPhoto> res = make_tl_object<pageBlockPhoto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->photo_id_ = TlFetchLong::parse(p);
  res->caption_ = TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p);
  if (var0 & 1) { res->url_ = TlFetchString<string>::parse(p); }
  if (var0 & 1) { res->webpage_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(photo_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
  if (var0 & 1) { TlStoreString::store(url_, s); }
  if (var0 & 1) { TlStoreBinary::store(webpage_id_, s); }
}

void pageBlockPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(photo_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
  if (var0 & 1) { TlStoreString::store(url_, s); }
  if (var0 & 1) { TlStoreBinary::store(webpage_id_, s); }
}

void pageBlockPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockPhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("photo_id", photo_id_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    if (var0 & 1) { s.store_field("url", url_); }
    if (var0 & 1) { s.store_field("webpage_id", webpage_id_); }
    s.store_class_end();
  }
}

pageBlockVideo::pageBlockVideo()
  : flags_()
  , autoplay_()
  , loop_()
  , video_id_()
  , caption_()
{}

pageBlockVideo::pageBlockVideo(int32 flags_, bool autoplay_, bool loop_, int64 video_id_, object_ptr<pageCaption> &&caption_)
  : flags_(flags_)
  , autoplay_(autoplay_)
  , loop_(loop_)
  , video_id_(video_id_)
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockVideo::ID;

object_ptr<PageBlock> pageBlockVideo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockVideo> res = make_tl_object<pageBlockVideo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->autoplay_ = (var0 & 1) != 0;
  res->loop_ = (var0 & 2) != 0;
  res->video_id_ = TlFetchLong::parse(p);
  res->caption_ = TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockVideo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (autoplay_ << 0) | (loop_ << 1)), s);
  TlStoreBinary::store(video_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockVideo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (autoplay_ << 0) | (loop_ << 1)), s);
  TlStoreBinary::store(video_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockVideo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (autoplay_ << 0) | (loop_ << 1)));
    if (var0 & 1) { s.store_field("autoplay", true); }
    if (var0 & 2) { s.store_field("loop", true); }
    s.store_field("video_id", video_id_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockCover::pageBlockCover(object_ptr<PageBlock> &&cover_)
  : cover_(std::move(cover_))
{}

const std::int32_t pageBlockCover::ID;

object_ptr<PageBlock> pageBlockCover::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockCover>(p);
}

pageBlockCover::pageBlockCover(TlBufferParser &p)
  : cover_(TlFetchObject<PageBlock>::parse(p))
{}

void pageBlockCover::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(cover_, s);
}

void pageBlockCover::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(cover_, s);
}

void pageBlockCover::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCover");
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_class_end();
  }
}

pageBlockEmbed::pageBlockEmbed()
  : flags_()
  , full_width_()
  , allow_scrolling_()
  , url_()
  , html_()
  , poster_photo_id_()
  , w_()
  , h_()
  , caption_()
{}

pageBlockEmbed::pageBlockEmbed(int32 flags_, bool full_width_, bool allow_scrolling_, string const &url_, string const &html_, int64 poster_photo_id_, int32 w_, int32 h_, object_ptr<pageCaption> &&caption_)
  : flags_(flags_)
  , full_width_(full_width_)
  , allow_scrolling_(allow_scrolling_)
  , url_(url_)
  , html_(html_)
  , poster_photo_id_(poster_photo_id_)
  , w_(w_)
  , h_(h_)
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockEmbed::ID;

object_ptr<PageBlock> pageBlockEmbed::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockEmbed> res = make_tl_object<pageBlockEmbed>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->full_width_ = (var0 & 1) != 0;
  res->allow_scrolling_ = (var0 & 8) != 0;
  if (var0 & 2) { res->url_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->html_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->poster_photo_id_ = TlFetchLong::parse(p); }
  if (var0 & 32) { res->w_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->h_ = TlFetchInt::parse(p); }
  res->caption_ = TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockEmbed::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (full_width_ << 0) | (allow_scrolling_ << 3)), s);
  if (var0 & 2) { TlStoreString::store(url_, s); }
  if (var0 & 4) { TlStoreString::store(html_, s); }
  if (var0 & 16) { TlStoreBinary::store(poster_photo_id_, s); }
  if (var0 & 32) { TlStoreBinary::store(w_, s); }
  if (var0 & 32) { TlStoreBinary::store(h_, s); }
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockEmbed::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (full_width_ << 0) | (allow_scrolling_ << 3)), s);
  if (var0 & 2) { TlStoreString::store(url_, s); }
  if (var0 & 4) { TlStoreString::store(html_, s); }
  if (var0 & 16) { TlStoreBinary::store(poster_photo_id_, s); }
  if (var0 & 32) { TlStoreBinary::store(w_, s); }
  if (var0 & 32) { TlStoreBinary::store(h_, s); }
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockEmbed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockEmbed");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (full_width_ << 0) | (allow_scrolling_ << 3)));
    if (var0 & 1) { s.store_field("full_width", true); }
    if (var0 & 8) { s.store_field("allow_scrolling", true); }
    if (var0 & 2) { s.store_field("url", url_); }
    if (var0 & 4) { s.store_field("html", html_); }
    if (var0 & 16) { s.store_field("poster_photo_id", poster_photo_id_); }
    if (var0 & 32) { s.store_field("w", w_); }
    if (var0 & 32) { s.store_field("h", h_); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockEmbedPost::pageBlockEmbedPost(string const &url_, int64 webpage_id_, int64 author_photo_id_, string const &author_, int32 date_, array<object_ptr<PageBlock>> &&blocks_, object_ptr<pageCaption> &&caption_)
  : url_(url_)
  , webpage_id_(webpage_id_)
  , author_photo_id_(author_photo_id_)
  , author_(author_)
  , date_(date_)
  , blocks_(std::move(blocks_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockEmbedPost::ID;

object_ptr<PageBlock> pageBlockEmbedPost::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockEmbedPost>(p);
}

pageBlockEmbedPost::pageBlockEmbedPost(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , webpage_id_(TlFetchLong::parse(p))
  , author_photo_id_(TlFetchLong::parse(p))
  , author_(TlFetchString<string>::parse(p))
  , date_(TlFetchInt::parse(p))
  , blocks_(TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p))
  , caption_(TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p))
{}

void pageBlockEmbedPost::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(webpage_id_, s);
  TlStoreBinary::store(author_photo_id_, s);
  TlStoreString::store(author_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockEmbedPost::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(webpage_id_, s);
  TlStoreBinary::store(author_photo_id_, s);
  TlStoreString::store(author_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockEmbedPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockEmbedPost");
    s.store_field("url", url_);
    s.store_field("webpage_id", webpage_id_);
    s.store_field("author_photo_id", author_photo_id_);
    s.store_field("author", author_);
    s.store_field("date", date_);
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockCollage::pageBlockCollage(array<object_ptr<PageBlock>> &&items_, object_ptr<pageCaption> &&caption_)
  : items_(std::move(items_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockCollage::ID;

object_ptr<PageBlock> pageBlockCollage::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockCollage>(p);
}

pageBlockCollage::pageBlockCollage(TlBufferParser &p)
  : items_(TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p))
  , caption_(TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p))
{}

void pageBlockCollage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockCollage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockCollage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockCollage");
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockSlideshow::pageBlockSlideshow(array<object_ptr<PageBlock>> &&items_, object_ptr<pageCaption> &&caption_)
  : items_(std::move(items_))
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockSlideshow::ID;

object_ptr<PageBlock> pageBlockSlideshow::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockSlideshow>(p);
}

pageBlockSlideshow::pageBlockSlideshow(TlBufferParser &p)
  : items_(TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p))
  , caption_(TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p))
{}

void pageBlockSlideshow::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockSlideshow::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockSlideshow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockSlideshow");
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockChannel::pageBlockChannel(object_ptr<Chat> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t pageBlockChannel::ID;

object_ptr<PageBlock> pageBlockChannel::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockChannel>(p);
}

pageBlockChannel::pageBlockChannel(TlBufferParser &p)
  : channel_(TlFetchObject<Chat>::parse(p))
{}

void pageBlockChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void pageBlockChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void pageBlockChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

pageBlockAudio::pageBlockAudio(int64 audio_id_, object_ptr<pageCaption> &&caption_)
  : audio_id_(audio_id_)
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockAudio::ID;

object_ptr<PageBlock> pageBlockAudio::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockAudio>(p);
}

pageBlockAudio::pageBlockAudio(TlBufferParser &p)
  : audio_id_(TlFetchLong::parse(p))
  , caption_(TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p))
{}

void pageBlockAudio::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(audio_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockAudio::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(audio_id_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockAudio");
    s.store_field("audio_id", audio_id_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

pageBlockKicker::pageBlockKicker(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageBlockKicker::ID;

object_ptr<PageBlock> pageBlockKicker::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockKicker>(p);
}

pageBlockKicker::pageBlockKicker(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageBlockKicker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockKicker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageBlockKicker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockKicker");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageBlockTable::pageBlockTable()
  : flags_()
  , bordered_()
  , striped_()
  , title_()
  , rows_()
{}

pageBlockTable::pageBlockTable(int32 flags_, bool bordered_, bool striped_, object_ptr<RichText> &&title_, array<object_ptr<pageTableRow>> &&rows_)
  : flags_(flags_)
  , bordered_(bordered_)
  , striped_(striped_)
  , title_(std::move(title_))
  , rows_(std::move(rows_))
{}

const std::int32_t pageBlockTable::ID;

object_ptr<PageBlock> pageBlockTable::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockTable> res = make_tl_object<pageBlockTable>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bordered_ = (var0 & 1) != 0;
  res->striped_ = (var0 & 2) != 0;
  res->title_ = TlFetchObject<RichText>::parse(p);
  res->rows_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<pageTableRow>, -524237339>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockTable::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bordered_ << 0) | (striped_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -524237339>>, 481674261>::store(rows_, s);
}

void pageBlockTable::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bordered_ << 0) | (striped_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -524237339>>, 481674261>::store(rows_, s);
}

void pageBlockTable::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockTable");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (bordered_ << 0) | (striped_ << 1)));
    if (var0 & 1) { s.store_field("bordered", true); }
    if (var0 & 2) { s.store_field("striped", true); }
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    { s.store_vector_begin("rows", rows_.size()); for (const auto &_value : rows_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockOrderedList::pageBlockOrderedList(array<object_ptr<PageListOrderedItem>> &&items_)
  : items_(std::move(items_))
{}

const std::int32_t pageBlockOrderedList::ID;

object_ptr<PageBlock> pageBlockOrderedList::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockOrderedList>(p);
}

pageBlockOrderedList::pageBlockOrderedList(TlBufferParser &p)
  : items_(TlFetchBoxed<TlFetchVector<TlFetchObject<PageListOrderedItem>>, 481674261>::parse(p))
{}

void pageBlockOrderedList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
}

void pageBlockOrderedList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(items_, s);
}

void pageBlockOrderedList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockOrderedList");
    { s.store_vector_begin("items", items_.size()); for (const auto &_value : items_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockDetails::pageBlockDetails()
  : flags_()
  , open_()
  , blocks_()
  , title_()
{}

pageBlockDetails::pageBlockDetails(int32 flags_, bool open_, array<object_ptr<PageBlock>> &&blocks_, object_ptr<RichText> &&title_)
  : flags_(flags_)
  , open_(open_)
  , blocks_(std::move(blocks_))
  , title_(std::move(title_))
{}

const std::int32_t pageBlockDetails::ID;

object_ptr<PageBlock> pageBlockDetails::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageBlockDetails> res = make_tl_object<pageBlockDetails>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->open_ = (var0 & 1) != 0;
  res->blocks_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p);
  res->title_ = TlFetchObject<RichText>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pageBlockDetails::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (open_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(title_, s);
}

void pageBlockDetails::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (open_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(title_, s);
}

void pageBlockDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockDetails");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (open_ << 0)));
    if (var0 & 1) { s.store_field("open", true); }
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    s.store_class_end();
  }
}

pageBlockRelatedArticles::pageBlockRelatedArticles(object_ptr<RichText> &&title_, array<object_ptr<pageRelatedArticle>> &&articles_)
  : title_(std::move(title_))
  , articles_(std::move(articles_))
{}

const std::int32_t pageBlockRelatedArticles::ID;

object_ptr<PageBlock> pageBlockRelatedArticles::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockRelatedArticles>(p);
}

pageBlockRelatedArticles::pageBlockRelatedArticles(TlBufferParser &p)
  : title_(TlFetchObject<RichText>::parse(p))
  , articles_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<pageRelatedArticle>, -1282352120>>, 481674261>::parse(p))
{}

void pageBlockRelatedArticles::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1282352120>>, 481674261>::store(articles_, s);
}

void pageBlockRelatedArticles::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1282352120>>, 481674261>::store(articles_, s);
}

void pageBlockRelatedArticles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockRelatedArticles");
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    { s.store_vector_begin("articles", articles_.size()); for (const auto &_value : articles_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

pageBlockMap::pageBlockMap(object_ptr<GeoPoint> &&geo_, int32 zoom_, int32 w_, int32 h_, object_ptr<pageCaption> &&caption_)
  : geo_(std::move(geo_))
  , zoom_(zoom_)
  , w_(w_)
  , h_(h_)
  , caption_(std::move(caption_))
{}

const std::int32_t pageBlockMap::ID;

object_ptr<PageBlock> pageBlockMap::fetch(TlBufferParser &p) {
  return make_tl_object<pageBlockMap>(p);
}

pageBlockMap::pageBlockMap(TlBufferParser &p)
  : geo_(TlFetchObject<GeoPoint>::parse(p))
  , zoom_(TlFetchInt::parse(p))
  , w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
  , caption_(TlFetchBoxed<TlFetchObject<pageCaption>, 1869903447>::parse(p))
{}

void pageBlockMap::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreBinary::store(zoom_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockMap::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreBinary::store(zoom_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBoxed<TlStoreObject, 1869903447>::store(caption_, s);
}

void pageBlockMap::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageBlockMap");
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    s.store_field("zoom", zoom_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_object_field("caption", static_cast<const BaseObject *>(caption_.get()));
    s.store_class_end();
  }
}

object_ptr<PageListOrderedItem> PageListOrderedItem::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case pageListOrderedItemText::ID:
      return pageListOrderedItemText::fetch(p);
    case pageListOrderedItemBlocks::ID:
      return pageListOrderedItemBlocks::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

pageListOrderedItemText::pageListOrderedItemText(string const &num_, object_ptr<RichText> &&text_)
  : num_(num_)
  , text_(std::move(text_))
{}

const std::int32_t pageListOrderedItemText::ID;

object_ptr<PageListOrderedItem> pageListOrderedItemText::fetch(TlBufferParser &p) {
  return make_tl_object<pageListOrderedItemText>(p);
}

pageListOrderedItemText::pageListOrderedItemText(TlBufferParser &p)
  : num_(TlFetchString<string>::parse(p))
  , text_(TlFetchObject<RichText>::parse(p))
{}

void pageListOrderedItemText::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(num_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageListOrderedItemText::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(num_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageListOrderedItemText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageListOrderedItemText");
    s.store_field("num", num_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageListOrderedItemBlocks::pageListOrderedItemBlocks(string const &num_, array<object_ptr<PageBlock>> &&blocks_)
  : num_(num_)
  , blocks_(std::move(blocks_))
{}

const std::int32_t pageListOrderedItemBlocks::ID;

object_ptr<PageListOrderedItem> pageListOrderedItemBlocks::fetch(TlBufferParser &p) {
  return make_tl_object<pageListOrderedItemBlocks>(p);
}

pageListOrderedItemBlocks::pageListOrderedItemBlocks(TlBufferParser &p)
  : num_(TlFetchString<string>::parse(p))
  , blocks_(TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p))
{}

void pageListOrderedItemBlocks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(num_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
}

void pageListOrderedItemBlocks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(num_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
}

void pageListOrderedItemBlocks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageListOrderedItemBlocks");
    s.store_field("num", num_);
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<PaidReactionPrivacy> PaidReactionPrivacy::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case paidReactionPrivacyDefault::ID:
      return paidReactionPrivacyDefault::fetch(p);
    case paidReactionPrivacyAnonymous::ID:
      return paidReactionPrivacyAnonymous::fetch(p);
    case paidReactionPrivacyPeer::ID:
      return paidReactionPrivacyPeer::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t paidReactionPrivacyDefault::ID;

object_ptr<PaidReactionPrivacy> paidReactionPrivacyDefault::fetch(TlBufferParser &p) {
  return make_tl_object<paidReactionPrivacyDefault>();
}

void paidReactionPrivacyDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void paidReactionPrivacyDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void paidReactionPrivacyDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactionPrivacyDefault");
    s.store_class_end();
  }
}

const std::int32_t paidReactionPrivacyAnonymous::ID;

object_ptr<PaidReactionPrivacy> paidReactionPrivacyAnonymous::fetch(TlBufferParser &p) {
  return make_tl_object<paidReactionPrivacyAnonymous>();
}

void paidReactionPrivacyAnonymous::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void paidReactionPrivacyAnonymous::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void paidReactionPrivacyAnonymous::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactionPrivacyAnonymous");
    s.store_class_end();
  }
}

paidReactionPrivacyPeer::paidReactionPrivacyPeer(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t paidReactionPrivacyPeer::ID;

object_ptr<PaidReactionPrivacy> paidReactionPrivacyPeer::fetch(TlBufferParser &p) {
  return make_tl_object<paidReactionPrivacyPeer>(p);
}

paidReactionPrivacyPeer::paidReactionPrivacyPeer(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
{}

void paidReactionPrivacyPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void paidReactionPrivacyPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void paidReactionPrivacyPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paidReactionPrivacyPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

object_ptr<Peer> Peer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case peerUser::ID:
      return peerUser::fetch(p);
    case peerChat::ID:
      return peerChat::fetch(p);
    case peerChannel::ID:
      return peerChannel::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

peerUser::peerUser(int64 user_id_)
  : user_id_(user_id_)
{}

const std::int32_t peerUser::ID;

object_ptr<Peer> peerUser::fetch(TlBufferParser &p) {
  return make_tl_object<peerUser>(p);
}

peerUser::peerUser(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
{}

void peerUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
}

void peerUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
}

void peerUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

peerChat::peerChat(int64 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t peerChat::ID;

object_ptr<Peer> peerChat::fetch(TlBufferParser &p) {
  return make_tl_object<peerChat>(p);
}

peerChat::peerChat(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
{}

void peerChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(chat_id_, s);
}

void peerChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(chat_id_, s);
}

void peerChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

peerChannel::peerChannel(int64 channel_id_)
  : channel_id_(channel_id_)
{}

const std::int32_t peerChannel::ID;

object_ptr<Peer> peerChannel::fetch(TlBufferParser &p) {
  return make_tl_object<peerChannel>(p);
}

peerChannel::peerChannel(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
{}

void peerChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(channel_id_, s);
}

void peerChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(channel_id_, s);
}

void peerChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerChannel");
    s.store_field("channel_id", channel_id_);
    s.store_class_end();
  }
}

object_ptr<PollAnswer> PollAnswer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case pollAnswer::ID:
      return pollAnswer::fetch(p);
    case inputPollAnswer::ID:
      return inputPollAnswer::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

pollAnswer::pollAnswer()
  : flags_()
  , text_()
  , option_()
  , media_()
  , added_by_()
  , date_()
{}

pollAnswer::pollAnswer(int32 flags_, object_ptr<textWithEntities> &&text_, bytes &&option_, object_ptr<MessageMedia> &&media_, object_ptr<Peer> &&added_by_, int32 date_)
  : flags_(flags_)
  , text_(std::move(text_))
  , option_(std::move(option_))
  , media_(std::move(media_))
  , added_by_(std::move(added_by_))
  , date_(date_)
{}

const std::int32_t pollAnswer::ID;

object_ptr<PollAnswer> pollAnswer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pollAnswer> res = make_tl_object<pollAnswer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->text_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  res->option_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 1) { res->media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (var0 & 2) { res->added_by_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 2) { res->date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void pollAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
  TlStoreString::store(option_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(added_by_, s); }
  if (var0 & 2) { TlStoreBinary::store(date_, s); }
}

void pollAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
  TlStoreString::store(option_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(added_by_, s); }
  if (var0 & 2) { TlStoreBinary::store(date_, s); }
}

void pollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollAnswer");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_bytes_field("option", option_);
    if (var0 & 1) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 2) { s.store_object_field("added_by", static_cast<const BaseObject *>(added_by_.get())); }
    if (var0 & 2) { s.store_field("date", date_); }
    s.store_class_end();
  }
}

inputPollAnswer::inputPollAnswer()
  : flags_()
  , text_()
  , media_()
{}

inputPollAnswer::inputPollAnswer(int32 flags_, object_ptr<textWithEntities> &&text_, object_ptr<InputMedia> &&media_)
  : flags_(flags_)
  , text_(std::move(text_))
  , media_(std::move(media_))
{}

const std::int32_t inputPollAnswer::ID;

object_ptr<PollAnswer> inputPollAnswer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputPollAnswer> res = make_tl_object<inputPollAnswer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->text_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (var0 & 1) { res->media_ = TlFetchObject<InputMedia>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputPollAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
}

void inputPollAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
}

void inputPollAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPollAnswer");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    if (var0 & 1) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    s.store_class_end();
  }
}

premiumSubscriptionOption::premiumSubscriptionOption()
  : flags_()
  , current_()
  , can_purchase_upgrade_()
  , transaction_()
  , months_()
  , currency_()
  , amount_()
  , bot_url_()
  , store_product_()
{}

const std::int32_t premiumSubscriptionOption::ID;

object_ptr<premiumSubscriptionOption> premiumSubscriptionOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<premiumSubscriptionOption> res = make_tl_object<premiumSubscriptionOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->current_ = (var0 & 2) != 0;
  res->can_purchase_upgrade_ = (var0 & 4) != 0;
  if (var0 & 8) { res->transaction_ = TlFetchString<string>::parse(p); }
  res->months_ = TlFetchInt::parse(p);
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  res->bot_url_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->store_product_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void premiumSubscriptionOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumSubscriptionOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (current_ << 1) | (can_purchase_upgrade_ << 2)));
    if (var0 & 2) { s.store_field("current", true); }
    if (var0 & 4) { s.store_field("can_purchase_upgrade", true); }
    if (var0 & 8) { s.store_field("transaction", transaction_); }
    s.store_field("months", months_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_field("bot_url", bot_url_);
    if (var0 & 1) { s.store_field("store_product", store_product_); }
    s.store_class_end();
  }
}

const std::int32_t quickReply::ID;

object_ptr<quickReply> quickReply::fetch(TlBufferParser &p) {
  return make_tl_object<quickReply>(p);
}

quickReply::quickReply(TlBufferParser &p)
  : shortcut_id_(TlFetchInt::parse(p))
  , shortcut_(TlFetchString<string>::parse(p))
  , top_message_(TlFetchInt::parse(p))
  , count_(TlFetchInt::parse(p))
{}

void quickReply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "quickReply");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_field("shortcut", shortcut_);
    s.store_field("top_message", top_message_);
    s.store_field("count", count_);
    s.store_class_end();
  }
}

object_ptr<RequirementToContact> RequirementToContact::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case requirementToContactEmpty::ID:
      return requirementToContactEmpty::fetch(p);
    case requirementToContactPremium::ID:
      return requirementToContactPremium::fetch(p);
    case requirementToContactPaidMessages::ID:
      return requirementToContactPaidMessages::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t requirementToContactEmpty::ID;

object_ptr<RequirementToContact> requirementToContactEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<requirementToContactEmpty>();
}

void requirementToContactEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requirementToContactEmpty");
    s.store_class_end();
  }
}

const std::int32_t requirementToContactPremium::ID;

object_ptr<RequirementToContact> requirementToContactPremium::fetch(TlBufferParser &p) {
  return make_tl_object<requirementToContactPremium>();
}

void requirementToContactPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requirementToContactPremium");
    s.store_class_end();
  }
}

const std::int32_t requirementToContactPaidMessages::ID;

object_ptr<RequirementToContact> requirementToContactPaidMessages::fetch(TlBufferParser &p) {
  return make_tl_object<requirementToContactPaidMessages>(p);
}

requirementToContactPaidMessages::requirementToContactPaidMessages(TlBufferParser &p)
  : stars_amount_(TlFetchLong::parse(p))
{}

void requirementToContactPaidMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requirementToContactPaidMessages");
    s.store_field("stars_amount", stars_amount_);
    s.store_class_end();
  }
}

savedStarGift::savedStarGift()
  : flags_()
  , name_hidden_()
  , unsaved_()
  , refunded_()
  , can_upgrade_()
  , pinned_to_top_()
  , upgrade_separate_()
  , from_id_()
  , date_()
  , gift_()
  , message_()
  , msg_id_()
  , saved_id_()
  , convert_stars_()
  , upgrade_stars_()
  , can_export_at_()
  , transfer_stars_()
  , can_transfer_at_()
  , can_resell_at_()
  , collection_id_()
  , prepaid_upgrade_hash_()
  , drop_original_details_stars_()
  , gift_num_()
  , can_craft_at_()
{}

const std::int32_t savedStarGift::ID;

object_ptr<savedStarGift> savedStarGift::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<savedStarGift> res = make_tl_object<savedStarGift>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->name_hidden_ = (var0 & 1) != 0;
  res->unsaved_ = (var0 & 32) != 0;
  res->refunded_ = (var0 & 512) != 0;
  res->can_upgrade_ = (var0 & 1024) != 0;
  res->pinned_to_top_ = (var0 & 4096) != 0;
  res->upgrade_separate_ = (var0 & 131072) != 0;
  if (var0 & 2) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->gift_ = TlFetchObject<StarGift>::parse(p);
  if (var0 & 4) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (var0 & 8) { res->msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->saved_id_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->convert_stars_ = TlFetchLong::parse(p); }
  if (var0 & 64) { res->upgrade_stars_ = TlFetchLong::parse(p); }
  if (var0 & 128) { res->can_export_at_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->transfer_stars_ = TlFetchLong::parse(p); }
  if (var0 & 8192) { res->can_transfer_at_ = TlFetchInt::parse(p); }
  if (var0 & 16384) { res->can_resell_at_ = TlFetchInt::parse(p); }
  if (var0 & 32768) { res->collection_id_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (var0 & 65536) { res->prepaid_upgrade_hash_ = TlFetchString<string>::parse(p); }
  if (var0 & 262144) { res->drop_original_details_stars_ = TlFetchLong::parse(p); }
  if (var0 & 524288) { res->gift_num_ = TlFetchInt::parse(p); }
  if (var0 & 1048576) { res->can_craft_at_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void savedStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedStarGift");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (name_hidden_ << 0) | (unsaved_ << 5) | (refunded_ << 9) | (can_upgrade_ << 10) | (pinned_to_top_ << 12) | (upgrade_separate_ << 17)));
    if (var0 & 1) { s.store_field("name_hidden", true); }
    if (var0 & 32) { s.store_field("unsaved", true); }
    if (var0 & 512) { s.store_field("refunded", true); }
    if (var0 & 1024) { s.store_field("can_upgrade", true); }
    if (var0 & 4096) { s.store_field("pinned_to_top", true); }
    if (var0 & 131072) { s.store_field("upgrade_separate", true); }
    if (var0 & 2) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    s.store_field("date", date_);
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    if (var0 & 4) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    if (var0 & 8) { s.store_field("msg_id", msg_id_); }
    if (var0 & 2048) { s.store_field("saved_id", saved_id_); }
    if (var0 & 16) { s.store_field("convert_stars", convert_stars_); }
    if (var0 & 64) { s.store_field("upgrade_stars", upgrade_stars_); }
    if (var0 & 128) { s.store_field("can_export_at", can_export_at_); }
    if (var0 & 256) { s.store_field("transfer_stars", transfer_stars_); }
    if (var0 & 8192) { s.store_field("can_transfer_at", can_transfer_at_); }
    if (var0 & 16384) { s.store_field("can_resell_at", can_resell_at_); }
    if (var0 & 32768) { { s.store_vector_begin("collection_id", collection_id_.size()); for (const auto &_value : collection_id_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 65536) { s.store_field("prepaid_upgrade_hash", prepaid_upgrade_hash_); }
    if (var0 & 262144) { s.store_field("drop_original_details_stars", drop_original_details_stars_); }
    if (var0 & 524288) { s.store_field("gift_num", gift_num_); }
    if (var0 & 1048576) { s.store_field("can_craft_at", can_craft_at_); }
    s.store_class_end();
  }
}

secureCredentialsEncrypted::secureCredentialsEncrypted(bytes &&data_, bytes &&hash_, bytes &&secret_)
  : data_(std::move(data_))
  , hash_(std::move(hash_))
  , secret_(std::move(secret_))
{}

const std::int32_t secureCredentialsEncrypted::ID;

object_ptr<secureCredentialsEncrypted> secureCredentialsEncrypted::fetch(TlBufferParser &p) {
  return make_tl_object<secureCredentialsEncrypted>(p);
}

secureCredentialsEncrypted::secureCredentialsEncrypted(TlBufferParser &p)
  : data_(TlFetchBytes<bytes>::parse(p))
  , hash_(TlFetchBytes<bytes>::parse(p))
  , secret_(TlFetchBytes<bytes>::parse(p))
{}

void secureCredentialsEncrypted::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(data_, s);
  TlStoreString::store(hash_, s);
  TlStoreString::store(secret_, s);
}

void secureCredentialsEncrypted::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(data_, s);
  TlStoreString::store(hash_, s);
  TlStoreString::store(secret_, s);
}

void secureCredentialsEncrypted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureCredentialsEncrypted");
    s.store_bytes_field("data", data_);
    s.store_bytes_field("hash", hash_);
    s.store_bytes_field("secret", secret_);
    s.store_class_end();
  }
}

secureSecretSettings::secureSecretSettings(object_ptr<SecurePasswordKdfAlgo> &&secure_algo_, bytes &&secure_secret_, int64 secure_secret_id_)
  : secure_algo_(std::move(secure_algo_))
  , secure_secret_(std::move(secure_secret_))
  , secure_secret_id_(secure_secret_id_)
{}

const std::int32_t secureSecretSettings::ID;

object_ptr<secureSecretSettings> secureSecretSettings::fetch(TlBufferParser &p) {
  return make_tl_object<secureSecretSettings>(p);
}

secureSecretSettings::secureSecretSettings(TlBufferParser &p)
  : secure_algo_(TlFetchObject<SecurePasswordKdfAlgo>::parse(p))
  , secure_secret_(TlFetchBytes<bytes>::parse(p))
  , secure_secret_id_(TlFetchLong::parse(p))
{}

void secureSecretSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(secure_algo_, s);
  TlStoreString::store(secure_secret_, s);
  TlStoreBinary::store(secure_secret_id_, s);
}

void secureSecretSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(secure_algo_, s);
  TlStoreString::store(secure_secret_, s);
  TlStoreBinary::store(secure_secret_id_, s);
}

void secureSecretSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureSecretSettings");
    s.store_object_field("secure_algo", static_cast<const BaseObject *>(secure_algo_.get()));
    s.store_bytes_field("secure_secret", secure_secret_);
    s.store_field("secure_secret_id", secure_secret_id_);
    s.store_class_end();
  }
}

starsTransaction::starsTransaction()
  : flags_()
  , refund_()
  , pending_()
  , failed_()
  , gift_()
  , reaction_()
  , stargift_upgrade_()
  , business_transfer_()
  , stargift_resale_()
  , posts_search_()
  , stargift_prepaid_upgrade_()
  , stargift_drop_original_details_()
  , phonegroup_message_()
  , stargift_auction_bid_()
  , offer_()
  , id_()
  , amount_()
  , date_()
  , peer_()
  , title_()
  , description_()
  , photo_()
  , transaction_date_()
  , transaction_url_()
  , bot_payload_()
  , msg_id_()
  , extended_media_()
  , subscription_period_()
  , giveaway_post_id_()
  , stargift_()
  , floodskip_number_()
  , starref_commission_permille_()
  , starref_peer_()
  , starref_amount_()
  , paid_messages_()
  , premium_gift_months_()
  , ads_proceeds_from_date_()
  , ads_proceeds_to_date_()
{}

const std::int32_t starsTransaction::ID;

object_ptr<starsTransaction> starsTransaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsTransaction> res = make_tl_object<starsTransaction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->refund_ = (var0 & 8) != 0;
  res->pending_ = (var0 & 16) != 0;
  res->failed_ = (var0 & 64) != 0;
  res->gift_ = (var0 & 1024) != 0;
  res->reaction_ = (var0 & 2048) != 0;
  res->stargift_upgrade_ = (var0 & 262144) != 0;
  res->business_transfer_ = (var0 & 2097152) != 0;
  res->stargift_resale_ = (var0 & 4194304) != 0;
  res->posts_search_ = (var0 & 16777216) != 0;
  res->stargift_prepaid_upgrade_ = (var0 & 33554432) != 0;
  res->stargift_drop_original_details_ = (var0 & 67108864) != 0;
  res->phonegroup_message_ = (var0 & 134217728) != 0;
  res->stargift_auction_bid_ = (var0 & 268435456) != 0;
  res->offer_ = (var0 & 536870912) != 0;
  res->id_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchObject<StarsAmount>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->peer_ = TlFetchObject<StarsTransactionPeer>::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->description_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  if (var0 & 32) { res->transaction_date_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->transaction_url_ = TlFetchString<string>::parse(p); }
  if (var0 & 128) { res->bot_payload_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 256) { res->msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 512) { res->extended_media_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageMedia>>, 481674261>::parse(p); }
  if (var0 & 4096) { res->subscription_period_ = TlFetchInt::parse(p); }
  if (var0 & 8192) { res->giveaway_post_id_ = TlFetchInt::parse(p); }
  if (var0 & 16384) { res->stargift_ = TlFetchObject<StarGift>::parse(p); }
  if (var0 & 32768) { res->floodskip_number_ = TlFetchInt::parse(p); }
  if (var0 & 65536) { res->starref_commission_permille_ = TlFetchInt::parse(p); }
  if (var0 & 131072) { res->starref_peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 131072) { res->starref_amount_ = TlFetchObject<StarsAmount>::parse(p); }
  if (var0 & 524288) { res->paid_messages_ = TlFetchInt::parse(p); }
  if (var0 & 1048576) { res->premium_gift_months_ = TlFetchInt::parse(p); }
  if (var0 & 8388608) { res->ads_proceeds_from_date_ = TlFetchInt::parse(p); }
  if (var0 & 8388608) { res->ads_proceeds_to_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransaction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (refund_ << 3) | (pending_ << 4) | (failed_ << 6) | (gift_ << 10) | (reaction_ << 11) | (stargift_upgrade_ << 18) | (business_transfer_ << 21) | (stargift_resale_ << 22) | (posts_search_ << 24) | (stargift_prepaid_upgrade_ << 25) | (stargift_drop_original_details_ << 26) | (phonegroup_message_ << 27) | (stargift_auction_bid_ << 28) | (offer_ << 29)));
    if (var0 & 8) { s.store_field("refund", true); }
    if (var0 & 16) { s.store_field("pending", true); }
    if (var0 & 64) { s.store_field("failed", true); }
    if (var0 & 1024) { s.store_field("gift", true); }
    if (var0 & 2048) { s.store_field("reaction", true); }
    if (var0 & 262144) { s.store_field("stargift_upgrade", true); }
    if (var0 & 2097152) { s.store_field("business_transfer", true); }
    if (var0 & 4194304) { s.store_field("stargift_resale", true); }
    if (var0 & 16777216) { s.store_field("posts_search", true); }
    if (var0 & 33554432) { s.store_field("stargift_prepaid_upgrade", true); }
    if (var0 & 67108864) { s.store_field("stargift_drop_original_details", true); }
    if (var0 & 134217728) { s.store_field("phonegroup_message", true); }
    if (var0 & 268435456) { s.store_field("stargift_auction_bid", true); }
    if (var0 & 536870912) { s.store_field("offer", true); }
    s.store_field("id", id_);
    s.store_object_field("amount", static_cast<const BaseObject *>(amount_.get()));
    s.store_field("date", date_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("description", description_); }
    if (var0 & 4) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 32) { s.store_field("transaction_date", transaction_date_); }
    if (var0 & 32) { s.store_field("transaction_url", transaction_url_); }
    if (var0 & 128) { s.store_bytes_field("bot_payload", bot_payload_); }
    if (var0 & 256) { s.store_field("msg_id", msg_id_); }
    if (var0 & 512) { { s.store_vector_begin("extended_media", extended_media_.size()); for (const auto &_value : extended_media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4096) { s.store_field("subscription_period", subscription_period_); }
    if (var0 & 8192) { s.store_field("giveaway_post_id", giveaway_post_id_); }
    if (var0 & 16384) { s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get())); }
    if (var0 & 32768) { s.store_field("floodskip_number", floodskip_number_); }
    if (var0 & 65536) { s.store_field("starref_commission_permille", starref_commission_permille_); }
    if (var0 & 131072) { s.store_object_field("starref_peer", static_cast<const BaseObject *>(starref_peer_.get())); }
    if (var0 & 131072) { s.store_object_field("starref_amount", static_cast<const BaseObject *>(starref_amount_.get())); }
    if (var0 & 524288) { s.store_field("paid_messages", paid_messages_); }
    if (var0 & 1048576) { s.store_field("premium_gift_months", premium_gift_months_); }
    if (var0 & 8388608) { s.store_field("ads_proceeds_from_date", ads_proceeds_from_date_); }
    if (var0 & 8388608) { s.store_field("ads_proceeds_to_date", ads_proceeds_to_date_); }
    s.store_class_end();
  }
}

const std::int32_t statsDateRangeDays::ID;

object_ptr<statsDateRangeDays> statsDateRangeDays::fetch(TlBufferParser &p) {
  return make_tl_object<statsDateRangeDays>(p);
}

statsDateRangeDays::statsDateRangeDays(TlBufferParser &p)
  : min_date_(TlFetchInt::parse(p))
  , max_date_(TlFetchInt::parse(p))
{}

void statsDateRangeDays::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsDateRangeDays");
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_class_end();
  }
}

object_ptr<StatsGraph> StatsGraph::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case statsGraphAsync::ID:
      return statsGraphAsync::fetch(p);
    case statsGraphError::ID:
      return statsGraphError::fetch(p);
    case statsGraph::ID:
      return statsGraph::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t statsGraphAsync::ID;

object_ptr<StatsGraph> statsGraphAsync::fetch(TlBufferParser &p) {
  return make_tl_object<statsGraphAsync>(p);
}

statsGraphAsync::statsGraphAsync(TlBufferParser &p)
  : token_(TlFetchString<string>::parse(p))
{}

void statsGraphAsync::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsGraphAsync");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

statsGraphError::statsGraphError(string const &error_)
  : error_(error_)
{}

const std::int32_t statsGraphError::ID;

object_ptr<StatsGraph> statsGraphError::fetch(TlBufferParser &p) {
  return make_tl_object<statsGraphError>(p);
}

statsGraphError::statsGraphError(TlBufferParser &p)
  : error_(TlFetchString<string>::parse(p))
{}

void statsGraphError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsGraphError");
    s.store_field("error", error_);
    s.store_class_end();
  }
}

statsGraph::statsGraph()
  : flags_()
  , json_()
  , zoom_token_()
{}

const std::int32_t statsGraph::ID;

object_ptr<StatsGraph> statsGraph::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<statsGraph> res = make_tl_object<statsGraph>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->json_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
  if (var0 & 1) { res->zoom_token_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void statsGraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsGraph");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("json", static_cast<const BaseObject *>(json_.get()));
    if (var0 & 1) { s.store_field("zoom_token", zoom_token_); }
    s.store_class_end();
  }
}

textWithEntities::textWithEntities(string const &text_, array<object_ptr<MessageEntity>> &&entities_)
  : text_(text_)
  , entities_(std::move(entities_))
{}

const std::int32_t textWithEntities::ID;

object_ptr<textWithEntities> textWithEntities::fetch(TlBufferParser &p) {
  return make_tl_object<textWithEntities>(p);
}

textWithEntities::textWithEntities(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , entities_(TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p))
{}

void textWithEntities::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s);
}

void textWithEntities::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s);
}

void textWithEntities::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textWithEntities");
    s.store_field("text", text_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

theme::theme()
  : flags_()
  , creator_()
  , default_()
  , for_chat_()
  , id_()
  , access_hash_()
  , slug_()
  , title_()
  , document_()
  , settings_()
  , emoticon_()
  , installs_count_()
{}

const std::int32_t theme::ID;

object_ptr<theme> theme::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<theme> res = make_tl_object<theme>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  res->default_ = (var0 & 2) != 0;
  res->for_chat_ = (var0 & 32) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->slug_ = TlFetchString<string>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->document_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 8) { res->settings_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<themeSettings>, -94849324>>, 481674261>::parse(p); }
  if (var0 & 64) { res->emoticon_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->installs_count_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void theme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "theme");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | (default_ << 1) | (for_chat_ << 5)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 2) { s.store_field("default", true); }
    if (var0 & 32) { s.store_field("for_chat", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("slug", slug_);
    s.store_field("title", title_);
    if (var0 & 4) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 8) { { s.store_vector_begin("settings", settings_.size()); for (const auto &_value : settings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 64) { s.store_field("emoticon", emoticon_); }
    if (var0 & 16) { s.store_field("installs_count", installs_count_); }
    s.store_class_end();
  }
}

todoCompletion::todoCompletion(int32 id_, object_ptr<Peer> &&completed_by_, int32 date_)
  : id_(id_)
  , completed_by_(std::move(completed_by_))
  , date_(date_)
{}

const std::int32_t todoCompletion::ID;

object_ptr<todoCompletion> todoCompletion::fetch(TlBufferParser &p) {
  return make_tl_object<todoCompletion>(p);
}

todoCompletion::todoCompletion(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , completed_by_(TlFetchObject<Peer>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void todoCompletion::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(completed_by_, s);
  TlStoreBinary::store(date_, s);
}

void todoCompletion::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(completed_by_, s);
  TlStoreBinary::store(date_, s);
}

void todoCompletion::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "todoCompletion");
    s.store_field("id", id_);
    s.store_object_field("completed_by", static_cast<const BaseObject *>(completed_by_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

todoList::todoList()
  : flags_()
  , others_can_append_()
  , others_can_complete_()
  , title_()
  , list_()
{}

todoList::todoList(int32 flags_, bool others_can_append_, bool others_can_complete_, object_ptr<textWithEntities> &&title_, array<object_ptr<todoItem>> &&list_)
  : flags_(flags_)
  , others_can_append_(others_can_append_)
  , others_can_complete_(others_can_complete_)
  , title_(std::move(title_))
  , list_(std::move(list_))
{}

const std::int32_t todoList::ID;

object_ptr<todoList> todoList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<todoList> res = make_tl_object<todoList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->others_can_append_ = (var0 & 1) != 0;
  res->others_can_complete_ = (var0 & 2) != 0;
  res->title_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  res->list_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<todoItem>, -878074577>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void todoList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (others_can_append_ << 0) | (others_can_complete_ << 1)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -878074577>>, 481674261>::store(list_, s);
}

void todoList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (others_can_append_ << 0) | (others_can_complete_ << 1)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -878074577>>, 481674261>::store(list_, s);
}

void todoList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "todoList");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (others_can_append_ << 0) | (others_can_complete_ << 1)));
    if (var0 & 1) { s.store_field("others_can_append", true); }
    if (var0 & 2) { s.store_field("others_can_complete", true); }
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    { s.store_vector_begin("list", list_.size()); for (const auto &_value : list_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<Update> Update::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case updateNewMessage::ID:
      return updateNewMessage::fetch(p);
    case updateMessageID::ID:
      return updateMessageID::fetch(p);
    case updateDeleteMessages::ID:
      return updateDeleteMessages::fetch(p);
    case updateUserTyping::ID:
      return updateUserTyping::fetch(p);
    case updateChatUserTyping::ID:
      return updateChatUserTyping::fetch(p);
    case updateChatParticipants::ID:
      return updateChatParticipants::fetch(p);
    case updateUserStatus::ID:
      return updateUserStatus::fetch(p);
    case updateUserName::ID:
      return updateUserName::fetch(p);
    case updateNewAuthorization::ID:
      return updateNewAuthorization::fetch(p);
    case updateNewEncryptedMessage::ID:
      return updateNewEncryptedMessage::fetch(p);
    case updateEncryptedChatTyping::ID:
      return updateEncryptedChatTyping::fetch(p);
    case updateEncryption::ID:
      return updateEncryption::fetch(p);
    case updateEncryptedMessagesRead::ID:
      return updateEncryptedMessagesRead::fetch(p);
    case updateChatParticipantAdd::ID:
      return updateChatParticipantAdd::fetch(p);
    case updateChatParticipantDelete::ID:
      return updateChatParticipantDelete::fetch(p);
    case updateDcOptions::ID:
      return updateDcOptions::fetch(p);
    case updateNotifySettings::ID:
      return updateNotifySettings::fetch(p);
    case updateServiceNotification::ID:
      return updateServiceNotification::fetch(p);
    case updatePrivacy::ID:
      return updatePrivacy::fetch(p);
    case updateUserPhone::ID:
      return updateUserPhone::fetch(p);
    case updateReadHistoryInbox::ID:
      return updateReadHistoryInbox::fetch(p);
    case updateReadHistoryOutbox::ID:
      return updateReadHistoryOutbox::fetch(p);
    case updateWebPage::ID:
      return updateWebPage::fetch(p);
    case updateReadMessagesContents::ID:
      return updateReadMessagesContents::fetch(p);
    case updateChannelTooLong::ID:
      return updateChannelTooLong::fetch(p);
    case updateChannel::ID:
      return updateChannel::fetch(p);
    case updateNewChannelMessage::ID:
      return updateNewChannelMessage::fetch(p);
    case updateReadChannelInbox::ID:
      return updateReadChannelInbox::fetch(p);
    case updateDeleteChannelMessages::ID:
      return updateDeleteChannelMessages::fetch(p);
    case updateChannelMessageViews::ID:
      return updateChannelMessageViews::fetch(p);
    case updateChatParticipantAdmin::ID:
      return updateChatParticipantAdmin::fetch(p);
    case updateNewStickerSet::ID:
      return updateNewStickerSet::fetch(p);
    case updateStickerSetsOrder::ID:
      return updateStickerSetsOrder::fetch(p);
    case updateStickerSets::ID:
      return updateStickerSets::fetch(p);
    case updateSavedGifs::ID:
      return updateSavedGifs::fetch(p);
    case updateBotInlineQuery::ID:
      return updateBotInlineQuery::fetch(p);
    case updateBotInlineSend::ID:
      return updateBotInlineSend::fetch(p);
    case updateEditChannelMessage::ID:
      return updateEditChannelMessage::fetch(p);
    case updateBotCallbackQuery::ID:
      return updateBotCallbackQuery::fetch(p);
    case updateEditMessage::ID:
      return updateEditMessage::fetch(p);
    case updateInlineBotCallbackQuery::ID:
      return updateInlineBotCallbackQuery::fetch(p);
    case updateReadChannelOutbox::ID:
      return updateReadChannelOutbox::fetch(p);
    case updateDraftMessage::ID:
      return updateDraftMessage::fetch(p);
    case updateReadFeaturedStickers::ID:
      return updateReadFeaturedStickers::fetch(p);
    case updateRecentStickers::ID:
      return updateRecentStickers::fetch(p);
    case updateConfig::ID:
      return updateConfig::fetch(p);
    case updatePtsChanged::ID:
      return updatePtsChanged::fetch(p);
    case updateChannelWebPage::ID:
      return updateChannelWebPage::fetch(p);
    case updateDialogPinned::ID:
      return updateDialogPinned::fetch(p);
    case updatePinnedDialogs::ID:
      return updatePinnedDialogs::fetch(p);
    case updateBotWebhookJSON::ID:
      return updateBotWebhookJSON::fetch(p);
    case updateBotWebhookJSONQuery::ID:
      return updateBotWebhookJSONQuery::fetch(p);
    case updateBotShippingQuery::ID:
      return updateBotShippingQuery::fetch(p);
    case updateBotPrecheckoutQuery::ID:
      return updateBotPrecheckoutQuery::fetch(p);
    case updatePhoneCall::ID:
      return updatePhoneCall::fetch(p);
    case updateLangPackTooLong::ID:
      return updateLangPackTooLong::fetch(p);
    case updateLangPack::ID:
      return updateLangPack::fetch(p);
    case updateFavedStickers::ID:
      return updateFavedStickers::fetch(p);
    case updateChannelReadMessagesContents::ID:
      return updateChannelReadMessagesContents::fetch(p);
    case updateContactsReset::ID:
      return updateContactsReset::fetch(p);
    case updateChannelAvailableMessages::ID:
      return updateChannelAvailableMessages::fetch(p);
    case updateDialogUnreadMark::ID:
      return updateDialogUnreadMark::fetch(p);
    case updateMessagePoll::ID:
      return updateMessagePoll::fetch(p);
    case updateChatDefaultBannedRights::ID:
      return updateChatDefaultBannedRights::fetch(p);
    case updateFolderPeers::ID:
      return updateFolderPeers::fetch(p);
    case updatePeerSettings::ID:
      return updatePeerSettings::fetch(p);
    case updatePeerLocated::ID:
      return updatePeerLocated::fetch(p);
    case updateNewScheduledMessage::ID:
      return updateNewScheduledMessage::fetch(p);
    case updateDeleteScheduledMessages::ID:
      return updateDeleteScheduledMessages::fetch(p);
    case updateTheme::ID:
      return updateTheme::fetch(p);
    case updateGeoLiveViewed::ID:
      return updateGeoLiveViewed::fetch(p);
    case updateLoginToken::ID:
      return updateLoginToken::fetch(p);
    case updateMessagePollVote::ID:
      return updateMessagePollVote::fetch(p);
    case updateDialogFilter::ID:
      return updateDialogFilter::fetch(p);
    case updateDialogFilterOrder::ID:
      return updateDialogFilterOrder::fetch(p);
    case updateDialogFilters::ID:
      return updateDialogFilters::fetch(p);
    case updatePhoneCallSignalingData::ID:
      return updatePhoneCallSignalingData::fetch(p);
    case updateChannelMessageForwards::ID:
      return updateChannelMessageForwards::fetch(p);
    case updateReadChannelDiscussionInbox::ID:
      return updateReadChannelDiscussionInbox::fetch(p);
    case updateReadChannelDiscussionOutbox::ID:
      return updateReadChannelDiscussionOutbox::fetch(p);
    case updatePeerBlocked::ID:
      return updatePeerBlocked::fetch(p);
    case updateChannelUserTyping::ID:
      return updateChannelUserTyping::fetch(p);
    case updatePinnedMessages::ID:
      return updatePinnedMessages::fetch(p);
    case updatePinnedChannelMessages::ID:
      return updatePinnedChannelMessages::fetch(p);
    case updateChat::ID:
      return updateChat::fetch(p);
    case updateGroupCallParticipants::ID:
      return updateGroupCallParticipants::fetch(p);
    case updateGroupCall::ID:
      return updateGroupCall::fetch(p);
    case updatePeerHistoryTTL::ID:
      return updatePeerHistoryTTL::fetch(p);
    case updateChatParticipant::ID:
      return updateChatParticipant::fetch(p);
    case updateChannelParticipant::ID:
      return updateChannelParticipant::fetch(p);
    case updateBotStopped::ID:
      return updateBotStopped::fetch(p);
    case updateGroupCallConnection::ID:
      return updateGroupCallConnection::fetch(p);
    case updateBotCommands::ID:
      return updateBotCommands::fetch(p);
    case updatePendingJoinRequests::ID:
      return updatePendingJoinRequests::fetch(p);
    case updateBotChatInviteRequester::ID:
      return updateBotChatInviteRequester::fetch(p);
    case updateMessageReactions::ID:
      return updateMessageReactions::fetch(p);
    case updateAttachMenuBots::ID:
      return updateAttachMenuBots::fetch(p);
    case updateWebViewResultSent::ID:
      return updateWebViewResultSent::fetch(p);
    case updateBotMenuButton::ID:
      return updateBotMenuButton::fetch(p);
    case updateSavedRingtones::ID:
      return updateSavedRingtones::fetch(p);
    case updateTranscribedAudio::ID:
      return updateTranscribedAudio::fetch(p);
    case updateReadFeaturedEmojiStickers::ID:
      return updateReadFeaturedEmojiStickers::fetch(p);
    case updateUserEmojiStatus::ID:
      return updateUserEmojiStatus::fetch(p);
    case updateRecentEmojiStatuses::ID:
      return updateRecentEmojiStatuses::fetch(p);
    case updateRecentReactions::ID:
      return updateRecentReactions::fetch(p);
    case updateMoveStickerSetToTop::ID:
      return updateMoveStickerSetToTop::fetch(p);
    case updateMessageExtendedMedia::ID:
      return updateMessageExtendedMedia::fetch(p);
    case updateUser::ID:
      return updateUser::fetch(p);
    case updateAutoSaveSettings::ID:
      return updateAutoSaveSettings::fetch(p);
    case updateStory::ID:
      return updateStory::fetch(p);
    case updateReadStories::ID:
      return updateReadStories::fetch(p);
    case updateStoryID::ID:
      return updateStoryID::fetch(p);
    case updateStoriesStealthMode::ID:
      return updateStoriesStealthMode::fetch(p);
    case updateSentStoryReaction::ID:
      return updateSentStoryReaction::fetch(p);
    case updateBotChatBoost::ID:
      return updateBotChatBoost::fetch(p);
    case updateChannelViewForumAsMessages::ID:
      return updateChannelViewForumAsMessages::fetch(p);
    case updatePeerWallpaper::ID:
      return updatePeerWallpaper::fetch(p);
    case updateBotMessageReaction::ID:
      return updateBotMessageReaction::fetch(p);
    case updateBotMessageReactions::ID:
      return updateBotMessageReactions::fetch(p);
    case updateSavedDialogPinned::ID:
      return updateSavedDialogPinned::fetch(p);
    case updatePinnedSavedDialogs::ID:
      return updatePinnedSavedDialogs::fetch(p);
    case updateSavedReactionTags::ID:
      return updateSavedReactionTags::fetch(p);
    case updateSmsJob::ID:
      return updateSmsJob::fetch(p);
    case updateQuickReplies::ID:
      return updateQuickReplies::fetch(p);
    case updateNewQuickReply::ID:
      return updateNewQuickReply::fetch(p);
    case updateDeleteQuickReply::ID:
      return updateDeleteQuickReply::fetch(p);
    case updateQuickReplyMessage::ID:
      return updateQuickReplyMessage::fetch(p);
    case updateDeleteQuickReplyMessages::ID:
      return updateDeleteQuickReplyMessages::fetch(p);
    case updateBotBusinessConnect::ID:
      return updateBotBusinessConnect::fetch(p);
    case updateBotNewBusinessMessage::ID:
      return updateBotNewBusinessMessage::fetch(p);
    case updateBotEditBusinessMessage::ID:
      return updateBotEditBusinessMessage::fetch(p);
    case updateBotDeleteBusinessMessage::ID:
      return updateBotDeleteBusinessMessage::fetch(p);
    case updateNewStoryReaction::ID:
      return updateNewStoryReaction::fetch(p);
    case updateStarsBalance::ID:
      return updateStarsBalance::fetch(p);
    case updateBusinessBotCallbackQuery::ID:
      return updateBusinessBotCallbackQuery::fetch(p);
    case updateStarsRevenueStatus::ID:
      return updateStarsRevenueStatus::fetch(p);
    case updateBotPurchasedPaidMedia::ID:
      return updateBotPurchasedPaidMedia::fetch(p);
    case updatePaidReactionPrivacy::ID:
      return updatePaidReactionPrivacy::fetch(p);
    case updateSentPhoneCode::ID:
      return updateSentPhoneCode::fetch(p);
    case updateGroupCallChainBlocks::ID:
      return updateGroupCallChainBlocks::fetch(p);
    case updateReadMonoForumInbox::ID:
      return updateReadMonoForumInbox::fetch(p);
    case updateReadMonoForumOutbox::ID:
      return updateReadMonoForumOutbox::fetch(p);
    case updateMonoForumNoPaidException::ID:
      return updateMonoForumNoPaidException::fetch(p);
    case updateGroupCallMessage::ID:
      return updateGroupCallMessage::fetch(p);
    case updateGroupCallEncryptedMessage::ID:
      return updateGroupCallEncryptedMessage::fetch(p);
    case updatePinnedForumTopic::ID:
      return updatePinnedForumTopic::fetch(p);
    case updatePinnedForumTopics::ID:
      return updatePinnedForumTopics::fetch(p);
    case updateDeleteGroupCallMessages::ID:
      return updateDeleteGroupCallMessages::fetch(p);
    case updateStarGiftAuctionState::ID:
      return updateStarGiftAuctionState::fetch(p);
    case updateStarGiftAuctionUserState::ID:
      return updateStarGiftAuctionUserState::fetch(p);
    case updateEmojiGameInfo::ID:
      return updateEmojiGameInfo::fetch(p);
    case updateStarGiftCraftFail::ID:
      return updateStarGiftCraftFail::fetch(p);
    case updateChatParticipantRank::ID:
      return updateChatParticipantRank::fetch(p);
    case updateManagedBot::ID:
      return updateManagedBot::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

updateNewMessage::updateNewMessage(object_ptr<Message> &&message_, int32 pts_, int32 pts_count_)
  : message_(std::move(message_))
  , pts_(pts_)
  , pts_count_(pts_count_)
{}

const std::int32_t updateNewMessage::ID;

object_ptr<Update> updateNewMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewMessage>(p);
}

updateNewMessage::updateNewMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateNewMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

const std::int32_t updateMessageID::ID;

object_ptr<Update> updateMessageID::fetch(TlBufferParser &p) {
  return make_tl_object<updateMessageID>(p);
}

updateMessageID::updateMessageID(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , random_id_(TlFetchLong::parse(p))
{}

void updateMessageID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageID");
    s.store_field("id", id_);
    s.store_field("random_id", random_id_);
    s.store_class_end();
  }
}

updateDeleteMessages::updateDeleteMessages(array<int32> &&messages_, int32 pts_, int32 pts_count_)
  : messages_(std::move(messages_))
  , pts_(pts_)
  , pts_count_(pts_count_)
{}

const std::int32_t updateDeleteMessages::ID;

object_ptr<Update> updateDeleteMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateDeleteMessages>(p);
}

updateDeleteMessages::updateDeleteMessages(TlBufferParser &p)
  : messages_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateDeleteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteMessages");
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateUserTyping::updateUserTyping()
  : flags_()
  , user_id_()
  , top_msg_id_()
  , action_()
{}

const std::int32_t updateUserTyping::ID;

object_ptr<Update> updateUserTyping::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateUserTyping> res = make_tl_object<updateUserTyping>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->top_msg_id_ = TlFetchInt::parse(p); }
  res->action_ = TlFetchObject<SendMessageAction>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateUserTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserTyping");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("user_id", user_id_);
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateChatUserTyping::ID;

object_ptr<Update> updateChatUserTyping::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatUserTyping>(p);
}

updateChatUserTyping::updateChatUserTyping(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
  , from_id_(TlFetchObject<Peer>::parse(p))
  , action_(TlFetchObject<SendMessageAction>::parse(p))
{}

void updateChatUserTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatUserTyping");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateChatParticipants::ID;

object_ptr<Update> updateChatParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatParticipants>(p);
}

updateChatParticipants::updateChatParticipants(TlBufferParser &p)
  : participants_(TlFetchObject<ChatParticipants>::parse(p))
{}

void updateChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatParticipants");
    s.store_object_field("participants", static_cast<const BaseObject *>(participants_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateUserStatus::ID;

object_ptr<Update> updateUserStatus::fetch(TlBufferParser &p) {
  return make_tl_object<updateUserStatus>(p);
}

updateUserStatus::updateUserStatus(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , status_(TlFetchObject<UserStatus>::parse(p))
{}

void updateUserStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserStatus");
    s.store_field("user_id", user_id_);
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateUserName::ID;

object_ptr<Update> updateUserName::fetch(TlBufferParser &p) {
  return make_tl_object<updateUserName>(p);
}

updateUserName::updateUserName(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , first_name_(TlFetchString<string>::parse(p))
  , last_name_(TlFetchString<string>::parse(p))
  , usernames_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<username>, -1274595769>>, 481674261>::parse(p))
{}

void updateUserName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserName");
    s.store_field("user_id", user_id_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    { s.store_vector_begin("usernames", usernames_.size()); for (const auto &_value : usernames_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateNewAuthorization::updateNewAuthorization()
  : flags_()
  , unconfirmed_()
  , hash_()
  , date_()
  , device_()
  , location_()
{}

const std::int32_t updateNewAuthorization::ID;

object_ptr<Update> updateNewAuthorization::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateNewAuthorization> res = make_tl_object<updateNewAuthorization>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->unconfirmed_ = (var0 & 1) != 0;
  res->hash_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->date_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->device_ = TlFetchString<string>::parse(p); }
  if (var0 & 1) { res->location_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateNewAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewAuthorization");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (unconfirmed_ << 0)));
    if (var0 & 1) { s.store_field("unconfirmed", true); }
    s.store_field("hash", hash_);
    if (var0 & 1) { s.store_field("date", date_); }
    if (var0 & 1) { s.store_field("device", device_); }
    if (var0 & 1) { s.store_field("location", location_); }
    s.store_class_end();
  }
}

const std::int32_t updateNewEncryptedMessage::ID;

object_ptr<Update> updateNewEncryptedMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewEncryptedMessage>(p);
}

updateNewEncryptedMessage::updateNewEncryptedMessage(TlBufferParser &p)
  : message_(TlFetchObject<EncryptedMessage>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateNewEncryptedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewEncryptedMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateEncryptedChatTyping::ID;

object_ptr<Update> updateEncryptedChatTyping::fetch(TlBufferParser &p) {
  return make_tl_object<updateEncryptedChatTyping>(p);
}

updateEncryptedChatTyping::updateEncryptedChatTyping(TlBufferParser &p)
  : chat_id_(TlFetchInt::parse(p))
{}

void updateEncryptedChatTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEncryptedChatTyping");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

const std::int32_t updateEncryption::ID;

object_ptr<Update> updateEncryption::fetch(TlBufferParser &p) {
  return make_tl_object<updateEncryption>(p);
}

updateEncryption::updateEncryption(TlBufferParser &p)
  : chat_(TlFetchObject<EncryptedChat>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void updateEncryption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEncryption");
    s.store_object_field("chat", static_cast<const BaseObject *>(chat_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t updateEncryptedMessagesRead::ID;

object_ptr<Update> updateEncryptedMessagesRead::fetch(TlBufferParser &p) {
  return make_tl_object<updateEncryptedMessagesRead>(p);
}

updateEncryptedMessagesRead::updateEncryptedMessagesRead(TlBufferParser &p)
  : chat_id_(TlFetchInt::parse(p))
  , max_date_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void updateEncryptedMessagesRead::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEncryptedMessagesRead");
    s.store_field("chat_id", chat_id_);
    s.store_field("max_date", max_date_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t updateChatParticipantAdd::ID;

object_ptr<Update> updateChatParticipantAdd::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatParticipantAdd>(p);
}

updateChatParticipantAdd::updateChatParticipantAdd(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , inviter_id_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void updateChatParticipantAdd::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatParticipantAdd");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("inviter_id", inviter_id_);
    s.store_field("date", date_);
    s.store_field("version", version_);
    s.store_class_end();
  }
}

const std::int32_t updateChatParticipantDelete::ID;

object_ptr<Update> updateChatParticipantDelete::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatParticipantDelete>(p);
}

updateChatParticipantDelete::updateChatParticipantDelete(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void updateChatParticipantDelete::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatParticipantDelete");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("version", version_);
    s.store_class_end();
  }
}

const std::int32_t updateDcOptions::ID;

object_ptr<Update> updateDcOptions::fetch(TlBufferParser &p) {
  return make_tl_object<updateDcOptions>(p);
}

updateDcOptions::updateDcOptions(TlBufferParser &p)
  : dc_options_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<dcOption>, 414687501>>, 481674261>::parse(p))
{}

void updateDcOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDcOptions");
    { s.store_vector_begin("dc_options", dc_options_.size()); for (const auto &_value : dc_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateNotifySettings::ID;

object_ptr<Update> updateNotifySettings::fetch(TlBufferParser &p) {
  return make_tl_object<updateNotifySettings>(p);
}

updateNotifySettings::updateNotifySettings(TlBufferParser &p)
  : peer_(TlFetchObject<NotifyPeer>::parse(p))
  , notify_settings_(TlFetchBoxed<TlFetchObject<peerNotifySettings>, -1721619444>::parse(p))
{}

void updateNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNotifySettings");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("notify_settings", static_cast<const BaseObject *>(notify_settings_.get()));
    s.store_class_end();
  }
}

updateServiceNotification::updateServiceNotification()
  : flags_()
  , popup_()
  , invert_media_()
  , inbox_date_()
  , type_()
  , message_()
  , media_()
  , entities_()
{}

updateServiceNotification::updateServiceNotification(int32 flags_, bool popup_, bool invert_media_, int32 inbox_date_, string const &type_, string const &message_, object_ptr<MessageMedia> &&media_, array<object_ptr<MessageEntity>> &&entities_)
  : flags_(flags_)
  , popup_(popup_)
  , invert_media_(invert_media_)
  , inbox_date_(inbox_date_)
  , type_(type_)
  , message_(message_)
  , media_(std::move(media_))
  , entities_(std::move(entities_))
{}

const std::int32_t updateServiceNotification::ID;

object_ptr<Update> updateServiceNotification::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateServiceNotification> res = make_tl_object<updateServiceNotification>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->popup_ = (var0 & 1) != 0;
  res->invert_media_ = (var0 & 4) != 0;
  if (var0 & 2) { res->inbox_date_ = TlFetchInt::parse(p); }
  res->type_ = TlFetchString<string>::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  res->media_ = TlFetchObject<MessageMedia>::parse(p);
  res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateServiceNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateServiceNotification");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (popup_ << 0) | (invert_media_ << 2)));
    if (var0 & 1) { s.store_field("popup", true); }
    if (var0 & 4) { s.store_field("invert_media", true); }
    if (var0 & 2) { s.store_field("inbox_date", inbox_date_); }
    s.store_field("type", type_);
    s.store_field("message", message_);
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updatePrivacy::ID;

object_ptr<Update> updatePrivacy::fetch(TlBufferParser &p) {
  return make_tl_object<updatePrivacy>(p);
}

updatePrivacy::updatePrivacy(TlBufferParser &p)
  : key_(TlFetchObject<PrivacyKey>::parse(p))
  , rules_(TlFetchBoxed<TlFetchVector<TlFetchObject<PrivacyRule>>, 481674261>::parse(p))
{}

void updatePrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePrivacy");
    s.store_object_field("key", static_cast<const BaseObject *>(key_.get()));
    { s.store_vector_begin("rules", rules_.size()); for (const auto &_value : rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateUserPhone::ID;

object_ptr<Update> updateUserPhone::fetch(TlBufferParser &p) {
  return make_tl_object<updateUserPhone>(p);
}

updateUserPhone::updateUserPhone(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , phone_(TlFetchString<string>::parse(p))
{}

void updateUserPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserPhone");
    s.store_field("user_id", user_id_);
    s.store_field("phone", phone_);
    s.store_class_end();
  }
}

updateReadHistoryInbox::updateReadHistoryInbox()
  : flags_()
  , folder_id_()
  , peer_()
  , top_msg_id_()
  , max_id_()
  , still_unread_count_()
  , pts_()
  , pts_count_()
{}

const std::int32_t updateReadHistoryInbox::ID;

object_ptr<Update> updateReadHistoryInbox::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateReadHistoryInbox> res = make_tl_object<updateReadHistoryInbox>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->folder_id_ = TlFetchInt::parse(p); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 2) { res->top_msg_id_ = TlFetchInt::parse(p); }
  res->max_id_ = TlFetchInt::parse(p);
  res->still_unread_count_ = TlFetchInt::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateReadHistoryInbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadHistoryInbox");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("folder_id", folder_id_); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_field("max_id", max_id_);
    s.store_field("still_unread_count", still_unread_count_);
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

const std::int32_t updateReadHistoryOutbox::ID;

object_ptr<Update> updateReadHistoryOutbox::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadHistoryOutbox>(p);
}

updateReadHistoryOutbox::updateReadHistoryOutbox(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , max_id_(TlFetchInt::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateReadHistoryOutbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadHistoryOutbox");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

const std::int32_t updateWebPage::ID;

object_ptr<Update> updateWebPage::fetch(TlBufferParser &p) {
  return make_tl_object<updateWebPage>(p);
}

updateWebPage::updateWebPage(TlBufferParser &p)
  : webpage_(TlFetchObject<WebPage>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebPage");
    s.store_object_field("webpage", static_cast<const BaseObject *>(webpage_.get()));
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateReadMessagesContents::updateReadMessagesContents()
  : flags_()
  , messages_()
  , pts_()
  , pts_count_()
  , date_()
{}

const std::int32_t updateReadMessagesContents::ID;

object_ptr<Update> updateReadMessagesContents::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateReadMessagesContents> res = make_tl_object<updateReadMessagesContents>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateReadMessagesContents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadMessagesContents");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    if (var0 & 1) { s.store_field("date", date_); }
    s.store_class_end();
  }
}

updateChannelTooLong::updateChannelTooLong()
  : flags_()
  , channel_id_()
  , pts_()
{}

updateChannelTooLong::updateChannelTooLong(int32 flags_, int64 channel_id_, int32 pts_)
  : flags_(flags_)
  , channel_id_(channel_id_)
  , pts_(pts_)
{}

const std::int32_t updateChannelTooLong::ID;

object_ptr<Update> updateChannelTooLong::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateChannelTooLong> res = make_tl_object<updateChannelTooLong>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->pts_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateChannelTooLong::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelTooLong");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("channel_id", channel_id_);
    if (var0 & 1) { s.store_field("pts", pts_); }
    s.store_class_end();
  }
}

const std::int32_t updateChannel::ID;

object_ptr<Update> updateChannel::fetch(TlBufferParser &p) {
  return make_tl_object<updateChannel>(p);
}

updateChannel::updateChannel(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
{}

void updateChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannel");
    s.store_field("channel_id", channel_id_);
    s.store_class_end();
  }
}

const std::int32_t updateNewChannelMessage::ID;

object_ptr<Update> updateNewChannelMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewChannelMessage>(p);
}

updateNewChannelMessage::updateNewChannelMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateNewChannelMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewChannelMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateReadChannelInbox::updateReadChannelInbox()
  : flags_()
  , folder_id_()
  , channel_id_()
  , max_id_()
  , still_unread_count_()
  , pts_()
{}

const std::int32_t updateReadChannelInbox::ID;

object_ptr<Update> updateReadChannelInbox::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateReadChannelInbox> res = make_tl_object<updateReadChannelInbox>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->folder_id_ = TlFetchInt::parse(p); }
  res->channel_id_ = TlFetchLong::parse(p);
  res->max_id_ = TlFetchInt::parse(p);
  res->still_unread_count_ = TlFetchInt::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateReadChannelInbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadChannelInbox");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("folder_id", folder_id_); }
    s.store_field("channel_id", channel_id_);
    s.store_field("max_id", max_id_);
    s.store_field("still_unread_count", still_unread_count_);
    s.store_field("pts", pts_);
    s.store_class_end();
  }
}

const std::int32_t updateDeleteChannelMessages::ID;

object_ptr<Update> updateDeleteChannelMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateDeleteChannelMessages>(p);
}

updateDeleteChannelMessages::updateDeleteChannelMessages(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateDeleteChannelMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteChannelMessages");
    s.store_field("channel_id", channel_id_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

const std::int32_t updateChannelMessageViews::ID;

object_ptr<Update> updateChannelMessageViews::fetch(TlBufferParser &p) {
  return make_tl_object<updateChannelMessageViews>(p);
}

updateChannelMessageViews::updateChannelMessageViews(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , id_(TlFetchInt::parse(p))
  , views_(TlFetchInt::parse(p))
{}

void updateChannelMessageViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelMessageViews");
    s.store_field("channel_id", channel_id_);
    s.store_field("id", id_);
    s.store_field("views", views_);
    s.store_class_end();
  }
}

const std::int32_t updateChatParticipantAdmin::ID;

object_ptr<Update> updateChatParticipantAdmin::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatParticipantAdmin>(p);
}

updateChatParticipantAdmin::updateChatParticipantAdmin(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , is_admin_(TlFetchBool::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void updateChatParticipantAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatParticipantAdmin");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("is_admin", is_admin_);
    s.store_field("version", version_);
    s.store_class_end();
  }
}

const std::int32_t updateNewStickerSet::ID;

object_ptr<Update> updateNewStickerSet::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewStickerSet>(p);
}

updateNewStickerSet::updateNewStickerSet(TlBufferParser &p)
  : stickerset_(TlFetchObject<messages_StickerSet>::parse(p))
{}

void updateNewStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewStickerSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_class_end();
  }
}

updateStickerSetsOrder::updateStickerSetsOrder()
  : flags_()
  , masks_()
  , emojis_()
  , order_()
{}

const std::int32_t updateStickerSetsOrder::ID;

object_ptr<Update> updateStickerSetsOrder::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateStickerSetsOrder> res = make_tl_object<updateStickerSetsOrder>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->masks_ = (var0 & 1) != 0;
  res->emojis_ = (var0 & 2) != 0;
  res->order_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateStickerSetsOrder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStickerSetsOrder");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (masks_ << 0) | (emojis_ << 1)));
    if (var0 & 1) { s.store_field("masks", true); }
    if (var0 & 2) { s.store_field("emojis", true); }
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

updateStickerSets::updateStickerSets()
  : flags_()
  , masks_()
  , emojis_()
{}

const std::int32_t updateStickerSets::ID;

object_ptr<Update> updateStickerSets::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateStickerSets> res = make_tl_object<updateStickerSets>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->masks_ = (var0 & 1) != 0;
  res->emojis_ = (var0 & 2) != 0;
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStickerSets");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (masks_ << 0) | (emojis_ << 1)));
    if (var0 & 1) { s.store_field("masks", true); }
    if (var0 & 2) { s.store_field("emojis", true); }
    s.store_class_end();
  }
}

const std::int32_t updateSavedGifs::ID;

object_ptr<Update> updateSavedGifs::fetch(TlBufferParser &p) {
  return make_tl_object<updateSavedGifs>();
}

void updateSavedGifs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedGifs");
    s.store_class_end();
  }
}

updateBotInlineQuery::updateBotInlineQuery()
  : flags_()
  , query_id_()
  , user_id_()
  , query_()
  , geo_()
  , peer_type_()
  , offset_()
{}

const std::int32_t updateBotInlineQuery::ID;

object_ptr<Update> updateBotInlineQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotInlineQuery> res = make_tl_object<updateBotInlineQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->query_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->geo_ = TlFetchObject<GeoPoint>::parse(p); }
  if (var0 & 2) { res->peer_type_ = TlFetchObject<InlineQueryPeerType>::parse(p); }
  res->offset_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotInlineQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotInlineQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    s.store_field("query", query_);
    if (var0 & 1) { s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get())); }
    if (var0 & 2) { s.store_object_field("peer_type", static_cast<const BaseObject *>(peer_type_.get())); }
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

updateBotInlineSend::updateBotInlineSend()
  : flags_()
  , user_id_()
  , query_()
  , geo_()
  , id_()
  , msg_id_()
{}

const std::int32_t updateBotInlineSend::ID;

object_ptr<Update> updateBotInlineSend::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotInlineSend> res = make_tl_object<updateBotInlineSend>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  res->query_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->geo_ = TlFetchObject<GeoPoint>::parse(p); }
  res->id_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->msg_id_ = TlFetchObject<InputBotInlineMessageID>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotInlineSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotInlineSend");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("user_id", user_id_);
    s.store_field("query", query_);
    if (var0 & 1) { s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get())); }
    s.store_field("id", id_);
    if (var0 & 2) { s.store_object_field("msg_id", static_cast<const BaseObject *>(msg_id_.get())); }
    s.store_class_end();
  }
}

updateEditChannelMessage::updateEditChannelMessage(object_ptr<Message> &&message_, int32 pts_, int32 pts_count_)
  : message_(std::move(message_))
  , pts_(pts_)
  , pts_count_(pts_count_)
{}

const std::int32_t updateEditChannelMessage::ID;

object_ptr<Update> updateEditChannelMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateEditChannelMessage>(p);
}

updateEditChannelMessage::updateEditChannelMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateEditChannelMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEditChannelMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateBotCallbackQuery::updateBotCallbackQuery()
  : flags_()
  , query_id_()
  , user_id_()
  , peer_()
  , msg_id_()
  , chat_instance_()
  , data_()
  , game_short_name_()
{}

const std::int32_t updateBotCallbackQuery::ID;

object_ptr<Update> updateBotCallbackQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotCallbackQuery> res = make_tl_object<updateBotCallbackQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->msg_id_ = TlFetchInt::parse(p);
  res->chat_instance_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->data_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 2) { res->game_short_name_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotCallbackQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("chat_instance", chat_instance_);
    if (var0 & 1) { s.store_bytes_field("data", data_); }
    if (var0 & 2) { s.store_field("game_short_name", game_short_name_); }
    s.store_class_end();
  }
}

const std::int32_t updateEditMessage::ID;

object_ptr<Update> updateEditMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateEditMessage>(p);
}

updateEditMessage::updateEditMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateEditMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEditMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateInlineBotCallbackQuery::updateInlineBotCallbackQuery()
  : flags_()
  , query_id_()
  , user_id_()
  , msg_id_()
  , chat_instance_()
  , data_()
  , game_short_name_()
{}

const std::int32_t updateInlineBotCallbackQuery::ID;

object_ptr<Update> updateInlineBotCallbackQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateInlineBotCallbackQuery> res = make_tl_object<updateInlineBotCallbackQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->msg_id_ = TlFetchObject<InputBotInlineMessageID>::parse(p);
  res->chat_instance_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->data_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 2) { res->game_short_name_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateInlineBotCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateInlineBotCallbackQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    s.store_object_field("msg_id", static_cast<const BaseObject *>(msg_id_.get()));
    s.store_field("chat_instance", chat_instance_);
    if (var0 & 1) { s.store_bytes_field("data", data_); }
    if (var0 & 2) { s.store_field("game_short_name", game_short_name_); }
    s.store_class_end();
  }
}

const std::int32_t updateReadChannelOutbox::ID;

object_ptr<Update> updateReadChannelOutbox::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadChannelOutbox>(p);
}

updateReadChannelOutbox::updateReadChannelOutbox(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , max_id_(TlFetchInt::parse(p))
{}

void updateReadChannelOutbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadChannelOutbox");
    s.store_field("channel_id", channel_id_);
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

updateDraftMessage::updateDraftMessage()
  : flags_()
  , peer_()
  , top_msg_id_()
  , saved_peer_id_()
  , draft_()
{}

const std::int32_t updateDraftMessage::ID;

object_ptr<Update> updateDraftMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateDraftMessage> res = make_tl_object<updateDraftMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 1) { res->top_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->saved_peer_id_ = TlFetchObject<Peer>::parse(p); }
  res->draft_ = TlFetchObject<DraftMessage>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateDraftMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDraftMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_object_field("draft", static_cast<const BaseObject *>(draft_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateReadFeaturedStickers::ID;

object_ptr<Update> updateReadFeaturedStickers::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadFeaturedStickers>();
}

void updateReadFeaturedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadFeaturedStickers");
    s.store_class_end();
  }
}

const std::int32_t updateRecentStickers::ID;

object_ptr<Update> updateRecentStickers::fetch(TlBufferParser &p) {
  return make_tl_object<updateRecentStickers>();
}

void updateRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateRecentStickers");
    s.store_class_end();
  }
}

const std::int32_t updateConfig::ID;

object_ptr<Update> updateConfig::fetch(TlBufferParser &p) {
  return make_tl_object<updateConfig>();
}

void updateConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateConfig");
    s.store_class_end();
  }
}

const std::int32_t updatePtsChanged::ID;

object_ptr<Update> updatePtsChanged::fetch(TlBufferParser &p) {
  return make_tl_object<updatePtsChanged>();
}

void updatePtsChanged::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePtsChanged");
    s.store_class_end();
  }
}

const std::int32_t updateChannelWebPage::ID;

object_ptr<Update> updateChannelWebPage::fetch(TlBufferParser &p) {
  return make_tl_object<updateChannelWebPage>(p);
}

updateChannelWebPage::updateChannelWebPage(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , webpage_(TlFetchObject<WebPage>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateChannelWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelWebPage");
    s.store_field("channel_id", channel_id_);
    s.store_object_field("webpage", static_cast<const BaseObject *>(webpage_.get()));
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updateDialogPinned::updateDialogPinned()
  : flags_()
  , pinned_()
  , folder_id_()
  , peer_()
{}

const std::int32_t updateDialogPinned::ID;

object_ptr<Update> updateDialogPinned::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateDialogPinned> res = make_tl_object<updateDialogPinned>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 1) != 0;
  if (var0 & 2) { res->folder_id_ = TlFetchInt::parse(p); }
  res->peer_ = TlFetchObject<DialogPeer>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateDialogPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDialogPinned");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    if (var0 & 2) { s.store_field("folder_id", folder_id_); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

updatePinnedDialogs::updatePinnedDialogs()
  : flags_()
  , folder_id_()
  , order_()
{}

const std::int32_t updatePinnedDialogs::ID;

object_ptr<Update> updatePinnedDialogs::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePinnedDialogs> res = make_tl_object<updatePinnedDialogs>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 2) { res->folder_id_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->order_ = TlFetchBoxed<TlFetchVector<TlFetchObject<DialogPeer>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePinnedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePinnedDialogs");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 2) { s.store_field("folder_id", folder_id_); }
    if (var0 & 1) { { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t updateBotWebhookJSON::ID;

object_ptr<Update> updateBotWebhookJSON::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotWebhookJSON>(p);
}

updateBotWebhookJSON::updateBotWebhookJSON(TlBufferParser &p)
  : data_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
{}

void updateBotWebhookJSON::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotWebhookJSON");
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateBotWebhookJSONQuery::ID;

object_ptr<Update> updateBotWebhookJSONQuery::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotWebhookJSONQuery>(p);
}

updateBotWebhookJSONQuery::updateBotWebhookJSONQuery(TlBufferParser &p)
  : query_id_(TlFetchLong::parse(p))
  , data_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
  , timeout_(TlFetchInt::parse(p))
{}

void updateBotWebhookJSONQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotWebhookJSONQuery");
    s.store_field("query_id", query_id_);
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_field("timeout", timeout_);
    s.store_class_end();
  }
}

const std::int32_t updateBotShippingQuery::ID;

object_ptr<Update> updateBotShippingQuery::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotShippingQuery>(p);
}

updateBotShippingQuery::updateBotShippingQuery(TlBufferParser &p)
  : query_id_(TlFetchLong::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , payload_(TlFetchBytes<bytes>::parse(p))
  , shipping_address_(TlFetchBoxed<TlFetchObject<postAddress>, 512535275>::parse(p))
{}

void updateBotShippingQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotShippingQuery");
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    s.store_bytes_field("payload", payload_);
    s.store_object_field("shipping_address", static_cast<const BaseObject *>(shipping_address_.get()));
    s.store_class_end();
  }
}

updateBotPrecheckoutQuery::updateBotPrecheckoutQuery()
  : flags_()
  , query_id_()
  , user_id_()
  , payload_()
  , info_()
  , shipping_option_id_()
  , currency_()
  , total_amount_()
{}

const std::int32_t updateBotPrecheckoutQuery::ID;

object_ptr<Update> updateBotPrecheckoutQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotPrecheckoutQuery> res = make_tl_object<updateBotPrecheckoutQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->payload_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 1) { res->info_ = TlFetchBoxed<TlFetchObject<paymentRequestedInfo>, -1868808300>::parse(p); }
  if (var0 & 2) { res->shipping_option_id_ = TlFetchString<string>::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotPrecheckoutQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotPrecheckoutQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    s.store_bytes_field("payload", payload_);
    if (var0 & 1) { s.store_object_field("info", static_cast<const BaseObject *>(info_.get())); }
    if (var0 & 2) { s.store_field("shipping_option_id", shipping_option_id_); }
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_class_end();
  }
}

const std::int32_t updatePhoneCall::ID;

object_ptr<Update> updatePhoneCall::fetch(TlBufferParser &p) {
  return make_tl_object<updatePhoneCall>(p);
}

updatePhoneCall::updatePhoneCall(TlBufferParser &p)
  : phone_call_(TlFetchObject<PhoneCall>::parse(p))
{}

void updatePhoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePhoneCall");
    s.store_object_field("phone_call", static_cast<const BaseObject *>(phone_call_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateLangPackTooLong::ID;

object_ptr<Update> updateLangPackTooLong::fetch(TlBufferParser &p) {
  return make_tl_object<updateLangPackTooLong>(p);
}

updateLangPackTooLong::updateLangPackTooLong(TlBufferParser &p)
  : lang_code_(TlFetchString<string>::parse(p))
{}

void updateLangPackTooLong::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateLangPackTooLong");
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

const std::int32_t updateLangPack::ID;

object_ptr<Update> updateLangPack::fetch(TlBufferParser &p) {
  return make_tl_object<updateLangPack>(p);
}

updateLangPack::updateLangPack(TlBufferParser &p)
  : difference_(TlFetchBoxed<TlFetchObject<langPackDifference>, -209337866>::parse(p))
{}

void updateLangPack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateLangPack");
    s.store_object_field("difference", static_cast<const BaseObject *>(difference_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateFavedStickers::ID;

object_ptr<Update> updateFavedStickers::fetch(TlBufferParser &p) {
  return make_tl_object<updateFavedStickers>();
}

void updateFavedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFavedStickers");
    s.store_class_end();
  }
}

updateChannelReadMessagesContents::updateChannelReadMessagesContents()
  : flags_()
  , channel_id_()
  , top_msg_id_()
  , saved_peer_id_()
  , messages_()
{}

const std::int32_t updateChannelReadMessagesContents::ID;

object_ptr<Update> updateChannelReadMessagesContents::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateChannelReadMessagesContents> res = make_tl_object<updateChannelReadMessagesContents>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->top_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->saved_peer_id_ = TlFetchObject<Peer>::parse(p); }
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateChannelReadMessagesContents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelReadMessagesContents");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("channel_id", channel_id_);
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateContactsReset::ID;

object_ptr<Update> updateContactsReset::fetch(TlBufferParser &p) {
  return make_tl_object<updateContactsReset>();
}

void updateContactsReset::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateContactsReset");
    s.store_class_end();
  }
}

const std::int32_t updateChannelAvailableMessages::ID;

object_ptr<Update> updateChannelAvailableMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateChannelAvailableMessages>(p);
}

updateChannelAvailableMessages::updateChannelAvailableMessages(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , available_min_id_(TlFetchInt::parse(p))
{}

void updateChannelAvailableMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelAvailableMessages");
    s.store_field("channel_id", channel_id_);
    s.store_field("available_min_id", available_min_id_);
    s.store_class_end();
  }
}

updateDialogUnreadMark::updateDialogUnreadMark()
  : flags_()
  , unread_()
  , peer_()
  , saved_peer_id_()
{}

const std::int32_t updateDialogUnreadMark::ID;

object_ptr<Update> updateDialogUnreadMark::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateDialogUnreadMark> res = make_tl_object<updateDialogUnreadMark>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->unread_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<DialogPeer>::parse(p);
  if (var0 & 2) { res->saved_peer_id_ = TlFetchObject<Peer>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateDialogUnreadMark::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDialogUnreadMark");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (unread_ << 0)));
    if (var0 & 1) { s.store_field("unread", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_class_end();
  }
}

updateMessagePoll::updateMessagePoll()
  : flags_()
  , peer_()
  , msg_id_()
  , top_msg_id_()
  , poll_id_()
  , poll_()
  , results_()
{}

const std::int32_t updateMessagePoll::ID;

object_ptr<Update> updateMessagePoll::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateMessagePoll> res = make_tl_object<updateMessagePoll>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 2) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 2) { res->msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->top_msg_id_ = TlFetchInt::parse(p); }
  res->poll_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->poll_ = TlFetchBoxed<TlFetchObject<poll>, -1203610647>::parse(p); }
  res->results_ = TlFetchBoxed<TlFetchObject<pollResults>, -1166298786>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateMessagePoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessagePoll");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 2) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 2) { s.store_field("msg_id", msg_id_); }
    if (var0 & 4) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_field("poll_id", poll_id_);
    if (var0 & 1) { s.store_object_field("poll", static_cast<const BaseObject *>(poll_.get())); }
    s.store_object_field("results", static_cast<const BaseObject *>(results_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateChatDefaultBannedRights::ID;

object_ptr<Update> updateChatDefaultBannedRights::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatDefaultBannedRights>(p);
}

updateChatDefaultBannedRights::updateChatDefaultBannedRights(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , default_banned_rights_(TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void updateChatDefaultBannedRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatDefaultBannedRights");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("default_banned_rights", static_cast<const BaseObject *>(default_banned_rights_.get()));
    s.store_field("version", version_);
    s.store_class_end();
  }
}

const std::int32_t updateFolderPeers::ID;

object_ptr<Update> updateFolderPeers::fetch(TlBufferParser &p) {
  return make_tl_object<updateFolderPeers>(p);
}

updateFolderPeers::updateFolderPeers(TlBufferParser &p)
  : folder_peers_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<folderPeer>, -373643672>>, 481674261>::parse(p))
  , pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void updateFolderPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateFolderPeers");
    { s.store_vector_begin("folder_peers", folder_peers_.size()); for (const auto &_value : folder_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

const std::int32_t updatePeerSettings::ID;

object_ptr<Update> updatePeerSettings::fetch(TlBufferParser &p) {
  return make_tl_object<updatePeerSettings>(p);
}

updatePeerSettings::updatePeerSettings(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , settings_(TlFetchBoxed<TlFetchObject<peerSettings>, -193510921>::parse(p))
{}

void updatePeerSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePeerSettings");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

const std::int32_t updatePeerLocated::ID;

object_ptr<Update> updatePeerLocated::fetch(TlBufferParser &p) {
  return make_tl_object<updatePeerLocated>(p);
}

updatePeerLocated::updatePeerLocated(TlBufferParser &p)
  : peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<PeerLocated>>, 481674261>::parse(p))
{}

void updatePeerLocated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePeerLocated");
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateNewScheduledMessage::ID;

object_ptr<Update> updateNewScheduledMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewScheduledMessage>(p);
}

updateNewScheduledMessage::updateNewScheduledMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void updateNewScheduledMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewScheduledMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

updateDeleteScheduledMessages::updateDeleteScheduledMessages()
  : flags_()
  , peer_()
  , messages_()
  , sent_messages_()
{}

const std::int32_t updateDeleteScheduledMessages::ID;

object_ptr<Update> updateDeleteScheduledMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateDeleteScheduledMessages> res = make_tl_object<updateDeleteScheduledMessages>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  if (var0 & 1) { res->sent_messages_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateDeleteScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteScheduledMessages");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    if (var0 & 1) { { s.store_vector_begin("sent_messages", sent_messages_.size()); for (const auto &_value : sent_messages_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t updateTheme::ID;

object_ptr<Update> updateTheme::fetch(TlBufferParser &p) {
  return make_tl_object<updateTheme>(p);
}

updateTheme::updateTheme(TlBufferParser &p)
  : theme_(TlFetchBoxed<TlFetchObject<theme>, -1609668650>::parse(p))
{}

void updateTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTheme");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateGeoLiveViewed::ID;

object_ptr<Update> updateGeoLiveViewed::fetch(TlBufferParser &p) {
  return make_tl_object<updateGeoLiveViewed>(p);
}

updateGeoLiveViewed::updateGeoLiveViewed(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
{}

void updateGeoLiveViewed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGeoLiveViewed");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

const std::int32_t updateLoginToken::ID;

object_ptr<Update> updateLoginToken::fetch(TlBufferParser &p) {
  return make_tl_object<updateLoginToken>();
}

void updateLoginToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateLoginToken");
    s.store_class_end();
  }
}

const std::int32_t updateMessagePollVote::ID;

object_ptr<Update> updateMessagePollVote::fetch(TlBufferParser &p) {
  return make_tl_object<updateMessagePollVote>(p);
}

updateMessagePollVote::updateMessagePollVote(TlBufferParser &p)
  : poll_id_(TlFetchLong::parse(p))
  , peer_(TlFetchObject<Peer>::parse(p))
  , options_(TlFetchBoxed<TlFetchVector<TlFetchBytes<bytes>>, 481674261>::parse(p))
  , positions_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateMessagePollVote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessagePollVote");
    s.store_field("poll_id", poll_id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateDialogFilter::updateDialogFilter()
  : flags_()
  , id_()
  , filter_()
{}

const std::int32_t updateDialogFilter::ID;

object_ptr<Update> updateDialogFilter::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateDialogFilter> res = make_tl_object<updateDialogFilter>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->filter_ = TlFetchObject<DialogFilter>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateDialogFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDialogFilter");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get())); }
    s.store_class_end();
  }
}

const std::int32_t updateDialogFilterOrder::ID;

object_ptr<Update> updateDialogFilterOrder::fetch(TlBufferParser &p) {
  return make_tl_object<updateDialogFilterOrder>(p);
}

updateDialogFilterOrder::updateDialogFilterOrder(TlBufferParser &p)
  : order_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void updateDialogFilterOrder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDialogFilterOrder");
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateDialogFilters::ID;

object_ptr<Update> updateDialogFilters::fetch(TlBufferParser &p) {
  return make_tl_object<updateDialogFilters>();
}

void updateDialogFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDialogFilters");
    s.store_class_end();
  }
}

const std::int32_t updatePhoneCallSignalingData::ID;

object_ptr<Update> updatePhoneCallSignalingData::fetch(TlBufferParser &p) {
  return make_tl_object<updatePhoneCallSignalingData>(p);
}

updatePhoneCallSignalingData::updatePhoneCallSignalingData(TlBufferParser &p)
  : phone_call_id_(TlFetchLong::parse(p))
  , data_(TlFetchBytes<bytes>::parse(p))
{}

void updatePhoneCallSignalingData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePhoneCallSignalingData");
    s.store_field("phone_call_id", phone_call_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

const std::int32_t updateChannelMessageForwards::ID;

object_ptr<Update> updateChannelMessageForwards::fetch(TlBufferParser &p) {
  return make_tl_object<updateChannelMessageForwards>(p);
}

updateChannelMessageForwards::updateChannelMessageForwards(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , id_(TlFetchInt::parse(p))
  , forwards_(TlFetchInt::parse(p))
{}

void updateChannelMessageForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelMessageForwards");
    s.store_field("channel_id", channel_id_);
    s.store_field("id", id_);
    s.store_field("forwards", forwards_);
    s.store_class_end();
  }
}

updateReadChannelDiscussionInbox::updateReadChannelDiscussionInbox()
  : flags_()
  , channel_id_()
  , top_msg_id_()
  , read_max_id_()
  , broadcast_id_()
  , broadcast_post_()
{}

const std::int32_t updateReadChannelDiscussionInbox::ID;

object_ptr<Update> updateReadChannelDiscussionInbox::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateReadChannelDiscussionInbox> res = make_tl_object<updateReadChannelDiscussionInbox>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_id_ = TlFetchLong::parse(p);
  res->top_msg_id_ = TlFetchInt::parse(p);
  res->read_max_id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->broadcast_id_ = TlFetchLong::parse(p); }
  if (var0 & 1) { res->broadcast_post_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateReadChannelDiscussionInbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadChannelDiscussionInbox");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("channel_id", channel_id_);
    s.store_field("top_msg_id", top_msg_id_);
    s.store_field("read_max_id", read_max_id_);
    if (var0 & 1) { s.store_field("broadcast_id", broadcast_id_); }
    if (var0 & 1) { s.store_field("broadcast_post", broadcast_post_); }
    s.store_class_end();
  }
}

const std::int32_t updateReadChannelDiscussionOutbox::ID;

object_ptr<Update> updateReadChannelDiscussionOutbox::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadChannelDiscussionOutbox>(p);
}

updateReadChannelDiscussionOutbox::updateReadChannelDiscussionOutbox(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , top_msg_id_(TlFetchInt::parse(p))
  , read_max_id_(TlFetchInt::parse(p))
{}

void updateReadChannelDiscussionOutbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadChannelDiscussionOutbox");
    s.store_field("channel_id", channel_id_);
    s.store_field("top_msg_id", top_msg_id_);
    s.store_field("read_max_id", read_max_id_);
    s.store_class_end();
  }
}

updatePeerBlocked::updatePeerBlocked()
  : flags_()
  , blocked_()
  , blocked_my_stories_from_()
  , peer_id_()
{}

const std::int32_t updatePeerBlocked::ID;

object_ptr<Update> updatePeerBlocked::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePeerBlocked> res = make_tl_object<updatePeerBlocked>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->blocked_ = (var0 & 1) != 0;
  res->blocked_my_stories_from_ = (var0 & 2) != 0;
  res->peer_id_ = TlFetchObject<Peer>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePeerBlocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePeerBlocked");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (blocked_ << 0) | (blocked_my_stories_from_ << 1)));
    if (var0 & 1) { s.store_field("blocked", true); }
    if (var0 & 2) { s.store_field("blocked_my_stories_from", true); }
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    s.store_class_end();
  }
}

updateChannelUserTyping::updateChannelUserTyping()
  : flags_()
  , channel_id_()
  , top_msg_id_()
  , from_id_()
  , action_()
{}

const std::int32_t updateChannelUserTyping::ID;

object_ptr<Update> updateChannelUserTyping::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateChannelUserTyping> res = make_tl_object<updateChannelUserTyping>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->top_msg_id_ = TlFetchInt::parse(p); }
  res->from_id_ = TlFetchObject<Peer>::parse(p);
  res->action_ = TlFetchObject<SendMessageAction>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateChannelUserTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelUserTyping");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("channel_id", channel_id_);
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

updatePinnedMessages::updatePinnedMessages()
  : flags_()
  , pinned_()
  , peer_()
  , messages_()
  , pts_()
  , pts_count_()
{}

const std::int32_t updatePinnedMessages::ID;

object_ptr<Update> updatePinnedMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePinnedMessages> res = make_tl_object<updatePinnedMessages>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePinnedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePinnedMessages");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

updatePinnedChannelMessages::updatePinnedChannelMessages()
  : flags_()
  , pinned_()
  , channel_id_()
  , messages_()
  , pts_()
  , pts_count_()
{}

const std::int32_t updatePinnedChannelMessages::ID;

object_ptr<Update> updatePinnedChannelMessages::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePinnedChannelMessages> res = make_tl_object<updatePinnedChannelMessages>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 1) != 0;
  res->channel_id_ = TlFetchLong::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
  res->pts_ = TlFetchInt::parse(p);
  res->pts_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePinnedChannelMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePinnedChannelMessages");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    s.store_field("channel_id", channel_id_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

const std::int32_t updateChat::ID;

object_ptr<Update> updateChat::fetch(TlBufferParser &p) {
  return make_tl_object<updateChat>(p);
}

updateChat::updateChat(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
{}

void updateChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

const std::int32_t updateGroupCallParticipants::ID;

object_ptr<Update> updateGroupCallParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<updateGroupCallParticipants>(p);
}

updateGroupCallParticipants::updateGroupCallParticipants(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , participants_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<groupCallParticipant>, 708691884>>, 481674261>::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void updateGroupCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallParticipants");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("participants", participants_.size()); for (const auto &_value : participants_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("version", version_);
    s.store_class_end();
  }
}

updateGroupCall::updateGroupCall()
  : flags_()
  , live_story_()
  , peer_()
  , call_()
{}

const std::int32_t updateGroupCall::ID;

object_ptr<Update> updateGroupCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateGroupCall> res = make_tl_object<updateGroupCall>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->live_story_ = (var0 & 4) != 0;
  if (var0 & 2) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  res->call_ = TlFetchObject<GroupCall>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCall");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (live_story_ << 2)));
    if (var0 & 4) { s.store_field("live_story", true); }
    if (var0 & 2) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

updatePeerHistoryTTL::updatePeerHistoryTTL()
  : flags_()
  , peer_()
  , ttl_period_()
{}

const std::int32_t updatePeerHistoryTTL::ID;

object_ptr<Update> updatePeerHistoryTTL::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePeerHistoryTTL> res = make_tl_object<updatePeerHistoryTTL>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 1) { res->ttl_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePeerHistoryTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePeerHistoryTTL");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

updateChatParticipant::updateChatParticipant()
  : flags_()
  , chat_id_()
  , date_()
  , actor_id_()
  , user_id_()
  , prev_participant_()
  , new_participant_()
  , invite_()
  , qts_()
{}

const std::int32_t updateChatParticipant::ID;

object_ptr<Update> updateChatParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateChatParticipant> res = make_tl_object<updateChatParticipant>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->chat_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->actor_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->prev_participant_ = TlFetchObject<ChatParticipant>::parse(p); }
  if (var0 & 2) { res->new_participant_ = TlFetchObject<ChatParticipant>::parse(p); }
  if (var0 & 4) { res->invite_ = TlFetchObject<ExportedChatInvite>::parse(p); }
  res->qts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateChatParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatParticipant");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("chat_id", chat_id_);
    s.store_field("date", date_);
    s.store_field("actor_id", actor_id_);
    s.store_field("user_id", user_id_);
    if (var0 & 1) { s.store_object_field("prev_participant", static_cast<const BaseObject *>(prev_participant_.get())); }
    if (var0 & 2) { s.store_object_field("new_participant", static_cast<const BaseObject *>(new_participant_.get())); }
    if (var0 & 4) { s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get())); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateChannelParticipant::updateChannelParticipant()
  : flags_()
  , via_chatlist_()
  , channel_id_()
  , date_()
  , actor_id_()
  , user_id_()
  , prev_participant_()
  , new_participant_()
  , invite_()
  , qts_()
{}

const std::int32_t updateChannelParticipant::ID;

object_ptr<Update> updateChannelParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateChannelParticipant> res = make_tl_object<updateChannelParticipant>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->via_chatlist_ = (var0 & 8) != 0;
  res->channel_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->actor_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->prev_participant_ = TlFetchObject<ChannelParticipant>::parse(p); }
  if (var0 & 2) { res->new_participant_ = TlFetchObject<ChannelParticipant>::parse(p); }
  if (var0 & 4) { res->invite_ = TlFetchObject<ExportedChatInvite>::parse(p); }
  res->qts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateChannelParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelParticipant");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (via_chatlist_ << 3)));
    if (var0 & 8) { s.store_field("via_chatlist", true); }
    s.store_field("channel_id", channel_id_);
    s.store_field("date", date_);
    s.store_field("actor_id", actor_id_);
    s.store_field("user_id", user_id_);
    if (var0 & 1) { s.store_object_field("prev_participant", static_cast<const BaseObject *>(prev_participant_.get())); }
    if (var0 & 2) { s.store_object_field("new_participant", static_cast<const BaseObject *>(new_participant_.get())); }
    if (var0 & 4) { s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get())); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateBotStopped::ID;

object_ptr<Update> updateBotStopped::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotStopped>(p);
}

updateBotStopped::updateBotStopped(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
  , stopped_(TlFetchBool::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotStopped::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotStopped");
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    s.store_field("stopped", stopped_);
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateGroupCallConnection::updateGroupCallConnection()
  : flags_()
  , presentation_()
  , params_()
{}

const std::int32_t updateGroupCallConnection::ID;

object_ptr<Update> updateGroupCallConnection::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateGroupCallConnection> res = make_tl_object<updateGroupCallConnection>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->presentation_ = (var0 & 1) != 0;
  res->params_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateGroupCallConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallConnection");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (presentation_ << 0)));
    if (var0 & 1) { s.store_field("presentation", true); }
    s.store_object_field("params", static_cast<const BaseObject *>(params_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateBotCommands::ID;

object_ptr<Update> updateBotCommands::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotCommands>(p);
}

updateBotCommands::updateBotCommands(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , bot_id_(TlFetchLong::parse(p))
  , commands_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botCommand>, -1032140601>>, 481674261>::parse(p))
{}

void updateBotCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotCommands");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("bot_id", bot_id_);
    { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updatePendingJoinRequests::ID;

object_ptr<Update> updatePendingJoinRequests::fetch(TlBufferParser &p) {
  return make_tl_object<updatePendingJoinRequests>(p);
}

updatePendingJoinRequests::updatePendingJoinRequests(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , requests_pending_(TlFetchInt::parse(p))
  , recent_requesters_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void updatePendingJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePendingJoinRequests");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("requests_pending", requests_pending_);
    { s.store_vector_begin("recent_requesters", recent_requesters_.size()); for (const auto &_value : recent_requesters_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateBotChatInviteRequester::ID;

object_ptr<Update> updateBotChatInviteRequester::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotChatInviteRequester>(p);
}

updateBotChatInviteRequester::updateBotChatInviteRequester(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , date_(TlFetchInt::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , about_(TlFetchString<string>::parse(p))
  , invite_(TlFetchObject<ExportedChatInvite>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotChatInviteRequester::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotChatInviteRequester");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("date", date_);
    s.store_field("user_id", user_id_);
    s.store_field("about", about_);
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateMessageReactions::updateMessageReactions()
  : flags_()
  , peer_()
  , msg_id_()
  , top_msg_id_()
  , saved_peer_id_()
  , reactions_()
{}

const std::int32_t updateMessageReactions::ID;

object_ptr<Update> updateMessageReactions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateMessageReactions> res = make_tl_object<updateMessageReactions>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->msg_id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->top_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->saved_peer_id_ = TlFetchObject<Peer>::parse(p); }
  res->reactions_ = TlFetchBoxed<TlFetchObject<messageReactions>, 171155211>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageReactions");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_object_field("reactions", static_cast<const BaseObject *>(reactions_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateAttachMenuBots::ID;

object_ptr<Update> updateAttachMenuBots::fetch(TlBufferParser &p) {
  return make_tl_object<updateAttachMenuBots>();
}

void updateAttachMenuBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAttachMenuBots");
    s.store_class_end();
  }
}

const std::int32_t updateWebViewResultSent::ID;

object_ptr<Update> updateWebViewResultSent::fetch(TlBufferParser &p) {
  return make_tl_object<updateWebViewResultSent>(p);
}

updateWebViewResultSent::updateWebViewResultSent(TlBufferParser &p)
  : query_id_(TlFetchLong::parse(p))
{}

void updateWebViewResultSent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateWebViewResultSent");
    s.store_field("query_id", query_id_);
    s.store_class_end();
  }
}

const std::int32_t updateBotMenuButton::ID;

object_ptr<Update> updateBotMenuButton::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotMenuButton>(p);
}

updateBotMenuButton::updateBotMenuButton(TlBufferParser &p)
  : bot_id_(TlFetchLong::parse(p))
  , button_(TlFetchObject<BotMenuButton>::parse(p))
{}

void updateBotMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotMenuButton");
    s.store_field("bot_id", bot_id_);
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateSavedRingtones::ID;

object_ptr<Update> updateSavedRingtones::fetch(TlBufferParser &p) {
  return make_tl_object<updateSavedRingtones>();
}

void updateSavedRingtones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedRingtones");
    s.store_class_end();
  }
}

updateTranscribedAudio::updateTranscribedAudio()
  : flags_()
  , pending_()
  , peer_()
  , msg_id_()
  , transcription_id_()
  , text_()
{}

const std::int32_t updateTranscribedAudio::ID;

object_ptr<Update> updateTranscribedAudio::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateTranscribedAudio> res = make_tl_object<updateTranscribedAudio>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pending_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->msg_id_ = TlFetchInt::parse(p);
  res->transcription_id_ = TlFetchLong::parse(p);
  res->text_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateTranscribedAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateTranscribedAudio");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pending_ << 0)));
    if (var0 & 1) { s.store_field("pending", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("transcription_id", transcription_id_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

const std::int32_t updateReadFeaturedEmojiStickers::ID;

object_ptr<Update> updateReadFeaturedEmojiStickers::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadFeaturedEmojiStickers>();
}

void updateReadFeaturedEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadFeaturedEmojiStickers");
    s.store_class_end();
  }
}

const std::int32_t updateUserEmojiStatus::ID;

object_ptr<Update> updateUserEmojiStatus::fetch(TlBufferParser &p) {
  return make_tl_object<updateUserEmojiStatus>(p);
}

updateUserEmojiStatus::updateUserEmojiStatus(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , emoji_status_(TlFetchObject<EmojiStatus>::parse(p))
{}

void updateUserEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUserEmojiStatus");
    s.store_field("user_id", user_id_);
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateRecentEmojiStatuses::ID;

object_ptr<Update> updateRecentEmojiStatuses::fetch(TlBufferParser &p) {
  return make_tl_object<updateRecentEmojiStatuses>();
}

void updateRecentEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateRecentEmojiStatuses");
    s.store_class_end();
  }
}

const std::int32_t updateRecentReactions::ID;

object_ptr<Update> updateRecentReactions::fetch(TlBufferParser &p) {
  return make_tl_object<updateRecentReactions>();
}

void updateRecentReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateRecentReactions");
    s.store_class_end();
  }
}

updateMoveStickerSetToTop::updateMoveStickerSetToTop()
  : flags_()
  , masks_()
  , emojis_()
  , stickerset_()
{}

const std::int32_t updateMoveStickerSetToTop::ID;

object_ptr<Update> updateMoveStickerSetToTop::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateMoveStickerSetToTop> res = make_tl_object<updateMoveStickerSetToTop>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->masks_ = (var0 & 1) != 0;
  res->emojis_ = (var0 & 2) != 0;
  res->stickerset_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateMoveStickerSetToTop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMoveStickerSetToTop");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (masks_ << 0) | (emojis_ << 1)));
    if (var0 & 1) { s.store_field("masks", true); }
    if (var0 & 2) { s.store_field("emojis", true); }
    s.store_field("stickerset", stickerset_);
    s.store_class_end();
  }
}

const std::int32_t updateMessageExtendedMedia::ID;

object_ptr<Update> updateMessageExtendedMedia::fetch(TlBufferParser &p) {
  return make_tl_object<updateMessageExtendedMedia>(p);
}

updateMessageExtendedMedia::updateMessageExtendedMedia(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , extended_media_(TlFetchBoxed<TlFetchVector<TlFetchObject<MessageExtendedMedia>>, 481674261>::parse(p))
{}

void updateMessageExtendedMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMessageExtendedMedia");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    { s.store_vector_begin("extended_media", extended_media_.size()); for (const auto &_value : extended_media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateUser::ID;

object_ptr<Update> updateUser::fetch(TlBufferParser &p) {
  return make_tl_object<updateUser>(p);
}

updateUser::updateUser(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
{}

void updateUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateUser");
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

const std::int32_t updateAutoSaveSettings::ID;

object_ptr<Update> updateAutoSaveSettings::fetch(TlBufferParser &p) {
  return make_tl_object<updateAutoSaveSettings>();
}

void updateAutoSaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateAutoSaveSettings");
    s.store_class_end();
  }
}

const std::int32_t updateStory::ID;

object_ptr<Update> updateStory::fetch(TlBufferParser &p) {
  return make_tl_object<updateStory>(p);
}

updateStory::updateStory(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , story_(TlFetchObject<StoryItem>::parse(p))
{}

void updateStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateReadStories::ID;

object_ptr<Update> updateReadStories::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadStories>(p);
}

updateReadStories::updateReadStories(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , max_id_(TlFetchInt::parse(p))
{}

void updateReadStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadStories");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

const std::int32_t updateStoryID::ID;

object_ptr<Update> updateStoryID::fetch(TlBufferParser &p) {
  return make_tl_object<updateStoryID>(p);
}

updateStoryID::updateStoryID(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , random_id_(TlFetchLong::parse(p))
{}

void updateStoryID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoryID");
    s.store_field("id", id_);
    s.store_field("random_id", random_id_);
    s.store_class_end();
  }
}

const std::int32_t updateStoriesStealthMode::ID;

object_ptr<Update> updateStoriesStealthMode::fetch(TlBufferParser &p) {
  return make_tl_object<updateStoriesStealthMode>(p);
}

updateStoriesStealthMode::updateStoriesStealthMode(TlBufferParser &p)
  : stealth_mode_(TlFetchBoxed<TlFetchObject<storiesStealthMode>, 1898850301>::parse(p))
{}

void updateStoriesStealthMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStoriesStealthMode");
    s.store_object_field("stealth_mode", static_cast<const BaseObject *>(stealth_mode_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateSentStoryReaction::ID;

object_ptr<Update> updateSentStoryReaction::fetch(TlBufferParser &p) {
  return make_tl_object<updateSentStoryReaction>(p);
}

updateSentStoryReaction::updateSentStoryReaction(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , story_id_(TlFetchInt::parse(p))
  , reaction_(TlFetchObject<Reaction>::parse(p))
{}

void updateSentStoryReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSentStoryReaction");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("story_id", story_id_);
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateBotChatBoost::ID;

object_ptr<Update> updateBotChatBoost::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotChatBoost>(p);
}

updateBotChatBoost::updateBotChatBoost(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , boost_(TlFetchBoxed<TlFetchObject<boost>, 1262359766>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotChatBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotChatBoost");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("boost", static_cast<const BaseObject *>(boost_.get()));
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateChannelViewForumAsMessages::ID;

object_ptr<Update> updateChannelViewForumAsMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateChannelViewForumAsMessages>(p);
}

updateChannelViewForumAsMessages::updateChannelViewForumAsMessages(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , enabled_(TlFetchBool::parse(p))
{}

void updateChannelViewForumAsMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChannelViewForumAsMessages");
    s.store_field("channel_id", channel_id_);
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

updatePeerWallpaper::updatePeerWallpaper()
  : flags_()
  , wallpaper_overridden_()
  , peer_()
  , wallpaper_()
{}

const std::int32_t updatePeerWallpaper::ID;

object_ptr<Update> updatePeerWallpaper::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePeerWallpaper> res = make_tl_object<updatePeerWallpaper>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->wallpaper_overridden_ = (var0 & 2) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 1) { res->wallpaper_ = TlFetchObject<WallPaper>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePeerWallpaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePeerWallpaper");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (wallpaper_overridden_ << 1)));
    if (var0 & 2) { s.store_field("wallpaper_overridden", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get())); }
    s.store_class_end();
  }
}

const std::int32_t updateBotMessageReaction::ID;

object_ptr<Update> updateBotMessageReaction::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotMessageReaction>(p);
}

updateBotMessageReaction::updateBotMessageReaction(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , actor_(TlFetchObject<Peer>::parse(p))
  , old_reactions_(TlFetchBoxed<TlFetchVector<TlFetchObject<Reaction>>, 481674261>::parse(p))
  , new_reactions_(TlFetchBoxed<TlFetchVector<TlFetchObject<Reaction>>, 481674261>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotMessageReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotMessageReaction");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("date", date_);
    s.store_object_field("actor", static_cast<const BaseObject *>(actor_.get()));
    { s.store_vector_begin("old_reactions", old_reactions_.size()); for (const auto &_value : old_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("new_reactions", new_reactions_.size()); for (const auto &_value : new_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateBotMessageReactions::ID;

object_ptr<Update> updateBotMessageReactions::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotMessageReactions>(p);
}

updateBotMessageReactions::updateBotMessageReactions(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , reactions_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<reactionCount>, -1546531968>>, 481674261>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotMessageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotMessageReactions");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("date", date_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateSavedDialogPinned::updateSavedDialogPinned()
  : flags_()
  , pinned_()
  , peer_()
{}

const std::int32_t updateSavedDialogPinned::ID;

object_ptr<Update> updateSavedDialogPinned::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateSavedDialogPinned> res = make_tl_object<updateSavedDialogPinned>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<DialogPeer>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateSavedDialogPinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedDialogPinned");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

updatePinnedSavedDialogs::updatePinnedSavedDialogs()
  : flags_()
  , order_()
{}

const std::int32_t updatePinnedSavedDialogs::ID;

object_ptr<Update> updatePinnedSavedDialogs::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePinnedSavedDialogs> res = make_tl_object<updatePinnedSavedDialogs>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->order_ = TlFetchBoxed<TlFetchVector<TlFetchObject<DialogPeer>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePinnedSavedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePinnedSavedDialogs");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t updateSavedReactionTags::ID;

object_ptr<Update> updateSavedReactionTags::fetch(TlBufferParser &p) {
  return make_tl_object<updateSavedReactionTags>();
}

void updateSavedReactionTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSavedReactionTags");
    s.store_class_end();
  }
}

const std::int32_t updateSmsJob::ID;

object_ptr<Update> updateSmsJob::fetch(TlBufferParser &p) {
  return make_tl_object<updateSmsJob>(p);
}

updateSmsJob::updateSmsJob(TlBufferParser &p)
  : job_id_(TlFetchString<string>::parse(p))
{}

void updateSmsJob::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSmsJob");
    s.store_field("job_id", job_id_);
    s.store_class_end();
  }
}

const std::int32_t updateQuickReplies::ID;

object_ptr<Update> updateQuickReplies::fetch(TlBufferParser &p) {
  return make_tl_object<updateQuickReplies>(p);
}

updateQuickReplies::updateQuickReplies(TlBufferParser &p)
  : quick_replies_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<quickReply>, 110563371>>, 481674261>::parse(p))
{}

void updateQuickReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateQuickReplies");
    { s.store_vector_begin("quick_replies", quick_replies_.size()); for (const auto &_value : quick_replies_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateNewQuickReply::ID;

object_ptr<Update> updateNewQuickReply::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewQuickReply>(p);
}

updateNewQuickReply::updateNewQuickReply(TlBufferParser &p)
  : quick_reply_(TlFetchBoxed<TlFetchObject<quickReply>, 110563371>::parse(p))
{}

void updateNewQuickReply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewQuickReply");
    s.store_object_field("quick_reply", static_cast<const BaseObject *>(quick_reply_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateDeleteQuickReply::ID;

object_ptr<Update> updateDeleteQuickReply::fetch(TlBufferParser &p) {
  return make_tl_object<updateDeleteQuickReply>(p);
}

updateDeleteQuickReply::updateDeleteQuickReply(TlBufferParser &p)
  : shortcut_id_(TlFetchInt::parse(p))
{}

void updateDeleteQuickReply::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteQuickReply");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_class_end();
  }
}

const std::int32_t updateQuickReplyMessage::ID;

object_ptr<Update> updateQuickReplyMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateQuickReplyMessage>(p);
}

updateQuickReplyMessage::updateQuickReplyMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void updateQuickReplyMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateQuickReplyMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateDeleteQuickReplyMessages::ID;

object_ptr<Update> updateDeleteQuickReplyMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateDeleteQuickReplyMessages>(p);
}

updateDeleteQuickReplyMessages::updateDeleteQuickReplyMessages(TlBufferParser &p)
  : shortcut_id_(TlFetchInt::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void updateDeleteQuickReplyMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteQuickReplyMessages");
    s.store_field("shortcut_id", shortcut_id_);
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateBotBusinessConnect::ID;

object_ptr<Update> updateBotBusinessConnect::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotBusinessConnect>(p);
}

updateBotBusinessConnect::updateBotBusinessConnect(TlBufferParser &p)
  : connection_(TlFetchBoxed<TlFetchObject<botBusinessConnection>, -1892371723>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotBusinessConnect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotBusinessConnect");
    s.store_object_field("connection", static_cast<const BaseObject *>(connection_.get()));
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateBotNewBusinessMessage::updateBotNewBusinessMessage()
  : flags_()
  , connection_id_()
  , message_()
  , reply_to_message_()
  , qts_()
{}

const std::int32_t updateBotNewBusinessMessage::ID;

object_ptr<Update> updateBotNewBusinessMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotNewBusinessMessage> res = make_tl_object<updateBotNewBusinessMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->connection_id_ = TlFetchString<string>::parse(p);
  res->message_ = TlFetchObject<Message>::parse(p);
  if (var0 & 1) { res->reply_to_message_ = TlFetchObject<Message>::parse(p); }
  res->qts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotNewBusinessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotNewBusinessMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("connection_id", connection_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    if (var0 & 1) { s.store_object_field("reply_to_message", static_cast<const BaseObject *>(reply_to_message_.get())); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

updateBotEditBusinessMessage::updateBotEditBusinessMessage()
  : flags_()
  , connection_id_()
  , message_()
  , reply_to_message_()
  , qts_()
{}

const std::int32_t updateBotEditBusinessMessage::ID;

object_ptr<Update> updateBotEditBusinessMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBotEditBusinessMessage> res = make_tl_object<updateBotEditBusinessMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->connection_id_ = TlFetchString<string>::parse(p);
  res->message_ = TlFetchObject<Message>::parse(p);
  if (var0 & 1) { res->reply_to_message_ = TlFetchObject<Message>::parse(p); }
  res->qts_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBotEditBusinessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotEditBusinessMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("connection_id", connection_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    if (var0 & 1) { s.store_object_field("reply_to_message", static_cast<const BaseObject *>(reply_to_message_.get())); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateBotDeleteBusinessMessage::ID;

object_ptr<Update> updateBotDeleteBusinessMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotDeleteBusinessMessage>(p);
}

updateBotDeleteBusinessMessage::updateBotDeleteBusinessMessage(TlBufferParser &p)
  : connection_id_(TlFetchString<string>::parse(p))
  , peer_(TlFetchObject<Peer>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotDeleteBusinessMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotDeleteBusinessMessage");
    s.store_field("connection_id", connection_id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updateNewStoryReaction::ID;

object_ptr<Update> updateNewStoryReaction::fetch(TlBufferParser &p) {
  return make_tl_object<updateNewStoryReaction>(p);
}

updateNewStoryReaction::updateNewStoryReaction(TlBufferParser &p)
  : story_id_(TlFetchInt::parse(p))
  , peer_(TlFetchObject<Peer>::parse(p))
  , reaction_(TlFetchObject<Reaction>::parse(p))
{}

void updateNewStoryReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateNewStoryReaction");
    s.store_field("story_id", story_id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateStarsBalance::ID;

object_ptr<Update> updateStarsBalance::fetch(TlBufferParser &p) {
  return make_tl_object<updateStarsBalance>(p);
}

updateStarsBalance::updateStarsBalance(TlBufferParser &p)
  : balance_(TlFetchObject<StarsAmount>::parse(p))
{}

void updateStarsBalance::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStarsBalance");
    s.store_object_field("balance", static_cast<const BaseObject *>(balance_.get()));
    s.store_class_end();
  }
}

updateBusinessBotCallbackQuery::updateBusinessBotCallbackQuery()
  : flags_()
  , query_id_()
  , user_id_()
  , connection_id_()
  , message_()
  , reply_to_message_()
  , chat_instance_()
  , data_()
{}

const std::int32_t updateBusinessBotCallbackQuery::ID;

object_ptr<Update> updateBusinessBotCallbackQuery::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateBusinessBotCallbackQuery> res = make_tl_object<updateBusinessBotCallbackQuery>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_id_ = TlFetchLong::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->connection_id_ = TlFetchString<string>::parse(p);
  res->message_ = TlFetchObject<Message>::parse(p);
  if (var0 & 4) { res->reply_to_message_ = TlFetchObject<Message>::parse(p); }
  res->chat_instance_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->data_ = TlFetchBytes<bytes>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateBusinessBotCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBusinessBotCallbackQuery");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("query_id", query_id_);
    s.store_field("user_id", user_id_);
    s.store_field("connection_id", connection_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    if (var0 & 4) { s.store_object_field("reply_to_message", static_cast<const BaseObject *>(reply_to_message_.get())); }
    s.store_field("chat_instance", chat_instance_);
    if (var0 & 1) { s.store_bytes_field("data", data_); }
    s.store_class_end();
  }
}

const std::int32_t updateStarsRevenueStatus::ID;

object_ptr<Update> updateStarsRevenueStatus::fetch(TlBufferParser &p) {
  return make_tl_object<updateStarsRevenueStatus>(p);
}

updateStarsRevenueStatus::updateStarsRevenueStatus(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , status_(TlFetchBoxed<TlFetchObject<starsRevenueStatus>, -21080943>::parse(p))
{}

void updateStarsRevenueStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStarsRevenueStatus");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateBotPurchasedPaidMedia::ID;

object_ptr<Update> updateBotPurchasedPaidMedia::fetch(TlBufferParser &p) {
  return make_tl_object<updateBotPurchasedPaidMedia>(p);
}

updateBotPurchasedPaidMedia::updateBotPurchasedPaidMedia(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , payload_(TlFetchString<string>::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateBotPurchasedPaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateBotPurchasedPaidMedia");
    s.store_field("user_id", user_id_);
    s.store_field("payload", payload_);
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

const std::int32_t updatePaidReactionPrivacy::ID;

object_ptr<Update> updatePaidReactionPrivacy::fetch(TlBufferParser &p) {
  return make_tl_object<updatePaidReactionPrivacy>(p);
}

updatePaidReactionPrivacy::updatePaidReactionPrivacy(TlBufferParser &p)
  : private_(TlFetchObject<PaidReactionPrivacy>::parse(p))
{}

void updatePaidReactionPrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePaidReactionPrivacy");
    s.store_object_field("private", static_cast<const BaseObject *>(private_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateSentPhoneCode::ID;

object_ptr<Update> updateSentPhoneCode::fetch(TlBufferParser &p) {
  return make_tl_object<updateSentPhoneCode>(p);
}

updateSentPhoneCode::updateSentPhoneCode(TlBufferParser &p)
  : sent_code_(TlFetchObject<auth_SentCode>::parse(p))
{}

void updateSentPhoneCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateSentPhoneCode");
    s.store_object_field("sent_code", static_cast<const BaseObject *>(sent_code_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateGroupCallChainBlocks::ID;

object_ptr<Update> updateGroupCallChainBlocks::fetch(TlBufferParser &p) {
  return make_tl_object<updateGroupCallChainBlocks>(p);
}

updateGroupCallChainBlocks::updateGroupCallChainBlocks(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , sub_chain_id_(TlFetchInt::parse(p))
  , blocks_(TlFetchBoxed<TlFetchVector<TlFetchBytes<bytes>>, 481674261>::parse(p))
  , next_offset_(TlFetchInt::parse(p))
{}

void updateGroupCallChainBlocks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallChainBlocks");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("sub_chain_id", sub_chain_id_);
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_field("next_offset", next_offset_);
    s.store_class_end();
  }
}

const std::int32_t updateReadMonoForumInbox::ID;

object_ptr<Update> updateReadMonoForumInbox::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadMonoForumInbox>(p);
}

updateReadMonoForumInbox::updateReadMonoForumInbox(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , saved_peer_id_(TlFetchObject<Peer>::parse(p))
  , read_max_id_(TlFetchInt::parse(p))
{}

void updateReadMonoForumInbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadMonoForumInbox");
    s.store_field("channel_id", channel_id_);
    s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get()));
    s.store_field("read_max_id", read_max_id_);
    s.store_class_end();
  }
}

const std::int32_t updateReadMonoForumOutbox::ID;

object_ptr<Update> updateReadMonoForumOutbox::fetch(TlBufferParser &p) {
  return make_tl_object<updateReadMonoForumOutbox>(p);
}

updateReadMonoForumOutbox::updateReadMonoForumOutbox(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , saved_peer_id_(TlFetchObject<Peer>::parse(p))
  , read_max_id_(TlFetchInt::parse(p))
{}

void updateReadMonoForumOutbox::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateReadMonoForumOutbox");
    s.store_field("channel_id", channel_id_);
    s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get()));
    s.store_field("read_max_id", read_max_id_);
    s.store_class_end();
  }
}

updateMonoForumNoPaidException::updateMonoForumNoPaidException()
  : flags_()
  , exception_()
  , channel_id_()
  , saved_peer_id_()
{}

const std::int32_t updateMonoForumNoPaidException::ID;

object_ptr<Update> updateMonoForumNoPaidException::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updateMonoForumNoPaidException> res = make_tl_object<updateMonoForumNoPaidException>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->exception_ = (var0 & 1) != 0;
  res->channel_id_ = TlFetchLong::parse(p);
  res->saved_peer_id_ = TlFetchObject<Peer>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updateMonoForumNoPaidException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateMonoForumNoPaidException");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (exception_ << 0)));
    if (var0 & 1) { s.store_field("exception", true); }
    s.store_field("channel_id", channel_id_);
    s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateGroupCallMessage::ID;

object_ptr<Update> updateGroupCallMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateGroupCallMessage>(p);
}

updateGroupCallMessage::updateGroupCallMessage(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , message_(TlFetchBoxed<TlFetchObject<groupCallMessage>, 445316222>::parse(p))
{}

void updateGroupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallMessage");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateGroupCallEncryptedMessage::ID;

object_ptr<Update> updateGroupCallEncryptedMessage::fetch(TlBufferParser &p) {
  return make_tl_object<updateGroupCallEncryptedMessage>(p);
}

updateGroupCallEncryptedMessage::updateGroupCallEncryptedMessage(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , from_id_(TlFetchObject<Peer>::parse(p))
  , encrypted_message_(TlFetchBytes<bytes>::parse(p))
{}

void updateGroupCallEncryptedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateGroupCallEncryptedMessage");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get()));
    s.store_bytes_field("encrypted_message", encrypted_message_);
    s.store_class_end();
  }
}

updatePinnedForumTopic::updatePinnedForumTopic()
  : flags_()
  , pinned_()
  , peer_()
  , topic_id_()
{}

const std::int32_t updatePinnedForumTopic::ID;

object_ptr<Update> updatePinnedForumTopic::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePinnedForumTopic> res = make_tl_object<updatePinnedForumTopic>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->topic_id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePinnedForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePinnedForumTopic");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("topic_id", topic_id_);
    s.store_class_end();
  }
}

updatePinnedForumTopics::updatePinnedForumTopics()
  : flags_()
  , peer_()
  , order_()
{}

const std::int32_t updatePinnedForumTopics::ID;

object_ptr<Update> updatePinnedForumTopics::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<updatePinnedForumTopics> res = make_tl_object<updatePinnedForumTopics>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 1) { res->order_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void updatePinnedForumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updatePinnedForumTopics");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t updateDeleteGroupCallMessages::ID;

object_ptr<Update> updateDeleteGroupCallMessages::fetch(TlBufferParser &p) {
  return make_tl_object<updateDeleteGroupCallMessages>(p);
}

updateDeleteGroupCallMessages::updateDeleteGroupCallMessages(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void updateDeleteGroupCallMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateDeleteGroupCallMessages");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t updateStarGiftAuctionState::ID;

object_ptr<Update> updateStarGiftAuctionState::fetch(TlBufferParser &p) {
  return make_tl_object<updateStarGiftAuctionState>(p);
}

updateStarGiftAuctionState::updateStarGiftAuctionState(TlBufferParser &p)
  : gift_id_(TlFetchLong::parse(p))
  , state_(TlFetchObject<StarGiftAuctionState>::parse(p))
{}

void updateStarGiftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStarGiftAuctionState");
    s.store_field("gift_id", gift_id_);
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateStarGiftAuctionUserState::ID;

object_ptr<Update> updateStarGiftAuctionUserState::fetch(TlBufferParser &p) {
  return make_tl_object<updateStarGiftAuctionUserState>(p);
}

updateStarGiftAuctionUserState::updateStarGiftAuctionUserState(TlBufferParser &p)
  : gift_id_(TlFetchLong::parse(p))
  , user_state_(TlFetchBoxed<TlFetchObject<starGiftAuctionUserState>, 787403204>::parse(p))
{}

void updateStarGiftAuctionUserState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStarGiftAuctionUserState");
    s.store_field("gift_id", gift_id_);
    s.store_object_field("user_state", static_cast<const BaseObject *>(user_state_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateEmojiGameInfo::ID;

object_ptr<Update> updateEmojiGameInfo::fetch(TlBufferParser &p) {
  return make_tl_object<updateEmojiGameInfo>(p);
}

updateEmojiGameInfo::updateEmojiGameInfo(TlBufferParser &p)
  : info_(TlFetchObject<messages_EmojiGameInfo>::parse(p))
{}

void updateEmojiGameInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateEmojiGameInfo");
    s.store_object_field("info", static_cast<const BaseObject *>(info_.get()));
    s.store_class_end();
  }
}

const std::int32_t updateStarGiftCraftFail::ID;

object_ptr<Update> updateStarGiftCraftFail::fetch(TlBufferParser &p) {
  return make_tl_object<updateStarGiftCraftFail>();
}

void updateStarGiftCraftFail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateStarGiftCraftFail");
    s.store_class_end();
  }
}

const std::int32_t updateChatParticipantRank::ID;

object_ptr<Update> updateChatParticipantRank::fetch(TlBufferParser &p) {
  return make_tl_object<updateChatParticipantRank>(p);
}

updateChatParticipantRank::updateChatParticipantRank(TlBufferParser &p)
  : chat_id_(TlFetchLong::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , rank_(TlFetchString<string>::parse(p))
  , version_(TlFetchInt::parse(p))
{}

void updateChatParticipantRank::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateChatParticipantRank");
    s.store_field("chat_id", chat_id_);
    s.store_field("user_id", user_id_);
    s.store_field("rank", rank_);
    s.store_field("version", version_);
    s.store_class_end();
  }
}

const std::int32_t updateManagedBot::ID;

object_ptr<Update> updateManagedBot::fetch(TlBufferParser &p) {
  return make_tl_object<updateManagedBot>(p);
}

updateManagedBot::updateManagedBot(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , bot_id_(TlFetchLong::parse(p))
  , qts_(TlFetchInt::parse(p))
{}

void updateManagedBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updateManagedBot");
    s.store_field("user_id", user_id_);
    s.store_field("bot_id", bot_id_);
    s.store_field("qts", qts_);
    s.store_class_end();
  }
}

object_ptr<WebDocument> WebDocument::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case webDocument::ID:
      return webDocument::fetch(p);
    case webDocumentNoProxy::ID:
      return webDocumentNoProxy::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

webDocument::webDocument(string const &url_, int64 access_hash_, int32 size_, string const &mime_type_, array<object_ptr<DocumentAttribute>> &&attributes_)
  : url_(url_)
  , access_hash_(access_hash_)
  , size_(size_)
  , mime_type_(mime_type_)
  , attributes_(std::move(attributes_))
{}

const std::int32_t webDocument::ID;

object_ptr<WebDocument> webDocument::fetch(TlBufferParser &p) {
  return make_tl_object<webDocument>(p);
}

webDocument::webDocument(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , size_(TlFetchInt::parse(p))
  , mime_type_(TlFetchString<string>::parse(p))
  , attributes_(TlFetchBoxed<TlFetchVector<TlFetchObject<DocumentAttribute>>, 481674261>::parse(p))
{}

void webDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void webDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void webDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webDocument");
    s.store_field("url", url_);
    s.store_field("access_hash", access_hash_);
    s.store_field("size", size_);
    s.store_field("mime_type", mime_type_);
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

webDocumentNoProxy::webDocumentNoProxy(string const &url_, int32 size_, string const &mime_type_, array<object_ptr<DocumentAttribute>> &&attributes_)
  : url_(url_)
  , size_(size_)
  , mime_type_(mime_type_)
  , attributes_(std::move(attributes_))
{}

const std::int32_t webDocumentNoProxy::ID;

object_ptr<WebDocument> webDocumentNoProxy::fetch(TlBufferParser &p) {
  return make_tl_object<webDocumentNoProxy>(p);
}

webDocumentNoProxy::webDocumentNoProxy(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , size_(TlFetchInt::parse(p))
  , mime_type_(TlFetchString<string>::parse(p))
  , attributes_(TlFetchBoxed<TlFetchVector<TlFetchObject<DocumentAttribute>>, 481674261>::parse(p))
{}

void webDocumentNoProxy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void webDocumentNoProxy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void webDocumentNoProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webDocumentNoProxy");
    s.store_field("url", url_);
    s.store_field("size", size_);
    s.store_field("mime_type", mime_type_);
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_authorizationForm::account_authorizationForm()
  : flags_()
  , required_types_()
  , values_()
  , errors_()
  , users_()
  , privacy_policy_url_()
{}

const std::int32_t account_authorizationForm::ID;

object_ptr<account_authorizationForm> account_authorizationForm::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_authorizationForm> res = make_tl_object<account_authorizationForm>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->required_types_ = TlFetchBoxed<TlFetchVector<TlFetchObject<SecureRequiredType>>, 481674261>::parse(p);
  res->values_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<secureValue>, 411017418>>, 481674261>::parse(p);
  res->errors_ = TlFetchBoxed<TlFetchVector<TlFetchObject<SecureValueError>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->privacy_policy_url_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void account_authorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.authorizationForm");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    { s.store_vector_begin("required_types", required_types_.size()); for (const auto &_value : required_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("values", values_.size()); for (const auto &_value : values_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("errors", errors_.size()); for (const auto &_value : errors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("privacy_policy_url", privacy_policy_url_); }
    s.store_class_end();
  }
}

const std::int32_t account_autoDownloadSettings::ID;

object_ptr<account_autoDownloadSettings> account_autoDownloadSettings::fetch(TlBufferParser &p) {
  return make_tl_object<account_autoDownloadSettings>(p);
}

account_autoDownloadSettings::account_autoDownloadSettings(TlBufferParser &p)
  : low_(TlFetchBoxed<TlFetchObject<autoDownloadSettings>, -1163561432>::parse(p))
  , medium_(TlFetchBoxed<TlFetchObject<autoDownloadSettings>, -1163561432>::parse(p))
  , high_(TlFetchBoxed<TlFetchObject<autoDownloadSettings>, -1163561432>::parse(p))
{}

void account_autoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.autoDownloadSettings");
    s.store_object_field("low", static_cast<const BaseObject *>(low_.get()));
    s.store_object_field("medium", static_cast<const BaseObject *>(medium_.get()));
    s.store_object_field("high", static_cast<const BaseObject *>(high_.get()));
    s.store_class_end();
  }
}

const std::int32_t account_paidMessagesRevenue::ID;

object_ptr<account_paidMessagesRevenue> account_paidMessagesRevenue::fetch(TlBufferParser &p) {
  return make_tl_object<account_paidMessagesRevenue>(p);
}

account_paidMessagesRevenue::account_paidMessagesRevenue(TlBufferParser &p)
  : stars_amount_(TlFetchLong::parse(p))
{}

void account_paidMessagesRevenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.paidMessagesRevenue");
    s.store_field("stars_amount", stars_amount_);
    s.store_class_end();
  }
}

object_ptr<account_SavedMusicIds> account_SavedMusicIds::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_savedMusicIdsNotModified::ID:
      return account_savedMusicIdsNotModified::fetch(p);
    case account_savedMusicIds::ID:
      return account_savedMusicIds::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_savedMusicIdsNotModified::ID;

object_ptr<account_SavedMusicIds> account_savedMusicIdsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_savedMusicIdsNotModified>();
}

void account_savedMusicIdsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.savedMusicIdsNotModified");
    s.store_class_end();
  }
}

const std::int32_t account_savedMusicIds::ID;

object_ptr<account_SavedMusicIds> account_savedMusicIds::fetch(TlBufferParser &p) {
  return make_tl_object<account_savedMusicIds>(p);
}

account_savedMusicIds::account_savedMusicIds(TlBufferParser &p)
  : ids_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void account_savedMusicIds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.savedMusicIds");
    { s.store_vector_begin("ids", ids_.size()); for (const auto &_value : ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<account_SavedRingtones> account_SavedRingtones::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_savedRingtonesNotModified::ID:
      return account_savedRingtonesNotModified::fetch(p);
    case account_savedRingtones::ID:
      return account_savedRingtones::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_savedRingtonesNotModified::ID;

object_ptr<account_SavedRingtones> account_savedRingtonesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_savedRingtonesNotModified>();
}

void account_savedRingtonesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.savedRingtonesNotModified");
    s.store_class_end();
  }
}

const std::int32_t account_savedRingtones::ID;

object_ptr<account_SavedRingtones> account_savedRingtones::fetch(TlBufferParser &p) {
  return make_tl_object<account_savedRingtones>(p);
}

account_savedRingtones::account_savedRingtones(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , ringtones_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void account_savedRingtones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.savedRingtones");
    s.store_field("hash", hash_);
    { s.store_vector_begin("ringtones", ringtones_.size()); for (const auto &_value : ringtones_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t account_webAuthorizations::ID;

object_ptr<account_webAuthorizations> account_webAuthorizations::fetch(TlBufferParser &p) {
  return make_tl_object<account_webAuthorizations>(p);
}

account_webAuthorizations::account_webAuthorizations(TlBufferParser &p)
  : authorizations_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<webAuthorization>, -1493633966>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void account_webAuthorizations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.webAuthorizations");
    { s.store_vector_begin("authorizations", authorizations_.size()); for (const auto &_value : authorizations_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t auth_passkeyLoginOptions::ID;

object_ptr<auth_passkeyLoginOptions> auth_passkeyLoginOptions::fetch(TlBufferParser &p) {
  return make_tl_object<auth_passkeyLoginOptions>(p);
}

auth_passkeyLoginOptions::auth_passkeyLoginOptions(TlBufferParser &p)
  : options_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
{}

void auth_passkeyLoginOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.passkeyLoginOptions");
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_class_end();
  }
}

const std::int32_t bots_requestedButton::ID;

object_ptr<bots_requestedButton> bots_requestedButton::fetch(TlBufferParser &p) {
  return make_tl_object<bots_requestedButton>(p);
}

bots_requestedButton::bots_requestedButton(TlBufferParser &p)
  : webapp_req_id_(TlFetchString<string>::parse(p))
{}

void bots_requestedButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.requestedButton");
    s.store_field("webapp_req_id", webapp_req_id_);
    s.store_class_end();
  }
}

const std::int32_t chatlists_exportedInvites::ID;

object_ptr<chatlists_exportedInvites> chatlists_exportedInvites::fetch(TlBufferParser &p) {
  return make_tl_object<chatlists_exportedInvites>(p);
}

chatlists_exportedInvites::chatlists_exportedInvites(TlBufferParser &p)
  : invites_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<exportedChatlistInvite>, 206668204>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void chatlists_exportedInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.exportedInvites");
    { s.store_vector_begin("invites", invites_.size()); for (const auto &_value : invites_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<contacts_SponsoredPeers> contacts_SponsoredPeers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case contacts_sponsoredPeersEmpty::ID:
      return contacts_sponsoredPeersEmpty::fetch(p);
    case contacts_sponsoredPeers::ID:
      return contacts_sponsoredPeers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t contacts_sponsoredPeersEmpty::ID;

object_ptr<contacts_SponsoredPeers> contacts_sponsoredPeersEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_sponsoredPeersEmpty>();
}

void contacts_sponsoredPeersEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.sponsoredPeersEmpty");
    s.store_class_end();
  }
}

const std::int32_t contacts_sponsoredPeers::ID;

object_ptr<contacts_SponsoredPeers> contacts_sponsoredPeers::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_sponsoredPeers>(p);
}

contacts_sponsoredPeers::contacts_sponsoredPeers(TlBufferParser &p)
  : peers_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<sponsoredPeer>, -963180333>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_sponsoredPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.sponsoredPeers");
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<help_AppUpdate> help_AppUpdate::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_appUpdate::ID:
      return help_appUpdate::fetch(p);
    case help_noAppUpdate::ID:
      return help_noAppUpdate::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

help_appUpdate::help_appUpdate()
  : flags_()
  , can_not_skip_()
  , id_()
  , version_()
  , text_()
  , entities_()
  , document_()
  , url_()
  , sticker_()
{}

const std::int32_t help_appUpdate::ID;

object_ptr<help_AppUpdate> help_appUpdate::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_appUpdate> res = make_tl_object<help_appUpdate>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_not_skip_ = (var0 & 1) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->version_ = TlFetchString<string>::parse(p);
  res->text_ = TlFetchString<string>::parse(p);
  res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p);
  if (var0 & 2) { res->document_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 4) { res->url_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->sticker_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void help_appUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.appUpdate");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_not_skip_ << 0)));
    if (var0 & 1) { s.store_field("can_not_skip", true); }
    s.store_field("id", id_);
    s.store_field("version", version_);
    s.store_field("text", text_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 2) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 4) { s.store_field("url", url_); }
    if (var0 & 8) { s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get())); }
    s.store_class_end();
  }
}

const std::int32_t help_noAppUpdate::ID;

object_ptr<help_AppUpdate> help_noAppUpdate::fetch(TlBufferParser &p) {
  return make_tl_object<help_noAppUpdate>();
}

void help_noAppUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.noAppUpdate");
    s.store_class_end();
  }
}

messages_botCallbackAnswer::messages_botCallbackAnswer()
  : flags_()
  , alert_()
  , has_url_()
  , native_ui_()
  , message_()
  , url_()
  , cache_time_()
{}

const std::int32_t messages_botCallbackAnswer::ID;

object_ptr<messages_botCallbackAnswer> messages_botCallbackAnswer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_botCallbackAnswer> res = make_tl_object<messages_botCallbackAnswer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->alert_ = (var0 & 2) != 0;
  res->has_url_ = (var0 & 8) != 0;
  res->native_ui_ = (var0 & 16) != 0;
  if (var0 & 1) { res->message_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->url_ = TlFetchString<string>::parse(p); }
  res->cache_time_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_botCallbackAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.botCallbackAnswer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (alert_ << 1) | (has_url_ << 3) | (native_ui_ << 4)));
    if (var0 & 2) { s.store_field("alert", true); }
    if (var0 & 8) { s.store_field("has_url", true); }
    if (var0 & 16) { s.store_field("native_ui", true); }
    if (var0 & 1) { s.store_field("message", message_); }
    if (var0 & 4) { s.store_field("url", url_); }
    s.store_field("cache_time", cache_time_);
    s.store_class_end();
  }
}

messages_discussionMessage::messages_discussionMessage()
  : flags_()
  , messages_()
  , max_id_()
  , read_inbox_max_id_()
  , read_outbox_max_id_()
  , unread_count_()
  , chats_()
  , users_()
{}

const std::int32_t messages_discussionMessage::ID;

object_ptr<messages_discussionMessage> messages_discussionMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_discussionMessage> res = make_tl_object<messages_discussionMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  if (var0 & 1) { res->max_id_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->read_inbox_max_id_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->read_outbox_max_id_ = TlFetchInt::parse(p); }
  res->unread_count_ = TlFetchInt::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_discussionMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.discussionMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("max_id", max_id_); }
    if (var0 & 2) { s.store_field("read_inbox_max_id", read_inbox_max_id_); }
    if (var0 & 4) { s.store_field("read_outbox_max_id", read_outbox_max_id_); }
    s.store_field("unread_count", unread_count_);
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_ExportedChatInvite> messages_ExportedChatInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_exportedChatInvite::ID:
      return messages_exportedChatInvite::fetch(p);
    case messages_exportedChatInviteReplaced::ID:
      return messages_exportedChatInviteReplaced::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_exportedChatInvite::ID;

object_ptr<messages_ExportedChatInvite> messages_exportedChatInvite::fetch(TlBufferParser &p) {
  return make_tl_object<messages_exportedChatInvite>(p);
}

messages_exportedChatInvite::messages_exportedChatInvite(TlBufferParser &p)
  : invite_(TlFetchObject<ExportedChatInvite>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_exportedChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.exportedChatInvite");
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_exportedChatInviteReplaced::ID;

object_ptr<messages_ExportedChatInvite> messages_exportedChatInviteReplaced::fetch(TlBufferParser &p) {
  return make_tl_object<messages_exportedChatInviteReplaced>(p);
}

messages_exportedChatInviteReplaced::messages_exportedChatInviteReplaced(TlBufferParser &p)
  : invite_(TlFetchObject<ExportedChatInvite>::parse(p))
  , new_invite_(TlFetchObject<ExportedChatInvite>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_exportedChatInviteReplaced::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.exportedChatInviteReplaced");
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_object_field("new_invite", static_cast<const BaseObject *>(new_invite_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_QuickReplies> messages_QuickReplies::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_quickReplies::ID:
      return messages_quickReplies::fetch(p);
    case messages_quickRepliesNotModified::ID:
      return messages_quickRepliesNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_quickReplies::ID;

object_ptr<messages_QuickReplies> messages_quickReplies::fetch(TlBufferParser &p) {
  return make_tl_object<messages_quickReplies>(p);
}

messages_quickReplies::messages_quickReplies(TlBufferParser &p)
  : quick_replies_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<quickReply>, 110563371>>, 481674261>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_quickReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.quickReplies");
    { s.store_vector_begin("quick_replies", quick_replies_.size()); for (const auto &_value : quick_replies_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_quickRepliesNotModified::ID;

object_ptr<messages_QuickReplies> messages_quickRepliesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_quickRepliesNotModified>();
}

void messages_quickRepliesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.quickRepliesNotModified");
    s.store_class_end();
  }
}

messages_searchCounter::messages_searchCounter()
  : flags_()
  , inexact_()
  , filter_()
  , count_()
{}

const std::int32_t messages_searchCounter::ID;

object_ptr<messages_searchCounter> messages_searchCounter::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_searchCounter> res = make_tl_object<messages_searchCounter>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inexact_ = (var0 & 2) != 0;
  res->filter_ = TlFetchObject<MessagesFilter>::parse(p);
  res->count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_searchCounter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchCounter");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inexact_ << 1)));
    if (var0 & 2) { s.store_field("inexact", true); }
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("count", count_);
    s.store_class_end();
  }
}

object_ptr<payments_StarGifts> payments_StarGifts::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_starGiftsNotModified::ID:
      return payments_starGiftsNotModified::fetch(p);
    case payments_starGifts::ID:
      return payments_starGifts::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t payments_starGiftsNotModified::ID;

object_ptr<payments_StarGifts> payments_starGiftsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftsNotModified>();
}

void payments_starGiftsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftsNotModified");
    s.store_class_end();
  }
}

const std::int32_t payments_starGifts::ID;

object_ptr<payments_StarGifts> payments_starGifts::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGifts>(p);
}

payments_starGifts::payments_starGifts(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , gifts_(TlFetchBoxed<TlFetchVector<TlFetchObject<StarGift>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void payments_starGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGifts");
    s.store_field("hash", hash_);
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_uniqueStarGift::ID;

object_ptr<payments_uniqueStarGift> payments_uniqueStarGift::fetch(TlBufferParser &p) {
  return make_tl_object<payments_uniqueStarGift>(p);
}

payments_uniqueStarGift::payments_uniqueStarGift(TlBufferParser &p)
  : gift_(TlFetchObject<StarGift>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void payments_uniqueStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.uniqueStarGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t phone_groupCallStars::ID;

object_ptr<phone_groupCallStars> phone_groupCallStars::fetch(TlBufferParser &p) {
  return make_tl_object<phone_groupCallStars>(p);
}

phone_groupCallStars::phone_groupCallStars(TlBufferParser &p)
  : total_stars_(TlFetchLong::parse(p))
  , top_donors_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<groupCallDonor>, -297595771>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void phone_groupCallStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.groupCallStars");
    s.store_field("total_stars", total_stars_);
    { s.store_vector_begin("top_donors", top_donors_.size()); for (const auto &_value : top_donors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

smsjobs_status::smsjobs_status()
  : flags_()
  , allow_international_()
  , recent_sent_()
  , recent_since_()
  , recent_remains_()
  , total_sent_()
  , total_since_()
  , last_gift_slug_()
  , terms_url_()
{}

const std::int32_t smsjobs_status::ID;

object_ptr<smsjobs_status> smsjobs_status::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<smsjobs_status> res = make_tl_object<smsjobs_status>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->allow_international_ = (var0 & 1) != 0;
  res->recent_sent_ = TlFetchInt::parse(p);
  res->recent_since_ = TlFetchInt::parse(p);
  res->recent_remains_ = TlFetchInt::parse(p);
  res->total_sent_ = TlFetchInt::parse(p);
  res->total_since_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->last_gift_slug_ = TlFetchString<string>::parse(p); }
  res->terms_url_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void smsjobs_status::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.status");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (allow_international_ << 0)));
    if (var0 & 1) { s.store_field("allow_international", true); }
    s.store_field("recent_sent", recent_sent_);
    s.store_field("recent_since", recent_since_);
    s.store_field("recent_remains", recent_remains_);
    s.store_field("total_sent", total_sent_);
    s.store_field("total_since", total_since_);
    if (var0 & 2) { s.store_field("last_gift_slug", last_gift_slug_); }
    s.store_field("terms_url", terms_url_);
    s.store_class_end();
  }
}

stories_foundStories::stories_foundStories()
  : flags_()
  , count_()
  , stories_()
  , next_offset_()
  , chats_()
  , users_()
{}

const std::int32_t stories_foundStories::ID;

object_ptr<stories_foundStories> stories_foundStories::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stories_foundStories> res = make_tl_object<stories_foundStories>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->stories_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<foundStory>, -394605632>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void stories_foundStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.foundStories");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("count", count_);
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_storyViewsList::stories_storyViewsList()
  : flags_()
  , count_()
  , views_count_()
  , forwards_count_()
  , reactions_count_()
  , views_()
  , chats_()
  , users_()
  , next_offset_()
{}

const std::int32_t stories_storyViewsList::ID;

object_ptr<stories_storyViewsList> stories_storyViewsList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stories_storyViewsList> res = make_tl_object<stories_storyViewsList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->views_count_ = TlFetchInt::parse(p);
  res->forwards_count_ = TlFetchInt::parse(p);
  res->reactions_count_ = TlFetchInt::parse(p);
  res->views_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StoryView>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void stories_storyViewsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.storyViewsList");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("count", count_);
    s.store_field("views_count", views_count_);
    s.store_field("forwards_count", forwards_count_);
    s.store_field("reactions_count", reactions_count_);
    { s.store_vector_begin("views", views_.size()); for (const auto &_value : views_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

account_createBusinessChatLink::account_createBusinessChatLink(object_ptr<inputBusinessChatLink> &&link_)
  : link_(std::move(link_))
{}

const std::int32_t account_createBusinessChatLink::ID;

void account_createBusinessChatLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2007898482);
  TlStoreBoxed<TlStoreObject, 292003751>::store(link_, s);
}

void account_createBusinessChatLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2007898482);
  TlStoreBoxed<TlStoreObject, 292003751>::store(link_, s);
}

void account_createBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.createBusinessChatLink");
    s.store_object_field("link", static_cast<const BaseObject *>(link_.get()));
    s.store_class_end();
  }
}

account_createBusinessChatLink::ReturnType account_createBusinessChatLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<businessChatLink>, -1263638929>::parse(p);
#undef FAIL
}

account_editBusinessChatLink::account_editBusinessChatLink(string const &slug_, object_ptr<inputBusinessChatLink> &&link_)
  : slug_(slug_)
  , link_(std::move(link_))
{}

const std::int32_t account_editBusinessChatLink::ID;

void account_editBusinessChatLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1942744913);
  TlStoreString::store(slug_, s);
  TlStoreBoxed<TlStoreObject, 292003751>::store(link_, s);
}

void account_editBusinessChatLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1942744913);
  TlStoreString::store(slug_, s);
  TlStoreBoxed<TlStoreObject, 292003751>::store(link_, s);
}

void account_editBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.editBusinessChatLink");
    s.store_field("slug", slug_);
    s.store_object_field("link", static_cast<const BaseObject *>(link_.get()));
    s.store_class_end();
  }
}

account_editBusinessChatLink::ReturnType account_editBusinessChatLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<businessChatLink>, -1263638929>::parse(p);
#undef FAIL
}

const std::int32_t account_getAccountTTL::ID;

void account_getAccountTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(150761757);
}

void account_getAccountTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(150761757);
}

void account_getAccountTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getAccountTTL");
    s.store_class_end();
  }
}

account_getAccountTTL::ReturnType account_getAccountTTL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<accountDaysTTL>, -1194283041>::parse(p);
#undef FAIL
}

const std::int32_t account_getReactionsNotifySettings::ID;

void account_getReactionsNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(115172684);
}

void account_getReactionsNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(115172684);
}

void account_getReactionsNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getReactionsNotifySettings");
    s.store_class_end();
  }
}

account_getReactionsNotifySettings::ReturnType account_getReactionsNotifySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<reactionsNotifySettings>, 1910827608>::parse(p);
#undef FAIL
}

account_getTmpPassword::account_getTmpPassword(object_ptr<InputCheckPasswordSRP> &&password_, int32 period_)
  : password_(std::move(password_))
  , period_(period_)
{}

const std::int32_t account_getTmpPassword::ID;

void account_getTmpPassword::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1151208273);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
  TlStoreBinary::store(period_, s);
}

void account_getTmpPassword::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1151208273);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
  TlStoreBinary::store(period_, s);
}

void account_getTmpPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getTmpPassword");
    s.store_object_field("password", static_cast<const BaseObject *>(password_.get()));
    s.store_field("period", period_);
    s.store_class_end();
  }
}

account_getTmpPassword::ReturnType account_getTmpPassword::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_tmpPassword>, -614138572>::parse(p);
#undef FAIL
}

const std::int32_t account_resendPasswordEmail::ID;

void account_resendPasswordEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2055154197);
}

void account_resendPasswordEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2055154197);
}

void account_resendPasswordEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resendPasswordEmail");
    s.store_class_end();
  }
}

account_resendPasswordEmail::ReturnType account_resendPasswordEmail::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_resetPassword::ID;

void account_resetPassword::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1828139493);
}

void account_resetPassword::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1828139493);
}

void account_resetPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetPassword");
    s.store_class_end();
  }
}

account_resetPassword::ReturnType account_resetPassword::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_ResetPasswordResult>::parse(p);
#undef FAIL
}

account_resetWebAuthorization::account_resetWebAuthorization(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_resetWebAuthorization::ID;

void account_resetWebAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(755087855);
  TlStoreBinary::store(hash_, s);
}

void account_resetWebAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(755087855);
  TlStoreBinary::store(hash_, s);
}

void account_resetWebAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetWebAuthorization");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_resetWebAuthorization::ReturnType account_resetWebAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_saveAutoSaveSettings::account_saveAutoSaveSettings(int32 flags_, bool users_, bool chats_, bool broadcasts_, object_ptr<InputPeer> &&peer_, object_ptr<autoSaveSettings> &&settings_)
  : flags_(flags_)
  , users_(users_)
  , chats_(chats_)
  , broadcasts_(broadcasts_)
  , peer_(std::move(peer_))
  , settings_(std::move(settings_))
{}

const std::int32_t account_saveAutoSaveSettings::ID;

void account_saveAutoSaveSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-694451359);
  TlStoreBinary::store((var0 = flags_ | (users_ << 0) | (chats_ << 1) | (broadcasts_ << 2)), s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBoxed<TlStoreObject, -934791986>::store(settings_, s);
}

void account_saveAutoSaveSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-694451359);
  TlStoreBinary::store((var0 = flags_ | (users_ << 0) | (chats_ << 1) | (broadcasts_ << 2)), s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBoxed<TlStoreObject, -934791986>::store(settings_, s);
}

void account_saveAutoSaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveAutoSaveSettings");
    s.store_field("flags", (var0 = flags_ | (users_ << 0) | (chats_ << 1) | (broadcasts_ << 2)));
    if (var0 & 1) { s.store_field("users", true); }
    if (var0 & 2) { s.store_field("chats", true); }
    if (var0 & 4) { s.store_field("broadcasts", true); }
    if (var0 & 8) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_saveAutoSaveSettings::ReturnType account_saveAutoSaveSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_saveRingtone::account_saveRingtone(object_ptr<InputDocument> &&id_, bool unsave_)
  : id_(std::move(id_))
  , unsave_(unsave_)
{}

const std::int32_t account_saveRingtone::ID;

void account_saveRingtone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1038768899);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unsave_, s);
}

void account_saveRingtone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1038768899);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unsave_, s);
}

void account_saveRingtone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveRingtone");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("unsave", unsave_);
    s.store_class_end();
  }
}

account_saveRingtone::ReturnType account_saveRingtone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_SavedRingtone>::parse(p);
#undef FAIL
}

account_saveTheme::account_saveTheme(object_ptr<InputTheme> &&theme_, bool unsave_)
  : theme_(std::move(theme_))
  , unsave_(unsave_)
{}

const std::int32_t account_saveTheme::ID;

void account_saveTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-229175188);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
  TlStoreBool::store(unsave_, s);
}

void account_saveTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-229175188);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
  TlStoreBool::store(unsave_, s);
}

void account_saveTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveTheme");
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_field("unsave", unsave_);
    s.store_class_end();
  }
}

account_saveTheme::ReturnType account_saveTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_sendConfirmPhoneCode::account_sendConfirmPhoneCode(string const &hash_, object_ptr<codeSettings> &&settings_)
  : hash_(hash_)
  , settings_(std::move(settings_))
{}

const std::int32_t account_sendConfirmPhoneCode::ID;

void account_sendConfirmPhoneCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(457157256);
  TlStoreString::store(hash_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void account_sendConfirmPhoneCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(457157256);
  TlStoreString::store(hash_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void account_sendConfirmPhoneCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.sendConfirmPhoneCode");
    s.store_field("hash", hash_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_sendConfirmPhoneCode::ReturnType account_sendConfirmPhoneCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

account_setAccountTTL::account_setAccountTTL(object_ptr<accountDaysTTL> &&ttl_)
  : ttl_(std::move(ttl_))
{}

const std::int32_t account_setAccountTTL::ID;

void account_setAccountTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(608323678);
  TlStoreBoxed<TlStoreObject, -1194283041>::store(ttl_, s);
}

void account_setAccountTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(608323678);
  TlStoreBoxed<TlStoreObject, -1194283041>::store(ttl_, s);
}

void account_setAccountTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setAccountTTL");
    s.store_object_field("ttl", static_cast<const BaseObject *>(ttl_.get()));
    s.store_class_end();
  }
}

account_setAccountTTL::ReturnType account_setAccountTTL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateBirthday::account_updateBirthday(int32 flags_, object_ptr<birthday> &&birthday_)
  : flags_(flags_)
  , birthday_(std::move(birthday_))
{}

const std::int32_t account_updateBirthday::ID;

void account_updateBirthday::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-865203183);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 1821253126>::store(birthday_, s); }
}

void account_updateBirthday::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-865203183);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 1821253126>::store(birthday_, s); }
}

void account_updateBirthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateBirthday");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("birthday", static_cast<const BaseObject *>(birthday_.get())); }
    s.store_class_end();
  }
}

account_updateBirthday::ReturnType account_updateBirthday::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateBusinessLocation::account_updateBusinessLocation(int32 flags_, object_ptr<InputGeoPoint> &&geo_point_, string const &address_)
  : flags_(flags_)
  , geo_point_(std::move(geo_point_))
  , address_(address_)
{}

const std::int32_t account_updateBusinessLocation::ID;

void account_updateBusinessLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1637149926);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s); }
  if (var0 & 1) { TlStoreString::store(address_, s); }
}

void account_updateBusinessLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1637149926);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s); }
  if (var0 & 1) { TlStoreString::store(address_, s); }
}

void account_updateBusinessLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateBusinessLocation");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 2) { s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get())); }
    if (var0 & 1) { s.store_field("address", address_); }
    s.store_class_end();
  }
}

account_updateBusinessLocation::ReturnType account_updateBusinessLocation::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_verifyPhone::account_verifyPhone(string const &phone_number_, string const &phone_code_hash_, string const &phone_code_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , phone_code_(phone_code_)
{}

const std::int32_t account_verifyPhone::ID;

void account_verifyPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1305716726);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(phone_code_, s);
}

void account_verifyPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1305716726);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(phone_code_, s);
}

void account_verifyPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.verifyPhone");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("phone_code", phone_code_);
    s.store_class_end();
  }
}

account_verifyPhone::ReturnType account_verifyPhone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_bindTempAuthKey::auth_bindTempAuthKey(int64 perm_auth_key_id_, int64 nonce_, int32 expires_at_, bytes &&encrypted_message_)
  : perm_auth_key_id_(perm_auth_key_id_)
  , nonce_(nonce_)
  , expires_at_(expires_at_)
  , encrypted_message_(std::move(encrypted_message_))
{}

const std::int32_t auth_bindTempAuthKey::ID;

void auth_bindTempAuthKey::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-841733627);
  TlStoreBinary::store(perm_auth_key_id_, s);
  TlStoreBinary::store(nonce_, s);
  TlStoreBinary::store(expires_at_, s);
  TlStoreString::store(encrypted_message_, s);
}

void auth_bindTempAuthKey::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-841733627);
  TlStoreBinary::store(perm_auth_key_id_, s);
  TlStoreBinary::store(nonce_, s);
  TlStoreBinary::store(expires_at_, s);
  TlStoreString::store(encrypted_message_, s);
}

void auth_bindTempAuthKey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.bindTempAuthKey");
    s.store_field("perm_auth_key_id", perm_auth_key_id_);
    s.store_field("nonce", nonce_);
    s.store_field("expires_at", expires_at_);
    s.store_bytes_field("encrypted_message", encrypted_message_);
    s.store_class_end();
  }
}

auth_bindTempAuthKey::ReturnType auth_bindTempAuthKey::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_cancelCode::auth_cancelCode(string const &phone_number_, string const &phone_code_hash_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
{}

const std::int32_t auth_cancelCode::ID;

void auth_cancelCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(520357240);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
}

void auth_cancelCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(520357240);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
}

void auth_cancelCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.cancelCode");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_class_end();
  }
}

auth_cancelCode::ReturnType auth_cancelCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_initPasskeyLogin::auth_initPasskeyLogin(int32 api_id_, string const &api_hash_)
  : api_id_(api_id_)
  , api_hash_(api_hash_)
{}

const std::int32_t auth_initPasskeyLogin::ID;

void auth_initPasskeyLogin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1368051895);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
}

void auth_initPasskeyLogin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1368051895);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
}

void auth_initPasskeyLogin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.initPasskeyLogin");
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", api_hash_);
    s.store_class_end();
  }
}

auth_initPasskeyLogin::ReturnType auth_initPasskeyLogin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<auth_passkeyLoginOptions>, -503089271>::parse(p);
#undef FAIL
}

const std::int32_t auth_requestPasswordRecovery::ID;

void auth_requestPasswordRecovery::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-661144474);
}

void auth_requestPasswordRecovery::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-661144474);
}

void auth_requestPasswordRecovery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.requestPasswordRecovery");
    s.store_class_end();
  }
}

auth_requestPasswordRecovery::ReturnType auth_requestPasswordRecovery::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<auth_passwordRecovery>, 326715557>::parse(p);
#undef FAIL
}

bots_canSendMessage::bots_canSendMessage(object_ptr<InputUser> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t bots_canSendMessage::ID;

void bots_canSendMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(324662502);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_canSendMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(324662502);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_canSendMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.canSendMessage");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

bots_canSendMessage::ReturnType bots_canSendMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_exportBotToken::bots_exportBotToken(object_ptr<InputUser> &&bot_, bool revoke_)
  : bot_(std::move(bot_))
  , revoke_(revoke_)
{}

const std::int32_t bots_exportBotToken::ID;

void bots_exportBotToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1123182101);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBool::store(revoke_, s);
}

void bots_exportBotToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1123182101);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBool::store(revoke_, s);
}

void bots_exportBotToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.exportBotToken");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("revoke", revoke_);
    s.store_class_end();
  }
}

bots_exportBotToken::ReturnType bots_exportBotToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<bots_exportedBotToken>, 1012971041>::parse(p);
#undef FAIL
}

bots_toggleUserEmojiStatusPermission::bots_toggleUserEmojiStatusPermission(object_ptr<InputUser> &&bot_, bool enabled_)
  : bot_(std::move(bot_))
  , enabled_(enabled_)
{}

const std::int32_t bots_toggleUserEmojiStatusPermission::ID;

void bots_toggleUserEmojiStatusPermission::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(115237778);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBool::store(enabled_, s);
}

void bots_toggleUserEmojiStatusPermission::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(115237778);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBool::store(enabled_, s);
}

void bots_toggleUserEmojiStatusPermission::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.toggleUserEmojiStatusPermission");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

bots_toggleUserEmojiStatusPermission::ReturnType bots_toggleUserEmojiStatusPermission::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_checkSearchPostsFlood::channels_checkSearchPostsFlood(int32 flags_, string const &query_)
  : flags_(flags_)
  , query_(query_)
{}

const std::int32_t channels_checkSearchPostsFlood::ID;

void channels_checkSearchPostsFlood::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(576090389);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(query_, s); }
}

void channels_checkSearchPostsFlood::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(576090389);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(query_, s); }
}

void channels_checkSearchPostsFlood::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.checkSearchPostsFlood");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("query", query_); }
    s.store_class_end();
  }
}

channels_checkSearchPostsFlood::ReturnType channels_checkSearchPostsFlood::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<searchPostsFlood>, 1040931690>::parse(p);
#undef FAIL
}

channels_getParticipant::channels_getParticipant(object_ptr<InputChannel> &&channel_, object_ptr<InputPeer> &&participant_)
  : channel_(std::move(channel_))
  , participant_(std::move(participant_))
{}

const std::int32_t channels_getParticipant::ID;

void channels_getParticipant::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1599378234);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void channels_getParticipant::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1599378234);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void channels_getParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getParticipant");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

channels_getParticipant::ReturnType channels_getParticipant::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<channels_channelParticipant>, -541588713>::parse(p);
#undef FAIL
}

chatlists_exportChatlistInvite::chatlists_exportChatlistInvite(object_ptr<inputChatlistDialogFilter> &&chatlist_, string const &title_, array<object_ptr<InputPeer>> &&peers_)
  : chatlist_(std::move(chatlist_))
  , title_(title_)
  , peers_(std::move(peers_))
{}

const std::int32_t chatlists_exportChatlistInvite::ID;

void chatlists_exportChatlistInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2072885362);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_exportChatlistInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2072885362);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_exportChatlistInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.exportChatlistInvite");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_field("title", title_);
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatlists_exportChatlistInvite::ReturnType chatlists_exportChatlistInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<chatlists_exportedChatlistInvite>, 283567014>::parse(p);
#undef FAIL
}

chatlists_joinChatlistUpdates::chatlists_joinChatlistUpdates(object_ptr<inputChatlistDialogFilter> &&chatlist_, array<object_ptr<InputPeer>> &&peers_)
  : chatlist_(std::move(chatlist_))
  , peers_(std::move(peers_))
{}

const std::int32_t chatlists_joinChatlistUpdates::ID;

void chatlists_joinChatlistUpdates::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-527828747);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_joinChatlistUpdates::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-527828747);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peers_, s);
}

void chatlists_joinChatlistUpdates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.joinChatlistUpdates");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatlists_joinChatlistUpdates::ReturnType chatlists_joinChatlistUpdates::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

contacts_blockFromReplies::contacts_blockFromReplies(int32 flags_, bool delete_message_, bool delete_history_, bool report_spam_, int32 msg_id_)
  : flags_(flags_)
  , delete_message_(delete_message_)
  , delete_history_(delete_history_)
  , report_spam_(report_spam_)
  , msg_id_(msg_id_)
{}

const std::int32_t contacts_blockFromReplies::ID;

void contacts_blockFromReplies::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(698914348);
  TlStoreBinary::store((var0 = flags_ | (delete_message_ << 0) | (delete_history_ << 1) | (report_spam_ << 2)), s);
  TlStoreBinary::store(msg_id_, s);
}

void contacts_blockFromReplies::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(698914348);
  TlStoreBinary::store((var0 = flags_ | (delete_message_ << 0) | (delete_history_ << 1) | (report_spam_ << 2)), s);
  TlStoreBinary::store(msg_id_, s);
}

void contacts_blockFromReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.blockFromReplies");
    s.store_field("flags", (var0 = flags_ | (delete_message_ << 0) | (delete_history_ << 1) | (report_spam_ << 2)));
    if (var0 & 1) { s.store_field("delete_message", true); }
    if (var0 & 2) { s.store_field("delete_history", true); }
    if (var0 & 4) { s.store_field("report_spam", true); }
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

contacts_blockFromReplies::ReturnType contacts_blockFromReplies::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t contacts_getStatuses::ID;

void contacts_getStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-995929106);
}

void contacts_getStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-995929106);
}

void contacts_getStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getStatuses");
    s.store_class_end();
  }
}

contacts_getStatuses::ReturnType contacts_getStatuses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<contactStatus>, 383348795>>, 481674261>::parse(p);
#undef FAIL
}

contacts_resetTopPeerRating::contacts_resetTopPeerRating(object_ptr<TopPeerCategory> &&category_, object_ptr<InputPeer> &&peer_)
  : category_(std::move(category_))
  , peer_(std::move(peer_))
{}

const std::int32_t contacts_resetTopPeerRating::ID;

void contacts_resetTopPeerRating::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(451113900);
  TlStoreBoxedUnknown<TlStoreObject>::store(category_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void contacts_resetTopPeerRating::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(451113900);
  TlStoreBoxedUnknown<TlStoreObject>::store(category_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void contacts_resetTopPeerRating::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.resetTopPeerRating");
    s.store_object_field("category", static_cast<const BaseObject *>(category_.get()));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

contacts_resetTopPeerRating::ReturnType contacts_resetTopPeerRating::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

contacts_unblock::contacts_unblock(int32 flags_, bool my_stories_from_, object_ptr<InputPeer> &&id_)
  : flags_(flags_)
  , my_stories_from_(my_stories_from_)
  , id_(std::move(id_))
{}

const std::int32_t contacts_unblock::ID;

void contacts_unblock::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1252994264);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void contacts_unblock::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1252994264);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void contacts_unblock::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.unblock");
    s.store_field("flags", (var0 = flags_ | (my_stories_from_ << 0)));
    if (var0 & 1) { s.store_field("my_stories_from", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

contacts_unblock::ReturnType contacts_unblock::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

contacts_updateContactNote::contacts_updateContactNote(object_ptr<InputUser> &&id_, object_ptr<textWithEntities> &&note_)
  : id_(std::move(id_))
  , note_(std::move(note_))
{}

const std::int32_t contacts_updateContactNote::ID;

void contacts_updateContactNote::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(329212923);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(note_, s);
}

void contacts_updateContactNote::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(329212923);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(note_, s);
}

void contacts_updateContactNote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.updateContactNote");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_object_field("note", static_cast<const BaseObject *>(note_.get()));
    s.store_class_end();
  }
}

contacts_updateContactNote::ReturnType contacts_updateContactNote::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t help_getInviteText::ID;

void help_getInviteText::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1295590211);
}

void help_getInviteText::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1295590211);
}

void help_getInviteText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getInviteText");
    s.store_class_end();
  }
}

help_getInviteText::ReturnType help_getInviteText::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<help_inviteText>, 415997816>::parse(p);
#undef FAIL
}

const std::int32_t help_getPremiumPromo::ID;

void help_getPremiumPromo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1206152236);
}

void help_getPremiumPromo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1206152236);
}

void help_getPremiumPromo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getPremiumPromo");
    s.store_class_end();
  }
}

help_getPremiumPromo::ReturnType help_getPremiumPromo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<help_premiumPromo>, 1395946908>::parse(p);
#undef FAIL
}

langpack_getDifference::langpack_getDifference(string const &lang_pack_, string const &lang_code_, int32 from_version_)
  : lang_pack_(lang_pack_)
  , lang_code_(lang_code_)
  , from_version_(from_version_)
{}

const std::int32_t langpack_getDifference::ID;

void langpack_getDifference::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-845657435);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBinary::store(from_version_, s);
}

void langpack_getDifference::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-845657435);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBinary::store(from_version_, s);
}

void langpack_getDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langpack.getDifference");
    s.store_field("lang_pack", lang_pack_);
    s.store_field("lang_code", lang_code_);
    s.store_field("from_version", from_version_);
    s.store_class_end();
  }
}

langpack_getDifference::ReturnType langpack_getDifference::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<langPackDifference>, -209337866>::parse(p);
#undef FAIL
}

const std::int32_t messages_clearRecentReactions::ID;

void messages_clearRecentReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1644236876);
}

void messages_clearRecentReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1644236876);
}

void messages_clearRecentReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.clearRecentReactions");
    s.store_class_end();
  }
}

messages_clearRecentReactions::ReturnType messages_clearRecentReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_deleteTopicHistory::messages_deleteTopicHistory(object_ptr<InputPeer> &&peer_, int32 top_msg_id_)
  : peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
{}

const std::int32_t messages_deleteTopicHistory::ID;

void messages_deleteTopicHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-763269360);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(top_msg_id_, s);
}

void messages_deleteTopicHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-763269360);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(top_msg_id_, s);
}

void messages_deleteTopicHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteTopicHistory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_msg_id", top_msg_id_);
    s.store_class_end();
  }
}

messages_deleteTopicHistory::ReturnType messages_deleteTopicHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_editExportedChatInvite::messages_editExportedChatInvite(int32 flags_, bool revoked_, object_ptr<InputPeer> &&peer_, string const &link_, int32 expire_date_, int32 usage_limit_, bool request_needed_, string const &title_)
  : flags_(flags_)
  , revoked_(revoked_)
  , peer_(std::move(peer_))
  , link_(link_)
  , expire_date_(expire_date_)
  , usage_limit_(usage_limit_)
  , request_needed_(request_needed_)
  , title_(title_)
{}

const std::int32_t messages_editExportedChatInvite::ID;

void messages_editExportedChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1110823051);
  TlStoreBinary::store((var0 = flags_ | (revoked_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
  if (var0 & 1) { TlStoreBinary::store(expire_date_, s); }
  if (var0 & 2) { TlStoreBinary::store(usage_limit_, s); }
  if (var0 & 8) { TlStoreBool::store(request_needed_, s); }
  if (var0 & 16) { TlStoreString::store(title_, s); }
}

void messages_editExportedChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1110823051);
  TlStoreBinary::store((var0 = flags_ | (revoked_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
  if (var0 & 1) { TlStoreBinary::store(expire_date_, s); }
  if (var0 & 2) { TlStoreBinary::store(usage_limit_, s); }
  if (var0 & 8) { TlStoreBool::store(request_needed_, s); }
  if (var0 & 16) { TlStoreString::store(title_, s); }
}

void messages_editExportedChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editExportedChatInvite");
    s.store_field("flags", (var0 = flags_ | (revoked_ << 2)));
    if (var0 & 4) { s.store_field("revoked", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("link", link_);
    if (var0 & 1) { s.store_field("expire_date", expire_date_); }
    if (var0 & 2) { s.store_field("usage_limit", usage_limit_); }
    if (var0 & 8) { s.store_field("request_needed", request_needed_); }
    if (var0 & 16) { s.store_field("title", title_); }
    s.store_class_end();
  }
}

messages_editExportedChatInvite::ReturnType messages_editExportedChatInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_ExportedChatInvite>::parse(p);
#undef FAIL
}

messages_getDocumentByHash::messages_getDocumentByHash(bytes &&sha256_, int64 size_, string const &mime_type_)
  : sha256_(std::move(sha256_))
  , size_(size_)
  , mime_type_(mime_type_)
{}

const std::int32_t messages_getDocumentByHash::ID;

void messages_getDocumentByHash::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1309538785);
  TlStoreString::store(sha256_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
}

void messages_getDocumentByHash::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1309538785);
  TlStoreString::store(sha256_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
}

void messages_getDocumentByHash::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDocumentByHash");
    s.store_bytes_field("sha256", sha256_);
    s.store_field("size", size_);
    s.store_field("mime_type", mime_type_);
    s.store_class_end();
  }
}

messages_getDocumentByHash::ReturnType messages_getDocumentByHash::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Document>::parse(p);
#undef FAIL
}

messages_getEmojiStickers::messages_getEmojiStickers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getEmojiStickers::ID;

void messages_getEmojiStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-67329649);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-67329649);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiStickers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getEmojiStickers::ReturnType messages_getEmojiStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_AllStickers>::parse(p);
#undef FAIL
}

messages_getExtendedMedia::messages_getExtendedMedia(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t messages_getExtendedMedia::ID;

void messages_getExtendedMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2064119788);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getExtendedMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2064119788);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getExtendedMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getExtendedMedia");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getExtendedMedia::ReturnType messages_getExtendedMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getInlineBotResults::messages_getInlineBotResults(int32 flags_, object_ptr<InputUser> &&bot_, object_ptr<InputPeer> &&peer_, object_ptr<InputGeoPoint> &&geo_point_, string const &query_, string const &offset_)
  : flags_(flags_)
  , bot_(std::move(bot_))
  , peer_(std::move(peer_))
  , geo_point_(std::move(geo_point_))
  , query_(query_)
  , offset_(offset_)
{}

const std::int32_t messages_getInlineBotResults::ID;

void messages_getInlineBotResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1364105629);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s); }
  TlStoreString::store(query_, s);
  TlStoreString::store(offset_, s);
}

void messages_getInlineBotResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1364105629);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s); }
  TlStoreString::store(query_, s);
  TlStoreString::store(offset_, s);
}

void messages_getInlineBotResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getInlineBotResults");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get())); }
    s.store_field("query", query_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

messages_getInlineBotResults::ReturnType messages_getInlineBotResults::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_botResults>, -534646026>::parse(p);
#undef FAIL
}

messages_getSavedReactionTags::messages_getSavedReactionTags(int32 flags_, object_ptr<InputPeer> &&peer_, int64 hash_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , hash_(hash_)
{}

const std::int32_t messages_getSavedReactionTags::ID;

void messages_getSavedReactionTags::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(909631579);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedReactionTags::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(909631579);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedReactionTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSavedReactionTags");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getSavedReactionTags::ReturnType messages_getSavedReactionTags::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SavedReactionTags>::parse(p);
#undef FAIL
}

messages_getSponsoredMessages::messages_getSponsoredMessages(int32 flags_, object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t messages_getSponsoredMessages::ID;

void messages_getSponsoredMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1030547536);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(msg_id_, s); }
}

void messages_getSponsoredMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1030547536);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(msg_id_, s); }
}

void messages_getSponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSponsoredMessages");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("msg_id", msg_id_); }
    s.store_class_end();
  }
}

messages_getSponsoredMessages::ReturnType messages_getSponsoredMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SponsoredMessages>::parse(p);
#undef FAIL
}

messages_getUnreadReactions::messages_getUnreadReactions(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_, object_ptr<InputPeer> &&saved_peer_id_, int32 offset_id_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
  , saved_peer_id_(std::move(saved_peer_id_))
  , offset_id_(offset_id_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
{}

const std::int32_t messages_getUnreadReactions::ID;

void messages_getUnreadReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1115713364);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
}

void messages_getUnreadReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1115713364);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
}

void messages_getUnreadReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getUnreadReactions");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_field("offset_id", offset_id_);
    s.store_field("add_offset", add_offset_);
    s.store_field("limit", limit_);
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_class_end();
  }
}

messages_getUnreadReactions::ReturnType messages_getUnreadReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_reorderQuickReplies::messages_reorderQuickReplies(array<int32> &&order_)
  : order_(std::move(order_))
{}

const std::int32_t messages_reorderQuickReplies::ID;

void messages_reorderQuickReplies::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1613961479);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_reorderQuickReplies::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1613961479);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_reorderQuickReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reorderQuickReplies");
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reorderQuickReplies::ReturnType messages_reorderQuickReplies::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_reportSponsoredMessage::messages_reportSponsoredMessage(bytes &&random_id_, bytes &&option_)
  : random_id_(std::move(random_id_))
  , option_(std::move(option_))
{}

const std::int32_t messages_reportSponsoredMessage::ID;

void messages_reportSponsoredMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(315355332);
  TlStoreString::store(random_id_, s);
  TlStoreString::store(option_, s);
}

void messages_reportSponsoredMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(315355332);
  TlStoreString::store(random_id_, s);
  TlStoreString::store(option_, s);
}

void messages_reportSponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportSponsoredMessage");
    s.store_bytes_field("random_id", random_id_);
    s.store_bytes_field("option", option_);
    s.store_class_end();
  }
}

messages_reportSponsoredMessage::ReturnType messages_reportSponsoredMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<channels_SponsoredMessageReportResult>::parse(p);
#undef FAIL
}

messages_requestAppWebView::messages_requestAppWebView(int32 flags_, bool write_allowed_, bool compact_, bool fullscreen_, object_ptr<InputPeer> &&peer_, object_ptr<InputBotApp> &&app_, string const &start_param_, object_ptr<dataJSON> &&theme_params_, string const &platform_)
  : flags_(flags_)
  , write_allowed_(write_allowed_)
  , compact_(compact_)
  , fullscreen_(fullscreen_)
  , peer_(std::move(peer_))
  , app_(std::move(app_))
  , start_param_(start_param_)
  , theme_params_(std::move(theme_params_))
  , platform_(platform_)
{}

const std::int32_t messages_requestAppWebView::ID;

void messages_requestAppWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1398901710);
  TlStoreBinary::store((var0 = flags_ | (write_allowed_ << 0) | (compact_ << 7) | (fullscreen_ << 8)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(app_, s);
  if (var0 & 2) { TlStoreString::store(start_param_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestAppWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1398901710);
  TlStoreBinary::store((var0 = flags_ | (write_allowed_ << 0) | (compact_ << 7) | (fullscreen_ << 8)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(app_, s);
  if (var0 & 2) { TlStoreString::store(start_param_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestAppWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestAppWebView");
    s.store_field("flags", (var0 = flags_ | (write_allowed_ << 0) | (compact_ << 7) | (fullscreen_ << 8)));
    if (var0 & 1) { s.store_field("write_allowed", true); }
    if (var0 & 128) { s.store_field("compact", true); }
    if (var0 & 256) { s.store_field("fullscreen", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("app", static_cast<const BaseObject *>(app_.get()));
    if (var0 & 2) { s.store_field("start_param", start_param_); }
    if (var0 & 4) { s.store_object_field("theme_params", static_cast<const BaseObject *>(theme_params_.get())); }
    s.store_field("platform", platform_);
    s.store_class_end();
  }
}

messages_requestAppWebView::ReturnType messages_requestAppWebView::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<webViewResultUrl>, 1294139288>::parse(p);
#undef FAIL
}

messages_searchCustomEmoji::messages_searchCustomEmoji(string const &emoticon_, int64 hash_)
  : emoticon_(emoticon_)
  , hash_(hash_)
{}

const std::int32_t messages_searchCustomEmoji::ID;

void messages_searchCustomEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(739360983);
  TlStoreString::store(emoticon_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchCustomEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(739360983);
  TlStoreString::store(emoticon_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchCustomEmoji");
    s.store_field("emoticon", emoticon_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_searchCustomEmoji::ReturnType messages_searchCustomEmoji::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EmojiList>::parse(p);
#undef FAIL
}

messages_sendPaidReaction::messages_sendPaidReaction(int32 flags_, object_ptr<InputPeer> &&peer_, int32 msg_id_, int32 count_, int64 random_id_, object_ptr<PaidReactionPrivacy> &&private_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , count_(count_)
  , random_id_(random_id_)
  , private_(std::move(private_))
{}

const std::int32_t messages_sendPaidReaction::ID;

void messages_sendPaidReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1488702288);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(count_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(private_, s); }
}

void messages_sendPaidReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1488702288);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(count_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(private_, s); }
}

void messages_sendPaidReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendPaidReaction");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("count", count_);
    s.store_field("random_id", random_id_);
    if (var0 & 1) { s.store_object_field("private", static_cast<const BaseObject *>(private_.get())); }
    s.store_class_end();
  }
}

messages_sendPaidReaction::ReturnType messages_sendPaidReaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_sendScheduledMessages::messages_sendScheduledMessages(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t messages_sendScheduledMessages::ID;

void messages_sendScheduledMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1120369398);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_sendScheduledMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1120369398);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_sendScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendScheduledMessages");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_sendScheduledMessages::ReturnType messages_sendScheduledMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setInlineGameScore::messages_setInlineGameScore(int32 flags_, bool edit_message_, bool force_, object_ptr<InputBotInlineMessageID> &&id_, object_ptr<InputUser> &&user_id_, int32 score_)
  : flags_(flags_)
  , edit_message_(edit_message_)
  , force_(force_)
  , id_(std::move(id_))
  , user_id_(std::move(user_id_))
  , score_(score_)
{}

const std::int32_t messages_setInlineGameScore::ID;

void messages_setInlineGameScore::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(363700068);
  TlStoreBinary::store((var0 = flags_ | (edit_message_ << 0) | (force_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(score_, s);
}

void messages_setInlineGameScore::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(363700068);
  TlStoreBinary::store((var0 = flags_ | (edit_message_ << 0) | (force_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(score_, s);
}

void messages_setInlineGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setInlineGameScore");
    s.store_field("flags", (var0 = flags_ | (edit_message_ << 0) | (force_ << 1)));
    if (var0 & 1) { s.store_field("edit_message", true); }
    if (var0 & 2) { s.store_field("force", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("score", score_);
    s.store_class_end();
  }
}

messages_setInlineGameScore::ReturnType messages_setInlineGameScore::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_startBot::messages_startBot(object_ptr<InputUser> &&bot_, object_ptr<InputPeer> &&peer_, int64 random_id_, string const &start_param_)
  : bot_(std::move(bot_))
  , peer_(std::move(peer_))
  , random_id_(random_id_)
  , start_param_(start_param_)
{}

const std::int32_t messages_startBot::ID;

void messages_startBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-421563528);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(start_param_, s);
}

void messages_startBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-421563528);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(start_param_, s);
}

void messages_startBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.startBot");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("random_id", random_id_);
    s.store_field("start_param", start_param_);
    s.store_class_end();
  }
}

messages_startBot::ReturnType messages_startBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_toggleDialogFilterTags::messages_toggleDialogFilterTags(bool enabled_)
  : enabled_(enabled_)
{}

const std::int32_t messages_toggleDialogFilterTags::ID;

void messages_toggleDialogFilterTags::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-47326647);
  TlStoreBool::store(enabled_, s);
}

void messages_toggleDialogFilterTags::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-47326647);
  TlStoreBool::store(enabled_, s);
}

void messages_toggleDialogFilterTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleDialogFilterTags");
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

messages_toggleDialogFilterTags::ReturnType messages_toggleDialogFilterTags::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_toggleTodoCompleted::messages_toggleTodoCompleted(object_ptr<InputPeer> &&peer_, int32 msg_id_, array<int32> &&completed_, array<int32> &&incompleted_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , completed_(std::move(completed_))
  , incompleted_(std::move(incompleted_))
{}

const std::int32_t messages_toggleTodoCompleted::ID;

void messages_toggleTodoCompleted::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-740282076);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(completed_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(incompleted_, s);
}

void messages_toggleTodoCompleted::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-740282076);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(completed_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(incompleted_, s);
}

void messages_toggleTodoCompleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleTodoCompleted");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    { s.store_vector_begin("completed", completed_.size()); for (const auto &_value : completed_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("incompleted", incompleted_.size()); for (const auto &_value : incompleted_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_toggleTodoCompleted::ReturnType messages_toggleTodoCompleted::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_updateDialogFilter::messages_updateDialogFilter(int32 flags_, int32 id_, object_ptr<DialogFilter> &&filter_)
  : flags_(flags_)
  , id_(id_)
  , filter_(std::move(filter_))
{}

const std::int32_t messages_updateDialogFilter::ID;

void messages_updateDialogFilter::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(450142282);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s); }
}

void messages_updateDialogFilter::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(450142282);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s); }
}

void messages_updateDialogFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.updateDialogFilter");
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get())); }
    s.store_class_end();
  }
}

messages_updateDialogFilter::ReturnType messages_updateDialogFilter::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_viewSponsoredMessage::messages_viewSponsoredMessage(bytes &&random_id_)
  : random_id_(std::move(random_id_))
{}

const std::int32_t messages_viewSponsoredMessage::ID;

void messages_viewSponsoredMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(647902787);
  TlStoreString::store(random_id_, s);
}

void messages_viewSponsoredMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(647902787);
  TlStoreString::store(random_id_, s);
}

void messages_viewSponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.viewSponsoredMessage");
    s.store_bytes_field("random_id", random_id_);
    s.store_class_end();
  }
}

messages_viewSponsoredMessage::ReturnType messages_viewSponsoredMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_getStarsRevenueAdsAccountUrl::payments_getStarsRevenueAdsAccountUrl(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t payments_getStarsRevenueAdsAccountUrl::ID;

void payments_getStarsRevenueAdsAccountUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-774377531);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_getStarsRevenueAdsAccountUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-774377531);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_getStarsRevenueAdsAccountUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsRevenueAdsAccountUrl");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

payments_getStarsRevenueAdsAccountUrl::ReturnType payments_getStarsRevenueAdsAccountUrl::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsRevenueAdsAccountUrl>, 961445665>::parse(p);
#undef FAIL
}

payments_getUniqueStarGiftValueInfo::payments_getUniqueStarGiftValueInfo(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t payments_getUniqueStarGiftValueInfo::ID;

void payments_getUniqueStarGiftValueInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1130737515);
  TlStoreString::store(slug_, s);
}

void payments_getUniqueStarGiftValueInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1130737515);
  TlStoreString::store(slug_, s);
}

void payments_getUniqueStarGiftValueInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getUniqueStarGiftValueInfo");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

payments_getUniqueStarGiftValueInfo::ReturnType payments_getUniqueStarGiftValueInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_uniqueStarGiftValueInfo>, 1362093126>::parse(p);
#undef FAIL
}

payments_sendStarGiftOffer::payments_sendStarGiftOffer(int32 flags_, object_ptr<InputPeer> &&peer_, string const &slug_, object_ptr<StarsAmount> &&price_, int32 duration_, int64 random_id_, int64 allow_paid_stars_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , slug_(slug_)
  , price_(std::move(price_))
  , duration_(duration_)
  , random_id_(random_id_)
  , allow_paid_stars_(allow_paid_stars_)
{}

const std::int32_t payments_sendStarGiftOffer::ID;

void payments_sendStarGiftOffer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1883739327);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(slug_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(price_, s);
  TlStoreBinary::store(duration_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 1) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void payments_sendStarGiftOffer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1883739327);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(slug_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(price_, s);
  TlStoreBinary::store(duration_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 1) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void payments_sendStarGiftOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.sendStarGiftOffer");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("slug", slug_);
    s.store_object_field("price", static_cast<const BaseObject *>(price_.get()));
    s.store_field("duration", duration_);
    s.store_field("random_id", random_id_);
    if (var0 & 1) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    s.store_class_end();
  }
}

payments_sendStarGiftOffer::ReturnType payments_sendStarGiftOffer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_sendStarsForm::payments_sendStarsForm(int64 form_id_, object_ptr<InputInvoice> &&invoice_)
  : form_id_(form_id_)
  , invoice_(std::move(invoice_))
{}

const std::int32_t payments_sendStarsForm::ID;

void payments_sendStarsForm::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2040056084);
  TlStoreBinary::store(form_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
}

void payments_sendStarsForm::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2040056084);
  TlStoreBinary::store(form_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
}

void payments_sendStarsForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.sendStarsForm");
    s.store_field("form_id", form_id_);
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_class_end();
  }
}

payments_sendStarsForm::ReturnType payments_sendStarsForm::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_PaymentResult>::parse(p);
#undef FAIL
}

phone_createGroupCall::phone_createGroupCall(int32 flags_, bool rtmp_stream_, object_ptr<InputPeer> &&peer_, int32 random_id_, string const &title_, int32 schedule_date_)
  : flags_(flags_)
  , rtmp_stream_(rtmp_stream_)
  , peer_(std::move(peer_))
  , random_id_(random_id_)
  , title_(title_)
  , schedule_date_(schedule_date_)
{}

const std::int32_t phone_createGroupCall::ID;

void phone_createGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1221445336);
  TlStoreBinary::store((var0 = flags_ | (rtmp_stream_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBinary::store(schedule_date_, s); }
}

void phone_createGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1221445336);
  TlStoreBinary::store((var0 = flags_ | (rtmp_stream_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBinary::store(schedule_date_, s); }
}

void phone_createGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.createGroupCall");
    s.store_field("flags", (var0 = flags_ | (rtmp_stream_ << 2)));
    if (var0 & 4) { s.store_field("rtmp_stream", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("random_id", random_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("schedule_date", schedule_date_); }
    s.store_class_end();
  }
}

phone_createGroupCall::ReturnType phone_createGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_discardGroupCall::phone_discardGroupCall(object_ptr<InputGroupCall> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t phone_discardGroupCall::ID;

void phone_discardGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2054648117);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_discardGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2054648117);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_discardGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.discardGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

phone_discardGroupCall::ReturnType phone_discardGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_exportGroupCallInvite::phone_exportGroupCallInvite(int32 flags_, bool can_self_unmute_, object_ptr<InputGroupCall> &&call_)
  : flags_(flags_)
  , can_self_unmute_(can_self_unmute_)
  , call_(std::move(call_))
{}

const std::int32_t phone_exportGroupCallInvite::ID;

void phone_exportGroupCallInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-425040769);
  TlStoreBinary::store((var0 = flags_ | (can_self_unmute_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_exportGroupCallInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-425040769);
  TlStoreBinary::store((var0 = flags_ | (can_self_unmute_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_exportGroupCallInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.exportGroupCallInvite");
    s.store_field("flags", (var0 = flags_ | (can_self_unmute_ << 0)));
    if (var0 & 1) { s.store_field("can_self_unmute", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

phone_exportGroupCallInvite::ReturnType phone_exportGroupCallInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_exportedGroupCallInvite>, 541839704>::parse(p);
#undef FAIL
}

phone_getGroupParticipants::phone_getGroupParticipants(object_ptr<InputGroupCall> &&call_, array<object_ptr<InputPeer>> &&ids_, array<int32> &&sources_, string const &offset_, int32 limit_)
  : call_(std::move(call_))
  , ids_(std::move(ids_))
  , sources_(std::move(sources_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t phone_getGroupParticipants::ID;

void phone_getGroupParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-984033109);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(ids_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(sources_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void phone_getGroupParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-984033109);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(ids_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(sources_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void phone_getGroupParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupParticipants");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("ids", ids_.size()); for (const auto &_value : ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("sources", sources_.size()); for (const auto &_value : sources_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

phone_getGroupParticipants::ReturnType phone_getGroupParticipants::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_groupParticipants>, -193506890>::parse(p);
#undef FAIL
}

phone_saveDefaultSendAs::phone_saveDefaultSendAs(object_ptr<InputGroupCall> &&call_, object_ptr<InputPeer> &&send_as_)
  : call_(std::move(call_))
  , send_as_(std::move(send_as_))
{}

const std::int32_t phone_saveDefaultSendAs::ID;

void phone_saveDefaultSendAs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1097313745);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s);
}

void phone_saveDefaultSendAs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1097313745);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s);
}

void phone_saveDefaultSendAs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.saveDefaultSendAs");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get()));
    s.store_class_end();
  }
}

phone_saveDefaultSendAs::ReturnType phone_saveDefaultSendAs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_sendGroupCallMessage::phone_sendGroupCallMessage(int32 flags_, object_ptr<InputGroupCall> &&call_, int64 random_id_, object_ptr<textWithEntities> &&message_, int64 allow_paid_stars_, object_ptr<InputPeer> &&send_as_)
  : flags_(flags_)
  , call_(std::move(call_))
  , random_id_(random_id_)
  , message_(std::move(message_))
  , allow_paid_stars_(allow_paid_stars_)
  , send_as_(std::move(send_as_))
{}

const std::int32_t phone_sendGroupCallMessage::ID;

void phone_sendGroupCallMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1311697904);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s);
  if (var0 & 1) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void phone_sendGroupCallMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1311697904);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s);
  if (var0 & 1) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void phone_sendGroupCallMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.sendGroupCallMessage");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("random_id", random_id_);
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    if (var0 & 1) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    if (var0 & 2) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    s.store_class_end();
  }
}

phone_sendGroupCallMessage::ReturnType phone_sendGroupCallMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_startScheduledGroupCall::phone_startScheduledGroupCall(object_ptr<InputGroupCall> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t phone_startScheduledGroupCall::ID;

void phone_startScheduledGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1451287362);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_startScheduledGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1451287362);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_startScheduledGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.startScheduledGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

phone_startScheduledGroupCall::ReturnType phone_startScheduledGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

premium_getBoostsList::premium_getBoostsList(int32 flags_, bool gifts_, object_ptr<InputPeer> &&peer_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , gifts_(gifts_)
  , peer_(std::move(peer_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t premium_getBoostsList::ID;

void premium_getBoostsList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1626764896);
  TlStoreBinary::store((var0 = flags_ | (gifts_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void premium_getBoostsList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1626764896);
  TlStoreBinary::store((var0 = flags_ | (gifts_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void premium_getBoostsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.getBoostsList");
    s.store_field("flags", (var0 = flags_ | (gifts_ << 0)));
    if (var0 & 1) { s.store_field("gifts", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

premium_getBoostsList::ReturnType premium_getBoostsList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<premium_boostsList>, -2030542532>::parse(p);
#undef FAIL
}

const std::int32_t smsjobs_join::ID;

void smsjobs_join::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1488007635);
}

void smsjobs_join::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1488007635);
}

void smsjobs_join::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.join");
    s.store_class_end();
  }
}

smsjobs_join::ReturnType smsjobs_join::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stickers_deleteStickerSet::stickers_deleteStickerSet(object_ptr<InputStickerSet> &&stickerset_)
  : stickerset_(std::move(stickerset_))
{}

const std::int32_t stickers_deleteStickerSet::ID;

void stickers_deleteStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2022685804);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void stickers_deleteStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2022685804);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void stickers_deleteStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.deleteStickerSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_class_end();
  }
}

stickers_deleteStickerSet::ReturnType stickers_deleteStickerSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stickers_setStickerSetThumb::stickers_setStickerSetThumb(int32 flags_, object_ptr<InputStickerSet> &&stickerset_, object_ptr<InputDocument> &&thumb_, int64 thumb_document_id_)
  : flags_(flags_)
  , stickerset_(std::move(stickerset_))
  , thumb_(std::move(thumb_))
  , thumb_document_id_(thumb_document_id_)
{}

const std::int32_t stickers_setStickerSetThumb::ID;

void stickers_setStickerSetThumb::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1486204014);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  if (var0 & 2) { TlStoreBinary::store(thumb_document_id_, s); }
}

void stickers_setStickerSetThumb::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1486204014);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  if (var0 & 2) { TlStoreBinary::store(thumb_document_id_, s); }
}

void stickers_setStickerSetThumb::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.setStickerSetThumb");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    if (var0 & 1) { s.store_object_field("thumb", static_cast<const BaseObject *>(thumb_.get())); }
    if (var0 & 2) { s.store_field("thumb_document_id", thumb_document_id_); }
    s.store_class_end();
  }
}

stickers_setStickerSetThumb::ReturnType stickers_setStickerSetThumb::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stories_getAlbums::stories_getAlbums(object_ptr<InputPeer> &&peer_, int64 hash_)
  : peer_(std::move(peer_))
  , hash_(hash_)
{}

const std::int32_t stories_getAlbums::ID;

void stories_getAlbums::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(632548039);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void stories_getAlbums::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(632548039);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void stories_getAlbums::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getAlbums");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

stories_getAlbums::ReturnType stories_getAlbums::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<stories_Albums>::parse(p);
#undef FAIL
}

stories_getPinnedStories::stories_getPinnedStories(object_ptr<InputPeer> &&peer_, int32 offset_id_, int32 limit_)
  : peer_(std::move(peer_))
  , offset_id_(offset_id_)
  , limit_(limit_)
{}

const std::int32_t stories_getPinnedStories::ID;

void stories_getPinnedStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1478600156);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getPinnedStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1478600156);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getPinnedStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getPinnedStories");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stories_getPinnedStories::ReturnType stories_getPinnedStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_stories>, 1673780490>::parse(p);
#undef FAIL
}

stories_sendReaction::stories_sendReaction(int32 flags_, bool add_to_recent_, object_ptr<InputPeer> &&peer_, int32 story_id_, object_ptr<Reaction> &&reaction_)
  : flags_(flags_)
  , add_to_recent_(add_to_recent_)
  , peer_(std::move(peer_))
  , story_id_(story_id_)
  , reaction_(std::move(reaction_))
{}

const std::int32_t stories_sendReaction::ID;

void stories_sendReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2144810674);
  TlStoreBinary::store((var0 = flags_ | (add_to_recent_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(story_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
}

void stories_sendReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2144810674);
  TlStoreBinary::store((var0 = flags_ | (add_to_recent_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(story_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
}

void stories_sendReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.sendReaction");
    s.store_field("flags", (var0 = flags_ | (add_to_recent_ << 0)));
    if (var0 & 1) { s.store_field("add_to_recent", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("story_id", story_id_);
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

stories_sendReaction::ReturnType stories_sendReaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

stories_togglePeerStoriesHidden::stories_togglePeerStoriesHidden(object_ptr<InputPeer> &&peer_, bool hidden_)
  : peer_(std::move(peer_))
  , hidden_(hidden_)
{}

const std::int32_t stories_togglePeerStoriesHidden::ID;

void stories_togglePeerStoriesHidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1123805756);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(hidden_, s);
}

void stories_togglePeerStoriesHidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1123805756);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(hidden_, s);
}

void stories_togglePeerStoriesHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.togglePeerStoriesHidden");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("hidden", hidden_);
    s.store_class_end();
  }
}

stories_togglePeerStoriesHidden::ReturnType stories_togglePeerStoriesHidden::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

upload_getCdnFile::upload_getCdnFile(bytes &&file_token_, int64 offset_, int32 limit_)
  : file_token_(std::move(file_token_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t upload_getCdnFile::ID;

void upload_getCdnFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(962554330);
  TlStoreString::store(file_token_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void upload_getCdnFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(962554330);
  TlStoreString::store(file_token_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void upload_getCdnFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.getCdnFile");
    s.store_bytes_field("file_token", file_token_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

upload_getCdnFile::ReturnType upload_getCdnFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<upload_CdnFile>::parse(p);
#undef FAIL
}

users_setSecureValueErrors::users_setSecureValueErrors(object_ptr<InputUser> &&id_, array<object_ptr<SecureValueError>> &&errors_)
  : id_(std::move(id_))
  , errors_(std::move(errors_))
{}

const std::int32_t users_setSecureValueErrors::ID;

void users_setSecureValueErrors::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1865902923);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(errors_, s);
}

void users_setSecureValueErrors::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1865902923);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(errors_, s);
}

void users_setSecureValueErrors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.setSecureValueErrors");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    { s.store_vector_begin("errors", errors_.size()); for (const auto &_value : errors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

users_setSecureValueErrors::ReturnType users_setSecureValueErrors::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
