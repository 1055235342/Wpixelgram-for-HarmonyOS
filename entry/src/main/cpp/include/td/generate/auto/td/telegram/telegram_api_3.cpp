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


const std::int32_t auctionBidLevel::ID;

object_ptr<auctionBidLevel> auctionBidLevel::fetch(TlBufferParser &p) {
  return make_tl_object<auctionBidLevel>(p);
}

auctionBidLevel::auctionBidLevel(TlBufferParser &p)
  : pos_(TlFetchInt::parse(p))
  , amount_(TlFetchLong::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void auctionBidLevel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auctionBidLevel");
    s.store_field("pos", pos_);
    s.store_field("amount", amount_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

object_ptr<ChannelAdminLogEventAction> ChannelAdminLogEventAction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t channelAdminLogEventActionChangeTitle::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeTitle::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeTitle>(p);
}

channelAdminLogEventActionChangeTitle::channelAdminLogEventActionChangeTitle(TlBufferParser &p)
  : prev_value_(TlFetchString<string>::parse(p))
  , new_value_(TlFetchString<string>::parse(p))
{}

void channelAdminLogEventActionChangeTitle::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeTitle");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeAbout::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeAbout::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeAbout>(p);
}

channelAdminLogEventActionChangeAbout::channelAdminLogEventActionChangeAbout(TlBufferParser &p)
  : prev_value_(TlFetchString<string>::parse(p))
  , new_value_(TlFetchString<string>::parse(p))
{}

void channelAdminLogEventActionChangeAbout::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeAbout");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeUsername::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeUsername::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeUsername>(p);
}

channelAdminLogEventActionChangeUsername::channelAdminLogEventActionChangeUsername(TlBufferParser &p)
  : prev_value_(TlFetchString<string>::parse(p))
  , new_value_(TlFetchString<string>::parse(p))
{}

void channelAdminLogEventActionChangeUsername::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeUsername");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangePhoto::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangePhoto::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangePhoto>(p);
}

channelAdminLogEventActionChangePhoto::channelAdminLogEventActionChangePhoto(TlBufferParser &p)
  : prev_photo_(TlFetchObject<Photo>::parse(p))
  , new_photo_(TlFetchObject<Photo>::parse(p))
{}

void channelAdminLogEventActionChangePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangePhoto");
    s.store_object_field("prev_photo", static_cast<const BaseObject *>(prev_photo_.get()));
    s.store_object_field("new_photo", static_cast<const BaseObject *>(new_photo_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleInvites::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleInvites::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleInvites>(p);
}

channelAdminLogEventActionToggleInvites::channelAdminLogEventActionToggleInvites(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleInvites");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleSignatures::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleSignatures::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleSignatures>(p);
}

channelAdminLogEventActionToggleSignatures::channelAdminLogEventActionToggleSignatures(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleSignatures::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleSignatures");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionUpdatePinned::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionUpdatePinned::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionUpdatePinned>(p);
}

channelAdminLogEventActionUpdatePinned::channelAdminLogEventActionUpdatePinned(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void channelAdminLogEventActionUpdatePinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionUpdatePinned");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionEditMessage::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionEditMessage::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionEditMessage>(p);
}

channelAdminLogEventActionEditMessage::channelAdminLogEventActionEditMessage(TlBufferParser &p)
  : prev_message_(TlFetchObject<Message>::parse(p))
  , new_message_(TlFetchObject<Message>::parse(p))
{}

void channelAdminLogEventActionEditMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionEditMessage");
    s.store_object_field("prev_message", static_cast<const BaseObject *>(prev_message_.get()));
    s.store_object_field("new_message", static_cast<const BaseObject *>(new_message_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionDeleteMessage::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionDeleteMessage::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionDeleteMessage>(p);
}

channelAdminLogEventActionDeleteMessage::channelAdminLogEventActionDeleteMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void channelAdminLogEventActionDeleteMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionDeleteMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantJoin::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantJoin::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantJoin>();
}

void channelAdminLogEventActionParticipantJoin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantJoin");
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantLeave::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantLeave::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantLeave>();
}

void channelAdminLogEventActionParticipantLeave::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantLeave");
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantInvite::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantInvite::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantInvite>(p);
}

channelAdminLogEventActionParticipantInvite::channelAdminLogEventActionParticipantInvite(TlBufferParser &p)
  : participant_(TlFetchObject<ChannelParticipant>::parse(p))
{}

void channelAdminLogEventActionParticipantInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantInvite");
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantToggleBan::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantToggleBan::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantToggleBan>(p);
}

channelAdminLogEventActionParticipantToggleBan::channelAdminLogEventActionParticipantToggleBan(TlBufferParser &p)
  : prev_participant_(TlFetchObject<ChannelParticipant>::parse(p))
  , new_participant_(TlFetchObject<ChannelParticipant>::parse(p))
{}

void channelAdminLogEventActionParticipantToggleBan::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantToggleBan");
    s.store_object_field("prev_participant", static_cast<const BaseObject *>(prev_participant_.get()));
    s.store_object_field("new_participant", static_cast<const BaseObject *>(new_participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantToggleAdmin::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantToggleAdmin::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantToggleAdmin>(p);
}

channelAdminLogEventActionParticipantToggleAdmin::channelAdminLogEventActionParticipantToggleAdmin(TlBufferParser &p)
  : prev_participant_(TlFetchObject<ChannelParticipant>::parse(p))
  , new_participant_(TlFetchObject<ChannelParticipant>::parse(p))
{}

void channelAdminLogEventActionParticipantToggleAdmin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantToggleAdmin");
    s.store_object_field("prev_participant", static_cast<const BaseObject *>(prev_participant_.get()));
    s.store_object_field("new_participant", static_cast<const BaseObject *>(new_participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeStickerSet::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeStickerSet::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeStickerSet>(p);
}

channelAdminLogEventActionChangeStickerSet::channelAdminLogEventActionChangeStickerSet(TlBufferParser &p)
  : prev_stickerset_(TlFetchObject<InputStickerSet>::parse(p))
  , new_stickerset_(TlFetchObject<InputStickerSet>::parse(p))
{}

void channelAdminLogEventActionChangeStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeStickerSet");
    s.store_object_field("prev_stickerset", static_cast<const BaseObject *>(prev_stickerset_.get()));
    s.store_object_field("new_stickerset", static_cast<const BaseObject *>(new_stickerset_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionTogglePreHistoryHidden::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionTogglePreHistoryHidden::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionTogglePreHistoryHidden>(p);
}

channelAdminLogEventActionTogglePreHistoryHidden::channelAdminLogEventActionTogglePreHistoryHidden(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionTogglePreHistoryHidden::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionTogglePreHistoryHidden");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionDefaultBannedRights::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionDefaultBannedRights::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionDefaultBannedRights>(p);
}

channelAdminLogEventActionDefaultBannedRights::channelAdminLogEventActionDefaultBannedRights(TlBufferParser &p)
  : prev_banned_rights_(TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p))
  , new_banned_rights_(TlFetchBoxed<TlFetchObject<chatBannedRights>, -1626209256>::parse(p))
{}

void channelAdminLogEventActionDefaultBannedRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionDefaultBannedRights");
    s.store_object_field("prev_banned_rights", static_cast<const BaseObject *>(prev_banned_rights_.get()));
    s.store_object_field("new_banned_rights", static_cast<const BaseObject *>(new_banned_rights_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionStopPoll::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionStopPoll::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionStopPoll>(p);
}

channelAdminLogEventActionStopPoll::channelAdminLogEventActionStopPoll(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void channelAdminLogEventActionStopPoll::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionStopPoll");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeLinkedChat::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeLinkedChat::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeLinkedChat>(p);
}

channelAdminLogEventActionChangeLinkedChat::channelAdminLogEventActionChangeLinkedChat(TlBufferParser &p)
  : prev_value_(TlFetchLong::parse(p))
  , new_value_(TlFetchLong::parse(p))
{}

void channelAdminLogEventActionChangeLinkedChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeLinkedChat");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeLocation::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeLocation::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeLocation>(p);
}

channelAdminLogEventActionChangeLocation::channelAdminLogEventActionChangeLocation(TlBufferParser &p)
  : prev_value_(TlFetchObject<ChannelLocation>::parse(p))
  , new_value_(TlFetchObject<ChannelLocation>::parse(p))
{}

void channelAdminLogEventActionChangeLocation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeLocation");
    s.store_object_field("prev_value", static_cast<const BaseObject *>(prev_value_.get()));
    s.store_object_field("new_value", static_cast<const BaseObject *>(new_value_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleSlowMode::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleSlowMode::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleSlowMode>(p);
}

channelAdminLogEventActionToggleSlowMode::channelAdminLogEventActionToggleSlowMode(TlBufferParser &p)
  : prev_value_(TlFetchInt::parse(p))
  , new_value_(TlFetchInt::parse(p))
{}

void channelAdminLogEventActionToggleSlowMode::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleSlowMode");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionStartGroupCall::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionStartGroupCall::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionStartGroupCall>(p);
}

channelAdminLogEventActionStartGroupCall::channelAdminLogEventActionStartGroupCall(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
{}

void channelAdminLogEventActionStartGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionStartGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionDiscardGroupCall::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionDiscardGroupCall::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionDiscardGroupCall>(p);
}

channelAdminLogEventActionDiscardGroupCall::channelAdminLogEventActionDiscardGroupCall(TlBufferParser &p)
  : call_(TlFetchObject<InputGroupCall>::parse(p))
{}

void channelAdminLogEventActionDiscardGroupCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionDiscardGroupCall");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantMute::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantMute::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantMute>(p);
}

channelAdminLogEventActionParticipantMute::channelAdminLogEventActionParticipantMute(TlBufferParser &p)
  : participant_(TlFetchBoxed<TlFetchObject<groupCallParticipant>, 708691884>::parse(p))
{}

void channelAdminLogEventActionParticipantMute::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantMute");
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantUnmute::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantUnmute::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantUnmute>(p);
}

channelAdminLogEventActionParticipantUnmute::channelAdminLogEventActionParticipantUnmute(TlBufferParser &p)
  : participant_(TlFetchBoxed<TlFetchObject<groupCallParticipant>, 708691884>::parse(p))
{}

void channelAdminLogEventActionParticipantUnmute::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantUnmute");
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleGroupCallSetting::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleGroupCallSetting::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleGroupCallSetting>(p);
}

channelAdminLogEventActionToggleGroupCallSetting::channelAdminLogEventActionToggleGroupCallSetting(TlBufferParser &p)
  : join_muted_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleGroupCallSetting::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleGroupCallSetting");
    s.store_field("join_muted", join_muted_);
    s.store_class_end();
  }
}

channelAdminLogEventActionParticipantJoinByInvite::channelAdminLogEventActionParticipantJoinByInvite()
  : flags_()
  , via_chatlist_()
  , invite_()
{}

const std::int32_t channelAdminLogEventActionParticipantJoinByInvite::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantJoinByInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelAdminLogEventActionParticipantJoinByInvite> res = make_tl_object<channelAdminLogEventActionParticipantJoinByInvite>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->via_chatlist_ = (var0 & 1) != 0;
  res->invite_ = TlFetchObject<ExportedChatInvite>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelAdminLogEventActionParticipantJoinByInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantJoinByInvite");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (via_chatlist_ << 0)));
    if (var0 & 1) { s.store_field("via_chatlist", true); }
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionExportedInviteDelete::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionExportedInviteDelete::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionExportedInviteDelete>(p);
}

channelAdminLogEventActionExportedInviteDelete::channelAdminLogEventActionExportedInviteDelete(TlBufferParser &p)
  : invite_(TlFetchObject<ExportedChatInvite>::parse(p))
{}

void channelAdminLogEventActionExportedInviteDelete::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionExportedInviteDelete");
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionExportedInviteRevoke::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionExportedInviteRevoke::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionExportedInviteRevoke>(p);
}

channelAdminLogEventActionExportedInviteRevoke::channelAdminLogEventActionExportedInviteRevoke(TlBufferParser &p)
  : invite_(TlFetchObject<ExportedChatInvite>::parse(p))
{}

void channelAdminLogEventActionExportedInviteRevoke::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionExportedInviteRevoke");
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionExportedInviteEdit::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionExportedInviteEdit::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionExportedInviteEdit>(p);
}

channelAdminLogEventActionExportedInviteEdit::channelAdminLogEventActionExportedInviteEdit(TlBufferParser &p)
  : prev_invite_(TlFetchObject<ExportedChatInvite>::parse(p))
  , new_invite_(TlFetchObject<ExportedChatInvite>::parse(p))
{}

void channelAdminLogEventActionExportedInviteEdit::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionExportedInviteEdit");
    s.store_object_field("prev_invite", static_cast<const BaseObject *>(prev_invite_.get()));
    s.store_object_field("new_invite", static_cast<const BaseObject *>(new_invite_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantVolume::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantVolume::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantVolume>(p);
}

channelAdminLogEventActionParticipantVolume::channelAdminLogEventActionParticipantVolume(TlBufferParser &p)
  : participant_(TlFetchBoxed<TlFetchObject<groupCallParticipant>, 708691884>::parse(p))
{}

void channelAdminLogEventActionParticipantVolume::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantVolume");
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeHistoryTTL::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeHistoryTTL::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeHistoryTTL>(p);
}

channelAdminLogEventActionChangeHistoryTTL::channelAdminLogEventActionChangeHistoryTTL(TlBufferParser &p)
  : prev_value_(TlFetchInt::parse(p))
  , new_value_(TlFetchInt::parse(p))
{}

void channelAdminLogEventActionChangeHistoryTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeHistoryTTL");
    s.store_field("prev_value", prev_value_);
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantJoinByRequest::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantJoinByRequest::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantJoinByRequest>(p);
}

channelAdminLogEventActionParticipantJoinByRequest::channelAdminLogEventActionParticipantJoinByRequest(TlBufferParser &p)
  : invite_(TlFetchObject<ExportedChatInvite>::parse(p))
  , approved_by_(TlFetchLong::parse(p))
{}

void channelAdminLogEventActionParticipantJoinByRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantJoinByRequest");
    s.store_object_field("invite", static_cast<const BaseObject *>(invite_.get()));
    s.store_field("approved_by", approved_by_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleNoForwards::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleNoForwards::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleNoForwards>(p);
}

channelAdminLogEventActionToggleNoForwards::channelAdminLogEventActionToggleNoForwards(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleNoForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleNoForwards");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionSendMessage::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionSendMessage::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionSendMessage>(p);
}

channelAdminLogEventActionSendMessage::channelAdminLogEventActionSendMessage(TlBufferParser &p)
  : message_(TlFetchObject<Message>::parse(p))
{}

void channelAdminLogEventActionSendMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionSendMessage");
    s.store_object_field("message", static_cast<const BaseObject *>(message_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeAvailableReactions::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeAvailableReactions::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeAvailableReactions>(p);
}

channelAdminLogEventActionChangeAvailableReactions::channelAdminLogEventActionChangeAvailableReactions(TlBufferParser &p)
  : prev_value_(TlFetchObject<ChatReactions>::parse(p))
  , new_value_(TlFetchObject<ChatReactions>::parse(p))
{}

void channelAdminLogEventActionChangeAvailableReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeAvailableReactions");
    s.store_object_field("prev_value", static_cast<const BaseObject *>(prev_value_.get()));
    s.store_object_field("new_value", static_cast<const BaseObject *>(new_value_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeUsernames::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeUsernames::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeUsernames>(p);
}

channelAdminLogEventActionChangeUsernames::channelAdminLogEventActionChangeUsernames(TlBufferParser &p)
  : prev_value_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
  , new_value_(TlFetchBoxed<TlFetchVector<TlFetchString<string>>, 481674261>::parse(p))
{}

void channelAdminLogEventActionChangeUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeUsernames");
    { s.store_vector_begin("prev_value", prev_value_.size()); for (const auto &_value : prev_value_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("new_value", new_value_.size()); for (const auto &_value : new_value_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleForum::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleForum::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleForum>(p);
}

channelAdminLogEventActionToggleForum::channelAdminLogEventActionToggleForum(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleForum::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleForum");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionCreateTopic::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionCreateTopic::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionCreateTopic>(p);
}

channelAdminLogEventActionCreateTopic::channelAdminLogEventActionCreateTopic(TlBufferParser &p)
  : topic_(TlFetchObject<ForumTopic>::parse(p))
{}

void channelAdminLogEventActionCreateTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionCreateTopic");
    s.store_object_field("topic", static_cast<const BaseObject *>(topic_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionEditTopic::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionEditTopic::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionEditTopic>(p);
}

channelAdminLogEventActionEditTopic::channelAdminLogEventActionEditTopic(TlBufferParser &p)
  : prev_topic_(TlFetchObject<ForumTopic>::parse(p))
  , new_topic_(TlFetchObject<ForumTopic>::parse(p))
{}

void channelAdminLogEventActionEditTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionEditTopic");
    s.store_object_field("prev_topic", static_cast<const BaseObject *>(prev_topic_.get()));
    s.store_object_field("new_topic", static_cast<const BaseObject *>(new_topic_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionDeleteTopic::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionDeleteTopic::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionDeleteTopic>(p);
}

channelAdminLogEventActionDeleteTopic::channelAdminLogEventActionDeleteTopic(TlBufferParser &p)
  : topic_(TlFetchObject<ForumTopic>::parse(p))
{}

void channelAdminLogEventActionDeleteTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionDeleteTopic");
    s.store_object_field("topic", static_cast<const BaseObject *>(topic_.get()));
    s.store_class_end();
  }
}

channelAdminLogEventActionPinTopic::channelAdminLogEventActionPinTopic()
  : flags_()
  , prev_topic_()
  , new_topic_()
{}

const std::int32_t channelAdminLogEventActionPinTopic::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionPinTopic::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<channelAdminLogEventActionPinTopic> res = make_tl_object<channelAdminLogEventActionPinTopic>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->prev_topic_ = TlFetchObject<ForumTopic>::parse(p); }
  if (var0 & 2) { res->new_topic_ = TlFetchObject<ForumTopic>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void channelAdminLogEventActionPinTopic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionPinTopic");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("prev_topic", static_cast<const BaseObject *>(prev_topic_.get())); }
    if (var0 & 2) { s.store_object_field("new_topic", static_cast<const BaseObject *>(new_topic_.get())); }
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleAntiSpam::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleAntiSpam::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleAntiSpam>(p);
}

channelAdminLogEventActionToggleAntiSpam::channelAdminLogEventActionToggleAntiSpam(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleAntiSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleAntiSpam");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangePeerColor::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangePeerColor::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangePeerColor>(p);
}

channelAdminLogEventActionChangePeerColor::channelAdminLogEventActionChangePeerColor(TlBufferParser &p)
  : prev_value_(TlFetchObject<PeerColor>::parse(p))
  , new_value_(TlFetchObject<PeerColor>::parse(p))
{}

void channelAdminLogEventActionChangePeerColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangePeerColor");
    s.store_object_field("prev_value", static_cast<const BaseObject *>(prev_value_.get()));
    s.store_object_field("new_value", static_cast<const BaseObject *>(new_value_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeProfilePeerColor::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeProfilePeerColor::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeProfilePeerColor>(p);
}

channelAdminLogEventActionChangeProfilePeerColor::channelAdminLogEventActionChangeProfilePeerColor(TlBufferParser &p)
  : prev_value_(TlFetchObject<PeerColor>::parse(p))
  , new_value_(TlFetchObject<PeerColor>::parse(p))
{}

void channelAdminLogEventActionChangeProfilePeerColor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeProfilePeerColor");
    s.store_object_field("prev_value", static_cast<const BaseObject *>(prev_value_.get()));
    s.store_object_field("new_value", static_cast<const BaseObject *>(new_value_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeWallpaper::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeWallpaper::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeWallpaper>(p);
}

channelAdminLogEventActionChangeWallpaper::channelAdminLogEventActionChangeWallpaper(TlBufferParser &p)
  : prev_value_(TlFetchObject<WallPaper>::parse(p))
  , new_value_(TlFetchObject<WallPaper>::parse(p))
{}

void channelAdminLogEventActionChangeWallpaper::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeWallpaper");
    s.store_object_field("prev_value", static_cast<const BaseObject *>(prev_value_.get()));
    s.store_object_field("new_value", static_cast<const BaseObject *>(new_value_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeEmojiStatus::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeEmojiStatus::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeEmojiStatus>(p);
}

channelAdminLogEventActionChangeEmojiStatus::channelAdminLogEventActionChangeEmojiStatus(TlBufferParser &p)
  : prev_value_(TlFetchObject<EmojiStatus>::parse(p))
  , new_value_(TlFetchObject<EmojiStatus>::parse(p))
{}

void channelAdminLogEventActionChangeEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeEmojiStatus");
    s.store_object_field("prev_value", static_cast<const BaseObject *>(prev_value_.get()));
    s.store_object_field("new_value", static_cast<const BaseObject *>(new_value_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionChangeEmojiStickerSet::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionChangeEmojiStickerSet::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionChangeEmojiStickerSet>(p);
}

channelAdminLogEventActionChangeEmojiStickerSet::channelAdminLogEventActionChangeEmojiStickerSet(TlBufferParser &p)
  : prev_stickerset_(TlFetchObject<InputStickerSet>::parse(p))
  , new_stickerset_(TlFetchObject<InputStickerSet>::parse(p))
{}

void channelAdminLogEventActionChangeEmojiStickerSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionChangeEmojiStickerSet");
    s.store_object_field("prev_stickerset", static_cast<const BaseObject *>(prev_stickerset_.get()));
    s.store_object_field("new_stickerset", static_cast<const BaseObject *>(new_stickerset_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleSignatureProfiles::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleSignatureProfiles::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleSignatureProfiles>(p);
}

channelAdminLogEventActionToggleSignatureProfiles::channelAdminLogEventActionToggleSignatureProfiles(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleSignatureProfiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleSignatureProfiles");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantSubExtend::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantSubExtend::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantSubExtend>(p);
}

channelAdminLogEventActionParticipantSubExtend::channelAdminLogEventActionParticipantSubExtend(TlBufferParser &p)
  : prev_participant_(TlFetchObject<ChannelParticipant>::parse(p))
  , new_participant_(TlFetchObject<ChannelParticipant>::parse(p))
{}

void channelAdminLogEventActionParticipantSubExtend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantSubExtend");
    s.store_object_field("prev_participant", static_cast<const BaseObject *>(prev_participant_.get()));
    s.store_object_field("new_participant", static_cast<const BaseObject *>(new_participant_.get()));
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionToggleAutotranslation::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionToggleAutotranslation::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionToggleAutotranslation>(p);
}

channelAdminLogEventActionToggleAutotranslation::channelAdminLogEventActionToggleAutotranslation(TlBufferParser &p)
  : new_value_(TlFetchBool::parse(p))
{}

void channelAdminLogEventActionToggleAutotranslation::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionToggleAutotranslation");
    s.store_field("new_value", new_value_);
    s.store_class_end();
  }
}

const std::int32_t channelAdminLogEventActionParticipantEditRank::ID;

object_ptr<ChannelAdminLogEventAction> channelAdminLogEventActionParticipantEditRank::fetch(TlBufferParser &p) {
  return make_tl_object<channelAdminLogEventActionParticipantEditRank>(p);
}

channelAdminLogEventActionParticipantEditRank::channelAdminLogEventActionParticipantEditRank(TlBufferParser &p)
  : user_id_(TlFetchLong::parse(p))
  , prev_rank_(TlFetchString<string>::parse(p))
  , new_rank_(TlFetchString<string>::parse(p))
{}

void channelAdminLogEventActionParticipantEditRank::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channelAdminLogEventActionParticipantEditRank");
    s.store_field("user_id", user_id_);
    s.store_field("prev_rank", prev_rank_);
    s.store_field("new_rank", new_rank_);
    s.store_class_end();
  }
}

chatAdminRights::chatAdminRights()
  : flags_()
  , change_info_()
  , post_messages_()
  , edit_messages_()
  , delete_messages_()
  , ban_users_()
  , invite_users_()
  , pin_messages_()
  , add_admins_()
  , anonymous_()
  , manage_call_()
  , other_()
  , manage_topics_()
  , post_stories_()
  , edit_stories_()
  , delete_stories_()
  , manage_direct_messages_()
  , manage_ranks_()
{}

chatAdminRights::chatAdminRights(int32 flags_, bool change_info_, bool post_messages_, bool edit_messages_, bool delete_messages_, bool ban_users_, bool invite_users_, bool pin_messages_, bool add_admins_, bool anonymous_, bool manage_call_, bool other_, bool manage_topics_, bool post_stories_, bool edit_stories_, bool delete_stories_, bool manage_direct_messages_, bool manage_ranks_)
  : flags_(flags_)
  , change_info_(change_info_)
  , post_messages_(post_messages_)
  , edit_messages_(edit_messages_)
  , delete_messages_(delete_messages_)
  , ban_users_(ban_users_)
  , invite_users_(invite_users_)
  , pin_messages_(pin_messages_)
  , add_admins_(add_admins_)
  , anonymous_(anonymous_)
  , manage_call_(manage_call_)
  , other_(other_)
  , manage_topics_(manage_topics_)
  , post_stories_(post_stories_)
  , edit_stories_(edit_stories_)
  , delete_stories_(delete_stories_)
  , manage_direct_messages_(manage_direct_messages_)
  , manage_ranks_(manage_ranks_)
{}

const std::int32_t chatAdminRights::ID;

object_ptr<chatAdminRights> chatAdminRights::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatAdminRights> res = make_tl_object<chatAdminRights>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->change_info_ = (var0 & 1) != 0;
  res->post_messages_ = (var0 & 2) != 0;
  res->edit_messages_ = (var0 & 4) != 0;
  res->delete_messages_ = (var0 & 8) != 0;
  res->ban_users_ = (var0 & 16) != 0;
  res->invite_users_ = (var0 & 32) != 0;
  res->pin_messages_ = (var0 & 128) != 0;
  res->add_admins_ = (var0 & 512) != 0;
  res->anonymous_ = (var0 & 1024) != 0;
  res->manage_call_ = (var0 & 2048) != 0;
  res->other_ = (var0 & 4096) != 0;
  res->manage_topics_ = (var0 & 8192) != 0;
  res->post_stories_ = (var0 & 16384) != 0;
  res->edit_stories_ = (var0 & 32768) != 0;
  res->delete_stories_ = (var0 & 65536) != 0;
  res->manage_direct_messages_ = (var0 & 131072) != 0;
  res->manage_ranks_ = (var0 & 262144) != 0;
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void chatAdminRights::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (change_info_ << 0) | (post_messages_ << 1) | (edit_messages_ << 2) | (delete_messages_ << 3) | (ban_users_ << 4) | (invite_users_ << 5) | (pin_messages_ << 7) | (add_admins_ << 9) | (anonymous_ << 10) | (manage_call_ << 11) | (other_ << 12) | (manage_topics_ << 13) | (post_stories_ << 14) | (edit_stories_ << 15) | (delete_stories_ << 16) | (manage_direct_messages_ << 17) | (manage_ranks_ << 18)), s);
}

void chatAdminRights::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (change_info_ << 0) | (post_messages_ << 1) | (edit_messages_ << 2) | (delete_messages_ << 3) | (ban_users_ << 4) | (invite_users_ << 5) | (pin_messages_ << 7) | (add_admins_ << 9) | (anonymous_ << 10) | (manage_call_ << 11) | (other_ << 12) | (manage_topics_ << 13) | (post_stories_ << 14) | (edit_stories_ << 15) | (delete_stories_ << 16) | (manage_direct_messages_ << 17) | (manage_ranks_ << 18)), s);
}

void chatAdminRights::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatAdminRights");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (change_info_ << 0) | (post_messages_ << 1) | (edit_messages_ << 2) | (delete_messages_ << 3) | (ban_users_ << 4) | (invite_users_ << 5) | (pin_messages_ << 7) | (add_admins_ << 9) | (anonymous_ << 10) | (manage_call_ << 11) | (other_ << 12) | (manage_topics_ << 13) | (post_stories_ << 14) | (edit_stories_ << 15) | (delete_stories_ << 16) | (manage_direct_messages_ << 17) | (manage_ranks_ << 18)));
    if (var0 & 1) { s.store_field("change_info", true); }
    if (var0 & 2) { s.store_field("post_messages", true); }
    if (var0 & 4) { s.store_field("edit_messages", true); }
    if (var0 & 8) { s.store_field("delete_messages", true); }
    if (var0 & 16) { s.store_field("ban_users", true); }
    if (var0 & 32) { s.store_field("invite_users", true); }
    if (var0 & 128) { s.store_field("pin_messages", true); }
    if (var0 & 512) { s.store_field("add_admins", true); }
    if (var0 & 1024) { s.store_field("anonymous", true); }
    if (var0 & 2048) { s.store_field("manage_call", true); }
    if (var0 & 4096) { s.store_field("other", true); }
    if (var0 & 8192) { s.store_field("manage_topics", true); }
    if (var0 & 16384) { s.store_field("post_stories", true); }
    if (var0 & 32768) { s.store_field("edit_stories", true); }
    if (var0 & 65536) { s.store_field("delete_stories", true); }
    if (var0 & 131072) { s.store_field("manage_direct_messages", true); }
    if (var0 & 262144) { s.store_field("manage_ranks", true); }
    s.store_class_end();
  }
}

dcOption::dcOption()
  : flags_()
  , ipv6_()
  , media_only_()
  , tcpo_only_()
  , cdn_()
  , static_()
  , this_port_only_()
  , id_()
  , ip_address_()
  , port_()
  , secret_()
{}

const std::int32_t dcOption::ID;

object_ptr<dcOption> dcOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<dcOption> res = make_tl_object<dcOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->ipv6_ = (var0 & 1) != 0;
  res->media_only_ = (var0 & 2) != 0;
  res->tcpo_only_ = (var0 & 4) != 0;
  res->cdn_ = (var0 & 8) != 0;
  res->static_ = (var0 & 16) != 0;
  res->this_port_only_ = (var0 & 32) != 0;
  res->id_ = TlFetchInt::parse(p);
  res->ip_address_ = TlFetchString<string>::parse(p);
  res->port_ = TlFetchInt::parse(p);
  if (var0 & 1024) { res->secret_ = TlFetchBytes<bytes>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void dcOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "dcOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (ipv6_ << 0) | (media_only_ << 1) | (tcpo_only_ << 2) | (cdn_ << 3) | (static_ << 4) | (this_port_only_ << 5)));
    if (var0 & 1) { s.store_field("ipv6", true); }
    if (var0 & 2) { s.store_field("media_only", true); }
    if (var0 & 4) { s.store_field("tcpo_only", true); }
    if (var0 & 8) { s.store_field("cdn", true); }
    if (var0 & 16) { s.store_field("static", true); }
    if (var0 & 32) { s.store_field("this_port_only", true); }
    s.store_field("id", id_);
    s.store_field("ip_address", ip_address_);
    s.store_field("port", port_);
    if (var0 & 1024) { s.store_bytes_field("secret", secret_); }
    s.store_class_end();
  }
}

const std::int32_t defaultHistoryTTL::ID;

object_ptr<defaultHistoryTTL> defaultHistoryTTL::fetch(TlBufferParser &p) {
  return make_tl_object<defaultHistoryTTL>(p);
}

defaultHistoryTTL::defaultHistoryTTL(TlBufferParser &p)
  : period_(TlFetchInt::parse(p))
{}

void defaultHistoryTTL::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "defaultHistoryTTL");
    s.store_field("period", period_);
    s.store_class_end();
  }
}

object_ptr<Document> Document::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case documentEmpty::ID:
      return documentEmpty::fetch(p);
    case document::ID:
      return document::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

documentEmpty::documentEmpty(int64 id_)
  : id_(id_)
{}

const std::int32_t documentEmpty::ID;

object_ptr<Document> documentEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<documentEmpty>(p);
}

documentEmpty::documentEmpty(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void documentEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void documentEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void documentEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "documentEmpty");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

document::document()
  : flags_()
  , id_()
  , access_hash_()
  , file_reference_()
  , date_()
  , mime_type_()
  , size_()
  , thumbs_()
  , video_thumbs_()
  , dc_id_()
  , attributes_()
{}

document::document(int32 flags_, int64 id_, int64 access_hash_, bytes &&file_reference_, int32 date_, string const &mime_type_, int64 size_, array<object_ptr<PhotoSize>> &&thumbs_, array<object_ptr<VideoSize>> &&video_thumbs_, int32 dc_id_, array<object_ptr<DocumentAttribute>> &&attributes_)
  : flags_(flags_)
  , id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
  , date_(date_)
  , mime_type_(mime_type_)
  , size_(size_)
  , thumbs_(std::move(thumbs_))
  , video_thumbs_(std::move(video_thumbs_))
  , dc_id_(dc_id_)
  , attributes_(std::move(attributes_))
{}

const std::int32_t document::ID;

object_ptr<Document> document::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<document> res = make_tl_object<document>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchLong::parse(p);
  res->access_hash_ = TlFetchLong::parse(p);
  res->file_reference_ = TlFetchBytes<bytes>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  res->mime_type_ = TlFetchString<string>::parse(p);
  res->size_ = TlFetchLong::parse(p);
  if (var0 & 1) { res->thumbs_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PhotoSize>>, 481674261>::parse(p); }
  if (var0 & 2) { res->video_thumbs_ = TlFetchBoxed<TlFetchVector<TlFetchObject<VideoSize>>, 481674261>::parse(p); }
  res->dc_id_ = TlFetchInt::parse(p);
  res->attributes_ = TlFetchBoxed<TlFetchVector<TlFetchObject<DocumentAttribute>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void document::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreBinary::store(date_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBinary::store(size_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(thumbs_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(video_thumbs_, s); }
  TlStoreBinary::store(dc_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void document::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
  TlStoreBinary::store(date_, s);
  TlStoreString::store(mime_type_, s);
  TlStoreBinary::store(size_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(thumbs_, s); }
  if (var0 & 2) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(video_thumbs_, s); }
  TlStoreBinary::store(dc_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(attributes_, s);
}

void document::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "document");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_field("date", date_);
    s.store_field("mime_type", mime_type_);
    s.store_field("size", size_);
    if (var0 & 1) { { s.store_vector_begin("thumbs", thumbs_.size()); for (const auto &_value : thumbs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { { s.store_vector_begin("video_thumbs", video_thumbs_.size()); for (const auto &_value : video_thumbs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_field("dc_id", dc_id_);
    { s.store_vector_begin("attributes", attributes_.size()); for (const auto &_value : attributes_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t emojiLanguage::ID;

object_ptr<emojiLanguage> emojiLanguage::fetch(TlBufferParser &p) {
  return make_tl_object<emojiLanguage>(p);
}

emojiLanguage::emojiLanguage(TlBufferParser &p)
  : lang_code_(TlFetchString<string>::parse(p))
{}

void emojiLanguage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "emojiLanguage");
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

inputChatlistDialogFilter::inputChatlistDialogFilter(int32 filter_id_)
  : filter_id_(filter_id_)
{}

const std::int32_t inputChatlistDialogFilter::ID;

void inputChatlistDialogFilter::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(filter_id_, s);
}

void inputChatlistDialogFilter::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(filter_id_, s);
}

void inputChatlistDialogFilter::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputChatlistDialogFilter");
    s.store_field("filter_id", filter_id_);
    s.store_class_end();
  }
}

object_ptr<InputDocument> InputDocument::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case inputDocumentEmpty::ID:
      return inputDocumentEmpty::fetch(p);
    case inputDocument::ID:
      return inputDocument::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t inputDocumentEmpty::ID;

object_ptr<InputDocument> inputDocumentEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<inputDocumentEmpty>();
}

void inputDocumentEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputDocumentEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputDocumentEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputDocumentEmpty");
    s.store_class_end();
  }
}

inputDocument::inputDocument(int64 id_, int64 access_hash_, bytes &&file_reference_)
  : id_(id_)
  , access_hash_(access_hash_)
  , file_reference_(std::move(file_reference_))
{}

const std::int32_t inputDocument::ID;

object_ptr<InputDocument> inputDocument::fetch(TlBufferParser &p) {
  return make_tl_object<inputDocument>(p);
}

inputDocument::inputDocument(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
  , access_hash_(TlFetchLong::parse(p))
  , file_reference_(TlFetchBytes<bytes>::parse(p))
{}

void inputDocument::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
}

void inputDocument::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
  TlStoreString::store(file_reference_, s);
}

void inputDocument::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputDocument");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_bytes_field("file_reference", file_reference_);
    s.store_class_end();
  }
}

const std::int32_t inputEncryptedFileEmpty::ID;

void inputEncryptedFileEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputEncryptedFileEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputEncryptedFileEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEncryptedFileEmpty");
    s.store_class_end();
  }
}

inputEncryptedFileUploaded::inputEncryptedFileUploaded(int64 id_, int32 parts_, string const &md5_checksum_, int32 key_fingerprint_)
  : id_(id_)
  , parts_(parts_)
  , md5_checksum_(md5_checksum_)
  , key_fingerprint_(key_fingerprint_)
{}

const std::int32_t inputEncryptedFileUploaded::ID;

void inputEncryptedFileUploaded::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(md5_checksum_, s);
  TlStoreBinary::store(key_fingerprint_, s);
}

void inputEncryptedFileUploaded::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreString::store(md5_checksum_, s);
  TlStoreBinary::store(key_fingerprint_, s);
}

void inputEncryptedFileUploaded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEncryptedFileUploaded");
    s.store_field("id", id_);
    s.store_field("parts", parts_);
    s.store_field("md5_checksum", md5_checksum_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_class_end();
  }
}

inputEncryptedFile::inputEncryptedFile(int64 id_, int64 access_hash_)
  : id_(id_)
  , access_hash_(access_hash_)
{}

const std::int32_t inputEncryptedFile::ID;

void inputEncryptedFile::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputEncryptedFile::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(access_hash_, s);
}

void inputEncryptedFile::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEncryptedFile");
    s.store_field("id", id_);
    s.store_field("access_hash", access_hash_);
    s.store_class_end();
  }
}

inputEncryptedFileBigUploaded::inputEncryptedFileBigUploaded(int64 id_, int32 parts_, int32 key_fingerprint_)
  : id_(id_)
  , parts_(parts_)
  , key_fingerprint_(key_fingerprint_)
{}

const std::int32_t inputEncryptedFileBigUploaded::ID;

void inputEncryptedFileBigUploaded::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreBinary::store(key_fingerprint_, s);
}

void inputEncryptedFileBigUploaded::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(parts_, s);
  TlStoreBinary::store(key_fingerprint_, s);
}

void inputEncryptedFileBigUploaded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputEncryptedFileBigUploaded");
    s.store_field("id", id_);
    s.store_field("parts", parts_);
    s.store_field("key_fingerprint", key_fingerprint_);
    s.store_class_end();
  }
}

inputFolderPeer::inputFolderPeer(object_ptr<InputPeer> &&peer_, int32 folder_id_)
  : peer_(std::move(peer_))
  , folder_id_(folder_id_)
{}

const std::int32_t inputFolderPeer::ID;

void inputFolderPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(folder_id_, s);
}

void inputFolderPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(folder_id_, s);
}

void inputFolderPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputFolderPeer");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("folder_id", folder_id_);
    s.store_class_end();
  }
}

inputMessageID::inputMessageID(int32 id_)
  : id_(id_)
{}

const std::int32_t inputMessageID::ID;

void inputMessageID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputMessageID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputMessageID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageID");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

inputMessageReplyTo::inputMessageReplyTo(int32 id_)
  : id_(id_)
{}

const std::int32_t inputMessageReplyTo::ID;

void inputMessageReplyTo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputMessageReplyTo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
}

void inputMessageReplyTo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageReplyTo");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

const std::int32_t inputMessagePinned::ID;

void inputMessagePinned::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void inputMessagePinned::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void inputMessagePinned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessagePinned");
    s.store_class_end();
  }
}

inputMessageCallbackQuery::inputMessageCallbackQuery(int32 id_, int64 query_id_)
  : id_(id_)
  , query_id_(query_id_)
{}

const std::int32_t inputMessageCallbackQuery::ID;

void inputMessageCallbackQuery::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(query_id_, s);
}

void inputMessageCallbackQuery::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(id_, s);
  TlStoreBinary::store(query_id_, s);
}

void inputMessageCallbackQuery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMessageCallbackQuery");
    s.store_field("id", id_);
    s.store_field("query_id", query_id_);
    s.store_class_end();
  }
}

inputStarGiftAuction::inputStarGiftAuction(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t inputStarGiftAuction::ID;

void inputStarGiftAuction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(gift_id_, s);
}

void inputStarGiftAuction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(gift_id_, s);
}

void inputStarGiftAuction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStarGiftAuction");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

inputStarGiftAuctionSlug::inputStarGiftAuctionSlug(string const &slug_)
  : slug_(slug_)
{}

const std::int32_t inputStarGiftAuctionSlug::ID;

void inputStarGiftAuctionSlug::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputStarGiftAuctionSlug::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(slug_, s);
}

void inputStarGiftAuctionSlug::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputStarGiftAuctionSlug");
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

invoice::invoice()
  : flags_()
  , test_()
  , name_requested_()
  , phone_requested_()
  , email_requested_()
  , shipping_address_requested_()
  , flexible_()
  , phone_to_provider_()
  , email_to_provider_()
  , recurring_()
  , currency_()
  , prices_()
  , max_tip_amount_()
  , suggested_tip_amounts_()
  , terms_url_()
  , subscription_period_()
{}

invoice::invoice(int32 flags_, bool test_, bool name_requested_, bool phone_requested_, bool email_requested_, bool shipping_address_requested_, bool flexible_, bool phone_to_provider_, bool email_to_provider_, bool recurring_, string const &currency_, array<object_ptr<labeledPrice>> &&prices_, int64 max_tip_amount_, array<int64> &&suggested_tip_amounts_, string const &terms_url_, int32 subscription_period_)
  : flags_(flags_)
  , test_(test_)
  , name_requested_(name_requested_)
  , phone_requested_(phone_requested_)
  , email_requested_(email_requested_)
  , shipping_address_requested_(shipping_address_requested_)
  , flexible_(flexible_)
  , phone_to_provider_(phone_to_provider_)
  , email_to_provider_(email_to_provider_)
  , recurring_(recurring_)
  , currency_(currency_)
  , prices_(std::move(prices_))
  , max_tip_amount_(max_tip_amount_)
  , suggested_tip_amounts_(std::move(suggested_tip_amounts_))
  , terms_url_(terms_url_)
  , subscription_period_(subscription_period_)
{}

const std::int32_t invoice::ID;

object_ptr<invoice> invoice::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<invoice> res = make_tl_object<invoice>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->test_ = (var0 & 1) != 0;
  res->name_requested_ = (var0 & 2) != 0;
  res->phone_requested_ = (var0 & 4) != 0;
  res->email_requested_ = (var0 & 8) != 0;
  res->shipping_address_requested_ = (var0 & 16) != 0;
  res->flexible_ = (var0 & 32) != 0;
  res->phone_to_provider_ = (var0 & 64) != 0;
  res->email_to_provider_ = (var0 & 128) != 0;
  res->recurring_ = (var0 & 512) != 0;
  res->currency_ = TlFetchString<string>::parse(p);
  res->prices_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<labeledPrice>, -886477832>>, 481674261>::parse(p);
  if (var0 & 256) { res->max_tip_amount_ = TlFetchLong::parse(p); }
  if (var0 & 256) { res->suggested_tip_amounts_ = TlFetchBoxed<TlFetchVector<TlFetchLong>, 481674261>::parse(p); }
  if (var0 & 1024) { res->terms_url_ = TlFetchString<string>::parse(p); }
  if (var0 & 2048) { res->subscription_period_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void invoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (test_ << 0) | (name_requested_ << 1) | (phone_requested_ << 2) | (email_requested_ << 3) | (shipping_address_requested_ << 4) | (flexible_ << 5) | (phone_to_provider_ << 6) | (email_to_provider_ << 7) | (recurring_ << 9)), s);
  TlStoreString::store(currency_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -886477832>>, 481674261>::store(prices_, s);
  if (var0 & 256) { TlStoreBinary::store(max_tip_amount_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(suggested_tip_amounts_, s); }
  if (var0 & 1024) { TlStoreString::store(terms_url_, s); }
  if (var0 & 2048) { TlStoreBinary::store(subscription_period_, s); }
}

void invoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (test_ << 0) | (name_requested_ << 1) | (phone_requested_ << 2) | (email_requested_ << 3) | (shipping_address_requested_ << 4) | (flexible_ << 5) | (phone_to_provider_ << 6) | (email_to_provider_ << 7) | (recurring_ << 9)), s);
  TlStoreString::store(currency_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, -886477832>>, 481674261>::store(prices_, s);
  if (var0 & 256) { TlStoreBinary::store(max_tip_amount_, s); }
  if (var0 & 256) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(suggested_tip_amounts_, s); }
  if (var0 & 1024) { TlStoreString::store(terms_url_, s); }
  if (var0 & 2048) { TlStoreBinary::store(subscription_period_, s); }
}

void invoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "invoice");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (test_ << 0) | (name_requested_ << 1) | (phone_requested_ << 2) | (email_requested_ << 3) | (shipping_address_requested_ << 4) | (flexible_ << 5) | (phone_to_provider_ << 6) | (email_to_provider_ << 7) | (recurring_ << 9)));
    if (var0 & 1) { s.store_field("test", true); }
    if (var0 & 2) { s.store_field("name_requested", true); }
    if (var0 & 4) { s.store_field("phone_requested", true); }
    if (var0 & 8) { s.store_field("email_requested", true); }
    if (var0 & 16) { s.store_field("shipping_address_requested", true); }
    if (var0 & 32) { s.store_field("flexible", true); }
    if (var0 & 64) { s.store_field("phone_to_provider", true); }
    if (var0 & 128) { s.store_field("email_to_provider", true); }
    if (var0 & 512) { s.store_field("recurring", true); }
    s.store_field("currency", currency_);
    { s.store_vector_begin("prices", prices_.size()); for (const auto &_value : prices_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 256) { s.store_field("max_tip_amount", max_tip_amount_); }
    if (var0 & 256) { { s.store_vector_begin("suggested_tip_amounts", suggested_tip_amounts_.size()); for (const auto &_value : suggested_tip_amounts_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 1024) { s.store_field("terms_url", terms_url_); }
    if (var0 & 2048) { s.store_field("subscription_period", subscription_period_); }
    s.store_class_end();
  }
}

labeledPrice::labeledPrice(string const &label_, int64 amount_)
  : label_(label_)
  , amount_(amount_)
{}

const std::int32_t labeledPrice::ID;

object_ptr<labeledPrice> labeledPrice::fetch(TlBufferParser &p) {
  return make_tl_object<labeledPrice>(p);
}

labeledPrice::labeledPrice(TlBufferParser &p)
  : label_(TlFetchString<string>::parse(p))
  , amount_(TlFetchLong::parse(p))
{}

void labeledPrice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(label_, s);
  TlStoreBinary::store(amount_, s);
}

void labeledPrice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(label_, s);
  TlStoreBinary::store(amount_, s);
}

void labeledPrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "labeledPrice");
    s.store_field("label", label_);
    s.store_field("amount", amount_);
    s.store_class_end();
  }
}

const std::int32_t langPackDifference::ID;

object_ptr<langPackDifference> langPackDifference::fetch(TlBufferParser &p) {
  return make_tl_object<langPackDifference>(p);
}

langPackDifference::langPackDifference(TlBufferParser &p)
  : lang_code_(TlFetchString<string>::parse(p))
  , from_version_(TlFetchInt::parse(p))
  , version_(TlFetchInt::parse(p))
  , strings_(TlFetchBoxed<TlFetchVector<TlFetchObject<LangPackString>>, 481674261>::parse(p))
{}

void langPackDifference::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "langPackDifference");
    s.store_field("lang_code", lang_code_);
    s.store_field("from_version", from_version_);
    s.store_field("version", version_);
    { s.store_vector_begin("strings", strings_.size()); for (const auto &_value : strings_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<MediaArea> MediaArea::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

mediaAreaVenue::mediaAreaVenue(object_ptr<mediaAreaCoordinates> &&coordinates_, object_ptr<GeoPoint> &&geo_, string const &title_, string const &address_, string const &provider_, string const &venue_id_, string const &venue_type_)
  : coordinates_(std::move(coordinates_))
  , geo_(std::move(geo_))
  , title_(title_)
  , address_(address_)
  , provider_(provider_)
  , venue_id_(venue_id_)
  , venue_type_(venue_type_)
{}

const std::int32_t mediaAreaVenue::ID;

object_ptr<MediaArea> mediaAreaVenue::fetch(TlBufferParser &p) {
  return make_tl_object<mediaAreaVenue>(p);
}

mediaAreaVenue::mediaAreaVenue(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , geo_(TlFetchObject<GeoPoint>::parse(p))
  , title_(TlFetchString<string>::parse(p))
  , address_(TlFetchString<string>::parse(p))
  , provider_(TlFetchString<string>::parse(p))
  , venue_id_(TlFetchString<string>::parse(p))
  , venue_type_(TlFetchString<string>::parse(p))
{}

void mediaAreaVenue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
}

void mediaAreaVenue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  TlStoreString::store(title_, s);
  TlStoreString::store(address_, s);
  TlStoreString::store(provider_, s);
  TlStoreString::store(venue_id_, s);
  TlStoreString::store(venue_type_, s);
}

void mediaAreaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaVenue");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    s.store_field("title", title_);
    s.store_field("address", address_);
    s.store_field("provider", provider_);
    s.store_field("venue_id", venue_id_);
    s.store_field("venue_type", venue_type_);
    s.store_class_end();
  }
}

inputMediaAreaVenue::inputMediaAreaVenue(object_ptr<mediaAreaCoordinates> &&coordinates_, int64 query_id_, string const &result_id_)
  : coordinates_(std::move(coordinates_))
  , query_id_(query_id_)
  , result_id_(result_id_)
{}

const std::int32_t inputMediaAreaVenue::ID;

object_ptr<MediaArea> inputMediaAreaVenue::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaAreaVenue>(p);
}

inputMediaAreaVenue::inputMediaAreaVenue(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , query_id_(TlFetchLong::parse(p))
  , result_id_(TlFetchString<string>::parse(p))
{}

void inputMediaAreaVenue::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBinary::store(query_id_, s);
  TlStoreString::store(result_id_, s);
}

void inputMediaAreaVenue::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBinary::store(query_id_, s);
  TlStoreString::store(result_id_, s);
}

void inputMediaAreaVenue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaAreaVenue");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_field("query_id", query_id_);
    s.store_field("result_id", result_id_);
    s.store_class_end();
  }
}

mediaAreaGeoPoint::mediaAreaGeoPoint()
  : flags_()
  , coordinates_()
  , geo_()
  , address_()
{}

mediaAreaGeoPoint::mediaAreaGeoPoint(int32 flags_, object_ptr<mediaAreaCoordinates> &&coordinates_, object_ptr<GeoPoint> &&geo_, object_ptr<geoPointAddress> &&address_)
  : flags_(flags_)
  , coordinates_(std::move(coordinates_))
  , geo_(std::move(geo_))
  , address_(std::move(address_))
{}

const std::int32_t mediaAreaGeoPoint::ID;

object_ptr<MediaArea> mediaAreaGeoPoint::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<mediaAreaGeoPoint> res = make_tl_object<mediaAreaGeoPoint>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->coordinates_ = TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p);
  res->geo_ = TlFetchObject<GeoPoint>::parse(p);
  if (var0 & 1) { res->address_ = TlFetchBoxed<TlFetchObject<geoPointAddress>, -565420653>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void mediaAreaGeoPoint::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -565420653>::store(address_, s); }
}

void mediaAreaGeoPoint::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_, s);
  if (var0 & 1) { TlStoreBoxed<TlStoreObject, -565420653>::store(address_, s); }
}

void mediaAreaGeoPoint::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaGeoPoint");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_object_field("geo", static_cast<const BaseObject *>(geo_.get()));
    if (var0 & 1) { s.store_object_field("address", static_cast<const BaseObject *>(address_.get())); }
    s.store_class_end();
  }
}

mediaAreaSuggestedReaction::mediaAreaSuggestedReaction()
  : flags_()
  , dark_()
  , flipped_()
  , coordinates_()
  , reaction_()
{}

mediaAreaSuggestedReaction::mediaAreaSuggestedReaction(int32 flags_, bool dark_, bool flipped_, object_ptr<mediaAreaCoordinates> &&coordinates_, object_ptr<Reaction> &&reaction_)
  : flags_(flags_)
  , dark_(dark_)
  , flipped_(flipped_)
  , coordinates_(std::move(coordinates_))
  , reaction_(std::move(reaction_))
{}

const std::int32_t mediaAreaSuggestedReaction::ID;

object_ptr<MediaArea> mediaAreaSuggestedReaction::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<mediaAreaSuggestedReaction> res = make_tl_object<mediaAreaSuggestedReaction>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->dark_ = (var0 & 1) != 0;
  res->flipped_ = (var0 & 2) != 0;
  res->coordinates_ = TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p);
  res->reaction_ = TlFetchObject<Reaction>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void mediaAreaSuggestedReaction::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0) | (flipped_ << 1)), s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
}

void mediaAreaSuggestedReaction::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (dark_ << 0) | (flipped_ << 1)), s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reaction_, s);
}

void mediaAreaSuggestedReaction::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaSuggestedReaction");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (dark_ << 0) | (flipped_ << 1)));
    if (var0 & 1) { s.store_field("dark", true); }
    if (var0 & 2) { s.store_field("flipped", true); }
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_object_field("reaction", static_cast<const BaseObject *>(reaction_.get()));
    s.store_class_end();
  }
}

mediaAreaChannelPost::mediaAreaChannelPost(object_ptr<mediaAreaCoordinates> &&coordinates_, int64 channel_id_, int32 msg_id_)
  : coordinates_(std::move(coordinates_))
  , channel_id_(channel_id_)
  , msg_id_(msg_id_)
{}

const std::int32_t mediaAreaChannelPost::ID;

object_ptr<MediaArea> mediaAreaChannelPost::fetch(TlBufferParser &p) {
  return make_tl_object<mediaAreaChannelPost>(p);
}

mediaAreaChannelPost::mediaAreaChannelPost(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , channel_id_(TlFetchLong::parse(p))
  , msg_id_(TlFetchInt::parse(p))
{}

void mediaAreaChannelPost::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBinary::store(channel_id_, s);
  TlStoreBinary::store(msg_id_, s);
}

void mediaAreaChannelPost::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBinary::store(channel_id_, s);
  TlStoreBinary::store(msg_id_, s);
}

void mediaAreaChannelPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaChannelPost");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_field("channel_id", channel_id_);
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

inputMediaAreaChannelPost::inputMediaAreaChannelPost(object_ptr<mediaAreaCoordinates> &&coordinates_, object_ptr<InputChannel> &&channel_, int32 msg_id_)
  : coordinates_(std::move(coordinates_))
  , channel_(std::move(channel_))
  , msg_id_(msg_id_)
{}

const std::int32_t inputMediaAreaChannelPost::ID;

object_ptr<MediaArea> inputMediaAreaChannelPost::fetch(TlBufferParser &p) {
  return make_tl_object<inputMediaAreaChannelPost>(p);
}

inputMediaAreaChannelPost::inputMediaAreaChannelPost(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , channel_(TlFetchObject<InputChannel>::parse(p))
  , msg_id_(TlFetchInt::parse(p))
{}

void inputMediaAreaChannelPost::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
}

void inputMediaAreaChannelPost::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBinary::store(msg_id_, s);
}

void inputMediaAreaChannelPost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "inputMediaAreaChannelPost");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("msg_id", msg_id_);
    s.store_class_end();
  }
}

mediaAreaUrl::mediaAreaUrl(object_ptr<mediaAreaCoordinates> &&coordinates_, string const &url_)
  : coordinates_(std::move(coordinates_))
  , url_(url_)
{}

const std::int32_t mediaAreaUrl::ID;

object_ptr<MediaArea> mediaAreaUrl::fetch(TlBufferParser &p) {
  return make_tl_object<mediaAreaUrl>(p);
}

mediaAreaUrl::mediaAreaUrl(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , url_(TlFetchString<string>::parse(p))
{}

void mediaAreaUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(url_, s);
}

void mediaAreaUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(url_, s);
}

void mediaAreaUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaUrl");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_field("url", url_);
    s.store_class_end();
  }
}

mediaAreaWeather::mediaAreaWeather(object_ptr<mediaAreaCoordinates> &&coordinates_, string const &emoji_, double temperature_c_, int32 color_)
  : coordinates_(std::move(coordinates_))
  , emoji_(emoji_)
  , temperature_c_(temperature_c_)
  , color_(color_)
{}

const std::int32_t mediaAreaWeather::ID;

object_ptr<MediaArea> mediaAreaWeather::fetch(TlBufferParser &p) {
  return make_tl_object<mediaAreaWeather>(p);
}

mediaAreaWeather::mediaAreaWeather(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , emoji_(TlFetchString<string>::parse(p))
  , temperature_c_(TlFetchDouble::parse(p))
  , color_(TlFetchInt::parse(p))
{}

void mediaAreaWeather::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(emoji_, s);
  TlStoreBinary::store(temperature_c_, s);
  TlStoreBinary::store(color_, s);
}

void mediaAreaWeather::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(emoji_, s);
  TlStoreBinary::store(temperature_c_, s);
  TlStoreBinary::store(color_, s);
}

void mediaAreaWeather::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaWeather");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_field("emoji", emoji_);
    s.store_field("temperature_c", temperature_c_);
    s.store_field("color", color_);
    s.store_class_end();
  }
}

mediaAreaStarGift::mediaAreaStarGift(object_ptr<mediaAreaCoordinates> &&coordinates_, string const &slug_)
  : coordinates_(std::move(coordinates_))
  , slug_(slug_)
{}

const std::int32_t mediaAreaStarGift::ID;

object_ptr<MediaArea> mediaAreaStarGift::fetch(TlBufferParser &p) {
  return make_tl_object<mediaAreaStarGift>(p);
}

mediaAreaStarGift::mediaAreaStarGift(TlBufferParser &p)
  : coordinates_(TlFetchBoxed<TlFetchObject<mediaAreaCoordinates>, -808853502>::parse(p))
  , slug_(TlFetchString<string>::parse(p))
{}

void mediaAreaStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(slug_, s);
}

void mediaAreaStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreObject, -808853502>::store(coordinates_, s);
  TlStoreString::store(slug_, s);
}

void mediaAreaStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "mediaAreaStarGift");
    s.store_object_field("coordinates", static_cast<const BaseObject *>(coordinates_.get()));
    s.store_field("slug", slug_);
    s.store_class_end();
  }
}

object_ptr<MessagePeerVote> MessagePeerVote::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messagePeerVote::ID:
      return messagePeerVote::fetch(p);
    case messagePeerVoteInputOption::ID:
      return messagePeerVoteInputOption::fetch(p);
    case messagePeerVoteMultiple::ID:
      return messagePeerVoteMultiple::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messagePeerVote::ID;

object_ptr<MessagePeerVote> messagePeerVote::fetch(TlBufferParser &p) {
  return make_tl_object<messagePeerVote>(p);
}

messagePeerVote::messagePeerVote(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , option_(TlFetchBytes<bytes>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void messagePeerVote::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePeerVote");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_bytes_field("option", option_);
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t messagePeerVoteInputOption::ID;

object_ptr<MessagePeerVote> messagePeerVoteInputOption::fetch(TlBufferParser &p) {
  return make_tl_object<messagePeerVoteInputOption>(p);
}

messagePeerVoteInputOption::messagePeerVoteInputOption(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void messagePeerVoteInputOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePeerVoteInputOption");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("date", date_);
    s.store_class_end();
  }
}

const std::int32_t messagePeerVoteMultiple::ID;

object_ptr<MessagePeerVote> messagePeerVoteMultiple::fetch(TlBufferParser &p) {
  return make_tl_object<messagePeerVoteMultiple>(p);
}

messagePeerVoteMultiple::messagePeerVoteMultiple(TlBufferParser &p)
  : peer_(TlFetchObject<Peer>::parse(p))
  , options_(TlFetchBoxed<TlFetchVector<TlFetchBytes<bytes>>, 481674261>::parse(p))
  , date_(TlFetchInt::parse(p))
{}

void messagePeerVoteMultiple::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messagePeerVoteMultiple");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_bytes_field("", _value); } s.store_class_end(); }
    s.store_field("date", date_);
    s.store_class_end();
  }
}

myBoost::myBoost()
  : flags_()
  , slot_()
  , peer_()
  , date_()
  , expires_()
  , cooldown_until_date_()
{}

const std::int32_t myBoost::ID;

object_ptr<myBoost> myBoost::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<myBoost> res = make_tl_object<myBoost>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->slot_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->peer_ = TlFetchObject<Peer>::parse(p); }
  res->date_ = TlFetchInt::parse(p);
  res->expires_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->cooldown_until_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void myBoost::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "myBoost");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("slot", slot_);
    if (var0 & 1) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    s.store_field("date", date_);
    s.store_field("expires", expires_);
    if (var0 & 2) { s.store_field("cooldown_until_date", cooldown_until_date_); }
    s.store_class_end();
  }
}

object_ptr<PageListItem> PageListItem::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case pageListItemText::ID:
      return pageListItemText::fetch(p);
    case pageListItemBlocks::ID:
      return pageListItemBlocks::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

pageListItemText::pageListItemText(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t pageListItemText::ID;

object_ptr<PageListItem> pageListItemText::fetch(TlBufferParser &p) {
  return make_tl_object<pageListItemText>(p);
}

pageListItemText::pageListItemText(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void pageListItemText::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageListItemText::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void pageListItemText::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageListItemText");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

pageListItemBlocks::pageListItemBlocks(array<object_ptr<PageBlock>> &&blocks_)
  : blocks_(std::move(blocks_))
{}

const std::int32_t pageListItemBlocks::ID;

object_ptr<PageListItem> pageListItemBlocks::fetch(TlBufferParser &p) {
  return make_tl_object<pageListItemBlocks>(p);
}

pageListItemBlocks::pageListItemBlocks(TlBufferParser &p)
  : blocks_(TlFetchBoxed<TlFetchVector<TlFetchObject<PageBlock>>, 481674261>::parse(p))
{}

void pageListItemBlocks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
}

void pageListItemBlocks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(blocks_, s);
}

void pageListItemBlocks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pageListItemBlocks");
    { s.store_vector_begin("blocks", blocks_.size()); for (const auto &_value : blocks_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

passkey::passkey()
  : flags_()
  , id_()
  , name_()
  , date_()
  , software_emoji_id_()
  , last_usage_date_()
{}

const std::int32_t passkey::ID;

object_ptr<passkey> passkey::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<passkey> res = make_tl_object<passkey>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->id_ = TlFetchString<string>::parse(p);
  res->name_ = TlFetchString<string>::parse(p);
  res->date_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->software_emoji_id_ = TlFetchLong::parse(p); }
  if (var0 & 2) { res->last_usage_date_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void passkey::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "passkey");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("id", id_);
    s.store_field("name", name_);
    s.store_field("date", date_);
    if (var0 & 1) { s.store_field("software_emoji_id", software_emoji_id_); }
    if (var0 & 2) { s.store_field("last_usage_date", last_usage_date_); }
    s.store_class_end();
  }
}

paymentRequestedInfo::paymentRequestedInfo()
  : flags_()
  , name_()
  , phone_()
  , email_()
  , shipping_address_()
{}

paymentRequestedInfo::paymentRequestedInfo(int32 flags_, string const &name_, string const &phone_, string const &email_, object_ptr<postAddress> &&shipping_address_)
  : flags_(flags_)
  , name_(name_)
  , phone_(phone_)
  , email_(email_)
  , shipping_address_(std::move(shipping_address_))
{}

const std::int32_t paymentRequestedInfo::ID;

object_ptr<paymentRequestedInfo> paymentRequestedInfo::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<paymentRequestedInfo> res = make_tl_object<paymentRequestedInfo>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->name_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->phone_ = TlFetchString<string>::parse(p); }
  if (var0 & 4) { res->email_ = TlFetchString<string>::parse(p); }
  if (var0 & 8) { res->shipping_address_ = TlFetchBoxed<TlFetchObject<postAddress>, 512535275>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void paymentRequestedInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(name_, s); }
  if (var0 & 2) { TlStoreString::store(phone_, s); }
  if (var0 & 4) { TlStoreString::store(email_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, 512535275>::store(shipping_address_, s); }
}

void paymentRequestedInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(name_, s); }
  if (var0 & 2) { TlStoreString::store(phone_, s); }
  if (var0 & 4) { TlStoreString::store(email_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, 512535275>::store(shipping_address_, s); }
}

void paymentRequestedInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "paymentRequestedInfo");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("name", name_); }
    if (var0 & 2) { s.store_field("phone", phone_); }
    if (var0 & 4) { s.store_field("email", email_); }
    if (var0 & 8) { s.store_object_field("shipping_address", static_cast<const BaseObject *>(shipping_address_.get())); }
    s.store_class_end();
  }
}

object_ptr<PhoneConnection> PhoneConnection::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case phoneConnection::ID:
      return phoneConnection::fetch(p);
    case phoneConnectionWebrtc::ID:
      return phoneConnectionWebrtc::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

phoneConnection::phoneConnection()
  : flags_()
  , tcp_()
  , id_()
  , ip_()
  , ipv6_()
  , port_()
  , peer_tag_()
{}

const std::int32_t phoneConnection::ID;

object_ptr<PhoneConnection> phoneConnection::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneConnection> res = make_tl_object<phoneConnection>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->tcp_ = (var0 & 1) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->ip_ = TlFetchString<string>::parse(p);
  res->ipv6_ = TlFetchString<string>::parse(p);
  res->port_ = TlFetchInt::parse(p);
  res->peer_tag_ = TlFetchBytes<bytes>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneConnection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneConnection");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (tcp_ << 0)));
    if (var0 & 1) { s.store_field("tcp", true); }
    s.store_field("id", id_);
    s.store_field("ip", ip_);
    s.store_field("ipv6", ipv6_);
    s.store_field("port", port_);
    s.store_bytes_field("peer_tag", peer_tag_);
    s.store_class_end();
  }
}

phoneConnectionWebrtc::phoneConnectionWebrtc()
  : flags_()
  , turn_()
  , stun_()
  , id_()
  , ip_()
  , ipv6_()
  , port_()
  , username_()
  , password_()
{}

const std::int32_t phoneConnectionWebrtc::ID;

object_ptr<PhoneConnection> phoneConnectionWebrtc::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<phoneConnectionWebrtc> res = make_tl_object<phoneConnectionWebrtc>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->turn_ = (var0 & 1) != 0;
  res->stun_ = (var0 & 2) != 0;
  res->id_ = TlFetchLong::parse(p);
  res->ip_ = TlFetchString<string>::parse(p);
  res->ipv6_ = TlFetchString<string>::parse(p);
  res->port_ = TlFetchInt::parse(p);
  res->username_ = TlFetchString<string>::parse(p);
  res->password_ = TlFetchString<string>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void phoneConnectionWebrtc::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phoneConnectionWebrtc");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (turn_ << 0) | (stun_ << 1)));
    if (var0 & 1) { s.store_field("turn", true); }
    if (var0 & 2) { s.store_field("stun", true); }
    s.store_field("id", id_);
    s.store_field("ip", ip_);
    s.store_field("ipv6", ipv6_);
    s.store_field("port", port_);
    s.store_field("username", username_);
    s.store_field("password", password_);
    s.store_class_end();
  }
}

pollAnswerVoters::pollAnswerVoters()
  : flags_()
  , chosen_()
  , correct_()
  , option_()
  , voters_()
  , recent_voters_()
{}

pollAnswerVoters::pollAnswerVoters(int32 flags_, bool chosen_, bool correct_, bytes &&option_, int32 voters_, array<object_ptr<Peer>> &&recent_voters_)
  : flags_(flags_)
  , chosen_(chosen_)
  , correct_(correct_)
  , option_(std::move(option_))
  , voters_(voters_)
  , recent_voters_(std::move(recent_voters_))
{}

const std::int32_t pollAnswerVoters::ID;

object_ptr<pollAnswerVoters> pollAnswerVoters::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<pollAnswerVoters> res = make_tl_object<pollAnswerVoters>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->chosen_ = (var0 & 1) != 0;
  res->correct_ = (var0 & 2) != 0;
  res->option_ = TlFetchBytes<bytes>::parse(p);
  if (var0 & 4) { res->voters_ = TlFetchInt::parse(p); }
  if (var0 & 4) { res->recent_voters_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void pollAnswerVoters::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (chosen_ << 0) | (correct_ << 1)), s);
  TlStoreString::store(option_, s);
  if (var0 & 4) { TlStoreBinary::store(voters_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(recent_voters_, s); }
}

void pollAnswerVoters::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (chosen_ << 0) | (correct_ << 1)), s);
  TlStoreString::store(option_, s);
  if (var0 & 4) { TlStoreBinary::store(voters_, s); }
  if (var0 & 4) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(recent_voters_, s); }
}

void pollAnswerVoters::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "pollAnswerVoters");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (chosen_ << 0) | (correct_ << 1)));
    if (var0 & 1) { s.store_field("chosen", true); }
    if (var0 & 2) { s.store_field("correct", true); }
    s.store_bytes_field("option", option_);
    if (var0 & 4) { s.store_field("voters", voters_); }
    if (var0 & 4) { { s.store_vector_begin("recent_voters", recent_voters_.size()); for (const auto &_value : recent_voters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

object_ptr<ProfileTab> ProfileTab::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t profileTabPosts::ID;

object_ptr<ProfileTab> profileTabPosts::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabPosts>();
}

void profileTabPosts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabPosts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabPosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabPosts");
    s.store_class_end();
  }
}

const std::int32_t profileTabGifts::ID;

object_ptr<ProfileTab> profileTabGifts::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabGifts>();
}

void profileTabGifts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabGifts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabGifts");
    s.store_class_end();
  }
}

const std::int32_t profileTabMedia::ID;

object_ptr<ProfileTab> profileTabMedia::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabMedia>();
}

void profileTabMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabMedia");
    s.store_class_end();
  }
}

const std::int32_t profileTabFiles::ID;

object_ptr<ProfileTab> profileTabFiles::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabFiles>();
}

void profileTabFiles::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabFiles::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabFiles::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabFiles");
    s.store_class_end();
  }
}

const std::int32_t profileTabMusic::ID;

object_ptr<ProfileTab> profileTabMusic::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabMusic>();
}

void profileTabMusic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabMusic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabMusic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabMusic");
    s.store_class_end();
  }
}

const std::int32_t profileTabVoice::ID;

object_ptr<ProfileTab> profileTabVoice::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabVoice>();
}

void profileTabVoice::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabVoice::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabVoice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabVoice");
    s.store_class_end();
  }
}

const std::int32_t profileTabLinks::ID;

object_ptr<ProfileTab> profileTabLinks::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabLinks>();
}

void profileTabLinks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabLinks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabLinks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabLinks");
    s.store_class_end();
  }
}

const std::int32_t profileTabGifs::ID;

object_ptr<ProfileTab> profileTabGifs::fetch(TlBufferParser &p) {
  return make_tl_object<profileTabGifs>();
}

void profileTabGifs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void profileTabGifs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void profileTabGifs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "profileTabGifs");
    s.store_class_end();
  }
}

reactionsNotifySettings::reactionsNotifySettings()
  : flags_()
  , messages_notify_from_()
  , stories_notify_from_()
  , poll_votes_notify_from_()
  , sound_()
  , show_previews_()
{}

reactionsNotifySettings::reactionsNotifySettings(int32 flags_, object_ptr<ReactionNotificationsFrom> &&messages_notify_from_, object_ptr<ReactionNotificationsFrom> &&stories_notify_from_, object_ptr<ReactionNotificationsFrom> &&poll_votes_notify_from_, object_ptr<NotificationSound> &&sound_, bool show_previews_)
  : flags_(flags_)
  , messages_notify_from_(std::move(messages_notify_from_))
  , stories_notify_from_(std::move(stories_notify_from_))
  , poll_votes_notify_from_(std::move(poll_votes_notify_from_))
  , sound_(std::move(sound_))
  , show_previews_(show_previews_)
{}

const std::int32_t reactionsNotifySettings::ID;

object_ptr<reactionsNotifySettings> reactionsNotifySettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<reactionsNotifySettings> res = make_tl_object<reactionsNotifySettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  if (var0 & 1) { res->messages_notify_from_ = TlFetchObject<ReactionNotificationsFrom>::parse(p); }
  if (var0 & 2) { res->stories_notify_from_ = TlFetchObject<ReactionNotificationsFrom>::parse(p); }
  if (var0 & 4) { res->poll_votes_notify_from_ = TlFetchObject<ReactionNotificationsFrom>::parse(p); }
  res->sound_ = TlFetchObject<NotificationSound>::parse(p);
  res->show_previews_ = TlFetchBool::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void reactionsNotifySettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(messages_notify_from_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(stories_notify_from_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(poll_votes_notify_from_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(sound_, s);
  TlStoreBool::store(show_previews_, s);
}

void reactionsNotifySettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(messages_notify_from_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(stories_notify_from_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(poll_votes_notify_from_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(sound_, s);
  TlStoreBool::store(show_previews_, s);
}

void reactionsNotifySettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reactionsNotifySettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("messages_notify_from", static_cast<const BaseObject *>(messages_notify_from_.get())); }
    if (var0 & 2) { s.store_object_field("stories_notify_from", static_cast<const BaseObject *>(stories_notify_from_.get())); }
    if (var0 & 4) { s.store_object_field("poll_votes_notify_from", static_cast<const BaseObject *>(poll_votes_notify_from_.get())); }
    s.store_object_field("sound", static_cast<const BaseObject *>(sound_.get()));
    s.store_field("show_previews", show_previews_);
    s.store_class_end();
  }
}

recentStory::recentStory()
  : flags_()
  , live_()
  , max_id_()
{}

recentStory::recentStory(int32 flags_, bool live_, int32 max_id_)
  : flags_(flags_)
  , live_(live_)
  , max_id_(max_id_)
{}

const std::int32_t recentStory::ID;

object_ptr<recentStory> recentStory::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<recentStory> res = make_tl_object<recentStory>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->live_ = (var0 & 1) != 0;
  if (var0 & 2) { res->max_id_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void recentStory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (live_ << 0)), s);
  if (var0 & 2) { TlStoreBinary::store(max_id_, s); }
}

void recentStory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (live_ << 0)), s);
  if (var0 & 2) { TlStoreBinary::store(max_id_, s); }
}

void recentStory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "recentStory");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (live_ << 0)));
    if (var0 & 1) { s.store_field("live", true); }
    if (var0 & 2) { s.store_field("max_id", max_id_); }
    s.store_class_end();
  }
}

object_ptr<ReportResult> ReportResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case reportResultChooseOption::ID:
      return reportResultChooseOption::fetch(p);
    case reportResultAddComment::ID:
      return reportResultAddComment::fetch(p);
    case reportResultReported::ID:
      return reportResultReported::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t reportResultChooseOption::ID;

object_ptr<ReportResult> reportResultChooseOption::fetch(TlBufferParser &p) {
  return make_tl_object<reportResultChooseOption>(p);
}

reportResultChooseOption::reportResultChooseOption(TlBufferParser &p)
  : title_(TlFetchString<string>::parse(p))
  , options_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<messageReportOption>, 2030298073>>, 481674261>::parse(p))
{}

void reportResultChooseOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportResultChooseOption");
    s.store_field("title", title_);
    { s.store_vector_begin("options", options_.size()); for (const auto &_value : options_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

reportResultAddComment::reportResultAddComment()
  : flags_()
  , optional_()
  , option_()
{}

const std::int32_t reportResultAddComment::ID;

object_ptr<ReportResult> reportResultAddComment::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<reportResultAddComment> res = make_tl_object<reportResultAddComment>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->optional_ = (var0 & 1) != 0;
  res->option_ = TlFetchBytes<bytes>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void reportResultAddComment::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportResultAddComment");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (optional_ << 0)));
    if (var0 & 1) { s.store_field("optional", true); }
    s.store_bytes_field("option", option_);
    s.store_class_end();
  }
}

const std::int32_t reportResultReported::ID;

object_ptr<ReportResult> reportResultReported::fetch(TlBufferParser &p) {
  return make_tl_object<reportResultReported>();
}

void reportResultReported::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "reportResultReported");
    s.store_class_end();
  }
}

object_ptr<RichText> RichText::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
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
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t textEmpty::ID;

object_ptr<RichText> textEmpty::fetch(TlBufferParser &p) {
  return make_tl_object<textEmpty>();
}

void textEmpty::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
}

void textEmpty::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
}

void textEmpty::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEmpty");
    s.store_class_end();
  }
}

textPlain::textPlain(string const &text_)
  : text_(text_)
{}

const std::int32_t textPlain::ID;

object_ptr<RichText> textPlain::fetch(TlBufferParser &p) {
  return make_tl_object<textPlain>(p);
}

textPlain::textPlain(TlBufferParser &p)
  : text_(TlFetchString<string>::parse(p))
{}

void textPlain::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
}

void textPlain::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreString::store(text_, s);
}

void textPlain::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textPlain");
    s.store_field("text", text_);
    s.store_class_end();
  }
}

textBold::textBold(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textBold::ID;

object_ptr<RichText> textBold::fetch(TlBufferParser &p) {
  return make_tl_object<textBold>(p);
}

textBold::textBold(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textBold::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textBold::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textBold::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textBold");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textItalic::textItalic(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textItalic::ID;

object_ptr<RichText> textItalic::fetch(TlBufferParser &p) {
  return make_tl_object<textItalic>(p);
}

textItalic::textItalic(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textItalic::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textItalic::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textItalic::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textItalic");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textUnderline::textUnderline(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textUnderline::ID;

object_ptr<RichText> textUnderline::fetch(TlBufferParser &p) {
  return make_tl_object<textUnderline>(p);
}

textUnderline::textUnderline(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textUnderline::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textUnderline::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textUnderline::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textUnderline");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textStrike::textStrike(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textStrike::ID;

object_ptr<RichText> textStrike::fetch(TlBufferParser &p) {
  return make_tl_object<textStrike>(p);
}

textStrike::textStrike(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textStrike::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textStrike::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textStrike::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textStrike");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textFixed::textFixed(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textFixed::ID;

object_ptr<RichText> textFixed::fetch(TlBufferParser &p) {
  return make_tl_object<textFixed>(p);
}

textFixed::textFixed(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textFixed::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textFixed::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textFixed::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textFixed");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textUrl::textUrl(object_ptr<RichText> &&text_, string const &url_, int64 webpage_id_)
  : text_(std::move(text_))
  , url_(url_)
  , webpage_id_(webpage_id_)
{}

const std::int32_t textUrl::ID;

object_ptr<RichText> textUrl::fetch(TlBufferParser &p) {
  return make_tl_object<textUrl>(p);
}

textUrl::textUrl(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , url_(TlFetchString<string>::parse(p))
  , webpage_id_(TlFetchLong::parse(p))
{}

void textUrl::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(webpage_id_, s);
}

void textUrl::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(url_, s);
  TlStoreBinary::store(webpage_id_, s);
}

void textUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textUrl");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("url", url_);
    s.store_field("webpage_id", webpage_id_);
    s.store_class_end();
  }
}

textEmail::textEmail(object_ptr<RichText> &&text_, string const &email_)
  : text_(std::move(text_))
  , email_(email_)
{}

const std::int32_t textEmail::ID;

object_ptr<RichText> textEmail::fetch(TlBufferParser &p) {
  return make_tl_object<textEmail>(p);
}

textEmail::textEmail(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , email_(TlFetchString<string>::parse(p))
{}

void textEmail::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(email_, s);
}

void textEmail::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(email_, s);
}

void textEmail::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textEmail");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("email", email_);
    s.store_class_end();
  }
}

textConcat::textConcat(array<object_ptr<RichText>> &&texts_)
  : texts_(std::move(texts_))
{}

const std::int32_t textConcat::ID;

object_ptr<RichText> textConcat::fetch(TlBufferParser &p) {
  return make_tl_object<textConcat>(p);
}

textConcat::textConcat(TlBufferParser &p)
  : texts_(TlFetchBoxed<TlFetchVector<TlFetchObject<RichText>>, 481674261>::parse(p))
{}

void textConcat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(texts_, s);
}

void textConcat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(texts_, s);
}

void textConcat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textConcat");
    { s.store_vector_begin("texts", texts_.size()); for (const auto &_value : texts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

textSubscript::textSubscript(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textSubscript::ID;

object_ptr<RichText> textSubscript::fetch(TlBufferParser &p) {
  return make_tl_object<textSubscript>(p);
}

textSubscript::textSubscript(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textSubscript::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textSubscript::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textSubscript::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textSubscript");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textSuperscript::textSuperscript(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textSuperscript::ID;

object_ptr<RichText> textSuperscript::fetch(TlBufferParser &p) {
  return make_tl_object<textSuperscript>(p);
}

textSuperscript::textSuperscript(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textSuperscript::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textSuperscript::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textSuperscript::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textSuperscript");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textMarked::textMarked(object_ptr<RichText> &&text_)
  : text_(std::move(text_))
{}

const std::int32_t textMarked::ID;

object_ptr<RichText> textMarked::fetch(TlBufferParser &p) {
  return make_tl_object<textMarked>(p);
}

textMarked::textMarked(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
{}

void textMarked::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textMarked::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
}

void textMarked::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textMarked");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_class_end();
  }
}

textPhone::textPhone(object_ptr<RichText> &&text_, string const &phone_)
  : text_(std::move(text_))
  , phone_(phone_)
{}

const std::int32_t textPhone::ID;

object_ptr<RichText> textPhone::fetch(TlBufferParser &p) {
  return make_tl_object<textPhone>(p);
}

textPhone::textPhone(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , phone_(TlFetchString<string>::parse(p))
{}

void textPhone::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(phone_, s);
}

void textPhone::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(phone_, s);
}

void textPhone::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textPhone");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("phone", phone_);
    s.store_class_end();
  }
}

textImage::textImage(int64 document_id_, int32 w_, int32 h_)
  : document_id_(document_id_)
  , w_(w_)
  , h_(h_)
{}

const std::int32_t textImage::ID;

object_ptr<RichText> textImage::fetch(TlBufferParser &p) {
  return make_tl_object<textImage>(p);
}

textImage::textImage(TlBufferParser &p)
  : document_id_(TlFetchLong::parse(p))
  , w_(TlFetchInt::parse(p))
  , h_(TlFetchInt::parse(p))
{}

void textImage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
}

void textImage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(document_id_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
}

void textImage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textImage");
    s.store_field("document_id", document_id_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_class_end();
  }
}

textAnchor::textAnchor(object_ptr<RichText> &&text_, string const &name_)
  : text_(std::move(text_))
  , name_(name_)
{}

const std::int32_t textAnchor::ID;

object_ptr<RichText> textAnchor::fetch(TlBufferParser &p) {
  return make_tl_object<textAnchor>(p);
}

textAnchor::textAnchor(TlBufferParser &p)
  : text_(TlFetchObject<RichText>::parse(p))
  , name_(TlFetchString<string>::parse(p))
{}

void textAnchor::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(name_, s);
}

void textAnchor::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(text_, s);
  TlStoreString::store(name_, s);
}

void textAnchor::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "textAnchor");
    s.store_object_field("text", static_cast<const BaseObject *>(text_.get()));
    s.store_field("name", name_);
    s.store_class_end();
  }
}

secureValue::secureValue()
  : flags_()
  , type_()
  , data_()
  , front_side_()
  , reverse_side_()
  , selfie_()
  , translation_()
  , files_()
  , plain_data_()
  , hash_()
{}

const std::int32_t secureValue::ID;

object_ptr<secureValue> secureValue::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<secureValue> res = make_tl_object<secureValue>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->type_ = TlFetchObject<SecureValueType>::parse(p);
  if (var0 & 1) { res->data_ = TlFetchBoxed<TlFetchObject<secureData>, -1964327229>::parse(p); }
  if (var0 & 2) { res->front_side_ = TlFetchObject<SecureFile>::parse(p); }
  if (var0 & 4) { res->reverse_side_ = TlFetchObject<SecureFile>::parse(p); }
  if (var0 & 8) { res->selfie_ = TlFetchObject<SecureFile>::parse(p); }
  if (var0 & 64) { res->translation_ = TlFetchBoxed<TlFetchVector<TlFetchObject<SecureFile>>, 481674261>::parse(p); }
  if (var0 & 16) { res->files_ = TlFetchBoxed<TlFetchVector<TlFetchObject<SecureFile>>, 481674261>::parse(p); }
  if (var0 & 32) { res->plain_data_ = TlFetchObject<SecurePlainData>::parse(p); }
  res->hash_ = TlFetchBytes<bytes>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void secureValue::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "secureValue");
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
    s.store_bytes_field("hash", hash_);
    s.store_class_end();
  }
}

sponsoredMessage::sponsoredMessage()
  : flags_()
  , recommended_()
  , can_report_()
  , random_id_()
  , url_()
  , title_()
  , message_()
  , entities_()
  , photo_()
  , media_()
  , color_()
  , button_text_()
  , sponsor_info_()
  , additional_info_()
  , min_display_duration_()
  , max_display_duration_()
{}

const std::int32_t sponsoredMessage::ID;

object_ptr<sponsoredMessage> sponsoredMessage::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<sponsoredMessage> res = make_tl_object<sponsoredMessage>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->recommended_ = (var0 & 32) != 0;
  res->can_report_ = (var0 & 4096) != 0;
  res->random_id_ = TlFetchBytes<bytes>::parse(p);
  res->url_ = TlFetchString<string>::parse(p);
  res->title_ = TlFetchString<string>::parse(p);
  res->message_ = TlFetchString<string>::parse(p);
  if (var0 & 2) { res->entities_ = TlFetchBoxed<TlFetchVector<TlFetchObject<MessageEntity>>, 481674261>::parse(p); }
  if (var0 & 64) { res->photo_ = TlFetchObject<Photo>::parse(p); }
  if (var0 & 16384) { res->media_ = TlFetchObject<MessageMedia>::parse(p); }
  if (var0 & 8192) { res->color_ = TlFetchObject<PeerColor>::parse(p); }
  res->button_text_ = TlFetchString<string>::parse(p);
  if (var0 & 128) { res->sponsor_info_ = TlFetchString<string>::parse(p); }
  if (var0 & 256) { res->additional_info_ = TlFetchString<string>::parse(p); }
  if (var0 & 32768) { res->min_display_duration_ = TlFetchInt::parse(p); }
  if (var0 & 32768) { res->max_display_duration_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void sponsoredMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredMessage");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (recommended_ << 5) | (can_report_ << 12)));
    if (var0 & 32) { s.store_field("recommended", true); }
    if (var0 & 4096) { s.store_field("can_report", true); }
    s.store_bytes_field("random_id", random_id_);
    s.store_field("url", url_);
    s.store_field("title", title_);
    s.store_field("message", message_);
    if (var0 & 2) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 64) { s.store_object_field("photo", static_cast<const BaseObject *>(photo_.get())); }
    if (var0 & 16384) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 8192) { s.store_object_field("color", static_cast<const BaseObject *>(color_.get())); }
    s.store_field("button_text", button_text_);
    if (var0 & 128) { s.store_field("sponsor_info", sponsor_info_); }
    if (var0 & 256) { s.store_field("additional_info", additional_info_); }
    if (var0 & 32768) { s.store_field("min_display_duration", min_display_duration_); }
    if (var0 & 32768) { s.store_field("max_display_duration", max_display_duration_); }
    s.store_class_end();
  }
}

sponsoredPeer::sponsoredPeer()
  : flags_()
  , random_id_()
  , peer_()
  , sponsor_info_()
  , additional_info_()
{}

const std::int32_t sponsoredPeer::ID;

object_ptr<sponsoredPeer> sponsoredPeer::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<sponsoredPeer> res = make_tl_object<sponsoredPeer>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->random_id_ = TlFetchBytes<bytes>::parse(p);
  res->peer_ = TlFetchObject<Peer>::parse(p);
  if (var0 & 1) { res->sponsor_info_ = TlFetchString<string>::parse(p); }
  if (var0 & 2) { res->additional_info_ = TlFetchString<string>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void sponsoredPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "sponsoredPeer");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_bytes_field("random_id", random_id_);
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("sponsor_info", sponsor_info_); }
    if (var0 & 2) { s.store_field("additional_info", additional_info_); }
    s.store_class_end();
  }
}

const std::int32_t starGiftUpgradePrice::ID;

object_ptr<starGiftUpgradePrice> starGiftUpgradePrice::fetch(TlBufferParser &p) {
  return make_tl_object<starGiftUpgradePrice>(p);
}

starGiftUpgradePrice::starGiftUpgradePrice(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
  , upgrade_stars_(TlFetchLong::parse(p))
{}

void starGiftUpgradePrice::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starGiftUpgradePrice");
    s.store_field("date", date_);
    s.store_field("upgrade_stars", upgrade_stars_);
    s.store_class_end();
  }
}

starsRevenueStatus::starsRevenueStatus()
  : flags_()
  , withdrawal_enabled_()
  , current_balance_()
  , available_balance_()
  , overall_revenue_()
  , next_withdrawal_at_()
{}

const std::int32_t starsRevenueStatus::ID;

object_ptr<starsRevenueStatus> starsRevenueStatus::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<starsRevenueStatus> res = make_tl_object<starsRevenueStatus>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->withdrawal_enabled_ = (var0 & 1) != 0;
  res->current_balance_ = TlFetchObject<StarsAmount>::parse(p);
  res->available_balance_ = TlFetchObject<StarsAmount>::parse(p);
  res->overall_revenue_ = TlFetchObject<StarsAmount>::parse(p);
  if (var0 & 2) { res->next_withdrawal_at_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void starsRevenueStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "starsRevenueStatus");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (withdrawal_enabled_ << 0)));
    if (var0 & 1) { s.store_field("withdrawal_enabled", true); }
    s.store_object_field("current_balance", static_cast<const BaseObject *>(current_balance_.get()));
    s.store_object_field("available_balance", static_cast<const BaseObject *>(available_balance_.get()));
    s.store_object_field("overall_revenue", static_cast<const BaseObject *>(overall_revenue_.get()));
    if (var0 & 2) { s.store_field("next_withdrawal_at", next_withdrawal_at_); }
    s.store_class_end();
  }
}

themeSettings::themeSettings()
  : flags_()
  , message_colors_animated_()
  , base_theme_()
  , accent_color_()
  , outbox_accent_color_()
  , message_colors_()
  , wallpaper_()
{}

themeSettings::themeSettings(int32 flags_, bool message_colors_animated_, object_ptr<BaseTheme> &&base_theme_, int32 accent_color_, int32 outbox_accent_color_, array<int32> &&message_colors_, object_ptr<WallPaper> &&wallpaper_)
  : flags_(flags_)
  , message_colors_animated_(message_colors_animated_)
  , base_theme_(std::move(base_theme_))
  , accent_color_(accent_color_)
  , outbox_accent_color_(outbox_accent_color_)
  , message_colors_(std::move(message_colors_))
  , wallpaper_(std::move(wallpaper_))
{}

const std::int32_t themeSettings::ID;

object_ptr<themeSettings> themeSettings::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<themeSettings> res = make_tl_object<themeSettings>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->message_colors_animated_ = (var0 & 4) != 0;
  res->base_theme_ = TlFetchObject<BaseTheme>::parse(p);
  res->accent_color_ = TlFetchInt::parse(p);
  if (var0 & 8) { res->outbox_accent_color_ = TlFetchInt::parse(p); }
  if (var0 & 1) { res->message_colors_ = TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p); }
  if (var0 & 2) { res->wallpaper_ = TlFetchObject<WallPaper>::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void themeSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (message_colors_animated_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(base_theme_, s);
  TlStoreBinary::store(accent_color_, s);
  if (var0 & 8) { TlStoreBinary::store(outbox_accent_color_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(message_colors_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s); }
}

void themeSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_ | (message_colors_animated_ << 2)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(base_theme_, s);
  TlStoreBinary::store(accent_color_, s);
  if (var0 & 8) { TlStoreBinary::store(outbox_accent_color_, s); }
  if (var0 & 1) { TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(message_colors_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(wallpaper_, s); }
}

void themeSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "themeSettings");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (message_colors_animated_ << 2)));
    if (var0 & 4) { s.store_field("message_colors_animated", true); }
    s.store_object_field("base_theme", static_cast<const BaseObject *>(base_theme_.get()));
    s.store_field("accent_color", accent_color_);
    if (var0 & 8) { s.store_field("outbox_accent_color", outbox_accent_color_); }
    if (var0 & 1) { { s.store_vector_begin("message_colors", message_colors_.size()); for (const auto &_value : message_colors_) { s.store_field("", _value); } s.store_class_end(); } }
    if (var0 & 2) { s.store_object_field("wallpaper", static_cast<const BaseObject *>(wallpaper_.get())); }
    s.store_class_end();
  }
}

object_ptr<VideoSize> VideoSize::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case videoSize::ID:
      return videoSize::fetch(p);
    case videoSizeEmojiMarkup::ID:
      return videoSizeEmojiMarkup::fetch(p);
    case videoSizeStickerMarkup::ID:
      return videoSizeStickerMarkup::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

videoSize::videoSize()
  : flags_()
  , type_()
  , w_()
  , h_()
  , size_()
  , video_start_ts_()
{}

videoSize::videoSize(int32 flags_, string const &type_, int32 w_, int32 h_, int32 size_, double video_start_ts_)
  : flags_(flags_)
  , type_(type_)
  , w_(w_)
  , h_(h_)
  , size_(size_)
  , video_start_ts_(video_start_ts_)
{}

const std::int32_t videoSize::ID;

object_ptr<VideoSize> videoSize::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<videoSize> res = make_tl_object<videoSize>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->type_ = TlFetchString<string>::parse(p);
  res->w_ = TlFetchInt::parse(p);
  res->h_ = TlFetchInt::parse(p);
  res->size_ = TlFetchInt::parse(p);
  if (var0 & 1) { res->video_start_ts_ = TlFetchDouble::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void videoSize::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(size_, s);
  if (var0 & 1) { TlStoreBinary::store(video_start_ts_, s); }
}

void videoSize::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  int32 var0;
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreString::store(type_, s);
  TlStoreBinary::store(w_, s);
  TlStoreBinary::store(h_, s);
  TlStoreBinary::store(size_, s);
  if (var0 & 1) { TlStoreBinary::store(video_start_ts_, s); }
}

void videoSize::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoSize");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("type", type_);
    s.store_field("w", w_);
    s.store_field("h", h_);
    s.store_field("size", size_);
    if (var0 & 1) { s.store_field("video_start_ts", video_start_ts_); }
    s.store_class_end();
  }
}

videoSizeEmojiMarkup::videoSizeEmojiMarkup(int64 emoji_id_, array<int32> &&background_colors_)
  : emoji_id_(emoji_id_)
  , background_colors_(std::move(background_colors_))
{}

const std::int32_t videoSizeEmojiMarkup::ID;

object_ptr<VideoSize> videoSizeEmojiMarkup::fetch(TlBufferParser &p) {
  return make_tl_object<videoSizeEmojiMarkup>(p);
}

videoSizeEmojiMarkup::videoSizeEmojiMarkup(TlBufferParser &p)
  : emoji_id_(TlFetchLong::parse(p))
  , background_colors_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void videoSizeEmojiMarkup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(emoji_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(background_colors_, s);
}

void videoSizeEmojiMarkup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBinary::store(emoji_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(background_colors_, s);
}

void videoSizeEmojiMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoSizeEmojiMarkup");
    s.store_field("emoji_id", emoji_id_);
    { s.store_vector_begin("background_colors", background_colors_.size()); for (const auto &_value : background_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

videoSizeStickerMarkup::videoSizeStickerMarkup(object_ptr<InputStickerSet> &&stickerset_, int64 sticker_id_, array<int32> &&background_colors_)
  : stickerset_(std::move(stickerset_))
  , sticker_id_(sticker_id_)
  , background_colors_(std::move(background_colors_))
{}

const std::int32_t videoSizeStickerMarkup::ID;

object_ptr<VideoSize> videoSizeStickerMarkup::fetch(TlBufferParser &p) {
  return make_tl_object<videoSizeStickerMarkup>(p);
}

videoSizeStickerMarkup::videoSizeStickerMarkup(TlBufferParser &p)
  : stickerset_(TlFetchObject<InputStickerSet>::parse(p))
  , sticker_id_(TlFetchLong::parse(p))
  , background_colors_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void videoSizeStickerMarkup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(sticker_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(background_colors_, s);
}

void videoSizeStickerMarkup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stickerset_, s);
  TlStoreBinary::store(sticker_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(background_colors_, s);
}

void videoSizeStickerMarkup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "videoSizeStickerMarkup");
    s.store_object_field("stickerset", static_cast<const BaseObject *>(stickerset_.get()));
    s.store_field("sticker_id", sticker_id_);
    { s.store_vector_begin("background_colors", background_colors_.size()); for (const auto &_value : background_colors_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t webAuthorization::ID;

object_ptr<webAuthorization> webAuthorization::fetch(TlBufferParser &p) {
  return make_tl_object<webAuthorization>(p);
}

webAuthorization::webAuthorization(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , bot_id_(TlFetchLong::parse(p))
  , domain_(TlFetchString<string>::parse(p))
  , browser_(TlFetchString<string>::parse(p))
  , platform_(TlFetchString<string>::parse(p))
  , date_created_(TlFetchInt::parse(p))
  , date_active_(TlFetchInt::parse(p))
  , ip_(TlFetchString<string>::parse(p))
  , region_(TlFetchString<string>::parse(p))
{}

void webAuthorization::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "webAuthorization");
    s.store_field("hash", hash_);
    s.store_field("bot_id", bot_id_);
    s.store_field("domain", domain_);
    s.store_field("browser", browser_);
    s.store_field("platform", platform_);
    s.store_field("date_created", date_created_);
    s.store_field("date_active", date_active_);
    s.store_field("ip", ip_);
    s.store_field("region", region_);
    s.store_class_end();
  }
}

const std::int32_t account_takeout::ID;

object_ptr<account_takeout> account_takeout::fetch(TlBufferParser &p) {
  return make_tl_object<account_takeout>(p);
}

account_takeout::account_takeout(TlBufferParser &p)
  : id_(TlFetchLong::parse(p))
{}

void account_takeout::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.takeout");
    s.store_field("id", id_);
    s.store_class_end();
  }
}

object_ptr<account_WallPapers> account_WallPapers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case account_wallPapersNotModified::ID:
      return account_wallPapersNotModified::fetch(p);
    case account_wallPapers::ID:
      return account_wallPapers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t account_wallPapersNotModified::ID;

object_ptr<account_WallPapers> account_wallPapersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<account_wallPapersNotModified>();
}

void account_wallPapersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.wallPapersNotModified");
    s.store_class_end();
  }
}

const std::int32_t account_wallPapers::ID;

object_ptr<account_WallPapers> account_wallPapers::fetch(TlBufferParser &p) {
  return make_tl_object<account_wallPapers>(p);
}

account_wallPapers::account_wallPapers(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , wallpapers_(TlFetchBoxed<TlFetchVector<TlFetchObject<WallPaper>>, 481674261>::parse(p))
{}

void account_wallPapers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.wallPapers");
    s.store_field("hash", hash_);
    { s.store_vector_begin("wallpapers", wallpapers_.size()); for (const auto &_value : wallpapers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t auth_passwordRecovery::ID;

object_ptr<auth_passwordRecovery> auth_passwordRecovery::fetch(TlBufferParser &p) {
  return make_tl_object<auth_passwordRecovery>(p);
}

auth_passwordRecovery::auth_passwordRecovery(TlBufferParser &p)
  : email_pattern_(TlFetchString<string>::parse(p))
{}

void auth_passwordRecovery::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.passwordRecovery");
    s.store_field("email_pattern", email_pattern_);
    s.store_class_end();
  }
}

const std::int32_t channels_channelParticipant::ID;

object_ptr<channels_channelParticipant> channels_channelParticipant::fetch(TlBufferParser &p) {
  return make_tl_object<channels_channelParticipant>(p);
}

channels_channelParticipant::channels_channelParticipant(TlBufferParser &p)
  : participant_(TlFetchObject<ChannelParticipant>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void channels_channelParticipant::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.channelParticipant");
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<chatlists_ChatlistInvite> chatlists_ChatlistInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case chatlists_chatlistInviteAlready::ID:
      return chatlists_chatlistInviteAlready::fetch(p);
    case chatlists_chatlistInvite::ID:
      return chatlists_chatlistInvite::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t chatlists_chatlistInviteAlready::ID;

object_ptr<chatlists_ChatlistInvite> chatlists_chatlistInviteAlready::fetch(TlBufferParser &p) {
  return make_tl_object<chatlists_chatlistInviteAlready>(p);
}

chatlists_chatlistInviteAlready::chatlists_chatlistInviteAlready(TlBufferParser &p)
  : filter_id_(TlFetchInt::parse(p))
  , missing_peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
  , already_peers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void chatlists_chatlistInviteAlready::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.chatlistInviteAlready");
    s.store_field("filter_id", filter_id_);
    { s.store_vector_begin("missing_peers", missing_peers_.size()); for (const auto &_value : missing_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("already_peers", already_peers_.size()); for (const auto &_value : already_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

chatlists_chatlistInvite::chatlists_chatlistInvite()
  : flags_()
  , title_noanimate_()
  , title_()
  , emoticon_()
  , peers_()
  , chats_()
  , users_()
{}

const std::int32_t chatlists_chatlistInvite::ID;

object_ptr<chatlists_ChatlistInvite> chatlists_chatlistInvite::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<chatlists_chatlistInvite> res = make_tl_object<chatlists_chatlistInvite>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->title_noanimate_ = (var0 & 2) != 0;
  res->title_ = TlFetchBoxed<TlFetchObject<textWithEntities>, 1964978502>::parse(p);
  if (var0 & 1) { res->emoticon_ = TlFetchString<string>::parse(p); }
  res->peers_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p);
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return std::move(res);
#undef FAIL
}

void chatlists_chatlistInvite::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.chatlistInvite");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (title_noanimate_ << 1)));
    if (var0 & 2) { s.store_field("title_noanimate", true); }
    s.store_object_field("title", static_cast<const BaseObject *>(title_.get()));
    if (var0 & 1) { s.store_field("emoticon", emoticon_); }
    { s.store_vector_begin("peers", peers_.size()); for (const auto &_value : peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t contacts_found::ID;

object_ptr<contacts_found> contacts_found::fetch(TlBufferParser &p) {
  return make_tl_object<contacts_found>(p);
}

contacts_found::contacts_found(TlBufferParser &p)
  : my_results_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
  , results_(TlFetchBoxed<TlFetchVector<TlFetchObject<Peer>>, 481674261>::parse(p))
  , chats_(TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void contacts_found::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.found");
    { s.store_vector_begin("my_results", my_results_.size()); for (const auto &_value : my_results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("results", results_.size()); for (const auto &_value : results_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t help_configSimple::ID;

object_ptr<help_configSimple> help_configSimple::fetch(TlBufferParser &p) {
  return make_tl_object<help_configSimple>(p);
}

help_configSimple::help_configSimple(TlBufferParser &p)
  : date_(TlFetchInt::parse(p))
  , expires_(TlFetchInt::parse(p))
  , rules_(TlFetchVector<TlFetchBoxed<TlFetchObject<accessPointRule>, 1182381663>>::parse(p))
{}

void help_configSimple::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.configSimple");
    s.store_field("date", date_);
    s.store_field("expires", expires_);
    { s.store_vector_begin("rules", rules_.size()); for (const auto &_value : rules_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

help_peerColorOption::help_peerColorOption()
  : flags_()
  , hidden_()
  , color_id_()
  , colors_()
  , dark_colors_()
  , channel_min_level_()
  , group_min_level_()
{}

const std::int32_t help_peerColorOption::ID;

object_ptr<help_peerColorOption> help_peerColorOption::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<help_peerColorOption> res = make_tl_object<help_peerColorOption>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->hidden_ = (var0 & 1) != 0;
  res->color_id_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->colors_ = TlFetchObject<help_PeerColorSet>::parse(p); }
  if (var0 & 4) { res->dark_colors_ = TlFetchObject<help_PeerColorSet>::parse(p); }
  if (var0 & 8) { res->channel_min_level_ = TlFetchInt::parse(p); }
  if (var0 & 16) { res->group_min_level_ = TlFetchInt::parse(p); }
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void help_peerColorOption::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.peerColorOption");
  int32 var0;
    s.store_field("flags", (var0 = flags_ | (hidden_ << 0)));
    if (var0 & 1) { s.store_field("hidden", true); }
    s.store_field("color_id", color_id_);
    if (var0 & 2) { s.store_object_field("colors", static_cast<const BaseObject *>(colors_.get())); }
    if (var0 & 4) { s.store_object_field("dark_colors", static_cast<const BaseObject *>(dark_colors_.get())); }
    if (var0 & 8) { s.store_field("channel_min_level", channel_min_level_); }
    if (var0 & 16) { s.store_field("group_min_level", group_min_level_); }
    s.store_class_end();
  }
}

const std::int32_t messages_affectedHistory::ID;

object_ptr<messages_affectedHistory> messages_affectedHistory::fetch(TlBufferParser &p) {
  return make_tl_object<messages_affectedHistory>(p);
}

messages_affectedHistory::messages_affectedHistory(TlBufferParser &p)
  : pts_(TlFetchInt::parse(p))
  , pts_count_(TlFetchInt::parse(p))
  , offset_(TlFetchInt::parse(p))
{}

void messages_affectedHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.affectedHistory");
    s.store_field("pts", pts_);
    s.store_field("pts_count", pts_count_);
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

const std::int32_t messages_botPreparedInlineMessage::ID;

object_ptr<messages_botPreparedInlineMessage> messages_botPreparedInlineMessage::fetch(TlBufferParser &p) {
  return make_tl_object<messages_botPreparedInlineMessage>(p);
}

messages_botPreparedInlineMessage::messages_botPreparedInlineMessage(TlBufferParser &p)
  : id_(TlFetchString<string>::parse(p))
  , expire_date_(TlFetchInt::parse(p))
{}

void messages_botPreparedInlineMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.botPreparedInlineMessage");
    s.store_field("id", id_);
    s.store_field("expire_date", expire_date_);
    s.store_class_end();
  }
}

const std::int32_t messages_chatAdminsWithInvites::ID;

object_ptr<messages_chatAdminsWithInvites> messages_chatAdminsWithInvites::fetch(TlBufferParser &p) {
  return make_tl_object<messages_chatAdminsWithInvites>(p);
}

messages_chatAdminsWithInvites::messages_chatAdminsWithInvites(TlBufferParser &p)
  : admins_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<chatAdminWithInvites>, -219353309>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void messages_chatAdminsWithInvites::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.chatAdminsWithInvites");
    { s.store_vector_begin("admins", admins_.size()); for (const auto &_value : admins_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_myStickers::ID;

object_ptr<messages_myStickers> messages_myStickers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_myStickers>(p);
}

messages_myStickers::messages_myStickers(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , sets_(TlFetchBoxed<TlFetchVector<TlFetchObject<StickerSetCovered>>, 481674261>::parse(p))
{}

void messages_myStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.myStickers");
    s.store_field("count", count_);
    { s.store_vector_begin("sets", sets_.size()); for (const auto &_value : sets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<messages_RecentStickers> messages_RecentStickers::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case messages_recentStickersNotModified::ID:
      return messages_recentStickersNotModified::fetch(p);
    case messages_recentStickers::ID:
      return messages_recentStickers::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t messages_recentStickersNotModified::ID;

object_ptr<messages_RecentStickers> messages_recentStickersNotModified::fetch(TlBufferParser &p) {
  return make_tl_object<messages_recentStickersNotModified>();
}

void messages_recentStickersNotModified::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.recentStickersNotModified");
    s.store_class_end();
  }
}

const std::int32_t messages_recentStickers::ID;

object_ptr<messages_RecentStickers> messages_recentStickers::fetch(TlBufferParser &p) {
  return make_tl_object<messages_recentStickers>(p);
}

messages_recentStickers::messages_recentStickers(TlBufferParser &p)
  : hash_(TlFetchLong::parse(p))
  , packs_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<stickerPack>, 313694676>>, 481674261>::parse(p))
  , stickers_(TlFetchBoxed<TlFetchVector<TlFetchObject<Document>>, 481674261>::parse(p))
  , dates_(TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p))
{}

void messages_recentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.recentStickers");
    s.store_field("hash", hash_);
    { s.store_vector_begin("packs", packs_.size()); for (const auto &_value : packs_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("stickers", stickers_.size()); for (const auto &_value : stickers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("dates", dates_.size()); for (const auto &_value : dates_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t messages_searchResultsPositions::ID;

object_ptr<messages_searchResultsPositions> messages_searchResultsPositions::fetch(TlBufferParser &p) {
  return make_tl_object<messages_searchResultsPositions>(p);
}

messages_searchResultsPositions::messages_searchResultsPositions(TlBufferParser &p)
  : count_(TlFetchInt::parse(p))
  , positions_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<searchResultPosition>, 2137295719>>, 481674261>::parse(p))
{}

void messages_searchResultsPositions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.searchResultsPositions");
    s.store_field("count", count_);
    { s.store_vector_begin("positions", positions_.size()); for (const auto &_value : positions_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

object_ptr<payments_PaymentResult> payments_PaymentResult::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  int constructor = p.fetch_int();
  switch (constructor) {
    case payments_paymentResult::ID:
      return payments_paymentResult::fetch(p);
    case payments_paymentVerificationNeeded::ID:
      return payments_paymentVerificationNeeded::fetch(p);
    default:
      FAIL(PSTRING() << "Unknown constructor found " << format::as_hex(constructor));
  }
#undef FAIL
}

const std::int32_t payments_paymentResult::ID;

object_ptr<payments_PaymentResult> payments_paymentResult::fetch(TlBufferParser &p) {
  return make_tl_object<payments_paymentResult>(p);
}

payments_paymentResult::payments_paymentResult(TlBufferParser &p)
  : updates_(TlFetchObject<Updates>::parse(p))
{}

void payments_paymentResult::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentResult");
    s.store_object_field("updates", static_cast<const BaseObject *>(updates_.get()));
    s.store_class_end();
  }
}

const std::int32_t payments_paymentVerificationNeeded::ID;

object_ptr<payments_PaymentResult> payments_paymentVerificationNeeded::fetch(TlBufferParser &p) {
  return make_tl_object<payments_paymentVerificationNeeded>(p);
}

payments_paymentVerificationNeeded::payments_paymentVerificationNeeded(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void payments_paymentVerificationNeeded::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.paymentVerificationNeeded");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

payments_savedStarGifts::payments_savedStarGifts()
  : flags_()
  , count_()
  , chat_notifications_enabled_()
  , gifts_()
  , next_offset_()
  , chats_()
  , users_()
{}

const std::int32_t payments_savedStarGifts::ID;

object_ptr<payments_savedStarGifts> payments_savedStarGifts::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<payments_savedStarGifts> res = make_tl_object<payments_savedStarGifts>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  if (var0 & 2) { res->chat_notifications_enabled_ = TlFetchBool::parse(p); }
  res->gifts_ = TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<savedStarGift>, 1105150972>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void payments_savedStarGifts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.savedStarGifts");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("count", count_);
    if (var0 & 2) { s.store_field("chat_notifications_enabled", chat_notifications_enabled_); }
    { s.store_vector_begin("gifts", gifts_.size()); for (const auto &_value : gifts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t payments_starsRevenueWithdrawalUrl::ID;

object_ptr<payments_starsRevenueWithdrawalUrl> payments_starsRevenueWithdrawalUrl::fetch(TlBufferParser &p) {
  return make_tl_object<payments_starsRevenueWithdrawalUrl>(p);
}

payments_starsRevenueWithdrawalUrl::payments_starsRevenueWithdrawalUrl(TlBufferParser &p)
  : url_(TlFetchString<string>::parse(p))
{}

void payments_starsRevenueWithdrawalUrl::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.starsRevenueWithdrawalUrl");
    s.store_field("url", url_);
    s.store_class_end();
  }
}

const std::int32_t stats_megagroupStats::ID;

object_ptr<stats_megagroupStats> stats_megagroupStats::fetch(TlBufferParser &p) {
  return make_tl_object<stats_megagroupStats>(p);
}

stats_megagroupStats::stats_megagroupStats(TlBufferParser &p)
  : period_(TlFetchBoxed<TlFetchObject<statsDateRangeDays>, -1237848657>::parse(p))
  , members_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , messages_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , viewers_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , posters_(TlFetchBoxed<TlFetchObject<statsAbsValueAndPrev>, -884757282>::parse(p))
  , growth_graph_(TlFetchObject<StatsGraph>::parse(p))
  , members_graph_(TlFetchObject<StatsGraph>::parse(p))
  , new_members_by_source_graph_(TlFetchObject<StatsGraph>::parse(p))
  , languages_graph_(TlFetchObject<StatsGraph>::parse(p))
  , messages_graph_(TlFetchObject<StatsGraph>::parse(p))
  , actions_graph_(TlFetchObject<StatsGraph>::parse(p))
  , top_hours_graph_(TlFetchObject<StatsGraph>::parse(p))
  , weekdays_graph_(TlFetchObject<StatsGraph>::parse(p))
  , top_posters_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<statsGroupTopPoster>, -1660637285>>, 481674261>::parse(p))
  , top_admins_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<statsGroupTopAdmin>, -682079097>>, 481674261>::parse(p))
  , top_inviters_(TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<statsGroupTopInviter>, 1398765469>>, 481674261>::parse(p))
  , users_(TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p))
{}

void stats_megagroupStats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.megagroupStats");
    s.store_object_field("period", static_cast<const BaseObject *>(period_.get()));
    s.store_object_field("members", static_cast<const BaseObject *>(members_.get()));
    s.store_object_field("messages", static_cast<const BaseObject *>(messages_.get()));
    s.store_object_field("viewers", static_cast<const BaseObject *>(viewers_.get()));
    s.store_object_field("posters", static_cast<const BaseObject *>(posters_.get()));
    s.store_object_field("growth_graph", static_cast<const BaseObject *>(growth_graph_.get()));
    s.store_object_field("members_graph", static_cast<const BaseObject *>(members_graph_.get()));
    s.store_object_field("new_members_by_source_graph", static_cast<const BaseObject *>(new_members_by_source_graph_.get()));
    s.store_object_field("languages_graph", static_cast<const BaseObject *>(languages_graph_.get()));
    s.store_object_field("messages_graph", static_cast<const BaseObject *>(messages_graph_.get()));
    s.store_object_field("actions_graph", static_cast<const BaseObject *>(actions_graph_.get()));
    s.store_object_field("top_hours_graph", static_cast<const BaseObject *>(top_hours_graph_.get()));
    s.store_object_field("weekdays_graph", static_cast<const BaseObject *>(weekdays_graph_.get()));
    { s.store_vector_begin("top_posters", top_posters_.size()); for (const auto &_value : top_posters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_admins", top_admins_.size()); for (const auto &_value : top_admins_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("top_inviters", top_inviters_.size()); for (const auto &_value : top_inviters_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stats_publicForwards::stats_publicForwards()
  : flags_()
  , count_()
  , forwards_()
  , next_offset_()
  , chats_()
  , users_()
{}

const std::int32_t stats_publicForwards::ID;

object_ptr<stats_publicForwards> stats_publicForwards::fetch(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return nullptr;
  object_ptr<stats_publicForwards> res = make_tl_object<stats_publicForwards>();
  int32 var0;
  if ((var0 = res->flags_ = TlFetchInt::parse(p)) < 0) { FAIL("Variable of type # can't be negative"); }
  res->count_ = TlFetchInt::parse(p);
  res->forwards_ = TlFetchBoxed<TlFetchVector<TlFetchObject<PublicForward>>, 481674261>::parse(p);
  if (var0 & 1) { res->next_offset_ = TlFetchString<string>::parse(p); }
  res->chats_ = TlFetchBoxed<TlFetchVector<TlFetchObject<Chat>>, 481674261>::parse(p);
  res->users_ = TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
  if (p.get_error()) { FAIL(""); }
  return res;
#undef FAIL
}

void stats_publicForwards::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stats.publicForwards");
  int32 var0;
    s.store_field("flags", (var0 = flags_));
    s.store_field("count", count_);
    { s.store_vector_begin("forwards", forwards_.size()); for (const auto &_value : forwards_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    if (var0 & 1) { s.store_field("next_offset", next_offset_); }
    { s.store_vector_begin("chats", chats_.size()); for (const auto &_value : chats_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    { s.store_vector_begin("users", users_.size()); for (const auto &_value : users_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

const std::int32_t stickers_suggestedShortName::ID;

object_ptr<stickers_suggestedShortName> stickers_suggestedShortName::fetch(TlBufferParser &p) {
  return make_tl_object<stickers_suggestedShortName>(p);
}

stickers_suggestedShortName::stickers_suggestedShortName(TlBufferParser &p)
  : short_name_(TlFetchString<string>::parse(p))
{}

void stickers_suggestedShortName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.suggestedShortName");
    s.store_field("short_name", short_name_);
    s.store_class_end();
  }
}

account_getCollectibleEmojiStatuses::account_getCollectibleEmojiStatuses(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getCollectibleEmojiStatuses::ID;

void account_getCollectibleEmojiStatuses::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(779830595);
  TlStoreBinary::store(hash_, s);
}

void account_getCollectibleEmojiStatuses::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(779830595);
  TlStoreBinary::store(hash_, s);
}

void account_getCollectibleEmojiStatuses::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getCollectibleEmojiStatuses");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getCollectibleEmojiStatuses::ReturnType account_getCollectibleEmojiStatuses::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<account_EmojiStatuses>::parse(p);
#undef FAIL
}

account_getDefaultGroupPhotoEmojis::account_getDefaultGroupPhotoEmojis(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t account_getDefaultGroupPhotoEmojis::ID;

void account_getDefaultGroupPhotoEmojis::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1856479058);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultGroupPhotoEmojis::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1856479058);
  TlStoreBinary::store(hash_, s);
}

void account_getDefaultGroupPhotoEmojis::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.getDefaultGroupPhotoEmojis");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

account_getDefaultGroupPhotoEmojis::ReturnType account_getDefaultGroupPhotoEmojis::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<EmojiList>::parse(p);
#undef FAIL
}

const std::int32_t account_initPasskeyRegistration::ID;

void account_initPasskeyRegistration::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1117079528);
}

void account_initPasskeyRegistration::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1117079528);
}

void account_initPasskeyRegistration::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.initPasskeyRegistration");
    s.store_class_end();
  }
}

account_initPasskeyRegistration::ReturnType account_initPasskeyRegistration::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<account_passkeyRegistrationOptions>, -513057567>::parse(p);
#undef FAIL
}

account_reorderUsernames::account_reorderUsernames(array<string> &&order_)
  : order_(std::move(order_))
{}

const std::int32_t account_reorderUsernames::ID;

void account_reorderUsernames::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-279966037);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(order_, s);
}

void account_reorderUsernames::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-279966037);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(order_, s);
}

void account_reorderUsernames::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.reorderUsernames");
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

account_reorderUsernames::ReturnType account_reorderUsernames::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_reportProfilePhoto::account_reportProfilePhoto(object_ptr<InputPeer> &&peer_, object_ptr<InputPhoto> &&photo_id_, object_ptr<ReportReason> &&reason_, string const &message_)
  : peer_(std::move(peer_))
  , photo_id_(std::move(photo_id_))
  , reason_(std::move(reason_))
  , message_(message_)
{}

const std::int32_t account_reportProfilePhoto::ID;

void account_reportProfilePhoto::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-91437323);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reason_, s);
  TlStoreString::store(message_, s);
}

void account_reportProfilePhoto::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-91437323);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(photo_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(reason_, s);
  TlStoreString::store(message_, s);
}

void account_reportProfilePhoto::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.reportProfilePhoto");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("photo_id", static_cast<const BaseObject *>(photo_id_.get()));
    s.store_object_field("reason", static_cast<const BaseObject *>(reason_.get()));
    s.store_field("message", message_);
    s.store_class_end();
  }
}

account_reportProfilePhoto::ReturnType account_reportProfilePhoto::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

const std::int32_t account_resetWebAuthorizations::ID;

void account_resetWebAuthorizations::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1747789204);
}

void account_resetWebAuthorizations::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1747789204);
}

void account_resetWebAuthorizations::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.resetWebAuthorizations");
    s.store_class_end();
  }
}

account_resetWebAuthorizations::ReturnType account_resetWebAuthorizations::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

account_updateEmojiStatus::account_updateEmojiStatus(object_ptr<EmojiStatus> &&emoji_status_)
  : emoji_status_(std::move(emoji_status_))
{}

const std::int32_t account_updateEmojiStatus::ID;

void account_updateEmojiStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-70001045);
  TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s);
}

void account_updateEmojiStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-70001045);
  TlStoreBoxedUnknown<TlStoreObject>::store(emoji_status_, s);
}

void account_updateEmojiStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "account.updateEmojiStatus");
    s.store_object_field("emoji_status", static_cast<const BaseObject *>(emoji_status_.get()));
    s.store_class_end();
  }
}

account_updateEmojiStatus::ReturnType account_updateEmojiStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

auth_exportLoginToken::auth_exportLoginToken(int32 api_id_, string const &api_hash_, array<int64> &&except_ids_)
  : api_id_(api_id_)
  , api_hash_(api_hash_)
  , except_ids_(std::move(except_ids_))
{}

const std::int32_t auth_exportLoginToken::ID;

void auth_exportLoginToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1210022402);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(except_ids_, s);
}

void auth_exportLoginToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1210022402);
  TlStoreBinary::store(api_id_, s);
  TlStoreString::store(api_hash_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(except_ids_, s);
}

void auth_exportLoginToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.exportLoginToken");
    s.store_field("api_id", api_id_);
    s.store_field("api_hash", api_hash_);
    { s.store_vector_begin("except_ids", except_ids_.size()); for (const auto &_value : except_ids_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

auth_exportLoginToken::ReturnType auth_exportLoginToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_LoginToken>::parse(p);
#undef FAIL
}

auth_importLoginToken::auth_importLoginToken(bytes &&token_)
  : token_(std::move(token_))
{}

const std::int32_t auth_importLoginToken::ID;

void auth_importLoginToken::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1783866140);
  TlStoreString::store(token_, s);
}

void auth_importLoginToken::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1783866140);
  TlStoreString::store(token_, s);
}

void auth_importLoginToken::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "auth.importLoginToken");
    s.store_bytes_field("token", token_);
    s.store_class_end();
  }
}

auth_importLoginToken::ReturnType auth_importLoginToken::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<auth_LoginToken>::parse(p);
#undef FAIL
}

bots_deletePreviewMedia::bots_deletePreviewMedia(object_ptr<InputUser> &&bot_, string const &lang_code_, array<object_ptr<InputMedia>> &&media_)
  : bot_(std::move(bot_))
  , lang_code_(lang_code_)
  , media_(std::move(media_))
{}

const std::int32_t bots_deletePreviewMedia::ID;

void bots_deletePreviewMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(755054003);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_, s);
}

void bots_deletePreviewMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(755054003);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(media_, s);
}

void bots_deletePreviewMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.deletePreviewMedia");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("lang_code", lang_code_);
    { s.store_vector_begin("media", media_.size()); for (const auto &_value : media_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

bots_deletePreviewMedia::ReturnType bots_deletePreviewMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

bots_editPreviewMedia::bots_editPreviewMedia(object_ptr<InputUser> &&bot_, string const &lang_code_, object_ptr<InputMedia> &&media_, object_ptr<InputMedia> &&new_media_)
  : bot_(std::move(bot_))
  , lang_code_(lang_code_)
  , media_(std::move(media_))
  , new_media_(std::move(new_media_))
{}

const std::int32_t bots_editPreviewMedia::ID;

void bots_editPreviewMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2061148049);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(new_media_, s);
}

void bots_editPreviewMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2061148049);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(new_media_, s);
}

void bots_editPreviewMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.editPreviewMedia");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("lang_code", lang_code_);
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_object_field("new_media", static_cast<const BaseObject *>(new_media_.get()));
    s.store_class_end();
  }
}

bots_editPreviewMedia::ReturnType bots_editPreviewMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<botPreviewMedia>, 602479523>::parse(p);
#undef FAIL
}

bots_getBotInfo::bots_getBotInfo(int32 flags_, object_ptr<InputUser> &&bot_, string const &lang_code_)
  : flags_(flags_)
  , bot_(std::move(bot_))
  , lang_code_(lang_code_)
{}

const std::int32_t bots_getBotInfo::ID;

void bots_getBotInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-589753091);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreString::store(lang_code_, s);
}

void bots_getBotInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-589753091);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreString::store(lang_code_, s);
}

void bots_getBotInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getBotInfo");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get())); }
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

bots_getBotInfo::ReturnType bots_getBotInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<bots_botInfo>, -391678544>::parse(p);
#undef FAIL
}

bots_getPreviewInfo::bots_getPreviewInfo(object_ptr<InputUser> &&bot_, string const &lang_code_)
  : bot_(std::move(bot_))
  , lang_code_(lang_code_)
{}

const std::int32_t bots_getPreviewInfo::ID;

void bots_getPreviewInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1111143341);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
}

void bots_getPreviewInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1111143341);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(lang_code_, s);
}

void bots_getPreviewInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getPreviewInfo");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("lang_code", lang_code_);
    s.store_class_end();
  }
}

bots_getPreviewInfo::ReturnType bots_getPreviewInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<bots_previewInfo>, 212278628>::parse(p);
#undef FAIL
}

bots_getRequestedWebViewButton::bots_getRequestedWebViewButton(object_ptr<InputUser> &&bot_, string const &webapp_req_id_)
  : bot_(std::move(bot_))
  , webapp_req_id_(webapp_req_id_)
{}

const std::int32_t bots_getRequestedWebViewButton::ID;

void bots_getRequestedWebViewButton::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1088047117);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(webapp_req_id_, s);
}

void bots_getRequestedWebViewButton::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1088047117);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreString::store(webapp_req_id_, s);
}

void bots_getRequestedWebViewButton::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.getRequestedWebViewButton");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("webapp_req_id", webapp_req_id_);
    s.store_class_end();
  }
}

bots_getRequestedWebViewButton::ReturnType bots_getRequestedWebViewButton::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<KeyboardButton>::parse(p);
#undef FAIL
}

bots_sendCustomRequest::bots_sendCustomRequest(string const &custom_method_, object_ptr<dataJSON> &&params_)
  : custom_method_(custom_method_)
  , params_(std::move(params_))
{}

const std::int32_t bots_sendCustomRequest::ID;

void bots_sendCustomRequest::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1440257555);
  TlStoreString::store(custom_method_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void bots_sendCustomRequest::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1440257555);
  TlStoreString::store(custom_method_, s);
  TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s);
}

void bots_sendCustomRequest::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.sendCustomRequest");
    s.store_field("custom_method", custom_method_);
    s.store_object_field("params", static_cast<const BaseObject *>(params_.get()));
    s.store_class_end();
  }
}

bots_sendCustomRequest::ReturnType bots_sendCustomRequest::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<dataJSON>, 2104790276>::parse(p);
#undef FAIL
}

bots_setBotInfo::bots_setBotInfo(int32 flags_, object_ptr<InputUser> &&bot_, string const &lang_code_, string const &name_, string const &about_, string const &description_)
  : flags_(flags_)
  , bot_(std::move(bot_))
  , lang_code_(lang_code_)
  , name_(name_)
  , about_(about_)
  , description_(description_)
{}

const std::int32_t bots_setBotInfo::ID;

void bots_setBotInfo::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(282013987);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreString::store(lang_code_, s);
  if (var0 & 8) { TlStoreString::store(name_, s); }
  if (var0 & 1) { TlStoreString::store(about_, s); }
  if (var0 & 2) { TlStoreString::store(description_, s); }
}

void bots_setBotInfo::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(282013987);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s); }
  TlStoreString::store(lang_code_, s);
  if (var0 & 8) { TlStoreString::store(name_, s); }
  if (var0 & 1) { TlStoreString::store(about_, s); }
  if (var0 & 2) { TlStoreString::store(description_, s); }
}

void bots_setBotInfo::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "bots.setBotInfo");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 4) { s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get())); }
    s.store_field("lang_code", lang_code_);
    if (var0 & 8) { s.store_field("name", name_); }
    if (var0 & 1) { s.store_field("about", about_); }
    if (var0 & 2) { s.store_field("description", description_); }
    s.store_class_end();
  }
}

bots_setBotInfo::ReturnType bots_setBotInfo::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_deleteChannel::channels_deleteChannel(object_ptr<InputChannel> &&channel_)
  : channel_(std::move(channel_))
{}

const std::int32_t channels_deleteChannel::ID;

void channels_deleteChannel::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1072619549);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_deleteChannel::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1072619549);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
}

void channels_deleteChannel::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.deleteChannel");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_class_end();
  }
}

channels_deleteChannel::ReturnType channels_deleteChannel::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_editBanned::channels_editBanned(object_ptr<InputChannel> &&channel_, object_ptr<InputPeer> &&participant_, object_ptr<chatBannedRights> &&banned_rights_)
  : channel_(std::move(channel_))
  , participant_(std::move(participant_))
  , banned_rights_(std::move(banned_rights_))
{}

const std::int32_t channels_editBanned::ID;

void channels_editBanned::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1763259007);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  TlStoreBoxed<TlStoreObject, -1626209256>::store(banned_rights_, s);
}

void channels_editBanned::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1763259007);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(participant_, s);
  TlStoreBoxed<TlStoreObject, -1626209256>::store(banned_rights_, s);
}

void channels_editBanned::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.editBanned");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_object_field("participant", static_cast<const BaseObject *>(participant_.get()));
    s.store_object_field("banned_rights", static_cast<const BaseObject *>(banned_rights_.get()));
    s.store_class_end();
  }
}

channels_editBanned::ReturnType channels_editBanned::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_getLeftChannels::channels_getLeftChannels(int32 offset_)
  : offset_(offset_)
{}

const std::int32_t channels_getLeftChannels::ID;

void channels_getLeftChannels::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2092831552);
  TlStoreBinary::store(offset_, s);
}

void channels_getLeftChannels::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2092831552);
  TlStoreBinary::store(offset_, s);
}

void channels_getLeftChannels::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.getLeftChannels");
    s.store_field("offset", offset_);
    s.store_class_end();
  }
}

channels_getLeftChannels::ReturnType channels_getLeftChannels::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

channels_setDiscussionGroup::channels_setDiscussionGroup(object_ptr<InputChannel> &&broadcast_, object_ptr<InputChannel> &&group_)
  : broadcast_(std::move(broadcast_))
  , group_(std::move(group_))
{}

const std::int32_t channels_setDiscussionGroup::ID;

void channels_setDiscussionGroup::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1079520178);
  TlStoreBoxedUnknown<TlStoreObject>::store(broadcast_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(group_, s);
}

void channels_setDiscussionGroup::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1079520178);
  TlStoreBoxedUnknown<TlStoreObject>::store(broadcast_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(group_, s);
}

void channels_setDiscussionGroup::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.setDiscussionGroup");
    s.store_object_field("broadcast", static_cast<const BaseObject *>(broadcast_.get()));
    s.store_object_field("group", static_cast<const BaseObject *>(group_.get()));
    s.store_class_end();
  }
}

channels_setDiscussionGroup::ReturnType channels_setDiscussionGroup::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

channels_toggleAntiSpam::channels_toggleAntiSpam(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_toggleAntiSpam::ID;

void channels_toggleAntiSpam::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1760814315);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleAntiSpam::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1760814315);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleAntiSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleAntiSpam");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_toggleAntiSpam::ReturnType channels_toggleAntiSpam::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

channels_toggleJoinToSend::channels_toggleJoinToSend(object_ptr<InputChannel> &&channel_, bool enabled_)
  : channel_(std::move(channel_))
  , enabled_(enabled_)
{}

const std::int32_t channels_toggleJoinToSend::ID;

void channels_toggleJoinToSend::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-456419968);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleJoinToSend::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-456419968);
  TlStoreBoxedUnknown<TlStoreObject>::store(channel_, s);
  TlStoreBool::store(enabled_, s);
}

void channels_toggleJoinToSend::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "channels.toggleJoinToSend");
    s.store_object_field("channel", static_cast<const BaseObject *>(channel_.get()));
    s.store_field("enabled", enabled_);
    s.store_class_end();
  }
}

channels_toggleJoinToSend::ReturnType channels_toggleJoinToSend::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

chatlists_hideChatlistUpdates::chatlists_hideChatlistUpdates(object_ptr<inputChatlistDialogFilter> &&chatlist_)
  : chatlist_(std::move(chatlist_))
{}

const std::int32_t chatlists_hideChatlistUpdates::ID;

void chatlists_hideChatlistUpdates::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1726252795);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_hideChatlistUpdates::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1726252795);
  TlStoreBoxed<TlStoreObject, -203367885>::store(chatlist_, s);
}

void chatlists_hideChatlistUpdates::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "chatlists.hideChatlistUpdates");
    s.store_object_field("chatlist", static_cast<const BaseObject *>(chatlist_.get()));
    s.store_class_end();
  }
}

chatlists_hideChatlistUpdates::ReturnType chatlists_hideChatlistUpdates::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

contacts_deleteByPhones::contacts_deleteByPhones(array<string> &&phones_)
  : phones_(std::move(phones_))
{}

const std::int32_t contacts_deleteByPhones::ID;

void contacts_deleteByPhones::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(269745566);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(phones_, s);
}

void contacts_deleteByPhones::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(269745566);
  TlStoreBoxed<TlStoreVector<TlStoreString>, 481674261>::store(phones_, s);
}

void contacts_deleteByPhones::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.deleteByPhones");
    { s.store_vector_begin("phones", phones_.size()); for (const auto &_value : phones_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

contacts_deleteByPhones::ReturnType contacts_deleteByPhones::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

contacts_getLocated::contacts_getLocated(int32 flags_, bool background_, object_ptr<InputGeoPoint> &&geo_point_, int32 self_expires_)
  : flags_(flags_)
  , background_(background_)
  , geo_point_(std::move(geo_point_))
  , self_expires_(self_expires_)
{}

const std::int32_t contacts_getLocated::ID;

void contacts_getLocated::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-750207932);
  TlStoreBinary::store((var0 = flags_ | (background_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  if (var0 & 1) { TlStoreBinary::store(self_expires_, s); }
}

void contacts_getLocated::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-750207932);
  TlStoreBinary::store((var0 = flags_ | (background_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(geo_point_, s);
  if (var0 & 1) { TlStoreBinary::store(self_expires_, s); }
}

void contacts_getLocated::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.getLocated");
    s.store_field("flags", (var0 = flags_ | (background_ << 1)));
    if (var0 & 2) { s.store_field("background", true); }
    s.store_object_field("geo_point", static_cast<const BaseObject *>(geo_point_.get()));
    if (var0 & 1) { s.store_field("self_expires", self_expires_); }
    s.store_class_end();
  }
}

contacts_getLocated::ReturnType contacts_getLocated::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

contacts_importContacts::contacts_importContacts(array<object_ptr<inputPhoneContact>> &&contacts_)
  : contacts_(std::move(contacts_))
{}

const std::int32_t contacts_importContacts::ID;

void contacts_importContacts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(746589157);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1780335806>>, 481674261>::store(contacts_, s);
}

void contacts_importContacts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(746589157);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 1780335806>>, 481674261>::store(contacts_, s);
}

void contacts_importContacts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "contacts.importContacts");
    { s.store_vector_begin("contacts", contacts_.size()); for (const auto &_value : contacts_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

contacts_importContacts::ReturnType contacts_importContacts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<contacts_importedContacts>, 2010127419>::parse(p);
#undef FAIL
}

const std::int32_t help_getCdnConfig::ID;

void help_getCdnConfig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1375900482);
}

void help_getCdnConfig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1375900482);
}

void help_getCdnConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getCdnConfig");
    s.store_class_end();
  }
}

help_getCdnConfig::ReturnType help_getCdnConfig::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<cdnConfig>, 1462101002>::parse(p);
#undef FAIL
}

const std::int32_t help_getSupportName::ID;

void help_getSupportName::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-748624084);
}

void help_getSupportName::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-748624084);
}

void help_getSupportName::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.getSupportName");
    s.store_class_end();
  }
}

help_getSupportName::ReturnType help_getSupportName::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<help_supportName>, -1945767479>::parse(p);
#undef FAIL
}

help_setBotUpdatesStatus::help_setBotUpdatesStatus(int32 pending_updates_count_, string const &message_)
  : pending_updates_count_(pending_updates_count_)
  , message_(message_)
{}

const std::int32_t help_setBotUpdatesStatus::ID;

void help_setBotUpdatesStatus::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-333262899);
  TlStoreBinary::store(pending_updates_count_, s);
  TlStoreString::store(message_, s);
}

void help_setBotUpdatesStatus::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-333262899);
  TlStoreBinary::store(pending_updates_count_, s);
  TlStoreString::store(message_, s);
}

void help_setBotUpdatesStatus::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "help.setBotUpdatesStatus");
    s.store_field("pending_updates_count", pending_updates_count_);
    s.store_field("message", message_);
    s.store_class_end();
  }
}

help_setBotUpdatesStatus::ReturnType help_setBotUpdatesStatus::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_acceptUrlAuth::messages_acceptUrlAuth(int32 flags_, bool write_allowed_, bool share_phone_number_, object_ptr<InputPeer> &&peer_, int32 msg_id_, int32 button_id_, string const &url_, string const &match_code_)
  : flags_(flags_)
  , write_allowed_(write_allowed_)
  , share_phone_number_(share_phone_number_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , button_id_(button_id_)
  , url_(url_)
  , match_code_(match_code_)
{}

const std::int32_t messages_acceptUrlAuth::ID;

void messages_acceptUrlAuth::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1738797278);
  TlStoreBinary::store((var0 = flags_ | (write_allowed_ << 0) | (share_phone_number_ << 3)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 2) { TlStoreBinary::store(msg_id_, s); }
  if (var0 & 2) { TlStoreBinary::store(button_id_, s); }
  if (var0 & 4) { TlStoreString::store(url_, s); }
  if (var0 & 16) { TlStoreString::store(match_code_, s); }
}

void messages_acceptUrlAuth::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1738797278);
  TlStoreBinary::store((var0 = flags_ | (write_allowed_ << 0) | (share_phone_number_ << 3)), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 2) { TlStoreBinary::store(msg_id_, s); }
  if (var0 & 2) { TlStoreBinary::store(button_id_, s); }
  if (var0 & 4) { TlStoreString::store(url_, s); }
  if (var0 & 16) { TlStoreString::store(match_code_, s); }
}

void messages_acceptUrlAuth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.acceptUrlAuth");
    s.store_field("flags", (var0 = flags_ | (write_allowed_ << 0) | (share_phone_number_ << 3)));
    if (var0 & 1) { s.store_field("write_allowed", true); }
    if (var0 & 8) { s.store_field("share_phone_number", true); }
    if (var0 & 2) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 2) { s.store_field("msg_id", msg_id_); }
    if (var0 & 2) { s.store_field("button_id", button_id_); }
    if (var0 & 4) { s.store_field("url", url_); }
    if (var0 & 16) { s.store_field("match_code", match_code_); }
    s.store_class_end();
  }
}

messages_acceptUrlAuth::ReturnType messages_acceptUrlAuth::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<UrlAuthResult>::parse(p);
#undef FAIL
}

messages_clearRecentStickers::messages_clearRecentStickers(int32 flags_, bool attached_)
  : flags_(flags_)
  , attached_(attached_)
{}

const std::int32_t messages_clearRecentStickers::ID;

void messages_clearRecentStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1986437075);
  TlStoreBinary::store((var0 = flags_ | (attached_ << 0)), s);
}

void messages_clearRecentStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1986437075);
  TlStoreBinary::store((var0 = flags_ | (attached_ << 0)), s);
}

void messages_clearRecentStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.clearRecentStickers");
    s.store_field("flags", (var0 = flags_ | (attached_ << 0)));
    if (var0 & 1) { s.store_field("attached", true); }
    s.store_class_end();
  }
}

messages_clearRecentStickers::ReturnType messages_clearRecentStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_deleteHistory::messages_deleteHistory(int32 flags_, bool just_clear_, bool revoke_, object_ptr<InputPeer> &&peer_, int32 max_id_, int32 min_date_, int32 max_date_)
  : flags_(flags_)
  , just_clear_(just_clear_)
  , revoke_(revoke_)
  , peer_(std::move(peer_))
  , max_id_(max_id_)
  , min_date_(min_date_)
  , max_date_(max_date_)
{}

const std::int32_t messages_deleteHistory::ID;

void messages_deleteHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1332768214);
  TlStoreBinary::store((var0 = flags_ | (just_clear_ << 0) | (revoke_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
  if (var0 & 4) { TlStoreBinary::store(min_date_, s); }
  if (var0 & 8) { TlStoreBinary::store(max_date_, s); }
}

void messages_deleteHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1332768214);
  TlStoreBinary::store((var0 = flags_ | (just_clear_ << 0) | (revoke_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
  if (var0 & 4) { TlStoreBinary::store(min_date_, s); }
  if (var0 & 8) { TlStoreBinary::store(max_date_, s); }
}

void messages_deleteHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.deleteHistory");
    s.store_field("flags", (var0 = flags_ | (just_clear_ << 0) | (revoke_ << 1)));
    if (var0 & 1) { s.store_field("just_clear", true); }
    if (var0 & 2) { s.store_field("revoke", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    if (var0 & 4) { s.store_field("min_date", min_date_); }
    if (var0 & 8) { s.store_field("max_date", max_date_); }
    s.store_class_end();
  }
}

messages_deleteHistory::ReturnType messages_deleteHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_editChatAbout::messages_editChatAbout(object_ptr<InputPeer> &&peer_, string const &about_)
  : peer_(std::move(peer_))
  , about_(about_)
{}

const std::int32_t messages_editChatAbout::ID;

void messages_editChatAbout::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-554301545);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(about_, s);
}

void messages_editChatAbout::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-554301545);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(about_, s);
}

void messages_editChatAbout::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editChatAbout");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("about", about_);
    s.store_class_end();
  }
}

messages_editChatAbout::ReturnType messages_editChatAbout::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_editInlineBotMessage::messages_editInlineBotMessage(int32 flags_, bool no_webpage_, bool invert_media_, object_ptr<InputBotInlineMessageID> &&id_, string const &message_, object_ptr<InputMedia> &&media_, object_ptr<ReplyMarkup> &&reply_markup_, array<object_ptr<MessageEntity>> &&entities_)
  : flags_(flags_)
  , no_webpage_(no_webpage_)
  , invert_media_(invert_media_)
  , id_(std::move(id_))
  , message_(message_)
  , media_(std::move(media_))
  , reply_markup_(std::move(reply_markup_))
  , entities_(std::move(entities_))
{}

const std::int32_t messages_editInlineBotMessage::ID;

void messages_editInlineBotMessage::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-2091549254);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 16)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 2048) { TlStoreString::store(message_, s); }
  if (var0 & 16384) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void messages_editInlineBotMessage::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-2091549254);
  TlStoreBinary::store((var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 16)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  if (var0 & 2048) { TlStoreString::store(message_, s); }
  if (var0 & 16384) { TlStoreBoxedUnknown<TlStoreObject>::store(media_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_markup_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(entities_, s); }
}

void messages_editInlineBotMessage::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.editInlineBotMessage");
    s.store_field("flags", (var0 = flags_ | (no_webpage_ << 1) | (invert_media_ << 16)));
    if (var0 & 2) { s.store_field("no_webpage", true); }
    if (var0 & 65536) { s.store_field("invert_media", true); }
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    if (var0 & 2048) { s.store_field("message", message_); }
    if (var0 & 16384) { s.store_object_field("media", static_cast<const BaseObject *>(media_.get())); }
    if (var0 & 4) { s.store_object_field("reply_markup", static_cast<const BaseObject *>(reply_markup_.get())); }
    if (var0 & 8) { { s.store_vector_begin("entities", entities_.size()); for (const auto &_value : entities_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    s.store_class_end();
  }
}

messages_editInlineBotMessage::ReturnType messages_editInlineBotMessage::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_faveSticker::messages_faveSticker(object_ptr<InputDocument> &&id_, bool unfave_)
  : id_(std::move(id_))
  , unfave_(unfave_)
{}

const std::int32_t messages_faveSticker::ID;

void messages_faveSticker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1174420133);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unfave_, s);
}

void messages_faveSticker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1174420133);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBool::store(unfave_, s);
}

void messages_faveSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.faveSticker");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_field("unfave", unfave_);
    s.store_class_end();
  }
}

messages_faveSticker::ReturnType messages_faveSticker::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_forwardMessages::messages_forwardMessages(int32 flags_, bool silent_, bool background_, bool with_my_score_, bool drop_author_, bool drop_media_captions_, bool noforwards_, bool allow_paid_floodskip_, object_ptr<InputPeer> &&from_peer_, array<int32> &&id_, array<int64> &&random_id_, object_ptr<InputPeer> &&to_peer_, int32 top_msg_id_, object_ptr<InputReplyTo> &&reply_to_, int32 schedule_date_, int32 schedule_repeat_period_, object_ptr<InputPeer> &&send_as_, object_ptr<InputQuickReplyShortcut> &&quick_reply_shortcut_, int64 effect_, int32 video_timestamp_, int64 allow_paid_stars_, object_ptr<suggestedPost> &&suggested_post_)
  : flags_(flags_)
  , silent_(silent_)
  , background_(background_)
  , with_my_score_(with_my_score_)
  , drop_author_(drop_author_)
  , drop_media_captions_(drop_media_captions_)
  , noforwards_(noforwards_)
  , allow_paid_floodskip_(allow_paid_floodskip_)
  , from_peer_(std::move(from_peer_))
  , id_(std::move(id_))
  , random_id_(std::move(random_id_))
  , to_peer_(std::move(to_peer_))
  , top_msg_id_(top_msg_id_)
  , reply_to_(std::move(reply_to_))
  , schedule_date_(schedule_date_)
  , schedule_repeat_period_(schedule_repeat_period_)
  , send_as_(std::move(send_as_))
  , quick_reply_shortcut_(std::move(quick_reply_shortcut_))
  , effect_(effect_)
  , video_timestamp_(video_timestamp_)
  , allow_paid_stars_(allow_paid_stars_)
  , suggested_post_(std::move(suggested_post_))
{}

const std::int32_t messages_forwardMessages::ID;

void messages_forwardMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(326126204);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (with_my_score_ << 8) | (drop_author_ << 11) | (drop_media_captions_ << 12) | (noforwards_ << 14) | (allow_paid_floodskip_ << 19)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(from_peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(random_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_peer_, s);
  if (var0 & 512) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 4194304) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 16777216) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 1048576) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 8388608) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
}

void messages_forwardMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(326126204);
  TlStoreBinary::store((var0 = flags_ | (silent_ << 5) | (background_ << 6) | (with_my_score_ << 8) | (drop_author_ << 11) | (drop_media_captions_ << 12) | (noforwards_ << 14) | (allow_paid_floodskip_ << 19)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(from_peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(random_id_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(to_peer_, s);
  if (var0 & 512) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 4194304) { TlStoreBoxedUnknown<TlStoreObject>::store(reply_to_, s); }
  if (var0 & 1024) { TlStoreBinary::store(schedule_date_, s); }
  if (var0 & 16777216) { TlStoreBinary::store(schedule_repeat_period_, s); }
  if (var0 & 8192) { TlStoreBoxedUnknown<TlStoreObject>::store(send_as_, s); }
  if (var0 & 131072) { TlStoreBoxedUnknown<TlStoreObject>::store(quick_reply_shortcut_, s); }
  if (var0 & 262144) { TlStoreBinary::store(effect_, s); }
  if (var0 & 1048576) { TlStoreBinary::store(video_timestamp_, s); }
  if (var0 & 2097152) { TlStoreBinary::store(allow_paid_stars_, s); }
  if (var0 & 8388608) { TlStoreBoxed<TlStoreObject, 244201445>::store(suggested_post_, s); }
}

void messages_forwardMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.forwardMessages");
    s.store_field("flags", (var0 = flags_ | (silent_ << 5) | (background_ << 6) | (with_my_score_ << 8) | (drop_author_ << 11) | (drop_media_captions_ << 12) | (noforwards_ << 14) | (allow_paid_floodskip_ << 19)));
    if (var0 & 32) { s.store_field("silent", true); }
    if (var0 & 64) { s.store_field("background", true); }
    if (var0 & 256) { s.store_field("with_my_score", true); }
    if (var0 & 2048) { s.store_field("drop_author", true); }
    if (var0 & 4096) { s.store_field("drop_media_captions", true); }
    if (var0 & 16384) { s.store_field("noforwards", true); }
    if (var0 & 524288) { s.store_field("allow_paid_floodskip", true); }
    s.store_object_field("from_peer", static_cast<const BaseObject *>(from_peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    { s.store_vector_begin("random_id", random_id_.size()); for (const auto &_value : random_id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_object_field("to_peer", static_cast<const BaseObject *>(to_peer_.get()));
    if (var0 & 512) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 4194304) { s.store_object_field("reply_to", static_cast<const BaseObject *>(reply_to_.get())); }
    if (var0 & 1024) { s.store_field("schedule_date", schedule_date_); }
    if (var0 & 16777216) { s.store_field("schedule_repeat_period", schedule_repeat_period_); }
    if (var0 & 8192) { s.store_object_field("send_as", static_cast<const BaseObject *>(send_as_.get())); }
    if (var0 & 131072) { s.store_object_field("quick_reply_shortcut", static_cast<const BaseObject *>(quick_reply_shortcut_.get())); }
    if (var0 & 262144) { s.store_field("effect", effect_); }
    if (var0 & 1048576) { s.store_field("video_timestamp", video_timestamp_); }
    if (var0 & 2097152) { s.store_field("allow_paid_stars", allow_paid_stars_); }
    if (var0 & 8388608) { s.store_object_field("suggested_post", static_cast<const BaseObject *>(suggested_post_.get())); }
    s.store_class_end();
  }
}

messages_forwardMessages::ReturnType messages_forwardMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

const std::int32_t messages_getAllDrafts::ID;

void messages_getAllDrafts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1782549861);
}

void messages_getAllDrafts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1782549861);
}

void messages_getAllDrafts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAllDrafts");
    s.store_class_end();
  }
}

messages_getAllDrafts::ReturnType messages_getAllDrafts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_getAttachMenuBots::messages_getAttachMenuBots(int64 hash_)
  : hash_(hash_)
{}

const std::int32_t messages_getAttachMenuBots::ID;

void messages_getAttachMenuBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(385663691);
  TlStoreBinary::store(hash_, s);
}

void messages_getAttachMenuBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(385663691);
  TlStoreBinary::store(hash_, s);
}

void messages_getAttachMenuBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAttachMenuBots");
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getAttachMenuBots::ReturnType messages_getAttachMenuBots::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<AttachMenuBots>::parse(p);
#undef FAIL
}

messages_getAttachedStickers::messages_getAttachedStickers(object_ptr<InputStickeredMedia> &&media_)
  : media_(std::move(media_))
{}

const std::int32_t messages_getAttachedStickers::ID;

void messages_getAttachedStickers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-866424884);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messages_getAttachedStickers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-866424884);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messages_getAttachedStickers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getAttachedStickers");
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

messages_getAttachedStickers::ReturnType messages_getAttachedStickers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<StickerSetCovered>>, 481674261>::parse(p);
#undef FAIL
}

messages_getCommonChats::messages_getCommonChats(object_ptr<InputUser> &&user_id_, int64 max_id_, int32 limit_)
  : user_id_(std::move(user_id_))
  , max_id_(max_id_)
  , limit_(limit_)
{}

const std::int32_t messages_getCommonChats::ID;

void messages_getCommonChats::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-468934396);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getCommonChats::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-468934396);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(limit_, s);
}

void messages_getCommonChats::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getCommonChats");
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_field("max_id", max_id_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

messages_getCommonChats::ReturnType messages_getCommonChats::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Chats>::parse(p);
#undef FAIL
}

messages_getDhConfig::messages_getDhConfig(int32 version_, int32 random_length_)
  : version_(version_)
  , random_length_(random_length_)
{}

const std::int32_t messages_getDhConfig::ID;

void messages_getDhConfig::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(651135312);
  TlStoreBinary::store(version_, s);
  TlStoreBinary::store(random_length_, s);
}

void messages_getDhConfig::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(651135312);
  TlStoreBinary::store(version_, s);
  TlStoreBinary::store(random_length_, s);
}

void messages_getDhConfig::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getDhConfig");
    s.store_field("version", version_);
    s.store_field("random_length", random_length_);
    s.store_class_end();
  }
}

messages_getDhConfig::ReturnType messages_getDhConfig::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_DhConfig>::parse(p);
#undef FAIL
}

messages_getForumTopicsByID::messages_getForumTopicsByID(object_ptr<InputPeer> &&peer_, array<int32> &&topics_)
  : peer_(std::move(peer_))
  , topics_(std::move(topics_))
{}

const std::int32_t messages_getForumTopicsByID::ID;

void messages_getForumTopicsByID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1358280184);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(topics_, s);
}

void messages_getForumTopicsByID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1358280184);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(topics_, s);
}

void messages_getForumTopicsByID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getForumTopicsByID");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("topics", topics_.size()); for (const auto &_value : topics_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_getForumTopicsByID::ReturnType messages_getForumTopicsByID::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_forumTopics>, 913709011>::parse(p);
#undef FAIL
}

messages_getFullChat::messages_getFullChat(int64 chat_id_)
  : chat_id_(chat_id_)
{}

const std::int32_t messages_getFullChat::ID;

void messages_getFullChat::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1364194508);
  TlStoreBinary::store(chat_id_, s);
}

void messages_getFullChat::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1364194508);
  TlStoreBinary::store(chat_id_, s);
}

void messages_getFullChat::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getFullChat");
    s.store_field("chat_id", chat_id_);
    s.store_class_end();
  }
}

messages_getFullChat::ReturnType messages_getFullChat::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_chatFull>, -438840932>::parse(p);
#undef FAIL
}

messages_getMessagesViews::messages_getMessagesViews(object_ptr<InputPeer> &&peer_, array<int32> &&id_, bool increment_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
  , increment_(increment_)
{}

const std::int32_t messages_getMessagesViews::ID;

void messages_getMessagesViews::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1468322785);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBool::store(increment_, s);
}

void messages_getMessagesViews::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1468322785);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
  TlStoreBool::store(increment_, s);
}

void messages_getMessagesViews::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getMessagesViews");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_field("increment", increment_);
    s.store_class_end();
  }
}

messages_getMessagesViews::ReturnType messages_getMessagesViews::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_messageViews>, -1228606141>::parse(p);
#undef FAIL
}

messages_getRecentReactions::messages_getRecentReactions(int32 limit_, int64 hash_)
  : limit_(limit_)
  , hash_(hash_)
{}

const std::int32_t messages_getRecentReactions::ID;

void messages_getRecentReactions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(960896434);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getRecentReactions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(960896434);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_getRecentReactions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.getRecentReactions");
    s.store_field("limit", limit_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_getRecentReactions::ReturnType messages_getRecentReactions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Reactions>::parse(p);
#undef FAIL
}

messages_readHistory::messages_readHistory(object_ptr<InputPeer> &&peer_, int32 max_id_)
  : peer_(std::move(peer_))
  , max_id_(max_id_)
{}

const std::int32_t messages_readHistory::ID;

void messages_readHistory::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(238054714);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
}

void messages_readHistory::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(238054714);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(max_id_, s);
}

void messages_readHistory::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.readHistory");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("max_id", max_id_);
    s.store_class_end();
  }
}

messages_readHistory::ReturnType messages_readHistory::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedMessages>, -2066640507>::parse(p);
#undef FAIL
}

messages_reportEncryptedSpam::messages_reportEncryptedSpam(object_ptr<inputEncryptedChat> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t messages_reportEncryptedSpam::ID;

void messages_reportEncryptedSpam::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1259113487);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
}

void messages_reportEncryptedSpam::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1259113487);
  TlStoreBoxed<TlStoreObject, -247351839>::store(peer_, s);
}

void messages_reportEncryptedSpam::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.reportEncryptedSpam");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_reportEncryptedSpam::ReturnType messages_reportEncryptedSpam::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_requestUrlAuth::messages_requestUrlAuth(int32 flags_, object_ptr<InputPeer> &&peer_, int32 msg_id_, int32 button_id_, string const &url_, string const &in_app_origin_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , button_id_(button_id_)
  , url_(url_)
  , in_app_origin_(in_app_origin_)
{}

const std::int32_t messages_requestUrlAuth::ID;

void messages_requestUrlAuth::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1991456356);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 2) { TlStoreBinary::store(msg_id_, s); }
  if (var0 & 2) { TlStoreBinary::store(button_id_, s); }
  if (var0 & 4) { TlStoreString::store(url_, s); }
  if (var0 & 8) { TlStoreString::store(in_app_origin_, s); }
}

void messages_requestUrlAuth::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1991456356);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s); }
  if (var0 & 2) { TlStoreBinary::store(msg_id_, s); }
  if (var0 & 2) { TlStoreBinary::store(button_id_, s); }
  if (var0 & 4) { TlStoreString::store(url_, s); }
  if (var0 & 8) { TlStoreString::store(in_app_origin_, s); }
}

void messages_requestUrlAuth::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.requestUrlAuth");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 2) { s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get())); }
    if (var0 & 2) { s.store_field("msg_id", msg_id_); }
    if (var0 & 2) { s.store_field("button_id", button_id_); }
    if (var0 & 4) { s.store_field("url", url_); }
    if (var0 & 8) { s.store_field("in_app_origin", in_app_origin_); }
    s.store_class_end();
  }
}

messages_requestUrlAuth::ReturnType messages_requestUrlAuth::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<UrlAuthResult>::parse(p);
#undef FAIL
}

messages_search::messages_search(int32 flags_, object_ptr<InputPeer> &&peer_, string const &q_, object_ptr<InputPeer> &&from_id_, object_ptr<InputPeer> &&saved_peer_id_, array<object_ptr<Reaction>> &&saved_reaction_, int32 top_msg_id_, object_ptr<MessagesFilter> &&filter_, int32 min_date_, int32 max_date_, int32 offset_id_, int32 add_offset_, int32 limit_, int32 max_id_, int32 min_id_, int64 hash_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , q_(q_)
  , from_id_(std::move(from_id_))
  , saved_peer_id_(std::move(saved_peer_id_))
  , saved_reaction_(std::move(saved_reaction_))
  , top_msg_id_(top_msg_id_)
  , filter_(std::move(filter_))
  , min_date_(min_date_)
  , max_date_(max_date_)
  , offset_id_(offset_id_)
  , add_offset_(add_offset_)
  , limit_(limit_)
  , max_id_(max_id_)
  , min_id_(min_id_)
  , hash_(hash_)
{}

const std::int32_t messages_search::ID;

void messages_search::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(703497338);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(q_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(from_id_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(saved_reaction_, s); }
  if (var0 & 2) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(min_date_, s);
  TlStoreBinary::store(max_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_search::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(703497338);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(q_, s);
  if (var0 & 1) { TlStoreBoxedUnknown<TlStoreObject>::store(from_id_, s); }
  if (var0 & 4) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(saved_reaction_, s); }
  if (var0 & 2) { TlStoreBinary::store(top_msg_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(filter_, s);
  TlStoreBinary::store(min_date_, s);
  TlStoreBinary::store(max_date_, s);
  TlStoreBinary::store(offset_id_, s);
  TlStoreBinary::store(add_offset_, s);
  TlStoreBinary::store(limit_, s);
  TlStoreBinary::store(max_id_, s);
  TlStoreBinary::store(min_id_, s);
  TlStoreBinary::store(hash_, s);
}

void messages_search::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.search");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("q", q_);
    if (var0 & 1) { s.store_object_field("from_id", static_cast<const BaseObject *>(from_id_.get())); }
    if (var0 & 4) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    if (var0 & 8) { { s.store_vector_begin("saved_reaction", saved_reaction_.size()); for (const auto &_value : saved_reaction_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); } }
    if (var0 & 2) { s.store_field("top_msg_id", top_msg_id_); }
    s.store_object_field("filter", static_cast<const BaseObject *>(filter_.get()));
    s.store_field("min_date", min_date_);
    s.store_field("max_date", max_date_);
    s.store_field("offset_id", offset_id_);
    s.store_field("add_offset", add_offset_);
    s.store_field("limit", limit_);
    s.store_field("max_id", max_id_);
    s.store_field("min_id", min_id_);
    s.store_field("hash", hash_);
    s.store_class_end();
  }
}

messages_search::ReturnType messages_search::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_Messages>::parse(p);
#undef FAIL
}

messages_sendBotRequestedPeer::messages_sendBotRequestedPeer(int32 flags_, object_ptr<InputPeer> &&peer_, int32 msg_id_, string const &webapp_req_id_, int32 button_id_, array<object_ptr<InputPeer>> &&requested_peers_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , msg_id_(msg_id_)
  , webapp_req_id_(webapp_req_id_)
  , button_id_(button_id_)
  , requested_peers_(std::move(requested_peers_))
{}

const std::int32_t messages_sendBotRequestedPeer::ID;

void messages_sendBotRequestedPeer::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1818030759);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(msg_id_, s); }
  if (var0 & 2) { TlStoreString::store(webapp_req_id_, s); }
  TlStoreBinary::store(button_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(requested_peers_, s);
}

void messages_sendBotRequestedPeer::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1818030759);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(msg_id_, s); }
  if (var0 & 2) { TlStoreString::store(webapp_req_id_, s); }
  TlStoreBinary::store(button_id_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(requested_peers_, s);
}

void messages_sendBotRequestedPeer::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendBotRequestedPeer");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("msg_id", msg_id_); }
    if (var0 & 2) { s.store_field("webapp_req_id", webapp_req_id_); }
    s.store_field("button_id", button_id_);
    { s.store_vector_begin("requested_peers", requested_peers_.size()); for (const auto &_value : requested_peers_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_sendBotRequestedPeer::ReturnType messages_sendBotRequestedPeer::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_sendWebViewData::messages_sendWebViewData(object_ptr<InputUser> &&bot_, int64 random_id_, string const &button_text_, string const &data_)
  : bot_(std::move(bot_))
  , random_id_(random_id_)
  , button_text_(button_text_)
  , data_(data_)
{}

const std::int32_t messages_sendWebViewData::ID;

void messages_sendWebViewData::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-603831608);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(button_text_, s);
  TlStoreString::store(data_, s);
}

void messages_sendWebViewData::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-603831608);
  TlStoreBoxedUnknown<TlStoreObject>::store(bot_, s);
  TlStoreBinary::store(random_id_, s);
  TlStoreString::store(button_text_, s);
  TlStoreString::store(data_, s);
}

void messages_sendWebViewData::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.sendWebViewData");
    s.store_object_field("bot", static_cast<const BaseObject *>(bot_.get()));
    s.store_field("random_id", random_id_);
    s.store_field("button_text", button_text_);
    s.store_field("data", data_);
    s.store_class_end();
  }
}

messages_sendWebViewData::ReturnType messages_sendWebViewData::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

messages_toggleSavedDialogPin::messages_toggleSavedDialogPin(int32 flags_, bool pinned_, object_ptr<InputDialogPeer> &&peer_)
  : flags_(flags_)
  , pinned_(pinned_)
  , peer_(std::move(peer_))
{}

const std::int32_t messages_toggleSavedDialogPin::ID;

void messages_toggleSavedDialogPin::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1400783906);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_toggleSavedDialogPin::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1400783906);
  TlStoreBinary::store((var0 = flags_ | (pinned_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void messages_toggleSavedDialogPin::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleSavedDialogPin");
    s.store_field("flags", (var0 = flags_ | (pinned_ << 0)));
    if (var0 & 1) { s.store_field("pinned", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

messages_toggleSavedDialogPin::ReturnType messages_toggleSavedDialogPin::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_toggleStickerSets::messages_toggleStickerSets(int32 flags_, bool uninstall_, bool archive_, bool unarchive_, array<object_ptr<InputStickerSet>> &&stickersets_)
  : flags_(flags_)
  , uninstall_(uninstall_)
  , archive_(archive_)
  , unarchive_(unarchive_)
  , stickersets_(std::move(stickersets_))
{}

const std::int32_t messages_toggleStickerSets::ID;

void messages_toggleStickerSets::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1257951254);
  TlStoreBinary::store((var0 = flags_ | (uninstall_ << 0) | (archive_ << 1) | (unarchive_ << 2)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickersets_, s);
}

void messages_toggleStickerSets::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1257951254);
  TlStoreBinary::store((var0 = flags_ | (uninstall_ << 0) | (archive_ << 1) | (unarchive_ << 2)), s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(stickersets_, s);
}

void messages_toggleStickerSets::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.toggleStickerSets");
    s.store_field("flags", (var0 = flags_ | (uninstall_ << 0) | (archive_ << 1) | (unarchive_ << 2)));
    if (var0 & 1) { s.store_field("uninstall", true); }
    if (var0 & 2) { s.store_field("archive", true); }
    if (var0 & 4) { s.store_field("unarchive", true); }
    { s.store_vector_begin("stickersets", stickersets_.size()); for (const auto &_value : stickersets_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

messages_toggleStickerSets::ReturnType messages_toggleStickerSets::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

messages_unpinAllMessages::messages_unpinAllMessages(int32 flags_, object_ptr<InputPeer> &&peer_, int32 top_msg_id_, object_ptr<InputPeer> &&saved_peer_id_)
  : flags_(flags_)
  , peer_(std::move(peer_))
  , top_msg_id_(top_msg_id_)
  , saved_peer_id_(std::move(saved_peer_id_))
{}

const std::int32_t messages_unpinAllMessages::ID;

void messages_unpinAllMessages::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(103667527);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
}

void messages_unpinAllMessages::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(103667527);
  TlStoreBinary::store((var0 = flags_), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 1) { TlStoreBinary::store(top_msg_id_, s); }
  if (var0 & 2) { TlStoreBoxedUnknown<TlStoreObject>::store(saved_peer_id_, s); }
}

void messages_unpinAllMessages::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.unpinAllMessages");
    s.store_field("flags", (var0 = flags_));
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 1) { s.store_field("top_msg_id", top_msg_id_); }
    if (var0 & 2) { s.store_object_field("saved_peer_id", static_cast<const BaseObject *>(saved_peer_id_.get())); }
    s.store_class_end();
  }
}

messages_unpinAllMessages::ReturnType messages_unpinAllMessages::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<messages_affectedHistory>, -1269012015>::parse(p);
#undef FAIL
}

messages_uploadMedia::messages_uploadMedia(int32 flags_, string const &business_connection_id_, object_ptr<InputPeer> &&peer_, object_ptr<InputMedia> &&media_)
  : flags_(flags_)
  , business_connection_id_(business_connection_id_)
  , peer_(std::move(peer_))
  , media_(std::move(media_))
{}

const std::int32_t messages_uploadMedia::ID;

void messages_uploadMedia::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(345405816);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(business_connection_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messages_uploadMedia::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(345405816);
  TlStoreBinary::store((var0 = flags_), s);
  if (var0 & 1) { TlStoreString::store(business_connection_id_, s); }
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(media_, s);
}

void messages_uploadMedia::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "messages.uploadMedia");
    s.store_field("flags", (var0 = flags_));
    if (var0 & 1) { s.store_field("business_connection_id", business_connection_id_); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("media", static_cast<const BaseObject *>(media_.get()));
    s.store_class_end();
  }
}

messages_uploadMedia::ReturnType messages_uploadMedia::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<MessageMedia>::parse(p);
#undef FAIL
}

payments_deleteStarGiftCollection::payments_deleteStarGiftCollection(object_ptr<InputPeer> &&peer_, int32 collection_id_)
  : peer_(std::move(peer_))
  , collection_id_(collection_id_)
{}

const std::int32_t payments_deleteStarGiftCollection::ID;

void payments_deleteStarGiftCollection::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1386854168);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(collection_id_, s);
}

void payments_deleteStarGiftCollection::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1386854168);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBinary::store(collection_id_, s);
}

void payments_deleteStarGiftCollection::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.deleteStarGiftCollection");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("collection_id", collection_id_);
    s.store_class_end();
  }
}

payments_deleteStarGiftCollection::ReturnType payments_deleteStarGiftCollection::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_getStarGiftUpgradeAttributes::payments_getStarGiftUpgradeAttributes(int64 gift_id_)
  : gift_id_(gift_id_)
{}

const std::int32_t payments_getStarGiftUpgradeAttributes::ID;

void payments_getStarGiftUpgradeAttributes::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1828948824);
  TlStoreBinary::store(gift_id_, s);
}

void payments_getStarGiftUpgradeAttributes::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1828948824);
  TlStoreBinary::store(gift_id_, s);
}

void payments_getStarGiftUpgradeAttributes::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarGiftUpgradeAttributes");
    s.store_field("gift_id", gift_id_);
    s.store_class_end();
  }
}

payments_getStarGiftUpgradeAttributes::ReturnType payments_getStarGiftUpgradeAttributes::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starGiftUpgradeAttributes>, 1187439471>::parse(p);
#undef FAIL
}

const std::int32_t payments_getStarsGiveawayOptions::ID;

void payments_getStarsGiveawayOptions::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1122042562);
}

void payments_getStarsGiveawayOptions::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1122042562);
}

void payments_getStarsGiveawayOptions::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsGiveawayOptions");
    s.store_class_end();
  }
}

payments_getStarsGiveawayOptions::ReturnType payments_getStarsGiveawayOptions::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<starsGiveawayOption>, -1798404822>>, 481674261>::parse(p);
#undef FAIL
}

payments_getStarsTransactionsByID::payments_getStarsTransactionsByID(int32 flags_, bool ton_, object_ptr<InputPeer> &&peer_, array<object_ptr<inputStarsTransaction>> &&id_)
  : flags_(flags_)
  , ton_(ton_)
  , peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t payments_getStarsTransactionsByID::ID;

void payments_getStarsTransactionsByID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(768218808);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 543876817>>, 481674261>::store(id_, s);
}

void payments_getStarsTransactionsByID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(768218808);
  TlStoreBinary::store((var0 = flags_ | (ton_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBoxed<TlStoreObject, 543876817>>, 481674261>::store(id_, s);
}

void payments_getStarsTransactionsByID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getStarsTransactionsByID");
    s.store_field("flags", (var0 = flags_ | (ton_ << 0)));
    if (var0 & 1) { s.store_field("ton", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_getStarsTransactionsByID::ReturnType payments_getStarsTransactionsByID::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_starsStatus>, 1822222573>::parse(p);
#undef FAIL
}

payments_getSuggestedStarRefBots::payments_getSuggestedStarRefBots(int32 flags_, bool order_by_revenue_, bool order_by_date_, object_ptr<InputPeer> &&peer_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , order_by_revenue_(order_by_revenue_)
  , order_by_date_(order_by_date_)
  , peer_(std::move(peer_))
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t payments_getSuggestedStarRefBots::ID;

void payments_getSuggestedStarRefBots::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(225134839);
  TlStoreBinary::store((var0 = flags_ | (order_by_revenue_ << 0) | (order_by_date_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getSuggestedStarRefBots::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(225134839);
  TlStoreBinary::store((var0 = flags_ | (order_by_revenue_ << 0) | (order_by_date_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void payments_getSuggestedStarRefBots::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.getSuggestedStarRefBots");
    s.store_field("flags", (var0 = flags_ | (order_by_revenue_ << 0) | (order_by_date_ << 1)));
    if (var0 & 1) { s.store_field("order_by_revenue", true); }
    if (var0 & 2) { s.store_field("order_by_date", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

payments_getSuggestedStarRefBots::ReturnType payments_getSuggestedStarRefBots::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<payments_suggestedStarRefBots>, -1261053863>::parse(p);
#undef FAIL
}

payments_reorderStarGiftCollections::payments_reorderStarGiftCollections(object_ptr<InputPeer> &&peer_, array<int32> &&order_)
  : peer_(std::move(peer_))
  , order_(std::move(order_))
{}

const std::int32_t payments_reorderStarGiftCollections::ID;

void payments_reorderStarGiftCollections::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1020594996);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void payments_reorderStarGiftCollections::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1020594996);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(order_, s);
}

void payments_reorderStarGiftCollections::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.reorderStarGiftCollections");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("order", order_.size()); for (const auto &_value : order_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

payments_reorderStarGiftCollections::ReturnType payments_reorderStarGiftCollections::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

payments_saveStarGift::payments_saveStarGift(int32 flags_, bool unsave_, object_ptr<InputSavedStarGift> &&stargift_)
  : flags_(flags_)
  , unsave_(unsave_)
  , stargift_(std::move(stargift_))
{}

const std::int32_t payments_saveStarGift::ID;

void payments_saveStarGift::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(707422588);
  TlStoreBinary::store((var0 = flags_ | (unsave_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_saveStarGift::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(707422588);
  TlStoreBinary::store((var0 = flags_ | (unsave_ << 0)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(stargift_, s);
}

void payments_saveStarGift::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "payments.saveStarGift");
    s.store_field("flags", (var0 = flags_ | (unsave_ << 0)));
    if (var0 & 1) { s.store_field("unsave", true); }
    s.store_object_field("stargift", static_cast<const BaseObject *>(stargift_.get()));
    s.store_class_end();
  }
}

payments_saveStarGift::ReturnType payments_saveStarGift::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBool::parse(p);
#undef FAIL
}

phone_createConferenceCall::phone_createConferenceCall(int32 flags_, bool muted_, bool video_stopped_, bool join_, int32 random_id_, UInt256 const &public_key_, bytes &&block_, object_ptr<dataJSON> &&params_)
  : flags_(flags_)
  , muted_(muted_)
  , video_stopped_(video_stopped_)
  , join_(join_)
  , random_id_(random_id_)
  , public_key_(public_key_)
  , block_(std::move(block_))
  , params_(std::move(params_))
{}

const std::int32_t phone_createConferenceCall::ID;

void phone_createConferenceCall::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2097431739);
  TlStoreBinary::store((var0 = flags_ | (muted_ << 0) | (video_stopped_ << 2) | (join_ << 3)), s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 8) { TlStoreBinary::store(public_key_, s); }
  if (var0 & 8) { TlStoreString::store(block_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s); }
}

void phone_createConferenceCall::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2097431739);
  TlStoreBinary::store((var0 = flags_ | (muted_ << 0) | (video_stopped_ << 2) | (join_ << 3)), s);
  TlStoreBinary::store(random_id_, s);
  if (var0 & 8) { TlStoreBinary::store(public_key_, s); }
  if (var0 & 8) { TlStoreString::store(block_, s); }
  if (var0 & 8) { TlStoreBoxed<TlStoreObject, 2104790276>::store(params_, s); }
}

void phone_createConferenceCall::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.createConferenceCall");
    s.store_field("flags", (var0 = flags_ | (muted_ << 0) | (video_stopped_ << 2) | (join_ << 3)));
    if (var0 & 1) { s.store_field("muted", true); }
    if (var0 & 4) { s.store_field("video_stopped", true); }
    if (var0 & 8) { s.store_field("join", true); }
    s.store_field("random_id", random_id_);
    if (var0 & 8) { s.store_field("public_key", public_key_); }
    if (var0 & 8) { s.store_bytes_field("block", block_); }
    if (var0 & 8) { s.store_object_field("params", static_cast<const BaseObject *>(params_.get())); }
    s.store_class_end();
  }
}

phone_createConferenceCall::ReturnType phone_createConferenceCall::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_getGroupCallChainBlocks::phone_getGroupCallChainBlocks(object_ptr<InputGroupCall> &&call_, int32 sub_chain_id_, int32 offset_, int32 limit_)
  : call_(std::move(call_))
  , sub_chain_id_(sub_chain_id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t phone_getGroupCallChainBlocks::ID;

void phone_getGroupCallChainBlocks::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-291534682);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(sub_chain_id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void phone_getGroupCallChainBlocks::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-291534682);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  TlStoreBinary::store(sub_chain_id_, s);
  TlStoreBinary::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void phone_getGroupCallChainBlocks::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.getGroupCallChainBlocks");
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    s.store_field("sub_chain_id", sub_chain_id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

phone_getGroupCallChainBlocks::ReturnType phone_getGroupCallChainBlocks::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

phone_toggleGroupCallSettings::phone_toggleGroupCallSettings(int32 flags_, bool reset_invite_hash_, object_ptr<InputGroupCall> &&call_, bool join_muted_, bool messages_enabled_, int64 send_paid_messages_stars_)
  : flags_(flags_)
  , reset_invite_hash_(reset_invite_hash_)
  , call_(std::move(call_))
  , join_muted_(join_muted_)
  , messages_enabled_(messages_enabled_)
  , send_paid_messages_stars_(send_paid_messages_stars_)
{}

const std::int32_t phone_toggleGroupCallSettings::ID;

void phone_toggleGroupCallSettings::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1757179150);
  TlStoreBinary::store((var0 = flags_ | (reset_invite_hash_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  if (var0 & 1) { TlStoreBool::store(join_muted_, s); }
  if (var0 & 4) { TlStoreBool::store(messages_enabled_, s); }
  if (var0 & 8) { TlStoreBinary::store(send_paid_messages_stars_, s); }
}

void phone_toggleGroupCallSettings::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1757179150);
  TlStoreBinary::store((var0 = flags_ | (reset_invite_hash_ << 1)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(call_, s);
  if (var0 & 1) { TlStoreBool::store(join_muted_, s); }
  if (var0 & 4) { TlStoreBool::store(messages_enabled_, s); }
  if (var0 & 8) { TlStoreBinary::store(send_paid_messages_stars_, s); }
}

void phone_toggleGroupCallSettings::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "phone.toggleGroupCallSettings");
    s.store_field("flags", (var0 = flags_ | (reset_invite_hash_ << 1)));
    if (var0 & 2) { s.store_field("reset_invite_hash", true); }
    s.store_object_field("call", static_cast<const BaseObject *>(call_.get()));
    if (var0 & 1) { s.store_field("join_muted", join_muted_); }
    if (var0 & 4) { s.store_field("messages_enabled", messages_enabled_); }
    if (var0 & 8) { s.store_field("send_paid_messages_stars", send_paid_messages_stars_); }
    s.store_class_end();
  }
}

phone_toggleGroupCallSettings::ReturnType phone_toggleGroupCallSettings::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}

premium_getUserBoosts::premium_getUserBoosts(object_ptr<InputPeer> &&peer_, object_ptr<InputUser> &&user_id_)
  : peer_(std::move(peer_))
  , user_id_(std::move(user_id_))
{}

const std::int32_t premium_getUserBoosts::ID;

void premium_getUserBoosts::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(965037343);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void premium_getUserBoosts::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(965037343);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxedUnknown<TlStoreObject>::store(user_id_, s);
}

void premium_getUserBoosts::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "premium.getUserBoosts");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_object_field("user_id", static_cast<const BaseObject *>(user_id_.get()));
    s.store_class_end();
  }
}

premium_getUserBoosts::ReturnType premium_getUserBoosts::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<premium_boostsList>, -2030542532>::parse(p);
#undef FAIL
}

stickers_removeStickerFromSet::stickers_removeStickerFromSet(object_ptr<InputDocument> &&sticker_)
  : sticker_(std::move(sticker_))
{}

const std::int32_t stickers_removeStickerFromSet::ID;

void stickers_removeStickerFromSet::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-143257775);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
}

void stickers_removeStickerFromSet::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-143257775);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
}

void stickers_removeStickerFromSet::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.removeStickerFromSet");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_class_end();
  }
}

stickers_removeStickerFromSet::ReturnType stickers_removeStickerFromSet::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stickers_replaceSticker::stickers_replaceSticker(object_ptr<InputDocument> &&sticker_, object_ptr<inputStickerSetItem> &&new_sticker_)
  : sticker_(std::move(sticker_))
  , new_sticker_(std::move(new_sticker_))
{}

const std::int32_t stickers_replaceSticker::ID;

void stickers_replaceSticker::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1184253338);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  TlStoreBoxed<TlStoreObject, 853188252>::store(new_sticker_, s);
}

void stickers_replaceSticker::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1184253338);
  TlStoreBoxedUnknown<TlStoreObject>::store(sticker_, s);
  TlStoreBoxed<TlStoreObject, 853188252>::store(new_sticker_, s);
}

void stickers_replaceSticker::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stickers.replaceSticker");
    s.store_object_field("sticker", static_cast<const BaseObject *>(sticker_.get()));
    s.store_object_field("new_sticker", static_cast<const BaseObject *>(new_sticker_.get()));
    s.store_class_end();
  }
}

stickers_replaceSticker::ReturnType stickers_replaceSticker::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<messages_StickerSet>::parse(p);
#undef FAIL
}

stories_deleteStories::stories_deleteStories(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t stories_deleteStories::ID;

void stories_deleteStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-1369842849);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_deleteStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-1369842849);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_deleteStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.deleteStories");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_deleteStories::ReturnType stories_deleteStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchInt>, 481674261>::parse(p);
#undef FAIL
}

stories_getPeerMaxIDs::stories_getPeerMaxIDs(array<object_ptr<InputPeer>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t stories_getPeerMaxIDs::ID;

void stories_getPeerMaxIDs::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2018087280);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void stories_getPeerMaxIDs::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2018087280);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void stories_getPeerMaxIDs::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getPeerMaxIDs");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_getPeerMaxIDs::ReturnType stories_getPeerMaxIDs::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchBoxed<TlFetchObject<recentStory>, 1897752877>>, 481674261>::parse(p);
#undef FAIL
}

stories_getPeerStories::stories_getPeerStories(object_ptr<InputPeer> &&peer_)
  : peer_(std::move(peer_))
{}

const std::int32_t stories_getPeerStories::ID;

void stories_getPeerStories::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(743103056);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void stories_getPeerStories::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(743103056);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
}

void stories_getPeerStories::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getPeerStories");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    s.store_class_end();
  }
}

stories_getPeerStories::ReturnType stories_getPeerStories::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_peerStories>, -890861720>::parse(p);
#undef FAIL
}

stories_getStoriesByID::stories_getStoriesByID(object_ptr<InputPeer> &&peer_, array<int32> &&id_)
  : peer_(std::move(peer_))
  , id_(std::move(id_))
{}

const std::int32_t stories_getStoriesByID::ID;

void stories_getStoriesByID::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(1467271796);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_getStoriesByID::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(1467271796);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  TlStoreBoxed<TlStoreVector<TlStoreBinary>, 481674261>::store(id_, s);
}

void stories_getStoriesByID::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getStoriesByID");
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_field("", _value); } s.store_class_end(); }
    s.store_class_end();
  }
}

stories_getStoriesByID::ReturnType stories_getStoriesByID::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_stories>, 1673780490>::parse(p);
#undef FAIL
}

stories_getStoryViewsList::stories_getStoryViewsList(int32 flags_, bool just_contacts_, bool reactions_first_, bool forwards_first_, object_ptr<InputPeer> &&peer_, string const &q_, int32 id_, string const &offset_, int32 limit_)
  : flags_(flags_)
  , just_contacts_(just_contacts_)
  , reactions_first_(reactions_first_)
  , forwards_first_(forwards_first_)
  , peer_(std::move(peer_))
  , q_(q_)
  , id_(id_)
  , offset_(offset_)
  , limit_(limit_)
{}

const std::int32_t stories_getStoryViewsList::ID;

void stories_getStoryViewsList::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(2127707223);
  TlStoreBinary::store((var0 = flags_ | (just_contacts_ << 0) | (reactions_first_ << 2) | (forwards_first_ << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreString::store(q_, s); }
  TlStoreBinary::store(id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getStoryViewsList::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(2127707223);
  TlStoreBinary::store((var0 = flags_ | (just_contacts_ << 0) | (reactions_first_ << 2) | (forwards_first_ << 3)), s);
  TlStoreBoxedUnknown<TlStoreObject>::store(peer_, s);
  if (var0 & 2) { TlStoreString::store(q_, s); }
  TlStoreBinary::store(id_, s);
  TlStoreString::store(offset_, s);
  TlStoreBinary::store(limit_, s);
}

void stories_getStoryViewsList::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "stories.getStoryViewsList");
    s.store_field("flags", (var0 = flags_ | (just_contacts_ << 0) | (reactions_first_ << 2) | (forwards_first_ << 3)));
    if (var0 & 1) { s.store_field("just_contacts", true); }
    if (var0 & 4) { s.store_field("reactions_first", true); }
    if (var0 & 8) { s.store_field("forwards_first", true); }
    s.store_object_field("peer", static_cast<const BaseObject *>(peer_.get()));
    if (var0 & 2) { s.store_field("q", q_); }
    s.store_field("id", id_);
    s.store_field("offset", offset_);
    s.store_field("limit", limit_);
    s.store_class_end();
  }
}

stories_getStoryViewsList::ReturnType stories_getStoryViewsList::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchObject<stories_storyViewsList>, 1507299269>::parse(p);
#undef FAIL
}

users_getRequirementsToContact::users_getRequirementsToContact(array<object_ptr<InputUser>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t users_getRequirementsToContact::ID;

void users_getRequirementsToContact::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-660962397);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void users_getRequirementsToContact::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-660962397);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void users_getRequirementsToContact::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.getRequirementsToContact");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

users_getRequirementsToContact::ReturnType users_getRequirementsToContact::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<RequirementToContact>>, 481674261>::parse(p);
#undef FAIL
}

users_getUsers::users_getUsers(array<object_ptr<InputUser>> &&id_)
  : id_(std::move(id_))
{}

const std::int32_t users_getUsers::ID;

void users_getUsers::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(227648840);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void users_getUsers::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(227648840);
  TlStoreBoxed<TlStoreVector<TlStoreBoxedUnknown<TlStoreObject>>, 481674261>::store(id_, s);
}

void users_getUsers::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.getUsers");
    { s.store_vector_begin("id", id_.size()); for (const auto &_value : id_) { s.store_object_field("", static_cast<const BaseObject *>(_value.get())); } s.store_class_end(); }
    s.store_class_end();
  }
}

users_getUsers::ReturnType users_getUsers::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchBoxed<TlFetchVector<TlFetchObject<User>>, 481674261>::parse(p);
#undef FAIL
}

users_suggestBirthday::users_suggestBirthday(object_ptr<InputUser> &&id_, object_ptr<birthday> &&birthday_)
  : id_(std::move(id_))
  , birthday_(std::move(birthday_))
{}

const std::int32_t users_suggestBirthday::ID;

void users_suggestBirthday::store(TlStorerCalcLength &s) const {
  (void)sizeof(s);
  s.store_binary(-61656206);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1821253126>::store(birthday_, s);
}

void users_suggestBirthday::store(TlStorerUnsafe &s) const {
  (void)sizeof(s);
  s.store_binary(-61656206);
  TlStoreBoxedUnknown<TlStoreObject>::store(id_, s);
  TlStoreBoxed<TlStoreObject, 1821253126>::store(birthday_, s);
}

void users_suggestBirthday::store(TlStorerToString &s, const char *field_name) const {
  if (!LOG_IS_STRIPPED(ERROR)) {
    s.store_class_begin(field_name, "users.suggestBirthday");
    s.store_object_field("id", static_cast<const BaseObject *>(id_.get()));
    s.store_object_field("birthday", static_cast<const BaseObject *>(birthday_.get()));
    s.store_class_end();
  }
}

users_suggestBirthday::ReturnType users_suggestBirthday::fetch_result(TlBufferParser &p) {
#define FAIL(error) p.set_error(error); return ReturnType()
  return TlFetchObject<Updates>::parse(p);
#undef FAIL
}
}  // namespace telegram_api
}  // namespace td
