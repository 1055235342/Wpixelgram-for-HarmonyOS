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


const std::int32_t attachMenuBotIconColor::ID;

object_ptr<attachMenuBotIconColor> attachMenuBotIconColor::fetch(TlBufferParser &p) {
  return make_tl_object<attachMenuBotIconColor>(p);
}

attachMenuBotIconColor::attachMenuBotIconColor(TlBufferParser &p)
  : name_(TlFetchString<string>::parse(p))
  , color_(TlFetchInt::parse(p))
{}

void attachMenuBotIconColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "attachMenuBotIconColor");
    s.store_field("name", name_);
    s.store_field("color", color_);
    s.store_class_end();
  }
}

availableEffect::availableEffect()
  : flags_()
  , premium_required_()
  , id_()
  , emoticon_()
  , static_icon_id_()
  , effect_sticker_id_()
  , effect_animation_id_()
{}

const std::int32_t availableEffect::ID;

object_ptr<availableEffect> availableEffect::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<availableEffect> res = make_tl_object<availableEffect>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->premium_required_ = (var0 & 4) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->emoticon_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->static_icon_id_ = TlFetchLong::parse(p); }
  res->effect_sticker_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->effect_animation_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void availableEffect::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "availableEffect");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (premium_required_ << 2)));
    if (var0 & 4) { s.store_field("premium_required", true); }
    s.store_field("id", id_);
    s.store_field("emoticon", emoticon_);
    if (var0 & 1) { s.store_field("static_icon_id", static_icon_id_); }
    s.store_field("effect_sticker_id", effect_sticker_id_);
    if (var0 & 2) { s.store_field("effect_animation_id", effect_animation_id_); }
    s.store_class_end();
  }
}

botBusinessConnection::botBusinessConnection()
  : flags_()
  , disabled_()
  , connection_id_()
  , user_id_()
  , dc_id_()
  , date_()
  , rights_()
{}

const std::int32_t botBusinessConnection::ID;

object_ptr<botBusinessConnection> botBusinessConnection::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<botBusinessConnection> res = make_tl_object<botBusinessConnection>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->disabled_ = (var0 & 2) != 0;
  res->connection_id_ = TlFetchString<string>::parse(p);
  res->user_id_ = TlFetchLong::parse(p);
  res->dc_id_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->rights_ = TlFetchBoxed<TlFetchObject<businessBotRights>, -1604170505>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void botBusinessConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "botBusinessConnection");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (disabled_ << 1)));
    if (var0 & 2) { s.store_field("disabled", true); }
    s.store_field("connection_id", connection_id_);
    s.store_field("user_id", user_id_);
    s.store_field("dc_id", dc_id_);
    s.store_field("date", date_);
    if (var0 & 4) { s.store_object_field("rights", static_cast<const BaseObject *>(rights_.get())); }
    s.store_class_end();
  }
}

object_ptr<BusinessAwayMessageSchedule> BusinessAwayMessageSchedule::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case businessAwayMessageScheduleAlways::ID:
      return businessAwayMessageScheduleAlways::fetch(p);
    case businessAwayMessageScheduleOutsideWorkHours::ID:
      return businessAwayMessageScheduleOutsideWorkHours::fetch(p);
    case businessAwayMessageScheduleCustom::ID:
      return businessAwayMessageScheduleCustom::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t businessAwayMessageScheduleAlways::ID;

object_ptr<BusinessAwayMessageSchedule> businessAwayMessageScheduleAlways::fetch(TlBufferParser &p) {
  return make_tl_object<businessAwayMessageScheduleAlways>();
}

void businessAwayMessageScheduleAlways::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void businessAwayMessageScheduleAlways::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void businessAwayMessageScheduleAlways::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageScheduleAlways");
    s.store_class_end();
  }
}

const std::int32_t businessAwayMessageScheduleOutsideWorkHours::ID;

object_ptr<BusinessAwayMessageSchedule> businessAwayMessageScheduleOutsideWorkHours::fetch(TlBufferParser &p) {
  return make_tl_object<businessAwayMessageScheduleOutsideWorkHours>();
}

void businessAwayMessageScheduleOutsideWorkHours::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void businessAwayMessageScheduleOutsideWorkHours::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void businessAwayMessageScheduleOutsideWorkHours::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageScheduleOutsideWorkHours");
    s.store_class_end();
  }
}

businessAwayMessageScheduleCustom::businessAwayMessageScheduleCustom(int32 start_date_, int32 end_date_)
  : start_date_(start_date_)
  , end_date_(end_date_)
{}

const std::int32_t businessAwayMessageScheduleCustom::ID;

object_ptr<BusinessAwayMessageSchedule> businessAwayMessageScheduleCustom::fetch(TlBufferParser &p) {
  return make_tl_object<businessAwayMessageScheduleCustom>(p);
}

businessAwayMessageScheduleCustom::businessAwayMessageScheduleCustom(TlBufferParser &p)
  : start_date_(TlFetchInt::parse(p))
  , end_date_(TlFetchInt::parse(p))
{}

void businessAwayMessageScheduleCustom::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(start_date_, s);
  TlStoreBinary::store(end_date_, s);
}

void businessAwayMessageScheduleCustom::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(start_date_, s);
  TlStoreBinary::store(end_date_, s);
}

void businessAwayMessageScheduleCustom::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessAwayMessageScheduleCustom");
    s.store_field("start_date", start_date_);
    s.store_field("end_date", end_date_);
    s.store_class_end();
  }
}

businessIntro::businessIntro()
  : flags_()
  , title_()
  , description_()
  , sticker_()
{}

const std::int32_t businessIntro::ID;

object_ptr<businessIntro> businessIntro::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<businessIntro> res = make_tl_object<businessIntro>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->title_ = TlFetchString<string>::parse(p);
  res->description_ = TlFetchString<string>::parse(p);
  if (var0 & 1) { res->sticker_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void businessIntro::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "businessIntro");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 1) { s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get())); }
    s.store_class_end();
  }
}

channelAdminLogEventsFilter::channelAdminLogEventsFilter(int32 flags_, bool join_, bool leave_, bool invite_, bool ban_, bool unban_, bool kick_, bool unkick_, bool promote_, bool demote_, bool info_, bool settings_, bool pinned_, bool edit_, bool delete_, bool group_call_, bool invites_, bool send_, bool forums_, bool sub_extend_, bool edit_rank_)
  : flags_(flags_)
  , join_(join_)
  , leave_(leave_)
  , invite_(invite_)
  , ban_(ban_)
  , unban_(unban_)
  , kick_(kick_)
  , unkick_(unkick_)
  , promote_(promote_)
  , demote_(demote_)
  , info_(info_)
  , settings_(settings_)
  , pinned_(pinned_)
  , edit_(edit_)
  , delete_(delete_)
  , group_call_(group_call_)
  , invites_(invites_)
  , send_(send_)
  , forums_(forums_)
  , sub_extend_(sub_extend_)
  , edit_rank_(edit_rank_)
{}

const std::int32_t channelAdminLogEventsFilter::ID;

void channelAdminLogEventsFilter::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (join_ << 0) | (leave_ << 1) | (invite_ << 2) | (ban_ << 3) | (unban_ << 4) | (kick_ << 5) | (unkick_ << 6) | (promote_ << 7) | (demote_ << 8) | (info_ << 9) | (settings_ << 10) | (pinned_ << 11) | (edit_ << 12) | (delete_ << 13) | (group_call_ << 14) | (invites_ << 15) | (send_ << 16) | (forums_ << 17) | (sub_extend_ << 18) | (edit_rank_ << 19)), s);
}

void channelAdminLogEventsFilter::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (join_ << 0) | (leave_ << 1) | (invite_ << 2) | (ban_ << 3) | (unban_ << 4) | (kick_ << 5) | (unkick_ << 6) | (promote_ << 7) | (demote_ << 8) | (info_ << 9) | (settings_ << 10) | (pinned_ << 11) | (edit_ << 12) | (delete_ << 13) | (group_call_ << 14) | (invites_ << 15) | (send_ << 16) | (forums_ << 17) | (sub_extend_ << 18) | (edit_rank_ << 19)), s);
}

void channelAdminLogEventsFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventsFilter");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (join_ << 0) | (leave_ << 1) | (invite_ << 2) | (ban_ << 3) | (unban_ << 4) | (kick_ << 5) | (unkick_ << 6) | (promote_ << 7) | (demote_ << 8) | (info_ << 9) | (settings_ << 10) | (pinned_ << 11) | (edit_ << 12) | (delete_ << 13) | (group_call_ << 14) | (invites_ << 15) | (send_ << 16) | (forums_ << 17) | (sub_extend_ << 18) | (edit_rank_ << 19)));
    if (var0 & 1) { s.store_field("join", true); }
    if (var0 & 2) { s.store_field("leave", true); }
    if (var0 & 4) { s.store_field("invite", true); }
    if (var0 & 8) { s.store_field("ban", true); }
    if (var0 & 16) { s.store_field("unban", true); }
    if (var0 & 32) { s.store_field("kick", true); }
    if (var0 & 64) { s.store_field("unkick", true); }
    if (var0 & 128) { s.store_field("promote", true); }
    if (var0 & 256) { s.store_field("demote", true); }
    if (var0 & 512) { s.store_field("info", true); }
    if (var0 & 1024) { s.store_field("settings", true); }
    if (var0 & 2048) { s.store_field("pinned", true); }
    if (var0 & 4096) { s.store_field("edit", true); }
    if (var0 & 8192) { s.store_field("delete", true); }
    if (var0 & 16384) { s.store_field("group_call", true); }
    if (var0 & 32768) { s.store_field("invites", true); }
    if (var0 & 65536) { s.store_field("send", true); }
    if (var0 & 131072) { s.store_field("forums", true); }
    if (var0 & 262144) { s.store_field("sub_extend", true); }
    if (var0 & 524288) { s.store_field("edit_rank", true); }
    s.store_class_end();
  }
}

object_ptr<ChannelParticipant> ChannelParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

channelParticipant::channelParticipant()
  : flags_()
  , user_id_()
  , date_()
  , subscription_until_date_()
  , rank_()
{}

const std::int32_t channelParticipant::ID;

object_ptr<ChannelParticipant> channelParticipant::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelParticipant> res = make_tl_object<channelParticipant>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->subscription_until_date_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipant");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("user_id", user_id_);
    s.store_field("date", date_);
    if (var0 & 1) { s.store_field("subscription_until_date", subscription_until_date_); }
    if (var0 & 4) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

channelParticipantSelf::channelParticipantSelf()
  : flags_()
  , via_request_()
  , user_id_()
  , inviter_id_()
  , date_()
  , subscription_until_date_()
  , rank_()
{}

const std::int32_t channelParticipantSelf::ID;

object_ptr<ChannelParticipant> channelParticipantSelf::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelParticipantSelf> res = make_tl_object<channelParticipantSelf>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->via_request_ = (var0 & 1) != 0;
  res->user_id_ = TlFetchLong::parse(p);
  res->inviter_id_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->subscription_until_date_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelParticipantSelf::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantSelf");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (via_request_ << 0)));
    if (var0 & 1) { s.store_field("via_request", true); }
    s.store_field("user_id", user_id_);
    s.store_field("inviter_id", inviter_id_);
    s.store_field("date", date_);
    if (var0 & 2) { s.store_field("subscription_until_date", subscription_until_date_); }
    if (var0 & 4) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

channelParticipantCreator::channelParticipantCreator()
  : flags_()
  , user_id_()
  , admin_rights_()
  , rank_()
{}

const std::int32_t channelParticipantCreator::ID;

object_ptr<ChannelParticipant> channelParticipantCreator::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelParticipantCreator> res = make_tl_object<channelParticipantCreator>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->user_id_ = TlFetchLong::parse(p);
  res->admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p);
  if (var0 & 1) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelParticipantCreator::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantCreator");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("user_id", user_id_);
    s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get()));
    if (var0 & 1) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

channelParticipantAdmin::channelParticipantAdmin()
  : flags_()
  , can_edit_()
  , self_()
  , user_id_()
  , inviter_id_()
  , promoted_by_()
  , date_()
  , admin_rights_()
  , rank_()
{}

const std::int32_t channelParticipantAdmin::ID;

object_ptr<ChannelParticipant> channelParticipantAdmin::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelParticipantAdmin> res = make_tl_object<channelParticipantAdmin>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->can_edit_ = (var0 & 1) != 0;
  res->self_ = (var0 & 2) != 0;
  res->user_id_ = TlFetchLong::parse(p);
  if (var0 & 2) { res->inviter_id_ = TlFetchLong::parse(p); }
  res->promoted_by_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p);
  if (var0 & 4) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelParticipantAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantAdmin");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (can_edit_ << 0) | (self_ << 1)));
    if (var0 & 1) { s.store_field("can_edit", true); }
    if (var0 & 2) { s.store_field("self", true); }
    s.store_field("user_id", user_id_);
    if (var0 & 2) { s.store_field("inviter_id", inviter_id_); }
    s.store_field("promoted_by", promoted_by_);
    s.store_field("date", date_);
    s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get()));
    if (var0 & 4) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

channelParticipantBanned::channelParticipantBanned()
  : flags_()
  , left_()
  , peer_()
  , kicked_by_()
  , date_()
  , banned_rights_()
  , rank_()
{}

const std::int32_t channelParticipantBanned::ID;

object_ptr<ChannelParticipant> channelParticipantBanned::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelParticipantBanned> res = make_tl_object<channelParticipantBanned>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->left_ = (var0 & 1) != 0;
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->kicked_by_ = TlFetchLong::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->banned_rights_ = TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p);
  if (var0 & 4) { res->rank_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelParticipantBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantBanned");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (left_ << 0)));
    if (var0 & 1) { s.store_field("left", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("kicked_by", kicked_by_);
    s.store_field("date", date_);
    s.store_object_field("banned_rights", static_cast<const BaseObject *>(banned_rights_.get()));
    if (var0 & 4) { s.store_field("rank", rank_); }
    s.store_class_end();
  }
}

const std::int32_t channelParticipantLeft::ID;

object_ptr<ChannelParticipant> channelParticipantLeft::fetch(TlBufferParser &p) {
  return make_tl_object<channelParticipantLeft>(p);
}

channelParticipantLeft::channelParticipantLeft(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
{}

void channelParticipantLeft::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelParticipantLeft");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

object_ptr<Chat> Chat::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

chatEmpty::chatEmpty(int64 id_)
  : id_(id_)
{}

const std::int32_t chatEmpty::ID;

object_ptr<Chat> chatEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<chatEmpty>(p);
}

chatEmpty::chatEmpty(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void chatEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void chatEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void chatEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatEmpty");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

chat::chat()
  : flags_()
  , creator_()
  , left_()
  , deactivated_()
  , call_active_()
  , call_not_empty_()
  , noforwards_()
  , id_()
  , title_()
  , photo_()
  , participants_count_()
  , date_()
  , version_()
  , migrated_to_()
  , admin_rights_()
  , default_banned_rights_()
{}

chat::chat(int32 flags_, bool creator_, bool left_, bool deactivated_, bool call_active_, bool call_not_empty_, bool noforwards_, int64 id_, string const &title_, object_ptr<ChatPhoto> &&photo_, int32 participants_count_, int32 date_, int32 version_, object_ptr<InputChannel> &&migrated_to_, object_ptr<chatAdminRights> &&admin_rights_, object_ptr<chatBannedRights> &&default_banned_rights_)
  : flags_(flags_)
  , creator_(creator_)
  , left_(left_)
  , deactivated_(deactivated_)
  , call_active_(call_active_)
  , call_not_empty_(call_not_empty_)
  , noforwards_(noforwards_)
  , id_(id_)
  , title_(title_)
  , photo_(std::move(photo_))
  , participants_count_(participants_count_)
  , date_(date_)
  , version_(version_)
  , migrated_to_(std::move(migrated_to_))
  , admin_rights_(std::move(admin_rights_))
  , default_banned_rights_(std::move(default_banned_rights_))
{}

const std::int32_t chat::ID;

object_ptr<Chat> chat::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chat> res = make_tl_object<chat>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  res->left_ = (var0 & 4) != 0;
  res->deactivated_ = (var0 & 32) != 0;
  res->call_active_ = (var0 & 8388608) != 0;
  res->call_not_empty_ = (var0 & 16777216) != 0;
  res->noforwards_ = (var0 & 33554432) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->photo_ = TlFetchObject<ChatPhoto>::parse(p);
  res->participants_count_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->version_ = TlFetchInt::parse(p);
  if (var0 & 64) { res->migrated_to_ = TlFetchObject<InputChannel>::parse(p); }
  if (var0 & 16384) { res->admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 262144) { res->default_banned_rights_ = TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (left_ << 2) | (deactivated_ << 5) | (call_active_ << 23) | (call_not_empty_ << 24) | (noforwards_ << 25)), s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBinary::store(participants_count_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBinary::store(version_, s);
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(migrated_to_, s); }
  if (var0 & 16384) { TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s); }
  if (var0 & 262144) { TlStoreBoxed<TlStoreObject, -1626209256>::store(default_banned_rights_, s); }
}

void chat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (left_ << 2) | (deactivated_ << 5) | (call_active_ << 23) | (call_not_empty_ << 24) | (noforwards_ << 25)), s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(title_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBinary::store(participants_count_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBinary::store(version_, s);
  if (var0 & 64) { TlStoreBoxedUnknown<TlStoreObject>::store(migrated_to_, s); }
  if (var0 & 16384) { TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s); }
  if (var0 & 262144) { TlStoreBoxed<TlStoreObject, -1626209256>::store(default_banned_rights_, s); }
}

void chat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chat");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | (left_ << 2) | (deactivated_ << 5) | (call_active_ << 23) | (call_not_empty_ << 24) | (noforwards_ << 25)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 4) { s.store_field("left", true); }
    if (var0 & 32) { s.store_field("deactivated", true); }
    if (var0 & 8388608) { s.store_field("call_active", true); }
    if (var0 & 16777216) { s.store_field("call_not_empty", true); }
    if (var0 & 33554432) { s.store_field("noforwards", true); }
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("participants_count", participants_count_);
    s.store_field("date", date_);
    s.store_field("version", version_);
    if (var0 & 64) { s.store_object_field("migrated_to", static_cast<const BaseObject *>(migrated_to_.get())); }
    if (var0 & 16384) { s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get())); }
    if (var0 & 262144) { s.store_object_field("default_banned_rights", static_cast<const BaseObject *>(default_banned_rights_.get())); }
    s.store_class_end();
  }
}

chatForbidden::chatForbidden(int64 id_, string const &title_)
  : id_(id_)
  , title_(title_)
{}

const std::int32_t chatForbidden::ID;

object_ptr<Chat> chatForbidden::fetch(TlBufferParser &p) {
  return make_tl_object<chatForbidden>(p);
}

chatForbidden::chatForbidden(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , title_(TlFetchString<string>::parse(p))
{}

void chatForbidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(title_, s);
}

void chatForbidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(title_, s);
}

void chatForbidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatForbidden");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

channel::channel()
  : flags_()
  , creator_()
  , left_()
  , broadcast_()
  , verified_()
  , megagroup_()
  , restricted_()
  , signatures_()
  , min_()
  , scam_()
  , has_link_()
  , has_geo_()
  , slowmode_enabled_()
  , call_active_()
  , call_not_empty_()
  , fake_()
  , gigagroup_()
  , noforwards_()
  , join_to_send_()
  , join_request_()
  , forum_()
  , flags2_()
  , stories_hidden_()
  , stories_hidden_min_()
  , stories_unavailable_()
  , signature_profiles_()
  , autotranslation_()
  , broadcast_messages_allowed_()
  , monoforum_()
  , forum_tabs_()
  , id_()
  , access_hash_()
  , title_()
  , username_()
  , photo_()
  , date_()
  , restriction_reason_()
  , admin_rights_()
  , banned_rights_()
  , default_banned_rights_()
  , participants_count_()
  , usernames_()
  , stories_max_id_()
  , color_()
  , profile_color_()
  , emoji_status_()
  , level_()
  , subscription_until_date_()
  , bot_verification_icon_()
  , send_paid_messages_stars_()
  , linked_monoforum_id_()
{}

channel::channel(int32 flags_, bool creator_, bool left_, bool broadcast_, bool verified_, bool megagroup_, bool restricted_, bool signatures_, bool min_, bool scam_, bool has_link_, bool has_geo_, bool slowmode_enabled_, bool call_active_, bool call_not_empty_, bool fake_, bool gigagroup_, bool noforwards_, bool join_to_send_, bool join_request_, bool forum_, int32 flags2_, bool stories_hidden_, bool stories_hidden_min_, bool stories_unavailable_, bool signature_profiles_, bool autotranslation_, bool broadcast_messages_allowed_, bool monoforum_, bool forum_tabs_, int64 id_, int64 access_hash_, string const &title_, string const &username_, object_ptr<ChatPhoto> &&photo_, int32 date_, array<object_ptr<restrictionReason>> &&restriction_reason_, object_ptr<chatAdminRights> &&admin_rights_, object_ptr<chatBannedRights> &&banned_rights_, object_ptr<chatBannedRights> &&default_banned_rights_, int32 participants_count_, array<object_ptr<username>> &&usernames_, object_ptr<recentStory> &&stories_max_id_, object_ptr<PeerColor> &&color_, object_ptr<PeerColor> &&profile_color_, object_ptr<EmojiStatus> &&emoji_status_, int32 level_, int32 subscription_until_date_, int64 bot_verification_icon_, int64 send_paid_messages_stars_, int64 linked_monoforum_id_)
  : flags_(flags_)
  , creator_(creator_)
  , left_(left_)
  , broadcast_(broadcast_)
  , verified_(verified_)
  , megagroup_(megagroup_)
  , restricted_(restricted_)
  , signatures_(signatures_)
  , min_(min_)
  , scam_(scam_)
  , has_link_(has_link_)
  , has_geo_(has_geo_)
  , slowmode_enabled_(slowmode_enabled_)
  , call_active_(call_active_)
  , call_not_empty_(call_not_empty_)
  , fake_(fake_)
  , gigagroup_(gigagroup_)
  , noforwards_(noforwards_)
  , join_to_send_(join_to_send_)
  , join_request_(join_request_)
  , forum_(forum_)
  , flags2_(flags2_)
  , stories_hidden_(stories_hidden_)
  , stories_hidden_min_(stories_hidden_min_)
  , stories_unavailable_(stories_unavailable_)
  , signature_profiles_(signature_profiles_)
  , autotranslation_(autotranslation_)
  , broadcast_messages_allowed_(broadcast_messages_allowed_)
  , monoforum_(monoforum_)
  , forum_tabs_(forum_tabs_)
  , id_(id_)
  , access_hash_(access_hash_)
  , title_(title_)
  , username_(username_)
  , photo_(std::move(photo_))
  , date_(date_)
  , restriction_reason_(std::move(restriction_reason_))
  , admin_rights_(std::move(admin_rights_))
  , banned_rights_(std::move(banned_rights_))
  , default_banned_rights_(std::move(default_banned_rights_))
  , participants_count_(participants_count_)
  , usernames_(std::move(usernames_))
  , stories_max_id_(std::move(stories_max_id_))
  , color_(std::move(color_))
  , profile_color_(std::move(profile_color_))
  , emoji_status_(std::move(emoji_status_))
  , level_(level_)
  , subscription_until_date_(subscription_until_date_)
  , bot_verification_icon_(bot_verification_icon_)
  , send_paid_messages_stars_(send_paid_messages_stars_)
  , linked_monoforum_id_(linked_monoforum_id_)
{}

const std::int32_t channel::ID;

object_ptr<Chat> channel::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channel> res = make_tl_object<channel>();
  int32 var0;
  int32 var1;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->creator_ = (var0 & 1) != 0;
  res->left_ = (var0 & 4) != 0;
  res->broadcast_ = (var0 & 32) != 0;
  res->verified_ = (var0 & 128) != 0;
  res->megagroup_ = (var0 & 256) != 0;
  res->restricted_ = (var0 & 512) != 0;
  res->signatures_ = (var0 & 2048) != 0;
  res->min_ = (var0 & 4096) != 0;
  res->scam_ = (var0 & 524288) != 0;
  res->has_link_ = (var0 & 1048576) != 0;
  res->has_geo_ = (var0 & 2097152) != 0;
  res->slowmode_enabled_ = (var0 & 4194304) != 0;
  res->call_active_ = (var0 & 8388608) != 0;
  res->call_not_empty_ = (var0 & 16777216) != 0;
  res->fake_ = (var0 & 33554432) != 0;
  res->gigagroup_ = (var0 & 67108864) != 0;
  res->noforwards_ = (var0 & 134217728) != 0;
  res->join_to_send_ = (var0 & 268435456) != 0;
  res->join_request_ = (var0 & 536870912) != 0;
  res->forum_ = (var0 & 1073741824) != 0;
  if ((var1 = res->flags2_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->stories_hidden_ = (var1 & 2) != 0;
  res->stories_hidden_min_ = (var1 & 4) != 0;
  res->stories_unavailable_ = (var1 & 8) != 0;
  res->signature_profiles_ = (var1 & 4096) != 0;
  res->autotranslation_ = (var1 & 32768) != 0;
  res->broadcast_messages_allowed_ = (var1 & 65536) != 0;
  res->monoforum_ = (var1 & 131072) != 0;
  res->forum_tabs_ = (var1 & 524288) != 0;
  res->id_ = TlFetchLong::parse(p);
  if (var0 & 8192) { res->access_hash_ = TlFetchLong::parse(p); }
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 64) { res->username_ = TlFetchString<string>::parse(p); }
  res->photo_ = TlFetchObject<ChatPhoto>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 512) { res->restriction_reason_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<restrictionReason>, -797791052>>, 481674261>::parse(p); }
  if (var0 & 16384) { res->admin_rights_ = TlFetchBoxed<TlFetchObject<chatAdminRights>, 1605510357>::parse(p); }
  if (var0 & 32768) { res->banned_rights_ = TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p); }
  if (var0 & 262144) { res->default_banned_rights_ = TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p); }
  if (var0 & 131072) { res->participants_count_ = TlFetchInt::parse(p); }
  if (var1 & 1) { res->usernames_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<username>, -1274595769>>, 481674261>::parse(p); }
  if (var1 & 16) { res->stories_max_id_ = TlFetchBoxed<TlFetchObject<recentStory>, 1897752877>::parse(p); }
  if (var1 & 128) { res->color_ = TlFetchObject<PeerColor>::parse(p); }
  if (var1 & 256) { res->profile_color_ = TlFetchObject<PeerColor>::parse(p); }
  if (var1 & 512) { res->emoji_status_ = TlFetchObject<EmojiStatus>::parse(p); }
  if (var1 & 1024) { res->level_ = TlFetchInt::parse(p); }
  if (var1 & 2048) { res->subscription_until_date_ = TlFetchInt::parse(p); }
  if (var1 & 8192) { res->bot_verification_icon_ = TlFetchLong::parse(p); }
  if (var1 & 16384) { res->send_paid_messages_stars_ = TlFetchLong::parse(p); }
  if (var1 & 262144) { res->linked_monoforum_id_ = TlFetchLong::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  int32 var1;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (left_ << 2) | (broadcast_ << 5) | (verified_ << 7) | (megagroup_ << 8) | (restricted_ << 9) | (signatures_ << 11) | (min_ << 12) | (scam_ << 19) | (has_link_ << 20) | (has_geo_ << 21) | (slowmode_enabled_ << 22) | (call_active_ << 23) | (call_not_empty_ << 24) | (fake_ << 25) | (gigagroup_ << 26) | (noforwards_ << 27) | (join_to_send_ << 28) | (join_request_ << 29) | (forum_ << 30)), s);
  TlStoreBinary::store((var1 = flags2_ | (stories_hidden_ << 1) | (stories_hidden_min_ << 2) | (stories_unavailable_ << 3) | (signature_profiles_ << 12) | (autotranslation_ << 15) | (broadcast_messages_allowed_ << 16) | (monoforum_ << 17) | (forum_tabs_ << 19)), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 8192) { TlStoreBinary::store(access_hash_, s); }
  TlStoreString::store(title_, s);
  if (var0 & 64) { TlStoreString::store(username_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 512) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -797791052>>, 481674261>::store(restriction_reason_, s); }
  if (var0 & 16384) { TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s); }
  if (var0 & 32768) { TlStoreBoxed<TlStoreObject, -1626209256>::store(banned_rights_, s); }
  if (var0 & 262144) { TlStoreBoxed<TlStoreObject, -1626209256>::store(default_banned_rights_, s); }
  if (var0 & 131072) { TlStoreBinary::store(participants_count_, s); }
  if (var1 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1274595769>>, 481674261>::store(usernames_, s); }
  if (var1 & 16) { TlStoreBoxed<TlStoreObject, 1897752877>::store(stories_max_id_, s); }
  if (var1 & 128) { TlStoreBoxedUnknown<TlStoreObject>::store(color_, s); }
  if (var1 & 256) { TlStoreBoxedUnknown<TlStoreObject>::store(profile_color_, s); }
  if (var1 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s); }
  if (var1 & 1024) { TlStoreBinary::store(level_, s); }
  if (var1 & 2048) { TlStoreBinary::store(subscription_until_date_, s); }
  if (var1 & 8192) { TlStoreBinary::store(bot_verification_icon_, s); }
  if (var1 & 16384) { TlStoreBinary::store(send_paid_messages_stars_, s); }
  if (var1 & 262144) { TlStoreBinary::store(linked_monoforum_id_, s); }
}

void channel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  int32 var1;
  TlStoreBinary::store((var0 = flags_ | (creator_ << 0) | (left_ << 2) | (broadcast_ << 5) | (verified_ << 7) | (megagroup_ << 8) | (restricted_ << 9) | (signatures_ << 11) | (min_ << 12) | (scam_ << 19) | (has_link_ << 20) | (has_geo_ << 21) | (slowmode_enabled_ << 22) | (call_active_ << 23) | (call_not_empty_ << 24) | (fake_ << 25) | (gigagroup_ << 26) | (noforwards_ << 27) | (join_to_send_ << 28) | (join_request_ << 29) | (forum_ << 30)), s);
  TlStoreBinary::store((var1 = flags2_ | (stories_hidden_ << 1) | (stories_hidden_min_ << 2) | (stories_unavailable_ << 3) | (signature_profiles_ << 12) | (autotranslation_ << 15) | (broadcast_messages_allowed_ << 16) | (monoforum_ << 17) | (forum_tabs_ << 19)), s);
  TlStoreBinary::store(id_, s);
  if (var0 & 8192) { TlStoreBinary::store(access_hash_, s); }
  TlStoreString::store(title_, s);
  if (var0 & 64) { TlStoreString::store(username_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 512) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -797791052>>, 481674261>::store(restriction_reason_, s); }
  if (var0 & 16384) { TlStoreBoxed<TlStoreObject, 1605510357>::store(admin_rights_, s); }
  if (var0 & 32768) { TlStoreBoxed<TlStoreObject, -1626209256>::store(banned_rights_, s); }
  if (var0 & 262144) { TlStoreBoxed<TlStoreObject, -1626209256>::store(default_banned_rights_, s); }
  if (var0 & 131072) { TlStoreBinary::store(participants_count_, s); }
  if (var1 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1274595769>>, 481674261>::store(usernames_, s); }
  if (var1 & 16) { TlStoreBoxed<TlStoreObject, 1897752877>::store(stories_max_id_, s); }
  if (var1 & 128) { TlStoreBoxedUnknown<TlStoreObject>::store(color_, s); }
  if (var1 & 256) { TlStoreBoxedUnknown<TlStoreObject>::store(profile_color_, s); }
  if (var1 & 512) { TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s); }
  if (var1 & 1024) { TlStoreBinary::store(level_, s); }
  if (var1 & 2048) { TlStoreBinary::store(subscription_until_date_, s); }
  if (var1 & 8192) { TlStoreBinary::store(bot_verification_icon_, s); }
  if (var1 & 16384) { TlStoreBinary::store(send_paid_messages_stars_, s); }
  if (var1 & 262144) { TlStoreBinary::store(linked_monoforum_id_, s); }
}

void channel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channel");
  int32 var0;
  int32 var1;
    s.store_field("flags", (var0 = flags_ | (creator_ << 0) | (left_ << 2) | (broadcast_ << 5) | (verified_ << 7) | (megagroup_ << 8) | (restricted_ << 9) | (signatures_ << 11) | (min_ << 12) | (scam_ << 19) | (has_link_ << 20) | (has_geo_ << 21) | (slowmode_enabled_ << 22) | (call_active_ << 23) | (call_not_empty_ << 24) | (fake_ << 25) | (gigagroup_ << 26) | (noforwards_ << 27) | (join_to_send_ << 28) | (join_request_ << 29) | (forum_ << 30)));
    if (var0 & 1) { s.store_field("creator", true); }
    if (var0 & 4) { s.store_field("left", true); }
    if (var0 & 32) { s.store_field("broadcast", true); }
    if (var0 & 128) { s.store_field("verified", true); }
    if (var0 & 256) { s.store_field("megagroup", true); }
    if (var0 & 512) { s.store_field("restricted", true); }
    if (var0 & 2048) { s.store_field("signatures", true); }
    if (var0 & 4096) { s.store_field("min", true); }
    if (var0 & 524288) { s.store_field("scam", true); }
    if (var0 & 1048576) { s.store_field("has_link", true); }
    if (var0 & 2097152) { s.store_field("has_geo", true); }
    if (var0 & 4194304) { s.store_field("slowmode_enabled", true); }
    if (var0 & 8388608) { s.store_field("call_active", true); }
    if (var0 & 16777216) { s.store_field("call_not_empty", true); }
    if (var0 & 33554432) { s.store_field("fake", true); }
    if (var0 & 67108864) { s.store_field("gigagroup", true); }
    if (var0 & 134217728) { s.store_field("noforwards", true); }
    if (var0 & 268435456) { s.store_field("join_to_send", true); }
    if (var0 & 536870912) { s.store_field("join_request", true); }
    if (var0 & 1073741824) { s.store_field("forum", true); }
    s.store_field("flags2", (var1 = flags2_ | (stories_hidden_ << 1) | (stories_hidden_min_ << 2) | (stories_unavailable_ << 3) | (signature_profiles_ << 12) | (autotranslation_ << 15) | (broadcast_messages_allowed_ << 16) | (monoforum_ << 17) | (forum_tabs_ << 19)));
    if (var1 & 2) { s.store_field("stories_hidden", true); }
    if (var1 & 4) { s.store_field("stories_hidden_min", true); }
    if (var1 & 8) { s.store_field("stories_unavailable", true); }
    if (var1 & 4096) { s.store_field("signature_profiles", true); }
    if (var1 & 32768) { s.store_field("autotranslation", true); }
    if (var1 & 65536) { s.store_field("broadcast_messages_allowed", true); }
    if (var1 & 131072) { s.store_field("monoforum", true); }
    if (var1 & 524288) { s.store_field("forum_tabs", true); }
    s.store_field("id", id_);
    if (var0 & 8192) { s.store_field("access_hash", access_hash_); }
    s.store_field("title", title_);
    if (var0 & 64) { s.store_field("username", username_); }
    s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get()));
    s.store_field("date", date_);
    if (var0 & 512) { { s.store_vector_begin("restriction_reason", restriction_reason_.size()); for (const auto &_value : restriction_reason_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16384) { s.store_object_field("admin_rights", static_cast<const BaseObject *>(admin_rights_.get())); }
    if (var0 & 32768) { s.store_object_field("banned_rights", static_cast<const BaseObject *>(banned_rights_.get())); }
    if (var0 & 262144) { s.store_object_field("default_banned_rights", static_cast<const BaseObject *>(default_banned_rights_.get())); }
    if (var0 & 131072) { s.store_field("participants_count", participants_count_); }
    if (var1 & 1) { { s.store_vector_begin("usernames", usernames_.size()); for (const auto &_value : usernames_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var1 & 16) { s.store_object_field("stories_max_id", static_cast<const BaseObject *>(stories_max_id_.get())); }
    if (var1 & 128) { s.store_object_field("color", static_cast<const BaseObject *>(color_.get())); }
    if (var1 & 256) { s.store_object_field("profile_color", static_cast<const BaseObject *>(profile_color_.get())); }
    if (var1 & 512) { s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get())); }
    if (var1 & 1024) { s.store_field("level", level_); }
    if (var1 & 2048) { s.store_field("subscription_until_date", subscription_until_date_); }
    if (var1 & 8192) { s.store_field("bot_verification_icon", bot_verification_icon_); }
    if (var1 & 16384) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    if (var1 & 262144) { s.store_field("linked_monoforum_id", linked_monoforum_id_); }
    s.store_class_end();
  }
}

channelForbidden::channelForbidden()
  : flags_()
  , broadcast_()
  , megagroup_()
  , monoforum_()
  , id_()
  , access_hash_()
  , title_()
  , until_date_()
{}

channelForbidden::channelForbidden(int32 flags_, bool broadcast_, bool megagroup_, bool monoforum_, int64 id_, int64 access_hash_, string const &title_, int32 until_date_)
  : flags_(flags_)
  , broadcast_(broadcast_)
  , megagroup_(megagroup_)
  , monoforum_(monoforum_)
  , id_(id_)
  , access_hash_(access_hash_)
  , title_(title_)
  , until_date_(until_date_)
{}

const std::int32_t channelForbidden::ID;

object_ptr<Chat> channelForbidden::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelForbidden> res = make_tl_object<channelForbidden>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->broadcast_ = (var0 & 32) != 0;
  res->megagroup_ = (var0 & 256) != 0;
  res->monoforum_ = (var0 & 1024) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  if (var0 & 65536) { res->until_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelForbidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (broadcast_ << 5) | (megagroup_ << 8) | (monoforum_ << 10)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(title_, s);
  if (var0 & 65536) { TlStoreBinary::store(until_date_, s); }
}

void channelForbidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (broadcast_ << 5) | (megagroup_ << 8) | (monoforum_ << 10)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(title_, s);
  if (var0 & 65536) { TlStoreBinary::store(until_date_, s); }
}

void channelForbidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelForbidden");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (broadcast_ << 5) | (megagroup_ << 8) | (monoforum_ << 10)));
    if (var0 & 32) { s.store_field("broadcast", true); }
    if (var0 & 256) { s.store_field("megagroup", true); }
    if (var0 & 1024) { s.store_field("monoforum", true); }
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_field("title", title_);
    if (var0 & 65536) { s.store_field("until_date", until_date_); }
    s.store_class_end();
  }
}

const std::int32_t emojiURL::ID;

object_ptr<emojiURL> emojiURL::fetch(TlBufferParser &p) {
  return make_tl_object<emojiURL>(p);
}

emojiURL::emojiURL(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void emojiURL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiURL");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

const std::int32_t exportedMessageLink::ID;

object_ptr<exportedMessageLink> exportedMessageLink::fetch(TlBufferParser &p) {
  return make_tl_object<exportedMessageLink>(p);
}

exportedMessageLink::exportedMessageLink(TlBufferParser &p)
  : link_(TlFetchString<string>::parse(p))
  , html_(TlFetchString<string>::parse(p))
{}

void exportedMessageLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "exportedMessageLink");
    s.store_field("link", link_);
    s.store_field("html", html_);
    s.store_class_end();
  }
}

const std::int32_t groupCallParticipantVideoSourceGroup::ID;

object_ptr<groupCallParticipantVideoSourceGroup> groupCallParticipantVideoSourceGroup::fetch(TlBufferParser &p) {
  return make_tl_object<groupCallParticipantVideoSourceGroup>(p);
}

groupCallParticipantVideoSourceGroup::groupCallParticipantVideoSourceGroup(TlBufferParser &p)
  : semantics_(TlFetchString<string>::parse(p))
  , sources_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void groupCallParticipantVideoSourceGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "groupCallParticipantVideoSourceGroup");
    s.store_field("semantics", semantics_);
    { s.store_vector_begin("sources", sources_.size()); for (const auto &_value : sources_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

inputBotInlineMessageMediaAuto::inputBotInlineMessageMediaAuto(int32 flags_, bool invert_media_, string const &message_, array<object_ptr<MessageEntity>> &&entities_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , invert_media_(invert_media_)
  , message_(message_)
  , entities_(std::move(entities_))
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageMediaAuto::ID;

void inputBotInlineMessageMediaAuto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 3)), s);
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaAuto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 3)), s);
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaAuto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageMediaAuto");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (invert_media_ << 3)));
    if (var0 & 8) { s.store_field("invert_media", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageText::inputBotInlineMessageText(int32 flags_, bool no_webpage_, bool invert_media_, string const &message_, array<object_ptr<MessageEntity>> &&entities_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , no_webpage_(no_webpage_)
  , invert_media_(invert_media_)
  , message_(message_)
  , entities_(std::move(entities_))
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageText::ID;

void inputBotInlineMessageText::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 0) | (invert_media_ << 3)), s);
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageText::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 0) | (invert_media_ << 3)), s);
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageText");
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

inputBotInlineMessageMediaGeo::inputBotInlineMessageMediaGeo(int32 flags_, object_ptr<InputGeoPoint> &&geo_point_, int32 heading_, int32 period_, int32 proximity_notification_radius_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , geo_point_(std::move(geo_point_))
  , heading_(heading_)
  , period_(period_)
  , proximity_notification_radius_(proximity_notification_radius_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageMediaGeo::ID;

void inputBotInlineMessageMediaGeo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  if (var0 & 1) { TlStoreBinary::store(heading_, s); }
  if (var0 & 2) { TlStoreBinary::store(period_, s); }
  if (var0 & 8) { TlStoreBinary::store(proximity_notification_radius_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaGeo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  if (var0 & 1) { TlStoreBinary::store(heading_, s); }
  if (var0 & 2) { TlStoreBinary::store(period_, s); }
  if (var0 & 8) { TlStoreBinary::store(proximity_notification_radius_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaGeo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageMediaGeo");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    if (var0 & 1) { s.store_field("heading", heading_); }
    if (var0 & 2) { s.store_field("period", period_); }
    if (var0 & 8) { s.store_field("proximity_notification_radius", proximity_notification_radius_); }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageMediaVenue::inputBotInlineMessageMediaVenue(int32 flags_, object_ptr<InputGeoPoint> &&geo_point_, string const &title_, string const &address_, string const &provider_, string const &venue_id_, string const &venue_type_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , geo_point_(std::move(geo_point_))
  , title_(title_)
  , address_(address_)
  , provider_(provider_)
  , venue_id_(venue_id_)
  , venue_type_(venue_type_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageMediaVenue::ID;

void inputBotInlineMessageMediaVenue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaVenue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageMediaVenue");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("venue_id", venue_id_);
    s.store_field("venue_type", venue_type_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageMediaContact::inputBotInlineMessageMediaContact(int32 flags_, string const &phone_number_, string const &first_name_, string const &last_name_, string const &vcard_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , phone_number_(phone_number_)
  , first_name_(first_name_)
  , last_name_(last_name_)
  , vcard_(vcard_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageMediaContact::ID;

void inputBotInlineMessageMediaContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(vcard_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(vcard_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageMediaContact");
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

inputBotInlineMessageGame::inputBotInlineMessageGame(int32 flags_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageGame::ID;

void inputBotInlineMessageGame::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageGame::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageGame::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageGame");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageMediaInvoice::inputBotInlineMessageMediaInvoice(int32 flags_, string const &title_, string const &description_, object_ptr<inputWebDocument> &&photo_, object_ptr<invoice> &&invoice_, bytes &&payload_, string const &provider_, object_ptr<dataJSON> &&provider_data_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , title_(title_)
  , description_(description_)
  , photo_(std::move(photo_))
  , invoice_(std::move(invoice_))
  , payload_(std::move(payload_))
  , provider_(provider_)
  , provider_data_(std::move(provider_data_))
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageMediaInvoice::ID;

void inputBotInlineMessageMediaInvoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1678949555>::store(photo_, s); }
  TlStoreBoxed<TlStoreObject, 77522308>::store(invoice_, s);
  TlStoreString::store(payload_, s);
  TlStoreString::store(provider_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(provider_data_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaInvoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(title_, s);
  TlStoreString::store(description_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -1678949555>::store(photo_, s); }
  TlStoreBoxed<TlStoreObject, 77522308>::store(invoice_, s);
  TlStoreString::store(payload_, s);
  TlStoreString::store(provider_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(provider_data_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaInvoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageMediaInvoice");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("title", title_);
    s.store_field("description", description_);
    if (var0 & 1) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    s.store_bytes_field("payload", payload_);
    s.store_field("provider", provider_);
    s.store_object_field("provider_data", static_cast<const BaseObject *>(provider_data_.get()));
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBotInlineMessageMediaWebPage::inputBotInlineMessageMediaWebPage(int32 flags_, bool invert_media_, bool force_large_media_, bool force_small_media_, bool optional_, string const &message_, array<object_ptr<MessageEntity>> &&entities_, string const &url_, object_ptr<ReplyMarkup> &&reply_markup_)
  : flags_(flags_)
  , invert_media_(invert_media_)
  , force_large_media_(force_large_media_)
  , force_small_media_(force_small_media_)
  , optional_(optional_)
  , message_(message_)
  , entities_(std::move(entities_))
  , url_(url_)
  , reply_markup_(std::move(reply_markup_))
{}

const std::int32_t inputBotInlineMessageMediaWebPage::ID;

void inputBotInlineMessageMediaWebPage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 3) | (force_large_media_ << 4) | (force_small_media_ << 5) | (optional_ << 6)), s);
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreString::store(url_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaWebPage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (invert_media_ << 3) | (force_large_media_ << 4) | (force_small_media_ << 5) | (optional_ << 6)), s);
  TlStoreString::store(message_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreString::store(url_, s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
}

void inputBotInlineMessageMediaWebPage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBotInlineMessageMediaWebPage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (invert_media_ << 3) | (force_large_media_ << 4) | (force_small_media_ << 5) | (optional_ << 6)));
    if (var0 & 8) { s.store_field("invert_media", true); }
    if (var0 & 16) { s.store_field("force_large_media", true); }
    if (var0 & 32) { s.store_field("force_small_media", true); }
    if (var0 & 64) { s.store_field("optional", true); }
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("url", url_);
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    s.store_class_end();
  }
}

inputBusinessChatLink::inputBusinessChatLink(int32 flags_, string const &message_, array<object_ptr<MessageEntity>> &&entities_, string const &title_)
  : flags_(flags_)
  , message_(message_)
  , entities_(std::move(entities_))
  , title_(title_)
{}

const std::int32_t inputBusinessChatLink::ID;

void inputBusinessChatLink::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(message_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 2) { TlStoreString::store(title_, s); }
}

void inputBusinessChatLink::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(message_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 2) { TlStoreString::store(title_, s); }
}

void inputBusinessChatLink::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessChatLink");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("message", message_);
    if (var0 & 1) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_field("title", title_); }
    s.store_class_end();
  }
}

inputBusinessGreetingMessage::inputBusinessGreetingMessage(int32 shortcut_id_, object_ptr<inputBusinessRecipients> &&recipients_, int32 no_activity_days_)
  : shortcut_id_(shortcut_id_)
  , recipients_(std::move(recipients_))
  , no_activity_days_(no_activity_days_)
{}

const std::int32_t inputBusinessGreetingMessage::ID;

void inputBusinessGreetingMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxed<TlStoreObject, 1871393450>::store(recipients_, s);
  TlStoreBinary::store(no_activity_days_, s);
}

void inputBusinessGreetingMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(shortcut_id_, s);
  TlStoreBoxed<TlStoreObject, 1871393450>::store(recipients_, s);
  TlStoreBinary::store(no_activity_days_, s);
}

void inputBusinessGreetingMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputBusinessGreetingMessage");
    s.store_field("shortcut_id", shortcut_id_);
    s.store_object_field("recipients", static_cast<const BaseObject *>(recipients_.get()));
    s.store_field("no_activity_days", no_activity_days_);
    s.store_class_end();
  }
}

inputPeerNotifySettings::inputPeerNotifySettings(int32 flags_, bool show_previews_, bool silent_, int32 mute_until_, object_ptr<NotificationSound> &&sound_, bool stories_muted_, bool stories_hide_sender_, object_ptr<NotificationSound> &&stories_sound_)
  : flags_(flags_)
  , show_previews_(show_previews_)
  , silent_(silent_)
  , mute_until_(mute_until_)
  , sound_(std::move(sound_))
  , stories_muted_(stories_muted_)
  , stories_hide_sender_(stories_hide_sender_)
  , stories_sound_(std::move(stories_sound_))
{}

const std::int32_t inputPeerNotifySettings::ID;

void inputPeerNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBool::store(show_previews_, s); }
  if (var0 & 2) { TlStoreBool::store(silent_, s); }
  if (var0 & 4) { TlStoreBinary::store(mute_until_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(sound_, s); }
  if (var0 & 64) { TlStoreBool::store(stories_muted_, s); }
  if (var0 & 128) { TlStoreBool::store(stories_hide_sender_, s); }
  if (var0 & 256) { TlStoreBoxedUnknown<TlStoreObject>::store(stories_sound_, s); }
}

void inputPeerNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBool::store(show_previews_, s); }
  if (var0 & 2) { TlStoreBool::store(silent_, s); }
  if (var0 & 4) { TlStoreBinary::store(mute_until_, s); }
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(sound_, s); }
  if (var0 & 64) { TlStoreBool::store(stories_muted_, s); }
  if (var0 & 128) { TlStoreBool::store(stories_hide_sender_, s); }
  if (var0 & 256) { TlStoreBoxedUnknown<TlStoreObject>::store(stories_sound_, s); }
}

void inputPeerNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputPeerNotifySettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("show_previews", show_previews_); }
    if (var0 & 2) { s.store_field("silent", silent_); }
    if (var0 & 4) { s.store_field("mute_until", mute_until_); }
    if (var0 & 8) { s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get())); }
    if (var0 & 64) { s.store_field("stories_muted", stories_muted_); }
    if (var0 & 128) { s.store_field("stories_hide_sender", stories_hide_sender_); }
    if (var0 & 256) { s.store_object_field("stories_sound", static_cast<const BaseObject *>(stories_sound_.get())); }
    s.store_class_end();
  }
}

inputTheme::inputTheme(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputTheme::ID;

void inputTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputTheme");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputThemeSlug::inputThemeSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputThemeSlug::ID;

void inputThemeSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputThemeSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputThemeSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputThemeSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

inputWebDocument::inputWebDocument(string const &url_, int32 size_, string const &mime_type_, array<object_ptr<DocumentAttribute>> &&attributes_)
  : url_(url_)
  , size_(size_)
  , mime_type_(mime_type_)
  , attributes_(std::move(attributes_))
{}

const std::int32_t inputWebDocument::ID;

object_ptr<inputWebDocument> inputWebDocument::fetch(TlBufferParser &p) {
  return make_tl_object<inputWebDocument>(p);
}

inputWebDocument::inputWebDocument(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
  , size_(TlFetchInt::parse(p))
  , mime_type_(TlFetchString<string>::parse(p))
  , attributes_(TlFetchBoxed<TlFetchVector<TlFetchObject<DocumentAttribute>>, 481674261>::parse(p))
{}

void inputWebDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void inputWebDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(size_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void inputWebDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputWebDocument");
    s.store_field("url", url_);
    s.store_field("size", size_);
    s.store_field("mime_type", mime_type_);
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

langPackLanguage::langPackLanguage()
  : flags_()
  , official_()
  , rtl_()
  , beta_()
  , name_()
  , native_name_()
  , lang_code_()
  , base_lang_code_()
  , plural_code_()
  , strings_count_()
  , translated_count_()
  , translations_url_()
{}

const std::int32_t langPackLanguage::ID;

object_ptr<langPackLanguage> langPackLanguage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<langPackLanguage> res = make_tl_object<langPackLanguage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->official_ = (var0 & 1) != 0;
  res->rtl_ = (var0 & 4) != 0;
  res->beta_ = (var0 & 8) != 0;
  res->name_ = TlFetchString<string>::parse(p);
  res->native_name_ = TlFetchString<string>::parse(p);
  res->lang_code_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->base_lang_code_ = TlFetchString<string>::parse(p); }
  res->plural_code_ = TlFetchString<string>::parse(p);
  res->strings_count_ = TlFetchInt::parse(p);
  res->translated_count_ = TlFetchInt::parse(p);
  res->translations_url_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void langPackLanguage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langPackLanguage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (official_ << 0) | (rtl_ << 2) | (beta_ << 3)));
    if (var0 & 1) { s.store_field("official", true); }
    if (var0 & 4) { s.store_field("rtl", true); }
    if (var0 & 8) { s.store_field("beta", true); }
    s.store_field("name", name_);
    s.store_field("native_name", native_name_);
    s.store_field("lang_code", lang_code_);
    if (var0 & 2) { s.store_field("base_lang_code", base_lang_code_); }
    s.store_field("plural_code", plural_code_);
    s.store_field("strings_count", strings_count_);
    s.store_field("translated_count", translated_count_);
    s.store_field("translations_url", translations_url_);
    s.store_class_end();
  }
}

object_ptr<MessageEntity> MessageEntity::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

messageEntityUnknown::messageEntityUnknown(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityUnknown::ID;

object_ptr<MessageEntity> messageEntityUnknown::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityUnknown>(p);
}

messageEntityUnknown::messageEntityUnknown(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityUnknown::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityUnknown::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityUnknown::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityUnknown");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityMention::messageEntityMention(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityMention::ID;

object_ptr<MessageEntity> messageEntityMention::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityMention>(p);
}

messageEntityMention::messageEntityMention(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityMention::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityMention::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityMention::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityMention");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityHashtag::messageEntityHashtag(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityHashtag::ID;

object_ptr<MessageEntity> messageEntityHashtag::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityHashtag>(p);
}

messageEntityHashtag::messageEntityHashtag(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityHashtag::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityHashtag::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityHashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityHashtag");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityBotCommand::messageEntityBotCommand(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityBotCommand::ID;

object_ptr<MessageEntity> messageEntityBotCommand::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityBotCommand>(p);
}

messageEntityBotCommand::messageEntityBotCommand(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityBotCommand::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBotCommand::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBotCommand::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityBotCommand");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityUrl::messageEntityUrl(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityUrl::ID;

object_ptr<MessageEntity> messageEntityUrl::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityUrl>(p);
}

messageEntityUrl::messageEntityUrl(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityUrl");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityEmail::messageEntityEmail(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityEmail::ID;

object_ptr<MessageEntity> messageEntityEmail::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityEmail>(p);
}

messageEntityEmail::messageEntityEmail(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityEmail");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityBold::messageEntityBold(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityBold::ID;

object_ptr<MessageEntity> messageEntityBold::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityBold>(p);
}

messageEntityBold::messageEntityBold(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityBold::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBold::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBold::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityBold");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityItalic::messageEntityItalic(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityItalic::ID;

object_ptr<MessageEntity> messageEntityItalic::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityItalic>(p);
}

messageEntityItalic::messageEntityItalic(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityItalic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityItalic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityItalic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityItalic");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityCode::messageEntityCode(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityCode::ID;

object_ptr<MessageEntity> messageEntityCode::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityCode>(p);
}

messageEntityCode::messageEntityCode(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityCode");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityPre::messageEntityPre(int32 offset_, int32 length_, string const &language_)
  : offset_(offset_)
  , length_(length_)
  , language_(language_)
{}

const std::int32_t messageEntityPre::ID;

object_ptr<MessageEntity> messageEntityPre::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityPre>(p);
}

messageEntityPre::messageEntityPre(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
  , language_(TlFetchString<string>::parse(p))
{}

void messageEntityPre::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreString::store(language_, s);
}

void messageEntityPre::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreString::store(language_, s);
}

void messageEntityPre::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityPre");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_field("language", language_);
    s.store_class_end();
  }
}

messageEntityTextUrl::messageEntityTextUrl(int32 offset_, int32 length_, string const &url_)
  : offset_(offset_)
  , length_(length_)
  , url_(url_)
{}

const std::int32_t messageEntityTextUrl::ID;

object_ptr<MessageEntity> messageEntityTextUrl::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityTextUrl>(p);
}

messageEntityTextUrl::messageEntityTextUrl(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
  , url_(TlFetchString<string>::parse(p))
{}

void messageEntityTextUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreString::store(url_, s);
}

void messageEntityTextUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreString::store(url_, s);
}

void messageEntityTextUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityTextUrl");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_field("url", url_);
    s.store_class_end();
  }
}

messageEntityMentionName::messageEntityMentionName(int32 offset_, int32 length_, int64 user_id_)
  : offset_(offset_)
  , length_(length_)
  , user_id_(user_id_)
{}

const std::int32_t messageEntityMentionName::ID;

object_ptr<MessageEntity> messageEntityMentionName::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityMentionName>(p);
}

messageEntityMentionName::messageEntityMentionName(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
  , user_id_(TlFetchLong::parse(p))
{}

void messageEntityMentionName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBinary::store(user_id_, s);
}

void messageEntityMentionName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBinary::store(user_id_, s);
}

void messageEntityMentionName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityMentionName");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_field("user_id", user_id_);
    s.store_class_end();
  }
}

inputMessageEntityMentionName::inputMessageEntityMentionName(int32 offset_, int32 length_, object_ptr<InputUser> &&user_id_)
  : offset_(offset_)
  , length_(length_)
  , user_id_(std::move(user_id_))
{}

const std::int32_t inputMessageEntityMentionName::ID;

object_ptr<MessageEntity> inputMessageEntityMentionName::fetch(TlBufferParser &p) {
  return make_tl_object<inputMessageEntityMentionName>(p);
}

inputMessageEntityMentionName::inputMessageEntityMentionName(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
  , user_id_(TlFetchObject<InputUser>::parse(p))
{}

void inputMessageEntityMentionName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void inputMessageEntityMentionName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void inputMessageEntityMentionName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageEntityMentionName");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

messageEntityPhone::messageEntityPhone(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityPhone::ID;

object_ptr<MessageEntity> messageEntityPhone::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityPhone>(p);
}

messageEntityPhone::messageEntityPhone(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityPhone");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityCashtag::messageEntityCashtag(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityCashtag::ID;

object_ptr<MessageEntity> messageEntityCashtag::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityCashtag>(p);
}

messageEntityCashtag::messageEntityCashtag(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityCashtag::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityCashtag::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityCashtag::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityCashtag");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityUnderline::messageEntityUnderline(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityUnderline::ID;

object_ptr<MessageEntity> messageEntityUnderline::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityUnderline>(p);
}

messageEntityUnderline::messageEntityUnderline(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityUnderline::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityUnderline::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityUnderline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityUnderline");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityStrike::messageEntityStrike(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityStrike::ID;

object_ptr<MessageEntity> messageEntityStrike::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityStrike>(p);
}

messageEntityStrike::messageEntityStrike(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityStrike::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityStrike::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityStrike::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityStrike");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityBankCard::messageEntityBankCard(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityBankCard::ID;

object_ptr<MessageEntity> messageEntityBankCard::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityBankCard>(p);
}

messageEntityBankCard::messageEntityBankCard(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityBankCard::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBankCard::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBankCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityBankCard");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntitySpoiler::messageEntitySpoiler(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntitySpoiler::ID;

object_ptr<MessageEntity> messageEntitySpoiler::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntitySpoiler>(p);
}

messageEntitySpoiler::messageEntitySpoiler(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntitySpoiler::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntitySpoiler::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntitySpoiler::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntitySpoiler");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityCustomEmoji::messageEntityCustomEmoji(int32 offset_, int32 length_, int64 document_id_)
  : offset_(offset_)
  , length_(length_)
  , document_id_(document_id_)
{}

const std::int32_t messageEntityCustomEmoji::ID;

object_ptr<MessageEntity> messageEntityCustomEmoji::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityCustomEmoji>(p);
}

messageEntityCustomEmoji::messageEntityCustomEmoji(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
  , document_id_(TlFetchLong::parse(p))
{}

void messageEntityCustomEmoji::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBinary::store(document_id_, s);
}

void messageEntityCustomEmoji::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBinary::store(document_id_, s);
}

void messageEntityCustomEmoji::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityCustomEmoji");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_field("document_id", document_id_);
    s.store_class_end();
  }
}

messageEntityBlockquote::messageEntityBlockquote()
  : flags_()
  , collapsed_()
  , offset_()
  , length_()
{}

messageEntityBlockquote::messageEntityBlockquote(int32 flags_, bool collapsed_, int32 offset_, int32 length_)
  : flags_(flags_)
  , collapsed_(collapsed_)
  , offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityBlockquote::ID;

object_ptr<MessageEntity> messageEntityBlockquote::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageEntityBlockquote> res = make_tl_object<messageEntityBlockquote>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->collapsed_ = (var0 & 1) != 0;
  res->offset_ = TlFetchInt::parse(p);
  res->length_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageEntityBlockquote::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (collapsed_ << 0)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBlockquote::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (collapsed_ << 0)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityBlockquote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityBlockquote");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (collapsed_ << 0)));
    if (var0 & 1) { s.store_field("collapsed", true); }
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityFormattedDate::messageEntityFormattedDate()
  : flags_()
  , relative_()
  , short_time_()
  , long_time_()
  , short_date_()
  , long_date_()
  , day_of_week_()
  , offset_()
  , length_()
  , date_()
{}

messageEntityFormattedDate::messageEntityFormattedDate(int32 flags_, bool relative_, bool short_time_, bool long_time_, bool short_date_, bool long_date_, bool day_of_week_, int32 offset_, int32 length_, int32 date_)
  : flags_(flags_)
  , relative_(relative_)
  , short_time_(short_time_)
  , long_time_(long_time_)
  , short_date_(short_date_)
  , long_date_(long_date_)
  , day_of_week_(day_of_week_)
  , offset_(offset_)
  , length_(length_)
  , date_(date_)
{}

const std::int32_t messageEntityFormattedDate::ID;

object_ptr<MessageEntity> messageEntityFormattedDate::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messageEntityFormattedDate> res = make_tl_object<messageEntityFormattedDate>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->relative_ = (var0 & 1) != 0;
  res->short_time_ = (var0 & 2) != 0;
  res->long_time_ = (var0 & 4) != 0;
  res->short_date_ = (var0 & 8) != 0;
  res->long_date_ = (var0 & 16) != 0;
  res->day_of_week_ = (var0 & 32) != 0;
  res->offset_ = TlFetchInt::parse(p);
  res->length_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void messageEntityFormattedDate::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (relative_ << 0) | (short_time_ << 1) | (long_time_ << 2) | (short_date_ << 3) | (long_date_ << 4) | (day_of_week_ << 5)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBinary::store(date_, s);
}

void messageEntityFormattedDate::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (relative_ << 0) | (short_time_ << 1) | (long_time_ << 2) | (short_date_ << 3) | (long_date_ << 4) | (day_of_week_ << 5)), s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreBinary::store(date_, s);
}

void messageEntityFormattedDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityFormattedDate");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (relative_ << 0) | (short_time_ << 1) | (long_time_ << 2) | (short_date_ << 3) | (long_date_ << 4) | (day_of_week_ << 5)));
    if (var0 & 1) { s.store_field("relative", true); }
    if (var0 & 2) { s.store_field("short_time", true); }
    if (var0 & 4) { s.store_field("long_time", true); }
    if (var0 & 8) { s.store_field("short_date", true); }
    if (var0 & 16) { s.store_field("long_date", true); }
    if (var0 & 32) { s.store_field("day_of_week", true); }
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

messageEntityDiffInsert::messageEntityDiffInsert(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityDiffInsert::ID;

object_ptr<MessageEntity> messageEntityDiffInsert::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityDiffInsert>(p);
}

messageEntityDiffInsert::messageEntityDiffInsert(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityDiffInsert::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityDiffInsert::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityDiffInsert::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityDiffInsert");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messageEntityDiffReplace::messageEntityDiffReplace(int32 offset_, int32 length_, string const &old_text_)
  : offset_(offset_)
  , length_(length_)
  , old_text_(old_text_)
{}

const std::int32_t messageEntityDiffReplace::ID;

object_ptr<MessageEntity> messageEntityDiffReplace::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityDiffReplace>(p);
}

messageEntityDiffReplace::messageEntityDiffReplace(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
  , old_text_(TlFetchString<string>::parse(p))
{}

void messageEntityDiffReplace::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreString::store(old_text_, s);
}

void messageEntityDiffReplace::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
  TlStoreString::store(old_text_, s);
}

void messageEntityDiffReplace::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityDiffReplace");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_field("old_text", old_text_);
    s.store_class_end();
  }
}

messageEntityDiffDelete::messageEntityDiffDelete(int32 offset_, int32 length_)
  : offset_(offset_)
  , length_(length_)
{}

const std::int32_t messageEntityDiffDelete::ID;

object_ptr<MessageEntity> messageEntityDiffDelete::fetch(TlBufferParser &p) {
  return make_tl_object<messageEntityDiffDelete>(p);
}

messageEntityDiffDelete::messageEntityDiffDelete(TlBufferParser &p)
  : offset_(TlFetchInt::parse(p))
  , length_(TlFetchInt::parse(p))
{}

void messageEntityDiffDelete::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityDiffDelete::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(length_, s);
}

void messageEntityDiffDelete::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messageEntityDiffDelete");
    s.store_field("offset", offset_);
    s.store_field("length", length_);
    s.store_class_end();
  }
}

messagePeerReaction::messagePeerReaction()
  : flags_()
  , big_()
  , unread_()
  , my_()
  , peer_id_()
  , date_()
  , reaction_()
{}

const std::int32_t messagePeerReaction::ID;

object_ptr<messagePeerReaction> messagePeerReaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messagePeerReaction> res = make_tl_object<messagePeerReaction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->big_ = (var0 & 1) != 0;
  res->unread_ = (var0 & 2) != 0;
  res->my_ = (var0 & 4) != 0;
  res->peer_id_ = TlFetchObject<Peer>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->reaction_ = TlFetchObject<Reaction>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messagePeerReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePeerReaction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (big_ << 0) | (unread_ << 1) | (my_ << 2)));
    if (var0 & 1) { s.store_field("big", true); }
    if (var0 & 2) { s.store_field("unread", true); }
    if (var0 & 4) { s.store_field("my", true); }
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    s.store_field("date", date_);
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

const std::int32_t paymentSavedCredentialsCard::ID;

object_ptr<paymentSavedCredentialsCard> paymentSavedCredentialsCard::fetch(TlBufferParser &p) {
  return make_tl_object<paymentSavedCredentialsCard>(p);
}

paymentSavedCredentialsCard::paymentSavedCredentialsCard(TlBufferParser &p)
  : id_(TlFetchString<string>::parse(p))
  , title_(TlFetchString<string>::parse(p))
{}

void paymentSavedCredentialsCard::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentSavedCredentialsCard");
    s.store_field("id", id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

object_ptr<PhotoSize> PhotoSize::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

photoSizeEmpty::photoSizeEmpty(string const &type_)
  : type_(type_)
{}

const std::int32_t photoSizeEmpty::ID;

object_ptr<PhotoSize> photoSizeEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<photoSizeEmpty>(p);
}

photoSizeEmpty::photoSizeEmpty(TlBufferParser &p)
  : type_(TlFetchString<string>::parse(p))
{}

void photoSizeEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
}

void photoSizeEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
}

void photoSizeEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoSizeEmpty");
    s.store_field("type", type_);
    s.store_class_end();
  }
}

photoSize::photoSize(string const &type_, int32 w_, int32 h_, int32 size_)
  : type_(type_)
  , w_(w_)
  , h_(h_)
  , size_(size_)
{}

const std::int32_t photoSize::ID;

object_ptr<PhotoSize> photoSize::fetch(TlBufferParser &p) {
  return make_tl_object<photoSize>(p);
}

photoSize::photoSize(TlBufferParser &p)
  : type_(TlFetchString<string>::parse(p))
  , w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
  , size_(TlFetchInt::parse(p))
{}

void photoSize::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(size_, s);
}

void photoSize::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(size_, s);
}

void photoSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoSize");
    s.store_field("type", type_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_field("size", size_);
    s.store_class_end();
  }
}

photoCachedSize::photoCachedSize(string const &type_, int32 w_, int32 h_, bytes &&bytes_)
  : type_(type_)
  , w_(w_)
  , h_(h_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t photoCachedSize::ID;

object_ptr<PhotoSize> photoCachedSize::fetch(TlBufferParser &p) {
  return make_tl_object<photoCachedSize>(p);
}

photoCachedSize::photoCachedSize(TlBufferParser &p)
  : type_(TlFetchString<string>::parse(p))
  , w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void photoCachedSize::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreString::store(bytes_, s);
}

void photoCachedSize::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreString::store(bytes_, s);
}

void photoCachedSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoCachedSize");
    s.store_field("type", type_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

photoStrippedSize::photoStrippedSize(string const &type_, bytes &&bytes_)
  : type_(type_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t photoStrippedSize::ID;

object_ptr<PhotoSize> photoStrippedSize::fetch(TlBufferParser &p) {
  return make_tl_object<photoStrippedSize>(p);
}

photoStrippedSize::photoStrippedSize(TlBufferParser &p)
  : type_(TlFetchString<string>::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void photoStrippedSize::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreString::store(bytes_, s);
}

void photoStrippedSize::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreString::store(bytes_, s);
}

void photoStrippedSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoStrippedSize");
    s.store_field("type", type_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

photoSizeProgressive::photoSizeProgressive(string const &type_, int32 w_, int32 h_, array<int32> &&sizes_)
  : type_(type_)
  , w_(w_)
  , h_(h_)
  , sizes_(std::move(sizes_))
{}

const std::int32_t photoSizeProgressive::ID;

object_ptr<PhotoSize> photoSizeProgressive::fetch(TlBufferParser &p) {
  return make_tl_object<photoSizeProgressive>(p);
}

photoSizeProgressive::photoSizeProgressive(TlBufferParser &p)
  : type_(TlFetchString<string>::parse(p))
  , w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
  , sizes_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void photoSizeProgressive::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(sizes_, s);
}

void photoSizeProgressive::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(sizes_, s);
}

void photoSizeProgressive::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoSizeProgressive");
    s.store_field("type", type_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    { s.store_vector_begin("sizes", sizes_.size()); for (const auto &_value : sizes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

photoPathSize::photoPathSize(string const &type_, bytes &&bytes_)
  : type_(type_)
  , bytes_(std::move(bytes_))
{}

const std::int32_t photoPathSize::ID;

object_ptr<PhotoSize> photoPathSize::fetch(TlBufferParser &p) {
  return make_tl_object<photoPathSize>(p);
}

photoPathSize::photoPathSize(TlBufferParser &p)
  : type_(TlFetchString<string>::parse(p))
  , bytes_(TlFetchBytes<bytes>::parse(p))
{}

void photoPathSize::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreString::store(bytes_, s);
}

void photoPathSize::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(type_, s);
  TlStoreString::store(bytes_, s);
}

void photoPathSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "photoPathSize");
    s.store_field("type", type_);
    s.store_bytes_field("bytes", bytes_);
    s.store_class_end();
  }
}

pollResults::pollResults()
  : flags_()
  , min_()
  , has_unread_votes_()
  , results_()
  , total_voters_()
  , recent_voters_()
  , solution_()
  , solution_entities_()
  , solution_media_()
{}

pollResults::pollResults(int32 flags_, bool min_, bool has_unread_votes_, array<object_ptr<pollAnswerVoters>> &&results_, int32 total_voters_, array<object_ptr<Peer>> &&recent_voters_, string const &solution_, array<object_ptr<MessageEntity>> &&solution_entities_, object_ptr<MessageMedia> &&solution_media_)
  : flags_(flags_)
  , min_(min_)
  , has_unread_votes_(has_unread_votes_)
  , results_(std::move(results_))
  , total_voters_(total_voters_)
  , recent_voters_(std::move(recent_voters_))
  , solution_(solution_)
  , solution_entities_(std::move(solution_entities_))
  , solution_media_(std::move(solution_media_))
{}

const std::int32_t pollResults::ID;

object_ptr<pollResults> pollResults::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pollResults> res = make_tl_object<pollResults>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->min_ = (var0 & 1) != 0;
  res->has_unread_votes_ = (var0 & 64) != 0;
  if (var0 & 2) { res->results_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<pollAnswerVoters>, 910500618>>, 481674261>::parse(p); }
  if (var0 & 4) { res->total_voters_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->recent_voters_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p); }
  if (var0 & 16) { res->solution_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->solution_entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 32) { res->solution_media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void pollResults::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (min_ << 0) | (has_unread_votes_ << 6)), s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 910500618>>, 481674261>::store(results_, s); }
  if (var0 & 4) { TlStoreBinary::store(total_voters_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(recent_voters_, s); }
  if (var0 & 16) { TlStoreString::store(solution_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(solution_entities_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(solution_media_, s); }
}

void pollResults::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (min_ << 0) | (has_unread_votes_ << 6)), s);
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 910500618>>, 481674261>::store(results_, s); }
  if (var0 & 4) { TlStoreBinary::store(total_voters_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(recent_voters_, s); }
  if (var0 & 16) { TlStoreString::store(solution_, s); }
  if (var0 & 16) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(solution_entities_, s); }
  if (var0 & 32) { TlStoreBoxedUnknown<TlStoreObject>::store(solution_media_, s); }
}

void pollResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollResults");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (min_ << 0) | (has_unread_votes_ << 6)));
    if (var0 & 1) { s.store_field("min", true); }
    if (var0 & 64) { s.store_field("has_unread_votes", true); }
    if (var0 & 2) { { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { s.store_field("total_voters", total_voters_); }
    if (var0 & 8) { { s.store_vector_begin("recent_voters", recent_voters_.size()); for (const auto &_value : recent_voters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("solution", solution_); }
    if (var0 & 16) { { s.store_vector_begin("solution_entities", solution_entities_.size()); for (const auto &_value : solution_entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 32) { s.store_object_field("solution_media", static_cast<const BaseObject *>(solution_media_.get())); }
    s.store_class_end();
  }
}

const std::int32_t popularContact::ID;

object_ptr<popularContact> popularContact::fetch(TlBufferParser &p) {
  return make_tl_object<popularContact>(p);
}

popularContact::popularContact(TlBufferParser &p)
  : client_id_(TlFetchLong::parse(p))
  , importers_(TlFetchInt::parse(p))
{}

void popularContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "popularContact");
    s.store_field("client_id", client_id_);
    s.store_field("importers", importers_);
    s.store_class_end();
  }
}

premiumGiftCodeOption::premiumGiftCodeOption()
  : flags_()
  , users_()
  , months_()
  , store_product_()
  , store_quantity_()
  , currency_()
  , amount_()
{}

premiumGiftCodeOption::premiumGiftCodeOption(int32 flags_, int32 users_, int32 months_, string const &store_product_, int32 store_quantity_, string const &currency_, int64 amount_)
  : flags_(flags_)
  , users_(users_)
  , months_(months_)
  , store_product_(store_product_)
  , store_quantity_(store_quantity_)
  , currency_(currency_)
  , amount_(amount_)
{}

const std::int32_t premiumGiftCodeOption::ID;

object_ptr<premiumGiftCodeOption> premiumGiftCodeOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<premiumGiftCodeOption> res = make_tl_object<premiumGiftCodeOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->users_ = TlFetchInt::parse(p);
  res->months_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->store_product_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->store_quantity_ = TlFetchInt::parse(p); }
  res->currency_ = TlFetchString<string>::parse(p);
  res->amount_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void premiumGiftCodeOption::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(users_, s);
  TlStoreBinary::store(months_, s);
  if (var0 & 1) { TlStoreString::store(store_product_, s); }
  if (var0 & 2) { TlStoreBinary::store(store_quantity_, s); }
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void premiumGiftCodeOption::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(users_, s);
  TlStoreBinary::store(months_, s);
  if (var0 & 1) { TlStoreString::store(store_product_, s); }
  if (var0 & 2) { TlStoreBinary::store(store_quantity_, s); }
  TlStoreString::store(currency_, s);
  TlStoreBinary::store(amount_, s);
}

void premiumGiftCodeOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premiumGiftCodeOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("users", users_);
    s.store_field("months", months_);
    if (var0 & 1) { s.store_field("store_product", store_product_); }
    if (var0 & 2) { s.store_field("store_quantity", store_quantity_); }
    s.store_field("currency", currency_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

object_ptr<PrivacyRule> PrivacyRule::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t privacyValueAllowContacts::ID;

object_ptr<PrivacyRule> privacyValueAllowContacts::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowContacts>();
}

void privacyValueAllowContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueAllowContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueAllowContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowContacts");
    s.store_class_end();
  }
}

const std::int32_t privacyValueAllowAll::ID;

object_ptr<PrivacyRule> privacyValueAllowAll::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowAll>();
}

void privacyValueAllowAll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueAllowAll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueAllowAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowAll");
    s.store_class_end();
  }
}

privacyValueAllowUsers::privacyValueAllowUsers(array<int64> &&users_)
  : users_(std::move(users_))
{}

const std::int32_t privacyValueAllowUsers::ID;

object_ptr<PrivacyRule> privacyValueAllowUsers::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowUsers>(p);
}

privacyValueAllowUsers::privacyValueAllowUsers(TlBufferParser &p)
  : users_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void privacyValueAllowUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(users_, s);
}

void privacyValueAllowUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(users_, s);
}

void privacyValueAllowUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowUsers");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t privacyValueDisallowContacts::ID;

object_ptr<PrivacyRule> privacyValueDisallowContacts::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueDisallowContacts>();
}

void privacyValueDisallowContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueDisallowContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueDisallowContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueDisallowContacts");
    s.store_class_end();
  }
}

const std::int32_t privacyValueDisallowAll::ID;

object_ptr<PrivacyRule> privacyValueDisallowAll::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueDisallowAll>();
}

void privacyValueDisallowAll::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueDisallowAll::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueDisallowAll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueDisallowAll");
    s.store_class_end();
  }
}

privacyValueDisallowUsers::privacyValueDisallowUsers(array<int64> &&users_)
  : users_(std::move(users_))
{}

const std::int32_t privacyValueDisallowUsers::ID;

object_ptr<PrivacyRule> privacyValueDisallowUsers::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueDisallowUsers>(p);
}

privacyValueDisallowUsers::privacyValueDisallowUsers(TlBufferParser &p)
  : users_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void privacyValueDisallowUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(users_, s);
}

void privacyValueDisallowUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(users_, s);
}

void privacyValueDisallowUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueDisallowUsers");
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

privacyValueAllowChatParticipants::privacyValueAllowChatParticipants(array<int64> &&chats_)
  : chats_(std::move(chats_))
{}

const std::int32_t privacyValueAllowChatParticipants::ID;

object_ptr<PrivacyRule> privacyValueAllowChatParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowChatParticipants>(p);
}

privacyValueAllowChatParticipants::privacyValueAllowChatParticipants(TlBufferParser &p)
  : chats_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void privacyValueAllowChatParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void privacyValueAllowChatParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void privacyValueAllowChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowChatParticipants");
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

privacyValueDisallowChatParticipants::privacyValueDisallowChatParticipants(array<int64> &&chats_)
  : chats_(std::move(chats_))
{}

const std::int32_t privacyValueDisallowChatParticipants::ID;

object_ptr<PrivacyRule> privacyValueDisallowChatParticipants::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueDisallowChatParticipants>(p);
}

privacyValueDisallowChatParticipants::privacyValueDisallowChatParticipants(TlBufferParser &p)
  : chats_(TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p))
{}

void privacyValueDisallowChatParticipants::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void privacyValueDisallowChatParticipants::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(chats_, s);
}

void privacyValueDisallowChatParticipants::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueDisallowChatParticipants");
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t privacyValueAllowCloseFriends::ID;

object_ptr<PrivacyRule> privacyValueAllowCloseFriends::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowCloseFriends>();
}

void privacyValueAllowCloseFriends::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueAllowCloseFriends::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueAllowCloseFriends::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowCloseFriends");
    s.store_class_end();
  }
}

const std::int32_t privacyValueAllowPremium::ID;

object_ptr<PrivacyRule> privacyValueAllowPremium::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowPremium>();
}

void privacyValueAllowPremium::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueAllowPremium::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueAllowPremium::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowPremium");
    s.store_class_end();
  }
}

const std::int32_t privacyValueAllowBots::ID;

object_ptr<PrivacyRule> privacyValueAllowBots::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueAllowBots>();
}

void privacyValueAllowBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueAllowBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueAllowBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueAllowBots");
    s.store_class_end();
  }
}

const std::int32_t privacyValueDisallowBots::ID;

object_ptr<PrivacyRule> privacyValueDisallowBots::fetch(TlBufferParser &p) {
  return make_tl_object<privacyValueDisallowBots>();
}

void privacyValueDisallowBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void privacyValueDisallowBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void privacyValueDisallowBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "privacyValueDisallowBots");
    s.store_class_end();
  }
}

object_ptr<PublicForward> PublicForward::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case publicForwardMessage::ID:
      return publicForwardMessage::fetch(p);
    case publicForwardStory::ID:
      return publicForwardStory::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t publicForwardMessage::ID;

object_ptr<PublicForward> publicForwardMessage::fetch(TlBufferParser &p) {
  return make_tl_object<publicForwardMessage>(p);
}

publicForwardMessage::publicForwardMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void publicForwardMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicForwardMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t publicForwardStory::ID;

object_ptr<PublicForward> publicForwardStory::fetch(TlBufferParser &p) {
  return make_tl_object<publicForwardStory>(p);
}

publicForwardStory::publicForwardStory(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , story_(TlFetchObject<StoryItem>::parse(p))
{}

void publicForwardStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "publicForwardStory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

reactionCount::reactionCount()
  : flags_()
  , chosen_order_()
  , reaction_()
  , count_()
{}

reactionCount::reactionCount(int32 flags_, int32 chosen_order_, object_ptr<Reaction> &&reaction_, int32 count_)
  : flags_(flags_)
  , chosen_order_(chosen_order_)
  , reaction_(std::move(reaction_))
  , count_(count_)
{}

const std::int32_t reactionCount::ID;

object_ptr<reactionCount> reactionCount::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<reactionCount> res = make_tl_object<reactionCount>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->chosen_order_ = TlFetchInt::parse(p); }
  res->reaction_ = TlFetchObject<Reaction>::parse(p);
  res->count_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void reactionCount::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(chosen_order_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
  TlStoreBinary::store(count_, s);
}

void reactionCount::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBinary::store(chosen_order_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
  TlStoreBinary::store(count_, s);
}

void reactionCount::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionCount");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("chosen_order", chosen_order_); }
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_field("count", count_);
    s.store_class_end();
  }
}

searchPostsFlood::searchPostsFlood()
  : flags_()
  , query_is_free_()
  , total_daily_()
  , remains_()
  , wait_till_()
  , stars_amount_()
{}

const std::int32_t searchPostsFlood::ID;

object_ptr<searchPostsFlood> searchPostsFlood::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<searchPostsFlood> res = make_tl_object<searchPostsFlood>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->query_is_free_ = (var0 & 1) != 0;
  res->total_daily_ = TlFetchInt::parse(p);
  res->remains_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->wait_till_ = TlFetchInt::parse(p); }
  res->stars_amount_ = TlFetchLong::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void searchPostsFlood::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "searchPostsFlood");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (query_is_free_ << 0)));
    if (var0 & 1) { s.store_field("query_is_free", true); }
    s.store_field("total_daily", total_daily_);
    s.store_field("remains", remains_);
    if (var0 & 2) { s.store_field("wait_till", wait_till_); }
    s.store_field("stars_amount", stars_amount_);
    s.store_class_end();
  }
}

object_ptr<SendMessageAction> SendMessageAction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t sendMessageTypingAction::ID;

object_ptr<SendMessageAction> sendMessageTypingAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageTypingAction>();
}

void sendMessageTypingAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageTypingAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageTypingAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageTypingAction");
    s.store_class_end();
  }
}

const std::int32_t sendMessageCancelAction::ID;

object_ptr<SendMessageAction> sendMessageCancelAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageCancelAction>();
}

void sendMessageCancelAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageCancelAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageCancelAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageCancelAction");
    s.store_class_end();
  }
}

const std::int32_t sendMessageRecordVideoAction::ID;

object_ptr<SendMessageAction> sendMessageRecordVideoAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageRecordVideoAction>();
}

void sendMessageRecordVideoAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageRecordVideoAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageRecordVideoAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageRecordVideoAction");
    s.store_class_end();
  }
}

sendMessageUploadVideoAction::sendMessageUploadVideoAction(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t sendMessageUploadVideoAction::ID;

object_ptr<SendMessageAction> sendMessageUploadVideoAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageUploadVideoAction>(p);
}

sendMessageUploadVideoAction::sendMessageUploadVideoAction(TlBufferParser &p)
  : progress_(TlFetchInt::parse(p))
{}

void sendMessageUploadVideoAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadVideoAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadVideoAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageUploadVideoAction");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

const std::int32_t sendMessageRecordAudioAction::ID;

object_ptr<SendMessageAction> sendMessageRecordAudioAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageRecordAudioAction>();
}

void sendMessageRecordAudioAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageRecordAudioAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageRecordAudioAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageRecordAudioAction");
    s.store_class_end();
  }
}

sendMessageUploadAudioAction::sendMessageUploadAudioAction(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t sendMessageUploadAudioAction::ID;

object_ptr<SendMessageAction> sendMessageUploadAudioAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageUploadAudioAction>(p);
}

sendMessageUploadAudioAction::sendMessageUploadAudioAction(TlBufferParser &p)
  : progress_(TlFetchInt::parse(p))
{}

void sendMessageUploadAudioAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadAudioAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadAudioAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageUploadAudioAction");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

sendMessageUploadPhotoAction::sendMessageUploadPhotoAction(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t sendMessageUploadPhotoAction::ID;

object_ptr<SendMessageAction> sendMessageUploadPhotoAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageUploadPhotoAction>(p);
}

sendMessageUploadPhotoAction::sendMessageUploadPhotoAction(TlBufferParser &p)
  : progress_(TlFetchInt::parse(p))
{}

void sendMessageUploadPhotoAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadPhotoAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadPhotoAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageUploadPhotoAction");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

sendMessageUploadDocumentAction::sendMessageUploadDocumentAction(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t sendMessageUploadDocumentAction::ID;

object_ptr<SendMessageAction> sendMessageUploadDocumentAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageUploadDocumentAction>(p);
}

sendMessageUploadDocumentAction::sendMessageUploadDocumentAction(TlBufferParser &p)
  : progress_(TlFetchInt::parse(p))
{}

void sendMessageUploadDocumentAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadDocumentAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadDocumentAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageUploadDocumentAction");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

const std::int32_t sendMessageGeoLocationAction::ID;

object_ptr<SendMessageAction> sendMessageGeoLocationAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageGeoLocationAction>();
}

void sendMessageGeoLocationAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageGeoLocationAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageGeoLocationAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageGeoLocationAction");
    s.store_class_end();
  }
}

const std::int32_t sendMessageChooseContactAction::ID;

object_ptr<SendMessageAction> sendMessageChooseContactAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageChooseContactAction>();
}

void sendMessageChooseContactAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageChooseContactAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageChooseContactAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageChooseContactAction");
    s.store_class_end();
  }
}

const std::int32_t sendMessageGamePlayAction::ID;

object_ptr<SendMessageAction> sendMessageGamePlayAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageGamePlayAction>();
}

void sendMessageGamePlayAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageGamePlayAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageGamePlayAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageGamePlayAction");
    s.store_class_end();
  }
}

const std::int32_t sendMessageRecordRoundAction::ID;

object_ptr<SendMessageAction> sendMessageRecordRoundAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageRecordRoundAction>();
}

void sendMessageRecordRoundAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageRecordRoundAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageRecordRoundAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageRecordRoundAction");
    s.store_class_end();
  }
}

sendMessageUploadRoundAction::sendMessageUploadRoundAction(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t sendMessageUploadRoundAction::ID;

object_ptr<SendMessageAction> sendMessageUploadRoundAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageUploadRoundAction>(p);
}

sendMessageUploadRoundAction::sendMessageUploadRoundAction(TlBufferParser &p)
  : progress_(TlFetchInt::parse(p))
{}

void sendMessageUploadRoundAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadRoundAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageUploadRoundAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageUploadRoundAction");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

const std::int32_t speakingInGroupCallAction::ID;

object_ptr<SendMessageAction> speakingInGroupCallAction::fetch(TlBufferParser &p) {
  return make_tl_object<speakingInGroupCallAction>();
}

void speakingInGroupCallAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void speakingInGroupCallAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void speakingInGroupCallAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "speakingInGroupCallAction");
    s.store_class_end();
  }
}

sendMessageHistoryImportAction::sendMessageHistoryImportAction(int32 progress_)
  : progress_(progress_)
{}

const std::int32_t sendMessageHistoryImportAction::ID;

object_ptr<SendMessageAction> sendMessageHistoryImportAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageHistoryImportAction>(p);
}

sendMessageHistoryImportAction::sendMessageHistoryImportAction(TlBufferParser &p)
  : progress_(TlFetchInt::parse(p))
{}

void sendMessageHistoryImportAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageHistoryImportAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(progress_, s);
}

void sendMessageHistoryImportAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageHistoryImportAction");
    s.store_field("progress", progress_);
    s.store_class_end();
  }
}

const std::int32_t sendMessageChooseStickerAction::ID;

object_ptr<SendMessageAction> sendMessageChooseStickerAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageChooseStickerAction>();
}

void sendMessageChooseStickerAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void sendMessageChooseStickerAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void sendMessageChooseStickerAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageChooseStickerAction");
    s.store_class_end();
  }
}

sendMessageEmojiInteraction::sendMessageEmojiInteraction(string const &emoticon_, int32 msg_id_, object_ptr<dataJSON> &&interaction_)
  : emoticon_(emoticon_)
  , msg_id_(msg_id_)
  , interaction_(std::move(interaction_))
{}

const std::int32_t sendMessageEmojiInteraction::ID;

object_ptr<SendMessageAction> sendMessageEmojiInteraction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageEmojiInteraction>(p);
}

sendMessageEmojiInteraction::sendMessageEmojiInteraction(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
  , interaction_(TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p))
{}

void sendMessageEmojiInteraction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(interaction_, s);
}

void sendMessageEmojiInteraction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(interaction_, s);
}

void sendMessageEmojiInteraction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageEmojiInteraction");
    s.store_field("emoticon", emoticon_);
    s.store_field("msg_id", msg_id_);
    s.store_object_field("interaction", static_cast<const BaseObject *>(interaction_.get()));
    s.store_class_end();
  }
}

sendMessageEmojiInteractionSeen::sendMessageEmojiInteractionSeen(string const &emoticon_)
  : emoticon_(emoticon_)
{}

const std::int32_t sendMessageEmojiInteractionSeen::ID;

object_ptr<SendMessageAction> sendMessageEmojiInteractionSeen::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageEmojiInteractionSeen>(p);
}

sendMessageEmojiInteractionSeen::sendMessageEmojiInteractionSeen(TlBufferParser &p)
  : emoticon_(TlFetchString<string>::parse(p))
{}

void sendMessageEmojiInteractionSeen::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void sendMessageEmojiInteractionSeen::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(emoticon_, s);
}

void sendMessageEmojiInteractionSeen::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageEmojiInteractionSeen");
    s.store_field("emoticon", emoticon_);
    s.store_class_end();
  }
}

sendMessageTextDraftAction::sendMessageTextDraftAction(int64 random_id_, object_ptr<textWithEntities> &&text_)
  : random_id_(random_id_)
  , text_(std::move(text_))
{}

const std::int32_t sendMessageTextDraftAction::ID;

object_ptr<SendMessageAction> sendMessageTextDraftAction::fetch(TlBufferParser &p) {
  return make_tl_object<sendMessageTextDraftAction>(p);
}

sendMessageTextDraftAction::sendMessageTextDraftAction(TlBufferParser &p)
  : random_id_(TlFetchLong::parse(p))
  , text_(TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p))
{}

void sendMessageTextDraftAction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(random_id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
}

void sendMessageTextDraftAction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(random_id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
}

void sendMessageTextDraftAction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sendMessageTextDraftAction");
    s.store_field("random_id", random_id_);
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

object_ptr<StickerSetCovered> StickerSetCovered::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case stickerSetCovered::ID:
      return stickerSetCovered::fetch(p);
    case stickerSetMultiCovered::ID:
      return stickerSetMultiCovered::fetch(p);
    case stickerSetFullCovered::ID:
      return stickerSetFullCovered::fetch(p);
    case stickerSetNoCovered::ID:
      return stickerSetNoCovered::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t stickerSetCovered::ID;

object_ptr<StickerSetCovered> stickerSetCovered::fetch(TlBufferParser &p) {
  return make_tl_object<stickerSetCovered>(p);
}

stickerSetCovered::stickerSetCovered(TlBufferParser &p)
  : set_(TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p))
  , cover_(TlFetchObject<Document>::parse(p))
{}

void stickerSetCovered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSetCovered");
    s.store_object_field("set", static_cast<const BaseObject *>(set_.get()));
    s.store_object_field("cover", static_cast<const BaseObject *>(cover_.get()));
    s.store_class_end();
  }
}

const std::int32_t stickerSetMultiCovered::ID;

object_ptr<StickerSetCovered> stickerSetMultiCovered::fetch(TlBufferParser &p) {
  return make_tl_object<stickerSetMultiCovered>(p);
}

stickerSetMultiCovered::stickerSetMultiCovered(TlBufferParser &p)
  : set_(TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p))
  , covers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void stickerSetMultiCovered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSetMultiCovered");
    s.store_object_field("set", static_cast<const BaseObject *>(set_.get()));
    { s.store_vector_begin("covers", covers_.size()); for (const auto &_value : covers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stickerSetFullCovered::ID;

object_ptr<StickerSetCovered> stickerSetFullCovered::fetch(TlBufferParser &p) {
  return make_tl_object<stickerSetFullCovered>(p);
}

stickerSetFullCovered::stickerSetFullCovered(TlBufferParser &p)
  : set_(TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p))
  , packs_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerPack>, 313694676>>, 481674261>::parse(p))
  , keywords_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerKeyword>, -50416996>>, 481674261>::parse(p))
  , documents_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void stickerSetFullCovered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSetFullCovered");
    s.store_object_field("set", static_cast<const BaseObject *>(set_.get()));
    { s.store_vector_begin("packs", packs_.size()); for (const auto &_value : packs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("keywords", keywords_.size()); for (const auto &_value : keywords_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stickerSetNoCovered::ID;

object_ptr<StickerSetCovered> stickerSetNoCovered::fetch(TlBufferParser &p) {
  return make_tl_object<stickerSetNoCovered>(p);
}

stickerSetNoCovered::stickerSetNoCovered(TlBufferParser &p)
  : set_(TlFetchBoxed<TlFetchObject<stickerSet>, 768691932>::parse(p))
{}

void stickerSetNoCovered::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickerSetNoCovered");
    s.store_object_field("set", static_cast<const BaseObject *>(set_.get()));
    s.store_class_end();
  }
}

object_ptr<StoryItem> StoryItem::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case storyItemDeleted::ID:
      return storyItemDeleted::fetch(p);
    case storyItemSkipped::ID:
      return storyItemSkipped::fetch(p);
    case storyItem::ID:
      return storyItem::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

storyItemDeleted::storyItemDeleted(int32 id_)
  : id_(id_)
{}

const std::int32_t storyItemDeleted::ID;

object_ptr<StoryItem> storyItemDeleted::fetch(TlBufferParser &p) {
  return make_tl_object<storyItemDeleted>(p);
}

storyItemDeleted::storyItemDeleted(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
{}

void storyItemDeleted::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void storyItemDeleted::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void storyItemDeleted::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyItemDeleted");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

storyItemSkipped::storyItemSkipped()
  : flags_()
  , close_friends_()
  , live_()
  , id_()
  , date_()
  , expire_date_()
{}

storyItemSkipped::storyItemSkipped(int32 flags_, bool close_friends_, bool live_, int32 id_, int32 date_, int32 expire_date_)
  : flags_(flags_)
  , close_friends_(close_friends_)
  , live_(live_)
  , id_(id_)
  , date_(date_)
  , expire_date_(expire_date_)
{}

const std::int32_t storyItemSkipped::ID;

object_ptr<StoryItem> storyItemSkipped::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyItemSkipped> res = make_tl_object<storyItemSkipped>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->close_friends_ = (var0 & 256) != 0;
  res->live_ = (var0 & 512) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->expire_date_ = TlFetchInt::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void storyItemSkipped::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (close_friends_ << 8) | (live_ << 9)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBinary::store(expire_date_, s);
}

void storyItemSkipped::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (close_friends_ << 8) | (live_ << 9)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(date_, s);
  TlStoreBinary::store(expire_date_, s);
}

void storyItemSkipped::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyItemSkipped");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (close_friends_ << 8) | (live_ << 9)));
    if (var0 & 256) { s.store_field("close_friends", true); }
    if (var0 & 512) { s.store_field("live", true); }
    s.store_field("id", id_);
    s.store_field("date", date_);
    s.store_field("expire_date", expire_date_);
    s.store_class_end();
  }
}

storyItem::storyItem()
  : flags_()
  , pinned_()
  , public_()
  , close_friends_()
  , min_()
  , noforwards_()
  , edited_()
  , contacts_()
  , selected_contacts_()
  , out_()
  , id_()
  , date_()
  , from_id_()
  , fwd_from_()
  , expire_date_()
  , caption_()
  , entities_()
  , media_()
  , media_areas_()
  , privacy_()
  , views_()
  , sent_reaction_()
  , albums_()
  , music_()
{}

storyItem::storyItem(int32 flags_, bool pinned_, bool public_, bool close_friends_, bool min_, bool noforwards_, bool edited_, bool contacts_, bool selected_contacts_, bool out_, int32 id_, int32 date_, object_ptr<Peer> &&from_id_, object_ptr<storyFwdHeader> &&fwd_from_, int32 expire_date_, string const &caption_, array<object_ptr<MessageEntity>> &&entities_, object_ptr<MessageMedia> &&media_, array<object_ptr<MediaArea>> &&media_areas_, array<object_ptr<PrivacyRule>> &&privacy_, object_ptr<storyViews> &&views_, object_ptr<Reaction> &&sent_reaction_, array<int32> &&albums_, object_ptr<Document> &&music_)
  : flags_(flags_)
  , pinned_(pinned_)
  , public_(public_)
  , close_friends_(close_friends_)
  , min_(min_)
  , noforwards_(noforwards_)
  , edited_(edited_)
  , contacts_(contacts_)
  , selected_contacts_(selected_contacts_)
  , out_(out_)
  , id_(id_)
  , date_(date_)
  , from_id_(std::move(from_id_))
  , fwd_from_(std::move(fwd_from_))
  , expire_date_(expire_date_)
  , caption_(caption_)
  , entities_(std::move(entities_))
  , media_(std::move(media_))
  , media_areas_(std::move(media_areas_))
  , privacy_(std::move(privacy_))
  , views_(std::move(views_))
  , sent_reaction_(std::move(sent_reaction_))
  , albums_(std::move(albums_))
  , music_(std::move(music_))
{}

const std::int32_t storyItem::ID;

object_ptr<StoryItem> storyItem::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyItem> res = make_tl_object<storyItem>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->pinned_ = (var0 & 32) != 0;
  res->public_ = (var0 & 128) != 0;
  res->close_friends_ = (var0 & 256) != 0;
  res->min_ = (var0 & 512) != 0;
  res->noforwards_ = (var0 & 1024) != 0;
  res->edited_ = (var0 & 2048) != 0;
  res->contacts_ = (var0 & 4096) != 0;
  res->selected_contacts_ = (var0 & 8192) != 0;
  res->out_ = (var0 & 65536) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 262144) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 131072) { res->fwd_from_ = TlFetchBoxed<TlFetchObject<storyFwdHeader>, -1205411504>::parse(p); }
  res->expire_date_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->caption_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  res->media_ = TlFetchObject<MessageMedia>::parse(p);
  if (var0 & 16384) { res->media_areas_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MediaArea>>, 481674261>::parse(p); }
  if (var0 & 4) { res->privacy_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PrivacyRule>>, 481674261>::parse(p); }
  if (var0 & 8) { res->views_ = TlFetchBoxed<TlFetchObject<storyViews>, -1923523370>::parse(p); }
  if (var0 & 32768) { res->sent_reaction_ = TlFetchObject<Reaction>::parse(p); }
  if (var0 & 524288) { res->albums_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (var0 & 1048576) { res->music_ = TlFetchObject<Document>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void storyItem::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 5) | (public_ << 7) | (close_friends_ << 8) | (min_ << 9) | (noforwards_ << 10) | (edited_ << 11) | (contacts_ << 12) | (selected_contacts_ << 13) | (out_ << 16)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 262144) { TlStoreBoxedUnknown<TlStoreObject>::store(from_id_, s); }
  if (var0 & 131072) { TlStoreBoxed<TlStoreObject, -1205411504>::store(fwd_from_, s); }
  TlStoreBinary::store(expire_date_, s);
  if (var0 & 1) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  if (var0 & 16384) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_areas_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, -1923523370>::store(views_, s); }
  if (var0 & 32768) { TlStoreBoxedUnknown<TlStoreObject>::store(sent_reaction_, s); }
  if (var0 & 524288) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(albums_, s); }
  if (var0 & 1048576) { TlStoreBoxedUnknown<TlStoreObject>::store(music_, s); }
}

void storyItem::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 5) | (public_ << 7) | (close_friends_ << 8) | (min_ << 9) | (noforwards_ << 10) | (edited_ << 11) | (contacts_ << 12) | (selected_contacts_ << 13) | (out_ << 16)), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(date_, s);
  if (var0 & 262144) { TlStoreBoxedUnknown<TlStoreObject>::store(from_id_, s); }
  if (var0 & 131072) { TlStoreBoxed<TlStoreObject, -1205411504>::store(fwd_from_, s); }
  TlStoreBinary::store(expire_date_, s);
  if (var0 & 1) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  if (var0 & 16384) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_areas_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, -1923523370>::store(views_, s); }
  if (var0 & 32768) { TlStoreBoxedUnknown<TlStoreObject>::store(sent_reaction_, s); }
  if (var0 & 524288) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(albums_, s); }
  if (var0 & 1048576) { TlStoreBoxedUnknown<TlStoreObject>::store(music_, s); }
}

void storyItem::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyItem");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (pinned_ << 5) | (public_ << 7) | (close_friends_ << 8) | (min_ << 9) | (noforwards_ << 10) | (edited_ << 11) | (contacts_ << 12) | (selected_contacts_ << 13) | (out_ << 16)));
    if (var0 & 32) { s.store_field("pinned", true); }
    if (var0 & 128) { s.store_field("public", true); }
    if (var0 & 256) { s.store_field("close_friends", true); }
    if (var0 & 512) { s.store_field("min", true); }
    if (var0 & 1024) { s.store_field("noforwards", true); }
    if (var0 & 2048) { s.store_field("edited", true); }
    if (var0 & 4096) { s.store_field("contacts", true); }
    if (var0 & 8192) { s.store_field("selected_contacts", true); }
    if (var0 & 65536) { s.store_field("out", true); }
    s.store_field("id", id_);
    s.store_field("date", date_);
    if (var0 & 262144) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 131072) { s.store_object_field("fwd_from", static_cast<const BaseObject *>(fwd_from_.get())); }
    s.store_field("expire_date", expire_date_);
    if (var0 & 1) { s.store_field("caption", caption_); }
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    if (var0 & 16384) { { s.store_vector_begin("media_areas", media_areas_.size()); for (const auto &_value : media_areas_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("privacy", privacy_.size()); for (const auto &_value : privacy_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 8) { s.store_object_field("views", static_cast<const BaseObject *>(views_.get())); }
    if (var0 & 32768) { s.store_object_field("sent_reaction", static_cast<const BaseObject *>(sent_reaction_.get())); }
    if (var0 & 524288) { { s.store_vector_begin("albums", albums_.size()); for (const auto &_value : albums_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 1048576) { s.store_object_field("music", static_cast<const BaseObject *>(music_.get())); }
    s.store_class_end();
  }
}

object_ptr<StoryReaction> StoryReaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case storyReaction::ID:
      return storyReaction::fetch(p);
    case storyReactionPublicForward::ID:
      return storyReactionPublicForward::fetch(p);
    case storyReactionPublicRepost::ID:
      return storyReactionPublicRepost::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t storyReaction::ID;

object_ptr<StoryReaction> storyReaction::fetch(TlBufferParser &p) {
  return make_tl_object<storyReaction>(p);
}

storyReaction::storyReaction(TlBufferParser &p)
  : peer_id_(TlFetchObject<Peer>::parse(p))
  , date_(TlFetchInt::parse(p))
  , reaction_(TlFetchObject<Reaction>::parse(p))
{}

void storyReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyReaction");
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    s.store_field("date", date_);
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

const std::int32_t storyReactionPublicForward::ID;

object_ptr<StoryReaction> storyReactionPublicForward::fetch(TlBufferParser &p) {
  return make_tl_object<storyReactionPublicForward>(p);
}

storyReactionPublicForward::storyReactionPublicForward(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void storyReactionPublicForward::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyReactionPublicForward");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t storyReactionPublicRepost::ID;

object_ptr<StoryReaction> storyReactionPublicRepost::fetch(TlBufferParser &p) {
  return make_tl_object<storyReactionPublicRepost>(p);
}

storyReactionPublicRepost::storyReactionPublicRepost(TlBufferParser &p)
  : peer_id_(TlFetchObject<Peer>::parse(p))
  , story_(TlFetchObject<StoryItem>::parse(p))
{}

void storyReactionPublicRepost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyReactionPublicRepost");
    s.store_object_field("peer_id", static_cast<const BaseObject *>(peer_id_.get()));
    s.store_object_field("story", static_cast<const BaseObject *>(story_.get()));
    s.store_class_end();
  }
}

storyViews::storyViews()
  : flags_()
  , has_viewers_()
  , views_count_()
  , forwards_count_()
  , reactions_()
  , reactions_count_()
  , recent_viewers_()
{}

storyViews::storyViews(int32 flags_, bool has_viewers_, int32 views_count_, int32 forwards_count_, array<object_ptr<reactionCount>> &&reactions_, int32 reactions_count_, array<int64> &&recent_viewers_)
  : flags_(flags_)
  , has_viewers_(has_viewers_)
  , views_count_(views_count_)
  , forwards_count_(forwards_count_)
  , reactions_(std::move(reactions_))
  , reactions_count_(reactions_count_)
  , recent_viewers_(std::move(recent_viewers_))
{}

const std::int32_t storyViews::ID;

object_ptr<storyViews> storyViews::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<storyViews> res = make_tl_object<storyViews>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->has_viewers_ = (var0 & 2) != 0;
  res->views_count_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->forwards_count_ = TlFetchInt::parse(p); }
  if (var0 & 8) { res->reactions_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<reactionCount>, -1546531968>>, 481674261>::parse(p); }
  if (var0 & 16) { res->reactions_count_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->recent_viewers_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void storyViews::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_viewers_ << 1)), s);
  TlStoreBinary::store(views_count_, s);
  if (var0 & 4) { TlStoreBinary::store(forwards_count_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1546531968>>, 481674261>::store(reactions_, s); }
  if (var0 & 16) { TlStoreBinary::store(reactions_count_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(recent_viewers_, s); }
}

void storyViews::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (has_viewers_ << 1)), s);
  TlStoreBinary::store(views_count_, s);
  if (var0 & 4) { TlStoreBinary::store(forwards_count_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -1546531968>>, 481674261>::store(reactions_, s); }
  if (var0 & 16) { TlStoreBinary::store(reactions_count_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(recent_viewers_, s); }
}

void storyViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "storyViews");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (has_viewers_ << 1)));
    if (var0 & 2) { s.store_field("has_viewers", true); }
    s.store_field("views_count", views_count_);
    if (var0 & 4) { s.store_field("forwards_count", forwards_count_); }
    if (var0 & 8) { { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { s.store_field("reactions_count", reactions_count_); }
    if (var0 & 1) { { s.store_vector_begin("recent_viewers", recent_viewers_.size()); for (const auto &_value : recent_viewers_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_class_end();
  }
}

suggestedPost::suggestedPost()
  : flags_()
  , accepted_()
  , rejected_()
  , price_()
  , schedule_date_()
{}

suggestedPost::suggestedPost(int32 flags_, bool accepted_, bool rejected_, object_ptr<StarsAmount> &&price_, int32 schedule_date_)
  : flags_(flags_)
  , accepted_(accepted_)
  , rejected_(rejected_)
  , price_(std::move(price_))
  , schedule_date_(schedule_date_)
{}

const std::int32_t suggestedPost::ID;

object_ptr<suggestedPost> suggestedPost::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<suggestedPost> res = make_tl_object<suggestedPost>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->accepted_ = (var0 & 2) != 0;
  res->rejected_ = (var0 & 4) != 0;
  if (var0 & 8) { res->price_ = TlFetchObject<StarsAmount>::parse(p); }
  if (var0 & 1) { res->schedule_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void suggestedPost::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (accepted_ << 1) | (rejected_ << 2)), s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(price_, s); }
  if (var0 & 1) { TlStoreBinary::store(schedule_date_, s); }
}

void suggestedPost::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (accepted_ << 1) | (rejected_ << 2)), s);
  if (var0 & 8) { TlStoreBoxedUnknown<TlStoreObject>::store(price_, s); }
  if (var0 & 1) { TlStoreBinary::store(schedule_date_, s); }
}

void suggestedPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "suggestedPost");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (accepted_ << 1) | (rejected_ << 2)));
    if (var0 & 2) { s.store_field("accepted", true); }
    if (var0 & 4) { s.store_field("rejected", true); }
    if (var0 & 8) { s.store_object_field("price", static_cast<const BaseObject *>(price_.get())); }
    if (var0 & 1) { s.store_field("schedule_date", schedule_date_); }
    s.store_class_end();
  }
}

todoItem::todoItem(int32 id_, object_ptr<textWithEntities> &&title_)
  : id_(id_)
  , title_(std::move(title_))
{}

const std::int32_t todoItem::ID;

object_ptr<todoItem> todoItem::fetch(TlBufferParser &p) {
  return make_tl_object<todoItem>(p);
}

todoItem::todoItem(TlBufferParser &p)
  : id_(TlFetchInt::parse(p))
  , title_(TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p))
{}

void todoItem::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
}

void todoItem::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(title_, s);
}

void todoItem::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "todoItem");
    s.store_field("id", id_);
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    s.store_class_end();
  }
}

object_ptr<WebPageAttribute> WebPageAttribute::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

webPageAttributeTheme::webPageAttributeTheme()
  : flags_()
  , documents_()
  , settings_()
{}

webPageAttributeTheme::webPageAttributeTheme(int32 flags_, array<object_ptr<Document>> &&documents_, object_ptr<themeSettings> &&settings_)
  : flags_(flags_)
  , documents_(std::move(documents_))
  , settings_(std::move(settings_))
{}

const std::int32_t webPageAttributeTheme::ID;

object_ptr<WebPageAttribute> webPageAttributeTheme::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPageAttributeTheme> res = make_tl_object<webPageAttributeTheme>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->documents_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p); }
  if (var0 & 2) { res->settings_ = TlFetchBoxed<TlFetchObject<themeSettings>, -94849324>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPageAttributeTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, -94849324>::store(settings_, s); }
}

void webPageAttributeTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(documents_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, -94849324>::store(settings_, s); }
}

void webPageAttributeTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeTheme");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get())); }
    s.store_class_end();
  }
}

webPageAttributeStory::webPageAttributeStory()
  : flags_()
  , peer_()
  , id_()
  , story_()
{}

webPageAttributeStory::webPageAttributeStory(int32 flags_, object_ptr<Peer> &&peer_, int32 id_, object_ptr<StoryItem> &&story_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(id_)
  , story_(std::move(story_))
{}

const std::int32_t webPageAttributeStory::ID;

object_ptr<WebPageAttribute> webPageAttributeStory::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPageAttributeStory> res = make_tl_object<webPageAttributeStory>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->peer_ = TlFetchObject<Peer>::parse(p);
  res->id_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->story_ = TlFetchObject<StoryItem>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPageAttributeStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(story_, s); }
}

void webPageAttributeStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(story_, s); }
}

void webPageAttributeStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeStory");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("story", static_cast<const BaseObject *>(story_.get())); }
    s.store_class_end();
  }
}

webPageAttributeStickerSet::webPageAttributeStickerSet()
  : flags_()
  , emojis_()
  , text_color_()
  , stickers_()
{}

webPageAttributeStickerSet::webPageAttributeStickerSet(int32 flags_, bool emojis_, bool text_color_, array<object_ptr<Document>> &&stickers_)
  : flags_(flags_)
  , emojis_(emojis_)
  , text_color_(text_color_)
  , stickers_(std::move(stickers_))
{}

const std::int32_t webPageAttributeStickerSet::ID;

object_ptr<WebPageAttribute> webPageAttributeStickerSet::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<webPageAttributeStickerSet> res = make_tl_object<webPageAttributeStickerSet>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->emojis_ = (var0 & 1) != 0;
  res->text_color_ = (var0 & 2) != 0;
  res->stickers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void webPageAttributeStickerSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (emojis_ << 0) | (text_color_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickers_, s);
}

void webPageAttributeStickerSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (emojis_ << 0) | (text_color_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickers_, s);
}

void webPageAttributeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeStickerSet");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (emojis_ << 0) | (text_color_ << 1)));
    if (var0 & 1) { s.store_field("emojis", true); }
    if (var0 & 2) { s.store_field("text_color", true); }
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

webPageAttributeUniqueStarGift::webPageAttributeUniqueStarGift(object_ptr<StarGift> &&gift_)
  : gift_(std::move(gift_))
{}

const std::int32_t webPageAttributeUniqueStarGift::ID;

object_ptr<WebPageAttribute> webPageAttributeUniqueStarGift::fetch(TlBufferParser &p) {
  return make_tl_object<webPageAttributeUniqueStarGift>(p);
}

webPageAttributeUniqueStarGift::webPageAttributeUniqueStarGift(TlBufferParser &p)
  : gift_(TlFetchObject<StarGift>::parse(p))
{}

void webPageAttributeUniqueStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(gift_, s);
}

void webPageAttributeUniqueStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(gift_, s);
}

void webPageAttributeUniqueStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeUniqueStarGift");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_class_end();
  }
}

webPageAttributeStarGiftCollection::webPageAttributeStarGiftCollection(array<object_ptr<Document>> &&icons_)
  : icons_(std::move(icons_))
{}

const std::int32_t webPageAttributeStarGiftCollection::ID;

object_ptr<WebPageAttribute> webPageAttributeStarGiftCollection::fetch(TlBufferParser &p) {
  return make_tl_object<webPageAttributeStarGiftCollection>(p);
}

webPageAttributeStarGiftCollection::webPageAttributeStarGiftCollection(TlBufferParser &p)
  : icons_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void webPageAttributeStarGiftCollection::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(icons_, s);
}

void webPageAttributeStarGiftCollection::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(icons_, s);
}

void webPageAttributeStarGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeStarGiftCollection");
    { s.store_vector_begin("icons", icons_.size()); for (const auto &_value : icons_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

webPageAttributeStarGiftAuction::webPageAttributeStarGiftAuction(object_ptr<StarGift> &&gift_, int32 end_date_)
  : gift_(std::move(gift_))
  , end_date_(end_date_)
{}

const std::int32_t webPageAttributeStarGiftAuction::ID;

object_ptr<WebPageAttribute> webPageAttributeStarGiftAuction::fetch(TlBufferParser &p) {
  return make_tl_object<webPageAttributeStarGiftAuction>(p);
}

webPageAttributeStarGiftAuction::webPageAttributeStarGiftAuction(TlBufferParser &p)
  : gift_(TlFetchObject<StarGift>::parse(p))
  , end_date_(TlFetchInt::parse(p))
{}

void webPageAttributeStarGiftAuction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(gift_, s);
  TlStoreBinary::store(end_date_, s);
}

void webPageAttributeStarGiftAuction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(gift_, s);
  TlStoreBinary::store(end_date_, s);
}

void webPageAttributeStarGiftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webPageAttributeStarGiftAuction");
    s.store_object_field("gift", static_cast<const BaseObject *>(gift_.get()));
    s.store_field("end_date", end_date_);
    s.store_class_end();
  }
}

object_ptr<account_ChatThemes> account_ChatThemes::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_chatThemesNotModified::ID:
      return account_chatThemesNotModified::fetch(p);
    case account_chatThemes::ID:
      return account_chatThemes::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_chatThemesNotModified::ID;

object_ptr<account_ChatThemes> account_chatThemesNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_chatThemesNotModified>();
}

void account_chatThemesNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.chatThemesNotModified");
    s.store_class_end();
  }
}

account_chatThemes::account_chatThemes()
  : flags_()
  , hash_()
  , themes_()
  , chats_()
  , users_()
  , next_offset_()
{}

const std::int32_t account_chatThemes::ID;

object_ptr<account_ChatThemes> account_chatThemes::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<account_chatThemes> res = make_tl_object<account_chatThemes>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->hash_ = TlFetchLong::parse(p);
  res->themes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<ChatTheme>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void account_chatThemes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.chatThemes");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("hash", hash_);
    { s.store_vector_begin("themes", themes_.size()); for (const auto &_value : themes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    s.store_class_end();
  }
}

help_termsOfService::help_termsOfService()
  : flags_()
  , popup_()
  , id_()
  , text_()
  , entities_()
  , min_age_confirm_()
{}

const std::int32_t help_termsOfService::ID;

object_ptr<help_termsOfService> help_termsOfService::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_termsOfService> res = make_tl_object<help_termsOfService>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->popup_ = (var0 & 1) != 0;
  res->id_ = TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
  res->text_ = TlFetchString<string>::parse(p);
  res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p);
  if (var0 & 2) { res->min_age_confirm_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void help_termsOfService::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.termsOfService");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (popup_ << 0)));
    if (var0 & 1) { s.store_field("popup", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("text", text_);
    { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 2) { s.store_field("min_age_confirm", min_age_confirm_); }
    s.store_class_end();
  }
}

const std::int32_t messages_affectedMessages::ID;

object_ptr<messages_affectedMessages> messages_affectedMessages::fetch(TlBufferParser &p) {
  return make_tl_object<messages_affectedMessages>(p);
}

messages_affectedMessages::messages_affectedMessages(TlBufferParser &p)
  : pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
{}

void messages_affectedMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.affectedMessages");
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_class_end();
  }
}

messages_dialogFilters::messages_dialogFilters()
  : flags_()
  , tags_enabled_()
  , filters_()
{}

const std::int32_t messages_dialogFilters::ID;

object_ptr<messages_dialogFilters> messages_dialogFilters::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<messages_dialogFilters> res = make_tl_object<messages_dialogFilters>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->tags_enabled_ = (var0 & 1) != 0;
  res->filters_ = TlFetchBoxed<TlFetchVector<TlFetchObject<DialogFilter>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void messages_dialogFilters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.dialogFilters");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (tags_enabled_ << 0)));
    if (var0 & 1) { s.store_field("tags_enabled", true); }
    { s.store_vector_begin("filters", filters_.size()); for (const auto &_value : filters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_emojiGameOutcome::messages_emojiGameOutcome(bytes &&seed_, int64 stake_ton_amount_, int64 ton_amount_)
  : seed_(std::move(seed_))
  , stake_ton_amount_(stake_ton_amount_)
  , ton_amount_(ton_amount_)
{}

const std::int32_t messages_emojiGameOutcome::ID;

object_ptr<messages_emojiGameOutcome> messages_emojiGameOutcome::fetch(TlBufferParser &p) {
  return make_tl_object<messages_emojiGameOutcome>(p);
}

messages_emojiGameOutcome::messages_emojiGameOutcome(TlBufferParser &p)
  : seed_(TlFetchBytes<bytes>::parse(p))
  , stake_ton_amount_(TlFetchLong::parse(p))
  , ton_amount_(TlFetchLong::parse(p))
{}

void messages_emojiGameOutcome::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(seed_, s);
  TlStoreBinary::store(stake_ton_amount_, s);
  TlStoreBinary::store(ton_amount_, s);
}

void messages_emojiGameOutcome::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(seed_, s);
  TlStoreBinary::store(stake_ton_amount_, s);
  TlStoreBinary::store(ton_amount_, s);
}

void messages_emojiGameOutcome::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.emojiGameOutcome");
    s.store_bytes_field("seed", seed_);
    s.store_field("stake_ton_amount", stake_ton_amount_);
    s.store_field("ton_amount", ton_amount_);
    s.store_class_end();
  }
}

object_ptr<messages_Reactions> messages_Reactions::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_reactionsNotModified::ID:
      return messages_reactionsNotModified::fetch(p);
    case messages_reactions::ID:
      return messages_reactions::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_reactionsNotModified::ID;

object_ptr<messages_Reactions> messages_reactionsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_reactionsNotModified>();
}

void messages_reactionsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reactionsNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_reactions::ID;

object_ptr<messages_Reactions> messages_reactions::fetch(TlBufferParser &p) {
  return make_tl_object<messages_reactions>(p);
}

messages_reactions::messages_reactions(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , reactions_(TlFetchBoxed<TlFetchVector<TlFetchObject<Reaction>>, 481674261>::parse(p))
{}

void messages_reactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reactions");
    s.store_field("hash", hash_);
    { s.store_vector_begin("reactions", reactions_.size()); for (const auto &_value : reactions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_checkedGiftCode::payments_checkedGiftCode()
  : flags_()
  , via_giveaway_()
  , from_id_()
  , giveaway_msg_id_()
  , to_id_()
  , date_()
  , days_()
  , used_date_()
  , chats_()
  , users_()
{}

const std::int32_t payments_checkedGiftCode::ID;

object_ptr<payments_checkedGiftCode> payments_checkedGiftCode::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_checkedGiftCode> res = make_tl_object<payments_checkedGiftCode>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->via_giveaway_ = (var0 & 4) != 0;
  if (var0 & 16) { res->from_id_ = TlFetchObject<Peer>::parse(p); }
  if (var0 & 8) { res->giveaway_msg_id_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->to_id_ = TlFetchLong::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->days_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->used_date_ = TlFetchInt::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_checkedGiftCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.checkedGiftCode");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (via_giveaway_ << 2)));
    if (var0 & 4) { s.store_field("via_giveaway", true); }
    if (var0 & 16) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 8) { s.store_field("giveaway_msg_id", giveaway_msg_id_); }
    if (var0 & 1) { s.store_field("to_id", to_id_); }
    s.store_field("date", date_);
    s.store_field("days", days_);
    if (var0 & 2) { s.store_field("used_date", used_date_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<payments_GiveawayInfo> payments_GiveawayInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_giveawayInfo::ID:
      return payments_giveawayInfo::fetch(p);
    case payments_giveawayInfoResults::ID:
      return payments_giveawayInfoResults::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

payments_giveawayInfo::payments_giveawayInfo()
  : flags_()
  , participating_()
  , preparing_results_()
  , start_date_()
  , joined_too_early_date_()
  , admin_disallowed_chat_id_()
  , disallowed_country_()
{}

const std::int32_t payments_giveawayInfo::ID;

object_ptr<payments_GiveawayInfo> payments_giveawayInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_giveawayInfo> res = make_tl_object<payments_giveawayInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->participating_ = (var0 & 1) != 0;
  res->preparing_results_ = (var0 & 8) != 0;
  res->start_date_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->joined_too_early_date_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->admin_disallowed_chat_id_ = TlFetchLong::parse(p); }
  if (var0 & 16) { res->disallowed_country_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_giveawayInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.giveawayInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (participating_ << 0) | (preparing_results_ << 3)));
    if (var0 & 1) { s.store_field("participating", true); }
    if (var0 & 8) { s.store_field("preparing_results", true); }
    s.store_field("start_date", start_date_);
    if (var0 & 2) { s.store_field("joined_too_early_date", joined_too_early_date_); }
    if (var0 & 4) { s.store_field("admin_disallowed_chat_id", admin_disallowed_chat_id_); }
    if (var0 & 16) { s.store_field("disallowed_country", disallowed_country_); }
    s.store_class_end();
  }
}

payments_giveawayInfoResults::payments_giveawayInfoResults()
  : flags_()
  , winner_()
  , refunded_()
  , start_date_()
  , gift_code_slug_()
  , stars_prize_()
  , finish_date_()
  , winners_count_()
  , activated_count_()
{}

const std::int32_t payments_giveawayInfoResults::ID;

object_ptr<payments_GiveawayInfo> payments_giveawayInfoResults::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_giveawayInfoResults> res = make_tl_object<payments_giveawayInfoResults>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->winner_ = (var0 & 1) != 0;
  res->refunded_ = (var0 & 2) != 0;
  res->start_date_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->gift_code_slug_ = TlFetchString<string>::parse(p); }
  if (var0 & 16) { res->stars_prize_ = TlFetchLong::parse(p); }
  res->finish_date_ = TlFetchInt::parse(p);
  res->winners_count_ = TlFetchInt::parse(p);
  if (var0 & 4) { res->activated_count_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void payments_giveawayInfoResults::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.giveawayInfoResults");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (winner_ << 0) | (refunded_ << 1)));
    if (var0 & 1) { s.store_field("winner", true); }
    if (var0 & 2) { s.store_field("refunded", true); }
    s.store_field("start_date", start_date_);
    if (var0 & 8) { s.store_field("gift_code_slug", gift_code_slug_); }
    if (var0 & 16) { s.store_field("stars_prize", stars_prize_); }
    s.store_field("finish_date", finish_date_);
    s.store_field("winners_count", winners_count_);
    if (var0 & 4) { s.store_field("activated_count", activated_count_); }
    s.store_class_end();
  }
}

payments_resaleStarGifts::payments_resaleStarGifts()
  : flags_()
  , count_()
  , gifts_()
  , next_offset_()
  , attributes_()
  , attributes_hash_()
  , chats_()
  , counters_()
  , users_()
{}

const std::int32_t payments_resaleStarGifts::ID;

object_ptr<payments_resaleStarGifts> payments_resaleStarGifts::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_resaleStarGifts> res = make_tl_object<payments_resaleStarGifts>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->gifts_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StarGift>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->attributes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<StarGiftAttribute>>, 481674261>::parse(p); }
  if (var0 & 2) { res->attributes_hash_ = TlFetchLong::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  if (var0 & 4) { res->counters_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starGiftAttributeCounter>, 783398488>>, 481674261>::parse(p); }
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_resaleStarGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.resaleStarGifts");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("count", count_);
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    if (var0 & 2) { { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_field("attributes_hash", attributes_hash_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 4) { { s.store_vector_begin("counters", counters_.size()); for (const auto &_value : counters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<payments_StarGiftCollections> payments_StarGiftCollections::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_starGiftCollectionsNotModified::ID:
      return payments_starGiftCollectionsNotModified::fetch(p);
    case payments_starGiftCollections::ID:
      return payments_starGiftCollections::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t payments_starGiftCollectionsNotModified::ID;

object_ptr<payments_StarGiftCollections> payments_starGiftCollectionsNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftCollectionsNotModified>();
}

void payments_starGiftCollectionsNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftCollectionsNotModified");
    s.store_class_end();
  }
}

const std::int32_t payments_starGiftCollections::ID;

object_ptr<payments_StarGiftCollections> payments_starGiftCollections::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starGiftCollections>(p);
}

payments_starGiftCollections::payments_starGiftCollections(TlBufferParser &p)
  : collections_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starGiftCollection>, -1653926992>>, 481674261>::parse(p))
{}

void payments_starGiftCollections::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starGiftCollections");
    { s.store_vector_begin("collections", collections_.size()); for (const auto &_value : collections_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t phone_groupCallStreamChannels::ID;

object_ptr<phone_groupCallStreamChannels> phone_groupCallStreamChannels::fetch(TlBufferParser &p) {
  return make_tl_object<phone_groupCallStreamChannels>(p);
}

phone_groupCallStreamChannels::phone_groupCallStreamChannels(TlBufferParser &p)
  : channels_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<groupCallStreamChannel>, -2132064081>>, 481674261>::parse(p))
{}

void phone_groupCallStreamChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.groupCallStreamChannels");
    { s.store_vector_begin("channels", channels_.size()); for (const auto &_value : channels_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

premium_boostsList::premium_boostsList()
  : flags_()
  , count_()
  , boosts_()
  , next_offset_()
  , users_()
{}

const std::int32_t premium_boostsList::ID;

object_ptr<premium_boostsList> premium_boostsList::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<premium_boostsList> res = make_tl_object<premium_boostsList>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->boosts_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<boost>, 1262359766>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void premium_boostsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.boostsList");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("count", count_);
    { s.store_vector_begin("boosts", boosts_.size()); for (const auto &_value : boosts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t premium_myBoosts::ID;

object_ptr<premium_myBoosts> premium_myBoosts::fetch(TlBufferParser &p) {
  return make_tl_object<premium_myBoosts>(p);
}

premium_myBoosts::premium_myBoosts(TlBufferParser &p)
  : my_boosts_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<myBoost>, -1001897636>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void premium_myBoosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.myBoosts");
    { s.store_vector_begin("my_boosts", my_boosts_.size()); for (const auto &_value : my_boosts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<users_SavedMusic> users_SavedMusic::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case users_savedMusicNotModified::ID:
      return users_savedMusicNotModified::fetch(p);
    case users_savedMusic::ID:
      return users_savedMusic::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t users_savedMusicNotModified::ID;

object_ptr<users_SavedMusic> users_savedMusicNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<users_savedMusicNotModified>(p);
}

users_savedMusicNotModified::users_savedMusicNotModified(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
{}

void users_savedMusicNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.savedMusicNotModified");
    s.store_field("count", count_);
    s.store_class_end();
  }
}

const std::int32_t users_savedMusic::ID;

object_ptr<users_SavedMusic> users_savedMusic::fetch(TlBufferParser &p) {
  return make_tl_object<users_savedMusic>(p);
}

users_savedMusic::users_savedMusic(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , documents_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
{}

void users_savedMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.savedMusic");
    s.store_field("count", count_);
    { s.store_vector_begin("documents", documents_.size()); for (const auto &_value : documents_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_deletePasskey::account_deletePasskey(string const &id_)
  : id_(id_)
{}

const std::int32_t account_deletePasskey::ID;

void account_deletePasskey::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-172665281);
  TlStoreString::store(id_, s);
}

void account_deletePasskey::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-172665281);
  TlStoreString::store(id_, s);
}

void account_deletePasskey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.deletePasskey");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

account_deletePasskey::ReturnType account_deletePasskey::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_finishTakeoutSession::account_finishTakeoutSession(int32 flags_, bool success_)
  : flags_(flags_)
  , success_(success_)
{}

const std::int32_t account_finishTakeoutSession::ID;

void account_finishTakeoutSession::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(489050862);
  TlStoreBinary::store((var0 = flags_ | (success_ << 0)), s);
}

void account_finishTakeoutSession::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(489050862);
  TlStoreBinary::store((var0 = flags_ | (success_ << 0)), s);
}

void account_finishTakeoutSession::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.finishTakeoutSession");
    s.store_field("flags", (var0 = flags_ | (success_ << 0)));
    if (var0 & 1) { s.store_field("success", true); }
    s.store_class_end();
  }
}

account_finishTakeoutSession::ReturnType account_finishTakeoutSession::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_getAuthorizationForm::account_getAuthorizationForm(int64 bot_id_, string const &scope_, string const &public_key_)
  : bot_id_(bot_id_)
  , scope_(scope_)
  , public_key_(public_key_)
{}

const std::int32_t account_getAuthorizationForm::ID;

void account_getAuthorizationForm::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1456907910);
  TlStoreBinary::store(bot_id_, s);
  TlStoreString::store(scope_, s);
  TlStoreString::store(public_key_, s);
}

void account_getAuthorizationForm::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1456907910);
  TlStoreBinary::store(bot_id_, s);
  TlStoreString::store(scope_, s);
  TlStoreString::store(public_key_, s);
}

void account_getAuthorizationForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getAuthorizationForm");
    s.store_field("bot_id", bot_id_);
    s.store_field("scope", scope_);
    s.store_field("public_key", public_key_);
    s.store_class_end();
  }
}

account_getAuthorizationForm::ReturnType account_getAuthorizationForm::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_authorizationForm>, -1389486888>::parse(p);
#undef FAIL
}

const std::int32_t account_getGlobalPrivacySettings::ID;

void account_getGlobalPrivacySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-349483786);
}

void account_getGlobalPrivacySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-349483786);
}

void account_getGlobalPrivacySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getGlobalPrivacySettings");
    s.store_class_end();
  }
}

account_getGlobalPrivacySettings::ReturnType account_getGlobalPrivacySettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<globalPrivacySettings>, -29248689>::parse(p);
#undef FAIL
}

account_getTheme::account_getTheme(string const &format_, object_ptr<InputTheme> &&theme_)
  : format_(format_)
  , theme_(std::move(theme_))
{}

const std::int32_t account_getTheme::ID;

void account_getTheme::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(978872812);
  TlStoreString::store(format_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
}

void account_getTheme::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(978872812);
  TlStoreString::store(format_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(theme_, s);
}

void account_getTheme::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getTheme");
    s.store_field("format", format_);
    s.store_object_field("theme", static_cast<const BaseObject *>(theme_.get()));
    s.store_class_end();
  }
}

account_getTheme::ReturnType account_getTheme::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<theme>, -1609668650>::parse(p);
#undef FAIL
}

account_invalidateSignInCodes::account_invalidateSignInCodes(array<string> &&codes_)
  : codes_(std::move(codes_))
{}

const std::int32_t account_invalidateSignInCodes::ID;

void account_invalidateSignInCodes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-896866118);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(codes_, s);
}

void account_invalidateSignInCodes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-896866118);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(codes_, s);
}

void account_invalidateSignInCodes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.invalidateSignInCodes");
    { s.store_vector_begin("codes", codes_.size()); for (const auto &_value : codes_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_invalidateSignInCodes::ReturnType account_invalidateSignInCodes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_saveWallPaper::account_saveWallPaper(object_ptr<InputWallPaper> &&wallpaper_, bool unsave_, object_ptr<wallPaperSettings> &&settings_)
  : wallpaper_(std::move(wallpaper_))
  , unsave_(unsave_)
  , settings_(std::move(settings_))
{}

const std::int32_t account_saveWallPaper::ID;

void account_saveWallPaper::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1817860919);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s);
  TlStoreBool::store(unsave_, s);
  TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s);
}

void account_saveWallPaper::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1817860919);
  TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s);
  TlStoreBool::store(unsave_, s);
  TlStoreBoxed<TlStoreObject, 925826256>::store(settings_, s);
}

void account_saveWallPaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.saveWallPaper");
    s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get()));
    s.store_field("unsave", unsave_);
    s.store_object_field("settings", static_cast<const BaseObject *>(settings_.get()));
    s.store_class_end();
  }
}

account_saveWallPaper::ReturnType account_saveWallPaper::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_setAuthorizationTTL::account_setAuthorizationTTL(int32 authorization_ttl_days_)
  : authorization_ttl_days_(authorization_ttl_days_)
{}

const std::int32_t account_setAuthorizationTTL::ID;

void account_setAuthorizationTTL::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1081501024);
  TlStoreBinary::store(authorization_ttl_days_, s);
}

void account_setAuthorizationTTL::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1081501024);
  TlStoreBinary::store(authorization_ttl_days_, s);
}

void account_setAuthorizationTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.setAuthorizationTTL");
    s.store_field("authorization_ttl_days", authorization_ttl_days_);
    s.store_class_end();
  }
}

account_setAuthorizationTTL::ReturnType account_setAuthorizationTTL::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_toggleSponsoredMessages::account_toggleSponsoredMessages(bool enabled_)
  : enabled_(enabled_)
{}

const std::int32_t account_toggleSponsoredMessages::ID;

void account_toggleSponsoredMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1176919155);
  TlStoreBool::store(enabled_, s);
}

void account_toggleSponsoredMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1176919155);
  TlStoreBool::store(enabled_, s);
}

void account_toggleSponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.toggleSponsoredMessages");
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

account_toggleSponsoredMessages::ReturnType account_toggleSponsoredMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_reportMissingCode::auth_reportMissingCode(string const &phone_number_, string const &phone_code_hash_, string const &mnc_)
  : phone_number_(phone_number_)
  , phone_code_hash_(phone_code_hash_)
  , mnc_(mnc_)
{}

const std::int32_t auth_reportMissingCode::ID;

void auth_reportMissingCode::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-878841866);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(mnc_, s);
}

void auth_reportMissingCode::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-878841866);
  TlStoreString::store(phone_number_, s);
  TlStoreString::store(phone_code_hash_, s);
  TlStoreString::store(mnc_, s);
}

void auth_reportMissingCode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.reportMissingCode");
    s.store_field("phone_number", phone_number_);
    s.store_field("phone_code_hash", phone_code_hash_);
    s.store_field("mnc", mnc_);
    s.store_class_end();
  }
}

auth_reportMissingCode::ReturnType auth_reportMissingCode::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_addPreviewMedia::bots_addPreviewMedia(object_ptr<InputUser> &&bot_, string const &lang_code_, object_ptr<InputMedia> &&media_)
  : bot_(std::move(bot_))
  , lang_code_(lang_code_)
  , media_(std::move(media_))
{}

const std::int32_t bots_addPreviewMedia::ID;

void bots_addPreviewMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(397326170);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void bots_addPreviewMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(397326170);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void bots_addPreviewMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.addPreviewMedia");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("lang_code", lang_code_);
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

bots_addPreviewMedia::ReturnType bots_addPreviewMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<botPreviewMedia>, 602479523>::parse(p);
#undef FAIL
}

bots_invokeWebViewCustomMethod::bots_invokeWebViewCustomMethod(object_ptr<InputUser> &&bot_, string const &custom_method_, object_ptr<dataJSON> &&params_)
  : bot_(std::move(bot_))
  , custom_method_(custom_method_)
  , params_(std::move(params_))
{}

const std::int32_t bots_invokeWebViewCustomMethod::ID;

void bots_invokeWebViewCustomMethod::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(142591463);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(custom_method_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void bots_invokeWebViewCustomMethod::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(142591463);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(custom_method_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void bots_invokeWebViewCustomMethod::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.invokeWebViewCustomMethod");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("custom_method", custom_method_);
    s.store_object_field("params", static_cast<const BaseObject *>(params_.get()));
    s.store_class_end();
  }
}

bots_invokeWebViewCustomMethod::ReturnType bots_invokeWebViewCustomMethod::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
#undef FAIL
}

channels_convertToGigagroup::channels_convertToGigagroup(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t channels_convertToGigagroup::ID;

void channels_convertToGigagroup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(187239529);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_convertToGigagroup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(187239529);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_convertToGigagroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.convertToGigagroup");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_convertToGigagroup::ReturnType channels_convertToGigagroup::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_editLocation::channels_editLocation(object_ptr<InputChannel> &&channel_, object_ptr<InputGeoPoint> &&geo_point_, string const &address_)
  : channel_(std::move(channel_))
  , geo_point_(std::move(geo_point_))
  , address_(address_)
{}

const std::int32_t channels_editLocation::ID;

void channels_editLocation::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1491484525);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreString::store(address_, s);
}

void channels_editLocation::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1491484525);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  TlStoreString::store(address_, s);
}

void channels_editLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.editLocation");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    s.store_field("address", address_);
    s.store_class_end();
  }
}

channels_editLocation::ReturnType channels_editLocation::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_restrictSponsoredMessages::channels_restrictSponsoredMessages(object_ptr<InputChannel> &&channel_, bool restricted_)
  : channel_(std::move(channel_))
  , restricted_(restricted_)
{}

const std::int32_t channels_restrictSponsoredMessages::ID;

void channels_restrictSponsoredMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1696000743);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(restricted_, s);
}

void channels_restrictSponsoredMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1696000743);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(restricted_, s);
}

void channels_restrictSponsoredMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.restrictSponsoredMessages");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("restricted", restricted_);
    s.store_class_end();
  }
}

channels_restrictSponsoredMessages::ReturnType channels_restrictSponsoredMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

chatlists_checkChatlistInvite::chatlists_checkChatlistInvite(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t chatlists_checkChatlistInvite::ID;

void chatlists_checkChatlistInvite::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1103171583);
  TlStoreString::store(slug_, s);
}

void chatlists_checkChatlistInvite::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1103171583);
  TlStoreString::store(slug_, s);
}

void chatlists_checkChatlistInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.checkChatlistInvite");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

chatlists_checkChatlistInvite::ReturnType chatlists_checkChatlistInvite::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<chatlists_ChatlistInvite>::parse(p);
#undef FAIL
}

chatlists_getLeaveChatlistSuggestions::chatlists_getLeaveChatlistSuggestions(object_ptr<inputChatlistDialogFilter> &&chatlist_)
  : chatlist_(std::move(chatlist_))
{}

const std::int32_t chatlists_getLeaveChatlistSuggestions::ID;

void chatlists_getLeaveChatlistSuggestions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-37955820);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_getLeaveChatlistSuggestions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-37955820);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_getLeaveChatlistSuggestions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.getLeaveChatlistSuggestions");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_class_end();
  }
}

chatlists_getLeaveChatlistSuggestions::ReturnType chatlists_getLeaveChatlistSuggestions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p);
#undef FAIL
}

contacts_acceptContact::contacts_acceptContact(object_ptr<InputUser> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t contacts_acceptContact::ID;

void contacts_acceptContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-130964977);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void contacts_acceptContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-130964977);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
}

void contacts_acceptContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.acceptContact");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_class_end();
  }
}

contacts_acceptContact::ReturnType contacts_acceptContact::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

contacts_addContact::contacts_addContact(int32 flags_, bool add_phone_privacy_exception_, object_ptr<InputUser> &&id_, string const &first_name_, string const &last_name_, string const &phone_, object_ptr<textWithEntities> &&note_)
  : flags_(flags_)
  , add_phone_privacy_exception_(add_phone_privacy_exception_)
  , id_(std::move(id_))
  , first_name_(first_name_)
  , last_name_(last_name_)
  , phone_(phone_)
  , note_(std::move(note_))
{}

const std::int32_t contacts_addContact::ID;

void contacts_addContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-642109868);
  TlStoreBinary::store((var0 = flags_ | (add_phone_privacy_exception_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(phone_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(note_, s); }
}

void contacts_addContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-642109868);
  TlStoreBinary::store((var0 = flags_ | (add_phone_privacy_exception_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreString::store(first_name_, s);
  TlStoreString::store(last_name_, s);
  TlStoreString::store(phone_, s);
  if (var0 & 2) { TlStoreBoxed<TlStoreObject, 1964978502>::store(note_, s); }
}

void contacts_addContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.addContact");
    s.store_field("flags", (var0 = flags_ | (add_phone_privacy_exception_ << 0)));
    if (var0 & 1) { s.store_field("add_phone_privacy_exception", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("first_name", first_name_);
    s.store_field("last_name", last_name_);
    s.store_field("phone", phone_);
    if (var0 & 2) { s.store_object_field("note", static_cast<const BaseObject *>(note_.get())); }
    s.store_class_end();
  }
}

contacts_addContact::ReturnType contacts_addContact::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

contacts_getSponsoredPeers::contacts_getSponsoredPeers(string const &q_)
  : q_(q_)
{}

const std::int32_t contacts_getSponsoredPeers::ID;

void contacts_getSponsoredPeers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1228356717);
  TlStoreString::store(q_, s);
}

void contacts_getSponsoredPeers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1228356717);
  TlStoreString::store(q_, s);
}

void contacts_getSponsoredPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getSponsoredPeers");
    s.store_field("q", q_);
    s.store_class_end();
  }
}

contacts_getSponsoredPeers::ReturnType contacts_getSponsoredPeers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<contacts_SponsoredPeers>::parse(p);
#undef FAIL
}

contacts_toggleTopPeers::contacts_toggleTopPeers(bool enabled_)
  : enabled_(enabled_)
{}

const std::int32_t contacts_toggleTopPeers::ID;

void contacts_toggleTopPeers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2062238246);
  TlStoreBool::store(enabled_, s);
}

void contacts_toggleTopPeers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2062238246);
  TlStoreBool::store(enabled_, s);
}

void contacts_toggleTopPeers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.toggleTopPeers");
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

contacts_toggleTopPeers::ReturnType contacts_toggleTopPeers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

help_getAppUpdate::help_getAppUpdate(string const &source_)
  : source_(source_)
{}

const std::int32_t help_getAppUpdate::ID;

void help_getAppUpdate::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1378703997);
  TlStoreString::store(source_, s);
}

void help_getAppUpdate::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1378703997);
  TlStoreString::store(source_, s);
}

void help_getAppUpdate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getAppUpdate");
    s.store_field("source", source_);
    s.store_class_end();
  }
}

help_getAppUpdate::ReturnType help_getAppUpdate::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<help_AppUpdate>::parse(p);
#undef FAIL
}

help_getRecentMeUrls::help_getRecentMeUrls(string const &referer_)
  : referer_(referer_)
{}

const std::int32_t help_getRecentMeUrls::ID;

void help_getRecentMeUrls::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1036054804);
  TlStoreString::store(referer_, s);
}

void help_getRecentMeUrls::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1036054804);
  TlStoreString::store(referer_, s);
}

void help_getRecentMeUrls::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getRecentMeUrls");
    s.store_field("referer", referer_);
    s.store_class_end();
  }
}

help_getRecentMeUrls::ReturnType help_getRecentMeUrls::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<help_recentMeUrls>, 235081943>::parse(p);
#undef FAIL
}

invokeWithBusinessConnectionPrefix::invokeWithBusinessConnectionPrefix(string const &connection_id_)
  : connection_id_(connection_id_)
{}

const std::int32_t invokeWithBusinessConnectionPrefix::ID;

void invokeWithBusinessConnectionPrefix::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-584540274);
  TlStoreString::store(connection_id_, s);
}

void invokeWithBusinessConnectionPrefix::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-584540274);
  TlStoreString::store(connection_id_, s);
}

void invokeWithBusinessConnectionPrefix::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invokeWithBusinessConnectionPrefix");
    s.store_field("connection_id", connection_id_);
    s.store_class_end();
  }
}

invokeWithBusinessConnectionPrefix::ReturnType invokeWithBusinessConnectionPrefix::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<error>, -994444869>::parse(p);
#undef FAIL
}

langpack_getStrings::langpack_getStrings(string const &lang_pack_, string const &lang_code_, array<string> &&keys_)
  : lang_pack_(lang_pack_)
  , lang_code_(lang_code_)
  , keys_(std::move(keys_))
{}

const std::int32_t langpack_getStrings::ID;

void langpack_getStrings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-269862909);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(keys_, s);
}

void langpack_getStrings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-269862909);
  TlStoreString::store(lang_pack_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(keys_, s);
}

void langpack_getStrings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langpack.getStrings");
    s.store_field("lang_pack", lang_pack_);
    s.store_field("lang_code", lang_code_);
    { s.store_vector_begin("keys", keys_.size()); for (const auto &_value : keys_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

langpack_getStrings::ReturnType langpack_getStrings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<LangPackString>>, 481674261>::parse(p);
#undef FAIL
}

messages_checkHistoryImportPeer::messages_checkHistoryImportPeer(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_checkHistoryImportPeer::ID;

void messages_checkHistoryImportPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1573261059);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_checkHistoryImportPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1573261059);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_checkHistoryImportPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.checkHistoryImportPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_checkHistoryImportPeer::ReturnType messages_checkHistoryImportPeer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_checkedHistoryImportPeer>, -1571952873>::parse(p);
#undef FAIL
}

messages_composeMessageWithAI::messages_composeMessageWithAI(int32 flags_, bool proofread_, bool emojify_, object_ptr<textWithEntities> &&text_, string const &translate_to_lang_, string const &change_tone_)
  : flags_(flags_)
  , proofread_(proofread_)
  , emojify_(emojify_)
  , text_(std::move(text_))
  , translate_to_lang_(translate_to_lang_)
  , change_tone_(change_tone_)
{}

const std::int32_t messages_composeMessageWithAI::ID;

void messages_composeMessageWithAI::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-45978882);
  TlStoreBinary::store((var0 = flags_ | (proofread_ << 0) | (emojify_ << 3)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
  if (var0 & 2) { TlStoreString::store(translate_to_lang_, s); }
  if (var0 & 4) { TlStoreString::store(change_tone_, s); }
}

void messages_composeMessageWithAI::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-45978882);
  TlStoreBinary::store((var0 = flags_ | (proofread_ << 0) | (emojify_ << 3)), s);
  TlStoreBoxed<TlStoreObject, 1964978502>::store(text_, s);
  if (var0 & 2) { TlStoreString::store(translate_to_lang_, s); }
  if (var0 & 4) { TlStoreString::store(change_tone_, s); }
}

void messages_composeMessageWithAI::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.composeMessageWithAI");
    s.store_field("flags", (var0 = flags_ | (proofread_ << 0) | (emojify_ << 3)));
    if (var0 & 1) { s.store_field("proofread", true); }
    if (var0 & 8) { s.store_field("emojify", true); }
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    if (var0 & 2) { s.store_field("translate_to_lang", translate_to_lang_); }
    if (var0 & 4) { s.store_field("change_tone", change_tone_); }
    s.store_class_end();
  }
}

messages_composeMessageWithAI::ReturnType messages_composeMessageWithAI::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_composedMessageWithAI>, -1864913414>::parse(p);
#undef FAIL
}

messages_declineUrlAuth::messages_declineUrlAuth(string const &url_)
  : url_(url_)
{}

const std::int32_t messages_declineUrlAuth::ID;

void messages_declineUrlAuth::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(893610940);
  TlStoreString::store(url_, s);
}

void messages_declineUrlAuth::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(893610940);
  TlStoreString::store(url_, s);
}

void messages_declineUrlAuth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.declineUrlAuth");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

messages_declineUrlAuth::ReturnType messages_declineUrlAuth::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_deleteRevokedExportedChatInvites::messages_deleteRevokedExportedChatInvites(object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&admin_id_)
  : peer_(std::move(peer_))
  , admin_id_(std::move(admin_id_))
{}

const std::int32_t messages_deleteRevokedExportedChatInvites::ID;

void messages_deleteRevokedExportedChatInvites::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1452833749);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(admin_id_, s);
}

void messages_deleteRevokedExportedChatInvites::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1452833749);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(admin_id_, s);
}

void messages_deleteRevokedExportedChatInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteRevokedExportedChatInvites");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("admin_id", static_cast<const BaseObject *>(admin_id_.get()));
    s.store_class_end();
  }
}

messages_deleteRevokedExportedChatInvites::ReturnType messages_deleteRevokedExportedChatInvites::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_editChatTitle::messages_editChatTitle(int64 chat_id_, string const &title_)
  : chat_id_(chat_id_)
  , title_(title_)
{}

const std::int32_t messages_editChatTitle::ID;

void messages_editChatTitle::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1937260541);
  TlStoreBinary::store(chat_id_, s);
  TlStoreString::store(title_, s);
}

void messages_editChatTitle::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1937260541);
  TlStoreBinary::store(chat_id_, s);
  TlStoreString::store(title_, s);
}

void messages_editChatTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatTitle");
    s.store_field("chat_id", chat_id_);
    s.store_field("title", title_);
    s.store_class_end();
  }
}

messages_editChatTitle::ReturnType messages_editChatTitle::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_editMessage::messages_editMessage(int32 flags_, bool no_webpage_, bool invert_media_, object_ptr<InputPeer> &&peer_, int32 id_, string const &message_, object_ptr<InputMedia> &&media_, object_ptr<ReplyMarkup> &&reply_markup_, array<object_ptr<MessageEntity>> &&entities_, int32 schedule_date_, int32 schedule_repeat_period_, int32 quick_reply_shortcut_id_)
  : flags_(flags_)
  , no_webpage_(no_webpage_)
  , invert_media_(invert_media_)
  , peer_(std::move(peer_))
  , id_(id_)
  , message_(message_)
  , media_(std::move(media_))
  , reply_markup_(std::move(reply_markup_))
  , entities_(std::move(entities_))
  , schedule_date_(schedule_date_)
  , schedule_repeat_period_(schedule_repeat_period_)
  , quick_reply_shortcut_id_(quick_reply_shortcut_id_)
{}

const std::int32_t messages_editMessage::ID;

void messages_editMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1374175969);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 16)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 2048) { TlStoreString::store(message_, s); }
  if (var0 & 16384) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 32768) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 262144) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 131072) { TlStoreBinary::store(quick_reply_shortcut_id_, s); }
}

void messages_editMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1374175969);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 16)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 2048) { TlStoreString::store(message_, s); }
  if (var0 & 16384) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 32768) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 262144) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 131072) { TlStoreBinary::store(quick_reply_shortcut_id_, s); }
}

void messages_editMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editMessage");
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 16)));
    if (var0 & 2) { s.store_field("no_webpage", true); }
    if (var0 & 65536) { s.store_field("invert_media", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 2048) { s.store_field("message", message_); }
    if (var0 & 16384) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 32768) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 262144) { s.store_field("schedule_repeat_period", schedule_repeat_period_); }
    if (var0 & 131072) { s.store_field("quick_reply_shortcut_id", quick_reply_shortcut_id_); }
    s.store_class_end();
  }
}

messages_editMessage::ReturnType messages_editMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getBotCallbackAnswer::messages_getBotCallbackAnswer(int32 flags_, bool game_, object_ptr<InputPeer> &&peer_, int32 msg_id_, bytes &&data_, object_ptr<InputCheckPasswordSRP> &&password_)
  : flags_(flags_)
  , game_(game_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , data_(std::move(data_))
  , password_(std::move(password_))
{}

const std::int32_t messages_getBotCallbackAnswer::ID;

void messages_getBotCallbackAnswer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1824339449);
  TlStoreBinary::store((var0 = flags_ | (game_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  if (var0 & 1) { TlStoreString::store(data_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
}

void messages_getBotCallbackAnswer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1824339449);
  TlStoreBinary::store((var0 = flags_ | (game_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  if (var0 & 1) { TlStoreString::store(data_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(password_, s); }
}

void messages_getBotCallbackAnswer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getBotCallbackAnswer");
    s.store_field("flags", (var0 = flags_ | (game_ << 1)));
    if (var0 & 2) { s.store_field("game", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    if (var0 & 1) { s.store_bytes_field("data", data_); }
    if (var0 & 4) { s.store_object_field("password", static_cast<const BaseObject *>(password_.get())); }
    s.store_class_end();
  }
}

messages_getBotCallbackAnswer::ReturnType messages_getBotCallbackAnswer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_botCallbackAnswer>, 911761060>::parse(p);
#undef FAIL
}

messages_getDiscussionMessage::messages_getDiscussionMessage(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t messages_getDiscussionMessage::ID;

void messages_getDiscussionMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1147761405);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_getDiscussionMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1147761405);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_getDiscussionMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDiscussionMessage");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

messages_getDiscussionMessage::ReturnType messages_getDiscussionMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_discussionMessage>, -1506535550>::parse(p);
#undef FAIL
}

messages_getEmojiStickerGroups::messages_getEmojiStickerGroups(int32 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getEmojiStickerGroups::ID;

void messages_getEmojiStickerGroups::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(500711669);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiStickerGroups::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(500711669);
  TlStoreBinary::store(hash_, s);
}

void messages_getEmojiStickerGroups::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getEmojiStickerGroups");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getEmojiStickerGroups::ReturnType messages_getEmojiStickerGroups::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_EmojiGroups>::parse(p);
#undef FAIL
}

messages_getHistory::messages_getHistory(object_ptr<InputPeer> &&peer_, int32 offset_id_, int32 offset_date_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_, int64 hash_)
  : peer_(std::move(peer_))
  , offset_id_(offset_id_)
  , offset_date_(offset_date_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
  , hash_(hash_)
{}

const std::int32_t messages_getHistory::ID;

void messages_getHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1143203525);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1143203525);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getHistory");
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

messages_getHistory::ReturnType messages_getHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getOutboxReadDate::messages_getOutboxReadDate(object_ptr<InputPeer> &&peer_, int32 msg_id_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
{}

const std::int32_t messages_getOutboxReadDate::ID;

void messages_getOutboxReadDate::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1941176739);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_getOutboxReadDate::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1941176739);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
}

void messages_getOutboxReadDate::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getOutboxReadDate");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

messages_getOutboxReadDate::ReturnType messages_getOutboxReadDate::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<outboxReadDate>, 1001931436>::parse(p);
#undef FAIL
}

messages_getRecentLocations::messages_getRecentLocations(object_ptr<InputPeer> &&peer_, int32 limit_, int64 hash_)
  : peer_(std::move(peer_))
  , limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_getRecentLocations::ID;

void messages_getRecentLocations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1881817312);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getRecentLocations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1881817312);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getRecentLocations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getRecentLocations");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getRecentLocations::ReturnType messages_getRecentLocations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getReplies::messages_getReplies(object_ptr<InputPeer> &&peer_, int32 msg_id_, int32 offset_id_, int32 offset_date_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_, int64 hash_)
  : peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , offset_id_(offset_id_)
  , offset_date_(offset_date_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
  , hash_(hash_)
{}

const std::int32_t messages_getReplies::ID;

void messages_getReplies::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(584962828);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getReplies::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(584962828);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(msg_id_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(offset_date_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getReplies::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getReplies");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("msg_id", msg_id_);
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

messages_getReplies::ReturnType messages_getReplies::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_getWebPagePreview::messages_getWebPagePreview(int32 flags_, string const &message_, array<object_ptr<MessageEntity>> &&entities_)
  : flags_(flags_)
  , message_(message_)
  , entities_(std::move(entities_))
{}

const std::int32_t messages_getWebPagePreview::ID;

void messages_getWebPagePreview::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1460498287);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(message_, s);
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void messages_getWebPagePreview::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1460498287);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(message_, s);
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void messages_getWebPagePreview::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getWebPagePreview");
    s.store_field("flags", (var0 = flags_));
    s.store_field("message", message_);
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

messages_getWebPagePreview::ReturnType messages_getWebPagePreview::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_webPagePreview>, -1936029524>::parse(p);
#undef FAIL
}

messages_initHistoryImport::messages_initHistoryImport(object_ptr<InputPeer> &&peer_, object_ptr<InputFile> &&file_, int32 media_count_)
  : peer_(std::move(peer_))
  , file_(std::move(file_))
  , media_count_(media_count_)
{}

const std::int32_t messages_initHistoryImport::ID;

void messages_initHistoryImport::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(873008187);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  TlStoreBinary::store(media_count_, s);
}

void messages_initHistoryImport::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(873008187);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(file_, s);
  TlStoreBinary::store(media_count_, s);
}

void messages_initHistoryImport::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.initHistoryImport");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("file", static_cast<const BaseObject *>(file_.get()));
    s.store_field("media_count", media_count_);
    s.store_class_end();
  }
}

messages_initHistoryImport::ReturnType messages_initHistoryImport::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_historyImport>, 375566091>::parse(p);
#undef FAIL
}

messages_readFeaturedStickers::messages_readFeaturedStickers(array<int64> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t messages_readFeaturedStickers::ID;

void messages_readFeaturedStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1527873830);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_readFeaturedStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1527873830);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void messages_readFeaturedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readFeaturedStickers");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_readFeaturedStickers::ReturnType messages_readFeaturedStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_receivedQueue::messages_receivedQueue(int32 max_qts_)
  : max_qts_(max_qts_)
{}

const std::int32_t messages_receivedQueue::ID;

void messages_receivedQueue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1436924774);
  TlStoreBinary::store(max_qts_, s);
}

void messages_receivedQueue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1436924774);
  TlStoreBinary::store(max_qts_, s);
}

void messages_receivedQueue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.receivedQueue");
    s.store_field("max_qts", max_qts_);
    s.store_class_end();
  }
}

messages_receivedQueue::ReturnType messages_receivedQueue::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p);
#undef FAIL
}

messages_reorderStickerSets::messages_reorderStickerSets(int32 flags_, bool masks_, bool emojis_, array<int64> &&order_)
  : flags_(flags_)
  , masks_(masks_)
  , emojis_(emojis_)
  , order_(std::move(order_))
{}

const std::int32_t messages_reorderStickerSets::ID;

void messages_reorderStickerSets::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2016638777);
  TlStoreBinary::store((var0 = flags_ | (masks_ << 0) | (emojis_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_reorderStickerSets::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2016638777);
  TlStoreBinary::store((var0 = flags_ | (masks_ << 0) | (emojis_ << 1)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void messages_reorderStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reorderStickerSets");
    s.store_field("flags", (var0 = flags_ | (masks_ << 0) | (emojis_ << 1)));
    if (var0 & 1) { s.store_field("masks", true); }
    if (var0 & 2) { s.store_field("emojis", true); }
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_reorderStickerSets::ReturnType messages_reorderStickerSets::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_savePreparedInlineMessage::messages_savePreparedInlineMessage(int32 flags_, object_ptr<InputBotInlineResult> &&result_, object_ptr<InputUser> &&user_id_, array<object_ptr<InlineQueryPeerType>> &&peer_types_)
  : flags_(flags_)
  , result_(std::move(result_))
  , user_id_(std::move(user_id_))
  , peer_types_(std::move(peer_types_))
{}

const std::int32_t messages_savePreparedInlineMessage::ID;

void messages_savePreparedInlineMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-232816849);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(result_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peer_types_, s); }
}

void messages_savePreparedInlineMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-232816849);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(result_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(peer_types_, s); }
}

void messages_savePreparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.savePreparedInlineMessage");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("result", static_cast<const BaseObject *>(result_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    if (var0 & 1) { { s.store_vector_begin("peer_types", peer_types_.size()); for (const auto &_value : peer_types_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

messages_savePreparedInlineMessage::ReturnType messages_savePreparedInlineMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_botPreparedInlineMessage>, -1899035375>::parse(p);
#undef FAIL
}

messages_searchGlobal::messages_searchGlobal(int32 flags_, bool broadcasts_only_, bool groups_only_, bool users_only_, int32 folder_id_, string const &q_, object_ptr<MessagesFilter> &&filter_, int32 min_date_, int32 max_date_, int32 offset_rate_, object_ptr<InputPeer> &&offset_peer_, int32 offset_id_, int32 limit_)
  : flags_(flags_)
  , broadcasts_only_(broadcasts_only_)
  , groups_only_(groups_only_)
  , users_only_(users_only_)
  , folder_id_(folder_id_)
  , q_(q_)
  , filter_(std::move(filter_))
  , min_date_(min_date_)
  , max_date_(max_date_)
  , offset_rate_(offset_rate_)
  , offset_peer_(std::move(offset_peer_))
  , offset_id_(offset_id_)
  , limit_(limit_)
{}

const std::int32_t messages_searchGlobal::ID;

void messages_searchGlobal::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1271290010);
  TlStoreBinary::store((var0 = flags_ | (broadcasts_only_ << 1) | (groups_only_ << 2) | (users_only_ << 3)), s);
  if (var0 & 1) { TlStoreBinary::store(folder_id_, s); }
  TlStoreString::store(q_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(min_date_, s);
  TlStoreBinary::store(max_date_, s);
  TlStoreBinary::store(offset_rate_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_searchGlobal::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1271290010);
  TlStoreBinary::store((var0 = flags_ | (broadcasts_only_ << 1) | (groups_only_ << 2) | (users_only_ << 3)), s);
  if (var0 & 1) { TlStoreBinary::store(folder_id_, s); }
  TlStoreString::store(q_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(min_date_, s);
  TlStoreBinary::store(max_date_, s);
  TlStoreBinary::store(offset_rate_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(offset_peer_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_searchGlobal::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchGlobal");
    s.store_field("flags", (var0 = flags_ | (broadcasts_only_ << 1) | (groups_only_ << 2) | (users_only_ << 3)));
    if (var0 & 2) { s.store_field("broadcasts_only", true); }
    if (var0 & 4) { s.store_field("groups_only", true); }
    if (var0 & 8) { s.store_field("users_only", true); }
    if (var0 & 1) { s.store_field("folder_id", folder_id_); }
    s.store_field("q", q_);
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_field("offset_rate", offset_rate_);
    s.store_object_field("offset_peer", static_cast<const BaseObject *>(offset_peer_.get()));
    s.store_field("offset_id", offset_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_searchGlobal::ReturnType messages_searchGlobal::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_translateText::messages_translateText(int32 flags_, object_ptr<InputPeer> &&peer_, array<int32> &&id_, array<object_ptr<textWithEntities>> &&text_, string const &to_lang_, string const &tone_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(std::move(id_))
  , text_(std::move(text_))
  , to_lang_(to_lang_)
  , tone_(tone_)
{}

const std::int32_t messages_translateText::ID;

void messages_translateText::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1511079099);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1964978502>>, 481674261>::store(text_, s); }
  TlStoreString::store(to_lang_, s);
  if (var0 & 4) { TlStoreString::store(tone_, s); }
}

void messages_translateText::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1511079099);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1964978502>>, 481674261>::store(text_, s); }
  TlStoreString::store(to_lang_, s);
  if (var0 & 4) { TlStoreString::store(tone_, s); }
}

void messages_translateText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.translateText");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 1) { { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 2) { { s.store_vector_begin("text", text_.size()); for (const auto &_value : text_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("to_lang", to_lang_);
    if (var0 & 4) { s.store_field("tone", tone_); }
    s.store_class_end();
  }
}

messages_translateText::ReturnType messages_translateText::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_translateResult>, 870003448>::parse(p);
#undef FAIL
}

payments_getResaleStarGifts::payments_getResaleStarGifts(int32 flags_, bool sort_by_price_, bool sort_by_num_, bool for_craft_, bool stars_only_, int64 attributes_hash_, int64 gift_id_, array<object_ptr<StarGiftAttributeId>> &&attributes_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , sort_by_price_(sort_by_price_)
  , sort_by_num_(sort_by_num_)
  , for_craft_(for_craft_)
  , stars_only_(stars_only_)
  , attributes_hash_(attributes_hash_)
  , gift_id_(gift_id_)
  , attributes_(std::move(attributes_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t payments_getResaleStarGifts::ID;

void payments_getResaleStarGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2053087798);
  TlStoreBinary::store((var0 = flags_ | (sort_by_price_ << 1) | (sort_by_num_ << 2) | (for_craft_ << 4) | (stars_only_ << 5)), s);
  if (var0 & 1) { TlStoreBinary::store(attributes_hash_, s); }
  TlStoreBinary::store(gift_id_, s);
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s); }
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getResaleStarGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2053087798);
  TlStoreBinary::store((var0 = flags_ | (sort_by_price_ << 1) | (sort_by_num_ << 2) | (for_craft_ << 4) | (stars_only_ << 5)), s);
  if (var0 & 1) { TlStoreBinary::store(attributes_hash_, s); }
  TlStoreBinary::store(gift_id_, s);
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s); }
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getResaleStarGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getResaleStarGifts");
    s.store_field("flags", (var0 = flags_ | (sort_by_price_ << 1) | (sort_by_num_ << 2) | (for_craft_ << 4) | (stars_only_ << 5)));
    if (var0 & 2) { s.store_field("sort_by_price", true); }
    if (var0 & 4) { s.store_field("sort_by_num", true); }
    if (var0 & 16) { s.store_field("for_craft", true); }
    if (var0 & 32) { s.store_field("stars_only", true); }
    if (var0 & 1) { s.store_field("attributes_hash", attributes_hash_); }
    s.store_field("gift_id", gift_id_);
    if (var0 & 8) { { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

payments_getResaleStarGifts::ReturnType payments_getResaleStarGifts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_resaleStarGifts>, -1803939105>::parse(p);
#undef FAIL
}

payments_sendPaymentForm::payments_sendPaymentForm(int32 flags_, int64 form_id_, object_ptr<InputInvoice> &&invoice_, string const &requested_info_id_, string const &shipping_option_id_, object_ptr<InputPaymentCredentials> &&credentials_, int64 tip_amount_)
  : flags_(flags_)
  , form_id_(form_id_)
  , invoice_(std::move(invoice_))
  , requested_info_id_(requested_info_id_)
  , shipping_option_id_(shipping_option_id_)
  , credentials_(std::move(credentials_))
  , tip_amount_(tip_amount_)
{}

const std::int32_t payments_sendPaymentForm::ID;

void payments_sendPaymentForm::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(755192367);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(form_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
  if (var0 & 1) { TlStoreString::store(requested_info_id_, s); }
  if (var0 & 2) { TlStoreString::store(shipping_option_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(credentials_, s);
  if (var0 & 4) { TlStoreBinary::store(tip_amount_, s); }
}

void payments_sendPaymentForm::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(755192367);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(form_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(invoice_, s);
  if (var0 & 1) { TlStoreString::store(requested_info_id_, s); }
  if (var0 & 2) { TlStoreString::store(shipping_option_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(credentials_, s);
  if (var0 & 4) { TlStoreBinary::store(tip_amount_, s); }
}

void payments_sendPaymentForm::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.sendPaymentForm");
    s.store_field("flags", (var0 = flags_));
    s.store_field("form_id", form_id_);
    s.store_object_field("invoice", static_cast<const BaseObject *>(invoice_.get()));
    if (var0 & 1) { s.store_field("requested_info_id", requested_info_id_); }
    if (var0 & 2) { s.store_field("shipping_option_id", shipping_option_id_); }
    s.store_object_field("credentials", static_cast<const BaseObject *>(credentials_.get()));
    if (var0 & 4) { s.store_field("tip_amount", tip_amount_); }
    s.store_class_end();
  }
}

payments_sendPaymentForm::ReturnType payments_sendPaymentForm::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<payments_PaymentResult>::parse(p);
#undef FAIL
}

phone_receivedCall::phone_receivedCall(object_ptr<inputPhoneCall> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t phone_receivedCall::ID;

void phone_receivedCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(399855457);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
}

void phone_receivedCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(399855457);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
}

void phone_receivedCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.receivedCall");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

phone_receivedCall::ReturnType phone_receivedCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_saveCallDebug::phone_saveCallDebug(object_ptr<inputPhoneCall> &&peer_, object_ptr<dataJSON> &&debug_)
  : peer_(std::move(peer_))
  , debug_(std::move(debug_))
{}

const std::int32_t phone_saveCallDebug::ID;

void phone_saveCallDebug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(662363518);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(debug_, s);
}

void phone_saveCallDebug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(662363518);
  TlStoreBoxed<TlStoreObject, 506920429>::store(peer_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(debug_, s);
}

void phone_saveCallDebug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.saveCallDebug");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("debug", static_cast<const BaseObject *>(debug_.get()));
    s.store_class_end();
  }
}

phone_saveCallDebug::ReturnType phone_saveCallDebug::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

premium_applyBoost::premium_applyBoost(int32 flags_, array<int32> &&slots_, object_ptr<InputPeer> &&peer_)
  : flags_(flags_)
  , slots_(std::move(slots_))
  , peer_(std::move(peer_))
{}

const std::int32_t premium_applyBoost::ID;

void premium_applyBoost::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1803396934);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(slots_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void premium_applyBoost::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1803396934);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(slots_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void premium_applyBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.applyBoost");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { { s.store_vector_begin("slots", slots_.size()); for (const auto &_value : slots_) { s.store_field("", _value); } s.store_class_end(); } }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

premium_applyBoost::ReturnType premium_applyBoost::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<premium_myBoosts>, -1696454430>::parse(p);
#undef FAIL
}

premium_getBoostsStatus::premium_getBoostsStatus(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t premium_getBoostsStatus::ID;

void premium_getBoostsStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(70197089);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void premium_getBoostsStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(70197089);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void premium_getBoostsStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.getBoostsStatus");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

premium_getBoostsStatus::ReturnType premium_getBoostsStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<premium_boostsStatus>, 1230586490>::parse(p);
#undef FAIL
}

const std::int32_t premium_getMyBoosts::ID;

void premium_getMyBoosts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(199719754);
}

void premium_getMyBoosts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(199719754);
}

void premium_getMyBoosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.getMyBoosts");
    s.store_class_end();
  }
}

premium_getMyBoosts::ReturnType premium_getMyBoosts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<premium_myBoosts>, -1696454430>::parse(p);
#undef FAIL
}

stats_getMegagroupStats::stats_getMegagroupStats(int32 flags_, bool dark_, object_ptr<InputChannel> &&channel_)
  : flags_(flags_)
  , dark_(dark_)
  , channel_(std::move(channel_))
{}

const std::int32_t stats_getMegagroupStats::ID;

void stats_getMegagroupStats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-589330937);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void stats_getMegagroupStats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-589330937);
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void stats_getMegagroupStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getMegagroupStats");
    s.store_field("flags", (var0 = flags_ | (dark_ << 0)));
    if (var0 & 1) { s.store_field("dark", true); }
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

stats_getMegagroupStats::ReturnType stats_getMegagroupStats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_megagroupStats>, -276825834>::parse(p);
#undef FAIL
}

stats_getStoryPublicForwards::stats_getStoryPublicForwards(object_ptr<InputPeer> &&peer_, int32 id_, string const &offset_, int32 limit_)
  : peer_(std::move(peer_))
  , id_(id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t stats_getStoryPublicForwards::ID;

void stats_getStoryPublicForwards::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1505526026);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stats_getStoryPublicForwards::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1505526026);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stats_getStoryPublicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.getStoryPublicForwards");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stats_getStoryPublicForwards::ReturnType stats_getStoryPublicForwards::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stats_publicForwards>, -1828487648>::parse(p);
#undef FAIL
}

stats_loadAsyncGraph::stats_loadAsyncGraph(int32 flags_, string const &token_, int64 x_)
  : flags_(flags_)
  , token_(token_)
  , x_(x_)
{}

const std::int32_t stats_loadAsyncGraph::ID;

void stats_loadAsyncGraph::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1646092192);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(token_, s);
  if (var0 & 1) { TlStoreBinary::store(x_, s); }
}

void stats_loadAsyncGraph::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1646092192);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(token_, s);
  if (var0 & 1) { TlStoreBinary::store(x_, s); }
}

void stats_loadAsyncGraph::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.loadAsyncGraph");
    s.store_field("flags", (var0 = flags_));
    s.store_field("token", token_);
    if (var0 & 1) { s.store_field("x", x_); }
    s.store_class_end();
  }
}

stats_loadAsyncGraph::ReturnType stats_loadAsyncGraph::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<StatsGraph>::parse(p);
#undef FAIL
}

stories_editStory::stories_editStory(int32 flags_, object_ptr<InputPeer> &&peer_, int32 id_, object_ptr<InputMedia> &&media_, array<object_ptr<MediaArea>> &&media_areas_, string const &caption_, array<object_ptr<MessageEntity>> &&entities_, array<object_ptr<InputPrivacyRule>> &&privacy_rules_, object_ptr<InputDocument> &&music_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , id_(id_)
  , media_(std::move(media_))
  , media_areas_(std::move(media_areas_))
  , caption_(caption_)
  , entities_(std::move(entities_))
  , privacy_rules_(std::move(privacy_rules_))
  , music_(std::move(music_))
{}

const std::int32_t stories_editStory::ID;

void stories_editStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(744728363);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_areas_, s); }
  if (var0 & 2) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_rules_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(music_, s); }
}

void stories_editStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(744728363);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(id_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_areas_, s); }
  if (var0 & 2) { TlStoreString::store(caption_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(privacy_rules_, s); }
  if (var0 & 16) { TlStoreBoxedUnknown<TlStoreObject>::store(music_, s); }
}

void stories_editStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.editStory");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("id", id_);
    if (var0 & 1) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 8) { { s.store_vector_begin("media_areas", media_areas_.size()); for (const auto &_value : media_areas_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_field("caption", caption_); }
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 4) { { s.store_vector_begin("privacy_rules", privacy_rules_.size()); for (const auto &_value : privacy_rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 16) { s.store_object_field("music", static_cast<const BaseObject *>(music_.get())); }
    s.store_class_end();
  }
}

stories_editStory::ReturnType stories_editStory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t stories_getChatsToSend::ID;

void stories_getChatsToSend::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1519744160);
}

void stories_getChatsToSend::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1519744160);
}

void stories_getChatsToSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getChatsToSend");
    s.store_class_end();
  }
}

stories_getChatsToSend::ReturnType stories_getChatsToSend::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

stories_readStories::stories_readStories(object_ptr<InputPeer> &&peer_, int32 max_id_)
  : peer_(std::move(peer_))
  , max_id_(max_id_)
{}

const std::int32_t stories_readStories::ID;

void stories_readStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1521034552);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
}

void stories_readStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1521034552);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
}

void stories_readStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.readStories");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

stories_readStories::ReturnType stories_readStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
#undef FAIL
}

stories_report::stories_report(object_ptr<InputPeer> &&peer_, array<int32> &&id_, bytes &&option_, string const &message_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
  , option_(std::move(option_))
  , message_(message_)
{}

const std::int32_t stories_report::ID;

void stories_report::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(433646405);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreString::store(option_, s);
  TlStoreString::store(message_, s);
}

void stories_report::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(433646405);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreString::store(option_, s);
  TlStoreString::store(message_, s);
}

void stories_report::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.report");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_bytes_field("option", option_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

stories_report::ReturnType stories_report::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<ReportResult>::parse(p);
#undef FAIL
}

stories_toggleAllStoriesHidden::stories_toggleAllStoriesHidden(bool hidden_)
  : hidden_(hidden_)
{}

const std::int32_t stories_toggleAllStoriesHidden::ID;

void stories_toggleAllStoriesHidden::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2082822084);
  TlStoreBool::store(hidden_, s);
}

void stories_toggleAllStoriesHidden::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2082822084);
  TlStoreBool::store(hidden_, s);
}

void stories_toggleAllStoriesHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.toggleAllStoriesHidden");
    s.store_field("hidden", hidden_);
    s.store_class_end();
  }
}

stories_toggleAllStoriesHidden::ReturnType stories_toggleAllStoriesHidden::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

updates_getDifference::updates_getDifference(int32 flags_, int32 pts_, int32 pts_limit_, int32 pts_total_limit_, int32 date_, int32 qts_, int32 qts_limit_)
  : flags_(flags_)
  , pts_(pts_)
  , pts_limit_(pts_limit_)
  , pts_total_limit_(pts_total_limit_)
  , date_(date_)
  , qts_(qts_)
  , qts_limit_(qts_limit_)
{}

const std::int32_t updates_getDifference::ID;

void updates_getDifference::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(432207715);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(pts_, s);
  if (var0 & 2) { TlStoreBinary::store(pts_limit_, s); }
  if (var0 & 1) { TlStoreBinary::store(pts_total_limit_, s); }
  TlStoreBinary::store(date_, s);
  TlStoreBinary::store(qts_, s);
  if (var0 & 4) { TlStoreBinary::store(qts_limit_, s); }
}

void updates_getDifference::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(432207715);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(pts_, s);
  if (var0 & 2) { TlStoreBinary::store(pts_limit_, s); }
  if (var0 & 1) { TlStoreBinary::store(pts_total_limit_, s); }
  TlStoreBinary::store(date_, s);
  TlStoreBinary::store(qts_, s);
  if (var0 & 4) { TlStoreBinary::store(qts_limit_, s); }
}

void updates_getDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "updates.getDifference");
    s.store_field("flags", (var0 = flags_));
    s.store_field("pts", pts_);
    if (var0 & 2) { s.store_field("pts_limit", pts_limit_); }
    if (var0 & 1) { s.store_field("pts_total_limit", pts_total_limit_); }
    s.store_field("date", date_);
    s.store_field("qts", qts_);
    if (var0 & 4) { s.store_field("qts_limit", qts_limit_); }
    s.store_class_end();
  }
}

updates_getDifference::ReturnType updates_getDifference::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<updates_Difference>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
