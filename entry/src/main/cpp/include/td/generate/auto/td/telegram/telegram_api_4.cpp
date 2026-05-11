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


object_ptr<AttachMenuBots> AttachMenuBots::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case attachMenuBotsNotModified::ID:
      return attachMenuBotsNotModified::fetch(p);
    case attachMenuBots::ID:
      return attachMenuBots::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t attachMenuBotsNotModified::ID;

object_ptr<AttachMenuBots> attachMenuBotsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuBotsNotModified>();
}

void attachMenuBotsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuBotsNotModified");
    s.store_class_end();
  }
}

const std::int32_t attachMenuBots::ID;

object_ptr<AttachMenuBots> attachMenuBots::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuBots>(p);
}

attachMenuBots::attachMenuBots(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , bots_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<attachMenuBot>, -653423106>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void attachMenuBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuBots");
    s.store_field("hash", hash_);
    { s.store_vector_begin("bots", bots_.size()); for (const auto &_value : bots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

autoDownloadSettings::autoDownloadSettings()
  : flags_()
  , disabled_()
  , video_preload_large_()
  , audio_preload_next_()
  , phonecalls_less_data_()
  , stories_preload_()
  , photo_size_max_()
  , video_size_max_()
  , file_size_max_()
  , video_upload_maxbitrate_()
  , small_queue_active_operations_max_()
  , large_queue_active_operations_max_()
{}

autoDownloadSettings::autoDownloadSettings(int32 flags_, bool disabled_, bool video_preload_large_, bool audio_preload_next_, bool phonecalls_less_data_, bool stories_preload_, int32 photo_size_max_, int64 video_size_max_, int64 file_size_max_, int32 video_upload_maxbitrate_, int32 small_queue_active_operations_max_, int32 large_queue_active_operations_max_)
  : flags_(flags_)
  , disabled_(disabled_)
  , video_preload_large_(video_preload_large_)
  , audio_preload_next_(audio_preload_next_)
  , phonecalls_less_data_(phonecalls_less_data_)
  , stories_preload_(stories_preload_)
  , photo_size_max_(photo_size_max_)
  , video_size_max_(video_size_max_)
  , file_size_max_(file_size_max_)
  , video_upload_maxbitrate_(video_upload_maxbitrate_)
  , small_queue_active_operations_max_(small_queue_active_operations_max_)
  , large_queue_active_operations_max_(large_queue_active_operations_max_)
{}

const std::int32_t autoDownloadSettings::ID;

object_ptr<autoDownloadSettings> autoDownloadSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<autoDownloadSettings> res = make_tl_object<autoDownloadSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->disabled_ = (var0 & 1) != 0;
  res->video_preload_large_ = (var0 & 2) != 0;
  res->audio_preload_next_ = (var0 & 4) != 0;
  res->phonecalls_less_data_ = (var0 & 8) != 0;
  res->stories_preload_ = (var0 & 16) != 0;
  res->photo_size_max_ = TlFetchInt::parse(p);
  res->video_size_max_ = TlFetchLong::parse(p);
  res->file_size_max_ = TlFetchLong::parse(p);
  res->video_upload_maxbitrate_ = TlFetchInt::parse(p);
  res->small_queue_active_operations_max_ = TlFetchInt::parse(p);
  res->large_queue_active_operations_max_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void autoDownloadSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (disabled_ << 0) | (video_preload_large_ << 1) | (audio_preload_next_ << 2) | (phonecalls_less_data_ << 3) | (stories_preload_ << 4)), s);
  TlStoreBinary::store(photo_size_max_, s);
  TlStoreBinary::store(video_size_max_, s);
  TlStoreBinary::store(file_size_max_, s);
  TlStoreBinary::store(video_upload_maxbitrate_, s);
  TlStoreBinary::store(small_queue_active_operations_max_, s);
  TlStoreBinary::store(large_queue_active_operations_max_, s);
}

void autoDownloadSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (disabled_ << 0) | (video_preload_large_ << 1) | (audio_preload_next_ << 2) | (phonecalls_less_data_ << 3) | (stories_preload_ << 4)), s);
  TlStoreBinary::store(photo_size_max_, s);
  TlStoreBinary::store(video_size_max_, s);
  TlStoreBinary::store(file_size_max_, s);
  TlStoreBinary::store(video_upload_maxbitrate_, s);
  TlStoreBinary::store(small_queue_active_operations_max_, s);
  TlStoreBinary::store(large_queue_active_operations_max_, s);
}

void autoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autoDownloadSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (disabled_ << 0) | (video_preload_large_ << 1) | (audio_preload_next_ << 2) | (phonecalls_less_data_ << 3) | (stories_preload_ << 4)));
    if (var0 & 1) { s.store_field("disabled", true); }
    if (var0 & 2) { s.store_field("video_preload_large", true); }
    if (var0 & 4) { s.store_field("audio_preload_next", true); }
    if (var0 & 8) { s.store_field("phonecalls_less_data", true); }
    if (var0 & 16) { s.store_field("stories_preload", true); }
    s.store_field("photo_size_max", photo_size_max_);
    s.store_field("video_size_max", video_size_max_);
    s.store_field("file_size_max", file_size_max_);
    s.store_field("video_upload_maxbitrate", video_upload_maxbitrate_);
    s.store_field("small_queue_active_operations_max", small_queue_active_operations_max_);
    s.store_field("large_queue_active_operations_max", large_queue_active_operations_max_);
    s.store_class_end();
  }
}

botInfo::botInfo()
  : flags_()
  , has_preview_medias_()
  , user_id_()
  , description_()
  , description_photo_()
  , description_document_()
  , commands_()
  , menu_button_()
  , privacy_policy_url_()
  , app_settings_()
  , verifier_settings_()
{}

const std::int32_t botInfo::ID;

object_ptr<botInfo> botInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInfo> res = make_tl_object<botInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_preview_medias_ = (var0 & 64) != 0;
  if (var0 & 1) { res->user_id_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->description_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->description_photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 32) { res->description_document_ = TlFetchObject<Document>::parse(p); }
  if (var0 & 4) { res->commands_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botCommand>, -1032140601>>, 481674261>::parse(p); }
  if (var0 & 8) { res->menu_button_ = TlFetchObject<BotMenuButton>::parse(p); }
  if (var0 & 128) { res->privacy_policy_url_ = TlFetchString<string>::parse(p); }
  if (var0 & 256) { res->app_settings_ = TlFetchBoxed<TlFetchObject<botAppSettings>, -912582320>::parse(p); }
  if (var0 & 512) { res->verifier_settings_ = TlFetchBoxed<TlFetchObject<botVerifierSettings>, -1328716265>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void botInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_preview_medias_ << 6)));
    if (var0 & 64) { s.store_field("has_preview_medias", true); }
    if (var0 & 1) { s.store_field("user_id", user_id_); }
    if (var0 & 2) { s.store_field("description", description_); }
    if (var0 & 16) { s.store_object_field("description_photo", static_cast<const BaseObject *>(description_photo_.get())); }
    if (var0 & 32) { s.store_object_field("description_document", static_cast<const BaseObject *>(description_document_.get())); }
    if (var0 & 4) { { s.store_vector_begin("commands", commands_.size()); for (const auto &_value : commands_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 8) { s.store_object_field("menu_button", static_cast<const BaseObject *>(menu_button_.get())); }
    if (var0 & 128) { s.store_field("privacy_policy_url", privacy_policy_url_); }
    if (var0 & 256) { s.store_object_field("app_settings", static_cast<const BaseObject *>(app_settings_.get())); }
    if (var0 & 512) { s.store_object_field("verifier_settings", static_cast<const BaseObject *>(verifier_settings_.get())); }
    s.store_class_end();
  }
}

businessChatLink::businessChatLink()
  : flags_()
  , link_()
  , message_()
  , entities_()
  , title_()
  , views_()
{}

const std::int32_t businessChatLink::ID;

object_ptr<businessChatLink> businessChatLink::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessChatLink> res = make_tl_object<businessChatLink>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->link_ = TlFetchString<string>::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 2) { res->title_ = TlFetchString<string>::parse(p); }
  res->views_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessChatLink");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("link", link_);
    s.store_field("message", message_);
    if (var0 & 1) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_field("title", title_); }
    s.store_field("views", views_);
    s.store_class_end();
  }
}

const std::int32_t cdnPublicKey::ID;

object_ptr<cdnPublicKey> cdnPublicKey::fetch(TlBufferParser &p) {
  return make_tl_object<cdnPublicKey>(p);
}

cdnPublicKey::cdnPublicKey(TlBufferParser &p)
  : dc_id_(TlFetchInt::parse(p))
  , public_key_(TlFetchString<string>::parse(p))
{}

void cdnPublicKey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "cdnPublicKey");
    s.store_field("dc_id", dc_id_);
    s.store_field("public_key", public_key_);
    s.store_class_end();
  }
}

const std::int32_t chatOnlines::ID;

object_ptr<chatOnlines> chatOnlines::fetch(TlBufferParser &p) {
  return make_tl_object<chatOnlines>(p);
}

chatOnlines::chatOnlines(TlBufferParser &p)
  : onlines_(TlFetchInt::parse(p))
{}

void chatOnlines::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatOnlines");
    s.store_field("onlines", onlines_);
    s.store_class_end();
  }
}

object_ptr<ChatParticipant> ChatParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatParticipant::ID:
      return chatParticipant::fetch(p);
    case chatParticipantCreator::ID:
      return chatParticipantCreator::fetch(p);
    case chatParticipantAdmin::ID:
      return chatParticipantAdmin::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

chatParticipant::chatParticipant()
  : flags_()
  , user_id_()
  , inviter_id_()
  , date_()
  , rank_()
{}

const std::int32_t chatParticipant::ID;

object_ptr<ChatParticipant> chatParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatParticipant> res = make_tl_object<chatParticipant>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  res->inviter_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatParticipant");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("user_id", user_id_);
    s.store_field("inviter_id", inviter_id_);
    s.store_field("date", date_);
    if (var0 & 1) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

chatParticipantCreator::chatParticipantCreator()
  : flags_()
  , user_id_()
  , rank_()
{}

const std::int32_t chatParticipantCreator::ID;

object_ptr<ChatParticipant> chatParticipantCreator::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatParticipantCreator> res = make_tl_object<chatParticipantCreator>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatParticipantCreator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatParticipantCreator");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("user_id", user_id_);
    if (var0 & 1) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

chatParticipantAdmin::chatParticipantAdmin()
  : flags_()
  , user_id_()
  , inviter_id_()
  , date_()
  , rank_()
{}

const std::int32_t chatParticipantAdmin::ID;

object_ptr<ChatParticipant> chatParticipantAdmin::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatParticipantAdmin> res = make_tl_object<chatParticipantAdmin>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  res->inviter_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatParticipantAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatParticipantAdmin");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("user_id", user_id_);
    s.store_field("inviter_id", inviter_id_);
    s.store_field("date", date_);
    if (var0 & 1) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

object_ptr<ExportedChatInvite> ExportedChatInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatInviteExported::ID:
      return chatInviteExported::fetch(p);
    case chatInvitePublicJoinRequests::ID:
      return chatInvitePublicJoinRequests::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

chatInviteExported::chatInviteExported()
  : flags_()
  , revoked_()
  , permanent_()
  , request_needed_()
  , link_()
  , admin_id_()
  , date_()
  , start_date_()
  , expire_date_()
  , usage_limit_()
  , usage_()
  , requested_()
  , subscription_expired_()
  , title_()
  , subscription_pricing_()
{}

const std::int32_t chatInviteExported::ID;

object_ptr<ExportedChatInvite> chatInviteExported::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatInviteExported> res = make_tl_object<chatInviteExported>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->revoked_ = (var0 & 1) != 0;
  res->permanent_ = (var0 & 32) != 0;
  res->request_needed_ = (var0 & 64) != 0;
  res->link_ = TlFetchString<string>::parse(p);
  res->admin_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 16) { res->start_date_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->expire_date_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->usage_limit_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->usage_ = TlFetchInt::parse(p); }
  if (var0 & 128) { res->requested_ = TlFetchInt::parse(p); }
  if (var0 & 1024) { res->subscription_expired_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 512) { res->subscription_pricing_ = TlFetchBoxed<TlFetchObject<starsSubscriptionPricing>, 88173912>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatInviteExported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteExported");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (revoked_ << 0) | (permanent_ << 5) | (request_needed_ << 6)));
    if (var0 & 1) { s.store_field("revoked", true); }
    if (var0 & 32) { s.store_field("permanent", true); }
    if (var0 & 64) { s.store_field("request_needed", true); }
    s.store_field("link", link_);
    s.store_field("admin_id", admin_id_);
    s.store_field("date", date_);
    if (var0 & 16) { s.store_field("start_date", start_date_); }
    if (var0 & 2) { s.store_field("expire_date", expire_date_); }
    if (var0 & 4) { s.store_field("usage_limit", usage_limit_); }
    if (var0 & 8) { s.store_field("usage", usage_); }
    if (var0 & 128) { s.store_field("requested", requested_); }
    if (var0 & 1024) { s.store_field("subscription_expired", subscription_expired_); }
    if (var0 & 256) { s.store_field("title", title_); }
    if (var0 & 512) { s.store_object_field("subscription_pricing", static_cast<const BaseObject *>(subscription_pricing_.get())); }
    s.store_class_end();
  }
}

const std::int32_t chatInvitePublicJoinRequests::ID;

object_ptr<ExportedChatInvite> chatInvitePublicJoinRequests::fetch(TlBufferParser &p) {
  return make_tl_object<chatInvitePublicJoinRequests>();
}

void chatInvitePublicJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInvitePublicJoinRequests");
    s.store_class_end();
  }
}

factCheck::factCheck()
  : flags_()
  , need_check_()
  , country_()
  , text_()
  , hash_()
{}

const std::int32_t factCheck::ID;

object_ptr<factCheck> factCheck::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<factCheck> res = make_tl_object<factCheck>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->need_check_ = (var0 & 1) != 0;
  if (var0 & 2) { res->country_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->text_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  res->hash_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void factCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "factCheck");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (need_check_ << 0)));
    if (var0 & 1) { s.store_field("need_check", true); }
    if (var0 & 2) { s.store_field("country", country_); }
    if (var0 & 2) { s.store_object_field("text", static_cast<const BaseObject *>(text_.get())); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

object_ptr<GroupCall> GroupCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case groupCallDiscarded::ID:
      return groupCallDiscarded::fetch(p);
    case groupCall::ID:
      return groupCall::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t groupCallDiscarded::ID;

object_ptr<GroupCall> groupCallDiscarded::fetch(TlBufferParser &p) {
  return make_tl_object<groupCallDiscarded>(p);
}

groupCallDiscarded::groupCallDiscarded(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , duration_(TlFetchInt::parse(p))
{}

void groupCallDiscarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallDiscarded");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("duration", duration_);
    s.store_class_end();
  }
}

groupCall::groupCall()
  : flags_()
  , join_muted_()
  , can_change_join_muted_()
  , join_date_asc_()
  , schedule_start_subscribed_()
  , can_start_video_()
  , record_video_active_()
  , rtmp_stream_()
  , listeners_hidden_()
  , conference_()
  , creator_()
  , messages_enabled_()
  , can_change_messages_enabled_()
  , min_()
  , id_()
  , access_hash_()
  , participants_count_()
  , title_()
  , stream_dc_id_()
  , record_start_date_()
  , schedule_date_()
  , unmuted_video_count_()
  , unmuted_video_limit_()
  , version_()
  , invite_link_()
  , send_paid_messages_stars_()
  , default_send_as_()
{}

const std::int32_t groupCall::ID;

object_ptr<GroupCall> groupCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<groupCall> res = make_tl_object<groupCall>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->join_muted_ = (var0 & 2) != 0;
  res->can_change_join_muted_ = (var0 & 4) != 0;
  res->join_date_asc_ = (var0 & 64) != 0;
  res->schedule_start_subscribed_ = (var0 & 256) != 0;
  res->can_start_video_ = (var0 & 512) != 0;
  res->record_video_active_ = (var0 & 2048) != 0;
  res->rtmp_stream_ = (var0 & 4096) != 0;
  res->listeners_hidden_ = (var0 & 8192) != 0;
  res->conference_ = (var0 & 16384) != 0;
  res->creator_ = (var0 & 32768) != 0;
  res->messages_enabled_ = (var0 & 131072) != 0;
  res->can_change_messages_enabled_ = (var0 & 262144) != 0;
  res->min_ = (var0 & 524288) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->participants_count_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->stream_dc_id_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->record_start_date_ = TlFetchInt::parse(p); }
  if (var0 & 128) { res->schedule_date_ = TlFetchInt::parse(p); }
  if (var0 & 1024) { res->unmuted_video_count_ = TlFetchInt::parse(p); }
  res->unmuted_video_limit_ = TlFetchInt::parse(p);
  res->version_ = TlFetchInt::parse(p);
  if (var0 & 65536) { res->invite_link_ = TlFetchString<string>::parse(p); }
  if (var0 & 1048576) { res->send_paid_messages_stars_ = TlFetchLong::parse(p); }
  if (var0 & 2097152) { res->default_send_as_ = TlFetchObject<Peer>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void groupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCall");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (join_muted_ << 1) | (can_change_join_muted_ << 2) | (join_date_asc_ << 6) | (schedule_start_subscribed_ << 8) | (can_start_video_ << 9) | (record_video_active_ << 11) | (rtmp_stream_ << 12) | (listeners_hidden_ << 13) | (conference_ << 14) | (creator_ << 15) | (messages_enabled_ << 17) | (can_change_messages_enabled_ << 18) | (min_ << 19)));
    if (var0 & 2) { s.store_field("join_muted", true); }
    if (var0 & 4) { s.store_field("can_change_join_muted", true); }
    if (var0 & 64) { s.store_field("join_date_asc", true); }
    if (var0 & 256) { s.store_field("schedule_start_subscribed", true); }
    if (var0 & 512) { s.store_field("can_start_video", true); }
    if (var0 & 2048) { s.store_field("record_video_active", true); }
    if (var0 & 4096) { s.store_field("rtmp_stream", true); }
    if (var0 & 8192) { s.store_field("listeners_hidden", true); }
    if (var0 & 16384) { s.store_field("conference", true); }
    if (var0 & 32768) { s.store_field("creator", true); }
    if (var0 & 131072) { s.store_field("messages_enabled", true); }
    if (var0 & 262144) { s.store_field("can_change_messages_enabled", true); }
    if (var0 & 524288) { s.store_field("min", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("participants_count", participants_count_);
    if (var0 & 8) { s.store_field("title", title_); }
    if (var0 & 16) { s.store_field("stream_dc_id", stream_dc_id_); }
    if (var0 & 32) { s.store_field("record_start_date", record_start_date_); }
    if (var0 & 128) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 1024) { s.store_field("unmuted_video_count", unmuted_video_count_); }
    s.store_field("unmuted_video_limit", unmuted_video_limit_);
    s.store_field("version", version_);
    if (var0 & 65536) { s.store_field("invite_link", invite_link_); }
    if (var0 & 1048576) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    if (var0 & 2097152) { s.store_object_field("default_send_as", static_cast<const BaseObject *>(default_send_as_.get())); }
    s.store_class_end();
  }
}

groupCallParticipantVideo::groupCallParticipantVideo()
  : flags_()
  , paused_()
  , endpoint_()
  , source_groups_()
  , audio_source_()
{}

const std::int32_t groupCallParticipantVideo::ID;

object_ptr<groupCallParticipantVideo> groupCallParticipantVideo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<groupCallParticipantVideo> res = make_tl_object<groupCallParticipantVideo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->paused_ = (var0 & 1) != 0;
  res->endpoint_ = TlFetchString<string>::parse(p);
  res->source_groups_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<groupCallParticipantVideoSourceGroup>, -592373577>>, 481674261>::parse(p);
  if (var0 & 2) { res->audio_source_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void groupCallParticipantVideo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipantVideo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (paused_ << 0)));
    if (var0 & 1) { s.store_field("paused", true); }
    s.store_field("endpoint", endpoint_);
    { s.store_vector_begin("source_groups", source_groups_.size()); for (const auto &_value : source_groups_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 2) { s.store_field("audio_source", audio_source_); }
    s.store_class_end();
  }
}

inputBotInlineResult::inputBotInlineResult(int32 flags_, string const &id_, string const &type_, string const &title_, string const &description_, string const &url_, object_ptr<inputWebDocument> &&thumb_, object_ptr<inputWebDocument> &&content_, object_ptr<InputBotInlineMessage> &&send_message_)
  : flags_(flags_)
  , id_(id_)
  , type_(type_)
  , title_(title_)
  , description_(description_)
  , url_(url_)
  , thumb_(std::move(thumb_))
  , content_(std::move(content_))
  , send_message_(std::move(send_message_))
{}

const std::int32_t inputBotInlineResult::ID;

void inputBotInlineResult::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(id_, s);
  TlStoreString::store(type_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreString::store(description_, s); }
  if (var0 & 8) { TlStoreString::store(url_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreObject, -1678949555>::store(thumb_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreObject, -1678949555>::store(content_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResult::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(id_, s);
  TlStoreString::store(type_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreString::store(description_, s); }
  if (var0 & 8) { TlStoreString::store(url_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreObject, -1678949555>::store(thumb_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreObject, -1678949555>::store(content_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineResult");
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

inputBotInlineResultPhoto::inputBotInlineResultPhoto(string const &id_, string const &type_, object_ptr<InputPhoto> &&photo_, object_ptr<InputBotInlineMessage> &&send_message_)
  : id_(id_)
  , type_(type_)
  , photo_(std::move(photo_))
  , send_message_(std::move(send_message_))
{}

const std::int32_t inputBotInlineResultPhoto::ID;

void inputBotInlineResultPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(type_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResultPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(type_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResultPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineResultPhoto");
    s.store_field("id", id_);
    s.store_field("type", type_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_object_field("send_message", static_cast<const BaseObject *>(send_message_.get()));
    s.store_class_end();
  }
}

inputBotInlineResultDocument::inputBotInlineResultDocument(int32 flags_, string const &id_, string const &type_, string const &title_, string const &description_, object_ptr<InputDocument> &&document_, object_ptr<InputBotInlineMessage> &&send_message_)
  : flags_(flags_)
  , id_(id_)
  , type_(type_)
  , title_(title_)
  , description_(description_)
  , document_(std::move(document_))
  , send_message_(std::move(send_message_))
{}

const std::int32_t inputBotInlineResultDocument::ID;

void inputBotInlineResultDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(id_, s);
  TlStoreString::store(type_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreString::store(description_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResultDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(id_, s);
  TlStoreString::store(type_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreString::store(description_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResultDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineResultDocument");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    s.store_field("type", type_);
    if (var0 & 2) { s.store_field("title", title_); }
    if (var0 & 4) { s.store_field("description", description_); }
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_object_field("send_message", static_cast<const BaseObject *>(send_message_.get()));
    s.store_class_end();
  }
}

inputBotInlineResultGame::inputBotInlineResultGame(string const &id_, string const &short_name_, object_ptr<InputBotInlineMessage> &&send_message_)
  : id_(id_)
  , short_name_(short_name_)
  , send_message_(std::move(send_message_))
{}

const std::int32_t inputBotInlineResultGame::ID;

void inputBotInlineResultGame::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(short_name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResultGame::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(short_name_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(send_message_, s);
}

void inputBotInlineResultGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineResultGame");
    s.store_field("id", id_);
    s.store_field("short_name", short_name_);
    s.store_object_field("send_message", static_cast<const BaseObject *>(send_message_.get()));
    s.store_class_end();
  }
}

inputBusinessAwayMessage::inputBusinessAwayMessage(int32 flags_, bool offline_only_, int32 shortcut_id_, object_ptr<BusinessAwayMessageSchedule> &&schedule_, object_ptr<inputBusinessRecipients> &&recipients_)
  : flags_(flags_)
  , offline_only_(offline_only_)
  , shortcut_id_(shortcut_id_)
  , schedule_(std::move(schedule_))
  , recipients_(std::move(recipients_))
{}

const std::int32_t inputBusinessAwayMessage::ID;

void inputBusinessAwayMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (offline_only_ << 0)), s);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(schedule_, s);
  TlStoreBoxed<TlStoreObject, 1871393450>::store(recipients_, s);
}

void inputBusinessAwayMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (offline_only_ << 0)), s);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(schedule_, s);
  TlStoreBoxed<TlStoreObject, 1871393450>::store(recipients_, s);
}

void inputBusinessAwayMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessAwayMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (offline_only_ << 0)));
    if (var0 & 1) { s.store_field("offline_only", true); }
    s.store_field("shortcut_id", shortcut_id_);
    s.store_object_field("schedule", static_cast<const BaseObject *>(schedule_.get()));
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_class_end();
  }
}

inputDialogPeer::inputDialogPeer(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t inputDialogPeer::ID;

void inputDialogPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void inputDialogPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void inputDialogPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputDialogPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

inputDialogPeerFolder::inputDialogPeerFolder(int32 folder_id_)
  : folder_id_(folder_id_)
{}

const std::int32_t inputDialogPeerFolder::ID;

void inputDialogPeerFolder::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(folder_id_, s);
}

void inputDialogPeerFolder::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(folder_id_, s);
}

void inputDialogPeerFolder::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputDialogPeerFolder");
    s.store_field("folder_id", folder_id_);
    s.store_class_end();
  }
}

inputInvoiceMessage::inputInvoiceMessage(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t inputInvoiceMessage::ID;

void inputInvoiceMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void inputInvoiceMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void inputInvoiceMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

inputInvoiceSlug::inputInvoiceSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputInvoiceSlug::ID;

void inputInvoiceSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputInvoiceSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputInvoiceSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

inputInvoicePremiumGiftCode::inputInvoicePremiumGiftCode(object_ptr<InputStorePaymentPurpose> &&purpose_, object_ptr<premiumGiftCodeOption> &&option_)
  : purpose_(std::move(purpose_))
  , option_(std::move(option_))
{}

const std::int32_t inputInvoicePremiumGiftCode::ID;

void inputInvoicePremiumGiftCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
  TlStoreBoxed<TlStoreObject, 629052971>::store(option_, s);
}

void inputInvoicePremiumGiftCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
  TlStoreBoxed<TlStoreObject, 629052971>::store(option_, s);
}

void inputInvoicePremiumGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoicePremiumGiftCode");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_object_field("option", static_cast<const BaseObject *>(option_.get()));
    s.store_class_end();
  }
}

inputInvoiceStars::inputInvoiceStars(object_ptr<InputStorePaymentPurpose> &&purpose_)
  : purpose_(std::move(purpose_))
{}

const std::int32_t inputInvoiceStars::ID;

void inputInvoiceStars::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void inputInvoiceStars::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void inputInvoiceStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStars");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

inputInvoiceChatInviteSubscription::inputInvoiceChatInviteSubscription(string const &hash_)
  : hash_(hash_)
{}

const std::int32_t inputInvoiceChatInviteSubscription::ID;

void inputInvoiceChatInviteSubscription::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(hash_, s);
}

void inputInvoiceChatInviteSubscription::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(hash_, s);
}

void inputInvoiceChatInviteSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceChatInviteSubscription");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

inputInvoiceStarGift::inputInvoiceStarGift(int32 flags_, bool hide_name_, bool include_upgrade_, object_ptr<InputPeer> &&peer_, int64 gift_id_, object_ptr<textWithEntities> &&message_)
  : flags_(flags_)
  , hide_name_(hide_name_)
  , include_upgrade_(include_upgrade_)
  , peer_(std::move(peer_))
  , gift_id_(gift_id_)
  , message_(std::move(message_))
{}

const std::int32_t inputInvoiceStarGift::ID;

void inputInvoiceStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (hide_name_ << 0) | (include_upgrade_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(gift_id_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoiceStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (hide_name_ << 0) | (include_upgrade_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(gift_id_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoiceStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGift");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (hide_name_ << 0) | (include_upgrade_ << 2)));
    if (var0 & 1) { s.store_field("hide_name", true); }
    if (var0 & 4) { s.store_field("include_upgrade", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("gift_id", gift_id_);
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

inputInvoiceStarGiftUpgrade::inputInvoiceStarGiftUpgrade(int32 flags_, bool keep_original_details_, object_ptr<InputSavedStarGift> &&stargift_)
  : flags_(flags_)
  , keep_original_details_(keep_original_details_)
  , stargift_(std::move(stargift_))
{}

const std::int32_t inputInvoiceStarGiftUpgrade::ID;

void inputInvoiceStarGiftUpgrade::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (keep_original_details_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void inputInvoiceStarGiftUpgrade::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (keep_original_details_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void inputInvoiceStarGiftUpgrade::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGiftUpgrade");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (keep_original_details_ << 0)));
    if (var0 & 1) { s.store_field("keep_original_details", true); }
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

inputInvoiceStarGiftTransfer::inputInvoiceStarGiftTransfer(object_ptr<InputSavedStarGift> &&stargift_, object_ptr<InputPeer> &&to_id_)
  : stargift_(std::move(stargift_))
  , to_id_(std::move(to_id_))
{}

const std::int32_t inputInvoiceStarGiftTransfer::ID;

void inputInvoiceStarGiftTransfer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_id_, s);
}

void inputInvoiceStarGiftTransfer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_id_, s);
}

void inputInvoiceStarGiftTransfer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGiftTransfer");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_object_field("to_id", static_cast<const BaseObject *>(to_id_.get()));
    s.store_class_end();
  }
}

inputInvoicePremiumGiftStars::inputInvoicePremiumGiftStars(int32 flags_, object_ptr<InputUser> &&user_id_, int32 months_, object_ptr<textWithEntities> &&message_)
  : flags_(flags_)
  , user_id_(std::move(user_id_))
  , months_(months_)
  , message_(std::move(message_))
{}

const std::int32_t inputInvoicePremiumGiftStars::ID;

void inputInvoicePremiumGiftStars::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(months_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoicePremiumGiftStars::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(months_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoicePremiumGiftStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoicePremiumGiftStars");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("months", months_);
    if (var0 & 1) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

inputInvoiceBusinessBotTransferStars::inputInvoiceBusinessBotTransferStars(object_ptr<InputUser> &&bot_, int64 stars_)
  : bot_(std::move(bot_))
  , stars_(stars_)
{}

const std::int32_t inputInvoiceBusinessBotTransferStars::ID;

void inputInvoiceBusinessBotTransferStars::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(stars_, s);
}

void inputInvoiceBusinessBotTransferStars::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(stars_, s);
}

void inputInvoiceBusinessBotTransferStars::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceBusinessBotTransferStars");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("stars", stars_);
    s.store_class_end();
  }
}

inputInvoiceStarGiftResale::inputInvoiceStarGiftResale(int32 flags_, bool ton_, string const &slug_, object_ptr<InputPeer> &&to_id_)
  : flags_(flags_)
  , ton_(ton_)
  , slug_(slug_)
  , to_id_(std::move(to_id_))
{}

const std::int32_t inputInvoiceStarGiftResale::ID;

void inputInvoiceStarGiftResale::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreString::store(slug_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_id_, s);
}

void inputInvoiceStarGiftResale::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreString::store(slug_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_id_, s);
}

void inputInvoiceStarGiftResale::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGiftResale");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (ton_ << 0)));
    if (var0 & 1) { s.store_field("ton", true); }
    s.store_field("slug", slug_);
    s.store_object_field("to_id", static_cast<const BaseObject *>(to_id_.get()));
    s.store_class_end();
  }
}

inputInvoiceStarGiftPrepaidUpgrade::inputInvoiceStarGiftPrepaidUpgrade(object_ptr<InputPeer> &&peer_, string const &hash_)
  : peer_(std::move(peer_))
  , hash_(hash_)
{}

const std::int32_t inputInvoiceStarGiftPrepaidUpgrade::ID;

void inputInvoiceStarGiftPrepaidUpgrade::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(hash_, s);
}

void inputInvoiceStarGiftPrepaidUpgrade::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(hash_, s);
}

void inputInvoiceStarGiftPrepaidUpgrade::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGiftPrepaidUpgrade");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

inputInvoicePremiumAuthCode::inputInvoicePremiumAuthCode(object_ptr<InputStorePaymentPurpose> &&purpose_)
  : purpose_(std::move(purpose_))
{}

const std::int32_t inputInvoicePremiumAuthCode::ID;

void inputInvoicePremiumAuthCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void inputInvoicePremiumAuthCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void inputInvoicePremiumAuthCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoicePremiumAuthCode");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

inputInvoiceStarGiftDropOriginalDetails::inputInvoiceStarGiftDropOriginalDetails(object_ptr<InputSavedStarGift> &&stargift_)
  : stargift_(std::move(stargift_))
{}

const std::int32_t inputInvoiceStarGiftDropOriginalDetails::ID;

void inputInvoiceStarGiftDropOriginalDetails::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void inputInvoiceStarGiftDropOriginalDetails::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void inputInvoiceStarGiftDropOriginalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGiftDropOriginalDetails");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

inputInvoiceStarGiftAuctionBid::inputInvoiceStarGiftAuctionBid(int32 flags_, bool hide_name_, bool update_bid_, object_ptr<InputPeer> &&peer_, int64 gift_id_, int64 bid_amount_, object_ptr<textWithEntities> &&message_)
  : flags_(flags_)
  , hide_name_(hide_name_)
  , update_bid_(update_bid_)
  , peer_(std::move(peer_))
  , gift_id_(gift_id_)
  , bid_amount_(bid_amount_)
  , message_(std::move(message_))
{}

const std::int32_t inputInvoiceStarGiftAuctionBid::ID;

void inputInvoiceStarGiftAuctionBid::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (hide_name_ << 0) | (update_bid_ << 2)), s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBinary::store(gift_id_, s);
  TlStoreBinary::store(bid_amount_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoiceStarGiftAuctionBid::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (hide_name_ << 0) | (update_bid_ << 2)), s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreBinary::store(gift_id_, s);
  TlStoreBinary::store(bid_amount_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(message_, s); }
}

void inputInvoiceStarGiftAuctionBid::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputInvoiceStarGiftAuctionBid");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (hide_name_ << 0) | (update_bid_ << 2)));
    if (var0 & 1) { s.store_field("hide_name", true); }
    if (var0 & 4) { s.store_field("update_bid", true); }
    if (var0 & 8) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_field("gift_id", gift_id_);
    s.store_field("bid_amount", bid_amount_);
    if (var0 & 2) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

inputMessageReadMetric::inputMessageReadMetric(int32 msg_id_, int64 view_id_, int32 time_in_view_ms_, int32 active_time_in_view_ms_, int32 height_to_viewport_ratio_permille_, int32 seen_range_ratio_permille_)
  : msg_id_(msg_id_)
  , view_id_(view_id_)
  , time_in_view_ms_(time_in_view_ms_)
  , active_time_in_view_ms_(active_time_in_view_ms_)
  , height_to_viewport_ratio_permille_(height_to_viewport_ratio_permille_)
  , seen_range_ratio_permille_(seen_range_ratio_permille_)
{}

const std::int32_t inputMessageReadMetric::ID;

void inputMessageReadMetric::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(view_id_, s);
  TlStoreBinary::store(time_in_view_ms_, s);
  TlStoreBinary::store(active_time_in_view_ms_, s);
  TlStoreBinary::store(height_to_viewport_ratio_permille_, s);
  TlStoreBinary::store(seen_range_ratio_permille_, s);
}

void inputMessageReadMetric::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(view_id_, s);
  TlStoreBinary::store(time_in_view_ms_, s);
  TlStoreBinary::store(active_time_in_view_ms_, s);
  TlStoreBinary::store(height_to_viewport_ratio_permille_, s);
  TlStoreBinary::store(seen_range_ratio_permille_, s);
}

void inputMessageReadMetric::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageReadMetric");
    s.store_field("msg_id", msg_id_);
    s.store_field("view_id", view_id_);
    s.store_field("time_in_view_ms", time_in_view_ms_);
    s.store_field("active_time_in_view_ms", active_time_in_view_ms_);
    s.store_field("height_to_viewport_ratio_permille", height_to_viewport_ratio_permille_);
    s.store_field("seen_range_ratio_permille", seen_range_ratio_permille_);
    s.store_class_end();
  }
}

messageReactions::messageReactions()
  : flags_()
  , min_()
  , can_see_list_()
  , reactions_as_tags_()
  , results_()
  , recent_reactions_()
  , top_reactors_()
{}

const std::int32_t messageReactions::ID;

object_ptr<messageReactions> messageReactions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageReactions> res = make_tl_object<messageReactions>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->min_ = (var0 & 1) != 0;
  res->can_see_list_ = (var0 & 4) != 0;
  res->reactions_as_tags_ = (var0 & 8) != 0;
  res->results_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<reactionCount>, -1546531968>>, 481674261>::parse(p);
  if (var0 & 2) { res->recent_reactions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messagePeerReaction>, -1938180548>>, 481674261>::parse(p); }
  if (var0 & 16) { res->top_reactors_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messageReactor>, 1269016922>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messageReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReactions");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (min_ << 0) | (can_see_list_ << 2) | (reactions_as_tags_ << 3)));
    if (var0 & 1) { s.store_field("min", true); }
    if (var0 & 4) { s.store_field("can_see_list", true); }
    if (var0 & 8) { s.store_field("reactions_as_tags", true); }
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 2) { { s.store_vector_begin("recent_reactions", recent_reactions_.size()); for (const auto &_value : recent_reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { { s.store_vector_begin("top_reactors", top_reactors_.size()); for (const auto &_value : top_reactors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

messageReplies::messageReplies()
  : flags_()
  , comments_()
  , replies_()
  , replies_pts_()
  , recent_repliers_()
  , channel_id_()
  , max_id_()
  , read_max_id_()
{}

const std::int32_t messageReplies::ID;

object_ptr<messageReplies> messageReplies::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageReplies> res = make_tl_object<messageReplies>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->comments_ = (var0 & 1) != 0;
  res->replies_ = TlFetchInt::parse(p);
  res->replies_pts_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->recent_repliers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p); }
  if (var0 & 1) { res->channel_id_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->max_id_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->read_max_id_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messageReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReplies");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (comments_ << 0)));
    if (var0 & 1) { s.store_field("comments", true); }
    s.store_field("replies", replies_);
    s.store_field("replies_pts", replies_pts_);
    if (var0 & 2) { { s.store_vector_begin("recent_repliers", recent_repliers_.size()); for (const auto &_value : recent_repliers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1) { s.store_field("channel_id", channel_id_); }
    if (var0 & 4) { s.store_field("max_id", max_id_); }
    if (var0 & 8) { s.store_field("read_max_id", read_max_id_); }
    s.store_class_end();
  }
}

const std::int32_t messageReportOption::ID;

object_ptr<messageReportOption> messageReportOption::fetch(TlBufferParser &p) {
  return make_tl_object<messageReportOption>(p);
}

messageReportOption::messageReportOption(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
  , option_(TlFetchBytes<bytes>::parse(p))
{}

void messageReportOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageReportOption");
    s.store_field("text", text_);
    s.store_bytes_field("option", option_);
    s.store_class_end();
  }
}

const std::int32_t nearestDc::ID;

object_ptr<nearestDc> nearestDc::fetch(TlBufferParser &p) {
  return make_tl_object<nearestDc>(p);
}

nearestDc::nearestDc(TlBufferParser &p)
  : country_(TlFetchString<string>::parse(p))
  , this_dc_(TlFetchInt::parse(p))
  , nearest_dc_(TlFetchInt::parse(p))
{}

void nearestDc::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "nearestDc");
    s.store_field("country", country_);
    s.store_field("this_dc", this_dc_);
    s.store_field("nearest_dc", nearest_dc_);
    s.store_class_end();
  }
}

object_ptr<NotificationSound> NotificationSound::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case notificationSoundDefault::ID:
      return notificationSoundDefault::fetch(p);
    case notificationSoundNone::ID:
      return notificationSoundNone::fetch(p);
    case notificationSoundLocal::ID:
      return notificationSoundLocal::fetch(p);
    case notificationSoundRingtone::ID:
      return notificationSoundRingtone::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t notificationSoundDefault::ID;

object_ptr<NotificationSound> notificationSoundDefault::fetch(TlBufferParser &p) {
  return make_tl_object<notificationSoundDefault>();
}

void notificationSoundDefault::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void notificationSoundDefault::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void notificationSoundDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSoundDefault");
    s.store_class_end();
  }
}

const std::int32_t notificationSoundNone::ID;

object_ptr<NotificationSound> notificationSoundNone::fetch(TlBufferParser &p) {
  return make_tl_object<notificationSoundNone>();
}

void notificationSoundNone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void notificationSoundNone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void notificationSoundNone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSoundNone");
    s.store_class_end();
  }
}

notificationSoundLocal::notificationSoundLocal(string const &title_, string const &data_)
  : title_(title_)
  , data_(data_)
{}

const std::int32_t notificationSoundLocal::ID;

object_ptr<NotificationSound> notificationSoundLocal::fetch(TlBufferParser &p) {
  return make_tl_object<notificationSoundLocal>(p);
}

notificationSoundLocal::notificationSoundLocal(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , data_(TlFetchString<string>::parse(p))
{}

void notificationSoundLocal::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(title_, s);
  TlStoreString::store(data_, s);
}

void notificationSoundLocal::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(title_, s);
  TlStoreString::store(data_, s);
}

void notificationSoundLocal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSoundLocal");
    s.store_field("title", title_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

notificationSoundRingtone::notificationSoundRingtone(int64 id_)
  : id_(id_)
{}

const std::int32_t notificationSoundRingtone::ID;

object_ptr<NotificationSound> notificationSoundRingtone::fetch(TlBufferParser &p) {
  return make_tl_object<notificationSoundRingtone>(p);
}

notificationSoundRingtone::notificationSoundRingtone(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void notificationSoundRingtone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void notificationSoundRingtone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void notificationSoundRingtone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notificationSoundRingtone");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

pageRelatedArticle::pageRelatedArticle()
  : flags_()
  , url_()
  , webpage_id_()
  , title_()
  , description_()
  , photo_id_()
  , author_()
  , published_date_()
{}

pageRelatedArticle::pageRelatedArticle(int32 flags_, string const &url_, int64 webpage_id_, string const &title_, string const &description_, int64 photo_id_, string const &author_, int32 published_date_)
  : flags_(flags_)
  , url_(url_)
  , webpage_id_(webpage_id_)
  , title_(title_)
  , description_(description_)
  , photo_id_(photo_id_)
  , author_(author_)
  , published_date_(published_date_)
{}

const std::int32_t pageRelatedArticle::ID;

object_ptr<pageRelatedArticle> pageRelatedArticle::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pageRelatedArticle> res = make_tl_object<pageRelatedArticle>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->url_ = TlFetchString<string>::parse(p);
  res->webpage_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->description_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->photo_id_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->author_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->published_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void pageRelatedArticle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(webpage_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreString::store(description_, s); }
  if (var0 & 4) { TlStoreBinary::store(photo_id_, s); }
  if (var0 & 8) { TlStoreString::store(author_, s); }
  if (var0 & 16) { TlStoreBinary::store(published_date_, s); }
}

void pageRelatedArticle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(webpage_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreString::store(description_, s); }
  if (var0 & 4) { TlStoreBinary::store(photo_id_, s); }
  if (var0 & 8) { TlStoreString::store(author_, s); }
  if (var0 & 16) { TlStoreBinary::store(published_date_, s); }
}

void pageRelatedArticle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageRelatedArticle");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("url", url_);
    s.store_field("webpage_id", webpage_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("description", description_); }
    if (var0 & 4) { s.store_field("photo_id", photo_id_); }
    if (var0 & 8) { s.store_field("author", author_); }
    if (var0 & 16) { s.store_field("published_date", published_date_); }
    s.store_class_end();
  }
}

pageTableRow::pageTableRow(array<object_ptr<pageTableCell>> &&cells_)
  : cells_(std::move(cells_))
{}

const std::int32_t pageTableRow::ID;

object_ptr<pageTableRow> pageTableRow::fetch(TlBufferParser &p) {
  return make_tl_object<pageTableRow>(p);
}

pageTableRow::pageTableRow(TlBufferParser &p)
  : cells_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<pageTableCell>, 878078826>>, 481674261>::parse(p))
{}

void pageTableRow::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 878078826>>, 481674261>::store(cells_, s);
}

void pageTableRow::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 878078826>>, 481674261>::store(cells_, s);
}

void pageTableRow::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageTableRow");
    { s.store_vector_begin("cells", cells_.size()); for (const auto &_value : cells_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<PrepaidGiveaway> PrepaidGiveaway::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case prepaidGiveaway::ID:
      return prepaidGiveaway::fetch(p);
    case prepaidStarsGiveaway::ID:
      return prepaidStarsGiveaway::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t prepaidGiveaway::ID;

object_ptr<PrepaidGiveaway> prepaidGiveaway::fetch(TlBufferParser &p) {
  return make_tl_object<prepaidGiveaway>(p);
}

prepaidGiveaway::prepaidGiveaway(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , months_(TlFetchInt::parse(p))
  , quantity_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void prepaidGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "prepaidGiveaway");
    s.store_field("id", id_);
    s.store_field("months", months_);
    s.store_field("quantity", quantity_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t prepaidStarsGiveaway::ID;

object_ptr<PrepaidGiveaway> prepaidStarsGiveaway::fetch(TlBufferParser &p) {
  return make_tl_object<prepaidStarsGiveaway>(p);
}

prepaidStarsGiveaway::prepaidStarsGiveaway(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , stars_(TlFetchLong::parse(p))
  , quantity_(TlFetchInt::parse(p))
  , boosts_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void prepaidStarsGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "prepaidStarsGiveaway");
    s.store_field("id", id_);
    s.store_field("stars", stars_);
    s.store_field("quantity", quantity_);
    s.store_field("boosts", boosts_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t readParticipantDate::ID;

object_ptr<readParticipantDate> readParticipantDate::fetch(TlBufferParser &p) {
  return make_tl_object<readParticipantDate>(p);
}

readParticipantDate::readParticipantDate(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void readParticipantDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "readParticipantDate");
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

object_ptr<RequestPeerType> RequestPeerType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case requestPeerTypeUser::ID:
      return requestPeerTypeUser::fetch(p);
    case requestPeerTypeChat::ID:
      return requestPeerTypeChat::fetch(p);
    case requestPeerTypeBroadcast::ID:
      return requestPeerTypeBroadcast::fetch(p);
    case requestPeerTypeCreateBot::ID:
      return requestPeerTypeCreateBot::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

requestPeerTypeUser::requestPeerTypeUser()
  : flags_()
  , bot_()
  , premium_()
{}

requestPeerTypeUser::requestPeerTypeUser(int32 flags_, bool bot_, bool premium_)
  : flags_(flags_)
  , bot_(bot_)
  , premium_(premium_)
{}

const std::int32_t requestPeerTypeUser::ID;

object_ptr<RequestPeerType> requestPeerTypeUser::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestPeerTypeUser> res = make_tl_object<requestPeerTypeUser>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->bot_ = TlFetchBool::parse(p); }
  if (var0 & 2) { res->premium_ = TlFetchBool::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestPeerTypeUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBool::store(bot_, s); }
  if (var0 & 2) { TlStoreBool::store(premium_, s); }
}

void requestPeerTypeUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBool::store(bot_, s); }
  if (var0 & 2) { TlStoreBool::store(premium_, s); }
}

void requestPeerTypeUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestPeerTypeUser");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("bot", bot_); }
    if (var0 & 2) { s.store_field("premium", premium_); }
    s.store_class_end();
  }
}

requestPeerTypeChat::requestPeerTypeChat()
  : flags_()
  , creator_()
  , bot_participant_()
  , has_username_()
  , forum_()
  , user_admin_rights_()
  , bot_admin_rights_()
{}

requestPeerTypeChat::requestPeerTypeChat(int32 flags_, bool creator_, bool bot_participant_, bool has_username_, bool forum_, object_ptr<chatAdminRights> &&user_admin_rights_, object_ptr<chatAdminRights> &&bot_admin_rights_)
  : flags_(flags_)
  , creator_(creator_)
  , bot_participant_(bot_participant_)
  , has_username_(has_username_)
  , forum_(forum_)
  , user_admin_rights_(std::move(user_admin_rights_))
  , bot_admin_rights_(std::move(bot_admin_rights_))
{}

const std::int32_t requestPeerTypeChat::ID;

object_ptr<RequestPeerType> requestPeerTypeChat::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestPeerTypeChat> res = make_tl_object<requestPeerTypeChat>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  res->bot_participant_ = (var0 & 32) != 0;
  if (var0 & 8) { res->has_username_ = TlFetchBool::parse(p); }
  if (var0 & 16) { res->forum_ = TlFetchBool::parse(p); }
  if (var0 & 2) { res->user_admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 4) { res->bot_admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestPeerTypeChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (bot_participant_ << 5)), s);
  if (var0 & 8) { TlStoreBool::store(has_username_, s); }
  if (var0 & 16) { TlStoreBool::store(forum_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1605510357>::store(user_admin_rights_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1605510357>::store(bot_admin_rights_, s); }
}

void requestPeerTypeChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (bot_participant_ << 5)), s);
  if (var0 & 8) { TlStoreBool::store(has_username_, s); }
  if (var0 & 16) { TlStoreBool::store(forum_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1605510357>::store(user_admin_rights_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1605510357>::store(bot_admin_rights_, s); }
}

void requestPeerTypeChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestPeerTypeChat");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | (bot_participant_ << 5)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 32) { s.store_field("bot_participant", true); }
    if (var0 & 8) { s.store_field("has_username", has_username_); }
    if (var0 & 16) { s.store_field("forum", forum_); }
    if (var0 & 2) { s.store_object_field("user_admin_rights", static_cast<const BaseObject *>(user_admin_rights_.get())); }
    if (var0 & 4) { s.store_object_field("bot_admin_rights", static_cast<const BaseObject *>(bot_admin_rights_.get())); }
    s.store_class_end();
  }
}

requestPeerTypeBroadcast::requestPeerTypeBroadcast()
  : flags_()
  , creator_()
  , has_username_()
  , user_admin_rights_()
  , bot_admin_rights_()
{}

requestPeerTypeBroadcast::requestPeerTypeBroadcast(int32 flags_, bool creator_, bool has_username_, object_ptr<chatAdminRights> &&user_admin_rights_, object_ptr<chatAdminRights> &&bot_admin_rights_)
  : flags_(flags_)
  , creator_(creator_)
  , has_username_(has_username_)
  , user_admin_rights_(std::move(user_admin_rights_))
  , bot_admin_rights_(std::move(bot_admin_rights_))
{}

const std::int32_t requestPeerTypeBroadcast::ID;

object_ptr<RequestPeerType> requestPeerTypeBroadcast::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestPeerTypeBroadcast> res = make_tl_object<requestPeerTypeBroadcast>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  if (var0 & 8) { res->has_username_ = TlFetchBool::parse(p); }
  if (var0 & 2) { res->user_admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 4) { res->bot_admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestPeerTypeBroadcast::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0)), s);
  if (var0 & 8) { TlStoreBool::store(has_username_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1605510357>::store(user_admin_rights_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1605510357>::store(bot_admin_rights_, s); }
}

void requestPeerTypeBroadcast::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0)), s);
  if (var0 & 8) { TlStoreBool::store(has_username_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1605510357>::store(user_admin_rights_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 1605510357>::store(bot_admin_rights_, s); }
}

void requestPeerTypeBroadcast::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestPeerTypeBroadcast");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (creator_ << 0)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 8) { s.store_field("has_username", has_username_); }
    if (var0 & 2) { s.store_object_field("user_admin_rights", static_cast<const BaseObject *>(user_admin_rights_.get())); }
    if (var0 & 4) { s.store_object_field("bot_admin_rights", static_cast<const BaseObject *>(bot_admin_rights_.get())); }
    s.store_class_end();
  }
}

requestPeerTypeCreateBot::requestPeerTypeCreateBot()
  : flags_()
  , bot_managed_()
  , suggested_name_()
  , suggested_username_()
{}

requestPeerTypeCreateBot::requestPeerTypeCreateBot(int32 flags_, bool bot_managed_, string const &suggested_name_, string const &suggested_username_)
  : flags_(flags_)
  , bot_managed_(bot_managed_)
  , suggested_name_(suggested_name_)
  , suggested_username_(suggested_username_)
{}

const std::int32_t requestPeerTypeCreateBot::ID;

object_ptr<RequestPeerType> requestPeerTypeCreateBot::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestPeerTypeCreateBot> res = make_tl_object<requestPeerTypeCreateBot>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bot_managed_ = (var0 & 1) != 0;
  if (var0 & 2) { res->suggested_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->suggested_username_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestPeerTypeCreateBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bot_managed_ << 0)), s);
  if (var0 & 2) { TlStoreString::store(suggested_name_, s); }
  if (var0 & 4) { TlStoreString::store(suggested_username_, s); }
}

void requestPeerTypeCreateBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bot_managed_ << 0)), s);
  if (var0 & 2) { TlStoreString::store(suggested_name_, s); }
  if (var0 & 4) { TlStoreString::store(suggested_username_, s); }
}

void requestPeerTypeCreateBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestPeerTypeCreateBot");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (bot_managed_ << 0)));
    if (var0 & 1) { s.store_field("bot_managed", true); }
    if (var0 & 2) { s.store_field("suggested_name", suggested_name_); }
    if (var0 & 4) { s.store_field("suggested_username", suggested_username_); }
    s.store_class_end();
  }
}

savedReactionTag::savedReactionTag()
  : flags_()
  , reaction_()
  , title_()
  , count_()
{}

const std::int32_t savedReactionTag::ID;

object_ptr<savedReactionTag> savedReactionTag::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<savedReactionTag> res = make_tl_object<savedReactionTag>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->reaction_ = TlFetchObject<Reaction>::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  res->count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void savedReactionTag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "savedReactionTag");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    if (var0 & 1) { s.store_field("title", title_); }
    s.store_field("count", count_);
    s.store_class_end();
  }
}

object_ptr<SecureRequiredType> SecureRequiredType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case secureRequiredType::ID:
      return secureRequiredType::fetch(p);
    case secureRequiredTypeOneOf::ID:
      return secureRequiredTypeOneOf::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

secureRequiredType::secureRequiredType()
  : flags_()
  , native_names_()
  , selfie_required_()
  , translation_required_()
  , type_()
{}

const std::int32_t secureRequiredType::ID;

object_ptr<SecureRequiredType> secureRequiredType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<secureRequiredType> res = make_tl_object<secureRequiredType>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->native_names_ = (var0 & 1) != 0;
  res->selfie_required_ = (var0 & 2) != 0;
  res->translation_required_ = (var0 & 4) != 0;
  res->type_ = TlFetchObject<SecureValueType>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void secureRequiredType::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureRequiredType");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (native_names_ << 0) | (selfie_required_ << 1) | (translation_required_ << 2)));
    if (var0 & 1) { s.store_field("native_names", true); }
    if (var0 & 2) { s.store_field("selfie_required", true); }
    if (var0 & 4) { s.store_field("translation_required", true); }
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_class_end();
  }
}

const std::int32_t secureRequiredTypeOneOf::ID;

object_ptr<SecureRequiredType> secureRequiredTypeOneOf::fetch(TlBufferParser &p) {
  return make_tl_object<secureRequiredTypeOneOf>(p);
}

secureRequiredTypeOneOf::secureRequiredTypeOneOf(TlBufferParser &p)
  : types_(TlFetchBoxed<TlFetchVector<TlFetchObject<SecureRequiredType>>, 481674261>::parse(p))
{}

void secureRequiredTypeOneOf::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureRequiredTypeOneOf");
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<SecureValueError> SecureValueError::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case secureValueErrorData::ID:
      return secureValueErrorData::fetch(p);
    case secureValueErrorFrontSide::ID:
      return secureValueErrorFrontSide::fetch(p);
    case secureValueErrorReverseSide::ID:
      return secureValueErrorReverseSide::fetch(p);
    case secureValueErrorSelfie::ID:
      return secureValueErrorSelfie::fetch(p);
    case secureValueErrorFile::ID:
      return secureValueErrorFile::fetch(p);
    case secureValueErrorFiles::ID:
      return secureValueErrorFiles::fetch(p);
    case secureValueError::ID:
      return secureValueError::fetch(p);
    case secureValueErrorTranslationFile::ID:
      return secureValueErrorTranslationFile::fetch(p);
    case secureValueErrorTranslationFiles::ID:
      return secureValueErrorTranslationFiles::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

secureValueErrorData::secureValueErrorData(object_ptr<SecureValueType> &&type_, bytes &&data_hash_, string const &field_, string const &text_)
  : type_(std::move(type_))
  , data_hash_(std::move(data_hash_))
  , field_(field_)
  , text_(text_)
{}

const std::int32_t secureValueErrorData::ID;

object_ptr<SecureValueError> secureValueErrorData::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorData>(p);
}

secureValueErrorData::secureValueErrorData(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , data_hash_(TlFetchBytes<bytes>::parse(p))
  , field_(TlFetchString<string>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(data_hash_, s);
  TlStoreString::store(field_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(data_hash_, s);
  TlStoreString::store(field_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorData");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("data_hash", data_hash_);
    s.store_field("field", field_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorFrontSide::secureValueErrorFrontSide(object_ptr<SecureValueType> &&type_, bytes &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorFrontSide::ID;

object_ptr<SecureValueError> secureValueErrorFrontSide::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorFrontSide>(p);
}

secureValueErrorFrontSide::secureValueErrorFrontSide(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBytes<bytes>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorFrontSide::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorFrontSide::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorFrontSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorFrontSide");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("file_hash", file_hash_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorReverseSide::secureValueErrorReverseSide(object_ptr<SecureValueType> &&type_, bytes &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorReverseSide::ID;

object_ptr<SecureValueError> secureValueErrorReverseSide::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorReverseSide>(p);
}

secureValueErrorReverseSide::secureValueErrorReverseSide(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBytes<bytes>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorReverseSide::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorReverseSide::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorReverseSide::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorReverseSide");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("file_hash", file_hash_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorSelfie::secureValueErrorSelfie(object_ptr<SecureValueType> &&type_, bytes &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorSelfie::ID;

object_ptr<SecureValueError> secureValueErrorSelfie::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorSelfie>(p);
}

secureValueErrorSelfie::secureValueErrorSelfie(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBytes<bytes>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorSelfie::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorSelfie::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorSelfie::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorSelfie");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("file_hash", file_hash_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorFile::secureValueErrorFile(object_ptr<SecureValueType> &&type_, bytes &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorFile::ID;

object_ptr<SecureValueError> secureValueErrorFile::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorFile>(p);
}

secureValueErrorFile::secureValueErrorFile(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBytes<bytes>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorFile");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("file_hash", file_hash_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorFiles::secureValueErrorFiles(object_ptr<SecureValueType> &&type_, array<bytes> &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorFiles::ID;

object_ptr<SecureValueError> secureValueErrorFiles::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorFiles>(p);
}

secureValueErrorFiles::secureValueErrorFiles(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBoxed<TlFetchVector<TlFetchBytes<bytes>>, 481674261>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorFiles::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorFiles::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorFiles");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    { s.store_vector_begin("file_hash", file_hash_.size()); for (const auto &_value : file_hash_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueError::secureValueError(object_ptr<SecureValueType> &&type_, bytes &&hash_, string const &text_)
  : type_(std::move(type_))
  , hash_(std::move(hash_))
  , text_(text_)
{}

const std::int32_t secureValueError::ID;

object_ptr<SecureValueError> secureValueError::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueError>(p);
}

secureValueError::secureValueError(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , hash_(TlFetchBytes<bytes>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueError::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueError::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueError::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueError");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("hash", hash_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorTranslationFile::secureValueErrorTranslationFile(object_ptr<SecureValueType> &&type_, bytes &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorTranslationFile::ID;

object_ptr<SecureValueError> secureValueErrorTranslationFile::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorTranslationFile>(p);
}

secureValueErrorTranslationFile::secureValueErrorTranslationFile(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBytes<bytes>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorTranslationFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorTranslationFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorTranslationFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorTranslationFile");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("file_hash", file_hash_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

secureValueErrorTranslationFiles::secureValueErrorTranslationFiles(object_ptr<SecureValueType> &&type_, array<bytes> &&file_hash_, string const &text_)
  : type_(std::move(type_))
  , file_hash_(std::move(file_hash_))
  , text_(text_)
{}

const std::int32_t secureValueErrorTranslationFiles::ID;

object_ptr<SecureValueError> secureValueErrorTranslationFiles::fetch(TlBufferParser &p) {
  return make_tl_object<secureValueErrorTranslationFiles>(p);
}

secureValueErrorTranslationFiles::secureValueErrorTranslationFiles(TlBufferParser &p)
  : type_(TlFetchObject<SecureValueType>::parse(p))
  , file_hash_(TlFetchBoxed<TlFetchVector<TlFetchBytes<bytes>>, 481674261>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void secureValueErrorTranslationFiles::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorTranslationFiles::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(file_hash_, s);
  TlStoreString::store(text_, s);
}

void secureValueErrorTranslationFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueErrorTranslationFiles");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    { s.store_vector_begin("file_hash", file_hash_.size()); for (const auto &_value : file_hash_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_field("text", text_);
    s.store_class_end();
  }
}

starGiftAuctionUserState::starGiftAuctionUserState()
  : flags_()
  , returned_()
  , bid_amount_()
  , bid_date_()
  , min_bid_amount_()
  , bid_peer_()
  , acquired_count_()
{}

const std::int32_t starGiftAuctionUserState::ID;

object_ptr<starGiftAuctionUserState> starGiftAuctionUserState::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftAuctionUserState> res = make_tl_object<starGiftAuctionUserState>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->returned_ = (var0 & 2) != 0;
  if (var0 & 1) { res->bid_amount_ = TlFetchLong::parse(p); }
  if (var0 & 1) { res->bid_date_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->min_bid_amount_ = TlFetchLong::parse(p); }
  if (var0 & 1) { res->bid_peer_ = TlFetchObject<Peer>::parse(p); }
  res->acquired_count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starGiftAuctionUserState::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAuctionUserState");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (returned_ << 1)));
    if (var0 & 2) { s.store_field("returned", true); }
    if (var0 & 1) { s.store_field("bid_amount", bid_amount_); }
    if (var0 & 1) { s.store_field("bid_date", bid_date_); }
    if (var0 & 1) { s.store_field("min_bid_amount", min_bid_amount_); }
    if (var0 & 1) { s.store_object_field("bid_peer", static_cast<const BaseObject *>(bid_peer_.get())); }
    s.store_field("acquired_count", acquired_count_);
    s.store_class_end();
  }
}

starsSubscriptionPricing::starsSubscriptionPricing(int32 period_, int64 amount_)
  : period_(period_)
  , amount_(amount_)
{}

const std::int32_t starsSubscriptionPricing::ID;

object_ptr<starsSubscriptionPricing> starsSubscriptionPricing::fetch(TlBufferParser &p) {
  return make_tl_object<starsSubscriptionPricing>(p);
}

starsSubscriptionPricing::starsSubscriptionPricing(TlBufferParser &p)
  : period_(TlFetchInt::parse(p))
  , amount_(TlFetchLong::parse(p))
{}

void starsSubscriptionPricing::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(period_, s);
  TlStoreBinary::store(amount_, s);
}

void starsSubscriptionPricing::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(period_, s);
  TlStoreBinary::store(amount_, s);
}

void starsSubscriptionPricing::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsSubscriptionPricing");
    s.store_field("period", period_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

starsTopupOption::starsTopupOption()
  : flags_()
  , extended_()
  , stars_()
  , store_product_()
  , currency_()
  , amount_()
{}

const std::int32_t starsTopupOption::ID;

object_ptr<starsTopupOption> starsTopupOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsTopupOption> res = make_tl_object<starsTopupOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->extended_ = (var0 & 2) != 0;
  res->stars_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->store_product_ = TlFetchString<string>::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsTopupOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsTopupOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (extended_ << 1)));
    if (var0 & 2) { s.store_field("extended", true); }
    s.store_field("stars", stars_);
    if (var0 & 1) { s.store_field("store_product", store_product_); }
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

const std::int32_t statsGroupTopPoster::ID;

object_ptr<statsGroupTopPoster> statsGroupTopPoster::fetch(TlBufferParser &p) {
  return make_tl_object<statsGroupTopPoster>(p);
}

statsGroupTopPoster::statsGroupTopPoster(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , messages_(TlFetchInt::parse(p))
  , avg_chars_(TlFetchInt::parse(p))
{}

void statsGroupTopPoster::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsGroupTopPoster");
    s.store_field("user_id", user_id_);
    s.store_field("messages", messages_);
    s.store_field("avg_chars", avg_chars_);
    s.store_class_end();
  }
}

storyAlbum::storyAlbum()
  : flags_()
  , album_id_()
  , title_()
  , icon_photo_()
  , icon_video_()
{}

const std::int32_t storyAlbum::ID;

object_ptr<storyAlbum> storyAlbum::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyAlbum> res = make_tl_object<storyAlbum>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->album_id_ = TlFetchInt::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->icon_photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 2) { res->icon_video_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void storyAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyAlbum");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("album_id", album_id_);
    s.store_field("title", title_);
    if (var0 & 1) { s.store_object_field("icon_photo", static_cast<const BaseObject *>(icon_photo_.get())); }
    if (var0 & 2) { s.store_object_field("icon_video", static_cast<const BaseObject *>(icon_video_.get())); }
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryPeers::ID;

object_ptr<topPeerCategoryPeers> topPeerCategoryPeers::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryPeers>(p);
}

topPeerCategoryPeers::topPeerCategoryPeers(TlBufferParser &p)
  : category_(TlFetchObject<TopPeerCategory>::parse(p))
  , count_(TlFetchInt::parse(p))
  , peers_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<topPeer>, -305282981>>, 481674261>::parse(p))
{}

void topPeerCategoryPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryPeers");
    s.store_object_field("category", static_cast<const BaseObject *>(category_.get()));
    s.store_field("count", count_);
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<UrlAuthResult> UrlAuthResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case urlAuthResultRequest::ID:
      return urlAuthResultRequest::fetch(p);
    case urlAuthResultAccepted::ID:
      return urlAuthResultAccepted::fetch(p);
    case urlAuthResultDefault::ID:
      return urlAuthResultDefault::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

urlAuthResultRequest::urlAuthResultRequest()
  : flags_()
  , request_write_access_()
  , request_phone_number_()
  , match_codes_first_()
  , is_app_()
  , bot_()
  , domain_()
  , browser_()
  , platform_()
  , ip_()
  , region_()
  , match_codes_()
  , user_id_hint_()
  , verified_app_name_()
{}

const std::int32_t urlAuthResultRequest::ID;

object_ptr<UrlAuthResult> urlAuthResultRequest::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<urlAuthResultRequest> res = make_tl_object<urlAuthResultRequest>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->request_write_access_ = (var0 & 1) != 0;
  res->request_phone_number_ = (var0 & 2) != 0;
  res->match_codes_first_ = (var0 & 32) != 0;
  res->is_app_ = (var0 & 64) != 0;
  res->bot_ = TlFetchObject<User>::parse(p);
  res->domain_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->browser_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->platform_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->ip_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->region_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->match_codes_ = TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p); }
  if (var0 & 16) { res->user_id_hint_ = TlFetchLong::parse(p); }
  if (var0 & 128) { res->verified_app_name_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void urlAuthResultRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "urlAuthResultRequest");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (request_write_access_ << 0) | (request_phone_number_ << 1) | (match_codes_first_ << 5) | (is_app_ << 6)));
    if (var0 & 1) { s.store_field("request_write_access", true); }
    if (var0 & 2) { s.store_field("request_phone_number", true); }
    if (var0 & 32) { s.store_field("match_codes_first", true); }
    if (var0 & 64) { s.store_field("is_app", true); }
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("domain", domain_);
    if (var0 & 4) { s.store_field("browser", browser_); }
    if (var0 & 4) { s.store_field("platform", platform_); }
    if (var0 & 4) { s.store_field("ip", ip_); }
    if (var0 & 4) { s.store_field("region", region_); }
    if (var0 & 8) { { s.store_vector_begin("match_codes", match_codes_.size()); for (const auto &_value : match_codes_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("user_id_hint", user_id_hint_); }
    if (var0 & 128) { s.store_field("verified_app_name", verified_app_name_); }
    s.store_class_end();
  }
}

urlAuthResultAccepted::urlAuthResultAccepted()
  : flags_()
  , url_()
{}

const std::int32_t urlAuthResultAccepted::ID;

object_ptr<UrlAuthResult> urlAuthResultAccepted::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<urlAuthResultAccepted> res = make_tl_object<urlAuthResultAccepted>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->url_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void urlAuthResultAccepted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "urlAuthResultAccepted");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("url", url_); }
    s.store_class_end();
  }
}

const std::int32_t urlAuthResultDefault::ID;

object_ptr<UrlAuthResult> urlAuthResultDefault::fetch(TlBufferParser &p) {
  return make_tl_object<urlAuthResultDefault>();
}

void urlAuthResultDefault::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "urlAuthResultDefault");
    s.store_class_end();
  }
}

wallPaperSettings::wallPaperSettings()
  : flags_()
  , blur_()
  , motion_()
  , background_color_()
  , second_background_color_()
  , third_background_color_()
  , fourth_background_color_()
  , intensity_()
  , rotation_()
  , emoticon_()
{}

wallPaperSettings::wallPaperSettings(int32 flags_, bool blur_, bool motion_, int32 background_color_, int32 second_background_color_, int32 third_background_color_, int32 fourth_background_color_, int32 intensity_, int32 rotation_, string const &emoticon_)
  : flags_(flags_)
  , blur_(blur_)
  , motion_(motion_)
  , background_color_(background_color_)
  , second_background_color_(second_background_color_)
  , third_background_color_(third_background_color_)
  , fourth_background_color_(fourth_background_color_)
  , intensity_(intensity_)
  , rotation_(rotation_)
  , emoticon_(emoticon_)
{}

const std::int32_t wallPaperSettings::ID;

object_ptr<wallPaperSettings> wallPaperSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<wallPaperSettings> res = make_tl_object<wallPaperSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->blur_ = (var0 & 2) != 0;
  res->motion_ = (var0 & 4) != 0;
  if (var0 & 1) { res->background_color_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->second_background_color_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->third_background_color_ = TlFetchInt::parse(p); }
  if (var0 & 64) { res->fourth_background_color_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->intensity_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->rotation_ = TlFetchInt::parse(p); }
  if (var0 & 128) { res->emoticon_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void wallPaperSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (blur_ << 1) | (motion_ << 2)), s);
  if (var0 & 1) { TlStoreBinary::store(background_color_, s); }
  if (var0 & 16) { TlStoreBinary::store(second_background_color_, s); }
  if (var0 & 32) { TlStoreBinary::store(third_background_color_, s); }
  if (var0 & 64) { TlStoreBinary::store(fourth_background_color_, s); }
  if (var0 & 8) { TlStoreBinary::store(intensity_, s); }
  if (var0 & 16) { TlStoreBinary::store(rotation_, s); }
  if (var0 & 128) { TlStoreString::store(emoticon_, s); }
}

void wallPaperSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (blur_ << 1) | (motion_ << 2)), s);
  if (var0 & 1) { TlStoreBinary::store(background_color_, s); }
  if (var0 & 16) { TlStoreBinary::store(second_background_color_, s); }
  if (var0 & 32) { TlStoreBinary::store(third_background_color_, s); }
  if (var0 & 64) { TlStoreBinary::store(fourth_background_color_, s); }
  if (var0 & 8) { TlStoreBinary::store(intensity_, s); }
  if (var0 & 16) { TlStoreBinary::store(rotation_, s); }
  if (var0 & 128) { TlStoreString::store(emoticon_, s); }
}

void wallPaperSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallPaperSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (blur_ << 1) | (motion_ << 2)));
    if (var0 & 2) { s.store_field("blur", true); }
    if (var0 & 4) { s.store_field("motion", true); }
    if (var0 & 1) { s.store_field("background_color", background_color_); }
    if (var0 & 16) { s.store_field("second_background_color", second_background_color_); }
    if (var0 & 32) { s.store_field("third_background_color", third_background_color_); }
    if (var0 & 64) { s.store_field("fourth_background_color", fourth_background_color_); }
    if (var0 & 8) { s.store_field("intensity", intensity_); }
    if (var0 & 16) { s.store_field("rotation", rotation_); }
    if (var0 & 128) { s.store_field("emoticon", emoticon_); }
    s.store_class_end();
  }
}

account_contentSettings::account_contentSettings()
  : flags_()
  , sensitive_enabled_()
  , sensitive_can_change_()
{}

const std::int32_t account_contentSettings::ID;

object_ptr<account_contentSettings> account_contentSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_contentSettings> res = make_tl_object<account_contentSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->sensitive_enabled_ = (var0 & 1) != 0;
  res->sensitive_can_change_ = (var0 & 2) != 0;
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void account_contentSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.contentSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (sensitive_enabled_ << 0) | (sensitive_can_change_ << 1)));
    if (var0 & 1) { s.store_field("sensitive_enabled", true); }
    if (var0 & 2) { s.store_field("sensitive_can_change", true); }
    s.store_class_end();
  }
}

account_passwordInputSettings::account_passwordInputSettings(int32 flags_, object_ptr<PasswordKdfAlgo> &&new_algo_, bytes &&new_password_hash_, string const &hint_, string const &email_, object_ptr<secureSecretSettings> &&new_secure_settings_)
  : flags_(flags_)
  , new_algo_(std::move(new_algo_))
  , new_password_hash_(std::move(new_password_hash_))
  , hint_(hint_)
  , email_(email_)
  , new_secure_settings_(std::move(new_secure_settings_))
{}

const std::int32_t account_passwordInputSettings::ID;

void account_passwordInputSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(new_algo_, s); }
  if (var0 & 1) { TlStoreString::store(new_password_hash_, s); }
  if (var0 & 1) { TlStoreString::store(hint_, s); }
  if (var0 & 2) { TlStoreString::store(email_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 354925740>::store(new_secure_settings_, s); }
}

void account_passwordInputSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(new_algo_, s); }
  if (var0 & 1) { TlStoreString::store(new_password_hash_, s); }
  if (var0 & 1) { TlStoreString::store(hint_, s); }
  if (var0 & 2) { TlStoreString::store(email_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 354925740>::store(new_secure_settings_, s); }
}

void account_passwordInputSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.passwordInputSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("new_algo", static_cast<const BaseObject *>(new_algo_.get())); }
    if (var0 & 1) { s.store_bytes_field("new_password_hash", new_password_hash_); }
    if (var0 & 1) { s.store_field("hint", hint_); }
    if (var0 & 2) { s.store_field("email", email_); }
    if (var0 & 4) { s.store_object_field("new_secure_settings", static_cast<const BaseObject *>(new_secure_settings_.get())); }
    s.store_class_end();
  }
}

account_passwordSettings::account_passwordSettings()
  : flags_()
  , email_()
  , secure_settings_()
{}

const std::int32_t account_passwordSettings::ID;

object_ptr<account_passwordSettings> account_passwordSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_passwordSettings> res = make_tl_object<account_passwordSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->email_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->secure_settings_ = TlFetchBoxed<TlFetchObject<secureSecretSettings>, 354925740>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void account_passwordSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.passwordSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("email", email_); }
    if (var0 & 2) { s.store_object_field("secure_settings", static_cast<const BaseObject *>(secure_settings_.get())); }
    s.store_class_end();
  }
}

object_ptr<account_ResetPasswordResult> account_ResetPasswordResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_resetPasswordFailedWait::ID:
      return account_resetPasswordFailedWait::fetch(p);
    case account_resetPasswordRequestedWait::ID:
      return account_resetPasswordRequestedWait::fetch(p);
    case account_resetPasswordOk::ID:
      return account_resetPasswordOk::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_resetPasswordFailedWait::ID;

object_ptr<account_ResetPasswordResult> account_resetPasswordFailedWait::fetch(TlBufferParser &p) {
  return make_tl_object<account_resetPasswordFailedWait>(p);
}

account_resetPasswordFailedWait::account_resetPasswordFailedWait(TlBufferParser &p)
  : retry_date_(TlFetchInt::parse(p))
{}

void account_resetPasswordFailedWait::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetPasswordFailedWait");
    s.store_field("retry_date", retry_date_);
    s.store_class_end();
  }
}

const std::int32_t account_resetPasswordRequestedWait::ID;

object_ptr<account_ResetPasswordResult> account_resetPasswordRequestedWait::fetch(TlBufferParser &p) {
  return make_tl_object<account_resetPasswordRequestedWait>(p);
}

account_resetPasswordRequestedWait::account_resetPasswordRequestedWait(TlBufferParser &p)
  : until_date_(TlFetchInt::parse(p))
{}

void account_resetPasswordRequestedWait::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetPasswordRequestedWait");
    s.store_field("until_date", until_date_);
    s.store_class_end();
  }
}

const std::int32_t account_resetPasswordOk::ID;

object_ptr<account_ResetPasswordResult> account_resetPasswordOk::fetch(TlBufferParser &p) {
  return make_tl_object<account_resetPasswordOk>();
}

void account_resetPasswordOk::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetPasswordOk");
    s.store_class_end();
  }
}

const std::int32_t account_tmpPassword::ID;

object_ptr<account_tmpPassword> account_tmpPassword::fetch(TlBufferParser &p) {
  return make_tl_object<account_tmpPassword>(p);
}

account_tmpPassword::account_tmpPassword(TlBufferParser &p)
  : tmp_password_(TlFetchBytes<bytes>::parse(p))
  , valid_until_(TlFetchInt::parse(p))
{}

void account_tmpPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.tmpPassword");
    s.store_bytes_field("tmp_password", tmp_password_);
    s.store_field("valid_until", valid_until_);
    s.store_class_end();
  }
}

const std::int32_t bots_previewInfo::ID;

object_ptr<bots_previewInfo> bots_previewInfo::fetch(TlBufferParser &p) {
  return make_tl_object<bots_previewInfo>(p);
}

bots_previewInfo::bots_previewInfo(TlBufferParser &p)
  : media_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botPreviewMedia>, 602479523>>, 481674261>::parse(p))
  , lang_codes_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void bots_previewInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.previewInfo");
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("lang_codes", lang_codes_.size()); for (const auto &_value : lang_codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t channels_adminLogResults::ID;

object_ptr<channels_adminLogResults> channels_adminLogResults::fetch(TlBufferParser &p) {
  return make_tl_object<channels_adminLogResults>(p);
}

channels_adminLogResults::channels_adminLogResults(TlBufferParser &p)
  : events_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<channelAdminLogEvent>, 531458253>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void channels_adminLogResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.adminLogResults");
    { s.store_vector_begin("events", events_.size()); for (const auto &_value : events_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t chatlists_exportedChatlistInvite::ID;

object_ptr<chatlists_exportedChatlistInvite> chatlists_exportedChatlistInvite::fetch(TlBufferParser &p) {
  return make_tl_object<chatlists_exportedChatlistInvite>(p);
}

chatlists_exportedChatlistInvite::chatlists_exportedChatlistInvite(TlBufferParser &p)
  : filter_(TlFetchObject<DialogFilter>::parse(p))
  , invite_(TlFetchBoxed<TlFetchObject<exportedChatlistInvite>, 206668204>::parse(p))
{}

void chatlists_exportedChatlistInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.exportedChatlistInvite");
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_class_end();
  }
}

object_ptr<contacts_Blocked> contacts_Blocked::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case contacts_blocked::ID:
      return contacts_blocked::fetch(p);
    case contacts_blockedSlice::ID:
      return contacts_blockedSlice::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t contacts_blocked::ID;

object_ptr<contacts_Blocked> contacts_blocked::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_blocked>(p);
}

contacts_blocked::contacts_blocked(TlBufferParser &p)
  : blocked_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<peerBlocked>, -386039788>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_blocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.blocked");
    { s.store_vector_begin("blocked", blocked_.size()); for (const auto &_value : blocked_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t contacts_blockedSlice::ID;

object_ptr<contacts_Blocked> contacts_blockedSlice::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_blockedSlice>(p);
}

contacts_blockedSlice::contacts_blockedSlice(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , blocked_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<peerBlocked>, -386039788>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_blockedSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.blockedSlice");
    s.store_field("count", count_);
    { s.store_vector_begin("blocked", blocked_.size()); for (const auto &_value : blocked_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

help_country::help_country()
  : flags_()
  , hidden_()
  , iso2_()
  , default_name_()
  , name_()
  , country_codes_()
{}

const std::int32_t help_country::ID;

object_ptr<help_country> help_country::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_country> res = make_tl_object<help_country>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->hidden_ = (var0 & 1) != 0;
  res->iso2_ = TlFetchString<string>::parse(p);
  res->default_name_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->name_ = TlFetchString<string>::parse(p); }
  res->country_codes_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<help_countryCode>, 1107543535>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void help_country::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.country");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (hidden_ << 0)));
    if (var0 & 1) { s.store_field("hidden", true); }
    s.store_field("iso2", iso2_);
    s.store_field("default_name", default_name_);
    if (var0 & 2) { s.store_field("name", name_); }
    { s.store_vector_begin("country_codes", country_codes_.size()); for (const auto &_value : country_codes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<help_PeerColors> help_PeerColors::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_peerColorsNotModified::ID:
      return help_peerColorsNotModified::fetch(p);
    case help_peerColors::ID:
      return help_peerColors::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_peerColorsNotModified::ID;

object_ptr<help_PeerColors> help_peerColorsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<help_peerColorsNotModified>();
}

void help_peerColorsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.peerColorsNotModified");
    s.store_class_end();
  }
}

const std::int32_t help_peerColors::ID;

object_ptr<help_PeerColors> help_peerColors::fetch(TlBufferParser &p) {
  return make_tl_object<help_peerColors>(p);
}

help_peerColors::help_peerColors(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , colors_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<help_peerColorOption>, -1377014082>>, 481674261>::parse(p))
{}

void help_peerColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.peerColors");
    s.store_field("hash", hash_);
    { s.store_vector_begin("colors", colors_.size()); for (const auto &_value : colors_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_botApp::messages_botApp()
  : flags_()
  , inactive_()
  , request_write_access_()
  , has_settings_()
  , app_()
{}

const std::int32_t messages_botApp::ID;

object_ptr<messages_botApp> messages_botApp::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_botApp> res = make_tl_object<messages_botApp>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inactive_ = (var0 & 1) != 0;
  res->request_write_access_ = (var0 & 2) != 0;
  res->has_settings_ = (var0 & 4) != 0;
  res->app_ = TlFetchObject<BotApp>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_botApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.botApp");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inactive_ << 0) | (request_write_access_ << 1) | (has_settings_ << 2)));
    if (var0 & 1) { s.store_field("inactive", true); }
    if (var0 & 2) { s.store_field("request_write_access", true); }
    if (var0 & 4) { s.store_field("has_settings", true); }
    s.store_object_field("app", static_cast<const BaseObject *>(app_.get()));
    s.store_class_end();
  }
}

const std::int32_t messages_highScores::ID;

object_ptr<messages_highScores> messages_highScores::fetch(TlBufferParser &p) {
  return make_tl_object<messages_highScores>(p);
}

messages_highScores::messages_highScores(TlBufferParser &p)
  : scores_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<highScore>, 1940093419>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_highScores::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.highScores");
    { s.store_vector_begin("scores", scores_.size()); for (const auto &_value : scores_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_inactiveChats::ID;

object_ptr<messages_inactiveChats> messages_inactiveChats::fetch(TlBufferParser &p) {
  return make_tl_object<messages_inactiveChats>(p);
}

messages_inactiveChats::messages_inactiveChats(TlBufferParser &p)
  : dates_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_inactiveChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.inactiveChats");
    { s.store_vector_begin("dates", dates_.size()); for (const auto &_value : dates_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_peerDialogs::ID;

object_ptr<messages_peerDialogs> messages_peerDialogs::fetch(TlBufferParser &p) {
  return make_tl_object<messages_peerDialogs>(p);
}

messages_peerDialogs::messages_peerDialogs(TlBufferParser &p)
  : dialogs_(TlFetchBoxed<TlFetchVector<TlFetchObject<Dialog>>, 481674261>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , state_(TlFetchBoxed<TlFetchObject<updates_state>, -1519637954>::parse(p))
{}

void messages_peerDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.peerDialogs");
    { s.store_vector_begin("dialogs", dialogs_.size()); for (const auto &_value : dialogs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_object_field("state", static_cast<const BaseObject *>(state_.get()));
    s.store_class_end();
  }
}

const std::int32_t messages_preparedInlineMessage::ID;

object_ptr<messages_preparedInlineMessage> messages_preparedInlineMessage::fetch(TlBufferParser &p) {
  return make_tl_object<messages_preparedInlineMessage>(p);
}

messages_preparedInlineMessage::messages_preparedInlineMessage(TlBufferParser &p)
  : query_id_(TlFetchLong::parse(p))
  , result_(TlFetchObject<BotInlineResult>::parse(p))
  , peer_types_(TlFetchBoxed<TlFetchVector<TlFetchObject<InlineQueryPeerType>>, 481674261>::parse(p))
  , cache_time_(TlFetchInt::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_preparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.preparedInlineMessage");
    s.store_field("query_id", query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    { s.store_vector_begin("peer_types", peer_types_.size()); for (const auto &_value : peer_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("cache_time", cache_time_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_transcribedAudio::messages_transcribedAudio()
  : flags_()
  , pending_()
  , transcription_id_()
  , text_()
  , trial_remains_num_()
  , trial_remains_until_date_()
{}

const std::int32_t messages_transcribedAudio::ID;

object_ptr<messages_transcribedAudio> messages_transcribedAudio::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_transcribedAudio> res = make_tl_object<messages_transcribedAudio>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pending_ = (var0 & 1) != 0;
  res->transcription_id_ = TlFetchLong::parse(p);
  res->text_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->trial_remains_num_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->trial_remains_until_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_transcribedAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.transcribedAudio");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pending_ << 0)));
    if (var0 & 1) { s.store_field("pending", true); }
    s.store_field("transcription_id", transcription_id_);
    s.store_field("text", text_);
    if (var0 & 2) { s.store_field("trial_remains_num", trial_remains_num_); }
    if (var0 & 2) { s.store_field("trial_remains_until_date", trial_remains_until_date_); }
    s.store_class_end();
  }
}

const std::int32_t messages_webPage::ID;

object_ptr<messages_webPage> messages_webPage::fetch(TlBufferParser &p) {
  return make_tl_object<messages_webPage>(p);
}

messages_webPage::messages_webPage(TlBufferParser &p)
  : webpage_(TlFetchObject<WebPage>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_webPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.webPage");
    s.store_object_field("webpage", static_cast<const BaseObject *>(webpage_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_validatedRequestedInfo::payments_validatedRequestedInfo()
  : flags_()
  , id_()
  , shipping_options_()
{}

const std::int32_t payments_validatedRequestedInfo::ID;

object_ptr<payments_validatedRequestedInfo> payments_validatedRequestedInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_validatedRequestedInfo> res = make_tl_object<payments_validatedRequestedInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->id_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->shipping_options_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<shippingOption>, -1239335713>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_validatedRequestedInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.validatedRequestedInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("id", id_); }
    if (var0 & 2) { { s.store_vector_begin("shipping_options", shipping_options_.size()); for (const auto &_value : shipping_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t phone_phoneCall::ID;

object_ptr<phone_phoneCall> phone_phoneCall::fetch(TlBufferParser &p) {
  return make_tl_object<phone_phoneCall>(p);
}

phone_phoneCall::phone_phoneCall(TlBufferParser &p)
  : phone_call_(TlFetchObject<PhoneCall>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void phone_phoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.phoneCall");
    s.store_object_field("phone_call", static_cast<const BaseObject *>(phone_call_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stats_broadcastStats::ID;

object_ptr<stats_broadcastStats> stats_broadcastStats::fetch(TlBufferParser &p) {
  return make_tl_object<stats_broadcastStats>(p);
}

stats_broadcastStats::stats_broadcastStats(TlBufferParser &p)
  : period_(TlFetchBoxed<TlFetchObject<statsDateRangeDays>, -1237848657>::parse(p))
  , followers_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , views_per_post_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , shares_per_post_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , reactions_per_post_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , views_per_story_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , shares_per_story_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , reactions_per_story_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , enabled_notifications_(TlFetchBoxed<TlFetchObject<statsPercentValue>, -875679776>::parse(p))
  , growth_graph_(TlFetchObject<StatsGraph>::parse(p))
  , followers_graph_(TlFetchObject<StatsGraph>::parse(p))
  , mute_graph_(TlFetchObject<StatsGraph>::parse(p))
  , top_hours_graph_(TlFetchObject<StatsGraph>::parse(p))
  , interactions_graph_(TlFetchObject<StatsGraph>::parse(p))
  , iv_interactions_graph_(TlFetchObject<StatsGraph>::parse(p))
  , views_by_source_graph_(TlFetchObject<StatsGraph>::parse(p))
  , new_followers_by_source_graph_(TlFetchObject<StatsGraph>::parse(p))
  , languages_graph_(TlFetchObject<StatsGraph>::parse(p))
  , reactions_by_emotion_graph_(TlFetchObject<StatsGraph>::parse(p))
  , story_interactions_graph_(TlFetchObject<StatsGraph>::parse(p))
  , story_reactions_by_emotion_graph_(TlFetchObject<StatsGraph>::parse(p))
  , recent_posts_interactions_(TlFetchBoxed<TlFetchVector<TlFetchObject<PostInteractionCounters>>, 481674261>::parse(p))
{}

void stats_broadcastStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.broadcastStats");
    s.store_object_field("period", static_cast<const BaseObject *>(period_.get()));
    s.store_object_field("followers", static_cast<const BaseObject *>(followers_.get()));
    s.store_object_field("views_per_post", static_cast<const BaseObject *>(views_per_post_.get()));
    s.store_object_field("shares_per_post", static_cast<const BaseObject *>(shares_per_post_.get()));
    s.store_object_field("reactions_per_post", static_cast<const BaseObject *>(reactions_per_post_.get()));
    s.store_object_field("views_per_story", static_cast<const BaseObject *>(views_per_story_.get()));
    s.store_object_field("shares_per_story", static_cast<const BaseObject *>(shares_per_story_.get()));
    s.store_object_field("reactions_per_story", static_cast<const BaseObject *>(reactions_per_story_.get()));
    s.store_object_field("enabled_notifications", static_cast<const BaseObject *>(enabled_notifications_.get()));
    s.store_object_field("growth_graph", static_cast<const BaseObject *>(growth_graph_.get()));
    s.store_object_field("followers_graph", static_cast<const BaseObject *>(followers_graph_.get()));
    s.store_object_field("mute_graph", static_cast<const BaseObject *>(mute_graph_.get()));
    s.store_object_field("top_hours_graph", static_cast<const BaseObject *>(top_hours_graph_.get()));
    s.store_object_field("interactions_graph", static_cast<const BaseObject *>(interactions_graph_.get()));
    s.store_object_field("iv_interactions_graph", static_cast<const BaseObject *>(iv_interactions_graph_.get()));
    s.store_object_field("views_by_source_graph", static_cast<const BaseObject *>(views_by_source_graph_.get()));
    s.store_object_field("new_followers_by_source_graph", static_cast<const BaseObject *>(new_followers_by_source_graph_.get()));
    s.store_object_field("languages_graph", static_cast<const BaseObject *>(languages_graph_.get()));
    s.store_object_field("reactions_by_emotion_graph", static_cast<const BaseObject *>(reactions_by_emotion_graph_.get()));
    s.store_object_field("story_interactions_graph", static_cast<const BaseObject *>(story_interactions_graph_.get()));
    s.store_object_field("story_reactions_by_emotion_graph", static_cast<const BaseObject *>(story_reactions_by_emotion_graph_.get()));
    { s.store_vector_begin("recent_posts_interactions", recent_posts_interactions_.size()); for (const auto &_value : recent_posts_interactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stories_peerStories::ID;

object_ptr<stories_peerStories> stories_peerStories::fetch(TlBufferParser &p) {
  return make_tl_object<stories_peerStories>(p);
}

stories_peerStories::stories_peerStories(TlBufferParser &p)
  : stories_(TlFetchBoxed<TlFetchObject<peerStories>, -1707742823>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void stories_peerStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.peerStories");
    s.store_object_field("stories", static_cast<const BaseObject *>(stories_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t account_declinePasswordReset::ID;

void account_declinePasswordReset::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1284770294);
}

void account_declinePasswordReset::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1284770294);
}

void account_declinePasswordReset::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.declinePasswordReset");
    s.store_class_end();
  }
}

account_declinePasswordReset::ReturnType account_declinePasswordReset::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_deleteAccount::account_deleteAccount(int32 flags_, string const &reason_, object_ptr<InputCheckPasswordSRP> &&password_)
  : flags_(flags_)
  , reason_(reason_)
  , password_(std::move(password_))
{}

const std::int32_t account_deleteAccount::ID;

void account_deleteAccount::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1564422284);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(reason_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
}

void account_deleteAccount::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1564422284);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(reason_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
}

void account_deleteAccount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.deleteAccount");
    s.store_field("flags", (var0 = flags_));
    s.store_field("reason", reason_);
    if (var0 & 1) { s.store_object_field("password", static_cast<const BaseObject *>(password_.get())); }
    s.store_class_end();
  }
}

account_deleteAccount::ReturnType account_deleteAccount::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_getBotBusinessConnection::account_getBotBusinessConnection(string const &connection_id_)
  : connection_id_(connection_id_)
{}

const std::int32_t account_getBotBusinessConnection::ID;

void account_getBotBusinessConnection::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1990746736);
  TlStoreString::store(connection_id_, s);
}

void account_getBotBusinessConnection::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1990746736);
  TlStoreString::store(connection_id_, s);
}

void account_getBotBusinessConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getBotBusinessConnection");
    s.store_field("connection_id", connection_id_);
    s.store_class_end();
  }
}

account_getBotBusinessConnection::ReturnType account_getBotBusinessConnection::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

account_registerPasskey::account_registerPasskey(object_ptr<InputPasskeyCredential> &&credential_)
  : credential_(std::move(credential_))
{}

const std::int32_t account_registerPasskey::ID;

void account_registerPasskey::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1437867990);
  TlStoreBoxedUnknown<TlStoreObject>::store(credential_, s);
}

void account_registerPasskey::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1437867990);
  TlStoreBoxedUnknown<TlStoreObject>::store(credential_, s);
}

void account_registerPasskey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.registerPasskey");
    s.store_object_field("credential", static_cast<const BaseObject *>(credential_.get()));
    s.store_class_end();
  }
}

account_registerPasskey::ReturnType account_registerPasskey::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<passkey>, -1738457409>::parse(p);
#undef FAIL
}

account_resolveBusinessChatLink::account_resolveBusinessChatLink(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t account_resolveBusinessChatLink::ID;

void account_resolveBusinessChatLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1418913262);
  TlStoreString::store(slug_, s);
}

void account_resolveBusinessChatLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1418913262);
  TlStoreString::store(slug_, s);
}

void account_resolveBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resolveBusinessChatLink");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

account_resolveBusinessChatLink::ReturnType account_resolveBusinessChatLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_resolvedBusinessChatLinks>, -1708937439>::parse(p);
#undef FAIL
}

account_setGlobalPrivacySettings::account_setGlobalPrivacySettings(object_ptr<globalPrivacySettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t account_setGlobalPrivacySettings::ID;

void account_setGlobalPrivacySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(517647042);
  TlStoreBoxed<TlStoreObject, -29248689>::store(settings_, s);
}

void account_setGlobalPrivacySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(517647042);
  TlStoreBoxed<TlStoreObject, -29248689>::store(settings_, s);
}

void account_setGlobalPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setGlobalPrivacySettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_setGlobalPrivacySettings::ReturnType account_setGlobalPrivacySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<globalPrivacySettings>, -29248689>::parse(p);
#undef FAIL
}

account_setReactionsNotifySettings::account_setReactionsNotifySettings(object_ptr<reactionsNotifySettings> &&settings_)
  : settings_(std::move(settings_))
{}

const std::int32_t account_setReactionsNotifySettings::ID;

void account_setReactionsNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(829220168);
  TlStoreBoxed<TlStoreObject, 1910827608>::store(settings_, s);
}

void account_setReactionsNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(829220168);
  TlStoreBoxed<TlStoreObject, 1910827608>::store(settings_, s);
}

void account_setReactionsNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setReactionsNotifySettings");
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_setReactionsNotifySettings::ReturnType account_setReactionsNotifySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<reactionsNotifySettings>, 1910827608>::parse(p);
#undef FAIL
}

account_uploadRingtone::account_uploadRingtone(object_ptr<InputFile> &&file_, string const &file_name_, string const &mime_type_)
  : file_(std::move(file_))
  , file_name_(file_name_)
  , mime_type_(mime_type_)
{}

const std::int32_t account_uploadRingtone::ID;

void account_uploadRingtone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2095414366);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  TlStoreString::store(file_name_, s);
  TlStoreString::store(mime_type_, s);
}

void account_uploadRingtone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2095414366);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  TlStoreString::store(file_name_, s);
  TlStoreString::store(mime_type_, s);
}

void account_uploadRingtone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.uploadRingtone");
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_field("file_name", file_name_);
    s.store_field("mime_type", mime_type_);
    s.store_class_end();
  }
}

account_uploadRingtone::ReturnType account_uploadRingtone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Document>::parse(p);
#undef FAIL
}

account_uploadWallPaper::account_uploadWallPaper(int32 flags_, bool for_chat_, object_ptr<InputFile> &&file_, string const &mime_type_, object_ptr<wallPaperSettings> &&settings_)
  : flags_(flags_)
  , for_chat_(for_chat_)
  , file_(std::move(file_))
  , mime_type_(mime_type_)
  , settings_(std::move(settings_))
{}

const std::int32_t account_uploadWallPaper::ID;

void account_uploadWallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-476410109);
  TlStoreBinary::store((var0 = flags_ | (for_chat_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s);
}

void account_uploadWallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-476410109);
  TlStoreBinary::store((var0 = flags_ | (for_chat_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s);
}

void account_uploadWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.uploadWallPaper");
    s.store_field("flags", (var0 = flags_ | (for_chat_ << 0)));
    if (var0 & 1) { s.store_field("for_chat", true); }
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_field("mime_type", mime_type_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_uploadWallPaper::ReturnType account_uploadWallPaper::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<WallPaper>::parse(p);
#undef FAIL
}

auth_acceptLoginToken::auth_acceptLoginToken(bytes &&token_)
  : token_(std::move(token_))
{}

const std::int32_t auth_acceptLoginToken::ID;

void auth_acceptLoginToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-392909491);
  TlStoreString::store(token_, s);
}

void auth_acceptLoginToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-392909491);
  TlStoreString::store(token_, s);
}

void auth_acceptLoginToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.acceptLoginToken");
    s.store_bytes_field("token", token_);
    s.store_class_end();
  }
}

auth_acceptLoginToken::ReturnType auth_acceptLoginToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<authorization>, -1392388579>::parse(p);
#undef FAIL
}

const std::int32_t auth_resetAuthorizations::ID;

void auth_resetAuthorizations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1616179942);
}

void auth_resetAuthorizations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1616179942);
}

void auth_resetAuthorizations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.resetAuthorizations");
    s.store_class_end();
  }
}

auth_resetAuthorizations::ReturnType auth_resetAuthorizations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_signIn::auth_signIn(int32 flags_, string const &phone_number_, string const &phone_code_hash_, string const &phone_code_, object_ptr<EmailVerification> &&email_verification_)
  : flags_(flags_)
  , phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , phone_code_(phone_code_)
  , email_verification_(std::move(email_verification_))
{}

const std::int32_t auth_signIn::ID;

void auth_signIn::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1923962543);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  if (var0 & 1) { TlStoreString::store(phone_code_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(email_verification_, s); }
}

void auth_signIn::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1923962543);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  if (var0 & 1) { TlStoreString::store(phone_code_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(email_verification_, s); }
}

void auth_signIn::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.signIn");
    s.store_field("flags", (var0 = flags_));
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    if (var0 & 1) { s.store_field("phone_code", phone_code_); }
    if (var0 & 2) { s.store_object_field("email_verification", static_cast<const BaseObject *>(email_verification_.get())); }
    s.store_class_end();
  }
}

auth_signIn::ReturnType auth_signIn::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

bots_checkDownloadFileParams::bots_checkDownloadFileParams(object_ptr<InputUser> &&bot_, string const &file_name_, string const &url_)
  : bot_(std::move(bot_))
  , file_name_(file_name_)
  , url_(url_)
{}

const std::int32_t bots_checkDownloadFileParams::ID;

void bots_checkDownloadFileParams::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1342666121);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(file_name_, s);
  TlStoreString::store(url_, s);
}

void bots_checkDownloadFileParams::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1342666121);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(file_name_, s);
  TlStoreString::store(url_, s);
}

void bots_checkDownloadFileParams::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.checkDownloadFileParams");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("file_name", file_name_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

bots_checkDownloadFileParams::ReturnType bots_checkDownloadFileParams::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_getBotMenuButton::bots_getBotMenuButton(object_ptr<InputUser> &&user_id_)
  : user_id_(std::move(user_id_))
{}

const std::int32_t bots_getBotMenuButton::ID;

void bots_getBotMenuButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1671369944);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void bots_getBotMenuButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1671369944);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void bots_getBotMenuButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getBotMenuButton");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

bots_getBotMenuButton::ReturnType bots_getBotMenuButton::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<BotMenuButton>::parse(p);
#undef FAIL
}

bots_setBotBroadcastDefaultAdminRights::bots_setBotBroadcastDefaultAdminRights(object_ptr<chatAdminRights> &&admin_rights_)
  : admin_rights_(std::move(admin_rights_))
{}

const std::int32_t bots_setBotBroadcastDefaultAdminRights::ID;

void bots_setBotBroadcastDefaultAdminRights::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2021942497);
  TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s);
}

void bots_setBotBroadcastDefaultAdminRights::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2021942497);
  TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s);
}

void bots_setBotBroadcastDefaultAdminRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setBotBroadcastDefaultAdminRights");
    s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get()));
    s.store_class_end();
  }
}

bots_setBotBroadcastDefaultAdminRights::ReturnType bots_setBotBroadcastDefaultAdminRights::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_updateUserEmojiStatus::bots_updateUserEmojiStatus(object_ptr<InputUser> &&user_id_, object_ptr<EmojiStatus> &&emoji_status_)
  : user_id_(std::move(user_id_))
  , emoji_status_(std::move(emoji_status_))
{}

const std::int32_t bots_updateUserEmojiStatus::ID;

void bots_updateUserEmojiStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-308334395);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s);
}

void bots_updateUserEmojiStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-308334395);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s);
}

void bots_updateUserEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.updateUserEmojiStatus");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

bots_updateUserEmojiStatus::ReturnType bots_updateUserEmojiStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_deactivateAllUsernames::channels_deactivateAllUsernames(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t channels_deactivateAllUsernames::ID;

void channels_deactivateAllUsernames::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(170155475);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_deactivateAllUsernames::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(170155475);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_deactivateAllUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.deactivateAllUsernames");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_deactivateAllUsernames::ReturnType channels_deactivateAllUsernames::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_editPhoto::channels_editPhoto(object_ptr<InputChannel> &&channel_, object_ptr<InputChatPhoto> &&photo_)
  : channel_(std::move(channel_))
  , photo_(std::move(photo_))
{}

const std::int32_t channels_editPhoto::ID;

void channels_editPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-248621111);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
}

void channels_editPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-248621111);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
}

void channels_editPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.editPhoto");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

channels_editPhoto::ReturnType channels_editPhoto::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_getChannels::channels_getChannels(array<object_ptr<InputChannel>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t channels_getChannels::ID;

void channels_getChannels::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(176122811);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void channels_getChannels::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(176122811);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void channels_getChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getChannels");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_getChannels::ReturnType channels_getChannels::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

const std::int32_t channels_getGroupsForDiscussion::ID;

void channels_getGroupsForDiscussion::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-170208392);
}

void channels_getGroupsForDiscussion::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-170208392);
}

void channels_getGroupsForDiscussion::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getGroupsForDiscussion");
    s.store_class_end();
  }
}

channels_getGroupsForDiscussion::ReturnType channels_getGroupsForDiscussion::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

channels_getSendAs::channels_getSendAs(int32 flags_, bool for_paid_reactions_, bool for_live_stories_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , for_paid_reactions_(for_paid_reactions_)
  , for_live_stories_(for_live_stories_)
  , peer_(std::move(peer_))
{}

const std::int32_t channels_getSendAs::ID;

void channels_getSendAs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-410672065);
  TlStoreBinary::store((var0 = flags_ | (for_paid_reactions_ << 0) | (for_live_stories_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void channels_getSendAs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-410672065);
  TlStoreBinary::store((var0 = flags_ | (for_paid_reactions_ << 0) | (for_live_stories_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void channels_getSendAs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getSendAs");
    s.store_field("flags", (var0 = flags_ | (for_paid_reactions_ << 0) | (for_live_stories_ << 1)));
    if (var0 & 1) { s.store_field("for_paid_reactions", true); }
    if (var0 & 2) { s.store_field("for_live_stories", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

channels_getSendAs::ReturnType channels_getSendAs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<channels_sendAsPeers>, -191450938>::parse(p);
#undef FAIL
}

channels_reorderUsernames::channels_reorderUsernames(object_ptr<InputChannel> &&channel_, array<string> &&order_)
  : channel_(std::move(channel_))
  , order_(std::move(order_))
{}

const std::int32_t channels_reorderUsernames::ID;

void channels_reorderUsernames::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1268978403);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(order_, s);
}

void channels_reorderUsernames::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1268978403);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(order_, s);
}

void channels_reorderUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.reorderUsernames");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_reorderUsernames::ReturnType channels_reorderUsernames::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_toggleJoinRequest::channels_toggleJoinRequest(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_toggleJoinRequest::ID;

void channels_toggleJoinRequest::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1277789622);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleJoinRequest::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1277789622);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleJoinRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleJoinRequest");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_toggleJoinRequest::ReturnType channels_toggleJoinRequest::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_togglePreHistoryHidden::channels_togglePreHistoryHidden(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_togglePreHistoryHidden::ID;

void channels_togglePreHistoryHidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-356796084);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_togglePreHistoryHidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-356796084);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_togglePreHistoryHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.togglePreHistoryHidden");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_togglePreHistoryHidden::ReturnType channels_togglePreHistoryHidden::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

chatlists_deleteExportedInvite::chatlists_deleteExportedInvite(object_ptr<inputChatlistDialogFilter> &&chatlist_, string const &slug_)
  : chatlist_(std::move(chatlist_))
  , slug_(slug_)
{}

const std::int32_t chatlists_deleteExportedInvite::ID;

void chatlists_deleteExportedInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1906072670);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreString::store(slug_, s);
}

void chatlists_deleteExportedInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1906072670);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
  TlStoreString::store(slug_, s);
}

void chatlists_deleteExportedInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.deleteExportedInvite");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

chatlists_deleteExportedInvite::ReturnType chatlists_deleteExportedInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

help_acceptTermsOfService::help_acceptTermsOfService(object_ptr<dataJSON> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t help_acceptTermsOfService::ID;

void help_acceptTermsOfService::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-294455398);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(id_, s);
}

void help_acceptTermsOfService::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-294455398);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(id_, s);
}

void help_acceptTermsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.acceptTermsOfService");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

help_acceptTermsOfService::ReturnType help_acceptTermsOfService::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t help_getConfig::ID;

void help_getConfig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-990308245);
}

void help_getConfig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-990308245);
}

void help_getConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getConfig");
    s.store_class_end();
  }
}

help_getConfig::ReturnType help_getConfig::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<config>, -870702050>::parse(p);
#undef FAIL
}

const std::int32_t help_getNearestDc::ID;

void help_getNearestDc::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(531836966);
}

void help_getNearestDc::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(531836966);
}

void help_getNearestDc::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getNearestDc");
    s.store_class_end();
  }
}

help_getNearestDc::ReturnType help_getNearestDc::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<nearestDc>, -1910892683>::parse(p);
#undef FAIL
}

help_getPeerProfileColors::help_getPeerProfileColors(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t help_getPeerProfileColors::ID;

void help_getPeerProfileColors::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1412453891);
  TlStoreBinary::store(hash_, s);
}

void help_getPeerProfileColors::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1412453891);
  TlStoreBinary::store(hash_, s);
}

void help_getPeerProfileColors::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getPeerProfileColors");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_getPeerProfileColors::ReturnType help_getPeerProfileColors::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_PeerColors>::parse(p);
#undef FAIL
}

help_getTimezonesList::help_getTimezonesList(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t help_getTimezonesList::ID;

void help_getTimezonesList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1236468288);
  TlStoreBinary::store(hash_, s);
}

void help_getTimezonesList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1236468288);
  TlStoreBinary::store(hash_, s);
}

void help_getTimezonesList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getTimezonesList");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_getTimezonesList::ReturnType help_getTimezonesList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_TimezonesList>::parse(p);
#undef FAIL
}

help_getUserInfo::help_getUserInfo(object_ptr<InputUser> &&user_id_)
  : user_id_(std::move(user_id_))
{}

const std::int32_t help_getUserInfo::ID;

void help_getUserInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(59377875);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void help_getUserInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(59377875);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void help_getUserInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getUserInfo");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

help_getUserInfo::ReturnType help_getUserInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_UserInfo>::parse(p);
#undef FAIL
}

invokeWithApnsSecretPrefix::invokeWithApnsSecretPrefix(string const &nonce_, string const &secret_)
  : nonce_(nonce_)
  , secret_(secret_)
{}

const std::int32_t invokeWithApnsSecretPrefix::ID;

void invokeWithApnsSecretPrefix::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(229528824);
  TlStoreString::store(nonce_, s);
  TlStoreString::store(secret_, s);
}

void invokeWithApnsSecretPrefix::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(229528824);
  TlStoreString::store(nonce_, s);
  TlStoreString::store(secret_, s);
}

void invokeWithApnsSecretPrefix::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invokeWithApnsSecretPrefix");
    s.store_field("nonce", nonce_);
    s.store_field("secret", secret_);
    s.store_class_end();
  }
}

invokeWithApnsSecretPrefix::ReturnType invokeWithApnsSecretPrefix::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<error>, -994444869>::parse(p);
#undef FAIL
}

messages_checkQuickReplyShortcut::messages_checkQuickReplyShortcut(string const &shortcut_)
  : shortcut_(shortcut_)
{}

const std::int32_t messages_checkQuickReplyShortcut::ID;

void messages_checkQuickReplyShortcut::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-237962285);
  TlStoreString::store(shortcut_, s);
}

void messages_checkQuickReplyShortcut::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-237962285);
  TlStoreString::store(shortcut_, s);
}

void messages_checkQuickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.checkQuickReplyShortcut");
    s.store_field("shortcut", shortcut_);
    s.store_class_end();
  }
}

messages_checkQuickReplyShortcut::ReturnType messages_checkQuickReplyShortcut::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_deletePhoneCallHistory::messages_deletePhoneCallHistory(int32 flags_, bool revoke_)
  : flags_(flags_)
  , revoke_(revoke_)
{}

const std::int32_t messages_deletePhoneCallHistory::ID;

void messages_deletePhoneCallHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-104078327);
  TlStoreBinary::store((var0 = flags_ | (revoke_ << 0)), s);
}

void messages_deletePhoneCallHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-104078327);
  TlStoreBinary::store((var0 = flags_ | (revoke_ << 0)), s);
}

void messages_deletePhoneCallHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deletePhoneCallHistory");
    s.store_field("flags", (var0 = flags_ | (revoke_ << 0)));
    if (var0 & 1) { s.store_field("revoke", true); }
    s.store_class_end();
  }
}

messages_deletePhoneCallHistory::ReturnType messages_deletePhoneCallHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedFoundMessages>, -275956116>::parse(p);
#undef FAIL
}

messages_discardEncryption::messages_discardEncryption(int32 flags_, bool delete_history_, int32 chat_id_)
  : flags_(flags_)
  , delete_history_(delete_history_)
  , chat_id_(chat_id_)
{}

const std::int32_t messages_discardEncryption::ID;

void messages_discardEncryption::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-208425312);
  TlStoreBinary::store((var0 = flags_ | (delete_history_ << 0)), s);
  TlStoreBinary::store(chat_id_, s);
}

void messages_discardEncryption::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-208425312);
  TlStoreBinary::store((var0 = flags_ | (delete_history_ << 0)), s);
  TlStoreBinary::store(chat_id_, s);
}

void messages_discardEncryption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.discardEncryption");
    s.store_field("flags", (var0 = flags_ | (delete_history_ << 0)));
    if (var0 & 1) { s.store_field("delete_history", true); }
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

messages_discardEncryption::ReturnType messages_discardEncryption::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_editChatDefaultBannedRights::messages_editChatDefaultBannedRights(object_ptr<InputPeer> &&peer_, object_ptr<chatBannedRights> &&banned_rights_)
  : peer_(std::move(peer_))
  , banned_rights_(std::move(banned_rights_))
{}

const std::int32_t messages_editChatDefaultBannedRights::ID;

void messages_editChatDefaultBannedRights::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1517917375);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreObject, -1626209256>::store(banned_rights_, s);
}

void messages_editChatDefaultBannedRights::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1517917375);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreObject, -1626209256>::store(banned_rights_, s);
}

void messages_editChatDefaultBannedRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatDefaultBannedRights");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("banned_rights", static_cast<const BaseObject *>(banned_rights_.get()));
    s.store_class_end();
  }
}

messages_editChatDefaultBannedRights::ReturnType messages_editChatDefaultBannedRights::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_exportChatInvite::messages_exportChatInvite(int32 flags_, bool legacy_revoke_permanent_, bool request_needed_, object_ptr<InputPeer> &&peer_, int32 expire_date_, int32 usage_limit_, string const &title_, object_ptr<starsSubscriptionPricing> &&subscription_pricing_)
  : flags_(flags_)
  , legacy_revoke_permanent_(legacy_revoke_permanent_)
  , request_needed_(request_needed_)
  , peer_(std::move(peer_))
  , expire_date_(expire_date_)
  , usage_limit_(usage_limit_)
  , title_(title_)
  , subscription_pricing_(std::move(subscription_pricing_))
{}

const std::int32_t messages_exportChatInvite::ID;

void messages_exportChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1537876336);
  TlStoreBinary::store((var0 = flags_ | (legacy_revoke_permanent_ << 2) | (request_needed_ << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(expire_date_, s); }
  if (var0 & 2) { TlStoreBinary::store(usage_limit_, s); }
  if (var0 & 16) { TlStoreString::store(title_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreObject, 88173912>::store(subscription_pricing_, s); }
}

void messages_exportChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1537876336);
  TlStoreBinary::store((var0 = flags_ | (legacy_revoke_permanent_ << 2) | (request_needed_ << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(expire_date_, s); }
  if (var0 & 2) { TlStoreBinary::store(usage_limit_, s); }
  if (var0 & 16) { TlStoreString::store(title_, s); }
  if (var0 & 32) { TlStoreBoxed<TlStoreObject, 88173912>::store(subscription_pricing_, s); }
}

void messages_exportChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.exportChatInvite");
    s.store_field("flags", (var0 = flags_ | (legacy_revoke_permanent_ << 2) | (request_needed_ << 3)));
    if (var0 & 4) { s.store_field("legacy_revoke_permanent", true); }
    if (var0 & 8) { s.store_field("request_needed", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("expire_date", expire_date_); }
    if (var0 & 2) { s.store_field("usage_limit", usage_limit_); }
    if (var0 & 16) { s.store_field("title", title_); }
    if (var0 & 32) { s.store_object_field("subscription_pricing", static_cast<const BaseObject *>(subscription_pricing_.get())); }
    s.store_class_end();
  }
}

messages_exportChatInvite::ReturnType messages_exportChatInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<ExportedChatInvite>::parse(p);
#undef FAIL
}

messages_getAllStickers::messages_getAllStickers(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getAllStickers::ID;

void messages_getAllStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1197432408);
  TlStoreBinary::store(hash_, s);
}

void messages_getAllStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1197432408);
  TlStoreBinary::store(hash_, s);
}

void messages_getAllStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAllStickers");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getAllStickers::ReturnType messages_getAllStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_AllStickers>::parse(p);
#undef FAIL
}

messages_getChatInviteImporters::messages_getChatInviteImporters(int32 flags_, bool requested_, bool subscription_expired_, object_ptr<InputPeer> &&peer_, string const &link_, string const &q_, int32 offset_date_, object_ptr<InputUser> &&offset_user_, int32 limit_)
  : flags_(flags_)
  , requested_(requested_)
  , subscription_expired_(subscription_expired_)
  , peer_(std::move(peer_))
  , link_(link_)
  , q_(q_)
  , offset_date_(offset_date_)
  , offset_user_(std::move(offset_user_))
  , limit_(limit_)
{}

const std::int32_t messages_getChatInviteImporters::ID;

void messages_getChatInviteImporters::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-553329330);
  TlStoreBinary::store((var0 = flags_ | (requested_ << 0) | (subscription_expired_ << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreString::store(link_, s); }
  if (var0 & 4) { TlStoreString::store(q_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_user_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getChatInviteImporters::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-553329330);
  TlStoreBinary::store((var0 = flags_ | (requested_ << 0) | (subscription_expired_ << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreString::store(link_, s); }
  if (var0 & 4) { TlStoreString::store(q_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_user_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getChatInviteImporters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getChatInviteImporters");
    s.store_field("flags", (var0 = flags_ | (requested_ << 0) | (subscription_expired_ << 3)));
    if (var0 & 1) { s.store_field("requested", true); }
    if (var0 & 8) { s.store_field("subscription_expired", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_field("link", link_); }
    if (var0 & 4) { s.store_field("q", q_); }
    s.store_field("offset_date", offset_date_);
    s.store_object_field("offset_user", static_cast<const BaseObject *>(offset_user_.get()));
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getChatInviteImporters::ReturnType messages_getChatInviteImporters::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_chatInviteImporters>, -2118733814>::parse(p);
#undef FAIL
}

messages_getEmojiGroups::messages_getEmojiGroups(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getEmojiGroups::ID;

void messages_getEmojiGroups::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1955122779);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiGroups::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1955122779);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiGroups");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getEmojiGroups::ReturnType messages_getEmojiGroups::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_EmojiGroups>::parse(p);
#undef FAIL
}

messages_getForumTopics::messages_getForumTopics(int32 flags_, object_ptr<InputPeer> &&peer_, string const &q_, int32 offset_date_, int32 offset_id_, int32 offset_topic_, int32 limit_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , q_(q_)
  , offset_date_(offset_date_)
  , offset_id_(offset_id_)
  , offset_topic_(offset_topic_)
  , limit_(limit_)
{}

const std::int32_t messages_getForumTopics::ID;

void messages_getForumTopics::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1000635391);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreString::store(q_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_topic_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getForumTopics::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1000635391);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreString::store(q_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_topic_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getForumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getForumTopics");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("q", q_); }
    s.store_field("offset_date", offset_date_);
    s.store_field("offset_id", offset_id_);
    s.store_field("offset_topic", offset_topic_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getForumTopics::ReturnType messages_getForumTopics::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_forumTopics>, 913709011>::parse(p);
#undef FAIL
}

messages_getPreparedInlineMessage::messages_getPreparedInlineMessage(object_ptr<InputUser> &&bot_, string const &id_)
  : bot_(std::move(bot_))
  , id_(id_)
{}

const std::int32_t messages_getPreparedInlineMessage::ID;

void messages_getPreparedInlineMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2055291464);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(id_, s);
}

void messages_getPreparedInlineMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2055291464);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(id_, s);
}

void messages_getPreparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPreparedInlineMessage");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

messages_getPreparedInlineMessage::ReturnType messages_getPreparedInlineMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_preparedInlineMessage>, -11046771>::parse(p);
#undef FAIL
}

messages_getSavedDialogs::messages_getSavedDialogs(int32 flags_, bool exclude_pinned_, object_ptr<InputPeer> &&parent_peer_, int32 offset_date_, int32 offset_id_, object_ptr<InputPeer> &&offset_peer_, int32 limit_, int64 hash_)
  : flags_(flags_)
  , exclude_pinned_(exclude_pinned_)
  , parent_peer_(std::move(parent_peer_))
  , offset_date_(offset_date_)
  , offset_id_(offset_id_)
  , offset_peer_(std::move(offset_peer_))
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_getSavedDialogs::ID;

void messages_getSavedDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(512883865);
  TlStoreBinary::store((var0 = flags_ | (exclude_pinned_ << 0)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(512883865);
  TlStoreBinary::store((var0 = flags_ | (exclude_pinned_ << 0)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSavedDialogs");
    s.store_field("flags", (var0 = flags_ | (exclude_pinned_ << 0)));
    if (var0 & 1) { s.store_field("exclude_pinned", true); }
    if (var0 & 2) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_field("offset_date", offset_date_);
    s.store_field("offset_id", offset_id_);
    s.store_object_field("offset_peer", static_cast<const BaseObject *>(offset_peer_.get()));
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getSavedDialogs::ReturnType messages_getSavedDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SavedDialogs>::parse(p);
#undef FAIL
}

messages_getUnreadMentions::messages_getUnreadMentions(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_, int32 offset_id_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
  , offset_id_(offset_id_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
{}

const std::int32_t messages_getUnreadMentions::ID;

void messages_getUnreadMentions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-251140208);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
}

void messages_getUnreadMentions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-251140208);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
}

void messages_getUnreadMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getUnreadMentions");
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

messages_getUnreadMentions::ReturnType messages_getUnreadMentions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_importChatInvite::messages_importChatInvite(string const &hash_)
  : hash_(hash_)
{}

const std::int32_t messages_importChatInvite::ID;

void messages_importChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1817183516);
  TlStoreString::store(hash_, s);
}

void messages_importChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1817183516);
  TlStoreString::store(hash_, s);
}

void messages_importChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.importChatInvite");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_importChatInvite::ReturnType messages_importChatInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_readReactions::messages_readReactions(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_, object_ptr<InputPeer> &&saved_peer_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
  , saved_peer_id_(std::move(saved_peer_id_))
{}

const std::int32_t messages_readReactions::ID;

void messages_readReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1631301741);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
}

void messages_readReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1631301741);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
}

void messages_readReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readReactions");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_class_end();
  }
}

messages_readReactions::ReturnType messages_readReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_reportReadMetrics::messages_reportReadMetrics(object_ptr<InputPeer> &&peer_, array<object_ptr<inputMessageReadMetric>> &&metrics_)
  : peer_(std::move(peer_))
  , metrics_(std::move(metrics_))
{}

const std::int32_t messages_reportReadMetrics::ID;

void messages_reportReadMetrics::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1080542694);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1076577429>>, 481674261>::store(metrics_, s);
}

void messages_reportReadMetrics::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1080542694);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1076577429>>, 481674261>::store(metrics_, s);
}

void messages_reportReadMetrics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportReadMetrics");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("metrics", metrics_.size()); for (const auto &_value : metrics_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reportReadMetrics::ReturnType messages_reportReadMetrics::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_searchEmojiStickerSets::messages_searchEmojiStickerSets(int32 flags_, bool exclude_featured_, string const &q_, int64 hash_)
  : flags_(flags_)
  , exclude_featured_(exclude_featured_)
  , q_(q_)
  , hash_(hash_)
{}

const std::int32_t messages_searchEmojiStickerSets::ID;

void messages_searchEmojiStickerSets::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1833678516);
  TlStoreBinary::store((var0 = flags_ | (exclude_featured_ << 0)), s);
  TlStoreString::store(q_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchEmojiStickerSets::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1833678516);
  TlStoreBinary::store((var0 = flags_ | (exclude_featured_ << 0)), s);
  TlStoreString::store(q_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_searchEmojiStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchEmojiStickerSets");
    s.store_field("flags", (var0 = flags_ | (exclude_featured_ << 0)));
    if (var0 & 1) { s.store_field("exclude_featured", true); }
    s.store_field("q", q_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_searchEmojiStickerSets::ReturnType messages_searchEmojiStickerSets::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FoundStickerSets>::parse(p);
#undef FAIL
}

messages_sendReaction::messages_sendReaction(int32 flags_, bool big_, bool add_to_recent_, object_ptr<InputPeer> &&peer_, int32 msg_id_, array<object_ptr<Reaction>> &&reaction_)
  : flags_(flags_)
  , big_(big_)
  , add_to_recent_(add_to_recent_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , reaction_(std::move(reaction_))
{}

const std::int32_t messages_sendReaction::ID;

void messages_sendReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-754091820);
  TlStoreBinary::store((var0 = flags_ | (big_ << 1) | (add_to_recent_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(reaction_, s); }
}

void messages_sendReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-754091820);
  TlStoreBinary::store((var0 = flags_ | (big_ << 1) | (add_to_recent_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(reaction_, s); }
}

void messages_sendReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendReaction");
    s.store_field("flags", (var0 = flags_ | (big_ << 1) | (add_to_recent_ << 2)));
    if (var0 & 2) { s.store_field("big", true); }
    if (var0 & 4) { s.store_field("add_to_recent", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    if (var0 & 1) { { s.store_vector_begin("reaction", reaction_.size()); for (const auto &_value : reaction_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

messages_sendReaction::ReturnType messages_sendReaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setBotCallbackAnswer::messages_setBotCallbackAnswer(int32 flags_, bool alert_, int64 query_id_, string const &message_, string const &url_, int32 cache_time_)
  : flags_(flags_)
  , alert_(alert_)
  , query_id_(query_id_)
  , message_(message_)
  , url_(url_)
  , cache_time_(cache_time_)
{}

const std::int32_t messages_setBotCallbackAnswer::ID;

void messages_setBotCallbackAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-712043766);
  TlStoreBinary::store((var0 = flags_ | (alert_ << 1)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(message_, s); }
  if (var0 & 4) { TlStoreString::store(url_, s); }
  TlStoreBinary::store(cache_time_, s);
}

void messages_setBotCallbackAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-712043766);
  TlStoreBinary::store((var0 = flags_ | (alert_ << 1)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(message_, s); }
  if (var0 & 4) { TlStoreString::store(url_, s); }
  TlStoreBinary::store(cache_time_, s);
}

void messages_setBotCallbackAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setBotCallbackAnswer");
    s.store_field("flags", (var0 = flags_ | (alert_ << 1)));
    if (var0 & 2) { s.store_field("alert", true); }
    s.store_field("query_id", query_id_);
    if (var0 & 1) { s.store_field("message", message_); }
    if (var0 & 4) { s.store_field("url", url_); }
    s.store_field("cache_time", cache_time_);
    s.store_class_end();
  }
}

messages_setBotCallbackAnswer::ReturnType messages_setBotCallbackAnswer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_setEncryptedTyping::messages_setEncryptedTyping(object_ptr<inputEncryptedChat> &&peer_, bool typing_)
  : peer_(std::move(peer_))
  , typing_(typing_)
{}

const std::int32_t messages_setEncryptedTyping::ID;

void messages_setEncryptedTyping::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2031374829);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBool::store(typing_, s);
}

void messages_setEncryptedTyping::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2031374829);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBool::store(typing_, s);
}

void messages_setEncryptedTyping::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setEncryptedTyping");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("typing", typing_);
    s.store_class_end();
  }
}

messages_setEncryptedTyping::ReturnType messages_setEncryptedTyping::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_toggleBotInAttachMenu::messages_toggleBotInAttachMenu(int32 flags_, bool write_allowed_, object_ptr<InputUser> &&bot_, bool enabled_)
  : flags_(flags_)
  , write_allowed_(write_allowed_)
  , bot_(std::move(bot_))
  , enabled_(enabled_)
{}

const std::int32_t messages_toggleBotInAttachMenu::ID;

void messages_toggleBotInAttachMenu::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1777704297);
  TlStoreBinary::store((var0 = flags_ | (write_allowed_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBool::store(enabled_, s);
}

void messages_toggleBotInAttachMenu::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1777704297);
  TlStoreBinary::store((var0 = flags_ | (write_allowed_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBool::store(enabled_, s);
}

void messages_toggleBotInAttachMenu::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleBotInAttachMenu");
    s.store_field("flags", (var0 = flags_ | (write_allowed_ << 0)));
    if (var0 & 1) { s.store_field("write_allowed", true); }
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

messages_toggleBotInAttachMenu::ReturnType messages_toggleBotInAttachMenu::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_togglePaidReactionPrivacy::messages_togglePaidReactionPrivacy(object_ptr<InputPeer> &&peer_, int32 msg_id_, object_ptr<PaidReactionPrivacy> &&private_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , private_(std::move(private_))
{}

const std::int32_t messages_togglePaidReactionPrivacy::ID;

void messages_togglePaidReactionPrivacy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1129874869);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(private_, s);
}

void messages_togglePaidReactionPrivacy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1129874869);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(private_, s);
}

void messages_togglePaidReactionPrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.togglePaidReactionPrivacy");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_object_field("private", static_cast<const BaseObject *>(private_.get()));
    s.store_class_end();
  }
}

messages_togglePaidReactionPrivacy::ReturnType messages_togglePaidReactionPrivacy::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_togglePeerTranslations::messages_togglePeerTranslations(int32 flags_, bool disabled_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , disabled_(disabled_)
  , peer_(std::move(peer_))
{}

const std::int32_t messages_togglePeerTranslations::ID;

void messages_togglePeerTranslations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-461589127);
  TlStoreBinary::store((var0 = flags_ | (disabled_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_togglePeerTranslations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-461589127);
  TlStoreBinary::store((var0 = flags_ | (disabled_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_togglePeerTranslations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.togglePeerTranslations");
    s.store_field("flags", (var0 = flags_ | (disabled_ << 0)));
    if (var0 & 1) { s.store_field("disabled", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_togglePeerTranslations::ReturnType messages_togglePeerTranslations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_transcribeAudio::messages_transcribeAudio(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t messages_transcribeAudio::ID;

void messages_transcribeAudio::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(647928393);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_transcribeAudio::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(647928393);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_transcribeAudio::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.transcribeAudio");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

messages_transcribeAudio::ReturnType messages_transcribeAudio::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_transcribedAudio>, -809903785>::parse(p);
#undef FAIL
}

messages_uninstallStickerSet::messages_uninstallStickerSet(object_ptr<InputStickerSet> &&stickerset_)
  : stickerset_(std::move(stickerset_))
{}

const std::int32_t messages_uninstallStickerSet::ID;

void messages_uninstallStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-110209570);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void messages_uninstallStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-110209570);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
}

void messages_uninstallStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.uninstallStickerSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_class_end();
  }
}

messages_uninstallStickerSet::ReturnType messages_uninstallStickerSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_updatePinnedForumTopic::messages_updatePinnedForumTopic(object_ptr<InputPeer> &&peer_, int32 topic_id_, bool pinned_)
  : peer_(std::move(peer_))
  , topic_id_(topic_id_)
  , pinned_(pinned_)
{}

const std::int32_t messages_updatePinnedForumTopic::ID;

void messages_updatePinnedForumTopic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(392032849);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(topic_id_, s);
  TlStoreBool::store(pinned_, s);
}

void messages_updatePinnedForumTopic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(392032849);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(topic_id_, s);
  TlStoreBool::store(pinned_, s);
}

void messages_updatePinnedForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.updatePinnedForumTopic");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("topic_id", topic_id_);
    s.store_field("pinned", pinned_);
    s.store_class_end();
  }
}

messages_updatePinnedForumTopic::ReturnType messages_updatePinnedForumTopic::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_applyGiftCode::payments_applyGiftCode(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t payments_applyGiftCode::ID;

void payments_applyGiftCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-152934316);
  TlStoreString::store(slug_, s);
}

void payments_applyGiftCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-152934316);
  TlStoreString::store(slug_, s);
}

void payments_applyGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.applyGiftCode");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

payments_applyGiftCode::ReturnType payments_applyGiftCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_assignAppStoreTransaction::payments_assignAppStoreTransaction(bytes &&receipt_, object_ptr<InputStorePaymentPurpose> &&purpose_)
  : receipt_(std::move(receipt_))
  , purpose_(std::move(purpose_))
{}

const std::int32_t payments_assignAppStoreTransaction::ID;

void payments_assignAppStoreTransaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2131921795);
  TlStoreString::store(receipt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_assignAppStoreTransaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2131921795);
  TlStoreString::store(receipt_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_assignAppStoreTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.assignAppStoreTransaction");
    s.store_bytes_field("receipt", receipt_);
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

payments_assignAppStoreTransaction::ReturnType payments_assignAppStoreTransaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_canPurchaseStore::payments_canPurchaseStore(object_ptr<InputStorePaymentPurpose> &&purpose_)
  : purpose_(std::move(purpose_))
{}

const std::int32_t payments_canPurchaseStore::ID;

void payments_canPurchaseStore::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1339842215);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_canPurchaseStore::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1339842215);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_canPurchaseStore::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.canPurchaseStore");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

payments_canPurchaseStore::ReturnType payments_canPurchaseStore::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_changeStarsSubscription::payments_changeStarsSubscription(int32 flags_, object_ptr<InputPeer> &&peer_, string const &subscription_id_, bool canceled_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , subscription_id_(subscription_id_)
  , canceled_(canceled_)
{}

const std::int32_t payments_changeStarsSubscription::ID;

void payments_changeStarsSubscription::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-948500360);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(subscription_id_, s);
  if (var0 & 1) { TlStoreBool::store(canceled_, s); }
}

void payments_changeStarsSubscription::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-948500360);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(subscription_id_, s);
  if (var0 & 1) { TlStoreBool::store(canceled_, s); }
}

void payments_changeStarsSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.changeStarsSubscription");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("subscription_id", subscription_id_);
    if (var0 & 1) { s.store_field("canceled", canceled_); }
    s.store_class_end();
  }
}

payments_changeStarsSubscription::ReturnType payments_changeStarsSubscription::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_clearSavedInfo::payments_clearSavedInfo(int32 flags_, bool credentials_, bool info_)
  : flags_(flags_)
  , credentials_(credentials_)
  , info_(info_)
{}

const std::int32_t payments_clearSavedInfo::ID;

void payments_clearSavedInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-667062079);
  TlStoreBinary::store((var0 = flags_ | (credentials_ << 0) | (info_ << 1)), s);
}

void payments_clearSavedInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-667062079);
  TlStoreBinary::store((var0 = flags_ | (credentials_ << 0) | (info_ << 1)), s);
}

void payments_clearSavedInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.clearSavedInfo");
    s.store_field("flags", (var0 = flags_ | (credentials_ << 0) | (info_ << 1)));
    if (var0 & 1) { s.store_field("credentials", true); }
    if (var0 & 2) { s.store_field("info", true); }
    s.store_class_end();
  }
}

payments_clearSavedInfo::ReturnType payments_clearSavedInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_getStarGiftActiveAuctions::payments_getStarGiftActiveAuctions(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t payments_getStarGiftActiveAuctions::ID;

void payments_getStarGiftActiveAuctions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1513074355);
  TlStoreBinary::store(hash_, s);
}

void payments_getStarGiftActiveAuctions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1513074355);
  TlStoreBinary::store(hash_, s);
}

void payments_getStarGiftActiveAuctions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftActiveAuctions");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

payments_getStarGiftActiveAuctions::ReturnType payments_getStarGiftActiveAuctions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_StarGiftActiveAuctions>::parse(p);
#undef FAIL
}

payments_getStarGiftUpgradePreview::payments_getStarGiftUpgradePreview(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t payments_getStarGiftUpgradePreview::ID;

void payments_getStarGiftUpgradePreview::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1667580751);
  TlStoreBinary::store(gift_id_, s);
}

void payments_getStarGiftUpgradePreview::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1667580751);
  TlStoreBinary::store(gift_id_, s);
}

void payments_getStarGiftUpgradePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftUpgradePreview");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

payments_getStarGiftUpgradePreview::ReturnType payments_getStarGiftUpgradePreview::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftUpgradePreview>, 1038213101>::parse(p);
#undef FAIL
}

payments_getStarGifts::payments_getStarGifts(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t payments_getStarGifts::ID;

void payments_getStarGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1000983152);
  TlStoreBinary::store(hash_, s);
}

void payments_getStarGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1000983152);
  TlStoreBinary::store(hash_, s);
}

void payments_getStarGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGifts");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

payments_getStarGifts::ReturnType payments_getStarGifts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_StarGifts>::parse(p);
#undef FAIL
}

payments_getStarsGiftOptions::payments_getStarsGiftOptions(int32 flags_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , user_id_(std::move(user_id_))
{}

const std::int32_t payments_getStarsGiftOptions::ID;

void payments_getStarsGiftOptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-741774392);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s); }
}

void payments_getStarsGiftOptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-741774392);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s); }
}

void payments_getStarsGiftOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsGiftOptions");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get())); }
    s.store_class_end();
  }
}

payments_getStarsGiftOptions::ReturnType payments_getStarsGiftOptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starsGiftOption>, 1577421297>>, 481674261>::parse(p);
#undef FAIL
}

phone_deleteConferenceCallParticipants::phone_deleteConferenceCallParticipants(int32 flags_, bool only_left_, bool kick_, object_ptr<InputGroupCall> &&call_, array<int64> &&ids_, bytes &&block_)
  : flags_(flags_)
  , only_left_(only_left_)
  , kick_(kick_)
  , call_(std::move(call_))
  , ids_(std::move(ids_))
  , block_(std::move(block_))
{}

const std::int32_t phone_deleteConferenceCallParticipants::ID;

void phone_deleteConferenceCallParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1935276763);
  TlStoreBinary::store((var0 = flags_ | (only_left_ << 0) | (kick_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(ids_, s);
  TlStoreString::store(block_, s);
}

void phone_deleteConferenceCallParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1935276763);
  TlStoreBinary::store((var0 = flags_ | (only_left_ << 0) | (kick_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(ids_, s);
  TlStoreString::store(block_, s);
}

void phone_deleteConferenceCallParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.deleteConferenceCallParticipants");
    s.store_field("flags", (var0 = flags_ | (only_left_ << 0) | (kick_ << 1)));
    if (var0 & 1) { s.store_field("only_left", true); }
    if (var0 & 2) { s.store_field("kick", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("ids", ids_.size()); for (const auto &_value : ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_bytes_field("block", block_);
    s.store_class_end();
  }
}

phone_deleteConferenceCallParticipants::ReturnType phone_deleteConferenceCallParticipants::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_getGroupCallJoinAs::phone_getGroupCallJoinAs(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t phone_getGroupCallJoinAs::ID;

void phone_getGroupCallJoinAs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-277077702);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void phone_getGroupCallJoinAs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-277077702);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void phone_getGroupCallJoinAs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupCallJoinAs");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

phone_getGroupCallJoinAs::ReturnType phone_getGroupCallJoinAs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_joinAsPeers>, -1343921601>::parse(p);
#undef FAIL
}

phone_getGroupCallStreamChannels::phone_getGroupCallStreamChannels(object_ptr<InputGroupCall> &&call_)
  : call_(std::move(call_))
{}

const std::int32_t phone_getGroupCallStreamChannels::ID;

void phone_getGroupCallStreamChannels::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(447879488);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_getGroupCallStreamChannels::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(447879488);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
}

void phone_getGroupCallStreamChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupCallStreamChannels");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

phone_getGroupCallStreamChannels::ReturnType phone_getGroupCallStreamChannels::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_groupCallStreamChannels>, -790330702>::parse(p);
#undef FAIL
}

phone_inviteToGroupCall::phone_inviteToGroupCall(object_ptr<InputGroupCall> &&call_, array<object_ptr<InputUser>> &&users_)
  : call_(std::move(call_))
  , users_(std::move(users_))
{}

const std::int32_t phone_inviteToGroupCall::ID;

void phone_inviteToGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2067345760);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void phone_inviteToGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2067345760);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
}

void phone_inviteToGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.inviteToGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

phone_inviteToGroupCall::ReturnType phone_inviteToGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_requestCall::phone_requestCall(int32 flags_, bool video_, object_ptr<InputUser> &&user_id_, int32 random_id_, bytes &&g_a_hash_, object_ptr<phoneCallProtocol> &&protocol_)
  : flags_(flags_)
  , video_(video_)
  , user_id_(std::move(user_id_))
  , random_id_(random_id_)
  , g_a_hash_(std::move(g_a_hash_))
  , protocol_(std::move(protocol_))
{}

const std::int32_t phone_requestCall::ID;

void phone_requestCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1124046573);
  TlStoreBinary::store((var0 = flags_ | (video_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(g_a_hash_, s);
  TlStoreBoxed<TlStoreObject, -58224696>::store(protocol_, s);
}

void phone_requestCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1124046573);
  TlStoreBinary::store((var0 = flags_ | (video_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(g_a_hash_, s);
  TlStoreBoxed<TlStoreObject, -58224696>::store(protocol_, s);
}

void phone_requestCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.requestCall");
    s.store_field("flags", (var0 = flags_ | (video_ << 0)));
    if (var0 & 1) { s.store_field("video", true); }
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("random_id", random_id_);
    s.store_bytes_field("g_a_hash", g_a_hash_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

phone_requestCall::ReturnType phone_requestCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_phoneCall>, -326966976>::parse(p);
#undef FAIL
}

phone_sendGroupCallEncryptedMessage::phone_sendGroupCallEncryptedMessage(object_ptr<InputGroupCall> &&call_, bytes &&encrypted_message_)
  : call_(std::move(call_))
  , encrypted_message_(std::move(encrypted_message_))
{}

const std::int32_t phone_sendGroupCallEncryptedMessage::ID;

void phone_sendGroupCallEncryptedMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-441473683);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreString::store(encrypted_message_, s);
}

void phone_sendGroupCallEncryptedMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-441473683);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreString::store(encrypted_message_, s);
}

void phone_sendGroupCallEncryptedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.sendGroupCallEncryptedMessage");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_bytes_field("encrypted_message", encrypted_message_);
    s.store_class_end();
  }
}

phone_sendGroupCallEncryptedMessage::ReturnType phone_sendGroupCallEncryptedMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_sendSignalingData::phone_sendSignalingData(object_ptr<inputPhoneCall> &&peer_, bytes &&data_)
  : peer_(std::move(peer_))
  , data_(std::move(data_))
{}

const std::int32_t phone_sendSignalingData::ID;

void phone_sendSignalingData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-8744061);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreString::store(data_, s);
}

void phone_sendSignalingData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-8744061);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreString::store(data_, s);
}

void phone_sendSignalingData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.sendSignalingData");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

phone_sendSignalingData::ReturnType phone_sendSignalingData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_toggleGroupCallStartSubscription::phone_toggleGroupCallStartSubscription(object_ptr<InputGroupCall> &&call_, bool subscribed_)
  : call_(std::move(call_))
  , subscribed_(subscribed_)
{}

const std::int32_t phone_toggleGroupCallStartSubscription::ID;

void phone_toggleGroupCallStartSubscription::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(563885286);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBool::store(subscribed_, s);
}

void phone_toggleGroupCallStartSubscription::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(563885286);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBool::store(subscribed_, s);
}

void phone_toggleGroupCallStartSubscription::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.toggleGroupCallStartSubscription");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("subscribed", subscribed_);
    s.store_class_end();
  }
}

phone_toggleGroupCallStartSubscription::ReturnType phone_toggleGroupCallStartSubscription::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

photos_uploadProfilePhoto::photos_uploadProfilePhoto(int32 flags_, bool fallback_, object_ptr<InputUser> &&bot_, object_ptr<InputFile> &&file_, object_ptr<InputFile> &&video_, double video_start_ts_, object_ptr<VideoSize> &&video_emoji_markup_)
  : flags_(flags_)
  , fallback_(fallback_)
  , bot_(std::move(bot_))
  , file_(std::move(file_))
  , video_(std::move(video_))
  , video_start_ts_(video_start_ts_)
  , video_emoji_markup_(std::move(video_emoji_markup_))
{}

const std::int32_t photos_uploadProfilePhoto::ID;

void photos_uploadProfilePhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(59286453);
  TlStoreBinary::store((var0 = flags_ | (fallback_ << 3)), s);
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(file_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(video_emoji_markup_, s); }
}

void photos_uploadProfilePhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(59286453);
  TlStoreBinary::store((var0 = flags_ | (fallback_ << 3)), s);
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(file_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
  if (var0 & 4) { TlStoreBinary::store(video_start_ts_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(video_emoji_markup_, s); }
}

void photos_uploadProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.uploadProfilePhoto");
    s.store_field("flags", (var0 = flags_ | (fallback_ << 3)));
    if (var0 & 8) { s.store_field("fallback", true); }
    if (var0 & 32) { s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get())); }
    if (var0 & 1) { s.store_object_field("file", static_cast<const BaseObject *>(file_.get())); }
    if (var0 & 2) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    if (var0 & 4) { s.store_field("video_start_ts", video_start_ts_); }
    if (var0 & 16) { s.store_object_field("video_emoji_markup", static_cast<const BaseObject *>(video_emoji_markup_.get())); }
    s.store_class_end();
  }
}

photos_uploadProfilePhoto::ReturnType photos_uploadProfilePhoto::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<photos_photo>, 539045032>::parse(p);
#undef FAIL
}

stats_getBroadcastStats::stats_getBroadcastStats(int32 flags_, bool dark_, object_ptr<InputChannel> &&channel_)
  : flags_(flags_)
  , dark_(dark_)
  , channel_(std::move(channel_))
{}

const std::int32_t stats_getBroadcastStats::ID;

void stats_getBroadcastStats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1421720550);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void stats_getBroadcastStats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1421720550);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void stats_getBroadcastStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getBroadcastStats");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0)));
    if (var0 & 1) { s.store_field("dark", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

stats_getBroadcastStats::ReturnType stats_getBroadcastStats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_broadcastStats>, 963421692>::parse(p);
#undef FAIL
}

stickers_addStickerToSet::stickers_addStickerToSet(object_ptr<InputStickerSet> &&stickerset_, object_ptr<inputStickerSetItem> &&sticker_)
  : stickerset_(std::move(stickerset_))
  , sticker_(std::move(sticker_))
{}

const std::int32_t stickers_addStickerToSet::ID;

void stickers_addStickerToSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2041315650);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBoxed<TlStoreObject, 853188252>::store(sticker_, s);
}

void stickers_addStickerToSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2041315650);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBoxed<TlStoreObject, 853188252>::store(sticker_, s);
}

void stickers_addStickerToSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.addStickerToSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

stickers_addStickerToSet::ReturnType stickers_addStickerToSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stories_searchPosts::stories_searchPosts(int32 flags_, string const &hashtag_, object_ptr<MediaArea> &&area_, object_ptr<InputPeer> &&peer_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , hashtag_(hashtag_)
  , area_(std::move(area_))
  , peer_(std::move(peer_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t stories_searchPosts::ID;

void stories_searchPosts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-780072697);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(hashtag_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(area_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_searchPosts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-780072697);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(hashtag_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(area_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_searchPosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.searchPosts");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("hashtag", hashtag_); }
    if (var0 & 2) { s.store_object_field("area", static_cast<const BaseObject *>(area_.get())); }
    if (var0 & 4) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stories_searchPosts::ReturnType stories_searchPosts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_foundStories>, -488736969>::parse(p);
#undef FAIL
}

stories_togglePinned::stories_togglePinned(object_ptr<InputPeer> &&peer_, array<int32> &&id_, bool pinned_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
  , pinned_(pinned_)
{}

const std::int32_t stories_togglePinned::ID;

void stories_togglePinned::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1703566865);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBool::store(pinned_, s);
}

void stories_togglePinned::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1703566865);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBool::store(pinned_, s);
}

void stories_togglePinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.togglePinned");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("pinned", pinned_);
    s.store_class_end();
  }
}

stories_togglePinned::ReturnType stories_togglePinned::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
#undef FAIL
}

stories_updateAlbum::stories_updateAlbum(int32 flags_, object_ptr<InputPeer> &&peer_, int32 album_id_, string const &title_, array<int32> &&delete_stories_, array<int32> &&add_stories_, array<int32> &&order_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , album_id_(album_id_)
  , title_(title_)
  , delete_stories_(std::move(delete_stories_))
  , add_stories_(std::move(add_stories_))
  , order_(std::move(order_))
{}

const std::int32_t stories_updateAlbum::ID;

void stories_updateAlbum::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1582455222);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(album_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(delete_stories_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(add_stories_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s); }
}

void stories_updateAlbum::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1582455222);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(album_id_, s);
  if (var0 & 1) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(delete_stories_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(add_stories_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s); }
}

void stories_updateAlbum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.updateAlbum");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("album_id", album_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { { s.store_vector_begin("delete_stories", delete_stories_.size()); for (const auto &_value : delete_stories_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("add_stories", add_stories_.size()); for (const auto &_value : add_stories_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 8) { { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

stories_updateAlbum::ReturnType stories_updateAlbum::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<storyAlbum>, -1826262950>::parse(p);
#undef FAIL
}

const std::int32_t test_useConfigSimple::ID;

void test_useConfigSimple::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-105401795);
}

void test_useConfigSimple::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-105401795);
}

void test_useConfigSimple::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "test.useConfigSimple");
    s.store_class_end();
  }
}

test_useConfigSimple::ReturnType test_useConfigSimple::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<help_configSimple>, 1515793004>::parse(p);
#undef FAIL
}

upload_getFileHashes::upload_getFileHashes(object_ptr<InputFileLocation> &&location_, int64 offset_)
  : location_(std::move(location_))
  , offset_(offset_)
{}

const std::int32_t upload_getFileHashes::ID;

void upload_getFileHashes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1856595926);
  TlStoreBoxedUnknown<TlStoreObject>::store(location_, s);
  TlStoreBinary::store(offset_, s);
}

void upload_getFileHashes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1856595926);
  TlStoreBoxedUnknown<TlStoreObject>::store(location_, s);
  TlStoreBinary::store(offset_, s);
}

void upload_getFileHashes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.getFileHashes");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

upload_getFileHashes::ReturnType upload_getFileHashes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<fileHash>, -207944868>>, 481674261>::parse(p);
#undef FAIL
}

users_getSavedMusicByID::users_getSavedMusicByID(object_ptr<InputUser> &&id_, array<object_ptr<InputDocument>> &&documents_)
  : id_(std::move(id_))
  , documents_(std::move(documents_))
{}

const std::int32_t users_getSavedMusicByID::ID;

void users_getSavedMusicByID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1970513129);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s);
}

void users_getSavedMusicByID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1970513129);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s);
}

void users_getSavedMusicByID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.getSavedMusicByID");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

users_getSavedMusicByID::ReturnType users_getSavedMusicByID::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<users_SavedMusic>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
