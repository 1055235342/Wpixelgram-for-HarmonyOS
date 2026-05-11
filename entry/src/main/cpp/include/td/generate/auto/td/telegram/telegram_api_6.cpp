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


const std::int32_t accessPointRule::ID;

object_ptr<accessPointRule> accessPointRule::fetch(TlBufferParser &p) {
  return make_tl_object<accessPointRule>(p);
}

accessPointRule::accessPointRule(TlBufferParser &p)
  : phone_prefix_rules_(TlFetchString<string>::parse(p))
  , dc_id_(TlFetchInt::parse(p))
  , ips_(TlFetchVector<TlFetchObject<IpPort>>::parse(p))
{}

void accessPointRule::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "accessPointRule");
    s.store_field("phone_prefix_rules", phone_prefix_rules_);
    s.store_field("dc_id", dc_id_);
    { s.store_vector_begin("ips", ips_.size()); for (const auto &_value : ips_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

accountDaysTTL::accountDaysTTL(int32 days_)
  : days_(days_)
{}

const std::int32_t accountDaysTTL::ID;

object_ptr<accountDaysTTL> accountDaysTTL::fetch(TlBufferParser &p) {
  return make_tl_object<accountDaysTTL>(p);
}

accountDaysTTL::accountDaysTTL(TlBufferParser &p)
  : days_(TlFetchInt::parse(p))
{}

void accountDaysTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(days_, s);
}

void accountDaysTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(days_, s);
}

void accountDaysTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "accountDaysTTL");
    s.store_field("days", days_);
    s.store_class_end();
  }
}

const std::int32_t attachMenuBotsBot::ID;

object_ptr<attachMenuBotsBot> attachMenuBotsBot::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuBotsBot>(p);
}

attachMenuBotsBot::attachMenuBotsBot(TlBufferParser &p)
  : bot_(TlFetchBoxed<TlFetchObject<attachMenuBot>, -653423106>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void attachMenuBotsBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuBotsBot");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

autoSaveSettings::autoSaveSettings()
  : flags_()
  , photos_()
  , videos_()
  , video_max_size_()
{}

autoSaveSettings::autoSaveSettings(int32 flags_, bool photos_, bool videos_, int64 video_max_size_)
  : flags_(flags_)
  , photos_(photos_)
  , videos_(videos_)
  , video_max_size_(video_max_size_)
{}

const std::int32_t autoSaveSettings::ID;

object_ptr<autoSaveSettings> autoSaveSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<autoSaveSettings> res = make_tl_object<autoSaveSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->photos_ = (var0 & 1) != 0;
  res->videos_ = (var0 & 2) != 0;
  if (var0 & 4) { res->video_max_size_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void autoSaveSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (photos_ << 0) | (videos_ << 1)), s);
  if (var0 & 4) { TlStoreBinary::store(video_max_size_, s); }
}

void autoSaveSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (photos_ << 0) | (videos_ << 1)), s);
  if (var0 & 4) { TlStoreBinary::store(video_max_size_, s); }
}

void autoSaveSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "autoSaveSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (photos_ << 0) | (videos_ << 1)));
    if (var0 & 1) { s.store_field("photos", true); }
    if (var0 & 2) { s.store_field("videos", true); }
    if (var0 & 4) { s.store_field("video_max_size", video_max_size_); }
    s.store_class_end();
  }
}

botCommand::botCommand(string const &command_, string const &description_)
  : command_(command_)
  , description_(description_)
{}

const std::int32_t botCommand::ID;

object_ptr<botCommand> botCommand::fetch(TlBufferParser &p) {
  return make_tl_object<botCommand>(p);
}

botCommand::botCommand(TlBufferParser &p)
  : command_(TlFetchString<string>::parse(p))
  , description_(TlFetchString<string>::parse(p))
{}

void botCommand::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(command_, s);
  TlStoreString::store(description_, s);
}

void botCommand::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(command_, s);
  TlStoreString::store(description_, s);
}

void botCommand::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botCommand");
    s.store_field("command", command_);
    s.store_field("description", description_);
    s.store_class_end();
  }
}

object_ptr<BotInlineMessage> BotInlineMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

botInlineMessageMediaAuto::botInlineMessageMediaAuto()
  : flags_()
  , invert_media_()
  , message_()
  , entities_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageMediaAuto::ID;

object_ptr<BotInlineMessage> botInlineMessageMediaAuto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageMediaAuto> res = make_tl_object<botInlineMessageMediaAuto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->invert_media_ = (var0 & 8) != 0;
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageMediaAuto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageMediaAuto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (invert_media_ << 3)));
    if (var0 & 8) { s.store_field("invert_media", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageText::botInlineMessageText()
  : flags_()
  , no_webpage_()
  , invert_media_()
  , message_()
  , entities_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageText::ID;

object_ptr<BotInlineMessage> botInlineMessageText::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageText> res = make_tl_object<botInlineMessageText>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->no_webpage_ = (var0 & 1) != 0;
  res->invert_media_ = (var0 & 8) != 0;
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageText");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 0) | (invert_media_ << 3)));
    if (var0 & 1) { s.store_field("no_webpage", true); }
    if (var0 & 8) { s.store_field("invert_media", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageMediaGeo::botInlineMessageMediaGeo()
  : flags_()
  , geo_()
  , heading_()
  , period_()
  , proximity_notification_radius_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageMediaGeo::ID;

object_ptr<BotInlineMessage> botInlineMessageMediaGeo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageMediaGeo> res = make_tl_object<botInlineMessageMediaGeo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->geo_ = TlFetchObject<GeoPoint>::parse(p);
  if (var0 & 1) { res->heading_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->period_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->proximity_notification_radius_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageMediaGeo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageMediaGeo");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    if (var0 & 1) { s.store_field("heading", heading_); }
    if (var0 & 2) { s.store_field("period", period_); }
    if (var0 & 8) { s.store_field("proximity_notification_radius", proximity_notification_radius_); }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageMediaVenue::botInlineMessageMediaVenue()
  : flags_()
  , geo_()
  , title_()
  , address_()
  , provider_()
  , venue_id_()
  , venue_type_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageMediaVenue::ID;

object_ptr<BotInlineMessage> botInlineMessageMediaVenue::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageMediaVenue> res = make_tl_object<botInlineMessageMediaVenue>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->geo_ = TlFetchObject<GeoPoint>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->address_ = TlFetchString<string>::parse(p);
  res->provider_ = TlFetchString<string>::parse(p);
  res->venue_id_ = TlFetchString<string>::parse(p);
  res->venue_type_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageMediaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageMediaVenue");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("venue_id", venue_id_);
    s.store_field("venue_type", venue_type_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageMediaContact::botInlineMessageMediaContact()
  : flags_()
  , phone_number_()
  , first_name_()
  , last_name_()
  , vcard_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageMediaContact::ID;

object_ptr<BotInlineMessage> botInlineMessageMediaContact::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageMediaContact> res = make_tl_object<botInlineMessageMediaContact>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->phone_number_ = TlFetchString<string>::parse(p);
  res->first_name_ = TlFetchString<string>::parse(p);
  res->last_name_ = TlFetchString<string>::parse(p);
  res->vcard_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageMediaContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageMediaContact");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("phone_number", phone_number_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("vcard", vcard_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageMediaInvoice::botInlineMessageMediaInvoice()
  : flags_()
  , shipping_address_requested_()
  , test_()
  , title_()
  , description_()
  , photo_()
  , currency_()
  , total_amount_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageMediaInvoice::ID;

object_ptr<BotInlineMessage> botInlineMessageMediaInvoice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageMediaInvoice> res = make_tl_object<botInlineMessageMediaInvoice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->shipping_address_requested_ = (var0 & 2) != 0;
  res->test_ = (var0 & 8) != 0;
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->photo_ = TlFetchObject<WebDocument>::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->total_amount_ = TlFetchLong::parse(p);
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageMediaInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageMediaInvoice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (shipping_address_requested_ << 1) | (test_ << 3)));
    if (var0 & 2) { s.store_field("shipping_address_requested", true); }
    if (var0 & 8) { s.store_field("test", true); }
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 1) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_field("currency", currency_);
    s.store_field("total_amount", total_amount_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

botInlineMessageMediaWebPage::botInlineMessageMediaWebPage()
  : flags_()
  , invert_media_()
  , force_large_media_()
  , force_small_media_()
  , manual_()
  , safe_()
  , message_()
  , entities_()
  , url_()
  , reply_markup_()
{}

const std::int32_t botInlineMessageMediaWebPage::ID;

object_ptr<BotInlineMessage> botInlineMessageMediaWebPage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botInlineMessageMediaWebPage> res = make_tl_object<botInlineMessageMediaWebPage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->invert_media_ = (var0 & 8) != 0;
  res->force_large_media_ = (var0 & 16) != 0;
  res->force_small_media_ = (var0 & 32) != 0;
  res->manual_ = (var0 & 128) != 0;
  res->safe_ = (var0 & 256) != 0;
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  res->url_ = TlFetchString<string>::parse(p);
  if (var0 & 4) { res->reply_markup_ = TlFetchObject<ReplyMarkup>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void botInlineMessageMediaWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botInlineMessageMediaWebPage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (invert_media_ << 3) | (force_large_media_ << 4) | (force_small_media_ << 5) | (manual_ << 7) | (safe_ << 8)));
    if (var0 & 8) { s.store_field("invert_media", true); }
    if (var0 & 16) { s.store_field("force_large_media", true); }
    if (var0 & 32) { s.store_field("force_small_media", true); }
    if (var0 & 128) { s.store_field("manual", true); }
    if (var0 & 256) { s.store_field("safe", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("url", url_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

object_ptr<ChannelLocation> ChannelLocation::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case channelLocationEmpty::ID:
      return channelLocationEmpty::fetch(p);
    case channelLocation::ID:
      return channelLocation::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t channelLocationEmpty::ID;

object_ptr<ChannelLocation> channelLocationEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<channelLocationEmpty>();
}

void channelLocationEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelLocationEmpty");
    s.store_class_end();
  }
}

const std::int32_t channelLocation::ID;

object_ptr<ChannelLocation> channelLocation::fetch(TlBufferParser &p) {
  return make_tl_object<channelLocation>(p);
}

channelLocation::channelLocation(TlBufferParser &p)
  : geo_point_(TlFetchObject<GeoPoint>::parse(p))
  , address_(TlFetchString<string>::parse(p))
{}

void channelLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelLocation");
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    s.store_field("address", address_);
    s.store_class_end();
  }
}

const std::int32_t channelMessagesFilterEmpty::ID;

void channelMessagesFilterEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void channelMessagesFilterEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void channelMessagesFilterEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelMessagesFilterEmpty");
    s.store_class_end();
  }
}

channelMessagesFilter::channelMessagesFilter(int32 flags_, bool exclude_new_messages_, array<object_ptr<messageRange>> &&ranges_)
  : flags_(flags_)
  , exclude_new_messages_(exclude_new_messages_)
  , ranges_(std::move(ranges_))
{}

const std::int32_t channelMessagesFilter::ID;

void channelMessagesFilter::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (exclude_new_messages_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 182649427>>, 481674261>::store(ranges_, s);
}

void channelMessagesFilter::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (exclude_new_messages_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 182649427>>, 481674261>::store(ranges_, s);
}

void channelMessagesFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelMessagesFilter");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (exclude_new_messages_ << 1)));
    if (var0 & 2) { s.store_field("exclude_new_messages", true); }
    { s.store_vector_begin("ranges", ranges_.size()); for (const auto &_value : ranges_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatInviteImporter::chatInviteImporter()
  : flags_()
  , requested_()
  , via_chatlist_()
  , user_id_()
  , date_()
  , about_()
  , approved_by_()
{}

const std::int32_t chatInviteImporter::ID;

object_ptr<chatInviteImporter> chatInviteImporter::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatInviteImporter> res = make_tl_object<chatInviteImporter>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->requested_ = (var0 & 1) != 0;
  res->via_chatlist_ = (var0 & 8) != 0;
  res->user_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->about_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->approved_by_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void chatInviteImporter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatInviteImporter");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (requested_ << 0) | (via_chatlist_ << 3)));
    if (var0 & 1) { s.store_field("requested", true); }
    if (var0 & 8) { s.store_field("via_chatlist", true); }
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    if (var0 & 4) { s.store_field("about", about_); }
    if (var0 & 2) { s.store_field("approved_by", approved_by_); }
    s.store_class_end();
  }
}

object_ptr<ChatPhoto> ChatPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatPhotoEmpty::ID:
      return chatPhotoEmpty::fetch(p);
    case chatPhoto::ID:
      return chatPhoto::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t chatPhotoEmpty::ID;

object_ptr<ChatPhoto> chatPhotoEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<chatPhotoEmpty>();
}

void chatPhotoEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void chatPhotoEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void chatPhotoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhotoEmpty");
    s.store_class_end();
  }
}

chatPhoto::chatPhoto()
  : flags_()
  , has_video_()
  , photo_id_()
  , stripped_thumb_()
  , dc_id_()
{}

chatPhoto::chatPhoto(int32 flags_, bool has_video_, int64 photo_id_, bytes &&stripped_thumb_, int32 dc_id_)
  : flags_(flags_)
  , has_video_(has_video_)
  , photo_id_(photo_id_)
  , stripped_thumb_(std::move(stripped_thumb_))
  , dc_id_(dc_id_)
{}

const std::int32_t chatPhoto::ID;

object_ptr<ChatPhoto> chatPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatPhoto> res = make_tl_object<chatPhoto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_video_ = (var0 & 1) != 0;
  res->photo_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->stripped_thumb_ = TlFetchBytes<bytes>::parse(p); }
  res->dc_id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_video_ << 0)), s);
  TlStoreBinary::store(photo_id_, s);
  if (var0 & 2) { TlStoreString::store(stripped_thumb_, s); }
  TlStoreBinary::store(dc_id_, s);
}

void chatPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_video_ << 0)), s);
  TlStoreBinary::store(photo_id_, s);
  if (var0 & 2) { TlStoreString::store(stripped_thumb_, s); }
  TlStoreBinary::store(dc_id_, s);
}

void chatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatPhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_video_ << 0)));
    if (var0 & 1) { s.store_field("has_video", true); }
    s.store_field("photo_id", photo_id_);
    if (var0 & 2) { s.store_bytes_field("stripped_thumb", stripped_thumb_); }
    s.store_field("dc_id", dc_id_);
    s.store_class_end();
  }
}

codeSettings::codeSettings(int32 flags_, bool allow_flashcall_, bool current_number_, bool allow_app_hash_, bool allow_missed_call_, bool allow_firebase_, bool unknown_number_, array<bytes> &&logout_tokens_, string const &token_, bool app_sandbox_)
  : flags_(flags_)
  , allow_flashcall_(allow_flashcall_)
  , current_number_(current_number_)
  , allow_app_hash_(allow_app_hash_)
  , allow_missed_call_(allow_missed_call_)
  , allow_firebase_(allow_firebase_)
  , unknown_number_(unknown_number_)
  , logout_tokens_(std::move(logout_tokens_))
  , token_(token_)
  , app_sandbox_(app_sandbox_)
{}

const std::int32_t codeSettings::ID;

void codeSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (allow_flashcall_ << 0) | (current_number_ << 1) | (allow_app_hash_ << 4) | (allow_missed_call_ << 5) | (allow_firebase_ << 7) | (unknown_number_ << 9)), s);
  if (var0 & 64) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(logout_tokens_, s); }
  if (var0 & 256) { TlStoreString::store(token_, s); }
  if (var0 & 256) { TlStoreBool::store(app_sandbox_, s); }
}

void codeSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (allow_flashcall_ << 0) | (current_number_ << 1) | (allow_app_hash_ << 4) | (allow_missed_call_ << 5) | (allow_firebase_ << 7) | (unknown_number_ << 9)), s);
  if (var0 & 64) { TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(logout_tokens_, s); }
  if (var0 & 256) { TlStoreString::store(token_, s); }
  if (var0 & 256) { TlStoreBool::store(app_sandbox_, s); }
}

void codeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "codeSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (allow_flashcall_ << 0) | (current_number_ << 1) | (allow_app_hash_ << 4) | (allow_missed_call_ << 5) | (allow_firebase_ << 7) | (unknown_number_ << 9)));
    if (var0 & 1) { s.store_field("allow_flashcall", true); }
    if (var0 & 2) { s.store_field("current_number", true); }
    if (var0 & 16) { s.store_field("allow_app_hash", true); }
    if (var0 & 32) { s.store_field("allow_missed_call", true); }
    if (var0 & 128) { s.store_field("allow_firebase", true); }
    if (var0 & 512) { s.store_field("unknown_number", true); }
    if (var0 & 64) { { s.store_vector_begin("logout_tokens", logout_tokens_.size()); for (const auto &_value : logout_tokens_) { s.store_bytes_field("", _value); } s.store_class_end(); } }
    if (var0 & 256) { s.store_field("token", token_); }
    if (var0 & 256) { s.store_field("app_sandbox", app_sandbox_); }
    s.store_class_end();
  }
}

config::config()
  : flags_()
  , default_p2p_contacts_()
  , preload_featured_stickers_()
  , revoke_pm_inbox_()
  , blocked_mode_()
  , force_try_ipv6_()
  , date_()
  , expires_()
  , test_mode_()
  , this_dc_()
  , dc_options_()
  , dc_txt_domain_name_()
  , chat_size_max_()
  , megagroup_size_max_()
  , forwarded_count_max_()
  , online_update_period_ms_()
  , offline_blur_timeout_ms_()
  , offline_idle_timeout_ms_()
  , online_cloud_timeout_ms_()
  , notify_cloud_delay_ms_()
  , notify_default_delay_ms_()
  , push_chat_period_ms_()
  , push_chat_limit_()
  , edit_time_limit_()
  , revoke_time_limit_()
  , revoke_pm_time_limit_()
  , rating_e_decay_()
  , stickers_recent_limit_()
  , channels_read_media_period_()
  , tmp_sessions_()
  , call_receive_timeout_ms_()
  , call_ring_timeout_ms_()
  , call_connect_timeout_ms_()
  , call_packet_timeout_ms_()
  , me_url_prefix_()
  , autoupdate_url_prefix_()
  , gif_search_username_()
  , venue_search_username_()
  , img_search_username_()
  , static_maps_provider_()
  , caption_length_max_()
  , message_length_max_()
  , webfile_dc_id_()
  , suggested_lang_code_()
  , lang_pack_version_()
  , base_lang_pack_version_()
  , reactions_default_()
  , autologin_token_()
{}

const std::int32_t config::ID;

object_ptr<config> config::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<config> res = make_tl_object<config>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->default_p2p_contacts_ = (var0 & 8) != 0;
  res->preload_featured_stickers_ = (var0 & 16) != 0;
  res->revoke_pm_inbox_ = (var0 & 64) != 0;
  res->blocked_mode_ = (var0 & 256) != 0;
  res->force_try_ipv6_ = (var0 & 16384) != 0;
  res->date_ = TlFetchInt::parse(p);
  res->expires_ = TlFetchInt::parse(p);
  res->test_mode_ = TlFetchBool::parse(p);
  res->this_dc_ = TlFetchInt::parse(p);
  res->dc_options_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<dcOption>, 414687501>>, 481674261>::parse(p);
  res->dc_txt_domain_name_ = TlFetchString<string>::parse(p);
  res->chat_size_max_ = TlFetchInt::parse(p);
  res->megagroup_size_max_ = TlFetchInt::parse(p);
  res->forwarded_count_max_ = TlFetchInt::parse(p);
  res->online_update_period_ms_ = TlFetchInt::parse(p);
  res->offline_blur_timeout_ms_ = TlFetchInt::parse(p);
  res->offline_idle_timeout_ms_ = TlFetchInt::parse(p);
  res->online_cloud_timeout_ms_ = TlFetchInt::parse(p);
  res->notify_cloud_delay_ms_ = TlFetchInt::parse(p);
  res->notify_default_delay_ms_ = TlFetchInt::parse(p);
  res->push_chat_period_ms_ = TlFetchInt::parse(p);
  res->push_chat_limit_ = TlFetchInt::parse(p);
  res->edit_time_limit_ = TlFetchInt::parse(p);
  res->revoke_time_limit_ = TlFetchInt::parse(p);
  res->revoke_pm_time_limit_ = TlFetchInt::parse(p);
  res->rating_e_decay_ = TlFetchInt::parse(p);
  res->stickers_recent_limit_ = TlFetchInt::parse(p);
  res->channels_read_media_period_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->tmp_sessions_ = TlFetchInt::parse(p); }
  res->call_receive_timeout_ms_ = TlFetchInt::parse(p);
  res->call_ring_timeout_ms_ = TlFetchInt::parse(p);
  res->call_connect_timeout_ms_ = TlFetchInt::parse(p);
  res->call_packet_timeout_ms_ = TlFetchInt::parse(p);
  res->me_url_prefix_ = TlFetchString<string>::parse(p);
  if (var0 & 128) { res->autoupdate_url_prefix_ = TlFetchString<string>::parse(p); }
  if (var0 & 512) { res->gif_search_username_ = TlFetchString<string>::parse(p); }
  if (var0 & 1024) { res->venue_search_username_ = TlFetchString<string>::parse(p); }
  if (var0 & 2048) { res->img_search_username_ = TlFetchString<string>::parse(p); }
  if (var0 & 4096) { res->static_maps_provider_ = TlFetchString<string>::parse(p); }
  res->caption_length_max_ = TlFetchInt::parse(p);
  res->message_length_max_ = TlFetchInt::parse(p);
  res->webfile_dc_id_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->suggested_lang_code_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->lang_pack_version_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->base_lang_pack_version_ = TlFetchInt::parse(p); }
  if (var0 & 32768) { res->reactions_default_ = TlFetchObject<Reaction>::parse(p); }
  if (var0 & 65536) { res->autologin_token_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void config::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "config");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (default_p2p_contacts_ << 3) | (preload_featured_stickers_ << 4) | (revoke_pm_inbox_ << 6) | (blocked_mode_ << 8) | (force_try_ipv6_ << 14)));
    if (var0 & 8) { s.store_field("default_p2p_contacts", true); }
    if (var0 & 16) { s.store_field("preload_featured_stickers", true); }
    if (var0 & 64) { s.store_field("revoke_pm_inbox", true); }
    if (var0 & 256) { s.store_field("blocked_mode", true); }
    if (var0 & 16384) { s.store_field("force_try_ipv6", true); }
    s.store_field("date", date_);
    s.store_field("expires", expires_);
    s.store_field("test_mode", test_mode_);
    s.store_field("this_dc", this_dc_);
    { s.store_vector_begin("dc_options", dc_options_.size()); for (const auto &_value : dc_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("dc_txt_domain_name", dc_txt_domain_name_);
    s.store_field("chat_size_max", chat_size_max_);
    s.store_field("megagroup_size_max", megagroup_size_max_);
    s.store_field("forwarded_count_max", forwarded_count_max_);
    s.store_field("online_update_period_ms", online_update_period_ms_);
    s.store_field("offline_blur_timeout_ms", offline_blur_timeout_ms_);
    s.store_field("offline_idle_timeout_ms", offline_idle_timeout_ms_);
    s.store_field("online_cloud_timeout_ms", online_cloud_timeout_ms_);
    s.store_field("notify_cloud_delay_ms", notify_cloud_delay_ms_);
    s.store_field("notify_default_delay_ms", notify_default_delay_ms_);
    s.store_field("push_chat_period_ms", push_chat_period_ms_);
    s.store_field("push_chat_limit", push_chat_limit_);
    s.store_field("edit_time_limit", edit_time_limit_);
    s.store_field("revoke_time_limit", revoke_time_limit_);
    s.store_field("revoke_pm_time_limit", revoke_pm_time_limit_);
    s.store_field("rating_e_decay", rating_e_decay_);
    s.store_field("stickers_recent_limit", stickers_recent_limit_);
    s.store_field("channels_read_media_period", channels_read_media_period_);
    if (var0 & 1) { s.store_field("tmp_sessions", tmp_sessions_); }
    s.store_field("call_receive_timeout_ms", call_receive_timeout_ms_);
    s.store_field("call_ring_timeout_ms", call_ring_timeout_ms_);
    s.store_field("call_connect_timeout_ms", call_connect_timeout_ms_);
    s.store_field("call_packet_timeout_ms", call_packet_timeout_ms_);
    s.store_field("me_url_prefix", me_url_prefix_);
    if (var0 & 128) { s.store_field("autoupdate_url_prefix", autoupdate_url_prefix_); }
    if (var0 & 512) { s.store_field("gif_search_username", gif_search_username_); }
    if (var0 & 1024) { s.store_field("venue_search_username", venue_search_username_); }
    if (var0 & 2048) { s.store_field("img_search_username", img_search_username_); }
    if (var0 & 4096) { s.store_field("static_maps_provider", static_maps_provider_); }
    s.store_field("caption_length_max", caption_length_max_);
    s.store_field("message_length_max", message_length_max_);
    s.store_field("webfile_dc_id", webfile_dc_id_);
    if (var0 & 4) { s.store_field("suggested_lang_code", suggested_lang_code_); }
    if (var0 & 4) { s.store_field("lang_pack_version", lang_pack_version_); }
    if (var0 & 4) { s.store_field("base_lang_pack_version", base_lang_pack_version_); }
    if (var0 & 32768) { s.store_object_field("reactions_default", static_cast<const BaseObject *>(reactions_default_.get())); }
    if (var0 & 65536) { s.store_field("autologin_token", autologin_token_); }
    s.store_class_end();
  }
}

const std::int32_t contactBirthday::ID;

object_ptr<contactBirthday> contactBirthday::fetch(TlBufferParser &p) {
  return make_tl_object<contactBirthday>(p);
}

contactBirthday::contactBirthday(TlBufferParser &p)
  : contact_id_(TlFetchLong::parse(p))
  , birthday_(TlFetchBoxed<TlFetchObject<birthday>, 1821253126>::parse(p))
{}

void contactBirthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contactBirthday");
    s.store_field("contact_id", contact_id_);
    s.store_object_field("birthday", static_cast<const BaseObject *>(birthday_.get()));
    s.store_class_end();
  }
}

const std::int32_t fileHash::ID;

object_ptr<fileHash> fileHash::fetch(TlBufferParser &p) {
  return make_tl_object<fileHash>(p);
}

fileHash::fileHash(TlBufferParser &p)
  : offset_(TlFetchLong::parse(p))
  , limit_(TlFetchInt::parse(p))
  , hash_(TlFetchBytes<bytes>::parse(p))
{}

void fileHash::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "fileHash");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_bytes_field("hash", hash_);
    s.store_class_end();
  }
}

const std::int32_t foundStory::ID;

object_ptr<foundStory> foundStory::fetch(TlBufferParser &p) {
  return make_tl_object<foundStory>(p);
}

foundStory::foundStory(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , story_(TlFetchObject<StoryItem>::parse(p))
{}

void foundStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "foundStory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

object_ptr<InputBotInlineMessageID> InputBotInlineMessageID::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputBotInlineMessageID::ID:
      return inputBotInlineMessageID::fetch(p);
    case inputBotInlineMessageID64::ID:
      return inputBotInlineMessageID64::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

inputBotInlineMessageID::inputBotInlineMessageID(int32 dc_id_, int64 id_, int64 access_hash_)
  : dc_id_(dc_id_)
  , id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputBotInlineMessageID::ID;

object_ptr<InputBotInlineMessageID> inputBotInlineMessageID::fetch(TlBufferParser &p) {
  return make_tl_object<inputBotInlineMessageID>(p);
}

inputBotInlineMessageID::inputBotInlineMessageID(TlBufferParser &p)
  : dc_id_(TlFetchInt::parse(p))
  , id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputBotInlineMessageID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(dc_id_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputBotInlineMessageID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(dc_id_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputBotInlineMessageID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageID");
    s.store_field("dc_id", dc_id_);
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputBotInlineMessageID64::inputBotInlineMessageID64(int32 dc_id_, int64 owner_id_, int32 id_, int64 access_hash_)
  : dc_id_(dc_id_)
  , owner_id_(owner_id_)
  , id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputBotInlineMessageID64::ID;

object_ptr<InputBotInlineMessageID> inputBotInlineMessageID64::fetch(TlBufferParser &p) {
  return make_tl_object<inputBotInlineMessageID64>(p);
}

inputBotInlineMessageID64::inputBotInlineMessageID64(TlBufferParser &p)
  : dc_id_(TlFetchInt::parse(p))
  , owner_id_(TlFetchLong::parse(p))
  , id_(TlFetchInt::parse(p))
  , access_hash_(TlFetchLong::parse(p))
{}

void inputBotInlineMessageID64::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(dc_id_, s);
  TlStoreBinary::store(owner_id_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputBotInlineMessageID64::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(dc_id_, s);
  TlStoreBinary::store(owner_id_, s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputBotInlineMessageID64::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageID64");
    s.store_field("dc_id", dc_id_);
    s.store_field("owner_id", owner_id_);
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputBusinessBotRecipients::inputBusinessBotRecipients(int32 flags_, bool existing_chats_, bool new_chats_, bool contacts_, bool non_contacts_, bool exclude_selected_, array<object_ptr<InputUser>> &&users_, array<object_ptr<InputUser>> &&exclude_users_)
  : flags_(flags_)
  , existing_chats_(existing_chats_)
  , new_chats_(new_chats_)
  , contacts_(contacts_)
  , non_contacts_(non_contacts_)
  , exclude_selected_(exclude_selected_)
  , users_(std::move(users_))
  , exclude_users_(std::move(exclude_users_))
{}

const std::int32_t inputBusinessBotRecipients::ID;

void inputBusinessBotRecipients::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5)), s);
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s); }
  if (var0 & 64) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(exclude_users_, s); }
}

void inputBusinessBotRecipients::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5)), s);
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(users_, s); }
  if (var0 & 64) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(exclude_users_, s); }
}

void inputBusinessBotRecipients::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessBotRecipients");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (existing_chats_ << 0) | (new_chats_ << 1) | (contacts_ << 2) | (non_contacts_ << 3) | (exclude_selected_ << 5)));
    if (var0 & 1) { s.store_field("existing_chats", true); }
    if (var0 & 2) { s.store_field("new_chats", true); }
    if (var0 & 4) { s.store_field("contacts", true); }
    if (var0 & 8) { s.store_field("non_contacts", true); }
    if (var0 & 32) { s.store_field("exclude_selected", true); }
    if (var0 & 16) { { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 64) { { s.store_vector_begin("exclude_users", exclude_users_.size()); for (const auto &_value : exclude_users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

const std::int32_t inputChatThemeEmpty::ID;

void inputChatThemeEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputChatThemeEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputChatThemeEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatThemeEmpty");
    s.store_class_end();
  }
}

inputChatTheme::inputChatTheme(string const &emoticon_)
  : emoticon_(emoticon_)
{}

const std::int32_t inputChatTheme::ID;

void inputChatTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void inputChatTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void inputChatTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatTheme");
    s.store_field("emoticon", emoticon_);
    s.store_class_end();
  }
}

inputChatThemeUniqueGift::inputChatThemeUniqueGift(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputChatThemeUniqueGift::ID;

void inputChatThemeUniqueGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputChatThemeUniqueGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputChatThemeUniqueGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatThemeUniqueGift");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

const std::int32_t inputCheckPasswordEmpty::ID;

void inputCheckPasswordEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputCheckPasswordEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputCheckPasswordEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCheckPasswordEmpty");
    s.store_class_end();
  }
}

inputCheckPasswordSRP::inputCheckPasswordSRP(int64 srp_id_, bytes &&A_, bytes &&M1_)
  : srp_id_(srp_id_)
  , A_(std::move(A_))
  , M1_(std::move(M1_))
{}

const std::int32_t inputCheckPasswordSRP::ID;

void inputCheckPasswordSRP::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(srp_id_, s);
  TlStoreString::store(A_, s);
  TlStoreString::store(M1_, s);
}

void inputCheckPasswordSRP::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(srp_id_, s);
  TlStoreString::store(A_, s);
  TlStoreString::store(M1_, s);
}

void inputCheckPasswordSRP::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputCheckPasswordSRP");
    s.store_field("srp_id", srp_id_);
    s.store_bytes_field("A", A_);
    s.store_bytes_field("M1", M1_);
    s.store_class_end();
  }
}

const std::int32_t inputClientProxy::ID;

void inputClientProxy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputClientProxy");
    s.store_field("address", address_);
    s.store_field("port", port_);
    s.store_class_end();
  }
}

inputEncryptedChat::inputEncryptedChat(int32 chat_id_, int64 access_hash_)
  : chat_id_(chat_id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputEncryptedChat::ID;

void inputEncryptedChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputEncryptedChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputEncryptedChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEncryptedChat");
    s.store_field("chat_id", chat_id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

object_ptr<InputGeoPoint> InputGeoPoint::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputGeoPointEmpty::ID:
      return inputGeoPointEmpty::fetch(p);
    case inputGeoPoint::ID:
      return inputGeoPoint::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputGeoPointEmpty::ID;

object_ptr<InputGeoPoint> inputGeoPointEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputGeoPointEmpty>();
}

void inputGeoPointEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputGeoPointEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputGeoPointEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGeoPointEmpty");
    s.store_class_end();
  }
}

inputGeoPoint::inputGeoPoint()
  : flags_()
  , lat_()
  , long_()
  , accuracy_radius_()
{}

inputGeoPoint::inputGeoPoint(int32 flags_, double lat_, double long_, int32 accuracy_radius_)
  : flags_(flags_)
  , lat_(lat_)
  , long_(long_)
  , accuracy_radius_(accuracy_radius_)
{}

const std::int32_t inputGeoPoint::ID;

object_ptr<InputGeoPoint> inputGeoPoint::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputGeoPoint> res = make_tl_object<inputGeoPoint>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->lat_ = TlFetchDouble::parse(p);
  res->long_ = TlFetchDouble::parse(p);
  if (var0 & 1) { res->accuracy_radius_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputGeoPoint::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(lat_, s);
  TlStoreBinary::store(long_, s);
  if (var0 & 1) { TlStoreBinary::store(accuracy_radius_, s); }
}

void inputGeoPoint::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(lat_, s);
  TlStoreBinary::store(long_, s);
  if (var0 & 1) { TlStoreBinary::store(accuracy_radius_, s); }
}

void inputGeoPoint::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputGeoPoint");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("lat", lat_);
    s.store_field("long", long_);
    if (var0 & 1) { s.store_field("accuracy_radius", accuracy_radius_); }
    s.store_class_end();
  }
}

object_ptr<InputMedia> InputMedia::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputMediaEmpty::ID;

object_ptr<InputMedia> inputMediaEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaEmpty>();
}

void inputMediaEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMediaEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMediaEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaEmpty");
    s.store_class_end();
  }
}

inputMediaUploadedPhoto::inputMediaUploadedPhoto()
  : flags_()
  , spoiler_()
  , live_photo_()
  , file_()
  , stickers_()
  , ttl_seconds_()
  , video_()
{}

inputMediaUploadedPhoto::inputMediaUploadedPhoto(int32 flags_, bool spoiler_, bool live_photo_, object_ptr<InputFile> &&file_, array<object_ptr<InputDocument>> &&stickers_, int32 ttl_seconds_, object_ptr<InputDocument> &&video_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , live_photo_(live_photo_)
  , file_(std::move(file_))
  , stickers_(std::move(stickers_))
  , ttl_seconds_(ttl_seconds_)
  , video_(std::move(video_))
{}

const std::int32_t inputMediaUploadedPhoto::ID;

object_ptr<InputMedia> inputMediaUploadedPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaUploadedPhoto> res = make_tl_object<inputMediaUploadedPhoto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 4) != 0;
  res->live_photo_ = (var0 & 8) != 0;
  res->file_ = TlFetchObject<InputFile>::parse(p);
  if (var0 & 1) { res->stickers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputDocument>>, 481674261>::parse(p); }
  if (var0 & 2) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->video_ = TlFetchObject<InputDocument>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaUploadedPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 2) | (live_photo_ << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickers_, s); }
  if (var0 & 2) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
}

void inputMediaUploadedPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 2) | (live_photo_ << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickers_, s); }
  if (var0 & 2) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
}

void inputMediaUploadedPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaUploadedPhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 2) | (live_photo_ << 3)));
    if (var0 & 4) { s.store_field("spoiler", true); }
    if (var0 & 8) { s.store_field("live_photo", true); }
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    if (var0 & 1) { { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_field("ttl_seconds", ttl_seconds_); }
    if (var0 & 8) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    s.store_class_end();
  }
}

inputMediaPhoto::inputMediaPhoto()
  : flags_()
  , spoiler_()
  , live_photo_()
  , id_()
  , ttl_seconds_()
  , video_()
{}

inputMediaPhoto::inputMediaPhoto(int32 flags_, bool spoiler_, bool live_photo_, object_ptr<InputPhoto> &&id_, int32 ttl_seconds_, object_ptr<InputDocument> &&video_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , live_photo_(live_photo_)
  , id_(std::move(id_))
  , ttl_seconds_(ttl_seconds_)
  , video_(std::move(video_))
{}

const std::int32_t inputMediaPhoto::ID;

object_ptr<InputMedia> inputMediaPhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaPhoto> res = make_tl_object<inputMediaPhoto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 2) != 0;
  res->live_photo_ = (var0 & 4) != 0;
  res->id_ = TlFetchObject<InputPhoto>::parse(p);
  if (var0 & 1) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->video_ = TlFetchObject<InputDocument>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1) | (live_photo_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
}

void inputMediaPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1) | (live_photo_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(video_, s); }
}

void inputMediaPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaPhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 1) | (live_photo_ << 2)));
    if (var0 & 2) { s.store_field("spoiler", true); }
    if (var0 & 4) { s.store_field("live_photo", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    if (var0 & 1) { s.store_field("ttl_seconds", ttl_seconds_); }
    if (var0 & 4) { s.store_object_field("video", static_cast<const BaseObject *>(video_.get())); }
    s.store_class_end();
  }
}

inputMediaGeoPoint::inputMediaGeoPoint(object_ptr<InputGeoPoint> &&geo_point_)
  : geo_point_(std::move(geo_point_))
{}

const std::int32_t inputMediaGeoPoint::ID;

object_ptr<InputMedia> inputMediaGeoPoint::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaGeoPoint>(p);
}

inputMediaGeoPoint::inputMediaGeoPoint(TlBufferParser &p)
  : geo_point_(TlFetchObject<InputGeoPoint>::parse(p))
{}

void inputMediaGeoPoint::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
}

void inputMediaGeoPoint::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
}

void inputMediaGeoPoint::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaGeoPoint");
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    s.store_class_end();
  }
}

inputMediaContact::inputMediaContact(string const &phone_number_, string const &first_name_, string const &last_name_, string const &vcard_)
  : phone_number_(phone_number_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , vcard_(vcard_)
{}

const std::int32_t inputMediaContact::ID;

object_ptr<InputMedia> inputMediaContact::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaContact>(p);
}

inputMediaContact::inputMediaContact(TlBufferParser &p)
  : phone_number_(TlFetchString<string>::parse(p))
  , first_name_(TlFetchString<string>::parse(p))
  , last_name_(TlFetchString<string>::parse(p))
  , vcard_(TlFetchString<string>::parse(p))
{}

void inputMediaContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(vcard_, s);
}

void inputMediaContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(vcard_, s);
}

void inputMediaContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaContact");
    s.store_field("phone_number", phone_number_);
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("vcard", vcard_);
    s.store_class_end();
  }
}

inputMediaUploadedDocument::inputMediaUploadedDocument()
  : flags_()
  , nosound_video_()
  , force_file_()
  , spoiler_()
  , file_()
  , thumb_()
  , mime_type_()
  , attributes_()
  , stickers_()
  , video_cover_()
  , video_timestamp_()
  , ttl_seconds_()
{}

inputMediaUploadedDocument::inputMediaUploadedDocument(int32 flags_, bool nosound_video_, bool force_file_, bool spoiler_, object_ptr<InputFile> &&file_, object_ptr<InputFile> &&thumb_, string const &mime_type_, array<object_ptr<DocumentAttribute>> &&attributes_, array<object_ptr<InputDocument>> &&stickers_, object_ptr<InputPhoto> &&video_cover_, int32 video_timestamp_, int32 ttl_seconds_)
  : flags_(flags_)
  , nosound_video_(nosound_video_)
  , force_file_(force_file_)
  , spoiler_(spoiler_)
  , file_(std::move(file_))
  , thumb_(std::move(thumb_))
  , mime_type_(mime_type_)
  , attributes_(std::move(attributes_))
  , stickers_(std::move(stickers_))
  , video_cover_(std::move(video_cover_))
  , video_timestamp_(video_timestamp_)
  , ttl_seconds_(ttl_seconds_)
{}

const std::int32_t inputMediaUploadedDocument::ID;

object_ptr<InputMedia> inputMediaUploadedDocument::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaUploadedDocument> res = make_tl_object<inputMediaUploadedDocument>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->nosound_video_ = (var0 & 8) != 0;
  res->force_file_ = (var0 & 16) != 0;
  res->spoiler_ = (var0 & 32) != 0;
  res->file_ = TlFetchObject<InputFile>::parse(p);
  if (var0 & 4) { res->thumb_ = TlFetchObject<InputFile>::parse(p); }
  res->mime_type_ = TlFetchString<string>::parse(p);
  res->attributes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<DocumentAttribute>>, 481674261>::parse(p);
  if (var0 & 1) { res->stickers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputDocument>>, 481674261>::parse(p); }
  if (var0 & 64) { res->video_cover_ = TlFetchObject<InputPhoto>::parse(p); }
  if (var0 & 128) { res->video_timestamp_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaUploadedDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (nosound_video_ << 3) | (force_file_ << 4) | (spoiler_ << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickers_, s); }
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 128) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 2) { TlStoreBinary::store(ttl_seconds_, s); }
}

void inputMediaUploadedDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (nosound_video_ << 3) | (force_file_ << 4) | (spoiler_ << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(thumb_, s); }
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickers_, s); }
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 128) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 2) { TlStoreBinary::store(ttl_seconds_, s); }
}

void inputMediaUploadedDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaUploadedDocument");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (nosound_video_ << 3) | (force_file_ << 4) | (spoiler_ << 5)));
    if (var0 & 8) { s.store_field("nosound_video", true); }
    if (var0 & 16) { s.store_field("force_file", true); }
    if (var0 & 32) { s.store_field("spoiler", true); }
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    if (var0 & 4) { s.store_object_field("thumb", static_cast<const BaseObject *>(thumb_.get())); }
    s.store_field("mime_type", mime_type_);
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 64) { s.store_object_field("video_cover", static_cast<const BaseObject *>(video_cover_.get())); }
    if (var0 & 128) { s.store_field("video_timestamp", video_timestamp_); }
    if (var0 & 2) { s.store_field("ttl_seconds", ttl_seconds_); }
    s.store_class_end();
  }
}

inputMediaDocument::inputMediaDocument()
  : flags_()
  , spoiler_()
  , id_()
  , video_cover_()
  , video_timestamp_()
  , ttl_seconds_()
  , query_()
{}

inputMediaDocument::inputMediaDocument(int32 flags_, bool spoiler_, object_ptr<InputDocument> &&id_, object_ptr<InputPhoto> &&video_cover_, int32 video_timestamp_, int32 ttl_seconds_, string const &query_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , id_(std::move(id_))
  , video_cover_(std::move(video_cover_))
  , video_timestamp_(video_timestamp_)
  , ttl_seconds_(ttl_seconds_)
  , query_(query_)
{}

const std::int32_t inputMediaDocument::ID;

object_ptr<InputMedia> inputMediaDocument::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaDocument> res = make_tl_object<inputMediaDocument>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 4) != 0;
  res->id_ = TlFetchObject<InputDocument>::parse(p);
  if (var0 & 8) { res->video_cover_ = TlFetchObject<InputPhoto>::parse(p); }
  if (var0 & 16) { res->video_timestamp_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->query_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 16) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 2) { TlStoreString::store(query_, s); }
}

void inputMediaDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 16) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 2) { TlStoreString::store(query_, s); }
}

void inputMediaDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaDocument");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 2)));
    if (var0 & 4) { s.store_field("spoiler", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    if (var0 & 8) { s.store_object_field("video_cover", static_cast<const BaseObject *>(video_cover_.get())); }
    if (var0 & 16) { s.store_field("video_timestamp", video_timestamp_); }
    if (var0 & 1) { s.store_field("ttl_seconds", ttl_seconds_); }
    if (var0 & 2) { s.store_field("query", query_); }
    s.store_class_end();
  }
}

inputMediaVenue::inputMediaVenue(object_ptr<InputGeoPoint> &&geo_point_, string const &title_, string const &address_, string const &provider_, string const &venue_id_, string const &venue_type_)
  : geo_point_(std::move(geo_point_))
  , title_(title_)
  , address_(address_)
  , provider_(provider_)
  , venue_id_(venue_id_)
  , venue_type_(venue_type_)
{}

const std::int32_t inputMediaVenue::ID;

object_ptr<InputMedia> inputMediaVenue::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaVenue>(p);
}

inputMediaVenue::inputMediaVenue(TlBufferParser &p)
  : geo_point_(TlFetchObject<InputGeoPoint>::parse(p))
  , title_(TlFetchString<string>::parse(p))
  , address_(TlFetchString<string>::parse(p))
  , provider_(TlFetchString<string>::parse(p))
  , venue_id_(TlFetchString<string>::parse(p))
  , venue_type_(TlFetchString<string>::parse(p))
{}

void inputMediaVenue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
}

void inputMediaVenue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
}

void inputMediaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaVenue");
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("venue_id", venue_id_);
    s.store_field("venue_type", venue_type_);
    s.store_class_end();
  }
}

inputMediaPhotoExternal::inputMediaPhotoExternal()
  : flags_()
  , spoiler_()
  , url_()
  , ttl_seconds_()
{}

inputMediaPhotoExternal::inputMediaPhotoExternal(int32 flags_, bool spoiler_, string const &url_, int32 ttl_seconds_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , url_(url_)
  , ttl_seconds_(ttl_seconds_)
{}

const std::int32_t inputMediaPhotoExternal::ID;

object_ptr<InputMedia> inputMediaPhotoExternal::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaPhotoExternal> res = make_tl_object<inputMediaPhotoExternal>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 2) != 0;
  res->url_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaPhotoExternal::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1)), s);
  TlStoreString::store(url_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
}

void inputMediaPhotoExternal::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1)), s);
  TlStoreString::store(url_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
}

void inputMediaPhotoExternal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaPhotoExternal");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 1)));
    if (var0 & 2) { s.store_field("spoiler", true); }
    s.store_field("url", url_);
    if (var0 & 1) { s.store_field("ttl_seconds", ttl_seconds_); }
    s.store_class_end();
  }
}

inputMediaDocumentExternal::inputMediaDocumentExternal()
  : flags_()
  , spoiler_()
  , url_()
  , ttl_seconds_()
  , video_cover_()
  , video_timestamp_()
{}

inputMediaDocumentExternal::inputMediaDocumentExternal(int32 flags_, bool spoiler_, string const &url_, int32 ttl_seconds_, object_ptr<InputPhoto> &&video_cover_, int32 video_timestamp_)
  : flags_(flags_)
  , spoiler_(spoiler_)
  , url_(url_)
  , ttl_seconds_(ttl_seconds_)
  , video_cover_(std::move(video_cover_))
  , video_timestamp_(video_timestamp_)
{}

const std::int32_t inputMediaDocumentExternal::ID;

object_ptr<InputMedia> inputMediaDocumentExternal::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaDocumentExternal> res = make_tl_object<inputMediaDocumentExternal>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->spoiler_ = (var0 & 2) != 0;
  res->url_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->ttl_seconds_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->video_cover_ = TlFetchObject<InputPhoto>::parse(p); }
  if (var0 & 8) { res->video_timestamp_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaDocumentExternal::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1)), s);
  TlStoreString::store(url_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 8) { TlStoreBinary::store(video_timestamp_, s); }
}

void inputMediaDocumentExternal::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (spoiler_ << 1)), s);
  TlStoreString::store(url_, s);
  if (var0 & 1) { TlStoreBinary::store(ttl_seconds_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(video_cover_, s); }
  if (var0 & 8) { TlStoreBinary::store(video_timestamp_, s); }
}

void inputMediaDocumentExternal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaDocumentExternal");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (spoiler_ << 1)));
    if (var0 & 2) { s.store_field("spoiler", true); }
    s.store_field("url", url_);
    if (var0 & 1) { s.store_field("ttl_seconds", ttl_seconds_); }
    if (var0 & 4) { s.store_object_field("video_cover", static_cast<const BaseObject *>(video_cover_.get())); }
    if (var0 & 8) { s.store_field("video_timestamp", video_timestamp_); }
    s.store_class_end();
  }
}

inputMediaGame::inputMediaGame(object_ptr<InputGame> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t inputMediaGame::ID;

object_ptr<InputMedia> inputMediaGame::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaGame>(p);
}

inputMediaGame::inputMediaGame(TlBufferParser &p)
  : id_(TlFetchObject<InputGame>::parse(p))
{}

void inputMediaGame::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputMediaGame::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void inputMediaGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaGame");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

inputMediaInvoice::inputMediaInvoice()
  : flags_()
  , title_()
  , description_()
  , photo_()
  , invoice_()
  , payload_()
  , provider_()
  , provider_data_()
  , start_param_()
  , extended_media_()
{}

inputMediaInvoice::inputMediaInvoice(int32 flags_, string const &title_, string const &description_, object_ptr<inputWebDocument> &&photo_, object_ptr<invoice> &&invoice_, bytes &&payload_, string const &provider_, object_ptr<dataJSON> &&provider_data_, string const &start_param_, object_ptr<InputMedia> &&extended_media_)
  : flags_(flags_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , invoice_(std::move(invoice_))
  , payload_(std::move(payload_))
  , provider_(provider_)
  , provider_data_(std::move(provider_data_))
  , start_param_(start_param_)
  , extended_media_(std::move(extended_media_))
{}

const std::int32_t inputMediaInvoice::ID;

object_ptr<InputMedia> inputMediaInvoice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaInvoice> res = make_tl_object<inputMediaInvoice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->photo_ = TlFetchBoxed<TlFetchObject<inputWebDocument>, -1678949555>::parse(p); }
  res->invoice_ = TlFetchBoxed<TlFetchObject<invoice>, 77522308>::parse(p);
  res->payload_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 8) { res->provider_ = TlFetchString<string>::parse(p); }
  res->provider_data_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
  if (var0 & 2) { res->start_param_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->extended_media_ = TlFetchObject<InputMedia>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaInvoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1678949555>::store(photo_, s); }
  TlStoreBoxed<TlStoreObject, 77522308>::store(invoice_, s);
  TlStoreString::store(payload_, s);
  if (var0 & 8) { TlStoreString::store(provider_, s); }
  TlStoreBoxed<TlStoreObject, 2104790276>::store(provider_data_, s);
  if (var0 & 2) { TlStoreString::store(start_param_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(extended_media_, s); }
}

void inputMediaInvoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1678949555>::store(photo_, s); }
  TlStoreBoxed<TlStoreObject, 77522308>::store(invoice_, s);
  TlStoreString::store(payload_, s);
  if (var0 & 8) { TlStoreString::store(provider_, s); }
  TlStoreBoxed<TlStoreObject, 2104790276>::store(provider_data_, s);
  if (var0 & 2) { TlStoreString::store(start_param_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(extended_media_, s); }
}

void inputMediaInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaInvoice");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 1) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_bytes_field("payload", payload_);
    if (var0 & 8) { s.store_field("provider", provider_); }
    s.store_object_field("provider_data", static_cast<const BaseObject *>(provider_data_.get()));
    if (var0 & 2) { s.store_field("start_param", start_param_); }
    if (var0 & 4) { s.store_object_field("extended_media", static_cast<const BaseObject *>(extended_media_.get())); }
    s.store_class_end();
  }
}

inputMediaGeoLive::inputMediaGeoLive()
  : flags_()
  , stopped_()
  , geo_point_()
  , heading_()
  , period_()
  , proximity_notification_radius_()
{}

inputMediaGeoLive::inputMediaGeoLive(int32 flags_, bool stopped_, object_ptr<InputGeoPoint> &&geo_point_, int32 heading_, int32 period_, int32 proximity_notification_radius_)
  : flags_(flags_)
  , stopped_(stopped_)
  , geo_point_(std::move(geo_point_))
  , heading_(heading_)
  , period_(period_)
  , proximity_notification_radius_(proximity_notification_radius_)
{}

const std::int32_t inputMediaGeoLive::ID;

object_ptr<InputMedia> inputMediaGeoLive::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaGeoLive> res = make_tl_object<inputMediaGeoLive>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->stopped_ = (var0 & 1) != 0;
  res->geo_point_ = TlFetchObject<InputGeoPoint>::parse(p);
  if (var0 & 4) { res->heading_ = TlFetchInt::parse(p); }
  if (var0 & 2) { res->period_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->proximity_notification_radius_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaGeoLive::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (stopped_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  if (var0 & 4) { TlStoreBinary::store(heading_, s); }
  if (var0 & 2) { TlStoreBinary::store(period_, s); }
  if (var0 & 8) { TlStoreBinary::store(proximity_notification_radius_, s); }
}

void inputMediaGeoLive::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (stopped_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  if (var0 & 4) { TlStoreBinary::store(heading_, s); }
  if (var0 & 2) { TlStoreBinary::store(period_, s); }
  if (var0 & 8) { TlStoreBinary::store(proximity_notification_radius_, s); }
}

void inputMediaGeoLive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaGeoLive");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (stopped_ << 0)));
    if (var0 & 1) { s.store_field("stopped", true); }
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    if (var0 & 4) { s.store_field("heading", heading_); }
    if (var0 & 2) { s.store_field("period", period_); }
    if (var0 & 8) { s.store_field("proximity_notification_radius", proximity_notification_radius_); }
    s.store_class_end();
  }
}

inputMediaPoll::inputMediaPoll()
  : flags_()
  , poll_()
  , correct_answers_()
  , attached_media_()
  , solution_()
  , solution_entities_()
  , solution_media_()
{}

inputMediaPoll::inputMediaPoll(int32 flags_, object_ptr<poll> &&poll_, array<int32> &&correct_answers_, object_ptr<InputMedia> &&attached_media_, string const &solution_, array<object_ptr<MessageEntity>> &&solution_entities_, object_ptr<InputMedia> &&solution_media_)
  : flags_(flags_)
  , poll_(std::move(poll_))
  , correct_answers_(std::move(correct_answers_))
  , attached_media_(std::move(attached_media_))
  , solution_(solution_)
  , solution_entities_(std::move(solution_entities_))
  , solution_media_(std::move(solution_media_))
{}

const std::int32_t inputMediaPoll::ID;

object_ptr<InputMedia> inputMediaPoll::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaPoll> res = make_tl_object<inputMediaPoll>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->poll_ = TlFetchBoxed<TlFetchObject<poll>, -1203610647>::parse(p);
  if (var0 & 1) { res->correct_answers_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (var0 & 8) { res->attached_media_ = TlFetchObject<InputMedia>::parse(p); }
  if (var0 & 2) { res->solution_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->solution_entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 4) { res->solution_media_ = TlFetchObject<InputMedia>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaPoll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, -1203610647>::store(poll_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(correct_answers_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(attached_media_, s); }
  if (var0 & 2) { TlStoreString::store(solution_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(solution_entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(solution_media_, s); }
}

void inputMediaPoll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, -1203610647>::store(poll_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(correct_answers_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(attached_media_, s); }
  if (var0 & 2) { TlStoreString::store(solution_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(solution_entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(solution_media_, s); }
}

void inputMediaPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaPoll");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("poll", static_cast<const BaseObject *>(poll_.get()));
    if (var0 & 1) { { s.store_vector_begin("correct_answers", correct_answers_.size()); for (const auto &_value : correct_answers_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 8) { s.store_object_field("attached_media", static_cast<const BaseObject *>(attached_media_.get())); }
    if (var0 & 2) { s.store_field("solution", solution_); }
    if (var0 & 2) { { s.store_vector_begin("solution_entities", solution_entities_.size()); for (const auto &_value : solution_entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_object_field("solution_media", static_cast<const BaseObject *>(solution_media_.get())); }
    s.store_class_end();
  }
}

inputMediaDice::inputMediaDice(string const &emoticon_)
  : emoticon_(emoticon_)
{}

const std::int32_t inputMediaDice::ID;

object_ptr<InputMedia> inputMediaDice::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaDice>(p);
}

inputMediaDice::inputMediaDice(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
{}

void inputMediaDice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void inputMediaDice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void inputMediaDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaDice");
    s.store_field("emoticon", emoticon_);
    s.store_class_end();
  }
}

inputMediaStory::inputMediaStory(object_ptr<InputPeer> &&peer_, int32 id_)
  : peer_(std::move(peer_))
  , id_(id_)
{}

const std::int32_t inputMediaStory::ID;

object_ptr<InputMedia> inputMediaStory::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaStory>(p);
}

inputMediaStory::inputMediaStory(TlBufferParser &p)
  : peer_(TlFetchObject<InputPeer>::parse(p))
  , id_(TlFetchInt::parse(p))
{}

void inputMediaStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void inputMediaStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void inputMediaStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaStory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

inputMediaWebPage::inputMediaWebPage()
  : flags_()
  , force_large_media_()
  , force_small_media_()
  , optional_()
  , url_()
{}

inputMediaWebPage::inputMediaWebPage(int32 flags_, bool force_large_media_, bool force_small_media_, bool optional_, string const &url_)
  : flags_(flags_)
  , force_large_media_(force_large_media_)
  , force_small_media_(force_small_media_)
  , optional_(optional_)
  , url_(url_)
{}

const std::int32_t inputMediaWebPage::ID;

object_ptr<InputMedia> inputMediaWebPage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaWebPage> res = make_tl_object<inputMediaWebPage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->force_large_media_ = (var0 & 1) != 0;
  res->force_small_media_ = (var0 & 2) != 0;
  res->optional_ = (var0 & 4) != 0;
  res->url_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaWebPage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (force_large_media_ << 0) | (force_small_media_ << 1) | (optional_ << 2)), s);
  TlStoreString::store(url_, s);
}

void inputMediaWebPage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (force_large_media_ << 0) | (force_small_media_ << 1) | (optional_ << 2)), s);
  TlStoreString::store(url_, s);
}

void inputMediaWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaWebPage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (force_large_media_ << 0) | (force_small_media_ << 1) | (optional_ << 2)));
    if (var0 & 1) { s.store_field("force_large_media", true); }
    if (var0 & 2) { s.store_field("force_small_media", true); }
    if (var0 & 4) { s.store_field("optional", true); }
    s.store_field("url", url_);
    s.store_class_end();
  }
}

inputMediaPaidMedia::inputMediaPaidMedia()
  : flags_()
  , stars_amount_()
  , extended_media_()
  , payload_()
{}

inputMediaPaidMedia::inputMediaPaidMedia(int32 flags_, int64 stars_amount_, array<object_ptr<InputMedia>> &&extended_media_, string const &payload_)
  : flags_(flags_)
  , stars_amount_(stars_amount_)
  , extended_media_(std::move(extended_media_))
  , payload_(payload_)
{}

const std::int32_t inputMediaPaidMedia::ID;

object_ptr<InputMedia> inputMediaPaidMedia::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputMediaPaidMedia> res = make_tl_object<inputMediaPaidMedia>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->stars_amount_ = TlFetchLong::parse(p);
  res->extended_media_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InputMedia>>, 481674261>::parse(p);
  if (var0 & 1) { res->payload_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputMediaPaidMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(stars_amount_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(extended_media_, s);
  if (var0 & 1) { TlStoreString::store(payload_, s); }
}

void inputMediaPaidMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(stars_amount_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(extended_media_, s);
  if (var0 & 1) { TlStoreString::store(payload_, s); }
}

void inputMediaPaidMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaPaidMedia");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("stars_amount", stars_amount_);
    { s.store_vector_begin("extended_media", extended_media_.size()); for (const auto &_value : extended_media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("payload", payload_); }
    s.store_class_end();
  }
}

inputMediaTodo::inputMediaTodo(object_ptr<todoList> &&todo_)
  : todo_(std::move(todo_))
{}

const std::int32_t inputMediaTodo::ID;

object_ptr<InputMedia> inputMediaTodo::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaTodo>(p);
}

inputMediaTodo::inputMediaTodo(TlBufferParser &p)
  : todo_(TlFetchBoxed<TlFetchObject<todoList>, 1236871718>::parse(p))
{}

void inputMediaTodo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 1236871718>::store(todo_, s);
}

void inputMediaTodo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, 1236871718>::store(todo_, s);
}

void inputMediaTodo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaTodo");
    s.store_object_field("todo", static_cast<const BaseObject *>(todo_.get()));
    s.store_class_end();
  }
}

inputMediaStakeDice::inputMediaStakeDice(string const &game_hash_, int64 ton_amount_, bytes &&client_seed_)
  : game_hash_(game_hash_)
  , ton_amount_(ton_amount_)
  , client_seed_(std::move(client_seed_))
{}

const std::int32_t inputMediaStakeDice::ID;

object_ptr<InputMedia> inputMediaStakeDice::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaStakeDice>(p);
}

inputMediaStakeDice::inputMediaStakeDice(TlBufferParser &p)
  : game_hash_(TlFetchString<string>::parse(p))
  , ton_amount_(TlFetchLong::parse(p))
  , client_seed_(TlFetchBytes<bytes>::parse(p))
{}

void inputMediaStakeDice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(game_hash_, s);
  TlStoreBinary::store(ton_amount_, s);
  TlStoreString::store(client_seed_, s);
}

void inputMediaStakeDice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(game_hash_, s);
  TlStoreBinary::store(ton_amount_, s);
  TlStoreString::store(client_seed_, s);
}

void inputMediaStakeDice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaStakeDice");
    s.store_field("game_hash", game_hash_);
    s.store_field("ton_amount", ton_amount_);
    s.store_bytes_field("client_seed", client_seed_);
    s.store_class_end();
  }
}

inputThemeSettings::inputThemeSettings(int32 flags_, bool message_colors_animated_, object_ptr<BaseTheme> &&base_theme_, int32 accent_color_, int32 outbox_accent_color_, array<int32> &&message_colors_, object_ptr<InputWallPaper> &&wallpaper_, object_ptr<wallPaperSettings> &&wallpaper_settings_)
  : flags_(flags_)
  , message_colors_animated_(message_colors_animated_)
  , base_theme_(std::move(base_theme_))
  , accent_color_(accent_color_)
  , outbox_accent_color_(outbox_accent_color_)
  , message_colors_(std::move(message_colors_))
  , wallpaper_(std::move(wallpaper_))
  , wallpaper_settings_(std::move(wallpaper_settings_))
{}

const std::int32_t inputThemeSettings::ID;

void inputThemeSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (message_colors_animated_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(base_theme_, s);
  TlStoreBinary::store(accent_color_, s);
  if (var0 & 8) { TlStoreBinary::store(outbox_accent_color_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(message_colors_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 925826256>::store(wallpaper_settings_, s); }
}

void inputThemeSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (message_colors_animated_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(base_theme_, s);
  TlStoreBinary::store(accent_color_, s);
  if (var0 & 8) { TlStoreBinary::store(outbox_accent_color_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(message_colors_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 925826256>::store(wallpaper_settings_, s); }
}

void inputThemeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputThemeSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (message_colors_animated_ << 2)));
    if (var0 & 4) { s.store_field("message_colors_animated", true); }
    s.store_object_field("base_theme", static_cast<const BaseObject *>(base_theme_.get()));
    s.store_field("accent_color", accent_color_);
    if (var0 & 8) { s.store_field("outbox_accent_color", outbox_accent_color_); }
    if (var0 & 1) { { s.store_vector_begin("message_colors", message_colors_.size()); for (const auto &_value : message_colors_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 2) { s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get())); }
    if (var0 & 2) { s.store_object_field("wallpaper_settings", static_cast<const BaseObject *>(wallpaper_settings_.get())); }
    s.store_class_end();
  }
}

inputWallPaper::inputWallPaper(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputWallPaper::ID;

void inputWallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputWallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWallPaper");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputWallPaperSlug::inputWallPaperSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputWallPaperSlug::ID;

void inputWallPaperSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputWallPaperSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputWallPaperSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWallPaperSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

inputWallPaperNoFile::inputWallPaperNoFile(int64 id_)
  : id_(id_)
{}

const std::int32_t inputWallPaperNoFile::ID;

void inputWallPaperNoFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputWallPaperNoFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputWallPaperNoFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWallPaperNoFile");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

inputWebFileLocation::inputWebFileLocation(string const &url_, int64 access_hash_)
  : url_(url_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputWebFileLocation::ID;

void inputWebFileLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputWebFileLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputWebFileLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWebFileLocation");
    s.store_field("url", url_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputWebFileGeoPointLocation::inputWebFileGeoPointLocation(object_ptr<InputGeoPoint> &&geo_point_, int64 access_hash_, int32 w_, int32 h_, int32 zoom_, int32 scale_)
  : geo_point_(std::move(geo_point_))
  , access_hash_(access_hash_)
  , w_(w_)
  , h_(h_)
  , zoom_(zoom_)
  , scale_(scale_)
{}

const std::int32_t inputWebFileGeoPointLocation::ID;

void inputWebFileGeoPointLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(zoom_, s);
  TlStoreBinary::store(scale_, s);
}

void inputWebFileGeoPointLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(zoom_, s);
  TlStoreBinary::store(scale_, s);
}

void inputWebFileGeoPointLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWebFileGeoPointLocation");
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    s.store_field("access_hash", access_hash_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_field("zoom", zoom_);
    s.store_field("scale", scale_);
    s.store_class_end();
  }
}

inputWebFileAudioAlbumThumbLocation::inputWebFileAudioAlbumThumbLocation(int32 flags_, bool small_, object_ptr<InputDocument> &&document_, string const &title_, string const &performer_)
  : flags_(flags_)
  , small_(small_)
  , document_(std::move(document_))
  , title_(title_)
  , performer_(performer_)
{}

const std::int32_t inputWebFileAudioAlbumThumbLocation::ID;

void inputWebFileAudioAlbumThumbLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (small_ << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreString::store(performer_, s); }
}

void inputWebFileAudioAlbumThumbLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (small_ << 2)), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(document_, s); }
  if (var0 & 2) { TlStoreString::store(title_, s); }
  if (var0 & 2) { TlStoreString::store(performer_, s); }
}

void inputWebFileAudioAlbumThumbLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWebFileAudioAlbumThumbLocation");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (small_ << 2)));
    if (var0 & 4) { s.store_field("small", true); }
    if (var0 & 1) { s.store_object_field("document", static_cast<const BaseObject *>(document_.get())); }
    if (var0 & 2) { s.store_field("title", title_); }
    if (var0 & 2) { s.store_field("performer", performer_); }
    s.store_class_end();
  }
}

object_ptr<KeyboardButton> KeyboardButton::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

keyboardButton::keyboardButton()
  : flags_()
  , style_()
  , text_()
{}

keyboardButton::keyboardButton(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
{}

const std::int32_t keyboardButton::ID;

object_ptr<KeyboardButton> keyboardButton::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButton> res = make_tl_object<keyboardButton>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
}

void keyboardButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
}

void keyboardButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButton");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_class_end();
  }
}

keyboardButtonUrl::keyboardButtonUrl()
  : flags_()
  , style_()
  , text_()
  , url_()
{}

keyboardButtonUrl::keyboardButtonUrl(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, string const &url_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
  , url_(url_)
{}

const std::int32_t keyboardButtonUrl::ID;

object_ptr<KeyboardButton> keyboardButtonUrl::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonUrl> res = make_tl_object<keyboardButtonUrl>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void keyboardButtonUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void keyboardButtonUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonUrl");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

keyboardButtonCallback::keyboardButtonCallback()
  : flags_()
  , requires_password_()
  , style_()
  , text_()
  , data_()
{}

keyboardButtonCallback::keyboardButtonCallback(int32 flags_, bool requires_password_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, bytes &&data_)
  : flags_(flags_)
  , requires_password_(requires_password_)
  , style_(std::move(style_))
  , text_(text_)
  , data_(std::move(data_))
{}

const std::int32_t keyboardButtonCallback::ID;

object_ptr<KeyboardButton> keyboardButtonCallback::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonCallback> res = make_tl_object<keyboardButtonCallback>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->requires_password_ = (var0 & 1) != 0;
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  res->data_ = TlFetchBytes<bytes>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonCallback::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (requires_password_ << 0)), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreString::store(data_, s);
}

void keyboardButtonCallback::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (requires_password_ << 0)), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreString::store(data_, s);
}

void keyboardButtonCallback::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonCallback");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (requires_password_ << 0)));
    if (var0 & 1) { s.store_field("requires_password", true); }
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_bytes_field("data", data_);
    s.store_class_end();
  }
}

keyboardButtonRequestPhone::keyboardButtonRequestPhone()
  : flags_()
  , style_()
  , text_()
{}

keyboardButtonRequestPhone::keyboardButtonRequestPhone(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
{}

const std::int32_t keyboardButtonRequestPhone::ID;

object_ptr<KeyboardButton> keyboardButtonRequestPhone::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonRequestPhone> res = make_tl_object<keyboardButtonRequestPhone>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonRequestPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
}

void keyboardButtonRequestPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
}

void keyboardButtonRequestPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonRequestPhone");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_class_end();
  }
}

keyboardButtonRequestGeoLocation::keyboardButtonRequestGeoLocation()
  : flags_()
  , style_()
  , text_()
{}

keyboardButtonRequestGeoLocation::keyboardButtonRequestGeoLocation(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
{}

const std::int32_t keyboardButtonRequestGeoLocation::ID;

object_ptr<KeyboardButton> keyboardButtonRequestGeoLocation::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonRequestGeoLocation> res = make_tl_object<keyboardButtonRequestGeoLocation>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonRequestGeoLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
}

void keyboardButtonRequestGeoLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
}

void keyboardButtonRequestGeoLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonRequestGeoLocation");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_class_end();
  }
}

keyboardButtonSwitchInline::keyboardButtonSwitchInline()
  : flags_()
  , same_peer_()
  , style_()
  , text_()
  , query_()
  , peer_types_()
{}

keyboardButtonSwitchInline::keyboardButtonSwitchInline(int32 flags_, bool same_peer_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, string const &query_, array<object_ptr<InlineQueryPeerType>> &&peer_types_)
  : flags_(flags_)
  , same_peer_(same_peer_)
  , style_(std::move(style_))
  , text_(text_)
  , query_(query_)
  , peer_types_(std::move(peer_types_))
{}

const std::int32_t keyboardButtonSwitchInline::ID;

object_ptr<KeyboardButton> keyboardButtonSwitchInline::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonSwitchInline> res = make_tl_object<keyboardButtonSwitchInline>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->same_peer_ = (var0 & 1) != 0;
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  res->query_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->peer_types_ = TlFetchBoxed<TlFetchVector<TlFetchObject<InlineQueryPeerType>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonSwitchInline::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (same_peer_ << 0)), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreString::store(query_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peer_types_, s); }
}

void keyboardButtonSwitchInline::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (same_peer_ << 0)), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreString::store(query_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peer_types_, s); }
}

void keyboardButtonSwitchInline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonSwitchInline");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (same_peer_ << 0)));
    if (var0 & 1) { s.store_field("same_peer", true); }
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_field("query", query_);
    if (var0 & 2) { { s.store_vector_begin("peer_types", peer_types_.size()); for (const auto &_value : peer_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

keyboardButtonGame::keyboardButtonGame()
  : flags_()
  , style_()
  , text_()
{}

keyboardButtonGame::keyboardButtonGame(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
{}

const std::int32_t keyboardButtonGame::ID;

object_ptr<KeyboardButton> keyboardButtonGame::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonGame> res = make_tl_object<keyboardButtonGame>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonGame::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
}

void keyboardButtonGame::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
}

void keyboardButtonGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonGame");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_class_end();
  }
}

keyboardButtonBuy::keyboardButtonBuy()
  : flags_()
  , style_()
  , text_()
{}

keyboardButtonBuy::keyboardButtonBuy(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
{}

const std::int32_t keyboardButtonBuy::ID;

object_ptr<KeyboardButton> keyboardButtonBuy::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonBuy> res = make_tl_object<keyboardButtonBuy>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonBuy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
}

void keyboardButtonBuy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
}

void keyboardButtonBuy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonBuy");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_class_end();
  }
}

keyboardButtonUrlAuth::keyboardButtonUrlAuth()
  : flags_()
  , style_()
  , text_()
  , fwd_text_()
  , url_()
  , button_id_()
{}

keyboardButtonUrlAuth::keyboardButtonUrlAuth(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, string const &fwd_text_, string const &url_, int32 button_id_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
  , fwd_text_(fwd_text_)
  , url_(url_)
  , button_id_(button_id_)
{}

const std::int32_t keyboardButtonUrlAuth::ID;

object_ptr<KeyboardButton> keyboardButtonUrlAuth::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonUrlAuth> res = make_tl_object<keyboardButtonUrlAuth>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->fwd_text_ = TlFetchString<string>::parse(p); }
  res->url_ = TlFetchString<string>::parse(p);
  res->button_id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonUrlAuth::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  if (var0 & 1) { TlStoreString::store(fwd_text_, s); }
  TlStoreString::store(url_, s);
  TlStoreBinary::store(button_id_, s);
}

void keyboardButtonUrlAuth::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  if (var0 & 1) { TlStoreString::store(fwd_text_, s); }
  TlStoreString::store(url_, s);
  TlStoreBinary::store(button_id_, s);
}

void keyboardButtonUrlAuth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonUrlAuth");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    if (var0 & 1) { s.store_field("fwd_text", fwd_text_); }
    s.store_field("url", url_);
    s.store_field("button_id", button_id_);
    s.store_class_end();
  }
}

inputKeyboardButtonUrlAuth::inputKeyboardButtonUrlAuth()
  : flags_()
  , request_write_access_()
  , style_()
  , text_()
  , fwd_text_()
  , url_()
  , bot_()
{}

inputKeyboardButtonUrlAuth::inputKeyboardButtonUrlAuth(int32 flags_, bool request_write_access_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, string const &fwd_text_, string const &url_, object_ptr<InputUser> &&bot_)
  : flags_(flags_)
  , request_write_access_(request_write_access_)
  , style_(std::move(style_))
  , text_(text_)
  , fwd_text_(fwd_text_)
  , url_(url_)
  , bot_(std::move(bot_))
{}

const std::int32_t inputKeyboardButtonUrlAuth::ID;

object_ptr<KeyboardButton> inputKeyboardButtonUrlAuth::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputKeyboardButtonUrlAuth> res = make_tl_object<inputKeyboardButtonUrlAuth>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->request_write_access_ = (var0 & 1) != 0;
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->fwd_text_ = TlFetchString<string>::parse(p); }
  res->url_ = TlFetchString<string>::parse(p);
  res->bot_ = TlFetchObject<InputUser>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputKeyboardButtonUrlAuth::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (request_write_access_ << 0)), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  if (var0 & 2) { TlStoreString::store(fwd_text_, s); }
  TlStoreString::store(url_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void inputKeyboardButtonUrlAuth::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (request_write_access_ << 0)), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  if (var0 & 2) { TlStoreString::store(fwd_text_, s); }
  TlStoreString::store(url_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
}

void inputKeyboardButtonUrlAuth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputKeyboardButtonUrlAuth");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (request_write_access_ << 0)));
    if (var0 & 1) { s.store_field("request_write_access", true); }
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    if (var0 & 2) { s.store_field("fwd_text", fwd_text_); }
    s.store_field("url", url_);
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_class_end();
  }
}

keyboardButtonRequestPoll::keyboardButtonRequestPoll()
  : flags_()
  , style_()
  , quiz_()
  , text_()
{}

keyboardButtonRequestPoll::keyboardButtonRequestPoll(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, bool quiz_, string const &text_)
  : flags_(flags_)
  , style_(std::move(style_))
  , quiz_(quiz_)
  , text_(text_)
{}

const std::int32_t keyboardButtonRequestPoll::ID;

object_ptr<KeyboardButton> keyboardButtonRequestPoll::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonRequestPoll> res = make_tl_object<keyboardButtonRequestPoll>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  if (var0 & 1) { res->quiz_ = TlFetchBool::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonRequestPoll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  if (var0 & 1) { TlStoreBool::store(quiz_, s); }
  TlStoreString::store(text_, s);
}

void keyboardButtonRequestPoll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  if (var0 & 1) { TlStoreBool::store(quiz_, s); }
  TlStoreString::store(text_, s);
}

void keyboardButtonRequestPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonRequestPoll");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    if (var0 & 1) { s.store_field("quiz", quiz_); }
    s.store_field("text", text_);
    s.store_class_end();
  }
}

inputKeyboardButtonUserProfile::inputKeyboardButtonUserProfile()
  : flags_()
  , style_()
  , text_()
  , user_id_()
{}

inputKeyboardButtonUserProfile::inputKeyboardButtonUserProfile(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, object_ptr<InputUser> &&user_id_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
  , user_id_(std::move(user_id_))
{}

const std::int32_t inputKeyboardButtonUserProfile::ID;

object_ptr<KeyboardButton> inputKeyboardButtonUserProfile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputKeyboardButtonUserProfile> res = make_tl_object<inputKeyboardButtonUserProfile>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  res->user_id_ = TlFetchObject<InputUser>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputKeyboardButtonUserProfile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void inputKeyboardButtonUserProfile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void inputKeyboardButtonUserProfile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputKeyboardButtonUserProfile");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

keyboardButtonUserProfile::keyboardButtonUserProfile()
  : flags_()
  , style_()
  , text_()
  , user_id_()
{}

keyboardButtonUserProfile::keyboardButtonUserProfile(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, int64 user_id_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
  , user_id_(user_id_)
{}

const std::int32_t keyboardButtonUserProfile::ID;

object_ptr<KeyboardButton> keyboardButtonUserProfile::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonUserProfile> res = make_tl_object<keyboardButtonUserProfile>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonUserProfile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreBinary::store(user_id_, s);
}

void keyboardButtonUserProfile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreBinary::store(user_id_, s);
}

void keyboardButtonUserProfile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonUserProfile");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

keyboardButtonWebView::keyboardButtonWebView()
  : flags_()
  , style_()
  , text_()
  , url_()
{}

keyboardButtonWebView::keyboardButtonWebView(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, string const &url_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
  , url_(url_)
{}

const std::int32_t keyboardButtonWebView::ID;

object_ptr<KeyboardButton> keyboardButtonWebView::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonWebView> res = make_tl_object<keyboardButtonWebView>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void keyboardButtonWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void keyboardButtonWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonWebView");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

keyboardButtonSimpleWebView::keyboardButtonSimpleWebView()
  : flags_()
  , style_()
  , text_()
  , url_()
{}

keyboardButtonSimpleWebView::keyboardButtonSimpleWebView(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, string const &url_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
  , url_(url_)
{}

const std::int32_t keyboardButtonSimpleWebView::ID;

object_ptr<KeyboardButton> keyboardButtonSimpleWebView::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonSimpleWebView> res = make_tl_object<keyboardButtonSimpleWebView>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonSimpleWebView::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void keyboardButtonSimpleWebView::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreString::store(url_, s);
}

void keyboardButtonSimpleWebView::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonSimpleWebView");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

keyboardButtonRequestPeer::keyboardButtonRequestPeer()
  : flags_()
  , style_()
  , text_()
  , button_id_()
  , peer_type_()
  , max_quantity_()
{}

keyboardButtonRequestPeer::keyboardButtonRequestPeer(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, int32 button_id_, object_ptr<RequestPeerType> &&peer_type_, int32 max_quantity_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
  , button_id_(button_id_)
  , peer_type_(std::move(peer_type_))
  , max_quantity_(max_quantity_)
{}

const std::int32_t keyboardButtonRequestPeer::ID;

object_ptr<KeyboardButton> keyboardButtonRequestPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonRequestPeer> res = make_tl_object<keyboardButtonRequestPeer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  res->button_id_ = TlFetchInt::parse(p);
  res->peer_type_ = TlFetchObject<RequestPeerType>::parse(p);
  res->max_quantity_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonRequestPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreBinary::store(button_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_type_, s);
  TlStoreBinary::store(max_quantity_, s);
}

void keyboardButtonRequestPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreBinary::store(button_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_type_, s);
  TlStoreBinary::store(max_quantity_, s);
}

void keyboardButtonRequestPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonRequestPeer");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_field("button_id", button_id_);
    s.store_object_field("peer_type", static_cast<const BaseObject *>(peer_type_.get()));
    s.store_field("max_quantity", max_quantity_);
    s.store_class_end();
  }
}

inputKeyboardButtonRequestPeer::inputKeyboardButtonRequestPeer()
  : flags_()
  , name_requested_()
  , username_requested_()
  , photo_requested_()
  , style_()
  , text_()
  , button_id_()
  , peer_type_()
  , max_quantity_()
{}

inputKeyboardButtonRequestPeer::inputKeyboardButtonRequestPeer(int32 flags_, bool name_requested_, bool username_requested_, bool photo_requested_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, int32 button_id_, object_ptr<RequestPeerType> &&peer_type_, int32 max_quantity_)
  : flags_(flags_)
  , name_requested_(name_requested_)
  , username_requested_(username_requested_)
  , photo_requested_(photo_requested_)
  , style_(std::move(style_))
  , text_(text_)
  , button_id_(button_id_)
  , peer_type_(std::move(peer_type_))
  , max_quantity_(max_quantity_)
{}

const std::int32_t inputKeyboardButtonRequestPeer::ID;

object_ptr<KeyboardButton> inputKeyboardButtonRequestPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<inputKeyboardButtonRequestPeer> res = make_tl_object<inputKeyboardButtonRequestPeer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->name_requested_ = (var0 & 1) != 0;
  res->username_requested_ = (var0 & 2) != 0;
  res->photo_requested_ = (var0 & 4) != 0;
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  res->button_id_ = TlFetchInt::parse(p);
  res->peer_type_ = TlFetchObject<RequestPeerType>::parse(p);
  res->max_quantity_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void inputKeyboardButtonRequestPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (name_requested_ << 0) | (username_requested_ << 1) | (photo_requested_ << 2)), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreBinary::store(button_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_type_, s);
  TlStoreBinary::store(max_quantity_, s);
}

void inputKeyboardButtonRequestPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (name_requested_ << 0) | (username_requested_ << 1) | (photo_requested_ << 2)), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreBinary::store(button_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_type_, s);
  TlStoreBinary::store(max_quantity_, s);
}

void inputKeyboardButtonRequestPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputKeyboardButtonRequestPeer");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (name_requested_ << 0) | (username_requested_ << 1) | (photo_requested_ << 2)));
    if (var0 & 1) { s.store_field("name_requested", true); }
    if (var0 & 2) { s.store_field("username_requested", true); }
    if (var0 & 4) { s.store_field("photo_requested", true); }
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_field("button_id", button_id_);
    s.store_object_field("peer_type", static_cast<const BaseObject *>(peer_type_.get()));
    s.store_field("max_quantity", max_quantity_);
    s.store_class_end();
  }
}

keyboardButtonCopy::keyboardButtonCopy()
  : flags_()
  , style_()
  , text_()
  , copy_text_()
{}

keyboardButtonCopy::keyboardButtonCopy(int32 flags_, object_ptr<keyboardButtonStyle> &&style_, string const &text_, string const &copy_text_)
  : flags_(flags_)
  , style_(std::move(style_))
  , text_(text_)
  , copy_text_(copy_text_)
{}

const std::int32_t keyboardButtonCopy::ID;

object_ptr<KeyboardButton> keyboardButtonCopy::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonCopy> res = make_tl_object<keyboardButtonCopy>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1024) { res->style_ = TlFetchBoxed<TlFetchObject<keyboardButtonStyle>, 1339896880>::parse(p); }
  res->text_ = TlFetchString<string>::parse(p);
  res->copy_text_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void keyboardButtonCopy::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreString::store(copy_text_, s);
}

void keyboardButtonCopy::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1024) { TlStoreBoxed<TlStoreObject, 1339896880>::store(style_, s); }
  TlStoreString::store(text_, s);
  TlStoreString::store(copy_text_, s);
}

void keyboardButtonCopy::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonCopy");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1024) { s.store_object_field("style", static_cast<const BaseObject *>(style_.get())); }
    s.store_field("text", text_);
    s.store_field("copy_text", copy_text_);
    s.store_class_end();
  }
}

keyboardButtonStyle::keyboardButtonStyle()
  : flags_()
  , bg_primary_()
  , bg_danger_()
  , bg_success_()
  , icon_()
{}

keyboardButtonStyle::keyboardButtonStyle(int32 flags_, bool bg_primary_, bool bg_danger_, bool bg_success_, int64 icon_)
  : flags_(flags_)
  , bg_primary_(bg_primary_)
  , bg_danger_(bg_danger_)
  , bg_success_(bg_success_)
  , icon_(icon_)
{}

const std::int32_t keyboardButtonStyle::ID;

object_ptr<keyboardButtonStyle> keyboardButtonStyle::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<keyboardButtonStyle> res = make_tl_object<keyboardButtonStyle>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->bg_primary_ = (var0 & 1) != 0;
  res->bg_danger_ = (var0 & 2) != 0;
  res->bg_success_ = (var0 & 4) != 0;
  if (var0 & 8) { res->icon_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void keyboardButtonStyle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bg_primary_ << 0) | (bg_danger_ << 1) | (bg_success_ << 2)), s);
  if (var0 & 8) { TlStoreBinary::store(icon_, s); }
}

void keyboardButtonStyle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (bg_primary_ << 0) | (bg_danger_ << 1) | (bg_success_ << 2)), s);
  if (var0 & 8) { TlStoreBinary::store(icon_, s); }
}

void keyboardButtonStyle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "keyboardButtonStyle");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (bg_primary_ << 0) | (bg_danger_ << 1) | (bg_success_ << 2)));
    if (var0 & 1) { s.store_field("bg_primary", true); }
    if (var0 & 2) { s.store_field("bg_danger", true); }
    if (var0 & 4) { s.store_field("bg_success", true); }
    if (var0 & 8) { s.store_field("icon", icon_); }
    s.store_class_end();
  }
}

object_ptr<LangPackString> LangPackString::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case langPackString::ID:
      return langPackString::fetch(p);
    case langPackStringPluralized::ID:
      return langPackStringPluralized::fetch(p);
    case langPackStringDeleted::ID:
      return langPackStringDeleted::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

langPackString::langPackString(string const &key_, string const &value_)
  : key_(key_)
  , value_(value_)
{}

const std::int32_t langPackString::ID;

object_ptr<LangPackString> langPackString::fetch(TlBufferParser &p) {
  return make_tl_object<langPackString>(p);
}

langPackString::langPackString(TlBufferParser &p)
  : key_(TlFetchString<string>::parse(p))
  , value_(TlFetchString<string>::parse(p))
{}

void langPackString::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langPackString");
    s.store_field("key", key_);
    s.store_field("value", value_);
    s.store_class_end();
  }
}

langPackStringPluralized::langPackStringPluralized()
  : flags_()
  , key_()
  , zero_value_()
  , one_value_()
  , two_value_()
  , few_value_()
  , many_value_()
  , other_value_()
{}

langPackStringPluralized::langPackStringPluralized(int32 flags_, string const &key_, string const &zero_value_, string const &one_value_, string const &two_value_, string const &few_value_, string const &many_value_, string const &other_value_)
  : flags_(flags_)
  , key_(key_)
  , zero_value_(zero_value_)
  , one_value_(one_value_)
  , two_value_(two_value_)
  , few_value_(few_value_)
  , many_value_(many_value_)
  , other_value_(other_value_)
{}

const std::int32_t langPackStringPluralized::ID;

object_ptr<LangPackString> langPackStringPluralized::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<langPackStringPluralized> res = make_tl_object<langPackStringPluralized>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->key_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->zero_value_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->one_value_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->two_value_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->few_value_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->many_value_ = TlFetchString<string>::parse(p); }
  res->other_value_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void langPackStringPluralized::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langPackStringPluralized");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("key", key_);
    if (var0 & 1) { s.store_field("zero_value", zero_value_); }
    if (var0 & 2) { s.store_field("one_value", one_value_); }
    if (var0 & 4) { s.store_field("two_value", two_value_); }
    if (var0 & 8) { s.store_field("few_value", few_value_); }
    if (var0 & 16) { s.store_field("many_value", many_value_); }
    s.store_field("other_value", other_value_);
    s.store_class_end();
  }
}

langPackStringDeleted::langPackStringDeleted(string const &key_)
  : key_(key_)
{}

const std::int32_t langPackStringDeleted::ID;

object_ptr<LangPackString> langPackStringDeleted::fetch(TlBufferParser &p) {
  return make_tl_object<langPackStringDeleted>(p);
}

langPackStringDeleted::langPackStringDeleted(TlBufferParser &p)
  : key_(TlFetchString<string>::parse(p))
{}

void langPackStringDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langPackStringDeleted");
    s.store_field("key", key_);
    s.store_class_end();
  }
}

mediaAreaCoordinates::mediaAreaCoordinates()
  : flags_()
  , x_()
  , y_()
  , w_()
  , h_()
  , rotation_()
  , radius_()
{}

mediaAreaCoordinates::mediaAreaCoordinates(int32 flags_, double x_, double y_, double w_, double h_, double rotation_, double radius_)
  : flags_(flags_)
  , x_(x_)
  , y_(y_)
  , w_(w_)
  , h_(h_)
  , rotation_(rotation_)
  , radius_(radius_)
{}

const std::int32_t mediaAreaCoordinates::ID;

object_ptr<mediaAreaCoordinates> mediaAreaCoordinates::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<mediaAreaCoordinates> res = make_tl_object<mediaAreaCoordinates>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->x_ = TlFetchDouble::parse(p);
  res->y_ = TlFetchDouble::parse(p);
  res->w_ = TlFetchDouble::parse(p);
  res->h_ = TlFetchDouble::parse(p);
  res->rotation_ = TlFetchDouble::parse(p);
  if (var0 & 1) { res->radius_ = TlFetchDouble::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void mediaAreaCoordinates::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(x_, s);
  TlStoreBinary::store(y_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(rotation_, s);
  if (var0 & 1) { TlStoreBinary::store(radius_, s); }
}

void mediaAreaCoordinates::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(x_, s);
  TlStoreBinary::store(y_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(rotation_, s);
  if (var0 & 1) { TlStoreBinary::store(radius_, s); }
}

void mediaAreaCoordinates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaCoordinates");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("x", x_);
    s.store_field("y", y_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_field("rotation", rotation_);
    if (var0 & 1) { s.store_field("radius", radius_); }
    s.store_class_end();
  }
}

object_ptr<NotifyPeer> NotifyPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t notifyPeer::ID;

object_ptr<NotifyPeer> notifyPeer::fetch(TlBufferParser &p) {
  return make_tl_object<notifyPeer>(p);
}

notifyPeer::notifyPeer(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
{}

void notifyPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notifyPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

const std::int32_t notifyUsers::ID;

object_ptr<NotifyPeer> notifyUsers::fetch(TlBufferParser &p) {
  return make_tl_object<notifyUsers>();
}

void notifyUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notifyUsers");
    s.store_class_end();
  }
}

const std::int32_t notifyChats::ID;

object_ptr<NotifyPeer> notifyChats::fetch(TlBufferParser &p) {
  return make_tl_object<notifyChats>();
}

void notifyChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notifyChats");
    s.store_class_end();
  }
}

const std::int32_t notifyBroadcasts::ID;

object_ptr<NotifyPeer> notifyBroadcasts::fetch(TlBufferParser &p) {
  return make_tl_object<notifyBroadcasts>();
}

void notifyBroadcasts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notifyBroadcasts");
    s.store_class_end();
  }
}

const std::int32_t notifyForumTopic::ID;

object_ptr<NotifyPeer> notifyForumTopic::fetch(TlBufferParser &p) {
  return make_tl_object<notifyForumTopic>(p);
}

notifyForumTopic::notifyForumTopic(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , top_msg_id_(TlFetchInt::parse(p))
{}

void notifyForumTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "notifyForumTopic");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("top_msg_id", top_msg_id_);
    s.store_class_end();
  }
}

peerNotifySettings::peerNotifySettings()
  : flags_()
  , show_previews_()
  , silent_()
  , mute_until_()
  , ios_sound_()
  , android_sound_()
  , other_sound_()
  , stories_muted_()
  , stories_hide_sender_()
  , stories_ios_sound_()
  , stories_android_sound_()
  , stories_other_sound_()
{}

const std::int32_t peerNotifySettings::ID;

object_ptr<peerNotifySettings> peerNotifySettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<peerNotifySettings> res = make_tl_object<peerNotifySettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->show_previews_ = TlFetchBool::parse(p); }
  if (var0 & 2) { res->silent_ = TlFetchBool::parse(p); }
  if (var0 & 4) { res->mute_until_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->ios_sound_ = TlFetchObject<NotificationSound>::parse(p); }
  if (var0 & 16) { res->android_sound_ = TlFetchObject<NotificationSound>::parse(p); }
  if (var0 & 32) { res->other_sound_ = TlFetchObject<NotificationSound>::parse(p); }
  if (var0 & 64) { res->stories_muted_ = TlFetchBool::parse(p); }
  if (var0 & 128) { res->stories_hide_sender_ = TlFetchBool::parse(p); }
  if (var0 & 256) { res->stories_ios_sound_ = TlFetchObject<NotificationSound>::parse(p); }
  if (var0 & 512) { res->stories_android_sound_ = TlFetchObject<NotificationSound>::parse(p); }
  if (var0 & 1024) { res->stories_other_sound_ = TlFetchObject<NotificationSound>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void peerNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerNotifySettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("show_previews", show_previews_); }
    if (var0 & 2) { s.store_field("silent", silent_); }
    if (var0 & 4) { s.store_field("mute_until", mute_until_); }
    if (var0 & 8) { s.store_object_field("ios_sound", static_cast<const BaseObject *>(ios_sound_.get())); }
    if (var0 & 16) { s.store_object_field("android_sound", static_cast<const BaseObject *>(android_sound_.get())); }
    if (var0 & 32) { s.store_object_field("other_sound", static_cast<const BaseObject *>(other_sound_.get())); }
    if (var0 & 64) { s.store_field("stories_muted", stories_muted_); }
    if (var0 & 128) { s.store_field("stories_hide_sender", stories_hide_sender_); }
    if (var0 & 256) { s.store_object_field("stories_ios_sound", static_cast<const BaseObject *>(stories_ios_sound_.get())); }
    if (var0 & 512) { s.store_object_field("stories_android_sound", static_cast<const BaseObject *>(stories_android_sound_.get())); }
    if (var0 & 1024) { s.store_object_field("stories_other_sound", static_cast<const BaseObject *>(stories_other_sound_.get())); }
    s.store_class_end();
  }
}

peerSettings::peerSettings()
  : flags_()
  , report_spam_()
  , add_contact_()
  , block_contact_()
  , share_contact_()
  , need_contacts_exception_()
  , report_geo_()
  , autoarchived_()
  , invite_members_()
  , request_chat_broadcast_()
  , business_bot_paused_()
  , business_bot_can_reply_()
  , geo_distance_()
  , request_chat_title_()
  , request_chat_date_()
  , business_bot_id_()
  , business_bot_manage_url_()
  , charge_paid_message_stars_()
  , registration_month_()
  , phone_country_()
  , name_change_date_()
  , photo_change_date_()
{}

const std::int32_t peerSettings::ID;

object_ptr<peerSettings> peerSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<peerSettings> res = make_tl_object<peerSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->report_spam_ = (var0 & 1) != 0;
  res->add_contact_ = (var0 & 2) != 0;
  res->block_contact_ = (var0 & 4) != 0;
  res->share_contact_ = (var0 & 8) != 0;
  res->need_contacts_exception_ = (var0 & 16) != 0;
  res->report_geo_ = (var0 & 32) != 0;
  res->autoarchived_ = (var0 & 128) != 0;
  res->invite_members_ = (var0 & 256) != 0;
  res->request_chat_broadcast_ = (var0 & 1024) != 0;
  res->business_bot_paused_ = (var0 & 2048) != 0;
  res->business_bot_can_reply_ = (var0 & 4096) != 0;
  if (var0 & 64) { res->geo_distance_ = TlFetchInt::parse(p); }
  if (var0 & 512) { res->request_chat_title_ = TlFetchString<string>::parse(p); }
  if (var0 & 512) { res->request_chat_date_ = TlFetchInt::parse(p); }
  if (var0 & 8192) { res->business_bot_id_ = TlFetchLong::parse(p); }
  if (var0 & 8192) { res->business_bot_manage_url_ = TlFetchString<string>::parse(p); }
  if (var0 & 16384) { res->charge_paid_message_stars_ = TlFetchLong::parse(p); }
  if (var0 & 32768) { res->registration_month_ = TlFetchString<string>::parse(p); }
  if (var0 & 65536) { res->phone_country_ = TlFetchString<string>::parse(p); }
  if (var0 & 131072) { res->name_change_date_ = TlFetchInt::parse(p); }
  if (var0 & 262144) { res->photo_change_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void peerSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "peerSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (report_spam_ << 0) | (add_contact_ << 1) | (block_contact_ << 2) | (share_contact_ << 3) | (need_contacts_exception_ << 4) | (report_geo_ << 5) | (autoarchived_ << 7) | (invite_members_ << 8) | (request_chat_broadcast_ << 10) | (business_bot_paused_ << 11) | (business_bot_can_reply_ << 12)));
    if (var0 & 1) { s.store_field("report_spam", true); }
    if (var0 & 2) { s.store_field("add_contact", true); }
    if (var0 & 4) { s.store_field("block_contact", true); }
    if (var0 & 8) { s.store_field("share_contact", true); }
    if (var0 & 16) { s.store_field("need_contacts_exception", true); }
    if (var0 & 32) { s.store_field("report_geo", true); }
    if (var0 & 128) { s.store_field("autoarchived", true); }
    if (var0 & 256) { s.store_field("invite_members", true); }
    if (var0 & 1024) { s.store_field("request_chat_broadcast", true); }
    if (var0 & 2048) { s.store_field("business_bot_paused", true); }
    if (var0 & 4096) { s.store_field("business_bot_can_reply", true); }
    if (var0 & 64) { s.store_field("geo_distance", geo_distance_); }
    if (var0 & 512) { s.store_field("request_chat_title", request_chat_title_); }
    if (var0 & 512) { s.store_field("request_chat_date", request_chat_date_); }
    if (var0 & 8192) { s.store_field("business_bot_id", business_bot_id_); }
    if (var0 & 8192) { s.store_field("business_bot_manage_url", business_bot_manage_url_); }
    if (var0 & 16384) { s.store_field("charge_paid_message_stars", charge_paid_message_stars_); }
    if (var0 & 32768) { s.store_field("registration_month", registration_month_); }
    if (var0 & 65536) { s.store_field("phone_country", phone_country_); }
    if (var0 & 131072) { s.store_field("name_change_date", name_change_date_); }
    if (var0 & 262144) { s.store_field("photo_change_date", photo_change_date_); }
    s.store_class_end();
  }
}

object_ptr<PhoneCall> PhoneCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t phoneCallEmpty::ID;

object_ptr<PhoneCall> phoneCallEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<phoneCallEmpty>(p);
}

phoneCallEmpty::phoneCallEmpty(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void phoneCallEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallEmpty");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

phoneCallWaiting::phoneCallWaiting()
  : flags_()
  , video_()
  , id_()
  , access_hash_()
  , date_()
  , admin_id_()
  , participant_id_()
  , protocol_()
  , receive_date_()
{}

const std::int32_t phoneCallWaiting::ID;

object_ptr<PhoneCall> phoneCallWaiting::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneCallWaiting> res = make_tl_object<phoneCallWaiting>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->video_ = (var0 & 64) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->admin_id_ = TlFetchLong::parse(p);
  res->participant_id_ = TlFetchLong::parse(p);
  res->protocol_ = TlFetchBoxed<TlFetchObject<phoneCallProtocol>, -58224696>::parse(p);
  if (var0 & 1) { res->receive_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneCallWaiting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallWaiting");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (video_ << 6)));
    if (var0 & 64) { s.store_field("video", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    if (var0 & 1) { s.store_field("receive_date", receive_date_); }
    s.store_class_end();
  }
}

phoneCallRequested::phoneCallRequested()
  : flags_()
  , video_()
  , id_()
  , access_hash_()
  , date_()
  , admin_id_()
  , participant_id_()
  , g_a_hash_()
  , protocol_()
{}

const std::int32_t phoneCallRequested::ID;

object_ptr<PhoneCall> phoneCallRequested::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneCallRequested> res = make_tl_object<phoneCallRequested>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->video_ = (var0 & 64) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->admin_id_ = TlFetchLong::parse(p);
  res->participant_id_ = TlFetchLong::parse(p);
  res->g_a_hash_ = TlFetchBytes<bytes>::parse(p);
  res->protocol_ = TlFetchBoxed<TlFetchObject<phoneCallProtocol>, -58224696>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneCallRequested::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallRequested");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (video_ << 6)));
    if (var0 & 64) { s.store_field("video", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_bytes_field("g_a_hash", g_a_hash_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

phoneCallAccepted::phoneCallAccepted()
  : flags_()
  , video_()
  , id_()
  , access_hash_()
  , date_()
  , admin_id_()
  , participant_id_()
  , g_b_()
  , protocol_()
{}

const std::int32_t phoneCallAccepted::ID;

object_ptr<PhoneCall> phoneCallAccepted::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneCallAccepted> res = make_tl_object<phoneCallAccepted>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->video_ = (var0 & 64) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->admin_id_ = TlFetchLong::parse(p);
  res->participant_id_ = TlFetchLong::parse(p);
  res->g_b_ = TlFetchBytes<bytes>::parse(p);
  res->protocol_ = TlFetchBoxed<TlFetchObject<phoneCallProtocol>, -58224696>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneCallAccepted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallAccepted");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (video_ << 6)));
    if (var0 & 64) { s.store_field("video", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_bytes_field("g_b", g_b_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

phoneCall::phoneCall()
  : flags_()
  , p2p_allowed_()
  , video_()
  , conference_supported_()
  , id_()
  , access_hash_()
  , date_()
  , admin_id_()
  , participant_id_()
  , g_a_or_b_()
  , key_fingerprint_()
  , protocol_()
  , connections_()
  , start_date_()
  , custom_parameters_()
{}

const std::int32_t phoneCall::ID;

object_ptr<PhoneCall> phoneCall::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneCall> res = make_tl_object<phoneCall>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->p2p_allowed_ = (var0 & 32) != 0;
  res->video_ = (var0 & 64) != 0;
  res->conference_supported_ = (var0 & 256) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->admin_id_ = TlFetchLong::parse(p);
  res->participant_id_ = TlFetchLong::parse(p);
  res->g_a_or_b_ = TlFetchBytes<bytes>::parse(p);
  res->key_fingerprint_ = TlFetchLong::parse(p);
  res->protocol_ = TlFetchBoxed<TlFetchObject<phoneCallProtocol>, -58224696>::parse(p);
  res->connections_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PhoneConnection>>, 481674261>::parse(p);
  res->start_date_ = TlFetchInt::parse(p);
  if (var0 & 128) { res->custom_parameters_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCall");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (p2p_allowed_ << 5) | (video_ << 6) | (conference_supported_ << 8)));
    if (var0 & 32) { s.store_field("p2p_allowed", true); }
    if (var0 & 64) { s.store_field("video", true); }
    if (var0 & 256) { s.store_field("conference_supported", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("date", date_);
    s.store_field("admin_id", admin_id_);
    s.store_field("participant_id", participant_id_);
    s.store_bytes_field("g_a_or_b", g_a_or_b_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    { s.store_vector_begin("connections", connections_.size()); for (const auto &_value : connections_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("start_date", start_date_);
    if (var0 & 128) { s.store_object_field("custom_parameters", static_cast<const BaseObject *>(custom_parameters_.get())); }
    s.store_class_end();
  }
}

phoneCallDiscarded::phoneCallDiscarded()
  : flags_()
  , need_rating_()
  , need_debug_()
  , video_()
  , id_()
  , reason_()
  , duration_()
{}

const std::int32_t phoneCallDiscarded::ID;

object_ptr<PhoneCall> phoneCallDiscarded::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneCallDiscarded> res = make_tl_object<phoneCallDiscarded>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->need_rating_ = (var0 & 4) != 0;
  res->need_debug_ = (var0 & 8) != 0;
  res->video_ = (var0 & 64) != 0;
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->reason_ = TlFetchObject<PhoneCallDiscardReason>::parse(p); }
  if (var0 & 2) { res->duration_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneCallDiscarded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneCallDiscarded");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (need_rating_ << 2) | (need_debug_ << 3) | (video_ << 6)));
    if (var0 & 4) { s.store_field("need_rating", true); }
    if (var0 & 8) { s.store_field("need_debug", true); }
    if (var0 & 64) { s.store_field("video", true); }
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get())); }
    if (var0 & 2) { s.store_field("duration", duration_); }
    s.store_class_end();
  }
}

poll::poll()
  : id_()
  , flags_()
  , closed_()
  , public_voters_()
  , multiple_choice_()
  , quiz_()
  , open_answers_()
  , revoting_disabled_()
  , shuffle_answers_()
  , hide_results_until_close_()
  , creator_()
  , question_()
  , answers_()
  , close_period_()
  , close_date_()
  , hash_()
{}

poll::poll(int64 id_, int32 flags_, bool closed_, bool public_voters_, bool multiple_choice_, bool quiz_, bool open_answers_, bool revoting_disabled_, bool shuffle_answers_, bool hide_results_until_close_, bool creator_, object_ptr<textWithEntities> &&question_, array<object_ptr<PollAnswer>> &&answers_, int32 close_period_, int32 close_date_, int64 hash_)
  : id_(id_)
  , flags_(flags_)
  , closed_(closed_)
  , public_voters_(public_voters_)
  , multiple_choice_(multiple_choice_)
  , quiz_(quiz_)
  , open_answers_(open_answers_)
  , revoting_disabled_(revoting_disabled_)
  , shuffle_answers_(shuffle_answers_)
  , hide_results_until_close_(hide_results_until_close_)
  , creator_(creator_)
  , question_(std::move(question_))
  , answers_(std::move(answers_))
  , close_period_(close_period_)
  , close_date_(close_date_)
  , hash_(hash_)
{}

const std::int32_t poll::ID;

object_ptr<poll> poll::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<poll> res = make_tl_object<poll>();
  int32 var0;
  res->id_ = TlFetchLong::parse(p);
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->closed_ = (var0 & 1) != 0;
  res->public_voters_ = (var0 & 2) != 0;
  res->multiple_choice_ = (var0 & 4) != 0;
  res->quiz_ = (var0 & 8) != 0;
  res->open_answers_ = (var0 & 64) != 0;
  res->revoting_disabled_ = (var0 & 128) != 0;
  res->shuffle_answers_ = (var0 & 256) != 0;
  res->hide_results_until_close_ = (var0 & 512) != 0;
  res->creator_ = (var0 & 1024) != 0;
  res->question_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  res->answers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PollAnswer>>, 481674261>::parse(p);
  if (var0 & 16) { res->close_period_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->close_date_ = TlFetchInt::parse(p); }
  res->hash_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void poll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store((var0 = flags_ | (closed_ << 0) | (public_voters_ << 1) | (multiple_choice_ << 2) | (quiz_ << 3) | (open_answers_ << 6) | (revoting_disabled_ << 7) | (shuffle_answers_ << 8) | (hide_results_until_close_ << 9) | (creator_ << 10)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(question_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(answers_, s);
  if (var0 & 16) { TlStoreBinary::store(close_period_, s); }
  if (var0 & 32) { TlStoreBinary::store(close_date_, s); }
  TlStoreBinary::store(hash_, s);
}

void poll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store((var0 = flags_ | (closed_ << 0) | (public_voters_ << 1) | (multiple_choice_ << 2) | (quiz_ << 3) | (open_answers_ << 6) | (revoting_disabled_ << 7) | (shuffle_answers_ << 8) | (hide_results_until_close_ << 9) | (creator_ << 10)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(question_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(answers_, s);
  if (var0 & 16) { TlStoreBinary::store(close_period_, s); }
  if (var0 & 32) { TlStoreBinary::store(close_date_, s); }
  TlStoreBinary::store(hash_, s);
}

void poll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "poll");
  int32 var0;
    s.store_field("id", id_);
    s.store_field("flags", (var0 = flags_ | (closed_ << 0) | (public_voters_ << 1) | (multiple_choice_ << 2) | (quiz_ << 3) | (open_answers_ << 6) | (revoting_disabled_ << 7) | (shuffle_answers_ << 8) | (hide_results_until_close_ << 9) | (creator_ << 10)));
    if (var0 & 1) { s.store_field("closed", true); }
    if (var0 & 2) { s.store_field("public_voters", true); }
    if (var0 & 4) { s.store_field("multiple_choice", true); }
    if (var0 & 8) { s.store_field("quiz", true); }
    if (var0 & 64) { s.store_field("open_answers", true); }
    if (var0 & 128) { s.store_field("revoting_disabled", true); }
    if (var0 & 256) { s.store_field("shuffle_answers", true); }
    if (var0 & 512) { s.store_field("hide_results_until_close", true); }
    if (var0 & 1024) { s.store_field("creator", true); }
    s.store_object_field("question", static_cast<const BaseObject *>(question_.get()));
    { s.store_vector_begin("answers", answers_.size()); for (const auto &_value : answers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 16) { s.store_field("close_period", close_period_); }
    if (var0 & 32) { s.store_field("close_date", close_date_); }
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonSpam::ID;

void inputReportReasonSpam::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonSpam::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonSpam");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonViolence::ID;

void inputReportReasonViolence::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonViolence::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonViolence::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonViolence");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonPornography::ID;

void inputReportReasonPornography::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonPornography::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonPornography::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonPornography");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonChildAbuse::ID;

void inputReportReasonChildAbuse::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonChildAbuse::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonChildAbuse::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonChildAbuse");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonOther::ID;

void inputReportReasonOther::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonOther::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonOther::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonOther");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonCopyright::ID;

void inputReportReasonCopyright::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonCopyright::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonCopyright::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonCopyright");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonGeoIrrelevant::ID;

void inputReportReasonGeoIrrelevant::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonGeoIrrelevant::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonGeoIrrelevant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonGeoIrrelevant");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonFake::ID;

void inputReportReasonFake::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonFake::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonFake::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonFake");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonIllegalDrugs::ID;

void inputReportReasonIllegalDrugs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonIllegalDrugs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonIllegalDrugs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonIllegalDrugs");
    s.store_class_end();
  }
}

const std::int32_t inputReportReasonPersonalDetails::ID;

void inputReportReasonPersonalDetails::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputReportReasonPersonalDetails::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputReportReasonPersonalDetails::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputReportReasonPersonalDetails");
    s.store_class_end();
  }
}

object_ptr<SecurePasswordKdfAlgo> SecurePasswordKdfAlgo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case securePasswordKdfAlgoUnknown::ID:
      return securePasswordKdfAlgoUnknown::fetch(p);
    case securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::ID:
      return securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::fetch(p);
    case securePasswordKdfAlgoSHA512::ID:
      return securePasswordKdfAlgoSHA512::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t securePasswordKdfAlgoUnknown::ID;

object_ptr<SecurePasswordKdfAlgo> securePasswordKdfAlgoUnknown::fetch(TlBufferParser &p) {
  return make_tl_object<securePasswordKdfAlgoUnknown>();
}

void securePasswordKdfAlgoUnknown::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void securePasswordKdfAlgoUnknown::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void securePasswordKdfAlgoUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "securePasswordKdfAlgoUnknown");
    s.store_class_end();
  }
}

securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::securePasswordKdfAlgoPBKDF2HMACSHA512iter100000(bytes &&salt_)
  : salt_(std::move(salt_))
{}

const std::int32_t securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::ID;

object_ptr<SecurePasswordKdfAlgo> securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::fetch(TlBufferParser &p) {
  return make_tl_object<securePasswordKdfAlgoPBKDF2HMACSHA512iter100000>(p);
}

securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::securePasswordKdfAlgoPBKDF2HMACSHA512iter100000(TlBufferParser &p)
  : salt_(TlFetchBytes<bytes>::parse(p))
{}

void securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(salt_, s);
}

void securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(salt_, s);
}

void securePasswordKdfAlgoPBKDF2HMACSHA512iter100000::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "securePasswordKdfAlgoPBKDF2HMACSHA512iter100000");
    s.store_bytes_field("salt", salt_);
    s.store_class_end();
  }
}

securePasswordKdfAlgoSHA512::securePasswordKdfAlgoSHA512(bytes &&salt_)
  : salt_(std::move(salt_))
{}

const std::int32_t securePasswordKdfAlgoSHA512::ID;

object_ptr<SecurePasswordKdfAlgo> securePasswordKdfAlgoSHA512::fetch(TlBufferParser &p) {
  return make_tl_object<securePasswordKdfAlgoSHA512>(p);
}

securePasswordKdfAlgoSHA512::securePasswordKdfAlgoSHA512(TlBufferParser &p)
  : salt_(TlFetchBytes<bytes>::parse(p))
{}

void securePasswordKdfAlgoSHA512::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(salt_, s);
}

void securePasswordKdfAlgoSHA512::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(salt_, s);
}

void securePasswordKdfAlgoSHA512::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "securePasswordKdfAlgoSHA512");
    s.store_bytes_field("salt", salt_);
    s.store_class_end();
  }
}

secureValueHash::secureValueHash(object_ptr<SecureValueType> &&type_, bytes &&hash_)
  : type_(std::move(type_))
  , hash_(std::move(hash_))
{}

const std::int32_t secureValueHash::ID;

void secureValueHash::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(hash_, s);
}

void secureValueHash::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(type_, s);
  TlStoreString::store(hash_, s);
}

void secureValueHash::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValueHash");
    s.store_object_field("type", static_cast<const BaseObject *>(type_.get()));
    s.store_bytes_field("hash", hash_);
    s.store_class_end();
  }
}

shippingOption::shippingOption(string const &id_, string const &title_, array<object_ptr<labeledPrice>> &&prices_)
  : id_(id_)
  , title_(title_)
  , prices_(std::move(prices_))
{}

const std::int32_t shippingOption::ID;

object_ptr<shippingOption> shippingOption::fetch(TlBufferParser &p) {
  return make_tl_object<shippingOption>(p);
}

shippingOption::shippingOption(TlBufferParser &p)
  : id_(TlFetchString<string>::parse(p))
  , title_(TlFetchString<string>::parse(p))
  , prices_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<labeledPrice>, -886477832>>, 481674261>::parse(p))
{}

void shippingOption::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -886477832>>, 481674261>::store(prices_, s);
}

void shippingOption::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(id_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -886477832>>, 481674261>::store(prices_, s);
}

void shippingOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "shippingOption");
    s.store_field("id", id_);
    s.store_field("title", title_);
    { s.store_vector_begin("prices", prices_.size()); for (const auto &_value : prices_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t smsJob::ID;

object_ptr<smsJob> smsJob::fetch(TlBufferParser &p) {
  return make_tl_object<smsJob>(p);
}

smsJob::smsJob(TlBufferParser &p)
  : job_id_(TlFetchString<string>::parse(p))
  , phone_number_(TlFetchString<string>::parse(p))
  , text_(TlFetchString<string>::parse(p))
{}

void smsJob::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsJob");
    s.store_field("job_id", job_id_);
    s.store_field("phone_number", phone_number_);
    s.store_field("text", text_);
    s.store_class_end();
  }
}

object_ptr<StarGiftAttributeId> StarGiftAttributeId::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case starGiftAttributeIdModel::ID:
      return starGiftAttributeIdModel::fetch(p);
    case starGiftAttributeIdPattern::ID:
      return starGiftAttributeIdPattern::fetch(p);
    case starGiftAttributeIdBackdrop::ID:
      return starGiftAttributeIdBackdrop::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

starGiftAttributeIdModel::starGiftAttributeIdModel(int64 document_id_)
  : document_id_(document_id_)
{}

const std::int32_t starGiftAttributeIdModel::ID;

object_ptr<StarGiftAttributeId> starGiftAttributeIdModel::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeIdModel>(p);
}

starGiftAttributeIdModel::starGiftAttributeIdModel(TlBufferParser &p)
  : document_id_(TlFetchLong::parse(p))
{}

void starGiftAttributeIdModel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
}

void starGiftAttributeIdModel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
}

void starGiftAttributeIdModel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeIdModel");
    s.store_field("document_id", document_id_);
    s.store_class_end();
  }
}

starGiftAttributeIdPattern::starGiftAttributeIdPattern(int64 document_id_)
  : document_id_(document_id_)
{}

const std::int32_t starGiftAttributeIdPattern::ID;

object_ptr<StarGiftAttributeId> starGiftAttributeIdPattern::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeIdPattern>(p);
}

starGiftAttributeIdPattern::starGiftAttributeIdPattern(TlBufferParser &p)
  : document_id_(TlFetchLong::parse(p))
{}

void starGiftAttributeIdPattern::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
}

void starGiftAttributeIdPattern::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
}

void starGiftAttributeIdPattern::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeIdPattern");
    s.store_field("document_id", document_id_);
    s.store_class_end();
  }
}

starGiftAttributeIdBackdrop::starGiftAttributeIdBackdrop(int32 backdrop_id_)
  : backdrop_id_(backdrop_id_)
{}

const std::int32_t starGiftAttributeIdBackdrop::ID;

object_ptr<StarGiftAttributeId> starGiftAttributeIdBackdrop::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeIdBackdrop>(p);
}

starGiftAttributeIdBackdrop::starGiftAttributeIdBackdrop(TlBufferParser &p)
  : backdrop_id_(TlFetchInt::parse(p))
{}

void starGiftAttributeIdBackdrop::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(backdrop_id_, s);
}

void starGiftAttributeIdBackdrop::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(backdrop_id_, s);
}

void starGiftAttributeIdBackdrop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeIdBackdrop");
    s.store_field("backdrop_id", backdrop_id_);
    s.store_class_end();
  }
}

object_ptr<StarGiftAttributeRarity> StarGiftAttributeRarity::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

starGiftAttributeRarity::starGiftAttributeRarity(int32 permille_)
  : permille_(permille_)
{}

const std::int32_t starGiftAttributeRarity::ID;

object_ptr<StarGiftAttributeRarity> starGiftAttributeRarity::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeRarity>(p);
}

starGiftAttributeRarity::starGiftAttributeRarity(TlBufferParser &p)
  : permille_(TlFetchInt::parse(p))
{}

void starGiftAttributeRarity::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(permille_, s);
}

void starGiftAttributeRarity::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(permille_, s);
}

void starGiftAttributeRarity::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeRarity");
    s.store_field("permille", permille_);
    s.store_class_end();
  }
}

const std::int32_t starGiftAttributeRarityUncommon::ID;

object_ptr<StarGiftAttributeRarity> starGiftAttributeRarityUncommon::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeRarityUncommon>();
}

void starGiftAttributeRarityUncommon::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityUncommon::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityUncommon::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeRarityUncommon");
    s.store_class_end();
  }
}

const std::int32_t starGiftAttributeRarityRare::ID;

object_ptr<StarGiftAttributeRarity> starGiftAttributeRarityRare::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeRarityRare>();
}

void starGiftAttributeRarityRare::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityRare::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityRare::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeRarityRare");
    s.store_class_end();
  }
}

const std::int32_t starGiftAttributeRarityEpic::ID;

object_ptr<StarGiftAttributeRarity> starGiftAttributeRarityEpic::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeRarityEpic>();
}

void starGiftAttributeRarityEpic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityEpic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityEpic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeRarityEpic");
    s.store_class_end();
  }
}

const std::int32_t starGiftAttributeRarityLegendary::ID;

object_ptr<StarGiftAttributeRarity> starGiftAttributeRarityLegendary::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftAttributeRarityLegendary>();
}

void starGiftAttributeRarityLegendary::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityLegendary::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void starGiftAttributeRarityLegendary::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftAttributeRarityLegendary");
    s.store_class_end();
  }
}

starGiftCollection::starGiftCollection()
  : flags_()
  , collection_id_()
  , title_()
  , icon_()
  , gifts_count_()
  , hash_()
{}

const std::int32_t starGiftCollection::ID;

object_ptr<starGiftCollection> starGiftCollection::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starGiftCollection> res = make_tl_object<starGiftCollection>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collection_id_ = TlFetchInt::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->icon_ = TlFetchObject<Document>::parse(p); }
  res->gifts_count_ = TlFetchInt::parse(p);
  res->hash_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftCollection");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("collection_id", collection_id_);
    s.store_field("title", title_);
    if (var0 & 1) { s.store_object_field("icon", static_cast<const BaseObject *>(icon_.get())); }
    s.store_field("gifts_count", gifts_count_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

const std::int32_t statsURL::ID;

void statsURL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "statsURL");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

object_ptr<TopPeerCategory> TopPeerCategory::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t topPeerCategoryBotsPM::ID;

object_ptr<TopPeerCategory> topPeerCategoryBotsPM::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryBotsPM>();
}

void topPeerCategoryBotsPM::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsPM::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsPM::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryBotsPM");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryBotsInline::ID;

object_ptr<TopPeerCategory> topPeerCategoryBotsInline::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryBotsInline>();
}

void topPeerCategoryBotsInline::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsInline::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsInline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryBotsInline");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryCorrespondents::ID;

object_ptr<TopPeerCategory> topPeerCategoryCorrespondents::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryCorrespondents>();
}

void topPeerCategoryCorrespondents::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryCorrespondents::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryCorrespondents::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryCorrespondents");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryGroups::ID;

object_ptr<TopPeerCategory> topPeerCategoryGroups::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryGroups>();
}

void topPeerCategoryGroups::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryGroups::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryGroups");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryChannels::ID;

object_ptr<TopPeerCategory> topPeerCategoryChannels::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryChannels>();
}

void topPeerCategoryChannels::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryChannels::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryChannels");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryPhoneCalls::ID;

object_ptr<TopPeerCategory> topPeerCategoryPhoneCalls::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryPhoneCalls>();
}

void topPeerCategoryPhoneCalls::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryPhoneCalls::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryPhoneCalls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryPhoneCalls");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryForwardUsers::ID;

object_ptr<TopPeerCategory> topPeerCategoryForwardUsers::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryForwardUsers>();
}

void topPeerCategoryForwardUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryForwardUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryForwardUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryForwardUsers");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryForwardChats::ID;

object_ptr<TopPeerCategory> topPeerCategoryForwardChats::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryForwardChats>();
}

void topPeerCategoryForwardChats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryForwardChats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryForwardChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryForwardChats");
    s.store_class_end();
  }
}

const std::int32_t topPeerCategoryBotsApp::ID;

object_ptr<TopPeerCategory> topPeerCategoryBotsApp::fetch(TlBufferParser &p) {
  return make_tl_object<topPeerCategoryBotsApp>();
}

void topPeerCategoryBotsApp::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsApp::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void topPeerCategoryBotsApp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "topPeerCategoryBotsApp");
    s.store_class_end();
  }
}

object_ptr<UserProfilePhoto> UserProfilePhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case userProfilePhotoEmpty::ID:
      return userProfilePhotoEmpty::fetch(p);
    case userProfilePhoto::ID:
      return userProfilePhoto::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t userProfilePhotoEmpty::ID;

object_ptr<UserProfilePhoto> userProfilePhotoEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<userProfilePhotoEmpty>();
}

void userProfilePhotoEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userProfilePhotoEmpty");
    s.store_class_end();
  }
}

userProfilePhoto::userProfilePhoto()
  : flags_()
  , has_video_()
  , personal_()
  , photo_id_()
  , stripped_thumb_()
  , dc_id_()
{}

userProfilePhoto::userProfilePhoto(int32 flags_, bool has_video_, bool personal_, int64 photo_id_, bytes &&stripped_thumb_, int32 dc_id_)
  : flags_(flags_)
  , has_video_(has_video_)
  , personal_(personal_)
  , photo_id_(photo_id_)
  , stripped_thumb_(std::move(stripped_thumb_))
  , dc_id_(dc_id_)
{}

const std::int32_t userProfilePhoto::ID;

object_ptr<UserProfilePhoto> userProfilePhoto::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<userProfilePhoto> res = make_tl_object<userProfilePhoto>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_video_ = (var0 & 1) != 0;
  res->personal_ = (var0 & 4) != 0;
  res->photo_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->stripped_thumb_ = TlFetchBytes<bytes>::parse(p); }
  res->dc_id_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void userProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "userProfilePhoto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_video_ << 0) | (personal_ << 2)));
    if (var0 & 1) { s.store_field("has_video", true); }
    if (var0 & 4) { s.store_field("personal", true); }
    s.store_field("photo_id", photo_id_);
    if (var0 & 2) { s.store_bytes_field("stripped_thumb", stripped_thumb_); }
    s.store_field("dc_id", dc_id_);
    s.store_class_end();
  }
}

const std::int32_t auth_exportedAuthorization::ID;

object_ptr<auth_exportedAuthorization> auth_exportedAuthorization::fetch(TlBufferParser &p) {
  return make_tl_object<auth_exportedAuthorization>(p);
}

auth_exportedAuthorization::auth_exportedAuthorization(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void auth_exportedAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.exportedAuthorization");
    s.store_field("id", id_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

object_ptr<auth_LoginToken> auth_LoginToken::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case auth_loginToken::ID:
      return auth_loginToken::fetch(p);
    case auth_loginTokenMigrateTo::ID:
      return auth_loginTokenMigrateTo::fetch(p);
    case auth_loginTokenSuccess::ID:
      return auth_loginTokenSuccess::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t auth_loginToken::ID;

object_ptr<auth_LoginToken> auth_loginToken::fetch(TlBufferParser &p) {
  return make_tl_object<auth_loginToken>(p);
}

auth_loginToken::auth_loginToken(TlBufferParser &p)
  : expires_(TlFetchInt::parse(p))
  , token_(TlFetchBytes<bytes>::parse(p))
{}

void auth_loginToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.loginToken");
    s.store_field("expires", expires_);
    s.store_bytes_field("token", token_);
    s.store_class_end();
  }
}

const std::int32_t auth_loginTokenMigrateTo::ID;

object_ptr<auth_LoginToken> auth_loginTokenMigrateTo::fetch(TlBufferParser &p) {
  return make_tl_object<auth_loginTokenMigrateTo>(p);
}

auth_loginTokenMigrateTo::auth_loginTokenMigrateTo(TlBufferParser &p)
  : dc_id_(TlFetchInt::parse(p))
  , token_(TlFetchBytes<bytes>::parse(p))
{}

void auth_loginTokenMigrateTo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.loginTokenMigrateTo");
    s.store_field("dc_id", dc_id_);
    s.store_bytes_field("token", token_);
    s.store_class_end();
  }
}

const std::int32_t auth_loginTokenSuccess::ID;

object_ptr<auth_LoginToken> auth_loginTokenSuccess::fetch(TlBufferParser &p) {
  return make_tl_object<auth_loginTokenSuccess>(p);
}

auth_loginTokenSuccess::auth_loginTokenSuccess(TlBufferParser &p)
  : authorization_(TlFetchObject<auth_Authorization>::parse(p))
{}

void auth_loginTokenSuccess::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.loginTokenSuccess");
    s.store_object_field("authorization", static_cast<const BaseObject *>(authorization_.get()));
    s.store_class_end();
  }
}

const std::int32_t bots_exportedBotToken::ID;

object_ptr<bots_exportedBotToken> bots_exportedBotToken::fetch(TlBufferParser &p) {
  return make_tl_object<bots_exportedBotToken>(p);
}

bots_exportedBotToken::bots_exportedBotToken(TlBufferParser &p)
  : token_(TlFetchString<string>::parse(p))
{}

void bots_exportedBotToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.exportedBotToken");
    s.store_field("token", token_);
    s.store_class_end();
  }
}

const std::int32_t chatlists_chatlistUpdates::ID;

object_ptr<chatlists_chatlistUpdates> chatlists_chatlistUpdates::fetch(TlBufferParser &p) {
  return make_tl_object<chatlists_chatlistUpdates>(p);
}

chatlists_chatlistUpdates::chatlists_chatlistUpdates(TlBufferParser &p)
  : missing_peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void chatlists_chatlistUpdates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.chatlistUpdates");
    { s.store_vector_begin("missing_peers", missing_peers_.size()); for (const auto &_value : missing_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t contacts_importedContacts::ID;

object_ptr<contacts_importedContacts> contacts_importedContacts::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_importedContacts>(p);
}

contacts_importedContacts::contacts_importedContacts(TlBufferParser &p)
  : imported_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<importedContact>, -1052885936>>, 481674261>::parse(p))
  , popular_invites_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<popularContact>, 1558266229>>, 481674261>::parse(p))
  , retry_contacts_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_importedContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.importedContacts");
    { s.store_vector_begin("imported", imported_.size()); for (const auto &_value : imported_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("popular_invites", popular_invites_.size()); for (const auto &_value : popular_invites_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("retry_contacts", retry_contacts_.size()); for (const auto &_value : retry_contacts_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<help_AppConfig> help_AppConfig::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case help_appConfigNotModified::ID:
      return help_appConfigNotModified::fetch(p);
    case help_appConfig::ID:
      return help_appConfig::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t help_appConfigNotModified::ID;

object_ptr<help_AppConfig> help_appConfigNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<help_appConfigNotModified>();
}

void help_appConfigNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.appConfigNotModified");
    s.store_class_end();
  }
}

const std::int32_t help_appConfig::ID;

object_ptr<help_AppConfig> help_appConfig::fetch(TlBufferParser &p) {
  return make_tl_object<help_appConfig>(p);
}

help_appConfig::help_appConfig(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , config_(TlFetchObject<JSONValue>::parse(p))
{}

void help_appConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.appConfig");
    s.store_field("hash", hash_);
    s.store_object_field("config", static_cast<const BaseObject *>(config_.get()));
    s.store_class_end();
  }
}

const std::int32_t help_premiumPromo::ID;

object_ptr<help_premiumPromo> help_premiumPromo::fetch(TlBufferParser &p) {
  return make_tl_object<help_premiumPromo>(p);
}

help_premiumPromo::help_premiumPromo(TlBufferParser &p)
  : status_text_(TlFetchString<string>::parse(p))
  , status_entities_(TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p))
  , video_sections_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
  , videos_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
  , period_options_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<premiumSubscriptionOption>, 1596792306>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void help_premiumPromo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.premiumPromo");
    s.store_field("status_text", status_text_);
    { s.store_vector_begin("status_entities", status_entities_.size()); for (const auto &_value : status_entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("video_sections", video_sections_.size()); for (const auto &_value : video_sections_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("videos", videos_.size()); for (const auto &_value : videos_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("period_options", period_options_.size()); for (const auto &_value : period_options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t help_supportName::ID;

object_ptr<help_supportName> help_supportName::fetch(TlBufferParser &p) {
  return make_tl_object<help_supportName>(p);
}

help_supportName::help_supportName(TlBufferParser &p)
  : name_(TlFetchString<string>::parse(p))
{}

void help_supportName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.supportName");
    s.store_field("name", name_);
    s.store_class_end();
  }
}

messages_botResults::messages_botResults()
  : flags_()
  , gallery_()
  , query_id_()
  , next_offset_()
  , switch_pm_()
  , switch_webview_()
  , results_()
  , cache_time_()
  , users_()
{}

const std::int32_t messages_botResults::ID;

object_ptr<messages_botResults> messages_botResults::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_botResults> res = make_tl_object<messages_botResults>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->gallery_ = (var0 & 1) != 0;
  res->query_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->switch_pm_ = TlFetchBoxed<TlFetchObject<inlineBotSwitchPM>, 1008755359>::parse(p); }
  if (var0 & 8) { res->switch_webview_ = TlFetchBoxed<TlFetchObject<inlineBotWebView>, -1250781739>::parse(p); }
  res->results_ = TlFetchBoxed<TlFetchVector<TlFetchObject<BotInlineResult>>, 481674261>::parse(p);
  res->cache_time_ = TlFetchInt::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_botResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.botResults");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (gallery_ << 0)));
    if (var0 & 1) { s.store_field("gallery", true); }
    s.store_field("query_id", query_id_);
    if (var0 & 2) { s.store_field("next_offset", next_offset_); }
    if (var0 & 4) { s.store_object_field("switch_pm", static_cast<const BaseObject *>(switch_pm_.get())); }
    if (var0 & 8) { s.store_object_field("switch_webview", static_cast<const BaseObject *>(switch_webview_.get())); }
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("cache_time", cache_time_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_chatInviteImporters::ID;

object_ptr<messages_chatInviteImporters> messages_chatInviteImporters::fetch(TlBufferParser &p) {
  return make_tl_object<messages_chatInviteImporters>(p);
}

messages_chatInviteImporters::messages_chatInviteImporters(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , importers_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<chatInviteImporter>, -1940201511>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_chatInviteImporters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.chatInviteImporters");
    s.store_field("count", count_);
    { s.store_vector_begin("importers", importers_.size()); for (const auto &_value : importers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_Chats> messages_Chats::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_chats::ID:
      return messages_chats::fetch(p);
    case messages_chatsSlice::ID:
      return messages_chatsSlice::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_chats::ID;

object_ptr<messages_Chats> messages_chats::fetch(TlBufferParser &p) {
  return make_tl_object<messages_chats>(p);
}

messages_chats::messages_chats(TlBufferParser &p)
  : chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
{}

void messages_chats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.chats");
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_chatsSlice::ID;

object_ptr<messages_Chats> messages_chatsSlice::fetch(TlBufferParser &p) {
  return make_tl_object<messages_chatsSlice>(p);
}

messages_chatsSlice::messages_chatsSlice(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
{}

void messages_chatsSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.chatsSlice");
    s.store_field("count", count_);
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_checkedHistoryImportPeer::ID;

object_ptr<messages_checkedHistoryImportPeer> messages_checkedHistoryImportPeer::fetch(TlBufferParser &p) {
  return make_tl_object<messages_checkedHistoryImportPeer>(p);
}

messages_checkedHistoryImportPeer::messages_checkedHistoryImportPeer(TlBufferParser &p)
  : confirm_text_(TlFetchString<string>::parse(p))
{}

void messages_checkedHistoryImportPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.checkedHistoryImportPeer");
    s.store_field("confirm_text", confirm_text_);
    s.store_class_end();
  }
}

messages_composedMessageWithAI::messages_composedMessageWithAI()
  : flags_()
  , result_text_()
  , diff_text_()
{}

const std::int32_t messages_composedMessageWithAI::ID;

object_ptr<messages_composedMessageWithAI> messages_composedMessageWithAI::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_composedMessageWithAI> res = make_tl_object<messages_composedMessageWithAI>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->result_text_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (var0 & 1) { res->diff_text_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_composedMessageWithAI::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.composedMessageWithAI");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("result_text", static_cast<const BaseObject *>(result_text_.get()));
    if (var0 & 1) { s.store_object_field("diff_text", static_cast<const BaseObject *>(diff_text_.get())); }
    s.store_class_end();
  }
}

object_ptr<messages_Dialogs> messages_Dialogs::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_dialogs::ID:
      return messages_dialogs::fetch(p);
    case messages_dialogsSlice::ID:
      return messages_dialogsSlice::fetch(p);
    case messages_dialogsNotModified::ID:
      return messages_dialogsNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_dialogs::ID;

object_ptr<messages_Dialogs> messages_dialogs::fetch(TlBufferParser &p) {
  return make_tl_object<messages_dialogs>(p);
}

messages_dialogs::messages_dialogs(TlBufferParser &p)
  : dialogs_(TlFetchBoxed<TlFetchVector<TlFetchObject<Dialog>>, 481674261>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_dialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.dialogs");
    { s.store_vector_begin("dialogs", dialogs_.size()); for (const auto &_value : dialogs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_dialogsSlice::ID;

object_ptr<messages_Dialogs> messages_dialogsSlice::fetch(TlBufferParser &p) {
  return make_tl_object<messages_dialogsSlice>(p);
}

messages_dialogsSlice::messages_dialogsSlice(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , dialogs_(TlFetchBoxed<TlFetchVector<TlFetchObject<Dialog>>, 481674261>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_dialogsSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.dialogsSlice");
    s.store_field("count", count_);
    { s.store_vector_begin("dialogs", dialogs_.size()); for (const auto &_value : dialogs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_dialogsNotModified::ID;

object_ptr<messages_Dialogs> messages_dialogsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_dialogsNotModified>(p);
}

messages_dialogsNotModified::messages_dialogsNotModified(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
{}

void messages_dialogsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.dialogsNotModified");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

object_ptr<messages_EmojiGroups> messages_EmojiGroups::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_emojiGroupsNotModified::ID:
      return messages_emojiGroupsNotModified::fetch(p);
    case messages_emojiGroups::ID:
      return messages_emojiGroups::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_emojiGroupsNotModified::ID;

object_ptr<messages_EmojiGroups> messages_emojiGroupsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_emojiGroupsNotModified>();
}

void messages_emojiGroupsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.emojiGroupsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_emojiGroups::ID;

object_ptr<messages_EmojiGroups> messages_emojiGroups::fetch(TlBufferParser &p) {
  return make_tl_object<messages_emojiGroups>(p);
}

messages_emojiGroups::messages_emojiGroups(TlBufferParser &p)
  : hash_(TlFetchInt::parse(p))
  , groups_(TlFetchBoxed<TlFetchVector<TlFetchObject<EmojiGroup>>, 481674261>::parse(p))
{}

void messages_emojiGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.emojiGroups");
    s.store_field("hash", hash_);
    { s.store_vector_begin("groups", groups_.size()); for (const auto &_value : groups_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_FeaturedStickers> messages_FeaturedStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_featuredStickersNotModified::ID:
      return messages_featuredStickersNotModified::fetch(p);
    case messages_featuredStickers::ID:
      return messages_featuredStickers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_featuredStickersNotModified::ID;

object_ptr<messages_FeaturedStickers> messages_featuredStickersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_featuredStickersNotModified>(p);
}

messages_featuredStickersNotModified::messages_featuredStickersNotModified(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
{}

void messages_featuredStickersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.featuredStickersNotModified");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

messages_featuredStickers::messages_featuredStickers()
  : flags_()
  , premium_()
  , hash_()
  , count_()
  , sets_()
  , unread_()
{}

const std::int32_t messages_featuredStickers::ID;

object_ptr<messages_FeaturedStickers> messages_featuredStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_featuredStickers> res = make_tl_object<messages_featuredStickers>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->premium_ = (var0 & 1) != 0;
  res->hash_ = TlFetchLong::parse(p);
  res->count_ = TlFetchInt::parse(p);
  res->sets_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StickerSetCovered>>, 481674261>::parse(p);
  res->unread_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messages_featuredStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.featuredStickers");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (premium_ << 0)));
    if (var0 & 1) { s.store_field("premium", true); }
    s.store_field("hash", hash_);
    s.store_field("count", count_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("unread", unread_.size()); for (const auto &_value : unread_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_historyImportParsed::messages_historyImportParsed()
  : flags_()
  , pm_()
  , group_()
  , title_()
{}

const std::int32_t messages_historyImportParsed::ID;

object_ptr<messages_historyImportParsed> messages_historyImportParsed::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_historyImportParsed> res = make_tl_object<messages_historyImportParsed>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pm_ = (var0 & 1) != 0;
  res->group_ = (var0 & 2) != 0;
  if (var0 & 4) { res->title_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_historyImportParsed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.historyImportParsed");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pm_ << 0) | (group_ << 1)));
    if (var0 & 1) { s.store_field("pm", true); }
    if (var0 & 2) { s.store_field("group", true); }
    if (var0 & 4) { s.store_field("title", title_); }
    s.store_class_end();
  }
}

object_ptr<messages_SavedDialogs> messages_SavedDialogs::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_savedDialogs::ID:
      return messages_savedDialogs::fetch(p);
    case messages_savedDialogsSlice::ID:
      return messages_savedDialogsSlice::fetch(p);
    case messages_savedDialogsNotModified::ID:
      return messages_savedDialogsNotModified::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_savedDialogs::ID;

object_ptr<messages_SavedDialogs> messages_savedDialogs::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedDialogs>(p);
}

messages_savedDialogs::messages_savedDialogs(TlBufferParser &p)
  : dialogs_(TlFetchBoxed<TlFetchVector<TlFetchObject<SavedDialog>>, 481674261>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_savedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedDialogs");
    { s.store_vector_begin("dialogs", dialogs_.size()); for (const auto &_value : dialogs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_savedDialogsSlice::ID;

object_ptr<messages_SavedDialogs> messages_savedDialogsSlice::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedDialogsSlice>(p);
}

messages_savedDialogsSlice::messages_savedDialogsSlice(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , dialogs_(TlFetchBoxed<TlFetchVector<TlFetchObject<SavedDialog>>, 481674261>::parse(p))
  , messages_(TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_savedDialogsSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedDialogsSlice");
    s.store_field("count", count_);
    { s.store_vector_begin("dialogs", dialogs_.size()); for (const auto &_value : dialogs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_savedDialogsNotModified::ID;

object_ptr<messages_SavedDialogs> messages_savedDialogsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_savedDialogsNotModified>(p);
}

messages_savedDialogsNotModified::messages_savedDialogsNotModified(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
{}

void messages_savedDialogsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savedDialogsNotModified");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

messages_searchResultsCalendar::messages_searchResultsCalendar()
  : flags_()
  , inexact_()
  , count_()
  , min_date_()
  , min_msg_id_()
  , offset_id_offset_()
  , periods_()
  , messages_()
  , chats_()
  , users_()
{}

const std::int32_t messages_searchResultsCalendar::ID;

object_ptr<messages_searchResultsCalendar> messages_searchResultsCalendar::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_searchResultsCalendar> res = make_tl_object<messages_searchResultsCalendar>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->inexact_ = (var0 & 1) != 0;
  res->count_ = TlFetchInt::parse(p);
  res->min_date_ = TlFetchInt::parse(p);
  res->min_msg_id_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->offset_id_offset_ = TlFetchInt::parse(p); }
  res->periods_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<searchResultsCalendarPeriod>, -911191137>>, 481674261>::parse(p);
  res->messages_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Message>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_searchResultsCalendar::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchResultsCalendar");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (inexact_ << 0)));
    if (var0 & 1) { s.store_field("inexact", true); }
    s.store_field("count", count_);
    s.store_field("min_date", min_date_);
    s.store_field("min_msg_id", min_msg_id_);
    if (var0 & 2) { s.store_field("offset_id_offset", offset_id_offset_); }
    { s.store_vector_begin("periods", periods_.size()); for (const auto &_value : periods_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("messages", messages_.size()); for (const auto &_value : messages_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_SentEncryptedMessage> messages_SentEncryptedMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_sentEncryptedMessage::ID:
      return messages_sentEncryptedMessage::fetch(p);
    case messages_sentEncryptedFile::ID:
      return messages_sentEncryptedFile::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_sentEncryptedMessage::ID;

object_ptr<messages_SentEncryptedMessage> messages_sentEncryptedMessage::fetch(TlBufferParser &p) {
  return make_tl_object<messages_sentEncryptedMessage>(p);
}

messages_sentEncryptedMessage::messages_sentEncryptedMessage(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
{}

void messages_sentEncryptedMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sentEncryptedMessage");
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t messages_sentEncryptedFile::ID;

object_ptr<messages_SentEncryptedMessage> messages_sentEncryptedFile::fetch(TlBufferParser &p) {
  return make_tl_object<messages_sentEncryptedFile>(p);
}

messages_sentEncryptedFile::messages_sentEncryptedFile(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
  , file_(TlFetchObject<EncryptedFile>::parse(p))
{}

void messages_sentEncryptedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sentEncryptedFile");
    s.store_field("date", date_);
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

object_ptr<payments_StarGiftActiveAuctions> payments_StarGiftActiveAuctions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_starGiftActiveAuctionsNotModified::ID:
      return payments_starGiftActiveAuctionsNotModified::fetch(p);
    case payments_starGiftActiveAuctions::ID:
      return payments_starGiftActiveAuctions::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t payments_starGiftActiveAuctionsNotModified::ID;

object_ptr<payments_StarGiftActiveAuctions> payments_starGiftActiveAuctionsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftActiveAuctionsNotModified>();
}

void payments_starGiftActiveAuctionsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftActiveAuctionsNotModified");
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftActiveAuctions::ID;

object_ptr<payments_StarGiftActiveAuctions> payments_starGiftActiveAuctions::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftActiveAuctions>(p);
}

payments_starGiftActiveAuctions::payments_starGiftActiveAuctions(TlBufferParser &p)
  : auctions_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starGiftActiveAuctionState>, -753154979>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
{}

void payments_starGiftActiveAuctions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftActiveAuctions");
    { s.store_vector_begin("auctions", auctions_.size()); for (const auto &_value : auctions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_uniqueStarGiftValueInfo::payments_uniqueStarGiftValueInfo()
  : flags_()
  , last_sale_on_fragment_()
  , value_is_average_()
  , currency_()
  , value_()
  , initial_sale_date_()
  , initial_sale_stars_()
  , initial_sale_price_()
  , last_sale_date_()
  , last_sale_price_()
  , floor_price_()
  , average_price_()
  , listed_count_()
  , fragment_listed_count_()
  , fragment_listed_url_()
{}

const std::int32_t payments_uniqueStarGiftValueInfo::ID;

object_ptr<payments_uniqueStarGiftValueInfo> payments_uniqueStarGiftValueInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_uniqueStarGiftValueInfo> res = make_tl_object<payments_uniqueStarGiftValueInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->last_sale_on_fragment_ = (var0 & 2) != 0;
  res->value_is_average_ = (var0 & 64) != 0;
  res->currency_ = TlFetchString<string>::parse(p);
  res->value_ = TlFetchLong::parse(p);
  res->initial_sale_date_ = TlFetchInt::parse(p);
  res->initial_sale_stars_ = TlFetchLong::parse(p);
  res->initial_sale_price_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->last_sale_date_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->last_sale_price_ = TlFetchLong::parse(p); }
  if (var0 & 4) { res->floor_price_ = TlFetchLong::parse(p); }
  if (var0 & 8) { res->average_price_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->listed_count_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->fragment_listed_count_ = TlFetchInt::parse(p); }
  if (var0 & 32) { res->fragment_listed_url_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_uniqueStarGiftValueInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.uniqueStarGiftValueInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (last_sale_on_fragment_ << 1) | (value_is_average_ << 6)));
    if (var0 & 2) { s.store_field("last_sale_on_fragment", true); }
    if (var0 & 64) { s.store_field("value_is_average", true); }
    s.store_field("currency", currency_);
    s.store_field("value", value_);
    s.store_field("initial_sale_date", initial_sale_date_);
    s.store_field("initial_sale_stars", initial_sale_stars_);
    s.store_field("initial_sale_price", initial_sale_price_);
    if (var0 & 1) { s.store_field("last_sale_date", last_sale_date_); }
    if (var0 & 1) { s.store_field("last_sale_price", last_sale_price_); }
    if (var0 & 4) { s.store_field("floor_price", floor_price_); }
    if (var0 & 8) { s.store_field("average_price", average_price_); }
    if (var0 & 16) { s.store_field("listed_count", listed_count_); }
    if (var0 & 32) { s.store_field("fragment_listed_count", fragment_listed_count_); }
    if (var0 & 32) { s.store_field("fragment_listed_url", fragment_listed_url_); }
    s.store_class_end();
  }
}

object_ptr<storage_FileType> storage_FileType::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t storage_fileUnknown::ID;

object_ptr<storage_FileType> storage_fileUnknown::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileUnknown>();
}

void storage_fileUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileUnknown");
    s.store_class_end();
  }
}

const std::int32_t storage_filePartial::ID;

object_ptr<storage_FileType> storage_filePartial::fetch(TlBufferParser &p) {
  return make_tl_object<storage_filePartial>();
}

void storage_filePartial::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.filePartial");
    s.store_class_end();
  }
}

const std::int32_t storage_fileJpeg::ID;

object_ptr<storage_FileType> storage_fileJpeg::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileJpeg>();
}

void storage_fileJpeg::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileJpeg");
    s.store_class_end();
  }
}

const std::int32_t storage_fileGif::ID;

object_ptr<storage_FileType> storage_fileGif::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileGif>();
}

void storage_fileGif::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileGif");
    s.store_class_end();
  }
}

const std::int32_t storage_filePng::ID;

object_ptr<storage_FileType> storage_filePng::fetch(TlBufferParser &p) {
  return make_tl_object<storage_filePng>();
}

void storage_filePng::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.filePng");
    s.store_class_end();
  }
}

const std::int32_t storage_filePdf::ID;

object_ptr<storage_FileType> storage_filePdf::fetch(TlBufferParser &p) {
  return make_tl_object<storage_filePdf>();
}

void storage_filePdf::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.filePdf");
    s.store_class_end();
  }
}

const std::int32_t storage_fileMp3::ID;

object_ptr<storage_FileType> storage_fileMp3::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileMp3>();
}

void storage_fileMp3::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileMp3");
    s.store_class_end();
  }
}

const std::int32_t storage_fileMov::ID;

object_ptr<storage_FileType> storage_fileMov::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileMov>();
}

void storage_fileMov::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileMov");
    s.store_class_end();
  }
}

const std::int32_t storage_fileMp4::ID;

object_ptr<storage_FileType> storage_fileMp4::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileMp4>();
}

void storage_fileMp4::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileMp4");
    s.store_class_end();
  }
}

const std::int32_t storage_fileWebp::ID;

object_ptr<storage_FileType> storage_fileWebp::fetch(TlBufferParser &p) {
  return make_tl_object<storage_fileWebp>();
}

void storage_fileWebp::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storage.fileWebp");
    s.store_class_end();
  }
}

stories_stories::stories_stories()
  : flags_()
  , count_()
  , stories_()
  , pinned_to_top_()
  , chats_()
  , users_()
{}

const std::int32_t stories_stories::ID;

object_ptr<stories_stories> stories_stories::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stories_stories> res = make_tl_object<stories_stories>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->stories_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StoryItem>>, 481674261>::parse(p);
  if (var0 & 1) { res->pinned_to_top_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void stories_stories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.stories");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("count", count_);
    { s.store_vector_begin("stories", stories_.size()); for (const auto &_value : stories_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { { s.store_vector_begin("pinned_to_top", pinned_to_top_.size()); for (const auto &_value : pinned_to_top_) { s.store_field("", _value); } s.store_class_end(); } }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<users_Users> users_Users::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case users_users::ID:
      return users_users::fetch(p);
    case users_usersSlice::ID:
      return users_usersSlice::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t users_users::ID;

object_ptr<users_Users> users_users::fetch(TlBufferParser &p) {
  return make_tl_object<users_users>(p);
}

users_users::users_users(TlBufferParser &p)
  : users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void users_users::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.users");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t users_usersSlice::ID;

object_ptr<users_Users> users_usersSlice::fetch(TlBufferParser &p) {
  return make_tl_object<users_usersSlice>(p);
}

users_usersSlice::users_usersSlice(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void users_usersSlice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.usersSlice");
    s.store_field("count", count_);
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t account_getAllSecureValues::ID;

void account_getAllSecureValues::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1299661699);
}

void account_getAllSecureValues::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1299661699);
}

void account_getAllSecureValues::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getAllSecureValues");
    s.store_class_end();
  }
}

account_getAllSecureValues::ReturnType account_getAllSecureValues::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<secureValue>, 411017418>>, 481674261>::parse(p);
#undef FAIL
}

account_getChannelRestrictedStatusEmojis::account_getChannelRestrictedStatusEmojis(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getChannelRestrictedStatusEmojis::ID;

void account_getChannelRestrictedStatusEmojis::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(900325589);
  TlStoreBinary::store(hash_, s);
}

void account_getChannelRestrictedStatusEmojis::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(900325589);
  TlStoreBinary::store(hash_, s);
}

void account_getChannelRestrictedStatusEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getChannelRestrictedStatusEmojis");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getChannelRestrictedStatusEmojis::ReturnType account_getChannelRestrictedStatusEmojis::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EmojiList>::parse(p);
#undef FAIL
}

const std::int32_t account_getContactSignUpNotification::ID;

void account_getContactSignUpNotification::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1626880216);
}

void account_getContactSignUpNotification::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1626880216);
}

void account_getContactSignUpNotification::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getContactSignUpNotification");
    s.store_class_end();
  }
}

account_getContactSignUpNotification::ReturnType account_getContactSignUpNotification::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_getDefaultBackgroundEmojis::account_getDefaultBackgroundEmojis(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getDefaultBackgroundEmojis::ID;

void account_getDefaultBackgroundEmojis::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1509246514);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultBackgroundEmojis::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1509246514);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultBackgroundEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getDefaultBackgroundEmojis");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getDefaultBackgroundEmojis::ReturnType account_getDefaultBackgroundEmojis::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EmojiList>::parse(p);
#undef FAIL
}

account_getMultiWallPapers::account_getMultiWallPapers(array<object_ptr<InputWallPaper>> &&wallpapers_)
  : wallpapers_(std::move(wallpapers_))
{}

const std::int32_t account_getMultiWallPapers::ID;

void account_getMultiWallPapers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1705865692);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(wallpapers_, s);
}

void account_getMultiWallPapers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1705865692);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(wallpapers_, s);
}

void account_getMultiWallPapers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getMultiWallPapers");
    { s.store_vector_begin("wallpapers", wallpapers_.size()); for (const auto &_value : wallpapers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_getMultiWallPapers::ReturnType account_getMultiWallPapers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<WallPaper>>, 481674261>::parse(p);
#undef FAIL
}

account_installTheme::account_installTheme(int32 flags_, bool dark_, object_ptr<InputTheme> &&theme_, string const &format_, object_ptr<BaseTheme> &&base_theme_)
  : flags_(flags_)
  , dark_(dark_)
  , theme_(std::move(theme_))
  , format_(format_)
  , base_theme_(std::move(base_theme_))
{}

const std::int32_t account_installTheme::ID;

void account_installTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-953697477);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s); }
  if (var0 & 4) { TlStoreString::store(format_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(base_theme_, s); }
}

void account_installTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-953697477);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s); }
  if (var0 & 4) { TlStoreString::store(format_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(base_theme_, s); }
}

void account_installTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.installTheme");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0)));
    if (var0 & 1) { s.store_field("dark", true); }
    if (var0 & 2) { s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get())); }
    if (var0 & 4) { s.store_field("format", format_); }
    if (var0 & 8) { s.store_object_field("base_theme", static_cast<const BaseObject *>(base_theme_.get())); }
    s.store_class_end();
  }
}

account_installTheme::ReturnType account_installTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_resetNotifySettings::ID;

void account_resetNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-612493497);
}

void account_resetNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-612493497);
}

void account_resetNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetNotifySettings");
    s.store_class_end();
  }
}

account_resetNotifySettings::ReturnType account_resetNotifySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_saveAutoDownloadSettings::account_saveAutoDownloadSettings(int32 flags_, bool low_, bool high_, object_ptr<autoDownloadSettings> &&settings_)
  : flags_(flags_)
  , low_(low_)
  , high_(high_)
  , settings_(std::move(settings_))
{}

const std::int32_t account_saveAutoDownloadSettings::ID;

void account_saveAutoDownloadSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1995661875);
  TlStoreBinary::store((var0 = flags_ | (low_ << 0) | (high_ << 1)), s);
  TlStoreBoxed<TlStoreObject, -1163561432>::store(settings_, s);
}

void account_saveAutoDownloadSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1995661875);
  TlStoreBinary::store((var0 = flags_ | (low_ << 0) | (high_ << 1)), s);
  TlStoreBoxed<TlStoreObject, -1163561432>::store(settings_, s);
}

void account_saveAutoDownloadSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveAutoDownloadSettings");
    s.store_field("flags", (var0 = flags_ | (low_ << 0) | (high_ << 1)));
    if (var0 & 1) { s.store_field("low", true); }
    if (var0 & 2) { s.store_field("high", true); }
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_saveAutoDownloadSettings::ReturnType account_saveAutoDownloadSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateBusinessGreetingMessage::account_updateBusinessGreetingMessage(int32 flags_, object_ptr<inputBusinessGreetingMessage> &&message_)
  : flags_(flags_)
  , message_(std::move(message_))
{}

const std::int32_t account_updateBusinessGreetingMessage::ID;

void account_updateBusinessGreetingMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1724755908);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 26528571>::store(message_, s); }
}

void account_updateBusinessGreetingMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1724755908);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 26528571>::store(message_, s); }
}

void account_updateBusinessGreetingMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateBusinessGreetingMessage");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("message", static_cast<const BaseObject *>(message_.get())); }
    s.store_class_end();
  }
}

account_updateBusinessGreetingMessage::ReturnType account_updateBusinessGreetingMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateBusinessIntro::account_updateBusinessIntro(int32 flags_, object_ptr<inputBusinessIntro> &&intro_)
  : flags_(flags_)
  , intro_(std::move(intro_))
{}

const std::int32_t account_updateBusinessIntro::ID;

void account_updateBusinessIntro::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1508585420);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 163867085>::store(intro_, s); }
}

void account_updateBusinessIntro::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1508585420);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, 163867085>::store(intro_, s); }
}

void account_updateBusinessIntro::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateBusinessIntro");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("intro", static_cast<const BaseObject *>(intro_.get())); }
    s.store_class_end();
  }
}

account_updateBusinessIntro::ReturnType account_updateBusinessIntro::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateDeviceLocked::account_updateDeviceLocked(int32 period_)
  : period_(period_)
{}

const std::int32_t account_updateDeviceLocked::ID;

void account_updateDeviceLocked::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(954152242);
  TlStoreBinary::store(period_, s);
}

void account_updateDeviceLocked::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(954152242);
  TlStoreBinary::store(period_, s);
}

void account_updateDeviceLocked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateDeviceLocked");
    s.store_field("period", period_);
    s.store_class_end();
  }
}

account_updateDeviceLocked::ReturnType account_updateDeviceLocked::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateNotifySettings::account_updateNotifySettings(object_ptr<InputNotifyPeer> &&peer_, object_ptr<inputPeerNotifySettings> &&settings_)
  : peer_(std::move(peer_))
  , settings_(std::move(settings_))
{}

const std::int32_t account_updateNotifySettings::ID;

void account_updateNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2067899501);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreObject, -892638494>::store(settings_, s);
}

void account_updateNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2067899501);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreObject, -892638494>::store(settings_, s);
}

void account_updateNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateNotifySettings");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_updateNotifySettings::ReturnType account_updateNotifySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updatePersonalChannel::account_updatePersonalChannel(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t account_updatePersonalChannel::ID;

void account_updatePersonalChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-649919008);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void account_updatePersonalChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-649919008);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void account_updatePersonalChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updatePersonalChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

account_updatePersonalChannel::ReturnType account_updatePersonalChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateStatus::account_updateStatus(bool offline_)
  : offline_(offline_)
{}

const std::int32_t account_updateStatus::ID;

void account_updateStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1713919532);
  TlStoreBool::store(offline_, s);
}

void account_updateStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1713919532);
  TlStoreBool::store(offline_, s);
}

void account_updateStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateStatus");
    s.store_field("offline", offline_);
    s.store_class_end();
  }
}

account_updateStatus::ReturnType account_updateStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_exportAuthorization::auth_exportAuthorization(int32 dc_id_)
  : dc_id_(dc_id_)
{}

const std::int32_t auth_exportAuthorization::ID;

void auth_exportAuthorization::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-440401971);
  TlStoreBinary::store(dc_id_, s);
}

void auth_exportAuthorization::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-440401971);
  TlStoreBinary::store(dc_id_, s);
}

void auth_exportAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.exportAuthorization");
    s.store_field("dc_id", dc_id_);
    s.store_class_end();
  }
}

auth_exportAuthorization::ReturnType auth_exportAuthorization::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<auth_exportedAuthorization>, -1271602504>::parse(p);
#undef FAIL
}

auth_sendCode::auth_sendCode(string const &phone_number_, int32 api_id_, string const &api_hash_, object_ptr<codeSettings> &&settings_)
  : phone_number_(phone_number_)
  , api_id_(api_id_)
  , api_hash_(api_hash_)
  , settings_(std::move(settings_))
{}

const std::int32_t auth_sendCode::ID;

void auth_sendCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1502141361);
  TlStoreString::store(phone_number_, s);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void auth_sendCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1502141361);
  TlStoreString::store(phone_number_, s);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreBoxed<TlStoreObject, -1390068360>::store(settings_, s);
}

void auth_sendCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.sendCode");
    s.store_field("phone_number", phone_number_);
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", api_hash_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

auth_sendCode::ReturnType auth_sendCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_SentCode>::parse(p);
#undef FAIL
}

bots_getBotCommands::bots_getBotCommands(object_ptr<BotCommandScope> &&scope_, string const &lang_code_)
  : scope_(std::move(scope_))
  , lang_code_(lang_code_)
{}

const std::int32_t bots_getBotCommands::ID;

void bots_getBotCommands::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-481554986);
  TlStoreBoxedUnknown<TlStoreObject>::store(scope_, s);
  TlStoreString::store(lang_code_, s);
}

void bots_getBotCommands::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-481554986);
  TlStoreBoxedUnknown<TlStoreObject>::store(scope_, s);
  TlStoreString::store(lang_code_, s);
}

void bots_getBotCommands::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getBotCommands");
    s.store_object_field("scope", static_cast<const BaseObject *>(scope_.get()));
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

bots_getBotCommands::ReturnType bots_getBotCommands::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<botCommand>, -1032140601>>, 481674261>::parse(p);
#undef FAIL
}

bots_getPopularAppBots::bots_getPopularAppBots(string const &offset_, int32 limit_)
  : offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t bots_getPopularAppBots::ID;

void bots_getPopularAppBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1034878574);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void bots_getPopularAppBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1034878574);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void bots_getPopularAppBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getPopularAppBots");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

bots_getPopularAppBots::ReturnType bots_getPopularAppBots::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<bots_popularAppBots>, 428978491>::parse(p);
#undef FAIL
}

bots_reorderPreviewMedias::bots_reorderPreviewMedias(object_ptr<InputUser> &&bot_, string const &lang_code_, array<object_ptr<InputMedia>> &&order_)
  : bot_(std::move(bot_))
  , lang_code_(lang_code_)
  , order_(std::move(order_))
{}

const std::int32_t bots_reorderPreviewMedias::ID;

void bots_reorderPreviewMedias::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1238895702);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s);
}

void bots_reorderPreviewMedias::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1238895702);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s);
}

void bots_reorderPreviewMedias::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.reorderPreviewMedias");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("lang_code", lang_code_);
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

bots_reorderPreviewMedias::ReturnType bots_reorderPreviewMedias::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_toggleUsername::bots_toggleUsername(object_ptr<InputUser> &&bot_, string const &username_, bool active_)
  : bot_(std::move(bot_))
  , username_(username_)
  , active_(active_)
{}

const std::int32_t bots_toggleUsername::ID;

void bots_toggleUsername::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(87861619);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(username_, s);
  TlStoreBool::store(active_, s);
}

void bots_toggleUsername::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(87861619);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(username_, s);
  TlStoreBool::store(active_, s);
}

void bots_toggleUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.toggleUsername");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("username", username_);
    s.store_field("active", active_);
    s.store_class_end();
  }
}

bots_toggleUsername::ReturnType bots_toggleUsername::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_updateStarRefProgram::bots_updateStarRefProgram(int32 flags_, object_ptr<InputUser> &&bot_, int32 commission_permille_, int32 duration_months_)
  : flags_(flags_)
  , bot_(std::move(bot_))
  , commission_permille_(commission_permille_)
  , duration_months_(duration_months_)
{}

const std::int32_t bots_updateStarRefProgram::ID;

void bots_updateStarRefProgram::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2005621427);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(commission_permille_, s);
  if (var0 & 1) { TlStoreBinary::store(duration_months_, s); }
}

void bots_updateStarRefProgram::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2005621427);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(commission_permille_, s);
  if (var0 & 1) { TlStoreBinary::store(duration_months_, s); }
}

void bots_updateStarRefProgram::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.updateStarRefProgram");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("commission_permille", commission_permille_);
    if (var0 & 1) { s.store_field("duration_months", duration_months_); }
    s.store_class_end();
  }
}

bots_updateStarRefProgram::ReturnType bots_updateStarRefProgram::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<starRefProgram>, -586389774>::parse(p);
#undef FAIL
}

channels_createChannel::channels_createChannel(int32 flags_, bool broadcast_, bool megagroup_, bool for_import_, bool forum_, string const &title_, string const &about_, object_ptr<InputGeoPoint> &&geo_point_, string const &address_, int32 ttl_period_)
  : flags_(flags_)
  , broadcast_(broadcast_)
  , megagroup_(megagroup_)
  , for_import_(for_import_)
  , forum_(forum_)
  , title_(title_)
  , about_(about_)
  , geo_point_(std::move(geo_point_))
  , address_(address_)
  , ttl_period_(ttl_period_)
{}

const std::int32_t channels_createChannel::ID;

void channels_createChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1862244601);
  TlStoreBinary::store((var0 = flags_ | (broadcast_ << 0) | (megagroup_ << 1) | (for_import_ << 3) | (forum_ << 5)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(about_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s); }
  if (var0 & 4) { TlStoreString::store(address_, s); }
  if (var0 & 16) { TlStoreBinary::store(ttl_period_, s); }
}

void channels_createChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1862244601);
  TlStoreBinary::store((var0 = flags_ | (broadcast_ << 0) | (megagroup_ << 1) | (for_import_ << 3) | (forum_ << 5)), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(about_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s); }
  if (var0 & 4) { TlStoreString::store(address_, s); }
  if (var0 & 16) { TlStoreBinary::store(ttl_period_, s); }
}

void channels_createChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.createChannel");
    s.store_field("flags", (var0 = flags_ | (broadcast_ << 0) | (megagroup_ << 1) | (for_import_ << 3) | (forum_ << 5)));
    if (var0 & 1) { s.store_field("broadcast", true); }
    if (var0 & 2) { s.store_field("megagroup", true); }
    if (var0 & 8) { s.store_field("for_import", true); }
    if (var0 & 32) { s.store_field("forum", true); }
    s.store_field("title", title_);
    s.store_field("about", about_);
    if (var0 & 4) { s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get())); }
    if (var0 & 4) { s.store_field("address", address_); }
    if (var0 & 16) { s.store_field("ttl_period", ttl_period_); }
    s.store_class_end();
  }
}

channels_createChannel::ReturnType channels_createChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_deleteMessages::channels_deleteMessages(object_ptr<InputChannel> &&channel_, array<int32> &&id_)
  : channel_(std::move(channel_))
  , id_(std::move(id_))
{}

const std::int32_t channels_deleteMessages::ID;

void channels_deleteMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2067661490);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void channels_deleteMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2067661490);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void channels_deleteMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.deleteMessages");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

channels_deleteMessages::ReturnType channels_deleteMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedMessages>, -2066640507>::parse(p);
#undef FAIL
}

channels_getParticipants::channels_getParticipants(object_ptr<InputChannel> &&channel_, object_ptr<ChannelParticipantsFilter> &&filter_, int32 offset_, int32 limit_, int64 hash_)
  : channel_(std::move(channel_))
  , filter_(std::move(filter_))
  , offset_(offset_)
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t channels_getParticipants::ID;

void channels_getParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2010044880);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void channels_getParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2010044880);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void channels_getParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getParticipants");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

channels_getParticipants::ReturnType channels_getParticipants::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<channels_ChannelParticipants>::parse(p);
#undef FAIL
}

channels_joinChannel::channels_joinChannel(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t channels_joinChannel::ID;

void channels_joinChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(615851205);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_joinChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(615851205);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_joinChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.joinChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_joinChannel::ReturnType channels_joinChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_leaveChannel::channels_leaveChannel(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t channels_leaveChannel::ID;

void channels_leaveChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-130635115);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_leaveChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-130635115);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_leaveChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.leaveChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_leaveChannel::ReturnType channels_leaveChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_readHistory::channels_readHistory(object_ptr<InputChannel> &&channel_, int32 max_id_)
  : channel_(std::move(channel_))
  , max_id_(max_id_)
{}

const std::int32_t channels_readHistory::ID;

void channels_readHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-871347913);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(max_id_, s);
}

void channels_readHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-871347913);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(max_id_, s);
}

void channels_readHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.readHistory");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

channels_readHistory::ReturnType channels_readHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_reportAntiSpamFalsePositive::channels_reportAntiSpamFalsePositive(object_ptr<InputChannel> &&channel_, int32 msg_id_)
  : channel_(std::move(channel_))
  , msg_id_(msg_id_)
{}

const std::int32_t channels_reportAntiSpamFalsePositive::ID;

void channels_reportAntiSpamFalsePositive::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1471109485);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
}

void channels_reportAntiSpamFalsePositive::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1471109485);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
}

void channels_reportAntiSpamFalsePositive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.reportAntiSpamFalsePositive");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

channels_reportAntiSpamFalsePositive::ReturnType channels_reportAntiSpamFalsePositive::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_setBoostsToUnblockRestrictions::channels_setBoostsToUnblockRestrictions(object_ptr<InputChannel> &&channel_, int32 boosts_)
  : channel_(std::move(channel_))
  , boosts_(boosts_)
{}

const std::int32_t channels_setBoostsToUnblockRestrictions::ID;

void channels_setBoostsToUnblockRestrictions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1388733202);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(boosts_, s);
}

void channels_setBoostsToUnblockRestrictions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1388733202);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(boosts_, s);
}

void channels_setBoostsToUnblockRestrictions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.setBoostsToUnblockRestrictions");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("boosts", boosts_);
    s.store_class_end();
  }
}

channels_setBoostsToUnblockRestrictions::ReturnType channels_setBoostsToUnblockRestrictions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_toggleAutotranslation::channels_toggleAutotranslation(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_toggleAutotranslation::ID;

void channels_toggleAutotranslation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(377471137);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleAutotranslation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(377471137);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleAutotranslation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleAutotranslation");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_toggleAutotranslation::ReturnType channels_toggleAutotranslation::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_toggleParticipantsHidden::channels_toggleParticipantsHidden(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_toggleParticipantsHidden::ID;

void channels_toggleParticipantsHidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1785624660);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleParticipantsHidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1785624660);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleParticipantsHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleParticipantsHidden");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_toggleParticipantsHidden::ReturnType channels_toggleParticipantsHidden::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_toggleSignatures::channels_toggleSignatures(int32 flags_, bool signatures_enabled_, bool profiles_enabled_, object_ptr<InputChannel> &&channel_)
  : flags_(flags_)
  , signatures_enabled_(signatures_enabled_)
  , profiles_enabled_(profiles_enabled_)
  , channel_(std::move(channel_))
{}

const std::int32_t channels_toggleSignatures::ID;

void channels_toggleSignatures::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1099781276);
  TlStoreBinary::store((var0 = flags_ | (signatures_enabled_ << 0) | (profiles_enabled_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_toggleSignatures::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1099781276);
  TlStoreBinary::store((var0 = flags_ | (signatures_enabled_ << 0) | (profiles_enabled_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_toggleSignatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleSignatures");
    s.store_field("flags", (var0 = flags_ | (signatures_enabled_ << 0) | (profiles_enabled_ << 1)));
    if (var0 & 1) { s.store_field("signatures_enabled", true); }
    if (var0 & 2) { s.store_field("profiles_enabled", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_toggleSignatures::ReturnType channels_toggleSignatures::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t contacts_getBirthdays::ID;

void contacts_getBirthdays::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-621959068);
}

void contacts_getBirthdays::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-621959068);
}

void contacts_getBirthdays::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getBirthdays");
    s.store_class_end();
  }
}

contacts_getBirthdays::ReturnType contacts_getBirthdays::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<contacts_contactBirthdays>, 290452237>::parse(p);
#undef FAIL
}

const std::int32_t contacts_getSaved::ID;

void contacts_getSaved::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2098076769);
}

void contacts_getSaved::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2098076769);
}

void contacts_getSaved::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getSaved");
    s.store_class_end();
  }
}

contacts_getSaved::ReturnType contacts_getSaved::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<savedPhoneContact>, 289586518>>, 481674261>::parse(p);
#undef FAIL
}

folders_editPeerFolders::folders_editPeerFolders(array<object_ptr<inputFolderPeer>> &&folder_peers_)
  : folder_peers_(std::move(folder_peers_))
{}

const std::int32_t folders_editPeerFolders::ID;

void folders_editPeerFolders::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1749536939);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -70073706>>, 481674261>::store(folder_peers_, s);
}

void folders_editPeerFolders::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1749536939);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -70073706>>, 481674261>::store(folder_peers_, s);
}

void folders_editPeerFolders::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "folders.editPeerFolders");
    { s.store_vector_begin("folder_peers", folder_peers_.size()); for (const auto &_value : folder_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

folders_editPeerFolders::ReturnType folders_editPeerFolders::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

help_editUserInfo::help_editUserInfo(object_ptr<InputUser> &&user_id_, string const &message_, array<object_ptr<MessageEntity>> &&entities_)
  : user_id_(std::move(user_id_))
  , message_(message_)
  , entities_(std::move(entities_))
{}

const std::int32_t help_editUserInfo::ID;

void help_editUserInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1723407216);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(message_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s);
}

void help_editUserInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1723407216);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(message_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s);
}

void help_editUserInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.editUserInfo");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("message", message_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

help_editUserInfo::ReturnType help_editUserInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_UserInfo>::parse(p);
#undef FAIL
}

help_getDeepLinkInfo::help_getDeepLinkInfo(string const &path_)
  : path_(path_)
{}

const std::int32_t help_getDeepLinkInfo::ID;

void help_getDeepLinkInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1072547679);
  TlStoreString::store(path_, s);
}

void help_getDeepLinkInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1072547679);
  TlStoreString::store(path_, s);
}

void help_getDeepLinkInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getDeepLinkInfo");
    s.store_field("path", path_);
    s.store_class_end();
  }
}

help_getDeepLinkInfo::ReturnType help_getDeepLinkInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_DeepLinkInfo>::parse(p);
#undef FAIL
}

help_getPassportConfig::help_getPassportConfig(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t help_getPassportConfig::ID;

void help_getPassportConfig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-966677240);
  TlStoreBinary::store(hash_, s);
}

void help_getPassportConfig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-966677240);
  TlStoreBinary::store(hash_, s);
}

void help_getPassportConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getPassportConfig");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

help_getPassportConfig::ReturnType help_getPassportConfig::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_PassportConfig>::parse(p);
#undef FAIL
}

const std::int32_t help_getTermsOfServiceUpdate::ID;

void help_getTermsOfServiceUpdate::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(749019089);
}

void help_getTermsOfServiceUpdate::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(749019089);
}

void help_getTermsOfServiceUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getTermsOfServiceUpdate");
    s.store_class_end();
  }
}

help_getTermsOfServiceUpdate::ReturnType help_getTermsOfServiceUpdate::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_TermsOfServiceUpdate>::parse(p);
#undef FAIL
}

messages_deleteFactCheck::messages_deleteFactCheck(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t messages_deleteFactCheck::ID;

void messages_deleteFactCheck::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-774204404);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_deleteFactCheck::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-774204404);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_deleteFactCheck::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteFactCheck");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

messages_deleteFactCheck::ReturnType messages_deleteFactCheck::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editChatParticipantRank::messages_editChatParticipantRank(object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&participant_, string const &rank_)
  : peer_(std::move(peer_))
  , participant_(std::move(participant_))
  , rank_(rank_)
{}

const std::int32_t messages_editChatParticipantRank::ID;

void messages_editChatParticipantRank::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1609616720);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  TlStoreString::store(rank_, s);
}

void messages_editChatParticipantRank::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1609616720);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  TlStoreString::store(rank_, s);
}

void messages_editChatParticipantRank::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatParticipantRank");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_field("rank", rank_);
    s.store_class_end();
  }
}

messages_editChatParticipantRank::ReturnType messages_editChatParticipantRank::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editChatPhoto::messages_editChatPhoto(int64 chat_id_, object_ptr<InputChatPhoto> &&photo_)
  : chat_id_(chat_id_)
  , photo_(std::move(photo_))
{}

const std::int32_t messages_editChatPhoto::ID;

void messages_editChatPhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(903730804);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
}

void messages_editChatPhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(903730804);
  TlStoreBinary::store(chat_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
}

void messages_editChatPhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatPhoto");
    s.store_field("chat_id", chat_id_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_class_end();
  }
}

messages_editChatPhoto::ReturnType messages_editChatPhoto::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getAdminsWithInvites::messages_getAdminsWithInvites(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_getAdminsWithInvites::ID;

void messages_getAdminsWithInvites::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(958457583);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getAdminsWithInvites::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(958457583);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_getAdminsWithInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAdminsWithInvites");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_getAdminsWithInvites::ReturnType messages_getAdminsWithInvites::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_chatAdminsWithInvites>, -1231326505>::parse(p);
#undef FAIL
}

messages_getCustomEmojiDocuments::messages_getCustomEmojiDocuments(array<int64> &&document_id_)
  : document_id_(std::move(document_id_))
{}

const std::int32_t messages_getCustomEmojiDocuments::ID;

void messages_getCustomEmojiDocuments::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-643100844);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(document_id_, s);
}

void messages_getCustomEmojiDocuments::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-643100844);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(document_id_, s);
}

void messages_getCustomEmojiDocuments::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getCustomEmojiDocuments");
    { s.store_vector_begin("document_id", document_id_.size()); for (const auto &_value : document_id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getCustomEmojiDocuments::ReturnType messages_getCustomEmojiDocuments::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p);
#undef FAIL
}

messages_getEmojiKeywords::messages_getEmojiKeywords(string const &lang_code_)
  : lang_code_(lang_code_)
{}

const std::int32_t messages_getEmojiKeywords::ID;

void messages_getEmojiKeywords::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(899735650);
  TlStoreString::store(lang_code_, s);
}

void messages_getEmojiKeywords::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(899735650);
  TlStoreString::store(lang_code_, s);
}

void messages_getEmojiKeywords::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiKeywords");
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

messages_getEmojiKeywords::ReturnType messages_getEmojiKeywords::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<emojiKeywordsDifference>, 1556570557>::parse(p);
#undef FAIL
}

messages_getEmojiKeywordsDifference::messages_getEmojiKeywordsDifference(string const &lang_code_, int32 from_version_)
  : lang_code_(lang_code_)
  , from_version_(from_version_)
{}

const std::int32_t messages_getEmojiKeywordsDifference::ID;

void messages_getEmojiKeywordsDifference::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(352892591);
  TlStoreString::store(lang_code_, s);
  TlStoreBinary::store(from_version_, s);
}

void messages_getEmojiKeywordsDifference::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(352892591);
  TlStoreString::store(lang_code_, s);
  TlStoreBinary::store(from_version_, s);
}

void messages_getEmojiKeywordsDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiKeywordsDifference");
    s.store_field("lang_code", lang_code_);
    s.store_field("from_version", from_version_);
    s.store_class_end();
  }
}

messages_getEmojiKeywordsDifference::ReturnType messages_getEmojiKeywordsDifference::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<emojiKeywordsDifference>, 1556570557>::parse(p);
#undef FAIL
}

messages_getEmojiProfilePhotoGroups::messages_getEmojiProfilePhotoGroups(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getEmojiProfilePhotoGroups::ID;

void messages_getEmojiProfilePhotoGroups::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(564480243);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiProfilePhotoGroups::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(564480243);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiProfilePhotoGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiProfilePhotoGroups");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getEmojiProfilePhotoGroups::ReturnType messages_getEmojiProfilePhotoGroups::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_EmojiGroups>::parse(p);
#undef FAIL
}

messages_getExportedChatInvite::messages_getExportedChatInvite(object_ptr<InputPeer> &&peer_, string const &link_)
  : peer_(std::move(peer_))
  , link_(link_)
{}

const std::int32_t messages_getExportedChatInvite::ID;

void messages_getExportedChatInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1937010524);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
}

void messages_getExportedChatInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1937010524);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
}

void messages_getExportedChatInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getExportedChatInvite");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("link", link_);
    s.store_class_end();
  }
}

messages_getExportedChatInvite::ReturnType messages_getExportedChatInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_ExportedChatInvite>::parse(p);
#undef FAIL
}

messages_getMessageReactionsList::messages_getMessageReactionsList(int32 flags_, object_ptr<InputPeer> &&peer_, int32 id_, object_ptr<Reaction> &&reaction_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(id_)
  , reaction_(std::move(reaction_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t messages_getMessageReactionsList::ID;

void messages_getMessageReactionsList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1176190792);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s); }
  if (var0 & 2) { TlStoreString::store(offset_, s); }
  TlStoreBinary::store(limit_, s);
}

void messages_getMessageReactionsList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1176190792);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s); }
  if (var0 & 2) { TlStoreString::store(offset_, s); }
  TlStoreBinary::store(limit_, s);
}

void messages_getMessageReactionsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMessageReactionsList");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get())); }
    if (var0 & 2) { s.store_field("offset", offset_); }
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getMessageReactionsList::ReturnType messages_getMessageReactionsList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_messageReactionsList>, 834488621>::parse(p);
#undef FAIL
}

messages_getOldFeaturedStickers::messages_getOldFeaturedStickers(int32 offset_, int32 limit_, int64 hash_)
  : offset_(offset_)
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_getOldFeaturedStickers::ID;

void messages_getOldFeaturedStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2127598753);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getOldFeaturedStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2127598753);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getOldFeaturedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getOldFeaturedStickers");
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getOldFeaturedStickers::ReturnType messages_getOldFeaturedStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_FeaturedStickers>::parse(p);
#undef FAIL
}

messages_getPinnedDialogs::messages_getPinnedDialogs(int32 folder_id_)
  : folder_id_(folder_id_)
{}

const std::int32_t messages_getPinnedDialogs::ID;

void messages_getPinnedDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-692498958);
  TlStoreBinary::store(folder_id_, s);
}

void messages_getPinnedDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-692498958);
  TlStoreBinary::store(folder_id_, s);
}

void messages_getPinnedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getPinnedDialogs");
    s.store_field("folder_id", folder_id_);
    s.store_class_end();
  }
}

messages_getPinnedDialogs::ReturnType messages_getPinnedDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_peerDialogs>, 863093588>::parse(p);
#undef FAIL
}

messages_getSavedGifs::messages_getSavedGifs(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getSavedGifs::ID;

void messages_getSavedGifs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1559270965);
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedGifs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1559270965);
  TlStoreBinary::store(hash_, s);
}

void messages_getSavedGifs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSavedGifs");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getSavedGifs::ReturnType messages_getSavedGifs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_SavedGifs>::parse(p);
#undef FAIL
}

messages_getSearchResultsPositions::messages_getSearchResultsPositions(int32 flags_, object_ptr<InputPeer> &&peer_, object_ptr<InputPeer> &&saved_peer_id_, object_ptr<MessagesFilter> &&filter_, int32 offset_id_, int32 limit_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , saved_peer_id_(std::move(saved_peer_id_))
  , filter_(std::move(filter_))
  , offset_id_(offset_id_)
  , limit_(limit_)
{}

const std::int32_t messages_getSearchResultsPositions::ID;

void messages_getSearchResultsPositions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1669386480);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getSearchResultsPositions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1669386480);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getSearchResultsPositions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getSearchResultsPositions");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 4) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getSearchResultsPositions::ReturnType messages_getSearchResultsPositions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_searchResultsPositions>, 1404185519>::parse(p);
#undef FAIL
}

messages_getWebPage::messages_getWebPage(string const &url_, int32 hash_)
  : url_(url_)
  , hash_(hash_)
{}

const std::int32_t messages_getWebPage::ID;

void messages_getWebPage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1919511901);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getWebPage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1919511901);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getWebPage");
    s.store_field("url", url_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getWebPage::ReturnType messages_getWebPage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_webPage>, -44166467>::parse(p);
#undef FAIL
}

messages_readDiscussion::messages_readDiscussion(object_ptr<InputPeer> &&peer_, int32 msg_id_, int32 read_max_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , read_max_id_(read_max_id_)
{}

const std::int32_t messages_readDiscussion::ID;

void messages_readDiscussion::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-147740172);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(read_max_id_, s);
}

void messages_readDiscussion::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-147740172);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(read_max_id_, s);
}

void messages_readDiscussion::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readDiscussion");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_field("read_max_id", read_max_id_);
    s.store_class_end();
  }
}

messages_readDiscussion::ReturnType messages_readDiscussion::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_readMentions::messages_readMentions(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
{}

const std::int32_t messages_readMentions::ID;

void messages_readMentions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(921026381);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
}

void messages_readMentions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(921026381);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
}

void messages_readMentions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readMentions");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_class_end();
  }
}

messages_readMentions::ReturnType messages_readMentions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_readPollVotes::messages_readPollVotes(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
{}

const std::int32_t messages_readPollVotes::ID;

void messages_readPollVotes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(388019416);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
}

void messages_readPollVotes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(388019416);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
}

void messages_readPollVotes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readPollVotes");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_class_end();
  }
}

messages_readPollVotes::ReturnType messages_readPollVotes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_reorderPinnedForumTopics::messages_reorderPinnedForumTopics(int32 flags_, bool force_, object_ptr<InputPeer> &&peer_, array<int32> &&order_)
  : flags_(flags_)
  , force_(force_)
  , peer_(std::move(peer_))
  , order_(std::move(order_))
{}

const std::int32_t messages_reorderPinnedForumTopics::ID;

void messages_reorderPinnedForumTopics::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(242762224);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_reorderPinnedForumTopics::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(242762224);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_reorderPinnedForumTopics::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reorderPinnedForumTopics");
    s.store_field("flags", (var0 = flags_ | (force_ << 0)));
    if (var0 & 1) { s.store_field("force", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reorderPinnedForumTopics::ReturnType messages_reorderPinnedForumTopics::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_reorderPinnedSavedDialogs::messages_reorderPinnedSavedDialogs(int32 flags_, bool force_, array<object_ptr<InputDialogPeer>> &&order_)
  : flags_(flags_)
  , force_(force_)
  , order_(std::move(order_))
{}

const std::int32_t messages_reorderPinnedSavedDialogs::ID;

void messages_reorderPinnedSavedDialogs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1955502713);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s);
}

void messages_reorderPinnedSavedDialogs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1955502713);
  TlStoreBinary::store((var0 = flags_ | (force_ << 0)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(order_, s);
}

void messages_reorderPinnedSavedDialogs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reorderPinnedSavedDialogs");
    s.store_field("flags", (var0 = flags_ | (force_ << 0)));
    if (var0 & 1) { s.store_field("force", true); }
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reorderPinnedSavedDialogs::ReturnType messages_reorderPinnedSavedDialogs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_sendMultiMedia::messages_sendMultiMedia(int32 flags_, bool silent_, bool background_, bool clear_draft_, bool noforwards_, bool update_stickersets_order_, bool invert_media_, bool allow_paid_floodskip_, object_ptr<InputPeer> &&peer_, object_ptr<InputReplyTo> &&reply_to_, array<object_ptr<inputSingleMedia>> &&multi_media_, int32 schedule_date_, object_ptr<InputPeer> &&send_as_, object_ptr<InputQuickReplyShortcut> &&quick_reply_shortcut_, int64 effect_, int64 allow_paid_stars_)
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
  , multi_media_(std::move(multi_media_))
  , schedule_date_(schedule_date_)
  , send_as_(std::move(send_as_))
  , quick_reply_shortcut_(std::move(quick_reply_shortcut_))
  , effect_(effect_)
  , allow_paid_stars_(allow_paid_stars_)
{}

const std::int32_t messages_sendMultiMedia::ID;

void messages_sendMultiMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(469278068);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 482797855>>, 481674261>::store(multi_media_, s);
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void messages_sendMultiMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(469278068);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (clear_draft_ << 7) | (noforwards_ << 14) | (update_stickersets_order_ << 15) | (invert_media_ << 16) | (allow_paid_floodskip_ << 19)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 482797855>>, 481674261>::store(multi_media_, s);
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
}

void messages_sendMultiMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendMultiMedia");
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
    { s.store_vector_begin("multi_media", multi_media_.size()); for (const auto &_value : multi_media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1024) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    if (var0 & 131072) { s.store_object_field("quick_reply_shortcut", static_cast<const BaseObject *>(quick_reply_shortcut_.get())); }
    if (var0 & 262144) { s.store_field("effect", effect_); }
    if (var0 & 2097152) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    s.store_class_end();
  }
}

messages_sendMultiMedia::ReturnType messages_sendMultiMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_setBotPrecheckoutResults::messages_setBotPrecheckoutResults(int32 flags_, bool success_, int64 query_id_, string const &error_)
  : flags_(flags_)
  , success_(success_)
  , query_id_(query_id_)
  , error_(error_)
{}

const std::int32_t messages_setBotPrecheckoutResults::ID;

void messages_setBotPrecheckoutResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(163765653);
  TlStoreBinary::store((var0 = flags_ | (success_ << 1)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(error_, s); }
}

void messages_setBotPrecheckoutResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(163765653);
  TlStoreBinary::store((var0 = flags_ | (success_ << 1)), s);
  TlStoreBinary::store(query_id_, s);
  if (var0 & 1) { TlStoreString::store(error_, s); }
}

void messages_setBotPrecheckoutResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setBotPrecheckoutResults");
    s.store_field("flags", (var0 = flags_ | (success_ << 1)));
    if (var0 & 2) { s.store_field("success", true); }
    s.store_field("query_id", query_id_);
    if (var0 & 1) { s.store_field("error", error_); }
    s.store_class_end();
  }
}

messages_setBotPrecheckoutResults::ReturnType messages_setBotPrecheckoutResults::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_setDefaultHistoryTTL::messages_setDefaultHistoryTTL(int32 period_)
  : period_(period_)
{}

const std::int32_t messages_setDefaultHistoryTTL::ID;

void messages_setDefaultHistoryTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1632299963);
  TlStoreBinary::store(period_, s);
}

void messages_setDefaultHistoryTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1632299963);
  TlStoreBinary::store(period_, s);
}

void messages_setDefaultHistoryTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.setDefaultHistoryTTL");
    s.store_field("period", period_);
    s.store_class_end();
  }
}

messages_setDefaultHistoryTTL::ReturnType messages_setDefaultHistoryTTL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_toggleSuggestedPostApproval::messages_toggleSuggestedPostApproval(int32 flags_, bool reject_, object_ptr<InputPeer> &&peer_, int32 msg_id_, int32 schedule_date_, string const &reject_comment_)
  : flags_(flags_)
  , reject_(reject_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , schedule_date_(schedule_date_)
  , reject_comment_(reject_comment_)
{}

const std::int32_t messages_toggleSuggestedPostApproval::ID;

void messages_toggleSuggestedPostApproval::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2130229924);
  TlStoreBinary::store((var0 = flags_ | (reject_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  if (var0 & 1) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 4) { TlStoreString::store(reject_comment_, s); }
}

void messages_toggleSuggestedPostApproval::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2130229924);
  TlStoreBinary::store((var0 = flags_ | (reject_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  if (var0 & 1) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 4) { TlStoreString::store(reject_comment_, s); }
}

void messages_toggleSuggestedPostApproval::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleSuggestedPostApproval");
    s.store_field("flags", (var0 = flags_ | (reject_ << 1)));
    if (var0 & 2) { s.store_field("reject", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    if (var0 & 1) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 4) { s.store_field("reject_comment", reject_comment_); }
    s.store_class_end();
  }
}

messages_toggleSuggestedPostApproval::ReturnType messages_toggleSuggestedPostApproval::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_uploadEncryptedFile::messages_uploadEncryptedFile(object_ptr<inputEncryptedChat> &&peer_, object_ptr<InputEncryptedFile> &&file_)
  : peer_(std::move(peer_))
  , file_(std::move(file_))
{}

const std::int32_t messages_uploadEncryptedFile::ID;

void messages_uploadEncryptedFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1347929239);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void messages_uploadEncryptedFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1347929239);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void messages_uploadEncryptedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.uploadEncryptedFile");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

messages_uploadEncryptedFile::ReturnType messages_uploadEncryptedFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EncryptedFile>::parse(p);
#undef FAIL
}

payments_editConnectedStarRefBot::payments_editConnectedStarRefBot(int32 flags_, bool revoked_, object_ptr<InputPeer> &&peer_, string const &link_)
  : flags_(flags_)
  , revoked_(revoked_)
  , peer_(std::move(peer_))
  , link_(link_)
{}

const std::int32_t payments_editConnectedStarRefBot::ID;

void payments_editConnectedStarRefBot::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-453204829);
  TlStoreBinary::store((var0 = flags_ | (revoked_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
}

void payments_editConnectedStarRefBot::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-453204829);
  TlStoreBinary::store((var0 = flags_ | (revoked_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(link_, s);
}

void payments_editConnectedStarRefBot::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.editConnectedStarRefBot");
    s.store_field("flags", (var0 = flags_ | (revoked_ << 0)));
    if (var0 & 1) { s.store_field("revoked", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("link", link_);
    s.store_class_end();
  }
}

payments_editConnectedStarRefBot::ReturnType payments_editConnectedStarRefBot::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_connectedStarRefBots>, -1730811363>::parse(p);
#undef FAIL
}

payments_getStarGiftAuctionAcquiredGifts::payments_getStarGiftAuctionAcquiredGifts(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t payments_getStarGiftAuctionAcquiredGifts::ID;

void payments_getStarGiftAuctionAcquiredGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1805831148);
  TlStoreBinary::store(gift_id_, s);
}

void payments_getStarGiftAuctionAcquiredGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1805831148);
  TlStoreBinary::store(gift_id_, s);
}

void payments_getStarGiftAuctionAcquiredGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftAuctionAcquiredGifts");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

payments_getStarGiftAuctionAcquiredGifts::ReturnType payments_getStarGiftAuctionAcquiredGifts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftAuctionAcquiredGifts>, 2103169520>::parse(p);
#undef FAIL
}

payments_getStarsRevenueStats::payments_getStarsRevenueStats(int32 flags_, bool dark_, bool ton_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , dark_(dark_)
  , ton_(ton_)
  , peer_(std::move(peer_))
{}

const std::int32_t payments_getStarsRevenueStats::ID;

void payments_getStarsRevenueStats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-652215594);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0) | (ton_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_getStarsRevenueStats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-652215594);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0) | (ton_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_getStarsRevenueStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsRevenueStats");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0) | (ton_ << 1)));
    if (var0 & 1) { s.store_field("dark", true); }
    if (var0 & 2) { s.store_field("ton", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

payments_getStarsRevenueStats::ReturnType payments_getStarsRevenueStats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsRevenueStats>, 1814066038>::parse(p);
#undef FAIL
}

payments_getStarsStatus::payments_getStarsStatus(int32 flags_, bool ton_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , ton_(ton_)
  , peer_(std::move(peer_))
{}

const std::int32_t payments_getStarsStatus::ID;

void payments_getStarsStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1319744447);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_getStarsStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1319744447);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_getStarsStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsStatus");
    s.store_field("flags", (var0 = flags_ | (ton_ << 0)));
    if (var0 & 1) { s.store_field("ton", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

payments_getStarsStatus::ReturnType payments_getStarsStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsStatus>, 1822222573>::parse(p);
#undef FAIL
}

payments_refundStarsCharge::payments_refundStarsCharge(object_ptr<InputUser> &&user_id_, string const &charge_id_)
  : user_id_(std::move(user_id_))
  , charge_id_(charge_id_)
{}

const std::int32_t payments_refundStarsCharge::ID;

void payments_refundStarsCharge::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(632196938);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(charge_id_, s);
}

void payments_refundStarsCharge::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(632196938);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreString::store(charge_id_, s);
}

void payments_refundStarsCharge::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.refundStarsCharge");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("charge_id", charge_id_);
    s.store_class_end();
  }
}

payments_refundStarsCharge::ReturnType payments_refundStarsCharge::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

payments_toggleChatStarGiftNotifications::payments_toggleChatStarGiftNotifications(int32 flags_, bool enabled_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , enabled_(enabled_)
  , peer_(std::move(peer_))
{}

const std::int32_t payments_toggleChatStarGiftNotifications::ID;

void payments_toggleChatStarGiftNotifications::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1626009505);
  TlStoreBinary::store((var0 = flags_ | (enabled_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_toggleChatStarGiftNotifications::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1626009505);
  TlStoreBinary::store((var0 = flags_ | (enabled_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void payments_toggleChatStarGiftNotifications::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.toggleChatStarGiftNotifications");
    s.store_field("flags", (var0 = flags_ | (enabled_ << 0)));
    if (var0 & 1) { s.store_field("enabled", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

payments_toggleChatStarGiftNotifications::ReturnType payments_toggleChatStarGiftNotifications::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_toggleStarGiftsPinnedToTop::payments_toggleStarGiftsPinnedToTop(object_ptr<InputPeer> &&peer_, array<object_ptr<InputSavedStarGift>> &&stargift_)
  : peer_(std::move(peer_))
  , stargift_(std::move(stargift_))
{}

const std::int32_t payments_toggleStarGiftsPinnedToTop::ID;

void payments_toggleStarGiftsPinnedToTop::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(353626032);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_toggleStarGiftsPinnedToTop::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(353626032);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stargift_, s);
}

void payments_toggleStarGiftsPinnedToTop::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.toggleStarGiftsPinnedToTop");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("stargift", stargift_.size()); for (const auto &_value : stargift_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_toggleStarGiftsPinnedToTop::ReturnType payments_toggleStarGiftsPinnedToTop::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_acceptCall::phone_acceptCall(object_ptr<inputPhoneCall> &&peer_, bytes &&g_b_, object_ptr<phoneCallProtocol> &&protocol_)
  : peer_(std::move(peer_))
  , g_b_(std::move(g_b_))
  , protocol_(std::move(protocol_))
{}

const std::int32_t phone_acceptCall::ID;

void phone_acceptCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1003664544);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreString::store(g_b_, s);
  TlStoreBoxed<TlStoreObject, -58224696>::store(protocol_, s);
}

void phone_acceptCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1003664544);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreString::store(g_b_, s);
  TlStoreBoxed<TlStoreObject, -58224696>::store(protocol_, s);
}

void phone_acceptCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.acceptCall");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_bytes_field("g_b", g_b_);
    s.store_object_field("protocol", static_cast<const BaseObject *>(protocol_.get()));
    s.store_class_end();
  }
}

phone_acceptCall::ReturnType phone_acceptCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<phone_phoneCall>, -326966976>::parse(p);
#undef FAIL
}

phone_deleteGroupCallParticipantMessages::phone_deleteGroupCallParticipantMessages(int32 flags_, bool report_spam_, object_ptr<InputGroupCall> &&call_, object_ptr<InputPeer> &&participant_)
  : flags_(flags_)
  , report_spam_(report_spam_)
  , call_(std::move(call_))
  , participant_(std::move(participant_))
{}

const std::int32_t phone_deleteGroupCallParticipantMessages::ID;

void phone_deleteGroupCallParticipantMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(499117216);
  TlStoreBinary::store((var0 = flags_ | (report_spam_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void phone_deleteGroupCallParticipantMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(499117216);
  TlStoreBinary::store((var0 = flags_ | (report_spam_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
}

void phone_deleteGroupCallParticipantMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.deleteGroupCallParticipantMessages");
    s.store_field("flags", (var0 = flags_ | (report_spam_ << 0)));
    if (var0 & 1) { s.store_field("report_spam", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

phone_deleteGroupCallParticipantMessages::ReturnType phone_deleteGroupCallParticipantMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_joinGroupCall::phone_joinGroupCall(int32 flags_, bool muted_, bool video_stopped_, object_ptr<InputGroupCall> &&call_, object_ptr<InputPeer> &&join_as_, string const &invite_hash_, UInt256 const &public_key_, bytes &&block_, object_ptr<dataJSON> &&params_)
  : flags_(flags_)
  , muted_(muted_)
  , video_stopped_(video_stopped_)
  , call_(std::move(call_))
  , join_as_(std::move(join_as_))
  , invite_hash_(invite_hash_)
  , public_key_(public_key_)
  , block_(std::move(block_))
  , params_(std::move(params_))
{}

const std::int32_t phone_joinGroupCall::ID;

void phone_joinGroupCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1883951017);
  TlStoreBinary::store((var0 = flags_ | (muted_ << 0) | (video_stopped_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(join_as_, s);
  if (var0 & 2) { TlStoreString::store(invite_hash_, s); }
  if (var0 & 8) { TlStoreBinary::store(public_key_, s); }
  if (var0 & 8) { TlStoreString::store(block_, s); }
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void phone_joinGroupCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1883951017);
  TlStoreBinary::store((var0 = flags_ | (muted_ << 0) | (video_stopped_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(join_as_, s);
  if (var0 & 2) { TlStoreString::store(invite_hash_, s); }
  if (var0 & 8) { TlStoreBinary::store(public_key_, s); }
  if (var0 & 8) { TlStoreString::store(block_, s); }
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void phone_joinGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.joinGroupCall");
    s.store_field("flags", (var0 = flags_ | (muted_ << 0) | (video_stopped_ << 2)));
    if (var0 & 1) { s.store_field("muted", true); }
    if (var0 & 4) { s.store_field("video_stopped", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_object_field("join_as", static_cast<const BaseObject *>(join_as_.get()));
    if (var0 & 2) { s.store_field("invite_hash", invite_hash_); }
    if (var0 & 8) { s.store_field("public_key", public_key_); }
    if (var0 & 8) { s.store_bytes_field("block", block_); }
    s.store_object_field("params", static_cast<const BaseObject *>(params_.get()));
    s.store_class_end();
  }
}

phone_joinGroupCall::ReturnType phone_joinGroupCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_saveCallLog::phone_saveCallLog(object_ptr<inputPhoneCall> &&peer_, object_ptr<InputFile> &&file_)
  : peer_(std::move(peer_))
  , file_(std::move(file_))
{}

const std::int32_t phone_saveCallLog::ID;

void phone_saveCallLog::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1092913030);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void phone_saveCallLog::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1092913030);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
}

void phone_saveCallLog::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.saveCallLog");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_class_end();
  }
}

phone_saveCallLog::ReturnType phone_saveCallLog::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

photos_updateProfilePhoto::photos_updateProfilePhoto(int32 flags_, bool fallback_, object_ptr<InputUser> &&bot_, object_ptr<InputPhoto> &&id_)
  : flags_(flags_)
  , fallback_(fallback_)
  , bot_(std::move(bot_))
  , id_(std::move(id_))
{}

const std::int32_t photos_updateProfilePhoto::ID;

void photos_updateProfilePhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(166207545);
  TlStoreBinary::store((var0 = flags_ | (fallback_ << 0)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void photos_updateProfilePhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(166207545);
  TlStoreBinary::store((var0 = flags_ | (fallback_ << 0)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void photos_updateProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photos.updateProfilePhoto");
    s.store_field("flags", (var0 = flags_ | (fallback_ << 0)));
    if (var0 & 1) { s.store_field("fallback", true); }
    if (var0 & 2) { s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get())); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

photos_updateProfilePhoto::ReturnType photos_updateProfilePhoto::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<photos_photo>, 539045032>::parse(p);
#undef FAIL
}

const std::int32_t smsjobs_getStatus::ID;

void smsjobs_getStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(279353576);
}

void smsjobs_getStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(279353576);
}

void smsjobs_getStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "smsjobs.getStatus");
    s.store_class_end();
  }
}

smsjobs_getStatus::ReturnType smsjobs_getStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<smsjobs_status>, 720277905>::parse(p);
#undef FAIL
}

stats_getStoryStats::stats_getStoryStats(int32 flags_, bool dark_, object_ptr<InputPeer> &&peer_, int32 id_)
  : flags_(flags_)
  , dark_(dark_)
  , peer_(std::move(peer_))
  , id_(id_)
{}

const std::int32_t stats_getStoryStats::ID;

void stats_getStoryStats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(927985472);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void stats_getStoryStats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(927985472);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
}

void stats_getStoryStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getStoryStats");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0)));
    if (var0 & 1) { s.store_field("dark", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_class_end();
  }
}

stats_getStoryStats::ReturnType stats_getStoryStats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_storyStats>, 1355613820>::parse(p);
#undef FAIL
}

stickers_renameStickerSet::stickers_renameStickerSet(object_ptr<InputStickerSet> &&stickerset_, string const &title_)
  : stickerset_(std::move(stickerset_))
  , title_(title_)
{}

const std::int32_t stickers_renameStickerSet::ID;

void stickers_renameStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(306912256);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreString::store(title_, s);
}

void stickers_renameStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(306912256);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreString::store(title_, s);
}

void stickers_renameStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.renameStickerSet");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_field("title", title_);
    s.store_class_end();
  }
}

stickers_renameStickerSet::ReturnType stickers_renameStickerSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stories_canSendStory::stories_canSendStory(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t stories_canSendStory::ID;

void stories_canSendStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(820732912);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void stories_canSendStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(820732912);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void stories_canSendStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.canSendStory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

stories_canSendStory::ReturnType stories_canSendStory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_canSendStoryCount>, -1014513586>::parse(p);
#undef FAIL
}

const std::int32_t stories_getAllReadPeerStories::ID;

void stories_getAllReadPeerStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1688541191);
}

void stories_getAllReadPeerStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1688541191);
}

void stories_getAllReadPeerStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getAllReadPeerStories");
    s.store_class_end();
  }
}

stories_getAllReadPeerStories::ReturnType stories_getAllReadPeerStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

stories_startLive::stories_startLive(int32 flags_, bool pinned_, bool noforwards_, bool rtmp_stream_, object_ptr<InputPeer> &&peer_, string const &caption_, array<object_ptr<MessageEntity>> &&entities_, array<object_ptr<InputPrivacyRule>> &&privacy_rules_, int64 random_id_, bool messages_enabled_, int64 send_paid_messages_stars_)
  : flags_(flags_)
  , pinned_(pinned_)
  , noforwards_(noforwards_)
  , rtmp_stream_(rtmp_stream_)
  , peer_(std::move(peer_))
  , caption_(caption_)
  , entities_(std::move(entities_))
  , privacy_rules_(std::move(privacy_rules_))
  , random_id_(random_id_)
  , messages_enabled_(messages_enabled_)
  , send_paid_messages_stars_(send_paid_messages_stars_)
{}

const std::int32_t stories_startLive::ID;

void stories_startLive::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-798372642);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 2) | (noforwards_ << 4) | (rtmp_stream_ << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_rules_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 64) { TlStoreBool::store(messages_enabled_, s); }
  if (var0 & 128) { TlStoreBinary::store(send_paid_messages_stars_, s); }
}

void stories_startLive::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-798372642);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 2) | (noforwards_ << 4) | (rtmp_stream_ << 5)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_rules_, s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 64) { TlStoreBool::store(messages_enabled_, s); }
  if (var0 & 128) { TlStoreBinary::store(send_paid_messages_stars_, s); }
}

void stories_startLive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.startLive");
    s.store_field("flags", (var0 = flags_ | (pinned_ << 2) | (noforwards_ << 4) | (rtmp_stream_ << 5)));
    if (var0 & 4) { s.store_field("pinned", true); }
    if (var0 & 16) { s.store_field("noforwards", true); }
    if (var0 & 32) { s.store_field("rtmp_stream", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("caption", caption_); }
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("privacy_rules", privacy_rules_.size()); for (const auto &_value : privacy_rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_field("random_id", random_id_);
    if (var0 & 64) { s.store_field("messages_enabled", messages_enabled_); }
    if (var0 & 128) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    s.store_class_end();
  }
}

stories_startLive::ReturnType stories_startLive::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

upload_getCdnFileHashes::upload_getCdnFileHashes(bytes &&file_token_, int64 offset_)
  : file_token_(std::move(file_token_))
  , offset_(offset_)
{}

const std::int32_t upload_getCdnFileHashes::ID;

void upload_getCdnFileHashes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1847836879);
  TlStoreString::store(file_token_, s);
  TlStoreBinary::store(offset_, s);
}

void upload_getCdnFileHashes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1847836879);
  TlStoreString::store(file_token_, s);
  TlStoreBinary::store(offset_, s);
}

void upload_getCdnFileHashes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.getCdnFileHashes");
    s.store_bytes_field("file_token", file_token_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

upload_getCdnFileHashes::ReturnType upload_getCdnFileHashes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<fileHash>, -207944868>>, 481674261>::parse(p);
#undef FAIL
}

upload_getWebFile::upload_getWebFile(object_ptr<InputWebFileLocation> &&location_, int32 offset_, int32 limit_)
  : location_(std::move(location_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t upload_getWebFile::ID;

void upload_getWebFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(619086221);
  TlStoreBoxedUnknown<TlStoreObject>::store(location_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void upload_getWebFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(619086221);
  TlStoreBoxedUnknown<TlStoreObject>::store(location_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void upload_getWebFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.getWebFile");
    s.store_object_field("location", static_cast<const BaseObject *>(location_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

upload_getWebFile::ReturnType upload_getWebFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<upload_webFile>, 568808380>::parse(p);
#undef FAIL
}

upload_reuploadCdnFile::upload_reuploadCdnFile(bytes &&file_token_, bytes &&request_token_)
  : file_token_(std::move(file_token_))
  , request_token_(std::move(request_token_))
{}

const std::int32_t upload_reuploadCdnFile::ID;

void upload_reuploadCdnFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1691921240);
  TlStoreString::store(file_token_, s);
  TlStoreString::store(request_token_, s);
}

void upload_reuploadCdnFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1691921240);
  TlStoreString::store(file_token_, s);
  TlStoreString::store(request_token_, s);
}

void upload_reuploadCdnFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "upload.reuploadCdnFile");
    s.store_bytes_field("file_token", file_token_);
    s.store_bytes_field("request_token", request_token_);
    s.store_class_end();
  }
}

upload_reuploadCdnFile::ReturnType upload_reuploadCdnFile::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<fileHash>, -207944868>>, 481674261>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
