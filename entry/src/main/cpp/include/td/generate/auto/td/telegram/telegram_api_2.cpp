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


attachMenuBotIcon::attachMenuBotIcon()
  : flags_()
  , name_()
  , icon_()
  , colors_()
{}

const std::int32_t attachMenuBotIcon::ID;

object_ptr<attachMenuBotIcon> attachMenuBotIcon::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<attachMenuBotIcon> res = make_tl_object<attachMenuBotIcon>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->name_ = TlFetchString<string>::parse(p);
  res->icon_ = TlFetchObject<Document>::parse(p);
  if (var0 & 1) { res->colors_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<attachMenuBotIconColor>, 1165423600>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void attachMenuBotIcon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuBotIcon");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("name", name_);
    s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get()));
    if (var0 & 1) { { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

object_ptr<AttachMenuPeerType> AttachMenuPeerType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case attachMenuPeerTypeSameBotPM::ID:
      return attachMenuPeerTypeSameBotPM::fetch(p);
    case attachMenuPeerTypeBotPM::ID:
      return attachMenuPeerTypeBotPM::fetch(p);
    case attachMenuPeerTypePM::ID:
      return attachMenuPeerTypePM::fetch(p);
    case attachMenuPeerTypeChat::ID:
      return attachMenuPeerTypeChat::fetch(p);
    case attachMenuPeerTypeBroadcast::ID:
      return attachMenuPeerTypeBroadcast::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t attachMenuPeerTypeSameBotPM::ID;

object_ptr<AttachMenuPeerType> attachMenuPeerTypeSameBotPM::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuPeerTypeSameBotPM>();
}

void attachMenuPeerTypeSameBotPM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuPeerTypeSameBotPM");
    s.store_class_end();
  }
}

const std::int32_t attachMenuPeerTypeBotPM::ID;

object_ptr<AttachMenuPeerType> attachMenuPeerTypeBotPM::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuPeerTypeBotPM>();
}

void attachMenuPeerTypeBotPM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuPeerTypeBotPM");
    s.store_class_end();
  }
}

const std::int32_t attachMenuPeerTypePM::ID;

object_ptr<AttachMenuPeerType> attachMenuPeerTypePM::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuPeerTypePM>();
}

void attachMenuPeerTypePM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuPeerTypePM");
    s.store_class_end();
  }
}

const std::int32_t attachMenuPeerTypeChat::ID;

object_ptr<AttachMenuPeerType> attachMenuPeerTypeChat::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuPeerTypeChat>();
}

void attachMenuPeerTypeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuPeerTypeChat");
    s.store_class_end();
  }
}

const std::int32_t attachMenuPeerTypeBroadcast::ID;

object_ptr<AttachMenuPeerType> attachMenuPeerTypeBroadcast::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuPeerTypeBroadcast>();
}

void attachMenuPeerTypeBroadcast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuPeerTypeBroadcast");
    s.store_class_end();
  }
}

availableReaction::availableReaction()
  : flags_()
  , inactive_()
  , premium_()
  , reaction_()
  , title_()
  , static_icon_()
  , appear_animation_()
  , select_animation_()
  , activate_animation_()
  , effect_animation_()
  , around_animation_()
  , center_icon_()
{}

const std::int32_t availableReaction::ID;

object_ptr<availableReaction> availableReaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<availableReaction> res = make_tl_object<availableReaction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inactive_ = (var0 & 1) != 0;
  res->premium_ = (var0 & 4) != 0;
  res->reaction_ = TlFetchString<string>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->static_icon_ = TlFetchObject<Document>::parse(p);
  res->appear_animation_ = TlFetchObject<Document>::parse(p);
  res->select_animation_ = TlFetchObject<Document>::parse(p);
  res->activate_animation_ = TlFetchObject<Document>::parse(p);
  res->effect_animation_ = TlFetchObject<Document>::parse(p);
  if (var0 & 2) { res->around_animation_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 2) { res->center_icon_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void availableReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableReaction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inactive_ << 0) | (premium_ << 2)));
    if (var0 & 1) { s.store_field("inactive", true); }
    if (var0 & 4) { s.store_field("premium", true); }
    s.store_field("reaction", reaction_);
    s.store_field("title", title_);
    s.store_object_field("static_icon", static_cast<const BaseObject *>(static_icon_.get()));
    s.store_object_field("appear_animation", static_cast<const BaseObject *>(appear_animation_.get()));
    s.store_object_field("select_animation", static_cast<const BaseObject *>(select_animation_.get()));
    s.store_object_field("activate_animation", static_cast<const BaseObject *>(activate_animation_.get()));
    s.store_object_field("effect_animation", static_cast<const BaseObject *>(effect_animation_.get()));
    if (var0 & 2) { s.store_object_field("around_animation", static_cast<const BaseObject *>(around_animation_.get())); }
    if (var0 & 2) { s.store_object_field("center_icon", static_cast<const BaseObject *>(center_icon_.get())); }
    s.store_class_end();
  }
}

boost::boost()
  : flags_()
  , gift_()
  , giveaway_()
  , unclaimed_()
  , id_()
  , user_id_()
  , giveaway_msg_id_()
  , date_()
  , expires_()
  , used_gift_slug_()
  , multiplier_()
  , stars_()
{}

const std::int32_t boost::ID;

object_ptr<boost> boost::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<boost> res = make_tl_object<boost>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->gift_ = (var0 & 2) != 0;
  res->giveaway_ = (var0 & 4) != 0;
  res->unclaimed_ = (var0 & 8) != 0;
  res->id_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->user_id_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->giveaway_msg_id_ = TlFetchInt::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->expires_ = TlFetchInt::parse(p);
  if (var0 & 16) { res->used_gift_slug_ = TlFetchString<string>::parse(p); }
  if (var0 & 32) { res->multiplier_ = TlFetchInt::parse(p); }
  if (var0 & 64) { res->stars_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void boost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "boost");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (gift_ << 1) | (giveaway_ << 2) | (unclaimed_ << 3)));
    if (var0 & 2) { s.store_field("gift", true); }
    if (var0 & 4) { s.store_field("giveaway", true); }
    if (var0 & 8) { s.store_field("unclaimed", true); }
    s.store_field("id", id_);
    if (var0 & 1) { s.store_field("user_id", user_id_); }
    if (var0 & 4) { s.store_field("giveaway_msg_id", giveaway_msg_id_); }
    s.store_field("date", date_);
    s.store_field("expires", expires_);
    if (var0 & 16) { s.store_field("used_gift_slug", used_gift_slug_); }
    if (var0 & 32) { s.store_field("multiplier", multiplier_); }
    if (var0 & 64) { s.store_field("stars", stars_); }
    s.store_class_end();
  }
}

object_ptr<BotApp> BotApp::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case botAppNotModified::ID:
      return botAppNotModified::fetch(p);
    case botApp::ID:
      return botApp::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t botAppNotModified::ID;

object_ptr<BotApp> botAppNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<botAppNotModified>();
}

void botAppNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botAppNotModified");
    s.store_class_end();
  }
}

botApp::botApp()
  : flags_()
  , id_()
  , access_hash_()
  , short_name_()
  , title_()
  , description_()
  , photo_()
  , document_()
  , hash_()
{}

const std::int32_t botApp::ID;

object_ptr<BotApp> botApp::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botApp> res = make_tl_object<botApp>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->short_name_ = TlFetchString<string>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  res->photo_ = TlFetchObject<Photo>::parse(p);
  if (var0 & 1) { res->document_ = TlFetchObject<Document>::parse(p); }
  res->hash_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botApp");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("short_name", short_name_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    if (var0 & 1) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

const std::int32_t botCommandScopeDefault::ID;

void botCommandScopeDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void botCommandScopeDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void botCommandScopeDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeDefault");
    s.store_class_end();
  }
}

const std::int32_t botCommandScopeUsers::ID;

void botCommandScopeUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void botCommandScopeUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void botCommandScopeUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeUsers");
    s.store_class_end();
  }
}

const std::int32_t botCommandScopeChats::ID;

void botCommandScopeChats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void botCommandScopeChats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void botCommandScopeChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChats");
    s.store_class_end();
  }
}

const std::int32_t botCommandScopeChatAdmins::ID;

void botCommandScopeChatAdmins::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void botCommandScopeChatAdmins::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void botCommandScopeChatAdmins::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopeChatAdmins");
    s.store_class_end();
  }
}

botCommandScopePeer::botCommandScopePeer(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t botCommandScopePeer::ID;

void botCommandScopePeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void botCommandScopePeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void botCommandScopePeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopePeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

botCommandScopePeerAdmins::botCommandScopePeerAdmins(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t botCommandScopePeerAdmins::ID;

void botCommandScopePeerAdmins::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void botCommandScopePeerAdmins::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void botCommandScopePeerAdmins::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopePeerAdmins");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

botCommandScopePeerUser::botCommandScopePeerUser(object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&user_id_)
  : peer_(std::move(peer_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t botCommandScopePeerUser::ID;

void botCommandScopePeerUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void botCommandScopePeerUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void botCommandScopePeerUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommandScopePeerUser");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

object_ptr<BotInlineResult> BotInlineResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case botInlineResult::ID:
      return botInlineResult::fetch(p);
    case botInlineMediaResult::ID:
      return botInlineMediaResult::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

botInlineResult::botInlineResult()
  : flags_()
  , id_()
  , type_()
  , title_()
  , description_()
  , url_()
  , thumb_()
  , content_()
  , send_message_()
{}

const std::int32_t botInlineResult::ID;

object_ptr<BotInlineResult> botInlineResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineResult> res = make_tl_object<botInlineResult>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchString<string>::parse(p);
  res->type_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->description_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->url_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->thumb_ = TlFetchObject<WebDocument>::parse(p); }
  if (var0 & 32) { res->content_ = TlFetchObject<WebDocument>::parse(p); }
  res->send_message_ = TlFetchObject<BotInlineMessage>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineResult");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    s.store_field("type", type_);
    if (var0 & 2) { s.store_field("title", title_); }
    if (var0 & 4) { s.store_field("description", description_); }
    if (var0 & 8) { s.store_field("url", url_); }
    if (var0 & 16) { s.store_object_field("thumb", static_cast<const BaseObject *>(thumb_.get())); }
    if (var0 & 32) { s.store_object_field("content", static_cast<const BaseObject *>(content_.get())); }
    s.store_object_field("send_message", static_cast<const BaseObject *>(send_message_.get()));
    s.store_class_end();
  }
}

botInlineMediaResult::botInlineMediaResult()
  : flags_()
  , id_()
  , type_()
  , photo_()
  , document_()
  , title_()
  , description_()
  , send_message_()
{}

const std::int32_t botInlineMediaResult::ID;

object_ptr<BotInlineResult> botInlineMediaResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMediaResult> res = make_tl_object<botInlineMediaResult>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchString<string>::parse(p);
  res->type_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 2) { res->document_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 4) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->description_ = TlFetchString<string>::parse(p); }
  res->send_message_ = TlFetchObject<BotInlineMessage>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMediaResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMediaResult");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    s.store_field("type", type_);
    if (var0 & 1) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 2) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 4) { s.store_field("title", title_); }
    if (var0 & 8) { s.store_field("description", description_); }
    s.store_object_field("send_message", static_cast<const BaseObject *>(send_message_.get()));
    s.store_class_end();
  }
}

businessAwayMessage::businessAwayMessage()
  : flags_()
  , offline_only_()
  , shortcut_id_()
  , schedule_()
  , recipients_()
{}

const std::int32_t businessAwayMessage::ID;

object_ptr<businessAwayMessage> businessAwayMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessAwayMessage> res = make_tl_object<businessAwayMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->offline_only_ = (var0 & 1) != 0;
  res->shortcut_id_ = TlFetchInt::parse(p);
  res->schedule_ = TlFetchObject<BusinessAwayMessageSchedule>::parse(p);
  res->recipients_ = TlFetchBoxed<TlFetchObject<businessRecipients>, 554733559>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessAwayMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (offline_only_ << 0)));
    if (var0 & 1) { s.store_field("offline_only", true); }
    s.store_field("shortcut_id", shortcut_id_);
    s.store_object_field("schedule", static_cast<const BaseObject *>(schedule_.get()));
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_class_end();
  }
}

businessWeeklyOpen::businessWeeklyOpen(int32 start_minute_, int32 end_minute_)
  : start_minute_(start_minute_)
  , end_minute_(end_minute_)
{}

const std::int32_t businessWeeklyOpen::ID;

object_ptr<businessWeeklyOpen> businessWeeklyOpen::fetch(TlBufferParser &p) {
  return make_tl_object<businessWeeklyOpen>(p);
}

businessWeeklyOpen::businessWeeklyOpen(TlBufferParser &p)
  : start_minute_(TlFetchInt::parse(p))
  , end_minute_(TlFetchInt::parse(p))
{}

void businessWeeklyOpen::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(start_minute_, s);
  TlStoreBinary::store(end_minute_, s);
}

void businessWeeklyOpen::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(start_minute_, s);
  TlStoreBinary::store(end_minute_, s);
}

void businessWeeklyOpen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessWeeklyOpen");
    s.store_field("start_minute", start_minute_);
    s.store_field("end_minute", end_minute_);
    s.store_class_end();
  }
}

const std::int32_t cdnConfig::ID;

object_ptr<cdnConfig> cdnConfig::fetch(TlBufferParser &p) {
  return make_tl_object<cdnConfig>(p);
}

cdnConfig::cdnConfig(TlBufferParser &p)
  : public_keys_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<cdnPublicKey>, -914167110>>, 481674261>::parse(p))
{}

void cdnConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cdnConfig");
    { s.store_vector_begin("public_keys", public_keys_.size()); for (const auto &_value : public_keys_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEvent::ID;

object_ptr<channelAdminLogEvent> channelAdminLogEvent::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEvent>(p);
}

channelAdminLogEvent::channelAdminLogEvent(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , action_(TlFetchObject<ChannelAdminLogEventAction>::parse(p))
{}

void channelAdminLogEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEvent");
    s.store_field("id", id_);
    s.store_field("date", date_);
    s.store_field("user_id", user_id_);
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelParticipantsRecent::ID;

void channelParticipantsRecent::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void channelParticipantsRecent::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void channelParticipantsRecent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsRecent");
    s.store_class_end();
  }
}

const std::int32_t channelParticipantsAdmins::ID;

void channelParticipantsAdmins::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void channelParticipantsAdmins::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void channelParticipantsAdmins::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsAdmins");
    s.store_class_end();
  }
}

channelParticipantsKicked::channelParticipantsKicked(string const &q_)
  : q_(q_)
{}

const std::int32_t channelParticipantsKicked::ID;

void channelParticipantsKicked::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsKicked::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsKicked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsKicked");
    s.store_field("q", q_);
    s.store_class_end();
  }
}

const std::int32_t channelParticipantsBots::ID;

void channelParticipantsBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void channelParticipantsBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void channelParticipantsBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsBots");
    s.store_class_end();
  }
}

channelParticipantsBanned::channelParticipantsBanned(string const &q_)
  : q_(q_)
{}

const std::int32_t channelParticipantsBanned::ID;

void channelParticipantsBanned::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsBanned::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsBanned");
    s.store_field("q", q_);
    s.store_class_end();
  }
}

channelParticipantsSearch::channelParticipantsSearch(string const &q_)
  : q_(q_)
{}

const std::int32_t channelParticipantsSearch::ID;

void channelParticipantsSearch::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsSearch::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsSearch::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsSearch");
    s.store_field("q", q_);
    s.store_class_end();
  }
}

channelParticipantsContacts::channelParticipantsContacts(string const &q_)
  : q_(q_)
{}

const std::int32_t channelParticipantsContacts::ID;

void channelParticipantsContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(q_, s);
}

void channelParticipantsContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsContacts");
    s.store_field("q", q_);
    s.store_class_end();
  }
}

channelParticipantsMentions::channelParticipantsMentions(int32 flags_, string const &q_, int32 top_msg_id_)
  : flags_(flags_)
  , q_(q_)
  , top_msg_id_(top_msg_id_)
{}

const std::int32_t channelParticipantsMentions::ID;

void channelParticipantsMentions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(q_, s); }
  if (var0 & 2) { TlStoreBinary::store(top_msg_id_, s); }
}

void channelParticipantsMentions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(q_, s); }
  if (var0 & 2) { TlStoreBinary::store(top_msg_id_, s); }
}

void channelParticipantsMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantsMentions");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("q", q_); }
    if (var0 & 2) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_class_end();
  }
}

object_ptr<DocumentAttribute> DocumentAttribute::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case documentAttributeImageSize::ID:
      return documentAttributeImageSize::fetch(p);
    case documentAttributeAnimated::ID:
      return documentAttributeAnimated::fetch(p);
    case documentAttributeSticker::ID:
      return documentAttributeSticker::fetch(p);
    case documentAttributeVideo::ID:
      return documentAttributeVideo::fetch(p);
    case documentAttributeAudio::ID:
      return documentAttributeAudio::fetch(p);
    case documentAttributeFilename::ID:
      return documentAttributeFilename::fetch(p);
    case documentAttributeHasStickers::ID:
      return documentAttributeHasStickers::fetch(p);
    case documentAttributeCustomEmoji::ID:
      return documentAttributeCustomEmoji::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

documentAttributeImageSize::documentAttributeImageSize(int32 w_, int32 h_)
  : w_(w_)
  , h_(h_)
{}

const std::int32_t documentAttributeImageSize::ID;

object_ptr<DocumentAttribute> documentAttributeImageSize::fetch(TlBufferParser &p) {
  return make_tl_object<documentAttributeImageSize>(p);
}

documentAttributeImageSize::documentAttributeImageSize(TlBufferParser &p)
  : w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
{}

void documentAttributeImageSize::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
}

void documentAttributeImageSize::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
}

void documentAttributeImageSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeImageSize");
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_class_end();
  }
}

const std::int32_t documentAttributeAnimated::ID;

object_ptr<DocumentAttribute> documentAttributeAnimated::fetch(TlBufferParser &p) {
  return make_tl_object<documentAttributeAnimated>();
}

void documentAttributeAnimated::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void documentAttributeAnimated::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void documentAttributeAnimated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeAnimated");
    s.store_class_end();
  }
}

documentAttributeSticker::documentAttributeSticker()
  : flags_()
  , mask_()
  , alt_()
  , stickerset_()
  , mask_coords_()
{}

documentAttributeSticker::documentAttributeSticker(int32 flags_, bool mask_, string const &alt_, object_ptr<InputStickerSet> &&stickerset_, object_ptr<maskCoords> &&mask_coords_)
  : flags_(flags_)
  , mask_(mask_)
  , alt_(alt_)
  , stickerset_(std::move(stickerset_))
  , mask_coords_(std::move(mask_coords_))
{}

const std::int32_t documentAttributeSticker::ID;

object_ptr<DocumentAttribute> documentAttributeSticker::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<documentAttributeSticker> res = make_tl_object<documentAttributeSticker>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->mask_ = (var0 & 2) != 0;
  res->alt_ = TlFetchString<string>::parse(p);
  res->stickerset_ = TlFetchObject<InputStickerSet>::parse(p);
  if (var0 & 1) { res->mask_coords_ = TlFetchBoxed<TlFetchObject<maskCoords>, -1361650766>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void documentAttributeSticker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (mask_ << 1)), s);
  TlStoreString::store(alt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1361650766>::store(mask_coords_, s); }
}

void documentAttributeSticker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (mask_ << 1)), s);
  TlStoreString::store(alt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1361650766>::store(mask_coords_, s); }
}

void documentAttributeSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeSticker");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (mask_ << 1)));
    if (var0 & 2) { s.store_field("mask", true); }
    s.store_field("alt", alt_);
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    if (var0 & 1) { s.store_object_field("mask_coords", static_cast<const BaseObject *>(mask_coords_.get())); }
    s.store_class_end();
  }
}

documentAttributeVideo::documentAttributeVideo()
  : flags_()
  , round_message_()
  , supports_streaming_()
  , nosound_()
  , duration_()
  , w_()
  , h_()
  , preload_prefix_size_()
  , video_start_ts_()
  , video_codec_()
{}

documentAttributeVideo::documentAttributeVideo(int32 flags_, bool round_message_, bool supports_streaming_, bool nosound_, double duration_, int32 w_, int32 h_, int32 preload_prefix_size_, double video_start_ts_, string const &video_codec_)
  : flags_(flags_)
  , round_message_(round_message_)
  , supports_streaming_(supports_streaming_)
  , nosound_(nosound_)
  , duration_(duration_)
  , w_(w_)
  , h_(h_)
  , preload_prefix_size_(preload_prefix_size_)
  , video_start_ts_(video_start_ts_)
  , video_codec_(video_codec_)
{}

const std::int32_t documentAttributeVideo::ID;

object_ptr<DocumentAttribute> documentAttributeVideo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<documentAttributeVideo> res = make_tl_object<documentAttributeVideo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->round_message_ = (var0 & 1) != 0;
  res->supports_streaming_ = (var0 & 2) != 0;
  res->nosound_ = (var0 & 8) != 0;
  res->duration_ = TlFetchDouble::parse(p);
  res->w_ = TlFetchInt::parse(p);
  res->h_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->preload_prefix_size_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->video_start_ts_ = TlFetchDouble::parse(p); }
  if (var0 & 32) { res->video_codec_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void documentAttributeVideo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (round_message_ << 0) | (supports_streaming_ << 1) | (nosound_ << 3)), s);
  TlStoreBinary::store(duration_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  if (var0 & 4) { TlStoreBinary::store(preload_prefix_size_, s); }
  if (var0 & 16) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 32) { TlStoreString::store(video_codec_, s); }
}

void documentAttributeVideo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (round_message_ << 0) | (supports_streaming_ << 1) | (nosound_ << 3)), s);
  TlStoreBinary::store(duration_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  if (var0 & 4) { TlStoreBinary::store(preload_prefix_size_, s); }
  if (var0 & 16) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 32) { TlStoreString::store(video_codec_, s); }
}

void documentAttributeVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeVideo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (round_message_ << 0) | (supports_streaming_ << 1) | (nosound_ << 3)));
    if (var0 & 1) { s.store_field("round_message", true); }
    if (var0 & 2) { s.store_field("supports_streaming", true); }
    if (var0 & 8) { s.store_field("nosound", true); }
    s.store_field("duration", duration_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    if (var0 & 4) { s.store_field("preload_prefix_size", preload_prefix_size_); }
    if (var0 & 16) { s.store_field("video_start_ts", video_start_ts_); }
    if (var0 & 32) { s.store_field("video_codec", video_codec_); }
    s.store_class_end();
  }
}

documentAttributeAudio::documentAttributeAudio()
  : flags_()
  , voice_()
  , duration_()
  , title_()
  , performer_()
  , waveform_()
{}

documentAttributeAudio::documentAttributeAudio(int32 flags_, bool voice_, int32 duration_, string const &title_, string const &performer_, bytes &&waveform_)
  : flags_(flags_)
  , voice_(voice_)
  , duration_(duration_)
  , title_(title_)
  , performer_(performer_)
  , waveform_(std::move(waveform_))
{}

const std::int32_t documentAttributeAudio::ID;

object_ptr<DocumentAttribute> documentAttributeAudio::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<documentAttributeAudio> res = make_tl_object<documentAttributeAudio>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->voice_ = (var0 & 1024) != 0;
  res->duration_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->performer_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->waveform_ = TlFetchBytes<bytes>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void documentAttributeAudio::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (voice_ << 10)), s);
  TlStoreBinary::store(duration_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreString::store(performer_, s); }
  if (var0 & 4) { TlStoreString::store(waveform_, s); }
}

void documentAttributeAudio::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (voice_ << 10)), s);
  TlStoreBinary::store(duration_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreString::store(performer_, s); }
  if (var0 & 4) { TlStoreString::store(waveform_, s); }
}

void documentAttributeAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeAudio");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (voice_ << 10)));
    if (var0 & 1024) { s.store_field("voice", true); }
    s.store_field("duration", duration_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("performer", performer_); }
    if (var0 & 4) { s.store_bytes_field("waveform", waveform_); }
    s.store_class_end();
  }
}

documentAttributeFilename::documentAttributeFilename(string const &file_name_)
  : file_name_(file_name_)
{}

const std::int32_t documentAttributeFilename::ID;

object_ptr<DocumentAttribute> documentAttributeFilename::fetch(TlBufferParser &p) {
  return make_tl_object<documentAttributeFilename>(p);
}

documentAttributeFilename::documentAttributeFilename(TlBufferParser &p)
  : file_name_(TlFetchString<string>::parse(p))
{}

void documentAttributeFilename::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(file_name_, s);
}

void documentAttributeFilename::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(file_name_, s);
}

void documentAttributeFilename::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeFilename");
    s.store_field("file_name", file_name_);
    s.store_class_end();
  }
}

const std::int32_t documentAttributeHasStickers::ID;

object_ptr<DocumentAttribute> documentAttributeHasStickers::fetch(TlBufferParser &p) {
  return make_tl_object<documentAttributeHasStickers>();
}

void documentAttributeHasStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void documentAttributeHasStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void documentAttributeHasStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeHasStickers");
    s.store_class_end();
  }
}

documentAttributeCustomEmoji::documentAttributeCustomEmoji()
  : flags_()
  , free_()
  , text_color_()
  , alt_()
  , stickerset_()
{}

documentAttributeCustomEmoji::documentAttributeCustomEmoji(int32 flags_, bool free_, bool text_color_, string const &alt_, object_ptr<InputStickerSet> &&stickerset_)
  : flags_(flags_)
  , free_(free_)
  , text_color_(text_color_)
  , alt_(alt_)
  , stickerset_(std::move(stickerset_))
{}

const std::int32_t documentAttributeCustomEmoji::ID;

object_ptr<DocumentAttribute> documentAttributeCustomEmoji::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<documentAttributeCustomEmoji> res = make_tl_object<documentAttributeCustomEmoji>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->free_ = (var0 & 1) != 0;
  res->text_color_ = (var0 & 2) != 0;
  res->alt_ = TlFetchString<string>::parse(p);
  res->stickerset_ = TlFetchObject<InputStickerSet>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void documentAttributeCustomEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (free_ << 0) | (text_color_ << 1)), s);
  TlStoreString::store(alt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void documentAttributeCustomEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (free_ << 0) | (text_color_ << 1)), s);
  TlStoreString::store(alt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void documentAttributeCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentAttributeCustomEmoji");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (free_ << 0) | (text_color_ << 1)));
    if (var0 & 1) { s.store_field("free", true); }
    if (var0 & 2) { s.store_field("text_color", true); }
    s.store_field("alt", alt_);
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_class_end();
  }
}

emailVerifyPurposeLoginSetup::emailVerifyPurposeLoginSetup(string const &phone_number_, string const &phone_code_hash_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
{}

const std::int32_t emailVerifyPurposeLoginSetup::ID;

void emailVerifyPurposeLoginSetup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
}

void emailVerifyPurposeLoginSetup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
}

void emailVerifyPurposeLoginSetup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailVerifyPurposeLoginSetup");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_class_end();
  }
}

const std::int32_t emailVerifyPurposeLoginChange::ID;

void emailVerifyPurposeLoginChange::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void emailVerifyPurposeLoginChange::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void emailVerifyPurposeLoginChange::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailVerifyPurposeLoginChange");
    s.store_class_end();
  }
}

const std::int32_t emailVerifyPurposePassport::ID;

void emailVerifyPurposePassport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void emailVerifyPurposePassport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void emailVerifyPurposePassport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emailVerifyPurposePassport");
    s.store_class_end();
  }
}

object_ptr<EncryptedChat> EncryptedChat::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case encryptedChatEmpty::ID:
      return encryptedChatEmpty::fetch(p);
    case encryptedChatWaiting::ID:
      return encryptedChatWaiting::fetch(p);
    case encryptedChatRequested::ID:
      return encryptedChatRequested::fetch(p);
    case encryptedChat::ID:
      return encryptedChat::fetch(p);
    case encryptedChatDiscarded::ID:
      return encryptedChatDiscarded::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t encryptedChatEmpty::ID;

object_ptr<EncryptedChat> encryptedChatEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedChatEmpty>(p);
}

encryptedChatEmpty::encryptedChatEmpty(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
{}

void encryptedChatEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedChatEmpty");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

encryptedChatWaiting::encryptedChatWaiting(int32 id_, int64 access_hash_, int32 date_, int64 admin_id_, int64 participant_id_)
  : id_(id_)
  , access_hash_(access_hash_)
  , date_(date_)
  , admin_id_(admin_id_)
  , participant_id_(participant_id_)
{}

const std::int32_t encryptedChatWaiting::ID;

object_ptr<EncryptedChat> encryptedChatWaiting::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedChatWaiting>(p);
}

encryptedChatWaiting::encryptedChatWaiting(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
  , admin_id_(TlFetchLong::parse(p))
  , participant_id_(TlFetchLong::parse(p))
{}

void encryptedChatWaiting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedChatWaiting");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_class_end();
  }
}

encryptedChatRequested::encryptedChatRequested()
  : flags_()
  , folder_id_()
  , id_()
  , access_hash_()
  , date_()
  , admin_id_()
  , participant_id_()
  , g_a_()
{}

encryptedChatRequested::encryptedChatRequested(int32 flags_, int32 folder_id_, int32 id_, int64 access_hash_, int32 date_, int64 admin_id_, int64 participant_id_, bytes &&g_a_)
  : flags_(flags_)
  , folder_id_(folder_id_)
  , id_(id_)
  , access_hash_(access_hash_)
  , date_(date_)
  , admin_id_(admin_id_)
  , participant_id_(participant_id_)
  , g_a_(std::move(g_a_))
{}

const std::int32_t encryptedChatRequested::ID;

object_ptr<EncryptedChat> encryptedChatRequested::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<encryptedChatRequested> res = make_tl_object<encryptedChatRequested>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->folder_id_ = TlFetchInt::parse(p); }
  res->id_ = TlFetchInt::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->admin_id_ = TlFetchLong::parse(p);
  res->participant_id_ = TlFetchLong::parse(p);
  res->g_a_ = TlFetchBytes<bytes>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void encryptedChatRequested::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedChatRequested");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("folder_id", folder_id_); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_bytes_field("g_a", g_a_);
    s.store_class_end();
  }
}

encryptedChat::encryptedChat(int32 id_, int64 access_hash_, int32 date_, int64 admin_id_, int64 participant_id_, bytes &&g_a_or_b_, int64 key_fingerprint_)
  : id_(id_)
  , access_hash_(access_hash_)
  , date_(date_)
  , admin_id_(admin_id_)
  , participant_id_(participant_id_)
  , g_a_or_b_(std::move(g_a_or_b_))
  , key_fingerprint_(key_fingerprint_)
{}

const std::int32_t encryptedChat::ID;

object_ptr<EncryptedChat> encryptedChat::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedChat>(p);
}

encryptedChat::encryptedChat(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
  , admin_id_(TlFetchLong::parse(p))
  , participant_id_(TlFetchLong::parse(p))
  , g_a_or_b_(TlFetchBytes<bytes>::parse(p))
  , key_fingerprint_(TlFetchLong::parse(p))
{}

void encryptedChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedChat");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_bytes_field("g_a_or_b", g_a_or_b_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_class_end();
  }
}

encryptedChatDiscarded::encryptedChatDiscarded()
  : flags_()
  , history_deleted_()
  , id_()
{}

const std::int32_t encryptedChatDiscarded::ID;

object_ptr<EncryptedChat> encryptedChatDiscarded::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<encryptedChatDiscarded> res = make_tl_object<encryptedChatDiscarded>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->history_deleted_ = (var0 & 1) != 0;
  res->id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void encryptedChatDiscarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedChatDiscarded");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (history_deleted_ << 0)));
    if (var0 & 1) { s.store_field("history_deleted", true); }
    s.store_field("id", id_);
    s.store_class_end();
  }
}

game::game()
  : flags_()
  , id_()
  , access_hash_()
  , short_name_()
  , title_()
  , description_()
  , photo_()
  , document_()
{}

game::game(int32 flags_, int64 id_, int64 access_hash_, string const &short_name_, string const &title_, string const &description_, object_ptr<Photo> &&photo_, object_ptr<Document> &&document_)
  : flags_(flags_)
  , id_(id_)
  , access_hash_(access_hash_)
  , short_name_(short_name_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , document_(std::move(document_))
{}

const std::int32_t game::ID;

object_ptr<game> game::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<game> res = make_tl_object<game>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->short_name_ = TlFetchString<string>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  res->photo_ = TlFetchObject<Photo>::parse(p);
  if (var0 & 1) { res->document_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void game::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(short_name_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
}

void game::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(short_name_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
}

void game::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "game");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("short_name", short_name_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    if (var0 & 1) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    s.store_class_end();
  }
}

globalPrivacySettings::globalPrivacySettings()
  : flags_()
  , archive_and_mute_new_noncontact_peers_()
  , keep_archived_unmuted_()
  , keep_archived_folders_()
  , hide_read_marks_()
  , new_noncontact_peers_require_premium_()
  , display_gifts_button_()
  , noncontact_peers_paid_stars_()
  , disallowed_gifts_()
{}

globalPrivacySettings::globalPrivacySettings(int32 flags_, bool archive_and_mute_new_noncontact_peers_, bool keep_archived_unmuted_, bool keep_archived_folders_, bool hide_read_marks_, bool new_noncontact_peers_require_premium_, bool display_gifts_button_, int64 noncontact_peers_paid_stars_, object_ptr<disallowedGiftsSettings> &&disallowed_gifts_)
  : flags_(flags_)
  , archive_and_mute_new_noncontact_peers_(archive_and_mute_new_noncontact_peers_)
  , keep_archived_unmuted_(keep_archived_unmuted_)
  , keep_archived_folders_(keep_archived_folders_)
  , hide_read_marks_(hide_read_marks_)
  , new_noncontact_peers_require_premium_(new_noncontact_peers_require_premium_)
  , display_gifts_button_(display_gifts_button_)
  , noncontact_peers_paid_stars_(noncontact_peers_paid_stars_)
  , disallowed_gifts_(std::move(disallowed_gifts_))
{}

const std::int32_t globalPrivacySettings::ID;

object_ptr<globalPrivacySettings> globalPrivacySettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<globalPrivacySettings> res = make_tl_object<globalPrivacySettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->archive_and_mute_new_noncontact_peers_ = (var0 & 1) != 0;
  res->keep_archived_unmuted_ = (var0 & 2) != 0;
  res->keep_archived_folders_ = (var0 & 4) != 0;
  res->hide_read_marks_ = (var0 & 8) != 0;
  res->new_noncontact_peers_require_premium_ = (var0 & 16) != 0;
  res->display_gifts_button_ = (var0 & 128) != 0;
  if (var0 & 32) { res->noncontact_peers_paid_stars_ = TlFetchLong::parse(p); }
  if (var0 & 64) { res->disallowed_gifts_ = TlFetchBoxed<TlFetchObject<disallowedGiftsSettings>, 1911715524>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void globalPrivacySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (archive_and_mute_new_noncontact_peers_ << 0) | (keep_archived_unmuted_ << 1) | (keep_archived_folders_ << 2) | (hide_read_marks_ << 3) | (new_noncontact_peers_require_premium_ << 4) | (display_gifts_button_ << 7)), s);
  if (var0 & 32) { TlStoreBinary::store(noncontact_peers_paid_stars_, s); }
  if (var0 & 64) { TlStoreBoxed<TlStoreObject, 1911715524>::store(disallowed_gifts_, s); }
}

void globalPrivacySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (archive_and_mute_new_noncontact_peers_ << 0) | (keep_archived_unmuted_ << 1) | (keep_archived_folders_ << 2) | (hide_read_marks_ << 3) | (new_noncontact_peers_require_premium_ << 4) | (display_gifts_button_ << 7)), s);
  if (var0 & 32) { TlStoreBinary::store(noncontact_peers_paid_stars_, s); }
  if (var0 & 64) { TlStoreBoxed<TlStoreObject, 1911715524>::store(disallowed_gifts_, s); }
}

void globalPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "globalPrivacySettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (archive_and_mute_new_noncontact_peers_ << 0) | (keep_archived_unmuted_ << 1) | (keep_archived_folders_ << 2) | (hide_read_marks_ << 3) | (new_noncontact_peers_require_premium_ << 4) | (display_gifts_button_ << 7)));
    if (var0 & 1) { s.store_field("archive_and_mute_new_noncontact_peers", true); }
    if (var0 & 2) { s.store_field("keep_archived_unmuted", true); }
    if (var0 & 4) { s.store_field("keep_archived_folders", true); }
    if (var0 & 8) { s.store_field("hide_read_marks", true); }
    if (var0 & 16) { s.store_field("new_noncontact_peers_require_premium", true); }
    if (var0 & 128) { s.store_field("display_gifts_button", true); }
    if (var0 & 32) { s.store_field("noncontact_peers_paid_stars", noncontact_peers_paid_stars_); }
    if (var0 & 64) { s.store_object_field("disallowed_gifts", static_cast<const BaseObject *>(disallowed_gifts_.get())); }
    s.store_class_end();
  }
}

groupCallDonor::groupCallDonor()
  : flags_()
  , top_()
  , my_()
  , peer_id_()
  , stars_()
{}

const std::int32_t groupCallDonor::ID;

object_ptr<groupCallDonor> groupCallDonor::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<groupCallDonor> res = make_tl_object<groupCallDonor>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->top_ = (var0 & 1) != 0;
  res->my_ = (var0 & 2) != 0;
  if (var0 & 8) { res->peer_id_ = TlFetchObject<Peer>::parse(p); }
  res->stars_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void groupCallDonor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallDonor");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (top_ << 0) | (my_ << 1)));
    if (var0 & 1) { s.store_field("top", true); }
    if (var0 & 2) { s.store_field("my", true); }
    if (var0 & 8) { s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get())); }
    s.store_field("stars", stars_);
    s.store_class_end();
  }
}

const std::int32_t groupCallStreamChannel::ID;

object_ptr<groupCallStreamChannel> groupCallStreamChannel::fetch(TlBufferParser &p) {
  return make_tl_object<groupCallStreamChannel>(p);
}

groupCallStreamChannel::groupCallStreamChannel(TlBufferParser &p)
  : channel_(TlFetchInt::parse(p))
  , scale_(TlFetchInt::parse(p))
  , last_timestamp_ms_(TlFetchLong::parse(p))
{}

void groupCallStreamChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallStreamChannel");
    s.store_field("channel", channel_);
    s.store_field("scale", scale_);
    s.store_field("last_timestamp_ms", last_timestamp_ms_);
    s.store_class_end();
  }
}

const std::int32_t highScore::ID;

object_ptr<highScore> highScore::fetch(TlBufferParser &p) {
  return make_tl_object<highScore>(p);
}

highScore::highScore(TlBufferParser &p)
  : pos_(TlFetchInt::parse(p))
  , user_id_(TlFetchLong::parse(p))
  , score_(TlFetchInt::parse(p))
{}

void highScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "highScore");
    s.store_field("pos", pos_);
    s.store_field("user_id", user_id_);
    s.store_field("score", score_);
    s.store_class_end();
  }
}

object_ptr<InlineQueryPeerType> InlineQueryPeerType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inlineQueryPeerTypeSameBotPM::ID:
      return inlineQueryPeerTypeSameBotPM::fetch(p);
    case inlineQueryPeerTypePM::ID:
      return inlineQueryPeerTypePM::fetch(p);
    case inlineQueryPeerTypeChat::ID:
      return inlineQueryPeerTypeChat::fetch(p);
    case inlineQueryPeerTypeMegagroup::ID:
      return inlineQueryPeerTypeMegagroup::fetch(p);
    case inlineQueryPeerTypeBroadcast::ID:
      return inlineQueryPeerTypeBroadcast::fetch(p);
    case inlineQueryPeerTypeBotPM::ID:
      return inlineQueryPeerTypeBotPM::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inlineQueryPeerTypeSameBotPM::ID;

object_ptr<InlineQueryPeerType> inlineQueryPeerTypeSameBotPM::fetch(TlBufferParser &p) {
  return make_tl_object<inlineQueryPeerTypeSameBotPM>();
}

void inlineQueryPeerTypeSameBotPM::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeSameBotPM::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeSameBotPM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryPeerTypeSameBotPM");
    s.store_class_end();
  }
}

const std::int32_t inlineQueryPeerTypePM::ID;

object_ptr<InlineQueryPeerType> inlineQueryPeerTypePM::fetch(TlBufferParser &p) {
  return make_tl_object<inlineQueryPeerTypePM>();
}

void inlineQueryPeerTypePM::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypePM::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypePM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryPeerTypePM");
    s.store_class_end();
  }
}

const std::int32_t inlineQueryPeerTypeChat::ID;

object_ptr<InlineQueryPeerType> inlineQueryPeerTypeChat::fetch(TlBufferParser &p) {
  return make_tl_object<inlineQueryPeerTypeChat>();
}

void inlineQueryPeerTypeChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryPeerTypeChat");
    s.store_class_end();
  }
}

const std::int32_t inlineQueryPeerTypeMegagroup::ID;

object_ptr<InlineQueryPeerType> inlineQueryPeerTypeMegagroup::fetch(TlBufferParser &p) {
  return make_tl_object<inlineQueryPeerTypeMegagroup>();
}

void inlineQueryPeerTypeMegagroup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeMegagroup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeMegagroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryPeerTypeMegagroup");
    s.store_class_end();
  }
}

const std::int32_t inlineQueryPeerTypeBroadcast::ID;

object_ptr<InlineQueryPeerType> inlineQueryPeerTypeBroadcast::fetch(TlBufferParser &p) {
  return make_tl_object<inlineQueryPeerTypeBroadcast>();
}

void inlineQueryPeerTypeBroadcast::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeBroadcast::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeBroadcast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryPeerTypeBroadcast");
    s.store_class_end();
  }
}

const std::int32_t inlineQueryPeerTypeBotPM::ID;

object_ptr<InlineQueryPeerType> inlineQueryPeerTypeBotPM::fetch(TlBufferParser &p) {
  return make_tl_object<inlineQueryPeerTypeBotPM>();
}

void inlineQueryPeerTypeBotPM::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeBotPM::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inlineQueryPeerTypeBotPM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inlineQueryPeerTypeBotPM");
    s.store_class_end();
  }
}

inputAppEvent::inputAppEvent(double time_, string const &type_, int64 peer_, object_ptr<JSONValue> &&data_)
  : time_(time_)
  , type_(type_)
  , peer_(peer_)
  , data_(std::move(data_))
{}

const std::int32_t inputAppEvent::ID;

object_ptr<inputAppEvent> inputAppEvent::fetch(TlBufferParser &p) {
  return make_tl_object<inputAppEvent>(p);
}

inputAppEvent::inputAppEvent(TlBufferParser &p)
  : time_(TlFetchDouble::parse(p))
  , type_(TlFetchString<string>::parse(p))
  , peer_(TlFetchLong::parse(p))
  , data_(TlFetchObject<JSONValue>::parse(p))
{}

void inputAppEvent::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(time_, s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(data_, s);
}

void inputAppEvent::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(time_, s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(data_, s);
}

void inputAppEvent::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputAppEvent");
    s.store_field("time", time_);
    s.store_field("type", type_);
    s.store_field("peer", peer_);
    s.store_object_field("data", static_cast<const BaseObject *>(data_.get()));
    s.store_class_end();
  }
}

const std::int32_t inputChatPhotoEmpty::ID;

void inputChatPhotoEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputChatPhotoEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputChatPhotoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhotoEmpty");
    s.store_class_end();
  }
}

inputChatUploadedPhoto::inputChatUploadedPhoto(int32 flags_, object_ptr<InputFile> &&file_, object_ptr<InputFile> &&video_, double video_start_ts_, object_ptr<VideoSize> &&video_emoji_markup_)
  : flags_(flags_)
  , file_(std::move(file_))
  , video_(std::move(video_))
  , video_start_ts_(video_start_ts_)
  , video_emoji_markup_(std::move(video_emoji_markup_))
{}

const std::int32_t inputChatUploadedPhoto::ID;

void inputChatUploadedPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(file_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(video_emoji_markup_, s); }
}

void inputChatUploadedPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(file_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(video_emoji_markup_, s); }
}

void inputChatUploadedPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatUploadedPhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("file", static_cast<const BaseObject *>(file_.get())); }
    if (var0 & 2) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    if (var0 & 4) { s.store_field("video_start_ts", video_start_ts_); }
    if (var0 & 8) { s.store_object_field("video_emoji_markup", static_cast<const BaseObject *>(video_emoji_markup_.get())); }
    s.store_class_end();
  }
}

inputChatPhoto::inputChatPhoto(object_ptr<InputPhoto> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t inputChatPhoto::ID;

void inputChatPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputChatPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatPhoto");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

inputPeerPhotoFileLocationLegacy::inputPeerPhotoFileLocationLegacy(int32 flags_, bool big_, object_ptr<InputPeer> &&peer_, int64 volume_id_, int32 local_id_)
  : flags_(flags_)
  , big_(big_)
  , peer_(std::move(peer_))
  , volume_id_(volume_id_)
  , local_id_(local_id_)
{}

const std::int32_t inputPeerPhotoFileLocationLegacy::ID;

void inputPeerPhotoFileLocationLegacy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (big_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
}

void inputPeerPhotoFileLocationLegacy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (big_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
}

void inputPeerPhotoFileLocationLegacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerPhotoFileLocationLegacy");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (big_ << 0)));
    if (var0 & 1) { s.store_field("big", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("volume_id", volume_id_);
    s.store_field("local_id", local_id_);
    s.store_class_end();
  }
}

inputStickerSetThumbLegacy::inputStickerSetThumbLegacy(object_ptr<InputStickerSet> &&stickerset_, int64 volume_id_, int32 local_id_)
  : stickerset_(std::move(stickerset_))
  , volume_id_(volume_id_)
  , local_id_(local_id_)
{}

const std::int32_t inputStickerSetThumbLegacy::ID;

void inputStickerSetThumbLegacy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
}

void inputStickerSetThumbLegacy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
}

void inputStickerSetThumbLegacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetThumbLegacy");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_field("volume_id", volume_id_);
    s.store_field("local_id", local_id_);
    s.store_class_end();
  }
}

inputFileLocation::inputFileLocation(int64 volume_id_, int32 local_id_, int64 secret_, bytes &&file_reference_)
  : volume_id_(volume_id_)
  , local_id_(local_id_)
  , secret_(secret_)
  , file_reference_(std::move(file_reference_))
{}

const std::int32_t inputFileLocation::ID;

void inputFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
  TlStoreBinary::store(secret_, s);
  TlStoreString::store(file_reference_, s);
}

void inputFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
  TlStoreBinary::store(secret_, s);
  TlStoreString::store(file_reference_, s);
}

void inputFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileLocation");
    s.store_field("volume_id", volume_id_);
    s.store_field("local_id", local_id_);
    s.store_field("secret", secret_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_class_end();
  }
}

inputEncryptedFileLocation::inputEncryptedFileLocation(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputEncryptedFileLocation::ID;

void inputEncryptedFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputEncryptedFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputEncryptedFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEncryptedFileLocation");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputDocumentFileLocation::inputDocumentFileLocation(int64 id_, int64 access_hash_, bytes &&file_reference_, string const &thumb_size_)
  : id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
  , thumb_size_(thumb_size_)
{}

const std::int32_t inputDocumentFileLocation::ID;

void inputDocumentFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreString::store(thumb_size_, s);
}

void inputDocumentFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreString::store(thumb_size_, s);
}

void inputDocumentFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputDocumentFileLocation");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_field("thumb_size", thumb_size_);
    s.store_class_end();
  }
}

inputSecureFileLocation::inputSecureFileLocation(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputSecureFileLocation::ID;

void inputSecureFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputSecureFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputSecureFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSecureFileLocation");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

const std::int32_t inputTakeoutFileLocation::ID;

void inputTakeoutFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputTakeoutFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputTakeoutFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputTakeoutFileLocation");
    s.store_class_end();
  }
}

inputPhotoFileLocation::inputPhotoFileLocation(int64 id_, int64 access_hash_, bytes &&file_reference_, string const &thumb_size_)
  : id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
  , thumb_size_(thumb_size_)
{}

const std::int32_t inputPhotoFileLocation::ID;

void inputPhotoFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreString::store(thumb_size_, s);
}

void inputPhotoFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreString::store(thumb_size_, s);
}

void inputPhotoFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhotoFileLocation");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_field("thumb_size", thumb_size_);
    s.store_class_end();
  }
}

inputPhotoLegacyFileLocation::inputPhotoLegacyFileLocation(int64 id_, int64 access_hash_, bytes &&file_reference_, int64 volume_id_, int32 local_id_, int64 secret_)
  : id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
  , volume_id_(volume_id_)
  , local_id_(local_id_)
  , secret_(secret_)
{}

const std::int32_t inputPhotoLegacyFileLocation::ID;

void inputPhotoLegacyFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
  TlStoreBinary::store(secret_, s);
}

void inputPhotoLegacyFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreBinary::store(volume_id_, s);
  TlStoreBinary::store(local_id_, s);
  TlStoreBinary::store(secret_, s);
}

void inputPhotoLegacyFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhotoLegacyFileLocation");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_field("volume_id", volume_id_);
    s.store_field("local_id", local_id_);
    s.store_field("secret", secret_);
    s.store_class_end();
  }
}

inputPeerPhotoFileLocation::inputPeerPhotoFileLocation(int32 flags_, bool big_, object_ptr<InputPeer> &&peer_, int64 photo_id_)
  : flags_(flags_)
  , big_(big_)
  , peer_(std::move(peer_))
  , photo_id_(photo_id_)
{}

const std::int32_t inputPeerPhotoFileLocation::ID;

void inputPeerPhotoFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (big_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(photo_id_, s);
}

void inputPeerPhotoFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (big_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(photo_id_, s);
}

void inputPeerPhotoFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerPhotoFileLocation");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (big_ << 0)));
    if (var0 & 1) { s.store_field("big", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("photo_id", photo_id_);
    s.store_class_end();
  }
}

inputStickerSetThumb::inputStickerSetThumb(object_ptr<InputStickerSet> &&stickerset_, int32 thumb_version_)
  : stickerset_(std::move(stickerset_))
  , thumb_version_(thumb_version_)
{}

const std::int32_t inputStickerSetThumb::ID;

void inputStickerSetThumb::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(thumb_version_, s);
}

void inputStickerSetThumb::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(thumb_version_, s);
}

void inputStickerSetThumb::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStickerSetThumb");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_field("thumb_version", thumb_version_);
    s.store_class_end();
  }
}

inputGroupCallStream::inputGroupCallStream(int32 flags_, object_ptr<InputGroupCall> &&call_, int64 time_ms_, int32 scale_, int32 video_channel_, int32 video_quality_)
  : flags_(flags_)
  , call_(std::move(call_))
  , time_ms_(time_ms_)
  , scale_(scale_)
  , video_channel_(video_channel_)
  , video_quality_(video_quality_)
{}

const std::int32_t inputGroupCallStream::ID;

void inputGroupCallStream::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(time_ms_, s);
  TlStoreBinary::store(scale_, s);
  if (var0 & 1) { TlStoreBinary::store(video_channel_, s); }
  if (var0 & 1) { TlStoreBinary::store(video_quality_, s); }
}

void inputGroupCallStream::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(time_ms_, s);
  TlStoreBinary::store(scale_, s);
  if (var0 & 1) { TlStoreBinary::store(video_channel_, s); }
  if (var0 & 1) { TlStoreBinary::store(video_quality_, s); }
}

void inputGroupCallStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGroupCallStream");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("time_ms", time_ms_);
    s.store_field("scale", scale_);
    if (var0 & 1) { s.store_field("video_channel", video_channel_); }
    if (var0 & 1) { s.store_field("video_quality", video_quality_); }
    s.store_class_end();
  }
}

inputSecureValue::inputSecureValue(int32 flags_, object_ptr<SecureValueType> &&type_, object_ptr<secureData> &&data_, object_ptr<InputSecureFile> &&front_side_, object_ptr<InputSecureFile> &&reverse_side_, object_ptr<InputSecureFile> &&selfie_, array<object_ptr<InputSecureFile>> &&translation_, array<object_ptr<InputSecureFile>> &&files_, object_ptr<SecurePlainData> &&plain_data_)
  : flags_(flags_)
  , type_(std::move(type_))
  , data_(std::move(data_))
  , front_side_(std::move(front_side_))
  , reverse_side_(std::move(reverse_side_))
  , selfie_(std::move(selfie_))
  , translation_(std::move(translation_))
  , files_(std::move(files_))
  , plain_data_(std::move(plain_data_))
{}

const std::int32_t inputSecureValue::ID;

void inputSecureValue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1964327229>::store(data_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(front_side_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reverse_side_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(selfie_, s); }
  if (var0 & 64) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(translation_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(files_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(plain_data_, s); }
}

void inputSecureValue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1964327229>::store(data_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(front_side_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reverse_side_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(selfie_, s); }
  if (var0 & 64) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(translation_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(files_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(plain_data_, s); }
}

void inputSecureValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputSecureValue");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    if (var0 & 1) { s.store_object_field("data", static_cast<const BaseObject *>(data_.get())); }
    if (var0 & 2) { s.store_object_field("front_side", static_cast<const BaseObject *>(front_side_.get())); }
    if (var0 & 4) { s.store_object_field("reverse_side", static_cast<const BaseObject *>(reverse_side_.get())); }
    if (var0 & 8) { s.store_object_field("selfie", static_cast<const BaseObject *>(selfie_.get())); }
    if (var0 & 64) { { s.store_vector_begin("translation", translation_.size()); for (const auto &_value : translation_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { { s.store_vector_begin("files", files_.size()); for (const auto &_value : files_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 32) { s.store_object_field("plain_data", static_cast<const BaseObject *>(plain_data_.get())); }
    s.store_class_end();
  }
}

object_ptr<InputUser> InputUser::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputUserEmpty::ID:
      return inputUserEmpty::fetch(p);
    case inputUserSelf::ID:
      return inputUserSelf::fetch(p);
    case inputUser::ID:
      return inputUser::fetch(p);
    case inputUserFromMessage::ID:
      return inputUserFromMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputUserEmpty::ID;

object_ptr<InputUser> inputUserEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputUserEmpty>();
}

void inputUserEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputUserEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputUserEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputUserEmpty");
    s.store_class_end();
  }
}

const std::int32_t inputUserSelf::ID;

object_ptr<InputUser> inputUserSelf::fetch(TlBufferParser &p) {
  return make_tl_object<inputUserSelf>();
}

void inputUserSelf::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputUserSelf::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputUserSelf::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputUserSelf");
    s.store_class_end();
  }
}

inputUser::inputUser(int64 user_id_, int64 access_hash_)
  : user_id_(user_id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputUser::ID;

object_ptr<InputUser> inputUser::fetch(TlBufferParser &p) {
  return make_tl_object<inputUser>(p);
}

inputUser::inputUser(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(user_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputUser");
    s.store_field("user_id", user_id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputUserFromMessage::inputUserFromMessage(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 user_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , user_id_(user_id_)
{}

const std::int32_t inputUserFromMessage::ID;

object_ptr<InputUser> inputUserFromMessage::fetch(TlBufferParser &p) {
  return make_tl_object<inputUserFromMessage>(p);
}

inputUserFromMessage::inputUserFromMessage(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , user_id_(TlFetchLong::parse(p))
{}

void inputUserFromMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(user_id_, s);
}

void inputUserFromMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(user_id_, s);
}

void inputUserFromMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputUserFromMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

object_ptr<MessageMedia> MessageMedia::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messageMediaEmpty::ID:
      return messageMediaEmpty::fetch(p);
    case messageMediaPhoto::ID:
      return messageMediaPhoto::fetch(p);
    case messageMediaGeo::ID:
      return messageMediaGeo::fetch(p);
    case messageMediaContact::ID:
      return messageMediaContact::fetch(p);
    case messageMediaUnsupported::ID:
      return messageMediaUnsupported::fetch(p);
    case messageMediaDocument::ID:
      return messageMediaDocument::fetch(p);
    case messageMediaWebPage::ID:
      return messageMediaWebPage::fetch(p);
    case messageMediaVenue::ID:
      return messageMediaVenue::fetch(p);
    case messageMediaGame::ID:
      return messageMediaGame::fetch(p);
    case messageMediaInvoice::ID:
      return messageMediaInvoice::fetch(p);
    case messageMediaGeoLive::ID:
      return messageMediaGeoLive::fetch(p);
    case messageMediaPoll::ID:
      return messageMediaPoll::fetch(p);
    case messageMediaDice::ID:
      return messageMediaDice::fetch(p);
    case messageMediaStory::ID:
      return messageMediaStory::fetch(p);
    case messageMediaGiveaway::ID:
      return messageMediaGiveaway::fetch(p);
    case messageMediaGiveawayResults::ID:
      return messageMediaGiveawayResults::fetch(p);
    case messageMediaPaidMedia::ID:
      return messageMediaPaidMedia::fetch(p);
    case messageMediaToDo::ID:
      return messageMediaToDo::fetch(p);
    case messageMediaVideoStream::ID:
      return messageMediaVideoStream::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messageMediaEmpty::ID;

object_ptr<MessageMedia> messageMediaEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaEmpty>();
}

void messageMediaEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void messageMediaEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void messageMediaEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaEmpty");
    s.store_class_end();
  }
}

messageMediaPhoto::messageMediaPhoto()
  : flags_()
  , spoiler_()
  , live_photo_()
  , photo_()
  , ttl_seconds_()
  , video_()
{}

messageMediaPhoto::messageMediaPhoto(int32 flags_, bool spoiler_, bool live_photo_, object_ptr<Photo> &&photo_, int32 ttl_seconds_, object_ptr<Document> &&video_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , live_photo_(live_photo_)
  , photo_(std::move(photo_))
  , ttl_seconds_(ttl_seconds_)
  , video_(std::move(video_))
{}

const std::int32_t messageMediaPhoto::ID;

object_ptr<MessageMedia> messageMediaPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaPhoto> res = make_tl_object<messageMediaPhoto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 8) != 0;
  res->live_photo_ = (var0 & 16) != 0;
  if (var0 & 1) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 4) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->video_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 3) | (live_photo_ << 4)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s); }
  if (var0 & 4) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
}

void messageMediaPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 3) | (live_photo_ << 4)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s); }
  if (var0 & 4) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
}

void messageMediaPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaPhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 3) | (live_photo_ << 4)));
    if (var0 & 8) { s.store_field("spoiler", true); }
    if (var0 & 16) { s.store_field("live_photo", true); }
    if (var0 & 1) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 4) { s.store_field("ttl_seconds", ttl_seconds_); }
    if (var0 & 16) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    s.store_class_end();
  }
}

messageMediaGeo::messageMediaGeo(object_ptr<GeoPoint> &&geo_)
  : geo_(std::move(geo_))
{}

const std::int32_t messageMediaGeo::ID;

object_ptr<MessageMedia> messageMediaGeo::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaGeo>(p);
}

messageMediaGeo::messageMediaGeo(TlBufferParser &p)
  : geo_(TlFetchObject<GeoPoint>::parse(p))
{}

void messageMediaGeo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
}

void messageMediaGeo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
}

void messageMediaGeo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaGeo");
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    s.store_class_end();
  }
}

messageMediaContact::messageMediaContact(string const &phone_number_, string const &first_name_, string const &last_name_, string const &vcard_, int64 user_id_)
  : phone_number_(phone_number_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , vcard_(vcard_)
  , user_id_(user_id_)
{}

const std::int32_t messageMediaContact::ID;

object_ptr<MessageMedia> messageMediaContact::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaContact>(p);
}

messageMediaContact::messageMediaContact(TlBufferParser &p)
  : phone_number_(TlFetchString<string>::parse(p))
  , first_name_(TlFetchString<string>::parse(p))
  , last_name_(TlFetchString<string>::parse(p))
  , vcard_(TlFetchString<string>::parse(p))
  , user_id_(TlFetchLong::parse(p))
{}

void messageMediaContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(vcard_, s);
  TlStoreBinary::store(user_id_, s);
}

void messageMediaContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(vcard_, s);
  TlStoreBinary::store(user_id_, s);
}

void messageMediaContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaContact");
    s.store_field("phone_number", phone_number_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("vcard", vcard_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

const std::int32_t messageMediaUnsupported::ID;

object_ptr<MessageMedia> messageMediaUnsupported::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaUnsupported>();
}

void messageMediaUnsupported::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void messageMediaUnsupported::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void messageMediaUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaUnsupported");
    s.store_class_end();
  }
}

messageMediaDocument::messageMediaDocument()
  : flags_()
  , nopremium_()
  , spoiler_()
  , video_()
  , round_()
  , voice_()
  , document_()
  , alt_documents_()
  , video_cover_()
  , video_timestamp_()
  , ttl_seconds_()
{}

messageMediaDocument::messageMediaDocument(int32 flags_, bool nopremium_, bool spoiler_, bool video_, bool round_, bool voice_, object_ptr<Document> &&document_, array<object_ptr<Document>> &&alt_documents_, object_ptr<Photo> &&video_cover_, int32 video_timestamp_, int32 ttl_seconds_)
  : flags_(flags_)
  , nopremium_(nopremium_)
  , spoiler_(spoiler_)
  , video_(video_)
  , round_(round_)
  , voice_(voice_)
  , document_(std::move(document_))
  , alt_documents_(std::move(alt_documents_))
  , video_cover_(std::move(video_cover_))
  , video_timestamp_(video_timestamp_)
  , ttl_seconds_(ttl_seconds_)
{}

const std::int32_t messageMediaDocument::ID;

object_ptr<MessageMedia> messageMediaDocument::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaDocument> res = make_tl_object<messageMediaDocument>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->nopremium_ = (var0 & 8) != 0;
  res->spoiler_ = (var0 & 16) != 0;
  res->video_ = (var0 & 64) != 0;
  res->round_ = (var0 & 128) != 0;
  res->voice_ = (var0 & 256) != 0;
  if (var0 & 1) { res->document_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 32) { res->alt_documents_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p); }
  if (var0 & 512) { res->video_cover_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 1024) { res->video_timestamp_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (nopremium_ << 3) | (spoiler_ << 4) | (video_ << 6) | (round_ << 7) | (voice_ << 8)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(alt_documents_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 1024) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 4) { TlStoreBinary::store(ttl_seconds_, s); }
}

void messageMediaDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (nopremium_ << 3) | (spoiler_ << 4) | (video_ << 6) | (round_ << 7) | (voice_ << 8)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(alt_documents_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 1024) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 4) { TlStoreBinary::store(ttl_seconds_, s); }
}

void messageMediaDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaDocument");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (nopremium_ << 3) | (spoiler_ << 4) | (video_ << 6) | (round_ << 7) | (voice_ << 8)));
    if (var0 & 8) { s.store_field("nopremium", true); }
    if (var0 & 16) { s.store_field("spoiler", true); }
    if (var0 & 64) { s.store_field("video", true); }
    if (var0 & 128) { s.store_field("round", true); }
    if (var0 & 256) { s.store_field("voice", true); }
    if (var0 & 1) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 32) { { s.store_vector_begin("alt_documents", alt_documents_.size()); for (const auto &_value : alt_documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 512) { s.store_object_field("video_cover", static_cast<const BaseObject *>(video_cover_.get())); }
    if (var0 & 1024) { s.store_field("video_timestamp", video_timestamp_); }
    if (var0 & 4) { s.store_field("ttl_seconds", ttl_seconds_); }
    s.store_class_end();
  }
}

messageMediaWebPage::messageMediaWebPage()
  : flags_()
  , force_large_media_()
  , force_small_media_()
  , manual_()
  , safe_()
  , webpage_()
{}

messageMediaWebPage::messageMediaWebPage(int32 flags_, bool force_large_media_, bool force_small_media_, bool manual_, bool safe_, object_ptr<WebPage> &&webpage_)
  : flags_(flags_)
  , force_large_media_(force_large_media_)
  , force_small_media_(force_small_media_)
  , manual_(manual_)
  , safe_(safe_)
  , webpage_(std::move(webpage_))
{}

const std::int32_t messageMediaWebPage::ID;

object_ptr<MessageMedia> messageMediaWebPage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaWebPage> res = make_tl_object<messageMediaWebPage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->force_large_media_ = (var0 & 1) != 0;
  res->force_small_media_ = (var0 & 2) != 0;
  res->manual_ = (var0 & 8) != 0;
  res->safe_ = (var0 & 16) != 0;
  res->webpage_ = TlFetchObject<WebPage>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaWebPage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (force_large_media_ << 0) | (force_small_media_ << 1) | (manual_ << 3) | (safe_ << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(webpage_, s);
}

void messageMediaWebPage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (force_large_media_ << 0) | (force_small_media_ << 1) | (manual_ << 3) | (safe_ << 4)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(webpage_, s);
}

void messageMediaWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaWebPage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (force_large_media_ << 0) | (force_small_media_ << 1) | (manual_ << 3) | (safe_ << 4)));
    if (var0 & 1) { s.store_field("force_large_media", true); }
    if (var0 & 2) { s.store_field("force_small_media", true); }
    if (var0 & 8) { s.store_field("manual", true); }
    if (var0 & 16) { s.store_field("safe", true); }
    s.store_object_field("webpage", static_cast<const BaseObject *>(webpage_.get()));
    s.store_class_end();
  }
}

messageMediaVenue::messageMediaVenue(object_ptr<GeoPoint> &&geo_, string const &title_, string const &address_, string const &provider_, string const &venue_id_, string const &venue_type_)
  : geo_(std::move(geo_))
  , title_(title_)
  , address_(address_)
  , provider_(provider_)
  , venue_id_(venue_id_)
  , venue_type_(venue_type_)
{}

const std::int32_t messageMediaVenue::ID;

object_ptr<MessageMedia> messageMediaVenue::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaVenue>(p);
}

messageMediaVenue::messageMediaVenue(TlBufferParser &p)
  : geo_(TlFetchObject<GeoPoint>::parse(p))
  , title_(TlFetchString<string>::parse(p))
  , address_(TlFetchString<string>::parse(p))
  , provider_(TlFetchString<string>::parse(p))
  , venue_id_(TlFetchString<string>::parse(p))
  , venue_type_(TlFetchString<string>::parse(p))
{}

void messageMediaVenue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
}

void messageMediaVenue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
}

void messageMediaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaVenue");
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("venue_id", venue_id_);
    s.store_field("venue_type", venue_type_);
    s.store_class_end();
  }
}

messageMediaGame::messageMediaGame(object_ptr<game> &&game_)
  : game_(std::move(game_))
{}

const std::int32_t messageMediaGame::ID;

object_ptr<MessageMedia> messageMediaGame::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaGame>(p);
}

messageMediaGame::messageMediaGame(TlBufferParser &p)
  : game_(TlFetchBoxed<TlFetchObject<game>, -1107729093>::parse(p))
{}

void messageMediaGame::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -1107729093>::store(game_, s);
}

void messageMediaGame::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -1107729093>::store(game_, s);
}

void messageMediaGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaGame");
    s.store_object_field("game", static_cast<const BaseObject *>(game_.get()));
    s.store_class_end();
  }
}

messageMediaInvoice::messageMediaInvoice()
  : flags_()
  , shipping_address_requested_()
  , test_()
  , title_()
  , description_()
  , photo_()
  , receipt_msg_id_()
  , currency_()
  , total_amount_()
  , start_param_()
  , extended_media_()
{}

messageMediaInvoice::messageMediaInvoice(int32 flags_, bool shipping_address_requested_, bool test_, string const &title_, string const &description_, object_ptr<WebDocument> &&photo_, int32 receipt_msg_id_, string const &currency_, int64 total_amount_, string const &start_param_, object_ptr<MessageExtendedMedia> &&extended_media_)
  : flags_(flags_)
  , shipping_address_requested_(shipping_address_requested_)
  , test_(test_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , receipt_msg_id_(receipt_msg_id_)
  , currency_(currency_)
  , total_amount_(total_amount_)
  , start_param_(start_param_)
  , extended_media_(std::move(extended_media_))
{}

const std::int32_t messageMediaInvoice::ID;

object_ptr<MessageMedia> messageMediaInvoice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaInvoice> res = make_tl_object<messageMediaInvoice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->shipping_address_requested_ = (var0 & 2) != 0;
  res->test_ = (var0 & 8) != 0;
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  if (var0 & 4) { res->receipt_msg_id_ = TlFetchInt::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  res->start_param_ = TlFetchString<string>::parse(p);
  if (var0 & 16) { res->extended_media_ = TlFetchObject<MessageExtendedMedia>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaInvoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (shipping_address_requested_ << 1) | (test_ << 3)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s); }
  if (var0 & 4) { TlStoreBinary::store(receipt_msg_id_, s); }
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(total_amount_, s);
  TlStoreString::store(start_param_, s);
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(extended_media_, s); }
}

void messageMediaInvoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (shipping_address_requested_ << 1) | (test_ << 3)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s); }
  if (var0 & 4) { TlStoreBinary::store(receipt_msg_id_, s); }
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(total_amount_, s);
  TlStoreString::store(start_param_, s);
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(extended_media_, s); }
}

void messageMediaInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaInvoice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (shipping_address_requested_ << 1) | (test_ << 3)));
    if (var0 & 2) { s.store_field("shipping_address_requested", true); }
    if (var0 & 8) { s.store_field("test", true); }
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 1) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 4) { s.store_field("receipt_msg_id", receipt_msg_id_); }
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("start_param", start_param_);
    if (var0 & 16) { s.store_object_field("extended_media", static_cast<const BaseObject *>(extended_media_.get())); }
    s.store_class_end();
  }
}

messageMediaGeoLive::messageMediaGeoLive()
  : flags_()
  , geo_()
  , heading_()
  , period_()
  , proximity_notification_radius_()
{}

messageMediaGeoLive::messageMediaGeoLive(int32 flags_, object_ptr<GeoPoint> &&geo_, int32 heading_, int32 period_, int32 proximity_notification_radius_)
  : flags_(flags_)
  , geo_(std::move(geo_))
  , heading_(heading_)
  , period_(period_)
  , proximity_notification_radius_(proximity_notification_radius_)
{}

const std::int32_t messageMediaGeoLive::ID;

object_ptr<MessageMedia> messageMediaGeoLive::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaGeoLive> res = make_tl_object<messageMediaGeoLive>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->geo_ = TlFetchObject<GeoPoint>::parse(p);
  if (var0 & 1) { res->heading_ = TlFetchInt::parse(p); }
  res->period_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->proximity_notification_radius_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaGeoLive::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  if (var0 & 1) { TlStoreBinary::store(heading_, s); }
  TlStoreBinary::store(period_, s);
  if (var0 & 2) { TlStoreBinary::store(proximity_notification_radius_, s); }
}

void messageMediaGeoLive::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  if (var0 & 1) { TlStoreBinary::store(heading_, s); }
  TlStoreBinary::store(period_, s);
  if (var0 & 2) { TlStoreBinary::store(proximity_notification_radius_, s); }
}

void messageMediaGeoLive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaGeoLive");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    if (var0 & 1) { s.store_field("heading", heading_); }
    s.store_field("period", period_);
    if (var0 & 2) { s.store_field("proximity_notification_radius", proximity_notification_radius_); }
    s.store_class_end();
  }
}

messageMediaPoll::messageMediaPoll()
  : flags_()
  , poll_()
  , results_()
  , attached_media_()
{}

messageMediaPoll::messageMediaPoll(int32 flags_, object_ptr<poll> &&poll_, object_ptr<pollResults> &&results_, object_ptr<MessageMedia> &&attached_media_)
  : flags_(flags_)
  , poll_(std::move(poll_))
  , results_(std::move(results_))
  , attached_media_(std::move(attached_media_))
{}

const std::int32_t messageMediaPoll::ID;

object_ptr<MessageMedia> messageMediaPoll::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaPoll> res = make_tl_object<messageMediaPoll>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->poll_ = TlFetchBoxed<TlFetchObject<poll>, -1203610647>::parse(p);
  res->results_ = TlFetchBoxed<TlFetchObject<pollResults>, -1166298786>::parse(p);
  if (var0 & 1) { res->attached_media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaPoll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, -1203610647>::store(poll_, s);
  TlStoreBoxed<TlStoreObject, -1166298786>::store(results_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(attached_media_, s); }
}

void messageMediaPoll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, -1203610647>::store(poll_, s);
  TlStoreBoxed<TlStoreObject, -1166298786>::store(results_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(attached_media_, s); }
}

void messageMediaPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaPoll");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("poll", static_cast<const BaseObject *>(poll_.get()));
    s.store_object_field("results", static_cast<const BaseObject *>(results_.get()));
    if (var0 & 1) { s.store_object_field("attached_media", static_cast<const BaseObject *>(attached_media_.get())); }
    s.store_class_end();
  }
}

messageMediaDice::messageMediaDice()
  : flags_()
  , value_()
  , emoticon_()
  , game_outcome_()
{}

messageMediaDice::messageMediaDice(int32 flags_, int32 value_, string const &emoticon_, object_ptr<messages_emojiGameOutcome> &&game_outcome_)
  : flags_(flags_)
  , value_(value_)
  , emoticon_(emoticon_)
  , game_outcome_(std::move(game_outcome_))
{}

const std::int32_t messageMediaDice::ID;

object_ptr<MessageMedia> messageMediaDice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaDice> res = make_tl_object<messageMediaDice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->value_ = TlFetchInt::parse(p);
  res->emoticon_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->game_outcome_ = TlFetchBoxed<TlFetchObject<messages_emojiGameOutcome>, -634726841>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaDice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(value_, s);
  TlStoreString::store(emoticon_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -634726841>::store(game_outcome_, s); }
}

void messageMediaDice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(value_, s);
  TlStoreString::store(emoticon_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -634726841>::store(game_outcome_, s); }
}

void messageMediaDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaDice");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("value", value_);
    s.store_field("emoticon", emoticon_);
    if (var0 & 1) { s.store_object_field("game_outcome", static_cast<const BaseObject *>(game_outcome_.get())); }
    s.store_class_end();
  }
}

messageMediaStory::messageMediaStory()
  : flags_()
  , via_mention_()
  , peer_()
  , id_()
  , story_()
{}

messageMediaStory::messageMediaStory(int32 flags_, bool via_mention_, object_ptr<Peer> &&peer_, int32 id_, object_ptr<StoryItem> &&story_)
  : flags_(flags_)
  , via_mention_(via_mention_)
  , peer_(std::move(peer_))
  , id_(id_)
  , story_(std::move(story_))
{}

const std::int32_t messageMediaStory::ID;

object_ptr<MessageMedia> messageMediaStory::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaStory> res = make_tl_object<messageMediaStory>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->via_mention_ = (var0 & 2) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->story_ = TlFetchObject<StoryItem>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (via_mention_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(story_, s); }
}

void messageMediaStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (via_mention_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(story_, s); }
}

void messageMediaStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaStory");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (via_mention_ << 1)));
    if (var0 & 2) { s.store_field("via_mention", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("story", static_cast<const BaseObject *>(story_.get())); }
    s.store_class_end();
  }
}

messageMediaGiveaway::messageMediaGiveaway()
  : flags_()
  , only_new_subscribers_()
  , winners_are_visible_()
  , channels_()
  , countries_iso2_()
  , prize_description_()
  , quantity_()
  , months_()
  , stars_()
  , until_date_()
{}

messageMediaGiveaway::messageMediaGiveaway(int32 flags_, bool only_new_subscribers_, bool winners_are_visible_, array<int64> &&channels_, array<string> &&countries_iso2_, string const &prize_description_, int32 quantity_, int32 months_, int64 stars_, int32 until_date_)
  : flags_(flags_)
  , only_new_subscribers_(only_new_subscribers_)
  , winners_are_visible_(winners_are_visible_)
  , channels_(std::move(channels_))
  , countries_iso2_(std::move(countries_iso2_))
  , prize_description_(prize_description_)
  , quantity_(quantity_)
  , months_(months_)
  , stars_(stars_)
  , until_date_(until_date_)
{}

const std::int32_t messageMediaGiveaway::ID;

object_ptr<MessageMedia> messageMediaGiveaway::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaGiveaway> res = make_tl_object<messageMediaGiveaway>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->only_new_subscribers_ = (var0 & 1) != 0;
  res->winners_are_visible_ = (var0 & 4) != 0;
  res->channels_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p);
  if (var0 & 2) { res->countries_iso2_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p); }
  if (var0 & 8) { res->prize_description_ = TlFetchString<string>::parse(p); }
  res->quantity_ = TlFetchInt::parse(p);
  if (var0 & 16) { res->months_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->stars_ = TlFetchLong::parse(p); }
  res->until_date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaGiveaway::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 2)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(channels_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  if (var0 & 8) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(quantity_, s);
  if (var0 & 16) { TlStoreBinary::store(months_, s); }
  if (var0 & 32) { TlStoreBinary::store(stars_, s); }
  TlStoreBinary::store(until_date_, s);
}

void messageMediaGiveaway::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 2)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(channels_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(countries_iso2_, s); }
  if (var0 & 8) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(quantity_, s);
  if (var0 & 16) { TlStoreBinary::store(months_, s); }
  if (var0 & 32) { TlStoreBinary::store(stars_, s); }
  TlStoreBinary::store(until_date_, s);
}

void messageMediaGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaGiveaway");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (only_new_subscribers_ << 0) | (winners_are_visible_ << 2)));
    if (var0 & 1) { s.store_field("only_new_subscribers", true); }
    if (var0 & 4) { s.store_field("winners_are_visible", true); }
    { s.store_vector_begin("channels", channels_.size()); for (const auto &_value : channels_) { s.store_field("", _value); } s.store_class_end(); }
    if (var0 & 2) { { s.store_vector_begin("countries_iso2", countries_iso2_.size()); for (const auto &_value : countries_iso2_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 8) { s.store_field("prize_description", prize_description_); }
    s.store_field("quantity", quantity_);
    if (var0 & 16) { s.store_field("months", months_); }
    if (var0 & 32) { s.store_field("stars", stars_); }
    s.store_field("until_date", until_date_);
    s.store_class_end();
  }
}

messageMediaGiveawayResults::messageMediaGiveawayResults()
  : flags_()
  , only_new_subscribers_()
  , refunded_()
  , channel_id_()
  , additional_peers_count_()
  , launch_msg_id_()
  , winners_count_()
  , unclaimed_count_()
  , winners_()
  , months_()
  , stars_()
  , prize_description_()
  , until_date_()
{}

messageMediaGiveawayResults::messageMediaGiveawayResults(int32 flags_, bool only_new_subscribers_, bool refunded_, int64 channel_id_, int32 additional_peers_count_, int32 launch_msg_id_, int32 winners_count_, int32 unclaimed_count_, array<int64> &&winners_, int32 months_, int64 stars_, string const &prize_description_, int32 until_date_)
  : flags_(flags_)
  , only_new_subscribers_(only_new_subscribers_)
  , refunded_(refunded_)
  , channel_id_(channel_id_)
  , additional_peers_count_(additional_peers_count_)
  , launch_msg_id_(launch_msg_id_)
  , winners_count_(winners_count_)
  , unclaimed_count_(unclaimed_count_)
  , winners_(std::move(winners_))
  , months_(months_)
  , stars_(stars_)
  , prize_description_(prize_description_)
  , until_date_(until_date_)
{}

const std::int32_t messageMediaGiveawayResults::ID;

object_ptr<MessageMedia> messageMediaGiveawayResults::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaGiveawayResults> res = make_tl_object<messageMediaGiveawayResults>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->only_new_subscribers_ = (var0 & 1) != 0;
  res->refunded_ = (var0 & 4) != 0;
  res->channel_id_ = TlFetchLong::parse(p);
  if (var0 & 8) { res->additional_peers_count_ = TlFetchInt::parse(p); }
  res->launch_msg_id_ = TlFetchInt::parse(p);
  res->winners_count_ = TlFetchInt::parse(p);
  res->unclaimed_count_ = TlFetchInt::parse(p);
  res->winners_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p);
  if (var0 & 16) { res->months_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->stars_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->prize_description_ = TlFetchString<string>::parse(p); }
  res->until_date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaGiveawayResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (refunded_ << 2)), s);
  TlStoreBinary::store(channel_id_, s);
  if (var0 & 8) { TlStoreBinary::store(additional_peers_count_, s); }
  TlStoreBinary::store(launch_msg_id_, s);
  TlStoreBinary::store(winners_count_, s);
  TlStoreBinary::store(unclaimed_count_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(winners_, s);
  if (var0 & 16) { TlStoreBinary::store(months_, s); }
  if (var0 & 32) { TlStoreBinary::store(stars_, s); }
  if (var0 & 2) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(until_date_, s);
}

void messageMediaGiveawayResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (only_new_subscribers_ << 0) | (refunded_ << 2)), s);
  TlStoreBinary::store(channel_id_, s);
  if (var0 & 8) { TlStoreBinary::store(additional_peers_count_, s); }
  TlStoreBinary::store(launch_msg_id_, s);
  TlStoreBinary::store(winners_count_, s);
  TlStoreBinary::store(unclaimed_count_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(winners_, s);
  if (var0 & 16) { TlStoreBinary::store(months_, s); }
  if (var0 & 32) { TlStoreBinary::store(stars_, s); }
  if (var0 & 2) { TlStoreString::store(prize_description_, s); }
  TlStoreBinary::store(until_date_, s);
}

void messageMediaGiveawayResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaGiveawayResults");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (only_new_subscribers_ << 0) | (refunded_ << 2)));
    if (var0 & 1) { s.store_field("only_new_subscribers", true); }
    if (var0 & 4) { s.store_field("refunded", true); }
    s.store_field("channel_id", channel_id_);
    if (var0 & 8) { s.store_field("additional_peers_count", additional_peers_count_); }
    s.store_field("launch_msg_id", launch_msg_id_);
    s.store_field("winners_count", winners_count_);
    s.store_field("unclaimed_count", unclaimed_count_);
    { s.store_vector_begin("winners", winners_.size()); for (const auto &_value : winners_) { s.store_field("", _value); } s.store_class_end(); }
    if (var0 & 16) { s.store_field("months", months_); }
    if (var0 & 32) { s.store_field("stars", stars_); }
    if (var0 & 2) { s.store_field("prize_description", prize_description_); }
    s.store_field("until_date", until_date_);
    s.store_class_end();
  }
}

messageMediaPaidMedia::messageMediaPaidMedia(int64 stars_amount_, array<object_ptr<MessageExtendedMedia>> &&extended_media_)
  : stars_amount_(stars_amount_)
  , extended_media_(std::move(extended_media_))
{}

const std::int32_t messageMediaPaidMedia::ID;

object_ptr<MessageMedia> messageMediaPaidMedia::fetch(TlBufferParser &p) {
  return make_tl_object<messageMediaPaidMedia>(p);
}

messageMediaPaidMedia::messageMediaPaidMedia(TlBufferParser &p)
  : stars_amount_(TlFetchLong::parse(p))
  , extended_media_(TlFetchBoxed<TlFetchVector<TlFetchObject<MessageExtendedMedia>>, 481674261>::parse(p))
{}

void messageMediaPaidMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(stars_amount_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(extended_media_, s);
}

void messageMediaPaidMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(stars_amount_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(extended_media_, s);
}

void messageMediaPaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaPaidMedia");
    s.store_field("stars_amount", stars_amount_);
    { s.store_vector_begin("extended_media", extended_media_.size()); for (const auto &_value : extended_media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messageMediaToDo::messageMediaToDo()
  : flags_()
  , todo_()
  , completions_()
{}

messageMediaToDo::messageMediaToDo(int32 flags_, object_ptr<todoList> &&todo_, array<object_ptr<todoCompletion>> &&completions_)
  : flags_(flags_)
  , todo_(std::move(todo_))
  , completions_(std::move(completions_))
{}

const std::int32_t messageMediaToDo::ID;

object_ptr<MessageMedia> messageMediaToDo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaToDo> res = make_tl_object<messageMediaToDo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->todo_ = TlFetchBoxed<TlFetchObject<todoList>, 1236871718>::parse(p);
  if (var0 & 1) { res->completions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<todoCompletion>, 572241380>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaToDo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, 1236871718>::store(todo_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 572241380>>, 481674261>::store(completions_, s); }
}

void messageMediaToDo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, 1236871718>::store(todo_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 572241380>>, 481674261>::store(completions_, s); }
}

void messageMediaToDo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaToDo");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("todo", static_cast<const BaseObject *>(todo_.get()));
    if (var0 & 1) { { s.store_vector_begin("completions", completions_.size()); for (const auto &_value : completions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

messageMediaVideoStream::messageMediaVideoStream()
  : flags_()
  , rtmp_stream_()
  , call_()
{}

messageMediaVideoStream::messageMediaVideoStream(int32 flags_, bool rtmp_stream_, object_ptr<InputGroupCall> &&call_)
  : flags_(flags_)
  , rtmp_stream_(rtmp_stream_)
  , call_(std::move(call_))
{}

const std::int32_t messageMediaVideoStream::ID;

object_ptr<MessageMedia> messageMediaVideoStream::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageMediaVideoStream> res = make_tl_object<messageMediaVideoStream>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->rtmp_stream_ = (var0 & 1) != 0;
  res->call_ = TlFetchObject<InputGroupCall>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageMediaVideoStream::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (rtmp_stream_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void messageMediaVideoStream::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (rtmp_stream_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void messageMediaVideoStream::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageMediaVideoStream");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (rtmp_stream_ << 0)));
    if (var0 & 1) { s.store_field("rtmp_stream", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

const std::int32_t pendingSuggestion::ID;

object_ptr<pendingSuggestion> pendingSuggestion::fetch(TlBufferParser &p) {
  return make_tl_object<pendingSuggestion>(p);
}

pendingSuggestion::pendingSuggestion(TlBufferParser &p)
  : suggestion_(TlFetchString<string>::parse(p))
  , title_(TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p))
  , description_(TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p))
  , url_(TlFetchString<string>::parse(p))
{}

void pendingSuggestion::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pendingSuggestion");
    s.store_field("suggestion", suggestion_);
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    s.store_object_field("description", static_cast<const BaseObject *>(description_.get()));
    s.store_field("url", url_);
    s.store_class_end();
  }
}

phoneCallProtocol::phoneCallProtocol()
  : flags_()
  , udp_p2p_()
  , udp_reflector_()
  , min_layer_()
  , max_layer_()
  , library_versions_()
{}

phoneCallProtocol::phoneCallProtocol(int32 flags_, bool udp_p2p_, bool udp_reflector_, int32 min_layer_, int32 max_layer_, array<string> &&library_versions_)
  : flags_(flags_)
  , udp_p2p_(udp_p2p_)
  , udp_reflector_(udp_reflector_)
  , min_layer_(min_layer_)
  , max_layer_(max_layer_)
  , library_versions_(std::move(library_versions_))
{}

const std::int32_t phoneCallProtocol::ID;

object_ptr<phoneCallProtocol> phoneCallProtocol::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneCallProtocol> res = make_tl_object<phoneCallProtocol>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->udp_p2p_ = (var0 & 1) != 0;
  res->udp_reflector_ = (var0 & 2) != 0;
  res->min_layer_ = TlFetchInt::parse(p);
  res->max_layer_ = TlFetchInt::parse(p);
  res->library_versions_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void phoneCallProtocol::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (udp_p2p_ << 0) | (udp_reflector_ << 1)), s);
  TlStoreBinary::store(min_layer_, s);
  TlStoreBinary::store(max_layer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(library_versions_, s);
}

void phoneCallProtocol::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (udp_p2p_ << 0) | (udp_reflector_ << 1)), s);
  TlStoreBinary::store(min_layer_, s);
  TlStoreBinary::store(max_layer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(library_versions_, s);
}

void phoneCallProtocol::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallProtocol");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (udp_p2p_ << 0) | (udp_reflector_ << 1)));
    if (var0 & 1) { s.store_field("udp_p2p", true); }
    if (var0 & 2) { s.store_field("udp_reflector", true); }
    s.store_field("min_layer", min_layer_);
    s.store_field("max_layer", max_layer_);
    { s.store_vector_begin("library_versions", library_versions_.size()); for (const auto &_value : library_versions_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<PostInteractionCounters> PostInteractionCounters::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case postInteractionCountersMessage::ID:
      return postInteractionCountersMessage::fetch(p);
    case postInteractionCountersStory::ID:
      return postInteractionCountersStory::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t postInteractionCountersMessage::ID;

object_ptr<PostInteractionCounters> postInteractionCountersMessage::fetch(TlBufferParser &p) {
  return make_tl_object<postInteractionCountersMessage>(p);
}

postInteractionCountersMessage::postInteractionCountersMessage(TlBufferParser &p)
  : msg_id_(TlFetchInt::parse(p))
  , views_(TlFetchInt::parse(p))
  , forwards_(TlFetchInt::parse(p))
  , reactions_(TlFetchInt::parse(p))
{}

void postInteractionCountersMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "postInteractionCountersMessage");
    s.store_field("msg_id", msg_id_);
    s.store_field("views", views_);
    s.store_field("forwards", forwards_);
    s.store_field("reactions", reactions_);
    s.store_class_end();
  }
}

const std::int32_t postInteractionCountersStory::ID;

object_ptr<PostInteractionCounters> postInteractionCountersStory::fetch(TlBufferParser &p) {
  return make_tl_object<postInteractionCountersStory>(p);
}

postInteractionCountersStory::postInteractionCountersStory(TlBufferParser &p)
  : story_id_(TlFetchInt::parse(p))
  , views_(TlFetchInt::parse(p))
  , forwards_(TlFetchInt::parse(p))
  , reactions_(TlFetchInt::parse(p))
{}

void postInteractionCountersStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "postInteractionCountersStory");
    s.store_field("story_id", story_id_);
    s.store_field("views", views_);
    s.store_field("forwards", forwards_);
    s.store_field("reactions", reactions_);
    s.store_class_end();
  }
}

object_ptr<Reaction> Reaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case reactionEmpty::ID:
      return reactionEmpty::fetch(p);
    case reactionEmoji::ID:
      return reactionEmoji::fetch(p);
    case reactionCustomEmoji::ID:
      return reactionCustomEmoji::fetch(p);
    case reactionPaid::ID:
      return reactionPaid::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t reactionEmpty::ID;

object_ptr<Reaction> reactionEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<reactionEmpty>();
}

void reactionEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void reactionEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void reactionEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionEmpty");
    s.store_class_end();
  }
}

reactionEmoji::reactionEmoji(string const &emoticon_)
  : emoticon_(emoticon_)
{}

const std::int32_t reactionEmoji::ID;

object_ptr<Reaction> reactionEmoji::fetch(TlBufferParser &p) {
  return make_tl_object<reactionEmoji>(p);
}

reactionEmoji::reactionEmoji(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
{}

void reactionEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void reactionEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void reactionEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionEmoji");
    s.store_field("emoticon", emoticon_);
    s.store_class_end();
  }
}

reactionCustomEmoji::reactionCustomEmoji(int64 document_id_)
  : document_id_(document_id_)
{}

const std::int32_t reactionCustomEmoji::ID;

object_ptr<Reaction> reactionCustomEmoji::fetch(TlBufferParser &p) {
  return make_tl_object<reactionCustomEmoji>(p);
}

reactionCustomEmoji::reactionCustomEmoji(TlBufferParser &p)
  : document_id_(TlFetchLong::parse(p))
{}

void reactionCustomEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
}

void reactionCustomEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
}

void reactionCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionCustomEmoji");
    s.store_field("document_id", document_id_);
    s.store_class_end();
  }
}

const std::int32_t reactionPaid::ID;

object_ptr<Reaction> reactionPaid::fetch(TlBufferParser &p) {
  return make_tl_object<reactionPaid>();
}

void reactionPaid::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void reactionPaid::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void reactionPaid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionPaid");
    s.store_class_end();
  }
}

const std::int32_t searchResultPosition::ID;

object_ptr<searchResultPosition> searchResultPosition::fetch(TlBufferParser &p) {
  return make_tl_object<searchResultPosition>(p);
}

searchResultPosition::searchResultPosition(TlBufferParser &p)
  : msg_id_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , offset_(TlFetchInt::parse(p))
{}

void searchResultPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchResultPosition");
    s.store_field("msg_id", msg_id_);
    s.store_field("date", date_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

const std::int32_t sponsoredMessageReportOption::ID;

object_ptr<sponsoredMessageReportOption> sponsoredMessageReportOption::fetch(TlBufferParser &p) {
  return make_tl_object<sponsoredMessageReportOption>(p);
}

sponsoredMessageReportOption::sponsoredMessageReportOption(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , option_(TlFetchBytes<bytes>::parse(p))
{}

void sponsoredMessageReportOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredMessageReportOption");
    s.store_field("text", text_);
    s.store_bytes_field("option", option_);
    s.store_class_end();
  }
}

object_ptr<StarGift> StarGift::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starGift::ID:
      return starGift::fetch(p);
    case starGiftUnique::ID:
      return starGiftUnique::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

starGift::starGift()
  : flags_()
  , limited_()
  , sold_out_()
  , birthday_()
  , require_premium_()
  , limited_per_user_()
  , peer_color_available_()
  , auction_()
  , id_()
  , sticker_()
  , stars_()
  , availability_remains_()
  , availability_total_()
  , availability_resale_()
  , convert_stars_()
  , first_sale_date_()
  , last_sale_date_()
  , upgrade_stars_()
  , resell_min_stars_()
  , title_()
  , released_by_()
  , per_user_total_()
  , per_user_remains_()
  , locked_until_date_()
  , auction_slug_()
  , gifts_per_round_()
  , auction_start_date_()
  , upgrade_variants_()
  , background_()
{}

starGift::starGift(int32 flags_, bool limited_, bool sold_out_, bool birthday_, bool require_premium_, bool limited_per_user_, bool peer_color_available_, bool auction_, int64 id_, object_ptr<Document> &&sticker_, int64 stars_, int32 availability_remains_, int32 availability_total_, int64 availability_resale_, int64 convert_stars_, int32 first_sale_date_, int32 last_sale_date_, int64 upgrade_stars_, int64 resell_min_stars_, string const &title_, object_ptr<Peer> &&released_by_, int32 per_user_total_, int32 per_user_remains_, int32 locked_until_date_, string const &auction_slug_, int32 gifts_per_round_, int32 auction_start_date_, int32 upgrade_variants_, object_ptr<starGiftBackground> &&background_)
  : flags_(flags_)
  , limited_(limited_)
  , sold_out_(sold_out_)
  , birthday_(birthday_)
  , require_premium_(require_premium_)
  , limited_per_user_(limited_per_user_)
  , peer_color_available_(peer_color_available_)
  , auction_(auction_)
  , id_(id_)
  , sticker_(std::move(sticker_))
  , stars_(stars_)
  , availability_remains_(availability_remains_)
  , availability_total_(availability_total_)
  , availability_resale_(availability_resale_)
  , convert_stars_(convert_stars_)
  , first_sale_date_(first_sale_date_)
  , last_sale_date_(last_sale_date_)
  , upgrade_stars_(upgrade_stars_)
  , resell_min_stars_(resell_min_stars_)
  , title_(title_)
  , released_by_(std::move(released_by_))
  , per_user_total_(per_user_total_)
  , per_user_remains_(per_user_remains_)
  , locked_until_date_(locked_until_date_)
  , auction_slug_(auction_slug_)
  , gifts_per_round_(gifts_per_round_)
  , auction_start_date_(auction_start_date_)
  , upgrade_variants_(upgrade_variants_)
  , background_(std::move(background_))
{}

const std::int32_t starGift::ID;

object_ptr<StarGift> starGift::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGift> res = make_tl_object<starGift>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->limited_ = (var0 & 1) != 0;
  res->sold_out_ = (var0 & 2) != 0;
  res->birthday_ = (var0 & 4) != 0;
  res->require_premium_ = (var0 & 128) != 0;
  res->limited_per_user_ = (var0 & 256) != 0;
  res->peer_color_available_ = (var0 & 1024) != 0;
  res->auction_ = (var0 & 2048) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->sticker_ = TlFetchObject<Document>::parse(p);
  res->stars_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->availability_remains_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->availability_total_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->availability_resale_ = TlFetchLong::parse(p); }
  res->convert_stars_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->first_sale_date_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->last_sale_date_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->upgrade_stars_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->resell_min_stars_ = TlFetchLong::parse(p); }
  if (var0 & 32) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 64) { res->released_by_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 256) { res->per_user_total_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->per_user_remains_ = TlFetchInt::parse(p); }
  if (var0 & 512) { res->locked_until_date_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->auction_slug_ = TlFetchString<string>::parse(p); }
  if (var0 & 2048) { res->gifts_per_round_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->auction_start_date_ = TlFetchInt::parse(p); }
  if (var0 & 4096) { res->upgrade_variants_ = TlFetchInt::parse(p); }
  if (var0 & 8192) { res->background_ = TlFetchBoxed<TlFetchObject<starGiftBackground>, -1342872680>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void starGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (limited_ << 0) | (sold_out_ << 1) | (birthday_ << 2) | (require_premium_ << 7) | (limited_per_user_ << 8) | (peer_color_available_ << 10) | (auction_ << 11)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  TlStoreBinary::store(stars_, s);
  if (var0 & 1) { TlStoreBinary::store(availability_remains_, s); }
  if (var0 & 1) { TlStoreBinary::store(availability_total_, s); }
  if (var0 & 16) { TlStoreBinary::store(availability_resale_, s); }
  TlStoreBinary::store(convert_stars_, s);
  if (var0 & 2) { TlStoreBinary::store(first_sale_date_, s); }
  if (var0 & 2) { TlStoreBinary::store(last_sale_date_, s); }
  if (var0 & 8) { TlStoreBinary::store(upgrade_stars_, s); }
  if (var0 & 16) { TlStoreBinary::store(resell_min_stars_, s); }
  if (var0 & 32) { TlStoreString::store(title_, s); }
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(released_by_, s); }
  if (var0 & 256) { TlStoreBinary::store(per_user_total_, s); }
  if (var0 & 256) { TlStoreBinary::store(per_user_remains_, s); }
  if (var0 & 512) { TlStoreBinary::store(locked_until_date_, s); }
  if (var0 & 2048) { TlStoreString::store(auction_slug_, s); }
  if (var0 & 2048) { TlStoreBinary::store(gifts_per_round_, s); }
  if (var0 & 2048) { TlStoreBinary::store(auction_start_date_, s); }
  if (var0 & 4096) { TlStoreBinary::store(upgrade_variants_, s); }
  if (var0 & 8192) { TlStoreBoxed<TlStoreObject, -1342872680>::store(background_, s); }
}

void starGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (limited_ << 0) | (sold_out_ << 1) | (birthday_ << 2) | (require_premium_ << 7) | (limited_per_user_ << 8) | (peer_color_available_ << 10) | (auction_ << 11)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  TlStoreBinary::store(stars_, s);
  if (var0 & 1) { TlStoreBinary::store(availability_remains_, s); }
  if (var0 & 1) { TlStoreBinary::store(availability_total_, s); }
  if (var0 & 16) { TlStoreBinary::store(availability_resale_, s); }
  TlStoreBinary::store(convert_stars_, s);
  if (var0 & 2) { TlStoreBinary::store(first_sale_date_, s); }
  if (var0 & 2) { TlStoreBinary::store(last_sale_date_, s); }
  if (var0 & 8) { TlStoreBinary::store(upgrade_stars_, s); }
  if (var0 & 16) { TlStoreBinary::store(resell_min_stars_, s); }
  if (var0 & 32) { TlStoreString::store(title_, s); }
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(released_by_, s); }
  if (var0 & 256) { TlStoreBinary::store(per_user_total_, s); }
  if (var0 & 256) { TlStoreBinary::store(per_user_remains_, s); }
  if (var0 & 512) { TlStoreBinary::store(locked_until_date_, s); }
  if (var0 & 2048) { TlStoreString::store(auction_slug_, s); }
  if (var0 & 2048) { TlStoreBinary::store(gifts_per_round_, s); }
  if (var0 & 2048) { TlStoreBinary::store(auction_start_date_, s); }
  if (var0 & 4096) { TlStoreBinary::store(upgrade_variants_, s); }
  if (var0 & 8192) { TlStoreBoxed<TlStoreObject, -1342872680>::store(background_, s); }
}

void starGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGift");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (limited_ << 0) | (sold_out_ << 1) | (birthday_ << 2) | (require_premium_ << 7) | (limited_per_user_ << 8) | (peer_color_available_ << 10) | (auction_ << 11)));
    if (var0 & 1) { s.store_field("limited", true); }
    if (var0 & 2) { s.store_field("sold_out", true); }
    if (var0 & 4) { s.store_field("birthday", true); }
    if (var0 & 128) { s.store_field("require_premium", true); }
    if (var0 & 256) { s.store_field("limited_per_user", true); }
    if (var0 & 1024) { s.store_field("peer_color_available", true); }
    if (var0 & 2048) { s.store_field("auction", true); }
    s.store_field("id", id_);
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("stars", stars_);
    if (var0 & 1) { s.store_field("availability_remains", availability_remains_); }
    if (var0 & 1) { s.store_field("availability_total", availability_total_); }
    if (var0 & 16) { s.store_field("availability_resale", availability_resale_); }
    s.store_field("convert_stars", convert_stars_);
    if (var0 & 2) { s.store_field("first_sale_date", first_sale_date_); }
    if (var0 & 2) { s.store_field("last_sale_date", last_sale_date_); }
    if (var0 & 8) { s.store_field("upgrade_stars", upgrade_stars_); }
    if (var0 & 16) { s.store_field("resell_min_stars", resell_min_stars_); }
    if (var0 & 32) { s.store_field("title", title_); }
    if (var0 & 64) { s.store_object_field("released_by", static_cast<const BaseObject *>(released_by_.get())); }
    if (var0 & 256) { s.store_field("per_user_total", per_user_total_); }
    if (var0 & 256) { s.store_field("per_user_remains", per_user_remains_); }
    if (var0 & 512) { s.store_field("locked_until_date", locked_until_date_); }
    if (var0 & 2048) { s.store_field("auction_slug", auction_slug_); }
    if (var0 & 2048) { s.store_field("gifts_per_round", gifts_per_round_); }
    if (var0 & 2048) { s.store_field("auction_start_date", auction_start_date_); }
    if (var0 & 4096) { s.store_field("upgrade_variants", upgrade_variants_); }
    if (var0 & 8192) { s.store_object_field("background", static_cast<const BaseObject *>(background_.get())); }
    s.store_class_end();
  }
}

starGiftUnique::starGiftUnique()
  : flags_()
  , require_premium_()
  , resale_ton_only_()
  , theme_available_()
  , burned_()
  , crafted_()
  , id_()
  , gift_id_()
  , title_()
  , slug_()
  , num_()
  , owner_id_()
  , owner_name_()
  , owner_address_()
  , attributes_()
  , availability_issued_()
  , availability_total_()
  , gift_address_()
  , resell_amount_()
  , released_by_()
  , value_amount_()
  , value_currency_()
  , value_usd_amount_()
  , theme_peer_()
  , peer_color_()
  , host_id_()
  , offer_min_stars_()
  , craft_chance_permille_()
{}

starGiftUnique::starGiftUnique(int32 flags_, bool require_premium_, bool resale_ton_only_, bool theme_available_, bool burned_, bool crafted_, int64 id_, int64 gift_id_, string const &title_, string const &slug_, int32 num_, object_ptr<Peer> &&owner_id_, string const &owner_name_, string const &owner_address_, array<object_ptr<StarGiftAttribute>> &&attributes_, int32 availability_issued_, int32 availability_total_, string const &gift_address_, array<object_ptr<StarsAmount>> &&resell_amount_, object_ptr<Peer> &&released_by_, int64 value_amount_, string const &value_currency_, int64 value_usd_amount_, object_ptr<Peer> &&theme_peer_, object_ptr<PeerColor> &&peer_color_, object_ptr<Peer> &&host_id_, int32 offer_min_stars_, int32 craft_chance_permille_)
  : flags_(flags_)
  , require_premium_(require_premium_)
  , resale_ton_only_(resale_ton_only_)
  , theme_available_(theme_available_)
  , burned_(burned_)
  , crafted_(crafted_)
  , id_(id_)
  , gift_id_(gift_id_)
  , title_(title_)
  , slug_(slug_)
  , num_(num_)
  , owner_id_(std::move(owner_id_))
  , owner_name_(owner_name_)
  , owner_address_(owner_address_)
  , attributes_(std::move(attributes_))
  , availability_issued_(availability_issued_)
  , availability_total_(availability_total_)
  , gift_address_(gift_address_)
  , resell_amount_(std::move(resell_amount_))
  , released_by_(std::move(released_by_))
  , value_amount_(value_amount_)
  , value_currency_(value_currency_)
  , value_usd_amount_(value_usd_amount_)
  , theme_peer_(std::move(theme_peer_))
  , peer_color_(std::move(peer_color_))
  , host_id_(std::move(host_id_))
  , offer_min_stars_(offer_min_stars_)
  , craft_chance_permille_(craft_chance_permille_)
{}

const std::int32_t starGiftUnique::ID;

object_ptr<StarGift> starGiftUnique::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftUnique> res = make_tl_object<starGiftUnique>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->require_premium_ = (var0 & 64) != 0;
  res->resale_ton_only_ = (var0 & 128) != 0;
  res->theme_available_ = (var0 & 512) != 0;
  res->burned_ = (var0 & 16384) != 0;
  res->crafted_ = (var0 & 32768) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->gift_id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->slug_ = TlFetchString<string>::parse(p);
  res->num_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->owner_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 2) { res->owner_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->owner_address_ = TlFetchString<string>::parse(p); }
  res->attributes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StarGiftAttribute>>, 481674261>::parse(p);
  res->availability_issued_ = TlFetchInt::parse(p);
  res->availability_total_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->gift_address_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->resell_amount_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StarsAmount>>, 481674261>::parse(p); }
  if (var0 & 32) { res->released_by_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 256) { res->value_amount_ = TlFetchLong::parse(p); }
  if (var0 & 256) { res->value_currency_ = TlFetchString<string>::parse(p); }
  if (var0 & 256) { res->value_usd_amount_ = TlFetchLong::parse(p); }
  if (var0 & 1024) { res->theme_peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 2048) { res->peer_color_ = TlFetchObject<PeerColor>::parse(p); }
  if (var0 & 4096) { res->host_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 8192) { res->offer_min_stars_ = TlFetchInt::parse(p); }
  if (var0 & 65536) { res->craft_chance_permille_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void starGiftUnique::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (require_premium_ << 6) | (resale_ton_only_ << 7) | (theme_available_ << 9) | (burned_ << 14) | (crafted_ << 15)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(gift_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(num_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(owner_id_, s); }
  if (var0 & 2) { TlStoreString::store(owner_name_, s); }
  if (var0 & 4) { TlStoreString::store(owner_address_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
  TlStoreBinary::store(availability_issued_, s);
  TlStoreBinary::store(availability_total_, s);
  if (var0 & 8) { TlStoreString::store(gift_address_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(resell_amount_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(released_by_, s); }
  if (var0 & 256) { TlStoreBinary::store(value_amount_, s); }
  if (var0 & 256) { TlStoreString::store(value_currency_, s); }
  if (var0 & 256) { TlStoreBinary::store(value_usd_amount_, s); }
  if (var0 & 1024) { TlStoreBoxedUnknown<TlStoreObject>::store(theme_peer_, s); }
  if (var0 & 2048) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_color_, s); }
  if (var0 & 4096) { TlStoreBoxedUnknown<TlStoreObject>::store(host_id_, s); }
  if (var0 & 8192) { TlStoreBinary::store(offer_min_stars_, s); }
  if (var0 & 65536) { TlStoreBinary::store(craft_chance_permille_, s); }
}

void starGiftUnique::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (require_premium_ << 6) | (resale_ton_only_ << 7) | (theme_available_ << 9) | (burned_ << 14) | (crafted_ << 15)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(gift_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(num_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(owner_id_, s); }
  if (var0 & 2) { TlStoreString::store(owner_name_, s); }
  if (var0 & 4) { TlStoreString::store(owner_address_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
  TlStoreBinary::store(availability_issued_, s);
  TlStoreBinary::store(availability_total_, s);
  if (var0 & 8) { TlStoreString::store(gift_address_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(resell_amount_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(released_by_, s); }
  if (var0 & 256) { TlStoreBinary::store(value_amount_, s); }
  if (var0 & 256) { TlStoreString::store(value_currency_, s); }
  if (var0 & 256) { TlStoreBinary::store(value_usd_amount_, s); }
  if (var0 & 1024) { TlStoreBoxedUnknown<TlStoreObject>::store(theme_peer_, s); }
  if (var0 & 2048) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_color_, s); }
  if (var0 & 4096) { TlStoreBoxedUnknown<TlStoreObject>::store(host_id_, s); }
  if (var0 & 8192) { TlStoreBinary::store(offer_min_stars_, s); }
  if (var0 & 65536) { TlStoreBinary::store(craft_chance_permille_, s); }
}

void starGiftUnique::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftUnique");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (require_premium_ << 6) | (resale_ton_only_ << 7) | (theme_available_ << 9) | (burned_ << 14) | (crafted_ << 15)));
    if (var0 & 64) { s.store_field("require_premium", true); }
    if (var0 & 128) { s.store_field("resale_ton_only", true); }
    if (var0 & 512) { s.store_field("theme_available", true); }
    if (var0 & 16384) { s.store_field("burned", true); }
    if (var0 & 32768) { s.store_field("crafted", true); }
    s.store_field("id", id_);
    s.store_field("gift_id", gift_id_);
    s.store_field("title", title_);
    s.store_field("slug", slug_);
    s.store_field("num", num_);
    if (var0 & 1) { s.store_object_field("owner_id", static_cast<const BaseObject *>(owner_id_.get())); }
    if (var0 & 2) { s.store_field("owner_name", owner_name_); }
    if (var0 & 4) { s.store_field("owner_address", owner_address_); }
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("availability_issued", availability_issued_);
    s.store_field("availability_total", availability_total_);
    if (var0 & 8) { s.store_field("gift_address", gift_address_); }
    if (var0 & 16) { { s.store_vector_begin("resell_amount", resell_amount_.size()); for (const auto &_value : resell_amount_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 32) { s.store_object_field("released_by", static_cast<const BaseObject *>(released_by_.get())); }
    if (var0 & 256) { s.store_field("value_amount", value_amount_); }
    if (var0 & 256) { s.store_field("value_currency", value_currency_); }
    if (var0 & 256) { s.store_field("value_usd_amount", value_usd_amount_); }
    if (var0 & 1024) { s.store_object_field("theme_peer", static_cast<const BaseObject *>(theme_peer_.get())); }
    if (var0 & 2048) { s.store_object_field("peer_color", static_cast<const BaseObject *>(peer_color_.get())); }
    if (var0 & 4096) { s.store_object_field("host_id", static_cast<const BaseObject *>(host_id_.get())); }
    if (var0 & 8192) { s.store_field("offer_min_stars", offer_min_stars_); }
    if (var0 & 65536) { s.store_field("craft_chance_permille", craft_chance_permille_); }
    s.store_class_end();
  }
}

const std::int32_t starGiftActiveAuctionState::ID;

object_ptr<starGiftActiveAuctionState> starGiftActiveAuctionState::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftActiveAuctionState>(p);
}

starGiftActiveAuctionState::starGiftActiveAuctionState(TlBufferParser &p)
  : gift_(TlFetchObject<StarGift>::parse(p))
  , state_(TlFetchObject<StarGiftAuctionState>::parse(p))
  , user_state_(TlFetchBoxed<TlFetchObject<starGiftAuctionUserState>, 787403204>::parse(p))
{}

void starGiftActiveAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftActiveAuctionState");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_object_field("user_state", static_cast<const BaseObject *>(user_state_.get()));
    s.store_class_end();
  }
}

starGiftAuctionAcquiredGift::starGiftAuctionAcquiredGift()
  : flags_()
  , name_hidden_()
  , peer_()
  , date_()
  , bid_amount_()
  , round_()
  , pos_()
  , message_()
  , gift_num_()
{}

const std::int32_t starGiftAuctionAcquiredGift::ID;

object_ptr<starGiftAuctionAcquiredGift> starGiftAuctionAcquiredGift::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftAuctionAcquiredGift> res = make_tl_object<starGiftAuctionAcquiredGift>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->name_hidden_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->bid_amount_ = TlFetchLong::parse(p);
  res->round_ = TlFetchInt::parse(p);
  res->pos_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->message_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (var0 & 4) { res->gift_num_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starGiftAuctionAcquiredGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionAcquiredGift");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (name_hidden_ << 0)));
    if (var0 & 1) { s.store_field("name_hidden", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("date", date_);
    s.store_field("bid_amount", bid_amount_);
    s.store_field("round", round_);
    s.store_field("pos", pos_);
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    if (var0 & 4) { s.store_field("gift_num", gift_num_); }
    s.store_class_end();
  }
}

object_ptr<StarGiftAuctionState> StarGiftAuctionState::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starGiftAuctionStateNotModified::ID:
      return starGiftAuctionStateNotModified::fetch(p);
    case starGiftAuctionState::ID:
      return starGiftAuctionState::fetch(p);
    case starGiftAuctionStateFinished::ID:
      return starGiftAuctionStateFinished::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t starGiftAuctionStateNotModified::ID;

object_ptr<StarGiftAuctionState> starGiftAuctionStateNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAuctionStateNotModified>();
}

void starGiftAuctionStateNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionStateNotModified");
    s.store_class_end();
  }
}

const std::int32_t starGiftAuctionState::ID;

object_ptr<StarGiftAuctionState> starGiftAuctionState::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAuctionState>(p);
}

starGiftAuctionState::starGiftAuctionState(TlBufferParser &p)
  : version_(TlFetchInt::parse(p))
  , start_date_(TlFetchInt::parse(p))
  , end_date_(TlFetchInt::parse(p))
  , min_bid_amount_(TlFetchLong::parse(p))
  , bid_levels_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<auctionBidLevel>, 822231244>>, 481674261>::parse(p))
  , top_bidders_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
  , next_round_at_(TlFetchInt::parse(p))
  , last_gift_num_(TlFetchInt::parse(p))
  , gifts_left_(TlFetchInt::parse(p))
  , current_round_(TlFetchInt::parse(p))
  , total_rounds_(TlFetchInt::parse(p))
  , rounds_(TlFetchBoxed<TlFetchVector<TlFetchObject<StarGiftAuctionRound>>, 481674261>::parse(p))
{}

void starGiftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionState");
    s.store_field("version", version_);
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_field("min_bid_amount", min_bid_amount_);
    { s.store_vector_begin("bid_levels", bid_levels_.size()); for (const auto &_value : bid_levels_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_bidders", top_bidders_.size()); for (const auto &_value : top_bidders_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("next_round_at", next_round_at_);
    s.store_field("last_gift_num", last_gift_num_);
    s.store_field("gifts_left", gifts_left_);
    s.store_field("current_round", current_round_);
    s.store_field("total_rounds", total_rounds_);
    { s.store_vector_begin("rounds", rounds_.size()); for (const auto &_value : rounds_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

starGiftAuctionStateFinished::starGiftAuctionStateFinished()
  : flags_()
  , start_date_()
  , end_date_()
  , average_price_()
  , listed_count_()
  , fragment_listed_count_()
  , fragment_listed_url_()
{}

const std::int32_t starGiftAuctionStateFinished::ID;

object_ptr<StarGiftAuctionState> starGiftAuctionStateFinished::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftAuctionStateFinished> res = make_tl_object<starGiftAuctionStateFinished>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->start_date_ = TlFetchInt::parse(p);
  res->end_date_ = TlFetchInt::parse(p);
  res->average_price_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->listed_count_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->fragment_listed_count_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->fragment_listed_url_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void starGiftAuctionStateFinished::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionStateFinished");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_field("average_price", average_price_);
    if (var0 & 1) { s.store_field("listed_count", listed_count_); }
    if (var0 & 2) { s.store_field("fragment_listed_count", fragment_listed_count_); }
    if (var0 & 2) { s.store_field("fragment_listed_url", fragment_listed_url_); }
    s.store_class_end();
  }
}

object_ptr<StarsAmount> StarsAmount::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starsAmount::ID:
      return starsAmount::fetch(p);
    case starsTonAmount::ID:
      return starsTonAmount::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

starsAmount::starsAmount(int64 amount_, int32 nanos_)
  : amount_(amount_)
  , nanos_(nanos_)
{}

const std::int32_t starsAmount::ID;

object_ptr<StarsAmount> starsAmount::fetch(TlBufferParser &p) {
  return make_tl_object<starsAmount>(p);
}

starsAmount::starsAmount(TlBufferParser &p)
  : amount_(TlFetchLong::parse(p))
  , nanos_(TlFetchInt::parse(p))
{}

void starsAmount::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(amount_, s);
  TlStoreBinary::store(nanos_, s);
}

void starsAmount::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(amount_, s);
  TlStoreBinary::store(nanos_, s);
}

void starsAmount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsAmount");
    s.store_field("amount", amount_);
    s.store_field("nanos", nanos_);
    s.store_class_end();
  }
}

starsTonAmount::starsTonAmount(int64 amount_)
  : amount_(amount_)
{}

const std::int32_t starsTonAmount::ID;

object_ptr<StarsAmount> starsTonAmount::fetch(TlBufferParser &p) {
  return make_tl_object<starsTonAmount>(p);
}

starsTonAmount::starsTonAmount(TlBufferParser &p)
  : amount_(TlFetchLong::parse(p))
{}

void starsTonAmount::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(amount_, s);
}

void starsTonAmount::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(amount_, s);
}

void starsTonAmount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTonAmount");
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

object_ptr<StarsTransactionPeer> StarsTransactionPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starsTransactionPeerUnsupported::ID:
      return starsTransactionPeerUnsupported::fetch(p);
    case starsTransactionPeerAppStore::ID:
      return starsTransactionPeerAppStore::fetch(p);
    case starsTransactionPeerPlayMarket::ID:
      return starsTransactionPeerPlayMarket::fetch(p);
    case starsTransactionPeerPremiumBot::ID:
      return starsTransactionPeerPremiumBot::fetch(p);
    case starsTransactionPeerFragment::ID:
      return starsTransactionPeerFragment::fetch(p);
    case starsTransactionPeer::ID:
      return starsTransactionPeer::fetch(p);
    case starsTransactionPeerAds::ID:
      return starsTransactionPeerAds::fetch(p);
    case starsTransactionPeerAPI::ID:
      return starsTransactionPeerAPI::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t starsTransactionPeerUnsupported::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerUnsupported::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerUnsupported>();
}

void starsTransactionPeerUnsupported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerUnsupported");
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeerAppStore::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerAppStore::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerAppStore>();
}

void starsTransactionPeerAppStore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerAppStore");
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeerPlayMarket::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerPlayMarket::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerPlayMarket>();
}

void starsTransactionPeerPlayMarket::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerPlayMarket");
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeerPremiumBot::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerPremiumBot::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerPremiumBot>();
}

void starsTransactionPeerPremiumBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerPremiumBot");
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeerFragment::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerFragment::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerFragment>();
}

void starsTransactionPeerFragment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerFragment");
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeer::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeer::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeer>(p);
}

starsTransactionPeer::starsTransactionPeer(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
{}

void starsTransactionPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeerAds::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerAds::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerAds>();
}

void starsTransactionPeerAds::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerAds");
    s.store_class_end();
  }
}

const std::int32_t starsTransactionPeerAPI::ID;

object_ptr<StarsTransactionPeer> starsTransactionPeerAPI::fetch(TlBufferParser &p) {
  return make_tl_object<starsTransactionPeerAPI>();
}

void starsTransactionPeerAPI::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTransactionPeerAPI");
    s.store_class_end();
  }
}

const std::int32_t statsPercentValue::ID;

object_ptr<statsPercentValue> statsPercentValue::fetch(TlBufferParser &p) {
  return make_tl_object<statsPercentValue>(p);
}

statsPercentValue::statsPercentValue(TlBufferParser &p)
  : part_(TlFetchDouble::parse(p))
  , total_(TlFetchDouble::parse(p))
{}

void statsPercentValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsPercentValue");
    s.store_field("part", part_);
    s.store_field("total", total_);
    s.store_class_end();
  }
}

webViewResultUrl::webViewResultUrl()
  : flags_()
  , fullsize_()
  , fullscreen_()
  , query_id_()
  , url_()
{}

const std::int32_t webViewResultUrl::ID;

object_ptr<webViewResultUrl> webViewResultUrl::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webViewResultUrl> res = make_tl_object<webViewResultUrl>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->fullsize_ = (var0 & 2) != 0;
  res->fullscreen_ = (var0 & 4) != 0;
  if (var0 & 1) { res->query_id_ = TlFetchLong::parse(p); }
  res->url_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void webViewResultUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webViewResultUrl");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (fullsize_ << 1) | (fullscreen_ << 2)));
    if (var0 & 2) { s.store_field("fullsize", true); }
    if (var0 & 4) { s.store_field("fullscreen", true); }
    if (var0 & 1) { s.store_field("query_id", query_id_); }
    s.store_field("url", url_);
    s.store_class_end();
  }
}

const std::int32_t account_businessChatLinks::ID;

object_ptr<account_businessChatLinks> account_businessChatLinks::fetch(TlBufferParser &p) {
  return make_tl_object<account_businessChatLinks>(p);
}

account_businessChatLinks::account_businessChatLinks(TlBufferParser &p)
  : links_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<businessChatLink>, -1263638929>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void account_businessChatLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.businessChatLinks");
    { s.store_vector_begin("links", links_.size()); for (const auto &_value : links_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t account_passkeyRegistrationOptions::ID;

object_ptr<account_passkeyRegistrationOptions> account_passkeyRegistrationOptions::fetch(TlBufferParser &p) {
  return make_tl_object<account_passkeyRegistrationOptions>(p);
}

account_passkeyRegistrationOptions::account_passkeyRegistrationOptions(TlBufferParser &p)
  : options_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
{}

void account_passkeyRegistrationOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.passkeyRegistrationOptions");
    s.store_object_field("options", static_cast<const BaseObject *>(options_.get()));
    s.store_class_end();
  }
}

const std::int32_t account_passkeys::ID;

object_ptr<account_passkeys> account_passkeys::fetch(TlBufferParser &p) {
  return make_tl_object<account_passkeys>(p);
}

account_passkeys::account_passkeys(TlBufferParser &p)
  : passkeys_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<passkey>, -1738457409>>, 481674261>::parse(p))
{}

void account_passkeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.passkeys");
    { s.store_vector_begin("passkeys", passkeys_.size()); for (const auto &_value : passkeys_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_password::account_password()
  : flags_()
  , has_recovery_()
  , has_secure_values_()
  , has_password_()
  , current_algo_()
  , srp_B_()
  , srp_id_()
  , hint_()
  , email_unconfirmed_pattern_()
  , new_algo_()
  , new_secure_algo_()
  , secure_random_()
  , pending_reset_date_()
  , login_email_pattern_()
{}

const std::int32_t account_password::ID;

object_ptr<account_password> account_password::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_password> res = make_tl_object<account_password>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_recovery_ = (var0 & 1) != 0;
  res->has_secure_values_ = (var0 & 2) != 0;
  res->has_password_ = (var0 & 4) != 0;
  if (var0 & 4) { res->current_algo_ = TlFetchObject<PasswordKdfAlgo>::parse(p); }
  if (var0 & 4) { res->srp_B_ = TlFetchBytes<bytes>::parse(p); }
  if (var0 & 4) { res->srp_id_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->hint_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->email_unconfirmed_pattern_ = TlFetchString<string>::parse(p); }
  res->new_algo_ = TlFetchObject<PasswordKdfAlgo>::parse(p);
  res->new_secure_algo_ = TlFetchObject<SecurePasswordKdfAlgo>::parse(p);
  res->secure_random_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 32) { res->pending_reset_date_ = TlFetchInt::parse(p); }
  if (var0 & 64) { res->login_email_pattern_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void account_password::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.password");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_recovery_ << 0) | (has_secure_values_ << 1) | (has_password_ << 2)));
    if (var0 & 1) { s.store_field("has_recovery", true); }
    if (var0 & 2) { s.store_field("has_secure_values", true); }
    if (var0 & 4) { s.store_field("has_password", true); }
    if (var0 & 4) { s.store_object_field("current_algo", static_cast<const BaseObject *>(current_algo_.get())); }
    if (var0 & 4) { s.store_bytes_field("srp_B", srp_B_); }
    if (var0 & 4) { s.store_field("srp_id", srp_id_); }
    if (var0 & 8) { s.store_field("hint", hint_); }
    if (var0 & 16) { s.store_field("email_unconfirmed_pattern", email_unconfirmed_pattern_); }
    s.store_object_field("new_algo", static_cast<const BaseObject *>(new_algo_.get()));
    s.store_object_field("new_secure_algo", static_cast<const BaseObject *>(new_secure_algo_.get()));
    s.store_bytes_field("secure_random", secure_random_);
    if (var0 & 32) { s.store_field("pending_reset_date", pending_reset_date_); }
    if (var0 & 64) { s.store_field("login_email_pattern", login_email_pattern_); }
    s.store_class_end();
  }
}

account_resolvedBusinessChatLinks::account_resolvedBusinessChatLinks()
  : flags_()
  , peer_()
  , message_()
  , entities_()
  , chats_()
  , users_()
{}

const std::int32_t account_resolvedBusinessChatLinks::ID;

object_ptr<account_resolvedBusinessChatLinks> account_resolvedBusinessChatLinks::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_resolvedBusinessChatLinks> res = make_tl_object<account_resolvedBusinessChatLinks>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void account_resolvedBusinessChatLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resolvedBusinessChatLinks");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("message", message_);
    if (var0 & 1) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<auth_Authorization> auth_Authorization::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case auth_authorization::ID:
      return auth_authorization::fetch(p);
    case auth_authorizationSignUpRequired::ID:
      return auth_authorizationSignUpRequired::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

auth_authorization::auth_authorization()
  : flags_()
  , setup_password_required_()
  , otherwise_relogin_days_()
  , tmp_sessions_()
  , future_auth_token_()
  , user_()
{}

const std::int32_t auth_authorization::ID;

object_ptr<auth_Authorization> auth_authorization::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_authorization> res = make_tl_object<auth_authorization>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->setup_password_required_ = (var0 & 2) != 0;
  if (var0 & 2) { res->otherwise_relogin_days_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->tmp_sessions_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->future_auth_token_ = TlFetchBytes<bytes>::parse(p); }
  res->user_ = TlFetchObject<User>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_authorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.authorization");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (setup_password_required_ << 1)));
    if (var0 & 2) { s.store_field("setup_password_required", true); }
    if (var0 & 2) { s.store_field("otherwise_relogin_days", otherwise_relogin_days_); }
    if (var0 & 1) { s.store_field("tmp_sessions", tmp_sessions_); }
    if (var0 & 4) { s.store_bytes_field("future_auth_token", future_auth_token_); }
    s.store_object_field("user", static_cast<const BaseObject *>(user_.get()));
    s.store_class_end();
  }
}

auth_authorizationSignUpRequired::auth_authorizationSignUpRequired()
  : flags_()
  , terms_of_service_()
{}

const std::int32_t auth_authorizationSignUpRequired::ID;

object_ptr<auth_Authorization> auth_authorizationSignUpRequired::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_authorizationSignUpRequired> res = make_tl_object<auth_authorizationSignUpRequired>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->terms_of_service_ = TlFetchBoxed<TlFetchObject<help_termsOfService>, 2013922064>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_authorizationSignUpRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.authorizationSignUpRequired");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("terms_of_service", static_cast<const BaseObject *>(terms_of_service_.get())); }
    s.store_class_end();
  }
}

object_ptr<auth_SentCode> auth_SentCode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case auth_sentCode::ID:
      return auth_sentCode::fetch(p);
    case auth_sentCodeSuccess::ID:
      return auth_sentCodeSuccess::fetch(p);
    case auth_sentCodePaymentRequired::ID:
      return auth_sentCodePaymentRequired::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

auth_sentCode::auth_sentCode()
  : flags_()
  , type_()
  , phone_code_hash_()
  , next_type_()
  , timeout_()
{}

const std::int32_t auth_sentCode::ID;

object_ptr<auth_SentCode> auth_sentCode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<auth_sentCode> res = make_tl_object<auth_sentCode>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->type_ = TlFetchObject<auth_SentCodeType>::parse(p);
  res->phone_code_hash_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->next_type_ = TlFetchObject<auth_CodeType>::parse(p); }
  if (var0 & 4) { res->timeout_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void auth_sentCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_field("phone_code_hash", phone_code_hash_);
    if (var0 & 2) { s.store_object_field("next_type", static_cast<const BaseObject *>(next_type_.get())); }
    if (var0 & 4) { s.store_field("timeout", timeout_); }
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodeSuccess::ID;

object_ptr<auth_SentCode> auth_sentCodeSuccess::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodeSuccess>(p);
}

auth_sentCodeSuccess::auth_sentCodeSuccess(TlBufferParser &p)
  : authorization_(TlFetchObject<auth_Authorization>::parse(p))
{}

void auth_sentCodeSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodeSuccess");
    s.store_object_field("authorization", static_cast<const BaseObject *>(authorization_.get()));
    s.store_class_end();
  }
}

const std::int32_t auth_sentCodePaymentRequired::ID;

object_ptr<auth_SentCode> auth_sentCodePaymentRequired::fetch(TlBufferParser &p) {
  return make_tl_object<auth_sentCodePaymentRequired>(p);
}

auth_sentCodePaymentRequired::auth_sentCodePaymentRequired(TlBufferParser &p)
  : store_product_(TlFetchString<string>::parse(p))
  , phone_code_hash_(TlFetchString<string>::parse(p))
  , support_email_address_(TlFetchString<string>::parse(p))
  , support_email_subject_(TlFetchString<string>::parse(p))
  , currency_(TlFetchString<string>::parse(p))
  , amount_(TlFetchLong::parse(p))
{}

void auth_sentCodePaymentRequired::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sentCodePaymentRequired");
    s.store_field("store_product", store_product_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("support_email_address", support_email_address_);
    s.store_field("support_email_subject", support_email_subject_);
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

const std::int32_t channels_sendAsPeers::ID;

object_ptr<channels_sendAsPeers> channels_sendAsPeers::fetch(TlBufferParser &p) {
  return make_tl_object<channels_sendAsPeers>(p);
}

channels_sendAsPeers::channels_sendAsPeers(TlBufferParser &p)
  : peers_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<sendAsPeer>, -1206095820>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void channels_sendAsPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.sendAsPeers");
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<help_PassportConfig> help_PassportConfig::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_passportConfigNotModified::ID:
      return help_passportConfigNotModified::fetch(p);
    case help_passportConfig::ID:
      return help_passportConfig::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_passportConfigNotModified::ID;

object_ptr<help_PassportConfig> help_passportConfigNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<help_passportConfigNotModified>();
}

void help_passportConfigNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.passportConfigNotModified");
    s.store_class_end();
  }
}

const std::int32_t help_passportConfig::ID;

object_ptr<help_PassportConfig> help_passportConfig::fetch(TlBufferParser &p) {
  return make_tl_object<help_passportConfig>(p);
}

help_passportConfig::help_passportConfig(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , countries_langs_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
{}

void help_passportConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.passportConfig");
    s.store_field("hash", hash_);
    s.store_object_field("countries_langs", static_cast<const BaseObject *>(countries_langs_.get()));
    s.store_class_end();
  }
}

object_ptr<help_PromoData> help_PromoData::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_promoDataEmpty::ID:
      return help_promoDataEmpty::fetch(p);
    case help_promoData::ID:
      return help_promoData::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_promoDataEmpty::ID;

object_ptr<help_PromoData> help_promoDataEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<help_promoDataEmpty>(p);
}

help_promoDataEmpty::help_promoDataEmpty(TlBufferParser &p)
  : expires_(TlFetchInt::parse(p))
{}

void help_promoDataEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.promoDataEmpty");
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

help_promoData::help_promoData()
  : flags_()
  , proxy_()
  , expires_()
  , peer_()
  , psa_type_()
  , psa_message_()
  , pending_suggestions_()
  , dismissed_suggestions_()
  , custom_pending_suggestion_()
  , chats_()
  , users_()
{}

const std::int32_t help_promoData::ID;

object_ptr<help_PromoData> help_promoData::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_promoData> res = make_tl_object<help_promoData>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->proxy_ = (var0 & 1) != 0;
  res->expires_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 2) { res->psa_type_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->psa_message_ = TlFetchString<string>::parse(p); }
  res->pending_suggestions_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p);
  res->dismissed_suggestions_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p);
  if (var0 & 16) { res->custom_pending_suggestion_ = TlFetchBoxed<TlFetchObject<pendingSuggestion>, -404214254>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void help_promoData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.promoData");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (proxy_ << 0)));
    if (var0 & 1) { s.store_field("proxy", true); }
    s.store_field("expires", expires_);
    if (var0 & 8) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 2) { s.store_field("psa_type", psa_type_); }
    if (var0 & 4) { s.store_field("psa_message", psa_message_); }
    { s.store_vector_begin("pending_suggestions", pending_suggestions_.size()); for (const auto &_value : pending_suggestions_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("dismissed_suggestions", dismissed_suggestions_.size()); for (const auto &_value : dismissed_suggestions_) { s.store_field("", _value); } s.store_class_end(); }
    if (var0 & 16) { s.store_object_field("custom_pending_suggestion", static_cast<const BaseObject *>(custom_pending_suggestion_.get())); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<help_TimezonesList> help_TimezonesList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_timezonesListNotModified::ID:
      return help_timezonesListNotModified::fetch(p);
    case help_timezonesList::ID:
      return help_timezonesList::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_timezonesListNotModified::ID;

object_ptr<help_TimezonesList> help_timezonesListNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<help_timezonesListNotModified>();
}

void help_timezonesListNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.timezonesListNotModified");
    s.store_class_end();
  }
}

const std::int32_t help_timezonesList::ID;

object_ptr<help_TimezonesList> help_timezonesList::fetch(TlBufferParser &p) {
  return make_tl_object<help_timezonesList>(p);
}

help_timezonesList::help_timezonesList(TlBufferParser &p)
  : timezones_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<timezone>, -7173643>>, 481674261>::parse(p))
  , hash_(TlFetchInt::parse(p))
{}

void help_timezonesList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.timezonesList");
    { s.store_vector_begin("timezones", timezones_.size()); for (const auto &_value : timezones_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

const std::int32_t messages_chatFull::ID;

object_ptr<messages_chatFull> messages_chatFull::fetch(TlBufferParser &p) {
  return make_tl_object<messages_chatFull>(p);
}

messages_chatFull::messages_chatFull(TlBufferParser &p)
  : full_chat_(TlFetchObject<ChatFull>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_chatFull::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.chatFull");
    s.store_object_field("full_chat", static_cast<const BaseObject *>(full_chat_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_historyImport::ID;

object_ptr<messages_historyImport> messages_historyImport::fetch(TlBufferParser &p) {
  return make_tl_object<messages_historyImport>(p);
}

messages_historyImport::messages_historyImport(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void messages_historyImport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.historyImport");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

const std::int32_t messages_messageViews::ID;

object_ptr<messages_messageViews> messages_messageViews::fetch(TlBufferParser &p) {
  return make_tl_object<messages_messageViews>(p);
}

messages_messageViews::messages_messageViews(TlBufferParser &p)
  : views_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messageViews>, 1163625789>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_messageViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.messageViews");
    { s.store_vector_begin("views", views_.size()); for (const auto &_value : views_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_peerSettings::ID;

object_ptr<messages_peerSettings> messages_peerSettings::fetch(TlBufferParser &p) {
  return make_tl_object<messages_peerSettings>(p);
}

messages_peerSettings::messages_peerSettings(TlBufferParser &p)
  : settings_(TlFetchBoxed<TlFetchObject<peerSettings>, -193510921>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_peerSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.peerSettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_SavedReactionTags> messages_SavedReactionTags::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_savedReactionTagsNotModified::ID:
      return messages_savedReactionTagsNotModified::fetch(p);
    case messages_savedReactionTags::ID:
      return messages_savedReactionTags::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_savedReactionTagsNotModified::ID;

object_ptr<messages_SavedReactionTags> messages_savedReactionTagsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedReactionTagsNotModified>();
}

void messages_savedReactionTagsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedReactionTagsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_savedReactionTags::ID;

object_ptr<messages_SavedReactionTags> messages_savedReactionTags::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedReactionTags>(p);
}

messages_savedReactionTags::messages_savedReactionTags(TlBufferParser &p)
  : tags_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<savedReactionTag>, -881854424>>, 481674261>::parse(p))
  , hash_(TlFetchLong::parse(p))
{}

void messages_savedReactionTags::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedReactionTags");
    { s.store_vector_begin("tags", tags_.size()); for (const auto &_value : tags_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

object_ptr<messages_StickerSet> messages_StickerSet::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_stickerSet::ID:
      return messages_stickerSet::fetch(p);
    case messages_stickerSetNotModified::ID:
      return messages_stickerSetNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messages_stickerSet::messages_stickerSet(object_ptr<stickerSet> &&set_, array<object_ptr<stickerPack>> &&packs_, array<object_ptr<stickerKeyword>> &&keywords_, array<object_ptr<Document>> &&documents_)
  : set_(std::move(set_))
  , packs_(std::move(packs_))
  , keywords_(std::move(keywords_))
  , documents_(std::move(documents_))
{}

const std::int32_t messages_stickerSet::ID;

object_ptr<messages_StickerSet> messages_stickerSet::fetch(TlBufferParser &p) {
  return make_tl_object<messages_stickerSet>(p);
}

messages_stickerSet::messages_stickerSet(TlBufferParser &p)
  : set_(TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p))
  , packs_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerPack>, 313694676>>, 481674261>::parse(p))
  , keywords_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerKeyword>, -50416996>>, 481674261>::parse(p))
  , documents_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void messages_stickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.stickerSet");
    s.store_object_field("set", static_cast<const BaseObject *>(set_.get()));
    { s.store_vector_begin("packs", packs_.size()); for (const auto &_value : packs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("keywords", keywords_.size()); for (const auto &_value : keywords_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_stickerSetNotModified::ID;

object_ptr<messages_StickerSet> messages_stickerSetNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_stickerSetNotModified>();
}

void messages_stickerSetNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.stickerSetNotModified");
    s.store_class_end();
  }
}

object_ptr<messages_Stickers> messages_Stickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_stickersNotModified::ID:
      return messages_stickersNotModified::fetch(p);
    case messages_stickers::ID:
      return messages_stickers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_stickersNotModified::ID;

object_ptr<messages_Stickers> messages_stickersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_stickersNotModified>();
}

void messages_stickersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.stickersNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_stickers::ID;

object_ptr<messages_Stickers> messages_stickers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_stickers>(p);
}

messages_stickers::messages_stickers(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , stickers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void messages_stickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.stickers");
    s.store_field("hash", hash_);
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_bankCardData::ID;

object_ptr<payments_bankCardData> payments_bankCardData::fetch(TlBufferParser &p) {
  return make_tl_object<payments_bankCardData>(p);
}

payments_bankCardData::payments_bankCardData(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , open_urls_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<bankCardOpenUrl>, -177732982>>, 481674261>::parse(p))
{}

void payments_bankCardData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.bankCardData");
    s.store_field("title", title_);
    { s.store_vector_begin("open_urls", open_urls_.size()); for (const auto &_value : open_urls_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<payments_PaymentReceipt> payments_PaymentReceipt::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_paymentReceipt::ID:
      return payments_paymentReceipt::fetch(p);
    case payments_paymentReceiptStars::ID:
      return payments_paymentReceiptStars::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

payments_paymentReceipt::payments_paymentReceipt()
  : flags_()
  , date_()
  , bot_id_()
  , provider_id_()
  , title_()
  , description_()
  , photo_()
  , invoice_()
  , info_()
  , shipping_()
  , tip_amount_()
  , currency_()
  , total_amount_()
  , credentials_title_()
  , users_()
{}

const std::int32_t payments_paymentReceipt::ID;

object_ptr<payments_PaymentReceipt> payments_paymentReceipt::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_paymentReceipt> res = make_tl_object<payments_paymentReceipt>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->date_ = TlFetchInt::parse(p);
  res->bot_id_ = TlFetchLong::parse(p);
  res->provider_id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  res->invoice_ = TlFetchBoxed<TlFetchObject<invoice>, 77522308>::parse(p);
  if (var0 & 1) { res->info_ = TlFetchBoxed<TlFetchObject<paymentRequestedInfo>, -1868808300>::parse(p); }
  if (var0 & 2) { res->shipping_ = TlFetchBoxed<TlFetchObject<shippingOption>, -1239335713>::parse(p); }
  if (var0 & 8) { res->tip_amount_ = TlFetchLong::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  res->credentials_title_ = TlFetchString<string>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_paymentReceipt::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentReceipt");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("date", date_);
    s.store_field("bot_id", bot_id_);
    s.store_field("provider_id", provider_id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 4) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    if (var0 & 1) { s.store_object_field("info", static_cast<const BaseObject *>(info_.get())); }
    if (var0 & 2) { s.store_object_field("shipping", static_cast<const BaseObject *>(shipping_.get())); }
    if (var0 & 8) { s.store_field("tip_amount", tip_amount_); }
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("credentials_title", credentials_title_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_paymentReceiptStars::payments_paymentReceiptStars()
  : flags_()
  , date_()
  , bot_id_()
  , title_()
  , description_()
  , photo_()
  , invoice_()
  , currency_()
  , total_amount_()
  , transaction_id_()
  , users_()
{}

const std::int32_t payments_paymentReceiptStars::ID;

object_ptr<payments_PaymentReceipt> payments_paymentReceiptStars::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_paymentReceiptStars> res = make_tl_object<payments_paymentReceiptStars>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->date_ = TlFetchInt::parse(p);
  res->bot_id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  res->invoice_ = TlFetchBoxed<TlFetchObject<invoice>, 77522308>::parse(p);
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  res->transaction_id_ = TlFetchString<string>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_paymentReceiptStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentReceiptStars");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("date", date_);
    s.store_field("bot_id", bot_id_);
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 4) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    s.store_field("transaction_id", transaction_id_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_starsRevenueAdsAccountUrl::ID;

object_ptr<payments_starsRevenueAdsAccountUrl> payments_starsRevenueAdsAccountUrl::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starsRevenueAdsAccountUrl>(p);
}

payments_starsRevenueAdsAccountUrl::payments_starsRevenueAdsAccountUrl(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void payments_starsRevenueAdsAccountUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starsRevenueAdsAccountUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

payments_starsRevenueStats::payments_starsRevenueStats()
  : flags_()
  , top_hours_graph_()
  , revenue_graph_()
  , status_()
  , usd_rate_()
{}

const std::int32_t payments_starsRevenueStats::ID;

object_ptr<payments_starsRevenueStats> payments_starsRevenueStats::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_starsRevenueStats> res = make_tl_object<payments_starsRevenueStats>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->top_hours_graph_ = TlFetchObject<StatsGraph>::parse(p); }
  res->revenue_graph_ = TlFetchObject<StatsGraph>::parse(p);
  res->status_ = TlFetchBoxed<TlFetchObject<starsRevenueStatus>, -21080943>::parse(p);
  res->usd_rate_ = TlFetchDouble::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_starsRevenueStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starsRevenueStats");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("top_hours_graph", static_cast<const BaseObject *>(top_hours_graph_.get())); }
    s.store_object_field("revenue_graph", static_cast<const BaseObject *>(revenue_graph_.get()));
    s.store_object_field("status", static_cast<const BaseObject *>(status_.get()));
    s.store_field("usd_rate", usd_rate_);
    s.store_class_end();
  }
}

payments_starsStatus::payments_starsStatus()
  : flags_()
  , balance_()
  , subscriptions_()
  , subscriptions_next_offset_()
  , subscriptions_missing_balance_()
  , history_()
  , next_offset_()
  , chats_()
  , users_()
{}

const std::int32_t payments_starsStatus::ID;

object_ptr<payments_starsStatus> payments_starsStatus::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_starsStatus> res = make_tl_object<payments_starsStatus>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->balance_ = TlFetchObject<StarsAmount>::parse(p);
  if (var0 & 2) { res->subscriptions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starsSubscription>, 779004698>>, 481674261>::parse(p); }
  if (var0 & 4) { res->subscriptions_next_offset_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->subscriptions_missing_balance_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->history_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starsTransaction>, 325426864>>, 481674261>::parse(p); }
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_starsStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starsStatus");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("balance", static_cast<const BaseObject *>(balance_.get()));
    if (var0 & 2) { { s.store_vector_begin("subscriptions", subscriptions_.size()); for (const auto &_value : subscriptions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_field("subscriptions_next_offset", subscriptions_next_offset_); }
    if (var0 & 16) { s.store_field("subscriptions_missing_balance", subscriptions_missing_balance_); }
    if (var0 & 8) { { s.store_vector_begin("history", history_.size()); for (const auto &_value : history_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

premium_boostsStatus::premium_boostsStatus()
  : flags_()
  , my_boost_()
  , level_()
  , current_level_boosts_()
  , boosts_()
  , gift_boosts_()
  , next_level_boosts_()
  , premium_audience_()
  , boost_url_()
  , prepaid_giveaways_()
  , my_boost_slots_()
{}

const std::int32_t premium_boostsStatus::ID;

object_ptr<premium_boostsStatus> premium_boostsStatus::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<premium_boostsStatus> res = make_tl_object<premium_boostsStatus>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->my_boost_ = (var0 & 4) != 0;
  res->level_ = TlFetchInt::parse(p);
  res->current_level_boosts_ = TlFetchInt::parse(p);
  res->boosts_ = TlFetchInt::parse(p);
  if (var0 & 16) { res->gift_boosts_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->next_level_boosts_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->premium_audience_ = TlFetchBoxed<TlFetchObject<statsPercentValue>, -875679776>::parse(p); }
  res->boost_url_ = TlFetchString<string>::parse(p);
  if (var0 & 8) { res->prepaid_giveaways_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PrepaidGiveaway>>, 481674261>::parse(p); }
  if (var0 & 4) { res->my_boost_slots_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void premium_boostsStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.boostsStatus");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (my_boost_ << 2)));
    if (var0 & 4) { s.store_field("my_boost", true); }
    s.store_field("level", level_);
    s.store_field("current_level_boosts", current_level_boosts_);
    s.store_field("boosts", boosts_);
    if (var0 & 16) { s.store_field("gift_boosts", gift_boosts_); }
    if (var0 & 1) { s.store_field("next_level_boosts", next_level_boosts_); }
    if (var0 & 2) { s.store_object_field("premium_audience", static_cast<const BaseObject *>(premium_audience_.get())); }
    s.store_field("boost_url", boost_url_);
    if (var0 & 8) { { s.store_vector_begin("prepaid_giveaways", prepaid_giveaways_.size()); for (const auto &_value : prepaid_giveaways_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("my_boost_slots", my_boost_slots_.size()); for (const auto &_value : my_boost_slots_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t stories_canSendStoryCount::ID;

object_ptr<stories_canSendStoryCount> stories_canSendStoryCount::fetch(TlBufferParser &p) {
  return make_tl_object<stories_canSendStoryCount>(p);
}

stories_canSendStoryCount::stories_canSendStoryCount(TlBufferParser &p)
  : count_remains_(TlFetchInt::parse(p))
{}

void stories_canSendStoryCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.canSendStoryCount");
    s.store_field("count_remains", count_remains_);
    s.store_class_end();
  }
}

const std::int32_t stories_storyViews::ID;

object_ptr<stories_storyViews> stories_storyViews::fetch(TlBufferParser &p) {
  return make_tl_object<stories_storyViews>(p);
}

stories_storyViews::stories_storyViews(TlBufferParser &p)
  : views_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<storyViews>, -1923523370>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void stories_storyViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.storyViews");
    { s.store_vector_begin("views", views_.size()); for (const auto &_value : views_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<updates_Difference> updates_Difference::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case updates_differenceEmpty::ID:
      return updates_differenceEmpty::fetch(p);
    case updates_difference::ID:
      return updates_difference::fetch(p);
    case updates_differenceSlice::ID:
      return updates_differenceSlice::fetch(p);
    case updates_differenceTooLong::ID:
      return updates_differenceTooLong::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t updates_differenceEmpty::ID;

object_ptr<updates_Difference> updates_differenceEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<updates_differenceEmpty>(p);
}

updates_differenceEmpty::updates_differenceEmpty(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
  , seq_(TlFetchInt::parse(p))
{}

void updates_differenceEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.differenceEmpty");
    s.store_field("date", date_);
    s.store_field("seq", seq_);
    s.store_class_end();
  }
}

const std::int32_t updates_difference::ID;

object_ptr<updates_Difference> updates_difference::fetch(TlBufferParser &p) {
  return make_tl_object<updates_difference>(p);
}

updates_difference::updates_difference(TlBufferParser &p)
  : new_messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , new_encrypted_messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<EncryptedMessage>>, 481674261>::parse(p))
  , other_updates_(TlFetchBoxed<TlFetchVector<TlFetchObject<Update>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , state_(TlFetchBoxed<TlFetchObject<updates_state>, -1519637954>::parse(p))
{}

void updates_difference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.difference");
    { s.store_vector_begin("new_messages", new_messages_.size()); for (const auto &_value : new_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("new_encrypted_messages", new_encrypted_messages_.size()); for (const auto &_value : new_encrypted_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("other_updates", other_updates_.size()); for (const auto &_value : other_updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

updates_differenceSlice::updates_differenceSlice(array<object_ptr<Message>> &&new_messages_, array<object_ptr<EncryptedMessage>> &&new_encrypted_messages_, array<object_ptr<Update>> &&other_updates_, array<object_ptr<Chat>> &&chats_, array<object_ptr<User>> &&users_, object_ptr<updates_state> &&intermediate_state_)
  : new_messages_(std::move(new_messages_))
  , new_encrypted_messages_(std::move(new_encrypted_messages_))
  , other_updates_(std::move(other_updates_))
  , chats_(std::move(chats_))
  , users_(std::move(users_))
  , intermediate_state_(std::move(intermediate_state_))
{}

const std::int32_t updates_differenceSlice::ID;

object_ptr<updates_Difference> updates_differenceSlice::fetch(TlBufferParser &p) {
  return make_tl_object<updates_differenceSlice>(p);
}

updates_differenceSlice::updates_differenceSlice(TlBufferParser &p)
  : new_messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , new_encrypted_messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<EncryptedMessage>>, 481674261>::parse(p))
  , other_updates_(TlFetchBoxed<TlFetchVector<TlFetchObject<Update>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , intermediate_state_(TlFetchBoxed<TlFetchObject<updates_state>, -1519637954>::parse(p))
{}

void updates_differenceSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.differenceSlice");
    { s.store_vector_begin("new_messages", new_messages_.size()); for (const auto &_value : new_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("new_encrypted_messages", new_encrypted_messages_.size()); for (const auto &_value : new_encrypted_messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("other_updates", other_updates_.size()); for (const auto &_value : other_updates_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("intermediate_state", static_cast<const BaseObject *>(intermediate_state_.get()));
    s.store_class_end();
  }
}

const std::int32_t updates_differenceTooLong::ID;

object_ptr<updates_Difference> updates_differenceTooLong::fetch(TlBufferParser &p) {
  return make_tl_object<updates_differenceTooLong>(p);
}

updates_differenceTooLong::updates_differenceTooLong(TlBufferParser &p)
  : pts_(TlFetchInt::parse(p))
{}

void updates_differenceTooLong::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.differenceTooLong");
    s.store_field("pts", pts_);
    s.store_class_end();
  }
}

const std::int32_t account_deleteAutoSaveExceptions::ID;

void account_deleteAutoSaveExceptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1404829728);
}

void account_deleteAutoSaveExceptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1404829728);
}

void account_deleteAutoSaveExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.deleteAutoSaveExceptions");
    s.store_class_end();
  }
}

account_deleteAutoSaveExceptions::ReturnType account_deleteAutoSaveExceptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_getAutoDownloadSettings::ID;

void account_getAutoDownloadSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1457130303);
}

void account_getAutoDownloadSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1457130303);
}

void account_getAutoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getAutoDownloadSettings");
    s.store_class_end();
  }
}

account_getAutoDownloadSettings::ReturnType account_getAutoDownloadSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_autoDownloadSettings>, 1674235686>::parse(p);
#undef FAIL
}

const std::int32_t account_getContentSettings::ID;

void account_getContentSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1952756306);
}

void account_getContentSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1952756306);
}

void account_getContentSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getContentSettings");
    s.store_class_end();
  }
}

account_getContentSettings::ReturnType account_getContentSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_contentSettings>, 1474462241>::parse(p);
#undef FAIL
}

account_getNotifyExceptions::account_getNotifyExceptions(int32 flags_, bool compare_sound_, bool compare_stories_, object_ptr<InputNotifyPeer> &&peer_)
  : flags_(flags_)
  , compare_sound_(compare_sound_)
  , compare_stories_(compare_stories_)
  , peer_(std::move(peer_))
{}

const std::int32_t account_getNotifyExceptions::ID;

void account_getNotifyExceptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1398240377);
  TlStoreBinary::store((var0 = flags_ | (compare_sound_ << 1) | (compare_stories_ << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
}

void account_getNotifyExceptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1398240377);
  TlStoreBinary::store((var0 = flags_ | (compare_sound_ << 1) | (compare_stories_ << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
}

void account_getNotifyExceptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getNotifyExceptions");
    s.store_field("flags", (var0 = flags_ | (compare_sound_ << 1) | (compare_stories_ << 2)));
    if (var0 & 2) { s.store_field("compare_sound", true); }
    if (var0 & 4) { s.store_field("compare_stories", true); }
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_class_end();
  }
}

account_getNotifyExceptions::ReturnType account_getNotifyExceptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t account_getPasskeys::ID;

void account_getPasskeys::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-367063982);
}

void account_getPasskeys::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-367063982);
}

void account_getPasskeys::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getPasskeys");
    s.store_class_end();
  }
}

account_getPasskeys::ReturnType account_getPasskeys::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_passkeys>, -119494116>::parse(p);
#undef FAIL
}

account_getPasswordSettings::account_getPasswordSettings(object_ptr<InputCheckPasswordSRP> &&password_)
  : password_(std::move(password_))
{}

const std::int32_t account_getPasswordSettings::ID;

void account_getPasswordSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1663767815);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void account_getPasswordSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1663767815);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void account_getPasswordSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getPasswordSettings");
    s.store_object_field("password", static_cast<const BaseObject *>(password_.get()));
    s.store_class_end();
  }
}

account_getPasswordSettings::ReturnType account_getPasswordSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_passwordSettings>, -1705233435>::parse(p);
#undef FAIL
}

account_getWallPapers::account_getWallPapers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getWallPapers::ID;

void account_getWallPapers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(127302966);
  TlStoreBinary::store(hash_, s);
}

void account_getWallPapers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(127302966);
  TlStoreBinary::store(hash_, s);
}

void account_getWallPapers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getWallPapers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getWallPapers::ReturnType account_getWallPapers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_WallPapers>::parse(p);
#undef FAIL
}

const std::int32_t account_getWebAuthorizations::ID;

void account_getWebAuthorizations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(405695855);
}

void account_getWebAuthorizations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(405695855);
}

void account_getWebAuthorizations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getWebAuthorizations");
    s.store_class_end();
  }
}

account_getWebAuthorizations::ReturnType account_getWebAuthorizations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_webAuthorizations>, -313079300>::parse(p);
#undef FAIL
}

account_resetAuthorization::account_resetAuthorization(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_resetAuthorization::ID;

void account_resetAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-545786948);
  TlStoreBinary::store(hash_, s);
}

void account_resetAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-545786948);
  TlStoreBinary::store(hash_, s);
}

void account_resetAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetAuthorization");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_resetAuthorization::ReturnType account_resetAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_setMainProfileTab::account_setMainProfileTab(object_ptr<ProfileTab> &&tab_)
  : tab_(std::move(tab_))
{}

const std::int32_t account_setMainProfileTab::ID;

void account_setMainProfileTab::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1575909552);
  TlStoreBoxedUnknown<TlStoreObject>::store(tab_, s);
}

void account_setMainProfileTab::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1575909552);
  TlStoreBoxedUnknown<TlStoreObject>::store(tab_, s);
}

void account_setMainProfileTab::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setMainProfileTab");
    s.store_object_field("tab", static_cast<const BaseObject *>(tab_.get()));
    s.store_class_end();
  }
}

account_setMainProfileTab::ReturnType account_setMainProfileTab::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_setPrivacy::account_setPrivacy(object_ptr<InputPrivacyKey> &&key_, array<object_ptr<InputPrivacyRule>> &&rules_)
  : key_(std::move(key_))
  , rules_(std::move(rules_))
{}

const std::int32_t account_setPrivacy::ID;

void account_setPrivacy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-906486552);
  TlStoreBoxedUnknown<TlStoreObject>::store(key_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(rules_, s);
}

void account_setPrivacy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-906486552);
  TlStoreBoxedUnknown<TlStoreObject>::store(key_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(rules_, s);
}

void account_setPrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setPrivacy");
    s.store_object_field("key", static_cast<const BaseObject *>(key_.get()));
    { s.store_vector_begin("rules", rules_.size()); for (const auto &_value : rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_setPrivacy::ReturnType account_setPrivacy::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_privacyRules>, 1352683077>::parse(p);
#undef FAIL
}

account_toggleNoPaidMessagesException::account_toggleNoPaidMessagesException(int32 flags_, bool refund_charged_, bool require_payment_, object_ptr<InputPeer> &&parent_peer_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , refund_charged_(refund_charged_)
  , require_payment_(require_payment_)
  , parent_peer_(std::move(parent_peer_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t account_toggleNoPaidMessagesException::ID;

void account_toggleNoPaidMessagesException::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-30483850);
  TlStoreBinary::store((var0 = flags_ | (refund_charged_ << 0) | (require_payment_ << 2)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void account_toggleNoPaidMessagesException::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-30483850);
  TlStoreBinary::store((var0 = flags_ | (refund_charged_ << 0) | (require_payment_ << 2)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void account_toggleNoPaidMessagesException::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.toggleNoPaidMessagesException");
    s.store_field("flags", (var0 = flags_ | (refund_charged_ << 0) | (require_payment_ << 2)));
    if (var0 & 1) { s.store_field("refund_charged", true); }
    if (var0 & 4) { s.store_field("require_payment", true); }
    if (var0 & 2) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

account_toggleNoPaidMessagesException::ReturnType account_toggleNoPaidMessagesException::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_unregisterDevice::account_unregisterDevice(int32 token_type_, string const &token_, array<int64> &&other_uids_)
  : token_type_(token_type_)
  , token_(token_)
  , other_uids_(std::move(other_uids_))
{}

const std::int32_t account_unregisterDevice::ID;

void account_unregisterDevice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1779249670);
  TlStoreBinary::store(token_type_, s);
  TlStoreString::store(token_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(other_uids_, s);
}

void account_unregisterDevice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1779249670);
  TlStoreBinary::store(token_type_, s);
  TlStoreString::store(token_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(other_uids_, s);
}

void account_unregisterDevice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.unregisterDevice");
    s.store_field("token_type", token_type_);
    s.store_field("token", token_);
    { s.store_vector_begin("other_uids", other_uids_.size()); for (const auto &_value : other_uids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_unregisterDevice::ReturnType account_unregisterDevice::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateBusinessWorkHours::account_updateBusinessWorkHours(int32 flags_, object_ptr<businessWorkHours> &&business_work_hours_)
  : flags_(flags_)
  , business_work_hours_(std::move(business_work_hours_))
{}

const std::int32_t account_updateBusinessWorkHours::ID;

void account_updateBusinessWorkHours::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1258348646);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1936543592>::store(business_work_hours_, s); }
}

void account_updateBusinessWorkHours::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1258348646);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1936543592>::store(business_work_hours_, s); }
}

void account_updateBusinessWorkHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateBusinessWorkHours");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("business_work_hours", static_cast<const BaseObject *>(business_work_hours_.get())); }
    s.store_class_end();
  }
}

account_updateBusinessWorkHours::ReturnType account_updateBusinessWorkHours::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateUsername::account_updateUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t account_updateUsername::ID;

void account_updateUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1040964988);
  TlStoreString::store(username_, s);
}

void account_updateUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1040964988);
  TlStoreString::store(username_, s);
}

void account_updateUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

account_updateUsername::ReturnType account_updateUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

bots_getBotRecommendations::bots_getBotRecommendations(object_ptr<InputUser> &&bot_)
  : bot_(std::move(bot_))
{}

const std::int32_t bots_getBotRecommendations::ID;

void bots_getBotRecommendations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1581840363);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_getBotRecommendations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1581840363);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void bots_getBotRecommendations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getBotRecommendations");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

bots_getBotRecommendations::ReturnType bots_getBotRecommendations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<users_Users>::parse(p);
#undef FAIL
}

channels_deleteParticipantHistory::channels_deleteParticipantHistory(object_ptr<InputChannel> &&channel_, object_ptr<InputPeer> &&participant_)
  : channel_(std::move(channel_))
  , participant_(std::move(participant_))
{}

const std::int32_t channels_deleteParticipantHistory::ID;

void channels_deleteParticipantHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(913655003);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void channels_deleteParticipantHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(913655003);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void channels_deleteParticipantHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.deleteParticipantHistory");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

channels_deleteParticipantHistory::ReturnType channels_deleteParticipantHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

channels_toggleForum::channels_toggleForum(object_ptr<InputChannel> &&channel_, bool enabled_, bool tabs_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
  , tabs_(tabs_)
{}

const std::int32_t channels_toggleForum::ID;

void channels_toggleForum::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1073174324);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
  TlStoreBool::store(tabs_, s);
}

void channels_toggleForum::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1073174324);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
  TlStoreBool::store(tabs_, s);
}

void channels_toggleForum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleForum");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_field("tabs", tabs_);
    s.store_class_end();
  }
}

channels_toggleForum::ReturnType channels_toggleForum::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_updateEmojiStatus::channels_updateEmojiStatus(object_ptr<InputChannel> &&channel_, object_ptr<EmojiStatus> &&emoji_status_)
  : channel_(std::move(channel_))
  , emoji_status_(std::move(emoji_status_))
{}

const std::int32_t channels_updateEmojiStatus::ID;

void channels_updateEmojiStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-254548312);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s);
}

void channels_updateEmojiStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-254548312);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s);
}

void channels_updateEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.updateEmojiStatus");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

channels_updateEmojiStatus::ReturnType channels_updateEmojiStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

chatlists_getExportedInvites::chatlists_getExportedInvites(object_ptr<inputChatlistDialogFilter> &&chatlist_)
  : chatlist_(std::move(chatlist_))
{}

const std::int32_t chatlists_getExportedInvites::ID;

void chatlists_getExportedInvites::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-838608253);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_getExportedInvites::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-838608253);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_getExportedInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.getExportedInvites");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_class_end();
  }
}

chatlists_getExportedInvites::ReturnType chatlists_getExportedInvites::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<chatlists_exportedInvites>, 279670215>::parse(p);
#undef FAIL
}

contacts_setBlocked::contacts_setBlocked(int32 flags_, bool my_stories_from_, array<object_ptr<InputPeer>> &&id_, int32 limit_)
  : flags_(flags_)
  , my_stories_from_(my_stories_from_)
  , id_(std::move(id_))
  , limit_(limit_)
{}

const std::int32_t contacts_setBlocked::ID;

void contacts_setBlocked::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1798939530);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
  TlStoreBinary::store(limit_, s);
}

void contacts_setBlocked::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1798939530);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
  TlStoreBinary::store(limit_, s);
}

void contacts_setBlocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.setBlocked");
    s.store_field("flags", (var0 = flags_ | (my_stories_from_ << 0)));
    if (var0 & 1) { s.store_field("my_stories_from", true); }
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

contacts_setBlocked::ReturnType contacts_setBlocked::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

fragment_getCollectibleInfo::fragment_getCollectibleInfo(object_ptr<InputCollectible> &&collectible_)
  : collectible_(std::move(collectible_))
{}

const std::int32_t fragment_getCollectibleInfo::ID;

void fragment_getCollectibleInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1105295942);
  TlStoreBoxedUnknown<TlStoreObject>::store(collectible_, s);
}

void fragment_getCollectibleInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1105295942);
  TlStoreBoxedUnknown<TlStoreObject>::store(collectible_, s);
}

void fragment_getCollectibleInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fragment.getCollectibleInfo");
    s.store_object_field("collectible", static_cast<const BaseObject *>(collectible_.get()));
    s.store_class_end();
  }
}

fragment_getCollectibleInfo::ReturnType fragment_getCollectibleInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<fragment_collectibleInfo>, 1857945489>::parse(p);
#undef FAIL
}

help_getAppConfig::help_getAppConfig(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t help_getAppConfig::ID;

void help_getAppConfig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1642330196);
  TlStoreBinary::store(hash_, s);
}

void help_getAppConfig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1642330196);
  TlStoreBinary::store(hash_, s);
}

void help_getAppConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getAppConfig");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_getAppConfig::ReturnType help_getAppConfig::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_AppConfig>::parse(p);
#undef FAIL
}

help_getCountriesList::help_getCountriesList(string const &lang_code_, int32 hash_)
  : lang_code_(lang_code_)
  , hash_(hash_)
{}

const std::int32_t help_getCountriesList::ID;

void help_getCountriesList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1935116200);
  TlStoreString::store(lang_code_, s);
  TlStoreBinary::store(hash_, s);
}

void help_getCountriesList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1935116200);
  TlStoreString::store(lang_code_, s);
  TlStoreBinary::store(hash_, s);
}

void help_getCountriesList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getCountriesList");
    s.store_field("lang_code", lang_code_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_getCountriesList::ReturnType help_getCountriesList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_CountriesList>::parse(p);
#undef FAIL
}

messages_deleteChat::messages_deleteChat(int64 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t messages_deleteChat::ID;

void messages_deleteChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1540419152);
  TlStoreBinary::store(chat_id_, s);
}

void messages_deleteChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1540419152);
  TlStoreBinary::store(chat_id_, s);
}

void messages_deleteChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

messages_deleteChat::ReturnType messages_deleteChat::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_deleteQuickReplyMessages::messages_deleteQuickReplyMessages(int32 shortcut_id_, array<int32> &&id_)
  : shortcut_id_(shortcut_id_)
  , id_(std::move(id_))
{}

const std::int32_t messages_deleteQuickReplyMessages::ID;

void messages_deleteQuickReplyMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-519706352);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_deleteQuickReplyMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-519706352);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_deleteQuickReplyMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteQuickReplyMessages");
    s.store_field("shortcut_id", shortcut_id_);
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_deleteQuickReplyMessages::ReturnType messages_deleteQuickReplyMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editForumTopic::messages_editForumTopic(int32 flags_, object_ptr<InputPeer> &&peer_, int32 topic_id_, string const &title_, int64 icon_emoji_id_, bool closed_, bool hidden_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , topic_id_(topic_id_)
  , title_(title_)
  , icon_emoji_id_(icon_emoji_id_)
  , closed_(closed_)
  , hidden_(hidden_)
{}

const std::int32_t messages_editForumTopic::ID;

void messages_editForumTopic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-825487052);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(topic_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBinary::store(icon_emoji_id_, s); }
  if (var0 & 4) { TlStoreBool::store(closed_, s); }
  if (var0 & 8) { TlStoreBool::store(hidden_, s); }
}

void messages_editForumTopic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-825487052);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(topic_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBinary::store(icon_emoji_id_, s); }
  if (var0 & 4) { TlStoreBool::store(closed_, s); }
  if (var0 & 8) { TlStoreBool::store(hidden_, s); }
}

void messages_editForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editForumTopic");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("topic_id", topic_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("icon_emoji_id", icon_emoji_id_); }
    if (var0 & 4) { s.store_field("closed", closed_); }
    if (var0 & 8) { s.store_field("hidden", hidden_); }
    s.store_class_end();
  }
}

messages_editForumTopic::ReturnType messages_editForumTopic::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getEmojiKeywordsLanguages::messages_getEmojiKeywordsLanguages(array<string> &&lang_codes_)
  : lang_codes_(std::move(lang_codes_))
{}

const std::int32_t messages_getEmojiKeywordsLanguages::ID;

void messages_getEmojiKeywordsLanguages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1318675378);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(lang_codes_, s);
}

void messages_getEmojiKeywordsLanguages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1318675378);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(lang_codes_, s);
}

void messages_getEmojiKeywordsLanguages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiKeywordsLanguages");
    { s.store_vector_begin("lang_codes", lang_codes_.size()); for (const auto &_value : lang_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getEmojiKeywordsLanguages::ReturnType messages_getEmojiKeywordsLanguages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<emojiLanguage>, -1275374751>>, 481674261>::parse(p);
#undef FAIL
}

messages_getFavedStickers::messages_getFavedStickers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getFavedStickers::ID;

void messages_getFavedStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(82946729);
  TlStoreBinary::store(hash_, s);
}

void messages_getFavedStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(82946729);
  TlStoreBinary::store(hash_, s);
}

void messages_getFavedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getFavedStickers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getFavedStickers::ReturnType messages_getFavedStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FavedStickers>::parse(p);
#undef FAIL
}

messages_getInlineGameHighScores::messages_getInlineGameHighScores(object_ptr<InputBotInlineMessageID> &&id_, object_ptr<InputUser> &&user_id_)
  : id_(std::move(id_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t messages_getInlineGameHighScores::ID;

void messages_getInlineGameHighScores::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(258170395);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_getInlineGameHighScores::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(258170395);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_getInlineGameHighScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getInlineGameHighScores");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

messages_getInlineGameHighScores::ReturnType messages_getInlineGameHighScores::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_highScores>, -1707344487>::parse(p);
#undef FAIL
}

messages_getMaskStickers::messages_getMaskStickers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getMaskStickers::ID;

void messages_getMaskStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1678738104);
  TlStoreBinary::store(hash_, s);
}

void messages_getMaskStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1678738104);
  TlStoreBinary::store(hash_, s);
}

void messages_getMaskStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMaskStickers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getMaskStickers::ReturnType messages_getMaskStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_AllStickers>::parse(p);
#undef FAIL
}

messages_getPollResults::messages_getPollResults(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 poll_hash_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , poll_hash_(poll_hash_)
{}

const std::int32_t messages_getPollResults::ID;

void messages_getPollResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-308026565);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(poll_hash_, s);
}

void messages_getPollResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-308026565);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(poll_hash_, s);
}

void messages_getPollResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPollResults");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("poll_hash", poll_hash_);
    s.store_class_end();
  }
}

messages_getPollResults::ReturnType messages_getPollResults::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getQuickReplyMessages::messages_getQuickReplyMessages(int32 flags_, int32 shortcut_id_, array<int32> &&id_, int64 hash_)
  : flags_(flags_)
  , shortcut_id_(shortcut_id_)
  , id_(std::move(id_))
  , hash_(hash_)
{}

const std::int32_t messages_getQuickReplyMessages::ID;

void messages_getQuickReplyMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1801153085);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(shortcut_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s); }
  TlStoreBinary::store(hash_, s);
}

void messages_getQuickReplyMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1801153085);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(shortcut_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s); }
  TlStoreBinary::store(hash_, s);
}

void messages_getQuickReplyMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getQuickReplyMessages");
    s.store_field("flags", (var0 = flags_));
    s.store_field("shortcut_id", shortcut_id_);
    if (var0 & 1) { { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getQuickReplyMessages::ReturnType messages_getQuickReplyMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getScheduledMessages::messages_getScheduledMessages(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t messages_getScheduledMessages::ID;

void messages_getScheduledMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1111817116);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getScheduledMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1111817116);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_getScheduledMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getScheduledMessages");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getScheduledMessages::ReturnType messages_getScheduledMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getStickers::messages_getStickers(string const &emoticon_, int64 hash_)
  : emoticon_(emoticon_)
  , hash_(hash_)
{}

const std::int32_t messages_getStickers::ID;

void messages_getStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-710552671);
  TlStoreString::store(emoticon_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-710552671);
  TlStoreString::store(emoticon_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getStickers");
    s.store_field("emoticon", emoticon_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getStickers::ReturnType messages_getStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Stickers>::parse(p);
#undef FAIL
}

const std::int32_t messages_getSuggestedDialogFilters::ID;

void messages_getSuggestedDialogFilters::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1566780372);
}

void messages_getSuggestedDialogFilters::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1566780372);
}

void messages_getSuggestedDialogFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSuggestedDialogFilters");
    s.store_class_end();
  }
}

messages_getSuggestedDialogFilters::ReturnType messages_getSuggestedDialogFilters::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<dialogFilterSuggested>, 2004110666>>, 481674261>::parse(p);
#undef FAIL
}

messages_getUnreadPollVotes::messages_getUnreadPollVotes(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_, int32 offset_id_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
  , offset_id_(offset_id_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
{}

const std::int32_t messages_getUnreadPollVotes::ID;

void messages_getUnreadPollVotes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1126722802);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
}

void messages_getUnreadPollVotes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1126722802);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
}

void messages_getUnreadPollVotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getUnreadPollVotes");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_field("offset_id", offset_id_);
    s.store_field("add_offset", add_offset_);
    s.store_field("limit", limit_);
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_class_end();
  }
}

messages_getUnreadPollVotes::ReturnType messages_getUnreadPollVotes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_markDialogUnread::messages_markDialogUnread(int32 flags_, bool unread_, object_ptr<InputPeer> &&parent_peer_, object_ptr<InputDialogPeer> &&peer_)
  : flags_(flags_)
  , unread_(unread_)
  , parent_peer_(std::move(parent_peer_))
  , peer_(std::move(peer_))
{}

const std::int32_t messages_markDialogUnread::ID;

void messages_markDialogUnread::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1940912392);
  TlStoreBinary::store((var0 = flags_ | (unread_ << 0)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_markDialogUnread::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1940912392);
  TlStoreBinary::store((var0 = flags_ | (unread_ << 0)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_markDialogUnread::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.markDialogUnread");
    s.store_field("flags", (var0 = flags_ | (unread_ << 0)));
    if (var0 & 1) { s.store_field("unread", true); }
    if (var0 & 2) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_markDialogUnread::ReturnType messages_markDialogUnread::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_rateTranscribedAudio::messages_rateTranscribedAudio(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 transcription_id_, bool good_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , transcription_id_(transcription_id_)
  , good_(good_)
{}

const std::int32_t messages_rateTranscribedAudio::ID;

void messages_rateTranscribedAudio::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2132608815);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(transcription_id_, s);
  TlStoreBool::store(good_, s);
}

void messages_rateTranscribedAudio::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2132608815);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(transcription_id_, s);
  TlStoreBool::store(good_, s);
}

void messages_rateTranscribedAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.rateTranscribedAudio");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("transcription_id", transcription_id_);
    s.store_field("good", good_);
    s.store_class_end();
  }
}

messages_rateTranscribedAudio::ReturnType messages_rateTranscribedAudio::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_reportSpam::messages_reportSpam(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_reportSpam::ID;

void messages_reportSpam::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-820669733);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_reportSpam::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-820669733);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_reportSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportSpam");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_reportSpam::ReturnType messages_reportSpam::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_requestEncryption::messages_requestEncryption(object_ptr<InputUser> &&user_id_, int32 random_id_, bytes &&g_a_)
  : user_id_(std::move(user_id_))
  , random_id_(random_id_)
  , g_a_(std::move(g_a_))
{}

const std::int32_t messages_requestEncryption::ID;

void messages_requestEncryption::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-162681021);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(g_a_, s);
}

void messages_requestEncryption::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-162681021);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(g_a_, s);
}

void messages_requestEncryption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestEncryption");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("random_id", random_id_);
    s.store_bytes_field("g_a", g_a_);
    s.store_class_end();
  }
}

messages_requestEncryption::ReturnType messages_requestEncryption::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EncryptedChat>::parse(p);
#undef FAIL
}

messages_requestWebView::messages_requestWebView(int32 flags_, bool from_bot_menu_, bool silent_, bool compact_, bool fullscreen_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&bot_, string const &url_, string const &start_param_, object_ptr<dataJSON> &&theme_params_, string const &platform_, object_ptr<InputReplyTo> &&reply_to_, object_ptr<InputPeer> &&send_as_)
  : flags_(flags_)
  , from_bot_menu_(from_bot_menu_)
  , silent_(silent_)
  , compact_(compact_)
  , fullscreen_(fullscreen_)
  , peer_(std::move(peer_))
  , bot_(std::move(bot_))
  , url_(url_)
  , start_param_(start_param_)
  , theme_params_(std::move(theme_params_))
  , platform_(platform_)
  , reply_to_(std::move(reply_to_))
  , send_as_(std::move(send_as_))
{}

const std::int32_t messages_requestWebView::ID;

void messages_requestWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(647873217);
  TlStoreBinary::store((var0 = flags_ | (from_bot_menu_ << 4) | (silent_ << 5) | (compact_ << 7) | (fullscreen_ << 8)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 2) { TlStoreString::store(url_, s); }
  if (var0 & 8) { TlStoreString::store(start_param_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void messages_requestWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(647873217);
  TlStoreBinary::store((var0 = flags_ | (from_bot_menu_ << 4) | (silent_ << 5) | (compact_ << 7) | (fullscreen_ << 8)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 2) { TlStoreString::store(url_, s); }
  if (var0 & 8) { TlStoreString::store(start_param_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void messages_requestWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestWebView");
    s.store_field("flags", (var0 = flags_ | (from_bot_menu_ << 4) | (silent_ << 5) | (compact_ << 7) | (fullscreen_ << 8)));
    if (var0 & 16) { s.store_field("from_bot_menu", true); }
    if (var0 & 32) { s.store_field("silent", true); }
    if (var0 & 128) { s.store_field("compact", true); }
    if (var0 & 256) { s.store_field("fullscreen", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    if (var0 & 2) { s.store_field("url", url_); }
    if (var0 & 8) { s.store_field("start_param", start_param_); }
    if (var0 & 4) { s.store_object_field("theme_params", static_cast<const BaseObject *>(theme_params_.get())); }
    s.store_field("platform", platform_);
    if (var0 & 1) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    s.store_class_end();
  }
}

messages_requestWebView::ReturnType messages_requestWebView::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<webViewResultUrl>, 1294139288>::parse(p);
#undef FAIL
}

messages_searchStickers::messages_searchStickers(int32 flags_, bool emojis_, string const &q_, string const &emoticon_, array<string> &&lang_code_, int32 offset_, int32 limit_, int64 hash_)
  : flags_(flags_)
  , emojis_(emojis_)
  , q_(q_)
  , emoticon_(emoticon_)
  , lang_code_(std::move(lang_code_))
  , offset_(offset_)
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_searchStickers::ID;

void messages_searchStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(699516522);
  TlStoreBinary::store((var0 = flags_ | (emojis_ << 0)), s);
  TlStoreString::store(q_, s);
  TlStoreString::store(emoticon_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(lang_code_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(699516522);
  TlStoreBinary::store((var0 = flags_ | (emojis_ << 0)), s);
  TlStoreString::store(q_, s);
  TlStoreString::store(emoticon_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(lang_code_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchStickers");
    s.store_field("flags", (var0 = flags_ | (emojis_ << 0)));
    if (var0 & 1) { s.store_field("emojis", true); }
    s.store_field("q", q_);
    s.store_field("emoticon", emoticon_);
    { s.store_vector_begin("lang_code", lang_code_.size()); for (const auto &_value : lang_code_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_searchStickers::ReturnType messages_searchStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FoundStickers>::parse(p);
#undef FAIL
}

messages_sendEncryptedFile::messages_sendEncryptedFile(int32 flags_, bool silent_, object_ptr<inputEncryptedChat> &&peer_, int64 random_id_, bytes &&data_, object_ptr<InputEncryptedFile> &&file_)
  : flags_(flags_)
  , silent_(silent_)
  , peer_(std::move(peer_))
  , random_id_(random_id_)
  , data_(std::move(data_))
  , file_(std::move(file_))
{}

const std::int32_t messages_sendEncryptedFile::ID;

void messages_sendEncryptedFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1431914525);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 0)), s);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(data_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void messages_sendEncryptedFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1431914525);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 0)), s);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(data_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void messages_sendEncryptedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendEncryptedFile");
    s.store_field("flags", (var0 = flags_ | (silent_ << 0)));
    if (var0 & 1) { s.store_field("silent", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("random_id", random_id_);
    s.store_bytes_field("data", data_);
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

messages_sendEncryptedFile::ReturnType messages_sendEncryptedFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SentEncryptedMessage>::parse(p);
#undef FAIL
}

messages_sendEncryptedService::messages_sendEncryptedService(object_ptr<inputEncryptedChat> &&peer_, int64 random_id_, bytes &&data_)
  : peer_(std::move(peer_))
  , random_id_(random_id_)
  , data_(std::move(data_))
{}

const std::int32_t messages_sendEncryptedService::ID;

void messages_sendEncryptedService::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(852769188);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(data_, s);
}

void messages_sendEncryptedService::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(852769188);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(data_, s);
}

void messages_sendEncryptedService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendEncryptedService");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("random_id", random_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

messages_sendEncryptedService::ReturnType messages_sendEncryptedService::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SentEncryptedMessage>::parse(p);
#undef FAIL
}

messages_setChatTheme::messages_setChatTheme(object_ptr<InputPeer> &&peer_, object_ptr<InputChatTheme> &&theme_)
  : peer_(std::move(peer_))
  , theme_(std::move(theme_))
{}

const std::int32_t messages_setChatTheme::ID;

void messages_setChatTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(135398089);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
}

void messages_setChatTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(135398089);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
}

void messages_setChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setChatTheme");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

messages_setChatTheme::ReturnType messages_setChatTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setGameScore::messages_setGameScore(int32 flags_, bool edit_message_, bool force_, object_ptr<InputPeer> &&peer_, int32 id_, object_ptr<InputUser> &&user_id_, int32 score_)
  : flags_(flags_)
  , edit_message_(edit_message_)
  , force_(force_)
  , peer_(std::move(peer_))
  , id_(id_)
  , user_id_(std::move(user_id_))
  , score_(score_)
{}

const std::int32_t messages_setGameScore::ID;

void messages_setGameScore::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1896289088);
  TlStoreBinary::store((var0 = flags_ | (edit_message_ << 0) | (force_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(score_, s);
}

void messages_setGameScore::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1896289088);
  TlStoreBinary::store((var0 = flags_ | (edit_message_ << 0) | (force_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(score_, s);
}

void messages_setGameScore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setGameScore");
    s.store_field("flags", (var0 = flags_ | (edit_message_ << 0) | (force_ << 1)));
    if (var0 & 1) { s.store_field("edit_message", true); }
    if (var0 & 2) { s.store_field("force", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("score", score_);
    s.store_class_end();
  }
}

messages_setGameScore::ReturnType messages_setGameScore::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setTyping::messages_setTyping(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_, object_ptr<SendMessageAction> &&action_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
  , action_(std::move(action_))
{}

const std::int32_t messages_setTyping::ID;

void messages_setTyping::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1486110434);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(action_, s);
}

void messages_setTyping::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1486110434);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(action_, s);
}

void messages_setTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setTyping");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_object_field("action", static_cast<const BaseObject *>(action_.get()));
    s.store_class_end();
  }
}

messages_setTyping::ReturnType messages_setTyping::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_summarizeText::messages_summarizeText(int32 flags_, object_ptr<InputPeer> &&peer_, int32 id_, string const &to_lang_, string const &tone_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(id_)
  , to_lang_(to_lang_)
  , tone_(tone_)
{}

const std::int32_t messages_summarizeText::ID;

void messages_summarizeText::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1413754042);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(to_lang_, s); }
  if (var0 & 4) { TlStoreString::store(tone_, s); }
}

void messages_summarizeText::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1413754042);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(to_lang_, s); }
  if (var0 & 4) { TlStoreString::store(tone_, s); }
}

void messages_summarizeText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.summarizeText");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_field("to_lang", to_lang_); }
    if (var0 & 4) { s.store_field("tone", tone_); }
    s.store_class_end();
  }
}

messages_summarizeText::ReturnType messages_summarizeText::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
#undef FAIL
}

payments_exportInvoice::payments_exportInvoice(object_ptr<InputMedia> &&invoice_media_)
  : invoice_media_(std::move(invoice_media_))
{}

const std::int32_t payments_exportInvoice::ID;

void payments_exportInvoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(261206117);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_media_, s);
}

void payments_exportInvoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(261206117);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_media_, s);
}

void payments_exportInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.exportInvoice");
    s.store_object_field("invoice_media", static_cast<const BaseObject *>(invoice_media_.get()));
    s.store_class_end();
  }
}

payments_exportInvoice::ReturnType payments_exportInvoice::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_exportedInvoice>, -1362048039>::parse(p);
#undef FAIL
}

payments_getStarGiftAuctionState::payments_getStarGiftAuctionState(object_ptr<InputStarGiftAuction> &&auction_, int32 version_)
  : auction_(std::move(auction_))
  , version_(version_)
{}

const std::int32_t payments_getStarGiftAuctionState::ID;

void payments_getStarGiftAuctionState::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1553986774);
  TlStoreBoxedUnknown<TlStoreObject>::store(auction_, s);
  TlStoreBinary::store(version_, s);
}

void payments_getStarGiftAuctionState::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1553986774);
  TlStoreBoxedUnknown<TlStoreObject>::store(auction_, s);
  TlStoreBinary::store(version_, s);
}

void payments_getStarGiftAuctionState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftAuctionState");
    s.store_object_field("auction", static_cast<const BaseObject *>(auction_.get()));
    s.store_field("version", version_);
    s.store_class_end();
  }
}

payments_getStarGiftAuctionState::ReturnType payments_getStarGiftAuctionState::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftAuctionState>, 1798960364>::parse(p);
#undef FAIL
}

payments_getStarsRevenueWithdrawalUrl::payments_getStarsRevenueWithdrawalUrl(int32 flags_, bool ton_, object_ptr<InputPeer> &&peer_, int64 amount_, object_ptr<InputCheckPasswordSRP> &&password_)
  : flags_(flags_)
  , ton_(ton_)
  , peer_(std::move(peer_))
  , amount_(amount_)
  , password_(std::move(password_))
{}

const std::int32_t payments_getStarsRevenueWithdrawalUrl::ID;

void payments_getStarsRevenueWithdrawalUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(607378578);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreBinary::store(amount_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void payments_getStarsRevenueWithdrawalUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(607378578);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreBinary::store(amount_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
}

void payments_getStarsRevenueWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsRevenueWithdrawalUrl");
    s.store_field("flags", (var0 = flags_ | (ton_ << 0)));
    if (var0 & 1) { s.store_field("ton", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_field("amount", amount_); }
    s.store_object_field("password", static_cast<const BaseObject *>(password_.get()));
    s.store_class_end();
  }
}

payments_getStarsRevenueWithdrawalUrl::ReturnType payments_getStarsRevenueWithdrawalUrl::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsRevenueWithdrawalUrl>, 497778871>::parse(p);
#undef FAIL
}

payments_getStarsSubscriptions::payments_getStarsSubscriptions(int32 flags_, bool missing_balance_, object_ptr<InputPeer> &&peer_, string const &offset_)
  : flags_(flags_)
  , missing_balance_(missing_balance_)
  , peer_(std::move(peer_))
  , offset_(offset_)
{}

const std::int32_t payments_getStarsSubscriptions::ID;

void payments_getStarsSubscriptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(52761285);
  TlStoreBinary::store((var0 = flags_ | (missing_balance_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
}

void payments_getStarsSubscriptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(52761285);
  TlStoreBinary::store((var0 = flags_ | (missing_balance_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
}

void payments_getStarsSubscriptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsSubscriptions");
    s.store_field("flags", (var0 = flags_ | (missing_balance_ << 0)));
    if (var0 & 1) { s.store_field("missing_balance", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

payments_getStarsSubscriptions::ReturnType payments_getStarsSubscriptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsStatus>, 1822222573>::parse(p);
#undef FAIL
}

const std::int32_t payments_getStarsTopupOptions::ID;

void payments_getStarsTopupOptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1072773165);
}

void payments_getStarsTopupOptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1072773165);
}

void payments_getStarsTopupOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsTopupOptions");
    s.store_class_end();
  }
}

payments_getStarsTopupOptions::ReturnType payments_getStarsTopupOptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starsTopupOption>, 198776256>>, 481674261>::parse(p);
#undef FAIL
}

payments_resolveStarGiftOffer::payments_resolveStarGiftOffer(int32 flags_, bool decline_, int32 offer_msg_id_)
  : flags_(flags_)
  , decline_(decline_)
  , offer_msg_id_(offer_msg_id_)
{}

const std::int32_t payments_resolveStarGiftOffer::ID;

void payments_resolveStarGiftOffer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-372344804);
  TlStoreBinary::store((var0 = flags_ | (decline_ << 0)), s);
  TlStoreBinary::store(offer_msg_id_, s);
}

void payments_resolveStarGiftOffer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-372344804);
  TlStoreBinary::store((var0 = flags_ | (decline_ << 0)), s);
  TlStoreBinary::store(offer_msg_id_, s);
}

void payments_resolveStarGiftOffer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.resolveStarGiftOffer");
    s.store_field("flags", (var0 = flags_ | (decline_ << 0)));
    if (var0 & 1) { s.store_field("decline", true); }
    s.store_field("offer_msg_id", offer_msg_id_);
    s.store_class_end();
  }
}

payments_resolveStarGiftOffer::ReturnType payments_resolveStarGiftOffer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_updateStarGiftCollection::payments_updateStarGiftCollection(int32 flags_, object_ptr<InputPeer> &&peer_, int32 collection_id_, string const &title_, array<object_ptr<InputSavedStarGift>> &&delete_stargift_, array<object_ptr<InputSavedStarGift>> &&add_stargift_, array<object_ptr<InputSavedStarGift>> &&order_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , collection_id_(collection_id_)
  , title_(title_)
  , delete_stargift_(std::move(delete_stargift_))
  , add_stargift_(std::move(add_stargift_))
  , order_(std::move(order_))
{}

const std::int32_t payments_updateStarGiftCollection::ID;

void payments_updateStarGiftCollection::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1339932391);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(collection_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(delete_stargift_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(add_stargift_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s); }
}

void payments_updateStarGiftCollection::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1339932391);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(collection_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(delete_stargift_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(add_stargift_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s); }
}

void payments_updateStarGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.updateStarGiftCollection");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("collection_id", collection_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { { s.store_vector_begin("delete_stargift", delete_stargift_.size()); for (const auto &_value : delete_stargift_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("add_stargift", add_stargift_.size()); for (const auto &_value : add_stargift_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 8) { { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

payments_updateStarGiftCollection::ReturnType payments_updateStarGiftCollection::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<starGiftCollection>, -1653926992>::parse(p);
#undef FAIL
}

phone_discardCall::phone_discardCall(int32 flags_, bool video_, object_ptr<inputPhoneCall> &&peer_, int32 duration_, object_ptr<PhoneCallDiscardReason> &&reason_, int64 connection_id_)
  : flags_(flags_)
  , video_(video_)
  , peer_(std::move(peer_))
  , duration_(duration_)
  , reason_(std::move(reason_))
  , connection_id_(connection_id_)
{}

const std::int32_t phone_discardCall::ID;

void phone_discardCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1295269440);
  TlStoreBinary::store((var0 = flags_ | (video_ << 0)), s);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBinary::store(duration_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reason_, s);
  TlStoreBinary::store(connection_id_, s);
}

void phone_discardCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1295269440);
  TlStoreBinary::store((var0 = flags_ | (video_ << 0)), s);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBinary::store(duration_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reason_, s);
  TlStoreBinary::store(connection_id_, s);
}

void phone_discardCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.discardCall");
    s.store_field("flags", (var0 = flags_ | (video_ << 0)));
    if (var0 & 1) { s.store_field("video", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("duration", duration_);
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("connection_id", connection_id_);
    s.store_class_end();
  }
}

phone_discardCall::ReturnType phone_discardCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_leaveGroupCall::phone_leaveGroupCall(object_ptr<InputGroupCall> &&call_, int32 source_)
  : call_(std::move(call_))
  , source_(source_)
{}

const std::int32_t phone_leaveGroupCall::ID;

void phone_leaveGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1342404601);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(source_, s);
}

void phone_leaveGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1342404601);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(source_, s);
}

void phone_leaveGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.leaveGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("source", source_);
    s.store_class_end();
  }
}

phone_leaveGroupCall::ReturnType phone_leaveGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_leaveGroupCallPresentation::phone_leaveGroupCallPresentation(object_ptr<InputGroupCall> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t phone_leaveGroupCallPresentation::ID;

void phone_leaveGroupCallPresentation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(475058500);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_leaveGroupCallPresentation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(475058500);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_leaveGroupCallPresentation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.leaveGroupCallPresentation");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

phone_leaveGroupCallPresentation::ReturnType phone_leaveGroupCallPresentation::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

photos_getUserPhotos::photos_getUserPhotos(object_ptr<InputUser> &&user_id_, int32 offset_, int64 max_id_, int32 limit_)
  : user_id_(std::move(user_id_))
  , offset_(offset_)
  , max_id_(max_id_)
  , limit_(limit_)
{}

const std::int32_t photos_getUserPhotos::ID;

void photos_getUserPhotos::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1848823128);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(limit_, s);
}

void photos_getUserPhotos::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1848823128);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(limit_, s);
}

void photos_getUserPhotos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.getUserPhotos");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("offset", offset_);
    s.store_field("max_id", max_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

photos_getUserPhotos::ReturnType photos_getUserPhotos::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<photos_Photos>::parse(p);
#undef FAIL
}

const std::int32_t smsjobs_leave::ID;

void smsjobs_leave::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1734824589);
}

void smsjobs_leave::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1734824589);
}

void smsjobs_leave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.leave");
    s.store_class_end();
  }
}

smsjobs_leave::ReturnType smsjobs_leave::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stats_getMessagePublicForwards::stats_getMessagePublicForwards(object_ptr<InputChannel> &&channel_, int32 msg_id_, string const &offset_, int32 limit_)
  : channel_(std::move(channel_))
  , msg_id_(msg_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t stats_getMessagePublicForwards::ID;

void stats_getMessagePublicForwards::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1595212100);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stats_getMessagePublicForwards::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1595212100);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stats_getMessagePublicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getMessagePublicForwards");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stats_getMessagePublicForwards::ReturnType stats_getMessagePublicForwards::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_publicForwards>, -1828487648>::parse(p);
#undef FAIL
}

stickers_changeStickerPosition::stickers_changeStickerPosition(object_ptr<InputDocument> &&sticker_, int32 position_)
  : sticker_(std::move(sticker_))
  , position_(position_)
{}

const std::int32_t stickers_changeStickerPosition::ID;

void stickers_changeStickerPosition::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-4795190);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  TlStoreBinary::store(position_, s);
}

void stickers_changeStickerPosition::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-4795190);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  TlStoreBinary::store(position_, s);
}

void stickers_changeStickerPosition::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.changeStickerPosition");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_field("position", position_);
    s.store_class_end();
  }
}

stickers_changeStickerPosition::ReturnType stickers_changeStickerPosition::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

updates_getChannelDifference::updates_getChannelDifference(int32 flags_, bool force_, object_ptr<InputChannel> &&channel_, object_ptr<ChannelMessagesFilter> &&filter_, int32 pts_, int32 limit_)
  : flags_(flags_)
  , force_(force_)
  , channel_(std::move(channel_))
  , filter_(std::move(filter_))
  , pts_(pts_)
  , limit_(limit_)
{}

const std::int32_t updates_getChannelDifference::ID;

void updates_getChannelDifference::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(51854712);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(pts_, s);
  TlStoreBinary::store(limit_, s);
}

void updates_getChannelDifference::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(51854712);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(pts_, s);
  TlStoreBinary::store(limit_, s);
}

void updates_getChannelDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.getChannelDifference");
    s.store_field("flags", (var0 = flags_ | (force_ << 0)));
    if (var0 & 1) { s.store_field("force", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("pts", pts_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

updates_getChannelDifference::ReturnType updates_getChannelDifference::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<updates_ChannelDifference>::parse(p);
#undef FAIL
}

users_getFullUser::users_getFullUser(object_ptr<InputUser> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t users_getFullUser::ID;

void users_getFullUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1240508136);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void users_getFullUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1240508136);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void users_getFullUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.getFullUser");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

users_getFullUser::ReturnType users_getFullUser::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<users_userFull>, 997004590>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
