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

std::string to_string(const BaseObject &value) {
  TlStorerToString storer;
  value.store(storer, "");
  return storer.move_as_string();
}

authorization::authorization()
  : flags_()
  , current_()
  , official_app_()
  , password_pending_()
  , encrypted_requests_disabled_()
  , call_requests_disabled_()
  , unconfirmed_()
  , hash_()
  , device_model_()
  , platform_()
  , system_version_()
  , api_id_()
  , app_name_()
  , app_version_()
  , date_created_()
  , date_active_()
  , ip_()
  , country_()
  , region_()
{}

const std::int32_t authorization::ID;

object_ptr<authorization> authorization::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<authorization> res = make_tl_object<authorization>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->current_ = (var0 & 1) != 0;
  res->official_app_ = (var0 & 2) != 0;
  res->password_pending_ = (var0 & 4) != 0;
  res->encrypted_requests_disabled_ = (var0 & 8) != 0;
  res->call_requests_disabled_ = (var0 & 16) != 0;
  res->unconfirmed_ = (var0 & 32) != 0;
  res->hash_ = TlFetchLong::parse(p);
  res->device_model_ = TlFetchString<string>::parse(p);
  res->platform_ = TlFetchString<string>::parse(p);
  res->system_version_ = TlFetchString<string>::parse(p);
  res->api_id_ = TlFetchInt::parse(p);
  res->app_name_ = TlFetchString<string>::parse(p);
  res->app_version_ = TlFetchString<string>::parse(p);
  res->date_created_ = TlFetchInt::parse(p);
  res->date_active_ = TlFetchInt::parse(p);
  res->ip_ = TlFetchString<string>::parse(p);
  res->country_ = TlFetchString<string>::parse(p);
  res->region_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void authorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "authorization");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (current_ << 0) | (official_app_ << 1) | (password_pending_ << 2) | (encrypted_requests_disabled_ << 3) | (call_requests_disabled_ << 4) | (unconfirmed_ << 5)));
    if (var0 & 1) { s.store_field("current", true); }
    if (var0 & 2) { s.store_field("official_app", true); }
    if (var0 & 4) { s.store_field("password_pending", true); }
    if (var0 & 8) { s.store_field("encrypted_requests_disabled", true); }
    if (var0 & 16) { s.store_field("call_requests_disabled", true); }
    if (var0 & 32) { s.store_field("unconfirmed", true); }
    s.store_field("hash", hash_);
    s.store_field("device_model", device_model_);
    s.store_field("platform", platform_);
    s.store_field("system_version", system_version_);
    s.store_field("api_id", api_id_);
    s.store_field("app_name", app_name_);
    s.store_field("app_version", app_version_);
    s.store_field("date_created", date_created_);
    s.store_field("date_active", date_active_);
    s.store_field("ip", ip_);
    s.store_field("country", country_);
    s.store_field("region", region_);
    s.store_class_end();
  }
}

const std::int32_t bankCardOpenUrl::ID;

object_ptr<bankCardOpenUrl> bankCardOpenUrl::fetch(TlBufferParser &p) {
  return make_tl_object<bankCardOpenUrl>(p);
}

bankCardOpenUrl::bankCardOpenUrl(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , name_(TlFetchString<string>::parse(p))
{}

void bankCardOpenUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bankCardOpenUrl");
    s.store_field("url", url_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

const std::int32_t botVerification::ID;

object_ptr<botVerification> botVerification::fetch(TlBufferParser &p) {
  return make_tl_object<botVerification>(p);
}

botVerification::botVerification(TlBufferParser &p)
  : bot_id_(TlFetchLong::parse(p))
  , icon_(TlFetchLong::parse(p))
  , description_(TlFetchString<string>::parse(p))
{}

void botVerification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botVerification");
    s.store_field("bot_id", bot_id_);
    s.store_field("icon", icon_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

const std::int32_t businessGreetingMessage::ID;

object_ptr<businessGreetingMessage> businessGreetingMessage::fetch(TlBufferParser &p) {
  return make_tl_object<businessGreetingMessage>(p);
}

businessGreetingMessage::businessGreetingMessage(TlBufferParser &p)
  : shortcut_id_(TlFetchInt::parse(p))
  , recipients_(TlFetchBoxed<TlFetchObject<businessRecipients>, 554733559>::parse(p))
  , no_activity_days_(TlFetchInt::parse(p))
{}

void businessGreetingMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessGreetingMessage");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_field("no_activity_days", no_activity_days_);
    s.store_class_end();
  }
}

object_ptr<ChatTheme> ChatTheme::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatTheme::ID:
      return chatTheme::fetch(p);
    case chatThemeUniqueGift::ID:
      return chatThemeUniqueGift::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t chatTheme::ID;

object_ptr<ChatTheme> chatTheme::fetch(TlBufferParser &p) {
  return make_tl_object<chatTheme>(p);
}

chatTheme::chatTheme(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
{}

void chatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatTheme");
    s.store_field("emoticon", emoticon_);
    s.store_class_end();
  }
}

const std::int32_t chatThemeUniqueGift::ID;

object_ptr<ChatTheme> chatThemeUniqueGift::fetch(TlBufferParser &p) {
  return make_tl_object<chatThemeUniqueGift>(p);
}

chatThemeUniqueGift::chatThemeUniqueGift(TlBufferParser &p)
  : gift_(TlFetchObject<StarGift>::parse(p))
  , theme_settings_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<themeSettings>, -94849324>>, 481674261>::parse(p))
{}

void chatThemeUniqueGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatThemeUniqueGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    { s.store_vector_begin("theme_settings", theme_settings_.size()); for (const auto &_value : theme_settings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t emojiKeywordsDifference::ID;

object_ptr<emojiKeywordsDifference> emojiKeywordsDifference::fetch(TlBufferParser &p) {
  return make_tl_object<emojiKeywordsDifference>(p);
}

emojiKeywordsDifference::emojiKeywordsDifference(TlBufferParser &p)
  : lang_code_(TlFetchString<string>::parse(p))
  , from_version_(TlFetchInt::parse(p))
  , version_(TlFetchInt::parse(p))
  , keywords_(TlFetchBoxed<TlFetchVector<TlFetchObject<EmojiKeyword>>, 481674261>::parse(p))
{}

void emojiKeywordsDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiKeywordsDifference");
    s.store_field("lang_code", lang_code_);
    s.store_field("from_version", from_version_);
    s.store_field("version", version_);
    { s.store_vector_begin("keywords", keywords_.size()); for (const auto &_value : keywords_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<EmojiStatus> EmojiStatus::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case emojiStatusEmpty::ID:
      return emojiStatusEmpty::fetch(p);
    case emojiStatus::ID:
      return emojiStatus::fetch(p);
    case emojiStatusCollectible::ID:
      return emojiStatusCollectible::fetch(p);
    case inputEmojiStatusCollectible::ID:
      return inputEmojiStatusCollectible::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t emojiStatusEmpty::ID;

object_ptr<EmojiStatus> emojiStatusEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<emojiStatusEmpty>();
}

void emojiStatusEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void emojiStatusEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void emojiStatusEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatusEmpty");
    s.store_class_end();
  }
}

emojiStatus::emojiStatus()
  : flags_()
  , document_id_()
  , until_()
{}

emojiStatus::emojiStatus(int32 flags_, int64 document_id_, int32 until_)
  : flags_(flags_)
  , document_id_(document_id_)
  , until_(until_)
{}

const std::int32_t emojiStatus::ID;

object_ptr<EmojiStatus> emojiStatus::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<emojiStatus> res = make_tl_object<emojiStatus>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->document_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->until_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void emojiStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(document_id_, s);
  if (var0 & 1) { TlStoreBinary::store(until_, s); }
}

void emojiStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(document_id_, s);
  if (var0 & 1) { TlStoreBinary::store(until_, s); }
}

void emojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatus");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("document_id", document_id_);
    if (var0 & 1) { s.store_field("until", until_); }
    s.store_class_end();
  }
}

emojiStatusCollectible::emojiStatusCollectible()
  : flags_()
  , collectible_id_()
  , document_id_()
  , title_()
  , slug_()
  , pattern_document_id_()
  , center_color_()
  , edge_color_()
  , pattern_color_()
  , text_color_()
  , until_()
{}

emojiStatusCollectible::emojiStatusCollectible(int32 flags_, int64 collectible_id_, int64 document_id_, string const &title_, string const &slug_, int64 pattern_document_id_, int32 center_color_, int32 edge_color_, int32 pattern_color_, int32 text_color_, int32 until_)
  : flags_(flags_)
  , collectible_id_(collectible_id_)
  , document_id_(document_id_)
  , title_(title_)
  , slug_(slug_)
  , pattern_document_id_(pattern_document_id_)
  , center_color_(center_color_)
  , edge_color_(edge_color_)
  , pattern_color_(pattern_color_)
  , text_color_(text_color_)
  , until_(until_)
{}

const std::int32_t emojiStatusCollectible::ID;

object_ptr<EmojiStatus> emojiStatusCollectible::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<emojiStatusCollectible> res = make_tl_object<emojiStatusCollectible>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collectible_id_ = TlFetchLong::parse(p);
  res->document_id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->slug_ = TlFetchString<string>::parse(p);
  res->pattern_document_id_ = TlFetchLong::parse(p);
  res->center_color_ = TlFetchInt::parse(p);
  res->edge_color_ = TlFetchInt::parse(p);
  res->pattern_color_ = TlFetchInt::parse(p);
  res->text_color_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->until_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void emojiStatusCollectible::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(collectible_id_, s);
  TlStoreBinary::store(document_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(pattern_document_id_, s);
  TlStoreBinary::store(center_color_, s);
  TlStoreBinary::store(edge_color_, s);
  TlStoreBinary::store(pattern_color_, s);
  TlStoreBinary::store(text_color_, s);
  if (var0 & 1) { TlStoreBinary::store(until_, s); }
}

void emojiStatusCollectible::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(collectible_id_, s);
  TlStoreBinary::store(document_id_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(slug_, s);
  TlStoreBinary::store(pattern_document_id_, s);
  TlStoreBinary::store(center_color_, s);
  TlStoreBinary::store(edge_color_, s);
  TlStoreBinary::store(pattern_color_, s);
  TlStoreBinary::store(text_color_, s);
  if (var0 & 1) { TlStoreBinary::store(until_, s); }
}

void emojiStatusCollectible::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiStatusCollectible");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("collectible_id", collectible_id_);
    s.store_field("document_id", document_id_);
    s.store_field("title", title_);
    s.store_field("slug", slug_);
    s.store_field("pattern_document_id", pattern_document_id_);
    s.store_field("center_color", center_color_);
    s.store_field("edge_color", edge_color_);
    s.store_field("pattern_color", pattern_color_);
    s.store_field("text_color", text_color_);
    if (var0 & 1) { s.store_field("until", until_); }
    s.store_class_end();
  }
}

inputEmojiStatusCollectible::inputEmojiStatusCollectible()
  : flags_()
  , collectible_id_()
  , until_()
{}

inputEmojiStatusCollectible::inputEmojiStatusCollectible(int32 flags_, int64 collectible_id_, int32 until_)
  : flags_(flags_)
  , collectible_id_(collectible_id_)
  , until_(until_)
{}

const std::int32_t inputEmojiStatusCollectible::ID;

object_ptr<EmojiStatus> inputEmojiStatusCollectible::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputEmojiStatusCollectible> res = make_tl_object<inputEmojiStatusCollectible>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collectible_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->until_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputEmojiStatusCollectible::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(collectible_id_, s);
  if (var0 & 1) { TlStoreBinary::store(until_, s); }
}

void inputEmojiStatusCollectible::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(collectible_id_, s);
  if (var0 & 1) { TlStoreBinary::store(until_, s); }
}

void inputEmojiStatusCollectible::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEmojiStatusCollectible");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("collectible_id", collectible_id_);
    if (var0 & 1) { s.store_field("until", until_); }
    s.store_class_end();
  }
}

object_ptr<EncryptedMessage> EncryptedMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case encryptedMessage::ID:
      return encryptedMessage::fetch(p);
    case encryptedMessageService::ID:
      return encryptedMessageService::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t encryptedMessage::ID;

object_ptr<EncryptedMessage> encryptedMessage::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedMessage>(p);
}

encryptedMessage::encryptedMessage(TlBufferParser &p)
  : random_id_(TlFetchLong::parse(p))
  , chat_id_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
  , file_(TlFetchObject<EncryptedFile>::parse(p))
{}

void encryptedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedMessage");
    s.store_field("random_id", random_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("date", date_);
    s.store_bytes_field("bytes", bytes_);
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

const std::int32_t encryptedMessageService::ID;

object_ptr<EncryptedMessage> encryptedMessageService::fetch(TlBufferParser &p) {
  return make_tl_object<encryptedMessageService>(p);
}

encryptedMessageService::encryptedMessageService(TlBufferParser &p)
  : random_id_(TlFetchLong::parse(p))
  , chat_id_(TlFetchInt::parse(p))
  , date_(TlFetchInt::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void encryptedMessageService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "encryptedMessageService");
    s.store_field("random_id", random_id_);
    s.store_field("chat_id", chat_id_);
    s.store_field("date", date_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

const std::int32_t error::ID;

object_ptr<error> error::fetch(TlBufferParser &p) {
  return make_tl_object<error>(p);
}

error::error(TlBufferParser &p)
  : code_(TlFetchInt::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void error::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "error");
    s.store_field("code", code_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

const std::int32_t exportedContactToken::ID;

object_ptr<exportedContactToken> exportedContactToken::fetch(TlBufferParser &p) {
  return make_tl_object<exportedContactToken>(p);
}

exportedContactToken::exportedContactToken(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , expires_(TlFetchInt::parse(p))
{}

void exportedContactToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "exportedContactToken");
    s.store_field("url", url_);
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

geoPointAddress::geoPointAddress()
  : flags_()
  , country_iso2_()
  , state_()
  , city_()
  , street_()
{}

geoPointAddress::geoPointAddress(int32 flags_, string const &country_iso2_, string const &state_, string const &city_, string const &street_)
  : flags_(flags_)
  , country_iso2_(country_iso2_)
  , state_(state_)
  , city_(city_)
  , street_(street_)
{}

const std::int32_t geoPointAddress::ID;

object_ptr<geoPointAddress> geoPointAddress::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<geoPointAddress> res = make_tl_object<geoPointAddress>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->country_iso2_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->state_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->city_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->street_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void geoPointAddress::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(country_iso2_, s);
  if (var0 & 1) { TlStoreString::store(state_, s); }
  if (var0 & 2) { TlStoreString::store(city_, s); }
  if (var0 & 4) { TlStoreString::store(street_, s); }
}

void geoPointAddress::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(country_iso2_, s);
  if (var0 & 1) { TlStoreString::store(state_, s); }
  if (var0 & 2) { TlStoreString::store(city_, s); }
  if (var0 & 4) { TlStoreString::store(street_, s); }
}

void geoPointAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "geoPointAddress");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("country_iso2", country_iso2_);
    if (var0 & 1) { s.store_field("state", state_); }
    if (var0 & 2) { s.store_field("city", city_); }
    if (var0 & 4) { s.store_field("street", street_); }
    s.store_class_end();
  }
}

groupCallParticipant::groupCallParticipant()
  : flags_()
  , muted_()
  , left_()
  , can_self_unmute_()
  , just_joined_()
  , versioned_()
  , min_()
  , muted_by_you_()
  , volume_by_admin_()
  , self_()
  , video_joined_()
  , peer_()
  , date_()
  , active_date_()
  , source_()
  , volume_()
  , about_()
  , raise_hand_rating_()
  , video_()
  , presentation_()
  , paid_stars_total_()
{}

const std::int32_t groupCallParticipant::ID;

object_ptr<groupCallParticipant> groupCallParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<groupCallParticipant> res = make_tl_object<groupCallParticipant>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->muted_ = (var0 & 1) != 0;
  res->left_ = (var0 & 2) != 0;
  res->can_self_unmute_ = (var0 & 4) != 0;
  res->just_joined_ = (var0 & 16) != 0;
  res->versioned_ = (var0 & 32) != 0;
  res->min_ = (var0 & 256) != 0;
  res->muted_by_you_ = (var0 & 512) != 0;
  res->volume_by_admin_ = (var0 & 1024) != 0;
  res->self_ = (var0 & 4096) != 0;
  res->video_joined_ = (var0 & 32768) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->active_date_ = TlFetchInt::parse(p); }
  res->source_ = TlFetchInt::parse(p);
  if (var0 & 128) { res->volume_ = TlFetchInt::parse(p); }
  if (var0 & 2048) { res->about_ = TlFetchString<string>::parse(p); }
  if (var0 & 8192) { res->raise_hand_rating_ = TlFetchLong::parse(p); }
  if (var0 & 64) { res->video_ = TlFetchBoxed<TlFetchObject<groupCallParticipantVideo>, 1735736008>::parse(p); }
  if (var0 & 16384) { res->presentation_ = TlFetchBoxed<TlFetchObject<groupCallParticipantVideo>, 1735736008>::parse(p); }
  if (var0 & 65536) { res->paid_stars_total_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void groupCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipant");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (muted_ << 0) | (left_ << 1) | (can_self_unmute_ << 2) | (just_joined_ << 4) | (versioned_ << 5) | (min_ << 8) | (muted_by_you_ << 9) | (volume_by_admin_ << 10) | (self_ << 12) | (video_joined_ << 15)));
    if (var0 & 1) { s.store_field("muted", true); }
    if (var0 & 2) { s.store_field("left", true); }
    if (var0 & 4) { s.store_field("can_self_unmute", true); }
    if (var0 & 16) { s.store_field("just_joined", true); }
    if (var0 & 32) { s.store_field("versioned", true); }
    if (var0 & 256) { s.store_field("min", true); }
    if (var0 & 512) { s.store_field("muted_by_you", true); }
    if (var0 & 1024) { s.store_field("volume_by_admin", true); }
    if (var0 & 4096) { s.store_field("self", true); }
    if (var0 & 32768) { s.store_field("video_joined", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("date", date_);
    if (var0 & 8) { s.store_field("active_date", active_date_); }
    s.store_field("source", source_);
    if (var0 & 128) { s.store_field("volume", volume_); }
    if (var0 & 2048) { s.store_field("about", about_); }
    if (var0 & 8192) { s.store_field("raise_hand_rating", raise_hand_rating_); }
    if (var0 & 64) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    if (var0 & 16384) { s.store_object_field("presentation", static_cast<const BaseObject *>(presentation_.get())); }
    if (var0 & 65536) { s.store_field("paid_stars_total", paid_stars_total_); }
    s.store_class_end();
  }
}

const std::int32_t importedContact::ID;

object_ptr<importedContact> importedContact::fetch(TlBufferParser &p) {
  return make_tl_object<importedContact>(p);
}

importedContact::importedContact(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , client_id_(TlFetchLong::parse(p))
{}

void importedContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "importedContact");
    s.store_field("user_id", user_id_);
    s.store_field("client_id", client_id_);
    s.store_class_end();
  }
}

object_ptr<InputChannel> InputChannel::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputChannelEmpty::ID:
      return inputChannelEmpty::fetch(p);
    case inputChannel::ID:
      return inputChannel::fetch(p);
    case inputChannelFromMessage::ID:
      return inputChannelFromMessage::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputChannelEmpty::ID;

object_ptr<InputChannel> inputChannelEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputChannelEmpty>();
}

void inputChannelEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputChannelEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputChannelEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChannelEmpty");
    s.store_class_end();
  }
}

inputChannel::inputChannel(int64 channel_id_, int64 access_hash_)
  : channel_id_(channel_id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputChannel::ID;

object_ptr<InputChannel> inputChannel::fetch(TlBufferParser &p) {
  return make_tl_object<inputChannel>(p);
}

inputChannel::inputChannel(TlBufferParser &p)
  : channel_id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(channel_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(channel_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChannel");
    s.store_field("channel_id", channel_id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputChannelFromMessage::inputChannelFromMessage(object_ptr<InputPeer> &&peer_, int32 msg_id_, int64 channel_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , channel_id_(channel_id_)
{}

const std::int32_t inputChannelFromMessage::ID;

object_ptr<InputChannel> inputChannelFromMessage::fetch(TlBufferParser &p) {
  return make_tl_object<inputChannelFromMessage>(p);
}

inputChannelFromMessage::inputChannelFromMessage(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , channel_id_(TlFetchLong::parse(p))
{}

void inputChannelFromMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(channel_id_, s);
}

void inputChannelFromMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(channel_id_, s);
}

void inputChannelFromMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChannelFromMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("channel_id", channel_id_);
    s.store_class_end();
  }
}

inputCollectibleUsername::inputCollectibleUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t inputCollectibleUsername::ID;

void inputCollectibleUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(username_, s);
}

void inputCollectibleUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(username_, s);
}

void inputCollectibleUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCollectibleUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

inputCollectiblePhone::inputCollectiblePhone(string const &phone_)
  : phone_(phone_)
{}

const std::int32_t inputCollectiblePhone::ID;

void inputCollectiblePhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_, s);
}

void inputCollectiblePhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_, s);
}

void inputCollectiblePhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCollectiblePhone");
    s.store_field("phone", phone_);
    s.store_class_end();
  }
}

inputPhoneContact::inputPhoneContact(int32 flags_, int64 client_id_, string const &phone_, string const &first_name_, string const &last_name_, object_ptr<textWithEntities> &&note_)
  : flags_(flags_)
  , client_id_(client_id_)
  , phone_(phone_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , note_(std::move(note_))
{}

const std::int32_t inputPhoneContact::ID;

void inputPhoneContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(client_id_, s);
  TlStoreString::store(phone_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 1964978502>::store(note_, s); }
}

void inputPhoneContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(client_id_, s);
  TlStoreString::store(phone_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 1964978502>::store(note_, s); }
}

void inputPhoneContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhoneContact");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("client_id", client_id_);
    s.store_field("phone", phone_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    if (var0 & 1) { s.store_object_field("note", static_cast<const BaseObject *>(note_.get())); }
    s.store_class_end();
  }
}

object_ptr<InputFile> InputFile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputFile::ID:
      return inputFile::fetch(p);
    case inputFileBig::ID:
      return inputFileBig::fetch(p);
    case inputFileStoryDocument::ID:
      return inputFileStoryDocument::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputFile::inputFile(int64 id_, int32 parts_, string const &name_, string const &md5_checksum_)
  : id_(id_)
  , parts_(parts_)
  , name_(name_)
  , md5_checksum_(md5_checksum_)
{}

const std::int32_t inputFile::ID;

object_ptr<InputFile> inputFile::fetch(TlBufferParser &p) {
  return make_tl_object<inputFile>(p);
}

inputFile::inputFile(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , parts_(TlFetchInt::parse(p))
  , name_(TlFetchString<string>::parse(p))
  , md5_checksum_(TlFetchString<string>::parse(p))
{}

void inputFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(name_, s);
  TlStoreString::store(md5_checksum_, s);
}

void inputFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(name_, s);
  TlStoreString::store(md5_checksum_, s);
}

void inputFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFile");
    s.store_field("id", id_);
    s.store_field("parts", parts_);
    s.store_field("name", name_);
    s.store_field("md5_checksum", md5_checksum_);
    s.store_class_end();
  }
}

inputFileBig::inputFileBig(int64 id_, int32 parts_, string const &name_)
  : id_(id_)
  , parts_(parts_)
  , name_(name_)
{}

const std::int32_t inputFileBig::ID;

object_ptr<InputFile> inputFileBig::fetch(TlBufferParser &p) {
  return make_tl_object<inputFileBig>(p);
}

inputFileBig::inputFileBig(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , parts_(TlFetchInt::parse(p))
  , name_(TlFetchString<string>::parse(p))
{}

void inputFileBig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(name_, s);
}

void inputFileBig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(name_, s);
}

void inputFileBig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileBig");
    s.store_field("id", id_);
    s.store_field("parts", parts_);
    s.store_field("name", name_);
    s.store_class_end();
  }
}

inputFileStoryDocument::inputFileStoryDocument(object_ptr<InputDocument> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t inputFileStoryDocument::ID;

object_ptr<InputFile> inputFileStoryDocument::fetch(TlBufferParser &p) {
  return make_tl_object<inputFileStoryDocument>(p);
}

inputFileStoryDocument::inputFileStoryDocument(TlBufferParser &p)
  : id_(TlFetchObject<InputDocument>::parse(p))
{}

void inputFileStoryDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputFileStoryDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputFileStoryDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFileStoryDocument");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

inputPasskeyResponseRegister::inputPasskeyResponseRegister(object_ptr<dataJSON> &&client_data_, bytes &&attestation_data_)
  : client_data_(std::move(client_data_))
  , attestation_data_(std::move(attestation_data_))
{}

const std::int32_t inputPasskeyResponseRegister::ID;

void inputPasskeyResponseRegister::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(client_data_, s);
  TlStoreString::store(attestation_data_, s);
}

void inputPasskeyResponseRegister::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(client_data_, s);
  TlStoreString::store(attestation_data_, s);
}

void inputPasskeyResponseRegister::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPasskeyResponseRegister");
    s.store_object_field("client_data", static_cast<const BaseObject *>(client_data_.get()));
    s.store_bytes_field("attestation_data", attestation_data_);
    s.store_class_end();
  }
}

inputPasskeyResponseLogin::inputPasskeyResponseLogin(object_ptr<dataJSON> &&client_data_, bytes &&authenticator_data_, bytes &&signature_, string const &user_handle_)
  : client_data_(std::move(client_data_))
  , authenticator_data_(std::move(authenticator_data_))
  , signature_(std::move(signature_))
  , user_handle_(user_handle_)
{}

const std::int32_t inputPasskeyResponseLogin::ID;

void inputPasskeyResponseLogin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(client_data_, s);
  TlStoreString::store(authenticator_data_, s);
  TlStoreString::store(signature_, s);
  TlStoreString::store(user_handle_, s);
}

void inputPasskeyResponseLogin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(client_data_, s);
  TlStoreString::store(authenticator_data_, s);
  TlStoreString::store(signature_, s);
  TlStoreString::store(user_handle_, s);
}

void inputPasskeyResponseLogin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPasskeyResponseLogin");
    s.store_object_field("client_data", static_cast<const BaseObject *>(client_data_.get()));
    s.store_bytes_field("authenticator_data", authenticator_data_);
    s.store_bytes_field("signature", signature_);
    s.store_field("user_handle", user_handle_);
    s.store_class_end();
  }
}

object_ptr<InputPhoto> InputPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputPhotoEmpty::ID:
      return inputPhotoEmpty::fetch(p);
    case inputPhoto::ID:
      return inputPhoto::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputPhotoEmpty::ID;

object_ptr<InputPhoto> inputPhotoEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputPhotoEmpty>();
}

void inputPhotoEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputPhotoEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputPhotoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhotoEmpty");
    s.store_class_end();
  }
}

inputPhoto::inputPhoto(int64 id_, int64 access_hash_, bytes &&file_reference_)
  : id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
{}

const std::int32_t inputPhoto::ID;

object_ptr<InputPhoto> inputPhoto::fetch(TlBufferParser &p) {
  return make_tl_object<inputPhoto>(p);
}

inputPhoto::inputPhoto(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , file_reference_(TlFetchBytes<bytes>::parse(p))
{}

void inputPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
}

void inputPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
}

void inputPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPhoto");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_class_end();
  }
}

inputStarsTransaction::inputStarsTransaction(int32 flags_, bool refund_, string const &id_)
  : flags_(flags_)
  , refund_(refund_)
  , id_(id_)
{}

const std::int32_t inputStarsTransaction::ID;

void inputStarsTransaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (refund_ << 0)), s);
  TlStoreString::store(id_, s);
}

void inputStarsTransaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (refund_ << 0)), s);
  TlStoreString::store(id_, s);
}

void inputStarsTransaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStarsTransaction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (refund_ << 0)));
    if (var0 & 1) { s.store_field("refund", true); }
    s.store_field("id", id_);
    s.store_class_end();
  }
}

messageFwdHeader::messageFwdHeader()
  : flags_()
  , imported_()
  , saved_out_()
  , from_id_()
  , from_name_()
  , date_()
  , channel_post_()
  , post_author_()
  , saved_from_peer_()
  , saved_from_msg_id_()
  , saved_from_id_()
  , saved_from_name_()
  , saved_date_()
  , psa_type_()
{}

const std::int32_t messageFwdHeader::ID;

object_ptr<messageFwdHeader> messageFwdHeader::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageFwdHeader> res = make_tl_object<messageFwdHeader>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->imported_ = (var0 & 128) != 0;
  res->saved_out_ = (var0 & 2048) != 0;
  if (var0 & 1) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 32) { res->from_name_ = TlFetchString<string>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->channel_post_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->post_author_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->saved_from_peer_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 16) { res->saved_from_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 256) { res->saved_from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 512) { res->saved_from_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 1024) { res->saved_date_ = TlFetchInt::parse(p); }
  if (var0 & 64) { res->psa_type_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messageFwdHeader::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageFwdHeader");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (imported_ << 7) | (saved_out_ << 11)));
    if (var0 & 128) { s.store_field("imported", true); }
    if (var0 & 2048) { s.store_field("saved_out", true); }
    if (var0 & 1) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 32) { s.store_field("from_name", from_name_); }
    s.store_field("date", date_);
    if (var0 & 4) { s.store_field("channel_post", channel_post_); }
    if (var0 & 8) { s.store_field("post_author", post_author_); }
    if (var0 & 16) { s.store_object_field("saved_from_peer", static_cast<const BaseObject *>(saved_from_peer_.get())); }
    if (var0 & 16) { s.store_field("saved_from_msg_id", saved_from_msg_id_); }
    if (var0 & 256) { s.store_object_field("saved_from_id", static_cast<const BaseObject *>(saved_from_id_.get())); }
    if (var0 & 512) { s.store_field("saved_from_name", saved_from_name_); }
    if (var0 & 1024) { s.store_field("saved_date", saved_date_); }
    if (var0 & 64) { s.store_field("psa_type", psa_type_); }
    s.store_class_end();
  }
}

const std::int32_t outboxReadDate::ID;

object_ptr<outboxReadDate> outboxReadDate::fetch(TlBufferParser &p) {
  return make_tl_object<outboxReadDate>(p);
}

outboxReadDate::outboxReadDate(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
{}

void outboxReadDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "outboxReadDate");
    s.store_field("date", date_);
    s.store_class_end();
  }
}

object_ptr<PhoneCallDiscardReason> PhoneCallDiscardReason::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case phoneCallDiscardReasonMissed::ID:
      return phoneCallDiscardReasonMissed::fetch(p);
    case phoneCallDiscardReasonDisconnect::ID:
      return phoneCallDiscardReasonDisconnect::fetch(p);
    case phoneCallDiscardReasonHangup::ID:
      return phoneCallDiscardReasonHangup::fetch(p);
    case phoneCallDiscardReasonBusy::ID:
      return phoneCallDiscardReasonBusy::fetch(p);
    case phoneCallDiscardReasonMigrateConferenceCall::ID:
      return phoneCallDiscardReasonMigrateConferenceCall::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t phoneCallDiscardReasonMissed::ID;

object_ptr<PhoneCallDiscardReason> phoneCallDiscardReasonMissed::fetch(TlBufferParser &p) {
  return make_tl_object<phoneCallDiscardReasonMissed>();
}

void phoneCallDiscardReasonMissed::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonMissed::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonMissed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallDiscardReasonMissed");
    s.store_class_end();
  }
}

const std::int32_t phoneCallDiscardReasonDisconnect::ID;

object_ptr<PhoneCallDiscardReason> phoneCallDiscardReasonDisconnect::fetch(TlBufferParser &p) {
  return make_tl_object<phoneCallDiscardReasonDisconnect>();
}

void phoneCallDiscardReasonDisconnect::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonDisconnect::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonDisconnect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallDiscardReasonDisconnect");
    s.store_class_end();
  }
}

const std::int32_t phoneCallDiscardReasonHangup::ID;

object_ptr<PhoneCallDiscardReason> phoneCallDiscardReasonHangup::fetch(TlBufferParser &p) {
  return make_tl_object<phoneCallDiscardReasonHangup>();
}

void phoneCallDiscardReasonHangup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonHangup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonHangup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallDiscardReasonHangup");
    s.store_class_end();
  }
}

const std::int32_t phoneCallDiscardReasonBusy::ID;

object_ptr<PhoneCallDiscardReason> phoneCallDiscardReasonBusy::fetch(TlBufferParser &p) {
  return make_tl_object<phoneCallDiscardReasonBusy>();
}

void phoneCallDiscardReasonBusy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonBusy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void phoneCallDiscardReasonBusy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallDiscardReasonBusy");
    s.store_class_end();
  }
}

phoneCallDiscardReasonMigrateConferenceCall::phoneCallDiscardReasonMigrateConferenceCall(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t phoneCallDiscardReasonMigrateConferenceCall::ID;

object_ptr<PhoneCallDiscardReason> phoneCallDiscardReasonMigrateConferenceCall::fetch(TlBufferParser &p) {
  return make_tl_object<phoneCallDiscardReasonMigrateConferenceCall>(p);
}

phoneCallDiscardReasonMigrateConferenceCall::phoneCallDiscardReasonMigrateConferenceCall(TlBufferParser &p)
  : slug_(TlFetchString<string>::parse(p))
{}

void phoneCallDiscardReasonMigrateConferenceCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void phoneCallDiscardReasonMigrateConferenceCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void phoneCallDiscardReasonMigrateConferenceCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallDiscardReasonMigrateConferenceCall");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

postAddress::postAddress(string const &street_line1_, string const &street_line2_, string const &city_, string const &state_, string const &country_iso2_, string const &post_code_)
  : street_line1_(street_line1_)
  , street_line2_(street_line2_)
  , city_(city_)
  , state_(state_)
  , country_iso2_(country_iso2_)
  , post_code_(post_code_)
{}

const std::int32_t postAddress::ID;

object_ptr<postAddress> postAddress::fetch(TlBufferParser &p) {
  return make_tl_object<postAddress>(p);
}

postAddress::postAddress(TlBufferParser &p)
  : street_line1_(TlFetchString<string>::parse(p))
  , street_line2_(TlFetchString<string>::parse(p))
  , city_(TlFetchString<string>::parse(p))
  , state_(TlFetchString<string>::parse(p))
  , country_iso2_(TlFetchString<string>::parse(p))
  , post_code_(TlFetchString<string>::parse(p))
{}

void postAddress::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(street_line1_, s);
  TlStoreString::store(street_line2_, s);
  TlStoreString::store(city_, s);
  TlStoreString::store(state_, s);
  TlStoreString::store(country_iso2_, s);
  TlStoreString::store(post_code_, s);
}

void postAddress::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(street_line1_, s);
  TlStoreString::store(street_line2_, s);
  TlStoreString::store(city_, s);
  TlStoreString::store(state_, s);
  TlStoreString::store(country_iso2_, s);
  TlStoreString::store(post_code_, s);
}

void postAddress::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "postAddress");
    s.store_field("street_line1", street_line1_);
    s.store_field("street_line2", street_line2_);
    s.store_field("city", city_);
    s.store_field("state", state_);
    s.store_field("country_iso2", country_iso2_);
    s.store_field("post_code", post_code_);
    s.store_class_end();
  }
}

object_ptr<RequestedPeer> RequestedPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case requestedPeerUser::ID:
      return requestedPeerUser::fetch(p);
    case requestedPeerChat::ID:
      return requestedPeerChat::fetch(p);
    case requestedPeerChannel::ID:
      return requestedPeerChannel::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

requestedPeerUser::requestedPeerUser()
  : flags_()
  , user_id_()
  , first_name_()
  , last_name_()
  , username_()
  , photo_()
{}

const std::int32_t requestedPeerUser::ID;

object_ptr<RequestedPeer> requestedPeerUser::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestedPeerUser> res = make_tl_object<requestedPeerUser>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->first_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 1) { res->last_name_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->username_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestedPeerUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestedPeerUser");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("user_id", user_id_);
    if (var0 & 1) { s.store_field("first_name", first_name_); }
    if (var0 & 1) { s.store_field("last_name", last_name_); }
    if (var0 & 2) { s.store_field("username", username_); }
    if (var0 & 4) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_class_end();
  }
}

requestedPeerChat::requestedPeerChat()
  : flags_()
  , chat_id_()
  , title_()
  , photo_()
{}

const std::int32_t requestedPeerChat::ID;

object_ptr<RequestedPeer> requestedPeerChat::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestedPeerChat> res = make_tl_object<requestedPeerChat>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->chat_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestedPeerChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestedPeerChat");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("chat_id", chat_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 4) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_class_end();
  }
}

requestedPeerChannel::requestedPeerChannel()
  : flags_()
  , channel_id_()
  , title_()
  , username_()
  , photo_()
{}

const std::int32_t requestedPeerChannel::ID;

object_ptr<RequestedPeer> requestedPeerChannel::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<requestedPeerChannel> res = make_tl_object<requestedPeerChannel>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->channel_id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->title_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->username_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void requestedPeerChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "requestedPeerChannel");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("channel_id", channel_id_);
    if (var0 & 1) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("username", username_); }
    if (var0 & 4) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_class_end();
  }
}

secureData::secureData(bytes &&data_, bytes &&data_hash_, bytes &&secret_)
  : data_(std::move(data_))
  , data_hash_(std::move(data_hash_))
  , secret_(std::move(secret_))
{}

const std::int32_t secureData::ID;

object_ptr<secureData> secureData::fetch(TlBufferParser &p) {
  return make_tl_object<secureData>(p);
}

secureData::secureData(TlBufferParser &p)
  : data_(TlFetchBytes<bytes>::parse(p))
  , data_hash_(TlFetchBytes<bytes>::parse(p))
  , secret_(TlFetchBytes<bytes>::parse(p))
{}

void secureData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(data_, s);
  TlStoreString::store(data_hash_, s);
  TlStoreString::store(secret_, s);
}

void secureData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(data_, s);
  TlStoreString::store(data_hash_, s);
  TlStoreString::store(secret_, s);
}

void secureData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureData");
    s.store_bytes_field("data", data_);
    s.store_bytes_field("data_hash", data_hash_);
    s.store_bytes_field("secret", secret_);
    s.store_class_end();
  }
}

sendAsPeer::sendAsPeer()
  : flags_()
  , premium_required_()
  , peer_()
{}

const std::int32_t sendAsPeer::ID;

object_ptr<sendAsPeer> sendAsPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<sendAsPeer> res = make_tl_object<sendAsPeer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->premium_required_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void sendAsPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendAsPeer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (premium_required_ << 0)));
    if (var0 & 1) { s.store_field("premium_required", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

starsGiftOption::starsGiftOption()
  : flags_()
  , extended_()
  , stars_()
  , store_product_()
  , currency_()
  , amount_()
{}

const std::int32_t starsGiftOption::ID;

object_ptr<starsGiftOption> starsGiftOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsGiftOption> res = make_tl_object<starsGiftOption>();
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

void starsGiftOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsGiftOption");
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

const std::int32_t statsGroupTopAdmin::ID;

object_ptr<statsGroupTopAdmin> statsGroupTopAdmin::fetch(TlBufferParser &p) {
  return make_tl_object<statsGroupTopAdmin>(p);
}

statsGroupTopAdmin::statsGroupTopAdmin(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , deleted_(TlFetchInt::parse(p))
  , kicked_(TlFetchInt::parse(p))
  , banned_(TlFetchInt::parse(p))
{}

void statsGroupTopAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsGroupTopAdmin");
    s.store_field("user_id", user_id_);
    s.store_field("deleted", deleted_);
    s.store_field("kicked", kicked_);
    s.store_field("banned", banned_);
    s.store_class_end();
  }
}

const std::int32_t statsGroupTopInviter::ID;

object_ptr<statsGroupTopInviter> statsGroupTopInviter::fetch(TlBufferParser &p) {
  return make_tl_object<statsGroupTopInviter>(p);
}

statsGroupTopInviter::statsGroupTopInviter(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , invitations_(TlFetchInt::parse(p))
{}

void statsGroupTopInviter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsGroupTopInviter");
    s.store_field("user_id", user_id_);
    s.store_field("invitations", invitations_);
    s.store_class_end();
  }
}

const std::int32_t stickerPack::ID;

object_ptr<stickerPack> stickerPack::fetch(TlBufferParser &p) {
  return make_tl_object<stickerPack>(p);
}

stickerPack::stickerPack(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
  , documents_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void stickerPack::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerPack");
    s.store_field("emoticon", emoticon_);
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<StoryView> StoryView::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case storyView::ID:
      return storyView::fetch(p);
    case storyViewPublicForward::ID:
      return storyViewPublicForward::fetch(p);
    case storyViewPublicRepost::ID:
      return storyViewPublicRepost::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

storyView::storyView()
  : flags_()
  , blocked_()
  , blocked_my_stories_from_()
  , user_id_()
  , date_()
  , reaction_()
{}

const std::int32_t storyView::ID;

object_ptr<StoryView> storyView::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyView> res = make_tl_object<storyView>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->blocked_ = (var0 & 1) != 0;
  res->blocked_my_stories_from_ = (var0 & 2) != 0;
  res->user_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->reaction_ = TlFetchObject<Reaction>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void storyView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyView");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (blocked_ << 0) | (blocked_my_stories_from_ << 1)));
    if (var0 & 1) { s.store_field("blocked", true); }
    if (var0 & 2) { s.store_field("blocked_my_stories_from", true); }
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    if (var0 & 4) { s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get())); }
    s.store_class_end();
  }
}

storyViewPublicForward::storyViewPublicForward()
  : flags_()
  , blocked_()
  , blocked_my_stories_from_()
  , message_()
{}

const std::int32_t storyViewPublicForward::ID;

object_ptr<StoryView> storyViewPublicForward::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyViewPublicForward> res = make_tl_object<storyViewPublicForward>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->blocked_ = (var0 & 1) != 0;
  res->blocked_my_stories_from_ = (var0 & 2) != 0;
  res->message_ = TlFetchObject<Message>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void storyViewPublicForward::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyViewPublicForward");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (blocked_ << 0) | (blocked_my_stories_from_ << 1)));
    if (var0 & 1) { s.store_field("blocked", true); }
    if (var0 & 2) { s.store_field("blocked_my_stories_from", true); }
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

storyViewPublicRepost::storyViewPublicRepost()
  : flags_()
  , blocked_()
  , blocked_my_stories_from_()
  , peer_id_()
  , story_()
{}

const std::int32_t storyViewPublicRepost::ID;

object_ptr<StoryView> storyViewPublicRepost::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyViewPublicRepost> res = make_tl_object<storyViewPublicRepost>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->blocked_ = (var0 & 1) != 0;
  res->blocked_my_stories_from_ = (var0 & 2) != 0;
  res->peer_id_ = TlFetchObject<Peer>::parse(p);
  res->story_ = TlFetchObject<StoryItem>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void storyViewPublicRepost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyViewPublicRepost");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (blocked_ << 0) | (blocked_my_stories_from_ << 1)));
    if (var0 & 1) { s.store_field("blocked", true); }
    if (var0 & 2) { s.store_field("blocked_my_stories_from", true); }
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

const std::int32_t topPeer::ID;

object_ptr<topPeer> topPeer::fetch(TlBufferParser &p) {
  return make_tl_object<topPeer>(p);
}

topPeer::topPeer(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , rating_(TlFetchDouble::parse(p))
{}

void topPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("rating", rating_);
    s.store_class_end();
  }
}

object_ptr<WallPaper> WallPaper::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case wallPaper::ID:
      return wallPaper::fetch(p);
    case wallPaperNoFile::ID:
      return wallPaperNoFile::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

wallPaper::wallPaper()
  : id_()
  , flags_()
  , creator_()
  , default_()
  , pattern_()
  , dark_()
  , access_hash_()
  , slug_()
  , document_()
  , settings_()
{}

wallPaper::wallPaper(int64 id_, int32 flags_, bool creator_, bool default_, bool pattern_, bool dark_, int64 access_hash_, string const &slug_, object_ptr<Document> &&document_, object_ptr<wallPaperSettings> &&settings_)
  : id_(id_)
  , flags_(flags_)
  , creator_(creator_)
  , default_(default_)
  , pattern_(pattern_)
  , dark_(dark_)
  , access_hash_(access_hash_)
  , slug_(slug_)
  , document_(std::move(document_))
  , settings_(std::move(settings_))
{}

const std::int32_t wallPaper::ID;

object_ptr<WallPaper> wallPaper::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<wallPaper> res = make_tl_object<wallPaper>();
  int32 var0;
  res->id_ = TlFetchLong::parse(p);
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  res->default_ = (var0 & 2) != 0;
  res->pattern_ = (var0 & 8) != 0;
  res->dark_ = (var0 & 16) != 0;
  res->access_hash_ = TlFetchLong::parse(p);
  res->slug_ = TlFetchString<string>::parse(p);
  res->document_ = TlFetchObject<Document>::parse(p);
  if (var0 & 4) { res->settings_ = TlFetchBoxed<TlFetchObject<wallPaperSettings>, 925826256>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void wallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (default_ << 1) | (pattern_ << 3) | (dark_ << 4)), s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(slug_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s); }
}

void wallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (default_ << 1) | (pattern_ << 3) | (dark_ << 4)), s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(slug_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(document_, s);
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s); }
}

void wallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallPaper");
  int32 var0;
    s.store_field("id", id_);
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | (default_ << 1) | (pattern_ << 3) | (dark_ << 4)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 2) { s.store_field("default", true); }
    if (var0 & 8) { s.store_field("pattern", true); }
    if (var0 & 16) { s.store_field("dark", true); }
    s.store_field("access_hash", access_hash_);
    s.store_field("slug", slug_);
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    if (var0 & 4) { s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get())); }
    s.store_class_end();
  }
}

wallPaperNoFile::wallPaperNoFile()
  : id_()
  , flags_()
  , default_()
  , dark_()
  , settings_()
{}

wallPaperNoFile::wallPaperNoFile(int64 id_, int32 flags_, bool default_, bool dark_, object_ptr<wallPaperSettings> &&settings_)
  : id_(id_)
  , flags_(flags_)
  , default_(default_)
  , dark_(dark_)
  , settings_(std::move(settings_))
{}

const std::int32_t wallPaperNoFile::ID;

object_ptr<WallPaper> wallPaperNoFile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<wallPaperNoFile> res = make_tl_object<wallPaperNoFile>();
  int32 var0;
  res->id_ = TlFetchLong::parse(p);
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->default_ = (var0 & 2) != 0;
  res->dark_ = (var0 & 16) != 0;
  if (var0 & 4) { res->settings_ = TlFetchBoxed<TlFetchObject<wallPaperSettings>, 925826256>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void wallPaperNoFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store((var0 = flags_ | (default_ << 1) | (dark_ << 4)), s);
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s); }
}

void wallPaperNoFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store((var0 = flags_ | (default_ << 1) | (dark_ << 4)), s);
  if (var0 & 4) { TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s); }
}

void wallPaperNoFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "wallPaperNoFile");
  int32 var0;
    s.store_field("id", id_);
    s.store_field("flags", (var0 = flags_ | (default_ << 1) | (dark_ << 4)));
    if (var0 & 2) { s.store_field("default", true); }
    if (var0 & 16) { s.store_field("dark", true); }
    if (var0 & 4) { s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get())); }
    s.store_class_end();
  }
}

const std::int32_t account_authorizations::ID;

object_ptr<account_authorizations> account_authorizations::fetch(TlBufferParser &p) {
  return make_tl_object<account_authorizations>(p);
}

account_authorizations::account_authorizations(TlBufferParser &p)
  : authorization_ttl_days_(TlFetchInt::parse(p))
  , authorizations_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<authorization>, -1392388579>>, 481674261>::parse(p))
{}

void account_authorizations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.authorizations");
    s.store_field("authorization_ttl_days", authorization_ttl_days_);
    { s.store_vector_begin("authorizations", authorizations_.size()); for (const auto &_value : authorizations_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<account_EmailVerified> account_EmailVerified::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_emailVerified::ID:
      return account_emailVerified::fetch(p);
    case account_emailVerifiedLogin::ID:
      return account_emailVerifiedLogin::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_emailVerified::ID;

object_ptr<account_EmailVerified> account_emailVerified::fetch(TlBufferParser &p) {
  return make_tl_object<account_emailVerified>(p);
}

account_emailVerified::account_emailVerified(TlBufferParser &p)
  : email_(TlFetchString<string>::parse(p))
{}

void account_emailVerified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.emailVerified");
    s.store_field("email", email_);
    s.store_class_end();
  }
}

const std::int32_t account_emailVerifiedLogin::ID;

object_ptr<account_EmailVerified> account_emailVerifiedLogin::fetch(TlBufferParser &p) {
  return make_tl_object<account_emailVerifiedLogin>(p);
}

account_emailVerifiedLogin::account_emailVerifiedLogin(TlBufferParser &p)
  : email_(TlFetchString<string>::parse(p))
  , sent_code_(TlFetchObject<auth_SentCode>::parse(p))
{}

void account_emailVerifiedLogin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.emailVerifiedLogin");
    s.store_field("email", email_);
    s.store_object_field("sent_code", static_cast<const BaseObject *>(sent_code_.get()));
    s.store_class_end();
  }
}

object_ptr<account_SavedRingtone> account_SavedRingtone::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_savedRingtone::ID:
      return account_savedRingtone::fetch(p);
    case account_savedRingtoneConverted::ID:
      return account_savedRingtoneConverted::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_savedRingtone::ID;

object_ptr<account_SavedRingtone> account_savedRingtone::fetch(TlBufferParser &p) {
  return make_tl_object<account_savedRingtone>();
}

void account_savedRingtone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.savedRingtone");
    s.store_class_end();
  }
}

const std::int32_t account_savedRingtoneConverted::ID;

object_ptr<account_SavedRingtone> account_savedRingtoneConverted::fetch(TlBufferParser &p) {
  return make_tl_object<account_savedRingtoneConverted>(p);
}

account_savedRingtoneConverted::account_savedRingtoneConverted(TlBufferParser &p)
  : document_(TlFetchObject<Document>::parse(p))
{}

void account_savedRingtoneConverted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.savedRingtoneConverted");
    s.store_object_field("document", static_cast<const BaseObject *>(document_.get()));
    s.store_class_end();
  }
}

object_ptr<contacts_Contacts> contacts_Contacts::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case contacts_contactsNotModified::ID:
      return contacts_contactsNotModified::fetch(p);
    case contacts_contacts::ID:
      return contacts_contacts::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t contacts_contactsNotModified::ID;

object_ptr<contacts_Contacts> contacts_contactsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_contactsNotModified>();
}

void contacts_contactsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.contactsNotModified");
    s.store_class_end();
  }
}

const std::int32_t contacts_contacts::ID;

object_ptr<contacts_Contacts> contacts_contacts::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_contacts>(p);
}

contacts_contacts::contacts_contacts(TlBufferParser &p)
  : contacts_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<contact>, 341499403>>, 481674261>::parse(p))
  , saved_count_(TlFetchInt::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_contacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.contacts");
    { s.store_vector_begin("contacts", contacts_.size()); for (const auto &_value : contacts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("saved_count", saved_count_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<help_TermsOfServiceUpdate> help_TermsOfServiceUpdate::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_termsOfServiceUpdateEmpty::ID:
      return help_termsOfServiceUpdateEmpty::fetch(p);
    case help_termsOfServiceUpdate::ID:
      return help_termsOfServiceUpdate::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_termsOfServiceUpdateEmpty::ID;

object_ptr<help_TermsOfServiceUpdate> help_termsOfServiceUpdateEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<help_termsOfServiceUpdateEmpty>(p);
}

help_termsOfServiceUpdateEmpty::help_termsOfServiceUpdateEmpty(TlBufferParser &p)
  : expires_(TlFetchInt::parse(p))
{}

void help_termsOfServiceUpdateEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.termsOfServiceUpdateEmpty");
    s.store_field("expires", expires_);
    s.store_class_end();
  }
}

const std::int32_t help_termsOfServiceUpdate::ID;

object_ptr<help_TermsOfServiceUpdate> help_termsOfServiceUpdate::fetch(TlBufferParser &p) {
  return make_tl_object<help_termsOfServiceUpdate>(p);
}

help_termsOfServiceUpdate::help_termsOfServiceUpdate(TlBufferParser &p)
  : expires_(TlFetchInt::parse(p))
  , terms_of_service_(TlFetchBoxed<TlFetchObject<help_termsOfService>, 2013922064>::parse(p))
{}

void help_termsOfServiceUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.termsOfServiceUpdate");
    s.store_field("expires", expires_);
    s.store_object_field("terms_of_service", static_cast<const BaseObject *>(terms_of_service_.get()));
    s.store_class_end();
  }
}

const std::int32_t messages_exportedChatInvites::ID;

object_ptr<messages_exportedChatInvites> messages_exportedChatInvites::fetch(TlBufferParser &p) {
  return make_tl_object<messages_exportedChatInvites>(p);
}

messages_exportedChatInvites::messages_exportedChatInvites(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , invites_(TlFetchBoxed<TlFetchVector<TlFetchObject<ExportedChatInvite>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_exportedChatInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.exportedChatInvites");
    s.store_field("count", count_);
    { s.store_vector_begin("invites", invites_.size()); for (const auto &_value : invites_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_FoundStickers> messages_FoundStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_foundStickersNotModified::ID:
      return messages_foundStickersNotModified::fetch(p);
    case messages_foundStickers::ID:
      return messages_foundStickers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messages_foundStickersNotModified::messages_foundStickersNotModified()
  : flags_()
  , next_offset_()
{}

const std::int32_t messages_foundStickersNotModified::ID;

object_ptr<messages_FoundStickers> messages_foundStickersNotModified::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_foundStickersNotModified> res = make_tl_object<messages_foundStickersNotModified>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->next_offset_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_foundStickersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.foundStickersNotModified");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

messages_foundStickers::messages_foundStickers()
  : flags_()
  , next_offset_()
  , hash_()
  , stickers_()
{}

const std::int32_t messages_foundStickers::ID;

object_ptr<messages_FoundStickers> messages_foundStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_foundStickers> res = make_tl_object<messages_foundStickers>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->next_offset_ = TlFetchInt::parse(p); }
  res->hash_ = TlFetchLong::parse(p);
  res->stickers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_foundStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.foundStickers");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_field("hash", hash_);
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_messageReactionsList::messages_messageReactionsList()
  : flags_()
  , count_()
  , reactions_()
  , chats_()
  , users_()
  , next_offset_()
{}

const std::int32_t messages_messageReactionsList::ID;

object_ptr<messages_messageReactionsList> messages_messageReactionsList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_messageReactionsList> res = make_tl_object<messages_messageReactionsList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->reactions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messagePeerReaction>, -1938180548>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_messageReactionsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.messageReactionsList");
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

const std::int32_t payments_starGiftAuctionAcquiredGifts::ID;

object_ptr<payments_starGiftAuctionAcquiredGifts> payments_starGiftAuctionAcquiredGifts::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftAuctionAcquiredGifts>(p);
}

payments_starGiftAuctionAcquiredGifts::payments_starGiftAuctionAcquiredGifts(TlBufferParser &p)
  : gifts_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starGiftAuctionAcquiredGift>, 1118831432>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
{}

void payments_starGiftAuctionAcquiredGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftAuctionAcquiredGifts");
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_suggestedStarRefBots::payments_suggestedStarRefBots()
  : flags_()
  , count_()
  , suggested_bots_()
  , users_()
  , next_offset_()
{}

const std::int32_t payments_suggestedStarRefBots::ID;

object_ptr<payments_suggestedStarRefBots> payments_suggestedStarRefBots::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_suggestedStarRefBots> res = make_tl_object<payments_suggestedStarRefBots>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->suggested_bots_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starRefProgram>, -586389774>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_suggestedStarRefBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.suggestedStarRefBots");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("count", count_);
    { s.store_vector_begin("suggested_bots", suggested_bots_.size()); for (const auto &_value : suggested_bots_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

const std::int32_t phone_exportedGroupCallInvite::ID;

object_ptr<phone_exportedGroupCallInvite> phone_exportedGroupCallInvite::fetch(TlBufferParser &p) {
  return make_tl_object<phone_exportedGroupCallInvite>(p);
}

phone_exportedGroupCallInvite::phone_exportedGroupCallInvite(TlBufferParser &p)
  : link_(TlFetchString<string>::parse(p))
{}

void phone_exportedGroupCallInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.exportedGroupCallInvite");
    s.store_field("link", link_);
    s.store_class_end();
  }
}

object_ptr<photos_Photos> photos_Photos::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case photos_photos::ID:
      return photos_photos::fetch(p);
    case photos_photosSlice::ID:
      return photos_photosSlice::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t photos_photos::ID;

object_ptr<photos_Photos> photos_photos::fetch(TlBufferParser &p) {
  return make_tl_object<photos_photos>(p);
}

photos_photos::photos_photos(TlBufferParser &p)
  : photos_(TlFetchBoxed<TlFetchVector<TlFetchObject<Photo>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void photos_photos::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.photos");
    { s.store_vector_begin("photos", photos_.size()); for (const auto &_value : photos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t photos_photosSlice::ID;

object_ptr<photos_Photos> photos_photosSlice::fetch(TlBufferParser &p) {
  return make_tl_object<photos_photosSlice>(p);
}

photos_photosSlice::photos_photosSlice(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , photos_(TlFetchBoxed<TlFetchVector<TlFetchObject<Photo>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void photos_photosSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.photosSlice");
    s.store_field("count", count_);
    { s.store_vector_begin("photos", photos_.size()); for (const auto &_value : photos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t upload_webFile::ID;

object_ptr<upload_webFile> upload_webFile::fetch(TlBufferParser &p) {
  return make_tl_object<upload_webFile>(p);
}

upload_webFile::upload_webFile(TlBufferParser &p)
  : size_(TlFetchInt::parse(p))
  , mime_type_(TlFetchString<string>::parse(p))
  , file_type_(TlFetchObject<storage_FileType>::parse(p))
  , mtime_(TlFetchInt::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void upload_webFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.webFile");
    s.store_field("size", size_);
    s.store_field("mime_type", mime_type_);
    s.store_object_field("file_type", static_cast<const BaseObject *>(file_type_.get()));
    s.store_field("mtime", mtime_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

account_changeAuthorizationSettings::account_changeAuthorizationSettings(int32 flags_, bool confirmed_, int64 hash_, bool encrypted_requests_disabled_, bool call_requests_disabled_)
  : flags_(flags_)
  , confirmed_(confirmed_)
  , hash_(hash_)
  , encrypted_requests_disabled_(encrypted_requests_disabled_)
  , call_requests_disabled_(call_requests_disabled_)
{}

const std::int32_t account_changeAuthorizationSettings::ID;

void account_changeAuthorizationSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1089766498);
  TlStoreBinary::store((var0 = flags_ | (confirmed_ << 3)), s);
  TlStoreBinary::store(hash_, s);
  if (var0 & 1) { TlStoreBool::store(encrypted_requests_disabled_, s); }
  if (var0 & 2) { TlStoreBool::store(call_requests_disabled_, s); }
}

void account_changeAuthorizationSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1089766498);
  TlStoreBinary::store((var0 = flags_ | (confirmed_ << 3)), s);
  TlStoreBinary::store(hash_, s);
  if (var0 & 1) { TlStoreBool::store(encrypted_requests_disabled_, s); }
  if (var0 & 2) { TlStoreBool::store(call_requests_disabled_, s); }
}

void account_changeAuthorizationSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.changeAuthorizationSettings");
    s.store_field("flags", (var0 = flags_ | (confirmed_ << 3)));
    if (var0 & 8) { s.store_field("confirmed", true); }
    s.store_field("hash", hash_);
    if (var0 & 1) { s.store_field("encrypted_requests_disabled", encrypted_requests_disabled_); }
    if (var0 & 2) { s.store_field("call_requests_disabled", call_requests_disabled_); }
    s.store_class_end();
  }
}

account_changeAuthorizationSettings::ReturnType account_changeAuthorizationSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_confirmPhone::account_confirmPhone(string const &phone_code_hash_, string const &phone_code_)
  : phone_code_hash_(phone_code_hash_)
  , phone_code_(phone_code_)
{}

const std::int32_t account_confirmPhone::ID;

void account_confirmPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1596029123);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(phone_code_, s);
}

void account_confirmPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1596029123);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(phone_code_, s);
}

void account_confirmPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.confirmPhone");
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("phone_code", phone_code_);
    s.store_class_end();
  }
}

account_confirmPhone::ReturnType account_confirmPhone::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_deleteBusinessChatLink::account_deleteBusinessChatLink(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t account_deleteBusinessChatLink::ID;

void account_deleteBusinessChatLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1611085428);
  TlStoreString::store(slug_, s);
}

void account_deleteBusinessChatLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1611085428);
  TlStoreString::store(slug_, s);
}

void account_deleteBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.deleteBusinessChatLink");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

account_deleteBusinessChatLink::ReturnType account_deleteBusinessChatLink::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_getBusinessChatLinks::ID;

void account_getBusinessChatLinks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1869667809);
}

void account_getBusinessChatLinks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1869667809);
}

void account_getBusinessChatLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getBusinessChatLinks");
    s.store_class_end();
  }
}

account_getBusinessChatLinks::ReturnType account_getBusinessChatLinks::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_businessChatLinks>, -331111727>::parse(p);
#undef FAIL
}

const std::int32_t account_getConnectedBots::ID;

void account_getConnectedBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1319421967);
}

void account_getConnectedBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1319421967);
}

void account_getConnectedBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getConnectedBots");
    s.store_class_end();
  }
}

account_getConnectedBots::ReturnType account_getConnectedBots::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_connectedBots>, 400029819>::parse(p);
#undef FAIL
}

account_getDefaultEmojiStatuses::account_getDefaultEmojiStatuses(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getDefaultEmojiStatuses::ID;

void account_getDefaultEmojiStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-696962170);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultEmojiStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-696962170);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getDefaultEmojiStatuses");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getDefaultEmojiStatuses::ReturnType account_getDefaultEmojiStatuses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_EmojiStatuses>::parse(p);
#undef FAIL
}

account_getSecureValue::account_getSecureValue(array<object_ptr<SecureValueType>> &&types_)
  : types_(std::move(types_))
{}

const std::int32_t account_getSecureValue::ID;

void account_getSecureValue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1936088002);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(types_, s);
}

void account_getSecureValue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1936088002);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(types_, s);
}

void account_getSecureValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getSecureValue");
    { s.store_vector_begin("types", types_.size()); for (const auto &_value : types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_getSecureValue::ReturnType account_getSecureValue::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<secureValue>, 411017418>>, 481674261>::parse(p);
#undef FAIL
}

account_saveSecureValue::account_saveSecureValue(object_ptr<inputSecureValue> &&value_, int64 secure_secret_id_)
  : value_(std::move(value_))
  , secure_secret_id_(secure_secret_id_)
{}

const std::int32_t account_saveSecureValue::ID;

void account_saveSecureValue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1986010339);
  TlStoreBoxed<TlStoreObject, -618540889>::store(value_, s);
  TlStoreBinary::store(secure_secret_id_, s);
}

void account_saveSecureValue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1986010339);
  TlStoreBoxed<TlStoreObject, -618540889>::store(value_, s);
  TlStoreBinary::store(secure_secret_id_, s);
}

void account_saveSecureValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveSecureValue");
    s.store_object_field("value", static_cast<const BaseObject *>(value_.get()));
    s.store_field("secure_secret_id", secure_secret_id_);
    s.store_class_end();
  }
}

account_saveSecureValue::ReturnType account_saveSecureValue::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<secureValue>, 411017418>::parse(p);
#undef FAIL
}

account_sendVerifyEmailCode::account_sendVerifyEmailCode(object_ptr<EmailVerifyPurpose> &&purpose_, string const &email_)
  : purpose_(std::move(purpose_))
  , email_(email_)
{}

const std::int32_t account_sendVerifyEmailCode::ID;

void account_sendVerifyEmailCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1730136133);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
  TlStoreString::store(email_, s);
}

void account_sendVerifyEmailCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1730136133);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
  TlStoreString::store(email_, s);
}

void account_sendVerifyEmailCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.sendVerifyEmailCode");
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_field("email", email_);
    s.store_class_end();
  }
}

account_sendVerifyEmailCode::ReturnType account_sendVerifyEmailCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_sentEmailCode>, -2128640689>::parse(p);
#undef FAIL
}

account_sendVerifyPhoneCode::account_sendVerifyPhoneCode(string const &phone_number_, object_ptr<codeSettings> &&settings_)
  : phone_number_(phone_number_)
  , settings_(std::move(settings_))
{}

const std::int32_t account_sendVerifyPhoneCode::ID;

void account_sendVerifyPhoneCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1516022023);
  TlStoreString::store(phone_number_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void account_sendVerifyPhoneCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1516022023);
  TlStoreString::store(phone_number_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void account_sendVerifyPhoneCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.sendVerifyPhoneCode");
    s.store_field("phone_number", phone_number_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_sendVerifyPhoneCode::ReturnType account_sendVerifyPhoneCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

account_setContactSignUpNotification::account_setContactSignUpNotification(bool silent_)
  : silent_(silent_)
{}

const std::int32_t account_setContactSignUpNotification::ID;

void account_setContactSignUpNotification::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-806076575);
  TlStoreBool::store(silent_, s);
}

void account_setContactSignUpNotification::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-806076575);
  TlStoreBool::store(silent_, s);
}

void account_setContactSignUpNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setContactSignUpNotification");
    s.store_field("silent", silent_);
    s.store_class_end();
  }
}

account_setContactSignUpNotification::ReturnType account_setContactSignUpNotification::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_toggleConnectedBotPaused::account_toggleConnectedBotPaused(object_ptr<InputPeer> &&peer_, bool paused_)
  : peer_(std::move(peer_))
  , paused_(paused_)
{}

const std::int32_t account_toggleConnectedBotPaused::ID;

void account_toggleConnectedBotPaused::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1684934807);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(paused_, s);
}

void account_toggleConnectedBotPaused::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1684934807);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBool::store(paused_, s);
}

void account_toggleConnectedBotPaused::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.toggleConnectedBotPaused");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("paused", paused_);
    s.store_class_end();
  }
}

account_toggleConnectedBotPaused::ReturnType account_toggleConnectedBotPaused::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updatePasswordSettings::account_updatePasswordSettings(object_ptr<InputCheckPasswordSRP> &&password_, object_ptr<account_passwordInputSettings> &&new_settings_)
  : password_(std::move(password_))
  , new_settings_(std::move(new_settings_))
{}

const std::int32_t account_updatePasswordSettings::ID;

void account_updatePasswordSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1516564433);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
  TlStoreBoxed<TlStoreObject, -1036572727>::store(new_settings_, s);
}

void account_updatePasswordSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1516564433);
  TlStoreBoxedUnknown<TlStoreObject>::store(password_, s);
  TlStoreBoxed<TlStoreObject, -1036572727>::store(new_settings_, s);
}

void account_updatePasswordSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updatePasswordSettings");
    s.store_object_field("password", static_cast<const BaseObject *>(password_.get()));
    s.store_object_field("new_settings", static_cast<const BaseObject *>(new_settings_.get()));
    s.store_class_end();
  }
}

account_updatePasswordSettings::ReturnType account_updatePasswordSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_checkPaidAuth::auth_checkPaidAuth(string const &phone_number_, string const &phone_code_hash_, int64 form_id_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , form_id_(form_id_)
{}

const std::int32_t auth_checkPaidAuth::ID;

void auth_checkPaidAuth::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1457889180);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreBinary::store(form_id_, s);
}

void auth_checkPaidAuth::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1457889180);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreBinary::store(form_id_, s);
}

void auth_checkPaidAuth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.checkPaidAuth");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("form_id", form_id_);
    s.store_class_end();
  }
}

auth_checkPaidAuth::ReturnType auth_checkPaidAuth::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

auth_checkRecoveryPassword::auth_checkRecoveryPassword(string const &code_)
  : code_(code_)
{}

const std::int32_t auth_checkRecoveryPassword::ID;

void auth_checkRecoveryPassword::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(221691769);
  TlStoreString::store(code_, s);
}

void auth_checkRecoveryPassword::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(221691769);
  TlStoreString::store(code_, s);
}

void auth_checkRecoveryPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.checkRecoveryPassword");
    s.store_field("code", code_);
    s.store_class_end();
  }
}

auth_checkRecoveryPassword::ReturnType auth_checkRecoveryPassword::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_finishPasskeyLogin::auth_finishPasskeyLogin(int32 flags_, object_ptr<InputPasskeyCredential> &&credential_, int32 from_dc_id_, int64 from_auth_key_id_)
  : flags_(flags_)
  , credential_(std::move(credential_))
  , from_dc_id_(from_dc_id_)
  , from_auth_key_id_(from_auth_key_id_)
{}

const std::int32_t auth_finishPasskeyLogin::ID;

void auth_finishPasskeyLogin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1739084537);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(credential_, s);
  if (var0 & 1) { TlStoreBinary::store(from_dc_id_, s); }
  if (var0 & 1) { TlStoreBinary::store(from_auth_key_id_, s); }
}

void auth_finishPasskeyLogin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1739084537);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(credential_, s);
  if (var0 & 1) { TlStoreBinary::store(from_dc_id_, s); }
  if (var0 & 1) { TlStoreBinary::store(from_auth_key_id_, s); }
}

void auth_finishPasskeyLogin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.finishPasskeyLogin");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("credential", static_cast<const BaseObject *>(credential_.get()));
    if (var0 & 1) { s.store_field("from_dc_id", from_dc_id_); }
    if (var0 & 1) { s.store_field("from_auth_key_id", from_auth_key_id_); }
    s.store_class_end();
  }
}

auth_finishPasskeyLogin::ReturnType auth_finishPasskeyLogin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

auth_recoverPassword::auth_recoverPassword(int32 flags_, string const &code_, object_ptr<account_passwordInputSettings> &&new_settings_)
  : flags_(flags_)
  , code_(code_)
  , new_settings_(std::move(new_settings_))
{}

const std::int32_t auth_recoverPassword::ID;

void auth_recoverPassword::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(923364464);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(code_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1036572727>::store(new_settings_, s); }
}

void auth_recoverPassword::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(923364464);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(code_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1036572727>::store(new_settings_, s); }
}

void auth_recoverPassword::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.recoverPassword");
    s.store_field("flags", (var0 = flags_));
    s.store_field("code", code_);
    if (var0 & 1) { s.store_object_field("new_settings", static_cast<const BaseObject *>(new_settings_.get())); }
    s.store_class_end();
  }
}

auth_recoverPassword::ReturnType auth_recoverPassword::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_Authorization>::parse(p);
#undef FAIL
}

bots_checkUsername::bots_checkUsername(string const &username_)
  : username_(username_)
{}

const std::int32_t bots_checkUsername::ID;

void bots_checkUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2014174821);
  TlStoreString::store(username_, s);
}

void bots_checkUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2014174821);
  TlStoreString::store(username_, s);
}

void bots_checkUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.checkUsername");
    s.store_field("username", username_);
    s.store_class_end();
  }
}

bots_checkUsername::ReturnType bots_checkUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t bots_getAdminedBots::ID;

void bots_getAdminedBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1334764157);
}

void bots_getAdminedBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1334764157);
}

void bots_getAdminedBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getAdminedBots");
    s.store_class_end();
  }
}

bots_getAdminedBots::ReturnType bots_getAdminedBots::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
#undef FAIL
}

bots_requestWebViewButton::bots_requestWebViewButton(object_ptr<InputUser> &&user_id_, object_ptr<KeyboardButton> &&button_)
  : user_id_(std::move(user_id_))
  , button_(std::move(button_))
{}

const std::int32_t bots_requestWebViewButton::ID;

void bots_requestWebViewButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(832742238);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(button_, s);
}

void bots_requestWebViewButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(832742238);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(button_, s);
}

void bots_requestWebViewButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.requestWebViewButton");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_object_field("button", static_cast<const BaseObject *>(button_.get()));
    s.store_class_end();
  }
}

bots_requestWebViewButton::ReturnType bots_requestWebViewButton::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<bots_requestedButton>, -247743273>::parse(p);
#undef FAIL
}

channels_deleteHistory::channels_deleteHistory(int32 flags_, bool for_everyone_, object_ptr<InputChannel> &&channel_, int32 max_id_)
  : flags_(flags_)
  , for_everyone_(for_everyone_)
  , channel_(std::move(channel_))
  , max_id_(max_id_)
{}

const std::int32_t channels_deleteHistory::ID;

void channels_deleteHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1683319225);
  TlStoreBinary::store((var0 = flags_ | (for_everyone_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(max_id_, s);
}

void channels_deleteHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1683319225);
  TlStoreBinary::store((var0 = flags_ | (for_everyone_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(max_id_, s);
}

void channels_deleteHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.deleteHistory");
    s.store_field("flags", (var0 = flags_ | (for_everyone_ << 0)));
    if (var0 & 1) { s.store_field("for_everyone", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

channels_deleteHistory::ReturnType channels_deleteHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_editTitle::channels_editTitle(object_ptr<InputChannel> &&channel_, string const &title_)
  : channel_(std::move(channel_))
  , title_(title_)
{}

const std::int32_t channels_editTitle::ID;

void channels_editTitle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1450044624);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(title_, s);
}

void channels_editTitle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1450044624);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(title_, s);
}

void channels_editTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.editTitle");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

channels_editTitle::ReturnType channels_editTitle::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_getAdminedPublicChannels::channels_getAdminedPublicChannels(int32 flags_, bool by_location_, bool check_limit_, bool for_personal_)
  : flags_(flags_)
  , by_location_(by_location_)
  , check_limit_(check_limit_)
  , for_personal_(for_personal_)
{}

const std::int32_t channels_getAdminedPublicChannels::ID;

void channels_getAdminedPublicChannels::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-122669393);
  TlStoreBinary::store((var0 = flags_ | (by_location_ << 0) | (check_limit_ << 1) | (for_personal_ << 2)), s);
}

void channels_getAdminedPublicChannels::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-122669393);
  TlStoreBinary::store((var0 = flags_ | (by_location_ << 0) | (check_limit_ << 1) | (for_personal_ << 2)), s);
}

void channels_getAdminedPublicChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getAdminedPublicChannels");
    s.store_field("flags", (var0 = flags_ | (by_location_ << 0) | (check_limit_ << 1) | (for_personal_ << 2)));
    if (var0 & 1) { s.store_field("by_location", true); }
    if (var0 & 2) { s.store_field("check_limit", true); }
    if (var0 & 4) { s.store_field("for_personal", true); }
    s.store_class_end();
  }
}

channels_getAdminedPublicChannels::ReturnType channels_getAdminedPublicChannels::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

const std::int32_t channels_getInactiveChannels::ID;

void channels_getInactiveChannels::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(300429806);
}

void channels_getInactiveChannels::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(300429806);
}

void channels_getInactiveChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getInactiveChannels");
    s.store_class_end();
  }
}

channels_getInactiveChannels::ReturnType channels_getInactiveChannels::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_inactiveChats>, -1456996667>::parse(p);
#undef FAIL
}

channels_getMessageAuthor::channels_getMessageAuthor(object_ptr<InputChannel> &&channel_, int32 id_)
  : channel_(std::move(channel_))
  , id_(id_)
{}

const std::int32_t channels_getMessageAuthor::ID;

void channels_getMessageAuthor::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-320691994);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(id_, s);
}

void channels_getMessageAuthor::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-320691994);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(id_, s);
}

void channels_getMessageAuthor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getMessageAuthor");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

channels_getMessageAuthor::ReturnType channels_getMessageAuthor::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<User>::parse(p);
#undef FAIL
}

channels_getMessages::channels_getMessages(object_ptr<InputChannel> &&channel_, array<object_ptr<InputMessage>> &&id_)
  : channel_(std::move(channel_))
  , id_(std::move(id_))
{}

const std::int32_t channels_getMessages::ID;

void channels_getMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1383294429);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void channels_getMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1383294429);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void channels_getMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getMessages");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_getMessages::ReturnType channels_getMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

channels_reportSpam::channels_reportSpam(object_ptr<InputChannel> &&channel_, object_ptr<InputPeer> &&participant_, array<int32> &&id_)
  : channel_(std::move(channel_))
  , participant_(std::move(participant_))
  , id_(std::move(id_))
{}

const std::int32_t channels_reportSpam::ID;

void channels_reportSpam::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-196443371);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void channels_reportSpam::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-196443371);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void channels_reportSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.reportSpam");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_reportSpam::ReturnType channels_reportSpam::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_toggleViewForumAsMessages::channels_toggleViewForumAsMessages(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_toggleViewForumAsMessages::ID;

void channels_toggleViewForumAsMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1757889771);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleViewForumAsMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1757889771);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleViewForumAsMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleViewForumAsMessages");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_toggleViewForumAsMessages::ReturnType channels_toggleViewForumAsMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_updateColor::channels_updateColor(int32 flags_, bool for_profile_, object_ptr<InputChannel> &&channel_, int32 color_, int64 background_emoji_id_)
  : flags_(flags_)
  , for_profile_(for_profile_)
  , channel_(std::move(channel_))
  , color_(color_)
  , background_emoji_id_(background_emoji_id_)
{}

const std::int32_t channels_updateColor::ID;

void channels_updateColor::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-659933583);
  TlStoreBinary::store((var0 = flags_ | (for_profile_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  if (var0 & 4) { TlStoreBinary::store(color_, s); }
  if (var0 & 1) { TlStoreBinary::store(background_emoji_id_, s); }
}

void channels_updateColor::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-659933583);
  TlStoreBinary::store((var0 = flags_ | (for_profile_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  if (var0 & 4) { TlStoreBinary::store(color_, s); }
  if (var0 & 1) { TlStoreBinary::store(background_emoji_id_, s); }
}

void channels_updateColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.updateColor");
    s.store_field("flags", (var0 = flags_ | (for_profile_ << 1)));
    if (var0 & 2) { s.store_field("for_profile", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    if (var0 & 4) { s.store_field("color", color_); }
    if (var0 & 1) { s.store_field("background_emoji_id", background_emoji_id_); }
    s.store_class_end();
  }
}

channels_updateColor::ReturnType channels_updateColor::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_updateUsername::channels_updateUsername(object_ptr<InputChannel> &&channel_, string const &username_)
  : channel_(std::move(channel_))
  , username_(username_)
{}

const std::int32_t channels_updateUsername::ID;

void channels_updateUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(890549214);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(username_, s);
}

void channels_updateUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(890549214);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreString::store(username_, s);
}

void channels_updateUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.updateUsername");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("username", username_);
    s.store_class_end();
  }
}

channels_updateUsername::ReturnType channels_updateUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

chatlists_getChatlistUpdates::chatlists_getChatlistUpdates(object_ptr<inputChatlistDialogFilter> &&chatlist_)
  : chatlist_(std::move(chatlist_))
{}

const std::int32_t chatlists_getChatlistUpdates::ID;

void chatlists_getChatlistUpdates::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1992190687);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_getChatlistUpdates::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1992190687);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_getChatlistUpdates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.getChatlistUpdates");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_class_end();
  }
}

chatlists_getChatlistUpdates::ReturnType chatlists_getChatlistUpdates::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<chatlists_chatlistUpdates>, -1816295539>::parse(p);
#undef FAIL
}

contacts_block::contacts_block(int32 flags_, bool my_stories_from_, object_ptr<InputPeer> &&id_)
  : flags_(flags_)
  , my_stories_from_(my_stories_from_)
  , id_(std::move(id_))
{}

const std::int32_t contacts_block::ID;

void contacts_block::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(774801204);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void contacts_block::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(774801204);
  TlStoreBinary::store((var0 = flags_ | (my_stories_from_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void contacts_block::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.block");
    s.store_field("flags", (var0 = flags_ | (my_stories_from_ << 0)));
    if (var0 & 1) { s.store_field("my_stories_from", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

contacts_block::ReturnType contacts_block::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

help_hidePromoData::help_hidePromoData(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t help_hidePromoData::ID;

void help_hidePromoData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(505748629);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void help_hidePromoData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(505748629);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void help_hidePromoData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.hidePromoData");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

help_hidePromoData::ReturnType help_hidePromoData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

help_saveAppLog::help_saveAppLog(array<object_ptr<inputAppEvent>> &&events_)
  : events_(std::move(events_))
{}

const std::int32_t help_saveAppLog::ID;

void help_saveAppLog::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1862465352);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 488313413>>, 481674261>::store(events_, s);
}

void help_saveAppLog::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1862465352);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 488313413>>, 481674261>::store(events_, s);
}

void help_saveAppLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.saveAppLog");
    { s.store_vector_begin("events", events_.size()); for (const auto &_value : events_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

help_saveAppLog::ReturnType help_saveAppLog::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_appendTodoList::messages_appendTodoList(object_ptr<InputPeer> &&peer_, int32 msg_id_, array<object_ptr<todoItem>> &&list_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , list_(std::move(list_))
{}

const std::int32_t messages_appendTodoList::ID;

void messages_appendTodoList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(564531287);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -878074577>>, 481674261>::store(list_, s);
}

void messages_appendTodoList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(564531287);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -878074577>>, 481674261>::store(list_, s);
}

void messages_appendTodoList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.appendTodoList");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    { s.store_vector_begin("list", list_.size()); for (const auto &_value : list_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_appendTodoList::ReturnType messages_appendTodoList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_createChat::messages_createChat(int32 flags_, array<object_ptr<InputUser>> &&users_, string const &title_, int32 ttl_period_)
  : flags_(flags_)
  , users_(std::move(users_))
  , title_(title_)
  , ttl_period_(ttl_period_)
{}

const std::int32_t messages_createChat::ID;

void messages_createChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1831936556);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
  TlStoreString::store(title_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_period_, s); }
}

void messages_createChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1831936556);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s);
  TlStoreString::store(title_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_period_, s); }
}

void messages_createChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.createChat");
    s.store_field("flags", (var0 = flags_));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("title", title_);
    if (var0 & 1) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

messages_createChat::ReturnType messages_createChat::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_invitedUsers>, 2136862630>::parse(p);
#undef FAIL
}

messages_deleteChatUser::messages_deleteChatUser(int32 flags_, bool revoke_history_, int64 chat_id_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , revoke_history_(revoke_history_)
  , chat_id_(chat_id_)
  , user_id_(std::move(user_id_))
{}

const std::int32_t messages_deleteChatUser::ID;

void messages_deleteChatUser::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1575461717);
  TlStoreBinary::store((var0 = flags_ | (revoke_history_ << 0)), s);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_deleteChatUser::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1575461717);
  TlStoreBinary::store((var0 = flags_ | (revoke_history_ << 0)), s);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void messages_deleteChatUser::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteChatUser");
    s.store_field("flags", (var0 = flags_ | (revoke_history_ << 0)));
    if (var0 & 1) { s.store_field("revoke_history", true); }
    s.store_field("chat_id", chat_id_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

messages_deleteChatUser::ReturnType messages_deleteChatUser::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_deleteQuickReplyShortcut::messages_deleteQuickReplyShortcut(int32 shortcut_id_)
  : shortcut_id_(shortcut_id_)
{}

const std::int32_t messages_deleteQuickReplyShortcut::ID;

void messages_deleteQuickReplyShortcut::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1019234112);
  TlStoreBinary::store(shortcut_id_, s);
}

void messages_deleteQuickReplyShortcut::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1019234112);
  TlStoreBinary::store(shortcut_id_, s);
}

void messages_deleteQuickReplyShortcut::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteQuickReplyShortcut");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_class_end();
  }
}

messages_deleteQuickReplyShortcut::ReturnType messages_deleteQuickReplyShortcut::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t messages_getDefaultHistoryTTL::ID;

void messages_getDefaultHistoryTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1703637384);
}

void messages_getDefaultHistoryTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1703637384);
}

void messages_getDefaultHistoryTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDefaultHistoryTTL");
    s.store_class_end();
  }
}

messages_getDefaultHistoryTTL::ReturnType messages_getDefaultHistoryTTL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<defaultHistoryTTL>, 1135897376>::parse(p);
#undef FAIL
}

messages_getDialogUnreadMarks::messages_getDialogUnreadMarks(int32 flags_, object_ptr<InputPeer> &&parent_peer_)
  : flags_(flags_)
  , parent_peer_(std::move(parent_peer_))
{}

const std::int32_t messages_getDialogUnreadMarks::ID;

void messages_getDialogUnreadMarks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(555754018);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
}

void messages_getDialogUnreadMarks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(555754018);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
}

void messages_getDialogUnreadMarks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDialogUnreadMarks");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    s.store_class_end();
  }
}

messages_getDialogUnreadMarks::ReturnType messages_getDialogUnreadMarks::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<DialogPeer>>, 481674261>::parse(p);
#undef FAIL
}

messages_getDialogs::messages_getDialogs(int32 flags_, bool exclude_pinned_, int32 folder_id_, int32 offset_date_, int32 offset_id_, object_ptr<InputPeer> &&offset_peer_, int32 limit_, int64 hash_)
  : flags_(flags_)
  , exclude_pinned_(exclude_pinned_)
  , folder_id_(folder_id_)
  , offset_date_(offset_date_)
  , offset_id_(offset_id_)
  , offset_peer_(std::move(offset_peer_))
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_getDialogs::ID;

void messages_getDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1594569905);
  TlStoreBinary::store((var0 = flags_ | (exclude_pinned_ << 0)), s);
  if (var0 & 2) { TlStoreBinary::store(folder_id_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1594569905);
  TlStoreBinary::store((var0 = flags_ | (exclude_pinned_ << 0)), s);
  if (var0 & 2) { TlStoreBinary::store(folder_id_, s); }
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDialogs");
    s.store_field("flags", (var0 = flags_ | (exclude_pinned_ << 0)));
    if (var0 & 1) { s.store_field("exclude_pinned", true); }
    if (var0 & 2) { s.store_field("folder_id", folder_id_); }
    s.store_field("offset_date", offset_date_);
    s.store_field("offset_id", offset_id_);
    s.store_object_field("offset_peer", static_cast<const BaseObject *>(offset_peer_.get()));
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getDialogs::ReturnType messages_getDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Dialogs>::parse(p);
#undef FAIL
}

const std::int32_t messages_getEmojiGameInfo::ID;

void messages_getEmojiGameInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-75592537);
}

void messages_getEmojiGameInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-75592537);
}

void messages_getEmojiGameInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiGameInfo");
    s.store_class_end();
  }
}

messages_getEmojiGameInfo::ReturnType messages_getEmojiGameInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_EmojiGameInfo>::parse(p);
#undef FAIL
}

const std::int32_t messages_getPaidReactionPrivacy::ID;

void messages_getPaidReactionPrivacy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1193563562);
}

void messages_getPaidReactionPrivacy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1193563562);
}

void messages_getPaidReactionPrivacy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPaidReactionPrivacy");
    s.store_class_end();
  }
}

messages_getPaidReactionPrivacy::ReturnType messages_getPaidReactionPrivacy::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getPollVotes::messages_getPollVotes(int32 flags_, object_ptr<InputPeer> &&peer_, int32 id_, bytes &&option_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(id_)
  , option_(std::move(option_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t messages_getPollVotes::ID;

void messages_getPollVotes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1200736242);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(option_, s); }
  if (var0 & 2) { TlStoreString::store(offset_, s); }
  TlStoreBinary::store(limit_, s);
}

void messages_getPollVotes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1200736242);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreString::store(option_, s); }
  if (var0 & 2) { TlStoreString::store(offset_, s); }
  TlStoreBinary::store(limit_, s);
}

void messages_getPollVotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPollVotes");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_bytes_field("option", option_); }
    if (var0 & 2) { s.store_field("offset", offset_); }
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getPollVotes::ReturnType messages_getPollVotes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_votesList>, 1218005070>::parse(p);
#undef FAIL
}

messages_getSavedDialogsByID::messages_getSavedDialogsByID(int32 flags_, object_ptr<InputPeer> &&parent_peer_, array<object_ptr<InputPeer>> &&ids_)
  : flags_(flags_)
  , parent_peer_(std::move(parent_peer_))
  , ids_(std::move(ids_))
{}

const std::int32_t messages_getSavedDialogsByID::ID;

void messages_getSavedDialogsByID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1869585558);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(ids_, s);
}

void messages_getSavedDialogsByID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1869585558);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(parent_peer_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(ids_, s);
}

void messages_getSavedDialogsByID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSavedDialogsByID");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 2) { s.store_object_field("parent_peer", static_cast<const BaseObject *>(parent_peer_.get())); }
    { s.store_vector_begin("ids", ids_.size()); for (const auto &_value : ids_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getSavedDialogsByID::ReturnType messages_getSavedDialogsByID::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SavedDialogs>::parse(p);
#undef FAIL
}

messages_getTopReactions::messages_getTopReactions(int32 limit_, int64 hash_)
  : limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_getTopReactions::ID;

void messages_getTopReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1149164102);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getTopReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1149164102);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getTopReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getTopReactions");
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getTopReactions::ReturnType messages_getTopReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Reactions>::parse(p);
#undef FAIL
}

messages_hideAllChatJoinRequests::messages_hideAllChatJoinRequests(int32 flags_, bool approved_, object_ptr<InputPeer> &&peer_, string const &link_)
  : flags_(flags_)
  , approved_(approved_)
  , peer_(std::move(peer_))
  , link_(link_)
{}

const std::int32_t messages_hideAllChatJoinRequests::ID;

void messages_hideAllChatJoinRequests::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-528091926);
  TlStoreBinary::store((var0 = flags_ | (approved_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreString::store(link_, s); }
}

void messages_hideAllChatJoinRequests::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-528091926);
  TlStoreBinary::store((var0 = flags_ | (approved_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreString::store(link_, s); }
}

void messages_hideAllChatJoinRequests::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.hideAllChatJoinRequests");
    s.store_field("flags", (var0 = flags_ | (approved_ << 0)));
    if (var0 & 1) { s.store_field("approved", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_field("link", link_); }
    s.store_class_end();
  }
}

messages_hideAllChatJoinRequests::ReturnType messages_hideAllChatJoinRequests::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_installStickerSet::messages_installStickerSet(object_ptr<InputStickerSet> &&stickerset_, bool archived_)
  : stickerset_(std::move(stickerset_))
  , archived_(archived_)
{}

const std::int32_t messages_installStickerSet::ID;

void messages_installStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-946871200);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBool::store(archived_, s);
}

void messages_installStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-946871200);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBool::store(archived_, s);
}

void messages_installStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.installStickerSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_field("archived", archived_);
    s.store_class_end();
  }
}

messages_installStickerSet::ReturnType messages_installStickerSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSetInstallResult>::parse(p);
#undef FAIL
}

messages_migrateChat::messages_migrateChat(int64 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t messages_migrateChat::ID;

void messages_migrateChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1568189671);
  TlStoreBinary::store(chat_id_, s);
}

void messages_migrateChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1568189671);
  TlStoreBinary::store(chat_id_, s);
}

void messages_migrateChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.migrateChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

messages_migrateChat::ReturnType messages_migrateChat::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_prolongWebView::messages_prolongWebView(int32 flags_, bool silent_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&bot_, int64 query_id_, object_ptr<InputReplyTo> &&reply_to_, object_ptr<InputPeer> &&send_as_)
  : flags_(flags_)
  , silent_(silent_)
  , peer_(std::move(peer_))
  , bot_(std::move(bot_))
  , query_id_(query_id_)
  , reply_to_(std::move(reply_to_))
  , send_as_(std::move(send_as_))
{}

const std::int32_t messages_prolongWebView::ID;

void messages_prolongWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1328014717);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void messages_prolongWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1328014717);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
}

void messages_prolongWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.prolongWebView");
    s.store_field("flags", (var0 = flags_ | (silent_ << 5)));
    if (var0 & 32) { s.store_field("silent", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("query_id", query_id_);
    if (var0 & 1) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    s.store_class_end();
  }
}

messages_prolongWebView::ReturnType messages_prolongWebView::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_readEncryptedHistory::messages_readEncryptedHistory(object_ptr<inputEncryptedChat> &&peer_, int32 max_date_)
  : peer_(std::move(peer_))
  , max_date_(max_date_)
{}

const std::int32_t messages_readEncryptedHistory::ID;

void messages_readEncryptedHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2135648522);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(max_date_, s);
}

void messages_readEncryptedHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2135648522);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(max_date_, s);
}

void messages_readEncryptedHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readEncryptedHistory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_date", max_date_);
    s.store_class_end();
  }
}

messages_readEncryptedHistory::ReturnType messages_readEncryptedHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_readMessageContents::messages_readMessageContents(array<int32> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t messages_readMessageContents::ID;

void messages_readMessageContents::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(916930423);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_readMessageContents::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(916930423);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_readMessageContents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readMessageContents");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_readMessageContents::ReturnType messages_readMessageContents::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedMessages>, -2066640507>::parse(p);
#undef FAIL
}

messages_reportMessagesDelivery::messages_reportMessagesDelivery(int32 flags_, bool push_, object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : flags_(flags_)
  , push_(push_)
  , peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t messages_reportMessagesDelivery::ID;

void messages_reportMessagesDelivery::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1517122453);
  TlStoreBinary::store((var0 = flags_ | (push_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_reportMessagesDelivery::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1517122453);
  TlStoreBinary::store((var0 = flags_ | (push_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_reportMessagesDelivery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportMessagesDelivery");
    s.store_field("flags", (var0 = flags_ | (push_ << 0)));
    if (var0 & 1) { s.store_field("push", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reportMessagesDelivery::ReturnType messages_reportMessagesDelivery::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_reportReaction::messages_reportReaction(object_ptr<InputPeer> &&peer_, int32 id_, object_ptr<InputPeer> &&reaction_peer_)
  : peer_(std::move(peer_))
  , id_(id_)
  , reaction_peer_(std::move(reaction_peer_))
{}

const std::int32_t messages_reportReaction::ID;

void messages_reportReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1063567478);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_peer_, s);
}

void messages_reportReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1063567478);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_peer_, s);
}

void messages_reportReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportReaction");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_object_field("reaction_peer", static_cast<const BaseObject *>(reaction_peer_.get()));
    s.store_class_end();
  }
}

messages_reportReaction::ReturnType messages_reportReaction::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_requestMainWebView::messages_requestMainWebView(int32 flags_, bool compact_, bool fullscreen_, object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&bot_, string const &start_param_, object_ptr<dataJSON> &&theme_params_, string const &platform_)
  : flags_(flags_)
  , compact_(compact_)
  , fullscreen_(fullscreen_)
  , peer_(std::move(peer_))
  , bot_(std::move(bot_))
  , start_param_(start_param_)
  , theme_params_(std::move(theme_params_))
  , platform_(platform_)
{}

const std::int32_t messages_requestMainWebView::ID;

void messages_requestMainWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-908059013);
  TlStoreBinary::store((var0 = flags_ | (compact_ << 7) | (fullscreen_ << 8)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 2) { TlStoreString::store(start_param_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestMainWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-908059013);
  TlStoreBinary::store((var0 = flags_ | (compact_ << 7) | (fullscreen_ << 8)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  if (var0 & 2) { TlStoreString::store(start_param_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
  TlStoreString::store(platform_, s);
}

void messages_requestMainWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestMainWebView");
    s.store_field("flags", (var0 = flags_ | (compact_ << 7) | (fullscreen_ << 8)));
    if (var0 & 128) { s.store_field("compact", true); }
    if (var0 & 256) { s.store_field("fullscreen", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    if (var0 & 2) { s.store_field("start_param", start_param_); }
    if (var0 & 1) { s.store_object_field("theme_params", static_cast<const BaseObject *>(theme_params_.get())); }
    s.store_field("platform", platform_);
    s.store_class_end();
  }
}

messages_requestMainWebView::ReturnType messages_requestMainWebView::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<webViewResultUrl>, 1294139288>::parse(p);
#undef FAIL
}

messages_saveDraft::messages_saveDraft(int32 flags_, bool no_webpage_, bool invert_media_, object_ptr<InputReplyTo> &&reply_to_, object_ptr<InputPeer> &&peer_, string const &message_, array<object_ptr<MessageEntity>> &&entities_, object_ptr<InputMedia> &&media_, int64 effect_, object_ptr<suggestedPost> &&suggested_post_)
  : flags_(flags_)
  , no_webpage_(no_webpage_)
  , invert_media_(invert_media_)
  , reply_to_(std::move(reply_to_))
  , peer_(std::move(peer_))
  , message_(message_)
  , entities_(std::move(entities_))
  , media_(std::move(media_))
  , effect_(effect_)
  , suggested_post_(std::move(suggested_post_))
{}

const std::int32_t messages_saveDraft::ID;

void messages_saveDraft::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1420701838);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 6)), s);
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(message_, s);
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 128) { TlStoreBinary::store(effect_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
}

void messages_saveDraft::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1420701838);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 6)), s);
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(message_, s);
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 128) { TlStoreBinary::store(effect_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
}

void messages_saveDraft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.saveDraft");
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 6)));
    if (var0 & 2) { s.store_field("no_webpage", true); }
    if (var0 & 64) { s.store_field("invert_media", true); }
    if (var0 & 16) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("message", message_);
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 32) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 128) { s.store_field("effect", effect_); }
    if (var0 & 256) { s.store_object_field("suggested_post", static_cast<const BaseObject *>(suggested_post_.get())); }
    s.store_class_end();
  }
}

messages_saveDraft::ReturnType messages_saveDraft::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_saveRecentSticker::messages_saveRecentSticker(int32 flags_, bool attached_, object_ptr<InputDocument> &&id_, bool unsave_)
  : flags_(flags_)
  , attached_(attached_)
  , id_(std::move(id_))
  , unsave_(unsave_)
{}

const std::int32_t messages_saveRecentSticker::ID;

void messages_saveRecentSticker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(958863608);
  TlStoreBinary::store((var0 = flags_ | (attached_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unsave_, s);
}

void messages_saveRecentSticker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(958863608);
  TlStoreBinary::store((var0 = flags_ | (attached_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unsave_, s);
}

void messages_saveRecentSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.saveRecentSticker");
    s.store_field("flags", (var0 = flags_ | (attached_ << 0)));
    if (var0 & 1) { s.store_field("attached", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("unsave", unsave_);
    s.store_class_end();
  }
}

messages_saveRecentSticker::ReturnType messages_saveRecentSticker::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_sendEncrypted::messages_sendEncrypted(int32 flags_, bool silent_, object_ptr<inputEncryptedChat> &&peer_, int64 random_id_, bytes &&data_)
  : flags_(flags_)
  , silent_(silent_)
  , peer_(std::move(peer_))
  , random_id_(random_id_)
  , data_(std::move(data_))
{}

const std::int32_t messages_sendEncrypted::ID;

void messages_sendEncrypted::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1157265941);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 0)), s);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(data_, s);
}

void messages_sendEncrypted::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1157265941);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 0)), s);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(data_, s);
}

void messages_sendEncrypted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendEncrypted");
    s.store_field("flags", (var0 = flags_ | (silent_ << 0)));
    if (var0 & 1) { s.store_field("silent", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("random_id", random_id_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

messages_sendEncrypted::ReturnType messages_sendEncrypted::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SentEncryptedMessage>::parse(p);
#undef FAIL
}

messages_sendInlineBotResult::messages_sendInlineBotResult(int32 flags_, bool silent_, bool background_, bool clear_draft_, bool hide_via_, object_ptr<InputPeer> &&peer_, object_ptr<InputReplyTo> &&reply_to_, int64 random_id_, int64 query_id_, string const &id_, int32 schedule_date_, object_ptr<InputPeer> &&send_as_, object_ptr<InputQuickReplyShortcut> &&quick_reply_shortcut_, int64 allow_paid_stars_)
  : flags_(flags_)
  , silent_(silent_)
  , background_(background_)
  , clear_draft_(clear_draft_)
  , hide_via_(hide_via_)
  , peer_(std::move(peer_))
  , reply_to_(std::move(reply_to_))
  , random_id_(random_id_)
  , query_id_(query_id_)
  , id_(id_)
  , schedule_date_(schedule_date_)
  , send_as_(std::move(send_as_))
  , quick_reply_shortcut_(std::move(quick_reply_shortcut_))
  , allow_paid_stars_(allow_paid_stars_)
{}

const std::int32_t messages_sendInlineBotResult::ID;

void messages_sendInlineBotResult::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1060145594);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (hide_via_ << 11)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBinary::store(random_id_, s);
  TlStoreBinary::store(query_id_, s);
  TlStoreString::store(id_, s);
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void messages_sendInlineBotResult::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1060145594);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (hide_via_ << 11)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBinary::store(random_id_, s);
  TlStoreBinary::store(query_id_, s);
  TlStoreString::store(id_, s);
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void messages_sendInlineBotResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendInlineBotResult");
    s.store_field("flags", (var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (hide_via_ << 11)));
    if (var0 & 32) { s.store_field("silent", true); }
    if (var0 & 64) { s.store_field("background", true); }
    if (var0 & 128) { s.store_field("clear_draft", true); }
    if (var0 & 2048) { s.store_field("hide_via", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    s.store_field("random_id", random_id_);
    s.store_field("query_id", query_id_);
    s.store_field("id", id_);
    if (var0 & 1024) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    if (var0 & 131072) { s.store_object_field("quick_reply_shortcut", static_cast<const BaseObject *>(quick_reply_shortcut_.get())); }
    if (var0 & 2097152) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    s.store_class_end();
  }
}

messages_sendInlineBotResult::ReturnType messages_sendInlineBotResult::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_sendWebViewResultMessage::messages_sendWebViewResultMessage(string const &bot_query_id_, object_ptr<InputBotInlineResult> &&result_)
  : bot_query_id_(bot_query_id_)
  , result_(std::move(result_))
{}

const std::int32_t messages_sendWebViewResultMessage::ID;

void messages_sendWebViewResultMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(172168437);
  TlStoreString::store(bot_query_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(result_, s);
}

void messages_sendWebViewResultMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(172168437);
  TlStoreString::store(bot_query_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(result_, s);
}

void messages_sendWebViewResultMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendWebViewResultMessage");
    s.store_field("bot_query_id", bot_query_id_);
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_class_end();
  }
}

messages_sendWebViewResultMessage::ReturnType messages_sendWebViewResultMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<webViewMessageSent>, 211046684>::parse(p);
#undef FAIL
}

messages_setBotShippingResults::messages_setBotShippingResults(int32 flags_, int64 query_id_, string const &error_, array<object_ptr<shippingOption>> &&shipping_options_)
  : flags_(flags_)
  , query_id_(query_id_)
  , error_(error_)
  , shipping_options_(std::move(shipping_options_))
{}

const std::int32_t messages_setBotShippingResults::ID;

void messages_setBotShippingResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-436833542);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(error_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1239335713>>, 481674261>::store(shipping_options_, s); }
}

void messages_setBotShippingResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-436833542);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(error_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1239335713>>, 481674261>::store(shipping_options_, s); }
}

void messages_setBotShippingResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setBotShippingResults");
    s.store_field("flags", (var0 = flags_));
    s.store_field("query_id", query_id_);
    if (var0 & 1) { s.store_field("error", error_); }
    if (var0 & 2) { { s.store_vector_begin("shipping_options", shipping_options_.size()); for (const auto &_value : shipping_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

messages_setBotShippingResults::ReturnType messages_setBotShippingResults::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_startHistoryImport::messages_startHistoryImport(object_ptr<InputPeer> &&peer_, int64 import_id_)
  : peer_(std::move(peer_))
  , import_id_(import_id_)
{}

const std::int32_t messages_startHistoryImport::ID;

void messages_startHistoryImport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1271008444);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(import_id_, s);
}

void messages_startHistoryImport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1271008444);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(import_id_, s);
}

void messages_startHistoryImport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.startHistoryImport");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("import_id", import_id_);
    s.store_class_end();
  }
}

messages_startHistoryImport::ReturnType messages_startHistoryImport::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_getPaymentForm::payments_getPaymentForm(int32 flags_, object_ptr<InputInvoice> &&invoice_, object_ptr<dataJSON> &&theme_params_)
  : flags_(flags_)
  , invoice_(std::move(invoice_))
  , theme_params_(std::move(theme_params_))
{}

const std::int32_t payments_getPaymentForm::ID;

void payments_getPaymentForm::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(924093883);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
}

void payments_getPaymentForm::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(924093883);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 2104790276>::store(theme_params_, s); }
}

void payments_getPaymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getPaymentForm");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    if (var0 & 1) { s.store_object_field("theme_params", static_cast<const BaseObject *>(theme_params_.get())); }
    s.store_class_end();
  }
}

payments_getPaymentForm::ReturnType payments_getPaymentForm::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_PaymentForm>::parse(p);
#undef FAIL
}

payments_getPremiumGiftCodeOptions::payments_getPremiumGiftCodeOptions(int32 flags_, object_ptr<InputPeer> &&boost_peer_)
  : flags_(flags_)
  , boost_peer_(std::move(boost_peer_))
{}

const std::int32_t payments_getPremiumGiftCodeOptions::ID;

void payments_getPremiumGiftCodeOptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(660060756);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s); }
}

void payments_getPremiumGiftCodeOptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(660060756);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(boost_peer_, s); }
}

void payments_getPremiumGiftCodeOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getPremiumGiftCodeOptions");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("boost_peer", static_cast<const BaseObject *>(boost_peer_.get())); }
    s.store_class_end();
  }
}

payments_getPremiumGiftCodeOptions::ReturnType payments_getPremiumGiftCodeOptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<premiumGiftCodeOption>, 629052971>>, 481674261>::parse(p);
#undef FAIL
}

payments_getSavedStarGift::payments_getSavedStarGift(array<object_ptr<InputSavedStarGift>> &&stargift_)
  : stargift_(std::move(stargift_))
{}

const std::int32_t payments_getSavedStarGift::ID;

void payments_getSavedStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1269456634);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_getSavedStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1269456634);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_getSavedStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getSavedStarGift");
    { s.store_vector_begin("stargift", stargift_.size()); for (const auto &_value : stargift_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_getSavedStarGift::ReturnType payments_getSavedStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_savedStarGifts>, -1779201615>::parse(p);
#undef FAIL
}

payments_getStarGiftCollections::payments_getStarGiftCollections(object_ptr<InputPeer> &&peer_, int64 hash_)
  : peer_(std::move(peer_))
  , hash_(hash_)
{}

const std::int32_t payments_getStarGiftCollections::ID;

void payments_getStarGiftCollections::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1743023651);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void payments_getStarGiftCollections::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1743023651);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(hash_, s);
}

void payments_getStarGiftCollections::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftCollections");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

payments_getStarGiftCollections::ReturnType payments_getStarGiftCollections::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_StarGiftCollections>::parse(p);
#undef FAIL
}

payments_launchPrepaidGiveaway::payments_launchPrepaidGiveaway(object_ptr<InputPeer> &&peer_, int64 giveaway_id_, object_ptr<InputStorePaymentPurpose> &&purpose_)
  : peer_(std::move(peer_))
  , giveaway_id_(giveaway_id_)
  , purpose_(std::move(purpose_))
{}

const std::int32_t payments_launchPrepaidGiveaway::ID;

void payments_launchPrepaidGiveaway::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1609928480);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(giveaway_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_launchPrepaidGiveaway::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1609928480);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(giveaway_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(purpose_, s);
}

void payments_launchPrepaidGiveaway::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.launchPrepaidGiveaway");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("giveaway_id", giveaway_id_);
    s.store_object_field("purpose", static_cast<const BaseObject *>(purpose_.get()));
    s.store_class_end();
  }
}

payments_launchPrepaidGiveaway::ReturnType payments_launchPrepaidGiveaway::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_updateStarGiftPrice::payments_updateStarGiftPrice(object_ptr<InputSavedStarGift> &&stargift_, object_ptr<StarsAmount> &&resell_amount_)
  : stargift_(std::move(stargift_))
  , resell_amount_(std::move(resell_amount_))
{}

const std::int32_t payments_updateStarGiftPrice::ID;

void payments_updateStarGiftPrice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-306287413);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(resell_amount_, s);
}

void payments_updateStarGiftPrice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-306287413);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(resell_amount_, s);
}

void payments_updateStarGiftPrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.updateStarGiftPrice");
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_object_field("resell_amount", static_cast<const BaseObject *>(resell_amount_.get()));
    s.store_class_end();
  }
}

payments_updateStarGiftPrice::ReturnType payments_updateStarGiftPrice::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t phone_getCallConfig::ID;

void phone_getCallConfig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1430593449);
}

void phone_getCallConfig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1430593449);
}

void phone_getCallConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getCallConfig");
    s.store_class_end();
  }
}

phone_getCallConfig::ReturnType phone_getCallConfig::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
#undef FAIL
}

phone_inviteConferenceCallParticipant::phone_inviteConferenceCallParticipant(int32 flags_, bool video_, object_ptr<InputGroupCall> &&call_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , video_(video_)
  , call_(std::move(call_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t phone_inviteConferenceCallParticipant::ID;

void phone_inviteConferenceCallParticipant::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1124981115);
  TlStoreBinary::store((var0 = flags_ | (video_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void phone_inviteConferenceCallParticipant::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1124981115);
  TlStoreBinary::store((var0 = flags_ | (video_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void phone_inviteConferenceCallParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.inviteConferenceCallParticipant");
    s.store_field("flags", (var0 = flags_ | (video_ << 0)));
    if (var0 & 1) { s.store_field("video", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

phone_inviteConferenceCallParticipant::ReturnType phone_inviteConferenceCallParticipant::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_toggleGroupCallRecord::phone_toggleGroupCallRecord(int32 flags_, bool start_, bool video_, object_ptr<InputGroupCall> &&call_, string const &title_, bool video_portrait_)
  : flags_(flags_)
  , start_(start_)
  , video_(video_)
  , call_(std::move(call_))
  , title_(title_)
  , video_portrait_(video_portrait_)
{}

const std::int32_t phone_toggleGroupCallRecord::ID;

void phone_toggleGroupCallRecord::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-248985848);
  TlStoreBinary::store((var0 = flags_ | (start_ << 0) | (video_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreBool::store(video_portrait_, s); }
}

void phone_toggleGroupCallRecord::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-248985848);
  TlStoreBinary::store((var0 = flags_ | (start_ << 0) | (video_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 4) { TlStoreBool::store(video_portrait_, s); }
}

void phone_toggleGroupCallRecord::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.toggleGroupCallRecord");
    s.store_field("flags", (var0 = flags_ | (start_ << 0) | (video_ << 2)));
    if (var0 & 1) { s.store_field("start", true); }
    if (var0 & 4) { s.store_field("video", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    if (var0 & 2) { s.store_field("title", title_); }
    if (var0 & 4) { s.store_field("video_portrait", video_portrait_); }
    s.store_class_end();
  }
}

phone_toggleGroupCallRecord::ReturnType phone_toggleGroupCallRecord::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

stickers_changeSticker::stickers_changeSticker(int32 flags_, object_ptr<InputDocument> &&sticker_, string const &emoji_, object_ptr<maskCoords> &&mask_coords_, string const &keywords_)
  : flags_(flags_)
  , sticker_(std::move(sticker_))
  , emoji_(emoji_)
  , mask_coords_(std::move(mask_coords_))
  , keywords_(keywords_)
{}

const std::int32_t stickers_changeSticker::ID;

void stickers_changeSticker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-179077444);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  if (var0 & 1) { TlStoreString::store(emoji_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, -1361650766>::store(mask_coords_, s); }
  if (var0 & 4) { TlStoreString::store(keywords_, s); }
}

void stickers_changeSticker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-179077444);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  if (var0 & 1) { TlStoreString::store(emoji_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, -1361650766>::store(mask_coords_, s); }
  if (var0 & 4) { TlStoreString::store(keywords_, s); }
}

void stickers_changeSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.changeSticker");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    if (var0 & 1) { s.store_field("emoji", emoji_); }
    if (var0 & 2) { s.store_object_field("mask_coords", static_cast<const BaseObject *>(mask_coords_.get())); }
    if (var0 & 4) { s.store_field("keywords", keywords_); }
    s.store_class_end();
  }
}

stickers_changeSticker::ReturnType stickers_changeSticker::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stories_getStoryReactionsList::stories_getStoryReactionsList(int32 flags_, bool forwards_first_, object_ptr<InputPeer> &&peer_, int32 id_, object_ptr<Reaction> &&reaction_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , forwards_first_(forwards_first_)
  , peer_(std::move(peer_))
  , id_(id_)
  , reaction_(std::move(reaction_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t stories_getStoryReactionsList::ID;

void stories_getStoryReactionsList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1179482081);
  TlStoreBinary::store((var0 = flags_ | (forwards_first_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s); }
  if (var0 & 2) { TlStoreString::store(offset_, s); }
  TlStoreBinary::store(limit_, s);
}

void stories_getStoryReactionsList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1179482081);
  TlStoreBinary::store((var0 = flags_ | (forwards_first_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s); }
  if (var0 & 2) { TlStoreString::store(offset_, s); }
  TlStoreBinary::store(limit_, s);
}

void stories_getStoryReactionsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getStoryReactionsList");
    s.store_field("flags", (var0 = flags_ | (forwards_first_ << 2)));
    if (var0 & 4) { s.store_field("forwards_first", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get())); }
    if (var0 & 2) { s.store_field("offset", offset_); }
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stories_getStoryReactionsList::ReturnType stories_getStoryReactionsList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_storyReactionsList>, -1436583780>::parse(p);
#undef FAIL
}

stories_incrementStoryViews::stories_incrementStoryViews(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t stories_incrementStoryViews::ID;

void stories_incrementStoryViews::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1308456197);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_incrementStoryViews::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1308456197);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_incrementStoryViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.incrementStoryViews");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_incrementStoryViews::ReturnType stories_incrementStoryViews::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

stories_sendStory::stories_sendStory(int32 flags_, bool pinned_, bool noforwards_, bool fwd_modified_, object_ptr<InputPeer> &&peer_, object_ptr<InputMedia> &&media_, array<object_ptr<MediaArea>> &&media_areas_, string const &caption_, array<object_ptr<MessageEntity>> &&entities_, array<object_ptr<InputPrivacyRule>> &&privacy_rules_, int64 random_id_, int32 period_, object_ptr<InputPeer> &&fwd_from_id_, int32 fwd_from_story_, array<int32> &&albums_, object_ptr<InputDocument> &&music_)
  : flags_(flags_)
  , pinned_(pinned_)
  , noforwards_(noforwards_)
  , fwd_modified_(fwd_modified_)
  , peer_(std::move(peer_))
  , media_(std::move(media_))
  , media_areas_(std::move(media_areas_))
  , caption_(caption_)
  , entities_(std::move(entities_))
  , privacy_rules_(std::move(privacy_rules_))
  , random_id_(random_id_)
  , period_(period_)
  , fwd_from_id_(std::move(fwd_from_id_))
  , fwd_from_story_(fwd_from_story_)
  , albums_(std::move(albums_))
  , music_(std::move(music_))
{}

const std::int32_t stories_sendStory::ID;

void stories_sendStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1885443944);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 2) | (noforwards_ << 4) | (fwd_modified_ << 7)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  if (var0 & 32) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_areas_, s); }
  if (var0 & 1) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_rules_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 8) { TlStoreBinary::store(period_, s); }
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(fwd_from_id_, s); }
  if (var0 & 64) { TlStoreBinary::store(fwd_from_story_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(albums_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(music_, s); }
}

void stories_sendStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1885443944);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 2) | (noforwards_ << 4) | (fwd_modified_ << 7)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  if (var0 & 32) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_areas_, s); }
  if (var0 & 1) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_rules_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 8) { TlStoreBinary::store(period_, s); }
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(fwd_from_id_, s); }
  if (var0 & 64) { TlStoreBinary::store(fwd_from_story_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(albums_, s); }
  if (var0 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(music_, s); }
}

void stories_sendStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.sendStory");
    s.store_field("flags", (var0 = flags_ | (pinned_ << 2) | (noforwards_ << 4) | (fwd_modified_ << 7)));
    if (var0 & 4) { s.store_field("pinned", true); }
    if (var0 & 16) { s.store_field("noforwards", true); }
    if (var0 & 128) { s.store_field("fwd_modified", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    if (var0 & 32) { { s.store_vector_begin("media_areas", media_areas_.size()); for (const auto &_value : media_areas_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 1) { s.store_field("caption", caption_); }
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("privacy_rules", privacy_rules_.size()); for (const auto &_value : privacy_rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("random_id", random_id_);
    if (var0 & 8) { s.store_field("period", period_); }
    if (var0 & 64) { s.store_object_field("fwd_from_id", static_cast<const BaseObject *>(fwd_from_id_.get())); }
    if (var0 & 64) { s.store_field("fwd_from_story", fwd_from_story_); }
    if (var0 & 256) { { s.store_vector_begin("albums", albums_.size()); for (const auto &_value : albums_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 512) { s.store_object_field("music", static_cast<const BaseObject *>(music_.get())); }
    s.store_class_end();
  }
}

stories_sendStory::ReturnType stories_sendStory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

upload_saveBigFilePart::upload_saveBigFilePart(int64 file_id_, int32 file_part_, int32 file_total_parts_, bytes &&bytes_)
  : file_id_(file_id_)
  , file_part_(file_part_)
  , file_total_parts_(file_total_parts_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t upload_saveBigFilePart::ID;

void upload_saveBigFilePart::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-562337987);
  TlStoreBinary::store(file_id_, s);
  TlStoreBinary::store(file_part_, s);
  TlStoreBinary::store(file_total_parts_, s);
  TlStoreString::store(bytes_, s);
}

void upload_saveBigFilePart::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-562337987);
  TlStoreBinary::store(file_id_, s);
  TlStoreBinary::store(file_part_, s);
  TlStoreBinary::store(file_total_parts_, s);
  TlStoreString::store(bytes_, s);
}

void upload_saveBigFilePart::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.saveBigFilePart");
    s.store_field("file_id", file_id_);
    s.store_field("file_part", file_part_);
    s.store_field("file_total_parts", file_total_parts_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

upload_saveBigFilePart::ReturnType upload_saveBigFilePart::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

object_ptr<Object> Object::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case accessPointRule::ID:
      return accessPointRule::fetch(p);
    case accountDaysTTL::ID:
      return accountDaysTTL::fetch(p);
    case attachMenuBot::ID:
      return attachMenuBot::fetch(p);
    case attachMenuBotIcon::ID:
      return attachMenuBotIcon::fetch(p);
    case attachMenuBotIconColor::ID:
      return attachMenuBotIconColor::fetch(p);
    case attachMenuBotsNotModified::ID:
      return attachMenuBotsNotModified::fetch(p);
    case attachMenuBots::ID:
      return attachMenuBots::fetch(p);
    case attachMenuBotsBot::ID:
      return attachMenuBotsBot::fetch(p);
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
    case auctionBidLevel::ID:
      return auctionBidLevel::fetch(p);
    case authorization::ID:
      return authorization::fetch(p);
    case autoDownloadSettings::ID:
      return autoDownloadSettings::fetch(p);
    case autoSaveException::ID:
      return autoSaveException::fetch(p);
    case autoSaveSettings::ID:
      return autoSaveSettings::fetch(p);
    case availableEffect::ID:
      return availableEffect::fetch(p);
    case availableReaction::ID:
      return availableReaction::fetch(p);
    case bankCardOpenUrl::ID:
      return bankCardOpenUrl::fetch(p);
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
    case birthday::ID:
      return birthday::fetch(p);
    case boost::ID:
      return boost::fetch(p);
    case botAppNotModified::ID:
      return botAppNotModified::fetch(p);
    case botApp::ID:
      return botApp::fetch(p);
    case botAppSettings::ID:
      return botAppSettings::fetch(p);
    case botBusinessConnection::ID:
      return botBusinessConnection::fetch(p);
    case botCommand::ID:
      return botCommand::fetch(p);
    case botInfo::ID:
      return botInfo::fetch(p);
    case botInlineMessageMediaAuto::ID:
      return botInlineMessageMediaAuto::fetch(p);
    case botInlineMessageText::ID:
      return botInlineMessageText::fetch(p);
    case botInlineMessageMediaGeo::ID:
      return botInlineMessageMediaGeo::fetch(p);
    case botInlineMessageMediaVenue::ID:
      return botInlineMessageMediaVenue::fetch(p);
    case botInlineMessageMediaContact::ID:
      return botInlineMessageMediaContact::fetch(p);
    case botInlineMessageMediaInvoice::ID:
      return botInlineMessageMediaInvoice::fetch(p);
    case botInlineMessageMediaWebPage::ID:
      return botInlineMessageMediaWebPage::fetch(p);
    case botInlineResult::ID:
      return botInlineResult::fetch(p);
    case botInlineMediaResult::ID:
      return botInlineMediaResult::fetch(p);
    case botMenuButtonDefault::ID:
      return botMenuButtonDefault::fetch(p);
    case botMenuButtonCommands::ID:
      return botMenuButtonCommands::fetch(p);
    case botMenuButton::ID:
      return botMenuButton::fetch(p);
    case botPreviewMedia::ID:
      return botPreviewMedia::fetch(p);
    case botVerification::ID:
      return botVerification::fetch(p);
    case botVerifierSettings::ID:
      return botVerifierSettings::fetch(p);
    case businessAwayMessage::ID:
      return businessAwayMessage::fetch(p);
    case businessAwayMessageScheduleAlways::ID:
      return businessAwayMessageScheduleAlways::fetch(p);
    case businessAwayMessageScheduleOutsideWorkHours::ID:
      return businessAwayMessageScheduleOutsideWorkHours::fetch(p);
    case businessAwayMessageScheduleCustom::ID:
      return businessAwayMessageScheduleCustom::fetch(p);
    case businessBotRecipients::ID:
      return businessBotRecipients::fetch(p);
    case businessBotRights::ID:
      return businessBotRights::fetch(p);
    case businessChatLink::ID:
      return businessChatLink::fetch(p);
    case businessGreetingMessage::ID:
      return businessGreetingMessage::fetch(p);
    case businessIntro::ID:
      return businessIntro::fetch(p);
    case businessLocation::ID:
      return businessLocation::fetch(p);
    case businessRecipients::ID:
      return businessRecipients::fetch(p);
    case businessWeeklyOpen::ID:
      return businessWeeklyOpen::fetch(p);
    case businessWorkHours::ID:
      return businessWorkHours::fetch(p);
    case cdnConfig::ID:
      return cdnConfig::fetch(p);
    case cdnPublicKey::ID:
      return cdnPublicKey::fetch(p);
    case channelAdminLogEvent::ID:
      return channelAdminLogEvent::fetch(p);
    case channelAdminLogEventActionChangeTitle::ID:
      return channelAdminLogEventActionChangeTitle::fetch(p);
    case channelAdminLogEventActionChangeAbout::ID:
      return channelAdminLogEventActionChangeAbout::fetch(p);
    case channelAdminLogEventActionChangeUsername::ID:
      return channelAdminLogEventActionChangeUsername::fetch(p);
    case channelAdminLogEventActionChangePhoto::ID:
      return channelAdminLogEventActionChangePhoto::fetch(p);
    case channelAdminLogEventActionToggleInvites::ID:
      return channelAdminLogEventActionToggleInvites::fetch(p);
    case channelAdminLogEventActionToggleSignatures::ID:
      return channelAdminLogEventActionToggleSignatures::fetch(p);
    case channelAdminLogEventActionUpdatePinned::ID:
      return channelAdminLogEventActionUpdatePinned::fetch(p);
    case channelAdminLogEventActionEditMessage::ID:
      return channelAdminLogEventActionEditMessage::fetch(p);
    case channelAdminLogEventActionDeleteMessage::ID:
      return channelAdminLogEventActionDeleteMessage::fetch(p);
    case channelAdminLogEventActionParticipantJoin::ID:
      return channelAdminLogEventActionParticipantJoin::fetch(p);
    case channelAdminLogEventActionParticipantLeave::ID:
      return channelAdminLogEventActionParticipantLeave::fetch(p);
    case channelAdminLogEventActionParticipantInvite::ID:
      return channelAdminLogEventActionParticipantInvite::fetch(p);
    case channelAdminLogEventActionParticipantToggleBan::ID:
      return channelAdminLogEventActionParticipantToggleBan::fetch(p);
    case channelAdminLogEventActionParticipantToggleAdmin::ID:
      return channelAdminLogEventActionParticipantToggleAdmin::fetch(p);
    case channelAdminLogEventActionChangeStickerSet::ID:
      return channelAdminLogEventActionChangeStickerSet::fetch(p);
    case channelAdminLogEventActionTogglePreHistoryHidden::ID:
      return channelAdminLogEventActionTogglePreHistoryHidden::fetch(p);
    case channelAdminLogEventActionDefaultBannedRights::ID:
      return channelAdminLogEventActionDefaultBannedRights::fetch(p);
    case channelAdminLogEventActionStopPoll::ID:
      return channelAdminLogEventActionStopPoll::fetch(p);
    case channelAdminLogEventActionChangeLinkedChat::ID:
      return channelAdminLogEventActionChangeLinkedChat::fetch(p);
    case channelAdminLogEventActionChangeLocation::ID:
      return channelAdminLogEventActionChangeLocation::fetch(p);
    case channelAdminLogEventActionToggleSlowMode::ID:
      return channelAdminLogEventActionToggleSlowMode::fetch(p);
    case channelAdminLogEventActionStartGroupCall::ID:
      return channelAdminLogEventActionStartGroupCall::fetch(p);
    case channelAdminLogEventActionDiscardGroupCall::ID:
      return channelAdminLogEventActionDiscardGroupCall::fetch(p);
    case channelAdminLogEventActionParticipantMute::ID:
      return channelAdminLogEventActionParticipantMute::fetch(p);
    case channelAdminLogEventActionParticipantUnmute::ID:
      return channelAdminLogEventActionParticipantUnmute::fetch(p);
    case channelAdminLogEventActionToggleGroupCallSetting::ID:
      return channelAdminLogEventActionToggleGroupCallSetting::fetch(p);
    case channelAdminLogEventActionParticipantJoinByInvite::ID:
      return channelAdminLogEventActionParticipantJoinByInvite::fetch(p);
    case channelAdminLogEventActionExportedInviteDelete::ID:
      return channelAdminLogEventActionExportedInviteDelete::fetch(p);
    case channelAdminLogEventActionExportedInviteRevoke::ID:
      return channelAdminLogEventActionExportedInviteRevoke::fetch(p);
    case channelAdminLogEventActionExportedInviteEdit::ID:
      return channelAdminLogEventActionExportedInviteEdit::fetch(p);
    case channelAdminLogEventActionParticipantVolume::ID:
      return channelAdminLogEventActionParticipantVolume::fetch(p);
    case channelAdminLogEventActionChangeHistoryTTL::ID:
      return channelAdminLogEventActionChangeHistoryTTL::fetch(p);
    case channelAdminLogEventActionParticipantJoinByRequest::ID:
      return channelAdminLogEventActionParticipantJoinByRequest::fetch(p);
    case channelAdminLogEventActionToggleNoForwards::ID:
      return channelAdminLogEventActionToggleNoForwards::fetch(p);
    case channelAdminLogEventActionSendMessage::ID:
      return channelAdminLogEventActionSendMessage::fetch(p);
    case channelAdminLogEventActionChangeAvailableReactions::ID:
      return channelAdminLogEventActionChangeAvailableReactions::fetch(p);
    case channelAdminLogEventActionChangeUsernames::ID:
      return channelAdminLogEventActionChangeUsernames::fetch(p);
    case channelAdminLogEventActionToggleForum::ID:
      return channelAdminLogEventActionToggleForum::fetch(p);
    case channelAdminLogEventActionCreateTopic::ID:
      return channelAdminLogEventActionCreateTopic::fetch(p);
    case channelAdminLogEventActionEditTopic::ID:
      return channelAdminLogEventActionEditTopic::fetch(p);
    case channelAdminLogEventActionDeleteTopic::ID:
      return channelAdminLogEventActionDeleteTopic::fetch(p);
    case channelAdminLogEventActionPinTopic::ID:
      return channelAdminLogEventActionPinTopic::fetch(p);
    case channelAdminLogEventActionToggleAntiSpam::ID:
      return channelAdminLogEventActionToggleAntiSpam::fetch(p);
    case channelAdminLogEventActionChangePeerColor::ID:
      return channelAdminLogEventActionChangePeerColor::fetch(p);
    case channelAdminLogEventActionChangeProfilePeerColor::ID:
      return channelAdminLogEventActionChangeProfilePeerColor::fetch(p);
    case channelAdminLogEventActionChangeWallpaper::ID:
      return channelAdminLogEventActionChangeWallpaper::fetch(p);
    case channelAdminLogEventActionChangeEmojiStatus::ID:
      return channelAdminLogEventActionChangeEmojiStatus::fetch(p);
    case channelAdminLogEventActionChangeEmojiStickerSet::ID:
      return channelAdminLogEventActionChangeEmojiStickerSet::fetch(p);
    case channelAdminLogEventActionToggleSignatureProfiles::ID:
      return channelAdminLogEventActionToggleSignatureProfiles::fetch(p);
    case channelAdminLogEventActionParticipantSubExtend::ID:
      return channelAdminLogEventActionParticipantSubExtend::fetch(p);
    case channelAdminLogEventActionToggleAutotranslation::ID:
      return channelAdminLogEventActionToggleAutotranslation::fetch(p);
    case channelAdminLogEventActionParticipantEditRank::ID:
      return channelAdminLogEventActionParticipantEditRank::fetch(p);
    case channelLocationEmpty::ID:
      return channelLocationEmpty::fetch(p);
    case channelLocation::ID:
      return channelLocation::fetch(p);
    case channelParticipant::ID:
      return channelParticipant::fetch(p);
    case channelParticipantSelf::ID:
      return channelParticipantSelf::fetch(p);
    case channelParticipantCreator::ID:
      return channelParticipantCreator::fetch(p);
    case channelParticipantAdmin::ID:
      return channelParticipantAdmin::fetch(p);
    case channelParticipantBanned::ID:
      return channelParticipantBanned::fetch(p);
    case channelParticipantLeft::ID:
      return channelParticipantLeft::fetch(p);
    case chatEmpty::ID:
      return chatEmpty::fetch(p);
    case chat::ID:
      return chat::fetch(p);
    case chatForbidden::ID:
      return chatForbidden::fetch(p);
    case channel::ID:
      return channel::fetch(p);
    case channelForbidden::ID:
      return channelForbidden::fetch(p);
    case chatAdminRights::ID:
      return chatAdminRights::fetch(p);
    case chatAdminWithInvites::ID:
      return chatAdminWithInvites::fetch(p);
    case chatBannedRights::ID:
      return chatBannedRights::fetch(p);
    case chatFull::ID:
      return chatFull::fetch(p);
    case channelFull::ID:
      return channelFull::fetch(p);
    case chatInviteAlready::ID:
      return chatInviteAlready::fetch(p);
    case chatInvite::ID:
      return chatInvite::fetch(p);
    case chatInvitePeek::ID:
      return chatInvitePeek::fetch(p);
    case chatInviteImporter::ID:
      return chatInviteImporter::fetch(p);
    case chatOnlines::ID:
      return chatOnlines::fetch(p);
    case chatParticipant::ID:
      return chatParticipant::fetch(p);
    case chatParticipantCreator::ID:
      return chatParticipantCreator::fetch(p);
    case chatParticipantAdmin::ID:
      return chatParticipantAdmin::fetch(p);
    case chatParticipantsForbidden::ID:
      return chatParticipantsForbidden::fetch(p);
    case chatParticipants::ID:
      return chatParticipants::fetch(p);
    case chatPhotoEmpty::ID:
      return chatPhotoEmpty::fetch(p);
    case chatPhoto::ID:
      return chatPhoto::fetch(p);
    case chatReactionsNone::ID:
      return chatReactionsNone::fetch(p);
    case chatReactionsAll::ID:
      return chatReactionsAll::fetch(p);
    case chatReactionsSome::ID:
      return chatReactionsSome::fetch(p);
    case chatTheme::ID:
      return chatTheme::fetch(p);
    case chatThemeUniqueGift::ID:
      return chatThemeUniqueGift::fetch(p);
    case config::ID:
      return config::fetch(p);
    case connectedBot::ID:
      return connectedBot::fetch(p);
    case connectedBotStarRef::ID:
      return connectedBotStarRef::fetch(p);
    case contact::ID:
      return contact::fetch(p);
    case contactBirthday::ID:
      return contactBirthday::fetch(p);
    case contactStatus::ID:
      return contactStatus::fetch(p);
    case dataJSON::ID:
      return dataJSON::fetch(p);
    case dcOption::ID:
      return dcOption::fetch(p);
    case defaultHistoryTTL::ID:
      return defaultHistoryTTL::fetch(p);
    case dialog::ID:
      return dialog::fetch(p);
    case dialogFolder::ID:
      return dialogFolder::fetch(p);
    case dialogFilter::ID:
      return dialogFilter::fetch(p);
    case dialogFilterDefault::ID:
      return dialogFilterDefault::fetch(p);
    case dialogFilterChatlist::ID:
      return dialogFilterChatlist::fetch(p);
    case dialogFilterSuggested::ID:
      return dialogFilterSuggested::fetch(p);
    case dialogPeer::ID:
      return dialogPeer::fetch(p);
    case dialogPeerFolder::ID:
      return dialogPeerFolder::fetch(p);
    case disallowedGiftsSettings::ID:
      return disallowedGiftsSettings::fetch(p);
    case documentEmpty::ID:
      return documentEmpty::fetch(p);
    case document::ID:
      return document::fetch(p);
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
    case draftMessageEmpty::ID:
      return draftMessageEmpty::fetch(p);
    case draftMessage::ID:
      return draftMessage::fetch(p);
    case emojiGroup::ID:
      return emojiGroup::fetch(p);
    case emojiGroupGreeting::ID:
      return emojiGroupGreeting::fetch(p);
    case emojiGroupPremium::ID:
      return emojiGroupPremium::fetch(p);
    case emojiKeyword::ID:
      return emojiKeyword::fetch(p);
    case emojiKeywordDeleted::ID:
      return emojiKeywordDeleted::fetch(p);
    case emojiKeywordsDifference::ID:
      return emojiKeywordsDifference::fetch(p);
    case emojiLanguage::ID:
      return emojiLanguage::fetch(p);
    case emojiListNotModified::ID:
      return emojiListNotModified::fetch(p);
    case emojiList::ID:
      return emojiList::fetch(p);
    case emojiStatusEmpty::ID:
      return emojiStatusEmpty::fetch(p);
    case emojiStatus::ID:
      return emojiStatus::fetch(p);
    case emojiStatusCollectible::ID:
      return emojiStatusCollectible::fetch(p);
    case inputEmojiStatusCollectible::ID:
      return inputEmojiStatusCollectible::fetch(p);
    case emojiURL::ID:
      return emojiURL::fetch(p);
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
    case encryptedFileEmpty::ID:
      return encryptedFileEmpty::fetch(p);
    case encryptedFile::ID:
      return encryptedFile::fetch(p);
    case encryptedMessage::ID:
      return encryptedMessage::fetch(p);
    case encryptedMessageService::ID:
      return encryptedMessageService::fetch(p);
    case error::ID:
      return error::fetch(p);
    case chatInviteExported::ID:
      return chatInviteExported::fetch(p);
    case chatInvitePublicJoinRequests::ID:
      return chatInvitePublicJoinRequests::fetch(p);
    case exportedChatlistInvite::ID:
      return exportedChatlistInvite::fetch(p);
    case exportedContactToken::ID:
      return exportedContactToken::fetch(p);
    case exportedMessageLink::ID:
      return exportedMessageLink::fetch(p);
    case exportedStoryLink::ID:
      return exportedStoryLink::fetch(p);
    case factCheck::ID:
      return factCheck::fetch(p);
    case fileHash::ID:
      return fileHash::fetch(p);
    case folder::ID:
      return folder::fetch(p);
    case folderPeer::ID:
      return folderPeer::fetch(p);
    case forumTopicDeleted::ID:
      return forumTopicDeleted::fetch(p);
    case forumTopic::ID:
      return forumTopic::fetch(p);
    case foundStory::ID:
      return foundStory::fetch(p);
    case game::ID:
      return game::fetch(p);
    case geoPointEmpty::ID:
      return geoPointEmpty::fetch(p);
    case geoPoint::ID:
      return geoPoint::fetch(p);
    case geoPointAddress::ID:
      return geoPointAddress::fetch(p);
    case globalPrivacySettings::ID:
      return globalPrivacySettings::fetch(p);
    case groupCallDiscarded::ID:
      return groupCallDiscarded::fetch(p);
    case groupCall::ID:
      return groupCall::fetch(p);
    case groupCallDonor::ID:
      return groupCallDonor::fetch(p);
    case groupCallMessage::ID:
      return groupCallMessage::fetch(p);
    case groupCallParticipant::ID:
      return groupCallParticipant::fetch(p);
    case groupCallParticipantVideo::ID:
      return groupCallParticipantVideo::fetch(p);
    case groupCallParticipantVideoSourceGroup::ID:
      return groupCallParticipantVideoSourceGroup::fetch(p);
    case groupCallStreamChannel::ID:
      return groupCallStreamChannel::fetch(p);
    case highScore::ID:
      return highScore::fetch(p);
    case importedContact::ID:
      return importedContact::fetch(p);
    case inlineBotSwitchPM::ID:
      return inlineBotSwitchPM::fetch(p);
    case inlineBotWebView::ID:
      return inlineBotWebView::fetch(p);
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
    case inputAppEvent::ID:
      return inputAppEvent::fetch(p);
    case inputBotInlineMessageID::ID:
      return inputBotInlineMessageID::fetch(p);
    case inputBotInlineMessageID64::ID:
      return inputBotInlineMessageID64::fetch(p);
    case inputChannelEmpty::ID:
      return inputChannelEmpty::fetch(p);
    case inputChannel::ID:
      return inputChannel::fetch(p);
    case inputChannelFromMessage::ID:
      return inputChannelFromMessage::fetch(p);
    case inputDocumentEmpty::ID:
      return inputDocumentEmpty::fetch(p);
    case inputDocument::ID:
      return inputDocument::fetch(p);
    case inputFile::ID:
      return inputFile::fetch(p);
    case inputFileBig::ID:
      return inputFileBig::fetch(p);
    case inputFileStoryDocument::ID:
      return inputFileStoryDocument::fetch(p);
    case inputGameID::ID:
      return inputGameID::fetch(p);
    case inputGameShortName::ID:
      return inputGameShortName::fetch(p);
    case inputGeoPointEmpty::ID:
      return inputGeoPointEmpty::fetch(p);
    case inputGeoPoint::ID:
      return inputGeoPoint::fetch(p);
    case inputGroupCall::ID:
      return inputGroupCall::fetch(p);
    case inputGroupCallSlug::ID:
      return inputGroupCallSlug::fetch(p);
    case inputGroupCallInviteMessage::ID:
      return inputGroupCallInviteMessage::fetch(p);
    case inputMediaEmpty::ID:
      return inputMediaEmpty::fetch(p);
    case inputMediaUploadedPhoto::ID:
      return inputMediaUploadedPhoto::fetch(p);
    case inputMediaPhoto::ID:
      return inputMediaPhoto::fetch(p);
    case inputMediaGeoPoint::ID:
      return inputMediaGeoPoint::fetch(p);
    case inputMediaContact::ID:
      return inputMediaContact::fetch(p);
    case inputMediaUploadedDocument::ID:
      return inputMediaUploadedDocument::fetch(p);
    case inputMediaDocument::ID:
      return inputMediaDocument::fetch(p);
    case inputMediaVenue::ID:
      return inputMediaVenue::fetch(p);
    case inputMediaPhotoExternal::ID:
      return inputMediaPhotoExternal::fetch(p);
    case inputMediaDocumentExternal::ID:
      return inputMediaDocumentExternal::fetch(p);
    case inputMediaGame::ID:
      return inputMediaGame::fetch(p);
    case inputMediaInvoice::ID:
      return inputMediaInvoice::fetch(p);
    case inputMediaGeoLive::ID:
      return inputMediaGeoLive::fetch(p);
    case inputMediaPoll::ID:
      return inputMediaPoll::fetch(p);
    case inputMediaDice::ID:
      return inputMediaDice::fetch(p);
    case inputMediaStory::ID:
      return inputMediaStory::fetch(p);
    case inputMediaWebPage::ID:
      return inputMediaWebPage::fetch(p);
    case inputMediaPaidMedia::ID:
      return inputMediaPaidMedia::fetch(p);
    case inputMediaTodo::ID:
      return inputMediaTodo::fetch(p);
    case inputMediaStakeDice::ID:
      return inputMediaStakeDice::fetch(p);
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
    case inputPhotoEmpty::ID:
      return inputPhotoEmpty::fetch(p);
    case inputPhoto::ID:
      return inputPhoto::fetch(p);
    case inputReplyToMessage::ID:
      return inputReplyToMessage::fetch(p);
    case inputReplyToStory::ID:
      return inputReplyToStory::fetch(p);
    case inputReplyToMonoForum::ID:
      return inputReplyToMonoForum::fetch(p);
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
    case inputUserEmpty::ID:
      return inputUserEmpty::fetch(p);
    case inputUserSelf::ID:
      return inputUserSelf::fetch(p);
    case inputUser::ID:
      return inputUser::fetch(p);
    case inputUserFromMessage::ID:
      return inputUserFromMessage::fetch(p);
    case inputWebDocument::ID:
      return inputWebDocument::fetch(p);
    case invoice::ID:
      return invoice::fetch(p);
    case ipPort::ID:
      return ipPort::fetch(p);
    case ipPortSecret::ID:
      return ipPortSecret::fetch(p);
    case jsonObjectValue::ID:
      return jsonObjectValue::fetch(p);
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
    case keyboardButton::ID:
      return keyboardButton::fetch(p);
    case keyboardButtonUrl::ID:
      return keyboardButtonUrl::fetch(p);
    case keyboardButtonCallback::ID:
      return keyboardButtonCallback::fetch(p);
    case keyboardButtonRequestPhone::ID:
      return keyboardButtonRequestPhone::fetch(p);
    case keyboardButtonRequestGeoLocation::ID:
      return keyboardButtonRequestGeoLocation::fetch(p);
    case keyboardButtonSwitchInline::ID:
      return keyboardButtonSwitchInline::fetch(p);
    case keyboardButtonGame::ID:
      return keyboardButtonGame::fetch(p);
    case keyboardButtonBuy::ID:
      return keyboardButtonBuy::fetch(p);
    case keyboardButtonUrlAuth::ID:
      return keyboardButtonUrlAuth::fetch(p);
    case inputKeyboardButtonUrlAuth::ID:
      return inputKeyboardButtonUrlAuth::fetch(p);
    case keyboardButtonRequestPoll::ID:
      return keyboardButtonRequestPoll::fetch(p);
    case inputKeyboardButtonUserProfile::ID:
      return inputKeyboardButtonUserProfile::fetch(p);
    case keyboardButtonUserProfile::ID:
      return keyboardButtonUserProfile::fetch(p);
    case keyboardButtonWebView::ID:
      return keyboardButtonWebView::fetch(p);
    case keyboardButtonSimpleWebView::ID:
      return keyboardButtonSimpleWebView::fetch(p);
    case keyboardButtonRequestPeer::ID:
      return keyboardButtonRequestPeer::fetch(p);
    case inputKeyboardButtonRequestPeer::ID:
      return inputKeyboardButtonRequestPeer::fetch(p);
    case keyboardButtonCopy::ID:
      return keyboardButtonCopy::fetch(p);
    case keyboardButtonRow::ID:
      return keyboardButtonRow::fetch(p);
    case keyboardButtonStyle::ID:
      return keyboardButtonStyle::fetch(p);
    case labeledPrice::ID:
      return labeledPrice::fetch(p);
    case langPackDifference::ID:
      return langPackDifference::fetch(p);
    case langPackLanguage::ID:
      return langPackLanguage::fetch(p);
    case langPackString::ID:
      return langPackString::fetch(p);
    case langPackStringPluralized::ID:
      return langPackStringPluralized::fetch(p);
    case langPackStringDeleted::ID:
      return langPackStringDeleted::fetch(p);
    case maskCoords::ID:
      return maskCoords::fetch(p);
    case mediaAreaVenue::ID:
      return mediaAreaVenue::fetch(p);
    case inputMediaAreaVenue::ID:
      return inputMediaAreaVenue::fetch(p);
    case mediaAreaGeoPoint::ID:
      return mediaAreaGeoPoint::fetch(p);
    case mediaAreaSuggestedReaction::ID:
      return mediaAreaSuggestedReaction::fetch(p);
    case mediaAreaChannelPost::ID:
      return mediaAreaChannelPost::fetch(p);
    case inputMediaAreaChannelPost::ID:
      return inputMediaAreaChannelPost::fetch(p);
    case mediaAreaUrl::ID:
      return mediaAreaUrl::fetch(p);
    case mediaAreaWeather::ID:
      return mediaAreaWeather::fetch(p);
    case mediaAreaStarGift::ID:
      return mediaAreaStarGift::fetch(p);
    case mediaAreaCoordinates::ID:
      return mediaAreaCoordinates::fetch(p);
    case messageEmpty::ID:
      return messageEmpty::fetch(p);
    case message::ID:
      return message::fetch(p);
    case messageService::ID:
      return messageService::fetch(p);
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
    case messageEntityUnknown::ID:
      return messageEntityUnknown::fetch(p);
    case messageEntityMention::ID:
      return messageEntityMention::fetch(p);
    case messageEntityHashtag::ID:
      return messageEntityHashtag::fetch(p);
    case messageEntityBotCommand::ID:
      return messageEntityBotCommand::fetch(p);
    case messageEntityUrl::ID:
      return messageEntityUrl::fetch(p);
    case messageEntityEmail::ID:
      return messageEntityEmail::fetch(p);
    case messageEntityBold::ID:
      return messageEntityBold::fetch(p);
    case messageEntityItalic::ID:
      return messageEntityItalic::fetch(p);
    case messageEntityCode::ID:
      return messageEntityCode::fetch(p);
    case messageEntityPre::ID:
      return messageEntityPre::fetch(p);
    case messageEntityTextUrl::ID:
      return messageEntityTextUrl::fetch(p);
    case messageEntityMentionName::ID:
      return messageEntityMentionName::fetch(p);
    case inputMessageEntityMentionName::ID:
      return inputMessageEntityMentionName::fetch(p);
    case messageEntityPhone::ID:
      return messageEntityPhone::fetch(p);
    case messageEntityCashtag::ID:
      return messageEntityCashtag::fetch(p);
    case messageEntityUnderline::ID:
      return messageEntityUnderline::fetch(p);
    case messageEntityStrike::ID:
      return messageEntityStrike::fetch(p);
    case messageEntityBankCard::ID:
      return messageEntityBankCard::fetch(p);
    case messageEntitySpoiler::ID:
      return messageEntitySpoiler::fetch(p);
    case messageEntityCustomEmoji::ID:
      return messageEntityCustomEmoji::fetch(p);
    case messageEntityBlockquote::ID:
      return messageEntityBlockquote::fetch(p);
    case messageEntityFormattedDate::ID:
      return messageEntityFormattedDate::fetch(p);
    case messageEntityDiffInsert::ID:
      return messageEntityDiffInsert::fetch(p);
    case messageEntityDiffReplace::ID:
      return messageEntityDiffReplace::fetch(p);
    case messageEntityDiffDelete::ID:
      return messageEntityDiffDelete::fetch(p);
    case messageExtendedMediaPreview::ID:
      return messageExtendedMediaPreview::fetch(p);
    case messageExtendedMedia::ID:
      return messageExtendedMedia::fetch(p);
    case messageFwdHeader::ID:
      return messageFwdHeader::fetch(p);
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
    case messagePeerReaction::ID:
      return messagePeerReaction::fetch(p);
    case messagePeerVote::ID:
      return messagePeerVote::fetch(p);
    case messagePeerVoteInputOption::ID:
      return messagePeerVoteInputOption::fetch(p);
    case messagePeerVoteMultiple::ID:
      return messagePeerVoteMultiple::fetch(p);
    case messageRange::ID:
      return messageRange::fetch(p);
    case messageReactions::ID:
      return messageReactions::fetch(p);
    case messageReactor::ID:
      return messageReactor::fetch(p);
    case messageReplies::ID:
      return messageReplies::fetch(p);
    case messageReplyHeader::ID:
      return messageReplyHeader::fetch(p);
    case messageReplyStoryHeader::ID:
      return messageReplyStoryHeader::fetch(p);
    case messageReportOption::ID:
      return messageReportOption::fetch(p);
    case messageViews::ID:
      return messageViews::fetch(p);
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
    case missingInvitee::ID:
      return missingInvitee::fetch(p);
    case myBoost::ID:
      return myBoost::fetch(p);
    case nearestDc::ID:
      return nearestDc::fetch(p);
    case notificationSoundDefault::ID:
      return notificationSoundDefault::fetch(p);
    case notificationSoundNone::ID:
      return notificationSoundNone::fetch(p);
    case notificationSoundLocal::ID:
      return notificationSoundLocal::fetch(p);
    case notificationSoundRingtone::ID:
      return notificationSoundRingtone::fetch(p);
    case notifyPeer::ID:
      return notifyPeer::fetch(p);
    case notifyUsers::ID:
      return notifyUsers::fetch(p);
    case notifyChats::ID:
      return notifyChats::fetch(p);
    case notifyBroadcasts::ID:
      return notifyBroadcasts::fetch(p);
    case notifyForumTopic::ID:
      return notifyForumTopic::fetch(p);
    case outboxReadDate::ID:
      return outboxReadDate::fetch(p);
    case page::ID:
      return page::fetch(p);
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
    case pageCaption::ID:
      return pageCaption::fetch(p);
    case pageListItemText::ID:
      return pageListItemText::fetch(p);
    case pageListItemBlocks::ID:
      return pageListItemBlocks::fetch(p);
    case pageListOrderedItemText::ID:
      return pageListOrderedItemText::fetch(p);
    case pageListOrderedItemBlocks::ID:
      return pageListOrderedItemBlocks::fetch(p);
    case pageRelatedArticle::ID:
      return pageRelatedArticle::fetch(p);
    case pageTableCell::ID:
      return pageTableCell::fetch(p);
    case pageTableRow::ID:
      return pageTableRow::fetch(p);
    case paidReactionPrivacyDefault::ID:
      return paidReactionPrivacyDefault::fetch(p);
    case paidReactionPrivacyAnonymous::ID:
      return paidReactionPrivacyAnonymous::fetch(p);
    case paidReactionPrivacyPeer::ID:
      return paidReactionPrivacyPeer::fetch(p);
    case passkey::ID:
      return passkey::fetch(p);
    case passwordKdfAlgoUnknown::ID:
      return passwordKdfAlgoUnknown::fetch(p);
    case passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::ID:
      return passwordKdfAlgoSHA256SHA256PBKDF2HMACSHA512iter100000SHA256ModPow::fetch(p);
    case paymentCharge::ID:
      return paymentCharge::fetch(p);
    case paymentFormMethod::ID:
      return paymentFormMethod::fetch(p);
    case paymentRequestedInfo::ID:
      return paymentRequestedInfo::fetch(p);
    case paymentSavedCredentialsCard::ID:
      return paymentSavedCredentialsCard::fetch(p);
    case peerUser::ID:
      return peerUser::fetch(p);
    case peerChat::ID:
      return peerChat::fetch(p);
    case peerChannel::ID:
      return peerChannel::fetch(p);
    case peerBlocked::ID:
      return peerBlocked::fetch(p);
    case peerColor::ID:
      return peerColor::fetch(p);
    case peerColorCollectible::ID:
      return peerColorCollectible::fetch(p);
    case inputPeerColorCollectible::ID:
      return inputPeerColorCollectible::fetch(p);
    case peerLocated::ID:
      return peerLocated::fetch(p);
    case peerSelfLocated::ID:
      return peerSelfLocated::fetch(p);
    case peerNotifySettings::ID:
      return peerNotifySettings::fetch(p);
    case peerSettings::ID:
      return peerSettings::fetch(p);
    case peerStories::ID:
      return peerStories::fetch(p);
    case pendingSuggestion::ID:
      return pendingSuggestion::fetch(p);
    case phoneCallEmpty::ID:
      return phoneCallEmpty::fetch(p);
    case phoneCallWaiting::ID:
      return phoneCallWaiting::fetch(p);
    case phoneCallRequested::ID:
      return phoneCallRequested::fetch(p);
    case phoneCallAccepted::ID:
      return phoneCallAccepted::fetch(p);
    case phoneCall::ID:
      return phoneCall::fetch(p);
    case phoneCallDiscarded::ID:
      return phoneCallDiscarded::fetch(p);
    case phoneCallDiscardReasonMissed::ID:
      return phoneCallDiscardReasonMissed::fetch(p);
    case phoneCallDiscardReasonDisconnect::ID:
      return phoneCallDiscardReasonDisconnect::fetch(p);
    case phoneCallDiscardReasonHangup::ID:
      return phoneCallDiscardReasonHangup::fetch(p);
    case phoneCallDiscardReasonBusy::ID:
      return phoneCallDiscardReasonBusy::fetch(p);
    case phoneCallDiscardReasonMigrateConferenceCall::ID:
      return phoneCallDiscardReasonMigrateConferenceCall::fetch(p);
    case phoneCallProtocol::ID:
      return phoneCallProtocol::fetch(p);
    case phoneConnection::ID:
      return phoneConnection::fetch(p);
    case phoneConnectionWebrtc::ID:
      return phoneConnectionWebrtc::fetch(p);
    case photoEmpty::ID:
      return photoEmpty::fetch(p);
    case photo::ID:
      return photo::fetch(p);
    case photoSizeEmpty::ID:
      return photoSizeEmpty::fetch(p);
    case photoSize::ID:
      return photoSize::fetch(p);
    case photoCachedSize::ID:
      return photoCachedSize::fetch(p);
    case photoStrippedSize::ID:
      return photoStrippedSize::fetch(p);
    case photoSizeProgressive::ID:
      return photoSizeProgressive::fetch(p);
    case photoPathSize::ID:
      return photoPathSize::fetch(p);
    case poll::ID:
      return poll::fetch(p);
    case pollAnswer::ID:
      return pollAnswer::fetch(p);
    case inputPollAnswer::ID:
      return inputPollAnswer::fetch(p);
    case pollAnswerVoters::ID:
      return pollAnswerVoters::fetch(p);
    case pollResults::ID:
      return pollResults::fetch(p);
    case popularContact::ID:
      return popularContact::fetch(p);
    case postAddress::ID:
      return postAddress::fetch(p);
    case postInteractionCountersMessage::ID:
      return postInteractionCountersMessage::fetch(p);
    case postInteractionCountersStory::ID:
      return postInteractionCountersStory::fetch(p);
    case premiumGiftCodeOption::ID:
      return premiumGiftCodeOption::fetch(p);
    case premiumSubscriptionOption::ID:
      return premiumSubscriptionOption::fetch(p);
    case prepaidGiveaway::ID:
      return prepaidGiveaway::fetch(p);
    case prepaidStarsGiveaway::ID:
      return prepaidStarsGiveaway::fetch(p);
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
    case privacyValueAllowContacts::ID:
      return privacyValueAllowContacts::fetch(p);
    case privacyValueAllowAll::ID:
      return privacyValueAllowAll::fetch(p);
    case privacyValueAllowUsers::ID:
      return privacyValueAllowUsers::fetch(p);
    case privacyValueDisallowContacts::ID:
      return privacyValueDisallowContacts::fetch(p);
    case privacyValueDisallowAll::ID:
      return privacyValueDisallowAll::fetch(p);
    case privacyValueDisallowUsers::ID:
      return privacyValueDisallowUsers::fetch(p);
    case privacyValueAllowChatParticipants::ID:
      return privacyValueAllowChatParticipants::fetch(p);
    case privacyValueDisallowChatParticipants::ID:
      return privacyValueDisallowChatParticipants::fetch(p);
    case privacyValueAllowCloseFriends::ID:
      return privacyValueAllowCloseFriends::fetch(p);
    case privacyValueAllowPremium::ID:
      return privacyValueAllowPremium::fetch(p);
    case privacyValueAllowBots::ID:
      return privacyValueAllowBots::fetch(p);
    case privacyValueDisallowBots::ID:
      return privacyValueDisallowBots::fetch(p);
    case profileTabPosts::ID:
      return profileTabPosts::fetch(p);
    case profileTabGifts::ID:
      return profileTabGifts::fetch(p);
    case profileTabMedia::ID:
      return profileTabMedia::fetch(p);
    case profileTabFiles::ID:
      return profileTabFiles::fetch(p);
    case profileTabMusic::ID:
      return profileTabMusic::fetch(p);
    case profileTabVoice::ID:
      return profileTabVoice::fetch(p);
    case profileTabLinks::ID:
      return profileTabLinks::fetch(p);
    case profileTabGifs::ID:
      return profileTabGifs::fetch(p);
    case publicForwardMessage::ID:
      return publicForwardMessage::fetch(p);
    case publicForwardStory::ID:
      return publicForwardStory::fetch(p);
    case quickReply::ID:
      return quickReply::fetch(p);
    case reactionEmpty::ID:
      return reactionEmpty::fetch(p);
    case reactionEmoji::ID:
      return reactionEmoji::fetch(p);
    case reactionCustomEmoji::ID:
      return reactionCustomEmoji::fetch(p);
    case reactionPaid::ID:
      return reactionPaid::fetch(p);
    case reactionCount::ID:
      return reactionCount::fetch(p);
    case reactionNotificationsFromContacts::ID:
      return reactionNotificationsFromContacts::fetch(p);
    case reactionNotificationsFromAll::ID:
      return reactionNotificationsFromAll::fetch(p);
    case reactionsNotifySettings::ID:
      return reactionsNotifySettings::fetch(p);
    case readParticipantDate::ID:
      return readParticipantDate::fetch(p);
    case receivedNotifyMessage::ID:
      return receivedNotifyMessage::fetch(p);
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
    case recentStory::ID:
      return recentStory::fetch(p);
    case replyKeyboardHide::ID:
      return replyKeyboardHide::fetch(p);
    case replyKeyboardForceReply::ID:
      return replyKeyboardForceReply::fetch(p);
    case replyKeyboardMarkup::ID:
      return replyKeyboardMarkup::fetch(p);
    case replyInlineMarkup::ID:
      return replyInlineMarkup::fetch(p);
    case reportResultChooseOption::ID:
      return reportResultChooseOption::fetch(p);
    case reportResultAddComment::ID:
      return reportResultAddComment::fetch(p);
    case reportResultReported::ID:
      return reportResultReported::fetch(p);
    case requestPeerTypeUser::ID:
      return requestPeerTypeUser::fetch(p);
    case requestPeerTypeChat::ID:
      return requestPeerTypeChat::fetch(p);
    case requestPeerTypeBroadcast::ID:
      return requestPeerTypeBroadcast::fetch(p);
    case requestPeerTypeCreateBot::ID:
      return requestPeerTypeCreateBot::fetch(p);
    case requestedPeerUser::ID:
      return requestedPeerUser::fetch(p);
    case requestedPeerChat::ID:
      return requestedPeerChat::fetch(p);
    case requestedPeerChannel::ID:
      return requestedPeerChannel::fetch(p);
    case requirementToContactEmpty::ID:
      return requirementToContactEmpty::fetch(p);
    case requirementToContactPremium::ID:
      return requirementToContactPremium::fetch(p);
    case requirementToContactPaidMessages::ID:
      return requirementToContactPaidMessages::fetch(p);
    case restrictionReason::ID:
      return restrictionReason::fetch(p);
    case textEmpty::ID:
      return textEmpty::fetch(p);
    case textPlain::ID:
      return textPlain::fetch(p);
    case textBold::ID:
      return textBold::fetch(p);
    case textItalic::ID:
      return textItalic::fetch(p);
    case textUnderline::ID:
      return textUnderline::fetch(p);
    case textStrike::ID:
      return textStrike::fetch(p);
    case textFixed::ID:
      return textFixed::fetch(p);
    case textUrl::ID:
      return textUrl::fetch(p);
    case textEmail::ID:
      return textEmail::fetch(p);
    case textConcat::ID:
      return textConcat::fetch(p);
    case textSubscript::ID:
      return textSubscript::fetch(p);
    case textSuperscript::ID:
      return textSuperscript::fetch(p);
    case textMarked::ID:
      return textMarked::fetch(p);
    case textPhone::ID:
      return textPhone::fetch(p);
    case textImage::ID:
      return textImage::fetch(p);
    case textAnchor::ID:
      return textAnchor::fetch(p);
    case savedPhoneContact::ID:
      return savedPhoneContact::fetch(p);
    case savedDialog::ID:
      return savedDialog::fetch(p);
    case monoForumDialog::ID:
      return monoForumDialog::fetch(p);
    case savedReactionTag::ID:
      return savedReactionTag::fetch(p);
    case savedStarGift::ID:
      return savedStarGift::fetch(p);
    case searchPostsFlood::ID:
      return searchPostsFlood::fetch(p);
    case searchResultsCalendarPeriod::ID:
      return searchResultsCalendarPeriod::fetch(p);
    case searchResultPosition::ID:
      return searchResultPosition::fetch(p);
    case secureCredentialsEncrypted::ID:
      return secureCredentialsEncrypted::fetch(p);
    case secureData::ID:
      return secureData::fetch(p);
    case secureFileEmpty::ID:
      return secureFileEmpty::fetch(p);
    case secureFile::ID:
      return secureFile::fetch(p);
    case securePasswordKdfAlgoUnknown::ID:
      return securePasswordKdfAlgoUnknown::fetch(p);
    case securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::ID:
      return securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::fetch(p);
    case securePasswordKdfAlgoSHA512::ID:
      return securePasswordKdfAlgoSHA512::fetch(p);
    case securePlainPhone::ID:
      return securePlainPhone::fetch(p);
    case securePlainEmail::ID:
      return securePlainEmail::fetch(p);
    case secureRequiredType::ID:
      return secureRequiredType::fetch(p);
    case secureRequiredTypeOneOf::ID:
      return secureRequiredTypeOneOf::fetch(p);
    case secureSecretSettings::ID:
      return secureSecretSettings::fetch(p);
    case secureValue::ID:
      return secureValue::fetch(p);
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
    case sendAsPeer::ID:
      return sendAsPeer::fetch(p);
    case sendMessageTypingAction::ID:
      return sendMessageTypingAction::fetch(p);
    case sendMessageCancelAction::ID:
      return sendMessageCancelAction::fetch(p);
    case sendMessageRecordVideoAction::ID:
      return sendMessageRecordVideoAction::fetch(p);
    case sendMessageUploadVideoAction::ID:
      return sendMessageUploadVideoAction::fetch(p);
    case sendMessageRecordAudioAction::ID:
      return sendMessageRecordAudioAction::fetch(p);
    case sendMessageUploadAudioAction::ID:
      return sendMessageUploadAudioAction::fetch(p);
    case sendMessageUploadPhotoAction::ID:
      return sendMessageUploadPhotoAction::fetch(p);
    case sendMessageUploadDocumentAction::ID:
      return sendMessageUploadDocumentAction::fetch(p);
    case sendMessageGeoLocationAction::ID:
      return sendMessageGeoLocationAction::fetch(p);
    case sendMessageChooseContactAction::ID:
      return sendMessageChooseContactAction::fetch(p);
    case sendMessageGamePlayAction::ID:
      return sendMessageGamePlayAction::fetch(p);
    case sendMessageRecordRoundAction::ID:
      return sendMessageRecordRoundAction::fetch(p);
    case sendMessageUploadRoundAction::ID:
      return sendMessageUploadRoundAction::fetch(p);
    case speakingInGroupCallAction::ID:
      return speakingInGroupCallAction::fetch(p);
    case sendMessageHistoryImportAction::ID:
      return sendMessageHistoryImportAction::fetch(p);
    case sendMessageChooseStickerAction::ID:
      return sendMessageChooseStickerAction::fetch(p);
    case sendMessageEmojiInteraction::ID:
      return sendMessageEmojiInteraction::fetch(p);
    case sendMessageEmojiInteractionSeen::ID:
      return sendMessageEmojiInteractionSeen::fetch(p);
    case sendMessageTextDraftAction::ID:
      return sendMessageTextDraftAction::fetch(p);
    case shippingOption::ID:
      return shippingOption::fetch(p);
    case smsJob::ID:
      return smsJob::fetch(p);
    case sponsoredMessage::ID:
      return sponsoredMessage::fetch(p);
    case sponsoredMessageReportOption::ID:
      return sponsoredMessageReportOption::fetch(p);
    case sponsoredPeer::ID:
      return sponsoredPeer::fetch(p);
    case starGift::ID:
      return starGift::fetch(p);
    case starGiftUnique::ID:
      return starGiftUnique::fetch(p);
    case starGiftActiveAuctionState::ID:
      return starGiftActiveAuctionState::fetch(p);
    case starGiftAttributeModel::ID:
      return starGiftAttributeModel::fetch(p);
    case starGiftAttributePattern::ID:
      return starGiftAttributePattern::fetch(p);
    case starGiftAttributeBackdrop::ID:
      return starGiftAttributeBackdrop::fetch(p);
    case starGiftAttributeOriginalDetails::ID:
      return starGiftAttributeOriginalDetails::fetch(p);
    case starGiftAttributeCounter::ID:
      return starGiftAttributeCounter::fetch(p);
    case starGiftAttributeIdModel::ID:
      return starGiftAttributeIdModel::fetch(p);
    case starGiftAttributeIdPattern::ID:
      return starGiftAttributeIdPattern::fetch(p);
    case starGiftAttributeIdBackdrop::ID:
      return starGiftAttributeIdBackdrop::fetch(p);
    case starGiftAttributeRarity::ID:
      return starGiftAttributeRarity::fetch(p);
    case starGiftAttributeRarityUncommon::ID:
      return starGiftAttributeRarityUncommon::fetch(p);
    case starGiftAttributeRarityRare::ID:
      return starGiftAttributeRarityRare::fetch(p);
    case starGiftAttributeRarityEpic::ID:
      return starGiftAttributeRarityEpic::fetch(p);
    case starGiftAttributeRarityLegendary::ID:
      return starGiftAttributeRarityLegendary::fetch(p);
    case starGiftAuctionAcquiredGift::ID:
      return starGiftAuctionAcquiredGift::fetch(p);
    case starGiftAuctionRound::ID:
      return starGiftAuctionRound::fetch(p);
    case starGiftAuctionRoundExtendable::ID:
      return starGiftAuctionRoundExtendable::fetch(p);
    case starGiftAuctionStateNotModified::ID:
      return starGiftAuctionStateNotModified::fetch(p);
    case starGiftAuctionState::ID:
      return starGiftAuctionState::fetch(p);
    case starGiftAuctionStateFinished::ID:
      return starGiftAuctionStateFinished::fetch(p);
    case starGiftAuctionUserState::ID:
      return starGiftAuctionUserState::fetch(p);
    case starGiftBackground::ID:
      return starGiftBackground::fetch(p);
    case starGiftCollection::ID:
      return starGiftCollection::fetch(p);
    case starGiftUpgradePrice::ID:
      return starGiftUpgradePrice::fetch(p);
    case starRefProgram::ID:
      return starRefProgram::fetch(p);
    case starsAmount::ID:
      return starsAmount::fetch(p);
    case starsTonAmount::ID:
      return starsTonAmount::fetch(p);
    case starsGiftOption::ID:
      return starsGiftOption::fetch(p);
    case starsGiveawayOption::ID:
      return starsGiveawayOption::fetch(p);
    case starsGiveawayWinnersOption::ID:
      return starsGiveawayWinnersOption::fetch(p);
    case starsRating::ID:
      return starsRating::fetch(p);
    case starsRevenueStatus::ID:
      return starsRevenueStatus::fetch(p);
    case starsSubscription::ID:
      return starsSubscription::fetch(p);
    case starsSubscriptionPricing::ID:
      return starsSubscriptionPricing::fetch(p);
    case starsTopupOption::ID:
      return starsTopupOption::fetch(p);
    case starsTransaction::ID:
      return starsTransaction::fetch(p);
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
    case statsAbsValueAndPrev::ID:
      return statsAbsValueAndPrev::fetch(p);
    case statsDateRangeDays::ID:
      return statsDateRangeDays::fetch(p);
    case statsGraphAsync::ID:
      return statsGraphAsync::fetch(p);
    case statsGraphError::ID:
      return statsGraphError::fetch(p);
    case statsGraph::ID:
      return statsGraph::fetch(p);
    case statsGroupTopAdmin::ID:
      return statsGroupTopAdmin::fetch(p);
    case statsGroupTopInviter::ID:
      return statsGroupTopInviter::fetch(p);
    case statsGroupTopPoster::ID:
      return statsGroupTopPoster::fetch(p);
    case statsPercentValue::ID:
      return statsPercentValue::fetch(p);
    case stickerKeyword::ID:
      return stickerKeyword::fetch(p);
    case stickerPack::ID:
      return stickerPack::fetch(p);
    case stickerSet::ID:
      return stickerSet::fetch(p);
    case stickerSetCovered::ID:
      return stickerSetCovered::fetch(p);
    case stickerSetMultiCovered::ID:
      return stickerSetMultiCovered::fetch(p);
    case stickerSetFullCovered::ID:
      return stickerSetFullCovered::fetch(p);
    case stickerSetNoCovered::ID:
      return stickerSetNoCovered::fetch(p);
    case storiesStealthMode::ID:
      return storiesStealthMode::fetch(p);
    case storyAlbum::ID:
      return storyAlbum::fetch(p);
    case storyFwdHeader::ID:
      return storyFwdHeader::fetch(p);
    case storyItemDeleted::ID:
      return storyItemDeleted::fetch(p);
    case storyItemSkipped::ID:
      return storyItemSkipped::fetch(p);
    case storyItem::ID:
      return storyItem::fetch(p);
    case storyReaction::ID:
      return storyReaction::fetch(p);
    case storyReactionPublicForward::ID:
      return storyReactionPublicForward::fetch(p);
    case storyReactionPublicRepost::ID:
      return storyReactionPublicRepost::fetch(p);
    case storyView::ID:
      return storyView::fetch(p);
    case storyViewPublicForward::ID:
      return storyViewPublicForward::fetch(p);
    case storyViewPublicRepost::ID:
      return storyViewPublicRepost::fetch(p);
    case storyViews::ID:
      return storyViews::fetch(p);
    case suggestedPost::ID:
      return suggestedPost::fetch(p);
    case textWithEntities::ID:
      return textWithEntities::fetch(p);
    case theme::ID:
      return theme::fetch(p);
    case themeSettings::ID:
      return themeSettings::fetch(p);
    case timezone::ID:
      return timezone::fetch(p);
    case todoCompletion::ID:
      return todoCompletion::fetch(p);
    case todoItem::ID:
      return todoItem::fetch(p);
    case todoList::ID:
      return todoList::fetch(p);
    case topPeer::ID:
      return topPeer::fetch(p);
    case topPeerCategoryBotsPM::ID:
      return topPeerCategoryBotsPM::fetch(p);
    case topPeerCategoryBotsInline::ID:
      return topPeerCategoryBotsInline::fetch(p);
    case topPeerCategoryCorrespondents::ID:
      return topPeerCategoryCorrespondents::fetch(p);
    case topPeerCategoryGroups::ID:
      return topPeerCategoryGroups::fetch(p);
    case topPeerCategoryChannels::ID:
      return topPeerCategoryChannels::fetch(p);
    case topPeerCategoryPhoneCalls::ID:
      return topPeerCategoryPhoneCalls::fetch(p);
    case topPeerCategoryForwardUsers::ID:
      return topPeerCategoryForwardUsers::fetch(p);
    case topPeerCategoryForwardChats::ID:
      return topPeerCategoryForwardChats::fetch(p);
    case topPeerCategoryBotsApp::ID:
      return topPeerCategoryBotsApp::fetch(p);
    case topPeerCategoryPeers::ID:
      return topPeerCategoryPeers::fetch(p);
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
    case urlAuthResultRequest::ID:
      return urlAuthResultRequest::fetch(p);
    case urlAuthResultAccepted::ID:
      return urlAuthResultAccepted::fetch(p);
    case urlAuthResultDefault::ID:
      return urlAuthResultDefault::fetch(p);
    case userEmpty::ID:
      return userEmpty::fetch(p);
    case user::ID:
      return user::fetch(p);
    case userFull::ID:
      return userFull::fetch(p);
    case userProfilePhotoEmpty::ID:
      return userProfilePhotoEmpty::fetch(p);
    case userProfilePhoto::ID:
      return userProfilePhoto::fetch(p);
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
    case username::ID:
      return username::fetch(p);
    case videoSize::ID:
      return videoSize::fetch(p);
    case videoSizeEmojiMarkup::ID:
      return videoSizeEmojiMarkup::fetch(p);
    case videoSizeStickerMarkup::ID:
      return videoSizeStickerMarkup::fetch(p);
    case wallPaper::ID:
      return wallPaper::fetch(p);
    case wallPaperNoFile::ID:
      return wallPaperNoFile::fetch(p);
    case wallPaperSettings::ID:
      return wallPaperSettings::fetch(p);
    case webAuthorization::ID:
      return webAuthorization::fetch(p);
    case webDocument::ID:
      return webDocument::fetch(p);
    case webDocumentNoProxy::ID:
      return webDocumentNoProxy::fetch(p);
    case webPageEmpty::ID:
      return webPageEmpty::fetch(p);
    case webPagePending::ID:
      return webPagePending::fetch(p);
    case webPage::ID:
      return webPage::fetch(p);
    case webPageNotModified::ID:
      return webPageNotModified::fetch(p);
    case webPageAttributeTheme::ID:
      return webPageAttributeTheme::fetch(p);
    case webPageAttributeStory::ID:
      return webPageAttributeStory::fetch(p);
    case webPageAttributeStickerSet::ID:
      return webPageAttributeStickerSet::fetch(p);
    case webPageAttributeUniqueStarGift::ID:
      return webPageAttributeUniqueStarGift::fetch(p);
    case webPageAttributeStarGiftCollection::ID:
      return webPageAttributeStarGiftCollection::fetch(p);
    case webPageAttributeStarGiftAuction::ID:
      return webPageAttributeStarGiftAuction::fetch(p);
    case webViewMessageSent::ID:
      return webViewMessageSent::fetch(p);
    case webViewResultUrl::ID:
      return webViewResultUrl::fetch(p);
    case account_authorizationForm::ID:
      return account_authorizationForm::fetch(p);
    case account_authorizations::ID:
      return account_authorizations::fetch(p);
    case account_autoDownloadSettings::ID:
      return account_autoDownloadSettings::fetch(p);
    case account_autoSaveSettings::ID:
      return account_autoSaveSettings::fetch(p);
    case account_businessChatLinks::ID:
      return account_businessChatLinks::fetch(p);
    case account_chatThemesNotModified::ID:
      return account_chatThemesNotModified::fetch(p);
    case account_chatThemes::ID:
      return account_chatThemes::fetch(p);
    case account_connectedBots::ID:
      return account_connectedBots::fetch(p);
    case account_contentSettings::ID:
      return account_contentSettings::fetch(p);
    case account_emailVerified::ID:
      return account_emailVerified::fetch(p);
    case account_emailVerifiedLogin::ID:
      return account_emailVerifiedLogin::fetch(p);
    case account_emojiStatusesNotModified::ID:
      return account_emojiStatusesNotModified::fetch(p);
    case account_emojiStatuses::ID:
      return account_emojiStatuses::fetch(p);
    case account_paidMessagesRevenue::ID:
      return account_paidMessagesRevenue::fetch(p);
    case account_passkeyRegistrationOptions::ID:
      return account_passkeyRegistrationOptions::fetch(p);
    case account_passkeys::ID:
      return account_passkeys::fetch(p);
    case account_password::ID:
      return account_password::fetch(p);
    case account_passwordSettings::ID:
      return account_passwordSettings::fetch(p);
    case account_privacyRules::ID:
      return account_privacyRules::fetch(p);
    case account_resetPasswordFailedWait::ID:
      return account_resetPasswordFailedWait::fetch(p);
    case account_resetPasswordRequestedWait::ID:
      return account_resetPasswordRequestedWait::fetch(p);
    case account_resetPasswordOk::ID:
      return account_resetPasswordOk::fetch(p);
    case account_resolvedBusinessChatLinks::ID:
      return account_resolvedBusinessChatLinks::fetch(p);
    case account_savedMusicIdsNotModified::ID:
      return account_savedMusicIdsNotModified::fetch(p);
    case account_savedMusicIds::ID:
      return account_savedMusicIds::fetch(p);
    case account_savedRingtone::ID:
      return account_savedRingtone::fetch(p);
    case account_savedRingtoneConverted::ID:
      return account_savedRingtoneConverted::fetch(p);
    case account_savedRingtonesNotModified::ID:
      return account_savedRingtonesNotModified::fetch(p);
    case account_savedRingtones::ID:
      return account_savedRingtones::fetch(p);
    case account_sentEmailCode::ID:
      return account_sentEmailCode::fetch(p);
    case account_takeout::ID:
      return account_takeout::fetch(p);
    case account_themesNotModified::ID:
      return account_themesNotModified::fetch(p);
    case account_themes::ID:
      return account_themes::fetch(p);
    case account_tmpPassword::ID:
      return account_tmpPassword::fetch(p);
    case account_wallPapersNotModified::ID:
      return account_wallPapersNotModified::fetch(p);
    case account_wallPapers::ID:
      return account_wallPapers::fetch(p);
    case account_webAuthorizations::ID:
      return account_webAuthorizations::fetch(p);
    case auth_authorization::ID:
      return auth_authorization::fetch(p);
    case auth_authorizationSignUpRequired::ID:
      return auth_authorizationSignUpRequired::fetch(p);
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
    case auth_exportedAuthorization::ID:
      return auth_exportedAuthorization::fetch(p);
    case auth_loggedOut::ID:
      return auth_loggedOut::fetch(p);
    case auth_loginToken::ID:
      return auth_loginToken::fetch(p);
    case auth_loginTokenMigrateTo::ID:
      return auth_loginTokenMigrateTo::fetch(p);
    case auth_loginTokenSuccess::ID:
      return auth_loginTokenSuccess::fetch(p);
    case auth_passkeyLoginOptions::ID:
      return auth_passkeyLoginOptions::fetch(p);
    case auth_passwordRecovery::ID:
      return auth_passwordRecovery::fetch(p);
    case auth_sentCode::ID:
      return auth_sentCode::fetch(p);
    case auth_sentCodeSuccess::ID:
      return auth_sentCodeSuccess::fetch(p);
    case auth_sentCodePaymentRequired::ID:
      return auth_sentCodePaymentRequired::fetch(p);
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
    case bots_botInfo::ID:
      return bots_botInfo::fetch(p);
    case bots_exportedBotToken::ID:
      return bots_exportedBotToken::fetch(p);
    case bots_popularAppBots::ID:
      return bots_popularAppBots::fetch(p);
    case bots_previewInfo::ID:
      return bots_previewInfo::fetch(p);
    case bots_requestedButton::ID:
      return bots_requestedButton::fetch(p);
    case channels_adminLogResults::ID:
      return channels_adminLogResults::fetch(p);
    case channels_channelParticipant::ID:
      return channels_channelParticipant::fetch(p);
    case channels_channelParticipants::ID:
      return channels_channelParticipants::fetch(p);
    case channels_channelParticipantsNotModified::ID:
      return channels_channelParticipantsNotModified::fetch(p);
    case channels_sendAsPeers::ID:
      return channels_sendAsPeers::fetch(p);
    case channels_sponsoredMessageReportResultChooseOption::ID:
      return channels_sponsoredMessageReportResultChooseOption::fetch(p);
    case channels_sponsoredMessageReportResultAdsHidden::ID:
      return channels_sponsoredMessageReportResultAdsHidden::fetch(p);
    case channels_sponsoredMessageReportResultReported::ID:
      return channels_sponsoredMessageReportResultReported::fetch(p);
    case chatlists_chatlistInviteAlready::ID:
      return chatlists_chatlistInviteAlready::fetch(p);
    case chatlists_chatlistInvite::ID:
      return chatlists_chatlistInvite::fetch(p);
    case chatlists_chatlistUpdates::ID:
      return chatlists_chatlistUpdates::fetch(p);
    case chatlists_exportedChatlistInvite::ID:
      return chatlists_exportedChatlistInvite::fetch(p);
    case chatlists_exportedInvites::ID:
      return chatlists_exportedInvites::fetch(p);
    case contacts_blocked::ID:
      return contacts_blocked::fetch(p);
    case contacts_blockedSlice::ID:
      return contacts_blockedSlice::fetch(p);
    case contacts_contactBirthdays::ID:
      return contacts_contactBirthdays::fetch(p);
    case contacts_contactsNotModified::ID:
      return contacts_contactsNotModified::fetch(p);
    case contacts_contacts::ID:
      return contacts_contacts::fetch(p);
    case contacts_found::ID:
      return contacts_found::fetch(p);
    case contacts_importedContacts::ID:
      return contacts_importedContacts::fetch(p);
    case contacts_resolvedPeer::ID:
      return contacts_resolvedPeer::fetch(p);
    case contacts_sponsoredPeersEmpty::ID:
      return contacts_sponsoredPeersEmpty::fetch(p);
    case contacts_sponsoredPeers::ID:
      return contacts_sponsoredPeers::fetch(p);
    case contacts_topPeersNotModified::ID:
      return contacts_topPeersNotModified::fetch(p);
    case contacts_topPeers::ID:
      return contacts_topPeers::fetch(p);
    case contacts_topPeersDisabled::ID:
      return contacts_topPeersDisabled::fetch(p);
    case fragment_collectibleInfo::ID:
      return fragment_collectibleInfo::fetch(p);
    case help_appConfigNotModified::ID:
      return help_appConfigNotModified::fetch(p);
    case help_appConfig::ID:
      return help_appConfig::fetch(p);
    case help_appUpdate::ID:
      return help_appUpdate::fetch(p);
    case help_noAppUpdate::ID:
      return help_noAppUpdate::fetch(p);
    case help_configSimple::ID:
      return help_configSimple::fetch(p);
    case help_countriesListNotModified::ID:
      return help_countriesListNotModified::fetch(p);
    case help_countriesList::ID:
      return help_countriesList::fetch(p);
    case help_country::ID:
      return help_country::fetch(p);
    case help_countryCode::ID:
      return help_countryCode::fetch(p);
    case help_deepLinkInfoEmpty::ID:
      return help_deepLinkInfoEmpty::fetch(p);
    case help_deepLinkInfo::ID:
      return help_deepLinkInfo::fetch(p);
    case help_inviteText::ID:
      return help_inviteText::fetch(p);
    case help_passportConfigNotModified::ID:
      return help_passportConfigNotModified::fetch(p);
    case help_passportConfig::ID:
      return help_passportConfig::fetch(p);
    case help_peerColorOption::ID:
      return help_peerColorOption::fetch(p);
    case help_peerColorSet::ID:
      return help_peerColorSet::fetch(p);
    case help_peerColorProfileSet::ID:
      return help_peerColorProfileSet::fetch(p);
    case help_peerColorsNotModified::ID:
      return help_peerColorsNotModified::fetch(p);
    case help_peerColors::ID:
      return help_peerColors::fetch(p);
    case help_premiumPromo::ID:
      return help_premiumPromo::fetch(p);
    case help_promoDataEmpty::ID:
      return help_promoDataEmpty::fetch(p);
    case help_promoData::ID:
      return help_promoData::fetch(p);
    case help_recentMeUrls::ID:
      return help_recentMeUrls::fetch(p);
    case help_support::ID:
      return help_support::fetch(p);
    case help_supportName::ID:
      return help_supportName::fetch(p);
    case help_termsOfService::ID:
      return help_termsOfService::fetch(p);
    case help_termsOfServiceUpdateEmpty::ID:
      return help_termsOfServiceUpdateEmpty::fetch(p);
    case help_termsOfServiceUpdate::ID:
      return help_termsOfServiceUpdate::fetch(p);
    case help_timezonesListNotModified::ID:
      return help_timezonesListNotModified::fetch(p);
    case help_timezonesList::ID:
      return help_timezonesList::fetch(p);
    case help_userInfoEmpty::ID:
      return help_userInfoEmpty::fetch(p);
    case help_userInfo::ID:
      return help_userInfo::fetch(p);
    case messages_affectedFoundMessages::ID:
      return messages_affectedFoundMessages::fetch(p);
    case messages_affectedHistory::ID:
      return messages_affectedHistory::fetch(p);
    case messages_affectedMessages::ID:
      return messages_affectedMessages::fetch(p);
    case messages_allStickersNotModified::ID:
      return messages_allStickersNotModified::fetch(p);
    case messages_allStickers::ID:
      return messages_allStickers::fetch(p);
    case messages_archivedStickers::ID:
      return messages_archivedStickers::fetch(p);
    case messages_availableEffectsNotModified::ID:
      return messages_availableEffectsNotModified::fetch(p);
    case messages_availableEffects::ID:
      return messages_availableEffects::fetch(p);
    case messages_availableReactionsNotModified::ID:
      return messages_availableReactionsNotModified::fetch(p);
    case messages_availableReactions::ID:
      return messages_availableReactions::fetch(p);
    case messages_botApp::ID:
      return messages_botApp::fetch(p);
    case messages_botCallbackAnswer::ID:
      return messages_botCallbackAnswer::fetch(p);
    case messages_botPreparedInlineMessage::ID:
      return messages_botPreparedInlineMessage::fetch(p);
    case messages_botResults::ID:
      return messages_botResults::fetch(p);
    case messages_chatAdminsWithInvites::ID:
      return messages_chatAdminsWithInvites::fetch(p);
    case messages_chatFull::ID:
      return messages_chatFull::fetch(p);
    case messages_chatInviteImporters::ID:
      return messages_chatInviteImporters::fetch(p);
    case messages_chats::ID:
      return messages_chats::fetch(p);
    case messages_chatsSlice::ID:
      return messages_chatsSlice::fetch(p);
    case messages_checkedHistoryImportPeer::ID:
      return messages_checkedHistoryImportPeer::fetch(p);
    case messages_composedMessageWithAI::ID:
      return messages_composedMessageWithAI::fetch(p);
    case messages_dhConfigNotModified::ID:
      return messages_dhConfigNotModified::fetch(p);
    case messages_dhConfig::ID:
      return messages_dhConfig::fetch(p);
    case messages_dialogFilters::ID:
      return messages_dialogFilters::fetch(p);
    case messages_dialogs::ID:
      return messages_dialogs::fetch(p);
    case messages_dialogsSlice::ID:
      return messages_dialogsSlice::fetch(p);
    case messages_dialogsNotModified::ID:
      return messages_dialogsNotModified::fetch(p);
    case messages_discussionMessage::ID:
      return messages_discussionMessage::fetch(p);
    case messages_emojiGameUnavailable::ID:
      return messages_emojiGameUnavailable::fetch(p);
    case messages_emojiGameDiceInfo::ID:
      return messages_emojiGameDiceInfo::fetch(p);
    case messages_emojiGameOutcome::ID:
      return messages_emojiGameOutcome::fetch(p);
    case messages_emojiGroupsNotModified::ID:
      return messages_emojiGroupsNotModified::fetch(p);
    case messages_emojiGroups::ID:
      return messages_emojiGroups::fetch(p);
    case messages_exportedChatInvite::ID:
      return messages_exportedChatInvite::fetch(p);
    case messages_exportedChatInviteReplaced::ID:
      return messages_exportedChatInviteReplaced::fetch(p);
    case messages_exportedChatInvites::ID:
      return messages_exportedChatInvites::fetch(p);
    case messages_favedStickersNotModified::ID:
      return messages_favedStickersNotModified::fetch(p);
    case messages_favedStickers::ID:
      return messages_favedStickers::fetch(p);
    case messages_featuredStickersNotModified::ID:
      return messages_featuredStickersNotModified::fetch(p);
    case messages_featuredStickers::ID:
      return messages_featuredStickers::fetch(p);
    case messages_forumTopics::ID:
      return messages_forumTopics::fetch(p);
    case messages_foundStickerSetsNotModified::ID:
      return messages_foundStickerSetsNotModified::fetch(p);
    case messages_foundStickerSets::ID:
      return messages_foundStickerSets::fetch(p);
    case messages_foundStickersNotModified::ID:
      return messages_foundStickersNotModified::fetch(p);
    case messages_foundStickers::ID:
      return messages_foundStickers::fetch(p);
    case messages_highScores::ID:
      return messages_highScores::fetch(p);
    case messages_historyImport::ID:
      return messages_historyImport::fetch(p);
    case messages_historyImportParsed::ID:
      return messages_historyImportParsed::fetch(p);
    case messages_inactiveChats::ID:
      return messages_inactiveChats::fetch(p);
    case messages_invitedUsers::ID:
      return messages_invitedUsers::fetch(p);
    case messages_messageEditData::ID:
      return messages_messageEditData::fetch(p);
    case messages_messageReactionsList::ID:
      return messages_messageReactionsList::fetch(p);
    case messages_messageViews::ID:
      return messages_messageViews::fetch(p);
    case messages_messages::ID:
      return messages_messages::fetch(p);
    case messages_messagesSlice::ID:
      return messages_messagesSlice::fetch(p);
    case messages_channelMessages::ID:
      return messages_channelMessages::fetch(p);
    case messages_messagesNotModified::ID:
      return messages_messagesNotModified::fetch(p);
    case messages_myStickers::ID:
      return messages_myStickers::fetch(p);
    case messages_peerDialogs::ID:
      return messages_peerDialogs::fetch(p);
    case messages_peerSettings::ID:
      return messages_peerSettings::fetch(p);
    case messages_preparedInlineMessage::ID:
      return messages_preparedInlineMessage::fetch(p);
    case messages_quickReplies::ID:
      return messages_quickReplies::fetch(p);
    case messages_quickRepliesNotModified::ID:
      return messages_quickRepliesNotModified::fetch(p);
    case messages_reactionsNotModified::ID:
      return messages_reactionsNotModified::fetch(p);
    case messages_reactions::ID:
      return messages_reactions::fetch(p);
    case messages_recentStickersNotModified::ID:
      return messages_recentStickersNotModified::fetch(p);
    case messages_recentStickers::ID:
      return messages_recentStickers::fetch(p);
    case messages_savedDialogs::ID:
      return messages_savedDialogs::fetch(p);
    case messages_savedDialogsSlice::ID:
      return messages_savedDialogsSlice::fetch(p);
    case messages_savedDialogsNotModified::ID:
      return messages_savedDialogsNotModified::fetch(p);
    case messages_savedGifsNotModified::ID:
      return messages_savedGifsNotModified::fetch(p);
    case messages_savedGifs::ID:
      return messages_savedGifs::fetch(p);
    case messages_savedReactionTagsNotModified::ID:
      return messages_savedReactionTagsNotModified::fetch(p);
    case messages_savedReactionTags::ID:
      return messages_savedReactionTags::fetch(p);
    case messages_searchCounter::ID:
      return messages_searchCounter::fetch(p);
    case messages_searchResultsCalendar::ID:
      return messages_searchResultsCalendar::fetch(p);
    case messages_searchResultsPositions::ID:
      return messages_searchResultsPositions::fetch(p);
    case messages_sentEncryptedMessage::ID:
      return messages_sentEncryptedMessage::fetch(p);
    case messages_sentEncryptedFile::ID:
      return messages_sentEncryptedFile::fetch(p);
    case messages_sponsoredMessages::ID:
      return messages_sponsoredMessages::fetch(p);
    case messages_sponsoredMessagesEmpty::ID:
      return messages_sponsoredMessagesEmpty::fetch(p);
    case messages_stickerSet::ID:
      return messages_stickerSet::fetch(p);
    case messages_stickerSetNotModified::ID:
      return messages_stickerSetNotModified::fetch(p);
    case messages_stickerSetInstallResultSuccess::ID:
      return messages_stickerSetInstallResultSuccess::fetch(p);
    case messages_stickerSetInstallResultArchive::ID:
      return messages_stickerSetInstallResultArchive::fetch(p);
    case messages_stickersNotModified::ID:
      return messages_stickersNotModified::fetch(p);
    case messages_stickers::ID:
      return messages_stickers::fetch(p);
    case messages_transcribedAudio::ID:
      return messages_transcribedAudio::fetch(p);
    case messages_translateResult::ID:
      return messages_translateResult::fetch(p);
    case messages_votesList::ID:
      return messages_votesList::fetch(p);
    case messages_webPage::ID:
      return messages_webPage::fetch(p);
    case messages_webPagePreview::ID:
      return messages_webPagePreview::fetch(p);
    case payments_bankCardData::ID:
      return payments_bankCardData::fetch(p);
    case payments_checkCanSendGiftResultOk::ID:
      return payments_checkCanSendGiftResultOk::fetch(p);
    case payments_checkCanSendGiftResultFail::ID:
      return payments_checkCanSendGiftResultFail::fetch(p);
    case payments_checkedGiftCode::ID:
      return payments_checkedGiftCode::fetch(p);
    case payments_connectedStarRefBots::ID:
      return payments_connectedStarRefBots::fetch(p);
    case payments_exportedInvoice::ID:
      return payments_exportedInvoice::fetch(p);
    case payments_giveawayInfo::ID:
      return payments_giveawayInfo::fetch(p);
    case payments_giveawayInfoResults::ID:
      return payments_giveawayInfoResults::fetch(p);
    case payments_paymentForm::ID:
      return payments_paymentForm::fetch(p);
    case payments_paymentFormStars::ID:
      return payments_paymentFormStars::fetch(p);
    case payments_paymentFormStarGift::ID:
      return payments_paymentFormStarGift::fetch(p);
    case payments_paymentReceipt::ID:
      return payments_paymentReceipt::fetch(p);
    case payments_paymentReceiptStars::ID:
      return payments_paymentReceiptStars::fetch(p);
    case payments_paymentResult::ID:
      return payments_paymentResult::fetch(p);
    case payments_paymentVerificationNeeded::ID:
      return payments_paymentVerificationNeeded::fetch(p);
    case payments_resaleStarGifts::ID:
      return payments_resaleStarGifts::fetch(p);
    case payments_savedInfo::ID:
      return payments_savedInfo::fetch(p);
    case payments_savedStarGifts::ID:
      return payments_savedStarGifts::fetch(p);
    case payments_starGiftActiveAuctionsNotModified::ID:
      return payments_starGiftActiveAuctionsNotModified::fetch(p);
    case payments_starGiftActiveAuctions::ID:
      return payments_starGiftActiveAuctions::fetch(p);
    case payments_starGiftAuctionAcquiredGifts::ID:
      return payments_starGiftAuctionAcquiredGifts::fetch(p);
    case payments_starGiftAuctionState::ID:
      return payments_starGiftAuctionState::fetch(p);
    case payments_starGiftCollectionsNotModified::ID:
      return payments_starGiftCollectionsNotModified::fetch(p);
    case payments_starGiftCollections::ID:
      return payments_starGiftCollections::fetch(p);
    case payments_starGiftUpgradeAttributes::ID:
      return payments_starGiftUpgradeAttributes::fetch(p);
    case payments_starGiftUpgradePreview::ID:
      return payments_starGiftUpgradePreview::fetch(p);
    case payments_starGiftWithdrawalUrl::ID:
      return payments_starGiftWithdrawalUrl::fetch(p);
    case payments_starGiftsNotModified::ID:
      return payments_starGiftsNotModified::fetch(p);
    case payments_starGifts::ID:
      return payments_starGifts::fetch(p);
    case payments_starsRevenueAdsAccountUrl::ID:
      return payments_starsRevenueAdsAccountUrl::fetch(p);
    case payments_starsRevenueStats::ID:
      return payments_starsRevenueStats::fetch(p);
    case payments_starsRevenueWithdrawalUrl::ID:
      return payments_starsRevenueWithdrawalUrl::fetch(p);
    case payments_starsStatus::ID:
      return payments_starsStatus::fetch(p);
    case payments_suggestedStarRefBots::ID:
      return payments_suggestedStarRefBots::fetch(p);
    case payments_uniqueStarGift::ID:
      return payments_uniqueStarGift::fetch(p);
    case payments_uniqueStarGiftValueInfo::ID:
      return payments_uniqueStarGiftValueInfo::fetch(p);
    case payments_validatedRequestedInfo::ID:
      return payments_validatedRequestedInfo::fetch(p);
    case phone_exportedGroupCallInvite::ID:
      return phone_exportedGroupCallInvite::fetch(p);
    case phone_groupCall::ID:
      return phone_groupCall::fetch(p);
    case phone_groupCallStars::ID:
      return phone_groupCallStars::fetch(p);
    case phone_groupCallStreamChannels::ID:
      return phone_groupCallStreamChannels::fetch(p);
    case phone_groupCallStreamRtmpUrl::ID:
      return phone_groupCallStreamRtmpUrl::fetch(p);
    case phone_groupParticipants::ID:
      return phone_groupParticipants::fetch(p);
    case phone_joinAsPeers::ID:
      return phone_joinAsPeers::fetch(p);
    case phone_phoneCall::ID:
      return phone_phoneCall::fetch(p);
    case photos_photo::ID:
      return photos_photo::fetch(p);
    case photos_photos::ID:
      return photos_photos::fetch(p);
    case photos_photosSlice::ID:
      return photos_photosSlice::fetch(p);
    case premium_boostsList::ID:
      return premium_boostsList::fetch(p);
    case premium_boostsStatus::ID:
      return premium_boostsStatus::fetch(p);
    case premium_myBoosts::ID:
      return premium_myBoosts::fetch(p);
    case smsjobs_eligibleToJoin::ID:
      return smsjobs_eligibleToJoin::fetch(p);
    case smsjobs_status::ID:
      return smsjobs_status::fetch(p);
    case stats_broadcastStats::ID:
      return stats_broadcastStats::fetch(p);
    case stats_megagroupStats::ID:
      return stats_megagroupStats::fetch(p);
    case stats_messageStats::ID:
      return stats_messageStats::fetch(p);
    case stats_publicForwards::ID:
      return stats_publicForwards::fetch(p);
    case stats_storyStats::ID:
      return stats_storyStats::fetch(p);
    case stickers_suggestedShortName::ID:
      return stickers_suggestedShortName::fetch(p);
    case storage_fileUnknown::ID:
      return storage_fileUnknown::fetch(p);
    case storage_filePartial::ID:
      return storage_filePartial::fetch(p);
    case storage_fileJpeg::ID:
      return storage_fileJpeg::fetch(p);
    case storage_fileGif::ID:
      return storage_fileGif::fetch(p);
    case storage_filePng::ID:
      return storage_filePng::fetch(p);
    case storage_filePdf::ID:
      return storage_filePdf::fetch(p);
    case storage_fileMp3::ID:
      return storage_fileMp3::fetch(p);
    case storage_fileMov::ID:
      return storage_fileMov::fetch(p);
    case storage_fileMp4::ID:
      return storage_fileMp4::fetch(p);
    case storage_fileWebp::ID:
      return storage_fileWebp::fetch(p);
    case stories_albumsNotModified::ID:
      return stories_albumsNotModified::fetch(p);
    case stories_albums::ID:
      return stories_albums::fetch(p);
    case stories_allStoriesNotModified::ID:
      return stories_allStoriesNotModified::fetch(p);
    case stories_allStories::ID:
      return stories_allStories::fetch(p);
    case stories_canSendStoryCount::ID:
      return stories_canSendStoryCount::fetch(p);
    case stories_foundStories::ID:
      return stories_foundStories::fetch(p);
    case stories_peerStories::ID:
      return stories_peerStories::fetch(p);
    case stories_stories::ID:
      return stories_stories::fetch(p);
    case stories_storyReactionsList::ID:
      return stories_storyReactionsList::fetch(p);
    case stories_storyViews::ID:
      return stories_storyViews::fetch(p);
    case stories_storyViewsList::ID:
      return stories_storyViewsList::fetch(p);
    case updates_channelDifferenceEmpty::ID:
      return updates_channelDifferenceEmpty::fetch(p);
    case updates_channelDifferenceTooLong::ID:
      return updates_channelDifferenceTooLong::fetch(p);
    case updates_channelDifference::ID:
      return updates_channelDifference::fetch(p);
    case updates_differenceEmpty::ID:
      return updates_differenceEmpty::fetch(p);
    case updates_difference::ID:
      return updates_difference::fetch(p);
    case updates_differenceSlice::ID:
      return updates_differenceSlice::fetch(p);
    case updates_differenceTooLong::ID:
      return updates_differenceTooLong::fetch(p);
    case updates_state::ID:
      return updates_state::fetch(p);
    case upload_cdnFileReuploadNeeded::ID:
      return upload_cdnFileReuploadNeeded::fetch(p);
    case upload_cdnFile::ID:
      return upload_cdnFile::fetch(p);
    case upload_file::ID:
      return upload_file::fetch(p);
    case upload_fileCdnRedirect::ID:
      return upload_fileCdnRedirect::fetch(p);
    case upload_webFile::ID:
      return upload_webFile::fetch(p);
    case users_savedMusicNotModified::ID:
      return users_savedMusicNotModified::fetch(p);
    case users_savedMusic::ID:
      return users_savedMusic::fetch(p);
    case users_userFull::ID:
      return users_userFull::fetch(p);
    case users_users::ID:
      return users_users::fetch(p);
    case users_usersSlice::ID:
      return users_usersSlice::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
